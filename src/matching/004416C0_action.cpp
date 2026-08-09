// TribeSendQuickMessageDialog::action — real pass
// VA: 004416C0
#include <string.h>
#include "../../include/game_globals.h"

long __fastcall action_TribeSendQuickMessageDialog(void* _this, int _, void* sender, long param2, unsigned long param3, unsigned long param4)
{
    if (!sender) goto base_action;
    if (sender != *(void**)((char*)_this + 0x490)) goto base_action;  // chatInput
    
    if (param2 == 0) {
        // OK/Enter pressed
        char* text = ((char*(__fastcall*)(void*,int))0x475B10)(sender, 0);
        if (!text) goto cancel_action;
        text = ((char*(__fastcall*)(void*,int))0x475B10)(sender, 0);
        if (*text == 0) goto cancel_action;
        
        // Copy chat text to stack buffer
        void* parent = *(void**)((char*)_this + 0x40);
        char* src = ((char*(__fastcall*)(void*,int))0x475B10)(sender, 0);
        char buf[64];
        strcpy(buf, src);
        
        // Close dialog, go to game screen
        ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"Game Screen", 0);
        ((void(__fastcall*)(void*,int,char*))0x464060)((void*)0x62E870, 0, (char*)"Send Quick Message Dialog");
        
        // Send message to game
        void* baseGame = (void*)rge_base_game;
        int* pgmInfo = *(int**)((char*)baseGame + 0x0C);
        int world = pgmInfo[0x3F4/4];
        int playerId = *(short*)((char*)world + 0x7C);
        void* vtable = *(void**)baseGame;
        if (!((int(__stdcall*)(int,int))(*(int*)vtable + 0x54))(playerId, (int)buf + 4))
        {
            int isMulti = ((int(__fastcall*)(void*,int))0x422400)(baseGame, 0);
            if (isMulti) {
                int progMode = *(int*)((char*)baseGame + 0x1B0);
                if (progMode != 5) {
                    // Send via communications
                    void* comm = *(void**)0x62C4C0;
                    ((void(__fastcall*)(void*,int,char*))0x429760)(comm, 0, buf + 4);
                }
            } else {
                // Single player: play sound + display message
                ((void(__fastcall*)(void*,int,int))0x422E60)(baseGame, 0, 2);
                ((void(__fastcall*)(void*,int,char*))0x4973F0)(parent, 0, buf);
            }
        }
        return 1;
    }
    
cancel_action:
    if (param2 == 1) {
        // Cancel/Close
        ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"Game Screen", 0);
        ((void(__fastcall*)(void*,int,char*))0x464060)((void*)0x62E870, 0, (char*)"Send Quick Message Dialog");
        return 1;
    }
    
base_action:
    return ((long(__fastcall*)(void*,int,void*,long,unsigned long,unsigned long))0x46A4E0)(_this, 0, sender, param2, param3, param4);
}
