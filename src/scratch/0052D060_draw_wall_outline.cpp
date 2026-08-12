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
// - Fresh pass: matched the original individual short output homes instead of
//   the synthetic aggregate. The short local order improves the structural
//   diff, but VC5 still reserves a 0x20 frame instead of the original 0x1C.
// - Cast world time before the shift and reuse the time local for the shape
//   transform; this recovers the original SHR and shared EAX branch shape.
// - Tested separate int centers, dword alignment-tail aliasing, and a split
//   tail local. They worsened the basin and were rolled back. Removing the
//   unused x1/y2 names and player alias emitted no change.
// - Fresh pass ends at 176 strict bytes, exact five-call multiset, 0x20/0x1C
//   frame, and 73.05% shape. Remaining gap starts at the frame/prologue.
// - Resumed after host interruption and restored the pinned clean source. The
//   one-short alignment-tail variant was already a byte-identical duplicate;
//   no new natural source lead justifies retaining it.

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
    short x4;
    short y3;
    short x2;
    short y1;
    short scr_y;
    short local_12;
    short scr_x;
    short x3;
    short y4;
    short local_4[2];

    if (this->get_tile_screen_coords(
            (short)x, (short)y, &x3, &scr_x, 0) != 0) {
        master->alignment_box(
            this->world, (float)x + 0.5f, (float)y + 0.5f,
            x4, local_12, scr_y, y3, y4, y1, x2, local_4[0]);

        if (master->check_placement(
                this->player, (float)x + 0.5f, (float)y + 0.5f,
                0, 1, master->elevation_flag, 0, 1, 1, 1) == 0) {
            fog_next_shape = 5;
        } else {
            unsigned int time = ((unsigned int)this->world->world_time >> 7) & 7;
            if (time < 4)
                time += 0x24;
            else
                time = 0x2C - time;
            fog_next_shape = (time << 4) | 9;
        }

        if (master->sprite != 0) {
            x3 = (short)((int)local_4[0] +
                ((int)x4 - (int)x3) / 2 + x3);
            scr_x = (short)((int)scr_x +
                ((int)y3 - (int)local_4[0]) / 2 + local_4[0]);
            SDI_Draw_Line = (int)scr_x;
            master->draw(
                this->draw_area,
                x3, scr_x,
                rge_base_game->get_player()->color_table,
                mode + 1, 0, 0, 0);
        }
    }

    fog_next_shape = 0;
    return 1;
}
