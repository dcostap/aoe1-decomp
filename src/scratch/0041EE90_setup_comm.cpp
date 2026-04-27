// VA: 0041EE90 RGE_Base_Game::setup_comm (342 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: alloc TCommunications_Handler, ctor, configure handlers, set globals

extern void* operator_new(unsigned int size);
extern int TCommHandler_ctor(void* ch, void* prog_window, unsigned char max_players, int chat, int* game_guid);
extern void TCommHandler_StopIfSyncFail(void* ch, int val);
extern void TCommHandler_ShowSyncChatMsgs(void* ch, int val);
extern void TCommHandler_SetStepMode(void* ch, int val);
extern void TCommHandler_SetSpeedControl(void* ch, int val);
extern void TCommHandler_DropPacketsIntentionally(void* ch, int val);
extern void RGE_Game_World_reset_comm(int world, int handler);
extern void TCommHandler_SetSpeedV1(int handler, int val);

int chat_global;
int comm_global;
int speed_val1;
int speed_val2;

struct Shim_1EE90 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char p14[0x18C - 0x14];
    int comm_handler;          // +0x18C
    int comm_syncstop;         // +0x190
    int comm_droppackets;      // +0x194
    int comm_syncmsg;          // +0x198
    int comm_stepmode;         // +0x19C
    int comm_speed;            // +0x1A0
    char p1A4[0x3F4 - 0x1A4];
    int world;                 // +0x3F4
};

int RGE_Base_Game_setup_comm(Shim_1EE90* self)
{
    int guid[4];
    int* gptr;
    void* ch;
    int i;
    
    ch = operator_new(0x1774);
    if (ch) {
        gptr = (int*)((char*)self->prog_info + 0x8E8);
        for (i = 0; i < 4; i++)
            guid[i] = gptr[i];
        TCommHandler_ctor(
            ch, self->prog_window,
            *(unsigned char*)((char*)self->prog_info + 0x878),
            chat_global, guid);
    }
    
    self->comm_handler = (int)ch;
    if (!ch)
        return 0;
    
    TCommHandler_StopIfSyncFail(ch, self->comm_syncstop);
    TCommHandler_ShowSyncChatMsgs(ch, self->comm_syncmsg);
    TCommHandler_SetStepMode(ch, self->comm_stepmode);
    TCommHandler_SetSpeedControl(ch, self->comm_speed);
    TCommHandler_DropPacketsIntentionally(ch, self->comm_droppackets);
    comm_global = (int)ch;
    
    if (self->world)
        RGE_Game_World_reset_comm(self->world, (int)ch);
    
    if (speed_val1)
        TCommHandler_SetSpeedV1((int)ch, speed_val1);
    if (speed_val2)
        TCommHandler_SetSpeedV1((int)ch, speed_val2);
    
    return 1;
}
