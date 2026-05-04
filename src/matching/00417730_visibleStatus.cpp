// VA: 00417730 UnitAIModule::visibleStatus (60B)
// PDB source: aiuaimod.cpp lines 3900-3910
// __thiscall with 3 params: RGE_Visible_Map* param_1, int param_2 (x), int param_3 (y)
// ret 0Ch = 3 params cleaned.
// Similar to get_visible but accessed via this->objectValue->owner instead of direct player.
// Use #define for absolute address, load-order matching, branch-free explored path.

#define unified_map_offsets ((unsigned long**)0x886808)

class RGE_Visible_Map;

class RGE_Player {
public:
    char gap_00[0xD0];
    unsigned long mutualExploredMask;   // +0xD0
    unsigned long mutualVisibleMask;    // +0xD4
};

class RGE_Static_Object {
public:
    void* vtable_ptr;                   // +0x00
    long id;                            // +0x04
    char gap_08[4];                     // +0x08
    RGE_Player* owner;                  // +0x0C
};

class UnitAIModule {
public:
    void* vtable_ptr;                   // +0x00
    RGE_Static_Object* objectValue;     // +0x04

    unsigned char visibleStatus(class RGE_Visible_Map* param_1, int param_2, int param_3);
};

unsigned char UnitAIModule::visibleStatus(class RGE_Visible_Map* param_1, int param_2, int param_3) {
    unsigned long cell = unified_map_offsets[param_3][param_2];
    RGE_Player* owner = this->objectValue->owner;
    if ((owner->mutualVisibleMask & cell) != 0) return 0x0F;
    if ((cell & owner->mutualExploredMask) != 0) return 0x80;
    return 0;
}
