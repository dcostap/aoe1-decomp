// Class: TRIBE_Screen_Sed
// Size:  0x948
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] setup
// [02] set_rect
// [03] set_rect
// [04] set_color
// [05] set_active
// [06] set_positioning
// [07] set_fixed_position
// [08] set_redraw
// [09] set_overlapped_redraw
// [10] draw_setup
// [11] draw_finish
// [12] draw
// [13] draw_rect
// [14] draw_offset
// [15] draw_rect2
// [16] draw_offset2
// [17] paint
// [18] wnd_proc
// [19] handle_idle
// [20] handle_size
// [21] handle_paint
// [22] handle_key_down
// [23] handle_char
// [24] handle_command
// [25] handle_user_command
// [26] handle_timer_command
// [27] handle_scroll
// [28] handle_mouse_down
// [29] handle_mouse_move
// [30] handle_mouse_up
// [31] handle_mouse_dbl_click
// [32] mouse_move_action
// [33] mouse_left_down_action
// [34] mouse_left_hold_action
// [35] mouse_left_move_action
// [36] mouse_left_up_action
// [37] mouse_left_dbl_click_action
// [38] mouse_right_down_action
// [39] mouse_right_hold_action
// [40] mouse_right_move_action
// [41] mouse_right_up_action
// [42] mouse_right_dbl_click_action
// [43] key_down_action
// [44] char_action
// [45] action
// [46] get_true_render_rect
// [47] is_inside
// [48] set_focus
// [49] set_tab_order
// [50] set_tab_order
// [51] get_help_info
// [52] stop_sound_system
// [53] restart_sound_system
// [54] take_snapshot
// [55] handle_reactivate
// [56] draw_background
// [57] set_ideal_size
// [58] create_button
// [59] create_button
// [60] create_check_box
// [61] create_radio_button
// [62] create_text
// [63] create_text
// [64] create_text
// [65] create_input
// [66] create_edit
// [67] create_drop_down
// [68] create_list
// [69] create_scrollbar
// [70] create_auto_scrollbar
// [71] create_vert_slider
// [72] create_horz_slider
// [73] position_panel
//
// Member Layout:
// [0x478] int is_multi_player
// [0x47C] int set_player_first_flag
// [0x480] RGE_Static_Object * SelectedObject
// [0x484] RGE_Static_Object * DestinationObject
// [0x488] float px1
// [0x48C] float py1
// [0x490] float px2
// [0x494] float py2
// [0x498] int CurrentVictory
// [0x49C] int CurrentPlayer
// [0x4A0] SELECT_REGION_e SelectRegionFlag
// [0x4A4] ScenarioMode scenario_mode
// [0x4A8] MapType map_type
// [0x4AC] VictoryType mp_victory_type
// [0x4B0] BrushSize brush_size
// [0x4B4] PaintType paint_type
// [0x4B8] short player_num
// [0x4BC] MessageType message_type
// [0x4C0] uchar need_to_save_flag
// [0x4C1] uchar valid_save_spot_flag
// [0x4C4] TShape * background_pic
// [0x4C8] TRIBE_Main_View * main_view
// [0x4CC] RGE_Diamond_Map_View * map_view
// [0x4D0] TMessagePanel * message_panel
// [0x4D4] TPanel * bottom_panel
// [0x4D8] TButtonPanel *[10] scenario_mode_button (sz: 0x28)
// [0x500] TButtonPanel * menu_button
// [0x504] TButtonPanel * help_button
// [0x508] TButtonPanel *[3] map_type_button (sz: 0xC)
// [0x514] TTextPanel *[3] map_type_text (sz: 0xC)
// [0x520] TTextPanel * map_type_label
// [0x524] TTextPanel * default_terrain_label
// [0x528] TDropDownPanel * default_terrain_drop
// [0x52C] TTextPanel * map_size_label
// [0x530] TDropDownPanel * map_size_drop
// [0x534] TTextPanel * map_style_label
// [0x538] TDropDownPanel * map_style_drop
// [0x53C] TTextPanel * random_seed_label
// [0x540] TEditPanel * random_seed_input
// [0x544] TTextPanel * random_seed_used_label
// [0x548] TTextPanel * random_seed_used_text
// [0x54C] TButtonPanel * generate_map_button
// [0x550] TTextPanel * map_generating_text
// [0x554] TTextPanel * brush_size_label
// [0x558] TButtonPanel *[5] brush_size_button (sz: 0x14)
// [0x56C] TTextPanel *[5] brush_size_button_label (sz: 0x14)
// [0x580] TTextPanel * paint_type_label
// [0x584] TButtonPanel *[3] paint_type_button (sz: 0xC)
// [0x590] TTextPanel *[3] paint_type_button_label (sz: 0xC)
// [0x59C] TTextPanel * paint_terrain_label
// [0x5A0] TListPanel * paint_terrain_list
// [0x5A4] TScrollBarPanel * paint_terrain_scrollbar
// [0x5A8] TListPanel * paint_elevation_list
// [0x5AC] TScrollBarPanel * paint_elevation_scrollbar
// [0x5B0] TTextPanel * player_label
// [0x5B4] TDropDownPanel * player_list
// [0x5B8] TDropDownPanel * player_number_list
// [0x5BC] TDropDownPanel * player_advance_civilization_drop
// [0x5C0] TButtonPanel * player_advance_civilization_button
// [0x5C4] TTextPanel *[5] player_inven_label (sz: 0x14)
// [0x5D8] TEditPanel *[5] player_inven_input (sz: 0x14)
// [0x5EC] TTextPanel *[2] player_setting_label (sz: 0x8)
// [0x5F4] TTextPanel * player_starting_age_label
// [0x5F8] TDropDownPanel *[2] player_setting_drop (sz: 0x8)
// [0x600] TDropDownPanel * BuildList
// [0x604] TDropDownPanel * CityLayout
// [0x608] TDropDownPanel * AiRules
// [0x60C] TTextPanel * player_build_text
// [0x610] TTextPanel * player_city_text
// [0x614] TTextPanel * AiRules_text
// [0x618] TDropDownPanel * unit_player_list
// [0x61C] TButtonPanel *[4] unit_mode_select (sz: 0x10)
// [0x62C] TTextPanel *[4] unit_mode_select_label (sz: 0x10)
// [0x63C] TListPanel * unit_list
// [0x640] TScrollBarPanel * unit_scrollbar
// [0x644] List_Info * unit_list_info
// [0x648] TShape * button_unit_pics
// [0x64C] TShape *[5] button_bldg_pics (sz: 0x14)
// [0x660] TRIBE_Scenario_Editor_Panel_Object * object_panel
// [0x664] short unit_list_size
// [0x668] TButtonPanel *[6] victory_cond_on (sz: 0x18)
// [0x680] TButtonPanel *[2] victory_and_or (sz: 0x8)
// [0x688] TTextPanel * victory_condition_label
// [0x68C] TTextPanel * victory_amount_label
// [0x690] TTextPanel * victory_long_label
// [0x694] TTextPanel *[2] victory_text_and_or (sz: 0x8)
// [0x69C] TTextPanel * victory_label_conquest
// [0x6A0] TTextPanel * victory_label_explore
// [0x6A4] TTextPanel * victory_label_explore_percent
// [0x6A8] TTextPanel * victory_label_ruins
// [0x6AC] TTextPanel * victory_label_artifacts
// [0x6B0] TTextPanel * victory_label_discoveries
// [0x6B4] TTextPanel * victory_label_gold
// [0x6B8] TEditPanel * victory_condition_explore
// [0x6BC] TEditPanel * victory_condition_ruins
// [0x6C0] TEditPanel * victory_condition_artifacts
// [0x6C4] TEditPanel * victory_condition_discoveries
// [0x6C8] TEditPanel * victory_condition_gold
// [0x6CC] TTextPanel *[5] victory_cond_type_label (sz: 0x14)
// [0x6E0] TButtonPanel *[5] victory_cond_type (sz: 0x14)
// [0x6F4] TTextPanel * victory_score_label
// [0x6F8] TDropDownPanel * victory_score
// [0x6FC] TTextPanel * victory_time_label
// [0x700] TDropDownPanel * victory_time
// [0x704] TButtonPanel *[12] victory_button (sz: 0x30)
// [0x734] TDropDownPanel * victory_drop_down
// [0x738] TDropDownPanel * victory_object_list
// [0x73C] TDropDownPanel * victory_player_list
// [0x740] TDropDownPanel * victory_enemy_player_list
// [0x744] TDropDownPanel * victory_attribute_list
// [0x748] TDropDownPanel * victory_ages_list
// [0x74C] TDropDownPanel * victory_tech_list
// [0x750] TButtonPanel * victory_button_set_object
// [0x754] TButtonPanel * victory_button_set_destination
// [0x758] TButtonPanel * victory_button_go_to_dest
// [0x75C] TTextPanel * victory_condition_text
// [0x760] TTextPanel * victory_condition_type
// [0x764] TTextPanel * victory_amount_text
// [0x768] TTextPanel * victory_which_enemy_text
// [0x76C] TEditPanel * victory_amount_input
// [0x770] TScrollBarPanel * victory_object_scrollbar
// [0x774] TEditPanel * message_input
// [0x778] TButtonPanel *[5] message_button (sz: 0x14)
// [0x78C] TTextPanel *[5] message_button_label (sz: 0x14)
// [0x7A0] long current_message
// [0x7A4] TTextPanel *[4] cinematic_label (sz: 0x10)
// [0x7B4] TDropDownPanel *[4] cinematic_input (sz: 0x10)
// [0x7C4] TTextPanel *[1] options_label
// [0x7C8] TButtonPanel *[1] options_button
// [0x7CC] TDropDownPanel * options_player_list
// [0x7D0] TTextPanel * options_disable_tech_text
// [0x7D4] TButtonPanel *[16] options_disable_button (sz: 0x40)
// [0x814] TTextPanel *[16] options_disable_text (sz: 0x40)
// [0x854] TTextPanel *[8] Diplomacy_opponent_label (sz: 0x20)
// [0x874] TTextPanel *[8] Diplomacy_player_text (sz: 0x20)
// [0x894] TDropDownPanel * Diplomacy_player_list
// [0x898] TTextPanel *[4] Diplomacy_status_label (sz: 0x10)
// [0x8A8] TButtonPanel *[8][3] Diplomacy_friend_box (sz: 0x60)
// [0x908] TButtonPanel *[8] Diplomacy_AlliedVictory (sz: 0x20)
// [0x928] TRIBE_World * world
// [0x92C] ulong update_interval
// [0x930] ulong last_update_time
// [0x934] ulong map_redraw_interval
// [0x938] ulong last_map_redraw_time
// [0x93C] int changed_system_colors
// [0x940] ulong save_text_color
// [0x944] ulong save_window_color
// ----------------------------------------------------------------

// Function: TRIBE_Screen_Sed
// Address: 004a81e0
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s__SCN: ".SCN"
// [HELPER] s__s_scx: "%s.scx"
// [HELPER] s__scn: ".scn"
// [HELPER] s_bordline: "bordline"
// [HELPER] s_default_d_scx: "default%d.scx"
// [HELPER] s_map640_bmp: "map640.bmp"
// [HELPER] s_scr5: "scr5"
TRIBE_Screen_Sed * __thiscall
TRIBE_Screen_Sed::TRIBE_Screen_Sed(TRIBE_Screen_Sed *this,char *param_1,int param_2)
{
  ulong uVar1;
  int iVar2;
  byte *pbVar3;
  long lVar4;
  RGE_Main_View *this_00;
  RGE_Diamond_Map_View *this_01;
  RGE_Diamond_Map *this_02;
  RGE_Font *pRVar5;
  TMessagePanel *pTVar6;
  TPanel *pTVar7;
  int iVar8;
  byte bVar9;
  byte *pbVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  byte *unaff_retaddr;
  char name [260];
  char temp_name [260];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f453;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  name._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Scenario_Editor_Screen);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->is_multi_player = 0;
  this->scenario_mode = ScenarioModeNone;
  this->map_type = MapTypeNone;
  this->mp_victory_type = VictoryTypeConquest;
  this->brush_size = BrushSizeNone;
  this->paint_type = PaintTypeNone;
  this->player_num = 1;
  this->message_type = MessageTypeNone;
  this->SelectedObject = (RGE_Static_Object *)0x0;
  this->DestinationObject = (RGE_Static_Object *)0x0;
  this->CurrentPlayer = 0;
  this->need_to_save_flag = '\0';
  this->valid_save_spot_flag = '\0';
  init_module_variables(this);
  this->update_interval = 200;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x117);
  this->last_update_time = uVar1;
  this->map_redraw_interval = 1000;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x11a);
  this->last_map_redraw_time = uVar1;
  this->save_text_color = 0;
  this->save_window_color = 0;
  this->changed_system_colors = 0;
  this->CurrentVictory = 0;
  (**(code **)(rge_base_game->_padding_ + 0xc))(7);
  iVar2 = command_new_map(this,(char *)unaff_retaddr,(int)param_1,0,0x90,0x90,1);
  if (iVar2 == 0) {
    this->_padding_ = 1;
    goto LAB_004a8728;
  }
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(temp_name,s_default_d_scx,iVar2);
  if (unaff_retaddr != (byte *)0x0) {
    pbVar10 = (byte *)temp_name;
    pbVar3 = unaff_retaddr;
    do {
      bVar9 = *pbVar3;
      bVar11 = bVar9 < *pbVar10;
      if (bVar9 != *pbVar10) {
LAB_004a8376:
        iVar2 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_004a837b;
      }
      if (bVar9 == 0) break;
      bVar9 = pbVar3[1];
      bVar11 = bVar9 < pbVar10[1];
      if (bVar9 != pbVar10[1]) goto LAB_004a8376;
      pbVar3 = pbVar3 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar9 != 0);
    iVar2 = 0;
LAB_004a837b:
    if (iVar2 == 0) {
      this->need_to_save_flag = '\x01';
    }
  }
  lVar4 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr5,0xc387,1);
  if (lVar4 != 0) {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    this_00 = (RGE_Main_View *)operator_new(0x380);
    pcStack_8._0_1_ = 1;
    if (this_00 == (RGE_Main_View *)0x0) {
      this_00 = (RGE_Main_View *)0x0;
    }
    else {
      RGE_Main_View::RGE_Main_View(this_00);
      this_00->_padding_ = (int)&TRIBE_Main_View::_vftable_;
    }
    pcStack_8._0_1_ = 0;
    this->main_view = (TRIBE_Main_View *)this_00;
    if ((this_00 != (RGE_Main_View *)0x0) && (this_00->_padding_ == 0)) {
      lVar4 = RGE_View::setup((RGE_View *)this_00,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0,
                              0,0xa1,0,s_bordline);
      if (lVar4 != 0) {
        this_01 = (RGE_Diamond_Map_View *)operator_new(0x16c);
        pcStack_8._0_1_ = 2;
        if (this_01 == (RGE_Diamond_Map_View *)0x0) {
          this_02 = (RGE_Diamond_Map *)0x0;
        }
        else {
          this_02 = (RGE_Diamond_Map *)RGE_Diamond_Map_View::RGE_Diamond_Map_View(this_01);
        }
        pcStack_8._0_1_ = 0;
        this->map_view = (RGE_Diamond_Map_View *)this_02;
        if ((this_02 != (RGE_Diamond_Map *)0x0) && (this_02->_padding_ == 0)) {
          lVar4 = RGE_Diamond_Map::setup
                            (this_02,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0,0,0xa1,0,
                             rge_base_game->map_save_area);
          if (lVar4 != 0) {
            RGE_Diamond_Map::set_bitmap((RGE_Diamond_Map *)this->map_view,s_map640_bmp,0xc4e1);
            *(TRIBE_Main_View **)&this->map_view->field_0x150 = this->main_view;
            *(RGE_Diamond_Map_View **)&this->main_view->field_0x360 = this->map_view;
            TPanel::set_help_info((TPanel *)this->main_view,-1,-1);
            pRVar5 = RGE_Base_Game::get_font(rge_base_game,0xb);
            pTVar6 = (TMessagePanel *)operator_new(0x380);
            pcStack_8._0_1_ = 3;
            if (pTVar6 == (TMessagePanel *)0x0) {
              pTVar6 = (TMessagePanel *)0x0;
            }
            else {
              pTVar6 = (TMessagePanel *)
                       TMessagePanel::TMessagePanel
                                 (pTVar6,pRVar5->font,pRVar5->font_wid,pRVar5->font_hgt);
            }
            pcStack_8._0_1_ = 0;
            this->message_panel = pTVar6;
            if ((pTVar6 != (TMessagePanel *)0x0) && (pTVar6->_padding_ == 0)) {
              iVar2 = (**(code **)(pTVar6->_padding_ + 4))
                                (this->_padding_,this->main_view,0,0,0,0,0);
              if (iVar2 != 0) {
                pTVar7 = (TPanel *)operator_new(0xf4);
                pcStack_8._0_1_ = 4;
                if (pTVar7 == (TPanel *)0x0) {
                  pTVar7 = (TPanel *)0x0;
                }
                else {
                  pTVar7 = (TPanel *)TPanel::TPanel(pTVar7);
                }
                pcStack_8 = (code *)((uint)pcStack_8._1_3_ << 8);
                this->bottom_panel = pTVar7;
                if ((pTVar7 != (TPanel *)0x0) && (pTVar7->error_code == 0)) {
                  iVar2 = (**(code **)(pTVar7->_padding_ + 4))(this->_padding_,this,0,0,0,0,0);
                  if (iVar2 != 0) {
                    create_all_buttons_etc(this);
                    if ((unaff_retaddr == (byte *)0x0) || (*unaff_retaddr == 0)) {
                      set_player_active(this,0,1);
                      set_player_active(this,1,1);
                      iVar2 = 1;
                    }
                    else {
                      iVar2 = strstr(unaff_retaddr,s__scn);
                      if (iVar2 == 0) {
                        iVar2 = strstr(unaff_retaddr,s__SCN);
                        if (iVar2 != 0) goto LAB_004a8602;
                      }
                      else {
LAB_004a8602:
                        bVar9 = *unaff_retaddr;
                        pbVar10 = unaff_retaddr;
                        iVar2 = 0;
                        do {
                          iVar8 = iVar2;
                          pbVar10[(int)(name + -(int)unaff_retaddr)] = bVar9;
                          bVar9 = pbVar10[1];
                          pbVar10 = pbVar10 + 1;
                          iVar2 = iVar8 + 1;
                        } while (bVar9 != 0x2e);
                        name[iVar8 + 1] = '\0';
                        sprintf(unaff_retaddr,s__s_scx,name);
                        RGE_Scenario::Set_scenario_name
                                  ((RGE_Scenario *)this->world->_padding_,(char *)unaff_retaddr);
                      }
                      iVar2 = 0;
                      do {
                        iVar8 = RGE_Scenario::Get_player_Active
                                          ((RGE_Scenario *)this->world->_padding_,iVar2);
                        if (iVar8 == 0) break;
                        iVar2 = iVar2 + 1;
                      } while (iVar2 < 8);
                      iVar2 = iVar2 + -1;
                    }
                    TDropDownPanel::set_line(this->player_number_list,iVar2);
                    SavePlayerActiveStatus(this);
                    TPanel::set_curr_child((TPanel *)this,this->bottom_panel);
                    position_panels(this);
                    set_panel_info(this);
                    set_map_type(this,MapTypeBlank,0);
                    set_mp_victory_type(this,VictoryTypeStandard,0);
                    set_brush_size(this,BrushSizeVerySmall);
                    set_paint_type(this,PaintTypeTerrain,0);
                    set_player(this,1,'\0','\0');
                    set_unit_player(this,1);
                    set_message_type(this,MessageTypeDescription,0);
                    set_scenario_mode(this,ScenarioModeMap);
                    set_unit(this,-1);
                    RGE_Map::set_map_visible((RGE_Map *)this->world->_padding_,'\x01');
                    RGE_Map::set_map_fog((RGE_Map *)this->world->_padding_,'\0');
                    goto LAB_004a8728;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  this->_padding_ = 1;
LAB_004a8728:
  *unaff_FS_OFFSET = uStack_10;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004a8750
void * __thiscall
TRIBE_Screen_Sed::_vector_deleting_destructor_(TRIBE_Screen_Sed *this,uint param_1)
{
  ~TRIBE_Screen_Sed(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: set_panel_info
// Address: 004a8770
void __thiscall TRIBE_Screen_Sed::set_panel_info(TRIBE_Screen_Sed *this)
{
  RGE_Player *pRVar1;
  
  RGE_View::set_world((RGE_View *)this->main_view,(RGE_Game_World *)this->world);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_View::set_player((RGE_View *)this->main_view,pRVar1);
  RGE_Diamond_Map::set_world((RGE_Diamond_Map *)this->map_view,(RGE_Game_World *)this->world);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Diamond_Map::set_player((RGE_Diamond_Map *)this->map_view,pRVar1);
  return;
}

// --------------------------------------------------

// Function: set_string
// Address: 004a87d0
void __thiscall
TRIBE_Screen_Sed::set_string(TRIBE_Screen_Sed *this,char *param_1,long param_2,int param_3)
{
  TPanel::get_string((TPanel *)this,param_2,param_1,param_3);
  return;
}

// --------------------------------------------------

// Function: create_button
// Address: 004a87f0
int __thiscall
TRIBE_Screen_Sed::create_button
          (TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2,long param_3,int param_4)
{
  int iVar1;
  char str1 [120];
  TPanel::get_string((TPanel *)this,param_3,str1 + 4,0x78);
  iVar1 = create_button(this,param_1,param_2,str1 + 4,(char *)0x0,(char *)0x0,(char *)0x0);
  return iVar1;
}

// --------------------------------------------------

// Function: create_button
// Address: 004a8840
int __thiscall
TRIBE_Screen_Sed::create_button
          (TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2,char *param_3,char *param_4
          ,char *param_5,char *param_6)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_button
                    ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,0,0,0,0,10,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_5 != (char *)0x0) {
    TButtonPanel::set_text(*param_2,2,param_5);
  }
  if (param_6 != (char *)0x0) {
    TButtonPanel::set_text(*param_2,3,param_6);
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  if (this->_padding_ != 0) {
    TButtonPanel::set_bevel_info
              (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
               (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
               ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
  }
  return 1;
}

// --------------------------------------------------

// Function: create_text
// Address: 004a8910
int __thiscall
TRIBE_Screen_Sed::create_text
          (TRIBE_Screen_Sed *this,TPanel *param_1,TTextPanel **param_2,long param_3)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_text((TEasy_Panel *)this,param_1,param_2,param_3,0,0,0,0,10,0,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: create_text
// Address: 004a8960
int __thiscall
TRIBE_Screen_Sed::create_text
          (TRIBE_Screen_Sed *this,TPanel *param_1,TTextPanel **param_2,char *param_3)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_text((TEasy_Panel *)this,param_1,param_2,param_3,0,0,0,0,10,0,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: create_input
// Address: 004a89b0
int __thiscall
TRIBE_Screen_Sed::create_input
          (TRIBE_Screen_Sed *this,TPanel *param_1,TInputPanel **param_2,char *param_3,short param_4,
          FormatType param_5)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_input
                    ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,param_5,0,0,0,0,10);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: create_edit
// Address: 004a8a00
int __thiscall
TRIBE_Screen_Sed::create_edit
          (TRIBE_Screen_Sed *this,TPanel *param_1,TEditPanel **param_2,char *param_3,short param_4,
          FormatType param_5,int param_6,int param_7)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_edit
                    ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,param_5,0,0,0,0,10,param_6,
                     param_7);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: create_drop_down
// Address: 004a8a60
// [HELPER] s_: ""
// [HELPER] s__ai: ".ai"
// [HELPER] s__avi: ".avi"
// [HELPER] s__bmp: ".bmp"
// [HELPER] s__cty: ".cty"
// [HELPER] s__per: ".per"
int __thiscall
TRIBE_Screen_Sed::create_drop_down(TRIBE_Screen_Sed *this,TPanel *param_1,TDropDownPanel **param_2)
{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  TDropDownPanel **ppTVar7;
  uint uVar8;
  uint uVar9;
  TDropDownPanel *pTVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uchar uVar14;
  uchar uVar15;
  int end_i;
  RGE_Player *player;
  char str [256];
  
  if ((((((param_2 == &this->victory_object_list) || (param_2 == &this->victory_attribute_list)) ||
        (param_2 == &this->victory_ages_list)) ||
       ((param_2 == &this->victory_tech_list || (param_2 == &this->BuildList)))) ||
      (param_2 == &this->CityLayout)) ||
     ((param_2 == &this->AiRules || (param_2 == &this->victory_time)))) {
    lVar3 = 0xdc;
  }
  else if (param_2 == &this->victory_drop_down) {
    lVar3 = 0xb4;
  }
  else if ((((param_2 == this->cinematic_input) || (param_2 == this->cinematic_input + 1)) ||
           (param_2 == this->cinematic_input + 2)) ||
          (((param_2 == this->cinematic_input + 3 || (param_2 == &this->default_terrain_drop)) ||
           ((param_2 == &this->map_size_drop || (param_2 == &this->map_style_drop)))))) {
    lVar3 = 0xaa;
  }
  else if (((param_2 == &this->player_advance_civilization_drop) || (param_2 == &this->player_list))
          || (((param_2 == &this->player_number_list ||
               (((param_2 == &this->unit_player_list || (param_2 == &this->victory_player_list)) ||
                (param_2 == &this->options_player_list)))) ||
              ((param_2 == &this->Diplomacy_player_list ||
               (param_2 == &this->victory_enemy_player_list)))))) {
    lVar3 = 0x96;
  }
  else {
    lVar3 = 0x82;
  }
  iVar4 = TEasy_Panel::create_drop_down
                    ((TEasy_Panel *)this,param_1,param_2,lVar3,100,0,0,lVar3,0x16,10);
  if (iVar4 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  TDropDownPanel::empty_list(*param_2);
  ppTVar7 = &this->map_size_drop;
  if (param_2 == ppTVar7) {
    TDropDownPanel::append_line(*ppTVar7,0x2973,0);
    TDropDownPanel::append_line(*ppTVar7,0x2974,0);
    TDropDownPanel::append_line(*ppTVar7,0x2975,0);
    TDropDownPanel::append_line(*ppTVar7,0x2976,0);
    TDropDownPanel::append_line(*ppTVar7,0x2977,0);
    TDropDownPanel::append_line(*ppTVar7,0x2978,0);
    pTVar10 = *ppTVar7;
    lVar3 = 3;
  }
  else {
    ppTVar7 = &this->map_style_drop;
    if (param_2 == ppTVar7) {
      TDropDownPanel::append_line(*ppTVar7,0x296a,0);
      TDropDownPanel::append_line(*ppTVar7,0x296b,0);
      TDropDownPanel::append_line(*ppTVar7,0x296c,0);
      TDropDownPanel::append_line(*ppTVar7,0x296d,0);
      TDropDownPanel::append_line(*ppTVar7,0x296e,0);
      TDropDownPanel::append_line(*ppTVar7,0x296f,0);
      TDropDownPanel::append_line(*ppTVar7,0x2970,0);
      TDropDownPanel::append_line(*ppTVar7,0x2971,0);
      TDropDownPanel::append_line(*ppTVar7,0x2972,0);
      pTVar10 = *ppTVar7;
      lVar3 = 3;
    }
    else {
      ppTVar7 = &this->player_number_list;
      if (param_2 == ppTVar7) {
        iVar4 = 0;
        do {
          TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
          iVar4 = iVar4 + 1;
        } while (iVar4 < 8);
        pTVar10 = *ppTVar7;
        lVar3 = 0;
      }
      else {
        ppTVar7 = &this->victory_enemy_player_list;
        if (param_2 == ppTVar7) {
          iVar4 = 0;
          do {
            TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 8);
          pTVar10 = *ppTVar7;
          lVar3 = 0;
        }
        else {
          ppTVar7 = &this->victory_attribute_list;
          if (param_2 == ppTVar7) {
            TDropDownPanel::append_line(*ppTVar7,0x2882,0x2b);
            TDropDownPanel::append_line(*ppTVar7,0x2883,0x29);
            TDropDownPanel::append_line(*ppTVar7,0x2884,0x2c);
            TDropDownPanel::append_line(*ppTVar7,0x2886,0x28);
            TDropDownPanel::append_line(*ppTVar7,0x2887,0x15);
            TDropDownPanel::append_line(*ppTVar7,0x2888,0x14);
            TDropDownPanel::append_line(*ppTVar7,0x2889,0x25);
            pTVar10 = *ppTVar7;
            lVar3 = 0;
          }
          else {
            ppTVar7 = &this->default_terrain_drop;
            if (param_2 == ppTVar7) {
              TDropDownPanel::append_line(*ppTVar7,0x297d,0);
              TDropDownPanel::append_line(*ppTVar7,0x297e,0);
              TDropDownPanel::append_line(*ppTVar7,0x297f,0);
              TDropDownPanel::append_line(*ppTVar7,0x2980,0);
              TDropDownPanel::append_line(*ppTVar7,0x2981,0);
              TDropDownPanel::append_line(*ppTVar7,0x2982,0);
              TDropDownPanel::append_line(*ppTVar7,0x2983,0);
              TDropDownPanel::append_line(*ppTVar7,0x2984,0);
              TDropDownPanel::append_line(*ppTVar7,0x2985,0);
              pTVar10 = *ppTVar7;
              lVar3 = 0;
            }
            else {
              ppTVar7 = this->player_setting_drop;
              if (param_2 == ppTVar7) {
                TDropDownPanel::append_line(*ppTVar7,0x27e3,0);
                TDropDownPanel::append_line(*ppTVar7,0x27e4,0);
                pTVar10 = *ppTVar7;
                lVar3 = 0;
              }
              else {
                ppTVar7 = &this->victory_drop_down;
                if (param_2 == ppTVar7) {
                  TDropDownPanel::append_line(*ppTVar7,0x2851,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2852,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2853,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2854,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2855,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2856,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2857,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2858,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2859,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285a,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285b,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285c,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285d,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285e,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285f,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2860,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2861,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2862,0);
                  TDropDownPanel::append_line(*ppTVar7,0x284f,0);
                  pTVar10 = *ppTVar7;
                  lVar3 = 0;
                }
                else {
                  ppTVar7 = this->player_setting_drop + 1;
                  if (param_2 == ppTVar7) {
                    TDropDownPanel::append_line(*ppTVar7,0x27f7,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27f8,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27f9,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fa,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fb,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fc,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fd,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fe,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27ff,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2800,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2801,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2802,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2806,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2807,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2809,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2808,0);
                    pTVar10 = *ppTVar7;
                    lVar3 = 0;
                  }
                  else {
                    ppTVar7 = &this->victory_ages_list;
                    if (param_2 == ppTVar7) {
                      TDropDownPanel::append_line(*ppTVar7,0x1069,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106a,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106b,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106c,0);
                      pTVar10 = *ppTVar7;
                      lVar3 = 0;
                    }
                    else {
                      ppTVar7 = &this->victory_tech_list;
                      if (param_2 == ppTVar7) {
                        TDropDownPanel::set_sorted(*ppTVar7,1);
                        iVar4 = 0;
                        piVar5 = (int *)rge_base_game->world[1]._padding_;
                        if (0 < (short)piVar5[1]) {
                          iVar12 = 0;
                          do {
                            pcVar6 = TPanel::get_string((TPanel *)this,
                                                        (int)*(short *)(*piVar5 + 0x2a + iVar12));
                            if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
                              TDropDownPanel::append_line(*ppTVar7,pcVar6,iVar4);
                            }
                            iVar4 = iVar4 + 1;
                            iVar12 = iVar12 + 0x3c;
                            piVar5 = (int *)rge_base_game->world[1]._padding_;
                          } while (iVar4 < (short)piVar5[1]);
                        }
                        pTVar10 = *ppTVar7;
                        lVar3 = 0;
                      }
                      else {
                        if (param_2 == &this->AiRules) {
                          uVar15 = '\x01';
                          uVar14 = '\0';
                          pcVar13 = s__per;
                          pTVar10 = this->AiRules;
                          pcVar6 = rge_base_game->prog_info->ai_dir;
                        }
                        else {
                          ppTVar7 = &this->BuildList;
                          if (param_2 == ppTVar7) {
                            uVar15 = '\x01';
                            pcVar13 = s__ai;
                          }
                          else {
                            ppTVar7 = &this->CityLayout;
                            if (param_2 != ppTVar7) {
                              if (((param_2 == this->cinematic_input) ||
                                  (param_2 == this->cinematic_input + 1)) ||
                                 (param_2 == this->cinematic_input + 2)) {
                                pTVar10 = *param_2;
                                uVar15 = '\0';
                                uVar14 = '\x01';
                                pcVar13 = s__avi;
                                pcVar6 = rge_base_game->prog_info->avi_dir;
                              }
                              else {
                                if (param_2 != this->cinematic_input + 3) {
                                  ppTVar7 = &this->victory_object_list;
                                  if (param_2 != ppTVar7) goto LAB_004a9300;
                                  TDropDownPanel::set_sorted(*ppTVar7,1);
                                  TDropDownPanel::empty_list(*ppTVar7);
                                  iVar11 = 0;
                                  iVar4 = *(int *)(this->world->_padding_ + 4);
                                  iVar12 = (int)*(short *)(iVar4 + 0x22);
                                  if (0 < iVar12) {
                                    do {
                                      iVar2 = *(int *)(*(int *)(iVar4 + 0x24) + iVar11 * 4);
                                      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x4e) == '\0')) {
                                        if (*(short *)(iVar2 + 0xc) < 1) {
                                          uVar8 = 0xffffffff;
                                          pcVar6 = *(char **)(iVar2 + 8);
                                          do {
                                            pcVar13 = pcVar6;
                                            if (uVar8 == 0) break;
                                            uVar8 = uVar8 - 1;
                                            pcVar13 = pcVar6 + 1;
                                            cVar1 = *pcVar6;
                                            pcVar6 = pcVar13;
                                          } while (cVar1 != '\0');
                                          uVar8 = ~uVar8;
                                          pcVar6 = pcVar13 + -uVar8;
                                          pcVar13 = str;
                                          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                                            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
                                            pcVar6 = pcVar6 + 4;
                                            pcVar13 = pcVar13 + 4;
                                          }
                                          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                                            *pcVar13 = *pcVar6;
                                            pcVar6 = pcVar6 + 1;
                                            pcVar13 = pcVar13 + 1;
                                          }
                                        }
                                        else {
                                          (**(code **)(rge_base_game->_padding_ + 0x20))
                                                    ((int)*(short *)(iVar2 + 0xc),str,0x100);
                                        }
                                        TDropDownPanel::append_line
                                                  (this->victory_object_list,str,iVar11);
                                      }
                                      iVar11 = iVar11 + 1;
                                    } while (iVar11 < iVar12);
                                  }
                                  pTVar10 = this->victory_object_list;
                                  lVar3 = 0;
                                  goto LAB_004a92fb;
                                }
                                pTVar10 = *param_2;
                                uVar15 = '\0';
                                uVar14 = '\x01';
                                pcVar13 = s__bmp;
                                pcVar6 = s_;
                              }
                              goto LAB_004a92f0;
                            }
                            uVar15 = '\0';
                            pcVar13 = s__cty;
                          }
                          uVar14 = '\x01';
                          pTVar10 = *ppTVar7;
                          pcVar6 = rge_base_game->prog_info->ai_dir;
                        }
LAB_004a92f0:
                        MakeFileList(this,pTVar10,pcVar6,pcVar13,uVar14,uVar15);
                        pTVar10 = *param_2;
                        lVar3 = 0;
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
LAB_004a92fb:
  TDropDownPanel::set_line(pTVar10,lVar3);
LAB_004a9300:
  return (uint)(this->_padding_ == 0);
}

// --------------------------------------------------

// Function: SetupListOfTerrain
// Address: 004a9320
int __thiscall TRIBE_Screen_Sed::SetupListOfTerrain(TRIBE_Screen_Sed *this,TListPanel *param_1)
{
  TTextPanel::empty_list((TTextPanel *)param_1);
  TTextPanel::append_line((TTextPanel *)param_1,0x297d,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x297e,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x297f,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2980,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2981,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2982,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2983,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2984,0);
  TTextPanel::append_line((TTextPanel *)param_1,0x2985,0);
  return 8;
}

// --------------------------------------------------

// Function: create_list
// Address: 004a93c0
// [HELPER] s__s__d: "%s %d"
int __thiscall
TRIBE_Screen_Sed::create_list
          (TRIBE_Screen_Sed *this,TPanel *param_1,TListPanel **param_2,TScrollBarPanel **param_3)
{
  int iVar1;
  char str1 [50];
  char str2 [60];
  
  iVar1 = TEasy_Panel::create_list((TEasy_Panel *)this,param_1,param_2,0,0,0,0,10);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  TTextPanel::empty_list((TTextPanel *)*param_2);
  iVar1 = TEasy_Panel::create_auto_scrollbar
                    ((TEasy_Panel *)this,(TScrollBarPanel **)param_2,(TTextPanel *)*param_2,0x14);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_2 == &this->paint_elevation_list) {
    set_string(this,str1,0x2987,0x32);
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      sprintf(str2,s__s__d,str1,iVar1);
      TTextPanel::append_line((TTextPanel *)this->paint_elevation_list,str2,0);
    } while (iVar1 < 7);
    return 1;
  }
  if (param_2 == &this->paint_terrain_list) {
    SetupListOfTerrain(this,this->paint_terrain_list);
  }
  return 1;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Sed
// Address: 004a94a0
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
void __thiscall TRIBE_Screen_Sed::~TRIBE_Screen_Sed(TRIBE_Screen_Sed *this)
{
  TShape *pTVar1;
  int iVar2;
  TShape **ppTVar3;
  TButtonPanel **ppTVar4;
  TEditPanel **ppTVar5;
  TDropDownPanel **ppTVar6;
  TTextPanel **ppTVar7;
  TButtonPanel **ppTVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f468;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,&s_QuitSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OpenSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_NewSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_type_label);
  ppTVar7 = this->map_type_text;
  iVar2 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -3));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->default_terrain_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->default_terrain_drop);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_size_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_size_drop);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_style_drop);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_style_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_generating_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_input);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_used_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_used_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->generate_map_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->brush_size_label);
  ppTVar7 = this->brush_size_button_label;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_type_label);
  ppTVar7 = this->paint_type_button_label;
  iVar2 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -3));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_elevation_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_elevation_scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_advance_civilization_drop);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_starting_age_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_build_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_city_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->AiRules_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_number_list);
  ppTVar5 = this->player_inven_input;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar5 + -5));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar5);
    ppTVar5 = ppTVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar6 = this->player_setting_drop;
  iVar2 = 2;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar6 + -3));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar6);
    ppTVar6 = ppTVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->BuildList);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->CityLayout);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->AiRules);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_player_list);
  ppTVar7 = this->unit_mode_select_label;
  iVar2 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -4));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_scrollbar);
  if (this->unit_list_info != (List_Info *)0x0) {
    free(this->unit_list_info);
    this->unit_list_info = (List_Info *)0x0;
  }
  if (this->object_panel != (TRIBE_Scenario_Editor_Panel_Object *)0x0) {
    (**(code **)this->object_panel->_padding_)(1);
    this->object_panel = (TRIBE_Scenario_Editor_Panel_Object *)0x0;
  }
  pTVar1 = this->button_unit_pics;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->button_unit_pics = (TShape *)0x0;
  }
  ppTVar3 = this->button_bldg_pics;
  iVar2 = 5;
  do {
    pTVar1 = *ppTVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *ppTVar3 = (TShape *)0x0;
    }
    ppTVar3 = ppTVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = this->victory_cond_on;
  iVar2 = 6;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar7 = this->victory_text_and_or;
  iVar2 = 2;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_long_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_conquest);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_explore);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_explore_percent);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_ruins);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_artifacts);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_discoveries);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_gold);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_explore);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_ruins);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_artifacts);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_discoveries);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_gold);
  ppTVar4 = this->victory_cond_type;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -5));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_score_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_score);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_time_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_time);
  ppTVar4 = this->victory_button;
  iVar2 = 0xc;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_drop_down);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_object_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_player_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_ages_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_tech_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_set_object);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_set_destination);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_go_to_dest);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_type);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_input);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_enemy_player_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_attribute_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_which_enemy_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_object_scrollbar);
  ppTVar7 = this->message_button_label;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message_input);
  ppTVar6 = this->cinematic_input;
  iVar2 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar6 + -4));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar6);
    ppTVar6 = ppTVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = this->options_button;
  iVar2 = 1;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -1));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->options_player_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->options_disable_tech_text);
  ppTVar7 = this->options_disable_text;
  iVar2 = 0x10;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -0x10));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    ppTVar7 = ppTVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = this->Diplomacy_AlliedVictory;
  ppTVar8 = this->Diplomacy_friend_box[0] + 1;
  iVar2 = 8;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)&this->Diplomacy_player_list);
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -0x25));
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar8 + -1));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar8);
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar8 + 1));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    ppTVar8 = ppTVar8 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)this->Diplomacy_status_label);
  TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 1));
  TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 2));
  TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 3));
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->menu_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->help_button);
  ppTVar4 = this->scenario_mode_button;
  iVar2 = 10;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)this,&this->bottom_panel);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message_panel);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->main_view);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_view);
  pTVar1 = this->background_pic;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->background_pic = (TShape *)0x0;
  }
  if (this->world != (TRIBE_World *)0x0) {
    (**(code **)(this->world->_padding_ + 0xb8))();
  }
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: set_scenario_mode
// Address: 004a9cc0
void __thiscall TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed *this,ScenarioMode param_1)
{
  short sVar1;
  TRIBE_Player *pTVar2;
  RGE_Player *pRVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  TButtonPanel *pTVar7;
  TEditPanel **ppTVar8;
  TDropDownPanel **ppTVar9;
  TDropDownPanel **ppTVar10;
  TButtonPanel **ppTVar11;
  TButtonPanel **ppTVar12;
  TTextPanel **ppTVar13;
  int unaff_EBP;
  int iVar14;
  int iVar15;
  RGE_Master_Static_Object *pRVar16;
  int i;
  int activate_counter;
  ScenarioMode mode;
  ScenarioMode local_4;
  
  mode = ScenarioModeNone;
  this->valid_save_spot_flag = '\0';
  do {
    if (mode == ScenarioModeNone) {
      local_4 = this->scenario_mode;
      iVar15 = 0;
    }
    else {
      if (param_1 != ScenarioModeSave) {
        local_4 = param_1;
      }
      iVar15 = 1;
    }
    switch(local_4) {
    case ScenarioModeMap:
      (**(code **)(this->map_type_label->_padding_ + 0x14))(iVar15);
      ppTVar13 = this->map_type_text;
      iVar14 = 3;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      (**(code **)(this->generate_map_button->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        set_map_type(this,MapTypeNone,0);
      }
      else {
        set_map_type(this,this->map_type,1);
      }
      break;
    case ScenarioModeTerrain:
      (**(code **)(this->brush_size_label->_padding_ + 0x14))(iVar15);
      (**(code **)(this->paint_type_label->_padding_ + 0x14))(iVar15);
      (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar15);
      ppTVar13 = this->brush_size_button_label;
      iVar14 = 5;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      ppTVar13 = this->paint_type_button_label;
      iVar14 = 3;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        set_brush_size(this,BrushSizeNone);
        set_paint_type(this,PaintTypeNone,0);
      }
      else {
        set_brush_size(this,this->brush_size);
        set_paint_type(this,this->paint_type,1);
      }
      break;
    case ScenarioModePlayers:
      (**(code **)(this->player_list->_padding_ + 0x14))(iVar15);
      (**(code **)(this->player_number_list->_padding_ + 0x14))(iVar15);
      ppTVar8 = this->player_inven_input;
      iVar14 = 5;
      do {
        (**(code **)(((TTextPanel *)ppTVar8[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar8)->_padding_ + 0x14))(iVar15);
        ppTVar8 = ppTVar8 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      ppTVar9 = this->player_setting_drop;
      iVar14 = 2;
      do {
        (**(code **)(((TTextPanel *)ppTVar9[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar9)->_padding_ + 0x14))(iVar15);
        ppTVar9 = ppTVar9 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        set_player(this,this->player_num,'\x01','\0');
        (**(code **)(*(int *)this->map_view + 0x14))(1);
        SavePlayerActiveStatus(this);
      }
      else {
        iVar14 = T_Scenario::GetPlayerAge
                           ((T_Scenario *)this->world->_padding_,this->player_num + -1);
        TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,iVar14);
        set_player(this,this->player_num,'\0','\x01');
        TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
        (**(code **)(*(int *)this->map_view + 0x14))(0);
      }
      (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x14))(iVar15);
      (**(code **)(this->player_label->_padding_ + 0x14))(iVar15);
      (**(code **)(this->player_starting_age_label->_padding_ + 0x14))(iVar15);
      (**(code **)(this->player_build_text->_padding_ + 0x14))(iVar15);
      (**(code **)(this->player_city_text->_padding_ + 0x14))(iVar15);
      (**(code **)(this->AiRules_text->_padding_ + 0x14))(iVar15);
      (**(code **)(this->BuildList->_padding_ + 0x14))(iVar15);
      (**(code **)(this->CityLayout->_padding_ + 0x14))(iVar15);
      (**(code **)(this->AiRules->_padding_ + 0x14))(iVar15);
      break;
    case ScenarioModeUnits:
      (**(code **)(this->unit_player_list->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_list->_padding_ + 0x14))(iVar15);
      (**(code **)(this->object_panel->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select[3]->_padding_ + 0x14))(iVar15);
      if (iVar15 != 0) {
        TButtonPanel::set_radio_button(this->unit_mode_select[0]);
      }
      (**(code **)(this->unit_mode_select_label[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select_label[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select_label[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->unit_mode_select_label[3]->_padding_ + 0x14))(iVar15);
      sVar1 = this->player_num;
      if (iVar15 == 0) {
        if ((sVar1 < 1) || (8 < sVar1)) {
          this->player_num = 1;
          set_player(this,1,'\0','\0');
        }
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        set_unit(this,-1);
      }
      else {
        set_unit_player(this,sVar1);
        iVar15 = TTextPanel::currentLineNumber((TTextPanel *)this->unit_list);
        set_unit(this,(short)iVar15);
        TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->unit_list);
        set_paint_object_mode(this);
        (**(code **)(rge_base_game->_padding_ + 0x10))(rge_base_game->game_mode,4);
        if ((rge_base_game->master_obj_id == -1) ||
           (pRVar3 = RGE_Base_Game::get_player(rge_base_game), pRVar3 == (RGE_Player *)0x0)) {
          pTVar2 = (TRIBE_Player *)0x0;
          pRVar16 = (RGE_Master_Static_Object *)0x0;
        }
        else {
          sVar1 = rge_base_game->master_obj_id;
          pTVar2 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
          pRVar3 = RGE_Base_Game::get_player(rge_base_game);
          pRVar16 = *(RGE_Master_Static_Object **)
                     (*(int *)(*(int *)(this->world->_padding_ + pRVar3->id * 4) + 0x24) + sVar1 * 4
                     );
        }
        TRIBE_Scenario_Editor_Panel_Object::set_master_info(this->object_panel,pRVar16,pTVar2);
        (**(code **)(this->object_panel->_padding_ + 0x20))(1);
      }
      break;
    case ScenarioModeDiplomacy:
      if (this->player_num < 1) {
        this->player_num = 1;
      }
      (**(code **)(this->Diplomacy_player_list->_padding_ + 0x14))(iVar15);
      i = 0;
      lVar5 = TDropDownPanel::get_line(this->player_number_list);
      if (-1 < lVar5) {
        ppTVar12 = this->Diplomacy_friend_box[0] + 1;
        ppTVar11 = this->Diplomacy_AlliedVictory;
        do {
          (**(code **)(((TTextPanel *)ppTVar11[-0x25])->_padding_ + 0x14))(iVar15);
          pTVar7 = *ppTVar11;
          if (unaff_EBP != this->player_num + -1) {
            (**(code **)(pTVar7->_padding_ + 0x14))(0);
            (**(code **)((*(TButtonPanel *(*) [3])(ppTVar12 + -1))[0]->_padding_ + 0x14))(iVar15);
            (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
            pTVar7 = ppTVar12[1];
          }
          (**(code **)(pTVar7->_padding_ + 0x14))(iVar15);
          ppTVar11 = ppTVar11 + 1;
          i = i + 1;
          ppTVar12 = ppTVar12 + 3;
          lVar5 = TDropDownPanel::get_line(this->player_number_list);
        } while (i <= lVar5);
      }
      (**(code **)(this->Diplomacy_status_label[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->Diplomacy_status_label[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->Diplomacy_status_label[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(this->Diplomacy_status_label[3]->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        save_diplomacy_in_scenario(this,this->player_num + -1);
      }
      else {
        load_diplomacy_from_scenario(this,this->player_num + -1);
      }
      break;
    case ScenarioModeVictory:
      activate_victory_panel(this,iVar15);
      if (iVar15 == 0) {
        save_victory_cond_in_scenario(this,this->CurrentVictory);
        iVar15 = 0;
        lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
        activate_victory_proper_fields(this,lVar5,iVar15);
        this->SelectedObject = (RGE_Static_Object *)0x0;
        this->DestinationObject = (RGE_Static_Object *)0x0;
        pRVar3 = RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(pRVar3);
      }
      else {
        load_victory_cond_from_scenario(this,this->CurrentVictory);
        lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
        activate_victory_proper_fields(this,lVar5,iVar15);
      }
      break;
    case ScenarioModeVictoryMulti:
      (**(code **)(this->victory_condition_label->_padding_ + 0x14))(iVar15);
      ppTVar12 = this->victory_cond_type;
      iVar14 = 5;
      do {
        (**(code **)(((TTextPanel *)ppTVar12[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
        ppTVar12 = ppTVar12 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        save_multi_victory_cond_in_scenario(this);
        (**(code **)(*(int *)this->map_view + 0x14))(1);
        set_mp_victory_type(this,VictoryTypeNone,0);
      }
      else {
        load_multi_victory_cond_from_scenario(this);
        (**(code **)(*(int *)this->map_view + 0x14))(0);
        set_mp_victory_type(this,this->mp_victory_type,1);
      }
      break;
    case ScenarioModeOptions:
      if (iVar15 == 0) {
        (**(code **)(*(int *)this->map_view + 0x14))(1);
        SaveDisabledItemsInScenario(this);
      }
      else {
        (**(code **)(*(int *)this->map_view + 0x14))(0);
        iVar14 = this->options_button[0]->_padding_;
        iVar6 = T_Scenario::GetScenarioOption((T_Scenario *)this->world->_padding_,2);
        (**(code **)(iVar14 + 0xe0))(iVar6);
        LoadDisabledItemsFromScenario(this);
        if (this->player_num == 0) {
          iVar14 = 0;
        }
        else {
          iVar14 = this->player_num + -1;
        }
        TDropDownPanel::setCurrentLineNumber(this->options_player_list,iVar14);
      }
      ppTVar12 = this->options_button;
      iVar14 = 1;
      do {
        (**(code **)(((TTextPanel *)ppTVar12[-1])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
        ppTVar12 = ppTVar12 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      (**(code **)(this->options_player_list->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        lVar5 = TDropDownPanel::get_line(this->options_player_list);
        this->player_num = (short)lVar5 + 1;
      }
      else {
        TDropDownPanel::set_line(this->options_player_list,this->player_num + -1);
      }
      (**(code **)(this->options_disable_tech_text->_padding_ + 0x14))(iVar15);
      ppTVar13 = this->options_disable_text;
      iVar14 = 0x10;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-0x10])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      break;
    case ScenarioModeMessages:
      ppTVar13 = this->message_button_label;
      iVar14 = 5;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      TButtonPanel::set_radio_button(this->message_button[this->current_message]);
      lVar5 = this->current_message;
      if (iVar15 == 0) {
        pcVar4 = TEditPanel::get_input_buffer(this->message_input);
        RGE_Scenario::Set_message((RGE_Scenario *)this->world->_padding_,pcVar4,lVar5);
        set_message_type(this,MessageTypeNone,0);
        (**(code **)(*(int *)this->map_view + 0x14))(1);
        save_info_in_scenario(this);
        break;
      }
      pcVar4 = RGE_Scenario::Get_message((RGE_Scenario *)this->world->_padding_,lVar5);
      TEditPanel::set_text(this->message_input,pcVar4);
      switch(this->current_message) {
      case 0:
        lVar5 = 0x7770;
        break;
      case 1:
        lVar5 = 0x7771;
        break;
      case 2:
        lVar5 = 0x7772;
        break;
      case 3:
        lVar5 = 0x7773;
        break;
      case 4:
        lVar5 = 0x7774;
        break;
      default:
        goto switchD_004aa268_default;
      }
      TPanel::set_help_info((TPanel *)this->message_input,lVar5,-1);
switchD_004aa268_default:
      set_message_type(this,this->message_type,1);
      (**(code **)(*(int *)this->map_view + 0x14))(0);
      TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->message_input);
      break;
    case ScenarioModeCinematics:
      ppTVar9 = this->cinematic_input;
      activate_counter = 4;
      ppTVar10 = ppTVar9;
      do {
        (**(code **)(((TTextPanel *)ppTVar10[-4])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar10)->_padding_ + 0x14))(iVar15);
        ppTVar10 = ppTVar10 + 1;
        activate_counter = activate_counter + -1;
      } while (activate_counter != 0);
      if (iVar15 == 0) {
        pcVar4 = TDropDownPanel::currentLine(*ppTVar9);
        RGE_Scenario::Set_Cine_PreGame((RGE_Scenario *)this->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[1]);
        RGE_Scenario::Set_Cine_Victory((RGE_Scenario *)this->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[2]);
        RGE_Scenario::Set_Cine_Loss((RGE_Scenario *)this->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[3]);
        RGE_Scenario::Set_Mission_Bmp((RGE_Scenario *)this->world->_padding_,pcVar4);
      }
      else {
        TPanel::set_curr_child(this->bottom_panel,(TPanel *)*ppTVar9);
        pcVar4 = RGE_Scenario::Get_Cine_PreGame((RGE_Scenario *)this->world->_padding_);
        lVar5 = TDropDownPanel::get_line(*ppTVar9,pcVar4);
        TDropDownPanel::setCurrentLineNumber(*ppTVar9,lVar5);
        pcVar4 = RGE_Scenario::Get_Cine_Victory((RGE_Scenario *)this->world->_padding_);
        lVar5 = TDropDownPanel::get_line(this->cinematic_input[1],pcVar4);
        TDropDownPanel::setCurrentLineNumber(this->cinematic_input[1],lVar5);
        pcVar4 = RGE_Scenario::Get_Cine_Loss((RGE_Scenario *)this->world->_padding_);
        lVar5 = TDropDownPanel::get_line(this->cinematic_input[2],pcVar4);
        TDropDownPanel::setCurrentLineNumber(this->cinematic_input[2],lVar5);
        pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
        iVar15 = TDropDownPanel::get_line(this->cinematic_input[3],pcVar4);
        if (iVar15 == -1) {
          lVar5 = 0;
          pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
          TDropDownPanel::append_line(this->cinematic_input[3],pcVar4,lVar5);
          pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
          iVar15 = TDropDownPanel::get_line(this->cinematic_input[3],pcVar4);
        }
        TDropDownPanel::setCurrentLineNumber(this->cinematic_input[3],iVar15);
      }
    }
    mode = mode + ScenarioModeMap;
    if (1 < (int)mode) {
      if (param_1 != ScenarioModeSave) {
        this->scenario_mode = param_1;
        if (param_1 != ScenarioModeNone) {
          TButtonPanel::set_radio_button(this->scenario_mode_button[param_1 - ScenarioModeMap]);
        }
        iVar15 = this->_padding_;
        (**(code **)(iVar15 + 0x50))(this->_padding_,this->_padding_);
        (**(code **)(iVar15 + 0x20))(1);
      }
      this->valid_save_spot_flag = '\x01';
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: set_paint_object_mode
// Address: 004aa730
void __thiscall TRIBE_Screen_Sed::set_paint_object_mode(TRIBE_Screen_Sed *this)
{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((((rge_base_game->master_obj_id != -1) &&
       (iVar1 = *(int *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x24) +
                        rge_base_game->master_obj_id * 4), iVar1 != 0)) &&
      (*(char *)(iVar1 + 4) == 'P')) && (*(char *)(iVar1 + 0x16c) != '\0')) {
    bVar2 = true;
  }
  if (bVar2) {
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x15,0);
    return;
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(8,rge_base_game->sub_game_mode);
  return;
}

// --------------------------------------------------

// Function: set_map_type
// Address: 004aa7a0
void __thiscall TRIBE_Screen_Sed::set_map_type(TRIBE_Screen_Sed *this,MapType param_1,int param_2)
{
  MapType MVar1;
  TTextPanel *pTVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    if (iVar3 == 0) {
      iVar4 = 0;
      MVar1 = this->map_type;
    }
    else {
      if (param_1 == MapTypeNone) {
        return;
      }
      if (param_2 == 0) break;
      iVar4 = 1;
      MVar1 = param_1;
    }
    if (MVar1 == MapTypeBlank) {
      (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
      (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
      (**(code **)(this->default_terrain_label->_padding_ + 0x14))(iVar4);
      pTVar2 = (TTextPanel *)this->default_terrain_drop;
LAB_004aa8b8:
      (**(code **)(pTVar2->_padding_ + 0x14))(iVar4);
    }
    else {
      if (MVar1 == MapTypeRandom) {
        (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_style_label->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_style_drop->_padding_ + 0x14))(iVar4);
        (**(code **)(this->random_seed_used_label->_padding_ + 0x14))(iVar4);
        pTVar2 = this->random_seed_used_text;
        goto LAB_004aa8b8;
      }
      if (MVar1 == MapTypeSeed) {
        (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_style_label->_padding_ + 0x14))(iVar4);
        (**(code **)(this->map_style_drop->_padding_ + 0x14))(iVar4);
        (**(code **)(this->random_seed_label->_padding_ + 0x14))(iVar4);
        (**(code **)(this->random_seed_input->_padding_ + 0x14))(iVar4);
        if (iVar4 != 0) {
          TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->random_seed_input);
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  this->map_type = param_1;
  TButtonPanel::set_radio_button(this->map_type_button[param_1 - MapTypeBlank]);
  (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_mp_victory_type
// Address: 004aa8f0
void __thiscall
TRIBE_Screen_Sed::set_mp_victory_type(TRIBE_Screen_Sed *this,VictoryType param_1,int param_2)
{
  VictoryType VVar1;
  TButtonPanel **ppTVar2;
  TTextPanel **ppTVar3;
  int iVar4;
  int iVar5;
  int activate_counter;
  int local_4;
  
  local_4 = 0;
  do {
    if (local_4 == 0) {
      iVar5 = 0;
      VVar1 = this->mp_victory_type;
    }
    else {
      if (param_1 == VictoryTypeNone) {
        return;
      }
      if (param_2 == 0) break;
      iVar5 = 1;
      VVar1 = param_1;
    }
    switch(VVar1) {
    case VictoryTypeScore:
      (**(code **)(this->victory_score_label->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_score->_padding_ + 0x14))(iVar5);
      break;
    case VictoryTypeTime:
      (**(code **)(this->victory_time_label->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_time->_padding_ + 0x14))(iVar5);
      break;
    case VictoryTypeCustom:
      ppTVar2 = this->victory_cond_on;
      iVar4 = 5;
      do {
        (**(code **)((*ppTVar2)->_padding_ + 0x14))(iVar5);
        ppTVar2 = ppTVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      ppTVar3 = this->victory_text_and_or;
      iVar4 = 2;
      do {
        (**(code **)(((TButtonPanel *)ppTVar3[-5])->_padding_ + 0x14))(iVar5);
        (**(code **)((*ppTVar3)->_padding_ + 0x14))(iVar5);
        ppTVar3 = ppTVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      (**(code **)(this->victory_amount_label->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_label_conquest->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_label_explore->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_label_ruins->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_label_artifacts->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_label_discoveries->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_condition_explore->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_condition_ruins->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_condition_artifacts->_padding_ + 0x14))(iVar5);
      (**(code **)(this->victory_condition_discoveries->_padding_ + 0x14))(iVar5);
      if (iVar5 == 1) {
        TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_condition_explore);
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 2);
  this->mp_victory_type = param_1;
  TButtonPanel::set_radio_button
            ((TButtonPanel *)this->victory_cond_type_label[param_1 + VictoryTypeTime]);
  (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_brush_size
// Address: 004aaa90
void __thiscall TRIBE_Screen_Sed::set_brush_size(TRIBE_Screen_Sed *this,BrushSize param_1)
{
  if (param_1 != BrushSizeNone) {
    this->brush_size = param_1;
    TButtonPanel::set_radio_button(this->brush_size_button[param_1 - BrushSizeVerySmall]);
    switch(this->brush_size) {
    case BrushSizeVerySmall:
      rge_base_game->brush_size = 1;
      return;
    case BrushSizeSmall:
      rge_base_game->brush_size = 3;
      return;
    case BrushSizeMedium:
      rge_base_game->brush_size = 5;
      return;
    case BrushSizeLarge:
      rge_base_game->brush_size = 7;
      return;
    case BrushSizeXLarge:
      rge_base_game->brush_size = 9;
      return;
    default:
      rge_base_game->brush_size = 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_paint_type
// Address: 004aab60
void __thiscall
TRIBE_Screen_Sed::set_paint_type(TRIBE_Screen_Sed *this,PaintType param_1,int param_2)
{
  TTextPanel **ppTVar1;
  int iVar2;
  int iVar3;
  int activate_counter;
  PaintType val;
  PaintType local_4;
  
  val = PaintTypeNone;
  do {
    if (val == PaintTypeNone) {
      local_4 = this->paint_type;
      iVar3 = 0;
    }
    else {
      if (param_1 == PaintTypeNone) {
        return;
      }
      if (param_2 == 0) break;
      local_4 = param_1;
      iVar3 = 1;
    }
    (**(code **)(this->brush_size_label->_padding_ + 0x14))(iVar3);
    ppTVar1 = this->brush_size_button_label;
    iVar2 = 5;
    do {
      (**(code **)(((TButtonPanel *)ppTVar1[-5])->_padding_ + 0x14))(iVar3);
      (**(code **)((*ppTVar1)->_padding_ + 0x14))(iVar3);
      ppTVar1 = ppTVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (local_4 == PaintTypeTerrain) {
      (**(code **)(this->paint_terrain_list->_padding_ + 0x14))(iVar3);
      (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar3);
      if (iVar3 == 0) {
LAB_004aacf6:
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      }
      else {
        iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_terrain_list);
        set_terrain(this,(short)iVar3);
        (**(code **)(rge_base_game->_padding_ + 0x10))(9,0);
      }
    }
    else if (local_4 == PaintTypeElevation) {
      (**(code **)(this->paint_elevation_list->_padding_ + 0x14))(iVar3);
      (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar3);
      if (iVar3 == 0) goto LAB_004aacf6;
      iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
      set_elevation(this,(short)iVar3);
      (**(code **)(rge_base_game->_padding_ + 0x10))(10,0);
    }
    else if (local_4 == PaintTypeCliffs) {
      (**(code **)(this->paint_elevation_list->_padding_ + 0x14))(0);
      (**(code **)(this->paint_terrain_list->_padding_ + 0x14))(0);
      (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(0);
      (**(code **)(this->brush_size_label->_padding_ + 0x14))(0);
      ppTVar1 = this->brush_size_button_label;
      iVar2 = 5;
      do {
        (**(code **)(((TButtonPanel *)ppTVar1[-5])->_padding_ + 0x14))(0);
        (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
        ppTVar1 = ppTVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar3 == 0) goto LAB_004aacf6;
      iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
      set_elevation(this,(short)iVar3);
      (**(code **)(rge_base_game->_padding_ + 0x10))(0x13,0);
    }
    val = val + PaintTypeTerrain;
  } while ((int)val < 2);
  this->paint_type = param_1;
  TButtonPanel::set_radio_button(this->paint_type_button[param_1 - PaintTypeTerrain]);
  (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_terrain
// Address: 004aad50
void __thiscall TRIBE_Screen_Sed::set_terrain(TRIBE_Screen_Sed *this,short param_1)
{
  short sVar1;
  
  switch(param_1) {
  default:
    sVar1 = 0;
    break;
  case 1:
    sVar1 = 6;
    break;
  case 2:
    sVar1 = 10;
    break;
  case 3:
    sVar1 = 1;
    break;
  case 4:
    sVar1 = 0xd;
    break;
  case 5:
    sVar1 = 0x14;
    break;
  case 6:
    sVar1 = 4;
    break;
  case 7:
    sVar1 = 0x13;
    break;
  case 8:
    sVar1 = 0x16;
  }
  rge_base_game->terrain_id = sVar1;
  TListPanel::scroll_cur_line(this->paint_terrain_list,'\x01',param_1,1);
  return;
}

// --------------------------------------------------

// Function: set_elevation
// Address: 004aadf0
void __thiscall TRIBE_Screen_Sed::set_elevation(TRIBE_Screen_Sed *this,short param_1)
{
  rge_base_game->elevation_height = param_1;
  TListPanel::scroll_cur_line(this->paint_elevation_list,'\x01',param_1,1);
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 004aae20
// [HELPER] s__d: "%d"
void __thiscall
TRIBE_Screen_Sed::set_player(TRIBE_Screen_Sed *this,short param_1,uchar param_2,uchar param_3)
{
  uchar uVar1;
  RGE_Player *this_00;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined2 in_stack_00000006;
  long lVar5;
  char str [30];
  
  uVar1 = param_2;
  _param_2 = (uint)param_2;
  iVar4 = this->player_num + -1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  this_00 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(this_00);
  if (uVar1 != '\0') {
    pcVar2 = TEditPanel::currentLine(this->player_inven_input[0]);
    iVar3 = atoi(pcVar2);
    T_Scenario::Set_player_Food((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    **(float **)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) = (float)iVar3;
    pcVar2 = TEditPanel::currentLine(this->player_inven_input[1]);
    iVar3 = atoi(pcVar2);
    T_Scenario::Set_player_Wood((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 4) =
         (float)iVar3;
    pcVar2 = TEditPanel::currentLine(this->player_inven_input[2]);
    iVar3 = atoi(pcVar2);
    T_Scenario::Set_player_Stone((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 8) =
         (float)iVar3;
    pcVar2 = TEditPanel::currentLine(this->player_inven_input[3]);
    _param_2 = atoi(pcVar2);
    T_Scenario::Set_player_Gold((T_Scenario *)this->world->_padding_,iVar4,_param_2);
    *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 0xc) =
         (float)(int)_param_2;
    pcVar2 = TEditPanel::currentLine(this->player_inven_input[4]);
    RGE_Scenario::SetPlayerName((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2);
    iVar3 = TDropDownPanel::currentLineNumber(this->player_setting_drop[0]);
    RGE_Scenario::Set_player_Type((RGE_Scenario *)this->world->_padding_,iVar4,iVar3);
    iVar3 = TDropDownPanel::currentLineNumber(this->player_setting_drop[1]);
    RGE_Scenario::Set_player_Civ((RGE_Scenario *)this->world->_padding_,iVar4,iVar3 + 1);
    iVar3 = 0;
    pcVar2 = TDropDownPanel::currentLine(this->AiRules);
    RGE_Scenario::Set_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
    iVar3 = 0;
    pcVar2 = TDropDownPanel::currentLine(this->BuildList);
    RGE_Scenario::Set_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
    iVar3 = 0;
    pcVar2 = TDropDownPanel::currentLine(this->CityLayout);
    RGE_Scenario::Set_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
  }
  iVar4 = param_1 + -1;
  this->player_num = param_1;
  if (param_1 != 0) {
    TDropDownPanel::set_line(this->player_list,iVar4);
    (**(code **)(rge_base_game->_padding_ + 0x14))(_param_1);
    if (param_2 == '\x01') {
      iVar3 = T_Scenario::Get_player_Food((T_Scenario *)this->world->_padding_,iVar4);
      sprintf(str,&s__d,iVar3);
      TEditPanel::set_text(this->player_inven_input[0],str);
      iVar3 = T_Scenario::Get_player_Wood((T_Scenario *)this->world->_padding_,iVar4);
      sprintf(str,&s__d,iVar3);
      TEditPanel::set_text(this->player_inven_input[1],str);
      iVar3 = T_Scenario::Get_player_Stone((T_Scenario *)this->world->_padding_,iVar4);
      sprintf(str,&s__d,iVar3);
      TEditPanel::set_text(this->player_inven_input[2],str);
      iVar3 = T_Scenario::Get_player_Gold((T_Scenario *)this->world->_padding_,iVar4);
      sprintf(str,&s__d,iVar3);
      TEditPanel::set_text(this->player_inven_input[3],str);
      pcVar2 = RGE_Scenario::GetPlayerName((RGE_Scenario *)this->world->_padding_,iVar4);
      TEditPanel::set_text(this->player_inven_input[4],pcVar2);
      iVar3 = RGE_Scenario::Get_player_Type((RGE_Scenario *)this->world->_padding_,iVar4);
      TDropDownPanel::setCurrentLineNumber(this->player_setting_drop[0],iVar3);
      iVar3 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)this->world->_padding_,iVar4);
      TDropDownPanel::setCurrentLineNumber(this->player_setting_drop[1],iVar3 + -1);
      pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
      iVar3 = TDropDownPanel::get_line(this->AiRules,pcVar2);
      if (iVar3 == -1) {
        lVar5 = 0;
        pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
        TDropDownPanel::append_line(this->AiRules,pcVar2,lVar5);
        pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
        iVar3 = TDropDownPanel::get_line(this->AiRules,pcVar2);
      }
      TDropDownPanel::setCurrentLineNumber(this->AiRules,iVar3);
      pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
      iVar3 = TDropDownPanel::get_line(this->BuildList,pcVar2);
      if (iVar3 == -1) {
        lVar5 = 0;
        pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
        TDropDownPanel::append_line(this->BuildList,pcVar2,lVar5);
        pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
        iVar3 = TDropDownPanel::get_line(this->BuildList,pcVar2);
      }
      TDropDownPanel::setCurrentLineNumber(this->BuildList,iVar3);
      pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
      iVar3 = TDropDownPanel::get_line(this->CityLayout,pcVar2);
      if (iVar3 == -1) {
        lVar5 = 0;
        pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
        TDropDownPanel::append_line(this->CityLayout,pcVar2,lVar5);
        pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
        iVar3 = TDropDownPanel::get_line(this->CityLayout,pcVar2);
      }
      TDropDownPanel::setCurrentLineNumber(this->CityLayout,iVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_player_active
// Address: 004ab2b0
void __thiscall
TRIBE_Screen_Sed::set_player_active(TRIBE_Screen_Sed *this,short param_1,int param_2)
{
  RGE_Scenario::Set_player_Active((RGE_Scenario *)this->world->_padding_,(int)param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: set_unit_player
// Address: 004ab300
void __thiscall TRIBE_Screen_Sed::set_unit_player(TRIBE_Screen_Sed *this,short param_1)
{
  char cVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  RGE_Player *pRVar6;
  List_Info *pLVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short unaff_BX;
  short sVar13;
  char *pcVar14;
  undefined4 *puVar15;
  short sVar16;
  char *pcVar17;
  List_Info *pLVar18;
  undefined2 in_stack_00000006;
  int is_error;
  float save_view_x;
  short end_i;
  
  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
  fVar3 = pRVar6->view_x;
  sVar16 = pRVar6->map_x;
  save_view_x = (float)CONCAT22(save_view_x._2_2_,pRVar6->map_y);
  (**(code **)(rge_base_game->_padding_ + 0x14))(_param_1);
  this->player_num = param_1;
  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::set_view_loc(pRVar6,save_view_x,fVar3);
  RGE_Player::set_map_loc(pRVar6,sVar16,unaff_BX);
  RGE_View::set_player((RGE_View *)this->main_view,pRVar6);
  RGE_Diamond_Map::set_player((RGE_Diamond_Map *)this->map_view,pRVar6);
  TDropDownPanel::setCurrentLineNumber(this->unit_player_list,(int)param_1);
  TTextPanel::empty_list((TTextPanel *)this->unit_list);
  if (this->unit_list_info != (List_Info *)0x0) {
    free(this->unit_list_info);
    this->unit_list_info = (List_Info *)0x0;
  }
  if (pRVar6 != (RGE_Player *)0x0) {
    this->unit_list_size = 1;
    sVar16 = pRVar6->master_object_num;
    if (0 < sVar16) {
      iVar9 = 0;
      iVar12 = (int)sVar16;
      do {
        iVar4 = *(int *)(iVar9 + (int)pRVar6->master_objects);
        if ((iVar4 != 0) && (*(char *)(iVar4 + 0x4e) == '\0')) {
          this->unit_list_size = this->unit_list_size + 1;
        }
        iVar9 = iVar9 + 4;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    if (this->unit_list_size != 0) {
      pLVar7 = (List_Info *)calloc((int)this->unit_list_size,0x66);
      this->unit_list_info = pLVar7;
      if (pLVar7 != (List_Info *)0x0) {
        pLVar7->id = -1;
        set_string(this,this->unit_list_info->text,0x2775,0x14);
        is_error = 1;
        sVar13 = 0;
        if (0 < sVar16) {
          save_view_x = 0.0;
          do {
            iVar9 = *(int *)((int)save_view_x + (int)pRVar6->master_objects);
            if ((iVar9 != 0) && (*(char *)(iVar9 + 0x4e) == '\0')) {
              iVar12 = (int)(short)is_error;
              this->unit_list_info[iVar12].id = sVar13;
              iVar9 = *(int *)((int)save_view_x + (int)pRVar6->master_objects);
              sVar2 = *(short *)(iVar9 + 0xc);
              if (sVar2 < 1) {
                uVar10 = 0xffffffff;
                pcVar14 = *(char **)(iVar9 + 8);
                do {
                  pcVar17 = pcVar14;
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  pcVar17 = pcVar14 + 1;
                  cVar1 = *pcVar14;
                  pcVar14 = pcVar17;
                } while (cVar1 != '\0');
                uVar10 = ~uVar10;
                pcVar14 = pcVar17 + -uVar10;
                pLVar7 = this->unit_list_info + iVar12;
                for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(undefined4 *)pLVar7->text = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pLVar7 = (List_Info *)(pLVar7->text + 4);
                }
                for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                  pLVar7->text[0] = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pLVar7 = (List_Info *)(pLVar7->text + 1);
                }
              }
              else {
                (**(code **)(rge_base_game->_padding_ + 0x20))
                          ((int)sVar2,this->unit_list_info + iVar12,100);
              }
              is_error = is_error + 1;
            }
            sVar13 = sVar13 + 1;
            save_view_x = (float)((int)save_view_x + 4);
          } while (sVar13 < sVar16);
        }
        qsort(this->unit_list_info,(int)this->unit_list_size,0x66,TRIBE_Screen_Sed_unit_list_compare
             );
        iVar9 = calloc((int)this->unit_list_size,4);
        if (iVar9 != 0) {
          bVar5 = false;
          sVar16 = 0;
          sVar13 = 0;
          if (0 < this->unit_list_size) {
            do {
              puVar8 = (undefined4 *)calloc(100,1);
              iVar12 = (int)sVar13;
              *(undefined4 **)(iVar9 + iVar12 * 4) = puVar8;
              if (puVar8 == (undefined4 *)0x0) {
                bVar5 = true;
                break;
              }
              uVar10 = 0xffffffff;
              pLVar7 = this->unit_list_info + iVar12;
              do {
                pLVar18 = pLVar7;
                if (uVar10 == 0) break;
                uVar10 = uVar10 - 1;
                pLVar18 = (List_Info *)(pLVar7->text + 1);
                pcVar14 = pLVar7->text;
                pLVar7 = pLVar18;
              } while (*pcVar14 != '\0');
              uVar10 = ~uVar10;
              puVar15 = (undefined4 *)((int)pLVar18 - uVar10);
              for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar8 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar8 = puVar8 + 1;
              }
              for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar8 = *(undefined1 *)puVar15;
                puVar15 = (undefined4 *)((int)puVar15 + 1);
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
              if (this->unit_list_info[iVar12].id == rge_base_game->master_obj_id) {
                sVar16 = sVar13;
              }
              sVar13 = sVar13 + 1;
            } while (sVar13 < this->unit_list_size);
          }
          if (!bVar5) {
            (**(code **)(this->unit_list->_padding_ + 0xe0))(iVar9,this->unit_list_size);
            TListPanel::scroll_cur_line(this->unit_list,'\x01',sVar16,1);
          }
          sVar16 = 0;
          if (0 < this->unit_list_size) {
            do {
              iVar12 = *(int *)(iVar9 + sVar16 * 4);
              if (iVar12 != 0) {
                free(iVar12);
              }
              sVar16 = sVar16 + 1;
            } while (sVar16 < this->unit_list_size);
          }
          free(iVar9);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_unit
// Address: 004ab670
void __thiscall TRIBE_Screen_Sed::set_unit(TRIBE_Screen_Sed *this,short param_1)
{
  if (param_1 == -1) {
    rge_base_game->master_obj_id = -1;
    TListPanel::scroll_cur_line(this->unit_list,'\x01',-1,1);
    return;
  }
  rge_base_game->master_obj_id = this->unit_list_info[param_1].id;
  TListPanel::scroll_cur_line(this->unit_list,'\x01',param_1,1);
  return;
}

// --------------------------------------------------

// Function: set_message_type
// Address: 004ab6e0
void __thiscall
TRIBE_Screen_Sed::set_message_type(TRIBE_Screen_Sed *this,MessageType param_1,int param_2)
{
  (**(code **)(this->message_input->_padding_ + 0x14))(param_2);
  (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: handle_size
// Address: 004ab710
long __thiscall TRIBE_Screen_Sed::handle_size(TRIBE_Screen_Sed *this,long param_1,long param_2)
{
  TPanel::handle_size((TPanel *)this,param_1,param_2);
  position_panels(this);
  TPanel::handle_size((TPanel *)this,param_1,param_2);
  return 0;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004ab740
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
long __thiscall TRIBE_Screen_Sed::handle_idle(TRIBE_Screen_Sed *this)
{
  ulong uVar1;
  TPanel *pTVar2;
  long lVar3;
  
  if (rge_base_game->prog_mode == 7) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x8b1);
    if (this->update_interval <= this->last_update_time - uVar1) {
      pTVar2 = TPanelSystem::modalPanel(&panel_system);
      if (pTVar2 == (TPanel *)0x0) {
        (**(code **)(*(int *)this->main_view + 0x20))(1);
        if (this->map_redraw_interval <= this->last_map_redraw_time - uVar1) {
          (**(code **)(*(int *)this->map_view + 0x20))(1);
          this->last_map_redraw_time = uVar1;
        }
      }
    }
  }
  lVar3 = TPanel::handle_idle((TPanel *)this);
  return lVar3;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 004ab7d0
long __thiscall
TRIBE_Screen_Sed::key_down_action
          (TRIBE_Screen_Sed *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  ScenarioMode SVar1;
  RGE_Static_Object *pRVar2;
  uchar uVar3;
  TPanel *pTVar4;
  int iVar5;
  RGE_Player *pRVar6;
  short sVar7;
  
  pTVar4 = TPanelSystem::modalPanel(&panel_system);
  if (pTVar4 == (TPanel *)0x0) {
    if (param_4 != 0) {
      switch(param_1) {
      case 0x41:
        if (rge_base_game->outline_type != '\x03') {
          rge_base_game->outline_type = '\x03';
          return 1;
        }
        rge_base_game->outline_type = '\0';
        return 1;
      case 0x42:
        goto switchD_004ab80d_caseD_42;
      case 0x43:
        (**(code **)(this->scenario_mode_button[9]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeCinematics);
        return 0;
      case 0x44:
        (**(code **)(this->scenario_mode_button[4]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeDiplomacy);
        return 0;
      default:
        goto switchD_004ab80d_caseD_45;
      case 0x49:
        (**(code **)(this->scenario_mode_button[5]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeVictory);
        return 0;
      case 0x4d:
        (**(code **)(this->scenario_mode_button[0]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeMap);
        return 0;
      case 0x4f:
        (**(code **)(this->scenario_mode_button[7]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeOptions);
        return 0;
      case 0x50:
        (**(code **)(this->scenario_mode_button[2]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModePlayers);
        return 0;
      case 0x54:
        (**(code **)(this->scenario_mode_button[1]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeTerrain);
        return 0;
      case 0x55:
        (**(code **)(this->scenario_mode_button[3]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeUnits);
        return 0;
      case 0x56:
        (**(code **)(this->scenario_mode_button[6]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeVictoryMulti);
        return 0;
      case 0x57:
        (**(code **)(this->scenario_mode_button[8]->_padding_ + 0xe0))(1);
        set_scenario_mode(this,ScenarioModeMessages);
        return 0;
      }
    }
    switch(param_1) {
    case 9:
      if (this->scenario_mode == ScenarioModePlayers) {
        if (this->bottom_panel->curr_child == (TPanel *)0x0) {
          TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->player_inven_input[0]);
          return 0;
        }
      }
      else if (((this->scenario_mode == ScenarioModeVictory) &&
               (this->bottom_panel->curr_child == (TPanel *)0x0)) &&
              (this->victory_amount_input->_padding_ != 0)) {
        TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
        return 0;
      }
      break;
    case 0x1b:
      command_cancel(this);
      return 0;
    case 0x2e:
      if (this->scenario_mode == ScenarioModeUnits) {
        pRVar6 = RGE_Base_Game::get_player(rge_base_game);
        pRVar2 = pRVar6->selected_obj;
        if (pRVar2 != (RGE_Static_Object *)0x0) {
          if (pRVar2->sprite_list == (RGE_Active_Sprite_List *)0x0) {
            if (pRVar2->sprite == (RGE_Sprite *)0x0) {
              uVar3 = '\x14';
            }
            else {
              uVar3 = RGE_Sprite::get_lowest_draw_level(pRVar2->sprite);
            }
          }
          else {
            uVar3 = RGE_Active_Sprite_List::get_lowest_draw_level(pRVar2->sprite_list);
          }
          (**(code **)pRVar2->_padding_)(1);
          if (uVar3 == '\0') {
            (**(code **)(*(int *)this->main_view + 0x20))(2);
          }
        }
        return 1;
      }
      break;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
      SVar1 = this->scenario_mode;
      iVar5 = param_1 + -0x30;
      sVar7 = (short)iVar5;
      if ((SVar1 == ScenarioModeOptions) && (0 < iVar5)) {
        SaveDisabledItemsInScenario(this);
        TDropDownPanel::setCurrentLineNumber(this->options_player_list,param_1 + -0x31);
        (**(code **)(this->_padding_ + 0xb4))(this->options_player_list,3,0,0);
        set_player(this,sVar7,'\0','\0');
        this->player_num = sVar7;
        LoadDisabledItemsFromScenario(this);
        return 0;
      }
      if ((SVar1 == ScenarioModePlayers) && (0 < iVar5)) {
        if (this->bottom_panel->curr_child == (TPanel *)0x0) {
          TDropDownPanel::setCurrentLineNumber(this->player_list,param_1 + -0x31);
          (**(code **)(this->_padding_ + 0xb4))(this->player_list,0,0,0);
          return 0;
        }
      }
      else {
        if (SVar1 == ScenarioModeUnits) {
          TDropDownPanel::setCurrentLineNumber(this->unit_player_list,iVar5);
          (**(code **)(this->_padding_ + 0xb4))(this->unit_player_list,0,0,0);
          return 0;
        }
        if ((SVar1 == ScenarioModeVictory) && (0 < iVar5)) {
          if (this->bottom_panel->curr_child == (TPanel *)0x0) {
            TDropDownPanel::setCurrentLineNumber(this->victory_player_list,param_1 + -0x31);
            (**(code **)(this->_padding_ + 0xb4))(this->victory_player_list,1,0,0);
            return 0;
          }
        }
        else if (SVar1 == ScenarioModeDiplomacy) {
          if (0 < iVar5) {
            TDropDownPanel::setCurrentLineNumber(this->Diplomacy_player_list,param_1 + -0x31);
            (**(code **)(this->_padding_ + 0xb4))(this->Diplomacy_player_list,1,0,0);
            return 0;
          }
        }
        else if (0 < iVar5) {
          set_player(this,sVar7,'\0','\0');
          this->player_num = sVar7;
          return 0;
        }
      }
    }
  }
switchD_004ab80d_caseD_45:
  return 0;
switchD_004ab80d_caseD_42:
  View_Grid_Mode = View_Grid_Mode + 1;
  iVar5 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
  if (iVar5 == 0) {
    if (View_Grid_Mode < 2) goto LAB_004ab9ba;
  }
  else if (View_Grid_Mode < 5) goto LAB_004ab9ba;
  View_Grid_Mode = 0;
LAB_004ab9ba:
  (**(code **)(*(int *)this->main_view + 0x20))(2);
  return 0;
}

// --------------------------------------------------

// Function: action
// Address: 004abcd0
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
long __thiscall
TRIBE_Screen_Sed::action
          (TRIBE_Screen_Sed *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  byte bVar1;
  TRIBE_World *pTVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  RGE_Player *pRVar6;
  char *pcVar7;
  byte *pbVar8;
  TRIBE_Player *pTVar9;
  TButtonPanel **ppTVar10;
  TRIBE_Screen_Sed_Open *this_00;
  TEditPanel **ppTVar11;
  RGE_Static_Object *pRVar12;
  byte *pbVar13;
  float fVar14;
  float *unaff_FS_OFFSET;
  bool bVar15;
  uchar uVar16;
  float fVar17;
  RGE_Master_Static_Object *pRVar18;
  uchar uVar19;
  int iVar20;
  int iVar21;
  long x2;
  long x1;
  long y1;
  long y2;
  char random_val [24];
  float local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f48b;
  *unaff_FS_OFFSET = (float)&local_c;
  if (param_1 == (TPanel *)0x0) {
    lVar5 = 0;
    goto LAB_004abe5f;
  }
  if ((TRIBE_Main_View *)param_1 != this->main_view) {
    pRVar12 = this->SelectedObject;
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      iVar20 = 0;
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
    }
    pRVar12 = this->DestinationObject;
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      iVar20 = 0;
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
    }
  }
  if ((param_2 == 0) &&
     ((((((((TEditPanel *)param_1 == this->random_seed_input ||
           ((TEditPanel *)param_1 == this->player_inven_input[0])) ||
          ((TEditPanel *)param_1 == this->player_inven_input[1])) ||
         (((TEditPanel *)param_1 == this->player_inven_input[2] ||
          ((TEditPanel *)param_1 == this->player_inven_input[3])))) ||
        ((TEditPanel *)param_1 == this->player_inven_input[4])) ||
       ((((TTextPanel *)param_1 == this->player_setting_label[0] ||
         ((TEditPanel *)param_1 == this->victory_condition_explore)) ||
        (((TEditPanel *)param_1 == this->victory_condition_ruins ||
         ((((TEditPanel *)param_1 == this->victory_condition_artifacts ||
           ((TEditPanel *)param_1 == this->victory_condition_discoveries)) ||
          ((TEditPanel *)param_1 == this->victory_condition_gold)))))))) ||
      (((TEditPanel *)param_1 == this->victory_amount_input ||
       ((TEditPanel *)param_1 == this->message_input)))))) {
    this->need_to_save_flag = '\x01';
  }
  if ((TRIBE_Main_View *)param_1 == this->main_view) {
    if (param_2 != 0x10) {
      if ((param_2 == 0x11) && (rge_base_game->game_mode == 0x11)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))();
      }
      goto LAB_004abe90;
    }
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_object(pRVar6);
    if (this->SelectRegionFlag == SELECT_OBJECT) {
      this->SelectedObject = (RGE_Static_Object *)param_3;
    }
    if (this->SelectRegionFlag == SELECT_DEST_OBJECT) {
      this->DestinationObject = (RGE_Static_Object *)param_3;
    }
    pRVar12 = this->SelectedObject;
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      iVar20 = 0;
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
    }
    pRVar12 = this->DestinationObject;
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      iVar20 = 0;
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
    }
    (**(code **)(rge_base_game->_padding_ + 0x10))();
  }
  else {
LAB_004abe90:
    if (param_2 == 1) {
      iVar20 = 0;
      ppTVar10 = this->scenario_mode_button;
      do {
        if ((TButtonPanel *)param_1 == *ppTVar10) {
          set_scenario_mode(this,iVar20 + ScenarioModeMap);
          goto LAB_004abe5a;
        }
        iVar20 = iVar20 + 1;
        ppTVar10 = ppTVar10 + 1;
      } while (iVar20 < 10);
      if ((TButtonPanel *)param_1 == this->menu_button) {
        command_menu(this);
      }
      else {
        if ((TButtonPanel *)param_1 != this->help_button) goto LAB_004abf01;
        TEasy_Panel::setup_popup_help((TEasy_Panel *)this);
      }
    }
    else {
      iVar20 = 0;
      ppTVar10 = this->scenario_mode_button;
      do {
        if ((TButtonPanel *)param_1 == *ppTVar10) goto LAB_004abe5a;
        iVar20 = iVar20 + 1;
        ppTVar10 = ppTVar10 + 1;
      } while (iVar20 < 10);
      if (((TButtonPanel *)param_1 != this->menu_button) &&
         ((TButtonPanel *)param_1 != this->help_button)) {
LAB_004abf01:
        pcVar7 = TPanel::panelName(param_1);
        if (pcVar7 != (char *)0x0) {
          pbVar13 = &s_OKDialog;
          pbVar8 = (byte *)TPanel::panelName(param_1);
          do {
            bVar1 = *pbVar8;
            bVar15 = bVar1 < *pbVar13;
            if (bVar1 != *pbVar13) {
LAB_004abf3c:
              iVar20 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
              goto LAB_004abf41;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar15 = bVar1 < pbVar13[1];
            if (bVar1 != pbVar13[1]) goto LAB_004abf3c;
            pbVar8 = pbVar8 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar1 != 0);
          iVar20 = 0;
LAB_004abf41:
          if (iVar20 == 0) {
            if (param_2 == 0) {
              TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
              set_scenario_mode(this,ScenarioModePlayers);
            }
            goto LAB_004abe5a;
          }
        }
        switch(this->scenario_mode) {
        case ScenarioModeMap:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 1) {
            iVar20 = 0;
            ppTVar10 = this->map_type_button;
            do {
              if ((TButtonPanel *)param_1 == *ppTVar10) {
                set_map_type(this,iVar20 + MapTypeBlank,1);
                goto LAB_004abe5a;
              }
              iVar20 = iVar20 + 1;
              ppTVar10 = ppTVar10 + 1;
            } while (iVar20 < 3);
            if ((TButtonPanel *)param_1 == this->generate_map_button) {
              (**(code **)(this->map_generating_text->_padding_ + 0x14))();
              (**(code **)(this->_padding_ + 0x20))();
              InvalidateRect(rge_base_game->prog_window,0,0);
              RGE_Base_Game::draw_window(rge_base_game);
              iVar20 = TDropDownPanel::currentLineNumber(this->map_size_drop);
              local_c = (float)TDropDownPanel::currentLineNumber(this->map_style_drop);
              fVar14 = local_c;
              switch(iVar20) {
              case 0:
                fVar14 = 1.00893e-43;
                break;
              case 1:
                fVar14 = 1.34525e-43;
                break;
              case 2:
                fVar14 = 1.68156e-43;
                break;
              case 3:
                fVar14 = 2.01787e-43;
                break;
              case 4:
                fVar14 = 2.8026e-43;
                break;
              case 5:
                fVar14 = 3.50325e-43;
              }
              lVar5 = TDropDownPanel::get_line(this->player_number_list);
              if (this->map_type == MapTypeBlank) {
                iVar20 = TDropDownPanel::currentLineNumber(this->default_terrain_drop);
                switch(iVar20) {
                case 0:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\0',(long)fVar14,(long)fVar14);
                  break;
                case 1:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x06',(long)fVar14,(long)fVar14);
                  break;
                case 2:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\n',(long)fVar14,(long)fVar14);
                  break;
                case 3:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x01',(long)fVar14,(long)fVar14);
                  break;
                case 4:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\r',(long)fVar14,(long)fVar14);
                  break;
                case 5:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x14',(long)fVar14,(long)fVar14);
                  break;
                case 6:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x04',(long)fVar14,(long)fVar14);
                  break;
                case 7:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x13',(long)fVar14,(long)fVar14);
                  break;
                case 8:
                  pTVar2 = this->world;
                  RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
                                     (RGE_Game_World *)pTVar2,'\x16',(long)fVar14,(long)fVar14);
                }
              }
              else {
                if (this->map_type == MapTypeSeed) {
                  pcVar7 = TEditPanel::currentLine(this->random_seed_input);
                  iVar20 = atoi(pcVar7);
                  rge_base_game->random_map_seed = iVar20;
                }
                else {
                  rge_base_game->random_map_seed = -1;
                }
                iVar20 = 0;
                do {
                  RGE_Player::reset_selected(*(RGE_Player **)(this->world->_padding_ + iVar20));
                  iVar20 = iVar20 + 4;
                } while (iVar20 < 0x24);
                (**(code **)(*(int *)this->world->_padding_ + 0x28))
                          (this->world,fVar14,fVar14,local_c,lVar5 + 1);
                rge_base_game->random_map_seed = random_val._4_4_;
                itoa(rge_base_game->save_random_map_seed,&stack0xffffffb4,10);
                (**(code **)(this->random_seed_used_text->_padding_ + 0xe8))(&stack0xffffffb4);
                debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp,0xb58);
              }
              iVar20 = 0;
              fVar17 = (float)((int)fVar14 / 2);
              local_c = fVar17;
              do {
                sVar3 = (short)((int)fVar14 / 2);
                RGE_Player::set_map_loc
                          (*(RGE_Player **)(this->world->_padding_ + iVar20),sVar3,sVar3);
                RGE_Player::set_view_loc
                          (*(RGE_Player **)(this->world->_padding_ + iVar20),fVar17,fVar17);
                iVar20 = iVar20 + 4;
              } while (iVar20 < 0x20);
              iVar20 = 0;
              do {
                RGE_Tile_List::del_list
                          ((RGE_Tile_List *)(*(int *)(this->world->_padding_ + iVar20) + 0x58));
                RGE_Player::set_map_visible(*(RGE_Player **)(this->world->_padding_ + iVar20));
                iVar20 = iVar20 + 4;
              } while (iVar20 < 0x20);
              set_panel_info(this);
              (**(code **)(this->map_generating_text->_padding_ + 0x14))(0);
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeTerrain:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if ((param_2 == 2) || (param_2 == 1)) {
            if ((TListPanel *)param_1 == this->paint_terrain_list) {
              iVar20 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_terrain_list);
              set_terrain(this,(short)iVar20);
              (**(code **)(this->brush_size_button[0]->_padding_ + 0x14))();
            }
            else {
              if ((TListPanel *)param_1 != this->paint_elevation_list) {
                if (param_2 == 1) {
                  if (this->valid_save_spot_flag != '\0') {
                    this->need_to_save_flag = '\x01';
                  }
                  iVar20 = 0;
                  ppTVar10 = this->brush_size_button;
                  do {
                    if ((TButtonPanel *)param_1 == *ppTVar10) {
                      set_brush_size(this,iVar20 + BrushSizeVerySmall);
                      goto LAB_004abe5a;
                    }
                    iVar20 = iVar20 + 1;
                    ppTVar10 = ppTVar10 + 1;
                  } while (iVar20 < 5);
                  iVar20 = 0;
                  ppTVar10 = this->paint_type_button;
                  do {
                    if ((TButtonPanel *)param_1 == *ppTVar10) {
                      set_paint_type(this,iVar20 + PaintTypeTerrain,1);
                      goto LAB_004abe5a;
                    }
                    iVar20 = iVar20 + 1;
                    ppTVar10 = ppTVar10 + 1;
                  } while (iVar20 < 3);
                }
                break;
              }
              iVar20 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
              set_elevation(this,(short)iVar20);
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModePlayers:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 0) {
            iVar20 = 0;
            ppTVar11 = this->player_inven_input;
            do {
              if ((TEditPanel *)param_1 == *ppTVar11) {
                TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
                break;
              }
              iVar20 = iVar20 + 1;
              ppTVar11 = ppTVar11 + 1;
            } while (iVar20 < 5);
            if (this->valid_save_spot_flag != '\0') {
              this->need_to_save_flag = '\x01';
            }
            if ((TDropDownPanel *)param_1 == this->player_advance_civilization_drop) {
              if (this->valid_save_spot_flag != '\0') {
                this->need_to_save_flag = '\x01';
              }
              iVar20 = TDropDownPanel::currentLineNumber(this->player_advance_civilization_drop);
              T_Scenario::SetPlayerAge
                        ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar20);
            }
            if ((TDropDownPanel *)param_1 == this->player_list) {
              uVar19 = '\x01';
              uVar16 = '\x01';
              lVar5 = TDropDownPanel::get_line(this->player_list);
              set_player(this,(short)lVar5 + 1,uVar16,uVar19);
              lVar5 = TDropDownPanel::get_line(this->player_list);
              iVar20 = T_Scenario::GetPlayerAge((T_Scenario *)this->world->_padding_,lVar5);
              TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,iVar20);
            }
            if ((TDropDownPanel *)param_1 == this->player_number_list) {
              set_player(this,this->player_num,'\x01','\0');
              SavePlayerActiveStatus(this);
              set_player(this,this->player_num,'\0','\x01');
            }
          }
          if ((param_2 == 1) &&
             ((TDropDownPanel *)param_1 == this->player_advance_civilization_drop)) {
            iVar20 = TDropDownPanel::currentLineNumber(this->player_advance_civilization_drop);
            T_Scenario::SetPlayerAge
                      ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar20);
          }
          break;
        case ScenarioModeUnits:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 0) {
            if (this->valid_save_spot_flag != '\0') {
              this->need_to_save_flag = '\x01';
            }
            if ((TDropDownPanel *)param_1 == this->unit_player_list) {
              lVar5 = TDropDownPanel::get_line(this->unit_player_list);
              set_unit_player(this,(short)lVar5);
              lVar5 = TDropDownPanel::get_line(this->unit_player_list);
              if (lVar5 != 0) {
                (**(code **)(rge_base_game->_padding_ + 0x10))();
                if ((rge_base_game->master_obj_id == -1) ||
                   (pRVar6 = RGE_Base_Game::get_player(rge_base_game), pRVar6 == (RGE_Player *)0x0))
{
                  pTVar9 = (TRIBE_Player *)0x0;
                  pRVar18 = (RGE_Master_Static_Object *)0x0;
                }
                else {
                  sVar3 = rge_base_game->master_obj_id;
                  pTVar9 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
                  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                  pRVar18 = *(RGE_Master_Static_Object **)
                             (*(int *)(*(int *)(this->world->_padding_ + pRVar6->id * 4) + 0x24) +
                             sVar3 * 4);
                }
                TRIBE_Scenario_Editor_Panel_Object::set_master_info
                          (this->object_panel,pRVar18,pTVar9);
                set_paint_object_mode(this);
                (**(code **)(this->object_panel->_padding_ + 0x20))(2);
                goto LAB_004abe5a;
              }
              (**(code **)(rge_base_game->_padding_ + 0x10))();
            }
          }
          if ((param_2 == 2) || (param_2 == 1)) {
            if ((TListPanel *)param_1 == this->unit_list) {
              iVar20 = TTextPanel::currentLineNumber((TTextPanel *)this->unit_list);
              set_unit(this,(short)iVar20);
              if ((rge_base_game->game_mode != 8) && (rge_base_game->game_mode != 0x15)) {
                TButtonPanel::set_radio_button(this->unit_mode_select[0]);
              }
              if ((rge_base_game->master_obj_id == -1) ||
                 (pRVar6 = RGE_Base_Game::get_player(rge_base_game), pRVar6 == (RGE_Player *)0x0)) {
                pTVar9 = (TRIBE_Player *)0x0;
                pRVar18 = (RGE_Master_Static_Object *)0x0;
              }
              else {
                sVar3 = rge_base_game->master_obj_id;
                pTVar9 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
                pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                pRVar18 = *(RGE_Master_Static_Object **)
                           (*(int *)(*(int *)(this->world->_padding_ + pRVar6->id * 4) + 0x24) +
                           sVar3 * 4);
              }
              TRIBE_Scenario_Editor_Panel_Object::set_master_info(this->object_panel,pRVar18,pTVar9)
              ;
              set_paint_object_mode(this);
              (**(code **)(this->object_panel->_padding_ + 0x20))();
              goto LAB_004abe5a;
            }
            if (param_2 == 1) {
              if ((TButtonPanel *)param_1 == this->unit_mode_select[0]) {
                set_paint_object_mode(this);
              }
              else if ((TButtonPanel *)param_1 == this->unit_mode_select[1]) {
                pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                RGE_Player::unselect_object(pRVar6);
                (**(code **)(rge_base_game->_padding_ + 0x10))();
              }
              else if ((TButtonPanel *)param_1 == this->unit_mode_select[2]) {
                (**(code **)(rge_base_game->_padding_ + 0x10))();
              }
              else if ((TButtonPanel *)param_1 == this->unit_mode_select[3]) {
                (**(code **)(rge_base_game->_padding_ + 0x10))();
              }
            }
          }
          break;
        case ScenarioModeDiplomacy:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if ((param_2 == 0) || (param_2 == 1)) {
            if ((TDropDownPanel *)param_1 == this->Diplomacy_player_list) {
              (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][0]->_padding_ + 0x14))
                        ();
              (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][1]->_padding_ + 0x14))
                        ();
              (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][2]->_padding_ + 0x14))
                        (1);
              (**(code **)(this->Diplomacy_AlliedVictory[this->player_num + -1]->_padding_ + 0x14))
                        (0);
              lVar5 = TDropDownPanel::get_line(this->Diplomacy_player_list);
              sVar3 = (short)lVar5 + 1;
              this->player_num = sVar3;
              (**(code **)(this->Diplomacy_friend_box[sVar3 + -1][0]->_padding_ + 0x14))(0);
              (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][1]->_padding_ + 0x14))
                        (0);
              (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][2]->_padding_ + 0x14))
                        (0);
              (**(code **)(this->Diplomacy_AlliedVictory[this->player_num + -1]->_padding_ + 0x14))
                        (1);
              lVar5 = TDropDownPanel::get_line(this->Diplomacy_player_list);
              load_diplomacy_from_scenario(this,lVar5);
            }
            if (param_2 == 1) {
              save_diplomacy_in_scenario(this,this->player_num + -1);
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeVictory:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (((param_2 == 0) || (param_2 == 1)) &&
             ((TDropDownPanel *)param_1 == this->victory_player_list)) {
            save_victory_cond_in_scenario(this,this->CurrentVictory);
            activate_victory_panel(this,0);
            activate_victory_proper_fields(this,0,0);
            lVar5 = TDropDownPanel::get_line(this->victory_player_list);
            sVar3 = (short)lVar5 + 1;
            this->player_num = sVar3;
            T_Scenario::SetSPWhich((T_Scenario *)this->world->_padding_,sVar3 + -1);
            this->CurrentVictory = 0;
            load_victory_cond_from_scenario(this,0);
            activate_victory_panel(this,1);
            iVar20 = 1;
            lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
            activate_victory_proper_fields(this,lVar5,iVar20);
          }
          if ((param_2 == 0) && ((TEditPanel *)param_1 == this->victory_amount_input)) {
            TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
          }
          if ((param_2 == 2) && ((TDropDownPanel *)param_1 == this->victory_drop_down)) {
            iVar20 = 1;
            lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
            activate_victory_proper_fields(this,lVar5,iVar20);
          }
          if (param_2 == 1) {
            if ((TEditPanel *)param_1 != this->victory_amount_input) {
              lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
              if ((TDropDownPanel *)param_1 == this->victory_drop_down) {
                (**(code **)(rge_base_game->_padding_ + 0x10))();
                this->DestinationObject = (RGE_Static_Object *)0x0;
                this->SelectedObject = (RGE_Static_Object *)0x0;
                pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                RGE_Player::unselect_object(pRVar6);
              }
              if (lVar5 == 2) {
                this->DestinationObject = (RGE_Static_Object *)0x0;
                pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                RGE_Player::unselect_object(pRVar6);
              }
              if ((TButtonPanel *)param_1 == this->victory_button_set_object) {
                this->SelectRegionFlag = SELECT_OBJECT;
                (**(code **)(rge_base_game->_padding_ + 0x10))();
                pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                RGE_Player::unselect_object(pRVar6);
                pRVar12 = this->DestinationObject;
LAB_004ac2a8:
                if (pRVar12 != (RGE_Static_Object *)0x0) {
                  iVar20 = 0;
                  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                  RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
                }
              }
              else {
                if ((TButtonPanel *)param_1 == this->victory_button_set_destination) {
                  if (lVar5 != 1) {
                    this->SelectRegionFlag = SELECT_AREA;
                    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::unselect_object(pRVar6);
                    pRVar12 = this->SelectedObject;
                    if (pRVar12 != (RGE_Static_Object *)0x0) {
                      iVar20 = 0;
                      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                      RGE_Player::select_one_object(pRVar6,pRVar12,iVar20);
                    }
                    (**(code **)(rge_base_game->_padding_ + 0x10))();
                    goto LAB_004abe5a;
                  }
                  if ((TButtonPanel *)param_1 == this->victory_button_set_destination) {
                    this->SelectRegionFlag = SELECT_DEST_OBJECT;
                    (**(code **)(rge_base_game->_padding_ + 0x10))();
                    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::unselect_object(pRVar6);
                    pRVar12 = this->SelectedObject;
                    goto LAB_004ac2a8;
                  }
                }
                if (((TButtonPanel *)param_1 != this->victory_button_go_to_dest) || (lVar5 == 1)) {
                  if ((TDropDownPanel *)param_1 == this->victory_drop_down) {
                    iVar20 = 0;
                    lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
                    activate_victory_proper_fields(this,lVar5,iVar20);
                  }
                  iVar20 = 0;
                  ppTVar10 = this->victory_button;
                  do {
                    if (((TButtonPanel *)param_1 == *ppTVar10) && (this->CurrentVictory != iVar20))
{
                      iVar21 = 0;
                      lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
                      activate_victory_proper_fields(this,lVar5,iVar21);
                      save_victory_cond_in_scenario(this,this->CurrentVictory);
                      activate_victory_panel(this,0);
                      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                      RGE_Player::unselect_object(pRVar6);
                      this->CurrentVictory = iVar20;
                      load_victory_cond_from_scenario(this,iVar20);
                      activate_victory_panel(this,1);
                      iVar21 = 1;
                      lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
                      activate_victory_proper_fields(this,lVar5,iVar21);
                      pRVar12 = this->SelectedObject;
                      if (pRVar12 != (RGE_Static_Object *)0x0) {
                        iVar21 = 0;
                        pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                        RGE_Player::select_one_object(pRVar6,pRVar12,iVar21);
                      }
                      pRVar12 = this->DestinationObject;
                      if (pRVar12 != (RGE_Static_Object *)0x0) {
                        iVar21 = 0;
                        pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                        RGE_Player::select_one_object(pRVar6,pRVar12,iVar21);
                      }
                    }
                    iVar20 = iVar20 + 1;
                    ppTVar10 = ppTVar10 + 1;
                  } while (iVar20 < 0xc);
                  break;
                }
                RGE_View::get_selection_area
                          ((RGE_View *)this->main_view,&y1,&y2,&x1,(long *)random_val,1);
                fVar17 = (float)x1;
                bVar15 = fVar17 != _DAT_00573ae8;
                fVar14 = (float)(int)random_val._0_4_;
                this->px1 = (float)y1;
                this->py1 = (float)y2;
                this->SelectRegionFlag = SELECT_OFF;
                this->px2 = (float)x1;
                this->py2 = fVar14;
                if (bVar15) {
                  fVar17 = fVar17 - (fVar17 - (float)y1) * _DAT_00573aec;
                  fVar14 = fVar14 - (fVar14 - (float)y2) * _DAT_00573aec;
                  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                  RGE_Player::set_view_loc(pRVar6,fVar17,fVar14);
                  sVar3 = __ftol();
                  sVar4 = __ftol();
                  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
                  RGE_Player::set_map_loc(pRVar6,sVar4,sVar3);
                }
              }
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModeVictoryMulti:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 1) {
            iVar20 = 0;
            ppTVar10 = this->victory_cond_type;
            do {
              if ((TButtonPanel *)param_1 == *ppTVar10) {
                set_mp_victory_type(this,iVar20 + VictoryTypeStandard,1);
                if (iVar20 != 4) {
                  T_Scenario::Set_Multi_Conquest((T_Scenario *)this->world->_padding_,1);
                  (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
                }
                goto LAB_004abe5a;
              }
              iVar20 = iVar20 + 1;
              ppTVar10 = ppTVar10 + 1;
            } while (iVar20 < 5);
          }
          break;
        case ScenarioModeOptions:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 1) {
            SaveDisabledItemsInScenario(this);
            LoadDisabledItemsFromScenario(this);
            if ((TButtonPanel *)param_1 == this->options_button[0]) {
              iVar20 = TButtonPanel::get_state(this->options_button[0]);
              T_Scenario::SetScenarioOption((T_Scenario *)this->world->_padding_,2,iVar20);
            }
          }
          break;
        case ScenarioModeMessages:
          if (this->valid_save_spot_flag != '\0') {
            this->need_to_save_flag = '\x01';
          }
          if (param_2 == 1) {
            lVar5 = this->current_message;
            pcVar7 = TEditPanel::get_input_buffer(this->message_input);
            RGE_Scenario::Set_message((RGE_Scenario *)this->world->_padding_,pcVar7,lVar5);
            iVar20 = 0;
            ppTVar10 = this->message_button;
            do {
              if ((TButtonPanel *)param_1 == *ppTVar10) {
                this->current_message = iVar20;
                break;
              }
              iVar20 = iVar20 + 1;
              ppTVar10 = ppTVar10 + 1;
            } while (iVar20 < 5);
            pcVar7 = RGE_Scenario::Get_message
                               ((RGE_Scenario *)this->world->_padding_,this->current_message);
            TEditPanel::set_text(this->message_input,pcVar7);
            switch(this->current_message) {
            case 0:
              TPanel::set_help_info((TPanel *)this->message_input,0x7770,-1);
              break;
            case 1:
              TPanel::set_help_info((TPanel *)this->message_input,0x7771,-1);
              break;
            case 2:
              TPanel::set_help_info((TPanel *)this->message_input,0x7772,-1);
              break;
            case 3:
              TPanel::set_help_info((TPanel *)this->message_input,0x7773,-1);
              break;
            case 4:
              TPanel::set_help_info((TPanel *)this->message_input,0x7774,-1);
            }
          }
        }
        pcVar7 = TPanel::panelName(param_1);
        uVar16 = (uchar)param_2;
        if (pcVar7 != (char *)0x0) {
          pbVar13 = &s_QuitSaveDialog;
          pbVar8 = (byte *)TPanel::panelName(param_1);
          do {
            bVar1 = *pbVar8;
            bVar15 = bVar1 < *pbVar13;
            if (bVar1 != *pbVar13) {
LAB_004ace86:
              iVar20 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
              goto LAB_004ace8b;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar15 = bVar1 < pbVar13[1];
            if (bVar1 != pbVar13[1]) goto LAB_004ace86;
            pbVar8 = pbVar8 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar1 != 0);
          iVar20 = 0;
LAB_004ace8b:
          if (iVar20 == 0) {
            TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
            TPanelSystem::destroyPanel(&panel_system,&s_QuitSaveDialog);
            if (param_2 == 0) {
              command_save(this,uVar16,'\x01');
            }
            else if (param_2 == 1) {
              iVar20 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
              if (iVar20 == 0) {
                RGE_Base_Game::close(rge_base_game);
              }
              else {
                TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
              }
            }
            goto LAB_004abe5a;
          }
        }
        pcVar7 = TPanel::panelName(param_1);
        if (pcVar7 != (char *)0x0) {
          pbVar13 = &s_OpenSaveDialog;
          pbVar8 = (byte *)TPanel::panelName(param_1);
          do {
            bVar1 = *pbVar8;
            bVar15 = bVar1 < *pbVar13;
            if (bVar1 != *pbVar13) {
LAB_004acf3c:
              iVar20 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
              goto LAB_004acf41;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar15 = bVar1 < pbVar13[1];
            if (bVar1 != pbVar13[1]) goto LAB_004acf3c;
            pbVar8 = pbVar8 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar1 != 0);
          iVar20 = 0;
LAB_004acf41:
          if (iVar20 == 0) {
            TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
            TPanelSystem::destroyPanel(&panel_system,&s_OpenSaveDialog);
            if (param_2 == 0) {
              command_save(this,uVar16,'\x02');
            }
            else if (param_2 == 1) {
              this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
              uStack_4 = 0;
              if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
                TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
              }
              uStack_4 = 0xffffffff;
              TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
            }
            goto LAB_004abe5a;
          }
        }
        pcVar7 = TPanel::panelName(param_1);
        if (pcVar7 != (char *)0x0) {
          pbVar13 = &s_NewSaveDialog;
          pbVar8 = (byte *)TPanel::panelName(param_1);
          do {
            bVar1 = *pbVar8;
            bVar15 = bVar1 < *pbVar13;
            if (bVar1 != *pbVar13) {
LAB_004ad001:
              iVar20 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
              goto LAB_004ad006;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar15 = bVar1 < pbVar13[1];
            if (bVar1 != pbVar13[1]) goto LAB_004ad001;
            pbVar8 = pbVar8 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar1 != 0);
          iVar20 = 0;
LAB_004ad006:
          if (iVar20 == 0) {
            TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
            TPanelSystem::destroyPanel(&panel_system,&s_NewSaveDialog);
            if (param_2 == 0) {
              command_save(this,uVar16,'\x03');
            }
            else if (param_2 == 1) {
              TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
            }
            goto LAB_004abe5a;
          }
        }
        lVar5 = 0;
        goto LAB_004abe5f;
      }
    }
  }
LAB_004abe5a:
  lVar5 = 1;
LAB_004abe5f:
  *unaff_FS_OFFSET = local_c;
  return lVar5;
}

// --------------------------------------------------

// Function: draw
// Address: 004ad0f0
// [HELPER] s_scr_sed__draw: "scr_sed::draw"
void __thiscall TRIBE_Screen_Sed::draw(TRIBE_Screen_Sed *this)
{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  tagRECT rect;
  
  TEasy_Panel::draw((TEasy_Panel *)this);
  if ((((this->_padding_ != 0) && (this->main_view != (TRIBE_Main_View *)0x0)) &&
      (this->_padding_ == this->_padding_)) &&
     (((this->_padding_ == this->_padding_ && (this->_padding_ == this->_padding_)) &&
      (this->_padding_ == this->_padding_)))) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    puVar3 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_scr_sed__draw,1);
    if (puVar3 != (uchar *)0x0) {
      iVar2 = *(int *)&this->main_view->field_0x98;
      TDrawArea::DrawBevel3
                ((TDrawArea *)this->_padding_,0,0,this->_padding_ + -1,
                 *(int *)&this->main_view->field_0x90 + -1,(uchar)this->_padding_,
                 *(uchar *)((int)&this->_padding_ + 1),*(uchar *)((int)&this->_padding_ + 2),
                 *(uchar *)((int)&this->_padding_ + 3),(uchar)this->_padding_,
                 *(uchar *)((int)&this->_padding_ + 1));
      TDrawArea::DrawBevel3
                ((TDrawArea *)this->_padding_,0,iVar2 + 1,this->_padding_ + -1,this->_padding_ + -1,
                 (uchar)this->_padding_,*(uchar *)((int)&this->_padding_ + 1),
                 *(uchar *)((int)&this->_padding_ + 2),*(uchar *)((int)&this->_padding_ + 3),
                 (uchar)this->_padding_,*(uchar *)((int)&this->_padding_ + 1));
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_scr_sed__draw);
    }
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: command_cancel
// Address: 004ad240
void __thiscall TRIBE_Screen_Sed::command_cancel(TRIBE_Screen_Sed *this)
{
  RGE_Player *pRVar1;
  
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(pRVar1);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_area(pRVar1);
  return;
}

// --------------------------------------------------

// Function: command_menu
// Address: 004ad270
int __thiscall TRIBE_Screen_Sed::command_menu(TRIBE_Screen_Sed *this)
{
  TRIBE_Dialog_Sed_Menu *this_00;
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4ab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Dialog_Sed_Menu *)operator_new(0x4b4);
  local_4 = 0;
  if (this_00 == (TRIBE_Dialog_Sed_Menu *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(this_00,this);
  }
  local_4 = 0xffffffff;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[0x36] != 0)) {
    (**(code **)*puVar1)(1);
    *unaff_FS_OFFSET = this_00;
    return 0;
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: command_new
// Address: 004ad300
void __thiscall TRIBE_Screen_Sed::command_new(TRIBE_Screen_Sed *this)
{
  uchar uVar1;
  
  uVar1 = need_to_save(this);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_NewSaveDialog,0x1c2,100);
    return;
  }
  TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
  return;
}

// --------------------------------------------------

// Function: command_new_map
// Address: 004ad340
int __thiscall
TRIBE_Screen_Sed::command_new_map
          (TRIBE_Screen_Sed *this,char *param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  short *psVar5;
  char *pcVar6;
  int tribe;
  int local_7d4;
  RGE_Player_Info player_info;
  RGE_Map_Gen_Info map_info;
  
  this->need_to_save_flag = '\0';
  if (rge_base_game->world == (RGE_Game_World *)0x0) {
    if (param_6 != 0) {
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x44d,(char *)0x0,-1);
    }
    iVar1 = TRIBE_Game::load_game_data((TRIBE_Game *)rge_base_game);
    if (iVar1 == 0) {
      if (param_6 != 0) {
        TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
      }
      return 0;
    }
  }
  this->world = (TRIBE_World *)rge_base_game->world;
  if (param_6 != 0) {
    if (param_1 == (char *)0x0) {
      iVar1 = 0x44e;
    }
    else {
      iVar1 = 0x44f;
    }
    TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,iVar1,(char *)0x0,-1);
  }
  player_info._672_4_ = &map_info.land;
  player_info.ai_info = (short)param_4;
  player_info.campaign = (uchar)param_5;
  player_info._681_1_ = param_5._1_1_;
  player_info.map_info = (RGE_Map_Gen_Info *)param_1;
  player_info.name[0]._0_4_ = 0x2865 - (int)(player_info.type + 4);
  player_info._682_2_ = 0;
  player_info.scenario._0_2_ = 8;
  local_7d4 = 0;
  plVar4 = player_info.player_id_hash;
  psVar5 = player_info.color + 2;
  pcVar6 = player_info.name[0] + 4;
  iVar1 = 0;
  do {
    iVar3 = iVar1;
    plVar4 = plVar4 + 1;
    local_7d4 = local_7d4 + 1;
    if ((short)this->world->_padding_ <= local_7d4) {
      local_7d4 = 1;
    }
    set_string(this,pcVar6,(long)(player_info.type + player_info.name[0]._0_4_ + iVar3 + 4),0x41);
    player_info.type[iVar3 + 4] = '\0';
    player_info.tribe[iVar3 + 4] = (char)local_7d4;
    *psVar5 = -1;
    *plVar4 = iVar3;
    iVar1 = iVar3 + 1;
    pcVar6 = pcVar6 + 0x41;
    psVar5 = psVar5 + 1;
  } while (iVar1 < 8);
  player_info.player_id_hash[iVar3 + 2] = iVar1;
  map_info.land.clump_num._0_2_ = 0;
  if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    rge_base_game->sound_system->mute = '\x01';
  }
  uVar2 = (**(code **)(this->world->_padding_ + 0xd4))(player_info.name[0] + 4,param_3);
  uVar2 = uVar2 & 0xff;
  if ((uVar2 != 0) && ((short)this->world->_padding_ < 8)) {
    uVar2 = 0;
    (**(code **)(this->world->_padding_ + 0xb8))();
  }
  if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    rge_base_game->sound_system->mute = '\0';
  }
  if ((uVar2 != 0) && (this->player_number_list != (TDropDownPanel *)0x0)) {
    iVar1 = 0;
    do {
      iVar3 = RGE_Scenario::Get_player_Active((RGE_Scenario *)this->world->_padding_,iVar1);
      if (iVar3 == 0) break;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    if ((iVar1 < 8) && (0 < iVar1)) {
      TDropDownPanel::set_line(this->player_number_list,iVar1 + -1);
    }
    SavePlayerActiveStatus(this);
  }
  return uVar2;
}

// --------------------------------------------------

// Function: command_open
// Address: 004ad590
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
void __thiscall TRIBE_Screen_Sed::command_open(TRIBE_Screen_Sed *this)
{
  uchar uVar1;
  TRIBE_Screen_Sed_Open *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4cb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  uVar1 = need_to_save(this);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_OpenSaveDialog,0x1c2,100);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
  local_4 = 0;
  if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
    TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
  }
  local_4 = 0xffffffff;
  TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: command_outline
// Address: 004ad630
void __thiscall TRIBE_Screen_Sed::command_outline(TRIBE_Screen_Sed *this)
{
  uchar uVar1;
  uchar outline_type;
  
  uVar1 = rge_base_game->outline_type;
  switch(uVar1) {
  case '\0':
  case '\x03':
    rge_base_game->outline_type = '\x02';
    return;
  case '\x01':
    uVar1 = '\0';
    break;
  case '\x02':
    rge_base_game->outline_type = '\x01';
    return;
  }
  rge_base_game->outline_type = uVar1;
  return;
}

// --------------------------------------------------

// Function: command_player
// Address: 004ad680
void __thiscall TRIBE_Screen_Sed::command_player(TRIBE_Screen_Sed *this,int param_1)
{
  (**(code **)(rge_base_game->_padding_ + 0x14))(param_1);
  return;
}

// --------------------------------------------------

// Function: command_quit
// Address: 004ad6a0
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
void __thiscall TRIBE_Screen_Sed::command_quit(TRIBE_Screen_Sed *this)
{
  uchar uVar1;
  int iVar2;
  
  uVar1 = need_to_save(this);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_QuitSaveDialog,0x1c2,100);
    return;
  }
  iVar2 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
  if (iVar2 == 0) {
    RGE_Base_Game::close(rge_base_game);
    return;
  }
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  return;
}

// --------------------------------------------------

// Function: command_save
// Address: 004ad700
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
// [HELPER] s_default_d: "default%d"
void __thiscall TRIBE_Screen_Sed::command_save(TRIBE_Screen_Sed *this,uchar param_1,uchar param_2)
{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  char temp_name [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4ee;
  *unaff_FS_OFFSET = &local_c;
  set_scenario_mode(this,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
  iVar3 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
  if (iVar3 < 1) {
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
  }
  else {
    iVar3 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
    if (iVar3 < 1) {
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    }
    else {
      pbVar4 = (byte *)RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
      if (*pbVar4 == 0) {
        command_save_as(this,param_2);
      }
      else {
        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
        if (param_1 != '\0') {
          TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
        }
        cVar2 = (**(code **)(this->world->_padding_ + 0xe4))(pbVar4);
        if (cVar2 == '\0') {
          TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
        }
        else {
          TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
          iVar3 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
          sprintf(temp_name + 4,s_default_d,iVar3);
          pbVar5 = (byte *)(temp_name + 4);
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_004ad897:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_004ad89c;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_004ad897;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_004ad89c:
          if (iVar3 != 0) {
            this->need_to_save_flag = '\0';
          }
          if (param_2 == '\x01') {
            iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
            if (iVar3 == 0) {
              RGE_Base_Game::close(rge_base_game);
            }
            else {
              TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
            }
          }
          else if (param_2 == '\x02') {
            temp_name._0_4_ = operator_new(0x490);
            uStack_4 = 0;
            if ((TRIBE_Screen_Sed_Open *)temp_name._0_4_ != (TRIBE_Screen_Sed_Open *)0x0) {
              TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open((TRIBE_Screen_Sed_Open *)temp_name._0_4_)
              ;
            }
            uStack_4 = 0xffffffff;
            TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
          }
          else if (param_2 == '\x03') {
            TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: command_save_as
// Address: 004ad960
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
void __thiscall TRIBE_Screen_Sed::command_save_as(TRIBE_Screen_Sed *this,uchar param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  char scenario_name [224];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f50e;
  *unaff_FS_OFFSET = &local_c;
  set_scenario_mode(this,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
  iVar1 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
  if (iVar1 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
  }
  else {
    iVar1 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
    if (iVar1 < 1) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    }
    else {
      scenario_name[4] = '\0';
      scenario_name._0_4_ = operator_new(0x6a4);
      local_4 = 0;
      if ((TribeSaveGameScreen *)scenario_name._0_4_ != (TribeSaveGameScreen *)0x0) {
        TribeSaveGameScreen::TribeSaveGameScreen
                  ((TribeSaveGameScreen *)scenario_name._0_4_,SaveScenarioEdit,scenario_name + 4,
                   (uint)param_1);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_get_default_name
// Address: 004ada70
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_default_d_scx: "default%d.scx"
char * __thiscall TRIBE_Screen_Sed::scenario_get_default_name(TRIBE_Screen_Sed *this)
{
  char *pcVar1;
  int iVar2;
  char temp_name [260];
  
  pcVar1 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    sprintf(temp_name + 4,s_default_d_scx,iVar2);
    RGE_Scenario::Set_scenario_name((RGE_Scenario *)this->world->_padding_,temp_name + 4);
  }
  pcVar1 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
  return pcVar1;
}

// --------------------------------------------------

// Function: command_quick_save
// Address: 004adaf0
void __thiscall TRIBE_Screen_Sed::command_quick_save(TRIBE_Screen_Sed *this)
{
  scenario_get_default_name(this);
  command_save(this,'\0','\0');
  return;
}

// --------------------------------------------------

// Function: scenario_save_defaulted
// Address: 004adb10
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_default_d: "default%d"
// [HELPER] s_default_d_scx: "default%d.scx"
char * __thiscall TRIBE_Screen_Sed::scenario_save_defaulted(TRIBE_Screen_Sed *this)
{
  char cVar1;
  int iVar2;
  
  set_scenario_mode(this,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
  iVar2 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
  if (iVar2 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
    return (char *)0x0;
  }
  iVar2 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
  if (iVar2 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    return (char *)0x0;
  }
  TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(0x86bad8,s_default_d_scx,iVar2);
  cVar1 = (**(code **)(this->world->_padding_ + 0xe4))(0x86bad8);
  if (cVar1 == '\0') {
    TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
    return (char *)0x0;
  }
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(0x86bad8,s_default_d,iVar2);
  return &UNK_0086bad4.field_0x4;
}

// --------------------------------------------------

// Function: need_to_save
// Address: 004adc30
uchar __thiscall TRIBE_Screen_Sed::need_to_save(TRIBE_Screen_Sed *this)
{
  return this->need_to_save_flag;
}

// --------------------------------------------------

// Function: set_focus
// Address: 004adc40
void __thiscall TRIBE_Screen_Sed::set_focus(TRIBE_Screen_Sed *this,int param_1)
{
  TScreenPanel::set_focus((TScreenPanel *)this,param_1);
  if (this->_padding_ != 0) {
    RGE_Base_Game::set_windows_mouse(rge_base_game,0);
    return;
  }
  RGE_Base_Game::set_windows_mouse(rge_base_game,1);
  return;
}

// --------------------------------------------------

// Function: SaveDisabledItemsInScenario
// Address: 004adc80
void __thiscall TRIBE_Screen_Sed::SaveDisabledItemsInScenario(TRIBE_Screen_Sed *this)
{
  short sVar1;
  int iVar2;
  long lVar3;
  T_Scenario *this_00;
  TButtonPanel **ppTVar4;
  int iVar5;
  
  if (this->player_num == 0) {
    this->player_num = 1;
  }
  iVar5 = 0;
  ppTVar4 = this->options_disable_button;
  do {
    iVar2 = TButtonPanel::get_state(*ppTVar4);
    if (iVar2 == 0) {
      sVar1 = this->player_num;
      this_00 = (T_Scenario *)this->world->_padding_;
    }
    else {
      sVar1 = this->player_num;
      this_00 = (T_Scenario *)this->world->_padding_;
    }
    T_Scenario::SetDisabledTechnology(this_00,sVar1 + -1,iVar5,(uint)(iVar2 == 0));
    iVar5 = iVar5 + 1;
    ppTVar4 = ppTVar4 + 1;
  } while (iVar5 < 0x10);
  lVar3 = TDropDownPanel::get_line(this->options_player_list);
  this->player_num = (short)lVar3 + 1;
  return;
}

// --------------------------------------------------

// Function: LoadDisabledItemsFromScenario
// Address: 004add00
void __thiscall TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(TRIBE_Screen_Sed *this)
{
  int iVar1;
  int iVar2;
  TButtonPanel **ppTVar3;
  
  iVar2 = 0;
  ppTVar3 = this->options_disable_button;
  do {
    iVar1 = T_Scenario::GetDisabledTechnology
                      ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar2);
    if (iVar1 == 0) {
      (**(code **)((*ppTVar3)->_padding_ + 0xe0))(1);
    }
    else {
      (**(code **)((*ppTVar3)->_padding_ + 0xe0))(0);
    }
    iVar2 = iVar2 + 1;
    ppTVar3 = ppTVar3 + 1;
  } while (iVar2 < 0x10);
  return;
}

// --------------------------------------------------

// Function: save_info_in_scenario
// Address: 004add50
void __thiscall TRIBE_Screen_Sed::save_info_in_scenario(TRIBE_Screen_Sed *this)
{
  return;
}

// --------------------------------------------------

// Function: save_multi_victory_cond_in_scenario
// Address: 004add60
void __thiscall TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed *this)
{
  long lVar1;
  char *pcVar2;
  int iVar3;
  T_Scenario *pTVar4;
  int iVar5;
  
  switch(this->mp_victory_type) {
  case VictoryTypeStandard:
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
    break;
  case VictoryTypeConquest:
    iVar5 = 1;
    goto LAB_004adda4;
  case VictoryTypeScore:
    iVar5 = 2;
    pTVar4 = (T_Scenario *)this->world->_padding_;
    break;
  case VictoryTypeTime:
    iVar5 = 3;
    pTVar4 = (T_Scenario *)this->world->_padding_;
    break;
  default:
    iVar5 = 4;
LAB_004adda4:
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::SetMPVictory(pTVar4,iVar5);
  lVar1 = TDropDownPanel::get_id(this->victory_score);
  T_Scenario::SetVictoryScore((T_Scenario *)this->world->_padding_,lVar1);
  lVar1 = TDropDownPanel::get_id(this->victory_time);
  T_Scenario::SetVictoryTime((T_Scenario *)this->world->_padding_,lVar1);
  iVar5 = TButtonPanel::get_state(this->victory_cond_type[0]);
  if (iVar5 != 0) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
    goto LAB_004ade58;
  }
  iVar5 = TButtonPanel::get_state(this->victory_cond_type[1]);
  if (iVar5 == 0) {
    iVar5 = TButtonPanel::get_state(this->victory_cond_type[2]);
    if (iVar5 != 0) {
      iVar5 = 2;
      pTVar4 = (T_Scenario *)this->world->_padding_;
      goto LAB_004ade58;
    }
    iVar5 = TButtonPanel::get_state(this->victory_cond_type[3]);
    if (iVar5 != 0) {
      iVar5 = 3;
      pTVar4 = (T_Scenario *)this->world->_padding_;
      goto LAB_004ade58;
    }
    iVar5 = 4;
  }
  else {
    iVar5 = 1;
  }
  pTVar4 = (T_Scenario *)this->world->_padding_;
LAB_004ade58:
  T_Scenario::SetMPVictory(pTVar4,iVar5);
  lVar1 = TDropDownPanel::get_id(this->victory_score);
  T_Scenario::SetVictoryScore((T_Scenario *)this->world->_padding_,lVar1);
  lVar1 = TDropDownPanel::get_id(this->victory_time);
  T_Scenario::SetVictoryTime((T_Scenario *)this->world->_padding_,lVar1);
  iVar5 = TButtonPanel::get_state(this->victory_and_or[1]);
  if (iVar5 == 0) {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_victory_all_flag(pTVar4,(uint)(iVar5 != 0));
  iVar5 = TButtonPanel::get_state(this->victory_cond_on[0]);
  if ((iVar5 == 0) && (iVar5 = TButtonPanel::get_state(this->victory_cond_type[4]), iVar5 != 0)) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    iVar5 = 1;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Conquest(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(this->victory_condition_explore);
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(this->victory_cond_on[1]);
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    if (100 < iVar5) {
      iVar5 = 100;
    }
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Exploration(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(this->victory_condition_ruins);
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(this->victory_cond_on[2]);
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Ruins(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(this->victory_condition_artifacts);
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(this->victory_cond_on[3]);
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Artifacts(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(this->victory_condition_discoveries);
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(this->victory_cond_on[4]);
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Discoveries(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(this->victory_condition_gold);
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(this->victory_cond_on[5]);
  if (iVar3 == 0) {
    T_Scenario::Set_Multi_Gold((T_Scenario *)this->world->_padding_,0);
    return;
  }
  T_Scenario::Set_Multi_Gold((T_Scenario *)this->world->_padding_,iVar5);
  return;
}

// --------------------------------------------------

// Function: save_victory_cond_in_scenario
// Address: 004ae070
void __thiscall TRIBE_Screen_Sed::save_victory_cond_in_scenario(TRIBE_Screen_Sed *this,int param_1)
{
  int iVar1;
  char *pcVar2;
  long lVar3;
  T_Scenario *pTVar4;
  int iVar5;
  long x1;
  long y1;
  long x2;
  long y2;
  int VictoryType;
  long local_4;
  
  iVar1 = TButtonPanel::get_state(this->victory_and_or[1]);
  if (iVar1 == 0) {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_victory_all_flag(pTVar4,(uint)(iVar1 != 0));
  iVar1 = TButtonPanel::get_state(this->victory_cond_on[0]);
  if ((iVar1 == 0) && (iVar1 = TButtonPanel::get_state(this->victory_cond_type[4]), iVar1 != 0)) {
    iVar1 = 0;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  else {
    iVar1 = 1;
    pTVar4 = (T_Scenario *)this->world->_padding_;
  }
  T_Scenario::Set_Multi_Conquest(pTVar4,iVar1);
  if (param_1 < 0) {
    return;
  }
  pcVar2 = TEditPanel::currentLine(this->victory_amount_input);
  iVar1 = atoi(pcVar2);
  local_4 = TDropDownPanel::get_line(this->victory_drop_down);
  lVar3 = TDropDownPanel::get_line(this->victory_enemy_player_list);
  iVar5 = lVar3 + 1;
  lVar3 = TDropDownPanel::get_id(this->victory_object_list);
  RGE_View::get_selection_area((RGE_View *)this->main_view,&y1,&x2,&y2,&VictoryType,1);
  this->px1 = (float)y1;
  this->py1 = (float)x2;
  this->px2 = (float)y2;
  this->py2 = (float)VictoryType;
  T_Scenario::ClearSPVictoryCondition((T_Scenario *)this->world->_padding_,param_1);
  switch(local_4) {
  case 1:
    if ((this->SelectedObject != (RGE_Static_Object *)0x0) &&
       (this->DestinationObject != (RGE_Static_Object *)0x0)) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,3);
      T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
      T_Scenario::SetSPDestObjectID
                ((T_Scenario *)this->world->_padding_,param_1,this->DestinationObject);
      return;
    }
    break;
  case 2:
    if (this->SelectedObject != (RGE_Static_Object *)0x0) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,3);
      T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
      T_Scenario::SetSPRectangle
                ((T_Scenario *)this->world->_padding_,param_1,this->px1,this->py1,this->px2,
                 this->py2);
      return;
    }
    break;
  case 3:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,2);
    T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    goto LAB_004ae57f;
  case 4:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,2);
    T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
    T_Scenario::SetSPRectangle
              ((T_Scenario *)this->world->_padding_,param_1,this->px1,this->py1,this->px2,this->py2)
    ;
    return;
  case 5:
    if (((0 < iVar5) && (iVar5 < 9)) && (iVar1 != 0)) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
      T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
      T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
      T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
      return;
    }
    break;
  case 6:
    if (this->SelectedObject != (RGE_Static_Object *)0x0) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
      T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
      return;
    }
    break;
  case 7:
    if ((0 < iVar5) && (iVar5 < 9)) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
      T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
      T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
      T_Scenario::SetSPAllFlag((T_Scenario *)this->world->_padding_,param_1,1);
      return;
    }
    break;
  case 8:
    if ((0 < iVar5) && (iVar5 < 9)) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
      T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
      return;
    }
    break;
  case 9:
    if (this->SelectedObject != (RGE_Static_Object *)0x0) {
      T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,5);
      T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
      return;
    }
    break;
  case 10:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 0;
    goto LAB_004ae570;
  case 0xb:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 3;
    goto LAB_004ae570;
  case 0xc:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 1;
    goto LAB_004ae570;
  case 0xd:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 2;
    goto LAB_004ae570;
  case 0xe:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 4;
    goto LAB_004ae570;
  case 0xf:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,5);
    lVar3 = TDropDownPanel::get_line(this->victory_ages_list);
    T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,lVar3 + 1);
    return;
  case 0x10:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    lVar3 = 6;
    goto LAB_004ae570;
  case 0x11:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,6);
    lVar3 = TDropDownPanel::get_id(this->victory_attribute_list);
LAB_004ae570:
    T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,lVar3);
LAB_004ae57f:
    T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
    return;
  case 0x12:
    T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,7);
    lVar3 = TDropDownPanel::get_id(this->victory_tech_list);
    T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,lVar3);
  }
  return;
}

// --------------------------------------------------

// Function: load_victory_cond_from_scenario
// Address: 004ae620
void __thiscall
TRIBE_Screen_Sed::load_victory_cond_from_scenario(TRIBE_Screen_Sed *this,int param_1)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  RGE_Static_Object *pRVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  RGE_Static_Object *obj;
  long y2;
  long x2;
  long y1;
  long x1;
  int VictoryType;
  int Amount;
  RGE_Static_Object *destobj;
  char str [40];
  int iStack_4;
  
  iVar2 = T_Scenario::Get_victory_all_flag((T_Scenario *)this->world->_padding_);
  iVar3 = this->victory_and_or[0]->_padding_;
  if (iVar2 == 0) {
    (**(code **)(iVar3 + 0xe0))(1);
    iVar3 = this->victory_and_or[1]->_padding_;
  }
  else {
    (**(code **)(iVar3 + 0xe0))(0);
    iVar3 = this->victory_and_or[1]->_padding_;
  }
  (**(code **)(iVar3 + 0xe0))(iVar2 != 0);
  if (-1 < iStack_4) {
    this->SelectedObject = (RGE_Static_Object *)0x0;
    this->DestinationObject = (RGE_Static_Object *)0x0;
    (**(code **)(*(int *)this->world->_padding_ + 8))();
    T_Scenario::SetSPWhich((T_Scenario *)this->world->_padding_,this->player_num + -1);
    iVar3 = T_Scenario::GetSPAmount((T_Scenario *)this->world->_padding_,iStack_4);
    itoa(iVar3,&destobj,10);
    TEditPanel::set_text(this->victory_amount_input,(char *)&destobj);
    iVar2 = T_Scenario::GetSPPlayerID((T_Scenario *)this->world->_padding_,iStack_4);
    TDropDownPanel::set_line(this->victory_enemy_player_list,iVar2 + -1);
    iVar2 = T_Scenario::GetSPObjectType((T_Scenario *)this->world->_padding_,iStack_4);
    lVar4 = TDropDownPanel::get_line(this->victory_object_list,iVar2);
    TDropDownPanel::setCurrentLineNumber(this->victory_object_list,lVar4);
    pRVar5 = T_Scenario::GetSPObject((T_Scenario *)this->world->_padding_,iStack_4);
    pRVar6 = T_Scenario::GetSPDestObjectID((T_Scenario *)this->world->_padding_,iStack_4);
    this->SelectedObject = pRVar5;
    this->DestinationObject = pRVar6;
    iVar2 = T_Scenario::GetSPVictoryType((T_Scenario *)this->world->_padding_,iStack_4);
    iVar7 = T_Scenario::GetSPAttribType((T_Scenario *)this->world->_padding_,iStack_4);
    pfVar1 = &this->px2;
    T_Scenario::GetSPRectangle
              ((T_Scenario *)this->world->_padding_,iStack_4,&this->px1,&this->py1,pfVar1,&this->py2
              );
    lVar4 = __ftol();
    lVar8 = __ftol();
    lVar9 = __ftol();
    lVar10 = __ftol();
    RGE_View::set_selection_area((RGE_View *)this->main_view,-1,-1,-1,-1);
    if (*pfVar1 != _DAT_00573af0) {
      RGE_View::set_selection_area((RGE_View *)this->main_view,lVar4,lVar8,lVar9,lVar10);
    }
    switch(iVar2) {
    case 0:
      iVar3 = 0;
      break;
    case 1:
      if (iVar3 == 0) {
        if (pRVar5 == (RGE_Static_Object *)0x0) {
          iVar3 = T_Scenario::GetSPAllFlag((T_Scenario *)this->world->_padding_,iStack_4);
          if (iVar3 == 0) {
            iVar3 = 8;
          }
          else {
            iVar3 = 7;
          }
        }
        else {
          iVar3 = 6;
        }
      }
      else {
        iVar3 = 5;
      }
      break;
    case 2:
      T_Scenario::GetSPRectangle
                ((T_Scenario *)this->world->_padding_,iStack_4,&this->px1,&this->py1,pfVar1,
                 &this->py2);
      if (*pfVar1 <= (float)_DAT_00573af8) {
        iVar3 = 3;
      }
      else {
        iVar3 = 4;
      }
      break;
    case 3:
      if (pRVar6 == (RGE_Static_Object *)0x0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
      break;
    case 4:
      switch(iVar7) {
      case 0:
        iVar3 = 10;
        break;
      case 1:
        iVar3 = 0xc;
        break;
      case 2:
        iVar3 = 0xd;
        break;
      case 3:
        iVar3 = 0xb;
        break;
      case 4:
        iVar3 = 0xe;
        break;
      case 5:
        TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0xf);
        iVar3 = T_Scenario::GetSPAmount((T_Scenario *)this->world->_padding_,iStack_4);
        TDropDownPanel::setCurrentLineNumber(this->victory_ages_list,iVar3 + -1);
        return;
      case 6:
        iVar3 = 0x10;
        break;
      default:
        goto switchD_004ae82a_default;
      }
      break;
    case 5:
      if (pRVar5 == (RGE_Static_Object *)0x0) {
        return;
      }
      iVar3 = 9;
      break;
    case 6:
      TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0x11);
      TDropDownPanel::setCurrentLineId(this->victory_attribute_list,iVar7);
      return;
    case 7:
      TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0x12);
      TDropDownPanel::setCurrentLineId(this->victory_tech_list,iVar7);
      return;
    default:
      goto switchD_004ae82a_default;
    }
    TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,iVar3);
  }
switchD_004ae82a_default:
  return;
}

// --------------------------------------------------

// Function: load_multi_victory_cond_from_scenario
// Address: 004ae9d0
// [HELPER] s_0: "0"
void __thiscall TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(TRIBE_Screen_Sed *this)
{
  int iVar1;
  long lVar2;
  int iVar3;
  TButtonPanel *this_00;
  char *pcVar4;
  char acStack_24 [4];
  char str [20];
  
  iVar1 = T_Scenario::GetMPVictory((T_Scenario *)this->world->_padding_);
  switch(iVar1) {
  case 0:
    this->mp_victory_type = VictoryTypeStandard;
    break;
  case 1:
    this->mp_victory_type = VictoryTypeConquest;
    break;
  case 2:
    this->mp_victory_type = VictoryTypeScore;
    break;
  case 3:
    this->mp_victory_type = VictoryTypeTime;
    break;
  default:
    this->mp_victory_type = VictoryTypeCustom;
  }
  iVar1 = T_Scenario::GetVictoryScore((T_Scenario *)this->world->_padding_);
  if (iVar1 == 0) {
    iVar1 = 900;
  }
  acStack_24[0] = 'P';
  acStack_24[1] = -0x16;
  acStack_24[2] = 'J';
  acStack_24[3] = '\0';
  lVar2 = TDropDownPanel::get_line(this->victory_score,iVar1);
  acStack_24[0] = '\\';
  acStack_24[1] = -0x16;
  acStack_24[2] = 'J';
  acStack_24[3] = '\0';
  TDropDownPanel::set_line(this->victory_score,lVar2);
  iVar1 = T_Scenario::GetVictoryTime((T_Scenario *)this->world->_padding_);
  if (iVar1 == 0) {
    iVar1 = 9000;
  }
  acStack_24[0] = -0x7f;
  acStack_24[1] = -0x16;
  acStack_24[2] = 'J';
  acStack_24[3] = '\0';
  lVar2 = TDropDownPanel::get_line(this->victory_time,iVar1);
  acStack_24[0] = -0x73;
  acStack_24[1] = -0x16;
  acStack_24[2] = 'J';
  acStack_24[3] = '\0';
  TDropDownPanel::set_line(this->victory_time,lVar2);
  iVar1 = T_Scenario::Get_victory_all_flag((T_Scenario *)this->world->_padding_);
  if (iVar1 == 0) {
    this_00 = this->victory_and_or[0];
  }
  else {
    this_00 = this->victory_and_or[1];
  }
  TButtonPanel::set_radio_button(this_00);
  iVar1 = T_Scenario::Get_Multi_Conquest((T_Scenario *)this->world->_padding_);
  if (iVar1 == 0) {
    acStack_24[0] = -0x20;
    acStack_24[1] = -0x16;
    acStack_24[2] = 'J';
    acStack_24[3] = '\0';
    (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
  }
  else {
    acStack_24[0] = -0x2c;
    acStack_24[1] = -0x16;
    acStack_24[2] = 'J';
    acStack_24[3] = '\0';
    (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
  }
  acStack_24[0] = -0x12;
  acStack_24[1] = -0x16;
  acStack_24[2] = 'J';
  acStack_24[3] = '\0';
  iVar3 = T_Scenario::Get_Multi_Exploration((T_Scenario *)this->world->_padding_);
  iVar1 = this->victory_cond_on[1]->_padding_;
  if (iVar3 == 0) {
    acStack_24[0] = '\0';
    acStack_24[1] = '\0';
    acStack_24[2] = '\0';
    acStack_24[3] = '\0';
    (**(code **)(iVar1 + 0xe0))();
    pcVar4 = s_0;
  }
  else {
    acStack_24[0] = '\x01';
    acStack_24[1] = '\0';
    acStack_24[2] = '\0';
    acStack_24[3] = '\0';
    (**(code **)(iVar1 + 0xe0))();
    itoa(iVar3);
    pcVar4 = &stack0xffffffe4;
  }
  TEditPanel::set_text(this->victory_condition_explore,pcVar4);
  iVar3 = T_Scenario::Get_Multi_Ruins((T_Scenario *)this->world->_padding_);
  iVar1 = this->victory_cond_on[2]->_padding_;
  if (iVar3 == 0) {
    (**(code **)(iVar1 + 0xe0))();
    pcVar4 = s_0;
  }
  else {
    (**(code **)(iVar1 + 0xe0))();
    itoa(iVar3,&stack0xffffffe0);
    pcVar4 = &stack0xffffffe0;
  }
  TEditPanel::set_text(this->victory_condition_ruins,pcVar4);
  iVar3 = T_Scenario::Get_Multi_Artifacts((T_Scenario *)this->world->_padding_);
  iVar1 = this->victory_cond_on[3]->_padding_;
  if (iVar3 == 0) {
    (**(code **)(iVar1 + 0xe0))();
    pcVar4 = s_0;
  }
  else {
    (**(code **)(iVar1 + 0xe0))();
    itoa(iVar3,acStack_24,10);
    pcVar4 = acStack_24;
  }
  TEditPanel::set_text(this->victory_condition_artifacts,pcVar4);
  iVar3 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)this->world->_padding_);
  iVar1 = this->victory_cond_on[4]->_padding_;
  if (iVar3 == 0) {
    (**(code **)(iVar1 + 0xe0))(0);
    pcVar4 = s_0;
  }
  else {
    (**(code **)(iVar1 + 0xe0))(1);
    itoa(iVar3,&stack0xffffffd8,10);
    pcVar4 = &stack0xffffffd8;
  }
  TEditPanel::set_text(this->victory_condition_discoveries,pcVar4);
  iVar3 = T_Scenario::Get_Multi_Gold((T_Scenario *)this->world->_padding_);
  iVar1 = this->victory_cond_on[5]->_padding_;
  if (iVar3 == 0) {
    (**(code **)(iVar1 + 0xe0))(0);
    pcVar4 = s_0;
  }
  else {
    (**(code **)(iVar1 + 0xe0))(1);
    itoa(iVar3,&stack0xffffffd4,10);
    pcVar4 = &stack0xffffffd4;
  }
  TEditPanel::set_text(this->victory_condition_gold,pcVar4);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
  return;
}

// --------------------------------------------------

// Function: save_diplomacy_in_scenario
// Address: 004aecb0
void __thiscall TRIBE_Screen_Sed::save_diplomacy_in_scenario(TRIBE_Screen_Sed *this,int param_1)
{
  int iVar1;
  T_Scenario *this_00;
  TButtonPanel **ppTVar2;
  int iVar3;
  
  if (-1 < param_1) {
    iVar3 = 0;
    ppTVar2 = this->Diplomacy_friend_box[0] + 1;
    do {
      iVar1 = TButtonPanel::get_state((*(TButtonPanel *(*) [3])(ppTVar2 + -1))[0]);
      if (iVar1 == 1) {
        iVar1 = 0;
        this_00 = (T_Scenario *)this->world->_padding_;
LAB_004aed1a:
        T_Scenario::Set_player_attitude(this_00,param_1,iVar3,iVar1);
      }
      else {
        iVar1 = TButtonPanel::get_state(*ppTVar2);
        if (iVar1 == 1) {
          this_00 = (T_Scenario *)this->world->_padding_;
          iVar1 = 1;
          goto LAB_004aed1a;
        }
        iVar1 = TButtonPanel::get_state(ppTVar2[1]);
        if (iVar1 == 1) {
          iVar1 = 3;
          this_00 = (T_Scenario *)this->world->_padding_;
          goto LAB_004aed1a;
        }
      }
      iVar3 = iVar3 + 1;
      ppTVar2 = ppTVar2 + 3;
    } while (iVar3 < 8);
    iVar3 = TButtonPanel::get_state(this->Diplomacy_AlliedVictory[param_1]);
    T_Scenario::SetPlayerAlliedVictory((T_Scenario *)this->world->_padding_,param_1,iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: load_diplomacy_from_scenario
// Address: 004aed50
void __thiscall TRIBE_Screen_Sed::load_diplomacy_from_scenario(TRIBE_Screen_Sed *this,int param_1)
{
  int iVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  int iVar4;
  
  if (-1 < param_1) {
    iVar4 = 0;
    ppTVar2 = this->Diplomacy_AlliedVictory;
    ppTVar3 = this->Diplomacy_friend_box[0] + 1;
    do {
      iVar1 = T_Scenario::Get_player_attitude((T_Scenario *)this->world->_padding_,param_1,iVar4);
      if (iVar1 == 0) {
        TButtonPanel::set_radio_button((*(TButtonPanel *(*) [3])(ppTVar3 + -1))[0]);
      }
      if (iVar1 == 1) {
        TButtonPanel::set_radio_button(*ppTVar3);
      }
      if (iVar1 == 3) {
        TButtonPanel::set_radio_button(ppTVar3[1]);
      }
      (**(code **)((*ppTVar2)->_padding_ + 0xe0))(0);
      iVar4 = iVar4 + 1;
      ppTVar2 = ppTVar2 + 1;
      ppTVar3 = ppTVar3 + 3;
    } while (iVar4 < 8);
    iVar4 = this->Diplomacy_AlliedVictory[param_1]->_padding_;
    iVar1 = T_Scenario::GetPlayerAlliedVictory((T_Scenario *)this->world->_padding_,param_1);
    (**(code **)(iVar4 + 0xe0))(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: activate_victory_proper_fields
// Address: 004aee10
void __thiscall
TRIBE_Screen_Sed::activate_victory_proper_fields(TRIBE_Screen_Sed *this,int param_1,int param_2)
{
  TPanel *ptr [2];
  
  this->SelectRegionFlag = SELECT_OFF;
  if (param_2 == 0) {
    (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    (**(code **)(this->victory_button_set_object->_padding_ + 0x14))(0);
    (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))(0);
    (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))(0);
    (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))(0);
    (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))(0);
    (**(code **)(this->victory_attribute_list->_padding_ + 0x14))(0);
    (**(code **)(this->victory_ages_list->_padding_ + 0x14))(0);
    (**(code **)(this->victory_tech_list->_padding_ + 0x14))(0);
    return;
  }
  TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
  switch(param_1) {
  default:
    return;
  case 1:
    (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))();
    return;
  case 2:
    (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))();
    (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))();
    return;
  case 3:
    (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7766,-1);
    break;
  case 4:
    (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7767,-1);
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))(param_2);
    (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))(param_2);
    return;
  case 5:
    (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))(param_2);
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7768,-1);
    (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))(param_2);
    (**(code **)(this->_padding_ + 200))(&stack0xffffffe4,2);
    goto LAB_004af094;
  case 6:
  case 9:
    (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    return;
  case 7:
    (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))();
    (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_enemy_player_list);
    return;
  case 8:
    (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))();
    (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))();
LAB_004af094:
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_enemy_player_list);
    return;
  case 10:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7769,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    return;
  case 0xb:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776a,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    return;
  case 0xc:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776b,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    return;
  case 0xd:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776c,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    return;
  case 0xe:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776d,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    return;
  case 0xf:
    (**(code **)(this->victory_ages_list->_padding_ + 0x14))();
    return;
  case 0x10:
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776e,-1);
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    break;
  case 0x11:
    (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776f,-1);
    TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    (**(code **)(this->victory_attribute_list->_padding_ + 0x14))();
    return;
  case 0x12:
    (**(code **)(this->victory_tech_list->_padding_ + 0x14))();
    return;
  }
  TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
  return;
}

// --------------------------------------------------

// Function: init_module_variables
// Address: 004af320
void __thiscall TRIBE_Screen_Sed::init_module_variables(TRIBE_Screen_Sed *this)
{
  TEditPanel **ppTVar1;
  TDropDownPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  TTextPanel **ppTVar4;
  TButtonPanel **ppTVar5;
  int iVar6;
  
  this->background_pic = (TShape *)0x0;
  this->main_view = (TRIBE_Main_View *)0x0;
  this->map_view = (RGE_Diamond_Map_View *)0x0;
  this->message_panel = (TMessagePanel *)0x0;
  this->bottom_panel = (TPanel *)0x0;
  this->set_player_first_flag = 0;
  ppTVar3 = this->scenario_mode_button;
  for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
  }
  this->menu_button = (TButtonPanel *)0x0;
  this->help_button = (TButtonPanel *)0x0;
  this->map_type_label = (TTextPanel *)0x0;
  ppTVar4 = this->map_type_text;
  iVar6 = 3;
  do {
    ppTVar4[-3] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->default_terrain_drop = (TDropDownPanel *)0x0;
  this->default_terrain_label = (TTextPanel *)0x0;
  this->map_size_drop = (TDropDownPanel *)0x0;
  this->map_size_label = (TTextPanel *)0x0;
  this->map_style_drop = (TDropDownPanel *)0x0;
  this->map_style_label = (TTextPanel *)0x0;
  this->map_generating_text = (TTextPanel *)0x0;
  this->random_seed_label = (TTextPanel *)0x0;
  this->random_seed_input = (TEditPanel *)0x0;
  this->random_seed_used_label = (TTextPanel *)0x0;
  this->random_seed_used_text = (TTextPanel *)0x0;
  this->generate_map_button = (TButtonPanel *)0x0;
  this->brush_size_label = (TTextPanel *)0x0;
  this->paint_type_label = (TTextPanel *)0x0;
  this->paint_terrain_label = (TTextPanel *)0x0;
  ppTVar4 = this->brush_size_button_label;
  iVar6 = 5;
  do {
    ppTVar4[-5] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  ppTVar4 = this->paint_type_button_label;
  iVar6 = 3;
  do {
    ppTVar4[-3] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->paint_terrain_list = (TListPanel *)0x0;
  this->paint_terrain_scrollbar = (TScrollBarPanel *)0x0;
  this->paint_elevation_list = (TListPanel *)0x0;
  this->paint_elevation_scrollbar = (TScrollBarPanel *)0x0;
  this->player_advance_civilization_drop = (TDropDownPanel *)0x0;
  this->player_label = (TTextPanel *)0x0;
  this->player_starting_age_label = (TTextPanel *)0x0;
  this->player_build_text = (TTextPanel *)0x0;
  this->player_city_text = (TTextPanel *)0x0;
  this->player_list = (TDropDownPanel *)0x0;
  this->player_number_list = (TDropDownPanel *)0x0;
  ppTVar1 = this->player_inven_input;
  iVar6 = 5;
  do {
    ppTVar1[-5] = (TEditPanel *)0x0;
    *ppTVar1 = (TEditPanel *)0x0;
    ppTVar1 = ppTVar1 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  ppTVar2 = this->player_setting_drop;
  iVar6 = 2;
  do {
    ppTVar2[-3] = (TDropDownPanel *)0x0;
    *ppTVar2 = (TDropDownPanel *)0x0;
    ppTVar2 = ppTVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->BuildList = (TDropDownPanel *)0x0;
  this->CityLayout = (TDropDownPanel *)0x0;
  this->AiRules = (TDropDownPanel *)0x0;
  this->unit_player_list = (TDropDownPanel *)0x0;
  ppTVar4 = this->unit_mode_select_label;
  iVar6 = 4;
  do {
    ppTVar4[-4] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->unit_list = (TListPanel *)0x0;
  this->unit_scrollbar = (TScrollBarPanel *)0x0;
  this->unit_list_info = (List_Info *)0x0;
  this->button_unit_pics = (TShape *)0x0;
  this->button_bldg_pics[0] = (TShape *)0x0;
  this->button_bldg_pics[1] = (TShape *)0x0;
  this->button_bldg_pics[2] = (TShape *)0x0;
  this->button_bldg_pics[3] = (TShape *)0x0;
  this->button_bldg_pics[4] = (TShape *)0x0;
  this->object_panel = (TRIBE_Scenario_Editor_Panel_Object *)0x0;
  this->unit_list_size = 0;
  ppTVar3 = this->victory_cond_on;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
  }
  ppTVar4 = this->victory_text_and_or;
  iVar6 = 2;
  do {
    ppTVar4[-5] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->victory_amount_label = (TTextPanel *)0x0;
  this->victory_long_label = (TTextPanel *)0x0;
  this->victory_condition_label = (TTextPanel *)0x0;
  this->victory_label_conquest = (TTextPanel *)0x0;
  this->victory_label_explore = (TTextPanel *)0x0;
  this->victory_label_explore_percent = (TTextPanel *)0x0;
  this->victory_label_ruins = (TTextPanel *)0x0;
  this->victory_label_artifacts = (TTextPanel *)0x0;
  this->victory_label_discoveries = (TTextPanel *)0x0;
  this->victory_label_gold = (TTextPanel *)0x0;
  this->victory_condition_explore = (TEditPanel *)0x0;
  this->victory_condition_ruins = (TEditPanel *)0x0;
  this->victory_condition_artifacts = (TEditPanel *)0x0;
  this->victory_condition_discoveries = (TEditPanel *)0x0;
  this->victory_condition_gold = (TEditPanel *)0x0;
  ppTVar3 = this->victory_cond_type;
  iVar6 = 5;
  do {
    ppTVar3[-5] = (TButtonPanel *)0x0;
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->victory_score_label = (TTextPanel *)0x0;
  this->victory_score = (TDropDownPanel *)0x0;
  this->victory_time_label = (TTextPanel *)0x0;
  this->victory_time = (TDropDownPanel *)0x0;
  ppTVar3 = this->victory_button;
  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
  }
  this->victory_drop_down = (TDropDownPanel *)0x0;
  this->victory_object_list = (TDropDownPanel *)0x0;
  this->victory_player_list = (TDropDownPanel *)0x0;
  this->victory_ages_list = (TDropDownPanel *)0x0;
  this->victory_tech_list = (TDropDownPanel *)0x0;
  this->victory_button_set_object = (TButtonPanel *)0x0;
  this->victory_button_set_destination = (TButtonPanel *)0x0;
  this->victory_button_go_to_dest = (TButtonPanel *)0x0;
  this->victory_condition_text = (TTextPanel *)0x0;
  this->victory_condition_type = (TTextPanel *)0x0;
  this->victory_amount_text = (TTextPanel *)0x0;
  this->victory_amount_input = (TEditPanel *)0x0;
  this->victory_enemy_player_list = (TDropDownPanel *)0x0;
  this->victory_attribute_list = (TDropDownPanel *)0x0;
  this->victory_which_enemy_text = (TTextPanel *)0x0;
  this->victory_object_scrollbar = (TScrollBarPanel *)0x0;
  ppTVar4 = this->message_button_label;
  iVar6 = 5;
  do {
    ppTVar4[-5] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->message_input = (TEditPanel *)0x0;
  ppTVar2 = this->cinematic_input;
  iVar6 = 4;
  do {
    ppTVar2[-4] = (TDropDownPanel *)0x0;
    *ppTVar2 = (TDropDownPanel *)0x0;
    ppTVar2 = ppTVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  ppTVar3 = this->options_button;
  iVar6 = 1;
  do {
    ppTVar3[-1] = (TButtonPanel *)0x0;
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->options_player_list = (TDropDownPanel *)0x0;
  this->options_disable_tech_text = (TTextPanel *)0x0;
  ppTVar4 = this->options_disable_text;
  iVar6 = 0x10;
  do {
    ppTVar4[-0x10] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->Diplomacy_player_list = (TDropDownPanel *)0x0;
  ppTVar3 = this->Diplomacy_AlliedVictory;
  ppTVar5 = this->Diplomacy_friend_box[0] + 1;
  iVar6 = 8;
  do {
    ppTVar3[-0x25] = (TButtonPanel *)0x0;
    (*(TButtonPanel *(*) [3])(ppTVar5 + -1))[0] = (TButtonPanel *)0x0;
    *ppTVar5 = (TButtonPanel *)0x0;
    ppTVar5[1] = (TButtonPanel *)0x0;
    *ppTVar3 = (TButtonPanel *)0x0;
    ppTVar3 = ppTVar3 + 1;
    ppTVar5 = ppTVar5 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->Diplomacy_status_label[0] = (TTextPanel *)0x0;
  this->Diplomacy_status_label[1] = (TTextPanel *)0x0;
  this->Diplomacy_status_label[2] = (TTextPanel *)0x0;
  this->Diplomacy_status_label[3] = (TTextPanel *)0x0;
  this->world = (TRIBE_World *)0x0;
  return;
}

// --------------------------------------------------

// Function: create_all_buttons_etc
// Address: 004af6c0
// [HELPER] s_0: "0"
// [HELPER] s_1200: "1200"
// [HELPER] s_1500: "1500"
// [HELPER] s_1800: "1800"
// [HELPER] s_2100: "2100"
// [HELPER] s_2400: "2400"
// [HELPER] s_2700: "2700"
// [HELPER] s_3000: "3000"
// [HELPER] s_300: "300"
// [HELPER] s_400: "400"
// [HELPER] s_500: "500"
// [HELPER] s_600: "600"
// [HELPER] s_700: "700"
// [HELPER] s_800: "800"
// [HELPER] s_900: "900"
// [HELPER] s_: ""
// [HELPER] s__: "}"
// [HELPER] s__d: "%d"
// [HELPER] s__d_: "%d "
// [HELPER] s_btnbldg_d_shp: "btnbldg%d.shp"
// [HELPER] s_btnunit_shp: "btnunit.shp"
void __thiscall TRIBE_Screen_Sed::create_all_buttons_etc(TRIBE_Screen_Sed *this)
{
  TListPanel **ppTVar1;
  TEditPanel **ppTVar2;
  code *pcVar3;
  bool bVar4;
  TPanel *pTVar5;
  int iVar6;
  long lVar7;
  TShape *pTVar8;
  RGE_Font *pRVar9;
  TRIBE_Scenario_Editor_Panel_Object *pTVar10;
  TButtonPanel **ppTVar11;
  TDropDownPanel **ppTVar12;
  TButtonPanel **ppTVar13;
  TTextPanel **ppTVar14;
  TEditPanel **ppTVar15;
  TButtonPanel *(*papTVar16) [3];
  undefined4 *unaff_FS_OFFSET;
  long lVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int i;
  int iStack_1c8;
  TPanel *ptr [4];
  char str4 [20];
  char str3 [20];
  char str1 [140];
  char str [100];
  char str2 [140];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f54a;
  *unaff_FS_OFFSET = &local_c;
  ppTVar13 = this->scenario_mode_button;
  iVar6 = create_button(this,(TPanel *)this,ppTVar13,0x271a,1);
  if (iVar6 != 0) {
    TPanel::set_help_info((TPanel *)*ppTVar13,0x76c0,-1);
    iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 1,0x271b,1);
    if (iVar6 != 0) {
      TPanel::set_help_info((TPanel *)this->scenario_mode_button[1],0x76c1,-1);
      iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 2,0x271c,1);
      if (iVar6 != 0) {
        TPanel::set_help_info((TPanel *)this->scenario_mode_button[2],0x76c2,-1);
        iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 3,0x271d,1);
        if (iVar6 != 0) {
          TPanel::set_help_info((TPanel *)this->scenario_mode_button[3],0x76c3,-1);
          iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 4,0x2722,1);
          if (iVar6 != 0) {
            TPanel::set_help_info((TPanel *)this->scenario_mode_button[4],0x76c8,-1);
            iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 5,0x271e,1);
            if (iVar6 != 0) {
              TPanel::set_help_info((TPanel *)this->scenario_mode_button[5],0x76c4,-1);
              iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 6,0x2723,1);
              if (iVar6 != 0) {
                TPanel::set_help_info((TPanel *)this->scenario_mode_button[6],0x76c9,-1);
                iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 7,0x2721,1);
                if (iVar6 != 0) {
                  TPanel::set_help_info((TPanel *)this->scenario_mode_button[7],0x76c7,-1);
                  iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 8,0x271f,1)
                  ;
                  if (iVar6 != 0) {
                    TPanel::set_help_info((TPanel *)this->scenario_mode_button[8],0x76c5,-1);
                    iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 9,0x2720,
                                          1);
                    if (iVar6 != 0) {
                      TPanel::set_help_info((TPanel *)this->scenario_mode_button[9],0x76c6,-1);
                      iVar6 = 10;
                      ppTVar11 = ppTVar13;
                      do {
                        TButtonPanel::set_radio_info(*ppTVar11,ppTVar13,10);
                        (**(code **)((*ppTVar11)->_padding_ + 0x14))(1);
                        ppTVar11 = ppTVar11 + 1;
                        iVar6 = iVar6 + -1;
                      } while (iVar6 != 0);
                      ppTVar13 = &this->menu_button;
                      iVar6 = create_button(this,(TPanel *)this,ppTVar13,0x2724,0);
                      if (iVar6 != 0) {
                        TPanel::set_help_info((TPanel *)*ppTVar13,0x774c,-1);
                        (**(code **)((*ppTVar13)->_padding_ + 0x14))(1);
                        iVar6 = create_button(this,(TPanel *)this,&this->help_button,0xfa9,0);
                        if (iVar6 != 0) {
                          (**(code **)(this->help_button->_padding_ + 0x14))(1);
                          iVar6 = create_text(this,this->bottom_panel,&this->map_type_label,0x29a6);
                          if (iVar6 != 0) {
                            ppTVar13 = this->map_type_button;
                            iVar6 = create_radio_button(this,this->bottom_panel,ppTVar13);
                            if (iVar6 != 0) {
                              TPanel::set_help_info((TPanel *)*ppTVar13,0x76cf,-1);
                              iVar6 = create_radio_button(this,this->bottom_panel,
                                                          this->map_type_button + 1);
                              if (iVar6 != 0) {
                                TPanel::set_help_info((TPanel *)this->map_type_button[1],0x76d0,-1);
                                iVar6 = create_radio_button(this,this->bottom_panel,
                                                            this->map_type_button + 2);
                                if (iVar6 != 0) {
                                  TPanel::set_help_info
                                            ((TPanel *)this->map_type_button[2],0x76d1,-1);
                                  iVar6 = create_text(this,this->bottom_panel,this->map_type_text,
                                                      0x299c);
                                  if (iVar6 != 0) {
                                    iVar6 = create_text(this,this->bottom_panel,
                                                        this->map_type_text + 1,0x299d);
                                    if (iVar6 != 0) {
                                      iVar6 = create_text(this,this->bottom_panel,
                                                          this->map_type_text + 2,0x299e);
                                      if (iVar6 != 0) {
                                        iVar6 = create_text(this,this->bottom_panel,
                                                            &this->default_terrain_label,0x299f);
                                        if (iVar6 != 0) {
                                          iVar6 = create_drop_down(this,this->bottom_panel,
                                                                   &this->default_terrain_drop);
                                          if (iVar6 != 0) {
                                            TPanel::set_help_info
                                                      ((TPanel *)this->default_terrain_drop,0x76d6,
                                                       -1);
                                            iVar20 = 0;
                                            iVar19 = 1;
                                            iVar18 = 1;
                                            lVar17 = 1;
                                            lVar7 = TPanel::height((TPanel *)this);
                                            iVar6 = lVar7 + -200;
                                            lVar7 = TPanel::width((TPanel *)this);
                                            iVar6 = TEasy_Panel::create_text
                                                              ((TEasy_Panel *)this,
                                                               (TPanel *)this->main_view,
                                                               &this->map_generating_text,0x29a5,0,0
                                                               ,lVar7,iVar6,lVar17,iVar18,iVar19,
                                                               iVar20);
                                            if (iVar6 != 0) {
                                              (**(code **)(this->map_generating_text->_padding_ +
                                                          0x14))(0);
                                              iVar6 = create_text(this,this->bottom_panel,
                                                                  &this->map_size_label,0x29a0);
                                              if (iVar6 != 0) {
                                                iVar6 = create_drop_down(this,this->bottom_panel,
                                                                         &this->map_size_drop);
                                                if (iVar6 != 0) {
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->map_size_drop,0x76d2,-1
                                                            );
                                                  iVar6 = create_text(this,this->bottom_panel,
                                                                      &this->map_style_label,0x29a1)
                                                  ;
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->map_style_drop)
                                                    ;
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)this->map_style_drop,
                                                                 0x76d3,-1);
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->random_seed_label,
                                                                          0x29a2);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_edit(this,this->bottom_panel,
                                                                            &this->random_seed_input
                                                                            ,s_0,5,FormatUnsignedInt
                                                                            ,0,0);
                                                        if (iVar6 != 0) {
                                                          TPanel::set_help_info
                                                                    ((TPanel *)
                                                                     this->random_seed_input,0x76d4,
                                                                     -1);
                                                          iVar6 = create_text(this,this->
                                                  bottom_panel,&this->random_seed_used_label,0x29a3)
                                                  ;
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->random_seed_used_text
                                                                        ,s_0);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_button(this,this->bottom_panel,
                                                                            &this->
                                                  generate_map_button,0x29a4,0);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->generate_map_button,
                                                               0x76d5,-1);
                                                    iVar6 = 3;
                                                    ppTVar11 = ppTVar13;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar11,ppTVar13,3);
                                                      ppTVar11 = ppTVar11 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->brush_size_label,
                                                                        0x29af);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->paint_terrain_label
                                                                          ,0x29bc);
                                                      if (iVar6 != 0) {
                                                        ppTVar13 = this->brush_size_button;
                                                        iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar13,0x76d9,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->brush_size_button + 1);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->brush_size_button[1],
                                                               0x76da,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->brush_size_button + 2);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->brush_size_button[2],
                                                               0x76db,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->brush_size_button + 3);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->brush_size_button[3],
                                                               0x76dc,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->brush_size_button + 4);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->brush_size_button[4],
                                                               0x76dd,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  brush_size_button_label,0x29b0);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  brush_size_button_label + 1,0x29b1);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  brush_size_button_label + 2,0x29b2);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  brush_size_button_label + 3,0x29b3);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  brush_size_button_label + 4,0x29b4);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->paint_type_label,
                                                                        0x29b9);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->paint_type_button);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->paint_type_button[0],
                                                               0x76de,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->paint_type_button + 1);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->paint_type_button[1],
                                                               0x76df,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->paint_type_button + 2);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->paint_type_button[2],
                                                               0x76e0,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  paint_type_button_label,0x271a);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  paint_type_button_label + 1,0x2987);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  paint_type_button_label + 2,0x29ba);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_list(this,this->bottom_panel,
                                                                        &this->paint_terrain_list,
                                                                        &this->
                                                  paint_terrain_scrollbar);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->paint_terrain_list,
                                                               0x76e1,-1);
                                                    iVar6 = create_list(this,this->bottom_panel,
                                                                        &this->paint_elevation_list,
                                                                        &this->
                                                  paint_elevation_scrollbar);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->paint_elevation_list,
                                                               0x76e2,-1);
                                                    iVar6 = 5;
                                                    ppTVar11 = ppTVar13;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar11,ppTVar13,5);
                                                      ppTVar11 = ppTVar11 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    iVar6 = 3;
                                                    ppTVar13 = this->paint_type_button;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar13,this->paint_type_button,3
                                                                );
                                                      ppTVar13 = ppTVar13 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    ppTVar13 = this->unit_mode_select;
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar13,0x76f8,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->unit_mode_select + 1);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->unit_mode_select[1],
                                                               0x76f7,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->unit_mode_select + 2);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->unit_mode_select[2],
                                                               0x76f9,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->unit_mode_select + 3);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->unit_mode_select[3],
                                                               0x76fa,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->unit_mode_select_label
                                                                        ,0x2777);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->
                                                  unit_mode_select_label + 1,0x2778);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->unit_mode_select_label
                                                                        + 2,0x2779);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->
                                                  unit_mode_select_label + 3,0x277a);
                                                  if (iVar6 != 0) {
                                                    iVar6 = 4;
                                                    ppTVar11 = ppTVar13;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar11,ppTVar13,4);
                                                      ppTVar11 = ppTVar11 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    TButtonPanel::set_radio_button(*ppTVar13);
                                                    ppTVar1 = &this->unit_list;
                                                    iVar6 = create_list(this,(TPanel *)this,ppTVar1,
                                                                        &this->unit_scrollbar);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar1,0x76fb,-1);
                                                      TPanel::set_z_order((TPanel *)*ppTVar1,'\x02',
                                                                          0);
                                                      pTVar8 = (TShape *)operator_new(0x20);
                                                      uStack_4 = 0;
                                                      if (pTVar8 == (TShape *)0x0) {
                                                        pTVar8 = (TShape *)0x0;
                                                      }
                                                      else {
                                                        pTVar8 = (TShape *)
                                                                 TShape::TShape(pTVar8,s_btnunit_shp
                                                                                ,0xc62a);
                                                      }
                                                      uStack_4 = 0xffffffff;
                                                      this->button_unit_pics = pTVar8;
                                                      if (pTVar8 != (TShape *)0x0) {
                                                        iVar6 = TShape::is_loaded(pTVar8);
                                                        if (iVar6 != 0) {
                                                          iVar6 = 0;
                                                          do {
                                                            iVar18 = iVar6;
                                                            if (iVar6 == 4) {
                                                              iVar18 = 1;
                                                            }
                                                            sprintf(str + 4,s_btnbldg_d_shp,iVar18);
                                                            pTVar8 = (TShape *)operator_new(0x20);
                                                            uStack_4 = 1;
                                                            if (pTVar8 == (TShape *)0x0) {
                                                              pTVar8 = (TShape *)0x0;
                                                            }
                                                            else {
                                                              pTVar8 = (TShape *)
                                                                       TShape::TShape(pTVar8,str + 4
                                                                                      ,iVar18 + 
                                                  0xc610);
                                                  }
                                                  uStack_4 = 0xffffffff;
                                                  this->button_bldg_pics[iVar18] = pTVar8;
                                                  if (pTVar8 == (TShape *)0x0) goto LAB_004b1a1f;
                                                  iVar18 = TShape::is_loaded(pTVar8);
                                                  if (iVar18 == 0) goto LAB_004b1a1f;
                                                  iVar6 = iVar6 + 1;
                                                  } while (iVar6 < 5);
                                                  ppTVar12 = &this->unit_player_list;
                                                  iVar6 = create_drop_down(this,this->bottom_panel,
                                                                           ppTVar12);
                                                  if (iVar6 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar12,0x76fc,-1);
                                                  pRVar9 = RGE_Base_Game::get_font(rge_base_game,10)
                                                  ;
                                                  pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                            operator_new(0x21c);
                                                  uStack_4 = 2;
                                                  if (pTVar10 ==
                                                      (TRIBE_Scenario_Editor_Panel_Object *)0x0) {
                                                    pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                              0x0;
                                                  }
                                                  else {
                                                    pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                              TRIBE_Scenario_Editor_Panel_Object::
                                                              TRIBE_Scenario_Editor_Panel_Object
                                                                        (pTVar10,(TDrawArea *)
                                                                                 this->_padding_,
                                                                         (TPanel *)this,pRVar9->font
                                                                         ,pRVar9->font_wid,
                                                                         pRVar9->font_hgt,
                                                                         this->button_unit_pics,
                                                                         this->button_bldg_pics,
                                                                         (TRIBE_Player *)0x0);
                                                  }
                                                  uStack_4 = 0xffffffff;
                                                  this->object_panel = pTVar10;
                                                  if ((pTVar10 !=
                                                       (TRIBE_Scenario_Editor_Panel_Object *)0x0) &&
                                                     (pTVar10->_padding_ == 0)) {
                                                    (**(code **)(pTVar10->_padding_ + 0x14))(0);
                                                    TPanel::set_z_order((TPanel *)*ppTVar12,'\x01',0
                                                                       );
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->player_label,0x2864);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->
                                                  player_starting_age_label,0x2815);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  player_advance_civilization_drop);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->
                                                  player_advance_civilization_drop,0x7765,-1);
                                                  Set_player_advance_civilization_text(this,0);
                                                  iVar6 = create_drop_down(this,this->bottom_panel,
                                                                           &this->player_list);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->player_list,0x76e6,-1
                                                              );
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  player_number_list);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->player_number_list,
                                                               0x76e7,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->player_inven_label,
                                                                        0x280b);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->player_inven_label +
                                                                          1,0x280c);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->player_inven_label
                                                                            + 2,0x280d);
                                                        if (iVar6 != 0) {
                                                          iVar6 = create_text(this,this->
                                                  bottom_panel,this->player_inven_label + 3,0x280e);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->player_inven_label + 4
                                                                        ,0x2805);
                                                    if (iVar6 != 0) {
                                                      iVar6 = 0;
                                                      ppTVar15 = this->player_inven_input;
                                                      do {
                                                        iVar18 = create_edit(this,this->bottom_panel
                                                                             ,ppTVar15,s_0,5,
                                                                             FormatUnsignedInt,0,0);
                                                        if (iVar18 == 0) goto LAB_004b1a29;
                                                        iVar6 = iVar6 + 1;
                                                        ppTVar15 = ppTVar15 + 1;
                                                      } while (iVar6 < 4);
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 this->player_inven_input[0],0x76e8,
                                                                 1);
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 this->player_inven_input[1],0x76e9,
                                                                 1);
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 this->player_inven_input[2],0x76eb,
                                                                 1);
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 this->player_inven_input[3],0x76ea,
                                                                 1);
                                                      iVar6 = create_edit(this,this->bottom_panel,
                                                                          this->player_inven_input +
                                                                          4,s_,0x1c,FormatText,1,1);
                                                      if (iVar6 != 0) {
                                                        TPanel::set_help_info
                                                                  ((TPanel *)
                                                                   this->player_inven_input[4],
                                                                   0x76ec,1);
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  player_setting_label,0x2810);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->player_setting_label +
                                                                        1,0x2811);
                                                    if (iVar6 != 0) {
                                                      iVar6 = 0;
                                                      ppTVar12 = this->player_setting_drop;
                                                      do {
                                                        iVar18 = create_drop_down(this,this->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar18 == 0) goto LAB_004b1a29;
                                                  iVar6 = iVar6 + 1;
                                                  ppTVar12 = ppTVar12 + 1;
                                                  } while (iVar6 < 2);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->player_setting_drop[0],
                                                             0x76ed,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->player_setting_drop[1],
                                                             0x76ee,-1);
                                                  iVar6 = create_drop_down(this,this->bottom_panel,
                                                                           &this->BuildList);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->BuildList,0x76ef,-1);
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->CityLayout);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)this->CityLayout,0x76f0,
                                                                 -1);
                                                      iVar6 = create_drop_down(this,this->
                                                  bottom_panel,&this->AiRules);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->AiRules,0x76f1,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->player_build_text,
                                                                        0x2813);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->player_city_text,
                                                                          0x2814);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            &this->AiRules_text,
                                                                            0x2812);
                                                        if (iVar6 != 0) {
                                                          pcVar3 = *(code **)(this->_padding_ + 200)
                                                          ;
                                                          (*pcVar3)(this->player_inven_input,5);
                                                          iVar6 = create_check_box(this,this->
                                                  bottom_panel,this->victory_cond_on);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_on[0],
                                                               0x7704,-1);
                                                    iVar6 = create_check_box(this,this->bottom_panel
                                                                             ,this->victory_cond_on
                                                                              + 1);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)this->victory_cond_on[1],
                                                                 0x7706,-1);
                                                      iVar6 = create_check_box(this,this->
                                                  bottom_panel,this->victory_cond_on + 2);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_on[2],
                                                               0x7707,-1);
                                                    iVar6 = create_check_box(this,this->bottom_panel
                                                                             ,this->victory_cond_on
                                                                              + 3);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)this->victory_cond_on[3],
                                                                 0x7708,-1);
                                                      iVar6 = create_check_box(this,this->
                                                  bottom_panel,this->victory_cond_on + 4);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_on[4],
                                                               0x7709,-1);
                                                    iVar6 = create_check_box(this,this->bottom_panel
                                                                             ,this->victory_cond_on
                                                                              + 5);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)this->victory_cond_on[5],
                                                                 0x770a,-1);
                                                      ppTVar13 = this->victory_and_or;
                                                      iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar13,0x7701,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->victory_and_or + 1);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_and_or[1],
                                                               0x7703,-1);
                                                    iVar6 = 2;
                                                    ppTVar11 = ppTVar13;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar11,ppTVar13,2);
                                                      ppTVar11 = ppTVar11 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    TButtonPanel::set_radio_button(*ppTVar13);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->victory_text_and_or,
                                                                        0x28a2);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->victory_text_and_or
                                                                          + 1,0x28a3);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            &this->
                                                  victory_amount_label,0x28a4);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_long_label,
                                                                        0x28a5);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->
                                                  victory_condition_label,0x10e0);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->
                                                  victory_label_conquest,0x10e1);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_label_explore
                                                                        ,0x10e2);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->
                                                  victory_label_explore_percent,0x10e7);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_label_ruins,
                                                                        0x10e3);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->
                                                  victory_label_artifacts,0x10e4);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->
                                                  victory_label_discoveries,0x10e5);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_label_gold,
                                                                        0x10e6);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_edit(this,this->bottom_panel,
                                                                          &this->
                                                  victory_condition_explore,&s__,3,FormatUnsignedInt
                                                  ,0,0);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_condition_explore,
                                                               0x770b,-1);
                                                    iVar6 = create_edit(this,this->bottom_panel,
                                                                        &this->
                                                  victory_condition_ruins,&s__,2,FormatUnsignedInt,0
                                                  ,0);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_condition_ruins,0x770c,
                                                               -1);
                                                    ppTVar15 = &this->victory_condition_artifacts;
                                                    iVar6 = create_edit(this,this->bottom_panel,
                                                                        ppTVar15,&s__,2,
                                                                        FormatUnsignedInt,0,0);
                                                    if (iVar6 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar15,0x770d,-1);
                                                      ppTVar2 = &this->victory_condition_discoveries
                                                      ;
                                                      iVar6 = create_edit(this,this->bottom_panel,
                                                                          ppTVar2,&s__,2,
                                                                          FormatUnsignedInt,0,0);
                                                      if (iVar6 != 0) {
                                                        TPanel::set_help_info
                                                                  ((TPanel *)*ppTVar2,0x770e,-1);
                                                        iVar6 = create_edit(this,this->bottom_panel,
                                                                            &this->
                                                  victory_condition_gold,&s__,5,FormatUnsignedInt,0,
                                                  0);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_condition_gold,0x770f,
                                                               -1);
                                                    ptr[2] = (TPanel *)this->victory_condition_ruins
                                                    ;
                                                    ptr[1] = (TPanel *)
                                                             this->victory_condition_explore;
                                                    ptr[3] = (TPanel *)*ppTVar15;
                                                    str4._0_4_ = *ppTVar2;
                                                    (*pcVar3)(ptr + 1,4);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  victory_cond_type_label,0x10ec);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  victory_cond_type_label + 1,0x10e1);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  victory_cond_type_label + 2,0x10ea);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  victory_cond_type_label + 3,0x10e9);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->
                                                  victory_cond_type_label + 4,0x10eb);
                                                  if (iVar6 != 0) {
                                                    ppTVar13 = this->victory_cond_type;
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar13,0x7756,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->victory_cond_type + 1);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_type[1],
                                                               0x7757,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->victory_cond_type + 2);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_type[2],
                                                               0x7758,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->victory_cond_type + 3);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_type[3],
                                                               0x7759,-1);
                                                    iVar6 = create_radio_button(this,this->
                                                  bottom_panel,this->victory_cond_type + 4);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_cond_type[4],
                                                               0x775a,-1);
                                                    iVar6 = 5;
                                                    ppTVar11 = ppTVar13;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar11,ppTVar13,5);
                                                      ppTVar11 = ppTVar11 + 1;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    TButtonPanel::set_radio_button
                                                              (this->victory_cond_type[1]);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_score_label,
                                                                        0x10ea);
                                                    if (iVar6 != 0) {
                                                      ppTVar12 = &this->victory_score;
                                                      iVar6 = create_drop_down(this,this->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar12,0x775b,-1);
                                                    TDropDownPanel::empty_list(*ppTVar12);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_3000,3000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_2700,0xa8c);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_2400,0x960);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_2100,0x834);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_1800,0x708);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_1500,0x5dc);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,s_1200,0x4b0);
                                                    TDropDownPanel::append_line(*ppTVar12,s_900,900)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_800,800)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_700,700)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_600,600)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_500,500)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_400,400)
                                                    ;
                                                    TDropDownPanel::append_line(*ppTVar12,s_300,300)
                                                    ;
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_time_label,
                                                                        0x10e9);
                                                    if (iVar6 != 0) {
                                                      ppTVar12 = &this->victory_time;
                                                      iVar6 = create_drop_down(this,this->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar12,0x775c,-1);
                                                    TDropDownPanel::empty_list(*ppTVar12);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2634,15000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2635,13000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2636,11000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2637,9000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2638,7000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x2639,5000);
                                                    TDropDownPanel::append_line
                                                              (*ppTVar12,0x263a,3000);
                                                    ppTVar13 = this->victory_button;
                                                    iVar6 = 1;
                                                    do {
                                                      sprintf(str1 + 4,&s__d,iVar6);
                                                      sprintf(str2 + 4,s_<_d>,iVar6);
                                                      sprintf(str3 + 4,s__d_,iVar6);
                                                      sprintf(str4 + 4,s_<_d*>,iVar6);
                                                      iVar18 = create_button(this,this->bottom_panel
                                                                             ,ppTVar13,str1 + 4,
                                                                             str2 + 4,str3 + 4,
                                                                             str4 + 4);
                                                      if (iVar18 == 0) goto LAB_004b1a29;
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar13,0x7712,-1);
                                                      ppTVar13 = ppTVar13 + 1;
                                                      bVar4 = iVar6 < 0xc;
                                                      iVar6 = iVar6 + 1;
                                                    } while (bVar4);
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_drop_down);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_object_list);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_player_list);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_enemy_player_list);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_attribute_list);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_ages_list);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  victory_tech_list);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_drop_down,
                                                               0x7716,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_object_list,
                                                               0x7714,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_player_list,
                                                               0x7713,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_ages_list,
                                                               0x7715,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_enemy_player_list,
                                                               0x7760,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_attribute_list,0x7761,
                                                               -1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->victory_tech_list,
                                                               0x7762,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->
                                                  victory_condition_text,0x2870);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->
                                                  victory_condition_type,0x2871);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_button(this,this->bottom_panel,
                                                                          &this->
                                                  victory_button_set_object,0x2872,0);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_button(this,this->bottom_panel,
                                                                          &this->
                                                  victory_button_set_destination,0x2873,0);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_button(this,this->bottom_panel,
                                                                          &this->
                                                  victory_button_go_to_dest,0x2874,0);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_button_set_object,
                                                               0x7717,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_button_set_destination,
                                                               0x7718,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               this->victory_button_go_to_dest,
                                                               0x7719,-1);
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->victory_amount_text,
                                                                        0x2875);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          &this->
                                                  victory_which_enemy_text,0x2876);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_edit(this,this->bottom_panel,
                                                                        &this->victory_amount_input,
                                                                        s_0,5,FormatUnsignedInt,0,0)
                                                    ;
                                                    if (iVar6 != 0) {
                                                      ppTVar13 = this->message_button;
                                                      iVar6 = 0;
                                                      ppTVar11 = ppTVar13;
                                                      do {
                                                        iVar18 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar11);
                                                  if (iVar18 == 0) goto LAB_004b1a29;
                                                  iVar6 = iVar6 + 1;
                                                  ppTVar11 = ppTVar11 + 1;
                                                  } while (iVar6 < 5);
                                                  this->current_message = 0;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar13,0x771c,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->message_button[1],
                                                             0x771d,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->message_button[2],
                                                             0x771e,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->message_button[3],
                                                             0x771f,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->message_button[4],
                                                             0x7720,-1);
                                                  iVar6 = create_text(this,this->bottom_panel,
                                                                      this->message_button_label,
                                                                      0x2a36);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->message_button_label +
                                                                        1,0x2a37);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->message_button_label
                                                                          + 2,0x2a38);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  message_button_label + 3,0x2a39);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->message_button_label +
                                                                        4,0x2a31);
                                                    if (iVar6 != 0) {
                                                      iVar6 = 5;
                                                      ppTVar11 = ppTVar13;
                                                      do {
                                                        TButtonPanel::set_radio_info
                                                                  (*ppTVar11,ppTVar13,5);
                                                        ppTVar11 = ppTVar11 + 1;
                                                        iVar6 = iVar6 + -1;
                                                      } while (iVar6 != 0);
                                                      iVar6 = create_edit(this,this->bottom_panel,
                                                                          &this->message_input,s_,
                                                                          0xfff,FormatMultiLine,1,1)
                                                      ;
                                                      if (iVar6 != 0) {
                                                        TPanel::set_help_info
                                                                  ((TPanel *)this->message_input,-1,
                                                                   -1);
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->cinematic_label,
                                                                            0x2af9);
                                                        if (iVar6 != 0) {
                                                          iVar6 = create_text(this,this->
                                                  bottom_panel,this->cinematic_label + 1,0x2afa);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->cinematic_label + 2,
                                                                        0x2afb);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->cinematic_label + 3,
                                                                          0x2afc);
                                                      if (iVar6 != 0) {
                                                        iVar6 = 0;
                                                        ppTVar12 = this->cinematic_input;
                                                        do {
                                                          iVar18 = create_drop_down(this,this->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar18 == 0) goto LAB_004b1a29;
                                                  iVar6 = iVar6 + 1;
                                                  ppTVar12 = ppTVar12 + 1;
                                                  } while (iVar6 < 4);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->cinematic_input[0],
                                                             0x7724,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->cinematic_input[1],
                                                             0x7725,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->cinematic_input[2],
                                                             0x7726,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->cinematic_input[3],
                                                             0x7727,-1);
                                                  iVar6 = create_text(this,this->bottom_panel,
                                                                      this->options_label,0x2604);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        &this->
                                                  options_disable_tech_text,0x32d7);
                                                  if (iVar6 != 0) {
                                                    iVar6 = 0;
                                                    ppTVar13 = this->options_button;
                                                    do {
                                                      iVar18 = create_check_box(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar18 == 0) goto LAB_004b1a29;
                                                  iVar6 = iVar6 + 1;
                                                  ppTVar13 = ppTVar13 + 1;
                                                  } while (iVar6 < 1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)this->options_button[0],
                                                             0x7729,-1);
                                                  iVar6 = create_drop_down(this,this->bottom_panel,
                                                                           &this->
                                                  options_player_list);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->options_player_list,
                                                               0x772b,-1);
                                                    iVar6 = 0;
                                                    ppTVar13 = this->options_disable_button;
                                                    do {
                                                      iVar18 = create_check_box(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar18 == 0) goto LAB_004b1a29;
                                                  iVar6 = iVar6 + 1;
                                                  ppTVar13 = ppTVar13 + 1;
                                                  } while (iVar6 < 0x10);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0],0x772c,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[1],0x772d,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[2],0x772e,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[3],0x772f,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[4],0x7730,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[5],0x7731,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[6],0x7732,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[7],0x7733,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[8],0x7734,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[9],0x7735,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[10],0x7736
                                                             ,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0xb],
                                                             0x7737,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0xc],
                                                             0x7738,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0xd],
                                                             0x7739,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0xe],
                                                             0x773a,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             this->options_disable_button[0xf],
                                                             0x773b,-1);
                                                  iVar6 = create_text(this,this->bottom_panel,
                                                                      this->options_disable_text,
                                                                      0x32c9);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->options_disable_text +
                                                                        1,0x32ca);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->options_disable_text
                                                                          + 2,0x32cb);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  options_disable_text + 3,0x32cc);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->options_disable_text +
                                                                        4,0x32cd);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->options_disable_text
                                                                          + 5,0x32ce);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  options_disable_text + 6,0x32cf);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->options_disable_text +
                                                                        7,0x32d0);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->options_disable_text
                                                                          + 8,0x32d1);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  options_disable_text + 9,0x32d2);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->options_disable_text +
                                                                        10,0x32d3);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->options_disable_text
                                                                          + 0xb,0x32d4);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  options_disable_text + 0xc,0x32d5);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->options_disable_text +
                                                                        0xd,0x32d6);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->options_disable_text
                                                                          + 0xe,0x32d8);
                                                      if (iVar6 != 0) {
                                                        iVar6 = create_text(this,this->bottom_panel,
                                                                            this->
                                                  options_disable_text + 0xf,0x32d9);
                                                  if (iVar6 != 0) {
                                                    iVar6 = 0;
                                                    ppTVar14 = this->Diplomacy_player_text;
                                                    do {
                                                      iVar6 = iVar6 + 1;
                                                      sprintf(str1 + 4,&s__d,iVar6);
                                                      iVar18 = create_text(this,this->bottom_panel,
                                                                           ppTVar14,str1 + 4);
                                                      if (iVar18 == 0) goto LAB_004b1a29;
                                                      ppTVar14 = ppTVar14 + 1;
                                                    } while (iVar6 < 8);
                                                    iVar6 = create_drop_down(this,this->bottom_panel
                                                                             ,&this->
                                                  Diplomacy_player_list);
                                                  if (iVar6 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)this->Diplomacy_player_list
                                                               ,0x773d,-1);
                                                    ptr[0] = (TPanel *)this->Diplomacy_AlliedVictory
                                                    ;
                                                    iStack_1c8 = 0;
                                                    papTVar16 = this->Diplomacy_friend_box;
                                                    do {
                                                      iVar6 = create_radio_button(this,this->
                                                  bottom_panel,*papTVar16);
                                                  if (iVar6 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)(*papTVar16)[0],0x773f,-1);
                                                  ppTVar13 = *papTVar16 + 1;
                                                  iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar13);
                                                  if (iVar6 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar13,0x7740,-1);
                                                  ppTVar11 = *papTVar16 + 2;
                                                  iVar6 = create_radio_button(this,this->
                                                  bottom_panel,ppTVar11);
                                                  if (iVar6 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar11,0x7741,-1);
                                                  TButtonPanel::set_radio_info
                                                            ((*papTVar16)[0],*papTVar16,3);
                                                  TButtonPanel::set_radio_info
                                                            (*ppTVar13,*papTVar16,3);
                                                  TButtonPanel::set_radio_info
                                                            (*ppTVar11,*papTVar16,3);
                                                  TButtonPanel::set_radio_button(*ppTVar13);
                                                  iVar6 = create_check_box(this,this->bottom_panel,
                                                                           (TButtonPanel **)ptr[0]);
                                                  pTVar5 = ptr[0];
                                                  if (iVar6 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)ptr[0]->_padding_,0x773e,-1);
                                                  ptr[0] = (TPanel *)&pTVar5->previousPanelValue;
                                                  iStack_1c8 = iStack_1c8 + 1;
                                                  papTVar16 = papTVar16 + 1;
                                                  } while (iStack_1c8 < 8);
                                                  iVar6 = create_text(this,this->bottom_panel,
                                                                      this->Diplomacy_status_label,
                                                                      0x29cd);
                                                  if (iVar6 != 0) {
                                                    iVar6 = create_text(this,this->bottom_panel,
                                                                        this->Diplomacy_status_label
                                                                        + 1,0x29ce);
                                                    if (iVar6 != 0) {
                                                      iVar6 = create_text(this,this->bottom_panel,
                                                                          this->
                                                  Diplomacy_status_label + 2,0x29cf);
                                                  if (iVar6 != 0) {
                                                    create_text(this,this->bottom_panel,
                                                                this->Diplomacy_status_label + 3,
                                                                0x29d0);
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
                                                  goto LAB_004b1a29;
                                                  }
                                                  }
                                                  }
LAB_004b1a1f:
                                                  this->_padding_ = 1;
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
  }
LAB_004b1a29:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: position_panels
// Address: 004b1a50
void __thiscall TRIBE_Screen_Sed::position_panels(TRIBE_Screen_Sed *this)
{
  TButtonPanel *pTVar1;
  int iVar2;
  uint uVar3;
  TEditPanel **ppTVar4;
  TButtonPanel **ppTVar5;
  TDropDownPanel **ppTVar6;
  TTextPanel **ppTVar7;
  TButtonPanel **ppTVar8;
  int iVar9;
  TScrollBarPanel *this_00;
  uint uVar10;
  
  if (this->main_view != (TRIBE_Main_View *)0x0) {
    iVar9 = 0;
    do {
      if (iVar9 == 0) {
        pTVar1 = (TButtonPanel *)0x0;
      }
      else {
        pTVar1 = this->scenario_mode_button[iVar9 + -1];
      }
      (**(code **)(this->scenario_mode_button[iVar9]->_padding_ + 0x18))
                (7,2,2,2,2,0x32,0x6d,0x16,0x16,pTVar1,0,0,0);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 5);
    iVar9 = 5;
    do {
      if (iVar9 == 5) {
        pTVar1 = (TButtonPanel *)0x0;
      }
      else {
        pTVar1 = this->scenario_mode_button[iVar9 + -1];
      }
      (**(code **)(this->scenario_mode_button[iVar9]->_padding_ + 0x18))
                (7,2,2,2,2,0x32,0x6d,0x16,0x16,pTVar1,this->scenario_mode_button[iVar9 + -5],0,0);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 10);
    (**(code **)(this->menu_button->_padding_ + 0x18))(9,2,5,3,3,0x3a,0x3a,0x14,0x28,0,0,0,0);
    (**(code **)(this->help_button->_padding_ + 0x18))(10,5,5,5,5,0x14,0x1e,0x14,0x1e,0,0,0,0);
    (**(code **)(*(int *)this->map_view + 0x18))(10,0,0,0,0,0xe6,0xe6,0x87,0x87,0,0,0,0);
    (**(code **)(this->bottom_panel->_padding_ + 0x18))
              (8,2,2,2,2,0,0,0x89,0x89,0,0,this->map_view,0);
    (**(code **)(this->unit_list->_padding_ + 0x18))
              (7,0,6,0,4,0x7c,200,0,0,0,this->menu_button,0,this->bottom_panel);
    (**(code **)(this->object_panel->_padding_ + 0x18))(8,4,4,4,4,0x96,0x96,0x6c,0x6c,0,0,0,0);
    this_00 = (TScrollBarPanel *)this->unit_list;
    iVar9 = TTextPanel::numberLines((TTextPanel *)this_00);
    iVar2 = TTextPanel::numberDrawLines((TTextPanel *)this_00);
    if (iVar2 < iVar9) {
      (**(code **)(this->unit_list->_padding_ + 0x18))
                (7,0,6,0,4,0x68,0xdc,0,0,0,this->menu_button,0,this->bottom_panel);
      (**(code **)(this->unit_scrollbar->_padding_ + 0x18))
                (7,1,1,0,2,0x12,0x12,0,0,this->unit_list,this->menu_button,0,this->bottom_panel);
      this_00 = this->unit_scrollbar;
    }
    (**(code **)(*(int *)this->main_view + 0x18))
              (7,0,6,0,4,0,0,0,0,this_00,this->menu_button,0,this->bottom_panel);
    (**(code **)(this->message_panel->_padding_ + 0x18))(8,4,4,4,4,0,0,0x18,0x18,0,0,0,0);
    (**(code **)(this->map_type_label->_padding_ + 0x1c))(4,4,0x78,0x16);
    (**(code **)(this->map_type_button[0]->_padding_ + 0x1c))(4,0x16,0x16,0x16);
    (**(code **)(this->map_type_button[1]->_padding_ + 0x1c))(4,0x2c,0x16,0x16);
    (**(code **)(this->map_type_button[2]->_padding_ + 0x1c))(4,0x42,0x16,0x16);
    (**(code **)(this->map_type_text[0]->_padding_ + 0x1c))(0x24,0x16,0x73,0x16);
    (**(code **)(this->map_type_text[1]->_padding_ + 0x1c))(0x24,0x2c,0x73,0x16);
    (**(code **)(this->map_type_text[2]->_padding_ + 0x1c))(0x24,0x42,0x73,0x16);
    (**(code **)(this->map_size_label->_padding_ + 0x1c))(0xaa,4,0x82,0x16);
    (**(code **)(this->map_size_drop->_padding_ + 0x1c))(0xaa,0x16,0xaa,0x16);
    (**(code **)(this->map_style_label->_padding_ + 0x1c))(0xaa,0x30,0x82,0x16);
    (**(code **)(this->map_style_drop->_padding_ + 0x1c))(0xaa,0x42,0xaa,0x16);
    (**(code **)(this->default_terrain_label->_padding_ + 0x1c))(0xaa,0x30,0x82,0x16);
    (**(code **)(this->default_terrain_drop->_padding_ + 0x1c))(0xaa,0x42,0xaa,0x16);
    (**(code **)(this->random_seed_label->_padding_ + 0x1c))(0x24,0x5a,0x78,0x16);
    (**(code **)(this->random_seed_input->_padding_ + 0x1c))(0x24,0x70,0x37,0x16);
    (**(code **)(this->random_seed_used_label->_padding_ + 0x1c))(0x24,0x5a,0x78,0x16);
    (**(code **)(this->random_seed_used_text->_padding_ + 0x1c))(0x24,0x70,0x37,0x16);
    (**(code **)(this->generate_map_button->_padding_ + 0x1c))(0xb4,0x60,0x82,0x26);
    (**(code **)(this->paint_terrain_list->_padding_ + 0x1c))(0x73,0x17,0xa5,0x6e);
    (**(code **)(this->paint_terrain_label->_padding_ + 0x1c))(0x73,1,0x3c,0x16);
    (**(code **)(this->paint_elevation_list->_padding_ + 0x1c))(0x73,0x17,0xa5,0x6e);
    (**(code **)(this->paint_type_label->_padding_ + 0x1c))(2,1,0x6e,0x14);
    (**(code **)(this->paint_type_button[0]->_padding_ + 0x1c))(2,0x17,0x1e,0x16);
    (**(code **)(this->paint_type_button[1]->_padding_ + 0x1c))(2,0x2d,0x1e,0x16);
    (**(code **)(this->paint_type_button[2]->_padding_ + 0x1c))(2,0x43,0x1e,0x16);
    (**(code **)(this->paint_type_button_label[0]->_padding_ + 0x1c))(0x21,0x17,0x51,0x16);
    (**(code **)(this->paint_type_button_label[1]->_padding_ + 0x1c))(0x21,0x2d,0x51,0x16);
    (**(code **)(this->paint_type_button_label[2]->_padding_ + 0x1c))(0x21,0x43,0x51,0x16);
    (**(code **)(this->brush_size_label->_padding_ + 0x1c))(0x118,4,0x6e,0x14);
    (**(code **)(this->brush_size_button[0]->_padding_ + 0x1c))(0x11a,0x17,0x1e,0x16);
    (**(code **)(this->brush_size_button[1]->_padding_ + 0x1c))(0x11a,0x2d,0x1e,0x16);
    (**(code **)(this->brush_size_button[2]->_padding_ + 0x1c))(0x11a,0x43,0x1e,0x16);
    (**(code **)(this->brush_size_button[3]->_padding_ + 0x1c))(0x11a,0x59,0x1e,0x16);
    (**(code **)(this->brush_size_button[4]->_padding_ + 0x1c))(0x11a,0x6f,0x1e,0x16);
    (**(code **)(this->brush_size_button_label[0]->_padding_ + 0x1c))(0x139,0x17,0x5a,0x16);
    (**(code **)(this->brush_size_button_label[1]->_padding_ + 0x1c))(0x139,0x2d,0x5a,0x16);
    (**(code **)(this->brush_size_button_label[2]->_padding_ + 0x1c))(0x139,0x43,0x5a,0x16);
    (**(code **)(this->brush_size_button_label[3]->_padding_ + 0x1c))(0x139,0x59,0x5a,0x16);
    (**(code **)(this->brush_size_button_label[4]->_padding_ + 0x1c))(0x139,0x6f,0x5a,0x16);
    (**(code **)(this->player_label->_padding_ + 0x1c))(4,4,0x50,0x12);
    (**(code **)(this->player_starting_age_label->_padding_ + 0x1c))(4,0x5c,0x5f,0x12);
    (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x1c))(4,0x6e,0x96,0x16);
    (**(code **)(this->player_label->_padding_ + 0x1c))(4,0x2a,0x96,0x12);
    (**(code **)(this->player_list->_padding_ + 0x1c))(4,7,0x96,0x16);
    (**(code **)(this->player_number_list->_padding_ + 0x1c))(4,0x3e,0x96,0x16);
    iVar9 = 0xa6;
    ppTVar4 = this->player_inven_input;
    do {
      iVar2 = 0x19;
      do {
        (**(code **)(((TTextPanel *)ppTVar4[-5])->_padding_ + 0x1c))(iVar9,iVar2 + -0x12,0x37,0x12);
        (**(code **)((*ppTVar4)->_padding_ + 0x1c))(iVar9,iVar2,0x37,0x16);
        iVar2 = iVar2 + 0x2c;
        ppTVar4 = ppTVar4 + 1;
      } while (iVar2 < 0x71);
      iVar9 = iVar9 + 0x44;
    } while (iVar9 < 0x12e);
    (**(code **)(this->player_inven_label[4]->_padding_ + 0x1c))(0xa6,0x5c,100,0x12);
    (**(code **)(this->player_inven_input[4]->_padding_ + 0x1c))(0xa6,0x6e,0x7d,0x16);
    iVar9 = 0x19;
    ppTVar6 = this->player_setting_drop;
    do {
      (**(code **)(((TTextPanel *)ppTVar6[-3])->_padding_ + 0x1c))(500,iVar9 + -0x12,0x82,0x12);
      (**(code **)((*ppTVar6)->_padding_ + 0x1c))(500,iVar9,0x82,0x16);
      iVar9 = iVar9 + 0x2c;
      ppTVar6 = ppTVar6 + 1;
    } while (iVar9 < 0x71);
    (**(code **)(this->BuildList->_padding_ + 0x1c))(300,0x45,0xbe,0x16);
    (**(code **)(this->CityLayout->_padding_ + 0x1c))(300,0x19,0xbe,0x16);
    (**(code **)(this->player_build_text->_padding_ + 0x1c))(300,0x33,0x82,0x12);
    (**(code **)(this->player_city_text->_padding_ + 0x1c))(300,7,0x82,0x12);
    (**(code **)(this->AiRules_text->_padding_ + 0x1c))(300,0x5c,0x82,0x12);
    (**(code **)(this->AiRules->_padding_ + 0x1c))(300,0x6e,0xbe,0x16);
    (**(code **)(this->unit_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    (**(code **)(this->unit_mode_select[0]->_padding_ + 0x1c))(0xa0,0x16,0x1e,0x16);
    (**(code **)(this->unit_mode_select[1]->_padding_ + 0x1c))(0xa0,0x30,0x1e,0x16);
    (**(code **)(this->unit_mode_select[2]->_padding_ + 0x1c))(0xa0,0x4a,0x1e,0x16);
    (**(code **)(this->unit_mode_select[3]->_padding_ + 0x1c))(0xa0,0x62,0x1e,0x16);
    (**(code **)(this->unit_mode_select_label[0]->_padding_ + 0x1c))(0xc0,0x16,0x6e,0x16);
    (**(code **)(this->unit_mode_select_label[1]->_padding_ + 0x1c))(0xc0,0x30,0x6e,0x16);
    (**(code **)(this->unit_mode_select_label[2]->_padding_ + 0x1c))(0xc0,0x4a,0x6e,0x16);
    (**(code **)(this->unit_mode_select_label[3]->_padding_ + 0x1c))(0xc0,0x62,0x6e,0x16);
    (**(code **)(this->victory_condition_label->_padding_ + 0x1c))(0x22,0,0x78,0x12);
    (**(code **)(this->victory_cond_type[0]->_padding_ + 0x1c))(0xe,0x12,0x14,0x12);
    (**(code **)(this->victory_cond_type[1]->_padding_ + 0x1c))(0xe,0x26,0x14,0x12);
    (**(code **)(this->victory_cond_type[2]->_padding_ + 0x1c))(0xe,0x3a,0x14,0x12);
    (**(code **)(this->victory_cond_type[3]->_padding_ + 0x1c))(0xe,0x4e,0x14,0x12);
    (**(code **)(this->victory_cond_type[4]->_padding_ + 0x1c))(0xe,0x62,0x14,0x12);
    (**(code **)(this->victory_cond_type_label[0]->_padding_ + 0x1c))(0x22,0x12,0x78,0x12);
    (**(code **)(this->victory_cond_type_label[1]->_padding_ + 0x1c))(0x22,0x26,0x78,0x12);
    (**(code **)(this->victory_cond_type_label[2]->_padding_ + 0x1c))(0x22,0x3a,0x78,0x12);
    (**(code **)(this->victory_cond_type_label[3]->_padding_ + 0x1c))(0x22,0x4e,0x78,0x12);
    (**(code **)(this->victory_cond_type_label[4]->_padding_ + 0x1c))(0x22,0x62,0x78,0x12);
    (**(code **)(this->victory_score_label->_padding_ + 0x1c))(0xa4,0x12,100,0x12);
    (**(code **)(this->victory_score->_padding_ + 0x1c))(0xa4,0x28,100,0x16);
    (**(code **)(this->victory_time_label->_padding_ + 0x1c))(0xa4,0x12,0xdc,0x12);
    (**(code **)(this->victory_time->_padding_ + 0x1c))(0xa4,0x28,0xdc,0x16);
    (**(code **)(this->victory_cond_on[0]->_padding_ + 0x1c))(0xa4,0x12,0x14,0x12);
    (**(code **)(this->victory_cond_on[1]->_padding_ + 0x1c))(0xa4,0x26,0x14,0x12);
    (**(code **)(this->victory_cond_on[2]->_padding_ + 0x1c))(0xa4,0x3a,0x14,0x12);
    (**(code **)(this->victory_cond_on[3]->_padding_ + 0x1c))(0xa4,0x4e,0x14,0x12);
    (**(code **)(this->victory_cond_on[4]->_padding_ + 0x1c))(0xa4,0x62,0x14,0x12);
    (**(code **)(this->victory_cond_on[5]->_padding_ + 0x1c))(0xa4,0x76,0x14,0x12);
    (**(code **)(this->victory_label_conquest->_padding_ + 0x1c))(0xb8,0x12,0x82,0x12);
    (**(code **)(this->victory_label_explore->_padding_ + 0x1c))(0xb8,0x26,0x82,0x12);
    (**(code **)(this->victory_label_ruins->_padding_ + 0x1c))(0xb8,0x3a,0x82,0x12);
    (**(code **)(this->victory_label_artifacts->_padding_ + 0x1c))(0xb8,0x4e,0x82,0x12);
    (**(code **)(this->victory_label_discoveries->_padding_ + 0x1c))(0xb8,0x62,0x82,0x12);
    (**(code **)(this->victory_amount_label->_padding_ + 0x1c))(0x126,0,0x5a,0x12);
    (**(code **)(this->victory_condition_explore->_padding_ + 0x1c))(0x126,0x26,0x3c,0x12);
    (**(code **)(this->victory_condition_ruins->_padding_ + 0x1c))(0x126,0x3a,0x3c,0x12);
    (**(code **)(this->victory_condition_artifacts->_padding_ + 0x1c))(0x126,0x4e,0x3c,0x12);
    (**(code **)(this->victory_condition_discoveries->_padding_ + 0x1c))(0x126,0x62,0x3c,0x12);
    (**(code **)(this->victory_and_or[0]->_padding_ + 0x1c))(0x180,0x12,0x14,0x12);
    (**(code **)(this->victory_and_or[1]->_padding_ + 0x1c))(0x180,0x26,0x14,0x12);
    (**(code **)(this->victory_text_and_or[0]->_padding_ + 0x1c))(0x194,0x12,0x5a,0x12);
    (**(code **)(this->victory_text_and_or[1]->_padding_ + 0x1c))(0x194,0x26,0x5a,0x12);
    uVar10 = 0;
    ppTVar5 = this->victory_button;
    do {
      uVar3 = (int)uVar10 >> 0x1f;
      (**(code **)((*ppTVar5)->_padding_ + 0x1c))
                (((int)(uVar10 + (uVar3 & 3)) >> 2) * 0x30 + 0xdc,
                 (((uVar10 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3) * 0x1a + 0x1e,0x2c,0x16);
      uVar10 = uVar10 + 1;
      ppTVar5 = ppTVar5 + 1;
    } while ((int)uVar10 < 0xc);
    (**(code **)(this->victory_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    (**(code **)(this->victory_drop_down->_padding_ + 0x1c))(4,0x1c,0xb4,0x16);
    (**(code **)(this->victory_condition_text->_padding_ + 0x1c))(0xdc,4,0x8c,0x16);
    (**(code **)(this->victory_button_set_object->_padding_ + 0x1c))(4,0x38,0x96,0x16);
    (**(code **)(this->victory_button_set_destination->_padding_ + 0x1c))(4,0x52,0x96,0x16);
    (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x1c))(4,0x6c,0x96,0x16);
    (**(code **)(this->victory_amount_text->_padding_ + 0x1c))(0xa0,0x50,0x3c,0x16);
    (**(code **)(this->victory_amount_input->_padding_ + 0x1c))(0xa0,0x66,0x32,0x16);
    (**(code **)(this->victory_enemy_player_list->_padding_ + 0x1c))(4,0x66,0x96,0x16);
    (**(code **)(this->victory_attribute_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(this->victory_which_enemy_text->_padding_ + 0x1c))(4,0x50,0x96,0x16);
    (**(code **)(this->victory_object_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(this->victory_ages_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(this->victory_tech_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    iVar9 = 8;
    ppTVar7 = this->message_button_label;
    do {
      (**(code **)(((TButtonPanel *)ppTVar7[-5])->_padding_ + 0x1c))(4,iVar9,0x1e,0x12);
      (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x24,iVar9,0x82,0x12);
      iVar9 = iVar9 + 0x19;
      ppTVar7 = ppTVar7 + 1;
    } while (iVar9 < 0x85);
    (**(code **)(this->message_input->_padding_ + 0x18))(7,0xaf,4,0x28,4,0,0,0,0,0,0,0,0);
    iVar9 = 0x16;
    ppTVar6 = this->cinematic_input;
    do {
      (**(code **)(((TTextPanel *)ppTVar6[-4])->_padding_ + 0x1c))(4,iVar9 + -0x12,0xaa,0x12);
      (**(code **)((*ppTVar6)->_padding_ + 0x1c))(4,iVar9,0xaa,0x16);
      iVar9 = iVar9 + 0x2c;
      ppTVar6 = ppTVar6 + 1;
    } while (iVar9 < 0x9a);
    (**(code **)(this->cinematic_label[3]->_padding_ + 0x1c))(0xb2,4,0xaa,0x12);
    (**(code **)(this->cinematic_input[3]->_padding_ + 0x1c))(0xb2,0x16,0xaa,0x16);
    iVar9 = 0x2c;
    ppTVar5 = (TButtonPanel **)this->options_label;
    do {
      (**(code **)(ppTVar5[1]->_padding_ + 0x1c))(3,iVar9,0x14,0x14);
      (**(code **)((*ppTVar5)->_padding_ + 0x1c))(0x16,iVar9,0x87,0x14);
      iVar9 = iVar9 + 0x1a;
      ppTVar5 = ppTVar5 + 1;
    } while (iVar9 < 0x46);
    (**(code **)(this->options_disable_tech_text->_padding_ + 0x1c))(0xa0,3,0xa0,0x16);
    (**(code **)(this->options_player_list->_padding_ + 0x1c))(3,3,0x96,0x16);
    ppTVar7 = this->options_disable_text;
    iVar9 = 0x1a;
    do {
      (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0xa0,iVar9,0x14,0x14);
      (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0xb4,iVar9,0x87,0x14);
      iVar9 = iVar9 + 0x14;
      ppTVar7 = ppTVar7 + 1;
    } while (iVar9 < 0x7e);
    ppTVar7 = this->options_disable_text + 5;
    iVar9 = 0x1a;
    do {
      (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0x13b,iVar9,0x14,0x14);
      (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x14f,iVar9,0x87,0x14);
      iVar9 = iVar9 + 0x14;
      ppTVar7 = ppTVar7 + 1;
    } while (iVar9 < 0x7e);
    ppTVar7 = this->options_disable_text + 10;
    iVar9 = 6;
    do {
      (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0x1d6,iVar9,0x14,0x14);
      (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x1ea,iVar9,0x87,0x14);
      iVar9 = iVar9 + 0x14;
      ppTVar7 = ppTVar7 + 1;
    } while (iVar9 < 0x7e);
    (**(code **)(this->Diplomacy_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    iVar9 = 0x96;
    ppTVar5 = this->Diplomacy_AlliedVictory;
    ppTVar8 = this->Diplomacy_friend_box[0] + 1;
    do {
      (**(code **)(((TTextPanel *)ppTVar5[-0x25])->_padding_ + 0x1c))(iVar9,0x1c,0x1e,0x16);
      (**(code **)((*(TButtonPanel *(*) [3])(ppTVar8 + -1))[0]->_padding_ + 0x1c))
                (iVar9,0x34,0x1a,0x12);
      (**(code **)((*ppTVar8)->_padding_ + 0x1c))(iVar9,0x48,0x1a,0x12);
      (**(code **)(ppTVar8[1]->_padding_ + 0x1c))(iVar9,0x5c,0x1a,0x12);
      (**(code **)((*ppTVar5)->_padding_ + 0x1c))(iVar9,0x70,0x1a,0x12);
      iVar9 = iVar9 + 0x1f;
      ppTVar5 = ppTVar5 + 1;
      ppTVar8 = ppTVar8 + 3;
    } while (iVar9 < 0x18e);
    (**(code **)(this->Diplomacy_status_label[0]->_padding_ + 0x1c))(2,0x34,0x91,0x16);
    (**(code **)(this->Diplomacy_status_label[1]->_padding_ + 0x1c))(2,0x48,0x91,0x16);
    (**(code **)(this->Diplomacy_status_label[2]->_padding_ + 0x1c))(2,0x5c,0x91,0x16);
    (**(code **)(this->Diplomacy_status_label[3]->_padding_ + 0x1c))(2,0x70,0x91,0x16);
  }
  return;
}

// --------------------------------------------------

// Function: activate_victory_panel
// Address: 004b29e0
void __thiscall TRIBE_Screen_Sed::activate_victory_panel(TRIBE_Screen_Sed *this,int param_1)
{
  int iVar1;
  long lVar2;
  TButtonPanel **ppTVar3;
  int iVar4;
  
  iVar4 = 0;
  ppTVar3 = this->victory_button;
  do {
    (**(code **)((*ppTVar3)->_padding_ + 0x14))(param_1);
    iVar1 = T_Scenario::GetSPVictoryType((T_Scenario *)this->world->_padding_,iVar4);
    if (param_1 != 0) {
      (**(code **)((*ppTVar3)->_padding_ + 0xe0))
                ((-(iVar1 != 0) & 2U) + (this->CurrentVictory == iVar4));
    }
    iVar4 = iVar4 + 1;
    ppTVar3 = ppTVar3 + 1;
  } while (iVar4 < 0xc);
  (**(code **)(this->victory_drop_down->_padding_ + 0x14))(param_1);
  (**(code **)(this->victory_condition_text->_padding_ + 0x14))(param_1);
  (**(code **)(this->victory_player_list->_padding_ + 0x14))(param_1);
  if (param_1 != 0) {
    TDropDownPanel::set_line(this->victory_player_list,this->player_num + -1);
    return;
  }
  lVar2 = TDropDownPanel::get_line(this->victory_player_list);
  this->player_num = (short)lVar2 + 1;
  return;
}

// --------------------------------------------------

// Function: MakeFileList
// Address: 004b2aa0
// [HELPER] s__s__s: "%s\n%s"
int __thiscall
TRIBE_Screen_Sed::MakeFileList
          (TRIBE_Screen_Sed *this,TDropDownPanel *param_1,char *param_2,char *param_3,uchar param_4,
          uchar param_5)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int count;
  int extension_strlen;
  _finddata_t fileInfo;
  char file_name [260];
  char path [260];
  
  extension_strlen = 0;
  TDropDownPanel::empty_list(param_1);
  if (param_4 != '\0') {
    TDropDownPanel::append_line(param_1,0x2775,0);
  }
  if (param_5 != '\0') {
    TDropDownPanel::append_line(param_1,0x277b,0);
  }
  sprintf(path + 4,s__s__s,param_2,param_3);
  iVar2 = __findfirst(path + 4,&fileInfo.time_create);
  uVar3 = 0xffffffff;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *param_3;
    param_3 = param_3 + 1;
  } while (cVar1 != '\0');
  fileInfo.attrib = ~uVar3 - 1;
  iVar4 = iVar2;
  do {
    if (iVar4 == -1) {
      return extension_strlen;
    }
    uVar3 = 0xffffffff;
    extension_strlen = extension_strlen + 1;
    pcVar5 = fileInfo.name + 4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = (~uVar3 - 1) - fileInfo.attrib;
    strncpy(file_name + 4,fileInfo.name + 4,iVar4);
    file_name[iVar4 + 4] = '\0';
    TDropDownPanel::append_line(param_1,file_name + 4,0);
    iVar4 = __findnext(iVar2,&fileInfo.time_create);
  } while( true );
}

// --------------------------------------------------

// Function: Set_player_advance_civilization_text
// Address: 004b2bc0
int __thiscall
TRIBE_Screen_Sed::Set_player_advance_civilization_text(TRIBE_Screen_Sed *this,int param_1)
{
  TDropDownPanel::empty_list(this->player_advance_civilization_drop);
  TDropDownPanel::append_line(this->player_advance_civilization_drop,0x1069,0);
  TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106a,1);
  TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106b,2);
  TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106c,3);
  TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106d,4);
  TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,0);
  (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: SavePlayerActiveStatus
// Address: 004b2c50
void __thiscall TRIBE_Screen_Sed::SavePlayerActiveStatus(TRIBE_Screen_Sed *this)
{
  long lVar1;
  TRIBE_World *pTVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  lVar1 = TDropDownPanel::get_line(this->player_number_list);
  pTVar2 = this->world;
  iVar4 = lVar1 + 1;
  iVar5 = 0;
  iVar3 = (int)(short)pTVar2->_padding_;
  if (iVar3 != 1 && -1 < iVar3 + -1) {
    do {
      RGE_Scenario::Set_player_Active((RGE_Scenario *)pTVar2->_padding_,iVar5,(uint)(iVar5 < iVar4))
      ;
      pTVar2 = this->world;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (short)pTVar2->_padding_ + -1);
  }
  TDropDownPanel::empty_list(this->victory_player_list);
  TDropDownPanel::empty_list(this->victory_enemy_player_list);
  TDropDownPanel::empty_list(this->options_player_list);
  TDropDownPanel::empty_list(this->Diplomacy_player_list);
  TDropDownPanel::empty_list(this->player_list);
  TDropDownPanel::empty_list(this->unit_player_list);
  TDropDownPanel::append_line(this->unit_player_list,0x2776,0);
  if (0 < iVar4) {
    iVar3 = 0x2865;
    do {
      TDropDownPanel::append_line(this->unit_player_list,iVar3,0);
      TDropDownPanel::append_line(this->victory_player_list,iVar3,0);
      TDropDownPanel::append_line(this->victory_enemy_player_list,iVar3,0);
      TDropDownPanel::append_line(this->options_player_list,iVar3,0);
      TDropDownPanel::append_line(this->Diplomacy_player_list,iVar3,0);
      TDropDownPanel::append_line(this->player_list,iVar3,0);
      iVar5 = iVar3 + -0x2864;
      iVar3 = iVar3 + 1;
    } while (iVar5 < iVar4);
  }
  if (iVar4 <= this->player_num) {
    set_player(this,(short)iVar4,'\0','\0');
  }
  TDropDownPanel::set_line(this->victory_player_list,this->player_num + -1);
  TDropDownPanel::set_line(this->options_player_list,this->player_num + -1);
  TDropDownPanel::set_line(this->Diplomacy_player_list,this->player_num + -1);
  TDropDownPanel::set_line(this->player_list,this->player_num + -1);
  TDropDownPanel::set_line(this->unit_player_list,(int)this->player_num);
  return;
}

// --------------------------------------------------

// Function: create_check_box
// Address: 004b2dd0
int __thiscall
TRIBE_Screen_Sed::create_check_box(TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_check_box((TEasy_Panel *)this,param_1,param_2,0,0,0,0,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  if (this->_padding_ != 0) {
    TButtonPanel::set_bevel_info
              (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
               (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
               ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
  }
  return 1;
}

// --------------------------------------------------

// Function: create_radio_button
// Address: 004b2e60
int __thiscall
TRIBE_Screen_Sed::create_radio_button(TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_radio_button((TEasy_Panel *)this,param_1,param_2,0,0,0,0,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
  (**(code **)((*param_2)->_padding_ + 0x14))(0);
  if (this->_padding_ != 0) {
    TButtonPanel::set_bevel_info
              (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
               (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
               ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
  }
  return 1;
}

// --------------------------------------------------

