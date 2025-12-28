// Class: RGE_Base_Game
// Size:  0xA24
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] run
// [02] wnd_proc
// [03] set_prog_mode
// [04] set_game_mode
// [05] set_player
// [06] get_error_code
// [07] get_string
// [08] get_string
// [09] get_string
// [10] get_string2
// [11] get_view_panel
// [12] get_map_panel
// [13] new_scenario_header
// [14] new_scenario_header
// [15] new_scenario_info
// [16] notification
// [17] reset_comm
// [18] send_game_options
// [19] receive_game_options
// [20] gameSummary
// [21] processCheatCode
// [22] setup_music_system
// [23] shutdown_music_system
// [24] setup
// [25] setup_cmd_options
// [26] setup_class
// [27] setup_main_window
// [28] setup_graphics_system
// [29] setup_palette
// [30] setup_mouse
// [31] setup_registry
// [32] setup_debugging_log
// [33] setup_chat
// [34] setup_comm
// [35] setup_sound_system
// [36] setup_fonts
// [37] setup_sounds
// [38] setup_shapes
// [39] setup_blank_screen
// [40] setup_timings
// [41] stop_sound_system
// [42] restart_sound_system
// [43] stop_music_system
// [44] restart_music_system
// [45] create_world
// [46] handle_message
// [47] handle_idle
// [48] handle_mouse_move
// [49] handle_key_down
// [50] handle_user_command
// [51] handle_command
// [52] handle_music_done
// [53] handle_paint
// [54] handle_activate
// [55] handle_init_menu
// [56] handle_exit_menu
// [57] handle_size
// [58] handle_palette_changed
// [59] handle_query_new_palette
// [60] handle_close
// [61] handle_destroy
// [62] action_update
// [63] action_mouse_move
// [64] action_key_down
// [65] action_user_command
// [66] action_command
// [67] action_music_done
// [68] action_activate
// [69] action_deactivate
// [70] action_init_menu
// [71] action_exit_menu
// [72] action_size
// [73] action_close
// [74] calc_timings
// [75] calc_timing_text
// [76] show_timings
// [77] show_comm
// [78] show_ai
// [79] setup_map_save_area
// [80] set_interface_messages
//
// Member Layout:
// [0x004] RGE_Game_Info * player_game_info
// [0x008] RGE_Scenario_File_Info * scenario_info
// [0x00C] RGE_Prog_Info * prog_info
// [0x010] void * prog_window
// [0x014] int prog_ready
// [0x018] int prog_active
// [0x01C] void * prog_palette
// [0x020] void * prog_mutex
// [0x024] long window_style
// [0x028] int random_game_seed
// [0x02C] int random_map_seed
// [0x030] int save_random_game_seed
// [0x034] int save_random_map_seed
// [0x038] int screen_saver_enabled
// [0x03C] int low_power_enabled
// [0x040] int error_code
// [0x044] int is_timer
// [0x048] TDrawSystem * draw_system
// [0x04C] TDrawArea * draw_area
// [0x050] uchar outline_type
// [0x054] int custom_mouse
// [0x058] short shape_num
// [0x05C] TShape * * shapes
// [0x060] TSound_Driver * sound_system
// [0x064] TMusic_System * music_system
// [0x068] short sound_num
// [0x06C] TDigital * * sounds
// [0x070] uchar save_music_type
// [0x074] int save_music_track_from
// [0x078] int save_music_track_to
// [0x07C] int save_music_cur_track
// [0x080] char[260] save_music_file (sz: 0x104)
// [0x184] int save_music_loop
// [0x188] ulong save_music_pos
// [0x18C] TCommunications_Handler * comm_handler
// [0x190] int comm_syncstop
// [0x194] int comm_droppackets
// [0x198] int comm_syncmsg
// [0x19C] int comm_stepmode
// [0x1A0] int comm_speed
// [0x1A4] TDebuggingLog * debugLog
// [0x1A8] int log_comm
// [0x1AC] TRegistry * registry
// [0x1B0] int prog_mode
// [0x1B4] int game_mode
// [0x1B8] int sub_game_mode
// [0x1BC] int paused
// [0x1C0] TMousePointer * mouse_pointer
// [0x1C4] int erase_mouse
// [0x1C8] int mouse_blit_sync
// [0x1CC] int is_mouse_on
// [0x1D0] int windows_mouse
// [0x1D4] void * mouse_cursor
// [0x1D8] int input_enabled
// [0x1DC] void * input_disabled_window
// [0x1E0] short font_num
// [0x1E4] RGE_Font * fonts
// [0x1E8] char[261] work_dir (sz: 0x105)
// [0x2ED] char[261] string_dll_name (sz: 0x105)
// [0x3F4] RGE_Game_World * world
// [0x3F8] int render_all
// [0x3FC] short master_obj_id
// [0x3FE] short terrain_id
// [0x400] short elevation_height
// [0x402] short brush_size
// [0x404] char[256] timing_text (sz: 0x100)
// [0x504] ulong frame_count
// [0x508] ulong world_update_count
// [0x50C] ulong view_update_count
// [0x510] ulong last_frame_count
// [0x514] ulong last_world_update_count
// [0x518] ulong last_view_update_count
// [0x51C] ulong fps
// [0x520] ulong world_update_fps
// [0x524] ulong view_update_fps
// [0x528] RGE_Timing_Info[30] timings (sz: 0x3C0)
// [0x8E8] int do_show_timings
// [0x8EC] int do_show_comm
// [0x8F0] int do_show_ai
// [0x8F4] ulong last_view_time
// [0x8F8] RGE_Game_Options rge_game_options (sz: 0xA8)
// [0x9A0] int campaignGameValue
// [0x9A4] int savedGameValue
// [0x9A8] int quick_build
// [0x9AC] int save_check_for_cd
// [0x9B0] int[9] playerIDValue (sz: 0x24)
// [0x9D4] int display_selected_ids
// [0x9D8] long[9] countdown_timer (sz: 0x24)
// [0x9FC] int auto_paused
// [0xA00] int save_paused
// [0xA04] int non_user_pause
// [0xA08] int rollover
// [0xA0C] float game_speed
// [0xA10] int single_player_difficulty
// [0xA14] uchar pathFindingValue
// [0xA15] uchar[9] resigned (sz: 0x9)
// [0xA20] TDrawArea * map_save_area
// ----------------------------------------------------------------

// Function: RGE_Base_Game
// Address: 0041b6a0
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_: ""
// [HELPER] s_language_dll: "language.dll"
/* public: __thiscall RGE_Base_Game::RGE_Base_Game(struct RGE_Prog_Info *,int) */

RGE_Base_Game * __thiscall
RGE_Base_Game::RGE_Base_Game(RGE_Base_Game *this,RGE_Prog_Info *param_1,int param_2)
{
  char cVar1;
  void *pvVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int unaff_retaddr;
  
  this->player_game_info = (RGE_Game_Info *)0x0;
  this->random_game_seed = -1;
  this->random_map_seed = -1;
  this->save_random_game_seed = -1;
  this->save_random_map_seed = -1;
  this->quick_build = 0;
  this->_padding_ = (int)&_vftable_;
  do_draw_log = 0;
  safe_draw_log = 0;
  draw_log_name._0_1_ = 0;
  draw_log = (_iobuf *)0x0;
  setVersion(this,1.0);
  setScenarioGame(this,0);
  setCampaignGame(this,0);
  setSavedGame(this,0);
  setSinglePlayerGame(this,1);
  setMultiplayerGame(this,0);
  setMapSize(this,0x60,0x60,8);
  setAllowCheatCodes(this,0);
  setCheatNotification(this,1);
  setFullVisibility(this,0);
  setFogOfWar(this,1);
  setColoredChat(this,1);
  setGameDeveloperMode(this,0);
  setDifficulty(this,0);
  iVar8 = 0;
  do {
    setPlayerCDAndVersion(this,iVar8,'\0');
    setPlayerHasCD(this,iVar8,0);
    setPlayerVersion(this,iVar8,'\0');
    setPlayerTeam(this,iVar8,1);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 9);
  setPathFinding(this,'\0');
  setMpPathFinding(this,'\0');
  setNumberPlayers(this,4);
  setScenarioName(this,s_);
  rge_base_game = this;
  this->prog_info = param_1;
  this->prog_window = (void *)0x0;
  this->prog_ready = 0;
  this->prog_active = 1;
  this->prog_palette = (void *)0x0;
  this->window_style = 0;
  StringTable = (void *)0x0;
  this->screen_saver_enabled = 0;
  this->error_code = 0;
  this->is_timer = 0;
  this->draw_system = (TDrawSystem *)0x0;
  this->draw_area = (TDrawArea *)0x0;
  this->outline_type = '\x02';
  this->custom_mouse = 0;
  this->shapes = (TShape **)0x0;
  this->sound_system = (TSound_Driver *)0x0;
  this->music_system = (TMusic_System *)0x0;
  this->sound_num = 0;
  this->sounds = (TDigital **)0x0;
  this->save_music_type = '\0';
  this->save_music_track_from = 0;
  this->save_music_track_to = 0;
  this->save_music_cur_track = 0;
  this->save_music_file[0] = '\0';
  this->save_music_loop = 0;
  this->save_music_pos = 0;
  this->comm_handler = (TCommunications_Handler *)0x0;
  this->debugLog = (TDebuggingLog *)0x0;
  this->log_comm = 0;
  this->comm_syncstop = 0;
  this->comm_syncmsg = 0;
  this->comm_stepmode = 0;
  this->comm_speed = 1;
  this->comm_droppackets = 0;
  this->registry = (TRegistry *)0x0;
  this->prog_mode = 0;
  this->game_mode = 0;
  this->sub_game_mode = 0;
  this->paused = 0;
  this->mouse_pointer = (TMousePointer *)0x0;
  this->erase_mouse = 0;
  this->mouse_blit_sync = 0;
  this->is_mouse_on = 1;
  this->windows_mouse = 1;
  pvVar2 = (void *)LoadCursorA(0,0x7f00);
  this->mouse_cursor = pvVar2;
  this->font_num = 0;
  this->fonts = (RGE_Font *)0x0;
  GetCurrentDirectoryA(0x105,this->work_dir);
  uVar4 = 0xffffffff;
  pcVar7 = &s_language_dll;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = this->string_dll_name;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  this->master_obj_id = -1;
  this->terrain_id = -1;
  this->elevation_height = -1;
  this->world = (RGE_Game_World *)0x0;
  this->render_all = 1;
  this->brush_size = 1;
  this->timing_text[0] = '\0';
  this->frame_count = 0;
  this->world_update_count = 0;
  this->view_update_count = 0;
  this->last_frame_count = 0;
  this->last_world_update_count = 0;
  this->last_view_update_count = 0;
  this->fps = 0;
  this->world_update_fps = 0;
  this->view_update_fps = 0;
  this->last_view_time = 0;
  puVar3 = &this->timings[0].last_time;
  iVar8 = 0x1e;
  do {
    ((RGE_Timing_Info *)(puVar3 + -1))->accum_time = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3 = puVar3 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  this->do_show_timings = 0;
  this->do_show_comm = 0;
  this->do_show_ai = 0;
  this->save_check_for_cd = 1;
  L = (TDebuggingLog *)0x0;
  iVar8 = 0;
  AppInst = this->prog_info->instance;
  AppWnd = (void *)0x0;
  chat = (TChat *)0x0;
  comm = (TCommunications_Handler *)0x0;
  Regs = (TRegistry *)0x0;
  sound_driver = (TSound_Driver *)0x0;
  driveInfo = (DriveInformation *)0x0;
  this->scenario_info = (RGE_Scenario_File_Info *)0x0;
  piVar6 = this->playerIDValue;
  do {
    *piVar6 = 0;
    this->resigned[iVar8] = '\0';
    iVar8 = iVar8 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar8 < 9);
  this->auto_paused = 0;
  this->rollover = 1;
  this->map_save_area = (TDrawArea *)0x0;
  this->game_speed = 1.0;
  this->single_player_difficulty = 2;
  iVar8 = setup_registry(this);
  if (iVar8 == 0) {
    this->error_code = 0xe;
    return this;
  }
  Regs = this->registry;
  iVar8 = setup_debugging_log(this);
  if (iVar8 == 0) {
    this->error_code = 0xf;
    return this;
  }
  L = this->debugLog;
  if (unaff_retaddr != 0) {
    iVar8 = setup(this);
    if ((iVar8 == 0) && (this->error_code == 0)) {
      this->error_code = 1;
    }
  }
  this->display_selected_ids = 0;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0041ba80
/* public: virtual void * __thiscall RGE_Base_Game::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Base_Game::_vector_deleting_destructor_(RGE_Base_Game *this,uint param_1)
{
  ~RGE_Base_Game(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0041baa0
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
// [HELPER] s_Difficulty: "Difficulty"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Game_Speed: "Game Speed"
// [HELPER] s_MP_Path_Finding: "MP Path Finding"
// [HELPER] s_Mouse_Style: "Mouse Style"
// [HELPER] s_NODXCHECK: "NODXCHECK"
// [HELPER] s_Path_Finding: "Path Finding"
// [HELPER] s_Rollover_Text: "Rollover Text"
// [HELPER] s_Screen_Size: "Screen Size"
// [HELPER] s_Scroll_Speed: "Scroll Speed"
// [HELPER] s__sscenario_inf: "%sscenario.inf"
// [HELPER] s_c__aoeact_txt: "c:\aoeact.txt"
// [HELPER] s_c__fps_txt: "c:\fps.txt"
// [HELPER] s_drawlog_d_txt: "drawlog%d.txt"
// [HELPER] s_empires_exe: "empires.exe"
// [HELPER] s_game_d_nfo: "game%d.nfo"
// [HELPER] s_w: "w"
/* WARNING: Variable defined which should be unmapped: DXPlatform */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Base_Game::setup(void) */

int __thiscall RGE_Base_Game::setup(RGE_Base_Game *this)
{
  char cVar1;
  uchar uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  RGE_Game_Info *pRVar6;
  RGE_Scenario_File_Info *pRVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  char **ppcVar12;
  undefined4 *unaff_FS_OFFSET;
  ulong DXPlatform;
  ulong DXVersion;
  _MEMORYSTATUS ms;
  char filename [260];
  char s [256];
  _OFSTRUCT of;
  _finddata_t file_info;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c9f8;
  *unaff_FS_OFFSET = &local_c;
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x20a);
  debug_srand(s_C__msdev_work_age1_x1_basegame_c,0x20a,uVar3);
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_Screen_Size);
  if (iVar4 < 0x321) {
    if (iVar4 == 800) {
      this->prog_info->main_wid = 800;
      this->prog_info->main_hgt = 600;
    }
    else if (iVar4 == 0x280) {
      this->prog_info->main_wid = 0x280;
      this->prog_info->main_hgt = 0x1e0;
    }
  }
  else if (iVar4 == 0x400) {
    this->prog_info->main_wid = 0x400;
    this->prog_info->main_hgt = 0x300;
  }
  else if (iVar4 == 0x500) {
    this->prog_info->main_wid = 0x500;
    this->prog_info->main_hgt = 0x400;
  }
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_Rollover_Text);
  if (iVar4 == 2) {
    this->rollover = 0;
  }
  else {
    this->rollover = 1;
  }
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_Mouse_Style);
  if (iVar4 == 2) {
    this->prog_info->interface_style = 2;
  }
  else if (iVar4 == 1) {
    this->prog_info->interface_style = 1;
  }
  ms.dwLength = TRegistry::RegGetInt(this->registry,1,s_Game_Speed);
  if (ms.dwLength != 0xffffffff) {
    this->game_speed = (float)(int)ms.dwLength * _DAT_0056f014;
  }
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_Difficulty);
  if (iVar4 != -1) {
    this->single_player_difficulty = iVar4;
  }
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_Path_Finding);
  if ((0 < iVar4) && (iVar4 < 4)) {
    setPathFinding(this,(char)iVar4 + 0xff);
  }
  iVar4 = TRegistry::RegGetInt(this->registry,1,s_MP_Path_Finding);
  if ((0 < iVar4) && (iVar4 < 4)) {
    setMpPathFinding(this,(char)iVar4 + 0xff);
  }
  uVar3 = TRegistry::RegGetInt(this->registry,1,s_Scroll_Speed);
  if (((uVar3 != 0xffffffff) && (9 < (int)uVar3)) && ((int)uVar3 < 0xc9)) {
    this->prog_info->mouse_scroll_interval = uVar3;
    this->prog_info->key_scroll_interval = uVar3;
  }
  iVar4 = __findfirst(s_empires_exe,&file_info.time_create);
  if (iVar4 == -1) {
    this->error_code = 0x17;
  }
  else {
    iVar4 = this->_padding_;
    iVar5 = (**(code **)(iVar4 + 100))();
    if (iVar5 == 0) {
      this->error_code = 2;
    }
    else {
      StringTable = (void *)LoadLibraryA(this->string_dll_name);
      if (StringTable == (void *)0x0) {
        this->error_code = 1;
      }
      else {
        GlobalMemoryStatus(&ms.dwMemoryLoad);
        if ((((ms.dwTotalPageFile < 0x1400000) || (ms.dwTotalVirtual < 0xa00000)) &&
            ((ms.dwTotalPageFile < 0xa00000 || (ms.dwTotalVirtual < 0x1400000)))) &&
           (ms.dwTotalVirtual < 0x1e00000)) {
          this->error_code = 0x16;
        }
        else {
          (**(code **)(iVar4 + 0x140))();
          if (debugActions == 1) {
            actionFile = (_iobuf *)fopen(s_c__aoeact_txt,s_w);
          }
          if ((this->prog_info->check_expiration == 0) ||
             (iVar5 = check_expiration(this), iVar5 != 0)) {
            if ((this->prog_info->check_multi_copies == 0) ||
               (iVar5 = check_multi_copies(this), iVar5 != 0)) {
              uVar2 = check_prog_argument(this,s_NODXCHECK);
              if ((uVar2 == '\0') && (GetDXVersion(&ms.dwLength,&DXVersion), ms.dwLength < 0x501)) {
                this->error_code = 0x14;
              }
              else {
                SystemParametersInfoA(0x10,0,&this->screen_saver_enabled,0);
                if (this->screen_saver_enabled != 0) {
                  SystemParametersInfoA(0x11,0,0,2);
                }
                SystemParametersInfoA(0x53,0,&this->low_power_enabled,0);
                if (this->low_power_enabled != 0) {
                  SystemParametersInfoA(0x55,0,0,2);
                }
                iVar5 = check_for_cd(this,0);
                this->save_check_for_cd = iVar5;
                iVar5 = (**(code **)(iVar4 + 0x68))();
                if (iVar5 == 0) {
                  this->error_code = 5;
                }
                else {
                  iVar5 = (**(code **)(iVar4 + 0x6c))();
                  if (iVar5 == 0) {
                    this->error_code = 6;
                  }
                  else {
                    iVar5 = (**(code **)(iVar4 + 0x70))();
                    if (iVar5 == 0) {
                      if (this->error_code == 0) {
                        this->error_code = 7;
                      }
                    }
                    else {
                      iVar5 = (**(code **)(iVar4 + 0x74))();
                      if (iVar5 == 0) {
                        this->error_code = 0x11;
                      }
                      else {
                        iVar5 = (**(code **)(iVar4 + 0x98))();
                        if (iVar5 == 0) {
                          this->error_code = 7;
                        }
                        else {
                          iVar5 = (**(code **)(iVar4 + 0x13c))();
                          if (iVar5 == 0) {
                            this->error_code = 7;
                          }
                          else {
                            iVar5 = (**(code **)(iVar4 + 0x78))();
                            if (iVar5 == 0) {
                              this->error_code = 8;
                            }
                            else {
                              iVar5 = (**(code **)(iVar4 + 0x8c))();
                              if (iVar5 == 0) {
                                this->error_code = 10;
                              }
                              else {
                                iVar5 = (**(code **)(iVar4 + 0x84))();
                                if (iVar5 == 0) {
                                  this->error_code = 0x10;
                                }
                                else {
                                  iVar5 = (**(code **)(iVar4 + 0x88))();
                                  if (iVar5 == 0) {
                                    this->error_code = 9;
                                  }
                                  else {
                                    iVar5 = (**(code **)(iVar4 + 0x90))();
                                    if (iVar5 == 0) {
                                      this->error_code = 0xb;
                                    }
                                    else {
                                      iVar5 = (**(code **)(iVar4 + 0x94))();
                                      if (iVar5 == 0) {
                                        this->error_code = 0xc;
                                      }
                                      else {
                                        DXVersion = (ulong)operator_new(0x274);
                                        uStack_4 = 0;
                                        if ((DriveInformation *)DXVersion == (DriveInformation *)0x0
                                           ) {
                                          driveInfo = (DriveInformation *)0x0;
                                        }
                                        else {
                                          driveInfo = (DriveInformation *)
                                                      DriveInformation::DriveInformation
                                                                ((DriveInformation *)DXVersion);
                                        }
                                        uStack_4 = 0xffffffff;
                                        if (driveInfo != (DriveInformation *)0x0) {
                                          iVar5 = (**(code **)(iVar4 + 0x9c))();
                                          if (iVar5 != 0) {
                                            (**(code **)(iVar4 + 0xc))(0);
                                            (**(code **)(iVar4 + 0xa0))();
                                            (**(code **)(iVar4 + 0xe4))(this->prog_window,0,0,0);
                                            this->prog_ready = 1;
                                            ShowWindow(this->prog_window,5);
                                            SetFocus(this->prog_window);
                                            mouse_on(this);
                                            iVar4 = SetTimer(this->prog_window,1,0x32,0);
                                            this->is_timer = iVar4;
                                            iVar4 = TRegistry::RegGetInt
                                                              (this->registry,0,s_Game_File_Number);
                                            if (iVar4 < 0) {
                                              iVar4 = 0;
                                              do {
                                                sprintf(filename + 4,s_game_d_nfo,iVar4);
                                                iVar5 = __findfirst(filename + 4,
                                                                    &file_info.time_create);
                                                if (iVar5 == -1) {
                                                  TRegistry::RegSetInt
                                                            (this->registry,0,s_Game_File_Number,
                                                             iVar4);
                                                  DXVersion = (ulong)operator_new(0x118);
                                                  uStack_4 = 2;
                                                  if ((RGE_Game_Info *)DXVersion ==
                                                      (RGE_Game_Info *)0x0) goto LAB_0041c0d5;
                                                  pRVar6 = (RGE_Game_Info *)
                                                           RGE_Game_Info::RGE_Game_Info
                                                                     ((RGE_Game_Info *)DXVersion,
                                                                      filename + 4);
                                                  goto LAB_0041c0d7;
                                                }
                                                iVar4 = iVar4 + 1;
                                              } while (iVar4 < 9999);
                                            }
                                            else {
                                              iVar4 = TRegistry::RegGetInt
                                                                (this->registry,0,s_Game_File_Number
                                                                );
                                              sprintf(filename + 4,s_game_d_nfo,iVar4);
                                              DXVersion = (ulong)operator_new(0x118);
                                              uStack_4 = 1;
                                              if ((RGE_Game_Info *)DXVersion == (RGE_Game_Info *)0x0
                                                 ) {
LAB_0041c0d5:
                                                pRVar6 = (RGE_Game_Info *)0x0;
                                              }
                                              else {
                                                pRVar6 = (RGE_Game_Info *)
                                                         RGE_Game_Info::RGE_Game_Info
                                                                   ((RGE_Game_Info *)DXVersion,
                                                                    filename + 4);
                                              }
LAB_0041c0d7:
                                              uStack_4 = 0xffffffff;
                                              this->player_game_info = pRVar6;
                                            }
                                            sprintf(filename + 4,s__sscenario_inf,
                                                    this->prog_info->scenario_dir);
                                            DXVersion = (ulong)operator_new(0x10c);
                                            uStack_4 = 3;
                                            if ((RGE_Scenario_File_Info *)DXVersion ==
                                                (RGE_Scenario_File_Info *)0x0) {
                                              pRVar7 = (RGE_Scenario_File_Info *)0x0;
                                            }
                                            else {
                                              pRVar7 = (RGE_Scenario_File_Info *)
                                                       RGE_Scenario_File_Info::
                                                       RGE_Scenario_File_Info
                                                                 ((RGE_Scenario_File_Info *)
                                                                  DXVersion,filename + 4);
                                            }
                                            this->scenario_info = pRVar7;
                                            uStack_4 = 0xffffffff;
                                            if (do_draw_log != 0) {
                                              if ((char)draw_log_name == '\0') {
                                                iVar4 = 0;
                                                do {
                                                  sprintf(s + 4,s_drawlog_d_txt,iVar4);
                                                  iVar5 = OpenFile(s + 4,&of.Reserved1,0x4000);
                                                  if (iVar5 == -1) {
                                                    draw_log = (_iobuf *)fopen(s + 4,s_w);
                                                    uVar8 = 0xffffffff;
                                                    pcVar10 = s + 4;
                                                    goto code_r0x0041c1b9;
                                                  }
                                                  iVar4 = iVar4 + 1;
                                                } while (iVar4 < 1000);
                                              }
                                              else {
                                                draw_log = (_iobuf *)fopen(&draw_log_name,s_w);
                                              }
                                            }
                                            goto LAB_0041c1ed;
                                          }
                                          this->error_code = 0xd;
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
            else {
              this->error_code = 4;
            }
          }
          else {
            this->error_code = 3;
          }
        }
      }
    }
  }
  iVar4 = 0;
  goto LAB_0041c223;
  while( true ) {
    uVar8 = uVar8 - 1;
    pcVar11 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar11;
    if (cVar1 == '\0') break;
code_r0x0041c1b9:
    pcVar11 = pcVar10;
    if (uVar8 == 0) break;
  }
  uVar8 = ~uVar8;
  pcVar10 = pcVar11 + -uVar8;
  ppcVar12 = &draw_log_name;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *ppcVar12 = *(char **)pcVar10;
    pcVar10 = pcVar10 + 4;
    ppcVar12 = ppcVar12 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(char *)ppcVar12 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    ppcVar12 = (char **)((int)ppcVar12 + 1);
  }
LAB_0041c1ed:
  if ((do_fps_log != 0) && (fps_log = (_iobuf *)fopen(s_c__fps_txt,s_w), fps_log == (_iobuf *)0x0))
{
    do_fps_log = 0;
  }
  iVar4 = 1;
LAB_0041c223:
  *unaff_FS_OFFSET = local_c;
  return iVar4;
}

// --------------------------------------------------

// Function: set_prog_mode
// Address: 0041c240
/* public: virtual void __thiscall RGE_Base_Game::set_prog_mode(int) */

void __thiscall RGE_Base_Game::set_prog_mode(RGE_Base_Game *this,int param_1)
{
  this->prog_mode = param_1;
  return;
}

// --------------------------------------------------

// Function: get_view_panel
// Address: 0041c250
/* public: virtual class TPanel * __thiscall RGE_Base_Game::get_view_panel(void) */

TPanel * __thiscall RGE_Base_Game::get_view_panel(RGE_Base_Game *this)
{
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: get_map_panel
// Address: 0041c260
/* public: virtual class TPanel * __thiscall RGE_Base_Game::get_map_panel(void) */

TPanel * __thiscall RGE_Base_Game::get_map_panel(RGE_Base_Game *this)
{
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: ~RGE_Base_Game
// Address: 0041c270
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_Difficulty: "Difficulty"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Game_Speed: "Game Speed"
// [HELPER] s_MP_Path_Finding: "MP Path Finding"
// [HELPER] s_MS_WINHELP: "MS_WINHELP"
// [HELPER] s_Mouse_Style: "Mouse Style"
// [HELPER] s_Path_Finding: "Path Finding"
// [HELPER] s_Rollover_Text: "Rollover Text"
// [HELPER] s_Screen_Size: "Screen Size"
// [HELPER] s_Scroll_Speed: "Scroll Speed"
// [HELPER] s_game_d_nfo: "game%d.nfo"
/* WARNING: Variable defined which should be unmapped: filename */
/* public: virtual __thiscall RGE_Base_Game::~RGE_Base_Game(void) */

void __thiscall RGE_Base_Game::~RGE_Base_Game(RGE_Base_Game *this)
{
  RGE_Scenario_File_Info *this_00;
  RGE_Game_Info *this_01;
  TDrawArea *this_02;
  TMousePointer *this_03;
  TCommunications_Handler *this_04;
  int iVar1;
  TDrawSystem *this_05;
  TRegistry *this_06;
  TDebuggingLog *this_07;
  TShape *this_08;
  TChat *pTVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  char filename [13];
  char str [256];
  
  this->_padding_ = (int)&_vftable_;
  if ((do_debug_random != 0) && (wrote_debug_random_log == 0)) {
    debug_random_write();
    dump_vismap_log();
  }
  if (this->draw_system != (TDrawSystem *)0x0) {
    TRegistry::RegSetInt(this->registry,1,s_Screen_Size,this->draw_system->ScreenWidth);
  }
  TRegistry::RegSetInt(this->registry,1,s_Rollover_Text,2 - (uint)(this->rollover != 0));
  if (this->prog_info->interface_style == 2) {
    iVar5 = 2;
  }
  else {
    iVar5 = 1;
  }
  TRegistry::RegSetInt(this->registry,1,s_Mouse_Style,iVar5);
  iVar5 = __ftol();
  TRegistry::RegSetInt(this->registry,1,s_Game_Speed,iVar5);
  TRegistry::RegSetInt(this->registry,1,s_Difficulty,this->single_player_difficulty);
  bVar3 = pathFinding(this);
  TRegistry::RegSetInt(this->registry,1,s_Path_Finding,bVar3 + 1);
  bVar3 = mpPathFinding(this);
  TRegistry::RegSetInt(this->registry,1,s_MP_Path_Finding,bVar3 + 1);
  TRegistry::RegSetInt(this->registry,1,s_Scroll_Speed,this->prog_info->mouse_scroll_interval);
  if (actionFile != (_iobuf *)0x0) {
    fclose(actionFile);
    actionFile = (_iobuf *)0x0;
  }
  if (fps_log != (_iobuf *)0x0) {
    fclose(fps_log);
    fps_log = (_iobuf *)0x0;
  }
  if (draw_log != (_iobuf *)0x0) {
    fclose(draw_log);
    draw_log = (_iobuf *)0x0;
  }
  this_00 = this->scenario_info;
  if (this_00 != (RGE_Scenario_File_Info *)0x0) {
    RGE_Scenario_File_Info::~RGE_Scenario_File_Info(this_00);
    operator_delete(this_00);
    this->scenario_info = (RGE_Scenario_File_Info *)0x0;
  }
  if (this->player_game_info != (RGE_Game_Info *)0x0) {
    iVar5 = TRegistry::RegGetInt(this->registry,0,s_Game_File_Number);
    if (-1 < iVar5) {
      iVar5 = TRegistry::RegGetInt(this->registry,0,s_Game_File_Number);
      sprintf(filename + 4,s_game_d_nfo,iVar5);
      RGE_Game_Info::save(this->player_game_info,filename + 4);
    }
    this_01 = this->player_game_info;
    if (this_01 != (RGE_Game_Info *)0x0) {
      RGE_Game_Info::~RGE_Game_Info(this_01);
      operator_delete(this_01);
    }
    this->player_game_info = (RGE_Game_Info *)0x0;
  }
  this->prog_mode = 0;
  if (this->world != (RGE_Game_World *)0x0) {
    (**(code **)(this->world->_padding_ + 0xa0))(1);
    this->world = (RGE_Game_World *)0x0;
  }
  this_02 = this->map_save_area;
  if (this_02 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this_02);
    operator_delete(this_02);
    this->map_save_area = (TDrawArea *)0x0;
  }
  this_03 = this->mouse_pointer;
  if (this_03 != (TMousePointer *)0x0) {
    TMousePointer::~TMousePointer(this_03);
    operator_delete(this_03);
    this->mouse_pointer = (TMousePointer *)0x0;
  }
  if (driveInfo != (DriveInformation *)0x0) {
    operator_delete(driveInfo);
    driveInfo = (DriveInformation *)0x0;
  }
  this_04 = this->comm_handler;
  if (this_04 != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::~TCommunications_Handler(this_04);
    operator_delete(this_04);
    this->comm_handler = (TCommunications_Handler *)0x0;
  }
  pTVar2 = chat;
  if (chat != (TChat *)0x0) {
    TChat::~TChat(chat);
    operator_delete(pTVar2);
    chat = (TChat *)0x0;
  }
  if (this->fonts != (RGE_Font *)0x0) {
    iVar5 = 0;
    if (0 < this->font_num) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)((int)&this->fonts->font + iVar4);
        if (iVar1 != 0) {
          DeleteObject(iVar1);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar5 < this->font_num);
    }
    free(this->fonts);
    this->fonts = (RGE_Font *)0x0;
  }
  stop_sound_system(this);
  TPanelSystem::destroyPanel(&panel_system,s_Blank_Screen);
  this_05 = this->draw_system;
  if (this_05 != (TDrawSystem *)0x0) {
    TDrawSystem::~TDrawSystem(this_05);
    operator_delete(this_05);
    this->draw_system = (TDrawSystem *)0x0;
    this->draw_area = (TDrawArea *)0x0;
  }
  if (this->screen_saver_enabled != 0) {
    SystemParametersInfoA(0x11,1,0,2);
  }
  if (this->low_power_enabled != 0) {
    SystemParametersInfoA(0x55,1,0,2);
  }
  if (this->prog_palette != (void *)0x0) {
    TPanelSystem::release_palette(&panel_system,this->prog_palette);
    this->prog_palette = (void *)0x0;
  }
  this_06 = this->registry;
  if (this_06 != (TRegistry *)0x0) {
    TRegistry::~TRegistry(this_06);
    operator_delete(this_06);
    this->registry = (TRegistry *)0x0;
  }
  if (this->prog_mutex != (void *)0x0) {
    CloseHandle(this->prog_mutex);
    this->prog_mutex = (void *)0x0;
  }
  rge_base_game = (RGE_Base_Game *)0x0;
  if (this->prog_window != (void *)0x0) {
    DestroyWindow(this->prog_window);
  }
                    /* language.dll match for 0x3eb: "Age of Empires Help" */
  get_string(this,0x3eb,str + 4,0x100);
  if ((str[4] != '\0') && (iVar5 = FindWindowA(s_MS_WINHELP,str + 4), iVar5 != 0)) {
    SendMessageA(iVar5,0x10,0,0);
  }
  if ((StringTable != (void *)0x0) && (StringTable != this->prog_info->instance)) {
    FreeLibrary(StringTable);
    StringTable = (void *)0x0;
  }
  this_07 = this->debugLog;
  if (this_07 != (TDebuggingLog *)0x0) {
    TDebuggingLog::~TDebuggingLog(this_07);
    operator_delete(this_07);
    this->debugLog = (TDebuggingLog *)0x0;
  }
  if (this->shapes != (TShape **)0x0) {
    iVar5 = 0;
    if (0 < this->shape_num) {
      do {
        this_08 = this->shapes[iVar5];
        if (this_08 != (TShape *)0x0) {
          TShape::~TShape(this_08);
          operator_delete(this_08);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < this->shape_num);
    }
    free(this->shapes);
  }
  return;
}

// --------------------------------------------------

// Function: notification
// Address: 0041c6e0
/* public: virtual void __thiscall RGE_Base_Game::notification(int,long,long,long,long) */

void __thiscall
RGE_Base_Game::notification
          (RGE_Base_Game *this,int param_1,long param_2,long param_3,long param_4,long param_5)
{
  return;
}

// --------------------------------------------------

// Function: processCheatCode
// Address: 0041c6f0
/* public: virtual int __thiscall RGE_Base_Game::processCheatCode(int,char *) */

int __thiscall RGE_Base_Game::processCheatCode(RGE_Base_Game *this,int param_1,char *param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_message
// Address: 0041c700
/* protected: virtual int __thiscall RGE_Base_Game::handle_message(struct tagMSG *) */

int __thiscall RGE_Base_Game::handle_message(RGE_Base_Game *this,tagMSG *param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: action_update
// Address: 0041c710
/* protected: virtual int __thiscall RGE_Base_Game::action_update(void) */

int __thiscall RGE_Base_Game::action_update(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_mouse_move
// Address: 0041c720
/* protected: virtual int __thiscall RGE_Base_Game::action_mouse_move(long,long,int,int,int,int) */

int __thiscall
RGE_Base_Game::action_mouse_move
          (RGE_Base_Game *this,long param_1,long param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  return 1;
}

// --------------------------------------------------

// Function: action_key_down
// Address: 0041c730
/* protected: virtual int __thiscall RGE_Base_Game::action_key_down(unsigned long,int,int,int,int)
    */

int __thiscall
RGE_Base_Game::action_key_down
          (RGE_Base_Game *this,ulong param_1,int param_2,int param_3,int param_4,int param_5)
{
  return 1;
}

// --------------------------------------------------

// Function: action_user_command
// Address: 0041c740
/* protected: virtual int __thiscall RGE_Base_Game::action_user_command(unsigned long,unsigned long)
    */

int __thiscall RGE_Base_Game::action_user_command(RGE_Base_Game *this,ulong param_1,ulong param_2)
{
  return 1;
}

// --------------------------------------------------

// Function: action_command
// Address: 0041c750
/* protected: virtual int __thiscall RGE_Base_Game::action_command(unsigned long,unsigned long) */

int __thiscall RGE_Base_Game::action_command(RGE_Base_Game *this,ulong param_1,ulong param_2)
{
  return 1;
}

// --------------------------------------------------

// Function: action_music_done
// Address: 0041c760
/* protected: virtual int __thiscall RGE_Base_Game::action_music_done(void) */

int __thiscall RGE_Base_Game::action_music_done(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_activate
// Address: 0041c770
/* protected: virtual int __thiscall RGE_Base_Game::action_activate(void) */

int __thiscall RGE_Base_Game::action_activate(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_deactivate
// Address: 0041c780
/* protected: virtual int __thiscall RGE_Base_Game::action_deactivate(void) */

int __thiscall RGE_Base_Game::action_deactivate(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_init_menu
// Address: 0041c790
/* protected: virtual int __thiscall RGE_Base_Game::action_init_menu(void) */

int __thiscall RGE_Base_Game::action_init_menu(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_exit_menu
// Address: 0041c7a0
/* protected: virtual int __thiscall RGE_Base_Game::action_exit_menu(void) */

int __thiscall RGE_Base_Game::action_exit_menu(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_size
// Address: 0041c7b0
/* protected: virtual int __thiscall RGE_Base_Game::action_size(void) */

int __thiscall RGE_Base_Game::action_size(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: action_close
// Address: 0041c7c0
/* protected: virtual int __thiscall RGE_Base_Game::action_close(void) */

int __thiscall RGE_Base_Game::action_close(RGE_Base_Game *this)
{
  return 1;
}

// --------------------------------------------------

// Function: reset_timings
// Address: 0041c7d0
/* public: void __thiscall RGE_Base_Game::reset_timings(void) */

void __thiscall RGE_Base_Game::reset_timings(RGE_Base_Game *this)
{
  ulong *puVar1;
  int iVar2;
  
  puVar1 = &this->timings[0].last_time;
  this->frame_count = 0;
  this->world_update_count = 0;
  this->view_update_count = 0;
  this->last_frame_count = 0;
  this->last_world_update_count = 0;
  this->last_view_update_count = 0;
  this->fps = 0;
  this->world_update_fps = 0;
  this->view_update_fps = 0;
  iVar2 = 0x1e;
  do {
    ((RGE_Timing_Info *)(puVar1 + -1))->accum_time = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: add_to_timing
// Address: 0041c830
/* public: void __thiscall RGE_Base_Game::add_to_timing(int,unsigned long) */

void __thiscall RGE_Base_Game::add_to_timing(RGE_Base_Game *this,int param_1,ulong param_2)
{
  this->timings[param_1].accum_time = this->timings[param_1].accum_time + param_2;
  this->timings[param_1].last_single_time = param_2;
  if (this->timings[param_1].max_time < param_2) {
    this->timings[param_1].max_time = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: increment_world_update_count
// Address: 0041c870
/* public: void __thiscall RGE_Base_Game::increment_world_update_count(void) */

void __thiscall RGE_Base_Game::increment_world_update_count(RGE_Base_Game *this)
{
  this->world_update_count = this->world_update_count + 1;
  return;
}

// --------------------------------------------------

// Function: increment_view_update_count
// Address: 0041c880
/* public: void __thiscall RGE_Base_Game::increment_view_update_count(void) */

void __thiscall RGE_Base_Game::increment_view_update_count(RGE_Base_Game *this)
{
  this->view_update_count = this->view_update_count + 1;
  return;
}

// --------------------------------------------------

// Function: set_last_single_time
// Address: 0041c890
/* public: void __thiscall RGE_Base_Game::set_last_single_time(int,unsigned long) */

void __thiscall RGE_Base_Game::set_last_single_time(RGE_Base_Game *this,int param_1,ulong param_2)
{
  this->timings[param_1].last_single_time = param_2;
  return;
}

// --------------------------------------------------

// Function: get_last_time
// Address: 0041c8b0
/* public: unsigned long __thiscall RGE_Base_Game::get_last_time(int) */

ulong __thiscall RGE_Base_Game::get_last_time(RGE_Base_Game *this,int param_1)
{
  return this->timings[param_1].last_time;
}

// --------------------------------------------------

// Function: get_last_single_time
// Address: 0041c8d0
/* public: unsigned long __thiscall RGE_Base_Game::get_last_single_time(int) */

ulong __thiscall RGE_Base_Game::get_last_single_time(RGE_Base_Game *this,int param_1)
{
  return this->timings[param_1].last_single_time;
}

// --------------------------------------------------

// Function: get_accum_time
// Address: 0041c8f0
/* public: unsigned long __thiscall RGE_Base_Game::get_accum_time(int) */

ulong __thiscall RGE_Base_Game::get_accum_time(RGE_Base_Game *this,int param_1)
{
  return this->timings[param_1].accum_time;
}

// --------------------------------------------------

// Function: get_max_time
// Address: 0041c910
/* public: unsigned long __thiscall RGE_Base_Game::get_max_time(int) */

ulong __thiscall RGE_Base_Game::get_max_time(RGE_Base_Game *this,int param_1)
{
  return this->timings[param_1].max_time;
}

// --------------------------------------------------

// Function: get_last_max_time
// Address: 0041c930
/* public: unsigned long __thiscall RGE_Base_Game::get_last_max_time(int) */

ulong __thiscall RGE_Base_Game::get_last_max_time(RGE_Base_Game *this,int param_1)
{
  return this->timings[param_1].last_max_time;
}

// --------------------------------------------------

// Function: get_last_world_update_count
// Address: 0041c950
/* public: unsigned long __thiscall RGE_Base_Game::get_last_world_update_count(void) */

ulong __thiscall RGE_Base_Game::get_last_world_update_count(RGE_Base_Game *this)
{
  return this->last_world_update_count;
}

// --------------------------------------------------

// Function: get_last_view_update_count
// Address: 0041c960
/* public: unsigned long __thiscall RGE_Base_Game::get_last_view_update_count(void) */

ulong __thiscall RGE_Base_Game::get_last_view_update_count(RGE_Base_Game *this)
{
  return this->last_view_update_count;
}

// --------------------------------------------------

// Function: get_world_update_count
// Address: 0041c970
/* public: unsigned long __thiscall RGE_Base_Game::get_world_update_count(void) */

ulong __thiscall RGE_Base_Game::get_world_update_count(RGE_Base_Game *this)
{
  return this->world_update_count;
}

// --------------------------------------------------

// Function: get_view_update_count
// Address: 0041c980
/* public: unsigned long __thiscall RGE_Base_Game::get_view_update_count(void) */

ulong __thiscall RGE_Base_Game::get_view_update_count(RGE_Base_Game *this)
{
  return this->view_update_count;
}

// --------------------------------------------------

// Function: get_error_code
// Address: 0041c990
/* public: virtual int __thiscall RGE_Base_Game::get_error_code(void) */

int __thiscall RGE_Base_Game::get_error_code(RGE_Base_Game *this)
{
  return this->error_code;
}

// --------------------------------------------------

// Function: get_string
// Address: 0041c9a0
/* public: virtual char * __thiscall RGE_Base_Game::get_string(long) */

char * __thiscall RGE_Base_Game::get_string(RGE_Base_Game *this,long param_1)
{
  (**(code **)(this->_padding_ + 0x20))(param_1,&DAT_005b2168,0x200);
  return (char *)&DAT_005b2168;
}

// --------------------------------------------------

// Function: get_string
// Address: 0041c9c0
/* public: virtual char * __thiscall RGE_Base_Game::get_string(long,char *,int) */

char * __thiscall
RGE_Base_Game::get_string(RGE_Base_Game *this,long param_1,char *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = LoadStringA(StringTable,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = '\0';
  }
  param_2[param_3 + -1] = '\0';
  return param_2;
}

// --------------------------------------------------

// Function: get_string
// Address: 0041c9f0
/* public: virtual char * __thiscall RGE_Base_Game::get_string(int,long,char *,int) */

char * __thiscall
RGE_Base_Game::get_string(RGE_Base_Game *this,int param_1,long param_2,char *param_3,int param_4)
{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(this->_padding_ + 0x28))(param_1,param_2,0,param_3,param_4);
  return pcVar1;
}

// --------------------------------------------------

// Function: get_string2
// Address: 0041ca10
/* public: virtual char * __thiscall RGE_Base_Game::get_string2(int,long,long,char *,int) */

char * __thiscall
RGE_Base_Game::get_string2
          (RGE_Base_Game *this,int param_1,long param_2,long param_3,char *param_4,int param_5)
{
  char *pcVar1;
  
  *param_4 = '\0';
  if (param_1 == 1) {
    switch(param_2) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 0xe:
    case 0xf:
                    /* language.dll match for 0x7d2: "Could not initialize program. Uninstall Age of
                       Empires, and then run Setup again." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7d2,param_4,param_5);
      return pcVar1;
    case 7:
    case 8:
    case 0xb:
    case 0xd:
    case 0x11:
                    /* language.dll match for 0x7d3: "Could not initialize graphics system. Make
                       sure that your video card and driver are compatible with DirectDraw." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7d3,param_4,param_5);
      return pcVar1;
    case 9:
    case 0x10:
                    /* language.dll match for 0x7d5: "Could not initialize communications system.
                       Make sure that you have DirectX 5.0a or higher and that it is installed
                       properly." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7d5,param_4,param_5);
      return pcVar1;
    case 10:
    case 0xc:
                    /* language.dll match for 0x7d4: "Could not initialize sound system." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7d4,param_4,param_5);
      return pcVar1;
    case 0x12:
                    /* language.dll match for 0x7dc: "Game stopped because it was out of sync!" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7dc,param_4,param_5);
      return pcVar1;
    case 0x13:
                    /* language.dll match for 0x7db: "Age of Empires requires a color palette of 256
                       Color or higher to run. To change you color palette, go to the Display
                       Properties dialog box in Windows Control Panel." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7db,param_4,param_5);
      return pcVar1;
    case 0x14:
                    /* language.dll match for 0x7dd: "Age of Empires could not initialize DirectX.
                       Make sure that DirectX 5.0 or higher is installed and contact your hardware
                       manufacturer for a video driver update. Please see the ReadmeX.doc file for
                       more information."
                       language.dll match for 0x7dd: "Age of Empires requires DirectX 5.0a or
                       higher." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7dd,param_4,param_5);
      return pcVar1;
    case 0x15:
                    /* language.dll match for 0x7de: "Age of Empires requires Microsoft Windows NT
                       4.0 with Service Pack 3 and the DirectPlay 5.0a update." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7de,param_4,param_5);
      return pcVar1;
    case 0x16:
                    /* language.dll match for 0x7df: "Not enough memory or swap file space. Close
                       other applications and/or free some disk space, and then restart Age of
                       Empires." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7df,param_4,param_5);
      return pcVar1;
    case 0x17:
                    /* language.dll match for 0x7e0: "Age of Empires Expansion requires Age of
                       Empires 1.0, 1.0A, or 1.0B to be installed." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x7e0,param_4,param_5);
      return pcVar1;
    }
  }
  else if (param_1 == 2) {
    pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(param_2,param_4,param_5);
    return pcVar1;
  }
  param_4[param_5 + -1] = '\0';
  return param_4;
}

// --------------------------------------------------

// Function: get_scenario_info
// Address: 0041cb80
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: header_size */
/* public: class RGE_Scenario * __thiscall RGE_Base_Game::get_scenario_info(char *,int) */

RGE_Scenario * __thiscall
RGE_Base_Game::get_scenario_info(RGE_Base_Game *this,char *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  RGE_Scenario *pRVar3;
  long header_size;
  long version;
  long obj_id;
  char temp_name [300];
  
  sprintf(temp_name + 4,s__s_s,this->prog_info->scenario_dir,param_1);
  if (param_2 == 0) {
    if (param_1 == (char *)0x0) {
      return (RGE_Scenario *)0x0;
    }
    iVar1 = rge_open(temp_name + 4,0x8000);
  }
  else {
    iVar1 = RGE_Game_Info::open_scenario(this->player_game_info);
  }
  if (iVar1 == -1) {
    return (RGE_Scenario *)0x0;
  }
  rge_read_uncompressed(iVar1,&obj_id,4);
  rge_read_uncompressed(iVar1,&version,4);
  if (0 < version) {
    pvVar2 = (void *)malloc(version);
    if (pvVar2 == (void *)0x0) {
      rge_close(iVar1);
      return (RGE_Scenario *)0x0;
    }
    rge_read_uncompressed(iVar1,pvVar2,version);
    free(pvVar2);
  }
  rge_read(iVar1,temp_name,4);
  pRVar3 = (RGE_Scenario *)(**(code **)(this->_padding_ + 0x3c))(iVar1);
  rge_close(iVar1);
  return pRVar3;
}

// --------------------------------------------------

// Function: get_scenario_header
// Address: 0041cca0
// [HELPER] s_1_03: "1.03"
// [HELPER] s_1_04: "1.04"
// [HELPER] s_1_05: "1.05"
// [HELPER] s_1_06: "1.06"
// [HELPER] s_1_07: "1.07"
// [HELPER] s_1_08: "1.08"
// [HELPER] s_1_09: "1.09"
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: version */
/* public: class RGE_Scenario_Header * __thiscall RGE_Base_Game::get_scenario_header(char *,int) */

RGE_Scenario_Header * __thiscall
RGE_Base_Game::get_scenario_header(RGE_Base_Game *this,char *param_1,int param_2)
{
  int iVar1;
  RGE_Scenario_Header *pRVar2;
  long version;
  char temp_name [300];
  
  sprintf(temp_name + 4,s__s_s,this->prog_info->scenario_dir,param_1);
  if (param_2 == 0) {
    if (param_1 == (char *)0x0) {
      return (RGE_Scenario_Header *)0x0;
    }
    iVar1 = rge_open(temp_name + 4,0x8000);
  }
  else {
    iVar1 = RGE_Game_Info::open_scenario(this->player_game_info);
  }
  if (iVar1 == -1) {
    return (RGE_Scenario_Header *)0x0;
  }
  rge_read_uncompressed(iVar1,temp_name,4);
  pRVar2 = (RGE_Scenario_Header *)0x0;
  if ((((((temp_name._0_4_ == s_1_03._0_4_) || (temp_name._0_4_ == s_1_04._0_4_)) ||
        (temp_name._0_4_ == s_1_05._0_4_)) ||
       ((temp_name._0_4_ == s_1_06._0_4_ || (temp_name._0_4_ == s_1_07._0_4_)))) ||
      ((temp_name._0_4_ == s_1_08._0_4_ ||
       ((temp_name._0_4_ == s_1_09._0_4_ || (temp_name._0_4_ == s_1_10._0_4_)))))) ||
     (temp_name._0_4_ == s_1_11._0_4_)) {
    pRVar2 = (RGE_Scenario_Header *)(**(code **)(this->_padding_ + 0x38))(iVar1);
  }
  rge_close(iVar1);
  return pRVar2;
}

// --------------------------------------------------

// Function: write_scenario_header
// Address: 0041cda0
/* WARNING: Variable defined which should be unmapped: header_size */
/* public: void __thiscall RGE_Base_Game::write_scenario_header(int) */

void __thiscall RGE_Base_Game::write_scenario_header(RGE_Base_Game *this,int param_1)
{
  RGE_Scenario_Header *this_00;
  int unaff_retaddr;
  long header_size;
  RGE_Base_Game *pRStack_4;
  
  pRStack_4 = this;
  this_00 = (RGE_Scenario_Header *)(**(code **)(this->_padding_ + 0x34))(this->world->scenario);
  if (this_00 != (RGE_Scenario_Header *)0x0) {
    (**(code **)(this_00->_padding_ + 4))(unaff_retaddr);
    RGE_Scenario_Header::~RGE_Scenario_Header(this_00);
    operator_delete(this_00);
    return;
  }
  header_size = 0;
  rge_write_uncompressed(unaff_retaddr,&header_size,4);
  return;
}

// --------------------------------------------------

// Function: new_scenario_header
// Address: 0041ce00
/* public: virtual class RGE_Scenario_Header * __thiscall RGE_Base_Game::new_scenario_header(int) */

RGE_Scenario_Header * __thiscall RGE_Base_Game::new_scenario_header(RGE_Base_Game *this,int param_1)
{
  RGE_Scenario_Header *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca1b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Scenario_Header *)operator_new(0x14);
  local_4 = 0;
  if (pRVar1 != (RGE_Scenario_Header *)0x0) {
    pRVar1 = (RGE_Scenario_Header *)RGE_Scenario_Header::RGE_Scenario_Header(pRVar1,param_1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario_Header *)0x0;
}

// --------------------------------------------------

// Function: new_scenario_header
// Address: 0041ce60
/* public: virtual class RGE_Scenario_Header * __thiscall RGE_Base_Game::new_scenario_header(class
   RGE_Scenario *) */

RGE_Scenario_Header * __thiscall
RGE_Base_Game::new_scenario_header(RGE_Base_Game *this,RGE_Scenario *param_1)
{
  RGE_Scenario_Header *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca3b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Scenario_Header *)operator_new(0x14);
  local_4 = 0;
  if (pRVar1 != (RGE_Scenario_Header *)0x0) {
    pRVar1 = (RGE_Scenario_Header *)RGE_Scenario_Header::RGE_Scenario_Header(pRVar1,param_1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario_Header *)0x0;
}

// --------------------------------------------------

// Function: new_scenario_info
// Address: 0041cec0
/* public: virtual class RGE_Scenario * __thiscall RGE_Base_Game::new_scenario_info(int) */

RGE_Scenario * __thiscall RGE_Base_Game::new_scenario_info(RGE_Base_Game *this,int param_1)
{
  RGE_Scenario *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca5b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Scenario *)operator_new(0x1990);
  local_4 = 0;
  if (pRVar1 != (RGE_Scenario *)0x0) {
    pRVar1 = (RGE_Scenario *)RGE_Scenario::RGE_Scenario(pRVar1,param_1,(RGE_Game_World *)0x0);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario *)0x0;
}

// --------------------------------------------------

// Function: get_campaign_info
// Address: 0041cf30
/* public: void __thiscall RGE_Base_Game::get_campaign_info(long &,long &,long &) */

void __thiscall
RGE_Base_Game::get_campaign_info(RGE_Base_Game *this,long *param_1,long *param_2,long *param_3)
{
  long lVar1;
  
  lVar1 = RGE_Game_Info::get_current_campaign(this->player_game_info);
  *param_1 = lVar1;
  lVar1 = RGE_Game_Info::get_current_player(this->player_game_info);
  *param_2 = lVar1;
  lVar1 = RGE_Game_Info::get_current_scenario(this->player_game_info);
  *param_3 = lVar1;
  return;
}

// --------------------------------------------------

// Function: set_campaign_info
// Address: 0041cf70
/* public: unsigned char __thiscall RGE_Base_Game::set_campaign_info(long,long,long) */

uchar __thiscall
RGE_Base_Game::set_campaign_info(RGE_Base_Game *this,long param_1,long param_2,long param_3)
{
  uchar uVar1;
  
  uVar1 = RGE_Game_Info::set_current_campaign(this->player_game_info,param_1);
  if (uVar1 != '\0') {
    uVar1 = RGE_Game_Info::set_current_person(this->player_game_info,param_2);
    if (uVar1 != '\0') {
      uVar1 = RGE_Game_Info::set_current_scenario(this->player_game_info,param_3);
      if (uVar1 != '\0') {
        return '\x01';
      }
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: set_campaign_win
// Address: 0041cfc0
/* public: void __thiscall RGE_Base_Game::set_campaign_win(void) */

void __thiscall RGE_Base_Game::set_campaign_win(RGE_Base_Game *this)
{
  RGE_Game_Info::notify_of_scenario_complete(this->player_game_info);
  return;
}

// --------------------------------------------------

// Function: run
// Address: 0041cfd0
/* WARNING: Variable defined which should be unmapped: msg */
/* public: virtual int __thiscall RGE_Base_Game::run(void) */

int __thiscall RGE_Base_Game::run(RGE_Base_Game *this)
{
  int iVar1;
  tagMSG msg;
  
  while( true ) {
    while( true ) {
      while (((this->prog_active == 0 || ((this->prog_mode != 4 && (this->prog_mode != 2)))) ||
             ((this->comm_handler != (TCommunications_Handler *)0x0 &&
              (iVar1 = TCommunications_Handler::IsPaused(this->comm_handler), iVar1 != 0))))) {
        iVar1 = GetMessageA(&msg.message,0,0,0);
        if (iVar1 == 0) {
          return msg.lParam;
        }
        TranslateMessage(&msg.message);
        DispatchMessageA(&msg.message);
      }
      iVar1 = PeekMessageA(&msg.message,0,0,0,1);
      if (iVar1 != 0) break;
      (**(code **)(this->_padding_ + 0xbc))();
    }
    if (msg.wParam == 0x12) break;
    iVar1 = (**(code **)(this->_padding_ + 0xb8))(&msg.message);
    if (iVar1 != 0) {
      TranslateMessage(&msg.message);
      DispatchMessageA(&msg.message);
    }
  }
  return msg.lParam;
}

// --------------------------------------------------

// Function: setup_cmd_options
// Address: 0041d0a0
// [HELPER] do_color_log: " "
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_1024: "1024"
// [HELPER] s_1280: "1280"
// [HELPER] s_640: "640"
// [HELPER] s_800: "800"
// [HELPER] s_AISPEED_: "AISPEED="
// [HELPER] s_ALLCP1: "ALLCP1"
// [HELPER] s_ALLCP: "ALLCP"
// [HELPER] s_ALLGRASS: "ALLGRASS"
// [HELPER] s_CDAUDIO: "CDAUDIO"
// [HELPER] s_CD_AUDIO: "CD AUDIO"
// [HELPER] s_COLORLOG: "COLORLOG"
// [HELPER] s_CUBEOUTLINE: "CUBEOUTLINE"
// [HELPER] s_CUBE_OUTLINE: "CUBE OUTLINE"
// [HELPER] s_CUSTOMMOUSE: "CUSTOMMOUSE"
// [HELPER] s_CUSTOM_MOUSE: "CUSTOM MOUSE"
// [HELPER] s_DATA_: "DATA="
// [HELPER] s_DDERRORLOG: "DDERRORLOG"
// [HELPER] s_DDFLUSHLOG: "DDFLUSHLOG"
// [HELPER] s_DDLOCKLOG: "DDLOCKLOG"
// [HELPER] s_DDLOG: "DDLOG"
// [HELPER] s_DDNOFLUSHLOG: "DDNOFLUSHLOG"
// [HELPER] s_DEVELOPER: "DEVELOPER"
// [HELPER] s_DIRECTDRAW: "DIRECTDRAW"
// [HELPER] s_DIRECT_DRAW: "DIRECT DRAW"
// [HELPER] s_DOLOGSTATUS: "DOLOGSTATUS"
// [HELPER] s_DRAWLOG: "DRAWLOG"
// [HELPER] s_DRAWLOG_: "DRAWLOG="
// [HELPER] s_DROPPACKETS: "DROPPACKETS"
// [HELPER] s_EDGEOUTLINE: "EDGEOUTLINE"
// [HELPER] s_EDGE_OUTLINE: "EDGE OUTLINE"
// [HELPER] s_FASTVIEW: "FASTVIEW"
// [HELPER] s_FAST_VIEW: "FAST VIEW"
// [HELPER] s_FILEFIRST: "FILEFIRST"
// [HELPER] s_FILE_FIRST: "FILE FIRST"
// [HELPER] s_FIXEDUPDATE: "FIXEDUPDATE"
// [HELPER] s_FIXEDUPDATE_: "FIXEDUPDATE="
// [HELPER] s_FULLSCREEN: "FULLSCREEN"
// [HELPER] s_FULL_SCREEN: "FULL SCREEN"
// [HELPER] s_GAMECD: "GAMECD"
// [HELPER] s_GROUNDOUTLINE: "GROUNDOUTLINE"
// [HELPER] s_GROUND_OUTLINE: "GROUND OUTLINE"
// [HELPER] s_IMAMUSIC: "IMAMUSIC"
// [HELPER] s_IMA_MUSIC: "IMA MUSIC"
// [HELPER] s_LOGACTION: "LOGACTION"
// [HELPER] s_LOGAI: "LOGAI"
// [HELPER] s_LOGAI_: "LOGAI="
// [HELPER] s_LOGCOMM: "LOGCOMM"
// [HELPER] s_LOGDEBUG_: "LOGDEBUG="
// [HELPER] s_LOGFPS: "LOGFPS"
// [HELPER] s_LOGOUTPUT: "LOGOUTPUT"
// [HELPER] s_LOGRANDOM: "LOGRANDOM"
// [HELPER] s_LOGUPDATECHANGES: "LOGUPDATECHANGES"
// [HELPER] s_LOG_COMM: "LOG COMM"
// [HELPER] s_LOG_FPS: "LOG FPS"
// [HELPER] s_LOG_OUTPUT: "LOG OUTPUT"
// [HELPER] s_MFILL: "MFILL"
// [HELPER] s_MIDIMUSIC: "MIDIMUSIC"
// [HELPER] s_MIDI_MUSIC: "MIDI MUSIC"
// [HELPER] s_MSYNC: "MSYNC"
// [HELPER] s_NOAICHEAT: "NOAICHEAT"
// [HELPER] s_NOCHATCHEATCODES: "NOCHATCHEATCODES"
// [HELPER] s_NOCOMMSPEED: "NOCOMMSPEED"
// [HELPER] s_NOCP: "NOCP"
// [HELPER] s_NOLOGSTATUS: "NOLOGSTATUS"
// [HELPER] s_NOMOUSE: "NOMOUSE"
// [HELPER] s_NOMUSIC: "NOMUSIC"
// [HELPER] s_NOPATHCAP: "NOPATHCAP"
// [HELPER] s_NOPATHLIMIT: "NOPATHLIMIT"
// [HELPER] s_NORMALMOUSE: "NORMALMOUSE"
// [HELPER] s_NORMAL_MOUSE: "NORMAL MOUSE"
// [HELPER] s_NOSOUND: "NOSOUND"
// [HELPER] s_NOSTARTUP: "NOSTARTUP"
// [HELPER] s_NO_MOUSE: "NO MOUSE"
// [HELPER] s_NO_MUSIC: "NO MUSIC"
// [HELPER] s_NO_SOUND: "NO SOUND"
// [HELPER] s_NO_STARTUP: "NO STARTUP"
// [HELPER] s_ONEBUTTON: "ONEBUTTON"
// [HELPER] s_ONE_BUTTON: "ONE BUTTON"
// [HELPER] s_RANDOMGAME_: "RANDOMGAME="
// [HELPER] s_RANDOMMAP_: "RANDOMMAP="
// [HELPER] s_RESEND1_: "RESEND1="
// [HELPER] s_RESEND2_: "RESEND2="
// [HELPER] s_RES_WARN: "RES_WARN"
// [HELPER] s_RUNLOG: "RUNLOG"
// [HELPER] s_SAFEDRAWLOG: "SAFEDRAWLOG"
// [HELPER] s_SCENARIOS_: "SCENARIOS="
// [HELPER] s_SLOWVIEW: "SLOWVIEW"
// [HELPER] s_SLOW_VIEW: "SLOW VIEW"
// [HELPER] s_SPEED1_: "SPEED1="
// [HELPER] s_SPEED2_: "SPEED2="
// [HELPER] s_SQUAREOUTLINE: "SQUAREOUTLINE"
// [HELPER] s_SQUARE_OUTLINE: "SQUARE OUTLINE"
// [HELPER] s_STEPMODE: "STEPMODE"
// [HELPER] s_STREAMMUSIC: "STREAMMUSIC"
// [HELPER] s_STREAM_MUSIC: "STREAM MUSIC"
// [HELPER] s_SYNCMSG: "SYNCMSG"
// [HELPER] s_SYNCSTOP: "SYNCSTOP"
// [HELPER] s_SYSTEMMEMORY: "SYSTEMMEMORY"
// [HELPER] s_SYSTEM_MEMORY: "SYSTEM MEMORY"
// [HELPER] s_TWOBUTTON: "TWOBUTTON"
// [HELPER] s_TWO_BUTTON: "TWO BUTTON"
// [HELPER] s_UIP: "UIP"
// [HELPER] s_UNP: "UNP"
// [HELPER] s_VIDEOMEMORY: "VIDEOMEMORY"
// [HELPER] s_VIDEO_MEMORY: "VIDEO MEMORY"
// [HELPER] s_WINDOW: "WINDOW"
// [HELPER] s_WING: "WING"
// [HELPER] s_WORLD_: "WORLD="
// [HELPER] s__: "}"
// [HELPER] shape_file_first: " "
// [HELPER] sound_file_first: " "
/* WARNING: Variable defined which should be unmapped: cmd_line */
/* protected: virtual int __thiscall RGE_Base_Game::setup_cmd_options(void) */

int __thiscall RGE_Base_Game::setup_cmd_options(RGE_Base_Game *this)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cmd_line [256];
  uchar temp_str [256];
  
  strncpy(cmd_line + 4,this->prog_info->cmd_line,0xff);
  temp_str[3] = '\0';
  CharUpperA(cmd_line + 4);
  iVar2 = strstr(cmd_line,s_NOSTARTUP);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_NO_STARTUP), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_NO_STARTUP), iVar2 != 0)) {
    this->prog_info->skip_startup = 1;
  }
  iVar2 = strstr(cmd_line,s_SYSTEMMEMORY);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_SYSTEM_MEMORY), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_SYSTEM_MEMORY), iVar2 != 0)) {
    this->prog_info->use_sys_mem = 1;
  }
  iVar2 = strstr(cmd_line,s_MIDIMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_MIDI_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_MIDI_MUSIC), iVar2 != 0)) {
    this->prog_info->use_music = 1;
    this->prog_info->use_cd_audio = 0;
    this->prog_info->use_ima = 0;
    this->prog_info->use_midi = 1;
    this->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(cmd_line,s_MSYNC);
  if (iVar2 != 0) {
    this->mouse_blit_sync = 1;
  }
  iVar2 = strstr(cmd_line,s_MFILL);
  DDSys_CanColorFill = (int)(iVar2 == 0);
  iVar2 = strstr(cmd_line,s_NOSOUND);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_NO_SOUND), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_NO_SOUND), iVar2 != 0)) {
    this->prog_info->use_sound = 0;
  }
  iVar2 = strstr(cmd_line,s_640);
  if (iVar2 != 0) {
    this->prog_info->main_wid = 0x280;
    this->prog_info->main_hgt = 0x1e0;
  }
  iVar2 = strstr(cmd_line,s_800);
  if (iVar2 != 0) {
    this->prog_info->main_wid = 800;
    this->prog_info->main_hgt = 600;
  }
  iVar2 = strstr(cmd_line,s_1024);
  if (iVar2 != 0) {
    this->prog_info->main_wid = 0x400;
    this->prog_info->main_hgt = 0x300;
  }
  iVar2 = strstr(cmd_line,s_ALLCP);
  if (iVar2 != 0) {
    all_cp = 1;
    do_run_log = 1;
    this->comm_speed = 0;
    do_debug_timeGetTime = 1;
    debug_timeGetTime_interval = 10;
    do_fixed_update = 1;
    fixed_update_time = 0x14;
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_RESEND1_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    resend_adj1 = atol(temp_str);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_RESEND2_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    resend_adj2 = atol(temp_str);
  }
  iVar2 = strstr(cmd_line,s_NOMOUSE);
  if ((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_NO_MOUSE), iVar2 != 0)) {
    this->custom_mouse = 0;
  }
  iVar2 = strstr(cmd_line,s_WING);
  if (iVar2 != 0) {
    this->prog_info->full_screen = 0;
    this->prog_info->use_dir_draw = 0;
  }
  iVar2 = strstr(cmd_line,s_DIRECTDRAW);
  if ((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_DIRECT_DRAW), iVar2 != 0)) {
    this->prog_info->use_dir_draw = 1;
  }
  iVar2 = strstr(cmd_line,s_FULLSCREEN);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_FULL_SCREEN), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_FULL_SCREEN), iVar2 != 0)) {
    this->prog_info->full_screen = 1;
    this->prog_info->use_dir_draw = 1;
  }
  iVar2 = strstr(cmd_line,s_VIDEOMEMORY);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_VIDEO_MEMORY), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_VIDEO_MEMORY), iVar2 != 0)) {
    this->prog_info->use_sys_mem = 0;
  }
  iVar2 = strstr(cmd_line,s_STREAMMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_STREAM_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_STREAM_MUSIC), iVar2 != 0)) {
    this->prog_info->use_music = 1;
    this->prog_info->use_cd_audio = 0;
    this->prog_info->use_ima = 0;
    this->prog_info->use_midi = 0;
    this->prog_info->use_wave_music = 1;
  }
  iVar2 = strstr(cmd_line,s_IMAMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_IMA_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_IMA_MUSIC), iVar2 != 0)) {
    this->prog_info->use_music = 1;
    this->prog_info->use_cd_audio = 0;
    this->prog_info->use_ima = 1;
    this->prog_info->use_midi = 0;
    this->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(cmd_line,s_FASTVIEW);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_FAST_VIEW), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_FAST_VIEW), iVar2 != 0)) {
    this->prog_info->fast_view = 1;
  }
  iVar2 = strstr(cmd_line,s_SLOWVIEW);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_SLOW_VIEW), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_SLOW_VIEW), iVar2 != 0)) {
    this->prog_info->fast_view = 0;
  }
  iVar2 = strstr(cmd_line,s_ONEBUTTON);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_ONE_BUTTON), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_ONE_BUTTON), iVar2 != 0)) {
    this->prog_info->interface_style = 1;
  }
  iVar2 = strstr(cmd_line,s_TWOBUTTON);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_TWO_BUTTON), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_TWO_BUTTON), iVar2 != 0)) {
    this->prog_info->interface_style = 2;
  }
  iVar2 = strstr(cmd_line,s_RUNLOG);
  if (iVar2 != 0) {
    do_run_log = 1;
  }
  iVar2 = strstr(cmd_line,s_SYNCMSG);
  if (iVar2 != 0) {
    this->comm_syncmsg = 1;
  }
  iVar2 = strstr(cmd_line,s_DROPPACKETS);
  if (iVar2 != 0) {
    this->comm_droppackets = 1;
  }
  iVar2 = strstr(cmd_line,s_NOCOMMSPEED);
  if (iVar2 != 0) {
    this->comm_speed = 0;
  }
  iVar2 = strstr(cmd_line,s_SYNCSTOP);
  if (iVar2 != 0) {
    this->comm_syncstop = 1;
  }
  iVar2 = strstr(cmd_line,s_STEPMODE);
  if (iVar2 != 0) {
    this->comm_stepmode = 1;
  }
  iVar2 = strstr(cmd_line,s_SQUAREOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_SQUARE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_SQUARE_OUTLINE), iVar2 != 0)) {
    this->outline_type = '\0';
  }
  iVar2 = strstr(cmd_line,s_CUBEOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_CUBE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_CUBE_OUTLINE), iVar2 != 0)) {
    this->outline_type = '\x01';
  }
  iVar2 = strstr(cmd_line,s_GROUNDOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_GROUND_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_GROUND_OUTLINE), iVar2 != 0)) {
    this->outline_type = '\x02';
  }
  iVar2 = strstr(cmd_line,s_EDGEOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_EDGE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_EDGE_OUTLINE), iVar2 != 0)) {
    this->outline_type = '\x03';
  }
  iVar2 = strstr(cmd_line,s_CUSTOMMOUSE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_CUSTOM_MOUSE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_CUSTOM_MOUSE), iVar2 != 0)) {
    this->custom_mouse = 1;
  }
  iVar2 = strstr(cmd_line,s_NOCP);
  if (iVar2 != 0) {
    useComputerPlayers = 0;
  }
  iVar2 = strstr(cmd_line,s_LOGAI);
  if (iVar2 != 0) {
    startLoggingAI = 1;
  }
  iVar2 = strstr(cmd_line,s_NOLOGSTATUS);
  if (iVar2 != 0) {
    logStatusOn = 0;
  }
  iVar2 = strstr(cmd_line,s_DOLOGSTATUS);
  if (iVar2 != 0) {
    logStatusOn = 1;
  }
  iVar2 = strstr(cmd_line,s_NOAICHEAT);
  if (iVar2 != 0) {
    allowAIToCheat = 0;
  }
  iVar2 = strstr(cmd_line,s_NOCHATCHEATCODES);
  if (iVar2 != 0) {
    chatCheatCodes = 0;
  }
  iVar2 = strstr(cmd_line,s_LOGUPDATECHANGES);
  if (iVar2 != 0) {
    logUpdateChanges = 1;
  }
  iVar2 = strstr(cmd_line,s_UIP);
  if (iVar2 != 0) {
    useInfluencePlacement = 1;
  }
  iVar2 = strstr(cmd_line,s_ALLGRASS);
  if (iVar2 != 0) {
    all_grassland_on = 1;
  }
  iVar2 = strstr(cmd_line,s_ALLCP);
  if (iVar2 != 0) {
    all_cp = 1;
  }
  iVar2 = strstr(cmd_line,s_ALLCP1);
  if (iVar2 != 0) {
    all_cp = 2;
  }
  iVar2 = strstr(cmd_line,s_NOPATHLIMIT);
  if (iVar2 != 0) {
    numberPathingIterations = -1;
  }
  iVar2 = strstr(cmd_line,s_UNP);
  if (iVar2 != 0) {
    useNewPathing = -1;
  }
  iVar2 = strstr(cmd_line,s_COLORLOG);
  if (iVar2 != 0) {
    do_color_log = '\x01';
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_LOGAI_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    specificAIPlayerToLog = atol(temp_str);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_LOGDEBUG_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    logDebugID = atol(temp_str);
  }
  iVar2 = strstr(cmd_line,s_NOPATHCAP);
  if (iVar2 != 0) {
    pathingCapValue = -1;
  }
  iVar2 = strstr(cmd_line,s_GAMECD);
  if (iVar2 != 0) {
    force_cd = 1;
  }
  iVar2 = strstr(cmd_line,s_1280);
  if (iVar2 != 0) {
    this->prog_info->main_wid = 0x500;
    this->prog_info->main_hgt = 0x400;
  }
  iVar2 = strstr(cmd_line,s_LOGFPS);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_LOG_FPS), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_LOG_FPS), iVar2 != 0)) {
    do_fps_log = 1;
  }
  iVar2 = strstr(cmd_line,s_DDERRORLOG);
  if (iVar2 != 0) {
    Sys_DDLOG_Enable = 1;
    Sys_DDLOG_ErrorOn = 1;
  }
  iVar2 = strstr(cmd_line,s_DDLOG);
  if (iVar2 != 0) {
    Sys_DDLOG_Enable = 1;
    Sys_DDLOG_ErrorOn = 0;
  }
  iVar2 = strstr(cmd_line,s_DDFLUSHLOG);
  if (iVar2 != 0) {
    DDlogAutoFlush = 1;
  }
  iVar2 = strstr(cmd_line,s_DDNOFLUSHLOG);
  if (iVar2 != 0) {
    DDlogAutoFlush = 0;
  }
  iVar2 = strstr(cmd_line,s_DDLOCKLOG);
  if (iVar2 != 0) {
    debug_log_lock = 1;
  }
  iVar2 = strstr(cmd_line,s_LOGRANDOM);
  if (iVar2 != 0) {
    do_debug_random = 1;
  }
  iVar2 = strstr(cmd_line,s_FIXEDUPDATE);
  if (iVar2 != 0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
  }
  iVar2 = strstr(cmd_line,s_LOGACTION);
  if (iVar2 != 0) {
    debugActions = 1;
  }
  iVar2 = strstr(cmd_line,s_RES_WARN);
  if (iVar2 != 0) {
    RESFILE_Set_Missing_Flag(1);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_SCENARIOS_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    this->prog_info->scenario_dir[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(this->prog_info->scenario_dir,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    __mbsncat(this->prog_info->scenario_dir,s__,1);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_WORLD_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    this->prog_info->world_db_file[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(this->prog_info->world_db_file,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_FIXEDUPDATE_);
  if (pcVar3 != (char *)0x0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    fixed_update_time = atol(temp_str);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_AISPEED_);
  if (pcVar3 != (char *)0x0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    debug_timeGetTime_interval = atol(temp_str);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_RANDOMGAME_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    iVar2 = atol(temp_str);
    this->random_game_seed = iVar2;
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_RANDOMMAP_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    iVar2 = atol(temp_str);
    this->random_map_seed = iVar2;
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_DRAWLOG_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    draw_log_name._0_1_ = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(&draw_log_name,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  iVar2 = strstr(cmd_line,s_DRAWLOG);
  if (iVar2 != 0) {
    do_draw_log = 1;
  }
  iVar2 = strstr(cmd_line,s_SAFEDRAWLOG);
  if (iVar2 != 0) {
    safe_draw_log = 1;
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_DATA_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    this->prog_info->game_data_file[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(this->prog_info->game_data_file,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  iVar2 = strstr(cmd_line,s_CDAUDIO);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_CD_AUDIO), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_CD_AUDIO), iVar2 != 0)) {
    this->prog_info->use_music = 1;
    this->prog_info->use_cd_audio = 1;
    this->prog_info->use_ima = 0;
    this->prog_info->use_midi = 0;
    this->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(cmd_line,s_WINDOW);
  if (iVar2 != 0) {
    this->prog_info->full_screen = 0;
  }
  iVar2 = strstr(cmd_line,s_FILEFIRST);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_FILE_FIRST), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_FILE_FIRST), iVar2 != 0)) {
    shape_file_first = '\x01';
    sound_file_first = '\x01';
  }
  iVar2 = strstr(cmd_line,s_LOGCOMM);
  if ((((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_LOG_COMM), iVar2 != 0)) ||
      (iVar2 = strstr(cmd_line,s_LOG_COMM), iVar2 != 0)) &&
     (this->log_comm = 1, L != (TDebuggingLog *)0x0)) {
    TDebuggingLog::LogFile(L,1);
    TDebuggingLog::LogTimestamp(L,1);
  }
  iVar2 = strstr(cmd_line,s_LOGOUTPUT);
  if ((((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_LOG_OUTPUT), iVar2 != 0)) ||
      (iVar2 = strstr(cmd_line,s_LOG_OUTPUT), iVar2 != 0)) &&
     (log_output = 1, L != (TDebuggingLog *)0x0)) {
    TDebuggingLog::LogOutput(L,1);
  }
  iVar2 = strstr(cmd_line,s_DEVELOPER);
  if (iVar2 != 0) {
    setGameDeveloperMode(this,1);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_SPEED1_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    speed_val1 = atol(temp_str);
  }
  pcVar3 = (char *)__mbsstr(cmd_line,s_SPEED2_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    temp_str[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(temp_str,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    speed_val2 = atol(temp_str);
  }
  if ((((this->prog_info->use_sound == 0) || (iVar2 = strstr(cmd_line,s_NOMUSIC), iVar2 != 0)) ||
      (iVar2 = strstr(cmd_line,s_NO_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_NO_MUSIC), iVar2 != 0)) {
    this->prog_info->use_music = 0;
  }
  if ((this->prog_info->use_dir_draw == 1) && (this->prog_info->full_screen == 1)) {
    this->custom_mouse = 1;
  }
  iVar2 = strstr(cmd_line,s_NORMALMOUSE);
  if (((iVar2 != 0) || (iVar2 = strstr(cmd_line,s_NORMAL_MOUSE), iVar2 != 0)) ||
     (iVar2 = strstr(cmd_line,s_NORMAL_MOUSE), iVar2 != 0)) {
    this->custom_mouse = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: setup_class
// Address: 0041e700
// [HELPER] s_: ""
/* WARNING: Variable defined which should be unmapped: cls */
/* protected: virtual int __thiscall RGE_Base_Game::setup_class(void) */

int __thiscall RGE_Base_Game::setup_class(RGE_Base_Game *this)
{
  RGE_Prog_Info *pRVar1;
  short sVar2;
  tagWNDCLASSA cls;
  
  pRVar1 = this->prog_info;
  if (pRVar1->prev_instance != (void *)0x0) {
    return 1;
  }
  cls.hbrBackground = (void *)0x0;
  cls.lpszClassName = s_;
  if (pRVar1->menu_name[0] != '\0') {
    cls.lpszClassName = pRVar1->menu_name;
  }
  cls.hCursor = (void *)LoadIconA(pRVar1->instance,pRVar1->icon_name);
  cls.lpszMenuName = (char *)0x0;
  cls.hIcon = this->prog_info->instance;
  cls.lpfnWndProc = (void *)0xb;
  cls.cbClsExtra = (int)rge_base_game_wnd_proc;
  cls.hInstance = (void *)0x0;
  cls.cbWndExtra = 0;
  sVar2 = RegisterClassA(&cls.lpfnWndProc);
  return (uint)(sVar2 != 0);
}

// --------------------------------------------------

// Function: setup_main_window
// Address: 0041e7d0
/* WARNING: Variable defined which should be unmapped: win_rect */
/* protected: virtual int __thiscall RGE_Base_Game::setup_main_window(void) */

int __thiscall RGE_Base_Game::setup_main_window(RGE_Base_Game *this)
{
  RGE_Prog_Info *pRVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  tagRECT win_rect;
  tagRECT client_rect;
  int iStack_4;
  
  iVar2 = GetSystemMetrics(0);
  iVar3 = GetSystemMetrics(1);
  pRVar1 = this->prog_info;
  if ((pRVar1->full_screen == 0) && ((iVar2 != pRVar1->main_wid || (iVar3 != pRVar1->main_hgt)))) {
    pvVar4 = pRVar1->instance;
    iVar3 = pRVar1->main_hgt;
    uVar5 = 0x2ca0000;
    iVar2 = pRVar1->main_wid;
  }
  else {
    pvVar4 = pRVar1->instance;
    uVar5 = 0x82080000;
  }
  pvVar4 = (void *)CreateWindowExA(0,pRVar1,pRVar1->prog_title,uVar5,0,0,iVar2,iVar3,0,0,pvVar4,0);
  this->prog_window = pvVar4;
  if (pvVar4 == (void *)0x0) {
    return 0;
  }
  GetWindowRect(pvVar4,&win_rect.top);
  GetClientRect(this->prog_window,&client_rect.top);
  pRVar1 = this->prog_info;
  if ((client_rect.bottom != pRVar1->main_wid) || (iStack_4 != pRVar1->main_hgt)) {
    SetWindowPos(this->prog_window,0,win_rect.top,win_rect.right,
                 ((win_rect.bottom - win_rect.top) - client_rect.bottom) + pRVar1->main_wid,
                 ((pRVar1->main_hgt - win_rect.right) - iStack_4) + client_rect.left,0);
  }
  if (this->prog_info->full_screen != 0) {
    ShowWindow(this->prog_window,this->prog_info->show_wnd_flag);
    UpdateWindow(this->prog_window);
    SetFocus(this->prog_window);
  }
  AppWnd = this->prog_window;
  TPanelSystem::DisableIME(&panel_system);
  return 1;
}

// --------------------------------------------------

// Function: setup_graphics_system
// Address: 0041e920
/* WARNING: Variable defined which should be unmapped: draw_mode */
/* protected: virtual int __thiscall RGE_Base_Game::setup_graphics_system(void) */

int __thiscall RGE_Base_Game::setup_graphics_system(RGE_Base_Game *this)
{
  RGE_Prog_Info *pRVar1;
  int iVar2;
  int iVar3;
  TDrawArea *this_00;
  undefined4 uVar4;
  int iVar5;
  TDrawSystem *pTVar6;
  int iVar7;
  void *pvVar8;
  undefined4 *unaff_FS_OFFSET;
  uchar draw_mode;
  uchar draw_type;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca7b;
  *unaff_FS_OFFSET = &uStack_c;
  if (this->prog_info->use_dir_draw != 0) {
    uVar4 = GetDC(0);
    iVar5 = GetDeviceCaps(uVar4,0xc);
    ReleaseDC(0,uVar4);
    if (iVar5 < 8) {
      this->error_code = 0x13;
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
  }
  pRVar1 = this->prog_info;
  iVar5 = pRVar1->use_dir_draw;
  iVar2 = pRVar1->use_sys_mem;
  iVar3 = pRVar1->full_screen;
  pTVar6 = (TDrawSystem *)operator_new(0x47c);
  uStack_4 = 0;
  if (pTVar6 == (TDrawSystem *)0x0) {
    pTVar6 = (TDrawSystem *)0x0;
  }
  else {
    pTVar6 = (TDrawSystem *)TDrawSystem::TDrawSystem(pTVar6);
  }
  uStack_4 = 0xffffffff;
  this->draw_system = pTVar6;
  if (pTVar6 == (TDrawSystem *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  TDrawSystem::CheckAvailModes(pTVar6,this->prog_info->full_screen);
  iVar7 = TDrawSystem::IsModeAvail(this->draw_system,this->prog_info->main_wid,0,8);
  if (iVar7 == 0) {
    if (this->prog_info->main_wid != 0x280) {
      iVar7 = TDrawSystem::IsModeAvail(this->draw_system,0x280,0,8);
      if (iVar7 != 0) {
        this->prog_info->main_wid = 0x280;
        this->prog_info->main_hgt = 0x1e0;
        goto LAB_0041eb16;
      }
    }
    if (this->prog_info->main_wid != 800) {
      iVar7 = TDrawSystem::IsModeAvail(this->draw_system,800,0,8);
      if (iVar7 != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
        goto LAB_0041eb16;
      }
    }
    if (this->prog_info->main_wid != 0x400) {
      iVar7 = TDrawSystem::IsModeAvail(this->draw_system,0x400,0,8);
      if (iVar7 != 0) {
        this->prog_info->main_wid = 0x400;
        this->prog_info->main_hgt = 0x300;
        goto LAB_0041eb16;
      }
    }
    if (this->prog_info->main_wid == 0x500) goto LAB_0041eb4d;
    iVar7 = TDrawSystem::IsModeAvail(this->draw_system,0x400,0,8);
    if (iVar7 == 0) goto LAB_0041eb4d;
    this->prog_info->main_wid = 0x500;
    this->prog_info->main_hgt = 0x400;
  }
LAB_0041eb16:
  pRVar1 = this->prog_info;
  iVar5 = TDrawSystem::Init(this->draw_system,pRVar1->instance,this->prog_window,this->prog_palette,
                            (iVar5 != 0) + '\x01',(iVar3 != 0) + '\x01',pRVar1->main_wid,
                            pRVar1->main_hgt,(uint)(iVar2 != 0));
  if (iVar5 != 0) {
    TPanelSystem::release_palette(&panel_system,this->prog_palette);
    pvVar8 = TPanelSystem::get_palette(&panel_system,this->prog_info->pal_file,0xc544);
    this->prog_palette = pvVar8;
    this_00 = this->draw_system->DrawArea;
    this->draw_area = this_00;
    TDrawArea::Clear(this_00,(tagRECT *)0x0,0);
    TDrawSystem::Paint(this->draw_system,(tagRECT *)0x0);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0041eb4d:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: setup_palette
// Address: 0041ebc0
/* protected: virtual int __thiscall RGE_Base_Game::setup_palette(void) */

int __thiscall RGE_Base_Game::setup_palette(RGE_Base_Game *this)
{
  void *pvVar1;
  
  pvVar1 = TPanelSystem::get_palette(&panel_system,this->prog_info->pal_file,0xc544);
  this->prog_palette = pvVar1;
  return (uint)(pvVar1 != (void *)0x0);
}

// --------------------------------------------------

// Function: setup_mouse
// Address: 0041ebf0
// [HELPER] s_Custom_Mouse: "Custom Mouse"
/* WARNING: Variable defined which should be unmapped: custom_type */
/* protected: virtual int __thiscall RGE_Base_Game::setup_mouse(void) */

int __thiscall RGE_Base_Game::setup_mouse(RGE_Base_Game *this)
{
  int iVar1;
  TMousePointer *pTVar2;
  RGE_Base_Game *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  int custom_type;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca9b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar1 = TRegistry::RegGetInt(this->registry,0,s_Custom_Mouse);
  if (iVar1 == -1) {
    TRegistry::RegSetInt(this->registry,0,s_Custom_Mouse,0);
  }
  else {
    if (iVar1 == 1) {
      pRVar3 = (RGE_Base_Game *)0x1;
      goto LAB_0041ec3b;
    }
    if (iVar1 == 2) {
      this->custom_mouse = 0;
      pRVar3 = this;
      goto LAB_0041ec3b;
    }
  }
  pRVar3 = (RGE_Base_Game *)0x0;
LAB_0041ec3b:
  pTVar2 = (TMousePointer *)operator_new(0x254);
  local_4 = 0;
  if (pTVar2 == (TMousePointer *)0x0) {
    pTVar2 = (TMousePointer *)0x0;
  }
  else {
    pTVar2 = (TMousePointer *)TMousePointer::TMousePointer(pTVar2,(int)pRVar3);
  }
  local_4 = 0xffffffff;
  this->mouse_pointer = pTVar2;
  if (pTVar2 == (TMousePointer *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  iVar1 = TMousePointer::setup
                    (pTVar2,this->custom_mouse,this->draw_area,this->prog_info->cursor_file,51000,10
                    );
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  mouse_off(this);
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_chat
// Address: 0041ed00
/* protected: virtual int __thiscall RGE_Base_Game::setup_chat(void) */

int __thiscall RGE_Base_Game::setup_chat(RGE_Base_Game *this)
{
  TChat *this_00;
  undefined4 *unaff_FS_OFFSET;
  bool bVar1;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cabb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TChat *)operator_new(0x100);
  local_4 = 0;
  if (this_00 == (TChat *)0x0) {
    chat = (TChat *)0x0;
  }
  else {
    chat = (TChat *)TChat::TChat(this_00,this->prog_window);
  }
  bVar1 = chat != (TChat *)0x0;
  *unaff_FS_OFFSET = local_c;
  return (uint)bVar1;
}

// --------------------------------------------------

// Function: setup_registry
// Address: 0041ed70
/* protected: virtual int __thiscall RGE_Base_Game::setup_registry(void) */

int __thiscall RGE_Base_Game::setup_registry(RGE_Base_Game *this)
{
  TRegistry *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cadb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TRegistry *)operator_new(0x110);
  local_4 = 0;
  if (pTVar1 == (TRegistry *)0x0) {
    pTVar1 = (TRegistry *)0x0;
  }
  else {
    pTVar1 = (TRegistry *)TRegistry::TRegistry(pTVar1,this->prog_info->registry_key);
  }
  this->registry = pTVar1;
  *unaff_FS_OFFSET = local_c;
  return (uint)(pTVar1 != (TRegistry *)0x0);
}

// --------------------------------------------------

// Function: setup_debugging_log
// Address: 0041ede0
/* protected: virtual int __thiscall RGE_Base_Game::setup_debugging_log(void) */

int __thiscall RGE_Base_Game::setup_debugging_log(RGE_Base_Game *this)
{
  TDebuggingLog *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cafb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TDebuggingLog *)operator_new(0x7b0);
  local_4 = 0;
  if (pTVar1 == (TDebuggingLog *)0x0) {
    pTVar1 = (TDebuggingLog *)0x0;
  }
  else {
    pTVar1 = (TDebuggingLog *)TDebuggingLog::TDebuggingLog(pTVar1);
  }
  local_4 = 0xffffffff;
  this->debugLog = pTVar1;
  if (pTVar1 == (TDebuggingLog *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  TDebuggingLog::LogFile(pTVar1,this->log_comm);
  TDebuggingLog::LogOutput(this->debugLog,log_output);
  TDebuggingLog::LogTimestamp(this->debugLog,1);
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_comm
// Address: 0041ee90
/* protected: virtual int __thiscall RGE_Base_Game::setup_comm(void) */

int __thiscall RGE_Base_Game::setup_comm(RGE_Base_Game *this)
{
  TCommunications_Handler *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb1b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TCommunications_Handler *)operator_new(0x1774);
  local_4 = 0;
  if (pTVar1 == (TCommunications_Handler *)0x0) {
    pTVar1 = (TCommunications_Handler *)0x0;
  }
  else {
    pTVar1 = (TCommunications_Handler *)
             TCommunications_Handler::TCommunications_Handler
                       (pTVar1,this->prog_window,(uchar)this->prog_info->max_players,chat,
                        this->prog_info->game_guid);
  }
  local_4 = 0xffffffff;
  this->comm_handler = pTVar1;
  if (pTVar1 == (TCommunications_Handler *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  TCommunications_Handler::StopIfSyncFail(pTVar1,this->comm_syncstop);
  TCommunications_Handler::ShowSyncChatMsgs(this->comm_handler,this->comm_syncmsg);
  TCommunications_Handler::SetStepMode(this->comm_handler,this->comm_stepmode);
  TCommunications_Handler::SetSpeedControl(this->comm_handler,this->comm_speed);
  TCommunications_Handler::DropPacketsIntentionally(this->comm_handler,this->comm_droppackets);
  comm = this->comm_handler;
  if (this->world != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_communications(this->world,this->comm_handler);
  }
  if (speed_val1 != 0) {
    TCommunications_Handler::SetSpeedV1(this->comm_handler,speed_val1);
  }
  if (speed_val2 != 0) {
    TCommunications_Handler::SetSpeedV1(this->comm_handler,speed_val2);
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: reset_comm
// Address: 0041eff0
/* public: virtual int __thiscall RGE_Base_Game::reset_comm(void) */

int __thiscall RGE_Base_Game::reset_comm(RGE_Base_Game *this)
{
  TCommunications_Handler *this_00;
  int iVar1;
  
  this_00 = this->comm_handler;
  if (this_00 != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::~TCommunications_Handler(this_00);
    operator_delete(this_00);
    this->comm_handler = (TCommunications_Handler *)0x0;
    comm = (TCommunications_Handler *)0x0;
  }
  iVar1 = (**(code **)(this->_padding_ + 0x88))();
  return iVar1;
}

// --------------------------------------------------

// Function: setup_sound_system
// Address: 0041f030
// [HELPER] s_Sound_Volume: "Sound Volume"
/* protected: virtual int __thiscall RGE_Base_Game::setup_sound_system(void) */

int __thiscall RGE_Base_Game::setup_sound_system(RGE_Base_Game *this)
{
  TSound_Driver *pTVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb3b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar3 = 0;
  if (this->prog_info->use_sound != 0) {
    pTVar1 = (TSound_Driver *)operator_new(0x69c);
    local_4 = 0;
    if (pTVar1 == (TSound_Driver *)0x0) {
      pTVar1 = (TSound_Driver *)0x0;
    }
    else {
      pTVar1 = (TSound_Driver *)
               TSound_Driver::TSound_Driver(pTVar1,this->prog_window,this->prog_info->sounds_dir);
    }
    local_4 = 0xffffffff;
    this->sound_system = pTVar1;
    if (pTVar1 != (TSound_Driver *)0x0) {
      iVar2 = TSound_Driver::driver_active(pTVar1);
      if (iVar2 == 0) {
        pTVar1 = this->sound_system;
        if (pTVar1 != (TSound_Driver *)0x0) {
          TSound_Driver::~TSound_Driver(pTVar1);
          operator_delete(pTVar1);
        }
        this->sound_system = (TSound_Driver *)0x0;
        goto LAB_0041f0f9;
      }
    }
    sound_driver = this->sound_system;
    iVar2 = TRegistry::RegGetInt(this->registry,1,s_Sound_Volume);
    if (iVar2 != -1) {
      iVar3 = -iVar2;
    }
    TSound_Driver::set_volume(this->sound_system,iVar3,1);
  }
  (**(code **)(this->_padding_ + 0x58))();
LAB_0041f0f9:
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_music_system
// Address: 0041f110
// [HELPER] s_Music_Volume: "Music Volume"
// [HELPER] s__s__s: "%s\n%s"
/* WARNING: Variable defined which should be unmapped: music_type */
/* public: virtual int __thiscall RGE_Base_Game::setup_music_system(void) */

int __thiscall RGE_Base_Game::setup_music_system(RGE_Base_Game *this)
{
  RGE_Prog_Info *pRVar1;
  int iVar2;
  TMusic_System *pTVar3;
  uchar uVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  uchar music_type;
  char music_path [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb5e;
  *unaff_FS_OFFSET = &local_c;
  if (this->prog_info->use_music != 0) {
    iVar5 = -5000;
    iVar2 = TRegistry::RegGetInt(this->registry,1,s_Music_Volume);
    if (iVar2 != -1) {
      iVar5 = -iVar2;
    }
    if (iVar5 < -0x26ab) {
      this->prog_info->use_music = 0;
      pTVar3 = this->music_system;
      if (pTVar3 != (TMusic_System *)0x0) {
        TMusic_System::~TMusic_System(pTVar3);
        operator_delete(pTVar3);
        this->music_system = (TMusic_System *)0x0;
      }
    }
    else if (this->music_system == (TMusic_System *)0x0) {
      pRVar1 = this->prog_info;
      if (pRVar1->use_cd_audio == 0) {
        if (pRVar1->use_midi == 0) {
          if (pRVar1->use_ima == 0) {
            uVar4 = (-(pRVar1->use_wave_music != 0) & 2U) + 1;
          }
          else {
            uVar4 = '\x04';
          }
        }
        else {
          uVar4 = '\x02';
        }
      }
      else {
        uVar4 = '\x01';
      }
      sprintf(music_path + 4,s__s__s,this->work_dir,pRVar1->sounds_dir);
      music_path._0_4_ = operator_new(0x3f8);
      local_4 = 0;
      if ((TMusic_System *)music_path._0_4_ == (TMusic_System *)0x0) {
        pTVar3 = (TMusic_System *)0x0;
      }
      else {
        pTVar3 = (TMusic_System *)
                 TMusic_System::TMusic_System
                           ((TMusic_System *)music_path._0_4_,uVar4,this->prog_info->instance,
                            this->prog_window,this->sound_system,music_path + 4);
      }
      local_4 = 0xffffffff;
      this->music_system = pTVar3;
      if ((((pTVar3 != (TMusic_System *)0x0) && (uVar4 == '\x01')) &&
          (this->prog_info->use_cd_audio == 0)) &&
         ((pTVar3->device_open == 0 || (pTVar3->track_count < 2)))) {
        iVar2 = TMusic_System::set_music_type(pTVar3,'\x02');
        if (iVar2 == 0) {
          TMusic_System::set_music_type(this->music_system,'\x03');
        }
      }
      if (this->music_system != (TMusic_System *)0x0) {
        TMusic_System::set_volume(this->music_system,iVar5,1);
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_shapes
// Address: 0041f2d0
// [HELPER] s_groupnum_shp: "groupnum.shp"
// [HELPER] s_moveto_shp: "moveto.shp"
// [HELPER] s_waypoint_shp: "waypoint.shp"
/* protected: virtual int __thiscall RGE_Base_Game::setup_shapes(void) */

int __thiscall RGE_Base_Game::setup_shapes(RGE_Base_Game *this)
{
  TShape **ppTVar1;
  int iVar2;
  int iVar3;
  TShape *pTVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb91;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->shape_num = 3;
  ppTVar1 = (TShape **)calloc(3,4);
  this->shapes = ppTVar1;
  if (ppTVar1 == (TShape **)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  iVar2 = 0;
  if (0 < this->shape_num) {
    do {
      iVar3 = iVar2 + 1;
      this->shapes[iVar2] = (TShape *)0x0;
      iVar2 = iVar3;
    } while (iVar3 < this->shape_num);
  }
  pTVar4 = (TShape *)operator_new(0x20);
  local_4 = 0;
  if (pTVar4 == (TShape *)0x0) {
    pTVar4 = (TShape *)0x0;
  }
  else {
    pTVar4 = (TShape *)TShape::TShape(pTVar4,s_groupnum_shp,0xc4e3);
  }
  local_4 = 0xffffffff;
  *this->shapes = pTVar4;
  pTVar4 = (TShape *)operator_new(0x20);
  local_4 = 1;
  if (pTVar4 == (TShape *)0x0) {
    pTVar4 = (TShape *)0x0;
  }
  else {
    pTVar4 = (TShape *)TShape::TShape(pTVar4,s_waypoint_shp,0xc4e4);
  }
  local_4 = 0xffffffff;
  this->shapes[1] = pTVar4;
  pTVar4 = (TShape *)operator_new(0x20);
  local_4 = 2;
  if (pTVar4 == (TShape *)0x0) {
    pTVar4 = (TShape *)0x0;
  }
  else {
    pTVar4 = (TShape *)TShape::TShape(pTVar4,s_moveto_shp,0xc4e5);
  }
  this->shapes[2] = pTVar4;
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_sounds
// Address: 0041f400
// [HELPER] s_button1_wav: "button1.wav"
// [HELPER] s_button2_wav: "button2.wav"
// [HELPER] s_chatrcvd_wav: "chatrcvd.wav"
/* protected: virtual int __thiscall RGE_Base_Game::setup_sounds(void) */

int __thiscall RGE_Base_Game::setup_sounds(RGE_Base_Game *this)
{
  TDigital **ppTVar1;
  int iVar2;
  TDigital *pTVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbc1;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->sound_num = 3;
  ppTVar1 = (TDigital **)calloc(3,4);
  this->sounds = ppTVar1;
  if (ppTVar1 == (TDigital **)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  iVar4 = 0;
  if (0 < this->sound_num) {
    do {
      iVar2 = iVar4 + 1;
      this->sounds[iVar4] = (TDigital *)0x0;
      iVar4 = iVar2;
    } while (iVar2 < this->sound_num);
  }
  pTVar3 = (TDigital *)operator_new(0x3c);
  local_4 = 0;
  if (pTVar3 == (TDigital *)0x0) {
    pTVar3 = (TDigital *)0x0;
  }
  else {
    pTVar3 = (TDigital *)TDigital::TDigital(pTVar3,this->sound_system,s_button1_wav,0xc47c);
  }
  local_4 = 0xffffffff;
  *this->sounds = pTVar3;
  pTVar3 = (TDigital *)operator_new(0x3c);
  local_4 = 1;
  if (pTVar3 == (TDigital *)0x0) {
    pTVar3 = (TDigital *)0x0;
  }
  else {
    pTVar3 = (TDigital *)TDigital::TDigital(pTVar3,this->sound_system,s_button2_wav,0xc47d);
  }
  local_4 = 0xffffffff;
  this->sounds[1] = pTVar3;
  pTVar3 = (TDigital *)operator_new(0x3c);
  local_4 = 2;
  if (pTVar3 == (TDigital *)0x0) {
    pTVar3 = (TDigital *)0x0;
  }
  else {
    pTVar3 = (TDigital *)TDigital::TDigital(pTVar3,this->sound_system,s_chatrcvd_wav,0xc47e);
  }
  iVar4 = 0;
  local_4 = 0xffffffff;
  this->sounds[2] = pTVar3;
  if (0 < this->sound_num) {
    do {
      if (this->sounds[iVar4] != (TDigital *)0x0) {
        TDigital::load(this->sounds[iVar4],(char *)0x0,-1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->sound_num);
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_fonts
// Address: 0041f560
// [HELPER] s_basegame__setup_fonts: "basegame::setup_fonts"
/* WARNING: Variable defined which should be unmapped: i */
/* protected: virtual int __thiscall RGE_Base_Game::setup_fonts(void) */

int __thiscall RGE_Base_Game::setup_fonts(RGE_Base_Game *this)
{
  RGE_Font *pRVar1;
  void *pvVar2;
  undefined4 uVar3;
  short sVar4;
  void *pvVar5;
  short i;
  tagTEXTMETRICA tm;
  
  this->font_num = 0xc;
  pRVar1 = (RGE_Font *)calloc(0xc,0xc);
  this->fonts = pRVar1;
  if (pRVar1 == (RGE_Font *)0x0) {
    return 0;
  }
  pvVar2 = TDrawArea::GetDc(this->draw_area,s_basegame__setup_fonts);
  if (pvVar2 != (void *)0x0) {
    sVar4 = 0;
    if (0 < this->font_num) {
      do {
        tm.tmHeight = (long)sVar4;
        switch(tm.tmHeight) {
        case 0:
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
          pvVar5 = make_font(this,pvVar2,0x6e,0);
          break;
        case 1:
                    /* language.dll match for 0x71: "Copperplate Gothic Light" */
          pvVar5 = make_font(this,pvVar2,0x71,0);
          break;
        default:
          pvVar5 = (void *)0x0;
          break;
        case 4:
                    /* language.dll match for 0x74: "Copperplate Gothic Light" */
          pvVar5 = make_font(this,pvVar2,0x74,0);
          break;
        case 6:
                    /* language.dll match for 0x83: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x83,0);
          break;
        case 7:
                    /* language.dll match for 0x77: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x77,0);
          break;
        case 8:
                    /* language.dll match for 0x80: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x80,1);
          break;
        case 9:
                    /* language.dll match for 0x7a: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x7a,0);
          break;
        case 10:
                    /* language.dll match for 0x7d: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x7d,0);
          break;
        case 0xb:
                    /* language.dll match for 0x80: "Arial" */
          pvVar5 = make_font(this,pvVar2,0x80,0);
        }
        if (pvVar5 != (void *)0x0) {
          uVar3 = SelectObject(pvVar2,pvVar5);
          GetTextMetricsA(pvVar2,&tm.tmAscent);
          this->fonts[tm.tmHeight].font = pvVar5;
          this->fonts[tm.tmHeight].font_wid = tm.tmMaxCharWidth;
          this->fonts[tm.tmHeight].font_hgt = tm.tmAscent + tm.tmAveCharWidth;
          SelectObject(pvVar2,uVar3);
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < this->font_num);
    }
    TDrawArea::ReleaseDc(this->draw_area,s_basegame__setup_fonts);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: setup_blank_screen
// Address: 0041f730
// [HELPER] s_Blank_Screen: "Blank Screen"
/* protected: virtual int __thiscall RGE_Base_Game::setup_blank_screen(void) */

int __thiscall RGE_Base_Game::setup_blank_screen(RGE_Base_Game *this)
{
  TScreenPanel *pTVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbdb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TScreenPanel *)operator_new(0x478);
  local_4 = 0;
  if (pTVar1 == (TScreenPanel *)0x0) {
    pTVar1 = (TScreenPanel *)0x0;
  }
  else {
    pTVar1 = (TScreenPanel *)TScreenPanel::TScreenPanel(pTVar1,s_Blank_Screen);
  }
  local_4 = 0xffffffff;
  if (pTVar1 == (TScreenPanel *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  lVar2 = TScreenPanel::setup(pTVar1,this->draw_area,(char *)0x0,-1,0);
  if (lVar2 == 0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Blank_Screen,0);
  set_render_all(this);
  SendMessageA(this->prog_window,0xf,0,0);
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: setup_timings
// Address: 0041f800
/* protected: virtual void __thiscall RGE_Base_Game::setup_timings(void) */

void __thiscall RGE_Base_Game::setup_timings(RGE_Base_Game *this)
{
  this->timings[1].include_in_total = 1;
  this->timings[2].include_in_total = 1;
  this->timings[3].include_in_total = 1;
  this->timings[10].include_in_total = 1;
  this->timings[0xd].include_in_total = 1;
  this->timings[0].is_summary = 1;
  this->timings[4].is_summary = 1;
  return;
}

// --------------------------------------------------

// Function: stop_sound_system
// Address: 0041f830
// [HELPER] s_Sound_Volume: "Sound Volume"
/* protected: virtual void __thiscall RGE_Base_Game::stop_sound_system(void) */

void __thiscall RGE_Base_Game::stop_sound_system(RGE_Base_Game *this)
{
  TDigital *this_00;
  TSound_Driver *this_01;
  RGE_Game_World *pRVar1;
  long lVar2;
  int iVar3;
  
  if (chat != (TChat *)0x0) {
    TChat::StopSoundSystem(chat);
  }
  TPanelSystem::stop_sound_system(&panel_system);
  pRVar1 = this->world;
  if ((pRVar1 != (RGE_Game_World *)0x0) && (iVar3 = 0, 0 < pRVar1->sound_num)) {
    do {
      RGE_Sound::restart_sound(pRVar1->sounds[iVar3],(TSound_Driver *)0x0);
      pRVar1 = this->world;
      iVar3 = iVar3 + 1;
    } while (iVar3 < pRVar1->sound_num);
  }
  if (this->sounds != (TDigital **)0x0) {
    iVar3 = 0;
    if (0 < this->sound_num) {
      do {
        this_00 = this->sounds[iVar3];
        if (this_00 != (TDigital *)0x0) {
          TDigital::~TDigital(this_00);
          operator_delete(this_00);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < this->sound_num);
    }
    free(this->sounds);
    this->sounds = (TDigital **)0x0;
  }
  (**(code **)(this->_padding_ + 0x5c))();
  if (this->sound_system != (TSound_Driver *)0x0) {
    lVar2 = TSound_Driver::get_volume(this->sound_system);
    TRegistry::RegSetInt(this->registry,1,s_Sound_Volume,-lVar2);
    this_01 = this->sound_system;
    if (this_01 != (TSound_Driver *)0x0) {
      TSound_Driver::~TSound_Driver(this_01);
      operator_delete(this_01);
    }
    this->sound_system = (TSound_Driver *)0x0;
    sound_driver = (TSound_Driver *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: restart_sound_system
// Address: 0041f920
/* protected: virtual int __thiscall RGE_Base_Game::restart_sound_system(void) */

int __thiscall RGE_Base_Game::restart_sound_system(RGE_Base_Game *this)
{
  int iVar1;
  int iVar2;
  RGE_Game_World *pRVar3;
  
  if (this->sound_system == (TSound_Driver *)0x0) {
    iVar1 = this->_padding_;
    iVar2 = (**(code **)(iVar1 + 0x8c))();
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(iVar1 + 0x94))();
    if (iVar2 == 0) {
      return 0;
    }
    pRVar3 = this->world;
    if ((pRVar3 != (RGE_Game_World *)0x0) && (iVar2 = 0, 0 < pRVar3->sound_num)) {
      do {
        RGE_Sound::restart_sound(pRVar3->sounds[iVar2],this->sound_system);
        pRVar3 = this->world;
        iVar2 = iVar2 + 1;
      } while (iVar2 < pRVar3->sound_num);
    }
    TPanelSystem::restart_sound_system(&panel_system);
    if (chat != (TChat *)0x0) {
      TChat::RestartSoundSystem(chat,this->sound_system);
    }
    (**(code **)(iVar1 + 0xb0))();
  }
  return 1;
}

// --------------------------------------------------

// Function: stop_music_system
// Address: 0041f9b0
/* protected: virtual void __thiscall RGE_Base_Game::stop_music_system(void) */

void __thiscall RGE_Base_Game::stop_music_system(RGE_Base_Game *this)
{
  if (this->music_system != (TMusic_System *)0x0) {
    TMusic_System::get_play_info
              (this->music_system,&this->save_music_type,&this->save_music_track_from,
               &this->save_music_track_to,&this->save_music_cur_track,this->save_music_file,
               &this->save_music_loop,&this->save_music_pos);
    TMusic_System::stop_track(this->music_system);
  }
  return;
}

// --------------------------------------------------

// Function: restart_music_system
// Address: 0041f9f0
/* protected: virtual int __thiscall RGE_Base_Game::restart_music_system(void) */

int __thiscall RGE_Base_Game::restart_music_system(RGE_Base_Game *this)
{
  TMusic_System *this_00;
  int iVar1;
  
  this_00 = this->music_system;
  if (this_00 == (TMusic_System *)0x0) {
    return 1;
  }
  iVar1 = this->save_music_track_from;
  if (iVar1 != 0) {
    if (iVar1 == this->save_music_track_to) {
      TMusic_System::play_track(this_00,iVar1,this->save_music_loop,this->save_music_pos);
      return 1;
    }
    if ((iVar1 != 0) && (this->save_music_track_to != 0)) {
      TMusic_System::play_tracks
                (this_00,iVar1,this->save_music_track_to,this->save_music_loop,
                 this->save_music_cur_track,this->save_music_pos);
      return 1;
    }
  }
  if (this->save_music_file[0] != '\0') {
    TMusic_System::play_file
              (this_00,this->save_music_file,this->save_music_loop,this->save_music_pos);
  }
  return 1;
}

// --------------------------------------------------

// Function: shutdown_music_system
// Address: 0041fa90
// [HELPER] s_Music_Volume: "Music Volume"
/* public: virtual void __thiscall RGE_Base_Game::shutdown_music_system(void) */

void __thiscall RGE_Base_Game::shutdown_music_system(RGE_Base_Game *this)
{
  TMusic_System *this_00;
  
  if (this->music_system != (TMusic_System *)0x0) {
    (**(code **)(this->_padding_ + 0xac))();
    TRegistry::RegSetInt(this->registry,1,s_Music_Volume,-this->music_system->volume);
    this_00 = this->music_system;
    if (this_00 != (TMusic_System *)0x0) {
      TMusic_System::~TMusic_System(this_00);
      operator_delete(this_00);
    }
    this->music_system = (TMusic_System *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: make_font
// Address: 0041faf0
// [HELPER] s_B: "B"
// [HELPER] s_b: "b"
/* WARNING: Variable defined which should be unmapped: style */
/* protected: void * __thiscall RGE_Base_Game::make_font(void *,long,int) */

void * __thiscall
RGE_Base_Game::make_font(RGE_Base_Game *this,void *param_1,long param_2,int param_3)
{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcStack_13c;
  undefined4 uStack_138;
  long lStack_130;
  char *pcStack_12c;
  undefined4 uStack_128;
  char style [10];
  char point_size_str [10];
  char face_name [256];
  
  pcStack_12c = face_name + 4;
  uStack_128 = 0x100;
  lStack_130 = param_2;
  pcVar1 = *(code **)(this->_padding_ + 0x20);
  (*pcVar1)();
  if (point_size_str[4] == '\0') {
    return (void *)0x0;
  }
  pcStack_13c = style + 4;
  uStack_138 = 10;
  (*pcVar1)(param_2 + 1);
  iVar2 = atoi(&stack0xfffffedc);
  (*pcVar1)(param_2 + 2,&lStack_130,10);
  iVar3 = strstr(&pcStack_13c,s_B);
  if (iVar3 == 0) {
    iVar3 = strstr(&pcStack_13c,s_b);
    iVar4 = 400;
    if (iVar3 == 0) goto LAB_0041fb90;
  }
  iVar4 = 700;
LAB_0041fb90:
  pvVar5 = make_font(this,(void *)face_name._228_4_,&stack0xfffffedc,iVar2,iVar4,face_name._236_4_);
  return pvVar5;
}

// --------------------------------------------------

// Function: make_font
// Address: 0041fbc0
/* WARNING: Variable defined which should be unmapped: logfont */
/* protected: void * __thiscall RGE_Base_Game::make_font(void *,char *,int,int,int) */

void * __thiscall
RGE_Base_Game::make_font
          (RGE_Base_Game *this,void *param_1,char *param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  uchar *puVar9;
  undefined4 unaff_retaddr;
  tagLOGFONTA logfont;
  char str [256];
  char *pcStack_4;
  
                    /* language.dll match for 0x65: "1" */
  (**(code **)(this->_padding_ + 0x20))(0x65,str + 4,0x100);
  logfont.lfOrientation._3_1_ = atoi(logfont.lfFaceName + 0x18);
  puVar7 = (undefined4 *)&stack0xfffffeb8;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  MulDiv(unaff_retaddr,0x60,0x48);
  logfont.lfHeight = 0;
  logfont.lfWidth = 0;
  logfont.lfOrientation._0_1_ = 0;
  logfont.lfOrientation._1_1_ = 0;
  logfont.lfWeight._0_1_ = 0;
  logfont.lfWeight._1_1_ = 0;
  logfont.lfOrientation._2_1_ = param_2._0_1_;
  logfont.lfWeight._2_1_ = 2;
  logfont.lfWeight._3_1_ = 2;
  uVar4 = 0xffffffff;
  do {
    pcVar8 = pcStack_4;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcStack_4 + 1;
    cVar1 = *pcStack_4;
    pcStack_4 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  logfont.lfEscapement = (long)param_1;
  puVar6 = (uchar *)(pcVar8 + -uVar4);
  puVar9 = &logfont.lfItalic;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)puVar9 = *(undefined4 *)puVar6;
    puVar6 = puVar6 + 4;
    puVar9 = puVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  pvVar2 = (void *)CreateFontIndirectA(&stack0xfffffeb8);
  return pvVar2;
}

// --------------------------------------------------

// Function: check_for_cd
// Address: 0041fc90
// [HELPER] s_CDPath: "CDPath"
/* WARNING: Variable defined which should be unmapped: vol_ser_num */
/* public: int __thiscall RGE_Base_Game::check_for_cd(int) */

int __thiscall RGE_Base_Game::check_for_cd(RGE_Base_Game *this,int param_1)
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  ulong vol_ser_num;
  ulong file_sys_flags;
  ulong max_comp_len;
  char vol_name [256];
  char file_sys_name [256];
  
  if (this->prog_info->verify_cd == 0) {
    return 1;
  }
  if (0 < param_1) {
    iVar4 = 0;
    uVar5 = 0;
    do {
      uVar1 = uVar5 + 1;
      iVar2 = TCommunications_Handler::GetPlayerHumanity(this->comm_handler,uVar1);
      if (iVar2 == 2) {
        iVar2 = playerHasCD(this,uVar5);
        if (iVar2 != 0) {
          iVar4 = iVar4 + 1;
        }
      }
      uVar5 = uVar1;
    } while ((int)uVar1 < 9);
    return (uint)(param_1 <= this->prog_info->max_players_per_cd * iVar4);
  }
  if (force_cd != 0) {
    return 1;
  }
  pcVar3 = TRegistry::RegGetAscii(this->registry,0,s_CDPath);
  if (pcVar3 == (char *)0x0) {
    return 0;
  }
  iVar4 = GetDriveTypeA();
  if (iVar4 != 5) {
    return 0;
  }
  iVar4 = GetVolumeInformationA
                    (pcVar3,vol_name,0x100,&vol_ser_num,&max_comp_len,&file_sys_flags,file_sys_name)
  ;
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = stricmp(&stack0xfffffddc,this->prog_info->vol_name);
  return (uint)(iVar4 == 0);
}

// --------------------------------------------------

// Function: check_expiration
// Address: 0041fde0
/* WARNING: Variable defined which should be unmapped: cur_date */
/* protected: int __thiscall RGE_Base_Game::check_expiration(void) */

int __thiscall RGE_Base_Game::check_expiration(RGE_Base_Game *this)
{
  RGE_Prog_Info *pRVar1;
  int iVar2;
  int *piVar3;
  long cur_date;
  tm kill_def;
  
  piVar3 = &kill_def.tm_min;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  pRVar1 = this->prog_info;
  kill_def.tm_year = pRVar1->expire_month + -1;
  kill_def.tm_mon = (int)pRVar1->expire_day;
  kill_def.tm_wday = (int)pRVar1->expire_year;
  iVar2 = mktime(&kill_def.tm_min);
  time(&kill_def);
  return (uint)(kill_def.tm_sec <= iVar2);
}

// --------------------------------------------------

// Function: check_multi_copies
// Address: 0041fe50
// [HELPER] s_LOBBY: "LOBBY"
/* protected: int __thiscall RGE_Base_Game::check_multi_copies(void) */

int __thiscall RGE_Base_Game::check_multi_copies(RGE_Base_Game *this)
{
  uchar uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  pvVar2 = (void *)CreateMutexA(0,1,this->prog_info);
  this->prog_mutex = pvVar2;
  iVar3 = GetLastError();
  if (iVar3 != 0xb7) {
    if (this->prog_mutex != (void *)0x0) {
      ReleaseMutex(this->prog_mutex);
    }
    return 1;
  }
  iVar3 = FindWindowA(this->prog_info,this->prog_info->prog_title);
  if (iVar3 != 0) {
    uVar1 = check_prog_argument(this,s_LOBBY);
    if (uVar1 != '\0') {
      SendMessageA(iVar3,0x10,0,0);
      if (this->prog_mutex == (void *)0x0) {
        return 1;
      }
      ReleaseMutex(this->prog_mutex);
      return 1;
    }
    iVar4 = IsIconic(iVar3);
    if (iVar4 != 0) {
      ShowWindow(iVar3,1);
    }
    SetForegroundWindow(iVar3);
    uVar5 = GetLastActivePopup(iVar3);
    BringWindowToTop(uVar5);
  }
  if (this->prog_mutex != (void *)0x0) {
    ReleaseMutex(this->prog_mutex);
    CloseHandle(this->prog_mutex);
    this->prog_mutex = (void *)0x0;
  }
  return 0;
}

// --------------------------------------------------

// Function: check_paint
// Address: 0041ff20
/* WARNING: Variable defined which should be unmapped: surface_status */
/* protected: int __thiscall RGE_Base_Game::check_paint(void) */

int __thiscall RGE_Base_Game::check_paint(RGE_Base_Game *this)
{
  uchar uVar1;
  int iVar2;
  uchar surface_status;
  tagRECT update_rect;
  
  if (this->prog_ready == 0) {
    clear_window(this);
    ValidateRect(this->prog_window,0);
    return 0;
  }
  iVar2 = IsIconic(this->prog_window);
  if (iVar2 != 0) {
    ValidateRect(this->prog_window,0);
    return 0;
  }
  if (this->prog_active == 0) {
    iVar2 = GetUpdateRect(this->prog_window,&update_rect.top,0);
    if (iVar2 != 0) {
      TDrawSystem::Paint(this->draw_system,(tagRECT *)&update_rect.top);
    }
    ValidateRect(this->prog_window,0);
    return 0;
  }
  uVar1 = TDrawSystem::CheckSurfaces(this->draw_system);
  update_rect.left = CONCAT31(update_rect.left._1_3_,uVar1);
  if (uVar1 != '\x01') {
    if (uVar1 == '\x02') {
      TDrawSystem::ClearRestored(this->draw_system);
      set_render_all(this);
    }
    else if (uVar1 == '\x03') {
      ValidateRect(this->prog_window,0);
      DestroyWindow(this->prog_window);
      return 0;
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: clear_window
// Address: 00420000
/* WARNING: Variable defined which should be unmapped: rect */
/* protected: void __thiscall RGE_Base_Game::clear_window(void) */

void __thiscall RGE_Base_Game::clear_window(RGE_Base_Game *this)
{
  undefined4 uVar1;
  undefined4 uVar2;
  tagRECT rect;
  
  if (this->prog_window != (void *)0x0) {
    uVar1 = GetDC(this->prog_window);
    GetClientRect(this->prog_window,&rect.top);
    uVar2 = GetStockObject(4);
    FillRect(uVar1,&rect.top,uVar2);
    ReleaseDC(this->prog_window,uVar1);
  }
  return;
}

// --------------------------------------------------

// Function: create_world
// Address: 00420050
/* protected: virtual class RGE_Game_World * __thiscall RGE_Base_Game::create_world(void) */

RGE_Game_World * __thiscall RGE_Base_Game::create_world(RGE_Base_Game *this)
{
  RGE_Game_World *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbfb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Game_World *)operator_new(0x104);
  local_4 = 0;
  if (pRVar1 != (RGE_Game_World *)0x0) {
    pRVar1 = (RGE_Game_World *)RGE_Game_World::RGE_Game_World(pRVar1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Game_World *)0x0;
}

// --------------------------------------------------

// Function: close
// Address: 004200b0
/* public: void __thiscall RGE_Base_Game::close(void) */

void __thiscall RGE_Base_Game::close(RGE_Base_Game *this)
{
  SendMessageA(this->prog_window,0x10,0,0);
  return;
}

// --------------------------------------------------

// Function: create_dialog
// Address: 004200d0
/* public: int __thiscall RGE_Base_Game::create_dialog(class TPanel * *,class TPanel *) */

int __thiscall RGE_Base_Game::create_dialog(RGE_Base_Game *this,TPanel **param_1,TPanel *param_2)
{
  *param_1 = (TPanel *)0x0;
  if (param_2 == (TPanel *)0x0) {
    return 0;
  }
  if (param_2->error_code != 0) {
    (**(code **)param_2->_padding_)(1);
    return 0;
  }
  *param_1 = param_2;
  return 1;
}

// --------------------------------------------------

// Function: delete_dialog
// Address: 00420110
/* public: void __thiscall RGE_Base_Game::delete_dialog(class TPanel * *) */

void __thiscall RGE_Base_Game::delete_dialog(RGE_Base_Game *this,TPanel **param_1)
{
  if (*param_1 != (TPanel *)0x0) {
    (**(code **)(*param_1)->_padding_)(1);
    *param_1 = (TPanel *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: set_game_mode
// Address: 00420130
/* public: virtual void __thiscall RGE_Base_Game::set_game_mode(int,int) */

void __thiscall RGE_Base_Game::set_game_mode(RGE_Base_Game *this,int param_1,int param_2)
{
  this->game_mode = param_1;
  this->sub_game_mode = param_2;
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 00420150
/* public: virtual void __thiscall RGE_Base_Game::set_player(short) */

void __thiscall RGE_Base_Game::set_player(RGE_Base_Game *this,short param_1)
{
  RGE_Game_World *pRVar1;
  
  pRVar1 = this->world;
  if ((pRVar1 != (RGE_Game_World *)0x0) && (param_1 < pRVar1->player_num)) {
    pRVar1->curr_player = param_1;
    RGE_Map::clear_map_view_info(this->world->map);
  }
  return;
}

// --------------------------------------------------

// Function: get_paused
// Address: 00420180
/* public: int __thiscall RGE_Base_Game::get_paused(void) */

int __thiscall RGE_Base_Game::get_paused(RGE_Base_Game *this)
{
  int iVar1;
  
  if (this->prog_mode == 7) {
    return 0;
  }
  iVar1 = TCommunications_Handler::IsPaused(this->comm_handler);
  return iVar1;
}

// --------------------------------------------------

// Function: get_font
// Address: 004201a0
/* public: struct RGE_Font * __thiscall RGE_Base_Game::get_font(int) */

RGE_Font * __thiscall RGE_Base_Game::get_font(RGE_Base_Game *this,int param_1)
{
  if (this->fonts == (RGE_Font *)0x0) {
    return (RGE_Font *)0x0;
  }
  return this->fonts + param_1;
}

// --------------------------------------------------

// Function: get_shape
// Address: 004201c0
/* public: class TShape * __thiscall RGE_Base_Game::get_shape(int) */

TShape * __thiscall RGE_Base_Game::get_shape(RGE_Base_Game *this,int param_1)
{
  TShape *pTVar1;
  
  pTVar1 = (TShape *)this->shapes;
  if (pTVar1 == (TShape *)0x0) {
    return pTVar1;
  }
  return (TShape *)(&pTVar1->shape)[param_1];
}

// --------------------------------------------------

// Function: get_sound
// Address: 004201e0
/* public: class TDigital * __thiscall RGE_Base_Game::get_sound(int) */

TDigital * __thiscall RGE_Base_Game::get_sound(RGE_Base_Game *this,int param_1)
{
  TDigital *pTVar1;
  
  pTVar1 = (TDigital *)this->sounds;
  if (pTVar1 == (TDigital *)0x0) {
    return pTVar1;
  }
  return *(TDigital **)(pTVar1->sound_file + param_1 * 4 + -10);
}

// --------------------------------------------------

// Function: request_pause
// Address: 00420200
/* public: void __thiscall RGE_Base_Game::request_pause(void) */

void __thiscall RGE_Base_Game::request_pause(RGE_Base_Game *this)
{
  TCommunications_Handler::TogglePauseGame(this->comm_handler);
  if (this->world != (RGE_Game_World *)0x0) {
    this->world->temp_pause = '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: set_paused
// Address: 00420220
/* public: void __thiscall RGE_Base_Game::set_paused(int,int) */

void __thiscall RGE_Base_Game::set_paused(RGE_Base_Game *this,int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = get_paused(this);
  this->save_paused = iVar1;
  if (param_1 != iVar1) {
    if (param_1 != 0) {
      this->non_user_pause = param_2;
      request_pause(this);
      return;
    }
    this->non_user_pause = 0;
    request_pause(this);
  }
  return;
}

// --------------------------------------------------

// Function: get_mouse_info
// Address: 00420270
/* public: void __thiscall RGE_Base_Game::get_mouse_info(unsigned int,long,struct tagPOINT &,int
   &,int &,int &,int &) */

void __thiscall
RGE_Base_Game::get_mouse_info
          (RGE_Base_Game *this,uint param_1,long param_2,tagPOINT *param_3,int *param_4,int *param_5
          ,int *param_6,int *param_7)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0xffff;
  uVar2 = (uint)param_2 >> 0x10;
  param_3->x = uVar1;
  param_3->y = uVar2;
  if (60000 < uVar1) {
    param_3->x = uVar1 - 0x10000;
  }
  if (60000 < uVar2) {
    param_3->y = uVar2 - 0x10000;
  }
  *param_4 = param_1 & 1;
  *param_5 = param_1 & 2;
  *param_6 = param_1 & 8;
  *param_7 = param_1 & 4;
  return;
}

// --------------------------------------------------

// Function: get_mouse_pos
// Address: 004202e0
/* public: void __thiscall RGE_Base_Game::get_mouse_pos(struct tagPOINT &) */

void __thiscall RGE_Base_Game::get_mouse_pos(RGE_Base_Game *this,tagPOINT *param_1)
{
  GetCursorPos(param_1);
  if (this->prog_info->full_screen == 0) {
    ScreenToClient(this->prog_window,param_1);
    if (60000 < param_1->x) {
      param_1->x = param_1->x + -0x10000;
    }
    if (60000 < param_1->y) {
      param_1->y = param_1->y + -0x10000;
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_player
// Address: 00420330
/* public: class RGE_Player * __thiscall RGE_Base_Game::get_player(void) */

RGE_Player * __thiscall RGE_Base_Game::get_player(RGE_Base_Game *this)
{
  short sVar1;
  RGE_Player *pRVar2;
  
  pRVar2 = (RGE_Player *)this->world;
  if (pRVar2 == (RGE_Player *)0x0) {
    return pRVar2;
  }
  if (*(short *)&pRVar2->world == 0) {
    return (RGE_Player *)0x0;
  }
  sVar1 = *(short *)&(pRVar2->diam_tile_list).list;
  if (*(short *)&pRVar2->world <= sVar1) {
    return (RGE_Player *)0x0;
  }
  return (&pRVar2->doppleganger_creator->owner)[sVar1];
}

// --------------------------------------------------

// Function: draw_window
// Address: 00420360
/* public: void __thiscall RGE_Base_Game::draw_window(void) */

void __thiscall RGE_Base_Game::draw_window(RGE_Base_Game *this)
{
  UpdateWindow(this->prog_window);
  return;
}

// --------------------------------------------------

// Function: mouse_on
// Address: 00420370
/* public: void __thiscall RGE_Base_Game::mouse_on(void) */

void __thiscall RGE_Base_Game::mouse_on(RGE_Base_Game *this)
{
  if (this->is_mouse_on == 0) {
    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
      TMousePointer::on(this->mouse_pointer);
      this->is_mouse_on = 1;
      return;
    }
    SetCursor(this->mouse_cursor);
    SetClassLongA(this->prog_window,0xfffffff4,this->mouse_cursor);
    this->is_mouse_on = 1;
  }
  return;
}

// --------------------------------------------------

// Function: mouse_off
// Address: 004203e0
/* public: void __thiscall RGE_Base_Game::mouse_off(void) */

void __thiscall RGE_Base_Game::mouse_off(RGE_Base_Game *this)
{
  if (this->is_mouse_on != 0) {
    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
      TMousePointer::off(this->mouse_pointer);
      this->is_mouse_on = 0;
      return;
    }
    SetCursor(0);
    SetClassLongA(this->prog_window,0xfffffff4,0);
    this->is_mouse_on = 0;
  }
  return;
}

// --------------------------------------------------

// Function: set_windows_mouse
// Address: 00420440
/* public: void __thiscall RGE_Base_Game::set_windows_mouse(int) */

void __thiscall RGE_Base_Game::set_windows_mouse(RGE_Base_Game *this,int param_1)
{
  if (this->custom_mouse == 0) {
    this->windows_mouse = 1;
  }
  else {
    this->windows_mouse = param_1;
    if (this->windows_mouse == 0) {
      SetCursor(0);
      SetClassLongA(this->prog_window,0xfffffff4,0);
      if (this->is_mouse_on == 0) {
        TMousePointer::off(this->mouse_pointer);
        return;
      }
      TMousePointer::on(this->mouse_pointer);
      return;
    }
  }
  TMousePointer::off(this->mouse_pointer);
  if (this->is_mouse_on == 0) {
    SetCursor(0);
    SetClassLongA(this->prog_window,0xfffffff4,0);
    return;
  }
  SetCursor(this->mouse_cursor);
  SetClassLongA(this->prog_window,0xfffffff4,this->mouse_cursor);
  return;
}

// --------------------------------------------------

// Function: set_mouse_cursor
// Address: 00420500
/* public: void __thiscall RGE_Base_Game::set_mouse_cursor(void *) */

void __thiscall RGE_Base_Game::set_mouse_cursor(RGE_Base_Game *this,void *param_1)
{
  this->mouse_cursor = param_1;
  if (param_1 != (void *)0x0) {
    last_mouse_cursor = param_1;
  }
  if ((this->is_mouse_on != 0) && ((this->custom_mouse == 0 || (this->windows_mouse != 0)))) {
    SetCursor(this->mouse_cursor);
    SetClassLongA(this->prog_window,0xfffffff4,this->mouse_cursor);
  }
  return;
}

// --------------------------------------------------

// Function: set_mouse_facet
// Address: 00420560
/* public: void __thiscall RGE_Base_Game::set_mouse_facet(long) */

void __thiscall RGE_Base_Game::set_mouse_facet(RGE_Base_Game *this,long param_1)
{
  TMousePointer::set_facet(this->mouse_pointer,param_1);
  return;
}

// --------------------------------------------------

// Function: wnd_proc
// Address: 004206d0
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
/* WARNING: Variable defined which should be unmapped: mouse_down */
/* public: virtual long __stdcall RGE_Base_Game::wnd_proc(void *,unsigned int,unsigned int,long) */

long RGE_Base_Game::wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  bool bVar1;
  void *this;
  TPanel *pTVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int unaff_EDI;
  void *in_stack_00000014;
  int mouse_down;
  
  this = param_1;
  color_log('$','$',3);
  bVar1 = false;
  if ((0x200 < param_3) && (param_3 < 0x207)) {
    bVar1 = true;
    color_log('L','L',4);
  }
  if (*(TSound_Driver **)((int)param_1 + 0x60) != (TSound_Driver *)0x0) {
    TSound_Driver::handle_messages
              (*(TSound_Driver **)((int)param_1 + 0x60),(void *)param_2,param_3,param_4,
               (long)in_stack_00000014);
  }
  color_log('$','\x16',3);
  if (*(TMusic_System **)((int)param_1 + 100) != (TMusic_System *)0x0) {
    TMusic_System::handle_messages
              (*(TMusic_System **)((int)param_1 + 100),(void *)param_2,param_3,param_4,
               (long)in_stack_00000014);
  }
  color_log('$','L',3);
  param_1 = (void *)0x0;
  pTVar2 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar2 == (TPanel *)0x0) {
LAB_004207c2:
    color_log('$','E',3);
    iVar4 = debug_timeGetTime_on;
    if (param_3 < 6) {
      if (param_3 == 5) {
        if (system_ignore_size_messages != 0) goto LAB_00420f09;
        color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
        iVar3 = (**(code **)(*this + 0xe4))(param_2,5,param_4,in_stack_00000014);
        iVar4 = debug_timeGetTime_on;
        if (iVar3 != 0) goto LAB_00420f09;
        if (bVar1) {
          color_log('L','_',4);
          color_log('$','_',3);
          return (long)param_1;
        }
        goto LAB_00420e74;
      }
      if (param_3 != 2) goto LAB_00420f09;
      color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xf4))(param_2,2,param_4,in_stack_00000014);
joined_r0x00420d93:
      iVar4 = debug_timeGetTime_on;
      if (iVar3 != 0) goto LAB_00420f09;
LAB_00420e5e:
      if (bVar1) {
        color_log('L','_',4);
      }
      goto LAB_00420e74;
    }
    if (param_3 < 0x10) {
      if (param_3 != 0xf) {
        if ((param_3 == 6) && (*(int *)((int)this + 0x14) != 0)) {
          if ((param_4 & 0xffffU) == 0) {
            iVar4 = GetWindowThreadProcessId(*(undefined4 *)((int)this + 0x10),0);
            iVar3 = GetWindowThreadProcessId(in_stack_00000014,0);
            if (iVar3 == iVar4) {
              save_active_wnd = in_stack_00000014;
            }
          }
          iVar4 = debug_timeGetTime_on;
          if (((param_2 == *(uint *)((int)this + 0x10)) && ((param_4 & 0xffffU) != 0)) &&
             (((uint)param_4 >> 0x10 != 0 && (save_active_wnd != (void *)0x0)))) {
            save_active_wnd = (void *)0x0;
          }
        }
        goto LAB_00420f09;
      }
      color_log('2','E',3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xd4))(param_2,0xf,param_4,in_stack_00000014);
    }
    else if (param_3 < 0x1d) {
      if (param_3 != 0x1c) {
        if (param_3 != 0x10) goto LAB_00420f09;
LAB_00420dc9:
        color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
        iVar3 = (**(code **)(*this + 0xf0))(param_2,param_3,param_4,in_stack_00000014);
        iVar4 = debug_timeGetTime_on;
        if (iVar3 != 0) goto LAB_00420f09;
        if (bVar1) {
          color_log('L','_',4);
          color_log('$','_',3);
          return (long)param_1;
        }
        goto LAB_00420e74;
      }
      if (*(int *)((int)this + 0x14) != 0) {
        if (param_4 == 1) {
          if (DAT_0062c558 != 0) {
            SetCursor(0);
            SetClassLongA(*(undefined4 *)((int)this + 0x10),0xfffffff4,0);
            if (*(int *)((int)this + 0x1b0) != 1) {
                    /* WARNING: Load size is inaccurate */
              (**(code **)(*this + 0xa8))();
            }
            DAT_0062c558 = 0;
            if (*(TDrawSystem **)((int)this + 0x48) != (TDrawSystem *)0x0) {
              TDrawSystem::CheckSurfaces(*(TDrawSystem **)((int)this + 0x48));
              TDrawSystem::ClearRestored(*(TDrawSystem **)((int)this + 0x48));
              set_render_all((RGE_Base_Game *)this);
            }
            if (*(int *)((int)this + 0x1b0) != 1) {
              if (*(TDrawSystem **)((int)this + 0x48) != (TDrawSystem *)0x0) {
                TDrawSystem::ClearPrimarySurface(*(TDrawSystem **)((int)this + 0x48));
                TDrawSystem::ModifyPalette
                          (*(TDrawSystem **)((int)this + 0x48),0,0x100,
                           (*(TDrawSystem **)((int)this + 0x48))->palette);
              }
              set_render_all((RGE_Base_Game *)this);
              InvalidateRect(*(undefined4 *)((int)this + 0x10),0,1);
              do_restore_palette = 10;
              restore_palette_timer = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xe9b);
              restore_mouse_after_paint = 1;
            }
          }
        }
        else if (DAT_0062c558 == 0) {
          SetClassLongA(*(undefined4 *)((int)this + 0x10),0xfffffff4,0);
          if (*(int *)((int)this + 0x1b0) != 1) {
                    /* WARNING: Load size is inaccurate */
            (**(code **)(*this + 0xa4))();
          }
          DAT_0062c558 = 1;
          if ((*(int *)((int)this + 0x1b0) != 1) &&
             (*(TMousePointer **)((int)this + 0x1c0) != (TMousePointer *)0x0)) {
            TMousePointer::Shutdown_Mouse(*(TMousePointer **)((int)this + 0x1c0));
          }
        }
      }
      color_log('2','T',3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xd8))(param_2,0x1c,param_4,in_stack_00000014);
    }
    else if (param_3 < 0x105) {
      if (param_3 == 0x104) {
        color_log('$',0xba,3);
                    /* WARNING: Load size is inaccurate */
        iVar3 = (**(code **)(*this + 0xc4))(param_2,0x104,param_4,in_stack_00000014);
      }
      else {
        if (param_3 != 0x100) goto LAB_00420f09;
        color_log('$',0xba,3);
                    /* WARNING: Load size is inaccurate */
        iVar3 = (**(code **)(*this + 0xc4))(param_2,0x100,param_4,in_stack_00000014);
      }
    }
    else if (param_3 < 0x112) {
      if (param_3 != 0x111) {
        if (((param_3 == 0x105) && (param_4 == 0x12)) &&
           (pTVar2 = TPanelSystem::currentPanel(&panel_system), iVar4 = debug_timeGetTime_on,
           pTVar2 != (TPanel *)0x0)) {
          pTVar2 = TPanelSystem::currentPanel(&panel_system);
          (**(code **)(pTVar2->_padding_ + 0xdc))();
          iVar4 = debug_timeGetTime_on;
        }
        goto LAB_00420f09;
      }
      color_log('2','\x16',3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xcc))(param_2,0x111,param_4,in_stack_00000014);
    }
    else if (param_3 < 0x201) {
      if (param_3 == 0x200) {
        color_log('$','T',3);
                    /* WARNING: Load size is inaccurate */
        iVar4 = (**(code **)(*this + 0xc0))(param_2,0x200,param_4,in_stack_00000014);
        if (iVar4 != 0) {
          iVar4 = debug_timeGetTime_on;
          if (MouseCursorInChildContol != 0) {
            if (*(int *)((int)this + 0x1d0) == 0) {
              SetCursor(0);
              SetClassLongA(*(undefined4 *)((int)this + 0x10),0xfffffff4,0);
              mouse_on((RGE_Base_Game *)this);
              MouseCursorInChildContol = 0;
              iVar4 = debug_timeGetTime_on;
            }
            else {
              SetCursor(*(undefined4 *)((int)this + 0x1d4));
              MouseCursorInChildContol = 0;
              iVar4 = debug_timeGetTime_on;
            }
          }
          goto LAB_00420f09;
        }
        goto LAB_00420d04;
      }
      if (param_3 == 0x112) {
        if (((param_4 == 0xf100) && (*(int *)(*(int *)((int)this + 0xc) + 0x894) != 0)) &&
           (iVar3 = IsIconic(*(undefined4 *)((int)this + 0x10)), iVar4 = debug_timeGetTime_on,
           iVar3 == 0)) {
          return 0;
        }
        goto LAB_00420f09;
      }
      if (param_3 == 0x113) {
                    /* WARNING: Load size is inaccurate */
        (**(code **)(*this + 0xbc))();
        iVar4 = debug_timeGetTime_on;
        goto LAB_00420f09;
      }
      if (param_3 != 0x116) goto LAB_00420f09;
      color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xdc))(param_2,0x116,param_4,in_stack_00000014);
    }
    else {
      if (0x218 < param_3) {
        if (0x3b9 < param_3) {
          if (param_3 == 0x400) {
            color_log('2','$',3);
            iVar4 = debug_timeGetTime_on;
                    /* WARNING: Load size is inaccurate */
            debug_timeGetTime_on = 0;
            iVar3 = (**(code **)(*this + 200))(param_2,0x400,param_4,in_stack_00000014);
            if (iVar3 == 0) {
              if (bVar1) {
                color_log('L','_',4);
              }
              color_log('$','_',3);
              debug_timeGetTime_on = iVar4;
              return (long)param_1;
            }
            goto LAB_00420f09;
          }
          if (param_3 != 0x500) goto LAB_00420f09;
LAB_00420e36:
          color_log('2','L',3);
                    /* WARNING: Load size is inaccurate */
          iVar3 = (**(code **)(*this + 0xd0))(param_2,param_3,param_4,in_stack_00000014);
          goto joined_r0x00420d93;
        }
        if (param_3 == 0x3b9) goto LAB_00420e36;
        if (param_3 != 0x30f) {
          if (param_3 != 0x311) goto LAB_00420f09;
          color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
          iVar3 = (**(code **)(*this + 0xe8))(param_2,0x311,param_4,in_stack_00000014);
          goto joined_r0x00420d93;
        }
        color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
        iVar4 = (**(code **)(*this + 0xec))(param_2,0x30f,param_4,in_stack_00000014);
        if (iVar4 != 0) goto LAB_00420dc9;
        goto LAB_00420e5e;
      }
      if (param_3 == 0x218) {
        if (param_4 == 0) {
          return 0x424d5144;
        }
        goto LAB_00420f09;
      }
      if (param_3 != 0x212) goto LAB_00420f09;
      color_log('2',0xba,3);
                    /* WARNING: Load size is inaccurate */
      iVar3 = (**(code **)(*this + 0xe0))(param_2,0x212,param_4,in_stack_00000014);
    }
    iVar4 = debug_timeGetTime_on;
    if (iVar3 != 0) {
LAB_00420f09:
      debug_timeGetTime_on = iVar4;
      color_log('T','$',3);
      lVar5 = DefWindowProcA(param_2,param_3,param_4,in_stack_00000014);
      if (unaff_EDI != 0) {
        color_log('L','_',4);
      }
      color_log('$','_',3);
      return lVar5;
    }
  }
  else {
    color_log('$','2',3);
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    param_1 = (void *)(**(code **)(pTVar2->_padding_ + 0x48))
                                (param_2,param_3,param_4,in_stack_00000014);
    if (((param_1 == (void *)0x0) || (param_3 == 0x200)) || (param_3 == 0x113)) goto LAB_004207c2;
  }
LAB_00420d04:
  if (bVar1) {
    color_log('L','_',4);
    color_log('$','_',3);
    return (long)param_1;
  }
LAB_00420e74:
  color_log('$','_',3);
  return (long)param_1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00420f60
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
/* protected: virtual int __thiscall RGE_Base_Game::handle_idle(void) */

int __thiscall RGE_Base_Game::handle_idle(RGE_Base_Game *this)
{
  TDrawSystem *this_00;
  ulong uVar1;
  TPanel *pTVar2;
  int iVar3;
  uint uVar4;
  
  if ((this->prog_ready != 0) && (this->prog_window != (void *)0x0)) {
    color_log('\x16','\x16',2);
    if ((do_restore_palette != 0) && (this->prog_active != 0)) {
      uVar4 = 0xfa;
      if (5 < do_restore_palette) {
        uVar4 = 500;
      }
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xf9a);
      if (uVar4 <= uVar1 - restore_palette_timer) {
        this_00 = this->draw_system;
        if (this_00 != (TDrawSystem *)0x0) {
          TDrawSystem::ModifyPalette(this_00,0,0x100,this_00->palette);
        }
                    /* language.dll match for 0xfa4: "No" */
        do_restore_palette = do_restore_palette + -1;
        restore_palette_timer = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xfa4);
      }
    }
    color_log('2','2',5);
    if (this->sound_system != (TSound_Driver *)0x0) {
      color_log('\x16',0xba,2);
      TSound_Driver::handle_messages(this->sound_system,this->prog_window,0x113,0,0);
    }
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar2 != (TPanel *)0x0) {
      color_log('\x16','E',2);
      pTVar2 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar2->_padding_ + 0x4c))();
    }
    if (this->comm_handler != (TCommunications_Handler *)0x0) {
      iVar3 = multiplayerGame(this);
      if (iVar3 != 0) {
        color_log('E','E',1);
        TCommunications_Handler::ReceiveGameMessages(this->comm_handler);
        color_log('E','_',1);
      }
    }
    if (this->do_show_comm != 0) {
      color_log('\x16','2',2);
      (**(code **)(this->_padding_ + 0x134))();
    }
    if (this->do_show_ai != 0) {
      color_log('\x16','$',2);
      (**(code **)(this->_padding_ + 0x138))();
    }
    color_log('2','_',5);
    color_log('\x16','_',2);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_mouse_move
// Address: 00421110
/* WARNING: Variable defined which should be unmapped: shift_key */
/* protected: virtual int __thiscall RGE_Base_Game::handle_mouse_move(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_mouse_move
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  int shift_key;
  int ctrl_key;
  int right_btn;
  int left_btn;
  tagPOINT point;
  undefined4 local_4;
  
  if (this->prog_ready == 0) {
    return 1;
  }
  if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
    iVar1 = TMousePointer::in_game_mode(this->mouse_pointer);
    if (iVar1 == 0) {
      TMousePointer::draw(this->mouse_pointer,0);
    }
    else {
      TMousePointer::Poll(this->mouse_pointer);
    }
  }
  get_mouse_info(this,param_3,param_4,(tagPOINT *)&point.y,&point.x,&left_btn,&right_btn,&ctrl_key);
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0xfc))(point.y,local_4,point.x,left_btn,right_btn,ctrl_key);
  (**(code **)(iVar1 + 0xbc))();
  return 1;
}

// --------------------------------------------------

// Function: handle_key_down
// Address: 004211d0
// [HELPER] s___AoE_04d_bmp: ".\AoE%04d.bmp"
/* protected: virtual int __thiscall RGE_Base_Game::handle_key_down(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_key_down
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  short sVar1;
  int iVar2;
  
  if (this->prog_ready == 0) {
    return 1;
  }
  DAT_005b2370 = param_4 & 0xffff;
  DAT_005b2368 = param_3;
  sVar1 = GetKeyState(0x11);
  DAT_0062c4bc = (uint)(sVar1 < 0);
  sVar1 = GetKeyState(0x12);
  DAT_0062c4b4 = (uint)(sVar1 < 0);
  sVar1 = GetKeyState(0x10);
  DAT_005b2164 = (uint)(sVar1 < 0);
  if (((((param_1 == this->prog_window) && (param_2 == 0x104)) &&
       ((DAT_005b2368 == 0x12 || ((DAT_005b2368 == 0x20 || (DAT_005b2368 == 0x79)))))) &&
      (this->prog_info->full_screen != 0)) && (iVar2 = IsIconic(this->prog_window), iVar2 == 0)) {
    return 0;
  }
  if ((DAT_0062c4bc != 0) && (DAT_005b2368 == 0x7b)) {
    TDrawArea::take_snapshot(this->draw_system->DrawArea,s___AoE_04d_bmp,&snapshot_number);
    return 0;
  }
  iVar2 = (**(code **)(this->_padding_ + 0x100))
                    (DAT_005b2368,DAT_005b2370,DAT_0062c4bc,DAT_0062c4b4,DAT_005b2164);
  return (uint)(iVar2 != 0);
}

// --------------------------------------------------

// Function: handle_user_command
// Address: 004212e0
/* protected: virtual int __thiscall RGE_Base_Game::handle_user_command(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_user_command
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = TCommunications_Handler::MultiplayerGameStart(this->comm_handler);
  if ((iVar1 != 0) && (out_of_sync == 0)) {
    if (param_3 == 0x17b3) {
      iVar1 = playerID(this,param_4);
      uVar2 = 1;
      iVar1 = this->world->players[iVar1]->_padding_;
    }
    else {
      if (param_3 != 0x17b4) goto LAB_00421350;
      iVar1 = playerID(this,param_4);
      uVar2 = 0;
      iVar1 = this->world->players[iVar1]->_padding_;
    }
    (**(code **)(iVar1 + 0xd4))(param_4,uVar2);
  }
LAB_00421350:
  if (param_3 == 0x17a2) {
    if (this->world != (RGE_Game_World *)0x0) {
      (**(code **)(this->world->_padding_ + 0xec))(1);
    }
  }
  else if ((param_3 == 0x17a3) && (this->world != (RGE_Game_World *)0x0)) {
    (**(code **)(this->world->_padding_ + 0xec))(0);
  }
  iVar1 = (**(code **)(this->_padding_ + 0x104))(param_3,param_4);
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: handle_command
// Address: 004213a0
/* protected: virtual int __thiscall RGE_Base_Game::handle_command(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_command
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x108))(param_3,param_4);
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: handle_music_done
// Address: 004213c0
/* protected: virtual int __thiscall RGE_Base_Game::handle_music_done(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_music_done
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x10c))();
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: handle_paint
// Address: 004213e0
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
/* protected: virtual int __thiscall RGE_Base_Game::handle_paint(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_paint
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  IDirectDrawSurface *pIVar1;
  TSound_Driver *this_00;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  TPanel *pTVar6;
  ulong uVar7;
  undefined4 unaff_ESI;
  
  color_log('2','2',4);
                    /* language.dll match for 0x10ea: "Score" */
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10ea);
  iVar3 = check_paint(this);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10ee);
  add_to_timing(this,5,uVar4 - uVar2);
  if (iVar3 == 0) {
    color_log('2','_',4);
    return 0;
  }
  iVar3 = this->prog_mode;
  if (((((iVar3 == 4) || (iVar3 == 6)) || (iVar3 == 7)) &&
      ((this->draw_system->DrawType != '\x01' && (this->custom_mouse != 0)))) &&
     (this->mouse_blit_sync != 0)) {
    pIVar1 = this->draw_system->PrimarySurface;
    iVar3 = (**(code **)((int)*pIVar1 + 0x34))(pIVar1,1);
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10fc);
    do {
      if (iVar3 != -0x7789fde4) goto LAB_004214dc;
      pIVar1 = this->draw_system->PrimarySurface;
      iVar3 = (**(code **)((int)*pIVar1 + 0x34))(pIVar1,1);
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1100);
    } while (uVar4 <= uVar2 + 100);
    this->mouse_blit_sync = 0;
  }
LAB_004214dc:
  color_log('2',0xba,4);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x110c);
  this_00 = rge_base_game->sound_system;
  if (this_00 != (TSound_Driver *)0x0) {
    TSound_Driver::play_list(this_00);
    TSound_Driver::reset_play_list(this_00);
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1115);
  add_to_timing(this,10,uVar4 - uVar2);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x111c);
  if (this->erase_mouse != 0) {
    color_log('2','L',4);
    if ((this->render_all == 0) && (this->custom_mouse != 0)) {
      TMousePointer::erase(this->mouse_pointer);
    }
    this->erase_mouse = 0;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1127);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x112a);
  color_log('2','\x16',4);
  pTVar6 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar6 == (TPanel *)0x0) {
    clear_window(this);
  }
  else {
    color_log('\x16','\x16',1);
    if (this->render_all != 0) {
      pTVar6 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar6->_padding_ + 0x20))(2);
    }
    pTVar6 = TPanelSystem::currentPanel(&panel_system);
    (**(code **)(pTVar6->_padding_ + 0x54))();
    color_log('\x16','_',1);
  }
  color_log('2','$',4);
  if (DAT_0062c57c != 0) {
    DAT_0062c57c = 0;
    if (((this->prog_mode == 4) || (this->prog_mode == 5)) && (this->do_show_timings != 0)) {
      (**(code **)(this->_padding_ + 0x130))();
    }
  }
                    /* language.dll match for 0x1147: "Nebuchad"
                       language.dll match for 0x1147: "Hammurabi II" */
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1147);
  add_to_timing(this,2,uVar7 - uVar5);
                    /* language.dll match for 0x114b: "Croesus"
                       language.dll match for 0x114b: "Hammurabi IV" */
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x114b);
  color_log('2','T',4);
  if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
    TMousePointer::draw(this->mouse_pointer,1);
    this->erase_mouse = 1;
  }
                    /* language.dll match for 0x115b: "Sarpedon"
                       language.dll match for 0x115b: "Minos II" */
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x115b);
  add_to_timing(this,8,(uVar4 - uVar2) + (uVar7 - uVar5));
                    /* language.dll match for 0x1160: "Pasiphae" */
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1160);
  color_log('2','E',4);
  TDrawSystem::Paint(this->draw_system,(tagRECT *)0x0);
  ValidateRect(this->prog_window,0);
  ValidateRect(this->prog_window,0);
                    /* language.dll match for 0x1176: "9"
                       language.dll match for 0x1176: "7" */
  this->render_all = 0;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1176);
  add_to_timing(this,3,uVar4 - uVar2);
  color_log('2','_',4);
                    /* language.dll match for 0x1182: "Darius" */
  this->frame_count = this->frame_count + 1;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1182);
  if (999 < uVar2 - DAT_0062c578) {
    (**(code **)(this->_padding_ + 0x128))();
    DAT_0062c57c = 1;
    DAT_0062c578 = uVar2;
  }
  if (restore_mouse_after_paint != 0) {
    if (this->mouse_pointer != (TMousePointer *)0x0) {
      TMousePointer::Restore_Mouse(this->mouse_pointer,this->draw_area);
      if (this->is_mouse_on != 0) {
        if ((this->custom_mouse == 0) || (this->windows_mouse != 0)) {
          SetCursor(this->mouse_cursor);
          SetClassLongA(this->prog_window,0xfffffff4,this->mouse_cursor);
        }
        else {
          TMousePointer::on(this->mouse_pointer);
          TMousePointer::draw(this->mouse_pointer,1);
        }
      }
      InvalidateRect(unaff_ESI,0,0);
    }
    restore_mouse_after_paint = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: handle_activate
// Address: 00421830
/* protected: virtual int __thiscall RGE_Base_Game::handle_activate(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_activate
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  TPanel *pTVar1;
  int iVar2;
  
  if (param_3 == 0) {
    this->prog_active = 0;
  }
  else {
    this->prog_active = 1;
  }
  iVar2 = this->prog_mode;
  if (this->prog_active != 0) {
    if ((((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) && (this->auto_paused == 1)) {
      this->auto_paused = 0;
      set_paused(this,0,0);
    }
    pTVar1 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar1 != (TPanel *)0x0) {
      pTVar1 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar1->_padding_ + 0xdc))();
    }
    (**(code **)(this->_padding_ + 0x110))();
    return 1;
  }
  if (((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) {
    iVar2 = singlePlayerGame(this);
    if (iVar2 == 1) {
      iVar2 = get_paused(this);
      if (iVar2 == 0) {
        this->auto_paused = 1;
        set_paused(this,1,0);
      }
    }
  }
  (**(code **)(this->_padding_ + 0x114))();
  return 1;
}

// --------------------------------------------------

// Function: handle_init_menu
// Address: 00421910
/* protected: virtual int __thiscall RGE_Base_Game::handle_init_menu(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_init_menu
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x118))();
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: handle_exit_menu
// Address: 00421930
/* protected: virtual int __thiscall RGE_Base_Game::handle_exit_menu(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_exit_menu
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x11c))();
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: handle_size
// Address: 00421950
/* protected: virtual int __thiscall RGE_Base_Game::handle_size(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_size(RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  TPanel *pTVar2;
  
  if (param_3 == 1) {
    return param_3;
  }
  if (this->draw_system != (TDrawSystem *)0x0) {
    TDrawSystem::HandleSize(this->draw_system,param_1,param_2,param_3,param_4);
    if ((this->draw_system != (TDrawSystem *)0x0) &&
       (iVar1 = this->draw_system->ScreenWidth, iVar1 != 0)) {
      this->prog_info->main_wid = iVar1;
      this->prog_info->main_hgt = this->draw_system->ScreenHeight;
    }
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar2 != (TPanel *)0x0) {
      pTVar2 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar2->_padding_ + 0x50))(this->prog_info->main_wid,this->prog_info->main_hgt);
    }
  }
  (**(code **)(this->_padding_ + 0x120))();
  return 1;
}

// --------------------------------------------------

// Function: handle_palette_changed
// Address: 004219f0
/* protected: virtual int __thiscall RGE_Base_Game::handle_palette_changed(void *,unsigned
   int,unsigned int,long) */

int __thiscall
RGE_Base_Game::handle_palette_changed
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  TDrawSystem *this_00;
  
  if (this->draw_system != (TDrawSystem *)0x0) {
    TDrawSystem::HandlePaletteChanged(this->draw_system,param_1,param_2,param_3,param_4);
  }
  if ((void *)param_3 != param_1) {
    this_00 = this->draw_system;
    if (((this_00->DrawType == '\x01') || (this_00->ScreenMode == '\x01')) ||
       (this_00 == (TDrawSystem *)0x0)) {
      (**(code **)(this->_padding_ + 0xec))(param_1,param_2,param_3,param_4);
    }
    else if (this->prog_mode != 1) {
      TDrawSystem::ModifyPalette(this_00,0,0x100,this_00->palette);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: handle_query_new_palette
// Address: 00421a80
/* protected: virtual int __thiscall RGE_Base_Game::handle_query_new_palette(void *,unsigned
   int,unsigned int,long) */

int __thiscall
RGE_Base_Game::handle_query_new_palette
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  TDrawSystem *pTVar1;
  int iVar2;
  undefined4 uVar3;
  TPanel *pTVar4;
  TEasy_Panel *this_00;
  void *pvVar5;
  uint unaff_EBX;
  uint unaff_retaddr;
  undefined4 uVar6;
  
  pTVar1 = this->draw_system;
  if (((pTVar1 != (TDrawSystem *)0x0) && (pTVar1->DrawType != '\x01')) &&
     (pTVar1->ScreenMode != '\x01')) {
    InvalidateRect(param_1,0,0);
    iVar2 = TDrawSystem::HandleQueryNewPalette
                      (this->draw_system,param_1,unaff_EBX,unaff_retaddr,(long)param_1);
    return iVar2;
  }
  uVar3 = GetDC(param_1);
  pTVar4 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar4 == (TPanel *)0x0) {
    pvVar5 = this->prog_palette;
    if (pvVar5 == (void *)0x0) goto LAB_00421b1b;
    uVar6 = 0;
  }
  else {
    this_00 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
    pvVar5 = TEasy_Panel::get_palette(this_00);
    if (pvVar5 == (void *)0x0) goto LAB_00421b1b;
    uVar6 = 0;
    pvVar5 = TEasy_Panel::get_palette(this_00);
  }
  SelectPalette(uVar3,pvVar5,uVar6);
LAB_00421b1b:
  iVar2 = RealizePalette(uVar3);
  ReleaseDC(param_1,uVar3);
  if (iVar2 != 0) {
    InvalidateRect(param_1,0,0);
  }
  if (this->draw_system != (TDrawSystem *)0x0) {
    iVar2 = TDrawSystem::HandleQueryNewPalette(this->draw_system,param_1,param_2,param_3,param_4);
    return iVar2;
  }
  return 1;
}

// --------------------------------------------------

// Function: handle_close
// Address: 00421b70
/* protected: virtual int __thiscall RGE_Base_Game::handle_close(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_close
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x124))();
  if (iVar1 == 0) {
    return 0;
  }
  if ((this->draw_area != (TDrawArea *)0x0) && (this->draw_system != (TDrawSystem *)0x0)) {
    TDrawArea::Clear(this->draw_area,(tagRECT *)0x0,0);
    TDrawSystem::Paint(this->draw_system,(tagRECT *)0x0);
  }
  return 1;
}

// --------------------------------------------------

// Function: handle_destroy
// Address: 00421bb0
/* protected: virtual int __thiscall RGE_Base_Game::handle_destroy(void *,unsigned int,unsigned
   int,long) */

int __thiscall
RGE_Base_Game::handle_destroy
          (RGE_Base_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  this->prog_ready = 0;
  if (this->is_timer != 0) {
    KillTimer(this->prog_window,1);
  }
  this->prog_window = (void *)0x0;
  PostQuitMessage(0);
  return 1;
}

// --------------------------------------------------

// Function: calc_timings
// Address: 00421bf0
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
// [HELPER] s__lu___ld___ld___ld___ld___d___d_: "%lu, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %..."
/* protected: virtual void __thiscall RGE_Base_Game::calc_timings(void) */

void __thiscall RGE_Base_Game::calc_timings(RGE_Base_Game *this)
{
  ulong uVar1;
  RGE_Player *pRVar2;
  ulonglong uVar3;
  ulong uVar4;
  uint uVar5;
  RGE_Player **ppRVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  RGE_Timing_Info *pRVar10;
  int iVar11;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar7 = 0;
  pRVar10 = this->timings;
  iVar9 = 0x1e;
  do {
    if (pRVar10->is_summary == 0) {
      pRVar10->last_time = pRVar10->accum_time;
      pRVar10->last_max_time = pRVar10->max_time;
      pRVar10->accum_time = 0;
      pRVar10->max_time = 0;
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12b5);
      pRVar10->start_time = uVar4;
      if (pRVar10->include_in_total != 0) {
        uVar7 = uVar7 + pRVar10->last_time;
      }
    }
    pRVar10 = pRVar10 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (this->timings[0].start_time == 0) {
    this->timings[0].last_time = uVar7;
  }
  else {
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12be);
    this->timings[0].last_time = uVar4 - this->timings[0].start_time;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12c1);
  uVar5 = this->timings[0].last_time;
  this->timings[0].start_time = uVar4;
  if (uVar7 < uVar5) {
    this->timings[4].last_time = uVar5 - uVar7;
  }
  else {
    this->timings[4].last_time = 0;
  }
  uVar4 = this->timings[6].last_time;
  uVar1 = this->timings[7].last_time;
  uVar7 = this->timings[2].last_time;
  if (uVar1 + uVar4 < uVar7) {
    this->timings[9].last_time = (uVar7 - uVar4) - uVar1;
  }
  else {
    this->timings[9].last_time = 0;
  }
  if (((uVar5 == 0) || (this->frame_count == 0)) ||
     (uVar3 = (ulonglong)uVar5 / (ulonglong)this->frame_count, (int)uVar3 == 0)) {
    this->fps = 1000;
  }
  else {
    this->fps = (ulong)(1000 / uVar3);
  }
  if (((uVar5 == 0) || (this->view_update_count == 0)) ||
     (uVar3 = (ulonglong)uVar5 / (ulonglong)this->view_update_count, (int)uVar3 == 0)) {
    this->view_update_fps = 0;
  }
  else {
    this->view_update_fps = (ulong)(1000 / uVar3);
  }
  if (((uVar5 == 0) || (this->world_update_count == 0)) ||
     (uVar3 = (ulonglong)uVar5 / (ulonglong)this->world_update_count, (int)uVar3 == 0)) {
    this->world_update_fps = 0;
  }
  else {
    this->world_update_fps = (ulong)(1000 / uVar3);
  }
  (**(code **)(this->_padding_ + 300))();
  if ((do_fps_log != 0) && (this->prog_mode == 4)) {
    iVar11 = 0;
    iVar8 = 0;
    iVar9 = (int)this->world->player_num;
    if (1 < iVar9) {
      ppRVar6 = this->world->players;
      iVar9 = iVar9 + -1;
      do {
        ppRVar6 = ppRVar6 + 1;
        iVar11 = iVar11 + (*ppRVar6)->objects->number_of_objects;
        iVar8 = iVar8 + (*ppRVar6)->sleeping_objects->number_of_objects;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    uVar7 = this->world_update_count;
    if (uVar7 == 0) {
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_c = 0;
      uStack_8 = 0;
      uStack_4 = 0;
      uVar5 = 0;
    }
    else {
      uStack_18 = this->timings[4].last_time / uVar7;
      uStack_14 = this->timings[0xd].last_time / uVar7;
      uStack_10 = (this->timings[10].last_time + this->timings[0xc].last_time) / uVar7;
      uStack_c = this->timings[1].last_time / uVar7;
      uStack_8 = this->timings[3].last_time / uVar7;
      uStack_4 = this->timings[7].last_time / uVar7;
      uVar5 = this->timings[6].last_time / uVar7;
    }
    pRVar2 = *this->world->players;
    fprintf(fps_log,s__lu___ld___ld___ld___ld___d___d_,this->world->world_time,start_mem_total,
            start_mem_high,cur_mem_total,cur_mem_high,(int)pRVar2->objects->number_of_objects,
            (int)pRVar2->sleeping_objects->number_of_objects,iVar11,iVar8,uVar7,
            this->view_update_count,this->world_update_fps,this->view_update_fps,uVar5,
            this->timings[6].last_max_time,uStack_4,this->timings[7].last_max_time,uStack_8,
            this->timings[3].last_max_time,uStack_c,this->timings[1].last_max_time,uStack_10,
            this->timings[10].last_max_time + this->timings[0xc].last_max_time,uStack_14,
            this->timings[0xd].last_max_time,uStack_18,this->timings[4].last_max_time,0,0xffffffff,
            0xffffffff);
    fflush(fps_log);
  }
  this->last_frame_count = this->frame_count;
  this->last_world_update_count = this->world_update_count;
  this->last_view_update_count = this->view_update_count;
  this->frame_count = 0;
  this->world_update_count = 0;
  this->view_update_count = 0;
  return;
}

// --------------------------------------------------

// Function: calc_timing_text
// Address: 00421fa0
// [HELPER] s_fps__lu__rend__lu__view__lu__map: "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, upd=%lu, snd=%lu, misc=%lu, ot..."
/* protected: virtual void __thiscall RGE_Base_Game::calc_timing_text(void) */

void __thiscall RGE_Base_Game::calc_timing_text(RGE_Base_Game *this)
{
  ulong uVar1;
  
  uVar1 = this->frame_count;
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  sprintf(this->timing_text,s_fps__lu__rend__lu__view__lu__map,this->fps,
          this->timings[2].last_time / uVar1,this->timings[6].last_time / uVar1,
          this->timings[7].last_time / uVar1,this->timings[3].last_time / uVar1,
          this->timings[1].last_time / uVar1,this->timings[10].last_time / uVar1,
          this->timings[0xd].last_time / uVar1,this->timings[4].last_time / uVar1,
          this->timings[0].last_time / uVar1);
  return;
}

// --------------------------------------------------

// Function: show_timings
// Address: 00422030
/* protected: virtual void __thiscall RGE_Base_Game::show_timings(void) */

void __thiscall RGE_Base_Game::show_timings(RGE_Base_Game *this)
{
  SetWindowTextA(this->prog_window,this->timing_text);
  return;
}

// --------------------------------------------------

// Function: show_comm
// Address: 00422050
// [HELPER] s__s: "%s"
/* WARNING: Variable defined which should be unmapped: str */
/* protected: virtual void __thiscall RGE_Base_Game::show_comm(void) */

void __thiscall RGE_Base_Game::show_comm(RGE_Base_Game *this)
{
  char *pcVar1;
  char str [256];
  
  pcVar1 = TCommunications_Handler::GetCommInfo(this->comm_handler,'\x01');
  sprintf(str + 4,s__s,pcVar1);
  SetWindowTextA(this->prog_window,str + 4);
  return;
}

// --------------------------------------------------

// Function: show_ai
// Address: 00422090
// [HELPER] s_No_AI_Information_for_Player___d: "No AI Information for Player #%d."
/* WARNING: Variable defined which should be unmapped: str */
/* protected: virtual void __thiscall RGE_Base_Game::show_ai(void) */

void __thiscall RGE_Base_Game::show_ai(RGE_Base_Game *this)
{
  char str [256];
  
  sprintf(str + 4,s_No_AI_Information_for_Player___d,(int)this->world->curr_player);
  SetWindowTextA(this->prog_window,str + 4);
  return;
}

// --------------------------------------------------

// Function: send_game_options
// Address: 004220d0
/* public: virtual void __thiscall RGE_Base_Game::send_game_options(void) */

void __thiscall RGE_Base_Game::send_game_options(RGE_Base_Game *this)
{
  if (this->comm_handler != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::SetMyGameOptions
              (this->comm_handler,(char *)&this->rge_game_options,0xa8);
  }
  return;
}

// --------------------------------------------------

// Function: receive_game_options
// Address: 004220f0
/* WARNING: Variable defined which should be unmapped: size */
/* public: virtual void __thiscall RGE_Base_Game::receive_game_options(void) */

void __thiscall RGE_Base_Game::receive_game_options(RGE_Base_Game *this)
{
  RGE_Game_Options *pRVar1;
  ulong size;
  ulong local_4;
  
  if (this->comm_handler != (TCommunications_Handler *)0x0) {
    local_4 = 0;
    pRVar1 = (RGE_Game_Options *)
             TCommunications_Handler::GetMyGameOptions(this->comm_handler,&local_4);
    if ((pRVar1 != (RGE_Game_Options *)0x0) && (local_4 == 0xa8)) {
      set_game_options(this,pRVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_game_options
// Address: 00422130
/* public: void __thiscall RGE_Base_Game::set_game_options(struct RGE_Base_Game::RGE_Game_Options *)
    */

void __thiscall RGE_Base_Game::set_game_options(RGE_Base_Game *this,RGE_Game_Options *param_1)
{
  int iVar1;
  
  setVersion(this,param_1->versionValue);
  setScenarioGame(this,(uint)param_1->scenarioGameValue);
  setScenarioName(this,param_1->scenarioNameValue);
  setSinglePlayerGame(this,(uint)param_1->singlePlayerGameValue);
  setMultiplayerGame(this,(uint)param_1->multiplayerGameValue);
  setMapSize(this,(uint)param_1->mapXSizeValue,(uint)param_1->mapYSizeValue,
             (uint)param_1->mapZSizeValue);
  setAllowCheatCodes(this,(uint)param_1->allowCheatCodesValue);
  setCheatNotification(this,(uint)param_1->cheatNotificationValue);
  setFullVisibility(this,(uint)param_1->fullVisibilityValue);
  setFogOfWar(this,(uint)param_1->fogOfWarValue);
  setColoredChat(this,(uint)param_1->coloredChatValue);
  setNumberPlayers(this,(uint)param_1->numberPlayersValue);
  setGameDeveloperMode(this,(uint)param_1->gameDeveloperModeValue);
  setDifficulty(this,(uint)param_1->difficultyValue);
  setMpPathFinding(this,param_1->mpPathFindingValue);
  iVar1 = 0;
  do {
    setPlayerCDAndVersion(this,iVar1,param_1->playerCDAndVersionValue[iVar1]);
    setPlayerTeam(this,iVar1,(uint)param_1->playerTeamValue[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}

// --------------------------------------------------

// Function: get_game_options
// Address: 00422260
/* public: void __thiscall RGE_Base_Game::get_game_options(struct RGE_Base_Game::RGE_Game_Options *)
    */

void __thiscall RGE_Base_Game::get_game_options(RGE_Base_Game *this,RGE_Game_Options *param_1)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  float fVar9;
  
  fVar9 = version(this);
  param_1->versionValue = fVar9;
  iVar3 = scenarioGame(this);
  param_1->scenarioGameValue = (uchar)iVar3;
  pcVar4 = scenarioName(this);
  uVar6 = 0xffffffff;
  do {
    pcVar8 = pcVar4;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar4 = pcVar8 + -uVar6;
  pcVar8 = param_1->scenarioNameValue;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar3 = singlePlayerGame(this);
  param_1->singlePlayerGameValue = (uchar)iVar3;
  iVar3 = multiplayerGame(this);
  param_1->multiplayerGameValue = (uchar)iVar3;
  iVar3 = mapXSize(this);
  param_1->mapXSizeValue = (uchar)iVar3;
  iVar3 = mapYSize(this);
  param_1->mapYSizeValue = (uchar)iVar3;
  iVar3 = mapZSize(this);
  param_1->mapZSizeValue = (uchar)iVar3;
  iVar3 = allowCheatCodes(this);
  param_1->allowCheatCodesValue = (uchar)iVar3;
  iVar3 = cheatNotification(this);
  param_1->cheatNotificationValue = (uchar)iVar3;
  iVar3 = fullVisibility(this);
  param_1->fullVisibilityValue = (uchar)iVar3;
  iVar3 = fogOfWar(this);
  param_1->fogOfWarValue = (uchar)iVar3;
  iVar3 = coloredChat(this);
  param_1->coloredChatValue = (uchar)iVar3;
  iVar3 = numberPlayers(this);
  param_1->numberPlayersValue = (uchar)iVar3;
  iVar3 = gameDeveloperMode(this);
  param_1->gameDeveloperModeValue = (uchar)iVar3;
  iVar3 = difficulty(this);
  param_1->difficultyValue = (uchar)iVar3;
  uVar2 = mpPathFinding(this);
  param_1->mpPathFindingValue = uVar2;
  iVar3 = 0;
  do {
    uVar2 = playerCDAndVersion(this,iVar3);
    param_1->playerCDAndVersionValue[iVar3] = uVar2;
    iVar5 = playerTeam(this,iVar3);
    param_1->playerTeamValue[iVar3] = (uchar)iVar5;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  return;
}

// --------------------------------------------------

// Function: version
// Address: 00422390
/* public: float __thiscall RGE_Base_Game::version(void)const  */

float __thiscall RGE_Base_Game::version(RGE_Base_Game *this)
{
  return (this->rge_game_options).versionValue;
}

// --------------------------------------------------

// Function: scenarioGame
// Address: 004223a0
/* public: int __thiscall RGE_Base_Game::scenarioGame(void)const  */

int __thiscall RGE_Base_Game::scenarioGame(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).scenarioGameValue;
}

// --------------------------------------------------

// Function: randomGame
// Address: 004223b0
/* public: int __thiscall RGE_Base_Game::randomGame(void)const  */

int __thiscall RGE_Base_Game::randomGame(RGE_Base_Game *this)
{
  return (uint)((this->rge_game_options).scenarioGameValue == '\0');
}

// --------------------------------------------------

// Function: campaignGame
// Address: 004223c0
/* public: int __thiscall RGE_Base_Game::campaignGame(void)const  */

int __thiscall RGE_Base_Game::campaignGame(RGE_Base_Game *this)
{
  return this->campaignGameValue;
}

// --------------------------------------------------

// Function: savedGame
// Address: 004223d0
/* public: int __thiscall RGE_Base_Game::savedGame(void)const  */

int __thiscall RGE_Base_Game::savedGame(RGE_Base_Game *this)
{
  return this->savedGameValue;
}

// --------------------------------------------------

// Function: scenarioName
// Address: 004223e0
/* public: char * __thiscall RGE_Base_Game::scenarioName(void) */

char * __thiscall RGE_Base_Game::scenarioName(RGE_Base_Game *this)
{
  return (this->rge_game_options).scenarioNameValue;
}

// --------------------------------------------------

// Function: singlePlayerGame
// Address: 004223f0
/* public: int __thiscall RGE_Base_Game::singlePlayerGame(void)const  */

int __thiscall RGE_Base_Game::singlePlayerGame(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).singlePlayerGameValue;
}

// --------------------------------------------------

// Function: multiplayerGame
// Address: 00422400
/* public: int __thiscall RGE_Base_Game::multiplayerGame(void)const  */

int __thiscall RGE_Base_Game::multiplayerGame(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).multiplayerGameValue;
}

// --------------------------------------------------

// Function: mapXSize
// Address: 00422410
/* public: int __thiscall RGE_Base_Game::mapXSize(void)const  */

int __thiscall RGE_Base_Game::mapXSize(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).mapXSizeValue;
}

// --------------------------------------------------

// Function: mapYSize
// Address: 00422420
/* public: int __thiscall RGE_Base_Game::mapYSize(void)const  */

int __thiscall RGE_Base_Game::mapYSize(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).mapYSizeValue;
}

// --------------------------------------------------

// Function: mapZSize
// Address: 00422430
/* public: int __thiscall RGE_Base_Game::mapZSize(void)const  */

int __thiscall RGE_Base_Game::mapZSize(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).mapZSizeValue;
}

// --------------------------------------------------

// Function: allowCheatCodes
// Address: 00422440
/* public: int __thiscall RGE_Base_Game::allowCheatCodes(void)const  */

int __thiscall RGE_Base_Game::allowCheatCodes(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).allowCheatCodesValue;
}

// --------------------------------------------------

// Function: cheatNotification
// Address: 00422450
/* public: int __thiscall RGE_Base_Game::cheatNotification(void)const  */

int __thiscall RGE_Base_Game::cheatNotification(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).cheatNotificationValue;
}

// --------------------------------------------------

// Function: fullVisibility
// Address: 00422460
/* public: int __thiscall RGE_Base_Game::fullVisibility(void)const  */

int __thiscall RGE_Base_Game::fullVisibility(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).fullVisibilityValue;
}

// --------------------------------------------------

// Function: fogOfWar
// Address: 00422470
/* public: int __thiscall RGE_Base_Game::fogOfWar(void)const  */

int __thiscall RGE_Base_Game::fogOfWar(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).fogOfWarValue;
}

// --------------------------------------------------

// Function: coloredChat
// Address: 00422480
/* public: int __thiscall RGE_Base_Game::coloredChat(void)const  */

int __thiscall RGE_Base_Game::coloredChat(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).coloredChatValue;
}

// --------------------------------------------------

// Function: gameDeveloperMode
// Address: 00422490
/* public: int __thiscall RGE_Base_Game::gameDeveloperMode(void)const  */

int __thiscall RGE_Base_Game::gameDeveloperMode(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).gameDeveloperModeValue;
}

// --------------------------------------------------

// Function: playerHasCD
// Address: 004224a0
/* public: int __thiscall RGE_Base_Game::playerHasCD(int) */

int __thiscall RGE_Base_Game::playerHasCD(RGE_Base_Game *this,int param_1)
{
  return (this->rge_game_options).playerCDAndVersionValue[param_1] & 1;
}

// --------------------------------------------------

// Function: playerVersion
// Address: 004224c0
/* public: unsigned char __thiscall RGE_Base_Game::playerVersion(int) */

uchar __thiscall RGE_Base_Game::playerVersion(RGE_Base_Game *this,int param_1)
{
  return (this->rge_game_options).playerCDAndVersionValue[param_1] >> 1;
}

// --------------------------------------------------

// Function: playerVersionString
// Address: 004224e0
// [HELPER] s_1_0: "1.0"
// [HELPER] s_1_0a: "1.0a"
// [HELPER] s_1_0b: "1.0b"
// [HELPER] s_1_0c: "1.0c"
// [HELPER] s_1_0d: "1.0d"
// [HELPER] s_1_0e: "1.0e"
// [HELPER] s_1_1: "1.1"
// [HELPER] s_1_1a: "1.1a"
// [HELPER] s_1_1b: "1.1b"
// [HELPER] s_1_1c: "1.1c"
// [HELPER] s_1_2: "1.2"
// [HELPER] s_1_2a: "1.2a"
// [HELPER] s_1_2b: "1.2b"
// [HELPER] s_1_2c: "1.2c"
// [HELPER] s_1_3: "1.3"
// [HELPER] s_1_3a: "1.3a"
// [HELPER] s_1_3b: "1.3b"
// [HELPER] s_1_3c: "1.3c"
// [HELPER] s_1_4: "1.4"
// [HELPER] s_1_4a: "1.4a"
// [HELPER] s_1_4b: "1.4b"
// [HELPER] s_1_4c: "1.4c"
// [HELPER] s_1_X: "1.X"
// [HELPER] s_: ""
/* public: char * __thiscall RGE_Base_Game::playerVersionString(int) */

char * __thiscall RGE_Base_Game::playerVersionString(RGE_Base_Game *this,int param_1)
{
  uchar uVar1;
  
  uVar1 = playerVersion(this,param_1);
  switch(uVar1) {
  case '\0':
    return s_;
  case '\x01':
    return s_1_0;
  case '\x02':
    return s_1_0a;
  case '\x03':
    return s_1_0b;
  case '\x04':
    return s_1_0c;
  case '\x05':
    return s_1_0d;
  case '\x06':
    return s_1_0e;
  case '\a':
    return s_1_1;
  case '\b':
    return s_1_1a;
  case '\t':
    return s_1_1b;
  case '\n':
    return s_1_1c;
  case '\v':
    return s_1_2;
  case '\f':
    return s_1_2a;
  case '\r':
    return s_1_2b;
  case '\x0e':
    return s_1_2c;
  case '\x0f':
    return s_1_3;
  case '\x10':
    return s_1_3a;
  case '\x11':
    return s_1_3b;
  case '\x12':
    return s_1_3c;
  case '\x13':
    return s_1_4;
  case '\x14':
    return s_1_4a;
  case '\x15':
    return s_1_4b;
  case '\x16':
    return s_1_4c;
  default:
    return s_1_X;
  }
}

// --------------------------------------------------

// Function: playerCDAndVersion
// Address: 00422630
/* public: unsigned char __thiscall RGE_Base_Game::playerCDAndVersion(int) */

uchar __thiscall RGE_Base_Game::playerCDAndVersion(RGE_Base_Game *this,int param_1)
{
  return (this->rge_game_options).playerCDAndVersionValue[param_1];
}

// --------------------------------------------------

// Function: difficulty
// Address: 00422640
/* public: int __thiscall RGE_Base_Game::difficulty(void) */

int __thiscall RGE_Base_Game::difficulty(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).difficultyValue;
}

// --------------------------------------------------

// Function: numberPlayers
// Address: 00422650
/* public: int __thiscall RGE_Base_Game::numberPlayers(void)const  */

int __thiscall RGE_Base_Game::numberPlayers(RGE_Base_Game *this)
{
  return (uint)(this->rge_game_options).numberPlayersValue;
}

// --------------------------------------------------

// Function: playerTeam
// Address: 00422660
/* public: int __thiscall RGE_Base_Game::playerTeam(int) */

int __thiscall RGE_Base_Game::playerTeam(RGE_Base_Game *this,int param_1)
{
  return (uint)(this->rge_game_options).playerTeamValue[param_1];
}

// --------------------------------------------------

// Function: pathFinding
// Address: 00422670
/* public: unsigned char __thiscall RGE_Base_Game::pathFinding(void) */

uchar __thiscall RGE_Base_Game::pathFinding(RGE_Base_Game *this)
{
  return this->pathFindingValue;
}

// --------------------------------------------------

// Function: mpPathFinding
// Address: 00422680
/* public: unsigned char __thiscall RGE_Base_Game::mpPathFinding(void) */

uchar __thiscall RGE_Base_Game::mpPathFinding(RGE_Base_Game *this)
{
  return (this->rge_game_options).mpPathFindingValue;
}

// --------------------------------------------------

// Function: gameSummary
// Address: 00422690
/* public: virtual char * __thiscall RGE_Base_Game::gameSummary(void) */

char * __thiscall RGE_Base_Game::gameSummary(RGE_Base_Game *this)
{
  DAT_0062c49c._0_1_ = 0;
  return (char *)&DAT_0062c49c;
}

// --------------------------------------------------

// Function: find_campaigns
// Address: 004226a0
/* public: void __thiscall RGE_Base_Game::find_campaigns(void) */

void __thiscall RGE_Base_Game::find_campaigns(RGE_Base_Game *this)
{
  RGE_Game_Info::find_campaigns(this->player_game_info);
  return;
}

// --------------------------------------------------

// Function: setScenarioGame
// Address: 004226b0
/* public: void __thiscall RGE_Base_Game::setScenarioGame(int) */

void __thiscall RGE_Base_Game::setScenarioGame(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).scenarioGameValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setVersion
// Address: 004226c0
/* public: void __thiscall RGE_Base_Game::setVersion(float) */

void __thiscall RGE_Base_Game::setVersion(RGE_Base_Game *this,float param_1)
{
  (this->rge_game_options).versionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setScenarioName
// Address: 004226d0
/* public: void __thiscall RGE_Base_Game::setScenarioName(char *) */

void __thiscall RGE_Base_Game::setScenarioName(RGE_Base_Game *this,char *param_1)
{
                    /* language.dll match for 0x80: "Arial" */
  strncpy((this->rge_game_options).scenarioNameValue,param_1,0x80);
  (this->rge_game_options).scenarioNameValue[0x7f] = '\0';
  return;
}

// --------------------------------------------------

// Function: setCampaignGame
// Address: 00422700
/* public: void __thiscall RGE_Base_Game::setCampaignGame(int) */

void __thiscall RGE_Base_Game::setCampaignGame(RGE_Base_Game *this,int param_1)
{
  this->campaignGameValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setSavedGame
// Address: 00422710
/* public: void __thiscall RGE_Base_Game::setSavedGame(int) */

void __thiscall RGE_Base_Game::setSavedGame(RGE_Base_Game *this,int param_1)
{
  this->savedGameValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setSinglePlayerGame
// Address: 00422720
/* public: void __thiscall RGE_Base_Game::setSinglePlayerGame(int) */

void __thiscall RGE_Base_Game::setSinglePlayerGame(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).singlePlayerGameValue = (uchar)param_1;
  (this->rge_game_options).multiplayerGameValue = param_1 == 0;
  return;
}

// --------------------------------------------------

// Function: setMultiplayerGame
// Address: 00422740
/* public: void __thiscall RGE_Base_Game::setMultiplayerGame(int) */

void __thiscall RGE_Base_Game::setMultiplayerGame(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).multiplayerGameValue = (uchar)param_1;
  (this->rge_game_options).singlePlayerGameValue = param_1 == 0;
  return;
}

// --------------------------------------------------

// Function: setMapSize
// Address: 00422760
/* public: void __thiscall RGE_Base_Game::setMapSize(int,int,int) */

void __thiscall RGE_Base_Game::setMapSize(RGE_Base_Game *this,int param_1,int param_2,int param_3)
{
  (this->rge_game_options).mapXSizeValue = (uchar)param_1;
  (this->rge_game_options).mapYSizeValue = (uchar)param_2;
  (this->rge_game_options).mapZSizeValue = (uchar)param_3;
  return;
}

// --------------------------------------------------

// Function: setAllowCheatCodes
// Address: 00422790
/* public: void __thiscall RGE_Base_Game::setAllowCheatCodes(int) */

void __thiscall RGE_Base_Game::setAllowCheatCodes(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).allowCheatCodesValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setCheatNotification
// Address: 004227a0
/* public: void __thiscall RGE_Base_Game::setCheatNotification(int) */

void __thiscall RGE_Base_Game::setCheatNotification(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).cheatNotificationValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setFullVisibility
// Address: 004227b0
/* public: void __thiscall RGE_Base_Game::setFullVisibility(int) */

void __thiscall RGE_Base_Game::setFullVisibility(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).fullVisibilityValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setFogOfWar
// Address: 004227c0
/* public: void __thiscall RGE_Base_Game::setFogOfWar(int) */

void __thiscall RGE_Base_Game::setFogOfWar(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).fogOfWarValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setColoredChat
// Address: 004227d0
/* public: void __thiscall RGE_Base_Game::setColoredChat(int) */

void __thiscall RGE_Base_Game::setColoredChat(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).coloredChatValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setNumberPlayers
// Address: 004227e0
/* public: void __thiscall RGE_Base_Game::setNumberPlayers(int) */

void __thiscall RGE_Base_Game::setNumberPlayers(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).numberPlayersValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setGameDeveloperMode
// Address: 004227f0
/* public: void __thiscall RGE_Base_Game::setGameDeveloperMode(int) */

void __thiscall RGE_Base_Game::setGameDeveloperMode(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).gameDeveloperModeValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setPlayerHasCD
// Address: 00422800
/* public: void __thiscall RGE_Base_Game::setPlayerHasCD(int,int) */

void __thiscall RGE_Base_Game::setPlayerHasCD(RGE_Base_Game *this,int param_1,int param_2)
{
  (this->rge_game_options).playerCDAndVersionValue[param_1] =
       (this->rge_game_options).playerCDAndVersionValue[param_1] & 0xfe | (byte)param_2;
  return;
}

// --------------------------------------------------

// Function: setPlayerVersion
// Address: 00422820
/* public: void __thiscall RGE_Base_Game::setPlayerVersion(int,unsigned char) */

void __thiscall RGE_Base_Game::setPlayerVersion(RGE_Base_Game *this,int param_1,uchar param_2)
{
  (this->rge_game_options).playerCDAndVersionValue[param_1] =
       param_2 << 1 | (this->rge_game_options).playerCDAndVersionValue[param_1] & 1;
  return;
}

// --------------------------------------------------

// Function: setPlayerCDAndVersion
// Address: 00422850
/* public: void __thiscall RGE_Base_Game::setPlayerCDAndVersion(int,unsigned char) */

void __thiscall RGE_Base_Game::setPlayerCDAndVersion(RGE_Base_Game *this,int param_1,uchar param_2)
{
  (this->rge_game_options).playerCDAndVersionValue[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: setDifficulty
// Address: 00422870
/* public: void __thiscall RGE_Base_Game::setDifficulty(int) */

void __thiscall RGE_Base_Game::setDifficulty(RGE_Base_Game *this,int param_1)
{
  (this->rge_game_options).difficultyValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setPlayerTeam
// Address: 00422880
/* public: void __thiscall RGE_Base_Game::setPlayerTeam(int,int) */

void __thiscall RGE_Base_Game::setPlayerTeam(RGE_Base_Game *this,int param_1,int param_2)
{
  (this->rge_game_options).playerTeamValue[param_1] = (uchar)param_2;
  return;
}

// --------------------------------------------------

// Function: setPathFinding
// Address: 004228a0
/* public: void __thiscall RGE_Base_Game::setPathFinding(unsigned char) */

void __thiscall RGE_Base_Game::setPathFinding(RGE_Base_Game *this,uchar param_1)
{
  this->pathFindingValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setMpPathFinding
// Address: 004228b0
/* public: void __thiscall RGE_Base_Game::setMpPathFinding(unsigned char) */

void __thiscall RGE_Base_Game::setMpPathFinding(RGE_Base_Game *this,uchar param_1)
{
  (this->rge_game_options).mpPathFindingValue = param_1;
  return;
}

// --------------------------------------------------

// Function: set_map_visible
// Address: 004228c0
/* public: void __thiscall RGE_Base_Game::set_map_visible(unsigned char) */

void __thiscall RGE_Base_Game::set_map_visible(RGE_Base_Game *this,uchar param_1)
{
  if (this->world != (RGE_Game_World *)0x0) {
    RGE_Game_World::set_map_visible(this->world,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: set_map_fog
// Address: 004228e0
/* public: void __thiscall RGE_Base_Game::set_map_fog(unsigned char) */

void __thiscall RGE_Base_Game::set_map_fog(RGE_Base_Game *this,uchar param_1)
{
  if (this->world != (RGE_Game_World *)0x0) {
    RGE_Game_World::set_map_fog(this->world,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: turn_world_sound_off
// Address: 00422900
/* public: void __thiscall RGE_Base_Game::turn_world_sound_off(void) */

void __thiscall RGE_Base_Game::turn_world_sound_off(RGE_Base_Game *this)
{
                    /* WARNING: Could not recover jumptable at 0x00422908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(this->world->_padding_ + 0xb4))();
  return;
}

// --------------------------------------------------

// Function: campaign_open_scenario
// Address: 00422910
/* public: int __thiscall RGE_Base_Game::campaign_open_scenario(void) */

int __thiscall RGE_Base_Game::campaign_open_scenario(RGE_Base_Game *this)
{
  int iVar1;
  
  iVar1 = RGE_Game_Info::open_scenario(this->player_game_info);
  return iVar1;
}

// --------------------------------------------------

// Function: GetChecksum
// Address: 00422920
/* public: long __thiscall RGE_Base_Game::GetChecksum(long) */

long __thiscall RGE_Base_Game::GetChecksum(RGE_Base_Game *this,long param_1)
{
  RGE_Game_World *pRVar1;
  long lVar2;
  
  pRVar1 = this->world;
  if (pRVar1 != (RGE_Game_World *)0x0) {
    if (param_1 < 0) {
      lVar2 = RGE_Player::get_checksum(pRVar1->players[pRVar1->curr_player]);
      return lVar2;
    }
    if (param_1 < pRVar1->player_num) {
      lVar2 = RGE_Player::get_checksum(pRVar1->players[param_1]);
      return lVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: GetWorldChecksums
// Address: 00422960
/* WARNING: Variable defined which should be unmapped: checksum1 */
/* public: unsigned char __thiscall RGE_Base_Game::GetWorldChecksums(long &,long &,long &) */

uchar __thiscall
RGE_Base_Game::GetWorldChecksums(RGE_Base_Game *this,long *param_1,long *param_2,long *param_3)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  long checksum1;
  long checksum2;
  long checksum3;
  long local_8;
  RGE_Base_Game *local_4;
  
  iVar2 = 0;
  checksum2 = 0;
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  pRVar1 = this->world;
  checksum3 = 0;
  local_8 = 0;
  if (pRVar1 != (RGE_Game_World *)0x0) {
    local_4 = this;
    if (0 < pRVar1->player_num) {
      do {
        RGE_Player::get_checksums(pRVar1->players[iVar2],&checksum2,&checksum3,&local_8);
        *param_1 = *param_1 + checksum2;
        *param_2 = *param_2 + checksum3;
        iVar2 = iVar2 + 1;
        *param_3 = *param_3 + local_8;
        pRVar1 = local_4->world;
      } while (iVar2 < pRVar1->player_num);
    }
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: GetWorldChecksum
// Address: 00422a10
/* public: long __thiscall RGE_Base_Game::GetWorldChecksum(void) */

long __thiscall RGE_Base_Game::GetWorldChecksum(RGE_Base_Game *this)
{
  RGE_Game_World *pRVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = 0;
  pRVar1 = this->world;
  if (pRVar1 != (RGE_Game_World *)0x0) {
    iVar4 = 0;
    if (0 < pRVar1->player_num) {
      do {
        lVar2 = RGE_Player::get_checksum(pRVar1->players[iVar4]);
        lVar3 = lVar3 + lVar2;
        pRVar1 = this->world;
        iVar4 = iVar4 + 1;
      } while (iVar4 < pRVar1->player_num);
    }
    return lVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: disable_input
// Address: 00422a50
/* public: void __thiscall RGE_Base_Game::disable_input(void) */

void __thiscall RGE_Base_Game::disable_input(RGE_Base_Game *this)
{
  void *pvVar1;
  int iVar2;
  
  if (this->is_mouse_on != 0) {
    pvVar1 = (void *)LoadCursorA(0,0x7f02);
    set_mouse_cursor(this,pvVar1);
  }
  TPanelSystem::DisableInput(&panel_system);
  this->input_enabled = 0;
  if (this->input_disabled_window != (void *)0x0) {
    iVar2 = GetCapture();
    if (iVar2 != 0) {
      ReleaseCapture();
    }
    SetCapture(this->input_disabled_window);
  }
  return;
}

// --------------------------------------------------

// Function: enable_input
// Address: 00422ab0
/* public: void __thiscall RGE_Base_Game::enable_input(void) */

void __thiscall RGE_Base_Game::enable_input(RGE_Base_Game *this)
{
  int iVar1;
  void *pvVar2;
  
  if (this->input_disabled_window != (void *)0x0) {
    iVar1 = GetCapture();
    if (iVar1 != 0) {
      ReleaseCapture();
    }
  }
  TPanelSystem::EnableInput(&panel_system);
  this->input_enabled = 1;
  if (this->is_mouse_on != 0) {
    pvVar2 = (void *)LoadCursorA(0,0x7f00);
    set_mouse_cursor(this,pvVar2);
  }
  return;
}

// --------------------------------------------------

// Function: set_screen_size
// Address: 00422b10
// [HELPER] s_DISPLAY: "DISPLAY"
/* WARNING: Variable defined which should be unmapped: win_rect */
/* public: void __thiscall RGE_Base_Game::set_screen_size(long,long) */

void __thiscall RGE_Base_Game::set_screen_size(RGE_Base_Game *this,long param_1,long param_2)
{
  int iVar1;
  long lStack_58;
  long lStack_54;
  int iStack_50;
  void *pvStack_4c;
  int iStack_48;
  int iStack_44;
  char *pcVar2;
  int iVar3;
  tagRECT win_rect;
  tagRECT client_rect;
  
  if ((this->draw_area->Width != param_1) || (this->draw_area->Height != param_2)) {
    if ((this->draw_system->DrawType == '\x02') && (this->draw_system->ScreenMode == '\x02')) {
      SetCursor();
      iStack_44 = 0x422b5d;
      SetClassLongA();
      TMousePointer::Shutdown_Mouse(this->mouse_pointer);
      iStack_44 = 0x422b74;
      TDrawSystem::SetDisplaySize(this->draw_system,param_1,param_2,8);
      TDrawSystem::CheckSurfaces(this->draw_system);
      TDrawSystem::ClearRestored(this->draw_system);
      set_render_all(this);
      restore_mouse_after_paint = 1;
      return;
    }
    iVar3 = 0;
    pcVar2 = s_DISPLAY;
    iStack_44 = 0x422bb7;
    iVar1 = CreateICA();
    if (iVar1 != 0) {
      iStack_44 = 8;
      pvStack_4c = (void *)0x422bc6;
      iStack_48 = iVar1;
      client_rect.right = GetDeviceCaps();
      iStack_44 = 10;
      pvStack_4c = (void *)0x422bd3;
      iStack_48 = iVar1;
      client_rect.bottom = GetDeviceCaps();
      iStack_48 = 0x422bde;
      iStack_44 = iVar1;
      DeleteDC();
    }
    if ((param_1 <= client_rect.right) && (param_2 <= client_rect.bottom)) {
      if ((client_rect.right == param_1) && (client_rect.bottom == param_2)) {
        pvStack_4c = this->prog_window;
        iStack_44 = 0x92080000;
        iStack_48 = -0x10;
        this->window_style = -0x6df80000;
        iStack_50 = 0x422c18;
        SetWindowLongA();
        iStack_44 = this->window_style;
        iStack_48 = -0x14;
      }
      else {
        pvStack_4c = this->prog_window;
        iStack_44 = 0x12ca0000;
        iStack_48 = -0x14;
        this->window_style = 0x12ca0000;
        iStack_50 = 0x422c3a;
        SetWindowLongA();
        iStack_44 = this->window_style;
        iStack_48 = -0x10;
      }
      pvStack_4c = this->prog_window;
      iStack_50 = 0x422c46;
      SetWindowLongA();
      iStack_50 = 0;
      lStack_54 = param_2;
      lStack_58 = param_1;
      SetWindowPos(this->prog_window,0,0,0);
      GetWindowRect(this->prog_window,&lStack_58);
      GetClientRect(this->prog_window,&iStack_48);
      if ((pcVar2 != (char *)param_1) || (iVar3 != param_2)) {
        SetWindowPos(this->prog_window,0,lStack_58,lStack_54,
                     ((param_1 + iStack_50) - lStack_58) - (int)pcVar2,
                     (int)pvStack_4c + ((param_2 - lStack_54) - iVar3),0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: check_prog_argument
// Address: 00422cc0
/* public: unsigned char __thiscall RGE_Base_Game::check_prog_argument(char *) */

uchar __thiscall RGE_Base_Game::check_prog_argument(RGE_Base_Game *this,char *param_1)
{
  int iVar1;
  undefined4 unaff_retaddr;
  char cmd_line [256];
  
  cmd_line[0] = -1;
  cmd_line[1] = '\0';
  cmd_line[2] = '\0';
  cmd_line[3] = '\0';
  strncpy(cmd_line + 4,this->prog_info->cmd_line);
  cmd_line._0_4_ = cmd_line + 4;
  CharUpperA();
  iVar1 = strstr(cmd_line,unaff_retaddr);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: get_scenario_checksum
// Address: 00422d20
/* public: long __thiscall RGE_Base_Game::get_scenario_checksum(char *) */

long __thiscall RGE_Base_Game::get_scenario_checksum(RGE_Base_Game *this,char *param_1)
{
  ulong uVar1;
  RGE_Scenario_Header *this_00;
  
  this_00 = get_scenario_header(this,param_1,0);
  if (this_00 == (RGE_Scenario_Header *)0x0) {
    return 0;
  }
  uVar1 = this_00->checksum;
  RGE_Scenario_Header::~RGE_Scenario_Header(this_00);
  operator_delete(this_00);
  return uVar1;
}

// --------------------------------------------------

// Function: check_scenario_checksum
// Address: 00422d60
/* public: unsigned char __thiscall RGE_Base_Game::check_scenario_checksum(char *,long) */

uchar __thiscall
RGE_Base_Game::check_scenario_checksum(RGE_Base_Game *this,char *param_1,long param_2)
{
  long lVar1;
  
  lVar1 = get_scenario_checksum(this,param_1);
  if ((lVar1 != 0) && (lVar1 == param_2)) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: dump_memory_usage
// Address: 00422d80
/* public: void __thiscall RGE_Base_Game::dump_memory_usage(char *) */

void __thiscall RGE_Base_Game::dump_memory_usage(RGE_Base_Game *this,char *param_1)
{
  return;
}

// --------------------------------------------------

// Function: playerID
// Address: 00422d90
/* public: int __thiscall RGE_Base_Game::playerID(int) */

int __thiscall RGE_Base_Game::playerID(RGE_Base_Game *this,int param_1)
{
  return this->playerIDValue[param_1];
}

// --------------------------------------------------

// Function: setPlayerID
// Address: 00422da0
/* public: void __thiscall RGE_Base_Game::setPlayerID(int,int) */

void __thiscall RGE_Base_Game::setPlayerID(RGE_Base_Game *this,int param_1,int param_2)
{
  this->playerIDValue[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: reset_countdown_timer
// Address: 00422dc0
/* public: void __thiscall RGE_Base_Game::reset_countdown_timer(long) */

void __thiscall RGE_Base_Game::reset_countdown_timer(RGE_Base_Game *this,long param_1)
{
  this->countdown_timer[param_1] = -1;
  return;
}

// --------------------------------------------------

// Function: set_countdown_timer
// Address: 00422de0
/* public: void __thiscall RGE_Base_Game::set_countdown_timer(long,long) */

void __thiscall RGE_Base_Game::set_countdown_timer(RGE_Base_Game *this,long param_1,long param_2)
{
  if ((param_2 < this->countdown_timer[param_1]) || (this->countdown_timer[param_1] < 0)) {
    this->countdown_timer[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: get_countdown_timer
// Address: 00422e10
/* public: void __thiscall RGE_Base_Game::get_countdown_timer(long,long &) */

void __thiscall RGE_Base_Game::get_countdown_timer(RGE_Base_Game *this,long param_1,long *param_2)
{
  *param_2 = this->countdown_timer[param_1];
  return;
}

// --------------------------------------------------

// Function: play_video
// Address: 00422e30
/* public: int __thiscall RGE_Base_Game::play_video(char *) */

int __thiscall RGE_Base_Game::play_video(RGE_Base_Game *this,char *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: close_video
// Address: 00422e40
/* public: void __thiscall RGE_Base_Game::close_video(void) */

void __thiscall RGE_Base_Game::close_video(RGE_Base_Game *this)
{
  return;
}

// --------------------------------------------------

// Function: handle_video_notify
// Address: 00422e50
/* public: void __thiscall RGE_Base_Game::handle_video_notify(void) */

void __thiscall RGE_Base_Game::handle_video_notify(RGE_Base_Game *this)
{
  return;
}

// --------------------------------------------------

// Function: play_sound
// Address: 00422e60
/* public: int __thiscall RGE_Base_Game::play_sound(int) */

int __thiscall RGE_Base_Game::play_sound(RGE_Base_Game *this,int param_1)
{
  TDigital **ppTVar1;
  int iVar2;
  
  ppTVar1 = this->sounds;
  if (ppTVar1 == (TDigital **)0x0) {
    return (int)ppTVar1;
  }
  if (ppTVar1[param_1] == (TDigital *)0x0) {
    return 0;
  }
  iVar2 = TDigital::is_playing(ppTVar1[param_1]);
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = TDigital::play(this->sounds[param_1]);
  return iVar2;
}

// --------------------------------------------------

// Function: get_game_speed
// Address: 00422eb0
/* public: float __thiscall RGE_Base_Game::get_game_speed(void) */

float __thiscall RGE_Base_Game::get_game_speed(RGE_Base_Game *this)
{
  return this->game_speed;
}

// --------------------------------------------------

// Function: set_game_speed
// Address: 00422ec0
/* public: void __thiscall RGE_Base_Game::set_game_speed(float) */

void __thiscall RGE_Base_Game::set_game_speed(RGE_Base_Game *this,float param_1)
{
  this->game_speed = param_1;
  return;
}

// --------------------------------------------------

// Function: get_single_player_difficulty
// Address: 00422ed0
/* public: int __thiscall RGE_Base_Game::get_single_player_difficulty(void) */

int __thiscall RGE_Base_Game::get_single_player_difficulty(RGE_Base_Game *this)
{
  return this->single_player_difficulty;
}

// --------------------------------------------------

// Function: set_single_player_difficulty
// Address: 00422ee0
/* public: void __thiscall RGE_Base_Game::set_single_player_difficulty(int) */

void __thiscall RGE_Base_Game::set_single_player_difficulty(RGE_Base_Game *this,int param_1)
{
  this->single_player_difficulty = param_1;
  return;
}

// --------------------------------------------------

// Function: setup_map_save_area
// Address: 00422ef0
// [HELPER] s_Diamond_Map_Save_Area: "Diamond Map Save Area"
/* protected: virtual int __thiscall RGE_Base_Game::setup_map_save_area(void) */

int __thiscall RGE_Base_Game::setup_map_save_area(RGE_Base_Game *this)
{
  TDrawArea *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cc1b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TDrawArea *)operator_new(0x100);
  local_4 = 0;
  if (pTVar1 == (TDrawArea *)0x0) {
    pTVar1 = (TDrawArea *)0x0;
  }
  else {
    pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Diamond_Map_Save_Area,0);
  }
  local_4 = 0xffffffff;
  this->map_save_area = pTVar1;
  if (pTVar1 == (TDrawArea *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  iVar2 = TDrawArea::Init(pTVar1,this->draw_system,0x118,0x8c,0,0);
  if (iVar2 == 0) {
    pTVar1 = this->map_save_area;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
    }
    this->map_save_area = (TDrawArea *)0x0;
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: reload_scenarios_info
// Address: 00422fd0
/* public: void __thiscall RGE_Base_Game::reload_scenarios_info(void) */

void __thiscall RGE_Base_Game::reload_scenarios_info(RGE_Base_Game *this)
{
  RGE_Scenario_File_Info::reload_scenarios(this->scenario_info);
  return;
}

// --------------------------------------------------

// Function: set_interface_messages
// Address: 00422fe0
/* protected: virtual void __thiscall RGE_Base_Game::set_interface_messages(void) */

void __thiscall RGE_Base_Game::set_interface_messages(RGE_Base_Game *this)
{
  return;
}

// --------------------------------------------------

// Function: set_render_all
// Address: 00422ff0
/* public: void __thiscall RGE_Base_Game::set_render_all(void) */

void __thiscall RGE_Base_Game::set_render_all(RGE_Base_Game *this)
{
  this->render_all = 1;
  TPanelSystem::set_restore(&panel_system);
  return;
}

// --------------------------------------------------

