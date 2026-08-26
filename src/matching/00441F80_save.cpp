// 00441F80 RGE_Doppleganger_Object::save
// PDB: dpl_obj.cpp:418-462, 204 bytes
// __thiscall, void, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: class member fields, no EDI save -> wrong prologue (79.4%)
// probe 2: int handle=file + void* casts -> compile error
// probe 3: int handle=file + char* offsets -> MATCH
//   Key: `int handle = file;` forces VC5 to preserve original file handle
//   in EDI (callee-saved). Without this, VC5 uses EAX (caller-saved) and
//   generates wrong prologue (no push edi). The handle local goes into EDI
//   without extra stack space because it's kept entirely in register.
//   char* casts avoid VC5 void* arithmetic error.

#include <stdlib.h>

extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

extern float save_game_version;
extern float DAT_00570418;

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

void RGE_Doppleganger_Object::save(int file) {
    int handle = file;

    RGE_Animated_Object::save(file);

    if (*(char**)((char*)this + 0x8C) != NULL) {
        file = *(int*)(*(char**)((char*)this + 0x8C) + 4);
    } else {
        file = -1 - *(int*)((char*)this + 0x98);
    }
    rge_write(handle, &file, 4);
    rge_write(handle, (char*)this + 0xA8, 1);
    rge_write(handle, (char*)this + 0xA9, 4);

    if (*(char**)((char*)this + 0x94) != NULL) {
        file = *(short*)(*(char**)((char*)this + 0x94) + 0x10);
    } else {
        file = -1;
    }
    rge_write(handle, &file, 4);
    rge_write(handle, (char*)this + 0x98, 4);

    if (save_game_version >= DAT_00570418) {
        rge_write(handle, (char*)this + 0xA4, 4);
    }
}
