#include "common.h"
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

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

