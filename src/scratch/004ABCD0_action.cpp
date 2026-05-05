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
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stdlib.h>
#include <string.h>

struct RGE_Static_Object;
struct RGE_Master_Static_Object;
struct TRIBE_Player;
struct TShape;
struct TMessagePanel;
struct TScrollBarPanel;
struct TRIBE_Main_View;
struct RGE_Diamond_Map_View;
struct TRIBE_Scenario_Editor_Panel_Object;
struct RGE_Scenario;
struct T_Scenario;

struct TPanel {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_active(int active);        // +0x14
    virtual void vf18();
    virtual void vf1C();
    virtual void redraw(int flags);             // +0x20
    char* panelName();
    void set_curr_child(TPanel* child);
    void set_help_info(long string_id, long param_2);
};

struct TRIBE_Main_View : public TPanel {
    void get_selection_area(long* y1, long* y2, long* x1, long* x2, int flag);
};

struct TButtonPanel : public TPanel {
    int get_state();
    void set_radio_button();
};
struct TTextPanel : public TPanel {
    int currentLineNumber();
    void set_text(char* text);
};
struct TListPanel : public TTextPanel {};
struct TDropDownPanel : public TTextPanel {
    int get_line();
    void setCurrentLineNumber(int line);
};
struct TEditPanel : public TTextPanel {
    char* currentLine();
    char* get_input_buffer();
};

struct TPanelSystem {
    void destroyPanel(char* name);
    void setCurrentPanel(char* name, int param_2);
};

struct RGE_Tile_List {
    char pad[0x14];
    void del_list();
};

struct RGE_Player {
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x4A - 0x28];
    short id;
    char gap_4C[0x58 - 0x4C];
    RGE_Tile_List tile_list;
    void select_one_object(RGE_Static_Object* obj, int mode);
    void unselect_object();
    void reset_selected();
    void set_map_loc(short x, short y);
    void set_view_loc(float x, float y);
    void set_map_visible();
};

struct RGE_Map {
    void clear_map(RGE_Player* player, void* world, unsigned char terrain, long width, long height);
};

struct RGE_Game_World {
    void* vtable_ptr;
    char gap_04[0x28 - 0x04];
    RGE_Map* map;
    char gap_2C[0x40 - 0x2C];
    RGE_Player** players;
    char gap_44[0x5C - 0x44];
    RGE_Scenario* scenario;
    void new_random_map(float size_x, float size_y, float style, long players);
};

struct TRIBE_World : public RGE_Game_World {};

struct RGE_Base_Game_Dispatch {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void redraw(long mode, long flags);
};

struct RGE_Base_Game {
    void* vtable_ptr;
    char gap_04[0x10 - 0x04];
    void* prog_window;
    char gap_14[0x2C - 0x14];
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    char gap_38[0x1B4 - 0x38];
    int game_mode;
    char gap_1B8[0x3FC - 0x1B8];
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    RGE_Player* get_player();
    void draw_window();
    void redraw(int flags);
    void close();
};

struct TRIBE_Game : public RGE_Base_Game {
    int start_menu();
    void start_scenario_editor(char* name, int mode);
};

struct T_Scenario {
    void SetPlayerAge(int player, int age);
    int GetPlayerAge(long player);
    void SetSPWhich(int player);
    void Set_Multi_Conquest(int v);
    void SetScenarioOption(int option, int value);
};

struct RGE_Scenario : public T_Scenario {
    void Set_message(char* text, long which);
    char* Get_message(long which);
};

struct TRIBE_Scenario_Editor_Panel_Object : public TPanel {
    void set_master_info(RGE_Master_Static_Object* master, TRIBE_Player* player);
};

struct TRIBE_Screen_Sed_Open {
    char pad[0x490];
    TRIBE_Screen_Sed_Open();
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern char s_OKDialog[];
extern char s_QuitSaveDialog[];
extern char s_OpenSaveDialog[];
extern char s_NewSaveDialog[];
extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Editor_Open[];
extern char s_C__msdev_work_age1_x1_scr_sed_cp[];

extern int __stdcall InvalidateRect(void* hwnd, void* rect, int erase);
extern "C" void __cdecl debug_rand(char* file, int line);

#define GAME_REDRAW0() (((RGE_Base_Game_Dispatch*)rge_base_game)->redraw(0, 0))
#define GAME_PLAYER() (rge_base_game->get_player())
#define SELECT_IF_PRESENT(obj_) do { RGE_Static_Object* _sel_obj = (obj_); if (_sel_obj != 0) { GAME_PLAYER()->select_one_object(_sel_obj, 0); } } while (0)

struct TRIBE_Screen_Sed : public TPanel {
    enum SELECT_REGION_e { SELECT_OFF = 0, SELECT_OBJECT = 1, SELECT_DEST_OBJECT = 2, SELECT_AREA = 3 };
    enum ScenarioMode { ScenarioModeMap = 1, ScenarioModeTerrain = 2, ScenarioModePlayers = 3, ScenarioModeUnits = 4, ScenarioModeDiplomacy = 5, ScenarioModeVictory = 6, ScenarioModeVictoryMulti = 7, ScenarioModeOptions = 8, ScenarioModeMessages = 9 };
    enum MapType { MapTypeBlank = 1, MapTypeSeed = 2, MapTypeRandom = 3 };
    enum VictoryType { VictoryTypeStandard = 1 };
    enum BrushSize { BrushSizeVerySmall = 1 };
    enum PaintType { PaintTypeTerrain = 1 };
    enum MessageType { MessageTypeNone = 0 };
    enum { ScenarioModeMapEnum = 1 };
    struct List_Info { char text[100]; short id; };

    char gap_panel[0x478 - 4];
    int is_multi_player;
    int set_player_first_flag;
    RGE_Static_Object* SelectedObject;
    RGE_Static_Object* DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    SELECT_REGION_e SelectRegionFlag;
    ScenarioMode scenario_mode;
    MapType map_type;
    VictoryType mp_victory_type;
    BrushSize brush_size;
    PaintType paint_type;
    short player_num;
    unsigned char pad_4BA[2];
    MessageType message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    unsigned char pad_4C2[2];
    TShape* background_pic;
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    TMessagePanel* message_panel;
    TPanel* bottom_panel;
    TButtonPanel* scenario_mode_button[10];
    TButtonPanel* menu_button;
    TButtonPanel* help_button;
    TButtonPanel* map_type_button[3];
    TTextPanel* map_type_text[3];
    TTextPanel* map_type_label;
    TTextPanel* default_terrain_label;
    TDropDownPanel* default_terrain_drop;
    TTextPanel* map_size_label;
    TDropDownPanel* map_size_drop;
    TTextPanel* map_style_label;
    TDropDownPanel* map_style_drop;
    TTextPanel* random_seed_label;
    TEditPanel* random_seed_input;
    TTextPanel* random_seed_used_label;
    TTextPanel* random_seed_used_text;
    TButtonPanel* generate_map_button;
    TTextPanel* map_generating_text;
    TTextPanel* brush_size_label;
    TButtonPanel* brush_size_button[5];
    TTextPanel* brush_size_button_label[5];
    TTextPanel* paint_type_label;
    TButtonPanel* paint_type_button[3];
    TTextPanel* paint_type_button_label[3];
    TTextPanel* paint_terrain_label;
    TListPanel* paint_terrain_list;
    TScrollBarPanel* paint_terrain_scrollbar;
    TListPanel* paint_elevation_list;
    TScrollBarPanel* paint_elevation_scrollbar;
    TTextPanel* player_label;
    TDropDownPanel* player_list;
    TDropDownPanel* player_number_list;
    TDropDownPanel* player_advance_civilization_drop;
    TButtonPanel* player_advance_civilization_button;
    TTextPanel* player_inven_label[5];
    TEditPanel* player_inven_input[5];
    TTextPanel* player_setting_label[2];
    TTextPanel* player_starting_age_label;
    TDropDownPanel* player_setting_drop[2];
    TDropDownPanel* BuildList;
    TDropDownPanel* CityLayout;
    TDropDownPanel* AiRules;
    TTextPanel* player_build_text;
    TTextPanel* player_city_text;
    TTextPanel* AiRules_text;
    TDropDownPanel* unit_player_list;
    TButtonPanel* unit_mode_select[4];
    TTextPanel* unit_mode_select_label[4];
    TListPanel* unit_list;
    TScrollBarPanel* unit_scrollbar;
    List_Info* unit_list_info;
    TShape* button_unit_pics;
    TShape* button_bldg_pics[5];
    TRIBE_Scenario_Editor_Panel_Object* object_panel;
    short unit_list_size;
    unsigned char pad_666[2];
    TButtonPanel* victory_cond_on[6];
    TButtonPanel* victory_and_or[2];
    TTextPanel* victory_condition_label;
    TTextPanel* victory_amount_label;
    TTextPanel* victory_long_label;
    TTextPanel* victory_text_and_or[2];
    TTextPanel* victory_label_conquest;
    TTextPanel* victory_label_explore;
    TTextPanel* victory_label_explore_percent;
    TTextPanel* victory_label_ruins;
    TTextPanel* victory_label_artifacts;
    TTextPanel* victory_label_discoveries;
    TTextPanel* victory_label_gold;
    TEditPanel* victory_condition_explore;
    TEditPanel* victory_condition_ruins;
    TEditPanel* victory_condition_artifacts;
    TEditPanel* victory_condition_discoveries;
    TEditPanel* victory_condition_gold;
    TTextPanel* victory_cond_type_label[5];
    TButtonPanel* victory_cond_type[5];
    TTextPanel* victory_score_label;
    TDropDownPanel* victory_score;
    TTextPanel* victory_time_label;
    TDropDownPanel* victory_time;
    TButtonPanel* victory_button[12];
    TDropDownPanel* victory_drop_down;
    TDropDownPanel* victory_object_list;
    TDropDownPanel* victory_player_list;
    TDropDownPanel* victory_enemy_player_list;
    TDropDownPanel* victory_attribute_list;
    TDropDownPanel* victory_ages_list;
    TDropDownPanel* victory_tech_list;
    TButtonPanel* victory_button_set_object;
    TButtonPanel* victory_button_set_destination;
    TButtonPanel* victory_button_go_to_dest;
    TTextPanel* victory_condition_text;
    TTextPanel* victory_condition_type;
    TTextPanel* victory_amount_text;
    TTextPanel* victory_which_enemy_text;
    TEditPanel* victory_amount_input;
    TScrollBarPanel* victory_object_scrollbar;
    TEditPanel* message_input;
    TButtonPanel* message_button[5];
    TTextPanel* message_button_label[5];
    long current_message;
    TTextPanel* cinematic_label[4];
    TDropDownPanel* cinematic_input[4];
    TTextPanel* options_label[1];
    TButtonPanel* options_button[1];
    TDropDownPanel* options_player_list;
    TTextPanel* options_disable_tech_text;
    TButtonPanel* options_disable_button[16];
    TTextPanel* options_disable_text[16];
    TTextPanel* Diplomacy_opponent_label[8];
    TTextPanel* Diplomacy_player_text[8];
    TDropDownPanel* Diplomacy_player_list;
    TTextPanel* Diplomacy_status_label[4];
    TButtonPanel* Diplomacy_friend_box[8][3];
    TButtonPanel* Diplomacy_AlliedVictory[8];
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    int changed_system_colors;
    unsigned long save_text_color;
    unsigned long save_window_color;

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void set_scenario_mode(int mode);
    void command_menu();
    void set_map_type(int type, int redraw);
    void set_brush_size(int size);
    void set_paint_type(int type, int redraw);
    void set_terrain(short terrain);
    void set_elevation(short elevation);
    void set_unit_player(short player);
    void set_unit(short unit);
    void set_paint_object_mode();
    void set_player(short player, unsigned char a, unsigned char b);
    void SavePlayerActiveStatus();
    void activate_victory_panel(int active);
    void activate_victory_proper_fields(long line, int active);
    void save_victory_cond_in_scenario(int current);
    void load_victory_cond_from_scenario(int current);
    void set_mp_victory_type(int type, int redraw);
    void SaveDisabledItemsInScenario();
    void LoadDisabledItemsFromScenario();
    void set_panel_info();
    void command_save(unsigned char event_type, unsigned char dialog_type);
    void setup_popup_help();
    void load_diplomacy_from_scenario(long player);
    void save_diplomacy_in_scenario(int player);
};

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    long result;
    int i;
    int map_size;
    long line;
    char random_val[28];
    long x2;
    long x1;
    long y1;
    long y2;
    float f1;
    float f2;
    RGE_Player* player;
    char* panel_name;
    unsigned char* scan;
    unsigned char* lit;
    unsigned char ch;
    int cmp_value;
    TRIBE_Player* tribe_player;
    RGE_Master_Static_Object* master;

    if (param_1 == 0) {
        result = 0;
        goto early_return;
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
            goto early_return_one;
        }
        if (param_2 == 0x11 && rge_base_game->game_mode == 0x11) {
            GAME_REDRAW0();
        }
    }

    goto after_early_return;
early_return_one:
    result = 1;
early_return:
    return result;
after_early_return:

    if (param_2 == 1) {
        for (i = 0; i < 10; i++) {
            if (param_1 == this->scenario_mode_button[i]) {
                this->set_scenario_mode(i + ScenarioModeMap);
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

    panel_name = param_1->panelName();
    if (panel_name != 0) {
        lit = (unsigned char*)0x584EB4;
        scan = (unsigned char*)param_1->panelName();
        while (1) {
            ch = *scan;
            if (ch != *lit) { cmp_value = (ch < *lit) ? -1 : 1; break; }
            if (ch == 0) { cmp_value = 0; break; }
            ch = scan[1];
            if (ch != lit[1]) { cmp_value = (ch < lit[1]) ? -1 : 1; break; }
            scan += 2;
            lit += 2;
            if (ch == 0) { cmp_value = 0; break; }
        }
        if (cmp_value == 0) {
            if (param_2 == 0) {
                panel_system.destroyPanel(s_OKDialog);
                this->set_scenario_mode(ScenarioModePlayers);
            }
            return 1;
        }
    }

    switch (this->scenario_mode) {
    case ScenarioModeMap:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 3; i++) {
                if (param_1 == this->map_type_button[i]) {
                    this->set_map_type(i + MapTypeBlank, 1);
                    return 1;
                }
            }
            if (param_1 == this->generate_map_button) {
                this->map_generating_text->set_active(1);
                this->redraw(2);
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
                f1 = (float)(map_size / 2);
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->set_map_loc((short)f1, (short)f1);
                    this->world->players[i]->set_view_loc(f1, f1);
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
                    if (param_1 == this->paint_type_button[i]) { this->set_paint_type(i + PaintTypeTerrain, 1); return 1; }
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
                if (line != 0) {
                    GAME_REDRAW0();
                    if (rge_base_game->master_obj_id == -1 || (player = GAME_PLAYER()) == 0) {
                        tribe_player = 0;
                        master = 0;
                    } else {
                        master = player->master_objects[rge_base_game->master_obj_id];
                        tribe_player = (TRIBE_Player*)GAME_PLAYER();
                    }
                    this->object_panel->set_master_info(master, tribe_player);
                    this->set_paint_object_mode();
                    this->object_panel->redraw(2);
                    return 1;
                }
                GAME_REDRAW0();
            }
        }
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->unit_list) {
                i = ((TTextPanel*)this->unit_list)->currentLineNumber();
                this->set_unit((short)i);
                if (rge_base_game->game_mode != 8 && rge_base_game->game_mode != 0x15) this->unit_mode_select[0]->set_radio_button();
                if (rge_base_game->master_obj_id == -1 || (player = GAME_PLAYER()) == 0) { tribe_player = 0; master = 0; }
                else { master = player->master_objects[rge_base_game->master_obj_id]; tribe_player = (TRIBE_Player*)GAME_PLAYER(); }
                this->object_panel->set_master_info(master, tribe_player);
                this->set_paint_object_mode();
                this->object_panel->redraw(2);
                return 1;
            }
            if (param_2 == 1) {
                if (param_1 == this->unit_mode_select[0]) this->set_paint_object_mode();
                else if (param_1 == this->unit_mode_select[1]) { GAME_PLAYER()->unselect_object(); GAME_REDRAW0(); }
                else if (param_1 == this->unit_mode_select[2]) GAME_REDRAW0();
                else if (param_1 == this->unit_mode_select[3]) GAME_REDRAW0();
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
                if (param_1 == this->victory_button_set_object) { this->SelectRegionFlag = SELECT_OBJECT; GAME_REDRAW0(); GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->DestinationObject); }
                else if (param_1 == this->victory_button_set_destination && line != 1) { this->SelectRegionFlag = SELECT_AREA; GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->SelectedObject); GAME_REDRAW0(); return 1; }
                else if (param_1 == this->victory_button_set_destination) { this->SelectRegionFlag = SELECT_DEST_OBJECT; GAME_REDRAW0(); GAME_PLAYER()->unselect_object(); SELECT_IF_PRESENT(this->SelectedObject); }
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
                        player = GAME_PLAYER();
                        player->set_map_loc((short)f1, (short)f2);
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

    case ScenarioModeVictoryMulti:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 5; i++) {
                if (param_1 == this->victory_cond_type[i]) {
                    this->set_mp_victory_type(i + VictoryTypeStandard, 1);
                    if (i != 4) { this->world->scenario->Set_Multi_Conquest(1); this->victory_cond_on[0]->redraw(1); }
                    return 1;
                }
            }
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

    case ScenarioModeMessages:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            line = this->current_message;
            this->world->scenario->Set_message(this->message_input->get_input_buffer(), line);
            for (i = 0; i < 5; i++) if (param_1 == this->message_button[i]) { this->current_message = i; break; }
            this->message_input->set_text(this->world->scenario->Get_message(this->current_message));
            switch (this->current_message) {
            case 0: this->message_input->set_help_info(0x7770, -1); break;
            case 1: this->message_input->set_help_info(0x7771, -1); break;
            case 2: this->message_input->set_help_info(0x7772, -1); break;
            case 3: this->message_input->set_help_info(0x7773, -1); break;
            case 4: this->message_input->set_help_info(0x7774, -1); break;
            }
        }
        break;
    }

    panel_name = param_1->panelName();
    if (panel_name != 0) {
        lit = (unsigned char*)0x586D18;
        scan = (unsigned char*)param_1->panelName();
        while (1) {
            ch = *scan;
            if (ch != *lit) { cmp_value = (ch < *lit) ? -1 : 1; break; }
            if (ch == 0) { cmp_value = 0; break; }
            ch = scan[1];
            if (ch != lit[1]) { cmp_value = (ch < lit[1]) ? -1 : 1; break; }
            scan += 2;
            lit += 2;
            if (ch == 0) { cmp_value = 0; break; }
        }
        if (cmp_value == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_QuitSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 1);
            else if (param_2 == 1) {
                if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) rge_base_game->close();
                else panel_system.destroyPanel(s_Scenario_Editor_Screen);
            }
            return 1;
        }
    }

    panel_name = param_1->panelName();
    if (panel_name != 0) {
        lit = (unsigned char*)0x586D08;
        scan = (unsigned char*)param_1->panelName();
        while (1) {
            ch = *scan;
            if (ch != *lit) { cmp_value = (ch < *lit) ? -1 : 1; break; }
            if (ch == 0) { cmp_value = 0; break; }
            ch = scan[1];
            if (ch != lit[1]) { cmp_value = (ch < lit[1]) ? -1 : 1; break; }
            scan += 2;
            lit += 2;
            if (ch == 0) { cmp_value = 0; break; }
        }
        if (cmp_value == 0) {
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
    }

    panel_name = param_1->panelName();
    if (panel_name != 0) {
        lit = (unsigned char*)0x586CF8;
        scan = (unsigned char*)param_1->panelName();
        while (1) {
            ch = *scan;
            if (ch != *lit) { cmp_value = (ch < *lit) ? -1 : 1; break; }
            if (ch == 0) { cmp_value = 0; break; }
            ch = scan[1];
            if (ch != lit[1]) { cmp_value = (ch < lit[1]) ? -1 : 1; break; }
            scan += 2;
            lit += 2;
            if (ch == 0) { cmp_value = 0; break; }
        }
        if (cmp_value == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_NewSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 3);
            else if (param_2 == 1) ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
            return 1;
        }
    }

    result = 0;
    return result;
}
