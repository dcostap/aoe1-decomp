#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

// Default constructor
RGE_Doppleganger_Object::RGE_Doppleganger_Object()
    : RGE_Animated_Object()
{
    this->doppled_object = nullptr;
    this->draw_color = nullptr;
    this->doppled_master_obj = nullptr;
    this->doppled_player = 0;
    this->MapAddress = nullptr;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = '\0';
    this->map_color = '\0';
    this->doppledObjectID = -1;
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441A70
RGE_Doppleganger_Object::RGE_Doppleganger_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Animated_Object(param_1, param_2, 0)
{
    int fd = param_1;

    this->doppled_object = nullptr;
    this->draw_color = nullptr;
    this->doppled_master_obj = nullptr;
    this->doppled_player = 0;
    this->MapAddress = nullptr;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = '\0';
    this->map_color = '\0';
    this->doppledObjectID = -1;

    if (param_3 != 0) {
        this->setup(fd, param_2);
    }

    // Read doppleganger-specific fields after setup
    int temp_int = 0;

    rge_read(fd, &temp_int, 4);
    this->doppled_object = (RGE_Static_Object*)temp_int; // stored as int, rehook resolves to pointer

    this->doppledObjectID = -1;

    rge_read(fd, &this->map_draw_level, 1);
    rge_read(fd, &this->map_color, 4);

    rge_read(fd, &temp_int, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)temp_int; // stored as int, rehook resolves

    rge_read(fd, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(fd, &this->CantSeeBits, 4);
    }
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441DA0, dpl_obj.cpp.asm @ 0x00441DA0
int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Animated_Object::setup(param_1, param_2);
    this->type = 0x19;

    // Compute MapAddress from unified_map_offsets using world coordinates
    int y = (int)this->world_y;
    int x = (int)this->world_x;
    this->MapAddress = unified_map_offsets[y] + x;

    this->LastMapValue = 0;
    this->CantSeeBits = 0;

    return 1;
}
