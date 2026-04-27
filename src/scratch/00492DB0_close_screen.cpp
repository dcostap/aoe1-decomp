// TRIBE_Credits_Screen::close_screen — real pass (EH-framed)
// VA: 00492DB0
#include "../../include/game_globals.h"

void __fastcall close_screen(void* _this, int _)
{
    void* gamePanel = ((void*(__fastcall*)(void*,int,char*))0x463D50)((void*)0x62E870, 0, (char*)"Game Screen");
    if (gamePanel) {
        int sp = ((int(__fastcall*)(void*,int))0x4223F0)(rge_base_game, 0);
        if (sp == 1) {
            int savePaused = *(int*)((char*)rge_base_game + 0xA00);
            if (!savePaused) {
                ((void(__fastcall*)(void*,int,int,int))0x420220)(rge_base_game, 0, 0, 0);
            }
        }
        ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"Game Screen", 0);
    } else {
        void* mm = operator new(0x4B0);
        if (mm)
            ((void(__fastcall*)(void*,int))0x49E6D0)(mm, 0);
        ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"Main Menu", 0);
    }
    ((void(__fastcall*)(void*,int,char*))0x464060)((void*)0x62E870, 0, (char*)"Credits Screen");
}
