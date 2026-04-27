// 00520E30 TRIBE_Panel_Text_Line::set_info
// Source: tpnl_txl.cpp lines 40-47
//
// Attempt log:
// Probe 1: strcmp/strcpy with __stdcall function ptr — 30.8% diff, register allocation off
// Probe 2: swapped operand order (type == text_type, strcmp(str, text)) — 20.1% diff, strcmp matches!
//   Remaining: vtable load timing and no ecx=this in set_redraw call
// Probe 3: declare set_redraw in TPanel and call as member function for thiscall codegen

#include "..\..\include\game_globals.h"
#include <string.h>

class TPanel {
public:
    char gap_00[0x7C];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int);
    virtual long handle_idle();

    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char modal);
};

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;                    // +0xF4 (4)
    unsigned char text_type;       // +0xF8 (1)
    char text[200];                // +0xF9 (200)
    char _pad[3];                  // +0x1C1 (3)
    long id;                       // +0x1C4 (4)

    virtual ~TRIBE_Panel_Text_Line();
    virtual void* scalar_deleting_destructor(unsigned int);
    virtual long draw();
    virtual void set_info(unsigned char type, char* str, long new_id);
};

void TRIBE_Panel_Text_Line::set_info(unsigned char type, char* str, long new_id)
{
    if (type == this->text_type && strcmp(str, this->text) == 0 && new_id == this->id)
        return;

    this->text_type = type;
    strcpy(this->text, str);
    this->id = new_id;

    this->set_redraw(1);
}
