// VA: 004212E0 RGE_Base_Game::handle_user_command
// PDB source: basegame.cpp

extern int out_of_sync;




int RGE_Base_Game::handle_user_command(void* param_1, unsigned int param_2, unsigned int command, long param)
{
    if (this->comm_handler->MultiplayerGameStart() != 0 && out_of_sync == 0) {
        if (command == 0x17B3) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 1);
        } else if (command == 0x17B4) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 0);
        }
    }

    switch (command) {
    case 0x17A2:
        if (this->world != 0) {
            this->world->pause((unsigned char)1);
        }
        break;
    case 0x17A3:
        if (this->world != 0) {
            this->world->pause((unsigned char)0);
        }
        break;
    }

    return this->default_handle_user_command(command, param) != 0;
}
