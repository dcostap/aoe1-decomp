// TribeSendMessageDialog::~TribeSendMessageDialog — real pass (EH-framed)
// VA: 00440E20
#include "../../include/game_globals.h"

void __fastcall dtor_TribeSendMessageDialog(void* _this, int _)
{
    // Set vtable
    // delete_panel at +0x490 (title)
    ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x490);
    
    // Loop 8×: delete 3 offsets each iteration (playerCivilization text panels)
    int i;
    void* base = (char*)_this + 0x4B4;
    for (i = 0; i < 8; i++) {
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)base + i*4 - 0x20);
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)base + i*4);
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)base + i*4 + 0x20);
    }
    
    // Loop 4×: delete 2 offsets each iteration (radioButton pairs)
    base = (char*)_this + 0x504;
    for (i = 0; i < 4; i++) {
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)base + i*4 - 0x10);
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)base + i*4);
    }
    
    // Delete individual panels
    ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x518);  // chatInput
    ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x51C);  // chatTitle
    ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x520);  // okButton
    ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x524);  // help_button
    
    // Delete TShape at +0x528
    void* shape = *(void**)((char*)_this + 0x528);
    if (shape) {
        ((void(__fastcall*)(void*,int))0x4B8DD0)(shape, 0);  // TShape::~TShape
        ((void(__fastcall*)(void*,int))0x54B660)(shape, 0);   // operator delete
    }
    
    // Base TDialogPanel dtor
    ((void(__fastcall*)(void*,int))0x473E40)(_this, 0);
}
