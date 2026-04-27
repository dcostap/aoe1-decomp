// VA: 0052A510 TRIBE_Game::disconnect_multiplayer_game (279 B)
// PDB source: tribegam.cpp
// Packet-grounded: disconnect MP game with timeout wait loop

extern int RGE_Base_Game_multiplayerGame(void* self);
extern void RGE_Base_Game_disable_input(void* self);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* unk1, int unk2);
extern void TCommunications_Handler_SendIResignMsg(void* comm);
extern void TCommunications_Handler_ShutdownGameMessages(void* comm);
extern int TCommunications_Handler_CountWaitingMessages(void* comm);
extern void TCommunications_Handler_GameOver(void* comm);
extern void TCommunications_Handler_UnlinkToLevel(void* comm, int level);
extern unsigned long debug_timeGetTime(const char* file, int line);

void TRIBE_Game_disconnect_multiplayer_game(void* self)
{
    if (!RGE_Base_Game_multiplayerGame(self)) {
        TCommunications_Handler_GameOver(*(void**)((char*)self + 0x18C));
        return;
    }
    
    int mode = *(int*)((char*)self + 0x1B0);
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        void* comm = *(void**)((char*)self + 0x18C);
        TCommunications_Handler_SendIResignMsg(comm);
        TCommunications_Handler_ShutdownGameMessages(comm);
        
        if (TCommunications_Handler_CountWaitingMessages(comm) > 0) {
            RGE_Base_Game_disable_input(self);
            TRIBE_Game_show_status_message(self, 0x4C0, 0, -1);
            
            unsigned long startTime = debug_timeGetTime("tribegam.cpp", 0x15F8);
            unsigned long elapsedStart = startTime;
            
            do {
                void* scenario = *(void**)((char*)self + 0x3F4);
                if (!scenario || *(unsigned char*)((char*)scenario + 0x1D) == 1)
                    break;
                
                TCommunications_Handler_ShutdownGameMessages(comm);
                unsigned long now = debug_timeGetTime("tribegam.cpp", 0x1601);
                if (now - elapsedStart >= 500) {
                    if (TCommunications_Handler_CountWaitingMessages(comm) == 0)
                        break;
                    elapsedStart = debug_timeGetTime("tribegam.cpp", 0x1605);
                }
            } while (elapsedStart - startTime < 15000);
        }
        
        TCommunications_Handler_GameOver(comm);
        TCommunications_Handler_UnlinkToLevel(comm, 5);
        return;
    }
}
