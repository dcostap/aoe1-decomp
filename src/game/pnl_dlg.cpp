#include "../common.h"
#include "pnl_dlg.h"

TDialogPanel::TDialogPanel(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TDialogPanel(TDialogPanel * this, char * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              TDialogPanel *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00473c10(R)
//                               ??0TDialogPanel@@QAE@PAD@Z                                   XREF[13]:    TribeAboutDialog:0043ad9e(c),
//                               TDialogPanel::TDialogPanel                                                TribeConfigDialog:0043b587(c),
//                                                                                                         TribeDiplomacyDialog:0043c95a(c),
//                                                                                                         THelpDialog:0043e862(c),
//                                                                                                         THelpDialog:0043e902(c),
//                                                                                                         TListDialog:0043ee78(c),
//                                                                                                         TribeMenuDialog:0043f365(c),
//                                                                                                         TMessageDialog:0043fc78(c),
//                                                                                                         TRIBE_Dialog_Sed_Menu:00440165(c),
//                                                                                                         TribeSendMessageDialog:004407ca(c)
//                                                                                                         TribeSendQuickMessageDialog:004415
//                                                                                                         TribeMPCreateDialog:004920ea(c),
//                                                                                                         TRIBE_Dialog_Name:004a6d77(c)
//                              pnl_dlg.cpp:33 (62)
//         00473c10     MOV        EAX,dword ptr [ESP + param_1]
//         00473c14     PUSH       ESI
//         00473c15     MOV        ESI,this
//         00473c17     PUSH       EAX
//         00473c18     CALL       TEasy_Panel::TEasy_Panel                         undefined TEasy_Panel(TEasy_Panel * this, cha
//         00473c1d     MOV        EAX,0xb
//         00473c22     XOR        this,this
//         00473c24     MOV        dword ptr [ESI + 0x480],EAX
//         00473c2a     MOV        dword ptr [ESI + 0x484],EAX
//         00473c30     MOV        dword ptr [ESI + 0x488],EAX
//         00473c36     MOV        dword ptr [ESI + 0x478],this
//         00473c3c     MOV        dword ptr [ESI + 0x47c],this
//         00473c42     MOV        dword ptr [ESI + 0x48c],this
//         00473c48     MOV        dword ptr [ESI],TDialogPanel::`vftable'          = 00473c60
//                              pnl_dlg.cpp:34 (6)
//         00473c4e     MOV        EAX,ESI
//         00473c50     POP        ESI
//         00473c51     RET        0x4
//         00473c54     ??         90h
//         00473c55     NOP
//         00473c56     NOP
//         00473c57     NOP
//         00473c58     NOP
//         00473c59     NOP
//         00473c5a     NOP
//         00473c5b     NOP
//         00473c5c     NOP
//         00473c5d     NOP
//         00473c5e     NOP
//         00473c5f     NOP
}

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall setup(TDialogPanel * this, TDrawArea * param_1, TPane
//              int               EAX:4          <RETURN>
//              TDialogPanel *    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00473d60(R), 00473dc0(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[3]:     00473d68(R), 00473da4(W), 00473dab(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00473d90(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00473d95(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00473def(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00473d8c(R)
//                               ?setup@TDialogPanel@@UAEHPAVTDrawArea@@PAVTPanel@@JJEH@Z     XREF[15]:    0056f738(*), 0056f878(*),
//                               TDialogPanel::setup                                                       0056f9c0(*), 0056faf0(*),
//                                                                                                         0056fc20(*), 0056fd58(*),
//                                                                                                         0056fe88(*), 0056ffb8(*),
//                                                                                                         005700e8(*), 00570218(*),
//                                                                                                         005711d8(*), 00571e18(*),
//                                                                                                         00572748(*), 00573890(*),
//                                                                                                         005766a8(*)
//                              pnl_dlg.cpp:87 (18)
//         00473d60     MOV        EAX,dword ptr [ESP + param_1]
//         00473d64     PUSH       EBX
//         00473d65     PUSH       EBP
//         00473d66     PUSH       ESI
//         00473d67     PUSH       EDI
//         00473d68     MOV        EDI,dword ptr [ESP + param_2]
//         00473d6c     TEST       EDI,EDI
//         00473d6e     MOV        ESI,this
//         00473d70     JZ         LAB_00473d86
//                              pnl_dlg.cpp:93 (7)
//         00473d72     MOV        this,EDI
//         00473d74     CALL       TPanel::width                                    long width(TPanel * this)
//                              pnl_dlg.cpp:94 (11)
//         00473d79     MOV        this,EDI
//         00473d7b     MOV        EBX,EAX
//         00473d7d     CALL       TPanel::height                                   long height(TPanel * this)
//         00473d82     MOV        EBP,EAX
//                              pnl_dlg.cpp:96 (2)
//         00473d84     JMP        LAB_00473d8c
//                               LAB_00473d86                                                 XREF[1]:     00473d70(j)
//                              pnl_dlg.cpp:98 (3)
//         00473d86     MOV        EBX,dword ptr [EAX + 0x18]
//                              pnl_dlg.cpp:99 (3)
//         00473d89     MOV        EBP,dword ptr [EAX + 0x1c]
//                               LAB_00473d8c                                                 XREF[1]:     00473d84(j)
//                              pnl_dlg.cpp:102 (82)
//         00473d8c     MOV        EAX,dword ptr [ESP + param_6]
//         00473d90     MOV        this,dword ptr [ESP + param_3]
//         00473d94     PUSH       EAX
//         00473d95     MOV        EAX,dword ptr [ESP + param_4]
//         00473d99     PUSH       EAX
//         00473d9a     PUSH       this
//         00473d9b     CDQ
//         00473d9c     SUB        EAX,EDX
//         00473d9e     MOV        EDX,EAX
//         00473da0     MOV        EAX,EBP
//         00473da2     SAR        EDX,0x1
//         00473da4     MOV        dword ptr [ESP + param_2],EDX
//         00473da8     CDQ
//         00473da9     SUB        EAX,EDX
//         00473dab     MOV        EDX,dword ptr [ESP + param_2]
//         00473daf     SAR        EAX,0x1
//         00473db1     SUB        EAX,EDX
//         00473db3     PUSH       EAX
//         00473db4     MOV        EAX,this
//         00473db6     CDQ
//         00473db7     SUB        EAX,EDX
//         00473db9     MOV        this,EAX
//         00473dbb     MOV        EAX,EBX
//         00473dbd     CDQ
//         00473dbe     SUB        EAX,EDX
//         00473dc0     MOV        EDX,dword ptr [ESP + param_1]
//         00473dc4     SAR        this,0x1
//         00473dc6     SAR        EAX,0x1
//         00473dc8     SUB        EAX,this
//         00473dca     MOV        this,ESI
//         00473dcc     PUSH       EAX
//         00473dcd     PUSH       0x0
//         00473dcf     PUSH       -0x1
//         00473dd1     PUSH       0x0
//         00473dd3     PUSH       EDI
//         00473dd4     PUSH       EDX
//         00473dd5     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
//         00473dda     TEST       EAX,EAX
//         00473ddc     JNZ        LAB_00473def
//                              pnl_dlg.cpp:104 (10)
//         00473dde     MOV        dword ptr [ESI + 0xd8],0x1
//                              pnl_dlg.cpp:124 (7)
//         00473de8     POP        EDI
//         00473de9     POP        ESI
//         00473dea     POP        EBP
//         00473deb     POP        EBX
//         00473dec     RET        0x18
//                               LAB_00473def                                                 XREF[1]:     00473ddc(j)
//                              pnl_dlg.cpp:108 (12)
//         00473def     MOV        this,dword ptr [ESP + param_5]
//         00473df3     MOV        EAX,dword ptr [ESI]
//         00473df5     PUSH       this
//         00473df6     MOV        this,ESI
//         00473df8     CALL       dword ptr [EAX + 0x10]
//                              pnl_dlg.cpp:111 (11)
//         00473dfb     PUSH       0x0
//         00473dfd     PUSH       offset DAT_fffffff8
//         00473dff     MOV        this,ESI
//         00473e01     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              pnl_dlg.cpp:114 (11)
//         00473e06     PUSH       ESI
//         00473e07     MOV        this,panel_system
//         00473e0c     CALL       TPanelSystem::setModalPanel                      void setModalPanel(TPanelSystem * this, TPane
//                              pnl_dlg.cpp:117 (7)
//         00473e11     MOV        this,dword ptr [ESI + 0x40]
//         00473e14     TEST       this,this
//         00473e16     JZ         LAB_00473e27
//                              pnl_dlg.cpp:119 (3)
//         00473e18     MOV        EDX,dword ptr [ECX + this->_padding_]
//                              pnl_dlg.cpp:120 (12)
//         00473e1b     PUSH       ESI
//         00473e1c     MOV        dword ptr [ESI + 0x47c],EDX
//         00473e22     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_00473e27                                                 XREF[1]:     00473e16(j)
//                              pnl_dlg.cpp:124 (12)
//         00473e27     POP        EDI
//         00473e28     POP        ESI
//         00473e29     POP        EBP
//         00473e2a     MOV        EAX,0x1
//         00473e2f     POP        EBX
//         00473e30     RET        0x18
//         00473e33     ??         90h
//         00473e34     NOP
//         00473e35     NOP
//         00473e36     NOP
//         00473e37     NOP
//         00473e38     NOP
//         00473e39     NOP
//         00473e3a     NOP
//         00473e3b     NOP
//         00473e3c     NOP
//         00473e3d     NOP
//         00473e3e     NOP
//         00473e3f     NOP
    return 0;
}

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall setup(TDialogPanel * this, TDrawArea * param_1, TPane
//              int               EAX:4          <RETURN>
//              TDialogPanel *    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00473d60(R), 00473dc0(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[3]:     00473d68(R), 00473da4(W), 00473dab(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00473d90(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00473d95(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00473def(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00473d8c(R)
//                               ?setup@TDialogPanel@@UAEHPAVTDrawArea@@PAVTPanel@@JJEH@Z     XREF[15]:    0056f738(*), 0056f878(*),
//                               TDialogPanel::setup                                                       0056f9c0(*), 0056faf0(*),
//                                                                                                         0056fc20(*), 0056fd58(*),
//                                                                                                         0056fe88(*), 0056ffb8(*),
//                                                                                                         005700e8(*), 00570218(*),
//                                                                                                         005711d8(*), 00571e18(*),
//                                                                                                         00572748(*), 00573890(*),
//                                                                                                         005766a8(*)
//                              pnl_dlg.cpp:87 (18)
//         00473d60     MOV        EAX,dword ptr [ESP + param_1]
//         00473d64     PUSH       EBX
//         00473d65     PUSH       EBP
//         00473d66     PUSH       ESI
//         00473d67     PUSH       EDI
//         00473d68     MOV        EDI,dword ptr [ESP + param_2]
//         00473d6c     TEST       EDI,EDI
//         00473d6e     MOV        ESI,this
//         00473d70     JZ         LAB_00473d86
//                              pnl_dlg.cpp:93 (7)
//         00473d72     MOV        this,EDI
//         00473d74     CALL       TPanel::width                                    long width(TPanel * this)
//                              pnl_dlg.cpp:94 (11)
//         00473d79     MOV        this,EDI
//         00473d7b     MOV        EBX,EAX
//         00473d7d     CALL       TPanel::height                                   long height(TPanel * this)
//         00473d82     MOV        EBP,EAX
//                              pnl_dlg.cpp:96 (2)
//         00473d84     JMP        LAB_00473d8c
//                               LAB_00473d86                                                 XREF[1]:     00473d70(j)
//                              pnl_dlg.cpp:98 (3)
//         00473d86     MOV        EBX,dword ptr [EAX + 0x18]
//                              pnl_dlg.cpp:99 (3)
//         00473d89     MOV        EBP,dword ptr [EAX + 0x1c]
//                               LAB_00473d8c                                                 XREF[1]:     00473d84(j)
//                              pnl_dlg.cpp:102 (82)
//         00473d8c     MOV        EAX,dword ptr [ESP + param_6]
//         00473d90     MOV        this,dword ptr [ESP + param_3]
//         00473d94     PUSH       EAX
//         00473d95     MOV        EAX,dword ptr [ESP + param_4]
//         00473d99     PUSH       EAX
//         00473d9a     PUSH       this
//         00473d9b     CDQ
//         00473d9c     SUB        EAX,EDX
//         00473d9e     MOV        EDX,EAX
//         00473da0     MOV        EAX,EBP
//         00473da2     SAR        EDX,0x1
//         00473da4     MOV        dword ptr [ESP + param_2],EDX
//         00473da8     CDQ
//         00473da9     SUB        EAX,EDX
//         00473dab     MOV        EDX,dword ptr [ESP + param_2]
//         00473daf     SAR        EAX,0x1
//         00473db1     SUB        EAX,EDX
//         00473db3     PUSH       EAX
//         00473db4     MOV        EAX,this
//         00473db6     CDQ
//         00473db7     SUB        EAX,EDX
//         00473db9     MOV        this,EAX
//         00473dbb     MOV        EAX,EBX
//         00473dbd     CDQ
//         00473dbe     SUB        EAX,EDX
//         00473dc0     MOV        EDX,dword ptr [ESP + param_1]
//         00473dc4     SAR        this,0x1
//         00473dc6     SAR        EAX,0x1
//         00473dc8     SUB        EAX,this
//         00473dca     MOV        this,ESI
//         00473dcc     PUSH       EAX
//         00473dcd     PUSH       0x0
//         00473dcf     PUSH       -0x1
//         00473dd1     PUSH       0x0
//         00473dd3     PUSH       EDI
//         00473dd4     PUSH       EDX
//         00473dd5     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
//         00473dda     TEST       EAX,EAX
//         00473ddc     JNZ        LAB_00473def
//                              pnl_dlg.cpp:104 (10)
//         00473dde     MOV        dword ptr [ESI + 0xd8],0x1
//                              pnl_dlg.cpp:124 (7)
//         00473de8     POP        EDI
//         00473de9     POP        ESI
//         00473dea     POP        EBP
//         00473deb     POP        EBX
//         00473dec     RET        0x18
//                               LAB_00473def                                                 XREF[1]:     00473ddc(j)
//                              pnl_dlg.cpp:108 (12)
//         00473def     MOV        this,dword ptr [ESP + param_5]
//         00473df3     MOV        EAX,dword ptr [ESI]
//         00473df5     PUSH       this
//         00473df6     MOV        this,ESI
//         00473df8     CALL       dword ptr [EAX + 0x10]
//                              pnl_dlg.cpp:111 (11)
//         00473dfb     PUSH       0x0
//         00473dfd     PUSH       offset DAT_fffffff8
//         00473dff     MOV        this,ESI
//         00473e01     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              pnl_dlg.cpp:114 (11)
//         00473e06     PUSH       ESI
//         00473e07     MOV        this,panel_system
//         00473e0c     CALL       TPanelSystem::setModalPanel                      void setModalPanel(TPanelSystem * this, TPane
//                              pnl_dlg.cpp:117 (7)
//         00473e11     MOV        this,dword ptr [ESI + 0x40]
//         00473e14     TEST       this,this
//         00473e16     JZ         LAB_00473e27
//                              pnl_dlg.cpp:119 (3)
//         00473e18     MOV        EDX,dword ptr [ECX + this->_padding_]
//                              pnl_dlg.cpp:120 (12)
//         00473e1b     PUSH       ESI
//         00473e1c     MOV        dword ptr [ESI + 0x47c],EDX
//         00473e22     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_00473e27                                                 XREF[1]:     00473e16(j)
//                              pnl_dlg.cpp:124 (12)
//         00473e27     POP        EDI
//         00473e28     POP        ESI
//         00473e29     POP        EBP
//         00473e2a     MOV        EAX,0x1
//         00473e2f     POP        EBX
//         00473e30     RET        0x18
//         00473e33     ??         90h
//         00473e34     NOP
//         00473e35     NOP
//         00473e36     NOP
//         00473e37     NOP
//         00473e38     NOP
//         00473e39     NOP
//         00473e3a     NOP
//         00473e3b     NOP
//         00473e3c     NOP
//         00473e3d     NOP
//         00473e3e     NOP
//         00473e3f     NOP
    return 0;
}

TDialogPanel::~TDialogPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TDialogPanel(TDialogPanel * this)
//              void              <VOID>         <RETURN>
//              TDialogPanel *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00473e68(W), 00473ea3(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00473e59(W)
//                               ??1TDialogPanel@@UAE@XZ                                      XREF[13]:    ~TribeAboutDialog:0043b3e9(c),
//                               TDialogPanel::~TDialogPanel                                               ~TribeConfigDialog:0043c28e(c),
//                                                                                                         ~TribeDiplomacyDialog:0043d886(c),
//                                                                                                         ~THelpDialog:0043e9c5(c),
//                                                                                                         ~TListDialog:0043ef65(c),
//                                                                                                         ~TribeMenuDialog:0043f700(c),
//                                                                                                         ~TMessageDialog:0043fd34(c),
//                                                                                                         ~TRIBE_Dialog_Sed_Menu:004403dc(c)
//                                                                                                         ~TribeSendMessageDialog:00440f08(c
//                                                                                                         ~TribeSendQuickMessageDialog:00441
//                                                                                                         `vector_deleting_destructor':00473
//                                                                                                         ~TribeMPCreateDialog:004923a9(c),
//                                                                                                         ~TRIBE_Dialog_Name:004a6fd9(c)
//                              pnl_dlg.cpp:130 (35)
//         00473e40     PUSH       -0x1
//         00473e42     PUSH       FUN_0055e3e8
//         00473e47     MOV        EAX,FS:[0x0]
//         00473e4d     PUSH       EAX
//         00473e4e     MOV        dword ptr FS:[0x0],ESP
//         00473e55     PUSH       this
//         00473e56     PUSH       ESI
//         00473e57     MOV        ESI,this
//         00473e59     MOV        dword ptr [ESP + local_10],ESI
//         00473e5d     MOV        dword ptr [ESI],TDialogPanel::`vftable'          = 00473c60
//                              pnl_dlg.cpp:135 (22)
//         00473e63     MOV        this,panel_system
//         00473e68     MOV        dword ptr [ESP + local_4],0x0
//         00473e70     CALL       TPanelSystem::restorePreviousModalPanel          int restorePreviousModalPanel(TPanelSystem *
//         00473e75     TEST       EAX,EAX
//         00473e77     JNZ        LAB_00473e84
//                              pnl_dlg.cpp:136 (11)
//         00473e79     PUSH       EAX
//         00473e7a     MOV        this,panel_system
//         00473e7f     CALL       TPanelSystem::setModalPanel                      void setModalPanel(TPanelSystem * this, TPane
//                               LAB_00473e84                                                 XREF[1]:     00473e77(j)
//                              pnl_dlg.cpp:139 (7)
//         00473e84     MOV        this,dword ptr [ESI + 0x40]
//         00473e87     TEST       this,this
//         00473e89     JZ         LAB_00473ea1
//                              pnl_dlg.cpp:141 (7)
//         00473e8b     MOV        EAX,dword ptr [this->_padding_]
//         00473e8d     PUSH       0x2
//         00473e8f     CALL       dword ptr [EAX + 0x20]
//                              pnl_dlg.cpp:142 (17)
//         00473e92     MOV        this,dword ptr [ESI + 0x47c]
//         00473e98     PUSH       this
//         00473e99     MOV        this,dword ptr [ESI + 0x40]
//         00473e9c     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_00473ea1                                                 XREF[1]:     00473e89(j)
//         00473ea1     MOV        this,ESI
//                              pnl_dlg.cpp:144 (29)
//         00473ea3     MOV        dword ptr [ESP + local_4],0xffffffff
//         00473eab     CALL       TEasy_Panel::~TEasy_Panel                        void ~TEasy_Panel(TEasy_Panel * this)
//         00473eb0     MOV        this,dword ptr [ESP + 0x8]
//         00473eb4     POP        ESI
//         00473eb5     MOV        dword ptr FS:[0x0],this
//         00473ebc     ADD        ESP,0x10
//         00473ebf     RET
}

void TDialogPanel::set_focus(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_focus(TDialogPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TDialogPanel *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00473ec0(R)
//                               ?set_focus@TDialogPanel@@UAEXH@Z                             XREF[15]:    0056f6d0(*), 0056f810(*),
//                               TDialogPanel::set_focus                                                   0056f958(*), 0056fa88(*),
//                                                                                                         0056fbb8(*), 0056fcf0(*),
//                                                                                                         0056fe20(*), 0056ff50(*),
//                                                                                                         00570080(*), 005701b0(*),
//                                                                                                         00571170(*), 00571db0(*),
//                                                                                                         005726e0(*), 00573828(*),
//                                                                                                         00576640(*)
//                              pnl_dlg.cpp:150 (10)
//         00473ec0     MOV        EAX,dword ptr [ESP + param_1]
//         00473ec4     PUSH       EAX
//         00473ec5     CALL       TEasy_Panel::set_focus                           void set_focus(TEasy_Panel * this, int param_1)
//                              pnl_dlg.cpp:152 (3)
//         00473eca     RET        0x4
//         00473ecd     ??         90h
//         00473ece     NOP
//         00473ecf     NOP
    return;
}

