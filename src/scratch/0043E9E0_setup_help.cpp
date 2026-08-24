// 0043E9E0 THelpDialog::setup_help
// Attempt log:
// - Baseline rebuilt the prior local class/vtable candidate; the old volatile size
//   probe was then removed as non-source scaffolding (574-byte positional diff).
// - Replaced manual sign fixups with <stdlib.h> abs(), reproducing the oracle's
//   repeated cdq/xor/sub absolute-value idiom and improving shape to 78.97%.
// - Tested declaration order, pointer/pointee volatility, typed RGE_Font::text_height,
//   x/y local reuse, the absolute global pointer, and split text-height arithmetic.
//   Only the typed font/global surfaces changed emitted bytes; duplicate/liveness
//   probes were rolled back to the clean natural form.
// - Typed the list child as a local TListPanel with the proven bot_line field;
//   it worsened the structural diff by 2 bytes and was rolled back.
// - Reordered the natural local declarations to match the original stack bands;
//   VC5 emitted identical code, so declaration order is not the current blocker.
// - Replaced the anonymous font gap with the generated RGE_Font fields
//   (font, font_wid, font_hgt); field naming and layout were codegen-neutral.
// - Swapping the height/yPosition operand order did not change codegen. Splitting
//   that expression into ordered statements aligned all 27 calls with the oracle.
// - Original stack reads prove that create_list receives the help_string parameter
//   and that the single-player branch tests and reads in_help_page_id. Correcting
//   those two argument owners made the frame exact and improved the strict diff
//   from 564 to 556 bytes. The remaining mismatch is geometry register scheduling.
// - Evaluating parent width plus xPosition directly in the first geometry guard
//   reproduced the oracle's EBX x-geometry basin. Restoring the explicit parent
//   argument on create_button and duplicating its two OK-call arms recovered the
//   oracle's shared call tail and improved the strict diff to 437 bytes.
// - BINARY NOTE: the geometry helpers use the protected const QBE symbols.
//   Reordering their declarations restores the oracle's width-then-xPosition
//   call order and improves the strict diff to 431 bytes.
// - BINARY NOTE: setup_help is protected. Keep the IAEXP owner symbol, not the
//   byte-identical public QAEXP spelling.
// - The remaining mismatch is the proven geometry home topology: the oracle
//   stores dialog_x at the dead text-parameter home and y at the dead
//   more_text-parameter home. Natural local variants did not reproduce this
//   spill without unsupported compiler steering.

#include <stdlib.h>

extern "C" char* strcpy(char*, const char*);

#include "../../include/dlg_help_context.h"

void THelpDialog::setup_help(TEasy_Panel* parent, char* text, char* more_text, long page_id, long x_limit, long y_limit)
{
    RGE_Font* rge_text_font;
    TPanel* tabList[2];
    this->ok_button = 0;
    this->encyclopedia_button = 0;
    this->title = 0;
    this->list = 0;
    strcpy(this->parent_panel, text);
    this->help_page_id = page_id;
    rge_text_font = ((RGE_Base_Game*)rge_base_game)->get_font(11);

    if (this->setup(parent->renderArea(), parent, 0x154, 0x190, parent->get_popup_info_file(), parent->get_popup_info_id(), 1)) {
        this->create_text(this, &this->list, more_text, 10, 10, 0x14a, 0x186, 11, 0, 0, 1);
        long line_count = *(short*)((char*)this->list + 0xfe) + 2;
        long dialog_x;
        long panel_height;
        panel_height = line_count * rge_text_font->font_hgt + 0x37;

        if (parent->width() + parent->xPosition() >= x_limit + 0x163) {
            dialog_x = abs(parent->xPosition() - x_limit - 5);
        } else if (parent->xPosition() + 10 <= x_limit - 0x159) {
            dialog_x = abs((x_limit - 0x159) - parent->xPosition());
        } else {
            dialog_x = parent->width() / 2 - 0xaa;
        }
        if (dialog_x < 0) dialog_x = 0;

        long y = y_limit - panel_height;
        if (parent->yPosition() <= y - 10) {
            y = abs(y - parent->yPosition() - 10);
        } else {
            y = parent->height();
            y += parent->yPosition();
            if (panel_height + y_limit + 10 <= y) {
                y = abs(y_limit - parent->yPosition() + 10);
            } else {
                y = parent->height() / 2 - panel_height / 2;
            }
        }
        if (y < 0) y = 0;

        this->set_fixed_position(dialog_x, y, 0x154, panel_height);
        this->set_ideal_size(this->field_B0, this->field_B8);
        this->list->set_fixed_position(10, 10, 0x14a, line_count * rge_text_font->font_hgt);

        if (((RGE_Base_Game*)rge_base_game)->singlePlayerGame() && page_id >= 0) {
            char* s = this->get_string((int)page_id);
            if (s != 0 && *s != 0) {
                this->create_button(this, &this->encyclopedia_button, 0x243d, 0, 0, 25,
                                    line_count * rge_text_font->font_hgt + 20,
                                    0x78, 25, 11, 0);
            }
        }

        if (this->encyclopedia_button == 0) {
            this->create_button(this, &this->ok_button, 0xfa1, 0, 0x6e,
                                line_count * rge_text_font->font_hgt + 20,
                                0x78, 25, 11, 0, 0);
        } else {
            this->create_button(this, &this->ok_button, 0xfa1, 0, 0xc3,
                                line_count * rge_text_font->font_hgt + 20,
                                0x78, 25, 11, 0, 0);
        }
        this->ok_button->hotkey = 0x1b;
        this->ok_button->hotkey_shift = 0;
        this->set_curr_child(this->ok_button);
        tabList[0] = this->ok_button;
        long count = 1;
        if (this->encyclopedia_button != 0) {
            tabList[1] = this->encyclopedia_button;
            count = 2;
        }
        this->set_tab_order(tabList, (short)count);
    }
}
