// VA: 00417730 UnitAIModule::visibleStatus (60B)
// PDB source: aiuaimod.cpp lines 3900-3910
// tried direct inline access and row/mask/player local variants; best match gets first 19 bytes exact
// remaining drift: VC5 keeps loading mask into edx before owner into ecx/eax, then computes the explored return in eax instead of the original edx/dl neg+sbb byte pattern

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
    char gap_08[4];
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
    RGE_Player* player;
    unsigned long mask;
    unsigned long explored;

    row = unified_map_offsets[param_3];
    mask = row[param_2];
    player = this->objectValue->owner;
    if ((player->mutualVisibleMask & mask) != 0) {
        return 0x0F;
    }
    explored = player->mutualExploredMask & mask;
    return (unsigned char)(-((int)(explored != 0)) & 0x80);
}
