#pragma once
#include "Part.h"

class Body : public Part
{

private:
	Part* Next = nullptr;
};

