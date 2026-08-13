// VA: 0052CAF0 draw_multi_object_outline (1385B)
// PDB: tvw_main.cpp, lines 39-210
//
// Baseline reconstruction from the original call order and the matching
// tvw_main.cpp donors.  The outline has four diagonal paths and two explicit
// edge paths for each non-diagonal orientation.
//
// Attempt log:
// - Baseline: typed player/master/view ownership, direct mouse and selection
//   calls, and explicit diagonal and edge outline paths.  All 28 calls align;
//   the remaining gap is structural, with a 0x38 frame versus 0x48 original.
// - Layout lead: named the binary-backed calculation and fixed-edge locals
//   and changed grid temporaries to int.  It improved size and frame, but
//   reduced code shape.  Restored the baseline source.
// - Left in scratch: call order is exact, but branch topology, frame locals,
//   and the global relocation remain unresolved.

struct tagPOINT {
    long x;
    long y;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void SetClipRect(tagRECT* rect);
};

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class TRIBE_Master_Building_Object;

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
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
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

    void get_mouse_pos(tagPOINT& point);
};

extern RGE_Base_Game* rge_base_game;
extern "C" long __cdecl _ftol(void);

class TPanel {
public:
    virtual int dummy00();
    virtual int dummy04();
    virtual int dummy08();
    virtual int dummy0c();
    virtual int dummy10();
    virtual int dummy14();
    virtual int dummy18();
    virtual int dummy1c();
    virtual int dummy20();
    virtual int dummy24();
    virtual int dummy28();
    virtual int dummy2c();
    virtual int dummy30();
    virtual int dummy34();
    virtual int dummy38();
    virtual int dummy3c();
    virtual int dummy40();
    virtual int dummy44();
    virtual int dummy48();
    virtual int dummy4c();
    virtual int dummy50();
    virtual int dummy54();
    virtual int dummy58();
    virtual int dummy5c();
    virtual int dummy60();
    virtual int dummy64();
    virtual int dummy68();
    virtual int dummy6c();
    virtual int dummy70();
    virtual int dummy74();
    virtual int dummy78();
    virtual int dummy7c();
    virtual int dummy80();
    virtual int dummy84();
    virtual int dummy88();
    virtual int dummy8c();
    virtual int dummy90();
    virtual int dummy94();
    virtual int dummy98();
    virtual int dummy9c();
    virtual int dummya0();
    virtual int dummya4();
    virtual int dummya8();
    virtual int dummyac();
    virtual int dummyb0();
    virtual int dummyb4();
    virtual int dummyb8();
    virtual int is_inside(long x, long y);

    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_30[0x5C];
    long left;
    long top;
    long right;
    long bottom;
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    void* map;
    char gap_108[0x6C];

    int get_selection_area(
        long* col1, long* row1, long* col2, long* row2, int normalize);
};

class RGE_Main_View : public RGE_View {
public:
    unsigned char pick1(
        unsigned char command, unsigned char mode, long x, long y,
        RGE_Pick_Info* info, RGE_Static_Object* exclude, int flags);
    void fixup_pick_info(RGE_Pick_Info* info);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    int draw_wall_outline(
        long col, long row, TRIBE_Master_Building_Object* master,
        long endpoint);
    virtual void draw_multi_object_outline();
};

void TRIBE_Main_View::draw_multi_object_outline() {
    short master_id;
    TRIBE_Master_Building_Object* master;
    long start_col;
    long start_row;
    long end_col;
    long end_row;
    long col;
    long row;
    long col_min;
    long col_max;
    long row_min;
    long row_max;
    long endpoint;
    int row_distance;
    int col_distance;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    master_id = rge_base_game->master_obj_id;
    if (master_id == -1)
        return;

    master = (TRIBE_Master_Building_Object*)
        this->player->master_objects[(int)master_id];
    if (master == 0)
        return;

    this->render_area->SetClipRect(&this->clip_rect);

    if (this->get_selection_area(
            &start_col, &start_row, &end_col, &end_row, 0) == 0) {
        rge_base_game->get_mouse_pos(point);
        if (this->is_inside(point.x, point.y) == 0)
            return;

        if (this->pick1(
                0x28, 0, point.x - this->left, point.y - this->top,
                &pick_info, 0, 1) != 0x33)
            return;

        this->fixup_pick_info(&pick_info);
        start_col = (int)pick_info.x;
        end_col = start_col;
        start_row = (int)pick_info.y;
        end_row = start_row;
    }

    col_distance = end_col - start_col;
    if (col_distance < 0)
        col_distance = -col_distance;
    row_distance = end_row - start_row;
    if (row_distance < 0)
        row_distance = -row_distance;

    if (col_distance == row_distance) {
        if (end_col < start_col) {
            if (end_row < start_row) {
                col = end_col;
                row = end_row;
                while (col <= start_col) {
                    this->draw_wall_outline(col, row, master, 2);
                    ++col;
                    ++row;
                }
                this->render_area->SetClipRect(0);
                return;
            }

            col = start_col;
            row = start_row;
            while (col >= end_col) {
                this->draw_wall_outline(col, row, master, 2);
                --col;
                ++row;
            }
            this->render_area->SetClipRect(0);
            return;
        }

        if (end_row < start_row) {
            col = start_col;
            row = start_row;
            while (col <= end_col) {
                this->draw_wall_outline(col, row, master, 2);
                ++col;
                --row;
            }
            this->render_area->SetClipRect(0);
            return;
        }

        col = start_col;
        row = start_row;
        while (col <= end_col) {
            this->draw_wall_outline(col, row, master, 2);
            ++col;
            ++row;
        }
        this->render_area->SetClipRect(0);
        return;
    }

    if (col_distance > row_distance) {
        col_min = start_col;
        col_max = end_col;
        if (col_max < col_min) {
            col_min = end_col;
            col_max = start_col;
        }

        if (start_row < end_row) {
            for (col = col_min; col <= col_max; ++col) {
                endpoint = (col == start_col || col == end_col) ? 2 : 0;
                this->draw_wall_outline(col, start_row, master, endpoint);
            }
            for (row = start_row + 1; row <= end_row; ++row) {
                endpoint = (row == start_row || row == end_row) ? 2 : 1;
                this->draw_wall_outline(end_col, row, master, endpoint);
            }
            this->render_area->SetClipRect(0);
            return;
        }

        for (col = col_min; col <= col_max; ++col) {
            endpoint = (col == start_col || col == end_col) ? 2 : 0;
            this->draw_wall_outline(col, start_row, master, endpoint);
        }
        for (row = end_row; row < start_row; ++row) {
            endpoint = (row == start_row || row == end_row) ? 2 : 1;
            this->draw_wall_outline(end_col, row, master, endpoint);
        }
        this->render_area->SetClipRect(0);
        return;
    }

    row_min = start_row;
    row_max = end_row;
    if (row_max < row_min) {
        row_min = end_row;
        row_max = start_row;
    }

    if (start_col < end_col) {
        for (row = row_min; row <= row_max; ++row) {
            endpoint = (row == start_row || row == end_row) ? 2 : 0;
            this->draw_wall_outline(start_col, row, master, endpoint);
        }
        for (col = start_col + 1; col <= end_col; ++col) {
            endpoint = (col == start_col || col == end_col) ? 2 : 1;
            this->draw_wall_outline(col, end_row, master, endpoint);
        }
        this->render_area->SetClipRect(0);
        return;
    }

    for (row = row_min; row <= row_max; ++row) {
        endpoint = (row == start_row || row == end_row) ? 2 : 0;
        this->draw_wall_outline(start_col, row, master, endpoint);
    }
    for (col = end_col; col < start_col; ++col) {
        endpoint = (col == start_col || col == end_col) ? 2 : 1;
        this->draw_wall_outline(col, end_row, master, endpoint);
    }
    this->render_area->SetClipRect(0);
}
