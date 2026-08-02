// VA: 00421830 RGE_Base_Game::handle_activate (215 B)
// PDB source: basegame.cpp lines 4537-4598
// Attempt log:
// baseline reconstruction: named RGE_Base_Game fields, natural active/inactive
// branches, typed direct helpers, and virtual dispatch surfaces from the packet.
// restored the missing VPAD8 macro layer; the complete virtual padding aligned
// panel +0xDC and base-game +0x110/+0x114 calls and produced an exact match.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class TPanel {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD4(48)
    VPAD2(52)
    VPAD1(54)
    virtual void activate_panel(); // vtable +0xDC
};

class TPanelSystem {
public:
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    VPAD64(0)
    VPAD4(64)
    virtual void activate_dispatch();   // vtable +0x110
    virtual void deactivate_dispatch(); // vtable +0x114

    char gap_04[0x18 - 0x04];
    int prog_active; // +0x18
    char gap_1C[0x1B0 - 0x1C];
    int prog_mode;   // +0x1B0
    char gap_1B4[0x9FC - 0x1B4];
    int auto_paused; // +0x9FC

    int singlePlayerGame();
    int get_paused();
    void set_paused(int paused, int non_user_pause);

    int handle_activate(void* param_1, unsigned int param_2,
                        unsigned int param_3, long param_4);
};

int RGE_Base_Game::handle_activate(void* param_1, unsigned int param_2,
                                   unsigned int param_3, long param_4)
{
    if (param_3 != 0) {
        this->prog_active = 1;
    } else {
        this->prog_active = 0;
    }

    if (this->prog_active != 0) {
        if ((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) &&
            this->auto_paused == 1) {
            this->auto_paused = 0;
            this->set_paused(0, 0);
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->activate_panel();
        }
        this->activate_dispatch();
    } else {
        if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) {
            if (this->singlePlayerGame() == 1 && this->get_paused() == 0) {
                this->auto_paused = 1;
                this->set_paused(1, 0);
            }
        }
        this->deactivate_dispatch();
    }

    return 1;
}
