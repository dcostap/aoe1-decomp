// 004D5F00 TribeConstructionAIModule::canPlace
// Attempt log:
// 1: Natural reconstruction from packet/decompiler with local stubs and /GX for EH temp ConstructionItem; compiled close but ConstructionItem was 0x74 not 0x80, shifting fields/frame by -0xC.
// 2: Add ConstructionItem tail pad to exact 0x80: frame/offsets now match, but compiler omitted original manual temp list self-link stores.
// 3: Explicitly initialize tempLots.next/tempLots.prev to &tempLots after construction: main body 464 bytes, now only helper call context missing.
// 4: Model fallback placement helper as subobject at `[this+314h] + 0xCEC`, not direct pointer: only four FPU test-mask bytes differ.
// 5: Spell bounds checks as negated >= to get VC5 test ah,41 instead of test ah,01.
// FLAGS: config/flags/004D5F00_canPlace.rsp uses /GX for original EH frame.

extern int useInfluencePlacement;

#ifndef TAICONMD_SHARED_CONTEXT
class BuildItem;
class TribeInformationAIModule {
public:
    int influenceCanPlaceStructure(BuildItem*);
};

class BaseItem {
public:
    virtual ~BaseItem();
    int typeID();
    float xSize();
    float ySize();
    char gap_04[0x68];
};

class BuildItem : public BaseItem {
public:
    char gap_6c[0x44];
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem();
    ~ConstructionItem();
    int built();
    int inProgress();
    ConstructionItem* next; // +6c
    ConstructionItem* prev; // +70
    char gap_74[0x0c];
};

class PlacementHelper {
public:
    int canPlace(BuildItem* item);
};

class TribeConstructionAIModule {
public:
    char gap_000[0x0f0];
    int field_f0;
    ConstructionItem constructionLots; // +f4
    char gap_174[0x2fc - 0x174];
    float x;
    float y;
    char gap_304[4];
    int max_x;
    int max_y;
    char gap_310[4];
    PlacementHelper* helper; // +314

    int canPlace(BuildItem* item);
};
#endif

int TribeConstructionAIModule::canPlace(BuildItem* item)
{
    if (this->x <= 0.0 || this->y <= 0.0 || (float)this->max_x <= this->x || (float)this->max_y <= this->y) {
        return ((TribeInformationAIModule*)((char*)this->md + 0xcec))->influenceCanPlaceStructure(item);
    }

    if (item->typeID() == 0x2d) {
        return 1;
    }

    if (useInfluencePlacement == 1 || this->field_f0 == 0) {
        return ((TribeInformationAIModule*)((char*)this->md + 0xcec))->influenceCanPlaceStructure(item);
    }

    ConstructionItem tempLots;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;
    ConstructionItem* cur = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (cur != end && cur != 0) {
        if (cur->typeID() == item->typeID() ||
            (cur->xSize() == item->xSize() && cur->ySize() == item->ySize() && cur->typeID() == -1)) {
            if (!cur->built() && !cur->inProgress()) {
                return 1;
            }
        }
        cur = cur->next;
    }
    return 0;
}
