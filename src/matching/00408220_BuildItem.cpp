// VA: 00408220 BuildItem::BuildItem(int,int,int,int,int,int,char*,float,float,float,int,int,int,int)
// aiblditm.cpp lines 63-66

// Attempt log:
// - body assignments and reordered bodies kept a 194-byte function but left a
//   63-byte register/scheduling mismatch after the BaseItem call.
// - the donor-backed pointer types for vtable/next/prev were retained; adding a
//   polymorphic surface, an explicit base call, register parameters, and a
//   focused variant sweep did not improve codegen.
// - exact source shape: initialize the scalar members in the constructor
//   initializer list, then assign the array elements and vtable pointer in the
//   body. This reproduces the original post-base load/store schedule exactly.

#include <string.h>

class BaseItem {
public:
    void* vtable_ptr;
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

    BuildItem(int cat, int typeID, int uniqueID, int number, int priority,
              int buildFrom, char* name, float xSize, float ySize, float zSize,
              int terrainSet, int adj0, int adj1, int elevation);
};

// 00408220 - 194 bytes
BuildItem::BuildItem(int cat, int typeID, int uniqueID, int number, int priority,
                     int buildFrom, char* name, float xSize, float ySize, float zSize,
                     int terrainSet, int adj0, int adj1, int elevation)
    : BaseItem(typeID, -1, uniqueID, name, -1.0f, -1.0f, -1.0f, xSize, ySize, zSize),
      next(0), prev(0), buildCategoryValue(cat), numberValue(number),
      priorityValue(priority), progressValue(0), builtValue(0),
      buildAttemptsValue(0), buildFromValue(buildFrom), terrainSetValue(terrainSet),
      placeOnElevationValue(elevation), numberBuildsValue(0), buildCapValue(-1),
      skipCyclesValue(0), permanentSkipValue(0) {
    this->terrainAdjacencyValue[0] = adj0;
    this->vtable_ptr = (void*)0x56E734;
    this->terrainAdjacencyValue[1] = adj1;
}
