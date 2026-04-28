// VA: 005359E0 RGE_View::pick
// Source: view.cpp lines 2272-2300
// Size: 151 bytes, __thiscall, ret 18h (6 params)
// Status: parked — 8 probes, epilogue + zeroing scheduling artifact
// Conditional generates correct sub/neg/sbb/and pattern.
// view_function call pushes 9 args correctly (stdcall, callee-cleanup).
// Remaining: struct zeroing interleaved with arg prep (lea reordering),
//   missing duplicated epilogue for 0x33 branch (7 bytes short = 144 vs 151).
// Compiler optimization — different scheduling from original VC5.

#include <stdlib.h>

extern int __stdcall view_function(int a, int b,
                                    int* c, int* d, int* e,
                                    int* f, int* g, short* h, short* i);

struct RGE_View {
    char _gap[4];
    unsigned char pick(int key, int param_2, int mouse_y, int mouse_x,
                       void* info, void* obj);
};

unsigned char RGE_View::pick(int key, int param_2, int mouse_y, int mouse_x,
                              void* info, void* obj) {
    // Local: 16 bytes
    int locals[4];
    locals[0] = mouse_y;     // [esp+8] area: start_mouse_pos.y
    locals[1] = mouse_x;     // [esp+0Ch] area: mouse_pos.x
    locals[2] = mouse_y;     // [esp+10h] area: mouse_pos.y

    // Conditional: result = (key != '(') ? obj : 0
    int result = (key != 0x28) ? (int)obj : 0;

    // Zero info: separate from call arg prep
    int* pi = (int*)info;
    pi[0] = 0;
    pi[1] = 0;
    pi[2] = 0;
    pi[3] = 0;
    pi[4] = 0;

    // Call view_function
    int ret = view_function(key, param_2,
                            &locals[2], &locals[0], &result,
                            (int*)((char*)info + 0),
                            (int*)((char*)info + 4),
                            (short*)((char*)info + 8),
                            (short*)((char*)info + 0xA));

    unsigned char ucode = (unsigned char)ret;
    if (ucode == 0x34) {
        *(int*)((char*)info + 0xC) = result;
    } else if (ucode == 0x33) {
        *(int*)((char*)info + 0x10) = result;
    }

    return ucode;
}
