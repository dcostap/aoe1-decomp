// VA: 0048F190 TribeAchievementsScreen::handle_mouse_down (226 B)
// PDB source: scr_ach.cpp (lines 783-801)
// Packet-grounded: virtual thiscall override; base TEasy_Panel::handle_mouse_down call,
// then mode-0-only dispatch through the five achievement_choice TTextPanel buttons,
// calling set_mode(1..4). Offsets proven: current_mode +0x47C, achievement_choice +0x4B4.
//
// Attempt log:
// - (prior scratch content was an unrelated wrong shim; replaced with the packet-grounded
//   natural member/class reconstruction)

#include "../../include/scr_ach_context.h"

long TribeAchievementsScreen::handle_mouse_down(unsigned char button, long x, long y, int flags, int area)
{
    long result = TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
    if (current_mode == 0) {
        if (achievement_choice[0]->is_inside(x, y)) {
            set_mode(1);
            return result;
        }
        if (achievement_choice[1]->is_inside(x, y)) {
            set_mode(2);
            return result;
        }
        if (achievement_choice[2]->is_inside(x, y)) {
            set_mode(3);
            return result;
        }
        if (achievement_choice[3]->is_inside(x, y)) {
            if (achievement_choice[4]->is_inside(x, y) == 0) {
                set_mode(4);
            }
        }
    }
    return result;
}
