// TribeBuildAIModule::mostNeededResource
// VA: 004D4F80, taibldmd.cpp:962-1026
//
// The source below keeps the binary-proven BuildItem sentinel walk and the
// period-style typed AI/resource call surfaces.  The initial count is allowed
// to reuse the incoming ResourceItem reference home, as in the original.
// Attempt log:
// 1: replaced the fake __fastcall helper-pointer scaffold with the typed
//    ResourceItem/BuildItem/TRIBE_Player surfaces; size, frame, calls, and CFG
//    all became exact, leaving one byte at the max-count exit.
// 2: folded the increment into the comparison; VC5 emitted the same bytes.
// 3: changed the max-count return to a natural loop break, restoring the
//    original shared final `return count` reload and exact bytes.
// Main-agent audit restored polymorphic player/main-AI ownership; emitted
// code remains exact.

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    void setAllValues(int value);
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    void objectCost(int type, int amount, ResourceItem* item, int flag);
    void researchCost(int type, int amount, ResourceItem* item, int flag);
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID();
};

class BuildItem : public BaseItem {
public:
    virtual ~BuildItem();

    BuildItem* next;
    BuildItem* prev;
    char gap_74[0xB0 - 0x74];

    int buildCategory();
    int inProgress();
    int built();
    int numberBuilds();
    int buildCap();
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;
    char gap_1A0[0x5BC - 0x1A0];
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0x12568];
    TRIBE_Player* aiPlayer;
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;

    int mostNeededResource(ResourceItem& item, int maxCount);
};

int TribeBuildAIModule::mostNeededResource(ResourceItem& item, int maxCount)
{
    item.setAllValues(0);

    BuildItem* buildItem = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;

    if (buildItem != sentinel) {
        while (buildItem != sentinel) {
            if (buildItem == 0) {
                break;
            }

            if (buildItem->built() == 0 &&
                buildItem->inProgress() == 0 &&
                buildItem->buildCategory() != 6) {
                int cap = buildItem->buildCap();
                if (cap == -1 ||
                    buildItem->numberBuilds() <= buildItem->buildCap()) {
                    if (buildItem->buildCategory() == 1 ||
                        buildItem->buildCategory() == 4) {
                        this->md->aiPlayer->researchCost(
                            buildItem->typeID(), -1, &item, 1);
                    } else {
                        this->md->aiPlayer->objectCost(
                            buildItem->typeID(), -1, &item, 1);
                    }

                    if (++count == maxCount) {
                        break;
                    }
                }
            }

            buildItem = buildItem->next;
        }
    }

    return count;
}
