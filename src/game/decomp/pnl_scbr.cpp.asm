// Auto-generated scaffold unit: pnl_scbr.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Pnl_scbr.cpp
#include "../include/common.h"

// Offset: 0x0047A700
undefined TScrollBarPanel(TScrollBarPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TScrollBarPanel::TScrollBarPanel(void)                                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TScrollBarPanel(TScrollBarPanel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0047a761(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0047a868(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0047a71b(W)  
    //                               ??0TScrollBarPanel@@QAE@XZ                                   XREF[3]:     create_scrollbar:0046997e(c), 
    //                               TScrollBarPanel::TScrollBarPanel                                          setup:0047427b(c), 
    //                                                                                                         TVerticalSliderPanel:0047bce3(c)  
    //                              Pnl_scbr.cpp:66 (38)
    //         0047a700     PUSH       -0x1
    //         0047a702     PUSH       FUN_0055e578
    //         0047a707     MOV        EAX,FS:[0x0]
    //         0047a70d     PUSH       EAX
    //         0047a70e     MOV        dword ptr FS:[0x0],ESP
    //         0047a715     PUSH       this
    //         0047a716     PUSH       EBX
    //         0047a717     PUSH       ESI
    //         0047a718     MOV        ESI,this
    //         0047a71a     PUSH       EDI
    //         0047a71b     MOV        dword ptr [ESP + local_10],ESI
    //         0047a71f     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //         0047a724     XOR        EBX,EBX
    //                              Pnl_scbr.cpp:71 (270)
    //         0047a726     MOV        EDI,dword ptr [->USER32.DLL::SetRect]            = 0048b002
    //         0047a72c     MOV        dword ptr [ESI + 0xf4],EBX
    //         0047a732     MOV        dword ptr [ESI + 0xf8],EBX
    //         0047a738     MOV        dword ptr [ESI + 0xfc],EBX
    //         0047a73e     PUSH       EBX
    //         0047a73f     MOV        dword ptr [ESI + 0x100],EBX
    //         0047a745     PUSH       EBX
    //         0047a746     MOV        dword ptr [ESI + 0x104],EBX
    //         0047a74c     PUSH       EBX
    //         0047a74d     LEA        EAX,[ESI + 0x164]
    //         0047a753     MOV        dword ptr [ESI + 0x108],EBX
    //         0047a759     PUSH       EBX
    //         0047a75a     MOV        dword ptr [ESI + 0x10c],EBX
    //         0047a760     PUSH       EAX
    //         0047a761     MOV        dword ptr [ESP + local_4],EBX
    //         0047a765     MOV        dword ptr [ESI + 0x110],EBX
    //         0047a76b     MOV        dword ptr [ESI + 0x114],EBX
    //         0047a771     MOV        dword ptr [ESI + 0x118],EBX
    //         0047a777     MOV        dword ptr [ESI + 0x11c],EBX
    //         0047a77d     MOV        dword ptr [ESI + 0x120],EBX
    //         0047a783     MOV        dword ptr [ESI + 0x124],EBX
    //         0047a789     MOV        dword ptr [ESI + 0x128],EBX
    //         0047a78f     MOV        dword ptr [ESI + 0x12c],EBX
    //         0047a795     MOV        dword ptr [ESI + 0x130],EBX
    //         0047a79b     MOV        dword ptr [ESI + 0x134],EBX
    //         0047a7a1     MOV        dword ptr [ESI + 0x138],EBX
    //         0047a7a7     MOV        dword ptr [ESI + 0x13c],EBX
    //         0047a7ad     MOV        dword ptr [ESI + 0x140],EBX
    //         0047a7b3     MOV        byte ptr [ESI + 0x144],BL
    //         0047a7b9     MOV        dword ptr [ESI + 0x148],EBX
    //         0047a7bf     MOV        dword ptr [ESI + 0x14c],EBX
    //         0047a7c5     MOV        dword ptr [ESI + 0x150],EBX
    //         0047a7cb     MOV        byte ptr [ESI + 0x154],BL
    //         0047a7d1     MOV        dword ptr [ESI + 0x158],EBX
    //         0047a7d7     MOV        dword ptr [ESI + 0x15c],0x64
    //         0047a7e1     MOV        dword ptr [ESI + 0x160],0xfa
    //         0047a7eb     MOV        dword ptr [ESI + 0x1b4],EBX
    //         0047a7f1     MOV        dword ptr [ESI + 0x1b8],0x1
    //         0047a7fb     MOV        byte ptr [ESI + 0x1bc],BL
    //         0047a801     MOV        byte ptr [ESI + 0x1bd],BL
    //         0047a807     MOV        byte ptr [ESI + 0x1be],BL
    //         0047a80d     MOV        byte ptr [ESI + 0x1bf],BL
    //         0047a813     MOV        byte ptr [ESI + 0x1c0],BL
    //         0047a819     MOV        byte ptr [ESI + 0x1c1],BL
    //         0047a81f     MOV        dword ptr [ESI],TScrollBarPanel::`vftable'       = 0047a880
    //         0047a825     MOV        byte ptr [ESI + 0xee],0x5
    //         0047a82c     MOV        dword ptr [ESI + 0xc0],EBX
    //         0047a832     CALL       EDI=>USER32.DLL::SetRect
    //                              Pnl_scbr.cpp:72 (13)
    //         0047a834     PUSH       EBX
    //         0047a835     PUSH       EBX
    //         0047a836     PUSH       EBX
    //         0047a837     LEA        this,[ESI + 0x174]
    //         0047a83d     PUSH       EBX
    //         0047a83e     PUSH       this
    //         0047a83f     CALL       EDI=>USER32.DLL::SetRect
    //                              Pnl_scbr.cpp:73 (13)
    //         0047a841     PUSH       EBX
    //         0047a842     PUSH       EBX
    //         0047a843     PUSH       EBX
    //         0047a844     LEA        EDX,[ESI + 0x184]
    //         0047a84a     PUSH       EBX
    //         0047a84b     PUSH       EDX
    //         0047a84c     CALL       EDI=>USER32.DLL::SetRect
    //                              Pnl_scbr.cpp:74 (13)
    //         0047a84e     PUSH       EBX
    //         0047a84f     PUSH       EBX
    //         0047a850     PUSH       EBX
    //         0047a851     LEA        EAX,[ESI + 0x194]
    //         0047a857     PUSH       EBX
    //         0047a858     PUSH       EAX
    //         0047a859     CALL       EDI=>USER32.DLL::SetRect
    //                              Pnl_scbr.cpp:75 (13)
    //         0047a85b     PUSH       EBX
    //         0047a85c     PUSH       EBX
    //         0047a85d     PUSH       EBX
    //         0047a85e     PUSH       EBX
    //         0047a85f     LEA        this,[ESI + 0x1a4]
    //         0047a865     PUSH       this
    //         0047a866     CALL       EDI=>USER32.DLL::SetRect
    //                              Pnl_scbr.cpp:76 (20)
    //         0047a868     MOV        this,dword ptr [ESP + local_c]
    //         0047a86c     MOV        EAX,ESI
    //         0047a86e     POP        EDI
    //         0047a86f     POP        ESI
    //         0047a870     MOV        dword ptr FS:[0x0],this
    //         0047a877     POP        EBX
    //         0047a878     ADD        ESP,0x10
    //         0047a87b     RET
}

// Offset: 0x0047A8A0
void TScrollBarPanel(TScrollBarPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TScrollBarPanel::~TScrollBarPanel(void)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TScrollBarPanel(TScrollBarPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //                               ??1TScrollBarPanel@@UAE@XZ                                   XREF[2]:     `scalar_deleting_destructor':0047a
    //                               TScrollBarPanel::~TScrollBarPanel                                         ~TVerticalSliderPanel:0047bd36(c)  
    //                              Pnl_scbr.cpp:82 (11)
    //         0047a8a0     MOV        dword ptr [this->_padding_],TScrollBarPanel::`   = 0047a880
    //         0047a8a6     JMP        TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0047A8B0
long setup(TScrollBarPanel* this_, TDrawArea* param_2, TPanel* param_3, long param_4, long param_5, long param_6, long param_7, char* param_8, char* param_9, char* param_10, char* param_11, long param_12, long param_13, TPanel* param_14, long param_15, Orientation param_16) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TScrollBarPanel::setup(class TDrawArea *,class TPanel *,long,long,long,lon... *
    //                              *********************************************************************************************************
    //                              long __thiscall setup(TScrollBarPanel * this, TDrawArea * param_1, T
    //              long              EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047a8fc(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0047a8f7(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0047a8f2(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0047a8ed(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0047a8e6(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0047a8dc(R)  
    //              char *            Stack[0x1c]:4  param_7
    //              char *            Stack[0x20]:4  param_8
    //              char *            Stack[0x24]:4  param_9
    //              char *            Stack[0x28]:4  param_10
    //              long              Stack[0x2c]:4  param_11                  XREF[1]:     0047a8b4(R)  
    //              long              Stack[0x30]:4  param_12                  XREF[1]:     0047a8be(R)  
    //              TPanel *          Stack[0x34]:4  param_13                  XREF[1]:     0047a8c8(R)  
    //              long              Stack[0x38]:4  param_14                  XREF[1]:     0047a8d2(R)  
    //              Orientation       Stack[0x3c]:4  param_15                  XREF[1]:     0047a8b0(R)  
    //                               ?setup@TScrollBarPanel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJPA  XREF[4]:     create_scrollbar:004699d8(c), 
    //                               TScrollBarPanel::setup                                                    setup:004742e4(c), 
    //                                                                                                         setup:0047bd95(c), 
    //                                                                                                         setup:0047be95(c)  
    //                              Pnl_scbr.cpp:117 (4)
    //         0047a8b0     MOV        EAX,dword ptr [ESP + param_15]
    //                              Pnl_scbr.cpp:120 (10)
    //         0047a8b4     MOV        EDX,dword ptr [ESP + param_11]
    //         0047a8b8     MOV        dword ptr [ECX + this->orientationValue],EAX
    //                              Pnl_scbr.cpp:121 (10)
    //         0047a8be     MOV        EAX,dword ptr [ESP + param_12]
    //         0047a8c2     MOV        dword ptr [ECX + this->arrowSize],EDX
    //                              Pnl_scbr.cpp:122 (10)
    //         0047a8c8     MOV        EDX,dword ptr [ESP + param_13]
    //         0047a8cc     MOV        dword ptr [ECX + this->tabSize],EAX
    //                              Pnl_scbr.cpp:123 (10)
    //         0047a8d2     MOV        EAX,dword ptr [ESP + param_14]
    //         0047a8d6     MOV        dword ptr [ECX + this->list_panel],EDX
    //                              Pnl_scbr.cpp:125 (43)
    //         0047a8dc     MOV        EDX,dword ptr [ESP + param_6]
    //         0047a8e0     MOV        dword ptr [ECX + this->list_len],EAX
    //         0047a8e6     MOV        EAX,dword ptr [ESP + param_5]
    //         0047a8ea     PUSH       0x0
    //         0047a8ec     PUSH       EDX
    //         0047a8ed     MOV        EDX,dword ptr [ESP + param_4]
    //         0047a8f1     PUSH       EAX
    //         0047a8f2     MOV        EAX,dword ptr [ESP + param_3]
    //         0047a8f6     PUSH       EDX
    //         0047a8f7     MOV        EDX,dword ptr [ESP + param_2]
    //         0047a8fb     PUSH       EAX
    //         0047a8fc     MOV        EAX,dword ptr [ESP + param_1]
    //         0047a900     PUSH       EDX
    //         0047a901     PUSH       EAX
    //         0047a902     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //                              Pnl_scbr.cpp:132 (5)
    //         0047a907     MOV        EAX,0x1
    //                              Pnl_scbr.cpp:133 (3)
    //         0047a90c     RET        0x3c
}

// Offset: 0x0047A910
void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TScrollBarPanel::set_rect(long,long,long,long)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall set_rect(TScrollBarPanel * this, long param_1, long 
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0047a923(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0047a914(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0047a91d(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0047a910(R)  
    //                               ?set_rect@TScrollBarPanel@@UAEXJJJJ@Z                        XREF[3]:     set_rect:0047bdd4(c), 
    //                               TScrollBarPanel::set_rect                                                 set_rect:0047bed9(c), 0057183c(*)  
    //                              Pnl_scbr.cpp:139 (33)
    //         0047a910     MOV        EAX,dword ptr [ESP + param_4]
    //         0047a914     MOV        EDX,dword ptr [ESP + param_2]
    //         0047a918     PUSH       EBX
    //         0047a919     PUSH       EBP
    //         0047a91a     PUSH       ESI
    //         0047a91b     MOV        ESI,this
    //         0047a91d     MOV        this,dword ptr [ESP + param_3]
    //         0047a921     PUSH       EDI
    //         0047a922     PUSH       EAX
    //         0047a923     MOV        EAX,dword ptr [ESP + param_1]
    //         0047a927     PUSH       this
    //         0047a928     PUSH       EDX
    //         0047a929     PUSH       EAX
    //         0047a92a     MOV        this,ESI
    //         0047a92c     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
    //                              Pnl_scbr.cpp:143 (13)
    //         0047a931     CMP        dword ptr [ESI + 0x1b4],0x1
    //         0047a938     JNZ        LAB_0047a9df
    //                              Pnl_scbr.cpp:144 (3)
    //         0047a93e     MOV        EAX,dword ptr [ESI + 0x10]
    //                              Pnl_scbr.cpp:145 (3)
    //         0047a941     MOV        EDX,dword ptr [ESI + 0x18]
    //                              Pnl_scbr.cpp:151 (38)
    //         0047a944     MOV        EBP,dword ptr [ESI + 0x14]
    //         0047a947     LEA        this,[EAX + 0x2]
    //         0047a94a     LEA        EDI,[EDX + EAX*0x1 + -0x5]
    //         0047a94e     MOV        EAX,dword ptr [ESI + 0xc]
    //         0047a951     MOV        dword ptr [ESI + 0x168],this
    //         0047a957     ADD        EBP,EAX
    //         0047a959     MOV        dword ptr [ESI + 0x178],this
    //         0047a95f     SUB        EBP,EDX
    //         0047a961     LEA        EBX,[EAX + 0x2]
    //         0047a964     MOV        dword ptr [ESI + 0x164],EBX
    //                              Pnl_scbr.cpp:154 (19)
    //         0047a96a     MOV        dword ptr [ESI + 0x188],this
    //         0047a970     LEA        EAX,[EBP + 0x2]
    //         0047a973     LEA        EBX,[EBX + EDX*0x1 + -0x5]
    //         0047a977     MOV        dword ptr [ESI + 0x174],EAX
    //                              Pnl_scbr.cpp:157 (10)
    //         0047a97d     MOV        dword ptr [ESI + 0x198],this
    //         0047a983     LEA        EBP,[EAX + EDX*0x1 + -0x5]
    //                              Pnl_scbr.cpp:160 (6)
    //         0047a987     MOV        dword ptr [ESI + 0x1a8],this
    //                              Pnl_scbr.cpp:163 (3)
    //         0047a98d     LEA        this,[EBX + 0x1]
    //                              Pnl_scbr.cpp:164 (11)
    //         0047a990     SUB        EAX,EDX
    //         0047a992     MOV        dword ptr [ESI + 0x138],this
    //         0047a998     ADD        EAX,0x4
    //                              Pnl_scbr.cpp:165 (6)
    //         0047a99b     MOV        dword ptr [ESI + 0x134],this
    //                              Pnl_scbr.cpp:192 (55)
    //         0047a9a1     MOV        this,ESI
    //         0047a9a3     MOV        dword ptr [ESI + 0x170],EDI
    //         0047a9a9     MOV        dword ptr [ESI + 0x16c],EBX
    //         0047a9af     MOV        dword ptr [ESI + 0x180],EDI
    //         0047a9b5     MOV        dword ptr [ESI + 0x17c],EBP
    //         0047a9bb     MOV        dword ptr [ESI + 0x190],EDI
    //         0047a9c1     MOV        dword ptr [ESI + 0x1a0],EDI
    //         0047a9c7     MOV        dword ptr [ESI + 0x1b0],EDI
    //         0047a9cd     MOV        dword ptr [ESI + 0x13c],EAX
    //         0047a9d3     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:193 (7)
    //         0047a9d8     POP        EDI
    //         0047a9d9     POP        ESI
    //         0047a9da     POP        EBP
    //         0047a9db     POP        EBX
    //         0047a9dc     RET        0x10
    //                               LAB_0047a9df                                                 XREF[1]:     0047a938(j)  
    //                              Pnl_scbr.cpp:170 (3)
    //         0047a9df     MOV        this,dword ptr [ESI + 0x10]
    //                              Pnl_scbr.cpp:175 (48)
    //         0047a9e2     MOV        EBP,dword ptr [ESI + 0x18]
    //         0047a9e5     MOV        EDX,dword ptr [ESI + 0x14]
    //         0047a9e8     MOV        EAX,dword ptr [ESI + 0xc]
    //         0047a9eb     ADD        EBP,this
    //         0047a9ed     LEA        EBX,[ECX + this+0x2]
    //         0047a9f0     SUB        EBP,EDX
    //         0047a9f2     ADD        EAX,0x2
    //         0047a9f5     MOV        dword ptr [ESI + 0x168],EBX
    //         0047a9fb     LEA        EBX,[EDX + EBX*0x1 + -0x5]
    //         0047a9ff     LEA        this,[EBP + 0x2]
    //         0047aa02     MOV        dword ptr [ESI + 0x164],EAX
    //         0047aa08     MOV        dword ptr [ESI + 0x178],this
    //         0047aa0e     LEA        EDI,[EDX + EAX*0x1 + -0x5]
    //                              Pnl_scbr.cpp:176 (4)
    //         0047aa12     LEA        EBP,[this->_padding_ + EDX*0x1 + -0x5]
    //                              Pnl_scbr.cpp:188 (38)
    //         0047aa16     SUB        this,EDX
    //         0047aa18     ADD        this,0x4
    //         0047aa1b     MOV        dword ptr [ESI + 0x174],EAX
    //         0047aa21     MOV        dword ptr [ESI + 0x184],EAX
    //         0047aa27     MOV        dword ptr [ESI + 0x194],EAX
    //         0047aa2d     MOV        dword ptr [ESI + 0x1a4],EAX
    //         0047aa33     LEA        EAX,[EBX + 0x1]
    //         0047aa36     MOV        dword ptr [ESI + 0x12c],this
    //                              Pnl_scbr.cpp:192 (61)
    //         0047aa3c     MOV        this,ESI
    //         0047aa3e     MOV        dword ptr [ESI + 0x16c],EDI
    //         0047aa44     MOV        dword ptr [ESI + 0x170],EBX
    //         0047aa4a     MOV        dword ptr [ESI + 0x17c],EDI
    //         0047aa50     MOV        dword ptr [ESI + 0x180],EBP
    //         0047aa56     MOV        dword ptr [ESI + 0x18c],EDI
    //         0047aa5c     MOV        dword ptr [ESI + 0x19c],EDI
    //         0047aa62     MOV        dword ptr [ESI + 0x1ac],EDI
    //         0047aa68     MOV        dword ptr [ESI + 0x128],EAX
    //         0047aa6e     MOV        dword ptr [ESI + 0x124],EAX
    //         0047aa74     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:193 (7)
    //         0047aa79     POP        EDI
    //         0047aa7a     POP        ESI
    //         0047aa7b     POP        EBP
    //         0047aa7c     POP        EBX
    //         0047aa7d     RET        0x10
}

// Offset: 0x0047AA80
void calc_item_rects(TScrollBarPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TScrollBarPanel::calc_item_rects(void)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall calc_item_rects(TScrollBarPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //                               ?calc_item_rects@TScrollBarPanel@@IAEXXZ                     XREF[6]:     set_rect:0047a9d3(c), 
    //                               TScrollBarPanel::calc_item_rects                                          set_rect:0047aa74(c), 
    //                                                                                                         set_tab_pos:0047abfb(c), 
    //                                                                                                         mouse_left_move_action:0047b24d(c)
    //                                                                                                         mouse_left_move_action:0047b33b(c)
    //                                                                                                         set_rect:0047bf1d(c)  
    //                              Pnl_scbr.cpp:198 (12)
    //         0047aa80     MOV        EAX,dword ptr [ECX + this->orientationValue]
    //         0047aa86     PUSH       ESI
    //         0047aa87     CMP        EAX,0x1
    //         0047aa8a     JNZ        LAB_0047aacf
    //                              Pnl_scbr.cpp:201 (6)
    //         0047aa8c     MOV        EAX,dword ptr [ECX + this->tab_x]
    //                              Pnl_scbr.cpp:202 (3)
    //         0047aa92     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              Pnl_scbr.cpp:204 (17)
    //         0047aa95     MOV        ESI,dword ptr [ECX + this+0x16c]
    //         0047aa9b     MOV        dword ptr [ECX + this->tab_rect.left],EAX
    //         0047aaa1     LEA        EDX,[EDX + EAX*0x1 + -0x5]
    //         0047aaa5     INC        ESI
    //                              Pnl_scbr.cpp:205 (13)
    //         0047aaa6     DEC        EAX
    //         0047aaa7     MOV        dword ptr [ECX + this+0x18c],EDX
    //         0047aaad     MOV        dword ptr [ECX + this+0x19c],EAX
    //                              Pnl_scbr.cpp:208 (26)
    //         0047aab3     MOV        EAX,dword ptr [ECX + this->down_rect.left]
    //         0047aab9     INC        EDX
    //         0047aaba     DEC        EAX
    //         0047aabb     MOV        dword ptr [ECX + this->top_rect.left],ESI
    //         0047aac1     MOV        dword ptr [ECX + this->bottom_rect.left],EDX
    //         0047aac7     MOV        dword ptr [ECX + this+0x1ac],EAX
    //                              Pnl_scbr.cpp:220 (2)
    //         0047aacd     POP        ESI
    //         0047aace     RET
    //                               LAB_0047aacf                                                 XREF[1]:     0047aa8a(j)  
    //                              Pnl_scbr.cpp:211 (6)
    //         0047aacf     MOV        EAX,dword ptr [ECX + this->tab_y]
    //                              Pnl_scbr.cpp:212 (3)
    //         0047aad5     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              Pnl_scbr.cpp:214 (17)
    //         0047aad8     MOV        ESI,dword ptr [ECX + this+0x170]
    //         0047aade     MOV        dword ptr [ECX + this+0x188],EAX
    //         0047aae4     LEA        EDX,[EDX + EAX*0x1 + -0x5]
    //         0047aae8     INC        ESI
    //                              Pnl_scbr.cpp:215 (13)
    //         0047aae9     DEC        EAX
    //         0047aaea     MOV        dword ptr [ECX + this+0x190],EDX
    //         0047aaf0     MOV        dword ptr [ECX + this+0x1a0],EAX
    //                              Pnl_scbr.cpp:218 (26)
    //         0047aaf6     MOV        EAX,dword ptr [ECX + this+0x178]
    //         0047aafc     INC        EDX
    //         0047aafd     DEC        EAX
    //         0047aafe     MOV        dword ptr [ECX + this+0x198],ESI
    //         0047ab04     MOV        dword ptr [ECX + this+0x1a8],EDX
    //         0047ab0a     MOV        dword ptr [ECX + this+0x1b0],EAX
    //                              Pnl_scbr.cpp:220 (2)
    //         0047ab10     POP        ESI
    //         0047ab11     RET
}

// Offset: 0x0047AB20
void set_tab_pos(TScrollBarPanel* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollBarPanel::set_tab_pos(long)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_tab_pos(TScrollBarPanel * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0047ab25(R)  
    //                               ?set_tab_pos@TScrollBarPanel@@QAEXJ@Z                        XREF[5]:     TribeConfigDialog:0043b946(c), 
    //                               TScrollBarPanel::set_tab_pos                                              TribeConfigDialog:0043ba4b(c), 
    //                                                                                                         TribeConfigDialog:0043bb2f(c), 
    //                                                                                                         set_list_len:0047ac1f(c), 
    //                                                                                                         scroll:0047b4a0(c)  
    //                              Pnl_scbr.cpp:225 (5)
    //         0047ab20     PUSH       EBX
    //         0047ab21     PUSH       ESI
    //         0047ab22     MOV        ESI,this
    //         0047ab24     PUSH       EDI
    //                              Pnl_scbr.cpp:226 (4)
    //         0047ab25     MOV        EDI,dword ptr [ESP + param_1]
    //                              Pnl_scbr.cpp:229 (6)
    //         0047ab29     MOV        EAX,dword ptr [ESI + 0x1b4]
    //                              Pnl_scbr.cpp:230 (21)
    //         0047ab2f     MOV        EBX,dword ptr [ESI + 0xf8]
    //         0047ab35     CMP        EAX,0x1
    //         0047ab38     MOV        dword ptr [ESI + 0x104],EDI
    //         0047ab3e     JNZ        LAB_0047ab97
    //         0047ab40     TEST       EBX,EBX
    //         0047ab42     JLE        LAB_0047ab6d
    //                              Pnl_scbr.cpp:232 (41)
    //         0047ab44     MOV        EAX,dword ptr [ESI + 0x120]
    //         0047ab4a     MOV        this,dword ptr [ESI + 0x138]
    //         0047ab50     CDQ
    //         0047ab51     SUB        EAX,EDX
    //         0047ab53     MOV        EDX,dword ptr [ESI + 0x13c]
    //         0047ab59     SAR        EAX,0x1
    //         0047ab5b     ADD        EAX,EDX
    //         0047ab5d     SUB        EAX,this
    //         0047ab5f     IMUL       EAX,EDI
    //         0047ab62     CDQ
    //         0047ab63     IDIV       EBX
    //         0047ab65     ADD        EAX,this
    //         0047ab67     MOV        dword ptr [ESI + 0x134],EAX
    //                               LAB_0047ab6d                                                 XREF[1]:     0047ab42(j)  
    //                              Pnl_scbr.cpp:233 (16)
    //         0047ab6d     MOV        EAX,dword ptr [ESI + 0x134]
    //         0047ab73     MOV        this,dword ptr [ESI + 0x138]
    //         0047ab79     CMP        EAX,this
    //         0047ab7b     JGE        LAB_0047ab85
    //                              Pnl_scbr.cpp:234 (6)
    //         0047ab7d     MOV        dword ptr [ESI + 0x134],this
    //                              Pnl_scbr.cpp:235 (12)
    //         0047ab83     JMP        LAB_0047abf9
    //                               LAB_0047ab85                                                 XREF[1]:     0047ab7b(j)  
    //         0047ab85     MOV        this,dword ptr [ESI + 0x13c]
    //         0047ab8b     CMP        EAX,this
    //         0047ab8d     JLE        LAB_0047abf9
    //                              Pnl_scbr.cpp:236 (6)
    //         0047ab8f     MOV        dword ptr [ESI + 0x134],this
    //                              Pnl_scbr.cpp:238 (2)
    //         0047ab95     JMP        LAB_0047abf9
    //                               LAB_0047ab97                                                 XREF[1]:     0047ab3e(j)  
    //                              Pnl_scbr.cpp:239 (4)
    //         0047ab97     TEST       EBX,EBX
    //         0047ab99     JLE        LAB_0047abd9
    //                              Pnl_scbr.cpp:240 (7)
    //         0047ab9b     LEA        EAX,[EBX + -0x1]
    //         0047ab9e     CMP        EDI,EAX
    //         0047aba0     JNZ        LAB_0047abb0
    //                              Pnl_scbr.cpp:241 (12)
    //         0047aba2     MOV        this,dword ptr [ESI + 0x12c]
    //         0047aba8     MOV        dword ptr [ESI + 0x124],this
    //                              Pnl_scbr.cpp:242 (2)
    //         0047abae     JMP        LAB_0047abd9
    //                               LAB_0047abb0                                                 XREF[1]:     0047aba0(j)  
    //                              Pnl_scbr.cpp:243 (41)
    //         0047abb0     MOV        EAX,dword ptr [ESI + 0x120]
    //         0047abb6     MOV        this,dword ptr [ESI + 0x128]
    //         0047abbc     CDQ
    //         0047abbd     SUB        EAX,EDX
    //         0047abbf     MOV        EDX,dword ptr [ESI + 0x12c]
    //         0047abc5     SAR        EAX,0x1
    //         0047abc7     ADD        EAX,EDX
    //         0047abc9     SUB        EAX,this
    //         0047abcb     IMUL       EAX,EDI
    //         0047abce     CDQ
    //         0047abcf     IDIV       EBX
    //         0047abd1     ADD        EAX,this
    //         0047abd3     MOV        dword ptr [ESI + 0x124],EAX
    //                               LAB_0047abd9                                                 XREF[2]:     0047ab99(j), 0047abae(j)  
    //                              Pnl_scbr.cpp:245 (14)
    //         0047abd9     MOV        EAX,dword ptr [ESI + 0x124]
    //         0047abdf     MOV        this,dword ptr [ESI + 0x128]
    //         0047abe5     CMP        EAX,this
    //                              Pnl_scbr.cpp:247 (12)
    //         0047abe7     JL         LAB_0047abf3
    //         0047abe9     MOV        this,dword ptr [ESI + 0x12c]
    //         0047abef     CMP        EAX,this
    //         0047abf1     JLE        LAB_0047abf9
    //                               LAB_0047abf3                                                 XREF[1]:     0047abe7(j)  
    //                              Pnl_scbr.cpp:248 (6)
    //         0047abf3     MOV        dword ptr [ESI + 0x124],this
    //                               LAB_0047abf9                                                 XREF[4]:     0047ab83(j), 0047ab8d(j), 
    //                                                                                                         0047ab95(j), 0047abf1(j)  
    //                              Pnl_scbr.cpp:251 (7)
    //         0047abf9     MOV        this,ESI
    //         0047abfb     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:252 (9)
    //         0047ac00     MOV        EDX,dword ptr [ESI]
    //         0047ac02     PUSH       0x1
    //         0047ac04     MOV        this,ESI
    //         0047ac06     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_scbr.cpp:253 (6)
    //         0047ac09     POP        EDI
    //         0047ac0a     POP        ESI
    //         0047ac0b     POP        EBX
    //         0047ac0c     RET        0x4
}

// Offset: 0x0047AC10
void set_list_len(TScrollBarPanel* this_, long param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollBarPanel::set_list_len(long,long)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall set_list_len(TScrollBarPanel * this, long param_1, l
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0047ac14(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0047ac10(R)  
    //                               ?set_list_len@TScrollBarPanel@@QAEXJJ@Z                      XREF[1]:     calc_draw_info:0047cf9a(c)  
    //                               TScrollBarPanel::set_list_len
    //                              Pnl_scbr.cpp:258 (20)
    //         0047ac10     MOV        EDX,dword ptr [ESP + param_2]
    //         0047ac14     MOV        EAX,dword ptr [ESP + param_1]
    //         0047ac18     PUSH       EDX
    //         0047ac19     MOV        dword ptr [ECX + this->list_len],EAX
    //         0047ac1f     CALL       TScrollBarPanel::set_tab_pos                     void set_tab_pos(TScrollBarPanel * this, long
    //                              Pnl_scbr.cpp:261 (3)
    //         0047ac24     RET        0x8
}

// Offset: 0x0047AC30
void set_buttons(TScrollBarPanel* this_, TShape* param_2, int param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollBarPanel::set_buttons(class TShape *,int,int,int,int)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_buttons(TScrollBarPanel * this, TShape * param_1
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              TShape *          Stack[0x4]:4   param_1                   XREF[1]:     0047ac30(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047ac34(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0047ac3e(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0047ac48(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0047ac52(R)  
    //                               ?set_buttons@TScrollBarPanel@@QAEXPAVTShape@@HHHH@Z          XREF[4]:     create_scrollbar:00469a14(c), 
    //                               TScrollBarPanel::set_buttons                                              create_vert_slider:00469bce(c), 
    //                                                                                                         create_horz_slider:00469d3e(c), 
    //                                                                                                         set_buttons:00474868(c)  
    //                              Pnl_scbr.cpp:267 (4)
    //         0047ac30     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_scbr.cpp:269 (10)
    //         0047ac34     MOV        EDX,dword ptr [ESP + param_2]
    //         0047ac38     MOV        dword ptr [ECX + this->button_pics],EAX
    //                              Pnl_scbr.cpp:270 (10)
    //         0047ac3e     MOV        EAX,dword ptr [ESP + param_3]
    //         0047ac42     MOV        dword ptr [ECX + this->back_frame],EDX
    //                              Pnl_scbr.cpp:271 (10)
    //         0047ac48     MOV        EDX,dword ptr [ESP + param_4]
    //         0047ac4c     MOV        dword ptr [ECX + this->up_frame],EAX
    //                              Pnl_scbr.cpp:272 (16)
    //         0047ac52     MOV        EAX,dword ptr [ESP + param_5]
    //         0047ac56     MOV        dword ptr [ECX + this->down_frame],EDX
    //         0047ac5c     MOV        dword ptr [ECX + this->tab_frame],EAX
    //                              Pnl_scbr.cpp:273 (3)
    //         0047ac62     RET        0x14
}

// Offset: 0x0047AC70
void set_bevel_info(TScrollBarPanel* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollBarPanel::set_bevel_info(int,int,int,int,int,int,int)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_bevel_info(TScrollBarPanel * this, int param_1, 
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ac70(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047ac74(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0047ac7e(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0047ac88(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0047ac92(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0047ac9c(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     0047aca6(R)  
    //                               ?set_bevel_info@TScrollBarPanel@@QAEXHHHHHHH@Z               XREF[5]:     create_scrollbar:00469a5d(c), 
    //                               TScrollBarPanel::set_bevel_info                                           create_vert_slider:00469c18(c), 
    //                                                                                                         create_horz_slider:00469d88(c), 
    //                                                                                                         set_bevel_info:0047477e(c), 
    //                                                                                                         TRIBE_Screen_Game:0049517d(c)  
    //                              Pnl_scbr.cpp:279 (4)
    //         0047ac70     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_scbr.cpp:281 (10)
    //         0047ac74     MOV        DL,byte ptr [ESP + param_2]
    //         0047ac78     MOV        dword ptr [ECX + this->bevel_type],EAX
    //                              Pnl_scbr.cpp:282 (10)
    //         0047ac7e     MOV        AL,byte ptr [ESP + param_3]
    //         0047ac82     MOV        byte ptr [ECX + this->bevel_color1],DL
    //                              Pnl_scbr.cpp:283 (10)
    //         0047ac88     MOV        DL,byte ptr [ESP + param_4]
    //         0047ac8c     MOV        byte ptr [ECX + this->bevel_color2],AL
    //                              Pnl_scbr.cpp:284 (10)
    //         0047ac92     MOV        AL,byte ptr [ESP + param_5]
    //         0047ac96     MOV        byte ptr [ECX + this->bevel_color3],DL
    //                              Pnl_scbr.cpp:285 (10)
    //         0047ac9c     MOV        DL,byte ptr [ESP + param_6]
    //         0047aca0     MOV        byte ptr [ECX + this->bevel_color4],AL
    //                              Pnl_scbr.cpp:286 (16)
    //         0047aca6     MOV        AL,byte ptr [ESP + param_7]
    //         0047acaa     MOV        byte ptr [ECX + this->bevel_color5],DL
    //         0047acb0     MOV        byte ptr [ECX + this->bevel_color6],AL
    //                              Pnl_scbr.cpp:287 (3)
    //         0047acb6     RET        0x1c
}

// Offset: 0x0047ACC0
long THorizontalSliderPanel::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TScrollBarPanel::handle_idle(void)                                    *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TScrollBarPanel * this)
    //              long              EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //                               ?handle_idle@TScrollBarPanel@@UAEJXZ                         XREF[3]:     0057187c(*), 00571a84(*), 
    //                               TScrollBarPanel::handle_idle                                              00571b64(*)  
    //                              Pnl_scbr.cpp:292 (4)
    //         0047acc0     PUSH       EBX
    //         0047acc1     PUSH       ESI
    //         0047acc2     MOV        ESI,this
    //                              Pnl_scbr.cpp:294 (22)
    //         0047acc4     XOR        EAX,EAX
    //         0047acc6     MOV        AL,byte ptr [ESI + 0x154]
    //         0047accc     DEC        EAX
    //         0047accd     JZ         LAB_0047ade2
    //         0047acd3     DEC        EAX
    //         0047acd4     JNZ        switchD_0047ad2c::caseD_3
    //                              Pnl_scbr.cpp:304 (10)
    //         0047acda     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047ace0     XOR        EBX,EBX
    //         0047ace2     CMP        EAX,EBX
    //                              Pnl_scbr.cpp:305 (6)
    //         0047ace4     JZ         switchD_0047ad2c::caseD_3
    //                              Pnl_scbr.cpp:306 (15)
    //         0047acea     PUSH       0x132
    //         0047acef     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047acf4     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Pnl_scbr.cpp:307 (21)
    //         0047acf9     MOV        EDX,dword ptr [ESI + 0x158]
    //         0047acff     MOV        this,EAX
    //         0047ad01     SUB        this,EDX
    //         0047ad03     MOV        EDX,dword ptr [ESI + 0x15c]
    //         0047ad09     ADD        ESP,0x8
    //         0047ad0c     CMP        this,EDX
    //                              Pnl_scbr.cpp:308 (6)
    //         0047ad0e     JC         switchD_0047ad2c::caseD_3
    //                              Pnl_scbr.cpp:309 (6)
    //         0047ad14     MOV        dword ptr [ESI + 0x158],EAX
    //                              Pnl_scbr.cpp:310 (25)
    //         0047ad1a     XOR        EAX,EAX
    //         0047ad1c     MOV        AL,byte ptr [ESI + 0x144]
    //         0047ad22     DEC        EAX
    //         0047ad23     CMP        EAX,0x4
    //         0047ad26     JA         switchD_0047ad2c::caseD_3
    //                               switchD_0047ad2c::switchD
    //         0047ad2c     JMP        dword ptr [EAX*0x4 + switchD_0047ad2c::switchd   = 0047ad33
    //                               switchD_0047ad2c::caseD_1                                    XREF[2]:     0047ad2c(j), 0047ae24(*)  
    //                              Pnl_scbr.cpp:312 (9)
    //         0047ad33     PUSH       EBX
    //         0047ad34     PUSH       EBX
    //         0047ad35     MOV        this,ESI
    //         0047ad37     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:339 (2)
    //         0047ad3c     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047ad3e     POP        ESI
    //         0047ad3f     POP        EBX
    //         0047ad40     RET
    //                               switchD_0047ad2c::caseD_2                                    XREF[2]:     0047ad2c(j), 0047ae28(*)  
    //                              Pnl_scbr.cpp:315 (10)
    //         0047ad41     PUSH       EBX
    //         0047ad42     PUSH       0x1
    //         0047ad44     MOV        this,ESI
    //         0047ad46     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:339 (2)
    //         0047ad4b     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047ad4d     POP        ESI
    //         0047ad4e     POP        EBX
    //         0047ad4f     RET
    //                               switchD_0047ad2c::caseD_4                                    XREF[2]:     0047ad2c(j), 0047ae30(*)  
    //                              Pnl_scbr.cpp:318 (32)
    //         0047ad50     MOV        EAX,dword ptr [ESI + 0x150]
    //         0047ad56     MOV        this,dword ptr [ESI + 0x14c]
    //         0047ad5c     LEA        EDX,[ESI + 0x194]
    //         0047ad62     PUSH       EDX
    //         0047ad63     PUSH       EAX
    //         0047ad64     PUSH       this
    //         0047ad65     MOV        this,ESI
    //         0047ad67     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047ad6c     TEST       EAX,EAX
    //         0047ad6e     JNZ        LAB_0047ad8a
    //                              Pnl_scbr.cpp:321 (21)
    //         0047ad70     MOV        EDX,dword ptr [ESI]
    //         0047ad72     PUSH       0x1
    //         0047ad74     MOV        this,ESI
    //         0047ad76     MOV        dword ptr [ESI + 0x148],EBX
    //         0047ad7c     MOV        byte ptr [ESI + 0x154],BL
    //         0047ad82     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_scbr.cpp:339 (2)
    //         0047ad85     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047ad87     POP        ESI
    //         0047ad88     POP        EBX
    //         0047ad89     RET
    //                               LAB_0047ad8a                                                 XREF[1]:     0047ad6e(j)  
    //                              Pnl_scbr.cpp:324 (10)
    //         0047ad8a     PUSH       EBX
    //         0047ad8b     PUSH       0x2
    //         0047ad8d     MOV        this,ESI
    //         0047ad8f     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:339 (2)
    //         0047ad94     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047ad96     POP        ESI
    //         0047ad97     POP        EBX
    //         0047ad98     RET
    //                               switchD_0047ad2c::caseD_5                                    XREF[2]:     0047ad2c(j), 0047ae34(*)  
    //                              Pnl_scbr.cpp:327 (32)
    //         0047ad99     MOV        this,dword ptr [ESI + 0x150]
    //         0047ad9f     MOV        EDX,dword ptr [ESI + 0x14c]
    //         0047ada5     LEA        EAX,[ESI + 0x1a4]
    //         0047adab     PUSH       EAX
    //         0047adac     PUSH       this
    //         0047adad     PUSH       EDX
    //         0047adae     MOV        this,ESI
    //         0047adb0     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047adb5     TEST       EAX,EAX
    //         0047adb7     JNZ        LAB_0047add3
    //                              Pnl_scbr.cpp:330 (21)
    //         0047adb9     MOV        EAX,dword ptr [ESI]
    //         0047adbb     PUSH       0x1
    //         0047adbd     MOV        this,ESI
    //         0047adbf     MOV        dword ptr [ESI + 0x148],EBX
    //         0047adc5     MOV        byte ptr [ESI + 0x154],BL
    //         0047adcb     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_scbr.cpp:339 (2)
    //         0047adce     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047add0     POP        ESI
    //         0047add1     POP        EBX
    //         0047add2     RET
    //                               LAB_0047add3                                                 XREF[1]:     0047adb7(j)  
    //                              Pnl_scbr.cpp:333 (10)
    //         0047add3     PUSH       EBX
    //         0047add4     PUSH       0x3
    //         0047add6     MOV        this,ESI
    //         0047add8     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:339 (2)
    //         0047addd     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:340 (3)
    //         0047addf     POP        ESI
    //         0047ade0     POP        EBX
    //         0047ade1     RET
    //                               LAB_0047ade2                                                 XREF[1]:     0047accd(j)  
    //                              Pnl_scbr.cpp:296 (15)
    //         0047ade2     PUSH       0x128
    //         0047ade7     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047adec     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Pnl_scbr.cpp:297 (21)
    //         0047adf1     MOV        EBX,dword ptr [ESI + 0x158]
    //         0047adf7     MOV        EDX,dword ptr [ESI + 0x160]
    //         0047adfd     MOV        this,EAX
    //         0047adff     ADD        ESP,0x8
    //         0047ae02     SUB        this,EBX
    //         0047ae04     CMP        this,EDX
    //                              Pnl_scbr.cpp:298 (2)
    //         0047ae06     JC         switchD_0047ad2c::caseD_3
    //                              Pnl_scbr.cpp:300 (21)
    //         0047ae08     MOV        this,dword ptr [ESI + 0x15c]
    //         0047ae0e     MOV        byte ptr [ESI + 0x154],0x2
    //         0047ae15     SUB        EAX,this
    //         0047ae17     MOV        dword ptr [ESI + 0x158],EAX
    //                               switchD_0047ad2c::caseD_3                                    XREF[7]:     0047acd4(j), 0047ace4(j), 
    //                                                                                                         0047ad0e(j), 0047ad26(j), 
    //                                                                                                         0047ad2c(j), 0047ae06(j), 
    //                                                                                                         0047ae2c(*)  
    //                              Pnl_scbr.cpp:340 (27)
    //         0047ae1d     POP        ESI
    //         0047ae1e     XOR        EAX,EAX
    //         0047ae20     POP        EBX
    //         0047ae21     RET
}

// Offset: 0x0047AE22
undefined FUN_0047ae22() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0047ae22()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0047ae22
    //         0047ae22     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0047ad2c::switchdataD_0047ae24                       XREF[1]:     handle_idle:0047ad2c(*)  
}

// Offset: 0x0047AE40
long THorizontalSliderPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TScrollBarPanel::mouse_left_down_action(long,long,int,int)            *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_down_action(TScrollBarPanel * this, long 
    //              long              EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0047ae4f(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0047ae4b(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_down_action@TScrollBarPanel@@UAEJJJHH@Z          XREF[3]:     005718b4(*), 00571abc(*), 
    //                               TScrollBarPanel::mouse_left_down_action                                   00571b9c(*)  
    //                              Pnl_scbr.cpp:346 (6)
    //         0047ae40     PUSH       EBX
    //         0047ae41     PUSH       EBP
    //         0047ae42     PUSH       ESI
    //         0047ae43     PUSH       EDI
    //         0047ae44     MOV        ESI,this
    //                              Pnl_scbr.cpp:347 (5)
    //         0047ae46     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                              Pnl_scbr.cpp:349 (33)
    //         0047ae4b     MOV        EDI,dword ptr [ESP + param_2]
    //         0047ae4f     MOV        EBP,dword ptr [ESP + param_1]
    //         0047ae53     LEA        EAX,[ESI + 0x164]
    //         0047ae59     MOV        this,ESI
    //         0047ae5b     PUSH       EAX
    //         0047ae5c     PUSH       EDI
    //         0047ae5d     PUSH       EBP
    //         0047ae5e     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047ae63     TEST       EAX,EAX
    //         0047ae65     MOV        EBX,0x1
    //         0047ae6a     JZ         LAB_0047ae88
    //                              Pnl_scbr.cpp:352 (23)
    //         0047ae6c     PUSH       0x0
    //         0047ae6e     PUSH       0x0
    //         0047ae70     MOV        this,ESI
    //         0047ae72     MOV        byte ptr [ESI + 0x144],BL
    //         0047ae78     MOV        dword ptr [ESI + 0x148],EBX
    //         0047ae7e     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:354 (25)
    //         0047ae83     JMP        LAB_0047af64
    //                               LAB_0047ae88                                                 XREF[1]:     0047ae6a(j)  
    //         0047ae88     LEA        this,[ESI + 0x174]
    //         0047ae8e     PUSH       this
    //         0047ae8f     PUSH       EDI
    //         0047ae90     PUSH       EBP
    //         0047ae91     MOV        this,ESI
    //         0047ae93     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047ae98     TEST       EAX,EAX
    //         0047ae9a     JZ         LAB_0047aeb8
    //                              Pnl_scbr.cpp:357 (23)
    //         0047ae9c     PUSH       0x0
    //         0047ae9e     PUSH       EBX
    //         0047ae9f     MOV        this,ESI
    //         0047aea1     MOV        byte ptr [ESI + 0x144],0x2
    //         0047aea8     MOV        dword ptr [ESI + 0x148],EBX
    //         0047aeae     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:359 (25)
    //         0047aeb3     JMP        LAB_0047af64
    //                               LAB_0047aeb8                                                 XREF[1]:     0047ae9a(j)  
    //         0047aeb8     LEA        EDX,[ESI + 0x184]
    //         0047aebe     MOV        this,ESI
    //         0047aec0     PUSH       EDX
    //         0047aec1     PUSH       EDI
    //         0047aec2     PUSH       EBP
    //         0047aec3     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047aec8     TEST       EAX,EAX
    //         0047aeca     JZ         LAB_0047af01
    //                              Pnl_scbr.cpp:360 (6)
    //         0047aecc     MOV        EAX,dword ptr [ESI + 0x1b4]
    //                              Pnl_scbr.cpp:361 (11)
    //         0047aed2     MOV        byte ptr [ESI + 0x144],0x3
    //         0047aed9     CMP        EAX,EBX
    //         0047aedb     JNZ        LAB_0047aeef
    //                              Pnl_scbr.cpp:362 (16)
    //         0047aedd     MOV        this,dword ptr [ESI + 0x134]
    //         0047aee3     MOV        EAX,EBP
    //         0047aee5     SUB        EAX,this
    //         0047aee7     MOV        dword ptr [ESI + 0x140],EAX
    //                              Pnl_scbr.cpp:364 (2)
    //         0047aeed     JMP        LAB_0047af64
    //                               LAB_0047aeef                                                 XREF[1]:     0047aedb(j)  
    //                              Pnl_scbr.cpp:366 (16)
    //         0047aeef     MOV        EAX,dword ptr [ESI + 0x124]
    //         0047aef5     MOV        this,EDI
    //         0047aef7     SUB        this,EAX
    //         0047aef9     MOV        dword ptr [ESI + 0x130],this
    //                              Pnl_scbr.cpp:369 (22)
    //         0047aeff     JMP        LAB_0047af64
    //                               LAB_0047af01                                                 XREF[1]:     0047aeca(j)  
    //         0047af01     LEA        EDX,[ESI + 0x194]
    //         0047af07     MOV        this,ESI
    //         0047af09     PUSH       EDX
    //         0047af0a     PUSH       EDI
    //         0047af0b     PUSH       EBP
    //         0047af0c     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047af11     TEST       EAX,EAX
    //         0047af13     JZ         LAB_0047af2f
    //                              Pnl_scbr.cpp:372 (24)
    //         0047af15     PUSH       0x0
    //         0047af17     PUSH       0x2
    //         0047af19     MOV        this,ESI
    //         0047af1b     MOV        byte ptr [ESI + 0x144],0x4
    //         0047af22     MOV        dword ptr [ESI + 0x148],EBX
    //         0047af28     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:374 (22)
    //         0047af2d     JMP        LAB_0047af64
    //                               LAB_0047af2f                                                 XREF[1]:     0047af13(j)  
    //         0047af2f     LEA        EAX,[ESI + 0x1a4]
    //         0047af35     MOV        this,ESI
    //         0047af37     PUSH       EAX
    //         0047af38     PUSH       EDI
    //         0047af39     PUSH       EBP
    //         0047af3a     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047af3f     TEST       EAX,EAX
    //         0047af41     JZ         LAB_0047af5d
    //                              Pnl_scbr.cpp:377 (24)
    //         0047af43     PUSH       0x0
    //         0047af45     PUSH       0x3
    //         0047af47     MOV        this,ESI
    //         0047af49     MOV        byte ptr [ESI + 0x144],0x5
    //         0047af50     MOV        dword ptr [ESI + 0x148],EBX
    //         0047af56     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:379 (2)
    //         0047af5b     JMP        LAB_0047af64
    //                               LAB_0047af5d                                                 XREF[1]:     0047af41(j)  
    //                              Pnl_scbr.cpp:380 (7)
    //         0047af5d     MOV        byte ptr [ESI + 0x144],0x0
    //                               LAB_0047af64                                                 XREF[6]:     0047ae83(j), 0047aeb3(j), 
    //                                                                                                         0047aeed(j), 0047aeff(j), 
    //                                                                                                         0047af2d(j), 0047af5b(j)  
    //                              Pnl_scbr.cpp:382 (10)
    //         0047af64     MOV        AL,byte ptr [ESI + 0x144]
    //         0047af6a     TEST       AL,AL
    //         0047af6c     JZ         LAB_0047afbe
    //                              Pnl_scbr.cpp:383 (24)
    //         0047af6e     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0047af74     TEST       EAX,EAX
    //         0047af76     JZ         LAB_0047af8c
    //         0047af78     MOV        this,dword ptr [EAX + 0x74]
    //         0047af7b     TEST       this,this
    //         0047af7d     JZ         LAB_0047af8c
    //         0047af7f     MOV        this,dword ptr [EAX + 0x40]
    //         0047af82     TEST       this,this
    //         0047af84     JZ         LAB_0047af8c
    //                              Pnl_scbr.cpp:384 (6)
    //         0047af86     PUSH       EAX
    //         0047af87     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_0047af8c                                                 XREF[3]:     0047af76(j), 0047af7d(j), 
    //                                                                                                         0047af84(j)  
    //                              Pnl_scbr.cpp:389 (33)
    //         0047af8c     PUSH       0x185
    //         0047af91     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047af96     MOV        dword ptr [ESI + 0x14c],EBP
    //         0047af9c     MOV        dword ptr [ESI + 0x150],EDI
    //         0047afa2     MOV        byte ptr [ESI + 0x154],BL
    //         0047afa8     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Pnl_scbr.cpp:390 (17)
    //         0047afad     MOV        EDX,dword ptr [ESI]
    //         0047afaf     ADD        ESP,0x8
    //         0047afb2     MOV        this,ESI
    //         0047afb4     MOV        dword ptr [ESI + 0x158],EAX
    //         0047afba     PUSH       EBX
    //         0047afbb     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0047afbe                                                 XREF[1]:     0047af6c(j)  
    //                              Pnl_scbr.cpp:394 (9)
    //         0047afbe     POP        EDI
    //         0047afbf     POP        ESI
    //         0047afc0     POP        EBP
    //         0047afc1     XOR        EAX,EAX
    //         0047afc3     POP        EBX
    //         0047afc4     RET        0x10
}

// Offset: 0x0047AFD0
long THorizontalSliderPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TScrollBarPanel::mouse_left_move_action(long,long,int,int)            *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_move_action(TScrollBarPanel * this, long 
    //              long              EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0047afd5(R), 0047b2db(R), 0047b2e3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[7]:     0047aff5(R), 0047b04f(R), 0047b0aa(R), 0047b133(R), 
    //                                                                                     0047b2a3(R), 0047b2fb(R), 0047b396(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_move_action@TScrollBarPanel@@UAEJJJHH@Z          XREF[3]:     005718bc(*), 00571ac4(*), 
    //                               TScrollBarPanel::mouse_left_move_action                                   00571ba4(*)  
    //                              Pnl_scbr.cpp:400 (5)
    //         0047afd0     PUSH       EBX
    //         0047afd1     PUSH       EBP
    //         0047afd2     PUSH       ESI
    //         0047afd3     MOV        ESI,this
    //                              Pnl_scbr.cpp:404 (32)
    //         0047afd5     MOV        EBP,dword ptr [ESP + param_1]
    //         0047afd9     XOR        EAX,EAX
    //         0047afdb     MOV        AL,byte ptr [ESI + 0x144]
    //         0047afe1     XOR        EBX,EBX
    //         0047afe3     DEC        EAX
    //         0047afe4     PUSH       EDI
    //         0047afe5     CMP        EAX,0x4
    //         0047afe8     JA         switchD_0047afee::default
    //                               switchD_0047afee::switchD
    //         0047afee     JMP        dword ptr [EAX*0x4 + switchD_0047afee::switchd   = 0047aff5
    //                               switchD_0047afee::caseD_1                                    XREF[2]:     0047afee(j), 0047b3b0(*)  
    //                              Pnl_scbr.cpp:406 (22)
    //         0047aff5     MOV        this,dword ptr [ESP + param_2]
    //         0047aff9     LEA        EAX,[ESI + 0x164]
    //         0047afff     PUSH       EAX
    //         0047b000     PUSH       this
    //         0047b001     PUSH       EBP
    //         0047b002     MOV        this,ESI
    //         0047b004     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047b009     TEST       EAX,EAX
    //                              Pnl_scbr.cpp:407 (20)
    //         0047b00b     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b011     JZ         LAB_0047b111
    //         0047b017     CMP        EAX,EBX
    //         0047b019     JNZ        switchD_0047afee::default
    //                              Pnl_scbr.cpp:410 (41)
    //         0047b01f     PUSH       0x19a
    //         0047b024     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047b029     MOV        dword ptr [ESI + 0x148],0x1
    //         0047b033     MOV        byte ptr [ESI + 0x154],0x2
    //         0047b03a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0047b03f     ADD        ESP,0x8
    //         0047b042     MOV        dword ptr [ESI + 0x158],EAX
    //                              Pnl_scbr.cpp:411 (2)
    //         0047b048     PUSH       EBX
    //         0047b049     PUSH       EBX
    //                              Pnl_scbr.cpp:415 (5)
    //         0047b04a     JMP        LAB_0047b0fc
    //                               switchD_0047afee::caseD_2                                    XREF[2]:     0047afee(j), 0047b3b4(*)  
    //                              Pnl_scbr.cpp:425 (22)
    //         0047b04f     MOV        EDX,dword ptr [ESP + param_2]
    //         0047b053     LEA        this,[ESI + 0x174]
    //         0047b059     PUSH       this
    //         0047b05a     PUSH       EDX
    //         0047b05b     PUSH       EBP
    //         0047b05c     MOV        this,ESI
    //         0047b05e     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047b063     TEST       EAX,EAX
    //                              Pnl_scbr.cpp:426 (20)
    //         0047b065     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b06b     JZ         LAB_0047b19a
    //         0047b071     CMP        EAX,EBX
    //         0047b073     JNZ        switchD_0047afee::default
    //                              Pnl_scbr.cpp:429 (41)
    //         0047b079     PUSH       0x1ad
    //         0047b07e     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047b083     MOV        dword ptr [ESI + 0x148],0x1
    //         0047b08d     MOV        byte ptr [ESI + 0x154],0x2
    //         0047b094     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0047b099     ADD        ESP,0x8
    //         0047b09c     MOV        dword ptr [ESI + 0x158],EAX
    //                              Pnl_scbr.cpp:430 (3)
    //         0047b0a2     PUSH       EBX
    //         0047b0a3     PUSH       0x1
    //                              Pnl_scbr.cpp:434 (5)
    //         0047b0a5     JMP        LAB_0047b185
    //                               switchD_0047afee::caseD_4                                    XREF[2]:     0047afee(j), 0047b3bc(*)  
    //                              Pnl_scbr.cpp:444 (22)
    //         0047b0aa     MOV        this,dword ptr [ESP + param_2]
    //         0047b0ae     LEA        EAX,[ESI + 0x194]
    //         0047b0b4     PUSH       EAX
    //         0047b0b5     PUSH       this
    //         0047b0b6     PUSH       EBP
    //         0047b0b7     MOV        this,ESI
    //         0047b0b9     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047b0be     TEST       EAX,EAX
    //                              Pnl_scbr.cpp:445 (16)
    //         0047b0c0     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b0c6     JZ         LAB_0047b111
    //         0047b0c8     CMP        EAX,EBX
    //         0047b0ca     JNZ        switchD_0047afee::default
    //                              Pnl_scbr.cpp:448 (41)
    //         0047b0d0     PUSH       0x1c0
    //         0047b0d5     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047b0da     MOV        dword ptr [ESI + 0x148],0x1
    //         0047b0e4     MOV        byte ptr [ESI + 0x154],0x2
    //         0047b0eb     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0047b0f0     ADD        ESP,0x8
    //         0047b0f3     MOV        dword ptr [ESI + 0x158],EAX
    //                              Pnl_scbr.cpp:449 (10)
    //         0047b0f9     PUSH       EBX
    //         0047b0fa     PUSH       0x2
    //                               LAB_0047b0fc                                                 XREF[1]:     0047b04a(j)  
    //         0047b0fc     MOV        this,ESI
    //         0047b0fe     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:450 (9)
    //         0047b103     MOV        EDX,dword ptr [ESI]
    //         0047b105     PUSH       0x1
    //         0047b107     MOV        this,ESI
    //         0047b109     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_scbr.cpp:453 (5)
    //         0047b10c     JMP        switchD_0047afee::default
    //                               LAB_0047b111                                                 XREF[2]:     0047b011(j), 0047b0c6(j)  
    //                              Pnl_scbr.cpp:454 (8)
    //         0047b111     CMP        EAX,EBX
    //         0047b113     JZ         switchD_0047afee::default
    //                              Pnl_scbr.cpp:457 (21)
    //         0047b119     MOV        EAX,dword ptr [ESI]
    //         0047b11b     PUSH       0x1
    //         0047b11d     MOV        this,ESI
    //         0047b11f     MOV        dword ptr [ESI + 0x148],EBX
    //         0047b125     MOV        byte ptr [ESI + 0x154],BL
    //         0047b12b     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_scbr.cpp:460 (5)
    //         0047b12e     JMP        switchD_0047afee::default
    //                               switchD_0047afee::caseD_5                                    XREF[2]:     0047afee(j), 0047b3c0(*)  
    //                              Pnl_scbr.cpp:463 (22)
    //         0047b133     MOV        EDX,dword ptr [ESP + param_2]
    //         0047b137     LEA        this,[ESI + 0x1a4]
    //         0047b13d     PUSH       this
    //         0047b13e     PUSH       EDX
    //         0047b13f     PUSH       EBP
    //         0047b140     MOV        this,ESI
    //         0047b142     CALL       TPanel::is_inside_rect                           int is_inside_rect(TPanel * this, long param_
    //         0047b147     TEST       EAX,EAX
    //                              Pnl_scbr.cpp:464 (16)
    //         0047b149     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b14f     JZ         LAB_0047b19a
    //         0047b151     CMP        EAX,EBX
    //         0047b153     JNZ        switchD_0047afee::default
    //                              Pnl_scbr.cpp:467 (41)
    //         0047b159     PUSH       0x1d3
    //         0047b15e     PUSH       s_C:\msdev\work\age1_x1\Pnl_scbr.c               = "C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp"
    //         0047b163     MOV        dword ptr [ESI + 0x148],0x1
    //         0047b16d     MOV        byte ptr [ESI + 0x154],0x2
    //         0047b174     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0047b179     ADD        ESP,0x8
    //         0047b17c     MOV        dword ptr [ESI + 0x158],EAX
    //                              Pnl_scbr.cpp:468 (10)
    //         0047b182     PUSH       EBX
    //         0047b183     PUSH       0x3
    //                               LAB_0047b185                                                 XREF[1]:     0047b0a5(j)  
    //         0047b185     MOV        this,ESI
    //         0047b187     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                              Pnl_scbr.cpp:469 (9)
    //         0047b18c     MOV        EAX,dword ptr [ESI]
    //         0047b18e     PUSH       0x1
    //         0047b190     MOV        this,ESI
    //         0047b192     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_scbr.cpp:472 (5)
    //         0047b195     JMP        switchD_0047afee::default
    //                               LAB_0047b19a                                                 XREF[2]:     0047b06b(j), 0047b14f(j)  
    //                              Pnl_scbr.cpp:473 (8)
    //         0047b19a     CMP        EAX,EBX
    //         0047b19c     JZ         switchD_0047afee::default
    //                              Pnl_scbr.cpp:476 (21)
    //         0047b1a2     MOV        EDX,dword ptr [ESI]
    //         0047b1a4     PUSH       0x1
    //         0047b1a6     MOV        this,ESI
    //         0047b1a8     MOV        dword ptr [ESI + 0x148],EBX
    //         0047b1ae     MOV        byte ptr [ESI + 0x154],BL
    //         0047b1b4     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_scbr.cpp:479 (5)
    //         0047b1b7     JMP        switchD_0047afee::default
    //                               switchD_0047afee::caseD_3                                    XREF[2]:     0047afee(j), 0047b3b8(*)  
    //                              Pnl_scbr.cpp:482 (13)
    //         0047b1bc     CMP        dword ptr [ESI + 0x1b4],0x1
    //         0047b1c3     JNZ        LAB_0047b2a3
    //                              Pnl_scbr.cpp:483 (10)
    //         0047b1c9     MOV        EDX,dword ptr [ESI + 0x14c]
    //         0047b1cf     MOV        EAX,EBP
    //         0047b1d1     SUB        EAX,EDX
    //                              Pnl_scbr.cpp:484 (10)
    //         0047b1d3     CMP        EAX,EBX
    //         0047b1d5     JLE        LAB_0047b1dd
    //         0047b1d7     MOV        this,dword ptr [ESI + 0x138]
    //                               LAB_0047b1dd                                                 XREF[1]:     0047b1d5(j)  
    //                              Pnl_scbr.cpp:486 (30)
    //         0047b1dd     MOV        this,dword ptr [ESI + 0x134]
    //         0047b1e3     MOV        EDX,dword ptr [ESI + 0x138]
    //         0047b1e9     CMP        this,EDX
    //         0047b1eb     JNZ        LAB_0047b1fd
    //         0047b1ed     CMP        EAX,EBX
    //         0047b1ef     JLE        LAB_0047b1fd
    //         0047b1f1     MOV        EDI,dword ptr [ESI + 0x140]
    //         0047b1f7     ADD        EDI,this
    //         0047b1f9     CMP        EBP,EDI
    //                              Pnl_scbr.cpp:488 (26)
    //         0047b1fb     JL         LAB_0047b215
    //                               LAB_0047b1fd                                                 XREF[2]:     0047b1eb(j), 0047b1ef(j)  
    //         0047b1fd     CMP        this,dword ptr [ESI + 0x13c]
    //         0047b203     JNZ        LAB_0047b217
    //         0047b205     CMP        EAX,EBX
    //         0047b207     JGE        LAB_0047b219
    //         0047b209     MOV        EDI,dword ptr [ESI + 0x140]
    //         0047b20f     ADD        EDI,this
    //         0047b211     CMP        EBP,EDI
    //         0047b213     JL         LAB_0047b217
    //                               LAB_0047b215                                                 XREF[1]:     0047b1fb(j)  
    //                              Pnl_scbr.cpp:489 (2)
    //         0047b215     XOR        EAX,EAX
    //                               LAB_0047b217                                                 XREF[2]:     0047b203(j), 0047b213(j)  
    //                              Pnl_scbr.cpp:490 (8)
    //         0047b217     CMP        EAX,EBX
    //                               LAB_0047b219                                                 XREF[1]:     0047b207(j)  
    //         0047b219     JZ         switchD_0047afee::default
    //                              Pnl_scbr.cpp:491 (16)
    //         0047b21f     MOV        EDI,dword ptr [ESI + 0x134]
    //         0047b225     ADD        EDI,EAX
    //         0047b227     MOV        EAX,EDI
    //         0047b229     MOV        dword ptr [ESI + 0x134],EDI
    //                              Pnl_scbr.cpp:492 (4)
    //         0047b22f     CMP        EAX,EDX
    //         0047b231     JGE        LAB_0047b23b
    //                              Pnl_scbr.cpp:493 (6)
    //         0047b233     MOV        dword ptr [ESI + 0x134],EDX
    //                              Pnl_scbr.cpp:494 (12)
    //         0047b239     JMP        LAB_0047b24b
    //                               LAB_0047b23b                                                 XREF[1]:     0047b231(j)  
    //         0047b23b     MOV        this,dword ptr [ESI + 0x13c]
    //         0047b241     CMP        EAX,this
    //         0047b243     JLE        LAB_0047b24b
    //                              Pnl_scbr.cpp:495 (6)
    //         0047b245     MOV        dword ptr [ESI + 0x134],this
    //                               LAB_0047b24b                                                 XREF[2]:     0047b239(j), 0047b243(j)  
    //                              Pnl_scbr.cpp:496 (7)
    //         0047b24b     MOV        this,ESI
    //         0047b24d     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:497 (9)
    //         0047b252     MOV        EAX,dword ptr [ESI]
    //         0047b254     PUSH       0x1
    //         0047b256     MOV        this,ESI
    //         0047b258     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_scbr.cpp:498 (16)
    //         0047b25b     MOV        EDX,dword ptr [ESI + 0x138]
    //         0047b261     MOV        this,dword ptr [ESI + 0x13c]
    //         0047b267     CMP        EDX,this
    //         0047b269     JNZ        LAB_0047b272
    //                              Pnl_scbr.cpp:499 (2)
    //         0047b26b     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:500 (5)
    //         0047b26d     JMP        LAB_0047b384
    //                               LAB_0047b272                                                 XREF[1]:     0047b269(j)  
    //                              Pnl_scbr.cpp:501 (22)
    //         0047b272     MOV        EAX,dword ptr [ESI + 0x134]
    //         0047b278     MOV        EDI,dword ptr [ESI + 0xf8]
    //         0047b27e     SUB        EAX,EDX
    //         0047b280     SUB        this,EDX
    //         0047b282     IMUL       EAX,EDI
    //         0047b285     CDQ
    //         0047b286     IDIV       this
    //                              Pnl_scbr.cpp:502 (4)
    //         0047b288     CMP        EAX,EBX
    //         0047b28a     JGE        LAB_0047b293
    //                              Pnl_scbr.cpp:503 (2)
    //         0047b28c     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:504 (16)
    //         0047b28e     JMP        LAB_0047b384
    //                               LAB_0047b293                                                 XREF[1]:     0047b28a(j)  
    //         0047b293     LEA        this,[EDI + -0x1]
    //         0047b296     CMP        EAX,this
    //         0047b298     JLE        LAB_0047b384
    //                              Pnl_scbr.cpp:510 (5)
    //         0047b29e     JMP        LAB_0047b382
    //                               LAB_0047b2a3                                                 XREF[1]:     0047b1c3(j)  
    //                              Pnl_scbr.cpp:511 (14)
    //         0047b2a3     MOV        EDI,dword ptr [ESP + param_2]
    //         0047b2a7     MOV        EDX,dword ptr [ESI + 0x150]
    //         0047b2ad     MOV        EAX,EDI
    //         0047b2af     SUB        EAX,EDX
    //                              Pnl_scbr.cpp:512 (10)
    //         0047b2b1     CMP        EAX,EBX
    //         0047b2b3     JLE        LAB_0047b2bb
    //         0047b2b5     MOV        this,dword ptr [ESI + 0x128]
    //                               LAB_0047b2bb                                                 XREF[1]:     0047b2b3(j)  
    //                              Pnl_scbr.cpp:514 (32)
    //         0047b2bb     MOV        this,dword ptr [ESI + 0x124]
    //         0047b2c1     MOV        EDX,dword ptr [ESI + 0x128]
    //         0047b2c7     CMP        this,EDX
    //         0047b2c9     JNZ        LAB_0047b2e7
    //         0047b2cb     CMP        EAX,EBX
    //         0047b2cd     JLE        LAB_0047b2e7
    //         0047b2cf     MOV        EBP,dword ptr [ESI + 0x130]
    //         0047b2d5     ADD        EBP,this
    //         0047b2d7     CMP        EDI,EBP
    //         0047b2d9     JGE        LAB_0047b2e3
    //                              Pnl_scbr.cpp:516 (40)
    //         0047b2db     MOV        EBP,dword ptr [ESP + param_1]
    //         0047b2df     XOR        EAX,EAX
    //         0047b2e1     JMP        LAB_0047b305
    //                               LAB_0047b2e3                                                 XREF[1]:     0047b2d9(j)  
    //         0047b2e3     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_0047b2e7                                                 XREF[2]:     0047b2c9(j), 0047b2cd(j)  
    //         0047b2e7     CMP        this,dword ptr [ESI + 0x12c]
    //         0047b2ed     JNZ        LAB_0047b305
    //         0047b2ef     CMP        EAX,EBX
    //         0047b2f1     JGE        LAB_0047b307
    //         0047b2f3     MOV        EDI,dword ptr [ESI + 0x130]
    //         0047b2f9     ADD        EDI,this
    //         0047b2fb     MOV        this,dword ptr [ESP + param_2]
    //         0047b2ff     CMP        this,EDI
    //         0047b301     JL         LAB_0047b305
    //                              Pnl_scbr.cpp:517 (2)
    //         0047b303     XOR        EAX,EAX
    //                               LAB_0047b305                                                 XREF[3]:     0047b2e1(j), 0047b2ed(j), 
    //                                                                                                         0047b301(j)  
    //                              Pnl_scbr.cpp:518 (8)
    //         0047b305     CMP        EAX,EBX
    //                               LAB_0047b307                                                 XREF[1]:     0047b2f1(j)  
    //         0047b307     JZ         switchD_0047afee::default
    //                              Pnl_scbr.cpp:519 (16)
    //         0047b30d     MOV        EDI,dword ptr [ESI + 0x124]
    //         0047b313     ADD        EDI,EAX
    //         0047b315     MOV        EAX,EDI
    //         0047b317     MOV        dword ptr [ESI + 0x124],EDI
    //                              Pnl_scbr.cpp:520 (4)
    //         0047b31d     CMP        EAX,EDX
    //         0047b31f     JGE        LAB_0047b329
    //                              Pnl_scbr.cpp:521 (6)
    //         0047b321     MOV        dword ptr [ESI + 0x124],EDX
    //                              Pnl_scbr.cpp:522 (12)
    //         0047b327     JMP        LAB_0047b339
    //                               LAB_0047b329                                                 XREF[1]:     0047b31f(j)  
    //         0047b329     MOV        this,dword ptr [ESI + 0x12c]
    //         0047b32f     CMP        EAX,this
    //         0047b331     JLE        LAB_0047b339
    //                              Pnl_scbr.cpp:523 (6)
    //         0047b333     MOV        dword ptr [ESI + 0x124],this
    //                               LAB_0047b339                                                 XREF[2]:     0047b327(j), 0047b331(j)  
    //                              Pnl_scbr.cpp:524 (7)
    //         0047b339     MOV        this,ESI
    //         0047b33b     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:525 (9)
    //         0047b340     MOV        EDX,dword ptr [ESI]
    //         0047b342     PUSH       0x1
    //         0047b344     MOV        this,ESI
    //         0047b346     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_scbr.cpp:526 (16)
    //         0047b349     MOV        EDX,dword ptr [ESI + 0x128]
    //         0047b34f     MOV        this,dword ptr [ESI + 0x12c]
    //         0047b355     CMP        EDX,this
    //         0047b357     JNZ        LAB_0047b35d
    //                              Pnl_scbr.cpp:527 (2)
    //         0047b359     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:528 (2)
    //         0047b35b     JMP        LAB_0047b384
    //                               LAB_0047b35d                                                 XREF[1]:     0047b357(j)  
    //                              Pnl_scbr.cpp:529 (22)
    //         0047b35d     MOV        EAX,dword ptr [ESI + 0x124]
    //         0047b363     MOV        EDI,dword ptr [ESI + 0xf8]
    //         0047b369     SUB        EAX,EDX
    //         0047b36b     SUB        this,EDX
    //         0047b36d     IMUL       EAX,EDI
    //         0047b370     CDQ
    //         0047b371     IDIV       this
    //                              Pnl_scbr.cpp:530 (4)
    //         0047b373     CMP        EAX,EBX
    //         0047b375     JGE        LAB_0047b37b
    //                              Pnl_scbr.cpp:531 (2)
    //         0047b377     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:532 (9)
    //         0047b379     JMP        LAB_0047b384
    //                               LAB_0047b37b                                                 XREF[1]:     0047b375(j)  
    //         0047b37b     LEA        this,[EDI + -0x1]
    //         0047b37e     CMP        EAX,this
    //         0047b380     JLE        LAB_0047b384
    //                               LAB_0047b382                                                 XREF[1]:     0047b29e(j)  
    //                              Pnl_scbr.cpp:533 (2)
    //         0047b382     MOV        EAX,this
    //                               LAB_0047b384                                                 XREF[6]:     0047b26d(j), 0047b28e(j), 
    //                                                                                                         0047b298(j), 0047b35b(j), 
    //                                                                                                         0047b379(j), 0047b380(j)  
    //                              Pnl_scbr.cpp:535 (10)
    //         0047b384     PUSH       EAX
    //         0047b385     PUSH       offset DAT_fffffff8
    //         0047b387     MOV        this,ESI
    //         0047b389     CALL       TScrollBarPanel::scroll                          void scroll(TScrollBarPanel * this, ActionTyp
    //                               switchD_0047afee::default                                    XREF[13]:    0047afe8(j), 0047b019(j), 
    //                                                                                                         0047b073(j), 0047b0ca(j), 
    //                                                                                                         0047b10c(j), 0047b113(j), 
    //                                                                                                         0047b12e(j), 0047b153(j), 
    //                                                                                                         0047b195(j), 0047b19c(j), 
    //                                                                                                         0047b1b7(j), 0047b219(j), 
    //                                                                                                         0047b307(j)  
    //                              Pnl_scbr.cpp:541 (8)
    //         0047b38e     CMP        byte ptr [ESI + 0x144],BL
    //         0047b394     JZ         LAB_0047b3a6
    //                              Pnl_scbr.cpp:543 (16)
    //         0047b396     MOV        EAX,dword ptr [ESP + param_2]
    //         0047b39a     MOV        dword ptr [ESI + 0x14c],EBP
    //         0047b3a0     MOV        dword ptr [ESI + 0x150],EAX
    //                               LAB_0047b3a6                                                 XREF[1]:     0047b394(j)  
    //                              Pnl_scbr.cpp:547 (30)
    //         0047b3a6     POP        EDI
    //         0047b3a7     POP        ESI
    //         0047b3a8     POP        EBP
    //         0047b3a9     XOR        EAX,EAX
    //         0047b3ab     POP        EBX
    //         0047b3ac     RET        0x10
}

// Offset: 0x0047B3D0
long THorizontalSliderPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TScrollBarPanel::mouse_left_up_action(long,long,int,int)              *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_up_action(TScrollBarPanel * this, long pa
    //              long              EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_up_action@TScrollBarPanel@@UAEJJJHH@Z            XREF[3]:     005718c0(*), 00571ac8(*), 
    //                               TScrollBarPanel::mouse_left_up_action                                     00571ba8(*)  
    //                              Pnl_scbr.cpp:553 (3)
    //         0047b3d0     PUSH       ESI
    //         0047b3d1     MOV        ESI,this
    //                              Pnl_scbr.cpp:581 (7)
    //         0047b3d3     MOV        this,dword ptr [ESI + 0x40]
    //         0047b3d6     TEST       this,this
    //         0047b3d8     JZ         LAB_0047b3ee
    //                              Pnl_scbr.cpp:582 (20)
    //         0047b3da     MOV        EDX,dword ptr [ESI + 0x104]
    //         0047b3e0     MOV        EAX,dword ptr [this->_padding_]
    //         0047b3e2     PUSH       0x0
    //         0047b3e4     PUSH       EDX
    //         0047b3e5     PUSH       0x5
    //         0047b3e7     PUSH       ESI
    //         0047b3e8     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_0047b3ee                                                 XREF[1]:     0047b3d8(j)  
    //                              Pnl_scbr.cpp:584 (7)
    //         0047b3ee     MOV        this,ESI
    //         0047b3f0     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              Pnl_scbr.cpp:588 (33)
    //         0047b3f5     MOV        EAX,dword ptr [ESI]
    //         0047b3f7     PUSH       0x1
    //         0047b3f9     MOV        this,ESI
    //         0047b3fb     MOV        byte ptr [ESI + 0x144],0x0
    //         0047b402     MOV        byte ptr [ESI + 0x154],0x0
    //         0047b409     MOV        dword ptr [ESI + 0x148],0x0
    //         0047b413     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_scbr.cpp:589 (2)
    //         0047b416     XOR        EAX,EAX
    //                              Pnl_scbr.cpp:590 (4)
    //         0047b418     POP        ESI
    //         0047b419     RET        0x10
}

// Offset: 0x0047B420
void scroll(TScrollBarPanel* this_, ActionType param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollBarPanel::scroll(enum TScrollBarPanel::ActionType,long)                *
    //                              *********************************************************************************************************
    //                              void __thiscall scroll(TScrollBarPanel * this, ActionType param_1, l
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              ActionType        Stack[0x4]:4   param_1                   XREF[2]:     0047b437(R), 0047b448(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0047b42e(R), 0047b480(R)  
    //                               ?scroll@TScrollBarPanel@@QAEXW4ActionType@1@J@Z              XREF[11]:    handle_idle:0047ad37(c), 
    //                               TScrollBarPanel::scroll                                                   handle_idle:0047ad46(c), 
    //                                                                                                         handle_idle:0047ad8f(c), 
    //                                                                                                         handle_idle:0047add8(c), 
    //                                                                                                         mouse_left_down_action:0047ae7e(c)
    //                                                                                                         mouse_left_down_action:0047aeae(c)
    //                                                                                                         mouse_left_down_action:0047af28(c)
    //                                                                                                         mouse_left_down_action:0047af56(c)
    //                                                                                                         mouse_left_move_action:0047b0fe(c)
    //                                                                                                         mouse_left_move_action:0047b187(c)
    //                                                                                                         mouse_left_move_action:0047b389(c)
    //                              Pnl_scbr.cpp:596 (4)
    //         0047b420     PUSH       ESI
    //         0047b421     PUSH       EDI
    //         0047b422     MOV        EDI,this
    //                              Pnl_scbr.cpp:599 (10)
    //         0047b424     MOV        this,dword ptr [EDI + 0xf4]
    //         0047b42a     TEST       this,this
    //         0047b42c     JZ         LAB_0047b448
    //                              Pnl_scbr.cpp:600 (14)
    //         0047b42e     MOV        EDX,dword ptr [ESP + param_2]
    //         0047b432     MOV        EAX,dword ptr [this->_padding_]
    //         0047b434     PUSH       0x0
    //         0047b436     PUSH       EDX
    //         0047b437     MOV        EDX,dword ptr [ESP + param_1]
    //         0047b43b     PUSH       EDX
    //                              Pnl_scbr.cpp:640 (7)
    //         0047b43c     PUSH       EDI
    //         0047b43d     CALL       dword ptr [EAX + 0xb4]
    //                              Pnl_scbr.cpp:643 (5)
    //         0047b443     POP        EDI
    //         0047b444     POP        ESI
    //         0047b445     RET        0x8
    //                               LAB_0047b448                                                 XREF[1]:     0047b42c(j)  
    //                              Pnl_scbr.cpp:605 (24)
    //         0047b448     MOV        EAX,dword ptr [ESP + param_1]
    //         0047b44c     MOV        this,dword ptr [EDI + 0x104]
    //         0047b452     CMP        EAX,0x4
    //         0047b455     MOV        ESI,this
    //         0047b457     JA         switchD_0047b459::default
    //                               switchD_0047b459::switchD
    //         0047b459     JMP        dword ptr [EAX*0x4 + switchD_0047b459::switchd   = 0047b460
    //                               switchD_0047b459::caseD_0                                    XREF[2]:     0047b459(j), 0047b4c0(*)  
    //                              Pnl_scbr.cpp:608 (6)
    //         0047b460     SUB        ESI,dword ptr [EDI + 0xfc]
    //                              Pnl_scbr.cpp:609 (2)
    //         0047b466     JMP        LAB_0047b484
    //                               switchD_0047b459::caseD_1                                    XREF[2]:     0047b459(j), 0047b4c4(*)  
    //                              Pnl_scbr.cpp:612 (6)
    //         0047b468     ADD        ESI,dword ptr [EDI + 0xfc]
    //                              Pnl_scbr.cpp:613 (2)
    //         0047b46e     JMP        LAB_0047b484
    //                               switchD_0047b459::caseD_2                                    XREF[2]:     0047b459(j), 0047b4c8(*)  
    //                              Pnl_scbr.cpp:616 (6)
    //         0047b470     SUB        ESI,dword ptr [EDI + 0x100]
    //                              Pnl_scbr.cpp:617 (2)
    //         0047b476     JMP        LAB_0047b484
    //                               switchD_0047b459::caseD_3                                    XREF[2]:     0047b459(j), 0047b4cc(*)  
    //                              Pnl_scbr.cpp:620 (6)
    //         0047b478     ADD        ESI,dword ptr [EDI + 0x100]
    //                              Pnl_scbr.cpp:621 (2)
    //         0047b47e     JMP        LAB_0047b484
    //                               switchD_0047b459::caseD_4                                    XREF[2]:     0047b459(j), 0047b4d0(*)  
    //                              Pnl_scbr.cpp:624 (4)
    //         0047b480     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_0047b484                                                 XREF[4]:     0047b466(j), 0047b46e(j), 
    //                                                                                                         0047b476(j), 0047b47e(j)  
    //                              Pnl_scbr.cpp:631 (4)
    //         0047b484     TEST       ESI,ESI
    //         0047b486     JGE        LAB_0047b48c
    //                              Pnl_scbr.cpp:632 (2)
    //         0047b488     XOR        ESI,ESI
    //                              Pnl_scbr.cpp:633 (13)
    //         0047b48a     JMP        LAB_0047b499
    //                               LAB_0047b48c                                                 XREF[1]:     0047b486(j)  
    //         0047b48c     MOV        EAX,dword ptr [EDI + 0xf8]
    //         0047b492     DEC        EAX
    //         0047b493     CMP        ESI,EAX
    //         0047b495     JLE        LAB_0047b499
    //                              Pnl_scbr.cpp:634 (2)
    //         0047b497     MOV        ESI,EAX
    //                               LAB_0047b499                                                 XREF[2]:     0047b48a(j), 0047b495(j)  
    //                              Pnl_scbr.cpp:636 (4)
    //         0047b499     CMP        ESI,this
    //         0047b49b     JZ         switchD_0047b459::default
    //                              Pnl_scbr.cpp:638 (8)
    //         0047b49d     PUSH       ESI
    //         0047b49e     MOV        this,EDI
    //         0047b4a0     CALL       TScrollBarPanel::set_tab_pos                     void set_tab_pos(TScrollBarPanel * this, long
    //                              Pnl_scbr.cpp:639 (7)
    //         0047b4a5     MOV        this,dword ptr [EDI + 0x40]
    //         0047b4a8     TEST       this,this
    //         0047b4aa     JZ         switchD_0047b459::default
    //                              Pnl_scbr.cpp:640 (14)
    //         0047b4ac     MOV        EAX,dword ptr [this->_padding_]
    //         0047b4ae     PUSH       0x0
    //         0047b4b0     PUSH       ESI
    //         0047b4b1     PUSH       0x4
    //         0047b4b3     PUSH       EDI
    //         0047b4b4     CALL       dword ptr [EAX + 0xb4]
    //                               switchD_0047b459::default                                    XREF[3]:     0047b457(j), 0047b49b(j), 
    //                                                                                                         0047b4aa(j)  
    //                              Pnl_scbr.cpp:643 (26)
    //         0047b4ba     POP        EDI
    //         0047b4bb     POP        ESI
    //         0047b4bc     RET        0x8
}

// Offset: 0x0047B4E0
void TScrollBarPanel::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TScrollBarPanel::draw(void)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TScrollBarPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //                               ?draw@TScrollBarPanel@@UAEXXZ                                XREF[3]:     draw:0047bddc(T), 
    //                               TScrollBarPanel::draw                                                     draw:0047bde0(j), 
    //                                                                                                         draw:0047bf30(j), 00571860(*)  
    //                              Pnl_scbr.cpp:649 (5)
    //         0047b4e0     PUSH       EBP
    //         0047b4e1     PUSH       ESI
    //         0047b4e2     MOV        ESI,this
    //         0047b4e4     PUSH       EDI
    //                              Pnl_scbr.cpp:651 (7)
    //         0047b4e5     MOV        this,dword ptr [ESI + 0x40]
    //         0047b4e8     TEST       this,this
    //         0047b4ea     JZ         LAB_0047b4f5
    //                              Pnl_scbr.cpp:656 (9)
    //         0047b4ec     MOV        EAX,dword ptr [this->_padding_]
    //         0047b4ee     LEA        EDX,[ESI + 0x24]
    //         0047b4f1     PUSH       EDX
    //         0047b4f2     CALL       dword ptr [EAX + 0x3c]
    //                               LAB_0047b4f5                                                 XREF[1]:     0047b4ea(j)  
    //                              Pnl_scbr.cpp:659 (9)
    //         0047b4f5     MOV        EBP,dword ptr [ESI]
    //         0047b4f7     PUSH       0x0
    //         0047b4f9     MOV        this,ESI
    //         0047b4fb     CALL       dword ptr [EBP + 0x28]
    //                              Pnl_scbr.cpp:661 (23)
    //         0047b4fe     MOV        this,dword ptr [ESI + 0x20]
    //         0047b501     PUSH       0x1
    //         0047b503     PUSH       s_pnl_scbr::draw                                 = "pnl_scbr::draw"
    //         0047b508     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0047b50d     TEST       EAX,EAX
    //         0047b50f     JZ         LAB_0047b650
    //                              Pnl_scbr.cpp:664 (7)
    //         0047b515     MOV        this,ESI
    //         0047b517     CALL       TScrollBarPanel::draw_back_pic                   void draw_back_pic(TScrollBarPanel * this)
    //                              Pnl_scbr.cpp:665 (18)
    //         0047b51c     LEA        EAX,[ESI + 0x8c]
    //         0047b522     MOV        this,ESI
    //         0047b524     PUSH       EAX
    //         0047b525     PUSH       0x1
    //         0047b527     PUSH       0x0
    //         0047b529     CALL       TScrollBarPanel::draw_border                     void draw_border(TScrollBarPanel * this, int 
    //                              Pnl_scbr.cpp:668 (38)
    //         0047b52e     MOV        this,dword ptr [ESI + 0x168]
    //         0047b534     MOV        EAX,dword ptr [ESI + 0x170]
    //         0047b53a     CMP        this,EAX
    //         0047b53c     JZ         LAB_0047b5a7
    //         0047b53e     MOV        EDX,dword ptr [ESI + 0x164]
    //         0047b544     MOV        EAX,dword ptr [ESI + 0x16c]
    //         0047b54a     LEA        EDI,[ESI + 0x164]
    //         0047b550     CMP        EDX,EAX
    //         0047b552     JZ         LAB_0047b5a7
    //                              Pnl_scbr.cpp:670 (44)
    //         0047b554     CMP        byte ptr [ESI + 0x144],0x1
    //         0047b55b     JNZ        LAB_0047b56e
    //         0047b55d     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b563     TEST       EAX,EAX
    //         0047b565     JZ         LAB_0047b56e
    //         0047b567     MOV        EAX,0x1
    //         0047b56c     JMP        LAB_0047b570
    //                               LAB_0047b56e                                                 XREF[2]:     0047b55b(j), 0047b565(j)  
    //         0047b56e     XOR        EAX,EAX
    //                               LAB_0047b570                                                 XREF[1]:     0047b56c(j)  
    //         0047b570     PUSH       EDI
    //         0047b571     PUSH       EAX
    //         0047b572     MOV        EAX,dword ptr [ESI + 0x110]
    //         0047b578     MOV        this,ESI
    //         0047b57a     PUSH       EAX
    //         0047b57b     CALL       TScrollBarPanel::draw_button_pic                 void draw_button_pic(TScrollBarPanel * this, 
    //                              Pnl_scbr.cpp:671 (39)
    //         0047b580     CMP        byte ptr [ESI + 0x144],0x1
    //         0047b587     JNZ        LAB_0047b59a
    //         0047b589     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b58f     TEST       EAX,EAX
    //         0047b591     JZ         LAB_0047b59a
    //         0047b593     MOV        EAX,0x1
    //         0047b598     JMP        LAB_0047b59c
    //                               LAB_0047b59a                                                 XREF[2]:     0047b587(j), 0047b591(j)  
    //         0047b59a     XOR        EAX,EAX
    //                               LAB_0047b59c                                                 XREF[1]:     0047b598(j)  
    //         0047b59c     PUSH       EDI
    //         0047b59d     PUSH       EAX
    //         0047b59e     PUSH       0x1
    //         0047b5a0     MOV        this,ESI
    //         0047b5a2     CALL       TScrollBarPanel::draw_border                     void draw_border(TScrollBarPanel * this, int 
    //                               LAB_0047b5a7                                                 XREF[2]:     0047b53c(j), 0047b552(j)  
    //                              Pnl_scbr.cpp:675 (38)
    //         0047b5a7     MOV        this,dword ptr [ESI + 0x178]
    //         0047b5ad     MOV        EAX,dword ptr [ESI + 0x180]
    //         0047b5b3     CMP        this,EAX
    //         0047b5b5     JZ         LAB_0047b620
    //         0047b5b7     MOV        EDX,dword ptr [ESI + 0x174]
    //         0047b5bd     MOV        EAX,dword ptr [ESI + 0x17c]
    //         0047b5c3     LEA        EDI,[ESI + 0x174]
    //         0047b5c9     CMP        EDX,EAX
    //         0047b5cb     JZ         LAB_0047b620
    //                              Pnl_scbr.cpp:677 (44)
    //         0047b5cd     CMP        byte ptr [ESI + 0x144],0x2
    //         0047b5d4     JNZ        LAB_0047b5e7
    //         0047b5d6     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b5dc     TEST       EAX,EAX
    //         0047b5de     JZ         LAB_0047b5e7
    //         0047b5e0     MOV        EAX,0x1
    //         0047b5e5     JMP        LAB_0047b5e9
    //                               LAB_0047b5e7                                                 XREF[2]:     0047b5d4(j), 0047b5de(j)  
    //         0047b5e7     XOR        EAX,EAX
    //                               LAB_0047b5e9                                                 XREF[1]:     0047b5e5(j)  
    //         0047b5e9     PUSH       EDI
    //         0047b5ea     PUSH       EAX
    //         0047b5eb     MOV        EAX,dword ptr [ESI + 0x114]
    //         0047b5f1     MOV        this,ESI
    //         0047b5f3     PUSH       EAX
    //         0047b5f4     CALL       TScrollBarPanel::draw_button_pic                 void draw_button_pic(TScrollBarPanel * this, 
    //                              Pnl_scbr.cpp:678 (39)
    //         0047b5f9     CMP        byte ptr [ESI + 0x144],0x2
    //         0047b600     JNZ        LAB_0047b613
    //         0047b602     MOV        EAX,dword ptr [ESI + 0x148]
    //         0047b608     TEST       EAX,EAX
    //         0047b60a     JZ         LAB_0047b613
    //         0047b60c     MOV        EAX,0x1
    //         0047b611     JMP        LAB_0047b615
    //                               LAB_0047b613                                                 XREF[2]:     0047b600(j), 0047b60a(j)  
    //         0047b613     XOR        EAX,EAX
    //                               LAB_0047b615                                                 XREF[1]:     0047b611(j)  
    //         0047b615     PUSH       EDI
    //         0047b616     PUSH       EAX
    //         0047b617     PUSH       0x1
    //         0047b619     MOV        this,ESI
    //         0047b61b     CALL       TScrollBarPanel::draw_border                     void draw_border(TScrollBarPanel * this, int 
    //                               LAB_0047b620                                                 XREF[2]:     0047b5b5(j), 0047b5cb(j)  
    //                              Pnl_scbr.cpp:682 (23)
    //         0047b620     MOV        this,dword ptr [ESI + 0x118]
    //         0047b626     LEA        EDI,[ESI + 0x184]
    //         0047b62c     PUSH       EDI
    //         0047b62d     PUSH       0x0
    //         0047b62f     PUSH       this
    //         0047b630     MOV        this,ESI
    //         0047b632     CALL       TScrollBarPanel::draw_button_pic                 void draw_button_pic(TScrollBarPanel * this, 
    //                              Pnl_scbr.cpp:683 (12)
    //         0047b637     PUSH       EDI
    //         0047b638     PUSH       0x0
    //         0047b63a     PUSH       0x1
    //         0047b63c     MOV        this,ESI
    //         0047b63e     CALL       TScrollBarPanel::draw_border                     void draw_border(TScrollBarPanel * this, int 
    //                              Pnl_scbr.cpp:685 (13)
    //         0047b643     MOV        this,dword ptr [ESI + 0x20]
    //         0047b646     PUSH       s_pnl_scbr::draw                                 = "pnl_scbr::draw"
    //         0047b64b     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0047b650                                                 XREF[1]:     0047b50f(j)  
    //                              Pnl_scbr.cpp:688 (5)
    //         0047b650     MOV        this,ESI
    //         0047b652     CALL       dword ptr [EBP + 0x2c]
    //                              Pnl_scbr.cpp:689 (4)
    //         0047b655     POP        EDI
    //         0047b656     POP        ESI
    //         0047b657     POP        EBP
    //         0047b658     RET
}

// Offset: 0x0047B660
void draw_border(TScrollBarPanel* this_, int param_2, int param_3, tagRECT* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TScrollBarPanel::draw_border(int,int,struct tagRECT *)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_border(TScrollBarPanel * this, int param_1, int
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047b677(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047b672(R)  
    //              tagRECT *         Stack[0xc]:4   param_3                   XREF[1]:     0047b660(R)  
    //                               ?draw_border@TScrollBarPanel@@IAEXHHPAUtagRECT@@@Z           XREF[4]:     draw:0047b529(c), 
    //                               TScrollBarPanel::draw_border                                              draw:0047b5a2(c), 
    //                                                                                                         draw:0047b61b(c), 
    //                                                                                                         draw:0047b63e(c)  
    //                              Pnl_scbr.cpp:695 (34)
    //         0047b660     MOV        EAX,dword ptr [ESP + param_3]
    //         0047b664     MOV        EDX,dword ptr [EAX + 0xc]
    //         0047b667     PUSH       EDX
    //         0047b668     MOV        EDX,dword ptr [EAX + 0x8]
    //         0047b66b     PUSH       EDX
    //         0047b66c     MOV        EDX,dword ptr [EAX + 0x4]
    //         0047b66f     MOV        EAX,dword ptr [EAX]
    //         0047b671     PUSH       EDX
    //         0047b672     MOV        EDX,dword ptr [ESP + param_2]
    //         0047b676     PUSH       EAX
    //         0047b677     MOV        EAX,dword ptr [ESP + param_1]
    //         0047b67b     PUSH       EDX
    //         0047b67c     PUSH       EAX
    //         0047b67d     CALL       TScrollBarPanel::draw_border                     void draw_border(TScrollBarPanel * this, int 
    //                              Pnl_scbr.cpp:697 (3)
    //         0047b682     RET        0xc
}

// Offset: 0x0047B690
void draw_border(TScrollBarPanel* this_, int param_2, int param_3, long param_4, long param_5, long param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TScrollBarPanel::draw_border(int,int,long,long,long,long)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_border(TScrollBarPanel * this, int param_1, int
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0047b6d9(R), 0047b79d(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047b6b6(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0047b691(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0047b6a6(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0047b696(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0047b6aa(R)  
    //                               ?draw_border@TScrollBarPanel@@IAEXHHJJJJ@Z                   XREF[1]:     draw_border:0047b67d(c)  
    //                               TScrollBarPanel::draw_border
    //                              Pnl_scbr.cpp:703 (1)
    //         0047b690     PUSH       EBX
    //                              Pnl_scbr.cpp:704 (37)
    //         0047b691     MOV        EBX,dword ptr [ESP + param_3]
    //         0047b695     PUSH       EBP
    //         0047b696     MOV        EBP,dword ptr [ESP + param_5]
    //         0047b69a     PUSH       ESI
    //         0047b69b     CMP        EBX,EBP
    //         0047b69d     PUSH       EDI
    //         0047b69e     MOV        ESI,this
    //         0047b6a0     JZ         switchD_0047b6d2::default
    //         0047b6a6     MOV        EDI,dword ptr [ESP + param_4]
    //         0047b6aa     MOV        EAX,dword ptr [ESP + param_6]
    //         0047b6ae     CMP        EDI,EAX
    //         0047b6b0     JZ         switchD_0047b6d2::default
    //                              Pnl_scbr.cpp:707 (6)
    //         0047b6b6     MOV        this,dword ptr [ESP + param_2]
    //         0047b6ba     TEST       this,this
    //                              Pnl_scbr.cpp:709 (29)
    //         0047b6bc     MOV        this,dword ptr [ESI + 0x1b8]
    //         0047b6c2     JZ         LAB_0047b78c
    //         0047b6c8     DEC        this
    //         0047b6c9     CMP        this,0x3
    //         0047b6cc     JA         switchD_0047b6d2::default
    //                               switchD_0047b6d2::switchD
    //         0047b6d2     JMP        dword ptr [this->_padding_*0x4 + switchD_0047b   = 0047b6d9
    //                               switchD_0047b6d2::caseD_0                                    XREF[2]:     0047b6d2(j), 0047b888(*)  
    //                              Pnl_scbr.cpp:712 (4)
    //         0047b6d9     MOV        this,dword ptr [ESP + param_1]
    //                              Pnl_scbr.cpp:713 (27)
    //         0047b6dd     PUSH       0xff
    //         0047b6e2     TEST       this,this
    //         0047b6e4     PUSH       EAX
    //         0047b6e5     JZ         LAB_0047b7e8
    //         0047b6eb     MOV        this,dword ptr [ESI + 0x20]
    //         0047b6ee     INC        EDI
    //         0047b6ef     PUSH       EBP
    //         0047b6f0     INC        EBX
    //         0047b6f1     PUSH       EDI
    //         0047b6f2     PUSH       EBX
    //         0047b6f3     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b6f8     POP        EDI
    //         0047b6f9     POP        ESI
    //         0047b6fa     POP        EBP
    //         0047b6fb     POP        EBX
    //         0047b6fc     RET        0x18
    //                               switchD_0047b6d2::caseD_1                                    XREF[2]:     0047b6d2(j), 0047b88c(*)  
    //                              Pnl_scbr.cpp:719 (26)
    //         0047b6ff     MOV        this,byte ptr [ESI + 0x1bc]
    //         0047b705     MOV        DL,byte ptr [ESI + 0x1c1]
    //         0047b70b     PUSH       this
    //         0047b70c     MOV        this,dword ptr [ESI + 0x20]
    //         0047b70f     PUSH       EDX
    //         0047b710     PUSH       EAX
    //         0047b711     PUSH       EBP
    //         0047b712     PUSH       EDI
    //         0047b713     PUSH       EBX
    //         0047b714     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b719     POP        EDI
    //         0047b71a     POP        ESI
    //         0047b71b     POP        EBP
    //         0047b71c     POP        EBX
    //         0047b71d     RET        0x18
    //                               switchD_0047b6d2::caseD_2                                    XREF[2]:     0047b6d2(j), 0047b890(*)  
    //                              Pnl_scbr.cpp:723 (40)
    //         0047b720     MOV        this,byte ptr [ESI + 0x1bc]
    //         0047b726     MOV        DL,byte ptr [ESI + 0x1bd]
    //         0047b72c     PUSH       this
    //         0047b72d     MOV        this,byte ptr [ESI + 0x1c0]
    //         0047b733     PUSH       EDX
    //         0047b734     MOV        DL,byte ptr [ESI + 0x1c1]
    //         0047b73a     PUSH       this
    //         0047b73b     MOV        this,dword ptr [ESI + 0x20]
    //         0047b73e     PUSH       EDX
    //         0047b73f     PUSH       EAX
    //         0047b740     PUSH       EBP
    //         0047b741     PUSH       EDI
    //         0047b742     PUSH       EBX
    //         0047b743     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b748     POP        EDI
    //         0047b749     POP        ESI
    //         0047b74a     POP        EBP
    //         0047b74b     POP        EBX
    //         0047b74c     RET        0x18
    //                               switchD_0047b6d2::caseD_3                                    XREF[2]:     0047b6d2(j), 0047b894(*)  
    //                              Pnl_scbr.cpp:727 (41)
    //         0047b74f     MOV        this,byte ptr [ESI + 0x1bc]
    //         0047b755     MOV        DL,byte ptr [ESI + 0x1bd]
    //         0047b75b     PUSH       this
    //         0047b75c     MOV        this,byte ptr [ESI + 0x1be]
    //         0047b762     PUSH       EDX
    //         0047b763     MOV        DL,byte ptr [ESI + 0x1bf]
    //         0047b769     PUSH       this
    //         0047b76a     MOV        this,byte ptr [ESI + 0x1c0]
    //         0047b770     PUSH       EDX
    //         0047b771     MOV        DL,byte ptr [ESI + 0x1c1]
    //         0047b777     PUSH       this
    //                              Pnl_scbr.cpp:755 (13)
    //         0047b778     MOV        this,dword ptr [ESI + 0x20]
    //         0047b77b     PUSH       EDX
    //         0047b77c     PUSH       EAX
    //         0047b77d     PUSH       EBP
    //         0047b77e     PUSH       EDI
    //         0047b77f     PUSH       EBX
    //         0047b780     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b785     POP        EDI
    //         0047b786     POP        ESI
    //         0047b787     POP        EBP
    //         0047b788     POP        EBX
    //         0047b789     RET        0x18
    //                               LAB_0047b78c                                                 XREF[1]:     0047b6c2(j)  
    //                              Pnl_scbr.cpp:733 (17)
    //         0047b78c     DEC        this
    //         0047b78d     CMP        this,0x3
    //         0047b790     JA         switchD_0047b6d2::default
    //                               switchD_0047b796::switchD
    //         0047b796     JMP        dword ptr [this->_padding_*0x4 + switchD_0047b   = 0047b79d
    //                               switchD_0047b796::caseD_0                                    XREF[2]:     0047b796(j), 0047b898(*)  
    //                              Pnl_scbr.cpp:736 (4)
    //         0047b79d     MOV        this,dword ptr [ESP + param_1]
    //                              Pnl_scbr.cpp:738 (22)
    //         0047b7a1     PUSH       0x0
    //         0047b7a3     TEST       this,this
    //         0047b7a5     JZ         LAB_0047b7e7
    //         0047b7a7     MOV        this,dword ptr [ESI + 0x20]
    //         0047b7aa     SUB        EAX,EDI
    //         0047b7ac     PUSH       EAX
    //         0047b7ad     LEA        EAX,[EDI + 0x1]
    //         0047b7b0     PUSH       EAX
    //         0047b7b1     PUSH       EBP
    //         0047b7b2     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Pnl_scbr.cpp:739 (20)
    //         0047b7b7     MOV        this,EBP
    //         0047b7b9     PUSH       0x0
    //         0047b7bb     SUB        this,EBX
    //         0047b7bd     LEA        EDX,[EBX + 0x1]
    //         0047b7c0     PUSH       this
    //         0047b7c1     MOV        this,dword ptr [ESI + 0x20]
    //         0047b7c4     PUSH       EDI
    //         0047b7c5     PUSH       EDX
    //         0047b7c6     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Pnl_scbr.cpp:740 (21)
    //         0047b7cb     MOV        this,dword ptr [ESI + 0x20]
    //         0047b7ce     LEA        EAX,[EDI + -0x1]
    //         0047b7d1     PUSH       0xff
    //         0047b7d6     DEC        EBP
    //         0047b7d7     PUSH       EAX
    //         0047b7d8     PUSH       EBP
    //         0047b7d9     PUSH       EDI
    //         0047b7da     PUSH       EBX
    //         0047b7db     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b7e0     POP        EDI
    //         0047b7e1     POP        ESI
    //         0047b7e2     POP        EBP
    //         0047b7e3     POP        EBX
    //         0047b7e4     RET        0x18
    //                               LAB_0047b7e7                                                 XREF[1]:     0047b7a5(j)  
    //                              Pnl_scbr.cpp:743 (13)
    //         0047b7e7     PUSH       EAX
    //                               LAB_0047b7e8                                                 XREF[1]:     0047b6e5(j)  
    //         0047b7e8     MOV        this,dword ptr [ESI + 0x20]
    //         0047b7eb     DEC        EBP
    //         0047b7ec     PUSH       EBP
    //         0047b7ed     PUSH       EDI
    //         0047b7ee     PUSH       EBX
    //         0047b7ef     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b7f4     POP        EDI
    //         0047b7f5     POP        ESI
    //         0047b7f6     POP        EBP
    //         0047b7f7     POP        EBX
    //         0047b7f8     RET        0x18
    //                               switchD_0047b796::caseD_1                                    XREF[2]:     0047b796(j), 0047b89c(*)  
    //                              Pnl_scbr.cpp:747 (26)
    //         0047b7fb     MOV        this,byte ptr [ESI + 0x1c1]
    //         0047b801     MOV        DL,byte ptr [ESI + 0x1bc]
    //         0047b807     PUSH       this
    //         0047b808     MOV        this,dword ptr [ESI + 0x20]
    //         0047b80b     PUSH       EDX
    //         0047b80c     PUSH       EAX
    //         0047b80d     PUSH       EBP
    //         0047b80e     PUSH       EDI
    //         0047b80f     PUSH       EBX
    //         0047b810     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b815     POP        EDI
    //         0047b816     POP        ESI
    //         0047b817     POP        EBP
    //         0047b818     POP        EBX
    //         0047b819     RET        0x18
    //                               switchD_0047b796::caseD_2                                    XREF[2]:     0047b796(j), 0047b8a0(*)  
    //                              Pnl_scbr.cpp:751 (40)
    //         0047b81c     MOV        this,byte ptr [ESI + 0x1c1]
    //         0047b822     MOV        DL,byte ptr [ESI + 0x1c0]
    //         0047b828     PUSH       this
    //         0047b829     MOV        this,byte ptr [ESI + 0x1bd]
    //         0047b82f     PUSH       EDX
    //         0047b830     MOV        DL,byte ptr [ESI + 0x1bc]
    //         0047b836     PUSH       this
    //         0047b837     MOV        this,dword ptr [ESI + 0x20]
    //         0047b83a     PUSH       EDX
    //         0047b83b     PUSH       EAX
    //         0047b83c     PUSH       EBP
    //         0047b83d     PUSH       EDI
    //         0047b83e     PUSH       EBX
    //         0047b83f     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
    //                              Pnl_scbr.cpp:759 (7)
    //         0047b844     POP        EDI
    //         0047b845     POP        ESI
    //         0047b846     POP        EBP
    //         0047b847     POP        EBX
    //         0047b848     RET        0x18
    //                               switchD_0047b796::caseD_3                                    XREF[2]:     0047b796(j), 0047b8a4(*)  
    //                              Pnl_scbr.cpp:755 (54)
    //         0047b84b     MOV        this,byte ptr [ESI + 0x1c1]
    //         0047b851     MOV        DL,byte ptr [ESI + 0x1c0]
    //         0047b857     PUSH       this
    //         0047b858     MOV        this,byte ptr [ESI + 0x1bf]
    //         0047b85e     PUSH       EDX
    //         0047b85f     MOV        DL,byte ptr [ESI + 0x1be]
    //         0047b865     PUSH       this
    //         0047b866     MOV        this,byte ptr [ESI + 0x1bd]
    //         0047b86c     PUSH       EDX
    //         0047b86d     MOV        DL,byte ptr [ESI + 0x1bc]
    //         0047b873     PUSH       this
    //         0047b874     MOV        this,dword ptr [ESI + 0x20]
    //         0047b877     PUSH       EDX
    //         0047b878     PUSH       EAX
    //         0047b879     PUSH       EBP
    //         0047b87a     PUSH       EDI
    //         0047b87b     PUSH       EBX
    //         0047b87c     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                               switchD_0047b796::default                                    XREF[4]:     0047b6a0(j), 0047b6b0(j), 
    //                               switchD_0047b6d2::default                                                 0047b6cc(j), 0047b790(j)  
    //                              Pnl_scbr.cpp:759 (39)
    //         0047b881     POP        EDI
    //         0047b882     POP        ESI
    //         0047b883     POP        EBP
    //         0047b884     POP        EBX
    //         0047b885     RET        0x18
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0047b6d2::switchdataD_0047b888                       XREF[1]:     draw_border:0047b6d2(*)  
}

// Offset: 0x0047B8B0
void draw_back_pic(TScrollBarPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TScrollBarPanel::draw_back_pic(void)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_back_pic(TScrollBarPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0047b90d(W), 0047b94f(R)  
    //              long              Stack[-0x8]:4  pic_hgt                   XREF[2]:     0047b8e1(*), 0047b8f8(R)  
    //              long              Stack[-0xc]:4  y_min                     XREF[2]:     0047b8d7(*), 0047b901(R)  
    //              long              Stack[-0x10]:4 y_max                     XREF[2]:     0047b8e5(*), 0047b8f4(R)  
    //              long              Stack[-0x14]:4 x_min                     XREF[2]:     0047b8db(*), 0047b8f0(R)  
    //              long              Stack[-0x18]:4 x_max
    //                               ?draw_back_pic@TScrollBarPanel@@IAEXXZ                       XREF[1]:     draw:0047b517(c)  
    //                               TScrollBarPanel::draw_back_pic
    //                              Pnl_scbr.cpp:765 (9)
    //         0047b8b0     SUB        ESP,0x14
    //         0047b8b3     PUSH       EBX
    //         0047b8b4     PUSH       EBP
    //         0047b8b5     PUSH       ESI
    //         0047b8b6     MOV        ESI,this
    //         0047b8b8     PUSH       EDI
    //                              Pnl_scbr.cpp:770 (29)
    //         0047b8b9     MOV        this,dword ptr [ESI + 0x108]
    //         0047b8bf     TEST       this,this
    //         0047b8c1     JZ         LAB_0047b95c
    //         0047b8c7     MOV        EAX,dword ptr [ESI + 0x10c]
    //         0047b8cd     CMP        EAX,-0x1
    //         0047b8d0     JZ         LAB_0047b95c
    //                              Pnl_scbr.cpp:772 (26)
    //         0047b8d6     PUSH       EAX
    //         0047b8d7     LEA        EAX=>y_min,[ESP + 0x1c]
    //         0047b8db     LEA        EDX=>x_min,[ESP + 0x14]
    //         0047b8df     PUSH       EAX
    //         0047b8e0     PUSH       EDX
    //         0047b8e1     LEA        EAX=>pic_hgt,[ESP + 0x28]
    //         0047b8e5     LEA        EDX=>y_max,[ESP + 0x20]
    //         0047b8e9     PUSH       EAX
    //         0047b8ea     PUSH       EDX
    //         0047b8eb     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
    //                              Pnl_scbr.cpp:773 (8)
    //         0047b8f0     MOV        EBP,dword ptr [ESP + x_min]
    //         0047b8f4     MOV        EAX,dword ptr [ESP + y_max]
    //                              Pnl_scbr.cpp:774 (4)
    //         0047b8f8     MOV        EDI,dword ptr [ESP + pic_hgt]
    //                              Pnl_scbr.cpp:777 (23)
    //         0047b8fc     MOV        this,dword ptr [ESI + 0x18]
    //         0047b8ff     SUB        EBP,EAX
    //         0047b901     MOV        EAX,dword ptr [ESP + y_min]
    //         0047b905     SUB        EAX,EDI
    //         0047b907     INC        EBP
    //         0047b908     INC        EAX
    //         0047b909     XOR        EBX,EBX
    //         0047b90b     TEST       this,this
    //         0047b90d     MOV        dword ptr [ESP + local_4],EAX
    //         0047b911     JL         LAB_0047b95c
    //                               LAB_0047b913                                                 XREF[1]:     0047b95a(j)  
    //                              Pnl_scbr.cpp:780 (9)
    //         0047b913     MOV        this,dword ptr [ESI + 0x14]
    //         0047b916     XOR        EDI,EDI
    //         0047b918     TEST       this,this
    //         0047b91a     JL         LAB_0047b953
    //                               LAB_0047b91c                                                 XREF[1]:     0047b94d(j)  
    //                              Pnl_scbr.cpp:782 (45)
    //         0047b91c     MOV        EAX,dword ptr [ESI + 0x10c]
    //         0047b922     PUSH       0x0
    //         0047b924     PUSH       0x0
    //         0047b926     PUSH       EAX
    //         0047b927     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047b92a     MOV        this,EBX
    //         0047b92c     ADD        this,EAX
    //         0047b92e     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047b931     PUSH       this
    //         0047b932     MOV        this,dword ptr [ESI + 0xc]
    //         0047b935     MOV        EDX,EDI
    //         0047b937     ADD        EDX,this
    //         0047b939     MOV        this,dword ptr [ESI + 0x108]
    //         0047b93f     PUSH       EDX
    //         0047b940     PUSH       EAX
    //         0047b941     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //         0047b946     MOV        EAX,dword ptr [ESI + 0x14]
    //                              Pnl_scbr.cpp:783 (6)
    //         0047b949     ADD        EDI,EBP
    //         0047b94b     CMP        EDI,EAX
    //         0047b94d     JLE        LAB_0047b91c
    //                              Pnl_scbr.cpp:780 (4)
    //         0047b94f     MOV        EAX,dword ptr [ESP + local_4]
    //                               LAB_0047b953                                                 XREF[1]:     0047b91a(j)  
    //                              Pnl_scbr.cpp:777 (3)
    //         0047b953     MOV        this,dword ptr [ESI + 0x18]
    //                              Pnl_scbr.cpp:785 (6)
    //         0047b956     ADD        EBX,EAX
    //         0047b958     CMP        EBX,this
    //         0047b95a     JLE        LAB_0047b913
    //                               LAB_0047b95c                                                 XREF[3]:     0047b8c1(j), 0047b8d0(j), 
    //                                                                                                         0047b911(j)  
    //                              Pnl_scbr.cpp:799 (8)
    //         0047b95c     POP        EDI
    //         0047b95d     POP        ESI
    //         0047b95e     POP        EBP
    //         0047b95f     POP        EBX
    //         0047b960     ADD        ESP,0x14
    //         0047b963     RET
}

// Offset: 0x0047B970
void draw_button_pic(TScrollBarPanel* this_, int param_2, int param_3, tagRECT* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TScrollBarPanel::draw_button_pic(int,int,struct tagRECT *)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_button_pic(TScrollBarPanel * this, int param_1,
    //              void              <VOID>         <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0047b987(R), 0047ba1b(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047ba11(R)  
    //              tagRECT *         Stack[0xc]:4   param_3                   XREF[4]:     0047b994(R), 0047b9a6(*), 0047b9c1(R), 0047ba51(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0047b9ab(*), 0047b9ee(R)  
    //              long              Stack[-0x8]:4  y_min                     XREF[2]:     0047b9a1(*), 0047b9fb(R)  
    //              long              Stack[-0xc]:4  y_max                     XREF[2]:     0047b9b6(*), 0047b9c5(R)  
    //              long              Stack[-0x10]:4 x_min
    //                               ?draw_button_pic@TScrollBarPanel@@IAEXHHPAUtagRECT@@@Z       XREF[3]:     draw:0047b57b(c), 
    //                               TScrollBarPanel::draw_button_pic                                          draw:0047b5f4(c), 
    //                                                                                                         draw:0047b632(c)  
    //                              Pnl_scbr.cpp:805 (8)
    //         0047b970     SUB        ESP,0xc
    //         0047b973     PUSH       EBX
    //         0047b974     MOV        EBX,this
    //         0047b976     PUSH       EBP
    //         0047b977     PUSH       ESI
    //                              Pnl_scbr.cpp:810 (28)
    //         0047b978     MOV        EAX,dword ptr [EBX + 0x108]
    //         0047b97e     PUSH       EDI
    //         0047b97f     TEST       EAX,EAX
    //         0047b981     JZ         LAB_0047ba4e
    //         0047b987     MOV        EDI,dword ptr [ESP + param_1]
    //         0047b98b     CMP        EDI,-0x1
    //         0047b98e     JZ         LAB_0047ba4e
    //                              Pnl_scbr.cpp:821 (13)
    //         0047b994     MOV        ESI,dword ptr [ESP + param_3]
    //         0047b998     MOV        this,dword ptr [EBX + 0x20]
    //         0047b99b     PUSH       ESI
    //         0047b99c     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT * 
    //                              Pnl_scbr.cpp:823 (32)
    //         0047b9a1     LEA        EAX=>y_min,[ESP + 0x14]
    //         0047b9a5     PUSH       EDI
    //         0047b9a6     LEA        this=>param_3,[ESP + 0x2c]
    //         0047b9aa     PUSH       EAX
    //         0047b9ab     LEA        EDX=>local_4,[ESP + 0x20]
    //         0047b9af     PUSH       this
    //         0047b9b0     MOV        this,dword ptr [EBX + 0x108]
    //         0047b9b6     LEA        EAX=>y_max,[ESP + 0x1c]
    //         0047b9ba     PUSH       EDX
    //         0047b9bb     PUSH       EAX
    //         0047b9bc     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
    //                              Pnl_scbr.cpp:826 (29)
    //         0047b9c1     MOV        EAX,dword ptr [ESP + param_3]
    //         0047b9c5     MOV        EDI,dword ptr [ESP + y_max]
    //         0047b9c9     SUB        EAX,EDI
    //         0047b9cb     MOV        this,dword ptr [ESI]
    //         0047b9cd     INC        EAX
    //         0047b9ce     CDQ
    //         0047b9cf     SUB        EAX,EDX
    //         0047b9d1     MOV        EBP,EAX
    //         0047b9d3     MOV        EAX,dword ptr [ESI + 0x8]
    //         0047b9d6     SUB        EAX,this
    //         0047b9d8     SAR        EBP,0x1
    //         0047b9da     INC        EAX
    //         0047b9db     CDQ
    //         0047b9dc     SUB        EAX,EDX
    //                              Pnl_scbr.cpp:827 (51)
    //         0047b9de     MOV        EDX,dword ptr [ESI + 0x4]
    //         0047b9e1     MOV        this,EAX
    //         0047b9e3     MOV        EAX,dword ptr [ESI + 0xc]
    //         0047b9e6     SAR        this,0x1
    //         0047b9e8     SUB        this,EBP
    //         0047b9ea     SUB        EAX,EDX
    //         0047b9ec     SUB        this,EDI
    //         0047b9ee     MOV        EBP,dword ptr [ESP + local_4]
    //         0047b9f2     ADD        this,word ptr [ESI]
    //         0047b9f5     INC        EAX
    //         0047b9f6     CDQ
    //         0047b9f7     SUB        EAX,EDX
    //         0047b9f9     MOV        EDI,EAX
    //         0047b9fb     MOV        EAX,dword ptr [ESP + y_min]
    //         0047b9ff     SUB        EAX,EBP
    //         0047ba01     SAR        EDI,0x1
    //         0047ba03     INC        EAX
    //         0047ba04     CDQ
    //         0047ba05     SUB        EAX,EDX
    //         0047ba07     SAR        EAX,0x1
    //         0047ba09     SUB        EDI,EAX
    //         0047ba0b     SUB        EDI,EBP
    //         0047ba0d     ADD        DI,word ptr [ESI + 0x4]
    //                              Pnl_scbr.cpp:829 (8)
    //         0047ba11     MOV        ESI,dword ptr [ESP + param_2]
    //         0047ba15     TEST       ESI,ESI
    //         0047ba17     JZ         LAB_0047ba1b
    //                              Pnl_scbr.cpp:831 (1)
    //         0047ba19     INC        this
    //                              Pnl_scbr.cpp:832 (1)
    //         0047ba1a     DEC        EDI
    //                               LAB_0047ba1b                                                 XREF[1]:     0047ba17(j)  
    //                              Pnl_scbr.cpp:835 (41)
    //         0047ba1b     MOV        EAX,dword ptr [ESP + param_1]
    //         0047ba1f     XOR        EDX,EDX
    //         0047ba21     TEST       ESI,ESI
    //         0047ba23     SETNZ      DL
    //         0047ba26     ADD        EDX,EAX
    //         0047ba28     PUSH       0x0
    //         0047ba2a     MOVSX      EAX,DI
    //         0047ba2d     MOVSX      this,this
    //         0047ba30     PUSH       0x0
    //         0047ba32     PUSH       EDX
    //         0047ba33     MOV        EDX,dword ptr [EBX + 0x20]
    //         0047ba36     PUSH       EAX
    //         0047ba37     PUSH       this
    //         0047ba38     MOV        this,dword ptr [EBX + 0x108]
    //         0047ba3e     PUSH       EDX
    //         0047ba3f     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Pnl_scbr.cpp:836 (10)
    //         0047ba44     POP        EDI
    //         0047ba45     POP        ESI
    //         0047ba46     POP        EBP
    //         0047ba47     POP        EBX
    //         0047ba48     ADD        ESP,0xc
    //         0047ba4b     RET        0xc
    //                               LAB_0047ba4e                                                 XREF[2]:     0047b981(j), 0047b98e(j)  
    //                              Pnl_scbr.cpp:813 (13)
    //         0047ba4e     MOV        this,dword ptr [EBX + 0x40]
    //         0047ba51     MOV        EDX,dword ptr [ESP + param_3]
    //         0047ba55     PUSH       EDX
    //         0047ba56     MOV        EAX,dword ptr [this->_padding_]
    //         0047ba58     CALL       dword ptr [EAX + 0x3c]
    //                              Pnl_scbr.cpp:836 (10)
    //         0047ba5b     POP        EDI
    //         0047ba5c     POP        ESI
    //         0047ba5d     POP        EBP
    //         0047ba5e     POP        EBX
    //         0047ba5f     ADD        ESP,0xc
    //         0047ba62     RET        0xc
}

