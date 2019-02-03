#pragma once
#include <Windows.h>
#include "BuffEntry.h"
#include "guicon.h"
#include <stdint.h>
class BuffManager {
public:
	

	BuffEntry * getBuffUnsafe(int i) {
		_asm {
			mov ebx, i
			mov eax, [ecx + 0x10]
			mov eax, [eax + ebx * 0x8]
		}
	}

	BuffEntry * getEndBuffUnsafe(int i) {
		_asm {
			mov eax, [ecx + 0x14]

		}
	}

	BuffEntry * getBuffSafe(int i) {
			if (0 <= i && i < 0x40) {
				return getBuffUnsafe(i);
			}
			else {
				return nullptr;
			}
	}


	BuffEntry* GetBuffEntryByName(char* BuffName) {
		auto pStart = ((DWORD)this + 0x10);
		auto pEnd = (BuffEntry *)((DWORD)this + 0x14);
		Console.print("Buff %i \n", (unsigned int)pEnd);
		Console.print("Buff %i \n", (unsigned int)pStart);
		Console.print("Buff %i \n", sizeof(BuffEntry));
		
		for (int i = 0; i < 64; i++)
		{
			auto* buff = getBuffUnsafe(i);
			if (buff == pEnd) {
				break;
			}
			if (!buff->IsValid()) continue;
			Console.print("Buff %s \n", buff->GetBuffName());
			if (!strcmp(buff->GetBuffName(), BuffName)) {
				return buff;
			}
		}
		return NULL;
	}
};