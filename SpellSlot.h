#pragma once
#include <Windows.h>
#include "SpellInfo.h"
class SpellSlot {
public:
	int GetLevel() {
		return *(int*)((DWORD)this + 0x20);
	}

	float GetTime() {
		return *(float*)((DWORD)this + 0x28);
	}

	float GetCD() {
		return *(float*)((DWORD)this + 0x18);
	}

	SpellInfo* GetSpellData() {
		return (SpellInfo*)((DWORD)this + 0x124);
	}


};