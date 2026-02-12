// Stub constructors/destructors for types used by TRIBE_World init overrides.
#include "../include/TRIBE_Map.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/globals.h"

// --- TRIBE_Map ---
TRIBE_Map::TRIBE_Map(int param_1, RGE_Sound** param_2, char param_3)
    : RGE_Map(param_1, param_2, (uchar)param_3) {
    // Source of truth: tmap.cpp.decomp
    // Delegates to RGE_Map(int fd, RGE_Sound** sounds, uchar load_map)
    // which reads 0x8DD0 bytes from empires.dat via rge_read, then
    // loads terrain/border TShape SLPs and initializes tile sizes.
    this->Game = nullptr;
    this->rge_player = nullptr;
    this->rge_game_world = nullptr;
    this->rge_map_gen_information = nullptr;
    this->zones = nullptr;
    this->old_cliff_x = 0;
    this->old_cliff_y = 0;
    this->safe_cliff_x = 0;
    this->safe_cliff_y = 0;
    this->old_cliff_direction = 0;
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
    this->old_cliff_x = 0;
    this->old_cliff_y = 0;
    this->safe_cliff_x = 0;
    this->safe_cliff_y = 0;
    this->old_cliff_direction = 0;
    memset(this->cliff_master_table, 0, sizeof(this->cliff_master_table));
}

TRIBE_Map::~TRIBE_Map() {}
void TRIBE_Map::data_load_random_map(int p1) {}
void TRIBE_Map::load_random_map(char* p1, char* p2, char* p3, char* p4) {}
uchar TRIBE_Map::do_terrain_brush(long p1, long p2, long p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) { return 0; }
uchar TRIBE_Map::do_elevation_brush(long p1, long p2, long p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_elevation_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) { return 0; }
uchar TRIBE_Map::do_cliff_brush(long p1, long p2, uchar p3, uchar p4) { return 0; }
uchar TRIBE_Map::do_cliff_brush_stroke(long p1, long p2, long p3, long p4, uchar p5, uchar p6) { return 0; }
void TRIBE_Map::map_generate(RGE_Player* p1, RGE_Game_World* p2, RGE_Player_Info* p3, uchar* p4) {}
void TRIBE_Map::map_generate2(RGE_Game_World* p1, long p2, long p3, uchar p4, long p5) {}
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

// --- RGE_Effects (from effects.cpp.decomp) ---
RGE_Effects::RGE_Effects(int param_1) {
    // Source of truth: effects.cpp.decomp @ 0x004490E0
    rge_read(param_1, &this->effect_num, 4);
    if (this->effect_num < 1) {
        this->effects = nullptr;
        this->effect_num = 0;
    } else {
        this->effects = (RGE_Effect*)calloc(this->effect_num, 0x2c);
        for (int i = 0; i < this->effect_num; i++) {
            rge_read(param_1, this->effects[i].name, 0x1f);
            rge_read(param_1, &this->effects[i].effect_list_num, 2);
            if (this->effects[i].effect_list_num < 1) {
                this->effects[i].effect_list = nullptr;
            } else {
                this->effects[i].effect_list = (RGE_Effect_Command*)calloc((int)this->effects[i].effect_list_num, 0xc);
                for (short j = 0; j < this->effects[i].effect_list_num; j++) {
                    RGE_Effect_Command* cmd = &this->effects[i].effect_list[j];
                    rge_read(param_1, &cmd->command, 1);
                    rge_read(param_1, &cmd->change_num1, 2);
                    rge_read(param_1, &cmd->change_num2, 2);
                    rge_read(param_1, &cmd->change_num3, 2);
                    rge_read(param_1, &cmd->change_amount, 4);
                }
            }
        }
    }
}

RGE_Effects::RGE_Effects(char* param_1) {
    // Source of truth: effects.cpp.decomp @ 0x00449260
    // Text file constructor - reads from data file
    // TODO(accuracy): implement full text file parsing via fscanf
    this->effect_num = 0;
    this->effects = nullptr;
}

RGE_Effects::~RGE_Effects() {
    // Source of truth: effects.cpp.decomp @ 0x00449440
    for (short i = 0; i < this->effect_num; i++) {
        if (this->effects[i].effect_list != nullptr) {
            free(this->effects[i].effect_list);
        }
        this->effects[i].effect_list = nullptr;
    }
    if (this->effects != nullptr) {
        free(this->effects);
        this->effects = nullptr;
    }
    this->effect_num = 0;
}

void RGE_Effects::save(int p1) {
    // Source of truth: effects.cpp.decomp @ 0x004494B0
    rge_write(p1, &this->effect_num, 4);
    for (int i = 0; i < this->effect_num; i++) {
        rge_write(p1, this->effects[i].name, 0x1f);
        rge_write(p1, &this->effects[i].effect_list_num, 2);
        for (short j = 0; j < this->effects[i].effect_list_num; j++) {
            RGE_Effect_Command* cmd = &this->effects[i].effect_list[j];
            rge_write(p1, &cmd->command, 1);
            rge_write(p1, &cmd->change_num1, 2);
            rge_write(p1, &cmd->change_num2, 2);
            rge_write(p1, &cmd->change_num3, 2);
            rge_write(p1, &cmd->change_amount, 4);
        }
    }
}

void RGE_Effects::do_effect(short p1, RGE_Player* p2) {
    // Source of truth: effects.cpp.decomp @ 0x004495C0
    if ((int)p1 >= this->effect_num) return;
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) return;
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        switch (cmd->command) {
        case 0: // modify_tobj (set)
            // TODO: p2->modify_tobj(cmd->change_num1, cmd->change_num2, cmd->change_amount, (uchar)cmd->change_num3);
            break;
        case 1: // resource modify
            if (cmd->change_num1 >= 0) {
                if (cmd->change_num2 == 0) {
                    // TODO: p2->new_attribute_num(cmd->change_num1, cmd->change_amount);
                } else {
                    // TODO: p2->add_attribute_num(cmd->change_num1, cmd->change_amount, 0);
                }
            }
            break;
        case 2: // make_available
            // TODO: p2->make_available(cmd->change_num1, (uchar)cmd->change_num2);
            break;
        case 3: // copy_obj
            // TODO: p2->copy_obj(cmd->change_num1, cmd->change_num2);
            break;
        case 4: // modify_tobj_delta
            // TODO: p2->modify_tobj_delta(cmd->change_num1, cmd->change_num2, cmd->change_amount, (uchar)cmd->change_num3);
            break;
        case 5: // modify_tobj_percent
            // TODO: p2->modify_tobj_percent(cmd->change_num1, cmd->change_num2, cmd->change_amount, (uchar)cmd->change_num3);
            break;
        }
    }
}

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
