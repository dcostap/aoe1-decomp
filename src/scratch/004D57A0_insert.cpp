// VA: 004D57A0 TribeBuildAIModule::insert
// Source: taibldmd.cpp lines 1505-1600
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: full typed version with correct layout

#include <stdlib.h>

class BaseItem {
public:
    virtual ~BaseItem();
    int built();
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;    // +0x6C
    BuildItem* prev;    // +0x70
    char gap_74[0x98 - 0x74];
    int buildCategoryValue; // +0x98
};

class MainDecisionAIModule {
public:
    char gap_00[0x10D7C];
    char gap_10D80[0x1256C - 0x10D80];
    void* aiPlayer;     // +0x1256C
};

class TribeBuildAIModule {
public:
    char gap_000[0x0F0];
    BuildItem buildList; // +0x0F0 (embedded sentinel)
    char gap_1A0[0x5BC - 0x1A0];
    MainDecisionAIModule* md; // +0x5BC

    int insert(int p1, int p2, int p3);
    int insertItem(void* player, int type, int val1, int flags, int buildCategory, int p2, int p3);
};

int TribeBuildAIModule::insert(int p1, int p2, int p3)
{
    int buildCat;
    int flags;
    int result;

    if (p1 <= 0xB) {
        if (p1 == 0xB) { goto L_case_31; }
        if (p1 < 4) { return 0; }
        if (p1 > 5) { return 0; }
        buildCat = 0x57;
        flags = 2;
    } else if (p1 <= 0x19) {
        if (p1 == 0x19) {
            buildCat = 0x57;
            flags = 2;
        } else {
            int idx = p1 - 0xD;
            if (idx > 6) { return 0; }
            switch (idx) {
            case 0: case 2: case 4: case 5: case 6:
                buildCat = 0x2D;
                flags = 2;
                break;
            default:
                return 0;
            }
        }
    } else if (p1 <= 0x46) {
        if (p1 >= 0x44) {
            buildCat = -1;
            flags = 0;
        } else {
            int idx = p1 - 0x23;
            if (idx > 0xF) { return 0; }
            switch (idx) {
            case 0: case 1:
                goto L_case_31;
            case 2: case 5: case 0xB:
                buildCat = 0x65;
                flags = 2;
                break;
            case 4: case 6:
                buildCat = 0x57;
                flags = 2;
                break;
            case 0xA: case 0xE: case 0xF:
                buildCat = -1;
                flags = 0;
                break;
            default:
                return 0;
            }
        }
    } else {
        int idx = p1 - 0x49;
        if (idx > 0xE2) { return 0; }
        switch (p1) {
        case 0x49: case 0x4B:
            buildCat = 0x0C;
            flags = 2;
            break;
        case 0x4F: case 0x67: case 0xC7: case 0x114: case 0x116:
            buildCat = -1;
            flags = 0;
            break;
        case 0x53:
            buildCat = 0x6D;
            flags = 2;
            break;
        case 0x5D:
            buildCat = 0;
            flags = 2;
            break;
        case 0x7D:
            buildCat = 0x68;
            flags = 2;
            break;
        case 0xFA:
            buildCat = 0x2D;
            flags = 2;
            break;
        default:
            return 0;
        }
    }
    goto L_after_switch;

L_case_31:
    buildCat = 0x31;
    flags = 2;

L_after_switch:
    if (p3 != -1) {
        result = this->insertItem(this->md->aiPlayer, p1, 1, flags, buildCat, p2, p3);
        return result;
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

        result = this->insertItem(this->md->aiPlayer, p1, 1, flags, buildCat, p2, count);
    }
    return result;
}
