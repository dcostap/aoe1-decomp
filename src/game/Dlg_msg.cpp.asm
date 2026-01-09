#include "common.h"
#include "Dlg_msg.h"

TMessageDialog::TMessageDialog(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TMessageDialog(TMessageDialog * this, char * pa
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0043fc70(R)  
    //                               ??0TMessageDialog@@QAE@PAD@Z                                 XREF[5]:     popupOKDialog:00469fd5(c), 
    //                               TMessageDialog::TMessageDialog                                            popupYesNoDialog:0046a0d6(c), 
    //                                                                                                         popupYesNoDialog:0046a101(c), 
    //                                                                                                         popupYesNoCancelDialog:0046a1e6(c)
    //                                                                                                         popupYesNoCancelDialog:0046a211(c)
    //                              Dlg_msg.cpp:43 (15)
    //         0043fc70     MOV        EAX,dword ptr [ESP + param_1]
    //         0043fc74     PUSH       ESI
    //         0043fc75     MOV        ESI,this
    //         0043fc77     PUSH       EAX
    //         0043fc78     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //         0043fc7d     XOR        EAX,EAX
    //                              Dlg_msg.cpp:47 (32)
    //         0043fc7f     XOR        this,this
    //         0043fc81     MOV        byte ptr [ESI + 0x490],AL
    //         0043fc87     MOV        dword ptr [ESI + 0x494],EAX
    //         0043fc8d     MOV        dword ptr [ESI],TMessageDialog::`vftable'        = 0043fcb0
    //         0043fc93     MOV        dword ptr [ESI + 0x498],this
    //         0043fc99     MOV        dword ptr [ESI + 0x49c],this
    //                              Dlg_msg.cpp:48 (12)
    //         0043fc9f     MOV        EAX,ESI
    //         0043fca1     MOV        dword ptr [ESI + 0x4a0],this
    //         0043fca7     POP        ESI
    //         0043fca8     RET        0x4
    //         0043fcab     ??         90h
    //         0043fcac     NOP
    //         0043fcad     NOP
    //         0043fcae     NOP
    //         0043fcaf     NOP
}

TMessageDialog::~TMessageDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~TMessageDialog(TMessageDialog * this)
    //              void              <VOID>         <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043fcfb(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043fceb(W)  
    //                               ??1TMessageDialog@@UAE@XZ                                    XREF[1]:     `scalar_deleting_destructor':0043f
    //                               TMessageDialog::~TMessageDialog
    //                              Dlg_msg.cpp:54 (37)
    //         0043fcd0     PUSH       -0x1
    //         0043fcd2     PUSH       FUN_0055d198
    //         0043fcd7     MOV        EAX,FS:[0x0]
    //         0043fcdd     PUSH       EAX
    //         0043fcde     MOV        dword ptr FS:[0x0],ESP
    //         0043fce5     PUSH       this
    //         0043fce6     PUSH       EBX
    //         0043fce7     MOV        EBX,this
    //         0043fce9     PUSH       ESI
    //         0043fcea     PUSH       EDI
    //         0043fceb     MOV        dword ptr [ESP + local_10],EBX
    //         0043fcef     MOV        dword ptr [EBX],TMessageDialog::`vftable'        = 0043fcb0
    //                              Dlg_msg.cpp:57 (24)
    //         0043fcf5     MOV        this,dword ptr [EBX + 0x494]
    //         0043fcfb     MOV        dword ptr [ESP + local_4],0x0
    //         0043fd03     TEST       this,this
    //         0043fd05     JZ         LAB_0043fd0d
    //         0043fd07     MOV        EAX,dword ptr [this->_padding_]
    //         0043fd09     PUSH       0x1
    //         0043fd0b     CALL       dword ptr [EAX]
    //                               LAB_0043fd0d                                                 XREF[1]:     0043fd05(j)  
    //                              Dlg_msg.cpp:59 (11)
    //         0043fd0d     LEA        ESI,[EBX + 0x498]
    //         0043fd13     MOV        EDI,0x3
    //                               LAB_0043fd18                                                 XREF[1]:     0043fd28(j)  
    //                              Dlg_msg.cpp:60 (6)
    //         0043fd18     MOV        this,dword ptr [ESI]
    //         0043fd1a     TEST       this,this
    //         0043fd1c     JZ         LAB_0043fd24
    //                              Dlg_msg.cpp:61 (14)
    //         0043fd1e     MOV        EDX,dword ptr [this->_padding_]
    //         0043fd20     PUSH       0x1
    //         0043fd22     CALL       dword ptr [EDX]
    //                               LAB_0043fd24                                                 XREF[1]:     0043fd1c(j)  
    //         0043fd24     ADD        ESI,0x4
    //         0043fd27     DEC        EDI
    //         0043fd28     JNZ        LAB_0043fd18
    //         0043fd2a     MOV        this,EBX
    //                              Dlg_msg.cpp:64 (31)
    //         0043fd2c     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         0043fd34     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         0043fd39     MOV        this,dword ptr [ESP + 0x10]
    //         0043fd3d     POP        EDI
    //         0043fd3e     POP        ESI
    //         0043fd3f     MOV        dword ptr FS:[0x0],this
    //         0043fd46     POP        EBX
    //         0043fd47     ADD        ESP,0x10
    //         0043fd4a     RET
    //         0043fd4b     ??         90h
    //         0043fd4c     NOP
    //         0043fd4d     NOP
    //         0043fd4e     NOP
    //         0043fd4f     NOP
    //                              * public: long __thiscall TMessageDialog::setup(class TPanel *,char *,long,long,long,unsigned char,c... *
    //                              long __thiscall setup(TMessageDialog * this, TPanel * param_1, char 
    //              long              EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043fd7b(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043fd71(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0043fd57(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0043fd67(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0043fd75(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0043fda0(R)  
    //              char *            Stack[0x1c]:4  param_7                   XREF[1]:     0043fdbd(R)  
    //              long              Stack[0x20]:4  param_8
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0043fd99(R)  
    //                               ?setup@TMessageDialog@@QAEJPAVTPanel@@PADJJJE1JJ@Z           XREF[4]:     setup:00440059(c), 
    //                               TMessageDialog::setup                                                     popupOKDialog:0046a018(c), 
    //                                                                                                         popupYesNoDialog:0046a138(c), 
    //                                                                                                         popupYesNoCancelDialog:0046a248(c)
    //                              Dlg_msg.cpp:71 (5)
    //         0043fd50     PUSH       EBX
    //         0043fd51     PUSH       EBP
    //         0043fd52     PUSH       ESI
    //         0043fd53     MOV        ESI,this
    //                              Dlg_msg.cpp:80 (2)
    //         0043fd55     XOR        this,this
    //                              Dlg_msg.cpp:82 (57)
    //         0043fd57     MOV        EDX,dword ptr [ESP + param_3]
    //         0043fd5b     LEA        EAX,[ESI + 0x498]
    //         0043fd61     PUSH       EDI
    //         0043fd62     PUSH       0x1
    //         0043fd64     PUSH       EDX
    //         0043fd65     MOV        dword ptr [EAX],this
    //         0043fd67     MOV        EDX,dword ptr [ESP + param_4]
    //         0043fd6b     MOV        dword ptr [EAX + 0x4],this
    //         0043fd6e     MOV        dword ptr [EAX + 0x8],this
    //         0043fd71     MOV        EAX,dword ptr [ESP + param_2]
    //         0043fd75     MOV        this,dword ptr [ESP + param_5]
    //         0043fd79     PUSH       EAX
    //         0043fd7a     PUSH       this
    //         0043fd7b     MOV        this,dword ptr [ESP + param_1]
    //         0043fd7f     PUSH       EDX
    //         0043fd80     PUSH       this
    //         0043fd81     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         0043fd86     PUSH       EAX
    //         0043fd87     MOV        this,ESI
    //         0043fd89     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0043fd8e     TEST       EAX,EAX
    //                              Dlg_msg.cpp:83 (6)
    //         0043fd90     JZ         switchD_0043fdf0::default
    //                              Dlg_msg.cpp:88 (67)
    //         0043fd96     MOV        this,dword ptr [ESI + 0x18]
    //         0043fd99     MOV        EDI,dword ptr [ESP + param_9]
    //         0043fd9d     MOV        EDX,dword ptr [ESI + 0x14]
    //         0043fda0     MOV        AL,byte ptr [ESP + param_6]
    //         0043fda4     PUSH       0x1
    //         0043fda6     SUB        this,EDI
    //         0043fda8     MOV        EBX,dword ptr [ESI]
    //         0043fdaa     PUSH       0x1
    //         0043fdac     PUSH       0x1
    //         0043fdae     SUB        this,0x6
    //         0043fdb1     PUSH       0xb
    //         0043fdb3     SUB        EDX,0x3
    //         0043fdb6     PUSH       this
    //         0043fdb7     MOV        byte ptr [ESI + 0x490],AL
    //         0043fdbd     MOV        EAX,dword ptr [ESP + param_7]
    //         0043fdc1     PUSH       EDX
    //         0043fdc2     PUSH       0x3
    //         0043fdc4     PUSH       0x3
    //         0043fdc6     LEA        this,[ESI + 0x494]
    //         0043fdcc     PUSH       EAX
    //         0043fdcd     PUSH       this
    //         0043fdce     PUSH       ESI
    //         0043fdcf     MOV        this,ESI
    //         0043fdd1     CALL       dword ptr [EBX + 0x100]
    //         0043fdd7     TEST       EAX,EAX
    //                              Dlg_msg.cpp:89 (6)
    //         0043fdd9     JZ         switchD_0043fdf0::default
    //                              Dlg_msg.cpp:93 (24)
    //         0043fddf     XOR        EAX,EAX
    //         0043fde1     MOV        AL,byte ptr [ESI + 0x490]
    //         0043fde7     CMP        EAX,0x4
    //         0043fdea     JA         switchD_0043fdf0::default
    //                               switchD_0043fdf0::switchD
    //         0043fdf0     JMP        dword ptr [EAX*0x4 + switchD_0043fdf0::switchd   = 0043fdf7
    //                               switchD_0043fdf0::caseD_0                                    XREF[2]:     0043fdf0(j), 0043ffc8(*)  
    //                              Dlg_msg.cpp:96 (8)
    //         0043fdf7     MOV        dword ptr [ESP + 0x28],0x1
    //                              Dlg_msg.cpp:100 (2)
    //         0043fdff     JMP        LAB_0043fe13
    //                               switchD_0043fdf0::caseD_4                                    XREF[2]:     0043fdf0(j), 0043ffd8(*)  
    //                              Dlg_msg.cpp:105 (8)
    //         0043fe01     MOV        dword ptr [ESP + 0x28],0x3
    //                              Dlg_msg.cpp:106 (2)
    //         0043fe09     JMP        LAB_0043fe13
    //                               switchD_0043fdf0::caseD_2                                    XREF[4]:     0043fdf0(j), 0043ffcc(*), 
    //                               switchD_0043fdf0::caseD_3                                                 0043ffd0(*), 0043ffd4(*)  
    //                               switchD_0043fdf0::caseD_1
    //                              Dlg_msg.cpp:108 (8)
    //         0043fe0b     MOV        dword ptr [ESP + 0x28],0x2
    //                               LAB_0043fe13                                                 XREF[2]:     0043fdff(j), 0043fe09(j)  
    //                              Dlg_msg.cpp:117 (18)
    //         0043fe13     MOV        this,dword ptr [ESP + 0x28]
    //         0043fe17     MOV        EBP,dword ptr [ESP + 0x30]
    //         0043fe1b     MOV        EDX,this
    //         0043fe1d     MOV        EAX,dword ptr [ESI + 0x14]
    //         0043fe20     IMUL       EDX,EBP
    //         0043fe23     SUB        EAX,EDX
    //                              Dlg_msg.cpp:118 (4)
    //         0043fe25     TEST       EAX,EAX
    //         0043fe27     JG         LAB_0043fe33
    //                              Dlg_msg.cpp:119 (8)
    //         0043fe29     MOV        dword ptr [ESP + 0x1c],0x0
    //                              Dlg_msg.cpp:120 (2)
    //         0043fe31     JMP        LAB_0043fe3b
    //                               LAB_0043fe33                                                 XREF[1]:     0043fe27(j)  
    //                              Dlg_msg.cpp:121 (8)
    //         0043fe33     CDQ
    //         0043fe34     INC        this
    //         0043fe35     IDIV       this
    //         0043fe37     MOV        dword ptr [ESP + 0x1c],EAX
    //                               LAB_0043fe3b                                                 XREF[1]:     0043fe31(j)  
    //                              Dlg_msg.cpp:124 (3)
    //         0043fe3b     MOV        EAX,dword ptr [ESI + 0x18]
    //                              Dlg_msg.cpp:125 (29)
    //         0043fe3e     MOV        this,dword ptr [ESP + 0x28]
    //         0043fe42     SUB        EAX,EDI
    //         0043fe44     MOV        EDI,dword ptr [ESP + 0x1c]
    //         0043fe48     SUB        EAX,0x7
    //         0043fe4b     MOV        dword ptr [ESP + 0x18],0x0
    //         0043fe53     TEST       this,this
    //         0043fe55     MOV        dword ptr [ESP + 0x24],EAX
    //         0043fe59     JLE        LAB_0043feb5
    //                              Dlg_msg.cpp:127 (18)
    //         0043fe5b     MOV        this,dword ptr [EBX + 0xec]
    //         0043fe61     LEA        EBX,[ESI + 0x498]
    //         0043fe67     MOV        dword ptr [ESP + 0x20],this
    //         0043fe6b     JMP        LAB_0043fe71
    //                               LAB_0043fe6d                                                 XREF[1]:     0043feb3(j)  
    //                              Dlg_msg.cpp:124 (4)
    //         0043fe6d     MOV        EAX,dword ptr [ESP + 0x24]
    //                               LAB_0043fe71                                                 XREF[1]:     0043fe6b(j)  
    //                              Dlg_msg.cpp:127 (40)
    //         0043fe71     MOV        EDX,dword ptr [ESP + 0x34]
    //         0043fe75     PUSH       0x0
    //         0043fe77     PUSH       0x0=>DAT_fffffff8
    //         0043fe79     PUSH       offset DAT_fffffff4
    //         0043fe7b     PUSH       EDX=>DAT_fffffff0
    //         0043fe7c     PUSH       EBP
    //         0043fe7d     PUSH       EAX
    //         0043fe7e     PUSH       EDI
    //         0043fe7f     PUSH       s_                                               = ""
    //         0043fe84     PUSH       s_                                               = ""
    //         0043fe89     PUSH       EBX
    //         0043fe8a     PUSH       ESI
    //         0043fe8b     MOV        this,ESI
    //         0043fe8d     CALL       dword ptr [ESP + 0x4c]
    //         0043fe91     TEST       EAX,EAX
    //         0043fe93     JZ         switchD_0043fdf0::default
    //                              Dlg_msg.cpp:129 (28)
    //         0043fe99     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0043fe9d     MOV        this,dword ptr [ESP + 0x28]
    //         0043fea1     ADD        EAX,EBP
    //         0043fea3     ADD        EBX,0x4
    //         0043fea6     ADD        EDI,EAX
    //         0043fea8     MOV        EAX,dword ptr [ESP + 0x18]
    //         0043feac     INC        EAX
    //         0043fead     CMP        EAX,this
    //         0043feaf     MOV        dword ptr [ESP + 0x18],EAX
    //         0043feb3     JL         LAB_0043fe6d
    //                               LAB_0043feb5                                                 XREF[1]:     0043fe59(j)  
    //                              Dlg_msg.cpp:133 (24)
    //         0043feb5     XOR        EAX,EAX
    //         0043feb7     MOV        AL,byte ptr [ESI + 0x490]
    //         0043febd     CMP        EAX,0x4
    //         0043fec0     JA         switchD_0043fec6::default
    //                               switchD_0043fec6::switchD
    //         0043fec6     JMP        dword ptr [EAX*0x4 + switchD_0043fec6::switchd   = 0043fecd
    //                               switchD_0043fec6::caseD_0                                    XREF[2]:     0043fec6(j), 0043ffdc(*)  
    //                              Dlg_msg.cpp:136 (18)
    //         0043fecd     MOV        this,dword ptr [ESI + 0x498]
    //                              language.dll match for 0xfa1: "OK"
    //         0043fed3     PUSH       0xfa1
    //         0043fed8     PUSH       0x0=>DAT_fffffff8
    //         0043feda     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:137 (5)
    //         0043fedf     JMP        switchD_0043fec6::default
    //                               switchD_0043fec6::caseD_1                                    XREF[2]:     0043fec6(j), 0043ffe0(*)  
    //                              Dlg_msg.cpp:139 (18)
    //         0043fee4     MOV        this,dword ptr [ESI + 0x498]
    //                              language.dll match for 0xfa1: "OK"
    //         0043feea     PUSH       0xfa1
    //         0043feef     PUSH       0x0=>DAT_fffffff8
    //         0043fef1     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:140 (5)
    //         0043fef6     PUSH       0xfa2
    //                              Dlg_msg.cpp:142 (2)
    //         0043fefb     JMP        LAB_0043ff6b
    //                               switchD_0043fec6::caseD_2                                    XREF[2]:     0043fec6(j), 0043ffe4(*)  
    //                              Dlg_msg.cpp:144 (18)
    //         0043fefd     MOV        this,dword ptr [ESI + 0x498]
    //                              language.dll match for 0xfa3: "Yes"
    //         0043ff03     PUSH       0xfa3
    //         0043ff08     PUSH       0x0=>DAT_fffffff8
    //         0043ff0a     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:145 (5)
    //         0043ff0f     PUSH       0xfa4
    //                              Dlg_msg.cpp:147 (2)
    //         0043ff14     JMP        LAB_0043ff6b
    //                               switchD_0043fec6::caseD_4                                    XREF[2]:     0043fec6(j), 0043ffec(*)  
    //                              Dlg_msg.cpp:149 (18)
    //         0043ff16     MOV        this,dword ptr [ESI + 0x498]
    //                              language.dll match for 0xfa3: "Yes"
    //         0043ff1c     PUSH       0xfa3
    //         0043ff21     PUSH       0x0=>DAT_fffffff8
    //         0043ff23     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:150 (18)
    //         0043ff28     MOV        this,dword ptr [ESI + 0x49c]
    //                              language.dll match for 0xfa4: "No"
    //         0043ff2e     PUSH       0xfa4
    //         0043ff33     PUSH       0x0=>DAT_fffffff8
    //         0043ff35     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:151 (18)
    //         0043ff3a     MOV        this,dword ptr [ESI + 0x4a0]
    //                              language.dll match for 0xfa2: "Cancel"
    //         0043ff40     PUSH       0xfa2
    //         0043ff45     PUSH       0x0=>DAT_fffffff8
    //         0043ff47     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:152 (6)
    //         0043ff4c     MOV        EAX,dword ptr [ESI + 0x4a0]
    //                              Dlg_msg.cpp:153 (2)
    //         0043ff52     JMP        LAB_0043ff7e
    //                               switchD_0043fec6::caseD_3                                    XREF[2]:     0043fec6(j), 0043ffe8(*)  
    //                              Dlg_msg.cpp:155 (18)
    //         0043ff54     MOV        this,dword ptr [ESI + 0x498]
    //                              language.dll match for 0xfa5: "Retry"
    //         0043ff5a     PUSH       0xfa5
    //         0043ff5f     PUSH       0x0=>DAT_fffffff8
    //         0043ff61     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              language.dll match for 0xfa7: "Abort"
    //                              Dlg_msg.cpp:156 (18)
    //         0043ff66     PUSH       0xfa7
    //                               LAB_0043ff6b                                                 XREF[2]:     0043fefb(j), 0043ff14(j)  
    //         0043ff6b     MOV        this,dword ptr [ESI + 0x49c]
    //         0043ff71     PUSH       0x0=>DAT_fffffff8
    //         0043ff73     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Dlg_msg.cpp:157 (26)
    //         0043ff78     MOV        EAX,dword ptr [ESI + 0x49c]
    //                               LAB_0043ff7e                                                 XREF[1]:     0043ff52(j)  
    //         0043ff7e     MOV        dword ptr [EAX + 0x298],0x1b
    //         0043ff88     MOV        dword ptr [EAX + 0x29c],0x0
    //                               switchD_0043fec6::default                                    XREF[2]:     0043fec0(j), 0043fedf(j)  
    //                              Dlg_msg.cpp:161 (22)
    //         0043ff92     MOV        this,dword ptr [ESP + 0x28]
    //         0043ff96     MOV        EAX,dword ptr [ESI]
    //         0043ff98     LEA        EDI,[ESI + 0x498]
    //         0043ff9e     PUSH       this
    //         0043ff9f     PUSH       EDI=>DAT_fffffff8
    //         0043ffa0     MOV        this,ESI
    //         0043ffa2     CALL       dword ptr [EAX + 0xc8]
    //                              Dlg_msg.cpp:162 (10)
    //         0043ffa8     MOV        EDX,dword ptr [EDI]
    //         0043ffaa     MOV        this,ESI
    //         0043ffac     PUSH       EDX
    //         0043ffad     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              Dlg_msg.cpp:164 (5)
    //         0043ffb2     MOV        EAX,0x1
    //                              Dlg_msg.cpp:165 (57)
    //         0043ffb7     POP        EDI
    //         0043ffb8     POP        ESI
    //         0043ffb9     POP        EBP
    //         0043ffba     POP        EBX
    //         0043ffbb     RET        0x24
    //                               switchD_0043fdf0::default                                    XREF[4]:     0043fd90(j), 0043fdd9(j), 
    //                                                                                                         0043fdea(j), 0043fe93(j)  
    //         0043ffbe     POP        EDI
    //         0043ffbf     POP        ESI
    //         0043ffc0     POP        EBP
    //         0043ffc1     XOR        EAX,EAX
    //         0043ffc3     POP        EBX
    //         0043ffc4     RET        0x24
    //         0043ffc7     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0043fdf0::switchdataD_0043ffc8                       XREF[1]:     setup:0043fdf0(*)  
    //         0043ffc8     addr       switchD_0043fdf0::caseD_0
    //         0043ffcc     addr       switchD_0043fdf0::caseD_1
    //         0043ffd0     addr       switchD_0043fdf0::caseD_1
    //         0043ffd4     addr       switchD_0043fdf0::caseD_1
    //         0043ffd8     addr       switchD_0043fdf0::caseD_4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0043fec6::switchdataD_0043ffdc                       XREF[1]:     setup:0043fec6(*)  
    //         0043ffdc     addr       switchD_0043fec6::caseD_0
    //         0043ffe0     addr       switchD_0043fec6::caseD_1
    //         0043ffe4     addr       switchD_0043fec6::caseD_2
    //         0043ffe8     addr       switchD_0043fec6::caseD_3
    //         0043ffec     addr       switchD_0043fec6::caseD_4
    //                              * public: long __thiscall TMessageDialog::setup(class TPanel *,char *,long,long,long,unsigned char,i... *
    //                              long __thiscall setup(TMessageDialog * this, TPanel * param_1, char 
    //              long              EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0044004d(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00440045(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0044003d(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00440035(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0044002d(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     00440021(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     0043fffd(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00440019(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00440012(R)  
    //              char[256]         Stack[-0x104   str                       XREF[0,2]:   0043fff6(*), 00440028(*)  
    //                               ?setup@TMessageDialog@@QAEJPAVTPanel@@PADJJJEHJJ@Z
    //                               TMessageDialog::setup
    //                              Dlg_msg.cpp:172 (6)
    //         0043fff0     SUB        ESP,0x100
    //                              Dlg_msg.cpp:174 (28)
    //         0043fff6     LEA        EAX=>str[4],[ESP]
    //         0043fffa     PUSH       ESI
    //         0043fffb     MOV        ESI,this
    //         0043fffd     MOV        this,dword ptr [ESP + param_7]
    //         00440004     PUSH       0x100
    //         00440009     PUSH       EAX
    //         0044000a     PUSH       this
    //         0044000b     MOV        this,ESI
    //         0044000d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Dlg_msg.cpp:175 (76)
    //         00440012     MOV        EDX,dword ptr [ESP + param_9]
    //         00440019     MOV        EAX,dword ptr [ESP + param_8]
    //         00440020     PUSH       EDX
    //         00440021     MOV        EDX,dword ptr [ESP + param_6]
    //         00440028     LEA        this=>str[4],[ESP + 0x8]
    //         0044002c     PUSH       EAX
    //         0044002d     MOV        EAX,dword ptr [ESP + param_5]
    //         00440034     PUSH       this
    //         00440035     MOV        this,dword ptr [ESP + param_4]
    //         0044003c     PUSH       EDX
    //         0044003d     MOV        EDX,dword ptr [ESP + param_3]
    //         00440044     PUSH       EAX
    //         00440045     MOV        EAX,dword ptr [ESP + param_2]
    //         0044004c     PUSH       this
    //         0044004d     MOV        this,dword ptr [ESP + param_1]
    //         00440054     PUSH       EDX
    //         00440055     PUSH       EAX
    //         00440056     PUSH       this
    //         00440057     MOV        this,ESI
    //         00440059     CALL       TMessageDialog::setup                            long setup(TMessageDialog * this, TPanel * pa
    //                              Dlg_msg.cpp:176 (10)
    //         0044005e     POP        ESI
    //         0044005f     ADD        ESP,0x100
    //         00440065     RET        0x24
    //         00440068     ??         90h
    //         00440069     NOP
    //         0044006a     NOP
    //         0044006b     NOP
    //         0044006c     NOP
    //         0044006d     NOP
    //         0044006e     NOP
    //         0044006f     NOP
    //                              * public: virtual long __thiscall TMessageDialog::action(class TPanel *,long,unsigned long,unsigned ... *
    //                              long __thiscall action(TMessageDialog * this, TPanel * param_1, long
    //              long              EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00440070(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00440077(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004400e9(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004400e4(R)  
    //                               ?action@TMessageDialog@@UAEJPAVTPanel@@JKK@Z                 XREF[1]:     0056fe14(*)  
    //                               TMessageDialog::action
    //                              Dlg_msg.cpp:182 (23)
    //         00440070     MOV        EDX,dword ptr [ESP + param_1]
    //         00440074     MOV        EAX,this
    //         00440076     PUSH       ESI
    //         00440077     MOV        ESI,dword ptr [ESP + param_2]
    //         0044007b     MOV        this,dword ptr [EAX + 0x40]
    //         0044007e     TEST       this,this
    //         00440080     JZ         LAB_004400e4
    //         00440082     CMP        ESI,0x1
    //         00440085     JNZ        LAB_004400e4
    //                              Dlg_msg.cpp:185 (8)
    //         00440087     CMP        EDX,dword ptr [EAX + 0x498]
    //         0044008d     JNZ        LAB_004400a4
    //                              Dlg_msg.cpp:187 (15)
    //         0044008f     MOV        EDX,dword ptr [this->_padding_]
    //         00440091     PUSH       0x0
    //         00440093     PUSH       0x0
    //         00440095     PUSH       0x0
    //         00440097     PUSH       EAX
    //         00440098     CALL       dword ptr [EDX + 0xb4]
    //                              Dlg_msg.cpp:188 (2)
    //         0044009e     MOV        EAX,ESI
    //                              Dlg_msg.cpp:203 (4)
    //         004400a0     POP        ESI
    //         004400a1     RET        0x10
    //                               LAB_004400a4                                                 XREF[1]:     0044008d(j)  
    //                              Dlg_msg.cpp:190 (8)
    //         004400a4     CMP        EDX,dword ptr [EAX + 0x49c]
    //         004400aa     JNZ        LAB_004400c4
    //                              Dlg_msg.cpp:192 (15)
    //         004400ac     MOV        EDX,dword ptr [this->_padding_]
    //         004400ae     PUSH       0x0
    //         004400b0     PUSH       0x0
    //         004400b2     PUSH       0x1
    //         004400b4     PUSH       EAX
    //         004400b5     CALL       dword ptr [EDX + 0xb4]
    //                              Dlg_msg.cpp:193 (5)
    //         004400bb     MOV        EAX,0x1
    //                              Dlg_msg.cpp:203 (4)
    //         004400c0     POP        ESI
    //         004400c1     RET        0x10
    //                               LAB_004400c4                                                 XREF[1]:     004400aa(j)  
    //                              Dlg_msg.cpp:195 (8)
    //         004400c4     CMP        EDX,dword ptr [EAX + 0x4a0]
    //         004400ca     JNZ        LAB_004400e4
    //                              Dlg_msg.cpp:197 (15)
    //         004400cc     MOV        EDX,dword ptr [this->_padding_]
    //         004400ce     PUSH       0x0
    //         004400d0     PUSH       0x0
    //         004400d2     PUSH       0x2
    //         004400d4     PUSH       EAX
    //         004400d5     CALL       dword ptr [EDX + 0xb4]
    //                              Dlg_msg.cpp:198 (5)
    //         004400db     MOV        EAX,0x1
    //                              Dlg_msg.cpp:203 (4)
    //         004400e0     POP        ESI
    //         004400e1     RET        0x10
    //                               LAB_004400e4                                                 XREF[3]:     00440080(j), 00440085(j), 
    //                                                                                                         004400ca(j)  
    //                              Dlg_msg.cpp:202 (19)
    //         004400e4     MOV        this,dword ptr [ESP + param_4]
    //         004400e8     PUSH       this
    //         004400e9     MOV        this,dword ptr [ESP + param_3]
    //         004400ed     PUSH       this
    //         004400ee     PUSH       ESI
    //         004400ef     PUSH       EDX
    //         004400f0     MOV        this,EAX
    //         004400f2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              Dlg_msg.cpp:203 (4)
    //         004400f7     POP        ESI
    //         004400f8     RET        0x10
    //         004400fb     ??         90h
    //         004400fc     NOP
    //         004400fd     NOP
    //         004400fe     NOP
    //         004400ff     NOP
}

long TMessageDialog::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              long __thiscall key_down_action(TMessageDialog * this, long param_1,
    //              long              EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?key_down_action@TMessageDialog@@UAEJJFHHH@Z                 XREF[1]:     0056fe0c(*)  
    //                               TMessageDialog::key_down_action
    //                              Dlg_msg.cpp:209 (2)
    //         00440100     XOR        EAX,EAX
    //                              Dlg_msg.cpp:215 (3)
    //         00440102     RET        0x14
    //         00440105     ??         90h
    //         00440106     NOP
    //         00440107     NOP
    //         00440108     NOP
    //         00440109     NOP
    //         0044010a     NOP
    //         0044010b     NOP
    //         0044010c     NOP
    //         0044010d     NOP
    //         0044010e     NOP
    //         0044010f     NOP
    return 0;
}

long TMessageDialog::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TMessageDialog * this)
    //              long              EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //                               ?handle_idle@TMessageDialog@@UAEJXZ                          XREF[1]:     0056fdac(*)  
    //                               TMessageDialog::handle_idle
    //                              Dlg_msg.cpp:222 (3)
    //         00440110     PUSH       ESI
    //         00440111     MOV        ESI,this
    //                              Dlg_msg.cpp:223 (16)
    //         00440113     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440119     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0044011f     TEST       EAX,EAX
    //         00440121     JNZ        LAB_00440128
    //                              Dlg_msg.cpp:224 (5)
    //         00440123     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_00440128                                                 XREF[1]:     00440121(j)  
    //                              Dlg_msg.cpp:225 (7)
    //         00440128     MOV        this,ESI
    //         0044012a     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              Dlg_msg.cpp:226 (2)
    //         0044012f     POP        ESI
    //         00440130     RET
    //         00440131     ??         90h
    //         00440132     NOP
    //         00440133     NOP
    //         00440134     NOP
    //         00440135     NOP
    //         00440136     NOP
    //         00440137     NOP
    //         00440138     NOP
    //         00440139     NOP
    //         0044013a     NOP
    //         0044013b     NOP
    //         0044013c     NOP
    //         0044013d     NOP
    //         0044013e     NOP
    //         0044013f     NOP
    return 0;
}

long TMessageDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, char* param_7, long param_8, long param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

long TMessageDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, int param_7, long param_8, long param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

long TMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

