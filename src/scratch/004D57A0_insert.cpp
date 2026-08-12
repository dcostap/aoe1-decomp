// VA: 004D57A0 TribeBuildAIModule::insert
// Source: taibldmd.cpp lines 1505-1600
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: full typed version with correct layout
// 2: restored the BuildAIModule base call, BuildItem::built field layout,
//    and the original nested switch family; the first baseline used a
//    derived helper call and placed the list/MD fields at the wrong offsets.
// 3-4: the typed base/list/MD surface improved structural coverage and frame
//    parity; a self alias did not change emitted code and was removed.
// 5: matched the original signed range-check polarity and added case 0x12B,
//    improving jump-table coverage but not positional bytes.
// 6-9: explicit base-call, result-local, base-pointer, and non-derived-class
//    spellings were codegen duplicates or failed to restore the second call.
// Best current reconstruction: typed fields and calls are correct, but VC5
//    still merges the two insertItem sites and keeps this/category allocation
//    in a different basin than the original.

#include <stdlib.h>

class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;
    int built();
};

class TribeBuildMD {
public:
    char gap_00[0xF0];
    void* player;       // +0xF0
};

class BuildAIModule {
public:
    int insertItem(void* player, int type, int val1, int flags,
                   int buildCategory, int p2, int p3);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_000[0x0F0];
    BuildItem buildList; // +0x0F0 (embedded sentinel)
    char gap_160[0x45C];
    TribeBuildMD* md; // +0x5BC

    int insert(int p1, int p2, int p3);
};

int TribeBuildAIModule::insert(int p1, int p2, int p3)
{
    int buildCat;
    int flags;

    if (p1 <= 0xB) {
        if (p1 == 0xB) {
            goto L_case_31;
        }
        if (p1 < 4) {
            return 0;
        }
        if (p1 <= 5) {
            goto L_case_57;
        }
        return 0;
    } else if (p1 > 0x19) {
        if (p1 <= 0x46) {
            if (p1 < 0x44) {
                switch (p1) {
                case 0x23:
                case 0x24:
                    goto L_case_31;
                case 0x25:
                case 0x28:
                case 0x2E:
                    goto L_case_65;
                case 0x27:
                case 0x29:
                    goto L_case_57;
                case 0x2D:
                case 0x31:
                case 0x32:
                    goto L_case_negative;
                default:
                    return 0;
                }
            }
            goto L_case_negative;
        }

        {
            int idx = p1 - 0x49;
            switch (idx) {
            case 0:
            case 2:
                buildCat = 0x0C;
                flags = 2;
                break;
            case 6:
            case 0x1E:
            case 0x7E:
            case 0xCB:
            case 0xCD:
                goto L_case_negative;
            case 0xE2:
                goto L_case_65;
            case 0xA:
                buildCat = 0x6D;
                flags = 2;
                break;
            case 0x14:
                buildCat = 0;
                flags = 2;
                break;
            case 0x34:
                buildCat = 0x68;
                flags = 2;
                break;
            case 0xB1:
                goto L_case_2D;
            default:
                return 0;
            }
        }
    } else if (p1 != 0x19) {
        {
            int idx = p1 - 0xD;
            switch (idx) {
            case 0:
            case 2:
            case 4:
            case 5:
            case 6:
                goto L_case_2D;
            default:
                return 0;
            }
        }
    }

L_case_57:
    buildCat = 0x57;
    flags = 2;
    goto L_after_switch;

L_case_31:
    buildCat = 0x31;
    flags = 2;
    goto L_after_switch;

L_case_65:
    buildCat = 0x65;
    flags = 2;
    goto L_after_switch;

L_case_2D:
    buildCat = 0x2D;
    flags = 2;
    goto L_after_switch;

L_case_negative:
    buildCat = -1;
    flags = 0;

L_after_switch:
    if (p3 != -1) {
        return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, p3);
    }

    {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;
        int count = 0;

        if (item != sentinel) {
            while (item != 0 && item->built() == 1) {
                item = item->next;
                count++;
                if (item == sentinel) break;
            }
        }

        return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, count);
    }
}
