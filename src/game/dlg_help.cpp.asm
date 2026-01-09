#include "common.h"
#include "dlg_help.h"

THelpDialog::THelpDialog(TEasy_Panel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall THelpDialog(THelpDialog * this, TEasy_Panel * p
    //              undefined         <UNASSIGNED>   <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              TEasy_Panel *     Stack[0x4]:4   param_1                   XREF[1]:     0043e895(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043e88f(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0043e867(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0043e88a(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0043e885(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0043e881(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043e86e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043e8a2(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043e85e(W)  
    //                               ??0THelpDialog@@QAE@PAVTEasy_Panel@@PADJJJJ@Z                XREF[1]:     command_help:0046a2c5(c)  
    //                               THelpDialog::THelpDialog
    //                              dlg_help.cpp:57 (39)
    //         0043e840     PUSH       -0x1
    //         0043e842     PUSH       FUN_0055d088
    //         0043e847     MOV        EAX,FS:[0x0]
    //         0043e84d     PUSH       EAX
    //         0043e84e     MOV        dword ptr FS:[0x0],ESP
    //         0043e855     PUSH       this
    //         0043e856     PUSH       ESI
    //         0043e857     MOV        ESI,this
    //         0043e859     PUSH       s_Help_Dialog                                    = "Help Dialog"
    //         0043e85e     MOV        dword ptr [ESP + local_10],ESI
    //         0043e862     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              dlg_help.cpp:58 (26)
    //         0043e867     MOV        EAX,dword ptr [ESP + param_3]
    //         0043e86b     MOV        this,ESI
    //         0043e86d     PUSH       EAX
    //         0043e86e     MOV        dword ptr [ESP + local_4],0x0
    //         0043e876     MOV        dword ptr [ESI],THelpDialog::`vftable'           = 0043e8c0
    //         0043e87c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //                              dlg_help.cpp:60 (33)
    //         0043e881     MOV        this,dword ptr [ESP + param_6]
    //         0043e885     MOV        EDX,dword ptr [ESP + param_5]
    //         0043e889     PUSH       this
    //         0043e88a     MOV        this,dword ptr [ESP + param_4]
    //         0043e88e     PUSH       EDX
    //         0043e88f     MOV        EDX,dword ptr [ESP + param_2]
    //         0043e893     PUSH       this
    //         0043e894     PUSH       EAX
    //         0043e895     MOV        EAX,dword ptr [ESP + param_1]
    //         0043e899     PUSH       EDX
    //         0043e89a     PUSH       EAX
    //         0043e89b     MOV        this,ESI
    //         0043e89d     CALL       THelpDialog::setup_help                          void setup_help(THelpDialog * this, TEasy_Pan
    //                              dlg_help.cpp:61 (20)
    //         0043e8a2     MOV        this,dword ptr [ESP + local_c]
    //         0043e8a6     MOV        EAX,ESI
    //         0043e8a8     MOV        dword ptr FS:[0x0],this
    //         0043e8af     POP        ESI
    //         0043e8b0     ADD        ESP,0x10
    //         0043e8b3     RET        0x18
    //         0043e8b6     ??         90h
    //         0043e8b7     NOP
    //         0043e8b8     NOP
    //         0043e8b9     NOP
    //         0043e8ba     NOP
    //         0043e8bb     NOP
    //         0043e8bc     NOP
    //         0043e8bd     NOP
    //         0043e8be     NOP
    //         0043e8bf     NOP
}

THelpDialog::THelpDialog(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall THelpDialog(THelpDialog * this, TEasy_Panel * p
    //              undefined         <UNASSIGNED>   <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              TEasy_Panel *     Stack[0x4]:4   param_1                   XREF[1]:     0043e91e(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043e919(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     0043e914(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0043e90f(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0043e90b(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0043e907(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043e927(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043e93a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043e8fe(W)  
    //                               ??0THelpDialog@@QAE@PAVTEasy_Panel@@PAD1JJJ@Z                XREF[1]:     command_help:0046a33b(c)  
    //                               THelpDialog::THelpDialog
    //                              dlg_help.cpp:68 (39)
    //         0043e8e0     PUSH       -0x1
    //         0043e8e2     PUSH       FUN_0055d0a8
    //         0043e8e7     MOV        EAX,FS:[0x0]
    //         0043e8ed     PUSH       EAX
    //         0043e8ee     MOV        dword ptr FS:[0x0],ESP
    //         0043e8f5     PUSH       this
    //         0043e8f6     PUSH       ESI
    //         0043e8f7     MOV        ESI,this
    //         0043e8f9     PUSH       s_Help_Dialog                                    = "Help Dialog"
    //         0043e8fe     MOV        dword ptr [ESP + local_10],ESI
    //         0043e902     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              dlg_help.cpp:69 (51)
    //         0043e907     MOV        EAX,dword ptr [ESP + param_6]
    //         0043e90b     MOV        this,dword ptr [ESP + param_5]
    //         0043e90f     MOV        EDX,dword ptr [ESP + param_4]
    //         0043e913     PUSH       EAX
    //         0043e914     MOV        EAX,dword ptr [ESP + param_3]
    //         0043e918     PUSH       this
    //         0043e919     MOV        this,dword ptr [ESP + param_2]
    //         0043e91d     PUSH       EDX
    //         0043e91e     MOV        EDX,dword ptr [ESP + param_1]
    //         0043e922     PUSH       EAX
    //         0043e923     PUSH       this
    //         0043e924     PUSH       EDX
    //         0043e925     MOV        this,ESI
    //         0043e927     MOV        dword ptr [ESP + local_4],0x0
    //         0043e92f     MOV        dword ptr [ESI],THelpDialog::`vftable'           = 0043e8c0
    //         0043e935     CALL       THelpDialog::setup_help                          void setup_help(THelpDialog * this, TEasy_Pan
    //                              dlg_help.cpp:70 (20)
    //         0043e93a     MOV        this,dword ptr [ESP + local_c]
    //         0043e93e     MOV        EAX,ESI
    //         0043e940     MOV        dword ptr FS:[0x0],this
    //         0043e947     POP        ESI
    //         0043e948     ADD        ESP,0x10
    //         0043e94b     RET        0x18
    //         0043e94e     ??         90h
    //         0043e94f     NOP
}

THelpDialog::~THelpDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~THelpDialog(THelpDialog * this)
    //              void              <VOID>         <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043e979(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043e969(W)  
    //                               ??1THelpDialog@@UAE@XZ                                       XREF[1]:     `scalar_deleting_destructor':0043e
    //                               THelpDialog::~THelpDialog
    //                              dlg_help.cpp:76 (35)
    //         0043e950     PUSH       -0x1
    //         0043e952     PUSH       FUN_0055d0c8
    //         0043e957     MOV        EAX,FS:[0x0]
    //         0043e95d     PUSH       EAX
    //         0043e95e     MOV        dword ptr FS:[0x0],ESP
    //         0043e965     PUSH       this
    //         0043e966     PUSH       ESI
    //         0043e967     MOV        ESI,this
    //         0043e969     MOV        dword ptr [ESP + local_10],ESI
    //         0043e96d     MOV        dword ptr [ESI],THelpDialog::`vftable'           = 0043e8c0
    //                              dlg_help.cpp:77 (18)
    //         0043e973     MOV        this,dword ptr [ESI + 0x59c]
    //         0043e979     MOV        dword ptr [ESP + local_4],0x0
    //         0043e981     TEST       this,this
    //         0043e983     JZ         LAB_0043e98b
    //                              dlg_help.cpp:78 (6)
    //         0043e985     MOV        EAX,dword ptr [this->_padding_]
    //         0043e987     PUSH       0x1
    //         0043e989     CALL       dword ptr [EAX]
    //                               LAB_0043e98b                                                 XREF[1]:     0043e983(j)  
    //                              dlg_help.cpp:80 (10)
    //         0043e98b     MOV        this,dword ptr [ESI + 0x5a0]
    //         0043e991     TEST       this,this
    //         0043e993     JZ         LAB_0043e99b
    //                              dlg_help.cpp:81 (6)
    //         0043e995     MOV        EDX,dword ptr [this->_padding_]
    //         0043e997     PUSH       0x1
    //         0043e999     CALL       dword ptr [EDX]
    //                               LAB_0043e99b                                                 XREF[1]:     0043e993(j)  
    //                              dlg_help.cpp:83 (10)
    //         0043e99b     MOV        this,dword ptr [ESI + 0x598]
    //         0043e9a1     TEST       this,this
    //         0043e9a3     JZ         LAB_0043e9ab
    //                              dlg_help.cpp:84 (6)
    //         0043e9a5     MOV        EAX,dword ptr [this->_padding_]
    //         0043e9a7     PUSH       0x1
    //         0043e9a9     CALL       dword ptr [EAX]
    //                               LAB_0043e9ab                                                 XREF[1]:     0043e9a3(j)  
    //                              dlg_help.cpp:86 (10)
    //         0043e9ab     MOV        this,dword ptr [ESI + 0x594]
    //         0043e9b1     TEST       this,this
    //         0043e9b3     JZ         LAB_0043e9bb
    //                              dlg_help.cpp:87 (8)
    //         0043e9b5     MOV        EDX,dword ptr [this->_padding_]
    //         0043e9b7     PUSH       0x1
    //         0043e9b9     CALL       dword ptr [EDX]
    //                               LAB_0043e9bb                                                 XREF[1]:     0043e9b3(j)  
    //         0043e9bb     MOV        this,ESI
    //                              dlg_help.cpp:88 (29)
    //         0043e9bd     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         0043e9c5     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         0043e9ca     MOV        this,dword ptr [ESP + 0x8]
    //         0043e9ce     POP        ESI
    //         0043e9cf     MOV        dword ptr FS:[0x0],this
    //         0043e9d6     ADD        ESP,0x10
    //         0043e9d9     RET
    //         0043e9da     ??         90h
    //         0043e9db     NOP
    //         0043e9dc     NOP
    //         0043e9dd     NOP
    //         0043e9de     NOP
    //         0043e9df     NOP
}

void THelpDialog::setup_help(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
    //                              void __thiscall setup_help(THelpDialog * this, TEasy_Panel * param_1
    //              void              <VOID>         <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              TEasy_Panel *     Stack[0x4]:4   param_1                   XREF[1]:     0043ea51(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043e9e9(R)  
    //              char *            Stack[0xc]:4   param_3
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0043ea3c(R)  
    //              long              Stack[0x14]:4  param_5
    //              long              Stack[0x18]:4  param_6
    //              TPanel *[2]       Stack[-0xc]:8  tabList                   XREF[1]:     0043ea5c(W)  
    //              RGE_Font *        Stack[-0x10]:4 rge_text_font
    //                               ?setup_help@THelpDialog@@IAEXPAVTEasy_Panel@@PAD1JJJ@Z       XREF[2]:     THelpDialog:0043e89d(c), 
    //                               THelpDialog::setup_help                                                   THelpDialog:0043e935(c)  
    //                              dlg_help.cpp:94 (9)
    //         0043e9e0     SUB        ESP,0xc
    //         0043e9e3     PUSH       EBX
    //         0043e9e4     PUSH       EBP
    //         0043e9e5     MOV        EBP,this
    //         0043e9e7     PUSH       ESI
    //         0043e9e8     PUSH       EDI
    //                              dlg_help.cpp:105 (63)
    //         0043e9e9     MOV        EDI,dword ptr [ESP + param_2]
    //         0043e9ed     LEA        EBX,[EBP + 0x598]
    //         0043e9f3     OR         this,0xffffffff
    //         0043e9f6     XOR        EAX,EAX
    //         0043e9f8     MOV        dword ptr [EBP + 0x59c],0x0
    //         0043ea02     MOV        dword ptr [EBP + 0x5a0],0x0
    //         0043ea0c     MOV        dword ptr [EBP + 0x594],0x0
    //         0043ea16     MOV        dword ptr [EBX],0x0
    //         0043ea1c     LEA        EDX,[EBP + 0x494]
    //         0043ea22     SCASB.RE   ES:EDI
    //         0043ea24     NOT        this
    //         0043ea26     SUB        EDI,this
    //                              dlg_help.cpp:107 (41)
    //         0043ea28     PUSH       0xb
    //         0043ea2a     MOV        EAX,this
    //         0043ea2c     MOV        ESI,EDI
    //         0043ea2e     MOV        EDI,EDX
    //         0043ea30     SHR        this,0x2
    //         0043ea33     MOVSD.REP  ES:EDI,ESI
    //         0043ea35     MOV        this,EAX
    //         0043ea37     AND        this,0x3
    //         0043ea3a     MOVSB.REP  ES:EDI,ESI
    //         0043ea3c     MOV        this,dword ptr [ESP + param_4]
    //         0043ea40     MOV        dword ptr [EBP + 0x490],this
    //         0043ea46     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ea4c     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              dlg_help.cpp:109 (64)
    //         0043ea51     MOV        EDI,dword ptr [ESP + param_1]
    //         0043ea55     MOV        ESI,dword ptr [EBP]
    //         0043ea58     PUSH       0x1
    //         0043ea5a     MOV        this,EDI
    //         0043ea5c     MOV        dword ptr [ESP + tabList[0]],EAX
    //         0043ea60     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0043ea65     PUSH       EAX
    //         0043ea66     MOV        this,EDI
    //         0043ea68     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0043ea6d     PUSH       EAX
    //         0043ea6e     PUSH       0x190
    //         0043ea73     PUSH       0x154
    //         0043ea78     PUSH       EDI
    //         0043ea79     MOV        this,EDI
    //         0043ea7b     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         0043ea80     PUSH       EAX
    //         0043ea81     MOV        this,EBP
    //         0043ea83     CALL       dword ptr [ESI + 0x12c]
    //         0043ea89     TEST       EAX,EAX
    //         0043ea8b     JZ         LAB_0043ed27
    //                              dlg_help.cpp:113 (37)
    //         0043ea91     MOV        EDX,dword ptr [ESP + 0x28]
    //         0043ea95     PUSH       0x1
    //         0043ea97     PUSH       0x0=>DAT_fffffff8
    //         0043ea99     PUSH       0x0=>DAT_fffffff4
    //         0043ea9b     PUSH       offset DAT_fffffff0
    //         0043ea9d     PUSH       0x186
    //         0043eaa2     PUSH       0x14a
    //         0043eaa7     PUSH       0xa
    //         0043eaa9     PUSH       0xa
    //         0043eaab     PUSH       EDX
    //         0043eaac     PUSH       EBX
    //         0043eaad     PUSH       EBP
    //         0043eaae     MOV        this,EBP
    //         0043eab0     CALL       dword ptr [ESI + 0x100]
    //                              dlg_help.cpp:116 (2)
    //         0043eab6     MOV        EAX,dword ptr [EBX]
    //                              dlg_help.cpp:117 (23)
    //         0043eab8     MOV        this,dword ptr [ESP + 0x10]
    //         0043eabc     MOVSX      ESI,word ptr [EAX + 0xfe]
    //         0043eac3     ADD        ESI,0x2
    //         0043eac6     MOV        EAX,ESI
    //         0043eac8     IMUL       EAX,dword ptr [ECX + this->_padding_]
    //         0043eacc     ADD        EAX,0x37
    //                              dlg_help.cpp:121 (44)
    //         0043eacf     MOV        this,EDI
    //         0043ead1     MOV        dword ptr [ESP + 0x20],EAX
    //         0043ead5     CALL       TPanel::width                                    long width(TPanel * this)
    //         0043eada     MOV        this,EDI
    //         0043eadc     MOV        EBX,EAX
    //         0043eade     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0043eae3     ADD        EBX,EAX
    //         0043eae5     MOV        dword ptr [ESP + 0x24],EBX
    //         0043eae9     MOV        EBX,dword ptr [ESP + 0x30]
    //         0043eaed     MOV        EAX,dword ptr [ESP + 0x24]
    //         0043eaf1     LEA        EDX,[EBX + 0x163]
    //         0043eaf7     CMP        EAX,EDX
    //         0043eaf9     JL         LAB_0043eb14
    //                              dlg_help.cpp:123 (23)
    //         0043eafb     MOV        this,EDI
    //         0043eafd     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0043eb02     MOV        this,0xfffffffb
    //         0043eb07     SUB        this,EBX
    //         0043eb09     ADD        EAX,this
    //         0043eb0b     CDQ
    //         0043eb0c     MOV        EBX,EAX
    //         0043eb0e     XOR        EBX,EDX
    //         0043eb10     SUB        EBX,EDX
    //                              dlg_help.cpp:126 (18)
    //         0043eb12     JMP        LAB_0043eb4e
    //                               LAB_0043eb14                                                 XREF[1]:     0043eaf9(j)  
    //         0043eb14     MOV        this,EDI
    //         0043eb16     ADD        EBX,0xfffffea7
    //         0043eb1c     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0043eb21     ADD        EAX,0xa
    //                              dlg_help.cpp:127 (22)
    //         0043eb24     MOV        this,EDI
    //         0043eb26     CMP        EAX,EBX
    //         0043eb28     JG         LAB_0043eb3c
    //         0043eb2a     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0043eb2f     SUB        EBX,EAX
    //         0043eb31     MOV        EAX,EBX
    //         0043eb33     CDQ
    //         0043eb34     MOV        EBX,EAX
    //         0043eb36     XOR        EBX,EDX
    //         0043eb38     SUB        EBX,EDX
    //                              dlg_help.cpp:128 (2)
    //         0043eb3a     JMP        LAB_0043eb4e
    //                               LAB_0043eb3c                                                 XREF[1]:     0043eb28(j)  
    //                              dlg_help.cpp:130 (18)
    //         0043eb3c     CALL       TPanel::width                                    long width(TPanel * this)
    //         0043eb41     CDQ
    //         0043eb42     SUB        EAX,EDX
    //         0043eb44     MOV        EBX,EAX
    //         0043eb46     SAR        EBX,0x1
    //         0043eb48     SUB        EBX,0xaa
    //                               LAB_0043eb4e                                                 XREF[2]:     0043eb12(j), 0043eb3a(j)  
    //                              dlg_help.cpp:131 (8)
    //         0043eb4e     TEST       EBX,EBX
    //         0043eb50     MOV        dword ptr [ESP + 0x24],EBX
    //         0043eb54     JGE        LAB_0043eb5c
    //                              dlg_help.cpp:132 (6)
    //         0043eb56     XOR        EBX,EBX
    //         0043eb58     MOV        dword ptr [ESP + 0x24],EBX
    //                               LAB_0043eb5c                                                 XREF[1]:     0043eb54(j)  
    //                              dlg_help.cpp:137 (25)
    //         0043eb5c     MOV        EAX,dword ptr [ESP + 0x34]
    //         0043eb60     MOV        EDX,dword ptr [ESP + 0x20]
    //         0043eb64     SUB        EAX,EDX
    //         0043eb66     MOV        this,EDI
    //         0043eb68     MOV        dword ptr [ESP + 0x28],EAX
    //         0043eb6c     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
    //         0043eb71     MOV        EDX,dword ptr [ESP + 0x28]
    //                              dlg_help.cpp:139 (32)
    //         0043eb75     MOV        this,EDI
    //         0043eb77     ADD        EDX,-0xa
    //         0043eb7a     CMP        EAX,EDX
    //         0043eb7c     JG         LAB_0043eb97
    //         0043eb7e     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
    //         0043eb83     MOV        this,EAX
    //         0043eb85     MOV        EAX,dword ptr [ESP + 0x28]
    //         0043eb89     SUB        EAX,this
    //         0043eb8b     SUB        EAX,0xa
    //         0043eb8e     CDQ
    //         0043eb8f     MOV        this,EAX
    //         0043eb91     XOR        this,EDX
    //         0043eb93     SUB        this,EDX
    //                              dlg_help.cpp:142 (40)
    //         0043eb95     JMP        LAB_0043ebf3
    //                               LAB_0043eb97                                                 XREF[1]:     0043eb7c(j)  
    //         0043eb97     CALL       TPanel::height                                   long height(TPanel * this)
    //         0043eb9c     MOV        this,EDI
    //         0043eb9e     MOV        EBX,EAX
    //         0043eba0     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
    //         0043eba5     MOV        EDX,dword ptr [ESP + 0x20]
    //         0043eba9     ADD        EBX,EAX
    //         0043ebab     MOV        dword ptr [ESP + 0x28],EBX
    //         0043ebaf     MOV        EBX,dword ptr [ESP + 0x34]
    //         0043ebb3     MOV        this,dword ptr [ESP + 0x28]
    //         0043ebb7     LEA        EAX,[EDX + EBX*0x1 + 0xa]
    //         0043ebbb     CMP        EAX,this
    //                              dlg_help.cpp:143 (25)
    //         0043ebbd     MOV        this,EDI
    //         0043ebbf     JG         LAB_0043ebd8
    //         0043ebc1     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
    //         0043ebc6     MOV        EDX,EAX
    //         0043ebc8     MOV        EAX,EBX
    //         0043ebca     SUB        EAX,EDX
    //         0043ebcc     ADD        EAX,0xa
    //         0043ebcf     CDQ
    //         0043ebd0     MOV        this,EAX
    //         0043ebd2     XOR        this,EDX
    //         0043ebd4     SUB        this,EDX
    //                              dlg_help.cpp:144 (2)
    //         0043ebd6     JMP        LAB_0043ebef
    //                               LAB_0043ebd8                                                 XREF[1]:     0043ebbf(j)  
    //                              dlg_help.cpp:146 (27)
    //         0043ebd8     CALL       TPanel::height                                   long height(TPanel * this)
    //         0043ebdd     CDQ
    //         0043ebde     SUB        EAX,EDX
    //         0043ebe0     MOV        this,EAX
    //         0043ebe2     MOV        EAX,dword ptr [ESP + 0x20]
    //         0043ebe6     CDQ
    //         0043ebe7     SUB        EAX,EDX
    //         0043ebe9     SAR        this,0x1
    //         0043ebeb     SAR        EAX,0x1
    //         0043ebed     SUB        this,EAX
    //                               LAB_0043ebef                                                 XREF[1]:     0043ebd6(j)  
    //         0043ebef     MOV        EBX,dword ptr [ESP + 0x24]
    //                               LAB_0043ebf3                                                 XREF[1]:     0043eb95(j)  
    //                              dlg_help.cpp:147 (4)
    //         0043ebf3     TEST       this,this
    //         0043ebf5     JGE        LAB_0043ebf9
    //                              dlg_help.cpp:148 (2)
    //         0043ebf7     XOR        this,this
    //                               LAB_0043ebf9                                                 XREF[1]:     0043ebf5(j)  
    //                              dlg_help.cpp:153 (20)
    //         0043ebf9     MOV        EAX,dword ptr [ESP + 0x20]
    //         0043ebfd     MOV        EDI,dword ptr [EBP]
    //         0043ec00     PUSH       EAX
    //         0043ec01     PUSH       offset DAT_fffffff8
    //         0043ec06     PUSH       this=>DAT_fffffff4
    //         0043ec07     PUSH       EBX=>DAT_fffffff0
    //         0043ec08     MOV        this,EBP
    //         0043ec0a     CALL       dword ptr [EDI + 0x1c]
    //                              dlg_help.cpp:154 (22)
    //         0043ec0d     MOV        this,dword ptr [EBP + 0xb8]
    //         0043ec13     MOV        EDX,dword ptr [EBP + 0xb0]
    //         0043ec19     PUSH       this
    //         0043ec1a     PUSH       EDX=>DAT_fffffff8
    //         0043ec1b     MOV        this,EBP
    //         0043ec1d     CALL       dword ptr [EDI + 0xe4]
    //                              dlg_help.cpp:157 (31)
    //         0043ec23     MOV        EBX,dword ptr [ESP + 0x10]
    //         0043ec27     MOV        EDX,ESI
    //         0043ec29     MOV        this,dword ptr [EBP + 0x598]
    //         0043ec2f     IMUL       EDX,dword ptr [EBX + 0x8]
    //         0043ec33     MOV        EAX,dword ptr [this->_padding_]
    //         0043ec35     PUSH       EDX
    //         0043ec36     PUSH       offset DAT_fffffff8
    //         0043ec3b     PUSH       offset DAT_fffffff4
    //         0043ec3d     PUSH       offset DAT_fffffff0
    //         0043ec3f     CALL       dword ptr [EAX + 0x1c]
    //                              dlg_help.cpp:163 (23)
    //         0043ec42     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ec48     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043ec4d     TEST       EAX,EAX
    //         0043ec4f     JZ         LAB_0043ec97
    //         0043ec51     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0043ec55     TEST       EAX,EAX
    //         0043ec57     JL         LAB_0043ec97
    //                              dlg_help.cpp:165 (8)
    //         0043ec59     PUSH       EAX
    //         0043ec5a     MOV        this,EBP
    //         0043ec5c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //                              dlg_help.cpp:166 (9)
    //         0043ec61     TEST       EAX,EAX
    //         0043ec63     JZ         LAB_0043ec97
    //         0043ec65     CMP        byte ptr [EAX],0x0
    //         0043ec68     JZ         LAB_0043ec97
    //                              dlg_help.cpp:167 (45)
    //         0043ec6a     MOV        EAX,ESI
    //         0043ec6c     PUSH       0x0
    //         0043ec6e     IMUL       EAX,dword ptr [EBX + 0x8]
    //         0043ec72     PUSH       0x0=>DAT_fffffff8
    //         0043ec74     PUSH       offset DAT_fffffff4
    //         0043ec76     PUSH       offset DAT_fffffff0
    //         0043ec78     ADD        EAX,0x14
    //         0043ec7b     PUSH       0x78
    //         0043ec7d     PUSH       EAX
    //         0043ec7e     PUSH       0x19
    //         0043ec80     PUSH       0x0
    //         0043ec82     LEA        EAX,[EBP + 0x5a0]
    //                              language.dll match for 0x243d: "More Help"
    //         0043ec88     PUSH       0x243d
    //         0043ec8d     PUSH       EAX
    //         0043ec8e     PUSH       EBP
    //         0043ec8f     MOV        this,EBP
    //         0043ec91     CALL       dword ptr [EDI + 0xe8]
    //                               LAB_0043ec97                                                 XREF[4]:     0043ec4f(j), 0043ec57(j), 
    //                                                                                                         0043ec63(j), 0043ec68(j)  
    //                              dlg_help.cpp:171 (6)
    //         0043ec97     MOV        EAX,dword ptr [EBP + 0x5a0]
    //                              dlg_help.cpp:172 (24)
    //         0043ec9d     PUSH       0x0
    //         0043ec9f     PUSH       0x0=>DAT_fffffff8
    //         0043eca1     PUSH       offset DAT_fffffff4
    //         0043eca3     TEST       EAX,EAX
    //         0043eca5     PUSH       offset DAT_fffffff0
    //         0043eca7     PUSH       0x78
    //         0043eca9     JNZ        LAB_0043ecb7
    //         0043ecab     IMUL       ESI,dword ptr [EBX + 0x8]
    //         0043ecaf     ADD        ESI,0x14
    //         0043ecb2     PUSH       ESI
    //         0043ecb3     PUSH       0x6e
    //                              dlg_help.cpp:173 (2)
    //         0043ecb5     JMP        LAB_0043ecc4
    //                               LAB_0043ecb7                                                 XREF[1]:     0043eca9(j)  
    //                              dlg_help.cpp:174 (36)
    //         0043ecb7     IMUL       ESI,dword ptr [EBX + 0x8]
    //         0043ecbb     ADD        ESI,0x14
    //         0043ecbe     PUSH       ESI
    //         0043ecbf     PUSH       0xc3
    //                               LAB_0043ecc4                                                 XREF[1]:     0043ecb5(j)  
    //         0043ecc4     PUSH       0x0
    //         0043ecc6     LEA        ESI,[EBP + 0x59c]
    //                              language.dll match for 0xfa1: "OK"
    //         0043eccc     PUSH       0xfa1
    //         0043ecd1     PUSH       ESI
    //         0043ecd2     PUSH       EBP
    //         0043ecd3     MOV        this,EBP
    //         0043ecd5     CALL       dword ptr [EDI + 0xe8]
    //                              dlg_help.cpp:175 (22)
    //         0043ecdb     MOV        EAX,dword ptr [ESI]
    //         0043ecdd     MOV        dword ptr [EAX + 0x298],0x1b
    //         0043ece7     MOV        dword ptr [EAX + 0x29c],0x0
    //                              dlg_help.cpp:177 (10)
    //         0043ecf1     MOV        this,dword ptr [ESI]
    //         0043ecf3     PUSH       this
    //         0043ecf4     MOV        this,EBP
    //         0043ecf6     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              dlg_help.cpp:182 (21)
    //         0043ecfb     MOV        EAX,dword ptr [EBP + 0x5a0]
    //         0043ed01     MOV        EDX,dword ptr [ESI]
    //         0043ed03     TEST       EAX,EAX
    //         0043ed05     MOV        dword ptr [ESP + 0x14],EDX
    //         0043ed09     MOV        this,0x1
    //         0043ed0e     JZ         LAB_0043ed19
    //                              dlg_help.cpp:183 (9)
    //         0043ed10     MOV        dword ptr [ESP + 0x18],EAX
    //         0043ed14     MOV        this,0x2
    //                               LAB_0043ed19                                                 XREF[1]:     0043ed0e(j)  
    //                              dlg_help.cpp:184 (14)
    //         0043ed19     LEA        EAX,[ESP + 0x14]
    //         0043ed1d     PUSH       this
    //         0043ed1e     PUSH       EAX=>DAT_fffffff8
    //         0043ed1f     MOV        this,EBP
    //         0043ed21     CALL       dword ptr [EDI + 0xc8]
    //                               LAB_0043ed27                                                 XREF[1]:     0043ea8b(j)  
    //                              dlg_help.cpp:185 (10)
    //         0043ed27     POP        EDI
    //         0043ed28     POP        ESI
    //         0043ed29     POP        EBP
    //         0043ed2a     POP        EBX
    //         0043ed2b     ADD        ESP,0xc
    //         0043ed2e     RET        0x18
    //         0043ed31     ??         90h
    //         0043ed32     NOP
    //         0043ed33     NOP
    //         0043ed34     NOP
    //         0043ed35     NOP
    //         0043ed36     NOP
    //         0043ed37     NOP
    //         0043ed38     NOP
    //         0043ed39     NOP
    //         0043ed3a     NOP
    //         0043ed3b     NOP
    //         0043ed3c     NOP
    //         0043ed3d     NOP
    //         0043ed3e     NOP
    //         0043ed3f     NOP
    return;
}

long THelpDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    //                              long __thiscall action(THelpDialog * this, TPanel * param_1, long pa
    //              long              EAX:4          <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043ed40(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0043ed48(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0043edee(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043ede9(R)  
    //                               ?action@THelpDialog@@UAEJPAVTPanel@@JKK@Z                    XREF[1]:     0056fa7c(*)  
    //                               THelpDialog::action
    //                              dlg_help.cpp:191 (28)
    //         0043ed40     MOV        EAX,dword ptr [ESP + param_1]
    //         0043ed44     PUSH       EBX
    //         0043ed45     PUSH       ESI
    //         0043ed46     MOV        ESI,this
    //         0043ed48     MOV        this,dword ptr [ESP + param_2]
    //         0043ed4c     PUSH       EDI
    //         0043ed4d     MOV        EBX,dword ptr [ESI + 0x490]
    //         0043ed53     CMP        this,0x1
    //         0043ed56     JNZ        LAB_0043ede9
    //                              dlg_help.cpp:203 (8)
    //         0043ed5c     CMP        EAX,dword ptr [ESI + 0x59c]
    //         0043ed62     JNZ        LAB_0043ed91
    //                              dlg_help.cpp:207 (19)
    //         0043ed64     ADD        ESI,0x494
    //         0043ed6a     PUSH       0x0
    //         0043ed6c     PUSH       ESI
    //         0043ed6d     MOV        this,panel_system
    //         0043ed72     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_help.cpp:208 (15)
    //         0043ed77     PUSH       s_Help_Dialog                                    = "Help Dialog"
    //         0043ed7c     MOV        this,panel_system
    //         0043ed81     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_help.cpp:209 (5)
    //         0043ed86     MOV        EAX,0x1
    //                              dlg_help.cpp:223 (6)
    //         0043ed8b     POP        EDI
    //         0043ed8c     POP        ESI
    //         0043ed8d     POP        EBX
    //         0043ed8e     RET        0x10
    //                               LAB_0043ed91                                                 XREF[1]:     0043ed62(j)  
    //                              dlg_help.cpp:211 (8)
    //         0043ed91     CMP        EAX,dword ptr [ESI + 0x5a0]
    //         0043ed97     JNZ        LAB_0043ede9
    //                              dlg_help.cpp:215 (19)
    //         0043ed99     LEA        EAX,[ESI + 0x494]
    //         0043ed9f     PUSH       0x0
    //         0043eda1     PUSH       EAX
    //         0043eda2     MOV        this,panel_system
    //         0043eda7     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_help.cpp:216 (15)
    //         0043edac     PUSH       s_Help_Dialog                                    = "Help Dialog"
    //         0043edb1     MOV        this,panel_system
    //         0043edb6     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_help.cpp:217 (35)
    //         0043edbb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043edc1     PUSH       EBX
    //         0043edc2     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0043edc5     MOV        this,ESI
    //         0043edc7     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043edcc     PUSH       EAX
    //         0043edcd     PUSH       0x101
    //         0043edd2     PUSH       s_empires.hlp                                    = "empires.hlp"
    //         0043edd7     PUSH       EDI
    //         0043edd8     CALL       dword ptr [->USER32.DLL::WinHelpA]               = 0048aff6
    //                              dlg_help.cpp:218 (5)
    //         0043edde     MOV        EAX,0x1
    //                              dlg_help.cpp:223 (6)
    //         0043ede3     POP        EDI
    //         0043ede4     POP        ESI
    //         0043ede5     POP        EBX
    //         0043ede6     RET        0x10
    //                               LAB_0043ede9                                                 XREF[2]:     0043ed56(j), 0043ed97(j)  
    //                              dlg_help.cpp:222 (19)
    //         0043ede9     MOV        EDX,dword ptr [ESP + param_4]
    //         0043eded     PUSH       EDX
    //         0043edee     MOV        EDX,dword ptr [ESP + param_3]
    //         0043edf2     PUSH       EDX
    //         0043edf3     PUSH       this
    //         0043edf4     PUSH       EAX
    //         0043edf5     MOV        this,ESI
    //         0043edf7     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              dlg_help.cpp:223 (6)
    //         0043edfc     POP        EDI
    //         0043edfd     POP        ESI
    //         0043edfe     POP        EBX
    //         0043edff     RET        0x10
    //         0043ee02     ??         90h
    //         0043ee03     NOP
    //         0043ee04     NOP
    //         0043ee05     NOP
    //         0043ee06     NOP
    //         0043ee07     NOP
    //         0043ee08     NOP
    //         0043ee09     NOP
    //         0043ee0a     NOP
    //         0043ee0b     NOP
    //         0043ee0c     NOP
    //         0043ee0d     NOP
    //         0043ee0e     NOP
    //         0043ee0f     NOP
    return 0;
}

long THelpDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              long __thiscall handle_mouse_down(THelpDialog * this, uchar param_1,
    //              long              EAX:4          <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0043ee16(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0043ee11(R)  
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_down@THelpDialog@@UAEJEJJHH@Z                  XREF[1]:     0056fa38(*)  
    //                               THelpDialog::handle_mouse_down
    //                              dlg_help.cpp:230 (1)
    //         0043ee10     PUSH       EBX
    //                              dlg_help.cpp:231 (27)
    //         0043ee11     MOV        EBX,dword ptr [ESP + param_3]
    //         0043ee15     PUSH       EBP
    //         0043ee16     MOV        EBP,dword ptr [ESP + param_2]
    //         0043ee1a     PUSH       ESI
    //         0043ee1b     MOV        ESI,this
    //         0043ee1d     PUSH       EDI
    //         0043ee1e     PUSH       EBX
    //         0043ee1f     MOV        EDI,dword ptr [ESI]
    //         0043ee21     PUSH       EBP
    //         0043ee22     CALL       dword ptr [EDI + 0xbc]
    //         0043ee28     TEST       EAX,EAX
    //         0043ee2a     JNZ        LAB_0043ee4b
    //                              dlg_help.cpp:233 (19)
    //         0043ee2c     PUSH       EAX
    //         0043ee2d     PUSH       EAX=>DAT_fffffff8
    //         0043ee2e     MOV        EAX,dword ptr [ESI + 0x59c]
    //         0043ee34     PUSH       offset DAT_fffffff4
    //         0043ee36     PUSH       EAX=>DAT_fffffff0
    //         0043ee37     MOV        this,ESI
    //         0043ee39     CALL       dword ptr [EDI + 0xb4]
    //                              dlg_help.cpp:234 (5)
    //         0043ee3f     MOV        EAX,0x1
    //                              dlg_help.cpp:238 (7)
    //         0043ee44     POP        EDI
    //         0043ee45     POP        ESI
    //         0043ee46     POP        EBP
    //         0043ee47     POP        EBX
    //         0043ee48     RET        0x14
    //                               LAB_0043ee4b                                                 XREF[1]:     0043ee2a(j)  
    //                              dlg_help.cpp:237 (24)
    //         0043ee4b     MOV        this,dword ptr [ESP + 0x24]
    //         0043ee4f     MOV        EDX,dword ptr [ESP + 0x20]
    //         0043ee53     MOV        EAX,dword ptr [ESP + 0x14]
    //         0043ee57     PUSH       this
    //         0043ee58     PUSH       EDX=>DAT_fffffff8
    //         0043ee59     PUSH       EBX=>DAT_fffffff4
    //         0043ee5a     PUSH       EBP=>DAT_fffffff0
    //         0043ee5b     PUSH       EAX
    //         0043ee5c     MOV        this,ESI
    //         0043ee5e     CALL       TEasy_Panel::handle_mouse_down                   long handle_mouse_down(TEasy_Panel * this, uc
    //                              dlg_help.cpp:238 (7)
    //         0043ee63     POP        EDI
    //         0043ee64     POP        ESI
    //         0043ee65     POP        EBP
    //         0043ee66     POP        EBX
    //         0043ee67     RET        0x14
    //         0043ee6a     ??         90h
    //         0043ee6b     NOP
    //         0043ee6c     NOP
    //         0043ee6d     NOP
    //         0043ee6e     NOP
    //         0043ee6f     NOP
    return 0;
}

