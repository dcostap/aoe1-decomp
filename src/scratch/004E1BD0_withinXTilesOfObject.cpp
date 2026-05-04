// VA: 004E1BD0, TribeInformationAIModule::withinXTilesOfObject, 310 bytes
// Source: taiinfmd.cpp lines 6750-6791
// FLAGS: default
//
// LEFT IN SCRATCH: Function relies on non-standard register convention.
// The ORIGINAL computes ftol(obj->field_38) → obj_y stored to [esp+10h]
// (NEVER READ from stack, overwritten by loop counter), and expects the
// CALLER to pass obj_y in ebx register. The second ftol(obj->field_3C)
// → obj_x is stored at [esp+14h] and used in the distance calculation.
//
// Our VC5 computes both obj_x and obj_y as local variables and stores
// both on the stack, generating 288 bytes vs 310 (22 bytes short).
// The register convention (ebx = obj_y from caller) is impossible to
// replicate in standard C++ without inline asm.
//
// Struct layout confirmed correct:
//   ImportantObjectEntry: id(+0), type(+2), gap(+2), x(+8), y(+9),
//                         gap(+0A), owner(+0B), rest(+0C to +0x23)
//   Stride: 0x24 ✓

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#pragma pack(push, 1)
struct ImportantObjectEntry {
    int id;             // +0x00
    short type;         // +0x04
    uchar x;            // +0x08 (tile coordinate)
    uchar y;            // +0x09
    uchar gap_0A;       // +0x0A
    uchar owner;        // +0x0B
    char rest[0x1A];    // +0x0C to +0x23 (total 0x24 = 36 bytes, matches stride)
};
#pragma pack(pop)

class RGE_Static_Object {
public:
    char gap_00[0x30];
    float hp;           // +0x30
    float pad_34;
    float y_float;      // +0x38 (y tile coordinate, ftol'd first)
    float x_float;      // +0x3C (x tile coordinate, ftol'd second)
    char gap_40[0x08];
    uchar object_state; // +0x48
};

// Owner check vtable proxy — vtable slot 6 at +0x18
struct OwnerCheckProxy {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int v18(int owner);
};

class MainDecisionAIModule {
public:
    char pad_00[0xF0];
    OwnerCheckProxy* some_object;  // +0xF0
    
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;               // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;            // +0x110
    ImportantObjectEntry* importantObjectMemory;  // +0x114
    
    int withinXTilesOfObject(RGE_Static_Object* obj, int tile_range, 
                             int type1, int type2, int type3, int type4);
};

int TribeInformationAIModule::withinXTilesOfObject(
    RGE_Static_Object* obj, int tile_range, 
    int type1, int type2, int type3, int type4)
{
    int tile_range_sq = tile_range * tile_range;
    int obj_y = (int)(obj->y_float);
    int obj_x = (int)(obj->x_float);

    int closest_dist = -1;
    int closest_id = -1;

    for (int i = 0; i < this->maxImportantObjectMemory; i++) {
        ImportantObjectEntry* entry = &this->importantObjectMemory[i];
        RGE_Static_Object* target = this->md->object(entry->id);

        if (target == 0)
            continue;
        if (target->object_state > 2)
            continue;

        // Skip when hp == 0.0f (fcomp with 0.0)
        if (target->hp == 0.0f)
            continue;

        // Type check
        int type = entry->type;
        if (type != type1 && type != type2 && type != type3 && type != type4)
            continue;

        // Owner check via vtable call
        int owner = entry->owner;
        if (this->md->some_object->v18(owner) == 0)
            continue;

        // Distance calculation
        int dx = (int)entry->x - obj_x;
        int dy = (int)entry->y - obj_y;
        int dist = dx * dx + dy * dy;

        if (dist <= tile_range_sq && (dist < closest_dist || closest_id == -1)) {
            closest_dist = dist;
            closest_id = entry->id;
        }
    }

    return closest_id;
}
