// VA: 004982E0 TRIBE_Screen_Game::action
// PDB source: scr_game.cpp
// Exact notes:
// - The authentic scr_game.cpp context supplies the panel, game, and load-screen declarations.
// - The restart path captures rge_base_game before it tests id.
// - Other pause paths load rge_base_game at pause_cleanup.
// - Both paths join at pause_loaded and call RGE_Base_Game::singlePlayerGame.
// - Later member accesses reload rge_base_game after that call.
// - Using the reviewed extern for the restart capture stays exact.
// - The storage helper and the disabled local declarations were not required.
// FLAGS: config/flags/004982E0_action.rsp (/GX required by original EH setup)

#include <new.h>
#include "../../include/scr_game_context.h"

long TRIBE_Screen_Game::action(TPanel* panel, long id,
                               unsigned long p3, unsigned long p4)
{
    TEasy_Panel* tool_box;
    RGE_Base_Game* cleanup_game;

    if (panel == 0) {
        goto null_base_action;
    }

    tool_box = this->tool_box;
    if (panel != tool_box && tool_box->active != 0 &&
        tool_box->action(panel, id, p3, p4) != 0) {
        return 1;
    }

        if (id == 1 || id == 4) {
            for (int i = 0; i < 17; ++i) {
                if (panel == this->button_panel[i]) {
                    this->do_button_action(p3, p4, id == 4);
                    return 1;
                }
            }
        }

        if (panel == this->object_panel && id == 1) {
            this->object_changed();
            return 1;
        }

    if (panel->panelName() == 0) {
        goto named_base_action;
    }

    if (strcmp(panel->panelName(), "RestartDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("RestartDialog");
        cleanup_game = rge_base_game;
        if (id != 0) {
            goto pause_loaded;
        }
        ((TRIBE_Game*)cleanup_game)->restart_game();
        return 1;
    } else if (strcmp(panel->panelName(), "QuitGameDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitGameDialog");
        if (id == 0) {
            ((TRIBE_Game*)rge_base_game)->do_game_over();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(panel->panelName(), "CloseProgramDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("CloseProgramDialog");
        if (id == 0) {
            rge_base_game->close();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(panel->panelName(), "ResignDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("ResignDialog");
        if (id == 0) {
            this->resign_flag = 1;
            RGE_Player* player = rge_base_game->get_player();
            player->resign(comm->WhoAmI(), id);
            return 1;
        }
        goto pause_cleanup;
    } else if (strcmp(panel->panelName(), "QuitAndLoadDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitAndLoadDialog");
        if (id == 0) {
            new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            return 1;
        }
        goto pause_cleanup;
    } else {
        goto named_base_action;
    }

pause_cleanup:
    cleanup_game = rge_base_game;
pause_loaded:
    // BINARY NOTE: Restart has a receiver. Other dialogs reload it above.
    // The later accesses reload the global after singlePlayerGame.
    // BINARY NOTE: action reads save_paused at the shipped +0xA00 offset.
    if (cleanup_game->singlePlayerGame() == 1 &&
        *(int*)((char*)rge_base_game + 0xA00) == 0) {
        rge_base_game->set_paused(0, 0);
    }
    goto finish;

clear_cleanup:
    confirmed_close = 0;
    if (rge_base_game->singlePlayerGame() == 1 &&
        *(int*)((char*)rge_base_game + 0xA00) == 0) {
        rge_base_game->set_paused(0, 0);
        return 1;
    }

finish:

    return 1;

null_base_action:
    return TEasy_Panel::action(panel, id, p3, p4);

named_base_action:
    return TEasy_Panel::action(panel, id, p3, p4);
}
