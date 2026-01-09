#include "common.h"
#include "rpnl_tim.h"

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* param_1, TPanel* param_2, void* param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Panel_Time(RGE_Panel_Time * this, TDrawArea
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Panel_Time    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0048a6cd(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0048a6a6(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[1]:     0048a6a2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048a6b6(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048a6f8(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048a699(W)  
    //                               ??0RGE_Panel_Time@@QAE@PAVTDrawArea@@PAVTPanel@@PAX@Z
    //                               RGE_Panel_Time::RGE_Panel_Time
    //                              rpnl_tim.cpp:30 (34)
    //         0048a680     PUSH       -0x1
    //         0048a682     PUSH       FUN_0055e798
    //         0048a687     MOV        EAX,FS:[0x0]
    //         0048a68d     PUSH       EAX
    //         0048a68e     MOV        dword ptr FS:[0x0],ESP
    //         0048a695     PUSH       this
    //         0048a696     PUSH       ESI
    //         0048a697     MOV        ESI,this
    //         0048a699     MOV        dword ptr [ESP + local_10],ESI
    //         0048a69d     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              rpnl_tim.cpp:33 (4)
    //         0048a6a2     MOV        this,dword ptr [ESP + param_3]
    //                              rpnl_tim.cpp:39 (72)
    //         0048a6a6     MOV        EDX,dword ptr [ESP + param_2]
    //         0048a6aa     XOR        EAX,EAX
    //         0048a6ac     MOV        dword ptr [ESI + 0xf4],this
    //         0048a6b2     PUSH       EAX
    //         0048a6b3     PUSH       EAX
    //         0048a6b4     PUSH       EAX
    //         0048a6b5     PUSH       EAX
    //         0048a6b6     MOV        dword ptr [ESP + local_4],EAX
    //         0048a6ba     MOV        dword ptr [ESI + 0x80],EAX
    //         0048a6c0     MOV        dword ptr [ESI + 0xf8],EAX
    //         0048a6c6     MOV        dword ptr [ESI + 0xfc],EAX
    //         0048a6cc     PUSH       EAX
    //         0048a6cd     MOV        EAX,dword ptr [ESP + param_1]
    //         0048a6d1     PUSH       EDX
    //         0048a6d2     PUSH       EAX
    //         0048a6d3     MOV        this,ESI
    //         0048a6d5     MOV        dword ptr [ESI],RGE_Panel_Time::`vftable'        = 0048a710
    //         0048a6db     MOV        dword ptr [ESI + 0x100],0xffffffff
    //         0048a6e5     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //         0048a6ea     TEST       EAX,EAX
    //         0048a6ec     JNZ        LAB_0048a6f8
    //                              rpnl_tim.cpp:40 (10)
    //         0048a6ee     MOV        dword ptr [ESI + 0xd8],0x1
    //                               LAB_0048a6f8                                                 XREF[1]:     0048a6ec(j)  
    //                              rpnl_tim.cpp:41 (20)
    //         0048a6f8     MOV        this,dword ptr [ESP + local_c]
    //         0048a6fc     MOV        EAX,ESI
    //         0048a6fe     MOV        dword ptr FS:[0x0],this
    //         0048a705     POP        ESI
    //         0048a706     ADD        ESP,0x10
    //         0048a709     RET        0xc
    //         0048a70c     ??         90h
    //         0048a70d     NOP
    //         0048a70e     NOP
    //         0048a70f     NOP
}

void RGE_Panel_Time::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(RGE_Panel_Time * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Panel_Time    ECX:4 (auto)   this
    //              char[100]         Stack[-0x68]   str
    //              tagPALETTEENTRY   Stack[-0x70]:4 paletteColor
    //              void *            Stack[-0x74]:4 old_font                  XREF[1]:     0048a76d(W)  
    //              long              Stack[-0x7c]:4 player_num
    //              long              Stack[-0x80]:4 countdown_timer
    //                               ?draw@RGE_Panel_Time@@UAEXXZ                                 XREF[1]:     00572070(*)  
    //                               RGE_Panel_Time::draw
    //                              rpnl_tim.cpp:47 (6)
    //         0048a740     SUB        ESP,0x7c
    //         0048a743     PUSH       ESI
    //         0048a744     MOV        ESI,this
    //                              rpnl_tim.cpp:52 (35)
    //         0048a746     MOV        EAX,dword ptr [ESI + 0x20]
    //         0048a749     TEST       EAX,EAX
    //         0048a74b     JZ         LAB_0048aa60
    //         0048a751     MOV        EAX,dword ptr [ESI + 0x70]
    //         0048a754     TEST       EAX,EAX
    //         0048a756     JZ         LAB_0048aa60
    //         0048a75c     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0048a75f     TEST       EAX,EAX
    //         0048a761     JZ         LAB_0048aa60
    //         0048a767     PUSH       EDI
    //         0048a768     PUSH       EBX
    //                              rpnl_tim.cpp:55 (11)
    //         0048a769     MOV        EBX,dword ptr [ESI]
    //         0048a76b     PUSH       0x0
    //         0048a76d     MOV        dword ptr [ESP + old_font],EBX
    //         0048a771     CALL       dword ptr [EBX + 0x28]
    //                              rpnl_tim.cpp:57 (6)
    //         0048a774     MOV        EDI,dword ptr [ESI + 0xe0]
    //                              rpnl_tim.cpp:59 (28)
    //         0048a77a     MOV        this,dword ptr [ESI + 0x20]
    //         0048a77d     INC        EDI
    //         0048a77e     PUSH       s_rpnl_tim::draw                                 = "rpnl_tim::draw"
    //         0048a783     MOV        dword ptr [ESI + 0xe0],EDI
    //         0048a789     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0048a78e     TEST       EAX,EAX
    //         0048a790     JZ         LAB_0048aa59
    //                              rpnl_tim.cpp:61 (21)
    //         0048a796     MOV        this,dword ptr [ESI + 0x20]
    //         0048a799     MOV        EAX,dword ptr [ESI + 0x88]
    //         0048a79f     PUSH       EBP
    //         0048a7a0     PUSH       EAX=>DAT_fffffff8
    //         0048a7a1     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a7a4     PUSH       EDX=>DAT_fffffff4
    //         0048a7a5     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              rpnl_tim.cpp:62 (20)
    //         0048a7ab     MOV        this,dword ptr [ESI + 0x20]
    //         0048a7ae     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0048a7b4     PUSH       EAX=>DAT_fffffff8
    //         0048a7b5     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a7b8     PUSH       EDX=>DAT_fffffff4
    //         0048a7b9     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              rpnl_tim.cpp:64 (19)
    //         0048a7bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a7c5     MOV        dword ptr [ESP + 0x1c],EAX
    //         0048a7c9     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0048a7ce     TEST       EAX,EAX
    //         0048a7d0     JZ         LAB_0048a84e
    //                              rpnl_tim.cpp:66 (18)
    //         0048a7d2     MOV        EAX,dword ptr [ESI + 0x20]
    //         0048a7d5     PUSH       offset DAT_fffffff8
    //         0048a7da     MOV        this,dword ptr [EAX + 0x38]
    //         0048a7dd     PUSH       this=>DAT_fffffff4
    //         0048a7de     CALL       dword ptr [->GDI32.DLL::SetBkColor]              = 0048b34c
    //                              rpnl_tim.cpp:67 (15)
    //         0048a7e4     MOV        EDX,dword ptr [ESI + 0x20]
    //         0048a7e7     PUSH       offset DAT_fffffff8
    //         0048a7e9     MOV        EAX,dword ptr [EDX + 0x38]
    //         0048a7ec     PUSH       EAX=>DAT_fffffff4
    //         0048a7ed     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              rpnl_tim.cpp:68 (18)
    //         0048a7f3     MOV        this,dword ptr [ESI + 0x20]
    //         0048a7f6     PUSH       offset DAT_fffffff8
    //         0048a7fb     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a7fe     PUSH       EDX=>DAT_fffffff4
    //         0048a7ff     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              rpnl_tim.cpp:69 (15)
    //         0048a805     LEA        EAX,[ESP + 0x28]
    //         0048a809     PUSH       s_Paused                                         = "Paused"
    //         0048a80e     PUSH       EAX=>DAT_fffffff4
    //         0048a80f     CALL       sprintf                                          undefined sprintf()
    //                              rpnl_tim.cpp:71 (53)
    //         0048a814     LEA        EDI,[ESP + 0x30]
    //         0048a818     OR         this,0xffffffff
    //         0048a81b     XOR        EAX,EAX
    //         0048a81d     ADD        ESP,0x8
    //         0048a820     SCASB.RE   ES:EDI
    //         0048a822     MOV        EDX,dword ptr [ESI + 0x90]
    //         0048a828     MOV        EAX,dword ptr [ESI + 0x8c]
    //         0048a82e     NOT        this
    //         0048a830     DEC        this
    //         0048a831     SUB        EDX,0x2
    //         0048a834     PUSH       this=>DAT_fffffff8
    //         0048a835     LEA        this,[ESP + 0x2c]
    //         0048a839     PUSH       this=>DAT_fffffff4
    //         0048a83a     MOV        this,dword ptr [ESI + 0x20]
    //         0048a83d     PUSH       EDX=>DAT_fffffff0
    //         0048a83e     PUSH       EAX
    //         0048a83f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a842     PUSH       EDX
    //         0048a843     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              rpnl_tim.cpp:73 (5)
    //         0048a849     JMP        LAB_0048aa2a
    //                               LAB_0048a84e                                                 XREF[1]:     0048a7d0(j)  
    //                              rpnl_tim.cpp:75 (15)
    //         0048a84e     MOV        EAX,dword ptr [ESI + 0x20]
    //         0048a851     PUSH       offset DAT_fffffff8
    //         0048a853     MOV        this,dword ptr [EAX + 0x38]
    //         0048a856     PUSH       this=>DAT_fffffff4
    //         0048a857     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              rpnl_tim.cpp:76 (18)
    //         0048a85d     MOV        EDX,dword ptr [ESI + 0x20]
    //         0048a860     PUSH       offset DAT_fffffff8
    //         0048a865     MOV        EAX,dword ptr [EDX + 0x38]
    //         0048a868     PUSH       EAX=>DAT_fffffff4
    //         0048a869     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              rpnl_tim.cpp:78 (6)
    //         0048a86f     MOV        EDI,dword ptr [ESI + 0xf8]
    //                              rpnl_tim.cpp:79 (2)
    //         0048a875     XOR        this,this
    //                              rpnl_tim.cpp:80 (2)
    //         0048a877     XOR        EBP,EBP
    //                              rpnl_tim.cpp:81 (5)
    //         0048a879     CMP        EDI,0x3b
    //         0048a87c     JLE        LAB_0048a8c1
    //                              rpnl_tim.cpp:83 (21)
    //         0048a87e     MOV        EAX,0x88888889
    //         0048a883     IMUL       EDI
    //         0048a885     ADD        EDX,EDI
    //         0048a887     SAR        EDX,0x5
    //         0048a88a     MOV        this,EDX
    //         0048a88c     SHR        this,0x1f
    //         0048a88f     ADD        EDX,this
    //         0048a891     MOV        this,EDX
    //                              rpnl_tim.cpp:84 (7)
    //         0048a893     SHL        EDX,0x4
    //         0048a896     SUB        EDX,this
    //         0048a898     NEG        EDX
    //                              rpnl_tim.cpp:85 (8)
    //         0048a89a     CMP        this,0x3b
    //         0048a89d     LEA        EDI,[EDI + EDX*0x4]
    //         0048a8a0     JLE        LAB_0048a8c1
    //                              rpnl_tim.cpp:87 (21)
    //         0048a8a2     MOV        EAX,0x88888889
    //         0048a8a7     IMUL       this
    //         0048a8a9     ADD        EDX,this
    //         0048a8ab     SAR        EDX,0x5
    //         0048a8ae     MOV        EAX,EDX
    //         0048a8b0     SHR        EAX,0x1f
    //         0048a8b3     ADD        EDX,EAX
    //         0048a8b5     MOV        EBP,EDX
    //                              rpnl_tim.cpp:88 (10)
    //         0048a8b7     SHL        EDX,0x4
    //         0048a8ba     SUB        EDX,EBP
    //         0048a8bc     NEG        EDX
    //         0048a8be     LEA        this,[this->_padding_ + EDX*0x4]
    //                               LAB_0048a8c1                                                 XREF[2]:     0048a87c(j), 0048a8a0(j)  
    //                              rpnl_tim.cpp:91 (38)
    //         0048a8c1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a8c6     SUB        ESP,0x8
    //         0048a8c9     MOV        EDX,dword ptr [EAX + 0x3f4]
    //         0048a8cf     LEA        EAX,[ESP + 0x30]
    //         0048a8d3     FLD        float ptr [EDX + 0x18]
    //         0048a8d6     FSTP       double ptr [ESP]=>DAT_fffffff4
    //         0048a8d9     PUSH       EDI=>DAT_fffffff0
    //         0048a8da     PUSH       this
    //         0048a8db     PUSH       EBP
    //         0048a8dc     PUSH       s_%02ld:%02ld:%02ld_(%3.1f)                      = "%02ld:%02ld:%02ld (%3.1f)"
    //         0048a8e1     PUSH       EAX
    //         0048a8e2     CALL       sprintf                                          undefined sprintf()
    //                              rpnl_tim.cpp:93 (53)
    //         0048a8e7     LEA        EDI,[ESP + 0x44]
    //         0048a8eb     OR         this,0xffffffff
    //         0048a8ee     XOR        EAX,EAX
    //         0048a8f0     ADD        ESP,0x1c
    //         0048a8f3     SCASB.RE   ES:EDI
    //         0048a8f5     MOV        EDX,dword ptr [ESI + 0x90]
    //         0048a8fb     MOV        EAX,dword ptr [ESI + 0x8c]
    //         0048a901     NOT        this
    //         0048a903     DEC        this
    //         0048a904     SUB        EDX,0x2
    //         0048a907     PUSH       this=>DAT_fffffff8
    //         0048a908     LEA        this,[ESP + 0x2c]
    //         0048a90c     PUSH       this=>DAT_fffffff4
    //         0048a90d     MOV        this,dword ptr [ESI + 0x20]
    //         0048a910     PUSH       EDX=>DAT_fffffff0
    //         0048a911     PUSH       EAX
    //         0048a912     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a915     PUSH       EDX
    //         0048a916     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              rpnl_tim.cpp:95 (5)
    //         0048a91c     MOV        EAX,[rge_base_game]                              = 00000000
    //                              rpnl_tim.cpp:97 (27)
    //         0048a921     MOV        EBP,0x1
    //         0048a926     MOV        this,dword ptr [EAX + 0x3f4]
    //         0048a92c     MOVSX      EDI,word ptr [ECX + this->_padding_]
    //         0048a930     CMP        EDI,EBP
    //         0048a932     MOV        dword ptr [ESP + 0x14],EDI
    //         0048a936     JLE        LAB_0048aa2a
    //                              rpnl_tim.cpp:91 (5)
    //         0048a93c     MOV        EBX,0xd
    //                               LAB_0048a941                                                 XREF[1]:     0048aa20(j)  
    //                              rpnl_tim.cpp:99 (17)
    //         0048a941     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a947     LEA        EDX,[ESP + 0x10]
    //         0048a94b     PUSH       EDX=>DAT_fffffff8
    //         0048a94c     PUSH       EBP=>DAT_fffffff4
    //         0048a94d     CALL       RGE_Base_Game::get_countdown_timer               void get_countdown_timer(RGE_Base_Game * this
    //                              rpnl_tim.cpp:100 (12)
    //         0048a952     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048a956     TEST       EAX,EAX
    //         0048a958     JL         LAB_0048aa1d
    //                              rpnl_tim.cpp:103 (49)
    //         0048a95e     LEA        EAX,[ESP + 0x20]
    //         0048a962     PUSH       EAX=>DAT_fffffff8
    //         0048a963     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a968     PUSH       offset DAT_fffffff4
    //         0048a96a     MOV        this,dword ptr [EAX + 0x3f4]
    //         0048a970     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a973     MOV        this,dword ptr [EDX + EBP*0x4]
    //         0048a976     MOV        EDX,dword ptr [ECX + this+0x108]
    //         0048a97c     XOR        this,this
    //         0048a97e     MOV        this,byte ptr [EDX + 0x25]
    //         0048a981     MOV        EDX,dword ptr [EAX + 0x48]
    //         0048a984     PUSH       this=>DAT_fffffff0
    //         0048a985     MOV        EAX,dword ptr [EDX + 0x8]
    //         0048a988     PUSH       EAX
    //         0048a989     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              rpnl_tim.cpp:106 (53)
    //         0048a98f     MOV        this,dword ptr [ESP + 0x22]
    //         0048a993     MOV        EDX,dword ptr [ESP + 0x21]
    //         0048a997     MOV        EAX,dword ptr [ESP + 0x20]
    //         0048a99b     AND        this,0xff
    //         0048a9a1     SHL        this,0x8
    //         0048a9a4     AND        EDX,0xff
    //         0048a9aa     AND        EAX,0xff
    //         0048a9af     OR         this,EDX
    //         0048a9b1     SHL        this,0x8
    //         0048a9b4     OR         this,EAX
    //         0048a9b6     PUSH       this=>DAT_fffffff8
    //         0048a9b7     MOV        this,dword ptr [ESI + 0x20]
    //         0048a9ba     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048a9bd     PUSH       EDX=>DAT_fffffff4
    //         0048a9be     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              rpnl_tim.cpp:121 (28)
    //         0048a9c4     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048a9c8     MOV        this,ESI
    //         0048a9ca     PUSH       EAX=>DAT_fffffff8
    //                              language.dll match for 0x2c24: "%d Years"
    //         0048a9cb     PUSH       offset DAT_fffffff4
    //         0048a9d0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0048a9d5     LEA        this,[ESP + 0x2c]
    //         0048a9d9     PUSH       EAX=>DAT_fffffff4
    //         0048a9da     PUSH       this=>DAT_fffffff0
    //         0048a9db     CALL       sprintf                                          undefined sprintf()
    //                              rpnl_tim.cpp:124 (54)
    //         0048a9e0     LEA        EDI,[ESP + 0x34]
    //         0048a9e4     OR         this,0xffffffff
    //         0048a9e7     XOR        EAX,EAX
    //         0048a9e9     ADD        ESP,0xc
    //         0048a9ec     SCASB.RE   ES:EDI
    //         0048a9ee     NOT        this
    //         0048a9f0     DEC        this
    //         0048a9f1     LEA        EDX,[ESP + 0x28]
    //         0048a9f5     PUSH       this=>DAT_fffffff8
    //         0048a9f6     MOV        this,dword ptr [ESI + 0x90]
    //         0048a9fc     MOV        EAX,EBX
    //         0048a9fe     PUSH       EDX=>DAT_fffffff4
    //         0048a9ff     MOV        EDX,dword ptr [ESI + 0x20]
    //         0048aa02     ADD        EAX,this
    //         0048aa04     MOV        this,dword ptr [ESI + 0x8c]
    //         0048aa0a     PUSH       EAX=>DAT_fffffff0
    //         0048aa0b     MOV        EAX,dword ptr [EDX + 0x38]
    //         0048aa0e     PUSH       this
    //         0048aa0f     PUSH       EAX
    //         0048aa10     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              rpnl_tim.cpp:125 (16)
    //         0048aa16     MOV        EDI,dword ptr [ESP + 0x14]
    //         0048aa1a     ADD        EBX,0xd
    //                               LAB_0048aa1d                                                 XREF[1]:     0048a958(j)  
    //         0048aa1d     INC        EBP
    //         0048aa1e     CMP        EBP,EDI
    //         0048aa20     JL         LAB_0048a941
    //                              rpnl_tim.cpp:97 (4)
    //         0048aa26     MOV        EBX,dword ptr [ESP + 0x18]
    //                               LAB_0048aa2a                                                 XREF[2]:     0048a849(j), 0048a936(j)  
    //                              rpnl_tim.cpp:130 (18)
    //         0048aa2a     MOV        EDX,dword ptr [ESI + 0x20]
    //         0048aa2d     MOV        this,dword ptr [ESP + 0x1c]
    //         0048aa31     PUSH       this=>DAT_fffffff8
    //         0048aa32     MOV        EAX,dword ptr [EDX + 0x38]
    //         0048aa35     PUSH       EAX=>DAT_fffffff4
    //         0048aa36     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              rpnl_tim.cpp:131 (15)
    //         0048aa3c     MOV        this,dword ptr [ESI + 0x20]
    //         0048aa3f     PUSH       0x0=>DAT_fffffff8
    //         0048aa41     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048aa44     PUSH       EDX=>DAT_fffffff4
    //         0048aa45     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              rpnl_tim.cpp:132 (14)
    //         0048aa4b     MOV        this,dword ptr [ESI + 0x20]
    //         0048aa4e     PUSH       s_rpnl_tim::draw                                 = "rpnl_tim::draw"
    //         0048aa53     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0048aa58     POP        EBP
    //                               LAB_0048aa59                                                 XREF[1]:     0048a790(j)  
    //                              rpnl_tim.cpp:137 (7)
    //         0048aa59     MOV        this,ESI
    //         0048aa5b     CALL       dword ptr [EBX + 0x2c]
    //         0048aa5e     POP        EBX
    //         0048aa5f     POP        EDI
    //                               LAB_0048aa60                                                 XREF[3]:     0048a74b(j), 0048a756(j), 
    //                                                                                                         0048a761(j)  
    //                              rpnl_tim.cpp:138 (5)
    //         0048aa60     POP        ESI
    //         0048aa61     ADD        ESP,0x7c
    //         0048aa64     RET
    //         0048aa65     ??         90h
    //         0048aa66     NOP
    //         0048aa67     NOP
    //         0048aa68     NOP
    //         0048aa69     NOP
    //         0048aa6a     NOP
    //         0048aa6b     NOP
    //         0048aa6c     NOP
    //         0048aa6d     NOP
    //         0048aa6e     NOP
    //         0048aa6f     NOP
    return;
}

long RGE_Panel_Time::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(RGE_Panel_Time * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Panel_Time    ECX:4 (auto)   this
    //                               ?handle_idle@RGE_Panel_Time@@UAEJXZ                          XREF[1]:     0057208c(*)  
    //                               RGE_Panel_Time::handle_idle
    //                              rpnl_tim.cpp:144 (3)
    //         0048aa70     PUSH       ESI
    //         0048aa71     MOV        ESI,this
    //                              rpnl_tim.cpp:147 (5)
    //         0048aa73     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              rpnl_tim.cpp:149 (28)
    //         0048aa78     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048aa7d     MOV        this,dword ptr [EAX + 0x3f4]
    //         0048aa83     MOV        EAX,0x10624dd3
    //         0048aa88     MUL        dword ptr [ECX + this->_padding_]
    //         0048aa8b     SHR        EDX,0x6
    //         0048aa8e     MOV        dword ptr [ESI + 0xf8],EDX
    //                              rpnl_tim.cpp:152 (23)
    //         0048aa94     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048aa9a     MOV        EAX,0x10624dd3
    //         0048aa9f     MOV        this,dword ptr [EDX + 0x3f4]
    //         0048aaa5     MUL        dword ptr [ECX + this->_padding_]
    //         0048aaa8     SHR        EDX,0x6
    //                              rpnl_tim.cpp:153 (4)
    //         0048aaab     TEST       EDX,EDX
    //         0048aaad     JLE        LAB_0048aad4
    //                              rpnl_tim.cpp:154 (11)
    //         0048aaaf     MOV        EAX,dword ptr [ESI + 0x100]
    //         0048aab5     CMP        EAX,-0x1
    //         0048aab8     JNZ        LAB_0048aacc
    //                              rpnl_tim.cpp:156 (6)
    //         0048aaba     MOV        dword ptr [ESI + 0x100],EDX
    //                              rpnl_tim.cpp:157 (10)
    //         0048aac0     MOV        dword ptr [ESI + 0x104],0x0
    //                              rpnl_tim.cpp:159 (2)
    //         0048aaca     JMP        LAB_0048aad4
    //                               LAB_0048aacc                                                 XREF[1]:     0048aab8(j)  
    //                              rpnl_tim.cpp:160 (8)
    //         0048aacc     SUB        EDX,EAX
    //         0048aace     MOV        dword ptr [ESI + 0x104],EDX
    //                               LAB_0048aad4                                                 XREF[2]:     0048aaad(j), 0048aaca(j)  
    //                              rpnl_tim.cpp:162 (16)
    //         0048aad4     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0048aada     MOV        EAX,dword ptr [ESI + 0xfc]
    //         0048aae0     CMP        EDX,EAX
    //         0048aae2     JZ         LAB_0048ab07
    //                              rpnl_tim.cpp:164 (9)
    //         0048aae4     MOV        EAX,dword ptr [ESI]
    //         0048aae6     PUSH       0x1
    //         0048aae8     MOV        this,ESI
    //         0048aaea     CALL       dword ptr [EAX + 0x20]
    //                              rpnl_tim.cpp:166 (7)
    //         0048aaed     MOV        this,dword ptr [ESI + 0x40]
    //         0048aaf0     TEST       this,this
    //         0048aaf2     JZ         LAB_0048aafb
    //                              rpnl_tim.cpp:168 (7)
    //         0048aaf4     MOV        EDX,dword ptr [this->_padding_]
    //         0048aaf6     PUSH       0x1
    //         0048aaf8     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0048aafb                                                 XREF[1]:     0048aaf2(j)  
    //                              rpnl_tim.cpp:171 (12)
    //         0048aafb     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0048ab01     MOV        dword ptr [ESI + 0xfc],EAX
    //                               LAB_0048ab07                                                 XREF[1]:     0048aae2(j)  
    //                              rpnl_tim.cpp:173 (2)
    //         0048ab07     XOR        EAX,EAX
    //                              rpnl_tim.cpp:174 (2)
    //         0048ab09     POP        ESI
    //         0048ab0a     RET
    //         0048ab0b     ??         90h
    //         0048ab0c     NOP
    //         0048ab0d     NOP
    //         0048ab0e     NOP
    //         0048ab0f     NOP
    return 0;
}

RGE_Panel_Time::~RGE_Panel_Time() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Panel_Time(RGE_Panel_Time * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Panel_Time    ECX:4 (auto)   this
    //                               ??1RGE_Panel_Time@@UAE@XZ                                    XREF[1]:     `scalar_deleting_destructor':0048a
    //                               RGE_Panel_Time::~RGE_Panel_Time
    //         0048a730     JMP        TPanel::~TPanel
    //         0048a735     ??         90h
    //         0048a736     NOP
    //         0048a737     NOP
    //         0048a738     NOP
    //         0048a739     NOP
    //         0048a73a     NOP
    //         0048a73b     NOP
    //         0048a73c     NOP
    //         0048a73d     NOP
    //         0048a73e     NOP
    //         0048a73f     NOP
}

