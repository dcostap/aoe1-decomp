#include <string.h>
#include "../../include/scr_end_context.h"

// 004936D0 TribeEndScreen::TribeEndScreen
// Source: scr_end.cpp lines 34-116
// Binary-backed ownership: TScreenPanel ends at +0x478. The four child
// panels occupy +0x478 through +0x487. The constructor arguments are the
// title string and the text list passed to the text panel.
// Attempt log:
// - Baseline: restored the typed TScreenPanel hierarchy, the proven child
//   allocation sizes, the resolution background copy, the three panel setup
//   calls, the text-list virtual call, and the final child chain.
// - Probe 2: changed the resolution gate to render_area->width, matching the
//   original [this+0x20]+0x18 access; the natural source then matched exactly.

TribeEndScreen::TribeEndScreen(char* title_text, char** text_list,
                               int text_count)
    : TScreenPanel((char*)"End Screen")
{
    char background_name[10];

    if (this->setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    if (this->render_area->width < 0x320) {
        strcpy(background_name, "bgA640");
    } else if (this->render_area->width < 0x400) {
        strcpy(background_name, "bgA800");
    } else {
        strcpy(background_name, "bgA1024");
    }

    this->background = new TPicturePanel;
    if (this->background == 0) {
        this->setup_error = 1;
        return;
    }
    if (this->background->setup(this->render_area, this, 0, 0, 0, 0,
                                background_name, -1, 0, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    this->background->set_positioning(
        2, 0, 0, 0, 0,
        this->width * 0x280 / 0x280,
        this->width * 0x280 / 0x280,
        this->height * 0x1E0 / 0x1E0,
        this->height * 0x1E0 / 0x1E0,
        0, 0, 0, 0);

    RGE_Font* font = rge_base_game->get_font(1);
    this->title = new TTextPanel;
    if (this->title == 0) {
        this->setup_error = 1;
        return;
    }
    this->title->setup(
        this->render_area, this->background,
        this->width * 0x14 / 0x280,
        this->height * 0x14 / 0x1E0,
        this->width * 600 / 0x280,
        this->height * 0x1E / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, title_text);

    this->text = new TTextPanel;
    if (this->text == 0) {
        this->setup_error = 1;
        return;
    }
    font = rge_base_game->get_font(0x0B);
    this->text->setup(
        this->render_area, this->background,
        this->width * 0x14 / 0x280,
        this->height * 0x46 / 0x1E0,
        this->width * 600 / 0x280,
        this->height * 0x154 / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, 0);
    this->text->set_text(text_list, (short)text_count);
    this->text->set_alignment(0, 0);
    this->text->scroll(6, 0, 1);

    TDigital* sound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(0);
    this->okButton = new TButtonPanel;
    if (this->okButton == 0) {
        this->setup_error = 1;
        return;
    }
    this->okButton->setup(
        this->render_area, this->background,
        this->width * 0xAA / 0x280,
        this->height * 0x1AE / 0x1E0,
        this->width * 300 / 0x280,
        this->height * 0x28 / 0x1E0,
        3, sound, 1, 0);
    this->okButton->set_text_info((char*)"OK", font->font,
                                  font->font_wid, font->font_hgt, -1, -1);

    this->set_curr_child(this->background);
    this->background->set_curr_child(this->text);
}
