// TribeBuildAIModule::skipNextBuildListItem
// VA: 004D4460, taibldmd.cpp:439-459
// Baseline: natural sentinel-list walk and the typed BuildItem/AI surfaces.
// Probe 2: keep the strategic-number comparison as one source expression; the
// original carries that call result directly into the typeID comparison.
// Probe 3: use the same combined sentinel/null loop form as the exact sibling
// nextBuildListItemCategory; its bottom compare should target the loop test.

#ifndef TAIBLDMD_SHARED_CONTEXT
class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID();
    int skip();
    void setSkip(int value);
};

class BuildItem : public BaseItem {
public:
    virtual ~BuildItem();

    BuildItem* next;                 // +0x6C
    BuildItem* prev;                 // +0x70
    int buildCategoryValue;          // +0x74
    int numberValue;                 // +0x78
    int priorityValue;               // +0x7C
    int progressValue;               // +0x80
    int builtValue;                  // +0x84
    int buildAttemptsValue;          // +0x88
    int buildFromValue;              // +0x8C
    int terrainSetValue;             // +0x90
    int terrainAdjacencyValue[2];    // +0x94
    int placeOnElevationValue;       // +0x9C
    int numberBuildsValue;           // +0xA0
    int buildCapValue;               // +0xA4
    int skipCyclesValue;             // +0xA8
    unsigned char permanentSkipValue;// +0xAC
    unsigned char endPad[3];         // +0xAD

    int built();
    int inProgress();
    int buildCategory();
    void setBuildAttempts(int value);
    void incrementSkipCycles();
    int skipCycles();
    void setPermanentSkip(unsigned char value);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;             // +0xF0
    char gap_1A0[0x41C];             // through +0x5BC
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int value);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;// +0x1146C
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;   // +0x5BC

    void skipNextBuildListItem();
};
#endif

void TribeBuildAIModule::skipNextBuildListItem()
{
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1) {
            if (item->typeID() != this->md->tacticalAI.strategicNumber(0xB1) ||
                item->buildCategory() != 0) {
                item->setBuildAttempts(this->md->tacticalAI.strategicNumber(0x72));
                item->setSkip(1);
                item->incrementSkipCycles();
                if (item->skipCycles() == this->md->tacticalAI.strategicNumber(0x92)) {
                    item->setPermanentSkip(1);
                }
                return;
            }
        }

        item = item->next;
    }
}
