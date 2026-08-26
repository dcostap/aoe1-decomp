// VA: 004206D0 RGE_Base_Game::wnd_proc (2181 B)
// PDB source: basegame.cpp:3513-3975
// Attempt log:
// - Rebuilt the message dispatcher from the executable's ordered calls and
//   switch cases.  The prior file was only a behavior sketch with omitted
//   handlers and wrapper calls.
// - Added the period Win32 imports, named base-game fields, panel virtual
//   surface, sound/music forwarding, and all observed message handlers.
// - Corrected the WM_CLOSE fallthrough and shared the 0x10/0x30F and
//   0x3B9/0x500 handler tails.  The child-cursor state is at 0062C4C4.
// - Raw return blocks at 00420D04, 00420E5E, and 00420E74 reload the wparam
//   home at [esp+24].  Ordinary handled tails return wparam; only WM_USER
//   0x400 returns the panel result after restoring debug_timeGetTime_on.
// - An explicit mouse_down pair in the destroy, exit-menu, and music paths was
//   rolled back after VC5 proved it away or merged it without adding calls.
// - Inlining the panel-result tails for exit-menu and music-done raised the
//   call surface from 74 to 78 calls and the shape score to 89.33 percent.
// - A WM_SIZE tail returning wparam kept a separate 4C/24 log pair: 80/80
//   calls and +1 byte versus 80/80 and -9 bytes with panel_result.  Keep this
//   binary-supported return-home lead while the shared-tail return remains.
// - Replacing all handled-tail predicates with mouse_down matched the later
//   [esp+10] loads but collapsed four log calls.  Restored the 80-call source.
// - Kept the WM_SIZE handled tail on mouse_down: it recovers the binary's
//   [esp+10] load and one exact block without changing the 80-call surface.
// - Corrected WM_ACTIVATE to use wparam's high word.  Named int word values
//   recover the binary's shared extraction and reduce the diff to 1118 bytes;
//   the remaining cost is a 17-byte size increase and tail placement drift.
// - Inlined the thread-id comparison and reversed its operands to match the
//   original call-result homes and cmp operand order.
// - Made the definition the __stdcall RGE_Base_Game member.  This restores the
//   original decorated owner symbol and the stack-passed member ABI.
// - Binary evidence at 00420D04 loads the mouse-down home before the handled
//   log pair.  The early handled tail now uses that predicate; changing the
//   other joined tails merges distinct shipped blocks and loses call order.
// - Tested the exact-donor panel_system macro and the period Windows SDK
//   surface.  They restore the absolute panel receiver, but do not remove the
//   remaining tail-placement drift.
// - Probes 1-25 tested owner ABI, return-tail predicates, stack aliases,
//   global forms, SDK context, boolean width, and switch source order.
// - Direct external declarations for the fixed storage slots recover the
//   original absolute load/store form without pointer aliases.  The remaining
//   drift is the compiler's shared WM_SIZE logging tail and shifted blocks.
// - Behavior review corrected message 0x400's first color-log argument,
//   restored WM_COMMAND's unconditional DefWindowProcA path, and made the
//   music-done exit log depend only on mouse_down before returning wparam.
// - The corrected ordinary tails improve the current check to 1,609 bytes,
//   94.88 percent shape, and 78/80 ordered calls.  VC5 still merges the
//   WM_SIZE two-log block into the music block.  Raw code proves a separate
//   block at 00420859; source-order and lifetime probes did not split it.

#include <windows.h>

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern void color_log(unsigned char a, unsigned char b, int c);

// BINARY NOTE: these external objects occupy the fixed storage slots observed
// in the executable.  Direct objects preserve the original absolute accesses.
extern int system_ignore_size_messages_storage;
extern int MouseCursorInChildContol_storage;
extern int mouse_cursor_in_child_control_storage;
extern void* save_active_wnd_storage;
extern int do_restore_palette_storage;
extern unsigned long restore_palette_timer_storage;
extern int restore_mouse_after_paint_storage;
extern int debug_timeGetTime_on_storage;





class TPanel;

// BINARY NOTE: panel_system is the fixed object at 0062E870.
long __stdcall RGE_Base_Game::wnd_proc(void* hwnd, unsigned int msg,
                                       unsigned int wparam, long lparam)
{
    RGE_Base_Game* self = this;
    color_log(0x24, 0x24, 3);
    int mouse_down = 0;
    if (msg >= 0x201 && msg <= 0x206) {
        mouse_down = 1;
        color_log(0x4C, 0x4C, 4);
    }

    if (self->sound_system != 0) {
        self->sound_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x16, 3);
    if (self->music_system != 0) {
        self->music_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x4C, 3);

    long panel_result = 0;
    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x24, 0x32, 3);
        panel = panel_system.currentPanel();
        panel_result = panel->wnd_proc(hwnd, msg, wparam, lparam);
        if (panel_result != 0 && msg != 0x200 && msg != 0x113)
            goto panel_return_after_exit_menu;
    }

    color_log(0x24, 0x45, 3);

    switch (msg) {
    case 2:
        color_log(0x32, 0xBA, 3);
        if (self->handle_destroy(hwnd, 2, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 5:
        {
        if (system_ignore_size_messages_storage != 0)
            goto default_window_proc;
        color_log(0x32, 0xBA, 3);
        int size_handled = self->handle_size(hwnd, 5, wparam, lparam);
        if (size_handled != 0)
            goto default_window_proc;
        if (mouse_down == 0)
            goto wparam_return;
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)wparam;
        }

    case 6:
        if (self->prog_ready != 0) {
            int active_state = wparam & 0xFFFF;
            int minimized = wparam >> 16;
            if (active_state == 0) {
                if (GetWindowThreadProcessId((void*)lparam, 0) ==
                    GetWindowThreadProcessId(self->prog_window, 0))
                    save_active_wnd_storage = (void*)lparam;
            }
            if (hwnd == self->prog_window && active_state != 0 &&
                minimized != 0 && save_active_wnd_storage != 0) {
                save_active_wnd_storage = 0;
            }
        }
        goto default_window_proc;

    case 0x0F:
        color_log(0x32, 0x45, 3);
        if (self->handle_paint(hwnd, 0x0F, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x1C:
        if (self->prog_ready != 0) {
            if (wparam == 1) {
                if (MouseCursorInChildContol_storage != 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    if (self->prog_mode != 1)
                        self->restart_sound_system();
                    MouseCursorInChildContol_storage = 0;
                    if (self->draw_system != 0) {
                        self->draw_system->CheckSurfaces();
                        self->draw_system->ClearRestored();
                        self->set_render_all();
                    }
                    if (self->prog_mode != 1) {
                        if (self->draw_system != 0) {
                            self->draw_system->ClearPrimarySurface();
                            self->draw_system->ModifyPalette(
                                0, 0x100, self->draw_system->palette);
                        }
                        self->set_render_all();
                        InvalidateRect(self->prog_window, 0, 1);
                        do_restore_palette_storage = 10;
                        restore_palette_timer_storage = debug_timeGetTime(
                            (char*)0x57FB08, 0xE9B);
                        restore_mouse_after_paint_storage = 1;
                    }
                }
            } else if (MouseCursorInChildContol_storage == 0) {
                SetClassLongA(self->prog_window, -12, 0);
                if (self->prog_mode != 1)
                    self->stop_sound_system();
                MouseCursorInChildContol_storage = 1;
                if (self->prog_mode != 1 && self->mouse_pointer != 0)
                    self->mouse_pointer->Shutdown_Mouse();
            }
        }
        color_log(0x32, 0x54, 3);
        if (self->handle_activate(hwnd, 0x1C, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x104:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x104, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x100:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x100, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x105:
        if (wparam == 0x12 && panel_system.currentPanel() != 0) {
            panel = panel_system.currentPanel();
            panel->activate_panel();
        }
        goto default_window_proc;

    case 0x111:
        color_log(0x32, 0x16, 3);
        if (self->handle_command(hwnd, 0x111, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

    case 0x112:
        if (wparam == 0xF100 && self->prog_info->field_894 != 0 &&
            IsIconic(self->prog_window) == 0)
            return 0;
        goto default_window_proc;

    case 0x113:
        if (self->handle_idle() != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x116:
        color_log(0x32, 0xBA, 3);
        if (self->handle_init_menu(hwnd, 0x116, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x200:
        color_log(0x24, 0x54, 3);
        if (self->handle_mouse_move(hwnd, 0x200, wparam, lparam) != 0) {
            if (mouse_cursor_in_child_control_storage != 0) {
                if (self->windows_mouse == 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    self->mouse_on();
                    mouse_cursor_in_child_control_storage = 0;
                } else {
                    SetCursor(self->mouse_cursor);
                    mouse_cursor_in_child_control_storage = 0;
                }
            }
            goto default_window_proc;
        }
        goto panel_return;

    case 0x212:
        color_log(0x32, 0xBA, 3);
        if (self->handle_exit_menu(hwnd, 0x212, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

panel_return_after_exit_menu:
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)wparam;

    case 0x218:
        if (wparam == 0)
            return 0x424D5144;
        goto default_window_proc;

    case 0x10:
        goto close_message;

    case 0x30F:
        color_log(0x32, 0xBA, 3);
        if (self->handle_query_new_palette(hwnd, 0x30F, wparam, lparam) != 0)
            goto close_message;
        goto panel_return_alt;

    case 0x311:
        color_log(0x32, 0xBA, 3);
        if (self->handle_palette_changed(hwnd, 0x311, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 0x3B9:
        goto music_done_message;

    case 0x400:
        color_log(0x32, 0x24, 3);
        {
            int old_time = debug_timeGetTime_on_storage;
            debug_timeGetTime_on_storage = 0;
            if (self->handle_user_command(hwnd, 0x400, wparam, lparam) == 0) {
                if (mouse_down != 0)
                    color_log(0x4C, 0x5F, 4);
                color_log(0x24, 0x5F, 3);
                debug_timeGetTime_on_storage = old_time;
                return (long)panel_result;
            }
            debug_timeGetTime_on_storage = old_time;
        }
        goto default_window_proc;

    case 0x500:
        goto music_done_message;

close_message:
    color_log(0x32, 0xBA, 3);
    if (self->handle_close(hwnd, msg, wparam, lparam) != 0)
        goto default_window_proc;
    if (panel_result != 0) {
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)panel_result;
    }
    goto panel_return_alt;

music_done_message:
    {
    color_log(0x32, 0x4C, 3);
    int music_handled = self->handle_music_done(hwnd, msg, wparam, lparam);
    if (music_handled != 0)
        goto default_window_proc;
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;
    }

    default:
        goto default_window_proc;
    }

 wparam_return:
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

panel_return:
    if (mouse_down == 0)
        goto panel_return_alt;
    color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

panel_return_alt:
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

default_window_proc:
    {
        color_log(0x24, 0x54, 3);
        long result = DefWindowProcA(hwnd, msg, wparam, lparam);
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return result;
    }

}
