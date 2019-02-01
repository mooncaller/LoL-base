#pragma once
#include "Offsets.h"
#include <Windows.h>
#include "Vector.h"
class AIManager
{
public:

     Vector GetVelocity() {
		return *(Vector*)((DWORD)this + O_AIMGR_VELOCITY);
	}

};

