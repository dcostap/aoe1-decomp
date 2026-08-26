#include <stdlib.h>

// 00437EC0 RGE_Diamond_Map::draw_visible_object (diam_map.cpp:1021-1112)
// Attempt log (sa-d55a5d35-draw_visible_object, bounded 10-probe pass):
// - Reconstructed the typed object/master/player/map and doppleganger surfaces, coordinate
//   ftol results, visibility masks, and the vslot +0xEC draw_object call surface.
// - Corrected master fog/map field offsets; all bytes remain exact-size and the direct ftol
//   sequence is stable. The natural candidate remains broad (340 differing bytes) because
//   this/player callee-save coloring, shared visibility tails, global map-offset relocation,
//   and case-1/case-3 versus case-2 virtual-call topology are unresolved.
// - Explicit shared-label and common-tail switch experiments were diagnostic only and rolled
//   back; retain ordinary nested visibility and switch source in scratch for the next worker.
// - Fresh pass: testing an int draw-level local. The original zero-extends map_draw_level into
//   a callee-save register before its jump table, while the prior unsigned-char source lowered
//   the dispatch into a decrement chain and lost one draw_object call.
// - int level plus an explicit case 0 produced the closest clean dispatch basin (339 differing
//   bytes, 384 emitted bytes), but VC5 still folded case 2 into the case-3 draw_object site.
// - Switch-arm order, case-zero/default exit spelling, and an inline case-3 color assignment
//   did not change that basin. Int working-color locals and a common call tail added a frame or
//   widened the function, so those diagnostics were rolled back.
// - Final validated candidate keeps the ordinary typed switch and separate case-two return;
//   remaining structural gaps are this/player register coloring and the folded virtual call.
// - Current pass: a byte working color was codegen-identical; one full-width working color
//   restored four calls but widened the body by 31 bytes. A natural common tail added a frame
//   and still folded the case-two call; both diagnostics were rolled back.
// - Current pause: the int-level ordinary switch remains authoritative. The next lead must
//   explain the this/player register homes and the case-call topology without compiler tricks.
// Follow-up sa012838e7_draw_visible:
// - Restored the clean candidate before each probe. Byte-width level improved size by 13 bytes
//   but did not recover the missing case-2 virtual call. A named self receiver was codegen-neutral.
// - Replaced the switch with ordered if dispatch; it reduced size and still folded case 2.
// - Donor search confirms the target's case layout is a natural switch-family shape. Paused with
//   the clean int-level switch; unresolved gap is register-home allocation plus call topology.
// - Tested the recovered natural shared tail: case 2 calls and returns, while cases 1 and 3
//   assign mode and call once after the switch. VC5 added a frame, emitted 416 bytes, and still
//   folded the case-2 virtual call; restored the clean switch.
// - Follow-up orch-437EC0-a: rechecked the best self/goto basin and short-row baseline; neither
//   changed the missing call or the this/player register swap. Splitting case 2 from the switch,
//   short or branch-local full-width color temporaries, and hoisting map were nonproductive.
// - Final source restores the clean int-level ordinary switch. The remaining structural gap is
//   compiler folding of equivalent case-2/case-3 calls; no evidence-backed natural variant remains.
// Follow-up sa-11cad2ac:
// - An absolute unified_map_offsets probe improved relocation masking only.
//   Restore the named global declaration for the living source.
// - A positive nested visibility guard reached exact 397-byte size and 336 differing bytes;
//   a combined short-circuit guard had better shape but worse edit distance, so it was rolled back.
// - Complete TPanel and RGE_Diamond_Map field surfaces, declaration scope, short row spelling,
//   and distinct case argument spellings did not change emitted code. The two call sites still fold.
// - Current natural source keeps the positive nested visibility guard, named map table, short
//   row, ordinary int switch, and separate case-two return. No exact result; pause for new evidence.

// Follow-up sa-52e29a9a:
// - Rechecked the target dossier, local ABI evidence, same-TU donors, and bounded target history.
// - Corrected the reviewed master layout: unit_level is +0x8F, so map_color is +0x90. The old
//   source read +0x8F. This changes one emitted displacement but not the 336-byte mismatch.
// - Positive map visibility polarity, semantic coordinate-name variants, the 256-row map symbol,
//   repeated direct mask expressions, and proven pointer vptr surfaces were codegen-duplicate.
// - Moving level-3 color assignment before the switch reduced the diff by two bytes but shortened
//   the body by 13 bytes and lowered shape; restore the 397-byte natural switch source.
// - The clean natural source retains typed ownership, the named map symbol, and ordinary switch flow.
// Follow-up sa-83abdfae:
// - The period-supported stdlib context improved shape to 67.41% and edit cost to 274,
//   but the result stayed 336 bytes different with one missing draw_object call.
// - Exact donor TPanel signatures worsened the result to 337 bytes and 65.19% shape;
//   restore the local generic slot surface. The reviewed full object virtual surface was neutral.
// - Direct case-3 color1, explicit casts, branch-local color copies, player alias removal,
//   declaration-order changes, and unsigned level widths did not recover the separate call.
// - Final validation remains 397 bytes, 336 differing bytes, 3/4 calls, and MISMATCH.
//   The unresolved gap is the original case-2 call topology and this/player register homes.
// Follow-up sa-326d096d:
// - Removing the unused world member, direct map-member reloads, an object alias, joined
//   coordinate initializers, and level-before-player declaration order were codegen-duplicate.
//   Restore the pinned natural body after each test.
// - The target listing marks this method protected. Retain protected access so the rebuilt
//   decorated symbol uses MAE, matching the target's Ghidra symbol; body bytes are unchanged.
// - A register hint for the local player is rejected by VC5 (C2071). No compiler steering remains.
// - Current claim: using color2 in level 2 reached exact size and 335 differing
//   bytes but still folded one mode-2 call. Lifting that call before the switch
//   worsened the result to 341 bytes. The original color1 switch source remains.

extern unsigned long* unified_map_offsets[256];

class RGE_Visible_Map;
class RGE_Tile;
class RGE_Color_Table;

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    char gap_04[0x61];
    unsigned char fog_flag;
    char gap_66[0x28];
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x34];
    RGE_Visible_Map* visible;
    char gap_3C[0x0E];
    short id;
    char gap_4C[0x60];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();

    char gap_04[0x8DB4];
    unsigned char map_visible_flag;
    unsigned char fog_flag;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float); virtual void new_sprite();
    virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*); virtual void modify(); virtual void modify_delta();
    virtual void modify_percent(); virtual void transform(); virtual void copy_obj();
    virtual void set_object_state(unsigned char); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj(); virtual void die_die_die();
    virtual void damage(); virtual float calculateDamage(); virtual void rotate(long);
    virtual unsigned char can_attack(); virtual void set_attribute(); virtual void set_attribute_amount();
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(); virtual void do_command(); virtual void move_to(); virtual void work();
    virtual void stop(); virtual void set_attack(); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(); virtual void set_being_worked_on();
    virtual void release_being_worked_on(); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(); virtual void exit_obj();
    virtual int explore_terrain(); virtual void unexplore_terrain(); virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*); virtual unsigned char underAttack();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    char gap_28[0x10];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    char gap_50[0x38];
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char gap_AA[2];
    int doppledObjectID;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

class TDrawArea;
class RGE_Game_World;

#ifndef DIAM_MAP_CONTEXT_H
class TPanel {
public:
    virtual ~TPanel();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8();
    virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8();
    virtual void vDC();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0xB8];
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Diamond_Map : public TPanel {
public:
    virtual void draw_selected_area();
    virtual void draw_objects();

protected:
    virtual void draw_visible_object(RGE_Static_Object* object,
                                     unsigned char color1,
                                     unsigned char color2);

public:
    virtual void draw_object(short x, short y, unsigned char color,
                             short mode, RGE_Static_Object* object);
    virtual void draw_view_rect();

    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    char gap_100[0x60];
    unsigned long cur_player_bit;
};
#endif

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object* object,
                                          unsigned char color1,
                                          unsigned char color2)
{
    if (object->tile == 0)
        return;

    short col;
    short row;
    RGE_Player* player;
    col = (short)object->world_x;
    row = (short)object->world_y;
    player = this->player;
    unsigned char visibility;
    if (player->visible != 0) {
        RGE_Map* map = this->map;
        if (map->map_visible_flag != 0 && map->fog_flag == 0) {
            visibility = 0x0F;
        } else {
            visibility = 0;
            unsigned long mask = unified_map_offsets[(short)row][(short)col];
            if ((player->mutualExploredMask & mask) != 0)
                visibility = 0x80;
            if ((player->mutualVisibleMask & mask) != 0)
                visibility = 0x0F;
            if (map->map_visible_flag != 0 && visibility == 0)
                visibility = 0x80;
            if (map->fog_flag == 0 && visibility == 0x80)
                visibility = 0x0F;
        }
    } else {
        visibility = 0x0F;
    }

    if (visibility != 0x0F &&
        (visibility != 0x80 || object->master_obj->fog_flag == 0))
        return;

    int level;
    if (object->type == 0x19) {
        if (visibility == 0x0F)
            return;

        RGE_Doppleganger_Object* dopple =
            (RGE_Doppleganger_Object*)object;
        if (player->mutualAlly[object->owner->id] == 1 &&
            (this->cur_player_bit & dopple->CantSeeBits) == 0) {
            level = dopple->map_draw_level;
            color1 = dopple->map_color;
            color2 = color1;
        } else {
            level = 0;
            color1 = 0xFF;
            color2 = 0xFF;
        }
    } else {
        level = object->master_obj->map_draw_level;
        if (level == 3)
            color1 = object->master_obj->map_color;
    }

    switch (level) {
    case 0:
        return;
    case 2:
        this->draw_object(col, (short)row, color1, 2, object);
        return;
    case 1:
        this->draw_object(col, (short)row, color2, 1, object);
        break;
    case 3:
        color2 = color1;
        this->draw_object(col, row, color2, 2, object);
        break;
    default:
        return;
    }
}
