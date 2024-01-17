#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	Part* GetLastTail();

	Part* SnakeMove(int2 _Prev);

	//Part* GetBack()
	//{
	//	return Back;
	//}

	//void SetBack(Part* _Back)
	//{
	//	Back = _Back;
	//}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;

};

