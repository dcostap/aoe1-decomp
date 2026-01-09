#pragma once
#include "common.h"

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;                       // 0x0
    int allocated_size;                      // 0x4
    int active_size;                         // 0x8
    RGE_Static_Object** Objects;             // 0xC
    ulong** Map_Addresses;                   // 0x10
    ulong* Last_Map_Value;                   // 0x14
    int* Object_ids;                         // 0x18

    RGE_Doppleganger_Creator(RGE_Player* param_1, int param_2);
    ~RGE_Doppleganger_Creator();
    int add_doppleganger_check(RGE_Static_Object* param_1, ulong* param_2);
    int remove_doppleganger_check(RGE_Static_Object* param_1);
    void perform_doppleganger_checks();
    void expand_allocations(int param_1);
};

static_assert(sizeof(RGE_Doppleganger_Creator) == 0x1C, "RGE_Doppleganger_Creator Size Mismatch");

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;       // 0x8C
    RGE_Color_Table* draw_color;             // 0x90
    RGE_Master_Static_Object* doppled_master_obj; // 0x94
    int doppled_player;                      // 0x98
    ulong* MapAddress;                       // 0x9C
    ulong LastMapValue;                      // 0xA0
    ulong CantSeeBits;                       // 0xA4
    uchar map_draw_level;                    // 0xA8
    uchar map_color;                         // 0xA9
    int doppledObjectID;                     // 0xAC

    virtual uchar update();                                 // vt0[9]+0x24=0x441EB0
    virtual void rehook();                                  // vt0[11]+0x2C=0x441E00
    virtual void save(int param_1);                         // vt0[12]+0x30=0x441F80
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x441DA0
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, RGE_Static_Object* param_6); // vt0[123]+0x1EC=0x441BB0
    virtual void validate();                                // vt0[124]+0x1F0=0x442050
    virtual int setup(RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[125]+0x1F4=0x441D30
    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, RGE_Static_Object* param_7);
    ~RGE_Doppleganger_Object();
    RGE_Doppleganger_Object(int param_1, RGE_Game_World* param_2, int param_3);
};

static_assert(sizeof(RGE_Doppleganger_Object) == 0xB0, "RGE_Doppleganger_Object Size Mismatch");

