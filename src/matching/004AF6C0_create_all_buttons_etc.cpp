// VA: 004AF6C0 TRIBE_Screen_Sed::create_all_buttons_etc
// PDB source: scr_sed2.cpp lines 1353-1893
// Initial reconstruction from packet/Ghidra plus matched local helper surfaces.
// try 1: compiles with /GX; .text is 9056 vs original 9090, manual diff after obj extraction
//        is 75.30% positional / 39.05% edit. First mismatch is initial button-base register
//        coloring (original EBP=&scenario_mode_button, rebuilt EDI); declaration/register probes did not move it.
// - Direct scenario-array cursors and the one-element options-button loop recover the
//   original frame, size, and early block layout.  The Diplomacy player loop uses i=0
//   with i+1 because the original reloads that display value from a zero-based counter.
// - Best validation is 9090/9090 bytes, 358/358 calls, 96.08% exact blocks, and
//   99.68% shape. Remaining drift is register/stack scheduling around later locals,
//   indirect relocations, and a one-byte epilogue displacement.
// - Natural four-panel group ordering (ptr[0..3]) replaces split ptr/str4 storage;
//   it recovers the +13DA block and improves the diagnostic diff by 5 bytes.
// try 2: restored the period ABI surfaces for long help/string IDs, short radio
//        counts and edit widths, TShape, and the scenario-object constructor.
//        This preserved the 9090-byte frame and 358 ordered calls.
// try 3: reordered victory-button setup and update expressions, then moved the
//        diplomacy counter setup before its cursor.  This reduced the mismatch
//        from 2682 to 53 bytes and restored 353/355 relocation masks.
// BINARY NOTE: Ground-truth and screen type dumps declare
//              Diplomacy_friend_box as TButtonPanel* [8][3] at +0x8A8.
//              Direct [i][0..2] access is therefore the natural row owner.
// second pass: Direct multidimensional indexing recovers the original row
//               registers, body order, size, frame, calls, and relocation masks.
// EXACT NOTE: The original PDB lists i but no pp local for this function.
//              Direct Diplomacy_AlliedVictory[i] indexing recovers the final
//              loop-home store order and the complete 9090-byte function.
//              The remaining pp is only the victory_button cursor.  Replacing
//              it with victory_button[i - 1] changed four bytes at +0x185C.
// FLAGS: /GX (original has VC5 EH frame for new TShape/new editor object)
//
// NATURALIZATION AUDIT:
// - The source gate does not permit the former absolute string casts, the
//   storage macro, or the generated screen surface.
// - The string externs below name the executable objects proved by the data
//   listing.  The inherited TPanel surface names the +0xC8 tab-order slot.
// - Exact donor 004B2EF0 uses the same ordered TPanel virtual declarations.
// - The type inventory gives TRIBE_Screen_Sed size 0x948 and keeps the
//   Diplomacy_friend_box member as TButtonPanel* [8][3] at +0x8A8.
// - The resulting source is policy-clean.  Its current build is 9090 bytes
//   with 358 ordered calls and 388/388 relocation masks.
// TYPE GATE:
// - Inventory types identify setup and the editor constructor's first
//   parameter as TDrawArea*, master_game_obj as RGE_Master_Static_Object*,
//   SelectedObject and DestinationObject as RGE_Static_Object*, and
//   unit_list_info as the nested 0x66-byte List_Info record.
// - RGE_Font::font and the editor constructor's font parameter remain void*;
//   TPanel::wnd_proc's first parameter is the Windows HWND-equivalent void*.
// - TShape uses the inventory-backed eight-field 0x20-byte surface.  No
//   aggregate payload, fake virtual slot, address cast, VPAD, or macro remains.
// BINARY NOTE: Named string externs make a natural do-loop split into a
//              first iteration and a loop body under VC5.  That split adds
//              five call sites.  A bottom-tested while loop keeps one site.
// BINARY NOTE: TRIBE_Scenario_Editor_Panel_Object owns the +0x214 and
//              +0x218 fields through TRIBE_Panel_Object.  Its status field
//              is the inherited TPanel error_code at +0xD8.

#include <stdio.h>
#include <new.h>

#include "../../include/rge_base_game_global.h"

// The executable's string table gives these objects stable names and values.
// Keep them as externs instead of hiding their addresses in casts.
extern char s_space[];             // 00580460: " "
extern char s_percent_d[];         // 00584610: "%d"
extern char s_btnbldg_d_shp[];     // 00586340: "btnbldg%d.shp"
extern char s_btnunit_shp[];       // 00586368: "btnunit.shp"
extern char s_0[];                 // 00586D44: "0"
extern char s_angle_d_star[];      // 00586D48: "<%d*>"
extern char s_percent_d_star[];    // 00586D50: "%d*"
extern char s_angle_d[];           // 00586D54: "<%d>"
extern char s_300[];               // 00586D5C: "300"
extern char s_400[];               // 00586D60: "400"
extern char s_500[];               // 00586D64: "500"
extern char s_600[];               // 00586D68: "600"
extern char s_700[];               // 00586D6C: "700"
extern char s_900[];               // 00586D70: "900"
extern char s_1200[];              // 00586D74: "1200"
extern char s_1500[];              // 00586D7C: "1500"
extern char s_1800[];              // 00586D84: "1800"
extern char s_2100[];              // 00586D8C: "2100"
extern char s_2400[];              // 00586D94: "2400"
extern char s_2700[];              // 00586D9C: "2700"
extern char s_3000[];              // 00586DA4: "3000"
extern char s_800[];               // 005800F8: "800"
extern char s_empty[];             // 00592A40: ""

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class Shape_Header;
class Shape_File_Header;
class Shape_Offsets;
class SLhape_File_Header;
class Shape_Info;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
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
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
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
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    char gap_24[0x54];
    int have_focus;
    char gap_7C[0x5C];
    int error_code;
    char gap_DC[0x8];
    long help_string_id;
    long help_page_id;
    char gap_EC[0x8];
    void set_help_info(long, long);
    void set_z_order(unsigned char, short);
    int width();
    int height();
};

class TButtonPanel : public TPanel {
public:
    void set_radio_info(TButtonPanel**, short);
    void set_radio_button();
};

class TTextPanel : public TPanel {};
class TEditPanel : public TPanel {};
class TListPanel : public TPanel {};
class TScrollBarPanel : public TPanel {};

class TDropDownPanel : public TPanel {
public:
    void empty_list();
    int append_line(long, long);
    int append_line(char*, long);
    void setCurrentLineNumber(int);
    void set_line(long);
    long get_line();
};

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;
    TShape(char*, long);
    ~TShape();
    int is_loaded();
};

class TRIBE_Panel_Object : public TPanel {
public:
    char gap_F4[0x120];
    virtual ~TRIBE_Panel_Object();
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj; // +0x214
    int master_culture_id; // +0x218
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea*, TPanel*, void*, long, long, TShape*, TShape**, class TRIBE_Player*);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class TRIBE_Player;
class TRIBE_World;
class TMessagePanel : public TPanel {
public:
    char gap_F4[0x28C];
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x26C];
};

class RGE_Main_View : public RGE_View {};
class TRIBE_Main_View : public RGE_Main_View {};

class RGE_Diamond_Map : public TPanel {};
class RGE_Diamond_Map_View : public RGE_Diamond_Map {};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    RGE_Font* get_font(int);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    class List_Info {
    public:
        char text[100];
        short id;
    };

    int is_multi_player; // +0x478
    int set_player_first_flag; // +0x47C
    RGE_Static_Object* SelectedObject; // +0x480
    RGE_Static_Object* DestinationObject; // +0x484
    float px1; // +0x488
    float py1; // +0x48C
    float px2; // +0x490
    float py2; // +0x494
    int CurrentVictory; // +0x498
    int CurrentPlayer; // +0x49C
    int SelectRegionFlag; // +0x4A0
    int scenario_mode; // +0x4A4
    int map_type; // +0x4A8
    int mp_victory_type; // +0x4AC
    int brush_size; // +0x4B0
    int paint_type; // +0x4B4
    short player_num; // +0x4B8
    unsigned char pad_4BA[0x2];
    int message_type; // +0x4BC
    unsigned char need_to_save_flag; // +0x4C0
    unsigned char valid_save_spot_flag; // +0x4C1
    unsigned char pad_4C2[0x2];
    TShape* background_pic; // +0x4C4
    TRIBE_Main_View* main_view; // +0x4C8
    RGE_Diamond_Map_View* map_view; // +0x4CC
    TMessagePanel* message_panel; // +0x4D0
    TPanel* bottom_panel; // +0x4D4
    TButtonPanel* scenario_mode_button[10]; // +0x4D8
    TButtonPanel* menu_button; // +0x500
    TButtonPanel* help_button; // +0x504
    TButtonPanel* map_type_button[3]; // +0x508
    TTextPanel* map_type_text[3]; // +0x514
    TTextPanel* map_type_label; // +0x520
    TTextPanel* default_terrain_label; // +0x524
    TDropDownPanel* default_terrain_drop; // +0x528
    TTextPanel* map_size_label; // +0x52C
    TDropDownPanel* map_size_drop; // +0x530
    TTextPanel* map_style_label; // +0x534
    TDropDownPanel* map_style_drop; // +0x538
    TTextPanel* random_seed_label; // +0x53C
    TEditPanel* random_seed_input; // +0x540
    TTextPanel* random_seed_used_label; // +0x544
    TTextPanel* random_seed_used_text; // +0x548
    TButtonPanel* generate_map_button; // +0x54C
    TTextPanel* map_generating_text; // +0x550
    TTextPanel* brush_size_label; // +0x554
    TButtonPanel* brush_size_button[5]; // +0x558
    TTextPanel* brush_size_button_label[5]; // +0x56C
    TTextPanel* paint_type_label; // +0x580
    TButtonPanel* paint_type_button[3]; // +0x584
    TTextPanel* paint_type_button_label[3]; // +0x590
    TTextPanel* paint_terrain_label; // +0x59C
    TListPanel* paint_terrain_list; // +0x5A0
    TScrollBarPanel* paint_terrain_scrollbar; // +0x5A4
    TListPanel* paint_elevation_list; // +0x5A8
    TScrollBarPanel* paint_elevation_scrollbar; // +0x5AC
    TTextPanel* player_label; // +0x5B0
    TDropDownPanel* player_list; // +0x5B4
    TDropDownPanel* player_number_list; // +0x5B8
    TDropDownPanel* player_advance_civilization_drop; // +0x5BC
    TButtonPanel* player_advance_civilization_button; // +0x5C0
    TTextPanel* player_inven_label[5]; // +0x5C4
    TEditPanel* player_inven_input[5]; // +0x5D8
    TTextPanel* player_setting_label[2]; // +0x5EC
    TTextPanel* player_starting_age_label; // +0x5F4
    TDropDownPanel* player_setting_drop[2]; // +0x5F8
    TDropDownPanel* BuildList; // +0x600
    TDropDownPanel* CityLayout; // +0x604
    TDropDownPanel* AiRules; // +0x608
    TTextPanel* player_build_text; // +0x60C
    TTextPanel* player_city_text; // +0x610
    TTextPanel* AiRules_text; // +0x614
    TDropDownPanel* unit_player_list; // +0x618
    TButtonPanel* unit_mode_select[4]; // +0x61C
    TTextPanel* unit_mode_select_label[4]; // +0x62C
    TListPanel* unit_list; // +0x63C
    TScrollBarPanel* unit_scrollbar; // +0x640
    List_Info* unit_list_info; // +0x644
    TShape* button_unit_pics; // +0x648
    TShape* button_bldg_pics[5]; // +0x64C
    TRIBE_Scenario_Editor_Panel_Object* object_panel; // +0x660
    short unit_list_size; // +0x664
    unsigned char pad_666[2];
    TButtonPanel* victory_cond_on[6]; // +0x668
    TButtonPanel* victory_and_or[2]; // +0x680
    TTextPanel* victory_condition_label; // +0x688
    TTextPanel* victory_amount_label; // +0x68C
    TTextPanel* victory_long_label; // +0x690
    TTextPanel* victory_text_and_or[2]; // +0x694
    TTextPanel* victory_label_conquest; // +0x69C
    TTextPanel* victory_label_explore; // +0x6A0
    TTextPanel* victory_label_explore_percent; // +0x6A4
    TTextPanel* victory_label_ruins; // +0x6A8
    TTextPanel* victory_label_artifacts; // +0x6AC
    TTextPanel* victory_label_discoveries; // +0x6B0
    TTextPanel* victory_label_gold; // +0x6B4
    TEditPanel* victory_condition_explore; // +0x6B8
    TEditPanel* victory_condition_ruins; // +0x6BC
    TEditPanel* victory_condition_artifacts; // +0x6C0
    TEditPanel* victory_condition_discoveries; // +0x6C4
    TEditPanel* victory_condition_gold; // +0x6C8
    TTextPanel* victory_cond_type_label[5]; // +0x6CC
    TButtonPanel* victory_cond_type[5]; // +0x6E0
    TTextPanel* victory_score_label; // +0x6F4
    TDropDownPanel* victory_score; // +0x6F8
    TTextPanel* victory_time_label; // +0x6FC
    TDropDownPanel* victory_time; // +0x700
    TButtonPanel* victory_button[12]; // +0x704
    TDropDownPanel* victory_drop_down; // +0x734
    TDropDownPanel* victory_object_list; // +0x738
    TDropDownPanel* victory_player_list; // +0x73C
    TDropDownPanel* victory_enemy_player_list; // +0x740
    TDropDownPanel* victory_attribute_list; // +0x744
    TDropDownPanel* victory_ages_list; // +0x748
    TDropDownPanel* victory_tech_list; // +0x74C
    TButtonPanel* victory_button_set_object; // +0x750
    TButtonPanel* victory_button_set_destination; // +0x754
    TButtonPanel* victory_button_go_to_dest; // +0x758
    TTextPanel* victory_condition_text; // +0x75C
    TTextPanel* victory_condition_type; // +0x760
    TTextPanel* victory_amount_text; // +0x764
    TTextPanel* victory_which_enemy_text; // +0x768
    TEditPanel* victory_amount_input; // +0x76C
    TScrollBarPanel* victory_object_scrollbar; // +0x770
    TEditPanel* message_input; // +0x774
    TButtonPanel* message_button[5]; // +0x778
    TTextPanel* message_button_label[5]; // +0x78C
    long current_message; // +0x7A0
    TTextPanel* cinematic_label[4]; // +0x7A4
    TDropDownPanel* cinematic_input[4]; // +0x7B4
    TTextPanel* options_label[1]; // +0x7C4
    TButtonPanel* options_button[1]; // +0x7C8
    TDropDownPanel* options_player_list; // +0x7CC
    TTextPanel* options_disable_tech_text; // +0x7D0
    TButtonPanel* options_disable_button[16]; // +0x7D4
    TTextPanel* options_disable_text[16]; // +0x814
    TTextPanel* Diplomacy_opponent_label[8]; // +0x854
    TTextPanel* Diplomacy_player_text[8]; // +0x874
    TDropDownPanel* Diplomacy_player_list; // +0x894
    TTextPanel* Diplomacy_status_label[4]; // +0x898
    TButtonPanel* Diplomacy_friend_box[8][3]; // +0x8A8
    TButtonPanel* Diplomacy_AlliedVictory[8]; // +0x908
    TRIBE_World* world; // +0x928
    unsigned long update_interval; // +0x92C
    unsigned long last_update_time; // +0x930
    unsigned long map_redraw_interval; // +0x934
    unsigned long last_map_redraw_time; // +0x938
    int changed_system_colors; // +0x93C
    unsigned long save_text_color; // +0x940
    unsigned long save_window_color; // +0x944

    virtual ~TRIBE_Screen_Sed();
    int create_button(TPanel*, TButtonPanel**, long, int);
    int create_button(TPanel*, TButtonPanel**, char*, char*, char*, char*);
    int create_text(TPanel*, TTextPanel**, long);
    int create_text(TPanel*, TTextPanel**, char*);
    int create_text(TPanel*, TTextPanel**, int, int, int, int, int, int, int, int, int);
    int create_drop_down(TPanel*, TDropDownPanel**);
    int create_edit(TPanel*, TEditPanel**, char*, short, int, int, int);
    int create_list(TPanel*, TListPanel**, TScrollBarPanel**);
    int create_radio_button(TPanel*, TButtonPanel**);
    int create_check_box(TPanel*, TButtonPanel**);
    int Set_player_advance_civilization_text(int);
    void create_all_buttons_etc();
};

const int FormatText = 0;
const int FormatUnsignedInt = 3;
const int FormatMultiLine = 7;

void TRIBE_Screen_Sed::create_all_buttons_etc()
{
    int i;
    TButtonPanel** pp;
    int count;
    TPanel* ptr[4];
    char str4[20];
    char str3[20];
    char str1[140];
    char str[100];
    char str2[140];
    TButtonPanel** cur;
    TTextPanel** tt;
    TButtonPanel** group;

    group = this->scenario_mode_button;
    cur = group;
    if (!(this->create_button(this, cur, 0x271A, 1))) goto fail; (*cur)->set_help_info(0x76C0, -1);
    cur = this->scenario_mode_button + 1;
    if (!(this->create_button(this, cur, 0x271B, 1))) goto fail; (*cur)->set_help_info(0x76C1, -1);
    cur = this->scenario_mode_button + 2;
    if (!(this->create_button(this, cur, 0x271C, 1))) goto fail; (*cur)->set_help_info(0x76C2, -1);
    cur = this->scenario_mode_button + 3;
    if (!(this->create_button(this, cur, 0x271D, 1))) goto fail; (*cur)->set_help_info(0x76C3, -1);
    cur = this->scenario_mode_button + 4;
    if (!(this->create_button(this, cur, 0x2722, 1))) goto fail; (*cur)->set_help_info(0x76C8, -1);
    cur = this->scenario_mode_button + 5;
    if (!(this->create_button(this, cur, 0x271E, 1))) goto fail; (*cur)->set_help_info(0x76C4, -1);
    cur = this->scenario_mode_button + 6;
    if (!(this->create_button(this, cur, 0x2723, 1))) goto fail; (*cur)->set_help_info(0x76C9, -1);
    cur = this->scenario_mode_button + 7;
    if (!(this->create_button(this, cur, 0x2721, 1))) goto fail; (*cur)->set_help_info(0x76C7, -1);
    cur = this->scenario_mode_button + 8;
    if (!(this->create_button(this, cur, 0x271F, 1))) goto fail; (*cur)->set_help_info(0x76C5, -1);
    cur = this->scenario_mode_button + 9;
    if (!(this->create_button(this, cur, 0x2720, 1))) goto fail; (*cur)->set_help_info(0x76C6, -1);

    cur = group;
    count = 10;
    do {
        (*cur)->set_radio_info(group, 10);
        (*cur)->set_active(1);
        ++cur;
        --count;
    } while (count != 0);

    if (!(this->create_button(this, &this->menu_button, 0x2724, 0))) goto fail;
    (this->menu_button)->set_help_info(0x774C, -1);
    this->menu_button->set_active(1);
    if (!(this->create_button(this, &this->help_button, 0x0FA9, 0))) goto fail;
    this->help_button->set_active(1);

    if (!(this->create_text(this->bottom_panel, &this->map_type_label, 0x29A6))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[0]))) goto fail; (this->map_type_button[0])->set_help_info(0x76CF, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[1]))) goto fail; (this->map_type_button[1])->set_help_info(0x76D0, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[2]))) goto fail; (this->map_type_button[2])->set_help_info(0x76D1, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[0], 0x299C))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[1], 0x299D))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[2], 0x299E))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->default_terrain_label, 0x299F))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->default_terrain_drop))) goto fail; (this->default_terrain_drop)->set_help_info(0x76D6, -1);
    if (!(this->create_text(this->main_view, &this->map_generating_text, 0x29A5, 0, 0,
                         (int)(this)->width(), (int)(this)->height() - 200, 1, 1, 1, 0))) goto fail;
    this->map_generating_text->set_active(0);

    if (!(this->create_text(this->bottom_panel, &this->map_size_label, 0x29A0))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_size_drop))) goto fail; (this->map_size_drop)->set_help_info(0x76D2, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_style_label, 0x29A1))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_style_drop))) goto fail; (this->map_style_drop)->set_help_info(0x76D3, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_label, 0x29A2))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->random_seed_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail; (this->random_seed_input)->set_help_info(0x76D4, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_label, 0x29A3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_text, s_0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->generate_map_button, 0x29A4, 0))) goto fail; (this->generate_map_button)->set_help_info(0x76D5, -1);
    for (i = 0; i < 3; ++i) this->map_type_button[i]->set_radio_info(this->map_type_button, 3);

    if (!(this->create_text(this->bottom_panel, &this->brush_size_label, 0x29AF))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_terrain_label, 0x29BC))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[0]))) goto fail; (this->brush_size_button[0])->set_help_info(0x76D9, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[1]))) goto fail; (this->brush_size_button[1])->set_help_info(0x76DA, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[2]))) goto fail; (this->brush_size_button[2])->set_help_info(0x76DB, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[3]))) goto fail; (this->brush_size_button[3])->set_help_info(0x76DC, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[4]))) goto fail; (this->brush_size_button[4])->set_help_info(0x76DD, -1);
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[0], 0x29B0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[1], 0x29B1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[2], 0x29B2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[3], 0x29B3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[4], 0x29B4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_label, 0x29B9))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[0]))) goto fail; (this->paint_type_button[0])->set_help_info(0x76DE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[1]))) goto fail; (this->paint_type_button[1])->set_help_info(0x76DF, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[2]))) goto fail; (this->paint_type_button[2])->set_help_info(0x76E0, -1);
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[0], 0x271A))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[1], 0x2987))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[2], 0x29BA))) goto fail;
    if (!(this->create_list(this->bottom_panel, &this->paint_terrain_list, &this->paint_terrain_scrollbar))) goto fail; (this->paint_terrain_list)->set_help_info(0x76E1, -1);
    if (!(this->create_list(this->bottom_panel, &this->paint_elevation_list, &this->paint_elevation_scrollbar))) goto fail; (this->paint_elevation_list)->set_help_info(0x76E2, -1);
    for (i = 0; i < 5; ++i) this->brush_size_button[i]->set_radio_info(this->brush_size_button, 5);
    for (i = 0; i < 3; ++i) this->paint_type_button[i]->set_radio_info(this->paint_type_button, 3);

    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[0]))) goto fail; (this->unit_mode_select[0])->set_help_info(0x76F8, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[1]))) goto fail; (this->unit_mode_select[1])->set_help_info(0x76F7, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[2]))) goto fail; (this->unit_mode_select[2])->set_help_info(0x76F9, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[3]))) goto fail; (this->unit_mode_select[3])->set_help_info(0x76FA, -1);
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[0], 0x2777))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[1], 0x2778))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[2], 0x2779))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[3], 0x277A))) goto fail;
    for (i = 0; i < 4; ++i) this->unit_mode_select[i]->set_radio_info(this->unit_mode_select, 4);
    this->unit_mode_select[0]->set_radio_button();

    if (!(this->create_list(this, &this->unit_list, &this->unit_scrollbar))) goto fail;
    (this->unit_list)->set_help_info(0x76FB, -1);
    this->unit_list->set_z_order(2, 0);

    this->button_unit_pics = new TShape(s_btnunit_shp, 0xC62A);
    if (!this->button_unit_pics) goto bad;
    if (!this->button_unit_pics->is_loaded()) goto bad;

    for (i = 0; i < 5; ++i) {
        int idx = i;
        if (idx == 4) idx = 1;
        sprintf(str, s_btnbldg_d_shp, idx);
        this->button_bldg_pics[idx] = new TShape(str, idx + 0xC610);
        if (!this->button_bldg_pics[idx]) goto bad;
        if (!this->button_bldg_pics[idx]->is_loaded()) goto bad;
    }

    if (!(this->create_drop_down(this->bottom_panel, &this->unit_player_list))) goto fail; (this->unit_player_list)->set_help_info(0x76FC, -1);
    {
        RGE_Font* f = rge_base_game->get_font(10);
        this->object_panel = new TRIBE_Scenario_Editor_Panel_Object(this->render_area, this, f->font, f->font_wid, f->font_hgt,
                                                                    this->button_unit_pics, this->button_bldg_pics, 0);
        if (!this->object_panel || this->object_panel->error_code != 0) goto bad;
        this->object_panel->set_active(0);
        this->unit_player_list->set_z_order(1, 0);
    }

    if (!(this->create_text(this->bottom_panel, &this->player_label, 0x2864))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_starting_age_label, 0x2815))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->player_advance_civilization_drop))) goto fail; (this->player_advance_civilization_drop)->set_help_info(0x7765, -1);
    this->Set_player_advance_civilization_text(0);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_list))) goto fail; (this->player_list)->set_help_info(0x76E6, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_number_list))) goto fail; (this->player_number_list)->set_help_info(0x76E7, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[0], 0x280B))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[1], 0x280C))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[2], 0x280D))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[3], 0x280E))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[4], 0x2805))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[i], s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;
    (this->player_inven_input[0])->set_help_info(0x76E8, 1);
    (this->player_inven_input[1])->set_help_info(0x76E9, 1);
    (this->player_inven_input[2])->set_help_info(0x76EB, 1);
    (this->player_inven_input[3])->set_help_info(0x76EA, 1);
    if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[4], s_empty, 0x1C, FormatText, 1, 1))) goto fail; (this->player_inven_input[4])->set_help_info(0x76EC, 1);
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[0], 0x2810))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[1], 0x2811))) goto fail;
    for (i = 0; i < 2; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->player_setting_drop[i]))) goto fail;
    (this->player_setting_drop[0])->set_help_info(0x76ED, -1);
    (this->player_setting_drop[1])->set_help_info(0x76EE, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->BuildList))) goto fail; (this->BuildList)->set_help_info(0x76EF, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->CityLayout))) goto fail; (this->CityLayout)->set_help_info(0x76F0, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->AiRules))) goto fail; (this->AiRules)->set_help_info(0x76F1, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_build_text, 0x2813))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_city_text, 0x2814))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->AiRules_text, 0x2812))) goto fail;
    this->set_tab_order((TPanel**)this->player_inven_input, 5);

    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[0]))) goto fail; (this->victory_cond_on[0])->set_help_info(0x7704, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[1]))) goto fail; (this->victory_cond_on[1])->set_help_info(0x7706, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[2]))) goto fail; (this->victory_cond_on[2])->set_help_info(0x7707, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[3]))) goto fail; (this->victory_cond_on[3])->set_help_info(0x7708, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[4]))) goto fail; (this->victory_cond_on[4])->set_help_info(0x7709, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[5]))) goto fail; (this->victory_cond_on[5])->set_help_info(0x770A, -1);

    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[0]))) goto fail; (this->victory_and_or[0])->set_help_info(0x7701, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[1]))) goto fail; (this->victory_and_or[1])->set_help_info(0x7703, -1);
    for (i = 0; i < 2; ++i) this->victory_and_or[i]->set_radio_info(this->victory_and_or, 2);
    this->victory_and_or[0]->set_radio_button();
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[0], 0x28A2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[1], 0x28A3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_label, 0x28A4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_long_label, 0x28A5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_label, 0x10E0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_conquest, 0x10E1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore, 0x10E2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore_percent, 0x10E7))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_ruins, 0x10E3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_artifacts, 0x10E4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_discoveries, 0x10E5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_gold, 0x10E6))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_explore, s_space, 3, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_explore)->set_help_info(0x770B, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_ruins, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_ruins)->set_help_info(0x770C, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_artifacts, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_artifacts)->set_help_info(0x770D, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_discoveries, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_discoveries)->set_help_info(0x770E, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_gold, s_space, 5, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_gold)->set_help_info(0x770F, -1);
    ptr[0] = this->victory_condition_explore;
    ptr[1] = this->victory_condition_ruins;
    ptr[2] = this->victory_condition_artifacts;
    ptr[3] = this->victory_condition_discoveries;
    this->set_tab_order(ptr, 4);

    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[0], 0x10EC))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[1], 0x10E1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[2], 0x10EA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[3], 0x10E9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[4], 0x10EB))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[0]))) goto fail; (this->victory_cond_type[0])->set_help_info(0x7756, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[1]))) goto fail; (this->victory_cond_type[1])->set_help_info(0x7757, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[2]))) goto fail; (this->victory_cond_type[2])->set_help_info(0x7758, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[3]))) goto fail; (this->victory_cond_type[3])->set_help_info(0x7759, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[4]))) goto fail; (this->victory_cond_type[4])->set_help_info(0x775A, -1);
    for (i = 0; i < 5; ++i) this->victory_cond_type[i]->set_radio_info(this->victory_cond_type, 5);
    this->victory_cond_type[1]->set_radio_button();

    if (!(this->create_text(this->bottom_panel, &this->victory_score_label, 0x10EA))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_score))) goto fail; (this->victory_score)->set_help_info(0x775B, -1);
    this->victory_score->empty_list();
    this->victory_score->append_line(s_3000, 3000);
    this->victory_score->append_line(s_2700, 2700);
    this->victory_score->append_line(s_2400, 2400);
    this->victory_score->append_line(s_2100, 2100);
    this->victory_score->append_line(s_1800, 1800);
    this->victory_score->append_line(s_1500, 1500);
    this->victory_score->append_line(s_1200, 1200);
    this->victory_score->append_line(s_900, 900);
    this->victory_score->append_line(s_800, 800);
    this->victory_score->append_line(s_700, 700);
    this->victory_score->append_line(s_600, 600);
    this->victory_score->append_line(s_500, 500);
    this->victory_score->append_line(s_400, 400);
    this->victory_score->append_line(s_300, 300);

    if (!(this->create_text(this->bottom_panel, &this->victory_time_label, 0x10E9))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_time))) goto fail; (this->victory_time)->set_help_info(0x775C, -1);
    this->victory_time->empty_list();
    this->victory_time->append_line(0x2634, 15000);
    this->victory_time->append_line(0x2635, 13000);
    this->victory_time->append_line(0x2636, 11000);
    this->victory_time->append_line(0x2637, 9000);
    this->victory_time->append_line(0x2638, 7000);
    this->victory_time->append_line(0x2639, 5000);
    this->victory_time->append_line(0x263A, 3000);

    i = 1;
    pp = this->victory_button;
    while (i - 1 < 12) {
        sprintf(str1, s_percent_d, i);
        sprintf(str2, s_angle_d, i);
        sprintf(str3, s_percent_d_star, i);
        sprintf(str4, s_angle_d_star, i);
        if (!(this->create_button(this->bottom_panel, pp, str1, str2, str3, str4))) goto fail;
        (*pp)->set_help_info(0x7712, -1);
        ++pp;
        ++i;
    }

    if (!(this->create_drop_down(this->bottom_panel, &this->victory_drop_down))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_object_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_player_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_enemy_player_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_attribute_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_ages_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_tech_list))) goto fail;
    (this->victory_drop_down)->set_help_info(0x7716, -1);
    (this->victory_object_list)->set_help_info(0x7714, -1);
    (this->victory_player_list)->set_help_info(0x7713, -1);
    (this->victory_ages_list)->set_help_info(0x7715, -1);
    (this->victory_enemy_player_list)->set_help_info(0x7760, -1);
    (this->victory_attribute_list)->set_help_info(0x7761, -1);
    (this->victory_tech_list)->set_help_info(0x7762, -1);

    if (!(this->create_text(this->bottom_panel, &this->victory_condition_text, 0x2870))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_type, 0x2871))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_object, 0x2872, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_destination, 0x2873, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_go_to_dest, 0x2874, 0))) goto fail;
    (this->victory_button_set_object)->set_help_info(0x7717, -1);
    (this->victory_button_set_destination)->set_help_info(0x7718, -1);
    (this->victory_button_go_to_dest)->set_help_info(0x7719, -1);
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_text, 0x2875))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_which_enemy_text, 0x2876))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_amount_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;

    for (i = 0; i < 5; ++i) if (!(this->create_radio_button(this->bottom_panel, &this->message_button[i]))) goto fail;
    this->current_message = 0;
    (this->message_button[0])->set_help_info(0x771C, -1);
    (this->message_button[1])->set_help_info(0x771D, -1);
    (this->message_button[2])->set_help_info(0x771E, -1);
    (this->message_button[3])->set_help_info(0x771F, -1);
    (this->message_button[4])->set_help_info(0x7720, -1);
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[0], 0x2A36))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[1], 0x2A37))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[2], 0x2A38))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[3], 0x2A39))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[4], 0x2A31))) goto fail;
    for (i = 0; i < 5; ++i) this->message_button[i]->set_radio_info(this->message_button, 5);
    if (!(this->create_edit(this->bottom_panel, &this->message_input, s_empty, 0x0FFF, FormatMultiLine, 1, 1))) goto fail;
    (this->message_input)->set_help_info(-1, -1);

    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[0], 0x2AF9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[1], 0x2AFA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[2], 0x2AFB))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[3], 0x2AFC))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->cinematic_input[i]))) goto fail;
    (this->cinematic_input[0])->set_help_info(0x7724, -1);
    (this->cinematic_input[1])->set_help_info(0x7725, -1);
    (this->cinematic_input[2])->set_help_info(0x7726, -1);
    (this->cinematic_input[3])->set_help_info(0x7727, -1);

    if (!(this->create_text(this->bottom_panel, &this->options_label[0], 0x2604))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_tech_text, 0x32D7))) goto fail;
    for (i = 0; i < 1; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_button[i]))) goto fail;
    (this->options_button[0])->set_help_info(0x7729, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->options_player_list))) goto fail; (this->options_player_list)->set_help_info(0x772B, -1);
    for (i = 0; i < 16; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_disable_button[i]))) goto fail;
    (this->options_disable_button[0])->set_help_info(0x772C, -1);
    (this->options_disable_button[1])->set_help_info(0x772D, -1);
    (this->options_disable_button[2])->set_help_info(0x772E, -1);
    (this->options_disable_button[3])->set_help_info(0x772F, -1);
    (this->options_disable_button[4])->set_help_info(0x7730, -1);
    (this->options_disable_button[5])->set_help_info(0x7731, -1);
    (this->options_disable_button[6])->set_help_info(0x7732, -1);
    (this->options_disable_button[7])->set_help_info(0x7733, -1);
    (this->options_disable_button[8])->set_help_info(0x7734, -1);
    (this->options_disable_button[9])->set_help_info(0x7735, -1);
    (this->options_disable_button[10])->set_help_info(0x7736, -1);
    (this->options_disable_button[11])->set_help_info(0x7737, -1);
    (this->options_disable_button[12])->set_help_info(0x7738, -1);
    (this->options_disable_button[13])->set_help_info(0x7739, -1);
    (this->options_disable_button[14])->set_help_info(0x773A, -1);
    (this->options_disable_button[15])->set_help_info(0x773B, -1);
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[0], 0x32C9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[1], 0x32CA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[2], 0x32CB))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[3], 0x32CC))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[4], 0x32CD))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[5], 0x32CE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[6], 0x32CF))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[7], 0x32D0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[8], 0x32D1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[9], 0x32D2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[10], 0x32D3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[11], 0x32D4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[12], 0x32D5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[13], 0x32D6))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[14], 0x32D8))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[15], 0x32D9))) goto fail;

    i = 0;
    tt = this->Diplomacy_player_text;
    while (1) {
        sprintf(str1, s_percent_d, i + 1);
        if (!(this->create_text(this->bottom_panel, tt, str1))) goto fail;
        ++tt;
        ++i;
        if (i >= 8) break;
    }
    if (!(this->create_drop_down(this->bottom_panel, &this->Diplomacy_player_list))) goto fail; (this->Diplomacy_player_list)->set_help_info(0x773D, -1);

    i = 0;
    while (i < 8) {
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][0]))) goto fail; (this->Diplomacy_friend_box[i][0])->set_help_info(0x773F, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][1]))) goto fail; (this->Diplomacy_friend_box[i][1])->set_help_info(0x7740, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][2]))) goto fail; (this->Diplomacy_friend_box[i][2])->set_help_info(0x7741, -1);
        this->Diplomacy_friend_box[i][0]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][2]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_button();
        if (!(this->create_check_box(this->bottom_panel, &this->Diplomacy_AlliedVictory[i]))) goto fail;
        this->Diplomacy_AlliedVictory[i]->set_help_info(0x773E, -1);
        ++i;
    }
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[0], 0x29CD))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[1], 0x29CE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[2], 0x29CF))) goto fail;
    this->create_text(this->bottom_panel, &this->Diplomacy_status_label[3], 0x29D0);

fail:
    return;

bad:
    this->error_code = 1;
    return;
}
