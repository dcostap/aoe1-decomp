#include "../include/TRIBE_Screen_Sed.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Diamond_Map.h"
#include "../include/RGE_Diamond_Map_View.h"
#include "../include/RGE_Font.h"
#include "../include/RGE_Main_View.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_View.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TDropDownPanel.h"
#include "../include/TListPanel.h"
#include "../include/TMessagePanel.h"
#include "../include/TRegistry.h"
#include "../include/TRIBE_Dialog_Sed_Menu.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Main_View.h"
#include "../include/TRIBE_Screen_Sed_Open.h"
#include "../include/TRIBE_World.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <stdio.h>
#include <string.h>

static const char* kScrSedSourcePath = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp";

static char kScenarioEditorScreenName[] = "Scenario Editor Screen";
static char kScenarioMenuDialogName[] = "Scenario Menu Dialog";
static char kSaveGameScreenName[] = "Save Game Screen";
static char kQuitSaveDialogName[] = "QuitSaveDialog";
static char kOpenSaveDialogName[] = "OpenSaveDialog";
static char kNewSaveDialogName[] = "NewSaveDialog";

static int command_save(TRIBE_Screen_Sed* this_, unsigned char param_1, unsigned char param_2);

static void init_module_variables(TRIBE_Screen_Sed* this_) {
    // TODO: STUB (partial): scr_sed2.cpp.decomp has a full initializer; this just nulls fields we use.
    if (!this_) return;

    this_->background_pic = nullptr;
    this_->main_view = nullptr;
    this_->map_view = nullptr;
    this_->message_panel = nullptr;
    this_->bottom_panel = nullptr;

    for (int i = 0; i < 10; ++i) this_->scenario_mode_button[i] = nullptr;
    this_->menu_button = nullptr;
    this_->help_button = nullptr;

    for (int i = 0; i < 3; ++i) {
        this_->map_type_button[i] = nullptr;
        this_->map_type_text[i] = nullptr;
    }
    this_->map_type_label = nullptr;

    for (int i = 0; i < 5; ++i) {
        this_->brush_size_button[i] = nullptr;
        this_->brush_size_button_label[i] = nullptr;
    }
    for (int i = 0; i < 3; ++i) {
        this_->paint_type_button[i] = nullptr;
        this_->paint_type_button_label[i] = nullptr;
    }

    this_->world = nullptr;
    this_->unit_list_info = nullptr;
    this_->button_unit_pics = nullptr;
    for (int i = 0; i < 5; ++i) this_->button_bldg_pics[i] = nullptr;
    this_->object_panel = nullptr;
}

static void set_player_active(TRIBE_Screen_Sed* this_, short player_num, int active) {
    // Decomp-first transliteration. Source of truth: scr_sed.cpp.decomp @ 0x004AB2B0
    if (!this_ || !this_->world || !this_->world->scenario) return;
    this_->world->scenario->Set_player_Active((int)player_num, active);
}

static void SavePlayerActiveStatus(TRIBE_Screen_Sed* this_) {
    // TODO: STUB (partial): Full parity in scr_sed2.cpp.decomp @ 0x004B2C50
    if (!this_ || !this_->world || !this_->world->scenario) return;

    // TODO: STUB - Best-effort handling; replace with strict scr_sed parity for active-player propagation.
    int active_players = 2;
    if (this_->player_number_list) {
        active_players = (int)this_->player_number_list->get_line() + 1;
        if (active_players < 1) active_players = 1;
    }

    // Scenario uses player indices starting at 0; keep Gaia and others untouched.
    for (int i = 0; i < 8; ++i) {
        this_->world->scenario->Set_player_Active(i, (i < active_players) ? 1 : 0);
    }
}

static void set_panel_info(TRIBE_Screen_Sed* this_) {
    // Decomp-first transliteration (small).
    if (!this_ || !rge_base_game) return;

    if (this_->main_view) {
        RGE_View* view = (RGE_View*)this_->main_view;
        view->world = (RGE_Game_World*)this_->world;
        view->player = rge_base_game->get_player();
        view->map = (this_->world != nullptr) ? this_->world->map : nullptr;
    }

    if (this_->map_view) {
        RGE_Diamond_Map* map = (RGE_Diamond_Map*)this_->map_view;
        map->set_world((RGE_Game_World*)this_->world);
        map->set_player(rge_base_game->get_player());
        map->set_main_view((RGE_View*)this_->main_view);
    }
}

static void set_map_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::MapType param_1, int /*param_2*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AA740
    if (!this_) return;
    if (param_1 == TRIBE_Screen_Sed::MapTypeNone) return;
    this_->map_type = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_mp_victory_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::VictoryType param_1, int /*param_2*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AA8F0
    if (!this_) return;
    if (param_1 == TRIBE_Screen_Sed::VictoryTypeNone) return;
    this_->mp_victory_type = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_brush_size(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::BrushSize param_1) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AAA90
    if (!this_ || param_1 == TRIBE_Screen_Sed::BrushSizeNone) return;
    this_->brush_size = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_paint_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::PaintType param_1, int /*param_2*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AAB30
    if (!this_ || param_1 == TRIBE_Screen_Sed::PaintTypeNone) return;
    this_->paint_type = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_player(TRIBE_Screen_Sed* this_, short player_num, unsigned char /*param_2*/, unsigned char /*param_3*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AB080
    if (!this_) return;
    this_->player_num = player_num;
}

static void set_unit_player(TRIBE_Screen_Sed* this_, short player_num) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AB300
    if (!this_) return;
    if (this_->unit_player_list) {
        this_->unit_player_list->set_line(player_num);
    }
}

static void set_message_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::MessageType param_1, int /*param_2*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004ACB90
    if (!this_) return;
    if (param_1 == TRIBE_Screen_Sed::MessageTypeNone) return;
    this_->message_type = param_1;
}

static void set_scenario_mode(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::ScenarioMode param_1) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004A9AA0
    if (!this_) return;
    this_->scenario_mode = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_unit(TRIBE_Screen_Sed* this_, short /*param_1*/) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AC0C0
    if (!this_) return;
}

static void set_string(TRIBE_Screen_Sed* this_, char* param_2, long param_3, int param_4) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A91E0
    if (!this_ || !param_2) return;
    sprintf(param_2, "str_%ld_%d", param_3, param_4);
}

static int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, long param_4, int param_5) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9260
    if (!this_) return 0;
    return this_->create_button(param_2, param_3, param_4, 0, 0, 0, 0, 0, 10, param_5, 0);
}

static int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, char* param_4, char* param_5, char* /*param_6*/, char* /*param_7*/) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9320
    if (!this_) return 0;
    return this_->create_button(param_2, param_3, param_4, param_5, 0, 0, 0, 0, 10, 1, 0);
}

static int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, long param_4) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9460
    if (!this_) return 0;
    return this_->create_text(param_2, param_3, (int)param_4, 0, 0, 0, 0, 0, 0, 0, 0);
}

static int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, char* param_4) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9530
    if (!this_) return 0;
    return this_->create_text(param_2, param_3, param_4, 0, 0, 0, 0, 0, 0, 0, 0);
}

static int create_input(TRIBE_Screen_Sed* this_, TPanel* param_2, TInputPanel** param_3, char* param_4, short param_5, FormatType param_6) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9600
    if (!this_) return 0;
    return this_->create_input(param_2, param_3, param_4, param_5, param_6, 0, 0, 0, 0, 0);
}

static int create_edit(TRIBE_Screen_Sed* this_, TPanel* param_2, TEditPanel** param_3, char* param_4, short param_5, FormatType param_6, int param_7, int param_8) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A96D0
    if (!this_) return 0;
    return this_->create_edit(param_2, param_3, param_4, param_5, param_6, 0, 0, 0, 0, 0, param_7, param_8);
}

static int create_drop_down(TRIBE_Screen_Sed* this_, TPanel* param_2, TDropDownPanel** param_3) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A97B0
    if (!this_) return 0;
    return this_->create_drop_down(param_2, param_3, 0, 0, 0, 0, 0, 0, 0);
}

static int SetupListOfTerrain(TRIBE_Screen_Sed* this_, TListPanel* param_2) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9C40
    if (!this_ || !param_2) return 0;
    return 1;
}

static int create_list(TRIBE_Screen_Sed* this_, TPanel* param_2, TListPanel** param_3, TScrollBarPanel** param_4) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004A9D60
    if (!this_) return 0;
    const int created = this_->create_list(param_2, param_3, 0, 0, 0, 0, 0);
    if (created != 0 && param_3 && *param_3 != nullptr && param_4) {
        this_->create_scrollbar(param_2, param_4, nullptr, 0, 0, 0, 0, 0);
    }
    return created;
}

static int FUN_004aa6e6() {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AA6E6
    return 0;
}

static void set_paint_object_mode(TRIBE_Screen_Sed* this_) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AA760
    if (!this_) return;
}

static int FUN_004aab4a() {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AAB4A
    return 0;
}

static void set_terrain(TRIBE_Screen_Sed* this_, short param_2) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AAD20
    if (!this_) return;
    if (this_->paint_terrain_list) {
        this_->paint_terrain_list->set_line(param_2);
    }
}

static void set_elevation(TRIBE_Screen_Sed* this_, short param_2) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AADF0
    if (!this_) return;
    if (this_->paint_elevation_list) {
        this_->paint_elevation_list->set_line(param_2);
    }
}

static int TRIBE_Screen_Sed_unit_list_compare(void* param_1, void* param_2) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AB2F0
    const TRIBE_Screen_Sed::List_Info* a = (const TRIBE_Screen_Sed::List_Info*)param_1;
    const TRIBE_Screen_Sed::List_Info* b = (const TRIBE_Screen_Sed::List_Info*)param_2;
    if (!a || !b) return 0;
    return (int)a->id - (int)b->id;
}

static int FUN_004abc31() {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004ABC31
    return 0;
}

static int FUN_004ad06e() {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AD06E
    return 0;
}

static void command_cancel(TRIBE_Screen_Sed* this_) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AD2B0
    if (!this_) return;
}

static void command_outline(TRIBE_Screen_Sed* this_) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AD6A0
    if (!this_) return;
}

static void command_player(TRIBE_Screen_Sed* this_, int param_2) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AD6C0
    if (!this_) return;
    set_player(this_, (short)param_2, 0, 0);
}

static void command_save_as(TRIBE_Screen_Sed* this_, unsigned char param_2) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004ADC70
    if (!this_) return;
    (void)param_2;
    this_->popupOKDialog((char*)"Save As not implemented yet.", (char*)0, 0x1c2, 100);
}

static char* scenario_get_default_name(TRIBE_Screen_Sed* /*this_*/) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004ADFA0
    static char s_default_name[] = "default.scx";
    return s_default_name;
}

static void command_quick_save(TRIBE_Screen_Sed* this_) {
    // TODO: STUB (partial): Full parity in scr_sed.cpp.decomp @ 0x004AE040
    if (!this_) return;
    (void)command_save(this_, 1, 0);
}

static char* scenario_save_defaulted(TRIBE_Screen_Sed* this_) {
    // TODO: Full transliteration pending. Source of truth: scr_sed.cpp.decomp @ 0x004AE050
    return scenario_get_default_name(this_);
}

static int command_new_map(TRIBE_Screen_Sed* this_, char* scenario_filename, int is_multi_player, int param_4, int param_5, int param_6, int show_status) {
    // TODO: STUB (partial): Full parity requires scr_sed.cpp.decomp @ 0x004AD340.
    (void)is_multi_player;
    (void)param_4;
    (void)param_5;
    (void)param_6;

    if (!this_ || !rge_base_game) return 0;
    this_->need_to_save_flag = 0;

    if (rge_base_game->world == nullptr) {
        if (show_status != 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44d, (char*)0, -1); // "Loading game data..."
        }
        const int ok = ((TRIBE_Game*)rge_base_game)->load_game_data();
        if (show_status != 0) {
            ((TRIBE_Game*)rge_base_game)->close_status_message();
        }
        if (ok == 0) return 0;
    }

    this_->world = (TRIBE_World*)rge_base_game->world;

    // TODO: STUB - Best-effort handling; replace with strict scr_sed parity for scenario-name propagation.
    if (scenario_filename != nullptr) {
        rge_base_game->setScenarioName(scenario_filename);
    }

    return (this_->world != nullptr) ? 1 : 0;
}

static int need_to_save(TRIBE_Screen_Sed* this_) {
    return (this_ != nullptr && this_->need_to_save_flag != 0) ? 1 : 0;
}

static int command_menu(TRIBE_Screen_Sed* this_) {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AD270
    if (!this_) return 0;

    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this_);
    if (dlg != nullptr && dlg->error_code != 0) {
        delete dlg;
        return 0;
    }

    if (panel_system) {
        panel_system->setCurrentPanel(kScenarioMenuDialogName, 0);
    }
    return 1;
}

static void command_new(TRIBE_Screen_Sed* this_) {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AD300
    if (!this_) return;

    if (need_to_save(this_) != 0) {
        // "Do you want to save your changes to this scenario?"
        this_->popupYesNoCancelDialog(0x2447, kNewSaveDialogName, 0x1c2, 100);
        return;
    }

    if (rge_base_game) {
        ((TRIBE_Game*)rge_base_game)->start_scenario_editor((char*)0, 0);
    }
}

static void command_open(TRIBE_Screen_Sed* this_) {
    // Source of truth intent: scr_sed.cpp.decomp @ 0x004AD590
    if (!this_) return;
    if (need_to_save(this_) != 0) {
        this_->popupYesNoCancelDialog(0x2447, kOpenSaveDialogName, 0x1c2, 100);
        return;
    }

    TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
    if (open == nullptr) return;
    if (panel_system == nullptr) {
        delete open;
        return;
    }
    if (open->error_code != 0) {
        delete open;
        return;
    }

    {
        panel_system->add_panel((TPanel*)open);
        panel_system->setCurrentPanel((char*)"Scenario Editor Open", 0);
    }
}

static void command_quit(TRIBE_Screen_Sed* this_) {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AD6A0
    if (!this_ || !rge_base_game) return;

    if (need_to_save(this_) != 0) {
        this_->popupYesNoCancelDialog(0x2447, kQuitSaveDialogName, 0x1c2, 100);
        return;
    }

    const int ok = ((TRIBE_Game*)rge_base_game)->start_menu();
    if (ok == 0) {
        rge_base_game->close();
        return;
    }

    if (panel_system) {
        panel_system->destroyPanel(kScenarioEditorScreenName);
    }
}

static int command_save(TRIBE_Screen_Sed* this_, unsigned char param_1, unsigned char param_2) {
    // TODO: STUB: save pipeline parity requires scr_sed.cpp.decomp @ 0x004AD700.
    (void)param_1;
    (void)param_2;
    if (!this_) return 0;
    this_->popupOKDialog((char*)"Save not implemented yet.", (char*)0, 0x1c2, 100);
    return 0;
}

static void create_all_buttons_etc(TRIBE_Screen_Sed* this_) {
    // TODO: STUB (partial): Full parity is scr_sed2.cpp.decomp @ 0x004AF6C0.
    if (!this_) return;

    // Scenario mode buttons (Map/Terrain/Players/Units/Diplomacy/Individual Victory/Global Victory/Options/Messages/Cinematics)
    const long mode_ids[10] = { 0x271a, 0x271b, 0x271c, 0x271d, 0x2722, 0x271e, 0x2723, 0x2721, 0x271f, 0x2720 };
    for (int i = 0; i < 10; ++i) {
        (void)this_->create_button((TPanel*)this_, &this_->scenario_mode_button[i], mode_ids[i], 0, 0, 0, 0, 0, 10, 1, 0);
        if (this_->scenario_mode_button[i]) {
            this_->scenario_mode_button[i]->set_z_order('\x01', 0);
        }
    }

    (void)this_->create_button((TPanel*)this_, &this_->menu_button, 0x2724, 0, 0, 0, 0, 0, 10, 1, 0);
    (void)this_->create_button((TPanel*)this_, &this_->help_button, 0x0fa9, 0, 0, 0, 0, 0, 10, 1, 0);
}

static void position_panels(TRIBE_Screen_Sed* this_) {
    // TODO: STUB (partial): Full parity is scr_sed2.cpp.decomp @ 0x004B29E0.
    if (!this_ || !rge_base_game || !rge_base_game->draw_area) return;

    const long screen_w = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_wid : rge_base_game->draw_area->Width;
    const long screen_h = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_hgt : rge_base_game->draw_area->Height;
    const long bottom_h = 0xA1; // matches common original UI split.

    if (this_->bottom_panel) {
        this_->bottom_panel->set_rect(0, screen_h - bottom_h, screen_w, bottom_h);
    }
    if (this_->main_view) {
        ((TPanel*)this_->main_view)->set_rect(0, 0, screen_w, screen_h - bottom_h);
    }
    if (this_->map_view) {
        ((TPanel*)this_->map_view)->set_rect(screen_w - 0xA1, 0, 0xA1, 0xA1);
    }
    if (this_->message_panel) {
        ((TPanel*)this_->message_panel)->set_rect(0, 0, screen_w - 0xA1, 0x28);
    }
}

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* scenario_name, int is_multi_player_in)
    // Partially verified. Source of truth: scr_sed.cpp.asm @ 0x004A81E0
    : TScreenPanel(kScenarioEditorScreenName) {
    this->is_multi_player = 0;
    this->scenario_mode = ScenarioModeNone;
    this->map_type = MapTypeNone;
    this->mp_victory_type = VictoryTypeConquest;
    this->brush_size = BrushSizeNone;
    this->paint_type = PaintTypeNone;
    this->player_num = 1;
    this->message_type = MessageTypeNone;
    this->SelectedObject = nullptr;
    this->DestinationObject = nullptr;
    this->CurrentPlayer = 0;
    this->need_to_save_flag = 0;
    this->valid_save_spot_flag = 0;

    init_module_variables(this);

    this->update_interval = 200;
    this->last_update_time = debug_timeGetTime(kScrSedSourcePath, 0x117);
    this->map_redraw_interval = 1000;
    this->last_map_redraw_time = debug_timeGetTime(kScrSedSourcePath, 0x11a);

    this->save_text_color = 0;
    this->save_window_color = 0;
    this->changed_system_colors = 0;
    this->CurrentVictory = 0;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    rge_base_game->set_prog_mode(7);

    if (command_new_map(this, scenario_name, is_multi_player_in, 0, 0x90, 0x90, 1) == 0) {
        this->error_code = 1;
        return;
    }

    // If we're editing the default scenario, mark as needing a save (matches original startup behavior).
    if (rge_base_game->registry != nullptr && scenario_name != nullptr) {
        const int game_file_no = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        char temp_name[260];
        sprintf(temp_name, "default%d.scx", game_file_no);
        if (strcmp(scenario_name, temp_name) == 0) {
            this->need_to_save_flag = 1;
        }
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr5", 0xC387, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);

    // Main view.
    this->main_view = new TRIBE_Main_View();
    if (this->main_view == nullptr || ((RGE_View*)this->main_view)->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, (uchar)0xA1) == 0) {
        this->error_code = 1;
        return;
    }
    this->main_view->set_help_info(-1, -1);

    // Diamond minimap.
    this->map_view = new RGE_Diamond_Map_View();
    if (this->map_view == nullptr || this->map_view->error_code != 0 ||
        ((RGE_Diamond_Map*)this->map_view)->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, (uchar)0xA1, 0, rge_base_game->map_save_area) == 0) {
        this->error_code = 1;
        return;
    }
    ((RGE_Diamond_Map*)this->map_view)->set_bitmap((char*)"map640.bmp", 0xC4E1);
    ((RGE_Diamond_Map*)this->map_view)->set_main_view((RGE_View*)this->main_view);
    ((RGE_Main_View*)this->main_view)->map_view = (TPanel*)this->map_view;

    // Message panel.
    {
        RGE_Font* font = rge_base_game->get_font(0xb);
        this->message_panel = (font != nullptr) ? new TMessagePanel(font->font, font->font_wid, font->font_hgt) : new TMessagePanel();
        if (this->message_panel == nullptr || this->message_panel->setup(rge_base_game->draw_area, this->main_view, 0, 0, 0, 0, 0) == 0) {
            this->error_code = 1;
            return;
        }
    }

    // Bottom panel container.
    this->bottom_panel = new TPanel();
    if (this->bottom_panel == nullptr || this->bottom_panel->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    create_all_buttons_etc(this);

    // TODO: STUB - Best-effort processing; replace with strict scr_sed parity for player-state/name flow.
    int player_num_line = 1;
    if (scenario_name == nullptr || *scenario_name == '\0') {
        set_player_active(this, 0, 1);
        set_player_active(this, 1, 1);
        player_num_line = 1;
    } else {
        if (this->world && this->world->scenario) {
            if (strstr(scenario_name, ".scn") != nullptr || strstr(scenario_name, ".SCN") != nullptr) {
                char name[260];
                int i = 0;
                while (scenario_name[i] != '\0' && scenario_name[i] != '.' && i < (int)sizeof(name) - 1) {
                    name[i] = scenario_name[i];
                    ++i;
                }
                name[i] = '\0';
                char scx_name[260];
                sprintf(scx_name, "%s.scx", name);
                this->world->scenario->Set_scenario_name(scx_name);
            }

            int i = 0;
            while (i < 8) {
                if (this->world->scenario->Get_player_Active(i) == 0) break;
                ++i;
            }
            player_num_line = i - 1;
        }
    }
    if (this->player_number_list) {
        this->player_number_list->set_line(player_num_line);
    }
    SavePlayerActiveStatus(this);

    this->set_curr_child(this->bottom_panel);
    position_panels(this);
    set_panel_info(this);

    set_map_type(this, MapTypeBlank, 0);
    set_mp_victory_type(this, VictoryTypeStandard, 0);
    set_brush_size(this, BrushSizeVerySmall);
    set_paint_type(this, PaintTypeTerrain, 0);
    set_player(this, 1, '\0', '\0');
    set_unit_player(this, 1);
    set_message_type(this, MessageTypeDescription, 0);
    set_scenario_mode(this, ScenarioModeMap);
    set_unit(this, -1);
    if (this->world && this->world->map) {
        this->world->map->set_map_visible('\x01');
        this->world->map->set_map_fog('\0');
    }
}

TRIBE_Screen_Sed::~TRIBE_Screen_Sed() {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004A94A0
    if (panel_system) {
        panel_system->destroyPanel(kQuitSaveDialogName);
        panel_system->destroyPanel(kOpenSaveDialogName);
        panel_system->destroyPanel(kNewSaveDialogName);
        panel_system->destroyPanel(kSaveGameScreenName);
        panel_system->destroyPanel(kScenarioMenuDialogName);
    }

    for (int i = 0; i < 10; ++i) {
        this->delete_panel((TPanel**)&this->scenario_mode_button[i]);
    }
    this->delete_panel((TPanel**)&this->menu_button);
    this->delete_panel((TPanel**)&this->help_button);

    this->delete_panel((TPanel**)&this->bottom_panel);
    this->delete_panel((TPanel**)&this->message_panel);
    this->delete_panel((TPanel**)&this->main_view);
    this->delete_panel((TPanel**)&this->map_view);

    if (this->background_pic) {
        delete this->background_pic;
        this->background_pic = nullptr;
    }

    if (this->world) {
        this->world->del_game_info();
    }
}

long TRIBE_Screen_Sed::handle_size(long param_1, long param_2) {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AB710
    TPanel::handle_size(param_1, param_2);
    position_panels(this);
    TPanel::handle_size(param_1, param_2);
    return 0;
}

long TRIBE_Screen_Sed::handle_idle() {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AB740
    if (rge_base_game && rge_base_game->prog_mode == 7) {
        const unsigned long now = debug_timeGetTime(kScrSedSourcePath, 0x8b1);
        const unsigned long dt = now - this->last_update_time;
        if ((unsigned long)this->update_interval <= dt) {
            this->last_update_time = now;

            TPanel* modal = (panel_system != nullptr) ? panel_system->modalPanelValue : nullptr;
            if (modal == nullptr) {
                if (this->main_view) ((TPanel*)this->main_view)->set_redraw(TPanel::Redraw);

                const unsigned long map_dt = now - this->last_map_redraw_time;
                if ((unsigned long)this->map_redraw_interval <= map_dt) {
                    if (this->map_view) ((TPanel*)this->map_view)->set_redraw(TPanel::Redraw);
                    this->last_map_redraw_time = now;
                }
            }
        }
    }

    return TPanel::handle_idle();
}

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // TODO: STUB (partial): scr_sed.cpp.decomp @ 0x004AB7D0 contains full editor hotkeys.
    (void)param_2;
    (void)param_3;
    (void)param_5;

    if (param_4 != 0) {
        // ESC: open menu.
        if (param_1 == 0x1b) {
            (void)command_menu(this);
            return 1;
        }
        // Ctrl+S: save.
        if ((param_1 == 'S' || param_1 == 's') && param_4 != 0) {
            (void)command_save(this, 0, 0);
            return 1;
        }
    }

    return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5);
}

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    (void)param_3;
    (void)param_4;

    if (param_1 == nullptr) {
        return 0;
    }

    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->menu_button) {
            return command_menu(this);
        }
        if ((TButtonPanel*)param_1 == this->help_button) {
            this->popupOKDialog((char*)"Help not implemented yet.", (char*)0, 0x1c2, 100);
            return 1;
        }
    }

    // Save prompt dialogs: TMessageDialog forwards action to parent with param_2 = 0/1/2.
    const char* panel_name = param_1->panelName();
    if (panel_name != nullptr) {
        if (strcmp(panel_name, kQuitSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kQuitSaveDialogName);
                    command_quit(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kQuitSaveDialogName);
                command_quit(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kQuitSaveDialogName);
            }
            return 1;
        }

        if (strcmp(panel_name, kOpenSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kOpenSaveDialogName);
                    command_open(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kOpenSaveDialogName);
                command_open(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kOpenSaveDialogName);
            }
            return 1;
        }

        if (strcmp(panel_name, kNewSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kNewSaveDialogName);
                    command_new(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kNewSaveDialogName);
                command_new(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kNewSaveDialogName);
            }
            return 1;
        }
    }

    return TScreenPanel::action(param_1, param_2, param_3, param_4);
}

void TRIBE_Screen_Sed::draw() {
    // Decomp intent: scr_sed.cpp.decomp @ 0x004AD0F0 (bevels/etc); keep minimal.
    TScreenPanel::draw();
}

void TRIBE_Screen_Sed::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Screen_Sed::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Sed::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Sed::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Sed::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Sed::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Sed::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Sed::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Sed::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Sed::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Sed::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Sed::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Sed::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Sed::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Sed::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Sed::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Sed::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Sed::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Sed::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Sed::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Sed::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Sed::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Sed::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Sed::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Sed::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Sed::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Sed::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Sed::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Sed::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Sed::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Sed::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Sed::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Sed::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Sed::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Sed::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Sed::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Sed::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }


#if 0 // TASK_227_SCR_SED_DECOMP_REFERENCE_BEGIN
// Auto-generated decompiler unit: scr_sed.cpp.decomp
// SourceMap: C:/msdev/work/age1_x1/scr_sed.cpp
#include "../include/common.h"

// Offset: 0x004A81E0
undefined TRIBE_Screen_Sed(TRIBE_Screen_Sed* this_, char* param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: __thiscall TRIBE_Screen_Sed::TRIBE_Screen_Sed(char *,int) */
    // 
    // TRIBE_Screen_Sed * __thiscall
    // TRIBE_Screen_Sed::TRIBE_Screen_Sed(TRIBE_Screen_Sed *this,char *param_1,int param_2)
    // 
    // {
    //   ulong uVar1;
    //   int iVar2;
    //   byte *pbVar3;
    //   long lVar4;
    //   RGE_Main_View *this_00;
    //   RGE_Diamond_Map_View *this_01;
    //   RGE_Diamond_Map *this_02;
    //   RGE_Font *pRVar5;
    //   TMessagePanel *pTVar6;
    //   TPanel *pTVar7;
    //   int iVar8;
    //   byte bVar9;
    //   byte *pbVar10;
    //   undefined4 *unaff_FS_OFFSET;
    //   bool bVar11;
    //   byte *unaff_retaddr;
    //   char name [260];
    //   char temp_name [260];
    //   undefined4 uStack_10;
    //   undefined4 uStack_c;
    //   code *pcStack_8;
    //   undefined4 local_4;
    //   
    //   local_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f453;
    //   uStack_c = *unaff_FS_OFFSET;
    //   *unaff_FS_OFFSET = &uStack_c;
    //   name._0_4_ = this;
    //   TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Scenario_Editor_Screen);
    //   local_4 = 0;
    //   this->_padding_ = (int)&_vftable_;
    //   this->is_multi_player = 0;
    //   this->scenario_mode = ScenarioModeNone;
    //   this->map_type = MapTypeNone;
    //   this->mp_victory_type = VictoryTypeConquest;
    //   this->brush_size = BrushSizeNone;
    //   this->paint_type = PaintTypeNone;
    //   this->player_num = 1;
    //   this->message_type = MessageTypeNone;
    //   this->SelectedObject = (RGE_Static_Object *)0x0;
    //   this->DestinationObject = (RGE_Static_Object *)0x0;
    //   this->CurrentPlayer = 0;
    //   this->need_to_save_flag = '\0';
    //   this->valid_save_spot_flag = '\0';
    //   init_module_variables(this);
    //   this->update_interval = 200;
    //   uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x117);
    //   this->last_update_time = uVar1;
    //   this->map_redraw_interval = 1000;
    //   uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x11a);
    //   this->last_map_redraw_time = uVar1;
    //   this->save_text_color = 0;
    //   this->save_window_color = 0;
    //   this->changed_system_colors = 0;
    //   this->CurrentVictory = 0;
    //   (**(code **)(rge_base_game->_padding_ + 0xc))(7);
    //   iVar2 = command_new_map(this,(char *)unaff_retaddr,(int)param_1,0,0x90,0x90,1);
    //   if (iVar2 == 0) {
    //     this->_padding_ = 1;
    //     goto LAB_004a8728;
    //   }
    //   iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    //   sprintf(temp_name,s_default_d_scx,iVar2);
    //   if (unaff_retaddr != (byte *)0x0) {
    //     pbVar10 = (byte *)temp_name;
    //     pbVar3 = unaff_retaddr;
    //     do {
    //       bVar9 = *pbVar3;
    //       bVar11 = bVar9 < *pbVar10;
    //       if (bVar9 != *pbVar10) {
    // LAB_004a8376:
    //         iVar2 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
    //         goto LAB_004a837b;
    //       }
    //       if (bVar9 == 0) break;
    //       bVar9 = pbVar3[1];
    //       bVar11 = bVar9 < pbVar10[1];
    //       if (bVar9 != pbVar10[1]) goto LAB_004a8376;
    //       pbVar3 = pbVar3 + 2;
    //       pbVar10 = pbVar10 + 2;
    //     } while (bVar9 != 0);
    //     iVar2 = 0;
    // LAB_004a837b:
    //     if (iVar2 == 0) {
    //       this->need_to_save_flag = '\x01';
    //     }
    //   }
    //   lVar4 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr5,0xc387,1);
    //   if (lVar4 != 0) {
    //     TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    //     this_00 = (RGE_Main_View *)operator_new(0x380);
    //     pcStack_8._0_1_ = 1;
    //     if (this_00 == (RGE_Main_View *)0x0) {
    //       this_00 = (RGE_Main_View *)0x0;
    //     }
    //     else {
    //       RGE_Main_View::RGE_Main_View(this_00);
    //       this_00->_padding_ = (int)&TRIBE_Main_View::_vftable_;
    //     }
    //     pcStack_8._0_1_ = 0;
    //     this->main_view = (TRIBE_Main_View *)this_00;
    //     if ((this_00 != (RGE_Main_View *)0x0) && (this_00->_padding_ == 0)) {
    //       lVar4 = RGE_View::setup((RGE_View *)this_00,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0,
    //                               0,0xa1,0,s_bordline);
    //       if (lVar4 != 0) {
    //         this_01 = (RGE_Diamond_Map_View *)operator_new(0x16c);
    //         pcStack_8._0_1_ = 2;
    //         if (this_01 == (RGE_Diamond_Map_View *)0x0) {
    //           this_02 = (RGE_Diamond_Map *)0x0;
    //         }
    //         else {
    //           this_02 = (RGE_Diamond_Map *)RGE_Diamond_Map_View::RGE_Diamond_Map_View(this_01);
    //         }
    //         pcStack_8._0_1_ = 0;
    //         this->map_view = (RGE_Diamond_Map_View *)this_02;
    //         if ((this_02 != (RGE_Diamond_Map *)0x0) && (this_02->_padding_ == 0)) {
    //           lVar4 = RGE_Diamond_Map::setup
    //                             (this_02,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0,0,0xa1,0,
    //                              rge_base_game->map_save_area);
    //           if (lVar4 != 0) {
    //             RGE_Diamond_Map::set_bitmap((RGE_Diamond_Map *)this->map_view,s_map640_bmp,0xc4e1);
    //             *(TRIBE_Main_View **)&this->map_view->field_0x150 = this->main_view;
    //             *(RGE_Diamond_Map_View **)&this->main_view->field_0x360 = this->map_view;
    //             TPanel::set_help_info((TPanel *)this->main_view,-1,-1);
    //             pRVar5 = RGE_Base_Game::get_font(rge_base_game,0xb);
    //             pTVar6 = (TMessagePanel *)operator_new(0x380);
    //             pcStack_8._0_1_ = 3;
    //             if (pTVar6 == (TMessagePanel *)0x0) {
    //               pTVar6 = (TMessagePanel *)0x0;
    //             }
    //             else {
    //               pTVar6 = (TMessagePanel *)
    //                        TMessagePanel::TMessagePanel
    //                                  (pTVar6,pRVar5->font,pRVar5->font_wid,pRVar5->font_hgt);
    //             }
    //             pcStack_8._0_1_ = 0;
    //             this->message_panel = pTVar6;
    //             if ((pTVar6 != (TMessagePanel *)0x0) && (pTVar6->_padding_ == 0)) {
    //               iVar2 = (**(code **)(pTVar6->_padding_ + 4))
    //                                 (this->_padding_,this->main_view,0,0,0,0,0);
    //               if (iVar2 != 0) {
    //                 pTVar7 = (TPanel *)operator_new(0xf4);
    //                 pcStack_8._0_1_ = 4;
    //                 if (pTVar7 == (TPanel *)0x0) {
    //                   pTVar7 = (TPanel *)0x0;
    //                 }
    //                 else {
    //                   pTVar7 = (TPanel *)TPanel::TPanel(pTVar7);
    //                 }
    //                 pcStack_8 = (code *)((uint)pcStack_8._1_3_ << 8);
    //                 this->bottom_panel = pTVar7;
    //                 if ((pTVar7 != (TPanel *)0x0) && (pTVar7->error_code == 0)) {
    //                   iVar2 = (**(code **)(pTVar7->_padding_ + 4))(this->_padding_,this,0,0,0,0,0);
    //                   if (iVar2 != 0) {
    //                     create_all_buttons_etc(this);
    //                     if ((unaff_retaddr == (byte *)0x0) || (*unaff_retaddr == 0)) {
    //                       set_player_active(this,0,1);
    //                       set_player_active(this,1,1);
    //                       iVar2 = 1;
    //                     }
    //                     else {
    //                       iVar2 = strstr(unaff_retaddr,s__scn);
    //                       if (iVar2 == 0) {
    //                         iVar2 = strstr(unaff_retaddr,s__SCN);
    //                         if (iVar2 != 0) goto LAB_004a8602;
    //                       }
    //                       else {
    // LAB_004a8602:
    //                         bVar9 = *unaff_retaddr;
    //                         pbVar10 = unaff_retaddr;
    //                         iVar2 = 0;
    //                         do {
    //                           iVar8 = iVar2;
    //                           pbVar10[(int)(name + -(int)unaff_retaddr)] = bVar9;
    //                           bVar9 = pbVar10[1];
    //                           pbVar10 = pbVar10 + 1;
    //                           iVar2 = iVar8 + 1;
    //                         } while (bVar9 != 0x2e);
    //                         name[iVar8 + 1] = '\0';
    //                         sprintf(unaff_retaddr,s__s_scx,name);
    //                         RGE_Scenario::Set_scenario_name
    //                                   ((RGE_Scenario *)this->world->_padding_,(char *)unaff_retaddr);
    //                       }
    //                       iVar2 = 0;
    //                       do {
    //                         iVar8 = RGE_Scenario::Get_player_Active
    //                                           ((RGE_Scenario *)this->world->_padding_,iVar2);
    //                         if (iVar8 == 0) break;
    //                         iVar2 = iVar2 + 1;
    //                       } while (iVar2 < 8);
    //                       iVar2 = iVar2 + -1;
    //                     }
    //                     TDropDownPanel::set_line(this->player_number_list,iVar2);
    //                     SavePlayerActiveStatus(this);
    //                     TPanel::set_curr_child((TPanel *)this,this->bottom_panel);
    //                     position_panels(this);
    //                     set_panel_info(this);
    //                     set_map_type(this,MapTypeBlank,0);
    //                     set_mp_victory_type(this,VictoryTypeStandard,0);
    //                     set_brush_size(this,BrushSizeVerySmall);
    //                     set_paint_type(this,PaintTypeTerrain,0);
    //                     set_player(this,1,'\0','\0');
    //                     set_unit_player(this,1);
    //                     set_message_type(this,MessageTypeDescription,0);
    //                     set_scenario_mode(this,ScenarioModeMap);
    //                     set_unit(this,-1);
    //                     RGE_Map::set_map_visible((RGE_Map *)this->world->_padding_,'\x01');
    //                     RGE_Map::set_map_fog((RGE_Map *)this->world->_padding_,'\0');
    //                     goto LAB_004a8728;
    //                   }
    //                 }
    //               }
    //             }
    //           }
    //         }
    //       }
    //     }
    //   }
    //   this->_padding_ = 1;
    // LAB_004a8728:
    //   *unaff_FS_OFFSET = uStack_10;
    //   return this;
    // }
    // 
    // 
}

// Offset: 0x004A8770
void set_panel_info(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_panel_info(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_panel_info(TRIBE_Screen_Sed *this)
    // 
    // {
    //   RGE_Player *pRVar1;
    //   
    //   RGE_View::set_world((RGE_View *)this->main_view,(RGE_Game_World *)this->world);
    //   pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_View::set_player((RGE_View *)this->main_view,pRVar1);
    //   RGE_Diamond_Map::set_world((RGE_Diamond_Map *)this->map_view,(RGE_Game_World *)this->world);
    //   pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_Diamond_Map::set_player((RGE_Diamond_Map *)this->map_view,pRVar1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004A87D0
void set_string(TRIBE_Screen_Sed* this_, char* param_2, long param_3, int param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_string(char *,long,int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_string(TRIBE_Screen_Sed *this,char *param_1,long param_2,int param_3)
    // 
    // {
    //   TPanel::get_string((TPanel *)this,param_2,param_1,param_3);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004A87F0
int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, long param_4, int param_5) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: str1 */
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_button(class TPanel *,class TButtonPanel *
    //    *,long,int) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_button
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2,long param_3,int param_4)
    // 
    // {
    //   int iVar1;
    //   char str1 [120];
    //   
    //                     /* language.dll match for 0x78: "10" */
    //   TPanel::get_string((TPanel *)this,param_3,str1 + 4,0x78);
    //   iVar1 = create_button(this,param_1,param_2,str1 + 4,(char *)0x0,(char *)0x0,(char *)0x0);
    //   return iVar1;
    // }
    // 
    // 
}

// Offset: 0x004A8840
int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, char* param_4, char* param_5, char* param_6, char* param_7) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_button(class TPanel *,class TButtonPanel *
    //    *,char *,char *,char *,char *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_button
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2,char *param_3,char *param_4
    //           ,char *param_5,char *param_6)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_button
    //                     ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,0,0,0,0,10,1,0);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   if (param_5 != (char *)0x0) {
    //     TButtonPanel::set_text(*param_2,2,param_5);
    //   }
    //   if (param_6 != (char *)0x0) {
    //     TButtonPanel::set_text(*param_2,3,param_6);
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   if (this->_padding_ != 0) {
    //     TButtonPanel::set_bevel_info
    //               (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
    //                (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
    //                ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
    //   }
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A8910
int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, long param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_text(class TPanel *,class TTextPanel * *,long)
    //     */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_text
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TTextPanel **param_2,long param_3)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_text((TEasy_Panel *)this,param_1,param_2,param_3,0,0,0,0,10,0,0,0);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A8960
int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, char* param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_text(class TPanel *,class TTextPanel * *,char
    //    *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_text
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TTextPanel **param_2,char *param_3)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_text((TEasy_Panel *)this,param_1,param_2,param_3,0,0,0,0,10,0,0,0);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A89B0
int create_input(TRIBE_Screen_Sed* this_, TPanel* param_2, TInputPanel** param_3, char* param_4, short param_5, FormatType param_6) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_input(class TPanel *,class TInputPanel *
    //    *,char *,short,enum TInputPanel::FormatType) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_input
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TInputPanel **param_2,char *param_3,short param_4,
    //           FormatType param_5)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_input
    //                     ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,param_5,0,0,0,0,10);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A8A00
int create_edit(TRIBE_Screen_Sed* this_, TPanel* param_2, TEditPanel** param_3, char* param_4, short param_5, FormatType param_6, int param_7, int param_8) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_edit(class TPanel *,class TEditPanel * *,char
    //    *,short,enum TEditPanel::FormatType,int,int) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_edit
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TEditPanel **param_2,char *param_3,short param_4,
    //           FormatType param_5,int param_6,int param_7)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_edit
    //                     ((TEasy_Panel *)this,param_1,param_2,param_3,param_4,param_5,0,0,0,0,10,param_6,
    //                      param_7);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A8A60
int create_drop_down(TRIBE_Screen_Sed* this_, TPanel* param_2, TDropDownPanel** param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: end_i */
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_drop_down(class TPanel *,class TDropDownPanel
    //    * *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_drop_down(TRIBE_Screen_Sed *this,TPanel *param_1,TDropDownPanel **param_2)
    // 
    // {
    //   char cVar1;
    //   int iVar2;
    //   long lVar3;
    //   int iVar4;
    //   int *piVar5;
    //   char *pcVar6;
    //   TDropDownPanel **ppTVar7;
    //   uint uVar8;
    //   uint uVar9;
    //   TDropDownPanel *pTVar10;
    //   int iVar11;
    //   int iVar12;
    //   char *pcVar13;
    //   uchar uVar14;
    //   uchar uVar15;
    //   int end_i;
    //   RGE_Player *player;
    //   char str [256];
    //   
    //   if ((((((param_2 == &this->victory_object_list) || (param_2 == &this->victory_attribute_list)) ||
    //         (param_2 == &this->victory_ages_list)) ||
    //        ((param_2 == &this->victory_tech_list || (param_2 == &this->BuildList)))) ||
    //       (param_2 == &this->CityLayout)) ||
    //      ((param_2 == &this->AiRules || (param_2 == &this->victory_time)))) {
    //     lVar3 = 0xdc;
    //   }
    //   else if (param_2 == &this->victory_drop_down) {
    //     lVar3 = 0xb4;
    //   }
    //   else if ((((param_2 == this->cinematic_input) || (param_2 == this->cinematic_input + 1)) ||
    //            (param_2 == this->cinematic_input + 2)) ||
    //           (((param_2 == this->cinematic_input + 3 || (param_2 == &this->default_terrain_drop)) ||
    //            ((param_2 == &this->map_size_drop || (param_2 == &this->map_style_drop)))))) {
    //     lVar3 = 0xaa;
    //   }
    //   else if (((param_2 == &this->player_advance_civilization_drop) || (param_2 == &this->player_list))
    //           || (((param_2 == &this->player_number_list ||
    //                (((param_2 == &this->unit_player_list || (param_2 == &this->victory_player_list)) ||
    //                 (param_2 == &this->options_player_list)))) ||
    //               ((param_2 == &this->Diplomacy_player_list ||
    //                (param_2 == &this->victory_enemy_player_list)))))) {
    //     lVar3 = 0x96;
    //   }
    //   else {
    //     lVar3 = 0x82;
    //   }
    //   iVar4 = TEasy_Panel::create_drop_down
    //                     ((TEasy_Panel *)this,param_1,param_2,lVar3,100,0,0,lVar3,0x16,10);
    //   if (iVar4 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   TDropDownPanel::empty_list(*param_2);
    //   ppTVar7 = &this->map_size_drop;
    //   if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x2973: "Tiny" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2973,0);
    //                     /* language.dll match for 0x2974: "Small" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2974,0);
    //                     /* language.dll match for 0x2975: "Medium" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2975,0);
    //                     /* language.dll match for 0x2976: "Large" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2976,0);
    //                     /* language.dll match for 0x2977: "Huge" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2977,0);
    //                     /* language.dll match for 0x2978: "Gigantic" */
    //     TDropDownPanel::append_line(*ppTVar7,0x2978,0);
    //     pTVar10 = *ppTVar7;
    //     lVar3 = 3;
    //   }
    //   else {
    //     ppTVar7 = &this->map_style_drop;
    //     if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x296a: "Small Islands" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296a,0);
    //                     /* language.dll match for 0x296b: "Large Islands" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296b,0);
    //                     /* language.dll match for 0x296c: "Coastal" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296c,0);
    //                     /* language.dll match for 0x296d: "Inland" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296d,0);
    //                     /* language.dll match for 0x296e: "Highland" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296e,0);
    //                     /* language.dll match for 0x296f: "Continental" */
    //       TDropDownPanel::append_line(*ppTVar7,0x296f,0);
    //                     /* language.dll match for 0x2970: "Mediterranean" */
    //       TDropDownPanel::append_line(*ppTVar7,0x2970,0);
    //                     /* language.dll match for 0x2971: "Hill Country" */
    //       TDropDownPanel::append_line(*ppTVar7,0x2971,0);
    //                     /* language.dll match for 0x2972: "Narrows"
    //                        language.dll match for 0x2972: "******* SIZE *******" */
    //       TDropDownPanel::append_line(*ppTVar7,0x2972,0);
    //       pTVar10 = *ppTVar7;
    //       lVar3 = 3;
    //     }
    //     else {
    //       ppTVar7 = &this->player_number_list;
    //       if (param_2 == ppTVar7) {
    //         iVar4 = 0;
    //         do {
    //           TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
    //           iVar4 = iVar4 + 1;
    //         } while (iVar4 < 8);
    //         pTVar10 = *ppTVar7;
    //         lVar3 = 0;
    //       }
    //       else {
    //         ppTVar7 = &this->victory_enemy_player_list;
    //         if (param_2 == ppTVar7) {
    //           iVar4 = 0;
    //           do {
    //             TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
    //             iVar4 = iVar4 + 1;
    //           } while (iVar4 < 8);
    //           pTVar10 = *ppTVar7;
    //           lVar3 = 0;
    //         }
    //         else {
    //           ppTVar7 = &this->victory_attribute_list;
    //           if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x2882: "Razings" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2882,0x2b);
    //                     /* language.dll match for 0x2883: "Conversions" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2883,0x29);
    //                     /* language.dll match for 0x2884: "Kill Ratio" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2884,0x2c);
    //                     /* language.dll match for 0x2886: "Military Population" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2886,0x28);
    //                     /* language.dll match for 0x2887: "Technologies" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2887,0x15);
    //                     /* language.dll match for 0x2888: "Kills" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2888,0x14);
    //                     /* language.dll match for 0x2889: "Villager Population" */
    //             TDropDownPanel::append_line(*ppTVar7,0x2889,0x25);
    //             pTVar10 = *ppTVar7;
    //             lVar3 = 0;
    //           }
    //           else {
    //             ppTVar7 = &this->default_terrain_drop;
    //             if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x297d: "Grass" */
    //               TDropDownPanel::append_line(*ppTVar7,0x297d,0);
    //                     /* language.dll match for 0x297e: "Desert" */
    //               TDropDownPanel::append_line(*ppTVar7,0x297e,0);
    //                     /* language.dll match for 0x297f: "Forest" */
    //               TDropDownPanel::append_line(*ppTVar7,0x297f,0);
    //                     /* language.dll match for 0x2980: "Water" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2980,0);
    //                     /* language.dll match for 0x2981: "Palm Desert" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2981,0);
    //                     /* language.dll match for 0x2982: "Jungle" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2982,0);
    //                     /* language.dll match for 0x2983: "Shallows" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2983,0);
    //                     /* language.dll match for 0x2984: "Pine Forest" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2984,0);
    //                     /* language.dll match for 0x2985: "Deep Water" */
    //               TDropDownPanel::append_line(*ppTVar7,0x2985,0);
    //               pTVar10 = *ppTVar7;
    //               lVar3 = 0;
    //             }
    //             else {
    //               ppTVar7 = this->player_setting_drop;
    //               if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x27e3: "Computer" */
    //                 TDropDownPanel::append_line(*ppTVar7,0x27e3,0);
    //                     /* language.dll match for 0x27e4: "Either" */
    //                 TDropDownPanel::append_line(*ppTVar7,0x27e4,0);
    //                 pTVar10 = *ppTVar7;
    //                 lVar3 = 0;
    //               }
    //               else {
    //                 ppTVar7 = &this->victory_drop_down;
    //                 if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x2851: "         < None >" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2851,0);
    //                     /* language.dll match for 0x2852: " Bring Object to Object" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2852,0);
    //                     /* language.dll match for 0x2853: " Bring Object to Area" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2853,0);
    //                     /* language.dll match for 0x2854: " Create # of Objects" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2854,0);
    //                     /* language.dll match for 0x2855: " Create Objects in Area" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2855,0);
    //                     /* language.dll match for 0x2856: " Destroy # of Objects" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2856,0);
    //                     /* language.dll match for 0x2857: " Destroy Specific Object" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2857,0);
    //                     /* language.dll match for 0x2858: " Destroy All Objects" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2858,0);
    //                     /* language.dll match for 0x2859: " Destroy Player" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2859,0);
    //                     /* language.dll match for 0x285a: " Capture Object" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285a,0);
    //                     /* language.dll match for 0x285b: " Gold Stockpile" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285b,0);
    //                     /* language.dll match for 0x285c: " Food Stockpile" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285c,0);
    //                     /* language.dll match for 0x285d: " Wood Stockpile" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285d,0);
    //                     /* language.dll match for 0x285e: " Stone Stockpile" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285e,0);
    //                     /* language.dll match for 0x285f: " Population" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x285f,0);
    //                     /* language.dll match for 0x2860: " Age" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2860,0);
    //                     /* language.dll match for 0x2861: " Exploration" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2861,0);
    //                     /* language.dll match for 0x2862: " Other Attributes" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x2862,0);
    //                     /* language.dll match for 0x284f: "Technologies" */
    //                   TDropDownPanel::append_line(*ppTVar7,0x284f,0);
    //                   pTVar10 = *ppTVar7;
    //                   lVar3 = 0;
    //                 }
    //                 else {
    //                   ppTVar7 = this->player_setting_drop + 1;
    //                   if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x27f7: "Egyptian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27f7,0);
    //                     /* language.dll match for 0x27f8: "Greek" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27f8,0);
    //                     /* language.dll match for 0x27f9: "Babylonian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27f9,0);
    //                     /* language.dll match for 0x27fa: "Assyrian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27fa,0);
    //                     /* language.dll match for 0x27fb: "Minoan" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27fb,0);
    //                     /* language.dll match for 0x27fc: "Hittite" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27fc,0);
    //                     /* language.dll match for 0x27fd: "Phoenician" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27fd,0);
    //                     /* language.dll match for 0x27fe: "Sumerian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27fe,0);
    //                     /* language.dll match for 0x27ff: "Persian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x27ff,0);
    //                     /* language.dll match for 0x2800: "Shang" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2800,0);
    //                     /* language.dll match for 0x2801: "Yamato" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2801,0);
    //                     /* language.dll match for 0x2802: "Choson" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2802,0);
    //                     /* language.dll match for 0x2806: "Roman" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2806,0);
    //                     /* language.dll match for 0x2807: "Carthaginian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2807,0);
    //                     /* language.dll match for 0x2809: "Palmyran" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2809,0);
    //                     /* language.dll match for 0x2808: "Macedonian" */
    //                     TDropDownPanel::append_line(*ppTVar7,0x2808,0);
    //                     pTVar10 = *ppTVar7;
    //                     lVar3 = 0;
    //                   }
    //                   else {
    //                     ppTVar7 = &this->victory_ages_list;
    //                     if (param_2 == ppTVar7) {
    //                     /* language.dll match for 0x1069: "Stone Age" */
    //                       TDropDownPanel::append_line(*ppTVar7,0x1069,0);
    //                     /* language.dll match for 0x106a: "Tool Age" */
    //                       TDropDownPanel::append_line(*ppTVar7,0x106a,0);
    //                     /* language.dll match for 0x106b: "Bronze Age" */
    //                       TDropDownPanel::append_line(*ppTVar7,0x106b,0);
    //                     /* language.dll match for 0x106c: "Iron Age" */
    //                       TDropDownPanel::append_line(*ppTVar7,0x106c,0);
    //                       pTVar10 = *ppTVar7;
    //                       lVar3 = 0;
    //                     }
    //                     else {
    //                       ppTVar7 = &this->victory_tech_list;
    //                       if (param_2 == ppTVar7) {
    //                         TDropDownPanel::set_sorted(*ppTVar7,1);
    //                         iVar4 = 0;
    //                         piVar5 = (int *)rge_base_game->world[1]._padding_;
    //                         if (0 < (short)piVar5[1]) {
    //                           iVar12 = 0;
    //                           do {
    //                             pcVar6 = TPanel::get_string((TPanel *)this,
    //                                                         (int)*(short *)(*piVar5 + 0x2a + iVar12));
    //                             if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
    //                               TDropDownPanel::append_line(*ppTVar7,pcVar6,iVar4);
    //                             }
    //                             iVar4 = iVar4 + 1;
    //                             iVar12 = iVar12 + 0x3c;
    //                             piVar5 = (int *)rge_base_game->world[1]._padding_;
    //                           } while (iVar4 < (short)piVar5[1]);
    //                         }
    //                         pTVar10 = *ppTVar7;
    //                         lVar3 = 0;
    //                       }
    //                       else {
    //                         if (param_2 == &this->AiRules) {
    //                           uVar15 = '\x01';
    //                           uVar14 = '\0';
    //                           pcVar13 = s__per;
    //                           pTVar10 = this->AiRules;
    //                           pcVar6 = rge_base_game->prog_info->ai_dir;
    //                         }
    //                         else {
    //                           ppTVar7 = &this->BuildList;
    //                           if (param_2 == ppTVar7) {
    //                             uVar15 = '\x01';
    //                             pcVar13 = s__ai;
    //                           }
    //                           else {
    //                             ppTVar7 = &this->CityLayout;
    //                             if (param_2 != ppTVar7) {
    //                               if (((param_2 == this->cinematic_input) ||
    //                                   (param_2 == this->cinematic_input + 1)) ||
    //                                  (param_2 == this->cinematic_input + 2)) {
    //                                 pTVar10 = *param_2;
    //                                 uVar15 = '\0';
    //                                 uVar14 = '\x01';
    //                                 pcVar13 = s__avi;
    //                                 pcVar6 = rge_base_game->prog_info->avi_dir;
    //                               }
    //                               else {
    //                                 if (param_2 != this->cinematic_input + 3) {
    //                                   ppTVar7 = &this->victory_object_list;
    //                                   if (param_2 != ppTVar7) goto LAB_004a9300;
    //                                   TDropDownPanel::set_sorted(*ppTVar7,1);
    //                                   TDropDownPanel::empty_list(*ppTVar7);
    //                                   iVar11 = 0;
    //                                   iVar4 = *(int *)(this->world->_padding_ + 4);
    //                                   iVar12 = (int)*(short *)(iVar4 + 0x22);
    //                                   if (0 < iVar12) {
    //                                     do {
    //                                       iVar2 = *(int *)(*(int *)(iVar4 + 0x24) + iVar11 * 4);
    //                                       if ((iVar2 != 0) && (*(char *)(iVar2 + 0x4e) == '\0')) {
    //                                         if (*(short *)(iVar2 + 0xc) < 1) {
    //                                           uVar8 = 0xffffffff;
    //                                           pcVar6 = *(char **)(iVar2 + 8);
    //                                           do {
    //                                             pcVar13 = pcVar6;
    //                                             if (uVar8 == 0) break;
    //                                             uVar8 = uVar8 - 1;
    //                                             pcVar13 = pcVar6 + 1;
    //                                             cVar1 = *pcVar6;
    //                                             pcVar6 = pcVar13;
    //                                           } while (cVar1 != '\0');
    //                                           uVar8 = ~uVar8;
    //                                           pcVar6 = pcVar13 + -uVar8;
    //                                           pcVar13 = str;
    //                                           for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    //                                             *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
    //                                             pcVar6 = pcVar6 + 4;
    //                                             pcVar13 = pcVar13 + 4;
    //                                           }
    //                                           for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    //                                             *pcVar13 = *pcVar6;
    //                                             pcVar6 = pcVar6 + 1;
    //                                             pcVar13 = pcVar13 + 1;
    //                                           }
    //                                         }
    //                                         else {
    //                                           (**(code **)(rge_base_game->_padding_ + 0x20))
    //                                                     ((int)*(short *)(iVar2 + 0xc),str,0x100);
    //                                         }
    //                                         TDropDownPanel::append_line
    //                                                   (this->victory_object_list,str,iVar11);
    //                                       }
    //                                       iVar11 = iVar11 + 1;
    //                                     } while (iVar11 < iVar12);
    //                                   }
    //                                   pTVar10 = this->victory_object_list;
    //                                   lVar3 = 0;
    //                                   goto LAB_004a92fb;
    //                                 }
    //                                 pTVar10 = *param_2;
    //                                 uVar15 = '\0';
    //                                 uVar14 = '\x01';
    //                                 pcVar13 = s__bmp;
    //                                 pcVar6 = s_;
    //                               }
    //                               goto LAB_004a92f0;
    //                             }
    //                             uVar15 = '\0';
    //                             pcVar13 = s__cty;
    //                           }
    //                           uVar14 = '\x01';
    //                           pTVar10 = *ppTVar7;
    //                           pcVar6 = rge_base_game->prog_info->ai_dir;
    //                         }
    // LAB_004a92f0:
    //                         MakeFileList(this,pTVar10,pcVar6,pcVar13,uVar14,uVar15);
    //                         pTVar10 = *param_2;
    //                         lVar3 = 0;
    //                       }
    //                     }
    //                   }
    //                 }
    //               }
    //             }
    //           }
    //         }
    //       }
    //     }
    //   }
    // LAB_004a92fb:
    //   TDropDownPanel::set_line(pTVar10,lVar3);
    // LAB_004a9300:
    //   return (uint)(this->_padding_ == 0);
    // }
    // 
    // 
}

// Offset: 0x004A9320
int SetupListOfTerrain(TRIBE_Screen_Sed* this_, TListPanel* param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::SetupListOfTerrain(class TListPanel *) */
    // 
    // int __thiscall TRIBE_Screen_Sed::SetupListOfTerrain(TRIBE_Screen_Sed *this,TListPanel *param_1)
    // 
    // {
    //   TTextPanel::empty_list((TTextPanel *)param_1);
    //                     /* language.dll match for 0x297d: "Grass" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x297d,0);
    //                     /* language.dll match for 0x297e: "Desert" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x297e,0);
    //                     /* language.dll match for 0x297f: "Forest" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x297f,0);
    //                     /* language.dll match for 0x2980: "Water" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2980,0);
    //                     /* language.dll match for 0x2981: "Palm Desert" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2981,0);
    //                     /* language.dll match for 0x2982: "Jungle" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2982,0);
    //                     /* language.dll match for 0x2983: "Shallows" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2983,0);
    //                     /* language.dll match for 0x2984: "Pine Forest" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2984,0);
    //                     /* language.dll match for 0x2985: "Deep Water" */
    //   TTextPanel::append_line((TTextPanel *)param_1,0x2985,0);
    //   return 8;
    // }
    // 
    // 
}

// Offset: 0x004A93C0
int create_list(TRIBE_Screen_Sed* this_, TPanel* param_2, TListPanel** param_3, TScrollBarPanel** param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: str1 */
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_list(class TPanel *,class TListPanel * *,class
    //    TScrollBarPanel * *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_list
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,TListPanel **param_2,TScrollBarPanel **param_3)
    // 
    // {
    //   int iVar1;
    //   char str1 [50];
    //   char str2 [60];
    //   
    //   iVar1 = TEasy_Panel::create_list((TEasy_Panel *)this,param_1,param_2,0,0,0,0,10);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   TTextPanel::empty_list((TTextPanel *)*param_2);
    //   iVar1 = TEasy_Panel::create_auto_scrollbar
    //                     ((TEasy_Panel *)this,(TScrollBarPanel **)param_2,(TTextPanel *)*param_2,0x14);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   if (param_2 == &this->paint_elevation_list) {
    //                     /* language.dll match for 0x2987: "Elevation" */
    //     set_string(this,str1,0x2987,0x32);
    //     iVar1 = 0;
    //     do {
    //       iVar1 = iVar1 + 1;
    //       sprintf(str2,s__s__d,str1,iVar1);
    //       TTextPanel::append_line((TTextPanel *)this->paint_elevation_list,str2,0);
    //     } while (iVar1 < 7);
    //     return 1;
    //   }
    //   if (param_2 == &this->paint_terrain_list) {
    //     SetupListOfTerrain(this,this->paint_terrain_list);
    //   }
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004A94A0
void TRIBE_Screen_Sed(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: virtual __thiscall TRIBE_Screen_Sed::~TRIBE_Screen_Sed(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::~TRIBE_Screen_Sed(TRIBE_Screen_Sed *this)
    // 
    // {
    //   TShape *pTVar1;
    //   int iVar2;
    //   TShape **ppTVar3;
    //   TButtonPanel **ppTVar4;
    //   TEditPanel **ppTVar5;
    //   TDropDownPanel **ppTVar6;
    //   TTextPanel **ppTVar7;
    //   TButtonPanel **ppTVar8;
    //   undefined4 *unaff_FS_OFFSET;
    //   undefined4 uStack_c;
    //   code *pcStack_8;
    //   undefined4 local_4;
    //   
    //   pcStack_8 = FUN_0055f468;
    //   uStack_c = *unaff_FS_OFFSET;
    //   *unaff_FS_OFFSET = &uStack_c;
    //   this->_padding_ = (int)&_vftable_;
    //   local_4 = 0;
    //   TPanelSystem::destroyPanel(&panel_system,&s_QuitSaveDialog);
    //   TPanelSystem::destroyPanel(&panel_system,&s_OpenSaveDialog);
    //   TPanelSystem::destroyPanel(&panel_system,&s_NewSaveDialog);
    //   TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
    //   TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_type_label);
    //   ppTVar7 = this->map_type_text;
    //   iVar2 = 3;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -3));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->default_terrain_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->default_terrain_drop);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_size_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_size_drop);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_style_drop);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_style_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_generating_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_input);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_used_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->random_seed_used_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->generate_map_button);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->brush_size_label);
    //   ppTVar7 = this->brush_size_button_label;
    //   iVar2 = 5;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_type_label);
    //   ppTVar7 = this->paint_type_button_label;
    //   iVar2 = 3;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -3));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_terrain_scrollbar);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_elevation_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->paint_elevation_scrollbar);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_advance_civilization_drop);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_starting_age_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_build_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_city_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->AiRules_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->player_number_list);
    //   ppTVar5 = this->player_inven_input;
    //   iVar2 = 5;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar5 + -5));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar5);
    //     ppTVar5 = ppTVar5 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   ppTVar6 = this->player_setting_drop;
    //   iVar2 = 2;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar6 + -3));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar6);
    //     ppTVar6 = ppTVar6 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->BuildList);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->CityLayout);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->AiRules);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_player_list);
    //   ppTVar7 = this->unit_mode_select_label;
    //   iVar2 = 4;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -4));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->unit_scrollbar);
    //   if (this->unit_list_info != (List_Info *)0x0) {
    //     free(this->unit_list_info);
    //     this->unit_list_info = (List_Info *)0x0;
    //   }
    //   if (this->object_panel != (TRIBE_Scenario_Editor_Panel_Object *)0x0) {
    //     (**(code **)this->object_panel->_padding_)(1);
    //     this->object_panel = (TRIBE_Scenario_Editor_Panel_Object *)0x0;
    //   }
    //   pTVar1 = this->button_unit_pics;
    //   if (pTVar1 != (TShape *)0x0) {
    //     TShape::~TShape(pTVar1);
    //     operator_delete(pTVar1);
    //     this->button_unit_pics = (TShape *)0x0;
    //   }
    //   ppTVar3 = this->button_bldg_pics;
    //   iVar2 = 5;
    //   do {
    //     pTVar1 = *ppTVar3;
    //     if (pTVar1 != (TShape *)0x0) {
    //       TShape::~TShape(pTVar1);
    //       operator_delete(pTVar1);
    //       *ppTVar3 = (TShape *)0x0;
    //     }
    //     ppTVar3 = ppTVar3 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   ppTVar4 = this->victory_cond_on;
    //   iVar2 = 6;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   ppTVar7 = this->victory_text_and_or;
    //   iVar2 = 2;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_long_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_conquest);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_explore);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_explore_percent);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_ruins);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_artifacts);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_discoveries);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_label_gold);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_explore);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_ruins);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_artifacts);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_discoveries);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_gold);
    //   ppTVar4 = this->victory_cond_type;
    //   iVar2 = 5;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -5));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_score_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_score);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_time_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_time);
    //   ppTVar4 = this->victory_button;
    //   iVar2 = 0xc;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_drop_down);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_object_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_player_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_ages_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_tech_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_set_object);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_set_destination);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_button_go_to_dest);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_condition_type);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_amount_input);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_enemy_player_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_attribute_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_which_enemy_text);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->victory_object_scrollbar);
    //   ppTVar7 = this->message_button_label;
    //   iVar2 = 5;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -5));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message_input);
    //   ppTVar6 = this->cinematic_input;
    //   iVar2 = 4;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar6 + -4));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar6);
    //     ppTVar6 = ppTVar6 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   ppTVar4 = this->options_button;
    //   iVar2 = 1;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -1));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->options_player_list);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->options_disable_tech_text);
    //   ppTVar7 = this->options_disable_text;
    //   iVar2 = 0x10;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar7 + -0x10));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar7);
    //     ppTVar7 = ppTVar7 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   ppTVar4 = this->Diplomacy_AlliedVictory;
    //   ppTVar8 = this->Diplomacy_friend_box[0] + 1;
    //   iVar2 = 8;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)&this->Diplomacy_player_list);
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar4 + -0x25));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar8 + -1));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar8);
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar8 + 1));
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     ppTVar8 = ppTVar8 + 3;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)this->Diplomacy_status_label);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 1));
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 2));
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)(this->Diplomacy_status_label + 3));
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->menu_button);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->help_button);
    //   ppTVar4 = this->scenario_mode_button;
    //   iVar2 = 10;
    //   do {
    //     TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar2 = iVar2 + -1;
    //   } while (iVar2 != 0);
    //   TPanel::delete_panel((TPanel *)this,&this->bottom_panel);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message_panel);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->main_view);
    //   TPanel::delete_panel((TPanel *)this,(TPanel **)&this->map_view);
    //   pTVar1 = this->background_pic;
    //   if (pTVar1 != (TShape *)0x0) {
    //     TShape::~TShape(pTVar1);
    //     operator_delete(pTVar1);
    //     this->background_pic = (TShape *)0x0;
    //   }
    //   if (this->world != (TRIBE_World *)0x0) {
    //     (**(code **)(this->world->_padding_ + 0xb8))();
    //   }
    //   local_4 = 0xffffffff;
    //   TScreenPanel::~TScreenPanel((TScreenPanel *)this);
    //   *unaff_FS_OFFSET = uStack_c;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004A9CC0
void set_scenario_mode(TRIBE_Screen_Sed* this_, ScenarioMode param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: i */
    // /* public: void __thiscall TRIBE_Screen_Sed::set_scenario_mode(enum TRIBE_Screen_Sed::ScenarioMode)
    //     */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed *this,ScenarioMode param_1)
    // 
    // {
    //   short sVar1;
    //   TRIBE_Player *pTVar2;
    //   RGE_Player *pRVar3;
    //   char *pcVar4;
    //   long lVar5;
    //   int iVar6;
    //   TButtonPanel *pTVar7;
    //   TEditPanel **ppTVar8;
    //   TDropDownPanel **ppTVar9;
    //   TDropDownPanel **ppTVar10;
    //   TButtonPanel **ppTVar11;
    //   TButtonPanel **ppTVar12;
    //   TTextPanel **ppTVar13;
    //   int unaff_EBP;
    //   int iVar14;
    //   int iVar15;
    //   RGE_Master_Static_Object *pRVar16;
    //   int i;
    //   int activate_counter;
    //   ScenarioMode mode;
    //   ScenarioMode local_4;
    //   
    //   mode = ScenarioModeNone;
    //   this->valid_save_spot_flag = '\0';
    //   do {
    //     if (mode == ScenarioModeNone) {
    //       local_4 = this->scenario_mode;
    //       iVar15 = 0;
    //     }
    //     else {
    //       if (param_1 != ScenarioModeSave) {
    //         local_4 = param_1;
    //       }
    //       iVar15 = 1;
    //     }
    //     switch(local_4) {
    //     case ScenarioModeMap:
    //       (**(code **)(this->map_type_label->_padding_ + 0x14))(iVar15);
    //       ppTVar13 = this->map_type_text;
    //       iVar14 = 3;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
    //         ppTVar13 = ppTVar13 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       (**(code **)(this->generate_map_button->_padding_ + 0x14))(iVar15);
    //       if (iVar15 == 0) {
    //         set_map_type(this,MapTypeNone,0);
    //       }
    //       else {
    //         set_map_type(this,this->map_type,1);
    //       }
    //       break;
    //     case ScenarioModeTerrain:
    //       (**(code **)(this->brush_size_label->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->paint_type_label->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar15);
    //       ppTVar13 = this->brush_size_button_label;
    //       iVar14 = 5;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
    //         ppTVar13 = ppTVar13 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       ppTVar13 = this->paint_type_button_label;
    //       iVar14 = 3;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
    //         ppTVar13 = ppTVar13 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       if (iVar15 == 0) {
    //         set_brush_size(this,BrushSizeNone);
    //         set_paint_type(this,PaintTypeNone,0);
    //       }
    //       else {
    //         set_brush_size(this,this->brush_size);
    //         set_paint_type(this,this->paint_type,1);
    //       }
    //       break;
    //     case ScenarioModePlayers:
    //       (**(code **)(this->player_list->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->player_number_list->_padding_ + 0x14))(iVar15);
    //       ppTVar8 = this->player_inven_input;
    //       iVar14 = 5;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar8[-5])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar8)->_padding_ + 0x14))(iVar15);
    //         ppTVar8 = ppTVar8 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       ppTVar9 = this->player_setting_drop;
    //       iVar14 = 2;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar9[-3])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar9)->_padding_ + 0x14))(iVar15);
    //         ppTVar9 = ppTVar9 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       if (iVar15 == 0) {
    //         set_player(this,this->player_num,'\x01','\0');
    //         (**(code **)(*(int *)this->map_view + 0x14))(1);
    //         SavePlayerActiveStatus(this);
    //       }
    //       else {
    //         iVar14 = T_Scenario::GetPlayerAge
    //                            ((T_Scenario *)this->world->_padding_,this->player_num + -1);
    //         TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,iVar14);
    //         set_player(this,this->player_num,'\0','\x01');
    //         TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
    //         (**(code **)(*(int *)this->map_view + 0x14))(0);
    //       }
    //       (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->player_label->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->player_starting_age_label->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->player_build_text->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->player_city_text->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->AiRules_text->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->BuildList->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->CityLayout->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->AiRules->_padding_ + 0x14))(iVar15);
    //       break;
    //     case ScenarioModeUnits:
    //       (**(code **)(this->unit_player_list->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_list->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->object_panel->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select[0]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select[1]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select[2]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select[3]->_padding_ + 0x14))(iVar15);
    //       if (iVar15 != 0) {
    //         TButtonPanel::set_radio_button(this->unit_mode_select[0]);
    //       }
    //       (**(code **)(this->unit_mode_select_label[0]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select_label[1]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select_label[2]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->unit_mode_select_label[3]->_padding_ + 0x14))(iVar15);
    //       sVar1 = this->player_num;
    //       if (iVar15 == 0) {
    //         if ((sVar1 < 1) || (8 < sVar1)) {
    //           this->player_num = 1;
    //           set_player(this,1,'\0','\0');
    //         }
    //         (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    //         set_unit(this,-1);
    //       }
    //       else {
    //         set_unit_player(this,sVar1);
    //         iVar15 = TTextPanel::currentLineNumber((TTextPanel *)this->unit_list);
    //         set_unit(this,(short)iVar15);
    //         TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->unit_list);
    //         set_paint_object_mode(this);
    //         (**(code **)(rge_base_game->_padding_ + 0x10))(rge_base_game->game_mode,4);
    //         if ((rge_base_game->master_obj_id == -1) ||
    //            (pRVar3 = RGE_Base_Game::get_player(rge_base_game), pRVar3 == (RGE_Player *)0x0)) {
    //           pTVar2 = (TRIBE_Player *)0x0;
    //           pRVar16 = (RGE_Master_Static_Object *)0x0;
    //         }
    //         else {
    //           sVar1 = rge_base_game->master_obj_id;
    //           pTVar2 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    //           pRVar3 = RGE_Base_Game::get_player(rge_base_game);
    //           pRVar16 = *(RGE_Master_Static_Object **)
    //                      (*(int *)(*(int *)(this->world->_padding_ + pRVar3->id * 4) + 0x24) + sVar1 * 4
    //                      );
    //         }
    //         TRIBE_Scenario_Editor_Panel_Object::set_master_info(this->object_panel,pRVar16,pTVar2);
    //         (**(code **)(this->object_panel->_padding_ + 0x20))(1);
    //       }
    //       break;
    //     case ScenarioModeDiplomacy:
    //       if (this->player_num < 1) {
    //         this->player_num = 1;
    //       }
    //       (**(code **)(this->Diplomacy_player_list->_padding_ + 0x14))(iVar15);
    //       i = 0;
    //       lVar5 = TDropDownPanel::get_line(this->player_number_list);
    //       if (-1 < lVar5) {
    //         ppTVar12 = this->Diplomacy_friend_box[0] + 1;
    //         ppTVar11 = this->Diplomacy_AlliedVictory;
    //         do {
    //           (**(code **)(((TTextPanel *)ppTVar11[-0x25])->_padding_ + 0x14))(iVar15);
    //           pTVar7 = *ppTVar11;
    //           if (unaff_EBP != this->player_num + -1) {
    //             (**(code **)(pTVar7->_padding_ + 0x14))(0);
    //             (**(code **)((*(TButtonPanel *(*) [3])(ppTVar12 + -1))[0]->_padding_ + 0x14))(iVar15);
    //             (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
    //             pTVar7 = ppTVar12[1];
    //           }
    //           (**(code **)(pTVar7->_padding_ + 0x14))(iVar15);
    //           ppTVar11 = ppTVar11 + 1;
    //           i = i + 1;
    //           ppTVar12 = ppTVar12 + 3;
    //           lVar5 = TDropDownPanel::get_line(this->player_number_list);
    //         } while (i <= lVar5);
    //       }
    //       (**(code **)(this->Diplomacy_status_label[0]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->Diplomacy_status_label[1]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->Diplomacy_status_label[2]->_padding_ + 0x14))(iVar15);
    //       (**(code **)(this->Diplomacy_status_label[3]->_padding_ + 0x14))(iVar15);
    //       if (iVar15 == 0) {
    //         save_diplomacy_in_scenario(this,this->player_num + -1);
    //       }
    //       else {
    //         load_diplomacy_from_scenario(this,this->player_num + -1);
    //       }
    //       break;
    //     case ScenarioModeVictory:
    //       activate_victory_panel(this,iVar15);
    //       if (iVar15 == 0) {
    //         save_victory_cond_in_scenario(this,this->CurrentVictory);
    //         iVar15 = 0;
    //         lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //         activate_victory_proper_fields(this,lVar5,iVar15);
    //         this->SelectedObject = (RGE_Static_Object *)0x0;
    //         this->DestinationObject = (RGE_Static_Object *)0x0;
    //         pRVar3 = RGE_Base_Game::get_player(rge_base_game);
    //         RGE_Player::unselect_object(pRVar3);
    //       }
    //       else {
    //         load_victory_cond_from_scenario(this,this->CurrentVictory);
    //         lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //         activate_victory_proper_fields(this,lVar5,iVar15);
    //       }
    //       break;
    //     case ScenarioModeVictoryMulti:
    //       (**(code **)(this->victory_condition_label->_padding_ + 0x14))(iVar15);
    //       ppTVar12 = this->victory_cond_type;
    //       iVar14 = 5;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar12[-5])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
    //         ppTVar12 = ppTVar12 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       if (iVar15 == 0) {
    //         save_multi_victory_cond_in_scenario(this);
    //         (**(code **)(*(int *)this->map_view + 0x14))(1);
    //         set_mp_victory_type(this,VictoryTypeNone,0);
    //       }
    //       else {
    //         load_multi_victory_cond_from_scenario(this);
    //         (**(code **)(*(int *)this->map_view + 0x14))(0);
    //         set_mp_victory_type(this,this->mp_victory_type,1);
    //       }
    //       break;
    //     case ScenarioModeOptions:
    //       if (iVar15 == 0) {
    //         (**(code **)(*(int *)this->map_view + 0x14))(1);
    //         SaveDisabledItemsInScenario(this);
    //       }
    //       else {
    //         (**(code **)(*(int *)this->map_view + 0x14))(0);
    //         iVar14 = this->options_button[0]->_padding_;
    //         iVar6 = T_Scenario::GetScenarioOption((T_Scenario *)this->world->_padding_,2);
    //         (**(code **)(iVar14 + 0xe0))(iVar6);
    //         LoadDisabledItemsFromScenario(this);
    //         if (this->player_num == 0) {
    //           iVar14 = 0;
    //         }
    //         else {
    //           iVar14 = this->player_num + -1;
    //         }
    //         TDropDownPanel::setCurrentLineNumber(this->options_player_list,iVar14);
    //       }
    //       ppTVar12 = this->options_button;
    //       iVar14 = 1;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar12[-1])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
    //         ppTVar12 = ppTVar12 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       (**(code **)(this->options_player_list->_padding_ + 0x14))(iVar15);
    //       if (iVar15 == 0) {
    //         lVar5 = TDropDownPanel::get_line(this->options_player_list);
    //         this->player_num = (short)lVar5 + 1;
    //       }
    //       else {
    //         TDropDownPanel::set_line(this->options_player_list,this->player_num + -1);
    //       }
    //       (**(code **)(this->options_disable_tech_text->_padding_ + 0x14))(iVar15);
    //       ppTVar13 = this->options_disable_text;
    //       iVar14 = 0x10;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar13[-0x10])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
    //         ppTVar13 = ppTVar13 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       break;
    //     case ScenarioModeMessages:
    //       ppTVar13 = this->message_button_label;
    //       iVar14 = 5;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
    //         ppTVar13 = ppTVar13 + 1;
    //         iVar14 = iVar14 + -1;
    //       } while (iVar14 != 0);
    //       TButtonPanel::set_radio_button(this->message_button[this->current_message]);
    //       lVar5 = this->current_message;
    //       if (iVar15 == 0) {
    //         pcVar4 = TEditPanel::get_input_buffer(this->message_input);
    //         RGE_Scenario::Set_message((RGE_Scenario *)this->world->_padding_,pcVar4,lVar5);
    //         set_message_type(this,MessageTypeNone,0);
    //         (**(code **)(*(int *)this->map_view + 0x14))(1);
    //         save_info_in_scenario(this);
    //         break;
    //       }
    //       pcVar4 = RGE_Scenario::Get_message((RGE_Scenario *)this->world->_padding_,lVar5);
    //       TEditPanel::set_text(this->message_input,pcVar4);
    //       switch(this->current_message) {
    //       case 0:
    //         lVar5 = 0x7770;
    //         break;
    //       case 1:
    //         lVar5 = 0x7771;
    //         break;
    //       case 2:
    //         lVar5 = 0x7772;
    //         break;
    //       case 3:
    //         lVar5 = 0x7773;
    //         break;
    //       case 4:
    //                     /* language.dll match for 0x7774: "Type the history text (optional)." */
    //         lVar5 = 0x7774;
    //         break;
    //       default:
    //         goto switchD_004aa268_default;
    //       }
    //       TPanel::set_help_info((TPanel *)this->message_input,lVar5,-1);
    // switchD_004aa268_default:
    //       set_message_type(this,this->message_type,1);
    //       (**(code **)(*(int *)this->map_view + 0x14))(0);
    //       TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->message_input);
    //       break;
    //     case ScenarioModeCinematics:
    //       ppTVar9 = this->cinematic_input;
    //       activate_counter = 4;
    //       ppTVar10 = ppTVar9;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar10[-4])->_padding_ + 0x14))(iVar15);
    //         (**(code **)((*ppTVar10)->_padding_ + 0x14))(iVar15);
    //         ppTVar10 = ppTVar10 + 1;
    //         activate_counter = activate_counter + -1;
    //       } while (activate_counter != 0);
    //       if (iVar15 == 0) {
    //         pcVar4 = TDropDownPanel::currentLine(*ppTVar9);
    //         RGE_Scenario::Set_Cine_PreGame((RGE_Scenario *)this->world->_padding_,pcVar4);
    //         pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[1]);
    //         RGE_Scenario::Set_Cine_Victory((RGE_Scenario *)this->world->_padding_,pcVar4);
    //         pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[2]);
    //         RGE_Scenario::Set_Cine_Loss((RGE_Scenario *)this->world->_padding_,pcVar4);
    //         pcVar4 = TDropDownPanel::currentLine(this->cinematic_input[3]);
    //         RGE_Scenario::Set_Mission_Bmp((RGE_Scenario *)this->world->_padding_,pcVar4);
    //       }
    //       else {
    //         TPanel::set_curr_child(this->bottom_panel,(TPanel *)*ppTVar9);
    //         pcVar4 = RGE_Scenario::Get_Cine_PreGame((RGE_Scenario *)this->world->_padding_);
    //         lVar5 = TDropDownPanel::get_line(*ppTVar9,pcVar4);
    //         TDropDownPanel::setCurrentLineNumber(*ppTVar9,lVar5);
    //         pcVar4 = RGE_Scenario::Get_Cine_Victory((RGE_Scenario *)this->world->_padding_);
    //         lVar5 = TDropDownPanel::get_line(this->cinematic_input[1],pcVar4);
    //         TDropDownPanel::setCurrentLineNumber(this->cinematic_input[1],lVar5);
    //         pcVar4 = RGE_Scenario::Get_Cine_Loss((RGE_Scenario *)this->world->_padding_);
    //         lVar5 = TDropDownPanel::get_line(this->cinematic_input[2],pcVar4);
    //         TDropDownPanel::setCurrentLineNumber(this->cinematic_input[2],lVar5);
    //         pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
    //         iVar15 = TDropDownPanel::get_line(this->cinematic_input[3],pcVar4);
    //         if (iVar15 == -1) {
    //           lVar5 = 0;
    //           pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
    //           TDropDownPanel::append_line(this->cinematic_input[3],pcVar4,lVar5);
    //           pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)this->world->_padding_);
    //           iVar15 = TDropDownPanel::get_line(this->cinematic_input[3],pcVar4);
    //         }
    //         TDropDownPanel::setCurrentLineNumber(this->cinematic_input[3],iVar15);
    //       }
    //     }
    //     mode = mode + ScenarioModeMap;
    //     if (1 < (int)mode) {
    //       if (param_1 != ScenarioModeSave) {
    //         this->scenario_mode = param_1;
    //         if (param_1 != ScenarioModeNone) {
    //           TButtonPanel::set_radio_button(this->scenario_mode_button[param_1 - ScenarioModeMap]);
    //         }
    //         iVar15 = this->_padding_;
    //         (**(code **)(iVar15 + 0x50))(this->_padding_,this->_padding_);
    //         (**(code **)(iVar15 + 0x20))(1);
    //       }
    //       this->valid_save_spot_flag = '\x01';
    //       return;
    //     }
    //   } while( true );
    // }
    // 
    // 
}

// Offset: 0x004AA6E6
undefined FUN_004aa6e6() {
    // --- Ghidra decompiler output ---
    // 
    // void FUN_004aa6e6(void)
    // 
    // {
    //   char *pcVar1;
    //   int iVar2;
    //   bool bVar3;
    //   undefined4 in_EAX;
    //   char cVar4;
    //   int in_ECX;
    //   int in_EDX;
    //   char cVar5;
    //   int unaff_EBX;
    //   int unaff_ESI;
    //   int unaff_EDI;
    //   
    //   cVar5 = (char)((uint)unaff_EBX >> 8);
    //   *(char *)(in_EDX + -100) = *(char *)(in_EDX + -100) + cVar5;
    //   *(char *)(in_EDX + -2) = *(char *)(in_EDX + -2) + (char)((uint)in_EAX >> 8);
    //   pcVar1 = (char *)(unaff_EDI + 0x4a + unaff_EBX * 4);
    //   cVar4 = (char)((uint)in_ECX >> 8);
    //   *pcVar1 = *pcVar1 + cVar4;
    //   *(char *)(unaff_ESI + 0x9004aa4) = *(char *)(unaff_ESI + 0x9004aa4) + (char)in_EDX + -3;
    //   iVar2 = iRama183004a;
    //   *(char *)(iRama183004a + 0x4aa5) = *(char *)(iRama183004a + 0x4aa5) + (char)unaff_EBX;
    //   cRama293004a = (char)iVar2;
    //   cRama317004a = cRama293004a;
    //   *(char *)(unaff_EDI + -0x5e) = *(char *)(unaff_EDI + -0x5e) + cVar4;
    //   *(char *)(iVar2 + -0x5e) = *(char *)(iVar2 + -0x5e) + cVar5;
    //   *(char *)(in_ECX + -0x75ffb55e) = *(char *)(in_ECX + -0x75ffb55e) + cRama293004a;
    //   *(char *)(iVar2 + -0x6f6f6f70) = *(char *)(iVar2 + -0x6f6f6f70) + (char)in_EDX + -8;
    //   bVar3 = false;
    //   if ((((rge_base_game->master_obj_id != -1) &&
    //        (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 0x928) + 0x40) +
    //                                           *(short *)(in_ECX + 0x4b8) * 4) + 0x24) +
    //                         rge_base_game->master_obj_id * 4), iVar2 != 0)) &&
    //       (*(char *)(iVar2 + 4) == 'P')) && (*(char *)(iVar2 + 0x16c) != '\0')) {
    //     bVar3 = true;
    //   }
    //   if (bVar3) {
    //     (**(code **)(rge_base_game->_padding_ + 0x10))(0x15,0);
    //     return;
    //   }
    //   (**(code **)(rge_base_game->_padding_ + 0x10))(8,rge_base_game->sub_game_mode);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AA730
void set_paint_object_mode(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_paint_object_mode(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_paint_object_mode(TRIBE_Screen_Sed *this)
    // 
    // {
    //   int iVar1;
    //   bool bVar2;
    //   
    //   bVar2 = false;
    //   if ((((rge_base_game->master_obj_id != -1) &&
    //        (iVar1 = *(int *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x24) +
    //                         rge_base_game->master_obj_id * 4), iVar1 != 0)) &&
    //       (*(char *)(iVar1 + 4) == 'P')) && (*(char *)(iVar1 + 0x16c) != '\0')) {
    //     bVar2 = true;
    //   }
    //   if (bVar2) {
    //     (**(code **)(rge_base_game->_padding_ + 0x10))(0x15,0);
    //     return;
    //   }
    //   (**(code **)(rge_base_game->_padding_ + 0x10))(8,rge_base_game->sub_game_mode);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AA7A0
void set_map_type(TRIBE_Screen_Sed* this_, MapType param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_map_type(enum TRIBE_Screen_Sed::MapType,int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_map_type(TRIBE_Screen_Sed *this,MapType param_1,int param_2)
    // 
    // {
    //   MapType MVar1;
    //   TTextPanel *pTVar2;
    //   int iVar3;
    //   int iVar4;
    //   
    //   iVar3 = 0;
    //   do {
    //     if (iVar3 == 0) {
    //       iVar4 = 0;
    //       MVar1 = this->map_type;
    //     }
    //     else {
    //       if (param_1 == MapTypeNone) {
    //         return;
    //       }
    //       if (param_2 == 0) break;
    //       iVar4 = 1;
    //       MVar1 = param_1;
    //     }
    //     if (MVar1 == MapTypeBlank) {
    //       (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
    //       (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
    //       (**(code **)(this->default_terrain_label->_padding_ + 0x14))(iVar4);
    //       pTVar2 = (TTextPanel *)this->default_terrain_drop;
    // LAB_004aa8b8:
    //       (**(code **)(pTVar2->_padding_ + 0x14))(iVar4);
    //     }
    //     else {
    //       if (MVar1 == MapTypeRandom) {
    //         (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_style_label->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_style_drop->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->random_seed_used_label->_padding_ + 0x14))(iVar4);
    //         pTVar2 = this->random_seed_used_text;
    //         goto LAB_004aa8b8;
    //       }
    //       if (MVar1 == MapTypeSeed) {
    //         (**(code **)(this->map_size_label->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_size_drop->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_style_label->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->map_style_drop->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->random_seed_label->_padding_ + 0x14))(iVar4);
    //         (**(code **)(this->random_seed_input->_padding_ + 0x14))(iVar4);
    //         if (iVar4 != 0) {
    //           TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->random_seed_input);
    //         }
    //       }
    //     }
    //     iVar3 = iVar3 + 1;
    //   } while (iVar3 < 2);
    //   this->map_type = param_1;
    //   TButtonPanel::set_radio_button(this->map_type_button[param_1 - MapTypeBlank]);
    //   (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AA8F0
void set_mp_victory_type(TRIBE_Screen_Sed* this_, VictoryType param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: activate_counter */
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_mp_victory_type(enum
    //    TRIBE_Screen_Sed::VictoryType,int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_mp_victory_type(TRIBE_Screen_Sed *this,VictoryType param_1,int param_2)
    // 
    // {
    //   VictoryType VVar1;
    //   TButtonPanel **ppTVar2;
    //   TTextPanel **ppTVar3;
    //   int iVar4;
    //   int iVar5;
    //   int activate_counter;
    //   int local_4;
    //   
    //   local_4 = 0;
    //   do {
    //     if (local_4 == 0) {
    //       iVar5 = 0;
    //       VVar1 = this->mp_victory_type;
    //     }
    //     else {
    //       if (param_1 == VictoryTypeNone) {
    //         return;
    //       }
    //       if (param_2 == 0) break;
    //       iVar5 = 1;
    //       VVar1 = param_1;
    //     }
    //     switch(VVar1) {
    //     case VictoryTypeScore:
    //       (**(code **)(this->victory_score_label->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_score->_padding_ + 0x14))(iVar5);
    //       break;
    //     case VictoryTypeTime:
    //       (**(code **)(this->victory_time_label->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_time->_padding_ + 0x14))(iVar5);
    //       break;
    //     case VictoryTypeCustom:
    //       ppTVar2 = this->victory_cond_on;
    //       iVar4 = 5;
    //       do {
    //         (**(code **)((*ppTVar2)->_padding_ + 0x14))(iVar5);
    //         ppTVar2 = ppTVar2 + 1;
    //         iVar4 = iVar4 + -1;
    //       } while (iVar4 != 0);
    //       ppTVar3 = this->victory_text_and_or;
    //       iVar4 = 2;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar3[-5])->_padding_ + 0x14))(iVar5);
    //         (**(code **)((*ppTVar3)->_padding_ + 0x14))(iVar5);
    //         ppTVar3 = ppTVar3 + 1;
    //         iVar4 = iVar4 + -1;
    //       } while (iVar4 != 0);
    //       (**(code **)(this->victory_amount_label->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_label_conquest->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_label_explore->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_label_ruins->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_label_artifacts->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_label_discoveries->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_condition_explore->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_condition_ruins->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_condition_artifacts->_padding_ + 0x14))(iVar5);
    //       (**(code **)(this->victory_condition_discoveries->_padding_ + 0x14))(iVar5);
    //       if (iVar5 == 1) {
    //         TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_condition_explore);
    //       }
    //     }
    //     local_4 = local_4 + 1;
    //   } while (local_4 < 2);
    //   this->mp_victory_type = param_1;
    //   TButtonPanel::set_radio_button
    //             ((TButtonPanel *)this->victory_cond_type_label[param_1 + VictoryTypeTime]);
    //   (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AAA90
void set_brush_size(TRIBE_Screen_Sed* this_, BrushSize param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_brush_size(enum TRIBE_Screen_Sed::BrushSize) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_brush_size(TRIBE_Screen_Sed *this,BrushSize param_1)
    // 
    // {
    //   if (param_1 != BrushSizeNone) {
    //     this->brush_size = param_1;
    //     TButtonPanel::set_radio_button(this->brush_size_button[param_1 - BrushSizeVerySmall]);
    //     switch(this->brush_size) {
    //     case BrushSizeVerySmall:
    //       rge_base_game->brush_size = 1;
    //       return;
    //     case BrushSizeSmall:
    //       rge_base_game->brush_size = 3;
    //       return;
    //     case BrushSizeMedium:
    //       rge_base_game->brush_size = 5;
    //       return;
    //     case BrushSizeLarge:
    //       rge_base_game->brush_size = 7;
    //       return;
    //     case BrushSizeXLarge:
    //       rge_base_game->brush_size = 9;
    //       return;
    //     default:
    //       rge_base_game->brush_size = 2;
    //     }
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AAB4A
undefined FUN_004aab4a() {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Control flow encountered bad instruction data */
    // 
    // void FUN_004aab4a(void)
    // 
    // {
    //                     /* WARNING: Bad instruction - Truncating control flow here */
    //   halt_baddata();
    // }
    // 
    // 
}

// Offset: 0x004AAB60
void set_paint_type(TRIBE_Screen_Sed* this_, PaintType param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: activate_counter */
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_paint_type(enum TRIBE_Screen_Sed::PaintType,int)
    //     */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_paint_type(TRIBE_Screen_Sed *this,PaintType param_1,int param_2)
    // 
    // {
    //   TTextPanel **ppTVar1;
    //   int iVar2;
    //   int iVar3;
    //   int activate_counter;
    //   PaintType val;
    //   PaintType local_4;
    //   
    //   val = PaintTypeNone;
    //   do {
    //     if (val == PaintTypeNone) {
    //       local_4 = this->paint_type;
    //       iVar3 = 0;
    //     }
    //     else {
    //       if (param_1 == PaintTypeNone) {
    //         return;
    //       }
    //       if (param_2 == 0) break;
    //       local_4 = param_1;
    //       iVar3 = 1;
    //     }
    //     (**(code **)(this->brush_size_label->_padding_ + 0x14))(iVar3);
    //     ppTVar1 = this->brush_size_button_label;
    //     iVar2 = 5;
    //     do {
    //       (**(code **)(((TButtonPanel *)ppTVar1[-5])->_padding_ + 0x14))(iVar3);
    //       (**(code **)((*ppTVar1)->_padding_ + 0x14))(iVar3);
    //       ppTVar1 = ppTVar1 + 1;
    //       iVar2 = iVar2 + -1;
    //     } while (iVar2 != 0);
    //     if (local_4 == PaintTypeTerrain) {
    //       (**(code **)(this->paint_terrain_list->_padding_ + 0x14))(iVar3);
    //       (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar3);
    //       if (iVar3 == 0) {
    // LAB_004aacf6:
    //         (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    //       }
    //       else {
    //         iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_terrain_list);
    //         set_terrain(this,(short)iVar3);
    //         (**(code **)(rge_base_game->_padding_ + 0x10))(9,0);
    //       }
    //     }
    //     else if (local_4 == PaintTypeElevation) {
    //       (**(code **)(this->paint_elevation_list->_padding_ + 0x14))(iVar3);
    //       (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(iVar3);
    //       if (iVar3 == 0) goto LAB_004aacf6;
    //       iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
    //       set_elevation(this,(short)iVar3);
    //       (**(code **)(rge_base_game->_padding_ + 0x10))(10,0);
    //     }
    //     else if (local_4 == PaintTypeCliffs) {
    //       (**(code **)(this->paint_elevation_list->_padding_ + 0x14))(0);
    //       (**(code **)(this->paint_terrain_list->_padding_ + 0x14))(0);
    //       (**(code **)(this->paint_terrain_label->_padding_ + 0x14))(0);
    //       (**(code **)(this->brush_size_label->_padding_ + 0x14))(0);
    //       ppTVar1 = this->brush_size_button_label;
    //       iVar2 = 5;
    //       do {
    //         (**(code **)(((TButtonPanel *)ppTVar1[-5])->_padding_ + 0x14))(0);
    //         (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
    //         ppTVar1 = ppTVar1 + 1;
    //         iVar2 = iVar2 + -1;
    //       } while (iVar2 != 0);
    //       if (iVar3 == 0) goto LAB_004aacf6;
    //       iVar3 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
    //       set_elevation(this,(short)iVar3);
    //       (**(code **)(rge_base_game->_padding_ + 0x10))(0x13,0);
    //     }
    //     val = val + PaintTypeTerrain;
    //   } while ((int)val < 2);
    //   this->paint_type = param_1;
    //   TButtonPanel::set_radio_button(this->paint_type_button[param_1 - PaintTypeTerrain]);
    //   (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AAD50
void set_terrain(TRIBE_Screen_Sed* this_, short param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_terrain(short) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_terrain(TRIBE_Screen_Sed *this,short param_1)
    // 
    // {
    //   short sVar1;
    //   
    //   switch(param_1) {
    //   default:
    //     sVar1 = 0;
    //     break;
    //   case 1:
    //     sVar1 = 6;
    //     break;
    //   case 2:
    //     sVar1 = 10;
    //     break;
    //   case 3:
    //     sVar1 = 1;
    //     break;
    //   case 4:
    //     sVar1 = 0xd;
    //     break;
    //   case 5:
    //     sVar1 = 0x14;
    //     break;
    //   case 6:
    //     sVar1 = 4;
    //     break;
    //   case 7:
    //     sVar1 = 0x13;
    //     break;
    //   case 8:
    //     sVar1 = 0x16;
    //   }
    //   rge_base_game->terrain_id = sVar1;
    //   TListPanel::scroll_cur_line(this->paint_terrain_list,'\x01',param_1,1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AADF0
void set_elevation(TRIBE_Screen_Sed* this_, short param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_elevation(short) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_elevation(TRIBE_Screen_Sed *this,short param_1)
    // 
    // {
    //   rge_base_game->elevation_height = param_1;
    //   TListPanel::scroll_cur_line(this->paint_elevation_list,'\x01',param_1,1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AAE20
void set_player(TRIBE_Screen_Sed* this_, short param_2, uchar param_3, uchar param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: str */
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_player(short,unsigned char,unsigned char) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_player(TRIBE_Screen_Sed *this,short param_1,uchar param_2,uchar param_3)
    // 
    // {
    //   uchar uVar1;
    //   RGE_Player *this_00;
    //   char *pcVar2;
    //   int iVar3;
    //   int iVar4;
    //   undefined2 in_stack_00000006;
    //   long lVar5;
    //   char str [30];
    //   
    //   uVar1 = param_2;
    //   _param_2 = (uint)param_2;
    //   iVar4 = this->player_num + -1;
    //   if (iVar4 < 0) {
    //     iVar4 = 0;
    //   }
    //   this_00 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_Player::unselect_object(this_00);
    //   if (uVar1 != '\0') {
    //     pcVar2 = TEditPanel::currentLine(this->player_inven_input[0]);
    //     iVar3 = atoi(pcVar2);
    //     T_Scenario::Set_player_Food((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    //     **(float **)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) = (float)iVar3;
    //     pcVar2 = TEditPanel::currentLine(this->player_inven_input[1]);
    //     iVar3 = atoi(pcVar2);
    //     T_Scenario::Set_player_Wood((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    //     *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 4) =
    //          (float)iVar3;
    //     pcVar2 = TEditPanel::currentLine(this->player_inven_input[2]);
    //     iVar3 = atoi(pcVar2);
    //     T_Scenario::Set_player_Stone((T_Scenario *)this->world->_padding_,iVar4,iVar3);
    //     *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 8) =
    //          (float)iVar3;
    //     pcVar2 = TEditPanel::currentLine(this->player_inven_input[3]);
    //     _param_2 = atoi(pcVar2);
    //     T_Scenario::Set_player_Gold((T_Scenario *)this->world->_padding_,iVar4,_param_2);
    //     *(float *)(*(int *)(*(int *)(this->world->_padding_ + this->player_num * 4) + 0x50) + 0xc) =
    //          (float)(int)_param_2;
    //     pcVar2 = TEditPanel::currentLine(this->player_inven_input[4]);
    //     RGE_Scenario::SetPlayerName((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2);
    //     iVar3 = TDropDownPanel::currentLineNumber(this->player_setting_drop[0]);
    //     RGE_Scenario::Set_player_Type((RGE_Scenario *)this->world->_padding_,iVar4,iVar3);
    //     iVar3 = TDropDownPanel::currentLineNumber(this->player_setting_drop[1]);
    //     RGE_Scenario::Set_player_Civ((RGE_Scenario *)this->world->_padding_,iVar4,iVar3 + 1);
    //     iVar3 = 0;
    //     pcVar2 = TDropDownPanel::currentLine(this->AiRules);
    //     RGE_Scenario::Set_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
    //     iVar3 = 0;
    //     pcVar2 = TDropDownPanel::currentLine(this->BuildList);
    //     RGE_Scenario::Set_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
    //     iVar3 = 0;
    //     pcVar2 = TDropDownPanel::currentLine(this->CityLayout);
    //     RGE_Scenario::Set_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,pcVar2,iVar3);
    //   }
    //   iVar4 = param_1 + -1;
    //   this->player_num = param_1;
    //   if (param_1 != 0) {
    //     TDropDownPanel::set_line(this->player_list,iVar4);
    //     (**(code **)(rge_base_game->_padding_ + 0x14))(_param_1);
    //     if (param_2 == '\x01') {
    //       iVar3 = T_Scenario::Get_player_Food((T_Scenario *)this->world->_padding_,iVar4);
    //       sprintf(str,&s__d,iVar3);
    //       TEditPanel::set_text(this->player_inven_input[0],str);
    //       iVar3 = T_Scenario::Get_player_Wood((T_Scenario *)this->world->_padding_,iVar4);
    //       sprintf(str,&s__d,iVar3);
    //       TEditPanel::set_text(this->player_inven_input[1],str);
    //       iVar3 = T_Scenario::Get_player_Stone((T_Scenario *)this->world->_padding_,iVar4);
    //       sprintf(str,&s__d,iVar3);
    //       TEditPanel::set_text(this->player_inven_input[2],str);
    //       iVar3 = T_Scenario::Get_player_Gold((T_Scenario *)this->world->_padding_,iVar4);
    //       sprintf(str,&s__d,iVar3);
    //       TEditPanel::set_text(this->player_inven_input[3],str);
    //       pcVar2 = RGE_Scenario::GetPlayerName((RGE_Scenario *)this->world->_padding_,iVar4);
    //       TEditPanel::set_text(this->player_inven_input[4],pcVar2);
    //       iVar3 = RGE_Scenario::Get_player_Type((RGE_Scenario *)this->world->_padding_,iVar4);
    //       TDropDownPanel::setCurrentLineNumber(this->player_setting_drop[0],iVar3);
    //       iVar3 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)this->world->_padding_,iVar4);
    //       TDropDownPanel::setCurrentLineNumber(this->player_setting_drop[1],iVar3 + -1);
    //       pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //       iVar3 = TDropDownPanel::get_line(this->AiRules,pcVar2);
    //       if (iVar3 == -1) {
    //         lVar5 = 0;
    //         pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         TDropDownPanel::append_line(this->AiRules,pcVar2,lVar5);
    //         pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         iVar3 = TDropDownPanel::get_line(this->AiRules,pcVar2);
    //       }
    //       TDropDownPanel::setCurrentLineNumber(this->AiRules,iVar3);
    //       pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //       iVar3 = TDropDownPanel::get_line(this->BuildList,pcVar2);
    //       if (iVar3 == -1) {
    //         lVar5 = 0;
    //         pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         TDropDownPanel::append_line(this->BuildList,pcVar2,lVar5);
    //         pcVar2 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         iVar3 = TDropDownPanel::get_line(this->BuildList,pcVar2);
    //       }
    //       TDropDownPanel::setCurrentLineNumber(this->BuildList,iVar3);
    //       pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //       iVar3 = TDropDownPanel::get_line(this->CityLayout,pcVar2);
    //       if (iVar3 == -1) {
    //         lVar5 = 0;
    //         pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         TDropDownPanel::append_line(this->CityLayout,pcVar2,lVar5);
    //         pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this->world->_padding_,iVar4,0);
    //         iVar3 = TDropDownPanel::get_line(this->CityLayout,pcVar2);
    //       }
    //       TDropDownPanel::setCurrentLineNumber(this->CityLayout,iVar3);
    //     }
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AB2B0
void set_player_active(TRIBE_Screen_Sed* this_, short param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_player_active(short,int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_player_active(TRIBE_Screen_Sed *this,short param_1,int param_2)
    // 
    // {
    //   RGE_Scenario::Set_player_Active((RGE_Scenario *)this->world->_padding_,(int)param_1,param_2);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AB2D0
int TRIBE_Screen_Sed_unit_list_compare(void* param_1, void* param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* int __cdecl TRIBE_Screen_Sed_unit_list_compare(void const *,void const *) */
    // 
    // int __cdecl TRIBE_Screen_Sed_unit_list_compare(void *param_1,void *param_2)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
    //   if (iVar1 == 1) {
    //     return -1;
    //   }
    //   return (uint)(iVar1 == 3);
    // }
    // 
    // 
}

// Offset: 0x004AB300
void set_unit_player(TRIBE_Screen_Sed* this_, short param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: is_error */
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_unit_player(short) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_unit_player(TRIBE_Screen_Sed *this,short param_1)
    // 
    // {
    //   char cVar1;
    //   short sVar2;
    //   float fVar3;
    //   int iVar4;
    //   bool bVar5;
    //   RGE_Player *pRVar6;
    //   List_Info *pLVar7;
    //   undefined4 *puVar8;
    //   int iVar9;
    //   uint uVar10;
    //   uint uVar11;
    //   int iVar12;
    //   short unaff_BX;
    //   short sVar13;
    //   char *pcVar14;
    //   undefined4 *puVar15;
    //   short sVar16;
    //   char *pcVar17;
    //   List_Info *pLVar18;
    //   undefined2 in_stack_00000006;
    //   int is_error;
    //   float save_view_x;
    //   short end_i;
    //   
    //   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //   fVar3 = pRVar6->view_x;
    //   sVar16 = pRVar6->map_x;
    //   save_view_x = (float)CONCAT22(save_view_x._2_2_,pRVar6->map_y);
    //   (**(code **)(rge_base_game->_padding_ + 0x14))(_param_1);
    //   this->player_num = param_1;
    //   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_Player::set_view_loc(pRVar6,save_view_x,fVar3);
    //   RGE_Player::set_map_loc(pRVar6,sVar16,unaff_BX);
    //   RGE_View::set_player((RGE_View *)this->main_view,pRVar6);
    //   RGE_Diamond_Map::set_player((RGE_Diamond_Map *)this->map_view,pRVar6);
    //   TDropDownPanel::setCurrentLineNumber(this->unit_player_list,(int)param_1);
    //   TTextPanel::empty_list((TTextPanel *)this->unit_list);
    //   if (this->unit_list_info != (List_Info *)0x0) {
    //     free(this->unit_list_info);
    //     this->unit_list_info = (List_Info *)0x0;
    //   }
    //   if (pRVar6 != (RGE_Player *)0x0) {
    //     this->unit_list_size = 1;
    //     sVar16 = pRVar6->master_object_num;
    //     if (0 < sVar16) {
    //       iVar9 = 0;
    //       iVar12 = (int)sVar16;
    //       do {
    //         iVar4 = *(int *)(iVar9 + (int)pRVar6->master_objects);
    //         if ((iVar4 != 0) && (*(char *)(iVar4 + 0x4e) == '\0')) {
    //           this->unit_list_size = this->unit_list_size + 1;
    //         }
    //         iVar9 = iVar9 + 4;
    //         iVar12 = iVar12 + -1;
    //       } while (iVar12 != 0);
    //     }
    //     if (this->unit_list_size != 0) {
    //                     /* language.dll match for 0x66: "Copperplate Gothic Light" */
    //       pLVar7 = (List_Info *)calloc((int)this->unit_list_size,0x66);
    //       this->unit_list_info = pLVar7;
    //       if (pLVar7 != (List_Info *)0x0) {
    //         pLVar7->id = -1;
    //                     /* language.dll match for 0x2775: " <None> " */
    //         set_string(this,this->unit_list_info->text,0x2775,0x14);
    //         is_error = 1;
    //         sVar13 = 0;
    //         if (0 < sVar16) {
    //           save_view_x = 0.0;
    //           do {
    //             iVar9 = *(int *)((int)save_view_x + (int)pRVar6->master_objects);
    //             if ((iVar9 != 0) && (*(char *)(iVar9 + 0x4e) == '\0')) {
    //               iVar12 = (int)(short)is_error;
    //               this->unit_list_info[iVar12].id = sVar13;
    //               iVar9 = *(int *)((int)save_view_x + (int)pRVar6->master_objects);
    //               sVar2 = *(short *)(iVar9 + 0xc);
    //               if (sVar2 < 1) {
    //                 uVar10 = 0xffffffff;
    //                 pcVar14 = *(char **)(iVar9 + 8);
    //                 do {
    //                   pcVar17 = pcVar14;
    //                   if (uVar10 == 0) break;
    //                   uVar10 = uVar10 - 1;
    //                   pcVar17 = pcVar14 + 1;
    //                   cVar1 = *pcVar14;
    //                   pcVar14 = pcVar17;
    //                 } while (cVar1 != '\0');
    //                 uVar10 = ~uVar10;
    //                 pcVar14 = pcVar17 + -uVar10;
    //                 pLVar7 = this->unit_list_info + iVar12;
    //                 for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    //                   *(undefined4 *)pLVar7->text = *(undefined4 *)pcVar14;
    //                   pcVar14 = pcVar14 + 4;
    //                   pLVar7 = (List_Info *)(pLVar7->text + 4);
    //                 }
    //                 for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    //                   pLVar7->text[0] = *pcVar14;
    //                   pcVar14 = pcVar14 + 1;
    //                   pLVar7 = (List_Info *)(pLVar7->text + 1);
    //                 }
    //               }
    //               else {
    //                 (**(code **)(rge_base_game->_padding_ + 0x20))
    //                           ((int)sVar2,this->unit_list_info + iVar12,100);
    //               }
    //               is_error = is_error + 1;
    //             }
    //             sVar13 = sVar13 + 1;
    //             save_view_x = (float)((int)save_view_x + 4);
    //           } while (sVar13 < sVar16);
    //         }
    //                     /* language.dll match for 0x66: "Copperplate Gothic Light" */
    //         qsort(this->unit_list_info,(int)this->unit_list_size,0x66,TRIBE_Screen_Sed_unit_list_compare
    //              );
    //         iVar9 = calloc((int)this->unit_list_size,4);
    //         if (iVar9 != 0) {
    //           bVar5 = false;
    //           sVar16 = 0;
    //           sVar13 = 0;
    //           if (0 < this->unit_list_size) {
    //             do {
    //               puVar8 = (undefined4 *)calloc(100,1);
    //               iVar12 = (int)sVar13;
    //               *(undefined4 **)(iVar9 + iVar12 * 4) = puVar8;
    //               if (puVar8 == (undefined4 *)0x0) {
    //                 bVar5 = true;
    //                 break;
    //               }
    //               uVar10 = 0xffffffff;
    //               pLVar7 = this->unit_list_info + iVar12;
    //               do {
    //                 pLVar18 = pLVar7;
    //                 if (uVar10 == 0) break;
    //                 uVar10 = uVar10 - 1;
    //                 pLVar18 = (List_Info *)(pLVar7->text + 1);
    //                 pcVar14 = pLVar7->text;
    //                 pLVar7 = pLVar18;
    //               } while (*pcVar14 != '\0');
    //               uVar10 = ~uVar10;
    //               puVar15 = (undefined4 *)((int)pLVar18 - uVar10);
    //               for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    //                 *puVar8 = *puVar15;
    //                 puVar15 = puVar15 + 1;
    //                 puVar8 = puVar8 + 1;
    //               }
    //               for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    //                 *(undefined1 *)puVar8 = *(undefined1 *)puVar15;
    //                 puVar15 = (undefined4 *)((int)puVar15 + 1);
    //                 puVar8 = (undefined4 *)((int)puVar8 + 1);
    //               }
    //               if (this->unit_list_info[iVar12].id == rge_base_game->master_obj_id) {
    //                 sVar16 = sVar13;
    //               }
    //               sVar13 = sVar13 + 1;
    //             } while (sVar13 < this->unit_list_size);
    //           }
    //           if (!bVar5) {
    //             (**(code **)(this->unit_list->_padding_ + 0xe0))(iVar9,this->unit_list_size);
    //             TListPanel::scroll_cur_line(this->unit_list,'\x01',sVar16,1);
    //           }
    //           sVar16 = 0;
    //           if (0 < this->unit_list_size) {
    //             do {
    //               iVar12 = *(int *)(iVar9 + sVar16 * 4);
    //               if (iVar12 != 0) {
    //                 free(iVar12);
    //               }
    //               sVar16 = sVar16 + 1;
    //             } while (sVar16 < this->unit_list_size);
    //           }
    //           free(iVar9);
    //         }
    //       }
    //     }
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AB670
void set_unit(TRIBE_Screen_Sed* this_, short param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_unit(short) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_unit(TRIBE_Screen_Sed *this,short param_1)
    // 
    // {
    //   if (param_1 == -1) {
    //     rge_base_game->master_obj_id = -1;
    //     TListPanel::scroll_cur_line(this->unit_list,'\x01',-1,1);
    //     return;
    //   }
    //   rge_base_game->master_obj_id = this->unit_list_info[param_1].id;
    //   TListPanel::scroll_cur_line(this->unit_list,'\x01',param_1,1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AB6E0
void set_message_type(TRIBE_Screen_Sed* this_, MessageType param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::set_message_type(enum
    //    TRIBE_Screen_Sed::MessageType,int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::set_message_type(TRIBE_Screen_Sed *this,MessageType param_1,int param_2)
    // 
    // {
    //   (**(code **)(this->message_input->_padding_ + 0x14))(param_2);
    //   (**(code **)(this->bottom_panel->_padding_ + 0x20))(1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AB710
long TRIBE_Screen_Sed::handle_size(long param_1, long param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: virtual long __thiscall TRIBE_Screen_Sed::handle_size(long,long) */
    // 
    // long __thiscall TRIBE_Screen_Sed::handle_size(TRIBE_Screen_Sed *this,long param_1,long param_2)
    // 
    // {
    //   TPanel::handle_size((TPanel *)this,param_1,param_2);
    //   position_panels(this);
    //   TPanel::handle_size((TPanel *)this,param_1,param_2);
    //   return 0;
    // }
    // 
    // 
}

// Offset: 0x004AB740
long TRIBE_Screen_Sed::handle_idle() {
    // --- Ghidra decompiler output ---
    // 
    // /* public: virtual long __thiscall TRIBE_Screen_Sed::handle_idle(void) */
    // 
    // long __thiscall TRIBE_Screen_Sed::handle_idle(TRIBE_Screen_Sed *this)
    // 
    // {
    //   ulong uVar1;
    //   TPanel *pTVar2;
    //   long lVar3;
    //   
    //   if (rge_base_game->prog_mode == 7) {
    //     uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x8b1);
    //     if (this->update_interval <= this->last_update_time - uVar1) {
    //       pTVar2 = TPanelSystem::modalPanel(&panel_system);
    //       if (pTVar2 == (TPanel *)0x0) {
    //         (**(code **)(*(int *)this->main_view + 0x20))(1);
    //         if (this->map_redraw_interval <= this->last_map_redraw_time - uVar1) {
    //           (**(code **)(*(int *)this->map_view + 0x20))(1);
    //           this->last_map_redraw_time = uVar1;
    //         }
    //       }
    //     }
    //   }
    //   lVar3 = TPanel::handle_idle((TPanel *)this);
    //   return lVar3;
    // }
    // 
    // 
}

// Offset: 0x004AB7D0
long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: virtual long __thiscall TRIBE_Screen_Sed::key_down_action(long,short,int,int,int) */
    // 
    // long __thiscall
    // TRIBE_Screen_Sed::key_down_action
    //           (TRIBE_Screen_Sed *this,long param_1,short param_2,int param_3,int param_4,int param_5)
    // 
    // {
    //   ScenarioMode SVar1;
    //   RGE_Static_Object *pRVar2;
    //   uchar uVar3;
    //   TPanel *pTVar4;
    //   int iVar5;
    //   RGE_Player *pRVar6;
    //   short sVar7;
    //   
    //   pTVar4 = TPanelSystem::modalPanel(&panel_system);
    //   if (pTVar4 == (TPanel *)0x0) {
    //     if (param_4 != 0) {
    //       switch(param_1) {
    //       case 0x41:
    //         if (rge_base_game->outline_type != '\x03') {
    //           rge_base_game->outline_type = '\x03';
    //           return 1;
    //         }
    //         rge_base_game->outline_type = '\0';
    //         return 1;
    //       case 0x42:
    //         goto switchD_004ab80d_caseD_42;
    //       case 0x43:
    //         (**(code **)(this->scenario_mode_button[9]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeCinematics);
    //         return 0;
    //       case 0x44:
    //         (**(code **)(this->scenario_mode_button[4]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeDiplomacy);
    //         return 0;
    //       default:
    //         goto switchD_004ab80d_caseD_45;
    //       case 0x49:
    //         (**(code **)(this->scenario_mode_button[5]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeVictory);
    //         return 0;
    //       case 0x4d:
    //         (**(code **)(this->scenario_mode_button[0]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeMap);
    //         return 0;
    //       case 0x4f:
    //         (**(code **)(this->scenario_mode_button[7]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeOptions);
    //         return 0;
    //       case 0x50:
    //         (**(code **)(this->scenario_mode_button[2]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModePlayers);
    //         return 0;
    //       case 0x54:
    //         (**(code **)(this->scenario_mode_button[1]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeTerrain);
    //         return 0;
    //       case 0x55:
    //         (**(code **)(this->scenario_mode_button[3]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeUnits);
    //         return 0;
    //       case 0x56:
    //         (**(code **)(this->scenario_mode_button[6]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeVictoryMulti);
    //         return 0;
    //       case 0x57:
    //         (**(code **)(this->scenario_mode_button[8]->_padding_ + 0xe0))(1);
    //         set_scenario_mode(this,ScenarioModeMessages);
    //         return 0;
    //       }
    //     }
    //     switch(param_1) {
    //     case 9:
    //       if (this->scenario_mode == ScenarioModePlayers) {
    //         if (this->bottom_panel->curr_child == (TPanel *)0x0) {
    //           TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->player_inven_input[0]);
    //           return 0;
    //         }
    //       }
    //       else if (((this->scenario_mode == ScenarioModeVictory) &&
    //                (this->bottom_panel->curr_child == (TPanel *)0x0)) &&
    //               (this->victory_amount_input->_padding_ != 0)) {
    //         TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //         return 0;
    //       }
    //       break;
    //     case 0x1b:
    //       command_cancel(this);
    //       return 0;
    //     case 0x2e:
    //       if (this->scenario_mode == ScenarioModeUnits) {
    //         pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //         pRVar2 = pRVar6->selected_obj;
    //         if (pRVar2 != (RGE_Static_Object *)0x0) {
    //           if (pRVar2->sprite_list == (RGE_Active_Sprite_List *)0x0) {
    //             if (pRVar2->sprite == (RGE_Sprite *)0x0) {
    //               uVar3 = '\x14';
    //             }
    //             else {
    //               uVar3 = RGE_Sprite::get_lowest_draw_level(pRVar2->sprite);
    //             }
    //           }
    //           else {
    //             uVar3 = RGE_Active_Sprite_List::get_lowest_draw_level(pRVar2->sprite_list);
    //           }
    //           (**(code **)pRVar2->_padding_)(1);
    //           if (uVar3 == '\0') {
    //             (**(code **)(*(int *)this->main_view + 0x20))(2);
    //           }
    //         }
    //         return 1;
    //       }
    //       break;
    //     case 0x30:
    //     case 0x31:
    //     case 0x32:
    //     case 0x33:
    //     case 0x34:
    //     case 0x35:
    //     case 0x36:
    //     case 0x37:
    //     case 0x38:
    //       SVar1 = this->scenario_mode;
    //       iVar5 = param_1 + -0x30;
    //       sVar7 = (short)iVar5;
    //       if ((SVar1 == ScenarioModeOptions) && (0 < iVar5)) {
    //         SaveDisabledItemsInScenario(this);
    //         TDropDownPanel::setCurrentLineNumber(this->options_player_list,param_1 + -0x31);
    //         (**(code **)(this->_padding_ + 0xb4))(this->options_player_list,3,0,0);
    //         set_player(this,sVar7,'\0','\0');
    //         this->player_num = sVar7;
    //         LoadDisabledItemsFromScenario(this);
    //         return 0;
    //       }
    //       if ((SVar1 == ScenarioModePlayers) && (0 < iVar5)) {
    //         if (this->bottom_panel->curr_child == (TPanel *)0x0) {
    //           TDropDownPanel::setCurrentLineNumber(this->player_list,param_1 + -0x31);
    //           (**(code **)(this->_padding_ + 0xb4))(this->player_list,0,0,0);
    //           return 0;
    //         }
    //       }
    //       else {
    //         if (SVar1 == ScenarioModeUnits) {
    //           TDropDownPanel::setCurrentLineNumber(this->unit_player_list,iVar5);
    //           (**(code **)(this->_padding_ + 0xb4))(this->unit_player_list,0,0,0);
    //           return 0;
    //         }
    //         if ((SVar1 == ScenarioModeVictory) && (0 < iVar5)) {
    //           if (this->bottom_panel->curr_child == (TPanel *)0x0) {
    //             TDropDownPanel::setCurrentLineNumber(this->victory_player_list,param_1 + -0x31);
    //             (**(code **)(this->_padding_ + 0xb4))(this->victory_player_list,1,0,0);
    //             return 0;
    //           }
    //         }
    //         else if (SVar1 == ScenarioModeDiplomacy) {
    //           if (0 < iVar5) {
    //             TDropDownPanel::setCurrentLineNumber(this->Diplomacy_player_list,param_1 + -0x31);
    //             (**(code **)(this->_padding_ + 0xb4))(this->Diplomacy_player_list,1,0,0);
    //             return 0;
    //           }
    //         }
    //         else if (0 < iVar5) {
    //           set_player(this,sVar7,'\0','\0');
    //           this->player_num = sVar7;
    //           return 0;
    //         }
    //       }
    //     }
    //   }
    // switchD_004ab80d_caseD_45:
    //   return 0;
    // switchD_004ab80d_caseD_42:
    //   View_Grid_Mode = View_Grid_Mode + 1;
    //   iVar5 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
    //   if (iVar5 == 0) {
    //     if (View_Grid_Mode < 2) goto LAB_004ab9ba;
    //   }
    //   else if (View_Grid_Mode < 5) goto LAB_004ab9ba;
    //   View_Grid_Mode = 0;
    // LAB_004ab9ba:
    //   (**(code **)(*(int *)this->main_view + 0x20))(2);
    //   return 0;
    // }
    // 
    // 
}

// Offset: 0x004ABC31
undefined FUN_004abc31() {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    //     */
    // /* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
    // /* WARNING: This function may have set the stack pointer */
    // 
    // undefined4 FUN_004abc31(void)
    // 
    // {
    //   undefined1 *puVar1;
    //   int *piVar2;
    //   int iVar3;
    //   byte bVar4;
    //   TEditPanel *pTVar5;
    //   TRIBE_World *pTVar6;
    //   RGE_Scenario *pRVar7;
    //   TDropDownPanel *pTVar8;
    //   TPanel *pTVar9;
    //   TRIBE_Main_View *pTVar10;
    //   TTextPanel *pTVar11;
    //   MapType MVar12;
    //   undefined4 *puVar13;
    //   RGE_Map *pRVar14;
    //   TRIBE_Scenario_Editor_Panel_Object *pTVar15;
    //   TButtonPanel *pTVar16;
    //   code *pcVar17;
    //   TRIBE_Main_View *pTVar18;
    //   T_Scenario *pTVar19;
    //   float fVar20;
    //   RGE_Base_Game *pRVar21;
    //   char in_AL;
    //   byte bVar22;
    //   short sVar23;
    //   int iVar24;
    //   undefined4 uVar25;
    //   RGE_Player *pRVar26;
    //   int iVar27;
    //   char *pcVar28;
    //   byte *pbVar29;
    //   long lVar30;
    //   int extraout_EAX;
    //   undefined2 extraout_var;
    //   undefined2 extraout_var_00;
    //   undefined2 uVar32;
    //   TButtonPanel **ppTVar31;
    //   TRIBE_Screen_Sed_Open *this;
    //   TRIBE_Screen_Sed *this_00;
    //   TEditPanel **ppTVar33;
    //   undefined2 extraout_var_01;
    //   char *unaff_EBX;
    //   undefined1 *puVar34;
    //   undefined4 *puVar35;
    //   undefined4 *puVar36;
    //   undefined4 *puVar37;
    //   undefined4 *puVar38;
    //   undefined1 *puVar39;
    //   undefined1 *puVar40;
    //   undefined1 *puVar41;
    //   undefined1 *puVar42;
    //   undefined4 *puVar43;
    //   undefined4 *puVar44;
    //   undefined1 *puVar45;
    //   undefined4 *puVar46;
    //   undefined4 *puVar47;
    //   undefined4 *puVar48;
    //   undefined4 *puVar49;
    //   undefined4 *puVar50;
    //   undefined1 *puVar51;
    //   undefined1 *puVar52;
    //   undefined1 *puVar53;
    //   undefined1 *puVar54;
    //   undefined1 *puVar55;
    //   undefined1 *puVar56;
    //   undefined1 *puVar57;
    //   undefined4 unaff_EBP;
    //   int unaff_ESI;
    //   RGE_Static_Object *pRVar58;
    //   int unaff_EDI;
    //   byte *pbVar59;
    //   undefined4 *unaff_FS_OFFSET;
    //   char in_CF;
    //   bool bVar60;
    //   
    //   *(char *)(unaff_EDI + 0x66004ab9) = *(char *)(unaff_EDI + 0x66004ab9) + in_AL + -0x48 + in_CF;
    //   puVar1 = (undefined1 *)(unaff_EDI * 4 + -0x473effb6);
    //   *puVar1 = *puVar1;
    //   *(char *)(unaff_EDI + -0x48) = *(char *)(unaff_EDI + -0x48) + (char)((uint)unaff_EBX >> 8);
    //   *(char *)(unaff_ESI + -0x48) = *(char *)(unaff_ESI + -0x48) + (char)unaff_EBX;
    //   iVar24 = (CONCAT31(0xb83d00,(*unaff_EBX + 0x4aU | 0xc) + 0xc) | 0xc) + 0xc07060c;
    //   bVar4 = (byte)iVar24;
    //   bVar22 = bVar4 | 0xc;
    //   bRamb945004a = bRamb945004a | 0x4a;
    //   this_00 = (TRIBE_Screen_Sed *)CONCAT22(0xb945,CONCAT11(bVar4,*unaff_EBX) | 0xc4a);
    //   pcRam01000046 = unaff_EBX;
    //   *(byte *)&this_00->_padding_ = (char)this_00->_padding_ + bVar22;
    //   iVar24 = CONCAT31((int3)((uint)iVar24 >> 8),bVar22 + 0x20);
    //   piVar2 = (int *)(iVar24 + 0x400004a);
    //   *piVar2 = *piVar2 + iVar24;
    //   uRam0400003e = *unaff_FS_OFFSET;
    //   uRam04000046 = 0xffffffff;
    //   pcRam04000042 = FUN_0055f48b;
    //   *unaff_FS_OFFSET = 0x400003e;
    //   pTVar10 = pTRam0400004e;
    //   uRam04000012 = 0xb9ee004a;
    //   puVar34 = (undefined1 *)0x4000006;
    //   iRam04000006 = unaff_EDI;
    //   iRam0400000a = unaff_ESI;
    //   uRam0400000e = unaff_EBP;
    //   if (pTRam0400004e == (TRIBE_Main_View *)0x0) {
    //     uVar25 = 0;
    //     goto LAB_004abe5f;
    //   }
    //   if (pTRam0400004e != this_00->main_view) {
    //     if (this_00->SelectedObject != (RGE_Static_Object *)0x0) {
    //       iRam04000002 = 0;
    //       uRam03fffffa = 0x4abd1d;
    //       pRRam03fffffe = this_00->SelectedObject;
    //       pRVar26 = RGE_Base_Game::get_player(rge_base_game);
    //       uRam03fffffa = 0x4abd24;
    //       RGE_Player::select_one_object(pRVar26,pRRam03fffffe,iRam04000002);
    //     }
    //     if (this_00->DestinationObject != (RGE_Static_Object *)0x0) {
    //       iRam04000002 = 0;
    //       uRam03fffffa = 0x4abd3c;
    //       pRRam03fffffe = this_00->DestinationObject;
    //       pRVar26 = RGE_Base_Game::get_player(rge_base_game);
    //       uRam03fffffa = 0x4abd43;
    //       RGE_Player::select_one_object(pRVar26,pRRam03fffffe,iRam04000002);
    //     }
    //   }
    //   iVar24 = iRam04000052;
    //   puVar34 = (undefined1 *)0x4000006;
    //   if ((iRam04000052 == 0) &&
    //      (((((((pTVar10 == (TRIBE_Main_View *)this_00->random_seed_input ||
    //            (pTVar10 == (TRIBE_Main_View *)this_00->player_inven_input[0])) ||
    //           (pTVar10 == (TRIBE_Main_View *)this_00->player_inven_input[1])) ||
    //          ((pTVar10 == (TRIBE_Main_View *)this_00->player_inven_input[2] ||
    //           (pTVar10 == (TRIBE_Main_View *)this_00->player_inven_input[3])))) ||
    //         (pTVar10 == (TRIBE_Main_View *)this_00->player_inven_input[4])) ||
    //        (((pTVar10 == (TRIBE_Main_View *)this_00->player_setting_label[0] ||
    //          (pTVar10 == (TRIBE_Main_View *)this_00->victory_condition_explore)) ||
    //         ((pTVar10 == (TRIBE_Main_View *)this_00->victory_condition_ruins ||
    //          (((pTVar10 == (TRIBE_Main_View *)this_00->victory_condition_artifacts ||
    //            (pTVar10 == (TRIBE_Main_View *)this_00->victory_condition_discoveries)) ||
    //           (pTVar10 == (TRIBE_Main_View *)this_00->victory_condition_gold)))))))) ||
    //       ((pTVar10 == (TRIBE_Main_View *)this_00->victory_amount_input ||
    //        (pTVar10 == (TRIBE_Main_View *)this_00->message_input)))))) {
    //     this_00->need_to_save_flag = '\x01';
    //   }
    //   if (pTVar10 == this_00->main_view) {
    //     if (iVar24 != 0x10) {
    //       if ((iVar24 == 0x11) && (rge_base_game->game_mode == 0x11)) {
    //         iRam04000002 = 0;
    //         pRRam03fffffe = (RGE_Static_Object *)0x0;
    //         puVar34 = (undefined1 *)0x3fffffa;
    //         uRam03fffffa = 0x4abe90;
    //         (**(code **)(rge_base_game->_padding_ + 0x10))();
    //       }
    //       goto LAB_004abe90;
    //     }
    //     iRam04000002 = 0x4abde2;
    //     pRVar26 = RGE_Base_Game::get_player(rge_base_game);
    //     iRam04000002 = 0x4abde9;
    //     RGE_Player::unselect_object(pRVar26);
    //     pRVar58 = pRRam04000056;
    //     if (this_00->SelectRegionFlag == SELECT_OBJECT) {
    //       this_00->SelectedObject = pRRam04000056;
    //     }
    //     if (this_00->SelectRegionFlag == SELECT_DEST_OBJECT) {
    //       this_00->DestinationObject = pRVar58;
    //     }
    //     pRRam03fffffe = this_00->SelectedObject;
    //     if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
    //       iRam04000002 = 0;
    //       uRam03fffffa = 0x4abe25;
    //       pRVar26 = RGE_Base_Game::get_player(rge_base_game);
    //       uRam03fffffa = 0x4abe2c;
    //       RGE_Player::select_one_object(pRVar26,pRRam03fffffe,iRam04000002);
    //     }
    //     pRRam03fffffe = this_00->DestinationObject;
    //     if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
    //       iRam04000002 = 0;
    //       uRam03fffffa = 0x4abe44;
    //       pRVar26 = RGE_Base_Game::get_player(rge_base_game);
    //       uRam03fffffa = 0x4abe4b;
    //       RGE_Player::select_one_object(pRVar26,pRRam03fffffe,iRam04000002);
    //     }
    //     iRam04000002 = 0;
    //     pRRam03fffffe = (RGE_Static_Object *)0x0;
    //     puVar34 = (undefined1 *)0x3fffffa;
    //     uRam03fffffa = 0x4abe5a;
    //     (**(code **)(rge_base_game->_padding_ + 0x10))();
    //   }
    //   else {
    // LAB_004abe90:
    //     if (iVar24 == 1) {
    //       iVar27 = 0;
    //       ppTVar31 = this_00->scenario_mode_button;
    //       do {
    //         if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //           *(int *)(puVar34 + -4) = iVar27 + 1;
    //           *(undefined4 *)(puVar34 + -8) = 0x4ad069;
    //           TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar34 + -4));
    //           goto LAB_004abe5a;
    //         }
    //         iVar27 = iVar27 + 1;
    //         ppTVar31 = ppTVar31 + 1;
    //       } while (iVar27 < 10);
    //       if (pTVar10 == (TRIBE_Main_View *)this_00->menu_button) {
    //         *(undefined4 *)(puVar34 + -4) = 0x4abebd;
    //         TRIBE_Screen_Sed::command_menu(this_00);
    //       }
    //       else {
    //         if (pTVar10 != (TRIBE_Main_View *)this_00->help_button) goto LAB_004abf01;
    //         *(undefined4 *)(puVar34 + -4) = 0x4abece;
    //         TEasy_Panel::setup_popup_help((TEasy_Panel *)this_00);
    //       }
    //     }
    //     else {
    //       iVar27 = 0;
    //       ppTVar31 = this_00->scenario_mode_button;
    //       do {
    //         if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) goto LAB_004abe5a;
    //         iVar27 = iVar27 + 1;
    //         ppTVar31 = ppTVar31 + 1;
    //       } while (iVar27 < 10);
    //       if ((pTVar10 != (TRIBE_Main_View *)this_00->menu_button) &&
    //          (pTVar10 != (TRIBE_Main_View *)this_00->help_button)) {
    // LAB_004abf01:
    //         *(undefined4 *)(puVar34 + -4) = 0x4abf08;
    //         pcVar28 = TPanel::panelName((TPanel *)pTVar10);
    //         if (pcVar28 != (char *)0x0) {
    //           pbVar59 = &s_OKDialog;
    //           *(undefined4 *)(puVar34 + -4) = 0x4abf18;
    //           pbVar29 = (byte *)TPanel::panelName((TPanel *)pTVar10);
    //           do {
    //             bVar4 = *pbVar29;
    //             bVar60 = bVar4 < *pbVar59;
    //             if (bVar4 != *pbVar59) {
    // LAB_004abf3c:
    //               iVar27 = (1 - (uint)bVar60) - (uint)(bVar60 != 0);
    //               goto LAB_004abf41;
    //             }
    //             if (bVar4 == 0) break;
    //             bVar4 = pbVar29[1];
    //             bVar60 = bVar4 < pbVar59[1];
    //             if (bVar4 != pbVar59[1]) goto LAB_004abf3c;
    //             pbVar29 = pbVar29 + 2;
    //             pbVar59 = pbVar59 + 2;
    //           } while (bVar4 != 0);
    //           iVar27 = 0;
    // LAB_004abf41:
    //           if (iVar27 == 0) {
    //             if (iVar24 == 0) {
    //               *(undefined1 **)(puVar34 + -4) = &s_OKDialog;
    //               *(undefined4 *)(puVar34 + -8) = 0x4abf5c;
    //               TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar34 + -4));
    //               *(undefined4 *)(puVar34 + -4) = 3;
    //               *(undefined4 *)(puVar34 + -8) = 0x4abf65;
    //               TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar34 + -4));
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         switch(this_00->scenario_mode) {
    //         case ScenarioModeMap:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 1) {
    //             iVar27 = 0;
    //             ppTVar31 = this_00->map_type_button;
    //             do {
    //               if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //                 *(undefined4 *)(puVar34 + -4) = 1;
    //                 *(int *)(puVar34 + -8) = iVar27 + 1;
    //                 *(undefined4 *)(puVar34 + -0xc) = 0x4ac4f8;
    //                 TRIBE_Screen_Sed::set_map_type
    //                           (this_00,*(MapType *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                 goto LAB_004abe5a;
    //               }
    //               iVar27 = iVar27 + 1;
    //               ppTVar31 = ppTVar31 + 1;
    //             } while (iVar27 < 3);
    //             if (pTVar10 == (TRIBE_Main_View *)this_00->generate_map_button) {
    //               pTVar11 = this_00->map_generating_text;
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               pcVar17 = *(code **)(pTVar11->_padding_ + 0x14);
    //               puVar39 = puVar34 + -8;
    //               *(undefined4 *)(puVar34 + -8) = 0x4ac516;
    //               (*pcVar17)();
    //               iVar24 = this_00->_padding_;
    //               *(undefined4 *)(puVar39 + -4) = 2;
    //               pcVar17 = *(code **)(iVar24 + 0x20);
    //               puVar40 = puVar39 + -8;
    //               *(undefined4 *)(puVar39 + -8) = 0x4ac51f;
    //               (*pcVar17)();
    //               pRVar21 = rge_base_game;
    //               *(undefined4 *)(puVar40 + -4) = 0;
    //               *(undefined4 *)(puVar40 + -8) = 0;
    //               *(void **)(puVar40 + -0xc) = pRVar21->prog_window;
    //               puVar41 = puVar40 + -0x10;
    //               *(undefined4 *)(puVar40 + -0x10) = 0x4ac533;
    //               InvalidateRect();
    //               pRVar21 = rge_base_game;
    //               *(undefined4 *)(puVar41 + -4) = 0x4ac53e;
    //               RGE_Base_Game::draw_window(pRVar21);
    //               pTVar8 = this_00->map_size_drop;
    //               *(undefined4 *)(puVar41 + -4) = 0x4ac549;
    //               iVar24 = TDropDownPanel::currentLineNumber(pTVar8);
    //               pTVar8 = this_00->map_style_drop;
    //               *(undefined4 *)(puVar41 + -4) = 0x4ac556;
    //               iVar27 = TDropDownPanel::currentLineNumber(pTVar8);
    //               *(int *)(puVar41 + 0x4c) = iVar27;
    //               switch(iVar24) {
    //               case 0:
    //                 iVar24 = 0x48;
    //                 break;
    //               case 1:
    //                 iVar24 = 0x60;
    //                 break;
    //               case 2:
    //                 iVar24 = 0x78;
    //                 break;
    //               case 3:
    //                 iVar24 = 0x90;
    //                 break;
    //               case 4:
    //                 iVar24 = 200;
    //                 break;
    //               case 5:
    //                 iVar24 = 0xfa;
    //                 break;
    //               default:
    //                 iVar24 = *(int *)(puVar41 + 0x4c);
    //               }
    //               pTVar8 = this_00->player_number_list;
    //               *(undefined4 *)(puVar41 + -4) = 0x4ac59f;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               pRVar21 = rge_base_game;
    //               MVar12 = this_00->map_type;
    //               if (MVar12 == MapTypeBlank) {
    //                 pTVar8 = this_00->default_terrain_drop;
    //                 *(undefined4 *)(puVar41 + -4) = 0x4ac5bc;
    //                 iVar27 = TDropDownPanel::currentLineNumber(pTVar8);
    //                 switch(iVar27) {
    //                 case 0:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 0;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac5e5;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 1:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 6;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac603;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 2:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 10;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac621;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 3:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 1;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac63f;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 4:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 0xd;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac65d;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 5:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 0x14;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac67b;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 6:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 4;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac699;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 7:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 0x13;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac6b7;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                   break;
    //                 case 8:
    //                   pTVar6 = this_00->world;
    //                   *(int *)(puVar41 + -4) = iVar24;
    //                   *(int *)(puVar41 + -8) = iVar24;
    //                   *(undefined4 *)(puVar41 + -0xc) = 0x16;
    //                   puVar13 = (undefined4 *)pTVar6->_padding_;
    //                   *(TRIBE_World **)(puVar41 + -0x10) = pTVar6;
    //                   pRVar14 = (RGE_Map *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar41 + -0x14) = *puVar13;
    //                   *(undefined4 *)(puVar41 + -0x18) = 0x4ac6d5;
    //                   RGE_Map::clear_map(pRVar14,*(RGE_Player **)(puVar41 + -0x14),
    //                                      *(RGE_Game_World **)(puVar41 + -0x10),puVar41[-0xc],
    //                                      *(long *)(puVar41 + -8),*(long *)(puVar41 + -4));
    //                 }
    //               }
    //               else {
    //                 *(int *)(puVar41 + 0x48) = rge_base_game->random_map_seed;
    //                 if (MVar12 == MapTypeSeed) {
    //                   pTVar5 = this_00->random_seed_input;
    //                   *(undefined4 *)(puVar41 + -4) = 0x4ac6f7;
    //                   pcVar28 = TEditPanel::currentLine(pTVar5);
    //                   *(char **)(puVar41 + -4) = pcVar28;
    //                   *(undefined4 *)(puVar41 + -8) = 0x4ac6fd;
    //                   iVar27 = atoi();
    //                   rge_base_game->random_map_seed = iVar27;
    //                 }
    //                 else {
    //                   pRVar21->random_map_seed = -1;
    //                 }
    //                 iVar27 = 0;
    //                 do {
    //                   pRVar26 = *(RGE_Player **)(this_00->world->_padding_ + iVar27);
    //                   *(undefined4 *)(puVar41 + -4) = 0x4ac725;
    //                   RGE_Player::reset_selected(pRVar26);
    //                   iVar27 = iVar27 + 4;
    //                 } while (iVar27 < 0x24);
    //                 pTVar6 = this_00->world;
    //                 *(long *)(puVar41 + -4) = lVar30 + 1;
    //                 piVar2 = (int *)pTVar6->_padding_;
    //                 *(undefined4 *)(puVar41 + -8) = *(undefined4 *)(puVar41 + 0x4c);
    //                 *(int *)(puVar41 + -0xc) = iVar24;
    //                 *(int *)(puVar41 + -0x10) = iVar24;
    //                 iVar27 = *piVar2;
    //                 *(TRIBE_World **)(puVar41 + -0x14) = pTVar6;
    //                 pcVar17 = *(code **)(iVar27 + 0x28);
    //                 puVar42 = puVar41 + -0x18;
    //                 *(undefined4 *)(puVar41 + -0x18) = 0x4ac744;
    //                 (*pcVar17)();
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar42 + -4) = 10;
    //                 pRVar21->random_map_seed = *(int *)(puVar42 + 0x48);
    //                 pRVar21 = rge_base_game;
    //                 *(undefined1 **)(puVar42 + -8) = puVar42 + 0x20;
    //                 *(int *)(puVar42 + -0xc) = pRVar21->save_random_map_seed;
    //                 *(undefined4 *)(puVar42 + -0x10) = 0x4ac765;
    //                 itoa();
    //                 iVar27 = this_00->random_seed_used_text->_padding_;
    //                 *(undefined1 **)(puVar42 + -4) = puVar42 + 0x20;
    //                 pcVar17 = *(code **)(iVar27 + 0xe8);
    //                 puVar41 = puVar42 + -8;
    //                 *(undefined4 *)(puVar42 + -8) = 0x4ac77b;
    //                 (*pcVar17)();
    //                 *(undefined4 *)(puVar41 + -4) = 0xb58;
    //                 *(char **)(puVar41 + -8) = s_C__msdev_work_age1_x1_scr_sed_cp;
    //                 *(undefined4 *)(puVar41 + -0xc) = 0x4ac78a;
    //                 debug_rand(*(char **)(puVar41 + -8),*(int *)(puVar41 + -4));
    //               }
    //               iVar24 = iVar24 / 2;
    //               *(int *)(puVar41 + 0x4c) = iVar24;
    //               iVar27 = 0;
    //               *(float *)(puVar41 + 0x4c) = (float)*(int *)(puVar41 + 0x4c);
    //               uVar25 = *(undefined4 *)(puVar41 + 0x4c);
    //               do {
    //                 pTVar6 = this_00->world;
    //                 *(int *)(puVar41 + -4) = iVar24;
    //                 *(int *)(puVar41 + -8) = iVar24;
    //                 pRVar26 = *(RGE_Player **)(pTVar6->_padding_ + iVar27);
    //                 *(undefined4 *)(puVar41 + -0xc) = 0x4ac7bb;
    //                 RGE_Player::set_map_loc(pRVar26,*(short *)(puVar41 + -8),*(short *)(puVar41 + -4));
    //                 pTVar6 = this_00->world;
    //                 *(undefined4 *)(puVar41 + -4) = uVar25;
    //                 *(undefined4 *)(puVar41 + -8) = uVar25;
    //                 pRVar26 = *(RGE_Player **)(pTVar6->_padding_ + iVar27);
    //                 *(undefined4 *)(puVar41 + -0xc) = 0x4ac7ce;
    //                 RGE_Player::set_view_loc(pRVar26,*(float *)(puVar41 + -8),*(float *)(puVar41 + -4));
    //                 iVar27 = iVar27 + 4;
    //               } while (iVar27 < 0x20);
    //               iVar24 = 0;
    //               do {
    //                 iVar27 = *(int *)(this_00->world->_padding_ + iVar24);
    //                 *(undefined4 *)(puVar41 + -4) = 0x4ac7ec;
    //                 RGE_Tile_List::del_list((RGE_Tile_List *)(iVar27 + 0x58));
    //                 pRVar26 = *(RGE_Player **)(this_00->world->_padding_ + iVar24);
    //                 *(undefined4 *)(puVar41 + -4) = 0x4ac7fd;
    //                 RGE_Player::set_map_visible(pRVar26);
    //                 iVar24 = iVar24 + 4;
    //               } while (iVar24 < 0x20);
    //               *(undefined4 *)(puVar41 + -4) = 0x4ac80c;
    //               TRIBE_Screen_Sed::set_panel_info(this_00);
    //               pTVar11 = this_00->map_generating_text;
    //               *(undefined4 *)(puVar41 + -4) = 0;
    //               pcVar17 = *(code **)(pTVar11->_padding_ + 0x14);
    //               puVar34 = puVar41 + -8;
    //               *(undefined4 *)(puVar41 + -8) = 0x4ac81b;
    //               (*pcVar17)();
    //               goto LAB_004abe5a;
    //             }
    //           }
    //           break;
    //         case ScenarioModeTerrain:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if ((iVar24 == 2) || (iVar24 == 1)) {
    //             pTVar18 = (TRIBE_Main_View *)this_00->paint_terrain_list;
    //             if (pTVar10 == pTVar18) {
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac84e;
    //               iVar24 = TTextPanel::currentLineNumber((TTextPanel *)pTVar18);
    //               *(int *)(puVar34 + -4) = iVar24;
    //               *(undefined4 *)(puVar34 + -8) = 0x4ac856;
    //               TRIBE_Screen_Sed::set_terrain(this_00,*(short *)(puVar34 + -4));
    //               pTVar16 = this_00->brush_size_button[0];
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               pcVar17 = *(code **)(pTVar16->_padding_ + 0x14);
    //               puVar43 = (undefined4 *)(puVar34 + -8);
    //               puVar34 = puVar34 + -8;
    //               *puVar43 = 0x4ac865;
    //               (*pcVar17)();
    //             }
    //             else {
    //               pTVar18 = (TRIBE_Main_View *)this_00->paint_elevation_list;
    //               if (pTVar10 != pTVar18) {
    //                 if (iVar24 == 1) {
    //                   if (this_00->valid_save_spot_flag != '\0') {
    //                     this_00->need_to_save_flag = '\x01';
    //                   }
    //                   iVar27 = 0;
    //                   ppTVar31 = this_00->brush_size_button;
    //                   do {
    //                     if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //                       *(int *)(puVar34 + -4) = iVar27 + 1;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac8bf;
    //                       TRIBE_Screen_Sed::set_brush_size(this_00,*(BrushSize *)(puVar34 + -4));
    //                       goto LAB_004abe5a;
    //                     }
    //                     iVar27 = iVar27 + 1;
    //                     ppTVar31 = ppTVar31 + 1;
    //                   } while (iVar27 < 5);
    //                   iVar27 = 0;
    //                   ppTVar31 = this_00->paint_type_button;
    //                   do {
    //                     if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //                       *(undefined4 *)(puVar34 + -4) = 1;
    //                       *(int *)(puVar34 + -8) = iVar27 + 1;
    //                       *(undefined4 *)(puVar34 + -0xc) = 0x4ac8e9;
    //                       TRIBE_Screen_Sed::set_paint_type
    //                                 (this_00,*(PaintType *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                       goto LAB_004abe5a;
    //                     }
    //                     iVar27 = iVar27 + 1;
    //                     ppTVar31 = ppTVar31 + 1;
    //                   } while (iVar27 < 3);
    //                 }
    //                 break;
    //               }
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac879;
    //               iVar24 = TTextPanel::currentLineNumber((TTextPanel *)pTVar18);
    //               *(int *)(puVar34 + -4) = iVar24;
    //               *(undefined4 *)(puVar34 + -8) = 0x4ac881;
    //               TRIBE_Screen_Sed::set_elevation(this_00,*(short *)(puVar34 + -4));
    //             }
    //             goto LAB_004abe5a;
    //           }
    //           break;
    //         case ScenarioModePlayers:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 0) {
    //             iVar27 = 0;
    //             ppTVar33 = this_00->player_inven_input;
    //             do {
    //               if (pTVar10 == (TRIBE_Main_View *)*ppTVar33) {
    //                 pTVar9 = this_00->bottom_panel;
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0x4ac92b;
    //                 TPanel::set_curr_child(pTVar9,*(TPanel **)(puVar34 + -4));
    //                 iVar27 = extraout_EAX;
    //                 break;
    //               }
    //               iVar27 = iVar27 + 1;
    //               ppTVar33 = ppTVar33 + 1;
    //             } while (iVar27 < 5);
    //             uVar32 = (undefined2)((uint)iVar27 >> 0x10);
    //             if (this_00->valid_save_spot_flag != '\0') {
    //               this_00->need_to_save_flag = '\x01';
    //             }
    //             pTVar18 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop;
    //             if (pTVar10 == pTVar18) {
    //               if (this_00->valid_save_spot_flag != '\0') {
    //                 this_00->need_to_save_flag = '\x01';
    //               }
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac964;
    //               iVar27 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar18);
    //               pTVar6 = this_00->world;
    //               *(int *)(puVar34 + -4) = iVar27;
    //               pTVar19 = (T_Scenario *)pTVar6->_padding_;
    //               *(int *)(puVar34 + -8) = this_00->player_num + -1;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac97c;
    //               T_Scenario::SetPlayerAge(pTVar19,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //               uVar32 = extraout_var;
    //             }
    //             pTVar18 = (TRIBE_Main_View *)this_00->player_list;
    //             if (pTVar10 == pTVar18) {
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               *(undefined4 *)(puVar34 + -8) = 1;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac98f;
    //               lVar30 = TDropDownPanel::get_line((TDropDownPanel *)pTVar18);
    //               *(long *)(puVar34 + -0xc) = lVar30 + 1;
    //               *(undefined4 *)(puVar34 + -0x10) = 0x4ac998;
    //               TRIBE_Screen_Sed::set_player
    //                         (this_00,*(short *)(puVar34 + -0xc),puVar34[-8],puVar34[-4]);
    //               pTVar8 = this_00->player_list;
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac9a3;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               pTVar6 = this_00->world;
    //               *(long *)(puVar34 + -4) = lVar30;
    //               pTVar19 = (T_Scenario *)pTVar6->_padding_;
    //               *(undefined4 *)(puVar34 + -8) = 0x4ac9b2;
    //               iVar27 = T_Scenario::GetPlayerAge(pTVar19,*(int *)(puVar34 + -4));
    //               pTVar8 = this_00->player_advance_civilization_drop;
    //               *(int *)(puVar34 + -4) = iVar27;
    //               *(undefined4 *)(puVar34 + -8) = 0x4ac9be;
    //               TDropDownPanel::setCurrentLineNumber(pTVar8,*(int *)(puVar34 + -4));
    //               uVar32 = extraout_var_00;
    //             }
    //             if (pTVar10 == (TRIBE_Main_View *)this_00->player_number_list) {
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar34 + -4) = 0;
    //               *(undefined4 *)(puVar34 + -8) = 1;
    //               *(uint *)(puVar34 + -0xc) = CONCAT22(uVar32,sVar23);
    //               *(undefined4 *)(puVar34 + -0x10) = 0x4ac9d9;
    //               TRIBE_Screen_Sed::set_player
    //                         (this_00,*(short *)(puVar34 + -0xc),puVar34[-8],puVar34[-4]);
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac9e0;
    //               TRIBE_Screen_Sed::SavePlayerActiveStatus(this_00);
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               *(undefined4 *)(puVar34 + -8) = 0;
    //               *(uint *)(puVar34 + -0xc) = CONCAT22(extraout_var_01,sVar23);
    //               *(undefined4 *)(puVar34 + -0x10) = 0x4ac9f3;
    //               TRIBE_Screen_Sed::set_player
    //                         (this_00,*(short *)(puVar34 + -0xc),puVar34[-8],puVar34[-4]);
    //             }
    //           }
    //           if ((iVar24 == 1) &&
    //              (pTVar18 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop,
    //              pTVar10 == pTVar18)) {
    //             *(undefined4 *)(puVar34 + -4) = 0x4aca0f;
    //             iVar27 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar18);
    //             sVar23 = this_00->player_num;
    //             *(int *)(puVar34 + -4) = iVar27;
    //             pTVar19 = (T_Scenario *)this_00->world->_padding_;
    //             *(int *)(puVar34 + -8) = sVar23 + -1;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4aca27;
    //             T_Scenario::SetPlayerAge(pTVar19,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //           }
    //           break;
    //         case ScenarioModeUnits:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 0) {
    //             if (this_00->valid_save_spot_flag != '\0') {
    //               this_00->need_to_save_flag = '\x01';
    //             }
    //             pTVar18 = (TRIBE_Main_View *)this_00->unit_player_list;
    //             if (pTVar10 == pTVar18) {
    //               *(undefined4 *)(puVar34 + -4) = 0x4aca69;
    //               lVar30 = TDropDownPanel::get_line((TDropDownPanel *)pTVar18);
    //               *(long *)(puVar34 + -4) = lVar30;
    //               *(undefined4 *)(puVar34 + -8) = 0x4aca71;
    //               TRIBE_Screen_Sed::set_unit_player(this_00,*(short *)(puVar34 + -4));
    //               pTVar8 = this_00->unit_player_list;
    //               *(undefined4 *)(puVar34 + -4) = 0x4aca7c;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               iVar27 = rge_base_game->_padding_;
    //               if (lVar30 != 0) {
    //                 iVar24 = rge_base_game->game_mode;
    //                 *(undefined4 *)(puVar34 + -4) = 4;
    //                 *(int *)(puVar34 + -8) = iVar24;
    //                 pcVar17 = *(code **)(iVar27 + 0x10);
    //                 puVar45 = puVar34 + -0xc;
    //                 *(undefined4 *)(puVar34 + -0xc) = 0x4acaa5;
    //                 (*pcVar17)();
    //                 pRVar21 = rge_base_game;
    //                 if (rge_base_game->master_obj_id == -1) {
    // LAB_004acaf8:
    //                   *(undefined4 *)(puVar45 + -4) = 0;
    //                   *(undefined4 *)(puVar45 + -8) = 0;
    //                 }
    //                 else {
    //                   *(undefined4 *)(puVar45 + -4) = 0x4acaba;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   pRVar21 = rge_base_game;
    //                   if (pRVar26 == (RGE_Player *)0x0) goto LAB_004acaf8;
    //                   sVar23 = rge_base_game->master_obj_id;
    //                   *(undefined4 *)(puVar45 + -4) = 0x4acad0;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   pRVar21 = rge_base_game;
    //                   *(RGE_Player **)(puVar45 + -4) = pRVar26;
    //                   *(undefined4 *)(puVar45 + -8) = 0x4acadc;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   *(undefined4 *)(puVar45 + -8) =
    //                        *(undefined4 *)
    //                         (*(int *)(*(int *)(this_00->world->_padding_ + pRVar26->id * 4) + 0x24) +
    //                         sVar23 * 4);
    //                 }
    //                 pTVar15 = this_00->object_panel;
    //                 *(undefined4 *)(puVar45 + -0xc) = 0x4acb07;
    //                 TRIBE_Scenario_Editor_Panel_Object::set_master_info
    //                           (pTVar15,*(RGE_Master_Static_Object **)(puVar45 + -8),
    //                            *(TRIBE_Player **)(puVar45 + -4));
    //                 *(undefined4 *)(puVar45 + -4) = 0x4acb0e;
    //                 TRIBE_Screen_Sed::set_paint_object_mode(this_00);
    //                 pTVar15 = this_00->object_panel;
    //                 *(undefined4 *)(puVar45 + -4) = 2;
    //                 pcVar17 = *(code **)(pTVar15->_padding_ + 0x20);
    //                 puVar34 = puVar45 + -8;
    //                 *(undefined4 *)(puVar45 + -8) = 0x4acb1d;
    //                 (*pcVar17)();
    //                 goto LAB_004abe5a;
    //               }
    //               iVar3 = rge_base_game->game_mode;
    //               *(undefined4 *)(puVar34 + -4) = 3;
    //               *(int *)(puVar34 + -8) = iVar3;
    //               pcVar17 = *(code **)(iVar27 + 0x10);
    //               puVar44 = (undefined4 *)(puVar34 + -0xc);
    //               puVar34 = puVar34 + -0xc;
    //               *puVar44 = 0x4aca94;
    //               (*pcVar17)();
    //             }
    //           }
    //           pRVar21 = rge_base_game;
    //           if ((iVar24 == 2) || (iVar24 == 1)) {
    //             pTVar18 = (TRIBE_Main_View *)this_00->unit_list;
    //             if (pTVar10 == pTVar18) {
    //               *(undefined4 *)(puVar34 + -4) = 0x4acb43;
    //               iVar24 = TTextPanel::currentLineNumber((TTextPanel *)pTVar18);
    //               *(int *)(puVar34 + -4) = iVar24;
    //               *(undefined4 *)(puVar34 + -8) = 0x4acb4b;
    //               TRIBE_Screen_Sed::set_unit(this_00,*(short *)(puVar34 + -4));
    //               if ((rge_base_game->game_mode != 8) && (rge_base_game->game_mode != 0x15)) {
    //                 pTVar16 = this_00->unit_mode_select[0];
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acb6c;
    //                 TButtonPanel::set_radio_button(pTVar16);
    //               }
    //               pRVar21 = rge_base_game;
    //               if (rge_base_game->master_obj_id == -1) {
    // LAB_004acbbf:
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0;
    //               }
    //               else {
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acb81;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 pRVar21 = rge_base_game;
    //                 if (pRVar26 == (RGE_Player *)0x0) goto LAB_004acbbf;
    //                 sVar23 = rge_base_game->master_obj_id;
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acb97;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 pRVar21 = rge_base_game;
    //                 *(RGE_Player **)(puVar34 + -4) = pRVar26;
    //                 *(undefined4 *)(puVar34 + -8) = 0x4acba3;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 *(undefined4 *)(puVar34 + -8) =
    //                      *(undefined4 *)
    //                       (*(int *)(*(int *)(this_00->world->_padding_ + pRVar26->id * 4) + 0x24) +
    //                       sVar23 * 4);
    //               }
    //               pTVar15 = this_00->object_panel;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4acbce;
    //               TRIBE_Scenario_Editor_Panel_Object::set_master_info
    //                         (pTVar15,*(RGE_Master_Static_Object **)(puVar34 + -8),
    //                          *(TRIBE_Player **)(puVar34 + -4));
    //               *(undefined4 *)(puVar34 + -4) = 0x4acbd5;
    //               TRIBE_Screen_Sed::set_paint_object_mode(this_00);
    //               pTVar15 = this_00->object_panel;
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               pcVar17 = *(code **)(pTVar15->_padding_ + 0x20);
    //               puVar46 = (undefined4 *)(puVar34 + -8);
    //               puVar34 = puVar34 + -8;
    //               *puVar46 = 0x4acbe4;
    //               (*pcVar17)();
    //               goto LAB_004abe5a;
    //             }
    //             if (iVar24 == 1) {
    //               if (pTVar10 == (TRIBE_Main_View *)this_00->unit_mode_select[0]) {
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acc01;
    //                 TRIBE_Screen_Sed::set_paint_object_mode(this_00);
    //               }
    //               else if (pTVar10 == (TRIBE_Main_View *)this_00->unit_mode_select[1]) {
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acc19;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acc20;
    //                 RGE_Player::unselect_object(pRVar26);
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0xe;
    //                 pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                 puVar47 = (undefined4 *)(puVar34 + -0xc);
    //                 puVar34 = puVar34 + -0xc;
    //                 *puVar47 = 0x4acc2f;
    //                 (*pcVar17)();
    //               }
    //               else if (pTVar10 == (TRIBE_Main_View *)this_00->unit_mode_select[2]) {
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0xf;
    //                 pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                 puVar48 = (undefined4 *)(puVar34 + -0xc);
    //                 puVar34 = puVar34 + -0xc;
    //                 *puVar48 = 0x4acc4b;
    //                 (*pcVar17)();
    //               }
    //               else if (pTVar10 == (TRIBE_Main_View *)this_00->unit_mode_select[3]) {
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0x14;
    //                 pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                 puVar49 = (undefined4 *)(puVar34 + -0xc);
    //                 puVar34 = puVar34 + -0xc;
    //                 *puVar49 = 0x4acc6b;
    //                 (*pcVar17)();
    //               }
    //             }
    //           }
    //           break;
    //         case ScenarioModeDiplomacy:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if ((iVar24 == 0) || (iVar24 == 1)) {
    //             if (pTVar10 == (TRIBE_Main_View *)this_00->Diplomacy_player_list) {
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][0]->_padding_ + 0x14);
    //               puVar51 = puVar34 + -8;
    //               *(undefined4 *)(puVar34 + -8) = 0x4acd23;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar51 + -4) = 1;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][1]->_padding_ + 0x14);
    //               puVar52 = puVar51 + -8;
    //               *(undefined4 *)(puVar51 + -8) = 0x4acd3c;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar52 + -4) = 1;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][2]->_padding_ + 0x14);
    //               puVar53 = puVar52 + -8;
    //               *(undefined4 *)(puVar52 + -8) = 0x4acd54;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar53 + -4) = 0;
    //               pcVar17 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar23 + -1]->_padding_ + 0x14);
    //               puVar54 = puVar53 + -8;
    //               *(undefined4 *)(puVar53 + -8) = 0x4acd69;
    //               (*pcVar17)();
    //               pTVar8 = this_00->Diplomacy_player_list;
    //               *(undefined4 *)(puVar54 + -4) = 0x4acd74;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               sVar23 = (short)lVar30 + 1;
    //               *(undefined4 *)(puVar54 + -4) = 0;
    //               this_00->player_num = sVar23;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][0]->_padding_ + 0x14);
    //               puVar55 = puVar54 + -8;
    //               *(undefined4 *)(puVar54 + -8) = 0x4acd90;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar55 + -4) = 0;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][1]->_padding_ + 0x14);
    //               puVar56 = puVar55 + -8;
    //               *(undefined4 *)(puVar55 + -8) = 0x4acda9;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar56 + -4) = 0;
    //               pcVar17 = *(code **)(this_00->Diplomacy_friend_box[sVar23 + -1][2]->_padding_ + 0x14);
    //               puVar57 = puVar56 + -8;
    //               *(undefined4 *)(puVar56 + -8) = 0x4acdc1;
    //               (*pcVar17)();
    //               sVar23 = this_00->player_num;
    //               *(undefined4 *)(puVar57 + -4) = 1;
    //               pcVar17 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar23 + -1]->_padding_ + 0x14);
    //               puVar34 = puVar57 + -8;
    //               *(undefined4 *)(puVar57 + -8) = 0x4acdd6;
    //               (*pcVar17)();
    //               pTVar8 = this_00->Diplomacy_player_list;
    //               *(undefined4 *)(puVar34 + -4) = 0x4acde1;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               *(long *)(puVar34 + -4) = lVar30;
    //               *(undefined4 *)(puVar34 + -8) = 0x4acde9;
    //               TRIBE_Screen_Sed::load_diplomacy_from_scenario(this_00,*(int *)(puVar34 + -4));
    //             }
    //             if (iVar24 == 1) {
    //               *(int *)(puVar34 + -4) = this_00->player_num + -1;
    //               *(undefined4 *)(puVar34 + -8) = 0x4acdfe;
    //               TRIBE_Screen_Sed::save_diplomacy_in_scenario(this_00,*(int *)(puVar34 + -4));
    //               goto LAB_004abe5a;
    //             }
    //           }
    //           break;
    //         case ScenarioModeVictory:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (((iVar24 == 0) || (iVar24 == 1)) &&
    //              (pTVar10 == (TRIBE_Main_View *)this_00->victory_player_list)) {
    //             *(int *)(puVar34 + -4) = this_00->CurrentVictory;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac0b7;
    //             TRIBE_Screen_Sed::save_victory_cond_in_scenario(this_00,*(int *)(puVar34 + -4));
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac0c0;
    //             TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar34 + -4));
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(undefined4 *)(puVar34 + -8) = 0;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4ac0cb;
    //             TRIBE_Screen_Sed::activate_victory_proper_fields
    //                       (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             pTVar8 = this_00->victory_player_list;
    //             *(undefined4 *)(puVar34 + -4) = 0x4ac0d6;
    //             lVar30 = TDropDownPanel::get_line(pTVar8);
    //             sVar23 = (short)lVar30 + 1;
    //             this_00->player_num = sVar23;
    //             pTVar19 = (T_Scenario *)this_00->world->_padding_;
    //             *(int *)(puVar34 + -4) = sVar23 + -1;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac0f1;
    //             T_Scenario::SetSPWhich(pTVar19,*(int *)(puVar34 + -4));
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             this_00->CurrentVictory = 0;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac104;
    //             TRIBE_Screen_Sed::load_victory_cond_from_scenario(this_00,*(int *)(puVar34 + -4));
    //             *(undefined4 *)(puVar34 + -4) = 1;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac10d;
    //             TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar34 + -4));
    //             pTVar8 = this_00->victory_drop_down;
    //             *(undefined4 *)(puVar34 + -4) = 1;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac11a;
    //             lVar30 = TDropDownPanel::get_line(pTVar8);
    //             *(long *)(puVar34 + -8) = lVar30;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4ac122;
    //             TRIBE_Screen_Sed::activate_victory_proper_fields
    //                       (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //           }
    //           if ((iVar24 == 0) && (pTVar10 == (TRIBE_Main_View *)this_00->victory_amount_input)) {
    //             pTVar9 = this_00->bottom_panel;
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac13a;
    //             TPanel::set_curr_child(pTVar9,*(TPanel **)(puVar34 + -4));
    //           }
    //           if ((iVar24 == 2) &&
    //              (pTVar18 = (TRIBE_Main_View *)this_00->victory_drop_down, pTVar10 == pTVar18)) {
    //             *(undefined4 *)(puVar34 + -4) = 1;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ac150;
    //             lVar30 = TDropDownPanel::get_line((TDropDownPanel *)pTVar18);
    //             *(long *)(puVar34 + -8) = lVar30;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4ac158;
    //             TRIBE_Screen_Sed::activate_victory_proper_fields
    //                       (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //           }
    //           if (iVar24 == 1) {
    //             if (pTVar10 != (TRIBE_Main_View *)this_00->victory_amount_input) {
    //               pTVar8 = this_00->victory_drop_down;
    //               *(undefined4 *)(puVar34 + -4) = 0x4ac178;
    //               lVar30 = TDropDownPanel::get_line(pTVar8);
    //               pRVar21 = rge_base_game;
    //               if (pTVar10 == (TRIBE_Main_View *)this_00->victory_drop_down) {
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0;
    //                 pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                 puVar35 = (undefined4 *)(puVar34 + -0xc);
    //                 puVar34 = puVar34 + -0xc;
    //                 *puVar35 = 0x4ac193;
    //                 (*pcVar17)();
    //                 this_00->DestinationObject = (RGE_Static_Object *)0x0;
    //                 this_00->SelectedObject = (RGE_Static_Object *)0x0;
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac1aa;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac1b1;
    //                 RGE_Player::unselect_object(pRVar26);
    //               }
    //               if (lVar30 == 2) {
    //                 this_00->DestinationObject = (RGE_Static_Object *)0x0;
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac1cb;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac1d2;
    //                 RGE_Player::unselect_object(pRVar26);
    //               }
    //               if (pTVar10 == (TRIBE_Main_View *)this_00->victory_button_set_object) {
    //                 this_00->SelectRegionFlag = SELECT_OBJECT;
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar34 + -4) = 0;
    //                 *(undefined4 *)(puVar34 + -8) = 0x10;
    //                 pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                 puVar36 = (undefined4 *)(puVar34 + -0xc);
    //                 puVar34 = puVar34 + -0xc;
    //                 *puVar36 = 0x4ac1f2;
    //                 (*pcVar17)();
    //                 pRVar21 = rge_base_game;
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac1fd;
    //                 pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                 *(undefined4 *)(puVar34 + -4) = 0x4ac204;
    //                 RGE_Player::unselect_object(pRVar26);
    //                 pRVar58 = this_00->DestinationObject;
    // LAB_004ac2a8:
    //                 pRVar21 = rge_base_game;
    //                 if (pRVar58 != (RGE_Static_Object *)0x0) {
    //                   *(undefined4 *)(puVar34 + -4) = 0;
    //                   *(RGE_Static_Object **)(puVar34 + -8) = pRVar58;
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac2bd;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac2c4;
    //                   RGE_Player::select_one_object
    //                             (pRVar26,*(RGE_Static_Object **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                 }
    //               }
    //               else {
    //                 if (pTVar10 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
    //                   if (lVar30 != 1) {
    //                     this_00->SelectRegionFlag = SELECT_AREA;
    //                     pRVar21 = rge_base_game;
    //                     *(undefined4 *)(puVar34 + -4) = 0x4ac237;
    //                     pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                     *(undefined4 *)(puVar34 + -4) = 0x4ac23e;
    //                     RGE_Player::unselect_object(pRVar26);
    //                     pRVar21 = rge_base_game;
    //                     pRVar58 = this_00->SelectedObject;
    //                     if (pRVar58 != (RGE_Static_Object *)0x0) {
    //                       *(undefined4 *)(puVar34 + -4) = 0;
    //                       *(RGE_Static_Object **)(puVar34 + -8) = pRVar58;
    //                       *(undefined4 *)(puVar34 + -0xc) = 0x4ac255;
    //                       pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                       *(undefined4 *)(puVar34 + -0xc) = 0x4ac25c;
    //                       RGE_Player::select_one_object
    //                                 (pRVar26,*(RGE_Static_Object **)(puVar34 + -8),
    //                                  *(int *)(puVar34 + -4));
    //                     }
    //                     pRVar21 = rge_base_game;
    //                     *(undefined4 *)(puVar34 + -4) = 0;
    //                     *(undefined4 *)(puVar34 + -8) = 0x11;
    //                     pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                     puVar37 = (undefined4 *)(puVar34 + -0xc);
    //                     puVar34 = puVar34 + -0xc;
    //                     *puVar37 = 0x4ac26a;
    //                     (*pcVar17)();
    //                     goto LAB_004abe5a;
    //                   }
    //                   if (pTVar10 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
    //                     this_00->SelectRegionFlag = SELECT_DEST_OBJECT;
    //                     pRVar21 = rge_base_game;
    //                     *(undefined4 *)(puVar34 + -4) = 0;
    //                     *(undefined4 *)(puVar34 + -8) = 0x10;
    //                     pcVar17 = *(code **)(pRVar21->_padding_ + 0x10);
    //                     puVar38 = (undefined4 *)(puVar34 + -0xc);
    //                     puVar34 = puVar34 + -0xc;
    //                     *puVar38 = 0x4ac290;
    //                     (*pcVar17)();
    //                     pRVar21 = rge_base_game;
    //                     *(undefined4 *)(puVar34 + -4) = 0x4ac29b;
    //                     pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                     *(undefined4 *)(puVar34 + -4) = 0x4ac2a2;
    //                     RGE_Player::unselect_object(pRVar26);
    //                     pRVar58 = this_00->SelectedObject;
    //                     goto LAB_004ac2a8;
    //                   }
    //                 }
    //                 if ((pTVar10 != (TRIBE_Main_View *)this_00->victory_button_go_to_dest) ||
    //                    (lVar30 == 1)) {
    //                   pTVar18 = (TRIBE_Main_View *)this_00->victory_drop_down;
    //                   if (pTVar10 == pTVar18) {
    //                     *(undefined4 *)(puVar34 + -4) = 0;
    //                     *(undefined4 *)(puVar34 + -8) = 0x4ac3da;
    //                     lVar30 = TDropDownPanel::get_line((TDropDownPanel *)pTVar18);
    //                     *(long *)(puVar34 + -8) = lVar30;
    //                     *(undefined4 *)(puVar34 + -0xc) = 0x4ac3e2;
    //                     TRIBE_Screen_Sed::activate_victory_proper_fields
    //                               (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                   }
    //                   iVar24 = 0;
    //                   ppTVar31 = this_00->victory_button;
    //                   do {
    //                     if ((pTVar10 == (TRIBE_Main_View *)*ppTVar31) &&
    //                        (this_00->CurrentVictory != iVar24)) {
    //                       pTVar8 = this_00->victory_drop_down;
    //                       *(undefined4 *)(puVar34 + -4) = 0;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac40b;
    //                       lVar30 = TDropDownPanel::get_line(pTVar8);
    //                       *(long *)(puVar34 + -8) = lVar30;
    //                       *(undefined4 *)(puVar34 + -0xc) = 0x4ac413;
    //                       TRIBE_Screen_Sed::activate_victory_proper_fields
    //                                 (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                       *(int *)(puVar34 + -4) = this_00->CurrentVictory;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac421;
    //                       TRIBE_Screen_Sed::save_victory_cond_in_scenario
    //                                 (this_00,*(int *)(puVar34 + -4));
    //                       *(undefined4 *)(puVar34 + -4) = 0;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac42a;
    //                       TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar34 + -4));
    //                       pRVar21 = rge_base_game;
    //                       *(undefined4 *)(puVar34 + -4) = 0x4ac435;
    //                       pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                       *(undefined4 *)(puVar34 + -4) = 0x4ac43c;
    //                       RGE_Player::unselect_object(pRVar26);
    //                       *(int *)(puVar34 + -4) = iVar24;
    //                       this_00->CurrentVictory = iVar24;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac44a;
    //                       TRIBE_Screen_Sed::load_victory_cond_from_scenario
    //                                 (this_00,*(int *)(puVar34 + -4));
    //                       *(undefined4 *)(puVar34 + -4) = 1;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac453;
    //                       TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar34 + -4));
    //                       pTVar8 = this_00->victory_drop_down;
    //                       *(undefined4 *)(puVar34 + -4) = 1;
    //                       *(undefined4 *)(puVar34 + -8) = 0x4ac460;
    //                       lVar30 = TDropDownPanel::get_line(pTVar8);
    //                       *(long *)(puVar34 + -8) = lVar30;
    //                       *(undefined4 *)(puVar34 + -0xc) = 0x4ac468;
    //                       TRIBE_Screen_Sed::activate_victory_proper_fields
    //                                 (this_00,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                       pRVar21 = rge_base_game;
    //                       pRVar58 = this_00->SelectedObject;
    //                       if (pRVar58 != (RGE_Static_Object *)0x0) {
    //                         *(undefined4 *)(puVar34 + -4) = 0;
    //                         *(RGE_Static_Object **)(puVar34 + -8) = pRVar58;
    //                         *(undefined4 *)(puVar34 + -0xc) = 0x4ac480;
    //                         pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                         *(undefined4 *)(puVar34 + -0xc) = 0x4ac487;
    //                         RGE_Player::select_one_object
    //                                   (pRVar26,*(RGE_Static_Object **)(puVar34 + -8),
    //                                    *(int *)(puVar34 + -4));
    //                       }
    //                       pRVar21 = rge_base_game;
    //                       pRVar58 = this_00->DestinationObject;
    //                       if (pRVar58 != (RGE_Static_Object *)0x0) {
    //                         *(undefined4 *)(puVar34 + -4) = 0;
    //                         *(RGE_Static_Object **)(puVar34 + -8) = pRVar58;
    //                         *(undefined4 *)(puVar34 + -0xc) = 4899999;
    //                         pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                         *(undefined4 *)(puVar34 + -0xc) = 0x4ac4a6;
    //                         RGE_Player::select_one_object
    //                                   (pRVar26,*(RGE_Static_Object **)(puVar34 + -8),
    //                                    *(int *)(puVar34 + -4));
    //                       }
    //                     }
    //                     iVar24 = iVar24 + 1;
    //                     ppTVar31 = ppTVar31 + 1;
    //                   } while (iVar24 < 0xc);
    //                   iVar24 = *(int *)(puVar34 + 0x4c);
    //                   break;
    //                 }
    //                 pTVar10 = this_00->main_view;
    //                 *(undefined4 *)(puVar34 + -4) = 1;
    //                 *(undefined1 **)(puVar34 + -8) = puVar34 + 0x1c;
    //                 *(undefined1 **)(puVar34 + -0xc) = puVar34 + 0x10;
    //                 *(undefined1 **)(puVar34 + -0x10) = puVar34 + 0x18;
    //                 *(undefined1 **)(puVar34 + -0x14) = puVar34 + 0x14;
    //                 *(undefined4 *)(puVar34 + -0x18) = 0x4ac2ff;
    //                 RGE_View::get_selection_area
    //                           ((RGE_View *)pTVar10,*(long **)(puVar34 + -0x14),
    //                            *(long **)(puVar34 + -0x10),*(long **)(puVar34 + -0xc),
    //                            *(long **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                 fVar20 = (float)*(int *)(puVar34 + 0x10);
    //                 iVar24 = *(int *)(puVar34 + 0x14);
    //                 iVar27 = *(int *)(puVar34 + 0x18);
    //                 iVar3 = *(int *)(puVar34 + 0x1c);
    //                 *(float *)(puVar34 + 0x48) = (float)iVar27;
    //                 *(float *)(puVar34 + 0x4c) = (float)iVar3;
    //                 this_00->px1 = (float)iVar24;
    //                 this_00->py1 = (float)iVar27;
    //                 this_00->SelectRegionFlag = SELECT_OFF;
    //                 this_00->px2 = fVar20;
    //                 this_00->py2 = (float)iVar3;
    //                 if (fVar20 != -1.0) {
    //                   *(float *)(puVar34 + 0x50) = fVar20 - (fVar20 - (float)iVar24) * 0.5;
    //                   *(float *)(puVar34 + 0x4c) =
    //                        *(float *)(puVar34 + 0x4c) -
    //                        (*(float *)(puVar34 + 0x4c) - *(float *)(puVar34 + 0x48)) * 0.5;
    //                   *(undefined4 *)(puVar34 + -4) = *(undefined4 *)(puVar34 + 0x4c);
    //                   pRVar21 = rge_base_game;
    //                   *(undefined4 *)(puVar34 + -8) = *(undefined4 *)(puVar34 + 0x50);
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac398;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac39f;
    //                   RGE_Player::set_view_loc
    //                             (pRVar26,*(float *)(puVar34 + -8),*(float *)(puVar34 + -4));
    //                   *(undefined4 *)(puVar34 + -4) = 0x4ac3a8;
    //                   uVar25 = __ftol();
    //                   *(undefined4 *)(puVar34 + -4) = uVar25;
    //                   *(undefined4 *)(puVar34 + -8) = 0x4ac3b2;
    //                   uVar25 = __ftol();
    //                   pRVar21 = rge_base_game;
    //                   *(undefined4 *)(puVar34 + -8) = uVar25;
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac3be;
    //                   pRVar26 = RGE_Base_Game::get_player(pRVar21);
    //                   *(undefined4 *)(puVar34 + -0xc) = 0x4ac3c5;
    //                   RGE_Player::set_map_loc(pRVar26,*(short *)(puVar34 + -8),*(short *)(puVar34 + -4))
    //                   ;
    //                 }
    //               }
    //             }
    //             goto LAB_004abe5a;
    //           }
    //           break;
    //         case ScenarioModeVictoryMulti:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 1) {
    //             iVar27 = 0;
    //             ppTVar31 = this_00->victory_cond_type;
    //             do {
    //               if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //                 *(undefined4 *)(puVar34 + -4) = 1;
    //                 *(int *)(puVar34 + -8) = iVar27 + 1;
    //                 *(undefined4 *)(puVar34 + -0xc) = 0x4accb1;
    //                 TRIBE_Screen_Sed::set_mp_victory_type
    //                           (this_00,*(VictoryType *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //                 if (iVar27 != 4) {
    //                   pTVar6 = this_00->world;
    //                   *(undefined4 *)(puVar34 + -4) = 1;
    //                   pTVar19 = (T_Scenario *)pTVar6->_padding_;
    //                   *(undefined4 *)(puVar34 + -8) = 0x4accca;
    //                   T_Scenario::Set_Multi_Conquest(pTVar19,*(int *)(puVar34 + -4));
    //                   pTVar16 = this_00->victory_cond_on[0];
    //                   *(undefined4 *)(puVar34 + -4) = 1;
    //                   pcVar17 = *(code **)(pTVar16->_padding_ + 0xe0);
    //                   puVar50 = (undefined4 *)(puVar34 + -8);
    //                   puVar34 = puVar34 + -8;
    //                   *puVar50 = 0x4accdc;
    //                   (*pcVar17)();
    //                 }
    //                 goto LAB_004abe5a;
    //               }
    //               iVar27 = iVar27 + 1;
    //               ppTVar31 = ppTVar31 + 1;
    //             } while (iVar27 < 5);
    //           }
    //           break;
    //         case ScenarioModeOptions:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 1) {
    //             *(undefined4 *)(puVar34 + -4) = 0x4ace20;
    //             TRIBE_Screen_Sed::SaveDisabledItemsInScenario(this_00);
    //             *(undefined4 *)(puVar34 + -4) = 0x4ace27;
    //             TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(this_00);
    //             pTVar18 = (TRIBE_Main_View *)this_00->options_button[0];
    //             if (pTVar10 == pTVar18) {
    //               *(undefined4 *)(puVar34 + -4) = 0x4ace36;
    //               iVar27 = TButtonPanel::get_state((TButtonPanel *)pTVar18);
    //               pTVar6 = this_00->world;
    //               *(int *)(puVar34 + -4) = iVar27;
    //               *(undefined4 *)(puVar34 + -8) = 2;
    //               pTVar19 = (T_Scenario *)pTVar6->_padding_;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ace47;
    //               T_Scenario::SetScenarioOption(pTVar19,*(int *)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             }
    //           }
    //           break;
    //         case ScenarioModeMessages:
    //           if (this_00->valid_save_spot_flag != '\0') {
    //             this_00->need_to_save_flag = '\x01';
    //           }
    //           if (iVar24 == 1) {
    //             pTVar5 = this_00->message_input;
    //             *(long *)(puVar34 + -4) = this_00->current_message;
    //             *(undefined4 *)(puVar34 + -8) = 0x4abfad;
    //             pcVar28 = TEditPanel::get_input_buffer(pTVar5);
    //             pTVar6 = this_00->world;
    //             *(char **)(puVar34 + -8) = pcVar28;
    //             pRVar7 = (RGE_Scenario *)pTVar6->_padding_;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4abfbc;
    //             RGE_Scenario::Set_message(pRVar7,*(char **)(puVar34 + -8),*(long *)(puVar34 + -4));
    //             iVar27 = 0;
    //             ppTVar31 = this_00->message_button;
    //             do {
    //               if (pTVar10 == (TRIBE_Main_View *)*ppTVar31) {
    //                 this_00->current_message = iVar27;
    //                 break;
    //               }
    //               iVar27 = iVar27 + 1;
    //               ppTVar31 = ppTVar31 + 1;
    //             } while (iVar27 < 5);
    //             pTVar6 = this_00->world;
    //             *(long *)(puVar34 + -4) = this_00->current_message;
    //             pRVar7 = (RGE_Scenario *)pTVar6->_padding_;
    //             *(undefined4 *)(puVar34 + -8) = 0x4abfee;
    //             pcVar28 = RGE_Scenario::Get_message(pRVar7,*(long *)(puVar34 + -4));
    //             pTVar5 = this_00->message_input;
    //             *(char **)(puVar34 + -4) = pcVar28;
    //             *(undefined4 *)(puVar34 + -8) = 0x4abffa;
    //             TEditPanel::set_text(pTVar5,*(char **)(puVar34 + -4));
    //             switch(this_00->current_message) {
    //             case 0:
    //               pTVar5 = this_00->message_input;
    //               *(undefined4 *)(puVar34 + -4) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -8) = 0x7770;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac022;
    //               TPanel::set_help_info
    //                         ((TPanel *)pTVar5,*(long *)(puVar34 + -8),*(long *)(puVar34 + -4));
    //               break;
    //             case 1:
    //               pTVar5 = this_00->message_input;
    //               *(undefined4 *)(puVar34 + -4) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -8) = 0x7771;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac039;
    //               TPanel::set_help_info
    //                         ((TPanel *)pTVar5,*(long *)(puVar34 + -8),*(long *)(puVar34 + -4));
    //               break;
    //             case 2:
    //               pTVar5 = this_00->message_input;
    //               *(undefined4 *)(puVar34 + -4) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -8) = 0x7772;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac050;
    //               TPanel::set_help_info
    //                         ((TPanel *)pTVar5,*(long *)(puVar34 + -8),*(long *)(puVar34 + -4));
    //               break;
    //             case 3:
    //               pTVar5 = this_00->message_input;
    //               *(undefined4 *)(puVar34 + -4) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -8) = 0x7773;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac067;
    //               TPanel::set_help_info
    //                         ((TPanel *)pTVar5,*(long *)(puVar34 + -8),*(long *)(puVar34 + -4));
    //               break;
    //             case 4:
    //               pTVar5 = this_00->message_input;
    //               *(undefined4 *)(puVar34 + -4) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -8) = 0x7774;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ac07e;
    //               TPanel::set_help_info
    //                         ((TPanel *)pTVar5,*(long *)(puVar34 + -8),*(long *)(puVar34 + -4));
    //             }
    //           }
    //         }
    //         *(undefined4 *)(puVar34 + -4) = 0x4ace4e;
    //         pcVar28 = TPanel::panelName((TPanel *)pTVar10);
    //         if (pcVar28 != (char *)0x0) {
    //           pbVar59 = &s_QuitSaveDialog;
    //           *(undefined4 *)(puVar34 + -4) = 0x4ace62;
    //           pbVar29 = (byte *)TPanel::panelName((TPanel *)pTVar10);
    //           do {
    //             bVar4 = *pbVar29;
    //             bVar60 = bVar4 < *pbVar59;
    //             if (bVar4 != *pbVar59) {
    // LAB_004ace86:
    //               iVar27 = (1 - (uint)bVar60) - (uint)(bVar60 != 0);
    //               goto LAB_004ace8b;
    //             }
    //             if (bVar4 == 0) break;
    //             bVar4 = pbVar29[1];
    //             bVar60 = bVar4 < pbVar59[1];
    //             if (bVar4 != pbVar59[1]) goto LAB_004ace86;
    //             pbVar29 = pbVar29 + 2;
    //             pbVar59 = pbVar59 + 2;
    //           } while (bVar4 != 0);
    //           iVar27 = 0;
    // LAB_004ace8b:
    //           if (iVar27 == 0) {
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(char **)(puVar34 + -8) = s_Scenario_Editor_Screen;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4ace9f;
    //             TPanelSystem::setCurrentPanel
    //                       (&panel_system,*(char **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             *(undefined **)(puVar34 + -4) = &s_QuitSaveDialog;
    //             *(undefined4 *)(puVar34 + -8) = 0x4aceae;
    //             TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar34 + -4));
    //             pRVar21 = rge_base_game;
    //             if (iVar24 == 0) {
    //               *(undefined4 *)(puVar34 + -4) = 1;
    //               *(undefined4 *)(puVar34 + -8) = 0;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4acebc;
    //               TRIBE_Screen_Sed::command_save(this_00,puVar34[-8],puVar34[-4]);
    //             }
    //             else if (iVar24 == 1) {
    //               *(undefined4 *)(puVar34 + -4) = 0x4aced5;
    //               iVar24 = TRIBE_Game::start_menu((TRIBE_Game *)pRVar21);
    //               pRVar21 = rge_base_game;
    //               if (iVar24 == 0) {
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acee4;
    //                 RGE_Base_Game::close(pRVar21);
    //               }
    //               else {
    //                 *(char **)(puVar34 + -4) = s_Scenario_Editor_Screen;
    //                 *(undefined4 *)(puVar34 + -8) = 0x4acef8;
    //                 TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar34 + -4));
    //               }
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         *(undefined4 *)(puVar34 + -4) = 0x4acf04;
    //         pcVar28 = TPanel::panelName((TPanel *)pTVar10);
    //         if (pcVar28 != (char *)0x0) {
    //           pbVar59 = &s_OpenSaveDialog;
    //           *(undefined4 *)(puVar34 + -4) = 0x4acf18;
    //           pbVar29 = (byte *)TPanel::panelName((TPanel *)pTVar10);
    //           do {
    //             bVar4 = *pbVar29;
    //             bVar60 = bVar4 < *pbVar59;
    //             if (bVar4 != *pbVar59) {
    // LAB_004acf3c:
    //               iVar27 = (1 - (uint)bVar60) - (uint)(bVar60 != 0);
    //               goto LAB_004acf41;
    //             }
    //             if (bVar4 == 0) break;
    //             bVar4 = pbVar29[1];
    //             bVar60 = bVar4 < pbVar59[1];
    //             if (bVar4 != pbVar59[1]) goto LAB_004acf3c;
    //             pbVar29 = pbVar29 + 2;
    //             pbVar59 = pbVar59 + 2;
    //           } while (bVar4 != 0);
    //           iVar27 = 0;
    // LAB_004acf41:
    //           if (iVar27 == 0) {
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(char **)(puVar34 + -8) = s_Scenario_Editor_Screen;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4acf55;
    //             TPanelSystem::setCurrentPanel
    //                       (&panel_system,*(char **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             *(undefined **)(puVar34 + -4) = &s_OpenSaveDialog;
    //             *(undefined4 *)(puVar34 + -8) = 0x4acf64;
    //             TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar34 + -4));
    //             if (iVar24 == 0) {
    //               *(undefined4 *)(puVar34 + -4) = 2;
    //               *(undefined4 *)(puVar34 + -8) = 0;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4acf72;
    //               TRIBE_Screen_Sed::command_save(this_00,puVar34[-8],puVar34[-4]);
    //             }
    //             else if (iVar24 == 1) {
    //               *(undefined4 *)(puVar34 + -4) = 0x490;
    //               *(undefined4 *)(puVar34 + -8) = 0x4acf8a;
    //               this = (TRIBE_Screen_Sed_Open *)operator_new(*(uint *)(puVar34 + -4));
    //               *(TRIBE_Screen_Sed_Open **)(puVar34 + 0x4c) = this;
    //               *(undefined4 *)(puVar34 + 0x40) = 0;
    //               if (this != (TRIBE_Screen_Sed_Open *)0x0) {
    //                 *(undefined4 *)(puVar34 + -4) = 0x4acfa4;
    //                 TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
    //               }
    //               *(undefined4 *)(puVar34 + -4) = 0;
    //               *(char **)(puVar34 + -8) = s_Scenario_Editor_Open;
    //               *(undefined4 *)(puVar34 + 0x40) = 0xffffffff;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4acfbd;
    //               TPanelSystem::setCurrentPanel
    //                         (&panel_system,*(char **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         *(undefined4 *)(puVar34 + -4) = 0x4acfc9;
    //         pcVar28 = TPanel::panelName((TPanel *)pTVar10);
    //         if (pcVar28 != (char *)0x0) {
    //           pbVar59 = &s_NewSaveDialog;
    //           *(undefined4 *)(puVar34 + -4) = 0x4acfdd;
    //           pbVar29 = (byte *)TPanel::panelName((TPanel *)pTVar10);
    //           do {
    //             bVar4 = *pbVar29;
    //             bVar60 = bVar4 < *pbVar59;
    //             if (bVar4 != *pbVar59) {
    // LAB_004ad001:
    //               iVar27 = (1 - (uint)bVar60) - (uint)(bVar60 != 0);
    //               goto LAB_004ad006;
    //             }
    //             if (bVar4 == 0) break;
    //             bVar4 = pbVar29[1];
    //             bVar60 = bVar4 < pbVar59[1];
    //             if (bVar4 != pbVar59[1]) goto LAB_004ad001;
    //             pbVar29 = pbVar29 + 2;
    //             pbVar59 = pbVar59 + 2;
    //           } while (bVar4 != 0);
    //           iVar27 = 0;
    // LAB_004ad006:
    //           if (iVar27 == 0) {
    //             *(undefined4 *)(puVar34 + -4) = 0;
    //             *(char **)(puVar34 + -8) = s_Scenario_Editor_Screen;
    //             *(undefined4 *)(puVar34 + -0xc) = 0x4ad01a;
    //             TPanelSystem::setCurrentPanel
    //                       (&panel_system,*(char **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             *(undefined **)(puVar34 + -4) = &s_NewSaveDialog;
    //             *(undefined4 *)(puVar34 + -8) = 0x4ad029;
    //             TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar34 + -4));
    //             pRVar21 = rge_base_game;
    //             if (iVar24 == 0) {
    //               *(undefined4 *)(puVar34 + -4) = 3;
    //               *(undefined4 *)(puVar34 + -8) = 0;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ad037;
    //               TRIBE_Screen_Sed::command_save(this_00,puVar34[-8],puVar34[-4]);
    //             }
    //             else if (iVar24 == 1) {
    //               *(undefined4 *)(puVar34 + -4) = 0;
    //               *(undefined4 *)(puVar34 + -8) = 0;
    //               *(undefined4 *)(puVar34 + -0xc) = 0x4ad054;
    //               TRIBE_Game::start_scenario_editor
    //                         ((TRIBE_Game *)pRVar21,*(char **)(puVar34 + -8),*(int *)(puVar34 + -4));
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         uVar25 = 0;
    //         goto LAB_004abe5f;
    //       }
    //     }
    //   }
    // LAB_004abe5a:
    //   uVar25 = 1;
    // LAB_004abe5f:
    //   *unaff_FS_OFFSET = *(undefined4 *)(puVar34 + 0x38);
    //   return uVar25;
    // }
    // 
    // 
}

// Offset: 0x004ABCD0
long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: x2 */
    // /* public: virtual long __thiscall TRIBE_Screen_Sed::action(class TPanel *,long,unsigned
    //    long,unsigned long) */
    // 
    // long __thiscall
    // TRIBE_Screen_Sed::action
    //           (TRIBE_Screen_Sed *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
    // 
    // {
    //   byte bVar1;
    //   TRIBE_World *pTVar2;
    //   short sVar3;
    //   short sVar4;
    //   long lVar5;
    //   RGE_Player *pRVar6;
    //   char *pcVar7;
    //   byte *pbVar8;
    //   TRIBE_Player *pTVar9;
    //   TButtonPanel **ppTVar10;
    //   TRIBE_Screen_Sed_Open *this_00;
    //   TEditPanel **ppTVar11;
    //   RGE_Static_Object *pRVar12;
    //   byte *pbVar13;
    //   float fVar14;
    //   float *unaff_FS_OFFSET;
    //   bool bVar15;
    //   uchar uVar16;
    //   RGE_Master_Static_Object *pRVar17;
    //   uchar uVar18;
    //   int iVar19;
    //   float fVar20;
    //   int iVar21;
    //   long x2;
    //   long x1;
    //   long y1;
    //   long y2;
    //   char random_val [24];
    //   float local_c;
    //   code *pcStack_8;
    //   undefined4 uStack_4;
    //   
    //   local_c = *unaff_FS_OFFSET;
    //   uStack_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f48b;
    //   *unaff_FS_OFFSET = (float)&local_c;
    //   if (param_1 == (TPanel *)0x0) {
    //     lVar5 = 0;
    //     goto LAB_004abe5f;
    //   }
    //   if ((TRIBE_Main_View *)param_1 != this->main_view) {
    //     pRVar12 = this->SelectedObject;
    //     if (pRVar12 != (RGE_Static_Object *)0x0) {
    //       iVar19 = 0;
    //       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //       RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //     }
    //     pRVar12 = this->DestinationObject;
    //     if (pRVar12 != (RGE_Static_Object *)0x0) {
    //       iVar19 = 0;
    //       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //       RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //     }
    //   }
    //   if ((param_2 == 0) &&
    //      ((((((((TEditPanel *)param_1 == this->random_seed_input ||
    //            ((TEditPanel *)param_1 == this->player_inven_input[0])) ||
    //           ((TEditPanel *)param_1 == this->player_inven_input[1])) ||
    //          (((TEditPanel *)param_1 == this->player_inven_input[2] ||
    //           ((TEditPanel *)param_1 == this->player_inven_input[3])))) ||
    //         ((TEditPanel *)param_1 == this->player_inven_input[4])) ||
    //        ((((TTextPanel *)param_1 == this->player_setting_label[0] ||
    //          ((TEditPanel *)param_1 == this->victory_condition_explore)) ||
    //         (((TEditPanel *)param_1 == this->victory_condition_ruins ||
    //          ((((TEditPanel *)param_1 == this->victory_condition_artifacts ||
    //            ((TEditPanel *)param_1 == this->victory_condition_discoveries)) ||
    //           ((TEditPanel *)param_1 == this->victory_condition_gold)))))))) ||
    //       (((TEditPanel *)param_1 == this->victory_amount_input ||
    //        ((TEditPanel *)param_1 == this->message_input)))))) {
    //     this->need_to_save_flag = '\x01';
    //   }
    //   if ((TRIBE_Main_View *)param_1 == this->main_view) {
    //     if (param_2 != 0x10) {
    //       if ((param_2 == 0x11) && (rge_base_game->game_mode == 0x11)) {
    //         (**(code **)(rge_base_game->_padding_ + 0x10))();
    //       }
    //       goto LAB_004abe90;
    //     }
    //     pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //     RGE_Player::unselect_object(pRVar6);
    //     if (this->SelectRegionFlag == SELECT_OBJECT) {
    //       this->SelectedObject = (RGE_Static_Object *)param_3;
    //     }
    //     if (this->SelectRegionFlag == SELECT_DEST_OBJECT) {
    //       this->DestinationObject = (RGE_Static_Object *)param_3;
    //     }
    //     pRVar12 = this->SelectedObject;
    //     if (pRVar12 != (RGE_Static_Object *)0x0) {
    //       iVar19 = 0;
    //       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //       RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //     }
    //     pRVar12 = this->DestinationObject;
    //     if (pRVar12 != (RGE_Static_Object *)0x0) {
    //       iVar19 = 0;
    //       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //       RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //     }
    //     (**(code **)(rge_base_game->_padding_ + 0x10))();
    //   }
    //   else {
    // LAB_004abe90:
    //     if (param_2 == 1) {
    //       iVar19 = 0;
    //       ppTVar10 = this->scenario_mode_button;
    //       do {
    //         if ((TButtonPanel *)param_1 == *ppTVar10) {
    //           set_scenario_mode(this,iVar19 + ScenarioModeMap);
    //           goto LAB_004abe5a;
    //         }
    //         iVar19 = iVar19 + 1;
    //         ppTVar10 = ppTVar10 + 1;
    //       } while (iVar19 < 10);
    //       if ((TButtonPanel *)param_1 == this->menu_button) {
    //         command_menu(this);
    //       }
    //       else {
    //         if ((TButtonPanel *)param_1 != this->help_button) goto LAB_004abf01;
    //         TEasy_Panel::setup_popup_help((TEasy_Panel *)this);
    //       }
    //     }
    //     else {
    //       iVar19 = 0;
    //       ppTVar10 = this->scenario_mode_button;
    //       do {
    //         if ((TButtonPanel *)param_1 == *ppTVar10) goto LAB_004abe5a;
    //         iVar19 = iVar19 + 1;
    //         ppTVar10 = ppTVar10 + 1;
    //       } while (iVar19 < 10);
    //       if (((TButtonPanel *)param_1 != this->menu_button) &&
    //          ((TButtonPanel *)param_1 != this->help_button)) {
    // LAB_004abf01:
    //         pcVar7 = TPanel::panelName(param_1);
    //         if (pcVar7 != (char *)0x0) {
    //           pbVar13 = &s_OKDialog;
    //           pbVar8 = (byte *)TPanel::panelName(param_1);
    //           do {
    //             bVar1 = *pbVar8;
    //             bVar15 = bVar1 < *pbVar13;
    //             if (bVar1 != *pbVar13) {
    // LAB_004abf3c:
    //               iVar19 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
    //               goto LAB_004abf41;
    //             }
    //             if (bVar1 == 0) break;
    //             bVar1 = pbVar8[1];
    //             bVar15 = bVar1 < pbVar13[1];
    //             if (bVar1 != pbVar13[1]) goto LAB_004abf3c;
    //             pbVar8 = pbVar8 + 2;
    //             pbVar13 = pbVar13 + 2;
    //           } while (bVar1 != 0);
    //           iVar19 = 0;
    // LAB_004abf41:
    //           if (iVar19 == 0) {
    //             if (param_2 == 0) {
    //               TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
    //               set_scenario_mode(this,ScenarioModePlayers);
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         switch(this->scenario_mode) {
    //         case ScenarioModeMap:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 1) {
    //             iVar19 = 0;
    //             ppTVar10 = this->map_type_button;
    //             do {
    //               if ((TButtonPanel *)param_1 == *ppTVar10) {
    //                 set_map_type(this,iVar19 + MapTypeBlank,1);
    //                 goto LAB_004abe5a;
    //               }
    //               iVar19 = iVar19 + 1;
    //               ppTVar10 = ppTVar10 + 1;
    //             } while (iVar19 < 3);
    //             if ((TButtonPanel *)param_1 == this->generate_map_button) {
    //               (**(code **)(this->map_generating_text->_padding_ + 0x14))();
    //               (**(code **)(this->_padding_ + 0x20))();
    //               InvalidateRect(rge_base_game->prog_window,0,0);
    //               RGE_Base_Game::draw_window(rge_base_game);
    //               iVar19 = TDropDownPanel::currentLineNumber(this->map_size_drop);
    //               local_c = (float)TDropDownPanel::currentLineNumber(this->map_style_drop);
    //               fVar14 = local_c;
    //               switch(iVar19) {
    //               case 0:
    //                 fVar14 = 1.00893e-43;
    //                 break;
    //               case 1:
    //                 fVar14 = 1.34525e-43;
    //                 break;
    //               case 2:
    //                     /* language.dll match for 0x78: "10" */
    //                 fVar14 = 1.68156e-43;
    //                 break;
    //               case 3:
    //                 fVar14 = 2.01787e-43;
    //                 break;
    //               case 4:
    //                 fVar14 = 2.8026e-43;
    //                 break;
    //               case 5:
    //                 fVar14 = 3.50325e-43;
    //               }
    //               lVar5 = TDropDownPanel::get_line(this->player_number_list);
    //               if (this->map_type == MapTypeBlank) {
    //                 iVar19 = TDropDownPanel::currentLineNumber(this->default_terrain_drop);
    //                 switch(iVar19) {
    //                 case 0:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\0',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 1:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x06',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 2:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\n',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 3:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x01',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 4:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\r',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 5:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x14',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 6:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x04',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 7:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x13',(long)fVar14,(long)fVar14);
    //                   break;
    //                 case 8:
    //                   pTVar2 = this->world;
    //                   RGE_Map::clear_map((RGE_Map *)pTVar2->_padding_,*(RGE_Player **)pTVar2->_padding_,
    //                                      (RGE_Game_World *)pTVar2,'\x16',(long)fVar14,(long)fVar14);
    //                 }
    //               }
    //               else {
    //                 if (this->map_type == MapTypeSeed) {
    //                   pcVar7 = TEditPanel::currentLine(this->random_seed_input);
    //                   iVar19 = atoi(pcVar7);
    //                   rge_base_game->random_map_seed = iVar19;
    //                 }
    //                 else {
    //                   rge_base_game->random_map_seed = -1;
    //                 }
    //                 iVar19 = 0;
    //                 do {
    //                   RGE_Player::reset_selected(*(RGE_Player **)(this->world->_padding_ + iVar19));
    //                   iVar19 = iVar19 + 4;
    //                 } while (iVar19 < 0x24);
    //                 (**(code **)(*(int *)this->world->_padding_ + 0x28))
    //                           (this->world,fVar14,fVar14,local_c,lVar5 + 1);
    //                 rge_base_game->random_map_seed = random_val._4_4_;
    //                 itoa(rge_base_game->save_random_map_seed,&stack0xffffffb4,10);
    //                 (**(code **)(this->random_seed_used_text->_padding_ + 0xe8))(&stack0xffffffb4);
    //                 debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp,0xb58);
    //               }
    //               iVar19 = 0;
    //               fVar20 = (float)((int)fVar14 / 2);
    //               local_c = fVar20;
    //               do {
    //                 sVar3 = (short)((int)fVar14 / 2);
    //                 RGE_Player::set_map_loc
    //                           (*(RGE_Player **)(this->world->_padding_ + iVar19),sVar3,sVar3);
    //                 RGE_Player::set_view_loc
    //                           (*(RGE_Player **)(this->world->_padding_ + iVar19),fVar20,fVar20);
    //                 iVar19 = iVar19 + 4;
    //               } while (iVar19 < 0x20);
    //               iVar19 = 0;
    //               do {
    //                 RGE_Tile_List::del_list
    //                           ((RGE_Tile_List *)(*(int *)(this->world->_padding_ + iVar19) + 0x58));
    //                 RGE_Player::set_map_visible(*(RGE_Player **)(this->world->_padding_ + iVar19));
    //                 iVar19 = iVar19 + 4;
    //               } while (iVar19 < 0x20);
    //               set_panel_info(this);
    //               (**(code **)(this->map_generating_text->_padding_ + 0x14))(0);
    //               goto LAB_004abe5a;
    //             }
    //           }
    //           break;
    //         case ScenarioModeTerrain:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if ((param_2 == 2) || (param_2 == 1)) {
    //             if ((TListPanel *)param_1 == this->paint_terrain_list) {
    //               iVar19 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_terrain_list);
    //               set_terrain(this,(short)iVar19);
    //               (**(code **)(this->brush_size_button[0]->_padding_ + 0x14))();
    //             }
    //             else {
    //               if ((TListPanel *)param_1 != this->paint_elevation_list) {
    //                 if (param_2 == 1) {
    //                   if (this->valid_save_spot_flag != '\0') {
    //                     this->need_to_save_flag = '\x01';
    //                   }
    //                   iVar19 = 0;
    //                   ppTVar10 = this->brush_size_button;
    //                   do {
    //                     if ((TButtonPanel *)param_1 == *ppTVar10) {
    //                       set_brush_size(this,iVar19 + BrushSizeVerySmall);
    //                       goto LAB_004abe5a;
    //                     }
    //                     iVar19 = iVar19 + 1;
    //                     ppTVar10 = ppTVar10 + 1;
    //                   } while (iVar19 < 5);
    //                   iVar19 = 0;
    //                   ppTVar10 = this->paint_type_button;
    //                   do {
    //                     if ((TButtonPanel *)param_1 == *ppTVar10) {
    //                       set_paint_type(this,iVar19 + PaintTypeTerrain,1);
    //                       goto LAB_004abe5a;
    //                     }
    //                     iVar19 = iVar19 + 1;
    //                     ppTVar10 = ppTVar10 + 1;
    //                   } while (iVar19 < 3);
    //                 }
    //                 break;
    //               }
    //               iVar19 = TTextPanel::currentLineNumber((TTextPanel *)this->paint_elevation_list);
    //               set_elevation(this,(short)iVar19);
    //             }
    //             goto LAB_004abe5a;
    //           }
    //           break;
    //         case ScenarioModePlayers:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 0) {
    //             iVar19 = 0;
    //             ppTVar11 = this->player_inven_input;
    //             do {
    //               if ((TEditPanel *)param_1 == *ppTVar11) {
    //                 TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
    //                 break;
    //               }
    //               iVar19 = iVar19 + 1;
    //               ppTVar11 = ppTVar11 + 1;
    //             } while (iVar19 < 5);
    //             if (this->valid_save_spot_flag != '\0') {
    //               this->need_to_save_flag = '\x01';
    //             }
    //             if ((TDropDownPanel *)param_1 == this->player_advance_civilization_drop) {
    //               if (this->valid_save_spot_flag != '\0') {
    //                 this->need_to_save_flag = '\x01';
    //               }
    //               iVar19 = TDropDownPanel::currentLineNumber(this->player_advance_civilization_drop);
    //               T_Scenario::SetPlayerAge
    //                         ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar19);
    //             }
    //             if ((TDropDownPanel *)param_1 == this->player_list) {
    //               uVar18 = '\x01';
    //               uVar16 = '\x01';
    //               lVar5 = TDropDownPanel::get_line(this->player_list);
    //               set_player(this,(short)lVar5 + 1,uVar16,uVar18);
    //               lVar5 = TDropDownPanel::get_line(this->player_list);
    //               iVar19 = T_Scenario::GetPlayerAge((T_Scenario *)this->world->_padding_,lVar5);
    //               TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,iVar19);
    //             }
    //             if ((TDropDownPanel *)param_1 == this->player_number_list) {
    //               set_player(this,this->player_num,'\x01','\0');
    //               SavePlayerActiveStatus(this);
    //               set_player(this,this->player_num,'\0','\x01');
    //             }
    //           }
    //           if ((param_2 == 1) &&
    //              ((TDropDownPanel *)param_1 == this->player_advance_civilization_drop)) {
    //             iVar19 = TDropDownPanel::currentLineNumber(this->player_advance_civilization_drop);
    //             T_Scenario::SetPlayerAge
    //                       ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar19);
    //           }
    //           break;
    //         case ScenarioModeUnits:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 0) {
    //             if (this->valid_save_spot_flag != '\0') {
    //               this->need_to_save_flag = '\x01';
    //             }
    //             if ((TDropDownPanel *)param_1 == this->unit_player_list) {
    //               lVar5 = TDropDownPanel::get_line(this->unit_player_list);
    //               set_unit_player(this,(short)lVar5);
    //               lVar5 = TDropDownPanel::get_line(this->unit_player_list);
    //               if (lVar5 != 0) {
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //                 if ((rge_base_game->master_obj_id == -1) ||
    //                    (pRVar6 = RGE_Base_Game::get_player(rge_base_game), pRVar6 == (RGE_Player *)0x0))
    //                 {
    //                   pTVar9 = (TRIBE_Player *)0x0;
    //                   pRVar17 = (RGE_Master_Static_Object *)0x0;
    //                 }
    //                 else {
    //                   sVar3 = rge_base_game->master_obj_id;
    //                   pTVar9 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    //                   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                   pRVar17 = *(RGE_Master_Static_Object **)
    //                              (*(int *)(*(int *)(this->world->_padding_ + pRVar6->id * 4) + 0x24) +
    //                              sVar3 * 4);
    //                 }
    //                 TRIBE_Scenario_Editor_Panel_Object::set_master_info
    //                           (this->object_panel,pRVar17,pTVar9);
    //                 set_paint_object_mode(this);
    //                 (**(code **)(this->object_panel->_padding_ + 0x20))(2);
    //                 goto LAB_004abe5a;
    //               }
    //               (**(code **)(rge_base_game->_padding_ + 0x10))();
    //             }
    //           }
    //           if ((param_2 == 2) || (param_2 == 1)) {
    //             if ((TListPanel *)param_1 == this->unit_list) {
    //               iVar19 = TTextPanel::currentLineNumber((TTextPanel *)this->unit_list);
    //               set_unit(this,(short)iVar19);
    //               if ((rge_base_game->game_mode != 8) && (rge_base_game->game_mode != 0x15)) {
    //                 TButtonPanel::set_radio_button(this->unit_mode_select[0]);
    //               }
    //               if ((rge_base_game->master_obj_id == -1) ||
    //                  (pRVar6 = RGE_Base_Game::get_player(rge_base_game), pRVar6 == (RGE_Player *)0x0)) {
    //                 pTVar9 = (TRIBE_Player *)0x0;
    //                 pRVar17 = (RGE_Master_Static_Object *)0x0;
    //               }
    //               else {
    //                 sVar3 = rge_base_game->master_obj_id;
    //                 pTVar9 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    //                 pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                 pRVar17 = *(RGE_Master_Static_Object **)
    //                            (*(int *)(*(int *)(this->world->_padding_ + pRVar6->id * 4) + 0x24) +
    //                            sVar3 * 4);
    //               }
    //               TRIBE_Scenario_Editor_Panel_Object::set_master_info(this->object_panel,pRVar17,pTVar9)
    //               ;
    //               set_paint_object_mode(this);
    //               (**(code **)(this->object_panel->_padding_ + 0x20))();
    //               goto LAB_004abe5a;
    //             }
    //             if (param_2 == 1) {
    //               if ((TButtonPanel *)param_1 == this->unit_mode_select[0]) {
    //                 set_paint_object_mode(this);
    //               }
    //               else if ((TButtonPanel *)param_1 == this->unit_mode_select[1]) {
    //                 pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                 RGE_Player::unselect_object(pRVar6);
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //               }
    //               else if ((TButtonPanel *)param_1 == this->unit_mode_select[2]) {
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //               }
    //               else if ((TButtonPanel *)param_1 == this->unit_mode_select[3]) {
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //               }
    //             }
    //           }
    //           break;
    //         case ScenarioModeDiplomacy:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if ((param_2 == 0) || (param_2 == 1)) {
    //             if ((TDropDownPanel *)param_1 == this->Diplomacy_player_list) {
    //               (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][0]->_padding_ + 0x14))
    //                         ();
    //               (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][1]->_padding_ + 0x14))
    //                         ();
    //               (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][2]->_padding_ + 0x14))
    //                         (1);
    //               (**(code **)(this->Diplomacy_AlliedVictory[this->player_num + -1]->_padding_ + 0x14))
    //                         (0);
    //               lVar5 = TDropDownPanel::get_line(this->Diplomacy_player_list);
    //               sVar3 = (short)lVar5 + 1;
    //               this->player_num = sVar3;
    //               (**(code **)(this->Diplomacy_friend_box[sVar3 + -1][0]->_padding_ + 0x14))(0);
    //               (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][1]->_padding_ + 0x14))
    //                         (0);
    //               (**(code **)(this->Diplomacy_friend_box[this->player_num + -1][2]->_padding_ + 0x14))
    //                         (0);
    //               (**(code **)(this->Diplomacy_AlliedVictory[this->player_num + -1]->_padding_ + 0x14))
    //                         (1);
    //               lVar5 = TDropDownPanel::get_line(this->Diplomacy_player_list);
    //               load_diplomacy_from_scenario(this,lVar5);
    //             }
    //             if (param_2 == 1) {
    //               save_diplomacy_in_scenario(this,this->player_num + -1);
    //               goto LAB_004abe5a;
    //             }
    //           }
    //           break;
    //         case ScenarioModeVictory:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (((param_2 == 0) || (param_2 == 1)) &&
    //              ((TDropDownPanel *)param_1 == this->victory_player_list)) {
    //             save_victory_cond_in_scenario(this,this->CurrentVictory);
    //             activate_victory_panel(this,0);
    //             activate_victory_proper_fields(this,0,0);
    //             lVar5 = TDropDownPanel::get_line(this->victory_player_list);
    //             sVar3 = (short)lVar5 + 1;
    //             this->player_num = sVar3;
    //             T_Scenario::SetSPWhich((T_Scenario *)this->world->_padding_,sVar3 + -1);
    //             this->CurrentVictory = 0;
    //             load_victory_cond_from_scenario(this,0);
    //             activate_victory_panel(this,1);
    //             iVar19 = 1;
    //             lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //             activate_victory_proper_fields(this,lVar5,iVar19);
    //           }
    //           if ((param_2 == 0) && ((TEditPanel *)param_1 == this->victory_amount_input)) {
    //             TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
    //           }
    //           if ((param_2 == 2) && ((TDropDownPanel *)param_1 == this->victory_drop_down)) {
    //             iVar19 = 1;
    //             lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //             activate_victory_proper_fields(this,lVar5,iVar19);
    //           }
    //           if (param_2 == 1) {
    //             if ((TEditPanel *)param_1 != this->victory_amount_input) {
    //               lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //               if ((TDropDownPanel *)param_1 == this->victory_drop_down) {
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //                 this->DestinationObject = (RGE_Static_Object *)0x0;
    //                 this->SelectedObject = (RGE_Static_Object *)0x0;
    //                 pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                 RGE_Player::unselect_object(pRVar6);
    //               }
    //               if (lVar5 == 2) {
    //                 this->DestinationObject = (RGE_Static_Object *)0x0;
    //                 pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                 RGE_Player::unselect_object(pRVar6);
    //               }
    //               if ((TButtonPanel *)param_1 == this->victory_button_set_object) {
    //                 this->SelectRegionFlag = SELECT_OBJECT;
    //                 (**(code **)(rge_base_game->_padding_ + 0x10))();
    //                 pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                 RGE_Player::unselect_object(pRVar6);
    //                 pRVar12 = this->DestinationObject;
    // LAB_004ac2a8:
    //                 if (pRVar12 != (RGE_Static_Object *)0x0) {
    //                   iVar19 = 0;
    //                   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                   RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //                 }
    //               }
    //               else {
    //                 if ((TButtonPanel *)param_1 == this->victory_button_set_destination) {
    //                   if (lVar5 != 1) {
    //                     this->SelectRegionFlag = SELECT_AREA;
    //                     pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                     RGE_Player::unselect_object(pRVar6);
    //                     pRVar12 = this->SelectedObject;
    //                     if (pRVar12 != (RGE_Static_Object *)0x0) {
    //                       iVar19 = 0;
    //                       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                       RGE_Player::select_one_object(pRVar6,pRVar12,iVar19);
    //                     }
    //                     (**(code **)(rge_base_game->_padding_ + 0x10))();
    //                     goto LAB_004abe5a;
    //                   }
    //                   if ((TButtonPanel *)param_1 == this->victory_button_set_destination) {
    //                     this->SelectRegionFlag = SELECT_DEST_OBJECT;
    //                     (**(code **)(rge_base_game->_padding_ + 0x10))();
    //                     pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                     RGE_Player::unselect_object(pRVar6);
    //                     pRVar12 = this->SelectedObject;
    //                     goto LAB_004ac2a8;
    //                   }
    //                 }
    //                 if (((TButtonPanel *)param_1 != this->victory_button_go_to_dest) || (lVar5 == 1)) {
    //                   if ((TDropDownPanel *)param_1 == this->victory_drop_down) {
    //                     iVar19 = 0;
    //                     lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //                     activate_victory_proper_fields(this,lVar5,iVar19);
    //                   }
    //                   iVar19 = 0;
    //                   ppTVar10 = this->victory_button;
    //                   do {
    //                     if (((TButtonPanel *)param_1 == *ppTVar10) && (this->CurrentVictory != iVar19))
    //                     {
    //                       iVar21 = 0;
    //                       lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //                       activate_victory_proper_fields(this,lVar5,iVar21);
    //                       save_victory_cond_in_scenario(this,this->CurrentVictory);
    //                       activate_victory_panel(this,0);
    //                       pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                       RGE_Player::unselect_object(pRVar6);
    //                       this->CurrentVictory = iVar19;
    //                       load_victory_cond_from_scenario(this,iVar19);
    //                       activate_victory_panel(this,1);
    //                       iVar21 = 1;
    //                       lVar5 = TDropDownPanel::get_line(this->victory_drop_down);
    //                       activate_victory_proper_fields(this,lVar5,iVar21);
    //                       pRVar12 = this->SelectedObject;
    //                       if (pRVar12 != (RGE_Static_Object *)0x0) {
    //                         iVar21 = 0;
    //                         pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                         RGE_Player::select_one_object(pRVar6,pRVar12,iVar21);
    //                       }
    //                       pRVar12 = this->DestinationObject;
    //                       if (pRVar12 != (RGE_Static_Object *)0x0) {
    //                         iVar21 = 0;
    //                         pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                         RGE_Player::select_one_object(pRVar6,pRVar12,iVar21);
    //                       }
    //                     }
    //                     iVar19 = iVar19 + 1;
    //                     ppTVar10 = ppTVar10 + 1;
    //                   } while (iVar19 < 0xc);
    //                   break;
    //                 }
    //                 RGE_View::get_selection_area
    //                           ((RGE_View *)this->main_view,&y1,&y2,&x1,(long *)random_val,1);
    //                 fVar14 = (float)x1;
    //                 fVar20 = (float)(int)random_val._0_4_;
    //                 this->px1 = (float)y1;
    //                 this->py1 = (float)y2;
    //                 this->SelectRegionFlag = SELECT_OFF;
    //                 this->px2 = fVar14;
    //                 this->py2 = fVar20;
    //                 if (fVar14 != -1.0) {
    //                   fVar14 = fVar14 - (fVar14 - (float)y1) * 0.5;
    //                   fVar20 = fVar20 - (fVar20 - (float)y2) * 0.5;
    //                   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                   RGE_Player::set_view_loc(pRVar6,fVar14,fVar20);
    //                   sVar3 = __ftol();
    //                   sVar4 = __ftol();
    //                   pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    //                   RGE_Player::set_map_loc(pRVar6,sVar4,sVar3);
    //                 }
    //               }
    //             }
    //             goto LAB_004abe5a;
    //           }
    //           break;
    //         case ScenarioModeVictoryMulti:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 1) {
    //             iVar19 = 0;
    //             ppTVar10 = this->victory_cond_type;
    //             do {
    //               if ((TButtonPanel *)param_1 == *ppTVar10) {
    //                 set_mp_victory_type(this,iVar19 + VictoryTypeStandard,1);
    //                 if (iVar19 != 4) {
    //                   T_Scenario::Set_Multi_Conquest((T_Scenario *)this->world->_padding_,1);
    //                   (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
    //                 }
    //                 goto LAB_004abe5a;
    //               }
    //               iVar19 = iVar19 + 1;
    //               ppTVar10 = ppTVar10 + 1;
    //             } while (iVar19 < 5);
    //           }
    //           break;
    //         case ScenarioModeOptions:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 1) {
    //             SaveDisabledItemsInScenario(this);
    //             LoadDisabledItemsFromScenario(this);
    //             if ((TButtonPanel *)param_1 == this->options_button[0]) {
    //               iVar19 = TButtonPanel::get_state(this->options_button[0]);
    //               T_Scenario::SetScenarioOption((T_Scenario *)this->world->_padding_,2,iVar19);
    //             }
    //           }
    //           break;
    //         case ScenarioModeMessages:
    //           if (this->valid_save_spot_flag != '\0') {
    //             this->need_to_save_flag = '\x01';
    //           }
    //           if (param_2 == 1) {
    //             lVar5 = this->current_message;
    //             pcVar7 = TEditPanel::get_input_buffer(this->message_input);
    //             RGE_Scenario::Set_message((RGE_Scenario *)this->world->_padding_,pcVar7,lVar5);
    //             iVar19 = 0;
    //             ppTVar10 = this->message_button;
    //             do {
    //               if ((TButtonPanel *)param_1 == *ppTVar10) {
    //                 this->current_message = iVar19;
    //                 break;
    //               }
    //               iVar19 = iVar19 + 1;
    //               ppTVar10 = ppTVar10 + 1;
    //             } while (iVar19 < 5);
    //             pcVar7 = RGE_Scenario::Get_message
    //                                ((RGE_Scenario *)this->world->_padding_,this->current_message);
    //             TEditPanel::set_text(this->message_input,pcVar7);
    //             switch(this->current_message) {
    //             case 0:
    //                     /* language.dll match for 0x7770: "Type the scenario instructions." */
    //               TPanel::set_help_info((TPanel *)this->message_input,0x7770,-1);
    //               break;
    //             case 1:
    //                     /* language.dll match for 0x7771: "Type the hints (optional)." */
    //               TPanel::set_help_info((TPanel *)this->message_input,0x7771,-1);
    //               break;
    //             case 2:
    //                     /* language.dll match for 0x7772: "Type the victory message (optional)." */
    //               TPanel::set_help_info((TPanel *)this->message_input,0x7772,-1);
    //               break;
    //             case 3:
    //                     /* language.dll match for 0x7773: "Type the loss message (optional)." */
    //               TPanel::set_help_info((TPanel *)this->message_input,0x7773,-1);
    //               break;
    //             case 4:
    //                     /* language.dll match for 0x7774: "Type the history text (optional)." */
    //               TPanel::set_help_info((TPanel *)this->message_input,0x7774,-1);
    //             }
    //           }
    //         }
    //         pcVar7 = TPanel::panelName(param_1);
    //         uVar16 = (uchar)param_2;
    //         if (pcVar7 != (char *)0x0) {
    //           pbVar13 = &s_QuitSaveDialog;
    //           pbVar8 = (byte *)TPanel::panelName(param_1);
    //           do {
    //             bVar1 = *pbVar8;
    //             bVar15 = bVar1 < *pbVar13;
    //             if (bVar1 != *pbVar13) {
    // LAB_004ace86:
    //               iVar19 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
    //               goto LAB_004ace8b;
    //             }
    //             if (bVar1 == 0) break;
    //             bVar1 = pbVar8[1];
    //             bVar15 = bVar1 < pbVar13[1];
    //             if (bVar1 != pbVar13[1]) goto LAB_004ace86;
    //             pbVar8 = pbVar8 + 2;
    //             pbVar13 = pbVar13 + 2;
    //           } while (bVar1 != 0);
    //           iVar19 = 0;
    // LAB_004ace8b:
    //           if (iVar19 == 0) {
    //             TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    //             TPanelSystem::destroyPanel(&panel_system,&s_QuitSaveDialog);
    //             if (param_2 == 0) {
    //               command_save(this,uVar16,'\x01');
    //             }
    //             else if (param_2 == 1) {
    //               iVar19 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    //               if (iVar19 == 0) {
    //                 RGE_Base_Game::close(rge_base_game);
    //               }
    //               else {
    //                 TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
    //               }
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         pcVar7 = TPanel::panelName(param_1);
    //         if (pcVar7 != (char *)0x0) {
    //           pbVar13 = &s_OpenSaveDialog;
    //           pbVar8 = (byte *)TPanel::panelName(param_1);
    //           do {
    //             bVar1 = *pbVar8;
    //             bVar15 = bVar1 < *pbVar13;
    //             if (bVar1 != *pbVar13) {
    // LAB_004acf3c:
    //               iVar19 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
    //               goto LAB_004acf41;
    //             }
    //             if (bVar1 == 0) break;
    //             bVar1 = pbVar8[1];
    //             bVar15 = bVar1 < pbVar13[1];
    //             if (bVar1 != pbVar13[1]) goto LAB_004acf3c;
    //             pbVar8 = pbVar8 + 2;
    //             pbVar13 = pbVar13 + 2;
    //           } while (bVar1 != 0);
    //           iVar19 = 0;
    // LAB_004acf41:
    //           if (iVar19 == 0) {
    //             TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    //             TPanelSystem::destroyPanel(&panel_system,&s_OpenSaveDialog);
    //             if (param_2 == 0) {
    //               command_save(this,uVar16,'\x02');
    //             }
    //             else if (param_2 == 1) {
    //               this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
    //               uStack_4 = 0;
    //               if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
    //                 TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
    //               }
    //               uStack_4 = 0xffffffff;
    //               TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         pcVar7 = TPanel::panelName(param_1);
    //         if (pcVar7 != (char *)0x0) {
    //           pbVar13 = &s_NewSaveDialog;
    //           pbVar8 = (byte *)TPanel::panelName(param_1);
    //           do {
    //             bVar1 = *pbVar8;
    //             bVar15 = bVar1 < *pbVar13;
    //             if (bVar1 != *pbVar13) {
    // LAB_004ad001:
    //               iVar19 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
    //               goto LAB_004ad006;
    //             }
    //             if (bVar1 == 0) break;
    //             bVar1 = pbVar8[1];
    //             bVar15 = bVar1 < pbVar13[1];
    //             if (bVar1 != pbVar13[1]) goto LAB_004ad001;
    //             pbVar8 = pbVar8 + 2;
    //             pbVar13 = pbVar13 + 2;
    //           } while (bVar1 != 0);
    //           iVar19 = 0;
    // LAB_004ad006:
    //           if (iVar19 == 0) {
    //             TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    //             TPanelSystem::destroyPanel(&panel_system,&s_NewSaveDialog);
    //             if (param_2 == 0) {
    //               command_save(this,uVar16,'\x03');
    //             }
    //             else if (param_2 == 1) {
    //               TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
    //             }
    //             goto LAB_004abe5a;
    //           }
    //         }
    //         lVar5 = 0;
    //         goto LAB_004abe5f;
    //       }
    //     }
    //   }
    // LAB_004abe5a:
    //   lVar5 = 1;
    // LAB_004abe5f:
    //   *unaff_FS_OFFSET = local_c;
    //   return lVar5;
    // }
    // 
    // 
}

// Offset: 0x004AD06E
undefined FUN_004ad06e() {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
    // 
    // void FUN_004ad06e(void)
    // 
    // {
    //   char cVar1;
    //   undefined4 *puVar2;
    //   undefined4 *puVar3;
    //   undefined4 *unaff_EBP;
    //   
    //   puVar2 = (undefined4 *)0x20004ac0;
    //   cVar1 = '\r';
    //   puVar3 = puVar2;
    //   puRam20004ac0 = unaff_EBP;
    //   do {
    //     unaff_EBP = unaff_EBP + -1;
    //     puVar3 = puVar3 + -1;
    //     *puVar3 = *unaff_EBP;
    //     cVar1 = cVar1 + -1;
    //   } while ('\0' < cVar1);
    //   uRam20004a88 = 0x20004ac0;
    //   puVar3 = (undefined4 *)0x20004a3a;
    //   uRam20004a3a = 0x20004ac0;
    //   cVar1 = '\v';
    //   do {
    //     puVar2 = puVar2 + -1;
    //     puVar3 = puVar3 + -1;
    //     *puVar3 = *puVar2;
    //     cVar1 = cVar1 + -1;
    //   } while ('\0' < cVar1);
    //   uRam20004a0a = 0x20004a3a;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD0F0
void TRIBE_Screen_Sed::draw() {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: rect */
    // /* public: virtual void __thiscall TRIBE_Screen_Sed::draw(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::draw(TRIBE_Screen_Sed *this)
    // 
    // {
    //   int iVar1;
    //   int iVar2;
    //   uchar *puVar3;
    //   tagRECT rect;
    //   
    //   TEasy_Panel::draw((TEasy_Panel *)this);
    //   if ((((this->_padding_ != 0) && (this->main_view != (TRIBE_Main_View *)0x0)) &&
    //       (this->_padding_ == this->_padding_)) &&
    //      (((this->_padding_ == this->_padding_ && (this->_padding_ == this->_padding_)) &&
    //       (this->_padding_ == this->_padding_)))) {
    //     iVar1 = this->_padding_;
    //     (**(code **)(iVar1 + 0x28))(0);
    //     puVar3 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_scr_sed__draw,1);
    //     if (puVar3 != (uchar *)0x0) {
    //       iVar2 = *(int *)&this->main_view->field_0x98;
    //       TDrawArea::DrawBevel3
    //                 ((TDrawArea *)this->_padding_,0,0,this->_padding_ + -1,
    //                  *(int *)&this->main_view->field_0x90 + -1,(uchar)this->_padding_,
    //                  *(uchar *)((int)&this->_padding_ + 1),*(uchar *)((int)&this->_padding_ + 2),
    //                  *(uchar *)((int)&this->_padding_ + 3),(uchar)this->_padding_,
    //                  *(uchar *)((int)&this->_padding_ + 1));
    //       TDrawArea::DrawBevel3
    //                 ((TDrawArea *)this->_padding_,0,iVar2 + 1,this->_padding_ + -1,this->_padding_ + -1,
    //                  (uchar)this->_padding_,*(uchar *)((int)&this->_padding_ + 1),
    //                  *(uchar *)((int)&this->_padding_ + 2),*(uchar *)((int)&this->_padding_ + 3),
    //                  (uchar)this->_padding_,*(uchar *)((int)&this->_padding_ + 1));
    //       TDrawArea::Unlock((TDrawArea *)this->_padding_,s_scr_sed__draw);
    //     }
    //     (**(code **)(iVar1 + 0x2c))();
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD240
void command_cancel(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_cancel(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_cancel(TRIBE_Screen_Sed *this)
    // 
    // {
    //   RGE_Player *pRVar1;
    //   
    //   pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_Player::unselect_object(pRVar1);
    //   pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    //   RGE_Player::unselect_area(pRVar1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD270
int command_menu(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: int __thiscall TRIBE_Screen_Sed::command_menu(void) */
    // 
    // int __thiscall TRIBE_Screen_Sed::command_menu(TRIBE_Screen_Sed *this)
    // 
    // {
    //   TRIBE_Dialog_Sed_Menu *this_00;
    //   undefined4 *puVar1;
    //   undefined4 *unaff_FS_OFFSET;
    //   undefined4 local_c;
    //   code *pcStack_8;
    //   undefined4 local_4;
    //   
    //   local_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f4ab;
    //   local_c = *unaff_FS_OFFSET;
    //   *unaff_FS_OFFSET = &local_c;
    //                     /* language.dll match for 0x4b4: "Waiting" */
    //   this_00 = (TRIBE_Dialog_Sed_Menu *)operator_new(0x4b4);
    //   local_4 = 0;
    //   if (this_00 == (TRIBE_Dialog_Sed_Menu *)0x0) {
    //     puVar1 = (undefined4 *)0x0;
    //   }
    //   else {
    //     puVar1 = (undefined4 *)TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(this_00,this);
    //   }
    //   local_4 = 0xffffffff;
    //   if ((puVar1 != (undefined4 *)0x0) && (puVar1[0x36] != 0)) {
    //     (**(code **)*puVar1)(1);
    //     *unaff_FS_OFFSET = this_00;
    //     return 0;
    //   }
    //   *unaff_FS_OFFSET = local_c;
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x004AD300
void command_new(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_new(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_new(TRIBE_Screen_Sed *this)
    // 
    // {
    //   uchar uVar1;
    //   
    //   uVar1 = need_to_save(this);
    //   if (uVar1 != '\0') {
    //                     /* language.dll match for 0x2447: "Do you want to save your changes to this
    //                        scenario?" */
    //     TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_NewSaveDialog,0x1c2,100);
    //     return;
    //   }
    //   TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD340
int command_new_map(TRIBE_Screen_Sed* this_, char* param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: int __thiscall TRIBE_Screen_Sed::command_new_map(char *,int,int,int,int,int) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::command_new_map
    //           (TRIBE_Screen_Sed *this,char *param_1,int param_2,int param_3,int param_4,int param_5,
    //           int param_6)
    // 
    // {
    //   int iVar1;
    //   uint uVar2;
    //   int iVar3;
    //   long *plVar4;
    //   short *psVar5;
    //   char *pcVar6;
    //   int tribe;
    //   int local_7d4;
    //   RGE_Player_Info player_info;
    //   RGE_Map_Gen_Info map_info;
    //   
    //   this->need_to_save_flag = '\0';
    //   if (rge_base_game->world == (RGE_Game_World *)0x0) {
    //     if (param_6 != 0) {
    //                     /* language.dll match for 0x44d: "Loading game data..." */
    //       TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x44d,(char *)0x0,-1);
    //     }
    //     iVar1 = TRIBE_Game::load_game_data((TRIBE_Game *)rge_base_game);
    //     if (iVar1 == 0) {
    //       if (param_6 != 0) {
    //         TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    //       }
    //       return 0;
    //     }
    //   }
    //   this->world = (TRIBE_World *)rge_base_game->world;
    //   if (param_6 != 0) {
    //     if (param_1 == (char *)0x0) {
    //       iVar1 = 0x44e;
    //     }
    //     else {
    //                     /* language.dll match for 0x44f: "Loading scenario..." */
    //       iVar1 = 0x44f;
    //     }
    //     TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,iVar1,(char *)0x0,-1);
    //   }
    //   player_info._672_4_ = &map_info.land;
    //   player_info.ai_info = (short)param_4;
    //   player_info.campaign = (uchar)param_5;
    //   player_info._681_1_ = param_5._1_1_;
    //   player_info.map_info = (RGE_Map_Gen_Info *)param_1;
    //   player_info.name[0]._0_4_ = 0x2865 - (int)(player_info.type + 4);
    //   player_info._682_2_ = 0;
    //   player_info.scenario._0_2_ = 8;
    //   local_7d4 = 0;
    //   plVar4 = player_info.player_id_hash;
    //   psVar5 = player_info.color + 2;
    //   pcVar6 = player_info.name[0] + 4;
    //   iVar1 = 0;
    //   do {
    //     iVar3 = iVar1;
    //     plVar4 = plVar4 + 1;
    //     local_7d4 = local_7d4 + 1;
    //     if ((short)this->world->_padding_ <= local_7d4) {
    //       local_7d4 = 1;
    //     }
    //     set_string(this,pcVar6,(long)(player_info.type + player_info.name[0]._0_4_ + iVar3 + 4),0x41);
    //     player_info.type[iVar3 + 4] = '\0';
    //     player_info.tribe[iVar3 + 4] = (char)local_7d4;
    //     *psVar5 = -1;
    //     *plVar4 = iVar3;
    //     iVar1 = iVar3 + 1;
    //     pcVar6 = pcVar6 + 0x41;
    //     psVar5 = psVar5 + 1;
    //   } while (iVar1 < 8);
    //   player_info.player_id_hash[iVar3 + 2] = iVar1;
    //   map_info.land.clump_num._0_2_ = 0;
    //   if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    //     rge_base_game->sound_system->mute = '\x01';
    //   }
    //   uVar2 = (**(code **)(this->world->_padding_ + 0xd4))(player_info.name[0] + 4,param_3);
    //   uVar2 = uVar2 & 0xff;
    //   if ((uVar2 != 0) && ((short)this->world->_padding_ < 8)) {
    //     uVar2 = 0;
    //     (**(code **)(this->world->_padding_ + 0xb8))();
    //   }
    //   if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    //     rge_base_game->sound_system->mute = '\0';
    //   }
    //   if ((uVar2 != 0) && (this->player_number_list != (TDropDownPanel *)0x0)) {
    //     iVar1 = 0;
    //     do {
    //       iVar3 = RGE_Scenario::Get_player_Active((RGE_Scenario *)this->world->_padding_,iVar1);
    //       if (iVar3 == 0) break;
    //       iVar1 = iVar1 + 1;
    //     } while (iVar1 < 8);
    //     if ((iVar1 < 8) && (0 < iVar1)) {
    //       TDropDownPanel::set_line(this->player_number_list,iVar1 + -1);
    //     }
    //     SavePlayerActiveStatus(this);
    //   }
    //   return uVar2;
    // }
    // 
    // 
}

// Offset: 0x004AD590
void command_open(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_open(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_open(TRIBE_Screen_Sed *this)
    // 
    // {
    //   uchar uVar1;
    //   TRIBE_Screen_Sed_Open *this_00;
    //   undefined4 *unaff_FS_OFFSET;
    //   undefined4 local_c;
    //   code *pcStack_8;
    //   undefined4 local_4;
    //   
    //   local_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f4cb;
    //   local_c = *unaff_FS_OFFSET;
    //   *unaff_FS_OFFSET = &local_c;
    //   uVar1 = need_to_save(this);
    //   if (uVar1 != '\0') {
    //                     /* language.dll match for 0x2447: "Do you want to save your changes to this
    //                        scenario?" */
    //     TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_OpenSaveDialog,0x1c2,100);
    //     *unaff_FS_OFFSET = local_c;
    //     return;
    //   }
    //   this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
    //   local_4 = 0;
    //   if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
    //     TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
    //   }
    //   local_4 = 0xffffffff;
    //   TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
    //   *unaff_FS_OFFSET = local_c;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD630
void command_outline(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_outline(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_outline(TRIBE_Screen_Sed *this)
    // 
    // {
    //   uchar uVar1;
    //   uchar outline_type;
    //   
    //   uVar1 = rge_base_game->outline_type;
    //   switch(uVar1) {
    //   case '\0':
    //   case '\x03':
    //     rge_base_game->outline_type = '\x02';
    //     return;
    //   case '\x01':
    //     uVar1 = '\0';
    //     break;
    //   case '\x02':
    //     rge_base_game->outline_type = '\x01';
    //     return;
    //   }
    //   rge_base_game->outline_type = uVar1;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD680
void command_player(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_player(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_player(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   (**(code **)(rge_base_game->_padding_ + 0x14))(param_1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD6A0
void command_quit(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_quit(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_quit(TRIBE_Screen_Sed *this)
    // 
    // {
    //   uchar uVar1;
    //   int iVar2;
    //   
    //   uVar1 = need_to_save(this);
    //   if (uVar1 != '\0') {
    //                     /* language.dll match for 0x2447: "Do you want to save your changes to this
    //                        scenario?" */
    //     TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)this,0x2447,&s_QuitSaveDialog,0x1c2,100);
    //     return;
    //   }
    //   iVar2 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    //   if (iVar2 == 0) {
    //     RGE_Base_Game::close(rge_base_game);
    //     return;
    //   }
    //   TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD700
void command_save(TRIBE_Screen_Sed* this_, uchar param_2, uchar param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_save(unsigned char,unsigned char) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_save(TRIBE_Screen_Sed *this,uchar param_1,uchar param_2)
    // 
    // {
    //   byte bVar1;
    //   char cVar2;
    //   int iVar3;
    //   byte *pbVar4;
    //   byte *pbVar5;
    //   undefined4 *unaff_FS_OFFSET;
    //   bool bVar6;
    //   char temp_name [260];
    //   undefined4 local_c;
    //   code *pcStack_8;
    //   undefined4 uStack_4;
    //   
    //   local_c = *unaff_FS_OFFSET;
    //   uStack_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f4ee;
    //   *unaff_FS_OFFSET = &local_c;
    //   set_scenario_mode(this,ScenarioModeSave);
    //   T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
    //   iVar3 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
    //   if (iVar3 < 1) {
    //     TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    //                     /* language.dll match for 0x2742: "You need to make at least one player active"
    //                         */
    //     TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
    //   }
    //   else {
    //     iVar3 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
    //     if (iVar3 < 1) {
    //       TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    //                     /* language.dll match for 0x2743: "One or more civilizations must be set to
    //                        Player Type: Either" */
    //       TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    //     }
    //     else {
    //       pbVar4 = (byte *)RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
    //       if (*pbVar4 == 0) {
    //         command_save_as(this,param_2);
    //       }
    //       else {
    //                     /* language.dll match for 0x450: "Saving scenario..." */
    //         TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
    //         if (param_1 != '\0') {
    //           TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    //         }
    //         cVar2 = (**(code **)(this->world->_padding_ + 0xe4))(pbVar4);
    //         if (cVar2 == '\0') {
    //           TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    //                     /* language.dll match for 0x963: "The scenario could not be saved. Free some
    //                        disk space, and then try again." */
    //           TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
    //         }
    //         else {
    //           TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    //           iVar3 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    //           sprintf(temp_name + 4,s_default_d,iVar3);
    //           pbVar5 = (byte *)(temp_name + 4);
    //           do {
    //             bVar1 = *pbVar4;
    //             bVar6 = bVar1 < *pbVar5;
    //             if (bVar1 != *pbVar5) {
    // LAB_004ad897:
    //               iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
    //               goto LAB_004ad89c;
    //             }
    //             if (bVar1 == 0) break;
    //             bVar1 = pbVar4[1];
    //             bVar6 = bVar1 < pbVar5[1];
    //             if (bVar1 != pbVar5[1]) goto LAB_004ad897;
    //             pbVar4 = pbVar4 + 2;
    //             pbVar5 = pbVar5 + 2;
    //           } while (bVar1 != 0);
    //           iVar3 = 0;
    // LAB_004ad89c:
    //           if (iVar3 != 0) {
    //             this->need_to_save_flag = '\0';
    //           }
    //           if (param_2 == '\x01') {
    //             iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    //             if (iVar3 == 0) {
    //               RGE_Base_Game::close(rge_base_game);
    //             }
    //             else {
    //               TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
    //             }
    //           }
    //           else if (param_2 == '\x02') {
    //             temp_name._0_4_ = operator_new(0x490);
    //             uStack_4 = 0;
    //             if ((TRIBE_Screen_Sed_Open *)temp_name._0_4_ != (TRIBE_Screen_Sed_Open *)0x0) {
    //               TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open((TRIBE_Screen_Sed_Open *)temp_name._0_4_)
    //               ;
    //             }
    //             uStack_4 = 0xffffffff;
    //             TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
    //           }
    //           else if (param_2 == '\x03') {
    //             TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
    //           }
    //         }
    //       }
    //     }
    //   }
    //   *unaff_FS_OFFSET = local_c;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AD960
void command_save_as(TRIBE_Screen_Sed* this_, uchar param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_save_as(unsigned char) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_save_as(TRIBE_Screen_Sed *this,uchar param_1)
    // 
    // {
    //   int iVar1;
    //   undefined4 *unaff_FS_OFFSET;
    //   char scenario_name [224];
    //   undefined4 local_c;
    //   code *pcStack_8;
    //   undefined4 local_4;
    //   
    //   local_c = *unaff_FS_OFFSET;
    //   local_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f50e;
    //   *unaff_FS_OFFSET = &local_c;
    //   set_scenario_mode(this,ScenarioModeSave);
    //   T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
    //   iVar1 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
    //   if (iVar1 < 1) {
    //                     /* language.dll match for 0x2742: "You need to make at least one player active"
    //                         */
    //     TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
    //   }
    //   else {
    //     iVar1 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
    //     if (iVar1 < 1) {
    //                     /* language.dll match for 0x2743: "One or more civilizations must be set to
    //                        Player Type: Either" */
    //       TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    //     }
    //     else {
    //       scenario_name[4] = '\0';
    //       scenario_name._0_4_ = operator_new(0x6a4);
    //       local_4 = 0;
    //       if ((TribeSaveGameScreen *)scenario_name._0_4_ != (TribeSaveGameScreen *)0x0) {
    //         TribeSaveGameScreen::TribeSaveGameScreen
    //                   ((TribeSaveGameScreen *)scenario_name._0_4_,SaveScenarioEdit,scenario_name + 4,
    //                    (uint)param_1);
    //       }
    //       local_4 = 0xffffffff;
    //       TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
    //       TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    //     }
    //   }
    //   *unaff_FS_OFFSET = local_c;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004ADA70
char* scenario_get_default_name(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: temp_name */
    // /* public: char * __thiscall TRIBE_Screen_Sed::scenario_get_default_name(void) */
    // 
    // char * __thiscall TRIBE_Screen_Sed::scenario_get_default_name(TRIBE_Screen_Sed *this)
    // 
    // {
    //   char *pcVar1;
    //   int iVar2;
    //   char temp_name [260];
    //   
    //   pcVar1 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
    //   if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    //     iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    //     sprintf(temp_name + 4,s_default_d_scx,iVar2);
    //     RGE_Scenario::Set_scenario_name((RGE_Scenario *)this->world->_padding_,temp_name + 4);
    //   }
    //   pcVar1 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->world->_padding_);
    //   return pcVar1;
    // }
    // 
    // 
}

// Offset: 0x004ADAF0
void command_quick_save(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::command_quick_save(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::command_quick_save(TRIBE_Screen_Sed *this)
    // 
    // {
    //   scenario_get_default_name(this);
    //   command_save(this,'\0','\0');
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004ADB10
char* scenario_save_defaulted(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: char * __thiscall TRIBE_Screen_Sed::scenario_save_defaulted(void) */
    // 
    // char * __thiscall TRIBE_Screen_Sed::scenario_save_defaulted(TRIBE_Screen_Sed *this)
    // 
    // {
    //   char cVar1;
    //   int iVar2;
    //   
    //   set_scenario_mode(this,ScenarioModeSave);
    //   T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
    //   iVar2 = RGE_Scenario::active_player_count((RGE_Scenario *)this->world->_padding_);
    //   if (iVar2 < 1) {
    //                     /* language.dll match for 0x2742: "You need to make at least one player active"
    //                         */
    //     TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2742,(char *)0x0,0x1c2,100);
    //     return (char *)0x0;
    //   }
    //   iVar2 = RGE_Scenario::any_player_count((RGE_Scenario *)this->world->_padding_);
    //   if (iVar2 < 1) {
    //                     /* language.dll match for 0x2743: "One or more civilizations must be set to
    //                        Player Type: Either" */
    //     TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2743,(char *)0x0,0x1c2,100);
    //     return (char *)0x0;
    //   }
    //                     /* language.dll match for 0x450: "Saving scenario..." */
    //   TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
    //   iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    //   sprintf(0x86bad8,s_default_d_scx,iVar2);
    //   cVar1 = (**(code **)(this->world->_padding_ + 0xe4))(0x86bad8);
    //   if (cVar1 == '\0') {
    //     TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    //                     /* language.dll match for 0x963: "The scenario could not be saved. Free some
    //                        disk space, and then try again." */
    //     TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
    //     return (char *)0x0;
    //   }
    //   iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
    //   sprintf(0x86bad8,s_default_d,iVar2);
    //   return &UNK_0086bad4.field_0x4;
    // }
    // 
    // 
}

// Offset: 0x004ADC30
uchar need_to_save(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: unsigned char __thiscall TRIBE_Screen_Sed::need_to_save(void) */
    // 
    // uchar __thiscall TRIBE_Screen_Sed::need_to_save(TRIBE_Screen_Sed *this)
    // 
    // {
    //   return this->need_to_save_flag;
    // }
    // 
    // 
}

// Offset: 0x004ADC40
void TRIBE_Screen_Sed::set_focus(int param_1) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: virtual void __thiscall TRIBE_Screen_Sed::set_focus(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::set_focus(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   TScreenPanel::set_focus((TScreenPanel *)this,param_1);
    //   if (this->_padding_ != 0) {
    //     RGE_Base_Game::set_windows_mouse(rge_base_game,0);
    //     return;
    //   }
    //   RGE_Base_Game::set_windows_mouse(rge_base_game,1);
    //   return;
    // }
    // 
    // 
}

#endif // TASK_227_SCR_SED_DECOMP_REFERENCE_END

