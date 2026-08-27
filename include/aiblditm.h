#ifndef AOE1_AIBLDITM_H
#define AOE1_AIBLDITM_H

// Compiler-facing surface for the aiblditm.cpp source module.
// The BaseItem layout and constructors come from the reviewed aibitm surface.
#include "aibitm.h"

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
    BuildItem(int category, int typeID, int uniqueID, int number,
              int priority, int buildFrom, char* name, float xSize,
              float ySize, float zSize, int terrainSet, int adjacency0,
              int adjacency1, int elevation);
    BuildItem(BuildItem* source);
    BuildItem(const BuildItem& source);
    virtual ~BuildItem();

    int buildCategory() const;
    int number() const;
    int priority() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int terrainSet() const;
    int terrainAdjacency(int index) const;
    int placeOnElevation() const;
    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    int numberBuilds();
    void incrementNumberBuilds();
    void setNumberBuilds(int value);
    int buildCap();
    void setBuildCap(int value);
    int skipCycles();
    void incrementSkipCycles();
    void setSkipCycles(int value);
    unsigned char permanentSkip();
    void setPermanentSkip(unsigned char value);
};

int __cdecl operator==(const BuildItem& left, const BuildItem& right);
int __cdecl operator!=(const BuildItem& left, const BuildItem& right);
int __cdecl operator<(const BuildItem& left, const BuildItem& right);
int __cdecl operator>(const BuildItem& left, const BuildItem& right);

typedef char aiblditm_build_item_size[(sizeof(BuildItem) == 0xB0) ? 1 : -1];
typedef char aiblditm_terrain_values_offset[
    (sizeof(BaseItem) + sizeof(BuildItem*) + sizeof(BuildItem*) +
     sizeof(int) * 7 == 0x90) ? 1 : -1];

#endif
