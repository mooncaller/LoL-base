#pragma once
#include <Windows.h>
#include "BuffEntry.h"
#include "guicon.h"
class BuffManager {
public:
	DWORD pStart = *(DWORD*)((DWORD)this + 0x10);
	DWORD pEnd = *(DWORD*)((DWORD)this + 0x14);

	BuffEntry* GetBuffEntryByName(char* BuffName) {
		for (DWORD pBuffPtr = this->pStart; pBuffPtr != this->pEnd; pBuffPtr += 0x8)
		{
			Console.print("test2");
			auto pBuff = *(BuffEntry**)pBuffPtr;
			if (!pBuff->IsValid()) continue;
			Console.print("test1");
			if (pBuff) {
				Console.print("Buff : %s", pBuff->GetBuffName());
				if (!strcmp(pBuff->GetBuffName(), BuffName)) {
					return pBuff;
				}
			}
		}
		return NULL;
	}
};