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

typedef unsigned char uchar;

class RGE_Base_Game;
class TShape;

extern RGE_Base_Game* rge_base_game;

class TPanel;
class TRIBE_Screen_Sed;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Scenario;
class T_Scenario;

enum ScenarioMode {
    ScenarioModeNone = 0,
    ScenarioModeMap = 1,
    ScenarioModeTerrain = 2,
    ScenarioModePlayers = 3,
    ScenarioModeUnits = 4,
    ScenarioModeDiplomacy = 5,
    ScenarioModeVictory = 6,
    ScenarioModeVictoryMulti = 7,
    ScenarioModeOptions = 8,
    ScenarioModeMessages = 9,
    ScenarioModeCinematics = 10,
    ScenarioModeSave = 11
};

struct tagRECT { long left, top, right, bottom; };

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int active);      // +0x14
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int flags);       // +0x20
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);     // +0x50
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    char gap_00[0x10];
    int pnl_wid;                              // +0x14
    int pnl_hgt;                              // +0x18
    char gap_1C[0xF4 - 0x1C];
    void set_curr_child(TPanel* child);
    void set_help_info(int id, int page);
};

class TEasy_Panel : public TPanel {
public:
    char pad_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {};

class TTextPanel : public TPanel {};
class TEditPanel : public TTextPanel {
public:
    char* get_input_buffer();                 // 00475B00
    void set_text(char* text);                // 00475970
};
class TListPanel : public TTextPanel {
public:
    int currentLineNumber();                  // 0047DC50
};
class TDropDownPanel : public TTextPanel {
public:
    long get_line();                          // 00475380
    long get_line(char* text);                // 004753C0
    char* currentLine();                      // 004751C0
    void set_line(long line);                 // 00475250
    void setCurrentLineNumber(long line);     // 00475150
    int append_line(char* text, int data);    // 004752A0
};
class TButtonPanel : public TPanel {
public:
    void set_radio_button();                  // 00472690
    virtual void set_option(int v);           // +0xE0
};

class RGE_Diamond_Map_View : public TPanel {};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;  // +0x24
    char gap_28[0x4A - 0x28];
    short id;                                   // +0x4A
    void unselect_object();                     // 00470E30
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int a, int b);   // +0x10
    char gap_04[0x1B4 - 0x04];
    int game_mode;                              // +0x1B4
    char gap_1B8[0x3FC - 0x1B8];
    short master_obj_id;                        // +0x3FC
    RGE_Player* get_player();                   // 00420330
};

class RGE_Scenario {
public:
    char* Get_message(long id);                 // 0048CE40
    void Set_message(char* text, long field_index); // 0048CD10
    char* Get_Cine_PreGame();                   // 0048BC80
    char* Get_Cine_Victory();                   // 0048BC90
    char* Get_Cine_Loss();                      // 0048BCA0
    char* Get_Mission_Bmp();                    // 0048BCB0
    void Set_Cine_PreGame(char* text);          // 0048B960
    void Set_Cine_Victory(char* text);          // 0048B9A0
    void Set_Cine_Loss(char* text);             // 0048B9E0
    void Set_Mission_Bmp(char* text);           // 0048BA20
};

class T_Scenario : public RGE_Scenario {
public:
    int GetPlayerAge(int idx);                  // 0052BA70
    int GetScenarioOption(int option);          // 0052BA60
};

class TRIBE_World {
public:
    char gap_00[0x40];
    RGE_Player** players;                       // +0x40
    char gap_44[0x18];
    T_Scenario* scenario;                       // +0x5C
};

class TRIBE_Player {};
class RGE_Master_Static_Object {};

class TRIBE_Scenario_Editor_Panel_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);        // +0x14
    virtual void v18();
    virtual void v1C();
    virtual void v20(int v);                    // +0x20
    void set_master_info(RGE_Master_Static_Object* master, TRIBE_Player* player); // 004BEE40
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_000[0x480 - 0x478];
    void* SelectedObject;                       // +0x480
    void* DestinationObject;                    // +0x484
    char gap_488[0x498 - 0x488];
    int CurrentVictory;                         // +0x498
    char gap_49C[0x4A4 - 0x49C];
    int scenario_mode;                          // +0x4A4
    int map_type;                               // +0x4A8
    int mp_victory_type;                        // +0x4AC
    int brush_size;                             // +0x4B0
    int paint_type;                             // +0x4B4
    short player_num;                           // +0x4B8
    char gap_4BA[2];
    int message_type;                           // +0x4BC
    char gap_4C0[1];
    uchar valid_save_spot_flag;                 // +0x4C1
    char gap_4C2[0x4CC - 0x4C2];
    RGE_Diamond_Map_View* map_view;             // +0x4CC
    char gap_4D0[0x4D4 - 0x4D0];
    TPanel* bottom_panel;                       // +0x4D4
    TButtonPanel* scenario_mode_button[10];     // +0x4D8
    char gap_500[0x508 - 0x500];
    TButtonPanel* map_type_button[3];           // +0x508
    TButtonPanel* map_type_text[3];             // +0x514
    TPanel* map_type_label;                     // +0x520
    char gap_524[0x54C - 0x524];
    TPanel* generate_map_button;                // +0x54C
    char gap_550[0x554 - 0x550];
    TPanel* brush_size_label;                   // +0x554
    TPanel* brush_size_button[5];               // +0x558
    TPanel* brush_size_button_label[5];         // +0x56C
    TPanel* paint_type_label;                   // +0x580
    TPanel* paint_type_button[3];               // +0x584
    TPanel* paint_type_button_label[3];         // +0x590
    TPanel* paint_terrain_label;                // +0x59C
    char gap_5A0[0x5B0 - 0x5A0];
    TPanel* player_label;                       // +0x5B0
    TDropDownPanel* player_list;                // +0x5B4
    TDropDownPanel* player_number_list;         // +0x5B8
    TDropDownPanel* player_advance_civilization_drop; // +0x5BC
    char gap_5C0[0x5C4 - 0x5C0];
    TPanel* player_inven_label[5];              // +0x5C4
    TPanel* player_inven_input[5];              // +0x5D8
    TPanel* player_setting_label[2];            // +0x5EC
    TPanel* player_starting_age_label;          // +0x5F4
    TDropDownPanel* player_setting_drop[2];     // +0x5F8
    TDropDownPanel* BuildList;                  // +0x600
    TDropDownPanel* CityLayout;                 // +0x604
    TDropDownPanel* AiRules;                    // +0x608
    TPanel* player_build_text;                  // +0x60C
    TPanel* player_city_text;                   // +0x610
    TPanel* AiRules_text;                       // +0x614
    TDropDownPanel* unit_player_list;           // +0x618
    TButtonPanel* unit_mode_select[4];          // +0x61C
    TPanel* unit_mode_select_label[4];          // +0x62C
    TListPanel* unit_list;                      // +0x63C
    char gap_640[0x660 - 0x640];
    TRIBE_Scenario_Editor_Panel_Object* object_panel; // +0x660
    char gap_664[0x688 - 0x664];
    TPanel* victory_condition_label;            // +0x688
    char gap_68C[0x6CC - 0x68C];
    TPanel* victory_cond_type_label[5];         // +0x6CC
    TButtonPanel* victory_cond_type[5];         // +0x6E0
    char gap_6F4[0x734 - 0x6F4];
    TDropDownPanel* victory_drop_down;          // +0x734
    char gap_738[0x774 - 0x738];
    TEditPanel* message_input;                  // +0x774
    TButtonPanel* message_button[5];            // +0x778
    TPanel* message_button_label[5];            // +0x78C
    long current_message;                       // +0x7A0
    TPanel* cinematic_label[4];                 // +0x7A4
    TDropDownPanel* cinematic_input[4];         // +0x7B4
    TPanel* options_label[1];                   // +0x7C4
    TButtonPanel* options_button[1];            // +0x7C8
    TDropDownPanel* options_player_list;        // +0x7CC
    TPanel* options_disable_tech_text;          // +0x7D0
    TPanel* options_disable_button[16];         // +0x7D4
    TPanel* options_disable_text[16];           // +0x814
    char gap_854[0x874 - 0x854];
    TPanel* Diplomacy_player_text[8];           // +0x874
    TDropDownPanel* Diplomacy_player_list;      // +0x894
    TPanel* Diplomacy_status_label[4];          // +0x898
    TButtonPanel* Diplomacy_friend_box[8][3];   // +0x8A8
    TButtonPanel* Diplomacy_AlliedVictory[8];   // +0x908
    TRIBE_World* world;                         // +0x928

    void set_scenario_mode(ScenarioMode param_1);
    void set_map_type(int type, int redraw);                 // 004AA7A0
    void set_brush_size(int size);                           // 004AAA90
    void set_paint_type(int type, int redraw);               // 004AAB60
    void set_player(short player, uchar update, uchar refresh); // 004AAE20
    void set_mp_victory_type(int type, int redraw);          // 004AA8F0
    void set_message_type(int type, int value);              // 004AB6E0
    void set_unit(short unit);                               // 004AB670
    void set_unit_player(short player);                      // 004AB300
    void set_paint_object_mode();                            // 004AA730
    void activate_victory_panel(int flag);                   // 004B29E0
    void load_victory_cond_from_scenario(int current_victory); // 004AE620
    void save_victory_cond_in_scenario(int current_victory); // 004AE070
    void activate_victory_proper_fields(int line, int flag);// 004AEE10
    void load_multi_victory_cond_from_scenario();            // 004AE9D0
    void save_multi_victory_cond_in_scenario();              // 004ADD60
    void load_diplomacy_from_scenario(int player);           // 004AED50
    void save_diplomacy_in_scenario(int player);             // 004AECB0
    void SaveDisabledItemsInScenario();                      // 004ADC80
    void LoadDisabledItemsFromScenario();                    // 004ADD00
    void SavePlayerActiveStatus();                           // 004B2C50
    void save_info_in_scenario();                            // 004ADD50
};

void TRIBE_Screen_Sed::set_scenario_mode(ScenarioMode param_1)
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
                TButtonPanel** pp = this->map_type_text;
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
                this->set_map_type(this->map_type, 1);
            } else {
                this->set_map_type(ScenarioModeNone, 0);
            }
            break;

        case ScenarioModeTerrain:
            this->brush_size_label->set_active(active);
            this->paint_type_label->set_active(active);
            this->paint_terrain_label->set_active(active);
            {
                TPanel** pp = this->brush_size_button_label;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            {
                TPanel** pp = this->paint_type_button_label;
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
                this->set_paint_type(this->paint_type, 1);
            } else {
                this->set_brush_size(0);
                this->set_paint_type(0, 0);
            }
            break;

        case ScenarioModePlayers:
            this->player_list->set_active(active);
            this->player_number_list->set_active(active);
            {
                TPanel** pp = this->player_inven_input;
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
                    this->object_panel->v20(1);
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
                this->set_mp_victory_type(this->mp_victory_type, 1);
            } else {
                this->save_multi_victory_cond_in_scenario();
                this->map_view->set_active(1);
                this->set_mp_victory_type(0, 0);
            }
            break;

        case ScenarioModeMessages:
            {
                TPanel** pp = this->message_button_label;
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
                this->set_message_type(this->message_type, 1);
                this->map_view->set_active(0);
                this->bottom_panel->set_curr_child(this->message_input);
            } else {
                this->world->scenario->Set_message(this->message_input->get_input_buffer(), this->current_message);
                this->set_message_type(0, 0);
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
                this->options_button[0]->set_option(this->world->scenario->GetScenarioOption(2));
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
                TPanel** pp = this->options_disable_text;
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
