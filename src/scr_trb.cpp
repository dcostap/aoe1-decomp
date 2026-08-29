
#include <string.h>
#include "../include/scr_trb.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_pic.h"
#include "../include/basegame.h"

// scr_trb.cpp lines 37-157
// constructor's new expressions. The fixed tab-list copy is a REP MOVSD block.

TribeSelectTribeScreen::TribeSelectTribeScreen()
    : TScreenPanel("Select Tribe Screen")
{
    char backgroundName[10];
    TPanel* tabList[10];
    RGE_Font* font;
    TDigital* buttonSound;
    int secondWidth;
    int secondHeight;
    int i;
    int width;
    TPicturePanel* backgroundPanel;

    this->screenText = 0;

    if (this->setup(rge_base_game->draw_area, 0, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    width = this->render_area->Width;
    if (width < 0x320) {
        strcpy(backgroundName, "bgA640");
    } else {
        if (width < 0x400) {
            strcpy(backgroundName, "bgA800");
        } else {
            strcpy(backgroundName, "bgA1024");
        }
    }

    this->background = new TPicturePanel;
    if (this->background == 0) {
        this->error_code = 1;
        return;
    }
    if (this->background->setup(this->render_area, this, 0, 0,
                                0, 0, backgroundName, -1, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    backgroundPanel = this->background;
    secondHeight = this->pnl_hgt * 0x1E0 / 0x1E0;
    secondWidth = this->pnl_wid * 0x280 / 0x280;
    backgroundPanel->set_positioning(
        TPanel::PositionCentered, 0, 0, 0, 0, secondWidth, secondWidth,
        secondHeight, secondHeight, 0, 0, 0, 0);

    font = rge_base_game->get_font(1);
    this->title = new TTextPanel;
    if (this->title == 0) {
        this->error_code = 1;
        return;
    }
    this->title->setup(
        this->render_area, this->background,
        this->pnl_wid * 0x14 / 0x280,
        this->pnl_hgt * 0x14 / 0x1E0,
        this->pnl_wid * 600 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, "Civilization Selection");

    buttonSound = rge_base_game->get_sound(0);
    font = rge_base_game->get_font(0);
    secondWidth = 0;
    secondHeight = 0;
    i = 0;
    TButtonPanel** button = this->tribeButton;

    // The shipped loop re-enters through a zero-register reset.
    // LIKELY INTENT: The initial zero state makes this guard equivalent to do/while.
    while (i < 9) {
        *button = new TButtonPanel;
        if (*button == 0) {
            this->error_code = 1;
            return;
        }

        (*button)->setup(
            this->render_area, this->background,
            this->pnl_wid * 0x14 / 0x280 + secondWidth * this->pnl_wid / 0x280,
            this->pnl_hgt * 0x32 / 0x1E0 +
                secondHeight * this->pnl_hgt * 0x73 / 0x1E0,
            this->pnl_wid * 200 / 0x280,
            this->pnl_hgt * 0x6E / 0x1E0,
            TButtonPanel::DrawPicture, buttonSound,
            TButtonPanel::NotifyAction, 0);
        (*button)->set_text_info(this->tribeName(i), font->font,
                                 font->font_wid, font->font_hgt, -1, -1);

        if (i == 2 || i == 5) {
            secondHeight = -1;
            secondWidth += 200;
        }
        ++i;
        ++button;
        ++secondHeight;
    }

    font = rge_base_game->get_font(0xB);
    this->tribeText = new TTextPanel;
    if (this->tribeText == 0) {
        this->error_code = 1;
        return;
    }
    this->tribeText->setup(
        this->render_area, this->background,
        this->pnl_wid * 0x14 / 0x280,
        this->pnl_hgt * 400 / 0x1E0,
        this->pnl_wid * 0x1FE / 0x280,
        this->pnl_hgt * 0x3C / 0x1E0,
        font->font, font->font_wid, font->font_hgt,
        0, 0, 0, 0, 0, 0, "");
    this->tribeText->set_alignment(TTextPanel::AlignTop,
                                   TTextPanel::AlignWordwrap);

    this->okButton = new TButtonPanel;
    if (this->okButton == 0) {
        this->error_code = 1;
        return;
    }
    this->okButton->setup(
        this->render_area, this->background,
        this->pnl_wid * 500 / 0x280,
        this->pnl_hgt * 400 / 0x1E0,
        this->pnl_wid * 0x78 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        TButtonPanel::DrawPicture, buttonSound,
        TButtonPanel::NotifyAction, 0);
    this->okButton->set_text_info("Previous Screen", font->font,
                                  font->font_wid, font->font_hgt, -1, -1);

    this->cancelButton = new TButtonPanel;
    if (this->cancelButton == 0) {
            this->error_code = 1;
        return;
    }
    this->cancelButton->setup(
        this->render_area, this->background,
        this->pnl_wid * 500 / 0x280,
        this->pnl_hgt * 0x1B8 / 0x1E0,
        this->pnl_wid * 0x78 / 0x280,
        this->pnl_hgt * 0x1E / 0x1E0,
        TButtonPanel::DrawPicture, buttonSound,
        TButtonPanel::NotifyAction, 0);
    this->cancelButton->set_text_info("Cancel", font->font,
                                      font->font_wid, font->font_hgt, -1, -1);

    this->set_curr_child(this->background);
    this->background->set_curr_child(this->tribeButton[0]);
    this->fillTribeText(0);

    // Nine button pointers are copied by one REP MOVSD block.
    memcpy(tabList, this->tribeButton, 9 * sizeof(this->tribeButton[0]));
    tabList[9] = this->okButton;
    // The shipped call targets TPanel::set_tab_order directly.
    this->TPanel::set_tab_order(tabList, 10);
}

// scr_trb.cpp lines 162-172

extern void __cdecl free(void* ptr);

TribeSelectTribeScreen::~TribeSelectTribeScreen() {
    delete title;
    delete tribeText;
    {
        int i;
        for (i = 0; i < 9; i++) {
            delete tribeButton[i];
        }
    }
    delete okButton;
    delete cancelButton;
    {
        int i;
        for (i = 0; i < numLines; i++) {
            free(screenText[i]);
        }
    }
    free(screenText);
}

// The direct member helper declarations preserve the shipped thiscall calls.

long TribeSelectTribeScreen::action(TPanel* sender, long actionType,
                                    unsigned long param3,
                                    unsigned long param4)
{
    if (sender == (TPanel*)this->okButton || sender == (TPanel*)this->cancelButton) {
        if (actionType == 1) {
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Select Tribe Screen");
            return 1;
        }
    } else if (actionType == 1) {
        int i;
        for (i = 0; i < 9; i++) {
            if (sender == (TPanel*)this->tribeButton[i]) {
                this->fillTribeText(i);
                return 1;
            }
        }
    }

    return this->TEasy_Panel::action(sender, actionType, param3, param4);
}

// scr_trb.cpp lines 202-233
// TribeSelectTribeScreen::tribeText is +0x480. The text setter is the proved
// TTextPanel virtual at +0xE8. Scroll is a direct TTextPanel member call.

void TribeSelectTribeScreen::fillTribeText(int tribeIdx) {
    switch (tribeIdx) {
    case 0:
        this->tribeText->set_text("Assyrian information here.");
        break;
    case 1:
        this->tribeText->set_text("Babylonian information here.");
        break;
    case 2:
        this->tribeText->set_text("Egyptian information here.");
        break;
    case 3:
        this->tribeText->set_text("Greek information here.");
        break;
    case 4:
        this->tribeText->set_text("Hittite information here.");
        break;
    case 5:
        this->tribeText->set_text("Isrealite information here.");
        break;
    case 6:
        this->tribeText->set_text("Minoan information here.");
        break;
    case 7:
        this->tribeText->set_text("Phoenician information here.");
        break;
    case 8:
        this->tribeText->set_text("Sumerian information here.");
        break;
    }

    this->tribeText->scroll(6, 0, 1);
}


char* TribeSelectTribeScreen::tribeName(int param_1) {
    switch (param_1) {
    case 0: return "Assyrian";
    case 1: return "Babylonian";
    case 2: return "Egyptian";
    case 3: return "Greek";
    case 4: return "Hittite";
    case 5: return "Isrealite";
    case 6: return "Minoan";
    case 7: return "Phoenician";
    case 8: return "Sumerian";
    default: return "No Culture";
    }
}
