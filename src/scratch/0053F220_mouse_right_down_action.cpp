// 0053F220 RGE_Main_View::mouse_right_down_action(long,long,int,int)
// vw_main.cpp:1082-1111
// Attempt 6: nested if structure to force shared epilogue

extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Base_Game {
public:
    // vtable slots 0-3
    virtual ~RGE_Base_Game() {}
    virtual int run() { return 0; }
    virtual long wnd_proc(void*, unsigned int, unsigned int, long) { return 0; }
    virtual void set_prog_mode(int) {}
    // vt[4] (0x10)
    virtual void set_game_mode(int a, int b) {}
    // remaining vtable slots
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v0A() {}
    virtual void v0B() {}
    virtual void v0C() {}
    virtual void v0D() {}
    virtual void v0E() {}

    int get_paused();

    char pad_0004[0x1AC];   // +0x04 to +0x1AF
    int prog_mode;           // +0x1B0
    int game_mode;           // +0x1B4
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    // vtable slots 0-7
    virtual ~TPanel() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    // vt[8] (0x20)
    virtual void set_redraw(int mode) {}

    int capture_mouse();
    char gap_00[0xF0];       // +0x04 to +0xF3
};

class RGE_View : public TPanel {
public:
    // virtual methods for slots 9-57
    virtual void v24() {}
    virtual void v28() {}
    virtual void v2C() {}
    virtual void v30() {}
    virtual void v34() {}
    virtual void v38() {}
    virtual void v3C() {}
    virtual void v40() {}
    virtual void v44() {}
    virtual void v48() {}
    virtual void v4C() {}
    virtual void v50() {}
    virtual void v54() {}
    virtual void v58() {}
    virtual void v5C() {}
    virtual void v60() {}
    virtual void v64() {}
    virtual void v68() {}
    virtual void v6C() {}
    virtual void v70() {}
    virtual void v74() {}
    virtual void v78() {}
    virtual void v7C() {}
    virtual void v80() {}
    virtual void v84() {}
    virtual void v88() {}
    virtual void v8C() {}
    virtual void v90() {}
    virtual void v94() {}
    // vt[38] (0x98)
    virtual long mouse_right_down_action(long a, long b, int c, int d);
    virtual void v9C() {}
    virtual void vA0() {}
    virtual void vA4() {}
    virtual void vA8() {}
    virtual void vAC() {}
    virtual void vB0() {}
    virtual void vB4() {}
    virtual void vB8() {}
    virtual void vBC() {}
    virtual void vC0() {}
    virtual void vC4() {}
    virtual void vC8() {}
    virtual void vCC() {}
    virtual void vD0() {}
    virtual void vD4() {}
    virtual void vD8() {}
    virtual void vDC() {}
    virtual void vE0() {}
    virtual void vE4() {}
    // vt[58] (0xE8)
    virtual int start_scroll_view(unsigned char a, long b, long c, int d, int e) { return 0; }

    char gap_F4[0x0C];      // +0xF4 to +0xFF
    class RGE_Player* player;  // +0x100
};

class RGE_Player {
public:
    void* vtable;            // +0x00
    char gap_04[0x12C];      // +0x04 to +0x12F
    class RGE_Static_Object* selected_obj; // +0x130

    void unselect_object();
};

class RGE_Main_View : public RGE_View {
public:
    virtual long mouse_right_down_action(long, long, int, int);
};
#endif

long RGE_Main_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4)
{
    if (!rge_base_game->get_paused()) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            color_log(0x4C, 0x24, 1);

            if (rge_base_game->game_mode != 0x13) {
                this->capture_mouse();
            } else {
                if (this->player->selected_obj) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                rge_base_game->set_game_mode(0x13, 1);
                this->start_scroll_view(9, param_1, param_2, param_3, param_4);
            }

            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}
