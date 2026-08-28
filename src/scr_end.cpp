// PDB source module: C:\msdev\work\age1_x1\scr_end.cpp.
// The normal owners follow PDB source lines 34 through 143.

#include "../include/scr_end.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_pic.h"
#include "../include/rge_base_game_global.h"
#include "../include/scr_ach.h"
#include <string.h>

TribeEndScreen::TribeEndScreen(char* title_text, char** text_list,
                               int text_count)
    : TScreenPanel("End Screen")
{
    char background_name[10];

    if (setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        error_code = 1;
        return;
    }

    if (render_area->Width < 0x320) {
        strcpy(background_name, "bgA640");
    } else if (render_area->Width < 0x400) {
        strcpy(background_name, "bgA800");
    } else {
        strcpy(background_name, "bgA1024");
    }

    background = new TPicturePanel;
    if (background == 0) {
        error_code = 1;
        return;
    }
    if (background->setup(render_area, this, 0, 0, 0, 0, background_name,
                          -1, 0, 1) == 0) {
        error_code = 1;
        return;
    }

    background->set_positioning(
        TPanel::PositionCentered, 0, 0, 0, 0,
        pnl_wid * 0x280 / 0x280,
        pnl_wid * 0x280 / 0x280,
        pnl_hgt * 0x1E0 / 0x1E0,
        pnl_hgt * 0x1E0 / 0x1E0,
        0, 0, 0, 0);

    RGE_Font* font = rge_base_game->get_font(1);
    title = new TTextPanel;
    if (title == 0) {
        error_code = 1;
        return;
    }
    title->setup(
        render_area, background,
        pnl_wid * 0x14 / 0x280,
        pnl_hgt * 0x14 / 0x1E0,
        pnl_wid * 600 / 0x280,
        pnl_hgt * 0x1E / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, title_text);

    text = new TTextPanel;
    if (text == 0) {
        error_code = 1;
        return;
    }
    font = rge_base_game->get_font(0x0B);
    text->setup(
        render_area, background,
        pnl_wid * 0x14 / 0x280,
        pnl_hgt * 0x46 / 0x1E0,
        pnl_wid * 600 / 0x280,
        pnl_hgt * 0x154 / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, static_cast<char*>(0));
    text->set_text(text_list, static_cast<short>(text_count));
    text->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    text->scroll(6, 0, 1);

    TDigital* sound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(0);
    okButton = new TButtonPanel;
    if (okButton == 0) {
        error_code = 1;
        return;
    }
    okButton->setup(
        render_area, background,
        pnl_wid * 0xAA / 0x280,
        pnl_hgt * 0x1AE / 0x1E0,
        pnl_wid * 300 / 0x280,
        pnl_hgt * 0x28 / 0x1E0,
        TButtonPanel::DrawPicture, sound, TButtonPanel::NotifyAction, 0);
    okButton->set_text_info("OK", font->font, font->font_wid, font->font_hgt,
                            -1, -1);

    set_curr_child(background);
    background->set_curr_child(text);
}

TribeEndScreen::~TribeEndScreen()
{
    delete title;
    delete text;
    delete okButton;
    delete background;
}

long TribeEndScreen::action(TPanel* panel, long id, unsigned long param3,
                            unsigned long param4)
{
    if (panel == 0 || id != 1) {
        return TEasy_Panel::action(panel, id, param3, param4);
    }

    new TribeAchievementsScreen(get_string(0x269E), 1);
    panel_system.setCurrentPanel("Achievements Screen", 0);
    panel_system.destroyPanel("End Screen");
    return 1;
}
