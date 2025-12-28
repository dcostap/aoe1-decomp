// Class: TribeSendQuickMessageDialog
// Size:  0x49C
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
// [74] setup
// [75] setup
// [76] `scalar_deleting_destructor'
// [77] recycle_in_to_game
// [78] recycle_out_of_game
// [79] draw
// [80] shadow_draw
// [81] normal_draw
// [82] draw_front_frame
// [83] draw_back_frame
// [84] draw_frame
// [85] update
// [86] check_damage_sprites
// [87] rehook
// [88] save
// [89] teleport
// [90] new_sprite
// [91] add_overlay_sprite
// [92] remove_overlay_sprite
// [93] change_ownership
// [94] modify
// [95] modify_delta
// [96] modify_percent
// [97] transform
// [98] copy_obj
// [99] set_object_state
// [100] remove_visible_resource
// [101] create_doppleganger_when_dying
// [102] destroy_obj
// [103] die_die_die
// [104] damage
// [105] calculateDamage
// [106] rotate
// [107] can_attack
// [108] set_attribute
// [109] set_attribute_amount
// [110] heal
// [111] heal
// [112] canRepair
// [113] notify_of_relation
// [114] do_command
// [115] move_to
// [116] work
// [117] stop
// [118] set_attack
// [119] play_command_sound
// [120] play_move_sound
// [121] new_angle
// [122] spawn_death_obj
// [123] get_command_master
// [124] set_being_worked_on
// [125] release_being_worked_on
// [126] is_moving
// [127] get_target_obj
// [128] enter_obj
// [129] exit_obj
// [130] explore_terrain
// [131] unexplore_terrain
// [132] get_los_table
// [133] inAttackRange
// [134] underAttack
// [135] setUnderAttack
// [136] calc_attack_modifier
// [137] getSpeed
// [138] getAngle
// [139] maximumSpeed
// [140] rateOfFire
// [141] damageCapability
// [142] damageCapability
// [143] weaponRange
// [144] minimumWeaponRange
// [145] passableTile
// [146] facetToNextWaypoint
// [147] currentTargetID
// [148] currentTargetX
// [149] currentTargetY
// [150] currentTargetZ
// [151] setWaitingToMove
// [152] waitingToMove
// [153] actionState
// [154] keepGatheringWhenObjectIsOut
// [155] produceWhenKilledBy
// [156] useSameZoneDropsite
// [157] logDebug
// [158] notify
// [159] attack
// [160] attack
// [161] moveTo
// [162] moveTo
// [163] moveTo
// [164] moveAwayFrom
// [165] hunt
// [166] gather
// [167] convert
// [168] repair
// [169] build
// [170] trade
// [171] explore
// [172] enter
// [173] unload
// [174] transport
// [175] stopAction
// [176] pause
// [177] canPath
// [178] canPath
// [179] canBidirectionPath
// [180] canPathWithObstructions
// [181] canPathWithAdditionalPassability
// [182] findFirstTerrainAlongExceptionPath
// [183] canLinePath
// [184] canLinePath
// [185] firstTileAlongLine
// [186] userDefinedWaypoint
// [187] addUserDefinedWaypoint
// [188] removeAllUserDefinedWaypoints
// [189] removeUserDefinedWaypoint
// [190] numberUserDefinedWaypoints
// [191] findAvoidancePath
// [192] get_action_checksum
// [193] get_waypoint_checksum
// [194] setup
// [195] setup
// [196] create_object_list
// [197] create_sprite_list
// [198] setup
// [199] recycle_in_to_game
// [200] validate
// [201] setup
//
// Member Layout:
// [0x490] TEditPanel * chatInput
// [0x494] TTextPanel * chatTitle
// [0x498] Mode modeValue
// ----------------------------------------------------------------

// Function: TribeSendQuickMessageDialog
// Address: 00441530
// [HELPER] s_: ""
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
TribeSendQuickMessageDialog * __thiscall
TribeSendQuickMessageDialog::TribeSendQuickMessageDialog
          (TribeSendQuickMessageDialog *this,TScreenPanel *param_1,Mode param_2)
{
  long lVar1;
  char *pcVar2;
  TDrawArea *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d258;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Send_Quick_Message_Dialog);
  iVar6 = 1;
  local_4 = 0;
  this->modeValue = param_2;
  this->_padding_ = (int)&_vftable_;
  lVar1 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar2 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar5 = 0x23;
  lVar4 = 0x21c;
  pTVar3 = TPanel::renderArea((TPanel *)param_1);
  iVar6 = TDialogPanel::setup((TDialogPanel *)this,pTVar3,(TPanel *)param_1,lVar4,lVar5,pcVar2,lVar1
                              ,iVar6);
  if (iVar6 != 0) {
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->chatTitle,
                       (-(uint)(this->modeValue != AsChat) & 5) + 0x2668,5,5,0x78,0x19,4,1,1,0);
    if (iVar6 != 0) {
      iVar6 = TEasy_Panel::create_edit
                        ((TEasy_Panel *)this,(TPanel *)this,&this->chatInput,s_,0x41,FormatText,0x82
                         ,5,0x195,0x19,0xb,1,0);
      if (iVar6 != 0) {
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->chatInput);
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00441630
void * __thiscall
TribeSendQuickMessageDialog::_vector_deleting_destructor_
          (TribeSendQuickMessageDialog *this,uint param_1)
{
  ~TribeSendQuickMessageDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSendQuickMessageDialog
// Address: 00441650
void __thiscall
TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(TribeSendQuickMessageDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->chatInput != (TEditPanel *)0x0) {
    (**(code **)this->chatInput->_padding_)(1);
  }
  if (this->chatTitle != (TTextPanel *)0x0) {
    (**(code **)this->chatTitle->_padding_)(1);
  }
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004416c0
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
long __thiscall
TribeSendQuickMessageDialog::action
          (TribeSendQuickMessageDialog *this,TPanel *param_1,long param_2,ulong param_3,
          ulong param_4)
{
  char cVar1;
  TRIBE_Screen_Game *this_00;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char save_msg [66];
  
  if ((param_1 != (TPanel *)0x0) && ((TEditPanel *)param_1 == this->chatInput)) {
    if (param_2 == 0) {
      pcVar2 = TEditPanel::currentLine(this->chatInput);
      if ((pcVar2 != (char *)0x0) &&
         (pcVar2 = TEditPanel::currentLine(this->chatInput), *pcVar2 != '\0')) {
        this_00 = (TRIBE_Screen_Game *)this->_padding_;
        pcVar3 = TEditPanel::currentLine(this->chatInput);
        uVar6 = 0xffffffff;
        pcVar2 = save_msg;
        do {
          pcVar8 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar8 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar8;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar3 = pcVar8 + -uVar6;
        for (uVar7 = uVar6 >> 2; pcVar2 = pcVar2 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar2 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
        iVar4 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,save_msg + 4);
        if (iVar4 != 0) {
          return 1;
        }
        iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar4 == 0) {
          RGE_Base_Game::play_sound(rge_base_game,2);
          TRIBE_Screen_Game::display_system_message(this_00,&stack0xffffffb4);
          return 1;
        }
        if (rge_base_game->prog_mode == 5) {
          return 1;
        }
        TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
        return 1;
      }
    }
    else if (param_2 != 1) goto LAB_00441819;
    TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
    return 1;
  }
LAB_00441819:
  lVar5 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar5;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00441840
long __thiscall
TribeSendQuickMessageDialog::handle_mouse_down
          (TribeSendQuickMessageDialog *this,uchar param_1,long param_2,long param_3,int param_4,
          int param_5)
{
  int iVar1;
  int iVar2;
  long lVar3;
  uchar unaff_BL;
  
  iVar1 = this->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xbc))(param_2,param_3);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xb4))(this->chatInput,1,0,0);
    return 1;
  }
  lVar3 = TEasy_Panel::handle_mouse_down
                    ((TEasy_Panel *)this,unaff_BL,param_2,param_3,param_2,param_3);
  return lVar3;
}

// --------------------------------------------------

