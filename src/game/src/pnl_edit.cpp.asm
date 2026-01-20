// Auto-generated scaffold unit: pnl_edit.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/pnl_edit.cpp
#include "../include/common.h"

// Offset: 0x004755C0
undefined TEditPanel(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TEditPanel::TEditPanel(void)                                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TEditPanel(TEditPanel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ??0TEditPanel@@QAE@XZ                                        XREF[1]:     create_edit:0046922e(c)  
    //                               TEditPanel::TEditPanel
    //                              pnl_edit.cpp:50 (8)
    //         004755c0     PUSH       ESI
    //         004755c1     MOV        ESI,this
    //         004755c3     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              pnl_edit.cpp:52 (13)
    //         004755c8     XOR        EAX,EAX
    //         004755ca     MOV        this,0x1
    //         004755cf     MOV        dword ptr [ESI + 0xf4],EAX
    //                              pnl_edit.cpp:53 (6)
    //         004755d5     MOV        dword ptr [ESI + 0xfc],EAX
    //                              pnl_edit.cpp:54 (7)
    //         004755db     MOV        word ptr [ESI + 0xf8],AX
    //                              pnl_edit.cpp:56 (6)
    //         004755e2     MOV        dword ptr [ESI + 0x108],EAX
    //                              pnl_edit.cpp:57 (6)
    //         004755e8     MOV        dword ptr [ESI + 0x110],EAX
    //                              pnl_edit.cpp:58 (6)
    //         004755ee     MOV        dword ptr [ESI + 0x114],EAX
    //                              pnl_edit.cpp:59 (6)
    //         004755f4     MOV        dword ptr [ESI + 0x118],EAX
    //                              pnl_edit.cpp:60 (6)
    //         004755fa     MOV        dword ptr [ESI + 0x11c],EAX
    //                              pnl_edit.cpp:61 (6)
    //         00475600     MOV        dword ptr [ESI + 0x120],EAX
    //                              pnl_edit.cpp:62 (6)
    //         00475606     MOV        dword ptr [ESI + 0x124],EAX
    //                              pnl_edit.cpp:63 (6)
    //         0047560c     MOV        dword ptr [ESI + 0x14c],EAX
    //                              pnl_edit.cpp:65 (6)
    //         00475612     MOV        byte ptr [ESI + 0x154],AL
    //                              pnl_edit.cpp:66 (6)
    //         00475618     MOV        byte ptr [ESI + 0x155],AL
    //                              pnl_edit.cpp:67 (6)
    //         0047561e     MOV        byte ptr [ESI + 0x156],AL
    //                              pnl_edit.cpp:68 (6)
    //         00475624     MOV        byte ptr [ESI + 0x157],AL
    //                              pnl_edit.cpp:69 (6)
    //         0047562a     MOV        byte ptr [ESI + 0x158],AL
    //                              pnl_edit.cpp:70 (6)
    //         00475630     MOV        byte ptr [ESI + 0x159],AL
    //                              pnl_edit.cpp:71 (6)
    //         00475636     MOV        dword ptr [ESI + 0x15c],EAX
    //                              pnl_edit.cpp:72 (6)
    //         0047563c     MOV        dword ptr [ESI + 0x160],EAX
    //                              pnl_edit.cpp:73 (6)
    //         00475642     MOV        dword ptr [ESI + 0x164],EAX
    //                              pnl_edit.cpp:74 (30)
    //         00475648     MOV        dword ptr [ESI + 0x168],EAX
    //         0047564e     MOV        dword ptr [ESI],TEditPanel::`vftable'            = 00475670
    //         00475654     MOV        dword ptr [ESI + 0x80],this
    //         0047565a     MOV        dword ptr [ESI + 0x104],this
    //         00475660     MOV        dword ptr [ESI + 0x150],this
    //                              pnl_edit.cpp:75 (4)
    //         00475666     MOV        EAX,ESI
    //         00475668     POP        ESI
    //         00475669     RET
}

// Offset: 0x00475690
void TEditPanel(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TEditPanel::~TEditPanel(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TEditPanel(TEditPanel * this)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004756be(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004756aa(W)  
    //                               ??1TEditPanel@@UAE@XZ                                        XREF[1]:     `vector_deleting_destructor':00475
    //                               TEditPanel::~TEditPanel
    //                              pnl_edit.cpp:83 (36)
    //         00475690     PUSH       -0x1
    //         00475692     PUSH       FUN_0055e468
    //         00475697     MOV        EAX,FS:[0x0]
    //         0047569d     PUSH       EAX
    //         0047569e     MOV        dword ptr FS:[0x0],ESP
    //         004756a5     PUSH       this
    //         004756a6     PUSH       ESI
    //         004756a7     MOV        ESI,this
    //         004756a9     PUSH       EDI
    //         004756aa     MOV        dword ptr [ESP + local_10],ESI
    //         004756ae     MOV        dword ptr [ESI],TEditPanel::`vftable'            = 00475670
    //                              pnl_edit.cpp:84 (24)
    //         004756b4     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004756ba     XOR        EDI,EDI
    //         004756bc     CMP        EAX,EDI
    //         004756be     MOV        dword ptr [ESP + local_4],EDI
    //         004756c2     JZ         LAB_004756de
    //         004756c4     CMP        dword ptr [ESI + 0x104],EDI
    //         004756ca     JNZ        LAB_004756de
    //                              pnl_edit.cpp:86 (8)
    //         004756cc     PUSH       EDI
    //         004756cd     PUSH       EAX
    //         004756ce     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
    //                              pnl_edit.cpp:87 (10)
    //         004756d4     MOV        dword ptr [ESI + 0x104],0x1
    //                               LAB_004756de                                                 XREF[2]:     004756c2(j), 004756ca(j)  
    //                              pnl_edit.cpp:90 (10)
    //         004756de     MOV        EAX,dword ptr [ESI + 0xfc]
    //         004756e4     CMP        EAX,EDI
    //         004756e6     JZ         LAB_004756f7
    //                              pnl_edit.cpp:92 (9)
    //         004756e8     PUSH       EAX
    //         004756e9     CALL       free                                             undefined free()
    //         004756ee     ADD        ESP,0x4
    //                              pnl_edit.cpp:93 (6)
    //         004756f1     MOV        dword ptr [ESI + 0xfc],EDI
    //                               LAB_004756f7                                                 XREF[1]:     004756e6(j)  
    //                              pnl_edit.cpp:95 (8)
    //         004756f7     CMP        dword ptr [ESI + 0xf4],EDI
    //         004756fd     JZ         LAB_00475748
    //                              pnl_edit.cpp:97 (10)
    //         004756ff     MOV        EAX,dword ptr [ESI + 0x160]
    //         00475705     CMP        EAX,EDI
    //         00475707     JZ         LAB_00475735
    //                              pnl_edit.cpp:99 (11)
    //         00475709     PUSH       EDI
    //         0047570a     PUSH       offset DAT_fffffff8
    //         0047570c     PUSH       offset DAT_fffffff4
    //         0047570e     PUSH       EAX=>DAT_fffffff0
    //         0047570f     CALL       _ImmNotifyIME@16                                 undefined _ImmNotifyIME@16()
    //                              pnl_edit.cpp:104 (8)
    //         00475714     CMP        dword ptr [ESI + 0x164],EDI
    //         0047571a     JZ         LAB_0047572f
    //                              pnl_edit.cpp:105 (19)
    //         0047571c     MOV        EAX,dword ptr [ESI + 0x160]
    //         00475722     MOV        this,dword ptr [ESI + 0xf4]
    //         00475728     PUSH       EAX
    //         00475729     PUSH       this=>DAT_fffffff8
    //         0047572a     CALL       _ImmReleaseContext@8                             undefined _ImmReleaseContext@8()
    //                               LAB_0047572f                                                 XREF[1]:     0047571a(j)  
    //                              pnl_edit.cpp:106 (6)
    //         0047572f     MOV        dword ptr [ESI + 0x160],EDI
    //                               LAB_00475735                                                 XREF[1]:     00475707(j)  
    //                              pnl_edit.cpp:109 (13)
    //         00475735     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0047573b     PUSH       EDX
    //         0047573c     CALL       dword ptr [->USER32.DLL::DestroyWindow]          = 0048ad26
    //                              pnl_edit.cpp:110 (8)
    //         00475742     MOV        dword ptr [ESI + 0xf4],EDI
    //                               LAB_00475748                                                 XREF[1]:     004756fd(j)  
    //         00475748     MOV        this,ESI
    //                              pnl_edit.cpp:112 (30)
    //         0047574a     MOV        dword ptr [ESP + 0x14],0xffffffff
    //         00475752     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         00475757     MOV        this,dword ptr [ESP + 0xc]
    //         0047575b     POP        EDI
    //         0047575c     MOV        dword ptr FS:[0x0],this
    //         00475763     POP        ESI
    //         00475764     ADD        ESP,0x10
    //         00475767     RET
}

// Offset: 0x00475770
long setup(TEditPanel* this_, TDrawArea* param_2, TPanel* param_3, long param_4, long param_5, long param_6, long param_7, void* param_8, short param_9, char* param_10, FormatType param_11, int param_12) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEditPanel::setup(class TDrawArea *,class TPanel *,long,long,long,long,voi... *
    //                              *********************************************************************************************************
    //                              long __thiscall setup(TEditPanel * this, TDrawArea * param_1, TPanel
    //              long              EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     004757c0(R), 004757ee(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004757b5(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     004757aa(R), 004757f8(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0047579a(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00475792(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0047578a(R)  
    //              void *            Stack[0x1c]:4  param_7                   XREF[1]:     0047578e(R)  
    //              short             Stack[0x20]:2  param_8                   XREF[1]:     00475780(R)  
    //              char *            Stack[0x24]:4  param_9
    //              FormatType        Stack[0x28]:4  param_10                  XREF[1]:     00475770(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[1]:     00475796(R)  
    //                               ?setup@TEditPanel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJPAXFPAD  XREF[1]:     create_edit:004692a5(c)  
    //                               TEditPanel::setup
    //                              pnl_edit.cpp:121 (16)
    //         00475770     MOV        EAX,dword ptr [ESP + param_10]
    //         00475774     PUSH       EBX
    //         00475775     PUSH       EBP
    //         00475776     PUSH       ESI
    //         00475777     MOV        ESI,this
    //         00475779     PUSH       EDI
    //         0047577a     MOV        dword ptr [ESI + 0x128],EAX
    //                              pnl_edit.cpp:127 (9)
    //         00475780     MOV        EAX,dword ptr [ESP + param_8]
    //         00475784     TEST       AX,AX
    //         00475787     JLE        LAB_0047578a
    //                              pnl_edit.cpp:128 (1)
    //         00475789     INC        EAX
    //                               LAB_0047578a                                                 XREF[1]:     00475787(j)  
    //                              pnl_edit.cpp:133 (69)
    //         0047578a     MOV        EDI,dword ptr [ESP + param_6]
    //         0047578e     MOV        this,dword ptr [ESP + param_7]
    //         00475792     MOV        EBP,dword ptr [ESP + param_5]
    //         00475796     MOV        EDX,dword ptr [ESP + param_11]
    //         0047579a     MOV        EBX,dword ptr [ESP + param_4]
    //         0047579e     PUSH       0xff
    //         004757a3     MOV        word ptr [ESI + 0xf8],AX
    //         004757aa     MOV        EAX,dword ptr [ESP + param_3]
    //         004757ae     PUSH       EDI
    //         004757af     MOV        dword ptr [ESI + 0x12c],this
    //         004757b5     MOV        this,dword ptr [ESP + param_2]
    //         004757b9     PUSH       EBP
    //         004757ba     MOV        dword ptr [ESI + 0x148],EDX
    //         004757c0     MOV        EDX,dword ptr [ESP + param_1]
    //         004757c4     PUSH       EBX
    //         004757c5     PUSH       EAX
    //         004757c6     PUSH       this
    //         004757c7     PUSH       EDX
    //         004757c8     MOV        this,ESI
    //         004757ca     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //                              pnl_edit.cpp:134 (4)
    //         004757cf     TEST       EAX,EAX
    //         004757d1     JNZ        LAB_004757da
    //                              pnl_edit.cpp:189 (7)
    //         004757d3     POP        EDI
    //         004757d4     POP        ESI
    //         004757d5     POP        EBP
    //         004757d6     POP        EBX
    //         004757d7     RET        0x2c
    //                               LAB_004757da                                                 XREF[1]:     004757d1(j)  
    //                              pnl_edit.cpp:150 (75)
    //         004757da     MOV        this,dword ptr [ESI + 0x20]
    //         004757dd     MOV        EAX,dword ptr [ESI + 0x128]
    //         004757e3     SUB        EAX,0x7
    //         004757e6     PUSH       0x0
    //         004757e8     MOV        EDX,dword ptr [this->_padding_]
    //         004757ea     NEG        EAX
    //         004757ec     MOV        this,dword ptr [EDX]
    //         004757ee     MOV        EDX,dword ptr [ESP + param_1]
    //         004757f2     SBB        EAX,EAX
    //         004757f4     PUSH       this
    //         004757f5     MOV        this,dword ptr [EDX + 0x4]
    //         004757f8     MOV        EDX,dword ptr [ESP + param_3]
    //         004757fc     AND        EAX,0xffe0003c
    //         00475801     PUSH       0x1
    //         00475803     ADD        EDI,-0x2
    //         00475806     ADD        EAX,0x40200044
    //         0047580b     PUSH       this
    //         0047580c     ADD        EBP,-0x2
    //         0047580f     PUSH       EDI
    //         00475810     INC        EBX
    //         00475811     PUSH       EBP
    //         00475812     INC        EDX
    //         00475813     PUSH       EBX
    //         00475814     PUSH       EDX
    //         00475815     PUSH       EAX
    //         00475816     PUSH       0x0
    //         00475818     PUSH       s_edit                                           = "edit"
    //         0047581d     PUSH       0x0
    //         0047581f     CALL       dword ptr [->USER32.DLL::CreateWindowExA]        = 0048adf6
    //                              pnl_edit.cpp:151 (12)
    //         00475825     XOR        EBX,EBX
    //         00475827     MOV        dword ptr [ESI + 0xf4],EAX
    //         0047582d     CMP        EAX,EBX
    //         0047582f     JNZ        LAB_0047583a
    //                              pnl_edit.cpp:152 (2)
    //         00475831     XOR        EAX,EAX
    //                              pnl_edit.cpp:189 (7)
    //         00475833     POP        EDI
    //         00475834     POP        ESI
    //         00475835     POP        EBP
    //         00475836     POP        EBX
    //         00475837     RET        0x2c
    //                               LAB_0047583a                                                 XREF[1]:     0047582f(j)  
    //                              pnl_edit.cpp:154 (12)
    //         0047583a     MOV        EDI,dword ptr [->USER32.DLL::SetWindowLongA]     = 0048afb0
    //         00475840     PUSH       ESI
    //         00475841     PUSH       -0x15
    //         00475843     PUSH       EAX
    //         00475844     CALL       EDI=>USER32.DLL::SetWindowLongA
    //                              pnl_edit.cpp:157 (15)
    //         00475846     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0047584c     PUSH       -0x4
    //         0047584e     PUSH       EAX
    //         0047584f     CALL       dword ptr [->USER32.DLL::GetWindowLongA]         = 0048b048
    //                              pnl_edit.cpp:158 (22)
    //         00475855     MOV        this,dword ptr [ESI + 0xf4]
    //         0047585b     PUSH       pnl_sub_wnd_proc
    //         00475860     PUSH       -0x4
    //         00475862     PUSH       this
    //         00475863     MOV        dword ptr [ESI + 0x110],EAX
    //         00475869     CALL       EDI=>USER32.DLL::SetWindowLongA
    //                              pnl_edit.cpp:160 (21)
    //         0047586b     MOVSX      EDX,word ptr [ESI + 0xf8]
    //         00475872     ADD        EDX,0x2
    //         00475875     PUSH       0x1
    //         00475877     PUSH       EDX
    //         00475878     CALL       calloc                                           undefined calloc()
    //         0047587d     ADD        ESP,0x8
    //                              pnl_edit.cpp:161 (10)
    //         00475880     CMP        EAX,EBX
    //         00475882     MOV        dword ptr [ESI + 0xfc],EAX
    //         00475888     JNZ        LAB_00475893
    //                              pnl_edit.cpp:162 (2)
    //         0047588a     XOR        EAX,EAX
    //                              pnl_edit.cpp:189 (7)
    //         0047588c     POP        EDI
    //         0047588d     POP        ESI
    //         0047588e     POP        EBP
    //         0047588f     POP        EBX
    //         00475890     RET        0x2c
    //                               LAB_00475893                                                 XREF[1]:     00475888(j)  
    //                              pnl_edit.cpp:163 (3)
    //         00475893     MOV        byte ptr [EAX],0x0
    //                              pnl_edit.cpp:165 (19)
    //         00475896     MOV        EAX,dword ptr [ESP + 0x34]
    //         0047589a     CMP        EAX,EBX
    //         0047589c     MOV        dword ptr [ESI + 0x100],EBX
    //         004758a2     JZ         LAB_004758b1
    //         004758a4     CMP        byte ptr [EAX],0x0
    //         004758a7     JZ         LAB_004758b1
    //                              pnl_edit.cpp:166 (8)
    //         004758a9     PUSH       EAX
    //         004758aa     MOV        this,ESI
    //         004758ac     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                               LAB_004758b1                                                 XREF[2]:     004758a2(j), 004758a7(j)  
    //                              pnl_edit.cpp:168 (14)
    //         004758b1     PUSH       0x4
    //         004758b3     CALL       dword ptr [->GDI32.DLL::GetStockObject]          = 0048b1b8
    //         004758b9     MOV        dword ptr [ESI + 0x108],EAX
    //                              pnl_edit.cpp:170 (11)
    //         004758bf     MOV        EAX,0xffffff
    //         004758c4     MOV        dword ptr [ESI + 0x114],EAX
    //                              pnl_edit.cpp:172 (6)
    //         004758ca     MOV        dword ptr [ESI + 0x11c],EAX
    //                              pnl_edit.cpp:175 (28)
    //         004758d0     MOV        EAX,dword ptr [ESI + 0x12c]
    //         004758d6     MOV        dword ptr [ESI + 0x124],EBX
    //         004758dc     CMP        EAX,EBX
    //         004758de     MOV        dword ptr [ESI + 0x118],EBX
    //         004758e4     MOV        dword ptr [ESI + 0x120],EBX
    //         004758ea     JZ         LAB_004758fd
    //                              pnl_edit.cpp:176 (17)
    //         004758ec     PUSH       EBX
    //         004758ed     PUSH       EAX
    //         004758ee     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004758f4     PUSH       0x30
    //         004758f6     PUSH       EAX
    //         004758f7     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_004758fd                                                 XREF[1]:     004758ea(j)  
    //                              pnl_edit.cpp:183 (19)
    //         004758fd     MOV        this,dword ptr [ESI + 0x128]
    //         00475903     MOV        dword ptr [ESI + 0x144],0x2000
    //         0047590d     SUB        this,0x7
    //                              pnl_edit.cpp:189 (31)
    //         00475910     POP        EDI
    //         00475911     NEG        this
    //         00475913     SBB        this,this
    //         00475915     MOV        EAX,0x1
    //         0047591a     AND        this,0x10
    //         0047591d     ADD        this,0x2010
    //         00475923     MOV        dword ptr [ESI + 0x144],this
    //         00475929     POP        ESI
    //         0047592a     POP        EBP
    //         0047592b     POP        EBX
    //         0047592c     RET        0x2c
}

// Offset: 0x00475930
undefined pnl_sub_wnd_proc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined pnl_sub_wnd_proc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               pnl_sub_wnd_proc                                             XREF[1]:     setup:0047585b(*)  
    //                              pnl_edit.cpp:37 (1)
    //         00475930     PUSH       ESI
    //                              pnl_edit.cpp:38 (13)
    //         00475931     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00475935     PUSH       -0x15
    //         00475937     PUSH       ESI
    //         00475938     CALL       dword ptr [->USER32.DLL::GetWindowLongA]         = 0048b048
    //                              pnl_edit.cpp:39 (4)
    //         0047593e     TEST       EAX,EAX
    //         00475940     JZ         LAB_0047595d
    //                              pnl_edit.cpp:40 (23)
    //         00475942     MOV        ECX,dword ptr [ESP + 0x14]
    //         00475946     MOV        EDX,dword ptr [ESP + 0x10]
    //         0047594a     PUSH       ECX
    //         0047594b     MOV        ECX,dword ptr [ESP + 0x10]
    //         0047594f     PUSH       EDX
    //         00475950     PUSH       ECX
    //         00475951     PUSH       ESI
    //         00475952     MOV        ECX,EAX
    //         00475954     CALL       TEditPanel::sub_wnd_proc                         long sub_wnd_proc(TEditPanel * this, void * p
    //                              pnl_edit.cpp:43 (4)
    //         00475959     POP        ESI
    //         0047595a     RET        0x10
    //                               LAB_0047595d                                                 XREF[1]:     00475940(j)  
    //                              pnl_edit.cpp:42 (2)
    //         0047595d     XOR        EAX,EAX
    //                              pnl_edit.cpp:43 (4)
    //         0047595f     POP        ESI
    //         00475960     RET        0x10
}

// Offset: 0x00475970
void set_text(TEditPanel* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_text(char *)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TEditPanel * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00475981(R)  
    //                               ?set_text@TEditPanel@@QAEXPAD@Z                              XREF[20]:    action:00441048(c), 
    //                               TEditPanel::set_text                                                      setup:004758ac(c), 
    //                                                                                                         action:00490702(c), 
    //                                                                                                         action:00490984(c), 
    //                                                                                                         action:004a1bd8(c), 
    //                                                                                                         action:004a79d0(c), 
    //                                                                                                         action:004a7a92(c), 
    //                                                                                                         set_scenario_mode:004aa258(c), 
    //                                                                                                         set_player:004ab076(c), 
    //                                                                                                         set_player:004ab0a8(c), 
    //                                                                                                         set_player:004ab0da(c), 
    //                                                                                                         set_player:004ab10c(c), 
    //                                                                                                         set_player:004ab127(c), 
    //                                                                                                         action:004abff5(c), 
    //                                                                                                         load_victory_cond_from_scenario:00
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                              pnl_edit.cpp:195 (3)
    //         00475970     PUSH       ESI
    //         00475971     MOV        ESI,this
    //                              pnl_edit.cpp:196 (14)
    //         00475973     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475979     TEST       EAX,EAX
    //         0047597b     JZ         LAB_00475a1e
    //                              pnl_edit.cpp:198 (8)
    //         00475981     MOV        EDX,dword ptr [ESP + param_1]
    //         00475985     TEST       EDX,EDX
    //         00475987     JZ         LAB_004759ed
    //                              pnl_edit.cpp:200 (31)
    //         00475989     MOVSX      this,word ptr [ESI + 0xf8]
    //         00475990     PUSH       EDI
    //         00475991     MOV        EDI,dword ptr [ESI + 0xfc]
    //         00475997     PUSH       EBP
    //         00475998     MOV        EBP,this
    //         0047599a     XOR        EAX,EAX
    //         0047599c     SHR        this,0x2
    //         0047599f     STOSD.REP  ES:EDI
    //         004759a1     MOV        this,EBP
    //         004759a3     AND        this,0x3
    //         004759a6     STOSB.REP  ES:EDI
    //                              pnl_edit.cpp:201 (22)
    //         004759a8     MOVSX      EAX,word ptr [ESI + 0xf8]
    //         004759af     MOV        this,dword ptr [ESI + 0xfc]
    //         004759b5     DEC        EAX
    //         004759b6     PUSH       EAX
    //         004759b7     PUSH       EDX
    //         004759b8     PUSH       this
    //         004759b9     CALL       strncpy                                          undefined strncpy()
    //                              pnl_edit.cpp:202 (13)
    //         004759be     MOVSX      EDX,word ptr [ESI + 0xf8]
    //         004759c5     MOV        EAX,dword ptr [ESI + 0xfc]
    //                              pnl_edit.cpp:204 (32)
    //         004759cb     OR         this,0xffffffff
    //         004759ce     ADD        ESP,0xc
    //         004759d1     MOV        byte ptr [EAX + EDX*0x1 + -0x1],0x0
    //         004759d6     MOV        EDI,dword ptr [ESI + 0xfc]
    //         004759dc     XOR        EAX,EAX
    //         004759de     POP        EBP
    //         004759df     SCASB.RE   ES:EDI
    //         004759e1     NOT        this
    //         004759e3     DEC        this
    //         004759e4     POP        EDI
    //         004759e5     MOV        dword ptr [ESI + 0x100],this
    //                              pnl_edit.cpp:206 (2)
    //         004759eb     JMP        LAB_00475a00
    //                               LAB_004759ed                                                 XREF[1]:     00475987(j)  
    //                              pnl_edit.cpp:208 (9)
    //         004759ed     MOV        this,dword ptr [ESI + 0xfc]
    //         004759f3     MOV        byte ptr [this->_padding_],0x0
    //                              pnl_edit.cpp:209 (10)
    //         004759f6     MOV        dword ptr [ESI + 0x100],0x0
    //                               LAB_00475a00                                                 XREF[1]:     004759eb(j)  
    //                              pnl_edit.cpp:211 (20)
    //         00475a00     MOV        EDX,dword ptr [ESI + 0xfc]
    //         00475a06     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475a0c     PUSH       EDX
    //         00475a0d     PUSH       EAX
    //         00475a0e     CALL       dword ptr [->USER32.DLL::SetWindowTextA]         = 0048af70
    //                              pnl_edit.cpp:212 (10)
    //         00475a14     MOV        dword ptr [ESI + 0x14c],0x0
    //                               LAB_00475a1e                                                 XREF[1]:     0047597b(j)  
    //                              pnl_edit.cpp:214 (9)
    //         00475a1e     MOV        EDX,dword ptr [ESI]
    //         00475a20     PUSH       0x1
    //         00475a22     MOV        this,ESI
    //         00475a24     CALL       dword ptr [EDX + 0x20]
    //                              pnl_edit.cpp:215 (4)
    //         00475a27     POP        ESI
    //         00475a28     RET        0x4
}

// Offset: 0x00475A30
void update_text(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::update_text(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall update_text(TEditPanel * this)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              ulong             Stack[-0x8]:4  start
    //              ulong             Stack[-0xc]:4  end
    //                               ?update_text@TEditPanel@@QAEXXZ                              XREF[11]:    get_text:00475af3(c), 
    //                               TEditPanel::update_text                                                   get_input_buffer:00475b03(c), 
    //                                                                                                         currentLine:00475b13(c), 
    //                                                                                                         set_focus:00475c31(c), 
    //                                                                                                         sub_wnd_proc:004763a2(c), 
    //                                                                                                         verify_char:0047648e(c), 
    //                                                                                                         verify_char:00476555(c), 
    //                                                                                                         verify_char:004765c4(c), 
    //                                                                                                         verify_char:004765fe(c), 
    //                                                                                                         is_blank:00476a63(c), 
    //                                                                                                         get_trimmed_str:00476abb(c)  
    //                              pnl_edit.cpp:221 (6)
    //         00475a30     SUB        ESP,0x8
    //         00475a33     PUSH       ESI
    //         00475a34     MOV        ESI,this
    //                              pnl_edit.cpp:224 (14)
    //         00475a36     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475a3c     TEST       EAX,EAX
    //         00475a3e     JZ         LAB_00475aeb
    //                              pnl_edit.cpp:228 (24)
    //         00475a44     MOVSX      this,word ptr [ESI + 0xf8]
    //         00475a4b     MOV        EDX,dword ptr [ESI + 0xfc]
    //         00475a51     INC        this
    //         00475a52     PUSH       EDI
    //         00475a53     PUSH       this
    //         00475a54     PUSH       EDX
    //         00475a55     PUSH       EAX
    //         00475a56     CALL       dword ptr [->USER32.DLL::GetWindowTextA]         = 0048aee6
    //                              pnl_edit.cpp:229 (15)
    //         00475a5c     MOV        EDX,dword ptr [ESI + 0xfc]
    //         00475a62     OR         this,0xffffffff
    //         00475a65     MOV        EDI,EDX
    //         00475a67     XOR        EAX,EAX
    //         00475a69     SCASB.RE   ES:EDI
    //                              pnl_edit.cpp:230 (21)
    //         00475a6b     MOVSX      EAX,word ptr [ESI + 0xf8]
    //         00475a72     NOT        this
    //         00475a74     DEC        this
    //         00475a75     MOV        dword ptr [ESI + 0x100],this
    //         00475a7b     MOV        byte ptr [EAX + EDX*0x1 + -0x1],0x0
    //                              pnl_edit.cpp:232 (18)
    //         00475a80     MOVSX      this,word ptr [ESI + 0xf8]
    //         00475a87     MOV        EAX,dword ptr [ESI + 0x100]
    //         00475a8d     DEC        this
    //         00475a8e     CMP        EAX,this
    //         00475a90     JLE        LAB_00475aae
    //                              pnl_edit.cpp:234 (20)
    //         00475a92     MOV        EDX,dword ptr [ESI + 0xfc]
    //         00475a98     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475a9e     PUSH       EDX
    //         00475a9f     PUSH       EAX
    //         00475aa0     CALL       dword ptr [->USER32.DLL::SetWindowTextA]         = 0048af70
    //                              pnl_edit.cpp:235 (8)
    //         00475aa6     PUSH       -0x1
    //         00475aa8     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
    //                               LAB_00475aae                                                 XREF[1]:     00475a90(j)  
    //                              pnl_edit.cpp:264 (44)
    //         00475aae     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475ab4     LEA        this,[ESP + 0x8]
    //         00475ab8     LEA        EDX,[ESP + 0xc]
    //         00475abc     PUSH       this
    //         00475abd     PUSH       EDX=>DAT_fffffff8
    //         00475abe     PUSH       offset DAT_fffffff4
    //         00475ac3     PUSH       EAX=>DAT_fffffff0
    //         00475ac4     MOV        dword ptr [ESP + 0x1c],0x0
    //         00475acc     MOV        dword ptr [ESP + 0x18],0x0
    //         00475ad4     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              pnl_edit.cpp:265 (17)
    //         00475ada     MOV        this,dword ptr [ESP + 0x8]
    //         00475ade     MOV        EAX,dword ptr [ESP + 0xc]
    //         00475ae2     SUB        this,EAX
    //         00475ae4     POP        EDI
    //         00475ae5     MOV        dword ptr [ESI + 0x14c],this
    //                               LAB_00475aeb                                                 XREF[1]:     00475a3e(j)  
    //                              pnl_edit.cpp:266 (5)
    //         00475aeb     POP        ESI
    //         00475aec     ADD        ESP,0x8
    //         00475aef     RET
}

// Offset: 0x00475AF0
char* get_text(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEditPanel::get_text(void)                                                  *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_text(TEditPanel * this)
    //              char *            EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?get_text@TEditPanel@@QAEPADXZ                               XREF[8]:     load_campaign:0048ffb6(c), 
    //                               TEditPanel::get_text                                                      load_campaign:0049000c(c), 
    //                                                                                                         make_campaign:0049014d(c), 
    //                                                                                                         action:004906b8(c), 
    //                                                                                                         action:00490758(c), 
    //                                                                                                         action:0049fa73(c), 
    //                                                                                                         action:004a7042(c), 
    //                                                                                                         action:004a7081(c)  
    //                              pnl_edit.cpp:272 (3)
    //         00475af0     PUSH       ESI
    //         00475af1     MOV        ESI,this
    //                              pnl_edit.cpp:273 (5)
    //         00475af3     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:274 (6)
    //         00475af8     MOV        EAX,dword ptr [ESI + 0xfc]
    //                              pnl_edit.cpp:275 (2)
    //         00475afe     POP        ESI
    //         00475aff     RET
}

// Offset: 0x00475B00
char* get_input_buffer(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEditPanel::get_input_buffer(void)                                          *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_input_buffer(TEditPanel * this)
    //              char *            EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?get_input_buffer@TEditPanel@@QAEPADXZ                       XREF[2]:     set_scenario_mode:004aa2df(c), 
    //                               TEditPanel::get_input_buffer                                              action:004abfa8(c)  
    //                              pnl_edit.cpp:281 (3)
    //         00475b00     PUSH       ESI
    //         00475b01     MOV        ESI,this
    //                              pnl_edit.cpp:282 (5)
    //         00475b03     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:283 (6)
    //         00475b08     MOV        EAX,dword ptr [ESI + 0xfc]
    //                              pnl_edit.cpp:284 (2)
    //         00475b0e     POP        ESI
    //         00475b0f     RET
}

// Offset: 0x00475B10
char* currentLine(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEditPanel::currentLine(void)                                               *
    //                              *********************************************************************************************************
    //                              char * __thiscall currentLine(TEditPanel * this)
    //              char *            EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?currentLine@TEditPanel@@QAEPADXZ                            XREF[30]:    action:004416ee(c), 
    //                               TEditPanel::currentLine                                                   action:00441701(c), 
    //                                                                                                         action:00441718(c), 
    //                                                                                                         action:00492449(c), 
    //                                                                                                         action:00492460(c), 
    //                                                                                                         action:0049247e(c), 
    //                                                                                                         action:0049fb1a(c), 
    //                                                                                                         action:0049fb31(c), 
    //                                                                                                         action:0049fb84(c), 
    //                                                                                                         action:004a1b9d(c), 
    //                                                                                                         action:004a1bac(c), 
    //                                                                                                         action:004a1bbc(c), 
    //                                                                                                         set_player:004aae58(c), 
    //                                                                                                         set_player:004aae9c(c), 
    //                                                                                                         set_player:004aaee1(c), 
    //                                                                                                         set_player:004aaf26(c), 
    //                                                                                                         set_player:004aaf6b(c), 
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         [more]
    //                              pnl_edit.cpp:290 (3)
    //         00475b10     PUSH       ESI
    //         00475b11     MOV        ESI,this
    //                              pnl_edit.cpp:291 (5)
    //         00475b13     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:292 (6)
    //         00475b18     MOV        EAX,dword ptr [ESI + 0xfc]
    //                              pnl_edit.cpp:293 (2)
    //         00475b1e     POP        ESI
    //         00475b1f     RET
}

// Offset: 0x00475B20
void TEditPanel::set_active(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::set_active(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_active(TEditPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00475b20(R)  
    //                               ?set_active@TEditPanel@@UAEXH@Z                              XREF[1]:     005713bc(*)  
    //                               TEditPanel::set_active
    //                              pnl_edit.cpp:299 (13)
    //         00475b20     MOV        EAX,dword ptr [ESP + param_1]
    //         00475b24     PUSH       ESI
    //         00475b25     MOV        ESI,this
    //         00475b27     PUSH       EAX
    //         00475b28     CALL       TPanel::set_active                               void set_active(TPanel * this, int param_1)
    //                              pnl_edit.cpp:301 (17)
    //         00475b2d     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475b33     TEST       EAX,EAX
    //         00475b35     JZ         LAB_00475b51
    //         00475b37     MOV        this,dword ptr [ESI + 0x6c]
    //         00475b3a     TEST       this,this
    //         00475b3c     JNZ        LAB_00475b51
    //                              pnl_edit.cpp:303 (9)
    //         00475b3e     PUSH       0x0
    //         00475b40     PUSH       EAX
    //         00475b41     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
    //                              pnl_edit.cpp:304 (10)
    //         00475b47     MOV        dword ptr [ESI + 0x104],0x1
    //                               LAB_00475b51                                                 XREF[2]:     00475b35(j), 00475b3c(j)  
    //                              pnl_edit.cpp:306 (4)
    //         00475b51     POP        ESI
    //         00475b52     RET        0x4
}

// Offset: 0x00475B60
void TEditPanel::set_focus(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::set_focus(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_focus(TEditPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00475b60(R)  
    //                               ?set_focus@TEditPanel@@UAEXH@Z                               XREF[1]:     00571468(*)  
    //                               TEditPanel::set_focus
    //                              pnl_edit.cpp:314 (17)
    //         00475b60     MOV        EAX,dword ptr [ESP + param_1]
    //         00475b64     PUSH       ESI
    //         00475b65     MOV        ESI,this
    //         00475b67     PUSH       EDI
    //         00475b68     PUSH       EAX
    //         00475b69     MOV        EDI,dword ptr [ESI + 0x78]
    //         00475b6c     CALL       TPanel::set_focus                                void set_focus(TPanel * this, int param_1)
    //                              pnl_edit.cpp:320 (14)
    //         00475b71     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475b77     TEST       EAX,EAX
    //         00475b79     JZ         LAB_00475c24
    //                              pnl_edit.cpp:322 (6)
    //         00475b7f     CALL       dword ptr [->USER32.DLL::GetFocus]               = 0048b068
    //                              pnl_edit.cpp:323 (5)
    //         00475b85     MOV        this,dword ptr [ESI + 0x78]
    //         00475b88     TEST       this,this
    //                              pnl_edit.cpp:325 (12)
    //         00475b8a     MOV        this,dword ptr [ESI + 0xf4]
    //         00475b90     JZ         LAB_00475c0f
    //         00475b92     CMP        EAX,this
    //         00475b94     JZ         LAB_00475b9d
    //                              pnl_edit.cpp:326 (7)
    //         00475b96     PUSH       this
    //         00475b97     CALL       dword ptr [->USER32.DLL::SetFocus]               = 0048acd6
    //                               LAB_00475b9d                                                 XREF[1]:     00475b94(j)  
    //                              pnl_edit.cpp:343 (10)
    //         00475b9d     MOV        EAX,dword ptr [ESI + 0x160]
    //         00475ba3     TEST       EAX,EAX
    //         00475ba5     JNZ        LAB_00475bd3
    //                              pnl_edit.cpp:345 (10)
    //         00475ba7     MOV        EAX,dword ptr [ESI + 0x164]
    //         00475bad     TEST       EAX,EAX
    //         00475baf     JZ         LAB_00475bbf
    //                              pnl_edit.cpp:346 (12)
    //         00475bb1     MOV        this,dword ptr [ESI + 0xf4]
    //         00475bb7     PUSH       this
    //         00475bb8     CALL       _ImmGetContext@4                                 undefined _ImmGetContext@4()
    //                              pnl_edit.cpp:347 (2)
    //         00475bbd     JMP        LAB_00475bcd
    //                               LAB_00475bbf                                                 XREF[1]:     00475baf(j)  
    //                              pnl_edit.cpp:348 (20)
    //         00475bbf     MOV        EDX,dword ptr [ESI + 0xf4]
    //         00475bc5     PUSH       0x0
    //         00475bc7     PUSH       EDX=>DAT_fffffff8
    //         00475bc8     CALL       _ImmAssociateContext@8                           undefined _ImmAssociateContext@8()
    //                               LAB_00475bcd                                                 XREF[1]:     00475bbd(j)  
    //         00475bcd     MOV        dword ptr [ESI + 0x160],EAX
    //                               LAB_00475bd3                                                 XREF[1]:     00475ba5(j)  
    //                              pnl_edit.cpp:351 (20)
    //         00475bd3     MOV        EAX,dword ptr [ESI + 0x160]
    //         00475bd9     TEST       EAX,EAX
    //         00475bdb     JZ         LAB_00475c24
    //         00475bdd     MOV        this,dword ptr [ESI + 0x164]
    //         00475be3     TEST       this,this
    //         00475be5     JZ         LAB_00475c24
    //                              pnl_edit.cpp:353 (10)
    //         00475be7     MOV        this,dword ptr [ESI + 0x168]
    //         00475bed     TEST       this,this
    //         00475bef     JZ         LAB_00475c00
    //                              pnl_edit.cpp:354 (13)
    //         00475bf1     PUSH       0x1
    //         00475bf3     PUSH       EAX=>DAT_fffffff8
    //         00475bf4     CALL       _ImmSetOpenStatus@8                              undefined _ImmSetOpenStatus@8()
    //         00475bf9     MOV        [imc_retval],EAX
    //                              pnl_edit.cpp:355 (2)
    //         00475bfe     JMP        LAB_00475c24
    //                               LAB_00475c00                                                 XREF[1]:     00475bef(j)  
    //                              pnl_edit.cpp:356 (13)
    //         00475c00     PUSH       0x0
    //         00475c02     PUSH       EAX=>DAT_fffffff8
    //         00475c03     CALL       _ImmSetOpenStatus@8                              undefined _ImmSetOpenStatus@8()
    //         00475c08     MOV        [imc_retval],EAX
    //                              pnl_edit.cpp:359 (2)
    //         00475c0d     JMP        LAB_00475c24
    //                               LAB_00475c0f                                                 XREF[1]:     00475b90(j)  
    //                              pnl_edit.cpp:361 (14)
    //         00475c0f     CMP        EAX,this
    //         00475c11     JNZ        LAB_00475c24
    //         00475c13     MOV        this,dword ptr [ESI + 0x20]
    //         00475c16     MOV        this,dword ptr [ECX + this->_padding_]
    //         00475c19     CMP        EAX,this
    //         00475c1b     JZ         LAB_00475c24
    //                              pnl_edit.cpp:362 (7)
    //         00475c1d     PUSH       this
    //         00475c1e     CALL       dword ptr [->USER32.DLL::SetFocus]               = 0048acd6
    //                               LAB_00475c24                                                 XREF[7]:     00475b79(j), 00475bdb(j), 
    //                                                                                                         00475be5(j), 00475bfe(j), 
    //                                                                                                         00475c0d(j), 00475c11(j), 
    //                                                                                                         00475c1b(j)  
    //                              pnl_edit.cpp:376 (11)
    //         00475c24     TEST       EDI,EDI
    //         00475c26     JZ         LAB_00475c3f
    //         00475c28     MOV        EAX,dword ptr [ESI + 0x78]
    //         00475c2b     TEST       EAX,EAX
    //         00475c2d     JNZ        LAB_00475c3f
    //                              pnl_edit.cpp:378 (7)
    //         00475c2f     MOV        this,ESI
    //         00475c31     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:379 (9)
    //         00475c36     MOV        EDX,dword ptr [ESI]
    //         00475c38     PUSH       0x1
    //         00475c3a     MOV        this,ESI
    //         00475c3c     CALL       dword ptr [EDX + 0x20]
    //                               LAB_00475c3f                                                 XREF[2]:     00475c26(j), 00475c2d(j)  
    //                              pnl_edit.cpp:382 (31)
    //         00475c3f     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475c45     TEST       EAX,EAX
    //         00475c47     JZ         LAB_00475c6d
    //         00475c49     MOV        this,dword ptr [ESI + 0x78]
    //         00475c4c     TEST       this,this
    //         00475c4e     JZ         LAB_00475c6d
    //         00475c50     TEST       EDI,EDI
    //         00475c52     JNZ        LAB_00475c6d
    //         00475c54     MOV        this,dword ptr [ESI + 0x148]
    //         00475c5a     TEST       this,this
    //         00475c5c     JZ         LAB_00475c6d
    //                              pnl_edit.cpp:384 (15)
    //         00475c5e     PUSH       -0x1
    //         00475c60     PUSH       EDI=>DAT_fffffff8
    //         00475c61     PUSH       offset DAT_fffffff4
    //         00475c66     PUSH       EAX=>DAT_fffffff0
    //         00475c67     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_00475c6d                                                 XREF[4]:     00475c47(j), 00475c4e(j), 
    //                                                                                                         00475c52(j), 00475c5c(j)  
    //                              pnl_edit.cpp:387 (36)
    //         00475c6d     MOV        EAX,[DAT_0086b240]
    //         00475c72     TEST       EAX,EAX
    //         00475c74     JNZ        LAB_00475ca4
    //         00475c76     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475c7c     TEST       EAX,EAX
    //         00475c7e     JZ         LAB_00475ca4
    //         00475c80     MOV        this,dword ptr [ESI + 0x78]
    //         00475c83     TEST       this,this
    //         00475c85     JNZ        LAB_00475ca4
    //         00475c87     MOV        this,dword ptr [ESI + 0x104]
    //         00475c8d     TEST       this,this
    //         00475c8f     JNZ        LAB_00475ca4
    //                              pnl_edit.cpp:389 (9)
    //         00475c91     PUSH       0x0
    //         00475c93     PUSH       EAX=>DAT_fffffff8
    //         00475c94     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
    //                              pnl_edit.cpp:390 (10)
    //         00475c9a     MOV        dword ptr [ESI + 0x104],0x1
    //                               LAB_00475ca4                                                 XREF[4]:     00475c74(j), 00475c7e(j), 
    //                                                                                                         00475c85(j), 00475c8f(j)  
    //                              pnl_edit.cpp:393 (7)
    //         00475ca4     MOV        EAX,dword ptr [ESI + 0x78]
    //         00475ca7     TEST       EAX,EAX
    //         00475ca9     JZ         LAB_00475cb5
    //                              pnl_edit.cpp:394 (10)
    //         00475cab     MOV        dword ptr [DAT_0086b244],0x0
    //                               LAB_00475cb5                                                 XREF[1]:     00475ca9(j)  
    //                              pnl_edit.cpp:395 (5)
    //         00475cb5     POP        EDI
    //         00475cb6     POP        ESI
    //         00475cb7     RET        0x4
}

// Offset: 0x00475CC0
void TEditPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::set_rect(long,long,long,long)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall set_rect(TEditPanel * this, long param_1, long param
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00475cd1(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00475cc4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00475ccb(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00475cc0(R)  
    //                               ?set_rect@TEditPanel@@UAEXJJJJ@Z                             XREF[1]:     005713b4(*)  
    //                               TEditPanel::set_rect
    //                              pnl_edit.cpp:401 (31)
    //         00475cc0     MOV        EAX,dword ptr [ESP + param_4]
    //         00475cc4     MOV        EDX,dword ptr [ESP + param_2]
    //         00475cc8     PUSH       ESI
    //         00475cc9     MOV        ESI,this
    //         00475ccb     MOV        this,dword ptr [ESP + param_3]
    //         00475ccf     PUSH       EDI
    //         00475cd0     PUSH       EAX
    //         00475cd1     MOV        EAX,dword ptr [ESP + param_1]
    //         00475cd5     PUSH       this
    //         00475cd6     PUSH       EDX
    //         00475cd7     PUSH       EAX
    //         00475cd8     MOV        this,ESI
    //         00475cda     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
    //                              pnl_edit.cpp:404 (10)
    //         00475cdf     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00475ce5     TEST       EDI,EDI
    //         00475ce7     JZ         LAB_00475d35
    //                              pnl_edit.cpp:405 (76)
    //         00475ce9     MOV        EAX,dword ptr [ESI + 0x104]
    //         00475cef     TEST       EAX,EAX
    //         00475cf1     JNZ        LAB_00475d08
    //         00475cf3     MOV        EAX,dword ptr [ESI + 0x70]
    //         00475cf6     TEST       EAX,EAX
    //         00475cf8     JZ         LAB_00475d08
    //         00475cfa     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00475cfd     TEST       EAX,EAX
    //         00475cff     JZ         LAB_00475d08
    //         00475d01     MOV        EDX,0x1
    //         00475d06     JMP        LAB_00475d0a
    //                               LAB_00475d08                                                 XREF[3]:     00475cf1(j), 00475cf8(j), 
    //                                                                                                         00475cff(j)  
    //         00475d08     XOR        EDX,EDX
    //                               LAB_00475d0a                                                 XREF[1]:     00475d06(j)  
    //         00475d0a     MOV        EAX,dword ptr [ESI + 0x15c]
    //         00475d10     PUSH       EDX
    //         00475d11     MOV        EDX,dword ptr [ESI + 0x18]
    //         00475d14     LEA        this,[EAX + EAX*0x1]
    //         00475d17     SUB        EDX,this
    //         00475d19     DEC        EDX
    //         00475d1a     PUSH       EDX
    //         00475d1b     MOV        EDX,dword ptr [ESI + 0x14]
    //         00475d1e     SUB        EDX,this
    //         00475d20     MOV        this,dword ptr [ESI + 0x10]
    //         00475d23     DEC        EDX
    //         00475d24     ADD        this,EAX
    //         00475d26     PUSH       EDX
    //         00475d27     MOV        EDX,dword ptr [ESI + 0xc]
    //         00475d2a     ADD        EDX,EAX
    //         00475d2c     PUSH       this
    //         00475d2d     PUSH       EDX
    //         00475d2e     PUSH       EDI
    //         00475d2f     CALL       dword ptr [->USER32.DLL::MoveWindow]             = 0048b074
    //                               LAB_00475d35                                                 XREF[1]:     00475ce7(j)  
    //                              pnl_edit.cpp:407 (6)
    //         00475d35     MOV        EAX,dword ptr [ESI + 0x128]
    //                              pnl_edit.cpp:409 (21)
    //         00475d3b     MOV        this,dword ptr [ESI + 0x8c]
    //         00475d41     CMP        EAX,0x7
    //         00475d44     MOV        EAX,dword ptr [ESI + 0x15c]
    //         00475d4a     JNZ        LAB_00475d92
    //         00475d4c     LEA        EDX,[ECX + EAX*this+0x1 + 0x1]
    //                              pnl_edit.cpp:410 (8)
    //         00475d50     MOV        this,dword ptr [ESI + 0x90]
    //         00475d56     ADD        this,EAX
    //                              pnl_edit.cpp:411 (32)
    //         00475d58     PUSH       0x15
    //         00475d5a     MOV        dword ptr [ESI + 0x134],EDX
    //         00475d60     MOV        dword ptr [ESI + 0x138],this
    //         00475d66     MOV        EDI,EAX
    //         00475d68     CALL       dword ptr [->USER32.DLL::GetSystemMetrics]       = 0048ae08
    //         00475d6e     MOV        EDX,dword ptr [ESI + 0x94]
    //         00475d74     SUB        EDX,EDI
    //         00475d76     SUB        EDX,EAX
    //                              pnl_edit.cpp:412 (21)
    //         00475d78     MOV        EAX,dword ptr [ESI + 0x98]
    //         00475d7e     DEC        EDX
    //         00475d7f     SUB        EAX,EDI
    //         00475d81     MOV        dword ptr [ESI + 0x13c],EDX
    //         00475d87     MOV        dword ptr [ESI + 0x140],EAX
    //                              pnl_edit.cpp:421 (5)
    //         00475d8d     POP        EDI
    //         00475d8e     POP        ESI
    //         00475d8f     RET        0x10
    //                               LAB_00475d92                                                 XREF[1]:     00475d4a(j)  
    //                              pnl_edit.cpp:416 (4)
    //         00475d92     LEA        EDX,[ECX + EAX*0x1 + this->_padding_]
    //                              pnl_edit.cpp:417 (14)
    //         00475d96     MOV        this,dword ptr [ESI + 0x90]
    //         00475d9c     ADD        this,EAX
    //         00475d9e     MOV        dword ptr [ESI + 0x134],EDX
    //                              pnl_edit.cpp:418 (12)
    //         00475da4     MOV        EDX,dword ptr [ESI + 0x94]
    //         00475daa     MOV        dword ptr [ESI + 0x138],this
    //                              pnl_edit.cpp:419 (22)
    //         00475db0     MOV        this,dword ptr [ESI + 0x98]
    //         00475db6     SUB        EDX,EAX
    //         00475db8     SUB        this,EAX
    //         00475dba     MOV        dword ptr [ESI + 0x13c],EDX
    //         00475dc0     MOV        dword ptr [ESI + 0x140],this
    //                              pnl_edit.cpp:421 (5)
    //         00475dc6     POP        EDI
    //         00475dc7     POP        ESI
    //         00475dc8     RET        0x10
}

// Offset: 0x00475DD0
void TEditPanel::set_redraw(RedrawMode param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::set_redraw(enum TPanel::RedrawMode)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_redraw(TEditPanel * this, RedrawMode param_1)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              RedrawMode        Stack[0x4]:4   param_1                   XREF[1]:     00475de1(R)  
    //                               ?set_redraw@TEditPanel@@UAEXW4RedrawMode@TPanel@@@Z          XREF[1]:     005713c8(*)  
    //                               TEditPanel::set_redraw
    //                              pnl_edit.cpp:427 (3)
    //         00475dd0     PUSH       ESI
    //         00475dd1     MOV        ESI,this
    //                              pnl_edit.cpp:428 (7)
    //         00475dd3     PUSH       0x1
    //         00475dd5     CALL       TPanel::set_redraw                               void set_redraw(TPanel * this, RedrawMode par
    //                              pnl_edit.cpp:429 (35)
    //         00475dda     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00475ddd     TEST       EAX,EAX
    //         00475ddf     JZ         LAB_00475e08
    //         00475de1     MOV        EAX,dword ptr [ESP + param_1]
    //         00475de5     TEST       EAX,EAX
    //         00475de7     JZ         LAB_00475e08
    //         00475de9     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475def     TEST       EAX,EAX
    //         00475df1     JZ         LAB_00475e08
    //         00475df3     MOV        this,dword ptr [ESI + 0x104]
    //         00475df9     TEST       this,this
    //         00475dfb     JNZ        LAB_00475e08
    //                              pnl_edit.cpp:430 (11)
    //         00475dfd     PUSH       0x1
    //         00475dff     PUSH       0x0
    //         00475e01     PUSH       EAX
    //         00475e02     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                               LAB_00475e08                                                 XREF[4]:     00475ddf(j), 00475de7(j), 
    //                                                                                                         00475df1(j), 00475dfb(j)  
    //                              pnl_edit.cpp:431 (4)
    //         00475e08     POP        ESI
    //         00475e09     RET        0x4
}

// Offset: 0x00475E10
void set_text_color(TEditPanel* this_, ulong param_2, ulong param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_text_color(unsigned long,unsigned long)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_color(TEditPanel * this, ulong param_1, ulo
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00475e10(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00475e14(R)  
    //                               ?set_text_color@TEditPanel@@QAEXKK@Z                         XREF[1]:     create_edit:0046930b(c)  
    //                               TEditPanel::set_text_color
    //                              pnl_edit.cpp:437 (4)
    //         00475e10     MOV        EAX,dword ptr [ESP + param_1]
    //                              pnl_edit.cpp:439 (10)
    //         00475e14     MOV        EDX,dword ptr [ESP + param_2]
    //         00475e18     MOV        dword ptr [ECX + this->text_color1],EAX
    //                              pnl_edit.cpp:440 (13)
    //         00475e1e     MOV        EAX,dword ptr [this->_padding_]
    //         00475e20     PUSH       0x1
    //         00475e22     MOV        dword ptr [ECX + this->text_color2],EDX
    //         00475e28     CALL       dword ptr [EAX + 0x20]
    //                              pnl_edit.cpp:441 (3)
    //         00475e2b     RET        0x8
}

// Offset: 0x00475E30
void set_highlight_text_color(TEditPanel* this_, ulong param_2, ulong param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_highlight_text_color(unsigned long,unsigned long)             *
    //                              *********************************************************************************************************
    //                              void __thiscall set_highlight_text_color(TEditPanel * this, ulong pa
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1
    //              ulong             Stack[0x8]:4   param_2
    //                               ?set_highlight_text_color@TEditPanel@@QAEXKK@Z               XREF[1]:     create_edit:00469320(c)  
    //                               TEditPanel::set_highlight_text_color
    //                              pnl_edit.cpp:447 (3)
    //         00475e30     RET        0x8
}

// Offset: 0x00475E40
void set_back_color(TEditPanel* this_, void* param_2, ulong param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_back_color(void *,unsigned long,unsigned char)                *
    //                              *********************************************************************************************************
    //                              void __thiscall set_back_color(TEditPanel * this, void * param_1, ul
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1
    //              ulong             Stack[0x8]:4   param_2
    //              uchar             Stack[0xc]:1   param_3
    //                               ?set_back_color@TEditPanel@@QAEXPAXKE@Z                      XREF[1]:     create_edit:0046933c(c)  
    //                               TEditPanel::set_back_color
    //                              pnl_edit.cpp:460 (3)
    //         00475e40     RET        0xc
}

// Offset: 0x00475E50
void set_bevel_info(TEditPanel* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_bevel_info(int,int,int,int,int,int,int)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_bevel_info(TEditPanel * this, int param_1, int p
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00475e54(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00475e5b(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00475e50(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00475e66(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00475e70(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00475e80(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00475e8a(R)  
    //                               ?set_bevel_info@TEditPanel@@QAEXHHHHHHH@Z                    XREF[1]:     create_edit:004692f6(c)  
    //                               TEditPanel::set_bevel_info
    //                              pnl_edit.cpp:474 (22)
    //         00475e50     MOV        DL,byte ptr [ESP + param_3]
    //         00475e54     MOV        EAX,dword ptr [ESP + param_1]
    //         00475e58     PUSH       ESI
    //         00475e59     MOV        ESI,this
    //         00475e5b     MOV        this,byte ptr [ESP + param_2]
    //         00475e5f     PUSH       EDI
    //         00475e60     MOV        byte ptr [ESI + 0x154],this
    //                              pnl_edit.cpp:478 (10)
    //         00475e66     MOV        this,byte ptr [ESP + param_4]
    //         00475e6a     MOV        byte ptr [ESI + 0x155],DL
    //                              pnl_edit.cpp:479 (16)
    //         00475e70     MOV        DL,byte ptr [ESP + param_5]
    //         00475e74     MOV        dword ptr [ESI + 0x150],EAX
    //         00475e7a     MOV        byte ptr [ESI + 0x156],this
    //                              pnl_edit.cpp:480 (10)
    //         00475e80     MOV        this,byte ptr [ESP + param_6]
    //         00475e84     MOV        byte ptr [ESI + 0x157],DL
    //                              pnl_edit.cpp:481 (4)
    //         00475e8a     MOV        DL,byte ptr [ESP + param_7]
    //                              pnl_edit.cpp:483 (25)
    //         00475e8e     DEC        EAX
    //         00475e8f     CMP        EAX,0x6
    //         00475e92     MOV        byte ptr [ESI + 0x158],this
    //         00475e98     MOV        byte ptr [ESI + 0x159],DL
    //         00475e9e     JA         switchD_00475ea0::default
    //                               switchD_00475ea0::switchD
    //         00475ea0     JMP        dword ptr [EAX*0x4 + switchD_00475ea0::switchd   = 00475ea7
    //                               switchD_00475ea0::caseD_2                                    XREF[4]:     00475ea0(j), 00475ef8(*), 
    //                               switchD_00475ea0::caseD_5                                                 00475efc(*), 00475f08(*)  
    //                               switchD_00475ea0::caseD_1
    //                              pnl_edit.cpp:488 (10)
    //         00475ea7     MOV        dword ptr [ESI + 0x15c],0x1
    //                              pnl_edit.cpp:489 (2)
    //         00475eb1     JMP        LAB_00475ed5
    //                               switchD_00475ea0::caseD_6                                    XREF[3]:     00475ea0(j), 00475f00(*), 
    //                               switchD_00475ea0::caseD_3                                                 00475f0c(*)  
    //                              pnl_edit.cpp:493 (10)
    //         00475eb3     MOV        dword ptr [ESI + 0x15c],0x2
    //                              pnl_edit.cpp:494 (2)
    //         00475ebd     JMP        LAB_00475ed5
    //                               switchD_00475ea0::caseD_7                                    XREF[3]:     00475ea0(j), 00475f04(*), 
    //                               switchD_00475ea0::caseD_4                                                 00475f10(*)  
    //                              pnl_edit.cpp:498 (10)
    //         00475ebf     MOV        dword ptr [ESI + 0x15c],0x3
    //                              pnl_edit.cpp:499 (2)
    //         00475ec9     JMP        LAB_00475ed5
    //                               switchD_00475ea0::default                                    XREF[1]:     00475e9e(j)  
    //                              pnl_edit.cpp:502 (10)
    //         00475ecb     MOV        dword ptr [ESI + 0x15c],0x0
    //                               LAB_00475ed5                                                 XREF[3]:     00475eb1(j), 00475ebd(j), 
    //                                                                                                         00475ec9(j)  
    //                              pnl_edit.cpp:506 (23)
    //         00475ed5     MOV        EAX,dword ptr [ESI + 0x18]
    //         00475ed8     MOV        this,dword ptr [ESI + 0x14]
    //         00475edb     MOV        EDX,dword ptr [ESI + 0x10]
    //         00475ede     MOV        EDI,dword ptr [ESI]
    //         00475ee0     PUSH       EAX
    //         00475ee1     MOV        EAX,dword ptr [ESI + 0xc]
    //         00475ee4     PUSH       this
    //         00475ee5     PUSH       EDX
    //         00475ee6     PUSH       EAX
    //         00475ee7     MOV        this,ESI
    //         00475ee9     CALL       dword ptr [EDI + 0xc]
    //                              pnl_edit.cpp:508 (7)
    //         00475eec     PUSH       0x1
    //         00475eee     MOV        this,ESI
    //         00475ef0     CALL       dword ptr [EDI + 0x20]
    //                              pnl_edit.cpp:509 (33)
    //         00475ef3     POP        EDI
    //         00475ef4     POP        ESI
    //         00475ef5     RET        0x1c
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00475ea0::switchdataD_00475ef8                       XREF[1]:     set_bevel_info:00475ea0(*)  
}

// Offset: 0x00475F20
void set_ime_info(TEditPanel* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEditPanel::set_ime_info(int,int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall set_ime_info(TEditPanel * this, int param_1, int par
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00475f20(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00475f24(R)  
    //                               ?set_ime_info@TEditPanel@@QAEXHH@Z                           XREF[1]:     create_edit:0046934d(c)  
    //                               TEditPanel::set_ime_info
    //                              pnl_edit.cpp:515 (4)
    //         00475f20     MOV        EAX,dword ptr [ESP + param_1]
    //                              pnl_edit.cpp:517 (16)
    //         00475f24     MOV        EDX,dword ptr [ESP + param_2]
    //         00475f28     MOV        dword ptr [ECX + this->enable_ime],EAX
    //         00475f2e     MOV        dword ptr [ECX + this->turn_ime_on],EDX
    //                              pnl_edit.cpp:518 (3)
    //         00475f34     RET        0x8
}

// Offset: 0x00475F40
long TEditPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TEditPanel::wnd_proc(void *,unsigned int,unsigned int,long)           *
    //                              *********************************************************************************************************
    //                              long __thiscall wnd_proc(TEditPanel * this, void * param_1, uint par
    //              long              EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[2]:     00475ffd(R), 0047601b(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     00475f46(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[2]:     00475f42(R), 00476017(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[2]:     00475f4e(R), 00476013(R)  
    //                               ?wnd_proc@TEditPanel@@UAEJPAXIIJ@Z                           XREF[1]:     005713f0(*)  
    //                               TEditPanel::wnd_proc
    //                              pnl_edit.cpp:524 (2)
    //         00475f40     PUSH       EBX
    //         00475f41     PUSH       EBP
    //                              pnl_edit.cpp:529 (62)
    //         00475f42     MOV        EBP,dword ptr [ESP + param_3]
    //         00475f46     MOV        EBX,dword ptr [ESP + param_2]
    //         00475f4a     PUSH       ESI
    //         00475f4b     MOV        ESI,this
    //         00475f4d     PUSH       EDI
    //         00475f4e     MOV        EDI,dword ptr [ESP + param_4]
    //         00475f52     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00475f58     TEST       EAX,EAX
    //         00475f5a     JZ         LAB_00475ffd
    //         00475f60     MOV        this,dword ptr [ESI + 0x6c]
    //         00475f63     TEST       this,this
    //         00475f65     JZ         LAB_00475ffd
    //         00475f6b     MOV        this,dword ptr [ESI + 0x70]
    //         00475f6e     TEST       this,this
    //         00475f70     JZ         LAB_00475ffd
    //         00475f76     MOV        this,dword ptr [ESI + 0x104]
    //         00475f7c     TEST       this,this
    //         00475f7e     JNZ        LAB_00475ffd
    //                              pnl_edit.cpp:531 (24)
    //         00475f80     MOV        this,EBX
    //         00475f82     SUB        this,0x7
    //         00475f85     JZ         LAB_00476013
    //         00475f8b     SUB        this,0x10a
    //         00475f91     JZ         LAB_00475fe2
    //         00475f93     SUB        this,0x22
    //         00475f96     JNZ        LAB_00475ffd
    //                              pnl_edit.cpp:551 (10)
    //         00475f98     MOV        this,dword ptr [ESI + 0x108]
    //         00475f9e     TEST       this,this
    //         00475fa0     JZ         LAB_00475ffd
    //                              pnl_edit.cpp:554 (12)
    //         00475fa2     MOV        this,EDI
    //         00475fa4     AND        this,0xffff
    //         00475faa     CMP        this,EAX
    //         00475fac     JNZ        LAB_00475ffd
    //                              pnl_edit.cpp:557 (16)
    //         00475fae     MOV        EDX,dword ptr [ESI + 0x124]
    //         00475fb4     MOV        EDI,EBP
    //         00475fb6     PUSH       EDX
    //         00475fb7     PUSH       EDI
    //         00475fb8     CALL       dword ptr [->GDI32.DLL::SetBkColor]              = 0048b34c
    //                              pnl_edit.cpp:558 (9)
    //         00475fbe     PUSH       0x2
    //         00475fc0     PUSH       EDI
    //         00475fc1     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              pnl_edit.cpp:559 (14)
    //         00475fc7     MOV        EAX,dword ptr [ESI + 0x11c]
    //         00475fcd     PUSH       EAX
    //         00475fce     PUSH       EDI
    //         00475fcf     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              pnl_edit.cpp:560 (6)
    //         00475fd5     MOV        EAX,dword ptr [ESI + 0x108]
    //                              pnl_edit.cpp:598 (7)
    //         00475fdb     POP        EDI
    //         00475fdc     POP        ESI
    //         00475fdd     POP        EBP
    //         00475fde     POP        EBX
    //         00475fdf     RET        0x10
    //                               LAB_00475fe2                                                 XREF[1]:     00475f91(j)  
    //                              pnl_edit.cpp:576 (4)
    //         00475fe2     CMP        EDI,EAX
    //         00475fe4     JNZ        LAB_00475ffd
    //                              pnl_edit.cpp:578 (5)
    //         00475fe6     MOV        this,EBP
    //         00475fe8     SHR        this,0x10
    //                              pnl_edit.cpp:579 (7)
    //         00475feb     CMP        this,0x400
    //         00475ff0     JNZ        LAB_00475ffd
    //                              pnl_edit.cpp:587 (11)
    //         00475ff2     PUSH       0x1
    //         00475ff4     PUSH       0x0
    //         00475ff6     PUSH       EAX
    //         00475ff7     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                               LAB_00475ffd                                                 XREF[9]:     00475f5a(j), 00475f65(j), 
    //                                                                                                         00475f70(j), 00475f7e(j), 
    //                                                                                                         00475f96(j), 00475fa0(j), 
    //                                                                                                         00475fac(j), 00475fe4(j), 
    //                                                                                                         00475ff0(j)  
    //                              pnl_edit.cpp:596 (15)
    //         00475ffd     MOV        this,dword ptr [ESP + param_1]
    //         00476001     PUSH       EDI
    //         00476002     PUSH       EBP=>DAT_fffffff8
    //         00476003     PUSH       EBX=>DAT_fffffff4
    //         00476004     PUSH       this=>DAT_fffffff0
    //         00476005     MOV        this,ESI
    //         00476007     CALL       TPanel::wnd_proc                                 long wnd_proc(TPanel * this, void * param_1, 
    //                              pnl_edit.cpp:598 (7)
    //         0047600c     POP        EDI
    //         0047600d     POP        ESI
    //         0047600e     POP        EBP
    //         0047600f     POP        EBX
    //         00476010     RET        0x10
    //                               LAB_00476013                                                 XREF[1]:     00475f85(j)  
    //                              pnl_edit.cpp:540 (17)
    //         00476013     MOV        this,dword ptr [ESP + param_4]
    //         00476017     MOV        EDX,dword ptr [ESP + param_3]
    //         0047601b     MOV        EAX,dword ptr [ESP + param_1]
    //         0047601f     PUSH       this
    //         00476020     PUSH       EDX
    //         00476021     PUSH       0x7
    //         00476023     PUSH       EAX
    //                              pnl_edit.cpp:596 (7)
    //         00476024     MOV        this,ESI
    //         00476026     CALL       TPanel::wnd_proc                                 long wnd_proc(TPanel * this, void * param_1, 
    //                              pnl_edit.cpp:598 (7)
    //         0047602b     POP        EDI
    //         0047602c     POP        ESI
    //         0047602d     POP        EBP
    //         0047602e     POP        EBX
    //         0047602f     RET        0x10
}

// Offset: 0x00476040
long sub_wnd_proc(TEditPanel* this_, void* param_2, uint param_3, uint param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEditPanel::sub_wnd_proc(void *,unsigned int,unsigned int,long)               *
    //                              *********************************************************************************************************
    //                              long __thiscall sub_wnd_proc(TEditPanel * this, void * param_1, uint
    //              long              EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[2]:     00476093(R), 0047612a(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[2]:     00476049(R), 004762ef(W)  
    //              uint              Stack[0xc]:4   param_3                   XREF[6]:     004760b5(R), 00476126(R), 00476215(R), 00476244(R), 
    //                                                                                     0047625b(R), 004762d9(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[2]:     00476045(R), 00476319(W)  
    //              tagRECT           Stack[-0x14]   rect                      XREF[2]:     004762eb(W), 00476309(*)  
    //              ulong             Stack[-0x18]:4 old_end                   XREF[1]:     004762f3(W)  
    //              ulong             Stack[-0x1c]:4 new_end                   XREF[2]:     004762e7(W), 0047630d(*)  
    //              ulong             Stack[-0x20]:4 old_start
    //                               ?sub_wnd_proc@TEditPanel@@QAEJPAXIIJ@Z                       XREF[1]:     pnl_sub_wnd_proc:00475954(c)  
    //                               TEditPanel::sub_wnd_proc
    //                              pnl_edit.cpp:604 (5)
    //         00476040     SUB        ESP,0x1c
    //         00476043     PUSH       EBX
    //         00476044     PUSH       EBP
    //                              pnl_edit.cpp:618 (62)
    //         00476045     MOV        EBX,dword ptr [ESP + param_4]
    //         00476049     MOV        EBP,dword ptr [ESP + param_2]
    //         0047604d     PUSH       ESI
    //         0047604e     MOV        ESI,this
    //         00476050     PUSH       EDI
    //         00476051     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00476057     TEST       EAX,EAX
    //         00476059     JZ         switchD_00476114::caseD_103
    //         0047605f     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00476062     TEST       EAX,EAX
    //         00476064     JZ         switchD_00476114::caseD_103
    //         0047606a     MOV        EAX,dword ptr [ESI + 0x70]
    //         0047606d     TEST       EAX,EAX
    //         0047606f     JZ         switchD_00476114::caseD_103
    //         00476075     MOV        EAX,dword ptr [ESI + 0x104]
    //         0047607b     TEST       EAX,EAX
    //         0047607d     JNZ        switchD_00476114::caseD_103
    //                              pnl_edit.cpp:620 (16)
    //         00476083     CMP        EBP,0x14
    //         00476086     JA         LAB_004760f3
    //         00476088     JZ         LAB_004760a7
    //         0047608a     CMP        EBP,0xf
    //         0047608d     JNZ        switchD_00476114::caseD_103
    //                              pnl_edit.cpp:649 (15)
    //         00476093     MOV        EAX,dword ptr [ESP + param_1]
    //         00476097     PUSH       0x1
    //         00476099     PUSH       0x0
    //         0047609b     PUSH       EAX
    //         0047609c     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              pnl_edit.cpp:650 (5)
    //         004760a2     JMP        switchD_00476114::caseD_103
    //                               LAB_004760a7                                                 XREF[1]:     00476088(j)  
    //                              pnl_edit.cpp:624 (14)
    //         004760a7     MOV        EAX,dword ptr [ESI + 0x108]
    //         004760ad     TEST       EAX,EAX
    //         004760af     JZ         switchD_00476114::caseD_103
    //                              pnl_edit.cpp:627 (12)
    //         004760b5     MOV        EDI,dword ptr [ESP + param_3]
    //         004760b9     PUSH       EAX
    //         004760ba     PUSH       EDI
    //         004760bb     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              pnl_edit.cpp:628 (16)
    //         004760c1     MOV        EDX,dword ptr [ESP + 0x30]
    //         004760c5     LEA        this,[ESP + 0x1c]
    //         004760c9     PUSH       this
    //         004760ca     PUSH       EDX
    //         004760cb     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
    //                              pnl_edit.cpp:629 (19)
    //         004760d1     MOV        EAX,dword ptr [ESI + 0x108]
    //         004760d7     LEA        this,[ESP + 0x1c]
    //         004760db     PUSH       EAX
    //         004760dc     PUSH       this
    //         004760dd     PUSH       EDI
    //         004760de     CALL       dword ptr [->USER32.DLL::FillRect]               = 0048ae9c
    //                              pnl_edit.cpp:630 (5)
    //         004760e4     MOV        EAX,0x1
    //                              pnl_edit.cpp:753 (10)
    //         004760e9     POP        EDI
    //         004760ea     POP        ESI
    //         004760eb     POP        EBP
    //         004760ec     POP        EBX
    //         004760ed     ADD        ESP,0x1c
    //         004760f0     RET        0x10
    //                               LAB_004760f3                                                 XREF[1]:     00476086(j)  
    //                              pnl_edit.cpp:620 (40)
    //         004760f3     CMP        EBP,0x200
    //         004760f9     JA         switchD_00476114::caseD_103
    //         004760ff     JZ         LAB_004762ba
    //         00476105     LEA        EAX,[EBP + 0xffffff00]
    //         0047610b     CMP        EAX,0x4
    //         0047610e     JA         switchD_00476114::caseD_103
    //                               switchD_00476114::switchD
    //         00476114     JMP        dword ptr [EAX*0x4 + switchD_00476114::switchd   = 0047611b
    //                               switchD_00476114::caseD_100                                  XREF[2]:     00476114(j), 00476424(*)  
    //                              pnl_edit.cpp:653 (11)
    //         0047611b     MOV        this,dword ptr [ESI + 0x40]
    //         0047611e     TEST       this,this
    //         00476120     JZ         LAB_00476215
    //                              pnl_edit.cpp:655 (17)
    //         00476126     MOV        EDI,dword ptr [ESP + param_3]
    //         0047612a     MOV        EAX,dword ptr [ESP + param_1]
    //         0047612e     MOV        EDX,dword ptr [this->_padding_]
    //         00476130     PUSH       EBX
    //         00476131     PUSH       EDI
    //         00476132     PUSH       EBP
    //         00476133     PUSH       EAX
    //         00476134     CALL       dword ptr [EDX + 0x48]
    //                              pnl_edit.cpp:656 (4)
    //         00476137     TEST       EAX,EAX
    //         00476139     JZ         LAB_00476147
    //                              pnl_edit.cpp:657 (2)
    //         0047613b     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         0047613d     POP        EDI
    //         0047613e     POP        ESI
    //         0047613f     POP        EBP
    //         00476140     POP        EBX
    //         00476141     ADD        ESP,0x1c
    //         00476144     RET        0x10
    //                               LAB_00476147                                                 XREF[1]:     00476139(j)  
    //                              pnl_edit.cpp:659 (5)
    //         00476147     CMP        EDI,0x9
    //         0047614a     JNZ        LAB_004761af
    //                              pnl_edit.cpp:661 (12)
    //         0047614c     MOV        EDI,dword ptr [->USER32.DLL::GetKeyState]        = 0048af44
    //         00476152     PUSH       0x12
    //         00476154     CALL       EDI=>USER32.DLL::GetKeyState
    //         00476156     XOR        this,this
    //                              pnl_edit.cpp:662 (14)
    //         00476158     PUSH       0x11
    //         0047615a     TEST       AX,AX
    //         0047615d     SETL       this
    //         00476160     MOV        EBP,this
    //         00476162     CALL       EDI=>USER32.DLL::GetKeyState
    //         00476164     XOR        EDX,EDX
    //                              pnl_edit.cpp:663 (16)
    //         00476166     PUSH       0x10
    //         00476168     TEST       AX,AX
    //         0047616b     SETL       DL
    //         0047616e     MOV        dword ptr [ESP + 0x3c],EDX
    //         00476172     CALL       EDI=>USER32.DLL::GetKeyState
    //         00476174     XOR        this,this
    //                              pnl_edit.cpp:665 (35)
    //         00476176     MOV        EDX,dword ptr [ESI]
    //         00476178     TEST       AX,AX
    //         0047617b     SETL       this
    //         0047617e     MOV        EAX,this
    //         00476180     MOV        this,ESI
    //         00476182     PUSH       EAX
    //         00476183     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00476187     PUSH       EAX=>DAT_fffffff8
    //         00476188     PUSH       EBP=>DAT_fffffff4
    //         00476189     PUSH       EBX=>DAT_fffffff0
    //         0047618a     PUSH       0x9
    //         0047618c     MOV        dword ptr [DAT_0086b240],0x1
    //         00476196     CALL       dword ptr [EDX + 0x58]
    //                              pnl_edit.cpp:666 (10)
    //         00476199     MOV        dword ptr [DAT_0086b240],0x0
    //                              pnl_edit.cpp:667 (2)
    //         004761a3     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         004761a5     POP        EDI
    //         004761a6     POP        ESI
    //         004761a7     POP        EBP
    //         004761a8     POP        EBX
    //         004761a9     ADD        ESP,0x1c
    //         004761ac     RET        0x10
    //                               LAB_004761af                                                 XREF[1]:     0047614a(j)  
    //                              pnl_edit.cpp:669 (5)
    //         004761af     CMP        EDI,0xd
    //         004761b2     JNZ        LAB_004761d2
    //                              pnl_edit.cpp:671 (18)
    //         004761b4     MOV        this,dword ptr [ESI + 0x40]
    //         004761b7     PUSH       0x0
    //         004761b9     PUSH       0x0=>DAT_fffffff8
    //         004761bb     PUSH       0x0=>DAT_fffffff4
    //         004761bd     MOV        EDX,dword ptr [this->_padding_]
    //         004761bf     PUSH       ESI=>DAT_fffffff0
    //         004761c0     CALL       dword ptr [EDX + 0xb4]
    //                              pnl_edit.cpp:672 (2)
    //         004761c6     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         004761c8     POP        EDI
    //         004761c9     POP        ESI
    //         004761ca     POP        EBP
    //         004761cb     POP        EBX
    //         004761cc     ADD        ESP,0x1c
    //         004761cf     RET        0x10
    //                               LAB_004761d2                                                 XREF[1]:     004761b2(j)  
    //                              pnl_edit.cpp:674 (9)
    //         004761d2     CMP        EDI,0x1b
    //         004761d5     JNZ        LAB_004762dd
    //                              pnl_edit.cpp:676 (26)
    //         004761db     MOV        this,dword ptr [ESI + 0x40]
    //         004761de     PUSH       0x0
    //         004761e0     PUSH       0x0=>DAT_fffffff8
    //         004761e2     PUSH       offset DAT_fffffff4
    //         004761e4     MOV        EAX,dword ptr [this->_padding_]
    //         004761e6     PUSH       ESI=>DAT_fffffff0
    //         004761e7     CALL       dword ptr [EAX + 0xb4]
    //         004761ed     TEST       EAX,EAX
    //         004761ef     JNZ        LAB_004762ae
    //                              pnl_edit.cpp:677 (20)
    //         004761f5     MOV        this,dword ptr [ESI + 0xf4]
    //         004761fb     PUSH       EAX
    //         004761fc     PUSH       EAX=>DAT_fffffff8
    //         004761fd     PUSH       offset DAT_fffffff4
    //         00476202     PUSH       this=>DAT_fffffff0
    //         00476203     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              pnl_edit.cpp:678 (2)
    //         00476209     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         0047620b     POP        EDI
    //         0047620c     POP        ESI
    //         0047620d     POP        EBP
    //         0047620e     POP        EBX
    //         0047620f     ADD        ESP,0x1c
    //         00476212     RET        0x10
    //                               LAB_00476215                                                 XREF[1]:     00476120(j)  
    //                              pnl_edit.cpp:674 (4)
    //         00476215     MOV        EDI,dword ptr [ESP + param_3]
    //                              pnl_edit.cpp:682 (9)
    //         00476219     CMP        EDI,0x1b
    //         0047621c     JNZ        LAB_004762dd
    //                              pnl_edit.cpp:684 (22)
    //         00476222     MOV        EDX,dword ptr [ESI + 0xf4]
    //         00476228     PUSH       0x0
    //         0047622a     PUSH       0x0
    //         0047622c     PUSH       0xc7
    //         00476231     PUSH       EDX
    //         00476232     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              pnl_edit.cpp:685 (2)
    //         00476238     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         0047623a     POP        EDI
    //         0047623b     POP        ESI
    //         0047623c     POP        EBP
    //         0047623d     POP        EBX
    //         0047623e     ADD        ESP,0x1c
    //         00476241     RET        0x10
    //                               switchD_00476114::caseD_101                                  XREF[2]:     00476114(j), 00476428(*)  
    //                              pnl_edit.cpp:690 (11)
    //         00476244     CMP        dword ptr [ESP + param_3],0x9
    //         00476249     JNZ        switchD_00476114::caseD_103
    //                              pnl_edit.cpp:691 (2)
    //         0047624f     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         00476251     POP        EDI
    //         00476252     POP        ESI
    //         00476253     POP        EBP
    //         00476254     POP        EBX
    //         00476255     ADD        ESP,0x1c
    //         00476258     RET        0x10
    //                               switchD_00476114::caseD_102                                  XREF[2]:     00476114(j), 0047642c(*)  
    //                              pnl_edit.cpp:695 (16)
    //         0047625b     MOV        EAX,dword ptr [ESP + param_3]
    //         0047625f     MOV        this,ESI
    //         00476261     PUSH       EAX
    //         00476262     CALL       TEditPanel::verify_char                          int verify_char(TEditPanel * this, int param_1)
    //         00476267     TEST       EAX,EAX
    //         00476269     JNZ        switchD_00476114::caseD_103
    //                              pnl_edit.cpp:753 (10)
    //         0047626b     POP        EDI
    //         0047626c     POP        ESI
    //         0047626d     POP        EBP
    //         0047626e     POP        EBX
    //         0047626f     ADD        ESP,0x1c
    //         00476272     RET        0x10
    //                               switchD_00476114::caseD_104                                  XREF[2]:     00476114(j), 00476434(*)  
    //                              pnl_edit.cpp:700 (20)
    //         00476275     MOV        EAX,dword ptr [ESI + 0x160]
    //         0047627b     TEST       EAX,EAX
    //         0047627d     JZ         LAB_00476289
    //         0047627f     MOV        EAX,dword ptr [ESI + 0x164]
    //         00476285     TEST       EAX,EAX
    //         00476287     JNZ        LAB_004762ae
    //                               LAB_00476289                                                 XREF[1]:     0047627d(j)  
    //                              pnl_edit.cpp:704 (13)
    //         00476289     MOV        this,dword ptr [ESI + 0x20]
    //         0047628c     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0047628f     PUSH       EDX
    //         00476290     CALL       dword ptr [->USER32.DLL::SetFocus]               = 0048acd6
    //                              pnl_edit.cpp:705 (24)
    //         00476296     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0047629a     MOV        EDX,dword ptr [ESI + 0x20]
    //         0047629d     MOV        this,dword ptr [ESP + 0x38]
    //         004762a1     PUSH       EAX
    //         004762a2     MOV        EAX,dword ptr [EDX + 0x4]
    //         004762a5     PUSH       this=>DAT_fffffff8
    //         004762a6     PUSH       EBP=>DAT_fffffff4
    //         004762a7     PUSH       EAX=>DAT_fffffff0
    //         004762a8     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //                               LAB_004762ae                                                 XREF[2]:     004761ef(j), 00476287(j)  
    //                              pnl_edit.cpp:707 (2)
    //         004762ae     XOR        EAX,EAX
    //                              pnl_edit.cpp:753 (10)
    //         004762b0     POP        EDI
    //         004762b1     POP        ESI
    //         004762b2     POP        EBP
    //         004762b3     POP        EBX
    //         004762b4     ADD        ESP,0x1c
    //         004762b7     RET        0x10
    //                               LAB_004762ba                                                 XREF[1]:     004760ff(j)  
    //                              pnl_edit.cpp:709 (16)
    //         004762ba     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004762c0     MOV        EAX,dword ptr [this->_padding_ + 0x1d0]
    //         004762c6     TEST       EAX,EAX
    //         004762c8     JNZ        switchD_00476114::caseD_103
    //                              pnl_edit.cpp:711 (10)
    //         004762ca     MOV        dword ptr [MouseCursorInChildContol],0x1
    //                              pnl_edit.cpp:712 (9)
    //         004762d4     CALL       RGE_Base_Game::mouse_off                         void mouse_off(RGE_Base_Game * this)
    //                               switchD_00476114::caseD_103                                  XREF[14]:    00476059(j), 00476064(j), 
    //                                                                                                         0047606f(j), 0047607d(j), 
    //                                                                                                         0047608d(j), 004760a2(j), 
    //                                                                                                         004760af(j), 004760f9(j), 
    //                                                                                                         0047610e(j), 00476114(j), 
    //                                                                                                         00476249(j), 00476269(j), 
    //                                                                                                         004762c8(j), 00476430(*)  
    //         004762d9     MOV        EDI,dword ptr [ESP + param_3]
    //                               LAB_004762dd                                                 XREF[2]:     004761d5(j), 0047621c(j)  
    //                              pnl_edit.cpp:722 (44)
    //         004762dd     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004762e3     XOR        this,this
    //         004762e5     CMP        EAX,this
    //         004762e7     MOV        dword ptr [ESP + new_end],this
    //         004762eb     MOV        dword ptr [ESP + rect.left],this
    //         004762ef     MOV        dword ptr [ESP + param_2],this
    //         004762f3     MOV        dword ptr [ESP + old_end],this
    //         004762f7     JZ         LAB_00476419
    //         004762fd     CMP        EBP,0xb0
    //         00476303     JZ         LAB_00476419
    //                              pnl_edit.cpp:728 (30)
    //         00476309     LEA        this=>rect,[ESP + 0x18]
    //         0047630d     LEA        EDX=>new_end,[ESP + 0x10]
    //         00476311     PUSH       this
    //         00476312     PUSH       EDX=>DAT_fffffff8
    //         00476313     PUSH       offset DAT_fffffff4
    //         00476318     PUSH       EAX=>DAT_fffffff0
    //         00476319     MOV        dword ptr [ESP + param_4],0x1
    //         00476321     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_00476327                                                 XREF[1]:     0047641d(j)  
    //                              pnl_edit.cpp:730 (23)
    //         00476327     MOV        EAX,dword ptr [ESP + 0x30]
    //         0047632b     MOV        this,dword ptr [ESI + 0x110]
    //         00476331     PUSH       EBX
    //         00476332     PUSH       EDI=>DAT_fffffff8
    //         00476333     PUSH       EBP=>DAT_fffffff4
    //         00476334     PUSH       EAX=>DAT_fffffff0
    //         00476335     PUSH       this
    //         00476336     CALL       dword ptr [->USER32.DLL::CallWindowProcA]        = 0048b082
    //         0047633c     MOV        EDI,EAX
    //                              pnl_edit.cpp:732 (8)
    //         0047633e     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00476342     TEST       EAX,EAX
    //         00476344     JZ         LAB_00476398
    //                              pnl_edit.cpp:734 (28)
    //         00476346     MOV        this,dword ptr [ESI + 0xf4]
    //         0047634c     LEA        EDX,[ESP + 0x14]
    //         00476350     LEA        EAX,[ESP + 0x34]
    //         00476354     PUSH       EDX
    //         00476355     PUSH       EAX=>DAT_fffffff8
    //         00476356     PUSH       offset DAT_fffffff4
    //         0047635b     PUSH       this=>DAT_fffffff0
    //         0047635c     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              pnl_edit.cpp:735 (24)
    //         00476362     MOV        EDX,dword ptr [ESP + 0x34]
    //         00476366     MOV        EAX,dword ptr [ESP + 0x10]
    //         0047636a     CMP        EDX,EAX
    //         0047636c     JNZ        LAB_0047637a
    //         0047636e     MOV        EAX,dword ptr [ESP + 0x14]
    //         00476372     MOV        this,dword ptr [ESP + 0x18]
    //         00476376     CMP        EAX,this
    //         00476378     JZ         LAB_00476398
    //                               LAB_0047637a                                                 XREF[1]:     0047636c(j)  
    //                              pnl_edit.cpp:737 (17)
    //         0047637a     MOV        this,dword ptr [ESI + 0xf4]
    //         00476380     PUSH       0x1
    //         00476382     PUSH       0x0=>DAT_fffffff8
    //         00476384     PUSH       this=>DAT_fffffff4
    //         00476385     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              pnl_edit.cpp:738 (13)
    //         0047638b     MOV        EDX,dword ptr [ESI + 0xf4]
    //         00476391     PUSH       EDX
    //         00476392     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
    //                               LAB_00476398                                                 XREF[2]:     00476344(j), 00476378(j)  
    //                              pnl_edit.cpp:742 (8)
    //         00476398     CMP        EBP,0x302
    //         0047639e     JNZ        LAB_004763a7
    //                              pnl_edit.cpp:743 (7)
    //         004763a0     MOV        this,ESI
    //         004763a2     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                               LAB_004763a7                                                 XREF[1]:     0047639e(j)  
    //                              pnl_edit.cpp:745 (32)
    //         004763a7     CMP        EBP,0x201
    //         004763ad     JZ         LAB_004763c7
    //         004763af     CMP        EBP,0x202
    //         004763b5     JZ         LAB_004763c7
    //         004763b7     CMP        EBP,0x204
    //         004763bd     JZ         LAB_004763c7
    //         004763bf     CMP        EBP,0x205
    //         004763c5     JNZ        LAB_0047640d
    //                               LAB_004763c7                                                 XREF[3]:     004763ad(j), 004763b5(j), 
    //                                                                                                         004763bd(j)  
    //                              pnl_edit.cpp:747 (3)
    //         004763c7     MOV        EDI,dword ptr [ESI + 0xc]
    //                              pnl_edit.cpp:748 (5)
    //         004763ca     MOV        EDX,dword ptr [ESI + 0x10]
    //         004763cd     MOV        EAX,EBX
    //                              pnl_edit.cpp:749 (62)
    //         004763cf     MOV        this,panel_system
    //         004763d4     AND        EAX,0xffff
    //         004763d9     SHR        EBX,0x10
    //         004763dc     ADD        EDI,EAX
    //         004763de     ADD        EBX,EDX
    //         004763e0     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
    //         004763e5     MOV        this,dword ptr [ESP + 0x38]
    //         004763e9     AND        EBX,0xffff
    //         004763ef     SHL        EBX,0x10
    //         004763f2     AND        EDI,0xffff
    //         004763f8     MOV        EDX,dword ptr [EAX]
    //         004763fa     OR         EBX,EDI
    //         004763fc     PUSH       EBX
    //         004763fd     PUSH       this=>DAT_fffffff8
    //         004763fe     MOV        this,dword ptr [ESI + 0x20]
    //         00476401     PUSH       EBP=>DAT_fffffff4
    //         00476402     MOV        this,dword ptr [ECX + this->_padding_]
    //         00476405     PUSH       this=>DAT_fffffff0
    //         00476406     MOV        this,EAX
    //         00476408     CALL       dword ptr [EDX + 0x48]
    //         0047640b     MOV        EDI,EAX
    //                               LAB_0047640d                                                 XREF[1]:     004763c5(j)  
    //                              pnl_edit.cpp:752 (2)
    //         0047640d     MOV        EAX,EDI
    //                              pnl_edit.cpp:753 (10)
    //         0047640f     POP        EDI
    //         00476410     POP        ESI
    //         00476411     POP        EBP
    //         00476412     POP        EBX
    //         00476413     ADD        ESP,0x1c
    //         00476416     RET        0x10
    //                               LAB_00476419                                                 XREF[2]:     004762f7(j), 00476303(j)  
    //                              pnl_edit.cpp:725 (4)
    //         00476419     MOV        dword ptr [ESP + 0x3c],this
    //                              pnl_edit.cpp:727 (5)
    //         0047641d     JMP        LAB_00476327
}

// Offset: 0x00476422
undefined FUN_00476422() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00476422()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00476422
    //                              pnl_edit.cpp:753 (22)
    //         00476422     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00476114::switchdataD_00476424                       XREF[1]:     sub_wnd_proc:00476114(*)  
}

// Offset: 0x00476440
int verify_char(TEditPanel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEditPanel::verify_char(int)                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall verify_char(TEditPanel * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047645e(R)  
    //                               ?verify_char@TEditPanel@@QAEHH@Z                             XREF[1]:     sub_wnd_proc:00476262(c)  
    //                               TEditPanel::verify_char
    //                              pnl_edit.cpp:760 (13)
    //         00476440     MOV        EAX,[DAT_0086b244]
    //         00476445     PUSH       ESI
    //         00476446     TEST       EAX,EAX
    //         00476448     PUSH       EDI
    //         00476449     MOV        ESI,this
    //         0047644b     JZ         LAB_0047645e
    //                              pnl_edit.cpp:763 (10)
    //         0047644d     MOV        dword ptr [DAT_0086b244],0x0
    //                              pnl_edit.cpp:764 (2)
    //         00476457     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         00476459     POP        EDI
    //         0047645a     POP        ESI
    //         0047645b     RET        0x4
    //                               LAB_0047645e                                                 XREF[1]:     0047644b(j)  
    //                              pnl_edit.cpp:767 (9)
    //         0047645e     MOV        EDI,dword ptr [ESP + param_1]
    //         00476462     CMP        EDI,0x9
    //         00476465     JNZ        LAB_0047646e
    //                              pnl_edit.cpp:768 (2)
    //         00476467     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         00476469     POP        EDI
    //         0047646a     POP        ESI
    //         0047646b     RET        0x4
    //                               LAB_0047646e                                                 XREF[1]:     00476465(j)  
    //                              pnl_edit.cpp:770 (14)
    //         0047646e     CMP        EDI,0xd
    //         00476471     JNZ        LAB_00476483
    //         00476473     CMP        dword ptr [ESI + 0x128],0x7
    //         0047647a     JZ         LAB_00476483
    //                              pnl_edit.cpp:771 (2)
    //         0047647c     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         0047647e     POP        EDI
    //         0047647f     POP        ESI
    //         00476480     RET        0x4
    //                               LAB_00476483                                                 XREF[2]:     00476471(j), 0047647a(j)  
    //                              pnl_edit.cpp:773 (3)
    //         00476483     CMP        EDI,0x8
    //                              pnl_edit.cpp:774 (6)
    //         00476486     JZ         switchD_00476509::caseD_0
    //                              pnl_edit.cpp:776 (7)
    //         0047648c     MOV        this,ESI
    //         0047648e     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:778 (28)
    //         00476493     MOV        EAX,dword ptr [ESI + 0x14c]
    //         00476499     TEST       EAX,EAX
    //         0047649b     JNZ        LAB_004764fa
    //         0047649d     MOVSX      this,word ptr [ESI + 0xf8]
    //         004764a4     MOV        EDX,dword ptr [ESI + 0x100]
    //         004764aa     DEC        this
    //         004764ab     CMP        EDX,this
    //         004764ad     JL         LAB_004764be
    //                              pnl_edit.cpp:780 (8)
    //         004764af     PUSH       -0x1
    //         004764b1     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
    //                              pnl_edit.cpp:781 (2)
    //         004764b7     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         004764b9     POP        EDI
    //         004764ba     POP        ESI
    //         004764bb     RET        0x4
    //                               LAB_004764be                                                 XREF[1]:     004764ad(j)  
    //                              pnl_edit.cpp:784 (35)
    //         004764be     TEST       EAX,EAX
    //         004764c0     JNZ        LAB_004764fa
    //         004764c2     MOVSX      EDX,word ptr [ESI + 0xf8]
    //         004764c9     MOV        EAX,dword ptr [ESI + 0x100]
    //         004764cf     SUB        EDX,0x2
    //         004764d2     CMP        EAX,EDX
    //         004764d4     JL         LAB_004764fa
    //         004764d6     PUSH       EDI
    //         004764d7     CALL       dword ptr [->KERNEL32.DLL::IsDBCSLeadByte]       = 0048abd2
    //         004764dd     TEST       EAX,EAX
    //         004764df     JZ         LAB_004764fa
    //                              pnl_edit.cpp:787 (18)
    //         004764e1     PUSH       -0x1
    //         004764e3     MOV        dword ptr [DAT_0086b244],0x1
    //         004764ed     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
    //                              pnl_edit.cpp:788 (2)
    //         004764f3     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         004764f5     POP        EDI
    //         004764f6     POP        ESI
    //         004764f7     RET        0x4
    //                               LAB_004764fa                                                 XREF[4]:     0047649b(j), 004764c0(j), 
    //                                                                                                         004764d4(j), 004764df(j)  
    //                              pnl_edit.cpp:792 (22)
    //         004764fa     MOV        EAX,dword ptr [ESI + 0x128]
    //         00476500     CMP        EAX,0x8
    //         00476503     JA         switchD_00476509::caseD_0
    //                               switchD_00476509::switchD
    //         00476509     JMP        dword ptr [EAX*0x4 + switchD_00476509::switchd   = 00476643
    //                               switchD_00476509::caseD_8                                    XREF[2]:     00476509(j), 00476670(*)  
    //                              pnl_edit.cpp:798 (11)
    //         00476510     MOV        EAX,dword ptr [ESI + 0x100]
    //         00476516     CMP        EAX,0x2
    //         00476519     JGE        LAB_0047652c
    //                              pnl_edit.cpp:800 (14)
    //         0047651b     CMP        EDI,0x30
    //         0047651e     JL         LAB_00476529
    //         00476520     CMP        EDI,0x39
    //         00476523     JLE        switchD_00476509::caseD_0
    //                               LAB_00476529                                                 XREF[1]:     0047651e(j)  
    //                              pnl_edit.cpp:803 (18)
    //         00476529     CMP        EAX,0x2
    //                               LAB_0047652c                                                 XREF[1]:     00476519(j)  
    //         0047652c     JNZ        LAB_00476634
    //         00476532     CMP        EDI,0x30
    //         00476535     JNZ        LAB_00476634
    //                              pnl_edit.cpp:805 (22)
    //         0047653b     MOV        EAX,dword ptr [ESI + 0xfc]
    //         00476541     PUSH       EAX
    //         00476542     PUSH       s_10                                             = "10"
    //         00476547     CALL       __mbscmp                                         undefined __mbscmp()
    //         0047654c     ADD        ESP,0x8
    //         0047654f     TEST       EAX,EAX
    //                              pnl_edit.cpp:810 (2)
    //         00476551     JMP        LAB_004765ad
    //                               switchD_00476509::caseD_2                                    XREF[4]:     00476509(j), 00476654(*), 
    //                               switchD_00476509::caseD_3                                                 00476658(*), 0047665c(*)  
    //                               switchD_00476509::caseD_1
    //                              pnl_edit.cpp:815 (7)
    //         00476553     MOV        this,ESI
    //         00476555     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:816 (14)
    //         0047655a     CMP        EDI,0x30
    //         0047655d     JL         LAB_00476568
    //         0047655f     CMP        EDI,0x39
    //         00476562     JLE        switchD_00476509::caseD_0
    //                               LAB_00476568                                                 XREF[1]:     0047655d(j)  
    //                              pnl_edit.cpp:818 (29)
    //         00476568     CMP        EDI,0x2d
    //         0047656b     JNZ        LAB_00476585
    //         0047656d     MOV        this,dword ptr [ESI + 0xfc]
    //         00476573     CMP        byte ptr [this->_padding_],0x0
    //         00476576     JNZ        LAB_00476585
    //         00476578     CMP        dword ptr [ESI + 0x128],0x3
    //         0047657f     JNZ        switchD_00476509::caseD_0
    //                               LAB_00476585                                                 XREF[2]:     0047656b(j), 00476576(j)  
    //                              pnl_edit.cpp:820 (46)
    //         00476585     CMP        EDI,0x2e
    //         00476588     JNZ        LAB_00476634
    //         0047658e     MOV        EDX,dword ptr [ESI + 0xfc]
    //         00476594     PUSH       EDI
    //         00476595     PUSH       EDX
    //         00476596     CALL       __mbschr                                         undefined __mbschr()
    //         0047659b     ADD        ESP,0x8
    //         0047659e     TEST       EAX,EAX
    //         004765a0     JZ         LAB_00476634
    //         004765a6     CMP        dword ptr [ESI + 0x128],0x1
    //                               LAB_004765ad                                                 XREF[1]:     00476551(j)  
    //         004765ad     JZ         switchD_00476509::caseD_0
    //                              pnl_edit.cpp:823 (8)
    //         004765b3     PUSH       -0x1
    //         004765b5     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
    //                              pnl_edit.cpp:824 (2)
    //         004765bb     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (5)
    //         004765bd     POP        EDI
    //         004765be     POP        ESI
    //         004765bf     RET        0x4
    //                               switchD_00476509::caseD_5                                    XREF[3]:     00476509(j), 00476660(*), 
    //                               switchD_00476509::caseD_4                                                 00476664(*)  
    //                              pnl_edit.cpp:828 (7)
    //         004765c2     MOV        this,ESI
    //         004765c4     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:829 (34)
    //         004765c9     CMP        EDI,0x2e
    //         004765cc     JNZ        LAB_004765f0
    //         004765ce     CMP        dword ptr [ESI + 0x128],0x4
    //         004765d5     JNZ        LAB_004765eb
    //         004765d7     MOV        EAX,dword ptr [ESI + 0xfc]
    //         004765dd     PUSH       EDI
    //         004765de     PUSH       EAX
    //         004765df     CALL       __mbschr                                         undefined __mbschr()
    //         004765e4     ADD        ESP,0x8
    //         004765e7     TEST       EAX,EAX
    //         004765e9     JZ         switchD_00476509::caseD_0
    //                               LAB_004765eb                                                 XREF[1]:     004765d5(j)  
    //                              pnl_edit.cpp:832 (15)
    //         004765eb     CMP        EDI,0x2e
    //         004765ee     JZ         LAB_00476634
    //                               LAB_004765f0                                                 XREF[1]:     004765cc(j)  
    //         004765f0     CMP        EDI,0x5c
    //         004765f3     JZ         LAB_00476634
    //         004765f5     CMP        EDI,0x3a
    //         004765f8     JZ         LAB_00476634
    //                              pnl_edit.cpp:836 (2)
    //         004765fa     JMP        LAB_00476611
    //                               switchD_00476509::caseD_6                                    XREF[2]:     00476509(j), 00476668(*)  
    //                              pnl_edit.cpp:841 (7)
    //         004765fc     MOV        this,ESI
    //         004765fe     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:843 (49)
    //         00476603     CMP        EDI,0x3a
    //         00476606     JNZ        LAB_00476611
    //         00476608     CMP        dword ptr [ESI + 0x100],0x1
    //         0047660f     JNZ        LAB_00476634
    //                               LAB_00476611                                                 XREF[2]:     004765fa(j), 00476606(j)  
    //         00476611     CMP        EDI,0x2f
    //         00476614     JZ         LAB_00476634
    //         00476616     CMP        EDI,0x22
    //         00476619     JZ         LAB_00476634
    //         0047661b     CMP        EDI,0x2a
    //         0047661e     JZ         LAB_00476634
    //         00476620     CMP        EDI,0x3f
    //         00476623     JZ         LAB_00476634
    //         00476625     CMP        EDI,0x3e
    //         00476628     JZ         LAB_00476634
    //         0047662a     CMP        EDI,0x3c
    //         0047662d     JZ         LAB_00476634
    //         0047662f     CMP        EDI,0x7c
    //         00476632     JNZ        switchD_00476509::caseD_0
    //                               LAB_00476634                                                 XREF[14]:    0047652c(j), 00476535(j), 
    //                                                                                                         00476588(j), 004765a0(j), 
    //                                                                                                         004765ee(j), 004765f3(j), 
    //                                                                                                         004765f8(j), 0047660f(j), 
    //                                                                                                         00476614(j), 00476619(j), 
    //                                                                                                         0047661e(j), 00476623(j), 
    //                                                                                                         00476628(j), 0047662d(j)  
    //                              pnl_edit.cpp:846 (8)
    //         00476634     PUSH       -0x1
    //         00476636     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
    //                              pnl_edit.cpp:847 (2)
    //         0047663c     XOR        EAX,EAX
    //                              pnl_edit.cpp:853 (54)
    //         0047663e     POP        EDI
    //         0047663f     POP        ESI
    //         00476640     RET        0x4
    //                               switchD_00476509::caseD_7                                    XREF[11]:    00476486(j), 00476503(j), 
    //                               switchD_00476509::caseD_0                                                 00476509(j), 00476523(j), 
    //                                                                                                         00476562(j), 0047657f(j), 
    //                                                                                                         004765ad(j), 004765e9(j), 
    //                                                                                                         00476632(j), 00476650(*), 
    //                                                                                                         0047666c(*)  
    //         00476643     POP        EDI
    //         00476644     MOV        EAX,0x1
    //         00476649     POP        ESI
    //         0047664a     RET        0x4
}

// Offset: 0x0047664D
undefined FUN_0047664d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0047664d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0047664d
    //         0047664d     NOP
    //         0047664e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00476509::switchdataD_00476650                       XREF[1]:     verify_char:00476509(*)  
}

// Offset: 0x00476680
void TEditPanel::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::draw(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TEditPanel * this)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              tagRECT           Stack[-0x14]   r                         XREF[1]:     0047669c(W)  
    //              void *            Stack[-0x1c]:4 old_font
    //                               ?draw@TEditPanel@@UAEXXZ                                     XREF[1]:     005713d8(*)  
    //                               TEditPanel::draw
    //                              pnl_edit.cpp:859 (7)
    //         00476680     SUB        ESP,0x18
    //         00476683     PUSH       EBP
    //         00476684     PUSH       ESI
    //         00476685     MOV        ESI,this
    //                              pnl_edit.cpp:860 (2)
    //         00476687     XOR        EBP,EBP
    //                              pnl_edit.cpp:861 (16)
    //         00476689     MOV        EAX,dword ptr [ESI + 0x70]
    //         0047668c     MOV        dword ptr [ESI + 0x38],EBP
    //         0047668f     CMP        EAX,EBP
    //         00476691     JZ         LAB_00476a26
    //         00476697     PUSH       EDI
    //         00476698     PUSH       EBX
    //                              pnl_edit.cpp:864 (10)
    //         00476699     MOV        EBX,dword ptr [ESI]
    //         0047669b     PUSH       EBP
    //         0047669c     MOV        dword ptr [ESP + r.left],EBX
    //         004766a0     CALL       dword ptr [EBX + 0x28]
    //                              pnl_edit.cpp:867 (18)
    //         004766a3     CMP        dword ptr [ESI + 0x108],EBP
    //         004766a9     JZ         LAB_004766e0
    //         004766ab     CMP        dword ptr [ESI + 0x6c],EBP
    //         004766ae     JZ         LAB_004766e0
    //         004766b0     CMP        dword ptr [ESI + 0x78],EBP
    //         004766b3     JZ         LAB_004766e0
    //                              pnl_edit.cpp:869 (26)
    //         004766b5     MOV        this,dword ptr [ESI + 0x20]
    //         004766b8     MOV        EAX,dword ptr [ESI + 0x124]
    //         004766be     PUSH       EAX
    //         004766bf     MOV        EDX,dword ptr [this->_padding_]
    //         004766c1     MOV        EAX,dword ptr [EDX + 0x8]
    //         004766c4     PUSH       EAX
    //         004766c5     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
    //         004766cb     MOV        byte ptr [ESP + 0x10],AL
    //                              pnl_edit.cpp:870 (15)
    //         004766cf     LEA        EDX,[ESI + 0x24]
    //         004766d2     MOV        this,dword ptr [ESP + 0x10]
    //         004766d6     AND        this,0xff
    //         004766dc     PUSH       this
    //         004766dd     PUSH       EDX
    //                              pnl_edit.cpp:872 (2)
    //         004766de     JMP        LAB_00476722
    //                               LAB_004766e0                                                 XREF[3]:     004766a9(j), 004766ae(j), 
    //                                                                                                         004766b3(j)  
    //                              pnl_edit.cpp:875 (7)
    //         004766e0     MOV        this,dword ptr [ESI + 0x40]
    //         004766e3     CMP        this,EBP
    //         004766e5     JZ         LAB_00476715
    //                              pnl_edit.cpp:877 (16)
    //         004766e7     MOV        EAX,dword ptr [ESI + 0x150]
    //         004766ed     CMP        EAX,0x2
    //         004766f0     JL         LAB_00476702
    //         004766f2     CMP        EAX,0x7
    //         004766f5     JG         LAB_00476702
    //                              pnl_edit.cpp:878 (9)
    //         004766f7     MOV        EAX,dword ptr [this->_padding_]
    //         004766f9     LEA        EDX,[ESI + 0x24]
    //         004766fc     PUSH       EDX
    //         004766fd     CALL       dword ptr [EAX + 0x3c]
    //                              pnl_edit.cpp:879 (10)
    //         00476700     JMP        LAB_0047672a
    //                               LAB_00476702                                                 XREF[2]:     004766f0(j), 004766f5(j)  
    //         00476702     CMP        dword ptr [ECX + this->_padding_],EBP
    //         00476708     JNZ        LAB_0047672a
    //                              pnl_edit.cpp:880 (9)
    //         0047670a     MOV        EAX,dword ptr [this->_padding_]
    //         0047670c     LEA        EDX,[ESI + 0x24]
    //         0047670f     PUSH       EDX
    //         00476710     CALL       dword ptr [EAX + 0x34]
    //                              pnl_edit.cpp:882 (2)
    //         00476713     JMP        LAB_0047672a
    //                               LAB_00476715                                                 XREF[1]:     004766e5(j)  
    //                              pnl_edit.cpp:883 (21)
    //         00476715     XOR        EAX,EAX
    //         00476717     LEA        this,[ESI + 0x24]
    //         0047671a     MOV        AL,byte ptr [ESI + 0xef]
    //         00476720     PUSH       EAX
    //         00476721     PUSH       this
    //                               LAB_00476722                                                 XREF[1]:     004766de(j)  
    //         00476722     MOV        this,dword ptr [ESI + 0x20]
    //         00476725     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                               LAB_0047672a                                                 XREF[3]:     00476700(j), 00476708(j), 
    //                                                                                                         00476713(j)  
    //                              pnl_edit.cpp:886 (12)
    //         0047672a     CMP        dword ptr [ESI + 0x150],EBP
    //         00476730     JZ         LAB_004768c7
    //                              pnl_edit.cpp:888 (23)
    //         00476736     MOV        this,dword ptr [ESI + 0x20]
    //         00476739     PUSH       0x1
    //         0047673b     PUSH       s_pnl_edit::draw                                 = "pnl_edit::draw"
    //         00476740     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00476745     TEST       EAX,EAX
    //         00476747     JZ         switchD_0047675d::default
    //                              pnl_edit.cpp:890 (23)
    //         0047674d     MOV        EAX,dword ptr [ESI + 0x150]
    //         00476753     DEC        EAX
    //         00476754     CMP        EAX,0x6
    //         00476757     JA         switchD_0047675d::default
    //                               switchD_0047675d::switchD
    //         0047675d     JMP        dword ptr [EAX*0x4 + switchD_0047675d::switchd   = 00476764
    //                               switchD_0047675d::caseD_1                                    XREF[2]:     0047675d(j), 00476a2c(*)  
    //                              pnl_edit.cpp:893 (39)
    //         00476764     MOV        DL,byte ptr [ESI + 0x154]
    //         0047676a     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047676d     MOV        this,dword ptr [ESI + 0xc]
    //         00476770     PUSH       EDX
    //         00476771     MOV        EDX,dword ptr [ESI + 0x18]
    //         00476774     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00476778     PUSH       EDX
    //         00476779     MOV        EDX,dword ptr [ESI + 0x14]
    //         0047677c     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00476780     PUSH       EDX
    //         00476781     PUSH       EAX
    //         00476782     PUSH       this
    //         00476783     MOV        this,dword ptr [ESI + 0x20]
    //         00476786     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              pnl_edit.cpp:894 (5)
    //         0047678b     JMP        switchD_0047675d::default
    //                               switchD_0047675d::caseD_2                                    XREF[2]:     0047675d(j), 00476a30(*)  
    //                              pnl_edit.cpp:897 (19)
    //         00476790     MOV        DL,byte ptr [ESI + 0x154]
    //         00476796     MOV        EAX,dword ptr [ESI + 0x10]
    //         00476799     MOV        this,dword ptr [ESI + 0xc]
    //         0047679c     PUSH       EDX
    //         0047679d     MOV        DL,byte ptr [ESI + 0x159]
    //                              pnl_edit.cpp:898 (2)
    //         004767a3     JMP        LAB_00476812
    //                               switchD_0047675d::caseD_3                                    XREF[2]:     0047675d(j), 00476a34(*)  
    //                              pnl_edit.cpp:901 (33)
    //         004767a5     MOV        DL,byte ptr [ESI + 0x154]
    //         004767ab     MOV        EAX,dword ptr [ESI + 0x10]
    //         004767ae     MOV        this,dword ptr [ESI + 0xc]
    //         004767b1     PUSH       EDX
    //         004767b2     MOV        DL,byte ptr [ESI + 0x155]
    //         004767b8     PUSH       EDX
    //         004767b9     MOV        DL,byte ptr [ESI + 0x158]
    //         004767bf     PUSH       EDX
    //         004767c0     MOV        DL,byte ptr [ESI + 0x159]
    //                              pnl_edit.cpp:902 (5)
    //         004767c6     JMP        LAB_00476853
    //                               switchD_0047675d::caseD_4                                    XREF[2]:     0047675d(j), 00476a38(*)  
    //                              pnl_edit.cpp:905 (47)
    //         004767cb     MOV        DL,byte ptr [ESI + 0x154]
    //         004767d1     MOV        EAX,dword ptr [ESI + 0x10]
    //         004767d4     PUSH       EDX
    //         004767d5     MOV        DL,byte ptr [ESI + 0x155]
    //         004767db     PUSH       EDX
    //         004767dc     MOV        DL,byte ptr [ESI + 0x156]
    //         004767e2     MOV        this,dword ptr [ESI + 0xc]
    //         004767e5     PUSH       EDX
    //         004767e6     MOV        DL,byte ptr [ESI + 0x157]
    //         004767ec     PUSH       EDX
    //         004767ed     MOV        DL,byte ptr [ESI + 0x158]
    //         004767f3     PUSH       EDX
    //         004767f4     MOV        DL,byte ptr [ESI + 0x159]
    //                              pnl_edit.cpp:906 (5)
    //         004767fa     JMP        LAB_0047689f
    //                               switchD_0047675d::caseD_5                                    XREF[2]:     0047675d(j), 00476a3c(*)  
    //                              pnl_edit.cpp:909 (46)
    //         004767ff     MOV        DL,byte ptr [ESI + 0x159]
    //         00476805     MOV        EAX,dword ptr [ESI + 0x10]
    //         00476808     MOV        this,dword ptr [ESI + 0xc]
    //         0047680b     PUSH       EDX
    //         0047680c     MOV        DL,byte ptr [ESI + 0x154]
    //                               LAB_00476812                                                 XREF[1]:     004767a3(j)  
    //         00476812     PUSH       EDX
    //         00476813     MOV        EDX,dword ptr [ESI + 0x18]
    //         00476816     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         0047681a     PUSH       EDX
    //         0047681b     MOV        EDX,dword ptr [ESI + 0x14]
    //         0047681e     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00476822     PUSH       EDX
    //         00476823     PUSH       EAX
    //         00476824     PUSH       this
    //         00476825     MOV        this,dword ptr [ESI + 0x20]
    //         00476828     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
    //                              pnl_edit.cpp:910 (5)
    //         0047682d     JMP        switchD_0047675d::default
    //                               switchD_0047675d::caseD_6                                    XREF[2]:     0047675d(j), 00476a40(*)  
    //                              pnl_edit.cpp:913 (60)
    //         00476832     MOV        DL,byte ptr [ESI + 0x159]
    //         00476838     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047683b     MOV        this,dword ptr [ESI + 0xc]
    //         0047683e     PUSH       EDX
    //         0047683f     MOV        DL,byte ptr [ESI + 0x158]
    //         00476845     PUSH       EDX
    //         00476846     MOV        DL,byte ptr [ESI + 0x155]
    //         0047684c     PUSH       EDX
    //         0047684d     MOV        DL,byte ptr [ESI + 0x154]
    //                               LAB_00476853                                                 XREF[1]:     004767c6(j)  
    //         00476853     PUSH       EDX
    //         00476854     MOV        EDX,dword ptr [ESI + 0x18]
    //         00476857     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         0047685b     PUSH       EDX
    //         0047685c     MOV        EDX,dword ptr [ESI + 0x14]
    //         0047685f     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00476863     PUSH       EDX
    //         00476864     PUSH       EAX
    //         00476865     PUSH       this
    //         00476866     MOV        this,dword ptr [ESI + 0x20]
    //         00476869     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
    //                              pnl_edit.cpp:914 (2)
    //         0047686e     JMP        switchD_0047675d::default
    //                               switchD_0047675d::caseD_7                                    XREF[2]:     0047675d(j), 00476a44(*)  
    //                              pnl_edit.cpp:917 (74)
    //         00476870     MOV        DL,byte ptr [ESI + 0x159]
    //         00476876     MOV        EAX,dword ptr [ESI + 0x10]
    //         00476879     PUSH       EDX
    //         0047687a     MOV        DL,byte ptr [ESI + 0x158]
    //         00476880     PUSH       EDX
    //         00476881     MOV        DL,byte ptr [ESI + 0x157]
    //         00476887     MOV        this,dword ptr [ESI + 0xc]
    //         0047688a     PUSH       EDX
    //         0047688b     MOV        DL,byte ptr [ESI + 0x156]
    //         00476891     PUSH       EDX
    //         00476892     MOV        DL,byte ptr [ESI + 0x155]
    //         00476898     PUSH       EDX
    //         00476899     MOV        DL,byte ptr [ESI + 0x154]
    //                               LAB_0047689f                                                 XREF[1]:     004767fa(j)  
    //         0047689f     PUSH       EDX
    //         004768a0     MOV        EDX,dword ptr [ESI + 0x18]
    //         004768a3     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         004768a7     PUSH       EDX
    //         004768a8     MOV        EDX,dword ptr [ESI + 0x14]
    //         004768ab     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         004768af     PUSH       EDX
    //         004768b0     PUSH       EAX
    //         004768b1     PUSH       this
    //         004768b2     MOV        this,dword ptr [ESI + 0x20]
    //         004768b5     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                               switchD_0047675d::default                                    XREF[5]:     00476747(j), 00476757(j), 
    //                                                                                                         0047678b(j), 0047682d(j), 
    //                                                                                                         0047686e(j)  
    //                              pnl_edit.cpp:921 (13)
    //         004768ba     MOV        this,dword ptr [ESI + 0x20]
    //         004768bd     PUSH       s_pnl_edit::draw                                 = "pnl_edit::draw"
    //         004768c2     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004768c7                                                 XREF[1]:     00476730(j)  
    //                              pnl_edit.cpp:924 (14)
    //         004768c7     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004768cd     CMP        EAX,EBP
    //         004768cf     JZ         LAB_00476a1f
    //                              pnl_edit.cpp:926 (9)
    //         004768d5     CMP        dword ptr [ESI + 0x6c],EBP
    //         004768d8     JZ         LAB_00476a1f
    //                              pnl_edit.cpp:928 (5)
    //         004768de     MOV        this,dword ptr [ESI + 0x78]
    //         004768e1     CMP        this,EBP
    //                              pnl_edit.cpp:930 (16)
    //         004768e3     MOV        this,dword ptr [ESI + 0x104]
    //         004768e9     JZ         LAB_0047691f
    //         004768eb     CMP        this,EBP
    //         004768ed     JZ         LAB_00476a1f
    //                              pnl_edit.cpp:932 (9)
    //         004768f3     PUSH       0x5
    //         004768f5     PUSH       EAX
    //         004768f6     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
    //                              pnl_edit.cpp:933 (16)
    //         004768fc     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00476902     PUSH       0x1
    //         00476904     PUSH       EBP
    //         00476905     PUSH       EAX
    //         00476906     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              pnl_edit.cpp:972 (13)
    //         0047690c     MOV        this,ESI
    //         0047690e     MOV        dword ptr [ESI + 0x104],EBP
    //         00476914     CALL       dword ptr [EBX + 0x2c]
    //         00476917     POP        EBX
    //         00476918     POP        EDI
    //                              pnl_edit.cpp:973 (6)
    //         00476919     POP        ESI
    //         0047691a     POP        EBP
    //         0047691b     ADD        ESP,0x18
    //         0047691e     RET
    //                               LAB_0047691f                                                 XREF[1]:     004768e9(j)  
    //                              pnl_edit.cpp:939 (4)
    //         0047691f     CMP        this,EBP
    //         00476921     JNZ        LAB_00476935
    //                              pnl_edit.cpp:941 (8)
    //         00476923     PUSH       EBP
    //         00476924     PUSH       EAX
    //         00476925     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
    //                              pnl_edit.cpp:942 (10)
    //         0047692b     MOV        dword ptr [ESI + 0x104],0x1
    //                               LAB_00476935                                                 XREF[1]:     00476921(j)  
    //                              pnl_edit.cpp:946 (15)
    //         00476935     MOV        this,dword ptr [ESI + 0x20]
    //         00476938     PUSH       s_pnl_edit::draw                                 = "pnl_edit::draw"
    //         0047693d     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         00476942     MOV        EDI,EAX
    //                              pnl_edit.cpp:947 (8)
    //         00476944     CMP        EDI,EBP
    //         00476946     JZ         LAB_00476a1f
    //                              pnl_edit.cpp:949 (16)
    //         0047694c     MOV        this,dword ptr [ESI + 0x88]
    //         00476952     MOV        EBP,dword ptr [->GDI32.DLL::SelectClipRgn]       = 0048b2fc
    //         00476958     PUSH       this
    //         00476959     PUSH       EDI
    //         0047695a     CALL       EBP=>GDI32.DLL::SelectClipRgn
    //                              pnl_edit.cpp:950 (14)
    //         0047695c     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00476962     PUSH       EDX
    //         00476963     PUSH       EDI
    //         00476964     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              pnl_edit.cpp:951 (13)
    //         0047696a     PUSH       0x1
    //         0047696c     PUSH       EDI
    //         0047696d     MOV        dword ptr [ESP + 0x18],EAX
    //         00476971     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              pnl_edit.cpp:953 (14)
    //         00476977     MOV        EAX,dword ptr [ESI + 0x118]
    //         0047697d     PUSH       EAX
    //         0047697e     PUSH       EDI
    //         0047697f     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              pnl_edit.cpp:955 (6)
    //         00476985     MOV        this,dword ptr [ESI + 0x134]
    //                              pnl_edit.cpp:956 (6)
    //         0047698b     MOV        EDX,dword ptr [ESI + 0x138]
    //                              pnl_edit.cpp:957 (18)
    //         00476991     MOV        EAX,dword ptr [ESI + 0x13c]
    //         00476997     LEA        EBX,[ESI + 0x134]
    //         0047699d     DEC        this
    //         0047699e     INC        EDX
    //         0047699f     MOV        dword ptr [ESP + 0x18],this
    //                              pnl_edit.cpp:958 (11)
    //         004769a3     MOV        this,dword ptr [ESI + 0x140]
    //         004769a9     DEC        EAX
    //         004769aa     MOV        dword ptr [ESP + 0x1c],EDX
    //                              pnl_edit.cpp:959 (39)
    //         004769ae     MOV        EDX,dword ptr [ESI + 0x144]
    //         004769b4     MOV        dword ptr [ESP + 0x20],EAX
    //         004769b8     INC        this
    //         004769b9     PUSH       0x0
    //         004769bb     LEA        EAX,[ESP + 0x1c]
    //         004769bf     MOV        dword ptr [ESP + 0x28],this
    //         004769c3     MOV        this,dword ptr [ESI + 0xfc]
    //         004769c9     PUSH       EDX
    //         004769ca     PUSH       EAX
    //         004769cb     PUSH       -0x1
    //         004769cd     PUSH       this
    //         004769ce     PUSH       EDI
    //         004769cf     CALL       dword ptr [->USER32.DLL::DrawTextExA]            = 0048b094
    //                              pnl_edit.cpp:961 (14)
    //         004769d5     MOV        EDX,dword ptr [ESI + 0x114]
    //         004769db     PUSH       EDX
    //         004769dc     PUSH       EDI
    //         004769dd     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              pnl_edit.cpp:962 (26)
    //         004769e3     MOV        EAX,dword ptr [ESI + 0x144]
    //         004769e9     MOV        this,dword ptr [ESI + 0xfc]
    //         004769ef     PUSH       0x0
    //         004769f1     PUSH       EAX
    //         004769f2     PUSH       EBX
    //         004769f3     PUSH       -0x1
    //         004769f5     PUSH       this
    //         004769f6     PUSH       EDI
    //         004769f7     CALL       dword ptr [->USER32.DLL::DrawTextExA]            = 0048b094
    //                              pnl_edit.cpp:964 (12)
    //         004769fd     MOV        EDX,dword ptr [ESP + 0x10]
    //         00476a01     PUSH       EDX
    //         00476a02     PUSH       EDI
    //         00476a03     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              pnl_edit.cpp:965 (5)
    //         00476a09     PUSH       0x0
    //         00476a0b     PUSH       EDI
    //         00476a0c     CALL       EBP=>GDI32.DLL::SelectClipRgn
    //                              pnl_edit.cpp:966 (17)
    //         00476a0e     MOV        this,dword ptr [ESI + 0x20]
    //         00476a11     PUSH       s_pnl_edit::draw                                 = "pnl_edit::draw"
    //         00476a16     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         00476a1b     MOV        EBX,dword ptr [ESP + 0x14]
    //                               LAB_00476a1f                                                 XREF[4]:     004768cf(j), 004768d8(j), 
    //                                                                                                         004768ed(j), 00476946(j)  
    //                              pnl_edit.cpp:972 (7)
    //         00476a1f     MOV        this,ESI
    //         00476a21     CALL       dword ptr [EBX + 0x2c]
    //         00476a24     POP        EBX
    //         00476a25     POP        EDI
    //                               LAB_00476a26                                                 XREF[1]:     00476691(j)  
    //                              pnl_edit.cpp:973 (34)
    //         00476a26     POP        ESI
    //         00476a27     POP        EBP
    //         00476a28     ADD        ESP,0x18
    //         00476a2b     RET
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0047675d::switchdataD_00476a2c                       XREF[1]:     draw:0047675d(*)  
}

// Offset: 0x00476A50
void TEditPanel::paint() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::paint(void)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall paint(TEditPanel * this)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?paint@TEditPanel@@UAEXXZ                                    XREF[1]:     005713ec(*)  
    //                               TEditPanel::paint
    //                              pnl_edit.cpp:979 (1)
    //         00476a50     RET
}

// Offset: 0x00476A60
int is_blank(TEditPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEditPanel::is_blank(void)                                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall is_blank(TEditPanel * this)
    //              int               EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?is_blank@TEditPanel@@QAEHXZ                                 XREF[1]:     action:00492417(c)  
    //                               TEditPanel::is_blank
    //                              pnl_edit.cpp:987 (3)
    //         00476a60     PUSH       ESI
    //         00476a61     MOV        ESI,this
    //                              pnl_edit.cpp:990 (5)
    //         00476a63     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:991 (6)
    //         00476a68     MOV        ESI,dword ptr [ESI + 0xfc]
    //                              pnl_edit.cpp:993 (2)
    //         00476a6e     TEST       ESI,ESI
    //                              pnl_edit.cpp:994 (2)
    //         00476a70     JZ         LAB_00476aa0
    //                              pnl_edit.cpp:996 (3)
    //         00476a72     CMP        byte ptr [ESI],0x0
    //                              pnl_edit.cpp:997 (2)
    //         00476a75     JZ         LAB_00476aa0
    //                               LAB_00476a77                                                 XREF[1]:     00476a9a(j)  
    //                              pnl_edit.cpp:1001 (6)
    //         00476a77     MOV        AL,byte ptr [ESI]
    //         00476a79     TEST       AL,AL
    //         00476a7b     JZ         LAB_00476aa0
    //                              pnl_edit.cpp:1004 (18)
    //         00476a7d     AND        EAX,0xff
    //         00476a82     PUSH       EAX
    //         00476a83     CALL       __ismbcspace                                     undefined __ismbcspace()
    //         00476a88     ADD        ESP,0x4
    //         00476a8b     TEST       EAX,EAX
    //         00476a8d     JZ         LAB_00476a9c
    //                              pnl_edit.cpp:1007 (13)
    //         00476a8f     PUSH       ESI
    //         00476a90     CALL       __mbsinc                                         undefined __mbsinc()
    //         00476a95     ADD        ESP,0x4
    //         00476a98     MOV        ESI,EAX
    //         00476a9a     JMP        LAB_00476a77
    //                               LAB_00476a9c                                                 XREF[1]:     00476a8d(j)  
    //                              pnl_edit.cpp:1005 (2)
    //         00476a9c     XOR        EAX,EAX
    //                              pnl_edit.cpp:1011 (2)
    //         00476a9e     POP        ESI
    //         00476a9f     RET
    //                               LAB_00476aa0                                                 XREF[3]:     00476a70(j), 00476a75(j), 
    //                                                                                                         00476a7b(j)  
    //                              pnl_edit.cpp:1010 (5)
    //         00476aa0     MOV        EAX,0x1
    //                              pnl_edit.cpp:1011 (2)
    //         00476aa5     POP        ESI
    //         00476aa6     RET
}

// Offset: 0x00476AB0
char* get_trimmed_str(TEditPanel* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEditPanel::get_trimmed_str(char *,int)                                     *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_trimmed_str(TEditPanel * this, char * param_1,
    //              char *            EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00476ae0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00476afb(R)  
    //              char[256]         Stack[-0x104   temp_str                  XREF[0,5]:   00476ac7(*), 00476acb(*), 00476b14(R), 00476b18(*), 
    //                                                                                     00476b4a(*)  
    //                               ?get_trimmed_str@TEditPanel@@QAEPADPADH@Z                    XREF[4]:     action:004a7ae4(c), 
    //                               TEditPanel::get_trimmed_str                                               action:004a7eac(c), 
    //                                                                                                         action:004a7f3b(c), 
    //                                                                                                         action:004a7fc6(c)  
    //                              pnl_edit.cpp:1017 (11)
    //         00476ab0     SUB        ESP,0x100
    //         00476ab6     PUSH       EBX
    //         00476ab7     PUSH       ESI
    //         00476ab8     PUSH       EDI
    //         00476ab9     MOV        ESI,this
    //                              pnl_edit.cpp:1022 (5)
    //         00476abb     CALL       TEditPanel::update_text                          void update_text(TEditPanel * this)
    //                              pnl_edit.cpp:1024 (11)
    //         00476ac0     MOV        this,0x40
    //         00476ac5     XOR        EAX,EAX
    //         00476ac7     LEA        EDI=>temp_str[4],[ESP + 0xc]
    //                              pnl_edit.cpp:1025 (21)
    //         00476acb     LEA        EDX=>temp_str[4],[ESP + 0xc]
    //         00476acf     STOSD.REP  ES:EDI
    //         00476ad1     MOV        EDI,dword ptr [ESI + 0xfc]
    //         00476ad7     OR         this,0xffffffff
    //         00476ada     SCASB.RE   ES:EDI
    //         00476adc     NOT        this
    //         00476ade     SUB        EDI,this
    //                              pnl_edit.cpp:1027 (38)
    //         00476ae0     MOV        EBX,dword ptr [ESP + param_1]
    //         00476ae7     MOV        EAX,this
    //         00476ae9     MOV        ESI,EDI
    //         00476aeb     MOV        EDI,EDX
    //         00476aed     SHR        this,0x2
    //         00476af0     MOVSD.REP  ES:EDI,ESI
    //         00476af2     MOV        this,EAX
    //         00476af4     XOR        EAX,EAX
    //         00476af6     AND        this,0x3
    //         00476af9     MOVSB.REP  ES:EDI,ESI
    //         00476afb     MOV        this,dword ptr [ESP + param_2]
    //         00476b02     MOV        EDI,EBX
    //         00476b04     MOV        EDX,this
    //                              pnl_edit.cpp:1030 (14)
    //         00476b06     MOV        ESI,EBX
    //         00476b08     SHR        this,0x2
    //         00476b0b     STOSD.REP  ES:EDI
    //         00476b0d     MOV        this,EDX
    //         00476b0f     AND        this,0x3
    //         00476b12     STOSB.REP  ES:EDI
    //                              pnl_edit.cpp:1032 (26)
    //         00476b14     MOV        EAX,dword ptr [ESP + temp_str[4]]
    //         00476b18     LEA        EDI=>temp_str[4],[ESP + 0xc]
    //         00476b1c     AND        EAX,0xff
    //         00476b21     PUSH       EAX
    //         00476b22     CALL       __ismbcspace                                     undefined __ismbcspace()
    //         00476b27     ADD        ESP,0x4
    //         00476b2a     TEST       EAX,EAX
    //         00476b2c     JZ         LAB_00476b4a
    //                               LAB_00476b2e                                                 XREF[1]:     00476b48(j)  
    //                              pnl_edit.cpp:1033 (28)
    //         00476b2e     PUSH       EDI
    //         00476b2f     CALL       __mbsinc                                         undefined __mbsinc()
    //         00476b34     MOV        EDI,EAX
    //         00476b36     XOR        this,this
    //         00476b38     ADD        ESP,0x4
    //         00476b3b     MOV        this,byte ptr [EDI]
    //         00476b3d     PUSH       this
    //         00476b3e     CALL       __ismbcspace                                     undefined __ismbcspace()
    //         00476b43     ADD        ESP,0x4
    //         00476b46     TEST       EAX,EAX
    //         00476b48     JNZ        LAB_00476b2e
    //                               LAB_00476b4a                                                 XREF[1]:     00476b2c(j)  
    //                              pnl_edit.cpp:1035 (5)
    //         00476b4a     CMP        byte ptr [EDI]=>temp_str[4],0x0
    //         00476b4d     JZ         LAB_00476b76
    //                               LAB_00476b4f                                                 XREF[1]:     00476b74(j)  
    //                              pnl_edit.cpp:1037 (12)
    //         00476b4f     PUSH       0x1
    //         00476b51     PUSH       EDI
    //         00476b52     PUSH       ESI
    //         00476b53     CALL       __mbsncpy                                        undefined __mbsncpy()
    //         00476b58     ADD        ESP,0xc
    //                              pnl_edit.cpp:1038 (11)
    //         00476b5b     PUSH       ESI
    //         00476b5c     CALL       __mbsinc                                         undefined __mbsinc()
    //         00476b61     ADD        ESP,0x4
    //         00476b64     MOV        ESI,EAX
    //                              pnl_edit.cpp:1039 (16)
    //         00476b66     PUSH       EDI
    //         00476b67     CALL       __mbsinc                                         undefined __mbsinc()
    //         00476b6c     MOV        EDI,EAX
    //         00476b6e     ADD        ESP,0x4
    //         00476b71     CMP        byte ptr [EDI],0x0
    //         00476b74     JNZ        LAB_00476b4f
    //                               LAB_00476b76                                                 XREF[2]:     00476b4d(j), 00476b98(j)  
    //                              pnl_edit.cpp:1045 (7)
    //         00476b76     CMP        ESI,EBX
    //         00476b78     MOV        byte ptr [ESI],0x0
    //         00476b7b     JZ         LAB_00476b9a
    //                              pnl_edit.cpp:1047 (9)
    //         00476b7d     PUSH       ESI
    //         00476b7e     PUSH       EBX
    //         00476b7f     CALL       __mbsdec                                         undefined __mbsdec()
    //         00476b84     MOV        ESI,EAX
    //                              pnl_edit.cpp:1048 (20)
    //         00476b86     XOR        EDX,EDX
    //         00476b88     ADD        ESP,0x8
    //         00476b8b     MOV        DL,byte ptr [ESI]
    //         00476b8d     PUSH       EDX
    //         00476b8e     CALL       __ismbcspace                                     undefined __ismbcspace()
    //         00476b93     ADD        ESP,0x4
    //         00476b96     TEST       EAX,EAX
    //         00476b98     JNZ        LAB_00476b76
    //                               LAB_00476b9a                                                 XREF[1]:     00476b7b(j)  
    //                              pnl_edit.cpp:1054 (14)
    //         00476b9a     POP        EDI
    //         00476b9b     MOV        EAX,EBX
    //         00476b9d     POP        ESI
    //         00476b9e     POP        EBX
    //         00476b9f     ADD        ESP,0x100
    //         00476ba5     RET        0x8
}

// Offset: 0x00476BB0
void TEditPanel::handle_reactivate() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEditPanel::handle_reactivate(void)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall handle_reactivate(TEditPanel * this)
    //              void              <VOID>         <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //                               ?handle_reactivate@TEditPanel@@UAEXXZ                        XREF[1]:     00571484(*)  
    //                               TEditPanel::handle_reactivate
    //                              pnl_edit.cpp:1060 (3)
    //         00476bb0     PUSH       ESI
    //         00476bb1     MOV        ESI,this
    //                              pnl_edit.cpp:1061 (17)
    //         00476bb3     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00476bb9     TEST       EAX,EAX
    //         00476bbb     JZ         LAB_00476bdb
    //         00476bbd     MOV        EAX,dword ptr [ESI + 0x78]
    //         00476bc0     TEST       EAX,EAX
    //         00476bc2     JZ         LAB_00476bdb
    //                              pnl_edit.cpp:1063 (6)
    //         00476bc4     CALL       dword ptr [->USER32.DLL::GetFocus]               = 0048b068
    //                              pnl_edit.cpp:1064 (10)
    //         00476bca     MOV        ESI,dword ptr [ESI + 0xf4]
    //         00476bd0     CMP        EAX,ESI
    //         00476bd2     JZ         LAB_00476bdb
    //                              pnl_edit.cpp:1065 (7)
    //         00476bd4     PUSH       ESI
    //         00476bd5     CALL       dword ptr [->USER32.DLL::SetFocus]               = 0048acd6
    //                               LAB_00476bdb                                                 XREF[3]:     00476bbb(j), 00476bc2(j), 
    //                                                                                                         00476bd2(j)  
    //                              pnl_edit.cpp:1067 (2)
    //         00476bdb     POP        ESI
    //         00476bdc     RET
}

// Offset: 0x00476BE0
long TEditPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TEditPanel::handle_mouse_down(unsigned char,long,long,int,int)        *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TEditPanel * this, uchar param_1, 
    //              long              EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00476bf3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00476bee(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00476be9(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00476be4(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00476be0(R)  
    //                               ?handle_mouse_down@TEditPanel@@UAEJEJJHH@Z                   XREF[1]:     00571418(*)  
    //                               TEditPanel::handle_mouse_down
    //                              pnl_edit.cpp:1074 (30)
    //         00476be0     MOV        EAX,dword ptr [ESP + param_5]
    //         00476be4     MOV        EDX,dword ptr [ESP + param_4]
    //         00476be8     PUSH       EAX
    //         00476be9     MOV        EAX,dword ptr [ESP + param_3]
    //         00476bed     PUSH       EDX
    //         00476bee     MOV        EDX,dword ptr [ESP + param_2]
    //         00476bf2     PUSH       EAX
    //         00476bf3     MOV        EAX,dword ptr [ESP + param_1]
    //         00476bf7     PUSH       EDX
    //         00476bf8     PUSH       EAX
    //         00476bf9     CALL       TPanel::handle_mouse_down                        long handle_mouse_down(TPanel * this, uchar p
    //                              pnl_edit.cpp:1077 (3)
    //         00476bfe     RET        0x14
}

