// VA: 0050EE80 TRIBE_Master_Combat_Object::modify
// PDB source: tm_co_ob.cpp
// Attempt log:
// - 224/233 bytes (9 short) — close! FPU scheduling differences
// - Correct logic: switch on param_2: case 'd' (amount update), case 'e' (negated + 3 array loops)
// - Left in scratch

#include <stdlib.h>

struct RGE_Master_Combat_Object_modify {
    char base[0x148];
    void modify(float param_1, unsigned char param_2);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    short build_inv_0_amount;
    short build_inv_0_type;
    unsigned char build_inv_0_flag;
    char pad_14D[3];

    void modify(float param_1, unsigned char param_2);
};

void TRIBE_Master_Combat_Object::modify(float param_1, unsigned char param_2)
{
    if (param_2 == 0x64) {
        int i;
        for (i = 0; i < 3; i++) {
            unsigned char* flag = (unsigned char*)((char*)this + 0x14A + i * 6 + 2);
            if (*flag) {
                short* amount = (short*)((char*)this + 0x14A + i * 6);
                *amount = (short)(int)param_1;
            }
        }
        return;
    }
    
    if (param_2 == 0x65) {
        int i;
        for (i = 0; i < 3; i++) {
            unsigned char* flag = (unsigned char*)((char*)this + 0x14A + i * 6 + 2);
            if (!*flag) {
                short* amount = (short*)((char*)this + 0x14A + i * 6);
                *amount = (short)(int)(-param_1);
            }
        }
        
        for (i = 0; i < 3; i++) {
            short* type = (short*)((char*)this + 0x6A + i * 2);
            int* dst = (int*)((char*)this + 0x70 + i * 4);
            if (*type == 4)
                *dst = *(int*)&param_1;
        }
        for (i = 0; i < 3; i++) {
            short* type = (short*)((char*)this + 0x6A + i * 2);
            int* dst = (int*)((char*)this + 0x70 + i * 4);
            if (*type == 0xB)
                *(float*)dst = -param_1;
        }
        for (i = 0; i < 3; i++) {
            short* type = (short*)((char*)this + 0x6A + i * 2);
            int* dst = (int*)((char*)this + 0x70 + i * 4);
            if (*type == 0x13)
                *(float*)dst = -param_1;
        }
        return;
    }
    
    ((RGE_Master_Combat_Object_modify*)this)->modify(param_1, param_2);
}
