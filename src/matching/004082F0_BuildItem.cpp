// VA: 004082F0 BuildItem::BuildItem(BuildItem*)
// aiblditm.cpp lines 87-90

// attempt 1: natural C++ pointer copy constructor

#include <string.h>

class BaseItem {
public:
    int vtable;             // +0x00
    int typeIDValue;        // +0x04
    int gameIDValue;        // +0x08
    int uniqueIDValue;      // +0x0C
    char nameValue[64];     // +0x10
    float xValue;           // +0x50
    float yValue;           // +0x54
    float zValue;           // +0x58
    float xSizeValue;       // +0x5C
    float ySizeValue;       // +0x60
    float zSizeValue;       // +0x64
    int skipValue;          // +0x68

    BaseItem(BaseItem* src);
};

class BuildItem : public BaseItem {
public:
    void* next;                     // +0x6C
    void* prev;                     // +0x70
    int buildCategoryValue;         // +0x74
    int numberValue;                // +0x78
    int priorityValue;              // +0x7C
    int progressValue;              // +0x80
    int builtValue;                 // +0x84
    int buildAttemptsValue;         // +0x88
    int buildFromValue;             // +0x8C
    int terrainSetValue;            // +0x90
    int terrainAdjacencyValue[2];   // +0x94, +0x98
    int placeOnElevationValue;      // +0x9C
    int numberBuildsValue;          // +0xA0
    int buildCapValue;              // +0xA4
    int skipCyclesValue;            // +0xA8
    unsigned char permanentSkipValue; // +0xAC

    BuildItem(BuildItem* src);
};

// 004082F0 - 177 bytes
BuildItem::BuildItem(BuildItem* src) : BaseItem(static_cast<BaseItem*>(src)) {
    this->next = 0;
    this->prev = 0;
    this->buildCategoryValue = src->buildCategoryValue;
    this->numberValue = src->numberValue;
    this->priorityValue = src->priorityValue;
    this->progressValue = src->progressValue;
    this->builtValue = src->progressValue;       // NOTE: builtValue copies progressValue!
    this->buildAttemptsValue = src->buildAttemptsValue;
    this->buildFromValue = src->buildFromValue;
    this->terrainSetValue = src->terrainSetValue;
    this->placeOnElevationValue = src->placeOnElevationValue;
    this->numberBuildsValue = 0;
    this->buildCapValue = -1;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = 0;
    this->vtable = 0x56E734;
    this->terrainAdjacencyValue[0] = src->terrainAdjacencyValue[0];
    this->terrainAdjacencyValue[1] = src->terrainAdjacencyValue[1];
}
