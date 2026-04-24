// TRIBE_Panel_Inven::handle_idle
// Checks game mode, timer, and whether saved values changed.
// If changed, calls save_info and triggers redraw (vf20).
// changed base call to nonvirtual TPanel::handle_idle-style declaration; prolog now matches through the base call
// tried int loop index; worsened to 0x0c stack frame, rolled back to short index/do-while family
// tried plain for-loop with p local; worsened this register to edi, rolled back
// swapped loop locals to get ebx=this and two stack locals; current first real drift is loop source shape/bounds layout

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl color_log(unsigned char a, unsigned char b, unsigned char c);

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

extern int TRIBE_Panel_Inven_vftable;

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

long TRIBE_Panel_Inven::handle_idle() {
    ((TPanel*)this)->handle_idle();

    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xAD);
        if (now - this->idle_time >= (unsigned long)this->idle_interval) {
            color_log(0xBA, 0xBA, 5);

            int changed = 0;
            short i = 0;
            if (this->save_attr_num > i) {
                short* saved = this->save_attr;
                float* values = this->player->float_values;
                do {
                    if ((short)(int)values[i] != saved[i]) {
                        changed = 1;
                        break;
                    }
                    i++;
                } while (i < this->save_attr_num);
            }

            if (changed) {
                color_log(0xBA, 0x16, 5);
                save_info();
                vf20(1);
            }

            this->idle_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xC2);
            color_log(0xBA, 0x5F, 5);
        }
    }
    return 0;
}
