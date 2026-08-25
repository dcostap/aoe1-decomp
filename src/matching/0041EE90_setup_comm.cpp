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
