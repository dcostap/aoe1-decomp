// 00438E80 ClipDibBlt
// Attempt log:
// 1: Direct reconstruction from packet/decompiler with BITMAPINFO/RECT local structs: 85.44% diff; register allocation started wrong (rect left/top in edi/esi vs original esi/ebx).
// 2: Rewrote using decompiler variable topology/order: worse, inverted null-rect branch and spilled max_x/max_y.
// 3: Restore `if (param_2 != 0)` order while keeping decompiler variable topology: first mismatch at top/right register allocation (ecx/edx vs original ebx/ecx).
// 4: `register` hints for min-y/max-x/max-y locals made no codegen change; rolled back.
// 5: Temporary /O1 flag produced 398-byte wrong-size function; removed flag.
// 6: Temporary /O2 without /Oy made no codegen change; removed flag.
// 7: Temporary /Od produced broad 97.2% mismatch; removed flag.
// BLOCKER: behavior is understood, but VC5 register allocation/source shape is wrong from the first rect-load block. Original keeps left/top/right in ESI/EBX/ECX and stores max bounds to stack only after abs/dec; current best uses ESI/ECX/EDX and spills max bounds early, causing broad cascade.

typedef long LONG;

struct tagRECT { LONG left; LONG top; LONG right; LONG bottom; };
struct BITMAPINFO256 { unsigned int biSize; LONG biWidth; LONG biHeight; };

extern "C" int __cdecl ClipDibBlt(BITMAPINFO256* param_1, tagRECT* param_2,
    LONG* param_3, LONG* param_4, LONG* param_5, LONG* param_6,
    LONG* param_7, LONG* param_8, LONG* param_9, LONG* param_10,
    int param_11, int param_12)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;

    if (param_2 != 0) {
        iVar6 = param_2->left;
        iVar7 = param_2->top;
        iVar5 = param_2->right + 1;
        iVar2 = param_2->bottom + 1;
    } else {
        iVar6 = 0;
        iVar7 = 0;
        iVar5 = param_1->biWidth;
        iVar2 = param_1->biHeight;
    }
    if (iVar2 < 0) {
        iVar2 = -iVar2;
    }
    iVar5 = iVar5 - 1;
    iVar2 = iVar2 - 1;

    iVar1 = *param_3;
    if (iVar1 <= iVar5) {
        if (*param_4 <= iVar2) {
            iVar3 = *param_5;
            if (iVar6 <= iVar3 + iVar1 - 1) {
                iVar4 = *param_6;
                if (iVar7 <= iVar4 + *param_4 - 1 && 0 < iVar3 && 0 < iVar4) {
                    iVar3 = (*param_9 << 8) / iVar3;
                    iVar4 = (*param_10 << 8) / iVar4;

                    if (iVar1 < iVar6) {
                        *param_3 = iVar6;
                        int delta = iVar6 - iVar1;
                        *param_5 = *param_5 - delta;
                        int scaled = (delta * 0x100 * iVar3) >> 16;
                        if (param_11 == 0) {
                            *param_7 = *param_7 + scaled;
                        }
                        *param_9 = *param_9 - scaled;
                    }

                    iVar1 = *param_4;
                    if (iVar1 < iVar7) {
                        *param_4 = iVar7;
                        int delta = iVar7 - iVar1;
                        *param_6 = *param_6 - delta;
                        int scaled = (delta * 0x100 * iVar4) >> 16;
                        if (param_12 == 0) {
                            *param_8 = *param_8 + scaled;
                        }
                        *param_10 = *param_10 - scaled;
                    }

                    iVar1 = *param_3 + *param_5;
                    if (iVar5 < iVar1 - 1) {
                        int delta = iVar1 - iVar5 - 1;
                        *param_5 = *param_5 - delta;
                        int scaled = (delta * 0x100 * iVar3) >> 16;
                        *param_9 = *param_9 - scaled;
                        if (param_11 != 0) {
                            *param_7 = *param_7 + scaled;
                        }
                    }

                    iVar1 = *param_4 + *param_6;
                    if (iVar2 < iVar1 - 1) {
                        int delta = iVar1 - iVar2 - 1;
                        *param_6 = *param_6 - delta;
                        int scaled = (delta * 0x100 * iVar4) >> 16;
                        *param_10 = *param_10 - scaled;
                        if (param_12 != 0) {
                            *param_8 = *param_8 + scaled;
                        }
                    }

                    if (0 < *param_5 && 0 < *param_6 && 0 < *param_9 && 0 < *param_10) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
