// VA: 004959B0 set_overlapped_redraw (217B)
// scr_game.cpp
// Attempt log:
// - baseline: typed modal-panel and RECT reconstruction matched frame, size,
//   saved registers, and calls; the RECT copy order and comparison orientation
//   remained different.
// - layout: copied param_1->clip_rect before dialog->clip_rect, matching the
//   binary's field-load order and reducing the diff to 26 bytes.
// - control-flow: used the binary-observed comparison operand orientations for
//   the two symmetric rectangle-overlap tests; this reached exact bytes.
// - control-flow: combined the two orientations into one OR with one shared
//   redraw call, preserving the exact output while better reflecting the
//   period-plausible source shape.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::set_overlapped_redraw(
    TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3)
{
    TPanel* dialog = panel_system.modalPanel();
    if (dialog != 0) {
        tagRECT this_rect = param_1->clip_rect;
        tagRECT other_rect = dialog->clip_rect;

        if ((
            (
                ((other_rect.left >= this_rect.left) &&
                 (other_rect.left <= this_rect.right)) ||
                ((other_rect.right >= this_rect.left) &&
                 (other_rect.right <= this_rect.right)) ||
                ((this_rect.left > other_rect.left) &&
                 (other_rect.right > this_rect.right))
            ) &&
            (
                ((other_rect.top >= this_rect.top) &&
                 (other_rect.top <= this_rect.bottom)) ||
                ((other_rect.bottom >= this_rect.top) &&
                 (other_rect.bottom <= this_rect.bottom)) ||
                ((other_rect.top < this_rect.top) &&
                 (other_rect.bottom > this_rect.bottom))
            )
        ) ||
        (
            (
                ((this_rect.left >= other_rect.left) &&
                 (this_rect.left <= other_rect.right)) ||
                ((this_rect.right >= other_rect.left) &&
                 (this_rect.right <= other_rect.right)) ||
                ((this_rect.left < other_rect.left) &&
                 (this_rect.right > other_rect.right))
            ) &&
            (
                ((this_rect.top >= other_rect.top) &&
                 (this_rect.top <= other_rect.bottom)) ||
                ((this_rect.bottom >= other_rect.top) &&
                 (this_rect.bottom <= other_rect.bottom)) ||
                ((this_rect.top < other_rect.top) &&
                 (this_rect.bottom > other_rect.bottom))
            )
        )) {
            dialog->set_redraw(param_3);
        }
    }
}
