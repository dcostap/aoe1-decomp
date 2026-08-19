// VA: 0048A320 key_down_action (509 bytes)
// PDB: rpnl_tbx.cpp lines 312-372
// Attempt log:
// - Replaced the placeholder with the binary-backed tool-box key switch.
//   The source owns the selection rectangle as four long locals, uses the
//   game world map for elevation edits, and keeps the shared redraw tail.
// - Baseline: exact 0x10 frame and 509-byte code size; natural switch is 474
//   positional bytes from the oracle.  Calls align 12/13; VC5 merges the two
//   set_elev call sites into one shared call block.
// - A named self pointer, per-case map locals, a swapped case order, a
//   reference receiver, full trailing tool-box fields, and virtual-marker
//   changes were codegen duplicates.
// - Nested positive guards with shared fail/success labels improved the
//   diagnostic diff to 320 bytes and three returns, but used non-natural goto
//   scaffolding and remained 50 bytes short. Restored the clean switch.
// - A shared map receiver assigned after each set_elev call worsened size,
//   call count, and CFG; restored the clean direct map calls.
// - A natural if/else dispatch with the binary-backed post-call map owner
//   shortened the body to 448 bytes and lost calls; restored the switch.
// - Tried an outer positive pause guard (get_paused() == 0) to match the
//   original jne-to-failure branch; diff improved 474 -> 431 and shape
//   72.58% -> 76.51%, but the frame shrank 0x10 -> 0xC and set_elev stayed
//   merged. Kept as the best natural branch reconstruction.
// - Tested a case-specific named map receiver only in the 0x21 arm, based on
//   Ghidra's case-specific map alias; emitted code was an exact duplicate.
// - Left in scratch: the remaining structural lead is the original source
//   shape that keeps two set_elev call sites while sharing the failure tail.
// - Tested the plain Ghidra-backed if/else dispatch without the prior map
//   temporary; it still merged set_elev (1/2 calls) and worsened shape to
//   56.97%. Restored the clean outer-positive switch.
// - Duplicated clean_elevation inside both elevation branches while keeping
//   the shared redraw tail; VC5 retained both set_elev sites and merged the
//   clean tail. Calls reached 13/13, but the body grew to 533 bytes.
// - Changed the object arm to a natural common-success path (`object != 0`)
//   and kept branch-local elevation cleanup. This reached exact size, calls,
//   return count, and CFG; remaining drift is 43 bytes and a 0xC/0x10 frame.
// - Left in scratch: source-backed call topology is solved; remaining blocker
//   is stack/local topology around the fifth selection local and frame home.
// - Moved the four typed selection locals to function scope. This restored the
//   0x10 frame and reduced the positional diff from 43 to 14 bytes.
// - Direct player ownership, typed local scope/order, object-first case order,
//   and a branch-local view alias did not change the 14-byte result.
// - Early-return pause and object forms, and an if/else dispatch, worsened the
//   emitted CFG or call layout. The remaining drift is ESI/EDI recoloring:
//   original self=ESI/object=EDI; rebuilt self=EDI/object=ESI.
// - Main review replaced generic virtual-slot declarations with real TPanel
//   inheritance and the canonical RGE_Static_Object method surface.
// ACCEPTED DRIFT: The 14 changed bytes exchange ESI and EDI for `this` and the
// selected object. One register-only move also shifts across the unchanged EDI
// save. Every memory operand, argument, result, flag, call, branch, stack save,
// restore, cleanup, and possible fault stays in the same order.

typedef unsigned char uchar;

class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Active_Sprite_List;
class RGE_Sprite;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int mode);
    char gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    int get_selection_area(long* col1, long* row1, long* col2, long* row2,
                           int normalize);
};

class RGE_Diamond_Map : public TPanel {
};

class RGE_Map {
public:
    void set_elev(short col0, short row0, short col1, short row1,
                  uchar elevation, short direction, uchar apply);
    void clean_elevation(long x1, long y1, long x2, long y2,
                         uchar elevation);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    char gap_1B8[0x23C];
    RGE_Game_World* world;

    int get_paused();
    RGE_Player* get_player();
};

class RGE_Sprite {
public:
    uchar get_lowest_draw_level();
};

class RGE_Active_Sprite_List {
public:
    uchar get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();

    char gap_04[0x0C];
    RGE_Sprite* sprite;
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;
};

class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    char gap_F4[4];
    RGE_View* view;
    RGE_Diamond_Map* map;

    virtual long key_down_action(long key, short ch, int a3, int a4, int a5);
};

extern RGE_Base_Game* rge_base_game;

long RGE_Panel_Tool_Box::key_down_action(long key, short ch, int a3, int a4,
                                         int a5)
{
    long local_4;
    long x1;
    long y1;
    long x2;

    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->prog_mode != 4 &&
            rge_base_game->prog_mode != 6 &&
            rge_base_game->prog_mode != 7)
            return 0;

    switch (key) {
    case 0x2E:
        if (rge_base_game->game_mode != 0x12)
            return 0;
        {
            RGE_Player* player = rge_base_game->get_player();
            RGE_Static_Object* object = player->selected_obj;
            if (object != 0) {
                uchar draw_level;
                if (object->sprite_list != 0) {
                    draw_level = object->sprite_list->get_lowest_draw_level();
                } else if (object->sprite != 0) {
                    draw_level = object->sprite->get_lowest_draw_level();
                } else {
                    draw_level = 0x14;
                }

                object->destroy_obj();
                if (draw_level == 0)
                    this->view->set_redraw(2);
            }
            return 1;
        }

    case 0x21:
        if (rge_base_game->game_mode != 3)
            return 0;

        this->view->get_selection_area(&local_4, &x1, &y1, &x2, 1);
        rge_base_game->world->map->set_elev(
            (short)local_4, (short)x1, (short)y1, (short)x2, 0, 1, 1);
        rge_base_game->world->map->clean_elevation(local_4, x1, y1, x2, 8);
        break;

    case 0x22:
        if (rge_base_game->game_mode != 3)
            return 0;

        this->view->get_selection_area(&local_4, &x1, &y1, &x2, 1);
        rge_base_game->world->map->set_elev(
            (short)local_4, (short)x1, (short)y1, (short)x2, 0, -1, 1);
        rge_base_game->world->map->clean_elevation(local_4, x1, y1, x2, 8);
        break;

    default:
        return 0;
    }

    this->view->set_redraw(2);
    if (this->map != 0)
        this->map->set_redraw(2);
        return 1;
    }

    return 0;
}
