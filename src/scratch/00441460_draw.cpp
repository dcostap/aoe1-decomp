// TribeSendMessageDialog::draw — real pass
// VA: 00441460
#include "../../include/game_globals.h"

void __fastcall draw_TribeSendMessageDialog(void* _this, int _)
{
    // Base draw
    ((void(__fastcall*)(void*,int))0x467570)(_this, 0);
    
    void* bg = *(void**)((char*)_this + 0x528);
    if (!bg) return;
    
    void* baseGame = (void*)rge_base_game;
    int* pgmInfo = *(int**)((char*)baseGame + 0x0C);
    int* world = *(int**)((char*)pgmInfo + 0x3F4);
    
    // Lock
    void* vtable = *(void**)_this;
    ((void(__stdcall*)(int))(*(int*)vtable + 0x28))(0);
    
    int i;
    int yOff = 0;
    for (i = 1; i < 9; i++) {
        int pid = ((int(__fastcall*)(void*,int,int))0x422D90)(baseGame, 0, i);
        if (pid) {
            int* players = *(int**)((char*)world + 0x40);
            int* playerObj = *(int**)((char*)players + pid * 4);
            void* colorTable = *(void**)((char*)playerObj + 0x108);
            if (colorTable) {
                short colorId = *(short*)((char*)colorTable + 0x26);
                ((void(__cdecl*)(int))0x56C760)((colorId + 1) * 0x10);
                
                void* colorXform = (char*)colorTable + 0x28;
                int baseX = *(int*)((char*)_this + 0x0C) + 0x32;
                int driveVal = *(int*)((char*)_this + 0x10);
                int* drawArea = *(int**)((char*)_this + 0x20);
                int yPos = driveVal + *(int*)((char*)_this + 0x28) + yOff;
                
                ((void(__fastcall*)(void*,int,void*,int,int,int,int,void*))0x4B9440)(
                    bg, 0, drawArea, baseX, yPos, 0, 1, colorXform);
                
                yOff += 0x1E;
            }
        }
    }
    
    // Unlock
    ((void(__stdcall*)(void))(*(int*)vtable + 0x2C))();
}
