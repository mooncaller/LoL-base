#pragma once
#include <Windows.h>
#include "Offsets.h"

class BuffEntry
{
public:

	DWORD strptr;
	bool isBuffEmpty() {
		return strptr == 0;
	}
		bool IsAlive();
		bool IsValid() {
			if (this == NULL || (DWORD)this <= 0x1000)
				return false;

			return strcmp(GetBuffName(), "NULL");
		}

		float GetBuffStartTime() {
			return *(float*)((DWORD)this + O_BUFFMGR_STARTTIME);
		}

		float GetBuffEndTime() {
			return *(float*)((DWORD)this + O_BUFFMGR_ENDTIME);
		}

		int GetBuffCountAlt() {
			return (*(int*)((DWORD)this + 0x20) - *(int*)((DWORD)this + 0x1c)) >> 3;
		}

		float GetBuffCountFloat() {
			return *(float*)((DWORD)this + O_BUFFMGR_flBUFFCOUNT);
		}

		int GetBuffCountInt() {
			return *(int*)((DWORD)this + O_BUFFMGR_iBUFFCOUNT);
		}

		char* GetBuffName() {
			DWORD aux = *(DWORD*)((DWORD)this + O_BUFFMGR_BUFFNAME);
			if (aux == NULL)
				return "NULL";

			if (*(DWORD*)(aux + O_BUFFMGR_BUFFNAME) == NULL)
				return "NULL";

			return (char*)(aux + O_BUFFMGR_BUFFNAME);
		}
	
};

