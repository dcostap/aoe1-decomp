// VA: 0050EE80 TRIBE_Master_Combat_Object::modify
// PDB source: tm_co_ob.cpp
// Attempt log:
// - pre-claim state: if-form, 224/233 (9 short), 22.7% shape, wrong base-modify symbol
// - h1 baseline (CURRENT, clean pin): switch-form dispatch (sub eax,64h/je/dec/je chain,
//   matching the base RGE_Master_Combat_Object::modify style), real virtual class surface
//   so default call has true ?modify@RGE_Master_Combat_Object@@UAEXME@Z symbol, loop counter
//   hoisted out of the switch (VC5 C2360/C2374). Result: 233/233 size, calls 100% aligned,
//   shape 95.51%, exact-block 88.64%, edit diff 16.31%. First strict mismatch +0015
//   (je displacement: rebuilt 'e' body 2 bytes short).
// Remaining drift (EXACT CODEGEN stage, all in 'e' pts loops 2-4):
//   - original keeps bases in callee-saved esi(int@0x70)/edi(short@0x6A, this mutated via
//     add edi,6Ah), reloads BOTH working ptrs (ecx/eax) + counter edx at each loop start;
//     param_1 bits loaded at use inside loop2 (mov ebx,[esp+10h] after cmp/jne).
//   - rebuilt hoists bases to ebx/eax, hoists param_1 into edi before loop2, and loop4
//     reuses eax as short ptr (2 bytes shorter setup) -> shifts 'd' handler up 2 bytes.
// Next leads (not yet tried):
//   1. do/while pointer-loop idiom from exact donor modify_percent (0050EFC0) for the pts
//      loops (separate short*/int* locals per loop, int counter = 3).
//   2. Fuller real class surface (RGE_Master_Combat_Object real fields) — LESSONS notes
//      (00435020) that full typed class bodies can flip VC5 register basins.
//   3. Loop form variants: unbraced for bodies, i/j/k counters, or store cast spelled as
//      *vp = *(int*)&param_1 with volatile-free reload placement.

class RGE_Master_Combat_Object {
public:
    virtual void modify(float param_1, unsigned char param_2);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_000[0x66];      // vptr + 4..0x69
    short pts_type[3];       // 0x6A
    int pts_value[3];        // 0x70
    char gap_07C[0xCE];      // 0x7C..0x149
    struct InvEntry {
        short amount;        // +0
        unsigned char flag;  // +2
        char pad[3];         // +3..+5
    } build_inventory[3];    // 0x14A, 6-byte stride

    void modify(float param_1, unsigned char param_2);
};

void TRIBE_Master_Combat_Object::modify(float param_1, unsigned char param_2)
{
    int i;
    switch (param_2) {
    case 'd':
        for (i = 0; i < 3; i++) {
            if (build_inventory[i].flag)
                build_inventory[i].amount = (short)(int)param_1;
        }
        break;
    case 'e':
        for (i = 0; i < 3; i++) {
            if (!build_inventory[i].flag)
                build_inventory[i].amount = (short)(int)(-param_1);
        }
        for (i = 0; i < 3; i++) {
            if (pts_type[i] == 4)
                pts_value[i] = *(int*)&param_1;
        }
        for (i = 0; i < 3; i++) {
            if (pts_type[i] == 0x0B)
                *(float*)&pts_value[i] = -param_1;
        }
        for (i = 0; i < 3; i++) {
            if (pts_type[i] == 0x13)
                *(float*)&pts_value[i] = -param_1;
        }
        break;
    default:
        RGE_Master_Combat_Object::modify(param_1, param_2);
        break;
    }
}
