#include "Part.h"

Part* Part::GetLastTail()
{
	if (nullptr == Back)
	{
		return this;
	}

	return Back->GetLastTail();
}

Part* Part::SnakeMove(int2 _Prev)
{
	if (nullptr == Back)
	{
		return this;
	}

	Back->SetPos(_Prev);
	Back->GetPos();
	return Back->SnakeMove(GetPos());
}

