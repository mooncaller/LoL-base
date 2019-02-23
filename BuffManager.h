#pragma once
#include "Utils.h"
#include "BuffEntry.h"
#include "guicon.h"

class BuffManager {
private:
	union {
		DEFINE_MEMBER_0(void *base, 0x0);
		DEFINE_MEMBER_N(DWORD pStart, 0x10);
		DEFINE_MEMBER_N(DWORD pEnd, 0x14);
	};

public:
	BuffEntry* GetBuffEntryByName(char* BuffName) {
		int i = -1;
		for (DWORD pBuffPtr = this->pStart; pBuffPtr != this->pEnd; pBuffPtr += 0x8)
		{
			auto pBuff = *(BuffEntry**)pBuffPtr;
			i++;
			if (!pBuff) continue;
			if (!pBuff->IsValid()) continue;
			if (pBuff->IsAlive()) {
				if (!strcmp(pBuff->GetBuffName(), BuffName)) {
					return pBuff;
				}
			}
			
		}
		return NULL;
	}

	bool IsImmobile(int Type) {
		int i = -1;
		for (DWORD pBuffPtr = this->pStart; pBuffPtr != this->pEnd; pBuffPtr += 0x8)
		{
			auto pBuff = *(BuffEntry**)pBuffPtr;
			i++;
			if (!pBuff) continue;
			if (!pBuff->IsValid()) continue;
			if (pBuff->IsAlive()) {
				if (pBuff->getBuffType() == Type)
					return true;
			}

		}
		return false;
	}
};