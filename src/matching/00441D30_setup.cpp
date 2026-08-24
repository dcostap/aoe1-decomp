// attempt 1: direct base setup call, then the flag, ftol pair, map offset, and zeroed tail fields
// result: exact match after preserving the original arg order and the y-then-x ftol / table-indexing sequence
// moved to src\matching\00441D30_setup.cpp after local validation

#ifndef DPL_OBJ_SHARED_CONTEXT
class RGE_Master_Doppleganger_Object;
class RGE_Player;

extern unsigned long unified_map_offsets[];

class RGE_Animated_Object {
public:
    int setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    char gap_00[0x4E];
    unsigned char map_draw_level;
    char gap_4F[0x4D];
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;

    int setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z);
};
#endif

int RGE_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z) {
    this->RGE_Animated_Object::setup(master, player, x, y, z);
#ifdef DPL_OBJ_SHARED_CONTEXT
    this->type = 0x19;
#else
    this->map_draw_level = 0x19;
#endif
    int y_i = (int)y;
    int x_i = (int)x;
    this->MapAddress = (unsigned long*)((char*)unified_map_offsets[y_i] + x_i * 4);
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}
