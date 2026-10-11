#ifndef AOE1_AIBLDITM_H
#define AOE1_AIBLDITM_H

#include "aibitm.h"

// Build-list categories. AIBuildList::loadBuildList maps the leading letter of each line to one:
// B and A to BUILDING, R to RESEARCH, U and T to UNIT, L to LOAD_BUILD_LIST, C to BLOCKING_RESEARCH,
// E to ENABLE_ATTACK, and G to GATHERER_PERCENTAGE. Only GATHERER_PERCENTAGE has a developer name
// (insertGathererPercentage); the others are cleanup labels. See decomp_notes/build_categories.md.
#define BUILD_CATEGORY_BUILDING            0
#define BUILD_CATEGORY_RESEARCH            1
#define BUILD_CATEGORY_UNIT                2
#define BUILD_CATEGORY_LOAD_BUILD_LIST     3
#define BUILD_CATEGORY_BLOCKING_RESEARCH   4
#define BUILD_CATEGORY_ENABLE_ATTACK       5
#define BUILD_CATEGORY_GATHERER_PERCENTAGE 6

class BuildItem : public BaseItem {
  public:
    BuildItem* next;
    BuildItem* prev;
    int buildCategoryValue;
    int numberValue;
    int priorityValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int buildFromValue;
    int terrainSetValue;
    int terrainAdjacencyValue[2];
    int placeOnElevationValue;
    int numberBuildsValue;
    int buildCapValue;
    int skipCyclesValue;
    unsigned char permanentSkipValue;

    BuildItem();
    BuildItem(
        int bc, int ti, int bi, int n, int p, int bf, char* name, float x, float y, float z, int tSet, int tOne,
        int tTwo, int pEle
    );
    BuildItem(BuildItem* bi);
    BuildItem(const BuildItem& bi);
    virtual ~BuildItem();

    int buildCategory() const;
    int number() const;
    int priority() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int terrainSet() const;
    int terrainAdjacency(int v) const;
    int placeOnElevation() const;
    void setInProgress(int p);
    void setBuilt(int v);
    void setBuildAttempts(int v);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    int numberBuilds();
    void incrementNumberBuilds();
    void setNumberBuilds(int v);
    int buildCap();
    void setBuildCap(int v);
    int skipCycles();
    void incrementSkipCycles();
    void setSkipCycles(int v);
    unsigned char permanentSkip();
    void setPermanentSkip(unsigned char v);
};

int __cdecl operator==(const BuildItem& one, const BuildItem& two);
int __cdecl operator!=(const BuildItem& one, const BuildItem& two);
int __cdecl operator<(const BuildItem& one, const BuildItem& two);
int __cdecl operator>(const BuildItem& one, const BuildItem& two);

typedef char aiblditm_build_item_size[(sizeof(BuildItem) == 0xB0) ? 1 : -1];
typedef char aiblditm_terrain_values_offset
    [(sizeof(BaseItem) + sizeof(BuildItem*) + sizeof(BuildItem*) + sizeof(int) * 7 == 0x90) ? 1 : -1];

#endif
