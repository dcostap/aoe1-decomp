// VA: 00535610 RGE_View::draw_object_outline
// Source: view.cpp lines 2062-2207
// Attempt log:
// 1: broad natural reconstruction from packet: selected object, screen bounds, hit-test, bbox/project, draw outline and reset globals; after compile fixes object was too small (640 vs 665).
// 2: tried /Ob0 flag probe; no size change, flag removed.
// 3: tried /O1 /Oy flag probe; object shrank to 556 and failed configured size, flag removed.
// 4: reviewed original stack locals: eight short bbox/projection locals plus frame byte and coords; current source uses approximate uninitialized locals and wrong project signature.
// 5: reviewed original early screen bounds and hit-test call; current source matches behavior loosely but not exact argument/local shape.
// 6: original calls object vtable +24/+20/+34 and helper 00454690; current source fakes project/draw calls and misses exact helper surface.
// 7: original computes outline color from camera flags and selected result; modeled but scheduling/registers are likely wrong.
// 8: original special draw path depends on game mode/submode and view+174; modeled approximately.
// 9: final state remains too small (640 vs 665); no byte diff available.
// 10: left in scratch: needs real RGE_View/RGE_Static_Object draw/projection type surfaces and exact local short topology before matching.
// 11: canonical structural reset: restored the period RGE_Base_Game/RGE_Player/master-object ABI, RGE_View/TPanel ownership, virtual alignment/check_placement/draw slots, and typed pick/alignment_box calls. The old fake getMap/project/draw wrappers were removed.
// 12: direct absolute global surfaces restored the original fixed-address relocations and 0x3C frame; typed call order/target multiset became exact (12/12), with the remaining gap localized after the alignment call.
// 13: removing the named draw_flag temporary let VC5 retain the master vtable in EBX as in the oracle; widening the placement result to short recovered the oracle's xor-cx/mov-cl/test-cx sequence and reduced the strict gap to 225 bytes.
// 14: donor-shaped output reconstruction uses get_tile screen coordinates plus alignment_box x4/y2/scr_x/y3/y4/y1/x2/tail and the proven y4/tail midpoint formulas. Final source is size/frame exact with 12/12 calls and 54.42% exact-block coverage; remaining drift starts at the screen-coordinate output LEAs and late local-home/register scheduling. Duplicate final x3/scr_y spelling was rolled forward as the same canonical basin.

struct tagPOINT {
    long x;
    long y;
};

struct RGE_Game_World {
    void* vtable_ptr;
    long world_time;
};

struct RGE_Color_Table;
struct TDrawArea;
struct RGE_Sprite;
struct RGE_Sound;
struct RGE_Static_Object;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    void* tile;
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x1E];
    short master_object_num;
    struct RGE_Master_Static_Object** master_objects;
    char gap_28[0xE0];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    void* vtable_ptr;
    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x238];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;

    RGE_Player* get_player();
    void get_mouse_pos(tagPOINT& point);
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define fog_next_shape (*(int*)0x0086BBF0)
#define SDI_Draw_Line (*(int*)0x0086BBE0)

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float amount, unsigned char attribute);
    virtual void modify_delta(float amount, unsigned char attribute);
    virtual void modify_percent(float amount, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* player, float x, float y, int* placement,
        unsigned char check_terrain, unsigned char elevation,
        unsigned char check_objects, unsigned char check_units,
        unsigned char check_buildings, unsigned char check_fog);
    virtual unsigned char alignment(float* x, float* y,
                                    RGE_Game_World* world, unsigned char value);
    virtual long calc_base_damage_ability(void* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    char gap_04[0x14];
    RGE_Sprite* sprite;                    // +0x18
    char gap_1C[0x48];
    unsigned char elevation_flag;          // +0x64
    char gap_65[0x43];
    unsigned char draw_flag;               // +0xA8
    unsigned char draw_color;              // +0xA9

    unsigned char alignment_box(
        RGE_Game_World* world, float x, float y,
        short& x1, short& y1, short& x2, short& y2,
        short& x3, short& y3, short& x4, short& y4);
};

class TPanel {
public:
    void* vtable_ptr;
    char gap_04[0x1C];
    TDrawArea* render_area;                // +0x20
    char gap_24[0x68];
    long left;                              // +0x8C
    long top;                               // +0x90
    long right;                             // +0x94
    long bottom;                            // +0x98
    char gap_9C[0x58];
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;             // +0xF4
    int calc_draw_count;                    // +0xF8
    RGE_Game_World* world;                  // +0xFC
    RGE_Player* player;                     // +0x100
    void* map;                              // +0x104
    char gap_108[0x6C];
    RGE_Static_Object* movable_object;      // +0x174
    char gap_178[0x1E8];

    unsigned char pick(unsigned char mode, unsigned char parm,
                       long x, long y, RGE_Pick_Info* info,
                       RGE_Static_Object* object);
    int get_tile_screen_coords(short col, short row,
                               short* out_x, short* out_y, int adjust);
    void draw_object_outline();
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x25];
    unsigned char facet;                    // +0x35
    char gap_36[0x96];
};

void RGE_View::draw_object_outline() {
    short placement;
    short x1;
    short y2;
    short x4;
    short y3;
    short x2;
    short y1;
    short scr_x;
    unsigned char frame_color;
    short scr_y;
    short x3;
    short y4;
    short alignment_tail;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    short master_obj_id = rge_base_game->master_obj_id;
    if (master_obj_id == -1)
        return;

    RGE_Player* player = rge_base_game->get_player();
    RGE_Master_Static_Object* master = player->master_objects[(int)master_obj_id];
    if (master == 0)
        return;

    rge_base_game->get_mouse_pos(point);
    if (point.x < this->left || point.x > this->right ||
        point.y < this->top || point.y > this->bottom)
        return;

    unsigned short pick_result = (unsigned char)this->pick(
        0x28, 0, point.x - this->left, point.y - this->top,
        &pick_info, 0);
    if (pick_result != 0x33)
        return;

    master->alignment(&pick_info.x, &pick_info.y, this->world, 0);
    if (this->get_tile_screen_coords(
            (short)pick_info.x, (short)pick_info.y, &x3, &scr_y, 1) != 0) {
        master->alignment_box(this->world, pick_info.x, pick_info.y,
                              x4, y2, scr_x, y3, y4, y1, x2,
                              alignment_tail);

        placement = (unsigned char)master->check_placement(
            rge_base_game->get_player(), pick_info.x, pick_info.y,
            0, 1, master->elevation_flag, 0, 1, 1, 1);
        fog_next_shape = 1;
        if (placement == 0) {
            fog_next_shape = 5;
        } else {
            int shape = (this->world->world_time >> 7) & 7;
            if (shape < 4)
                shape += 0x24;
            else
                shape = 0x2C - shape;
            fog_next_shape = (shape << 4) | 9;
        }

        if (master->sprite != 0) {
            x3 = (short)((int)y4 + ((int)x4 - (int)x3) / 2 + x3);
            scr_y = (short)((int)scr_y + ((int)y3 - (int)alignment_tail) / 2 +
                         alignment_tail);
            SDI_Draw_Line = (int)scr_y;

            if (placement == 0)
                frame_color = master->draw_color;
            else
                frame_color = 0x97;

            if (rge_base_game->game_mode == 8 &&
                rge_base_game->sub_game_mode == 1 &&
                this->movable_object != 0) {
                RGE_Static_Object* movable = this->movable_object;
                RGE_Color_Table* colors = movable->owner->color_table;
                master->draw(this->render_area, x3, scr_y, colors,
                             movable->facet, 0, master->draw_flag & 1,
                             frame_color);
            } else {
                RGE_Color_Table* colors = rge_base_game->get_player()->color_table;
                master->draw(this->render_area, x3, scr_y, colors,
                             0, 0, master->draw_flag & 1, frame_color);
            }
        }
    }

    fog_next_shape = 0;
}
