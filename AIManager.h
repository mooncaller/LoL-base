#pragma once
#include "Offsets.h"
#include <Windows.h>
class AIManager
{
public:

	float GetVelocity() {
		return *(float*)((DWORD)this + O_AIMGR_VELOCITY);
	}

};

