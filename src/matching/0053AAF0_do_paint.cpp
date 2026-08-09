// VA: 0053AAF0 RGE_View::do_paint | view.cpp:6226-6301
// compiles at original size. Conversion/local pick_info offsets fixed by using f0/y; remaining mismatch is mode-dispatch/source-shape (original subtract chain keeps game in ECX and brush in DX before dispatch).
// 1: Baseline exact calls/frame/size; mode dispatch starts at +64 with game in EAX and mode in ECX.
// 2: Direct global game-mode/field expressions — 208-byte diff; rolled back.
// 3: Reordered cached mode/brush/game declarations; pending checker result.
// 4: Polymorphic RGE_Base_Game surface was a codegen duplicate of baseline.
// 5: Cache mode/brush values without a game pointer local; pending checker result.
// 6: Compute cliff result before map call — codegen duplicate; rolled back.
// 7: Duplicate the two natural cliff-call arms so VC5 can join the final call — exact 332B.
// STATUS: exact under default /O2 /Oy; the duplicated arms are retained because the
// original has one joined virtual call with branch-specific push 1/0 topology.

struct RGE_Static_Object;
struct RGE_Pick_Info { float f0; float y; float scr_x; char pad[8]; };

struct RGE_Map {
    virtual ~RGE_Map(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void paint_terrain(long old_col, long old_row, long col, long row, int brush, short terrain);
    virtual void v14();
    virtual void paint_elevation(long old_col, long old_row, long col, long row, int brush, short elevation);
    virtual void v1C();
    virtual void paint_cliff(long old_col, long old_row, long col, long row, int zero, int cliff);
};
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x3FE - 0x1BC];
    short terrain_id;
    short elevation_height;
    short brush_size;
};
extern RGE_Base_Game* rge_base_game;

struct RGE_View {
    virtual ~RGE_View(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void redraw(int flags);
    char gap_04[0x104 - 0x04];
    RGE_Map* map;
    char gap_108[0x2F4 - 0x108];
    long real_old_map_col;
    long real_old_map_row;

    unsigned char pick(unsigned char type, unsigned char p2, long x, long y, RGE_Pick_Info* info, RGE_Static_Object* obj);
    int do_paint(long param_1, long param_2, long param_3, long param_4, int param_5);
};

int RGE_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5)
{
    RGE_Pick_Info pick_info;
    long new_col;
    long new_row;
    int mode;
    short brush;

    if (this->pick(0x28, 0, param_3, param_4, &pick_info, 0) != 0x33) {
        return 0;
    }

    new_col = (long)pick_info.f0;
    new_row = (long)pick_info.y;
    this->pick(0x28, 0, param_1, param_2, &pick_info, 0);

    mode = rge_base_game->game_mode;
    brush = rge_base_game->brush_size;
    switch (mode) {
    case 9:
        if (param_5 != 0 && rge_base_game->terrain_id != -1) {
            this->map->paint_terrain(this->real_old_map_col, this->real_old_map_row, new_col, new_row, brush, rge_base_game->terrain_id);
        }
        break;
    case 10:
        if (param_5 != 0 && rge_base_game->elevation_height != -1) {
            this->map->paint_elevation(this->real_old_map_col, this->real_old_map_row, new_col, new_row, brush, rge_base_game->elevation_height);
        }
        break;
    case 0x13:
        if (rge_base_game->sub_game_mode == 1) {
            this->map->paint_cliff(this->real_old_map_col, this->real_old_map_row, new_col, new_row, 0, 1);
        } else {
            this->map->paint_cliff(this->real_old_map_col, this->real_old_map_row, new_col, new_row, 0, 0);
        }
        this->redraw(2);
        break;
    }

    this->real_old_map_row = new_row;
    this->real_old_map_col = new_col;
    return 1;
}
