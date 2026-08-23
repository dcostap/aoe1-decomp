// 004AB7D0 TRIBE_Screen_Sed::key_down_action
// scr_sed.cpp:2249-2503
//
// Reconstructed from the original switch structure and the named screen/panel
// ownership in the generated type reference.  In particular, the first switch
// is the modified-key scenario-mode hotkey switch; the second switch handles
// tab/cancel/delete and the numeric player selectors.
//
// Attempt log:
// - Replaced the prior placeholder modal/input and function-key model with the
//   binary-backed TPanelSystem modal guard and the two actual key switches.
// - Restored the __thiscall ABI (long, short, int, int, int), the screen field
//   ownership, and the exact TPanel/TButtonPanel virtual slots.
// - Kept scenario-mode cases in their source/PDB order (M,T,P,U,D,I,V,O,W,C,
//   with the grid-mode B case last) and numeric cases before tab/cancel/delete;
//   this reproduces the original jump-table handler placement.
// - Exact baseline: 1121 bytes, 45 ordered calls, 0-byte positional diff.

#include "../../include/scr_sed_context.h"

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2,
                                        int param_3, int param_4, int param_5)
{
    if (panel_system.modalPanel() == 0) {
        if (param_4 != 0) {
            switch (param_1) {
            case 0x41:
                if (rge_base_game->outline_type != 3) {
                    rge_base_game->outline_type = 3;
                    return 1;
                }
                rge_base_game->outline_type = 0;
                return 1;
            case 0x4D:
                this->scenario_mode_button[0]->set_state(1);
                this->set_scenario_mode(ScenarioModeMap);
                return 0;
            case 0x54:
                this->scenario_mode_button[1]->set_state(1);
                this->set_scenario_mode(ScenarioModeTerrain);
                return 0;
            case 0x50:
                this->scenario_mode_button[2]->set_state(1);
                this->set_scenario_mode(ScenarioModePlayers);
                return 0;
            case 0x55:
                this->scenario_mode_button[3]->set_state(1);
                this->set_scenario_mode(ScenarioModeUnits);
                return 0;
            case 0x44:
                this->scenario_mode_button[4]->set_state(1);
                this->set_scenario_mode(ScenarioModeDiplomacy);
                return 0;
            case 0x49:
                this->scenario_mode_button[5]->set_state(1);
                this->set_scenario_mode(ScenarioModeVictory);
                return 0;
            case 0x56:
                this->scenario_mode_button[6]->set_state(1);
                this->set_scenario_mode(ScenarioModeVictoryMulti);
                return 0;
            case 0x4F:
                this->scenario_mode_button[7]->set_state(1);
                this->set_scenario_mode(ScenarioModeOptions);
                return 0;
            case 0x57:
                this->scenario_mode_button[8]->set_state(1);
                this->set_scenario_mode(ScenarioModeMessages);
                return 0;
            case 0x43:
                this->scenario_mode_button[9]->set_state(1);
                this->set_scenario_mode(ScenarioModeCinematics);
                return 0;
            case 0x42:
                ++View_Grid_Mode;
                if (rge_base_game->gameDeveloperMode() != 0) {
                    if (View_Grid_Mode > 4) {
                        View_Grid_Mode = 0;
                    }
                } else if (View_Grid_Mode > 1) {
                    View_Grid_Mode = 0;
                }
                this->main_view->set_redraw(2);
                return 0;
            default:
                return 0;
            }
        }

        switch (param_1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
            {
                ScenarioMode mode = this->scenario_mode;
                int i = param_1 - 0x30;
                short selected = (short)i;

                if ((mode == ScenarioModeOptions) && (0 < i)) {
                    this->SaveDisabledItemsInScenario();
                    this->options_player_list->setCurrentLineNumber(i - 1);
                    this->action(this->options_player_list, 3, 0, 0);
                    this->set_player(selected, 0, 0);
                    this->player_num = selected;
                    this->LoadDisabledItemsFromScenario();
                    return 0;
                }

                if ((mode == ScenarioModePlayers) && (0 < i)) {
                    if (this->bottom_panel->curr_child == 0) {
                        this->player_list->setCurrentLineNumber(i - 1);
                        this->action(this->player_list, 0, 0, 0);
                        return 0;
                    }
                } else {
                    if (mode == ScenarioModeUnits) {
                        this->unit_player_list->setCurrentLineNumber(i);
                        this->action(this->unit_player_list, 0, 0, 0);
                        return 0;
                    }
                    if ((mode == ScenarioModeVictory) && (0 < i)) {
                        if (this->bottom_panel->curr_child == 0) {
                            this->victory_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->victory_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (mode == ScenarioModeDiplomacy) {
                        if (0 < i) {
                            this->Diplomacy_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->Diplomacy_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (0 < i) {
                        this->set_player(selected, 0, 0);
                        this->player_num = selected;
                        return 0;
                    }
                }
            }
            break;
        case 9:
            if (this->scenario_mode == ScenarioModePlayers) {
                if (this->bottom_panel->curr_child == 0) {
                    this->bottom_panel->set_curr_child(this->player_inven_input[0]);
                    return 0;
                }
            } else if ((this->scenario_mode == ScenarioModeVictory) &&
                       (this->bottom_panel->curr_child == 0) &&
                       (this->victory_amount_input->field_6C != 0)) {
                this->bottom_panel->set_curr_child(this->victory_amount_input);
                return 0;
            }
            break;
        case 0x1B:
            this->command_cancel();
            return 0;
        case 0x2E:
            if (this->scenario_mode == ScenarioModeUnits) {
                RGE_Player* player = rge_base_game->get_player();
                RGE_Static_Object* object = player->selected_obj;
                if (object != 0) {
                    uchar draw_level;
                    if (object->sprite_list != 0) {
                        draw_level = object->sprite_list->get_lowest_draw_level();
                    } else if (object->sprite != 0) {
                        draw_level = object->sprite->get_lowest_draw_level();
                    } else {
                        draw_level = 0x14;
                    }
                    object->set_selected(1);
                    if (draw_level == 0) {
                        this->main_view->set_redraw(2);
                    }
                }
                return 1;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
