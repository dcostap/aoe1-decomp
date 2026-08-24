// VA: 0041EE90 RGE_Base_Game::setup_comm (342 B) EH-framed
// PDB source: basegame.cpp:2483-2506
//
// Attempt log:
// - Replaced the packet scaffold's free helper shims and raw member offsets
//   with the period typed new-expression, GUID value parameter, member calls,
//   and named RGE_Base_Game/RGE_Prog_Info ownership.

#include <new.h>
#include <windows.h>

class TChat;

#ifndef BASEGAME_GROUPED_TU
class RGE_Prog_Info {
public:
    char gap_000[0x878];
    int max_players;
    char gap_87C[0x8E8 - 0x87C];
    _GUID game_guid;
};

class TCommunications_Handler {
public:
    char gap_000[0x1774];

    TCommunications_Handler(void* host_hwnd, unsigned char max_game_players,
                            TChat* chat, _GUID application_guid);
    ~TCommunications_Handler();

    void StopIfSyncFail(int flag);
    void ShowSyncChatMsgs(int param);
    void SetStepMode(int value);
    void SetSpeedControl(int value);
    void DropPacketsIntentionally(int flag);
    void SetSpeedV1(int value);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    void reset_communications(TCommunications_Handler* handler);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_004[0x08];
    RGE_Prog_Info* prog_info;
    void* prog_window;
    char gap_014[0x18C - 0x14];
    TCommunications_Handler* comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    char gap_1A4[0x3F4 - 0x1A4];
    RGE_Game_World* world;

    int setup_comm();
};
#endif

extern TChat* chat;
extern TCommunications_Handler* comm;
extern int speed_val1;
extern int speed_val2;

int RGE_Base_Game::setup_comm()
{
    TCommunications_Handler* new_comm;

    new_comm = new TCommunications_Handler(
        this->prog_window,
        (unsigned char)this->prog_info->max_players,
        chat,
        this->prog_info->game_guid);
    this->comm_handler = new_comm;

    if (new_comm == 0)
        return 0;

    new_comm->StopIfSyncFail(this->comm_syncstop);
    this->comm_handler->ShowSyncChatMsgs(this->comm_syncmsg);
    this->comm_handler->SetStepMode(this->comm_stepmode);
    this->comm_handler->SetSpeedControl(this->comm_speed);
    this->comm_handler->DropPacketsIntentionally(this->comm_droppackets);
    comm = this->comm_handler;

    if (this->world != 0)
        this->world->reset_communications(this->comm_handler);

    if (speed_val1 != 0)
        this->comm_handler->SetSpeedV1(speed_val1);
    if (speed_val2 != 0)
        this->comm_handler->SetSpeedV1(speed_val2);

    return 1;
}
