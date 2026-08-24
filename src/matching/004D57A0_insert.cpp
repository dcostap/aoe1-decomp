// VA: 004D57A0 TribeBuildAIModule::insert
// Source: taibldmd.cpp lines 1505-1600
// FLAGS: /nologo /c /O2 /Oy
//
// Matching notes:
// - The dispatch is one switch. Its case groups and assignment order recover
//   the three original VC5 jump-table clusters and category block order.
// - The two direct BuildAIModule::insertItem calls stay in separate branches.
// - The scan compares directly with &buildList. This lets VC5 mutate the
//   saved this register into the sentinel address, as in the original.
// Exact check: 446 bytes, 3 calls, frame 0x8, MATCH 0.0000%.

#ifndef TAIBLDMD_SHARED_CONTEXT
#include <stdlib.h>

class RGE_Player;

class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;
    int built();
};

class TribeBuildMD {
public:
    char gap_00[0xF0];
    RGE_Player* player;  // +0xF0
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;
    char gap_160[0x45C];

    int insertItem(RGE_Player* player, int type, int val1, int flags,
                   int buildCategory, int p2, int p3);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeBuildMD* md; // +0x5BC

    int insert(int p1, int p2, int p3);
};
#endif

int TribeBuildAIModule::insert(int p1, int p2, int p3)
{
    int flags;
    int buildCat;

    switch (p1) {
    case 4:
    case 5:
    case 0x19:
    case 0x27:
    case 0x29:
        buildCat = 0x57;
        flags = 2;
        break;
    case 0x0B:
    case 0x23:
    case 0x24:
        buildCat = 0x31;
        flags = 2;
        break;
    case 0x53:
        buildCat = 0x6D;
        flags = 2;
        break;
    case 0x49:
    case 0x4B:
        buildCat = 0x0C;
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
    case 0x25:
    case 0x28:
    case 0x2E:
    case 0x12B:
        buildCat = 0x65;
        flags = 2;
        break;
    case 0x0D:
    case 0x0F:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0xFA:
        buildCat = 0x2D;
        flags = 2;
        break;
    case 0x2D:
    case 0x31:
    case 0x32:
    case 0x4F:
    case 0x67:
    case 0xC7:
    case 0x114:
    case 0x116:
    case 0x44:
    case 0x45:
    case 0x46:
        buildCat = -1;
        flags = 0;
        break;
    default:
        return 0;
    }

    if (p3 == -1) {
        BuildItem* item = this->buildList.next;
        int count = 0;

        while (item != &this->buildList && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }

        return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, count);
    }

    return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, p3);
}
