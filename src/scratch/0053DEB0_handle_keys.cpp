// VA 0053DEB0 RGE_Main_View::handle_keys
// vw_main.cpp:258-423
// Attempt log:
// 1: Natural source from packet/decompiler, local type surfaces and Win32 imports.

typedef unsigned char uchar;
typedef void* HWND;
extern "C" HWND __stdcall GetForegroundWindow(void);
extern "C" int __stdcall GetKeyboardState(uchar* keys);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class RGE_Base_Game_0053DEB0 {
public:
    char gap_00[0x0C];
    void* prog_info;
    char gap_10[0x1A0];
    int prog_mode;
    int game_mode;
    int get_paused();
};
extern RGE_Base_Game_0053DEB0* rge_base_game;

struct ProgInfo_0053DEB0 {
    char gap_00[0x8D0];
    int key_scroll_time_divisor;
    float key_scroll_max_dist;
    float key_scroll_object_move;
};

class RGE_Player_0053DEB0 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void repaint(int);
    char gap_04[0x110];
    float view_x;
    float view_y;
    char gap_11C[0x14];
    RGE_Player_0053DEB0* selected_obj;
    void set_view_loc(float x, float y);
};

class Obj_0053DEB0 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30();
    virtual float move_to(float x, float y, int zero);
    char gap_04[0x34];
    float x;
    float y;
};

struct RGE_WindowHost_0053DEB0 { char gap[4]; HWND wnd; };

class RGE_Main_View_0053DEB0 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void repaint(int);
    char gap_04[0x1C];
    RGE_WindowHost_0053DEB0* host;
    char gap_24[0x54];
    int active;
    char gap_7C[0x84];
    RGE_Player_0053DEB0* player;
    char gap_104[0x25C];
    RGE_Main_View_0053DEB0* map_view;
    char gap_364[0x10];
    unsigned long last_key_scroll_time;
    int key_scrolling;

    int handle_keys();
};

int RGE_Main_View_0053DEB0::handle_keys()
{
    uchar keys[256];
    short horz_scroll;
    short vert_scroll;
    float scroll_dist2;
    int changed;
    ProgInfo_0053DEB0* info;

    if (rge_base_game->get_paused() != 0)
        goto fail;

    {
        int mode = rge_base_game->prog_mode;
        if (mode != 4 && mode != 6 && mode != 7 && mode != 5)
            goto fail;
    }

    if (GetForegroundWindow() != this->host->wnd)
        goto fail;

    changed = 0;
    if (this->active == 0)
        goto fail;

    GetKeyboardState(keys + 4);
    horz_scroll = 0;
    vert_scroll = 0;

    info = (ProgInfo_0053DEB0*)rge_base_game->prog_info;

    if (rge_base_game->game_mode == 0x12 && this->player != 0 && this->player->selected_obj != 0) {
        Obj_0053DEB0* obj = (Obj_0053DEB0*)this->player->selected_obj;
        if (keys[0x26] > 1) {
            obj->move_to(obj->x + info->key_scroll_object_move, obj->y - info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x28] > 1) {
            Obj_0053DEB0* obj2 = (Obj_0053DEB0*)this->player->selected_obj;
            obj2->move_to(obj->x - info->key_scroll_object_move, obj->y + info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x25] > 1) {
            Obj_0053DEB0* obj2 = (Obj_0053DEB0*)this->player->selected_obj;
            obj2->move_to(obj->x - info->key_scroll_object_move, obj->y - info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x27] > 1) {
            Obj_0053DEB0* obj2 = (Obj_0053DEB0*)this->player->selected_obj;
            obj2->move_to(obj->x + info->key_scroll_object_move, obj->y + info->key_scroll_object_move, 0);
            changed = 1;
        }
    } else if (this->player != 0) {
        if (keys[0x25] > 1)
            horz_scroll = -1;
        else if (keys[0x27] > 1)
            horz_scroll = 1;

        if (keys[0x26] > 1)
            vert_scroll = -1;
        else if (keys[0x28] > 1)
            vert_scroll = 1;

        if (horz_scroll != 0 || vert_scroll != 0) {
            unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x153);
            float scroll_dist;
            if (this->key_scrolling == 0) {
                scroll_dist = 1.0f;
                this->key_scrolling = 1;
            } else {
                scroll_dist = (float)(now - this->last_key_scroll_time) / info->key_scroll_time_divisor;
                int whole = (int)scroll_dist;
                if (scroll_dist - whole >= 0.5f)
                    scroll_dist = whole + 0.5f;
                else
                    scroll_dist = (float)whole;
            }
            if (scroll_dist > info->key_scroll_max_dist)
                scroll_dist = info->key_scroll_max_dist;
            if (scroll_dist > 0.0f) {
                scroll_dist2 = scroll_dist + scroll_dist;
                if (horz_scroll == -1) {
                    this->player->set_view_loc(this->player->view_x - scroll_dist, this->player->view_y - scroll_dist);
                } else if (horz_scroll == 1) {
                    this->player->set_view_loc(this->player->view_x + scroll_dist, this->player->view_y + scroll_dist);
                }
                if (vert_scroll == -1) {
                    this->player->set_view_loc(this->player->view_x + scroll_dist2, this->player->view_y - scroll_dist2);
                } else if (vert_scroll == 1) {
                    this->player->set_view_loc(this->player->view_x - scroll_dist2, this->player->view_y + scroll_dist2);
                }
                this->last_key_scroll_time = now;
                changed = 1;
            }
        }
    }

    if (horz_scroll == 0 && vert_scroll == 0)
        this->key_scrolling = 0;
    if (changed) {
        this->repaint(1);
        if (this->map_view != 0)
            this->map_view->repaint(1);
    }
    return changed;

fail:
    this->key_scrolling = 0;
    return 0;
}
