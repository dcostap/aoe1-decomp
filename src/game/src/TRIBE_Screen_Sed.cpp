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

    // Best-effort: if the dropdown exists, use it to set scenario active players.
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

    // Best-effort: populate scenario name into game options if provided.
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

    // Player active state + scenario name processing (best-effort for parity).
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

