// TribeSendQuickMessageDialog::TribeSendQuickMessageDialog — real pass (EH-framed)
// VA: 00441530
#include "../../include/game_globals.h"

void __fastcall ctor_TribeSendQuickMessageDialog(void* _this, int _, void* parent, int mode)
{
    // Base ctor: TDialogPanel("Send Quick Message Dialog")
    ((void(__fastcall*)(void*,int,char*))0x473C10)(_this, 0, "Send Quick Message Dialog");
    
    // Store mode param
    *(int*)((char*)_this + 0x498) = mode;
    
    // Get popup info from parent
    long infoId = ((long(__fastcall*)(void*,int))0x468450)(parent, 0);
    char* infoFile = ((char*(__fastcall*)(void*,int))0x468440)(parent, 0);
    void* drawArea = ((void*(__fastcall*)(void*,int))0x4667B0)(parent, 0);  // renderArea
    
    // Setup
    int setupOk = ((int(__fastcall*)(void*,int,void*,void*,int,int,char*,long,int))0x473C80)(
        _this, 0, drawArea, parent, 0x21C, 0x23, infoFile, infoId, 1);
    if (!setupOk) return;
    
    // Chat title string ID: conditional on mode
    int strId = (-(unsigned int)(mode != 1) & 5) + 0x2668;
    
    // Create text for chat title
    int textOk = ((int(__fastcall*)(void*,int,void*,void*,int,int,int,int,int,int,int,int,int))0x468C20)(
        _this, 0, _this, (char*)_this + 0x494, strId, 5, 5, 0x78, 0x19, 4, 1, 1, 0);
    if (!textOk) return;
    
    // Create edit for chat input
    int editOk = ((int(__fastcall*)(void*,int,void*,void*,char*,int,int,int,int,int,int,int,int,int))0x4691C0)(
        _this, 0, _this, (char*)_this + 0x490, "", 0x41, 0, 0x82, 5, 0x195, 0x19, 0x0B, 1, 0);
    if (!editOk) return;
    
    // Set current child to the edit box
    void* chatInput = *(void**)((char*)_this + 0x490);
    ((void(__fastcall*)(void*,int,void*))0x4663A0)(_this, 0, chatInput);
}
