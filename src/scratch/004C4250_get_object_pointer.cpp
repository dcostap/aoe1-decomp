// VA: 004C4250 RGE_Static_Object::get_object_pointer
// PDB source: stat_obj.cpp lines 1978-2011
#include <stdlib.h>

// Attempt log:
// baseline: natural owner/object-list search with the binary-proven
// player-index and world/player layouts; exact size/call set, 139 bytes differ.
// liveness: delayed signed compare-index initialization until after the player
// count guard; reduced the mismatch to 37 bytes and preserved all call sites.
// liveness: parameter-home reuse and several declaration/type/order variants
// either widened the function or emitted the same 37-byte codegen basin; rolled back.
// variant: 32 natural declaration/update variants produced only the same
// 37-byte basin or a 227-byte context tail; no exact candidate.
// fresh worker: direct (short) casts of the byte player index widened to 227B/190;
// restored the canonical compare-index source.
// fresh worker: register-qualified compare-index local emitted the same 219B/37
// basin; restored the ordinary local.
// 2026-08-10 orch-statobj-fresh-03 fresh pass (7 meaningful probes):
// unsigned-short/explicit-promotion, int-width, comma-update, and decompiler
// parameter-home/index forms either widened the body or emitted the same 219B/37
// basin. The unsigned-short Ghidra uVar4 spelling with signed casts was also a
// codegen duplicate. All six calls and canonical owner/world/player/list accesses
// remain exact; only ESI-owner versus EDX-compare-index loop-tail coloring and its
// dependent branch displacements differ.
// 2026-08-10 wave20-statobj-01 fresh pass (9 meaningful probes):
// a 32-variant declaration/owner-test/update lab, direct owner rereads,
// function-scope Ghidra local ordering, canonical polymorphic Player/World/List
// surfaces, explicit byte-to-short conversion, and signed/unsigned width pairs
// either reproduced the same 219B/37 basin or widened the function. The final
// unsigned-width variant widened to 247B/237; restored the clean source.
// left in scratch: best source is the readable owner/world/player reconstruction;
// remaining drift is only owner/compare-index register coloring and the loop tail.
// 2026-08-11 sa-2ff614d9-r1 fresh pass (9 meaningful probes): reordered the
// object-id/owner declarations, mixed direct byte-promotion with the named
// compare local, made the parameter-home reset explicit, restored <stdlib.h>,
// reversed equality operands, scoped the compare temporary, combined register
// hints, and tried a const owner pointer; all retained-size variants stayed in
// the 219B/37 basin or widened. A 24-variant mixed loop-surface lab likewise
// found no exact candidate. Restored the clean readable source; no probe moved
// the ESI-owner versus EDX-compare-index loop-tail hunk.
// 2026-08-12 orch2-4C4250-tail focused tail pass (3 meaningful probes): moving
// world reload before compare assignment widened to 227B/190; reusing the dead
// id home after the byte increment was a 219B/37 duplicate; combining both
// changes widened to 227B/190. Restored the clean source; the original
// increment/home/world/word-compare order remains unresolved.
// 2026-08-12 follow-C4250-r1 pass: adding the binary-supported polymorphic
// surface to RGE_Object_List, then to RGE_Player/RGE_Game_World, left the
// 219B/37 output unchanged. Routing the tail compare through the dead id
// parameter widened to 229B/158; swapping compare/index declaration order
// gave 219B/52; an explicit tail compare zero was a 219B/37 duplicate.
// Restored the readable clean source. Direct find_by_id calls remain exact;
// the unresolved drift is still only ESI owner versus EDX compare coloring
// and its dependent loop-tail branch displacements.

// tu-statobj-C4250 2026-08-12: retained the complete static/master surface and
// stat_obj.cpp header context. The layout/context ABI probe was codegen-neutral;
// the readable typed source still differs only in the owner/compare tail basin.
// 2026-08-13 sa-e39fccc4-r1-tail2 reassessment: direct owner rereads were a
// 219B/37 codegen duplicate. Unsigned or byte compare-index types widened the
// body (227B-238B); dead parameter-home update/order variants widened it to
// 241B-247B. Restored the clean typed source; no new tail lead was found.
// 2026-08-16 sa-967e1011-r1 fresh pass (11 meaningful probes): direct signed
// casts at both predicates, player and compare register hints, function-scope
// compare declaration, cached owner id, signed-byte and unsigned-owner-id
// types, split loop comparisons, split index initialization, and related
// declaration forms either widened the body or reproduced the 219B/37 basin.
// The split-comparison form briefly selected ESI for the owner and EDX for the
// tail compare, but lost the original EBX byte home and prologue. Restored the
// readable typed source. Remaining drift is the ESI-owner versus EDX-compare
// loop-tail register map and its dependent branch displacements.
// 2026-08-17 sa-27522190-r1 reassessment: direct byte comparisons widened the
// body; removing the object-id alias, direct owner rereads, split compare
// initialization, and byte-cast tail tests either duplicated 219B/37 or lost
// the original EBX byte home. Eight standard-header combinations also formed
// one duplicate 219B/37 basin. Restored the clean typed source; no natural
// source form moved the owner/compare register-map hunk.
// 2026-08-17 sa-222d08b4-r1 revisit: the Ghidra-supported unsigned compare,
// parameter-home index, loop-local compare, declaration-order, update-order,
// const-owner, and split-initialization forms either widened the body or
// reproduced the 219B/37 basin. The clean typed source remains authoritative.
// 2026-08-17 deep stat_obj/scenario context pass: replaced the anonymous local
// vtable pads with the donor-backed RGE_Static_Object prefix, the minimal
// stat_obj RGE_Player destructor/field surface, the one-slot polymorphic
// RGE_Game_World surface, and the real RGE_Object_List load header. These
// canonical context changes were codegen-neutral and retained the 219B/37
// basin. A full named player prefix and full world virtual ordering were also
// neutral. An owner reference or const pointer widened to 147 bytes. The
// explicit parameter-home index update, both alone and with a const saved id,
// widened to 227/190 bytes. Split owner/world initialization and const saved
// object-id forms were neutral. No policy-valid owner/index lifetime form moved
// the ESI-owner versus EDX-compare tail basin; the canonical context is kept.
// 2026-08-17 PDB-local audit: DIA names only obj_id and one player_id local;
// player_id has one-byte type metadata at virtual-frame offset +8. This supports
// the byte index and treats Ghidra's ushort uVar4 as a promotion temporary.
// Natural one-byte player_id reconstructions widened to 227 bytes or changed
// result allocation. The clean two-local form remains the only 219B/37 basin.

class RGE_Static_Object;
class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Object_Node;

class RGE_Object_List {
public:
    virtual void load(unsigned char flag, int file, RGE_Game_World* world);
    void* list;
    short number_of_objects;
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type; // +0x04
    unsigned char gap_05[3];
    char* name; // +0x08
    short string_id; // +0x0C
    short string_id2; // +0x0E
    short id; // +0x10
    short copy_id; // +0x12
    short object_group; // +0x14
    unsigned char gap_16[2];
    void* sprite; // +0x18
    void* death_sprite; // +0x1C
    void* undead_sprite; // +0x20
    unsigned char undead_flag; // +0x24
    unsigned char gap_25;
    short hp; // +0x26
    float los; // +0x28
    unsigned char obj_max; // +0x2C
    unsigned char gap_2D[3];
    float radius_x; // +0x30
    float radius_y; // +0x34
    float radius_z; // +0x38
    void* selected_sound; // +0x3C
    void* created_sound; // +0x40
    void* death_sound; // +0x44
    short death_spawn_obj_id; // +0x48
    unsigned char sort_number; // +0x4A
    unsigned char can_be_built_on; // +0x4B
    short button_pict; // +0x4C
    unsigned char hide_in_scenario_editor; // +0x4E
    unsigned char gap_4F;
    short portrait_pict; // +0x50
    unsigned char available; // +0x52
    unsigned char gap_53;
    short tile_req1; // +0x54
    short tile_req2; // +0x56
    short center_tile_req1; // +0x58
    short center_tile_req2; // +0x5A
    float construction_radius_x; // +0x5C
    float construction_radius_y; // +0x60
    unsigned char elevation_flag; // +0x64
    unsigned char fog_flag; // +0x65
    short terrain; // +0x66
    unsigned char movement_type; // +0x68
    unsigned char gap_69;
    short attribute_type_held[3]; // +0x6A
    float attribute_amount_held[3]; // +0x70
    short attribute_max_amount; // +0x7C
    unsigned char gap_7E[2];
    float attribute_rot; // +0x80
    float multiple_attribute_mod; // +0x84
    unsigned char attribute_flag[3]; // +0x88
    unsigned char area_effect_object_level; // +0x8B
    unsigned char combat_level; // +0x8C
    unsigned char select_level; // +0x8D
    unsigned char map_draw_level; // +0x8E
    unsigned char unit_level; // +0x8F
    unsigned char map_color; // +0x90
    unsigned char attack_reaction; // +0x91
    unsigned char convert_terrain_flag; // +0x92
    unsigned char damage_sprite_num; // +0x93
    void* damage_sprites; // +0x94
    long help_string_id; // +0x98
    long help_page_id; // +0x9C
    long hotkey_id; // +0xA0
    unsigned char recyclable; // +0xA4
    unsigned char track_as_resource; // +0xA5
    unsigned char create_doppleganger_on_death; // +0xA6
    unsigned char resource_group; // +0xA7
    unsigned char draw_flag; // +0xA8
    unsigned char draw_color; // +0xA9
    unsigned char gap_AA[2];
    float outline_radius_x; // +0xAC
    float outline_radius_y; // +0xB0
    float outline_radius_z; // +0xB4
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    char gap_04[0x38];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x08];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player* player);
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long angle);
    virtual unsigned char can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual int heal(int amount, int max_amount);
    virtual unsigned char heal(float amount);
    virtual int canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float angle);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object* object);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char value);

    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
    void* sprite; // +0x10
    void* old_sprite; // +0x14
    void* sprite_list; // +0x18
    void* tile; // +0x1C
    RGE_Static_Object* inside_obj; // +0x20
    void* objects; // +0x24
    short screen_x_offset; // +0x28
    short screen_y_offset; // +0x2A
    short shadow_x_offset; // +0x2C
    short shadow_y_offset; // +0x2E
    float hp; // +0x30
    unsigned char curr_damage_percent; // +0x34
    unsigned char facet; // +0x35
    unsigned char selected; // +0x36
    unsigned char selected_group; // +0x37
    float world_x; // +0x38
    float world_y; // +0x3C
    float world_z; // +0x40
    float attribute_amount_held; // +0x44
    unsigned char object_state; // +0x48
    unsigned char sleep_flag; // +0x49
    unsigned char dopple_flag; // +0x4A
    unsigned char goto_sleep_flag; // +0x4B
    short attribute_type_held; // +0x4C
    unsigned char type; // +0x4E
    unsigned char worker_num; // +0x4F
    void* player_object_node; // +0x50
    unsigned char pathing_group_members[0x10]; // +0x54
    unsigned char group_members[0x10]; // +0x64
    void* unit_ai_value; // +0x74
    int group_commander_value; // +0x78
    int zone_map_index; // +0x7C
    float group_range_value; // +0x80
    unsigned char in_obstruction_map_value; // +0x84
    unsigned char last_in_obstruction_map_value; // +0x85
    unsigned char under_attack_value; // +0x86
    unsigned char gap_87;

    RGE_Static_Object* get_object_pointer(long id);
};

RGE_Static_Object* RGE_Static_Object::get_object_pointer(long id)
{
    RGE_Static_Object* object = 0;

    if (id >= 0) {
        object = this->owner->objects->find_by_id(id);
        if (object == 0) {
            object = this->owner->sleeping_objects->find_by_id(id);
            if (object == 0) {
                object = this->owner->doppleganger_objects->find_by_id(id);
                if (object == 0) {
                    long object_id = id;
                    RGE_Player* player = this->owner;
                    unsigned char player_index = 0;
                    RGE_Game_World* world = player->world;
                    if (world->player_num > 0) {
                        short compare_index = 0;
                        do {
                            if (compare_index != player->id) {
                                object = world->players[player_index]->objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->sleeping_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->doppleganger_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                            }
                            player = this->owner;
                            ++player_index;
                            compare_index = player_index;
                            world = player->world;
                        } while (compare_index < world->player_num);
                    }
                }
            }
        }
    }

    return object;
}
