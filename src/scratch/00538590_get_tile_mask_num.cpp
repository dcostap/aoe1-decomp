// VA: 00538590 RGE_View::get_tile_mask_num
// PDB: view.cpp:4394-4439
// attempt 1: direct eight-neighbor reconstruction; right size but x/y register coloring swapped.
// attempt 2: decompiler-shaped scalar locals and fixed-address row pointer macro; still swapped x/y registers.
// attempt 3: introduce explicit col/row locals to probe VC5 register coloring; no change.
// attempt 4: mark col/row register locals; no change (and register parameters forced /O1 frame when paired with /O1 probe).
// attempt 5: use explicit negated OR boundary predicate like decompiler/original source; changed compares but not register coloring.
// attempt 6: swapped col/row local definitions as a register-allocation probe; load order moved but semantics wrong.
// attempt 7: swapped locals with row-first guard fixed initial load order but made body x/y swapped.
// attempt 8: keep a first-param guard temp while restoring col/row semantics; no register change.
// attempt 9: keep swapped local names but use row=first-arg as x and col=second-arg as y; behavior/call-free effects correct but VC5 still chooses first arg in EDX and second in EAX.
// tried fixed-address macro vs extern row array; macro reduced relocation noise but not register coloring.
// tried negated-OR guard, explicit locals, register locals, swapped local names, and /O1 probe; /O1 made an EBP frame and was discarded.
// left in scratch: remaining mismatch is broad x/y register coloring and derived branch distances; default build is 382 bytes, first mismatch offset 2, edit diff 112/382.

#define unified_map_offsets ((unsigned long**)0x886808)

class RGE_View {
public:
    char gap_000[0x1A0];
    unsigned char EdgeNumber[0x100]; // +0x1A0

    int get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, unsigned long param_5);
};

int RGE_View::get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, unsigned long param_5)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    unsigned int uVar5;
    int row = param_1;
    int col = param_2;

    uVar5 = 0;
    if (0 < row && 0 < col && row < param_3 - 1 && col < param_4 - 1) {
        iVar3 = (int)unified_map_offsets[col - 1];
        iVar1 = row * 4;
        if ((*(unsigned int*)(iVar3 + iVar1) & param_5) == 0)
            uVar5 = 0x80;
        iVar2 = row * 4 + 4;
        if ((unified_map_offsets[col][row + 1] & param_5) == 0)
            uVar5 |= 0x40;
        iVar4 = (int)unified_map_offsets[col + 1];
        if ((*(unsigned int*)(iVar4 + iVar1) & param_5) == 0)
            uVar5 |= 0x20;
        if ((unified_map_offsets[col][row - 1] & param_5) == 0)
            uVar5 |= 0x10;
        if ((*(unsigned int*)(iVar2 + iVar3) & param_5) == 0)
            uVar5 |= 0x08;
        if ((*(unsigned int*)(iVar4 + iVar2) & param_5) == 0)
            uVar5 |= 0x04;
        if ((*(unsigned int*)(iVar4 + iVar1 - 4) & param_5) == 0)
            uVar5 |= 0x02;
        if ((*(unsigned int*)(iVar3 + iVar1 - 4) & param_5) == 0)
            uVar5 |= 0x01;
    } else {
        if (0 < row && (unified_map_offsets[col][row - 1] & param_5) == 0)
            uVar5 = 0x10;
        iVar1 = param_3 - 1;
        if (row < iVar1 && (unified_map_offsets[col][row + 1] & param_5) == 0)
            uVar5 |= 0x40;
        if (0 < col && (unified_map_offsets[col - 1][row] & param_5) == 0)
            uVar5 |= 0x80;
        iVar3 = param_4 - 1;
        if (col < iVar3 && (unified_map_offsets[col + 1][row] & param_5) == 0)
            uVar5 |= 0x20;
        if (0 < row) {
            if (0 < col && (unified_map_offsets[col - 1][row - 1] & param_5) == 0)
                uVar5 |= 0x01;
            if (col < iVar3 && (unified_map_offsets[col + 1][row - 1] & param_5) == 0)
                uVar5 |= 0x02;
        }
        if (row < iVar1) {
            if (0 < col && (unified_map_offsets[col - 1][row + 1] & param_5) == 0)
                uVar5 |= 0x08;
            if (col < iVar3 && (unified_map_offsets[col + 1][row + 1] & param_5) == 0)
                uVar5 |= 0x04;
        }
    }
    return this->EdgeNumber[uVar5];
}
