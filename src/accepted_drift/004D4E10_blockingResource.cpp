// VA: 004D4E10 TribeBuildAIModule::blockingResource
// Source: taibldmd.cpp lines 915-956
// Attempt log:
// 1: natural source from packet/decompiler with /GX for ResourceItem EH cleanup: close but BaseItem size was 0x68, shifting BuildItem next/md offsets by -4.
// 2: correct BaseItem local layout to 0x6C so next is +0x6C and md is +0x5BC.
// 3: reshape list walk as do/while with post-loop sentinel/null checks; original does not return immediately after advancing to sentinel, but register coloring flipped this to EDI; rolled back.
// 4: add explicit self local to try to keep this in EBX and sentinel in EDI; no change in that shape, rolled back.
// 5: use top-guarded while with post-loop sentinel check: register coloring flipped this/sentinel.
// 6: explicit goto-shaped loop compiled same as early-return shape.
// 7: combined while condition matched block layout; remaining drift is this/sentinel register swap (EDI/EBX).
// 8: add explicit self local in the combined-condition shape to try to color this as EBX; no register change.
// 9: const sentinel/direct this spelling: no register change.
// ACCEPTED_DRIFT: reviewed 13-byte localized VC5 register-coloring drift only.
// Original keeps this in EBX and sentinel in EDI; rebuilt keeps this in EDI and sentinel in EBX.
// Block layout, calls, stack/EH offsets, object sizes, and behavior match; differences are address/register encodings and pop order only.

class BuildItem;
class ResourceItem;
class TRIBE_Player;
class TribeResourceAIModule;
class MainDecisionAIModule;

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x6C - 0x04];
    int typeID() const;
    int skip() const;
};

class BuildItem : public BaseItem {
public:
    BuildItem* next; // +0x6C
    BuildItem* prev;
    char gap_74[0x98 - 0x74];
    int buildCategoryValue; // +0x98
    char gap_9C[0xAC - 0x9C];
    unsigned char permanentSkipValue; // +0xAC

    int buildCategory() const;
    int built() const;
    int inProgress() const;
    unsigned char permanentSkip();
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    char gap_0C[0x70 - 0x0C];

    ResourceItem(int count);
};

class TRIBE_Player {
public:
    void objectCost(int type, int amount, ResourceItem* item, int flag);
    void researchCost(int type, int amount, ResourceItem* item, int flag);
};

class TribeResourceAIModule {
public:
    int resourcesAvailable(ResourceItem* item);
    int unavailableResource(ResourceItem* item);
};

class MainDecisionAIModule {
public:
    char gap_0000[0x10D7C];
    TribeResourceAIModule resourceAI; // +0x10D7C
    char gap_10D80[0x1256C - 0x10D80];
    TRIBE_Player* aiPlayer; // +0x1256C
};

class TribeBuildAIModule {
public:
    char gap_000[0x0F0];
    BuildItem buildList; // +0x0F0
    char gap_1A0[0x5BC - 0x1A0];
    MainDecisionAIModule* md; // +0x5BC

    int blockingResource();
};

int TribeBuildAIModule::blockingResource()
{
    BuildItem* item;
    BuildItem* const sentinel = &this->buildList;

    item = this->buildList.next;
    while (item != sentinel && item != 0 &&
           (item->built() || item->inProgress() || item->skip() == 1 || item->permanentSkip())) {
        item = item->next;
    }
    if (item == sentinel || item == 0) {
        return -1;
    }

    ResourceItem itemCost(4);
    if (item->buildCategory() == 1 || item->buildCategory() == 4) {
        this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
    }
    else {
        this->md->aiPlayer->objectCost(item->typeID(), -1, &itemCost, 1);
    }

    if (!this->md->resourceAI.resourcesAvailable(&itemCost)) {
        return this->md->resourceAI.unavailableResource(&itemCost);
    }
    return -1;
}
