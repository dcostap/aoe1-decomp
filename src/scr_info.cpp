// deleting destructor at 0049D5E0 is compiler-generated.

#include "../include/scr_info.h"
#include "../include/rge_base_game_global.h"
#include "../include/scr_main.h"
#include "../include/scr_sing.h"
#include "../include/tribegam.h"
#include <string.h>

TRIBE_Screen_Info::TRIBE_Screen_Info(char* panel_name, char* screen_file,
                                     long screen_id,
                                     unsigned long timer_value)
    : TScreenPanel(panel_name)
{
    timer = timer_value;
    auto_close = timer > 0;
    last_time = 0;

    if (setup(rge_base_game->draw_area, screen_file, screen_id, 0) == 0) {
        error_code = 1;
    }
}

TRIBE_Screen_Info::~TRIBE_Screen_Info()
{
}

long TRIBE_Screen_Info::handle_idle()
{
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    if (auto_close != 0) {
        if (last_time == 0) {
            last_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\scr_info.cpp", 0x48);
            return TPanel::handle_idle();
        }

        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_info.cpp", 0x4B);
        if (now - last_time > timer) {
            close_screen();
            return 0;
        }
    }

    return TPanel::handle_idle();
}

long TRIBE_Screen_Info::key_down_action(long key, short, int, int, int)
{
    if (key != 0x12 && key != 0x11 && key != 0x10) {
        close_screen();
    }
    return 0;
}

long TRIBE_Screen_Info::mouse_left_down_action(long, long, int, int)
{
    close_screen();
    return 0;
}

long TRIBE_Screen_Info::action(TPanel* panel, long event,
                               unsigned long param3,
                               unsigned long param4)
{
    return TEasy_Panel::action(panel, event, param3, param4);
}

void TRIBE_Screen_Info::close_screen()
{
    if (strcmp(panel_name, "RandomMap") == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen;
        panel_system.setCurrentPanel("Single Player Menu", 0);
        panel_system.destroyPanel("RandomMap");
        return;
    }

    if (strcmp(panel_name, "DeathMatch") == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen;
        panel_system.setCurrentPanel("Single Player Menu", 0);
        panel_system.destroyPanel("DeathMatch");
        return;
    }

    if (strcmp(panel_name, "Logo1Screen") == 0) {
        new TRIBE_Screen_Info("Logo2Screen", "scrlogo2", 0xC392, 2000);
        panel_system.setCurrentPanel("Logo2Screen", 0);
        return;
    }

    if (strcmp(panel_name, "Logo2Screen") == 0) {
        if (static_cast<TRIBE_Game*>(rge_base_game)->start_menu() == 0) {
            rge_base_game->close();
        }
        return;
    }

    if (strcmp(panel_name, "ScenarioEditorInfo") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info("UnitInfo1", "scrunit1", 0xC394, 0);
        panel_system.setCurrentPanel("UnitInfo1", 0);
        panel_system.destroyPanel("ScenarioEditorInfo");
        return;
    }

    if (strcmp(panel_name, "UnitInfo1") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info("UnitInfo2", "scrunit2", 0xC395, 0);
        panel_system.setCurrentPanel("UnitInfo2", 0);
        panel_system.destroyPanel("UnitInfo1");
        return;
    }

    if (strcmp(panel_name, "UnitInfo2") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info("UnitInfo3", "scrunit3", 0xC396, 0);
        panel_system.setCurrentPanel("UnitInfo3", 0);
        panel_system.destroyPanel("UnitInfo2");
        return;
    }

    if (strcmp(panel_name, "UnitInfo3") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Main_Menu;
        panel_system.setCurrentPanel("Main Menu", 0);
        panel_system.destroyPanel("UnitInfo3");
        return;
    }

    if (strcmp(panel_name, "FeaturesInfo") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info("TechInfo", "scrtech", 0xC393, 0);
        panel_system.setCurrentPanel("TechInfo", 0);
        panel_system.destroyPanel("FeaturesInfo");
        return;
    }

    if (strcmp(panel_name, "TechInfo") == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info("QuotesInfo", "scrinfqu", 0xC38F, 0);
        panel_system.setCurrentPanel("QuotesInfo", 0);
        panel_system.destroyPanel("TechInfo");
        return;
    }

    rge_base_game->close();
}
