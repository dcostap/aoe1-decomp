// VA: 004ABCD0 TRIBE_Screen_Sed::action | scr_sed.cpp:2509-3233
// First pass: cleaned Ghidra heuristic decompilation.  The goal of this pass is
// to get a large behavior-shaped source body compiling; exact matching has not
// yet been attempted.
// Attempt log:
// [1] Copied/restructured the Ghidra action body into local typed stubs with the
//     proven TRIBE_Screen_Sed field layout. VC5 compiles and writes an object.
//     check_function could not compare because rebuilt .text was shorter than
//     the original configured 5022-byte body.
// [2] Expanded duplicated map-clear switch, hardcoded/inlined dialog-name string
//     compares, and inlined game/player helper macros. check_function now
//     compares full size; current result is MISMATCH, first mismatch at +0x25
//     from null-param early-return block layout (original jumps to shared early
//     epilogue; current source emits an inline epilogue).
// [3] Added the typed TPanel virtual destructor. This moves activation/redraw
//     calls to the binary-backed +0x14/+0x20 slots and improves call alignment;
//     the remaining first mismatch is the shared early-return epilogue.
// [4] Tried moving the shared result label after the action body. That worsened
//     the first block and was rolled back; the TPanel-destructor candidate stays.
// [5] Direct return and outer non-null guard probes did not reproduce the
//     original null-path epilogue; the direct-return body remains the clean form.
// [6] Modeled InvalidateRect as its proven IAT pointer and new_random_map as the
//     world virtual at +0x28; both restore binary-backed call identities.
// [7] Removed cached GAME_PLAYER results in the two unit branches. The original
//     reloads the player for the master and tribe arguments; call-count parity
//     improved by two.
// [8] Restored the full TPanel virtual surface, TTextPanel E8 text dispatch,
//     and the direct TEditPanel/TPanel ownership. Modeled the victory-button
//     +0xE0 call as a local virtual slot.
// [9] Kept map-center arithmetic as an integer before the float view calls;
//     this removes the rebuilt-only center ftol and is the current best.
// [10-23] Binary checks confirmed the unit redraw status values, the
// world-player master lookup, the distinct object-panel redraw flags, and
// natural repeated panelName/strcmp lowering. Independent help predicates
// restore call count but add an unsupported 190-byte control-flow expansion.
// The PDB-order switch restores the original call order without helper scaffolding.
// Remaining structural gap: VC5 merges the five TPanel::set_help_info arms.
// [24-47] PDB line order shows the scenario-mode source order as Messages,
// Victory, Map, Terrain, Players, Units, VictoryMulti, Diplomacy, Options.
// This order gives 200/200 ordered calls, 88.73% shape, and 70.07% exact blocks.
// It adds 146 bytes of code or padding, so exact size and tail layout remain open.
// [48-50] The x/y declaration order is codegen-neutral.  Original pushes prove
// redraw(0x10,0) in both victory object-selection arms; this gives 70.07% blocks.
// FLAGS: /nologo /c /O2 /Oy /GX

#include "../../include/scr_sed_context.h"

#define GAME_REDRAW0() (((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0, 0))
#define GAME_PLAYER() (rge_base_game->get_player())
#define SELECT_IF_PRESENT(obj_) do { \
    RGE_Static_Object* selected_object = (obj_); \
    if (selected_object != 0) GAME_PLAYER()->select_one_object(selected_object, 0); \
} while (0)

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    int i;
    int map_size;
    int center;
    long line;
    long x2;
    long x1;
    long y1;
    long y2;
    char random_val[28];
    float f1;
    float f2;
    RGE_Player* player;
    char* panel_name;
    unsigned char* scan;
    unsigned char* lit;
    unsigned char ch;
    int cmp_value;

    if (param_1 == 0) {
        return 0;
    }

    if (param_1 != (TPanel*)this->main_view) {
        SELECT_IF_PRESENT(this->SelectedObject);
        SELECT_IF_PRESENT(this->DestinationObject);
    }

    if (param_2 == 0) {
        if (param_1 == (TPanel*)this->random_seed_input ||
            param_1 == (TPanel*)this->player_inven_input[0] ||
            param_1 == (TPanel*)this->player_inven_input[1] ||
            param_1 == (TPanel*)this->player_inven_input[2] ||
            param_1 == (TPanel*)this->player_inven_input[3] ||
            param_1 == (TPanel*)this->player_inven_input[4] ||
            param_1 == (TPanel*)this->player_setting_label[0] ||
            param_1 == (TPanel*)this->victory_condition_explore ||
            param_1 == (TPanel*)this->victory_condition_ruins ||
            param_1 == (TPanel*)this->victory_condition_artifacts ||
            param_1 == (TPanel*)this->victory_condition_discoveries ||
            param_1 == (TPanel*)this->victory_condition_gold ||
            param_1 == (TPanel*)this->victory_amount_input ||
            param_1 == (TPanel*)this->message_input) {
            this->need_to_save_flag = 1;
        }
    }

    if (param_1 == (TPanel*)this->main_view) {
        if (param_2 == 0x10) {
            GAME_PLAYER()->unselect_object();
            if (this->SelectRegionFlag == SELECT_OBJECT) this->SelectedObject = (RGE_Static_Object*)param_3;
            if (this->SelectRegionFlag == SELECT_DEST_OBJECT) this->DestinationObject = (RGE_Static_Object*)param_3;
            SELECT_IF_PRESENT(this->SelectedObject);
            SELECT_IF_PRESENT(this->DestinationObject);
            GAME_REDRAW0();
            return 1;
        }
        if (param_2 == 0x11 && rge_base_game->game_mode == 0x11) {
            GAME_REDRAW0();
        }
    }

    if (param_2 == 1) {
        for (i = 0; i < 10; i++) {
            if (param_1 == this->scenario_mode_button[i]) {
                this->set_scenario_mode((ScenarioMode)(i + ScenarioModeMap));
                return 1;
            }
        }
        if (param_1 == this->menu_button) {
            this->command_menu();
            return 1;
        }
        if (param_1 == this->help_button) {
            this->setup_popup_help();
            return 1;
        }
    } else {
        for (i = 0; i < 10; i++) {
            if (param_1 == this->scenario_mode_button[i]) return 1;
        }
        if (param_1 == this->menu_button || param_1 == this->help_button) return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_OKDialog) == 0) {
            if (param_2 == 0) {
                panel_system.destroyPanel(s_OKDialog);
                this->set_scenario_mode(ScenarioModePlayers);
            }
            return 1;
    }

    switch (this->scenario_mode) {
    case ScenarioModeMessages:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            line = this->current_message;
            this->world->scenario->Set_message(this->message_input->get_input_buffer(), line);
            for (i = 0; i < 5; i++) if (param_1 == this->message_button[i]) { this->current_message = i; break; }
            this->message_input->set_text(this->world->scenario->Get_message(this->current_message));
            switch (this->current_message) {
            case 0: ((TPanel*)this->message_input)->set_help_info(0x7770, -1); break;
            case 1: ((TPanel*)this->message_input)->set_help_info(0x7771, -1); break;
            case 2: ((TPanel*)this->message_input)->set_help_info(0x7772, -1); break;
            case 3: ((TPanel*)this->message_input)->set_help_info(0x7773, -1); break;
            case 4: ((TPanel*)this->message_input)->set_help_info(0x7774, -1); break;
            }
        }
        break;

    case ScenarioModeVictory:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if ((param_2 == 0 || param_2 == 1) && param_1 == this->victory_player_list) {
            this->save_victory_cond_in_scenario(this->CurrentVictory);
            this->activate_victory_panel(0);
            this->activate_victory_proper_fields(0, 0);
            line = this->victory_player_list->get_line();
            this->player_num = (short)line + 1;
            this->world->scenario->SetSPWhich(this->player_num - 1);
            this->CurrentVictory = 0;
            this->load_victory_cond_from_scenario(0);
            this->activate_victory_panel(1);
            line = this->victory_drop_down->get_line();
            this->activate_victory_proper_fields(line, 1);
        }
        if (param_2 == 0 && param_1 == this->victory_amount_input) this->bottom_panel->set_curr_child(0);
        if (param_2 == 2 && param_1 == this->victory_drop_down) { line = this->victory_drop_down->get_line(); this->activate_victory_proper_fields(line, 1); }
        if (param_2 == 1) {
            if (param_1 != this->victory_amount_input) {
                line = this->victory_drop_down->get_line();
                if (param_1 == this->victory_drop_down) { GAME_REDRAW0(); this->DestinationObject = 0; this->SelectedObject = 0; GAME_PLAYER()->unselect_object(); }
                if (line == 2) { this->DestinationObject = 0; GAME_PLAYER()->unselect_object(); }
                // BINARY NOTE: both object-selection arms use redraw mode 0x10.
                if (param_1 == this->victory_button_set_object) { this->SelectRegionFlag = SELECT_OBJECT; ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0x10, 0); GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->DestinationObject); }
                else if (param_1 == this->victory_button_set_destination && line != 1) { this->SelectRegionFlag = SELECT_AREA; GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->SelectedObject); GAME_REDRAW0(); return 1; }
                else if (param_1 == this->victory_button_set_destination) { this->SelectRegionFlag = SELECT_DEST_OBJECT; ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0x10, 0); GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->SelectedObject); }
                else if (param_1 == this->victory_button_go_to_dest && line != 1) {
                    this->main_view->get_selection_area(&y1, &y2, &x1, (long*)random_val, 1);
                    f1 = (float)x1;
                    f2 = (float)*(long*)random_val;
                    this->px1 = (float)y1;
                    this->py1 = (float)y2;
                    this->SelectRegionFlag = SELECT_OFF;
                    this->px2 = f1;
                    this->py2 = f2;
                    if (f1 != -1.0f) {
                        f1 = f1 - (f1 - (float)y1) * 0.5f;
                        f2 = f2 - (f2 - (float)y2) * 0.5f;
                        player = GAME_PLAYER();
                        player->set_view_loc(f1, f2);
                        GAME_PLAYER()->set_map_loc((short)f1, (short)f2);
                    }
                } else {
                    if (param_1 == this->victory_drop_down) { line = this->victory_drop_down->get_line(); this->activate_victory_proper_fields(line, 0); }
                    for (i = 0; i < 12; i++) {
                        if (param_1 == this->victory_button[i] && this->CurrentVictory != i) {
                            line = this->victory_drop_down->get_line();
                            this->activate_victory_proper_fields(line, 0);
                            this->save_victory_cond_in_scenario(this->CurrentVictory);
                            this->activate_victory_panel(0);
                            GAME_PLAYER()->unselect_object();
                            this->CurrentVictory = i;
                            this->load_victory_cond_from_scenario(i);
                            this->activate_victory_panel(1);
                            line = this->victory_drop_down->get_line();
                            this->activate_victory_proper_fields(line, 1);
                            SELECT_IF_PRESENT(this->SelectedObject);
                            SELECT_IF_PRESENT(this->DestinationObject);
                        }
                    }
                }
            }
            return 1;
        }
        break;

    case ScenarioModeMap:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 3; i++) {
                if (param_1 == this->map_type_button[i]) {
                    this->set_map_type((MapType)(i + MapTypeBlank), 1);
                    return 1;
                }
            }
            if (param_1 == this->generate_map_button) {
                this->map_generating_text->set_active(1);
                this->set_redraw(2);
                InvalidateRect(rge_base_game->prog_window, 0, 0);
                rge_base_game->draw_window();
                i = this->map_size_drop->currentLineNumber();
                f1 = (float)this->map_style_drop->currentLineNumber();
                switch (i) {
                case 0: map_size = 0x48; break;
                case 1: map_size = 0x60; break;
                case 2: map_size = 0x78; break;
                case 3: map_size = 0x90; break;
                case 4: map_size = 0xC8; break;
                case 5: map_size = 0xFA; break;
                default: map_size = i; break;
                }
                line = this->player_number_list->get_line();
                if (this->map_type == MapTypeBlank) {
                    switch (this->default_terrain_drop->currentLineNumber()) {
                    case 0:
                        this->world->map->clear_map(this->world->players[0], this->world, 0, map_size, map_size);
                        break;
                    case 1:
                        this->world->map->clear_map(this->world->players[0], this->world, 6, map_size, map_size);
                        break;
                    case 2:
                        this->world->map->clear_map(this->world->players[0], this->world, 10, map_size, map_size);
                        break;
                    case 3:
                        this->world->map->clear_map(this->world->players[0], this->world, 1, map_size, map_size);
                        break;
                    case 4:
                        this->world->map->clear_map(this->world->players[0], this->world, 13, map_size, map_size);
                        break;
                    case 5:
                        this->world->map->clear_map(this->world->players[0], this->world, 20, map_size, map_size);
                        break;
                    case 6:
                        this->world->map->clear_map(this->world->players[0], this->world, 4, map_size, map_size);
                        break;
                    case 7:
                        this->world->map->clear_map(this->world->players[0], this->world, 19, map_size, map_size);
                        break;
                    case 8:
                        this->world->map->clear_map(this->world->players[0], this->world, 22, map_size, map_size);
                        break;
                    }
                } else {
                    if (this->map_type == MapTypeSeed) {
                        rge_base_game->random_map_seed = atoi(this->random_seed_input->currentLine());
                    } else {
                        rge_base_game->random_map_seed = -1;
                    }
                    for (i = 0; i < 9; i++) this->world->players[i]->reset_selected();
                    this->world->new_random_map((float)map_size, (float)map_size, f1, line + 1);
                    rge_base_game->random_map_seed = *(int*)(random_val + 4);
                    itoa(rge_base_game->save_random_map_seed, random_val, 10);
                    this->random_seed_used_text->set_text(random_val);
                    debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp, 0xB58);
                }
                center = map_size / 2;
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->set_map_loc((short)center, (short)center);
                    this->world->players[i]->set_view_loc((float)center, (float)center);
                }
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->tile_list.del_list();
                    this->world->players[i]->set_map_visible();
                }
                this->set_panel_info();
                this->map_generating_text->set_active(0);
                return 1;
            }
        }
        break;

    case ScenarioModeTerrain:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->paint_terrain_list) {
                i = ((TTextPanel*)this->paint_terrain_list)->currentLineNumber();
                this->set_terrain((short)i);
                this->brush_size_button[0]->set_active(1);
                return 1;
            } else if (param_1 == this->paint_elevation_list) {
                i = ((TTextPanel*)this->paint_elevation_list)->currentLineNumber();
                this->set_elevation((short)i);
                return 1;
            } else if (param_2 == 1) {
                if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
                for (i = 0; i < 5; i++) {
                    if (param_1 == this->brush_size_button[i]) { this->set_brush_size(i + BrushSizeVerySmall); return 1; }
                }
                for (i = 0; i < 3; i++) {
                    if (param_1 == this->paint_type_button[i]) { this->set_paint_type((PaintType)(i + PaintTypeTerrain), 1); return 1; }
                }
            }
        }
        break;

    case ScenarioModePlayers:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0) {
            for (i = 0; i < 5; i++) if (param_1 == this->player_inven_input[i]) { this->bottom_panel->set_curr_child(0); break; }
            if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
            if (param_1 == this->player_advance_civilization_drop) {
                if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
                i = this->player_advance_civilization_drop->currentLineNumber();
                this->world->scenario->SetPlayerAge(this->player_num - 1, i);
            }
            if (param_1 == this->player_list) {
                line = this->player_list->get_line();
                this->set_player((short)line + 1, 1, 1);
                line = this->player_list->get_line();
                i = this->world->scenario->GetPlayerAge(line);
                this->player_advance_civilization_drop->setCurrentLineNumber(i);
            }
            if (param_1 == this->player_number_list) {
                this->set_player(this->player_num, 1, 0);
                this->SavePlayerActiveStatus();
                this->set_player(this->player_num, 0, 1);
            }
        }
        if (param_2 == 1 && param_1 == this->player_advance_civilization_drop) {
            i = this->player_advance_civilization_drop->currentLineNumber();
            this->world->scenario->SetPlayerAge(this->player_num - 1, i);
        }
        break;

    case ScenarioModeUnits:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0) {
            if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
            if (param_1 == this->unit_player_list) {
                line = this->unit_player_list->get_line();
                this->set_unit_player((short)line);
                line = this->unit_player_list->get_line();
                if (line == 0) {
                    // BINARY NOTE: the shipped path redraws with status 3.
                    ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(rge_base_game->game_mode, 3);
                } else {
                    // BINARY NOTE: status 4 precedes master-panel setup.
                    ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(rge_base_game->game_mode, 4);
                    // BINARY NOTE: master ownership is world->players[id].
                    RGE_Master_Static_Object* player_master;
                    TRIBE_Player* player_tribe;
                    short master_id = rge_base_game->master_obj_id;
                    if (rge_base_game->master_obj_id == -1 || GAME_PLAYER() == 0) {
                        player_tribe = 0;
                        player_master = 0;
                    } else {
                        player_master = this->world->players[GAME_PLAYER()->id]->master_objects[master_id];
                        player_tribe = (TRIBE_Player*)GAME_PLAYER();
                    }
                    this->object_panel->set_master_info(player_master, player_tribe);
                    this->set_paint_object_mode();
                this->object_panel->set_redraw(2);
                    return 1;
                }
            }
        }
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->unit_list) {
                RGE_Master_Static_Object* list_master;
                TRIBE_Player* list_tribe;
                i = ((TTextPanel*)this->unit_list)->currentLineNumber();
                this->set_unit((short)i);
                if (rge_base_game->game_mode != 8 && rge_base_game->game_mode != 0x15) this->unit_mode_select[0]->set_radio_button();
                if (rge_base_game->master_obj_id == -1 || GAME_PLAYER() == 0) { list_tribe = 0; list_master = 0; }
                else {
                    short master_id = rge_base_game->master_obj_id;
                    list_master = this->world->players[GAME_PLAYER()->id]->master_objects[master_id];
                    list_tribe = (TRIBE_Player*)GAME_PLAYER();
                }
                this->object_panel->set_master_info(list_master, list_tribe);
                this->set_paint_object_mode();
                // BINARY NOTE: the list path redraws with flag 1, not 2.
                this->object_panel->set_redraw(1);
                return 1;
            }
            if (param_2 == 1) {
                if (param_1 == this->unit_mode_select[0]) this->set_paint_object_mode();
                else if (param_1 == this->unit_mode_select[1]) { GAME_PLAYER()->unselect_object(); ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0xE, 0); }
                else if (param_1 == this->unit_mode_select[2]) ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0xF, 0);
                else if (param_1 == this->unit_mode_select[3]) ((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0x14, 0);
            }
        }
        break;

    case ScenarioModeVictoryMulti:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 5; i++) {
                if (param_1 == this->victory_cond_type[i]) {
                    this->set_mp_victory_type((VictoryType)(i + VictoryTypeStandard), 1);
                    if (i != 4) { this->world->scenario->Set_Multi_Conquest(1); this->victory_cond_on[0]->set_state(1); }
                    return 1;
                }
            }
        }
        break;

    case ScenarioModeDiplomacy:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0 || param_2 == 1) {
            if (param_1 == this->Diplomacy_player_list) {
                this->Diplomacy_friend_box[this->player_num - 1][0]->set_active(1);
                this->Diplomacy_friend_box[this->player_num - 1][1]->set_active(1);
                this->Diplomacy_friend_box[this->player_num - 1][2]->set_active(1);
                this->Diplomacy_AlliedVictory[this->player_num - 1]->set_active(0);
                line = this->Diplomacy_player_list->get_line();
                this->player_num = (short)line + 1;
                this->Diplomacy_friend_box[this->player_num - 1][0]->set_active(0);
                this->Diplomacy_friend_box[this->player_num - 1][1]->set_active(0);
                this->Diplomacy_friend_box[this->player_num - 1][2]->set_active(0);
                this->Diplomacy_AlliedVictory[this->player_num - 1]->set_active(1);
                line = this->Diplomacy_player_list->get_line();
                this->load_diplomacy_from_scenario(line);
            }
            if (param_2 == 1) { this->save_diplomacy_in_scenario(this->player_num - 1); return 1; }
        }
        break;

    case ScenarioModeOptions:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            this->SaveDisabledItemsInScenario();
            this->LoadDisabledItemsFromScenario();
            if (param_1 == this->options_button[0]) {
                i = this->options_button[0]->get_state();
                this->world->scenario->SetScenarioOption(2, i);
            }
        }
        break;

    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_QuitSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_QuitSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 1);
            else if (param_2 == 1) {
                if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) rge_base_game->close();
                else panel_system.destroyPanel(s_Scenario_Editor_Screen);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_OpenSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_OpenSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 2);
            else if (param_2 == 1) {
                TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open;
                (void)open;
                panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_NewSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_NewSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 3);
            else if (param_2 == 1) ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
            return 1;
    }

    return 0;
}
