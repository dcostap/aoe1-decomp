// VA: 004B1A50 TRIBE_Screen_Sed::position_panels (3969 B)
// PDB source: scr_sed2.cpp:1900-2175
// Attempt log:
// - Replaced the panel-name placeholder with the binary-supported panel layout.
// - Baseline uses the recovered set_position/set_fixed_position virtual surfaces,
//   natural panel arrays, and the two layout loops shown by the source-line bands.
// - Restored omitted object, unit-list, victory, and current-message fields from
//   the proven offsets; signed /4 and %4 reproduces the victory grid arithmetic.
// - Best check is 3969/3969 bytes with 157/157 calls and 100% shape.  The only
//   drift is nine option-loop register-color bytes; the natural TTextPanel cursor
//   is retained after equivalent register probes produced no exact match.
// - Tested a TPanel base cursor for the adjacent option fields; emitted bytes
//   were unchanged, so the canonical TTextPanel cursor was restored.

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void set_position(int, int, int, int, int, int, int, int, int,
                              TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(int, int, int, int);
    void set_z_order(unsigned char, int);
};

class TTextPanel : public TPanel {
public:
    int numberLines();
    int numberDrawLines();
};
class TButtonPanel : public TPanel {};
class TDropDownPanel : public TPanel {};
class TEditPanel : public TPanel {};
class TListPanel : public TTextPanel {};
class TScrollBarPanel : public TPanel {};
class TMessagePanel : public TPanel {};
class TRIBE_Main_View : public TPanel {};
class RGE_Diamond_Map_View : public TPanel {};
class TRIBE_Scenario_Editor_Panel_Object : public TPanel {};
class TShape;

class TRIBE_Screen_Sed {
public:
    char gap_000[0x478];
    char gap_478_to_4c4[0x4c4 - 0x478];
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
    TPanel* unit_list_info;
    TShape* button_unit_pics;
    TShape* button_bldg_pics[5];
    TButtonPanel* object_panel;
    char unit_list_size_pad[4];
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
    char current_message_pad[4];
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

    void position_panels();
};

void TRIBE_Screen_Sed::position_panels()
{
    if (this->main_view == 0)
        return;

    for (int mode_row = 0; mode_row < 5; ++mode_row) {
        TButtonPanel* previous = mode_row == 0 ? 0 : this->scenario_mode_button[mode_row - 1];
        this->scenario_mode_button[mode_row]->set_position(
            7, 2, 2, 2, 2, 0x32, 0x6d, 0x16, 0x16, previous, 0, 0, 0);
    }
    for (int mode_col = 5; mode_col < 10; ++mode_col) {
        TButtonPanel* previous = mode_col == 5 ? 0 : this->scenario_mode_button[mode_col - 1];
        this->scenario_mode_button[mode_col]->set_position(
            7, 2, 2, 2, 2, 0x32, 0x6d, 0x16, 0x16, previous,
            this->scenario_mode_button[mode_col - 5], 0, 0);
    }

    this->menu_button->set_position(9, 2, 5, 3, 3, 0x3a, 0x3a, 0x14, 0x28, 0, 0, 0, 0);
    this->help_button->set_position(10, 5, 5, 5, 5, 0x14, 0x1e, 0x14, 0x1e, 0, 0, 0, 0);
    this->map_view->set_position(10, 0, 0, 0, 0, 0xe6, 0xe6, 0x87, 0x87, 0, 0, 0, 0);
    this->bottom_panel->set_position(8, 2, 2, 2, 2, 0, 0, 0x89, 0x89, 0, 0, this->map_view, 0);
    this->unit_list->set_position(7, 0, 6, 0, 4, 0x7c, 200, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
    this->object_panel->set_position(8, 4, 4, 4, 4, 0x96, 0x96, 0x6c, 0x6c, 0, 0, 0, 0);

    TScrollBarPanel* unit_panel = (TScrollBarPanel*)this->unit_list;
    int number_lines = ((TTextPanel*)unit_panel)->numberLines();
    int number_draw_lines = ((TTextPanel*)unit_panel)->numberDrawLines();
    if (number_lines > number_draw_lines) {
        this->unit_list->set_position(7, 0, 6, 0, 4, 0x68, 0xdc, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
        this->unit_scrollbar->set_position(7, 1, 1, 0, 2, 0x12, 0x12, 0, 0, this->unit_list, this->menu_button, 0, this->bottom_panel);
        unit_panel = this->unit_scrollbar;
    }
    this->main_view->set_position(7, 0, 6, 0, 4, 0, 0, 0, 0, unit_panel, this->menu_button, 0, this->bottom_panel);
    this->message_panel->set_position(8, 4, 4, 4, 4, 0, 0, 0x18, 0x18, 0, 0, 0, 0);

    this->map_type_label->set_fixed_position(4, 4, 0x78, 0x16);
    this->map_type_button[0]->set_fixed_position(4, 0x16, 0x16, 0x16);
    this->map_type_button[1]->set_fixed_position(4, 0x2c, 0x16, 0x16);
    this->map_type_button[2]->set_fixed_position(4, 0x42, 0x16, 0x16);
    this->map_type_text[0]->set_fixed_position(0x24, 0x16, 0x73, 0x16);
    this->map_type_text[1]->set_fixed_position(0x24, 0x2c, 0x73, 0x16);
    this->map_type_text[2]->set_fixed_position(0x24, 0x42, 0x73, 0x16);
    this->map_size_label->set_fixed_position(0xaa, 4, 0x82, 0x16);
    this->map_size_drop->set_fixed_position(0xaa, 0x16, 0xaa, 0x16);
    this->map_style_label->set_fixed_position(0xaa, 0x30, 0x82, 0x16);
    this->map_style_drop->set_fixed_position(0xaa, 0x42, 0xaa, 0x16);
    this->default_terrain_label->set_fixed_position(0xaa, 0x30, 0x82, 0x16);
    this->default_terrain_drop->set_fixed_position(0xaa, 0x42, 0xaa, 0x16);
    this->random_seed_label->set_fixed_position(0x24, 0x5a, 0x78, 0x16);
    this->random_seed_input->set_fixed_position(0x24, 0x70, 0x37, 0x16);
    this->random_seed_used_label->set_fixed_position(0x24, 0x5a, 0x78, 0x16);
    this->random_seed_used_text->set_fixed_position(0x24, 0x70, 0x37, 0x16);
    this->generate_map_button->set_fixed_position(0xb4, 0x60, 0x82, 0x26);
    this->paint_terrain_list->set_fixed_position(0x73, 0x17, 0xa5, 0x6e);
    this->paint_terrain_label->set_fixed_position(0x73, 1, 0x3c, 0x16);
    this->paint_elevation_list->set_fixed_position(0x73, 0x17, 0xa5, 0x6e);
    this->paint_type_label->set_fixed_position(2, 1, 0x6e, 0x14);
    this->paint_type_button[0]->set_fixed_position(2, 0x17, 0x1e, 0x16);
    this->paint_type_button[1]->set_fixed_position(2, 0x2d, 0x1e, 0x16);
    this->paint_type_button[2]->set_fixed_position(2, 0x43, 0x1e, 0x16);
    this->paint_type_button_label[0]->set_fixed_position(0x21, 0x17, 0x51, 0x16);
    this->paint_type_button_label[1]->set_fixed_position(0x21, 0x2d, 0x51, 0x16);
    this->paint_type_button_label[2]->set_fixed_position(0x21, 0x43, 0x51, 0x16);
    this->brush_size_label->set_fixed_position(0x118, 4, 0x6e, 0x14);
    this->brush_size_button[0]->set_fixed_position(0x11a, 0x17, 0x1e, 0x16);
    this->brush_size_button[1]->set_fixed_position(0x11a, 0x2d, 0x1e, 0x16);
    this->brush_size_button[2]->set_fixed_position(0x11a, 0x43, 0x1e, 0x16);
    this->brush_size_button[3]->set_fixed_position(0x11a, 0x59, 0x1e, 0x16);
    this->brush_size_button[4]->set_fixed_position(0x11a, 0x6f, 0x1e, 0x16);
    this->brush_size_button_label[0]->set_fixed_position(0x139, 0x17, 0x5a, 0x16);
    this->brush_size_button_label[1]->set_fixed_position(0x139, 0x2d, 0x5a, 0x16);
    this->brush_size_button_label[2]->set_fixed_position(0x139, 0x43, 0x5a, 0x16);
    this->brush_size_button_label[3]->set_fixed_position(0x139, 0x59, 0x5a, 0x16);
    this->brush_size_button_label[4]->set_fixed_position(0x139, 0x6f, 0x5a, 0x16);

    this->player_label->set_fixed_position(4, 4, 0x50, 0x12);
    this->player_starting_age_label->set_fixed_position(4, 0x5c, 0x5f, 0x12);
    this->player_advance_civilization_drop->set_fixed_position(4, 0x6e, 0x96, 0x16);
    this->player_label->set_fixed_position(4, 0x2a, 0x96, 0x12);
    this->player_list->set_fixed_position(4, 7, 0x96, 0x16);
    this->player_number_list->set_fixed_position(4, 0x3e, 0x96, 0x16);

    int x = 0xa6;
    TEditPanel** player_input = this->player_inven_input;
    do {
        int y = 0x19;
        do {
            ((TTextPanel*)player_input[-5])->set_fixed_position(x, y - 0x12, 0x37, 0x12);
            (*player_input)->set_fixed_position(x, y, 0x37, 0x16);
            y += 0x2c;
            ++player_input;
        } while (y < 0x71);
        x += 0x44;
    } while (x < 0x12e);

    this->player_inven_label[4]->set_fixed_position(0xa6, 0x5c, 100, 0x12);
    this->player_inven_input[4]->set_fixed_position(0xa6, 0x6e, 0x7d, 0x16);

    int setting_y = 0x19;
    TDropDownPanel** setting_drop = this->player_setting_drop;
    do {
        ((TTextPanel*)setting_drop[-3])->set_fixed_position(500, setting_y - 0x12, 0x82, 0x12);
        (*setting_drop)->set_fixed_position(500, setting_y, 0x82, 0x16);
        setting_y += 0x2c;
        ++setting_drop;
    } while (setting_y < 0x71);

    this->BuildList->set_fixed_position(300, 0x45, 0xbe, 0x16);
    this->CityLayout->set_fixed_position(300, 0x19, 0xbe, 0x16);
    this->player_build_text->set_fixed_position(300, 0x33, 0x82, 0x12);
    this->player_city_text->set_fixed_position(300, 7, 0x82, 0x12);
    this->AiRules_text->set_fixed_position(300, 0x5c, 0x82, 0x12);
    this->AiRules->set_fixed_position(300, 0x6e, 0xbe, 0x16);

    this->unit_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    this->unit_mode_select[0]->set_fixed_position(0xa0, 0x16, 0x1e, 0x16);
    this->unit_mode_select[1]->set_fixed_position(0xa0, 0x30, 0x1e, 0x16);
    this->unit_mode_select[2]->set_fixed_position(0xa0, 0x4a, 0x1e, 0x16);
    this->unit_mode_select[3]->set_fixed_position(0xa0, 0x62, 0x1e, 0x16);
    this->unit_mode_select_label[0]->set_fixed_position(0xc0, 0x16, 0x6e, 0x16);
    this->unit_mode_select_label[1]->set_fixed_position(0xc0, 0x30, 0x6e, 0x16);
    this->unit_mode_select_label[2]->set_fixed_position(0xc0, 0x4a, 0x6e, 0x16);
    this->unit_mode_select_label[3]->set_fixed_position(0xc0, 0x62, 0x6e, 0x16);

    this->victory_condition_label->set_fixed_position(0x22, 0, 0x78, 0x12);
    this->victory_cond_type[0]->set_fixed_position(0x0e, 0x12, 0x14, 0x12);
    this->victory_cond_type[1]->set_fixed_position(0x0e, 0x26, 0x14, 0x12);
    this->victory_cond_type[2]->set_fixed_position(0x0e, 0x3a, 0x14, 0x12);
    this->victory_cond_type[3]->set_fixed_position(0x0e, 0x4e, 0x14, 0x12);
    this->victory_cond_type[4]->set_fixed_position(0x0e, 0x62, 0x14, 0x12);
    this->victory_cond_type_label[0]->set_fixed_position(0x22, 0x12, 0x78, 0x12);
    this->victory_cond_type_label[1]->set_fixed_position(0x22, 0x26, 0x78, 0x12);
    this->victory_cond_type_label[2]->set_fixed_position(0x22, 0x3a, 0x78, 0x12);
    this->victory_cond_type_label[3]->set_fixed_position(0x22, 0x4e, 0x78, 0x12);
    this->victory_cond_type_label[4]->set_fixed_position(0x22, 0x62, 0x78, 0x12);
    this->victory_score_label->set_fixed_position(0xa4, 0x12, 100, 0x12);
    this->victory_score->set_fixed_position(0xa4, 0x28, 100, 0x16);
    this->victory_time_label->set_fixed_position(0xa4, 0x12, 0xdc, 0x12);
    this->victory_time->set_fixed_position(0xa4, 0x28, 0xdc, 0x16);
    this->victory_cond_on[0]->set_fixed_position(0xa4, 0x12, 0x14, 0x12);
    this->victory_cond_on[1]->set_fixed_position(0xa4, 0x26, 0x14, 0x12);
    this->victory_cond_on[2]->set_fixed_position(0xa4, 0x3a, 0x14, 0x12);
    this->victory_cond_on[3]->set_fixed_position(0xa4, 0x4e, 0x14, 0x12);
    this->victory_cond_on[4]->set_fixed_position(0xa4, 0x62, 0x14, 0x12);
    this->victory_cond_on[5]->set_fixed_position(0xa4, 0x76, 0x14, 0x12);
    this->victory_label_conquest->set_fixed_position(0xb8, 0x12, 0x82, 0x12);
    this->victory_label_explore->set_fixed_position(0xb8, 0x26, 0x82, 0x12);
    this->victory_label_ruins->set_fixed_position(0xb8, 0x3a, 0x82, 0x12);
    this->victory_label_artifacts->set_fixed_position(0xb8, 0x4e, 0x82, 0x12);
    this->victory_label_discoveries->set_fixed_position(0xb8, 0x62, 0x82, 0x12);
    this->victory_amount_label->set_fixed_position(0x126, 0, 0x5a, 0x12);
    this->victory_condition_explore->set_fixed_position(0x126, 0x26, 0x3c, 0x12);
    this->victory_condition_ruins->set_fixed_position(0x126, 0x3a, 0x3c, 0x12);
    this->victory_condition_artifacts->set_fixed_position(0x126, 0x4e, 0x3c, 0x12);
    this->victory_condition_discoveries->set_fixed_position(0x126, 0x62, 0x3c, 0x12);
    this->victory_and_or[0]->set_fixed_position(0x180, 0x12, 0x14, 0x12);
    this->victory_and_or[1]->set_fixed_position(0x180, 0x26, 0x14, 0x12);
    this->victory_text_and_or[0]->set_fixed_position(0x194, 0x12, 0x5a, 0x12);
    this->victory_text_and_or[1]->set_fixed_position(0x194, 0x26, 0x5a, 0x12);

    for (int victory_index = 0; victory_index < 12; ++victory_index) {
        this->victory_button[victory_index]->set_fixed_position(
            ((victory_index / 4) * 0x30) + 0xdc,
            ((victory_index % 4) * 0x1a) + 0x1e, 0x2c, 0x16);
    }
    this->victory_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    this->victory_drop_down->set_fixed_position(4, 0x1c, 0xb4, 0x16);
    this->victory_condition_text->set_fixed_position(0xdc, 4, 0x8c, 0x16);
    this->victory_button_set_object->set_fixed_position(4, 0x38, 0x96, 0x16);
    this->victory_button_set_destination->set_fixed_position(4, 0x52, 0x96, 0x16);
    this->victory_button_go_to_dest->set_fixed_position(4, 0x6c, 0x96, 0x16);
    this->victory_amount_text->set_fixed_position(0xa0, 0x50, 0x3c, 0x16);
    this->victory_amount_input->set_fixed_position(0xa0, 0x66, 0x32, 0x16);
    this->victory_enemy_player_list->set_fixed_position(4, 0x66, 0x96, 0x16);
    this->victory_attribute_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_which_enemy_text->set_fixed_position(4, 0x50, 0x96, 0x16);
    this->victory_object_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_ages_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_tech_list->set_fixed_position(4, 0x38, 0xb4, 0x16);

    int message_y = 8;
    TTextPanel** message_label = this->message_button_label;
    do {
        ((TButtonPanel*)message_label[-5])->set_fixed_position(4, message_y, 0x1e, 0x12);
        (*message_label)->set_fixed_position(0x24, message_y, 0x82, 0x12);
        message_y += 0x19;
        ++message_label;
    } while (message_y < 0x85);

    this->message_input->set_position(7, 0xaf, 4, 0x28, 4, 0, 0, 0, 0, 0, 0, 0, 0);

    int cinematic_y = 0x16;
    TDropDownPanel** cinematic_input = this->cinematic_input;
    do {
        ((TTextPanel*)cinematic_input[-4])->set_fixed_position(4, cinematic_y - 0x12, 0xaa, 0x12);
        (*cinematic_input)->set_fixed_position(4, cinematic_y, 0xaa, 0x16);
        cinematic_y += 0x2c;
        ++cinematic_input;
    } while (cinematic_y < 0x9a);
    this->cinematic_label[3]->set_fixed_position(0xb2, 4, 0xaa, 0x12);
    this->cinematic_input[3]->set_fixed_position(0xb2, 0x16, 0xaa, 0x16);

    int option_y = 0x2c;
    TTextPanel** option_panel = this->options_label;
    do {
        ((TButtonPanel*)option_panel[1])->set_fixed_position(3, option_y, 0x14, 0x14);
        option_panel[0]->set_fixed_position(0x16, option_y, 0x87, 0x14);
        option_y += 0x1a;
        option_panel += 1;
    } while (option_y < 0x46);
    this->options_disable_tech_text->set_fixed_position(0xa0, 3, 0xa0, 0x16);
    this->options_player_list->set_fixed_position(3, 3, 0x96, 0x16);

    TTextPanel** option_text = this->options_disable_text;
    int disable_y = 0x1a;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0xa0, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0xb4, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);
    option_text = this->options_disable_text + 5;
    disable_y = 0x1a;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0x13b, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0x14f, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);
    option_text = this->options_disable_text + 10;
    disable_y = 6;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0x1d6, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0x1ea, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);

    this->Diplomacy_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    int diplomacy_x = 0x96;
    TButtonPanel** allied = this->Diplomacy_AlliedVictory;
    TButtonPanel** friend_box = this->Diplomacy_friend_box[0] + 1;
    do {
        ((TTextPanel*)allied[-0x25])->set_fixed_position(diplomacy_x, 0x1c, 0x1e, 0x16);
        (*(friend_box - 1))->set_fixed_position(diplomacy_x, 0x34, 0x1a, 0x12);
        (*friend_box)->set_fixed_position(diplomacy_x, 0x48, 0x1a, 0x12);
        friend_box[1]->set_fixed_position(diplomacy_x, 0x5c, 0x1a, 0x12);
        (*allied)->set_fixed_position(diplomacy_x, 0x70, 0x1a, 0x12);
        diplomacy_x += 0x1f;
        ++allied;
        friend_box += 3;
    } while (diplomacy_x < 0x18e);

    this->Diplomacy_status_label[0]->set_fixed_position(2, 0x34, 0x91, 0x16);
    this->Diplomacy_status_label[1]->set_fixed_position(2, 0x48, 0x91, 0x16);
    this->Diplomacy_status_label[2]->set_fixed_position(2, 0x5c, 0x91, 0x16);
    this->Diplomacy_status_label[3]->set_fixed_position(2, 0x70, 0x91, 0x16);
}
