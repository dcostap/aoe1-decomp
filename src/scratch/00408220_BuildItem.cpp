// VA: 00408220 BuildItem::BuildItem(int,int,int,int,int,int,char*,float,float,float,int,int,int,int)
// aiblditm.cpp lines 63-66

// attempt 1-4: various init list/body orderings (best 32%)
// attempt 5: explicit temp variables (47%)
// attempt 6: moved buildFrom/terrainSet before zero block (37%)
// attempt 7: variant_lab (7 variants, all same basin, 32%)
// attempt 8: volatile params (didn't help)
// left in scratch: persistent register-allocation drift
// Original uses ECX for cat load, EDX for number, ECX for priority,
// then hoists buildFrom→EDX and terrainSet→ECX before zero block.
// VC5 in our TU puts cat→EAX, number→ECX, priority→EDX, with
// buildFrom/terrainSet loaded AFTER zero block. Size matches (194B),
// all fields, vtable, ret 38h correct. Pure register-allocation drift.

#include <string.h>

class BaseItem {
public:
    int vtable;
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    BaseItem(int typeID, int gameID, int uniqueID, char* name,
             float x, float y, float z, float xSize, float ySize, float zSize);
};

class BuildItem : public BaseItem {
public:
    void* next;
    void* prev;
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

    BuildItem(int cat, int typeID, int uniqueID, int number, int priority,
              int buildFrom, char* name, float xSize, float ySize, float zSize,
              int terrainSet, int adj0, int adj1, int elevation);
};

// 00408220 - 194 bytes
BuildItem::BuildItem(int cat, int typeID, int uniqueID, int number, int priority,
                     int buildFrom, char* name, float xSize, float ySize, float zSize,
                     int terrainSet, int adj0, int adj1, int elevation)
    : BaseItem(typeID, -1, uniqueID, name, -1.0f, -1.0f, -1.0f, xSize, ySize, zSize) {
    this->buildCategoryValue = cat;
    this->numberValue = number;
    this->priorityValue = priority;
    this->next = 0;
    this->prev = 0;
    this->progressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
    this->numberBuildsValue = 0;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = 0;
    this->buildFromValue = buildFrom;
    this->terrainSetValue = terrainSet;
    this->terrainAdjacencyValue[0] = adj0;
    this->placeOnElevationValue = elevation;
    this->buildCapValue = -1;
    this->vtable = 0x56E734;
    this->terrainAdjacencyValue[1] = adj1;
}
