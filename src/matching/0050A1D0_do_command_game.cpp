// VA: 0050A1D0 TRIBE_Command::do_command_game
// PDB: tcommand.cpp lines 531-665.
#include <stdio.h>
#include "../tcommand_context.h"

void TRIBE_Command::do_command_game(TRIBE_Command_Game* cmd)
{
    char file_name[260];
    switch (cmd->game_command) {
    case 5:
        this->world->players[cmd->var1]->set_allied_victory((unsigned char)cmd->var2);
        break;
    case 0:
        this->world->players[cmd->var1]->set_relation(cmd->var2, (unsigned char)cmd->var3);
        rge_base_game->notification(8, cmd->var1, cmd->var2, cmd->var4, 0);
        this->world->update_mutual_allies();
        break;
    case 1:
        this->world->set_game_speed(cmd->var3);
        break;
    case 8:
        {
        out_of_sync2 = 1;
        TRIBE_Screen_Status_Message* status = new TRIBE_Screen_Status_Message("Temp Screen", "", 0, -1);
        (void)status;
        panel_system.setCurrentPanel("Temp Screen", 0);
        rge_base_game->close_game_screens(1);
        if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
            if (actionFile != 0) { fclose(actionFile); actionFile = 0; }
            if (DVlogf != 0) { fclose(DVlogf); DVlogf = 0; }
            if (DDlogf != 0) { fclose(DDlogf); DDlogf = 0; }
        }
        sprintf(file_name, "syncerr%d.gam", comm->WhoAmI());
        rge_base_game->save_game(file_name);
        this->world->players[this->world->curr_player]->loss_if_game_on();
        rge_base_game->do_game_over();
        TEasy_Panel* panel = (TEasy_Panel*)panel_system.currentPanel();
        if (panel != 0) {
            TDrawSystem* draw_system = rge_base_game->draw_system;
            draw_system->SetPalette(panel->get_palette());
            rge_base_game->set_render_all();
            rge_base_game->draw_window();
            panel->popupOKDialog(0x966, 0, 0x1C2, 100);
        }
        panel_system.destroyPanel("Temp Screen");
        break;
        }
    case 2:
        this->world->players[cmd->var1]->add_attribute_num(cmd->var2, cmd->var3, 0);
        break;
    case 4:
        {
        TRIBE_Game* game = rge_base_game;
        game->quick_build = cmd->var1;
        break;
        }
    case 6:
        ((TRIBE_World*)this->world)->cheat(cmd->var1, (short)(unsigned char)cmd->var2);
        break;
    case 7:
        this->world->effects->show_effect(0x71, this->world->players[cmd->var1]);
        break;
    default:
        break;
    }
}
