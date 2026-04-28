// 0042EC40 StringFromGUID (120 bytes)
// PDB: Com_hand.cpp
// STATUS: parked — register allocation differs from original
//
// Code structure is correct: extern array references generate relocation-based 
// indexed addressing matching the original's [reg+56F218h]/[reg*2+56F230h].
// However, VC5 assigns different registers:
//   Original: EAX=output, ESI=counter, EDI=guid
//   Rebuilt:  ECX=output, EDX=counter, ESI=guid
// Plus extra spilling of local temps.
//
// The extern arrays DAT_0056f218[20] and u_0123456789ABCDEF_0056f230[16]
// resolve via linker to 0x56F218 and 0x56F230 (relocations masked in diff).

extern unsigned char DAT_0056f218[20];
extern unsigned short u_0123456789ABCDEF_0056f230[16];

extern "C" int __cdecl StringFromGUID(void* guid, unsigned short* output)
{
    int i;

    *output++ = L'{';
    for (i = 0; i < 20; i++) {
        if (DAT_0056f218[i] == 0x2D) {
            *output++ = L'-';
        } else {
            unsigned char b = ((unsigned char*)guid)[DAT_0056f218[i]];
            *output++ = u_0123456789ABCDEF_0056f230[b >> 4];
            *output++ = u_0123456789ABCDEF_0056f230[b & 0xF];
        }
    }
    *output++ = L'}';
    *output = 0;
    return 0x26;
}
