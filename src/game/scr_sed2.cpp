#include "../common.h"
#include "scr_sed2.h"

void TRIBE_Screen_Sed::SaveDisabledItemsInScenario() {
    /* TODO: Stub */
//                              void __thiscall SaveDisabledItemsInScenario(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?SaveDisabledItemsInScenario@TRIBE_Screen_Sed@@IAEXXZ        XREF[3]:     set_scenario_mode:004aa5ab(c),
//                               TRIBE_Screen_Sed::SaveDisabledItemsInScenario                             key_down_action:004aba02(c),
//                                                                                                         action:004ace1b(c)
//                              scr_sed2.cpp:343 (5)
//         004adc80     PUSH       EBX
//         004adc81     PUSH       ESI
//         004adc82     PUSH       EDI
//         004adc83     MOV        EDI,this
//                              scr_sed2.cpp:344 (19)
//         004adc85     CMP        word ptr [EDI + 0x4b8],0x0
//         004adc8d     JNZ        LAB_004adc98
//         004adc8f     MOV        word ptr [EDI + 0x4b8],0x1
//                               LAB_004adc98                                                 XREF[1]:     004adc8d(j)
//                              scr_sed2.cpp:345 (8)
//         004adc98     XOR        ESI,ESI
//         004adc9a     LEA        EBX,[EDI + 0x7d4]
//                               LAB_004adca0                                                 XREF[1]:     004adce3(j)
//                              scr_sed2.cpp:347 (7)
//         004adca0     MOV        this,dword ptr [EBX]
//         004adca2     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//                              scr_sed2.cpp:348 (25)
//         004adca7     TEST       EAX,EAX
//         004adca9     JZ         LAB_004adcc2
//         004adcab     MOVSX      EAX,word ptr [EDI + 0x4b8]
//         004adcb2     MOV        this,dword ptr [EDI + 0x928]
//         004adcb8     PUSH       0x0
//         004adcba     DEC        EAX
//         004adcbb     PUSH       ESI
//         004adcbc     MOV        this,dword ptr [ECX + this->_padding_]
//         004adcbf     PUSH       EAX
//                              scr_sed2.cpp:349 (37)
//         004adcc0     JMP        LAB_004adcd7
//                               LAB_004adcc2                                                 XREF[1]:     004adca9(j)
//         004adcc2     MOVSX      EDX,word ptr [EDI + 0x4b8]
//         004adcc9     MOV        EAX,dword ptr [EDI + 0x928]
//         004adccf     PUSH       0x1
//         004adcd1     DEC        EDX
//         004adcd2     PUSH       ESI
//         004adcd3     MOV        this,dword ptr [EAX + 0x5c]
//         004adcd6     PUSH       EDX
//                               LAB_004adcd7                                                 XREF[1]:     004adcc0(j)
//         004adcd7     CALL       T_Scenario::SetDisabledTechnology                void SetDisabledTechnology(T_Scenario * this,
//         004adcdc     INC        ESI
//         004adcdd     ADD        EBX,0x4
//         004adce0     CMP        ESI,0x10
//         004adce3     JL         LAB_004adca0
//                              scr_sed2.cpp:351 (19)
//         004adce5     MOV        this,dword ptr [EDI + 0x7cc]
//         004adceb     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//         004adcf0     INC        EAX
//         004adcf1     MOV        word ptr [EDI + 0x4b8],AX
//                              scr_sed2.cpp:352 (4)
//         004adcf8     POP        EDI
//         004adcf9     POP        ESI
//         004adcfa     POP        EBX
//         004adcfb     RET
//         004adcfc     ??         90h
//         004adcfd     NOP
//         004adcfe     NOP
//         004adcff     NOP
    return;
}

void TRIBE_Screen_Sed::LoadDisabledItemsFromScenario() {
    /* TODO: Stub */
//                              void __thiscall LoadDisabledItemsFromScenario(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?LoadDisabledItemsFromScenario@TRIBE_Screen_Sed@@IAEXXZ      XREF[3]:     set_scenario_mode:004aa5e0(c),
//                               TRIBE_Screen_Sed::LoadDisabledItemsFromScenario                           key_down_action:004aba3e(c),
//                                                                                                         action:004ace22(c)
//                              scr_sed2.cpp:358 (5)
//         004add00     PUSH       EBX
//         004add01     MOV        EBX,this
//         004add03     PUSH       ESI
//         004add04     PUSH       EDI
//                              scr_sed2.cpp:359 (8)
//         004add05     XOR        ESI,ESI
//         004add07     LEA        EDI,[EBX + 0x7d4]
//                               LAB_004add0d                                                 XREF[1]:     004add48(j)
//                              scr_sed2.cpp:361 (24)
//         004add0d     MOVSX      EAX,word ptr [EBX + 0x4b8]
//         004add14     MOV        this,dword ptr [EBX + 0x928]
//         004add1a     DEC        EAX
//         004add1b     PUSH       ESI
//         004add1c     PUSH       EAX=>DAT_fffffff8
//         004add1d     MOV        this,dword ptr [ECX + this->_padding_]
//         004add20     CALL       T_Scenario::GetDisabledTechnology                int GetDisabledTechnology(T_Scenario * this,
//                              scr_sed2.cpp:362 (16)
//         004add25     MOV        this,dword ptr [EDI]
//         004add27     TEST       EAX,EAX
//         004add29     JZ         LAB_004add37
//         004add2b     MOV        EDX,dword ptr [this->_padding_]
//         004add2d     PUSH       0x0
//         004add2f     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:363 (21)
//         004add35     JMP        LAB_004add41
//                               LAB_004add37                                                 XREF[1]:     004add29(j)
//         004add37     MOV        EAX,dword ptr [this->_padding_]
//         004add39     PUSH       0x1
//         004add3b     CALL       dword ptr [EAX + 0xe0]
//                               LAB_004add41                                                 XREF[1]:     004add35(j)
//         004add41     INC        ESI
//         004add42     ADD        EDI,0x4
//         004add45     CMP        ESI,0x10
//         004add48     JL         LAB_004add0d
//                              scr_sed2.cpp:365 (4)
//         004add4a     POP        EDI
//         004add4b     POP        ESI
//         004add4c     POP        EBX
//         004add4d     RET
//         004add4e     ??         90h
//         004add4f     NOP
    return;
}

void TRIBE_Screen_Sed::save_info_in_scenario() {
    /* TODO: Stub */
//                              void __thiscall save_info_in_scenario(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?save_info_in_scenario@TRIBE_Screen_Sed@@IAEXXZ              XREF[1]:     set_scenario_mode:004aa30d(c)
//                               TRIBE_Screen_Sed::save_info_in_scenario
//                              scr_sed2.cpp:368 (1)
//         004add50     RET
//         004add51     ??         90h
//         004add52     NOP
//         004add53     NOP
//         004add54     NOP
//         004add55     NOP
//         004add56     NOP
//         004add57     NOP
//         004add58     NOP
//         004add59     NOP
//         004add5a     NOP
//         004add5b     NOP
//         004add5c     NOP
//         004add5d     NOP
//         004add5e     NOP
//         004add5f     NOP
    return;
}

void TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario() {
    /* TODO: Stub */
//                              void __thiscall save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?save_multi_victory_cond_in_scenario@TRIBE_Screen_Sed@@IAEXXZ XREF[1]:     set_scenario_mode:004aa1de(c)
//                               TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario
//                              scr_sed2.cpp:382 (4)
//         004add60     PUSH       ESI
//         004add61     MOV        ESI,this
//         004add63     PUSH       EDI
//                              scr_sed2.cpp:385 (19)
//         004add64     MOV        EAX,dword ptr [ESI + 0x4ac]
//         004add6a     DEC        EAX
//         004add6b     CMP        EAX,0x3
//         004add6e     JA         switchD_004add70::default
//                               switchD_004add70::switchD
//         004add70     JMP        dword ptr [EAX*0x4 + switchD_004add70::switchd   = 004add77
//                               switchD_004add70::caseD_1                                    XREF[2]:     004add70(j), 004ae05c(*)
//                              scr_sed2.cpp:388 (11)
//         004add77     MOV        EAX,dword ptr [ESI + 0x928]
//         004add7d     PUSH       0x0
//         004add7f     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:389 (2)
//         004add82     JMP        LAB_004addad
//                               switchD_004add70::caseD_2                                    XREF[2]:     004add70(j), 004ae060(*)
//                              scr_sed2.cpp:392 (2)
//         004add84     PUSH       0x1
//                              scr_sed2.cpp:393 (2)
//         004add86     JMP        LAB_004adda4
//                               switchD_004add70::caseD_3                                    XREF[2]:     004add70(j), 004ae064(*)
//                              scr_sed2.cpp:396 (11)
//         004add88     MOV        EDX,dword ptr [ESI + 0x928]
//         004add8e     PUSH       0x2
//         004add90     MOV        this,dword ptr [EDX + 0x5c]
//                              scr_sed2.cpp:397 (2)
//         004add93     JMP        LAB_004addad
//                               switchD_004add70::caseD_4                                    XREF[2]:     004add70(j), 004ae068(*)
//                              scr_sed2.cpp:400 (11)
//         004add95     MOV        EAX,dword ptr [ESI + 0x928]
//         004add9b     PUSH       0x3
//         004add9d     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:401 (2)
//         004adda0     JMP        LAB_004addad
//                               switchD_004add70::default                                    XREF[1]:     004add6e(j)
//                              scr_sed2.cpp:404 (16)
//         004adda2     PUSH       0x4
//                               LAB_004adda4                                                 XREF[1]:     004add86(j)
//         004adda4     MOV        this,dword ptr [ESI + 0x928]
//         004addaa     MOV        this,dword ptr [ECX + this->_padding_]
//                               LAB_004addad                                                 XREF[3]:     004add82(j), 004add93(j),
//                                                                                                         004adda0(j)
//         004addad     CALL       T_Scenario::SetMPVictory                         void SetMPVictory(T_Scenario * this, int para
//                              scr_sed2.cpp:408 (26)
//         004addb2     MOV        this,dword ptr [ESI + 0x6f8]
//         004addb8     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004addbd     MOV        EDX,dword ptr [ESI + 0x928]
//         004addc3     PUSH       EAX
//         004addc4     MOV        this,dword ptr [EDX + 0x5c]
//         004addc7     CALL       T_Scenario::SetVictoryScore                      void SetVictoryScore(T_Scenario * this, int p
//                              scr_sed2.cpp:409 (26)
//         004addcc     MOV        this,dword ptr [ESI + 0x700]
//         004addd2     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004addd7     PUSH       EAX
//         004addd8     MOV        EAX,dword ptr [ESI + 0x928]
//         004addde     MOV        this,dword ptr [EAX + 0x5c]
//         004adde1     CALL       T_Scenario::SetVictoryTime                       void SetVictoryTime(T_Scenario * this, int pa
//                              scr_sed2.cpp:411 (15)
//         004adde6     MOV        this,dword ptr [ESI + 0x6e0]
//         004addec     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004addf1     TEST       EAX,EAX
//         004addf3     JZ         LAB_004ade02
//                              scr_sed2.cpp:412 (11)
//         004addf5     MOV        this,dword ptr [ESI + 0x928]
//         004addfb     PUSH       0x0
//         004addfd     MOV        this,dword ptr [ECX + this->_padding_]
//                              scr_sed2.cpp:413 (17)
//         004ade00     JMP        LAB_004ade58
//                               LAB_004ade02                                                 XREF[1]:     004addf3(j)
//         004ade02     MOV        this,dword ptr [ESI + 0x6e4]
//         004ade08     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ade0d     TEST       EAX,EAX
//         004ade0f     JZ         LAB_004ade15
//                              scr_sed2.cpp:414 (2)
//         004ade11     PUSH       0x1
//                              scr_sed2.cpp:415 (17)
//         004ade13     JMP        LAB_004ade4f
//                               LAB_004ade15                                                 XREF[1]:     004ade0f(j)
//         004ade15     MOV        this,dword ptr [ESI + 0x6e8]
//         004ade1b     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ade20     TEST       EAX,EAX
//         004ade22     JZ         LAB_004ade31
//                              scr_sed2.cpp:416 (11)
//         004ade24     MOV        EAX,dword ptr [ESI + 0x928]
//         004ade2a     PUSH       0x2
//         004ade2c     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:417 (17)
//         004ade2f     JMP        LAB_004ade58
//                               LAB_004ade31                                                 XREF[1]:     004ade22(j)
//         004ade31     MOV        this,dword ptr [ESI + 0x6ec]
//         004ade37     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ade3c     TEST       EAX,EAX
//         004ade3e     JZ         LAB_004ade4d
//                              scr_sed2.cpp:418 (11)
//         004ade40     MOV        this,dword ptr [ESI + 0x928]
//         004ade46     PUSH       0x3
//         004ade48     MOV        this,dword ptr [ECX + this->_padding_]
//                              scr_sed2.cpp:419 (2)
//         004ade4b     JMP        LAB_004ade58
//                               LAB_004ade4d                                                 XREF[1]:     004ade3e(j)
//                              scr_sed2.cpp:420 (16)
//         004ade4d     PUSH       0x4
//                               LAB_004ade4f                                                 XREF[1]:     004ade13(j)
//         004ade4f     MOV        EDX,dword ptr [ESI + 0x928]
//         004ade55     MOV        this,dword ptr [EDX + 0x5c]
//                               LAB_004ade58                                                 XREF[3]:     004ade00(j), 004ade2f(j),
//                                                                                                         004ade4b(j)
//         004ade58     CALL       T_Scenario::SetMPVictory                         void SetMPVictory(T_Scenario * this, int para
//                              scr_sed2.cpp:422 (26)
//         004ade5d     MOV        this,dword ptr [ESI + 0x6f8]
//         004ade63     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004ade68     PUSH       EAX
//         004ade69     MOV        EAX,dword ptr [ESI + 0x928]
//         004ade6f     MOV        this,dword ptr [EAX + 0x5c]
//         004ade72     CALL       T_Scenario::SetVictoryScore                      void SetVictoryScore(T_Scenario * this, int p
//                              scr_sed2.cpp:423 (26)
//         004ade77     MOV        this,dword ptr [ESI + 0x700]
//         004ade7d     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004ade82     MOV        this,dword ptr [ESI + 0x928]
//         004ade88     PUSH       EAX
//         004ade89     MOV        this,dword ptr [ECX + this->_padding_]
//         004ade8c     CALL       T_Scenario::SetVictoryTime                       void SetVictoryTime(T_Scenario * this, int pa
//                              scr_sed2.cpp:425 (15)
//         004ade91     MOV        this,dword ptr [ESI + 0x684]
//         004ade97     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ade9c     TEST       EAX,EAX
//         004ade9e     JZ         LAB_004adead
//                              scr_sed2.cpp:426 (11)
//         004adea0     MOV        EDX,dword ptr [ESI + 0x928]
//         004adea6     PUSH       0x1
//         004adea8     MOV        this,dword ptr [EDX + 0x5c]
//                              scr_sed2.cpp:427 (2)
//         004adeab     JMP        LAB_004adeb8
//                               LAB_004adead                                                 XREF[1]:     004ade9e(j)
//                              scr_sed2.cpp:428 (16)
//         004adead     MOV        EAX,dword ptr [ESI + 0x928]
//         004adeb3     PUSH       0x0
//         004adeb5     MOV        this,dword ptr [EAX + 0x5c]
//                               LAB_004adeb8                                                 XREF[1]:     004adeab(j)
//         004adeb8     CALL       T_Scenario::Set_victory_all_flag                 void Set_victory_all_flag(T_Scenario * this,
//                              scr_sed2.cpp:430 (30)
//         004adebd     MOV        this,dword ptr [ESI + 0x668]
//         004adec3     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004adec8     TEST       EAX,EAX
//         004adeca     JNZ        LAB_004adee8
//         004adecc     MOV        this,dword ptr [ESI + 0x6f0]
//         004aded2     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004aded7     TEST       EAX,EAX
//         004aded9     JZ         LAB_004adee8
//                              scr_sed2.cpp:433 (13)
//         004adedb     MOV        this,dword ptr [ESI + 0x928]
//         004adee1     PUSH       0x0
//         004adee3     MOV        this,dword ptr [ECX + this->_padding_]
//         004adee6     JMP        LAB_004adef3
//                               LAB_004adee8                                                 XREF[2]:     004adeca(j), 004aded9(j)
//                              scr_sed2.cpp:431 (16)
//         004adee8     MOV        EDX,dword ptr [ESI + 0x928]
//         004adeee     PUSH       0x1
//         004adef0     MOV        this,dword ptr [EDX + 0x5c]
//                               LAB_004adef3                                                 XREF[1]:     004adee6(j)
//         004adef3     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              scr_sed2.cpp:435 (17)
//         004adef8     MOV        this,dword ptr [ESI + 0x6b8]
//         004adefe     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004adf03     PUSH       EAX
//         004adf04     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:436 (20)
//         004adf09     MOV        this,dword ptr [ESI + 0x66c]
//         004adf0f     ADD        ESP,0x4
//         004adf12     MOV        EDI,EAX
//         004adf14     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004adf19     TEST       EAX,EAX
//         004adf1b     JZ         LAB_004adf3d
//                              scr_sed2.cpp:438 (5)
//         004adf1d     CMP        EDI,0x1
//         004adf20     JGE        LAB_004adf27
//                              scr_sed2.cpp:439 (5)
//         004adf22     MOV        EDI,0x1
//                               LAB_004adf27                                                 XREF[1]:     004adf20(j)
//                              scr_sed2.cpp:440 (5)
//         004adf27     CMP        EDI,0x64
//         004adf2a     JLE        LAB_004adf31
//                              scr_sed2.cpp:441 (5)
//         004adf2c     MOV        EDI,0x64
//                               LAB_004adf31                                                 XREF[1]:     004adf2a(j)
//                              scr_sed2.cpp:442 (10)
//         004adf31     MOV        EAX,dword ptr [ESI + 0x928]
//         004adf37     PUSH       EDI
//         004adf38     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:444 (2)
//         004adf3b     JMP        LAB_004adf48
//                               LAB_004adf3d                                                 XREF[1]:     004adf1b(j)
//                              scr_sed2.cpp:445 (16)
//         004adf3d     MOV        this,dword ptr [ESI + 0x928]
//         004adf43     PUSH       0x0
//         004adf45     MOV        this,dword ptr [ECX + this->_padding_]
//                               LAB_004adf48                                                 XREF[1]:     004adf3b(j)
//         004adf48     CALL       T_Scenario::Set_Multi_Exploration                void Set_Multi_Exploration(T_Scenario * this,
//                              scr_sed2.cpp:447 (17)
//         004adf4d     MOV        this,dword ptr [ESI + 0x6bc]
//         004adf53     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004adf58     PUSH       EAX
//         004adf59     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:448 (20)
//         004adf5e     MOV        this,dword ptr [ESI + 0x670]
//         004adf64     ADD        ESP,0x4
//         004adf67     MOV        EDI,EAX
//         004adf69     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004adf6e     TEST       EAX,EAX
//         004adf70     JZ         LAB_004adf7e
//                              scr_sed2.cpp:449 (10)
//         004adf72     MOV        EDX,dword ptr [ESI + 0x928]
//         004adf78     PUSH       EDI
//         004adf79     MOV        this,dword ptr [EDX + 0x5c]
//                              scr_sed2.cpp:450 (2)
//         004adf7c     JMP        LAB_004adf89
//                               LAB_004adf7e                                                 XREF[1]:     004adf70(j)
//                              scr_sed2.cpp:451 (16)
//         004adf7e     MOV        EAX,dword ptr [ESI + 0x928]
//         004adf84     PUSH       0x0
//         004adf86     MOV        this,dword ptr [EAX + 0x5c]
//                               LAB_004adf89                                                 XREF[1]:     004adf7c(j)
//         004adf89     CALL       T_Scenario::Set_Multi_Ruins                      void Set_Multi_Ruins(T_Scenario * this, int p
//                              scr_sed2.cpp:453 (17)
//         004adf8e     MOV        this,dword ptr [ESI + 0x6c0]
//         004adf94     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004adf99     PUSH       EAX
//         004adf9a     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:454 (20)
//         004adf9f     MOV        this,dword ptr [ESI + 0x674]
//         004adfa5     ADD        ESP,0x4
//         004adfa8     MOV        EDI,EAX
//         004adfaa     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004adfaf     TEST       EAX,EAX
//         004adfb1     JZ         LAB_004adfbf
//                              scr_sed2.cpp:455 (10)
//         004adfb3     MOV        this,dword ptr [ESI + 0x928]
//         004adfb9     PUSH       EDI
//         004adfba     MOV        this,dword ptr [ECX + this->_padding_]
//                              scr_sed2.cpp:456 (2)
//         004adfbd     JMP        LAB_004adfca
//                               LAB_004adfbf                                                 XREF[1]:     004adfb1(j)
//                              scr_sed2.cpp:457 (16)
//         004adfbf     MOV        EDX,dword ptr [ESI + 0x928]
//         004adfc5     PUSH       0x0
//         004adfc7     MOV        this,dword ptr [EDX + 0x5c]
//                               LAB_004adfca                                                 XREF[1]:     004adfbd(j)
//         004adfca     CALL       T_Scenario::Set_Multi_Artifacts                  void Set_Multi_Artifacts(T_Scenario * this, i
//                              scr_sed2.cpp:459 (17)
//         004adfcf     MOV        this,dword ptr [ESI + 0x6c4]
//         004adfd5     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004adfda     PUSH       EAX
//         004adfdb     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:460 (20)
//         004adfe0     MOV        this,dword ptr [ESI + 0x678]
//         004adfe6     ADD        ESP,0x4
//         004adfe9     MOV        EDI,EAX
//         004adfeb     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004adff0     TEST       EAX,EAX
//         004adff2     JZ         LAB_004ae000
//                              scr_sed2.cpp:461 (10)
//         004adff4     MOV        EAX,dword ptr [ESI + 0x928]
//         004adffa     PUSH       EDI
//         004adffb     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:462 (2)
//         004adffe     JMP        LAB_004ae00b
//                               LAB_004ae000                                                 XREF[1]:     004adff2(j)
//                              scr_sed2.cpp:463 (16)
//         004ae000     MOV        this,dword ptr [ESI + 0x928]
//         004ae006     PUSH       0x0
//         004ae008     MOV        this,dword ptr [ECX + this->_padding_]
//                               LAB_004ae00b                                                 XREF[1]:     004adffe(j)
//         004ae00b     CALL       T_Scenario::Set_Multi_Discoveries                void Set_Multi_Discoveries(T_Scenario * this,
//                              scr_sed2.cpp:465 (17)
//         004ae010     MOV        this,dword ptr [ESI + 0x6c8]
//         004ae016     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004ae01b     PUSH       EAX
//         004ae01c     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:466 (20)
//         004ae021     MOV        this,dword ptr [ESI + 0x67c]
//         004ae027     ADD        ESP,0x4
//         004ae02a     MOV        EDI,EAX
//         004ae02c     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ae031     TEST       EAX,EAX
//         004ae033     JZ         LAB_004ae047
//                              scr_sed2.cpp:467 (10)
//         004ae035     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae03b     PUSH       EDI
//         004ae03c     MOV        this,dword ptr [EDX + 0x5c]
//                              scr_sed2.cpp:469 (5)
//         004ae03f     CALL       T_Scenario::Set_Multi_Gold                       void Set_Multi_Gold(T_Scenario * this, int pa
//                              scr_sed2.cpp:470 (3)
//         004ae044     POP        EDI
//         004ae045     POP        ESI
//         004ae046     RET
//                               LAB_004ae047                                                 XREF[1]:     004ae033(j)
//                              scr_sed2.cpp:469 (16)
//         004ae047     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae04d     PUSH       0x0
//         004ae04f     MOV        this,dword ptr [EAX + 0x5c]
//         004ae052     CALL       T_Scenario::Set_Multi_Gold                       void Set_Multi_Gold(T_Scenario * this, int pa
//                              scr_sed2.cpp:470 (21)
//         004ae057     POP        EDI
//         004ae058     POP        ESI
//         004ae059     RET
    return;
}

void TRIBE_Screen_Sed::save_victory_cond_in_scenario(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save_victory_cond_in_scenario(TRIBE_Screen_Sed * thi
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[6]:     004ae0e0(R), 004ae12e(W), 004ae278(R), 004ae2a2(R),
//                                                                                     004ae336(R), 004ae3d6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ae113(W), 004ae186(R)
//              int               Stack[-0x8]:4  VictoryType               XREF[2]:     004ae12a(*), 004ae174(R)
//              long              Stack[-0xc]:4  y2                        XREF[2]:     004ae134(*), 004ae16a(R)
//              long              Stack[-0x10]:4 x2                        XREF[2]:     004ae139(*), 004ae160(R)
//              long              Stack[-0x14]:4 y1                        XREF[2]:     004ae13e(*), 004ae14f(R)
//              long              Stack[-0x18]:4 x1
//                               ?save_victory_cond_in_scenario@TRIBE_Screen_Sed@@IAEXH@Z     XREF[3]:     set_scenario_mode:004aa147(c),
//                               TRIBE_Screen_Sed::save_victory_cond_in_scenario                           action:004ac0b2(c),
//                                                                                                         action:004ac41c(c)
//                              scr_sed2.cpp:476 (9)
//         004ae070     SUB        ESP,0x14
//         004ae073     PUSH       EBX
//         004ae074     PUSH       EBP
//         004ae075     PUSH       ESI
//         004ae076     MOV        ESI,this
//         004ae078     PUSH       EDI
//                              scr_sed2.cpp:477 (15)
//         004ae079     MOV        this,dword ptr [ESI + 0x684]
//         004ae07f     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ae084     TEST       EAX,EAX
//         004ae086     JZ         LAB_004ae095
//                              scr_sed2.cpp:478 (11)
//         004ae088     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae08e     PUSH       0x1
//         004ae090     MOV        this,dword ptr [EAX + 0x5c]
//                              scr_sed2.cpp:479 (2)
//         004ae093     JMP        LAB_004ae0a0
//                               LAB_004ae095                                                 XREF[1]:     004ae086(j)
//                              scr_sed2.cpp:480 (16)
//         004ae095     MOV        this,dword ptr [ESI + 0x928]
//         004ae09b     PUSH       0x0
//         004ae09d     MOV        this,dword ptr [ECX + this->_padding_]
//                               LAB_004ae0a0                                                 XREF[1]:     004ae093(j)
//         004ae0a0     CALL       T_Scenario::Set_victory_all_flag                 void Set_victory_all_flag(T_Scenario * this,
//                              scr_sed2.cpp:482 (30)
//         004ae0a5     MOV        this,dword ptr [ESI + 0x668]
//         004ae0ab     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ae0b0     TEST       EAX,EAX
//         004ae0b2     JNZ        LAB_004ae0d0
//         004ae0b4     MOV        this,dword ptr [ESI + 0x6f0]
//         004ae0ba     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004ae0bf     TEST       EAX,EAX
//         004ae0c1     JZ         LAB_004ae0d0
//                              scr_sed2.cpp:485 (13)
//         004ae0c3     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae0c9     PUSH       0x0
//         004ae0cb     MOV        this,dword ptr [EDX + 0x5c]
//         004ae0ce     JMP        LAB_004ae0db
//                               LAB_004ae0d0                                                 XREF[2]:     004ae0b2(j), 004ae0c1(j)
//                              scr_sed2.cpp:483 (16)
//         004ae0d0     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae0d6     PUSH       0x1
//         004ae0d8     MOV        this,dword ptr [EAX + 0x5c]
//                               LAB_004ae0db                                                 XREF[1]:     004ae0ce(j)
//         004ae0db     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              scr_sed2.cpp:487 (12)
//         004ae0e0     MOV        EDI,dword ptr [ESP + param_1]
//         004ae0e4     TEST       EDI,EDI
//         004ae0e6     JL         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:490 (17)
//         004ae0ec     MOV        this,dword ptr [ESI + 0x76c]
//         004ae0f2     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004ae0f7     PUSH       EAX
//         004ae0f8     CALL       atoi                                             undefined atoi()
//                              scr_sed2.cpp:491 (16)
//         004ae0fd     MOV        this,dword ptr [ESI + 0x734]
//         004ae103     ADD        ESP,0x4
//         004ae106     MOV        EBX,EAX
//         004ae108     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//                              scr_sed2.cpp:492 (15)
//         004ae10d     MOV        this,dword ptr [ESI + 0x740]
//         004ae113     MOV        dword ptr [ESP + local_4],EAX
//         004ae117     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//                              scr_sed2.cpp:493 (14)
//         004ae11c     MOV        this,dword ptr [ESI + 0x738]
//         004ae122     MOV        EBP,EAX
//         004ae124     INC        EBP
//         004ae125     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//                              scr_sed2.cpp:496 (37)
//         004ae12a     LEA        this=>VictoryType,[ESP + 0x1c]
//         004ae12e     MOV        dword ptr [ESP + param_1],EAX
//         004ae132     PUSH       0x1
//         004ae134     LEA        EDX=>y2,[ESP + 0x1c]
//         004ae138     PUSH       this
//         004ae139     LEA        EAX=>x2,[ESP + 0x1c]
//         004ae13d     PUSH       EDX
//         004ae13e     LEA        this=>y1,[ESP + 0x1c]
//         004ae142     PUSH       EAX
//         004ae143     PUSH       this
//         004ae144     MOV        this,dword ptr [ESI + 0x4c8]
//         004ae14a     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long
//                              scr_sed2.cpp:497 (4)
//         004ae14f     FILD       dword ptr [ESP + y1]
//                              scr_sed2.cpp:499 (51)
//         004ae153     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae159     PUSH       EDI
//         004ae15a     FSTP       float ptr [ESI + 0x488]
//         004ae160     FILD       dword ptr [ESP + x2]
//         004ae164     FSTP       float ptr [ESI + 0x48c]
//         004ae16a     FILD       dword ptr [ESP + y2]
//         004ae16e     FSTP       float ptr [ESI + 0x490]
//         004ae174     FILD       dword ptr [ESP + VictoryType]
//         004ae178     FSTP       float ptr [ESI + 0x494]
//         004ae17e     MOV        this,dword ptr [EDX + 0x5c]
//         004ae181     CALL       T_Scenario::ClearSPVictoryCondition              void ClearSPVictoryCondition(T_Scenario * thi
//                              scr_sed2.cpp:500 (20)
//         004ae186     MOV        EAX,dword ptr [ESP + local_4]
//         004ae18a     CMP        EAX,0x12
//         004ae18d     JA         switchD_004ae193::caseD_0
//                               switchD_004ae193::switchD
//         004ae193     JMP        dword ptr [EAX*0x4 + switchD_004ae193::switchd   = 004ae5c5
//                               switchD_004ae193::caseD_1                                    XREF[2]:     004ae193(j), 004ae5d4(*)
//                              scr_sed2.cpp:506 (28)
//         004ae19a     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae1a0     TEST       EAX,EAX
//         004ae1a2     JZ         switchD_004ae193::caseD_0
//         004ae1a8     MOV        EAX,dword ptr [ESI + 0x484]
//         004ae1ae     TEST       EAX,EAX
//         004ae1b0     JZ         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:509 (17)
//         004ae1b6     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae1bc     PUSH       0x3
//         004ae1be     PUSH       EDI
//         004ae1bf     MOV        this,dword ptr [EAX + 0x5c]
//         004ae1c2     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:510 (22)
//         004ae1c7     MOV        this,dword ptr [ESI + 0x480]
//         004ae1cd     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae1d3     PUSH       this
//         004ae1d4     PUSH       EDI
//         004ae1d5     MOV        this,dword ptr [EDX + 0x5c]
//         004ae1d8     CALL       T_Scenario::SetSPObject                          void SetSPObject(T_Scenario * this, int param
//                              scr_sed2.cpp:511 (22)
//         004ae1dd     MOV        EAX,dword ptr [ESI + 0x484]
//         004ae1e3     MOV        this,dword ptr [ESI + 0x928]
//         004ae1e9     PUSH       EAX
//         004ae1ea     PUSH       EDI
//         004ae1eb     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae1ee     CALL       T_Scenario::SetSPDestObjectID                    void SetSPDestObjectID(T_Scenario * this, int
//                              scr_sed2.cpp:631 (10)
//         004ae1f3     POP        EDI
//         004ae1f4     POP        ESI
//         004ae1f5     POP        EBP
//         004ae1f6     POP        EBX
//         004ae1f7     ADD        ESP,0x14
//         004ae1fa     RET        0x4
//                               switchD_004ae193::caseD_2                                    XREF[2]:     004ae193(j), 004ae5d8(*)
//                              scr_sed2.cpp:515 (14)
//         004ae1fd     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae203     TEST       EAX,EAX
//         004ae205     JZ         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:517 (17)
//         004ae20b     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae211     PUSH       0x3
//         004ae213     PUSH       EDI
//         004ae214     MOV        this,dword ptr [EDX + 0x5c]
//         004ae217     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:518 (22)
//         004ae21c     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae222     MOV        this,dword ptr [ESI + 0x928]
//         004ae228     PUSH       EAX
//         004ae229     PUSH       EDI
//         004ae22a     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae22d     CALL       T_Scenario::SetSPObject                          void SetSPObject(T_Scenario * this, int param
//                              scr_sed2.cpp:519 (43)
//         004ae232     MOV        EDX,dword ptr [ESI + 0x494]
//         004ae238     MOV        EAX,dword ptr [ESI + 0x490]
//         004ae23e     MOV        this,dword ptr [ESI + 0x48c]
//         004ae244     PUSH       EDX
//         004ae245     MOV        EDX,dword ptr [ESI + 0x488]
//         004ae24b     PUSH       EAX
//         004ae24c     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae252     PUSH       this
//         004ae253     PUSH       EDX
//         004ae254     PUSH       EDI
//         004ae255     MOV        this,dword ptr [EAX + 0x5c]
//         004ae258     CALL       T_Scenario::SetSPRectangle                       void SetSPRectangle(T_Scenario * this, int pa
//                              scr_sed2.cpp:631 (10)
//         004ae25d     POP        EDI
//         004ae25e     POP        ESI
//         004ae25f     POP        EBP
//         004ae260     POP        EBX
//         004ae261     ADD        ESP,0x14
//         004ae264     RET        0x4
//                               switchD_004ae193::caseD_3                                    XREF[2]:     004ae193(j), 004ae5dc(*)
//                              scr_sed2.cpp:523 (17)
//         004ae267     MOV        this,dword ptr [ESI + 0x928]
//         004ae26d     PUSH       0x2
//         004ae26f     PUSH       EDI
//         004ae270     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae273     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:524 (20)
//         004ae278     MOV        EDX,dword ptr [ESP + param_1]
//         004ae27c     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae282     PUSH       EDX
//         004ae283     PUSH       EDI
//         004ae284     MOV        this,dword ptr [EAX + 0x5c]
//         004ae287     CALL       T_Scenario::SetSPObjectType                      void SetSPObjectType(T_Scenario * this, int p
//                              scr_sed2.cpp:526 (5)
//         004ae28c     JMP        LAB_004ae57f
//                               switchD_004ae193::caseD_4                                    XREF[2]:     004ae193(j), 004ae5e0(*)
//                              scr_sed2.cpp:529 (17)
//         004ae291     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae297     PUSH       0x2
//         004ae299     PUSH       EDI
//         004ae29a     MOV        this,dword ptr [EDX + 0x5c]
//         004ae29d     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:530 (20)
//         004ae2a2     MOV        EAX,dword ptr [ESP + param_1]
//         004ae2a6     MOV        this,dword ptr [ESI + 0x928]
//         004ae2ac     PUSH       EAX
//         004ae2ad     PUSH       EDI
//         004ae2ae     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae2b1     CALL       T_Scenario::SetSPObjectType                      void SetSPObjectType(T_Scenario * this, int p
//                              scr_sed2.cpp:531 (16)
//         004ae2b6     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae2bc     PUSH       EBX
//         004ae2bd     PUSH       EDI
//         004ae2be     MOV        this,dword ptr [EDX + 0x5c]
//         004ae2c1     CALL       T_Scenario::SetSPAmount                          void SetSPAmount(T_Scenario * this, int param
//                              scr_sed2.cpp:532 (43)
//         004ae2c6     MOV        EAX,dword ptr [ESI + 0x494]
//         004ae2cc     MOV        this,dword ptr [ESI + 0x490]
//         004ae2d2     MOV        EDX,dword ptr [ESI + 0x48c]
//         004ae2d8     PUSH       EAX
//         004ae2d9     MOV        EAX,dword ptr [ESI + 0x488]
//         004ae2df     PUSH       this
//         004ae2e0     MOV        this,dword ptr [ESI + 0x928]
//         004ae2e6     PUSH       EDX
//         004ae2e7     PUSH       EAX
//         004ae2e8     PUSH       EDI
//         004ae2e9     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae2ec     CALL       T_Scenario::SetSPRectangle                       void SetSPRectangle(T_Scenario * this, int pa
//                              scr_sed2.cpp:631 (10)
//         004ae2f1     POP        EDI
//         004ae2f2     POP        ESI
//         004ae2f3     POP        EBP
//         004ae2f4     POP        EBX
//         004ae2f5     ADD        ESP,0x14
//         004ae2f8     RET        0x4
//                               switchD_004ae193::caseD_5                                    XREF[2]:     004ae193(j), 004ae5e4(*)
//                              scr_sed2.cpp:536 (18)
//         004ae2fb     CMP        EBP,0x1
//         004ae2fe     JL         switchD_004ae193::caseD_0
//         004ae304     CMP        EBP,0x8
//         004ae307     JG         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:538 (8)
//         004ae30d     TEST       EBX,EBX
//         004ae30f     JZ         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:540 (17)
//         004ae315     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae31b     PUSH       0x1
//         004ae31d     PUSH       EDI
//         004ae31e     MOV        this,dword ptr [EDX + 0x5c]
//         004ae321     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:541 (16)
//         004ae326     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae32c     PUSH       EBP
//         004ae32d     PUSH       EDI
//         004ae32e     MOV        this,dword ptr [EAX + 0x5c]
//         004ae331     CALL       T_Scenario::SetSPPlayerID                        void SetSPPlayerID(T_Scenario * this, int par
//                              scr_sed2.cpp:542 (20)
//         004ae336     MOV        this,dword ptr [ESP + param_1]
//         004ae33a     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae340     PUSH       this
//         004ae341     PUSH       EDI
//         004ae342     MOV        this,dword ptr [EDX + 0x5c]
//         004ae345     CALL       T_Scenario::SetSPObjectType                      void SetSPObjectType(T_Scenario * this, int p
//                              scr_sed2.cpp:543 (16)
//         004ae34a     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae350     PUSH       EBX
//         004ae351     PUSH       EDI
//         004ae352     MOV        this,dword ptr [EAX + 0x5c]
//         004ae355     CALL       T_Scenario::SetSPAmount                          void SetSPAmount(T_Scenario * this, int param
//                              scr_sed2.cpp:631 (10)
//         004ae35a     POP        EDI
//         004ae35b     POP        ESI
//         004ae35c     POP        EBP
//         004ae35d     POP        EBX
//         004ae35e     ADD        ESP,0x14
//         004ae361     RET        0x4
//                               switchD_004ae193::caseD_6                                    XREF[2]:     004ae193(j), 004ae5e8(*)
//                              scr_sed2.cpp:547 (14)
//         004ae364     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae36a     TEST       EAX,EAX
//         004ae36c     JZ         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:549 (17)
//         004ae372     MOV        this,dword ptr [ESI + 0x928]
//         004ae378     PUSH       0x1
//         004ae37a     PUSH       EDI
//         004ae37b     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae37e     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:550 (22)
//         004ae383     MOV        EDX,dword ptr [ESI + 0x480]
//         004ae389     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae38f     PUSH       EDX
//         004ae390     PUSH       EDI
//         004ae391     MOV        this,dword ptr [EAX + 0x5c]
//         004ae394     CALL       T_Scenario::SetSPObject                          void SetSPObject(T_Scenario * this, int param
//                              scr_sed2.cpp:631 (10)
//         004ae399     POP        EDI
//         004ae39a     POP        ESI
//         004ae39b     POP        EBP
//         004ae39c     POP        EBX
//         004ae39d     ADD        ESP,0x14
//         004ae3a0     RET        0x4
//                               switchD_004ae193::caseD_7                                    XREF[2]:     004ae193(j), 004ae5ec(*)
//                              scr_sed2.cpp:554 (18)
//         004ae3a3     CMP        EBP,0x1
//         004ae3a6     JL         switchD_004ae193::caseD_0
//         004ae3ac     CMP        EBP,0x8
//         004ae3af     JG         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:556 (17)
//         004ae3b5     MOV        this,dword ptr [ESI + 0x928]
//         004ae3bb     PUSH       0x1
//         004ae3bd     PUSH       EDI
//         004ae3be     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae3c1     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:557 (16)
//         004ae3c6     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae3cc     PUSH       EBP
//         004ae3cd     PUSH       EDI
//         004ae3ce     MOV        this,dword ptr [EDX + 0x5c]
//         004ae3d1     CALL       T_Scenario::SetSPPlayerID                        void SetSPPlayerID(T_Scenario * this, int par
//                              scr_sed2.cpp:558 (20)
//         004ae3d6     MOV        EAX,dword ptr [ESP + param_1]
//         004ae3da     MOV        this,dword ptr [ESI + 0x928]
//         004ae3e0     PUSH       EAX
//         004ae3e1     PUSH       EDI
//         004ae3e2     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae3e5     CALL       T_Scenario::SetSPObjectType                      void SetSPObjectType(T_Scenario * this, int p
//                              scr_sed2.cpp:559 (17)
//         004ae3ea     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae3f0     PUSH       0x1
//         004ae3f2     PUSH       EDI
//         004ae3f3     MOV        this,dword ptr [EDX + 0x5c]
//         004ae3f6     CALL       T_Scenario::SetSPAllFlag                         void SetSPAllFlag(T_Scenario * this, int para
//                              scr_sed2.cpp:631 (10)
//         004ae3fb     POP        EDI
//         004ae3fc     POP        ESI
//         004ae3fd     POP        EBP
//         004ae3fe     POP        EBX
//         004ae3ff     ADD        ESP,0x14
//         004ae402     RET        0x4
//                               switchD_004ae193::caseD_8                                    XREF[2]:     004ae193(j), 004ae5f0(*)
//                              scr_sed2.cpp:563 (18)
//         004ae405     CMP        EBP,0x1
//         004ae408     JL         switchD_004ae193::caseD_0
//         004ae40e     CMP        EBP,0x8
//         004ae411     JG         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:565 (17)
//         004ae417     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae41d     PUSH       0x1
//         004ae41f     PUSH       EDI
//         004ae420     MOV        this,dword ptr [EAX + 0x5c]
//         004ae423     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:566 (16)
//         004ae428     MOV        this,dword ptr [ESI + 0x928]
//         004ae42e     PUSH       EBP
//         004ae42f     PUSH       EDI
//         004ae430     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae433     CALL       T_Scenario::SetSPPlayerID                        void SetSPPlayerID(T_Scenario * this, int par
//                              scr_sed2.cpp:631 (10)
//         004ae438     POP        EDI
//         004ae439     POP        ESI
//         004ae43a     POP        EBP
//         004ae43b     POP        EBX
//         004ae43c     ADD        ESP,0x14
//         004ae43f     RET        0x4
//                               switchD_004ae193::caseD_9                                    XREF[2]:     004ae193(j), 004ae5f4(*)
//                              scr_sed2.cpp:570 (14)
//         004ae442     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae448     TEST       EAX,EAX
//         004ae44a     JZ         switchD_004ae193::caseD_0
//                              scr_sed2.cpp:572 (17)
//         004ae450     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae456     PUSH       0x5
//         004ae458     PUSH       EDI
//         004ae459     MOV        this,dword ptr [EDX + 0x5c]
//         004ae45c     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:573 (22)
//         004ae461     MOV        EAX,dword ptr [ESI + 0x480]
//         004ae467     MOV        this,dword ptr [ESI + 0x928]
//         004ae46d     PUSH       EAX
//         004ae46e     PUSH       EDI
//         004ae46f     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae472     CALL       T_Scenario::SetSPObject                          void SetSPObject(T_Scenario * this, int param
//                              scr_sed2.cpp:631 (10)
//         004ae477     POP        EDI
//         004ae478     POP        ESI
//         004ae479     POP        EBP
//         004ae47a     POP        EBX
//         004ae47b     ADD        ESP,0x14
//         004ae47e     RET        0x4
//                               switchD_004ae193::caseD_a                                    XREF[2]:     004ae193(j), 004ae5f8(*)
//                              scr_sed2.cpp:577 (17)
//         004ae481     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae487     PUSH       0x4
//         004ae489     PUSH       EDI
//         004ae48a     MOV        this,dword ptr [EDX + 0x5c]
//         004ae48d     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:578 (2)
//         004ae492     PUSH       0x0
//                              scr_sed2.cpp:580 (5)
//         004ae494     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_b                                    XREF[2]:     004ae193(j), 004ae5fc(*)
//                              scr_sed2.cpp:583 (17)
//         004ae499     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae49f     PUSH       0x4
//         004ae4a1     PUSH       EDI
//         004ae4a2     MOV        this,dword ptr [EDX + 0x5c]
//         004ae4a5     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:584 (2)
//         004ae4aa     PUSH       0x3
//                              scr_sed2.cpp:586 (5)
//         004ae4ac     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_c                                    XREF[2]:     004ae193(j), 004ae600(*)
//                              scr_sed2.cpp:589 (17)
//         004ae4b1     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae4b7     PUSH       0x4
//         004ae4b9     PUSH       EDI
//         004ae4ba     MOV        this,dword ptr [EDX + 0x5c]
//         004ae4bd     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:590 (2)
//         004ae4c2     PUSH       0x1
//                              scr_sed2.cpp:592 (5)
//         004ae4c4     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_d                                    XREF[2]:     004ae193(j), 004ae604(*)
//                              scr_sed2.cpp:595 (17)
//         004ae4c9     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae4cf     PUSH       0x4
//         004ae4d1     PUSH       EDI
//         004ae4d2     MOV        this,dword ptr [EDX + 0x5c]
//         004ae4d5     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:596 (2)
//         004ae4da     PUSH       0x2
//                              scr_sed2.cpp:598 (5)
//         004ae4dc     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_e                                    XREF[2]:     004ae193(j), 004ae608(*)
//                              scr_sed2.cpp:601 (17)
//         004ae4e1     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae4e7     PUSH       0x4
//         004ae4e9     PUSH       EDI
//         004ae4ea     MOV        this,dword ptr [EDX + 0x5c]
//         004ae4ed     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:602 (2)
//         004ae4f2     PUSH       0x4
//                              scr_sed2.cpp:604 (2)
//         004ae4f4     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_f                                    XREF[2]:     004ae193(j), 004ae60c(*)
//                              scr_sed2.cpp:607 (17)
//         004ae4f6     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae4fc     PUSH       0x4
//         004ae4fe     PUSH       EDI
//         004ae4ff     MOV        this,dword ptr [EDX + 0x5c]
//         004ae502     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:608 (17)
//         004ae507     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae50d     PUSH       0x5
//         004ae50f     PUSH       EDI
//         004ae510     MOV        this,dword ptr [EAX + 0x5c]
//         004ae513     CALL       T_Scenario::SetSPAttribType                      void SetSPAttribType(T_Scenario * this, int p
//                              scr_sed2.cpp:610 (28)
//         004ae518     MOV        this,dword ptr [ESI + 0x748]
//         004ae51e     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//         004ae523     MOV        this,dword ptr [ESI + 0x928]
//         004ae529     INC        EAX
//         004ae52a     PUSH       EAX
//         004ae52b     PUSH       EDI
//         004ae52c     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae52f     CALL       T_Scenario::SetSPAmount                          void SetSPAmount(T_Scenario * this, int param
//                              scr_sed2.cpp:631 (10)
//         004ae534     POP        EDI
//         004ae535     POP        ESI
//         004ae536     POP        EBP
//         004ae537     POP        EBX
//         004ae538     ADD        ESP,0x14
//         004ae53b     RET        0x4
//                               switchD_004ae193::caseD_10                                   XREF[2]:     004ae193(j), 004ae610(*)
//                              scr_sed2.cpp:614 (17)
//         004ae53e     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae544     PUSH       0x4
//         004ae546     PUSH       EDI
//         004ae547     MOV        this,dword ptr [EDX + 0x5c]
//         004ae54a     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:615 (2)
//         004ae54f     PUSH       0x6
//                              scr_sed2.cpp:617 (2)
//         004ae551     JMP        LAB_004ae570
//                               switchD_004ae193::caseD_11                                   XREF[2]:     004ae193(j), 004ae614(*)
//                              scr_sed2.cpp:620 (17)
//         004ae553     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae559     PUSH       0x6
//         004ae55b     PUSH       EDI
//         004ae55c     MOV        this,dword ptr [EDX + 0x5c]
//         004ae55f     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:621 (27)
//         004ae564     MOV        this,dword ptr [ESI + 0x744]
//         004ae56a     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004ae56f     PUSH       EAX
//                               LAB_004ae570                                                 XREF[6]:     004ae494(j), 004ae4ac(j),
//                                                                                                         004ae4c4(j), 004ae4dc(j),
//                                                                                                         004ae4f4(j), 004ae551(j)
//         004ae570     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae576     PUSH       EDI
//         004ae577     MOV        this,dword ptr [EAX + 0x5c]
//         004ae57a     CALL       T_Scenario::SetSPAttribType                      void SetSPAttribType(T_Scenario * this, int p
//                               LAB_004ae57f                                                 XREF[1]:     004ae28c(j)
//                              scr_sed2.cpp:622 (16)
//         004ae57f     MOV        this,dword ptr [ESI + 0x928]
//         004ae585     PUSH       EBX
//         004ae586     PUSH       EDI
//         004ae587     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae58a     CALL       T_Scenario::SetSPAmount                          void SetSPAmount(T_Scenario * this, int param
//                              scr_sed2.cpp:631 (10)
//         004ae58f     POP        EDI
//         004ae590     POP        ESI
//         004ae591     POP        EBP
//         004ae592     POP        EBX
//         004ae593     ADD        ESP,0x14
//         004ae596     RET        0x4
//                               switchD_004ae193::caseD_12                                   XREF[2]:     004ae193(j), 004ae618(*)
//                              scr_sed2.cpp:626 (17)
//         004ae599     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae59f     PUSH       0x7
//         004ae5a1     PUSH       EDI
//         004ae5a2     MOV        this,dword ptr [EDX + 0x5c]
//         004ae5a5     CALL       T_Scenario::SetSPVictoryType                     void SetSPVictoryType(T_Scenario * this, int
//                              scr_sed2.cpp:627 (27)
//         004ae5aa     MOV        this,dword ptr [ESI + 0x74c]
//         004ae5b0     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004ae5b5     PUSH       EAX
//         004ae5b6     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae5bc     PUSH       EDI
//         004ae5bd     MOV        this,dword ptr [EAX + 0x5c]
//         004ae5c0     CALL       T_Scenario::SetSPAttribType                      void SetSPAttribType(T_Scenario * this, int p
//                               switchD_004ae193::caseD_0                                    XREF[16]:    004ae0e6(j), 004ae18d(j),
//                                                                                                         004ae193(j), 004ae1a2(j),
//                                                                                                         004ae1b0(j), 004ae205(j),
//                                                                                                         004ae2fe(j), 004ae307(j),
//                                                                                                         004ae30f(j), 004ae36c(j),
//                                                                                                         004ae3a6(j), 004ae3af(j),
//                                                                                                         004ae408(j), 004ae411(j),
//                                                                                                         004ae44a(j), 004ae5d0(*)
//                              scr_sed2.cpp:631 (87)
//         004ae5c5     POP        EDI
//         004ae5c6     POP        ESI
//         004ae5c7     POP        EBP
//         004ae5c8     POP        EBX
//         004ae5c9     ADD        ESP,0x14
//         004ae5cc     RET        0x4
//         004ae5cf     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004ae193::switchdataD_004ae5d0                       XREF[1]:     save_victory_cond_in_scenario:004a
//         004ae5d0     addr       switchD_004ae193::caseD_0
//         004ae5d4     addr       switchD_004ae193::caseD_1
//         004ae5d8     addr       switchD_004ae193::caseD_2
//         004ae5dc     addr       switchD_004ae193::caseD_3
//         004ae5e0     addr       switchD_004ae193::caseD_4
//         004ae5e4     addr       switchD_004ae193::caseD_5
//         004ae5e8     addr       switchD_004ae193::caseD_6
//         004ae5ec     addr       switchD_004ae193::caseD_7
//         004ae5f0     addr       switchD_004ae193::caseD_8
//         004ae5f4     addr       switchD_004ae193::caseD_9
//         004ae5f8     addr       switchD_004ae193::caseD_a
//         004ae5fc     addr       switchD_004ae193::caseD_b
//         004ae600     addr       switchD_004ae193::caseD_c
//         004ae604     addr       switchD_004ae193::caseD_d
//         004ae608     addr       switchD_004ae193::caseD_e
//         004ae60c     addr       switchD_004ae193::caseD_f
//         004ae610     addr       switchD_004ae193::caseD_10
//         004ae614     addr       switchD_004ae193::caseD_11
//         004ae618     addr       switchD_004ae193::caseD_12
//         004ae61c     ??         90h
//         004ae61d     ??         90h
//         004ae61e     ??         90h
//         004ae61f     ??         90h
    return;
}

void TRIBE_Screen_Sed::load_victory_cond_from_scenario(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load_victory_cond_from_scenario(TRIBE_Screen_Sed * t
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              char[40]          Stack[-0x2c]   str
//              RGE_Static_Obj    Stack[-0x30]:4 destobj
//              int               Stack[-0x34]:4 Amount
//              int               Stack[-0x38]:4 VictoryType
//              long              Stack[-0x3c]:4 x1
//              long              Stack[-0x40]:4 y1
//              long              Stack[-0x44]:4 x2
//              long              Stack[-0x48]:4 y2
//              RGE_Static_Obj    Stack[-0x4c]:4 obj
//                               ?load_victory_cond_from_scenario@TRIBE_Screen_Sed@@IAEXH@Z   XREF[3]:     set_scenario_mode:004aa120(c),
//                               TRIBE_Screen_Sed::load_victory_cond_from_scenario                         action:004ac0ff(c),
//                                                                                                         action:004ac445(c)
//                              scr_sed2.cpp:638 (9)
//         004ae620     SUB        ESP,0x48
//         004ae623     PUSH       EBX
//         004ae624     PUSH       EBP
//         004ae625     PUSH       ESI
//         004ae626     MOV        ESI,this
//         004ae628     PUSH       EDI
//                              scr_sed2.cpp:640 (14)
//         004ae629     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae62f     MOV        this,dword ptr [EAX + 0x5c]
//         004ae632     CALL       T_Scenario::Get_victory_all_flag                 int Get_victory_all_flag(T_Scenario * this)
//                              scr_sed2.cpp:644 (21)
//         004ae637     MOV        this,dword ptr [ESI + 0x680]
//         004ae63d     XOR        EBX,EBX
//         004ae63f     CMP        EAX,EBX
//         004ae641     MOV        EDX,dword ptr [this->_padding_]
//         004ae643     JZ         LAB_004ae658
//         004ae645     PUSH       EBX
//         004ae646     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:645 (10)
//         004ae64c     MOV        this,dword ptr [ESI + 0x684]
//         004ae652     PUSH       0x1
//         004ae654     MOV        EAX,dword ptr [this->_padding_]
//                              scr_sed2.cpp:647 (2)
//         004ae656     JMP        LAB_004ae669
//                               LAB_004ae658                                                 XREF[1]:     004ae643(j)
//                              scr_sed2.cpp:649 (8)
//         004ae658     PUSH       0x1
//         004ae65a     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:650 (15)
//         004ae660     MOV        this,dword ptr [ESI + 0x684]
//         004ae666     PUSH       EBX
//         004ae667     MOV        EAX,dword ptr [this->_padding_]
//                               LAB_004ae669                                                 XREF[1]:     004ae656(j)
//         004ae669     CALL       dword ptr [EAX + 0xe0]
//                              scr_sed2.cpp:655 (12)
//         004ae66f     MOV        EDI,dword ptr [ESP + 0x5c]
//         004ae673     CMP        EDI,EBX
//         004ae675     JL         switchD_004ae82a::default
//                              scr_sed2.cpp:659 (26)
//         004ae67b     MOV        this,dword ptr [ESI + 0x928]
//         004ae681     MOV        dword ptr [ESI + 0x480],EBX
//         004ae687     MOV        dword ptr [ESI + 0x484],EBX
//         004ae68d     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae690     MOV        EDX,dword ptr [this->_padding_]
//         004ae692     CALL       dword ptr [EDX + 0x8]
//                              scr_sed2.cpp:662 (23)
//         004ae695     MOVSX      EAX,word ptr [ESI + 0x4b8]
//         004ae69c     MOV        this,dword ptr [ESI + 0x928]
//         004ae6a2     DEC        EAX
//         004ae6a3     PUSH       EAX
//         004ae6a4     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae6a7     CALL       T_Scenario::SetSPWhich                           void SetSPWhich(T_Scenario * this, int param_1)
//                              scr_sed2.cpp:665 (15)
//         004ae6ac     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae6b2     PUSH       EDI
//         004ae6b3     MOV        this,dword ptr [EDX + 0x5c]
//         004ae6b6     CALL       T_Scenario::GetSPAmount                          int GetSPAmount(T_Scenario * this, int param_1)
//                              scr_sed2.cpp:666 (17)
//         004ae6bb     LEA        this,[ESP + 0x30]
//         004ae6bf     PUSH       0xa
//         004ae6c1     PUSH       this
//         004ae6c2     PUSH       EAX
//         004ae6c3     MOV        dword ptr [ESP + 0x34],EAX
//         004ae6c7     CALL       itoa                                             undefined itoa()
//                              scr_sed2.cpp:667 (19)
//         004ae6cc     MOV        this,dword ptr [ESI + 0x76c]
//         004ae6d2     ADD        ESP,0xc
//         004ae6d5     LEA        EDX,[ESP + 0x30]
//         004ae6d9     PUSH       EDX
//         004ae6da     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:669 (15)
//         004ae6df     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae6e5     PUSH       EDI
//         004ae6e6     MOV        this,dword ptr [EAX + 0x5c]
//         004ae6e9     CALL       T_Scenario::GetSPPlayerID                        int GetSPPlayerID(T_Scenario * this, int para
//                              scr_sed2.cpp:672 (13)
//         004ae6ee     MOV        this,dword ptr [ESI + 0x740]
//         004ae6f4     DEC        EAX
//         004ae6f5     PUSH       EAX
//         004ae6f6     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:674 (15)
//         004ae6fb     MOV        this,dword ptr [ESI + 0x928]
//         004ae701     PUSH       EDI
//         004ae702     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae705     CALL       T_Scenario::GetSPObjectType                      int GetSPObjectType(T_Scenario * this, int pa
//                              scr_sed2.cpp:675 (12)
//         004ae70a     MOV        this,dword ptr [ESI + 0x738]
//         004ae710     PUSH       EAX
//         004ae711     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:676 (12)
//         004ae716     MOV        this,dword ptr [ESI + 0x738]
//         004ae71c     PUSH       EAX
//         004ae71d     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:678 (17)
//         004ae722     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae728     PUSH       EDI
//         004ae729     MOV        this,dword ptr [EDX + 0x5c]
//         004ae72c     CALL       T_Scenario::GetSPObject                          RGE_Static_Object * GetSPObject(T_Scenario *
//         004ae731     MOV        EBX,EAX
//                              scr_sed2.cpp:679 (19)
//         004ae733     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae739     PUSH       EDI
//         004ae73a     MOV        dword ptr [ESP + 0x14],EBX
//         004ae73e     MOV        this,dword ptr [EAX + 0x5c]
//         004ae741     CALL       T_Scenario::GetSPDestObjectID                    RGE_Static_Object * GetSPDestObjectID(T_Scena
//                              scr_sed2.cpp:683 (31)
//         004ae746     MOV        this,dword ptr [ESI + 0x928]
//         004ae74c     MOV        dword ptr [ESI + 0x480],EBX
//         004ae752     MOV        dword ptr [ESI + 0x484],EAX
//         004ae758     PUSH       EDI
//         004ae759     MOV        this,dword ptr [ECX + this->_padding_]
//         004ae75c     MOV        dword ptr [ESP + 0x30],EAX
//         004ae760     CALL       T_Scenario::GetSPVictoryType                     int GetSPVictoryType(T_Scenario * this, int p
//                              scr_sed2.cpp:684 (19)
//         004ae765     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae76b     PUSH       EDI
//         004ae76c     MOV        dword ptr [ESP + 0x28],EAX
//         004ae770     MOV        this,dword ptr [EDX + 0x5c]
//         004ae773     CALL       T_Scenario::GetSPAttribType                      int GetSPAttribType(T_Scenario * this, int pa
//                              scr_sed2.cpp:687 (47)
//         004ae778     LEA        EBP,[ESI + 0x494]
//         004ae77e     MOV        dword ptr [ESP + 0x5c],EAX
//         004ae782     LEA        EBX,[ESI + 0x490]
//         004ae788     LEA        EAX,[ESI + 0x48c]
//         004ae78e     PUSH       EBP
//         004ae78f     PUSH       EBX
//         004ae790     PUSH       EAX
//         004ae791     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae797     LEA        this,[ESI + 0x488]
//         004ae79d     PUSH       this
//         004ae79e     MOV        this,dword ptr [EAX + 0x5c]
//         004ae7a1     PUSH       EDI
//         004ae7a2     CALL       T_Scenario::GetSPRectangle                       void GetSPRectangle(T_Scenario * this, int pa
//                              scr_sed2.cpp:688 (49)
//         004ae7a7     FLD        float ptr [ESI + 0x488]
//         004ae7ad     CALL       __ftol                                           undefined __ftol()
//         004ae7b2     FLD        float ptr [ESI + 0x48c]
//         004ae7b8     MOV        dword ptr [ESP + 0x20],EAX
//         004ae7bc     CALL       __ftol                                           undefined __ftol()
//         004ae7c1     FLD        float ptr [EBX]
//         004ae7c3     MOV        dword ptr [ESP + 0x1c],EAX
//         004ae7c7     CALL       __ftol                                           undefined __ftol()
//         004ae7cc     FLD        float ptr [EBP]
//         004ae7cf     MOV        dword ptr [ESP + 0x18],EAX
//         004ae7d3     CALL       __ftol                                           undefined __ftol()
//                              scr_sed2.cpp:689 (23)
//         004ae7d8     MOV        this,dword ptr [ESI + 0x4c8]
//         004ae7de     PUSH       -0x1
//         004ae7e0     PUSH       -0x1
//         004ae7e2     PUSH       -0x1
//         004ae7e4     PUSH       -0x1
//         004ae7e6     MOV        dword ptr [ESP + 0x24],EAX
//         004ae7ea     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              scr_sed2.cpp:690 (15)
//         004ae7ef     FLD        float ptr [EBX]
//         004ae7f1     FCOMP      float ptr [DAT_00573af0]
//         004ae7f7     FNSTSW     AX
//         004ae7f9     TEST       AH,0x40
//         004ae7fc     JNZ        LAB_004ae81d
//                              scr_sed2.cpp:691 (31)
//         004ae7fe     MOV        this,dword ptr [ESP + 0x14]
//         004ae802     MOV        EDX,dword ptr [ESP + 0x18]
//         004ae806     MOV        EAX,dword ptr [ESP + 0x1c]
//         004ae80a     PUSH       this
//         004ae80b     MOV        this,dword ptr [ESP + 0x24]
//         004ae80f     PUSH       EDX
//         004ae810     PUSH       EAX
//         004ae811     PUSH       this
//         004ae812     MOV        this,dword ptr [ESI + 0x4c8]
//         004ae818     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                               LAB_004ae81d                                                 XREF[1]:     004ae7fc(j)
//                              scr_sed2.cpp:694 (20)
//         004ae81d     MOV        EAX,dword ptr [ESP + 0x24]
//         004ae821     CMP        EAX,0x7
//         004ae824     JA         switchD_004ae82a::default
//                               switchD_004ae82a::switchD
//         004ae82a     JMP        dword ptr [EAX*0x4 + switchD_004ae82a::switchd   = 004ae979
//                               switchD_004ae82a::caseD_4                                    XREF[2]:     004ae82a(j), 004ae9a0(*)
//                              scr_sed2.cpp:697 (20)
//         004ae831     MOV        EAX,dword ptr [ESP + 0x5c]
//         004ae835     CMP        EAX,0x6
//         004ae838     JA         switchD_004ae82a::default
//                               switchD_004ae83e::switchD
//         004ae83e     JMP        dword ptr [EAX*0x4 + switchD_004ae83e::switchd   = 004ae845
//                               switchD_004ae83e::caseD_0                                    XREF[2]:     004ae83e(j), 004ae9b0(*)
//                              scr_sed2.cpp:700 (2)
//         004ae845     PUSH       0xa
//                              scr_sed2.cpp:701 (5)
//         004ae847     JMP        LAB_004ae97b
//                               switchD_004ae83e::caseD_3                                    XREF[2]:     004ae83e(j), 004ae9bc(*)
//                              scr_sed2.cpp:704 (2)
//         004ae84c     PUSH       0xb
//                              scr_sed2.cpp:705 (5)
//         004ae84e     JMP        LAB_004ae97b
//                               switchD_004ae83e::caseD_1                                    XREF[2]:     004ae83e(j), 004ae9b4(*)
//                              scr_sed2.cpp:708 (2)
//         004ae853     PUSH       0xc
//                              scr_sed2.cpp:709 (5)
//         004ae855     JMP        LAB_004ae97b
//                               switchD_004ae83e::caseD_2                                    XREF[2]:     004ae83e(j), 004ae9b8(*)
//                              scr_sed2.cpp:712 (2)
//         004ae85a     PUSH       0xd
//                              scr_sed2.cpp:713 (5)
//         004ae85c     JMP        LAB_004ae97b
//                               switchD_004ae83e::caseD_4                                    XREF[2]:     004ae83e(j), 004ae9c0(*)
//                              scr_sed2.cpp:716 (2)
//         004ae861     PUSH       0xe
//                              scr_sed2.cpp:717 (5)
//         004ae863     JMP        LAB_004ae97b
//                               switchD_004ae83e::caseD_5                                    XREF[2]:     004ae83e(j), 004ae9c4(*)
//                              scr_sed2.cpp:720 (13)
//         004ae868     MOV        this,dword ptr [ESI + 0x734]
//         004ae86e     PUSH       0xf
//         004ae870     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:721 (23)
//         004ae875     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae87b     PUSH       EDI
//         004ae87c     MOV        this,dword ptr [EDX + 0x5c]
//         004ae87f     CALL       T_Scenario::GetSPAmount                          int GetSPAmount(T_Scenario * this, int param_1)
//         004ae884     MOV        this,dword ptr [ESI + 0x748]
//         004ae88a     DEC        EAX
//         004ae88b     PUSH       EAX
//                              scr_sed2.cpp:773 (5)
//         004ae88c     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:777 (10)
//         004ae891     POP        EDI
//         004ae892     POP        ESI
//         004ae893     POP        EBP
//         004ae894     POP        EBX
//         004ae895     ADD        ESP,0x48
//         004ae898     RET        0x4
//                               switchD_004ae83e::caseD_6                                    XREF[2]:     004ae83e(j), 004ae9c8(*)
//                              scr_sed2.cpp:725 (2)
//         004ae89b     PUSH       0x10
//                              scr_sed2.cpp:726 (5)
//         004ae89d     JMP        LAB_004ae97b
//                               switchD_004ae82a::caseD_6                                    XREF[2]:     004ae82a(j), 004ae9a8(*)
//                              scr_sed2.cpp:731 (13)
//         004ae8a2     MOV        this,dword ptr [ESI + 0x734]
//         004ae8a8     PUSH       0x11
//         004ae8aa     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:732 (16)
//         004ae8af     MOV        EAX,dword ptr [ESP + 0x5c]
//         004ae8b3     MOV        this,dword ptr [ESI + 0x744]
//         004ae8b9     PUSH       EAX
//         004ae8ba     CALL       TDropDownPanel::setCurrentLineId                 void setCurrentLineId(TDropDownPanel * this,
//                              scr_sed2.cpp:777 (10)
//         004ae8bf     POP        EDI
//         004ae8c0     POP        ESI
//         004ae8c1     POP        EBP
//         004ae8c2     POP        EBX
//         004ae8c3     ADD        ESP,0x48
//         004ae8c6     RET        0x4
//                               switchD_004ae82a::caseD_7                                    XREF[2]:     004ae82a(j), 004ae9ac(*)
//                              scr_sed2.cpp:737 (13)
//         004ae8c9     MOV        this,dword ptr [ESI + 0x734]
//         004ae8cf     PUSH       0x12
//         004ae8d1     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:738 (16)
//         004ae8d6     MOV        this,dword ptr [ESP + 0x5c]
//         004ae8da     PUSH       this
//         004ae8db     MOV        this,dword ptr [ESI + 0x74c]
//         004ae8e1     CALL       TDropDownPanel::setCurrentLineId                 void setCurrentLineId(TDropDownPanel * this,
//                              scr_sed2.cpp:777 (10)
//         004ae8e6     POP        EDI
//         004ae8e7     POP        ESI
//         004ae8e8     POP        EBP
//         004ae8e9     POP        EBX
//         004ae8ea     ADD        ESP,0x48
//         004ae8ed     RET        0x4
//                               switchD_004ae82a::caseD_5                                    XREF[2]:     004ae82a(j), 004ae9a4(*)
//                              scr_sed2.cpp:743 (14)
//         004ae8f0     MOV        EAX,dword ptr [ESP + 0x10]
//         004ae8f4     TEST       EAX,EAX
//         004ae8f6     JZ         switchD_004ae82a::default
//         004ae8fc     PUSH       0x9
//                              scr_sed2.cpp:744 (2)
//         004ae8fe     JMP        LAB_004ae97b
//                               switchD_004ae82a::caseD_1                                    XREF[2]:     004ae82a(j), 004ae994(*)
//                              scr_sed2.cpp:747 (8)
//         004ae900     MOV        EAX,dword ptr [ESP + 0x28]
//         004ae904     TEST       EAX,EAX
//         004ae906     JZ         LAB_004ae90c
//                              scr_sed2.cpp:748 (2)
//         004ae908     PUSH       0x5
//                              scr_sed2.cpp:749 (10)
//         004ae90a     JMP        LAB_004ae97b
//                               LAB_004ae90c                                                 XREF[1]:     004ae906(j)
//         004ae90c     MOV        EAX,dword ptr [ESP + 0x10]
//         004ae910     TEST       EAX,EAX
//         004ae912     JZ         LAB_004ae918
//                              scr_sed2.cpp:750 (2)
//         004ae914     PUSH       0x6
//                              scr_sed2.cpp:751 (21)
//         004ae916     JMP        LAB_004ae97b
//                               LAB_004ae918                                                 XREF[1]:     004ae912(j)
//         004ae918     MOV        EDX,dword ptr [ESI + 0x928]
//         004ae91e     PUSH       EDI
//         004ae91f     MOV        this,dword ptr [EDX + 0x5c]
//         004ae922     CALL       T_Scenario::GetSPAllFlag                         int GetSPAllFlag(T_Scenario * this, int param
//         004ae927     TEST       EAX,EAX
//         004ae929     JZ         LAB_004ae92f
//                              scr_sed2.cpp:752 (2)
//         004ae92b     PUSH       0x7
//                              scr_sed2.cpp:753 (2)
//         004ae92d     JMP        LAB_004ae97b
//                               LAB_004ae92f                                                 XREF[1]:     004ae929(j)
//                              scr_sed2.cpp:754 (2)
//         004ae92f     PUSH       0x8
//                              scr_sed2.cpp:755 (2)
//         004ae931     JMP        LAB_004ae97b
//                               switchD_004ae82a::caseD_2                                    XREF[2]:     004ae82a(j), 004ae998(*)
//                              scr_sed2.cpp:758 (31)
//         004ae933     PUSH       EBP
//         004ae934     LEA        EAX,[ESI + 0x48c]
//         004ae93a     PUSH       EBX
//         004ae93b     PUSH       EAX
//         004ae93c     LEA        EAX,[ESI + 0x488]
//         004ae942     PUSH       EAX
//         004ae943     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae949     PUSH       EDI
//         004ae94a     MOV        this,dword ptr [EAX + 0x5c]
//         004ae94d     CALL       T_Scenario::GetSPRectangle                       void GetSPRectangle(T_Scenario * this, int pa
//                              scr_sed2.cpp:759 (15)
//         004ae952     FLD        float ptr [EBX]
//         004ae954     FCOMP      double ptr [DAT_00573af8]
//         004ae95a     FNSTSW     AX
//         004ae95c     TEST       AH,0x41
//         004ae95f     JNZ        LAB_004ae965
//                              scr_sed2.cpp:760 (2)
//         004ae961     PUSH       0x4
//                              scr_sed2.cpp:761 (2)
//         004ae963     JMP        LAB_004ae97b
//                               LAB_004ae965                                                 XREF[1]:     004ae95f(j)
//                              scr_sed2.cpp:762 (2)
//         004ae965     PUSH       0x3
//                              scr_sed2.cpp:763 (2)
//         004ae967     JMP        LAB_004ae97b
//                               switchD_004ae82a::caseD_3                                    XREF[2]:     004ae82a(j), 004ae99c(*)
//                              scr_sed2.cpp:766 (8)
//         004ae969     MOV        EAX,dword ptr [ESP + 0x2c]
//         004ae96d     TEST       EAX,EAX
//         004ae96f     JZ         LAB_004ae975
//                              scr_sed2.cpp:767 (2)
//         004ae971     PUSH       0x1
//                              scr_sed2.cpp:768 (2)
//         004ae973     JMP        LAB_004ae97b
//                               LAB_004ae975                                                 XREF[1]:     004ae96f(j)
//                              scr_sed2.cpp:769 (2)
//         004ae975     PUSH       0x2
//                              scr_sed2.cpp:770 (2)
//         004ae977     JMP        LAB_004ae97b
//                               switchD_004ae82a::caseD_0                                    XREF[2]:     004ae82a(j), 004ae990(*)
//                              scr_sed2.cpp:773 (13)
//         004ae979     PUSH       0x0
//                               LAB_004ae97b                                                 XREF[15]:    004ae847(j), 004ae84e(j),
//                                                                                                         004ae855(j), 004ae85c(j),
//                                                                                                         004ae863(j), 004ae89d(j),
//                                                                                                         004ae8fe(j), 004ae90a(j),
//                                                                                                         004ae916(j), 004ae92d(j),
//                                                                                                         004ae931(j), 004ae963(j),
//                                                                                                         004ae967(j), 004ae973(j),
//                                                                                                         004ae977(j)
//         004ae97b     MOV        this,dword ptr [ESI + 0x734]
//         004ae981     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                               switchD_004ae83e::default                                    XREF[4]:     004ae675(j), 004ae824(j),
//                               switchD_004ae82a::default                                                 004ae838(j), 004ae8f6(j)
//                              scr_sed2.cpp:777 (70)
//         004ae986     POP        EDI
//         004ae987     POP        ESI
//         004ae988     POP        EBP
//         004ae989     POP        EBX
//         004ae98a     ADD        ESP,0x48
//         004ae98d     RET        0x4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004ae82a::switchdataD_004ae990                       XREF[1]:     load_victory_cond_from_scenario:00
//         004ae990     addr       switchD_004ae82a::caseD_0
//         004ae994     addr       switchD_004ae82a::caseD_1
//         004ae998     addr       switchD_004ae82a::caseD_2
//         004ae99c     addr       switchD_004ae82a::caseD_3
//         004ae9a0     addr       switchD_004ae82a::caseD_4
//         004ae9a4     addr       switchD_004ae82a::caseD_5
//         004ae9a8     addr       switchD_004ae82a::caseD_6
//         004ae9ac     addr       switchD_004ae82a::caseD_7
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004ae83e::switchdataD_004ae9b0                       XREF[1]:     load_victory_cond_from_scenario:00
//         004ae9b0     addr       switchD_004ae83e::caseD_0
//         004ae9b4     addr       switchD_004ae83e::caseD_1
//         004ae9b8     addr       switchD_004ae83e::caseD_2
//         004ae9bc     addr       switchD_004ae83e::caseD_3
//         004ae9c0     addr       switchD_004ae83e::caseD_4
//         004ae9c4     addr       switchD_004ae83e::caseD_5
//         004ae9c8     addr       switchD_004ae83e::caseD_6
//         004ae9cc     ??         90h
//         004ae9cd     ??         90h
//         004ae9ce     ??         90h
//         004ae9cf     ??         90h
    return;
}

void TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario() {
    /* TODO: Stub */
//                              void __thiscall load_multi_victory_cond_from_scenario(TRIBE_Screen_S
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              char[20]          Stack[-0x18]   str
//                               ?load_multi_victory_cond_from_scenario@TRIBE_Screen_Sed@@IA  XREF[1]:     set_scenario_mode:004aa1b7(c)
//                               TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario
//                              scr_sed2.cpp:785 (7)
//         004ae9d0     SUB        ESP,0x14
//         004ae9d3     PUSH       ESI
//         004ae9d4     MOV        ESI,this
//         004ae9d6     PUSH       EDI
//                              scr_sed2.cpp:789 (26)
//         004ae9d7     MOV        EAX,dword ptr [ESI + 0x928]
//         004ae9dd     MOV        this,dword ptr [EAX + 0x5c]
//         004ae9e0     CALL       T_Scenario::GetMPVictory                         int GetMPVictory(T_Scenario * this)
//         004ae9e5     CMP        EAX,0x3
//         004ae9e8     JA         switchD_004ae9ea::default
//                               switchD_004ae9ea::switchD
//         004ae9ea     JMP        dword ptr [EAX*0x4 + switchD_004ae9ea::switchd   = 004ae9f1
//                               switchD_004ae9ea::caseD_0                                    XREF[2]:     004ae9ea(j), 004aec98(*)
//                              scr_sed2.cpp:792 (10)
//         004ae9f1     MOV        dword ptr [ESI + 0x4ac],0x1
//                              scr_sed2.cpp:793 (2)
//         004ae9fb     JMP        LAB_004aea2b
//                               switchD_004ae9ea::caseD_1                                    XREF[2]:     004ae9ea(j), 004aec9c(*)
//                              scr_sed2.cpp:796 (10)
//         004ae9fd     MOV        dword ptr [ESI + 0x4ac],0x2
//                              scr_sed2.cpp:797 (2)
//         004aea07     JMP        LAB_004aea2b
//                               switchD_004ae9ea::caseD_2                                    XREF[2]:     004ae9ea(j), 004aeca0(*)
//                              scr_sed2.cpp:800 (10)
//         004aea09     MOV        dword ptr [ESI + 0x4ac],0x3
//                              scr_sed2.cpp:801 (2)
//         004aea13     JMP        LAB_004aea2b
//                               switchD_004ae9ea::caseD_3                                    XREF[2]:     004ae9ea(j), 004aeca4(*)
//                              scr_sed2.cpp:804 (10)
//         004aea15     MOV        dword ptr [ESI + 0x4ac],0x4
//                              scr_sed2.cpp:805 (2)
//         004aea1f     JMP        LAB_004aea2b
//                               switchD_004ae9ea::default                                    XREF[1]:     004ae9e8(j)
//                              scr_sed2.cpp:808 (10)
//         004aea21     MOV        dword ptr [ESI + 0x4ac],0x5
//                               LAB_004aea2b                                                 XREF[4]:     004ae9fb(j), 004aea07(j),
//                                                                                                         004aea13(j), 004aea1f(j)
//                              scr_sed2.cpp:812 (14)
//         004aea2b     MOV        this,dword ptr [ESI + 0x928]
//         004aea31     MOV        this,dword ptr [ECX + this->_padding_]
//         004aea34     CALL       T_Scenario::GetVictoryScore                      int GetVictoryScore(T_Scenario * this)
//                              scr_sed2.cpp:813 (4)
//         004aea39     TEST       EAX,EAX
//         004aea3b     JZ         LAB_004aea40
//                              scr_sed2.cpp:814 (1)
//         004aea3d     PUSH       EAX
//                              scr_sed2.cpp:815 (2)
//         004aea3e     JMP        LAB_004aea45
//                               LAB_004aea40                                                 XREF[1]:     004aea3b(j)
//                              scr_sed2.cpp:816 (28)
//         004aea40     PUSH       0x384
//                               LAB_004aea45                                                 XREF[1]:     004aea3e(j)
//         004aea45     MOV        this,dword ptr [ESI + 0x6f8]
//         004aea4b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004aea50     MOV        this,dword ptr [ESI + 0x6f8]
//         004aea56     PUSH       EAX
//         004aea57     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:818 (14)
//         004aea5c     MOV        EDX,dword ptr [ESI + 0x928]
//         004aea62     MOV        this,dword ptr [EDX + 0x5c]
//         004aea65     CALL       T_Scenario::GetVictoryTime                       int GetVictoryTime(T_Scenario * this)
//                              scr_sed2.cpp:819 (4)
//         004aea6a     TEST       EAX,EAX
//         004aea6c     JZ         LAB_004aea71
//                              scr_sed2.cpp:820 (1)
//         004aea6e     PUSH       EAX
//                              scr_sed2.cpp:821 (2)
//         004aea6f     JMP        LAB_004aea76
//                               LAB_004aea71                                                 XREF[1]:     004aea6c(j)
//                              scr_sed2.cpp:822 (28)
//         004aea71     PUSH       0x2328
//                               LAB_004aea76                                                 XREF[1]:     004aea6f(j)
//         004aea76     MOV        this,dword ptr [ESI + 0x700]
//         004aea7c     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004aea81     MOV        this,dword ptr [ESI + 0x700]
//         004aea87     PUSH       EAX
//         004aea88     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:824 (14)
//         004aea8d     MOV        EAX,dword ptr [ESI + 0x928]
//         004aea93     MOV        this,dword ptr [EAX + 0x5c]
//         004aea96     CALL       T_Scenario::Get_victory_all_flag                 int Get_victory_all_flag(T_Scenario * this)
//                              scr_sed2.cpp:825 (4)
//         004aea9b     TEST       EAX,EAX
//         004aea9d     JZ         LAB_004aeaa7
//                              scr_sed2.cpp:826 (6)
//         004aea9f     MOV        this,dword ptr [ESI + 0x684]
//                              scr_sed2.cpp:827 (2)
//         004aeaa5     JMP        LAB_004aeaad
//                               LAB_004aeaa7                                                 XREF[1]:     004aea9d(j)
//                              scr_sed2.cpp:828 (11)
//         004aeaa7     MOV        this,dword ptr [ESI + 0x680]
//                               LAB_004aeaad                                                 XREF[1]:     004aeaa5(j)
//         004aeaad     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              scr_sed2.cpp:830 (14)
//         004aeab2     MOV        this,dword ptr [ESI + 0x928]
//         004aeab8     MOV        this,dword ptr [ECX + this->_padding_]
//         004aeabb     CALL       T_Scenario::Get_Multi_Conquest                   int Get_Multi_Conquest(T_Scenario * this)
//                              scr_sed2.cpp:833 (20)
//         004aeac0     MOV        this,dword ptr [ESI + 0x668]
//         004aeac6     TEST       EAX,EAX
//         004aeac8     JZ         LAB_004aead6
//         004aeaca     MOV        EDX,dword ptr [this->_padding_]
//         004aeacc     PUSH       0x1
//         004aeace     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:837 (2)
//         004aead4     JMP        LAB_004aeae0
//                               LAB_004aead6                                                 XREF[1]:     004aeac8(j)
//                              scr_sed2.cpp:839 (10)
//         004aead6     MOV        EAX,dword ptr [this->_padding_]
//         004aead8     PUSH       0x0
//         004aeada     CALL       dword ptr [EAX + 0xe0]
//                               LAB_004aeae0                                                 XREF[1]:     004aead4(j)
//                              scr_sed2.cpp:843 (14)
//         004aeae0     MOV        this,dword ptr [ESI + 0x928]
//         004aeae6     MOV        this,dword ptr [ECX + this->_padding_]
//         004aeae9     CALL       T_Scenario::Get_Multi_Exploration                int Get_Multi_Exploration(T_Scenario * this)
//                              scr_sed2.cpp:846 (22)
//         004aeaee     MOV        this,dword ptr [ESI + 0x66c]
//         004aeaf4     MOV        EDI,EAX
//         004aeaf6     TEST       EDI,EDI
//         004aeaf8     MOV        EDX,dword ptr [this->_padding_]
//         004aeafa     JZ         LAB_004aeb1b
//         004aeafc     PUSH       0x1
//         004aeafe     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:847 (16)
//         004aeb04     LEA        EAX,[ESP + 0x8]
//         004aeb08     PUSH       0xa
//         004aeb0a     PUSH       EAX
//         004aeb0b     PUSH       EDI
//         004aeb0c     CALL       itoa                                             undefined itoa()
//         004aeb11     ADD        ESP,0xc
//                              scr_sed2.cpp:848 (5)
//         004aeb14     LEA        this,[ESP + 0x8]
//         004aeb18     PUSH       this
//                              scr_sed2.cpp:850 (2)
//         004aeb19     JMP        LAB_004aeb28
//                               LAB_004aeb1b                                                 XREF[1]:     004aeafa(j)
//                              scr_sed2.cpp:852 (8)
//         004aeb1b     PUSH       0x0
//         004aeb1d     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:853 (16)
//         004aeb23     PUSH       s_0                                              = "0"
//                               LAB_004aeb28                                                 XREF[1]:     004aeb19(j)
//         004aeb28     MOV        this,dword ptr [ESI + 0x6b8]
//         004aeb2e     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:856 (14)
//         004aeb33     MOV        EAX,dword ptr [ESI + 0x928]
//         004aeb39     MOV        this,dword ptr [EAX + 0x5c]
//         004aeb3c     CALL       T_Scenario::Get_Multi_Ruins                      int Get_Multi_Ruins(T_Scenario * this)
//                              scr_sed2.cpp:859 (22)
//         004aeb41     MOV        this,dword ptr [ESI + 0x670]
//         004aeb47     MOV        EDI,EAX
//         004aeb49     TEST       EDI,EDI
//         004aeb4b     MOV        EDX,dword ptr [this->_padding_]
//         004aeb4d     JZ         LAB_004aeb6e
//         004aeb4f     PUSH       0x1
//         004aeb51     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:860 (16)
//         004aeb57     LEA        EAX,[ESP + 0x8]
//         004aeb5b     PUSH       0xa
//         004aeb5d     PUSH       EAX
//         004aeb5e     PUSH       EDI
//         004aeb5f     CALL       itoa                                             undefined itoa()
//         004aeb64     ADD        ESP,0xc
//                              scr_sed2.cpp:861 (5)
//         004aeb67     LEA        this,[ESP + 0x8]
//         004aeb6b     PUSH       this
//                              scr_sed2.cpp:863 (2)
//         004aeb6c     JMP        LAB_004aeb7b
//                               LAB_004aeb6e                                                 XREF[1]:     004aeb4d(j)
//                              scr_sed2.cpp:865 (8)
//         004aeb6e     PUSH       0x0
//         004aeb70     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:866 (16)
//         004aeb76     PUSH       s_0                                              = "0"
//                               LAB_004aeb7b                                                 XREF[1]:     004aeb6c(j)
//         004aeb7b     MOV        this,dword ptr [ESI + 0x6bc]
//         004aeb81     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:869 (14)
//         004aeb86     MOV        EAX,dword ptr [ESI + 0x928]
//         004aeb8c     MOV        this,dword ptr [EAX + 0x5c]
//         004aeb8f     CALL       T_Scenario::Get_Multi_Artifacts                  int Get_Multi_Artifacts(T_Scenario * this)
//                              scr_sed2.cpp:872 (22)
//         004aeb94     MOV        this,dword ptr [ESI + 0x674]
//         004aeb9a     MOV        EDI,EAX
//         004aeb9c     TEST       EDI,EDI
//         004aeb9e     MOV        EDX,dword ptr [this->_padding_]
//         004aeba0     JZ         LAB_004aebc1
//         004aeba2     PUSH       0x1
//         004aeba4     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:873 (16)
//         004aebaa     LEA        EAX,[ESP + 0x8]
//         004aebae     PUSH       0xa
//         004aebb0     PUSH       EAX
//         004aebb1     PUSH       EDI
//         004aebb2     CALL       itoa                                             undefined itoa()
//         004aebb7     ADD        ESP,0xc
//                              scr_sed2.cpp:874 (5)
//         004aebba     LEA        this,[ESP + 0x8]
//         004aebbe     PUSH       this
//                              scr_sed2.cpp:876 (2)
//         004aebbf     JMP        LAB_004aebce
//                               LAB_004aebc1                                                 XREF[1]:     004aeba0(j)
//                              scr_sed2.cpp:878 (8)
//         004aebc1     PUSH       0x0
//         004aebc3     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:879 (16)
//         004aebc9     PUSH       s_0                                              = "0"
//                               LAB_004aebce                                                 XREF[1]:     004aebbf(j)
//         004aebce     MOV        this,dword ptr [ESI + 0x6c0]
//         004aebd4     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:882 (14)
//         004aebd9     MOV        EAX,dword ptr [ESI + 0x928]
//         004aebdf     MOV        this,dword ptr [EAX + 0x5c]
//         004aebe2     CALL       T_Scenario::Get_Multi_Discoveries                int Get_Multi_Discoveries(T_Scenario * this)
//                              scr_sed2.cpp:885 (22)
//         004aebe7     MOV        this,dword ptr [ESI + 0x678]
//         004aebed     MOV        EDI,EAX
//         004aebef     TEST       EDI,EDI
//         004aebf1     MOV        EDX,dword ptr [this->_padding_]
//         004aebf3     JZ         LAB_004aec14
//         004aebf5     PUSH       0x1
//         004aebf7     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:886 (16)
//         004aebfd     LEA        EAX,[ESP + 0x8]
//         004aec01     PUSH       0xa
//         004aec03     PUSH       EAX
//         004aec04     PUSH       EDI
//         004aec05     CALL       itoa                                             undefined itoa()
//         004aec0a     ADD        ESP,0xc
//                              scr_sed2.cpp:887 (5)
//         004aec0d     LEA        this,[ESP + 0x8]
//         004aec11     PUSH       this
//                              scr_sed2.cpp:889 (2)
//         004aec12     JMP        LAB_004aec21
//                               LAB_004aec14                                                 XREF[1]:     004aebf3(j)
//                              scr_sed2.cpp:891 (8)
//         004aec14     PUSH       0x0
//         004aec16     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:892 (16)
//         004aec1c     PUSH       s_0                                              = "0"
//                               LAB_004aec21                                                 XREF[1]:     004aec12(j)
//         004aec21     MOV        this,dword ptr [ESI + 0x6c4]
//         004aec27     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:895 (14)
//         004aec2c     MOV        EAX,dword ptr [ESI + 0x928]
//         004aec32     MOV        this,dword ptr [EAX + 0x5c]
//         004aec35     CALL       T_Scenario::Get_Multi_Gold                       int Get_Multi_Gold(T_Scenario * this)
//                              scr_sed2.cpp:898 (22)
//         004aec3a     MOV        this,dword ptr [ESI + 0x67c]
//         004aec40     MOV        EDI,EAX
//         004aec42     TEST       EDI,EDI
//         004aec44     MOV        EDX,dword ptr [this->_padding_]
//         004aec46     JZ         LAB_004aec67
//         004aec48     PUSH       0x1
//         004aec4a     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:899 (16)
//         004aec50     LEA        EAX,[ESP + 0x8]
//         004aec54     PUSH       0xa
//         004aec56     PUSH       EAX
//         004aec57     PUSH       EDI
//         004aec58     CALL       itoa                                             undefined itoa()
//         004aec5d     ADD        ESP,0xc
//                              scr_sed2.cpp:900 (5)
//         004aec60     LEA        this,[ESP + 0x8]
//         004aec64     PUSH       this
//                              scr_sed2.cpp:902 (2)
//         004aec65     JMP        LAB_004aec74
//                               LAB_004aec67                                                 XREF[1]:     004aec46(j)
//                              scr_sed2.cpp:904 (8)
//         004aec67     PUSH       0x0
//         004aec69     CALL       dword ptr [EDX + 0xe0]
//                              scr_sed2.cpp:905 (16)
//         004aec6f     PUSH       s_0                                              = "0"
//                               LAB_004aec74                                                 XREF[1]:     004aec65(j)
//         004aec74     MOV        this,dword ptr [ESI + 0x6c8]
//         004aec7a     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_sed2.cpp:908 (16)
//         004aec7f     MOV        EAX,dword ptr [ESI + 0x928]
//         004aec85     PUSH       0x1
//         004aec87     MOV        this,dword ptr [EAX + 0x5c]
//         004aec8a     CALL       T_Scenario::Save_victory_conditions_into_players void Save_victory_conditions_into_players(T_S
//                              scr_sed2.cpp:909 (25)
//         004aec8f     POP        EDI
//         004aec90     POP        ESI
//         004aec91     ADD        ESP,0x14
//         004aec94     RET
    return;
}

void TRIBE_Screen_Sed::save_diplomacy_in_scenario(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save_diplomacy_in_scenario(TRIBE_Screen_Sed * this,
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004aecb1(R)
//                               ?save_diplomacy_in_scenario@TRIBE_Screen_Sed@@IAEXH@Z        XREF[2]:     set_scenario_mode:004aa58e(c),
//                               TRIBE_Screen_Sed::save_diplomacy_in_scenario                              action:004acdf9(c)
//                              scr_sed2.cpp:913 (1)
//         004aecb0     PUSH       EBP
//                              scr_sed2.cpp:915 (17)
//         004aecb1     MOV        EBP,dword ptr [ESP + param_1]
//         004aecb5     PUSH       EDI
//         004aecb6     MOV        EDI,this
//         004aecb8     TEST       EBP,EBP
//         004aecba     JL         LAB_004aed46
//         004aecc0     PUSH       ESI
//         004aecc1     PUSH       EBX
//                              scr_sed2.cpp:917 (2)
//         004aecc2     XOR        ESI,ESI
//                              scr_sed2.cpp:940 (34)
//         004aecc4     LEA        EBX,[EDI + 0x8ac]
//                               LAB_004aecca                                                 XREF[1]:     004aed26(j)
//         004aecca     MOV        this,dword ptr [EBX + -0x4]
//         004aeccd     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004aecd2     CMP        EAX,0x1
//         004aecd5     JNZ        LAB_004aece6
//         004aecd7     MOV        EAX,dword ptr [EDI + 0x928]
//         004aecdd     PUSH       0x0
//         004aecdf     PUSH       ESI
//         004aece0     PUSH       EBP
//         004aece1     MOV        this,dword ptr [EAX + 0x5c]
//         004aece4     JMP        LAB_004aed1a
//                               LAB_004aece6                                                 XREF[1]:     004aecd5(j)
//                              scr_sed2.cpp:925 (7)
//         004aece6     MOV        this,dword ptr [EBX]
//         004aece8     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//                              scr_sed2.cpp:926 (5)
//         004aeced     CMP        EAX,0x1
//         004aecf0     JNZ        LAB_004aed00
//                              scr_sed2.cpp:928 (12)
//         004aecf2     MOV        this,dword ptr [EDI + 0x928]
//         004aecf8     PUSH       EAX
//         004aecf9     PUSH       ESI
//         004aecfa     PUSH       EBP
//         004aecfb     MOV        this,dword ptr [ECX + this->_padding_]
//                              scr_sed2.cpp:929 (2)
//         004aecfe     JMP        LAB_004aed1a
//                               LAB_004aed00                                                 XREF[1]:     004aecf0(j)
//                              scr_sed2.cpp:931 (8)
//         004aed00     MOV        this,dword ptr [EBX + 0x4]
//         004aed03     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//                              scr_sed2.cpp:932 (5)
//         004aed08     CMP        EAX,0x1
//         004aed0b     JNZ        LAB_004aed1f
//                              scr_sed2.cpp:934 (18)
//         004aed0d     MOV        EDX,dword ptr [EDI + 0x928]
//         004aed13     PUSH       0x3
//         004aed15     PUSH       ESI
//         004aed16     PUSH       EBP
//         004aed17     MOV        this,dword ptr [EDX + 0x5c]
//                               LAB_004aed1a                                                 XREF[2]:     004aece4(j), 004aecfe(j)
//         004aed1a     CALL       T_Scenario::Set_player_attitude                  void Set_player_attitude(T_Scenario * this, i
//                               LAB_004aed1f                                                 XREF[1]:     004aed0b(j)
//                              scr_sed2.cpp:917 (9)
//         004aed1f     INC        ESI
//         004aed20     ADD        EBX,0xc
//         004aed23     CMP        ESI,0x8
//         004aed26     JL         LAB_004aecca
//                              scr_sed2.cpp:938 (12)
//         004aed28     MOV        this,dword ptr [EDI + EBP*0x4 + 0x908]
//         004aed2f     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//                              scr_sed2.cpp:939 (18)
//         004aed34     PUSH       EAX
//         004aed35     MOV        EAX,dword ptr [EDI + 0x928]
//         004aed3b     PUSH       EBP
//         004aed3c     MOV        this,dword ptr [EAX + 0x5c]
//         004aed3f     CALL       T_Scenario::SetPlayerAlliedVictory               void SetPlayerAlliedVictory(T_Scenario * this
//         004aed44     POP        EBX
//         004aed45     POP        ESI
//                               LAB_004aed46                                                 XREF[1]:     004aecba(j)
//                              scr_sed2.cpp:940 (5)
//         004aed46     POP        EDI
//         004aed47     POP        EBP
//         004aed48     RET        0x4
//         004aed4b     ??         90h
//         004aed4c     NOP
//         004aed4d     NOP
//         004aed4e     NOP
//         004aed4f     NOP
    return;
}

void TRIBE_Screen_Sed::load_diplomacy_from_scenario(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load_diplomacy_from_scenario(TRIBE_Screen_Sed * this
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     004aed51(R), 004aed7f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004aed55(*)
//                               ?load_diplomacy_from_scenario@TRIBE_Screen_Sed@@IAEXH@Z      XREF[2]:     set_scenario_mode:004aa579(c),
//                               TRIBE_Screen_Sed::load_diplomacy_from_scenario                            action:004acde4(c)
//                              scr_sed2.cpp:944 (1)
//         004aed50     PUSH       this
//                              scr_sed2.cpp:947 (20)
//         004aed51     MOV        EAX,dword ptr [ESP + param_1]
//         004aed55     MOV        dword ptr [ESP]=>local_4,this
//         004aed59     TEST       EAX,EAX
//         004aed5b     JL         LAB_004aedff
//         004aed61     PUSH       EDI
//         004aed62     PUSH       ESI
//         004aed63     PUSH       EBP
//         004aed64     PUSH       EBX
//                              scr_sed2.cpp:950 (2)
//         004aed65     XOR        ESI,ESI
//                              scr_sed2.cpp:965 (18)
//         004aed67     LEA        EBX,[ECX + this->Diplomacy_AlliedVictory[0]]
//         004aed6d     LEA        EBP,[ECX + this+0x8ac]
//         004aed73     JMP        LAB_004aed79
//                               LAB_004aed75                                                 XREF[1]:     004aedcb(j)
//         004aed75     MOV        this,dword ptr [ESP + 0x10]
//                               LAB_004aed79                                                 XREF[1]:     004aed73(j)
//                              scr_sed2.cpp:952 (22)
//         004aed79     MOV        this,dword ptr [ECX + this->world]
//         004aed7f     MOV        EAX,dword ptr [ESP + param_1]
//         004aed83     PUSH       ESI
//         004aed84     PUSH       EAX=>DAT_fffffff8
//         004aed85     MOV        this,dword ptr [ECX + this->_padding_]
//         004aed88     CALL       T_Scenario::Get_player_attitude                  int Get_player_attitude(T_Scenario * this, in
//         004aed8d     MOV        EDI,EAX
//                              scr_sed2.cpp:954 (4)
//         004aed8f     TEST       EDI,EDI
//         004aed91     JNZ        LAB_004aed9b
//                              scr_sed2.cpp:955 (8)
//         004aed93     MOV        this,dword ptr [EBP + -0x4]
//         004aed96     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                               LAB_004aed9b                                                 XREF[1]:     004aed91(j)
//                              scr_sed2.cpp:956 (5)
//         004aed9b     CMP        EDI,0x1
//         004aed9e     JNZ        LAB_004aeda8
//                              scr_sed2.cpp:957 (8)
//         004aeda0     MOV        this,dword ptr [EBP]
//         004aeda3     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                               LAB_004aeda8                                                 XREF[1]:     004aed9e(j)
//                              scr_sed2.cpp:958 (5)
//         004aeda8     CMP        EDI,0x3
//         004aedab     JNZ        LAB_004aedb5
//                              scr_sed2.cpp:959 (8)
//         004aedad     MOV        this,dword ptr [EBP + 0x4]
//         004aedb0     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                               LAB_004aedb5                                                 XREF[1]:     004aedab(j)
//                              scr_sed2.cpp:961 (24)
//         004aedb5     MOV        this,dword ptr [EBX]
//         004aedb7     PUSH       0x0
//         004aedb9     MOV        EDX,dword ptr [this->_padding_]
//         004aedbb     CALL       dword ptr [EDX + 0xe0]
//         004aedc1     INC        ESI
//         004aedc2     ADD        EBX,0x4
//         004aedc5     ADD        EBP,0xc
//         004aedc8     CMP        ESI,0x8
//         004aedcb     JL         LAB_004aed75
//                              scr_sed2.cpp:964 (50)
//         004aedcd     MOV        ESI,dword ptr [ESP + 0x10]
//         004aedd1     MOV        EDI,dword ptr [ESP + 0x18]
//         004aedd5     PUSH       EDI
//         004aedd6     MOV        this,dword ptr [ESI + 0x928]
//         004aeddc     MOV        EAX,dword ptr [ESI + EDI*0x4 + 0x908]
//         004aede3     MOV        this,dword ptr [ECX + this->_padding_]
//         004aede6     MOV        EBX,dword ptr [EAX]
//         004aede8     CALL       T_Scenario::GetPlayerAlliedVictory               int GetPlayerAlliedVictory(T_Scenario * this,
//         004aeded     MOV        this,dword ptr [ESI + EDI*0x4 + 0x908]
//         004aedf4     PUSH       EAX
//         004aedf5     CALL       dword ptr [EBX + 0xe0]
//         004aedfb     POP        EBX
//         004aedfc     POP        EBP
//         004aedfd     POP        ESI
//         004aedfe     POP        EDI
//                               LAB_004aedff                                                 XREF[1]:     004aed5b(j)
//                              scr_sed2.cpp:965 (4)
//         004aedff     POP        this
//         004aee00     RET        0x4
//         004aee03     ??         90h
//         004aee04     NOP
//         004aee05     NOP
//         004aee06     NOP
//         004aee07     NOP
//         004aee08     NOP
//         004aee09     NOP
//         004aee0a     NOP
//         004aee0b     NOP
//         004aee0c     NOP
//         004aee0d     NOP
//         004aee0e     NOP
//         004aee0f     NOP
    return;
}

void TRIBE_Screen_Sed::activate_victory_proper_fields(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall activate_victory_proper_fields(TRIBE_Screen_Sed * th
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004aeec6(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004aee15(R)
//              TPanel *[2]       Stack[-0xc]:8  ptr
//                               ?activate_victory_proper_fields@TRIBE_Screen_Sed@@IAEXHH@Z   XREF[8]:     set_scenario_mode:004aa134(c),
//                               TRIBE_Screen_Sed::activate_victory_proper_fields                          set_scenario_mode:004aa15b(c),
//                                                                                                         action:004ac0c6(c),
//                                                                                                         action:004ac11d(c),
//                                                                                                         action:004ac153(c),
//                                                                                                         action:004ac3dd(c),
//                                                                                                         action:004ac40e(c),
//                                                                                                         action:004ac463(c)
//                              scr_sed2.cpp:971 (5)
//         004aee10     SUB        ESP,0x8
//         004aee13     PUSH       ESI
//         004aee14     PUSH       EDI
//                              scr_sed2.cpp:974 (24)
//         004aee15     MOV        EDI,dword ptr [ESP + param_2]
//         004aee19     MOV        ESI,this
//         004aee1b     TEST       EDI,EDI
//         004aee1d     MOV        dword ptr [ESI + 0x4a0],0x0
//         004aee27     JNZ        LAB_004aeeb9
//                              scr_sed2.cpp:976 (12)
//         004aee2d     MOV        this,dword ptr [ESI + 0x738]
//         004aee33     PUSH       EDI
//         004aee34     MOV        EAX,dword ptr [this->_padding_]
//         004aee36     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:977 (12)
//         004aee39     MOV        this,dword ptr [ESI + 0x764]
//         004aee3f     PUSH       EDI
//         004aee40     MOV        EDX,dword ptr [this->_padding_]
//         004aee42     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:978 (12)
//         004aee45     MOV        this,dword ptr [ESI + 0x76c]
//         004aee4b     PUSH       EDI
//         004aee4c     MOV        EAX,dword ptr [this->_padding_]
//         004aee4e     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:979 (12)
//         004aee51     MOV        this,dword ptr [ESI + 0x750]
//         004aee57     PUSH       EDI
//         004aee58     MOV        EDX,dword ptr [this->_padding_]
//         004aee5a     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:980 (12)
//         004aee5d     MOV        this,dword ptr [ESI + 0x754]
//         004aee63     PUSH       EDI
//         004aee64     MOV        EAX,dword ptr [this->_padding_]
//         004aee66     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:981 (12)
//         004aee69     MOV        this,dword ptr [ESI + 0x758]
//         004aee6f     PUSH       EDI
//         004aee70     MOV        EDX,dword ptr [this->_padding_]
//         004aee72     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:982 (12)
//         004aee75     MOV        this,dword ptr [ESI + 0x768]
//         004aee7b     PUSH       EDI
//         004aee7c     MOV        EAX,dword ptr [this->_padding_]
//         004aee7e     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:983 (12)
//         004aee81     MOV        this,dword ptr [ESI + 0x740]
//         004aee87     PUSH       EDI
//         004aee88     MOV        EDX,dword ptr [this->_padding_]
//         004aee8a     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:984 (12)
//         004aee8d     MOV        this,dword ptr [ESI + 0x744]
//         004aee93     PUSH       EDI
//         004aee94     MOV        EAX,dword ptr [this->_padding_]
//         004aee96     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:985 (12)
//         004aee99     MOV        this,dword ptr [ESI + 0x748]
//         004aee9f     PUSH       EDI
//         004aeea0     MOV        EDX,dword ptr [this->_padding_]
//         004aeea2     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:986 (9)
//         004aeea5     MOV        this,dword ptr [ESI + 0x74c]
//         004aeeab     PUSH       EDI
//         004aeeac     MOV        EAX,dword ptr [this->_padding_]
//                              scr_sed2.cpp:1134 (3)
//         004aeeae     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004aeeb1     POP        EDI
//         004aeeb2     POP        ESI
//         004aeeb3     ADD        ESP,0x8
//         004aeeb6     RET        0x8
//                               LAB_004aeeb9                                                 XREF[1]:     004aee27(j)
//                              scr_sed2.cpp:989 (13)
//         004aeeb9     MOV        this,dword ptr [ESI + 0x4d4]
//         004aeebf     PUSH       0x0
//         004aeec1     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:990 (20)
//         004aeec6     MOV        EAX,dword ptr [ESP + param_1]
//         004aeeca     CMP        EAX,0x12
//         004aeecd     JA         switchD_004aeed3::caseD_0
//                               switchD_004aeed3::switchD
//         004aeed3     JMP        dword ptr [EAX*0x4 + switchD_004aeed3::switchd   = 004af2ca
//                               switchD_004aeed3::caseD_1                                    XREF[2]:     004aeed3(j), 004af2d8(*)
//                              scr_sed2.cpp:995 (12)
//         004aeeda     MOV        this,dword ptr [ESI + 0x750]
//         004aeee0     PUSH       EDI
//         004aeee1     MOV        EDX,dword ptr [this->_padding_]
//         004aeee3     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:996 (6)
//         004aeee6     MOV        this,dword ptr [ESI + 0x754]
//                              scr_sed2.cpp:1134 (6)
//         004aeeec     PUSH       EDI
//         004aeeed     MOV        EAX,dword ptr [this->_padding_]
//         004aeeef     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004aeef2     POP        EDI
//         004aeef3     POP        ESI
//         004aeef4     ADD        ESP,0x8
//         004aeef7     RET        0x8
//                               switchD_004aeed3::caseD_2                                    XREF[2]:     004aeed3(j), 004af2dc(*)
//                              scr_sed2.cpp:1000 (12)
//         004aeefa     MOV        this,dword ptr [ESI + 0x750]
//         004aef00     PUSH       EDI
//         004aef01     MOV        EDX,dword ptr [this->_padding_]
//         004aef03     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1001 (12)
//         004aef06     MOV        this,dword ptr [ESI + 0x754]
//         004aef0c     PUSH       EDI
//         004aef0d     MOV        EAX,dword ptr [this->_padding_]
//         004aef0f     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1002 (12)
//         004aef12     MOV        this,dword ptr [ESI + 0x758]
//         004aef18     PUSH       EDI
//         004aef19     MOV        EDX,dword ptr [this->_padding_]
//         004aef1b     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004aef1e     POP        EDI
//         004aef1f     POP        ESI
//         004aef20     ADD        ESP,0x8
//         004aef23     RET        0x8
//                               switchD_004aeed3::caseD_3                                    XREF[2]:     004aeed3(j), 004af2e0(*)
//                              scr_sed2.cpp:1006 (12)
//         004aef26     MOV        this,dword ptr [ESI + 0x738]
//         004aef2c     PUSH       EDI
//         004aef2d     MOV        EAX,dword ptr [this->_padding_]
//         004aef2f     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1007 (12)
//         004aef32     MOV        this,dword ptr [ESI + 0x764]
//         004aef38     PUSH       EDI
//         004aef39     MOV        EDX,dword ptr [this->_padding_]
//         004aef3b     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1008 (12)
//         004aef3e     MOV        this,dword ptr [ESI + 0x76c]
//         004aef44     PUSH       EDI
//         004aef45     MOV        EAX,dword ptr [this->_padding_]
//         004aef47     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1009 (18)
//         004aef4a     MOV        this,dword ptr [ESI + 0x76c]
//         004aef50     PUSH       -0x1
//                              language.dll match for 0x7766: "Type the number of objects."
//         004aef52     PUSH       offset DAT_fffffff8
//         004aef57     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1011 (5)
//         004aef5c     JMP        LAB_004af254
//                               switchD_004aeed3::caseD_4                                    XREF[2]:     004aeed3(j), 004af2e4(*)
//                              scr_sed2.cpp:1014 (12)
//         004aef61     MOV        this,dword ptr [ESI + 0x738]
//         004aef67     PUSH       EDI
//         004aef68     MOV        EDX,dword ptr [this->_padding_]
//         004aef6a     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1015 (12)
//         004aef6d     MOV        this,dword ptr [ESI + 0x764]
//         004aef73     PUSH       EDI
//         004aef74     MOV        EAX,dword ptr [this->_padding_]
//         004aef76     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1016 (12)
//         004aef79     MOV        this,dword ptr [ESI + 0x76c]
//         004aef7f     PUSH       EDI
//         004aef80     MOV        EDX,dword ptr [this->_padding_]
//         004aef82     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1017 (18)
//         004aef85     MOV        this,dword ptr [ESI + 0x76c]
//         004aef8b     PUSH       -0x1
//                              language.dll match for 0x7767: "Type the number of objects."
//         004aef8d     PUSH       offset DAT_fffffff8
//         004aef92     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1018 (18)
//         004aef97     MOV        EAX,dword ptr [ESI + 0x76c]
//         004aef9d     MOV        this,dword ptr [ESI + 0x4d4]
//         004aefa3     PUSH       EAX
//         004aefa4     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1019 (12)
//         004aefa9     MOV        this,dword ptr [ESI + 0x754]
//         004aefaf     PUSH       EDI
//         004aefb0     MOV        EDX,dword ptr [this->_padding_]
//         004aefb2     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1020 (6)
//         004aefb5     MOV        this,dword ptr [ESI + 0x758]
//                              scr_sed2.cpp:1134 (6)
//         004aefbb     PUSH       EDI
//         004aefbc     MOV        EAX,dword ptr [this->_padding_]
//         004aefbe     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004aefc1     POP        EDI
//         004aefc2     POP        ESI
//         004aefc3     ADD        ESP,0x8
//         004aefc6     RET        0x8
//                               switchD_004aeed3::caseD_5                                    XREF[2]:     004aeed3(j), 004af2e8(*)
//                              scr_sed2.cpp:1024 (12)
//         004aefc9     MOV        this,dword ptr [ESI + 0x738]
//         004aefcf     PUSH       EDI
//         004aefd0     MOV        EDX,dword ptr [this->_padding_]
//         004aefd2     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1025 (12)
//         004aefd5     MOV        this,dword ptr [ESI + 0x764]
//         004aefdb     PUSH       EDI
//         004aefdc     MOV        EAX,dword ptr [this->_padding_]
//         004aefde     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1026 (12)
//         004aefe1     MOV        this,dword ptr [ESI + 0x76c]
//         004aefe7     PUSH       EDI
//         004aefe8     MOV        EDX,dword ptr [this->_padding_]
//         004aefea     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1027 (12)
//         004aefed     MOV        this,dword ptr [ESI + 0x768]
//         004aeff3     PUSH       EDI
//         004aeff4     MOV        EAX,dword ptr [this->_padding_]
//         004aeff6     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1028 (18)
//         004aeff9     MOV        this,dword ptr [ESI + 0x76c]
//         004aefff     PUSH       -0x1
//                              language.dll match for 0x7768: "Type the number of objects."
//         004af001     PUSH       offset DAT_fffffff8
//         004af006     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1029 (12)
//         004af00b     MOV        this,dword ptr [ESI + 0x740]
//         004af011     PUSH       EDI
//         004af012     MOV        EDX,dword ptr [this->_padding_]
//         004af014     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1033 (6)
//         004af017     MOV        EAX,dword ptr [ESI + 0x740]
//                              scr_sed2.cpp:1034 (6)
//         004af01d     MOV        this,dword ptr [ESI + 0x76c]
//                              scr_sed2.cpp:1035 (25)
//         004af023     MOV        EDX,dword ptr [ESI]
//         004af025     MOV        dword ptr [ESP + 0x8],EAX
//         004af029     LEA        EAX,[ESP + 0x8]
//         004af02d     MOV        dword ptr [ESP + 0xc],this
//         004af031     PUSH       0x2
//         004af033     PUSH       EAX=>DAT_fffffff8
//         004af034     MOV        this,ESI
//         004af036     CALL       dword ptr [EDX + 0xc8]
//                              scr_sed2.cpp:1050 (2)
//         004af03c     JMP        LAB_004af094
//                               switchD_004aeed3::caseD_7                                    XREF[2]:     004aeed3(j), 004af2f0(*)
//                              scr_sed2.cpp:1053 (12)
//         004af03e     MOV        this,dword ptr [ESI + 0x738]
//         004af044     PUSH       EDI
//         004af045     MOV        EAX,dword ptr [this->_padding_]
//         004af047     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1054 (12)
//         004af04a     MOV        this,dword ptr [ESI + 0x768]
//         004af050     PUSH       EDI
//         004af051     MOV        EDX,dword ptr [this->_padding_]
//         004af053     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1055 (12)
//         004af056     MOV        this,dword ptr [ESI + 0x740]
//         004af05c     PUSH       EDI
//         004af05d     MOV        EAX,dword ptr [this->_padding_]
//         004af05f     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1056 (18)
//         004af062     MOV        this,dword ptr [ESI + 0x740]
//         004af068     PUSH       this
//         004af069     MOV        this,dword ptr [ESI + 0x4d4]
//         004af06f     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af074     POP        EDI
//         004af075     POP        ESI
//         004af076     ADD        ESP,0x8
//         004af079     RET        0x8
//                               switchD_004aeed3::caseD_8                                    XREF[2]:     004aeed3(j), 004af2f4(*)
//                              scr_sed2.cpp:1060 (12)
//         004af07c     MOV        this,dword ptr [ESI + 0x768]
//         004af082     PUSH       EDI
//         004af083     MOV        EDX,dword ptr [this->_padding_]
//         004af085     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1061 (12)
//         004af088     MOV        this,dword ptr [ESI + 0x740]
//         004af08e     PUSH       EDI
//         004af08f     MOV        EAX,dword ptr [this->_padding_]
//         004af091     CALL       dword ptr [EAX + 0x14]
//                               LAB_004af094                                                 XREF[1]:     004af03c(j)
//                              scr_sed2.cpp:1062 (18)
//         004af094     MOV        this,dword ptr [ESI + 0x740]
//         004af09a     PUSH       this
//         004af09b     MOV        this,dword ptr [ESI + 0x4d4]
//         004af0a1     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af0a6     POP        EDI
//         004af0a7     POP        ESI
//         004af0a8     ADD        ESP,0x8
//         004af0ab     RET        0x8
//                               switchD_004aeed3::caseD_9                                    XREF[3]:     004aeed3(j), 004af2ec(*),
//                               switchD_004aeed3::caseD_6                                                 004af2f8(*)
//                              scr_sed2.cpp:1071 (12)
//         004af0ae     MOV        this,dword ptr [ESI + 0x750]
//         004af0b4     PUSH       EDI
//         004af0b5     MOV        EDX,dword ptr [this->_padding_]
//         004af0b7     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004af0ba     POP        EDI
//         004af0bb     POP        ESI
//         004af0bc     ADD        ESP,0x8
//         004af0bf     RET        0x8
//                               switchD_004aeed3::caseD_f                                    XREF[2]:     004aeed3(j), 004af310(*)
//                              scr_sed2.cpp:1083 (6)
//         004af0c2     MOV        this,dword ptr [ESI + 0x748]
//                              scr_sed2.cpp:1134 (6)
//         004af0c8     PUSH       EDI
//         004af0c9     MOV        EAX,dword ptr [this->_padding_]
//         004af0cb     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004af0ce     POP        EDI
//         004af0cf     POP        ESI
//         004af0d0     ADD        ESP,0x8
//         004af0d3     RET        0x8
//                               switchD_004aeed3::caseD_a                                    XREF[2]:     004aeed3(j), 004af2fc(*)
//                              scr_sed2.cpp:1087 (18)
//         004af0d6     MOV        this,dword ptr [ESI + 0x76c]
//         004af0dc     PUSH       -0x1
//                              language.dll match for 0x7769: "Type the quantity of gold."
//         004af0de     PUSH       0x7769
//         004af0e3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1088 (12)
//         004af0e8     MOV        this,dword ptr [ESI + 0x764]
//         004af0ee     PUSH       EDI
//         004af0ef     MOV        EDX,dword ptr [this->_padding_]
//         004af0f1     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1089 (12)
//         004af0f4     MOV        this,dword ptr [ESI + 0x76c]
//         004af0fa     PUSH       EDI
//         004af0fb     MOV        EAX,dword ptr [this->_padding_]
//         004af0fd     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1090 (18)
//         004af100     MOV        this,dword ptr [ESI + 0x76c]
//         004af106     PUSH       this
//         004af107     MOV        this,dword ptr [ESI + 0x4d4]
//         004af10d     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af112     POP        EDI
//         004af113     POP        ESI
//         004af114     ADD        ESP,0x8
//         004af117     RET        0x8
//                               switchD_004aeed3::caseD_b                                    XREF[2]:     004aeed3(j), 004af300(*)
//                              scr_sed2.cpp:1093 (18)
//         004af11a     MOV        this,dword ptr [ESI + 0x76c]
//         004af120     PUSH       -0x1
//                              language.dll match for 0x776a: "Type the quantity of food."
//         004af122     PUSH       0x776a
//         004af127     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1094 (12)
//         004af12c     MOV        this,dword ptr [ESI + 0x764]
//         004af132     PUSH       EDI
//         004af133     MOV        EDX,dword ptr [this->_padding_]
//         004af135     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1095 (12)
//         004af138     MOV        this,dword ptr [ESI + 0x76c]
//         004af13e     PUSH       EDI
//         004af13f     MOV        EAX,dword ptr [this->_padding_]
//         004af141     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1096 (18)
//         004af144     MOV        this,dword ptr [ESI + 0x76c]
//         004af14a     PUSH       this
//         004af14b     MOV        this,dword ptr [ESI + 0x4d4]
//         004af151     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af156     POP        EDI
//         004af157     POP        ESI
//         004af158     ADD        ESP,0x8
//         004af15b     RET        0x8
//                               switchD_004aeed3::caseD_c                                    XREF[2]:     004aeed3(j), 004af304(*)
//                              scr_sed2.cpp:1099 (18)
//         004af15e     MOV        this,dword ptr [ESI + 0x76c]
//         004af164     PUSH       -0x1
//                              language.dll match for 0x776b: "Type the quantity of wood."
//         004af166     PUSH       0x776b
//         004af16b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1100 (12)
//         004af170     MOV        this,dword ptr [ESI + 0x764]
//         004af176     PUSH       EDI
//         004af177     MOV        EDX,dword ptr [this->_padding_]
//         004af179     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1101 (12)
//         004af17c     MOV        this,dword ptr [ESI + 0x76c]
//         004af182     PUSH       EDI
//         004af183     MOV        EAX,dword ptr [this->_padding_]
//         004af185     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1102 (18)
//         004af188     MOV        this,dword ptr [ESI + 0x76c]
//         004af18e     PUSH       this
//         004af18f     MOV        this,dword ptr [ESI + 0x4d4]
//         004af195     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af19a     POP        EDI
//         004af19b     POP        ESI
//         004af19c     ADD        ESP,0x8
//         004af19f     RET        0x8
//                               switchD_004aeed3::caseD_d                                    XREF[2]:     004aeed3(j), 004af308(*)
//                              scr_sed2.cpp:1105 (18)
//         004af1a2     MOV        this,dword ptr [ESI + 0x76c]
//         004af1a8     PUSH       -0x1
//                              language.dll match for 0x776c: "Type the quantity of stone."
//         004af1aa     PUSH       0x776c
//         004af1af     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1106 (12)
//         004af1b4     MOV        this,dword ptr [ESI + 0x764]
//         004af1ba     PUSH       EDI
//         004af1bb     MOV        EDX,dword ptr [this->_padding_]
//         004af1bd     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1107 (12)
//         004af1c0     MOV        this,dword ptr [ESI + 0x76c]
//         004af1c6     PUSH       EDI
//         004af1c7     MOV        EAX,dword ptr [this->_padding_]
//         004af1c9     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1108 (18)
//         004af1cc     MOV        this,dword ptr [ESI + 0x76c]
//         004af1d2     PUSH       this
//         004af1d3     MOV        this,dword ptr [ESI + 0x4d4]
//         004af1d9     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af1de     POP        EDI
//         004af1df     POP        ESI
//         004af1e0     ADD        ESP,0x8
//         004af1e3     RET        0x8
//                               switchD_004aeed3::caseD_e                                    XREF[2]:     004aeed3(j), 004af30c(*)
//                              scr_sed2.cpp:1112 (18)
//         004af1e6     MOV        this,dword ptr [ESI + 0x76c]
//         004af1ec     PUSH       -0x1
//                              language.dll match for 0x776d: "Type the number of population
//         004af1ee     PUSH       0x776d
//         004af1f3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1113 (12)
//         004af1f8     MOV        this,dword ptr [ESI + 0x764]
//         004af1fe     PUSH       EDI
//         004af1ff     MOV        EDX,dword ptr [this->_padding_]
//         004af201     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1114 (12)
//         004af204     MOV        this,dword ptr [ESI + 0x76c]
//         004af20a     PUSH       EDI
//         004af20b     MOV        EAX,dword ptr [this->_padding_]
//         004af20d     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1115 (18)
//         004af210     MOV        this,dword ptr [ESI + 0x76c]
//         004af216     PUSH       this
//         004af217     MOV        this,dword ptr [ESI + 0x4d4]
//         004af21d     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af222     POP        EDI
//         004af223     POP        ESI
//         004af224     ADD        ESP,0x8
//         004af227     RET        0x8
//                               switchD_004aeed3::caseD_10                                   XREF[2]:     004aeed3(j), 004af314(*)
//                              scr_sed2.cpp:1119 (18)
//         004af22a     MOV        this,dword ptr [ESI + 0x76c]
//         004af230     PUSH       -0x1
//                              language.dll match for 0x776e: "Type the percentage of explor
//         004af232     PUSH       0x776e
//         004af237     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1120 (12)
//         004af23c     MOV        this,dword ptr [ESI + 0x764]
//         004af242     PUSH       EDI
//         004af243     MOV        EDX,dword ptr [this->_padding_]
//         004af245     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1121 (12)
//         004af248     MOV        this,dword ptr [ESI + 0x76c]
//         004af24e     PUSH       EDI
//         004af24f     MOV        EAX,dword ptr [this->_padding_]
//         004af251     CALL       dword ptr [EAX + 0x14]
//                               LAB_004af254                                                 XREF[1]:     004aef5c(j)
//                              scr_sed2.cpp:1122 (18)
//         004af254     MOV        this,dword ptr [ESI + 0x76c]
//         004af25a     PUSH       this
//         004af25b     MOV        this,dword ptr [ESI + 0x4d4]
//         004af261     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1138 (8)
//         004af266     POP        EDI
//         004af267     POP        ESI
//         004af268     ADD        ESP,0x8
//         004af26b     RET        0x8
//                               switchD_004aeed3::caseD_11                                   XREF[2]:     004aeed3(j), 004af318(*)
//                              scr_sed2.cpp:1126 (12)
//         004af26e     MOV        this,dword ptr [ESI + 0x764]
//         004af274     PUSH       EDI
//         004af275     MOV        EDX,dword ptr [this->_padding_]
//         004af277     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1127 (12)
//         004af27a     MOV        this,dword ptr [ESI + 0x76c]
//         004af280     PUSH       EDI
//         004af281     MOV        EAX,dword ptr [this->_padding_]
//         004af283     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1128 (18)
//         004af286     MOV        this,dword ptr [ESI + 0x76c]
//         004af28c     PUSH       -0x1
//                              language.dll match for 0x776f: "Type the quantity."
//         004af28e     PUSH       offset DAT_fffffff8
//         004af293     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1129 (18)
//         004af298     MOV        this,dword ptr [ESI + 0x76c]
//         004af29e     PUSH       this
//         004af29f     MOV        this,dword ptr [ESI + 0x4d4]
//         004af2a5     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_sed2.cpp:1130 (12)
//         004af2aa     MOV        this,dword ptr [ESI + 0x744]
//         004af2b0     PUSH       EDI
//         004af2b1     MOV        EDX,dword ptr [this->_padding_]
//         004af2b3     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1138 (8)
//         004af2b6     POP        EDI
//         004af2b7     POP        ESI
//         004af2b8     ADD        ESP,0x8
//         004af2bb     RET        0x8
//                               switchD_004aeed3::caseD_12                                   XREF[2]:     004aeed3(j), 004af31c(*)
//                              scr_sed2.cpp:1134 (12)
//         004af2be     MOV        this,dword ptr [ESI + 0x74c]
//         004af2c4     PUSH       EDI
//         004af2c5     MOV        EAX,dword ptr [this->_padding_]
//         004af2c7     CALL       dword ptr [EAX + 0x14]
//                               switchD_004aeed3::caseD_0                                    XREF[3]:     004aeecd(j), 004aeed3(j),
//                                                                                                         004af2d4(*)
//                              scr_sed2.cpp:1138 (86)
//         004af2ca     POP        EDI
//         004af2cb     POP        ESI
//         004af2cc     ADD        ESP,0x8
//         004af2cf     RET        0x8
    return;
}

void TRIBE_Screen_Sed::init_module_variables() {
    /* TODO: Stub */
//                              void __thiscall init_module_variables(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?init_module_variables@TRIBE_Screen_Sed@@IAEXXZ              XREF[1]:     TRIBE_Screen_Sed:004a8278(c)
//                               TRIBE_Screen_Sed::init_module_variables
//                              scr_sed2.cpp:1145 (3)
//         004af320     PUSH       ESI
//         004af321     MOV        EDX,this
//                              scr_sed2.cpp:1146 (9)
//         004af323     XOR        ESI,ESI
//         004af325     PUSH       EDI
//         004af326     MOV        dword ptr [EDX + 0x4c4],ESI
//                              scr_sed2.cpp:1148 (6)
//         004af32c     MOV        dword ptr [EDX + 0x4c8],ESI
//                              scr_sed2.cpp:1149 (6)
//         004af332     MOV        dword ptr [EDX + 0x4cc],ESI
//                              scr_sed2.cpp:1150 (6)
//         004af338     MOV        dword ptr [EDX + 0x4d0],ESI
//                              scr_sed2.cpp:1151 (12)
//         004af33e     MOV        dword ptr [EDX + 0x4d4],ESI
//         004af344     LEA        EDI,[EDX + 0x4d8]
//                              scr_sed2.cpp:1158 (15)
//         004af34a     MOV        this,0xa
//         004af34f     XOR        EAX,EAX
//         004af351     MOV        dword ptr [EDX + 0x47c],ESI
//         004af357     STOSD.REP  ES:EDI
//                              scr_sed2.cpp:1161 (6)
//         004af359     MOV        dword ptr [EDX + 0x500],ESI
//                              scr_sed2.cpp:1162 (6)
//         004af35f     MOV        dword ptr [EDX + 0x504],ESI
//                              scr_sed2.cpp:1165 (6)
//         004af365     MOV        dword ptr [EDX + 0x520],ESI
//                              scr_sed2.cpp:1350 (850)
//         004af36b     LEA        EAX,[EDX + 0x514]
//         004af371     MOV        this,0x3
//                               LAB_004af376                                                 XREF[1]:     004af37f(j)
//         004af376     MOV        dword ptr [EAX + -0xc],ESI
//         004af379     MOV        dword ptr [EAX],ESI
//         004af37b     ADD        EAX,0x4
//         004af37e     DEC        this
//         004af37f     JNZ        LAB_004af376
//         004af381     MOV        dword ptr [EDX + 0x528],ESI
//         004af387     MOV        dword ptr [EDX + 0x524],ESI
//         004af38d     MOV        dword ptr [EDX + 0x530],ESI
//         004af393     MOV        dword ptr [EDX + 0x52c],ESI
//         004af399     MOV        dword ptr [EDX + 0x538],ESI
//         004af39f     MOV        dword ptr [EDX + 0x534],ESI
//         004af3a5     MOV        dword ptr [EDX + 0x550],ESI
//         004af3ab     MOV        dword ptr [EDX + 0x53c],ESI
//         004af3b1     MOV        dword ptr [EDX + 0x540],ESI
//         004af3b7     MOV        dword ptr [EDX + 0x544],ESI
//         004af3bd     MOV        dword ptr [EDX + 0x548],ESI
//         004af3c3     MOV        dword ptr [EDX + 0x54c],ESI
//         004af3c9     MOV        dword ptr [EDX + 0x554],ESI
//         004af3cf     MOV        dword ptr [EDX + 0x580],ESI
//         004af3d5     MOV        dword ptr [EDX + 0x59c],ESI
//         004af3db     LEA        EAX,[EDX + 0x56c]
//         004af3e1     MOV        this,0x5
//                               LAB_004af3e6                                                 XREF[1]:     004af3ef(j)
//         004af3e6     MOV        dword ptr [EAX + -0x14],ESI
//         004af3e9     MOV        dword ptr [EAX],ESI
//         004af3eb     ADD        EAX,0x4
//         004af3ee     DEC        this
//         004af3ef     JNZ        LAB_004af3e6
//         004af3f1     LEA        EAX,[EDX + 0x590]
//         004af3f7     MOV        this,0x3
//                               LAB_004af3fc                                                 XREF[1]:     004af405(j)
//         004af3fc     MOV        dword ptr [EAX + -0xc],ESI
//         004af3ff     MOV        dword ptr [EAX],ESI
//         004af401     ADD        EAX,0x4
//         004af404     DEC        this
//         004af405     JNZ        LAB_004af3fc
//         004af407     MOV        dword ptr [EDX + 0x5a0],ESI
//         004af40d     MOV        dword ptr [EDX + 0x5a4],ESI
//         004af413     MOV        dword ptr [EDX + 0x5a8],ESI
//         004af419     MOV        dword ptr [EDX + 0x5ac],ESI
//         004af41f     MOV        dword ptr [EDX + 0x5bc],ESI
//         004af425     MOV        dword ptr [EDX + 0x5b0],ESI
//         004af42b     MOV        dword ptr [EDX + 0x5f4],ESI
//         004af431     MOV        dword ptr [EDX + 0x60c],ESI
//         004af437     MOV        dword ptr [EDX + 0x610],ESI
//         004af43d     MOV        dword ptr [EDX + 0x5b4],ESI
//         004af443     MOV        dword ptr [EDX + 0x5b8],ESI
//         004af449     LEA        EAX,[EDX + 0x5d8]
//         004af44f     MOV        this,0x5
//                               LAB_004af454                                                 XREF[1]:     004af45d(j)
//         004af454     MOV        dword ptr [EAX + -0x14],ESI
//         004af457     MOV        dword ptr [EAX],ESI
//         004af459     ADD        EAX,0x4
//         004af45c     DEC        this
//         004af45d     JNZ        LAB_004af454
//         004af45f     LEA        EAX,[EDX + 0x5f8]
//         004af465     MOV        this,0x2
//                               LAB_004af46a                                                 XREF[1]:     004af473(j)
//         004af46a     MOV        dword ptr [EAX + -0xc],ESI
//         004af46d     MOV        dword ptr [EAX],ESI
//         004af46f     ADD        EAX,0x4
//         004af472     DEC        this
//         004af473     JNZ        LAB_004af46a
//         004af475     MOV        dword ptr [EDX + 0x600],ESI
//         004af47b     MOV        dword ptr [EDX + 0x604],ESI
//         004af481     MOV        dword ptr [EDX + 0x608],ESI
//         004af487     MOV        dword ptr [EDX + 0x618],ESI
//         004af48d     LEA        EAX,[EDX + 0x62c]
//         004af493     MOV        this,0x4
//                               LAB_004af498                                                 XREF[1]:     004af4a1(j)
//         004af498     MOV        dword ptr [EAX + -0x10],ESI
//         004af49b     MOV        dword ptr [EAX],ESI
//         004af49d     ADD        EAX,0x4
//         004af4a0     DEC        this
//         004af4a1     JNZ        LAB_004af498
//         004af4a3     MOV        dword ptr [EDX + 0x63c],ESI
//         004af4a9     MOV        dword ptr [EDX + 0x640],ESI
//         004af4af     MOV        dword ptr [EDX + 0x644],ESI
//         004af4b5     XOR        EAX,EAX
//         004af4b7     MOV        dword ptr [EDX + 0x648],ESI
//         004af4bd     MOV        dword ptr [EDX + 0x64c],EAX
//         004af4c3     MOV        dword ptr [EDX + 0x650],EAX
//         004af4c9     LEA        EDI,[EDX + 0x668]
//         004af4cf     MOV        dword ptr [EDX + 0x654],EAX
//         004af4d5     MOV        this,0x6
//         004af4da     MOV        dword ptr [EDX + 0x658],EAX
//         004af4e0     MOV        dword ptr [EDX + 0x65c],EAX
//         004af4e6     MOV        dword ptr [EDX + 0x660],ESI
//         004af4ec     MOV        word ptr [EDX + 0x664],SI
//         004af4f3     STOSD.REP  ES:EDI
//         004af4f5     LEA        EAX,[EDX + 0x694]
//         004af4fb     MOV        this,0x2
//                               LAB_004af500                                                 XREF[1]:     004af509(j)
//         004af500     MOV        dword ptr [EAX + -0x14],ESI
//         004af503     MOV        dword ptr [EAX],ESI
//         004af505     ADD        EAX,0x4
//         004af508     DEC        this
//         004af509     JNZ        LAB_004af500
//         004af50b     MOV        dword ptr [EDX + 0x68c],ESI
//         004af511     MOV        dword ptr [EDX + 0x690],ESI
//         004af517     MOV        dword ptr [EDX + 0x688],ESI
//         004af51d     MOV        dword ptr [EDX + 0x69c],ESI
//         004af523     MOV        dword ptr [EDX + 0x6a0],ESI
//         004af529     MOV        dword ptr [EDX + 0x6a4],ESI
//         004af52f     MOV        dword ptr [EDX + 0x6a8],ESI
//         004af535     MOV        dword ptr [EDX + 0x6ac],ESI
//         004af53b     MOV        dword ptr [EDX + 0x6b0],ESI
//         004af541     MOV        dword ptr [EDX + 0x6b4],ESI
//         004af547     MOV        dword ptr [EDX + 0x6b8],ESI
//         004af54d     MOV        dword ptr [EDX + 0x6bc],ESI
//         004af553     MOV        dword ptr [EDX + 0x6c0],ESI
//         004af559     MOV        dword ptr [EDX + 0x6c4],ESI
//         004af55f     MOV        dword ptr [EDX + 0x6c8],ESI
//         004af565     LEA        EAX,[EDX + 0x6e0]
//         004af56b     MOV        this,0x5
//                               LAB_004af570                                                 XREF[1]:     004af579(j)
//         004af570     MOV        dword ptr [EAX + -0x14],ESI
//         004af573     MOV        dword ptr [EAX],ESI
//         004af575     ADD        EAX,0x4
//         004af578     DEC        this
//         004af579     JNZ        LAB_004af570
//         004af57b     LEA        EDI,[EDX + 0x704]
//         004af581     MOV        this,0xc
//         004af586     XOR        EAX,EAX
//         004af588     MOV        dword ptr [EDX + 0x6f4],ESI
//         004af58e     MOV        dword ptr [EDX + 0x6f8],ESI
//         004af594     MOV        dword ptr [EDX + 0x6fc],ESI
//         004af59a     MOV        dword ptr [EDX + 0x700],ESI
//         004af5a0     STOSD.REP  ES:EDI
//         004af5a2     MOV        dword ptr [EDX + 0x734],ESI
//         004af5a8     MOV        dword ptr [EDX + 0x738],ESI
//         004af5ae     MOV        dword ptr [EDX + 0x73c],ESI
//         004af5b4     MOV        dword ptr [EDX + 0x748],ESI
//         004af5ba     MOV        dword ptr [EDX + 0x74c],ESI
//         004af5c0     MOV        dword ptr [EDX + 0x750],ESI
//         004af5c6     MOV        dword ptr [EDX + 0x754],ESI
//         004af5cc     MOV        dword ptr [EDX + 0x758],ESI
//         004af5d2     MOV        dword ptr [EDX + 0x75c],ESI
//         004af5d8     MOV        dword ptr [EDX + 0x760],ESI
//         004af5de     MOV        dword ptr [EDX + 0x764],ESI
//         004af5e4     MOV        dword ptr [EDX + 0x76c],ESI
//         004af5ea     MOV        dword ptr [EDX + 0x740],ESI
//         004af5f0     MOV        dword ptr [EDX + 0x744],ESI
//         004af5f6     MOV        dword ptr [EDX + 0x768],ESI
//         004af5fc     MOV        dword ptr [EDX + 0x770],ESI
//         004af602     LEA        EAX,[EDX + 0x78c]
//         004af608     MOV        this,0x5
//                               LAB_004af60d                                                 XREF[1]:     004af616(j)
//         004af60d     MOV        dword ptr [EAX + -0x14],ESI
//         004af610     MOV        dword ptr [EAX],ESI
//         004af612     ADD        EAX,0x4
//         004af615     DEC        this
//         004af616     JNZ        LAB_004af60d
//         004af618     MOV        dword ptr [EDX + 0x774],ESI
//         004af61e     LEA        EAX,[EDX + 0x7b4]
//         004af624     MOV        this,0x4
//                               LAB_004af629                                                 XREF[1]:     004af632(j)
//         004af629     MOV        dword ptr [EAX + -0x10],ESI
//         004af62c     MOV        dword ptr [EAX],ESI
//         004af62e     ADD        EAX,0x4
//         004af631     DEC        this
//         004af632     JNZ        LAB_004af629
//         004af634     LEA        EAX,[EDX + 0x7c8]
//         004af63a     MOV        this,0x1
//                               LAB_004af63f                                                 XREF[1]:     004af648(j)
//         004af63f     MOV        dword ptr [EAX + -0x4],ESI
//         004af642     MOV        dword ptr [EAX],ESI
//         004af644     ADD        EAX,0x4
//         004af647     DEC        this
//         004af648     JNZ        LAB_004af63f
//         004af64a     MOV        dword ptr [EDX + 0x7cc],ESI
//         004af650     MOV        dword ptr [EDX + 0x7d0],ESI
//         004af656     LEA        EAX,[EDX + 0x814]
//         004af65c     MOV        this,0x10
//                               LAB_004af661                                                 XREF[1]:     004af66a(j)
//         004af661     MOV        dword ptr [EAX + -0x40],ESI
//         004af664     MOV        dword ptr [EAX],ESI
//         004af666     ADD        EAX,0x4
//         004af669     DEC        this
//         004af66a     JNZ        LAB_004af661
//         004af66c     MOV        dword ptr [EDX + 0x894],ESI
//         004af672     LEA        this,[EDX + 0x908]
//         004af678     LEA        EAX,[EDX + 0x8ac]
//         004af67e     MOV        EDI,0x8
//                               LAB_004af683                                                 XREF[1]:     004af69a(j)
//         004af683     MOV        dword ptr [this->_padding_ + 0xffffff6c],ESI
//         004af689     MOV        dword ptr [EAX + -0x4],ESI
//         004af68c     MOV        dword ptr [EAX],ESI
//         004af68e     MOV        dword ptr [EAX + 0x4],ESI
//         004af691     MOV        dword ptr [this->_padding_],ESI
//         004af693     ADD        this,0x4
//         004af696     ADD        EAX,0xc
//         004af699     DEC        EDI
//         004af69a     JNZ        LAB_004af683
//         004af69c     MOV        dword ptr [EDX + 0x898],ESI
//         004af6a2     MOV        dword ptr [EDX + 0x89c],ESI
//         004af6a8     MOV        dword ptr [EDX + 0x8a0],ESI
//         004af6ae     MOV        dword ptr [EDX + 0x8a4],ESI
//         004af6b4     MOV        dword ptr [EDX + 0x928],ESI
//         004af6ba     POP        EDI
//         004af6bb     POP        ESI
//         004af6bc     RET
//         004af6bd     ??         90h
//         004af6be     NOP
//         004af6bf     NOP
    return;
}

void TRIBE_Screen_Sed::create_all_buttons_etc() {
    /* TODO: Stub */
//                              void __thiscall create_all_buttons_etc(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b1a29(R)
//              char[140]         Stack[-0x9c]   str2
//              char[100]         Stack[-0x100   str
//              char[140]         Stack[-0x18c   str1
//              char[20]          Stack[-0x1a0   str3
//              char[20]          Stack[-0x1b4   str4
//              TPanel *[4]       Stack[-0x1c4   ptr
//              int               Stack[-0x1cc   i
//                               ?create_all_buttons_etc@TRIBE_Screen_Sed@@IAEXXZ             XREF[1]:     TRIBE_Screen_Sed:004a85c8(c)
//                               TRIBE_Screen_Sed::create_all_buttons_etc
//                              scr_sed2.cpp:1353 (33)
//         004af6c0     MOV        EAX,FS:[0x0]
//         004af6c6     PUSH       -0x1
//         004af6c8     PUSH       FUN_0055f54a
//         004af6cd     PUSH       EAX
//         004af6ce     MOV        dword ptr FS:[0x0],ESP
//         004af6d5     SUB        ESP,0x1bc
//         004af6db     PUSH       EBX
//         004af6dc     PUSH       EBP
//         004af6dd     PUSH       ESI
//         004af6de     MOV        ESI,this
//         004af6e0     PUSH       EDI
//                              scr_sed2.cpp:1363 (28)
//         004af6e1     PUSH       0x1
//         004af6e3     LEA        EBP,[ESI + 0x4d8]
//                              language.dll match for 0x271a: "Map"
//         004af6e9     PUSH       0x271a
//         004af6ee     PUSH       EBP
//         004af6ef     PUSH       ESI
//         004af6f0     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af6f5     TEST       EAX,EAX
//         004af6f7     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1364 (15)
//         004af6fd     MOV        this,dword ptr [EBP]
//         004af700     PUSH       -0x1
//                              language.dll match for 0x76c0: "Click to create randomly gene
//         004af702     PUSH       0x76c0
//         004af707     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1365 (30)
//         004af70c     LEA        EDI,[ESI + 0x4dc]
//         004af712     PUSH       0x1
//                              language.dll match for 0x271b: "Terrain"
//         004af714     PUSH       0x271b
//         004af719     PUSH       EDI
//         004af71a     PUSH       ESI
//         004af71b     MOV        this,ESI
//         004af71d     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af722     TEST       EAX,EAX
//         004af724     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1366 (14)
//         004af72a     MOV        this,dword ptr [EDI]
//         004af72c     PUSH       -0x1
//                              language.dll match for 0x76c1: "Click to place resources, ele
//         004af72e     PUSH       0x76c1
//         004af733     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1367 (30)
//         004af738     LEA        EDI,[ESI + 0x4e0]
//         004af73e     PUSH       0x1
//                              language.dll match for 0x271c: "Players"
//         004af740     PUSH       0x271c
//         004af745     PUSH       EDI
//         004af746     PUSH       ESI
//         004af747     MOV        this,ESI
//         004af749     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af74e     TEST       EAX,EAX
//         004af750     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1368 (14)
//         004af756     MOV        this,dword ptr [EDI]
//         004af758     PUSH       -0x1
//                              language.dll match for 0x76c2: "Click to choose the starting
//         004af75a     PUSH       0x76c2
//         004af75f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1369 (30)
//         004af764     LEA        EDI,[ESI + 0x4e4]
//         004af76a     PUSH       0x1
//                              language.dll match for 0x271d: "Units"
//         004af76c     PUSH       0x271d
//         004af771     PUSH       EDI
//         004af772     PUSH       ESI
//         004af773     MOV        this,ESI
//         004af775     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af77a     TEST       EAX,EAX
//         004af77c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1370 (14)
//         004af782     MOV        this,dword ptr [EDI]
//         004af784     PUSH       -0x1
//                              language.dll match for 0x76c3: "Click to place buildings, vil
//         004af786     PUSH       0x76c3
//         004af78b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1371 (30)
//         004af790     LEA        EDI,[ESI + 0x4e8]
//         004af796     PUSH       0x1
//                              language.dll match for 0x2722: "Diplomacy"
//         004af798     PUSH       0x2722
//         004af79d     PUSH       EDI
//         004af79e     PUSH       ESI
//         004af79f     MOV        this,ESI
//         004af7a1     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af7a6     TEST       EAX,EAX
//         004af7a8     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1372 (14)
//         004af7ae     MOV        this,dword ptr [EDI]
//         004af7b0     PUSH       -0x1
//                              language.dll match for 0x76c8: "Click to choose the diplomati
//         004af7b2     PUSH       0x76c8
//         004af7b7     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1373 (30)
//         004af7bc     LEA        EDI,[ESI + 0x4ec]
//         004af7c2     PUSH       0x1
//                              language.dll match for 0x271e: "Individual Victory"
//         004af7c4     PUSH       0x271e
//         004af7c9     PUSH       EDI
//         004af7ca     PUSH       ESI
//         004af7cb     MOV        this,ESI
//         004af7cd     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af7d2     TEST       EAX,EAX
//         004af7d4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1374 (14)
//         004af7da     MOV        this,dword ptr [EDI]
//         004af7dc     PUSH       -0x1
//                              language.dll match for 0x76c4: "Click to choose unique victor
//         004af7de     PUSH       0x76c4
//         004af7e3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1375 (30)
//         004af7e8     LEA        EDI,[ESI + 0x4f0]
//         004af7ee     PUSH       0x1
//                              language.dll match for 0x2723: "Global Victory"
//         004af7f0     PUSH       0x2723
//         004af7f5     PUSH       EDI
//         004af7f6     PUSH       ESI
//         004af7f7     MOV        this,ESI
//         004af7f9     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af7fe     TEST       EAX,EAX
//         004af800     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1376 (14)
//         004af806     MOV        this,dword ptr [EDI]
//         004af808     PUSH       -0x1
//                              language.dll match for 0x76c9: "Click to select one or more v
//         004af80a     PUSH       0x76c9
//         004af80f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1377 (30)
//         004af814     LEA        EDI,[ESI + 0x4f4]
//         004af81a     PUSH       0x1
//                              language.dll match for 0x2721: "Options"
//         004af81c     PUSH       0x2721
//         004af821     PUSH       EDI
//         004af822     PUSH       ESI
//         004af823     MOV        this,ESI
//         004af825     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af82a     TEST       EAX,EAX
//         004af82c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1378 (14)
//         004af832     MOV        this,dword ptr [EDI]
//         004af834     PUSH       -0x1
//                              language.dll match for 0x76c7: "Click to enable the full tech
//         004af836     PUSH       0x76c7
//         004af83b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1379 (30)
//         004af840     LEA        EDI,[ESI + 0x4f8]
//         004af846     PUSH       0x1
//                              language.dll match for 0x271f: "Messages"
//         004af848     PUSH       0x271f
//         004af84d     PUSH       EDI
//         004af84e     PUSH       ESI
//         004af84f     MOV        this,ESI
//         004af851     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af856     TEST       EAX,EAX
//         004af858     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1380 (14)
//         004af85e     MOV        this,dword ptr [EDI]
//         004af860     PUSH       -0x1
//                              language.dll match for 0x76c5: "Click to write scenario instr
//         004af862     PUSH       0x76c5
//         004af867     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1381 (30)
//         004af86c     LEA        EDI,[ESI + 0x4fc]
//         004af872     PUSH       0x1
//                              language.dll match for 0x2720: "Cinematics"
//         004af874     PUSH       0x2720
//         004af879     PUSH       EDI
//         004af87a     PUSH       ESI
//         004af87b     MOV        this,ESI
//         004af87d     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af882     TEST       EAX,EAX
//         004af884     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1382 (21)
//         004af88a     MOV        this,dword ptr [EDI]
//         004af88c     PUSH       -0x1
//                              language.dll match for 0x76c6: "Click to choose the cinematic
//         004af88e     PUSH       0x76c6
//         004af893     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004af898     MOV        EDI,EBP
//         004af89a     MOV        EBX,0xa
//                               LAB_004af89f                                                 XREF[1]:     004af8b6(j)
//                              scr_sed2.cpp:1389 (10)
//         004af89f     MOV        this,dword ptr [EDI]
//         004af8a1     PUSH       0xa
//         004af8a3     PUSH       EBP=>DAT_fffffff8
//         004af8a4     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              scr_sed2.cpp:1390 (15)
//         004af8a9     MOV        this,dword ptr [EDI]
//         004af8ab     PUSH       0x1
//         004af8ad     MOV        EAX,dword ptr [this->_padding_]
//         004af8af     CALL       dword ptr [EAX + 0x14]
//         004af8b2     ADD        EDI,0x4
//         004af8b5     DEC        EBX
//         004af8b6     JNZ        LAB_004af89f
//                              scr_sed2.cpp:1396 (30)
//         004af8b8     LEA        EDI,[ESI + 0x500]
//         004af8be     PUSH       0x0
//                              language.dll match for 0x2724: "Menu"
//         004af8c0     PUSH       offset DAT_fffffff8
//         004af8c5     PUSH       EDI=>DAT_fffffff4
//         004af8c6     PUSH       ESI=>DAT_fffffff0
//         004af8c7     MOV        this,ESI
//         004af8c9     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af8ce     TEST       EAX,EAX
//         004af8d0     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1397 (14)
//         004af8d6     MOV        this,dword ptr [EDI]
//         004af8d8     PUSH       -0x1
//                              language.dll match for 0x774c: "Click to display the menu."
//         004af8da     PUSH       offset DAT_fffffff8
//         004af8df     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1398 (9)
//         004af8e4     MOV        this,dword ptr [EDI]
//         004af8e6     PUSH       0x1
//         004af8e8     MOV        EDX,dword ptr [this->_padding_]
//         004af8ea     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1399 (30)
//         004af8ed     LEA        EDI,[ESI + 0x504]
//         004af8f3     PUSH       0x0
//                              language.dll match for 0xfa9: "?"
//         004af8f5     PUSH       offset DAT_fffffff8
//         004af8fa     PUSH       EDI=>DAT_fffffff4
//         004af8fb     PUSH       ESI=>DAT_fffffff0
//         004af8fc     MOV        this,ESI
//         004af8fe     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004af903     TEST       EAX,EAX
//         004af905     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1400 (11)
//         004af90b     MOV        EDI,dword ptr [EDI]
//         004af90d     PUSH       0x1
//         004af90f     MOV        this,EDI
//         004af911     MOV        EAX,dword ptr [EDI]
//         004af913     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:1406 (34)
//         004af916     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004af91c     LEA        this,[ESI + 0x520]
//                              language.dll match for 0x29a6: "Map"
//         004af922     PUSH       0x29a6
//         004af927     PUSH       this=>DAT_fffffff8
//         004af928     PUSH       EDX=>DAT_fffffff4
//         004af929     MOV        this,ESI
//         004af92b     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004af930     TEST       EAX,EAX
//         004af932     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1408 (29)
//         004af938     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004af93e     LEA        EBP,[ESI + 0x508]
//         004af944     PUSH       EBP
//         004af945     PUSH       EAX=>DAT_fffffff8
//         004af946     MOV        this,ESI
//         004af948     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004af94d     TEST       EAX,EAX
//         004af94f     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1409 (15)
//         004af955     MOV        this,dword ptr [EBP]
//         004af958     PUSH       -0x1
//                              language.dll match for 0x76cf: "Click to display the default
//         004af95a     PUSH       offset DAT_fffffff8
//         004af95f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1410 (29)
//         004af964     MOV        this,dword ptr [ESI + 0x4d4]
//         004af96a     LEA        EDI,[ESI + 0x50c]
//         004af970     PUSH       EDI
//         004af971     PUSH       this=>DAT_fffffff8
//         004af972     MOV        this,ESI
//         004af974     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004af979     TEST       EAX,EAX
//         004af97b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1411 (14)
//         004af981     MOV        this,dword ptr [EDI]
//         004af983     PUSH       -0x1
//                              language.dll match for 0x76d0: "Click to display a random dis
//         004af985     PUSH       offset DAT_fffffff8
//         004af98a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1412 (29)
//         004af98f     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004af995     LEA        EDI,[ESI + 0x510]
//         004af99b     PUSH       EDI
//         004af99c     PUSH       EDX=>DAT_fffffff8
//         004af99d     MOV        this,ESI
//         004af99f     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004af9a4     TEST       EAX,EAX
//         004af9a6     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1413 (14)
//         004af9ac     MOV        this,dword ptr [EDI]
//         004af9ae     PUSH       -0x1
//                              language.dll match for 0x76d1: "Click to display a random dis
//         004af9b0     PUSH       offset DAT_fffffff8
//         004af9b5     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1415 (34)
//         004af9ba     MOV        this,dword ptr [ESI + 0x4d4]
//         004af9c0     LEA        EAX,[ESI + 0x514]
//                              language.dll match for 0x299c: "Blank Map"
//         004af9c6     PUSH       0x299c
//         004af9cb     PUSH       EAX=>DAT_fffffff8
//         004af9cc     PUSH       this=>DAT_fffffff4
//         004af9cd     MOV        this,ESI
//         004af9cf     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004af9d4     TEST       EAX,EAX
//         004af9d6     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1416 (34)
//         004af9dc     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004af9e2     LEA        EDX,[ESI + 0x518]
//                              language.dll match for 0x299d: "Random Map"
//         004af9e8     PUSH       0x299d
//         004af9ed     PUSH       EDX=>DAT_fffffff8
//         004af9ee     PUSH       EAX=>DAT_fffffff4
//         004af9ef     MOV        this,ESI
//         004af9f1     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004af9f6     TEST       EAX,EAX
//         004af9f8     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1417 (34)
//         004af9fe     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afa04     LEA        this,[ESI + 0x51c]
//                              language.dll match for 0x299e: "Seed Map"
//         004afa0a     PUSH       0x299e
//         004afa0f     PUSH       this=>DAT_fffffff8
//         004afa10     PUSH       EDX=>DAT_fffffff4
//         004afa11     MOV        this,ESI
//         004afa13     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afa18     TEST       EAX,EAX
//         004afa1a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1419 (34)
//         004afa20     MOV        this,dword ptr [ESI + 0x4d4]
//         004afa26     LEA        EAX,[ESI + 0x524]
//                              language.dll match for 0x299f: "Default Terrain"
//         004afa2c     PUSH       0x299f
//         004afa31     PUSH       EAX=>DAT_fffffff8
//         004afa32     PUSH       this=>DAT_fffffff4
//         004afa33     MOV        this,ESI
//         004afa35     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afa3a     TEST       EAX,EAX
//         004afa3c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1420 (29)
//         004afa42     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afa48     LEA        EDI,[ESI + 0x528]
//         004afa4e     PUSH       EDI
//         004afa4f     PUSH       EDX=>DAT_fffffff8
//         004afa50     MOV        this,ESI
//         004afa52     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004afa57     TEST       EAX,EAX
//         004afa59     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1421 (14)
//         004afa5f     MOV        this,dword ptr [EDI]
//         004afa61     PUSH       -0x1
//                              language.dll match for 0x76d6: "Click to set the default terr
//         004afa63     PUSH       offset DAT_fffffff8
//         004afa68     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1423 (67)
//         004afa6d     PUSH       0x0
//         004afa6f     PUSH       offset DAT_fffffff8
//         004afa71     PUSH       offset DAT_fffffff4
//         004afa73     PUSH       offset DAT_fffffff0
//         004afa75     MOV        this,ESI
//         004afa77     LEA        EDI,[ESI + 0x550]
//         004afa7d     CALL       TPanel::height                                   long height(TPanel * this)
//         004afa82     SUB        EAX,0xc8
//         004afa87     MOV        this,ESI
//         004afa89     PUSH       EAX
//         004afa8a     CALL       TPanel::width                                    long width(TPanel * this)
//         004afa8f     PUSH       EAX
//         004afa90     MOV        EAX,dword ptr [ESI + 0x4c8]
//         004afa96     PUSH       0x0
//         004afa98     PUSH       0x0
//                              language.dll match for 0x29a5: "GENERATING MAP"
//         004afa9a     PUSH       0x29a5
//         004afa9f     PUSH       EDI
//         004afaa0     PUSH       EAX
//         004afaa1     MOV        this,ESI
//         004afaa3     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004afaa8     TEST       EAX,EAX
//         004afaaa     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1424 (11)
//         004afab0     MOV        EDI,dword ptr [EDI]
//         004afab2     PUSH       0x0
//         004afab4     MOV        this,EDI
//         004afab6     MOV        EDX,dword ptr [EDI]
//         004afab8     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1426 (34)
//         004afabb     MOV        this,dword ptr [ESI + 0x4d4]
//         004afac1     LEA        EAX,[ESI + 0x52c]
//                              language.dll match for 0x29a0: "Map Size"
//         004afac7     PUSH       0x29a0
//         004afacc     PUSH       EAX=>DAT_fffffff8
//         004afacd     PUSH       this=>DAT_fffffff4
//         004aface     MOV        this,ESI
//         004afad0     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afad5     TEST       EAX,EAX
//         004afad7     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1427 (29)
//         004afadd     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afae3     LEA        EDI,[ESI + 0x530]
//         004afae9     PUSH       EDI
//         004afaea     PUSH       EDX=>DAT_fffffff8
//         004afaeb     MOV        this,ESI
//         004afaed     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004afaf2     TEST       EAX,EAX
//         004afaf4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1428 (14)
//         004afafa     MOV        this,dword ptr [EDI]
//         004afafc     PUSH       -0x1
//                              language.dll match for 0x76d2: "Select the map size. The larg
//         004afafe     PUSH       offset DAT_fffffff8
//         004afb03     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1430 (34)
//         004afb08     MOV        this,dword ptr [ESI + 0x4d4]
//         004afb0e     LEA        EAX,[ESI + 0x534]
//                              language.dll match for 0x29a1: "Map Type"
//         004afb14     PUSH       0x29a1
//         004afb19     PUSH       EAX=>DAT_fffffff8
//         004afb1a     PUSH       this=>DAT_fffffff4
//         004afb1b     MOV        this,ESI
//         004afb1d     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afb22     TEST       EAX,EAX
//         004afb24     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1431 (29)
//         004afb2a     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afb30     LEA        EDI,[ESI + 0x538]
//         004afb36     PUSH       EDI
//         004afb37     PUSH       EDX=>DAT_fffffff8
//         004afb38     MOV        this,ESI
//         004afb3a     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004afb3f     TEST       EAX,EAX
//         004afb41     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1432 (14)
//         004afb47     MOV        this,dword ptr [EDI]
//         004afb49     PUSH       -0x1
//                              language.dll match for 0x76d3: "Select the distribution of la
//         004afb4b     PUSH       offset DAT_fffffff8
//         004afb50     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1434 (34)
//         004afb55     MOV        this,dword ptr [ESI + 0x4d4]
//         004afb5b     LEA        EAX,[ESI + 0x53c]
//                              language.dll match for 0x29a2: "Seed"
//         004afb61     PUSH       0x29a2
//         004afb66     PUSH       EAX=>DAT_fffffff8
//         004afb67     PUSH       this=>DAT_fffffff4
//         004afb68     MOV        this,ESI
//         004afb6a     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afb6f     TEST       EAX,EAX
//         004afb71     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1435 (42)
//         004afb77     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afb7d     PUSH       0x0
//         004afb7f     PUSH       0x0=>DAT_fffffff8
//         004afb81     PUSH       offset DAT_fffffff4
//         004afb83     LEA        EDI,[ESI + 0x540]
//         004afb89     PUSH       offset DAT_fffffff0
//         004afb8b     PUSH       s_0                                              = "0"
//         004afb90     PUSH       EDI
//         004afb91     PUSH       EDX
//         004afb92     MOV        this,ESI
//         004afb94     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004afb99     TEST       EAX,EAX
//         004afb9b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1436 (14)
//         004afba1     MOV        this,dword ptr [EDI]
//         004afba3     PUSH       -0x1
//                              language.dll match for 0x76d4: "Type the number of the seed m
//         004afba5     PUSH       offset DAT_fffffff8
//         004afbaa     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1438 (34)
//         004afbaf     MOV        this,dword ptr [ESI + 0x4d4]
//         004afbb5     LEA        EAX,[ESI + 0x544]
//                              language.dll match for 0x29a3: "Seed"
//         004afbbb     PUSH       0x29a3
//         004afbc0     PUSH       EAX=>DAT_fffffff8
//         004afbc1     PUSH       this=>DAT_fffffff4
//         004afbc2     MOV        this,ESI
//         004afbc4     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afbc9     TEST       EAX,EAX
//         004afbcb     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1439 (34)
//         004afbd1     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afbd7     LEA        EDX,[ESI + 0x548]
//         004afbdd     PUSH       s_0                                              = "0"
//         004afbe2     PUSH       EDX=>DAT_fffffff8
//         004afbe3     PUSH       EAX=>DAT_fffffff4
//         004afbe4     MOV        this,ESI
//         004afbe6     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afbeb     TEST       EAX,EAX
//         004afbed     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1441 (36)
//         004afbf3     MOV        this,dword ptr [ESI + 0x4d4]
//         004afbf9     LEA        EDI,[ESI + 0x54c]
//         004afbff     PUSH       0x0
//                              language.dll match for 0x29a4: "Generate Map"
//         004afc01     PUSH       offset DAT_fffffff8
//         004afc06     PUSH       EDI=>DAT_fffffff4
//         004afc07     PUSH       this=>DAT_fffffff0
//         004afc08     MOV        this,ESI
//         004afc0a     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004afc0f     TEST       EAX,EAX
//         004afc11     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1442 (21)
//         004afc17     MOV        this,dword ptr [EDI]
//         004afc19     PUSH       -0x1
//                              language.dll match for 0x76d5: "Click to create the map."
//         004afc1b     PUSH       offset DAT_fffffff8
//         004afc20     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004afc25     MOV        EDI,EBP
//         004afc27     MOV        EBX,0x3
//                               LAB_004afc2c                                                 XREF[1]:     004afc3a(j)
//                              scr_sed2.cpp:1446 (16)
//         004afc2c     MOV        this,dword ptr [EDI]
//         004afc2e     PUSH       0x3
//         004afc30     PUSH       EBP=>DAT_fffffff8
//         004afc31     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004afc36     ADD        EDI,0x4
//         004afc39     DEC        EBX
//         004afc3a     JNZ        LAB_004afc2c
//                              scr_sed2.cpp:1451 (34)
//         004afc3c     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afc42     LEA        EDX,[ESI + 0x554]
//                              language.dll match for 0x29af: "Brush Size"
//         004afc48     PUSH       0x29af
//         004afc4d     PUSH       EDX=>DAT_fffffff8
//         004afc4e     PUSH       EAX=>DAT_fffffff4
//         004afc4f     MOV        this,ESI
//         004afc51     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afc56     TEST       EAX,EAX
//         004afc58     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1452 (34)
//         004afc5e     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afc64     LEA        this,[ESI + 0x59c]
//                              language.dll match for 0x29bc: "Terrain"
//         004afc6a     PUSH       0x29bc
//         004afc6f     PUSH       this=>DAT_fffffff8
//         004afc70     PUSH       EDX=>DAT_fffffff4
//         004afc71     MOV        this,ESI
//         004afc73     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afc78     TEST       EAX,EAX
//         004afc7a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1453 (29)
//         004afc80     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afc86     LEA        EBP,[ESI + 0x558]
//         004afc8c     PUSH       EBP
//         004afc8d     PUSH       EAX=>DAT_fffffff8
//         004afc8e     MOV        this,ESI
//         004afc90     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afc95     TEST       EAX,EAX
//         004afc97     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1454 (15)
//         004afc9d     MOV        this,dword ptr [EBP]
//         004afca0     PUSH       -0x1
//                              language.dll match for 0x76d9: "Click to select the brush siz
//         004afca2     PUSH       offset DAT_fffffff8
//         004afca7     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1455 (29)
//         004afcac     MOV        this,dword ptr [ESI + 0x4d4]
//         004afcb2     LEA        EDI,[ESI + 0x55c]
//         004afcb8     PUSH       EDI
//         004afcb9     PUSH       this=>DAT_fffffff8
//         004afcba     MOV        this,ESI
//         004afcbc     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afcc1     TEST       EAX,EAX
//         004afcc3     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1456 (14)
//         004afcc9     MOV        this,dword ptr [EDI]
//         004afccb     PUSH       -0x1
//                              language.dll match for 0x76da: "Click to select the brush siz
//         004afccd     PUSH       offset DAT_fffffff8
//         004afcd2     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1457 (29)
//         004afcd7     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afcdd     LEA        EDI,[ESI + 0x560]
//         004afce3     PUSH       EDI
//         004afce4     PUSH       EDX=>DAT_fffffff8
//         004afce5     MOV        this,ESI
//         004afce7     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afcec     TEST       EAX,EAX
//         004afcee     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1458 (14)
//         004afcf4     MOV        this,dword ptr [EDI]
//         004afcf6     PUSH       -0x1
//                              language.dll match for 0x76db: "Click to select the brush siz
//         004afcf8     PUSH       offset DAT_fffffff8
//         004afcfd     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1459 (29)
//         004afd02     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afd08     LEA        EDI,[ESI + 0x564]
//         004afd0e     PUSH       EDI
//         004afd0f     PUSH       EAX=>DAT_fffffff8
//         004afd10     MOV        this,ESI
//         004afd12     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afd17     TEST       EAX,EAX
//         004afd19     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1460 (14)
//         004afd1f     MOV        this,dword ptr [EDI]
//         004afd21     PUSH       -0x1
//                              language.dll match for 0x76dc: "Click to select the brush siz
//         004afd23     PUSH       offset DAT_fffffff8
//         004afd28     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1461 (29)
//         004afd2d     MOV        this,dword ptr [ESI + 0x4d4]
//         004afd33     LEA        EDI,[ESI + 0x568]
//         004afd39     PUSH       EDI
//         004afd3a     PUSH       this=>DAT_fffffff8
//         004afd3b     MOV        this,ESI
//         004afd3d     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afd42     TEST       EAX,EAX
//         004afd44     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1462 (14)
//         004afd4a     MOV        this,dword ptr [EDI]
//         004afd4c     PUSH       -0x1
//                              language.dll match for 0x76dd: "Click to select the brush siz
//         004afd4e     PUSH       offset DAT_fffffff8
//         004afd53     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1463 (34)
//         004afd58     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afd5e     LEA        EDX,[ESI + 0x56c]
//                              language.dll match for 0x29b0: "Tiny"
//         004afd64     PUSH       0x29b0
//         004afd69     PUSH       EDX=>DAT_fffffff8
//         004afd6a     PUSH       EAX=>DAT_fffffff4
//         004afd6b     MOV        this,ESI
//         004afd6d     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afd72     TEST       EAX,EAX
//         004afd74     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1464 (34)
//         004afd7a     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afd80     LEA        this,[ESI + 0x570]
//                              language.dll match for 0x29b1: "Small"
//         004afd86     PUSH       0x29b1
//         004afd8b     PUSH       this=>DAT_fffffff8
//         004afd8c     PUSH       EDX=>DAT_fffffff4
//         004afd8d     MOV        this,ESI
//         004afd8f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afd94     TEST       EAX,EAX
//         004afd96     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1465 (34)
//         004afd9c     MOV        this,dword ptr [ESI + 0x4d4]
//         004afda2     LEA        EAX,[ESI + 0x574]
//                              language.dll match for 0x29b2: "Medium"
//         004afda8     PUSH       0x29b2
//         004afdad     PUSH       EAX=>DAT_fffffff8
//         004afdae     PUSH       this=>DAT_fffffff4
//         004afdaf     MOV        this,ESI
//         004afdb1     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afdb6     TEST       EAX,EAX
//         004afdb8     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1466 (34)
//         004afdbe     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afdc4     LEA        EDX,[ESI + 0x578]
//                              language.dll match for 0x29b3: "Large"
//         004afdca     PUSH       0x29b3
//         004afdcf     PUSH       EDX=>DAT_fffffff8
//         004afdd0     PUSH       EAX=>DAT_fffffff4
//         004afdd1     MOV        this,ESI
//         004afdd3     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afdd8     TEST       EAX,EAX
//         004afdda     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1467 (34)
//         004afde0     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afde6     LEA        this,[ESI + 0x57c]
//                              language.dll match for 0x29b4: "Huge"
//         004afdec     PUSH       0x29b4
//         004afdf1     PUSH       this=>DAT_fffffff8
//         004afdf2     PUSH       EDX=>DAT_fffffff4
//         004afdf3     MOV        this,ESI
//         004afdf5     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afdfa     TEST       EAX,EAX
//         004afdfc     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1469 (34)
//         004afe02     MOV        this,dword ptr [ESI + 0x4d4]
//         004afe08     LEA        EAX,[ESI + 0x580]
//                              language.dll match for 0x29b9: "Brush Type"
//         004afe0e     PUSH       0x29b9
//         004afe13     PUSH       EAX=>DAT_fffffff8
//         004afe14     PUSH       this=>DAT_fffffff4
//         004afe15     MOV        this,ESI
//         004afe17     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afe1c     TEST       EAX,EAX
//         004afe1e     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1470 (29)
//         004afe24     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afe2a     LEA        EDI,[ESI + 0x584]
//         004afe30     PUSH       EDI
//         004afe31     PUSH       EDX=>DAT_fffffff8
//         004afe32     MOV        this,ESI
//         004afe34     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afe39     TEST       EAX,EAX
//         004afe3b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1471 (14)
//         004afe41     MOV        this,dword ptr [EDI]
//         004afe43     PUSH       -0x1
//                              language.dll match for 0x76de: "Click to paint background ter
//         004afe45     PUSH       offset DAT_fffffff8
//         004afe4a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1472 (29)
//         004afe4f     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afe55     LEA        EDI,[ESI + 0x588]
//         004afe5b     PUSH       EDI
//         004afe5c     PUSH       EAX=>DAT_fffffff8
//         004afe5d     MOV        this,ESI
//         004afe5f     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afe64     TEST       EAX,EAX
//         004afe66     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1473 (14)
//         004afe6c     MOV        this,dword ptr [EDI]
//         004afe6e     PUSH       -0x1
//                              language.dll match for 0x76df: "Click to paint hills."
//         004afe70     PUSH       offset DAT_fffffff8
//         004afe75     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1474 (29)
//         004afe7a     MOV        this,dword ptr [ESI + 0x4d4]
//         004afe80     LEA        EDI,[ESI + 0x58c]
//         004afe86     PUSH       EDI
//         004afe87     PUSH       this=>DAT_fffffff8
//         004afe88     MOV        this,ESI
//         004afe8a     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004afe8f     TEST       EAX,EAX
//         004afe91     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1475 (14)
//         004afe97     MOV        this,dword ptr [EDI]
//         004afe99     PUSH       -0x1
//                              language.dll match for 0x76e0: "Click to paint cliffs. To pai
//         004afe9b     PUSH       offset DAT_fffffff8
//         004afea0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1476 (34)
//         004afea5     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004afeab     LEA        EDX,[ESI + 0x590]
//                              language.dll match for 0x271a: "Map"
//         004afeb1     PUSH       0x271a
//         004afeb6     PUSH       EDX=>DAT_fffffff8
//         004afeb7     PUSH       EAX=>DAT_fffffff4
//         004afeb8     MOV        this,ESI
//         004afeba     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afebf     TEST       EAX,EAX
//         004afec1     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1477 (34)
//         004afec7     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004afecd     LEA        this,[ESI + 0x594]
//                              language.dll match for 0x2987: "Elevation"
//         004afed3     PUSH       0x2987
//         004afed8     PUSH       this=>DAT_fffffff8
//         004afed9     PUSH       EDX=>DAT_fffffff4
//         004afeda     MOV        this,ESI
//         004afedc     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004afee1     TEST       EAX,EAX
//         004afee3     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1478 (34)
//         004afee9     MOV        this,dword ptr [ESI + 0x4d4]
//         004afeef     LEA        EAX,[ESI + 0x598]
//                              language.dll match for 0x29ba: "Cliffs"
//         004afef5     PUSH       0x29ba
//         004afefa     PUSH       EAX=>DAT_fffffff8
//         004afefb     PUSH       this=>DAT_fffffff4
//         004afefc     MOV        this,ESI
//         004afefe     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004aff03     TEST       EAX,EAX
//         004aff05     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1480 (36)
//         004aff0b     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004aff11     LEA        EDX,[ESI + 0x5a4]
//         004aff17     LEA        EDI,[ESI + 0x5a0]
//         004aff1d     PUSH       EDX
//         004aff1e     PUSH       EDI=>DAT_fffffff8
//         004aff1f     PUSH       EAX=>DAT_fffffff4
//         004aff20     MOV        this,ESI
//         004aff22     CALL       TRIBE_Screen_Sed::create_list                    int create_list(TRIBE_Screen_Sed * this, TPan
//         004aff27     TEST       EAX,EAX
//         004aff29     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1481 (14)
//         004aff2f     MOV        this,dword ptr [EDI]
//         004aff31     PUSH       -0x1
//                              language.dll match for 0x76e1: "Select the terrain to paint."
//         004aff33     PUSH       offset DAT_fffffff8
//         004aff38     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1482 (36)
//         004aff3d     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004aff43     LEA        this,[ESI + 0x5ac]
//         004aff49     LEA        EDI,[ESI + 0x5a8]
//         004aff4f     PUSH       this
//         004aff50     PUSH       EDI=>DAT_fffffff8
//         004aff51     PUSH       EDX=>DAT_fffffff4
//         004aff52     MOV        this,ESI
//         004aff54     CALL       TRIBE_Screen_Sed::create_list                    int create_list(TRIBE_Screen_Sed * this, TPan
//         004aff59     TEST       EAX,EAX
//         004aff5b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1483 (21)
//         004aff61     MOV        this,dword ptr [EDI]
//         004aff63     PUSH       -0x1
//                              language.dll match for 0x76e2: "Select the elevation to paint
//         004aff65     PUSH       offset DAT_fffffff8
//         004aff6a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004aff6f     MOV        EDI,EBP
//         004aff71     MOV        EBX,0x5
//                               LAB_004aff76                                                 XREF[1]:     004aff84(j)
//                              scr_sed2.cpp:1488 (16)
//         004aff76     MOV        this,dword ptr [EDI]
//         004aff78     PUSH       0x5
//         004aff7a     PUSH       EBP=>DAT_fffffff8
//         004aff7b     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004aff80     ADD        EDI,0x4
//         004aff83     DEC        EBX
//         004aff84     JNZ        LAB_004aff76
//                              scr_sed2.cpp:1893 (472)
//         004aff86     LEA        EBP,[ESI + 0x584]
//         004aff8c     MOV        EBX,0x3
//         004aff91     MOV        EDI,EBP
//                               LAB_004aff93                                                 XREF[1]:     004affa1(j)
//         004aff93     MOV        this,dword ptr [EDI]
//         004aff95     PUSH       0x3
//         004aff97     PUSH       EBP=>DAT_fffffff8
//         004aff98     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004aff9d     ADD        EDI,0x4
//         004affa0     DEC        EBX
//         004affa1     JNZ        LAB_004aff93
//         004affa3     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004affa9     LEA        EBX,[ESI + 0x61c]
//         004affaf     PUSH       EBX
//         004affb0     PUSH       EAX=>DAT_fffffff8
//         004affb1     MOV        this,ESI
//         004affb3     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004affb8     TEST       EAX,EAX
//         004affba     JZ         LAB_004b1a29
//         004affc0     MOV        this,dword ptr [EBX]
//         004affc2     PUSH       -0x1
//                              language.dll match for 0x76f8: "Click here, select a unit fro
//         004affc4     PUSH       offset DAT_fffffff8
//         004affc9     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004affce     MOV        this,dword ptr [ESI + 0x4d4]
//         004affd4     LEA        EDI,[ESI + 0x620]
//         004affda     PUSH       EDI
//         004affdb     PUSH       this=>DAT_fffffff8
//         004affdc     MOV        this,ESI
//         004affde     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004affe3     TEST       EAX,EAX
//         004affe5     JZ         LAB_004b1a29
//         004affeb     MOV        this,dword ptr [EDI]
//         004affed     PUSH       -0x1
//                              language.dll match for 0x76f7: "Click here, and then click th
//         004affef     PUSH       offset DAT_fffffff8
//         004afff4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004afff9     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004affff     LEA        EDI,[ESI + 0x624]
//         004b0005     PUSH       EDI
//         004b0006     PUSH       EDX=>DAT_fffffff8
//         004b0007     MOV        this,ESI
//         004b0009     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b000e     TEST       EAX,EAX
//         004b0010     JZ         LAB_004b1a29
//         004b0016     MOV        this,dword ptr [EDI]
//         004b0018     PUSH       -0x1
//                              language.dll match for 0x76f9: "Click here, and then click th
//         004b001a     PUSH       offset DAT_fffffff8
//         004b001f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b0024     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b002a     LEA        EDI,[ESI + 0x628]
//         004b0030     PUSH       EDI
//         004b0031     PUSH       EAX=>DAT_fffffff8
//         004b0032     MOV        this,ESI
//         004b0034     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0039     TEST       EAX,EAX
//         004b003b     JZ         LAB_004b1a29
//         004b0041     MOV        this,dword ptr [EDI]
//         004b0043     PUSH       -0x1
//                              language.dll match for 0x76fa: "Click here, and then click th
//         004b0045     PUSH       offset DAT_fffffff8
//         004b004a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b004f     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0055     LEA        this,[ESI + 0x62c]
//                              language.dll match for 0x2777: "Place"
//         004b005b     PUSH       0x2777
//         004b0060     PUSH       this=>DAT_fffffff8
//         004b0061     PUSH       EDX=>DAT_fffffff4
//         004b0062     MOV        this,ESI
//         004b0064     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0069     TEST       EAX,EAX
//         004b006b     JZ         LAB_004b1a29
//         004b0071     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0077     LEA        EAX,[ESI + 0x630]
//                              language.dll match for 0x2778: "Delete"
//         004b007d     PUSH       0x2778
//         004b0082     PUSH       EAX=>DAT_fffffff8
//         004b0083     PUSH       this=>DAT_fffffff4
//         004b0084     MOV        this,ESI
//         004b0086     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b008b     TEST       EAX,EAX
//         004b008d     JZ         LAB_004b1a29
//         004b0093     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0099     LEA        EDX,[ESI + 0x634]
//                              language.dll match for 0x2779: "Move"
//         004b009f     PUSH       0x2779
//         004b00a4     PUSH       EDX=>DAT_fffffff8
//         004b00a5     PUSH       EAX=>DAT_fffffff4
//         004b00a6     MOV        this,ESI
//         004b00a8     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b00ad     TEST       EAX,EAX
//         004b00af     JZ         LAB_004b1a29
//         004b00b5     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b00bb     LEA        this,[ESI + 0x638]
//                              language.dll match for 0x277a: "Rotate"
//         004b00c1     PUSH       0x277a
//         004b00c6     PUSH       this=>DAT_fffffff8
//         004b00c7     PUSH       EDX=>DAT_fffffff4
//         004b00c8     MOV        this,ESI
//         004b00ca     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b00cf     TEST       EAX,EAX
//         004b00d1     JZ         LAB_004b1a29
//         004b00d7     MOV        EDI,EBX
//         004b00d9     MOV        EBP,0x4
//                               LAB_004b00de                                                 XREF[1]:     004b00ec(j)
//         004b00de     MOV        this,dword ptr [EDI]
//         004b00e0     PUSH       0x4
//         004b00e2     PUSH       EBX=>DAT_fffffff8
//         004b00e3     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004b00e8     ADD        EDI,0x4
//         004b00eb     DEC        EBP
//         004b00ec     JNZ        LAB_004b00de
//         004b00ee     MOV        this,dword ptr [EBX]
//         004b00f0     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//         004b00f5     LEA        EAX,[ESI + 0x640]
//         004b00fb     LEA        EDI,[ESI + 0x63c]
//         004b0101     PUSH       EAX
//         004b0102     PUSH       EDI=>DAT_fffffff8
//         004b0103     PUSH       ESI=>DAT_fffffff4
//         004b0104     MOV        this,ESI
//         004b0106     CALL       TRIBE_Screen_Sed::create_list                    int create_list(TRIBE_Screen_Sed * this, TPan
//         004b010b     TEST       EAX,EAX
//         004b010d     JZ         LAB_004b1a29
//         004b0113     MOV        this,dword ptr [EDI]
//         004b0115     OR         EBP,0xffffffff
//         004b0118     PUSH       EBP
//                              language.dll match for 0x76fb: "Select the unit to place on t
//         004b0119     PUSH       offset DAT_fffffff8
//         004b011e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b0123     MOV        this,dword ptr [EDI]
//         004b0125     PUSH       0x0
//         004b0127     PUSH       offset DAT_fffffff8
//         004b0129     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//         004b012e     PUSH       0x20
//         004b0130     CALL       operator_new                                     void * operator_new(uint param_1)
//         004b0135     ADD        ESP,0x4
//         004b0138     MOV        dword ptr [ESP + 0x10],EAX
//         004b013c     TEST       EAX,EAX
//         004b013e     MOV        dword ptr [ESP + 0x1d4],0x0
//         004b0149     JZ         LAB_004b015e
//         004b014b     PUSH       0xc62a
//         004b0150     PUSH       s_btnunit.shp                                    = "btnunit.shp"
//         004b0155     MOV        this,EAX
//         004b0157     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004b015c     JMP        LAB_004b0160
//                               LAB_004b015e                                                 XREF[1]:     004b0149(j)
//                              scr_sed2.cpp:1522 (2)
//         004b015e     XOR        EAX,EAX
//                               LAB_004b0160                                                 XREF[1]:     004b015c(j)
//                              scr_sed2.cpp:1523 (36)
//         004b0160     TEST       EAX,EAX
//         004b0162     MOV        dword ptr [ESP + 0x1d4],EBP
//         004b0169     MOV        dword ptr [ESI + 0x648],EAX
//         004b016f     JZ         LAB_004b1a1f
//         004b0175     MOV        this,EAX
//         004b0177     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
//         004b017c     TEST       EAX,EAX
//         004b017e     JZ         LAB_004b1a1f
//                              scr_sed2.cpp:1529 (2)
//         004b0184     XOR        EBX,EBX
//                               LAB_004b0186                                                 XREF[1]:     004b0208(j)
//                              scr_sed2.cpp:1533 (7)
//         004b0186     CMP        EBX,0x4
//         004b0189     MOV        EDI,EBX
//         004b018b     JNZ        LAB_004b0192
//                              scr_sed2.cpp:1534 (5)
//         004b018d     MOV        EDI,0x1
//                               LAB_004b0192                                                 XREF[1]:     004b018b(j)
//                              scr_sed2.cpp:1536 (22)
//         004b0192     PUSH       EDI
//         004b0193     LEA        this,[ESP + 0xe0]
//         004b019a     PUSH       s_btnbldg%d.shp                                  = "btnbldg%d.shp"
//         004b019f     PUSH       this=>DAT_fffffff4
//         004b01a0     CALL       sprintf                                          undefined sprintf()
//         004b01a5     ADD        ESP,0xc
//                              scr_sed2.cpp:1537 (55)
//         004b01a8     PUSH       0x20
//         004b01aa     CALL       operator_new                                     void * operator_new(uint param_1)
//         004b01af     ADD        ESP,0x4
//         004b01b2     MOV        dword ptr [ESP + 0x10],EAX
//         004b01b6     TEST       EAX,EAX
//         004b01b8     MOV        dword ptr [ESP + 0x1d4],0x1
//         004b01c3     JZ         LAB_004b01dd
//         004b01c5     LEA        EDX,[EDI + 0xc610]
//         004b01cb     LEA        this,[ESP + 0xdc]
//         004b01d2     PUSH       EDX
//         004b01d3     PUSH       this=>DAT_fffffff8
//         004b01d4     MOV        this,EAX
//         004b01d6     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004b01db     JMP        LAB_004b01df
//                               LAB_004b01dd                                                 XREF[1]:     004b01c3(j)
//         004b01dd     XOR        EAX,EAX
//                               LAB_004b01df                                                 XREF[1]:     004b01db(j)
//                              scr_sed2.cpp:1538 (47)
//         004b01df     TEST       EAX,EAX
//         004b01e1     MOV        dword ptr [ESP + 0x1d4],EBP
//         004b01e8     MOV        dword ptr [ESI + EDI*0x4 + 0x64c],EAX
//         004b01ef     JZ         LAB_004b1a1f
//         004b01f5     MOV        this,EAX
//         004b01f7     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
//         004b01fc     TEST       EAX,EAX
//         004b01fe     JZ         LAB_004b1a1f
//         004b0204     INC        EBX
//         004b0205     CMP        EBX,0x5
//         004b0208     JL         LAB_004b0186
//                              scr_sed2.cpp:1546 (29)
//         004b020e     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0214     LEA        EBX,[ESI + 0x618]
//         004b021a     PUSH       EBX
//         004b021b     PUSH       EDX=>DAT_fffffff8
//         004b021c     MOV        this,ESI
//         004b021e     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0223     TEST       EAX,EAX
//         004b0225     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1547 (13)
//         004b022b     MOV        this,dword ptr [EBX]
//         004b022d     PUSH       EBP
//                              language.dll match for 0x76fc: "Select the player to place un
//         004b022e     PUSH       offset DAT_fffffff8
//         004b0233     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1550 (13)
//         004b0238     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b023e     PUSH       0xa
//         004b0240     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
//                              scr_sed2.cpp:1552 (77)
//         004b0245     PUSH       0x21c
//         004b024a     MOV        EDI,EAX
//         004b024c     CALL       operator_new                                     void * operator_new(uint param_1)
//         004b0251     ADD        ESP,0x4
//         004b0254     MOV        dword ptr [ESP + 0x10],EAX
//         004b0258     TEST       EAX,EAX
//         004b025a     MOV        dword ptr [ESP + 0x1d4],0x2
//         004b0265     JZ         LAB_004b0290
//         004b0267     MOV        EDX,dword ptr [ESI + 0x648]
//         004b026d     LEA        this,[ESI + 0x64c]
//         004b0273     PUSH       0x0
//         004b0275     PUSH       this=>DAT_fffffff8
//         004b0276     MOV        this,dword ptr [EDI + 0x8]
//         004b0279     PUSH       EDX=>DAT_fffffff4
//         004b027a     MOV        EDX,dword ptr [EDI + 0x4]
//         004b027d     PUSH       this=>DAT_fffffff0
//         004b027e     MOV        this,dword ptr [EDI]
//         004b0280     PUSH       EDX
//         004b0281     MOV        EDX,dword ptr [ESI + 0x20]
//         004b0284     PUSH       this
//         004b0285     PUSH       ESI
//         004b0286     PUSH       EDX
//         004b0287     MOV        this,EAX
//         004b0289     CALL       TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scen   undefined TRIBE_Scenario_Editor_Panel_Object(
//         004b028e     JMP        LAB_004b0292
//                               LAB_004b0290                                                 XREF[1]:     004b0265(j)
//         004b0290     XOR        EAX,EAX
//                               LAB_004b0292                                                 XREF[1]:     004b028e(j)
//                              scr_sed2.cpp:1553 (35)
//         004b0292     TEST       EAX,EAX
//         004b0294     MOV        dword ptr [ESP + 0x1d4],EBP
//         004b029b     MOV        dword ptr [ESI + 0x660],EAX
//         004b02a1     JZ         LAB_004b1a1f
//         004b02a7     MOV        this,dword ptr [EAX + 0xd8]
//         004b02ad     TEST       this,this
//         004b02af     JNZ        LAB_004b1a1f
//                              scr_sed2.cpp:1558 (9)
//         004b02b5     MOV        EDX,dword ptr [EAX]
//         004b02b7     PUSH       0x0
//         004b02b9     MOV        this,EAX
//         004b02bb     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:1559 (11)
//         004b02be     MOV        this,dword ptr [EBX]
//         004b02c0     PUSH       0x0
//         004b02c2     PUSH       offset DAT_fffffff8
//         004b02c4     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              scr_sed2.cpp:1564 (34)
//         004b02c9     MOV        this,dword ptr [ESI + 0x4d4]
//         004b02cf     LEA        EAX,[ESI + 0x5b0]
//                              language.dll match for 0x2864: "Number of Players"
//         004b02d5     PUSH       0x2864
//         004b02da     PUSH       EAX=>DAT_fffffff8
//         004b02db     PUSH       this=>DAT_fffffff4
//         004b02dc     MOV        this,ESI
//         004b02de     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b02e3     TEST       EAX,EAX
//         004b02e5     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1565 (34)
//         004b02eb     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b02f1     LEA        EDX,[ESI + 0x5f4]
//                              language.dll match for 0x2815: "Starting Age"
//         004b02f7     PUSH       0x2815
//         004b02fc     PUSH       EDX=>DAT_fffffff8
//         004b02fd     PUSH       EAX=>DAT_fffffff4
//         004b02fe     MOV        this,ESI
//         004b0300     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0305     TEST       EAX,EAX
//         004b0307     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1566 (29)
//         004b030d     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0313     LEA        EDI,[ESI + 0x5bc]
//         004b0319     PUSH       EDI
//         004b031a     PUSH       this=>DAT_fffffff8
//         004b031b     MOV        this,ESI
//         004b031d     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0322     TEST       EAX,EAX
//         004b0324     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1567 (13)
//         004b032a     MOV        this,dword ptr [EDI]
//         004b032c     PUSH       EBP
//                              language.dll match for 0x7765: "Select the starting age."
//         004b032d     PUSH       offset DAT_fffffff8
//         004b0332     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1568 (9)
//         004b0337     PUSH       0x0
//         004b0339     MOV        this,ESI
//         004b033b     CALL       TRIBE_Screen_Sed::Set_player_advance_civilizat   int Set_player_advance_civilization_text(TRIB
//                              scr_sed2.cpp:1570 (29)
//         004b0340     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0346     LEA        EDI,[ESI + 0x5b4]
//         004b034c     PUSH       EDI
//         004b034d     PUSH       EDX=>DAT_fffffff8
//         004b034e     MOV        this,ESI
//         004b0350     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0355     TEST       EAX,EAX
//         004b0357     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1571 (13)
//         004b035d     MOV        this,dword ptr [EDI]
//         004b035f     PUSH       EBP
//                              language.dll match for 0x76e6: "Select the player to customiz
//         004b0360     PUSH       offset DAT_fffffff8
//         004b0365     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1572 (29)
//         004b036a     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0370     LEA        EDI,[ESI + 0x5b8]
//         004b0376     PUSH       EDI
//         004b0377     PUSH       EAX=>DAT_fffffff8
//         004b0378     MOV        this,ESI
//         004b037a     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b037f     TEST       EAX,EAX
//         004b0381     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1573 (13)
//         004b0387     MOV        this,dword ptr [EDI]
//         004b0389     PUSH       EBP
//                              language.dll match for 0x76e7: "Select the number of players."
//         004b038a     PUSH       offset DAT_fffffff8
//         004b038f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1575 (34)
//         004b0394     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b039a     LEA        this,[ESI + 0x5c4]
//                              language.dll match for 0x280b: "Food"
//         004b03a0     PUSH       0x280b
//         004b03a5     PUSH       this=>DAT_fffffff8
//         004b03a6     PUSH       EDX=>DAT_fffffff4
//         004b03a7     MOV        this,ESI
//         004b03a9     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b03ae     TEST       EAX,EAX
//         004b03b0     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1576 (34)
//         004b03b6     MOV        this,dword ptr [ESI + 0x4d4]
//         004b03bc     LEA        EAX,[ESI + 0x5c8]
//                              language.dll match for 0x280c: "Wood"
//         004b03c2     PUSH       0x280c
//         004b03c7     PUSH       EAX=>DAT_fffffff8
//         004b03c8     PUSH       this=>DAT_fffffff4
//         004b03c9     MOV        this,ESI
//         004b03cb     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b03d0     TEST       EAX,EAX
//         004b03d2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1577 (34)
//         004b03d8     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b03de     LEA        EDX,[ESI + 0x5cc]
//                              language.dll match for 0x280d: "Stone"
//         004b03e4     PUSH       0x280d
//         004b03e9     PUSH       EDX=>DAT_fffffff8
//         004b03ea     PUSH       EAX=>DAT_fffffff4
//         004b03eb     MOV        this,ESI
//         004b03ed     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b03f2     TEST       EAX,EAX
//         004b03f4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1578 (34)
//         004b03fa     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0400     LEA        this,[ESI + 0x5d0]
//                              language.dll match for 0x280e: "Gold"
//         004b0406     PUSH       0x280e
//         004b040b     PUSH       this=>DAT_fffffff8
//         004b040c     PUSH       EDX=>DAT_fffffff4
//         004b040d     MOV        this,ESI
//         004b040f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0414     TEST       EAX,EAX
//         004b0416     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1579 (34)
//         004b041c     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0422     LEA        EAX,[ESI + 0x5d4]
//                              language.dll match for 0x2805: "Tribe Name"
//         004b0428     PUSH       0x2805
//         004b042d     PUSH       EAX=>DAT_fffffff8
//         004b042e     PUSH       this=>DAT_fffffff4
//         004b042f     MOV        this,ESI
//         004b0431     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0436     TEST       EAX,EAX
//         004b0438     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1581 (8)
//         004b043e     XOR        EBX,EBX
//         004b0440     LEA        EDI,[ESI + 0x5d8]
//                               LAB_004b0446                                                 XREF[1]:     004b0471(j)
//                              scr_sed2.cpp:1582 (45)
//         004b0446     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b044c     PUSH       0x0
//         004b044e     PUSH       0x0=>DAT_fffffff8
//         004b0450     PUSH       offset DAT_fffffff4
//         004b0452     PUSH       offset DAT_fffffff0
//         004b0454     PUSH       s_0                                              = "0"
//         004b0459     PUSH       EDI
//         004b045a     PUSH       EDX
//         004b045b     MOV        this,ESI
//         004b045d     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b0462     TEST       EAX,EAX
//         004b0464     JZ         LAB_004b1a29
//         004b046a     INC        EBX
//         004b046b     ADD        EDI,0x4
//         004b046e     CMP        EBX,0x4
//         004b0471     JL         LAB_004b0446
//                              scr_sed2.cpp:1583 (18)
//         004b0473     MOV        this,dword ptr [ESI + 0x5d8]
//         004b0479     PUSH       0x1
//                              language.dll match for 0x76e8: "Type the amount of food the p
//         004b047b     PUSH       offset DAT_fffffff8
//         004b0480     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1584 (18)
//         004b0485     MOV        this,dword ptr [ESI + 0x5dc]
//         004b048b     PUSH       0x1
//                              language.dll match for 0x76e9: "Type the amount of wood the p
//         004b048d     PUSH       offset DAT_fffffff8
//         004b0492     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1585 (18)
//         004b0497     MOV        this,dword ptr [ESI + 0x5e0]
//         004b049d     PUSH       0x1
//                              language.dll match for 0x76eb: "Type the amount of stone the
//         004b049f     PUSH       offset DAT_fffffff8
//         004b04a4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1586 (18)
//         004b04a9     MOV        this,dword ptr [ESI + 0x5e4]
//         004b04af     PUSH       0x1
//                              language.dll match for 0x76ea: "Type the amount of gold the p
//         004b04b1     PUSH       offset DAT_fffffff8
//         004b04b6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1588 (42)
//         004b04bb     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b04c1     PUSH       0x1
//         004b04c3     PUSH       offset DAT_fffffff8
//         004b04c5     PUSH       0x0=>DAT_fffffff4
//         004b04c7     LEA        EDI,[ESI + 0x5e8]
//         004b04cd     PUSH       offset DAT_fffffff0
//         004b04cf     PUSH       s_                                               = ""
//         004b04d4     PUSH       EDI
//         004b04d5     PUSH       EAX
//         004b04d6     MOV        this,ESI
//         004b04d8     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b04dd     TEST       EAX,EAX
//         004b04df     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1589 (14)
//         004b04e5     MOV        this,dword ptr [EDI]
//         004b04e7     PUSH       0x1
//                              language.dll match for 0x76ec: "Type a tribe name if you want
//         004b04e9     PUSH       offset DAT_fffffff8
//         004b04ee     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1591 (34)
//         004b04f3     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b04f9     LEA        this,[ESI + 0x5ec]
//                              language.dll match for 0x2810: "Player Type"
//         004b04ff     PUSH       0x2810
//         004b0504     PUSH       this=>DAT_fffffff8
//         004b0505     PUSH       EDX=>DAT_fffffff4
//         004b0506     MOV        this,ESI
//         004b0508     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b050d     TEST       EAX,EAX
//         004b050f     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1592 (34)
//         004b0515     MOV        this,dword ptr [ESI + 0x4d4]
//         004b051b     LEA        EAX,[ESI + 0x5f0]
//                              language.dll match for 0x2811: "Civilization"
//         004b0521     PUSH       0x2811
//         004b0526     PUSH       EAX=>DAT_fffffff8
//         004b0527     PUSH       this=>DAT_fffffff4
//         004b0528     MOV        this,ESI
//         004b052a     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b052f     TEST       EAX,EAX
//         004b0531     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1593 (10)
//         004b0537     LEA        EBP,[ESI + 0x5f8]
//         004b053d     XOR        EDI,EDI
//         004b053f     MOV        EBX,EBP
//                               LAB_004b0541                                                 XREF[1]:     004b055f(j)
//                              scr_sed2.cpp:1594 (32)
//         004b0541     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0547     PUSH       EBX
//         004b0548     PUSH       EDX=>DAT_fffffff8
//         004b0549     MOV        this,ESI
//         004b054b     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0550     TEST       EAX,EAX
//         004b0552     JZ         LAB_004b1a29
//         004b0558     INC        EDI
//         004b0559     ADD        EBX,0x4
//         004b055c     CMP        EDI,0x2
//         004b055f     JL         LAB_004b0541
//                              scr_sed2.cpp:1595 (15)
//         004b0561     MOV        this,dword ptr [EBP]
//         004b0564     PUSH       -0x1
//                              language.dll match for 0x76ed: "Select whether the position i
//         004b0566     PUSH       offset DAT_fffffff8
//         004b056b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1596 (18)
//         004b0570     MOV        this,dword ptr [ESI + 0x5fc]
//         004b0576     PUSH       -0x1
//                              language.dll match for 0x76ee: "Select the player's civilizat
//         004b0578     PUSH       offset DAT_fffffff8
//         004b057d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1598 (29)
//         004b0582     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0588     LEA        EDI,[ESI + 0x600]
//         004b058e     PUSH       EDI
//         004b058f     PUSH       EAX=>DAT_fffffff8
//         004b0590     MOV        this,ESI
//         004b0592     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0597     TEST       EAX,EAX
//         004b0599     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1599 (14)
//         004b059f     MOV        this,dword ptr [EDI]
//         004b05a1     PUSH       -0x1
//                              language.dll match for 0x76ef: "Select the strategy the compu
//         004b05a3     PUSH       offset DAT_fffffff8
//         004b05a8     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1600 (29)
//         004b05ad     MOV        this,dword ptr [ESI + 0x4d4]
//         004b05b3     LEA        EDI,[ESI + 0x604]
//         004b05b9     PUSH       EDI
//         004b05ba     PUSH       this=>DAT_fffffff8
//         004b05bb     MOV        this,ESI
//         004b05bd     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b05c2     TEST       EAX,EAX
//         004b05c4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1601 (14)
//         004b05ca     MOV        this,dword ptr [EDI]
//         004b05cc     PUSH       -0x1
//                              language.dll match for 0x76f0: "Select the city plan the comp
//         004b05ce     PUSH       offset DAT_fffffff8
//         004b05d3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1602 (29)
//         004b05d8     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b05de     LEA        EDI,[ESI + 0x608]
//         004b05e4     PUSH       EDI
//         004b05e5     PUSH       EDX=>DAT_fffffff8
//         004b05e6     MOV        this,ESI
//         004b05e8     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b05ed     TEST       EAX,EAX
//         004b05ef     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1603 (14)
//         004b05f5     MOV        this,dword ptr [EDI]
//         004b05f7     PUSH       -0x1
//                              language.dll match for 0x76f1: "Select the personality of the
//         004b05f9     PUSH       offset DAT_fffffff8
//         004b05fe     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1604 (34)
//         004b0603     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0609     LEA        EAX,[ESI + 0x60c]
//                              language.dll match for 0x2813: "Strategy"
//         004b060f     PUSH       0x2813
//         004b0614     PUSH       EAX=>DAT_fffffff8
//         004b0615     PUSH       this=>DAT_fffffff4
//         004b0616     MOV        this,ESI
//         004b0618     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b061d     TEST       EAX,EAX
//         004b061f     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1605 (34)
//         004b0625     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b062b     LEA        EDX,[ESI + 0x610]
//                              language.dll match for 0x2814: "City Plan"
//         004b0631     PUSH       0x2814
//         004b0636     PUSH       EDX=>DAT_fffffff8
//         004b0637     PUSH       EAX=>DAT_fffffff4
//         004b0638     MOV        this,ESI
//         004b063a     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b063f     TEST       EAX,EAX
//         004b0641     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1606 (34)
//         004b0647     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b064d     LEA        this,[ESI + 0x614]
//                              language.dll match for 0x2812: "Personality"
//         004b0653     PUSH       0x2812
//         004b0658     PUSH       this=>DAT_fffffff8
//         004b0659     PUSH       EDX=>DAT_fffffff4
//         004b065a     MOV        this,ESI
//         004b065c     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0661     TEST       EAX,EAX
//         004b0663     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1609 (25)
//         004b0669     MOV        EAX,dword ptr [ESI]
//         004b066b     LEA        this,[ESI + 0x5d8]
//         004b0671     PUSH       0x5
//         004b0673     PUSH       this=>DAT_fffffff8
//         004b0674     MOV        EAX,dword ptr [EAX + 0xc8]
//         004b067a     MOV        this,ESI
//         004b067c     MOV        dword ptr [ESP + 0x18],EAX
//         004b0680     CALL       EAX
//                              scr_sed2.cpp:1616 (29)
//         004b0682     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0688     LEA        EDI,[ESI + 0x668]
//         004b068e     PUSH       EDI
//         004b068f     PUSH       this=>DAT_fffffff8
//         004b0690     MOV        this,ESI
//         004b0692     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b0697     TEST       EAX,EAX
//         004b0699     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1617 (14)
//         004b069f     MOV        this,dword ptr [EDI]
//         004b06a1     PUSH       -0x1
//                              language.dll match for 0x7704: "The first civilization (or te
//         004b06a3     PUSH       offset DAT_fffffff8
//         004b06a8     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1618 (29)
//         004b06ad     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b06b3     LEA        EDI,[ESI + 0x66c]
//         004b06b9     PUSH       EDI
//         004b06ba     PUSH       EDX=>DAT_fffffff8
//         004b06bb     MOV        this,ESI
//         004b06bd     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b06c2     TEST       EAX,EAX
//         004b06c4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1619 (14)
//         004b06ca     MOV        this,dword ptr [EDI]
//         004b06cc     PUSH       -0x1
//                              language.dll match for 0x7706: "Type the percentage of the ma
//         004b06ce     PUSH       offset DAT_fffffff8
//         004b06d3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1620 (29)
//         004b06d8     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b06de     LEA        EDI,[ESI + 0x670]
//         004b06e4     PUSH       EDI
//         004b06e5     PUSH       EAX=>DAT_fffffff8
//         004b06e6     MOV        this,ESI
//         004b06e8     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b06ed     TEST       EAX,EAX
//         004b06ef     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1621 (14)
//         004b06f5     MOV        this,dword ptr [EDI]
//         004b06f7     PUSH       -0x1
//                              language.dll match for 0x7707: "The first civilization (or te
//         004b06f9     PUSH       offset DAT_fffffff8
//         004b06fe     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1622 (29)
//         004b0703     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0709     LEA        EDI,[ESI + 0x674]
//         004b070f     PUSH       EDI
//         004b0710     PUSH       this=>DAT_fffffff8
//         004b0711     MOV        this,ESI
//         004b0713     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b0718     TEST       EAX,EAX
//         004b071a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1623 (14)
//         004b0720     MOV        this,dword ptr [EDI]
//         004b0722     PUSH       -0x1
//                              language.dll match for 0x7708: "The first civilization (or te
//         004b0724     PUSH       offset DAT_fffffff8
//         004b0729     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1624 (29)
//         004b072e     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0734     LEA        EDI,[ESI + 0x678]
//         004b073a     PUSH       EDI
//         004b073b     PUSH       EDX=>DAT_fffffff8
//         004b073c     MOV        this,ESI
//         004b073e     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b0743     TEST       EAX,EAX
//         004b0745     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1625 (14)
//         004b074b     MOV        this,dword ptr [EDI]
//         004b074d     PUSH       -0x1
//                              language.dll match for 0x7709: "The first civilization (or te
//         004b074f     PUSH       offset DAT_fffffff8
//         004b0754     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1626 (29)
//         004b0759     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b075f     LEA        EDI,[ESI + 0x67c]
//         004b0765     PUSH       EDI
//         004b0766     PUSH       EAX=>DAT_fffffff8
//         004b0767     MOV        this,ESI
//         004b0769     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b076e     TEST       EAX,EAX
//         004b0770     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1627 (14)
//         004b0776     MOV        this,dword ptr [EDI]
//         004b0778     PUSH       -0x1
//         004b077a     PUSH       offset DAT_fffffff8
//         004b077f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1629 (29)
//         004b0784     MOV        this,dword ptr [ESI + 0x4d4]
//         004b078a     LEA        EBX,[ESI + 0x680]
//         004b0790     PUSH       EBX
//         004b0791     PUSH       this=>DAT_fffffff8
//         004b0792     MOV        this,ESI
//         004b0794     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0799     TEST       EAX,EAX
//         004b079b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1630 (14)
//         004b07a1     MOV        this,dword ptr [EBX]
//         004b07a3     PUSH       -0x1
//                              language.dll match for 0x7701: "Click to allow players to ach
//         004b07a5     PUSH       offset DAT_fffffff8
//         004b07aa     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1631 (29)
//         004b07af     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b07b5     LEA        EDI,[ESI + 0x684]
//         004b07bb     PUSH       EDI
//         004b07bc     PUSH       EDX=>DAT_fffffff8
//         004b07bd     MOV        this,ESI
//         004b07bf     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b07c4     TEST       EAX,EAX
//         004b07c6     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1632 (21)
//         004b07cc     MOV        this,dword ptr [EDI]
//         004b07ce     PUSH       -0x1
//                              language.dll match for 0x7703: "Click to require players to a
//         004b07d0     PUSH       offset DAT_fffffff8
//         004b07d5     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b07da     MOV        EDI,EBX
//         004b07dc     MOV        EBP,0x2
//                               LAB_004b07e1                                                 XREF[1]:     004b07ef(j)
//                              scr_sed2.cpp:1634 (16)
//         004b07e1     MOV        this,dword ptr [EDI]
//         004b07e3     PUSH       0x2
//         004b07e5     PUSH       EBX=>DAT_fffffff8
//         004b07e6     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004b07eb     ADD        EDI,0x4
//         004b07ee     DEC        EBP
//         004b07ef     JNZ        LAB_004b07e1
//                              scr_sed2.cpp:1635 (7)
//         004b07f1     MOV        this,dword ptr [EBX]
//         004b07f3     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              scr_sed2.cpp:1638 (34)
//         004b07f8     MOV        this,dword ptr [ESI + 0x4d4]
//         004b07fe     LEA        EAX,[ESI + 0x694]
//                              language.dll match for 0x28a2: "Any one"
//         004b0804     PUSH       0x28a2
//         004b0809     PUSH       EAX=>DAT_fffffff8
//         004b080a     PUSH       this=>DAT_fffffff4
//         004b080b     MOV        this,ESI
//         004b080d     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0812     TEST       EAX,EAX
//         004b0814     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1639 (34)
//         004b081a     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0820     LEA        EDX,[ESI + 0x698]
//                              language.dll match for 0x28a3: "All"
//         004b0826     PUSH       0x28a3
//         004b082b     PUSH       EDX=>DAT_fffffff8
//         004b082c     PUSH       EAX=>DAT_fffffff4
//         004b082d     MOV        this,ESI
//         004b082f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0834     TEST       EAX,EAX
//         004b0836     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1641 (34)
//         004b083c     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0842     LEA        this,[ESI + 0x68c]
//                              language.dll match for 0x28a4: "Quantity"
//         004b0848     PUSH       0x28a4
//         004b084d     PUSH       this=>DAT_fffffff8
//         004b084e     PUSH       EDX=>DAT_fffffff4
//         004b084f     MOV        this,ESI
//         004b0851     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0856     TEST       EAX,EAX
//         004b0858     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1642 (34)
//         004b085e     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0864     LEA        EAX,[ESI + 0x690]
//                              language.dll match for 0x28a5: "Which Conditions"
//         004b086a     PUSH       0x28a5
//         004b086f     PUSH       EAX=>DAT_fffffff8
//         004b0870     PUSH       this=>DAT_fffffff4
//         004b0871     MOV        this,ESI
//         004b0873     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0878     TEST       EAX,EAX
//         004b087a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1643 (34)
//         004b0880     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0886     LEA        EDX,[ESI + 0x688]
//                              language.dll match for 0x10e0: "Victory Condition"
//         004b088c     PUSH       0x10e0
//         004b0891     PUSH       EDX=>DAT_fffffff8
//         004b0892     PUSH       EAX=>DAT_fffffff4
//         004b0893     MOV        this,ESI
//         004b0895     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b089a     TEST       EAX,EAX
//         004b089c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1645 (34)
//         004b08a2     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b08a8     LEA        this,[ESI + 0x69c]
//                              language.dll match for 0x10e1: "Conquest"
//         004b08ae     PUSH       0x10e1
//         004b08b3     PUSH       this=>DAT_fffffff8
//         004b08b4     PUSH       EDX=>DAT_fffffff4
//         004b08b5     MOV        this,ESI
//         004b08b7     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b08bc     TEST       EAX,EAX
//         004b08be     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1646 (34)
//         004b08c4     MOV        this,dword ptr [ESI + 0x4d4]
//         004b08ca     LEA        EAX,[ESI + 0x6a0]
//                              language.dll match for 0x10e2: "Exploration"
//         004b08d0     PUSH       0x10e2
//         004b08d5     PUSH       EAX=>DAT_fffffff8
//         004b08d6     PUSH       this=>DAT_fffffff4
//         004b08d7     MOV        this,ESI
//         004b08d9     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b08de     TEST       EAX,EAX
//         004b08e0     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1647 (34)
//         004b08e6     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b08ec     LEA        EDX,[ESI + 0x6a4]
//                              language.dll match for 0x10e7: "Default"
//         004b08f2     PUSH       0x10e7
//         004b08f7     PUSH       EDX=>DAT_fffffff8
//         004b08f8     PUSH       EAX=>DAT_fffffff4
//         004b08f9     MOV        this,ESI
//         004b08fb     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0900     TEST       EAX,EAX
//         004b0902     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1648 (34)
//         004b0908     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b090e     LEA        this,[ESI + 0x6a8]
//                              language.dll match for 0x10e3: "Ruins"
//         004b0914     PUSH       0x10e3
//         004b0919     PUSH       this=>DAT_fffffff8
//         004b091a     PUSH       EDX=>DAT_fffffff4
//         004b091b     MOV        this,ESI
//         004b091d     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0922     TEST       EAX,EAX
//         004b0924     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1649 (34)
//         004b092a     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0930     LEA        EAX,[ESI + 0x6ac]
//                              language.dll match for 0x10e4: "Artifacts"
//         004b0936     PUSH       0x10e4
//         004b093b     PUSH       EAX=>DAT_fffffff8
//         004b093c     PUSH       this=>DAT_fffffff4
//         004b093d     MOV        this,ESI
//         004b093f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0944     TEST       EAX,EAX
//         004b0946     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1650 (34)
//         004b094c     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0952     LEA        EDX,[ESI + 0x6b0]
//                              language.dll match for 0x10e5: "Discoveries"
//         004b0958     PUSH       0x10e5
//         004b095d     PUSH       EDX=>DAT_fffffff8
//         004b095e     PUSH       EAX=>DAT_fffffff4
//         004b095f     MOV        this,ESI
//         004b0961     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0966     TEST       EAX,EAX
//         004b0968     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1651 (34)
//         004b096e     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0974     LEA        this,[ESI + 0x6b4]
//                              language.dll match for 0x10e6: "Gold"
//         004b097a     PUSH       0x10e6
//         004b097f     PUSH       this=>DAT_fffffff8
//         004b0980     PUSH       EDX=>DAT_fffffff4
//         004b0981     MOV        this,ESI
//         004b0983     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0988     TEST       EAX,EAX
//         004b098a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1653 (42)
//         004b0990     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0996     PUSH       0x0
//         004b0998     PUSH       0x0=>DAT_fffffff8
//         004b099a     PUSH       offset DAT_fffffff4
//         004b099c     LEA        EDI,[ESI + 0x6b8]
//         004b09a2     PUSH       offset DAT_fffffff0
//         004b09a4     PUSH       s__                                              = 20h
//         004b09a9     PUSH       EDI
//         004b09aa     PUSH       EAX
//         004b09ab     MOV        this,ESI
//         004b09ad     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b09b2     TEST       EAX,EAX
//         004b09b4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1654 (14)
//         004b09ba     MOV        this,dword ptr [EDI]
//         004b09bc     PUSH       -0x1
//                              language.dll match for 0x770b: "Type the percentage of the ma
//         004b09be     PUSH       offset DAT_fffffff8
//         004b09c3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1655 (42)
//         004b09c8     MOV        this,dword ptr [ESI + 0x4d4]
//         004b09ce     PUSH       0x0
//         004b09d0     PUSH       0x0=>DAT_fffffff8
//         004b09d2     PUSH       offset DAT_fffffff4
//         004b09d4     LEA        EDI,[ESI + 0x6bc]
//         004b09da     PUSH       offset DAT_fffffff0
//         004b09dc     PUSH       s__                                              = 20h
//         004b09e1     PUSH       EDI
//         004b09e2     PUSH       this
//         004b09e3     MOV        this,ESI
//         004b09e5     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b09ea     TEST       EAX,EAX
//         004b09ec     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1656 (14)
//         004b09f2     MOV        this,dword ptr [EDI]
//         004b09f4     PUSH       -0x1
//                              language.dll match for 0x770c: "Type the number of Ruins that
//         004b09f6     PUSH       offset DAT_fffffff8
//         004b09fb     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1657 (42)
//         004b0a00     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0a06     PUSH       0x0
//         004b0a08     PUSH       0x0=>DAT_fffffff8
//         004b0a0a     PUSH       offset DAT_fffffff4
//         004b0a0c     LEA        EBX,[ESI + 0x6c0]
//         004b0a12     PUSH       offset DAT_fffffff0
//         004b0a14     PUSH       s__                                              = 20h
//         004b0a19     PUSH       EBX
//         004b0a1a     PUSH       EDX
//         004b0a1b     MOV        this,ESI
//         004b0a1d     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b0a22     TEST       EAX,EAX
//         004b0a24     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1658 (14)
//         004b0a2a     MOV        this,dword ptr [EBX]
//         004b0a2c     PUSH       -0x1
//                              language.dll match for 0x770d: "Type the number of Artifacts
//         004b0a2e     PUSH       offset DAT_fffffff8
//         004b0a33     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1659 (42)
//         004b0a38     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0a3e     PUSH       0x0
//         004b0a40     PUSH       0x0=>DAT_fffffff8
//         004b0a42     PUSH       offset DAT_fffffff4
//         004b0a44     LEA        EDI,[ESI + 0x6c4]
//         004b0a4a     PUSH       offset DAT_fffffff0
//         004b0a4c     PUSH       s__                                              = 20h
//         004b0a51     PUSH       EDI
//         004b0a52     PUSH       EAX
//         004b0a53     MOV        this,ESI
//         004b0a55     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b0a5a     TEST       EAX,EAX
//         004b0a5c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1660 (14)
//         004b0a62     MOV        this,dword ptr [EDI]
//         004b0a64     PUSH       -0x1
//                              language.dll match for 0x770e: "Type the number of Discoverie
//         004b0a66     PUSH       offset DAT_fffffff8
//         004b0a6b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1661 (42)
//         004b0a70     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0a76     PUSH       0x0
//         004b0a78     PUSH       0x0=>DAT_fffffff8
//         004b0a7a     PUSH       offset DAT_fffffff4
//         004b0a7c     LEA        EBP,[ESI + 0x6c8]
//         004b0a82     PUSH       offset DAT_fffffff0
//         004b0a84     PUSH       s__                                              = 20h
//         004b0a89     PUSH       EBP
//         004b0a8a     PUSH       this
//         004b0a8b     MOV        this,ESI
//         004b0a8d     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b0a92     TEST       EAX,EAX
//         004b0a94     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1662 (15)
//         004b0a9a     MOV        this,dword ptr [EBP]
//         004b0a9d     PUSH       -0x1
//         004b0a9f     PUSH       offset DAT_fffffff8
//         004b0aa4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1665 (12)
//         004b0aa9     MOV        EAX,dword ptr [ESI + 0x6bc]
//         004b0aaf     MOV        EDX,dword ptr [ESI + 0x6b8]
//                              scr_sed2.cpp:1666 (10)
//         004b0ab5     MOV        this,dword ptr [EBX]
//         004b0ab7     MOV        dword ptr [ESP + 0x1c],EAX
//         004b0abb     MOV        dword ptr [ESP + 0x18],EDX
//                              scr_sed2.cpp:1667 (2)
//         004b0abf     MOV        EDX,dword ptr [EDI]
//                              scr_sed2.cpp:1668 (21)
//         004b0ac1     LEA        EAX,[ESP + 0x18]
//         004b0ac5     MOV        dword ptr [ESP + 0x20],this
//         004b0ac9     PUSH       0x4
//         004b0acb     PUSH       EAX=>DAT_fffffff8
//         004b0acc     MOV        this,ESI
//         004b0ace     MOV        dword ptr [ESP + 0x2c],EDX
//         004b0ad2     CALL       dword ptr [ESP + 0x18]
//                              scr_sed2.cpp:1670 (34)
//         004b0ad6     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0adc     LEA        this,[ESI + 0x6cc]
//                              language.dll match for 0x10ec: "Standard"
//         004b0ae2     PUSH       0x10ec
//         004b0ae7     PUSH       this=>DAT_fffffff8
//         004b0ae8     PUSH       EDX=>DAT_fffffff4
//         004b0ae9     MOV        this,ESI
//         004b0aeb     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0af0     TEST       EAX,EAX
//         004b0af2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1671 (34)
//         004b0af8     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0afe     LEA        EAX,[ESI + 0x6d0]
//                              language.dll match for 0x10e1: "Conquest"
//         004b0b04     PUSH       0x10e1
//         004b0b09     PUSH       EAX=>DAT_fffffff8
//         004b0b0a     PUSH       this=>DAT_fffffff4
//         004b0b0b     MOV        this,ESI
//         004b0b0d     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0b12     TEST       EAX,EAX
//         004b0b14     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1672 (34)
//         004b0b1a     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0b20     LEA        EDX,[ESI + 0x6d4]
//                              language.dll match for 0x10ea: "Score"
//         004b0b26     PUSH       0x10ea
//         004b0b2b     PUSH       EDX=>DAT_fffffff8
//         004b0b2c     PUSH       EAX=>DAT_fffffff4
//         004b0b2d     MOV        this,ESI
//         004b0b2f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0b34     TEST       EAX,EAX
//         004b0b36     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1673 (34)
//         004b0b3c     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0b42     LEA        this,[ESI + 0x6d8]
//                              language.dll match for 0x10e9: "Time Limit"
//         004b0b48     PUSH       0x10e9
//         004b0b4d     PUSH       this=>DAT_fffffff8
//         004b0b4e     PUSH       EDX=>DAT_fffffff4
//         004b0b4f     MOV        this,ESI
//         004b0b51     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0b56     TEST       EAX,EAX
//         004b0b58     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1674 (34)
//         004b0b5e     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0b64     LEA        EAX,[ESI + 0x6dc]
//                              language.dll match for 0x10eb: "Custom"
//         004b0b6a     PUSH       0x10eb
//         004b0b6f     PUSH       EAX=>DAT_fffffff8
//         004b0b70     PUSH       this=>DAT_fffffff4
//         004b0b71     MOV        this,ESI
//         004b0b73     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0b78     TEST       EAX,EAX
//         004b0b7a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1676 (29)
//         004b0b80     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0b86     LEA        EBX,[ESI + 0x6e0]
//         004b0b8c     PUSH       EBX
//         004b0b8d     PUSH       EDX=>DAT_fffffff8
//         004b0b8e     MOV        this,ESI
//         004b0b90     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0b95     TEST       EAX,EAX
//         004b0b97     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1677 (14)
//         004b0b9d     MOV        this,dword ptr [EBX]
//         004b0b9f     PUSH       -0x1
//                              language.dll match for 0x7756: "Click to require players to a
//         004b0ba1     PUSH       offset DAT_fffffff8
//         004b0ba6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1678 (29)
//         004b0bab     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0bb1     LEA        EDI,[ESI + 0x6e4]
//         004b0bb7     PUSH       EDI
//         004b0bb8     PUSH       EAX=>DAT_fffffff8
//         004b0bb9     MOV        this,ESI
//         004b0bbb     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0bc0     TEST       EAX,EAX
//         004b0bc2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1679 (14)
//         004b0bc8     MOV        this,dword ptr [EDI]
//         004b0bca     PUSH       -0x1
//                              language.dll match for 0x7757: "The first civilization (or te
//         004b0bcc     PUSH       offset DAT_fffffff8
//         004b0bd1     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1680 (29)
//         004b0bd6     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0bdc     LEA        EDI,[ESI + 0x6e8]
//         004b0be2     PUSH       EDI
//         004b0be3     PUSH       this=>DAT_fffffff8
//         004b0be4     MOV        this,ESI
//         004b0be6     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0beb     TEST       EAX,EAX
//         004b0bed     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1681 (14)
//         004b0bf3     MOV        this,dword ptr [EDI]
//         004b0bf5     PUSH       -0x1
//                              language.dll match for 0x7758: "Click to set the victory cond
//         004b0bf7     PUSH       offset DAT_fffffff8
//         004b0bfc     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1682 (29)
//         004b0c01     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0c07     LEA        EDI,[ESI + 0x6ec]
//         004b0c0d     PUSH       EDI
//         004b0c0e     PUSH       EDX=>DAT_fffffff8
//         004b0c0f     MOV        this,ESI
//         004b0c11     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0c16     TEST       EAX,EAX
//         004b0c18     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1683 (14)
//         004b0c1e     MOV        this,dword ptr [EDI]
//         004b0c20     PUSH       -0x1
//                              language.dll match for 0x7759: "Click to set the victory cond
//         004b0c22     PUSH       offset DAT_fffffff8
//         004b0c27     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1684 (29)
//         004b0c2c     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0c32     LEA        EDI,[ESI + 0x6f0]
//         004b0c38     PUSH       EDI
//         004b0c39     PUSH       EAX=>DAT_fffffff8
//         004b0c3a     MOV        this,ESI
//         004b0c3c     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b0c41     TEST       EAX,EAX
//         004b0c43     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1685 (21)
//         004b0c49     MOV        this,dword ptr [EDI]
//         004b0c4b     PUSH       -0x1
//                              language.dll match for 0x775a: "Click to set one or more cust
//         004b0c4d     PUSH       offset DAT_fffffff8
//         004b0c52     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b0c57     MOV        EDI,EBX
//         004b0c59     MOV        EBP,0x5
//                               LAB_004b0c5e                                                 XREF[1]:     004b0c6c(j)
//                              scr_sed2.cpp:1687 (16)
//         004b0c5e     MOV        this,dword ptr [EDI]
//         004b0c60     PUSH       0x5
//         004b0c62     PUSH       EBX=>DAT_fffffff8
//         004b0c63     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004b0c68     ADD        EDI,0x4
//         004b0c6b     DEC        EBP
//         004b0c6c     JNZ        LAB_004b0c5e
//                              scr_sed2.cpp:1688 (11)
//         004b0c6e     MOV        this,dword ptr [ESI + 0x6e4]
//         004b0c74     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              scr_sed2.cpp:1690 (34)
//         004b0c79     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0c7f     LEA        this,[ESI + 0x6f4]
//                              language.dll match for 0x10ea: "Score"
//         004b0c85     PUSH       0x10ea
//         004b0c8a     PUSH       this=>DAT_fffffff8
//         004b0c8b     PUSH       EDX=>DAT_fffffff4
//         004b0c8c     MOV        this,ESI
//         004b0c8e     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0c93     TEST       EAX,EAX
//         004b0c95     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1692 (29)
//         004b0c9b     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0ca1     LEA        EDI,[ESI + 0x6f8]
//         004b0ca7     PUSH       EDI
//         004b0ca8     PUSH       EAX=>DAT_fffffff8
//         004b0ca9     MOV        this,ESI
//         004b0cab     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0cb0     TEST       EAX,EAX
//         004b0cb2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1693 (14)
//         004b0cb8     MOV        this,dword ptr [EDI]
//         004b0cba     PUSH       -0x1
//                              language.dll match for 0x775b: "Select the score for the game
//         004b0cbc     PUSH       offset DAT_fffffff8
//         004b0cc1     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1694 (7)
//         004b0cc6     MOV        this,dword ptr [EDI]
//         004b0cc8     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:1695 (17)
//         004b0ccd     MOV        this,dword ptr [EDI]
//         004b0ccf     PUSH       0xbb8
//         004b0cd4     PUSH       s_3000                                           = "3000"
//         004b0cd9     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1696 (17)
//         004b0cde     MOV        this,dword ptr [EDI]
//         004b0ce0     PUSH       0xa8c
//         004b0ce5     PUSH       s_2700                                           = "2700"
//         004b0cea     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1697 (17)
//         004b0cef     MOV        this,dword ptr [EDI]
//                              language.dll match for 0x960: "********** TRIBE ERRORS ******
//         004b0cf1     PUSH       0x960
//         004b0cf6     PUSH       s_2400                                           = "2400"
//         004b0cfb     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1698 (17)
//         004b0d00     MOV        this,dword ptr [EDI]
//         004b0d02     PUSH       0x834
//         004b0d07     PUSH       s_2100                                           = "2100"
//         004b0d0c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1699 (17)
//         004b0d11     MOV        this,dword ptr [EDI]
//         004b0d13     PUSH       0x708
//         004b0d18     PUSH       s_1800                                           = "1800"
//         004b0d1d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1700 (17)
//         004b0d22     MOV        this,dword ptr [EDI]
//         004b0d24     PUSH       0x5dc
//         004b0d29     PUSH       s_1500                                           = "1500"
//         004b0d2e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1701 (17)
//         004b0d33     MOV        this,dword ptr [EDI]
//                              language.dll match for 0x4b0: "Ready"
//         004b0d35     PUSH       0x4b0
//         004b0d3a     PUSH       s_1200                                           = "1200"
//         004b0d3f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1702 (17)
//         004b0d44     MOV        this,dword ptr [EDI]
//         004b0d46     PUSH       0x384
//         004b0d4b     PUSH       s_900                                            = "900"
//         004b0d50     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1703 (17)
//         004b0d55     MOV        this,dword ptr [EDI]
//         004b0d57     PUSH       0x320
//         004b0d5c     PUSH       s_800                                            = "800"
//         004b0d61     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1704 (17)
//         004b0d66     MOV        this,dword ptr [EDI]
//         004b0d68     PUSH       0x2bc
//         004b0d6d     PUSH       s_700                                            = "700"
//         004b0d72     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1705 (17)
//         004b0d77     MOV        this,dword ptr [EDI]
//         004b0d79     PUSH       0x258
//         004b0d7e     PUSH       s_600                                            = "600"
//         004b0d83     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1706 (17)
//         004b0d88     MOV        this,dword ptr [EDI]
//         004b0d8a     PUSH       0x1f4
//         004b0d8f     PUSH       s_500                                            = "500"
//         004b0d94     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1707 (17)
//         004b0d99     MOV        this,dword ptr [EDI]
//         004b0d9b     PUSH       0x190
//         004b0da0     PUSH       s_400                                            = "400"
//         004b0da5     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1708 (17)
//         004b0daa     MOV        this,dword ptr [EDI]
//         004b0dac     PUSH       0x12c
//         004b0db1     PUSH       s_300                                            = "300"
//         004b0db6     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:1710 (34)
//         004b0dbb     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0dc1     LEA        this,[ESI + 0x6fc]
//                              language.dll match for 0x10e9: "Time Limit"
//         004b0dc7     PUSH       0x10e9
//         004b0dcc     PUSH       this=>DAT_fffffff8
//         004b0dcd     PUSH       EDX=>DAT_fffffff4
//         004b0dce     MOV        this,ESI
//         004b0dd0     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b0dd5     TEST       EAX,EAX
//         004b0dd7     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1712 (29)
//         004b0ddd     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0de3     LEA        EDI,[ESI + 0x700]
//         004b0de9     PUSH       EDI
//         004b0dea     PUSH       EAX=>DAT_fffffff8
//         004b0deb     MOV        this,ESI
//         004b0ded     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0df2     TEST       EAX,EAX
//         004b0df4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1713 (14)
//         004b0dfa     MOV        this,dword ptr [EDI]
//         004b0dfc     PUSH       -0x1
//                              language.dll match for 0x775c: "Select the time limit for the
//         004b0dfe     PUSH       offset DAT_fffffff8
//         004b0e03     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1714 (7)
//         004b0e08     MOV        this,dword ptr [EDI]
//         004b0e0a     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:1715 (17)
//         004b0e0f     MOV        this,dword ptr [EDI]
//         004b0e11     PUSH       0x3a98
//                              language.dll match for 0x2634: "15,000 years (2:00 hr)"
//         004b0e16     PUSH       offset DAT_fffffff8
//         004b0e1b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1716 (17)
//         004b0e20     MOV        this,dword ptr [EDI]
//         004b0e22     PUSH       0x32c8
//                              language.dll match for 0x2635: "13,000 years (1:45 hr)"
//         004b0e27     PUSH       offset DAT_fffffff8
//         004b0e2c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1717 (17)
//         004b0e31     MOV        this,dword ptr [EDI]
//         004b0e33     PUSH       0x2af8
//                              language.dll match for 0x2636: "11,000 years (1:30 hr)"
//         004b0e38     PUSH       offset DAT_fffffff8
//         004b0e3d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1718 (17)
//         004b0e42     MOV        this,dword ptr [EDI]
//         004b0e44     PUSH       0x2328
//                              language.dll match for 0x2637: "9,000 years (1:15 hr)"
//         004b0e49     PUSH       offset DAT_fffffff8
//         004b0e4e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1719 (17)
//         004b0e53     MOV        this,dword ptr [EDI]
//         004b0e55     PUSH       0x1b58
//                              language.dll match for 0x2638: "7,000 years (60 min)"
//         004b0e5a     PUSH       offset DAT_fffffff8
//         004b0e5f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1720 (17)
//         004b0e64     MOV        this,dword ptr [EDI]
//         004b0e66     PUSH       0x1388
//                              language.dll match for 0x2639: "5,000 years (40 min)"
//         004b0e6b     PUSH       offset DAT_fffffff8
//         004b0e70     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:1721 (28)
//         004b0e75     MOV        this,dword ptr [EDI]
//         004b0e77     PUSH       0xbb8
//                              language.dll match for 0x263a: "3,000 years (25 min)"
//         004b0e7c     PUSH       offset DAT_fffffff8
//         004b0e81     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//         004b0e86     MOV        EDI,0x1
//         004b0e8b     LEA        EBX,[ESI + 0x704]
//                               LAB_004b0e91                                                 XREF[1]:     004b0f26(j)
//                              scr_sed2.cpp:1729 (19)
//         004b0e91     PUSH       EDI
//         004b0e92     LEA        this,[ESP + 0x54]
//         004b0e96     PUSH       s_%d                                             = 6425h
//         004b0e9b     PUSH       this=>DAT_fffffff4
//         004b0e9c     CALL       sprintf                                          undefined sprintf()
//         004b0ea1     ADD        ESP,0xc
//                              scr_sed2.cpp:1730 (22)
//         004b0ea4     LEA        EDX,[ESP + 0x140]
//         004b0eab     PUSH       EDI
//         004b0eac     PUSH       s_<%d>                                           = "<%d>"
//         004b0eb1     PUSH       EDX=>DAT_fffffff4
//         004b0eb2     CALL       sprintf                                          undefined sprintf()
//         004b0eb7     ADD        ESP,0xc
//                              scr_sed2.cpp:1731 (19)
//         004b0eba     LEA        EAX,[ESP + 0x3c]
//         004b0ebe     PUSH       EDI
//         004b0ebf     PUSH       s_%d*                                            = "%d*"
//         004b0ec4     PUSH       EAX=>DAT_fffffff4
//         004b0ec5     CALL       sprintf                                          undefined sprintf()
//         004b0eca     ADD        ESP,0xc
//                              scr_sed2.cpp:1732 (19)
//         004b0ecd     LEA        this,[ESP + 0x28]
//         004b0ed1     PUSH       EDI
//         004b0ed2     PUSH       s_<%d*>                                          = "<%d*>"
//         004b0ed7     PUSH       this=>DAT_fffffff4
//         004b0ed8     CALL       sprintf                                          undefined sprintf()
//         004b0edd     ADD        ESP,0xc
//                              scr_sed2.cpp:1733 (46)
//         004b0ee0     LEA        EDX,[ESP + 0x28]
//         004b0ee4     LEA        EAX,[ESP + 0x3c]
//         004b0ee8     LEA        this,[ESP + 0x140]
//         004b0eef     PUSH       EDX
//         004b0ef0     PUSH       EAX=>DAT_fffffff8
//         004b0ef1     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0ef7     LEA        EDX,[ESP + 0x58]
//         004b0efb     PUSH       this=>DAT_fffffff4
//         004b0efc     PUSH       EDX=>DAT_fffffff0
//         004b0efd     PUSH       EBX
//         004b0efe     PUSH       EAX
//         004b0eff     MOV        this,ESI
//         004b0f01     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004b0f06     TEST       EAX,EAX
//         004b0f08     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1734 (30)
//         004b0f0e     MOV        this,dword ptr [EBX]
//         004b0f10     PUSH       -0x1
//                              language.dll match for 0x7712: "Click the number of the victo
//         004b0f12     PUSH       offset DAT_fffffff8
//         004b0f17     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b0f1c     ADD        EBX,0x4
//         004b0f1f     INC        EDI
//         004b0f20     LEA        this,[EDI + -0x1]
//         004b0f23     CMP        this,0xc
//         004b0f26     JL         LAB_004b0e91
//                              scr_sed2.cpp:1737 (29)
//         004b0f2c     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0f32     LEA        EAX,[ESI + 0x734]
//         004b0f38     PUSH       EAX
//         004b0f39     PUSH       EDX=>DAT_fffffff8
//         004b0f3a     MOV        this,ESI
//         004b0f3c     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0f41     TEST       EAX,EAX
//         004b0f43     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1738 (29)
//         004b0f49     LEA        EAX,[ESI + 0x738]
//         004b0f4f     MOV        this,ESI
//         004b0f51     PUSH       EAX
//         004b0f52     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0f58     PUSH       EAX=>DAT_fffffff8
//         004b0f59     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0f5e     TEST       EAX,EAX
//         004b0f60     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1739 (29)
//         004b0f66     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0f6c     LEA        EAX,[ESI + 0x73c]
//         004b0f72     PUSH       EAX
//         004b0f73     PUSH       this=>DAT_fffffff8
//         004b0f74     MOV        this,ESI
//         004b0f76     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0f7b     TEST       EAX,EAX
//         004b0f7d     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1740 (29)
//         004b0f83     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0f89     LEA        EAX,[ESI + 0x740]
//         004b0f8f     PUSH       EAX
//         004b0f90     PUSH       EDX=>DAT_fffffff8
//         004b0f91     MOV        this,ESI
//         004b0f93     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0f98     TEST       EAX,EAX
//         004b0f9a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1741 (29)
//         004b0fa0     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b0fa6     LEA        EBP,[ESI + 0x744]
//         004b0fac     PUSH       EBP
//         004b0fad     PUSH       EAX=>DAT_fffffff8
//         004b0fae     MOV        this,ESI
//         004b0fb0     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0fb5     TEST       EAX,EAX
//         004b0fb7     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1742 (29)
//         004b0fbd     MOV        this,dword ptr [ESI + 0x4d4]
//         004b0fc3     LEA        EBX,[ESI + 0x748]
//         004b0fc9     PUSH       EBX
//         004b0fca     PUSH       this=>DAT_fffffff8
//         004b0fcb     MOV        this,ESI
//         004b0fcd     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0fd2     TEST       EAX,EAX
//         004b0fd4     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1743 (29)
//         004b0fda     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b0fe0     LEA        EDI,[ESI + 0x74c]
//         004b0fe6     PUSH       EDI
//         004b0fe7     PUSH       EDX=>DAT_fffffff8
//         004b0fe8     MOV        this,ESI
//         004b0fea     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b0fef     TEST       EAX,EAX
//         004b0ff1     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1744 (18)
//         004b0ff7     MOV        this,dword ptr [ESI + 0x734]
//         004b0ffd     PUSH       -0x1
//                              language.dll match for 0x7716: "Select the victory condition."
//         004b0fff     PUSH       offset DAT_fffffff8
//         004b1004     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1745 (18)
//         004b1009     MOV        this,dword ptr [ESI + 0x738]
//         004b100f     PUSH       -0x1
//                              language.dll match for 0x7714: "Select a unit."
//         004b1011     PUSH       offset DAT_fffffff8
//         004b1016     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1746 (18)
//         004b101b     MOV        this,dword ptr [ESI + 0x73c]
//         004b1021     PUSH       -0x1
//                              language.dll match for 0x7713: "Select the player to customiz
//         004b1023     PUSH       offset DAT_fffffff8
//         004b1028     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1747 (14)
//         004b102d     MOV        this,dword ptr [EBX]
//         004b102f     PUSH       -0x1
//                              language.dll match for 0x7715: "Select the age."
//         004b1031     PUSH       offset DAT_fffffff8
//         004b1036     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1749 (18)
//         004b103b     MOV        this,dword ptr [ESI + 0x740]
//         004b1041     PUSH       -0x1
//                              language.dll match for 0x7760: "Select which enemy player."
//         004b1043     PUSH       offset DAT_fffffff8
//         004b1048     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1750 (15)
//         004b104d     MOV        this,dword ptr [EBP]
//         004b1050     PUSH       -0x1
//                              language.dll match for 0x7761: "Select the attribute to achie
//         004b1052     PUSH       offset DAT_fffffff8
//         004b1057     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1751 (14)
//         004b105c     MOV        this,dword ptr [EDI]
//         004b105e     PUSH       -0x1
//                              language.dll match for 0x7762: "Select the technology to achi
//         004b1060     PUSH       offset DAT_fffffff8
//         004b1065     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1753 (34)
//         004b106a     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1070     LEA        EAX,[ESI + 0x75c]
//                              language.dll match for 0x2870: "Victory Condition"
//         004b1076     PUSH       0x2870
//         004b107b     PUSH       EAX=>DAT_fffffff8
//         004b107c     PUSH       this=>DAT_fffffff4
//         004b107d     MOV        this,ESI
//         004b107f     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1084     TEST       EAX,EAX
//         004b1086     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1754 (34)
//         004b108c     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1092     LEA        EDX,[ESI + 0x760]
//                              language.dll match for 0x2871: "Victory Type"
//         004b1098     PUSH       0x2871
//         004b109d     PUSH       EDX=>DAT_fffffff8
//         004b109e     PUSH       EAX=>DAT_fffffff4
//         004b109f     MOV        this,ESI
//         004b10a1     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b10a6     TEST       EAX,EAX
//         004b10a8     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1756 (36)
//         004b10ae     MOV        this,dword ptr [ESI + 0x4d4]
//         004b10b4     LEA        EBP,[ESI + 0x750]
//         004b10ba     PUSH       0x0
//                              language.dll match for 0x2872: "Set Object"
//         004b10bc     PUSH       offset DAT_fffffff8
//         004b10c1     PUSH       EBP=>DAT_fffffff4
//         004b10c2     PUSH       this=>DAT_fffffff0
//         004b10c3     MOV        this,ESI
//         004b10c5     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004b10ca     TEST       EAX,EAX
//         004b10cc     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1757 (36)
//         004b10d2     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b10d8     LEA        EBX,[ESI + 0x754]
//         004b10de     PUSH       0x0
//                              language.dll match for 0x2873: "Set Destination"
//         004b10e0     PUSH       offset DAT_fffffff8
//         004b10e5     PUSH       EBX=>DAT_fffffff4
//         004b10e6     PUSH       EDX=>DAT_fffffff0
//         004b10e7     MOV        this,ESI
//         004b10e9     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004b10ee     TEST       EAX,EAX
//         004b10f0     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1758 (36)
//         004b10f6     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b10fc     LEA        EDI,[ESI + 0x758]
//         004b1102     PUSH       0x0
//                              language.dll match for 0x2874: "Go to Destination"
//         004b1104     PUSH       offset DAT_fffffff8
//         004b1109     PUSH       EDI=>DAT_fffffff4
//         004b110a     PUSH       EAX=>DAT_fffffff0
//         004b110b     MOV        this,ESI
//         004b110d     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
//         004b1112     TEST       EAX,EAX
//         004b1114     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1759 (15)
//         004b111a     MOV        this,dword ptr [EBP]
//         004b111d     PUSH       -0x1
//                              language.dll match for 0x7717: "Click here, and then click a
//         004b111f     PUSH       offset DAT_fffffff8
//         004b1124     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1760 (14)
//         004b1129     MOV        this,dword ptr [EBX]
//         004b112b     PUSH       -0x1
//                              language.dll match for 0x7718: "Click here, and then click a
//         004b112d     PUSH       offset DAT_fffffff8
//         004b1132     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1761 (14)
//         004b1137     MOV        this,dword ptr [EDI]
//         004b1139     PUSH       -0x1
//                              language.dll match for 0x7719: "Click to display the destinat
//         004b113b     PUSH       offset DAT_fffffff8
//         004b1140     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1764 (34)
//         004b1145     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b114b     LEA        this,[ESI + 0x764]
//                              language.dll match for 0x2875: "Quantity"
//         004b1151     PUSH       0x2875
//         004b1156     PUSH       this=>DAT_fffffff8
//         004b1157     PUSH       EDX=>DAT_fffffff4
//         004b1158     MOV        this,ESI
//         004b115a     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b115f     TEST       EAX,EAX
//         004b1161     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1765 (34)
//         004b1167     MOV        this,dword ptr [ESI + 0x4d4]
//         004b116d     LEA        EAX,[ESI + 0x768]
//                              language.dll match for 0x2876: "Which Player"
//         004b1173     PUSH       0x2876
//         004b1178     PUSH       EAX=>DAT_fffffff8
//         004b1179     PUSH       this=>DAT_fffffff4
//         004b117a     MOV        this,ESI
//         004b117c     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1181     TEST       EAX,EAX
//         004b1183     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1767 (42)
//         004b1189     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b118f     PUSH       0x0
//         004b1191     PUSH       0x0=>DAT_fffffff8
//         004b1193     PUSH       offset DAT_fffffff4
//         004b1195     PUSH       offset DAT_fffffff0
//         004b1197     LEA        EDX,[ESI + 0x76c]
//         004b119d     PUSH       s_0                                              = "0"
//         004b11a2     PUSH       EDX
//         004b11a3     PUSH       EAX
//         004b11a4     MOV        this,ESI
//         004b11a6     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b11ab     TEST       EAX,EAX
//         004b11ad     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1773 (10)
//         004b11b3     LEA        EBP,[ESI + 0x778]
//         004b11b9     XOR        EDI,EDI
//         004b11bb     MOV        EBX,EBP
//                               LAB_004b11bd                                                 XREF[1]:     004b11db(j)
//                              scr_sed2.cpp:1774 (32)
//         004b11bd     MOV        this,dword ptr [ESI + 0x4d4]
//         004b11c3     PUSH       EBX
//         004b11c4     PUSH       this=>DAT_fffffff8
//         004b11c5     MOV        this,ESI
//         004b11c7     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b11cc     TEST       EAX,EAX
//         004b11ce     JZ         LAB_004b1a29
//         004b11d4     INC        EDI
//         004b11d5     ADD        EBX,0x4
//         004b11d8     CMP        EDI,0x5
//         004b11db     JL         LAB_004b11bd
//                              scr_sed2.cpp:1776 (25)
//         004b11dd     MOV        this,dword ptr [EBP]
//         004b11e0     PUSH       -0x1
//                              language.dll match for 0x771c: "Type the scenario instruction
//         004b11e2     PUSH       offset DAT_fffffff8
//         004b11e7     MOV        dword ptr [ESI + 0x7a0],0x0
//         004b11f1     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1777 (18)
//         004b11f6     MOV        this,dword ptr [ESI + 0x77c]
//         004b11fc     PUSH       -0x1
//                              language.dll match for 0x771d: "Type the hints text for the s
//         004b11fe     PUSH       offset DAT_fffffff8
//         004b1203     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1778 (18)
//         004b1208     MOV        this,dword ptr [ESI + 0x780]
//         004b120e     PUSH       -0x1
//                              language.dll match for 0x771e: "Type the victory message that
//         004b1210     PUSH       offset DAT_fffffff8
//         004b1215     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1779 (18)
//         004b121a     MOV        this,dword ptr [ESI + 0x784]
//         004b1220     PUSH       -0x1
//                              language.dll match for 0x771f: "Type the loss message that ap
//         004b1222     PUSH       offset DAT_fffffff8
//         004b1227     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1780 (18)
//         004b122c     MOV        this,dword ptr [ESI + 0x788]
//         004b1232     PUSH       -0x1
//                              language.dll match for 0x7720: "Type historical background in
//         004b1234     PUSH       offset DAT_fffffff8
//         004b1239     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1782 (34)
//         004b123e     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1244     LEA        EDX,[ESI + 0x78c]
//                              language.dll match for 0x2a36: "Scenario Instructions"
//         004b124a     PUSH       0x2a36
//         004b124f     PUSH       EDX=>DAT_fffffff8
//         004b1250     PUSH       EAX=>DAT_fffffff4
//         004b1251     MOV        this,ESI
//         004b1253     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1258     TEST       EAX,EAX
//         004b125a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1783 (34)
//         004b1260     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1266     LEA        this,[ESI + 0x790]
//                              language.dll match for 0x2a37: "Hints"
//         004b126c     PUSH       0x2a37
//         004b1271     PUSH       this=>DAT_fffffff8
//         004b1272     PUSH       EDX=>DAT_fffffff4
//         004b1273     MOV        this,ESI
//         004b1275     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b127a     TEST       EAX,EAX
//         004b127c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1784 (34)
//         004b1282     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1288     LEA        EAX,[ESI + 0x794]
//                              language.dll match for 0x2a38: "Victory"
//         004b128e     PUSH       0x2a38
//         004b1293     PUSH       EAX=>DAT_fffffff8
//         004b1294     PUSH       this=>DAT_fffffff4
//         004b1295     MOV        this,ESI
//         004b1297     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b129c     TEST       EAX,EAX
//         004b129e     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1785 (34)
//         004b12a4     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b12aa     LEA        EDX,[ESI + 0x798]
//                              language.dll match for 0x2a39: "Loss"
//         004b12b0     PUSH       0x2a39
//         004b12b5     PUSH       EDX=>DAT_fffffff8
//         004b12b6     PUSH       EAX=>DAT_fffffff4
//         004b12b7     MOV        this,ESI
//         004b12b9     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b12be     TEST       EAX,EAX
//         004b12c0     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1786 (34)
//         004b12c6     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b12cc     LEA        this,[ESI + 0x79c]
//                              language.dll match for 0x2a31: "History"
//         004b12d2     PUSH       0x2a31
//         004b12d7     PUSH       this=>DAT_fffffff8
//         004b12d8     PUSH       EDX=>DAT_fffffff4
//         004b12d9     MOV        this,ESI
//         004b12db     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b12e0     TEST       EAX,EAX
//         004b12e2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1787 (7)
//         004b12e8     MOV        EDI,EBP
//         004b12ea     MOV        EBX,0x5
//                               LAB_004b12ef                                                 XREF[1]:     004b12fd(j)
//                              scr_sed2.cpp:1788 (16)
//         004b12ef     MOV        this,dword ptr [EDI]
//         004b12f1     PUSH       0x5
//         004b12f3     PUSH       EBP=>DAT_fffffff8
//         004b12f4     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004b12f9     ADD        EDI,0x4
//         004b12fc     DEC        EBX
//         004b12fd     JNZ        LAB_004b12ef
//                              scr_sed2.cpp:1791 (45)
//         004b12ff     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1305     PUSH       0x1
//         004b1307     PUSH       offset DAT_fffffff8
//         004b1309     PUSH       offset DAT_fffffff4
//         004b130b     LEA        EDI,[ESI + 0x774]
//         004b1311     PUSH       offset DAT_fffffff0
//         004b1316     PUSH       s_                                               = ""
//         004b131b     PUSH       EDI
//         004b131c     PUSH       EAX
//         004b131d     MOV        this,ESI
//         004b131f     CALL       TRIBE_Screen_Sed::create_edit                    int create_edit(TRIBE_Screen_Sed * this, TPan
//         004b1324     TEST       EAX,EAX
//         004b1326     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1792 (11)
//         004b132c     MOV        this,dword ptr [EDI]
//         004b132e     PUSH       -0x1
//         004b1330     PUSH       offset DAT_fffffff8
//         004b1332     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1799 (34)
//         004b1337     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b133d     LEA        this,[ESI + 0x7a4]
//                              language.dll match for 0x2af9: "Pre-Game Cinematic"
//         004b1343     PUSH       0x2af9
//         004b1348     PUSH       this=>DAT_fffffff8
//         004b1349     PUSH       EDX=>DAT_fffffff4
//         004b134a     MOV        this,ESI
//         004b134c     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1351     TEST       EAX,EAX
//         004b1353     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1800 (34)
//         004b1359     MOV        this,dword ptr [ESI + 0x4d4]
//         004b135f     LEA        EAX,[ESI + 0x7a8]
//                              language.dll match for 0x2afa: "Victory Cinematic"
//         004b1365     PUSH       0x2afa
//         004b136a     PUSH       EAX=>DAT_fffffff8
//         004b136b     PUSH       this=>DAT_fffffff4
//         004b136c     MOV        this,ESI
//         004b136e     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1373     TEST       EAX,EAX
//         004b1375     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1801 (34)
//         004b137b     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1381     LEA        EDX,[ESI + 0x7ac]
//                              language.dll match for 0x2afb: "Loss Cinematic"
//         004b1387     PUSH       0x2afb
//         004b138c     PUSH       EDX=>DAT_fffffff8
//         004b138d     PUSH       EAX=>DAT_fffffff4
//         004b138e     MOV        this,ESI
//         004b1390     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1395     TEST       EAX,EAX
//         004b1397     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1802 (34)
//         004b139d     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b13a3     LEA        this,[ESI + 0x7b0]
//                              language.dll match for 0x2afc: "Scenario Instruction Map"
//         004b13a9     PUSH       0x2afc
//         004b13ae     PUSH       this=>DAT_fffffff8
//         004b13af     PUSH       EDX=>DAT_fffffff4
//         004b13b0     MOV        this,ESI
//         004b13b2     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b13b7     TEST       EAX,EAX
//         004b13b9     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1803 (10)
//         004b13bf     LEA        EBP,[ESI + 0x7b4]
//         004b13c5     XOR        EDI,EDI
//         004b13c7     MOV        EBX,EBP
//                               LAB_004b13c9                                                 XREF[1]:     004b13e7(j)
//                              scr_sed2.cpp:1804 (32)
//         004b13c9     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b13cf     PUSH       EBX
//         004b13d0     PUSH       EAX=>DAT_fffffff8
//         004b13d1     MOV        this,ESI
//         004b13d3     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b13d8     TEST       EAX,EAX
//         004b13da     JZ         LAB_004b1a29
//         004b13e0     INC        EDI
//         004b13e1     ADD        EBX,0x4
//         004b13e4     CMP        EDI,0x4
//         004b13e7     JL         LAB_004b13c9
//                              scr_sed2.cpp:1805 (15)
//         004b13e9     MOV        this,dword ptr [EBP]
//         004b13ec     PUSH       -0x1
//                              language.dll match for 0x7724: "Select the cinematic that pla
//         004b13ee     PUSH       offset DAT_fffffff8
//         004b13f3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1806 (18)
//         004b13f8     MOV        this,dword ptr [ESI + 0x7b8]
//         004b13fe     PUSH       -0x1
//                              language.dll match for 0x7725: "Select the victory cinematic
//         004b1400     PUSH       offset DAT_fffffff8
//         004b1405     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1807 (18)
//         004b140a     MOV        this,dword ptr [ESI + 0x7bc]
//         004b1410     PUSH       -0x1
//                              language.dll match for 0x7726: "Select the loss cinematic tha
//         004b1412     PUSH       offset DAT_fffffff8
//         004b1417     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1808 (18)
//         004b141c     MOV        this,dword ptr [ESI + 0x7c0]
//         004b1422     PUSH       -0x1
//                              language.dll match for 0x7727: "Select the mission briefing m
//         004b1424     PUSH       offset DAT_fffffff8
//         004b1429     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1813 (34)
//         004b142e     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1434     LEA        this,[ESI + 0x7c4]
//                              language.dll match for 0x2604: "Full Tech Tree"
//         004b143a     PUSH       0x2604
//         004b143f     PUSH       this=>DAT_fffffff8
//         004b1440     PUSH       EDX=>DAT_fffffff4
//         004b1441     MOV        this,ESI
//         004b1443     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1448     TEST       EAX,EAX
//         004b144a     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1814 (34)
//         004b1450     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1456     LEA        EAX,[ESI + 0x7d0]
//                              language.dll match for 0x32d7: "Disable Technology"
//         004b145c     PUSH       0x32d7
//         004b1461     PUSH       EAX=>DAT_fffffff8
//         004b1462     PUSH       this=>DAT_fffffff4
//         004b1463     MOV        this,ESI
//         004b1465     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b146a     TEST       EAX,EAX
//         004b146c     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1815 (10)
//         004b1472     LEA        EBP,[ESI + 0x7c8]
//         004b1478     XOR        EDI,EDI
//         004b147a     MOV        EBX,EBP
//                               LAB_004b147c                                                 XREF[1]:     004b149a(j)
//                              scr_sed2.cpp:1816 (32)
//         004b147c     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1482     PUSH       EBX
//         004b1483     PUSH       EDX=>DAT_fffffff8
//         004b1484     MOV        this,ESI
//         004b1486     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b148b     TEST       EAX,EAX
//         004b148d     JZ         LAB_004b1a29
//         004b1493     INC        EDI
//         004b1494     ADD        EBX,0x4
//         004b1497     CMP        EDI,0x1
//         004b149a     JL         LAB_004b147c
//                              scr_sed2.cpp:1817 (15)
//         004b149c     MOV        this,dword ptr [EBP]
//         004b149f     PUSH       -0x1
//                              language.dll match for 0x7729: "If there is a check in the bo
//         004b14a1     PUSH       offset DAT_fffffff8
//         004b14a6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1819 (29)
//         004b14ab     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b14b1     LEA        EDI,[ESI + 0x7cc]
//         004b14b7     PUSH       EDI
//         004b14b8     PUSH       EAX=>DAT_fffffff8
//         004b14b9     MOV        this,ESI
//         004b14bb     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b14c0     TEST       EAX,EAX
//         004b14c2     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1820 (20)
//         004b14c8     MOV        this,dword ptr [EDI]
//         004b14ca     PUSH       -0x1
//                              language.dll match for 0x772b: "Select the player to customiz
//         004b14cc     PUSH       offset DAT_fffffff8
//         004b14d1     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b14d6     LEA        EBP,[ESI + 0x7d4]
//                              scr_sed2.cpp:1822 (4)
//         004b14dc     XOR        EDI,EDI
//         004b14de     MOV        EBX,EBP
//                               LAB_004b14e0                                                 XREF[1]:     004b14fe(j)
//                              scr_sed2.cpp:1823 (32)
//         004b14e0     MOV        this,dword ptr [ESI + 0x4d4]
//         004b14e6     PUSH       EBX
//         004b14e7     PUSH       this=>DAT_fffffff8
//         004b14e8     MOV        this,ESI
//         004b14ea     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b14ef     TEST       EAX,EAX
//         004b14f1     JZ         LAB_004b1a29
//         004b14f7     INC        EDI
//         004b14f8     ADD        EBX,0x4
//         004b14fb     CMP        EDI,0x10
//         004b14fe     JL         LAB_004b14e0
//                              scr_sed2.cpp:1824 (15)
//         004b1500     MOV        this,dword ptr [EBP]
//         004b1503     PUSH       -0x1
//                              language.dll match for 0x772c: "Click to prevent the player f
//         004b1505     PUSH       offset DAT_fffffff8
//         004b150a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1825 (18)
//         004b150f     MOV        this,dword ptr [ESI + 0x7d8]
//         004b1515     PUSH       -0x1
//                              language.dll match for 0x772d: "Click to prevent the player f
//         004b1517     PUSH       offset DAT_fffffff8
//         004b151c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1826 (18)
//         004b1521     MOV        this,dword ptr [ESI + 0x7dc]
//         004b1527     PUSH       -0x1
//                              language.dll match for 0x772e: "Click to prevent the player f
//         004b1529     PUSH       offset DAT_fffffff8
//         004b152e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1827 (18)
//         004b1533     MOV        this,dword ptr [ESI + 0x7e0]
//         004b1539     PUSH       -0x1
//                              language.dll match for 0x772f: "Click to prevent the player f
//         004b153b     PUSH       offset DAT_fffffff8
//         004b1540     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1828 (18)
//         004b1545     MOV        this,dword ptr [ESI + 0x7e4]
//         004b154b     PUSH       -0x1
//                              language.dll match for 0x7730: "Click to prevent the player f
//         004b154d     PUSH       offset DAT_fffffff8
//         004b1552     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1829 (18)
//         004b1557     MOV        this,dword ptr [ESI + 0x7e8]
//         004b155d     PUSH       -0x1
//                              language.dll match for 0x7731: "Click to prevent the player f
//         004b155f     PUSH       offset DAT_fffffff8
//         004b1564     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1830 (18)
//         004b1569     MOV        this,dword ptr [ESI + 0x7ec]
//         004b156f     PUSH       -0x1
//                              language.dll match for 0x7732: "Click to prevent the player f
//         004b1571     PUSH       offset DAT_fffffff8
//         004b1576     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1831 (18)
//         004b157b     MOV        this,dword ptr [ESI + 0x7f0]
//         004b1581     PUSH       -0x1
//                              language.dll match for 0x7733: "Click to prevent the player f
//         004b1583     PUSH       offset DAT_fffffff8
//         004b1588     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1832 (18)
//         004b158d     MOV        this,dword ptr [ESI + 0x7f4]
//         004b1593     PUSH       -0x1
//                              language.dll match for 0x7734: "Click to prevent the player f
//         004b1595     PUSH       offset DAT_fffffff8
//         004b159a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1833 (18)
//         004b159f     MOV        this,dword ptr [ESI + 0x7f8]
//         004b15a5     PUSH       -0x1
//                              language.dll match for 0x7735: "Click to prevent the player f
//         004b15a7     PUSH       offset DAT_fffffff8
//         004b15ac     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1834 (18)
//         004b15b1     MOV        this,dword ptr [ESI + 0x7fc]
//         004b15b7     PUSH       -0x1
//                              language.dll match for 0x7736: "Click to prevent the player f
//         004b15b9     PUSH       offset DAT_fffffff8
//         004b15be     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1835 (18)
//         004b15c3     MOV        this,dword ptr [ESI + 0x800]
//         004b15c9     PUSH       -0x1
//                              language.dll match for 0x7737: "Click to prevent the player f
//         004b15cb     PUSH       offset DAT_fffffff8
//         004b15d0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1836 (18)
//         004b15d5     MOV        this,dword ptr [ESI + 0x804]
//         004b15db     PUSH       -0x1
//                              language.dll match for 0x7738: "Click to prevent the player f
//         004b15dd     PUSH       offset DAT_fffffff8
//         004b15e2     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1837 (18)
//         004b15e7     MOV        this,dword ptr [ESI + 0x808]
//         004b15ed     PUSH       -0x1
//                              language.dll match for 0x7739: "Click to prevent the player f
//         004b15ef     PUSH       offset DAT_fffffff8
//         004b15f4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1838 (18)
//         004b15f9     MOV        this,dword ptr [ESI + 0x80c]
//         004b15ff     PUSH       -0x1
//                              language.dll match for 0x773a: "Click to prevent the player f
//         004b1601     PUSH       offset DAT_fffffff8
//         004b1606     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1839 (18)
//         004b160b     MOV        this,dword ptr [ESI + 0x810]
//         004b1611     PUSH       -0x1
//                              language.dll match for 0x773b: "Click to prevent the player f
//         004b1613     PUSH       offset DAT_fffffff8
//         004b1618     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1842 (34)
//         004b161d     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1623     LEA        EDX,[ESI + 0x814]
//                              language.dll match for 0x32c9: "Granary"
//         004b1629     PUSH       0x32c9
//         004b162e     PUSH       EDX=>DAT_fffffff8
//         004b162f     PUSH       EAX=>DAT_fffffff4
//         004b1630     MOV        this,ESI
//         004b1632     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1637     TEST       EAX,EAX
//         004b1639     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1843 (34)
//         004b163f     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1645     LEA        this,[ESI + 0x818]
//                              language.dll match for 0x32ca: "Storage Pit"
//         004b164b     PUSH       0x32ca
//         004b1650     PUSH       this=>DAT_fffffff8
//         004b1651     PUSH       EDX=>DAT_fffffff4
//         004b1652     MOV        this,ESI
//         004b1654     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1659     TEST       EAX,EAX
//         004b165b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1844 (34)
//         004b1661     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1667     LEA        EAX,[ESI + 0x81c]
//                              language.dll match for 0x32cb: "Dock"
//         004b166d     PUSH       0x32cb
//         004b1672     PUSH       EAX=>DAT_fffffff8
//         004b1673     PUSH       this=>DAT_fffffff4
//         004b1674     MOV        this,ESI
//         004b1676     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b167b     TEST       EAX,EAX
//         004b167d     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1845 (34)
//         004b1683     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1689     LEA        EDX,[ESI + 0x820]
//                              language.dll match for 0x32cc: "Barracks"
//         004b168f     PUSH       0x32cc
//         004b1694     PUSH       EDX=>DAT_fffffff8
//         004b1695     PUSH       EAX=>DAT_fffffff4
//         004b1696     MOV        this,ESI
//         004b1698     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b169d     TEST       EAX,EAX
//         004b169f     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1846 (34)
//         004b16a5     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b16ab     LEA        this,[ESI + 0x824]
//                              language.dll match for 0x32cd: "Market"
//         004b16b1     PUSH       0x32cd
//         004b16b6     PUSH       this=>DAT_fffffff8
//         004b16b7     PUSH       EDX=>DAT_fffffff4
//         004b16b8     MOV        this,ESI
//         004b16ba     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b16bf     TEST       EAX,EAX
//         004b16c1     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1847 (34)
//         004b16c7     MOV        this,dword ptr [ESI + 0x4d4]
//         004b16cd     LEA        EAX,[ESI + 0x828]
//                              language.dll match for 0x32ce: "Archery"
//         004b16d3     PUSH       0x32ce
//         004b16d8     PUSH       EAX=>DAT_fffffff8
//         004b16d9     PUSH       this=>DAT_fffffff4
//         004b16da     MOV        this,ESI
//         004b16dc     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b16e1     TEST       EAX,EAX
//         004b16e3     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1848 (34)
//         004b16e9     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b16ef     LEA        EDX,[ESI + 0x82c]
//                              language.dll match for 0x32cf: "Stable"
//         004b16f5     PUSH       0x32cf
//         004b16fa     PUSH       EDX=>DAT_fffffff8
//         004b16fb     PUSH       EAX=>DAT_fffffff4
//         004b16fc     MOV        this,ESI
//         004b16fe     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1703     TEST       EAX,EAX
//         004b1705     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1849 (34)
//         004b170b     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1711     LEA        this,[ESI + 0x830]
//                              language.dll match for 0x32d0: "Temple"
//         004b1717     PUSH       0x32d0
//         004b171c     PUSH       this=>DAT_fffffff8
//         004b171d     PUSH       EDX=>DAT_fffffff4
//         004b171e     MOV        this,ESI
//         004b1720     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1725     TEST       EAX,EAX
//         004b1727     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1850 (34)
//         004b172d     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1733     LEA        EAX,[ESI + 0x834]
//                              language.dll match for 0x32d1: "Govt Ctr"
//         004b1739     PUSH       0x32d1
//         004b173e     PUSH       EAX=>DAT_fffffff8
//         004b173f     PUSH       this=>DAT_fffffff4
//         004b1740     MOV        this,ESI
//         004b1742     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1747     TEST       EAX,EAX
//         004b1749     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1851 (34)
//         004b174f     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1755     LEA        EDX,[ESI + 0x838]
//                              language.dll match for 0x32d2: "Siege Wkshop"
//         004b175b     PUSH       0x32d2
//         004b1760     PUSH       EDX=>DAT_fffffff8
//         004b1761     PUSH       EAX=>DAT_fffffff4
//         004b1762     MOV        this,ESI
//         004b1764     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1769     TEST       EAX,EAX
//         004b176b     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1852 (34)
//         004b1771     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1777     LEA        this,[ESI + 0x83c]
//                              language.dll match for 0x32d3: "Academy"
//         004b177d     PUSH       0x32d3
//         004b1782     PUSH       this=>DAT_fffffff8
//         004b1783     PUSH       EDX=>DAT_fffffff4
//         004b1784     MOV        this,ESI
//         004b1786     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b178b     TEST       EAX,EAX
//         004b178d     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1853 (34)
//         004b1793     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1799     LEA        EAX,[ESI + 0x840]
//                              language.dll match for 0x32d4: "Tool Age"
//         004b179f     PUSH       0x32d4
//         004b17a4     PUSH       EAX=>DAT_fffffff8
//         004b17a5     PUSH       this=>DAT_fffffff4
//         004b17a6     MOV        this,ESI
//         004b17a8     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b17ad     TEST       EAX,EAX
//         004b17af     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1854 (34)
//         004b17b5     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b17bb     LEA        EDX,[ESI + 0x844]
//                              language.dll match for 0x32d5: "Bronze Age"
//         004b17c1     PUSH       0x32d5
//         004b17c6     PUSH       EDX=>DAT_fffffff8
//         004b17c7     PUSH       EAX=>DAT_fffffff4
//         004b17c8     MOV        this,ESI
//         004b17ca     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b17cf     TEST       EAX,EAX
//         004b17d1     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1855 (34)
//         004b17d7     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b17dd     LEA        this,[ESI + 0x848]
//                              language.dll match for 0x32d6: "Iron Age"
//         004b17e3     PUSH       0x32d6
//         004b17e8     PUSH       this=>DAT_fffffff8
//         004b17e9     PUSH       EDX=>DAT_fffffff4
//         004b17ea     MOV        this,ESI
//         004b17ec     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b17f1     TEST       EAX,EAX
//         004b17f3     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1856 (34)
//         004b17f9     MOV        this,dword ptr [ESI + 0x4d4]
//         004b17ff     LEA        EAX,[ESI + 0x84c]
//                              language.dll match for 0x32d8: "Town Center"
//         004b1805     PUSH       0x32d8
//         004b180a     PUSH       EAX=>DAT_fffffff8
//         004b180b     PUSH       this=>DAT_fffffff4
//         004b180c     MOV        this,ESI
//         004b180e     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1813     TEST       EAX,EAX
//         004b1815     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1857 (34)
//         004b181b     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1821     LEA        EDX,[ESI + 0x850]
//                              language.dll match for 0x32d9: "Wonder"
//         004b1827     PUSH       0x32d9
//         004b182c     PUSH       EDX=>DAT_fffffff8
//         004b182d     PUSH       EAX=>DAT_fffffff4
//         004b182e     MOV        this,ESI
//         004b1830     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b1835     TEST       EAX,EAX
//         004b1837     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1863 (11)
//         004b183d     XOR        EAX,EAX
//         004b183f     LEA        EBX,[ESI + 0x874]
//                               LAB_004b1845                                                 XREF[1]:     004b187f(j)
//         004b1845     LEA        EDI,[EAX + 0x1]
//                              scr_sed2.cpp:1865 (16)
//         004b1848     LEA        this,[ESP + 0x50]
//         004b184c     PUSH       EDI
//         004b184d     PUSH       s_%d                                             = 6425h
//         004b1852     PUSH       this=>DAT_fffffff4
//         004b1853     CALL       sprintf                                          undefined sprintf()
//                              scr_sed2.cpp:1866 (41)
//         004b1858     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b185e     ADD        ESP,0xc
//         004b1861     LEA        EDX,[ESP + 0x50]
//         004b1865     MOV        this,ESI
//         004b1867     PUSH       EDX
//         004b1868     PUSH       EBX=>DAT_fffffff8
//         004b1869     PUSH       EAX=>DAT_fffffff4
//         004b186a     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b186f     TEST       EAX,EAX
//         004b1871     JZ         LAB_004b1a29
//         004b1877     MOV        EAX,EDI
//         004b1879     ADD        EBX,0x4
//         004b187c     CMP        EAX,0x8
//         004b187f     JL         LAB_004b1845
//                              scr_sed2.cpp:1868 (29)
//         004b1881     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1887     LEA        EDI,[ESI + 0x894]
//         004b188d     PUSH       EDI
//         004b188e     PUSH       this=>DAT_fffffff8
//         004b188f     MOV        this,ESI
//         004b1891     CALL       TRIBE_Screen_Sed::create_drop_down               int create_drop_down(TRIBE_Screen_Sed * this,
//         004b1896     TEST       EAX,EAX
//         004b1898     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1869 (20)
//         004b189e     MOV        this,dword ptr [EDI]
//         004b18a0     PUSH       -0x1
//                              language.dll match for 0x773d: "Select the player to customiz
//         004b18a2     PUSH       offset DAT_fffffff8
//         004b18a7     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b18ac     LEA        EDX,[ESI + 0x908]
//                              scr_sed2.cpp:1871 (18)
//         004b18b2     MOV        dword ptr [ESP + 0x10],0x0
//         004b18ba     MOV        dword ptr [ESP + 0x14],EDX
//         004b18be     LEA        EDI,[ESI + 0x8a8]
//                               LAB_004b18c4                                                 XREF[1]:     004b19a3(j)
//                              scr_sed2.cpp:1873 (23)
//         004b18c4     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b18ca     PUSH       EDI
//         004b18cb     PUSH       EAX=>DAT_fffffff8
//         004b18cc     MOV        this,ESI
//         004b18ce     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b18d3     TEST       EAX,EAX
//         004b18d5     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1874 (14)
//         004b18db     MOV        this,dword ptr [EDI]
//         004b18dd     PUSH       -0x1
//                              language.dll match for 0x773f: "Click to set the player's dip
//         004b18df     PUSH       offset DAT_fffffff8
//         004b18e4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1875 (26)
//         004b18e9     MOV        this,dword ptr [ESI + 0x4d4]
//         004b18ef     LEA        EBX,[EDI + 0x4]
//         004b18f2     PUSH       EBX
//         004b18f3     PUSH       this=>DAT_fffffff8
//         004b18f4     MOV        this,ESI
//         004b18f6     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b18fb     TEST       EAX,EAX
//         004b18fd     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1876 (14)
//         004b1903     MOV        this,dword ptr [EBX]
//         004b1905     PUSH       -0x1
//                              language.dll match for 0x7740: "Click to set the player's dip
//                              language.dll match for 0x7740: "Click to set the player's dip
//         004b1907     PUSH       offset DAT_fffffff8
//         004b190c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1877 (26)
//         004b1911     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1917     LEA        EBP,[EDI + 0x8]
//         004b191a     PUSH       EBP
//         004b191b     PUSH       EDX=>DAT_fffffff8
//         004b191c     MOV        this,ESI
//         004b191e     CALL       TRIBE_Screen_Sed::create_radio_button            int create_radio_button(TRIBE_Screen_Sed * th
//         004b1923     TEST       EAX,EAX
//         004b1925     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1878 (15)
//         004b192b     MOV        this,dword ptr [EBP]
//         004b192e     PUSH       -0x1
//                              language.dll match for 0x7741: "Click to set the player's dip
//         004b1930     PUSH       offset DAT_fffffff8
//         004b1935     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_sed2.cpp:1880 (10)
//         004b193a     MOV        this,dword ptr [EDI]
//         004b193c     PUSH       0x3
//         004b193e     PUSH       EDI=>DAT_fffffff8
//         004b193f     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              scr_sed2.cpp:1881 (10)
//         004b1944     MOV        this,dword ptr [EBX]
//         004b1946     PUSH       0x3
//         004b1948     PUSH       EDI=>DAT_fffffff8
//         004b1949     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              scr_sed2.cpp:1882 (11)
//         004b194e     MOV        this,dword ptr [EBP]
//         004b1951     PUSH       0x3
//         004b1953     PUSH       EDI=>DAT_fffffff8
//         004b1954     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              scr_sed2.cpp:1883 (7)
//         004b1959     MOV        this,dword ptr [EBX]
//         004b195b     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              scr_sed2.cpp:1885 (27)
//         004b1960     MOV        EAX,dword ptr [ESP + 0x14]
//         004b1964     MOV        this,dword ptr [ESI + 0x4d4]
//         004b196a     PUSH       EAX
//         004b196b     PUSH       this=>DAT_fffffff8
//         004b196c     MOV        this,ESI
//         004b196e     CALL       TRIBE_Screen_Sed::create_check_box               int create_check_box(TRIBE_Screen_Sed * this,
//         004b1973     TEST       EAX,EAX
//         004b1975     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1886 (46)
//         004b197b     MOV        EBX,dword ptr [ESP + 0x14]
//         004b197f     PUSH       -0x1
//                              language.dll match for 0x773e: "Click to select whether allie
//         004b1981     PUSH       offset DAT_fffffff8
//         004b1986     MOV        this,dword ptr [EBX]
//         004b1988     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//         004b198d     MOV        EAX,dword ptr [ESP + 0x10]
//         004b1991     ADD        EBX,0x4
//         004b1994     INC        EAX
//         004b1995     ADD        EDI,0xc
//         004b1998     CMP        EAX,0x8
//         004b199b     MOV        dword ptr [ESP + 0x10],EAX
//         004b199f     MOV        dword ptr [ESP + 0x14],EBX
//         004b19a3     JL         LAB_004b18c4
//                              scr_sed2.cpp:1889 (30)
//         004b19a9     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b19af     LEA        EDX,[ESI + 0x898]
//                              language.dll match for 0x29cd: "Ally"
//         004b19b5     PUSH       0x29cd
//         004b19ba     PUSH       EDX=>DAT_fffffff8
//         004b19bb     PUSH       EAX=>DAT_fffffff4
//         004b19bc     MOV        this,ESI
//         004b19be     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b19c3     TEST       EAX,EAX
//         004b19c5     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1890 (30)
//         004b19c7     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b19cd     LEA        this,[ESI + 0x89c]
//                              language.dll match for 0x29ce: "Neutral"
//         004b19d3     PUSH       0x29ce
//         004b19d8     PUSH       this=>DAT_fffffff8
//         004b19d9     PUSH       EDX=>DAT_fffffff4
//         004b19da     MOV        this,ESI
//         004b19dc     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b19e1     TEST       EAX,EAX
//         004b19e3     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1891 (30)
//         004b19e5     MOV        this,dword ptr [ESI + 0x4d4]
//         004b19eb     LEA        EAX,[ESI + 0x8a0]
//                              language.dll match for 0x29cf: "Enemy"
//         004b19f1     PUSH       0x29cf
//         004b19f6     PUSH       EAX=>DAT_fffffff8
//         004b19f7     PUSH       this=>DAT_fffffff4
//         004b19f8     MOV        this,ESI
//         004b19fa     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//         004b19ff     TEST       EAX,EAX
//         004b1a01     JZ         LAB_004b1a29
//                              scr_sed2.cpp:1892 (26)
//         004b1a03     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1a09     LEA        EDX,[ESI + 0x8a4]
//                              language.dll match for 0x29d0: "Allied Victory"
//         004b1a0f     PUSH       0x29d0
//         004b1a14     PUSH       EDX=>DAT_fffffff8
//         004b1a15     PUSH       EAX=>DAT_fffffff4
//         004b1a16     MOV        this,ESI
//         004b1a18     CALL       TRIBE_Screen_Sed::create_text                    int create_text(TRIBE_Screen_Sed * this, TPan
//                              scr_sed2.cpp:1893 (2)
//         004b1a1d     JMP        LAB_004b1a29
//                               LAB_004b1a1f                                                 XREF[6]:     004b016f(j), 004b017e(j),
//                                                                                                         004b01ef(j), 004b01fe(j),
//                                                                                                         004b02a1(j), 004b02af(j)
//                              scr_sed2.cpp:1525 (10)
//         004b1a1f     MOV        dword ptr [ESI + 0xd8],0x1
//                               LAB_004b1a29                                                 XREF[181]:   004af6f7(j), 004af724(j),
//                                                                                                         004af750(j), 004af77c(j),
//                                                                                                         004af7a8(j), 004af7d4(j),
//                                                                                                         004af800(j), 004af82c(j),
//                                                                                                         004af858(j), 004af884(j),
//                                                                                                         004af8d0(j), 004af905(j),
//                                                                                                         004af932(j), 004af94f(j),
//                                                                                                         004af97b(j), 004af9a6(j),
//                                                                                                         004af9d6(j), 004af9f8(j),
//                                                                                                         004afa1a(j), 004afa3c(j), [more]
//                              scr_sed2.cpp:1893 (25)
//         004b1a29     MOV        this,dword ptr [ESP + local_c]
//         004b1a30     POP        EDI
//         004b1a31     POP        ESI
//         004b1a32     POP        EBP
//         004b1a33     MOV        dword ptr FS:[0x0],this
//         004b1a3a     POP        EBX
//         004b1a3b     ADD        ESP,0x1c8
//         004b1a41     RET
//         004b1a42     ??         90h
//         004b1a43     NOP
//         004b1a44     NOP
//         004b1a45     NOP
//         004b1a46     NOP
//         004b1a47     NOP
//         004b1a48     NOP
//         004b1a49     NOP
//         004b1a4a     NOP
//         004b1a4b     NOP
//         004b1a4c     NOP
//         004b1a4d     NOP
//         004b1a4e     NOP
//         004b1a4f     NOP
    return;
}

void TRIBE_Screen_Sed::position_panels() {
    /* TODO: Stub */
//                              void __thiscall position_panels(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?position_panels@TRIBE_Screen_Sed@@QAEXXZ                    XREF[2]:     TRIBE_Screen_Sed:004a869a(c),
//                               TRIBE_Screen_Sed::position_panels                                         handle_size:004ab726(c)
//                              scr_sed2.cpp:1900 (3)
//         004b1a50     PUSH       ESI
//         004b1a51     MOV        ESI,this
//                              scr_sed2.cpp:1906 (17)
//         004b1a53     MOV        EAX,dword ptr [ESI + 0x4c8]
//         004b1a59     TEST       EAX,EAX
//         004b1a5b     JZ         LAB_004b29cf
//         004b1a61     PUSH       EDI
//         004b1a62     PUSH       EBP
//         004b1a63     PUSH       EBX
//                              scr_sed2.cpp:1910 (2)
//         004b1a64     XOR        EDI,EDI
//                               LAB_004b1a66                                                 XREF[1]:     004b1a9e(j)
//                              scr_sed2.cpp:1911 (58)
//         004b1a66     TEST       EDI,EDI
//         004b1a68     JNZ        LAB_004b1a6e
//         004b1a6a     XOR        EAX,EAX
//         004b1a6c     JMP        LAB_004b1a75
//                               LAB_004b1a6e                                                 XREF[1]:     004b1a68(j)
//         004b1a6e     MOV        EAX,dword ptr [ESI + EDI*0x4 + 0x4d4]
//                               LAB_004b1a75                                                 XREF[1]:     004b1a6c(j)
//         004b1a75     MOV        this,dword ptr [ESI + EDI*0x4 + 0x4d8]
//         004b1a7c     PUSH       0x0
//         004b1a7e     PUSH       0x0=>DAT_fffffff8
//         004b1a80     PUSH       0x0=>DAT_fffffff4
//         004b1a82     MOV        EDX,dword ptr [this->_padding_]
//         004b1a84     PUSH       EAX=>DAT_fffffff0
//         004b1a85     PUSH       0x16
//         004b1a87     PUSH       0x16
//         004b1a89     PUSH       0x6d
//         004b1a8b     PUSH       0x32
//         004b1a8d     PUSH       0x2
//         004b1a8f     PUSH       0x2
//         004b1a91     PUSH       0x2
//         004b1a93     PUSH       0x2
//         004b1a95     PUSH       0x7
//         004b1a97     CALL       dword ptr [EDX + 0x18]
//         004b1a9a     INC        EDI
//         004b1a9b     CMP        EDI,0x5
//         004b1a9e     JL         LAB_004b1a66
//                              scr_sed2.cpp:1912 (5)
//         004b1aa0     MOV        EDI,0x5
//                               LAB_004b1aa5                                                 XREF[1]:     004b1ae4(j)
//                              scr_sed2.cpp:1913 (65)
//         004b1aa5     CMP        EDI,0x5
//         004b1aa8     JNZ        LAB_004b1aae
//         004b1aaa     XOR        EAX,EAX
//         004b1aac     JMP        LAB_004b1ab5
//                               LAB_004b1aae                                                 XREF[1]:     004b1aa8(j)
//         004b1aae     MOV        EAX,dword ptr [ESI + EDI*0x4 + 0x4d4]
//                               LAB_004b1ab5                                                 XREF[1]:     004b1aac(j)
//         004b1ab5     MOV        EBX,dword ptr [ESI + EDI*0x4 + 0x4c4]
//         004b1abc     MOV        this,dword ptr [ESI + EDI*0x4 + 0x4d8]
//         004b1ac3     PUSH       0x0
//         004b1ac5     PUSH       0x0=>DAT_fffffff8
//         004b1ac7     PUSH       EBX=>DAT_fffffff4
//         004b1ac8     MOV        EDX,dword ptr [this->_padding_]
//         004b1aca     PUSH       EAX=>DAT_fffffff0
//         004b1acb     PUSH       0x16
//         004b1acd     PUSH       0x16
//         004b1acf     PUSH       0x6d
//         004b1ad1     PUSH       0x32
//         004b1ad3     PUSH       0x2
//         004b1ad5     PUSH       0x2
//         004b1ad7     PUSH       0x2
//         004b1ad9     PUSH       0x2
//         004b1adb     PUSH       0x7
//         004b1add     CALL       dword ptr [EDX + 0x18]
//         004b1ae0     INC        EDI
//         004b1ae1     CMP        EDI,0xa
//         004b1ae4     JL         LAB_004b1aa5
//                              scr_sed2.cpp:1916 (37)
//         004b1ae6     MOV        this,dword ptr [ESI + 0x500]
//         004b1aec     PUSH       0x0
//         004b1aee     PUSH       0x0=>DAT_fffffff8
//         004b1af0     PUSH       0x0=>DAT_fffffff4
//         004b1af2     MOV        EAX,dword ptr [this->_padding_]
//         004b1af4     PUSH       0x0=>DAT_fffffff0
//         004b1af6     PUSH       0x28
//         004b1af8     PUSH       0x14
//         004b1afa     PUSH       0x3a
//         004b1afc     PUSH       0x3a
//         004b1afe     PUSH       0x3
//         004b1b00     PUSH       0x3
//         004b1b02     PUSH       0x5
//         004b1b04     PUSH       0x2
//         004b1b06     PUSH       0x9
//         004b1b08     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1917 (37)
//         004b1b0b     MOV        this,dword ptr [ESI + 0x504]
//         004b1b11     PUSH       0x0
//         004b1b13     PUSH       0x0=>DAT_fffffff8
//         004b1b15     PUSH       0x0=>DAT_fffffff4
//         004b1b17     MOV        EDX,dword ptr [this->_padding_]
//         004b1b19     PUSH       0x0=>DAT_fffffff0
//         004b1b1b     PUSH       0x1e
//         004b1b1d     PUSH       0x14
//         004b1b1f     PUSH       0x1e
//         004b1b21     PUSH       0x14
//         004b1b23     PUSH       0x5
//         004b1b25     PUSH       0x5
//         004b1b27     PUSH       0x5
//         004b1b29     PUSH       0x5
//         004b1b2b     PUSH       0xa
//         004b1b2d     CALL       dword ptr [EDX + 0x18]
//                              scr_sed2.cpp:1918 (49)
//         004b1b30     MOV        this,dword ptr [ESI + 0x4cc]
//         004b1b36     PUSH       0x0
//         004b1b38     PUSH       0x0=>DAT_fffffff8
//         004b1b3a     PUSH       0x0=>DAT_fffffff4
//         004b1b3c     MOV        EAX,dword ptr [this->_padding_]
//         004b1b3e     PUSH       0x0=>DAT_fffffff0
//         004b1b40     PUSH       0x87
//         004b1b45     PUSH       0x87
//         004b1b4a     PUSH       0xe6
//         004b1b4f     PUSH       0xe6
//         004b1b54     PUSH       0x0
//         004b1b56     PUSH       0x0
//         004b1b58     PUSH       0x0
//         004b1b5a     PUSH       0x0
//         004b1b5c     PUSH       0xa
//         004b1b5e     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1919 (48)
//         004b1b61     MOV        EAX,dword ptr [ESI + 0x4cc]
//         004b1b67     MOV        this,dword ptr [ESI + 0x4d4]
//         004b1b6d     PUSH       0x0
//         004b1b6f     PUSH       EAX=>DAT_fffffff8
//         004b1b70     PUSH       0x0=>DAT_fffffff4
//         004b1b72     MOV        EDX,dword ptr [this->_padding_]
//         004b1b74     PUSH       0x0=>DAT_fffffff0
//         004b1b76     PUSH       0x89
//         004b1b7b     PUSH       0x89
//         004b1b80     PUSH       0x0
//         004b1b82     PUSH       0x0
//         004b1b84     PUSH       0x2
//         004b1b86     PUSH       0x2
//         004b1b88     PUSH       0x2
//         004b1b8a     PUSH       0x2
//         004b1b8c     PUSH       0x8
//         004b1b8e     CALL       dword ptr [EDX + 0x18]
//                              scr_sed2.cpp:1925 (50)
//         004b1b91     MOV        EAX,dword ptr [ESI + 0x4d4]
//         004b1b97     MOV        this,dword ptr [ESI + 0x63c]
//         004b1b9d     PUSH       EAX
//         004b1b9e     MOV        EAX,dword ptr [ESI + 0x500]
//         004b1ba4     PUSH       0x0=>DAT_fffffff8
//         004b1ba6     PUSH       EAX=>DAT_fffffff4
//         004b1ba7     MOV        EDX,dword ptr [this->_padding_]
//         004b1ba9     PUSH       0x0=>DAT_fffffff0
//         004b1bab     PUSH       0x0
//         004b1bad     PUSH       0x0
//         004b1baf     PUSH       0xc8
//                              language.dll match for 0x7c: "B"
//         004b1bb4     PUSH       0x7c
//         004b1bb6     PUSH       0x4
//         004b1bb8     PUSH       0x0
//         004b1bba     PUSH       0x6
//         004b1bbc     PUSH       0x0
//         004b1bbe     PUSH       0x7
//         004b1bc0     CALL       dword ptr [EDX + 0x18]
//                              scr_sed2.cpp:1926 (43)
//         004b1bc3     MOV        this,dword ptr [ESI + 0x660]
//         004b1bc9     PUSH       0x0
//         004b1bcb     PUSH       0x0=>DAT_fffffff8
//         004b1bcd     PUSH       0x0=>DAT_fffffff4
//         004b1bcf     MOV        EDX,dword ptr [this->_padding_]
//         004b1bd1     PUSH       0x0=>DAT_fffffff0
//         004b1bd3     PUSH       0x6c
//         004b1bd5     PUSH       0x6c
//         004b1bd7     PUSH       0x96
//         004b1bdc     PUSH       0x96
//         004b1be1     PUSH       0x4
//         004b1be3     PUSH       0x4
//         004b1be5     PUSH       0x4
//         004b1be7     PUSH       0x4
//         004b1be9     PUSH       0x8
//         004b1beb     CALL       dword ptr [EDX + 0x18]
//                              scr_sed2.cpp:1928 (6)
//         004b1bee     MOV        EDI,dword ptr [ESI + 0x63c]
//                              scr_sed2.cpp:1930 (20)
//         004b1bf4     MOV        this,EDI
//         004b1bf6     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         004b1bfb     MOV        this,EDI
//         004b1bfd     MOV        EBX,EAX
//         004b1bff     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         004b1c04     CMP        EBX,EAX
//         004b1c06     JLE        LAB_004b1c74
//                              scr_sed2.cpp:1932 (50)
//         004b1c08     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1c0e     MOV        this,dword ptr [ESI + 0x63c]
//         004b1c14     PUSH       EDX
//         004b1c15     MOV        EDX,dword ptr [ESI + 0x500]
//         004b1c1b     PUSH       0x0=>DAT_fffffff8
//         004b1c1d     PUSH       EDX=>DAT_fffffff4
//         004b1c1e     MOV        EAX,dword ptr [this->_padding_]
//         004b1c20     PUSH       0x0=>DAT_fffffff0
//         004b1c22     PUSH       0x0
//         004b1c24     PUSH       0x0
//         004b1c26     PUSH       0xdc
//                              language.dll match for 0x68: "Arial"
//         004b1c2b     PUSH       0x68
//         004b1c2d     PUSH       0x4
//         004b1c2f     PUSH       0x0
//         004b1c31     PUSH       0x6
//         004b1c33     PUSH       0x0
//         004b1c35     PUSH       0x7
//         004b1c37     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1933 (52)
//         004b1c3a     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1c40     MOV        this,dword ptr [ESI + 0x640]
//         004b1c46     PUSH       EDX
//         004b1c47     MOV        EDX,dword ptr [ESI + 0x500]
//         004b1c4d     PUSH       0x0=>DAT_fffffff8
//         004b1c4f     PUSH       EDX=>DAT_fffffff4
//         004b1c50     MOV        EDX,dword ptr [ESI + 0x63c]
//         004b1c56     MOV        EAX,dword ptr [this->_padding_]
//         004b1c58     PUSH       EDX=>DAT_fffffff0
//         004b1c59     PUSH       0x0
//         004b1c5b     PUSH       0x0
//         004b1c5d     PUSH       0x12
//         004b1c5f     PUSH       0x12
//         004b1c61     PUSH       0x2
//         004b1c63     PUSH       0x0
//         004b1c65     PUSH       0x1
//         004b1c67     PUSH       0x1
//         004b1c69     PUSH       0x7
//         004b1c6b     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1934 (6)
//         004b1c6e     MOV        EDI,dword ptr [ESI + 0x640]
//                               LAB_004b1c74                                                 XREF[1]:     004b1c06(j)
//                              scr_sed2.cpp:1938 (46)
//         004b1c74     MOV        EDX,dword ptr [ESI + 0x4d4]
//         004b1c7a     MOV        this,dword ptr [ESI + 0x4c8]
//         004b1c80     PUSH       EDX
//         004b1c81     MOV        EDX,dword ptr [ESI + 0x500]
//         004b1c87     PUSH       0x0=>DAT_fffffff8
//         004b1c89     PUSH       EDX=>DAT_fffffff4
//         004b1c8a     MOV        EAX,dword ptr [this->_padding_]
//         004b1c8c     PUSH       EDI=>DAT_fffffff0
//         004b1c8d     PUSH       0x0
//         004b1c8f     PUSH       0x0
//         004b1c91     PUSH       0x0
//         004b1c93     PUSH       0x0
//         004b1c95     PUSH       0x4
//         004b1c97     PUSH       0x0
//         004b1c99     PUSH       0x6
//         004b1c9b     PUSH       0x0
//         004b1c9d     PUSH       0x7
//         004b1c9f     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1941 (37)
//         004b1ca2     MOV        this,dword ptr [ESI + 0x4d0]
//         004b1ca8     PUSH       0x0
//         004b1caa     PUSH       0x0=>DAT_fffffff8
//         004b1cac     PUSH       0x0=>DAT_fffffff4
//         004b1cae     MOV        EAX,dword ptr [this->_padding_]
//         004b1cb0     PUSH       0x0=>DAT_fffffff0
//         004b1cb2     PUSH       0x18
//         004b1cb4     PUSH       0x18
//         004b1cb6     PUSH       0x0
//         004b1cb8     PUSH       0x0
//         004b1cba     PUSH       0x4
//         004b1cbc     PUSH       0x4
//         004b1cbe     PUSH       0x4
//         004b1cc0     PUSH       0x4
//         004b1cc2     PUSH       0x8
//         004b1cc4     CALL       dword ptr [EAX + 0x18]
//                              scr_sed2.cpp:1944 (19)
//         004b1cc7     MOV        this,dword ptr [ESI + 0x520]
//         004b1ccd     PUSH       0x16
//                              language.dll match for 0x78: "10"
//         004b1ccf     PUSH       offset DAT_fffffff8
//         004b1cd1     PUSH       offset DAT_fffffff4
//         004b1cd3     MOV        EDX,dword ptr [this->_padding_]
//         004b1cd5     PUSH       offset DAT_fffffff0
//         004b1cd7     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1946 (19)
//         004b1cda     MOV        this,dword ptr [ESI + 0x508]
//         004b1ce0     PUSH       0x16
//         004b1ce2     PUSH       offset DAT_fffffff8
//         004b1ce4     PUSH       offset DAT_fffffff4
//         004b1ce6     MOV        EAX,dword ptr [this->_padding_]
//         004b1ce8     PUSH       offset DAT_fffffff0
//         004b1cea     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1947 (19)
//         004b1ced     MOV        this,dword ptr [ESI + 0x50c]
//         004b1cf3     PUSH       0x16
//         004b1cf5     PUSH       offset DAT_fffffff8
//         004b1cf7     PUSH       offset DAT_fffffff4
//         004b1cf9     MOV        EDX,dword ptr [this->_padding_]
//         004b1cfb     PUSH       offset DAT_fffffff0
//         004b1cfd     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1948 (19)
//         004b1d00     MOV        this,dword ptr [ESI + 0x510]
//         004b1d06     PUSH       0x16
//         004b1d08     PUSH       offset DAT_fffffff8
//         004b1d0a     PUSH       offset DAT_fffffff4
//         004b1d0c     MOV        EAX,dword ptr [this->_padding_]
//         004b1d0e     PUSH       offset DAT_fffffff0
//         004b1d10     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1950 (19)
//         004b1d13     MOV        this,dword ptr [ESI + 0x514]
//         004b1d19     PUSH       0x16
//                              language.dll match for 0x73: "B"
//         004b1d1b     PUSH       offset DAT_fffffff8
//         004b1d1d     PUSH       offset DAT_fffffff4
//         004b1d1f     MOV        EDX,dword ptr [this->_padding_]
//         004b1d21     PUSH       offset DAT_fffffff0
//         004b1d23     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1951 (19)
//         004b1d26     MOV        this,dword ptr [ESI + 0x518]
//         004b1d2c     PUSH       0x16
//                              language.dll match for 0x73: "B"
//         004b1d2e     PUSH       offset DAT_fffffff8
//         004b1d30     PUSH       offset DAT_fffffff4
//         004b1d32     MOV        EAX,dword ptr [this->_padding_]
//         004b1d34     PUSH       offset DAT_fffffff0
//         004b1d36     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1952 (19)
//         004b1d39     MOV        this,dword ptr [ESI + 0x51c]
//         004b1d3f     PUSH       0x16
//                              language.dll match for 0x73: "B"
//         004b1d41     PUSH       offset DAT_fffffff8
//         004b1d43     PUSH       offset DAT_fffffff4
//         004b1d45     MOV        EDX,dword ptr [this->_padding_]
//         004b1d47     PUSH       offset DAT_fffffff0
//         004b1d49     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1954 (25)
//         004b1d4c     MOV        this,dword ptr [ESI + 0x52c]
//         004b1d52     PUSH       0x16
//                              language.dll match for 0x82: "B"
//         004b1d54     PUSH       offset DAT_fffffff8
//         004b1d59     PUSH       offset DAT_fffffff4
//         004b1d5b     MOV        EAX,dword ptr [this->_padding_]
//         004b1d5d     PUSH       offset DAT_fffffff0
//         004b1d62     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1955 (25)
//         004b1d65     MOV        this,dword ptr [ESI + 0x530]
//         004b1d6b     PUSH       0x16
//         004b1d6d     PUSH       offset DAT_fffffff8
//         004b1d72     PUSH       offset DAT_fffffff4
//         004b1d74     MOV        EDX,dword ptr [this->_padding_]
//         004b1d76     PUSH       offset DAT_fffffff0
//         004b1d7b     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1957 (25)
//         004b1d7e     MOV        this,dword ptr [ESI + 0x534]
//         004b1d84     PUSH       0x16
//                              language.dll match for 0x82: "B"
//         004b1d86     PUSH       offset DAT_fffffff8
//         004b1d8b     PUSH       offset DAT_fffffff4
//         004b1d8d     MOV        EAX,dword ptr [this->_padding_]
//         004b1d8f     PUSH       offset DAT_fffffff0
//         004b1d94     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1958 (25)
//         004b1d97     MOV        this,dword ptr [ESI + 0x538]
//         004b1d9d     PUSH       0x16
//         004b1d9f     PUSH       offset DAT_fffffff8
//         004b1da4     PUSH       offset DAT_fffffff4
//         004b1da6     MOV        EDX,dword ptr [this->_padding_]
//         004b1da8     PUSH       offset DAT_fffffff0
//         004b1dad     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1960 (25)
//         004b1db0     MOV        this,dword ptr [ESI + 0x524]
//         004b1db6     PUSH       0x16
//                              language.dll match for 0x82: "B"
//         004b1db8     PUSH       offset DAT_fffffff8
//         004b1dbd     PUSH       offset DAT_fffffff4
//         004b1dbf     MOV        EAX,dword ptr [this->_padding_]
//         004b1dc1     PUSH       offset DAT_fffffff0
//         004b1dc6     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1961 (25)
//         004b1dc9     MOV        this,dword ptr [ESI + 0x528]
//         004b1dcf     PUSH       0x16
//         004b1dd1     PUSH       offset DAT_fffffff8
//         004b1dd6     PUSH       offset DAT_fffffff4
//         004b1dd8     MOV        EDX,dword ptr [this->_padding_]
//         004b1dda     PUSH       offset DAT_fffffff0
//         004b1ddf     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1963 (19)
//         004b1de2     MOV        this,dword ptr [ESI + 0x53c]
//         004b1de8     PUSH       0x16
//                              language.dll match for 0x78: "10"
//         004b1dea     PUSH       offset DAT_fffffff8
//         004b1dec     PUSH       offset DAT_fffffff4
//         004b1dee     MOV        EAX,dword ptr [this->_padding_]
//         004b1df0     PUSH       offset DAT_fffffff0
//         004b1df2     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1964 (19)
//         004b1df5     MOV        this,dword ptr [ESI + 0x540]
//         004b1dfb     PUSH       0x16
//         004b1dfd     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x70: "B"
//         004b1dff     PUSH       offset DAT_fffffff4
//         004b1e01     MOV        EDX,dword ptr [this->_padding_]
//         004b1e03     PUSH       offset DAT_fffffff0
//         004b1e05     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1966 (19)
//         004b1e08     MOV        this,dword ptr [ESI + 0x544]
//         004b1e0e     PUSH       0x16
//                              language.dll match for 0x78: "10"
//         004b1e10     PUSH       offset DAT_fffffff8
//         004b1e12     PUSH       offset DAT_fffffff4
//         004b1e14     MOV        EAX,dword ptr [this->_padding_]
//         004b1e16     PUSH       offset DAT_fffffff0
//         004b1e18     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1968 (19)
//         004b1e1b     MOV        this,dword ptr [ESI + 0x548]
//         004b1e21     PUSH       0x16
//         004b1e23     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x70: "B"
//         004b1e25     PUSH       offset DAT_fffffff4
//         004b1e27     MOV        EDX,dword ptr [this->_padding_]
//         004b1e29     PUSH       offset DAT_fffffff0
//         004b1e2b     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1970 (25)
//         004b1e2e     MOV        this,dword ptr [ESI + 0x54c]
//         004b1e34     PUSH       0x26
//                              language.dll match for 0x82: "B"
//         004b1e36     PUSH       offset DAT_fffffff8
//         004b1e3b     PUSH       offset DAT_fffffff4
//         004b1e3d     MOV        EAX,dword ptr [this->_padding_]
//         004b1e3f     PUSH       offset DAT_fffffff0
//         004b1e44     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1974 (22)
//         004b1e47     MOV        this,dword ptr [ESI + 0x5a0]
//         004b1e4d     MOV        EDX,dword ptr [this->_padding_]
//         004b1e4f     PUSH       0x6e
//         004b1e51     PUSH       offset DAT_fffffff8
//         004b1e56     PUSH       offset DAT_fffffff4
//                              language.dll match for 0x73: "B"
//         004b1e58     PUSH       offset DAT_fffffff0
//         004b1e5a     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1976 (19)
//         004b1e5d     MOV        this,dword ptr [ESI + 0x59c]
//         004b1e63     PUSH       0x16
//         004b1e65     PUSH       offset DAT_fffffff8
//         004b1e67     PUSH       offset DAT_fffffff4
//         004b1e69     MOV        EAX,dword ptr [this->_padding_]
//                              language.dll match for 0x73: "B"
//         004b1e6b     PUSH       offset DAT_fffffff0
//         004b1e6d     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1977 (22)
//         004b1e70     MOV        this,dword ptr [ESI + 0x5a8]
//         004b1e76     PUSH       0x6e
//         004b1e78     PUSH       offset DAT_fffffff8
//         004b1e7d     PUSH       offset DAT_fffffff4
//         004b1e7f     MOV        EDX,dword ptr [this->_padding_]
//                              language.dll match for 0x73: "B"
//         004b1e81     PUSH       offset DAT_fffffff0
//         004b1e83     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1979 (19)
//         004b1e86     MOV        this,dword ptr [ESI + 0x580]
//         004b1e8c     PUSH       0x14
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b1e8e     PUSH       offset DAT_fffffff8
//         004b1e90     PUSH       offset DAT_fffffff4
//         004b1e92     MOV        EAX,dword ptr [this->_padding_]
//         004b1e94     PUSH       offset DAT_fffffff0
//         004b1e96     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1980 (19)
//         004b1e99     MOV        this,dword ptr [ESI + 0x584]
//         004b1e9f     PUSH       0x16
//         004b1ea1     PUSH       offset DAT_fffffff8
//         004b1ea3     PUSH       offset DAT_fffffff4
//         004b1ea5     MOV        EDX,dword ptr [this->_padding_]
//         004b1ea7     PUSH       offset DAT_fffffff0
//         004b1ea9     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1981 (19)
//         004b1eac     MOV        this,dword ptr [ESI + 0x588]
//         004b1eb2     PUSH       0x16
//         004b1eb4     PUSH       offset DAT_fffffff8
//         004b1eb6     PUSH       offset DAT_fffffff4
//         004b1eb8     MOV        EAX,dword ptr [this->_padding_]
//         004b1eba     PUSH       offset DAT_fffffff0
//         004b1ebc     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1982 (19)
//         004b1ebf     MOV        this,dword ptr [ESI + 0x58c]
//         004b1ec5     PUSH       0x16
//         004b1ec7     PUSH       offset DAT_fffffff8
//         004b1ec9     PUSH       offset DAT_fffffff4
//         004b1ecb     MOV        EDX,dword ptr [this->_padding_]
//         004b1ecd     PUSH       offset DAT_fffffff0
//         004b1ecf     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1983 (19)
//         004b1ed2     MOV        this,dword ptr [ESI + 0x590]
//         004b1ed8     PUSH       0x16
//         004b1eda     PUSH       offset DAT_fffffff8
//         004b1edc     PUSH       offset DAT_fffffff4
//         004b1ede     MOV        EAX,dword ptr [this->_padding_]
//         004b1ee0     PUSH       offset DAT_fffffff0
//         004b1ee2     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1984 (19)
//         004b1ee5     MOV        this,dword ptr [ESI + 0x594]
//         004b1eeb     PUSH       0x16
//         004b1eed     PUSH       offset DAT_fffffff8
//         004b1eef     PUSH       offset DAT_fffffff4
//         004b1ef1     MOV        EDX,dword ptr [this->_padding_]
//         004b1ef3     PUSH       offset DAT_fffffff0
//         004b1ef5     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1985 (19)
//         004b1ef8     MOV        this,dword ptr [ESI + 0x598]
//         004b1efe     PUSH       0x16
//         004b1f00     PUSH       offset DAT_fffffff8
//         004b1f02     PUSH       offset DAT_fffffff4
//         004b1f04     MOV        EAX,dword ptr [this->_padding_]
//         004b1f06     PUSH       offset DAT_fffffff0
//         004b1f08     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1987 (22)
//         004b1f0b     MOV        this,dword ptr [ESI + 0x554]
//         004b1f11     PUSH       0x14
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b1f13     PUSH       offset DAT_fffffff8
//         004b1f15     PUSH       offset DAT_fffffff4
//         004b1f17     MOV        EDX,dword ptr [this->_padding_]
//         004b1f19     PUSH       offset DAT_fffffff0
//         004b1f1e     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1989 (22)
//         004b1f21     MOV        this,dword ptr [ESI + 0x558]
//         004b1f27     PUSH       0x16
//         004b1f29     PUSH       offset DAT_fffffff8
//         004b1f2b     PUSH       offset DAT_fffffff4
//         004b1f2d     MOV        EAX,dword ptr [this->_padding_]
//         004b1f2f     PUSH       offset DAT_fffffff0
//         004b1f34     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1990 (22)
//         004b1f37     MOV        this,dword ptr [ESI + 0x55c]
//         004b1f3d     PUSH       0x16
//         004b1f3f     PUSH       offset DAT_fffffff8
//         004b1f41     PUSH       offset DAT_fffffff4
//         004b1f43     MOV        EDX,dword ptr [this->_padding_]
//         004b1f45     PUSH       offset DAT_fffffff0
//         004b1f4a     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1991 (22)
//         004b1f4d     MOV        this,dword ptr [ESI + 0x560]
//         004b1f53     PUSH       0x16
//         004b1f55     PUSH       offset DAT_fffffff8
//         004b1f57     PUSH       offset DAT_fffffff4
//         004b1f59     MOV        EAX,dword ptr [this->_padding_]
//         004b1f5b     PUSH       offset DAT_fffffff0
//         004b1f60     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1992 (22)
//         004b1f63     MOV        this,dword ptr [ESI + 0x564]
//         004b1f69     PUSH       0x16
//         004b1f6b     PUSH       offset DAT_fffffff8
//         004b1f6d     PUSH       offset DAT_fffffff4
//         004b1f6f     MOV        EDX,dword ptr [this->_padding_]
//         004b1f71     PUSH       offset DAT_fffffff0
//         004b1f76     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1993 (22)
//         004b1f79     MOV        this,dword ptr [ESI + 0x568]
//         004b1f7f     PUSH       0x16
//         004b1f81     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x6f: "12"
//         004b1f83     PUSH       offset DAT_fffffff4
//         004b1f85     MOV        EAX,dword ptr [this->_padding_]
//         004b1f87     PUSH       offset DAT_fffffff0
//         004b1f8c     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1994 (22)
//         004b1f8f     MOV        this,dword ptr [ESI + 0x56c]
//         004b1f95     PUSH       0x16
//         004b1f97     PUSH       offset DAT_fffffff8
//         004b1f99     PUSH       offset DAT_fffffff4
//         004b1f9b     MOV        EDX,dword ptr [this->_padding_]
//         004b1f9d     PUSH       offset DAT_fffffff0
//         004b1fa2     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1995 (22)
//         004b1fa5     MOV        this,dword ptr [ESI + 0x570]
//         004b1fab     PUSH       0x16
//         004b1fad     PUSH       offset DAT_fffffff8
//         004b1faf     PUSH       offset DAT_fffffff4
//         004b1fb1     MOV        EAX,dword ptr [this->_padding_]
//         004b1fb3     PUSH       offset DAT_fffffff0
//         004b1fb8     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1996 (22)
//         004b1fbb     MOV        this,dword ptr [ESI + 0x574]
//         004b1fc1     PUSH       0x16
//         004b1fc3     PUSH       offset DAT_fffffff8
//         004b1fc5     PUSH       offset DAT_fffffff4
//         004b1fc7     MOV        EDX,dword ptr [this->_padding_]
//         004b1fc9     PUSH       offset DAT_fffffff0
//         004b1fce     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:1997 (22)
//         004b1fd1     MOV        this,dword ptr [ESI + 0x578]
//         004b1fd7     PUSH       0x16
//         004b1fd9     PUSH       offset DAT_fffffff8
//         004b1fdb     PUSH       offset DAT_fffffff4
//         004b1fdd     MOV        EAX,dword ptr [this->_padding_]
//         004b1fdf     PUSH       offset DAT_fffffff0
//         004b1fe4     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:1998 (22)
//         004b1fe7     MOV        this,dword ptr [ESI + 0x57c]
//         004b1fed     PUSH       0x16
//         004b1fef     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x6f: "12"
//         004b1ff1     PUSH       offset DAT_fffffff4
//         004b1ff3     MOV        EDX,dword ptr [this->_padding_]
//         004b1ff5     PUSH       offset DAT_fffffff0
//         004b1ffa     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:2001 (19)
//         004b1ffd     MOV        this,dword ptr [ESI + 0x5b0]
//         004b2003     PUSH       0x12
//         004b2005     PUSH       offset DAT_fffffff8
//         004b2007     PUSH       offset DAT_fffffff4
//         004b2009     MOV        EAX,dword ptr [this->_padding_]
//         004b200b     PUSH       offset DAT_fffffff0
//         004b200d     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:2002 (19)
//         004b2010     MOV        this,dword ptr [ESI + 0x5f4]
//         004b2016     PUSH       0x12
//         004b2018     PUSH       offset DAT_fffffff8
//         004b201a     PUSH       offset DAT_fffffff4
//         004b201c     MOV        EDX,dword ptr [this->_padding_]
//         004b201e     PUSH       offset DAT_fffffff0
//         004b2020     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:2003 (22)
//         004b2023     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2029     PUSH       0x16
//         004b202b     MOV        EAX,dword ptr [this->_padding_]
//         004b202d     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b2032     PUSH       offset DAT_fffffff4
//         004b2034     PUSH       offset DAT_fffffff0
//         004b2036     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:2004 (22)
//         004b2039     MOV        this,dword ptr [ESI + 0x5b0]
//         004b203f     PUSH       0x12
//         004b2041     PUSH       offset DAT_fffffff8
//         004b2046     PUSH       offset DAT_fffffff4
//         004b2048     MOV        EDX,dword ptr [this->_padding_]
//         004b204a     PUSH       offset DAT_fffffff0
//         004b204c     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:2005 (22)
//         004b204f     MOV        this,dword ptr [ESI + 0x5b4]
//         004b2055     PUSH       0x16
//         004b2057     PUSH       offset DAT_fffffff8
//         004b205c     PUSH       offset DAT_fffffff4
//         004b205e     MOV        EAX,dword ptr [this->_padding_]
//         004b2060     PUSH       offset DAT_fffffff0
//         004b2062     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:2006 (33)
//         004b2065     MOV        this,dword ptr [ESI + 0x5b8]
//         004b206b     PUSH       0x16
//         004b206d     PUSH       offset DAT_fffffff8
//         004b2072     PUSH       offset DAT_fffffff4
//         004b2074     MOV        EDX,dword ptr [this->_padding_]
//         004b2076     PUSH       offset DAT_fffffff0
//         004b2078     CALL       dword ptr [EDX + 0x1c]
//         004b207b     MOV        EBP,0xa6
//         004b2080     LEA        EBX,[ESI + 0x5d8]
//                               LAB_004b2086                                                 XREF[1]:     004b20bd(j)
//                              scr_sed2.cpp:2009 (5)
//         004b2086     MOV        EDI,0x19
//                               LAB_004b208b                                                 XREF[1]:     004b20b2(j)
//                              scr_sed2.cpp:2011 (17)
//         004b208b     MOV        this,dword ptr [EBX + -0x14]
//         004b208e     PUSH       0x12
//         004b2090     LEA        EDX,[EDI + -0x12]
//         004b2093     PUSH       offset DAT_fffffff8
//         004b2095     MOV        EAX,dword ptr [this->_padding_]
//         004b2097     PUSH       EDX=>DAT_fffffff4
//         004b2098     PUSH       EBP=>DAT_fffffff0
//         004b2099     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:2012 (35)
//         004b209c     MOV        this,dword ptr [EBX]
//         004b209e     PUSH       0x16
//         004b20a0     PUSH       offset DAT_fffffff8
//         004b20a2     PUSH       EDI=>DAT_fffffff4
//         004b20a3     MOV        EAX,dword ptr [this->_padding_]
//         004b20a5     PUSH       EBP=>DAT_fffffff0
//         004b20a6     CALL       dword ptr [EAX + 0x1c]
//         004b20a9     ADD        EDI,0x2c
//         004b20ac     ADD        EBX,0x4
//         004b20af     CMP        EDI,0x71
//         004b20b2     JL         LAB_004b208b
//         004b20b4     ADD        EBP,0x44
//         004b20b7     CMP        EBP,0x12e
//         004b20bd     JL         LAB_004b2086
//                              scr_sed2.cpp:2015 (22)
//         004b20bf     MOV        this,dword ptr [ESI + 0x5d4]
//         004b20c5     PUSH       0x12
//         004b20c7     PUSH       offset DAT_fffffff8
//         004b20c9     PUSH       offset DAT_fffffff4
//         004b20cb     MOV        EDX,dword ptr [this->_padding_]
//         004b20cd     PUSH       offset DAT_fffffff0
//         004b20d2     CALL       dword ptr [EDX + 0x1c]
//                              scr_sed2.cpp:2016 (22)
//         004b20d5     MOV        this,dword ptr [ESI + 0x5e8]
//         004b20db     PUSH       0x16
//         004b20dd     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b20df     PUSH       offset DAT_fffffff4
//         004b20e1     MOV        EAX,dword ptr [this->_padding_]
//         004b20e3     PUSH       offset DAT_fffffff0
//         004b20e8     CALL       dword ptr [EAX + 0x1c]
//                              scr_sed2.cpp:2175 (2278)
//         004b20eb     MOV        EDI,0x19
//         004b20f0     LEA        EBX,[ESI + 0x5f8]
//                               LAB_004b20f6                                                 XREF[1]:     004b212b(j)
//         004b20f6     MOV        this,dword ptr [EBX + -0xc]
//         004b20f9     PUSH       0x12
//         004b20fb     LEA        EAX,[EDI + -0x12]
//                              language.dll match for 0x82: "B"
//         004b20fe     PUSH       offset DAT_fffffff8
//         004b2103     MOV        EDX,dword ptr [this->_padding_]
//         004b2105     PUSH       EAX=>DAT_fffffff4
//         004b2106     PUSH       offset DAT_fffffff0
//         004b210b     CALL       dword ptr [EDX + 0x1c]
//         004b210e     MOV        this,dword ptr [EBX]
//         004b2110     PUSH       0x16
//                              language.dll match for 0x82: "B"
//         004b2112     PUSH       offset DAT_fffffff8
//         004b2117     PUSH       EDI=>DAT_fffffff4
//         004b2118     MOV        EDX,dword ptr [this->_padding_]
//         004b211a     PUSH       offset DAT_fffffff0
//         004b211f     CALL       dword ptr [EDX + 0x1c]
//         004b2122     ADD        EDI,0x2c
//         004b2125     ADD        EBX,0x4
//         004b2128     CMP        EDI,0x71
//         004b212b     JL         LAB_004b20f6
//         004b212d     MOV        this,dword ptr [ESI + 0x600]
//         004b2133     PUSH       0x16
//         004b2135     PUSH       offset DAT_fffffff8
//         004b213a     PUSH       offset DAT_fffffff4
//         004b213c     MOV        EAX,dword ptr [this->_padding_]
//         004b213e     PUSH       offset DAT_fffffff0
//         004b2143     CALL       dword ptr [EAX + 0x1c]
//         004b2146     MOV        this,dword ptr [ESI + 0x604]
//         004b214c     PUSH       0x16
//         004b214e     PUSH       offset DAT_fffffff8
//         004b2153     PUSH       offset DAT_fffffff4
//         004b2155     MOV        EDX,dword ptr [this->_padding_]
//         004b2157     PUSH       offset DAT_fffffff0
//         004b215c     CALL       dword ptr [EDX + 0x1c]
//         004b215f     MOV        this,dword ptr [ESI + 0x60c]
//         004b2165     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2167     PUSH       offset DAT_fffffff8
//         004b216c     PUSH       offset DAT_fffffff4
//         004b216e     MOV        EAX,dword ptr [this->_padding_]
//         004b2170     PUSH       offset DAT_fffffff0
//         004b2175     CALL       dword ptr [EAX + 0x1c]
//         004b2178     MOV        this,dword ptr [ESI + 0x610]
//         004b217e     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2180     PUSH       offset DAT_fffffff8
//         004b2185     PUSH       offset DAT_fffffff4
//         004b2187     MOV        EDX,dword ptr [this->_padding_]
//         004b2189     PUSH       offset DAT_fffffff0
//         004b218e     CALL       dword ptr [EDX + 0x1c]
//         004b2191     MOV        this,dword ptr [ESI + 0x614]
//         004b2197     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2199     PUSH       offset DAT_fffffff8
//         004b219e     PUSH       offset DAT_fffffff4
//         004b21a0     MOV        EAX,dword ptr [this->_padding_]
//         004b21a2     PUSH       offset DAT_fffffff0
//         004b21a7     CALL       dword ptr [EAX + 0x1c]
//         004b21aa     MOV        this,dword ptr [ESI + 0x608]
//         004b21b0     PUSH       0x16
//         004b21b2     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b21b7     PUSH       offset DAT_fffffff4
//         004b21b9     MOV        EDX,dword ptr [this->_padding_]
//         004b21bb     PUSH       offset DAT_fffffff0
//         004b21c0     CALL       dword ptr [EDX + 0x1c]
//         004b21c3     MOV        this,dword ptr [ESI + 0x618]
//         004b21c9     PUSH       0x16
//         004b21cb     PUSH       offset DAT_fffffff8
//         004b21d0     PUSH       offset DAT_fffffff4
//         004b21d2     MOV        EAX,dword ptr [this->_padding_]
//         004b21d4     PUSH       offset DAT_fffffff0
//         004b21d6     CALL       dword ptr [EAX + 0x1c]
//         004b21d9     MOV        this,dword ptr [ESI + 0x61c]
//         004b21df     PUSH       0x16
//         004b21e1     PUSH       offset DAT_fffffff8
//         004b21e3     PUSH       offset DAT_fffffff4
//         004b21e5     MOV        EDX,dword ptr [this->_padding_]
//         004b21e7     PUSH       offset DAT_fffffff0
//         004b21ec     CALL       dword ptr [EDX + 0x1c]
//         004b21ef     MOV        this,dword ptr [ESI + 0x620]
//         004b21f5     PUSH       0x16
//         004b21f7     PUSH       offset DAT_fffffff8
//         004b21f9     PUSH       offset DAT_fffffff4
//         004b21fb     MOV        EAX,dword ptr [this->_padding_]
//         004b21fd     PUSH       offset DAT_fffffff0
//         004b2202     CALL       dword ptr [EAX + 0x1c]
//         004b2205     MOV        this,dword ptr [ESI + 0x624]
//         004b220b     PUSH       0x16
//         004b220d     PUSH       offset DAT_fffffff8
//         004b220f     PUSH       offset DAT_fffffff4
//         004b2211     MOV        EDX,dword ptr [this->_padding_]
//         004b2213     PUSH       offset DAT_fffffff0
//         004b2218     CALL       dword ptr [EDX + 0x1c]
//         004b221b     MOV        this,dword ptr [ESI + 0x628]
//         004b2221     PUSH       0x16
//         004b2223     PUSH       offset DAT_fffffff8
//         004b2225     PUSH       offset DAT_fffffff4
//         004b2227     MOV        EAX,dword ptr [this->_padding_]
//         004b2229     PUSH       offset DAT_fffffff0
//         004b222e     CALL       dword ptr [EAX + 0x1c]
//         004b2231     MOV        this,dword ptr [ESI + 0x62c]
//         004b2237     PUSH       0x16
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b2239     PUSH       offset DAT_fffffff8
//         004b223b     MOV        EDX,dword ptr [this->_padding_]
//         004b223d     PUSH       offset DAT_fffffff4
//         004b223f     PUSH       offset DAT_fffffff0
//         004b2244     CALL       dword ptr [EDX + 0x1c]
//         004b2247     MOV        this,dword ptr [ESI + 0x630]
//         004b224d     PUSH       0x16
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b224f     PUSH       offset DAT_fffffff8
//         004b2251     PUSH       offset DAT_fffffff4
//         004b2253     MOV        EAX,dword ptr [this->_padding_]
//         004b2255     PUSH       offset DAT_fffffff0
//         004b225a     CALL       dword ptr [EAX + 0x1c]
//         004b225d     MOV        this,dword ptr [ESI + 0x634]
//         004b2263     PUSH       0x16
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b2265     PUSH       offset DAT_fffffff8
//         004b2267     PUSH       offset DAT_fffffff4
//         004b2269     MOV        EDX,dword ptr [this->_padding_]
//         004b226b     PUSH       offset DAT_fffffff0
//         004b2270     CALL       dword ptr [EDX + 0x1c]
//         004b2273     MOV        this,dword ptr [ESI + 0x638]
//         004b2279     PUSH       0x16
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004b227b     PUSH       offset DAT_fffffff8
//         004b227d     PUSH       offset DAT_fffffff4
//         004b227f     MOV        EAX,dword ptr [this->_padding_]
//         004b2281     PUSH       offset DAT_fffffff0
//         004b2286     CALL       dword ptr [EAX + 0x1c]
//         004b2289     MOV        this,dword ptr [ESI + 0x688]
//         004b228f     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b2291     PUSH       offset DAT_fffffff8
//         004b2293     PUSH       0x0=>DAT_fffffff4
//         004b2295     MOV        EDX,dword ptr [this->_padding_]
//         004b2297     PUSH       offset DAT_fffffff0
//         004b2299     CALL       dword ptr [EDX + 0x1c]
//         004b229c     MOV        this,dword ptr [ESI + 0x6e0]
//         004b22a2     PUSH       0x12
//         004b22a4     PUSH       offset DAT_fffffff8
//         004b22a6     PUSH       offset DAT_fffffff4
//         004b22a8     MOV        EAX,dword ptr [this->_padding_]
//         004b22aa     PUSH       offset DAT_fffffff0
//         004b22ac     CALL       dword ptr [EAX + 0x1c]
//         004b22af     MOV        this,dword ptr [ESI + 0x6e4]
//         004b22b5     PUSH       0x12
//         004b22b7     PUSH       offset DAT_fffffff8
//         004b22b9     PUSH       offset DAT_fffffff4
//         004b22bb     MOV        EDX,dword ptr [this->_padding_]
//         004b22bd     PUSH       offset DAT_fffffff0
//         004b22bf     CALL       dword ptr [EDX + 0x1c]
//         004b22c2     MOV        this,dword ptr [ESI + 0x6e8]
//         004b22c8     PUSH       0x12
//         004b22ca     PUSH       offset DAT_fffffff8
//         004b22cc     PUSH       offset DAT_fffffff4
//         004b22ce     MOV        EAX,dword ptr [this->_padding_]
//         004b22d0     PUSH       offset DAT_fffffff0
//         004b22d2     CALL       dword ptr [EAX + 0x1c]
//         004b22d5     MOV        this,dword ptr [ESI + 0x6ec]
//         004b22db     PUSH       0x12
//         004b22dd     PUSH       offset DAT_fffffff8
//         004b22df     PUSH       offset DAT_fffffff4
//         004b22e1     MOV        EDX,dword ptr [this->_padding_]
//         004b22e3     PUSH       offset DAT_fffffff0
//         004b22e5     CALL       dword ptr [EDX + 0x1c]
//         004b22e8     MOV        this,dword ptr [ESI + 0x6f0]
//         004b22ee     PUSH       0x12
//         004b22f0     PUSH       offset DAT_fffffff8
//         004b22f2     PUSH       offset DAT_fffffff4
//         004b22f4     MOV        EAX,dword ptr [this->_padding_]
//         004b22f6     PUSH       offset DAT_fffffff0
//         004b22f8     CALL       dword ptr [EAX + 0x1c]
//         004b22fb     MOV        this,dword ptr [ESI + 0x6cc]
//         004b2301     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b2303     PUSH       offset DAT_fffffff8
//         004b2305     PUSH       offset DAT_fffffff4
//         004b2307     MOV        EDX,dword ptr [this->_padding_]
//         004b2309     PUSH       offset DAT_fffffff0
//         004b230b     CALL       dword ptr [EDX + 0x1c]
//         004b230e     MOV        this,dword ptr [ESI + 0x6d0]
//         004b2314     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b2316     PUSH       offset DAT_fffffff8
//         004b2318     PUSH       offset DAT_fffffff4
//         004b231a     MOV        EAX,dword ptr [this->_padding_]
//         004b231c     PUSH       offset DAT_fffffff0
//         004b231e     CALL       dword ptr [EAX + 0x1c]
//         004b2321     MOV        this,dword ptr [ESI + 0x6d4]
//         004b2327     MOV        EDX,dword ptr [this->_padding_]
//         004b2329     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b232b     PUSH       offset DAT_fffffff8
//         004b232d     PUSH       offset DAT_fffffff4
//         004b232f     PUSH       offset DAT_fffffff0
//         004b2331     CALL       dword ptr [EDX + 0x1c]
//         004b2334     MOV        this,dword ptr [ESI + 0x6d8]
//         004b233a     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b233c     PUSH       offset DAT_fffffff8
//         004b233e     PUSH       offset DAT_fffffff4
//         004b2340     MOV        EAX,dword ptr [this->_padding_]
//         004b2342     PUSH       offset DAT_fffffff0
//         004b2344     CALL       dword ptr [EAX + 0x1c]
//         004b2347     MOV        this,dword ptr [ESI + 0x6dc]
//         004b234d     PUSH       0x12
//                              language.dll match for 0x78: "10"
//         004b234f     PUSH       offset DAT_fffffff8
//         004b2351     PUSH       offset DAT_fffffff4
//         004b2353     MOV        EDX,dword ptr [this->_padding_]
//         004b2355     PUSH       offset DAT_fffffff0
//         004b2357     CALL       dword ptr [EDX + 0x1c]
//         004b235a     MOV        this,dword ptr [ESI + 0x6f4]
//         004b2360     PUSH       0x12
//         004b2362     PUSH       offset DAT_fffffff8
//         004b2364     PUSH       offset DAT_fffffff4
//         004b2366     MOV        EAX,dword ptr [this->_padding_]
//         004b2368     PUSH       offset DAT_fffffff0
//         004b236d     CALL       dword ptr [EAX + 0x1c]
//         004b2370     MOV        this,dword ptr [ESI + 0x6f8]
//         004b2376     PUSH       0x16
//         004b2378     PUSH       offset DAT_fffffff8
//         004b237a     PUSH       offset DAT_fffffff4
//         004b237c     MOV        EDX,dword ptr [this->_padding_]
//         004b237e     PUSH       offset DAT_fffffff0
//         004b2383     CALL       dword ptr [EDX + 0x1c]
//         004b2386     MOV        this,dword ptr [ESI + 0x6fc]
//         004b238c     PUSH       0x12
//         004b238e     PUSH       offset DAT_fffffff8
//         004b2393     PUSH       offset DAT_fffffff4
//         004b2395     MOV        EAX,dword ptr [this->_padding_]
//         004b2397     PUSH       offset DAT_fffffff0
//         004b239c     CALL       dword ptr [EAX + 0x1c]
//         004b239f     MOV        this,dword ptr [ESI + 0x700]
//         004b23a5     PUSH       0x16
//         004b23a7     PUSH       offset DAT_fffffff8
//         004b23ac     PUSH       offset DAT_fffffff4
//         004b23ae     MOV        EDX,dword ptr [this->_padding_]
//         004b23b0     PUSH       offset DAT_fffffff0
//         004b23b5     CALL       dword ptr [EDX + 0x1c]
//         004b23b8     MOV        this,dword ptr [ESI + 0x668]
//         004b23be     PUSH       0x12
//         004b23c0     PUSH       offset DAT_fffffff8
//         004b23c2     PUSH       offset DAT_fffffff4
//         004b23c4     MOV        EAX,dword ptr [this->_padding_]
//         004b23c6     PUSH       offset DAT_fffffff0
//         004b23cb     CALL       dword ptr [EAX + 0x1c]
//         004b23ce     MOV        this,dword ptr [ESI + 0x66c]
//         004b23d4     PUSH       0x12
//         004b23d6     PUSH       offset DAT_fffffff8
//         004b23d8     PUSH       offset DAT_fffffff4
//         004b23da     MOV        EDX,dword ptr [this->_padding_]
//         004b23dc     PUSH       offset DAT_fffffff0
//         004b23e1     CALL       dword ptr [EDX + 0x1c]
//         004b23e4     MOV        this,dword ptr [ESI + 0x670]
//         004b23ea     PUSH       0x12
//         004b23ec     PUSH       offset DAT_fffffff8
//         004b23ee     PUSH       offset DAT_fffffff4
//         004b23f0     MOV        EAX,dword ptr [this->_padding_]
//         004b23f2     PUSH       offset DAT_fffffff0
//         004b23f7     CALL       dword ptr [EAX + 0x1c]
//         004b23fa     MOV        this,dword ptr [ESI + 0x674]
//         004b2400     PUSH       0x12
//         004b2402     PUSH       offset DAT_fffffff8
//         004b2404     PUSH       offset DAT_fffffff4
//         004b2406     MOV        EDX,dword ptr [this->_padding_]
//         004b2408     PUSH       offset DAT_fffffff0
//         004b240d     CALL       dword ptr [EDX + 0x1c]
//         004b2410     MOV        this,dword ptr [ESI + 0x678]
//         004b2416     PUSH       0x12
//         004b2418     PUSH       offset DAT_fffffff8
//         004b241a     PUSH       offset DAT_fffffff4
//         004b241c     MOV        EAX,dword ptr [this->_padding_]
//         004b241e     PUSH       offset DAT_fffffff0
//         004b2423     CALL       dword ptr [EAX + 0x1c]
//         004b2426     MOV        this,dword ptr [ESI + 0x67c]
//         004b242c     PUSH       0x12
//         004b242e     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x76: "B"
//         004b2430     PUSH       offset DAT_fffffff4
//         004b2432     MOV        EDX,dword ptr [this->_padding_]
//         004b2434     PUSH       offset DAT_fffffff0
//         004b2439     CALL       dword ptr [EDX + 0x1c]
//         004b243c     MOV        this,dword ptr [ESI + 0x69c]
//         004b2442     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2444     PUSH       offset DAT_fffffff8
//         004b2449     PUSH       offset DAT_fffffff4
//         004b244b     MOV        EAX,dword ptr [this->_padding_]
//         004b244d     PUSH       offset DAT_fffffff0
//         004b2452     CALL       dword ptr [EAX + 0x1c]
//         004b2455     MOV        this,dword ptr [ESI + 0x6a0]
//         004b245b     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b245d     PUSH       offset DAT_fffffff8
//         004b2462     PUSH       offset DAT_fffffff4
//         004b2464     MOV        EDX,dword ptr [this->_padding_]
//         004b2466     PUSH       offset DAT_fffffff0
//         004b246b     CALL       dword ptr [EDX + 0x1c]
//         004b246e     MOV        this,dword ptr [ESI + 0x6a8]
//         004b2474     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2476     PUSH       offset DAT_fffffff8
//         004b247b     PUSH       offset DAT_fffffff4
//         004b247d     MOV        EAX,dword ptr [this->_padding_]
//         004b247f     PUSH       offset DAT_fffffff0
//         004b2484     CALL       dword ptr [EAX + 0x1c]
//         004b2487     MOV        this,dword ptr [ESI + 0x6ac]
//         004b248d     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b248f     PUSH       offset DAT_fffffff8
//         004b2494     PUSH       offset DAT_fffffff4
//         004b2496     MOV        EDX,dword ptr [this->_padding_]
//         004b2498     PUSH       offset DAT_fffffff0
//         004b249d     CALL       dword ptr [EDX + 0x1c]
//         004b24a0     MOV        this,dword ptr [ESI + 0x6b0]
//         004b24a6     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b24a8     PUSH       offset DAT_fffffff8
//         004b24ad     PUSH       offset DAT_fffffff4
//         004b24af     MOV        EAX,dword ptr [this->_padding_]
//         004b24b1     PUSH       offset DAT_fffffff0
//         004b24b6     CALL       dword ptr [EAX + 0x1c]
//         004b24b9     MOV        this,dword ptr [ESI + 0x68c]
//         004b24bf     PUSH       0x12
//         004b24c1     PUSH       offset DAT_fffffff8
//         004b24c3     PUSH       0x0=>DAT_fffffff4
//         004b24c5     MOV        EDX,dword ptr [this->_padding_]
//         004b24c7     PUSH       offset DAT_fffffff0
//         004b24cc     CALL       dword ptr [EDX + 0x1c]
//         004b24cf     MOV        this,dword ptr [ESI + 0x6b8]
//         004b24d5     PUSH       0x12
//         004b24d7     PUSH       offset DAT_fffffff8
//         004b24d9     PUSH       offset DAT_fffffff4
//         004b24db     MOV        EAX,dword ptr [this->_padding_]
//         004b24dd     PUSH       offset DAT_fffffff0
//         004b24e2     CALL       dword ptr [EAX + 0x1c]
//         004b24e5     MOV        this,dword ptr [ESI + 0x6bc]
//         004b24eb     PUSH       0x12
//         004b24ed     PUSH       offset DAT_fffffff8
//         004b24ef     PUSH       offset DAT_fffffff4
//         004b24f1     MOV        EDX,dword ptr [this->_padding_]
//         004b24f3     PUSH       offset DAT_fffffff0
//         004b24f8     CALL       dword ptr [EDX + 0x1c]
//         004b24fb     MOV        this,dword ptr [ESI + 0x6c0]
//         004b2501     PUSH       0x12
//         004b2503     PUSH       offset DAT_fffffff8
//         004b2505     PUSH       offset DAT_fffffff4
//         004b2507     MOV        EAX,dword ptr [this->_padding_]
//         004b2509     PUSH       offset DAT_fffffff0
//         004b250e     CALL       dword ptr [EAX + 0x1c]
//         004b2511     MOV        this,dword ptr [ESI + 0x6c4]
//         004b2517     PUSH       0x12
//         004b2519     PUSH       offset DAT_fffffff8
//         004b251b     PUSH       offset DAT_fffffff4
//         004b251d     MOV        EDX,dword ptr [this->_padding_]
//         004b251f     PUSH       offset DAT_fffffff0
//         004b2524     CALL       dword ptr [EDX + 0x1c]
//         004b2527     MOV        this,dword ptr [ESI + 0x680]
//         004b252d     MOV        EAX,dword ptr [this->_padding_]
//         004b252f     PUSH       0x12
//         004b2531     PUSH       offset DAT_fffffff8
//         004b2533     PUSH       offset DAT_fffffff4
//         004b2535     PUSH       offset DAT_fffffff0
//         004b253a     CALL       dword ptr [EAX + 0x1c]
//         004b253d     MOV        this,dword ptr [ESI + 0x684]
//         004b2543     PUSH       0x12
//         004b2545     PUSH       offset DAT_fffffff8
//         004b2547     PUSH       offset DAT_fffffff4
//         004b2549     MOV        EDX,dword ptr [this->_padding_]
//         004b254b     PUSH       offset DAT_fffffff0
//         004b2550     CALL       dword ptr [EDX + 0x1c]
//         004b2553     MOV        this,dword ptr [ESI + 0x694]
//         004b2559     PUSH       0x12
//         004b255b     PUSH       offset DAT_fffffff8
//         004b255d     PUSH       offset DAT_fffffff4
//         004b255f     MOV        EAX,dword ptr [this->_padding_]
//         004b2561     PUSH       offset DAT_fffffff0
//         004b2566     CALL       dword ptr [EAX + 0x1c]
//         004b2569     MOV        this,dword ptr [ESI + 0x698]
//         004b256f     PUSH       0x12
//         004b2571     PUSH       offset DAT_fffffff8
//         004b2573     PUSH       offset DAT_fffffff4
//         004b2575     MOV        EDX,dword ptr [this->_padding_]
//         004b2577     PUSH       offset DAT_fffffff0
//         004b257c     CALL       dword ptr [EDX + 0x1c]
//         004b257f     XOR        EDI,EDI
//         004b2581     LEA        EBX,[ESI + 0x704]
//                               LAB_004b2587                                                 XREF[1]:     004b25c9(j)
//         004b2587     MOV        EAX,EDI
//         004b2589     PUSH       0x16
//         004b258b     CDQ
//         004b258c     XOR        EAX,EDX
//         004b258e     PUSH       offset DAT_fffffff8
//         004b2590     SUB        EAX,EDX
//         004b2592     MOV        this,dword ptr [EBX]
//         004b2594     AND        EAX,0x3
//         004b2597     XOR        EAX,EDX
//         004b2599     MOV        EBP,dword ptr [this->_padding_]
//         004b259b     SUB        EAX,EDX
//         004b259d     LEA        EDX,[EAX + EAX*0x2]
//         004b25a0     LEA        EAX,[EAX + EDX*0x4]
//         004b25a3     LEA        EDX,[EAX + EAX*0x1 + 0x1e]
//         004b25a7     MOV        EAX,EDI
//         004b25a9     PUSH       EDX=>DAT_fffffff4
//         004b25aa     CDQ
//         004b25ab     AND        EDX,0x3
//         004b25ae     ADD        EAX,EDX
//         004b25b0     SAR        EAX,0x2
//         004b25b3     LEA        EAX,[EAX + EAX*0x2]
//         004b25b6     SHL        EAX,0x4
//         004b25b9     ADD        EAX,0xdc
//         004b25be     PUSH       EAX=>DAT_fffffff0
//         004b25bf     CALL       dword ptr [EBP + 0x1c]
//         004b25c2     INC        EDI
//         004b25c3     ADD        EBX,0x4
//         004b25c6     CMP        EDI,0xc
//         004b25c9     JL         LAB_004b2587
//         004b25cb     MOV        this,dword ptr [ESI + 0x73c]
//         004b25d1     PUSH       0x16
//         004b25d3     PUSH       offset DAT_fffffff8
//         004b25d8     PUSH       offset DAT_fffffff4
//         004b25da     MOV        EDX,dword ptr [this->_padding_]
//         004b25dc     PUSH       offset DAT_fffffff0
//         004b25de     CALL       dword ptr [EDX + 0x1c]
//         004b25e1     MOV        this,dword ptr [ESI + 0x734]
//         004b25e7     PUSH       0x16
//         004b25e9     PUSH       offset DAT_fffffff8
//         004b25ee     PUSH       offset DAT_fffffff4
//         004b25f0     MOV        EAX,dword ptr [this->_padding_]
//         004b25f2     PUSH       offset DAT_fffffff0
//         004b25f4     CALL       dword ptr [EAX + 0x1c]
//         004b25f7     MOV        this,dword ptr [ESI + 0x75c]
//         004b25fd     PUSH       0x16
//         004b25ff     PUSH       offset DAT_fffffff8
//         004b2604     PUSH       offset DAT_fffffff4
//         004b2606     MOV        EDX,dword ptr [this->_padding_]
//         004b2608     PUSH       offset DAT_fffffff0
//         004b260d     CALL       dword ptr [EDX + 0x1c]
//         004b2610     MOV        this,dword ptr [ESI + 0x750]
//         004b2616     PUSH       0x16
//         004b2618     PUSH       offset DAT_fffffff8
//         004b261d     PUSH       offset DAT_fffffff4
//         004b261f     MOV        EAX,dword ptr [this->_padding_]
//         004b2621     PUSH       offset DAT_fffffff0
//         004b2623     CALL       dword ptr [EAX + 0x1c]
//         004b2626     MOV        this,dword ptr [ESI + 0x754]
//         004b262c     PUSH       0x16
//         004b262e     PUSH       offset DAT_fffffff8
//         004b2633     PUSH       offset DAT_fffffff4
//         004b2635     MOV        EDX,dword ptr [this->_padding_]
//         004b2637     PUSH       offset DAT_fffffff0
//         004b2639     CALL       dword ptr [EDX + 0x1c]
//         004b263c     MOV        this,dword ptr [ESI + 0x758]
//         004b2642     PUSH       0x16
//         004b2644     PUSH       offset DAT_fffffff8
//         004b2649     PUSH       offset DAT_fffffff4
//         004b264b     MOV        EAX,dword ptr [this->_padding_]
//         004b264d     PUSH       offset DAT_fffffff0
//         004b264f     CALL       dword ptr [EAX + 0x1c]
//         004b2652     MOV        this,dword ptr [ESI + 0x764]
//         004b2658     PUSH       0x16
//         004b265a     PUSH       offset DAT_fffffff8
//         004b265c     PUSH       offset DAT_fffffff4
//         004b265e     MOV        EDX,dword ptr [this->_padding_]
//         004b2660     PUSH       offset DAT_fffffff0
//         004b2665     CALL       dword ptr [EDX + 0x1c]
//         004b2668     MOV        this,dword ptr [ESI + 0x76c]
//         004b266e     PUSH       0x16
//         004b2670     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         004b2672     PUSH       offset DAT_fffffff4
//         004b2674     MOV        EAX,dword ptr [this->_padding_]
//         004b2676     PUSH       offset DAT_fffffff0
//         004b267b     CALL       dword ptr [EAX + 0x1c]
//         004b267e     MOV        this,dword ptr [ESI + 0x740]
//         004b2684     PUSH       0x16
//         004b2686     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         004b268b     PUSH       offset DAT_fffffff4
//         004b268d     MOV        EDX,dword ptr [this->_padding_]
//         004b268f     PUSH       offset DAT_fffffff0
//         004b2691     CALL       dword ptr [EDX + 0x1c]
//         004b2694     MOV        this,dword ptr [ESI + 0x744]
//         004b269a     PUSH       0x16
//         004b269c     PUSH       offset DAT_fffffff8
//         004b26a1     PUSH       offset DAT_fffffff4
//         004b26a3     MOV        EAX,dword ptr [this->_padding_]
//         004b26a5     PUSH       offset DAT_fffffff0
//         004b26a7     CALL       dword ptr [EAX + 0x1c]
//         004b26aa     MOV        this,dword ptr [ESI + 0x768]
//         004b26b0     PUSH       0x16
//         004b26b2     PUSH       offset DAT_fffffff8
//         004b26b7     PUSH       offset DAT_fffffff4
//         004b26b9     MOV        EDX,dword ptr [this->_padding_]
//         004b26bb     PUSH       offset DAT_fffffff0
//         004b26bd     CALL       dword ptr [EDX + 0x1c]
//         004b26c0     MOV        this,dword ptr [ESI + 0x738]
//         004b26c6     PUSH       0x16
//         004b26c8     PUSH       offset DAT_fffffff8
//         004b26cd     MOV        EAX,dword ptr [this->_padding_]
//         004b26cf     PUSH       offset DAT_fffffff4
//         004b26d1     PUSH       offset DAT_fffffff0
//         004b26d3     CALL       dword ptr [EAX + 0x1c]
//         004b26d6     MOV        this,dword ptr [ESI + 0x748]
//         004b26dc     PUSH       0x16
//         004b26de     PUSH       offset DAT_fffffff8
//         004b26e3     PUSH       offset DAT_fffffff4
//         004b26e5     MOV        EDX,dword ptr [this->_padding_]
//         004b26e7     PUSH       offset DAT_fffffff0
//         004b26e9     CALL       dword ptr [EDX + 0x1c]
//         004b26ec     MOV        this,dword ptr [ESI + 0x74c]
//         004b26f2     PUSH       0x16
//         004b26f4     PUSH       offset DAT_fffffff8
//         004b26f9     PUSH       offset DAT_fffffff4
//         004b26fb     MOV        EAX,dword ptr [this->_padding_]
//         004b26fd     PUSH       offset DAT_fffffff0
//         004b26ff     CALL       dword ptr [EAX + 0x1c]
//         004b2702     MOV        EDI,0x8
//         004b2707     LEA        EBX,[ESI + 0x78c]
//                               LAB_004b270d                                                 XREF[1]:     004b2739(j)
//         004b270d     MOV        this,dword ptr [EBX + -0x14]
//         004b2710     PUSH       0x12
//         004b2712     PUSH       offset DAT_fffffff8
//         004b2714     PUSH       EDI=>DAT_fffffff4
//         004b2715     MOV        EDX,dword ptr [this->_padding_]
//         004b2717     PUSH       offset DAT_fffffff0
//         004b2719     CALL       dword ptr [EDX + 0x1c]
//         004b271c     MOV        this,dword ptr [EBX]
//         004b271e     PUSH       0x12
//                              language.dll match for 0x82: "B"
//         004b2720     PUSH       offset DAT_fffffff8
//         004b2725     PUSH       EDI=>DAT_fffffff4
//         004b2726     MOV        EAX,dword ptr [this->_padding_]
//         004b2728     PUSH       offset DAT_fffffff0
//         004b272a     CALL       dword ptr [EAX + 0x1c]
//         004b272d     ADD        EDI,0x19
//         004b2730     ADD        EBX,0x4
//         004b2733     CMP        EDI,0x85
//         004b2739     JL         LAB_004b270d
//         004b273b     MOV        this,dword ptr [ESI + 0x774]
//         004b2741     PUSH       0x0
//         004b2743     PUSH       0x0=>DAT_fffffff8
//         004b2745     PUSH       0x0=>DAT_fffffff4
//         004b2747     MOV        EDX,dword ptr [this->_padding_]
//         004b2749     PUSH       0x0=>DAT_fffffff0
//         004b274b     PUSH       0x0
//         004b274d     PUSH       0x0
//         004b274f     PUSH       0x0
//         004b2751     PUSH       0x0
//         004b2753     PUSH       0x4
//         004b2755     PUSH       0x28
//         004b2757     PUSH       0x4
//         004b2759     PUSH       0xaf
//         004b275e     PUSH       0x7
//         004b2760     CALL       dword ptr [EDX + 0x18]
//         004b2763     MOV        EDI,0x16
//         004b2768     LEA        EBX,[ESI + 0x7b4]
//                               LAB_004b276e                                                 XREF[1]:     004b27a0(j)
//         004b276e     MOV        this,dword ptr [EBX + -0x10]
//         004b2771     PUSH       0x12
//         004b2773     LEA        EDX,[EDI + -0x12]
//         004b2776     PUSH       offset DAT_fffffff8
//         004b277b     MOV        EAX,dword ptr [this->_padding_]
//         004b277d     PUSH       EDX=>DAT_fffffff4
//         004b277e     PUSH       offset DAT_fffffff0
//         004b2780     CALL       dword ptr [EAX + 0x1c]
//         004b2783     MOV        this,dword ptr [EBX]
//         004b2785     PUSH       0x16
//         004b2787     PUSH       offset DAT_fffffff8
//         004b278c     PUSH       EDI=>DAT_fffffff4
//         004b278d     MOV        EAX,dword ptr [this->_padding_]
//         004b278f     PUSH       offset DAT_fffffff0
//         004b2791     CALL       dword ptr [EAX + 0x1c]
//         004b2794     ADD        EDI,0x2c
//         004b2797     ADD        EBX,0x4
//         004b279a     CMP        EDI,0x9a
//         004b27a0     JL         LAB_004b276e
//         004b27a2     MOV        this,dword ptr [ESI + 0x7b0]
//         004b27a8     PUSH       0x12
//         004b27aa     PUSH       offset DAT_fffffff8
//         004b27af     PUSH       offset DAT_fffffff4
//         004b27b1     MOV        EDX,dword ptr [this->_padding_]
//         004b27b3     PUSH       offset DAT_fffffff0
//         004b27b8     CALL       dword ptr [EDX + 0x1c]
//         004b27bb     MOV        this,dword ptr [ESI + 0x7c0]
//         004b27c1     PUSH       0x16
//         004b27c3     PUSH       offset DAT_fffffff8
//         004b27c8     PUSH       offset DAT_fffffff4
//         004b27ca     MOV        EAX,dword ptr [this->_padding_]
//         004b27cc     PUSH       offset DAT_fffffff0
//         004b27d1     CALL       dword ptr [EAX + 0x1c]
//         004b27d4     MOV        EBX,0x2c
//         004b27d9     LEA        EDI,[ESI + 0x7c4]
//                               LAB_004b27df                                                 XREF[1]:     004b2808(j)
//         004b27df     MOV        this,dword ptr [EDI + 0x4]
//         004b27e2     PUSH       0x14
//         004b27e4     PUSH       offset DAT_fffffff8
//         004b27e6     PUSH       EBX=>DAT_fffffff4
//         004b27e7     MOV        EDX,dword ptr [this->_padding_]
//         004b27e9     PUSH       offset DAT_fffffff0
//         004b27eb     CALL       dword ptr [EDX + 0x1c]
//         004b27ee     MOV        this,dword ptr [EDI]
//         004b27f0     PUSH       0x14
//         004b27f2     PUSH       offset DAT_fffffff8
//         004b27f7     PUSH       EBX=>DAT_fffffff4
//         004b27f8     MOV        EAX,dword ptr [this->_padding_]
//         004b27fa     PUSH       offset DAT_fffffff0
//         004b27fc     CALL       dword ptr [EAX + 0x1c]
//         004b27ff     ADD        EBX,0x1a
//         004b2802     ADD        EDI,0x4
//         004b2805     CMP        EBX,0x46
//         004b2808     JL         LAB_004b27df
//         004b280a     MOV        this,dword ptr [ESI + 0x7d0]
//         004b2810     PUSH       0x16
//         004b2812     PUSH       offset DAT_fffffff8
//         004b2817     PUSH       offset DAT_fffffff4
//         004b2819     MOV        EDX,dword ptr [this->_padding_]
//         004b281b     PUSH       offset DAT_fffffff0
//         004b2820     CALL       dword ptr [EDX + 0x1c]
//         004b2823     MOV        this,dword ptr [ESI + 0x7cc]
//         004b2829     PUSH       0x16
//         004b282b     PUSH       offset DAT_fffffff8
//         004b2830     PUSH       offset DAT_fffffff4
//         004b2832     MOV        EAX,dword ptr [this->_padding_]
//         004b2834     PUSH       offset DAT_fffffff0
//         004b2836     CALL       dword ptr [EAX + 0x1c]
//         004b2839     LEA        EBX,[ESI + 0x814]
//         004b283f     MOV        EDI,0x1a
//                               LAB_004b2844                                                 XREF[1]:     004b2873(j)
//         004b2844     MOV        this,dword ptr [EBX + -0x40]
//         004b2847     PUSH       0x14
//         004b2849     PUSH       offset DAT_fffffff8
//         004b284b     PUSH       EDI=>DAT_fffffff4
//         004b284c     MOV        EDX,dword ptr [this->_padding_]
//         004b284e     PUSH       offset DAT_fffffff0
//         004b2853     CALL       dword ptr [EDX + 0x1c]
//         004b2856     MOV        this,dword ptr [EBX]
//         004b2858     PUSH       0x14
//         004b285a     PUSH       offset DAT_fffffff8
//         004b285f     PUSH       EDI=>DAT_fffffff4
//         004b2860     MOV        EAX,dword ptr [this->_padding_]
//         004b2862     PUSH       offset DAT_fffffff0
//         004b2867     CALL       dword ptr [EAX + 0x1c]
//         004b286a     ADD        EDI,0x14
//         004b286d     ADD        EBX,0x4
//         004b2870     CMP        EDI,0x7e
//         004b2873     JL         LAB_004b2844
//         004b2875     LEA        EBX,[ESI + 0x828]
//         004b287b     MOV        EDI,0x1a
//                               LAB_004b2880                                                 XREF[1]:     004b28af(j)
//         004b2880     MOV        this,dword ptr [EBX + -0x40]
//         004b2883     PUSH       0x14
//         004b2885     PUSH       offset DAT_fffffff8
//         004b2887     PUSH       EDI=>DAT_fffffff4
//         004b2888     MOV        EDX,dword ptr [this->_padding_]
//         004b288a     PUSH       offset DAT_fffffff0
//         004b288f     CALL       dword ptr [EDX + 0x1c]
//         004b2892     MOV        this,dword ptr [EBX]
//         004b2894     PUSH       0x14
//         004b2896     PUSH       offset DAT_fffffff8
//         004b289b     PUSH       EDI=>DAT_fffffff4
//         004b289c     MOV        EAX,dword ptr [this->_padding_]
//         004b289e     PUSH       offset DAT_fffffff0
//         004b28a3     CALL       dword ptr [EAX + 0x1c]
//         004b28a6     ADD        EDI,0x14
//         004b28a9     ADD        EBX,0x4
//         004b28ac     CMP        EDI,0x7e
//         004b28af     JL         LAB_004b2880
//         004b28b1     LEA        EBX,[ESI + 0x83c]
//         004b28b7     MOV        EDI,0x6
//                               LAB_004b28bc                                                 XREF[1]:     004b28eb(j)
//         004b28bc     MOV        this,dword ptr [EBX + -0x40]
//         004b28bf     PUSH       0x14
//         004b28c1     PUSH       offset DAT_fffffff8
//         004b28c3     PUSH       EDI=>DAT_fffffff4
//         004b28c4     MOV        EDX,dword ptr [this->_padding_]
//         004b28c6     PUSH       offset DAT_fffffff0
//         004b28cb     CALL       dword ptr [EDX + 0x1c]
//         004b28ce     MOV        this,dword ptr [EBX]
//         004b28d0     PUSH       0x14
//         004b28d2     PUSH       offset DAT_fffffff8
//         004b28d7     PUSH       EDI=>DAT_fffffff4
//         004b28d8     MOV        EAX,dword ptr [this->_padding_]
//         004b28da     PUSH       offset DAT_fffffff0
//         004b28df     CALL       dword ptr [EAX + 0x1c]
//         004b28e2     ADD        EDI,0x14
//         004b28e5     ADD        EBX,0x4
//         004b28e8     CMP        EDI,0x7e
//         004b28eb     JL         LAB_004b28bc
//         004b28ed     MOV        this,dword ptr [ESI + 0x894]
//         004b28f3     PUSH       0x16
//         004b28f5     PUSH       offset DAT_fffffff8
//         004b28fa     PUSH       offset DAT_fffffff4
//         004b28fc     MOV        EDX,dword ptr [this->_padding_]
//         004b28fe     PUSH       offset DAT_fffffff0
//         004b2900     CALL       dword ptr [EDX + 0x1c]
//         004b2903     MOV        EDI,0x96
//         004b2908     LEA        EBP,[ESI + 0x908]
//         004b290e     LEA        EBX,[ESI + 0x8ac]
//                               LAB_004b2914                                                 XREF[1]:     004b2970(j)
//         004b2914     MOV        this,dword ptr [EBP + 0xffffff6c]
//         004b291a     PUSH       0x16
//         004b291c     PUSH       offset DAT_fffffff8
//         004b291e     PUSH       offset DAT_fffffff4
//         004b2920     MOV        EAX,dword ptr [this->_padding_]
//         004b2922     PUSH       EDI=>DAT_fffffff0
//         004b2923     CALL       dword ptr [EAX + 0x1c]
//         004b2926     MOV        this,dword ptr [EBX + -0x4]
//         004b2929     PUSH       0x12
//         004b292b     PUSH       offset DAT_fffffff8
//         004b292d     PUSH       offset DAT_fffffff4
//         004b292f     MOV        EDX,dword ptr [this->_padding_]
//         004b2931     PUSH       EDI=>DAT_fffffff0
//         004b2932     CALL       dword ptr [EDX + 0x1c]
//         004b2935     MOV        this,dword ptr [EBX]
//         004b2937     PUSH       0x12
//         004b2939     PUSH       offset DAT_fffffff8
//         004b293b     PUSH       offset DAT_fffffff4
//         004b293d     MOV        EAX,dword ptr [this->_padding_]
//         004b293f     PUSH       EDI=>DAT_fffffff0
//         004b2940     CALL       dword ptr [EAX + 0x1c]
//         004b2943     MOV        this,dword ptr [EBX + 0x4]
//         004b2946     PUSH       0x12
//         004b2948     PUSH       offset DAT_fffffff8
//         004b294a     PUSH       offset DAT_fffffff4
//         004b294c     MOV        EDX,dword ptr [this->_padding_]
//         004b294e     PUSH       EDI=>DAT_fffffff0
//         004b294f     CALL       dword ptr [EDX + 0x1c]
//         004b2952     MOV        this,dword ptr [EBP]
//         004b2955     PUSH       0x12
//         004b2957     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x70: "B"
//         004b2959     PUSH       offset DAT_fffffff4
//         004b295b     MOV        EAX,dword ptr [this->_padding_]
//         004b295d     PUSH       EDI=>DAT_fffffff0
//         004b295e     CALL       dword ptr [EAX + 0x1c]
//         004b2961     ADD        EDI,0x1f
//         004b2964     ADD        EBP,0x4
//         004b2967     ADD        EBX,0xc
//         004b296a     CMP        EDI,0x18e
//         004b2970     JL         LAB_004b2914
//         004b2972     MOV        this,dword ptr [ESI + 0x898]
//         004b2978     PUSH       0x16
//         004b297a     PUSH       offset DAT_fffffff8
//         004b297f     PUSH       offset DAT_fffffff4
//         004b2981     MOV        EDX,dword ptr [this->_padding_]
//         004b2983     PUSH       offset DAT_fffffff0
//         004b2985     CALL       dword ptr [EDX + 0x1c]
//         004b2988     MOV        this,dword ptr [ESI + 0x89c]
//         004b298e     PUSH       0x16
//         004b2990     PUSH       offset DAT_fffffff8
//         004b2995     PUSH       offset DAT_fffffff4
//         004b2997     MOV        EAX,dword ptr [this->_padding_]
//         004b2999     PUSH       offset DAT_fffffff0
//         004b299b     CALL       dword ptr [EAX + 0x1c]
//         004b299e     MOV        this,dword ptr [ESI + 0x8a0]
//         004b29a4     PUSH       0x16
//         004b29a6     PUSH       offset DAT_fffffff8
//         004b29ab     PUSH       offset DAT_fffffff4
//         004b29ad     MOV        EDX,dword ptr [this->_padding_]
//         004b29af     PUSH       offset DAT_fffffff0
//         004b29b1     CALL       dword ptr [EDX + 0x1c]
//         004b29b4     MOV        ESI,dword ptr [ESI + 0x8a4]
//         004b29ba     PUSH       0x16
//         004b29bc     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x70: "B"
//         004b29c1     PUSH       offset DAT_fffffff4
//         004b29c3     MOV        EAX,dword ptr [ESI]
//         004b29c5     PUSH       offset DAT_fffffff0
//         004b29c7     MOV        this,ESI
//         004b29c9     CALL       dword ptr [EAX + 0x1c]
//         004b29cc     POP        EBX
//         004b29cd     POP        EBP
//         004b29ce     POP        EDI
//                               LAB_004b29cf                                                 XREF[1]:     004b1a5b(j)
//         004b29cf     POP        ESI
//         004b29d0     RET
//         004b29d1     ??         90h
//         004b29d2     NOP
//         004b29d3     NOP
//         004b29d4     NOP
//         004b29d5     NOP
//         004b29d6     NOP
//         004b29d7     NOP
//         004b29d8     NOP
//         004b29d9     NOP
//         004b29da     NOP
//         004b29db     NOP
//         004b29dc     NOP
//         004b29dd     NOP
//         004b29de     NOP
//         004b29df     NOP
    return;
}

void TRIBE_Screen_Sed::activate_victory_panel(int param_1) {
    /* TODO: Stub */
//                              void __thiscall activate_victory_panel(TRIBE_Screen_Sed * this, int
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004b29e1(R)
//                               ?activate_victory_panel@TRIBE_Screen_Sed@@IAEXH@Z            XREF[5]:     set_scenario_mode:004aa10c(c),
//                               TRIBE_Screen_Sed::activate_victory_panel                                  action:004ac0bb(c),
//                                                                                                         action:004ac108(c),
//                                                                                                         action:004ac425(c),
//                                                                                                         action:004ac44e(c)
//                              scr_sed2.cpp:2183 (1)
//         004b29e0     PUSH       EBX
//                              scr_sed2.cpp:2186 (17)
//         004b29e1     MOV        EBX,dword ptr [ESP + param_1]
//         004b29e5     PUSH       EBP
//         004b29e6     PUSH       ESI
//         004b29e7     PUSH       EDI
//         004b29e8     MOV        EDI,this
//         004b29ea     XOR        ESI,ESI
//         004b29ec     LEA        EBP,[EDI + 0x704]
//                               LAB_004b29f2                                                 XREF[1]:     004b2a37(j)
//                              scr_sed2.cpp:2188 (9)
//         004b29f2     MOV        this,dword ptr [EBP]
//         004b29f5     PUSH       EBX
//         004b29f6     MOV        EAX,dword ptr [this->_padding_]
//         004b29f8     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:2189 (37)
//         004b29fb     MOV        this,dword ptr [EDI + 0x928]
//         004b2a01     PUSH       ESI
//         004b2a02     MOV        this,dword ptr [ECX + this->_padding_]
//         004b2a05     CALL       T_Scenario::GetSPVictoryType                     int GetSPVictoryType(T_Scenario * this, int p
//         004b2a0a     MOV        this,dword ptr [EDI + 0x498]
//         004b2a10     NEG        EAX
//         004b2a12     SBB        EAX,EAX
//         004b2a14     XOR        EDX,EDX
//         004b2a16     AND        EAX,0x2
//         004b2a19     CMP        this,ESI
//         004b2a1b     SETZ       DL
//         004b2a1e     ADD        EAX,EDX
//                              scr_sed2.cpp:2190 (4)
//         004b2a20     TEST       EBX,EBX
//         004b2a22     JZ         LAB_004b2a30
//                              scr_sed2.cpp:2191 (21)
//         004b2a24     MOV        this,dword ptr [EBP]
//         004b2a27     PUSH       EAX
//         004b2a28     MOV        EDX,dword ptr [this->_padding_]
//         004b2a2a     CALL       dword ptr [EDX + 0xe0]
//                               LAB_004b2a30                                                 XREF[1]:     004b2a22(j)
//         004b2a30     INC        ESI
//         004b2a31     ADD        EBP,0x4
//         004b2a34     CMP        ESI,0xc
//         004b2a37     JL         LAB_004b29f2
//                              scr_sed2.cpp:2193 (12)
//         004b2a39     MOV        this,dword ptr [EDI + 0x734]
//         004b2a3f     PUSH       EBX
//         004b2a40     MOV        EAX,dword ptr [this->_padding_]
//         004b2a42     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:2194 (12)
//         004b2a45     MOV        this,dword ptr [EDI + 0x75c]
//         004b2a4b     PUSH       EBX
//         004b2a4c     MOV        EDX,dword ptr [this->_padding_]
//         004b2a4e     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:2195 (12)
//         004b2a51     MOV        this,dword ptr [EDI + 0x73c]
//         004b2a57     PUSH       EBX
//         004b2a58     MOV        EAX,dword ptr [this->_padding_]
//         004b2a5a     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:2197 (4)
//         004b2a5d     TEST       EBX,EBX
//         004b2a5f     JZ         LAB_004b2a7c
//                              scr_sed2.cpp:2198 (20)
//         004b2a61     MOVSX      this,word ptr [EDI + 0x4b8]
//         004b2a68     DEC        this
//         004b2a69     PUSH       this
//         004b2a6a     MOV        this,dword ptr [EDI + 0x73c]
//         004b2a70     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2201 (7)
//         004b2a75     POP        EDI
//         004b2a76     POP        ESI
//         004b2a77     POP        EBP
//         004b2a78     POP        EBX
//         004b2a79     RET        0x4
//                               LAB_004b2a7c                                                 XREF[1]:     004b2a5f(j)
//                              scr_sed2.cpp:2200 (19)
//         004b2a7c     MOV        this,dword ptr [EDI + 0x73c]
//         004b2a82     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//         004b2a87     INC        EAX
//         004b2a88     MOV        word ptr [EDI + 0x4b8],AX
//                              scr_sed2.cpp:2201 (7)
//         004b2a8f     POP        EDI
//         004b2a90     POP        ESI
//         004b2a91     POP        EBP
//         004b2a92     POP        EBX
//         004b2a93     RET        0x4
//         004b2a96     ??         90h
//         004b2a97     NOP
//         004b2a98     NOP
//         004b2a99     NOP
//         004b2a9a     NOP
//         004b2a9b     NOP
//         004b2a9c     NOP
//         004b2a9d     NOP
//         004b2a9e     NOP
//         004b2a9f     NOP
    return;
}

int TRIBE_Screen_Sed::MakeFileList(TDropDownPanel* param_1, char* param_2, char* param_3, uchar param_4, uchar param_5) {
    /* TODO: Stub */
//                              int __thiscall MakeFileList(TRIBE_Screen_Sed * this, TDropDownPanel
//              int               EAX:4          <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              TDropDownPanel    Stack[0x4]:4   param_1                   XREF[1]:     004b2aa7(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     004b2af9(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     004b2af2(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004b2ac0(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     004b2ad9(R)
//              char[260]         Stack[-0x108   path                      XREF[0,2]:   004b2b02(*), 004b2b1b(*)
//              char[260]         Stack[-0x20c   file_name                 XREF[0,2]:   004b2b59(*), 004b2b76(*)
//              _finddata_t       Stack[-0x324   fileInfo                  XREF[2,4]:   004b2b3b(W), 004b2b55(R), 004b2b17(*), 004b2b8f(*),
//                                                                                     004b2b4f(*), 004b2b65(*)
//              int               Stack[-0x328   extension_strlen          XREF[4]:     004b2ab3(W), 004b2b41(R), 004b2b4b(W), 004b2ba2(R)
//              int               Stack[-0x32c   count
//                               ?MakeFileList@TRIBE_Screen_Sed@@IAEHPAVTDropDownPanel@@PAD1  XREF[1]:     create_drop_down:004a92f2(c)
//                               TRIBE_Screen_Sed::MakeFileList
//                              scr_sed2.cpp:2206 (7)
//         004b2aa0     SUB        ESP,0x328
//         004b2aa6     PUSH       EBX
//                              scr_sed2.cpp:2215 (25)
//         004b2aa7     MOV        EBX,dword ptr [ESP + param_1]
//         004b2aae     PUSH       EBP
//         004b2aaf     PUSH       ESI
//         004b2ab0     PUSH       EDI
//         004b2ab1     MOV        this,EBX
//         004b2ab3     MOV        dword ptr [ESP + extension_strlen],0x0
//         004b2abb     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2216 (11)
//         004b2ac0     MOV        AL,byte ptr [ESP + param_4]
//         004b2ac7     TEST       AL,AL
//         004b2ac9     JZ         LAB_004b2ad9
//                              scr_sed2.cpp:2217 (14)
//         004b2acb     PUSH       0x0
//                              language.dll match for 0x2775: " <None> "
//         004b2acd     PUSH       0x2775
//         004b2ad2     MOV        this,EBX
//         004b2ad4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                               LAB_004b2ad9                                                 XREF[1]:     004b2ac9(j)
//                              scr_sed2.cpp:2219 (11)
//         004b2ad9     MOV        AL,byte ptr [ESP + param_5]
//         004b2ae0     TEST       AL,AL
//         004b2ae2     JZ         LAB_004b2af2
//                              scr_sed2.cpp:2220 (14)
//         004b2ae4     PUSH       0x0
//                              language.dll match for 0x277b: "Random"
//         004b2ae6     PUSH       0x277b
//         004b2aeb     MOV        this,EBX
//         004b2aed     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                               LAB_004b2af2                                                 XREF[1]:     004b2ae2(j)
//                              scr_sed2.cpp:2222 (37)
//         004b2af2     MOV        EDI,dword ptr [ESP + param_3]
//         004b2af9     MOV        EAX,dword ptr [ESP + param_2]
//         004b2b00     PUSH       EDI
//         004b2b01     PUSH       EAX
//         004b2b02     LEA        this=>path[4],[ESP + 0x23c]
//         004b2b09     PUSH       s_%s*%s                                          = "%s*%s"
//         004b2b0e     PUSH       this
//         004b2b0f     CALL       sprintf                                          undefined sprintf()
//         004b2b14     ADD        ESP,0x10
//                              scr_sed2.cpp:2225 (20)
//         004b2b17     LEA        EDX=>fileInfo.time_create,[ESP + 0x18]
//         004b2b1b     LEA        EAX=>path[4],[ESP + 0x234]
//         004b2b22     PUSH       EDX
//         004b2b23     PUSH       EAX
//         004b2b24     CALL       __findfirst                                      undefined __findfirst()
//         004b2b29     MOV        EBP,EAX
//                              scr_sed2.cpp:2227 (13)
//         004b2b2b     OR         this,0xffffffff
//         004b2b2e     XOR        EAX,EAX
//         004b2b30     ADD        ESP,0x8
//         004b2b33     SCASB.RE   ES:EDI
//         004b2b35     NOT        this
//         004b2b37     DEC        this
//                              scr_sed2.cpp:2228 (9)
//         004b2b38     CMP        EBP,-0x1
//         004b2b3b     MOV        dword ptr [ESP + fileInfo.attrib],this
//         004b2b3f     JZ         LAB_004b2ba2
//                               LAB_004b2b41                                                 XREF[1]:     004b2ba0(j)
//                              scr_sed2.cpp:2230 (4)
//         004b2b41     MOV        EDI,dword ptr [ESP + extension_strlen]
//                              scr_sed2.cpp:2231 (20)
//         004b2b45     OR         this,0xffffffff
//         004b2b48     INC        EDI
//         004b2b49     XOR        EAX,EAX
//         004b2b4b     MOV        dword ptr [ESP + extension_strlen],EDI
//         004b2b4f     LEA        EDI=>fileInfo+0x18,[ESP + 0x2c]
//         004b2b53     SCASB.RE   ES:EDI
//         004b2b55     MOV        EAX,dword ptr [ESP + fileInfo.attrib]
//                              scr_sed2.cpp:2232 (29)
//         004b2b59     LEA        EDX=>file_name[4],[ESP + 0x130]
//         004b2b60     NOT        this
//         004b2b62     DEC        this
//         004b2b63     MOV        ESI,this
//         004b2b65     LEA        this=>fileInfo+0x18,[ESP + 0x2c]
//         004b2b69     SUB        ESI,EAX
//         004b2b6b     PUSH       ESI
//         004b2b6c     PUSH       this
//         004b2b6d     PUSH       EDX
//         004b2b6e     CALL       strncpy                                          undefined strncpy()
//         004b2b73     ADD        ESP,0xc
//                              scr_sed2.cpp:2234 (25)
//         004b2b76     LEA        EAX=>file_name[4],[ESP + 0x130]
//         004b2b7d     MOV        this,EBX
//         004b2b7f     MOV        byte ptr [ESP + ESI*0x1 + 0x130],0x0
//         004b2b87     PUSH       0x0
//         004b2b89     PUSH       EAX
//         004b2b8a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_sed2.cpp:2235 (19)
//         004b2b8f     LEA        this=>fileInfo.time_create,[ESP + 0x18]
//         004b2b93     PUSH       this
//         004b2b94     PUSH       EBP
//         004b2b95     CALL       __findnext                                       undefined __findnext()
//         004b2b9a     ADD        ESP,0x8
//         004b2b9d     CMP        EAX,-0x1
//         004b2ba0     JNZ        LAB_004b2b41
//                               LAB_004b2ba2                                                 XREF[1]:     004b2b3f(j)
//                              scr_sed2.cpp:2239 (4)
//         004b2ba2     MOV        EAX,dword ptr [ESP + extension_strlen]
//                              scr_sed2.cpp:2240 (13)
//         004b2ba6     POP        EDI
//         004b2ba7     POP        ESI
//         004b2ba8     POP        EBP
//         004b2ba9     POP        EBX
//         004b2baa     ADD        ESP,0x328
//         004b2bb0     RET        0x14
//         004b2bb3     ??         90h
//         004b2bb4     NOP
//         004b2bb5     NOP
//         004b2bb6     NOP
//         004b2bb7     NOP
//         004b2bb8     NOP
//         004b2bb9     NOP
//         004b2bba     NOP
//         004b2bbb     NOP
//         004b2bbc     NOP
//         004b2bbd     NOP
//         004b2bbe     NOP
//         004b2bbf     NOP
    return 0;
}

int TRIBE_Screen_Sed::Set_player_advance_civilization_text(int param_1) {
    /* TODO: Stub */
//                              int __thiscall Set_player_advance_civilization_text(TRIBE_Screen_Sed
//              int               EAX:4          <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?Set_player_advance_civilization_text@TRIBE_Screen_Sed@@IAE  XREF[1]:     create_all_buttons_etc:004b033b(c)
//                               TRIBE_Screen_Sed::Set_player_advance_civilization_text
//                              scr_sed2.cpp:2243 (3)
//         004b2bc0     PUSH       ESI
//         004b2bc1     MOV        ESI,this
//                              scr_sed2.cpp:2244 (11)
//         004b2bc3     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2bc9     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2245 (18)
//         004b2bce     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2bd4     PUSH       0x0
//                              language.dll match for 0x1069: "Stone Age"
//         004b2bd6     PUSH       0x1069
//         004b2bdb     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2246 (18)
//         004b2be0     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2be6     PUSH       0x1
//                              language.dll match for 0x106a: "Tool Age"
//         004b2be8     PUSH       0x106a
//         004b2bed     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2247 (18)
//         004b2bf2     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2bf8     PUSH       0x2
//                              language.dll match for 0x106b: "Bronze Age"
//         004b2bfa     PUSH       0x106b
//         004b2bff     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2248 (18)
//         004b2c04     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2c0a     PUSH       0x3
//                              language.dll match for 0x106c: "Iron Age"
//         004b2c0c     PUSH       0x106c
//         004b2c11     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2249 (18)
//         004b2c16     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2c1c     PUSH       0x4
//                              language.dll match for 0x106d: "Post-Iron Age"
//         004b2c1e     PUSH       0x106d
//         004b2c23     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2251 (13)
//         004b2c28     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2c2e     PUSH       0x0
//         004b2c30     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
//                              scr_sed2.cpp:2252 (13)
//         004b2c35     MOV        this,dword ptr [ESI + 0x5bc]
//         004b2c3b     PUSH       0x0
//         004b2c3d     MOV        EAX,dword ptr [this->_padding_]
//         004b2c3f     CALL       dword ptr [EAX + 0x14]
//                              scr_sed2.cpp:2253 (5)
//         004b2c42     MOV        EAX,0x1
//                              scr_sed2.cpp:2254 (4)
//         004b2c47     POP        ESI
//         004b2c48     RET        0x4
//         004b2c4b     ??         90h
//         004b2c4c     NOP
//         004b2c4d     NOP
//         004b2c4e     NOP
//         004b2c4f     NOP
    return 0;
}

void TRIBE_Screen_Sed::SavePlayerActiveStatus() {
    /* TODO: Stub */
//                              void __thiscall SavePlayerActiveStatus(TRIBE_Screen_Sed * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//                               ?SavePlayerActiveStatus@TRIBE_Screen_Sed@@IAEXXZ             XREF[4]:     TRIBE_Screen_Sed:004a8685(c),
//                               TRIBE_Screen_Sed::SavePlayerActiveStatus                                  set_scenario_mode:004a9ef6(c),
//                                                                                                         action:004ac9db(c),
//                                                                                                         command_new_map:004ad57a(c)
//                              scr_sed2.cpp:2258 (5)
//         004b2c50     PUSH       EBX
//         004b2c51     PUSH       ESI
//         004b2c52     MOV        ESI,this
//         004b2c54     PUSH       EDI
//                              scr_sed2.cpp:2259 (13)
//         004b2c55     MOV        this,dword ptr [ESI + 0x5b8]
//         004b2c5b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//         004b2c60     MOV        EBX,EAX
//                              scr_sed2.cpp:2261 (18)
//         004b2c62     MOV        EAX,dword ptr [ESI + 0x928]
//         004b2c68     INC        EBX
//         004b2c69     XOR        EDI,EDI
//         004b2c6b     MOVSX      this,word ptr [EAX + 0x3c]
//         004b2c6f     DEC        this
//         004b2c70     TEST       this,this
//         004b2c72     JLE        LAB_004b2c95
//                               LAB_004b2c74                                                 XREF[1]:     004b2c93(j)
//                              scr_sed2.cpp:2262 (33)
//         004b2c74     MOV        this,dword ptr [EAX + 0x5c]
//         004b2c77     XOR        EDX,EDX
//         004b2c79     CMP        EDI,EBX
//         004b2c7b     SETL       DL
//         004b2c7e     PUSH       EDX
//         004b2c7f     PUSH       EDI
//         004b2c80     CALL       RGE_Scenario::Set_player_Active                  void Set_player_Active(RGE_Scenario * this, i
//         004b2c85     MOV        EAX,dword ptr [ESI + 0x928]
//         004b2c8b     INC        EDI
//         004b2c8c     MOVSX      this,word ptr [EAX + 0x3c]
//         004b2c90     DEC        this
//         004b2c91     CMP        EDI,this
//         004b2c93     JL         LAB_004b2c74
//                               LAB_004b2c95                                                 XREF[1]:     004b2c72(j)
//                              scr_sed2.cpp:2264 (11)
//         004b2c95     MOV        this,dword ptr [ESI + 0x73c]
//         004b2c9b     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2265 (11)
//         004b2ca0     MOV        this,dword ptr [ESI + 0x740]
//         004b2ca6     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2266 (11)
//         004b2cab     MOV        this,dword ptr [ESI + 0x7cc]
//         004b2cb1     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2267 (11)
//         004b2cb6     MOV        this,dword ptr [ESI + 0x894]
//         004b2cbc     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2268 (11)
//         004b2cc1     MOV        this,dword ptr [ESI + 0x5b4]
//         004b2cc7     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2269 (11)
//         004b2ccc     MOV        this,dword ptr [ESI + 0x618]
//         004b2cd2     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_sed2.cpp:2271 (18)
//         004b2cd7     MOV        this,dword ptr [ESI + 0x618]
//         004b2cdd     PUSH       0x0
//                              language.dll match for 0x2776: "Gaia"
//         004b2cdf     PUSH       0x2776
//         004b2ce4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2272 (4)
//         004b2ce9     TEST       EBX,EBX
//         004b2ceb     JLE        LAB_004b2d51
//                              language.dll match for 0x2865: "Player 1"
//                              scr_sed2.cpp:2264 (5)
//         004b2ced     MOV        EDI,0x2865
//                               LAB_004b2cf2                                                 XREF[1]:     004b2d4f(j)
//                              scr_sed2.cpp:2274 (14)
//         004b2cf2     MOV        this,dword ptr [ESI + 0x618]
//         004b2cf8     PUSH       0x0
//         004b2cfa     PUSH       EDI
//         004b2cfb     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2275 (14)
//         004b2d00     MOV        this,dword ptr [ESI + 0x73c]
//         004b2d06     PUSH       0x0
//         004b2d08     PUSH       EDI
//         004b2d09     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2276 (14)
//         004b2d0e     MOV        this,dword ptr [ESI + 0x740]
//         004b2d14     PUSH       0x0
//         004b2d16     PUSH       EDI
//         004b2d17     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2277 (14)
//         004b2d1c     MOV        this,dword ptr [ESI + 0x7cc]
//         004b2d22     PUSH       0x0
//         004b2d24     PUSH       EDI
//         004b2d25     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2278 (14)
//         004b2d2a     MOV        this,dword ptr [ESI + 0x894]
//         004b2d30     PUSH       0x0
//         004b2d32     PUSH       EDI
//         004b2d33     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_sed2.cpp:2279 (25)
//         004b2d38     MOV        this,dword ptr [ESI + 0x5b4]
//         004b2d3e     PUSH       0x0
//         004b2d40     PUSH       EDI
//         004b2d41     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//         004b2d46     INC        EDI
//         004b2d47     LEA        EDX,[EDI + 0xffffd79b]
//         004b2d4d     CMP        EDX,EBX
//         004b2d4f     JL         LAB_004b2cf2
//                               LAB_004b2d51                                                 XREF[1]:     004b2ceb(j)
//                              scr_sed2.cpp:2282 (11)
//         004b2d51     MOVSX      EAX,word ptr [ESI + 0x4b8]
//         004b2d58     CMP        EAX,EBX
//         004b2d5a     JL         LAB_004b2d68
//                              scr_sed2.cpp:2283 (12)
//         004b2d5c     PUSH       0x0
//         004b2d5e     PUSH       0x0
//         004b2d60     PUSH       EBX
//         004b2d61     MOV        this,ESI
//         004b2d63     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
//                               LAB_004b2d68                                                 XREF[1]:     004b2d5a(j)
//                              scr_sed2.cpp:2285 (20)
//         004b2d68     MOVSX      this,word ptr [ESI + 0x4b8]
//         004b2d6f     DEC        this
//         004b2d70     PUSH       this
//         004b2d71     MOV        this,dword ptr [ESI + 0x73c]
//         004b2d77     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2286 (20)
//         004b2d7c     MOVSX      EDX,word ptr [ESI + 0x4b8]
//         004b2d83     MOV        this,dword ptr [ESI + 0x7cc]
//         004b2d89     DEC        EDX
//         004b2d8a     PUSH       EDX
//         004b2d8b     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2287 (20)
//         004b2d90     MOVSX      EAX,word ptr [ESI + 0x4b8]
//         004b2d97     MOV        this,dword ptr [ESI + 0x894]
//         004b2d9d     DEC        EAX
//         004b2d9e     PUSH       EAX
//         004b2d9f     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2288 (20)
//         004b2da4     MOVSX      this,word ptr [ESI + 0x4b8]
//         004b2dab     DEC        this
//         004b2dac     PUSH       this
//         004b2dad     MOV        this,dword ptr [ESI + 0x5b4]
//         004b2db3     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2289 (19)
//         004b2db8     MOVSX      EDX,word ptr [ESI + 0x4b8]
//         004b2dbf     MOV        this,dword ptr [ESI + 0x618]
//         004b2dc5     PUSH       EDX
//         004b2dc6     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_sed2.cpp:2290 (4)
//         004b2dcb     POP        EDI
//         004b2dcc     POP        ESI
//         004b2dcd     POP        EBX
//         004b2dce     RET
//         004b2dcf     ??         90h
    return;
}

int TRIBE_Screen_Sed::create_check_box(TPanel* param_1, TButtonPanel** param_2) {
    /* TODO: Stub */
//                              int __thiscall create_check_box(TRIBE_Screen_Sed * this, TPanel * pa
//              int               EAX:4          <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b2dd0(R)
//              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004b2dd6(R)
//                               ?create_check_box@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTBu  XREF[9]:     create_all_buttons_etc:004b0692(c)
//                               TRIBE_Screen_Sed::create_check_box                                        create_all_buttons_etc:004b06bd(c)
//                                                                                                         create_all_buttons_etc:004b06e8(c)
//                                                                                                         create_all_buttons_etc:004b0713(c)
//                                                                                                         create_all_buttons_etc:004b073e(c)
//                                                                                                         create_all_buttons_etc:004b0769(c)
//                                                                                                         create_all_buttons_etc:004b1486(c)
//                                                                                                         create_all_buttons_etc:004b14ea(c)
//                                                                                                         create_all_buttons_etc:004b196e(c)
//                              scr_sed2.cpp:2296 (35)
//         004b2dd0     MOV        EAX,dword ptr [ESP + param_1]
//         004b2dd4     PUSH       ESI
//         004b2dd5     PUSH       EDI
//         004b2dd6     MOV        EDI,dword ptr [ESP + param_2]
//         004b2dda     PUSH       0x0
//         004b2ddc     PUSH       0x1
//         004b2dde     PUSH       0x0
//         004b2de0     PUSH       0x0
//         004b2de2     PUSH       0x0
//         004b2de4     PUSH       0x0
//         004b2de6     PUSH       EDI
//         004b2de7     MOV        ESI,this
//         004b2de9     PUSH       EAX
//         004b2dea     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
//         004b2def     TEST       EAX,EAX
//         004b2df1     JNZ        LAB_004b2df8
//                              scr_sed2.cpp:2307 (5)
//         004b2df3     POP        EDI
//         004b2df4     POP        ESI
//         004b2df5     RET        0x8
//                               LAB_004b2df8                                                 XREF[1]:     004b2df1(j)
//                              scr_sed2.cpp:2300 (11)
//         004b2df8     MOV        this,dword ptr [EDI]
//         004b2dfa     PUSH       0x0
//         004b2dfc     PUSH       0x1
//         004b2dfe     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              scr_sed2.cpp:2301 (9)
//         004b2e03     MOV        this,dword ptr [EDI]
//         004b2e05     PUSH       0x0
//         004b2e07     MOV        EDX,dword ptr [this->_padding_]
//         004b2e09     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:2303 (10)
//         004b2e0c     MOV        EAX,dword ptr [ESI + 0x31c]
//         004b2e12     TEST       EAX,EAX
//         004b2e14     JZ         LAB_004b2e55
//                              scr_sed2.cpp:2304 (63)
//         004b2e16     XOR        EAX,EAX
//         004b2e18     XOR        this,this
//         004b2e1a     MOV        AL,byte ptr [ESI + 0x325]
//         004b2e20     MOV        this,byte ptr [ESI + 0x324]
//         004b2e26     XOR        EDX,EDX
//         004b2e28     PUSH       EAX
//         004b2e29     MOV        DL,byte ptr [ESI + 0x323]
//         004b2e2f     PUSH       this=>DAT_fffffff8
//         004b2e30     XOR        EAX,EAX
//         004b2e32     PUSH       EDX=>DAT_fffffff4
//         004b2e33     MOV        AL,byte ptr [ESI + 0x322]
//         004b2e39     XOR        this,this
//         004b2e3b     MOV        this,byte ptr [ESI + 0x321]
//         004b2e41     XOR        EDX,EDX
//         004b2e43     MOV        DL,byte ptr [ESI + 0x320]
//         004b2e49     PUSH       EAX=>DAT_fffffff0
//         004b2e4a     PUSH       this
//         004b2e4b     MOV        this,dword ptr [EDI]
//         004b2e4d     PUSH       EDX
//         004b2e4e     PUSH       0x3
//         004b2e50     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int
//                               LAB_004b2e55                                                 XREF[1]:     004b2e14(j)
//                              scr_sed2.cpp:2307 (10)
//         004b2e55     POP        EDI
//         004b2e56     MOV        EAX,0x1
//         004b2e5b     POP        ESI
//         004b2e5c     RET        0x8
//         004b2e5f     ??         90h
    return 0;
}

int TRIBE_Screen_Sed::create_radio_button(TPanel* param_1, TButtonPanel** param_2) {
    /* TODO: Stub */
//                              int __thiscall create_radio_button(TRIBE_Screen_Sed * this, TPanel *
//              int               EAX:4          <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b2e60(R)
//              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004b2e66(R)
//                               ?create_radio_button@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAV  XREF[26]:    create_all_buttons_etc:004af948(c)
//                               TRIBE_Screen_Sed::create_radio_button                                     create_all_buttons_etc:004af974(c)
//                                                                                                         create_all_buttons_etc:004af99f(c)
//                                                                                                         create_all_buttons_etc:004afc90(c)
//                                                                                                         create_all_buttons_etc:004afcbc(c)
//                                                                                                         create_all_buttons_etc:004afce7(c)
//                                                                                                         create_all_buttons_etc:004afd12(c)
//                                                                                                         create_all_buttons_etc:004afd3d(c)
//                                                                                                         create_all_buttons_etc:004afe34(c)
//                                                                                                         create_all_buttons_etc:004afe5f(c)
//                                                                                                         create_all_buttons_etc:004afe8a(c)
//                                                                                                         create_all_buttons_etc:004affb3(c)
//                                                                                                         create_all_buttons_etc:004affde(c)
//                                                                                                         create_all_buttons_etc:004b0009(c)
//                                                                                                         create_all_buttons_etc:004b0034(c)
//                                                                                                         create_all_buttons_etc:004b0794(c)
//                                                                                                         create_all_buttons_etc:004b07bf(c)
//                                                                                                         create_all_buttons_etc:004b0b90(c)
//                                                                                                         create_all_buttons_etc:004b0bbb(c)
//                                                                                                         create_all_buttons_etc:004b0be6(c)
//                                                                                                         [more]
//                              scr_sed2.cpp:2313 (35)
//         004b2e60     MOV        EAX,dword ptr [ESP + param_1]
//         004b2e64     PUSH       ESI
//         004b2e65     PUSH       EDI
//         004b2e66     MOV        EDI,dword ptr [ESP + param_2]
//         004b2e6a     PUSH       0x0
//         004b2e6c     PUSH       0x1
//         004b2e6e     PUSH       0x0
//         004b2e70     PUSH       0x0
//         004b2e72     PUSH       0x0
//         004b2e74     PUSH       0x0
//         004b2e76     PUSH       EDI
//         004b2e77     MOV        ESI,this
//         004b2e79     PUSH       EAX
//         004b2e7a     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
//         004b2e7f     TEST       EAX,EAX
//         004b2e81     JNZ        LAB_004b2e88
//                              scr_sed2.cpp:2324 (5)
//         004b2e83     POP        EDI
//         004b2e84     POP        ESI
//         004b2e85     RET        0x8
//                               LAB_004b2e88                                                 XREF[1]:     004b2e81(j)
//                              scr_sed2.cpp:2317 (11)
//         004b2e88     MOV        this,dword ptr [EDI]
//         004b2e8a     PUSH       0x0
//         004b2e8c     PUSH       0x1
//         004b2e8e     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              scr_sed2.cpp:2318 (9)
//         004b2e93     MOV        this,dword ptr [EDI]
//         004b2e95     PUSH       0x0
//         004b2e97     MOV        EDX,dword ptr [this->_padding_]
//         004b2e99     CALL       dword ptr [EDX + 0x14]
//                              scr_sed2.cpp:2320 (10)
//         004b2e9c     MOV        EAX,dword ptr [ESI + 0x31c]
//         004b2ea2     TEST       EAX,EAX
//         004b2ea4     JZ         LAB_004b2ee5
//                              scr_sed2.cpp:2321 (63)
//         004b2ea6     XOR        EAX,EAX
//         004b2ea8     XOR        this,this
//         004b2eaa     MOV        AL,byte ptr [ESI + 0x325]
//         004b2eb0     MOV        this,byte ptr [ESI + 0x324]
//         004b2eb6     XOR        EDX,EDX
//         004b2eb8     PUSH       EAX
//         004b2eb9     MOV        DL,byte ptr [ESI + 0x323]
//         004b2ebf     PUSH       this=>DAT_fffffff8
//         004b2ec0     XOR        EAX,EAX
//         004b2ec2     PUSH       EDX=>DAT_fffffff4
//         004b2ec3     MOV        AL,byte ptr [ESI + 0x322]
//         004b2ec9     XOR        this,this
//         004b2ecb     MOV        this,byte ptr [ESI + 0x321]
//         004b2ed1     XOR        EDX,EDX
//         004b2ed3     MOV        DL,byte ptr [ESI + 0x320]
//         004b2ed9     PUSH       EAX=>DAT_fffffff0
//         004b2eda     PUSH       this
//         004b2edb     MOV        this,dword ptr [EDI]
//         004b2edd     PUSH       EDX
//         004b2ede     PUSH       0x3
//         004b2ee0     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int
//                               LAB_004b2ee5                                                 XREF[1]:     004b2ea4(j)
//                              scr_sed2.cpp:2324 (10)
//         004b2ee5     POP        EDI
//         004b2ee6     MOV        EAX,0x1
//         004b2eeb     POP        ESI
//         004b2eec     RET        0x8
//         004b2eef     ??         90h
    return 0;
}

