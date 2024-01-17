#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.


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
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
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