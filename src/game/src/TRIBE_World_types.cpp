// Stub constructors/destructors for types used by TRIBE_World init overrides.
#include "../include/TRIBE_Map.h"
#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/globals.h"
#include <io.h>

// --- TRIBE_Map ---
TRIBE_Map::TRIBE_Map(int param_1, RGE_Sound** param_2, char param_3)
    : RGE_Map(param_1, param_2, 0) { // Decomp passes 0 (false) for load_map
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Map::TRIBE_Map(binary) param_1=%d param_3=%d", param_1, (int)param_3);

    if (param_3) {
        this->data_load_random_map(param_1);
    }

    this->Game = nullptr;
    this->rge_player = nullptr;
    this->rge_game_world = nullptr;
    this->rge_map_gen_information = nullptr;
    this->zones = nullptr;
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
    memset(this->cliff_master_table, 0, sizeof(this->cliff_master_table));
}

TRIBE_Map::TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8)
    : RGE_Map(param_1, param_2, param_3, param_5, param_6, param_7, param_8) {
    // Source of truth: tmap.cpp.decomp
    // Delegates to RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**)
    // which loads terrain/border definitions from text files.
    this->Game = nullptr;
    this->rge_player = nullptr;
    this->rge_game_world = nullptr;
    this->rge_map_gen_information = nullptr;
    this->zones = nullptr;
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
    memset(this->cliff_master_table, 0, sizeof(this->cliff_master_table));
}

TRIBE_Map::~TRIBE_Map() {}
void TRIBE_Map::data_load_random_map(int p1) {
    // Source of truth: tmap.cpp.decomp @ 0x0050F800.
    this->random_map = (RGE_RMM_Database_Controller*)new TRIBE_RMM_Database_Controller(p1);
}

void TRIBE_Map::load_random_map(char* p1, char* p2, char* p3, char* p4) {
    // Source of truth: tmap.cpp.decomp @ 0x0050F860.
    // Constructor argument order is (param_2, param_3, param_4, param_1).
    this->random_map = (RGE_RMM_Database_Controller*)new TRIBE_RMM_Database_Controller(p2, p3, p4, p1);
}
uchar TRIBE_Map::do_terrain_brush(long p1, long p2, long p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) { return 0; }
uchar TRIBE_Map::do_elevation_brush(long p1, long p2, long p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_elevation_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) { return 0; }
uchar TRIBE_Map::do_cliff_brush(long p1, long p2, uchar p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_cliff_brush_stroke(long p1, long p2, long p3, long p4, uchar p5, uchar p6) { return 0; }
void TRIBE_Map::map_generate(RGE_Player* p1, RGE_Game_World* p2, RGE_Player_Info* p3, uchar* p4) {}
void TRIBE_Map::save(int p1) {}
void TRIBE_Map::delete_cliff(long p1, long p2) {}

// --- RGE_Command (base class) ---
RGE_Command::RGE_Command(RGE_Game_World* param_1, TCommunications_Handler* param_2) {
    // Source of truth: Command.cpp.decomp @ 0x00433D40
    this->world = param_1;
    this->com_hand = param_2;
    this->last_order = nullptr;
    this->last_order_size = 0;
}

void RGE_Command::reset_communications(TCommunications_Handler* param_1) {
    // Source of truth: Command.cpp.decomp @ 0x00433DB0
    this->com_hand = param_1;
}

RGE_Command::~RGE_Command() {
    // Source of truth: Command.cpp.decomp @ 0x00433D90
    this->world = nullptr;
    this->com_hand = nullptr;
    if (this->last_order) {
        free(this->last_order);
        this->last_order = nullptr;
    }
}
void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {}
void RGE_Command::do_command(void* p1) {}
void RGE_Command::command_give_attribute(int p1, int p2, int p3, float p4) {}

// --- RGE_Scenario (base class stubs) ---
RGE_Scenario::~RGE_Scenario() {}
RGE_Static_Object* RGE_Scenario::get_object_pointer(int p1) { return nullptr; }
void RGE_Scenario::rehook() {}
void RGE_Scenario::save(int p1) {}

// --- TRIBE_Command ---
TRIBE_Command::TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm)
    : RGE_Command(world, comm) {
}

TRIBE_Command::~TRIBE_Command() {}
void TRIBE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {}
void TRIBE_Command::do_command(void* p1) {}
void TRIBE_Command::command_give_attribute(int p1, int p2, int p3, float p4) {}
void TRIBE_Command::do_command_give_attribute_tribe(TRIBE_Command_Give_Attribute* p1) {}
void TRIBE_Command::command_give_attribute(int p1, int p2, int p3, float p4, float p5) {}

// --- TRIBE_Effects (from teffects.cpp.decomp) ---
TRIBE_Effects::TRIBE_Effects(int param_1)
    : RGE_Effects(param_1) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D460
    // Just delegates to base class constructor
}

TRIBE_Effects::~TRIBE_Effects() {
    // Source of truth: bucket_050D.cpp.decomp @ 0x0050D4A0
    // Base class destructor handles cleanup
}

void TRIBE_Effects::save(int p1) {
    // Delegates to base class
    RGE_Effects::save(p1);
}

void TRIBE_Effects::do_effect(short p1, RGE_Player* p2) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D4D0
    if ((int)p1 >= this->effect_num) return;
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) return;
    // TRIBE-specific: handle tech enable/disable commands before base do_effect
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        // Command 'f' (0x66 = 102) = tech disable
        // TODO(accuracy): implement tech_abling calls
    }
    RGE_Effects::do_effect(p1, p2);
}

void TRIBE_Effects::do_tech_effect(short p1, RGE_Player* p2) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D550
    RGE_Effect* eff = &this->effects[p1];
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        // Command 'f' (0x66 = 102) = tech disable
        // TODO(accuracy): implement tech_abling calls
    }
}

// --- T_Scenario ---
T_Scenario::T_Scenario(int param_1, RGE_Game_World* param_2) {
    char* base_end = (char*)this + sizeof(RGE_Scenario);
    size_t tribe_size = sizeof(T_Scenario) - sizeof(RGE_Scenario);
    memset(base_end, 0, tribe_size);
}

T_Scenario::T_Scenario(RGE_Game_World* param_1) {
    char* base_end = (char*)this + sizeof(RGE_Scenario);
    size_t tribe_size = sizeof(T_Scenario) - sizeof(RGE_Scenario);
    memset(base_end, 0, tribe_size);
}

T_Scenario::~T_Scenario() {}
RGE_Static_Object* T_Scenario::get_object_pointer(int p1) { return nullptr; }
void T_Scenario::rehook() {}
void T_Scenario::save(int p1) {}

// --- RGE_Tile_List ---
#include "../include/RGE_Tile_List.h"
#include "../include/RGE_Tile_List_Node.h"

RGE_Tile_List::RGE_Tile_List(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x00471E40
    this->list = (RGE_Tile_List_Node*)calloc(param_1, sizeof(RGE_Tile_List_Node));
    this->list_size = param_1;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

void RGE_Tile_List::add_node(int param_1, int param_2) {
    // Source of truth: player.cpp.decomp @ 0x00471D70
    if (this->num_active >= this->list_size) {
        int new_size = this->list_size * 2;
        RGE_Tile_List_Node* new_list = (RGE_Tile_List_Node*)calloc(new_size, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, this->list, this->list_size * sizeof(RGE_Tile_List_Node));
        free(this->list);
        this->list = new_list;
        this->list_size = new_size;
    }
    this->list[this->num_active].col = param_1;
    this->list[this->num_active].row = param_2;
    this->num_active++;
    this->new_count++;
}

void RGE_Tile_List::del_list() {
    // Source of truth: player.cpp.decomp @ 0x00471DF0
    this->num_active = 0;
    this->new_count = 0;
    if (this->collapse_list != 0) {
        free(this->list);
        this->list_size = 8;
        this->list = (RGE_Tile_List_Node*)calloc(8, sizeof(RGE_Tile_List_Node));
        this->collapse_list = 0;
    }
}
