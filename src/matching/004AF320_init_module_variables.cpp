// VA: 004AF320 TRIBE_Screen_Sed::init_module_variables (925 B)
// PDB source: scr_sed2.cpp:1145-1350
// Baseline: typed field ownership and the loop/pointer shapes shown by the
// scr_sed2.cpp source-line bands and original assembly.
// Attempt log:
// - Replaced the incomplete raw-offset placeholder with the complete
//   period-plausible member reconstruction.  The paired arrays are modeled
//   as their actual adjacent fields so the negative-index loop stores retain
//   their canonical ownership.
// - Replaced the decompiler-shaped negative-index paired-array loops with
//   natural indexed loops over each adjacent field pair; this restored the
//   925-byte size and left a localized reset-order/register hunk.
// - A natural fixed-count loop over the five button_bldg_pics entries lets
//   VC5 share its zero value with the following rep stosd and exactly restores
//   the remaining 50-byte scheduling hunk.  The loop is retained as the
//   plausible source form rather than five codegen-only assignments.
// - Promoted unit_list_info to its proven nested List_Info pointer type; code
//   generation was unchanged.

class TShape;
class TRIBE_Main_View;
class RGE_Diamond_Map_View;
class TMessagePanel;
class TPanel;
class TButtonPanel;
class TTextPanel;
class TDropDownPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TRIBE_Scenario_Editor_Panel_Object;
class TRIBE_World;

class TRIBE_Screen_Sed {
public:
    class List_Info;

    char gap_000[0x478];
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
    char gap_4BA[2];
    int message_type; // +0x4BC
    unsigned char need_to_save_flag; // +0x4C0
    unsigned char valid_save_spot_flag; // +0x4C1
    char gap_4C2[2];

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
    char gap_666[2];
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

    void init_module_variables();
};

void TRIBE_Screen_Sed::init_module_variables()
{
    TButtonPanel** ppTVar3;
    int iVar6;

    this->background_pic = (TShape*)0;
    this->main_view = (TRIBE_Main_View*)0;
    this->map_view = (RGE_Diamond_Map_View*)0;
    this->message_panel = (TMessagePanel*)0;
    this->bottom_panel = (TPanel*)0;
    this->set_player_first_flag = 0;
    ppTVar3 = this->scenario_mode_button;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->menu_button = (TButtonPanel*)0;
    this->help_button = (TButtonPanel*)0;
    this->map_type_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->map_type_button[iVar6] = (TButtonPanel*)0;
        this->map_type_text[iVar6] = (TTextPanel*)0;
    }
    this->default_terrain_drop = (TDropDownPanel*)0;
    this->default_terrain_label = (TTextPanel*)0;
    this->map_size_drop = (TDropDownPanel*)0;
    this->map_size_label = (TTextPanel*)0;
    this->map_style_drop = (TDropDownPanel*)0;
    this->map_style_label = (TTextPanel*)0;
    this->map_generating_text = (TTextPanel*)0;
    this->random_seed_label = (TTextPanel*)0;
    this->random_seed_input = (TEditPanel*)0;
    this->random_seed_used_label = (TTextPanel*)0;
    this->random_seed_used_text = (TTextPanel*)0;
    this->generate_map_button = (TButtonPanel*)0;
    this->brush_size_label = (TTextPanel*)0;
    this->paint_type_label = (TTextPanel*)0;
    this->paint_terrain_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->brush_size_button[iVar6] = (TButtonPanel*)0;
        this->brush_size_button_label[iVar6] = (TTextPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->paint_type_button[iVar6] = (TButtonPanel*)0;
        this->paint_type_button_label[iVar6] = (TTextPanel*)0;
    }
    this->paint_terrain_list = (TListPanel*)0;
    this->paint_terrain_scrollbar = (TScrollBarPanel*)0;
    this->paint_elevation_list = (TListPanel*)0;
    this->paint_elevation_scrollbar = (TScrollBarPanel*)0;
    this->player_advance_civilization_drop = (TDropDownPanel*)0;
    this->player_label = (TTextPanel*)0;
    this->player_starting_age_label = (TTextPanel*)0;
    this->player_build_text = (TTextPanel*)0;
    this->player_city_text = (TTextPanel*)0;
    this->player_list = (TDropDownPanel*)0;
    this->player_number_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->player_inven_label[iVar6] = (TTextPanel*)0;
        this->player_inven_input[iVar6] = (TEditPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->player_setting_label[iVar6] = (TTextPanel*)0;
        this->player_setting_drop[iVar6] = (TDropDownPanel*)0;
    }
    this->BuildList = (TDropDownPanel*)0;
    this->CityLayout = (TDropDownPanel*)0;
    this->AiRules = (TDropDownPanel*)0;
    this->unit_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->unit_mode_select[iVar6] = (TButtonPanel*)0;
        this->unit_mode_select_label[iVar6] = (TTextPanel*)0;
    }
    this->unit_list = (TListPanel*)0;
    this->unit_scrollbar = (TScrollBarPanel*)0;
    this->unit_list_info = (List_Info*)0;
    this->button_unit_pics = (TShape*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6)
        this->button_bldg_pics[iVar6] = (TShape*)0;
    this->object_panel = (TRIBE_Scenario_Editor_Panel_Object*)0;
    this->unit_list_size = 0;
    ppTVar3 = this->victory_cond_on;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->victory_and_or[iVar6] = (TButtonPanel*)0;
        this->victory_text_and_or[iVar6] = (TTextPanel*)0;
    }
    this->victory_amount_label = (TTextPanel*)0;
    this->victory_long_label = (TTextPanel*)0;
    this->victory_condition_label = (TTextPanel*)0;
    this->victory_label_conquest = (TTextPanel*)0;
    this->victory_label_explore = (TTextPanel*)0;
    this->victory_label_explore_percent = (TTextPanel*)0;
    this->victory_label_ruins = (TTextPanel*)0;
    this->victory_label_artifacts = (TTextPanel*)0;
    this->victory_label_discoveries = (TTextPanel*)0;
    this->victory_label_gold = (TTextPanel*)0;
    this->victory_condition_explore = (TEditPanel*)0;
    this->victory_condition_ruins = (TEditPanel*)0;
    this->victory_condition_artifacts = (TEditPanel*)0;
    this->victory_condition_discoveries = (TEditPanel*)0;
    this->victory_condition_gold = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->victory_cond_type_label[iVar6] = (TTextPanel*)0;
        this->victory_cond_type[iVar6] = (TButtonPanel*)0;
    }
    this->victory_score_label = (TTextPanel*)0;
    this->victory_score = (TDropDownPanel*)0;
    this->victory_time_label = (TTextPanel*)0;
    this->victory_time = (TDropDownPanel*)0;
    ppTVar3 = this->victory_button;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->victory_drop_down = (TDropDownPanel*)0;
    this->victory_object_list = (TDropDownPanel*)0;
    this->victory_player_list = (TDropDownPanel*)0;
    this->victory_ages_list = (TDropDownPanel*)0;
    this->victory_tech_list = (TDropDownPanel*)0;
    this->victory_button_set_object = (TButtonPanel*)0;
    this->victory_button_set_destination = (TButtonPanel*)0;
    this->victory_button_go_to_dest = (TButtonPanel*)0;
    this->victory_condition_text = (TTextPanel*)0;
    this->victory_condition_type = (TTextPanel*)0;
    this->victory_amount_text = (TTextPanel*)0;
    this->victory_amount_input = (TEditPanel*)0;
    this->victory_enemy_player_list = (TDropDownPanel*)0;
    this->victory_attribute_list = (TDropDownPanel*)0;
    this->victory_which_enemy_text = (TTextPanel*)0;
    this->victory_object_scrollbar = (TScrollBarPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->message_button[iVar6] = (TButtonPanel*)0;
        this->message_button_label[iVar6] = (TTextPanel*)0;
    }
    this->message_input = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->cinematic_label[iVar6] = (TTextPanel*)0;
        this->cinematic_input[iVar6] = (TDropDownPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 1; ++iVar6) {
        this->options_label[iVar6] = (TTextPanel*)0;
        this->options_button[iVar6] = (TButtonPanel*)0;
    }
    this->options_player_list = (TDropDownPanel*)0;
    this->options_disable_tech_text = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 0x10; ++iVar6) {
        this->options_disable_button[iVar6] = (TButtonPanel*)0;
        this->options_disable_text[iVar6] = (TTextPanel*)0;
    }
    this->Diplomacy_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 8; ++iVar6) {
        this->Diplomacy_player_text[iVar6] = (TTextPanel*)0;
        this->Diplomacy_friend_box[iVar6][0] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][1] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][2] = (TButtonPanel*)0;
        this->Diplomacy_AlliedVictory[iVar6] = (TButtonPanel*)0;
    }
    this->Diplomacy_status_label[0] = (TTextPanel*)0;
    this->Diplomacy_status_label[1] = (TTextPanel*)0;
    this->Diplomacy_status_label[2] = (TTextPanel*)0;
    this->Diplomacy_status_label[3] = (TTextPanel*)0;
    this->world = (TRIBE_World*)0;
}
