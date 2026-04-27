// CopyPalette — first pass
// VA: 0043ACB0
// __cdecl, extern GDI/KERNEL function pointers

#include "../../include/game_globals.h"

// IAT-resolved Windows API calls — extern pointers for call dword [addr] shape
typedef int (__stdcall *_GetObjectAT)(void* hgdiobj, int cb, void* lpvObj);
typedef void* (__stdcall *_LocalAllocT)(int flags, int size);
typedef int (__stdcall *_GetPaletteEntriesT)(void* hpal, int start, int count, void* entries);
typedef void* (__stdcall *_CreatePaletteT)(void* logpal);
typedef void* (__stdcall *_LocalFreeT)(void* mem);

extern _GetObjectAT _GetObjectA;
extern _LocalAllocT _LocalAlloc;
extern _GetPaletteEntriesT _GetPaletteEntries;
extern _CreatePaletteT _CreatePalette;
extern _LocalFreeT _LocalFree;

void* __cdecl CopyPalette(void* param_1)
{
    int nNumEntries = 0;

    if (!param_1) return 0;

    _GetObjectA(param_1, 4, &nNumEntries);
    if (!nNumEntries) return 0;

    void* pal = _LocalAlloc(0x40, nNumEntries * 4 + 8);
    if (!pal) return 0;

    *(short*)pal = 0x300;           // palVersion = 0x300
    *(short*)((char*)pal + 2) = (short)nNumEntries;  // palNumEntries

    _GetPaletteEntries(param_1, 0, nNumEntries, (char*)pal + 4);
    void* result = _CreatePalette(pal);
    _LocalFree(pal);
    return result;
}
