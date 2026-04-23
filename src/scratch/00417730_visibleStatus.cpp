// tried the straight decompiler shape; first mismatch stayed at the initial register/load order
// fixed the visible-mask player offset to 0xD4; mismatch still begins at the first load sequence
class RGE_Player {
public:
    char gap_00[0xD0];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    char gap_08[0x4];
    RGE_Player* owner;
};

class RGE_Visible_Map;
extern unsigned long* unified_map_offsets[];

class UnitAIModule {
public:
    void* vtable_ptr;
    RGE_Static_Object* objectValue;

    unsigned char visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
};

unsigned char UnitAIModule::visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3) {
    unsigned long* row;
    RGE_Player* pVar1;
    unsigned long mask;

    row = unified_map_offsets[param_3];
    pVar1 = this->objectValue->owner;
    mask = row[param_2];
    if ((pVar1->mutualVisibleMask & mask) != 0) {
        return 0x0f;
    }
    return (unsigned char)(-((pVar1->mutualExploredMask & mask) != 0) & 0x80);
}
