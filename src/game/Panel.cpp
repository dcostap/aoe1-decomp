#include "../common.h"
#include "Panel.h"

TPanelSystem::TPanelSystem() {
    /* TODO: Stub */
//                              undefined __thiscall TPanelSystem(TPanelSystem * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ??0TPanelSystem@@QAE@XZ                                      XREF[1]:     $E1:00463bb5(c)
//                               TPanelSystem::TPanelSystem
//                              Panel.cpp:49 (75)
//         00463be0     PUSH       ESI
//         00463be1     MOV        ESI,this
//         00463be3     MOV        EAX,0x1
//         00463be8     XOR        EDX,EDX
//         00463bea     PUSH       EDI
//         00463beb     MOV        dword ptr [ESI + 0xac0],EAX
//         00463bf1     MOV        dword ptr [ESI + 0xac8],EAX
//         00463bf7     MOV        dword ptr [ESI],EDX
//         00463bf9     MOV        dword ptr [ESI + 0x4],EDX
//         00463bfc     MOV        dword ptr [ESI + 0x8],EDX
//         00463bff     MOV        dword ptr [ESI + 0xc],EDX
//         00463c02     MOV        dword ptr [ESI + 0x10],EDX
//         00463c05     MOV        dword ptr [ESI + 0x14],EDX
//         00463c08     MOV        dword ptr [ESI + 0x18],EDX
//         00463c0b     MOV        dword ptr [ESI + 0xabc],EDX
//         00463c11     MOV        dword ptr [ESI + 0xac4],EDX
//         00463c17     MOV        dword ptr [ESI + 0xacc],EDX
//         00463c1d     LEA        EAX,[ESI + 0xa6c]
//         00463c23     LEA        this,[ESI + 0x44]
//         00463c26     MOV        EDI,0xa
//                               LAB_00463c2b                                                 XREF[1]:     00463c42(j)
//                              Panel.cpp:54 (6)
//         00463c2b     MOV        dword ptr [EAX + 0xfffff5b0],EDX
//                              Panel.cpp:55 (2)
//         00463c31     MOV        byte ptr [this->mouseOwnerValue],DL
//                              Panel.cpp:56 (2)
//         00463c33     MOV        dword ptr [EAX],EDX
//                              Panel.cpp:57 (15)
//         00463c35     MOV        dword ptr [EAX + 0x28],EDX
//         00463c38     ADD        EAX,0x4
//         00463c3b     ADD        this,0x104
//         00463c41     DEC        EDI
//         00463c42     JNZ        LAB_00463c2b
//                              Panel.cpp:60 (7)
//         00463c44     MOV        this,ESI
//         00463c46     CALL       TPanelSystem::setup                              int setup(TPanelSystem * this)
//                              Panel.cpp:61 (5)
//         00463c4b     MOV        EAX,ESI
//         00463c4d     POP        EDI
//         00463c4e     POP        ESI
//         00463c4f     RET
}

TPanelSystem::~TPanelSystem() {
    /* TODO: Stub */
//                              void __thiscall ~TPanelSystem(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00463cae(W)
//                               ??1TPanelSystem@@QAE@XZ                                      XREF[1]:     $E2:00463bd5(c)
//                               TPanelSystem::~TPanelSystem
//                              Panel.cpp:66 (7)
//         00463c50     PUSH       this
//         00463c51     PUSH       EBX
//         00463c52     PUSH       EBP
//         00463c53     PUSH       ESI
//         00463c54     PUSH       EDI
//         00463c55     MOV        EBP,this
//                              Panel.cpp:70 (5)
//         00463c57     CALL       TPanelSystem::restore_system_colors              void restore_system_colors(TPanelSystem * this)
//                              Panel.cpp:74 (7)
//         00463c5c     MOV        EAX,dword ptr [EBP + 0x10]
//         00463c5f     TEST       EAX,EAX
//         00463c61     JZ         LAB_00463ca2
//                              Panel.cpp:75 (3)
//         00463c63     MOV        ESI,dword ptr [EAX + 0x8]
//                              Panel.cpp:76 (4)
//         00463c66     CMP        ESI,EAX
//         00463c68     JZ         LAB_00463c8f
//                               LAB_00463c6a                                                 XREF[1]:     00463c8d(j)
//                              Panel.cpp:77 (3)
//         00463c6a     MOV        ESI,dword ptr [ESI + 0x8]
//                              Panel.cpp:82 (15)
//         00463c6d     MOV        EAX,dword ptr [ESI + 0x4]
//         00463c70     MOV        this,dword ptr [EAX]
//         00463c72     TEST       this,this
//         00463c74     JZ         LAB_00463c7c
//         00463c76     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         00463c78     PUSH       0x1
//         00463c7a     CALL       dword ptr [EDX]
//                               LAB_00463c7c                                                 XREF[1]:     00463c74(j)
//                              Panel.cpp:84 (19)
//         00463c7c     MOV        EAX,dword ptr [ESI + 0x4]
//         00463c7f     PUSH       EAX
//         00463c80     CALL       free                                             undefined free()
//         00463c85     MOV        EAX,dword ptr [EBP + 0x10]
//         00463c88     ADD        ESP,0x4
//         00463c8b     CMP        ESI,EAX
//         00463c8d     JNZ        LAB_00463c6a
//                               LAB_00463c8f                                                 XREF[1]:     00463c68(j)
//                              Panel.cpp:86 (12)
//         00463c8f     MOV        this,dword ptr [EBP + 0x10]
//         00463c92     PUSH       this
//         00463c93     CALL       free                                             undefined free()
//         00463c98     ADD        ESP,0x4
//                              Panel.cpp:87 (7)
//         00463c9b     MOV        dword ptr [EBP + 0x10],0x0
//                               LAB_00463ca2                                                 XREF[1]:     00463c61(j)
//                              Panel.cpp:91 (20)
//         00463ca2     MOV        EBX,dword ptr [->GDI32.DLL::DeleteObject]        = 0048b160
//         00463ca8     LEA        EDI,[EBP + 0x44]
//         00463cab     LEA        ESI,[EBP + 0x1c]
//         00463cae     MOV        dword ptr [ESP + local_4],0xa
//                               LAB_00463cb6                                                 XREF[1]:     00463ce3(j)
//                              Panel.cpp:92 (6)
//         00463cb6     MOV        EAX,dword ptr [ESI]
//         00463cb8     TEST       EAX,EAX
//         00463cba     JZ         LAB_00463cd1
//                              Panel.cpp:93 (3)
//         00463cbc     PUSH       EAX
//         00463cbd     CALL       EBX=>GDI32.DLL::DeleteObject
//                              Panel.cpp:94 (4)
//         00463cbf     XOR        EAX,EAX
//         00463cc1     MOV        dword ptr [ESI],EAX
//                              Panel.cpp:95 (2)
//         00463cc3     MOV        byte ptr [EDI],AL
//                              Panel.cpp:96 (6)
//         00463cc5     MOV        dword ptr [ESI + 0xa50],EAX
//                              Panel.cpp:97 (26)
//         00463ccb     MOV        dword ptr [EBP + 0xa94],EAX
//                               LAB_00463cd1                                                 XREF[1]:     00463cba(j)
//         00463cd1     MOV        EAX,dword ptr [ESP + 0x10]
//         00463cd5     ADD        ESI,0x4
//         00463cd8     ADD        EDI,0x104
//         00463cde     DEC        EAX
//         00463cdf     MOV        dword ptr [ESP + 0x10],EAX
//         00463ce3     JNZ        LAB_00463cb6
//                              Panel.cpp:102 (7)
//         00463ce5     MOV        this,EBP
//         00463ce7     CALL       TPanelSystem::EnableIME                          void EnableIME(TPanelSystem * this)
//                              Panel.cpp:103 (6)
//         00463cec     POP        EDI
//         00463ced     POP        ESI
//         00463cee     POP        EBP
//         00463cef     POP        EBX
//         00463cf0     POP        this
//         00463cf1     RET
//         00463cf2     ??         90h
//         00463cf3     NOP
//         00463cf4     NOP
//         00463cf5     NOP
//         00463cf6     NOP
//         00463cf7     NOP
//         00463cf8     NOP
//         00463cf9     NOP
//         00463cfa     NOP
//         00463cfb     NOP
//         00463cfc     NOP
//         00463cfd     NOP
//         00463cfe     NOP
//         00463cff     NOP
}

TPanel* TPanelSystem::currentPanel() {
    /* TODO: Stub */
//                              TPanel * __thiscall currentPanel(TPanelSystem * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?currentPanel@TPanelSystem@@QBEPAVTPanel@@XZ                 XREF[31]:    wnd_proc:00420774(c),
//                               TPanelSystem::currentPanel                                                wnd_proc:00420790(c),
//                                                                                                         wnd_proc:00420b4d(c),
//                                                                                                         wnd_proc:00420b5f(c),
//                                                                                                         handle_idle:0042103e(c),
//                                                                                                         handle_idle:0042105a(c),
//                                                                                                         handle_paint:004215c3(c),
//                                                                                                         handle_paint:004215e9(c),
//                                                                                                         handle_paint:004215fc(c),
//                                                                                                         handle_activate:0042188a(c),
//                                                                                                         handle_activate:00421898(c),
//                                                                                                         sub_wnd_proc:004763e0(c),
//                                                                                                         handle_idle:00496768(c),
//                                                                                                         handle_game_update:00496ed7(c),
//                                                                                                         TribeLoadSavedGameScreen:0049ddce(
//                                                                                                         TribeSaveGameScreen:004a72b9(c),
//                                                                                                         TRIBE_Screen_Sed_Open:004b3454(c),
//                                                                                                         TRIBE_Screen_Status_Message:004b71
//                                                                                                         TRIBE_Screen_Status_Message:004b73
//                                                                                                         TRIBE_Mission_Screen:004b8185(c),
//                                                                                                         [more]
//                              Panel.cpp:108 (3)
//         00463d00     MOV        EAX,dword ptr [ECX + this->currentPanelValue]
//                              Panel.cpp:110 (1)
//         00463d03     RET
//         00463d04     ??         90h
//         00463d05     NOP
//         00463d06     NOP
//         00463d07     NOP
//         00463d08     NOP
//         00463d09     NOP
//         00463d0a     NOP
//         00463d0b     NOP
//         00463d0c     NOP
//         00463d0d     NOP
//         00463d0e     NOP
//         00463d0f     NOP
    return 0;
}

TPanel* TPanelSystem::previousPanel() {
    /* TODO: Stub */
//                              TPanel * __thiscall previousPanel(TPanelSystem * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?previousPanel@TPanelSystem@@QBEPAVTPanel@@XZ
//                               TPanelSystem::previousPanel
//                              Panel.cpp:115 (7)
//         00463d10     MOV        this,dword ptr [ECX + this->currentPanelValue]
//         00463d13     TEST       this,this
//         00463d15     JZ         LAB_00463d1c
//                              Panel.cpp:117 (5)
//         00463d17     JMP        TPanel::previousPanel                            TPanel * previousPanel(TPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_00463d1c                                                 XREF[1]:     00463d15(j)
//                              Panel.cpp:118 (2)
//         00463d1c     XOR        EAX,EAX
//                              Panel.cpp:119 (1)
//         00463d1e     RET
//         00463d1f     ??         90h
    return 0;
}

TPanel* TPanelSystem::mouseOwner() {
    /* TODO: Stub */
//                              TPanel * __thiscall mouseOwner(TPanelSystem * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?mouseOwner@TPanelSystem@@QBEPAVTPanel@@XZ                   XREF[10]:    wnd_proc:00465514(c),
//                               TPanelSystem::mouseOwner                                                  wnd_proc:00465522(c),
//                                                                                                         capture_mouse:00466228(c),
//                                                                                                         capture_mouse:00466236(c),
//                                                                                                         capture_mouse:00466248(c),
//                                                                                                         release_mouse:0046628f(c),
//                                                                                                         handle_game_update:00496c10(c),
//                                                                                                         handle_game_update:00496c1e(c),
//                                                                                                         do_auto_scroll:0053dc19(c),
//                                                                                                         do_auto_scroll:0053dc27(c)
//                              Panel.cpp:124 (2)
//         00463d20     MOV        EAX,dword ptr [this->mouseOwnerValue]
//                              Panel.cpp:126 (1)
//         00463d22     RET
//         00463d23     ??         90h
//         00463d24     NOP
//         00463d25     NOP
//         00463d26     NOP
//         00463d27     NOP
//         00463d28     NOP
//         00463d29     NOP
//         00463d2a     NOP
//         00463d2b     NOP
//         00463d2c     NOP
//         00463d2d     NOP
//         00463d2e     NOP
//         00463d2f     NOP
    return 0;
}

TPanel* TPanelSystem::keyboardOwner() {
    /* TODO: Stub */
//                              TPanel * __thiscall keyboardOwner(TPanelSystem * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?keyboardOwner@TPanelSystem@@QBEPAVTPanel@@XZ                XREF[4]:     wnd_proc:0046552b(c),
//                               TPanelSystem::keyboardOwner                                               wnd_proc:00465539(c),
//                                                                                                         wnd_proc:00465699(c),
//                                                                                                         wnd_proc:004656a7(c)
//                              Panel.cpp:131 (3)
//         00463d30     MOV        EAX,dword ptr [ECX + this->keyboardOwnerValue]
//                              Panel.cpp:133 (1)
//         00463d33     RET
//         00463d34     ??         90h
//         00463d35     NOP
//         00463d36     NOP
//         00463d37     NOP
//         00463d38     NOP
//         00463d39     NOP
//         00463d3a     NOP
//         00463d3b     NOP
//         00463d3c     NOP
//         00463d3d     NOP
//         00463d3e     NOP
//         00463d3f     NOP
    return 0;
}

TPanel* TPanelSystem::modalPanel() {
    /* TODO: Stub */
//                              TPanel * __thiscall modalPanel(TPanelSystem * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?modalPanel@TPanelSystem@@QBEPAVTPanel@@XZ                   XREF[10]:    wnd_proc:00465542(c),
//                               TPanelSystem::modalPanel                                                  wnd_proc:00465550(c),
//                                                                                                         wnd_proc:004656b0(c),
//                                                                                                         wnd_proc:004656be(c),
//                                                                                                         set_overlapped_redraw:004959bc(c),
//                                                                                                         key_down_action:00497466(c),
//                                                                                                         handle_mouse_pointing_at:0049bb27(
//                                                                                                         handle_idle:004ab77d(c),
//                                                                                                         key_down_action:004ab7da(c),
//                                                                                                         do_auto_scroll:0053dc07(c)
//                              Panel.cpp:138 (3)
//         00463d40     MOV        EAX,dword ptr [ECX + this->modalPanelValue]
//                              Panel.cpp:140 (1)
//         00463d43     RET
//         00463d44     ??         90h
//         00463d45     NOP
//         00463d46     NOP
//         00463d47     NOP
//         00463d48     NOP
//         00463d49     NOP
//         00463d4a     NOP
//         00463d4b     NOP
//         00463d4c     NOP
//         00463d4d     NOP
//         00463d4e     NOP
//         00463d4f     NOP
    return 0;
}

TPanel* TPanelSystem::panel(char* param_1) {
    /* TODO: Stub */
//                              TPanel * __thiscall panel(TPanelSystem * this, char * param_1)
//              TPanel *          EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00463d50(R)
//                               ?panel@TPanelSystem@@QAEPAVTPanel@@PAD@Z                     XREF[23]:    action:0043b43f(c),
//                               TPanelSystem::panel                                                       popupOKDialog:00469f96(c),
//                                                                                                         close_screen:00492dd0(c),
//                                                                                                         handle_paint:004965d7(c),
//                                                                                                         handle_paint:004965eb(c),
//                                                                                                         handle_game_update:00496f8c(c),
//                                                                                                         handle_game_update:00496fa0(c),
//                                                                                                         action:0049e601(c),
//                                                                                                         action:004a1a79(c),
//                                                                                                         action:004a7129(c),
//                                                                                                         save_for_scenario_editor:004a80f1(
//                                                                                                         TribeGameSettingsScreen:004b48ca(c
//                                                                                                         TRIBE_Screen_Status_Message:004b71
//                                                                                                         TRIBE_Screen_Status_Message:004b73
//                                                                                                         setup:00521f40(c),
//                                                                                                         get_view_panel:00523485(c),
//                                                                                                         show_status_message:005236c3(c),
//                                                                                                         restart_game:005244fd(c),
//                                                                                                         start_scenario_editor:00528ee0(c),
//                                                                                                         start_scenario_editor:00528efc(c),
//                                                                                                         [more]
//                              Panel.cpp:145 (10)
//         00463d50     MOV        EAX,dword ptr [ESP + param_1]
//         00463d54     PUSH       EAX
//         00463d55     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//                              Panel.cpp:147 (4)
//         00463d5a     TEST       EAX,EAX
//         00463d5c     JZ         LAB_00463d63
//                              Panel.cpp:148 (2)
//         00463d5e     MOV        EAX,dword ptr [EAX]
//                              Panel.cpp:150 (3)
//         00463d60     RET        0x4
//                               LAB_00463d63                                                 XREF[1]:     00463d5c(j)
//                              Panel.cpp:149 (2)
//         00463d63     XOR        EAX,EAX
//                              Panel.cpp:150 (3)
//         00463d65     RET        0x4
//         00463d68     ??         90h
//         00463d69     NOP
//         00463d6a     NOP
//         00463d6b     NOP
//         00463d6c     NOP
//         00463d6d     NOP
//         00463d6e     NOP
//         00463d6f     NOP
    return 0;
}

int TPanelSystem::numberActivePanels() {
    /* TODO: Stub */
//                              int __thiscall numberActivePanels(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?numberActivePanels@TPanelSystem@@QBEHXZ
//                               TPanelSystem::numberActivePanels
//                              Panel.cpp:155 (3)
//         00463d70     MOV        EAX,dword ptr [ECX + this->numberActivePanelsV
//                              Panel.cpp:157 (1)
//         00463d73     RET
//         00463d74     ??         90h
//         00463d75     NOP
//         00463d76     NOP
//         00463d77     NOP
//         00463d78     NOP
//         00463d79     NOP
//         00463d7a     NOP
//         00463d7b     NOP
//         00463d7c     NOP
//         00463d7d     NOP
//         00463d7e     NOP
//         00463d7f     NOP
    return 0;
}

int TPanelSystem::addPanel(TPanel* param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall addPanel(TPanelSystem * this, TPanel * param_1, int p
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00463d81(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00463de1(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00463de9(R)
//                               ?addPanel@TPanelSystem@@QAEHPAVTPanel@@HH@Z                  XREF[1]:     TPanel:00464876(c)
//                               TPanelSystem::addPanel
//                              Panel.cpp:162 (1)
//         00463d80     PUSH       EBX
//                              Panel.cpp:164 (23)
//         00463d81     MOV        EBX,dword ptr [ESP + param_1]
//         00463d85     PUSH       ESI
//         00463d86     PUSH       EDI
//         00463d87     MOV        EDI,this
//         00463d89     MOV        this,EBX
//         00463d8b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         00463d90     PUSH       EAX
//         00463d91     MOV        this,EDI
//         00463d93     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//                              Panel.cpp:165 (4)
//         00463d98     TEST       EAX,EAX
//         00463d9a     JNZ        LAB_00463de1
//                              Panel.cpp:168 (14)
//         00463d9c     PUSH       0xc
//         00463d9e     PUSH       0x1
//         00463da0     CALL       calloc                                           undefined calloc()
//         00463da5     MOV        ESI,EAX
//         00463da7     ADD        ESP,0x8
//                              Panel.cpp:169 (4)
//         00463daa     TEST       ESI,ESI
//         00463dac     JNZ        LAB_00463db4
//                              Panel.cpp:190 (6)
//         00463dae     POP        EDI
//         00463daf     POP        ESI
//         00463db0     POP        EBX
//         00463db1     RET        0xc
//                               LAB_00463db4                                                 XREF[1]:     00463dac(j)
//                              Panel.cpp:174 (11)
//         00463db4     PUSH       0x0
//         00463db6     MOV        this,EBX
//         00463db8     MOV        dword ptr [ESI],EBX
//         00463dba     CALL       TPanel::setPreviousPanel                         void setPreviousPanel(TPanel * this, TPanel *
//                              Panel.cpp:177 (9)
//         00463dbf     MOV        EAX,dword ptr [EDI + 0x10]
//         00463dc2     MOV        this,dword ptr [EAX + 0x4]
//         00463dc5     MOV        dword ptr [ESI + 0x4],this
//                              Panel.cpp:178 (6)
//         00463dc8     MOV        EDX,dword ptr [EDI + 0x10]
//         00463dcb     MOV        dword ptr [ESI + 0x8],EDX
//                              Panel.cpp:179 (6)
//         00463dce     MOV        EAX,dword ptr [EDI + 0x10]
//         00463dd1     MOV        dword ptr [EAX + 0x4],ESI
//                              Panel.cpp:180 (6)
//         00463dd4     MOV        this,dword ptr [ESI + 0x4]
//         00463dd7     MOV        dword ptr [ECX + this->modalPanelValue],ESI
//                              Panel.cpp:182 (7)
//         00463dda     MOV        EAX,dword ptr [EDI + 0x14]
//         00463ddd     INC        EAX
//         00463dde     MOV        dword ptr [EDI + 0x14],EAX
//                               LAB_00463de1                                                 XREF[1]:     00463d9a(j)
//                              Panel.cpp:187 (8)
//         00463de1     MOV        EAX,dword ptr [ESP + param_2]
//         00463de5     TEST       EAX,EAX
//         00463de7     JZ         LAB_00463df6
//                              Panel.cpp:188 (13)
//         00463de9     MOV        EDX,dword ptr [ESP + param_3]
//         00463ded     MOV        this,EDI
//         00463def     PUSH       EDX
//         00463df0     PUSH       EBX
//         00463df1     CALL       TPanelSystem::setCurrentPanel                    void setCurrentPanel(TPanelSystem * this, TPa
//                               LAB_00463df6                                                 XREF[1]:     00463de7(j)
//                              Panel.cpp:190 (11)
//         00463df6     POP        EDI
//         00463df7     POP        ESI
//         00463df8     MOV        EAX,0x1
//         00463dfd     POP        EBX
//         00463dfe     RET        0xc
//         00463e01     ??         90h
//         00463e02     NOP
//         00463e03     NOP
//         00463e04     NOP
//         00463e05     NOP
//         00463e06     NOP
//         00463e07     NOP
//         00463e08     NOP
//         00463e09     NOP
//         00463e0a     NOP
//         00463e0b     NOP
//         00463e0c     NOP
//         00463e0d     NOP
//         00463e0e     NOP
//         00463e0f     NOP
    return 0;
}

int TPanelSystem::removePanel(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall removePanel(TPanelSystem * this, char * param_1)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00463e10(R)
//                               ?removePanel@TPanelSystem@@QAEHPAD@Z                         XREF[1]:     ~TPanel:00464a11(c)
//                               TPanelSystem::removePanel
//                              Panel.cpp:195 (11)
//         00463e10     MOV        EAX,dword ptr [ESP + param_1]
//         00463e14     PUSH       ESI
//         00463e15     TEST       EAX,EAX
//         00463e17     MOV        ESI,this
//         00463e19     JNZ        LAB_00463e1f
//                              Panel.cpp:217 (4)
//         00463e1b     POP        ESI
//         00463e1c     RET        0x4
//                               LAB_00463e1f                                                 XREF[1]:     00463e19(j)
//                              Panel.cpp:201 (8)
//         00463e1f     PUSH       EAX
//         00463e20     MOV        this,ESI
//         00463e22     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//                              Panel.cpp:202 (4)
//         00463e27     TEST       EAX,EAX
//         00463e29     JNZ        LAB_00463e2f
//                              Panel.cpp:217 (4)
//         00463e2b     POP        ESI
//         00463e2c     RET        0x4
//                               LAB_00463e2f                                                 XREF[1]:     00463e29(j)
//                              Panel.cpp:206 (3)
//         00463e2f     MOV        EDX,dword ptr [ESI + 0x14]
//                              Panel.cpp:215 (31)
//         00463e32     PUSH       EAX
//         00463e33     DEC        EDX
//         00463e34     MOV        dword ptr [ESI + 0x14],EDX
//         00463e37     MOV        this,dword ptr [EAX + 0x4]
//         00463e3a     MOV        EDX,dword ptr [EAX + 0x8]
//         00463e3d     MOV        dword ptr [ECX + this->modalPanelValue],EDX
//         00463e40     MOV        this,dword ptr [EAX + 0x8]
//         00463e43     MOV        EDX,dword ptr [EAX + 0x4]
//         00463e46     MOV        dword ptr [ECX + this->keyboardOwnerValue],EDX
//         00463e49     CALL       free                                             undefined free()
//         00463e4e     ADD        ESP,0x4
//                              Panel.cpp:216 (5)
//         00463e51     MOV        EAX,0x1
//                              Panel.cpp:217 (4)
//         00463e56     POP        ESI
//         00463e57     RET        0x4
//         00463e5a     ??         90h
//         00463e5b     NOP
//         00463e5c     NOP
//         00463e5d     NOP
//         00463e5e     NOP
//         00463e5f     NOP
    return 0;
}

int TPanelSystem::restorePreviousPanel(int param_1) {
    /* TODO: Stub */
//                              int __thiscall restorePreviousPanel(TPanelSystem * this, int param_1)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00463ed5(R)
//                               ?restorePreviousPanel@TPanelSystem@@QAEHH@Z                  XREF[1]:     close_status_message:005237a7(c)
//                               TPanelSystem::restorePreviousPanel
//                              Panel.cpp:245 (5)
//         00463eb0     PUSH       EBX
//         00463eb1     PUSH       ESI
//         00463eb2     PUSH       EDI
//         00463eb3     MOV        EDI,this
//                              Panel.cpp:248 (7)
//         00463eb5     MOV        this,dword ptr [EDI + 0xc]
//         00463eb8     TEST       this,this
//         00463eba     JNZ        LAB_00463ec4
//                              Panel.cpp:249 (2)
//         00463ebc     XOR        EAX,EAX
//                              Panel.cpp:278 (6)
//         00463ebe     POP        EDI
//         00463ebf     POP        ESI
//         00463ec0     POP        EBX
//         00463ec1     RET        0x4
//                               LAB_00463ec4                                                 XREF[1]:     00463eba(j)
//                              Panel.cpp:250 (7)
//         00463ec4     CALL       TPanel::previousPanel                            TPanel * previousPanel(TPanel * this)
//         00463ec9     MOV        ESI,EAX
//                              Panel.cpp:251 (4)
//         00463ecb     TEST       ESI,ESI
//         00463ecd     JNZ        LAB_00463ed5
//                              Panel.cpp:278 (6)
//         00463ecf     POP        EDI
//         00463ed0     POP        ESI
//         00463ed1     POP        EBX
//         00463ed2     RET        0x4
//                               LAB_00463ed5                                                 XREF[1]:     00463ecd(j)
//                              Panel.cpp:261 (11)
//         00463ed5     MOV        EAX,dword ptr [ESP + param_1]
//         00463ed9     MOV        EBX,dword ptr [EDI + 0xc]
//         00463edc     TEST       EAX,EAX
//         00463ede     JNZ        LAB_00463eea
//                              Panel.cpp:263 (8)
//         00463ee0     PUSH       EBX
//         00463ee1     MOV        this,ESI
//         00463ee3     CALL       TPanel::setPreviousPanel                         void setPreviousPanel(TPanel * this, TPanel *
//                              Panel.cpp:265 (2)
//         00463ee8     JMP        LAB_00463f0d
//                               LAB_00463eea                                                 XREF[1]:     00463ede(j)
//                              Panel.cpp:266 (11)
//         00463eea     MOV        this,ESI
//         00463eec     CALL       TPanel::previousPanel                            TPanel * previousPanel(TPanel * this)
//         00463ef1     CMP        EAX,EBX
//         00463ef3     JNZ        LAB_00463efe
//                              Panel.cpp:267 (9)
//         00463ef5     PUSH       0x0
//         00463ef7     MOV        this,ESI
//         00463ef9     CALL       TPanel::setPreviousPanel                         void setPreviousPanel(TPanel * this, TPanel *
//                               LAB_00463efe                                                 XREF[1]:     00463ef3(j)
//                              Panel.cpp:268 (15)
//         00463efe     MOV        this,EBX
//         00463f00     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         00463f05     PUSH       EAX
//         00463f06     MOV        this,EDI
//         00463f08     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                               LAB_00463f0d                                                 XREF[1]:     00463ee8(j)
//                              Panel.cpp:273 (15)
//         00463f0d     MOV        EAX,dword ptr [ESI]
//         00463f0f     PUSH       0x1
//         00463f11     MOV        this,ESI
//         00463f13     MOV        dword ptr [EDI + 0xc],ESI
//         00463f16     CALL       dword ptr [EAX + 0xc0]
//                              Panel.cpp:274 (10)
//         00463f1c     MOV        this,dword ptr [EDI + 0xc]
//         00463f1f     PUSH       0x2
//         00463f21     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         00463f23     CALL       dword ptr [EDX + 0x20]
//                              Panel.cpp:275 (12)
//         00463f26     MOV        EAX,[AppWnd]                                     = 00000000
//         00463f2b     PUSH       EAX
//         00463f2c     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
//                              Panel.cpp:278 (11)
//         00463f32     POP        EDI
//         00463f33     POP        ESI
//         00463f34     MOV        EAX,0x1
//         00463f39     POP        EBX
//         00463f3a     RET        0x4
//         00463f3d     ??         90h
//         00463f3e     NOP
//         00463f3f     NOP
    return 0;
}

void TPanelSystem::setMouseOwner(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall setMouseOwner(TPanelSystem * this, TPanel * param_1)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00463f40(R)
//                               ?setMouseOwner@TPanelSystem@@QAEXPAVTPanel@@@Z               XREF[3]:     restorePreviousModalPanel:0046403d
//                               TPanelSystem::setMouseOwner                                               capture_mouse:0046626b(c),
//                                                                                                         release_mouse:0046629f(c)
//                              Panel.cpp:283 (6)
//         00463f40     MOV        EAX,dword ptr [ESP + param_1]
//         00463f44     MOV        dword ptr [this->mouseOwnerValue],EAX
//                              Panel.cpp:285 (3)
//         00463f46     RET        0x4
//         00463f49     ??         90h
//         00463f4a     NOP
//         00463f4b     NOP
//         00463f4c     NOP
//         00463f4d     NOP
//         00463f4e     NOP
//         00463f4f     NOP
    return;
}

void TPanelSystem::setKeyboardOwner(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall setKeyboardOwner(TPanelSystem * this, TPanel * param
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00463f50(R)
//                               ?setKeyboardOwner@TPanelSystem@@QAEXPAVTPanel@@@Z            XREF[1]:     restorePreviousModalPanel:00464045
//                               TPanelSystem::setKeyboardOwner
//                              Panel.cpp:290 (7)
//         00463f50     MOV        EAX,dword ptr [ESP + param_1]
//         00463f54     MOV        dword ptr [ECX + this->keyboardOwnerValue],EAX
//                              Panel.cpp:292 (3)
//         00463f57     RET        0x4
//         00463f5a     ??         90h
//         00463f5b     NOP
//         00463f5c     NOP
//         00463f5d     NOP
//         00463f5e     NOP
//         00463f5f     NOP
    return;
}

void TPanelSystem::setModalPanel(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall setModalPanel(TPanelSystem * this, TPanel * param_1)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00463f64(R)
//                               ?setModalPanel@TPanelSystem@@QAEXPAVTPanel@@@Z               XREF[5]:     setup:00473d4a(c),
//                               TPanelSystem::setModalPanel                                               setup:00473e0c(c),
//                                                                                                         ~TDialogPanel:00473e7f(c),
//                                                                                                         set_mode:00474ab7(c),
//                                                                                                         set_mode:004750da(c)
//                              Panel.cpp:297 (4)
//         00463f60     PUSH       ESI
//         00463f61     MOV        ESI,this
//         00463f63     PUSH       EDI
//                              Panel.cpp:301 (15)
//         00463f64     MOV        EDI,dword ptr [ESP + param_1]
//         00463f68     MOV        EAX,dword ptr [ESI + 0x8]
//         00463f6b     TEST       EAX,EAX
//         00463f6d     JZ         LAB_00463f7b
//         00463f6f     TEST       EDI,EDI
//         00463f71     JZ         LAB_00463f7b
//                              Panel.cpp:302 (8)
//         00463f73     PUSH       EAX
//         00463f74     MOV        this,EDI
//         00463f76     CALL       TPanel::setPreviousModalPanel                    void setPreviousModalPanel(TPanel * this, TPa
//                               LAB_00463f7b                                                 XREF[2]:     00463f6d(j), 00463f71(j)
//                              Panel.cpp:304 (7)
//         00463f7b     MOV        EAX,dword ptr [ESI + 0x8]
//         00463f7e     TEST       EAX,EAX
//         00463f80     JNZ        LAB_00463f93
//                              Panel.cpp:305 (7)
//         00463f82     MOV        EAX,dword ptr [ESI + 0x18]
//         00463f85     TEST       EAX,EAX
//         00463f87     JZ         LAB_00463fac
//                              Panel.cpp:306 (3)
//         00463f89     MOV        this,dword ptr [EAX + 0x40]
//                              Panel.cpp:307 (4)
//         00463f8c     TEST       this,this
//         00463f8e     JZ         LAB_00463fac
//                              Panel.cpp:308 (1)
//         00463f90     PUSH       EAX
//                              Panel.cpp:311 (9)
//         00463f91     JMP        LAB_00463fa7
//                               LAB_00463f93                                                 XREF[1]:     00463f80(j)
//         00463f93     MOV        this,dword ptr [EAX + 0x74]
//         00463f96     TEST       this,this
//         00463f98     JNZ        LAB_00463fac
//                              Panel.cpp:312 (3)
//         00463f9a     MOV        EAX,dword ptr [EAX + 0x40]
//                              Panel.cpp:313 (4)
//         00463f9d     TEST       EAX,EAX
//         00463f9f     JZ         LAB_00463fac
//                              Panel.cpp:314 (11)
//         00463fa1     MOV        this,dword ptr [ESI + 0x18]
//         00463fa4     PUSH       this
//         00463fa5     MOV        this,EAX
//                               LAB_00463fa7                                                 XREF[1]:     00463f91(j)
//         00463fa7     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_00463fac                                                 XREF[4]:     00463f87(j), 00463f8e(j),
//                                                                                                         00463f98(j), 00463f9f(j)
//                              Panel.cpp:322 (19)
//         00463fac     TEST       EDI,EDI
//         00463fae     MOV        dword ptr [ESI + 0x18],0x0
//         00463fb5     MOV        dword ptr [ESI + 0x8],EDI
//         00463fb8     JZ         LAB_00463fea
//         00463fba     CMP        EDI,dword ptr [ESI + 0xc]
//         00463fbd     JZ         LAB_00463fea
//                              Panel.cpp:327 (3)
//         00463fbf     MOV        this,dword ptr [EDI + 0x40]
//                              Panel.cpp:328 (4)
//         00463fc2     TEST       this,this
//         00463fc4     JZ         LAB_00463fd7
//                              Panel.cpp:329 (3)
//         00463fc6     MOV        EDX,dword ptr [ECX + this+0x3c]
//                              Panel.cpp:330 (9)
//         00463fc9     PUSH       EDI
//         00463fca     MOV        dword ptr [ESI + 0x18],EDX
//         00463fcd     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              Panel.cpp:337 (5)
//         00463fd2     POP        EDI
//         00463fd3     POP        ESI
//         00463fd4     RET        0x4
//                               LAB_00463fd7                                                 XREF[1]:     00463fc4(j)
//                              Panel.cpp:334 (19)
//         00463fd7     MOV        EAX,dword ptr [EDI]
//         00463fd9     PUSH       0x1
//         00463fdb     MOV        this,EDI
//         00463fdd     MOV        dword ptr [ESI + 0x18],0x0
//         00463fe4     CALL       dword ptr [EAX + 0xc0]
//                               LAB_00463fea                                                 XREF[2]:     00463fb8(j), 00463fbd(j)
//                              Panel.cpp:337 (5)
//         00463fea     POP        EDI
//         00463feb     POP        ESI
//         00463fec     RET        0x4
//         00463fef     ??         90h
    return;
}

void TPanelSystem::setCurrentPanelModal() {
    /* TODO: Stub */
//                              void __thiscall setCurrentPanelModal(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?setCurrentPanelModal@TPanelSystem@@QAEXXZ                   XREF[1]:     setCurrentPanel:004642b3(c)
//                               TPanelSystem::setCurrentPanelModal
//                              Panel.cpp:342 (3)
//         00463ff0     PUSH       ESI
//         00463ff1     MOV        ESI,this
//                              Panel.cpp:345 (14)
//         00463ff3     MOV        EAX,dword ptr [ESI + 0x8]
//         00463ff6     TEST       EAX,EAX
//         00463ff8     JZ         LAB_00464007
//         00463ffa     MOV        this,dword ptr [ESI + 0xc]
//         00463ffd     CMP        EAX,this
//         00463fff     JZ         LAB_00464007
//                              Panel.cpp:346 (6)
//         00464001     PUSH       EAX
//         00464002     CALL       TPanel::setPreviousModalPanel                    void setPreviousModalPanel(TPanel * this, TPa
//                               LAB_00464007                                                 XREF[2]:     00463ff8(j), 00463fff(j)
//                              Panel.cpp:348 (6)
//         00464007     MOV        EAX,dword ptr [ESI + 0xc]
//         0046400a     MOV        dword ptr [ESI + 0x8],EAX
//                              Panel.cpp:349 (2)
//         0046400d     POP        ESI
//         0046400e     RET
//         0046400f     ??         90h
    return;
}

int TPanelSystem::restorePreviousModalPanel() {
    /* TODO: Stub */
//                              int __thiscall restorePreviousModalPanel(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?restorePreviousModalPanel@TPanelSystem@@QAEHXZ              XREF[2]:     ~TDialogPanel:00473e70(c),
//                               TPanelSystem::restorePreviousModalPanel                                   set_mode:00474aa8(c)
//                              Panel.cpp:354 (4)
//         00464010     PUSH       ESI
//         00464011     PUSH       EDI
//         00464012     MOV        EDI,this
//                              Panel.cpp:357 (7)
//         00464014     MOV        this,dword ptr [EDI + 0x8]
//         00464017     TEST       this,this
//         00464019     JNZ        LAB_00464020
//                              Panel.cpp:358 (2)
//         0046401b     XOR        EAX,EAX
//                              Panel.cpp:371 (3)
//         0046401d     POP        EDI
//         0046401e     POP        ESI
//         0046401f     RET
//                               LAB_00464020                                                 XREF[1]:     00464019(j)
//                              Panel.cpp:359 (7)
//         00464020     CALL       TPanel::previousModalPanel                       TPanel * previousModalPanel(TPanel * this)
//         00464025     MOV        ESI,EAX
//                              Panel.cpp:360 (4)
//         00464027     TEST       ESI,ESI
//         00464029     JNZ        LAB_0046402e
//                              Panel.cpp:371 (3)
//         0046402b     POP        EDI
//         0046402c     POP        ESI
//         0046402d     RET
//                               LAB_0046402e                                                 XREF[1]:     00464029(j)
//                              Panel.cpp:365 (12)
//         0046402e     MOV        EAX,dword ptr [ESI]
//         00464030     PUSH       0x1
//         00464032     MOV        this,ESI
//         00464034     CALL       dword ptr [EAX + 0xc0]
//                              Panel.cpp:367 (8)
//         0046403a     PUSH       ESI
//         0046403b     MOV        this,EDI
//         0046403d     CALL       TPanelSystem::setMouseOwner                      void setMouseOwner(TPanelSystem * this, TPane
//                              Panel.cpp:368 (8)
//         00464042     PUSH       ESI
//         00464043     MOV        this,EDI
//         00464045     CALL       TPanelSystem::setKeyboardOwner                   void setKeyboardOwner(TPanelSystem * this, TP
//                              Panel.cpp:369 (3)
//         0046404a     MOV        dword ptr [EDI + 0x8],ESI
//                              Panel.cpp:371 (8)
//         0046404d     POP        EDI
//         0046404e     MOV        EAX,0x1
//         00464053     POP        ESI
//         00464054     RET
//         00464055     ??         90h
//         00464056     NOP
//         00464057     NOP
//         00464058     NOP
//         00464059     NOP
//         0046405a     NOP
//         0046405b     NOP
//         0046405c     NOP
//         0046405d     NOP
//         0046405e     NOP
//         0046405f     NOP
    return 0;
}

int TPanelSystem::destroyPanel(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall destroyPanel(TPanelSystem * this, char * param_1)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00464060(R)
//                               ?destroyPanel@TPanelSystem@@QAEHPAD@Z                        XREF[232]:   restorePreviousPanel:00463f08(c),
//                               TPanelSystem::destroyPanel                                                popupOKDialog:00469fa9(c),
//                                                                                                         action:0046a555(c),
//                                                                                                         action:0046a5c9(c),
//                                                                                                         action:0046a63e(c),
//                                                                                                         action:00493d12(c),
//                                                                                                         startGame:004a2691(c),
//                                                                                                         action:004a70d5(c),
//                                                                                                         action:004a70e4(c),
//                                                                                                         action:004a7182(c),
//                                                                                                         command_save:004ad754(c),
//                                                                                                         command_save:004ad790(c),
//                                                                                                         command_save:004ad801(c),
//                                                                                                         command_save:004ad8d8(c),
//                                                                                                         command_save_as:004ada53(c),
//                                                                                                         start_scenario_editor:00528e08(c),
//                                                                                                         start_scenario_editor:00528e8a(c),
//                                                                                                         start_scenario_editor:00528e99(c),
//                                                                                                         start_scenario_editor:00528ea8(c),
//                                                                                                         start_scenario_editor:00528f27(c),
//                                                                                                         [more]
//                              Panel.cpp:376 (12)
//         00464060     MOV        EAX,dword ptr [ESP + param_1]
//         00464064     PUSH       ESI
//         00464065     PUSH       EDI
//         00464066     MOV        EDI,this
//         00464068     TEST       EAX,EAX
//         0046406a     JNZ        LAB_00464071
//                              Panel.cpp:404 (5)
//         0046406c     POP        EDI
//         0046406d     POP        ESI
//         0046406e     RET        0x4
//                               LAB_00464071                                                 XREF[1]:     0046406a(j)
//                              Panel.cpp:382 (10)
//         00464071     PUSH       EAX
//         00464072     MOV        this,EDI
//         00464074     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//         00464079     MOV        ESI,EAX
//                              Panel.cpp:383 (4)
//         0046407b     TEST       ESI,ESI
//         0046407d     JNZ        LAB_00464084
//                              Panel.cpp:404 (5)
//         0046407f     POP        EDI
//         00464080     POP        ESI
//         00464081     RET        0x4
//                               LAB_00464084                                                 XREF[1]:     0046407d(j)
//                              Panel.cpp:387 (3)
//         00464084     MOV        EDX,dword ptr [EDI + 0x14]
//                              Panel.cpp:390 (13)
//         00464087     MOV        EAX,dword ptr [EDI + 0xc]
//         0046408a     DEC        EDX
//         0046408b     MOV        dword ptr [EDI + 0x14],EDX
//         0046408e     MOV        this,dword ptr [ESI]
//         00464090     CMP        EAX,this
//         00464092     JNZ        LAB_0046409b
//                              Panel.cpp:391 (7)
//         00464094     MOV        dword ptr [EDI + 0xc],0x0
//                               LAB_0046409b                                                 XREF[1]:     00464092(j)
//                              Panel.cpp:392 (8)
//         0046409b     MOV        this,dword ptr [EDI]
//         0046409d     MOV        EAX,dword ptr [ESI]
//         0046409f     CMP        this,EAX
//         004640a1     JNZ        LAB_004640a9
//                              Panel.cpp:393 (6)
//         004640a3     MOV        dword ptr [EDI],0x0
//                               LAB_004640a9                                                 XREF[1]:     004640a1(j)
//                              Panel.cpp:394 (9)
//         004640a9     MOV        EDX,dword ptr [EDI + 0x4]
//         004640ac     MOV        EAX,dword ptr [ESI]
//         004640ae     CMP        EDX,EAX
//         004640b0     JNZ        LAB_004640b9
//                              Panel.cpp:395 (7)
//         004640b2     MOV        dword ptr [EDI + 0x4],0x0
//                               LAB_004640b9                                                 XREF[1]:     004640b0(j)
//                              Panel.cpp:396 (9)
//         004640b9     MOV        EAX,dword ptr [EDI + 0x8]
//         004640bc     MOV        this,dword ptr [ESI]
//         004640be     CMP        EAX,this
//         004640c0     JNZ        LAB_004640c9
//                              Panel.cpp:397 (7)
//         004640c2     MOV        dword ptr [EDI + 0x8],0x0
//                               LAB_004640c9                                                 XREF[1]:     004640c0(j)
//                              Panel.cpp:399 (9)
//         004640c9     MOV        this,dword ptr [ESI + 0x4]
//         004640cc     MOV        EDX,dword ptr [ESI + 0x8]
//         004640cf     MOV        dword ptr [ECX + this->modalPanelValue],EDX
//                              Panel.cpp:400 (9)
//         004640d2     MOV        EAX,dword ptr [ESI + 0x8]
//         004640d5     MOV        this,dword ptr [ESI + 0x4]
//         004640d8     MOV        dword ptr [EAX + 0x4],this
//                              Panel.cpp:401 (12)
//         004640db     MOV        this,dword ptr [ESI]
//         004640dd     TEST       this,this
//         004640df     JZ         LAB_004640e7
//         004640e1     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         004640e3     PUSH       0x1
//         004640e5     CALL       dword ptr [EDX]
//                               LAB_004640e7                                                 XREF[1]:     004640df(j)
//                              Panel.cpp:402 (9)
//         004640e7     PUSH       ESI
//         004640e8     CALL       free                                             undefined free()
//         004640ed     ADD        ESP,0x4
//                              Panel.cpp:403 (5)
//         004640f0     MOV        EAX,0x1
//                              Panel.cpp:404 (5)
//         004640f5     POP        EDI
//         004640f6     POP        ESI
//         004640f7     RET        0x4
//         004640fa     ??         90h
//         004640fb     NOP
//         004640fc     NOP
//         004640fd     NOP
//         004640fe     NOP
//         004640ff     NOP
    return 0;
}

int TPanelSystem::inSystem(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall inSystem(TPanelSystem * this, TPanel * param_1)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00464123(R)
//                               ?inSystem@TPanelSystem@@QAEHPAVTPanel@@@Z                    XREF[1]:     ~TPanel:004649fb(c)
//                               TPanelSystem::inSystem
//                              Panel.cpp:418 (3)
//         00464120     PUSH       ESI
//         00464121     MOV        ESI,this
//                              Panel.cpp:419 (25)
//         00464123     MOV        this,dword ptr [ESP + param_1]
//         00464127     TEST       this,this
//         00464129     JZ         LAB_00464145
//         0046412b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         00464130     PUSH       EAX
//         00464131     MOV        this,ESI
//         00464133     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//         00464138     TEST       EAX,EAX
//         0046413a     JZ         LAB_00464145
//                              Panel.cpp:421 (5)
//         0046413c     MOV        EAX,0x1
//                              Panel.cpp:422 (4)
//         00464141     POP        ESI
//         00464142     RET        0x4
//                               LAB_00464145                                                 XREF[2]:     00464129(j), 0046413a(j)
//                              Panel.cpp:420 (2)
//         00464145     XOR        EAX,EAX
//                              Panel.cpp:422 (4)
//         00464147     POP        ESI
//         00464148     RET        0x4
//         0046414b     ??         90h
//         0046414c     NOP
//         0046414d     NOP
//         0046414e     NOP
//         0046414f     NOP
    return 0;
}

int TPanelSystem::inSystem(TPanel* param_1) {
    /* TODO: Stub */
//                              int __thiscall inSystem(TPanelSystem * this, TPanel * param_1)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00464123(R)
//                               ?inSystem@TPanelSystem@@QAEHPAVTPanel@@@Z                    XREF[1]:     ~TPanel:004649fb(c)
//                               TPanelSystem::inSystem
//                              Panel.cpp:418 (3)
//         00464120     PUSH       ESI
//         00464121     MOV        ESI,this
//                              Panel.cpp:419 (25)
//         00464123     MOV        this,dword ptr [ESP + param_1]
//         00464127     TEST       this,this
//         00464129     JZ         LAB_00464145
//         0046412b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         00464130     PUSH       EAX
//         00464131     MOV        this,ESI
//         00464133     CALL       TPanelSystem::findPanelNode                      PanelNode * findPanelNode(TPanelSystem * this
//         00464138     TEST       EAX,EAX
//         0046413a     JZ         LAB_00464145
//                              Panel.cpp:421 (5)
//         0046413c     MOV        EAX,0x1
//                              Panel.cpp:422 (4)
//         00464141     POP        ESI
//         00464142     RET        0x4
//                               LAB_00464145                                                 XREF[2]:     00464129(j), 0046413a(j)
//                              Panel.cpp:420 (2)
//         00464145     XOR        EAX,EAX
//                              Panel.cpp:422 (4)
//         00464147     POP        ESI
//         00464148     RET        0x4
//         0046414b     ??         90h
//         0046414c     NOP
//         0046414d     NOP
//         0046414e     NOP
//         0046414f     NOP
    return 0;
}

int TPanelSystem::setup() {
    /* TODO: Stub */
//                              int __thiscall setup(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?setup@TPanelSystem@@IAEHXZ                                  XREF[1]:     TPanelSystem:00463c46(c)
//                               TPanelSystem::setup
//                              Panel.cpp:427 (1)
//         00464150     PUSH       ESI
//                              Panel.cpp:429 (17)
//         00464151     PUSH       0xc
//         00464153     MOV        ESI,this
//         00464155     PUSH       0x1
//         00464157     CALL       calloc                                           undefined calloc()
//         0046415c     ADD        ESP,0x8
//         0046415f     MOV        dword ptr [ESI + 0x10],EAX
//                              Panel.cpp:430 (4)
//         00464162     TEST       EAX,EAX
//         00464164     JNZ        LAB_00464168
//                              Panel.cpp:443 (2)
//         00464166     POP        ESI
//         00464167     RET
//                               LAB_00464168                                                 XREF[1]:     00464164(j)
//                              Panel.cpp:432 (6)
//         00464168     MOV        dword ptr [EAX],0x0
//                              Panel.cpp:435 (4)
//         0046416e     MOV        EAX,dword ptr [ESI + 0x10]
//         00464171     PUSH       EDI
//                              Panel.cpp:438 (19)
//         00464172     MOV        EDI,dword ptr [->USER32.DLL::GetSysColor]        = 0048b02a
//         00464178     MOV        dword ptr [EAX + 0x4],EAX
//         0046417b     MOV        EAX,dword ptr [ESI + 0x10]
//         0046417e     PUSH       0x5
//         00464180     MOV        dword ptr [EAX + 0x8],EAX
//         00464183     CALL       EDI=>USER32.DLL::GetSysColor
//                              Panel.cpp:439 (16)
//         00464185     PUSH       0x8
//         00464187     MOV        dword ptr [ESI + 0xad0],EAX
//         0046418d     CALL       EDI=>USER32.DLL::GetSysColor
//         0046418f     MOV        dword ptr [ESI + 0xad4],EAX
//                              Panel.cpp:440 (11)
//         00464195     MOV        dword ptr [ESI + 0xacc],0x1
//         0046419f     POP        EDI
//                              Panel.cpp:442 (5)
//         004641a0     MOV        EAX,0x1
//                              Panel.cpp:443 (2)
//         004641a5     POP        ESI
//         004641a6     RET
//         004641a7     ??         90h
//         004641a8     NOP
//         004641a9     NOP
//         004641aa     NOP
//         004641ab     NOP
//         004641ac     NOP
//         004641ad     NOP
//         004641ae     NOP
//         004641af     NOP
    return 0;
}

PanelNode* TPanelSystem::findPanelNode(char* param_1) {
    /* TODO: Stub */
//                              PanelNode * __thiscall findPanelNode(TPanelSystem * this, char * par
//              PanelNode *       EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004641b2(R)
//                               ?findPanelNode@TPanelSystem@@IAEPAUPanelNode@@PAD@Z          XREF[7]:     panel:00463d55(c),
//                               TPanelSystem::findPanelNode                                               addPanel:00463d93(c),
//                                                                                                         removePanel:00463e22(c),
//                                                                                                         setCurrentPanel:00463e69(c),
//                                                                                                         destroyPanel:00464074(c),
//                                                                                                         inSystem:00464105(c),
//                                                                                                         inSystem:00464133(c)
//                              Panel.cpp:448 (2)
//         004641b0     PUSH       EBX
//         004641b1     PUSH       EBP
//                              Panel.cpp:449 (10)
//         004641b2     MOV        EBP,dword ptr [ESP + param_1]
//         004641b6     PUSH       ESI
//         004641b7     TEST       EBP,EBP
//         004641b9     PUSH       EDI
//         004641ba     MOV        EBX,this
//                              Panel.cpp:450 (6)
//         004641bc     JZ         LAB_00464254
//                              Panel.cpp:454 (6)
//         004641c2     MOV        EAX,dword ptr [EBX + 0x10]
//         004641c5     MOV        EDI,dword ptr [EAX + 0x8]
//                              Panel.cpp:456 (58)
//         004641c8     CMP        EDI,EAX
//         004641ca     JZ         LAB_0046420c
//                               LAB_004641cc                                                 XREF[1]:     0046420a(j)
//         004641cc     MOV        this,dword ptr [EDI]
//         004641ce     MOV        ESI,EBP
//         004641d0     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004641d5                                                 XREF[1]:     004641f3(j)
//         004641d5     MOV        DL,byte ptr [EAX]
//         004641d7     MOV        this,DL
//         004641d9     CMP        DL,byte ptr [ESI]
//         004641db     JNZ        LAB_004641f9
//         004641dd     TEST       this,this
//         004641df     JZ         LAB_004641f5
//         004641e1     MOV        DL,byte ptr [EAX + 0x1]
//         004641e4     MOV        this,DL
//         004641e6     CMP        DL,byte ptr [ESI + 0x1]
//         004641e9     JNZ        LAB_004641f9
//         004641eb     ADD        EAX,0x2
//         004641ee     ADD        ESI,0x2
//         004641f1     TEST       this,this
//         004641f3     JNZ        LAB_004641d5
//                               LAB_004641f5                                                 XREF[1]:     004641df(j)
//         004641f5     XOR        EAX,EAX
//         004641f7     JMP        LAB_004641fe
//                               LAB_004641f9                                                 XREF[2]:     004641db(j), 004641e9(j)
//         004641f9     SBB        EAX,EAX
//         004641fb     SBB        EAX,-0x1
//                               LAB_004641fe                                                 XREF[1]:     004641f7(j)
//         004641fe     TEST       EAX,EAX
//         00464200     JZ         LAB_0046420c
//                              Panel.cpp:457 (10)
//         00464202     MOV        EDI,dword ptr [EDI + 0x8]
//         00464205     MOV        EAX,dword ptr [EBX + 0x10]
//         00464208     CMP        EDI,EAX
//         0046420a     JNZ        LAB_004641cc
//                               LAB_0046420c                                                 XREF[2]:     004641ca(j), 00464200(j)
//                              Panel.cpp:459 (63)
//         0046420c     CMP        EDI,dword ptr [EBX + 0x10]
//         0046420f     JZ         LAB_00464254
//         00464211     MOV        this,dword ptr [EDI]
//         00464213     MOV        ESI,EBP
//         00464215     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_0046421a                                                 XREF[1]:     0046423c(j)
//         0046421a     MOV        DL,byte ptr [EAX]
//         0046421c     MOV        BL,byte ptr [ESI]
//         0046421e     MOV        this,DL
//         00464220     CMP        DL,BL
//         00464222     JNZ        LAB_00464242
//         00464224     TEST       this,this
//         00464226     JZ         LAB_0046423e
//         00464228     MOV        DL,byte ptr [EAX + 0x1]
//         0046422b     MOV        BL,byte ptr [ESI + 0x1]
//         0046422e     MOV        this,DL
//         00464230     CMP        DL,BL
//         00464232     JNZ        LAB_00464242
//         00464234     ADD        EAX,0x2
//         00464237     ADD        ESI,0x2
//         0046423a     TEST       this,this
//         0046423c     JNZ        LAB_0046421a
//                               LAB_0046423e                                                 XREF[1]:     00464226(j)
//         0046423e     XOR        EAX,EAX
//         00464240     JMP        LAB_00464247
//                               LAB_00464242                                                 XREF[2]:     00464222(j), 00464232(j)
//         00464242     SBB        EAX,EAX
//         00464244     SBB        EAX,-0x1
//                               LAB_00464247                                                 XREF[1]:     00464240(j)
//         00464247     TEST       EAX,EAX
//         00464249     JNZ        LAB_00464254
//                              Panel.cpp:460 (2)
//         0046424b     MOV        EAX,EDI
//                              Panel.cpp:462 (16)
//         0046424d     POP        EDI
//         0046424e     POP        ESI
//         0046424f     POP        EBP
//         00464250     POP        EBX
//         00464251     RET        0x4
//                               LAB_00464254                                                 XREF[3]:     004641bc(j), 0046420f(j),
//                                                                                                         00464249(j)
//         00464254     POP        EDI
//         00464255     POP        ESI
//         00464256     POP        EBP
//         00464257     XOR        EAX,EAX
//         00464259     POP        EBX
//         0046425a     RET        0x4
//         0046425d     ??         90h
//         0046425e     NOP
//         0046425f     NOP
    return 0;
}

int TPanelSystem::setCurrentPanel(char* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setCurrentPanel(TPanelSystem * this, TPanel * param_
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00464264(R)
//              int               Stack[0x8]:4   param_2
//                               ?setCurrentPanel@TPanelSystem@@IAEXPAVTPanel@@H@Z            XREF[2]:     addPanel:00463df1(c),
//                               TPanelSystem::setCurrentPanel                                             setCurrentPanel:00463e97(c)
//                              Panel.cpp:467 (4)
//         00464260     PUSH       ESI
//         00464261     MOV        ESI,this
//         00464263     PUSH       EDI
//                              Panel.cpp:470 (15)
//         00464264     MOV        EDI,dword ptr [ESP + param_1]
//         00464268     MOV        EAX,dword ptr [ESI + 0xc]
//         0046426b     MOV        this,EDI
//         0046426d     PUSH       EAX
//         0046426e     CALL       TPanel::setPreviousPanel                         void setPreviousPanel(TPanel * this, TPanel *
//                              Panel.cpp:473 (7)
//         00464273     MOV        this,dword ptr [ESI + 0xc]
//         00464276     TEST       this,this
//         00464278     JZ         LAB_00464284
//                              Panel.cpp:474 (10)
//         0046427a     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         0046427c     PUSH       0x0
//         0046427e     CALL       dword ptr [EDX + 0xc0]
//                               LAB_00464284                                                 XREF[1]:     00464278(j)
//                              Panel.cpp:478 (15)
//         00464284     MOV        EAX,dword ptr [EDI]
//         00464286     PUSH       0x1
//         00464288     MOV        this,EDI
//         0046428a     MOV        dword ptr [ESI + 0xc],EDI
//         0046428d     CALL       dword ptr [EAX + 0xc0]
//                              Panel.cpp:479 (10)
//         00464293     MOV        this,dword ptr [ESI + 0xc]
//         00464296     PUSH       0x2
//         00464298     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         0046429a     CALL       dword ptr [EDX + 0x20]
//                              Panel.cpp:480 (12)
//         0046429d     MOV        EAX,[AppWnd]                                     = 00000000
//         004642a2     PUSH       EAX
//         004642a3     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
//                              Panel.cpp:482 (8)
//         004642a9     MOV        EAX,dword ptr [ESP + 0x10]
//         004642ad     TEST       EAX,EAX
//         004642af     JZ         LAB_004642b8
//                              Panel.cpp:483 (7)
//         004642b1     MOV        this,ESI
//         004642b3     CALL       TPanelSystem::setCurrentPanelModal               void setCurrentPanelModal(TPanelSystem * this)
//                               LAB_004642b8                                                 XREF[1]:     004642af(j)
//                              Panel.cpp:484 (5)
//         004642b8     POP        EDI
//         004642b9     POP        ESI
//         004642ba     RET        0x8
//         004642bd     ??         90h
//         004642be     NOP
//         004642bf     NOP
    return 0;
}

void TPanelSystem::setCurrentPanel(TPanel* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setCurrentPanel(TPanelSystem * this, TPanel * param_
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00464264(R)
//              int               Stack[0x8]:4   param_2
//                               ?setCurrentPanel@TPanelSystem@@IAEXPAVTPanel@@H@Z            XREF[2]:     addPanel:00463df1(c),
//                               TPanelSystem::setCurrentPanel                                             setCurrentPanel:00463e97(c)
//                              Panel.cpp:467 (4)
//         00464260     PUSH       ESI
//         00464261     MOV        ESI,this
//         00464263     PUSH       EDI
//                              Panel.cpp:470 (15)
//         00464264     MOV        EDI,dword ptr [ESP + param_1]
//         00464268     MOV        EAX,dword ptr [ESI + 0xc]
//         0046426b     MOV        this,EDI
//         0046426d     PUSH       EAX
//         0046426e     CALL       TPanel::setPreviousPanel                         void setPreviousPanel(TPanel * this, TPanel *
//                              Panel.cpp:473 (7)
//         00464273     MOV        this,dword ptr [ESI + 0xc]
//         00464276     TEST       this,this
//         00464278     JZ         LAB_00464284
//                              Panel.cpp:474 (10)
//         0046427a     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         0046427c     PUSH       0x0
//         0046427e     CALL       dword ptr [EDX + 0xc0]
//                               LAB_00464284                                                 XREF[1]:     00464278(j)
//                              Panel.cpp:478 (15)
//         00464284     MOV        EAX,dword ptr [EDI]
//         00464286     PUSH       0x1
//         00464288     MOV        this,EDI
//         0046428a     MOV        dword ptr [ESI + 0xc],EDI
//         0046428d     CALL       dword ptr [EAX + 0xc0]
//                              Panel.cpp:479 (10)
//         00464293     MOV        this,dword ptr [ESI + 0xc]
//         00464296     PUSH       0x2
//         00464298     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         0046429a     CALL       dword ptr [EDX + 0x20]
//                              Panel.cpp:480 (12)
//         0046429d     MOV        EAX,[AppWnd]                                     = 00000000
//         004642a2     PUSH       EAX
//         004642a3     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
//                              Panel.cpp:482 (8)
//         004642a9     MOV        EAX,dword ptr [ESP + 0x10]
//         004642ad     TEST       EAX,EAX
//         004642af     JZ         LAB_004642b8
//                              Panel.cpp:483 (7)
//         004642b1     MOV        this,ESI
//         004642b3     CALL       TPanelSystem::setCurrentPanelModal               void setCurrentPanelModal(TPanelSystem * this)
//                               LAB_004642b8                                                 XREF[1]:     004642af(j)
//                              Panel.cpp:484 (5)
//         004642b8     POP        EDI
//         004642b9     POP        ESI
//         004642ba     RET        0x8
//         004642bd     ??         90h
//         004642be     NOP
//         004642bf     NOP
    return;
}

void* TPanelSystem::get_palette(char* param_1, long param_2) {
    /* TODO: Stub */
//                              void * __thiscall get_palette(TPanelSystem * this, char * param_1, l
//              void *            EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004642ca(R)
//              long              Stack[0x8]:4   param_2                   XREF[3]:     00464350(R), 004643d5(R), 0046443c(R)
//              char[260]         Stack[-0x108   file_name2                XREF[2,9]:   004642d5(W), 00464395(R), 004642eb(*), 0046430a(*),
//                                                                                     00464320(*), 0046432f(W), 00464368(*), 00464370(*),
//                                                                                     004643de(*), 00464415(*), 0046437d(R)
//              undefined4        Stack[-0x10c   local_10c                 XREF[4]:     0046433a(W), 00464364(R), 004643aa(R), 004643bb(W)
//                               ?get_palette@TPanelSystem@@QAEPAXPADJ@Z                      XREF[3]:     setup_graphics_system:0041eb84(c),
//                               TPanelSystem::get_palette                                                 setup_palette:0041ebd6(c),
//                                                                                                         set_palette:00467e40(c)
//                              Panel.cpp:490 (10)
//         004642c0     SUB        ESP,0x10c
//         004642c6     PUSH       EBX
//         004642c7     PUSH       EBP
//         004642c8     PUSH       ESI
//         004642c9     PUSH       EDI
//                              Panel.cpp:495 (17)
//         004642ca     MOV        EDI,dword ptr [ESP + param_1]
//         004642d1     MOV        EBX,this
//         004642d3     TEST       EDI,EDI
//         004642d5     MOV        dword ptr [ESP + file_name2[0]],EBX
//         004642d9     JZ         LAB_0046432f
//                              Panel.cpp:497 (15)
//         004642db     PUSH       0x2e
//         004642dd     PUSH       EDI
//         004642de     CALL       strchr                                           undefined strchr()
//         004642e3     ADD        ESP,0x8
//         004642e6     TEST       EAX,EAX
//         004642e8     JNZ        LAB_004642ff
//                              Panel.cpp:498 (19)
//         004642ea     PUSH       EDI
//         004642eb     LEA        EAX=>file_name2[4],[ESP + 0x1c]
//         004642ef     PUSH       s_%s.pal                                         = "%s.pal"
//         004642f4     PUSH       EAX
//         004642f5     CALL       sprintf                                          undefined sprintf()
//         004642fa     ADD        ESP,0xc
//                              Panel.cpp:499 (2)
//         004642fd     JMP        LAB_00464320
//                               LAB_004642ff                                                 XREF[1]:     004642e8(j)
//                              Panel.cpp:500 (33)
//         004642ff     OR         this,0xffffffff
//         00464302     XOR        EAX,EAX
//         00464304     SCASB.RE   ES:EDI
//         00464306     NOT        this
//         00464308     SUB        EDI,this
//         0046430a     LEA        EDX=>file_name2[4],[ESP + 0x18]
//         0046430e     MOV        EAX,this
//         00464310     MOV        ESI,EDI
//         00464312     MOV        EDI,EDX
//         00464314     SHR        this,0x2
//         00464317     MOVSD.REP  ES:EDI,ESI
//         00464319     MOV        this,EAX
//         0046431b     AND        this,0x3
//         0046431e     MOVSB.REP  ES:EDI,ESI
//                               LAB_00464320                                                 XREF[1]:     004642fd(j)
//                              Panel.cpp:501 (13)
//         00464320     LEA        this=>file_name2[4],[ESP + 0x18]
//         00464324     PUSH       this
//         00464325     CALL       strupr                                           undefined strupr()
//         0046432a     ADD        ESP,0x4
//                              Panel.cpp:503 (2)
//         0046432d     JMP        LAB_00464334
//                               LAB_0046432f                                                 XREF[1]:     004642d9(j)
//                              Panel.cpp:504 (5)
//         0046432f     MOV        byte ptr [ESP + file_name2[4]],0x0
//                               LAB_00464334                                                 XREF[1]:     0046432d(j)
//                              Panel.cpp:506 (10)
//         00464334     LEA        EDX,[EBX + 0x44]
//         00464337     OR         EBP,0xffffffff
//         0046433a     MOV        dword ptr [ESP + local_10c],EDX
//                              Panel.cpp:507 (8)
//         0046433e     XOR        EDI,EDI
//         00464340     LEA        EDX,[EBX + 0xa94]
//                               LAB_00464346                                                 XREF[1]:     004643bf(j)
//                              Panel.cpp:509 (10)
//         00464346     MOV        EAX,dword ptr [EDX + 0xfffff588]
//         0046434c     TEST       EAX,EAX
//         0046434e     JZ         LAB_004643a3
//                              Panel.cpp:511 (69)
//         00464350     MOV        EAX,dword ptr [ESP + param_2]
//         00464357     CMP        EAX,-0x1
//         0046435a     JZ         LAB_00464364
//         0046435c     CMP        dword ptr [EDX],EAX
//         0046435e     JZ         LAB_0046445b
//                               LAB_00464364                                                 XREF[1]:     0046435a(j)
//         00464364     MOV        EAX,dword ptr [ESP + local_10c]
//         00464368     LEA        ESI=>file_name2[4],[ESP + 0x18]
//                               LAB_0046436c                                                 XREF[1]:     0046438a(j)
//         0046436c     MOV        BL,byte ptr [EAX]
//         0046436e     MOV        this,BL
//         00464370     CMP        BL,byte ptr [ESI]=>file_name2[4]
//         00464372     JNZ        LAB_00464390
//         00464374     TEST       this,this
//         00464376     JZ         LAB_0046438c
//         00464378     MOV        BL,byte ptr [EAX + 0x1]
//         0046437b     MOV        this,BL
//         0046437d     CMP        BL,byte ptr [ESI + file_name2[5]]
//         00464380     JNZ        LAB_00464390
//         00464382     ADD        EAX,0x2
//         00464385     ADD        ESI,0x2
//         00464388     TEST       this,this
//         0046438a     JNZ        LAB_0046436c
//                               LAB_0046438c                                                 XREF[1]:     00464376(j)
//         0046438c     XOR        EAX,EAX
//         0046438e     JMP        LAB_00464395
//                               LAB_00464390                                                 XREF[2]:     00464372(j), 00464380(j)
//         00464390     SBB        EAX,EAX
//         00464392     SBB        EAX,-0x1
//                               LAB_00464395                                                 XREF[1]:     0046438e(j)
//                              Panel.cpp:517 (19)
//         00464395     MOV        EBX,dword ptr [ESP + file_name2[0]]
//         00464399     TEST       EAX,EAX
//         0046439b     JZ         LAB_0046445b
//         004643a1     JMP        LAB_004643aa
//                               LAB_004643a3                                                 XREF[1]:     0046434e(j)
//         004643a3     CMP        EBP,-0x1
//         004643a6     JNZ        LAB_004643aa
//                              Panel.cpp:518 (2)
//         004643a8     MOV        EBP,EDI
//                               LAB_004643aa                                                 XREF[2]:     004643a1(j), 004643a6(j)
//                              Panel.cpp:507 (23)
//         004643aa     MOV        this,dword ptr [ESP + local_10c]
//         004643ae     INC        EDI
//         004643af     ADD        EDX,0x4
//         004643b2     ADD        this,0x104
//         004643b8     CMP        EDI,0xa
//         004643bb     MOV        dword ptr [ESP + local_10c],this
//         004643bf     JL         LAB_00464346
//                              Panel.cpp:520 (5)
//         004643c1     CMP        EBP,-0x1
//         004643c4     JNZ        LAB_004643d5
//                              Panel.cpp:521 (2)
//         004643c6     XOR        EAX,EAX
//                              Panel.cpp:532 (13)
//         004643c8     POP        EDI
//         004643c9     POP        ESI
//         004643ca     POP        EBP
//         004643cb     POP        EBX
//         004643cc     ADD        ESP,0x10c
//         004643d2     RET        0x8
//                               LAB_004643d5                                                 XREF[1]:     004643c4(j)
//                              Panel.cpp:523 (27)
//         004643d5     MOV        EAX,dword ptr [ESP + param_2]
//         004643dc     PUSH       0x1
//         004643de     LEA        this=>file_name2[4],[ESP + 0x1c]
//         004643e2     PUSH       EAX
//         004643e3     PUSH       this
//         004643e4     CALL       ReadPalette                                      void * ReadPalette(char * param_1, long param
//         004643e9     ADD        ESP,0xc
//         004643ec     MOV        dword ptr [EBX + EBP*0x4 + 0x1c],EAX
//                              Panel.cpp:524 (4)
//         004643f0     TEST       EAX,EAX
//         004643f2     JNZ        LAB_00464401
//                              Panel.cpp:532 (13)
//         004643f4     POP        EDI
//         004643f5     POP        ESI
//         004643f6     POP        EBP
//         004643f7     POP        EBX
//         004643f8     ADD        ESP,0x10c
//         004643fe     RET        0x8
//                               LAB_00464401                                                 XREF[1]:     004643f2(j)
//                              Panel.cpp:527 (7)
//         00464401     MOV        EDI,dword ptr [EBX + EBP*0x4 + 0xa6c]
//                              Panel.cpp:528 (52)
//         00464408     MOV        EDX,EBP
//         0046440a     INC        EDI
//         0046440b     OR         this,0xffffffff
//         0046440e     MOV        dword ptr [EBX + EBP*0x4 + 0xa6c],EDI
//         00464415     LEA        EDI=>file_name2[4],[ESP + 0x18]
//         00464419     SHL        EDX,0x6
//         0046441c     XOR        EAX,EAX
//         0046441e     ADD        EDX,EBP
//         00464420     SCASB.RE   ES:EDI
//         00464422     NOT        this
//         00464424     SUB        EDI,this
//         00464426     LEA        EDX,[EBX + EDX*0x4 + 0x44]
//         0046442a     MOV        EAX,this
//         0046442c     MOV        ESI,EDI
//         0046442e     MOV        EDI,EDX
//         00464430     SHR        this,0x2
//         00464433     MOVSD.REP  ES:EDI,ESI
//         00464435     MOV        this,EAX
//         00464437     AND        this,0x3
//         0046443a     MOVSB.REP  ES:EDI,ESI
//                              Panel.cpp:529 (14)
//         0046443c     MOV        this,dword ptr [ESP + param_2]
//         00464443     MOV        dword ptr [EBX + EBP*0x4 + 0xa94],this
//                              Panel.cpp:531 (4)
//         0046444a     MOV        EAX,dword ptr [EBX + EBP*0x4 + 0x1c]
//                              Panel.cpp:532 (13)
//         0046444e     POP        EDI
//         0046444f     POP        ESI
//         00464450     POP        EBP
//         00464451     POP        EBX
//         00464452     ADD        ESP,0x10c
//         00464458     RET        0x8
//                               LAB_0046445b                                                 XREF[2]:     0046435e(j), 0046439b(j)
//                              Panel.cpp:513 (15)
//         0046445b     MOV        EAX,dword ptr [EBX + EDI*0x4 + 0xa6c]
//         00464462     INC        EAX
//         00464463     MOV        dword ptr [EBX + EDI*0x4 + 0xa6c],EAX
//                              Panel.cpp:514 (4)
//         0046446a     MOV        EAX,dword ptr [EBX + EDI*0x4 + 0x1c]
//                              Panel.cpp:532 (13)
//         0046446e     POP        EDI
//         0046446f     POP        ESI
//         00464470     POP        EBP
//         00464471     POP        EBX
//         00464472     ADD        ESP,0x10c
//         00464478     RET        0x8
//         0046447b     ??         90h
//         0046447c     NOP
//         0046447d     NOP
//         0046447e     NOP
//         0046447f     NOP
    return 0;
}

void TPanelSystem::release_palette(void* param_1) {
    /* TODO: Stub */
//                              void __thiscall release_palette(TPanelSystem * this, void * param_1)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00464486(R)
//                               ?release_palette@TPanelSystem@@QAEXPAX@Z                     XREF[4]:     ~RGE_Base_Game:0041c5ce(c),
//                               TPanelSystem::release_palette                                             setup_graphics_system:0041eb6b(c),
//                                                                                                         prepare_for_close:00467336(c),
//                                                                                                         set_palette:00467dd0(c)
//                              Panel.cpp:538 (4)
//         00464480     PUSH       ESI
//         00464481     PUSH       EDI
//         00464482     MOV        EDI,this
//                              Panel.cpp:541 (9)
//         00464484     XOR        ESI,ESI
//         00464486     MOV        this,dword ptr [ESP + param_1]
//         0046448a     LEA        EAX,[EDI + 0x1c]
//                               LAB_0046448d                                                 XREF[1]:     00464498(j)
//                              Panel.cpp:543 (13)
//         0046448d     CMP        dword ptr [EAX],this
//         0046448f     JZ         LAB_0046449f
//         00464491     INC        ESI
//         00464492     ADD        EAX,0x4
//         00464495     CMP        ESI,0xa
//         00464498     JL         LAB_0046448d
//                              Panel.cpp:555 (5)
//         0046449a     POP        EDI
//         0046449b     POP        ESI
//         0046449c     RET        0x4
//                               LAB_0046449f                                                 XREF[1]:     0046448f(j)
//                              Panel.cpp:545 (15)
//         0046449f     MOV        EAX,dword ptr [EDI + ESI*0x4 + 0xa6c]
//         004644a6     DEC        EAX
//         004644a7     MOV        dword ptr [EDI + ESI*0x4 + 0xa6c],EAX
//                              Panel.cpp:546 (2)
//         004644ae     JNZ        LAB_004644cf
//                              Panel.cpp:548 (11)
//         004644b0     MOV        EAX,dword ptr [EDI + ESI*0x4 + 0x1c]
//         004644b4     PUSH       EAX
//         004644b5     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              Panel.cpp:550 (20)
//         004644bb     MOV        this,ESI
//         004644bd     MOV        dword ptr [EDI + ESI*0x4 + 0x1c],0x0
//         004644c5     SHL        this,0x6
//         004644c8     ADD        this,ESI
//         004644ca     MOV        byte ptr [EDI + this->mouseOwnerValue*0x4 + 0x
//                               LAB_004644cf                                                 XREF[1]:     004644ae(j)
//                              Panel.cpp:555 (5)
//         004644cf     POP        EDI
//         004644d0     POP        ESI
//         004644d1     RET        0x4
//         004644d4     ??         90h
//         004644d5     NOP
//         004644d6     NOP
//         004644d7     NOP
//         004644d8     NOP
//         004644d9     NOP
//         004644da     NOP
//         004644db     NOP
//         004644dc     NOP
//         004644dd     NOP
//         004644de     NOP
//         004644df     NOP
    return;
}

void TPanelSystem::DisableIME() {
    /* TODO: Stub */
//                              void __thiscall DisableIME(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?DisableIME@TPanelSystem@@QAEXXZ                             XREF[3]:     setup_main_window:0041e909(c),
//                               TPanelSystem::DisableIME                                                  set_enable_ime:004682f2(c),
//                                                                                                         set_focus:00469ed4(c)
//                              Panel.cpp:561 (3)
//         004644e0     PUSH       ESI
//         004644e1     MOV        ESI,this
//                              Panel.cpp:562 (10)
//         004644e3     MOV        EAX,dword ptr [ESI + 0xac0]
//         004644e9     TEST       EAX,EAX
//         004644eb     JZ         LAB_0046450a
//                              Panel.cpp:565 (19)
//         004644ed     MOV        EAX,[AppWnd]                                     = 00000000
//         004644f2     PUSH       0x0
//         004644f4     PUSH       EAX
//         004644f5     CALL       _ImmAssociateContext@8                           undefined _ImmAssociateContext@8()
//         004644fa     MOV        dword ptr [ESI + 0xabc],EAX
//                              Panel.cpp:567 (10)
//         00464500     MOV        dword ptr [ESI + 0xac0],0x0
//                               LAB_0046450a                                                 XREF[1]:     004644eb(j)
//                              Panel.cpp:568 (2)
//         0046450a     POP        ESI
//         0046450b     RET
//         0046450c     ??         90h
//         0046450d     NOP
//         0046450e     NOP
//         0046450f     NOP
    return;
}

void TPanelSystem::EnableIME() {
    /* TODO: Stub */
//                              void __thiscall EnableIME(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?EnableIME@TPanelSystem@@QAEXXZ                              XREF[3]:     ~TPanelSystem:00463ce7(c),
//                               TPanelSystem::EnableIME                                                   set_enable_ime:004682ea(c),
//                                                                                                         set_focus:00469eca(c)
//                              Panel.cpp:575 (10)
//         00464510     MOV        EAX,dword ptr [ECX + this->Imc]
//         00464516     TEST       EAX,EAX
//         00464518     JZ         LAB_00464530
//                              Panel.cpp:579 (10)
//         0046451a     MOV        EDX,dword ptr [ECX + this->ImeEnabled]
//         00464520     TEST       EDX,EDX
//         00464522     JNZ        LAB_00464530
//                              Panel.cpp:582 (12)
//         00464524     PUSH       EAX
//         00464525     MOV        EAX,[AppWnd]                                     = 00000000
//         0046452a     PUSH       EAX
//         0046452b     CALL       _ImmAssociateContext@8                           undefined _ImmAssociateContext@8()
//                               LAB_00464530                                                 XREF[2]:     00464518(j), 00464522(j)
//                              Panel.cpp:583 (1)
//         00464530     RET
//         00464531     ??         90h
//         00464532     NOP
//         00464533     NOP
//         00464534     NOP
//         00464535     NOP
//         00464536     NOP
//         00464537     NOP
//         00464538     NOP
//         00464539     NOP
//         0046453a     NOP
//         0046453b     NOP
//         0046453c     NOP
//         0046453d     NOP
//         0046453e     NOP
//         0046453f     NOP
    return;
}

int TPanelSystem::IsIMEEnabled() {
    /* TODO: Stub */
//                              int __thiscall IsIMEEnabled(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?IsIMEEnabled@TPanelSystem@@QAEHXZ
//                               TPanelSystem::IsIMEEnabled
//                              Panel.cpp:589 (6)
//         00464540     MOV        EAX,dword ptr [ECX + this->ImeEnabled]
//                              Panel.cpp:591 (1)
//         00464546     RET
//         00464547     ??         90h
//         00464548     NOP
//         00464549     NOP
//         0046454a     NOP
//         0046454b     NOP
//         0046454c     NOP
//         0046454d     NOP
//         0046454e     NOP
//         0046454f     NOP
    return 0;
}

void TPanelSystem::TurnIMEOn() {
    /* TODO: Stub */
//                              void __thiscall TurnIMEOn(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?TurnIMEOn@TPanelSystem@@QAEXXZ
//                               TPanelSystem::TurnIMEOn
//                              Panel.cpp:597 (3)
//         00464550     PUSH       ESI
//         00464551     MOV        ESI,this
//                              Panel.cpp:598 (10)
//         00464553     MOV        EAX,dword ptr [ESI + 0xac4]
//         00464559     TEST       EAX,EAX
//         0046455b     JNZ        LAB_00464583
//                              Panel.cpp:601 (10)
//         0046455d     MOV        EAX,dword ptr [ESI + 0xac0]
//         00464563     TEST       EAX,EAX
//         00464565     JZ         LAB_00464583
//                              Panel.cpp:604 (10)
//         00464567     MOV        EAX,dword ptr [ESI + 0xabc]
//         0046456d     TEST       EAX,EAX
//         0046456f     JZ         LAB_00464583
//                              Panel.cpp:607 (8)
//         00464571     PUSH       0x1
//         00464573     PUSH       EAX
//         00464574     CALL       _ImmSetOpenStatus@8                              undefined _ImmSetOpenStatus@8()
//                              Panel.cpp:609 (10)
//         00464579     MOV        dword ptr [ESI + 0xac4],0x1
//                               LAB_00464583                                                 XREF[3]:     0046455b(j), 00464565(j),
//                                                                                                         0046456f(j)
//                              Panel.cpp:610 (2)
//         00464583     POP        ESI
//         00464584     RET
//         00464585     ??         90h
//         00464586     NOP
//         00464587     NOP
//         00464588     NOP
//         00464589     NOP
//         0046458a     NOP
//         0046458b     NOP
//         0046458c     NOP
//         0046458d     NOP
//         0046458e     NOP
//         0046458f     NOP
    return;
}

void TPanelSystem::TurnIMEOff() {
    /* TODO: Stub */
//                              void __thiscall TurnIMEOff(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?TurnIMEOff@TPanelSystem@@QAEXXZ
//                               TPanelSystem::TurnIMEOff
//                              Panel.cpp:616 (3)
//         00464590     PUSH       ESI
//         00464591     MOV        ESI,this
//                              Panel.cpp:617 (10)
//         00464593     MOV        EAX,dword ptr [ESI + 0xac4]
//         00464599     TEST       EAX,EAX
//         0046459b     JZ         LAB_004645c3
//                              Panel.cpp:620 (10)
//         0046459d     MOV        EAX,dword ptr [ESI + 0xac0]
//         004645a3     TEST       EAX,EAX
//         004645a5     JZ         LAB_004645c3
//                              Panel.cpp:623 (10)
//         004645a7     MOV        EAX,dword ptr [ESI + 0xabc]
//         004645ad     TEST       EAX,EAX
//         004645af     JZ         LAB_004645c3
//                              Panel.cpp:626 (8)
//         004645b1     PUSH       0x0
//         004645b3     PUSH       EAX
//         004645b4     CALL       _ImmSetOpenStatus@8                              undefined _ImmSetOpenStatus@8()
//                              Panel.cpp:628 (10)
//         004645b9     MOV        dword ptr [ESI + 0xac4],0x0
//                               LAB_004645c3                                                 XREF[3]:     0046459b(j), 004645a5(j),
//                                                                                                         004645af(j)
//                              Panel.cpp:629 (2)
//         004645c3     POP        ESI
//         004645c4     RET
//         004645c5     ??         90h
//         004645c6     NOP
//         004645c7     NOP
//         004645c8     NOP
//         004645c9     NOP
//         004645ca     NOP
//         004645cb     NOP
//         004645cc     NOP
//         004645cd     NOP
//         004645ce     NOP
//         004645cf     NOP
    return;
}

int TPanelSystem::IsIMEOn() {
    /* TODO: Stub */
//                              int __thiscall IsIMEOn(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?IsIMEOn@TPanelSystem@@QAEHXZ
//                               TPanelSystem::IsIMEOn
//                              Panel.cpp:635 (6)
//         004645d0     MOV        EAX,dword ptr [ECX + this->ImeOn]
//                              Panel.cpp:637 (1)
//         004645d6     RET
//         004645d7     ??         90h
//         004645d8     NOP
//         004645d9     NOP
//         004645da     NOP
//         004645db     NOP
//         004645dc     NOP
//         004645dd     NOP
//         004645de     NOP
//         004645df     NOP
    return 0;
}

int TPanelSystem::GetInputEnabled() {
    /* TODO: Stub */
//                              int __thiscall GetInputEnabled(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?GetInputEnabled@TPanelSystem@@QAEHXZ                        XREF[2]:     wnd_proc:004654e6(c),
//                               TPanelSystem::GetInputEnabled                                             wnd_proc:00465687(c)
//                              Panel.cpp:643 (6)
//         004645e0     MOV        EAX,dword ptr [ECX + this->InputEnabled]
//                              Panel.cpp:645 (1)
//         004645e6     RET
//         004645e7     ??         90h
//         004645e8     NOP
//         004645e9     NOP
//         004645ea     NOP
//         004645eb     NOP
//         004645ec     NOP
//         004645ed     NOP
//         004645ee     NOP
//         004645ef     NOP
    return 0;
}

void TPanelSystem::EnableInput() {
    /* TODO: Stub */
//                              void __thiscall EnableInput(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?EnableInput@TPanelSystem@@QAEXXZ                            XREF[1]:     enable_input:00422ad2(c)
//                               TPanelSystem::EnableInput
//                              Panel.cpp:651 (10)
//         004645f0     MOV        dword ptr [ECX + this->InputEnabled],0x1
//                              Panel.cpp:653 (1)
//         004645fa     RET
//         004645fb     ??         90h
//         004645fc     NOP
//         004645fd     NOP
//         004645fe     NOP
//         004645ff     NOP
    return;
}

void TPanelSystem::DisableInput() {
    /* TODO: Stub */
//                              void __thiscall DisableInput(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?DisableInput@TPanelSystem@@QAEXXZ                           XREF[1]:     disable_input:00422a77(c)
//                               TPanelSystem::DisableInput
//                              Panel.cpp:659 (10)
//         00464600     MOV        dword ptr [ECX + this->InputEnabled],0x0
//                              Panel.cpp:661 (1)
//         0046460a     RET
//         0046460b     ??         90h
//         0046460c     NOP
//         0046460d     NOP
//         0046460e     NOP
//         0046460f     NOP
    return;
}

void TPanelSystem::stop_sound_system() {
    /* TODO: Stub */
//                              void __thiscall stop_sound_system(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?stop_sound_system@TPanelSystem@@QAEXXZ                      XREF[1]:     stop_sound_system:0041f849(c)
//                               TPanelSystem::stop_sound_system
//                              Panel.cpp:667 (4)
//         00464610     PUSH       ESI
//         00464611     PUSH       EDI
//         00464612     MOV        EDI,this
//                              Panel.cpp:671 (6)
//         00464614     MOV        EAX,dword ptr [EDI + 0x10]
//         00464617     MOV        ESI,dword ptr [EAX + 0x8]
//                              Panel.cpp:672 (9)
//         0046461a     TEST       ESI,ESI
//         0046461c     JZ         LAB_00464638
//                               LAB_0046461e                                                 XREF[1]:     00464636(j)
//         0046461e     CMP        ESI,dword ptr [EDI + 0x10]
//         00464621     JZ         LAB_00464638
//                              Panel.cpp:674 (6)
//         00464623     MOV        this,dword ptr [ESI]
//         00464625     TEST       this,this
//         00464627     JZ         LAB_00464631
//                              Panel.cpp:675 (8)
//         00464629     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         0046462b     CALL       dword ptr [EDX + 0xd0]
//                               LAB_00464631                                                 XREF[1]:     00464627(j)
//                              Panel.cpp:676 (7)
//         00464631     MOV        ESI,dword ptr [ESI + 0x8]
//         00464634     TEST       ESI,ESI
//         00464636     JNZ        LAB_0046461e
//                               LAB_00464638                                                 XREF[2]:     0046461c(j), 00464621(j)
//                              Panel.cpp:680 (3)
//         00464638     POP        EDI
//         00464639     POP        ESI
//         0046463a     RET
//         0046463b     ??         90h
//         0046463c     NOP
//         0046463d     NOP
//         0046463e     NOP
//         0046463f     NOP
    return;
}

int TPanelSystem::restart_sound_system() {
    /* TODO: Stub */
//                              int __thiscall restart_sound_system(TPanelSystem * this)
//              int               EAX:4          <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?restart_sound_system@TPanelSystem@@QAEHXZ                   XREF[1]:     restart_sound_system:0041f981(c)
//                               TPanelSystem::restart_sound_system
//                              Panel.cpp:686 (5)
//         00464640     PUSH       EBX
//         00464641     PUSH       ESI
//         00464642     PUSH       EDI
//         00464643     MOV        EDI,this
//                              Panel.cpp:689 (5)
//         00464645     MOV        EBX,0x1
//                              Panel.cpp:690 (6)
//         0046464a     MOV        EAX,dword ptr [EDI + 0x10]
//         0046464d     MOV        ESI,dword ptr [EAX + 0x8]
//                              Panel.cpp:691 (9)
//         00464650     TEST       ESI,ESI
//         00464652     JZ         LAB_00464674
//                               LAB_00464654                                                 XREF[1]:     00464672(j)
//         00464654     CMP        ESI,dword ptr [EDI + 0x10]
//         00464657     JZ         LAB_00464674
//                              Panel.cpp:693 (6)
//         00464659     MOV        this,dword ptr [ESI]
//         0046465b     TEST       this,this
//         0046465d     JZ         LAB_0046466d
//                              Panel.cpp:695 (12)
//         0046465f     MOV        EDX,dword ptr [this->mouseOwnerValue]
//         00464661     CALL       dword ptr [EDX + 0xd4]
//         00464667     TEST       EAX,EAX
//         00464669     JNZ        LAB_0046466d
//                              Panel.cpp:696 (2)
//         0046466b     XOR        EBX,EBX
//                               LAB_0046466d                                                 XREF[2]:     0046465d(j), 00464669(j)
//                              Panel.cpp:698 (7)
//         0046466d     MOV        ESI,dword ptr [ESI + 0x8]
//         00464670     TEST       ESI,ESI
//         00464672     JNZ        LAB_00464654
//                               LAB_00464674                                                 XREF[2]:     00464652(j), 00464657(j)
//                              Panel.cpp:704 (6)
//         00464674     POP        EDI
//         00464675     MOV        EAX,EBX
//         00464677     POP        ESI
//         00464678     POP        EBX
//         00464679     RET
//         0046467a     ??         90h
//         0046467b     NOP
//         0046467c     NOP
//         0046467d     NOP
//         0046467e     NOP
//         0046467f     NOP
    return 0;
}

void TPanelSystem::restore_system_colors() {
    /* TODO: Stub */
//                              void __thiscall restore_system_colors(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004646d3(W)
//              int[2]            Stack[-0xc]:8  elems                     XREF[1,2]:   004646db(W), 004646c3(*), 004646cb(W)
//              ulong[2]          Stack[-0x14]:8 colors                    XREF[0,2]:   004646bb(W), 004646bf(*)
//                               ?restore_system_colors@TPanelSystem@@QAEXXZ                  XREF[1]:     ~TPanelSystem:00463c57(c)
//                               TPanelSystem::restore_system_colors
//                              Panel.cpp:710 (7)
//         00464680     SUB        ESP,0x10
//         00464683     PUSH       ESI
//         00464684     MOV        ESI,this
//         00464686     PUSH       EDI
//                              Panel.cpp:714 (10)
//         00464687     MOV        EAX,dword ptr [ESI + 0xacc]
//         0046468d     TEST       EAX,EAX
//         0046468f     JZ         LAB_004646e5
//                              Panel.cpp:716 (30)
//         00464691     MOV        EDI,dword ptr [->USER32.DLL::GetSysColor]        = 0048b02a
//         00464697     PUSH       0x5
//         00464699     CALL       EDI=>USER32.DLL::GetSysColor
//         0046469b     CMP        EAX,dword ptr [ESI + 0xad0]
//         004646a1     JNZ        LAB_004646af
//         004646a3     PUSH       0x8
//         004646a5     CALL       EDI=>USER32.DLL::GetSysColor
//         004646a7     CMP        EAX,dword ptr [ESI + 0xad4]
//         004646ad     JZ         LAB_004646e5
//                               LAB_004646af                                                 XREF[1]:     004646a1(j)
//                              Panel.cpp:720 (6)
//         004646af     MOV        EAX,dword ptr [ESI + 0xad0]
//                              Panel.cpp:721 (10)
//         004646b5     MOV        this,dword ptr [ESI + 0xad4]
//         004646bb     MOV        dword ptr [ESP + colors[1]],EAX
//                              Panel.cpp:722 (38)
//         004646bf     LEA        EDX=>colors[1],[ESP + 0x8]
//         004646c3     LEA        EAX=>elems[1],[ESP + 0x10]
//         004646c7     PUSH       EDX
//         004646c8     PUSH       EAX
//         004646c9     PUSH       0x2
//         004646cb     MOV        dword ptr [ESP + elems[1]],0x5
//         004646d3     MOV        dword ptr [ESP + local_4],0x8
//         004646db     MOV        dword ptr [ESP + elems[0]],this
//         004646df     CALL       dword ptr [->USER32.DLL::SetSysColors]           = 0048b038
//                               LAB_004646e5                                                 XREF[2]:     0046468f(j), 004646ad(j)
//                              Panel.cpp:725 (6)
//         004646e5     POP        EDI
//         004646e6     POP        ESI
//         004646e7     ADD        ESP,0x10
//         004646ea     RET
//         004646eb     ??         90h
//         004646ec     NOP
//         004646ed     NOP
//         004646ee     NOP
//         004646ef     NOP
    return;
}

void TPanelSystem::set_restore() {
    /* TODO: Stub */
//                              void __thiscall set_restore(TPanelSystem * this)
//              void              <VOID>         <RETURN>
//              TPanelSystem *    ECX:4 (auto)   this
//                               ?set_restore@TPanelSystem@@QAEXXZ                            XREF[1]:     set_render_all:00422fff(c)
//                               TPanelSystem::set_restore
//                              Panel.cpp:731 (6)
//         004646f0     MOV        EDX,dword ptr [ECX + this->panelListValue]
//         004646f3     MOV        EAX,dword ptr [EDX + 0x8]
//                              Panel.cpp:733 (7)
//         004646f6     CMP        EAX,EDX
//         004646f8     JZ         LAB_00464714
//         004646fa     PUSH       EBX
//         004646fb     MOV        BL,0x1
//                               LAB_004646fd                                                 XREF[1]:     00464711(j)
//                              Panel.cpp:735 (6)
//         004646fd     MOV        EDX,dword ptr [EAX]
//         004646ff     TEST       EDX,EDX
//         00464701     JZ         LAB_00464709
//                              Panel.cpp:736 (6)
//         00464703     MOV        byte ptr [EDX + 0xf3],BL
//                               LAB_00464709                                                 XREF[1]:     00464701(j)
//                              Panel.cpp:737 (10)
//         00464709     MOV        EAX,dword ptr [EAX + 0x8]
//         0046470c     MOV        EDX,dword ptr [ECX + this->panelListValue]
//         0046470f     CMP        EAX,EDX
//         00464711     JNZ        LAB_004646fd
//                              Panel.cpp:731 (1)
//         00464713     POP        EBX
//                               LAB_00464714                                                 XREF[1]:     004646f8(j)
//                              Panel.cpp:739 (1)
//         00464714     RET
//         00464715     ??         90h
//         00464716     NOP
//         00464717     NOP
//         00464718     NOP
//         00464719     NOP
//         0046471a     NOP
//         0046471b     NOP
//         0046471c     NOP
//         0046471d     NOP
//         0046471e     NOP
//         0046471f     NOP
    return;
}

TPanel::TPanel(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TPanel(TPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ??0TPanel@@QAE@XZ                                            XREF[18]:    RGE_Diamond_Map:00436833(c),
//                               TPanel::TPanel                                                            TEasy_Panel:0046711d(c),
//                                                                                                         TButtonPanel:00471ec6(c),
//                                                                                                         TDropDownPanel:00473ed3(c),
//                                                                                                         TEditPanel:004755c3(c),
//                                                                                                         TMessagePanel:00478f5d(c),
//                                                                                                         TPicturePanel:0047a1d3(c),
//                                                                                                         TScrollBarPanel:0047a71f(c),
//                                                                                                         TTextPanel:0047bf43(c),
//                                                                                                         RGE_Panel_Tool_Box:004898f2(c),
//                                                                                                         RGE_Panel_Time:0048a69d(c),
//                                                                                                         TRIBE_Screen_Sed:004a8583(c),
//                                                                                                         TRIBE_Panel_Inven:0051a5dd(c),
//                                                                                                         TRIBE_Panel_Object:0051ae0f(c),
//                                                                                                         TRIBE_Panel_Pop:0051ccbe(c),
//                                                                                                         TRIBE_Panel_Time:0051d7ae(c),
//                                                                                                         TRIBE_Panel_Text_Line:00520d8d(c),
//                                                                                                         RGE_View:0053352e(c)
//                              Panel.cpp:872 (244)
//         004648b0     MOV        EAX,this
//         004648b2     MOV        EDX,0x1
//         004648b7     XOR        this,this
//         004648b9     MOV        dword ptr [EAX + 0x4],this
//         004648bc     MOV        dword ptr [EAX + 0x8],this
//         004648bf     MOV        dword ptr [EAX + 0xc],this
//         004648c2     MOV        dword ptr [EAX + 0x10],this
//         004648c5     MOV        dword ptr [EAX + 0x14],this
//         004648c8     MOV        dword ptr [EAX + 0x18],this
//         004648cb     MOV        dword ptr [EAX + 0x1c],this
//         004648ce     MOV        dword ptr [EAX + 0x20],this
//         004648d1     MOV        dword ptr [EAX + 0x34],this
//         004648d4     MOV        dword ptr [EAX + 0x38],0x2
//         004648db     MOV        dword ptr [EAX + 0x3c],this
//         004648de     MOV        dword ptr [EAX + 0x40],this
//         004648e1     MOV        dword ptr [EAX + 0x44],this
//         004648e4     MOV        dword ptr [EAX + 0x48],this
//         004648e7     MOV        dword ptr [EAX + 0x4c],this
//         004648ea     MOV        dword ptr [EAX + 0x50],this
//         004648ed     MOV        dword ptr [EAX + 0x54],this
//         004648f0     MOV        dword ptr [EAX + 0x58],this
//         004648f3     MOV        dword ptr [EAX + 0x5c],this
//         004648f6     MOV        dword ptr [EAX + 0x60],this
//         004648f9     MOV        dword ptr [EAX + 0x64],this
//         004648fc     MOV        dword ptr [EAX + 0x68],this
//         004648ff     MOV        dword ptr [EAX + 0x6c],EDX
//         00464902     MOV        dword ptr [EAX + 0x70],this
//         00464905     MOV        dword ptr [EAX + 0x74],this
//         00464908     MOV        dword ptr [EAX + 0x78],this
//         0046490b     MOV        dword ptr [EAX + 0x7c],EDX
//         0046490e     MOV        dword ptr [EAX + 0x80],EDX
//         00464914     MOV        dword ptr [EAX + 0x88],this
//         0046491a     MOV        dword ptr [EAX + 0x9c],this
//         00464920     MOV        dword ptr [EAX + 0xa0],this
//         00464926     MOV        dword ptr [EAX + 0xa4],this
//         0046492c     MOV        dword ptr [EAX + 0xa8],this
//         00464932     MOV        dword ptr [EAX + 0xac],this
//         00464938     MOV        dword ptr [EAX + 0xb0],this
//         0046493e     MOV        dword ptr [EAX + 0xb4],this
//         00464944     MOV        dword ptr [EAX + 0xb8],this
//         0046494a     MOV        dword ptr [EAX + 0xc0],this
//         00464950     MOV        dword ptr [EAX + 0xc4],this
//         00464956     MOV        dword ptr [EAX + 0xc8],this
//         0046495c     MOV        dword ptr [EAX + 0xcc],this
//         00464962     MOV        dword ptr [EAX + 0xd0],this
//         00464968     MOV        dword ptr [EAX + 0xd4],this
//         0046496e     MOV        dword ptr [EAX + 0xd8],this
//         00464974     MOV        dword ptr [EAX + 0xdc],this
//         0046497a     MOV        dword ptr [EAX + 0xe0],this
//         00464980     MOV        byte ptr [EAX + 0xec],this
//         00464986     MOV        byte ptr [EAX + 0xed],this
//         0046498c     MOV        byte ptr [EAX + 0xee],this
//         00464992     MOV        byte ptr [EAX + 0xef],this
//         00464998     MOV        byte ptr [EAX + 0xf0],this
//         0046499e     MOV        byte ptr [EAX + 0xf2],this
//                              Panel.cpp:873 (6)
//         004649a4     MOV        dword ptr [EAX + 0x8c],this
//                              Panel.cpp:874 (6)
//         004649aa     MOV        dword ptr [EAX + 0x90],this
//                              Panel.cpp:875 (6)
//         004649b0     MOV        dword ptr [EAX + 0x94],this
//                              Panel.cpp:876 (6)
//         004649b6     MOV        dword ptr [EAX + 0x98],this
//                              Panel.cpp:877 (25)
//         004649bc     OR         this,0xffffffff
//         004649bf     MOV        dword ptr [EAX + 0xbc],0xfa
//         004649c9     MOV        dword ptr [EAX],TPanel::`vftable'                = 00464890
//         004649cf     MOV        dword ptr [EAX + 0xe4],this
//                              Panel.cpp:878 (6)
//         004649d5     MOV        dword ptr [EAX + 0xe8],this
//                              Panel.cpp:879 (1)
//         004649db     RET
//         004649dc     ??         90h
//         004649dd     NOP
//         004649de     NOP
//         004649df     NOP
}

TPanel::TPanel() {
    /* TODO: Stub */
//                              undefined __thiscall TPanel(TPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ??0TPanel@@QAE@XZ                                            XREF[18]:    RGE_Diamond_Map:00436833(c),
//                               TPanel::TPanel                                                            TEasy_Panel:0046711d(c),
//                                                                                                         TButtonPanel:00471ec6(c),
//                                                                                                         TDropDownPanel:00473ed3(c),
//                                                                                                         TEditPanel:004755c3(c),
//                                                                                                         TMessagePanel:00478f5d(c),
//                                                                                                         TPicturePanel:0047a1d3(c),
//                                                                                                         TScrollBarPanel:0047a71f(c),
//                                                                                                         TTextPanel:0047bf43(c),
//                                                                                                         RGE_Panel_Tool_Box:004898f2(c),
//                                                                                                         RGE_Panel_Time:0048a69d(c),
//                                                                                                         TRIBE_Screen_Sed:004a8583(c),
//                                                                                                         TRIBE_Panel_Inven:0051a5dd(c),
//                                                                                                         TRIBE_Panel_Object:0051ae0f(c),
//                                                                                                         TRIBE_Panel_Pop:0051ccbe(c),
//                                                                                                         TRIBE_Panel_Time:0051d7ae(c),
//                                                                                                         TRIBE_Panel_Text_Line:00520d8d(c),
//                                                                                                         RGE_View:0053352e(c)
//                              Panel.cpp:872 (244)
//         004648b0     MOV        EAX,this
//         004648b2     MOV        EDX,0x1
//         004648b7     XOR        this,this
//         004648b9     MOV        dword ptr [EAX + 0x4],this
//         004648bc     MOV        dword ptr [EAX + 0x8],this
//         004648bf     MOV        dword ptr [EAX + 0xc],this
//         004648c2     MOV        dword ptr [EAX + 0x10],this
//         004648c5     MOV        dword ptr [EAX + 0x14],this
//         004648c8     MOV        dword ptr [EAX + 0x18],this
//         004648cb     MOV        dword ptr [EAX + 0x1c],this
//         004648ce     MOV        dword ptr [EAX + 0x20],this
//         004648d1     MOV        dword ptr [EAX + 0x34],this
//         004648d4     MOV        dword ptr [EAX + 0x38],0x2
//         004648db     MOV        dword ptr [EAX + 0x3c],this
//         004648de     MOV        dword ptr [EAX + 0x40],this
//         004648e1     MOV        dword ptr [EAX + 0x44],this
//         004648e4     MOV        dword ptr [EAX + 0x48],this
//         004648e7     MOV        dword ptr [EAX + 0x4c],this
//         004648ea     MOV        dword ptr [EAX + 0x50],this
//         004648ed     MOV        dword ptr [EAX + 0x54],this
//         004648f0     MOV        dword ptr [EAX + 0x58],this
//         004648f3     MOV        dword ptr [EAX + 0x5c],this
//         004648f6     MOV        dword ptr [EAX + 0x60],this
//         004648f9     MOV        dword ptr [EAX + 0x64],this
//         004648fc     MOV        dword ptr [EAX + 0x68],this
//         004648ff     MOV        dword ptr [EAX + 0x6c],EDX
//         00464902     MOV        dword ptr [EAX + 0x70],this
//         00464905     MOV        dword ptr [EAX + 0x74],this
//         00464908     MOV        dword ptr [EAX + 0x78],this
//         0046490b     MOV        dword ptr [EAX + 0x7c],EDX
//         0046490e     MOV        dword ptr [EAX + 0x80],EDX
//         00464914     MOV        dword ptr [EAX + 0x88],this
//         0046491a     MOV        dword ptr [EAX + 0x9c],this
//         00464920     MOV        dword ptr [EAX + 0xa0],this
//         00464926     MOV        dword ptr [EAX + 0xa4],this
//         0046492c     MOV        dword ptr [EAX + 0xa8],this
//         00464932     MOV        dword ptr [EAX + 0xac],this
//         00464938     MOV        dword ptr [EAX + 0xb0],this
//         0046493e     MOV        dword ptr [EAX + 0xb4],this
//         00464944     MOV        dword ptr [EAX + 0xb8],this
//         0046494a     MOV        dword ptr [EAX + 0xc0],this
//         00464950     MOV        dword ptr [EAX + 0xc4],this
//         00464956     MOV        dword ptr [EAX + 0xc8],this
//         0046495c     MOV        dword ptr [EAX + 0xcc],this
//         00464962     MOV        dword ptr [EAX + 0xd0],this
//         00464968     MOV        dword ptr [EAX + 0xd4],this
//         0046496e     MOV        dword ptr [EAX + 0xd8],this
//         00464974     MOV        dword ptr [EAX + 0xdc],this
//         0046497a     MOV        dword ptr [EAX + 0xe0],this
//         00464980     MOV        byte ptr [EAX + 0xec],this
//         00464986     MOV        byte ptr [EAX + 0xed],this
//         0046498c     MOV        byte ptr [EAX + 0xee],this
//         00464992     MOV        byte ptr [EAX + 0xef],this
//         00464998     MOV        byte ptr [EAX + 0xf0],this
//         0046499e     MOV        byte ptr [EAX + 0xf2],this
//                              Panel.cpp:873 (6)
//         004649a4     MOV        dword ptr [EAX + 0x8c],this
//                              Panel.cpp:874 (6)
//         004649aa     MOV        dword ptr [EAX + 0x90],this
//                              Panel.cpp:875 (6)
//         004649b0     MOV        dword ptr [EAX + 0x94],this
//                              Panel.cpp:876 (6)
//         004649b6     MOV        dword ptr [EAX + 0x98],this
//                              Panel.cpp:877 (25)
//         004649bc     OR         this,0xffffffff
//         004649bf     MOV        dword ptr [EAX + 0xbc],0xfa
//         004649c9     MOV        dword ptr [EAX],TPanel::`vftable'                = 00464890
//         004649cf     MOV        dword ptr [EAX + 0xe4],this
//                              Panel.cpp:878 (6)
//         004649d5     MOV        dword ptr [EAX + 0xe8],this
//                              Panel.cpp:879 (1)
//         004649db     RET
//         004649dc     ??         90h
//         004649dd     NOP
//         004649de     NOP
//         004649df     NOP
}

TPanel::~TPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TPanel(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ??1TPanel@@UAE@XZ                                            XREF[21]:    ~RGE_Diamond_Map:004369a4(c),
//                               TPanel::~TPanel                                                           `scalar_deleting_destructor':00464
//                                                                                                         ~TEasy_Panel:0046728a(c),
//                                                                                                         ~TButtonPanel:0047208f(c),
//                                                                                                         ~TDropDownPanel:00473fbb(c),
//                                                                                                         ~TEditPanel:00475752(c),
//                                                                                                         ~TMessagePanel:004790c5(c),
//                                                                                                         ~TPicturePanel:0047a28a(c),
//                                                                                                         ~TScrollBarPanel:0047a8a6(c),
//                                                                                                         ~TTextPanel:0047c105(c),
//                                                                                                         ~RGE_Panel_Tool_Box:00489f35(c),
//                                                                                                         ~TPanel:0048a72e(T),
//                                                                                                         ~RGE_Panel_Time:0048a730(j),
//                                                                                                         ~TRIBE_Panel_Inven:0051a73f(c),
//                                                                                                         ~TRIBE_Panel_Inven:0051a74e(c),
//                                                                                                         ~TRIBE_Panel_Object:0051b0ee(c),
//                                                                                                         ~TRIBE_Panel_Pop:0051ce25(c),
//                                                                                                         ~TRIBE_Panel_Time:0051d925(c),
//                                                                                                         ~TPanel:00520e1e(T),
//                                                                                                         ~TRIBE_Panel_Text_Line:00520e20(j)
//                                                                                                         [more]
//                              Panel.cpp:884 (9)
//         004649e0     PUSH       ESI
//         004649e1     MOV        ESI,this
//         004649e3     MOV        dword ptr [ESI],TPanel::`vftable'                = 00464890
//                              Panel.cpp:887 (5)
//         004649e9     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              Panel.cpp:889 (22)
//         004649ee     MOV        EAX,dword ptr [ESI + 0x1c]
//         004649f1     TEST       EAX,EAX
//         004649f3     JZ         LAB_00464a16
//         004649f5     PUSH       ESI
//         004649f6     MOV        this,panel_system
//         004649fb     CALL       TPanelSystem::inSystem                           int inSystem(TPanelSystem * this, TPanel * pa
//         00464a00     TEST       EAX,EAX
//         00464a02     JZ         LAB_00464a16
//                              Panel.cpp:890 (18)
//         00464a04     MOV        this,ESI
//         00464a06     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         00464a0b     PUSH       EAX
//         00464a0c     MOV        this,panel_system
//         00464a11     CALL       TPanelSystem::removePanel                        int removePanel(TPanelSystem * this, char * p
//                               LAB_00464a16                                                 XREF[2]:     004649f3(j), 00464a02(j)
//                              Panel.cpp:894 (7)
//         00464a16     MOV        EAX,dword ptr [ESI + 0x54]
//         00464a19     TEST       EAX,EAX
//         00464a1b     JZ         LAB_00464a3d
//                              Panel.cpp:895 (7)
//         00464a1d     MOV        this,dword ptr [ESI + 0x40]
//         00464a20     TEST       this,this
//         00464a22     JZ         LAB_00464a2a
//                              Panel.cpp:896 (6)
//         00464a24     PUSH       EAX
//         00464a25     CALL       TPanel::remove_panel_node                        void remove_panel_node(TPanel * this, PanelNo
//                               LAB_00464a2a                                                 XREF[1]:     00464a22(j)
//                              Panel.cpp:897 (12)
//         00464a2a     MOV        EAX,dword ptr [ESI + 0x54]
//         00464a2d     PUSH       EAX
//         00464a2e     CALL       free                                             undefined free()
//         00464a33     ADD        ESP,0x4
//                              Panel.cpp:898 (7)
//         00464a36     MOV        dword ptr [ESI + 0x54],0x0
//                               LAB_00464a3d                                                 XREF[1]:     00464a1b(j)
//                              Panel.cpp:912 (17)
//         00464a3d     MOV        EAX,dword ptr [ESI + 0x88]
//         00464a43     MOV        dword ptr [ESI + 0x58],0x0
//         00464a4a     TEST       EAX,EAX
//         00464a4c     JZ         LAB_00464a5f
//                              Panel.cpp:913 (7)
//         00464a4e     PUSH       EAX
//         00464a4f     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              Panel.cpp:914 (10)
//         00464a55     MOV        dword ptr [ESI + 0x88],0x0
//                               LAB_00464a5f                                                 XREF[1]:     00464a4c(j)
//                              Panel.cpp:917 (7)
//         00464a5f     MOV        this,dword ptr [ESI + 0x40]
//         00464a62     TEST       this,this
//         00464a64     JZ         LAB_00464a6d
//                              Panel.cpp:918 (7)
//         00464a66     MOV        EDX,dword ptr [this->_padding_]
//         00464a68     PUSH       0x2
//         00464a6a     CALL       dword ptr [EDX + 0x20]
//                               LAB_00464a6d                                                 XREF[1]:     00464a64(j)
//                              Panel.cpp:920 (7)
//         00464a6d     MOV        ESI,dword ptr [ESI + 0x1c]
//         00464a70     TEST       ESI,ESI
//         00464a72     JZ         LAB_00464a7d
//                              Panel.cpp:921 (9)
//         00464a74     PUSH       ESI
//         00464a75     CALL       free                                             undefined free()
//         00464a7a     ADD        ESP,0x4
//                               LAB_00464a7d                                                 XREF[1]:     00464a72(j)
//                              Panel.cpp:922 (2)
//         00464a7d     POP        ESI
//         00464a7e     RET
//         00464a7f     ??         90h
}

long TPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    /* TODO: Stub */
//                              long __thiscall setup(TPanel * this, TDrawArea * param_1, TPanel * p
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00464a81(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00464a88(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00464aa0(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00464a9c(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00464aaa(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00464aba(R)
//              uchar             Stack[0x1c]:1  param_7
//                               ?setup@TPanel@@UAEJPAVTDrawArea@@PAV1@JJJJE@Z                XREF[92]:    setup:004369f7(c),
//                               TPanel::setup                                                             setup:00466b7e(c),
//                                                                                                         setup:004720c5(c),
//                                                                                                         setup:00474092(c),
//                                                                                                         setup:004757ca(c),
//                                                                                                         setup:0047a38c(c),
//                                                                                                         setup:0047a902(c),
//                                                                                                         setup:0047c145(c),
//                                                                                                         setup:0047c221(c),
//                                                                                                         setup:0047c315(c),
//                                                                                                         RGE_Panel_Tool_Box:00489972(c),
//                                                                                                         RGE_Panel_Time:0048a6e5(c),
//                                                                                                         TRIBE_Panel_Inven:0051a642(c),
//                                                                                                         TRIBE_Panel_Object:0051af40(c),
//                                                                                                         TRIBE_Panel_Pop:0051cd60(c),
//                                                                                                         TRIBE_Panel_Time:0051d85e(c),
//                                                                                                         setup:0051ea05(c),
//                                                                                                         TRIBE_Panel_Text_Line:00520dcb(c),
//                                                                                                         setup:0053399a(c), 0056f50c(*),
//                                                                                                         [more]
//                              Panel.cpp:928 (1)
//         00464a80     PUSH       EBX
//                              Panel.cpp:929 (7)
//         00464a81     MOV        EAX,dword ptr [ESP + param_1]
//         00464a85     PUSH       ESI
//         00464a86     MOV        ESI,this
//                              Panel.cpp:930 (4)
//         00464a88     MOV        this,dword ptr [ESP + param_2]
//                              Panel.cpp:932 (16)
//         00464a8c     XOR        EBX,EBX
//         00464a8e     MOV        dword ptr [ESI + 0x40],this
//         00464a91     MOV        this,dword ptr [ESI + 0x34]
//         00464a94     CMP        this,EBX
//         00464a96     PUSH       EDI
//         00464a97     MOV        dword ptr [ESI + 0x20],EAX
//         00464a9a     JNZ        LAB_00464adc
//                              Panel.cpp:935 (14)
//         00464a9c     MOV        this,dword ptr [ESP + param_4]
//         00464aa0     MOV        EDX,dword ptr [ESP + param_3]
//         00464aa4     MOV        dword ptr [ESI + 0xa0],this
//                              Panel.cpp:938 (10)
//         00464aaa     MOV        this,dword ptr [ESP + param_5]
//         00464aae     MOV        dword ptr [ESI + 0xac],this
//                              Panel.cpp:939 (6)
//         00464ab4     MOV        dword ptr [ESI + 0xb0],this
//                              Panel.cpp:940 (28)
//         00464aba     MOV        this,dword ptr [ESP + param_6]
//         00464abe     MOV        dword ptr [ESI + 0x9c],EDX
//         00464ac4     MOV        dword ptr [ESI + 0xa4],EBX
//         00464aca     MOV        dword ptr [ESI + 0xa8],EBX
//         00464ad0     MOV        dword ptr [ESI + 0xb4],this
//                              Panel.cpp:941 (6)
//         00464ad6     MOV        dword ptr [ESI + 0xb8],this
//                               LAB_00464adc                                                 XREF[1]:     00464a9a(j)
//                              Panel.cpp:945 (14)
//         00464adc     MOV        EDI,dword ptr [ESI]
//         00464ade     CMP        EAX,EBX
//         00464ae0     JZ         LAB_00464aec
//         00464ae2     MOV        EDX,dword ptr [EAX + 0x1c]
//         00464ae5     MOV        EAX,dword ptr [EAX + 0x18]
//         00464ae8     PUSH       EDX
//         00464ae9     PUSH       EAX
//                              Panel.cpp:946 (2)
//         00464aea     JMP        LAB_00464aee
//                               LAB_00464aec                                                 XREF[1]:     00464ae0(j)
//                              Panel.cpp:947 (7)
//         00464aec     PUSH       EBX
//         00464aed     PUSH       EBX
//                               LAB_00464aee                                                 XREF[1]:     00464aea(j)
//         00464aee     MOV        this,ESI
//         00464af0     CALL       dword ptr [EDI + 0x50]
//                              Panel.cpp:948 (10)
//         00464af3     MOV        this,dword ptr [ESP + 0x28]
//         00464af7     PUSH       this
//         00464af8     MOV        this,ESI
//         00464afa     CALL       dword ptr [EDI + 0x10]
//                              Panel.cpp:952 (10)
//         00464afd     MOV        EAX,dword ptr [ESI + 0x54]
//         00464b00     MOV        dword ptr [ESI + 0x68],EBX
//         00464b03     CMP        EAX,EBX
//         00464b05     JNZ        LAB_00464b42
//                              Panel.cpp:955 (12)
//         00464b07     PUSH       0xc
//         00464b09     PUSH       offset DAT_fffffff8
//         00464b0b     CALL       calloc                                           undefined calloc()
//         00464b10     ADD        ESP,0x8
//                              Panel.cpp:956 (7)
//         00464b13     CMP        EAX,EBX
//         00464b15     MOV        dword ptr [ESI + 0x54],EAX
//         00464b18     JNZ        LAB_00464b22
//                              Panel.cpp:957 (2)
//         00464b1a     XOR        EAX,EAX
//                              Panel.cpp:966 (6)
//         00464b1c     POP        EDI
//         00464b1d     POP        ESI
//         00464b1e     POP        EBX
//         00464b1f     RET        0x1c
//                               LAB_00464b22                                                 XREF[1]:     00464b18(j)
//                              Panel.cpp:958 (2)
//         00464b22     MOV        dword ptr [EAX],ESI
//                              Panel.cpp:959 (6)
//         00464b24     MOV        EDX,dword ptr [ESI + 0x54]
//         00464b27     MOV        dword ptr [EDX + 0x4],EBX
//                              Panel.cpp:960 (6)
//         00464b2a     MOV        EAX,dword ptr [ESI + 0x54]
//         00464b2d     MOV        dword ptr [EAX + 0x8],EBX
//                              Panel.cpp:961 (7)
//         00464b30     MOV        this,dword ptr [ESI + 0x40]
//         00464b33     CMP        this,EBX
//         00464b35     JZ         LAB_00464b42
//                              Panel.cpp:962 (11)
//         00464b37     MOV        EDX,dword ptr [ESI + 0x54]
//         00464b3a     PUSH       EBX
//         00464b3b     PUSH       EBX=>DAT_fffffff8
//         00464b3c     PUSH       EDX=>DAT_fffffff4
//         00464b3d     CALL       TPanel::add_panel_node                           void add_panel_node(TPanel * this, PanelNode
//                               LAB_00464b42                                                 XREF[2]:     00464b05(j), 00464b35(j)
//                              Panel.cpp:966 (11)
//         00464b42     POP        EDI
//         00464b43     POP        ESI
//         00464b44     MOV        EAX,0x1
//         00464b49     POP        EBX
//         00464b4a     RET        0x1c
//         00464b4d     ??         90h
//         00464b4e     NOP
//         00464b4f     NOP
    return 0;
}

void TPanel::add_panel_node(PanelNode* param_1, PanelNode* param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall add_panel_node(TPanel * this, PanelNode * param_1, P
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              PanelNode *       Stack[0x4]:4   param_1                   XREF[3]:     00464b60(R), 00464b7c(R), 00464b95(R)
//              PanelNode *       Stack[0x8]:4   param_2                   XREF[1]:     00464b50(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00464b8f(R)
//                               ?add_panel_node@TPanel@@QAEXPAUPanelNode@@0H@Z               XREF[3]:     setup:00464b3d(c),
//                               TPanel::add_panel_node                                                    set_child_z_order:004665d7(c),
//                                                                                                         set_child_z_order:004665ee(c)
//                              Panel.cpp:972 (9)
//         00464b50     MOV        EDX,dword ptr [ESP + param_2]
//         00464b54     PUSH       EDI
//         00464b55     TEST       EDX,EDX
//         00464b57     JNZ        LAB_00464b8f
//                              Panel.cpp:978 (7)
//         00464b59     MOV        EDX,dword ptr [ECX + this->first_child_node]
//         00464b5c     TEST       EDX,EDX
//         00464b5e     JNZ        LAB_00464b6c
//                              Panel.cpp:980 (7)
//         00464b60     MOV        EAX,dword ptr [ESP + param_1]
//         00464b64     MOV        dword ptr [EAX + 0x4],EDX
//                              Panel.cpp:981 (3)
//         00464b67     MOV        dword ptr [EAX + 0x8],EDX
//                              Panel.cpp:983 (2)
//         00464b6a     JMP        LAB_00464bc9
//                               LAB_00464b6c                                                 XREF[1]:     00464b5e(j)
//                              Panel.cpp:986 (7)
//         00464b6c     MOV        EAX,dword ptr [EDX + 0x8]
//         00464b6f     TEST       EAX,EAX
//         00464b71     JZ         LAB_00464b7c
//                               LAB_00464b73                                                 XREF[1]:     00464b7a(j)
//                              Panel.cpp:987 (9)
//         00464b73     MOV        EDX,EAX
//         00464b75     MOV        EAX,dword ptr [EDX + 0x8]
//         00464b78     TEST       EAX,EAX
//         00464b7a     JNZ        LAB_00464b73
//                               LAB_00464b7c                                                 XREF[1]:     00464b71(j)
//                              Panel.cpp:988 (7)
//         00464b7c     MOV        EAX,dword ptr [ESP + param_1]
//         00464b80     MOV        dword ptr [EDX + 0x8],EAX
//                              Panel.cpp:989 (3)
//         00464b83     MOV        dword ptr [EAX + 0x4],EDX
//                              Panel.cpp:990 (7)
//         00464b86     MOV        dword ptr [EAX + 0x8],0x0
//                              Panel.cpp:993 (2)
//         00464b8d     JMP        LAB_00464bc9
//                               LAB_00464b8f                                                 XREF[1]:     00464b57(j)
//                              Panel.cpp:995 (6)
//         00464b8f     MOV        EAX,dword ptr [ESP + param_3]
//         00464b93     TEST       EAX,EAX
//                              Panel.cpp:998 (9)
//         00464b95     MOV        EAX,dword ptr [ESP + param_1]
//         00464b99     JZ         LAB_00464bb3
//         00464b9b     MOV        dword ptr [EAX + 0x4],EDX
//                              Panel.cpp:999 (6)
//         00464b9e     MOV        EDI,dword ptr [EDX + 0x8]
//         00464ba1     MOV        dword ptr [EAX + 0x8],EDI
//                              Panel.cpp:1000 (3)
//         00464ba4     MOV        dword ptr [EDX + 0x8],EAX
//                              Panel.cpp:1001 (7)
//         00464ba7     MOV        EDX,dword ptr [EAX + 0x8]
//         00464baa     TEST       EDX,EDX
//         00464bac     JZ         LAB_00464bc9
//                              Panel.cpp:1002 (3)
//         00464bae     MOV        dword ptr [EDX + 0x4],EAX
//                              Panel.cpp:1004 (2)
//         00464bb1     JMP        LAB_00464bc9
//                               LAB_00464bb3                                                 XREF[1]:     00464b99(j)
//                              Panel.cpp:1007 (3)
//         00464bb3     MOV        EDI,dword ptr [EDX + 0x4]
//                              Panel.cpp:1008 (6)
//         00464bb6     MOV        dword ptr [EAX + 0x8],EDX
//         00464bb9     MOV        dword ptr [EAX + 0x4],EDI
//                              Panel.cpp:1009 (3)
//         00464bbc     MOV        dword ptr [EDX + 0x4],EAX
//                              Panel.cpp:1010 (7)
//         00464bbf     MOV        EDX,dword ptr [EAX + 0x4]
//         00464bc2     TEST       EDX,EDX
//         00464bc4     JZ         LAB_00464bc9
//                              Panel.cpp:1011 (3)
//         00464bc6     MOV        dword ptr [EDX + 0x8],EAX
//                               LAB_00464bc9                                                 XREF[5]:     00464b6a(j), 00464b8d(j),
//                                                                                                         00464bac(j), 00464bb1(j),
//                                                                                                         00464bc4(j)
//                              Panel.cpp:1016 (7)
//         00464bc9     MOV        EDX,dword ptr [EAX + 0x4]
//         00464bcc     TEST       EDX,EDX
//         00464bce     JNZ        LAB_00464bd3
//                              Panel.cpp:1017 (3)
//         00464bd0     MOV        dword ptr [ECX + this->first_child_node],EAX
//                               LAB_00464bd3                                                 XREF[1]:     00464bce(j)
//                              Panel.cpp:1019 (7)
//         00464bd3     MOV        EDX,dword ptr [EAX + 0x8]
//         00464bd6     TEST       EDX,EDX
//         00464bd8     JNZ        LAB_00464bdd
//                              Panel.cpp:1020 (3)
//         00464bda     MOV        dword ptr [ECX + this->last_child_node],EAX
//                               LAB_00464bdd                                                 XREF[1]:     00464bd8(j)
//                              Panel.cpp:1021 (4)
//         00464bdd     POP        EDI
//         00464bde     RET        0xc
//         00464be1     ??         90h
//         00464be2     NOP
//         00464be3     NOP
//         00464be4     NOP
//         00464be5     NOP
//         00464be6     NOP
//         00464be7     NOP
//         00464be8     NOP
//         00464be9     NOP
//         00464bea     NOP
//         00464beb     NOP
//         00464bec     NOP
//         00464bed     NOP
//         00464bee     NOP
//         00464bef     NOP
    return;
}

void TPanel::remove_panel_node(PanelNode* param_1) {
    /* TODO: Stub */
//                              void __thiscall remove_panel_node(TPanel * this, PanelNode * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              PanelNode *       Stack[0x4]:4   param_1                   XREF[1]:     00464bf0(R)
//                               ?remove_panel_node@TPanel@@QAEXPAUPanelNode@@@Z              XREF[2]:     ~TPanel:00464a25(c),
//                               TPanel::remove_panel_node                                                 set_child_z_order:004665a6(c)
//                              Panel.cpp:1027 (12)
//         00464bf0     MOV        EAX,dword ptr [ESP + param_1]
//         00464bf4     MOV        EDX,dword ptr [ECX + this->first_child_node]
//         00464bf7     CMP        EAX,EDX
//         00464bf9     PUSH       EDI
//         00464bfa     JNZ        LAB_00464c02
//                              Panel.cpp:1029 (6)
//         00464bfc     MOV        EDX,dword ptr [EAX + 0x8]
//         00464bff     MOV        dword ptr [ECX + this->first_child_node],EDX
//                               LAB_00464c02                                                 XREF[1]:     00464bfa(j)
//                              Panel.cpp:1031 (5)
//         00464c02     CMP        EAX,dword ptr [ECX + this->last_child_node]
//         00464c05     JNZ        LAB_00464c0d
//                              Panel.cpp:1032 (6)
//         00464c07     MOV        EDX,dword ptr [EAX + 0x4]
//         00464c0a     MOV        dword ptr [ECX + this->last_child_node],EDX
//                               LAB_00464c0d                                                 XREF[1]:     00464c05(j)
//                              Panel.cpp:1034 (7)
//         00464c0d     MOV        EDX,dword ptr [EAX + 0x4]
//         00464c10     TEST       EDX,EDX
//         00464c12     JZ         LAB_00464c1a
//                              Panel.cpp:1035 (6)
//         00464c14     MOV        EDI,dword ptr [EAX + 0x8]
//         00464c17     MOV        dword ptr [EDX + 0x8],EDI
//                               LAB_00464c1a                                                 XREF[1]:     00464c12(j)
//                              Panel.cpp:1037 (7)
//         00464c1a     MOV        EDX,dword ptr [EAX + 0x8]
//         00464c1d     TEST       EDX,EDX
//         00464c1f     JZ         LAB_00464c27
//                              Panel.cpp:1038 (6)
//         00464c21     MOV        EDI,dword ptr [EAX + 0x4]
//         00464c24     MOV        dword ptr [EDX + 0x4],EDI
//                               LAB_00464c27                                                 XREF[1]:     00464c1f(j)
//                              Panel.cpp:1043 (23)
//         00464c27     MOV        EDI,dword ptr [EAX]
//         00464c29     MOV        dword ptr [EAX + 0x4],0x0
//         00464c30     MOV        dword ptr [EAX + 0x8],0x0
//         00464c37     MOV        EDX,dword ptr [ECX + this->curr_child]
//         00464c3a     CMP        EDX,EDI
//         00464c3c     JNZ        LAB_00464c45
//                              Panel.cpp:1044 (7)
//         00464c3e     MOV        dword ptr [ECX + this->curr_child],0x0
//                               LAB_00464c45                                                 XREF[1]:     00464c3c(j)
//                              Panel.cpp:1045 (4)
//         00464c45     POP        EDI
//         00464c46     RET        0x4
//         00464c49     ??         90h
//         00464c4a     NOP
//         00464c4b     NOP
//         00464c4c     NOP
//         00464c4d     NOP
//         00464c4e     NOP
//         00464c4f     NOP
    return;
}

void TPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TPanel * this, tagRECT param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT           Stack[0x4]:16  param_1                   XREF[1,3]:   00464d84(R), 00464d74(R), 00464d7d(R), 00464d70(R)
//                               ?set_rect@TPanel@@UAEXUtagRECT@@@Z                           XREF[73]:    0056f510(*), 0056f618(*),
//                               TPanel::set_rect                                                          0056f758(*), 0056f8a0(*),
//                                                                                                         0056f9d0(*), 0056fb00(*),
//                                                                                                         0056fc38(*), 0056fd68(*),
//                                                                                                         0056fe98(*), 0056ffc8(*),
//                                                                                                         005700f8(*), 00570c40(*),
//                                                                                                         00570d20(*), 00570fd0(*),
//                                                                                                         005710b8(*), 005711e8(*),
//                                                                                                         005712c8(*), 005713b0(*),
//                                                                                                         00571490(*), 00571580(*), [more]
//                              Panel.cpp:1118 (33)
//         00464d70     MOV        EDX,dword ptr [ESP + param_1.bottom]
//         00464d74     MOV        EAX,dword ptr [ESP + param_1.top]
//         00464d78     SUB        EDX,EAX
//         00464d7a     PUSH       ESI
//         00464d7b     INC        EDX
//         00464d7c     PUSH       EDI
//         00464d7d     MOV        EDI,dword ptr [ESP + param_1.right]
//         00464d81     MOV        ESI,dword ptr [this->_padding_]
//         00464d83     PUSH       EDX
//         00464d84     MOV        EDX,dword ptr [ESP + param_1.left]
//         00464d88     SUB        EDI,EDX
//         00464d8a     INC        EDI
//         00464d8b     PUSH       EDI
//         00464d8c     PUSH       EAX
//         00464d8d     PUSH       EDX
//         00464d8e     CALL       dword ptr [ESI + 0xc]
//                              Panel.cpp:1120 (5)
//         00464d91     POP        EDI
//         00464d92     POP        ESI
//         00464d93     RET        0x10
//         00464d96     ??         90h
//         00464d97     NOP
//         00464d98     NOP
//         00464d99     NOP
//         00464d9a     NOP
//         00464d9b     NOP
//         00464d9c     NOP
//         00464d9d     NOP
//         00464d9e     NOP
//         00464d9f     NOP
    return;
}

void TPanel::set_rect(tagRECT param_1) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TPanel * this, tagRECT param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT           Stack[0x4]:16  param_1                   XREF[1,3]:   00464d84(R), 00464d74(R), 00464d7d(R), 00464d70(R)
//                               ?set_rect@TPanel@@UAEXUtagRECT@@@Z                           XREF[73]:    0056f510(*), 0056f618(*),
//                               TPanel::set_rect                                                          0056f758(*), 0056f8a0(*),
//                                                                                                         0056f9d0(*), 0056fb00(*),
//                                                                                                         0056fc38(*), 0056fd68(*),
//                                                                                                         0056fe98(*), 0056ffc8(*),
//                                                                                                         005700f8(*), 00570c40(*),
//                                                                                                         00570d20(*), 00570fd0(*),
//                                                                                                         005710b8(*), 005711e8(*),
//                                                                                                         005712c8(*), 005713b0(*),
//                                                                                                         00571490(*), 00571580(*), [more]
//                              Panel.cpp:1118 (33)
//         00464d70     MOV        EDX,dword ptr [ESP + param_1.bottom]
//         00464d74     MOV        EAX,dword ptr [ESP + param_1.top]
//         00464d78     SUB        EDX,EAX
//         00464d7a     PUSH       ESI
//         00464d7b     INC        EDX
//         00464d7c     PUSH       EDI
//         00464d7d     MOV        EDI,dword ptr [ESP + param_1.right]
//         00464d81     MOV        ESI,dword ptr [this->_padding_]
//         00464d83     PUSH       EDX
//         00464d84     MOV        EDX,dword ptr [ESP + param_1.left]
//         00464d88     SUB        EDI,EDX
//         00464d8a     INC        EDI
//         00464d8b     PUSH       EDI
//         00464d8c     PUSH       EAX
//         00464d8d     PUSH       EDX
//         00464d8e     CALL       dword ptr [ESI + 0xc]
//                              Panel.cpp:1120 (5)
//         00464d91     POP        EDI
//         00464d92     POP        ESI
//         00464d93     RET        0x10
//         00464d96     ??         90h
//         00464d97     NOP
//         00464d98     NOP
//         00464d99     NOP
//         00464d9a     NOP
//         00464d9b     NOP
//         00464d9c     NOP
//         00464d9d     NOP
//         00464d9e     NOP
//         00464d9f     NOP
    return;
}

void TPanel::set_color(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_color(TPanel * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00464da0(R)
//                               ?set_color@TPanel@@UAEXE@Z                                   XREF[73]:    0056f518(*), 0056f620(*),
//                               TPanel::set_color                                                         0056f760(*), 0056f8a8(*),
//                                                                                                         0056f9d8(*), 0056fb08(*),
//                                                                                                         0056fc40(*), 0056fd70(*),
//                                                                                                         0056fea0(*), 0056ffd0(*),
//                                                                                                         00570100(*), 00570c48(*),
//                                                                                                         00570d28(*), 00570fd8(*),
//                                                                                                         005710c0(*), 005711f0(*),
//                                                                                                         005712d0(*), 005713b8(*),
//                                                                                                         00571498(*), 00571588(*), [more]
//                              Panel.cpp:1126 (10)
//         00464da0     MOV        AL,byte ptr [ESP + param_1]
//         00464da4     MOV        byte ptr [ECX + this->color],AL
//                              Panel.cpp:1128 (7)
//         00464daa     MOV        EAX,dword ptr [ECX + this->active]
//         00464dad     TEST       EAX,EAX
//         00464daf     JZ         LAB_00464db8
//                              Panel.cpp:1129 (7)
//         00464db1     MOV        EDX,dword ptr [this->_padding_]
//         00464db3     PUSH       0x2
//         00464db5     CALL       dword ptr [EDX + 0x20]
//                               LAB_00464db8                                                 XREF[1]:     00464daf(j)
//                              Panel.cpp:1130 (3)
//         00464db8     RET        0x4
//         00464dbb     ??         90h
//         00464dbc     NOP
//         00464dbd     NOP
//         00464dbe     NOP
//         00464dbf     NOP
    return;
}

void TPanel::set_active(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_active(TPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00464dc0(R)
//                               ?set_active@TPanel@@UAEXH@Z                                  XREF[71]:    set_active:00475b28(c),
//                               TPanel::set_active                                                        TMessagePanel:00479012(c),
//                                                                                                         set_active:0047ce28(c),
//                                                                                                         0056f51c(*), 0056f624(*),
//                                                                                                         0056f764(*), 0056f8ac(*),
//                                                                                                         0056f9dc(*), 0056fb0c(*),
//                                                                                                         0056fc44(*), 0056fd74(*),
//                                                                                                         0056fea4(*), 0056ffd4(*),
//                                                                                                         00570104(*), 00570c4c(*),
//                                                                                                         00570d2c(*), 00570fdc(*),
//                                                                                                         005710c4(*), 005711f4(*),
//                                                                                                         005712d4(*), [more]
//                              Panel.cpp:1136 (12)
//         00464dc0     MOV        EAX,dword ptr [ESP + param_1]
//         00464dc4     PUSH       ESI
//         00464dc5     MOV        ESI,this
//         00464dc7     CMP        dword ptr [ESI + 0x6c],EAX
//         00464dca     JZ         LAB_00464df5
//                              Panel.cpp:1141 (7)
//         00464dcc     TEST       EAX,EAX
//         00464dce     MOV        dword ptr [ESI + 0x6c],EAX
//         00464dd1     JZ         LAB_00464de0
//                              Panel.cpp:1142 (9)
//         00464dd3     MOV        EAX,dword ptr [ESI]
//         00464dd5     PUSH       0x1
//         00464dd7     MOV        this,ESI
//         00464dd9     CALL       dword ptr [EAX + 0x20]
//                              Panel.cpp:1150 (4)
//         00464ddc     POP        ESI
//         00464ddd     RET        0x4
//                               LAB_00464de0                                                 XREF[1]:     00464dd1(j)
//                              Panel.cpp:1145 (7)
//         00464de0     MOV        this,ESI
//         00464de2     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              Panel.cpp:1147 (7)
//         00464de7     MOV        this,dword ptr [ESI + 0x40]
//         00464dea     TEST       this,this
//         00464dec     JZ         LAB_00464df5
//                              Panel.cpp:1148 (7)
//         00464dee     MOV        EDX,dword ptr [this->_padding_]
//         00464df0     PUSH       0x1
//         00464df2     CALL       dword ptr [EDX + 0x20]
//                               LAB_00464df5                                                 XREF[2]:     00464dca(j), 00464dec(j)
//                              Panel.cpp:1150 (4)
//         00464df5     POP        ESI
//         00464df6     RET        0x4
//         00464df9     ??         90h
//         00464dfa     NOP
//         00464dfb     NOP
//         00464dfc     NOP
//         00464dfd     NOP
//         00464dfe     NOP
//         00464dff     NOP
    return;
}

void TPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    /* TODO: Stub */
//                              void __thiscall set_positioning(TPanel * this, PositionMode param_1,
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              PositionMode      Stack[0x4]:4   param_1                   XREF[1]:     00464e00(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00464e0b(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00464e07(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00464e13(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00464e31(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00464e3b(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     00464e1d(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     00464e4e(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     00464e58(R)
//              TPanel *          Stack[0x28]:4  param_10                  XREF[1]:     00464e27(R)
//              TPanel *          Stack[0x2c]:4  param_11                  XREF[1]:     00464e68(R)
//              TPanel *          Stack[0x30]:4  param_12                  XREF[1]:     00464e72(R)
//              TPanel *          Stack[0x34]:4  param_13                  XREF[1]:     00464e44(R)
//                               ?set_positioning@TPanel@@UAEXW4PositionMode@1@JJJJJJJJPAV1@  XREF[73]:    0056f520(*), 0056f628(*),
//                               TPanel::set_positioning                                                   0056f768(*), 0056f8b0(*),
//                                                                                                         0056f9e0(*), 0056fb10(*),
//                                                                                                         0056fc48(*), 0056fd78(*),
//                                                                                                         0056fea8(*), 0056ffd8(*),
//                                                                                                         00570108(*), 00570c50(*),
//                                                                                                         00570d30(*), 00570fe0(*),
//                                                                                                         005710c8(*), 005711f8(*),
//                                                                                                         005712d8(*), 005713c0(*),
//                                                                                                         005714a0(*), 00571590(*), [more]
//                              Panel.cpp:1158 (7)
//         00464e00     MOV        EAX,dword ptr [ESP + param_1]
//         00464e04     PUSH       ESI
//         00464e05     MOV        ESI,this
//                              Panel.cpp:1162 (12)
//         00464e07     MOV        EDX,dword ptr [ESP + param_3]
//         00464e0b     MOV        this,dword ptr [ESP + param_2]
//         00464e0f     PUSH       EDI
//         00464e10     MOV        dword ptr [ESI + 0x34],EAX
//                              Panel.cpp:1163 (10)
//         00464e13     MOV        EAX,dword ptr [ESP + param_4]
//         00464e17     MOV        dword ptr [ESI + 0xa4],EAX
//                              Panel.cpp:1167 (10)
//         00464e1d     MOV        EAX,dword ptr [ESP + param_7]
//         00464e21     MOV        dword ptr [ESI + 0xb0],EAX
//                              Panel.cpp:1171 (24)
//         00464e27     MOV        EAX,dword ptr [ESP + param_10]
//         00464e2b     MOV        dword ptr [ESI + 0x9c],this
//         00464e31     MOV        this,dword ptr [ESP + param_5]
//         00464e35     MOV        dword ptr [ESI + 0xa0],EDX
//         00464e3b     MOV        EDX,dword ptr [ESP + param_6]
//                              Panel.cpp:1177 (73)
//         00464e3f     MOV        EDI,dword ptr [ESI]
//         00464e41     MOV        dword ptr [ESI + 0x44],EAX
//         00464e44     MOV        EAX,dword ptr [ESP + param_13]
//         00464e48     MOV        dword ptr [ESI + 0xa8],this
//         00464e4e     MOV        this,dword ptr [ESP + param_8]
//         00464e52     MOV        dword ptr [ESI + 0xac],EDX
//         00464e58     MOV        EDX,dword ptr [ESP + param_9]
//         00464e5c     MOV        dword ptr [ESI + 0x50],EAX
//         00464e5f     MOV        EAX,dword ptr [ESI + 0x20]
//         00464e62     MOV        dword ptr [ESI + 0xb4],this
//         00464e68     MOV        this,dword ptr [ESP + param_11]
//         00464e6c     MOV        dword ptr [ESI + 0xb8],EDX
//         00464e72     MOV        EDX,dword ptr [ESP + param_12]
//         00464e76     MOV        dword ptr [ESI + 0x48],this
//         00464e79     TEST       EAX,EAX
//         00464e7b     MOV        dword ptr [ESI + 0x4c],EDX
//         00464e7e     JZ         LAB_00464e8a
//         00464e80     MOV        this,dword ptr [EAX + 0x1c]
//         00464e83     MOV        EDX,dword ptr [EAX + 0x18]
//         00464e86     PUSH       this
//         00464e87     PUSH       EDX
//                              Panel.cpp:1178 (2)
//         00464e88     JMP        LAB_00464e8e
//                               LAB_00464e8a                                                 XREF[1]:     00464e7e(j)
//                              Panel.cpp:1179 (9)
//         00464e8a     PUSH       0x0
//         00464e8c     PUSH       0x0
//                               LAB_00464e8e                                                 XREF[1]:     00464e88(j)
//         00464e8e     MOV        this,ESI
//         00464e90     CALL       dword ptr [EDI + 0x50]
//                              Panel.cpp:1181 (7)
//         00464e93     MOV        EAX,dword ptr [ESI + 0x6c]
//         00464e96     TEST       EAX,EAX
//         00464e98     JZ         LAB_00464ea1
//                              Panel.cpp:1182 (7)
//         00464e9a     PUSH       0x2
//         00464e9c     MOV        this,ESI
//         00464e9e     CALL       dword ptr [EDI + 0x20]
//                               LAB_00464ea1                                                 XREF[1]:     00464e98(j)
//                              Panel.cpp:1183 (5)
//         00464ea1     POP        EDI
//         00464ea2     POP        ESI
//         00464ea3     RET        0x34
//         00464ea6     ??         90h
//         00464ea7     NOP
//         00464ea8     NOP
//         00464ea9     NOP
//         00464eaa     NOP
//         00464eab     NOP
//         00464eac     NOP
//         00464ead     NOP
//         00464eae     NOP
//         00464eaf     NOP
    return;
}

void TPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_fixed_position(TPanel * this, long param_1, long
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00464ecf(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00464ec6(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00464ebe(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00464eb0(R)
//                               ?set_fixed_position@TPanel@@UAEXJJJJ@Z                       XREF[73]:    0056f524(*), 0056f62c(*),
//                               TPanel::set_fixed_position                                                0056f76c(*), 0056f8b4(*),
//                                                                                                         0056f9e4(*), 0056fb14(*),
//                                                                                                         0056fc4c(*), 0056fd7c(*),
//                                                                                                         0056feac(*), 0056ffdc(*),
//                                                                                                         0057010c(*), 00570c54(*),
//                                                                                                         00570d34(*), 00570fe4(*),
//                                                                                                         005710cc(*), 005711fc(*),
//                                                                                                         005712dc(*), 005713c4(*),
//                                                                                                         005714a4(*), 00571594(*), [more]
//                              Panel.cpp:1189 (41)
//         00464eb0     MOV        EAX,dword ptr [ESP + param_4]
//         00464eb4     PUSH       0x0
//         00464eb6     PUSH       0x0
//         00464eb8     PUSH       0x0
//         00464eba     PUSH       0x0
//         00464ebc     PUSH       EAX
//         00464ebd     PUSH       EAX
//         00464ebe     MOV        EAX,dword ptr [ESP + param_3]
//         00464ec2     MOV        EDX,dword ptr [this->_padding_]
//         00464ec4     PUSH       EAX
//         00464ec5     PUSH       EAX
//         00464ec6     MOV        EAX,dword ptr [ESP + param_2]
//         00464eca     PUSH       0x0
//         00464ecc     PUSH       0x0
//         00464ece     PUSH       EAX
//         00464ecf     MOV        EAX,dword ptr [ESP + param_1]
//         00464ed3     PUSH       EAX
//         00464ed4     PUSH       0x0
//         00464ed6     CALL       dword ptr [EDX + 0x18]
//                              Panel.cpp:1192 (3)
//         00464ed9     RET        0x10
//         00464edc     ??         90h
//         00464edd     NOP
//         00464ede     NOP
//         00464edf     NOP
    return;
}

void TPanel::set_redraw(RedrawMode param_1) {
    /* TODO: Stub */
//                              void __thiscall set_redraw(TPanel * this, RedrawMode param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              RedrawMode        Stack[0x4]:4   param_1                   XREF[1]:     00464ee0(R)
//                               ?set_redraw@TPanel@@UAEXW4RedrawMode@1@@Z                    XREF[69]:    set_redraw:00437099(c),
//                               TPanel::set_redraw                                                        set_redraw:00475dd5(c),
//                                                                                                         set_redraw:004959a5(c),
//                                                                                                         set_redraw:00534429(c),
//                                                                                                         0056f630(*), 0056f770(*),
//                                                                                                         0056f8b8(*), 0056f9e8(*),
//                                                                                                         0056fb18(*), 0056fc50(*),
//                                                                                                         0056fd80(*), 0056feb0(*),
//                                                                                                         0056ffe0(*), 00570110(*),
//                                                                                                         00570c58(*), 00570d38(*),
//                                                                                                         00570fe8(*), 005710d0(*),
//                                                                                                         00571200(*), 005712e0(*), [more]
//                              Panel.cpp:1198 (15)
//         00464ee0     MOV        EAX,dword ptr [ESP + param_1]
//         00464ee4     CMP        EAX,0x1
//         00464ee7     JNZ        LAB_00464eef
//         00464ee9     CMP        dword ptr [ECX + this->need_redraw],0x2
//         00464eed     JZ         LAB_00464f1b
//                               LAB_00464eef                                                 XREF[1]:     00464ee7(j)
//                              Panel.cpp:1204 (28)
//         00464eef     TEST       EAX,EAX
//         00464ef1     MOV        dword ptr [ECX + this->need_redraw],EAX
//         00464ef4     JZ         LAB_00464f1b
//         00464ef6     MOV        EAX,dword ptr [ECX + this->render_area]
//         00464ef9     TEST       EAX,EAX
//         00464efb     JZ         LAB_00464f1b
//         00464efd     MOV        EDX,dword ptr [ECX + this->visible]
//         00464f00     TEST       EDX,EDX
//         00464f02     JZ         LAB_00464f1b
//         00464f04     MOV        EDX,dword ptr [ECX + this->active]
//         00464f07     TEST       EDX,EDX
//         00464f09     JZ         LAB_00464f1b
//                              Panel.cpp:1205 (16)
//         00464f0b     MOV        EAX,dword ptr [EAX + 0x4]
//         00464f0e     ADD        this,0x24
//         00464f11     PUSH       0x0
//         00464f13     PUSH       this
//         00464f14     PUSH       EAX
//         00464f15     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
//                               LAB_00464f1b                                                 XREF[5]:     00464eed(j), 00464ef4(j),
//                                                                                                         00464efb(j), 00464f02(j),
//                                                                                                         00464f09(j)
//                              Panel.cpp:1206 (3)
//         00464f1b     RET        0x4
//         00464f1e     ??         90h
//         00464f1f     NOP
    return;
}

void TPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {
    /* TODO: Stub */
//                              void __thiscall set_overlapped_redraw(TPanel * this, TPanel * param_
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00464f23(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00464f68(R)
//              RedrawMode        Stack[0xc]:4   param_3                   XREF[2]:     00464fd2(R), 00465020(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     00464f49(W), 00464fb4(R), 00464fc0(R), 00464fcc(R),
//                                                                                     0046500a(R), 0046501a(R)
//              tagRECT           Stack[-0x14]   this_rect                 XREF[4,7]:   00464f34(W), 00464f5a(R), 0046502a(R), 00465033(W),
//                                                                                     00464f3b(W), 00464fae(R), 00464fba(R), 00464fc6(R),
//                                                                                     00464ffe(R), 00464f42(W), 00464fe2(R)
//              PanelNode *       Stack[-0x18]:4 temp_node
//                               ?set_overlapped_redraw@TPanel@@UAEXPAV1@0W4RedrawMode@1@@Z   XREF[72]:    0056f52c(*), 0056f634(*),
//                               TPanel::set_overlapped_redraw                                             0056f774(*), 0056f8bc(*),
//                                                                                                         0056f9ec(*), 0056fb1c(*),
//                                                                                                         0056fc54(*), 0056fd84(*),
//                                                                                                         0056feb4(*), 0056ffe4(*),
//                                                                                                         00570114(*), 00570c5c(*),
//                                                                                                         00570d3c(*), 00570fec(*),
//                                                                                                         005710d4(*), 00571204(*),
//                                                                                                         005712e4(*), 005713cc(*),
//                                                                                                         005714ac(*), 0057159c(*), [more]
//                              Panel.cpp:1216 (3)
//         00464f20     SUB        ESP,0x14
//                              Panel.cpp:1220 (5)
//         00464f23     MOV        EAX,dword ptr [ESP + param_1]
//         00464f27     PUSH       EBX
//                              Panel.cpp:1224 (43)
//         00464f28     MOV        this,dword ptr [ECX + this->first_child_node]
//         00464f2b     PUSH       EBP
//         00464f2c     LEA        EDX,[EAX + 0x24]
//         00464f2f     PUSH       ESI
//         00464f30     TEST       this,this
//         00464f32     MOV        EBX,dword ptr [EDX]
//         00464f34     MOV        dword ptr [ESP + this_rect.left],this
//         00464f38     MOV        ESI,dword ptr [EDX + 0x4]
//         00464f3b     MOV        dword ptr [ESP + this_rect.right],ESI
//         00464f3f     MOV        EBP,dword ptr [EDX + 0x8]
//         00464f42     MOV        dword ptr [ESP + this_rect.bottom],EBP
//         00464f46     MOV        EDX,dword ptr [EDX + 0xc]
//         00464f49     MOV        dword ptr [ESP + local_4],EDX
//         00464f4d     JZ         LAB_0046503e
//                              Panel.cpp:1216 (1)
//         00464f53     PUSH       EDI
//                              Panel.cpp:1224 (6)
//         00464f54     JMP        LAB_00464f5a
//                               LAB_00464f56                                                 XREF[1]:     00465037(j)
//         00464f56     MOV        EAX,dword ptr [ESP + 0x28]
//                               LAB_00464f5a                                                 XREF[1]:     00464f54(j)
//                              Panel.cpp:1227 (24)
//         00464f5a     MOV        this,dword ptr [ESP + this_rect.left]
//         00464f5e     MOV        this,dword ptr [this->_padding_]
//         00464f60     CMP        this,EAX
//         00464f62     JZ         LAB_0046502a
//         00464f68     CMP        this,dword ptr [ESP + param_2]
//         00464f6c     JZ         LAB_0046502a
//                              Panel.cpp:1230 (20)
//         00464f72     MOV        EDX,dword ptr [ECX + this->z_order]
//         00464f78     MOV        ESI,dword ptr [EAX + 0xdc]
//         00464f7e     CMP        EDX,ESI
//         00464f80     JLE        LAB_0046502a
//                              Panel.cpp:1232 (7)
//         00464f86     LEA        EAX,[ECX + this->clip_rect.left]
//         00464f89     MOV        EDI,EAX
//         00464f8b     MOV        EAX,dword ptr [EDI]
//                              Panel.cpp:1240 (69)
//         00464f8d     CMP        EAX,EBX
//         00464f8f     MOV        ESI,dword ptr [EDI + 0x4]
//         00464f92     MOV        EDX,dword ptr [EDI + 0x8]
//         00464f95     MOV        EDI,dword ptr [EDI + 0xc]
//         00464f98     JL         LAB_00464f9e
//         00464f9a     CMP        EAX,EBP
//         00464f9c     JLE        LAB_00464fae
//                               LAB_00464f9e                                                 XREF[1]:     00464f98(j)
//         00464f9e     CMP        EDX,EBX
//         00464fa0     JL         LAB_00464fa6
//         00464fa2     CMP        EDX,EBP
//         00464fa4     JLE        LAB_00464fae
//                               LAB_00464fa6                                                 XREF[1]:     00464fa0(j)
//         00464fa6     CMP        EBX,EAX
//         00464fa8     JLE        LAB_00464fe8
//         00464faa     CMP        EDX,EBP
//         00464fac     JLE        LAB_00464fe6
//                               LAB_00464fae                                                 XREF[2]:     00464f9c(j), 00464fa4(j)
//         00464fae     CMP        ESI,dword ptr [ESP + this_rect.right]
//         00464fb2     JL         LAB_00464fba
//         00464fb4     CMP        ESI,dword ptr [ESP + local_4]
//         00464fb8     JLE        LAB_00464fd2
//                               LAB_00464fba                                                 XREF[1]:     00464fb2(j)
//         00464fba     CMP        EDI,dword ptr [ESP + this_rect.right]
//         00464fbe     JL         LAB_00464fc6
//         00464fc0     CMP        EDI,dword ptr [ESP + local_4]
//         00464fc4     JLE        LAB_00464fd2
//                               LAB_00464fc6                                                 XREF[1]:     00464fbe(j)
//         00464fc6     CMP        ESI,dword ptr [ESP + this_rect.right]
//         00464fca     JGE        LAB_00464fe2
//         00464fcc     CMP        EDI,dword ptr [ESP + local_4]
//         00464fd0     JLE        LAB_00464fe2
//                               LAB_00464fd2                                                 XREF[2]:     00464fb8(j), 00464fc4(j)
//                              Panel.cpp:1241 (10)
//         00464fd2     MOV        EAX,dword ptr [ESP + param_3]
//         00464fd6     MOV        EDX,dword ptr [this->_padding_]
//         00464fd8     PUSH       EAX
//         00464fd9     CALL       dword ptr [EDX + 0x20]
//                              Panel.cpp:1242 (10)
//         00464fdc     MOV        EBP,dword ptr [ESP + 0x1c]
//         00464fe0     JMP        LAB_0046502a
//                               LAB_00464fe2                                                 XREF[2]:     00464fca(j), 00464fd0(j)
//         00464fe2     MOV        EBP,dword ptr [ESP + this_rect.bottom]
//                               LAB_00464fe6                                                 XREF[1]:     00464fac(j)
//                              Panel.cpp:1247 (58)
//         00464fe6     CMP        EBX,EAX
//                               LAB_00464fe8                                                 XREF[1]:     00464fa8(j)
//         00464fe8     JL         LAB_00464fee
//         00464fea     CMP        EBX,EDX
//         00464fec     JLE        LAB_00464ffe
//                               LAB_00464fee                                                 XREF[1]:     00464fe8(j)
//         00464fee     CMP        EBP,EAX
//         00464ff0     JL         LAB_00464ff6
//         00464ff2     CMP        EBP,EDX
//         00464ff4     JLE        LAB_00464ffe
//                               LAB_00464ff6                                                 XREF[1]:     00464ff0(j)
//         00464ff6     CMP        EBX,EAX
//         00464ff8     JGE        LAB_0046502a
//         00464ffa     CMP        EBP,EDX
//         00464ffc     JLE        LAB_0046502a
//                               LAB_00464ffe                                                 XREF[2]:     00464fec(j), 00464ff4(j)
//         00464ffe     MOV        EAX,dword ptr [ESP + this_rect.right]
//         00465002     CMP        EAX,ESI
//         00465004     JL         LAB_0046500a
//         00465006     CMP        EAX,EDI
//         00465008     JLE        LAB_00465020
//                               LAB_0046500a                                                 XREF[1]:     00465004(j)
//         0046500a     MOV        EDX,dword ptr [ESP + local_4]
//         0046500e     CMP        EDX,ESI
//         00465010     JL         LAB_00465016
//         00465012     CMP        EDX,EDI
//         00465014     JLE        LAB_00465020
//                               LAB_00465016                                                 XREF[1]:     00465010(j)
//         00465016     CMP        EAX,ESI
//         00465018     JGE        LAB_0046502a
//         0046501a     CMP        dword ptr [ESP + local_4],EDI
//         0046501e     JLE        LAB_0046502a
//                               LAB_00465020                                                 XREF[2]:     00465008(j), 00465014(j)
//                              Panel.cpp:1248 (29)
//         00465020     MOV        EAX,dword ptr [ESP + param_3]
//         00465024     MOV        EDX,dword ptr [this->_padding_]
//         00465026     PUSH       EAX
//         00465027     CALL       dword ptr [EDX + 0x20]
//                               LAB_0046502a                                                 XREF[8]:     00464f62(j), 00464f6c(j),
//                                                                                                         00464f80(j), 00464fe0(j),
//                                                                                                         00464ff8(j), 00464ffc(j),
//                                                                                                         00465018(j), 0046501e(j)
//         0046502a     MOV        this,dword ptr [ESP + this_rect.left]
//         0046502e     MOV        EAX,dword ptr [ECX + this->previousModalPanelV
//         00465031     TEST       EAX,EAX
//         00465033     MOV        dword ptr [ESP + this_rect.left],EAX
//         00465037     JNZ        LAB_00464f56
//                              Panel.cpp:1216 (1)
//         0046503d     POP        EDI
//                               LAB_0046503e                                                 XREF[1]:     00464f4d(j)
//                              Panel.cpp:1256 (9)
//         0046503e     POP        ESI
//         0046503f     POP        EBP
//         00465040     POP        EBX
//         00465041     ADD        ESP,0x14
//         00465044     RET        0xc
//         00465047     ??         90h
//         00465048     NOP
//         00465049     NOP
//         0046504a     NOP
//         0046504b     NOP
//         0046504c     NOP
//         0046504d     NOP
//         0046504e     NOP
//         0046504f     NOP
    return;
}

void TPanel::set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2) {
    /* TODO: Stub */
//                              void __thiscall set_any_overlapping_redraw(TPanel * this, TPanel * p
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[2]:     00465053(R), 00465088(R)
//              RedrawMode        Stack[0x8]:4   param_2                   XREF[1]:     004650e2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00465078(W), 004650c4(R), 004650d0(R), 004650dc(R)
//              tagRECT           Stack[-0x14]   this_rect                 XREF[2,6]:   0046505f(W), 00465084(R), 0046506a(W), 004650be(R),
//                                                                                     004650ca(R), 004650d6(R), 0046510e(R), 00465071(W)
//              PanelNode *       Stack[-0x18]:4 temp_node
//                               ?set_any_overlapping_redraw@TPanel@@QAEXPAV1@W4RedrawMode@1
//                               TPanel::set_any_overlapping_redraw
//                              Panel.cpp:1264 (3)
//         00465050     SUB        ESP,0x14
//                              Panel.cpp:1268 (8)
//         00465053     MOV        EAX,dword ptr [ESP + param_1]
//         00465057     PUSH       EBX
//         00465058     ADD        EAX,0x24
//                              Panel.cpp:1270 (41)
//         0046505b     MOV        this,dword ptr [ECX + this->first_child_node]
//         0046505e     PUSH       EBP
//         0046505f     MOV        dword ptr [ESP + this_rect.left],this
//         00465063     MOV        EBX,dword ptr [EAX]
//         00465065     TEST       this,this
//         00465067     MOV        EDX,dword ptr [EAX + 0x4]
//         0046506a     MOV        dword ptr [ESP + this_rect.right],EDX
//         0046506e     MOV        EBP,dword ptr [EAX + 0x8]
//         00465071     MOV        dword ptr [ESP + this_rect.bottom],EBP
//         00465075     MOV        EAX,dword ptr [EAX + 0xc]
//         00465078     MOV        dword ptr [ESP + local_4],EAX
//         0046507c     JZ         LAB_0046514f
//         00465082     PUSH       EDI
//         00465083     PUSH       ESI
//                               LAB_00465084                                                 XREF[1]:     00465147(j)
//                              Panel.cpp:1273 (18)
//         00465084     MOV        this,dword ptr [ESP + this_rect.left]
//         00465088     MOV        EAX,dword ptr [ESP + param_1]
//         0046508c     MOV        this,dword ptr [this->_padding_]
//         0046508e     CMP        this,EAX
//         00465090     JZ         LAB_0046513a
//                              Panel.cpp:1276 (7)
//         00465096     LEA        EDX,[ECX + this->clip_rect.left]
//         00465099     MOV        EDI,EDX
//         0046509b     MOV        EAX,dword ptr [EDI]
//                              Panel.cpp:1284 (69)
//         0046509d     CMP        EAX,EBX
//         0046509f     MOV        ESI,dword ptr [EDI + 0x4]
//         004650a2     MOV        EDX,dword ptr [EDI + 0x8]
//         004650a5     MOV        EDI,dword ptr [EDI + 0xc]
//         004650a8     JL         LAB_004650ae
//         004650aa     CMP        EAX,EBP
//         004650ac     JLE        LAB_004650be
//                               LAB_004650ae                                                 XREF[1]:     004650a8(j)
//         004650ae     CMP        EDX,EBX
//         004650b0     JL         LAB_004650b6
//         004650b2     CMP        EDX,EBP
//         004650b4     JLE        LAB_004650be
//                               LAB_004650b6                                                 XREF[1]:     004650b0(j)
//         004650b6     CMP        EBX,EAX
//         004650b8     JLE        LAB_004650f8
//         004650ba     CMP        EDX,EBP
//         004650bc     JLE        LAB_004650f6
//                               LAB_004650be                                                 XREF[2]:     004650ac(j), 004650b4(j)
//         004650be     CMP        ESI,dword ptr [ESP + this_rect.right]
//         004650c2     JL         LAB_004650ca
//         004650c4     CMP        ESI,dword ptr [ESP + local_4]
//         004650c8     JLE        LAB_004650e2
//                               LAB_004650ca                                                 XREF[1]:     004650c2(j)
//         004650ca     CMP        EDI,dword ptr [ESP + this_rect.right]
//         004650ce     JL         LAB_004650d6
//         004650d0     CMP        EDI,dword ptr [ESP + local_4]
//         004650d4     JLE        LAB_004650e2
//                               LAB_004650d6                                                 XREF[1]:     004650ce(j)
//         004650d6     CMP        ESI,dword ptr [ESP + this_rect.right]
//         004650da     JGE        LAB_004650f2
//         004650dc     CMP        EDI,dword ptr [ESP + local_4]
//         004650e0     JLE        LAB_004650f2
//                               LAB_004650e2                                                 XREF[2]:     004650c8(j), 004650d4(j)
//                              Panel.cpp:1285 (10)
//         004650e2     MOV        EDX,dword ptr [ESP + param_2]
//         004650e6     MOV        EAX,dword ptr [this->_padding_]
//         004650e8     PUSH       EDX
//         004650e9     CALL       dword ptr [EAX + 0x20]
//                              Panel.cpp:1286 (10)
//         004650ec     MOV        EBP,dword ptr [ESP + 0x1c]
//         004650f0     JMP        LAB_0046513a
//                               LAB_004650f2                                                 XREF[2]:     004650da(j), 004650e0(j)
//         004650f2     MOV        EBP,dword ptr [ESP + 0x1c]
//                               LAB_004650f6                                                 XREF[1]:     004650bc(j)
//                              Panel.cpp:1291 (58)
//         004650f6     CMP        EBX,EAX
//                               LAB_004650f8                                                 XREF[1]:     004650b8(j)
//         004650f8     JL         LAB_004650fe
//         004650fa     CMP        EBX,EDX
//         004650fc     JLE        LAB_0046510e
//                               LAB_004650fe                                                 XREF[1]:     004650f8(j)
//         004650fe     CMP        EBP,EAX
//         00465100     JL         LAB_00465106
//         00465102     CMP        EBP,EDX
//         00465104     JLE        LAB_0046510e
//                               LAB_00465106                                                 XREF[1]:     00465100(j)
//         00465106     CMP        EBX,EAX
//         00465108     JGE        LAB_0046513a
//         0046510a     CMP        EBP,EDX
//         0046510c     JLE        LAB_0046513a
//                               LAB_0046510e                                                 XREF[2]:     004650fc(j), 00465104(j)
//         0046510e     MOV        EAX,dword ptr [ESP + this_rect.right]
//         00465112     CMP        EAX,ESI
//         00465114     JL         LAB_0046511a
//         00465116     CMP        EAX,EDI
//         00465118     JLE        LAB_00465130
//                               LAB_0046511a                                                 XREF[1]:     00465114(j)
//         0046511a     MOV        EDX,dword ptr [ESP + 0x20]
//         0046511e     CMP        EDX,ESI
//         00465120     JL         LAB_00465126
//         00465122     CMP        EDX,EDI
//         00465124     JLE        LAB_00465130
//                               LAB_00465126                                                 XREF[1]:     00465120(j)
//         00465126     CMP        EAX,ESI
//         00465128     JGE        LAB_0046513a
//         0046512a     CMP        dword ptr [ESP + 0x20],EDI
//         0046512e     JLE        LAB_0046513a
//                               LAB_00465130                                                 XREF[2]:     00465118(j), 00465124(j)
//                              Panel.cpp:1292 (31)
//         00465130     MOV        EDX,dword ptr [ESP + 0x2c]
//         00465134     MOV        EAX,dword ptr [this->_padding_]
//         00465136     PUSH       EDX
//         00465137     CALL       dword ptr [EAX + 0x20]
//                               LAB_0046513a                                                 XREF[6]:     00465090(j), 004650f0(j),
//                                                                                                         00465108(j), 0046510c(j),
//                                                                                                         00465128(j), 0046512e(j)
//         0046513a     MOV        EAX,dword ptr [ESP + 0x10]
//         0046513e     MOV        EAX,dword ptr [EAX + 0x8]
//         00465141     TEST       EAX,EAX
//         00465143     MOV        dword ptr [ESP + 0x10],EAX
//         00465147     JNZ        LAB_00465084
//         0046514d     POP        ESI
//         0046514e     POP        EDI
//                               LAB_0046514f                                                 XREF[1]:     0046507c(j)
//                              Panel.cpp:1294 (8)
//         0046514f     POP        EBP
//         00465150     POP        EBX
//         00465151     ADD        ESP,0x14
//         00465154     RET        0x8
//         00465157     ??         90h
//         00465158     NOP
//         00465159     NOP
//         0046515a     NOP
//         0046515b     NOP
//         0046515c     NOP
//         0046515d     NOP
//         0046515e     NOP
//         0046515f     NOP
    return;
}

void TPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?draw@TPanel@@UAEXXZ                                         XREF[3]:     draw:00474340(j),
//                               TPanel::draw                                                              draw:0051fa33(c), 00570c68(*)
//                              Panel.cpp:1300 (2)
//         00465160     MOV        EAX,this
//                              Panel.cpp:1303 (28)
//         00465162     MOV        EDX,dword ptr [EAX + 0x20]
//         00465165     MOV        dword ptr [EAX + 0x38],0x0
//         0046516c     TEST       EDX,EDX
//         0046516e     JZ         LAB_004651bf
//         00465170     MOV        this,dword ptr [EAX + 0x70]
//         00465173     TEST       this,this
//         00465175     JZ         LAB_004651bf
//         00465177     MOV        this,dword ptr [EAX + 0x6c]
//         0046517a     TEST       this,this
//         0046517c     JZ         LAB_004651bf
//                              Panel.cpp:1306 (8)
//         0046517e     MOV        this,byte ptr [EAX + 0xf0]
//         00465184     TEST       this,this
//                              Panel.cpp:1308 (2)
//         00465186     JNZ        LAB_004651ab
//                              Panel.cpp:1310 (7)
//         00465188     MOV        this,dword ptr [EAX + 0x40]
//         0046518b     TEST       this,this
//         0046518d     JZ         LAB_004651ab
//                              Panel.cpp:1312 (8)
//         0046518f     MOV        DL,byte ptr [EAX + 0xf2]
//         00465195     TEST       DL,DL
//                              Panel.cpp:1313 (11)
//         00465197     MOV        EDX,dword ptr [this->_padding_]
//         00465199     JZ         LAB_004651a3
//         0046519b     ADD        EAX,0x24
//         0046519e     PUSH       EAX
//         0046519f     CALL       dword ptr [EDX + 0x3c]
//                              Panel.cpp:1320 (1)
//         004651a2     RET
//                               LAB_004651a3                                                 XREF[1]:     00465199(j)
//                              Panel.cpp:1315 (7)
//         004651a3     ADD        EAX,0x24
//         004651a6     PUSH       EAX
//         004651a7     CALL       dword ptr [EDX + 0x34]
//                              Panel.cpp:1320 (1)
//         004651aa     RET
//                               LAB_004651ab                                                 XREF[2]:     00465186(j), 0046518d(j)
//                              Panel.cpp:1318 (20)
//         004651ab     XOR        this,this
//         004651ad     MOV        this,byte ptr [EAX + 0xef]
//         004651b3     ADD        EAX,0x24
//         004651b6     PUSH       this
//         004651b7     PUSH       EAX
//         004651b8     MOV        this,EDX
//         004651ba     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                               LAB_004651bf                                                 XREF[3]:     0046516e(j), 00465175(j),
//                                                                                                         0046517c(j)
//                              Panel.cpp:1320 (1)
//         004651bf     RET
    return;
}

void TPanel::draw_rect(tagRECT* param_1) {
    /* TODO: Stub */
//                              void __thiscall draw_rect(TPanel * this, tagRECT * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     004651d8(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004651e1(W)
//              tagRECT           Stack[-0x14]   save_rect                 XREF[0,1]:   004651d4(W)
//                               ?draw_rect@TPanel@@UAEXPAUtagRECT@@@Z                        XREF[73]:    0056f53c(*), 0056f644(*),
//                               TPanel::draw_rect                                                         0056f784(*), 0056f8cc(*),
//                                                                                                         0056f9fc(*), 0056fb2c(*),
//                                                                                                         0056fc64(*), 0056fd94(*),
//                                                                                                         0056fec4(*), 0056fff4(*),
//                                                                                                         00570124(*), 00570c6c(*),
//                                                                                                         00570d4c(*), 00570ffc(*),
//                                                                                                         005710e4(*), 00571214(*),
//                                                                                                         005712f4(*), 005713dc(*),
//                                                                                                         005714bc(*), 005715ac(*), [more]
//                              Panel.cpp:1326 (6)
//         004651c0     SUB        ESP,0x10
//         004651c3     PUSH       EBX
//         004651c4     PUSH       EBP
//         004651c5     PUSH       ESI
//                              Panel.cpp:1329 (18)
//         004651c6     LEA        ESI,[ECX + this->clip_rect.left]
//         004651c9     MOV        EAX,ESI
//         004651cb     PUSH       EDI
//         004651cc     MOV        EDI,dword ptr [EAX]
//         004651ce     MOV        EBX,dword ptr [EAX + 0x4]
//         004651d1     MOV        EDX,dword ptr [EAX + 0x8]
//         004651d4     MOV        dword ptr [ESP + save_rect.bottom],EDX
//                              Panel.cpp:1330 (35)
//         004651d8     MOV        EDX,dword ptr [ESP + param_1]
//         004651dc     MOV        EAX,dword ptr [EAX + 0xc]
//         004651df     MOV        EBP,dword ptr [EDX]
//         004651e1     MOV        dword ptr [ESP + local_4],EAX
//         004651e5     MOV        EAX,ESI
//         004651e7     MOV        dword ptr [EAX],EBP
//         004651e9     MOV        EBP,dword ptr [EDX + 0x4]
//         004651ec     MOV        dword ptr [EAX + 0x4],EBP
//         004651ef     MOV        EBP,dword ptr [EDX + 0x8]
//         004651f2     MOV        dword ptr [EAX + 0x8],EBP
//         004651f5     MOV        EDX,dword ptr [EDX + 0xc]
//         004651f8     MOV        dword ptr [EAX + 0xc],EDX
//                              Panel.cpp:1331 (5)
//         004651fb     MOV        EAX,dword ptr [this->_padding_]
//         004651fd     CALL       dword ptr [EAX + 0x30]
//                              Panel.cpp:1332 (19)
//         00465200     MOV        this,dword ptr [ESP + 0x18]
//         00465204     MOV        EDX,dword ptr [ESP + 0x1c]
//         00465208     MOV        dword ptr [ESI],EDI
//         0046520a     MOV        dword ptr [ESI + 0x4],EBX
//         0046520d     MOV        dword ptr [ESI + 0x8],this
//         00465210     MOV        dword ptr [ESI + 0xc],EDX
//                              Panel.cpp:1333 (10)
//         00465213     POP        EDI
//         00465214     POP        ESI
//         00465215     POP        EBP
//         00465216     POP        EBX
//         00465217     ADD        ESP,0x10
//         0046521a     RET        0x4
//         0046521d     ??         90h
//         0046521e     NOP
//         0046521f     NOP
    return;
}

void TPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {
    /* TODO: Stub */
//                              void __thiscall draw_offset(TPanel * this, long param_1, long param_
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00465224(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0046522d(R)
//              tagRECT *         Stack[0xc]:4   param_3                   XREF[1]:     0046525f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00465263(W)
//              tagRECT           Stack[-0x14]   save_rect                 XREF[0,3]:   00465248(W), 0046524f(W), 00465256(W)
//                               ?draw_offset@TPanel@@UAEXJJPAUtagRECT@@@Z                    XREF[73]:    0056f540(*), 0056f648(*),
//                               TPanel::draw_offset                                                       0056f788(*), 0056f8d0(*),
//                                                                                                         0056fa00(*), 0056fb30(*),
//                                                                                                         0056fc68(*), 0056fd98(*),
//                                                                                                         0056fec8(*), 0056fff8(*),
//                                                                                                         00570128(*), 00570c70(*),
//                                                                                                         00570d50(*), 00571000(*),
//                                                                                                         005710e8(*), 00571218(*),
//                                                                                                         005712f8(*), 005713e0(*),
//                                                                                                         005714c0(*), 005715b0(*), [more]
//                              Panel.cpp:1339 (4)
//         00465220     SUB        ESP,0x10
//         00465223     PUSH       EBX
//                              Panel.cpp:1342 (9)
//         00465224     MOV        EBX,dword ptr [ESP + param_1]
//         00465228     PUSH       EBP
//         00465229     PUSH       ESI
//         0046522a     MOV        ESI,this
//         0046522c     PUSH       EDI
//                              Panel.cpp:1343 (17)
//         0046522d     MOV        EBP,dword ptr [ESP + param_2]
//         00465231     MOV        EDI,dword ptr [ESI + 0xc]
//         00465234     MOV        EDX,dword ptr [ESI + 0x10]
//         00465237     ADD        EDI,EBX
//         00465239     ADD        EDX,EBP
//         0046523b     MOV        dword ptr [ESI + 0xc],EDI
//                              Panel.cpp:1345 (28)
//         0046523e     LEA        EDI,[ESI + 0x24]
//         00465241     MOV        EAX,EDI
//         00465243     MOV        dword ptr [ESI + 0x10],EDX
//         00465246     MOV        this,dword ptr [EAX]
//         00465248     MOV        dword ptr [ESP + save_rect.top],this
//         0046524c     MOV        EDX,dword ptr [EAX + 0x4]
//         0046524f     MOV        dword ptr [ESP + save_rect.right],EDX
//         00465253     MOV        this,dword ptr [EAX + 0x8]
//         00465256     MOV        dword ptr [ESP + save_rect.bottom],this
//                              Panel.cpp:1346 (29)
//         0046525a     MOV        this,EDI
//         0046525c     MOV        EDX,dword ptr [EAX + 0xc]
//         0046525f     MOV        EAX,dword ptr [ESP + param_3]
//         00465263     MOV        dword ptr [ESP + local_4],EDX
//         00465267     MOV        EDX,dword ptr [EAX]
//         00465269     MOV        dword ptr [this->_padding_],EDX
//         0046526b     MOV        EDX,dword ptr [EAX + 0x4]
//         0046526e     MOV        dword ptr [ECX + this->previousPanelValue],EDX
//         00465271     MOV        EDX,dword ptr [EAX + 0x8]
//         00465274     MOV        dword ptr [ECX + this->previousModalPanelValue
//                              Panel.cpp:1347 (13)
//         00465277     MOV        EDX,dword ptr [ESI]
//         00465279     MOV        EAX,dword ptr [EAX + 0xc]
//         0046527c     MOV        dword ptr [ECX + this->pnl_x],EAX
//         0046527f     MOV        this,ESI
//         00465281     CALL       dword ptr [EDX + 0x30]
//                              Panel.cpp:1348 (21)
//         00465284     MOV        EAX,dword ptr [ESP + 0x10]
//         00465288     MOV        this,dword ptr [ESP + 0x14]
//         0046528c     MOV        EDX,dword ptr [ESP + 0x18]
//         00465290     MOV        dword ptr [EDI],EAX
//         00465292     MOV        EAX,dword ptr [ESP + 0x1c]
//         00465296     MOV        dword ptr [EDI + 0x4],this
//                              Panel.cpp:1350 (9)
//         00465299     MOV        this,dword ptr [ESI + 0xc]
//         0046529c     MOV        dword ptr [EDI + 0x8],EDX
//         0046529f     MOV        dword ptr [EDI + 0xc],EAX
//                              Panel.cpp:1351 (13)
//         004652a2     MOV        EAX,dword ptr [ESI + 0x10]
//         004652a5     SUB        this,EBX
//         004652a7     SUB        EAX,EBP
//         004652a9     MOV        dword ptr [ESI + 0xc],this
//         004652ac     MOV        dword ptr [ESI + 0x10],EAX
//                              Panel.cpp:1352 (10)
//         004652af     POP        EDI
//         004652b0     POP        ESI
//         004652b1     POP        EBP
//         004652b2     POP        EBX
//         004652b3     ADD        ESP,0x10
//         004652b6     RET        0xc
//         004652b9     ??         90h
//         004652ba     NOP
//         004652bb     NOP
//         004652bc     NOP
//         004652bd     NOP
//         004652be     NOP
//         004652bf     NOP
    return;
}

void TPanel::draw_rect2(tagRECT* param_1) {
    /* TODO: Stub */
//                              void __thiscall draw_rect2(TPanel * this, tagRECT * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     004652c3(R)
//                               ?draw_rect2@TPanel@@UAEXPAUtagRECT@@@Z                       XREF[73]:    0056f544(*), 0056f64c(*),
//                               TPanel::draw_rect2                                                        0056f78c(*), 0056f8d4(*),
//                                                                                                         0056fa04(*), 0056fb34(*),
//                                                                                                         0056fc6c(*), 0056fd9c(*),
//                                                                                                         0056fecc(*), 0056fffc(*),
//                                                                                                         0057012c(*), 00570c74(*),
//                                                                                                         00570d54(*), 00571004(*),
//                                                                                                         005710ec(*), 0057121c(*),
//                                                                                                         005712fc(*), 005713e4(*),
//                                                                                                         005714c4(*), 005715b4(*), [more]
//                              Panel.cpp:1358 (3)
//         004652c0     PUSH       ESI
//         004652c1     MOV        ESI,this
//                              Panel.cpp:1360 (19)
//         004652c3     MOV        this,dword ptr [ESP + param_1]
//         004652c7     MOV        EAX,dword ptr [ESI]
//         004652c9     PUSH       this
//         004652ca     MOV        this,ESI
//         004652cc     MOV        byte ptr [ESI + 0xf2],0x1
//         004652d3     CALL       dword ptr [EAX + 0x34]
//                              Panel.cpp:1361 (7)
//         004652d6     MOV        byte ptr [ESI + 0xf2],0x0
//                              Panel.cpp:1362 (4)
//         004652dd     POP        ESI
//         004652de     RET        0x4
//         004652e1     ??         90h
//         004652e2     NOP
//         004652e3     NOP
//         004652e4     NOP
//         004652e5     NOP
//         004652e6     NOP
//         004652e7     NOP
//         004652e8     NOP
//         004652e9     NOP
//         004652ea     NOP
//         004652eb     NOP
//         004652ec     NOP
//         004652ed     NOP
//         004652ee     NOP
//         004652ef     NOP
    return;
}

void TPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {
    /* TODO: Stub */
//                              void __thiscall draw_offset2(TPanel * this, long param_1, long param
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004652fe(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004652f0(R)
//              tagRECT *         Stack[0xc]:4   param_3                   XREF[1]:     004652f7(R)
//                               ?draw_offset2@TPanel@@UAEXJJPAUtagRECT@@@Z                   XREF[73]:    0056f548(*), 0056f650(*),
//                               TPanel::draw_offset2                                                      0056f790(*), 0056f8d8(*),
//                                                                                                         0056fa08(*), 0056fb38(*),
//                                                                                                         0056fc70(*), 0056fda0(*),
//                                                                                                         0056fed0(*), 00570000(*),
//                                                                                                         00570130(*), 00570c78(*),
//                                                                                                         00570d58(*), 00571008(*),
//                                                                                                         005710f0(*), 00571220(*),
//                                                                                                         00571300(*), 005713e8(*),
//                                                                                                         005714c8(*), 005715b8(*), [more]
//                              Panel.cpp:1368 (32)
//         004652f0     MOV        EDX,dword ptr [ESP + param_2]
//         004652f4     PUSH       ESI
//         004652f5     MOV        ESI,this
//         004652f7     MOV        this,dword ptr [ESP + param_3]
//         004652fb     MOV        EAX,dword ptr [ESI]
//         004652fd     PUSH       this
//         004652fe     MOV        this,dword ptr [ESP + param_1]
//         00465302     PUSH       EDX
//         00465303     PUSH       this
//         00465304     MOV        this,ESI
//         00465306     MOV        byte ptr [ESI + 0xf2],0x1
//         0046530d     CALL       dword ptr [EAX + 0x38]
//                              Panel.cpp:1371 (7)
//         00465310     MOV        byte ptr [ESI + 0xf2],0x0
//                              Panel.cpp:1372 (4)
//         00465317     POP        ESI
//         00465318     RET        0xc
//         0046531b     ??         90h
//         0046531c     NOP
//         0046531d     NOP
//         0046531e     NOP
//         0046531f     NOP
    return;
}

void TPanel::draw_setup(int param_1) {
    /* TODO: Stub */
//                              void __thiscall draw_setup(TPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?draw_setup@TPanel@@UAEXH@Z                                  XREF[30]:    draw_setup:00467565(c),
//                               TPanel::draw_setup                                                        0056f530(*), 00570c60(*),
//                                                                                                         00570ff0(*), 00571208(*),
//                                                                                                         005712e8(*), 005713d0(*),
//                                                                                                         005714b0(*), 005715a0(*),
//                                                                                                         00571690(*), 00571778(*),
//                                                                                                         00571858(*), 00571a60(*),
//                                                                                                         00571b40(*), 00571c20(*),
//                                                                                                         00571f88(*), 00572068(*),
//                                                                                                         005728a0(*), 00572ad0(*),
//                                                                                                         00574468(*), [more]
//                              Panel.cpp:1385 (4)
//         00465320     PUSH       ESI
//         00465321     MOV        ESI,this
//         00465323     PUSH       EDI
//                              Panel.cpp:1388 (10)
//         00465324     MOV        EAX,dword ptr [ESI + 0x20]
//         00465327     MOV        EAX,dword ptr [EAX + 0x38]
//         0046532a     TEST       EAX,EAX
//         0046532c     JZ         LAB_0046533c
//                              Panel.cpp:1389 (14)
//         0046532e     MOV        this,dword ptr [ESI + 0x88]
//         00465334     PUSH       this
//         00465335     PUSH       EAX
//         00465336     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                               LAB_0046533c                                                 XREF[1]:     0046532c(j)
//                              Panel.cpp:1390 (12)
//         0046533c     MOV        this,dword ptr [ESI + 0x20]
//         0046533f     LEA        EDI,[ESI + 0x24]
//         00465342     PUSH       EDI
//         00465343     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              Panel.cpp:1392 (8)
//         00465348     MOV        EAX,dword ptr [ESP + 0xc]
//         0046534c     TEST       EAX,EAX
//         0046534e     JZ         LAB_00465362
//                              Panel.cpp:1393 (18)
//         00465350     MOV        this,dword ptr [ESI + 0x20]
//         00465353     XOR        EDX,EDX
//         00465355     MOV        DL,byte ptr [ESI + 0xef]
//         0046535b     PUSH       EDX
//         0046535c     PUSH       EDI
//         0046535d     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                               LAB_00465362                                                 XREF[1]:     0046534e(j)
//                              Panel.cpp:1395 (5)
//         00465362     POP        EDI
//         00465363     POP        ESI
//         00465364     RET        0x4
//         00465367     ??         90h
//         00465368     NOP
//         00465369     NOP
//         0046536a     NOP
//         0046536b     NOP
//         0046536c     NOP
//         0046536d     NOP
//         0046536e     NOP
//         0046536f     NOP
    return;
}

void TPanel::draw_finish() {
    /* TODO: Stub */
//                              void __thiscall draw_finish(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?draw_finish@TPanel@@UAEXXZ                                  XREF[73]:    0056f534(*), 0056f63c(*),
//                               TPanel::draw_finish                                                       0056f77c(*), 0056f8c4(*),
//                                                                                                         0056f9f4(*), 0056fb24(*),
//                                                                                                         0056fc5c(*), 0056fd8c(*),
//                                                                                                         0056febc(*), 0056ffec(*),
//                                                                                                         0057011c(*), 00570c64(*),
//                                                                                                         00570d44(*), 00570ff4(*),
//                                                                                                         005710dc(*), 0057120c(*),
//                                                                                                         005712ec(*), 005713d4(*),
//                                                                                                         005714b4(*), 005715a4(*), [more]
//                              Panel.cpp:1401 (3)
//         00465370     PUSH       ESI
//         00465371     MOV        ESI,this
//                              Panel.cpp:1403 (17)
//         00465373     MOV        EAX,dword ptr [ESI + 0x20]
//         00465376     MOV        dword ptr [ESI + 0x38],0x0
//         0046537d     MOV        EAX,dword ptr [EAX + 0x38]
//         00465380     TEST       EAX,EAX
//         00465382     JZ         LAB_0046538d
//                              Panel.cpp:1404 (9)
//         00465384     PUSH       0x0
//         00465386     PUSH       EAX
//         00465387     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                               LAB_0046538d                                                 XREF[1]:     00465382(j)
//                              Panel.cpp:1405 (10)
//         0046538d     MOV        this,dword ptr [ESI + 0x20]
//         00465390     PUSH       0x0
//         00465392     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              Panel.cpp:1406 (7)
//         00465397     MOV        byte ptr [ESI + 0xf3],0x0
//                              Panel.cpp:1407 (2)
//         0046539e     POP        ESI
//         0046539f     RET
    return;
}

void TPanel::paint() {
    /* TODO: Stub */
//                              void __thiscall paint(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?paint@TPanel@@UAEXXZ                                        XREF[72]:    0056f54c(*), 0056f654(*),
//                               TPanel::paint                                                             0056f794(*), 0056f8dc(*),
//                                                                                                         0056fa0c(*), 0056fb3c(*),
//                                                                                                         0056fc74(*), 0056fda4(*),
//                                                                                                         0056fed4(*), 00570004(*),
//                                                                                                         00570134(*), 00570c7c(*),
//                                                                                                         00570d5c(*), 0057100c(*),
//                                                                                                         005710f4(*), 00571224(*),
//                                                                                                         00571304(*), 005714cc(*),
//                                                                                                         005715bc(*), 005716ac(*), [more]
//                              Panel.cpp:1413 (3)
//         004653a0     PUSH       ESI
//         004653a1     MOV        ESI,this
//                              Panel.cpp:1414 (21)
//         004653a3     MOV        EAX,dword ptr [ESI + 0x20]
//         004653a6     TEST       EAX,EAX
//         004653a8     JZ         LAB_004653d3
//         004653aa     MOV        this,dword ptr [ESI + 0x70]
//         004653ad     TEST       this,this
//         004653af     JZ         LAB_004653d3
//         004653b1     MOV        this,dword ptr [ESI + 0x6c]
//         004653b4     TEST       this,this
//         004653b6     JZ         LAB_004653d3
//                              Panel.cpp:1417 (12)
//         004653b8     MOV        this,dword ptr [EAX]
//         004653ba     PUSH       EDI
//         004653bb     LEA        EDI,[ESI + 0x24]
//         004653be     PUSH       EDI
//         004653bf     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
//                              Panel.cpp:1418 (15)
//         004653c4     MOV        EAX,dword ptr [ESI + 0x20]
//         004653c7     PUSH       EDI
//         004653c8     MOV        this,dword ptr [EAX + 0x4]
//         004653cb     PUSH       this
//         004653cc     CALL       dword ptr [->USER32.DLL::ValidateRect]           = 0048ae8c
//         004653d2     POP        EDI
//                               LAB_004653d3                                                 XREF[3]:     004653a8(j), 004653af(j),
//                                                                                                         004653b6(j)
//                              Panel.cpp:1419 (2)
//         004653d3     POP        ESI
//         004653d4     RET
//         004653d5     ??         90h
//         004653d6     NOP
//         004653d7     NOP
//         004653d8     NOP
//         004653d9     NOP
//         004653da     NOP
//         004653db     NOP
//         004653dc     NOP
//         004653dd     NOP
//         004653de     NOP
//         004653df     NOP
    return;
}

long TPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              long __thiscall wnd_proc(TPanel * this, void * param_1, uint param_2
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[2]:     00465406(R), 00465446(R)
//              uint              Stack[0x8]:4   param_2                   XREF[10]:    004653f6(R), 004654f3(*), 00465571(R), 00465594(R),
//                                                                                     004655b9(R), 004655de(R), 00465603(R), 00465628(R),
//                                                                                     0046564d(R), 0046572a(W)
//              uint              Stack[0xc]:4   param_3                   XREF[4]:     0046543c(R), 004654fc(R), 004656db(R), 00465726(R)
//              long              Stack[0x10]:4  param_4                   XREF[12]:    00465402(R), 00465438(R), 004654f7(*), 00465578(R),
//                                                                                     0046559b(R), 004655c0(R), 004655e5(R), 0046560a(R),
//                                                                                     0046562f(R), 00465654(R), 00465714(W), 0046572f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0046557d(R), 004655a0(R), 004655c5(R), 004655ea(R),
//                                                                                     0046560f(R), 00465634(R), 00465659(R)
//              tagPOINT          Stack[-0xc]:8  point                     XREF[4,8]:   004653ec(W), 004654ef(R), 00465672(R), 004656c7(R),
//                                                                                     00465500(*), 00465582(R), 004655a5(R), 004655ca(R),
//                                                                                     004655ef(R), 00465614(R), 00465639(R), 0046565e(R)
//                               ?wnd_proc@TPanel@@UAEJPAXIIJ@Z                               XREF[72]:    wnd_proc:0047390a(c),
//                               TPanel::wnd_proc                                                          wnd_proc:00476007(c),
//                                                                                                         wnd_proc:00476026(c),
//                                                                                                         wnd_proc:0048f5b8(c),
//                                                                                                         wnd_proc:0049716d(c),
//                                                                                                         wnd_proc:004a71e4(c), 0056f550(*),
//                                                                                                         0056f658(*), 0056f798(*),
//                                                                                                         0056f8e0(*), 0056fa10(*),
//                                                                                                         0056fb40(*), 0056fc78(*),
//                                                                                                         0056fda8(*), 0056fed8(*),
//                                                                                                         00570008(*), 00570138(*),
//                                                                                                         00570c80(*), 00570d60(*),
//                                                                                                         005710f8(*), [more]
//                              Panel.cpp:1425 (3)
//         004653e0     SUB        ESP,0xc
//                              Panel.cpp:1432 (13)
//         004653e3     MOV        EAX,dword ptr [ECX + this->active]
//         004653e6     PUSH       EBX
//         004653e7     PUSH       EBP
//         004653e8     PUSH       ESI
//         004653e9     TEST       EAX,EAX
//         004653eb     PUSH       EDI
//         004653ec     MOV        dword ptr [ESP + point.x],this
//                              Panel.cpp:1433 (6)
//         004653f0     JZ         switchD_00465477::caseD_112
//                              Panel.cpp:1436 (63)
//         004653f6     MOV        EBP,dword ptr [ESP + param_2]
//         004653fa     CMP        EBP,0x206
//         00465400     JA         LAB_00465435
//         00465402     MOV        EBX,dword ptr [ESP + param_4]
//         00465406     MOV        EDI,dword ptr [ESP + param_1]
//         0046540a     CMP        EBP,0x200
//         00465410     JNC        LAB_004654d9
//         00465416     MOV        EAX,EBP
//         00465418     SUB        EAX,0x100
//         0046541d     JZ         switchD_0046556a::default
//         00465423     SUB        EAX,0x2
//         00465426     JZ         switchD_0046556a::default
//         0046542c     SUB        EAX,0x2
//         0046542f     JZ         switchD_0046556a::default
//                               LAB_00465435                                                 XREF[1]:     00465400(j)
//                              Panel.cpp:1496 (15)
//         00465435     MOV        ESI,dword ptr [ECX + this->last_child_node]
//         00465438     MOV        EBX,dword ptr [ESP + param_4]
//         0046543c     MOV        EDI,dword ptr [ESP + param_3]
//         00465440     TEST       ESI,ESI
//         00465442     JZ         LAB_00465462
//                               LAB_00465444                                                 XREF[1]:     0046545c(j)
//                              Panel.cpp:1498 (15)
//         00465444     MOV        this,dword ptr [ESI]
//         00465446     MOV        EAX,dword ptr [ESP + param_1]
//         0046544a     PUSH       EBX
//         0046544b     PUSH       EDI=>DAT_fffffff8
//         0046544c     MOV        EDX,dword ptr [this->_padding_]
//         0046544e     PUSH       EBP=>DAT_fffffff4
//         0046544f     PUSH       EAX=>DAT_fffffff0
//         00465450     CALL       dword ptr [EDX + 0x48]
//                              Panel.cpp:1499 (11)
//         00465453     TEST       EAX,EAX
//         00465455     JNZ        LAB_004654cf
//         00465457     MOV        ESI,dword ptr [ESI + 0x4]
//         0046545a     TEST       ESI,ESI
//         0046545c     JNZ        LAB_00465444
//                              Panel.cpp:1496 (4)
//         0046545e     MOV        this,dword ptr [ESP + 0x10]
//                               LAB_00465462                                                 XREF[1]:     00465442(j)
//                              Panel.cpp:1504 (28)
//         00465462     CMP        EBP,0x400
//         00465468     JA         switchD_00465477::caseD_112
//         0046546a     JZ         LAB_004654bc
//         0046546c     ADD        EBP,0xfffffeef
//         00465472     CMP        EBP,0x4
//         00465475     JA         switchD_00465477::caseD_112
//                               switchD_00465477::switchD
//         00465477     JMP        dword ptr [EBP*0x4 + switchD_00465477::switchd   = 0046547e
//                               switchD_00465477::caseD_111                                  XREF[2]:     00465477(j), 00465748(*)
//                              Panel.cpp:1507 (7)
//         0046547e     MOV        EDX,dword ptr [this->_padding_]
//         00465480     PUSH       EBX
//         00465481     PUSH       EDI=>DAT_fffffff8
//         00465482     CALL       dword ptr [EDX + 0x60]
//                              Panel.cpp:1521 (10)
//         00465485     POP        EDI
//         00465486     POP        ESI
//         00465487     POP        EBP
//         00465488     POP        EBX
//         00465489     ADD        ESP,0xc
//         0046548c     RET        0x10
//                               switchD_00465477::caseD_113                                  XREF[2]:     00465477(j), 00465750(*)
//                              Panel.cpp:1513 (7)
//         0046548f     MOV        EAX,dword ptr [this->_padding_]
//         00465491     PUSH       EBX
//         00465492     PUSH       EDI=>DAT_fffffff8
//         00465493     CALL       dword ptr [EAX + 0x68]
//                              Panel.cpp:1521 (10)
//         00465496     POP        EDI
//         00465497     POP        ESI
//         00465498     POP        EBP
//         00465499     POP        EBX
//         0046549a     ADD        ESP,0xc
//         0046549d     RET        0x10
//                               switchD_00465477::caseD_115                                  XREF[3]:     00465477(j), 00465754(*),
//                               switchD_00465477::caseD_114                                               00465758(*)
//                              Panel.cpp:1517 (18)
//         004654a0     MOV        EDX,dword ptr [this->_padding_]
//         004654a2     MOV        EAX,EDI
//         004654a4     SHR        EAX,0x10
//         004654a7     AND        EDI,0xffff
//         004654ad     PUSH       EAX
//         004654ae     PUSH       EDI=>DAT_fffffff8
//         004654af     CALL       dword ptr [EDX + 0x6c]
//                              Panel.cpp:1521 (10)
//         004654b2     POP        EDI
//         004654b3     POP        ESI
//         004654b4     POP        EBP
//         004654b5     POP        EBX
//         004654b6     ADD        ESP,0xc
//         004654b9     RET        0x10
//                               LAB_004654bc                                                 XREF[1]:     0046546a(j)
//                              Panel.cpp:1510 (7)
//         004654bc     MOV        EDX,dword ptr [this->_padding_]
//         004654be     PUSH       EBX
//         004654bf     PUSH       EDI=>DAT_fffffff8
//         004654c0     CALL       dword ptr [EDX + 0x64]
//                              Panel.cpp:1521 (10)
//         004654c3     POP        EDI
//         004654c4     POP        ESI
//         004654c5     POP        EBP
//         004654c6     POP        EBX
//         004654c7     ADD        ESP,0xc
//         004654ca     RET        0x10
//                               switchD_00465477::caseD_112                                  XREF[9]:     004653f0(j), 00465468(j),
//                                                                                                         00465475(j), 00465477(j),
//                                                                                                         004654df(j), 004654ed(j),
//                                                                                                         0046567c(j), 0046568e(j),
//                                                                                                         0046574c(*)
//                              Panel.cpp:1520 (2)
//         004654cd     XOR        EAX,EAX
//                               LAB_004654cf                                                 XREF[1]:     00465455(j)
//                              Panel.cpp:1521 (10)
//         004654cf     POP        EDI
//         004654d0     POP        ESI
//         004654d1     POP        EBP
//         004654d2     POP        EBX
//         004654d3     ADD        ESP,0xc
//         004654d6     RET        0x10
//                               LAB_004654d9                                                 XREF[1]:     00465410(j)
//                              Panel.cpp:1445 (22)
//         004654d9     MOV        EAX,dword ptr [ECX + this->render_area]
//         004654dc     CMP        EDI,dword ptr [EAX + 0x4]
//         004654df     JNZ        switchD_00465477::caseD_112
//         004654e1     MOV        this,panel_system
//         004654e6     CALL       TPanelSystem::GetInputEnabled                    int GetInputEnabled(TPanelSystem * this)
//         004654eb     TEST       EAX,EAX
//         004654ed     JZ         switchD_00465477::caseD_112
//                              Panel.cpp:1448 (32)
//         004654ef     MOV        ESI,dword ptr [ESP + point.x]
//         004654f3     LEA        this=>param_2,[ESP + 0x24]
//         004654f7     LEA        EDX=>param_4,[ESP + 0x2c]
//         004654fb     PUSH       this
//         004654fc     MOV        this,dword ptr [ESP + param_3]
//         00465500     LEA        EAX=>point.y,[ESP + 0x18]
//         00465504     PUSH       EDX
//         00465505     PUSH       EAX
//         00465506     PUSH       EBX
//         00465507     PUSH       this
//         00465508     MOV        this,ESI
//         0046550a     CALL       TPanel::get_mouse_info                           void get_mouse_info(TPanel * this, uint param
//                              Panel.cpp:1452 (12)
//         0046550f     MOV        this,panel_system
//         00465514     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         00465519     TEST       EAX,EAX
//                              Panel.cpp:1453 (14)
//         0046551b     MOV        this,panel_system
//         00465520     JZ         LAB_0046552b
//         00465522     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         00465527     MOV        this,EAX
//                              Panel.cpp:1454 (9)
//         00465529     JMP        LAB_0046555b
//                               LAB_0046552b                                                 XREF[1]:     00465520(j)
//         0046552b     CALL       TPanelSystem::keyboardOwner                      TPanel * keyboardOwner(TPanelSystem * this)
//         00465530     TEST       EAX,EAX
//                              Panel.cpp:1455 (14)
//         00465532     MOV        this,panel_system
//         00465537     JZ         LAB_00465542
//         00465539     CALL       TPanelSystem::keyboardOwner                      TPanel * keyboardOwner(TPanelSystem * this)
//         0046553e     MOV        this,EAX
//                              Panel.cpp:1456 (11)
//         00465540     JMP        LAB_0046555b
//                               LAB_00465542                                                 XREF[1]:     00465537(j)
//         00465542     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
//         00465547     TEST       EAX,EAX
//         00465549     JZ         LAB_00465559
//                              Panel.cpp:1457 (12)
//         0046554b     MOV        this,panel_system
//         00465550     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
//         00465555     MOV        this,EAX
//                              Panel.cpp:1458 (2)
//         00465557     JMP        LAB_0046555b
//                               LAB_00465559                                                 XREF[1]:     00465549(j)
//                              Panel.cpp:1459 (2)
//         00465559     MOV        this,ESI
//                               LAB_0046555b                                                 XREF[3]:     00465529(j), 00465540(j),
//                                                                                                         00465557(j)
//                              Panel.cpp:1460 (22)
//         0046555b     LEA        EAX,[EBP + 0xfffffe00]
//         00465561     CMP        EAX,0x6
//         00465564     JA         LAB_00465672
//                               switchD_0046556a::switchD
//         0046556a     JMP        dword ptr [EAX*0x4 + switchD_0046556a::switchd   = 00465571
//                               switchD_0046556a::caseD_200                                  XREF[2]:     0046556a(j), 0046575c(*)
//                              Panel.cpp:1462 (25)
//         00465571     MOV        EAX,dword ptr [ESP + param_2]
//         00465575     MOV        EDX,dword ptr [this->_padding_]
//         00465577     PUSH       EAX
//         00465578     MOV        EAX,dword ptr [ESP + param_4]
//         0046557c     PUSH       EAX
//         0046557d     MOV        EAX,dword ptr [ESP + local_4]
//         00465581     PUSH       EAX
//         00465582     MOV        EAX,dword ptr [ESP + point.y]
//         00465586     PUSH       EAX
//         00465587     CALL       dword ptr [EDX + 0x74]
//                              Panel.cpp:1521 (10)
//         0046558a     POP        EDI
//         0046558b     POP        ESI
//         0046558c     POP        EBP
//         0046558d     POP        EBX
//         0046558e     ADD        ESP,0xc
//         00465591     RET        0x10
//                               switchD_0046556a::caseD_201                                  XREF[2]:     0046556a(j), 00465760(*)
//                              Panel.cpp:1463 (27)
//         00465594     MOV        EAX,dword ptr [ESP + param_2]
//         00465598     MOV        EDX,dword ptr [this->_padding_]
//         0046559a     PUSH       EAX
//         0046559b     MOV        EAX,dword ptr [ESP + param_4]
//         0046559f     PUSH       EAX
//         004655a0     MOV        EAX,dword ptr [ESP + local_4]
//         004655a4     PUSH       EAX
//         004655a5     MOV        EAX,dword ptr [ESP + point.y]
//         004655a9     PUSH       EAX
//         004655aa     PUSH       0x1
//         004655ac     CALL       dword ptr [EDX + 0x70]
//                              Panel.cpp:1521 (10)
//         004655af     POP        EDI
//         004655b0     POP        ESI
//         004655b1     POP        EBP
//         004655b2     POP        EBX
//         004655b3     ADD        ESP,0xc
//         004655b6     RET        0x10
//                               switchD_0046556a::caseD_202                                  XREF[2]:     0046556a(j), 00465764(*)
//                              Panel.cpp:1464 (27)
//         004655b9     MOV        EAX,dword ptr [ESP + param_2]
//         004655bd     MOV        EDX,dword ptr [this->_padding_]
//         004655bf     PUSH       EAX
//         004655c0     MOV        EAX,dword ptr [ESP + param_4]
//         004655c4     PUSH       EAX
//         004655c5     MOV        EAX,dword ptr [ESP + local_4]
//         004655c9     PUSH       EAX
//         004655ca     MOV        EAX,dword ptr [ESP + point.y]
//         004655ce     PUSH       EAX
//         004655cf     PUSH       0x1
//         004655d1     CALL       dword ptr [EDX + 0x78]
//                              Panel.cpp:1521 (10)
//         004655d4     POP        EDI
//         004655d5     POP        ESI
//         004655d6     POP        EBP
//         004655d7     POP        EBX
//         004655d8     ADD        ESP,0xc
//         004655db     RET        0x10
//                               switchD_0046556a::caseD_203                                  XREF[2]:     0046556a(j), 00465768(*)
//                              Panel.cpp:1465 (27)
//         004655de     MOV        EAX,dword ptr [ESP + param_2]
//         004655e2     MOV        EDX,dword ptr [this->_padding_]
//         004655e4     PUSH       EAX
//         004655e5     MOV        EAX,dword ptr [ESP + param_4]
//         004655e9     PUSH       EAX
//         004655ea     MOV        EAX,dword ptr [ESP + local_4]
//         004655ee     PUSH       EAX
//         004655ef     MOV        EAX,dword ptr [ESP + point.y]
//         004655f3     PUSH       EAX
//         004655f4     PUSH       0x1
//         004655f6     CALL       dword ptr [EDX + 0x7c]
//                              Panel.cpp:1521 (10)
//         004655f9     POP        EDI
//         004655fa     POP        ESI
//         004655fb     POP        EBP
//         004655fc     POP        EBX
//         004655fd     ADD        ESP,0xc
//         00465600     RET        0x10
//                               switchD_0046556a::caseD_204                                  XREF[2]:     0046556a(j), 0046576c(*)
//                              Panel.cpp:1466 (27)
//         00465603     MOV        EAX,dword ptr [ESP + param_2]
//         00465607     MOV        EDX,dword ptr [this->_padding_]
//         00465609     PUSH       EAX
//         0046560a     MOV        EAX,dword ptr [ESP + param_4]
//         0046560e     PUSH       EAX
//         0046560f     MOV        EAX,dword ptr [ESP + local_4]
//         00465613     PUSH       EAX
//         00465614     MOV        EAX,dword ptr [ESP + point.y]
//         00465618     PUSH       EAX
//         00465619     PUSH       0x2
//         0046561b     CALL       dword ptr [EDX + 0x70]
//                              Panel.cpp:1521 (10)
//         0046561e     POP        EDI
//         0046561f     POP        ESI
//         00465620     POP        EBP
//         00465621     POP        EBX
//         00465622     ADD        ESP,0xc
//         00465625     RET        0x10
//                               switchD_0046556a::caseD_205                                  XREF[2]:     0046556a(j), 00465770(*)
//                              Panel.cpp:1467 (27)
//         00465628     MOV        EAX,dword ptr [ESP + param_2]
//         0046562c     MOV        EDX,dword ptr [this->_padding_]
//         0046562e     PUSH       EAX
//         0046562f     MOV        EAX,dword ptr [ESP + param_4]
//         00465633     PUSH       EAX
//         00465634     MOV        EAX,dword ptr [ESP + local_4]
//         00465638     PUSH       EAX
//         00465639     MOV        EAX,dword ptr [ESP + point.y]
//         0046563d     PUSH       EAX
//         0046563e     PUSH       0x2
//         00465640     CALL       dword ptr [EDX + 0x78]
//                              Panel.cpp:1521 (10)
//         00465643     POP        EDI
//         00465644     POP        ESI
//         00465645     POP        EBP
//         00465646     POP        EBX
//         00465647     ADD        ESP,0xc
//         0046564a     RET        0x10
//                               switchD_0046556a::caseD_206                                  XREF[2]:     0046556a(j), 00465774(*)
//                              Panel.cpp:1468 (27)
//         0046564d     MOV        EAX,dword ptr [ESP + param_2]
//         00465651     MOV        EDX,dword ptr [this->_padding_]
//         00465653     PUSH       EAX
//         00465654     MOV        EAX,dword ptr [ESP + param_4]
//         00465658     PUSH       EAX
//         00465659     MOV        EAX,dword ptr [ESP + local_4]
//         0046565d     PUSH       EAX
//         0046565e     MOV        EAX,dword ptr [ESP + point.y]
//         00465662     PUSH       EAX
//         00465663     PUSH       0x2
//         00465665     CALL       dword ptr [EDX + 0x7c]
//                              Panel.cpp:1521 (10)
//         00465668     POP        EDI
//         00465669     POP        ESI
//         0046566a     POP        EBP
//         0046566b     POP        EBX
//         0046566c     ADD        ESP,0xc
//         0046566f     RET        0x10
//                               LAB_00465672                                                 XREF[1]:     00465564(j)
//                              Panel.cpp:1460 (4)
//         00465672     MOV        this,dword ptr [ESP + point.x]
//                               switchD_0046556a::default                                    XREF[3]:     0046541d(j), 00465426(j),
//                                                                                                         0046542f(j)
//                              Panel.cpp:1474 (30)
//         00465676     MOV        this,dword ptr [ECX + this->render_area]
//         00465679     CMP        EDI,dword ptr [ECX + this->previousPanelValue]
//         0046567c     JNZ        switchD_00465477::caseD_112
//         00465682     MOV        this,panel_system
//         00465687     CALL       TPanelSystem::GetInputEnabled                    int GetInputEnabled(TPanelSystem * this)
//         0046568c     TEST       EAX,EAX
//         0046568e     JZ         switchD_00465477::caseD_112
//                              Panel.cpp:1477 (12)
//         00465694     MOV        this,panel_system
//         00465699     CALL       TPanelSystem::keyboardOwner                      TPanel * keyboardOwner(TPanelSystem * this)
//         0046569e     TEST       EAX,EAX
//                              Panel.cpp:1478 (14)
//         004656a0     MOV        this,panel_system
//         004656a5     JZ         LAB_004656b0
//         004656a7     CALL       TPanelSystem::keyboardOwner                      TPanel * keyboardOwner(TPanelSystem * this)
//         004656ac     MOV        ESI,EAX
//                              Panel.cpp:1479 (11)
//         004656ae     JMP        LAB_004656cb
//                               LAB_004656b0                                                 XREF[1]:     004656a5(j)
//         004656b0     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
//         004656b5     TEST       EAX,EAX
//         004656b7     JZ         LAB_004656c7
//                              Panel.cpp:1480 (12)
//         004656b9     MOV        this,panel_system
//         004656be     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
//         004656c3     MOV        ESI,EAX
//                              Panel.cpp:1481 (2)
//         004656c5     JMP        LAB_004656cb
//                               LAB_004656c7                                                 XREF[1]:     004656b7(j)
//                              Panel.cpp:1482 (4)
//         004656c7     MOV        ESI,dword ptr [ESP + point.x]
//                               LAB_004656cb                                                 XREF[2]:     004656ae(j), 004656c5(j)
//                              Panel.cpp:1484 (16)
//         004656cb     CMP        EBP,0x100
//         004656d1     JZ         LAB_004656f2
//         004656d3     CMP        EBP,0x104
//         004656d9     JZ         LAB_004656f2
//                              Panel.cpp:1492 (13)
//         004656db     MOV        EAX,dword ptr [ESP + param_3]
//         004656df     MOV        EDX,dword ptr [ESI]
//         004656e1     PUSH       EBX
//         004656e2     PUSH       EAX
//         004656e3     MOV        this,ESI
//         004656e5     CALL       dword ptr [EDX + 0x5c]
//                              Panel.cpp:1521 (10)
//         004656e8     POP        EDI
//         004656e9     POP        ESI
//         004656ea     POP        EBP
//         004656eb     POP        EBX
//         004656ec     ADD        ESP,0xc
//         004656ef     RET        0x10
//                               LAB_004656f2                                                 XREF[2]:     004656d1(j), 004656d9(j)
//                              Panel.cpp:1486 (12)
//         004656f2     MOV        EDI,dword ptr [->USER32.DLL::GetKeyState]        = 0048af44
//         004656f8     PUSH       0x12
//         004656fa     CALL       EDI=>USER32.DLL::GetKeyState
//         004656fc     XOR        this,this
//                              Panel.cpp:1487 (14)
//         004656fe     PUSH       0x11
//         00465700     TEST       AX,AX
//         00465703     SETL       this
//         00465706     MOV        EBP,this
//         00465708     CALL       EDI=>USER32.DLL::GetKeyState
//         0046570a     XOR        EDX,EDX
//                              Panel.cpp:1488 (16)
//         0046570c     PUSH       0x10
//         0046570e     TEST       AX,AX
//         00465711     SETL       DL
//         00465714     MOV        dword ptr [ESP + param_4],EDX
//         00465718     CALL       EDI=>USER32.DLL::GetKeyState
//         0046571a     XOR        this,this
//                              Panel.cpp:1489 (32)
//         0046571c     MOV        EDX,dword ptr [ESI]
//         0046571e     TEST       AX,AX
//         00465721     SETL       this
//         00465724     MOV        EAX,this
//         00465726     MOV        this,dword ptr [ESP + param_3]
//         0046572a     MOV        dword ptr [ESP + param_2],EAX
//         0046572e     PUSH       EAX
//         0046572f     MOV        EAX,dword ptr [ESP + param_4]
//         00465733     PUSH       EAX
//         00465734     PUSH       EBP
//         00465735     PUSH       EBX
//         00465736     PUSH       this
//         00465737     MOV        this,ESI
//         00465739     CALL       dword ptr [EDX + 0x58]
//                              Panel.cpp:1521 (60)
//         0046573c     POP        EDI
//         0046573d     POP        ESI
//         0046573e     POP        EBP
//         0046573f     POP        EBX
//         00465740     ADD        ESP,0xc
//         00465743     RET        0x10
    return 0;
}

long TPanel::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?handle_idle@TPanel@@UAEJXZ                                  XREF[68]:    handle_idle:00476f94(c),
//                               TPanel::handle_idle                                                       handle_idle:004783f3(c),
//                                                                                                         handle_idle:00490fe2(c),
//                                                                                                         handle_idle:00491b17(c),
//                                                                                                         handle_idle:00492caa(c),
//                                                                                                         handle_idle:0049305d(c),
//                                                                                                         handle_idle:004967dc(c),
//                                                                                                         handle_idle:0049d653(c),
//                                                                                                         handle_idle:0049d688(c),
//                                                                                                         handle_idle:0049e2ca(c),
//                                                                                                         handle_idle:0049f35a(c),
//                                                                                                         handle_idle:004a618a(c),
//                                                                                                         handle_idle:004a63c0(j),
//                                                                                                         handle_idle:004ab7ba(c),
//                                                                                                         handle_idle:004b31ba(c),
//                                                                                                         handle_idle:004b5c60(c),
//                                                                                                         handle_idle:004b88ca(c),
//                                                                                                         handle_idle:0051aad9(c),
//                                                                                                         handle_idle:0051d4e0(c),
//                                                                                                         handle_idle:0051e154(c), [more]
//                              Panel.cpp:1527 (3)
//         00465780     PUSH       ESI
//         00465781     MOV        ESI,this
//                              Panel.cpp:1531 (16)
//         00465783     MOV        EAX,dword ptr [ESI + 0x6c]
//         00465786     TEST       EAX,EAX
//         00465788     JZ         LAB_004657f6
//         0046578a     CMP        byte ptr [ESI + 0xec],0x1
//         00465791     JNZ        LAB_004657f6
//                              Panel.cpp:1533 (36)
//         00465793     PUSH       0x5fd
//         00465798     PUSH       s_C:\msdev\work\age1_x1\Panel.cpp                = "C:\\msdev\\work\\age1_x1\\Panel.cpp"
//         0046579d     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004657a2     MOV        EDX,dword ptr [ESI + 0xd4]
//         004657a8     MOV        this,dword ptr [ESI + 0xbc]
//         004657ae     SUB        EAX,EDX
//         004657b0     ADD        ESP,0x8
//         004657b3     CMP        EAX,this
//         004657b5     JL         LAB_004657f6
//                              Panel.cpp:1537 (55)
//         004657b7     MOV        this,dword ptr [ESI + 0xd0]
//         004657bd     MOV        EDX,dword ptr [ESI + 0xcc]
//         004657c3     MOV        AL,byte ptr [ESI + 0xed]
//         004657c9     PUSH       this
//         004657ca     MOV        this,dword ptr [ESI + 0xc8]
//         004657d0     PUSH       EDX
//         004657d1     MOV        EDX,dword ptr [ESI + 0xc4]
//         004657d7     CMP        AL,0x1
//         004657d9     MOV        EAX,dword ptr [ESI]
//         004657db     PUSH       this
//         004657dc     MOV        byte ptr [ESI + 0xec],0x2
//         004657e3     PUSH       EDX
//         004657e4     MOV        this,ESI
//         004657e6     JNZ        LAB_004657f0
//         004657e8     CALL       dword ptr [EAX + 0x88]
//                              Panel.cpp:1538 (2)
//         004657ee     JMP        LAB_004657f6
//                               LAB_004657f0                                                 XREF[1]:     004657e6(j)
//                              Panel.cpp:1539 (6)
//         004657f0     CALL       dword ptr [EAX + 0x9c]
//                               LAB_004657f6                                                 XREF[4]:     00465788(j), 00465791(j),
//                                                                                                         004657b5(j), 004657ee(j)
//                              Panel.cpp:1544 (7)
//         004657f6     MOV        ESI,dword ptr [ESI + 0x5c]
//         004657f9     TEST       ESI,ESI
//         004657fb     JZ         LAB_0046580f
//                               LAB_004657fd                                                 XREF[1]:     0046580d(j)
//                              Panel.cpp:1546 (7)
//         004657fd     MOV        this,dword ptr [ESI]
//         004657ff     MOV        EAX,dword ptr [this->_padding_]
//         00465801     CALL       dword ptr [EAX + 0x4c]
//                              Panel.cpp:1547 (11)
//         00465804     TEST       EAX,EAX
//         00465806     JNZ        LAB_00465811
//         00465808     MOV        ESI,dword ptr [ESI + 0x4]
//         0046580b     TEST       ESI,ESI
//         0046580d     JNZ        LAB_004657fd
//                               LAB_0046580f                                                 XREF[1]:     004657fb(j)
//                              Panel.cpp:1551 (2)
//         0046580f     XOR        EAX,EAX
//                               LAB_00465811                                                 XREF[1]:     00465806(j)
//                              Panel.cpp:1552 (2)
//         00465811     POP        ESI
//         00465812     RET
//         00465813     ??         90h
//         00465814     NOP
//         00465815     NOP
//         00465816     NOP
//         00465817     NOP
//         00465818     NOP
//         00465819     NOP
//         0046581a     NOP
//         0046581b     NOP
//         0046581c     NOP
//         0046581d     NOP
//         0046581e     NOP
//         0046581f     NOP
    return 0;
}

long TPanel::handle_size(long param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_size(TPanel * this, long param_1, long param_2)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[3]:     0046584b(W), 0046585a(R), 004659bc(R)
//              long              Stack[0x8]:4   param_2                   XREF[3]:     00465854(W), 0046585e(R), 004659e0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0046593a(W), 00465981(R), 00465991(R), 004659fb(W),
//                                                                                     00465a02(R)
//              long              Stack[-0x8]:4  calc_hgt
//              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     00465a1e(W)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     00465a1b(W)
//              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     00465a18(W)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00465a15(*)
//                               ?handle_size@TPanel@@UAEJJJ@Z                                XREF[72]:    handle_size:0043863f(c),
//                               TPanel::handle_size                                                       handle_size:00495af2(c),
//                                                                                                         handle_size:004ab71f(c),
//                                                                                                         handle_size:004ab72f(c),
//                                                                                                         0056f660(*), 0056f7a0(*),
//                                                                                                         0056f8e8(*), 0056fa18(*),
//                                                                                                         0056fb48(*), 0056fc80(*),
//                                                                                                         0056fdb0(*), 0056fee0(*),
//                                                                                                         00570010(*), 00570140(*),
//                                                                                                         00570c88(*), 00570d68(*),
//                                                                                                         00571018(*), 00571100(*),
//                                                                                                         00571230(*), 00571310(*), [more]
//                              Panel.cpp:1558 (6)
//         00465820     PUSH       this
//         00465821     PUSH       EBX
//         00465822     MOV        EBX,this
//         00465824     PUSH       EBP
//         00465825     PUSH       ESI
//                              Panel.cpp:1564 (8)
//         00465826     MOV        EAX,dword ptr [EBX + 0x40]
//         00465829     PUSH       EDI
//         0046582a     TEST       EAX,EAX
//         0046582c     JZ         LAB_0046585a
//                              Panel.cpp:1568 (18)
//         0046582e     MOV        EDI,dword ptr [EAX + 0x94]
//         00465834     MOV        EDX,dword ptr [EAX + 0x8c]
//         0046583a     MOV        EBP,dword ptr [EAX + 0x90]
//                              Panel.cpp:1569 (6)
//         00465840     MOV        this,dword ptr [EAX + 0x98]
//                              Panel.cpp:1570 (9)
//         00465846     MOV        EAX,EDI
//         00465848     SUB        EAX,EDX
//         0046584a     INC        EAX
//         0046584b     MOV        dword ptr [ESP + param_1],EAX
//                              Panel.cpp:1571 (9)
//         0046584f     MOV        EAX,this
//         00465851     SUB        EAX,EBP
//         00465853     INC        EAX
//         00465854     MOV        dword ptr [ESP + param_2],EAX
//                              Panel.cpp:1573 (2)
//         00465858     JMP        LAB_0046586a
//                               LAB_0046585a                                                 XREF[1]:     0046582c(j)
//                              Panel.cpp:1577 (4)
//         0046585a     MOV        EAX,dword ptr [ESP + param_1]
//                              Panel.cpp:1578 (12)
//         0046585e     MOV        this,dword ptr [ESP + param_2]
//         00465862     XOR        EDX,EDX
//         00465864     XOR        EBP,EBP
//         00465866     LEA        EDI,[EAX + -0x1]
//         00465869     DEC        this
//                               LAB_0046586a                                                 XREF[1]:     00465858(j)
//                              Panel.cpp:1581 (7)
//         0046586a     MOV        EAX,dword ptr [EBX + 0x34]
//         0046586d     TEST       EAX,EAX
//         0046586f     JNZ        LAB_00465896
//                              Panel.cpp:1583 (6)
//         00465871     MOV        ESI,dword ptr [EBX + 0x9c]
//                              Panel.cpp:1584 (6)
//         00465877     MOV        EAX,dword ptr [EBX + 0xa0]
//                              Panel.cpp:1586 (20)
//         0046587d     MOV        this,dword ptr [EBX + 0xb4]
//         00465883     ADD        ESI,EDX
//         00465885     MOV        EDX,dword ptr [EBX + 0xac]
//         0046588b     ADD        EAX,EBP
//         0046588d     LEA        EDI,[EDX + ESI*0x1 + -0x1]
//                              Panel.cpp:1588 (5)
//         00465891     JMP        LAB_00465a0a
//                               LAB_00465896                                                 XREF[1]:     0046586f(j)
//                              Panel.cpp:1590 (14)
//         00465896     MOV        EAX,dword ptr [EBX + 0x44]
//         00465899     TEST       EAX,EAX
//         0046589b     JZ         LAB_004658b6
//         0046589d     MOV        ESI,dword ptr [EAX + 0x6c]
//         004658a0     TEST       ESI,ESI
//         004658a2     JZ         LAB_004658b6
//                              Panel.cpp:1591 (16)
//         004658a4     MOV        EDX,dword ptr [EBX + 0x9c]
//         004658aa     MOV        EAX,dword ptr [EAX + 0x94]
//         004658b0     LEA        ESI,[EDX + EAX*0x1 + 0x1]
//                              Panel.cpp:1592 (2)
//         004658b4     JMP        LAB_004658be
//                               LAB_004658b6                                                 XREF[2]:     0046589b(j), 004658a2(j)
//                              Panel.cpp:1593 (8)
//         004658b6     MOV        ESI,dword ptr [EBX + 0x9c]
//         004658bc     ADD        ESI,EDX
//                               LAB_004658be                                                 XREF[1]:     004658b4(j)
//                              Panel.cpp:1595 (14)
//         004658be     MOV        EAX,dword ptr [EBX + 0x48]
//         004658c1     TEST       EAX,EAX
//         004658c3     JZ         LAB_004658de
//         004658c5     MOV        EDX,dword ptr [EAX + 0x6c]
//         004658c8     TEST       EDX,EDX
//         004658ca     JZ         LAB_004658de
//                              Panel.cpp:1596 (16)
//         004658cc     MOV        EDX,dword ptr [EBX + 0xa0]
//         004658d2     MOV        EAX,dword ptr [EAX + 0x98]
//         004658d8     LEA        EAX,[EDX + EAX*0x1 + 0x1]
//                              Panel.cpp:1597 (2)
//         004658dc     JMP        LAB_004658e6
//                               LAB_004658de                                                 XREF[2]:     004658c3(j), 004658ca(j)
//                              Panel.cpp:1598 (8)
//         004658de     MOV        EAX,dword ptr [EBX + 0xa0]
//         004658e4     ADD        EAX,EBP
//                               LAB_004658e6                                                 XREF[1]:     004658dc(j)
//                              Panel.cpp:1600 (14)
//         004658e6     MOV        EDX,dword ptr [EBX + 0x4c]
//         004658e9     TEST       EDX,EDX
//         004658eb     JZ         LAB_00465905
//         004658ed     MOV        EBP,dword ptr [EDX + 0x6c]
//         004658f0     TEST       EBP,EBP
//         004658f2     JZ         LAB_00465905
//                              Panel.cpp:1601 (15)
//         004658f4     MOV        EDI,dword ptr [EDX + 0x8c]
//         004658fa     MOV        EBP,dword ptr [EBX + 0xa4]
//         00465900     SUB        EDI,EBP
//         00465902     DEC        EDI
//                              Panel.cpp:1602 (2)
//         00465903     JMP        LAB_0046590b
//                               LAB_00465905                                                 XREF[2]:     004658eb(j), 004658f2(j)
//                              Panel.cpp:1603 (6)
//         00465905     SUB        EDI,dword ptr [EBX + 0xa4]
//                               LAB_0046590b                                                 XREF[1]:     00465903(j)
//                              Panel.cpp:1605 (14)
//         0046590b     MOV        EDX,dword ptr [EBX + 0x50]
//         0046590e     TEST       EDX,EDX
//         00465910     JZ         LAB_0046592a
//         00465912     MOV        EBP,dword ptr [EDX + 0x6c]
//         00465915     TEST       EBP,EBP
//         00465917     JZ         LAB_0046592a
//                              Panel.cpp:1606 (15)
//         00465919     MOV        this,dword ptr [EDX + 0x90]
//         0046591f     MOV        EBP,dword ptr [EBX + 0xa8]
//         00465925     SUB        this,EBP
//         00465927     DEC        this
//                              Panel.cpp:1607 (2)
//         00465928     JMP        LAB_00465930
//                               LAB_0046592a                                                 XREF[2]:     00465910(j), 00465917(j)
//                              Panel.cpp:1608 (6)
//         0046592a     SUB        this,dword ptr [EBX + 0xa8]
//                               LAB_00465930                                                 XREF[1]:     00465928(j)
//                              Panel.cpp:1610 (2)
//         00465930     MOV        EDX,EDI
//                              Panel.cpp:1611 (12)
//         00465932     MOV        EBP,this
//         00465934     SUB        EDX,ESI
//         00465936     SUB        EBP,EAX
//         00465938     INC        EDX
//         00465939     INC        EBP
//         0046593a     MOV        dword ptr [ESP + local_4],EBP
//                              Panel.cpp:1613 (12)
//         0046593e     MOV        EBP,dword ptr [EBX + 0xac]
//         00465944     TEST       EBP,EBP
//         00465946     JZ         LAB_0046594c
//         00465948     CMP        EDX,EBP
//                              Panel.cpp:1615 (16)
//         0046594a     JL         LAB_00465973
//                               LAB_0046594c                                                 XREF[1]:     00465946(j)
//         0046594c     MOV        EBP,dword ptr [EBX + 0xb0]
//         00465952     TEST       EBP,EBP
//         00465954     JZ         LAB_00465977
//         00465956     CMP        EDX,EBP
//         00465958     JLE        LAB_00465977
//                              Panel.cpp:1619 (18)
//         0046595a     MOV        EDX,dword ptr [EBX + 0x34]
//         0046595d     CMP        EDX,0x3
//         00465960     JZ         LAB_00465973
//         00465962     CMP        EDX,0x7
//         00465965     JZ         LAB_00465973
//         00465967     CMP        EDX,0x8
//         0046596a     JZ         LAB_00465973
//                              Panel.cpp:1622 (7)
//         0046596c     MOV        ESI,EDI
//         0046596e     SUB        ESI,EBP
//         00465970     INC        ESI
//         00465971     JMP        LAB_00465977
//                               LAB_00465973                                                 XREF[4]:     0046594a(j), 00465960(j),
//                                                                                                         00465965(j), 0046596a(j)
//                              Panel.cpp:1620 (4)
//         00465973     LEA        EDI,[ESI + EBP*0x1 + -0x1]
//                               LAB_00465977                                                 XREF[3]:     00465954(j), 00465958(j),
//                                                                                                         00465971(j)
//                              Panel.cpp:1625 (14)
//         00465977     MOV        EDX,dword ptr [EBX + 0xb4]
//         0046597d     TEST       EDX,EDX
//         0046597f     JZ         LAB_00465987
//         00465981     CMP        dword ptr [ESP + local_4],EDX
//                              Panel.cpp:1627 (18)
//         00465985     JL         LAB_004659b0
//                               LAB_00465987                                                 XREF[1]:     0046597f(j)
//         00465987     MOV        EDX,dword ptr [EBX + 0xb8]
//         0046598d     TEST       EDX,EDX
//         0046598f     JZ         LAB_004659b4
//         00465991     CMP        dword ptr [ESP + local_4],EDX
//         00465995     JLE        LAB_004659b4
//                              Panel.cpp:1631 (18)
//         00465997     MOV        EBP,dword ptr [EBX + 0x34]
//         0046599a     CMP        EBP,0x4
//         0046599d     JZ         LAB_004659b0
//         0046599f     CMP        EBP,0x7
//         004659a2     JZ         LAB_004659b0
//         004659a4     CMP        EBP,0x9
//         004659a7     JZ         LAB_004659b0
//                              Panel.cpp:1634 (7)
//         004659a9     MOV        EAX,this
//         004659ab     SUB        EAX,EDX
//         004659ad     INC        EAX
//         004659ae     JMP        LAB_004659b4
//                               LAB_004659b0                                                 XREF[4]:     00465985(j), 0046599d(j),
//                                                                                                         004659a2(j), 004659a7(j)
//                              Panel.cpp:1632 (4)
//         004659b0     LEA        this,[EAX + EDX*0x1 + -0x1]
//                               LAB_004659b4                                                 XREF[3]:     0046598f(j), 00465995(j),
//                                                                                                         004659ae(j)
//                              Panel.cpp:1637 (6)
//         004659b4     CMP        dword ptr [EBX + 0x34],0x2
//         004659b8     JNZ        LAB_00465a0e
//                              Panel.cpp:1639 (2)
//         004659ba     SUB        EDI,ESI
//                              Panel.cpp:1642 (12)
//         004659bc     MOV        ESI,dword ptr [ESP + param_1]
//         004659c0     SUB        this,EAX
//         004659c2     INC        EDI
//         004659c3     INC        this
//         004659c4     CMP        EDI,ESI
//         004659c6     JNZ        LAB_004659cc
//                              Panel.cpp:1643 (2)
//         004659c8     XOR        ESI,ESI
//                              Panel.cpp:1644 (2)
//         004659ca     JMP        LAB_004659e0
//                               LAB_004659cc                                                 XREF[1]:     004659c6(j)
//                              Panel.cpp:1645 (20)
//         004659cc     MOV        EAX,EDI
//         004659ce     CDQ
//         004659cf     SUB        EAX,EDX
//         004659d1     MOV        EBP,EAX
//         004659d3     MOV        EAX,ESI
//         004659d5     CDQ
//         004659d6     SUB        EAX,EDX
//         004659d8     MOV        ESI,EAX
//         004659da     SAR        EBP,0x1
//         004659dc     SAR        ESI,0x1
//         004659de     SUB        ESI,EBP
//                               LAB_004659e0                                                 XREF[1]:     004659ca(j)
//                              Panel.cpp:1648 (12)
//         004659e0     MOV        EBP,dword ptr [ESP + param_2]
//         004659e4     LEA        EDI,[EDI + ESI*0x1 + -0x1]
//         004659e8     CMP        this,EBP
//         004659ea     JNZ        LAB_004659f0
//                              Panel.cpp:1649 (2)
//         004659ec     XOR        EAX,EAX
//                              Panel.cpp:1650 (2)
//         004659ee     JMP        LAB_00465a0a
//                               LAB_004659f0                                                 XREF[1]:     004659ea(j)
//                              Panel.cpp:1651 (26)
//         004659f0     MOV        EAX,this
//         004659f2     CDQ
//         004659f3     SUB        EAX,EDX
//         004659f5     MOV        EDX,EAX
//         004659f7     MOV        EAX,EBP
//         004659f9     SAR        EDX,0x1
//         004659fb     MOV        dword ptr [ESP + local_4],EDX
//         004659ff     CDQ
//         00465a00     SUB        EAX,EDX
//         00465a02     MOV        EDX,dword ptr [ESP + local_4]
//         00465a06     SAR        EAX,0x1
//         00465a08     SUB        EAX,EDX
//                               LAB_00465a0a                                                 XREF[2]:     00465891(j), 004659ee(j)
//                              Panel.cpp:1652 (4)
//         00465a0a     LEA        this,[this->_padding_ + EAX*0x1 + -0x1]
//                               LAB_00465a0e                                                 XREF[1]:     004659b8(j)
//                              Panel.cpp:1656 (24)
//         00465a0e     MOV        EDX,dword ptr [EBX]
//         00465a10     SUB        ESP,0x10
//         00465a13     MOV        EBP,ESP
//         00465a15     MOV        dword ptr [EBP]=>local_24,ESI
//         00465a18     MOV        dword ptr [EBP + local_20],EAX
//         00465a1b     MOV        dword ptr [EBP + local_1c],EDI
//         00465a1e     MOV        dword ptr [EBP + local_18],this
//         00465a21     MOV        this,EBX
//         00465a23     CALL       dword ptr [EDX + 0x8]
//                              Panel.cpp:1659 (16)
//         00465a26     MOV        EBP,dword ptr [ESP + 0x1c]
//         00465a2a     MOV        EDI,dword ptr [ESP + 0x18]
//         00465a2e     MOV        dword ptr [ESP + 0x10],0x0
//                               LAB_00465a36                                                 XREF[1]:     00465a5d(j)
//                              Panel.cpp:1661 (7)
//         00465a36     MOV        ESI,dword ptr [EBX + 0x58]
//         00465a39     TEST       ESI,ESI
//         00465a3b     JZ         LAB_00465a51
//                               LAB_00465a3d                                                 XREF[1]:     00465a4f(j)
//                              Panel.cpp:1663 (9)
//         00465a3d     MOV        this,dword ptr [ESI]
//         00465a3f     PUSH       EBP
//         00465a40     PUSH       EDI=>DAT_fffffff8
//         00465a41     MOV        EAX,dword ptr [this->_padding_]
//         00465a43     CALL       dword ptr [EAX + 0x50]
//                              Panel.cpp:1664 (11)
//         00465a46     TEST       EAX,EAX
//         00465a48     JNZ        LAB_00465a61
//         00465a4a     MOV        ESI,dword ptr [ESI + 0x8]
//         00465a4d     TEST       ESI,ESI
//         00465a4f     JNZ        LAB_00465a3d
//                               LAB_00465a51                                                 XREF[1]:     00465a3b(j)
//                              Panel.cpp:1659 (14)
//         00465a51     MOV        EAX,dword ptr [ESP + 0x10]
//         00465a55     INC        EAX
//         00465a56     CMP        EAX,0x2
//         00465a59     MOV        dword ptr [ESP + 0x10],EAX
//         00465a5d     JL         LAB_00465a36
//                              Panel.cpp:1669 (2)
//         00465a5f     XOR        EAX,EAX
//                               LAB_00465a61                                                 XREF[1]:     00465a48(j)
//                              Panel.cpp:1670 (8)
//         00465a61     POP        EDI
//         00465a62     POP        ESI
//         00465a63     POP        EBP
//         00465a64     POP        EBX
//         00465a65     POP        this
//         00465a66     RET        0x8
//         00465a69     ??         90h
//         00465a6a     NOP
//         00465a6b     NOP
//         00465a6c     NOP
//         00465a6d     NOP
//         00465a6e     NOP
//         00465a6f     NOP
    return 0;
}

long TPanel::handle_paint() {
    /* TODO: Stub */
//                              long __thiscall handle_paint(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?handle_paint@TPanel@@UAEJXZ                                 XREF[47]:    handle_paint:0047bb50(c),
//                               TPanel::handle_paint                                                      0056f55c(*), 0056f664(*),
//                                                                                                         0056f7a4(*), 0056f8ec(*),
//                                                                                                         0056fa1c(*), 0056fb4c(*),
//                                                                                                         0056fc84(*), 0056fdb4(*),
//                                                                                                         0056fee4(*), 00570014(*),
//                                                                                                         00570144(*), 00570c8c(*),
//                                                                                                         00570d6c(*), 0057101c(*),
//                                                                                                         00571104(*), 00571234(*),
//                                                                                                         00571314(*), 005713fc(*),
//                                                                                                         005714dc(*), [more]
//                              Panel.cpp:1676 (4)
//         00465a70     PUSH       ESI
//         00465a71     PUSH       EDI
//         00465a72     MOV        EDI,this
//                              Panel.cpp:1679 (60)
//         00465a74     MOV        EAX,dword ptr [EDI + 0x20]
//         00465a77     TEST       EAX,EAX
//         00465a79     JZ         LAB_00465b20
//         00465a7f     MOV        this,dword ptr [EDI + 0x70]
//         00465a82     TEST       this,this
//         00465a84     JZ         LAB_00465b20
//         00465a8a     MOV        this,dword ptr [EDI + 0x6c]
//         00465a8d     TEST       this,this
//         00465a8f     JZ         LAB_00465b20
//         00465a95     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00465a9b     MOV        EDX,dword ptr [ECX + this->pnl_hgt]
//         00465a9e     TEST       EDX,EDX
//         00465aa0     JZ         LAB_00465b20
//         00465aa2     MOV        EDX,dword ptr [EAX + 0x4]
//         00465aa5     PUSH       EDX
//         00465aa6     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
//         00465aac     TEST       EAX,EAX
//         00465aae     JNZ        LAB_00465b20
//                              Panel.cpp:1682 (7)
//         00465ab0     MOV        EAX,dword ptr [EDI + 0x38]
//         00465ab3     TEST       EAX,EAX
//         00465ab5     JZ         LAB_00465b01
//                              Panel.cpp:1684 (7)
//         00465ab7     MOV        ESI,dword ptr [EDI + 0x58]
//         00465aba     TEST       ESI,ESI
//         00465abc     JZ         LAB_00465ad0
//                               LAB_00465abe                                                 XREF[1]:     00465ace(j)
//                              Panel.cpp:1685 (18)
//         00465abe     MOV        this,dword ptr [ESI]
//         00465ac0     MOV        EDX,dword ptr [EDI + 0x38]
//         00465ac3     PUSH       EDX
//         00465ac4     MOV        EAX,dword ptr [this->_padding_]
//         00465ac6     CALL       dword ptr [EAX + 0x20]
//         00465ac9     MOV        ESI,dword ptr [ESI + 0x8]
//         00465acc     TEST       ESI,ESI
//         00465ace     JNZ        LAB_00465abe
//                               LAB_00465ad0                                                 XREF[1]:     00465abc(j)
//                              Panel.cpp:1686 (14)
//         00465ad0     MOV        this,dword ptr [EDI + 0x40]
//         00465ad3     TEST       this,this
//         00465ad5     JZ         LAB_00465ae9
//         00465ad7     MOV        EAX,dword ptr [ECX + this->overlapping_children]
//         00465ada     TEST       EAX,EAX
//         00465adc     JZ         LAB_00465ae9
//                              Panel.cpp:1687 (11)
//         00465ade     MOV        EDX,dword ptr [EDI + 0x38]
//         00465ae1     MOV        EAX,dword ptr [this->_padding_]
//         00465ae3     PUSH       EDX
//         00465ae4     PUSH       EDI=>DAT_fffffff8
//         00465ae5     PUSH       EDI=>DAT_fffffff4
//         00465ae6     CALL       dword ptr [EAX + 0x24]
//                               LAB_00465ae9                                                 XREF[2]:     00465ad5(j), 00465adc(j)
//                              Panel.cpp:1688 (7)
//         00465ae9     MOV        EAX,dword ptr [EDI]
//         00465aeb     MOV        this,EDI
//         00465aed     CALL       dword ptr [EAX + 0x30]
//                              Panel.cpp:1689 (7)
//         00465af0     MOV        dword ptr [EDI + 0x38],0x0
//                              Panel.cpp:1690 (10)
//         00465af7     MOV        dword ptr [EDI + 0x84],0x1
//                               LAB_00465b01                                                 XREF[1]:     00465ab5(j)
//                              Panel.cpp:1694 (7)
//         00465b01     MOV        ESI,dword ptr [EDI + 0x58]
//         00465b04     TEST       ESI,ESI
//         00465b06     JZ         LAB_00465b16
//                               LAB_00465b08                                                 XREF[1]:     00465b14(j)
//                              Panel.cpp:1695 (14)
//         00465b08     MOV        this,dword ptr [ESI]
//         00465b0a     MOV        EDX,dword ptr [this->_padding_]
//         00465b0c     CALL       dword ptr [EDX + 0x54]
//         00465b0f     MOV        ESI,dword ptr [ESI + 0x8]
//         00465b12     TEST       ESI,ESI
//         00465b14     JNZ        LAB_00465b08
//                               LAB_00465b16                                                 XREF[1]:     00465b06(j)
//                              Panel.cpp:1697 (10)
//         00465b16     MOV        dword ptr [EDI + 0x84],0x0
//                               LAB_00465b20                                                 XREF[5]:     00465a79(j), 00465a84(j),
//                                                                                                         00465a8f(j), 00465aa0(j),
//                                                                                                         00465aae(j)
//                              Panel.cpp:1700 (5)
//         00465b20     POP        EDI
//         00465b21     XOR        EAX,EAX
//         00465b23     POP        ESI
//         00465b24     RET
//         00465b25     ??         90h
//         00465b26     NOP
//         00465b27     NOP
//         00465b28     NOP
//         00465b29     NOP
//         00465b2a     NOP
//         00465b2b     NOP
//         00465b2c     NOP
//         00465b2d     NOP
//         00465b2e     NOP
//         00465b2f     NOP
    return 0;
}

long TPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_key_down(TPanel * this, long param_1, short p
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00465b5e(R), 00465b84(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00465b4f(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00465b4b(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00465b47(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     00465b57(R), 00465b7a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00465b3a(W)
//                               ?handle_key_down@TPanel@@UAEJJFHHH@Z                         XREF[71]:    handle_key_down:004736d8(c),
//                               TPanel::handle_key_down                                                   handle_key_down:00474492(c),
//                                                                                                         0056f560(*), 0056f668(*),
//                                                                                                         0056f7a8(*), 0056f8f0(*),
//                                                                                                         0056fa20(*), 0056fb50(*),
//                                                                                                         0056fc88(*), 0056fdb8(*),
//                                                                                                         0056fee8(*), 00570018(*),
//                                                                                                         00570148(*), 00570c90(*),
//                                                                                                         00570d70(*), 00571108(*),
//                                                                                                         00571400(*), 005714e0(*),
//                                                                                                         005715d0(*), 005716c0(*), [more]
//                              Panel.cpp:1706 (1)
//         00465b30     PUSH       this
//                              Panel.cpp:1710 (13)
//         00465b31     MOV        EAX,dword ptr [ECX + this->have_focus]
//         00465b34     PUSH       EBX
//         00465b35     PUSH       EBP
//         00465b36     PUSH       ESI
//         00465b37     TEST       EAX,EAX
//         00465b39     PUSH       EDI
//         00465b3a     MOV        dword ptr [ESP + local_4],this
//                              Panel.cpp:1711 (6)
//         00465b3e     JZ         LAB_00465bd5
//                              Panel.cpp:1714 (19)
//         00465b44     MOV        ESI,dword ptr [ECX + this->last_child_node]
//         00465b47     MOV        EBX,dword ptr [ESP + param_4]
//         00465b4b     MOV        EDI,dword ptr [ESP + param_3]
//         00465b4f     MOV        EBP,dword ptr [ESP + param_2]
//         00465b53     TEST       ESI,ESI
//         00465b55     JZ         LAB_00465b7a
//                               LAB_00465b57                                                 XREF[1]:     00465b74(j)
//                              Panel.cpp:1716 (20)
//         00465b57     MOV        EDX,dword ptr [ESP + param_5]
//         00465b5b     MOV        this,dword ptr [ESI]
//         00465b5d     PUSH       EDX
//         00465b5e     MOV        EDX,dword ptr [ESP + param_1]
//         00465b62     MOV        EAX,dword ptr [this->_padding_]
//         00465b64     PUSH       EBX=>DAT_fffffff8
//         00465b65     PUSH       EDI=>DAT_fffffff4
//         00465b66     PUSH       EBP=>DAT_fffffff0
//         00465b67     PUSH       EDX
//         00465b68     CALL       dword ptr [EAX + 0x58]
//                              Panel.cpp:1717 (11)
//         00465b6b     TEST       EAX,EAX
//         00465b6d     JNZ        LAB_00465bd7
//         00465b6f     MOV        ESI,dword ptr [ESI + 0x4]
//         00465b72     TEST       ESI,ESI
//         00465b74     JNZ        LAB_00465b57
//                              Panel.cpp:1714 (4)
//         00465b76     MOV        this,dword ptr [ESP + 0x10]
//                               LAB_00465b7a                                                 XREF[1]:     00465b55(j)
//                              Panel.cpp:1721 (21)
//         00465b7a     MOV        ESI,dword ptr [ESP + param_5]
//         00465b7e     MOV        EAX,dword ptr [this->_padding_]
//         00465b80     PUSH       ESI
//         00465b81     PUSH       EBX=>DAT_fffffff8
//         00465b82     PUSH       EDI=>DAT_fffffff4
//         00465b83     PUSH       EBP=>DAT_fffffff0
//         00465b84     MOV        EBP,dword ptr [ESP + param_1]
//         00465b88     PUSH       EBP
//         00465b89     CALL       dword ptr [EAX + 0xac]
//                              Panel.cpp:1722 (2)
//         00465b8f     TEST       EAX,EAX
//                              Panel.cpp:1723 (2)
//         00465b91     JNZ        LAB_00465bd7
//                              Panel.cpp:1725 (31)
//         00465b93     TEST       EDI,EDI
//         00465b95     JNZ        LAB_00465bd5
//         00465b97     TEST       EBX,EBX
//         00465b99     JNZ        LAB_00465bd5
//         00465b9b     CMP        EBP,0x9
//         00465b9e     JNZ        LAB_00465bd5
//         00465ba0     MOV        EAX,dword ptr [ESP + 0x10]
//         00465ba4     MOV        this,dword ptr [EAX + 0x74]
//         00465ba7     TEST       this,this
//         00465ba9     JZ         LAB_00465bd5
//         00465bab     MOV        this,dword ptr [EAX + 0x40]
//         00465bae     TEST       this,this
//         00465bb0     JZ         LAB_00465bd5
//                              Panel.cpp:1727 (4)
//         00465bb2     TEST       ESI,ESI
//         00465bb4     JZ         LAB_00465bbb
//                              Panel.cpp:1729 (3)
//         00465bb6     MOV        EAX,dword ptr [EAX + 0x60]
//                              Panel.cpp:1732 (2)
//         00465bb9     JMP        LAB_00465bbe
//                               LAB_00465bbb                                                 XREF[1]:     00465bb4(j)
//                              Panel.cpp:1737 (7)
//         00465bbb     MOV        EAX,dword ptr [EAX + 0x64]
//                               LAB_00465bbe                                                 XREF[1]:     00465bb9(j)
//         00465bbe     TEST       EAX,EAX
//         00465bc0     JZ         LAB_00465bd5
//                              Panel.cpp:1739 (6)
//         00465bc2     PUSH       EAX
//         00465bc3     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              Panel.cpp:1740 (5)
//         00465bc8     MOV        EAX,0x1
//                              Panel.cpp:1746 (8)
//         00465bcd     POP        EDI
//         00465bce     POP        ESI
//         00465bcf     POP        EBP
//         00465bd0     POP        EBX
//         00465bd1     POP        this
//         00465bd2     RET        0x14
//                               LAB_00465bd5                                                 XREF[7]:     00465b3e(j), 00465b95(j),
//                                                                                                         00465b99(j), 00465b9e(j),
//                                                                                                         00465ba9(j), 00465bb0(j),
//                                                                                                         00465bc0(j)
//                              Panel.cpp:1745 (2)
//         00465bd5     XOR        EAX,EAX
//                               LAB_00465bd7                                                 XREF[2]:     00465b6d(j), 00465b91(j)
//                              Panel.cpp:1746 (8)
//         00465bd7     POP        EDI
//         00465bd8     POP        ESI
//         00465bd9     POP        EBP
//         00465bda     POP        EBX
//         00465bdb     POP        this
//         00465bdc     RET        0x14
//         00465bdf     ??         90h
    return 0;
}

long TPanel::handle_char(long param_1, short param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_char(TPanel * this, long param_1, short param
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00465bf9(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00465bfd(R)
//                               ?handle_char@TPanel@@UAEJJF@Z                                XREF[73]:    0056f564(*), 0056f66c(*),
//                               TPanel::handle_char                                                       0056f7ac(*), 0056f8f4(*),
//                                                                                                         0056fa24(*), 0056fb54(*),
//                                                                                                         0056fc8c(*), 0056fdbc(*),
//                                                                                                         0056feec(*), 0057001c(*),
//                                                                                                         0057014c(*), 00570c94(*),
//                                                                                                         00570d74(*), 00571024(*),
//                                                                                                         0057110c(*), 0057123c(*),
//                                                                                                         0057131c(*), 00571404(*),
//                                                                                                         005714e4(*), 005715d4(*), [more]
//                              Panel.cpp:1752 (6)
//         00465be0     PUSH       EBX
//         00465be1     PUSH       EBP
//         00465be2     MOV        EBP,this
//         00465be4     PUSH       ESI
//         00465be5     PUSH       EDI
//                              Panel.cpp:1756 (7)
//         00465be6     MOV        EAX,dword ptr [EBP + 0x78]
//         00465be9     TEST       EAX,EAX
//         00465beb     JNZ        LAB_00465bf6
//                              Panel.cpp:1757 (2)
//         00465bed     XOR        EAX,EAX
//                              Panel.cpp:1768 (7)
//         00465bef     POP        EDI
//         00465bf0     POP        ESI
//         00465bf1     POP        EBP
//         00465bf2     POP        EBX
//         00465bf3     RET        0x8
//                               LAB_00465bf6                                                 XREF[1]:     00465beb(j)
//                              Panel.cpp:1760 (15)
//         00465bf6     MOV        ESI,dword ptr [EBP + 0x5c]
//         00465bf9     MOV        EDI,dword ptr [ESP + param_1]
//         00465bfd     MOV        EBX,dword ptr [ESP + param_2]
//         00465c01     TEST       ESI,ESI
//         00465c03     JZ         LAB_00465c19
//                               LAB_00465c05                                                 XREF[1]:     00465c17(j)
//                              Panel.cpp:1762 (9)
//         00465c05     MOV        this,dword ptr [ESI]
//         00465c07     PUSH       EBX
//         00465c08     PUSH       EDI=>DAT_fffffff8
//         00465c09     MOV        EAX,dword ptr [this->_padding_]
//         00465c0b     CALL       dword ptr [EAX + 0x5c]
//                              Panel.cpp:1763 (11)
//         00465c0e     TEST       EAX,EAX
//         00465c10     JNZ        LAB_00465c26
//         00465c12     MOV        ESI,dword ptr [ESI + 0x4]
//         00465c15     TEST       ESI,ESI
//         00465c17     JNZ        LAB_00465c05
//                               LAB_00465c19                                                 XREF[1]:     00465c03(j)
//                              Panel.cpp:1767 (13)
//         00465c19     MOV        EDX,dword ptr [EBP]
//         00465c1c     PUSH       EBX
//         00465c1d     PUSH       EDI=>DAT_fffffff8
//         00465c1e     MOV        this,EBP
//         00465c20     CALL       dword ptr [EDX + 0xb0]
//                               LAB_00465c26                                                 XREF[1]:     00465c10(j)
//                              Panel.cpp:1768 (7)
//         00465c26     POP        EDI
//         00465c27     POP        ESI
//         00465c28     POP        EBP
//         00465c29     POP        EBX
//         00465c2a     RET        0x8
//         00465c2d     ??         90h
//         00465c2e     NOP
//         00465c2f     NOP
    return 0;
}

long TPanel::handle_command(uint param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_command(TPanel * this, uint param_1, long par
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//                               ?handle_command@TPanel@@UAEJIJ@Z                             XREF[73]:    0056f568(*), 0056f670(*),
//                               TPanel::handle_command                                                    0056f7b0(*), 0056f8f8(*),
//                                                                                                         0056fa28(*), 0056fb58(*),
//                                                                                                         0056fc90(*), 0056fdc0(*),
//                                                                                                         0056fef0(*), 00570020(*),
//                                                                                                         00570150(*), 00570c98(*),
//                                                                                                         00570d78(*), 00571028(*),
//                                                                                                         00571110(*), 00571240(*),
//                                                                                                         00571320(*), 00571408(*),
//                                                                                                         005714e8(*), 005715d8(*), [more]
//                              Panel.cpp:1774 (2)
//         00465c30     XOR        EAX,EAX
//                              Panel.cpp:1776 (3)
//         00465c32     RET        0x8
//         00465c35     ??         90h
//         00465c36     NOP
//         00465c37     NOP
//         00465c38     NOP
//         00465c39     NOP
//         00465c3a     NOP
//         00465c3b     NOP
//         00465c3c     NOP
//         00465c3d     NOP
//         00465c3e     NOP
//         00465c3f     NOP
    return 0;
}

long TPanel::handle_user_command(uint param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_user_command(TPanel * this, uint param_1, lon
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//                               ?handle_user_command@TPanel@@UAEJIJ@Z                        XREF[71]:    handle_user_command:00491c2b(c),
//                               TPanel::handle_user_command                                               handle_user_command:0049728a(c),
//                                                                                                         handle_user_command:004b5c96(c),
//                                                                                                         0056f56c(*), 0056f674(*),
//                                                                                                         0056f7b4(*), 0056f8fc(*),
//                                                                                                         0056fa2c(*), 0056fb5c(*),
//                                                                                                         0056fc94(*), 0056fdc4(*),
//                                                                                                         0056fef4(*), 00570024(*),
//                                                                                                         00570154(*), 00570c9c(*),
//                                                                                                         00570d7c(*), 0057102c(*),
//                                                                                                         00571114(*), 00571244(*),
//                                                                                                         00571324(*), [more]
//                              Panel.cpp:1783 (2)
//         00465c40     XOR        EAX,EAX
//                              Panel.cpp:1785 (3)
//         00465c42     RET        0x8
//         00465c45     ??         90h
//         00465c46     NOP
//         00465c47     NOP
//         00465c48     NOP
//         00465c49     NOP
//         00465c4a     NOP
//         00465c4b     NOP
//         00465c4c     NOP
//         00465c4d     NOP
//         00465c4e     NOP
//         00465c4f     NOP
    return 0;
}

long TPanel::handle_timer_command(uint param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_timer_command(TPanel * this, uint param_1, lo
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//                               ?handle_timer_command@TPanel@@UAEJIJ@Z                       XREF[72]:    0056f570(*), 0056f678(*),
//                               TPanel::handle_timer_command                                              0056f7b8(*), 0056f900(*),
//                                                                                                         0056fa30(*), 0056fb60(*),
//                                                                                                         0056fc98(*), 0056fdc8(*),
//                                                                                                         0056fef8(*), 00570028(*),
//                                                                                                         00570158(*), 00570ca0(*),
//                                                                                                         00570d80(*), 00571030(*),
//                                                                                                         00571118(*), 00571248(*),
//                                                                                                         00571328(*), 00571410(*),
//                                                                                                         005714f0(*), 005715e0(*), [more]
//                              Panel.cpp:1792 (2)
//         00465c50     XOR        EAX,EAX
//                              Panel.cpp:1794 (3)
//         00465c52     RET        0x8
//         00465c55     ??         90h
//         00465c56     NOP
//         00465c57     NOP
//         00465c58     NOP
//         00465c59     NOP
//         00465c5a     NOP
//         00465c5b     NOP
//         00465c5c     NOP
//         00465c5d     NOP
//         00465c5e     NOP
//         00465c5f     NOP
    return 0;
}

long TPanel::handle_scroll(long param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_scroll(TPanel * this, long param_1, long para
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//                               ?handle_scroll@TPanel@@UAEJJJ@Z                              XREF[73]:    0056f574(*), 0056f67c(*),
//                               TPanel::handle_scroll                                                     0056f7bc(*), 0056f904(*),
//                                                                                                         0056fa34(*), 0056fb64(*),
//                                                                                                         0056fc9c(*), 0056fdcc(*),
//                                                                                                         0056fefc(*), 0057002c(*),
//                                                                                                         0057015c(*), 00570ca4(*),
//                                                                                                         00570d84(*), 00571034(*),
//                                                                                                         0057111c(*), 0057124c(*),
//                                                                                                         0057132c(*), 00571414(*),
//                                                                                                         005714f4(*), 005715e4(*), [more]
//                              Panel.cpp:1800 (2)
//         00465c60     XOR        EAX,EAX
//                              Panel.cpp:1802 (3)
//         00465c62     RET        0x8
//         00465c65     ??         90h
//         00465c66     NOP
//         00465c67     NOP
//         00465c68     NOP
//         00465c69     NOP
//         00465c6a     NOP
//         00465c6b     NOP
//         00465c6c     NOP
//         00465c6d     NOP
//         00465c6e     NOP
//         00465c6f     NOP
    return 0;
}

long TPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_down(TPanel * this, uchar param_1, long
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00465c8d(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00465c89(R)
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00465d59(R)
//                               ?handle_mouse_down@TPanel@@UAEJEJJHH@Z                       XREF[26]:    handle_mouse_down:004679d9(c),
//                               TPanel::handle_mouse_down                                                 handle_mouse_down:00473174(c),
//                                                                                                         handle_mouse_down:004743e6(c),
//                                                                                                         handle_mouse_down:00476bf9(c),
//                                                                                                         handle_mouse_down:0053d3f4(c),
//                                                                                                         0056f578(*), 00570ca8(*),
//                                                                                                         005714f8(*), 005715e8(*),
//                                                                                                         005717c0(*), 005718a0(*),
//                                                                                                         00571aa8(*), 00571b88(*),
//                                                                                                         00571c68(*), 00571fd0(*),
//                                                                                                         005720b0(*), 005728e8(*),
//                                                                                                         00572b18(*), 005744b0(*),
//                                                                                                         00576c28(*), [more]
//                              Panel.cpp:1808 (6)
//         00465c70     PUSH       EBX
//         00465c71     PUSH       EBP
//         00465c72     PUSH       ESI
//         00465c73     MOV        ESI,this
//         00465c75     PUSH       EDI
//                              Panel.cpp:1812 (7)
//         00465c76     MOV        EAX,dword ptr [ESI + 0x6c]
//         00465c79     TEST       EAX,EAX
//         00465c7b     JNZ        LAB_00465c86
//                              Panel.cpp:1813 (2)
//         00465c7d     XOR        EAX,EAX
//                              Panel.cpp:1851 (7)
//         00465c7f     POP        EDI
//         00465c80     POP        ESI
//         00465c81     POP        EBP
//         00465c82     POP        EBX
//         00465c83     RET        0x14
//                               LAB_00465c86                                                 XREF[1]:     00465c7b(j)
//                              Panel.cpp:1815 (19)
//         00465c86     MOV        EAX,dword ptr [ESI + 0x68]
//         00465c89     MOV        EBP,dword ptr [ESP + param_3]
//         00465c8d     MOV        EBX,dword ptr [ESP + param_2]
//         00465c91     TEST       EAX,EAX
//         00465c93     JNZ        LAB_00465d59
//                              Panel.cpp:1817 (16)
//         00465c99     MOV        EAX,dword ptr [ESI]
//         00465c9b     PUSH       EBP
//         00465c9c     PUSH       EBX
//         00465c9d     MOV        this,ESI
//         00465c9f     CALL       dword ptr [EAX + 0xbc]
//         00465ca5     TEST       EAX,EAX
//         00465ca7     JNZ        LAB_00465cb0
//                              Panel.cpp:1851 (7)
//         00465ca9     POP        EDI
//         00465caa     POP        ESI
//         00465cab     POP        EBP
//         00465cac     POP        EBX
//         00465cad     RET        0x14
//                               LAB_00465cb0                                                 XREF[1]:     00465ca7(j)
//                              Panel.cpp:1821 (7)
//         00465cb0     MOV        EDI,dword ptr [ESI + 0x5c]
//         00465cb3     TEST       EDI,EDI
//         00465cb5     JZ         LAB_00465cde
//                               LAB_00465cb7                                                 XREF[1]:     00465cdc(j)
//                              Panel.cpp:1823 (24)
//         00465cb7     MOV        EAX,dword ptr [ESP + 0x24]
//         00465cbb     MOV        this,dword ptr [EDI]
//         00465cbd     PUSH       EAX
//         00465cbe     MOV        EAX,dword ptr [ESP + 0x24]
//         00465cc2     MOV        EDX,dword ptr [this->_padding_]
//         00465cc4     PUSH       EAX=>DAT_fffffff8
//         00465cc5     MOV        EAX,dword ptr [ESP + 0x1c]
//         00465cc9     PUSH       EBP=>DAT_fffffff4
//         00465cca     PUSH       EBX=>DAT_fffffff0
//         00465ccb     PUSH       EAX
//         00465ccc     CALL       dword ptr [EDX + 0x70]
//                              Panel.cpp:1824 (15)
//         00465ccf     TEST       EAX,EAX
//         00465cd1     JNZ        LAB_00465dae
//         00465cd7     MOV        EDI,dword ptr [EDI + 0x4]
//         00465cda     TEST       EDI,EDI
//         00465cdc     JNZ        LAB_00465cb7
//                               LAB_00465cde                                                 XREF[1]:     00465cb5(j)
//                              Panel.cpp:1828 (10)
//         00465cde     MOV        EAX,dword ptr [ESI + 0x80]
//         00465ce4     TEST       EAX,EAX
//         00465ce6     JNZ        LAB_00465cf1
//                              Panel.cpp:1829 (2)
//         00465ce8     XOR        EAX,EAX
//                              Panel.cpp:1851 (7)
//         00465cea     POP        EDI
//         00465ceb     POP        ESI
//         00465cec     POP        EBP
//         00465ced     POP        EBX
//         00465cee     RET        0x14
//                               LAB_00465cf1                                                 XREF[1]:     00465ce6(j)
//                              Panel.cpp:1831 (4)
//         00465cf1     MOV        this,byte ptr [ESP + 0x14]
//                              Panel.cpp:1834 (4)
//         00465cf5     MOV        EDX,dword ptr [ESP + 0x20]
//                              Panel.cpp:1835 (4)
//         00465cf9     MOV        EDI,dword ptr [ESP + 0x24]
//                              Panel.cpp:1836 (51)
//         00465cfd     PUSH       0x72c
//         00465d02     PUSH       s_C:\msdev\work\age1_x1\Panel.cpp                = "C:\\msdev\\work\\age1_x1\\Panel.cpp"
//         00465d07     MOV        byte ptr [ESI + 0xed],this
//         00465d0d     MOV        dword ptr [ESI + 0xc4],EBX
//         00465d13     MOV        dword ptr [ESI + 0xc8],EBP
//         00465d19     MOV        dword ptr [ESI + 0xcc],EDX
//         00465d1f     MOV        dword ptr [ESI + 0xd0],EDI
//         00465d25     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00465d2a     MOV        dword ptr [ESI + 0xd4],EAX
//                              Panel.cpp:1839 (33)
//         00465d30     MOV        EAX,dword ptr [ESI + 0x74]
//         00465d33     ADD        ESP,0x8
//         00465d36     MOV        byte ptr [ESI + 0xec],0x1
//         00465d3d     TEST       EAX,EAX
//         00465d3f     JZ         LAB_00465d5d
//         00465d41     MOV        this,dword ptr [ESI + 0x40]
//         00465d44     TEST       this,this
//         00465d46     JZ         LAB_00465d5d
//         00465d48     CMP        byte ptr [ESI + 0xed],0x1
//         00465d4f     JNZ        LAB_00465d5d
//                              Panel.cpp:1840 (12)
//         00465d51     PUSH       ESI
//         00465d52     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//         00465d57     JMP        LAB_00465d5d
//                               LAB_00465d59                                                 XREF[1]:     00465c93(j)
//         00465d59     MOV        EDI,dword ptr [ESP + param_5]
//                               LAB_00465d5d                                                 XREF[4]:     00465d3f(j), 00465d46(j),
//                                                                                                         00465d4f(j), 00465d57(j)
//                              Panel.cpp:1843 (10)
//         00465d5d     MOV        EAX,dword ptr [ESI + 0x80]
//         00465d63     TEST       EAX,EAX
//         00465d65     JNZ        LAB_00465d70
//                              Panel.cpp:1844 (2)
//         00465d67     XOR        EAX,EAX
//                              Panel.cpp:1851 (7)
//         00465d69     POP        EDI
//         00465d6a     POP        ESI
//         00465d6b     POP        EBP
//         00465d6c     POP        EBX
//         00465d6d     RET        0x14
//                               LAB_00465d70                                                 XREF[1]:     00465d65(j)
//                              Panel.cpp:1846 (9)
//         00465d70     CMP        byte ptr [ESI + 0xed],0x1
//         00465d77     JNZ        LAB_00465d97
//                              Panel.cpp:1847 (18)
//         00465d79     MOV        this,dword ptr [ESP + 0x20]
//         00465d7d     MOV        EAX,dword ptr [ESI]
//         00465d7f     PUSH       EDI
//         00465d80     PUSH       this=>DAT_fffffff8
//         00465d81     PUSH       EBP=>DAT_fffffff4
//         00465d82     PUSH       EBX=>DAT_fffffff0
//         00465d83     MOV        this,ESI
//         00465d85     CALL       dword ptr [EAX + 0x84]
//                              Panel.cpp:1850 (5)
//         00465d8b     MOV        EAX,0x1
//                              Panel.cpp:1851 (7)
//         00465d90     POP        EDI
//         00465d91     POP        ESI
//         00465d92     POP        EBP
//         00465d93     POP        EBX
//         00465d94     RET        0x14
//                               LAB_00465d97                                                 XREF[1]:     00465d77(j)
//                              Panel.cpp:1849 (18)
//         00465d97     MOV        EAX,dword ptr [ESP + 0x20]
//         00465d9b     MOV        EDX,dword ptr [ESI]
//         00465d9d     PUSH       EDI
//         00465d9e     PUSH       EAX=>DAT_fffffff8
//         00465d9f     PUSH       EBP=>DAT_fffffff4
//         00465da0     PUSH       EBX=>DAT_fffffff0
//         00465da1     MOV        this,ESI
//         00465da3     CALL       dword ptr [EDX + 0x98]
//                              Panel.cpp:1850 (5)
//         00465da9     MOV        EAX,0x1
//                               LAB_00465dae                                                 XREF[1]:     00465cd1(j)
//                              Panel.cpp:1851 (7)
//         00465dae     POP        EDI
//         00465daf     POP        ESI
//         00465db0     POP        EBP
//         00465db1     POP        EBX
//         00465db2     RET        0x14
//         00465db5     ??         90h
//         00465db6     NOP
//         00465db7     NOP
//         00465db8     NOP
//         00465db9     NOP
//         00465dba     NOP
//         00465dbb     NOP
//         00465dbc     NOP
//         00465dbd     NOP
//         00465dbe     NOP
//         00465dbf     NOP
    return 0;
}

long TPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_move(TPanel * this, long param_1, long
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00465de7(R), 00465e82(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00465de3(R), 00465e7e(R)
//              int               Stack[0xc]:4   param_3                   XREF[2]:     00465f0d(R), 00465f30(R)
//              int               Stack[0x10]:4  param_4                   XREF[2]:     00465f09(R), 00465f2c(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00465df1(W)
//                               ?handle_mouse_move@TPanel@@UAEJJJHH@Z                        XREF[72]:    handle_mouse_move:00474414(c),
//                               TPanel::handle_mouse_move                                                 handle_mouse_move:004755b1(c),
//                                                                                                         0056f57c(*), 0056f684(*),
//                                                                                                         0056f7c4(*), 0056f90c(*),
//                                                                                                         0056fa3c(*), 0056fb6c(*),
//                                                                                                         0056fca4(*), 0056fdd4(*),
//                                                                                                         0056ff04(*), 00570034(*),
//                                                                                                         00570164(*), 00570cac(*),
//                                                                                                         00570d8c(*), 0057103c(*),
//                                                                                                         00571124(*), 0057141c(*),
//                                                                                                         005714fc(*), 005715ec(*), [more]
//                              Panel.cpp:1857 (7)
//         00465dc0     PUSH       this
//         00465dc1     PUSH       EBX
//         00465dc2     PUSH       EBP
//         00465dc3     PUSH       ESI
//         00465dc4     PUSH       EDI
//         00465dc5     MOV        EDI,this
//                              Panel.cpp:1861 (7)
//         00465dc7     MOV        EAX,dword ptr [EDI + 0x6c]
//         00465dca     TEST       EAX,EAX
//         00465dcc     JNZ        LAB_00465dd8
//                              Panel.cpp:1862 (2)
//         00465dce     XOR        EAX,EAX
//                              Panel.cpp:1913 (8)
//         00465dd0     POP        EDI
//         00465dd1     POP        ESI
//         00465dd2     POP        EBP
//         00465dd3     POP        EBX
//         00465dd4     POP        this
//         00465dd5     RET        0x10
//                               LAB_00465dd8                                                 XREF[1]:     00465dcc(j)
//                              Panel.cpp:1864 (11)
//         00465dd8     MOV        EAX,dword ptr [EDI + 0x68]
//         00465ddb     TEST       EAX,EAX
//         00465ddd     JNZ        LAB_00465e64
//                              Panel.cpp:1866 (28)
//         00465de3     MOV        EBX,dword ptr [ESP + param_2]
//         00465de7     MOV        EBP,dword ptr [ESP + param_1]
//         00465deb     MOV        EAX,dword ptr [EDI]
//         00465ded     PUSH       EBX
//         00465dee     PUSH       EBP
//         00465def     MOV        this,EDI
//         00465df1     MOV        dword ptr [ESP + local_4],EAX
//         00465df5     CALL       dword ptr [EAX + 0xbc]
//         00465dfb     TEST       EAX,EAX
//         00465dfd     JNZ        LAB_00465e07
//                              Panel.cpp:1913 (8)
//         00465dff     POP        EDI
//         00465e00     POP        ESI
//         00465e01     POP        EBP
//         00465e02     POP        EBX
//         00465e03     POP        this
//         00465e04     RET        0x10
//                               LAB_00465e07                                                 XREF[1]:     00465dfd(j)
//                              Panel.cpp:1870 (7)
//         00465e07     MOV        ESI,dword ptr [EDI + 0x5c]
//         00465e0a     TEST       ESI,ESI
//         00465e0c     JZ         LAB_00465e30
//                               LAB_00465e0e                                                 XREF[1]:     00465e2e(j)
//                              Panel.cpp:1872 (19)
//         00465e0e     MOV        EDX,dword ptr [ESP + 0x24]
//         00465e12     MOV        this,dword ptr [ESI]
//         00465e14     PUSH       EDX
//         00465e15     MOV        EDX,dword ptr [ESP + 0x24]
//         00465e19     MOV        EAX,dword ptr [this->_padding_]
//         00465e1b     PUSH       EDX=>DAT_fffffff8
//         00465e1c     PUSH       EBX=>DAT_fffffff4
//         00465e1d     PUSH       EBP=>DAT_fffffff0
//         00465e1e     CALL       dword ptr [EAX + 0x74]
//                              Panel.cpp:1873 (15)
//         00465e21     TEST       EAX,EAX
//         00465e23     JNZ        LAB_00465f5e
//         00465e29     MOV        ESI,dword ptr [ESI + 0x4]
//         00465e2c     TEST       ESI,ESI
//         00465e2e     JNZ        LAB_00465e0e
//                               LAB_00465e30                                                 XREF[1]:     00465e0c(j)
//                              Panel.cpp:1877 (10)
//         00465e30     MOV        EAX,dword ptr [EDI + 0x80]
//         00465e36     TEST       EAX,EAX
//         00465e38     JNZ        LAB_00465e44
//                              Panel.cpp:1878 (2)
//         00465e3a     XOR        EAX,EAX
//                              Panel.cpp:1913 (8)
//         00465e3c     POP        EDI
//         00465e3d     POP        ESI
//         00465e3e     POP        EBP
//         00465e3f     POP        EBX
//         00465e40     POP        this
//         00465e41     RET        0x10
//                               LAB_00465e44                                                 XREF[1]:     00465e38(j)
//                              Panel.cpp:1880 (24)
//         00465e44     MOV        EAX,dword ptr [ESP + 0x24]
//         00465e48     MOV        this,dword ptr [ESP + 0x20]
//         00465e4c     MOV        EDX,dword ptr [ESP + 0x10]
//         00465e50     PUSH       EAX
//         00465e51     PUSH       this=>DAT_fffffff8
//         00465e52     PUSH       EBX=>DAT_fffffff4
//         00465e53     PUSH       EBP=>DAT_fffffff0
//         00465e54     MOV        this,EDI
//         00465e56     CALL       dword ptr [EDX + 0x80]
//                              Panel.cpp:1913 (8)
//         00465e5c     POP        EDI
//         00465e5d     POP        ESI
//         00465e5e     POP        EBP
//         00465e5f     POP        EBX
//         00465e60     POP        this
//         00465e61     RET        0x10
//                               LAB_00465e64                                                 XREF[1]:     00465ddd(j)
//                              Panel.cpp:1883 (10)
//         00465e64     MOV        EAX,dword ptr [EDI + 0x80]
//         00465e6a     TEST       EAX,EAX
//         00465e6c     JNZ        LAB_00465e78
//                              Panel.cpp:1884 (2)
//         00465e6e     XOR        EAX,EAX
//                              Panel.cpp:1913 (8)
//         00465e70     POP        EDI
//         00465e71     POP        ESI
//         00465e72     POP        EBP
//         00465e73     POP        EBX
//         00465e74     POP        this
//         00465e75     RET        0x10
//                               LAB_00465e78                                                 XREF[1]:     00465e6c(j)
//                              Panel.cpp:1886 (22)
//         00465e78     MOV        AL,byte ptr [EDI + 0xec]
//         00465e7e     MOV        ESI,dword ptr [ESP + param_2]
//         00465e82     MOV        EBX,dword ptr [ESP + param_1]
//         00465e86     CMP        AL,0x1
//         00465e88     JZ         LAB_00465e8e
//         00465e8a     CMP        AL,0x2
//         00465e8c     JNZ        LAB_00465ef8
//                               LAB_00465e8e                                                 XREF[1]:     00465e88(j)
//                              Panel.cpp:1889 (9)
//         00465e8e     CMP        byte ptr [EDI + 0xed],0x1
//         00465e95     JNZ        LAB_00465ed0
//                              Panel.cpp:1892 (44)
//         00465e97     MOV        EDX,dword ptr [EDI + 0xc4]
//         00465e9d     MOV        EAX,EBX
//         00465e9f     MOV        this,dword ptr [EDI + 0xc0]
//         00465ea5     SUB        EAX,EDX
//         00465ea7     CDQ
//         00465ea8     XOR        EAX,EDX
//         00465eaa     SUB        EAX,EDX
//         00465eac     CMP        EAX,this
//         00465eae     JG         LAB_00465ef8
//         00465eb0     MOV        EDX,dword ptr [EDI + 0xc8]
//         00465eb6     MOV        EAX,ESI
//         00465eb8     SUB        EAX,EDX
//         00465eba     CDQ
//         00465ebb     XOR        EAX,EDX
//         00465ebd     SUB        EAX,EDX
//         00465ebf     CMP        EAX,this
//         00465ec1     JG         LAB_00465ef8
//                              Panel.cpp:1912 (5)
//         00465ec3     MOV        EAX,0x1
//                              Panel.cpp:1913 (8)
//         00465ec8     POP        EDI
//         00465ec9     POP        ESI
//         00465eca     POP        EBP
//         00465ecb     POP        EBX
//         00465ecc     POP        this
//         00465ecd     RET        0x10
//                               LAB_00465ed0                                                 XREF[1]:     00465e95(j)
//                              Panel.cpp:1900 (38)
//         00465ed0     MOV        EDX,dword ptr [EDI + 0xc4]
//         00465ed6     MOV        EAX,EBX
//         00465ed8     SUB        EAX,EDX
//         00465eda     CDQ
//         00465edb     XOR        EAX,EDX
//         00465edd     SUB        EAX,EDX
//         00465edf     CMP        EAX,0xa
//         00465ee2     JG         LAB_00465ef8
//         00465ee4     MOV        EDX,dword ptr [EDI + 0xc8]
//         00465eea     MOV        EAX,ESI
//         00465eec     SUB        EAX,EDX
//         00465eee     CDQ
//         00465eef     XOR        EAX,EDX
//         00465ef1     SUB        EAX,EDX
//         00465ef3     CMP        EAX,0xa
//                              Panel.cpp:1901 (2)
//         00465ef6     JLE        LAB_00465f59
//                               LAB_00465ef8                                                 XREF[4]:     00465e8c(j), 00465eae(j),
//                                                                                                         00465ec1(j), 00465ee2(j)
//                              Panel.cpp:1906 (17)
//         00465ef8     MOV        AL,byte ptr [EDI + 0xed]
//         00465efe     MOV        byte ptr [EDI + 0xec],0x3
//         00465f05     CMP        AL,0x1
//         00465f07     JNZ        LAB_00465f2c
//                              Panel.cpp:1907 (22)
//         00465f09     MOV        this,dword ptr [ESP + param_4]
//         00465f0d     MOV        EDX,dword ptr [ESP + param_3]
//         00465f11     MOV        EAX,dword ptr [EDI]
//         00465f13     PUSH       this
//         00465f14     PUSH       EDX
//         00465f15     PUSH       ESI
//         00465f16     PUSH       EBX
//         00465f17     MOV        this,EDI
//         00465f19     CALL       dword ptr [EAX + 0x8c]
//                              Panel.cpp:1912 (5)
//         00465f1f     MOV        EAX,0x1
//                              Panel.cpp:1913 (8)
//         00465f24     POP        EDI
//         00465f25     POP        ESI
//         00465f26     POP        EBP
//         00465f27     POP        EBX
//         00465f28     POP        this
//         00465f29     RET        0x10
//                               LAB_00465f2c                                                 XREF[1]:     00465f07(j)
//                              Panel.cpp:1909 (26)
//         00465f2c     MOV        this,dword ptr [ESP + param_4]
//         00465f30     MOV        EDX,dword ptr [ESP + param_3]
//         00465f34     PUSH       this
//         00465f35     PUSH       EDX
//         00465f36     CMP        AL,0x2
//         00465f38     MOV        EAX,dword ptr [EDI]
//         00465f3a     PUSH       ESI
//         00465f3b     PUSH       EBX
//         00465f3c     MOV        this,EDI
//         00465f3e     JNZ        LAB_00465f53
//         00465f40     CALL       dword ptr [EAX + 0xa0]
//                              Panel.cpp:1912 (5)
//         00465f46     MOV        EAX,0x1
//                              Panel.cpp:1913 (8)
//         00465f4b     POP        EDI
//         00465f4c     POP        ESI
//         00465f4d     POP        EBP
//         00465f4e     POP        EBX
//         00465f4f     POP        this
//         00465f50     RET        0x10
//                               LAB_00465f53                                                 XREF[1]:     00465f3e(j)
//                              Panel.cpp:1911 (6)
//         00465f53     CALL       dword ptr [EAX + 0x80]
//                               LAB_00465f59                                                 XREF[1]:     00465ef6(j)
//                              Panel.cpp:1912 (5)
//         00465f59     MOV        EAX,0x1
//                               LAB_00465f5e                                                 XREF[1]:     00465e23(j)
//                              Panel.cpp:1913 (8)
//         00465f5e     POP        EDI
//         00465f5f     POP        ESI
//         00465f60     POP        EBP
//         00465f61     POP        EBX
//         00465f62     POP        this
//         00465f63     RET        0x10
//         00465f66     ??         90h
//         00465f67     NOP
//         00465f68     NOP
//         00465f69     NOP
//         00465f6a     NOP
//         00465f6b     NOP
//         00465f6c     NOP
//         00465f6d     NOP
//         00465f6e     NOP
//         00465f6f     NOP
    return 0;
}

long TPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_up(TPanel * this, uchar param_1, long p
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00465f91(R), 0046600c(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     00465f8d(R), 00466007(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00465ffc(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00465ff8(R)
//                               ?handle_mouse_up@TPanel@@UAEJEJJHH@Z                         XREF[71]:    handle_mouse_up:00474439(c),
//                               TPanel::handle_mouse_up                                                   handle_mouse_up:0053e2b3(c),
//                                                                                                         0056f580(*), 0056f688(*),
//                                                                                                         0056f7c8(*), 0056f910(*),
//                                                                                                         0056fa40(*), 0056fb70(*),
//                                                                                                         0056fca8(*), 0056fdd8(*),
//                                                                                                         0056ff08(*), 00570038(*),
//                                                                                                         00570168(*), 00570cb0(*),
//                                                                                                         00570d90(*), 00571040(*),
//                                                                                                         00571128(*), 00571338(*),
//                                                                                                         00571420(*), 00571500(*), [more]
//                              Panel.cpp:1919 (6)
//         00465f70     PUSH       EBX
//         00465f71     PUSH       EBP
//         00465f72     PUSH       ESI
//         00465f73     MOV        ESI,this
//         00465f75     PUSH       EDI
//                              Panel.cpp:1923 (7)
//         00465f76     MOV        EAX,dword ptr [ESI + 0x6c]
//         00465f79     TEST       EAX,EAX
//         00465f7b     JNZ        LAB_00465f86
//                              Panel.cpp:1924 (2)
//         00465f7d     XOR        EAX,EAX
//                              Panel.cpp:1959 (7)
//         00465f7f     POP        EDI
//         00465f80     POP        ESI
//         00465f81     POP        EBP
//         00465f82     POP        EBX
//         00465f83     RET        0x14
//                               LAB_00465f86                                                 XREF[1]:     00465f7b(j)
//                              Panel.cpp:1926 (7)
//         00465f86     MOV        EAX,dword ptr [ESI + 0x68]
//         00465f89     TEST       EAX,EAX
//         00465f8b     JNZ        LAB_00465fe5
//                              Panel.cpp:1928 (24)
//         00465f8d     MOV        this,dword ptr [ESP + param_3]
//         00465f91     MOV        EDX,dword ptr [ESP + param_2]
//         00465f95     MOV        EAX,dword ptr [ESI]
//         00465f97     PUSH       this
//         00465f98     PUSH       EDX
//         00465f99     MOV        this,ESI
//         00465f9b     CALL       dword ptr [EAX + 0xbc]
//         00465fa1     TEST       EAX,EAX
//         00465fa3     JNZ        LAB_00465fac
//                              Panel.cpp:1959 (7)
//         00465fa5     POP        EDI
//         00465fa6     POP        ESI
//         00465fa7     POP        EBP
//         00465fa8     POP        EBX
//         00465fa9     RET        0x14
//                               LAB_00465fac                                                 XREF[1]:     00465fa3(j)
//                              Panel.cpp:1932 (19)
//         00465fac     MOV        ESI,dword ptr [ESI + 0x5c]
//         00465faf     TEST       ESI,ESI
//         00465fb1     JZ         LAB_0046602c
//         00465fb3     MOV        EDI,dword ptr [ESP + 0x24]
//         00465fb7     MOV        EBP,dword ptr [ESP + 0x20]
//         00465fbb     MOV        EBX,dword ptr [ESP + 0x14]
//                               LAB_00465fbf                                                 XREF[1]:     00465fdc(j)
//                              Panel.cpp:1934 (20)
//         00465fbf     MOV        EDX,dword ptr [ESP + 0x1c]
//         00465fc3     MOV        this,dword ptr [ESI]
//         00465fc5     PUSH       EDI
//         00465fc6     PUSH       EBP=>DAT_fffffff8
//         00465fc7     MOV        EAX,dword ptr [this->_padding_]
//         00465fc9     PUSH       EDX=>DAT_fffffff4
//         00465fca     MOV        EDX,dword ptr [ESP + 0x24]
//         00465fce     PUSH       EDX=>DAT_fffffff0
//         00465fcf     PUSH       EBX
//         00465fd0     CALL       dword ptr [EAX + 0x78]
//                              Panel.cpp:1935 (11)
//         00465fd3     TEST       EAX,EAX
//         00465fd5     JNZ        LAB_00466056
//         00465fd7     MOV        ESI,dword ptr [ESI + 0x4]
//         00465fda     TEST       ESI,ESI
//         00465fdc     JNZ        LAB_00465fbf
//                              Panel.cpp:1959 (7)
//         00465fde     POP        EDI
//         00465fdf     POP        ESI
//         00465fe0     POP        EBP
//         00465fe1     POP        EBX
//         00465fe2     RET        0x14
//                               LAB_00465fe5                                                 XREF[1]:     00465f8b(j)
//                              Panel.cpp:1942 (10)
//         00465fe5     MOV        EAX,dword ptr [ESI + 0x80]
//         00465feb     TEST       EAX,EAX
//         00465fed     JNZ        LAB_00465ff8
//                              Panel.cpp:1943 (2)
//         00465fef     XOR        EAX,EAX
//                              Panel.cpp:1959 (7)
//         00465ff1     POP        EDI
//         00465ff2     POP        ESI
//         00465ff3     POP        EBP
//         00465ff4     POP        EBX
//         00465ff5     RET        0x14
//                               LAB_00465ff8                                                 XREF[1]:     00465fed(j)
//                              Panel.cpp:1946 (40)
//         00465ff8     MOV        this,dword ptr [ESP + param_5]
//         00465ffc     MOV        EDX,dword ptr [ESP + param_4]
//         00466000     MOV        AL,byte ptr [ESI + 0xed]
//         00466006     PUSH       this
//         00466007     MOV        this,dword ptr [ESP + param_3]
//         0046600b     PUSH       EDX
//         0046600c     MOV        EDX,dword ptr [ESP + param_2]
//         00466010     CMP        AL,0x1
//         00466012     MOV        EAX,dword ptr [ESI]
//         00466014     PUSH       this
//         00466015     PUSH       EDX
//         00466016     MOV        this,ESI
//         00466018     JNZ        LAB_00466022
//         0046601a     CALL       dword ptr [EAX + 0x90]
//                              Panel.cpp:1947 (2)
//         00466020     JMP        LAB_00466028
//                               LAB_00466022                                                 XREF[1]:     00466018(j)
//                              Panel.cpp:1948 (6)
//         00466022     CALL       dword ptr [EAX + 0xa4]
//                               LAB_00466028                                                 XREF[1]:     00466020(j)
//                              Panel.cpp:1949 (4)
//         00466028     TEST       EAX,EAX
//         0046602a     JZ         LAB_00466035
//                               LAB_0046602c                                                 XREF[1]:     00465fb1(j)
//                              Panel.cpp:1950 (2)
//         0046602c     XOR        EAX,EAX
//                              Panel.cpp:1959 (7)
//         0046602e     POP        EDI
//         0046602f     POP        ESI
//         00466030     POP        EBP
//         00466031     POP        EBX
//         00466032     RET        0x14
//                               LAB_00466035                                                 XREF[1]:     0046602a(j)
//                              Panel.cpp:1952 (14)
//         00466035     MOV        AL,byte ptr [ESP + 0x14]
//         00466039     MOV        this,byte ptr [ESI + 0xed]
//         0046603f     CMP        AL,this
//         00466041     JNZ        LAB_00466051
//                              Panel.cpp:1954 (7)
//         00466043     MOV        byte ptr [ESI + 0xed],0x0
//                              Panel.cpp:1955 (7)
//         0046604a     MOV        byte ptr [ESI + 0xec],0x0
//                               LAB_00466051                                                 XREF[1]:     00466041(j)
//                              Panel.cpp:1958 (5)
//         00466051     MOV        EAX,0x1
//                               LAB_00466056                                                 XREF[1]:     00465fd5(j)
//                              Panel.cpp:1959 (7)
//         00466056     POP        EDI
//         00466057     POP        ESI
//         00466058     POP        EBP
//         00466059     POP        EBX
//         0046605a     RET        0x14
//         0046605d     ??         90h
//         0046605e     NOP
//         0046605f     NOP
    return 0;
}

long TPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_dbl_click(TPanel * this, uchar param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00466087(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00466083(R)
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0046607f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00466067(W)
//                               ?handle_mouse_dbl_click@TPanel@@UAEJEJJHH@Z                  XREF[73]:    0056f584(*), 0056f68c(*),
//                               TPanel::handle_mouse_dbl_click                                            0056f7cc(*), 0056f914(*),
//                                                                                                         0056fa44(*), 0056fb74(*),
//                                                                                                         0056fcac(*), 0056fddc(*),
//                                                                                                         0056ff0c(*), 0057003c(*),
//                                                                                                         0057016c(*), 00570cb4(*),
//                                                                                                         00570d94(*), 00571044(*),
//                                                                                                         0057112c(*), 0057125c(*),
//                                                                                                         0057133c(*), 00571424(*),
//                                                                                                         00571504(*), 005715f4(*), [more]
//                              Panel.cpp:1965 (11)
//         00466060     PUSH       this
//         00466061     PUSH       EBX
//         00466062     PUSH       EBP
//         00466063     PUSH       ESI
//         00466064     MOV        ESI,this
//         00466066     PUSH       EDI
//         00466067     MOV        dword ptr [ESP + local_4],ESI
//                              Panel.cpp:1969 (7)
//         0046606b     MOV        EAX,dword ptr [ESI + 0x6c]
//         0046606e     TEST       EAX,EAX
//         00466070     JNZ        LAB_0046607c
//                              Panel.cpp:1970 (2)
//         00466072     XOR        EAX,EAX
//                              Panel.cpp:1998 (8)
//         00466074     POP        EDI
//         00466075     POP        ESI
//         00466076     POP        EBP
//         00466077     POP        EBX
//         00466078     POP        this
//         00466079     RET        0x14
//                               LAB_0046607c                                                 XREF[1]:     00466070(j)
//                              Panel.cpp:1972 (19)
//         0046607c     MOV        EAX,dword ptr [ESI + 0x68]
//         0046607f     MOV        EBX,dword ptr [ESP + param_5]
//         00466083     MOV        EDI,dword ptr [ESP + param_3]
//         00466087     MOV        EBP,dword ptr [ESP + param_2]
//         0046608b     TEST       EAX,EAX
//         0046608d     JNZ        LAB_004660d1
//                              Panel.cpp:1974 (16)
//         0046608f     MOV        EAX,dword ptr [ESI]
//         00466091     PUSH       EDI
//         00466092     PUSH       EBP
//         00466093     MOV        this,ESI
//         00466095     CALL       dword ptr [EAX + 0xbc]
//         0046609b     TEST       EAX,EAX
//         0046609d     JNZ        LAB_004660a7
//                              Panel.cpp:1998 (8)
//         0046609f     POP        EDI
//         004660a0     POP        ESI
//         004660a1     POP        EBP
//         004660a2     POP        EBX
//         004660a3     POP        this
//         004660a4     RET        0x14
//                               LAB_004660a7                                                 XREF[1]:     0046609d(j)
//                              Panel.cpp:1978 (7)
//         004660a7     MOV        ESI,dword ptr [ESI + 0x5c]
//         004660aa     TEST       ESI,ESI
//         004660ac     JZ         LAB_004660cd
//                               LAB_004660ae                                                 XREF[1]:     004660cb(j)
//                              Panel.cpp:1980 (20)
//         004660ae     MOV        EAX,dword ptr [ESP + 0x24]
//         004660b2     MOV        this,dword ptr [ESI]
//         004660b4     PUSH       EBX
//         004660b5     PUSH       EAX=>DAT_fffffff8
//         004660b6     MOV        EAX,dword ptr [ESP + 0x20]
//         004660ba     MOV        EDX,dword ptr [this->_padding_]
//         004660bc     PUSH       EDI=>DAT_fffffff4
//         004660bd     PUSH       EBP=>DAT_fffffff0
//         004660be     PUSH       EAX
//         004660bf     CALL       dword ptr [EDX + 0x7c]
//                              Panel.cpp:1981 (11)
//         004660c2     TEST       EAX,EAX
//         004660c4     JNZ        LAB_00466133
//         004660c6     MOV        ESI,dword ptr [ESI + 0x4]
//         004660c9     TEST       ESI,ESI
//         004660cb     JNZ        LAB_004660ae
//                               LAB_004660cd                                                 XREF[1]:     004660ac(j)
//                              Panel.cpp:1978 (4)
//         004660cd     MOV        ESI,dword ptr [ESP + 0x10]
//                               LAB_004660d1                                                 XREF[1]:     0046608d(j)
//                              Panel.cpp:1986 (10)
//         004660d1     MOV        EAX,dword ptr [ESI + 0x80]
//         004660d7     TEST       EAX,EAX
//         004660d9     JNZ        LAB_004660e5
//                              Panel.cpp:1987 (2)
//         004660db     XOR        EAX,EAX
//                              Panel.cpp:1998 (8)
//         004660dd     POP        EDI
//         004660de     POP        ESI
//         004660df     POP        EBP
//         004660e0     POP        EBX
//         004660e1     POP        this
//         004660e2     RET        0x14
//                               LAB_004660e5                                                 XREF[1]:     004660d9(j)
//                              Panel.cpp:1989 (4)
//         004660e5     MOV        AL,byte ptr [ESP + 0x18]
//                              Panel.cpp:1990 (26)
//         004660e9     PUSH       EBX
//         004660ea     CMP        AL,0x1
//         004660ec     MOV        EAX,dword ptr [ESI]
//         004660ee     MOV        dword ptr [ESP + 0x2c],EAX
//         004660f2     JNZ        LAB_00466105
//         004660f4     MOV        this,dword ptr [ESP + 0x28]
//         004660f8     PUSH       this=>DAT_fffffff8
//         004660f9     PUSH       EDI=>DAT_fffffff4
//         004660fa     PUSH       EBP=>DAT_fffffff0
//         004660fb     MOV        this,ESI
//         004660fd     CALL       dword ptr [EAX + 0x94]
//                              Panel.cpp:1991 (2)
//         00466103     JMP        LAB_00466114
//                               LAB_00466105                                                 XREF[1]:     004660f2(j)
//                              Panel.cpp:1992 (15)
//         00466105     MOV        EDX,dword ptr [ESP + 0x28]
//         00466109     MOV        this,ESI
//         0046610b     PUSH       EDX=>DAT_fffffff8
//         0046610c     PUSH       EDI=>DAT_fffffff4
//         0046610d     PUSH       EBP=>DAT_fffffff0
//         0046610e     CALL       dword ptr [EAX + 0xa8]
//                               LAB_00466114                                                 XREF[1]:     00466103(j)
//                              Panel.cpp:1993 (2)
//         00466114     TEST       EAX,EAX
//                              Panel.cpp:1994 (2)
//         00466116     JNZ        LAB_00466133
//                              Panel.cpp:1996 (22)
//         00466118     MOV        EAX,dword ptr [ESP + 0x24]
//         0046611c     MOV        this,dword ptr [ESP + 0x18]
//         00466120     MOV        EDX,dword ptr [ESP + 0x28]
//         00466124     PUSH       EBX
//         00466125     PUSH       EAX=>DAT_fffffff8
//         00466126     PUSH       EDI=>DAT_fffffff4
//         00466127     PUSH       EBP=>DAT_fffffff0
//         00466128     PUSH       this
//         00466129     MOV        this,ESI
//         0046612b     CALL       dword ptr [EDX + 0x70]
//                              Panel.cpp:1997 (5)
//         0046612e     MOV        EAX,0x1
//                               LAB_00466133                                                 XREF[2]:     004660c4(j), 00466116(j)
//                              Panel.cpp:1998 (8)
//         00466133     POP        EDI
//         00466134     POP        ESI
//         00466135     POP        EBP
//         00466136     POP        EBX
//         00466137     POP        this
//         00466138     RET        0x14
//         0046613b     ??         90h
//         0046613c     NOP
//         0046613d     NOP
//         0046613e     NOP
//         0046613f     NOP
    return 0;
}

long TPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TPanel * this, TPanel * param_1, long param_2
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00466158(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00466153(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0046614e(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     00466147(R)
//                               ?action@TPanel@@UAEJPAV1@JKK@Z                               XREF[30]:    action:0043c81a(c),
//                               TPanel::action                                                            action:0043de57(c),
//                                                                                                         action:00441401(c),
//                                                                                                         action:0046a661(c),
//                                                                                                         action:00474536(c),
//                                                                                                         action:0047d296(c),
//                                                                                                         action:004926bc(c), 0056f5bc(*),
//                                                                                                         00570cec(*), 0057107c(*),
//                                                                                                         00571374(*), 0057145c(*),
//                                                                                                         0057171c(*), 00571804(*),
//                                                                                                         005718e4(*), 00571aec(*),
//                                                                                                         00571bcc(*), 005720f4(*),
//                                                                                                         00572b5c(*), 005744f4(*), [more]
//                              Panel.cpp:2004 (7)
//         00466140     MOV        this,dword ptr [ECX + this->parent_panel]
//         00466143     TEST       this,this
//         00466145     JZ         LAB_00466166
//                              Panel.cpp:2006 (28)
//         00466147     MOV        EDX,dword ptr [ESP + param_4]
//         0046614b     MOV        EAX,dword ptr [this->_padding_]
//         0046614d     PUSH       EDX
//         0046614e     MOV        EDX,dword ptr [ESP + param_3]
//         00466152     PUSH       EDX
//         00466153     MOV        EDX,dword ptr [ESP + param_2]
//         00466157     PUSH       EDX
//         00466158     MOV        EDX,dword ptr [ESP + param_1]
//         0046615c     PUSH       EDX
//         0046615d     CALL       dword ptr [EAX + 0xb4]
//                              Panel.cpp:2008 (3)
//         00466163     RET        0x10
//                               LAB_00466166                                                 XREF[1]:     00466145(j)
//                              Panel.cpp:2007 (2)
//         00466166     XOR        EAX,EAX
//                              Panel.cpp:2008 (3)
//         00466168     RET        0x10
//         0046616b     ??         90h
//         0046616c     NOP
//         0046616d     NOP
//         0046616e     NOP
//         0046616f     NOP
    return 0;
}

void TPanel::get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5) {
    /* TODO: Stub */
//                              void __thiscall get_mouse_info(TPanel * this, uint param_1, long par
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1                   XREF[1]:     004661a6(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00466170(R)
//              tagPOINT *        Stack[0xc]:4   param_3                   XREF[1]:     00466174(R)
//              int *             Stack[0x10]:4  param_4                   XREF[1]:     004661aa(R)
//              int *             Stack[0x14]:4  param_5                   XREF[1]:     004661b8(R)
//                               ?get_mouse_info@TPanel@@QAEXIJAAUtagPOINT@@AAH1@Z            XREF[1]:     wnd_proc:0046550a(c)
//                               TPanel::get_mouse_info
//                              Panel.cpp:2014 (15)
//         00466170     MOV        this,dword ptr [ESP + param_2]
//         00466174     MOV        EDX,dword ptr [ESP + param_3]
//         00466178     MOV        EAX,this
//         0046617a     AND        EAX,0xffff
//                              Panel.cpp:2016 (3)
//         0046617f     SHR        this,0x10
//                              Panel.cpp:2018 (12)
//         00466182     CMP        EAX,0xea60
//         00466187     MOV        dword ptr [EDX],EAX
//         00466189     MOV        dword ptr [EDX + 0x4],this
//         0046618c     JLE        LAB_00466195
//                              Panel.cpp:2019 (7)
//         0046618e     ADD        EAX,0xffff0000
//         00466193     MOV        dword ptr [EDX],EAX
//                               LAB_00466195                                                 XREF[1]:     0046618c(j)
//                              Panel.cpp:2021 (8)
//         00466195     CMP        this,0xea60
//         0046619b     JLE        LAB_004661a6
//                              Panel.cpp:2022 (9)
//         0046619d     ADD        this,0xffff0000
//         004661a3     MOV        dword ptr [EDX + 0x4],this
//                               LAB_004661a6                                                 XREF[1]:     0046619b(j)
//                              Panel.cpp:2024 (10)
//         004661a6     MOV        EAX,dword ptr [ESP + param_1]
//         004661aa     MOV        EDX,dword ptr [ESP + param_4]
//         004661ae     MOV        this,EAX
//                              Panel.cpp:2025 (14)
//         004661b0     AND        EAX,0x4
//         004661b3     AND        this,0x8
//         004661b6     MOV        dword ptr [EDX],this
//         004661b8     MOV        this,dword ptr [ESP + param_5]
//         004661bc     MOV        dword ptr [this->_padding_],EAX
//                              Panel.cpp:2026 (3)
//         004661be     RET        0x14
//         004661c1     ??         90h
//         004661c2     NOP
//         004661c3     NOP
//         004661c4     NOP
//         004661c5     NOP
//         004661c6     NOP
//         004661c7     NOP
//         004661c8     NOP
//         004661c9     NOP
//         004661ca     NOP
//         004661cb     NOP
//         004661cc     NOP
//         004661cd     NOP
//         004661ce     NOP
//         004661cf     NOP
    return;
}

void TPanel::get_mouse_pos(tagPOINT* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_mouse_pos(TPanel * this, tagPOINT * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagPOINT *        Stack[0x4]:4   param_1                   XREF[1]:     004661d1(R)
//                               ?get_mouse_pos@TPanel@@QAEXAAUtagPOINT@@@Z
//                               TPanel::get_mouse_pos
//                              Panel.cpp:2032 (1)
//         004661d0     PUSH       ESI
//                              Panel.cpp:2033 (14)
//         004661d1     MOV        ESI,dword ptr [ESP + param_1]
//         004661d5     PUSH       EDI
//         004661d6     MOV        EDI,this
//         004661d8     PUSH       ESI
//         004661d9     CALL       dword ptr [->USER32.DLL::GetCursorPos]           = 0048aeba
//                              Panel.cpp:2034 (14)
//         004661df     MOV        EAX,dword ptr [EDI + 0x20]
//         004661e2     MOV        this,dword ptr [EAX]
//         004661e4     CMP        byte ptr [this->_padding_ + 0x479],0x2
//         004661eb     JZ         LAB_0046621a
//                              Panel.cpp:2036 (11)
//         004661ed     MOV        EDX,dword ptr [EAX + 0x4]
//         004661f0     PUSH       ESI
//         004661f1     PUSH       EDX
//         004661f2     CALL       dword ptr [->USER32.DLL::ScreenToClient]         = 0048aea8
//                              Panel.cpp:2037 (9)
//         004661f8     MOV        EAX,dword ptr [ESI]
//         004661fa     CMP        EAX,0xea60
//         004661ff     JLE        LAB_00466208
//                              Panel.cpp:2038 (7)
//         00466201     ADD        EAX,0xffff0000
//         00466206     MOV        dword ptr [ESI],EAX
//                               LAB_00466208                                                 XREF[1]:     004661ff(j)
//                              Panel.cpp:2039 (10)
//         00466208     MOV        EAX,dword ptr [ESI + 0x4]
//         0046620b     CMP        EAX,0xea60
//         00466210     JLE        LAB_0046621a
//                              Panel.cpp:2040 (8)
//         00466212     ADD        EAX,0xffff0000
//         00466217     MOV        dword ptr [ESI + 0x4],EAX
//                               LAB_0046621a                                                 XREF[2]:     004661eb(j), 00466210(j)
//                              Panel.cpp:2042 (5)
//         0046621a     POP        EDI
//         0046621b     POP        ESI
//         0046621c     RET        0x4
//         0046621f     ??         90h
    return;
}

int TPanel::capture_mouse() {
    /* TODO: Stub */
//                              int __thiscall capture_mouse(TPanel * this)
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?capture_mouse@TPanel@@QAEHXZ                                XREF[10]:    start_scroll_view:0043869e(c),
//                               TPanel::capture_mouse                                                     mouse_left_down_action:004731cf(c)
//                                                                                                         mouse_right_down_action:004733df(c
//                                                                                                         mouse_left_down_action:00478513(c)
//                                                                                                         mouse_left_down_action:0047ae46(c)
//                                                                                                         start_scroll_view:0053a1bb(c),
//                                                                                                         mouse_left_down_action:0053d46a(c)
//                                                                                                         mouse_right_down_action:0053d670(c
//                                                                                                         mouse_left_down_action:0053e785(c)
//                                                                                                         mouse_right_down_action:0053f277(c
//                              Panel.cpp:2048 (3)
//         00466220     PUSH       ESI
//         00466221     MOV        ESI,this
//                              Panel.cpp:2049 (28)
//         00466223     MOV        this,panel_system
//         00466228     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         0046622d     TEST       EAX,EAX
//         0046622f     JZ         LAB_00466243
//         00466231     MOV        this,panel_system
//         00466236     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         0046623b     CMP        EAX,ESI
//         0046623d     JZ         LAB_00466243
//                              Panel.cpp:2050 (2)
//         0046623f     XOR        EAX,EAX
//                              Panel.cpp:2060 (2)
//         00466241     POP        ESI
//         00466242     RET
//                               LAB_00466243                                                 XREF[2]:     0046622f(j), 0046623d(j)
//                              Panel.cpp:2052 (14)
//         00466243     MOV        this,panel_system
//         00466248     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         0046624d     CMP        EAX,ESI
//         0046624f     JNZ        LAB_00466258
//                              Panel.cpp:2053 (5)
//         00466251     MOV        EAX,0x1
//                              Panel.cpp:2060 (2)
//         00466256     POP        ESI
//         00466257     RET
//                               LAB_00466258                                                 XREF[1]:     0046624f(j)
//                              Panel.cpp:2055 (13)
//         00466258     MOV        EAX,dword ptr [ESI + 0x20]
//         0046625b     MOV        this,dword ptr [EAX + 0x4]
//         0046625e     PUSH       this
//         0046625f     CALL       dword ptr [->USER32.DLL::SetCapture]             = 0048af82
//                              Panel.cpp:2056 (11)
//         00466265     PUSH       ESI
//         00466266     MOV        this,panel_system
//         0046626b     CALL       TPanelSystem::setMouseOwner                      void setMouseOwner(TPanelSystem * this, TPane
//                              Panel.cpp:2057 (8)
//         00466270     MOV        EAX,0x1
//         00466275     MOV        dword ptr [ESI + 0x68],EAX
//                              Panel.cpp:2060 (2)
//         00466278     POP        ESI
//         00466279     RET
//         0046627a     ??         90h
//         0046627b     NOP
//         0046627c     NOP
//         0046627d     NOP
//         0046627e     NOP
//         0046627f     NOP
    return 0;
}

void TPanel::release_mouse() {
    /* TODO: Stub */
//                              void __thiscall release_mouse(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?release_mouse@TPanel@@QAEXXZ                                XREF[34]:    end_scroll_view:004387ca(c),
//                               TPanel::release_mouse                                                     setCurrentPanel:00463e7a(c),
//                                                                                                         ~TPanel:004649e9(c),
//                                                                                                         set_active:00464de2(c),
//                                                                                                         mouse_left_up_action:00473313(c),
//                                                                                                         mouse_right_up_action:00473523(c),
//                                                                                                         reset:00473b83(c),
//                                                                                                         mouse_left_up_action:00478613(c),
//                                                                                                         mouse_left_up_action:0047b3f0(c),
//                                                                                                         handle_game_update:00496c25(c),
//                                                                                                         mouse_left_up_action:004bf6c0(c),
//                                                                                                         end_scroll_view:0053aaad(c),
//                                                                                                         mouse_left_move_action:0053d4c3(c)
//                                                                                                         mouse_left_up_action:0053d54a(c),
//                                                                                                         mouse_right_move_action:0053d6e3(c
//                                                                                                         mouse_right_up_action:0053d762(c),
//                                                                                                         mouse_left_move_action:0053e841(c)
//                                                                                                         mouse_left_up_action:0053ea36(c),
//                                                                                                         mouse_right_move_action:0053f33e(c
//                                                                                                         mouse_right_move_action:0053f37e(c
//                                                                                                         [more]
//                              Panel.cpp:2066 (3)
//         00466280     PUSH       ESI
//         00466281     MOV        ESI,this
//                              Panel.cpp:2067 (7)
//         00466283     MOV        EAX,dword ptr [ESI + 0x68]
//         00466286     TEST       EAX,EAX
//         00466288     JZ         LAB_004662b1
//                              Panel.cpp:2069 (14)
//         0046628a     MOV        this,panel_system
//         0046628f     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         00466294     CMP        EAX,ESI
//         00466296     JNZ        LAB_004662aa
//                              Panel.cpp:2071 (12)
//         00466298     PUSH       0x0
//         0046629a     MOV        this,panel_system
//         0046629f     CALL       TPanelSystem::setMouseOwner                      void setMouseOwner(TPanelSystem * this, TPane
//                              Panel.cpp:2072 (6)
//         004662a4     CALL       dword ptr [->USER32.DLL::ReleaseCapture]         = 0048af90
//                               LAB_004662aa                                                 XREF[1]:     00466296(j)
//                              Panel.cpp:2074 (7)
//         004662aa     MOV        dword ptr [ESI + 0x68],0x0
//                               LAB_004662b1                                                 XREF[1]:     00466288(j)
//                              Panel.cpp:2076 (2)
//         004662b1     POP        ESI
//         004662b2     RET
//         004662b3     ??         90h
//         004662b4     NOP
//         004662b5     NOP
//         004662b6     NOP
//         004662b7     NOP
//         004662b8     NOP
//         004662b9     NOP
//         004662ba     NOP
//         004662bb     NOP
//         004662bc     NOP
//         004662bd     NOP
//         004662be     NOP
//         004662bf     NOP
    return;
}

uchar TPanel::is_redraw_needed() {
    /* TODO: Stub */
//                              uchar __thiscall is_redraw_needed(TPanel * this)
//              uchar             AL:1           <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?is_redraw_needed@TPanel@@QAEEXZ
//                               TPanel::is_redraw_needed
//                              Panel.cpp:2082 (21)
//         004662c0     MOV        EAX,dword ptr [ECX + this->render_area]
//         004662c3     TEST       EAX,EAX
//         004662c5     JZ         LAB_004662d9
//         004662c7     MOV        EAX,dword ptr [ECX + this->visible]
//         004662ca     TEST       EAX,EAX
//         004662cc     JZ         LAB_004662d9
//         004662ce     MOV        EAX,dword ptr [ECX + this->active]
//         004662d1     TEST       EAX,EAX
//         004662d3     JZ         LAB_004662d9
//                              Panel.cpp:2086 (3)
//         004662d5     MOV        AL,byte ptr [ECX + this->need_redraw]
//                              Panel.cpp:2087 (1)
//         004662d8     RET
//                               LAB_004662d9                                                 XREF[3]:     004662c5(j), 004662cc(j),
//                                                                                                         004662d3(j)
//                              Panel.cpp:2084 (2)
//         004662d9     XOR        AL,AL
//                              Panel.cpp:2087 (1)
//         004662db     RET
//         004662dc     ??         90h
//         004662dd     NOP
//         004662de     NOP
//         004662df     NOP
    return 0;
}

int TPanel::is_inside(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall is_inside(TPanel * this, long param_1, long param_2)
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004662e7(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004662f7(R)
//                               ?is_inside@TPanel@@UAEHJJ@Z                                  XREF[71]:    is_inside:004387e0(c),
//                               TPanel::is_inside                                                         is_inside:00519eef(c),
//                                                                                                         0056f6cc(*), 0056f80c(*),
//                                                                                                         0056f954(*), 0056fa84(*),
//                                                                                                         0056fbb4(*), 0056fcec(*),
//                                                                                                         0056fe1c(*), 0056ff4c(*),
//                                                                                                         0057007c(*), 005701ac(*),
//                                                                                                         00570cf4(*), 00570dd4(*),
//                                                                                                         00571084(*), 0057116c(*),
//                                                                                                         0057129c(*), 0057137c(*),
//                                                                                                         00571464(*), 00571544(*), [more]
//                              Panel.cpp:2093 (5)
//         004662e0     MOV        EAX,dword ptr [ECX + this->active]
//         004662e3     TEST       EAX,EAX
//                              Panel.cpp:2095 (2)
//         004662e5     JZ         LAB_0046630f
//                              Panel.cpp:2098 (32)
//         004662e7     MOV        EAX,dword ptr [ESP + param_1]
//         004662eb     MOV        EDX,dword ptr [ECX + this->clip_rect.left]
//         004662ee     CMP        EAX,EDX
//         004662f0     JL         LAB_0046630f
//         004662f2     CMP        EAX,dword ptr [ECX + this+0x2c]
//         004662f5     JG         LAB_0046630f
//         004662f7     MOV        EAX,dword ptr [ESP + param_2]
//         004662fb     MOV        EDX,dword ptr [ECX + this+0x28]
//         004662fe     CMP        EAX,EDX
//         00466300     JL         LAB_0046630f
//         00466302     CMP        EAX,dword ptr [ECX + this+0x30]
//         00466305     JG         LAB_0046630f
//                              Panel.cpp:2099 (5)
//         00466307     MOV        EAX,0x1
//                              Panel.cpp:2102 (3)
//         0046630c     RET        0x8
//                               LAB_0046630f                                                 XREF[5]:     004662e5(j), 004662f0(j),
//                                                                                                         004662f5(j), 00466300(j),
//                                                                                                         00466305(j)
//                              Panel.cpp:2101 (2)
//         0046630f     XOR        EAX,EAX
//                              Panel.cpp:2102 (3)
//         00466311     RET        0x8
//         00466314     ??         90h
//         00466315     NOP
//         00466316     NOP
//         00466317     NOP
//         00466318     NOP
//         00466319     NOP
//         0046631a     NOP
//         0046631b     NOP
//         0046631c     NOP
//         0046631d     NOP
//         0046631e     NOP
//         0046631f     NOP
    return 0;
}

int TPanel::is_inside_rect(long param_1, long param_2, tagRECT* param_3) {
    /* TODO: Stub */
//                              int __thiscall is_inside_rect(TPanel * this, long param_1, long para
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00466324(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00466331(R)
//              tagRECT *         Stack[0xc]:4   param_3                   XREF[1]:     00466320(R)
//                               ?is_inside_rect@TPanel@@QAEHJJPAUtagRECT@@@Z                 XREF[11]:    handle_idle:0047ad67(c),
//                               TPanel::is_inside_rect                                                    handle_idle:0047adb0(c),
//                                                                                                         mouse_left_down_action:0047ae5e(c)
//                                                                                                         mouse_left_down_action:0047ae93(c)
//                                                                                                         mouse_left_down_action:0047aec3(c)
//                                                                                                         mouse_left_down_action:0047af0c(c)
//                                                                                                         mouse_left_down_action:0047af3a(c)
//                                                                                                         mouse_left_move_action:0047b004(c)
//                                                                                                         mouse_left_move_action:0047b05e(c)
//                                                                                                         mouse_left_move_action:0047b0b9(c)
//                                                                                                         mouse_left_move_action:0047b142(c)
//                              Panel.cpp:2108 (33)
//         00466320     MOV        EAX,dword ptr [ESP + param_3]
//         00466324     MOV        this,dword ptr [ESP + param_1]
//         00466328     CMP        this,dword ptr [EAX]
//         0046632a     JL         LAB_00466349
//         0046632c     CMP        this,dword ptr [EAX + 0x8]
//         0046632f     JG         LAB_00466349
//         00466331     MOV        this,dword ptr [ESP + param_2]
//         00466335     MOV        EDX,dword ptr [EAX + 0x4]
//         00466338     CMP        this,EDX
//         0046633a     JL         LAB_00466349
//         0046633c     CMP        this,dword ptr [EAX + 0xc]
//         0046633f     JG         LAB_00466349
//                              Panel.cpp:2111 (5)
//         00466341     MOV        EAX,0x1
//                              Panel.cpp:2114 (3)
//         00466346     RET        0xc
//                               LAB_00466349                                                 XREF[4]:     0046632a(j), 0046632f(j),
//                                                                                                         0046633a(j), 0046633f(j)
//                              Panel.cpp:2113 (2)
//         00466349     XOR        EAX,EAX
//                              Panel.cpp:2114 (3)
//         0046634b     RET        0xc
//         0046634e     ??         90h
//         0046634f     NOP
    return 0;
}

int TPanel::bound_point(long* param_1, long* param_2) {
    /* TODO: Stub */
//                              int __thiscall bound_point(TPanel * this, long * param_1, long * par
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     00466355(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00466371(R)
//                               ?bound_point@TPanel@@QAEHAAJ0@Z                              XREF[1]:     handle_scroll_view:0053a313(c)
//                               TPanel::bound_point
//                              Panel.cpp:2120 (16)
//         00466350     MOV        EDX,dword ptr [ECX + this->clip_rect.left]
//         00466353     PUSH       ESI
//         00466354     PUSH       EDI
//         00466355     MOV        EDI,dword ptr [ESP + param_1]
//         00466359     XOR        EAX,EAX
//         0046635b     INC        EDX
//         0046635c     MOV        ESI,dword ptr [EDI]
//         0046635e     CMP        ESI,EDX
//                              Panel.cpp:2130 (10)
//         00466360     JL         LAB_0046636a
//         00466362     MOV        EDX,dword ptr [ECX + this+0x2c]
//         00466365     DEC        EDX
//         00466366     CMP        ESI,EDX
//         00466368     JLE        LAB_00466371
//                               LAB_0046636a                                                 XREF[1]:     00466360(j)
//                              Panel.cpp:2132 (2)
//         0046636a     MOV        dword ptr [EDI],EDX
//                              Panel.cpp:2133 (5)
//         0046636c     MOV        EAX,0x1
//                               LAB_00466371                                                 XREF[1]:     00466368(j)
//                              Panel.cpp:2136 (14)
//         00466371     MOV        EDI,dword ptr [ESP + param_2]
//         00466375     MOV        EDX,dword ptr [ECX + this+0x28]
//         00466378     INC        EDX
//         00466379     MOV        ESI,dword ptr [EDI]
//         0046637b     CMP        ESI,EDX
//         0046637d     JGE        LAB_0046638b
//                              Panel.cpp:2138 (2)
//         0046637f     MOV        dword ptr [EDI],EDX
//                              Panel.cpp:2144 (5)
//         00466381     MOV        EAX,0x1
//                              Panel.cpp:2148 (5)
//         00466386     POP        EDI
//         00466387     POP        ESI
//         00466388     RET        0x8
//                               LAB_0046638b                                                 XREF[1]:     0046637d(j)
//                              Panel.cpp:2141 (8)
//         0046638b     MOV        this,dword ptr [ECX + this+0x30]
//         0046638e     DEC        this
//         0046638f     CMP        ESI,this
//         00466391     JLE        LAB_0046639a
//                              Panel.cpp:2143 (2)
//         00466393     MOV        dword ptr [EDI],this
//                              Panel.cpp:2144 (5)
//         00466395     MOV        EAX,0x1
//                               LAB_0046639a                                                 XREF[1]:     00466391(j)
//                              Panel.cpp:2148 (5)
//         0046639a     POP        EDI
//         0046639b     POP        ESI
//         0046639c     RET        0x8
//         0046639f     ??         90h
    return 0;
}

void TPanel::set_curr_child(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_curr_child(TPanel * this, TPanel * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004663a4(R)
//                               ?set_curr_child@TPanel@@QAEXPAV1@@Z                          XREF[101]:   setModalPanel:00463fa7(c),
//                               TPanel::set_curr_child                                                    setModalPanel:00463fcd(c),
//                                                                                                         setup:00473d34(c),
//                                                                                                         ~TDialogPanel:00473e9c(c),
//                                                                                                         set_mode:00474a93(c),
//                                                                                                         set_mode:004750cf(c),
//                                                                                                         TribeAchievementsScreen:0048e171(c
//                                                                                                         set_mode:0048e4e9(c),
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TribeJoinScreen:0049191e(c),
//                                                                                                         TRIBE_Screen_Game:00495257(c),
//                                                                                                         TribeLoadSavedGameScreen:0049e02c(
//                                                                                                         TRIBE_Screen_Main_Menu:0049ebb1(c)
//                                                                                                         TribeMPSetupScreen:004a0a36(c),
//                                                                                                         action:004a7055(c),
//                                                                                                         TribeSaveGameScreen:004a7548(c),
//                                                                                                         TRIBE_Screen_Sed:004a8693(c),
//                                                                                                         set_map_type:004aa843(c),
//                                                                                                         TRIBE_Screen_Sed_Open:004b3631(c),
//                                                                                                         [more]
//                              Panel.cpp:2154 (4)
//         004663a0     PUSH       ESI
//         004663a1     MOV        ESI,this
//         004663a3     PUSH       EDI
//                              Panel.cpp:2155 (11)
//         004663a4     MOV        EDI,dword ptr [ESP + param_1]
//         004663a8     MOV        this,dword ptr [ESI + 0x3c]
//         004663ab     CMP        EDI,this
//         004663ad     JZ         LAB_004663de
//                              Panel.cpp:2158 (11)
//         004663af     TEST       this,this
//         004663b1     JZ         LAB_004663c4
//         004663b3     MOV        EAX,dword ptr [ESI + 0x78]
//         004663b6     TEST       EAX,EAX
//         004663b8     JZ         LAB_004663c4
//                              Panel.cpp:2159 (10)
//         004663ba     MOV        EAX,dword ptr [this->_padding_]
//         004663bc     PUSH       0x0
//         004663be     CALL       dword ptr [EAX + 0xc0]
//                               LAB_004663c4                                                 XREF[2]:     004663b1(j), 004663b8(j)
//                              Panel.cpp:2163 (14)
//         004663c4     TEST       EDI,EDI
//         004663c6     MOV        dword ptr [ESI + 0x3c],EDI
//         004663c9     JZ         LAB_004663de
//         004663cb     MOV        EAX,dword ptr [ESI + 0x78]
//         004663ce     TEST       EAX,EAX
//         004663d0     JZ         LAB_004663de
//                              Panel.cpp:2164 (12)
//         004663d2     MOV        EDX,dword ptr [EDI]
//         004663d4     PUSH       0x1
//         004663d6     MOV        this,EDI
//         004663d8     CALL       dword ptr [EDX + 0xc0]
//                               LAB_004663de                                                 XREF[3]:     004663ad(j), 004663c9(j),
//                                                                                                         004663d0(j)
//                              Panel.cpp:2165 (5)
//         004663de     POP        EDI
//         004663df     POP        ESI
//         004663e0     RET        0x4
//         004663e3     ??         90h
//         004663e4     NOP
//         004663e5     NOP
//         004663e6     NOP
//         004663e7     NOP
//         004663e8     NOP
//         004663e9     NOP
//         004663ea     NOP
//         004663eb     NOP
//         004663ec     NOP
//         004663ed     NOP
//         004663ee     NOP
//         004663ef     NOP
    return;
}

void TPanel::set_focus(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_focus(TPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004663f0(R)
//                               ?set_focus@TPanel@@UAEXH@Z                                   XREF[28]:    set_focus:00469e19(c),
//                               TPanel::set_focus                                                         set_focus:00475b6c(c),
//                                                                                                         set_focus:00476ee8(c),
//                                                                                                         set_focus:00478ef8(c),
//                                                                                                         set_focus:00533ac8(c),
//                                                                                                         0056f5c8(*), 00570cf8(*),
//                                                                                                         00571088(*), 005712a0(*),
//                                                                                                         00571380(*), 00571728(*),
//                                                                                                         00571810(*), 005718f0(*),
//                                                                                                         00571af8(*), 00571bd8(*),
//                                                                                                         00571cb8(*), 00572020(*),
//                                                                                                         00572100(*), 00572938(*),
//                                                                                                         00574500(*), [more]
//                              Panel.cpp:2171 (12)
//         004663f0     MOV        EAX,dword ptr [ESP + param_1]
//         004663f4     PUSH       ESI
//         004663f5     MOV        ESI,this
//         004663f7     CMP        EAX,dword ptr [ESI + 0x78]
//         004663fa     JZ         LAB_0046641b
//                              Panel.cpp:2175 (3)
//         004663fc     MOV        dword ptr [ESI + 0x78],EAX
//                              Panel.cpp:2177 (9)
//         004663ff     MOV        EAX,dword ptr [ESI]
//         00466401     PUSH       0x1
//         00466403     MOV        this,ESI
//         00466405     CALL       dword ptr [EAX + 0x20]
//                              Panel.cpp:2179 (7)
//         00466408     MOV        this,dword ptr [ESI + 0x3c]
//         0046640b     TEST       this,this
//         0046640d     JZ         LAB_0046641b
//                              Panel.cpp:2180 (12)
//         0046640f     MOV        EAX,dword ptr [ESI + 0x78]
//         00466412     MOV        EDX,dword ptr [this->_padding_]
//         00466414     PUSH       EAX
//         00466415     CALL       dword ptr [EDX + 0xc0]
//                               LAB_0046641b                                                 XREF[2]:     004663fa(j), 0046640d(j)
//                              Panel.cpp:2181 (4)
//         0046641b     POP        ESI
//         0046641c     RET        0x4
//         0046641f     ??         90h
    return;
}

int TPanel::get_focus() {
    /* TODO: Stub */
//                              int __thiscall get_focus(TPanel * this)
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?get_focus@TPanel@@QAEHXZ                                    XREF[5]:     handle_paint:004965c4(c),
//                               TPanel::get_focus                                                         handle_idle:00496777(c),
//                                                                                                         handle_game_update:00496f79(c),
//                                                                                                         wnd_proc:004970fd(c),
//                                                                                                         handle_mouse_pointing_at:0049bb15(
//                              Panel.cpp:2187 (3)
//         00466420     MOV        EAX,dword ptr [ECX + this->have_focus]
//                              Panel.cpp:2189 (1)
//         00466423     RET
//         00466424     ??         90h
//         00466425     NOP
//         00466426     NOP
//         00466427     NOP
//         00466428     NOP
//         00466429     NOP
//         0046642a     NOP
//         0046642b     NOP
//         0046642c     NOP
//         0046642d     NOP
//         0046642e     NOP
//         0046642f     NOP
    return 0;
}

void TPanel::set_z_order(uchar param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall set_z_order(TPanel * this, uchar param_1, short para
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[2]:     0046643e(R), 0046644e(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     00466439(R), 00466473(R)
//                               ?set_z_order@TPanel@@QAEXEF@Z                                XREF[14]:    setup:00473d3f(c),
//                               TPanel::set_z_order                                                       setup:00473e01(c),
//                                                                                                         set_mode:004750c1(c),
//                                                                                                         TRIBE_Screen_Game:00495234(c),
//                                                                                                         create_button:004a88a0(c),
//                                                                                                         create_text:004a8943(c),
//                                                                                                         create_text:004a8993(c),
//                                                                                                         create_input:004a89e7(c),
//                                                                                                         create_edit:004a8a41(c),
//                                                                                                         create_drop_down:004a8be7(c),
//                                                                                                         create_all_buttons_etc:004b0129(c)
//                                                                                                         create_all_buttons_etc:004b02c4(c)
//                                                                                                         create_check_box:004b2dfe(c),
//                                                                                                         create_radio_button:004b2e8e(c)
//                              Panel.cpp:2195 (9)
//         00466430     MOV        EAX,dword ptr [ECX + this->parent_panel]
//         00466433     XOR        EDX,EDX
//         00466435     CMP        EAX,EDX
//         00466437     JZ         LAB_0046644e
//                              Panel.cpp:2198 (18)
//         00466439     MOV        EDX,dword ptr [ESP + param_2]
//         0046643d     PUSH       EDX
//         0046643e     MOV        EDX,dword ptr [ESP + param_1]
//         00466442     PUSH       EDX
//         00466443     PUSH       this
//         00466444     MOV        this,EAX
//         00466446     CALL       TPanel::set_child_z_order                        void set_child_z_order(TPanel * this, TPanel
//                              Panel.cpp:2216 (3)
//         0046644b     RET        0x8
//                               LAB_0046644e                                                 XREF[1]:     00466437(j)
//                              Panel.cpp:2202 (19)
//         0046644e     MOV        EAX,dword ptr [ESP + param_1]
//         00466452     AND        EAX,0xff
//         00466457     SUB        EAX,EDX
//         00466459     JZ         LAB_00466473
//         0046645b     DEC        EAX
//         0046645c     JZ         LAB_0046646a
//         0046645e     DEC        EAX
//         0046645f     JNZ        LAB_0046647e
//                              Panel.cpp:2213 (6)
//         00466461     MOV        dword ptr [ECX + this->z_order],EDX
//                              Panel.cpp:2216 (3)
//         00466467     RET        0x8
//                               LAB_0046646a                                                 XREF[1]:     0046645c(j)
//                              Panel.cpp:2209 (6)
//         0046646a     MOV        dword ptr [ECX + this->z_order],EDX
//                              Panel.cpp:2216 (3)
//         00466470     RET        0x8
//                               LAB_00466473                                                 XREF[1]:     00466459(j)
//                              Panel.cpp:2205 (11)
//         00466473     MOVSX      EAX,word ptr [ESP + param_2]
//         00466478     MOV        dword ptr [ECX + this->z_order],EAX
//                               LAB_0046647e                                                 XREF[1]:     0046645f(j)
//                              Panel.cpp:2216 (3)
//         0046647e     RET        0x8
//         00466481     ??         90h
//         00466482     NOP
//         00466483     NOP
//         00466484     NOP
//         00466485     NOP
//         00466486     NOP
//         00466487     NOP
//         00466488     NOP
//         00466489     NOP
//         0046648a     NOP
//         0046648b     NOP
//         0046648c     NOP
//         0046648d     NOP
//         0046648e     NOP
//         0046648f     NOP
    return;
}

void TPanel::set_child_z_order(TPanel* param_1, uchar param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall set_child_z_order(TPanel * this, TPanel * param_1, u
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00466496(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00466491(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     00466529(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004664a7(W), 00466551(R)
//                               ?set_child_z_order@TPanel@@QAEXPAV1@EF@Z                     XREF[1]:     set_z_order:00466446(c)
//                               TPanel::set_child_z_order
//                              Panel.cpp:2222 (1)
//         00466490     PUSH       this
//                              Panel.cpp:2231 (38)
//         00466491     MOV        EAX,dword ptr [ESP + param_2]
//         00466495     PUSH       EBX
//         00466496     MOV        EBX,dword ptr [ESP + param_1]
//         0046649a     PUSH       EBP
//         0046649b     AND        EAX,0xff
//         004664a0     MOV        EBP,this
//         004664a2     PUSH       ESI
//         004664a3     SUB        EAX,0x0
//         004664a6     PUSH       EDI
//         004664a7     MOV        dword ptr [ESP + local_4],EBP
//         004664ab     JZ         LAB_00466526
//         004664ad     DEC        EAX
//         004664ae     JZ         LAB_004664f0
//         004664b0     DEC        EAX
//         004664b1     JNZ        LAB_00466585
//                              Panel.cpp:2259 (9)
//         004664b7     MOV        this,dword ptr [EBP + 0x58]
//         004664ba     XOR        EDX,EDX
//         004664bc     TEST       this,this
//         004664be     JZ         LAB_004664e1
//                               LAB_004664c0                                                 XREF[1]:     004664df(j)
//                              Panel.cpp:2261 (19)
//         004664c0     MOV        EAX,dword ptr [this->_padding_]
//         004664c2     CMP        EAX,EBX
//         004664c4     JZ         LAB_004664da
//         004664c6     MOV        EDI,dword ptr [EAX + 0xdc]
//         004664cc     MOVSX      ESI,DX
//         004664cf     CMP        EDI,ESI
//         004664d1     JGE        LAB_004664da
//                              Panel.cpp:2262 (7)
//         004664d3     MOV        DX,word ptr [EAX + 0xdc]
//                               LAB_004664da                                                 XREF[2]:     004664c4(j), 004664d1(j)
//                              Panel.cpp:2259 (7)
//         004664da     MOV        this,dword ptr [ECX + this->previousModalPanel
//         004664dd     TEST       this,this
//         004664df     JNZ        LAB_004664c0
//                               LAB_004664e1                                                 XREF[1]:     004664be(j)
//                              Panel.cpp:2264 (10)
//         004664e1     MOVSX      EAX,DX
//         004664e4     DEC        EAX
//         004664e5     MOV        dword ptr [EBX + 0xdc],EAX
//                              Panel.cpp:2265 (5)
//         004664eb     JMP        LAB_00466585
//                               LAB_004664f0                                                 XREF[1]:     004664ae(j)
//                              Panel.cpp:2270 (9)
//         004664f0     MOV        this,dword ptr [EBP + 0x58]
//         004664f3     XOR        EDX,EDX
//         004664f5     TEST       this,this
//         004664f7     JZ         LAB_0046651a
//                               LAB_004664f9                                                 XREF[1]:     00466518(j)
//                              Panel.cpp:2272 (19)
//         004664f9     MOV        EAX,dword ptr [this->_padding_]
//         004664fb     CMP        EAX,EBX
//         004664fd     JZ         LAB_00466513
//         004664ff     MOV        EDI,dword ptr [EAX + 0xdc]
//         00466505     MOVSX      ESI,DX
//         00466508     CMP        EDI,ESI
//         0046650a     JLE        LAB_00466513
//                              Panel.cpp:2273 (7)
//         0046650c     MOV        DX,word ptr [EAX + 0xdc]
//                               LAB_00466513                                                 XREF[2]:     004664fd(j), 0046650a(j)
//                              Panel.cpp:2270 (7)
//         00466513     MOV        this,dword ptr [ECX + this->previousModalPanel
//         00466516     TEST       this,this
//         00466518     JNZ        LAB_004664f9
//                               LAB_0046651a                                                 XREF[1]:     004664f7(j)
//                              Panel.cpp:2275 (10)
//         0046651a     MOVSX      this,DX
//         0046651d     INC        this
//         0046651e     MOV        dword ptr [EBX + 0xdc],this
//                              Panel.cpp:2276 (2)
//         00466524     JMP        LAB_00466585
//                               LAB_00466526                                                 XREF[1]:     004664ab(j)
//                              Panel.cpp:2236 (16)
//         00466526     MOV        EDX,dword ptr [EBP + 0x58]
//         00466529     MOV        DI,word ptr [ESP + param_3]
//         0046652e     MOV        EAX,EDX
//         00466530     XOR        ESI,ESI
//         00466532     TEST       EAX,EAX
//         00466534     JZ         LAB_00466555
//                              Panel.cpp:2238 (22)
//         00466536     MOVSX      this,DI
//                               LAB_00466539                                                 XREF[1]:     00466548(j)
//         00466539     MOV        EBP,dword ptr [EAX]
//         0046653b     CMP        dword ptr [EBP + 0xdc],this
//         00466541     JZ         LAB_0046654c
//         00466543     MOV        EAX,dword ptr [EAX + 0x8]
//         00466546     TEST       EAX,EAX
//         00466548     JNZ        LAB_00466539
//         0046654a     JMP        LAB_00466551
//                               LAB_0046654c                                                 XREF[1]:     00466541(j)
//                              Panel.cpp:2240 (9)
//         0046654c     MOV        ESI,0x1
//                               LAB_00466551                                                 XREF[1]:     0046654a(j)
//         00466551     MOV        EBP,dword ptr [ESP + local_4]
//                               LAB_00466555                                                 XREF[1]:     00466534(j)
//                              Panel.cpp:2245 (4)
//         00466555     TEST       ESI,ESI
//         00466557     JZ         LAB_0046657c
//                              Panel.cpp:2247 (6)
//         00466559     MOV        EAX,EDX
//         0046655b     TEST       EAX,EAX
//         0046655d     JZ         LAB_0046657c
//                              Panel.cpp:2249 (15)
//         0046655f     MOVSX      ESI,DI
//                               LAB_00466562                                                 XREF[1]:     0046657a(j)
//         00466562     MOV        this,dword ptr [EAX]
//         00466564     MOV        EDX,dword ptr [ECX + this->z_order]
//         0046656a     CMP        EDX,ESI
//         0046656c     JL         LAB_00466575
//                              Panel.cpp:2250 (14)
//         0046656e     INC        EDX
//         0046656f     MOV        dword ptr [ECX + this->z_order],EDX
//                               LAB_00466575                                                 XREF[1]:     0046656c(j)
//         00466575     MOV        EAX,dword ptr [EAX + 0x8]
//         00466578     TEST       EAX,EAX
//         0046657a     JNZ        LAB_00466562
//                               LAB_0046657c                                                 XREF[2]:     00466557(j), 0046655d(j)
//                              Panel.cpp:2253 (9)
//         0046657c     MOVSX      EDX,DI
//         0046657f     MOV        dword ptr [EBX + 0xdc],EDX
//                               LAB_00466585                                                 XREF[3]:     004664b1(j), 004664eb(j),
//                                                                                                         00466524(j)
//                              Panel.cpp:2289 (15)
//         00466585     MOV        EAX,dword ptr [EBP + 0x58]
//         00466588     MOV        EDI,dword ptr [EBP + 0x3c]
//         0046658b     XOR        ESI,ESI
//         0046658d     CMP        EAX,ESI
//         0046658f     MOV        dword ptr [EBP + 0x3c],ESI
//         00466592     JZ         LAB_004665ab
//                               LAB_00466594                                                 XREF[1]:     0046659d(j)
//                              Panel.cpp:2291 (13)
//         00466594     CMP        dword ptr [EAX],EBX
//         00466596     JZ         LAB_004665a1
//         00466598     MOV        EAX,dword ptr [EAX + 0x8]
//         0046659b     CMP        EAX,ESI
//         0046659d     JNZ        LAB_00466594
//         0046659f     JMP        LAB_004665ab
//                               LAB_004665a1                                                 XREF[1]:     00466596(j)
//                              Panel.cpp:2294 (10)
//         004665a1     PUSH       EAX
//         004665a2     MOV        this,EBP
//         004665a4     MOV        ESI,EAX
//         004665a6     CALL       TPanel::remove_panel_node                        void remove_panel_node(TPanel * this, PanelNo
//                               LAB_004665ab                                                 XREF[2]:     00466592(j), 0046659f(j)
//                              Panel.cpp:2300 (4)
//         004665ab     TEST       ESI,ESI
//         004665ad     JZ         LAB_004665f3
//                              Panel.cpp:2303 (9)
//         004665af     MOV        EAX,dword ptr [EBP + 0x58]
//         004665b2     XOR        EDX,EDX
//         004665b4     TEST       EAX,EAX
//         004665b6     JZ         LAB_004665e1
//                              Panel.cpp:2305 (25)
//         004665b8     MOV        this,dword ptr [EBX + 0xdc]
//                               LAB_004665be                                                 XREF[1]:     004665cd(j)
//         004665be     MOV        EBX,dword ptr [EAX]
//         004665c0     CMP        dword ptr [EBX + 0xdc],this
//         004665c6     JG         LAB_004665d1
//         004665c8     MOV        EAX,dword ptr [EAX + 0x8]
//         004665cb     TEST       EAX,EAX
//         004665cd     JNZ        LAB_004665be
//         004665cf     JMP        LAB_004665e1
//                               LAB_004665d1                                                 XREF[1]:     004665c6(j)
//                              Panel.cpp:2308 (11)
//         004665d1     PUSH       0x0
//         004665d3     PUSH       EAX
//         004665d4     PUSH       ESI
//         004665d5     MOV        this,EBP
//         004665d7     CALL       TPanel::add_panel_node                           void add_panel_node(TPanel * this, PanelNode
//                              Panel.cpp:2309 (5)
//         004665dc     MOV        EDX,0x1
//                               LAB_004665e1                                                 XREF[2]:     004665b6(j), 004665cf(j)
//                              Panel.cpp:2313 (4)
//         004665e1     TEST       EDX,EDX
//         004665e3     JNZ        LAB_004665f3
//                              Panel.cpp:2316 (14)
//         004665e5     MOV        EAX,dword ptr [EBP + 0x5c]
//         004665e8     PUSH       0x1
//         004665ea     PUSH       EAX
//         004665eb     PUSH       ESI
//         004665ec     MOV        this,EBP
//         004665ee     CALL       TPanel::add_panel_node                           void add_panel_node(TPanel * this, PanelNode
//                               LAB_004665f3                                                 XREF[2]:     004665ad(j), 004665e3(j)
//                              Panel.cpp:2321 (3)
//         004665f3     MOV        dword ptr [EBP + 0x3c],EDI
//                              Panel.cpp:2322 (8)
//         004665f6     POP        EDI
//         004665f7     POP        ESI
//         004665f8     POP        EBP
//         004665f9     POP        EBX
//         004665fa     POP        this
//         004665fb     RET        0xc
//         004665fe     ??         90h
//         004665ff     NOP
    return;
}

void TPanel::set_tab_order(TPanel** param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall set_tab_order(TPanel * this, TPanel * param_1, TPane
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00466650(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00466654(R)
//                               ?set_tab_order@TPanel@@UAEXPAV1@0@Z                          XREF[73]:    set_tab_order:004751ef(c),
//                               TPanel::set_tab_order                                                     0056f5cc(*), 0056f6d4(*),
//                                                                                                         0056f814(*), 0056f95c(*),
//                                                                                                         0056fa8c(*), 0056fbbc(*),
//                                                                                                         0056fcf4(*), 0056fe24(*),
//                                                                                                         0056ff54(*), 00570084(*),
//                                                                                                         005701b4(*), 00570cfc(*),
//                                                                                                         00570ddc(*), 0057108c(*),
//                                                                                                         00571174(*), 00571384(*),
//                                                                                                         0057146c(*), 0057154c(*),
//                                                                                                         0057163c(*), [more]
//                              Panel.cpp:2353 (4)
//         00466650     MOV        EAX,dword ptr [ESP + param_1]
//                              Panel.cpp:2355 (10)
//         00466654     MOV        EDX,dword ptr [ESP + param_2]
//         00466658     MOV        dword ptr [ECX + this->tab_prev_panel],EAX
//         0046665b     MOV        dword ptr [ECX + this->tab_next_panel],EDX
//                              Panel.cpp:2356 (7)
//         0046665e     MOV        dword ptr [ECX + this->tab_stop],0x1
//                              Panel.cpp:2357 (3)
//         00466665     RET        0x8
//         00466668     ??         90h
//         00466669     NOP
//         0046666a     NOP
//         0046666b     NOP
//         0046666c     NOP
//         0046666d     NOP
//         0046666e     NOP
//         0046666f     NOP
    return;
}

void TPanel::set_tab_order(TPanel* param_1, TPanel* param_2) {
    /* TODO: Stub */
//                              void __thiscall set_tab_order(TPanel * this, TPanel * param_1, TPane
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00466650(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00466654(R)
//                               ?set_tab_order@TPanel@@UAEXPAV1@0@Z                          XREF[73]:    set_tab_order:004751ef(c),
//                               TPanel::set_tab_order                                                     0056f5cc(*), 0056f6d4(*),
//                                                                                                         0056f814(*), 0056f95c(*),
//                                                                                                         0056fa8c(*), 0056fbbc(*),
//                                                                                                         0056fcf4(*), 0056fe24(*),
//                                                                                                         0056ff54(*), 00570084(*),
//                                                                                                         005701b4(*), 00570cfc(*),
//                                                                                                         00570ddc(*), 0057108c(*),
//                                                                                                         00571174(*), 00571384(*),
//                                                                                                         0057146c(*), 0057154c(*),
//                                                                                                         0057163c(*), [more]
//                              Panel.cpp:2353 (4)
//         00466650     MOV        EAX,dword ptr [ESP + param_1]
//                              Panel.cpp:2355 (10)
//         00466654     MOV        EDX,dword ptr [ESP + param_2]
//         00466658     MOV        dword ptr [ECX + this->tab_prev_panel],EAX
//         0046665b     MOV        dword ptr [ECX + this->tab_next_panel],EDX
//                              Panel.cpp:2356 (7)
//         0046665e     MOV        dword ptr [ECX + this->tab_stop],0x1
//                              Panel.cpp:2357 (3)
//         00466665     RET        0x8
//         00466668     ??         90h
//         00466669     NOP
//         0046666a     NOP
//         0046666b     NOP
//         0046666c     NOP
//         0046666d     NOP
//         0046666e     NOP
//         0046666f     NOP
    return;
}

TPanel* TPanel::previousPanel() {
    /* TODO: Stub */
//                              TPanel * __thiscall previousPanel(TPanel * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?previousPanel@TPanel@@QBEPAV1@XZ                            XREF[3]:     previousPanel:00463d17(c),
//                               TPanel::previousPanel                                                     restorePreviousPanel:00463ec4(c),
//                                                                                                         restorePreviousPanel:00463eec(c)
//                              Panel.cpp:2363 (3)
//         00466670     MOV        EAX,dword ptr [ECX + this->previousPanelValue]
//                              Panel.cpp:2365 (1)
//         00466673     RET
//         00466674     ??         90h
//         00466675     NOP
//         00466676     NOP
//         00466677     NOP
//         00466678     NOP
//         00466679     NOP
//         0046667a     NOP
//         0046667b     NOP
//         0046667c     NOP
//         0046667d     NOP
//         0046667e     NOP
//         0046667f     NOP
    return 0;
}

void TPanel::setPreviousPanel(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall setPreviousPanel(TPanel * this, TPanel * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00466680(R)
//                               ?setPreviousPanel@TPanel@@QAEXPAV1@@Z                        XREF[4]:     addPanel:00463dba(c),
//                               TPanel::setPreviousPanel                                                  restorePreviousPanel:00463ee3(c),
//                                                                                                         restorePreviousPanel:00463ef9(c),
//                                                                                                         setCurrentPanel:0046426e(c)
//                              Panel.cpp:2370 (7)
//         00466680     MOV        EAX,dword ptr [ESP + param_1]
//         00466684     MOV        dword ptr [ECX + this->previousPanelValue],EAX
//                              Panel.cpp:2372 (3)
//         00466687     RET        0x4
//         0046668a     ??         90h
//         0046668b     NOP
//         0046668c     NOP
//         0046668d     NOP
//         0046668e     NOP
//         0046668f     NOP
    return;
}

TPanel* TPanel::previousModalPanel() {
    /* TODO: Stub */
//                              TPanel * __thiscall previousModalPanel(TPanel * this)
//              TPanel *          EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?previousModalPanel@TPanel@@QBEPAV1@XZ                       XREF[1]:     restorePreviousModalPanel:00464020
//                               TPanel::previousModalPanel
//                              Panel.cpp:2377 (3)
//         00466690     MOV        EAX,dword ptr [ECX + this->previousModalPanelV
//                              Panel.cpp:2379 (1)
//         00466693     RET
//         00466694     ??         90h
//         00466695     NOP
//         00466696     NOP
//         00466697     NOP
//         00466698     NOP
//         00466699     NOP
//         0046669a     NOP
//         0046669b     NOP
//         0046669c     NOP
//         0046669d     NOP
//         0046669e     NOP
//         0046669f     NOP
    return 0;
}

void TPanel::setPreviousModalPanel(TPanel* param_1) {
    /* TODO: Stub */
//                              void __thiscall setPreviousModalPanel(TPanel * this, TPanel * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004666a0(R)
//                               ?setPreviousModalPanel@TPanel@@QAEXPAV1@@Z                   XREF[2]:     setModalPanel:00463f76(c),
//                               TPanel::setPreviousModalPanel                                             setCurrentPanelModal:00464002(c)
//                              Panel.cpp:2384 (7)
//         004666a0     MOV        EAX,dword ptr [ESP + param_1]
//         004666a4     MOV        dword ptr [ECX + this->previousModalPanelValue
//                              Panel.cpp:2386 (3)
//         004666a7     RET        0x4
//         004666aa     ??         90h
//         004666ab     NOP
//         004666ac     NOP
//         004666ad     NOP
//         004666ae     NOP
//         004666af     NOP
    return;
}

char* TPanel::panelName() {
    /* TODO: Stub */
//                              char * __thiscall panelName(TPanel * this)
//              char *            EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?panelName@TPanel@@QBEPADXZ                                  XREF[69]:    addPanel:00463d8b(c),
//                               TPanel::panelName                                                         restorePreviousPanel:00463f00(c),
//                                                                                                         inSystem:0046412b(c),
//                                                                                                         findPanelNode:004641d0(c),
//                                                                                                         findPanelNode:00464215(c),
//                                                                                                         ~TPanel:00464a06(c),
//                                                                                                         action:0046a4f4(c),
//                                                                                                         action:0046a504(c),
//                                                                                                         action:0046a568(c),
//                                                                                                         action:0046a578(c),
//                                                                                                         action:0046a5dc(c),
//                                                                                                         action:0046a5ec(c),
//                                                                                                         action:004983b1(c),
//                                                                                                         action:004983c5(c),
//                                                                                                         action:00498449(c),
//                                                                                                         action:004984cd(c),
//                                                                                                         action:004985a5(c),
//                                                                                                         action:00498650(c),
//                                                                                                         load_game:00526206(c),
//                                                                                                         load_game:00526215(c), [more]
//                              Panel.cpp:2391 (3)
//         004666b0     MOV        EAX,dword ptr [ECX + this->panelNameValue]
//                              Panel.cpp:2393 (1)
//         004666b3     RET
//         004666b4     ??         90h
//         004666b5     NOP
//         004666b6     NOP
//         004666b7     NOP
//         004666b8     NOP
//         004666b9     NOP
//         004666ba     NOP
//         004666bb     NOP
//         004666bc     NOP
//         004666bd     NOP
//         004666be     NOP
//         004666bf     NOP
    return 0;
}

void TPanel::setPanelName(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall setPanelName(TPanel * this, char * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004666c3(R)
//                               ?setPanelName@TPanel@@QAEXPAD@Z                              XREF[1]:     TPanel:00464849(c)
//                               TPanel::setPanelName
//                              Panel.cpp:2398 (3)
//         004666c0     PUSH       EBX
//         004666c1     PUSH       EBP
//         004666c2     PUSH       ESI
//                              Panel.cpp:2399 (25)
//         004666c3     MOV        ESI,dword ptr [ESP + param_1]
//         004666c7     TEST       ESI,ESI
//         004666c9     PUSH       EDI
//         004666ca     MOV        EBX,this
//         004666cc     JZ         LAB_00466748
//         004666ce     MOV        EDI,ESI
//         004666d0     OR         this,0xffffffff
//         004666d3     XOR        EAX,EAX
//         004666d5     SCASB.RE   ES:EDI
//         004666d7     NOT        this
//         004666d9     DEC        this
//         004666da     JZ         LAB_00466748
//                              Panel.cpp:2407 (33)
//         004666dc     MOV        EDX,dword ptr [EBX + 0x1c]
//         004666df     TEST       EDX,EDX
//         004666e1     JZ         LAB_0046670a
//         004666e3     MOV        EDI,ESI
//         004666e5     OR         this,0xffffffff
//         004666e8     SCASB.RE   ES:EDI
//         004666ea     NOT        this
//         004666ec     DEC        this
//         004666ed     MOV        EDI,EDX
//         004666ef     MOV        EBP,this
//         004666f1     OR         this,0xffffffff
//         004666f4     SCASB.RE   ES:EDI
//         004666f6     NOT        this
//         004666f8     DEC        this
//         004666f9     CMP        this,EBP
//         004666fb     JNC        LAB_00466721
//                              Panel.cpp:2408 (4)
//         004666fd     TEST       EDX,EDX
//         004666ff     JZ         LAB_0046670a
//                              Panel.cpp:2409 (9)
//         00466701     PUSH       EDX
//         00466702     CALL       free                                             undefined free()
//         00466707     ADD        ESP,0x4
//                               LAB_0046670a                                                 XREF[2]:     004666e1(j), 004666ff(j)
//                              Panel.cpp:2410 (23)
//         0046670a     MOV        EDI,ESI
//         0046670c     OR         this,0xffffffff
//         0046670f     XOR        EAX,EAX
//         00466711     SCASB.RE   ES:EDI
//         00466713     NOT        this
//         00466715     PUSH       this
//         00466716     CALL       malloc                                           undefined malloc()
//         0046671b     ADD        ESP,0x4
//         0046671e     MOV        dword ptr [EBX + 0x1c],EAX
//                               LAB_00466721                                                 XREF[1]:     004666fb(j)
//                              Panel.cpp:2412 (32)
//         00466721     MOV        EDI,ESI
//         00466723     OR         this,0xffffffff
//         00466726     XOR        EAX,EAX
//         00466728     SCASB.RE   ES:EDI
//         0046672a     NOT        this
//         0046672c     SUB        EDI,this
//         0046672e     MOV        EAX,this
//         00466730     MOV        ESI,EDI
//         00466732     MOV        EDI,dword ptr [EBX + 0x1c]
//         00466735     SHR        this,0x2
//         00466738     MOVSD.REP  ES:EDI,ESI
//         0046673a     MOV        this,EAX
//         0046673c     AND        this,0x3
//         0046673f     MOVSB.REP  ES:EDI,ESI
//                              Panel.cpp:2413 (7)
//         00466741     POP        EDI
//         00466742     POP        ESI
//         00466743     POP        EBP
//         00466744     POP        EBX
//         00466745     RET        0x4
//                               LAB_00466748                                                 XREF[2]:     004666cc(j), 004666da(j)
//                              Panel.cpp:2400 (7)
//         00466748     MOV        EAX,dword ptr [EBX + 0x1c]
//         0046674b     TEST       EAX,EAX
//         0046674d     JZ         LAB_0046675f
//                              Panel.cpp:2401 (9)
//         0046674f     PUSH       EAX
//         00466750     CALL       free                                             undefined free()
//         00466755     ADD        ESP,0x4
//                              Panel.cpp:2402 (7)
//         00466758     MOV        dword ptr [EBX + 0x1c],0x0
//                               LAB_0046675f                                                 XREF[1]:     0046674d(j)
//                              Panel.cpp:2413 (7)
//         0046675f     POP        EDI
//         00466760     POP        ESI
//         00466761     POP        EBP
//         00466762     POP        EBX
//         00466763     RET        0x4
//         00466766     ??         90h
//         00466767     NOP
//         00466768     NOP
//         00466769     NOP
//         0046676a     NOP
//         0046676b     NOP
//         0046676c     NOP
//         0046676d     NOP
//         0046676e     NOP
//         0046676f     NOP
    return;
}

long TPanel::xPosition() {
    /* TODO: Stub */
//                              long __thiscall xPosition(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?xPosition@TPanel@@QBEJXZ                                    XREF[24]:    TribeAboutDialog:0043afd9(c),
//                               TPanel::xPosition                                                         setup_help:0043eade(c),
//                                                                                                         setup_help:0043eafd(c),
//                                                                                                         setup_help:0043eb1c(c),
//                                                                                                         setup_help:0043eb2a(c),
//                                                                                                         setup:00473ca6(c),
//                                                                                                         set_mode:004748a2(c),
//                                                                                                         handle_mouse_move:00475578(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049e944(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9d1(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea16(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea47(c)
//                                                                                                         init_timeline:0051f445(c),
//                                                                                                         draw_axis:0051faea(c),
//                                                                                                         draw_axis:0051fb16(c),
//                                                                                                         draw_axis:0051fb3c(c),
//                                                                                                         draw_axis:0051fb60(c),
//                                                                                                         draw_axis:0051fb8f(c),
//                                                                                                         draw_axis:0051fbac(c),
//                                                                                                         draw_axis:0051fbdb(c), [more]
//                              Panel.cpp:2418 (3)
//         00466770     MOV        EAX,dword ptr [ECX + this->pnl_x]
//                              Panel.cpp:2420 (1)
//         00466773     RET
//         00466774     ??         90h
//         00466775     NOP
//         00466776     NOP
//         00466777     NOP
//         00466778     NOP
//         00466779     NOP
//         0046677a     NOP
//         0046677b     NOP
//         0046677c     NOP
//         0046677d     NOP
//         0046677e     NOP
//         0046677f     NOP
    return 0;
}

long TPanel::yPosition() {
    /* TODO: Stub */
//                              long __thiscall yPosition(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?yPosition@TPanel@@QBEJXZ                                    XREF[26]:    setup_help:0043eb6c(c),
//                               TPanel::yPosition                                                         setup_help:0043eb7e(c),
//                                                                                                         setup_help:0043eba0(c),
//                                                                                                         setup_help:0043ebc1(c),
//                                                                                                         setup:00473cad(c),
//                                                                                                         set_mode:004748b0(c),
//                                                                                                         set_mode:00474cfc(c),
//                                                                                                         set_mode:00474d27(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9c5(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea0a(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea3f(c)
//                                                                                                         init_timeline:0051f455(c),
//                                                                                                         draw_axis:0051facf(c),
//                                                                                                         draw_axis:0051fafc(c),
//                                                                                                         draw_axis:0051fb2a(c),
//                                                                                                         draw_axis:0051fb4e(c),
//                                                                                                         draw_axis:0051fb74(c),
//                                                                                                         draw_axis:0051fb9a(c),
//                                                                                                         draw_axis:0051fbc0(c),
//                                                                                                         draw_axis:0051fbed(c), [more]
//                              Panel.cpp:2425 (3)
//         00466780     MOV        EAX,dword ptr [ECX + this->pnl_y]
//                              Panel.cpp:2427 (1)
//         00466783     RET
//         00466784     ??         90h
//         00466785     NOP
//         00466786     NOP
//         00466787     NOP
//         00466788     NOP
//         00466789     NOP
//         0046678a     NOP
//         0046678b     NOP
//         0046678c     NOP
//         0046678d     NOP
//         0046678e     NOP
//         0046678f     NOP
    return 0;
}

long TPanel::width() {
    /* TODO: Stub */
//                              long __thiscall width(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?width@TPanel@@QBEJXZ                                        XREF[18]:    TribeAboutDialog:0043afe9(c),
//                               TPanel::width                                                             setup_help:0043ead5(c),
//                                                                                                         setup_help:0043eb3c(c),
//                                                                                                         setup:00473c94(c),
//                                                                                                         setup:00473d74(c),
//                                                                                                         set_mode:004748be(c),
//                                                                                                         handle_mouse_move:00475565(c),
//                                                                                                         set_scrollbar:0047c4eb(c),
//                                                                                                         handle_size:004962dd(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049e956(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9b9(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9fe(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea37(c)
//                                                                                                         create_all_buttons_etc:004afa8a(c)
//                                                                                                         create_timeline:0051e884(c),
//                                                                                                         create_timeline:0051e8b0(c),
//                                                                                                         init_timeline:0051f373(c),
//                                                                                                         draw_legend:00520d68(c)
//                              Panel.cpp:2432 (3)
//         00466790     MOV        EAX,dword ptr [ECX + this->pnl_wid]
//                              Panel.cpp:2434 (1)
//         00466793     RET
//         00466794     ??         90h
//         00466795     NOP
//         00466796     NOP
//         00466797     NOP
//         00466798     NOP
//         00466799     NOP
//         0046679a     NOP
//         0046679b     NOP
//         0046679c     NOP
//         0046679d     NOP
//         0046679e     NOP
//         0046679f     NOP
    return 0;
}

long TPanel::height() {
    /* TODO: Stub */
//                              long __thiscall height(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?height@TPanel@@QBEJXZ                                       XREF[17]:    setup_help:0043eb97(c),
//                               TPanel::height                                                            setup_help:0043ebd8(c),
//                                                                                                         setup:00473c9d(c),
//                                                                                                         setup:00473d7d(c),
//                                                                                                         set_mode:004748c8(c),
//                                                                                                         set_mode:00474d09(c),
//                                                                                                         set_mode:00474d34(c),
//                                                                                                         set_mode:00474d50(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9ad(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049e9f2(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea2f(c)
//                                                                                                         create_all_buttons_etc:004afa7d(c)
//                                                                                                         create_timeline:0051e899(c),
//                                                                                                         create_timeline:0051e8c3(c),
//                                                                                                         init_timeline:0051f426(c),
//                                                                                                         draw_axis:0051fd0d(c),
//                                                                                                         draw_special_events:0051ff57(c)
//                              Panel.cpp:2439 (3)
//         004667a0     MOV        EAX,dword ptr [ECX + this->pnl_hgt]
//                              Panel.cpp:2441 (1)
//         004667a3     RET
//         004667a4     ??         90h
//         004667a5     NOP
//         004667a6     NOP
//         004667a7     NOP
//         004667a8     NOP
//         004667a9     NOP
//         004667aa     NOP
//         004667ab     NOP
//         004667ac     NOP
//         004667ad     NOP
//         004667ae     NOP
//         004667af     NOP
    return 0;
}

TDrawArea* TPanel::renderArea() {
    /* TODO: Stub */
//                              TDrawArea * __thiscall renderArea(TPanel * this)
//              TDrawArea *       EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?renderArea@TPanel@@QBEPAVTDrawArea@@XZ                      XREF[13]:    TribeAboutDialog:0043ae2b(c),
//                               TPanel::renderArea                                                        TribeConfigDialog:0043b6cc(c),
//                                                                                                         TribeDiplomacyDialog:0043ca59(c),
//                                                                                                         setup_help:0043ea7b(c),
//                                                                                                         setup:0043efa1(c),
//                                                                                                         TribeMenuDialog:0043f3e2(c),
//                                                                                                         setup:0043fd81(c),
//                                                                                                         TRIBE_Dialog_Sed_Menu:004401b4(c),
//                                                                                                         TribeSendMessageDialog:004408a8(c)
//                                                                                                         TribeSendQuickMessageDialog:004415
//                                                                                                         TribeMPCreateDialog:0049215d(c),
//                                                                                                         TRIBE_Dialog_Name:004a6de4(c),
//                                                                                                         create_timeline:0051e981(c)
//                              Panel.cpp:2446 (3)
//         004667b0     MOV        EAX,dword ptr [ECX + this->render_area]
//                              Panel.cpp:2448 (1)
//         004667b3     RET
//         004667b4     ??         90h
//         004667b5     NOP
//         004667b6     NOP
//         004667b7     NOP
//         004667b8     NOP
//         004667b9     NOP
//         004667ba     NOP
//         004667bb     NOP
//         004667bc     NOP
//         004667bd     NOP
//         004667be     NOP
//         004667bf     NOP
    return 0;
}

tagRECT* TPanel::clipRectangle(tagRECT* __return_storage_ptr__) {
    /* TODO: Stub */
//                              tagRECT __thiscall clipRectangle(TPanel * this, tagRECT * __return_s
//              tagRECT           EAX:4 (ptr)    <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     004667c0(R)
//              tagRECT *         Stack[0x0]:4   __$ReturnUdt
//                               ?clipRectangle@TPanel@@QBE?AUtagRECT@@XZ
//                               TPanel::clipRectangle
//                              Panel.cpp:2453 (26)
//         004667c0     MOV        EAX,dword ptr [ESP + __return_storage_ptr__]
//         004667c4     ADD        this,0x24
//         004667c7     PUSH       ESI
//         004667c8     MOV        EDX,EAX
//         004667ca     MOV        ESI,dword ptr [this->_padding_]
//         004667cc     MOV        dword ptr [EDX],ESI
//         004667ce     MOV        ESI,dword ptr [ECX + this->previousPanelValue]
//         004667d1     MOV        dword ptr [EDX + 0x4],ESI
//         004667d4     MOV        ESI,dword ptr [ECX + this->previousModalPanelV
//         004667d7     MOV        dword ptr [EDX + 0x8],ESI
//                              Panel.cpp:2455 (10)
//         004667da     POP        ESI
//         004667db     MOV        this,dword ptr [ECX + this->pnl_x]
//         004667de     MOV        dword ptr [EDX + 0xc],this
//         004667e1     RET        0x4
//         004667e4     ??         90h
//         004667e5     NOP
//         004667e6     NOP
//         004667e7     NOP
//         004667e8     NOP
//         004667e9     NOP
//         004667ea     NOP
//         004667eb     NOP
//         004667ec     NOP
//         004667ed     NOP
//         004667ee     NOP
//         004667ef     NOP
    return 0;
}

void TPanel::setClipRectangle(tagRECT param_1) {
    /* TODO: Stub */
//                              void __thiscall setClipRectangle(TPanel * this, tagRECT param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT           Stack[0x4]:16  param_1                   XREF[1,3]:   004667f0(R), 004667f4(R), 004667fd(R), 00466804(R)
//                               ?setClipRectangle@TPanel@@QAEXUtagRECT@@@Z
//                               TPanel::setClipRectangle
//                              Panel.cpp:2460 (30)
//         004667f0     MOV        EAX,dword ptr [ESP + param_1.left]
//         004667f4     MOV        EDX,dword ptr [ESP + param_1.top]
//         004667f8     ADD        this,0x24
//         004667fb     MOV        dword ptr [this->_padding_],EAX
//         004667fd     MOV        EAX,dword ptr [ESP + param_1.right]
//         00466801     MOV        dword ptr [ECX + this->previousPanelValue],EDX
//         00466804     MOV        EDX,dword ptr [ESP + param_1.bottom]
//         00466808     MOV        dword ptr [ECX + this->previousModalPanelValue
//         0046680b     MOV        dword ptr [ECX + this->pnl_x],EDX
//                              Panel.cpp:2462 (3)
//         0046680e     RET        0x10
//         00466811     ??         90h
//         00466812     NOP
//         00466813     NOP
//         00466814     NOP
//         00466815     NOP
//         00466816     NOP
//         00466817     NOP
//         00466818     NOP
//         00466819     NOP
//         0046681a     NOP
//         0046681b     NOP
//         0046681c     NOP
//         0046681d     NOP
//         0046681e     NOP
//         0046681f     NOP
    return;
}

void TPanel::delete_panel(TPanel** param_1) {
    /* TODO: Stub */
//                              void __thiscall delete_panel(TPanel * this, TPanel * * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              TPanel * *        Stack[0x4]:4   param_1                   XREF[1]:     00466821(R)
//                               ?delete_panel@TPanel@@QAEXPAPAV1@@Z                          XREF[347]:   ~TribeAboutDialog:0043b332(c),
//                               TPanel::delete_panel                                                      ~TribeAboutDialog:0043b340(c),
//                                                                                                         ~TribeAboutDialog:0043b34e(c),
//                                                                                                         ~TribeAboutDialog:0043b35c(c),
//                                                                                                         ~TribeAboutDialog:0043b36a(c),
//                                                                                                         ~TribeAboutDialog:0043b378(c),
//                                                                                                         ~TribeAboutDialog:0043b386(c),
//                                                                                                         ~TribeAboutDialog:0043b394(c),
//                                                                                                         ~TribeAboutDialog:0043b3a2(c),
//                                                                                                         ~TribeAboutDialog:0043b3b0(c),
//                                                                                                         ~TribeAboutDialog:0043b3be(c),
//                                                                                                         ~TribeAboutDialog:0043b3cc(c),
//                                                                                                         ~TribeAboutDialog:0043b3da(c),
//                                                                                                         ~TribeMenuDialog:0043f6eb(c),
//                                                                                                         ~TRIBE_Screen_Main_Error:0049f272(
//                                                                                                         ~TRIBE_Screen_Main_Error:0049f280(
//                                                                                                         ~TRIBE_Screen_Wait:004a6084(c),
//                                                                                                         ~TRIBE_Screen_Wait:004a6092(c),
//                                                                                                         ~TRIBE_Screen_Wait:004a60a0(c),
//                                                                                                         ~TRIBE_Screen_Wait:004a60b3(c),
//                                                                                                         [more]
//                              Panel.cpp:2468 (1)
//         00466820     PUSH       ESI
//                              Panel.cpp:2469 (10)
//         00466821     MOV        ESI,dword ptr [ESP + param_1]
//         00466825     MOV        this,dword ptr [ESI]
//         00466827     TEST       this,this
//         00466829     JZ         LAB_00466837
//                              Panel.cpp:2471 (6)
//         0046682b     MOV        EAX,dword ptr [this->_padding_]
//         0046682d     PUSH       0x1
//         0046682f     CALL       dword ptr [EAX]
//                              Panel.cpp:2472 (6)
//         00466831     MOV        dword ptr [ESI],0x0
//                               LAB_00466837                                                 XREF[1]:     00466829(j)
//                              Panel.cpp:2474 (4)
//         00466837     POP        ESI
//         00466838     RET        0x4
//         0046683b     ??         90h
//         0046683c     NOP
//         0046683d     NOP
//         0046683e     NOP
//         0046683f     NOP
    return;
}

int TPanel::get_string(int param_1, char* param_2, int param_3) {
    /* TODO: Stub */
//                              char * __thiscall get_string(TPanel * this, int param_1)
//              char *            EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00466870(R)
//                               ?get_string@TPanel@@QAEPADH@Z                                XREF[106]:   action:00493ce2(c),
//                               TPanel::get_string                                                        TRIBE_Screen_Game:00494001(c),
//                                                                                                         TRIBE_Screen_Game:0049401c(c),
//                                                                                                         TRIBE_Screen_Game:00494037(c),
//                                                                                                         TRIBE_Screen_Game:00494060(c),
//                                                                                                         set_button:0049ad02(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea64(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea93(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049eaf6(c)
//                                                                                                         startGame:004a217e(c),
//                                                                                                         startGame:004a233d(c),
//                                                                                                         startGame:004a23a0(c),
//                                                                                                         startGame:004a275c(c),
//                                                                                                         TRIBE_Screen_Wait:004a57df(c),
//                                                                                                         TRIBE_Screen_Wait:004a5849(c),
//                                                                                                         TRIBE_Screen_Wait:004a5902(c),
//                                                                                                         TRIBE_Screen_Wait:004a59c8(c),
//                                                                                                         TRIBE_Screen_Wait:004a5aaa(c),
//                                                                                                         TRIBE_Screen_Wait:004a5ade(c),
//                                                                                                         TRIBE_Screen_Wait:004a5b6e(c),
//                                                                                                         [more]
//                              Panel.cpp:2499 (20)
//         00466870     MOV        EAX,dword ptr [ESP + param_1]
//         00466874     PUSH       0x200
//         00466879     PUSH       null_0062e670                                    = align(512)
//         0046687e     PUSH       EAX
//         0046687f     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              Panel.cpp:2501 (5)
//         00466884     MOV        EAX,null_0062e670                                = align(512)
//                              Panel.cpp:2502 (3)
//         00466889     RET        0x4
//         0046688c     ??         90h
//         0046688d     NOP
//         0046688e     NOP
//         0046688f     NOP
    return 0;
}

char* TPanel::get_string(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall get_string(TPanel * this, int param_1)
//              char *            EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00466870(R)
//                               ?get_string@TPanel@@QAEPADH@Z                                XREF[106]:   action:00493ce2(c),
//                               TPanel::get_string                                                        TRIBE_Screen_Game:00494001(c),
//                                                                                                         TRIBE_Screen_Game:0049401c(c),
//                                                                                                         TRIBE_Screen_Game:00494037(c),
//                                                                                                         TRIBE_Screen_Game:00494060(c),
//                                                                                                         set_button:0049ad02(c),
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea64(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049ea93(c)
//                                                                                                         TRIBE_Screen_Main_Menu:0049eaf6(c)
//                                                                                                         startGame:004a217e(c),
//                                                                                                         startGame:004a233d(c),
//                                                                                                         startGame:004a23a0(c),
//                                                                                                         startGame:004a275c(c),
//                                                                                                         TRIBE_Screen_Wait:004a57df(c),
//                                                                                                         TRIBE_Screen_Wait:004a5849(c),
//                                                                                                         TRIBE_Screen_Wait:004a5902(c),
//                                                                                                         TRIBE_Screen_Wait:004a59c8(c),
//                                                                                                         TRIBE_Screen_Wait:004a5aaa(c),
//                                                                                                         TRIBE_Screen_Wait:004a5ade(c),
//                                                                                                         TRIBE_Screen_Wait:004a5b6e(c),
//                                                                                                         [more]
//                              Panel.cpp:2499 (20)
//         00466870     MOV        EAX,dword ptr [ESP + param_1]
//         00466874     PUSH       0x200
//         00466879     PUSH       null_0062e670                                    = align(512)
//         0046687e     PUSH       EAX
//         0046687f     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              Panel.cpp:2501 (5)
//         00466884     MOV        EAX,null_0062e670                                = align(512)
//                              Panel.cpp:2502 (3)
//         00466889     RET        0x4
//         0046688c     ??         90h
//         0046688d     NOP
//         0046688e     NOP
//         0046688f     NOP
    return 0;
}

long TPanel::get_help_message() {
    /* TODO: Stub */
//                              long __thiscall get_help_message(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?get_help_message@TPanel@@QAEJXZ
//                               TPanel::get_help_message
//                              Panel.cpp:2508 (6)
//         00466890     MOV        EAX,dword ptr [ECX + this->help_string_id]
//                              Panel.cpp:2510 (1)
//         00466896     RET
//         00466897     ??         90h
//         00466898     NOP
//         00466899     NOP
//         0046689a     NOP
//         0046689b     NOP
//         0046689c     NOP
//         0046689d     NOP
//         0046689e     NOP
//         0046689f     NOP
    return 0;
}

long TPanel::get_help_page() {
    /* TODO: Stub */
//                              long __thiscall get_help_page(TPanel * this)
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?get_help_page@TPanel@@QAEJXZ
//                               TPanel::get_help_page
//                              Panel.cpp:2516 (6)
//         004668a0     MOV        EAX,dword ptr [ECX + this->help_page_id]
//                              Panel.cpp:2518 (1)
//         004668a6     RET
//         004668a7     ??         90h
//         004668a8     NOP
//         004668a9     NOP
//         004668aa     NOP
//         004668ab     NOP
//         004668ac     NOP
//         004668ad     NOP
//         004668ae     NOP
//         004668af     NOP
    return 0;
}

void TPanel::set_help_info(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall set_help_info(TPanel * this, long param_1, long para
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004668b0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004668b4(R)
//                               ?set_help_info@TPanel@@QAEXJJ@Z                              XREF[220]:   disable_unused_buttons:0049a8d3(c)
//                               TPanel::set_help_info                                                     set_button:0049ac45(c),
//                                                                                                         TribeSaveGameScreen:004a73ec(c),
//                                                                                                         TribeSaveGameScreen:004a743c(c),
//                                                                                                         TribeSaveGameScreen:004a74e6(c),
//                                                                                                         TribeSaveGameScreen:004a74f4(c),
//                                                                                                         TRIBE_Screen_Sed:004a84dd(c),
//                                                                                                         create_all_buttons_etc:004af707(c)
//                                                                                                         create_all_buttons_etc:004af733(c)
//                                                                                                         create_all_buttons_etc:004af75f(c)
//                                                                                                         create_all_buttons_etc:004af78b(c)
//                                                                                                         create_all_buttons_etc:004af7b7(c)
//                                                                                                         create_all_buttons_etc:004af7e3(c)
//                                                                                                         create_all_buttons_etc:004af80f(c)
//                                                                                                         create_all_buttons_etc:004af83b(c)
//                                                                                                         create_all_buttons_etc:004af867(c)
//                                                                                                         create_all_buttons_etc:004af893(c)
//                                                                                                         create_all_buttons_etc:004af8df(c)
//                                                                                                         create_all_buttons_etc:004af95f(c)
//                                                                                                         create_all_buttons_etc:004af98a(c)
//                                                                                                         [more]
//                              Panel.cpp:2524 (4)
//         004668b0     MOV        EAX,dword ptr [ESP + param_1]
//                              Panel.cpp:2526 (16)
//         004668b4     MOV        EDX,dword ptr [ESP + param_2]
//         004668b8     MOV        dword ptr [ECX + this->help_string_id],EAX
//         004668be     MOV        dword ptr [ECX + this->help_page_id],EDX
//                              Panel.cpp:2527 (3)
//         004668c4     RET        0x8
//         004668c7     ??         90h
//         004668c8     NOP
//         004668c9     NOP
//         004668ca     NOP
//         004668cb     NOP
//         004668cc     NOP
//         004668cd     NOP
//         004668ce     NOP
//         004668cf     NOP
    return;
}

uchar TPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              uchar __thiscall get_help_info(TPanel * this, char * * param_1, long
//              uchar             AL:1           <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              char * *          Stack[0x4]:4   param_1
//              long *            Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3                   XREF[1]:     004668ea(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004668e6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004668d7(W)
//                               ?get_help_info@TPanel@@UAEEAAPADAAJJJ@Z                      XREF[71]:    get_help_info:0054066a(c),
//                               TPanel::get_help_info                                                     0056f5d4(*), 0056f6dc(*),
//                                                                                                         0056f81c(*), 0056f964(*),
//                                                                                                         0056fa94(*), 0056fbc4(*),
//                                                                                                         0056fcfc(*), 0056fe2c(*),
//                                                                                                         0056ff5c(*), 0057008c(*),
//                                                                                                         005701bc(*), 00570d04(*),
//                                                                                                         00570de4(*), 00571094(*),
//                                                                                                         0057117c(*), 005712ac(*),
//                                                                                                         0057138c(*), 00571474(*),
//                                                                                                         00571554(*), [more]
//                              Panel.cpp:2533 (11)
//         004668d0     PUSH       this
//         004668d1     PUSH       EBX
//         004668d2     PUSH       EBP
//         004668d3     PUSH       ESI
//         004668d4     MOV        ESI,this
//         004668d6     PUSH       EDI
//         004668d7     MOV        dword ptr [ESP + local_4],ESI
//                              Panel.cpp:2536 (5)
//         004668db     MOV        EAX,dword ptr [ESI + 0x6c]
//         004668de     TEST       EAX,EAX
//                              Panel.cpp:2537 (6)
//         004668e0     JZ         LAB_00466974
//                              Panel.cpp:2539 (22)
//         004668e6     MOV        EDI,dword ptr [ESP + param_4]
//         004668ea     MOV        this,dword ptr [ESP + param_3]
//         004668ee     MOV        EAX,dword ptr [ESI]
//         004668f0     PUSH       EDI
//         004668f1     PUSH       this
//         004668f2     MOV        this,ESI
//         004668f4     CALL       dword ptr [EAX + 0xbc]
//         004668fa     TEST       EAX,EAX
//                              Panel.cpp:2540 (2)
//         004668fc     JZ         LAB_00466974
//                              Panel.cpp:2543 (15)
//         004668fe     MOV        ESI,dword ptr [ESI + 0x5c]
//         00466901     MOV        EBX,dword ptr [ESP + 0x1c]
//         00466905     MOV        EBP,dword ptr [ESP + 0x18]
//         00466909     TEST       ESI,ESI
//         0046690b     JZ         LAB_0046692a
//                               LAB_0046690d                                                 XREF[1]:     00466928(j)
//                              Panel.cpp:2544 (29)
//         0046690d     MOV        this,dword ptr [ESI]
//         0046690f     MOV        EAX,dword ptr [ESP + 0x20]
//         00466913     PUSH       EDI
//         00466914     PUSH       EAX=>DAT_fffffff8
//         00466915     MOV        EDX,dword ptr [this->_padding_]
//         00466917     PUSH       EBX=>DAT_fffffff4
//         00466918     PUSH       EBP=>DAT_fffffff0
//         00466919     CALL       dword ptr [EDX + 0xcc]
//         0046691f     TEST       AL,AL
//         00466921     JNZ        LAB_0046696a
//         00466923     MOV        ESI,dword ptr [ESI + 0x4]
//         00466926     TEST       ESI,ESI
//         00466928     JNZ        LAB_0046690d
//                               LAB_0046692a                                                 XREF[1]:     0046690b(j)
//                              Panel.cpp:2547 (14)
//         0046692a     MOV        this,dword ptr [ESP + 0x10]
//         0046692e     MOV        EAX,dword ptr [ECX + this->help_string_id]
//         00466934     TEST       EAX,EAX
//         00466936     JL         LAB_00466974
//                              Panel.cpp:2549 (19)
//         00466938     PUSH       EAX
//         00466939     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0046693e     MOV        EDI,EAX
//         00466940     OR         this,0xffffffff
//         00466943     XOR        EAX,EAX
//         00466945     SCASB.RE   ES:EDI
//         00466947     NOT        this
//         00466949     SUB        EDI,this
//                              Panel.cpp:2550 (31)
//         0046694b     MOV        EAX,dword ptr [ESP + 0x10]
//         0046694f     MOV        EDX,this
//         00466951     MOV        ESI,EDI
//         00466953     MOV        EDI,dword ptr [EBP]
//         00466956     SHR        this,0x2
//         00466959     MOVSD.REP  ES:EDI,ESI
//         0046695b     MOV        this,EDX
//         0046695d     AND        this,0x3
//         00466960     MOVSB.REP  ES:EDI,ESI
//         00466962     MOV        this,dword ptr [EAX + 0xe8]
//         00466968     MOV        dword ptr [EBX],this
//                               LAB_0046696a                                                 XREF[1]:     00466921(j)
//                              Panel.cpp:2551 (2)
//         0046696a     MOV        AL,0x1
//                              Panel.cpp:2555 (18)
//         0046696c     POP        EDI
//         0046696d     POP        ESI
//         0046696e     POP        EBP
//         0046696f     POP        EBX
//         00466970     POP        this
//         00466971     RET        0x10
//                               LAB_00466974                                                 XREF[3]:     004668e0(j), 004668fc(j),
//                                                                                                         00466936(j)
//         00466974     POP        EDI
//         00466975     POP        ESI
//         00466976     POP        EBP
//         00466977     XOR        AL,AL
//         00466979     POP        EBX
//         0046697a     POP        this
//         0046697b     RET        0x10
//         0046697e     ??         90h
//         0046697f     NOP
    return 0;
}

void TPanel::stop_sound_system() {
    /* TODO: Stub */
//                              void __thiscall stop_sound_system(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?stop_sound_system@TPanel@@UAEXXZ                            XREF[70]:    stop_sound_system:0049d51a(c),
//                               TPanel::stop_sound_system                                                 0056f5d8(*), 0056f6e0(*),
//                                                                                                         0056f820(*), 0056f968(*),
//                                                                                                         0056fa98(*), 0056fbc8(*),
//                                                                                                         0056fd00(*), 0056fe30(*),
//                                                                                                         0056ff60(*), 00570090(*),
//                                                                                                         005701c0(*), 00570d08(*),
//                                                                                                         00570de8(*), 00571180(*),
//                                                                                                         005712b0(*), 00571478(*),
//                                                                                                         00571558(*), 00571648(*),
//                                                                                                         00571738(*), [more]
//                              Panel.cpp:2561 (1)
//         00466980     PUSH       ESI
//                              Panel.cpp:2565 (7)
//         00466981     MOV        ESI,dword ptr [ECX + this->first_child_node]
//         00466984     TEST       ESI,ESI
//         00466986     JZ         LAB_00466999
//                               LAB_00466988                                                 XREF[1]:     00466997(j)
//                              Panel.cpp:2566 (17)
//         00466988     MOV        this,dword ptr [ESI]
//         0046698a     MOV        EAX,dword ptr [this->_padding_]
//         0046698c     CALL       dword ptr [EAX + 0xd0]
//         00466992     MOV        ESI,dword ptr [ESI + 0x8]
//         00466995     TEST       ESI,ESI
//         00466997     JNZ        LAB_00466988
//                               LAB_00466999                                                 XREF[1]:     00466986(j)
//                              Panel.cpp:2569 (2)
//         00466999     POP        ESI
//         0046699a     RET
//         0046699b     ??         90h
//         0046699c     NOP
//         0046699d     NOP
//         0046699e     NOP
//         0046699f     NOP
    return;
}

int TPanel::restart_sound_system() {
    /* TODO: Stub */
//                              int __thiscall restart_sound_system(TPanel * this)
//              int               EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?restart_sound_system@TPanel@@UAEHXZ                         XREF[70]:    restart_sound_system:0049d530(j),
//                               TPanel::restart_sound_system                                              0056f5dc(*), 0056f6e4(*),
//                                                                                                         0056f824(*), 0056f96c(*),
//                                                                                                         0056fa9c(*), 0056fbcc(*),
//                                                                                                         0056fd04(*), 0056fe34(*),
//                                                                                                         0056ff64(*), 00570094(*),
//                                                                                                         005701c4(*), 00570d0c(*),
//                                                                                                         00570dec(*), 00571184(*),
//                                                                                                         005712b4(*), 0057147c(*),
//                                                                                                         0057155c(*), 0057164c(*),
//                                                                                                         0057173c(*), [more]
//                              Panel.cpp:2575 (1)
//         004669a0     PUSH       ESI
//                              Panel.cpp:2580 (13)
//         004669a1     MOV        ESI,dword ptr [ECX + this->first_child_node]
//         004669a4     PUSH       EDI
//         004669a5     MOV        EDI,0x1
//         004669aa     TEST       ESI,ESI
//         004669ac     JZ         LAB_004669c5
//                               LAB_004669ae                                                 XREF[1]:     004669c3(j)
//                              Panel.cpp:2582 (14)
//         004669ae     MOV        this,dword ptr [ESI]
//         004669b0     MOV        EAX,dword ptr [this->_padding_]
//         004669b2     CALL       dword ptr [EAX + 0xd4]
//         004669b8     TEST       EAX,EAX
//         004669ba     JNZ        LAB_004669be
//                              Panel.cpp:2583 (2)
//         004669bc     XOR        EDI,EDI
//                               LAB_004669be                                                 XREF[1]:     004669ba(j)
//                              Panel.cpp:2580 (7)
//         004669be     MOV        ESI,dword ptr [ESI + 0x8]
//         004669c1     TEST       ESI,ESI
//         004669c3     JNZ        LAB_004669ae
//                               LAB_004669c5                                                 XREF[1]:     004669ac(j)
//                              Panel.cpp:2588 (2)
//         004669c5     MOV        EAX,EDI
//                              Panel.cpp:2589 (3)
//         004669c7     POP        EDI
//         004669c8     POP        ESI
//         004669c9     RET
//         004669ca     ??         90h
//         004669cb     NOP
//         004669cc     NOP
//         004669cd     NOP
//         004669ce     NOP
//         004669cf     NOP
    return 0;
}

void TPanel::handle_reactivate() {
    /* TODO: Stub */
//                              void __thiscall handle_reactivate(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?handle_reactivate@TPanel@@UAEXXZ                            XREF[72]:    0056f5e4(*), 0056f6ec(*),
//                               TPanel::handle_reactivate                                                 0056f82c(*), 0056f974(*),
//                                                                                                         0056faa4(*), 0056fbd4(*),
//                                                                                                         0056fd0c(*), 0056fe3c(*),
//                                                                                                         0056ff6c(*), 0057009c(*),
//                                                                                                         005701cc(*), 00570d14(*),
//                                                                                                         00570df4(*), 005710a4(*),
//                                                                                                         0057118c(*), 005712bc(*),
//                                                                                                         0057139c(*), 00571564(*),
//                                                                                                         00571654(*), 00571744(*), [more]
//                              Panel.cpp:2595 (1)
//         004669d0     PUSH       ESI
//                              Panel.cpp:2596 (7)
//         004669d1     MOV        ESI,dword ptr [ECX + this->first_child_node]
//         004669d4     TEST       ESI,ESI
//         004669d6     JZ         LAB_004669e9
//                               LAB_004669d8                                                 XREF[1]:     004669e7(j)
//                              Panel.cpp:2597 (17)
//         004669d8     MOV        this,dword ptr [ESI]
//         004669da     MOV        EAX,dword ptr [this->_padding_]
//         004669dc     CALL       dword ptr [EAX + 0xdc]
//         004669e2     MOV        ESI,dword ptr [ESI + 0x8]
//         004669e5     TEST       ESI,ESI
//         004669e7     JNZ        LAB_004669d8
//                               LAB_004669e9                                                 XREF[1]:     004669d6(j)
//                              Panel.cpp:2598 (2)
//         004669e9     POP        ESI
//         004669ea     RET
//         004669eb     ??         90h
//         004669ec     NOP
//         004669ed     NOP
//         004669ee     NOP
//         004669ef     NOP
    return;
}

void TPanel::get_true_render_rect(tagRECT* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_true_render_rect(TPanel * this, tagRECT * param_1)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     004669f0(R)
//                               ?get_true_render_rect@TPanel@@UAEXAAUtagRECT@@@Z             XREF[70]:    0056f5c0(*), 0056f6c8(*),
//                               TPanel::get_true_render_rect                                              0056f808(*), 0056f950(*),
//                                                                                                         0056fa80(*), 0056fbb0(*),
//                                                                                                         0056fce8(*), 0056fe18(*),
//                                                                                                         0056ff48(*), 00570078(*),
//                                                                                                         005701a8(*), 00570cf0(*),
//                                                                                                         00570dd0(*), 00571080(*),
//                                                                                                         00571168(*), 00571298(*),
//                                                                                                         00571378(*), 00571460(*),
//                                                                                                         00571540(*), 00571630(*), [more]
//                              Panel.cpp:2605 (12)
//         004669f0     MOV        EAX,dword ptr [ESP + param_1]
//         004669f4     MOV        EDX,dword ptr [ECX + this->render_rect.left]
//         004669fa     MOV        dword ptr [EAX],EDX
//                              Panel.cpp:2608 (9)
//         004669fc     MOV        EDX,dword ptr [ECX + this+0x90]
//         00466a02     MOV        dword ptr [EAX + 0x4],EDX
//                              Panel.cpp:2609 (9)
//         00466a05     MOV        EDX,dword ptr [ECX + this+0x94]
//         00466a0b     MOV        dword ptr [EAX + 0x8],EDX
//                              Panel.cpp:2610 (9)
//         00466a0e     MOV        this,dword ptr [ECX + this+0x98]
//         00466a14     MOV        dword ptr [EAX + 0xc],this
//                              Panel.cpp:2612 (3)
//         00466a17     RET        0x4
//         00466a1a     ??         90h
//         00466a1b     NOP
//         00466a1c     NOP
//         00466a1d     NOP
//         00466a1e     NOP
//         00466a1f     NOP
    return;
}

