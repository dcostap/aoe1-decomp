// VA: 0052D060 draw_wall_outline (391B)
// tvw_main.cpp, lines 216-275
//
// Attempt log:
// - Reconstructed the tile-coordinate, alignment-box, placement-check, and
//   master draw path from the original call/field evidence; baseline pending.
// - Corrected alignment_box to the period short-reference ABI and modeled the
//   proven contiguous short output window as a named local aggregate.
// - Reused the x3/scr_x homes for the two computed draw centers and inlined the
//   natural draw argument expressions; best documented result is 198 strict
//   bytes with exact call count, but frame/CFG/source scheduling remain open.
// - Final bounded probes did not close the remaining view/master register and
//   stack-frame basin; left the readable aggregate reconstruction in scratch.

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Color_Table;
class TDrawArea;

class RGE_Game_World {
public:
    int gap_00;
    int world_time;
};

class RGE_Master_Combat_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char attribute);
    virtual void modify_delta(float amount, unsigned char attribute);
    virtual void modify_percent(float amount, unsigned char attribute);
    virtual void save(int file_handle);
    virtual RGE_Static_Object* make_new_obj(
        RGE_Player* player, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* player, float x, float y, int* placement,
        unsigned char check_terrain, unsigned char elevation,
        unsigned char check_objects, unsigned char check_units,
        unsigned char check_buildings, unsigned char check_fog);
    virtual unsigned char alignment(
        float* x, float* y, RGE_Game_World* world, unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(
        TDrawArea* area, short x, short y, RGE_Color_Table* colors,
        long clip_x, long clip_y, int value, unsigned char flags);

    char gap_04[0x0C];
    short id;
    char gap_12[0x06];
    RGE_Sprite* sprite;
    char gap_1C[0x48];
    unsigned char elevation_flag;
    char gap_65[0x43];
    unsigned char draw_flag;
    unsigned char draw_color;
    char gap_AA[0x0E];

    unsigned char alignment_box(
        RGE_Game_World* world, float x, float y,
        short& x1, short& y1, short& x2, short& y2,
        short& x3, short& y3, short& x4, short& y4);
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
};

struct Wall_Outline_Short_Values {
    short x4;
    short y3;
    short x2;
    short y1;
    short scr_y;
    short alignment_value_5;
    short scr_x;
    short gap_0E;
    short x3;
    short gap_12;
    short y4;
    short gap_16;
    short alignment_tail[2];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x104];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;
extern int fog_next_shape;
extern int SDI_Draw_Line;

class RGE_View {
public:
    virtual ~RGE_View();
    char gap_04[0x1C];
    TDrawArea* draw_area;
    char gap_24[0xD8];
    RGE_Game_World* world;
    RGE_Player* player;

    int get_tile_screen_coords(
        short col, short row, short* out_x, short* out_y, int adjust);
};

class RGE_Main_View : public RGE_View {
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    int draw_wall_outline(
        long x, long y, TRIBE_Master_Building_Object* master, long mode);
};

int TRIBE_Main_View::draw_wall_outline(
    long x, long y, TRIBE_Master_Building_Object* master, long mode) {
    Wall_Outline_Short_Values values;

    if (this->get_tile_screen_coords(
            (short)x, (short)y, &values.x3, &values.scr_x, 0) != 0) {
        master->alignment_box(
            this->world, (float)x + 0.5f, (float)y + 0.5f,
            values.x4, values.alignment_value_5, values.scr_y, values.y3,
            values.y4, values.y1, values.x2, values.alignment_tail[0]);

        RGE_Player* player = this->player;
        if (master->check_placement(
                player, (float)x + 0.5f, (float)y + 0.5f,
                0, 1, master->elevation_flag, 0, 1, 1, 1) == 0) {
            fog_next_shape = 5;
        } else {
            unsigned int time = (unsigned int)(this->world->world_time >> 7) & 7;
            int shape;
            if (time < 4)
                shape = (int)time + 0x24;
            else
                shape = 0x2C - (int)time;
            fog_next_shape = (shape << 4) | 9;
        }

        if (master->sprite != 0) {
            values.x3 = (short)((int)values.alignment_tail[0] +
                ((int)values.x4 - (int)values.x3) / 2 + values.x3);
            values.scr_x = (short)(
                (int)values.scr_x +
                ((int)values.y3 - (int)values.alignment_tail[0]) / 2 +
                values.alignment_tail[0]);
            SDI_Draw_Line = (int)values.scr_x;
            master->draw(
                this->draw_area,
                values.x3, values.scr_x,
                rge_base_game->get_player()->color_table,
                mode + 1, 0, 0, 0);
        }
    }

    fog_next_shape = 0;
    return 1;
}
