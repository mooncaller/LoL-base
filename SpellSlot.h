#pragma once
#include <Windows.h>
class SpellSlot {
public:
	int GetLevel() {
		return *(int*)((DWORD)this + 0x20);
	}

	float GetTime() {
		return *(float*)((DWORD)this + 0x28);
	}
};