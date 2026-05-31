// VA: 004212E0 RGE_Base_Game::handle_user_command
// PDB source: basegame.cpp

#define out_of_sync (*(int*)0x62C560)

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class TCommunications_Handler {
public:
    int MultiplayerGameStart();
};

class RGE_Player_Command_Target {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD4(48)
    VPAD1(52)
    virtual void set_chat_flag(long player, int flag);  // slot 53, +0xD4
};

class RGE_Game_World {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD8(48)
    VPAD2(56)
    VPAD1(58)
    virtual void set_world_chat_flag(int flag);          // slot 59, +0xEC

    char gap_04[0x40 - 0x04];
    RGE_Player_Command_Target** players;                 // +0x40
};

class RGE_Base_Game {
public:
    VPAD64(0)
    VPAD1(64)
    virtual int default_handle_user_command(unsigned int command, long param); // slot 65, +0x104

    char gap_004[0x18C - 0x004];
    TCommunications_Handler* comm_handler;               // +0x18C
    char gap_190[0x3F4 - 0x190];
    RGE_Game_World* world;                               // +0x3F4

    int playerID(int player);
    int handle_user_command(void* param_1, unsigned int param_2, unsigned int command, long param);
};

int RGE_Base_Game::handle_user_command(void* param_1, unsigned int param_2, unsigned int command, long param)
{
    if (this->comm_handler->MultiplayerGameStart() != 0 && out_of_sync == 0) {
        if (command == 0x17B3) {
            this->world->players[this->playerID(param)]->set_chat_flag(param, 1);
        } else if (command == 0x17B4) {
            this->world->players[this->playerID(param)]->set_chat_flag(param, 0);
        }
    }

    switch (command) {
    case 0x17A2:
        if (this->world != 0) {
            this->world->set_world_chat_flag(1);
        }
        break;
    case 0x17A3:
        if (this->world != 0) {
            this->world->set_world_chat_flag(0);
        }
        break;
    }

    return this->default_handle_user_command(command, param) != 0;
}
