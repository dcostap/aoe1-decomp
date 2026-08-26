// VA: 004A9CC0 TRIBE_Screen_Sed::set_scenario_mode | scr_sed.cpp:1150-1535
// __thiscall set_scenario_mode(ScenarioMode), ret 4
// Attempt log:
// 1: natural reconstruction from packet/Ghidra with real PDB field names; two-pass
//    do-while like the exact set_map_type donor; per-array set_active loops modeled
//    like the exact ~TRIBE_Screen_Sed (walking pointer pp + count); case source
//    order follows the binary's physical layout (1,2,3,4,6,7,9,10,5,8).
// 2: layout fixes: TScreenPanel needs its 0x384 pad (0xF4+0x384=0x478); classes with
//    virtuals place data at +4 (vptr); RGE_Diamond_Map_View::set_active is slot 5.
// 3: case-8 (Options) has the save branch INLINE (if(!active){save}else{load}); all
//    other cases have the active/load branch inline.
// 4: activate_victory_proper_fields is (int,int) per PDB mangling (IAEXHH), not (long,int).
// 5: BREAKTHROUGH: rge_base_game must be a declared extern global, not the absolute-
//    deref macro (*(RGE_Base_Game**)0x62C574). The macro form shifted case-4 register
//    allocation by +8 bytes (set_game_mode arg temp, master_obj_id condition, B032/B038
//    global loads) and cascaded; the extern form made size/frame/calls exact (diff 1581->122).
// 6: diplomacy loop uses pointer-walk ppv/ppf + i counter; lVar5 >= 0 (test/jl); i++ order
//    after ppv++.
// LEFT IN SCRATCH (diff 122 / 4.70%, size exact, calls 100%): the case-5 diplomacy loop
//    homes i to [esp+10h] in the original (ppv in ebx) but VC5 homes ppv to [esp+10h] and
//    keeps i in ebx in the rebuilt, adding ~2 instr/iteration. Tried: indexed vs pointer
//    forms, all declaration/increment orders, function-vs-case scope, register hints,
//    lVar5 long/int, p placement, compare spellings, full typed class surface (worse).
//    Also 3-byte set_curr_child arg-register difference at +036A (mov eax vs mov ecx).
// Next lead: case-5 loop register home is allocator-driven; try a variant-lab axis on the
//    loop-top access order (player_text first vs AlliedVictory first) or the p local's
//    live range across the je.
// Follow-up session: an explicit TPanel cast, child/parent locals, and a register-qualified
// child local did not move the set_curr_child hunk. A canonical TButtonPanel p local and a
// function-scope p likewise emitted the unchanged 122-byte form. The focused diplomacy lab
// confirmed that loading AlliedVictory before player_text makes the frame 0x10; declaring p
// before the text access is emitted-identical to the clean text-first form. A focused call
// lab (direct, paired locals, reference alias) also left the +036A register difference.
// Current pass: baseline remains 122 bytes / 4.6959% nonexact with exact size, frame,
// and 157-call parity. H2-H25 tested field types, cursor scopes, declaration order,
// comparison and increment spellings, branch shape, pointer casts, and register hints;
// all emitted the same 122-byte basin or worsened structure. An ambient 128-variant
// declaration sweep also produced one unchanged group. Keep the clean baseline pinned.
// H26: declaring and initializing the diplomacy cursors inside the guarded
// block, in friend-box then AlliedVictory order, emitted the same 122-byte
// result. Restore the pinned source after this probe.
// ACCEPTED DRIFT: the three-byte set_curr_child hunk only exchanges EAX and
// ECX while passing the same child to the same parent. The remaining drift is
// one diplomacy loop. The original keeps its panel cursor in EBX and homes i;
// the rebuild keeps i in EBX and homes the cursor. Both forms read the same
// entries, execute the same predicates, and call set_active on the same panel
// sequence. Pointer and index increments remain paired after each iteration.
// Size, 0xC frame, all 157 calls, branches, field effects, return, cleanup, and
// fault order match. This function has no SEH. Twenty-seven focused
// hypotheses and a 128-variant declaration sweep found no natural exact
// allocation form. Fresh validation remains 2598 bytes, 157 ordered calls,
// the PDB owner symbol, and a 122-byte positional mismatch at +036A.

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed::ScenarioMode param_1)
{
    int cur_mode;
    int mode = 0;
    int active = 0;
    TButtonPanel** ppv;
    TButtonPanel** ppf;
    int i;
    int activate_counter;

    this->valid_save_spot_flag = 0;
    do {
        if (mode == 0) {
            cur_mode = this->scenario_mode;
            active = 0;
        } else {
            if (param_1 != ScenarioModeSave) {
                cur_mode = param_1;
            }
            active = 1;
        }

        switch (cur_mode) {
        case ScenarioModeMap:
            this->map_type_label->set_active(active);
            {
                TButtonPanel** pp = (TButtonPanel**)this->map_type_text;
                int count = 3;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->generate_map_button->set_active(active);
            if (active) {
                this->set_map_type((MapType)this->map_type, 1);
            } else {
                this->set_map_type((MapType)ScenarioModeNone, 0);
            }
            break;

        case ScenarioModeTerrain:
            this->brush_size_label->set_active(active);
            this->paint_type_label->set_active(active);
            this->paint_terrain_label->set_active(active);
            {
                TPanel** pp = (TPanel**)this->brush_size_button_label;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            {
                TPanel** pp = (TPanel**)this->paint_type_button_label;
                int count = 3;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->set_brush_size(this->brush_size);
                this->set_paint_type((PaintType)this->paint_type, 1);
            } else {
                this->set_brush_size(BrushSizeNone);
                this->set_paint_type((PaintType)0, 0);
            }
            break;

        case ScenarioModePlayers:
            this->player_list->set_active(active);
            this->player_number_list->set_active(active);
            {
                TPanel** pp = (TPanel**)this->player_inven_input;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            {
                TPanel** pp = (TPanel**)this->player_setting_drop;
                int count = 2;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->player_advance_civilization_drop->setCurrentLineNumber(
                    this->world->scenario->GetPlayerAge(this->player_num - 1));
                this->set_player(this->player_num, 0, 1);
                this->bottom_panel->set_curr_child(0);
                this->map_view->set_active(0);
            } else {
                this->set_player(this->player_num, 1, 0);
                this->map_view->set_active(1);
                this->SavePlayerActiveStatus();
            }
            this->player_advance_civilization_drop->set_active(active);
            this->player_label->set_active(active);
            this->player_starting_age_label->set_active(active);
            this->player_build_text->set_active(active);
            this->player_city_text->set_active(active);
            this->AiRules_text->set_active(active);
            this->BuildList->set_active(active);
            this->CityLayout->set_active(active);
            this->AiRules->set_active(active);
            break;

        case ScenarioModeUnits:
            this->unit_player_list->set_active(active);
            this->unit_list->set_active(active);
            this->object_panel->set_active(active);
            this->unit_mode_select[0]->set_active(active);
            this->unit_mode_select[1]->set_active(active);
            this->unit_mode_select[2]->set_active(active);
            this->unit_mode_select[3]->set_active(active);
            if (active) {
                this->unit_mode_select[0]->set_radio_button();
            }
            this->unit_mode_select_label[0]->set_active(active);
            this->unit_mode_select_label[1]->set_active(active);
            this->unit_mode_select_label[2]->set_active(active);
            this->unit_mode_select_label[3]->set_active(active);
            {
                short s = this->player_num;
                if (active) {
                    this->set_unit_player(s);
                    this->set_unit((short)this->unit_list->currentLineNumber());
                    this->bottom_panel->set_curr_child(this->unit_list);
                    this->set_paint_object_mode();
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 4);
                    if (rge_base_game->master_obj_id != -1 && rge_base_game->get_player() != 0) {
                        s = rge_base_game->master_obj_id;
                        this->object_panel->set_master_info(
                            this->world->players[rge_base_game->get_player()->id]->master_objects[s],
                            (TRIBE_Player*)rge_base_game->get_player());
                    } else {
                        this->object_panel->set_master_info(0, 0);
                    }
                    this->object_panel->set_redraw(1);
                } else {
                    if (s < 1 || s > 8) {
                        this->player_num = 1;
                        this->set_player(1, 0, 0);
                    }
                    rge_base_game->set_game_mode(0, 0);
                    this->set_unit(-1);
                }
            }
            break;

        case ScenarioModeVictory:
            this->activate_victory_panel(active);
            if (active) {
                this->load_victory_cond_from_scenario(this->CurrentVictory);
                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), active);
            } else {
                this->save_victory_cond_in_scenario(this->CurrentVictory);
                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 0);
                this->SelectedObject = 0;
                this->DestinationObject = 0;
                rge_base_game->get_player()->unselect_object();
            }
            break;

        case ScenarioModeVictoryMulti:
            this->victory_condition_label->set_active(active);
            {
                TPanel** pp = (TPanel**)this->victory_cond_type;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->load_multi_victory_cond_from_scenario();
                this->map_view->set_active(0);
                this->set_mp_victory_type((VictoryType)this->mp_victory_type, 1);
            } else {
                this->save_multi_victory_cond_in_scenario();
                this->map_view->set_active(1);
                this->set_mp_victory_type((VictoryType)0, 0);
            }
            break;

        case ScenarioModeMessages:
            {
                TPanel** pp = (TPanel**)this->message_button_label;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->message_button[this->current_message]->set_radio_button();
            if (active) {
                char* text = this->world->scenario->Get_message(this->current_message);
                this->message_input->set_text(text);
                switch (this->current_message) {
                case 0:
                    this->message_input->set_help_info(0x7770, -1);
                    break;
                case 1:
                    this->message_input->set_help_info(0x7771, -1);
                    break;
                case 2:
                    this->message_input->set_help_info(0x7772, -1);
                    break;
                case 3:
                    this->message_input->set_help_info(0x7773, -1);
                    break;
                case 4:
                    this->message_input->set_help_info(0x7774, -1);
                    break;
                default:
                    break;
                }
                this->set_message_type((MessageType)this->message_type, 1);
                this->map_view->set_active(0);
                this->bottom_panel->set_curr_child(this->message_input);
            } else {
                this->world->scenario->Set_message(this->message_input->get_input_buffer(), this->current_message);
                this->set_message_type(MessageTypeNone, 0);
                this->map_view->set_active(1);
                this->save_info_in_scenario();
            }
            break;

        case ScenarioModeCinematics:
            {
                TDropDownPanel** pp = this->cinematic_input;
                activate_counter = 4;
                do {
                    pp[-4]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    activate_counter--;
                } while (activate_counter != 0);
            }
            if (active) {
                this->bottom_panel->set_curr_child(this->cinematic_input[0]);
                {
                    long line;
                    line = this->cinematic_input[0]->get_line(this->world->scenario->Get_Cine_PreGame());
                    this->cinematic_input[0]->setCurrentLineNumber(line);
                    line = this->cinematic_input[1]->get_line(this->world->scenario->Get_Cine_Victory());
                    this->cinematic_input[1]->setCurrentLineNumber(line);
                    line = this->cinematic_input[2]->get_line(this->world->scenario->Get_Cine_Loss());
                    this->cinematic_input[2]->setCurrentLineNumber(line);
                    line = this->cinematic_input[3]->get_line(this->world->scenario->Get_Mission_Bmp());
                    if (line == -1) {
                        this->cinematic_input[3]->append_line(this->world->scenario->Get_Mission_Bmp(), 0);
                        line = this->cinematic_input[3]->get_line(this->world->scenario->Get_Mission_Bmp());
                    }
                    this->cinematic_input[3]->setCurrentLineNumber(line);
                }
            } else {
                this->world->scenario->Set_Cine_PreGame(this->cinematic_input[0]->currentLine());
                this->world->scenario->Set_Cine_Victory(this->cinematic_input[1]->currentLine());
                this->world->scenario->Set_Cine_Loss(this->cinematic_input[2]->currentLine());
                this->world->scenario->Set_Mission_Bmp(this->cinematic_input[3]->currentLine());
            }
            break;

        case ScenarioModeDiplomacy:
            if (this->player_num < 1) {
                this->player_num = 1;
            }
            this->Diplomacy_player_list->set_active(active);
            {
                long lVar5;
                i = 0;
                lVar5 = this->player_number_list->get_line();
                if (lVar5 >= 0) {
                    ppf = &this->Diplomacy_friend_box[0][1];
                    ppv = this->Diplomacy_AlliedVictory;
                    do {
                        ppv[-0x25]->set_active(active);
                        {
                            TPanel* p = *ppv;
                            if (i != this->player_num - 1) {
                                p->set_active(0);
                                ppf[-1]->set_active(active);
                                (*ppf)->set_active(active);
                                p = ppf[1];
                            }
                            p->set_active(active);
                        }
                        ppv++;
                        i++;
                        ppf += 3;
                        lVar5 = this->player_number_list->get_line();
                    } while (i <= lVar5);
                }
            }
            this->Diplomacy_status_label[0]->set_active(active);
            this->Diplomacy_status_label[1]->set_active(active);
            this->Diplomacy_status_label[2]->set_active(active);
            this->Diplomacy_status_label[3]->set_active(active);
            if (active) {
                this->load_diplomacy_from_scenario(this->player_num - 1);
            } else {
                this->save_diplomacy_in_scenario(this->player_num - 1);
            }
            break;

        case ScenarioModeOptions:
            if (!active) {
                this->map_view->set_active(1);
                this->SaveDisabledItemsInScenario();
            } else {
                this->map_view->set_active(0);
                this->options_button[0]->set_state(this->world->scenario->GetScenarioOption(2));
                this->LoadDisabledItemsFromScenario();
                if (this->player_num != 0) {
                    this->options_player_list->setCurrentLineNumber(this->player_num - 1);
                } else {
                    this->options_player_list->setCurrentLineNumber(0);
                }
            }
            {
                TButtonPanel** pp = this->options_button;
                int count = 1;
                do {
                    pp[-1]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->options_player_list->set_active(active);
            if (active) {
                this->options_player_list->set_line(this->player_num - 1);
            } else {
                this->player_num = (short)(this->options_player_list->get_line() + 1);
            }
            this->options_disable_tech_text->set_active(active);
            {
                TPanel** pp = (TPanel**)this->options_disable_text;
                int count = 16;
                do {
                    pp[-16]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            break;
        }

        mode++;
    } while (mode < 2);

    if (param_1 != ScenarioModeSave) {
        this->scenario_mode = param_1;
        if (param_1 != ScenarioModeNone) {
            this->scenario_mode_button[param_1 - 1]->set_radio_button();
        }
        this->handle_size(this->pnl_wid, this->pnl_hgt);
        this->set_redraw(1);
    }
    this->valid_save_spot_flag = 1;
}
