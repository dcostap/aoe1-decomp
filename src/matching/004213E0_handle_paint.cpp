// VA: 004213E0 RGE_Base_Game::handle_paint (1096 B)
// PDB source: basegame.cpp:4319-4531
// Attempt log:
// - Replaced the packet's raw-offset/free-function scaffold with the period
//   typed RGE_Base_Game, TDrawSystem, TPanel, TMousePointer, and COM surfaces.
//   Kept the original timing/panel/mouse control-flow shape and corrected the
//   final InvalidateRect receiver to the incoming window parameter.
// - The animation deadline is updated in place before the do-loop; this is the
//   natural source form that preserves the oracle's result/deadline registers.
// - The panel test is a direct positive currentPanel() predicate, and the
//   proven panel_system global is kept at 0062E870.
// - The late timing expression keeps the panel delta on the left of the
//   inline 115B elapsed subtraction; this preserves the original x86 order.



typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT;
class TDrawArea;
class TShape;

extern void color_log(unsigned char a, unsigned char b, int c);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);










extern RGE_Base_Game* rge_base_game;
extern int restore_mouse_after_paint;
int RGE_Base_Game::handle_paint(void* param_1, unsigned int param_2,
                                unsigned int param_3, long param_4)
{
    unsigned long time_a;
    unsigned long time_b;
    unsigned long time_c;
    int result;

    color_log(0x32, 0x32, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x10EA);
    result = this->check_paint();
    time_b = debug_timeGetTime((char*)0x57FB08, 0x10EE);
    this->add_to_timing(5, time_b - time_a);

    if (result == 0) {
        color_log(0x32, 0x5F, 4);
        return 0;
    }

    if (((this->prog_mode == 4 || this->prog_mode == 6 ||
          this->prog_mode == 7) &&
         this->draw_system->DrawType != 1 && this->custom_mouse != 0) &&
        this->mouse_blit_sync != 0) {
        IDirectDrawSurface* surface = this->draw_system->PrimarySurface;
        result = surface->GetBltStatus(1);
        time_a = debug_timeGetTime((char*)0x57FB08, 0x10FC);
        time_a += 100;

        do {
            if (result != (int)0x8876021C)
                goto paint_done;

            surface = this->draw_system->PrimarySurface;
            result = surface->GetBltStatus(1);
            time_b = debug_timeGetTime((char*)0x57FB08, 0x1100);
        } while (time_b <= time_a);

        this->mouse_blit_sync = 0;
    }

paint_done:
    color_log(0x32, 0xBA, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x110C);
    TSound_Driver* sound = rge_base_game->sound_system;
    if (sound != 0) {
        sound->play_list();
        sound->reset_play_list();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1115);
    this->add_to_timing(10, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x111C);
    if (this->erase_mouse != 0) {
        color_log(0x32, 0x4C, 4);
        if (this->render_all == 0 && this->custom_mouse != 0)
            this->mouse_pointer->erase();
        this->erase_mouse = 0;
    }

    time_c = debug_timeGetTime((char*)0x57FB08, 0x1127) - time_a;
    time_a = debug_timeGetTime((char*)0x57FB08, 0x112A);
    color_log(0x32, 0x16, 4);

    TPanel* panel;
    if (panel_system.currentPanel() != 0) {
        color_log(0x16, 0x16, 1);
        if (this->render_all != 0) {
            panel = panel_system.currentPanel();
            panel->set_redraw(2);
        }
        panel = panel_system.currentPanel();
        panel->handle_paint();
        color_log(0x16, 0x5F, 1);
    } else {
        this->clear_window();
    }

    color_log(0x32, 0x24, 4);
    if (DAT_0062c57c != 0) {
        DAT_0062c57c = 0;
        if ((this->prog_mode == 4 || this->prog_mode == 5) &&
            this->do_show_timings != 0)
            this->show_timings();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1147);
    this->add_to_timing(2, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x114B);
    color_log(0x32, 0x54, 4);
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    time_c += debug_timeGetTime((char*)0x57FB08, 0x115B) - time_a;
    this->add_to_timing(8, time_c);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1160);
    color_log(0x32, 0x45, 4);
    this->draw_system->Paint(0);
    ValidateRect(this->prog_window, 0);
    ValidateRect(this->prog_window, 0);
    this->render_all = 0;

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1176);
    this->add_to_timing(3, time_b - time_a);

    color_log(0x32, 0x5F, 4);
    ++this->frame_count;

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1182);
    if (time_a - DAT_0062c578 >= 1000) {
        this->calc_timings();
        DAT_0062c578 = time_a;
        DAT_0062c57c = 1;
    }

    if (restore_mouse_after_paint != 0) {
        if (this->mouse_pointer != 0) {
            this->mouse_pointer->Restore_Mouse(this->draw_area);
            if (this->is_mouse_on != 0) {
                if (this->custom_mouse == 0 || this->windows_mouse != 0) {
                    SetCursor(this->mouse_cursor);
                    SetClassLongA(this->prog_window, -12,
                                  (long)this->mouse_cursor);
                } else {
                    this->mouse_pointer->on();
                    this->mouse_pointer->draw(1);
                }
            }
            InvalidateRect(param_1, 0, 0);
        }
        restore_mouse_after_paint = 0;
    }

    return 1;
}
