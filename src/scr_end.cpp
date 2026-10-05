
#include "../include/scr_end.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_pic.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"
#include "../include/scr_ach.h"
#include <string.h>

TribeEndScreen::TribeEndScreen(char* titleText, char** textText, int textLineCount) : TScreenPanel("End Screen") {
    char backgroundName[10];

    if (setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        error_code = 1;
        return;
    }

    if (render_area->Width < 800) {
        strcpy(backgroundName, "bgA640");
    } else if (render_area->Width < 1024) {
        strcpy(backgroundName, "bgA800");
    } else {
        strcpy(backgroundName, "bgA1024");
    }

    background = new TPicturePanel;
    if (background == 0) {
        error_code = 1;
        return;
    }
    if (background->setup(render_area, this, 0, 0, 0, 0, backgroundName, -1, 0, 1) == 0) {
        error_code = 1;
        return;
    }

    background->set_positioning(
        TPanel::PositionCentered, 0, 0, 0, 0, pnl_wid * 640 / 640, pnl_wid * 640 / 640, pnl_hgt * 480 / 480,
        pnl_hgt * 480 / 480, 0, 0, 0, 0
    );

    RGE_Font* font = rge_base_game->get_font(RGE_FONT_COPPERPLATE_21_BOLD);
    title = new TTextPanel;
    if (title == 0) {
        error_code = 1;
        return;
    }
    title->setup(
        render_area, background, pnl_wid * 20 / 640, pnl_hgt * 20 / 480, pnl_wid * 600 / 640, pnl_hgt * 30 / 480,
        font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, titleText
    );

    text = new TTextPanel;
    if (text == 0) {
        error_code = 1;
        return;
    }
    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    text->setup(
        render_area, background, pnl_wid * 20 / 640, pnl_hgt * 70 / 480, pnl_wid * 600 / 640, pnl_hgt * 340 / 480,
        font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, static_cast<char*>(0)
    );
    text->set_text(textText, static_cast<short>(textLineCount));
    text->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    text->scroll(6, 0, 1);

    TDigital* sound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(RGE_FONT_COPPERPLATE_12_BOLD);
    okButton = new TButtonPanel;
    if (okButton == 0) {
        error_code = 1;
        return;
    }
    okButton->setup(
        render_area, background, pnl_wid * 170 / 640, pnl_hgt * 430 / 480, pnl_wid * 300 / 640, pnl_hgt * 40 / 480,
        TButtonPanel::DrawText, sound, TButtonPanel::NotifyAction, 0
    );
    okButton->set_text_info("OK", font->font, font->font_wid, font->font_hgt, -1, -1);

    set_curr_child(background);
    background->set_curr_child(text);
}

TribeEndScreen::~TribeEndScreen() {
    delete title;
    delete text;
    delete okButton;
    delete background;
}

long TribeEndScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel == 0 || actionIn != 1) {
        return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
    }

    new TribeAchievementsScreen(get_string(STRING_ID_ACHIEVEMENTS_TITLE), 1);
    panel_system.setCurrentPanel("Achievements Screen", 0);
    panel_system.destroyPanel("End Screen");
    return 1;
}
