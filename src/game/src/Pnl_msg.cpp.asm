// Auto-generated scaffold unit: pnl_msg.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/pnl_msg.h
#include "../include/common.h"

// Offset: 0x0047A160
long TMessagePanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TMessagePanel::handle_mouse_down(unsigned char,long,long,int,int)     *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TMessagePanel * this, uchar param_
    //              long              EAX:4          <RETURN>
    //              TMessagePanel *   ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_down@TMessagePanel@@UAEJEJJHH@Z                XREF[1]:     005716d8(*)  
    //                               TMessagePanel::handle_mouse_down
    //                              pnl_msg.h:41 (5)
    //         0047a160     XOR        EAX,EAX
    //         0047a162     RET        0x14
}

// Offset: 0x0047A170
long TMessagePanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TMessagePanel::handle_mouse_move(long,long,int,int)                   *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_move(TMessagePanel * this, long param_1
    //              long              EAX:4          <RETURN>
    //              TMessagePanel *   ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?handle_mouse_move@TMessagePanel@@UAEJJJHH@Z                 XREF[1]:     005716dc(*)  
    //                               TMessagePanel::handle_mouse_move
    //                              pnl_msg.h:43 (5)
    //         0047a170     XOR        EAX,EAX
    //         0047a172     RET        0x10
}

// Offset: 0x0047A180
long TMessagePanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TMessagePanel::handle_mouse_up(unsigned char,long,long,int,int)       *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_up(TMessagePanel * this, uchar param_1,
    //              long              EAX:4          <RETURN>
    //              TMessagePanel *   ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_up@TMessagePanel@@UAEJEJJHH@Z                  XREF[1]:     005716e0(*)  
    //                               TMessagePanel::handle_mouse_up
    //                              pnl_msg.h:45 (5)
    //         0047a180     XOR        EAX,EAX
    //         0047a182     RET        0x14
}

