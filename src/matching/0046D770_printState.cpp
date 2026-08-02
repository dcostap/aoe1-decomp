// VA: 0046D770 PathingSystem::printState
// PDB source: pathsys.cpp, lines 2233-2242
// Attempt log:
// - Replaced the prior placeholder with the binary-supported printState source
//   shape: two cdecl virtual debug calls followed by an indexed open-path scan.
// - Canonical ownership: MGP_openPaths is an 8-byte MGP_FloatHeap array at
//   +0x4F614, facetValue is [255][255] at +0x0C, and the counters/mask are the
//   named fields at +0x11DC2C/+0x11DC38/+0x11DCD8.
// - A natural MGP_FloatHeap* loop was exact-size but anchored at +0x4F61C;
//   the executable proves the source cursor is the interior y byte at +0x4F61D,
//   so the living source keeps that narrow, binary-supported cursor form.
// - Probe 1 baseline: natural typed record pointer and > 0 guard, 18 differing
//   bytes; the compiler added a redundant count test and used the record base.
// - Probe 2: one-based `i <= numberOpenPathsValue` guard corrected the branch
//   shape and mask offset; 6 differing bytes remained at the record cursor.
// - Probe 3: anchored the cursor at `MGP_openPaths[1].y` with proven byte/dword
//   offsets; exact 190-byte match.

typedef unsigned char uchar;

#define VPAD1(n) virtual void __cdecl vpad_##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Moving_Object {
public:
    VPAD64(0)
    VPAD16(64)
    VPAD1(80)
    virtual void __cdecl print(char* format, ...);
};

class PathingSystem {
public:
    void* vtable_ptr;
    int xSizeValue;
    int ySizeValue;
    unsigned char facetValue[255][255];
    unsigned char pad_fe0d[3];
    int MGP_costValue[255][255];

    struct MGP_FloatHeap {
        unsigned char x;
        unsigned char y;
        unsigned short next;
        int total;
    };

    MGP_FloatHeap MGP_openPaths[65026];
    unsigned char obstructionValue[1020][255];
    unsigned char miscValue[255][255];
    unsigned char pad_11dc29[3];
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    void* mapValue;
    void* worldValue;
    void* currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float* currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;
    char gap_11dc64[0x74];
    unsigned char CurrentFacetMask;

    void printState(RGE_Moving_Object* obj);
};

void PathingSystem::printState(RGE_Moving_Object* obj)
{
    obj->print("    There are %d open paths and %d traversed paths.",
        this->numberOpenPathsValue, this->numberTraversedPathsValue);
    obj->print("    The open paths:");

    int i = 1;
    if (i <= this->numberOpenPathsValue) {
        unsigned char* path = &this->MGP_openPaths[1].y;
        do {
            unsigned char facet = this->facetValue[path[-1]][path[0]];
            if ((facet & 0xf8) == this->CurrentFacetMask) {
                facet &= 7;
            } else {
                facet = 0xff;
            }
            obj->print("      %5d: (%d, %d), total=%d, facet=%d.",
                i, path[-1], path[0], *(int*)(path + 3), facet);
            ++i;
            path += 8;
        } while (i <= this->numberOpenPathsValue);
    }
}
