// TRIBE_Panel_Inven::handle_idle
// Checks game mode, timer, and whether saved values changed.
// If changed, calls save_info and triggers redraw (vf20).

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl color_log(unsigned char a, unsigned char b, unsigned char c);

#ifndef TPNL_INV_SHARED_CONTEXT
class TPanel {
public:
    long handle_idle();
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
};

extern RGE_Base_Game* rge_base_game;

#ifndef TPNL_INV_SHARED_CONTEXT
extern int TRIBE_Panel_Inven_vftable;
#endif

class TRIBE_Player {
public:
    char gap_00[0x4C];
    short field_4C;
    char gap_4E[0x02];
    float* float_values;
};

class TRIBE_Panel_Inven {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);

    // TPanel fields: offsets 0x04 through 0xF3
    char gap_04[0xF0];

    // TRIBE_Panel_Inven fields starting at offset 0xF4
    void* pics;                 // +0F4h
    TRIBE_Player* player;       // +0F8h
    short save_attr_num;        // +0FCh
    short gap_FE;
    short* save_attr;           // +100h
    int idle_time;              // +104h
    int idle_interval;          // +108h
    void* font;                 // +10Ch
    int font_color;             // +110h
    int back_color;             // +114h

    void save_info();
    long handle_idle();
};
#else
#include "../../include/tpnl_inv_context.h"
#endif

long TRIBE_Panel_Inven::handle_idle() {
#ifdef TPNL_INV_SHARED_CONTEXT
    this->TPanel::handle_idle();
#else
    ((TPanel*)this)->handle_idle();
#endif

    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xAD);
        if (now - this->idle_time >= (unsigned long)this->idle_interval) {
            color_log(0xBA, 0xBA, 5);

            int changed = 0;
            short i;
            i = (short)changed;
            if (0 < this->save_attr_num) {
                short* saved = this->save_attr;
                float* values = this->player->float_values;
                for (;;) {
                    if (i >= this->save_attr_num)
                        break;
                    if ((short)(int)values[i] != saved[i]) {
                        changed = 1;
                        break;
                    }
                    i++;
                }
            }

            if (changed) {
                color_log(0xBA, 0x16, 5);
                save_info();
#ifdef TPNL_INV_SHARED_CONTEXT
                this->set_redraw(1);
#else
                vf20(1);
#endif
            }

            this->idle_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xC2);
            color_log(0xBA, 0x5F, 5);
        }
    }
    return 0;
}
