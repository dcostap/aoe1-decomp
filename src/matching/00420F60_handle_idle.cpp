// VA: 00420F60 RGE_Base_Game::handle_idle (431 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline used a packet-grounded free-function/raw-offset scaffold; it had
//   the correct broad behavior but emitted wrapper call identities and a raw
//   vtable call, leaving a 463-byte / 21-call mismatch.
// - Probe 2: restored the period typed member surfaces for RGE_Base_Game,
//   TDrawSystem, TSound_Driver, TPanelSystem, TPanel, and communications. The
//   field ownership remains named; the original panel palette member and
//   virtual show_comm/show_ai calls are used instead of raw vtable plumbing.

extern void color_log(unsigned char a, unsigned char b, int c);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern int do_restore_palette;
extern int restore_palette_timer;




class TPanel;
class TDrawArea;
typedef int PositionMode;
typedef int RedrawMode;



extern TPanelSystem panel_system;



int RGE_Base_Game::handle_idle()
{
    if (!this->prog_ready || !this->prog_window)
        return 0;

    color_log(0x16, 0x16, 2);

    if (do_restore_palette && this->prog_active) {
        int delay = 0xFA;
        if (do_restore_palette > 5)
            delay = 0x1F4;

        unsigned long t = debug_timeGetTime((char*)0x57FB08, 0xF9A);
        if ((t - restore_palette_timer) >= (unsigned long)delay) {
            if (this->draw_system) {
                this->draw_system->ModifyPalette(0, 0x100,
                    this->draw_system->palette);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime((char*)0x57FB08,
                                                       0xFA4);
        }
    }

    color_log(0x32, 0x32, 5);

    if (this->sound_system) {
        color_log(0x16, 0xBA, 2);
        this->sound_system->handle_messages(this->prog_window, 0x113, 0, 0);
    }

    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x16, 0x45, 2);
        panel = panel_system.currentPanel();
        panel->handle_idle();
    }

    if (this->comm_handler) {
        if (this->multiplayerGame()) {
            color_log(0x45, 0x45, 1);
            this->comm_handler->ReceiveGameMessages();
            color_log(0x45, 0x5F, 1);
        }
    }

    if (this->do_show_comm) {
        color_log(0x16, 0x32, 2);
        this->show_comm();
    }

    if (this->do_show_ai) {
        color_log(0x16, 0x24, 2);
        this->show_ai();
    }

    color_log(0x32, 0x5F, 5);
    color_log(0x16, 0x5F, 2);

    return 1;
}
