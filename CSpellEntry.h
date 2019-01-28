#pragma once
#include <Windows.h>
class CSpellEntry {
public:
	char* GetSpellName() {
		auto aux3 = *(DWORD*)((DWORD)this + 0x4);
		if (aux3) {
			auto aux4 = *(DWORD*)(aux3 + 0xC);
			if (aux4) {
				if (*(DWORD*)(aux4 + 0x8)) {
					return (char*)(aux4 + 0x8);
				}
			}
		}
		return NULL;
	}
};