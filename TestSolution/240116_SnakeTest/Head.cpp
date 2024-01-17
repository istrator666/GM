#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.


void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	int2 PrevHeadpos = GetPos();

	switch (Select)
	{
	case 'A':
	case 'a':
		if (PrevPosition != Right) {
			AddPos(Left);
			PrevPosition = Left;
		}
		break;
	case 'S':
	case 's':
		if (PrevPosition != Up) {
			AddPos(Down);
			PrevPosition = Down;
		}
		break;
	case 'W':
	case 'w':
		if (PrevPosition != Down) {
			AddPos(Up);
			PrevPosition = Up;
		}
		break;
	case 'D':
	case 'd':
		if (PrevPosition != Left) {
			AddPos(Right);
			PrevPosition = Right;
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	int2 NextHeadPos = GetPos();

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		
		GetLastTail();
		Back = CurBody;
		Back->SetRenderChar('@');

		//Part* LastBack = this;

		//while (nullptr != LastBack->GetBack())
		//{
		//	LastBack = LastBack->GetBack();
		//}

		//LastBack->SetBack(CurBody);
			

		BodyManager::ResetBody();
	}

	SnakeMove(PrevHeadpos);
}