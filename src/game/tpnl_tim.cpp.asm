#include "common.h"
#include "tpnl_tim.h"

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* param_1, TPanel* param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Panel_Time(TRIBE_Panel_Time * this, TDraw
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0051d7d8(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0051d7d4(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0051d7c9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051d871(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051d7aa(W)  
    //                               ??0TRIBE_Panel_Time@@QAE@PAVTDrawArea@@PAVTPanel@@@Z         XREF[2]:     TRIBE_Screen_Game:00494983(c), 
    //                               TRIBE_Panel_Time::TRIBE_Panel_Time                                        TRIBE_Screen_Game:00494a43(c)  
    //                              tpnl_tim.cpp:35 (43)
    //         0051d790     PUSH       -0x1
    //         0051d792     PUSH       FUN_00561408
    //         0051d797     MOV        EAX,FS:[0x0]
    //         0051d79d     PUSH       EAX
    //         0051d79e     MOV        dword ptr FS:[0x0],ESP
    //         0051d7a5     PUSH       this
    //         0051d7a6     PUSH       ESI
    //         0051d7a7     MOV        ESI,this
    //         0051d7a9     PUSH       EDI
    //         0051d7aa     MOV        dword ptr [ESP + local_10],ESI
    //         0051d7ae     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //         0051d7b3     XOR        EDI,EDI
    //         0051d7b5     MOV        dword ptr [ESI],TRIBE_Panel_Time::`vftable'      = 0051d890
    //                              tpnl_tim.cpp:36 (6)
    //         0051d7bb     MOV        dword ptr [ESI + 0x80],EDI
    //                              tpnl_tim.cpp:38 (17)
    //         0051d7c1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051d7c7     PUSH       0xb
    //         0051d7c9     MOV        dword ptr [ESP + local_4],EDI
    //         0051d7cd     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              tpnl_tim.cpp:39 (2)
    //         0051d7d2     MOV        EAX,dword ptr [EAX]
    //                              tpnl_tim.cpp:62 (147)
    //         0051d7d4     MOV        this,dword ptr [ESP + param_2]
    //         0051d7d8     MOV        EDX,dword ptr [ESP + param_1]
    //         0051d7dc     PUSH       EDI
    //         0051d7dd     PUSH       EDI
    //         0051d7de     PUSH       EDI
    //         0051d7df     PUSH       EDI
    //         0051d7e0     MOV        dword ptr [ESI + 0xf4],EAX
    //         0051d7e6     PUSH       EDI
    //         0051d7e7     OR         EAX,0xffffffff
    //         0051d7ea     PUSH       this
    //         0051d7eb     PUSH       EDX
    //         0051d7ec     MOV        this,ESI
    //         0051d7ee     MOV        dword ptr [ESI + 0xf8],0xffffff
    //         0051d7f8     MOV        dword ptr [ESI + 0xfc],EDI
    //         0051d7fe     MOV        dword ptr [ESI + 0x100],EDI
    //         0051d804     MOV        dword ptr [ESI + 0x108],EDI
    //         0051d80a     MOV        dword ptr [ESI + 0x104],EDI
    //         0051d810     MOV        dword ptr [ESI + 0x10c],EDI
    //         0051d816     MOV        dword ptr [ESI + 0x110],EDI
    //         0051d81c     MOV        dword ptr [ESI + 0x114],EDI
    //         0051d822     MOV        dword ptr [ESI + 0x118],EDI
    //         0051d828     MOV        dword ptr [ESI + 0x11c],EDI
    //         0051d82e     MOV        dword ptr [ESI + 0x120],EDI
    //         0051d834     MOV        dword ptr [ESI + 0x124],EDI
    //         0051d83a     MOV        dword ptr [ESI + 0x12c],EAX
    //         0051d840     MOV        dword ptr [ESI + 0x134],EDI
    //         0051d846     MOV        dword ptr [ESI + 0x16c],EAX
    //         0051d84c     MOV        dword ptr [ESI + 0x170],EAX
    //         0051d852     MOV        dword ptr [ESI + 0x168],EDI
    //         0051d858     MOV        dword ptr [ESI + 0x130],EDI
    //         0051d85e     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //         0051d863     TEST       EAX,EAX
    //         0051d865     JNZ        LAB_0051d871
    //                              tpnl_tim.cpp:63 (10)
    //         0051d867     MOV        dword ptr [ESI + 0xd8],0x1
    //                               LAB_0051d871                                                 XREF[1]:     0051d865(j)  
    //                              tpnl_tim.cpp:64 (21)
    //         0051d871     MOV        this,dword ptr [ESP + local_c]
    //         0051d875     MOV        EAX,ESI
    //         0051d877     POP        EDI
    //         0051d878     MOV        dword ptr FS:[0x0],this
    //         0051d87f     POP        ESI
    //         0051d880     ADD        ESP,0x10
    //         0051d883     RET        0x8
    //         0051d886     ??         90h
    //         0051d887     NOP
    //         0051d888     NOP
    //         0051d889     NOP
    //         0051d88a     NOP
    //         0051d88b     NOP
    //         0051d88c     NOP
    //         0051d88d     NOP
    //         0051d88e     NOP
    //         0051d88f     NOP
}

TRIBE_Panel_Time::~TRIBE_Panel_Time() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Panel_Time(TRIBE_Panel_Time * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0051d8da(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051d8ca(W)  
    //                               ??1TRIBE_Panel_Time@@UAE@XZ                                  XREF[1]:     `scalar_deleting_destructor':0051d
    //                               TRIBE_Panel_Time::~TRIBE_Panel_Time
    //                              tpnl_tim.cpp:71 (36)
    //         0051d8b0     PUSH       -0x1
    //         0051d8b2     PUSH       FUN_00561428
    //         0051d8b7     MOV        EAX,FS:[0x0]
    //         0051d8bd     PUSH       EAX
    //         0051d8be     MOV        dword ptr FS:[0x0],ESP
    //         0051d8c5     PUSH       this
    //         0051d8c6     PUSH       ESI
    //         0051d8c7     MOV        ESI,this
    //         0051d8c9     PUSH       EDI
    //         0051d8ca     MOV        dword ptr [ESP + local_10],ESI
    //         0051d8ce     MOV        dword ptr [ESI],TRIBE_Panel_Time::`vftable'      = 0051d890
    //                              tpnl_tim.cpp:73 (18)
    //         0051d8d4     MOV        EAX,dword ptr [ESI + 0x130]
    //         0051d8da     MOV        dword ptr [ESP + local_4],0x0
    //         0051d8e2     TEST       EAX,EAX
    //         0051d8e4     JZ         LAB_0051d8f7
    //                              tpnl_tim.cpp:75 (7)
    //         0051d8e6     PUSH       EAX
    //         0051d8e7     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
    //                              tpnl_tim.cpp:76 (10)
    //         0051d8ed     MOV        dword ptr [ESI + 0x130],0x0
    //                               LAB_0051d8f7                                                 XREF[1]:     0051d8e4(j)  
    //                              tpnl_tim.cpp:79 (10)
    //         0051d8f7     MOV        EDI,dword ptr [ESI + 0x134]
    //         0051d8fd     TEST       EDI,EDI
    //         0051d8ff     JZ         LAB_0051d91b
    //                              tpnl_tim.cpp:81 (16)
    //         0051d901     MOV        this,EDI
    //         0051d903     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         0051d908     PUSH       EDI
    //         0051d909     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051d90e     ADD        ESP,0x4
    //                              tpnl_tim.cpp:82 (12)
    //         0051d911     MOV        dword ptr [ESI + 0x134],0x0
    //                               LAB_0051d91b                                                 XREF[1]:     0051d8ff(j)  
    //         0051d91b     MOV        this,ESI
    //                              tpnl_tim.cpp:85 (30)
    //         0051d91d     MOV        dword ptr [ESP + 0x14],0xffffffff
    //         0051d925     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0051d92a     MOV        this,dword ptr [ESP + 0xc]
    //         0051d92e     POP        EDI
    //         0051d92f     MOV        dword ptr FS:[0x0],this
    //         0051d936     POP        ESI
    //         0051d937     ADD        ESP,0x10
    //         0051d93a     RET
    //         0051d93b     ??         90h
    //         0051d93c     NOP
    //         0051d93d     NOP
    //         0051d93e     NOP
    //         0051d93f     NOP
}

void TRIBE_Panel_Time::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
    //                              void __thiscall set_rect(TRIBE_Panel_Time * this, long param_1, long
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0051d966(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0051d952(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0051d961(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0051d94e(R)  
    //                               ?set_rect@TRIBE_Panel_Time@@UAEXJJJJ@Z                       XREF[1]:     00576eb4(*)  
    //                               TRIBE_Panel_Time::set_rect
    //                              tpnl_tim.cpp:92 (14)
    //         0051d940     MOV        EAX,FS:[0x0]
    //         0051d946     PUSH       -0x1
    //         0051d948     PUSH       FUN_0056144b
    //         0051d94d     PUSH       EAX
    //                              tpnl_tim.cpp:94 (39)
    //         0051d94e     MOV        EAX,dword ptr [ESP + param_4]
    //         0051d952     MOV        EDX,dword ptr [ESP + param_2]
    //         0051d956     MOV        dword ptr FS:[0x0],ESP
    //         0051d95d     PUSH       EBX
    //         0051d95e     PUSH       ESI
    //         0051d95f     MOV        ESI,this
    //         0051d961     MOV        this,dword ptr [ESP + param_3]
    //         0051d965     PUSH       EDI
    //         0051d966     MOV        EDI,dword ptr [ESP + param_1]
    //         0051d96a     PUSH       EAX
    //         0051d96b     PUSH       this
    //         0051d96c     PUSH       EDX
    //         0051d96d     PUSH       EDI
    //         0051d96e     MOV        this,ESI
    //         0051d970     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
    //                              tpnl_tim.cpp:98 (42)
    //         0051d975     MOV        EAX,dword ptr [ESI + 0x16c]
    //         0051d97b     MOV        this,dword ptr [ESI + 0x14]
    //         0051d97e     XOR        EBX,EBX
    //         0051d980     CMP        this,EAX
    //         0051d982     JG         LAB_0051d99f
    //         0051d984     MOV        this,dword ptr [ESI + 0x18]
    //         0051d987     MOV        EDX,dword ptr [ESI + 0x170]
    //         0051d98d     CMP        this,EDX
    //         0051d98f     JG         LAB_0051d99f
    //         0051d991     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051d994     ADD        EDI,EAX
    //         0051d996     CMP        EDI,dword ptr [EDX + 0x18]
    //         0051d999     JL         LAB_0051da61
    //                               LAB_0051d99f                                                 XREF[2]:     0051d982(j), 0051d98f(j)  
    //                              tpnl_tim.cpp:100 (10)
    //         0051d99f     MOV        EAX,dword ptr [ESI + 0x130]
    //         0051d9a5     CMP        EAX,EBX
    //         0051d9a7     JZ         LAB_0051d9b6
    //                              tpnl_tim.cpp:102 (7)
    //         0051d9a9     PUSH       EAX
    //         0051d9aa     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
    //                              tpnl_tim.cpp:103 (6)
    //         0051d9b0     MOV        dword ptr [ESI + 0x130],EBX
    //                               LAB_0051d9b6                                                 XREF[1]:     0051d9a7(j)  
    //                              tpnl_tim.cpp:106 (10)
    //         0051d9b6     MOV        EDI,dword ptr [ESI + 0x134]
    //         0051d9bc     CMP        EDI,EBX
    //         0051d9be     JZ         LAB_0051d9d6
    //                              tpnl_tim.cpp:108 (16)
    //         0051d9c0     MOV        this,EDI
    //         0051d9c2     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         0051d9c7     PUSH       EDI
    //         0051d9c8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051d9cd     ADD        ESP,0x4
    //                              tpnl_tim.cpp:109 (6)
    //         0051d9d0     MOV        dword ptr [ESI + 0x134],EBX
    //                               LAB_0051d9d6                                                 XREF[1]:     0051d9be(j)  
    //                              tpnl_tim.cpp:112 (42)
    //         0051d9d6     PUSH       0x100
    //         0051d9db     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0051d9e0     ADD        ESP,0x4
    //         0051d9e3     MOV        dword ptr [ESP + 0x28],EAX
    //         0051d9e7     CMP        EAX,EBX
    //         0051d9e9     MOV        dword ptr [ESP + 0x14],EBX
    //         0051d9ed     JZ         LAB_0051d9fe
    //         0051d9ef     PUSH       EBX
    //         0051d9f0     PUSH       s_time_message_panel                             = "time message panel"
    //         0051d9f5     MOV        this,EAX
    //         0051d9f7     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         0051d9fc     JMP        LAB_0051da00
    //                               LAB_0051d9fe                                                 XREF[1]:     0051d9ed(j)  
    //         0051d9fe     XOR        EAX,EAX
    //                               LAB_0051da00                                                 XREF[1]:     0051d9fc(j)  
    //                              tpnl_tim.cpp:113 (37)
    //         0051da00     MOV        this,dword ptr [ESI + 0x18]
    //         0051da03     MOV        EDX,dword ptr [ESI + 0x14]
    //         0051da06     PUSH       EBX
    //         0051da07     PUSH       EBX
    //         0051da08     PUSH       this
    //         0051da09     MOV        this,dword ptr [ESI + 0x20]
    //         0051da0c     MOV        dword ptr [ESI + 0x134],EAX
    //         0051da12     PUSH       EDX
    //         0051da13     MOV        EDX,dword ptr [this->_padding_]
    //         0051da15     MOV        this,EAX
    //         0051da17     PUSH       EDX
    //         0051da18     MOV        dword ptr [ESP + 0x28],0xffffffff
    //         0051da20     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //                              tpnl_tim.cpp:114 (3)
    //         0051da25     MOV        EAX,dword ptr [ESI + 0x14]
    //                              tpnl_tim.cpp:115 (15)
    //         0051da28     MOV        this,dword ptr [ESI + 0x18]
    //         0051da2b     MOV        dword ptr [ESI + 0x16c],EAX
    //         0051da31     MOV        dword ptr [ESI + 0x170],this
    //                              tpnl_tim.cpp:119 (1)
    //         0051da37     DEC        EAX
    //                              tpnl_tim.cpp:120 (1)
    //         0051da38     DEC        this
    //                              tpnl_tim.cpp:122 (40)
    //         0051da39     PUSH       this
    //         0051da3a     PUSH       EAX
    //         0051da3b     PUSH       EBX
    //         0051da3c     PUSH       EBX
    //         0051da3d     MOV        dword ptr [ESI + 0x138],EBX
    //         0051da43     MOV        dword ptr [ESI + 0x13c],EBX
    //         0051da49     MOV        dword ptr [ESI + 0x140],EAX
    //         0051da4f     MOV        dword ptr [ESI + 0x144],this
    //         0051da55     CALL       dword ptr [->GDI32.DLL::CreateRectRgn]           = 0048b2ec
    //         0051da5b     MOV        dword ptr [ESI + 0x130],EAX
    //                               LAB_0051da61                                                 XREF[1]:     0051d999(j)  
    //                              tpnl_tim.cpp:125 (8)
    //         0051da61     CMP        dword ptr [ESI + 0x134],EBX
    //         0051da67     JZ         LAB_0051da8d
    //                              tpnl_tim.cpp:126 (34)
    //         0051da69     LEA        EAX,[ESI + 0x138]
    //         0051da6f     LEA        this,[ESI + 0x148]
    //         0051da75     MOV        EDX,dword ptr [EAX]
    //         0051da77     MOV        dword ptr [this->_padding_],EDX
    //         0051da79     MOV        EDX,dword ptr [EAX + 0x4]
    //         0051da7c     MOV        dword ptr [ECX + this->_padding_],EDX
    //         0051da7f     MOV        EDX,dword ptr [EAX + 0x8]
    //         0051da82     MOV        dword ptr [ECX + this->_padding_],EDX
    //         0051da85     MOV        EAX,dword ptr [EAX + 0xc]
    //         0051da88     MOV        dword ptr [ECX + this->_padding_],EAX
    //                              tpnl_tim.cpp:127 (2)
    //         0051da8b     JMP        LAB_0051daa1
    //                               LAB_0051da8d                                                 XREF[1]:     0051da67(j)  
    //                              tpnl_tim.cpp:129 (10)
    //         0051da8d     MOV        dword ptr [ESI + 0x16c],0xffffffff
    //                              tpnl_tim.cpp:130 (10)
    //         0051da97     MOV        dword ptr [ESI + 0x170],0xffffffff
    //                               LAB_0051daa1                                                 XREF[1]:     0051da8b(j)  
    //                              tpnl_tim.cpp:134 (16)
    //         0051daa1     MOV        EDX,dword ptr [ESI]
    //         0051daa3     PUSH       0x1
    //         0051daa5     MOV        this,ESI
    //         0051daa7     MOV        byte ptr [ESI + 0xf3],0x1
    //         0051daae     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_tim.cpp:136 (20)
    //         0051dab1     MOV        this,dword ptr [ESP + 0xc]
    //         0051dab5     POP        EDI
    //         0051dab6     POP        ESI
    //         0051dab7     MOV        dword ptr FS:[0x0],this
    //         0051dabe     POP        EBX
    //         0051dabf     ADD        ESP,0xc
    //         0051dac2     RET        0x10
    //         0051dac5     ??         90h
    //         0051dac6     NOP
    //         0051dac7     NOP
    //         0051dac8     NOP
    //         0051dac9     NOP
    //         0051daca     NOP
    //         0051dacb     NOP
    //         0051dacc     NOP
    //         0051dacd     NOP
    //         0051dace     NOP
    //         0051dacf     NOP
    return;
}

void TRIBE_Panel_Time::startup() {
    /* TODO: Stub */
    //                              void __thiscall startup(TRIBE_Panel_Time * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //                               ?startup@TRIBE_Panel_Time@@QAEXXZ                            XREF[2]:     TRIBE_Screen_Game:00495371(c), 
    //                               TRIBE_Panel_Time::startup                                                 TRIBE_Screen_Game:00495390(c)  
    //                              tpnl_tim.cpp:144 (8)
    //         0051dad0     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051dad5     PUSH       ESI
    //         0051dad6     MOV        ESI,this
    //                              tpnl_tim.cpp:146 (36)
    //         0051dad8     PUSH       0x92
    //         0051dadd     MOV        this,dword ptr [EAX + 0x3f4]
    //         0051dae3     PUSH       s_C:\msdev\work\age1_x1\tpnl_tim.c               = 43h    C
    //         0051dae8     MOV        dword ptr [ESI + 0x114],this
    //         0051daee     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051daf3     ADD        ESP,0x8
    //         0051daf6     MOV        dword ptr [ESI + 0x11c],EAX
    //                              tpnl_tim.cpp:147 (2)
    //         0051dafc     POP        ESI
    //         0051dafd     RET
    //         0051dafe     ??         90h
    //         0051daff     NOP
    return;
}

void TRIBE_Panel_Time::set_clock_type(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_clock_type(TRIBE_Panel_Time * this, int param_1,
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0051db08(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0051db03(R)  
    //                               ?set_clock_type@TRIBE_Panel_Time@@QAEXHH@Z                   XREF[9]:     TRIBE_Screen_Game:0049537e(c), 
    //                               TRIBE_Panel_Time::set_clock_type                                          TRIBE_Screen_Game:00495399(c), 
    //                                                                                                         key_down_action:00497f8b(c), 
    //                                                                                                         key_down_action:00497fa6(c), 
    //                                                                                                         reset_clocks:0049adc4(c), 
    //                                                                                                         reset_clocks:0049ae26(c), 
    //                                                                                                         reset_clocks:0049aee2(c), 
    //                                                                                                         reset_clocks:0049af9e(c), 
    //                                                                                                         reset_clocks:0049afe2(c)  
    //                              tpnl_tim.cpp:153 (3)
    //         0051db00     PUSH       ESI
    //         0051db01     MOV        ESI,this
    //                              tpnl_tim.cpp:154 (41)
    //         0051db03     MOV        this,dword ptr [ESP + param_2]
    //         0051db07     PUSH       EDI
    //         0051db08     MOV        EDI,dword ptr [ESP + param_1]
    //         0051db0c     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051db12     XOR        EDX,EDX
    //         0051db14     CMP        EAX,EDI
    //         0051db16     JNZ        LAB_0051db32
    //         0051db18     MOV        EAX,dword ptr [ESI + 0x118]
    //         0051db1e     CMP        EAX,EDX
    //         0051db20     JZ         LAB_0051dc3a
    //         0051db26     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         0051db2a     CMP        EAX,this
    //                              tpnl_tim.cpp:155 (6)
    //         0051db2c     JZ         LAB_0051dc3a
    //                               LAB_0051db32                                                 XREF[1]:     0051db16(j)  
    //                              tpnl_tim.cpp:159 (10)
    //         0051db32     CMP        this,EDX
    //         0051db34     MOV        dword ptr [ESI + 0x100],EDI
    //         0051db3a     JLE        LAB_0051db50
    //                              tpnl_tim.cpp:160 (18)
    //         0051db3c     MOV        EAX,dword ptr [ESI + 0x114]
    //         0051db42     MOV        EAX,dword ptr [EAX + 0x40]
    //         0051db45     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         0051db48     MOV        dword ptr [ESI + 0x118],this
    //                              tpnl_tim.cpp:161 (2)
    //         0051db4e     JMP        LAB_0051db56
    //                               LAB_0051db50                                                 XREF[1]:     0051db3a(j)  
    //                              tpnl_tim.cpp:162 (6)
    //         0051db50     MOV        dword ptr [ESI + 0x118],EDX
    //                               LAB_0051db56                                                 XREF[1]:     0051db4e(j)  
    //                              tpnl_tim.cpp:164 (14)
    //         0051db56     MOV        EAX,dword ptr [ESI + 0x118]
    //         0051db5c     CMP        EAX,EDX
    //         0051db5e     JZ         switchD_0051db73::default
    //                              tpnl_tim.cpp:166 (22)
    //         0051db64     MOV        EAX,dword ptr [EAX + 0x108]
    //         0051db6a     MOVSX      EAX,word ptr [EAX + 0x26]
    //         0051db6e     CMP        EAX,0x7
    //         0051db71     JA         switchD_0051db73::default
    //                               switchD_0051db73::switchD
    //         0051db73     JMP        dword ptr [EAX*0x4 + switchD_0051db73::switchd   = 0051db7a
    //                               switchD_0051db73::caseD_0                                    XREF[2]:     0051db73(j), 0051dc40(*)  
    //                              tpnl_tim.cpp:168 (22)
    //         0051db7a     MOV        dword ptr [ESI + 0xf8],0xff0000
    //         0051db84     MOV        dword ptr [ESI + 0xfc],0xb3b3b3
    //         0051db8e     JMP        LAB_0051dbf4
    //                               switchD_0051db73::caseD_1                                    XREF[2]:     0051db73(j), 0051dc44(*)  
    //                              tpnl_tim.cpp:169 (12)
    //         0051db90     MOV        dword ptr [ESI + 0xf8],0x2139c6
    //         0051db9a     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_2                                    XREF[2]:     0051db73(j), 0051dc48(*)  
    //                              tpnl_tim.cpp:170 (12)
    //         0051db9c     MOV        dword ptr [ESI + 0xf8],0xffff
    //         0051dba6     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_3                                    XREF[2]:     0051db73(j), 0051dc4c(*)  
    //                              tpnl_tim.cpp:171 (12)
    //         0051dba8     MOV        dword ptr [ESI + 0xf8],0x4f73a3
    //         0051dbb2     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_4                                    XREF[2]:     0051db73(j), 0051dc50(*)  
    //                              tpnl_tim.cpp:172 (12)
    //         0051dbb4     MOV        dword ptr [ESI + 0xf8],0xf77f3
    //         0051dbbe     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_5                                    XREF[2]:     0051db73(j), 0051dc54(*)  
    //                              tpnl_tim.cpp:173 (12)
    //         0051dbc0     MOV        dword ptr [ESI + 0xf8],0xc700
    //         0051dbca     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_6                                    XREF[2]:     0051db73(j), 0051dc58(*)  
    //                              tpnl_tim.cpp:174 (12)
    //         0051dbcc     MOV        dword ptr [ESI + 0xf8],pathSystem.MGP_openPath
    //         0051dbd6     JMP        LAB_0051dbee
    //                               switchD_0051db73::caseD_7                                    XREF[2]:     0051db73(j), 0051dc5c(*)  
    //                              tpnl_tim.cpp:175 (12)
    //         0051dbd8     MOV        dword ptr [ESI + 0xf8],0xadad00
    //         0051dbe2     JMP        LAB_0051dbee
    //                               switchD_0051db73::default                                    XREF[2]:     0051db5e(j), 0051db71(j)  
    //                              tpnl_tim.cpp:181 (10)
    //         0051dbe4     MOV        dword ptr [ESI + 0xf8],0xffffff
    //                               LAB_0051dbee                                                 XREF[7]:     0051db9a(j), 0051dba6(j), 
    //                                                                                                         0051dbb2(j), 0051dbbe(j), 
    //                                                                                                         0051dbca(j), 0051dbd6(j), 
    //                                                                                                         0051dbe2(j)  
    //                              tpnl_tim.cpp:182 (6)
    //         0051dbee     MOV        dword ptr [ESI + 0xfc],EDX
    //                               LAB_0051dbf4                                                 XREF[1]:     0051db8e(j)  
    //                              tpnl_tim.cpp:185 (10)
    //         0051dbf4     CMP        EDI,0x1
    //         0051dbf7     JZ         LAB_0051dc0a
    //         0051dbf9     CMP        EDI,0x2
    //         0051dbfc     JZ         LAB_0051dc0a
    //                              tpnl_tim.cpp:188 (12)
    //         0051dbfe     MOV        dword ptr [ESI + 0x108],0x2
    //         0051dc08     JMP        LAB_0051dc14
    //                               LAB_0051dc0a                                                 XREF[2]:     0051dbf7(j), 0051dbfc(j)  
    //                              tpnl_tim.cpp:186 (10)
    //         0051dc0a     MOV        dword ptr [ESI + 0x108],0x1
    //                               LAB_0051dc14                                                 XREF[1]:     0051dc08(j)  
    //                              tpnl_tim.cpp:190 (2)
    //         0051dc14     CMP        EDI,EDX
    //                              tpnl_tim.cpp:191 (5)
    //         0051dc16     MOV        EDI,dword ptr [ESI]
    //         0051dc18     JNZ        LAB_0051dc1d
    //         0051dc1a     PUSH       EDX
    //                              tpnl_tim.cpp:192 (2)
    //         0051dc1b     JMP        LAB_0051dc1f
    //                               LAB_0051dc1d                                                 XREF[1]:     0051dc18(j)  
    //                              tpnl_tim.cpp:193 (7)
    //         0051dc1d     PUSH       0x1
    //                               LAB_0051dc1f                                                 XREF[1]:     0051dc1b(j)  
    //         0051dc1f     MOV        this,ESI
    //         0051dc21     CALL       dword ptr [EDI + 0x14]
    //                              tpnl_tim.cpp:194 (7)
    //         0051dc24     PUSH       0x1
    //         0051dc26     MOV        this,ESI
    //         0051dc28     CALL       dword ptr [EDI + 0x20]
    //                              tpnl_tim.cpp:195 (10)
    //         0051dc2b     MOV        this,dword ptr [ESI + 0x40]
    //         0051dc2e     PUSH       0x1
    //         0051dc30     MOV        EDX,dword ptr [this->_padding_]
    //         0051dc32     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_tim.cpp:198 (5)
    //         0051dc35     MOV        this,ESI
    //         0051dc37     CALL       dword ptr [EDI + 0x4c]
    //                               LAB_0051dc3a                                                 XREF[2]:     0051db20(j), 0051db2c(j)  
    //                              tpnl_tim.cpp:199 (38)
    //         0051dc3a     POP        EDI
    //         0051dc3b     POP        ESI
    //         0051dc3c     RET        0x8
    //         0051dc3f     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0051db73::switchdataD_0051dc40                       XREF[1]:     set_clock_type:0051db73(*)  
    //         0051dc40     addr       switchD_0051db73::caseD_0
    //         0051dc44     addr       switchD_0051db73::caseD_1
    //         0051dc48     addr       switchD_0051db73::caseD_2
    //         0051dc4c     addr       switchD_0051db73::caseD_3
    //         0051dc50     addr       switchD_0051db73::caseD_4
    //         0051dc54     addr       switchD_0051db73::caseD_5
    //         0051dc58     addr       switchD_0051db73::caseD_6
    //         0051dc5c     addr       switchD_0051db73::caseD_7
    return;
}

int TRIBE_Panel_Time::get_clock_type() {
    /* TODO: Stub */
    //                              int __thiscall get_clock_type(TRIBE_Panel_Time * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //                               ?get_clock_type@TRIBE_Panel_Time@@QAEHXZ                     XREF[1]:     key_down_action:00497f78(c)  
    //                               TRIBE_Panel_Time::get_clock_type
    //                              tpnl_tim.cpp:205 (6)
    //         0051dc60     MOV        EAX,dword ptr [ECX + this->clock_type]
    //                              tpnl_tim.cpp:207 (1)
    //         0051dc66     RET
    //         0051dc67     ??         90h
    //         0051dc68     NOP
    //         0051dc69     NOP
    //         0051dc6a     NOP
    //         0051dc6b     NOP
    //         0051dc6c     NOP
    //         0051dc6d     NOP
    //         0051dc6e     NOP
    //         0051dc6f     NOP
    return 0;
}

int TRIBE_Panel_Time::get_player_id() {
    /* TODO: Stub */
    //                              int __thiscall get_player_id(TRIBE_Panel_Time * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //                               ?get_player_id@TRIBE_Panel_Time@@QAEHXZ
    //                               TRIBE_Panel_Time::get_player_id
    //                              tpnl_tim.cpp:213 (10)
    //         0051dc70     MOV        EAX,dword ptr [ECX + this->player]
    //         0051dc76     TEST       EAX,EAX
    //         0051dc78     JZ         LAB_0051dc7f
    //                              tpnl_tim.cpp:215 (4)
    //         0051dc7a     MOVSX      EAX,word ptr [EAX + 0x4a]
    //                              tpnl_tim.cpp:218 (1)
    //         0051dc7e     RET
    //                               LAB_0051dc7f                                                 XREF[1]:     0051dc78(j)  
    //                              tpnl_tim.cpp:217 (2)
    //         0051dc7f     XOR        EAX,EAX
    //                              tpnl_tim.cpp:218 (1)
    //         0051dc81     RET
    //         0051dc82     ??         90h
    //         0051dc83     NOP
    //         0051dc84     NOP
    //         0051dc85     NOP
    //         0051dc86     NOP
    //         0051dc87     NOP
    //         0051dc88     NOP
    //         0051dc89     NOP
    //         0051dc8a     NOP
    //         0051dc8b     NOP
    //         0051dc8c     NOP
    //         0051dc8d     NOP
    //         0051dc8e     NOP
    //         0051dc8f     NOP
    return 0;
}

void TRIBE_Panel_Time::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TRIBE_Panel_Time * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              char[256]         Stack[-0x104   str
    //              void *            Stack[-0x108   old_font
    //              undefined4        Stack[-0x110   local_110                 XREF[1]:     0051dcce(W)  
    //              tagRECT           Stack[-0x128   rect
    //                               ?draw@TRIBE_Panel_Time@@UAEXXZ                               XREF[1]:     00576ed8(*)  
    //                               TRIBE_Panel_Time::draw
    //                              tpnl_tim.cpp:224 (9)
    //         0051dc90     SUB        ESP,0x134
    //         0051dc96     PUSH       ESI
    //         0051dc97     MOV        ESI,this
    //                              tpnl_tim.cpp:231 (33)
    //         0051dc99     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051dc9c     TEST       EAX,EAX
    //         0051dc9e     JZ         LAB_0051e0d6
    //         0051dca4     MOV        EAX,dword ptr [ESI + 0x70]
    //         0051dca7     TEST       EAX,EAX
    //         0051dca9     JZ         LAB_0051e0d6
    //         0051dcaf     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0051dcb2     TEST       EAX,EAX
    //         0051dcb4     JZ         LAB_0051e0d6
    //                              tpnl_tim.cpp:234 (7)
    //         0051dcba     MOV        EDX,dword ptr [ESI + 0xe0]
    //         0051dcc0     PUSH       EDI
    //                              tpnl_tim.cpp:236 (20)
    //         0051dcc1     MOV        EDI,dword ptr [ESI]
    //         0051dcc3     PUSH       EBP
    //         0051dcc4     PUSH       EBX
    //         0051dcc5     INC        EDX
    //         0051dcc6     PUSH       0x0
    //         0051dcc8     MOV        dword ptr [ESI + 0xe0],EDX
    //         0051dcce     MOV        dword ptr [ESP + local_110],EDI
    //         0051dcd2     CALL       dword ptr [EDI + 0x28]
    //                              tpnl_tim.cpp:238 (11)
    //         0051dcd5     MOV        this,dword ptr [ESI + 0x108]
    //         0051dcdb     CMP        this,0x1
    //         0051dcde     JNZ        LAB_0051dce8
    //                              tpnl_tim.cpp:239 (6)
    //         0051dce0     MOV        EAX,dword ptr [ESI + 0x120]
    //                              tpnl_tim.cpp:240 (2)
    //         0051dce6     JMP        LAB_0051dcfe
    //                               LAB_0051dce8                                                 XREF[1]:     0051dcde(j)  
    //                              tpnl_tim.cpp:241 (28)
    //         0051dce8     MOV        EDX,dword ptr [ESI + 0x120]
    //         0051dcee     MOV        EAX,0xcccccccd
    //         0051dcf3     ADD        EDX,0x4
    //         0051dcf6     MUL        EDX
    //         0051dcf8     SHR        EDX,0x2
    //         0051dcfb     LEA        EAX,[EDX + EDX*0x4]
    //                               LAB_0051dcfe                                                 XREF[1]:     0051dce6(j)  
    //         0051dcfe     MOV        dword ptr [ESI + 0x128],EAX
    //                              tpnl_tim.cpp:246 (60)
    //         0051dd04     MOV        EAX,dword ptr [ESI + 0x134]
    //         0051dd0a     TEST       EAX,EAX
    //         0051dd0c     JZ         LAB_0051dd68
    //         0051dd0e     MOV        EDX,dword ptr [ESI + 0x128]
    //         0051dd14     MOV        EAX,dword ptr [ESI + 0x12c]
    //         0051dd1a     CMP        EDX,EAX
    //         0051dd1c     JNZ        LAB_0051dd40
    //         0051dd1e     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051dd24     MOV        EDX,dword ptr [ESI + 0x104]
    //         0051dd2a     CMP        EAX,EDX
    //         0051dd2c     JNZ        LAB_0051dd40
    //         0051dd2e     CMP        this,dword ptr [ESI + 0x10c]
    //         0051dd34     JNZ        LAB_0051dd40
    //         0051dd36     MOV        AL,byte ptr [ESI + 0xf3]
    //         0051dd3c     TEST       AL,AL
    //         0051dd3e     JZ         LAB_0051dd68
    //                               LAB_0051dd40                                                 XREF[3]:     0051dd1c(j), 0051dd2c(j), 
    //                                                                                                         0051dd34(j)  
    //                              tpnl_tim.cpp:248 (7)
    //         0051dd40     MOV        this,ESI
    //         0051dd42     CALL       TRIBE_Panel_Time::render_to_image_buffer         int render_to_image_buffer(TRIBE_Panel_Time *
    //                              tpnl_tim.cpp:249 (10)
    //         0051dd47     MOV        AL,byte ptr [ESI + 0xf3]
    //         0051dd4d     TEST       AL,AL
    //         0051dd4f     JZ         LAB_0051dd68
    //                              tpnl_tim.cpp:361 (15)
    //         0051dd51     MOV        this,ESI
    //         0051dd53     MOV        byte ptr [ESI + 0xf3],0x0
    //         0051dd5a     CALL       dword ptr [EDI + 0x2c]
    //         0051dd5d     POP        EBX
    //         0051dd5e     POP        EBP
    //         0051dd5f     POP        EDI
    //                              tpnl_tim.cpp:362 (8)
    //         0051dd60     POP        ESI
    //         0051dd61     ADD        ESP,0x134
    //         0051dd67     RET
    //                               LAB_0051dd68                                                 XREF[3]:     0051dd0c(j), 0051dd3e(j), 
    //                                                                                                         0051dd4f(j)  
    //                              tpnl_tim.cpp:258 (20)
    //         0051dd68     MOV        EAX,dword ptr [ESI + 0x168]
    //         0051dd6e     TEST       EAX,EAX
    //         0051dd70     JZ         LAB_0051ddca
    //         0051dd72     MOV        this,dword ptr [ESI + 0x134]
    //         0051dd78     TEST       this,this
    //         0051dd7a     JZ         LAB_0051ddca
    //                              tpnl_tim.cpp:269 (9)
    //         0051dd7c     PUSH       0x1
    //         0051dd7e     PUSH       offset DAT_fffffff8
    //         0051dd80     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1, 
    //                              tpnl_tim.cpp:270 (38)
    //         0051dd85     MOV        EDX,dword ptr [ESI + 0x15c]
    //         0051dd8b     MOV        EAX,dword ptr [ESI + 0x158]
    //         0051dd91     LEA        this,[ESI + 0x148]
    //         0051dd97     PUSH       0x1
    //         0051dd99     PUSH       this=>DAT_fffffff8
    //         0051dd9a     MOV        this,dword ptr [ESI + 0x20]
    //         0051dd9d     PUSH       EDX=>DAT_fffffff4
    //         0051dd9e     PUSH       EAX=>DAT_fffffff0
    //         0051dd9f     PUSH       this
    //         0051dda0     MOV        this,dword ptr [ESI + 0x134]
    //         0051dda6     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //                              tpnl_tim.cpp:271 (15)
    //         0051ddab     MOV        this,dword ptr [ESI + 0x134]
    //         0051ddb1     PUSH       0x1
    //         0051ddb3     PUSH       0x0=>DAT_fffffff8
    //         0051ddb5     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1, 
    //                              tpnl_tim.cpp:361 (8)
    //         0051ddba     MOV        this,ESI
    //         0051ddbc     CALL       dword ptr [EDI + 0x2c]
    //         0051ddbf     POP        EBX
    //         0051ddc0     POP        EBP
    //         0051ddc1     POP        EDI
    //                              tpnl_tim.cpp:362 (8)
    //         0051ddc2     POP        ESI
    //         0051ddc3     ADD        ESP,0x134
    //         0051ddc9     RET
    //                               LAB_0051ddca                                                 XREF[2]:     0051dd70(j), 0051dd7a(j)  
    //                              tpnl_tim.cpp:278 (21)
    //         0051ddca     MOV        this,dword ptr [ESI + 0x20]
    //         0051ddcd     PUSH       s_tpnl_tim::draw                                 = "tpnl_tim::draw"
    //         0051ddd2     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051ddd7     TEST       EAX,EAX
    //         0051ddd9     JZ         LAB_0051e0ce
    //                              tpnl_tim.cpp:280 (20)
    //         0051dddf     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051dde2     MOV        EDX,dword ptr [ESI + 0x88]
    //         0051dde8     PUSH       EDX
    //         0051dde9     MOV        this,dword ptr [EAX + 0x38]
    //         0051ddec     PUSH       this=>DAT_fffffff8
    //         0051dded     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_tim.cpp:281 (20)
    //         0051ddf3     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051ddf6     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0051ddfc     PUSH       EDX
    //         0051ddfd     MOV        this,dword ptr [EAX + 0x38]
    //         0051de00     PUSH       this=>DAT_fffffff8
    //         0051de01     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_tim.cpp:282 (19)
    //         0051de07     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051de0a     MOV        dword ptr [ESP + 0x40],EAX
    //         0051de0e     PUSH       0x1
    //         0051de10     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051de13     PUSH       EAX=>DAT_fffffff8
    //         0051de14     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_tim.cpp:284 (13)
    //         0051de1a     CMP        dword ptr [ESI + 0x108],0x1
    //         0051de21     JNZ        LAB_0051dea9
    //                              tpnl_tim.cpp:286 (6)
    //         0051de27     MOV        EDI,dword ptr [ESI + 0x120]
    //                              tpnl_tim.cpp:287 (2)
    //         0051de2d     XOR        this,this
    //                              tpnl_tim.cpp:288 (2)
    //         0051de2f     XOR        EBX,EBX
    //                              tpnl_tim.cpp:289 (5)
    //         0051de31     CMP        EDI,0x3b
    //         0051de34     JLE        LAB_0051de79
    //                              tpnl_tim.cpp:291 (21)
    //         0051de36     MOV        EAX,0x88888889
    //         0051de3b     IMUL       EDI
    //         0051de3d     ADD        EDX,EDI
    //         0051de3f     SAR        EDX,0x5
    //         0051de42     MOV        this,EDX
    //         0051de44     SHR        this,0x1f
    //         0051de47     ADD        EDX,this
    //         0051de49     MOV        this,EDX
    //                              tpnl_tim.cpp:292 (7)
    //         0051de4b     SHL        EDX,0x4
    //         0051de4e     SUB        EDX,this
    //         0051de50     NEG        EDX
    //                              tpnl_tim.cpp:293 (8)
    //         0051de52     CMP        this,0x3b
    //         0051de55     LEA        EDI,[EDI + EDX*0x4]
    //         0051de58     JLE        LAB_0051de79
    //                              tpnl_tim.cpp:295 (21)
    //         0051de5a     MOV        EAX,0x88888889
    //         0051de5f     IMUL       this
    //         0051de61     ADD        EDX,this
    //         0051de63     SAR        EDX,0x5
    //         0051de66     MOV        EAX,EDX
    //         0051de68     SHR        EAX,0x1f
    //         0051de6b     ADD        EDX,EAX
    //         0051de6d     MOV        EBX,EDX
    //                              tpnl_tim.cpp:296 (10)
    //         0051de6f     SHL        EDX,0x4
    //         0051de72     SUB        EDX,EBX
    //         0051de74     NEG        EDX
    //         0051de76     LEA        this,[this->_padding_ + EDX*0x4]
    //                               LAB_0051de79                                                 XREF[2]:     0051de34(j), 0051de58(j)  
    //                              tpnl_tim.cpp:299 (41)
    //         0051de79     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051de7e     SUB        ESP,0x8
    //         0051de81     MOV        EDX,dword ptr [EAX + 0x3f4]
    //         0051de87     LEA        EAX,[ESP + 0x4c]
    //         0051de8b     FLD        float ptr [EDX + 0x18]
    //         0051de8e     FSTP       double ptr [ESP]=>DAT_fffffff8
    //         0051de91     PUSH       EDI=>DAT_fffffff4
    //         0051de92     PUSH       this=>DAT_fffffff0
    //         0051de93     PUSH       EBX
    //         0051de94     PUSH       s_%02ld:%02ld:%02ld_(%3.1f)                      = "%02ld:%02ld:%02ld (%3.1f)"
    //         0051de99     PUSH       EAX
    //         0051de9a     CALL       sprintf                                          undefined sprintf()
    //         0051de9f     ADD        ESP,0x1c
    //                              tpnl_tim.cpp:300 (5)
    //         0051dea2     MOV        EBP,0x20
    //                              tpnl_tim.cpp:302 (2)
    //         0051dea7     JMP        LAB_0051df21
    //                               LAB_0051dea9                                                 XREF[1]:     0051de21(j)  
    //                              tpnl_tim.cpp:304 (16)
    //         0051dea9     MOV        this,dword ptr [ESI + 0x120]
    //         0051deaf     MOV        EAX,0xcccccccd
    //         0051deb4     ADD        this,0x4
    //         0051deb7     MUL        this
    //                              tpnl_tim.cpp:306 (21)
    //         0051deb9     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051debf     SHR        EDX,0x2
    //         0051dec2     SUB        EAX,0x4
    //         0051dec5     LEA        this,[EDX + EDX*0x4]
    //         0051dec8     JZ         LAB_0051df01
    //         0051deca     DEC        EAX
    //         0051decb     JZ         LAB_0051deec
    //         0051decd     DEC        EAX
    //                              tpnl_tim.cpp:311 (10)
    //         0051dece     PUSH       this
    //         0051decf     JZ         LAB_0051ded8
    //         0051ded1     PUSH       offset DAT_fffffff8
    //         0051ded6     JMP        LAB_0051df07
    //                              language.dll match for 0x2c27: "Ruins: %d Years"
    //                               LAB_0051ded8                                                 XREF[1]:     0051decf(j)  
    //                              tpnl_tim.cpp:310 (20)
    //         0051ded8     PUSH       offset DAT_fffffff8
    //         0051dedd     MOV        this,ESI
    //         0051dedf     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051dee4     PUSH       EAX=>DAT_fffffff8
    //         0051dee5     LEA        EAX,[ESP + 0x4c]
    //         0051dee9     PUSH       EAX=>DAT_fffffff4
    //         0051deea     JMP        LAB_0051df14
    //                               LAB_0051deec                                                 XREF[1]:     0051decb(j)  
    //                              tpnl_tim.cpp:309 (21)
    //         0051deec     PUSH       this
    //                              language.dll match for 0x2c26: "Artifacts: %d Years"
    //         0051deed     PUSH       offset DAT_fffffff8
    //         0051def2     MOV        this,ESI
    //         0051def4     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051def9     LEA        this,[ESP + 0x48]
    //         0051defd     PUSH       EAX=>DAT_fffffff8
    //         0051defe     PUSH       this=>DAT_fffffff4
    //         0051deff     JMP        LAB_0051df14
    //                               LAB_0051df01                                                 XREF[1]:     0051dec8(j)  
    //                              tpnl_tim.cpp:308 (27)
    //         0051df01     PUSH       this
    //                              language.dll match for 0x2c25: "Wonder: %d Years"
    //         0051df02     PUSH       offset DAT_fffffff8
    //                               LAB_0051df07                                                 XREF[1]:     0051ded6(j)  
    //         0051df07     MOV        this,ESI
    //         0051df09     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051df0e     LEA        EDX,[ESP + 0x48]
    //         0051df12     PUSH       EAX=>DAT_fffffff8
    //         0051df13     PUSH       EDX=>DAT_fffffff4
    //                               LAB_0051df14                                                 XREF[2]:     0051deea(j), 0051deff(j)  
    //         0051df14     CALL       sprintf                                          undefined sprintf()
    //         0051df19     ADD        ESP,0xc
    //                              tpnl_tim.cpp:314 (5)
    //         0051df1c     MOV        EBP,0x22
    //                               LAB_0051df21                                                 XREF[1]:     0051dea7(j)  
    //                              tpnl_tim.cpp:317 (20)
    //         0051df21     MOV        this,dword ptr [ESI + 0x20]
    //         0051df24     MOV        EAX,dword ptr [ESI + 0xfc]
    //         0051df2a     PUSH       EAX
    //         0051df2b     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051df2e     PUSH       EDX=>DAT_fffffff8
    //         0051df2f     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_tim.cpp:321 (6)
    //         0051df35     MOV        EDI,dword ptr [ESI + 0x8c]
    //                              tpnl_tim.cpp:322 (6)
    //         0051df3b     MOV        EBX,dword ptr [ESI + 0x90]
    //                              tpnl_tim.cpp:324 (14)
    //         0051df41     MOV        this,dword ptr [ESI + 0x18]
    //         0051df44     MOV        EAX,dword ptr [ESI + 0x14]
    //         0051df47     INC        EDI
    //         0051df48     INC        EBX
    //         0051df49     SUB        this,0x2
    //         0051df4c     SUB        EAX,0x2
    //                              tpnl_tim.cpp:326 (59)
    //         0051df4f     ADD        this,EBX
    //         0051df51     ADD        EAX,EDI
    //         0051df53     MOV        dword ptr [ESP + 0x14],this
    //         0051df57     ADD        this,-0x2
    //         0051df5a     MOV        dword ptr [ESP + 0x10],EAX
    //         0051df5e     LEA        EDX,[EBX + -0x1]
    //         0051df61     ADD        EAX,-0x2
    //         0051df64     MOV        dword ptr [ESP + 0x1c],EDX
    //         0051df68     PUSH       this
    //         0051df69     MOV        dword ptr [ESP + 0x40],EAX
    //         0051df6d     PUSH       EAX=>DAT_fffffff8
    //         0051df6e     MOV        EAX,dword ptr [ESP + 0x24]
    //         0051df72     MOV        dword ptr [ESP + 0x38],this
    //         0051df76     LEA        EDX,[EDI + -0x1]
    //         0051df79     PUSH       EAX=>DAT_fffffff4
    //         0051df7a     LEA        this,[ESP + 0x2c]
    //         0051df7e     PUSH       EDX=>DAT_fffffff0
    //         0051df7f     PUSH       this
    //         0051df80     MOV        dword ptr [ESP + 0x2c],EDX
    //         0051df84     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:327 (26)
    //         0051df8a     MOV        this,dword ptr [ESI + 0x20]
    //         0051df8d     LEA        EDX,[ESP + 0x20]
    //         0051df91     PUSH       EBP
    //         0051df92     PUSH       EDX=>DAT_fffffff8
    //         0051df93     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051df96     LEA        EAX,[ESP + 0x4c]
    //         0051df9a     PUSH       offset DAT_fffffff4
    //         0051df9c     PUSH       EAX=>DAT_fffffff0
    //         0051df9d     PUSH       EDX
    //         0051df9e     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:329 (34)
    //         0051dfa4     MOV        this,dword ptr [ESP + 0x14]
    //         0051dfa8     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0051dfac     LEA        EAX,[EBX + 0x1]
    //         0051dfaf     PUSH       this
    //         0051dfb0     PUSH       EDX=>DAT_fffffff8
    //         0051dfb1     MOV        dword ptr [ESP + 0x40],EAX
    //         0051dfb5     PUSH       EAX=>DAT_fffffff4
    //         0051dfb6     MOV        EAX,dword ptr [ESP + 0x24]
    //         0051dfba     LEA        this,[ESP + 0x2c]
    //         0051dfbe     PUSH       EAX=>DAT_fffffff0
    //         0051dfbf     PUSH       this
    //         0051dfc0     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:330 (26)
    //         0051dfc6     MOV        this,dword ptr [ESI + 0x20]
    //         0051dfc9     LEA        EDX,[ESP + 0x20]
    //         0051dfcd     PUSH       EBP
    //         0051dfce     PUSH       EDX=>DAT_fffffff8
    //         0051dfcf     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051dfd2     LEA        EAX,[ESP + 0x4c]
    //         0051dfd6     PUSH       offset DAT_fffffff4
    //         0051dfd8     PUSH       EAX=>DAT_fffffff0
    //         0051dfd9     PUSH       EDX
    //         0051dfda     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:332 (34)
    //         0051dfe0     MOV        this,dword ptr [ESP + 0x30]
    //         0051dfe4     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051dfe8     PUSH       this
    //         0051dfe9     MOV        this,dword ptr [ESP + 0x20]
    //         0051dfed     LEA        EAX,[EDI + 0x1]
    //         0051dff0     PUSH       EDX=>DAT_fffffff8
    //         0051dff1     PUSH       this=>DAT_fffffff4
    //         0051dff2     LEA        EDX,[ESP + 0x2c]
    //         0051dff6     PUSH       EAX=>DAT_fffffff0
    //         0051dff7     PUSH       EDX
    //         0051dff8     MOV        dword ptr [ESP + 0x2c],EAX
    //         0051dffc     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:333 (26)
    //         0051e002     LEA        EAX,[ESP + 0x20]
    //         0051e006     PUSH       EBP
    //         0051e007     PUSH       EAX=>DAT_fffffff8
    //         0051e008     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051e00b     LEA        this,[ESP + 0x4c]
    //         0051e00f     PUSH       offset DAT_fffffff4
    //         0051e011     PUSH       this=>DAT_fffffff0
    //         0051e012     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e015     PUSH       EAX
    //         0051e016     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:335 (31)
    //         0051e01c     MOV        this,dword ptr [ESP + 0x14]
    //         0051e020     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051e024     MOV        EAX,dword ptr [ESP + 0x38]
    //         0051e028     PUSH       this
    //         0051e029     MOV        this,dword ptr [ESP + 0x1c]
    //         0051e02d     PUSH       EDX=>DAT_fffffff8
    //         0051e02e     PUSH       EAX=>DAT_fffffff4
    //         0051e02f     LEA        EDX,[ESP + 0x2c]
    //         0051e033     PUSH       this=>DAT_fffffff0
    //         0051e034     PUSH       EDX
    //         0051e035     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:336 (26)
    //         0051e03b     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051e03e     LEA        EAX,[ESP + 0x20]
    //         0051e042     PUSH       EBP
    //         0051e043     PUSH       EAX=>DAT_fffffff8
    //         0051e044     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e047     LEA        this,[ESP + 0x4c]
    //         0051e04b     PUSH       offset DAT_fffffff4
    //         0051e04d     PUSH       this=>DAT_fffffff0
    //         0051e04e     PUSH       EAX
    //         0051e04f     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:345 (20)
    //         0051e055     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051e058     MOV        this,dword ptr [ESI + 0xf8]
    //         0051e05e     PUSH       this
    //         0051e05f     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e062     PUSH       EAX=>DAT_fffffff8
    //         0051e063     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_tim.cpp:347 (25)
    //         0051e069     MOV        this,dword ptr [ESP + 0x14]
    //         0051e06d     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051e071     DEC        this
    //         0051e072     DEC        EDX
    //         0051e073     PUSH       this
    //         0051e074     PUSH       EDX=>DAT_fffffff8
    //         0051e075     PUSH       EBX=>DAT_fffffff4
    //         0051e076     LEA        EAX,[ESP + 0x2c]
    //         0051e07a     PUSH       EDI=>DAT_fffffff0
    //         0051e07b     PUSH       EAX
    //         0051e07c     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:348 (26)
    //         0051e082     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051e085     LEA        this,[ESP + 0x20]
    //         0051e089     PUSH       EBP
    //         0051e08a     PUSH       this=>DAT_fffffff8
    //         0051e08b     MOV        this,dword ptr [EAX + 0x38]
    //         0051e08e     LEA        EDX,[ESP + 0x4c]
    //         0051e092     PUSH       offset DAT_fffffff4
    //         0051e094     PUSH       EDX=>DAT_fffffff0
    //         0051e095     PUSH       this
    //         0051e096     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:354 (18)
    //         0051e09c     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051e09f     MOV        EDX,dword ptr [ESP + 0x40]
    //         0051e0a3     PUSH       EDX
    //         0051e0a4     MOV        this,dword ptr [EAX + 0x38]
    //         0051e0a7     PUSH       this=>DAT_fffffff8
    //         0051e0a8     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_tim.cpp:355 (15)
    //         0051e0ae     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051e0b1     PUSH       0x0
    //         0051e0b3     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e0b6     PUSH       EAX=>DAT_fffffff8
    //         0051e0b7     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_tim.cpp:356 (17)
    //         0051e0bd     MOV        this,dword ptr [ESI + 0x20]
    //         0051e0c0     PUSH       s_tpnl_tim::draw                                 = "tpnl_tim::draw"
    //         0051e0c5     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0051e0ca     MOV        EDI,dword ptr [ESP + 0x34]
    //                              Symbol Ref: No symbol: finish_up
    //                               LAB_0051e0ce                                                 XREF[1]:     0051ddd9(j)  
    //                              tpnl_tim.cpp:361 (8)
    //         0051e0ce     MOV        this,ESI
    //         0051e0d0     CALL       dword ptr [EDI + 0x2c]
    //         0051e0d3     POP        EBX
    //         0051e0d4     POP        EBP
    //         0051e0d5     POP        EDI
    //                               LAB_0051e0d6                                                 XREF[3]:     0051dc9e(j), 0051dca9(j), 
    //                                                                                                         0051dcb4(j)  
    //                              tpnl_tim.cpp:362 (8)
    //         0051e0d6     POP        ESI
    //         0051e0d7     ADD        ESP,0x134
    //         0051e0dd     RET
    //         0051e0de     ??         90h
    //         0051e0df     NOP
    return;
}

void TRIBE_Panel_Time::get_true_render_rect(tagRECT* param_1) {
    /* TODO: Stub */
    //                              void __thiscall get_true_render_rect(TRIBE_Panel_Time * this, tagREC
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[2]:     0051e0ff(R), 0051e122(R)  
    //                               ?get_true_render_rect@TRIBE_Panel_Time@@UAEXAAUtagRECT@@@Z   XREF[1]:     00576f60(*)  
    //                               TRIBE_Panel_Time::get_true_render_rect
    //                              tpnl_tim.cpp:370 (31)
    //         0051e0e0     MOV        EAX,dword ptr [ECX + this->ImageBuffer]
    //         0051e0e6     TEST       EAX,EAX
    //         0051e0e8     JZ         LAB_0051e122
    //         0051e0ea     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051e0ed     TEST       EAX,EAX
    //         0051e0ef     JZ         LAB_0051e122
    //         0051e0f1     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051e0f4     TEST       EAX,EAX
    //         0051e0f6     JZ         LAB_0051e122
    //         0051e0f8     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051e0fb     TEST       EAX,EAX
    //         0051e0fd     JZ         LAB_0051e122
    //                              tpnl_tim.cpp:376 (32)
    //         0051e0ff     MOV        EAX,dword ptr [ESP + param_1]
    //         0051e103     ADD        this,0x158
    //         0051e109     MOV        EDX,dword ptr [this->_padding_]
    //         0051e10b     MOV        dword ptr [EAX],EDX
    //         0051e10d     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e110     MOV        dword ptr [EAX + 0x4],EDX
    //         0051e113     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e116     MOV        dword ptr [EAX + 0x8],EDX
    //         0051e119     MOV        this,dword ptr [ECX + this->_padding_]
    //         0051e11c     MOV        dword ptr [EAX + 0xc],this
    //                              tpnl_tim.cpp:378 (3)
    //         0051e11f     RET        0x4
    //                               LAB_0051e122                                                 XREF[4]:     0051e0e8(j), 0051e0ef(j), 
    //                                                                                                         0051e0f6(j), 0051e0fd(j)  
    //                              tpnl_tim.cpp:374 (32)
    //         0051e122     MOV        EDX,dword ptr [ESP + param_1]
    //         0051e126     ADD        this,0x8c
    //         0051e12c     MOV        EAX,dword ptr [this->_padding_]
    //         0051e12e     MOV        dword ptr [EDX],EAX
    //         0051e130     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051e133     MOV        dword ptr [EDX + 0x4],EAX
    //         0051e136     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051e139     MOV        dword ptr [EDX + 0x8],EAX
    //         0051e13c     MOV        this,dword ptr [ECX + this->_padding_]
    //         0051e13f     MOV        dword ptr [EDX + 0xc],this
    //                              tpnl_tim.cpp:378 (3)
    //         0051e142     RET        0x4
    //         0051e145     ??         90h
    //         0051e146     NOP
    //         0051e147     NOP
    //         0051e148     NOP
    //         0051e149     NOP
    //         0051e14a     NOP
    //         0051e14b     NOP
    //         0051e14c     NOP
    //         0051e14d     NOP
    //         0051e14e     NOP
    //         0051e14f     NOP
    return;
}

long TRIBE_Panel_Time::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Panel_Time * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051e1e6(*), 0051e1f7(R)  
    //              long              Stack[-0x8]:4  countdown_timer
    //                               ?handle_idle@TRIBE_Panel_Time@@UAEJXZ                        XREF[1]:     00576ef4(*)  
    //                               TRIBE_Panel_Time::handle_idle
    //                              tpnl_tim.cpp:385 (4)
    //         0051e150     PUSH       this
    //         0051e151     PUSH       ESI
    //         0051e152     MOV        ESI,this
    //                              tpnl_tim.cpp:386 (5)
    //         0051e154     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              tpnl_tim.cpp:388 (22)
    //         0051e159     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051e15f     CMP        EAX,0x6
    //         0051e162     JA         switchD_0051e168::default
    //                               switchD_0051e168::switchD
    //         0051e168     JMP        dword ptr [EAX*0x4 + switchD_0051e168::switchd   = 0051e28e
    //                               switchD_0051e168::caseD_1                                    XREF[2]:     0051e168(j), 0051e298(*)  
    //                              tpnl_tim.cpp:394 (44)
    //         0051e16f     PUSH       0x18a
    //         0051e174     PUSH       s_C:\msdev\work\age1_x1\tpnl_tim.c               = 43h    C
    //         0051e179     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051e17e     MOV        EDX,dword ptr [ESI + 0x11c]
    //         0051e184     MOV        this,EAX
    //         0051e186     SUB        this,EDX
    //         0051e188     MOV        EAX,0x10624dd3
    //         0051e18d     MUL        this
    //         0051e18f     ADD        ESP,0x8
    //         0051e192     SHR        EDX,0x6
    //         0051e195     MOV        dword ptr [ESI + 0x120],EDX
    //                              tpnl_tim.cpp:395 (5)
    //         0051e19b     JMP        switchD_0051e168::default
    //                               switchD_0051e168::caseD_2                                    XREF[2]:     0051e168(j), 0051e29c(*)  
    //                              tpnl_tim.cpp:398 (23)
    //         0051e1a0     MOV        EDX,dword ptr [ESI + 0x114]
    //         0051e1a6     MOV        EAX,0x10624dd3
    //         0051e1ab     MUL        dword ptr [EDX + 0x4]
    //         0051e1ae     SHR        EDX,0x6
    //         0051e1b1     MOV        dword ptr [ESI + 0x120],EDX
    //                              tpnl_tim.cpp:399 (5)
    //         0051e1b7     JMP        switchD_0051e168::default
    //                               switchD_0051e168::caseD_3                                    XREF[2]:     0051e168(j), 0051e2a0(*)  
    //                              tpnl_tim.cpp:402 (23)
    //         0051e1bc     MOV        EAX,dword ptr [ESI + 0x114]
    //         0051e1c2     FLD        float ptr [EAX + 0x118]
    //         0051e1c8     CALL       __ftol                                           undefined __ftol()
    //         0051e1cd     MOV        dword ptr [ESI + 0x120],EAX
    //                              tpnl_tim.cpp:403 (5)
    //         0051e1d3     JMP        switchD_0051e168::default
    //                               switchD_0051e168::caseD_4                                    XREF[2]:     0051e168(j), 0051e2a4(*)  
    //                              tpnl_tim.cpp:406 (10)
    //         0051e1d8     MOV        EAX,dword ptr [ESI + 0x118]
    //         0051e1de     TEST       EAX,EAX
    //         0051e1e0     JZ         LAB_0051e255
    //                              tpnl_tim.cpp:409 (21)
    //         0051e1e2     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0051e1e6     LEA        this=>local_4,[ESP + 0x4]
    //         0051e1ea     PUSH       this
    //         0051e1eb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051e1f1     PUSH       EDX
    //         0051e1f2     CALL       RGE_Base_Game::get_countdown_timer               void get_countdown_timer(RGE_Base_Game * this
    //                              tpnl_tim.cpp:410 (4)
    //         0051e1f7     MOV        EAX,dword ptr [ESP + local_4]
    //                              tpnl_tim.cpp:425 (6)
    //         0051e1fb     MOV        dword ptr [ESI + 0x120],EAX
    //                              tpnl_tim.cpp:426 (2)
    //         0051e201     JMP        switchD_0051e168::default
    //                               switchD_0051e168::caseD_5                                    XREF[2]:     0051e168(j), 0051e2a8(*)  
    //                              tpnl_tim.cpp:417 (22)
    //         0051e203     MOV        EAX,dword ptr [ESI + 0x118]
    //         0051e209     TEST       EAX,EAX
    //         0051e20b     JZ         LAB_0051e255
    //         0051e20d     CMP        dword ptr [EAX + 0x844],0xbf800000
    //         0051e217     JZ         LAB_0051e255
    //                              tpnl_tim.cpp:418 (6)
    //         0051e219     FLD        float ptr [EAX + 0x844]
    //                              tpnl_tim.cpp:425 (11)
    //         0051e21f     CALL       __ftol                                           undefined __ftol()
    //         0051e224     MOV        dword ptr [ESI + 0x120],EAX
    //                              tpnl_tim.cpp:426 (2)
    //         0051e22a     JMP        switchD_0051e168::default
    //                               switchD_0051e168::caseD_6                                    XREF[2]:     0051e168(j), 0051e2ac(*)  
    //                              tpnl_tim.cpp:424 (22)
    //         0051e22c     MOV        EAX,dword ptr [ESI + 0x118]
    //         0051e232     TEST       EAX,EAX
    //         0051e234     JZ         LAB_0051e255
    //         0051e236     CMP        dword ptr [EAX + 0x840],0xbf800000
    //         0051e240     JZ         LAB_0051e255
    //                              tpnl_tim.cpp:425 (17)
    //         0051e242     FLD        float ptr [EAX + 0x840]
    //         0051e248     CALL       __ftol                                           undefined __ftol()
    //         0051e24d     MOV        dword ptr [ESI + 0x120],EAX
    //                              tpnl_tim.cpp:426 (2)
    //         0051e253     JMP        switchD_0051e168::default
    //                               LAB_0051e255                                                 XREF[5]:     0051e1e0(j), 0051e20b(j), 
    //                                                                                                         0051e217(j), 0051e234(j), 
    //                                                                                                         0051e240(j)  
    //                              tpnl_tim.cpp:427 (10)
    //         0051e255     MOV        dword ptr [ESI + 0x120],0x0
    //                               switchD_0051e168::default                                    XREF[7]:     0051e162(j), 0051e19b(j), 
    //                                                                                                         0051e1b7(j), 0051e1d3(j), 
    //                                                                                                         0051e201(j), 0051e22a(j), 
    //                                                                                                         0051e253(j)  
    //                              tpnl_tim.cpp:431 (16)
    //         0051e25f     MOV        this,dword ptr [ESI + 0x120]
    //         0051e265     MOV        EAX,dword ptr [ESI + 0x124]
    //         0051e26b     CMP        this,EAX
    //         0051e26d     JZ         switchD_0051e168::caseD_0
    //                              tpnl_tim.cpp:433 (9)
    //         0051e26f     MOV        EDX,dword ptr [ESI]
    //         0051e271     PUSH       0x1
    //         0051e273     MOV        this,ESI
    //         0051e275     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_tim.cpp:434 (10)
    //         0051e278     MOV        this,dword ptr [ESI + 0x40]
    //         0051e27b     PUSH       0x1
    //         0051e27d     MOV        EAX,dword ptr [this->_padding_]
    //         0051e27f     CALL       dword ptr [EAX + 0x20]
    //                              tpnl_tim.cpp:435 (12)
    //         0051e282     MOV        this,dword ptr [ESI + 0x120]
    //         0051e288     MOV        dword ptr [ESI + 0x124],this
    //                               switchD_0051e168::caseD_0                                    XREF[3]:     0051e168(j), 0051e26d(j), 
    //                                                                                                         0051e294(*)  
    //                              tpnl_tim.cpp:437 (2)
    //         0051e28e     XOR        EAX,EAX
    //                              tpnl_tim.cpp:438 (32)
    //         0051e290     POP        ESI
    //         0051e291     POP        this
    //         0051e292     RET
    //         0051e293     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0051e168::switchdataD_0051e294                       XREF[1]:     handle_idle:0051e168(*)  
    //         0051e294     addr       switchD_0051e168::caseD_0
    //         0051e298     addr       switchD_0051e168::caseD_1
    //         0051e29c     addr       switchD_0051e168::caseD_2
    //         0051e2a0     addr       switchD_0051e168::caseD_3
    //         0051e2a4     addr       switchD_0051e168::caseD_4
    //         0051e2a8     addr       switchD_0051e168::caseD_5
    //         0051e2ac     addr       switchD_0051e168::caseD_6
    return 0;
}

int TRIBE_Panel_Time::render_to_image_buffer() {
    /* TODO: Stub */
    //                              int __thiscall render_to_image_buffer(TRIBE_Panel_Time * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              char[256]         Stack[-0x104   str
    //              void *            Stack[-0x108   old_font
    //              tagRECT           Stack[-0x118   rect
    //                               ?render_to_image_buffer@TRIBE_Panel_Time@@IAEHXZ             XREF[1]:     draw:0051dd42(c)  
    //                               TRIBE_Panel_Time::render_to_image_buffer
    //                              tpnl_tim.cpp:447 (12)
    //         0051e2b0     SUB        ESP,0x114
    //         0051e2b6     PUSH       EBX
    //         0051e2b7     PUSH       EBP
    //         0051e2b8     PUSH       ESI
    //         0051e2b9     MOV        ESI,this
    //         0051e2bb     PUSH       EDI
    //                              tpnl_tim.cpp:454 (12)
    //         0051e2bc     MOV        this,dword ptr [ESI + 0x134]
    //         0051e2c2     TEST       this,this
    //         0051e2c4     JNZ        LAB_0051e2d3
    //         0051e2c6     XOR        EAX,EAX
    //                              tpnl_tim.cpp:555 (11)
    //         0051e2c8     POP        EDI
    //         0051e2c9     POP        ESI
    //         0051e2ca     POP        EBP
    //         0051e2cb     POP        EBX
    //         0051e2cc     ADD        ESP,0x114
    //         0051e2d2     RET
    //                               LAB_0051e2d3                                                 XREF[1]:     0051e2c4(j)  
    //                              tpnl_tim.cpp:459 (14)
    //         0051e2d3     LEA        EDI,[ESI + 0x138]
    //         0051e2d9     PUSH       0x1
    //         0051e2db     PUSH       EDI
    //         0051e2dc     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
    //                              tpnl_tim.cpp:463 (20)
    //         0051e2e1     MOV        this,dword ptr [ESI + 0x134]
    //         0051e2e7     PUSH       s_tpnl_tim::render_to_image_buffer               = "tpnl_tim::render_to_image_buffer"
    //         0051e2ec     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051e2f1     TEST       EAX,EAX
    //         0051e2f3     JNZ        LAB_0051e300
    //                              tpnl_tim.cpp:555 (11)
    //         0051e2f5     POP        EDI
    //         0051e2f6     POP        ESI
    //         0051e2f7     POP        EBP
    //         0051e2f8     POP        EBX
    //         0051e2f9     ADD        ESP,0x114
    //         0051e2ff     RET
    //                               LAB_0051e300                                                 XREF[1]:     0051e2f3(j)  
    //                              tpnl_tim.cpp:467 (12)
    //         0051e300     MOV        this,dword ptr [ESI + 0x134]
    //         0051e306     PUSH       EDI
    //         0051e307     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT * 
    //                              tpnl_tim.cpp:468 (23)
    //         0051e30c     MOV        this,dword ptr [ESI + 0x134]
    //         0051e312     MOV        EAX,dword ptr [ESI + 0x130]
    //         0051e318     PUSH       EAX
    //         0051e319     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e31c     PUSH       EDX
    //         0051e31d     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_tim.cpp:470 (27)
    //         0051e323     MOV        this,dword ptr [ESI + 0x134]
    //         0051e329     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0051e32f     PUSH       EAX
    //         0051e330     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e333     PUSH       EDX
    //         0051e334     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //         0051e33a     MOV        dword ptr [ESP + 0x20],EAX
    //                              tpnl_tim.cpp:471 (18)
    //         0051e33e     MOV        EAX,dword ptr [ESI + 0x134]
    //         0051e344     PUSH       0x1
    //         0051e346     MOV        this,dword ptr [EAX + 0x38]
    //         0051e349     PUSH       this
    //         0051e34a     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_tim.cpp:473 (13)
    //         0051e350     CMP        dword ptr [ESI + 0x108],0x1
    //         0051e357     JNZ        LAB_0051e3e1
    //                              tpnl_tim.cpp:475 (6)
    //         0051e35d     MOV        EDI,dword ptr [ESI + 0x120]
    //                              tpnl_tim.cpp:476 (2)
    //         0051e363     XOR        this,this
    //                              tpnl_tim.cpp:477 (2)
    //         0051e365     XOR        EBX,EBX
    //                              tpnl_tim.cpp:478 (5)
    //         0051e367     CMP        EDI,0x3b
    //         0051e36a     JLE        LAB_0051e3b1
    //                              tpnl_tim.cpp:480 (21)
    //         0051e36c     MOV        EAX,0x88888889
    //         0051e371     IMUL       EDI
    //         0051e373     MOV        this,EDX
    //         0051e375     ADD        this,EDI
    //         0051e377     SAR        this,0x5
    //         0051e37a     MOV        EDX,this
    //         0051e37c     SHR        EDX,0x1f
    //         0051e37f     ADD        this,EDX
    //                              tpnl_tim.cpp:481 (9)
    //         0051e381     MOV        EAX,this
    //         0051e383     SHL        EAX,0x4
    //         0051e386     SUB        EAX,this
    //         0051e388     NEG        EAX
    //                              tpnl_tim.cpp:482 (8)
    //         0051e38a     CMP        this,0x3b
    //         0051e38d     LEA        EDI,[EDI + EAX*0x4]
    //         0051e390     JLE        LAB_0051e3b1
    //                              tpnl_tim.cpp:484 (21)
    //         0051e392     MOV        EAX,0x88888889
    //         0051e397     IMUL       this
    //         0051e399     ADD        EDX,this
    //         0051e39b     SAR        EDX,0x5
    //         0051e39e     MOV        EAX,EDX
    //         0051e3a0     SHR        EAX,0x1f
    //         0051e3a3     ADD        EDX,EAX
    //         0051e3a5     MOV        EBX,EDX
    //                              tpnl_tim.cpp:485 (10)
    //         0051e3a7     SHL        EDX,0x4
    //         0051e3aa     SUB        EDX,EBX
    //         0051e3ac     NEG        EDX
    //         0051e3ae     LEA        this,[this->_padding_ + EDX*0x4]
    //                               LAB_0051e3b1                                                 XREF[2]:     0051e36a(j), 0051e390(j)  
    //                              tpnl_tim.cpp:488 (41)
    //         0051e3b1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051e3b6     SUB        ESP,0x8
    //         0051e3b9     MOV        EDX,dword ptr [EAX + 0x3f4]
    //         0051e3bf     LEA        EAX,[ESP + 0x2c]
    //         0051e3c3     FLD        float ptr [EDX + 0x18]
    //         0051e3c6     FSTP       double ptr [ESP]
    //         0051e3c9     PUSH       EDI
    //         0051e3ca     PUSH       this
    //         0051e3cb     PUSH       EBX
    //         0051e3cc     PUSH       s_%02ld:%02ld:%02ld_(%3.1f)                      = "%02ld:%02ld:%02ld (%3.1f)"
    //         0051e3d1     PUSH       EAX
    //         0051e3d2     CALL       sprintf                                          undefined sprintf()
    //         0051e3d7     ADD        ESP,0x1c
    //                              tpnl_tim.cpp:489 (5)
    //         0051e3da     MOV        EDI,0x20
    //                              tpnl_tim.cpp:491 (2)
    //         0051e3df     JMP        LAB_0051e459
    //                               LAB_0051e3e1                                                 XREF[1]:     0051e357(j)  
    //                              tpnl_tim.cpp:493 (16)
    //         0051e3e1     MOV        this,dword ptr [ESI + 0x120]
    //         0051e3e7     MOV        EAX,0xcccccccd
    //         0051e3ec     ADD        this,0x4
    //         0051e3ef     MUL        this
    //                              tpnl_tim.cpp:495 (21)
    //         0051e3f1     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051e3f7     SHR        EDX,0x2
    //         0051e3fa     SUB        EAX,0x4
    //         0051e3fd     LEA        this,[EDX + EDX*0x4]
    //         0051e400     JZ         LAB_0051e439
    //         0051e402     DEC        EAX
    //         0051e403     JZ         LAB_0051e424
    //         0051e405     DEC        EAX
    //                              tpnl_tim.cpp:500 (10)
    //         0051e406     PUSH       this
    //         0051e407     JZ         LAB_0051e410
    //         0051e409     PUSH       0x2c24
    //         0051e40e     JMP        LAB_0051e43f
    //                              language.dll match for 0x2c27: "Ruins: %d Years"
    //                               LAB_0051e410                                                 XREF[1]:     0051e407(j)  
    //                              tpnl_tim.cpp:499 (20)
    //         0051e410     PUSH       0x2c27
    //         0051e415     MOV        this,ESI
    //         0051e417     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051e41c     PUSH       EAX
    //         0051e41d     LEA        EAX,[ESP + 0x2c]
    //         0051e421     PUSH       EAX
    //         0051e422     JMP        LAB_0051e44c
    //                               LAB_0051e424                                                 XREF[1]:     0051e403(j)  
    //                              tpnl_tim.cpp:498 (21)
    //         0051e424     PUSH       this
    //                              language.dll match for 0x2c26: "Artifacts: %d Years"
    //         0051e425     PUSH       0x2c26
    //         0051e42a     MOV        this,ESI
    //         0051e42c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051e431     LEA        this,[ESP + 0x28]
    //         0051e435     PUSH       EAX
    //         0051e436     PUSH       this
    //         0051e437     JMP        LAB_0051e44c
    //                               LAB_0051e439                                                 XREF[1]:     0051e400(j)  
    //                              tpnl_tim.cpp:497 (27)
    //         0051e439     PUSH       this
    //                              language.dll match for 0x2c25: "Wonder: %d Years"
    //         0051e43a     PUSH       0x2c25
    //                               LAB_0051e43f                                                 XREF[1]:     0051e40e(j)  
    //         0051e43f     MOV        this,ESI
    //         0051e441     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051e446     LEA        EDX,[ESP + 0x28]
    //         0051e44a     PUSH       EAX
    //         0051e44b     PUSH       EDX
    //                               LAB_0051e44c                                                 XREF[2]:     0051e422(j), 0051e437(j)  
    //         0051e44c     CALL       sprintf                                          undefined sprintf()
    //         0051e451     ADD        ESP,0xc
    //                              tpnl_tim.cpp:503 (5)
    //         0051e454     MOV        EDI,0x22
    //                               LAB_0051e459                                                 XREF[1]:     0051e3df(j)  
    //                              tpnl_tim.cpp:506 (23)
    //         0051e459     MOV        this,dword ptr [ESI + 0x134]
    //         0051e45f     MOV        EAX,dword ptr [ESI + 0xfc]
    //         0051e465     PUSH       EAX
    //         0051e466     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e469     PUSH       EDX
    //         0051e46a     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_tim.cpp:512 (3)
    //         0051e470     MOV        EBP,dword ptr [ESI + 0x14]
    //                              tpnl_tim.cpp:513 (6)
    //         0051e473     MOV        EBX,dword ptr [ESI + 0x18]
    //         0051e476     SUB        EBP,0x2
    //                              tpnl_tim.cpp:515 (25)
    //         0051e479     DEC        EBX
    //         0051e47a     INC        EBP
    //         0051e47b     LEA        EAX,[EBX + -0x2]
    //         0051e47e     LEA        this,[EBP + -0x2]
    //         0051e481     PUSH       EAX
    //         0051e482     PUSH       this
    //         0051e483     PUSH       0x0
    //         0051e485     LEA        EAX,[ESP + 0x1c]
    //         0051e489     PUSH       0x0
    //         0051e48b     PUSH       EAX
    //         0051e48c     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:516 (29)
    //         0051e492     MOV        EAX,dword ptr [ESI + 0x134]
    //         0051e498     LEA        this,[ESP + 0x10]
    //         0051e49c     PUSH       EDI
    //         0051e49d     PUSH       this
    //         0051e49e     MOV        this,dword ptr [EAX + 0x38]
    //         0051e4a1     LEA        EDX,[ESP + 0x2c]
    //         0051e4a5     PUSH       -0x1
    //         0051e4a7     PUSH       EDX
    //         0051e4a8     PUSH       this
    //         0051e4a9     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:518 (20)
    //         0051e4af     LEA        EAX,[EBP + -0x2]
    //         0051e4b2     PUSH       EBX
    //         0051e4b3     PUSH       EAX
    //         0051e4b4     PUSH       0x2
    //         0051e4b6     LEA        EDX,[ESP + 0x1c]
    //         0051e4ba     PUSH       0x0
    //         0051e4bc     PUSH       EDX
    //         0051e4bd     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:519 (29)
    //         0051e4c3     MOV        EDX,dword ptr [ESI + 0x134]
    //         0051e4c9     LEA        EAX,[ESP + 0x10]
    //         0051e4cd     PUSH       EDI
    //         0051e4ce     PUSH       EAX
    //         0051e4cf     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e4d2     LEA        this,[ESP + 0x2c]
    //         0051e4d6     PUSH       -0x1
    //         0051e4d8     PUSH       this
    //         0051e4d9     PUSH       EAX
    //         0051e4da     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:521 (20)
    //         0051e4e0     LEA        EAX,[EBX + -0x2]
    //         0051e4e3     LEA        this,[ESP + 0x10]
    //         0051e4e7     PUSH       EAX
    //         0051e4e8     PUSH       EBP
    //         0051e4e9     PUSH       0x0
    //         0051e4eb     PUSH       0x2
    //         0051e4ed     PUSH       this
    //         0051e4ee     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:522 (29)
    //         0051e4f4     MOV        this,dword ptr [ESI + 0x134]
    //         0051e4fa     LEA        EDX,[ESP + 0x10]
    //         0051e4fe     PUSH       EDI
    //         0051e4ff     PUSH       EDX
    //         0051e500     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e503     LEA        EAX,[ESP + 0x2c]
    //         0051e507     PUSH       -0x1
    //         0051e509     PUSH       EAX
    //         0051e50a     PUSH       EDX
    //         0051e50b     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:524 (17)
    //         0051e511     PUSH       EBX
    //         0051e512     PUSH       EBP
    //         0051e513     PUSH       0x2
    //         0051e515     LEA        EAX,[ESP + 0x1c]
    //         0051e519     PUSH       0x2
    //         0051e51b     PUSH       EAX
    //         0051e51c     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:525 (29)
    //         0051e522     MOV        EAX,dword ptr [ESI + 0x134]
    //         0051e528     LEA        this,[ESP + 0x10]
    //         0051e52c     PUSH       EDI
    //         0051e52d     PUSH       this
    //         0051e52e     MOV        this,dword ptr [EAX + 0x38]
    //         0051e531     LEA        EDX,[ESP + 0x2c]
    //         0051e535     PUSH       -0x1
    //         0051e537     PUSH       EDX
    //         0051e538     PUSH       this
    //         0051e539     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:527 (23)
    //         0051e53f     MOV        EAX,dword ptr [ESI + 0x134]
    //         0051e545     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051e54b     PUSH       EDX
    //         0051e54c     MOV        this,dword ptr [EAX + 0x38]
    //         0051e54f     PUSH       this
    //         0051e550     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_tim.cpp:529 (19)
    //         0051e556     DEC        EBX
    //         0051e557     DEC        EBP
    //         0051e558     PUSH       EBX
    //         0051e559     PUSH       EBP
    //         0051e55a     PUSH       0x1
    //         0051e55c     LEA        EDX,[ESP + 0x1c]
    //         0051e560     PUSH       0x1
    //         0051e562     PUSH       EDX
    //         0051e563     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_tim.cpp:530 (29)
    //         0051e569     MOV        EDX,dword ptr [ESI + 0x134]
    //         0051e56f     LEA        EAX,[ESP + 0x10]
    //         0051e573     PUSH       EDI
    //         0051e574     PUSH       EAX
    //         0051e575     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e578     LEA        this,[ESP + 0x2c]
    //         0051e57c     PUSH       -0x1
    //         0051e57e     PUSH       this
    //         0051e57f     PUSH       EAX
    //         0051e580     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_tim.cpp:533 (21)
    //         0051e586     MOV        EDX,dword ptr [ESI + 0x134]
    //         0051e58c     MOV        this,dword ptr [ESP + 0x20]
    //         0051e590     PUSH       this
    //         0051e591     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051e594     PUSH       EAX
    //         0051e595     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_tim.cpp:534 (19)
    //         0051e59b     MOV        this,dword ptr [ESI + 0x134]
    //         0051e5a1     XOR        EDI,EDI
    //         0051e5a3     PUSH       EDI
    //         0051e5a4     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051e5a7     PUSH       EDX
    //         0051e5a8     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_tim.cpp:535 (16)
    //         0051e5ae     MOV        this,dword ptr [ESI + 0x134]
    //         0051e5b4     PUSH       s_tpnl_tim::render_to_image_buffer               = "tpnl_tim::render_to_image_buffer"
    //         0051e5b9     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //                              tpnl_tim.cpp:539 (3)
    //         0051e5be     MOV        EAX,dword ptr [ESI + 0x14]
    //                              tpnl_tim.cpp:543 (21)
    //         0051e5c1     MOV        EDX,dword ptr [ESI + 0x8c]
    //         0051e5c7     MOV        this,dword ptr [ESI + 0x18]
    //         0051e5ca     MOV        dword ptr [ESI + 0x148],EDI
    //         0051e5d0     MOV        dword ptr [ESI + 0x14c],EDI
    //                              tpnl_tim.cpp:544 (14)
    //         0051e5d6     MOV        EDI,dword ptr [ESI + 0x90]
    //         0051e5dc     DEC        EAX
    //         0051e5dd     MOV        dword ptr [ESI + 0x158],EDX
    //         0051e5e3     DEC        this
    //                              tpnl_tim.cpp:545 (14)
    //         0051e5e4     ADD        EDX,EAX
    //         0051e5e6     MOV        dword ptr [ESI + 0x15c],EDI
    //         0051e5ec     MOV        dword ptr [ESI + 0x150],EAX
    //                              tpnl_tim.cpp:548 (18)
    //         0051e5f2     MOV        EAX,dword ptr [ESI + 0x128]
    //         0051e5f8     MOV        dword ptr [ESI + 0x154],this
    //         0051e5fe     MOV        dword ptr [ESI + 0x160],EDX
    //                              tpnl_tim.cpp:550 (38)
    //         0051e604     MOV        EDX,dword ptr [ESI + 0x108]
    //         0051e60a     ADD        EDI,this
    //         0051e60c     MOV        this,dword ptr [ESI + 0x100]
    //         0051e612     MOV        dword ptr [ESI + 0x164],EDI
    //         0051e618     MOV        dword ptr [ESI + 0x12c],EAX
    //         0051e61e     MOV        dword ptr [ESI + 0x104],this
    //         0051e624     MOV        dword ptr [ESI + 0x10c],EDX
    //                              tpnl_tim.cpp:552 (10)
    //         0051e62a     MOV        dword ptr [ESI + 0x168],0x1
    //                              tpnl_tim.cpp:555 (16)
    //         0051e634     POP        EDI
    //         0051e635     POP        ESI
    //         0051e636     POP        EBP
    //         0051e637     MOV        EAX,0x1
    //         0051e63c     POP        EBX
    //         0051e63d     ADD        ESP,0x114
    //         0051e643     RET
    //         0051e644     ??         90h
    //         0051e645     NOP
    //         0051e646     NOP
    //         0051e647     NOP
    //         0051e648     NOP
    //         0051e649     NOP
    //         0051e64a     NOP
    //         0051e64b     NOP
    //         0051e64c     NOP
    //         0051e64d     NOP
    //         0051e64e     NOP
    //         0051e64f     NOP
    return 0;
}

