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
// BINARY NOTE: The final drift is at the Diplomacy friend-row cursor.  The
//              original uses EDI for row 0 and EBX for row 1; VC5 colors the
//              natural equivalent as EDI=row 1 and EBX=row 0.
// Tested 21 meaningful hypotheses.  The best clean source remains nonexact:
// 9090/9090 bytes, 358/358 calls, 97.94% exact blocks, 99.84% shape, 53 bytes.
// FLAGS: /GX (original has VC5 EH frame for new TShape/new editor object)

#include <stdio.h>
#include <new.h>

#define CSTR(x) ((char*)(x))
#define OK(expr) do { if (!(expr)) goto fail; } while (0)
#define HELP(panel, id, flag) ((TPanel*)(panel))->set_help_info((id), (flag))
#define ACTIVE(panel, value) ((TPanel*)(panel))->set_active((value))

class TPanel {
public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void set_active(int);

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
    char payload[0x20];
    TShape(char*, long);
    int is_loaded();
};

class TRIBE_Scenario_Editor_Panel_Object : public TPanel {
public:
    char gap_04[0xD4];
    int failed; // +0xD8
    char gap_DC[0x140];
    TRIBE_Scenario_Editor_Panel_Object(void*, TPanel*, void*, long, long, TShape*, TShape**, class TRIBE_Player*);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class TRIBE_Player;

class RGE_Base_Game {
public:
    RGE_Font* get_font(int);
};
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
class TRIBE_Screen_Sed_Vtbl {
public:
    VPAD32(0) VPAD16(32) VPAD2(48)
    virtual void set_group_active(TPanel**, int); // slot 50, +0xC8
};

class TRIBE_Screen_Sed {
public:
    char gap_000[0x20];
    void* draw_area; // +0x20
    char gap_024[0xB4];
    int base_error_flag; // +0xD8
    char gap_0DC[0x39C];
    int is_multi_player; // +0x478
    int set_player_first_flag; // +0x47C
    void* SelectedObject; // +0x480
    void* DestinationObject; // +0x484
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
    TPanel* main_view; // +0x4C8
    TPanel* map_view; // +0x4CC
    TPanel* message_panel; // +0x4D0
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
    void* unit_list_info; // +0x644
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
    void* world; // +0x928

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
    int count;
    TPanel* ptr[4];
    char str4[20];
    char str3[20];
    char str1[140];
    char str[100];
    char str2[140];
    register TButtonPanel** cur;
    TButtonPanel** pp;
    TTextPanel** tt;
    TButtonPanel** group;

    group = this->scenario_mode_button;
    cur = group;
    OK(this->create_button((TPanel*)this, cur, 0x271A, 1)); HELP(*cur, 0x76C0, -1);
    cur = this->scenario_mode_button + 1;
    OK(this->create_button((TPanel*)this, cur, 0x271B, 1)); HELP(*cur, 0x76C1, -1);
    cur = this->scenario_mode_button + 2;
    OK(this->create_button((TPanel*)this, cur, 0x271C, 1)); HELP(*cur, 0x76C2, -1);
    cur = this->scenario_mode_button + 3;
    OK(this->create_button((TPanel*)this, cur, 0x271D, 1)); HELP(*cur, 0x76C3, -1);
    cur = this->scenario_mode_button + 4;
    OK(this->create_button((TPanel*)this, cur, 0x2722, 1)); HELP(*cur, 0x76C8, -1);
    cur = this->scenario_mode_button + 5;
    OK(this->create_button((TPanel*)this, cur, 0x271E, 1)); HELP(*cur, 0x76C4, -1);
    cur = this->scenario_mode_button + 6;
    OK(this->create_button((TPanel*)this, cur, 0x2723, 1)); HELP(*cur, 0x76C9, -1);
    cur = this->scenario_mode_button + 7;
    OK(this->create_button((TPanel*)this, cur, 0x2721, 1)); HELP(*cur, 0x76C7, -1);
    cur = this->scenario_mode_button + 8;
    OK(this->create_button((TPanel*)this, cur, 0x271F, 1)); HELP(*cur, 0x76C5, -1);
    cur = this->scenario_mode_button + 9;
    OK(this->create_button((TPanel*)this, cur, 0x2720, 1)); HELP(*cur, 0x76C6, -1);

    cur = group;
    count = 10;
    do {
        (*cur)->set_radio_info(group, 10);
        (*cur)->set_active(1);
        ++cur;
        --count;
    } while (count != 0);

    OK(this->create_button((TPanel*)this, &this->menu_button, 0x2724, 0));
    HELP(this->menu_button, 0x774C, -1);
    this->menu_button->set_active(1);
    OK(this->create_button((TPanel*)this, &this->help_button, 0x0FA9, 0));
    this->help_button->set_active(1);

    OK(this->create_text(this->bottom_panel, &this->map_type_label, 0x29A6));
    OK(this->create_radio_button(this->bottom_panel, &this->map_type_button[0])); HELP(this->map_type_button[0], 0x76CF, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->map_type_button[1])); HELP(this->map_type_button[1], 0x76D0, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->map_type_button[2])); HELP(this->map_type_button[2], 0x76D1, -1);
    OK(this->create_text(this->bottom_panel, &this->map_type_text[0], 0x299C));
    OK(this->create_text(this->bottom_panel, &this->map_type_text[1], 0x299D));
    OK(this->create_text(this->bottom_panel, &this->map_type_text[2], 0x299E));
    OK(this->create_text(this->bottom_panel, &this->default_terrain_label, 0x299F));
    OK(this->create_drop_down(this->bottom_panel, &this->default_terrain_drop)); HELP(this->default_terrain_drop, 0x76D6, -1);
    OK(this->create_text(this->main_view, &this->map_generating_text, 0x29A5, 0, 0,
                         (int)((TPanel*)this)->width(), (int)((TPanel*)this)->height() - 200, 1, 1, 1, 0));
    this->map_generating_text->set_active(0);

    OK(this->create_text(this->bottom_panel, &this->map_size_label, 0x29A0));
    OK(this->create_drop_down(this->bottom_panel, &this->map_size_drop)); HELP(this->map_size_drop, 0x76D2, -1);
    OK(this->create_text(this->bottom_panel, &this->map_style_label, 0x29A1));
    OK(this->create_drop_down(this->bottom_panel, &this->map_style_drop)); HELP(this->map_style_drop, 0x76D3, -1);
    OK(this->create_text(this->bottom_panel, &this->random_seed_label, 0x29A2));
    OK(this->create_edit(this->bottom_panel, &this->random_seed_input, CSTR(0x586D44), 5, FormatUnsignedInt, 0, 0)); HELP(this->random_seed_input, 0x76D4, -1);
    OK(this->create_text(this->bottom_panel, &this->random_seed_used_label, 0x29A3));
    OK(this->create_text(this->bottom_panel, &this->random_seed_used_text, CSTR(0x586D44)));
    OK(this->create_button(this->bottom_panel, &this->generate_map_button, 0x29A4, 0)); HELP(this->generate_map_button, 0x76D5, -1);
    for (i = 0; i < 3; ++i) this->map_type_button[i]->set_radio_info(this->map_type_button, 3);

    OK(this->create_text(this->bottom_panel, &this->brush_size_label, 0x29AF));
    OK(this->create_text(this->bottom_panel, &this->paint_terrain_label, 0x29BC));
    OK(this->create_radio_button(this->bottom_panel, &this->brush_size_button[0])); HELP(this->brush_size_button[0], 0x76D9, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->brush_size_button[1])); HELP(this->brush_size_button[1], 0x76DA, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->brush_size_button[2])); HELP(this->brush_size_button[2], 0x76DB, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->brush_size_button[3])); HELP(this->brush_size_button[3], 0x76DC, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->brush_size_button[4])); HELP(this->brush_size_button[4], 0x76DD, -1);
    OK(this->create_text(this->bottom_panel, &this->brush_size_button_label[0], 0x29B0));
    OK(this->create_text(this->bottom_panel, &this->brush_size_button_label[1], 0x29B1));
    OK(this->create_text(this->bottom_panel, &this->brush_size_button_label[2], 0x29B2));
    OK(this->create_text(this->bottom_panel, &this->brush_size_button_label[3], 0x29B3));
    OK(this->create_text(this->bottom_panel, &this->brush_size_button_label[4], 0x29B4));
    OK(this->create_text(this->bottom_panel, &this->paint_type_label, 0x29B9));
    OK(this->create_radio_button(this->bottom_panel, &this->paint_type_button[0])); HELP(this->paint_type_button[0], 0x76DE, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->paint_type_button[1])); HELP(this->paint_type_button[1], 0x76DF, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->paint_type_button[2])); HELP(this->paint_type_button[2], 0x76E0, -1);
    OK(this->create_text(this->bottom_panel, &this->paint_type_button_label[0], 0x271A));
    OK(this->create_text(this->bottom_panel, &this->paint_type_button_label[1], 0x2987));
    OK(this->create_text(this->bottom_panel, &this->paint_type_button_label[2], 0x29BA));
    OK(this->create_list(this->bottom_panel, &this->paint_terrain_list, &this->paint_terrain_scrollbar)); HELP(this->paint_terrain_list, 0x76E1, -1);
    OK(this->create_list(this->bottom_panel, &this->paint_elevation_list, &this->paint_elevation_scrollbar)); HELP(this->paint_elevation_list, 0x76E2, -1);
    for (i = 0; i < 5; ++i) this->brush_size_button[i]->set_radio_info(this->brush_size_button, 5);
    for (i = 0; i < 3; ++i) this->paint_type_button[i]->set_radio_info(this->paint_type_button, 3);

    OK(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[0])); HELP(this->unit_mode_select[0], 0x76F8, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[1])); HELP(this->unit_mode_select[1], 0x76F7, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[2])); HELP(this->unit_mode_select[2], 0x76F9, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[3])); HELP(this->unit_mode_select[3], 0x76FA, -1);
    OK(this->create_text(this->bottom_panel, &this->unit_mode_select_label[0], 0x2777));
    OK(this->create_text(this->bottom_panel, &this->unit_mode_select_label[1], 0x2778));
    OK(this->create_text(this->bottom_panel, &this->unit_mode_select_label[2], 0x2779));
    OK(this->create_text(this->bottom_panel, &this->unit_mode_select_label[3], 0x277A));
    for (i = 0; i < 4; ++i) this->unit_mode_select[i]->set_radio_info(this->unit_mode_select, 4);
    this->unit_mode_select[0]->set_radio_button();

    OK(this->create_list((TPanel*)this, &this->unit_list, &this->unit_scrollbar));
    HELP(this->unit_list, 0x76FB, -1);
    this->unit_list->set_z_order(2, 0);

    this->button_unit_pics = new TShape(CSTR(0x586368), 0xC62A);
    if (!this->button_unit_pics) goto bad;
    if (!this->button_unit_pics->is_loaded()) goto bad;

    for (i = 0; i < 5; ++i) {
        int idx = i;
        if (idx == 4) idx = 1;
        sprintf(str, CSTR(0x586340), idx);
        this->button_bldg_pics[idx] = new TShape(str, idx + 0xC610);
        if (!this->button_bldg_pics[idx]) goto bad;
        if (!this->button_bldg_pics[idx]->is_loaded()) goto bad;
    }

    OK(this->create_drop_down(this->bottom_panel, &this->unit_player_list)); HELP(this->unit_player_list, 0x76FC, -1);
    {
        RGE_Font* f = rge_base_game->get_font(10);
        this->object_panel = new TRIBE_Scenario_Editor_Panel_Object(this->draw_area, (TPanel*)this, f->font, f->font_wid, f->font_hgt,
                                                                    this->button_unit_pics, this->button_bldg_pics, 0);
        if (!this->object_panel || this->object_panel->failed != 0) goto bad;
        this->object_panel->set_active(0);
        this->unit_player_list->set_z_order(1, 0);
    }

    OK(this->create_text(this->bottom_panel, &this->player_label, 0x2864));
    OK(this->create_text(this->bottom_panel, &this->player_starting_age_label, 0x2815));
    OK(this->create_drop_down(this->bottom_panel, &this->player_advance_civilization_drop)); HELP(this->player_advance_civilization_drop, 0x7765, -1);
    this->Set_player_advance_civilization_text(0);
    OK(this->create_drop_down(this->bottom_panel, &this->player_list)); HELP(this->player_list, 0x76E6, -1);
    OK(this->create_drop_down(this->bottom_panel, &this->player_number_list)); HELP(this->player_number_list, 0x76E7, -1);
    OK(this->create_text(this->bottom_panel, &this->player_inven_label[0], 0x280B));
    OK(this->create_text(this->bottom_panel, &this->player_inven_label[1], 0x280C));
    OK(this->create_text(this->bottom_panel, &this->player_inven_label[2], 0x280D));
    OK(this->create_text(this->bottom_panel, &this->player_inven_label[3], 0x280E));
    OK(this->create_text(this->bottom_panel, &this->player_inven_label[4], 0x2805));
    for (i = 0; i < 4; ++i) OK(this->create_edit(this->bottom_panel, &this->player_inven_input[i], CSTR(0x586D44), 5, FormatUnsignedInt, 0, 0));
    HELP(this->player_inven_input[0], 0x76E8, 1);
    HELP(this->player_inven_input[1], 0x76E9, 1);
    HELP(this->player_inven_input[2], 0x76EB, 1);
    HELP(this->player_inven_input[3], 0x76EA, 1);
    OK(this->create_edit(this->bottom_panel, &this->player_inven_input[4], CSTR(0x592A40), 0x1C, FormatText, 1, 1)); HELP(this->player_inven_input[4], 0x76EC, 1);
    OK(this->create_text(this->bottom_panel, &this->player_setting_label[0], 0x2810));
    OK(this->create_text(this->bottom_panel, &this->player_setting_label[1], 0x2811));
    for (i = 0; i < 2; ++i) OK(this->create_drop_down(this->bottom_panel, &this->player_setting_drop[i]));
    HELP(this->player_setting_drop[0], 0x76ED, -1);
    HELP(this->player_setting_drop[1], 0x76EE, -1);
    OK(this->create_drop_down(this->bottom_panel, &this->BuildList)); HELP(this->BuildList, 0x76EF, -1);
    OK(this->create_drop_down(this->bottom_panel, &this->CityLayout)); HELP(this->CityLayout, 0x76F0, -1);
    OK(this->create_drop_down(this->bottom_panel, &this->AiRules)); HELP(this->AiRules, 0x76F1, -1);
    OK(this->create_text(this->bottom_panel, &this->player_build_text, 0x2813));
    OK(this->create_text(this->bottom_panel, &this->player_city_text, 0x2814));
    OK(this->create_text(this->bottom_panel, &this->AiRules_text, 0x2812));
    ((TRIBE_Screen_Sed_Vtbl*)this)->set_group_active((TPanel**)this->player_inven_input, 5);

    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[0])); HELP(this->victory_cond_on[0], 0x7704, -1);
    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[1])); HELP(this->victory_cond_on[1], 0x7706, -1);
    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[2])); HELP(this->victory_cond_on[2], 0x7707, -1);
    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[3])); HELP(this->victory_cond_on[3], 0x7708, -1);
    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[4])); HELP(this->victory_cond_on[4], 0x7709, -1);
    OK(this->create_check_box(this->bottom_panel, &this->victory_cond_on[5])); HELP(this->victory_cond_on[5], 0x770A, -1);

    OK(this->create_radio_button(this->bottom_panel, &this->victory_and_or[0])); HELP(this->victory_and_or[0], 0x7701, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->victory_and_or[1])); HELP(this->victory_and_or[1], 0x7703, -1);
    for (i = 0; i < 2; ++i) this->victory_and_or[i]->set_radio_info(this->victory_and_or, 2);
    this->victory_and_or[0]->set_radio_button();
    OK(this->create_text(this->bottom_panel, &this->victory_text_and_or[0], 0x28A2));
    OK(this->create_text(this->bottom_panel, &this->victory_text_and_or[1], 0x28A3));
    OK(this->create_text(this->bottom_panel, &this->victory_amount_label, 0x28A4));
    OK(this->create_text(this->bottom_panel, &this->victory_long_label, 0x28A5));
    OK(this->create_text(this->bottom_panel, &this->victory_condition_label, 0x10E0));
    OK(this->create_text(this->bottom_panel, &this->victory_label_conquest, 0x10E1));
    OK(this->create_text(this->bottom_panel, &this->victory_label_explore, 0x10E2));
    OK(this->create_text(this->bottom_panel, &this->victory_label_explore_percent, 0x10E7));
    OK(this->create_text(this->bottom_panel, &this->victory_label_ruins, 0x10E3));
    OK(this->create_text(this->bottom_panel, &this->victory_label_artifacts, 0x10E4));
    OK(this->create_text(this->bottom_panel, &this->victory_label_discoveries, 0x10E5));
    OK(this->create_text(this->bottom_panel, &this->victory_label_gold, 0x10E6));
    OK(this->create_edit(this->bottom_panel, &this->victory_condition_explore, CSTR(0x580460), 3, FormatUnsignedInt, 0, 0)); HELP(this->victory_condition_explore, 0x770B, -1);
    OK(this->create_edit(this->bottom_panel, &this->victory_condition_ruins, CSTR(0x580460), 2, FormatUnsignedInt, 0, 0)); HELP(this->victory_condition_ruins, 0x770C, -1);
    OK(this->create_edit(this->bottom_panel, &this->victory_condition_artifacts, CSTR(0x580460), 2, FormatUnsignedInt, 0, 0)); HELP(this->victory_condition_artifacts, 0x770D, -1);
    OK(this->create_edit(this->bottom_panel, &this->victory_condition_discoveries, CSTR(0x580460), 2, FormatUnsignedInt, 0, 0)); HELP(this->victory_condition_discoveries, 0x770E, -1);
    OK(this->create_edit(this->bottom_panel, &this->victory_condition_gold, CSTR(0x580460), 5, FormatUnsignedInt, 0, 0)); HELP(this->victory_condition_gold, 0x770F, -1);
    ptr[0] = this->victory_condition_explore;
    ptr[1] = this->victory_condition_ruins;
    ptr[2] = this->victory_condition_artifacts;
    ptr[3] = this->victory_condition_discoveries;
    ((TRIBE_Screen_Sed_Vtbl*)this)->set_group_active(ptr, 4);

    OK(this->create_text(this->bottom_panel, &this->victory_cond_type_label[0], 0x10EC));
    OK(this->create_text(this->bottom_panel, &this->victory_cond_type_label[1], 0x10E1));
    OK(this->create_text(this->bottom_panel, &this->victory_cond_type_label[2], 0x10EA));
    OK(this->create_text(this->bottom_panel, &this->victory_cond_type_label[3], 0x10E9));
    OK(this->create_text(this->bottom_panel, &this->victory_cond_type_label[4], 0x10EB));
    OK(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[0])); HELP(this->victory_cond_type[0], 0x7756, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[1])); HELP(this->victory_cond_type[1], 0x7757, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[2])); HELP(this->victory_cond_type[2], 0x7758, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[3])); HELP(this->victory_cond_type[3], 0x7759, -1);
    OK(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[4])); HELP(this->victory_cond_type[4], 0x775A, -1);
    for (i = 0; i < 5; ++i) this->victory_cond_type[i]->set_radio_info(this->victory_cond_type, 5);
    this->victory_cond_type[1]->set_radio_button();

    OK(this->create_text(this->bottom_panel, &this->victory_score_label, 0x10EA));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_score)); HELP(this->victory_score, 0x775B, -1);
    this->victory_score->empty_list();
    this->victory_score->append_line(CSTR(0x586DA4), 3000);
    this->victory_score->append_line(CSTR(0x586D9C), 2700);
    this->victory_score->append_line(CSTR(0x586D94), 2400);
    this->victory_score->append_line(CSTR(0x586D8C), 2100);
    this->victory_score->append_line(CSTR(0x586D84), 1800);
    this->victory_score->append_line(CSTR(0x586D7C), 1500);
    this->victory_score->append_line(CSTR(0x586D74), 1200);
    this->victory_score->append_line(CSTR(0x586D70), 900);
    this->victory_score->append_line(CSTR(0x5800F8), 800);
    this->victory_score->append_line(CSTR(0x586D6C), 700);
    this->victory_score->append_line(CSTR(0x586D68), 600);
    this->victory_score->append_line(CSTR(0x586D64), 500);
    this->victory_score->append_line(CSTR(0x586D60), 400);
    this->victory_score->append_line(CSTR(0x586D5C), 300);

    OK(this->create_text(this->bottom_panel, &this->victory_time_label, 0x10E9));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_time)); HELP(this->victory_time, 0x775C, -1);
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
    do {
        sprintf(str1, CSTR(0x584610), i);
        sprintf(str2, CSTR(0x586D54), i);
        sprintf(str3, CSTR(0x586D50), i);
        sprintf(str4, CSTR(0x586D48), i);
        OK(this->create_button(this->bottom_panel, pp, str1, str2, str3, str4));
        HELP(*pp, 0x7712, -1);
        ++pp;
        ++i;
    } while (i - 1 < 12);

    OK(this->create_drop_down(this->bottom_panel, &this->victory_drop_down));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_object_list));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_player_list));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_enemy_player_list));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_attribute_list));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_ages_list));
    OK(this->create_drop_down(this->bottom_panel, &this->victory_tech_list));
    HELP(this->victory_drop_down, 0x7716, -1);
    HELP(this->victory_object_list, 0x7714, -1);
    HELP(this->victory_player_list, 0x7713, -1);
    HELP(this->victory_ages_list, 0x7715, -1);
    HELP(this->victory_enemy_player_list, 0x7760, -1);
    HELP(this->victory_attribute_list, 0x7761, -1);
    HELP(this->victory_tech_list, 0x7762, -1);

    OK(this->create_text(this->bottom_panel, &this->victory_condition_text, 0x2870));
    OK(this->create_text(this->bottom_panel, &this->victory_condition_type, 0x2871));
    OK(this->create_button(this->bottom_panel, &this->victory_button_set_object, 0x2872, 0));
    OK(this->create_button(this->bottom_panel, &this->victory_button_set_destination, 0x2873, 0));
    OK(this->create_button(this->bottom_panel, &this->victory_button_go_to_dest, 0x2874, 0));
    HELP(this->victory_button_set_object, 0x7717, -1);
    HELP(this->victory_button_set_destination, 0x7718, -1);
    HELP(this->victory_button_go_to_dest, 0x7719, -1);
    OK(this->create_text(this->bottom_panel, &this->victory_amount_text, 0x2875));
    OK(this->create_text(this->bottom_panel, &this->victory_which_enemy_text, 0x2876));
    OK(this->create_edit(this->bottom_panel, &this->victory_amount_input, CSTR(0x586D44), 5, FormatUnsignedInt, 0, 0));

    for (i = 0; i < 5; ++i) OK(this->create_radio_button(this->bottom_panel, &this->message_button[i]));
    this->current_message = 0;
    HELP(this->message_button[0], 0x771C, -1);
    HELP(this->message_button[1], 0x771D, -1);
    HELP(this->message_button[2], 0x771E, -1);
    HELP(this->message_button[3], 0x771F, -1);
    HELP(this->message_button[4], 0x7720, -1);
    OK(this->create_text(this->bottom_panel, &this->message_button_label[0], 0x2A36));
    OK(this->create_text(this->bottom_panel, &this->message_button_label[1], 0x2A37));
    OK(this->create_text(this->bottom_panel, &this->message_button_label[2], 0x2A38));
    OK(this->create_text(this->bottom_panel, &this->message_button_label[3], 0x2A39));
    OK(this->create_text(this->bottom_panel, &this->message_button_label[4], 0x2A31));
    for (i = 0; i < 5; ++i) this->message_button[i]->set_radio_info(this->message_button, 5);
    OK(this->create_edit(this->bottom_panel, &this->message_input, CSTR(0x592A40), 0x0FFF, FormatMultiLine, 1, 1));
    HELP(this->message_input, -1, -1);

    OK(this->create_text(this->bottom_panel, &this->cinematic_label[0], 0x2AF9));
    OK(this->create_text(this->bottom_panel, &this->cinematic_label[1], 0x2AFA));
    OK(this->create_text(this->bottom_panel, &this->cinematic_label[2], 0x2AFB));
    OK(this->create_text(this->bottom_panel, &this->cinematic_label[3], 0x2AFC));
    for (i = 0; i < 4; ++i) OK(this->create_drop_down(this->bottom_panel, &this->cinematic_input[i]));
    HELP(this->cinematic_input[0], 0x7724, -1);
    HELP(this->cinematic_input[1], 0x7725, -1);
    HELP(this->cinematic_input[2], 0x7726, -1);
    HELP(this->cinematic_input[3], 0x7727, -1);

    OK(this->create_text(this->bottom_panel, &this->options_label[0], 0x2604));
    OK(this->create_text(this->bottom_panel, &this->options_disable_tech_text, 0x32D7));
    for (i = 0; i < 1; ++i) OK(this->create_check_box(this->bottom_panel, &this->options_button[i]));
    HELP(this->options_button[0], 0x7729, -1);
    OK(this->create_drop_down(this->bottom_panel, &this->options_player_list)); HELP(this->options_player_list, 0x772B, -1);
    for (i = 0; i < 16; ++i) OK(this->create_check_box(this->bottom_panel, &this->options_disable_button[i]));
    HELP(this->options_disable_button[0], 0x772C, -1);
    HELP(this->options_disable_button[1], 0x772D, -1);
    HELP(this->options_disable_button[2], 0x772E, -1);
    HELP(this->options_disable_button[3], 0x772F, -1);
    HELP(this->options_disable_button[4], 0x7730, -1);
    HELP(this->options_disable_button[5], 0x7731, -1);
    HELP(this->options_disable_button[6], 0x7732, -1);
    HELP(this->options_disable_button[7], 0x7733, -1);
    HELP(this->options_disable_button[8], 0x7734, -1);
    HELP(this->options_disable_button[9], 0x7735, -1);
    HELP(this->options_disable_button[10], 0x7736, -1);
    HELP(this->options_disable_button[11], 0x7737, -1);
    HELP(this->options_disable_button[12], 0x7738, -1);
    HELP(this->options_disable_button[13], 0x7739, -1);
    HELP(this->options_disable_button[14], 0x773A, -1);
    HELP(this->options_disable_button[15], 0x773B, -1);
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[0], 0x32C9));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[1], 0x32CA));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[2], 0x32CB));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[3], 0x32CC));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[4], 0x32CD));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[5], 0x32CE));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[6], 0x32CF));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[7], 0x32D0));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[8], 0x32D1));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[9], 0x32D2));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[10], 0x32D3));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[11], 0x32D4));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[12], 0x32D5));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[13], 0x32D6));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[14], 0x32D8));
    OK(this->create_text(this->bottom_panel, &this->options_disable_text[15], 0x32D9));

    i = 0;
    tt = this->Diplomacy_player_text;
    do {
        sprintf(str1, CSTR(0x584610), i + 1);
        OK(this->create_text(this->bottom_panel, tt, str1));
        ++i;
        ++tt;
    } while (i < 8);
    OK(this->create_drop_down(this->bottom_panel, &this->Diplomacy_player_list)); HELP(this->Diplomacy_player_list, 0x773D, -1);

    pp = this->Diplomacy_AlliedVictory;
    for (i = 0; i < 8; ++i) {
        TButtonPanel** row = this->Diplomacy_friend_box[i];
        OK(this->create_radio_button(this->bottom_panel, &row[0])); HELP(row[0], 0x773F, -1);
        OK(this->create_radio_button(this->bottom_panel, &row[1])); HELP(row[1], 0x7740, -1);
        OK(this->create_radio_button(this->bottom_panel, &row[2])); HELP(row[2], 0x7741, -1);
        row[0]->set_radio_info(row, 3);
        row[1]->set_radio_info(row, 3);
        row[2]->set_radio_info(row, 3);
        row[1]->set_radio_button();
        OK(this->create_check_box(this->bottom_panel, pp));
        HELP(*pp, 0x773E, -1);
        ++pp;
    }
    OK(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[0], 0x29CD));
    OK(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[1], 0x29CE));
    OK(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[2], 0x29CF));
    this->create_text(this->bottom_panel, &this->Diplomacy_status_label[3], 0x29D0);

goto_done:
fail:
    return;

bad:
    this->base_error_flag = 1;
    return;
}
