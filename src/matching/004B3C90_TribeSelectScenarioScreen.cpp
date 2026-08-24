// 004B3C90 TribeSelectScenarioScreen::TribeSelectScenarioScreen
// Initial authentic TU recovery. Shared declarations live in scr_sels_context.h.
#include "../../include/scr_sels_context.h"

TribeSelectScenarioScreen::TribeSelectScenarioScreen()
    : TScreenPanel(s_Select_Scenario_Screen)
{
    char* setup_file;
    TDrawArea* draw_area;
    int multiplayer;

    this->init_vars();

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = s_scr3;
    if (multiplayer == 0)
        setup_file = s_scr2;

    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(draw_area, 0, setup_file,
                                  (rge_base_game->multiplayerGame() != 0) +
                                      0xC384,
                                  1, 0, 0, 0, 0, 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x25FA,
                          0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->scenarioListX = 0x14;
        this->scenarioListY = 0x46;
        this->scenarioListWidth = 0x258;
        this->scenarioListHeight = 0x107;

        if (this->create_list(this, &this->scenarioList,
                              0x14, 0x46, 0x258, 0x107, 0x0B)) {
            this->scenarioList->set_second_column_pos(
                ((this->scenarioListWidth - 0x3C) * this->pnl_wid) /
                this->ideal_width);
            this->scenarioList->set_text((long)0x25FD);

            if (this->create_auto_scrollbar(&this->scenarioScrollbar,
                                            this->scenarioList, 0x14)) {
                this->scenarioScrollbar->set_help_info(-1, -1);

                if (this->create_text(this, &this->scenarioTitle, 0x25FE,
                                      this->scenarioListX,
                                      this->scenarioListY - 0x14,
                                      0x12C, 0x14, 4, 0, 0, 0)) {
                    if (this->create_text(this, &this->scenarioPlayersTitle,
                                          0x25FF,
                                          this->scenarioListWidth - 0xDC +
                                              this->scenarioListX,
                                          this->scenarioListY - 0x14,
                                          0xC8, 0x14, 4, 0, 0, 0)) {
                        this->scenarioPlayersTitle->set_alignment(3, 2);

                        this->missionTextX = this->scenarioListX;
                        this->missionTextY = this->scenarioListHeight +
                                             this->scenarioListY + 0x19;
                        this->missionTextWidth = this->scenarioListWidth;
                        this->missionTextHeight = 0x3C;

                        if (this->create_text(this, &this->missionTitle,
                                              0x2600, this->missionTextX,
                                              this->missionTextY - 0x14,
                                              0x190, 0x14, 4, 0, 0, 0)) {
                            if (this->create_text(
                                    this, &this->missionText,
                                    s_592A40, this->missionTextX,
                                    this->missionTextY,
                                    this->missionTextWidth,
                                    this->missionTextHeight,
                                    0x0B, 0, 0, 1)) {
                                this->missionText->set_bevel_info(
                                    3, this->desc[0], this->desc[1],
                                    this->desc[2], this->desc[3],
                                    this->desc[4], this->desc[5]);

                                if (this->create_auto_scrollbar(
                                        &this->missionScrollbar,
                                        this->missionText, 0x14)) {
                                    this->missionScrollbar->set_help_info(
                                        0x7532, -1);

                                    if (this->create_button(
                                            this, &this->okButton, 0x0FA1,
                                            0, 0x46, 0x1B8, 0xF0, 0x1E,
                                            0, 0, 0)) {
                                        this->okButton->set_help_info(
                                            0x7531, -1);

                                        if (this->create_button(
                                                this, &this->cancelButton,
                                                0x0FA2, 0, 0x14A, 0x1B8,
                                                0xF0, 0x1E, 0, 0, 0)) {
                                            this->cancelButton->set_help_info(
                                                0x7532, -1);
                                            TButtonPanel* cancel =
                                                this->cancelButton;
                                            cancel->hotkey = 0x1B;
                                            cancel->hotkey_shift = 0;

                                            if (this->create_button(
                                                    this, &this->close_button,
                                                    0x03EA, 0, 0, 0, 0, 0,
                                                    -1, -1, 0)) {
                                                this->close_button->set_active(1);
                                                this->close_button->set_positioning(
                                                    9, 4, 4, 4, 4, 0x11,
                                                    0x11, 0x11, 0x11, 0, 0,
                                                    0, 0);
                                                this->fillScenarios();
                                                this->scenariosLoaded = 1;
                                                this->getSettings();
                                                this->fillMissionText();
                                                this->activatePanels();
                                                this->set_curr_child(
                                                this->scenarioList);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
