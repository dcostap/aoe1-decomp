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
    char gap_04[0xF0];
};

class RGE_View {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int mode);

    int get_selection_area(long* col1, long* row1, long* col2, long* row2,
                           int normalize);
};

class RGE_Diamond_Map {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int mode);
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
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();

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
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->prog_mode != 4 &&
            rge_base_game->prog_mode != 6 &&
            rge_base_game->prog_mode != 7)
            return 0;

        long local_4;
        long x1;
        long y1;
        long x2;

    switch (key) {
    case 0x21:
        if (rge_base_game->game_mode != 3)
            return 0;

        this->view->get_selection_area(&local_4, &x1, &y1, &x2, 1);
        rge_base_game->world->map->set_elev(
            (short)local_4, (short)x1, (short)y1, (short)x2, 0, 1, 1);
        break;

    case 0x22:
        if (rge_base_game->game_mode != 3)
            return 0;

        this->view->get_selection_area(&local_4, &x1, &y1, &x2, 1);
        rge_base_game->world->map->set_elev(
            (short)local_4, (short)x1, (short)y1, (short)x2, 0, -1, 1);
        break;

    case 0x2E:
        if (rge_base_game->game_mode != 0x12)
            return 0;
        {
            RGE_Player* player = rge_base_game->get_player();
            RGE_Static_Object* object = player->selected_obj;
            if (object == 0)
                return 1;

            uchar draw_level;
            if (object->sprite_list != 0) {
                draw_level = object->sprite_list->get_lowest_draw_level();
            } else if (object->sprite != 0) {
                draw_level = object->sprite->get_lowest_draw_level();
            } else {
                draw_level = 0x14;
            }

            object->vf68();
            if (draw_level != 0)
                return 1;
            this->view->set_redraw(2);
            return 1;
        }

    default:
        return 0;
    }

    rge_base_game->world->map->clean_elevation(local_4, x1, y1, x2, 8);
    this->view->set_redraw(2);
    if (this->map != 0)
        this->map->set_redraw(2);
        return 1;
    }

    return 0;
}
