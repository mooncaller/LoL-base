#pragma once
#include <Windows.h>
#include "SpellInfo.h"
class CSpellEntry {
public:
	SpellInfo* getSpellInfo() {
		return (SpellInfo*)((DWORD)this + 0x8);
	}

	bool isAutoAttack() {
			return *(bool*)((DWORD)this + 0xAC);
	
	}
};