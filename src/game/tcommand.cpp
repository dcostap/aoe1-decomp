#include "../common.h"
#include "tcommand.h"

TRIBE_Command::TRIBE_Command(TRIBE_World* param_1, TCommunications_Handler* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Command(TRIBE_Command * this, TRIBE_World
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_World *     Stack[0x4]:4   param_1                   XREF[1]:     00509728(R)
//              TCommunication    Stack[0x8]:4   param_2                   XREF[1]:     00509720(R)
//                               ??0TRIBE_Command@@QAE@PAVTRIBE_World@@PAVTCommunications_Ha  XREF[1]:     command_init:0052e56b(c)
//                               TRIBE_Command::TRIBE_Command
//                              tcommand.cpp:56 (26)
//         00509720     MOV        EAX,dword ptr [ESP + param_2]
//         00509724     PUSH       ESI
//         00509725     MOV        ESI,this
//         00509727     PUSH       EAX
//         00509728     MOV        this,dword ptr [ESP + param_1]
//         0050972c     PUSH       this
//         0050972d     MOV        this,ESI
//         0050972f     CALL       RGE_Command::RGE_Command                         undefined RGE_Command(RGE_Command * this, RGE
//         00509734     MOV        dword ptr [ESI],TRIBE_Command::`vftable'         = 00434920
//                              tcommand.cpp:57 (6)
//         0050973a     MOV        EAX,ESI
//         0050973c     POP        ESI
//         0050973d     RET        0x8
}

void TRIBE_Command::do_command(void* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command(TRIBE_Command * this, void * param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0050977f(R)
//                               ?do_command@TRIBE_Command@@EAEXPAX@Z                         XREF[1]:     00576560(*)
//                               TRIBE_Command::do_command
//                              tcommand.cpp:62 (1)
//         00509770     PUSH       ESI
//                              tcommand.cpp:63 (14)
//         00509771     PUSH       0x3f
//         00509773     MOV        ESI,this
//         00509775     PUSH       s_C:\msdev\work\age1_x1\tcommand.c               = "C:\\msdev\\work\\age1_x1\\tcommand.cpp"
//         0050977a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//                              tcommand.cpp:66 (38)
//         0050977f     MOV        EAX,dword ptr [ESP + param_1]
//         00509783     XOR        this,this
//         00509785     ADD        ESP,0x8
//         00509788     MOV        this,byte ptr [EAX]
//         0050978a     ADD        this,-0x4
//         0050978d     CMP        this,0x73
//         00509790     JA         switchD_0050979e::caseD_5
//         00509796     XOR        EDX,EDX
//         00509798     MOV        DL,byte ptr [this->field0_0x0 + 0x509898]=>PTR   = 0050984d
//                               switchD_0050979e::switchD
//         0050979e     JMP        dword ptr [EDX*0x4 + switchD_0050979e::switchd   = 005097ed
//                               switchD_0050979e::caseD_64                                   XREF[2]:     0050979e(j), 00509860(*)
//                              tcommand.cpp:69 (8)
//         005097a5     PUSH       EAX
//         005097a6     MOV        this,ESI
//         005097a8     CALL       TRIBE_Command::do_command_make                   void do_command_make(TRIBE_Command * this, TR
//                              tcommand.cpp:125 (4)
//         005097ad     POP        ESI
//         005097ae     RET        0x4
//                               switchD_0050979e::caseD_65                                   XREF[2]:     0050979e(j), 00509864(*)
//                              tcommand.cpp:73 (8)
//         005097b1     PUSH       EAX
//         005097b2     MOV        this,ESI
//         005097b4     CALL       TRIBE_Command::do_command_research               void do_command_research(TRIBE_Command * this
//                              tcommand.cpp:125 (4)
//         005097b9     POP        ESI
//         005097ba     RET        0x4
//                               switchD_0050979e::caseD_66                                   XREF[2]:     0050979e(j), 00509868(*)
//                              tcommand.cpp:77 (8)
//         005097bd     PUSH       EAX
//         005097be     MOV        this,ESI
//         005097c0     CALL       TRIBE_Command::do_command_build                  void do_command_build(TRIBE_Command * this, T
//                              tcommand.cpp:125 (4)
//         005097c5     POP        ESI
//         005097c6     RET        0x4
//                               switchD_0050979e::caseD_69                                   XREF[2]:     0050979e(j), 00509874(*)
//                              tcommand.cpp:81 (8)
//         005097c9     PUSH       EAX
//         005097ca     MOV        this,ESI
//         005097cc     CALL       TRIBE_Command::do_command_build_wall             void do_command_build_wall(TRIBE_Command * th
//                              tcommand.cpp:125 (4)
//         005097d1     POP        ESI
//         005097d2     RET        0x4
//                               switchD_0050979e::caseD_68                                   XREF[2]:     0050979e(j), 00509870(*)
//                              tcommand.cpp:85 (8)
//         005097d5     PUSH       EAX
//         005097d6     MOV        this,ESI
//         005097d8     CALL       TRIBE_Command::do_command_explore                void do_command_explore(TRIBE_Command * this,
//                              tcommand.cpp:125 (4)
//         005097dd     POP        ESI
//         005097de     RET        0x4
//                               switchD_0050979e::caseD_67                                   XREF[2]:     0050979e(j), 0050986c(*)
//                              tcommand.cpp:89 (8)
//         005097e1     PUSH       EAX
//         005097e2     MOV        this,ESI
//         005097e4     CALL       TRIBE_Command::do_command_game                   void do_command_game(TRIBE_Command * this, TR
//                              tcommand.cpp:125 (4)
//         005097e9     POP        ESI
//         005097ea     RET        0x4
//                               switchD_0050979e::caseD_4                                    XREF[2]:     0050979e(j), 0050985c(*)
//                              tcommand.cpp:93 (8)
//         005097ed     PUSH       EAX
//         005097ee     MOV        this,ESI
//         005097f0     CALL       TRIBE_Command::do_command_tribe_create           void do_command_tribe_create(TRIBE_Command *
//                              tcommand.cpp:125 (4)
//         005097f5     POP        ESI
//         005097f6     RET        0x4
//                               switchD_0050979e::caseD_6a                                   XREF[2]:     0050979e(j), 00509878(*)
//                              tcommand.cpp:97 (8)
//         005097f9     PUSH       EAX
//         005097fa     MOV        this,ESI
//         005097fc     CALL       TRIBE_Command::do_command_cancel_build           void do_command_cancel_build(TRIBE_Command *
//                              tcommand.cpp:125 (4)
//         00509801     POP        ESI
//         00509802     RET        0x4
//                               switchD_0050979e::caseD_6b                                   XREF[2]:     0050979e(j), 0050987c(*)
//                              tcommand.cpp:100 (8)
//         00509805     PUSH       EAX
//         00509806     MOV        this,ESI
//         00509808     CALL       TRIBE_Command::do_command_attack_ground          void do_command_attack_ground(TRIBE_Command *
//                              tcommand.cpp:125 (4)
//         0050980d     POP        ESI
//         0050980e     RET        0x4
//                               switchD_0050979e::caseD_6c                                   XREF[2]:     0050979e(j), 00509880(*)
//                              tcommand.cpp:103 (8)
//         00509811     MOV        EDX,dword ptr [ESI]
//         00509813     PUSH       EAX
//         00509814     MOV        this,ESI
//         00509816     CALL       dword ptr [EDX + 0x10]
//                              tcommand.cpp:125 (4)
//         00509819     POP        ESI
//         0050981a     RET        0x4
//                               switchD_0050979e::caseD_6d                                   XREF[2]:     0050979e(j), 00509884(*)
//                              tcommand.cpp:106 (8)
//         0050981d     PUSH       EAX
//         0050981e     MOV        this,ESI
//         00509820     CALL       TRIBE_Command::do_command_trade_attribute        void do_command_trade_attribute(TRIBE_Command
//                              tcommand.cpp:125 (4)
//         00509825     POP        ESI
//         00509826     RET        0x4
//                               switchD_0050979e::caseD_6e                                   XREF[2]:     0050979e(j), 00509888(*)
//                              tcommand.cpp:110 (8)
//         00509829     PUSH       EAX
//         0050982a     MOV        this,ESI
//         0050982c     CALL       TRIBE_Command::do_command_repair                 void do_command_repair(TRIBE_Command * this,
//                              tcommand.cpp:125 (4)
//         00509831     POP        ESI
//         00509832     RET        0x4
//                               switchD_0050979e::caseD_6f                                   XREF[2]:     0050979e(j), 0050988c(*)
//                              tcommand.cpp:114 (8)
//         00509835     PUSH       EAX
//         00509836     MOV        this,ESI
//         00509838     CALL       TRIBE_Command::do_command_unload                 void do_command_unload(TRIBE_Command * this,
//                              tcommand.cpp:125 (4)
//         0050983d     POP        ESI
//         0050983e     RET        0x4
//                               switchD_0050979e::caseD_77                                   XREF[2]:     0050979e(j), 00509890(*)
//                              tcommand.cpp:118 (8)
//         00509841     PUSH       EAX
//         00509842     MOV        this,ESI
//         00509844     CALL       TRIBE_Command::do_command_queue                  void do_command_queue(TRIBE_Command * this, T
//                              tcommand.cpp:125 (4)
//         00509849     POP        ESI
//         0050984a     RET        0x4
//                               switchD_0050979e::caseD_6                                    XREF[3]:     00509790(j), 0050979e(j),
//                               switchD_0050979e::caseD_7                                                 00509894(*)
//                               switchD_0050979e::caseD_8
//                               switchD_0050979e::caseD_9
//                               switchD_0050979e::caseD_a
//                               switchD_0050979e::caseD_b
//                               switchD_0050979e::caseD_c
//                               switchD_0050979e::caseD_d
//                               switchD_0050979e::caseD_e
//                               switchD_0050979e::caseD_f
//                               switchD_0050979e::caseD_10
//                               switchD_0050979e::caseD_11
//                               switchD_0050979e::caseD_12
//                               switchD_0050979e::caseD_13
//                               switchD_0050979e::caseD_14
//                               switchD_0050979e::caseD_15
//                               switchD_0050979e::caseD_16
//                               switchD_0050979e::caseD_17
//                               switchD_0050979e::caseD_18
//                               switchD_0050979e::caseD_19
//                               switchD_0050979e::caseD_1a
//                               switchD_0050979e::caseD_1b
//                               switchD_0050979e::caseD_1c
//                               switchD_0050979e::caseD_1d
//                               switchD_0050979e::caseD_1e
//                               switchD_0050979e::caseD_1f
//                               switchD_0050979e::caseD_20
//                               switchD_0050979e::caseD_21
//                               switchD_0050979e::caseD_22
//                               switchD_0050979e::caseD_23
//                               switchD_0050979e::caseD_24
//                               switchD_0050979e::caseD_25
//                               switchD_0050979e::caseD_26
//                               switchD_0050979e::caseD_27
//                               switchD_0050979e::caseD_28
//                               switchD_0050979e::caseD_29
//                               switchD_0050979e::caseD_2a
//                               switchD_0050979e::caseD_2b
//                               switchD_0050979e::caseD_2c
//                               switchD_0050979e::caseD_2d
//                               switchD_0050979e::caseD_2e
//                               switchD_0050979e::caseD_2f
//                               switchD_0050979e::caseD_30
//                               switchD_0050979e::caseD_31
//                               switchD_0050979e::caseD_32
//                               switchD_0050979e::caseD_33
//                               switchD_0050979e::caseD_34
//                               switchD_0050979e::caseD_35
//                               switchD_0050979e::caseD_36
//                               switchD_0050979e::caseD_37
//                               switchD_0050979e::caseD_38
//                               switchD_0050979e::caseD_39
//                               switchD_0050979e::caseD_3a
//                               switchD_0050979e::caseD_3b
//                               switchD_0050979e::caseD_3c
//                               switchD_0050979e::caseD_3d
//                               switchD_0050979e::caseD_3e
//                               switchD_0050979e::caseD_3f
//                               switchD_0050979e::caseD_40
//                               switchD_0050979e::caseD_41
//                               switchD_0050979e::caseD_42
//                               switchD_0050979e::caseD_43
//                               switchD_0050979e::caseD_44
//                               switchD_0050979e::caseD_45
//                               switchD_0050979e::caseD_46
//                               switchD_0050979e::caseD_47
//                               switchD_0050979e::caseD_48
//                               switchD_0050979e::caseD_49
//                               switchD_0050979e::caseD_4a
//                               switchD_0050979e::caseD_4b
//                               switchD_0050979e::caseD_4c
//                               switchD_0050979e::caseD_4d
//                               switchD_0050979e::caseD_4e
//                               switchD_0050979e::caseD_4f
//                               switchD_0050979e::caseD_50
//                               switchD_0050979e::caseD_51
//                               switchD_0050979e::caseD_52
//                               switchD_0050979e::caseD_53
//                               switchD_0050979e::caseD_54
//                               switchD_0050979e::caseD_55
//                               switchD_0050979e::caseD_56
//                               switchD_0050979e::caseD_57
//                               switchD_0050979e::caseD_58
//                               switchD_0050979e::caseD_59
//                               switchD_0050979e::caseD_5a
//                               switchD_0050979e::caseD_5b
//                               switchD_0050979e::caseD_5c
//                               switchD_0050979e::caseD_5d
//                               switchD_0050979e::caseD_5e
//                               switchD_0050979e::caseD_5f
//                               switchD_0050979e::caseD_60
//                               switchD_0050979e::caseD_61
//                               switchD_0050979e::caseD_62
//                               switchD_0050979e::caseD_63
//                               switchD_0050979e::caseD_70
//                               switchD_0050979e::caseD_71
//                               switchD_0050979e::caseD_72
//                               switchD_0050979e::caseD_73
//                               switchD_0050979e::caseD_74
//                               switchD_0050979e::caseD_75
//                               switchD_0050979e::caseD_76
//                               switchD_0050979e::caseD_5
//                              tcommand.cpp:122 (8)
//         0050984d     PUSH       EAX
//         0050984e     MOV        this,ESI
//         00509850     CALL       RGE_Command::do_command                          void do_command(RGE_Command * this, void * pa
//                              tcommand.cpp:125 (183)
//         00509855     POP        ESI
//         00509856     RET        0x4
    return;
}

void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_tribe_create(TRIBE_Command * this, RGE_Co
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Command_Cr    Stack[0x4]:4   param_1                   XREF[1]:     00509910(R)
//                               ?do_command_tribe_create@TRIBE_Command@@AAEXPAURGE_Command_  XREF[1]:     do_command:005097f0(c)
//                               TRIBE_Command::do_command_tribe_create
//                              tcommand.cpp:130 (42)
//         00509910     MOV        EAX,dword ptr [ESP + param_1]
//         00509914     PUSH       ESI
//         00509915     PUSH       EDI
//         00509916     MOV        EDI,dword ptr [ECX + this->field4_0x4]
//         00509919     XOR        EDX,EDX
//         0050991b     MOV        DL,byte ptr [EAX + 0x4]
//         0050991e     MOV        EDI,dword ptr [EDI + 0x40]
//         00509921     MOVSX      ESI,word ptr [EAX + 0x2]
//         00509925     SHL        EDX,0x2
//         00509928     SHL        ESI,0x2
//         0050992b     MOV        EDI,dword ptr [EDI + EDX*0x1]
//         0050992e     MOV        EDI,dword ptr [EDI + 0x24]
//         00509931     MOV        EDI,dword ptr [EDI + ESI*0x1]
//         00509934     CMP        byte ptr [EDI + 0x68],0x1
//         00509938     JNZ        LAB_00509941
//                              tcommand.cpp:134 (7)
//         0050993a     MOV        dword ptr [EAX + 0x10],0x40800000
//                               LAB_00509941                                                 XREF[1]:     00509938(j)
//                              tcommand.cpp:136 (33)
//         00509941     MOV        this,dword ptr [ECX + this->field4_0x4]
//         00509944     MOV        EDI,dword ptr [EAX + 0x10]
//         00509947     PUSH       EDI
//         00509948     MOV        EDI,dword ptr [EAX + 0xc]
//         0050994b     MOV        this,dword ptr [this->field0_0x0 + 0x40]
//         0050994e     MOV        EAX,dword ptr [EAX + 0x8]
//         00509951     PUSH       EDI
//         00509952     PUSH       EAX
//         00509953     MOV        EDX,dword ptr [this->field0_0x0 + EDX*0x1]
//         00509956     PUSH       EDX
//         00509957     MOV        this,dword ptr [EDX + 0x24]
//         0050995a     MOV        this,dword ptr [this->field0_0x0 + ESI*0x1]
//         0050995d     MOV        ESI,dword ptr [this->field0_0x0]
//         0050995f     CALL       dword ptr [ESI + 0x18]
//                              tcommand.cpp:137 (9)
//         00509962     MOV        this,dword ptr [EAX + 0x8]
//         00509965     CMP        byte ptr [ECX + this->field4_0x4],0x50
//         00509969     JNZ        LAB_00509977
//                              tcommand.cpp:138 (12)
//         0050996b     PUSH       0x461c4000
//         00509970     MOV        this,EAX
//         00509972     CALL       TRIBE_Building_Object::build                     uchar build(TRIBE_Building_Object * this, flo
//                               LAB_00509977                                                 XREF[1]:     00509969(j)
//                              tcommand.cpp:139 (5)
//         00509977     POP        EDI
//         00509978     POP        ESI
//         00509979     RET        0x4
//         0050997c     ??         90h
//         0050997d     NOP
//         0050997e     NOP
//         0050997f     NOP
    return;
}

void TRIBE_Command::do_command_make(TRIBE_Command_Make* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_make(TRIBE_Command * this, TRIBE_Command_
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[3]:     0050999a(R), 005099ca(*), 005099da(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00509a06(W), 00509a2c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00509ada(R)
//              char[100]         Stack[-0x74]   work_name                 XREF[1,1]:   00509a00(W), 005099ba(*)
//              undefined         Stack[-0x76]:1 local_76                  XREF[1]:     005099c5(*)
//              undefined         Stack[-0x78]:1 local_78                  XREF[1]:     005099c0(*)
//              short             Stack[-0x7a]:2 work_target
//              short             Stack[-0x7c]:2 progress
//                               ?do_command_make@TRIBE_Command@@AAEXPAUTRIBE_Command_Make@@@Z XREF[1]:     do_command:005097a8(c)
//                               TRIBE_Command::do_command_make
//                              tcommand.cpp:143 (26)
//         00509980     MOV        EAX,FS:[0x0]
//         00509986     PUSH       -0x1
//         00509988     PUSH       FUN_00560dcb
//         0050998d     PUSH       EAX
//         0050998e     MOV        dword ptr FS:[0x0],ESP
//         00509995     SUB        ESP,0x6c
//         00509998     PUSH       EBX
//         00509999     PUSH       ESI
//                              tcommand.cpp:151 (24)
//         0050999a     MOV        ESI,dword ptr [ESP + param_1]
//         005099a1     MOV        EBX,this
//         005099a3     PUSH       EDI
//         005099a4     MOV        EAX,dword ptr [ESI + 0x4]
//         005099a7     MOV        this,dword ptr [EBX + 0x4]
//         005099aa     PUSH       EAX
//         005099ab     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         005099b0     MOV        EDI,EAX
//                              tcommand.cpp:153 (8)
//         005099b2     TEST       EDI,EDI
//         005099b4     JZ         LAB_00509ab1
//                              tcommand.cpp:157 (32)
//         005099ba     LEA        this=>work_name[4],[ESP + 0x14]
//         005099be     PUSH       0x64
//         005099c0     LEA        EDX=>local_78,[ESP + 0x10]
//         005099c4     PUSH       this
//         005099c5     LEA        EAX=>local_76,[ESP + 0x16]
//         005099c9     PUSH       EDX
//         005099ca     LEA        this=>param_1,[ESP + 0x94]
//         005099d1     PUSH       EAX
//         005099d2     PUSH       this
//         005099d3     MOV        this,EDI
//         005099d5     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
//                              tcommand.cpp:159 (28)
//         005099da     MOV        AX,word ptr [ESP + param_1]
//         005099e2     CMP        AX,0x67
//         005099e6     JZ         LAB_00509a9d
//         005099ec     CMP        AX,0x66
//         005099f0     JZ         LAB_00509a9d
//                              tcommand.cpp:170 (52)
//         005099f6     PUSH       0x50
//         005099f8     CALL       operator_new                                     void * operator_new(uint param_1)
//         005099fd     ADD        ESP,0x4
//         00509a00     MOV        dword ptr [ESP + work_name[0]],EAX
//         00509a04     TEST       EAX,EAX
//         00509a06     MOV        dword ptr [ESP + local_4],0x0
//         00509a11     JZ         LAB_00509a28
//         00509a13     MOV        EDX,dword ptr [ESI + 0xc]
//         00509a16     MOV        this,word ptr [ESI + 0xa]
//         00509a1a     PUSH       0x0
//         00509a1c     PUSH       EDX
//         00509a1d     PUSH       this
//         00509a1e     PUSH       EDI
//         00509a1f     MOV        this,EAX
//         00509a21     CALL       TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj     undefined TRIBE_Action_Make_Obj(TRIBE_Action_
//         00509a26     JMP        LAB_00509a2a
//                               LAB_00509a28                                                 XREF[1]:     00509a11(j)
//         00509a28     XOR        EAX,EAX
//                               LAB_00509a2a                                                 XREF[1]:     00509a26(j)
//                              tcommand.cpp:171 (15)
//         00509a2a     TEST       EAX,EAX
//         00509a2c     MOV        dword ptr [ESP + local_4],0xffffffff
//         00509a37     JZ         LAB_00509a44
//                              tcommand.cpp:172 (11)
//         00509a39     MOV        EDX,dword ptr [EDI]
//         00509a3b     PUSH       EAX
//         00509a3c     MOV        this,EDI
//         00509a3e     CALL       dword ptr [EDX + 0x208]
//                               LAB_00509a44                                                 XREF[1]:     00509a37(j)
//                              tcommand.cpp:174 (15)
//         00509a44     MOV        this,EDI
//         00509a46     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509a4b     TEST       EAX,EAX
//         00509a4d     JZ         LAB_00509ada
//                              tcommand.cpp:176 (19)
//         00509a53     PUSH       0x26c
//         00509a58     MOV        this,EDI
//         00509a5a     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509a5f     MOV        this,EAX
//         00509a61     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
//                              tcommand.cpp:177 (35)
//         00509a66     MOV        EAX,dword ptr [ESI + 0xc]
//         00509a69     PUSH       0xbf800000
//         00509a6e     PUSH       offset DAT_fffffff8
//         00509a73     PUSH       offset DAT_fffffff4
//         00509a78     PUSH       offset DAT_fffffff0
//         00509a7a     PUSH       EAX
//         00509a7b     MOV        this,EDI
//         00509a7d     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509a82     MOV        this,EAX
//         00509a84     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
//                              tcommand.cpp:205 (20)
//         00509a89     MOV        this,dword ptr [ESP + 0x78]
//         00509a8d     MOV        dword ptr FS:[0x0],this
//         00509a94     POP        EDI
//         00509a95     POP        ESI
//         00509a96     POP        EBX
//         00509a97     ADD        ESP,0x78
//         00509a9a     RET        0x4
//                               LAB_00509a9d                                                 XREF[2]:     005099e6(j), 005099f0(j)
//                              tcommand.cpp:183 (14)
//         00509a9d     MOV        EDX,dword ptr [EBX + 0x4]
//         00509aa0     XOR        this,this
//         00509aa2     MOV        this,byte ptr [ESI + 0x8]
//         00509aa5     MOV        EAX,dword ptr [EDX + 0x40]
//         00509aa8     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//                              tcommand.cpp:184 (4)
//         00509aab     TEST       this,this
//         00509aad     JZ         LAB_00509ada
//                              tcommand.cpp:193 (2)
//         00509aaf     JMP        LAB_00509ac3
//                               LAB_00509ab1                                                 XREF[1]:     005099b4(j)
//                              tcommand.cpp:196 (14)
//         00509ab1     MOV        EDX,dword ptr [EBX + 0x4]
//         00509ab4     XOR        this,this
//         00509ab6     MOV        this,byte ptr [ESI + 0x8]
//         00509ab9     MOV        EAX,dword ptr [EDX + 0x40]
//         00509abc     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//                              tcommand.cpp:197 (4)
//         00509abf     TEST       this,this
//         00509ac1     JZ         LAB_00509ada
//                               LAB_00509ac3                                                 XREF[1]:     00509aaf(j)
//                              tcommand.cpp:202 (23)
//         00509ac3     MOV        EAX,dword ptr [ESI + 0xc]
//         00509ac6     MOV        EDX,dword ptr [this->field0_0x0]
//         00509ac8     PUSH       EAX
//         00509ac9     MOV        EAX,dword ptr [ESI + 0x4]
//         00509acc     PUSH       EAX
//         00509acd     MOVSX      EAX,word ptr [ESI + 0xa]
//         00509ad1     PUSH       EAX
//         00509ad2     PUSH       0x0
//         00509ad4     CALL       dword ptr [EDX + 0x10c]
//                               LAB_00509ada                                                 XREF[3]:     00509a4d(j), 00509aad(j),
//                                                                                                         00509ac1(j)
//                              tcommand.cpp:205 (20)
//         00509ada     MOV        this,dword ptr [ESP + local_c]
//         00509ade     POP        EDI
//         00509adf     POP        ESI
//         00509ae0     MOV        dword ptr FS:[0x0],this
//         00509ae7     POP        EBX
//         00509ae8     ADD        ESP,0x78
//         00509aeb     RET        0x4
//         00509aee     ??         90h
//         00509aef     NOP
    return;
}

void TRIBE_Command::do_command_research(TRIBE_Command_Research* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_research(TRIBE_Command * this, TRIBE_Comm
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[3]:     00509b0a(R), 00509b3a(*), 00509b4a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00509b76(W), 00509b9a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00509c48(R)
//              char[100]         Stack[-0x74]   work_name                 XREF[1,1]:   00509b70(W), 00509b2a(*)
//              undefined         Stack[-0x76]:1 local_76                  XREF[1]:     00509b35(*)
//              undefined         Stack[-0x78]:1 local_78                  XREF[1]:     00509b30(*)
//              short             Stack[-0x7a]:2 work_target
//              short             Stack[-0x7c]:2 progress
//                               ?do_command_research@TRIBE_Command@@AAEXPAUTRIBE_Command_Re  XREF[1]:     do_command:005097b4(c)
//                               TRIBE_Command::do_command_research
//                              tcommand.cpp:209 (26)
//         00509af0     MOV        EAX,FS:[0x0]
//         00509af6     PUSH       -0x1
//         00509af8     PUSH       FUN_00560deb
//         00509afd     PUSH       EAX
//         00509afe     MOV        dword ptr FS:[0x0],ESP
//         00509b05     SUB        ESP,0x6c
//         00509b08     PUSH       EBX
//         00509b09     PUSH       ESI
//                              tcommand.cpp:217 (24)
//         00509b0a     MOV        ESI,dword ptr [ESP + param_1]
//         00509b11     MOV        EBX,this
//         00509b13     PUSH       EDI
//         00509b14     MOV        EAX,dword ptr [ESI + 0x4]
//         00509b17     MOV        this,dword ptr [EBX + 0x4]
//         00509b1a     PUSH       EAX
//         00509b1b     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00509b20     MOV        EDI,EAX
//                              tcommand.cpp:218 (8)
//         00509b22     TEST       EDI,EDI
//         00509b24     JZ         LAB_00509c1f
//                              tcommand.cpp:222 (32)
//         00509b2a     LEA        this=>work_name[4],[ESP + 0x14]
//         00509b2e     PUSH       0x64
//         00509b30     LEA        EDX=>local_78,[ESP + 0x10]
//         00509b34     PUSH       this
//         00509b35     LEA        EAX=>local_76,[ESP + 0x16]
//         00509b39     PUSH       EDX
//         00509b3a     LEA        this=>param_1,[ESP + 0x94]
//         00509b41     PUSH       EAX
//         00509b42     PUSH       this
//         00509b43     MOV        this,EDI
//         00509b45     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
//                              tcommand.cpp:224 (28)
//         00509b4a     MOV        AX,word ptr [ESP + param_1]
//         00509b52     CMP        AX,0x67
//         00509b56     JZ         LAB_00509c0b
//         00509b5c     CMP        AX,0x66
//         00509b60     JZ         LAB_00509c0b
//                              tcommand.cpp:226 (50)
//         00509b66     PUSH       0x48
//         00509b68     CALL       operator_new                                     void * operator_new(uint param_1)
//         00509b6d     ADD        ESP,0x4
//         00509b70     MOV        dword ptr [ESP + work_name[0]],EAX
//         00509b74     TEST       EAX,EAX
//         00509b76     MOV        dword ptr [ESP + local_4],0x0
//         00509b81     JZ         LAB_00509b96
//         00509b83     MOV        EDX,dword ptr [ESI + 0xc]
//         00509b86     MOV        this,word ptr [ESI + 0xa]
//         00509b8a     PUSH       EDX
//         00509b8b     PUSH       this
//         00509b8c     PUSH       EDI
//         00509b8d     MOV        this,EAX
//         00509b8f     CALL       TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech   undefined TRIBE_Action_Make_Tech(TRIBE_Action
//         00509b94     JMP        LAB_00509b98
//                               LAB_00509b96                                                 XREF[1]:     00509b81(j)
//         00509b96     XOR        EAX,EAX
//                               LAB_00509b98                                                 XREF[1]:     00509b94(j)
//                              tcommand.cpp:227 (15)
//         00509b98     TEST       EAX,EAX
//         00509b9a     MOV        dword ptr [ESP + local_4],0xffffffff
//         00509ba5     JZ         LAB_00509bb2
//                              tcommand.cpp:228 (11)
//         00509ba7     MOV        EDX,dword ptr [EDI]
//         00509ba9     PUSH       EAX
//         00509baa     MOV        this,EDI
//         00509bac     CALL       dword ptr [EDX + 0x208]
//                               LAB_00509bb2                                                 XREF[1]:     00509ba5(j)
//                              tcommand.cpp:230 (15)
//         00509bb2     MOV        this,EDI
//         00509bb4     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509bb9     TEST       EAX,EAX
//         00509bbb     JZ         LAB_00509c48
//                              tcommand.cpp:232 (19)
//         00509bc1     PUSH       0x26c
//         00509bc6     MOV        this,EDI
//         00509bc8     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509bcd     MOV        this,EAX
//         00509bcf     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
//                              tcommand.cpp:233 (35)
//         00509bd4     MOV        EAX,dword ptr [ESI + 0xc]
//         00509bd7     PUSH       0xbf800000
//         00509bdc     PUSH       offset DAT_fffffff8
//         00509be1     PUSH       offset DAT_fffffff4
//         00509be6     PUSH       offset DAT_fffffff0
//         00509be8     PUSH       EAX
//         00509be9     MOV        this,EDI
//         00509beb     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00509bf0     MOV        this,EAX
//         00509bf2     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
//                              tcommand.cpp:251 (20)
//         00509bf7     MOV        this,dword ptr [ESP + 0x78]
//         00509bfb     MOV        dword ptr FS:[0x0],this
//         00509c02     POP        EDI
//         00509c03     POP        ESI
//         00509c04     POP        EBX
//         00509c05     ADD        ESP,0x78
//         00509c08     RET        0x4
//                               LAB_00509c0b                                                 XREF[2]:     00509b56(j), 00509b60(j)
//                              tcommand.cpp:239 (14)
//         00509c0b     MOV        EDX,dword ptr [EBX + 0x4]
//         00509c0e     XOR        this,this
//         00509c10     MOV        this,byte ptr [ESI + 0x8]
//         00509c13     MOV        EAX,dword ptr [EDX + 0x40]
//         00509c16     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//                              tcommand.cpp:240 (4)
//         00509c19     TEST       this,this
//         00509c1b     JZ         LAB_00509c48
//                              tcommand.cpp:244 (2)
//         00509c1d     JMP        LAB_00509c31
//                               LAB_00509c1f                                                 XREF[1]:     00509b24(j)
//                              tcommand.cpp:247 (14)
//         00509c1f     MOV        EDX,dword ptr [EBX + 0x4]
//         00509c22     XOR        this,this
//         00509c24     MOV        this,byte ptr [ESI + 0x8]
//         00509c27     MOV        EAX,dword ptr [EDX + 0x40]
//         00509c2a     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//                              tcommand.cpp:248 (4)
//         00509c2d     TEST       this,this
//         00509c2f     JZ         LAB_00509c48
//                               LAB_00509c31                                                 XREF[1]:     00509c1d(j)
//                              tcommand.cpp:249 (23)
//         00509c31     MOV        EAX,dword ptr [ESI + 0xc]
//         00509c34     MOV        EDX,dword ptr [this->field0_0x0]
//         00509c36     PUSH       EAX
//         00509c37     MOV        EAX,dword ptr [ESI + 0x4]
//         00509c3a     PUSH       -0x1
//         00509c3c     PUSH       EAX
//         00509c3d     MOVSX      EAX,word ptr [ESI + 0xa]
//         00509c41     PUSH       EAX
//         00509c42     CALL       dword ptr [EDX + 0x118]
//                               LAB_00509c48                                                 XREF[3]:     00509bbb(j), 00509c1b(j),
//                                                                                                         00509c2f(j)
//                              tcommand.cpp:251 (20)
//         00509c48     MOV        this,dword ptr [ESP + local_c]
//         00509c4c     POP        EDI
//         00509c4d     POP        ESI
//         00509c4e     MOV        dword ptr FS:[0x0],this
//         00509c55     POP        EBX
//         00509c56     ADD        ESP,0x78
//         00509c59     RET        0x4
//         00509c5c     ??         90h
//         00509c5d     NOP
//         00509c5e     NOP
//         00509c5f     NOP
    return;
}

void TRIBE_Command::do_command_build(TRIBE_Command_Build* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_build(TRIBE_Command * this, TRIBE_Command
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[2]:     00509c66(R), 00509c78(W)
//              uchar             Stack[-0x8]:1  placementResult           XREF[1]:     00509cbf(*)
//              int               Stack[-0xc]:4  blockingObject            XREF[1]:     00509c6c(W)
//                               ?do_command_build@TRIBE_Command@@AAEXPAUTRIBE_Command_Build  XREF[1]:     do_command:005097c0(c)
//                               TRIBE_Command::do_command_build
//                              tcommand.cpp:256 (6)
//         00509c60     SUB        ESP,0xc
//         00509c63     PUSH       EBX
//         00509c64     PUSH       EBP
//         00509c65     PUSH       ESI
//                              tcommand.cpp:257 (13)
//         00509c66     MOV        ESI,dword ptr [ESP + param_1]
//         00509c6a     XOR        EAX,EAX
//         00509c6c     MOV        dword ptr [ESP + blockingObject],this
//         00509c70     MOV        AL,byte ptr [ESI + 0x1]
//                              tcommand.cpp:262 (19)
//         00509c73     MOV        this,dword ptr [ECX + this->field4_0x4]
//         00509c76     XOR        EDX,EDX
//         00509c78     MOV        dword ptr [ESP + param_1],EAX
//         00509c7c     MOV        DL,byte ptr [ESI + 0x2]
//         00509c7f     MOV        EAX,dword ptr [this->field0_0x0 + 0x40]
//         00509c82     PUSH       EDI
//         00509c83     MOV        EDI,dword ptr [EAX + EDX*0x4]
//                              tcommand.cpp:263 (8)
//         00509c86     TEST       EDI,EDI
//         00509c88     JZ         LAB_00509df8
//                              tcommand.cpp:269 (14)
//         00509c8e     MOV        AX,word ptr [ESI + 0xc]
//         00509c92     CMP        AX,0xffff
//         00509c96     JZ         LAB_00509df8
//                              tcommand.cpp:276 (9)
//         00509c9c     MOV        EDX,dword ptr [EDI + 0x24]
//         00509c9f     MOVSX      this,AX
//         00509ca2     MOV        EBX,dword ptr [EDX + this->field0_0x0*0x4]
//                              tcommand.cpp:277 (8)
//         00509ca5     TEST       EBX,EBX
//         00509ca7     JZ         LAB_00509df8
//                              tcommand.cpp:285 (33)
//         00509cad     MOV        this,dword ptr [ESI + 0x8]
//         00509cb0     MOV        EDX,dword ptr [ESI + 0x4]
//         00509cb3     MOV        EBP,dword ptr [EBX]
//         00509cb5     PUSH       0x1
//         00509cb7     PUSH       0x1
//         00509cb9     PUSH       0x1
//         00509cbb     PUSH       0x1
//         00509cbd     PUSH       0x1
//         00509cbf     LEA        EAX=>placementResult,[ESP + 0x28]
//         00509cc3     PUSH       0x1
//         00509cc5     PUSH       EAX
//         00509cc6     PUSH       this
//         00509cc7     PUSH       EDX
//         00509cc8     PUSH       EDI
//         00509cc9     MOV        this,EBX
//         00509ccb     CALL       dword ptr [EBP + 0x20]
//                              tcommand.cpp:287 (8)
//         00509cce     TEST       AL,AL
//         00509cd0     MOV        byte ptr [ESP + 0x18],AL
//         00509cd4     JZ         LAB_00509d2f
//                              tcommand.cpp:288 (12)
//         00509cd6     MOV        EAX,dword ptr [ESP + 0x20]
//         00509cda     TEST       EAX,EAX
//         00509cdc     JLE        LAB_00509df8
//                              tcommand.cpp:289 (13)
//         00509ce2     MOV        EAX,dword ptr [ESI + 0x14]
//         00509ce5     MOV        this,dword ptr [ESP + 0x10]
//         00509ce9     PUSH       EAX
//         00509cea     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:290 (8)
//         00509cef     TEST       EAX,EAX
//         00509cf1     JZ         LAB_00509df8
//                              tcommand.cpp:293 (46)
//         00509cf7     MOV        EAX,dword ptr [EAX + 0x4]
//         00509cfa     MOV        this,dword ptr [ESI + 0x10]
//         00509cfd     PUSH       EAX
//         00509cfe     MOV        EAX,dword ptr [ESI + 0x8]
//         00509d01     PUSH       this=>DAT_fffffff8
//         00509d02     MOV        this,dword ptr [ESI + 0x4]
//         00509d05     PUSH       EAX=>DAT_fffffff4
//         00509d06     MOV        EDX,dword ptr [EDI]
//         00509d08     MOVSX      EAX,word ptr [ESI + 0xc]
//         00509d0c     PUSH       this=>DAT_fffffff0
//         00509d0d     MOV        this,dword ptr [ESP + 0x24]
//         00509d11     PUSH       EAX
//         00509d12     MOV        EAX,dword ptr [ESP + 0x2c]
//         00509d16     AND        EAX,0xff
//         00509d1b     PUSH       this
//         00509d1c     PUSH       EAX
//         00509d1d     MOV        this,EDI
//         00509d1f     CALL       dword ptr [EDX + 0x100]
//                              tcommand.cpp:331 (10)
//         00509d25     POP        EDI
//         00509d26     POP        ESI
//         00509d27     POP        EBP
//         00509d28     POP        EBX
//         00509d29     ADD        ESP,0xc
//         00509d2c     RET        0x4
//                               LAB_00509d2f                                                 XREF[1]:     00509cd4(j)
//                              tcommand.cpp:302 (23)
//         00509d2f     MOV        this,word ptr [ESI + 0xc]
//         00509d33     PUSH       0x0
//         00509d35     PUSH       offset DAT_fffffff8
//         00509d3a     PUSH       this=>DAT_fffffff4
//         00509d3b     MOV        this,EDI
//         00509d3d     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
//         00509d42     TEST       AL,AL
//         00509d44     JNZ        LAB_00509d97
//                              tcommand.cpp:303 (12)
//         00509d46     MOV        EAX,dword ptr [ESP + 0x20]
//         00509d4a     TEST       EAX,EAX
//         00509d4c     JLE        LAB_00509df8
//                              tcommand.cpp:304 (13)
//         00509d52     MOV        EDX,dword ptr [ESI + 0x14]
//         00509d55     MOV        this,dword ptr [ESP + 0x10]
//         00509d59     PUSH       EDX
//         00509d5a     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:305 (8)
//         00509d5f     TEST       EAX,EAX
//         00509d61     JZ         LAB_00509df8
//                              tcommand.cpp:308 (38)
//         00509d67     MOV        EAX,dword ptr [EAX + 0x4]
//         00509d6a     MOV        this,dword ptr [ESI + 0x10]
//         00509d6d     PUSH       EAX
//         00509d6e     MOV        EAX,dword ptr [ESI + 0x8]
//         00509d71     MOV        EDX,dword ptr [EDI]
//         00509d73     PUSH       this=>DAT_fffffff8
//         00509d74     MOV        this,dword ptr [ESI + 0x4]
//         00509d77     PUSH       EAX=>DAT_fffffff4
//         00509d78     MOVSX      EAX,word ptr [ESI + 0xc]
//         00509d7c     PUSH       this=>DAT_fffffff0
//         00509d7d     MOV        this,dword ptr [ESP + 0x24]
//         00509d81     PUSH       EAX
//         00509d82     PUSH       this
//         00509d83     PUSH       0x0
//         00509d85     MOV        this,EDI
//         00509d87     CALL       dword ptr [EDX + 0x100]
//                              tcommand.cpp:331 (10)
//         00509d8d     POP        EDI
//         00509d8e     POP        ESI
//         00509d8f     POP        EBP
//         00509d90     POP        EBX
//         00509d91     ADD        ESP,0xc
//         00509d94     RET        0x4
//                               LAB_00509d97                                                 XREF[1]:     00509d44(j)
//                              tcommand.cpp:317 (22)
//         00509d97     MOV        EDX,dword ptr [ESI + 0x10]
//         00509d9a     MOV        EAX,dword ptr [ESI + 0x8]
//         00509d9d     MOV        this,dword ptr [ESI + 0x4]
//         00509da0     PUSH       EDX
//         00509da1     PUSH       0x0=>DAT_fffffff8
//         00509da3     PUSH       EAX=>DAT_fffffff4
//         00509da4     PUSH       this=>DAT_fffffff0
//         00509da5     PUSH       EDI
//         00509da6     MOV        this,EBX
//         00509da8     CALL       dword ptr [EBP + 0x3c]
//         00509dab     MOV        EBP,EAX
//                              tcommand.cpp:321 (15)
//         00509dad     MOV        EAX,dword ptr [ESP + 0x20]
//         00509db1     TEST       EAX,EAX
//         00509db3     JLE        LAB_00509df8
//         00509db5     LEA        EBX,[ESI + 0x14]
//         00509db8     MOV        dword ptr [ESP + 0x20],EAX
//                               LAB_00509dbc                                                 XREF[1]:     00509df6(j)
//                              tcommand.cpp:322 (14)
//         00509dbc     MOV        EDX,dword ptr [EBX]
//         00509dbe     MOV        this,dword ptr [ESP + 0x10]
//         00509dc2     PUSH       EDX
//         00509dc3     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//         00509dc8     MOV        EDI,EAX
//                              tcommand.cpp:324 (4)
//         00509dca     TEST       EDI,EDI
//         00509dcc     JZ         LAB_00509dea
//                              tcommand.cpp:326 (7)
//         00509dce     MOV        this,EDI
//         00509dd0     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//                              tcommand.cpp:328 (35)
//         00509dd5     MOV        this,dword ptr [ESI + 0x8]
//         00509dd8     MOV        EDX,dword ptr [ESI + 0x4]
//         00509ddb     MOV        EAX,dword ptr [EDI]
//         00509ddd     PUSH       0x0
//         00509ddf     PUSH       this=>DAT_fffffff8
//         00509de0     PUSH       EDX=>DAT_fffffff4
//         00509de1     PUSH       EBP=>DAT_fffffff0
//         00509de2     MOV        this,EDI
//         00509de4     CALL       dword ptr [EAX + 0x98]
//                               LAB_00509dea                                                 XREF[1]:     00509dcc(j)
//         00509dea     MOV        EAX,dword ptr [ESP + 0x20]
//         00509dee     ADD        EBX,0x4
//         00509df1     DEC        EAX
//         00509df2     MOV        dword ptr [ESP + 0x20],EAX
//         00509df6     JNZ        LAB_00509dbc
//                               LAB_00509df8                                                 XREF[8]:     00509c88(j), 00509c96(j),
//                                                                                                         00509ca7(j), 00509cdc(j),
//                                                                                                         00509cf1(j), 00509d4c(j),
//                                                                                                         00509d61(j), 00509db3(j)
//                              tcommand.cpp:331 (10)
//         00509df8     POP        EDI
//         00509df9     POP        ESI
//         00509dfa     POP        EBP
//         00509dfb     POP        EBX
//         00509dfc     ADD        ESP,0xc
//         00509dff     RET        0x4
//         00509e02     ??         90h
//         00509e03     NOP
//         00509e04     NOP
//         00509e05     NOP
//         00509e06     NOP
//         00509e07     NOP
//         00509e08     NOP
//         00509e09     NOP
//         00509e0a     NOP
//         00509e0b     NOP
//         00509e0c     NOP
//         00509e0d     NOP
//         00509e0e     NOP
//         00509e0f     NOP
    return;
}

void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_build_wall(TRIBE_Command * this, TRIBE_Co
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[9]:     00509e16(R), 00509e75(W), 00509ea2(*), 00509efb(*),
//                                                                                     00509f28(*), 00509f6f(*), 00509f93(*), 00509fae(R),
//                                                                                     00509fdb(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00509e2d(W), 00509fbe(R)
//              RGE_Obj_Info *    Stack[-0x8]:4  units                     XREF[2]:     00509e27(W), 00509fb6(R)
//              int               Stack[-0xc]:4  unitNum                   XREF[2]:     00509e84(W), 00509e9c(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     00509e8a(W), 00509eb2(R), 00509ec9(R), 00509f42(R)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[7]:     00509e91(W), 00509ead(R), 00509f38(R), 00509f6b(W),
//                                                                                     00509f75(R), 00509f8f(W), 00509f99(R)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[7]:     00509e6c(W), 00509ea9(R), 00509ec4(R), 00509ef7(W),
//                                                                                     00509f00(R), 00509f24(W), 00509f2d(R)
//                               ?do_command_build_wall@TRIBE_Command@@AAEXPAUTRIBE_Command_  XREF[1]:     do_command:005097cc(c)
//                               TRIBE_Command::do_command_build_wall
//                              tcommand.cpp:337 (6)
//         00509e10     SUB        ESP,0x18
//         00509e13     PUSH       EBX
//         00509e14     PUSH       EBP
//         00509e15     PUSH       ESI
//                              tcommand.cpp:338 (11)
//         00509e16     MOV        ESI,dword ptr [ESP + param_1]
//         00509e1a     XOR        EAX,EAX
//         00509e1c     MOV        EBP,this
//         00509e1e     MOV        AL,byte ptr [ESI + 0x1]
//                              tcommand.cpp:339 (3)
//         00509e21     LEA        this,[ESI + 0x10]
//                              tcommand.cpp:342 (23)
//         00509e24     MOV        EDX,dword ptr [EBP + 0x4]
//         00509e27     MOV        dword ptr [ESP + units],EAX
//         00509e2b     XOR        EAX,EAX
//         00509e2d     MOV        dword ptr [ESP + local_4],this
//         00509e31     MOV        AL,byte ptr [ESI + 0x2]
//         00509e34     MOV        this,dword ptr [EDX + 0x40]
//         00509e37     PUSH       EDI
//         00509e38     MOV        EDI,dword ptr [this->field0_0x0 + EAX*0x4]
//                              tcommand.cpp:343 (8)
//         00509e3b     TEST       EDI,EDI
//         00509e3d     JZ         LAB_00509ffa
//                              tcommand.cpp:347 (14)
//         00509e43     MOV        AX,word ptr [ESI + 0x8]
//         00509e47     CMP        AX,0xffff
//         00509e4b     JZ         LAB_00509ffa
//                              tcommand.cpp:351 (9)
//         00509e51     MOVSX      EDX,AX
//         00509e54     MOV        EAX,dword ptr [EDI + 0x24]
//         00509e57     MOV        EBX,dword ptr [EAX + EDX*0x4]
//                              tcommand.cpp:352 (8)
//         00509e5a     TEST       EBX,EBX
//         00509e5c     JZ         LAB_00509ffa
//                              tcommand.cpp:358 (64)
//         00509e62     XOR        EAX,EAX
//         00509e64     XOR        this,this
//         00509e66     MOV        AL,byte ptr [ESI + 0x6]
//         00509e69     MOV        this,byte ptr [ESI + 0x4]
//         00509e6c     MOV        dword ptr [ESP + local_18],EAX
//         00509e70     SUB        EAX,this
//         00509e72     CDQ
//         00509e73     XOR        EAX,EDX
//         00509e75     MOV        dword ptr [ESP + param_1],0x0
//         00509e7d     SUB        EAX,EDX
//         00509e7f     XOR        EDX,EDX
//         00509e81     MOV        DL,byte ptr [ESI + 0x3]
//         00509e84     MOV        dword ptr [ESP + unitNum],EAX
//         00509e88     XOR        EAX,EAX
//         00509e8a     MOV        dword ptr [ESP + local_10],EDX
//         00509e8e     MOV        AL,byte ptr [ESI + 0x5]
//         00509e91     MOV        dword ptr [ESP + local_14],EAX
//         00509e95     SUB        EAX,EDX
//         00509e97     CDQ
//         00509e98     XOR        EAX,EDX
//         00509e9a     SUB        EAX,EDX
//         00509e9c     MOV        EDX,dword ptr [ESP + unitNum]
//         00509ea0     CMP        EDX,EAX
//                              tcommand.cpp:361 (27)
//         00509ea2     LEA        EDX=>param_1,[ESP + 0x2c]
//         00509ea6     PUSH       EDX
//         00509ea7     JNZ        LAB_00509ec2
//         00509ea9     MOV        EAX,dword ptr [ESP + local_18]
//         00509ead     MOV        EDX,dword ptr [ESP + local_14]
//         00509eb1     PUSH       EAX
//         00509eb2     MOV        EAX,dword ptr [ESP + local_10]
//         00509eb6     PUSH       EDX
//         00509eb7     PUSH       this
//         00509eb8     MOV        this,dword ptr [ESI + 0xc]
//         00509ebb     PUSH       EAX
//         00509ebc     PUSH       this
//                              tcommand.cpp:363 (7)
//         00509ebd     JMP        LAB_00509fa5
//                               LAB_00509ec2                                                 XREF[1]:     00509ea7(j)
//         00509ec2     JL         LAB_00509f38
//                              tcommand.cpp:366 (25)
//         00509ec4     MOV        EAX,dword ptr [ESP + local_18]
//         00509ec8     PUSH       EAX
//         00509ec9     MOV        EAX,dword ptr [ESP + local_10]
//         00509ecd     PUSH       EAX
//         00509ece     PUSH       this
//         00509ecf     MOV        this,dword ptr [ESI + 0xc]
//         00509ed2     PUSH       EAX
//         00509ed3     PUSH       this
//         00509ed4     PUSH       EBX
//         00509ed5     PUSH       EDI
//         00509ed6     MOV        this,EBP
//         00509ed8     CALL       TRIBE_Command::place_line_of_walls               void place_line_of_walls(TRIBE_Command * this
//                              tcommand.cpp:367 (10)
//         00509edd     MOV        this,byte ptr [ESI + 0x5]
//         00509ee0     MOV        AL,byte ptr [ESI + 0x3]
//         00509ee3     CMP        AL,this
//         00509ee5     JNC        LAB_00509f0e
//                              tcommand.cpp:368 (34)
//         00509ee7     XOR        EDX,EDX
//         00509ee9     AND        this,0xff
//         00509eef     MOV        DL,byte ptr [ESI + 0x6]
//         00509ef2     AND        EAX,0xff
//         00509ef7     MOV        dword ptr [ESP + local_18],EDX
//         00509efb     LEA        EDX=>param_1,[ESP + 0x2c]
//         00509eff     PUSH       EDX
//         00509f00     MOV        EDX,dword ptr [ESP + local_18]
//         00509f04     PUSH       EDX
//         00509f05     PUSH       this
//         00509f06     INC        EAX
//         00509f07     PUSH       EDX
//         00509f08     PUSH       EAX
//                              tcommand.cpp:369 (11)
//         00509f09     JMP        LAB_00509fa1
//                               LAB_00509f0e                                                 XREF[1]:     00509ee5(j)
//         00509f0e     JBE        LAB_00509fae
//                              tcommand.cpp:370 (34)
//         00509f14     XOR        EDX,EDX
//         00509f16     AND        this,0xff
//         00509f1c     MOV        DL,byte ptr [ESI + 0x6]
//         00509f1f     AND        EAX,0xff
//         00509f24     MOV        dword ptr [ESP + local_18],EDX
//         00509f28     LEA        EDX=>param_1,[ESP + 0x2c]
//         00509f2c     PUSH       EDX
//         00509f2d     MOV        EDX,dword ptr [ESP + local_18]
//         00509f31     PUSH       EDX
//         00509f32     PUSH       this
//         00509f33     DEC        EAX
//         00509f34     PUSH       EDX
//         00509f35     PUSH       EAX
//                              tcommand.cpp:372 (2)
//         00509f36     JMP        LAB_00509fa1
//                               LAB_00509f38                                                 XREF[1]:     00509ec2(j)
//                              tcommand.cpp:375 (25)
//         00509f38     MOV        EAX,dword ptr [ESP + local_14]
//         00509f3c     MOV        EDX,dword ptr [ESI + 0xc]
//         00509f3f     PUSH       this
//         00509f40     PUSH       EAX
//         00509f41     PUSH       this
//         00509f42     MOV        this,dword ptr [ESP + local_10]
//         00509f46     PUSH       this
//         00509f47     PUSH       EDX
//         00509f48     PUSH       EBX
//         00509f49     PUSH       EDI
//         00509f4a     MOV        this,EBP
//         00509f4c     CALL       TRIBE_Command::place_line_of_walls               void place_line_of_walls(TRIBE_Command * this
//                              tcommand.cpp:376 (10)
//         00509f51     MOV        this,byte ptr [ESI + 0x6]
//         00509f54     MOV        AL,byte ptr [ESI + 0x4]
//         00509f57     CMP        AL,this
//         00509f59     JNC        LAB_00509f7d
//                              tcommand.cpp:377 (32)
//         00509f5b     XOR        EDX,EDX
//         00509f5d     AND        this,0xff
//         00509f63     MOV        DL,byte ptr [ESI + 0x5]
//         00509f66     AND        EAX,0xff
//         00509f6b     MOV        dword ptr [ESP + local_14],EDX
//         00509f6f     LEA        EDX=>param_1,[ESP + 0x2c]
//         00509f73     PUSH       EDX
//         00509f74     PUSH       this
//         00509f75     MOV        this,dword ptr [ESP + local_14]
//         00509f79     INC        EAX
//         00509f7a     PUSH       this
//                              tcommand.cpp:378 (4)
//         00509f7b     JMP        LAB_00509f9f
//                               LAB_00509f7d                                                 XREF[1]:     00509f59(j)
//         00509f7d     JBE        LAB_00509fae
//                              tcommand.cpp:379 (47)
//         00509f7f     XOR        EDX,EDX
//         00509f81     AND        this,0xff
//         00509f87     MOV        DL,byte ptr [ESI + 0x5]
//         00509f8a     AND        EAX,0xff
//         00509f8f     MOV        dword ptr [ESP + local_14],EDX
//         00509f93     LEA        EDX=>param_1,[ESP + 0x2c]
//         00509f97     PUSH       EDX
//         00509f98     PUSH       this
//         00509f99     MOV        this,dword ptr [ESP + local_14]
//         00509f9d     DEC        EAX
//         00509f9e     PUSH       this
//                               LAB_00509f9f                                                 XREF[1]:     00509f7b(j)
//         00509f9f     PUSH       EAX
//         00509fa0     PUSH       this
//                               LAB_00509fa1                                                 XREF[2]:     00509f09(j), 00509f36(j)
//         00509fa1     MOV        EAX,dword ptr [ESI + 0xc]
//         00509fa4     PUSH       EAX
//                               LAB_00509fa5                                                 XREF[1]:     00509ebd(j)
//         00509fa5     PUSH       EBX
//         00509fa6     PUSH       EDI
//         00509fa7     MOV        this,EBP
//         00509fa9     CALL       TRIBE_Command::place_line_of_walls               void place_line_of_walls(TRIBE_Command * this
//                               LAB_00509fae                                                 XREF[2]:     00509f0e(j), 00509f7d(j)
//                              tcommand.cpp:438 (8)
//         00509fae     MOV        EAX,dword ptr [ESP + param_1]
//         00509fb2     TEST       EAX,EAX
//         00509fb4     JZ         LAB_00509ffa
//                              tcommand.cpp:440 (8)
//         00509fb6     MOV        EAX,dword ptr [ESP + units]
//         00509fba     TEST       EAX,EAX
//         00509fbc     JLE        LAB_00509ffa
//                              tcommand.cpp:450 (70)
//         00509fbe     MOV        EDI,dword ptr [ESP + local_4]
//         00509fc2     MOV        EBX,EAX
//                               LAB_00509fc4                                                 XREF[1]:     00509ff8(j)
//         00509fc4     MOV        this,dword ptr [EDI]
//         00509fc6     PUSH       this
//         00509fc7     MOV        this,EBP
//         00509fc9     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//         00509fce     MOV        ESI,EAX
//         00509fd0     TEST       ESI,ESI
//         00509fd2     JZ         LAB_00509ff4
//         00509fd4     MOV        this,ESI
//         00509fd6     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//         00509fdb     MOV        EAX,dword ptr [ESP + param_1]
//         00509fdf     MOV        EDX,dword ptr [ESI]
//         00509fe1     PUSH       0x0
//         00509fe3     MOV        this,dword ptr [EAX + 0x3c]
//         00509fe6     PUSH       this
//         00509fe7     MOV        this,dword ptr [EAX + 0x38]
//         00509fea     PUSH       this
//         00509feb     PUSH       EAX
//         00509fec     MOV        this,ESI
//         00509fee     CALL       dword ptr [EDX + 0x98]
//                               LAB_00509ff4                                                 XREF[1]:     00509fd2(j)
//         00509ff4     ADD        EDI,0x4
//         00509ff7     DEC        EBX
//         00509ff8     JNZ        LAB_00509fc4
//                               LAB_00509ffa                                                 XREF[5]:     00509e3d(j), 00509e4b(j),
//                                                                                                         00509e5c(j), 00509fb4(j),
//                                                                                                         00509fbc(j)
//         00509ffa     POP        EDI
//         00509ffb     POP        ESI
//         00509ffc     POP        EBP
//         00509ffd     POP        EBX
//         00509ffe     ADD        ESP,0x18
//         0050a001     RET        0x4
//         0050a004     ??         90h
//         0050a005     NOP
//         0050a006     NOP
//         0050a007     NOP
//         0050a008     NOP
//         0050a009     NOP
//         0050a00a     NOP
//         0050a00b     NOP
//         0050a00c     NOP
//         0050a00d     NOP
//         0050a00e     NOP
//         0050a00f     NOP
    return;
}

void TRIBE_Command::place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6, int param_7, RGE_Static_Object** param_8) {
    /* TODO: Stub */
//                              void __thiscall place_line_of_walls(TRIBE_Command * this, TRIBE_Play
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[3]:     0050a067(R), 0050a098(W), 0050a0a0(R)
//              TRIBE_Master_B    Stack[0x8]:4   param_2                   XREF[3]:     0050a063(R), 0050a0aa(W), 0050a0ae(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[3]:     0050a010(R), 0050a06b(W), 0050a09c(R)
//              int               Stack[0x14]:4  param_5                   XREF[3]:     0050a03d(R), 0050a06f(W), 0050a07c(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0050a014(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0050a041(R)
//              RGE_Static_Obj    Stack[0x20]:4  param_8
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050a078(W), 0050a0b5(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050a049(W), 0050a05f(W)
//              int               Stack[-0xc]:4  y_skip                    XREF[2]:     0050a023(W), 0050a039(W)
//              int               Stack[-0x10]:4 x_skip
//                               ?place_line_of_walls@TRIBE_Command@@AAEXPAVTRIBE_Player@@PA  XREF[3]:     do_command_build_wall:00509ed8(c),
//                               TRIBE_Command::place_line_of_walls                                        do_command_build_wall:00509f4c(c),
//                                                                                                         do_command_build_wall:00509fa9(c)
//                              tcommand.cpp:456 (19)
//         0050a010     MOV        this,dword ptr [ESP + param_4]
//         0050a014     MOV        EAX,dword ptr [ESP + param_6]
//         0050a018     SUB        ESP,0xc
//         0050a01b     CMP        this,EAX
//         0050a01d     PUSH       EBX
//         0050a01e     PUSH       EBP
//         0050a01f     PUSH       ESI
//         0050a020     PUSH       EDI
//         0050a021     JNZ        LAB_0050a02d
//                              tcommand.cpp:462 (8)
//         0050a023     MOV        dword ptr [ESP + y_skip],0x0
//                              tcommand.cpp:463 (18)
//         0050a02b     JMP        LAB_0050a03d
//                               LAB_0050a02d                                                 XREF[1]:     0050a021(j)
//         0050a02d     XOR        EDX,EDX
//         0050a02f     CMP        EAX,this
//         0050a031     SETLE      DL
//         0050a034     DEC        EDX
//         0050a035     AND        EDX,0x2
//         0050a038     DEC        EDX
//         0050a039     MOV        dword ptr [ESP + y_skip],EDX
//                               LAB_0050a03d                                                 XREF[1]:     0050a02b(j)
//                              tcommand.cpp:468 (12)
//         0050a03d     MOV        EAX,dword ptr [ESP + param_5]
//         0050a041     MOV        ESI,dword ptr [ESP + param_7]
//         0050a045     CMP        EAX,ESI
//         0050a047     JNZ        LAB_0050a053
//                              tcommand.cpp:469 (8)
//         0050a049     MOV        dword ptr [ESP + local_8],0x0
//                              tcommand.cpp:470 (18)
//         0050a051     JMP        LAB_0050a063
//                               LAB_0050a053                                                 XREF[1]:     0050a047(j)
//         0050a053     XOR        EDX,EDX
//         0050a055     CMP        ESI,EAX
//         0050a057     SETLE      DL
//         0050a05a     DEC        EDX
//         0050a05b     AND        EDX,0x2
//         0050a05e     DEC        EDX
//         0050a05f     MOV        dword ptr [ESP + local_8],EDX
//                               LAB_0050a063                                                 XREF[1]:     0050a051(j)
//                              tcommand.cpp:483 (90)
//         0050a063     MOV        ESI,dword ptr [ESP + param_2]
//         0050a067     MOV        EBP,dword ptr [ESP + param_1]
//         0050a06b     MOV        dword ptr [ESP + param_4],EAX
//         0050a06f     MOV        dword ptr [ESP + param_5],this
//         0050a073     MOV        EAX,dword ptr [ESI]
//         0050a075     MOV        EAX,dword ptr [EAX + 0x20]
//         0050a078     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_0050a07c                                                 XREF[1]:     0050a124(j)
//         0050a07c     FILD       dword ptr [ESP + param_5]
//         0050a080     MOV        this,byte ptr [ESI + 0x64]
//         0050a083     PUSH       0x1
//         0050a085     PUSH       offset DAT_fffffff8
//         0050a087     PUSH       offset DAT_fffffff4
//         0050a089     FSUB       float ptr [DAT_00576570]                         = align(3)
//         0050a08f     PUSH       0x0=>DAT_fffffff0
//         0050a091     PUSH       this
//         0050a092     PUSH       0x1
//         0050a094     PUSH       0x0
//         0050a096     MOV        this,ESI
//         0050a098     FSTP       float ptr [ESP + param_1]
//         0050a09c     FILD       dword ptr [ESP + param_4]
//         0050a0a0     MOV        EBX,dword ptr [ESP + param_1]
//         0050a0a4     FSUB       float ptr [DAT_00576570]                         = align(3)
//         0050a0aa     FSTP       float ptr [ESP + param_2]
//         0050a0ae     MOV        EDI,dword ptr [ESP + param_2]
//         0050a0b2     PUSH       EDI
//         0050a0b3     PUSH       EBX
//         0050a0b4     PUSH       EBP
//         0050a0b5     CALL       dword ptr [ESP + local_4]
//         0050a0b9     TEST       AL,AL
//         0050a0bb     JNZ        LAB_0050a0f4
//                              tcommand.cpp:486 (23)
//         0050a0bd     MOV        DX,word ptr [ESI + 0x10]
//         0050a0c1     PUSH       0x0
//         0050a0c3     PUSH       offset DAT_fffffff8
//         0050a0c8     PUSH       EDX=>DAT_fffffff4
//         0050a0c9     MOV        this,EBP
//         0050a0cb     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
//         0050a0d0     TEST       AL,AL
//         0050a0d2     JZ         LAB_0050a129
//                              tcommand.cpp:490 (17)
//         0050a0d4     MOV        EAX,dword ptr [ESP + 0x28]
//         0050a0d8     MOV        this,ESI
//         0050a0da     PUSH       EAX
//         0050a0db     MOV        EAX,dword ptr [ESI]
//         0050a0dd     PUSH       0x0=>DAT_fffffff8
//         0050a0df     PUSH       EDI=>DAT_fffffff4
//         0050a0e0     PUSH       EBX=>DAT_fffffff0
//         0050a0e1     PUSH       EBP
//         0050a0e2     CALL       dword ptr [EAX + 0x3c]
//                              tcommand.cpp:493 (13)
//         0050a0e5     TEST       EAX,EAX
//         0050a0e7     JZ         LAB_0050a0f4
//         0050a0e9     MOV        this,dword ptr [ESP + 0x3c]
//         0050a0ed     CMP        dword ptr [this->field0_0x0],0x0
//         0050a0f0     JNZ        LAB_0050a0f4
//                              tcommand.cpp:494 (2)
//         0050a0f2     MOV        dword ptr [this->field0_0x0],EAX
//                               LAB_0050a0f4                                                 XREF[3]:     0050a0bb(j), 0050a0e7(j),
//                                                                                                         0050a0f0(j)
//                              tcommand.cpp:497 (24)
//         0050a0f4     MOV        EAX,dword ptr [ESP + 0x30]
//         0050a0f8     MOV        this,dword ptr [ESP + 0x34]
//         0050a0fc     CMP        EAX,this
//         0050a0fe     JNZ        LAB_0050a10c
//         0050a100     MOV        this,dword ptr [ESP + 0x2c]
//         0050a104     MOV        EDX,dword ptr [ESP + 0x38]
//         0050a108     CMP        this,EDX
//         0050a10a     JZ         LAB_0050a129
//                               LAB_0050a10c                                                 XREF[1]:     0050a0fe(j)
//                              tcommand.cpp:500 (4)
//         0050a10c     MOV        this,dword ptr [ESP + 0x10]
//                              tcommand.cpp:501 (25)
//         0050a110     MOV        EDX,dword ptr [ESP + 0x14]
//         0050a114     ADD        EAX,this
//         0050a116     MOV        dword ptr [ESP + 0x30],EAX
//         0050a11a     MOV        EAX,dword ptr [ESP + 0x2c]
//         0050a11e     ADD        EAX,EDX
//         0050a120     MOV        dword ptr [ESP + 0x2c],EAX
//         0050a124     JMP        LAB_0050a07c
//                               LAB_0050a129                                                 XREF[2]:     0050a0d2(j), 0050a10a(j)
//                              tcommand.cpp:503 (10)
//         0050a129     POP        EDI
//         0050a12a     POP        ESI
//         0050a12b     POP        EBP
//         0050a12c     POP        EBX
//         0050a12d     ADD        ESP,0xc
//         0050a130     RET        0x20
//         0050a133     ??         90h
//         0050a134     NOP
//         0050a135     NOP
//         0050a136     NOP
//         0050a137     NOP
//         0050a138     NOP
//         0050a139     NOP
//         0050a13a     NOP
//         0050a13b     NOP
//         0050a13c     NOP
//         0050a13d     NOP
//         0050a13e     NOP
//         0050a13f     NOP
    return;
}

void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_explore(TRIBE_Command * this, TRIBE_Comma
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[4]:     0050a146(R), 0050a165(W), 0050a1ab(R), 0050a1ba(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050a14f(W)
//                               ?do_command_explore@TRIBE_Command@@AAEXPAUTRIBE_Command_Exp  XREF[1]:     do_command:005097d8(c)
//                               TRIBE_Command::do_command_explore
//                              tcommand.cpp:508 (6)
//         0050a140     PUSH       this
//         0050a141     PUSH       EBX
//         0050a142     PUSH       EBP
//         0050a143     MOV        EBP,this
//         0050a145     PUSH       EDI
//                              tcommand.cpp:511 (4)
//         0050a146     MOV        EDI,dword ptr [ESP + param_1]
//                              tcommand.cpp:513 (24)
//         0050a14a     XOR        EAX,EAX
//         0050a14c     MOV        this,dword ptr [EBP + 0x4]
//         0050a14f     MOV        dword ptr [ESP + local_4],EBP
//         0050a153     MOV        AL,byte ptr [EDI + 0x2]
//         0050a156     LEA        EBX,[EDI + 0xc]
//         0050a159     MOV        EDX,dword ptr [this->field0_0x0 + 0x40]
//         0050a15c     CMP        dword ptr [EDX + EAX*0x4],0x0
//         0050a160     JZ         LAB_0050a1c1
//                              tcommand.cpp:517 (15)
//         0050a162     MOV        AL,byte ptr [EDI + 0x1]
//         0050a165     MOV        dword ptr [ESP + param_1],0x0
//         0050a16d     TEST       AL,AL
//         0050a16f     JBE        LAB_0050a1c1
//                              tcommand.cpp:508 (1)
//         0050a171     PUSH       ESI
//                               LAB_0050a172                                                 XREF[1]:     0050a1be(j)
//                              tcommand.cpp:518 (12)
//         0050a172     MOV        EAX,dword ptr [EBX]
//         0050a174     MOV        this,EBP
//         0050a176     PUSH       EAX
//         0050a177     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//         0050a17c     MOV        ESI,EAX
//                              tcommand.cpp:519 (4)
//         0050a17e     TEST       ESI,ESI
//         0050a180     JZ         LAB_0050a1ab
//                              tcommand.cpp:521 (7)
//         0050a182     MOV        this,ESI
//         0050a184     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//                              tcommand.cpp:524 (55)
//         0050a189     FLD        float ptr [EDI + 0x8]
//         0050a18c     MOV        EBP,dword ptr [ESI]
//         0050a18e     PUSH       0x1
//         0050a190     CALL       __ftol                                           undefined __ftol()
//         0050a195     FLD        float ptr [EDI + 0x4]
//         0050a198     PUSH       EAX
//         0050a199     CALL       __ftol                                           undefined __ftol()
//         0050a19e     PUSH       EAX
//         0050a19f     MOV        this,ESI
//         0050a1a1     CALL       dword ptr [EBP + 0x17c]
//         0050a1a7     MOV        EBP,dword ptr [ESP + 0x10]
//                               LAB_0050a1ab                                                 XREF[1]:     0050a180(j)
//         0050a1ab     MOV        EAX,dword ptr [ESP + param_1]
//         0050a1af     XOR        this,this
//         0050a1b1     MOV        this,byte ptr [EDI + 0x1]
//         0050a1b4     INC        EAX
//         0050a1b5     ADD        EBX,0x4
//         0050a1b8     CMP        EAX,this
//         0050a1ba     MOV        dword ptr [ESP + param_1],EAX
//         0050a1be     JL         LAB_0050a172
//                              tcommand.cpp:508 (1)
//         0050a1c0     POP        ESI
//                               LAB_0050a1c1                                                 XREF[2]:     0050a160(j), 0050a16f(j)
//                              tcommand.cpp:527 (7)
//         0050a1c1     POP        EDI
//         0050a1c2     POP        EBP
//         0050a1c3     POP        EBX
//         0050a1c4     POP        this
//         0050a1c5     RET        0x4
//         0050a1c8     ??         90h
//         0050a1c9     NOP
//         0050a1ca     NOP
//         0050a1cb     NOP
//         0050a1cc     NOP
//         0050a1cd     NOP
//         0050a1ce     NOP
//         0050a1cf     NOP
    return;
}

void TRIBE_Command::do_command_game(TRIBE_Command_Game* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_game(TRIBE_Command * this, TRIBE_Command_
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a1ef(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050a2a2(W), 0050a2ca(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050a44b(R)
//              char[260]         Stack[-0x114   fileName                  XREF[1,2]:   0050a29a(W), 0050a34d(*), 0050a365(*)
//                               ?do_command_game@TRIBE_Command@@AAEXPAUTRIBE_Command_Game@@@Z XREF[1]:     do_command:005097e4(c)
//                               TRIBE_Command::do_command_game
//                              tcommand.cpp:531 (27)
//         0050a1d0     MOV        EAX,FS:[0x0]
//         0050a1d6     PUSH       -0x1
//         0050a1d8     PUSH       FUN_00560e0e
//         0050a1dd     PUSH       EAX
//         0050a1de     MOV        dword ptr FS:[0x0],ESP
//         0050a1e5     SUB        ESP,0x108
//                              tcommand.cpp:532 (33)
//         0050a1eb     XOR        EAX,EAX
//         0050a1ed     PUSH       EBX
//         0050a1ee     PUSH       ESI
//         0050a1ef     MOV        ESI,dword ptr [ESP + param_1]
//         0050a1f6     PUSH       EDI
//         0050a1f7     MOV        EDI,this
//         0050a1f9     MOV        AL,byte ptr [ESI + 0x1]
//         0050a1fc     CMP        EAX,0x8
//         0050a1ff     JA         switchD_0050a205::caseD_3
//                               switchD_0050a205::switchD
//         0050a205     JMP        dword ptr [EAX*0x4 + switchD_0050a205::switchd   = 0050a227
//                               switchD_0050a205::caseD_5                                    XREF[2]:     0050a205(j), 0050a47c(*)
//                              tcommand.cpp:538 (22)
//         0050a20c     MOV        AL,byte ptr [ESI + 0x4]
//         0050a20f     MOV        EDX,dword ptr [EDI + 0x4]
//         0050a212     MOVSX      this,word ptr [ESI + 0x2]
//         0050a216     PUSH       EAX
//         0050a217     MOV        EAX,dword ptr [EDX + 0x40]
//         0050a21a     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//         0050a21d     CALL       RGE_Player::set_allied_victory                   void set_allied_victory(RGE_Player * this, uc
//                              tcommand.cpp:539 (5)
//         0050a222     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_0                                    XREF[2]:     0050a205(j), 0050a468(*)
//                              tcommand.cpp:544 (32)
//         0050a227     FLD        float ptr [ESI + 0x8]
//         0050a22a     CALL       __ftol                                           undefined __ftol()
//         0050a22f     MOVSX      this,word ptr [ESI + 0x4]
//         0050a233     MOV        EDX,dword ptr [EDI + 0x4]
//         0050a236     PUSH       EAX
//         0050a237     MOVSX      EAX,word ptr [ESI + 0x2]
//         0050a23b     PUSH       this
//         0050a23c     MOV        this,dword ptr [EDX + 0x40]
//         0050a23f     MOV        this,dword ptr [this->field0_0x0 + EAX*0x4]
//         0050a242     CALL       RGE_Player::set_relation                         void set_relation(RGE_Player * this, long par
//                              tcommand.cpp:546 (30)
//         0050a247     MOVSX      EAX,word ptr [ESI + 0xc]
//         0050a24b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a251     PUSH       0x0
//         0050a253     PUSH       EAX
//         0050a254     MOVSX      EAX,word ptr [ESI + 0x4]
//         0050a258     MOV        EDX,dword ptr [this->field0_0x0]
//         0050a25a     PUSH       EAX
//         0050a25b     MOVSX      EAX,word ptr [ESI + 0x2]
//         0050a25f     PUSH       EAX
//         0050a260     PUSH       0x8
//         0050a262     CALL       dword ptr [EDX + 0x40]
//                              tcommand.cpp:547 (8)
//         0050a265     MOV        this,dword ptr [EDI + 0x4]
//         0050a268     CALL       RGE_Game_World::update_mutual_allies             void update_mutual_allies(RGE_Game_World * th
//                              tcommand.cpp:549 (5)
//         0050a26d     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_1                                    XREF[2]:     0050a205(j), 0050a46c(*)
//                              tcommand.cpp:555 (12)
//         0050a272     MOV        this,dword ptr [ESI + 0x8]
//         0050a275     PUSH       this
//         0050a276     MOV        this,dword ptr [EDI + 0x4]
//         0050a279     CALL       RGE_Game_World::set_game_speed                   void set_game_speed(RGE_Game_World * this, fl
//                              tcommand.cpp:556 (5)
//         0050a27e     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_8                                    XREF[2]:     0050a205(j), 0050a488(*)
//                              tcommand.cpp:581 (60)
//         0050a283     PUSH       0x47c
//         0050a288     MOV        dword ptr [out_of_sync2],0x1
//         0050a292     CALL       operator_new                                     void * operator_new(uint param_1)
//         0050a297     ADD        ESP,0x4
//         0050a29a     MOV        dword ptr [ESP + fileName[0]],EAX
//         0050a29e     XOR        EBX,EBX
//         0050a2a0     CMP        EAX,EBX
//         0050a2a2     MOV        dword ptr [ESP + local_4],EBX
//         0050a2a9     JZ         LAB_0050a2bf
//         0050a2ab     PUSH       -0x1
//         0050a2ad     PUSH       EBX
//         0050a2ae     PUSH       s_                                               = ""
//         0050a2b3     PUSH       s_Temp_Screen                                    = "Temp Screen"
//         0050a2b8     MOV        this,EAX
//         0050a2ba     CALL       TRIBE_Screen_Status_Message::TRIBE_Screen_Stat   undefined TRIBE_Screen_Status_Message(TRIBE_S
//                               LAB_0050a2bf                                                 XREF[1]:     0050a2a9(j)
//                              tcommand.cpp:582 (27)
//         0050a2bf     PUSH       EBX
//         0050a2c0     PUSH       s_Temp_Screen                                    = "Temp Screen"
//         0050a2c5     MOV        this,panel_system
//         0050a2ca     MOV        dword ptr [ESP + local_4],0xffffffff
//         0050a2d5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              tcommand.cpp:584 (13)
//         0050a2da     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a2e0     PUSH       0x1
//         0050a2e2     CALL       TRIBE_Game::close_game_screens                   void close_game_screens(TRIBE_Game * this, in
//                              tcommand.cpp:587 (8)
//         0050a2e7     CMP        dword ptr [do_debug_random],EBX
//         0050a2ed     JZ         LAB_0050a341
//                              tcommand.cpp:589 (5)
//         0050a2ef     CALL       debug_random_write                               void debug_random_write(void)
//                              tcommand.cpp:590 (5)
//         0050a2f4     CALL       dump_vismap_log                                  void dump_vismap_log(void)
//                              tcommand.cpp:591 (9)
//         0050a2f9     MOV        EAX,[actionFile]                                 = 00000000
//         0050a2fe     CMP        EAX,EBX
//         0050a300     JZ         LAB_0050a311
//                              tcommand.cpp:593 (9)
//         0050a302     PUSH       EAX
//         0050a303     CALL       fclose                                           undefined fclose()
//         0050a308     ADD        ESP,0x4
//                              tcommand.cpp:594 (6)
//         0050a30b     MOV        dword ptr [actionFile],EBX                       = 00000000
//                               LAB_0050a311                                                 XREF[1]:     0050a300(j)
//                              tcommand.cpp:596 (9)
//         0050a311     MOV        EAX,[DVlogf]                                     = 00000000
//         0050a316     CMP        EAX,EBX
//         0050a318     JZ         LAB_0050a329
//                              tcommand.cpp:598 (9)
//         0050a31a     PUSH       EAX
//         0050a31b     CALL       fclose                                           undefined fclose()
//         0050a320     ADD        ESP,0x4
//                              tcommand.cpp:599 (6)
//         0050a323     MOV        dword ptr [DVlogf],EBX                           = 00000000
//                               LAB_0050a329                                                 XREF[1]:     0050a318(j)
//                              tcommand.cpp:601 (9)
//         0050a329     MOV        EAX,[DDlogf]                                     = 00000000
//         0050a32e     CMP        EAX,EBX
//         0050a330     JZ         LAB_0050a341
//                              tcommand.cpp:603 (9)
//         0050a332     PUSH       EAX
//         0050a333     CALL       fclose                                           undefined fclose()
//         0050a338     ADD        ESP,0x4
//                              tcommand.cpp:604 (6)
//         0050a33b     MOV        dword ptr [DDlogf],EBX                           = 00000000
//                               LAB_0050a341                                                 XREF[2]:     0050a2ed(j), 0050a330(j)
//                              tcommand.cpp:610 (27)
//         0050a341     MOV        this,dword ptr [comm]                            = 00000000
//         0050a347     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         0050a34c     PUSH       EAX
//         0050a34d     LEA        EDX=>fileName[4],[ESP + 0x14]
//         0050a351     PUSH       s_syncerr%d.gam                                  = "syncerr%d.gam"
//         0050a356     PUSH       EDX
//         0050a357     CALL       sprintf                                          undefined sprintf()
//                              tcommand.cpp:611 (19)
//         0050a35c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a362     ADD        ESP,0xc
//         0050a365     LEA        EAX=>fileName[4],[ESP + 0x10]
//         0050a369     PUSH       EAX
//         0050a36a     CALL       TRIBE_Game::save_game                            int save_game(TRIBE_Game * this, char * param
//                              tcommand.cpp:613 (18)
//         0050a36f     MOV        EDI,dword ptr [EDI + 0x4]
//         0050a372     MOVSX      this,word ptr [EDI + 0x7c]
//         0050a376     MOV        EDX,dword ptr [EDI + 0x40]
//         0050a379     MOV        this,dword ptr [EDX + this->field0_0x0*0x4]
//         0050a37c     CALL       RGE_Player::loss_if_game_on                      void loss_if_game_on(RGE_Player * this)
//                              tcommand.cpp:614 (11)
//         0050a381     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a387     CALL       TRIBE_Game::do_game_over                         void do_game_over(TRIBE_Game * this)
//                              tcommand.cpp:615 (12)
//         0050a38c     MOV        this,panel_system
//         0050a391     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         0050a396     MOV        ESI,EAX
//                              tcommand.cpp:616 (4)
//         0050a398     CMP        ESI,EBX
//         0050a39a     JZ         LAB_0050a3dd
//                              tcommand.cpp:618 (23)
//         0050a39c     MOV        EAX,[rge_base_game]                              = 00000000
//         0050a3a1     MOV        this,ESI
//         0050a3a3     MOV        EDI,dword ptr [EAX + 0x48]
//         0050a3a6     CALL       TEasy_Panel::get_palette                         void * get_palette(TEasy_Panel * this)
//         0050a3ab     PUSH       EAX
//         0050a3ac     MOV        this,EDI
//         0050a3ae     CALL       TDrawSystem::SetPalette                          void SetPalette(TDrawSystem * this, void * pa
//                              tcommand.cpp:619 (11)
//         0050a3b3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a3b9     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                              tcommand.cpp:620 (11)
//         0050a3be     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0050a3c4     CALL       RGE_Base_Game::draw_window                       void draw_window(RGE_Base_Game * this)
//                              tcommand.cpp:621 (20)
//         0050a3c9     PUSH       0x64
//         0050a3cb     PUSH       0x1c2
//         0050a3d0     PUSH       EBX
//                              language.dll match for 0x966: "You were dropped from the game
//         0050a3d1     PUSH       0x966
//         0050a3d6     MOV        this,ESI
//         0050a3d8     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                               LAB_0050a3dd                                                 XREF[1]:     0050a39a(j)
//                              tcommand.cpp:624 (15)
//         0050a3dd     PUSH       s_Temp_Screen                                    = "Temp Screen"
//         0050a3e2     MOV        this,panel_system
//         0050a3e7     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              tcommand.cpp:634 (2)
//         0050a3ec     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_2                                    XREF[2]:     0050a205(j), 0050a470(*)
//                              tcommand.cpp:640 (29)
//         0050a3ee     MOV        EDX,dword ptr [EDI + 0x4]
//         0050a3f1     PUSH       0x0
//         0050a3f3     MOVSX      this,word ptr [ESI + 0x2]
//         0050a3f7     MOV        EAX,dword ptr [EDX + 0x40]
//         0050a3fa     MOV        this,dword ptr [EAX + this->field0_0x0*0x4]
//         0050a3fd     MOV        EAX,dword ptr [ESI + 0x8]
//         0050a400     PUSH       EAX
//         0050a401     MOV        AX,word ptr [ESI + 0x4]
//         0050a405     MOV        EDX,dword ptr [this->field0_0x0]
//         0050a407     PUSH       EAX
//         0050a408     CALL       dword ptr [EDX + 0x78]
//                              tcommand.cpp:641 (2)
//         0050a40b     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_4                                    XREF[2]:     0050a205(j), 0050a478(*)
//                              tcommand.cpp:650 (15)
//         0050a40d     MOVSX      this,word ptr [ESI + 0x2]
//         0050a411     MOV        EAX,[rge_base_game]                              = 00000000
//         0050a416     MOV        dword ptr [EAX + 0x9a8],this
//                              tcommand.cpp:651 (2)
//         0050a41c     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_6                                    XREF[2]:     0050a205(j), 0050a480(*)
//                              tcommand.cpp:656 (19)
//         0050a41e     MOVZX      DX,byte ptr [ESI + 0x4]
//         0050a423     MOV        AX,word ptr [ESI + 0x2]
//         0050a427     MOV        this,dword ptr [EDI + 0x4]
//         0050a42a     PUSH       EDX
//         0050a42b     PUSH       EAX
//         0050a42c     CALL       TRIBE_World::cheat                               void cheat(TRIBE_World * this, short param_1,
//                              tcommand.cpp:657 (2)
//         0050a431     JMP        switchD_0050a205::caseD_3
//                               switchD_0050a205::caseD_7                                    XREF[2]:     0050a205(j), 0050a484(*)
//                              tcommand.cpp:662 (24)
//         0050a433     MOV        EDI,dword ptr [EDI + 0x4]
//         0050a436     MOVSX      EAX,word ptr [ESI + 0x2]
//         0050a43a     MOV        ESI,dword ptr [EDI + 0x40]
//         0050a43d     MOV        this,dword ptr [EDI + 0x4c]
//         0050a440     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         0050a443     MOV        EDX,dword ptr [this->field0_0x0]
//         0050a445     PUSH       EAX
//                              language.dll match for 0x71: "Copperplate Gothic Light"
//         0050a446     PUSH       0x71
//         0050a448     CALL       dword ptr [EDX + 0x8]
//                               switchD_0050a205::caseD_3                                    XREF[10]:    0050a1ff(j), 0050a205(j),
//                                                                                                         0050a222(j), 0050a26d(j),
//                                                                                                         0050a27e(j), 0050a3ec(j),
//                                                                                                         0050a40b(j), 0050a41c(j),
//                                                                                                         0050a431(j), 0050a474(*)
//                              tcommand.cpp:665 (65)
//         0050a44b     MOV        this,dword ptr [ESP + local_c]
//         0050a452     POP        EDI
//         0050a453     POP        ESI
//         0050a454     MOV        dword ptr FS:[0x0],this
//         0050a45b     POP        EBX
//         0050a45c     ADD        ESP,0x114
//         0050a462     RET        0x4
    return;
}

void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_cancel_build(TRIBE_Command * this, TRIBE_
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a490(R)
//                               ?do_command_cancel_build@TRIBE_Command@@AAEXPAUTRIBE_Comman  XREF[1]:     do_command:005097fc(c)
//                               TRIBE_Command::do_command_cancel_build
//                              tcommand.cpp:671 (16)
//         0050a490     MOV        EAX,dword ptr [ESP + param_1]
//         0050a494     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050a497     MOV        EDX,dword ptr [EAX + 0x4]
//         0050a49a     PUSH       EDX
//         0050a49b     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              tcommand.cpp:678 (4)
//         0050a4a0     TEST       EAX,EAX
//         0050a4a2     JZ         LAB_0050a4ae
//                              tcommand.cpp:681 (10)
//         0050a4a4     MOV        EDX,dword ptr [EAX]
//         0050a4a6     MOV        this,EAX
//         0050a4a8     CALL       dword ptr [EDX + 0x240]
//                               LAB_0050a4ae                                                 XREF[1]:     0050a4a2(j)
//                              tcommand.cpp:683 (3)
//         0050a4ae     RET        0x4
//         0050a4b1     ??         90h
//         0050a4b2     NOP
//         0050a4b3     NOP
//         0050a4b4     NOP
//         0050a4b5     NOP
//         0050a4b6     NOP
//         0050a4b7     NOP
//         0050a4b8     NOP
//         0050a4b9     NOP
//         0050a4ba     NOP
//         0050a4bb     NOP
//         0050a4bc     NOP
//         0050a4bd     NOP
//         0050a4be     NOP
//         0050a4bf     NOP
    return;
}

void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_attack_ground(TRIBE_Command * this, TRIBE
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a4c2(R)
//                               ?do_command_attack_ground@TRIBE_Command@@AAEXPAUTRIBE_Comma  XREF[1]:     do_command:00509808(c)
//                               TRIBE_Command::do_command_attack_ground
//                              tcommand.cpp:688 (2)
//         0050a4c0     PUSH       EBX
//         0050a4c1     PUSH       ESI
//                              tcommand.cpp:689 (12)
//         0050a4c2     MOV        ESI,dword ptr [ESP + param_1]
//         0050a4c6     XOR        EAX,EAX
//         0050a4c8     PUSH       EDI
//         0050a4c9     MOV        EBX,this
//         0050a4cb     MOV        AL,byte ptr [ESI + 0x1]
//                              tcommand.cpp:690 (3)
//         0050a4ce     LEA        EDI,[ESI + 0xc]
//                              tcommand.cpp:692 (7)
//         0050a4d1     TEST       EAX,EAX
//         0050a4d3     JLE        LAB_0050a503
//         0050a4d5     PUSH       EBP
//         0050a4d6     MOV        EBP,EAX
//                               LAB_0050a4d8                                                 XREF[1]:     0050a500(j)
//                              tcommand.cpp:697 (10)
//         0050a4d8     MOV        EAX,dword ptr [EDI]
//         0050a4da     MOV        this,EBX
//         0050a4dc     PUSH       EAX
//         0050a4dd     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:698 (4)
//         0050a4e2     TEST       EAX,EAX
//         0050a4e4     JZ         LAB_0050a4fc
//                              tcommand.cpp:700 (28)
//         0050a4e6     MOV        this,dword ptr [ESI + 0x8]
//         0050a4e9     MOV        EDX,dword ptr [EAX]
//         0050a4eb     PUSH       0x1
//         0050a4ed     PUSH       0x0
//         0050a4ef     PUSH       this
//         0050a4f0     MOV        this,dword ptr [ESI + 0x4]
//         0050a4f3     PUSH       this
//         0050a4f4     MOV        this,EAX
//         0050a4f6     CALL       dword ptr [EDX + 0x14c]
//                               LAB_0050a4fc                                                 XREF[1]:     0050a4e4(j)
//         0050a4fc     ADD        EDI,0x4
//         0050a4ff     DEC        EBP
//         0050a500     JNZ        LAB_0050a4d8
//                              tcommand.cpp:688 (1)
//         0050a502     POP        EBP
//                               LAB_0050a503                                                 XREF[1]:     0050a4d3(j)
//                              tcommand.cpp:703 (6)
//         0050a503     POP        EDI
//         0050a504     POP        ESI
//         0050a505     POP        EBX
//         0050a506     RET        0x4
//         0050a509     ??         90h
//         0050a50a     NOP
//         0050a50b     NOP
//         0050a50c     NOP
//         0050a50d     NOP
//         0050a50e     NOP
//         0050a50f     NOP
    return;
}

void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_give_attribute(TRIBE_Command * this, TRIB
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[8]:     0050a514(R), 0050a536(W), 0050a53c(W), 0050a544(R),
//                                                                                     0050a558(R), 0050a570(R), 0050a5a2(W), 0050a5a6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0050a524(W), 0050a55c(W), 0050a57d(R), 0050a59a(W),
//                                                                                     0050a59e(R)
//              float             Stack[-0x8]:4  cost
//                               ?do_command_give_attribute@TRIBE_Command@@EAEXPAUTRIBE_Comm  XREF[1]:     00576568(*)
//                               TRIBE_Command::do_command_give_attribute
//                              tcommand.cpp:708 (4)
//         0050a510     PUSH       this
//         0050a511     PUSH       EBX
//         0050a512     PUSH       EBP
//         0050a513     PUSH       ESI
//                              tcommand.cpp:713 (31)
//         0050a514     MOV        ESI,dword ptr [ESP + param_1]
//         0050a518     PUSH       EDI
//         0050a519     MOV        EDI,this
//         0050a51b     FLD        float ptr [ESI + 0x4]
//         0050a51e     FCOMP      float ptr [DAT_00576574]
//         0050a524     MOV        dword ptr [ESP + local_4],0x0
//         0050a52c     FNSTSW     AX
//         0050a52e     TEST       AH,0x1
//         0050a531     JNZ        LAB_0050a53c
//                              tcommand.cpp:714 (7)
//         0050a533     MOV        EAX,dword ptr [ESI + 0x4]
//         0050a536     MOV        dword ptr [ESP + param_1],EAX
//                              tcommand.cpp:715 (2)
//         0050a53a     JMP        LAB_0050a544
//                               LAB_0050a53c                                                 XREF[1]:     0050a531(j)
//                              tcommand.cpp:716 (8)
//         0050a53c     MOV        dword ptr [ESP + param_1],0x0
//                               LAB_0050a544                                                 XREF[1]:     0050a53a(j)
//                              tcommand.cpp:720 (17)
//         0050a544     FLD        float ptr [ESP + param_1]
//         0050a548     FCOMP      double ptr [DAT_00576578]
//         0050a54e     FNSTSW     AX
//         0050a550     TEST       AH,0x41
//         0050a553     JNZ        LAB_0050a560
//                              tcommand.cpp:722 (11)
//         0050a555     FLD        float ptr [ESI + 0x8]
//         0050a558     FMUL       float ptr [ESP + param_1]
//         0050a55c     FSTP       float ptr [ESP + local_4]
//                               LAB_0050a560                                                 XREF[1]:     0050a553(j)
//                              tcommand.cpp:727 (49)
//         0050a560     MOV        this,dword ptr [EDI + 0x4]
//         0050a563     MOV        DL,byte ptr [ESI + 0x3]
//         0050a566     XOR        EAX,EAX
//         0050a568     MOV        EBX,EDX
//         0050a56a     MOV        this,dword ptr [this->field0_0x0 + 0x40]
//         0050a56d     MOV        AL,byte ptr [ESI + 0x1]
//         0050a570     FLD        float ptr [ESP + param_1]
//         0050a574     MOV        EAX,dword ptr [this->field0_0x0 + EAX*0x4]
//         0050a577     AND        EBX,0xff
//         0050a57d     FADD       float ptr [ESP + local_4]
//         0050a581     MOV        EAX,dword ptr [EAX + 0x50]
//         0050a584     FCOMP      float ptr [EAX + EBX*0x4]
//         0050a587     LEA        EBX,[EAX + EBX*0x4]
//         0050a58a     FNSTSW     AX
//         0050a58c     TEST       AH,0x41
//         0050a58f     JNZ        LAB_0050a5a6
//                              tcommand.cpp:729 (5)
//         0050a591     FLD        float ptr [EBX]
//         0050a593     FMUL       float ptr [ESI + 0x8]
//                              tcommand.cpp:730 (16)
//         0050a596     FLD        float ptr [EBX]
//         0050a598     FXCH
//         0050a59a     FSTP       float ptr [ESP + local_4]
//         0050a59e     FSUB       float ptr [ESP + local_4]
//         0050a5a2     FSTP       float ptr [ESP + param_1]
//                               LAB_0050a5a6                                                 XREF[1]:     0050a58f(j)
//                              tcommand.cpp:748 (25)
//         0050a5a6     MOV        EBX,dword ptr [ESP + param_1]
//         0050a5aa     XOR        EAX,EAX
//         0050a5ac     MOV        AL,byte ptr [ESI + 0x2]
//         0050a5af     PUSH       0x0
//         0050a5b1     MOVZX      DX,DL
//         0050a5b5     MOV        this,dword ptr [this->field0_0x0 + EAX*0x4]
//         0050a5b8     PUSH       EBX
//         0050a5b9     PUSH       EDX
//         0050a5ba     MOV        EAX,dword ptr [this->field0_0x0]
//         0050a5bc     CALL       dword ptr [EAX + 0x78]
//                              tcommand.cpp:750 (49)
//         0050a5bf     FLD        float ptr [ESP + 0x18]
//         0050a5c3     MOV        EAX,dword ptr [EDI + 0x4]
//         0050a5c6     XOR        this,this
//         0050a5c8     FADD       float ptr [ESP + 0x10]
//         0050a5cc     MOV        this,byte ptr [ESI + 0x1]
//         0050a5cf     MOV        EDX,dword ptr [EAX + 0x40]
//         0050a5d2     PUSH       0x0
//         0050a5d4     MOV        this,dword ptr [EDX + this->field0_0x0*0x4]
//         0050a5d7     FSTP       float ptr [ESP + 0x14]
//         0050a5db     FLD        float ptr [ESP + 0x14]
//         0050a5df     MOVZX      DX,byte ptr [ESI + 0x3]
//         0050a5e4     FCHS
//         0050a5e6     MOV        EAX,dword ptr [this->field0_0x0]
//         0050a5e8     PUSH       this=>DAT_fffffff8
//         0050a5e9     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0050a5ec     PUSH       EDX=>DAT_fffffff4
//         0050a5ed     CALL       dword ptr [EAX + 0x78]
//                              tcommand.cpp:754 (28)
//         0050a5f0     MOV        EAX,dword ptr [EDI + 0x4]
//         0050a5f3     XOR        this,this
//         0050a5f5     MOV        this,byte ptr [ESI + 0x1]
//         0050a5f8     PUSH       0x0
//         0050a5fa     MOV        EDX,dword ptr [EAX + 0x40]
//         0050a5fd     MOV        this,dword ptr [EDX + this->field0_0x0*0x4]
//         0050a600     MOV        EDX,dword ptr [ESP + 0x14]
//         0050a604     PUSH       EDX=>DAT_fffffff8
//         0050a605     PUSH       offset DAT_fffffff4
//         0050a607     MOV        EAX,dword ptr [this->field0_0x0]
//         0050a609     CALL       dword ptr [EAX + 0x78]
//                              tcommand.cpp:756 (33)
//         0050a60c     MOV        EAX,dword ptr [EDI + 0x4]
//         0050a60f     XOR        this,this
//         0050a611     MOV        this,byte ptr [ESI + 0x2]
//         0050a614     PUSH       0x0
//         0050a616     MOV        EDX,dword ptr [EAX + 0x40]
//         0050a619     FLD        float ptr [ESP + 0x1c]
//         0050a61d     MOV        this,dword ptr [EDX + this->field0_0x0*0x4]
//         0050a620     PUSH       this=>DAT_fffffff8
//         0050a621     MOV        EAX,dword ptr [this->field0_0x0]
//         0050a623     FCHS
//         0050a625     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0050a628     PUSH       offset DAT_fffffff4
//         0050a62a     CALL       dword ptr [EAX + 0x78]
//                              tcommand.cpp:761 (43)
//         0050a62d     MOV        EBX,dword ptr [rge_base_game]                    = 00000000
//         0050a633     FLD        float ptr [ESP + 0x18]
//         0050a637     MOV        EBP,dword ptr [EBX]
//         0050a639     CALL       __ftol                                           undefined __ftol()
//         0050a63e     XOR        this,this
//         0050a640     PUSH       EAX
//         0050a641     MOV        this,byte ptr [ESI + 0x3]
//         0050a644     XOR        EDX,EDX
//         0050a646     MOV        DL,byte ptr [ESI + 0x2]
//         0050a649     XOR        EAX,EAX
//         0050a64b     MOV        AL,byte ptr [ESI + 0x1]
//         0050a64e     PUSH       this=>DAT_fffffff8
//         0050a64f     PUSH       EDX=>DAT_fffffff4
//         0050a650     PUSH       EAX=>DAT_fffffff0
//         0050a651     PUSH       0x7
//         0050a653     MOV        this,EBX
//         0050a655     CALL       dword ptr [EBP + 0x40]
//                              tcommand.cpp:767 (53)
//         0050a658     MOV        this,dword ptr [EDI + 0x4]
//         0050a65b     XOR        EBX,EBX
//         0050a65d     MOV        BL,byte ptr [ESI + 0x2]
//         0050a660     PUSH       0x0
//         0050a662     MOV        EDX,dword ptr [this->field0_0x0 + 0x40]
//         0050a665     FLD        float ptr [ESI + 0x4]
//         0050a668     MOV        EDI,dword ptr [EDX + EBX*0x4]
//         0050a66b     MOV        EBP,dword ptr [EDI]
//         0050a66d     CALL       __ftol                                           undefined __ftol()
//         0050a672     PUSH       EAX=>DAT_fffffff8
//         0050a673     XOR        EAX,EAX
//         0050a675     MOV        AL,byte ptr [ESI + 0x3]
//         0050a678     PUSH       EAX=>DAT_fffffff4
//         0050a679     XOR        this,this
//         0050a67b     PUSH       offset DAT_fffffff0
//         0050a680     MOV        this,byte ptr [ESI + 0x1]
//         0050a683     PUSH       EBX
//         0050a684     PUSH       this
//         0050a685     MOV        this,EDI
//         0050a687     CALL       dword ptr [EBP + 0xe8]
//                              tcommand.cpp:770 (8)
//         0050a68d     POP        EDI
//         0050a68e     POP        ESI
//         0050a68f     POP        EBP
//         0050a690     POP        EBX
//         0050a691     POP        this
//         0050a692     RET        0x4
//         0050a695     ??         90h
//         0050a696     NOP
//         0050a697     NOP
//         0050a698     NOP
//         0050a699     NOP
//         0050a69a     NOP
//         0050a69b     NOP
//         0050a69c     NOP
//         0050a69d     NOP
//         0050a69e     NOP
//         0050a69f     NOP
    return;
}

void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_trade_attribute(TRIBE_Command * this, TRI
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a6a1(R)
//                               ?do_command_trade_attribute@TRIBE_Command@@AAEXPAUTRIBE_Com  XREF[1]:     do_command:00509820(c)
//                               TRIBE_Command::do_command_trade_attribute
//                              tcommand.cpp:776 (1)
//         0050a6a0     PUSH       EBP
//                              tcommand.cpp:777 (11)
//         0050a6a1     MOV        EBP,dword ptr [ESP + param_1]
//         0050a6a5     XOR        EAX,EAX
//         0050a6a7     PUSH       ESI
//         0050a6a8     MOV        AL,byte ptr [EBP + 0x1]
//         0050a6ab     PUSH       EDI
//                              tcommand.cpp:780 (12)
//         0050a6ac     TEST       EAX,EAX
//         0050a6ae     MOV        EDI,this
//         0050a6b0     LEA        ESI,[EBP + 0x8]
//         0050a6b3     JLE        LAB_0050a6d5
//         0050a6b5     PUSH       EBX
//         0050a6b6     MOV        EBX,EAX
//                               LAB_0050a6b8                                                 XREF[1]:     0050a6d2(j)
//                              tcommand.cpp:785 (10)
//         0050a6b8     MOV        EAX,dword ptr [ESI]
//         0050a6ba     MOV        this,EDI
//         0050a6bc     PUSH       EAX
//         0050a6bd     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:786 (4)
//         0050a6c2     TEST       EAX,EAX
//         0050a6c4     JZ         LAB_0050a6ce
//                              tcommand.cpp:787 (14)
//         0050a6c6     MOV        this,word ptr [EBP + 0x4]
//         0050a6ca     MOV        word ptr [EAX + 0x4c],this
//                               LAB_0050a6ce                                                 XREF[1]:     0050a6c4(j)
//         0050a6ce     ADD        ESI,0x4
//         0050a6d1     DEC        EBX
//         0050a6d2     JNZ        LAB_0050a6b8
//                              tcommand.cpp:776 (1)
//         0050a6d4     POP        EBX
//                               LAB_0050a6d5                                                 XREF[1]:     0050a6b3(j)
//                              tcommand.cpp:789 (6)
//         0050a6d5     POP        EDI
//         0050a6d6     POP        ESI
//         0050a6d7     POP        EBP
//         0050a6d8     RET        0x4
//         0050a6db     ??         90h
//         0050a6dc     NOP
//         0050a6dd     NOP
//         0050a6de     NOP
//         0050a6df     NOP
    return;
}

void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_repair(TRIBE_Command * this, TRIBE_Comman
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a6e0(R)
//                               ?do_command_repair@TRIBE_Command@@AAEXPAUTRIBE_Command_Repa  XREF[1]:     do_command:0050982c(c)
//                               TRIBE_Command::do_command_repair
//                              tcommand.cpp:795 (8)
//         0050a6e0     MOV        EAX,dword ptr [ESP + param_1]
//         0050a6e4     PUSH       EBX
//         0050a6e5     MOV        EBX,this
//         0050a6e7     PUSH       EBP
//                              tcommand.cpp:801 (23)
//         0050a6e8     MOV        EDX,dword ptr [EAX + 0x4]
//         0050a6eb     XOR        this,this
//         0050a6ed     MOV        this,byte ptr [EAX + 0x1]
//         0050a6f0     PUSH       ESI
//         0050a6f1     PUSH       EDI
//         0050a6f2     MOV        EDI,this
//         0050a6f4     PUSH       EDX
//         0050a6f5     MOV        this,EBX
//         0050a6f7     LEA        ESI,[EAX + 0x8]
//         0050a6fa     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:803 (6)
//         0050a6ff     TEST       EDI,EDI
//         0050a701     MOV        EBP,EAX
//         0050a703     JLE        LAB_0050a721
//                               LAB_0050a705                                                 XREF[1]:     0050a71f(j)
//                              tcommand.cpp:805 (10)
//         0050a705     MOV        EAX,dword ptr [ESI]
//         0050a707     MOV        this,EBX
//         0050a709     PUSH       EAX
//         0050a70a     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//                              tcommand.cpp:806 (4)
//         0050a70f     TEST       EAX,EAX
//         0050a711     JZ         LAB_0050a71b
//                              tcommand.cpp:813 (14)
//         0050a713     PUSH       EBP
//         0050a714     MOV        this,EAX
//         0050a716     CALL       TRIBE_Combat_Object::do_repair                   void do_repair(TRIBE_Combat_Object * this, RG
//                               LAB_0050a71b                                                 XREF[1]:     0050a711(j)
//         0050a71b     ADD        ESI,0x4
//         0050a71e     DEC        EDI
//         0050a71f     JNZ        LAB_0050a705
//                               LAB_0050a721                                                 XREF[1]:     0050a703(j)
//                              tcommand.cpp:815 (7)
//         0050a721     POP        EDI
//         0050a722     POP        ESI
//         0050a723     POP        EBP
//         0050a724     POP        EBX
//         0050a725     RET        0x4
//         0050a728     ??         90h
//         0050a729     NOP
//         0050a72a     NOP
//         0050a72b     NOP
//         0050a72c     NOP
//         0050a72d     NOP
//         0050a72e     NOP
//         0050a72f     NOP
    return;
}

void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_unload(TRIBE_Command * this, TRIBE_Comman
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[4]:     0050a733(R), 0050a749(W), 0050a793(R), 0050a79b(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050a739(W), 0050a74f(R)
//                               ?do_command_unload@TRIBE_Command@@AAEXPAUTRIBE_Command_Unlo  XREF[1]:     do_command:00509838(c)
//                               TRIBE_Command::do_command_unload
//                              tcommand.cpp:820 (3)
//         0050a730     PUSH       this
//         0050a731     PUSH       EBX
//         0050a732     PUSH       EDI
//                              tcommand.cpp:821 (13)
//         0050a733     MOV        EDI,dword ptr [ESP + param_1]
//         0050a737     XOR        EAX,EAX
//         0050a739     MOV        dword ptr [ESP + local_4],this
//         0050a73d     MOV        AL,byte ptr [EDI + 0x1]
//                              tcommand.cpp:822 (3)
//         0050a740     LEA        EBX,[EDI + 0xc]
//                              tcommand.cpp:824 (10)
//         0050a743     TEST       EAX,EAX
//         0050a745     JLE        LAB_0050a7a3
//         0050a747     PUSH       ESI
//         0050a748     PUSH       EBP
//         0050a749     MOV        dword ptr [ESP + param_1],EAX
//                               LAB_0050a74d                                                 XREF[1]:     0050a79f(j)
//                              tcommand.cpp:828 (14)
//         0050a74d     MOV        EAX,dword ptr [EBX]
//         0050a74f     MOV        this,dword ptr [ESP + local_4]
//         0050a753     PUSH       EAX
//         0050a754     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
//         0050a759     MOV        ESI,EAX
//                              tcommand.cpp:829 (4)
//         0050a75b     TEST       ESI,ESI
//         0050a75d     JZ         LAB_0050a793
//                              tcommand.cpp:837 (7)
//         0050a75f     MOV        this,ESI
//         0050a761     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//                              tcommand.cpp:843 (61)
//         0050a766     MOV        this,dword ptr [ESI + 0xc]
//         0050a769     MOV        EBP,dword ptr [EDI + 0x8]
//         0050a76c     MOV        ESI,dword ptr [ESI + 0x4]
//         0050a76f     PUSH       0x64
//         0050a771     MOVSX      EAX,word ptr [this->field0_0x0 + 0x4a]
//         0050a775     PUSH       0x0
//         0050a777     PUSH       0x1
//         0050a779     PUSH       0x3f800000
//         0050a77e     MOV        EDX,dword ptr [this->field0_0x0]
//         0050a780     PUSH       0x0
//         0050a782     PUSH       EBP
//         0050a783     MOV        EBP,dword ptr [EDI + 0x4]
//         0050a786     PUSH       EBP
//         0050a787     PUSH       EAX
//         0050a788     PUSH       ESI
//         0050a789     PUSH       0x2d1
//         0050a78e     PUSH       ESI
//         0050a78f     PUSH       EAX
//         0050a790     CALL       dword ptr [EDX + 0x34]
//                               LAB_0050a793                                                 XREF[1]:     0050a75d(j)
//         0050a793     MOV        EAX,dword ptr [ESP + param_1]
//         0050a797     ADD        EBX,0x4
//         0050a79a     DEC        EAX
//         0050a79b     MOV        dword ptr [ESP + param_1],EAX
//         0050a79f     JNZ        LAB_0050a74d
//         0050a7a1     POP        EBP
//         0050a7a2     POP        ESI
//                               LAB_0050a7a3                                                 XREF[1]:     0050a745(j)
//                              tcommand.cpp:846 (6)
//         0050a7a3     POP        EDI
//         0050a7a4     POP        EBX
//         0050a7a5     POP        this
//         0050a7a6     RET        0x4
//         0050a7a9     ??         90h
//         0050a7aa     NOP
//         0050a7ab     NOP
//         0050a7ac     NOP
//         0050a7ad     NOP
//         0050a7ae     NOP
//         0050a7af     NOP
    return;
}

void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* param_1) {
    /* TODO: Stub */
//                              void __thiscall do_command_queue(TRIBE_Command * this, TRIBE_Command
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              TRIBE_Command_    Stack[0x4]:4   param_1                   XREF[1]:     0050a7b4(R)
//                               ?do_command_queue@TRIBE_Command@@AAEXPAUTRIBE_Command_Queue  XREF[1]:     do_command:00509844(c)
//                               TRIBE_Command::do_command_queue
//                              tcommand.cpp:852 (19)
//         0050a7b0     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050a7b3     PUSH       ESI
//         0050a7b4     MOV        ESI,dword ptr [ESP + param_1]
//         0050a7b8     MOV        EAX,dword ptr [ESI + 0x4]
//         0050a7bb     PUSH       EAX
//         0050a7bc     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0050a7c1     MOV        this,EAX
//                              tcommand.cpp:860 (4)
//         0050a7c3     TEST       this,this
//         0050a7c5     JZ         LAB_0050a7ec
//                              tcommand.cpp:862 (9)
//         0050a7c7     MOV        DX,word ptr [ESI + 0xa]
//         0050a7cb     TEST       DX,DX
//         0050a7ce     JLE        LAB_0050a7df
//                              tcommand.cpp:863 (11)
//         0050a7d0     PUSH       EDX
//         0050a7d1     MOV        DX,word ptr [ESI + 0x8]
//         0050a7d5     PUSH       EDX
//         0050a7d6     CALL       TRIBE_Building_Object::add_to_production_queue   void add_to_production_queue(TRIBE_Building_O
//                              tcommand.cpp:867 (4)
//         0050a7db     POP        ESI
//         0050a7dc     RET        0x4
//                               LAB_0050a7df                                                 XREF[1]:     0050a7ce(j)
//                              tcommand.cpp:865 (13)
//         0050a7df     MOV        AX,word ptr [ESI + 0x8]
//         0050a7e3     NEG        EDX
//         0050a7e5     PUSH       EDX
//         0050a7e6     PUSH       EAX
//         0050a7e7     CALL       TRIBE_Building_Object::remove_from_production_   void remove_from_production_queue(TRIBE_Build
//                               LAB_0050a7ec                                                 XREF[1]:     0050a7c5(j)
//                              tcommand.cpp:867 (4)
//         0050a7ec     POP        ESI
//         0050a7ed     RET        0x4
    return;
}

void TRIBE_Command::command_make(RGE_Static_Object* param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall command_make(TRIBE_Command * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050a883(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0050a863(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050a87f(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050a887(R)
//                               ?command_make@TRIBE_Command@@QAEXHHHH@Z                      XREF[1]:     trainUnit:0051520a(c)
//                               TRIBE_Command::command_make
//                              tcommand.cpp:906 (3)
//         0050a860     PUSH       EBX
//         0050a861     PUSH       ESI
//         0050a862     PUSH       EDI
//                              tcommand.cpp:916 (10)
//         0050a863     MOV        EDI,dword ptr [ESP + param_2]
//         0050a867     TEST       EDI,EDI
//         0050a869     MOV        EBX,this
//         0050a86b     JL         LAB_0050a8bb
//                              tcommand.cpp:921 (14)
//         0050a86d     PUSH       0x10
//         0050a86f     PUSH       0x1
//         0050a871     CALL       calloc                                           undefined calloc()
//         0050a876     MOV        ESI,EAX
//         0050a878     ADD        ESP,0x8
//                              tcommand.cpp:922 (4)
//         0050a87b     TEST       ESI,ESI
//         0050a87d     JZ         LAB_0050a8bb
//                              tcommand.cpp:929 (8)
//         0050a87f     MOV        this,dword ptr [ESP + param_3]
//         0050a883     MOV        EAX,dword ptr [ESP + param_1]
//                              tcommand.cpp:930 (4)
//         0050a887     MOV        EDX,dword ptr [ESP + param_4]
//                              tcommand.cpp:934 (38)
//         0050a88b     PUSH       this
//         0050a88c     PUSH       EDI
//         0050a88d     MOV        dword ptr [ESI + 0x4],EDI
//         0050a890     MOV        byte ptr [ESI + 0x8],AL
//         0050a893     MOV        byte ptr [ESI],0x64
//         0050a896     MOV        word ptr [ESI + 0xa],this
//         0050a89a     MOV        dword ptr [ESI + 0xc],EDX
//         0050a89d     PUSH       EAX
//         0050a89e     MOV        EAX,[L]                                          = 00000000
//         0050a8a3     PUSH       s_______>SEND_CMD_MAKE2_(PLR=%d,BL               = "      >SEND CMD MAKE2 (PLR=%d,BLDG=%d,OBJ=
//         0050a8a8     PUSH       EAX
//         0050a8a9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050a8ae     ADD        ESP,0x14
//                              tcommand.cpp:937 (10)
//         0050a8b1     MOV        this,EBX
//         0050a8b3     PUSH       0x10
//         0050a8b5     PUSH       ESI
//         0050a8b6     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050a8bb                                                 XREF[2]:     0050a86b(j), 0050a87d(j)
//                              tcommand.cpp:938 (6)
//         0050a8bb     POP        EDI
//         0050a8bc     POP        ESI
//         0050a8bd     POP        EBX
//         0050a8be     RET        0x10
//         0050a8c1     ??         90h
//         0050a8c2     NOP
//         0050a8c3     NOP
//         0050a8c4     NOP
//         0050a8c5     NOP
//         0050a8c6     NOP
//         0050a8c7     NOP
//         0050a8c8     NOP
//         0050a8c9     NOP
//         0050a8ca     NOP
//         0050a8cb     NOP
//         0050a8cc     NOP
//         0050a8cd     NOP
//         0050a8ce     NOP
//         0050a8cf     NOP
    return;
}

void TRIBE_Command::command_make(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall command_make(TRIBE_Command * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050a883(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0050a863(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050a87f(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050a887(R)
//                               ?command_make@TRIBE_Command@@QAEXHHHH@Z                      XREF[1]:     trainUnit:0051520a(c)
//                               TRIBE_Command::command_make
//                              tcommand.cpp:906 (3)
//         0050a860     PUSH       EBX
//         0050a861     PUSH       ESI
//         0050a862     PUSH       EDI
//                              tcommand.cpp:916 (10)
//         0050a863     MOV        EDI,dword ptr [ESP + param_2]
//         0050a867     TEST       EDI,EDI
//         0050a869     MOV        EBX,this
//         0050a86b     JL         LAB_0050a8bb
//                              tcommand.cpp:921 (14)
//         0050a86d     PUSH       0x10
//         0050a86f     PUSH       0x1
//         0050a871     CALL       calloc                                           undefined calloc()
//         0050a876     MOV        ESI,EAX
//         0050a878     ADD        ESP,0x8
//                              tcommand.cpp:922 (4)
//         0050a87b     TEST       ESI,ESI
//         0050a87d     JZ         LAB_0050a8bb
//                              tcommand.cpp:929 (8)
//         0050a87f     MOV        this,dword ptr [ESP + param_3]
//         0050a883     MOV        EAX,dword ptr [ESP + param_1]
//                              tcommand.cpp:930 (4)
//         0050a887     MOV        EDX,dword ptr [ESP + param_4]
//                              tcommand.cpp:934 (38)
//         0050a88b     PUSH       this
//         0050a88c     PUSH       EDI
//         0050a88d     MOV        dword ptr [ESI + 0x4],EDI
//         0050a890     MOV        byte ptr [ESI + 0x8],AL
//         0050a893     MOV        byte ptr [ESI],0x64
//         0050a896     MOV        word ptr [ESI + 0xa],this
//         0050a89a     MOV        dword ptr [ESI + 0xc],EDX
//         0050a89d     PUSH       EAX
//         0050a89e     MOV        EAX,[L]                                          = 00000000
//         0050a8a3     PUSH       s_______>SEND_CMD_MAKE2_(PLR=%d,BL               = "      >SEND CMD MAKE2 (PLR=%d,BLDG=%d,OBJ=
//         0050a8a8     PUSH       EAX
//         0050a8a9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050a8ae     ADD        ESP,0x14
//                              tcommand.cpp:937 (10)
//         0050a8b1     MOV        this,EBX
//         0050a8b3     PUSH       0x10
//         0050a8b5     PUSH       ESI
//         0050a8b6     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050a8bb                                                 XREF[2]:     0050a86b(j), 0050a87d(j)
//                              tcommand.cpp:938 (6)
//         0050a8bb     POP        EDI
//         0050a8bc     POP        ESI
//         0050a8bd     POP        EBX
//         0050a8be     RET        0x10
//         0050a8c1     ??         90h
//         0050a8c2     NOP
//         0050a8c3     NOP
//         0050a8c4     NOP
//         0050a8c5     NOP
//         0050a8c6     NOP
//         0050a8c7     NOP
//         0050a8c8     NOP
//         0050a8c9     NOP
//         0050a8ca     NOP
//         0050a8cb     NOP
//         0050a8cc     NOP
//         0050a8cd     NOP
//         0050a8ce     NOP
//         0050a8cf     NOP
    return;
}

void TRIBE_Command::command_research(RGE_Static_Object* param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall command_research(TRIBE_Command * this, int param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050a963(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0050a943(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050a95f(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050a967(R)
//                               ?command_research@TRIBE_Command@@QAEXHHHH@Z                  XREF[1]:     research:0051529a(c)
//                               TRIBE_Command::command_research
//                              tcommand.cpp:978 (3)
//         0050a940     PUSH       EBX
//         0050a941     PUSH       ESI
//         0050a942     PUSH       EDI
//                              tcommand.cpp:988 (10)
//         0050a943     MOV        EDI,dword ptr [ESP + param_2]
//         0050a947     TEST       EDI,EDI
//         0050a949     MOV        EBX,this
//         0050a94b     JL         LAB_0050a99b
//                              tcommand.cpp:993 (14)
//         0050a94d     PUSH       0x10
//         0050a94f     PUSH       0x1
//         0050a951     CALL       calloc                                           undefined calloc()
//         0050a956     MOV        ESI,EAX
//         0050a958     ADD        ESP,0x8
//                              tcommand.cpp:994 (4)
//         0050a95b     TEST       ESI,ESI
//         0050a95d     JZ         LAB_0050a99b
//                              tcommand.cpp:1001 (8)
//         0050a95f     MOV        this,dword ptr [ESP + param_3]
//         0050a963     MOV        EAX,dword ptr [ESP + param_1]
//                              tcommand.cpp:1002 (4)
//         0050a967     MOV        EDX,dword ptr [ESP + param_4]
//                              tcommand.cpp:1006 (38)
//         0050a96b     PUSH       this
//         0050a96c     PUSH       EDI
//         0050a96d     MOV        dword ptr [ESI + 0x4],EDI
//         0050a970     MOV        byte ptr [ESI + 0x8],AL
//                              language.dll match for 0x65: "1"
//         0050a973     MOV        byte ptr [ESI],0x65
//         0050a976     MOV        word ptr [ESI + 0xa],this
//         0050a97a     MOV        dword ptr [ESI + 0xc],EDX
//         0050a97d     PUSH       EAX
//         0050a97e     MOV        EAX,[L]                                          = 00000000
//         0050a983     PUSH       s_______>SEND_CMD_RESEARCH2_(PLR=%               = "      >SEND CMD RESEARCH2 (PLR=%d,BLDG=%d,
//         0050a988     PUSH       EAX
//         0050a989     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050a98e     ADD        ESP,0x14
//                              tcommand.cpp:1008 (10)
//         0050a991     MOV        this,EBX
//         0050a993     PUSH       0x10
//         0050a995     PUSH       ESI
//         0050a996     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050a99b                                                 XREF[2]:     0050a94b(j), 0050a95d(j)
//                              tcommand.cpp:1009 (6)
//         0050a99b     POP        EDI
//         0050a99c     POP        ESI
//         0050a99d     POP        EBX
//         0050a99e     RET        0x10
//         0050a9a1     ??         90h
//         0050a9a2     NOP
//         0050a9a3     NOP
//         0050a9a4     NOP
//         0050a9a5     NOP
//         0050a9a6     NOP
//         0050a9a7     NOP
//         0050a9a8     NOP
//         0050a9a9     NOP
//         0050a9aa     NOP
//         0050a9ab     NOP
//         0050a9ac     NOP
//         0050a9ad     NOP
//         0050a9ae     NOP
//         0050a9af     NOP
    return;
}

void TRIBE_Command::command_research(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall command_research(TRIBE_Command * this, int param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050a963(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0050a943(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050a95f(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050a967(R)
//                               ?command_research@TRIBE_Command@@QAEXHHHH@Z                  XREF[1]:     research:0051529a(c)
//                               TRIBE_Command::command_research
//                              tcommand.cpp:978 (3)
//         0050a940     PUSH       EBX
//         0050a941     PUSH       ESI
//         0050a942     PUSH       EDI
//                              tcommand.cpp:988 (10)
//         0050a943     MOV        EDI,dword ptr [ESP + param_2]
//         0050a947     TEST       EDI,EDI
//         0050a949     MOV        EBX,this
//         0050a94b     JL         LAB_0050a99b
//                              tcommand.cpp:993 (14)
//         0050a94d     PUSH       0x10
//         0050a94f     PUSH       0x1
//         0050a951     CALL       calloc                                           undefined calloc()
//         0050a956     MOV        ESI,EAX
//         0050a958     ADD        ESP,0x8
//                              tcommand.cpp:994 (4)
//         0050a95b     TEST       ESI,ESI
//         0050a95d     JZ         LAB_0050a99b
//                              tcommand.cpp:1001 (8)
//         0050a95f     MOV        this,dword ptr [ESP + param_3]
//         0050a963     MOV        EAX,dword ptr [ESP + param_1]
//                              tcommand.cpp:1002 (4)
//         0050a967     MOV        EDX,dword ptr [ESP + param_4]
//                              tcommand.cpp:1006 (38)
//         0050a96b     PUSH       this
//         0050a96c     PUSH       EDI
//         0050a96d     MOV        dword ptr [ESI + 0x4],EDI
//         0050a970     MOV        byte ptr [ESI + 0x8],AL
//                              language.dll match for 0x65: "1"
//         0050a973     MOV        byte ptr [ESI],0x65
//         0050a976     MOV        word ptr [ESI + 0xa],this
//         0050a97a     MOV        dword ptr [ESI + 0xc],EDX
//         0050a97d     PUSH       EAX
//         0050a97e     MOV        EAX,[L]                                          = 00000000
//         0050a983     PUSH       s_______>SEND_CMD_RESEARCH2_(PLR=%               = "      >SEND CMD RESEARCH2 (PLR=%d,BLDG=%d,
//         0050a988     PUSH       EAX
//         0050a989     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050a98e     ADD        ESP,0x14
//                              tcommand.cpp:1008 (10)
//         0050a991     MOV        this,EBX
//         0050a993     PUSH       0x10
//         0050a995     PUSH       ESI
//         0050a996     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050a99b                                                 XREF[2]:     0050a94b(j), 0050a95d(j)
//                              tcommand.cpp:1009 (6)
//         0050a99b     POP        EDI
//         0050a99c     POP        ESI
//         0050a99d     POP        EBX
//         0050a99e     RET        0x10
//         0050a9a1     ??         90h
//         0050a9a2     NOP
//         0050a9a3     NOP
//         0050a9a4     NOP
//         0050a9a5     NOP
//         0050a9a6     NOP
//         0050a9a7     NOP
//         0050a9a8     NOP
//         0050a9a9     NOP
//         0050a9aa     NOP
//         0050a9ab     NOP
//         0050a9ac     NOP
//         0050a9ad     NOP
//         0050a9ae     NOP
//         0050a9af     NOP
    return;
}

void TRIBE_Command::command_build(RGE_Static_Object** param_1, short param_2, short param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall command_build(TRIBE_Command * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050aaf4(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     0050aa93(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050aaa5(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050aae6(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0050aade(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     0050aae2(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0050aaed(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050aa9b(W), 0050ab1a(R)
//                               ?command_build@TRIBE_Command@@QAEXHPAHHHMMH@Z                XREF[1]:     buildObject:0051516a(c)
//                               TRIBE_Command::command_build
//                              tcommand.cpp:1066 (3)
//         0050aa90     PUSH       this
//         0050aa91     PUSH       EBX
//         0050aa92     PUSH       EBP
//                              tcommand.cpp:1073 (27)
//         0050aa93     MOV        EBP,dword ptr [ESP + param_2]
//         0050aa97     PUSH       ESI
//         0050aa98     TEST       EBP,EBP
//         0050aa9a     PUSH       EDI
//         0050aa9b     MOV        dword ptr [ESP + local_4],this
//         0050aa9f     JZ         LAB_0050ab28
//         0050aaa5     MOV        EBX,dword ptr [ESP + param_3]
//         0050aaa9     CMP        EBX,0x1
//         0050aaac     JL         LAB_0050ab28
//                              tcommand.cpp:1077 (7)
//         0050aaae     LEA        EDI,[EBX*0x4 + 0x14]
//                              tcommand.cpp:1078 (13)
//         0050aab5     PUSH       EDI
//         0050aab6     PUSH       0x1
//         0050aab8     CALL       calloc                                           undefined calloc()
//         0050aabd     MOV        ESI,EAX
//         0050aabf     ADD        ESP,0x8
//                              tcommand.cpp:1083 (7)
//         0050aac2     TEST       ESI,ESI
//         0050aac4     LEA        EAX,[ESI + 0x14]
//         0050aac7     JZ         LAB_0050ab28
//                              tcommand.cpp:1087 (6)
//         0050aac9     TEST       EBX,EBX
//         0050aacb     JLE        LAB_0050aade
//         0050aacd     MOV        this,EBP
//                              tcommand.cpp:1110 (15)
//         0050aacf     MOV        EDX,EBX
//         0050aad1     SUB        this,EAX
//                               LAB_0050aad3                                                 XREF[1]:     0050aadc(j)
//         0050aad3     MOV        EBP,dword ptr [this->field0_0x0 + EAX*0x1]
//         0050aad6     MOV        dword ptr [EAX],EBP
//         0050aad8     ADD        EAX,0x4
//         0050aadb     DEC        EDX
//         0050aadc     JNZ        LAB_0050aad3
//                               LAB_0050aade                                                 XREF[1]:     0050aacb(j)
//                              tcommand.cpp:1100 (4)
//         0050aade     MOV        this,dword ptr [ESP + param_5]
//                              tcommand.cpp:1101 (11)
//         0050aae2     MOV        EDX,dword ptr [ESP + param_6]
//         0050aae6     MOV        EAX,dword ptr [ESP + param_4]
//         0050aaea     MOV        dword ptr [ESI + 0x4],this
//                              tcommand.cpp:1102 (7)
//         0050aaed     MOV        this,dword ptr [ESP + param_7]
//         0050aaf1     MOV        dword ptr [ESI + 0x8],EDX
//                              tcommand.cpp:1103 (20)
//         0050aaf4     MOV        DL,byte ptr [ESP + param_1]
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         0050aaf8     MOV        byte ptr [ESI],0x66
//         0050aafb     MOV        byte ptr [ESI + 0x1],BL
//         0050aafe     MOV        word ptr [ESI + 0xc],AX
//         0050ab02     MOV        dword ptr [ESI + 0x10],this
//         0050ab05     MOV        byte ptr [ESI + 0x2],DL
//                              tcommand.cpp:1107 (18)
//         0050ab08     PUSH       EAX
//         0050ab09     MOV        EAX,[L]                                          = 00000000
//         0050ab0e     PUSH       EBX
//         0050ab0f     PUSH       s_______>SEND_CMD_BUILD2_(CNT=%d,O               = "      >SEND CMD BUILD2 (CNT=%d,OBJ=%d)"
//         0050ab14     PUSH       EAX
//         0050ab15     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1109 (14)
//         0050ab1a     MOV        this,dword ptr [ESP + local_4]
//         0050ab1e     ADD        ESP,0x10
//         0050ab21     PUSH       EDI
//         0050ab22     PUSH       ESI
//         0050ab23     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ab28                                                 XREF[3]:     0050aa9f(j), 0050aaac(j),
//                                                                                                         0050aac7(j)
//                              tcommand.cpp:1110 (8)
//         0050ab28     POP        EDI
//         0050ab29     POP        ESI
//         0050ab2a     POP        EBP
//         0050ab2b     POP        EBX
//         0050ab2c     POP        this
//         0050ab2d     RET        0x1c
    return;
}

void TRIBE_Command::command_build(int param_1, int* param_2, int param_3, int param_4, float param_5, float param_6, int param_7) {
    /* TODO: Stub */
//                              void __thiscall command_build(TRIBE_Command * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050aaf4(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     0050aa93(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050aaa5(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0050aae6(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0050aade(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     0050aae2(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0050aaed(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050aa9b(W), 0050ab1a(R)
//                               ?command_build@TRIBE_Command@@QAEXHPAHHHMMH@Z                XREF[1]:     buildObject:0051516a(c)
//                               TRIBE_Command::command_build
//                              tcommand.cpp:1066 (3)
//         0050aa90     PUSH       this
//         0050aa91     PUSH       EBX
//         0050aa92     PUSH       EBP
//                              tcommand.cpp:1073 (27)
//         0050aa93     MOV        EBP,dword ptr [ESP + param_2]
//         0050aa97     PUSH       ESI
//         0050aa98     TEST       EBP,EBP
//         0050aa9a     PUSH       EDI
//         0050aa9b     MOV        dword ptr [ESP + local_4],this
//         0050aa9f     JZ         LAB_0050ab28
//         0050aaa5     MOV        EBX,dword ptr [ESP + param_3]
//         0050aaa9     CMP        EBX,0x1
//         0050aaac     JL         LAB_0050ab28
//                              tcommand.cpp:1077 (7)
//         0050aaae     LEA        EDI,[EBX*0x4 + 0x14]
//                              tcommand.cpp:1078 (13)
//         0050aab5     PUSH       EDI
//         0050aab6     PUSH       0x1
//         0050aab8     CALL       calloc                                           undefined calloc()
//         0050aabd     MOV        ESI,EAX
//         0050aabf     ADD        ESP,0x8
//                              tcommand.cpp:1083 (7)
//         0050aac2     TEST       ESI,ESI
//         0050aac4     LEA        EAX,[ESI + 0x14]
//         0050aac7     JZ         LAB_0050ab28
//                              tcommand.cpp:1087 (6)
//         0050aac9     TEST       EBX,EBX
//         0050aacb     JLE        LAB_0050aade
//         0050aacd     MOV        this,EBP
//                              tcommand.cpp:1110 (15)
//         0050aacf     MOV        EDX,EBX
//         0050aad1     SUB        this,EAX
//                               LAB_0050aad3                                                 XREF[1]:     0050aadc(j)
//         0050aad3     MOV        EBP,dword ptr [this->field0_0x0 + EAX*0x1]
//         0050aad6     MOV        dword ptr [EAX],EBP
//         0050aad8     ADD        EAX,0x4
//         0050aadb     DEC        EDX
//         0050aadc     JNZ        LAB_0050aad3
//                               LAB_0050aade                                                 XREF[1]:     0050aacb(j)
//                              tcommand.cpp:1100 (4)
//         0050aade     MOV        this,dword ptr [ESP + param_5]
//                              tcommand.cpp:1101 (11)
//         0050aae2     MOV        EDX,dword ptr [ESP + param_6]
//         0050aae6     MOV        EAX,dword ptr [ESP + param_4]
//         0050aaea     MOV        dword ptr [ESI + 0x4],this
//                              tcommand.cpp:1102 (7)
//         0050aaed     MOV        this,dword ptr [ESP + param_7]
//         0050aaf1     MOV        dword ptr [ESI + 0x8],EDX
//                              tcommand.cpp:1103 (20)
//         0050aaf4     MOV        DL,byte ptr [ESP + param_1]
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         0050aaf8     MOV        byte ptr [ESI],0x66
//         0050aafb     MOV        byte ptr [ESI + 0x1],BL
//         0050aafe     MOV        word ptr [ESI + 0xc],AX
//         0050ab02     MOV        dword ptr [ESI + 0x10],this
//         0050ab05     MOV        byte ptr [ESI + 0x2],DL
//                              tcommand.cpp:1107 (18)
//         0050ab08     PUSH       EAX
//         0050ab09     MOV        EAX,[L]                                          = 00000000
//         0050ab0e     PUSH       EBX
//         0050ab0f     PUSH       s_______>SEND_CMD_BUILD2_(CNT=%d,O               = "      >SEND CMD BUILD2 (CNT=%d,OBJ=%d)"
//         0050ab14     PUSH       EAX
//         0050ab15     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1109 (14)
//         0050ab1a     MOV        this,dword ptr [ESP + local_4]
//         0050ab1e     ADD        ESP,0x10
//         0050ab21     PUSH       EDI
//         0050ab22     PUSH       ESI
//         0050ab23     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ab28                                                 XREF[3]:     0050aa9f(j), 0050aaac(j),
//                                                                                                         0050aac7(j)
//                              tcommand.cpp:1110 (8)
//         0050ab28     POP        EDI
//         0050ab29     POP        ESI
//         0050ab2a     POP        EBP
//         0050ab2b     POP        EBX
//         0050ab2c     POP        this
//         0050ab2d     RET        0x1c
    return;
}

void TRIBE_Command::command_build_wall(RGE_Static_Object** param_1, short param_2, short param_3, long param_4, long param_5, long param_6, long param_7) {
    /* TODO: Stub */
//                              void __thiscall command_build_wall(TRIBE_Command * this, RGE_Static_
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     0050ab35(R), 0050ab9e(R)
//              short             Stack[0x8]:2   param_2                   XREF[3]:     0050ab45(R), 0050ab61(W), 0050ac4a(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     0050abbe(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0050abba(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0050abdd(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0050abf4(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0050ac0b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050ab39(W), 0050ac4e(R)
//                               ?command_build_wall@TRIBE_Command@@QAEXPAPAVRGE_Static_Obje  XREF[1]:     command_make_wall:005136fd(c)
//                               TRIBE_Command::command_build_wall
//                              tcommand.cpp:1116 (5)
//         0050ab30     PUSH       this
//         0050ab31     PUSH       EBX
//         0050ab32     PUSH       EBP
//         0050ab33     PUSH       ESI
//         0050ab34     PUSH       EDI
//                              tcommand.cpp:1123 (31)
//         0050ab35     MOV        EDI,dword ptr [ESP + param_1]
//         0050ab39     MOV        dword ptr [ESP + local_4],this
//         0050ab3d     TEST       EDI,EDI
//         0050ab3f     JZ         LAB_0050ac5c
//         0050ab45     MOV        BX,word ptr [ESP + param_2]
//         0050ab4a     CMP        BX,0x1
//         0050ab4e     JL         LAB_0050ac5c
//                              tcommand.cpp:1127 (10)
//         0050ab54     MOVSX      EBP,BX
//         0050ab57     LEA        EAX,[EBP*0x4 + 0x10]
//                              tcommand.cpp:1128 (17)
//         0050ab5e     PUSH       EAX
//         0050ab5f     PUSH       0x1
//         0050ab61     MOV        dword ptr [ESP + param_2],EAX
//         0050ab65     CALL       calloc                                           undefined calloc()
//         0050ab6a     MOV        ESI,EAX
//         0050ab6c     ADD        ESP,0x8
//                              tcommand.cpp:1133 (11)
//         0050ab6f     TEST       ESI,ESI
//         0050ab71     LEA        EAX,[ESI + 0x10]
//         0050ab74     JZ         LAB_0050ac5c
//                              tcommand.cpp:1137 (4)
//         0050ab7a     TEST       EBP,EBP
//         0050ab7c     JLE        LAB_0050aba2
//                              tcommand.cpp:1143 (2)
//         0050ab7e     MOV        EDX,EDI
//                              tcommand.cpp:1176 (18)
//         0050ab80     MOV        EDI,EBP
//         0050ab82     SUB        EDX,EAX
//                               LAB_0050ab84                                                 XREF[1]:     0050ab9c(j)
//         0050ab84     MOV        this,dword ptr [EDX + EAX*0x1]
//         0050ab87     TEST       this,this
//         0050ab89     JZ         LAB_0050ab92
//         0050ab8b     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050ab8e     MOV        dword ptr [EAX],this
//         0050ab90     JMP        LAB_0050ab98
//                               LAB_0050ab92                                                 XREF[1]:     0050ab89(j)
//                              tcommand.cpp:1143 (6)
//         0050ab92     MOV        dword ptr [EAX],0xffffffff
//                               LAB_0050ab98                                                 XREF[1]:     0050ab90(j)
//                              tcommand.cpp:1137 (10)
//         0050ab98     ADD        EAX,0x4
//         0050ab9b     DEC        EDI
//         0050ab9c     JNZ        LAB_0050ab84
//         0050ab9e     MOV        EDI,dword ptr [ESP + param_1]
//                               LAB_0050aba2                                                 XREF[1]:     0050ab7c(j)
//                              tcommand.cpp:1148 (3)
//         0050aba2     MOV        byte ptr [ESI],0x69
//                              tcommand.cpp:1149 (3)
//         0050aba5     MOV        byte ptr [ESI + 0x1],BL
//                              tcommand.cpp:1150 (18)
//         0050aba8     MOV        EAX,dword ptr [EDI]
//         0050abaa     TEST       EAX,EAX
//         0050abac     JZ         LAB_0050abb7
//         0050abae     MOV        EDX,dword ptr [EAX + 0xc]
//         0050abb1     MOVSX      EAX,word ptr [EDX + 0x4a]
//         0050abb5     JMP        LAB_0050abba
//                               LAB_0050abb7                                                 XREF[1]:     0050abac(j)
//         0050abb7     OR         EAX,0xffffffff
//                               LAB_0050abba                                                 XREF[1]:     0050abb5(j)
//                              tcommand.cpp:1155 (22)
//         0050abba     MOV        EBX,dword ptr [ESP + param_4]
//         0050abbe     MOV        DI,word ptr [ESP + param_3]
//         0050abc3     TEST       EBX,EBX
//         0050abc5     MOV        byte ptr [ESI + 0x2],AL
//         0050abc8     MOV        word ptr [ESI + 0x8],DI
//         0050abcc     JGE        LAB_0050abd0
//         0050abce     XOR        EBX,EBX
//                               LAB_0050abd0                                                 XREF[1]:     0050abcc(j)
//                              tcommand.cpp:1156 (13)
//         0050abd0     CMP        EBX,0xff
//         0050abd6     JLE        LAB_0050abdd
//         0050abd8     MOV        EBX,0xff
//                               LAB_0050abdd                                                 XREF[1]:     0050abd6(j)
//                              tcommand.cpp:1157 (10)
//         0050abdd     MOV        EDX,dword ptr [ESP + param_5]
//         0050abe1     TEST       EDX,EDX
//         0050abe3     JGE        LAB_0050abe7
//         0050abe5     XOR        EDX,EDX
//                               LAB_0050abe7                                                 XREF[1]:     0050abe3(j)
//                              tcommand.cpp:1158 (13)
//         0050abe7     CMP        EDX,0xff
//         0050abed     JLE        LAB_0050abf4
//         0050abef     MOV        EDX,0xff
//                               LAB_0050abf4                                                 XREF[1]:     0050abed(j)
//                              tcommand.cpp:1160 (10)
//         0050abf4     MOV        this,dword ptr [ESP + param_6]
//         0050abf8     TEST       this,this
//         0050abfa     JGE        LAB_0050abfe
//         0050abfc     XOR        this,this
//                               LAB_0050abfe                                                 XREF[1]:     0050abfa(j)
//                              tcommand.cpp:1161 (13)
//         0050abfe     CMP        this,0xff
//         0050ac04     JLE        LAB_0050ac0b
//         0050ac06     MOV        this,0xff
//                               LAB_0050ac0b                                                 XREF[1]:     0050ac04(j)
//                              tcommand.cpp:1162 (10)
//         0050ac0b     MOV        EAX,dword ptr [ESP + param_7]
//         0050ac0f     TEST       EAX,EAX
//         0050ac11     JGE        LAB_0050ac15
//         0050ac13     XOR        EAX,EAX
//                               LAB_0050ac15                                                 XREF[1]:     0050ac11(j)
//                              tcommand.cpp:1163 (12)
//         0050ac15     CMP        EAX,0xff
//         0050ac1a     JLE        LAB_0050ac21
//         0050ac1c     MOV        EAX,0xff
//                               LAB_0050ac21                                                 XREF[1]:     0050ac1a(j)
//                              tcommand.cpp:1168 (6)
//         0050ac21     MOV        byte ptr [ESI + 0x6],AL
//         0050ac24     MOV        byte ptr [ESI + 0x3],BL
//                              tcommand.cpp:1172 (35)
//         0050ac27     MOVSX      EAX,DI
//         0050ac2a     MOV        byte ptr [ESI + 0x4],DL
//         0050ac2d     MOV        byte ptr [ESI + 0x5],this
//         0050ac30     MOV        dword ptr [ESI + 0xc],0xffffffff
//         0050ac37     MOV        this,dword ptr [L]                               = 00000000
//         0050ac3d     PUSH       EAX
//         0050ac3e     PUSH       EBP
//         0050ac3f     PUSH       s_______>SEND_CMD_BLD_WALL_(CNT=%d               = "      >SEND CMD BLD WALL (CNT=%d,OBJ=%d)"
//         0050ac44     PUSH       this
//         0050ac45     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1175 (18)
//         0050ac4a     MOV        EDX,dword ptr [ESP + param_2]
//         0050ac4e     MOV        this,dword ptr [ESP + local_4]
//         0050ac52     ADD        ESP,0x10
//         0050ac55     PUSH       EDX
//         0050ac56     PUSH       ESI
//         0050ac57     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ac5c                                                 XREF[3]:     0050ab3f(j), 0050ab4e(j),
//                                                                                                         0050ab74(j)
//                              tcommand.cpp:1176 (8)
//         0050ac5c     POP        EDI
//         0050ac5d     POP        ESI
//         0050ac5e     POP        EBP
//         0050ac5f     POP        EBX
//         0050ac60     POP        this
//         0050ac61     RET        0x1c
//         0050ac64     ??         90h
//         0050ac65     NOP
//         0050ac66     NOP
//         0050ac67     NOP
//         0050ac68     NOP
//         0050ac69     NOP
//         0050ac6a     NOP
//         0050ac6b     NOP
//         0050ac6c     NOP
//         0050ac6d     NOP
//         0050ac6e     NOP
//         0050ac6f     NOP
    return;
}

void TRIBE_Command::command_explore(int param_1, int* param_2, int param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall command_explore(TRIBE_Command * this, int param_1, i
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050acba(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     0050ac75(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050ac81(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0050acbe(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0050acc2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050ac79(W), 0050ace6(R)
//                               ?command_explore@TRIBE_Command@@QAEXHPAHHMM@Z
//                               TRIBE_Command::command_explore
//                              tcommand.cpp:1182 (5)
//         0050ac70     PUSH       this
//         0050ac71     PUSH       EBX
//         0050ac72     PUSH       EBP
//         0050ac73     PUSH       ESI
//         0050ac74     PUSH       EDI
//                              tcommand.cpp:1189 (21)
//         0050ac75     MOV        EDI,dword ptr [ESP + param_2]
//         0050ac79     MOV        dword ptr [ESP + local_4],this
//         0050ac7d     TEST       EDI,EDI
//         0050ac7f     JZ         LAB_0050acf4
//         0050ac81     MOV        EBX,dword ptr [ESP + param_3]
//         0050ac85     CMP        EBX,0x1
//         0050ac88     JL         LAB_0050acf4
//                              tcommand.cpp:1193 (7)
//         0050ac8a     LEA        EBP,[EBX*0x4 + 0xc]
//                              tcommand.cpp:1194 (13)
//         0050ac91     PUSH       EBP
//         0050ac92     PUSH       0x1
//         0050ac94     CALL       calloc                                           undefined calloc()
//         0050ac99     MOV        ESI,EAX
//         0050ac9b     ADD        ESP,0x8
//                              tcommand.cpp:1199 (7)
//         0050ac9e     TEST       ESI,ESI
//         0050aca0     LEA        EAX,[ESI + 0xc]
//         0050aca3     JZ         LAB_0050acf4
//                              tcommand.cpp:1203 (6)
//         0050aca5     TEST       EBX,EBX
//         0050aca7     JLE        LAB_0050acba
//         0050aca9     MOV        this,EDI
//                              tcommand.cpp:1221 (15)
//         0050acab     MOV        EDX,EBX
//         0050acad     SUB        this,EAX
//                               LAB_0050acaf                                                 XREF[1]:     0050acb8(j)
//         0050acaf     MOV        EDI,dword ptr [this->field0_0x0 + EAX*0x1]
//         0050acb2     MOV        dword ptr [EAX],EDI
//         0050acb4     ADD        EAX,0x4
//         0050acb7     DEC        EDX
//         0050acb8     JNZ        LAB_0050acaf
//                               LAB_0050acba                                                 XREF[1]:     0050aca7(j)
//                              tcommand.cpp:1211 (4)
//         0050acba     MOV        AL,byte ptr [ESP + param_1]
//                              tcommand.cpp:1212 (4)
//         0050acbe     MOV        this,dword ptr [ESP + param_4]
//                              tcommand.cpp:1213 (19)
//         0050acc2     MOV        EDX,dword ptr [ESP + param_5]
//                              language.dll match for 0x68: "Arial"
//         0050acc6     MOV        byte ptr [ESI],0x68
//         0050acc9     MOV        byte ptr [ESI + 0x1],BL
//         0050accc     MOV        byte ptr [ESI + 0x2],AL
//         0050accf     MOV        dword ptr [ESI + 0x4],this
//         0050acd2     MOV        dword ptr [ESI + 0x8],EDX
//                              tcommand.cpp:1217 (17)
//         0050acd5     MOV        EAX,[L]                                          = 00000000
//         0050acda     PUSH       EBX
//         0050acdb     PUSH       s_______>SEND_CMD_EXPLORE_(CNT=%d)               = "      >SEND CMD EXPLORE (CNT=%d)"
//         0050ace0     PUSH       EAX
//         0050ace1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1220 (14)
//         0050ace6     MOV        this,dword ptr [ESP + local_4]
//         0050acea     ADD        ESP,0xc
//         0050aced     PUSH       EBP
//         0050acee     PUSH       ESI
//         0050acef     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050acf4                                                 XREF[3]:     0050ac7f(j), 0050ac88(j),
//                                                                                                         0050aca3(j)
//                              tcommand.cpp:1221 (8)
//         0050acf4     POP        EDI
//         0050acf5     POP        ESI
//         0050acf6     POP        EBP
//         0050acf7     POP        EBX
//         0050acf8     POP        this
//         0050acf9     RET        0x14
//         0050acfc     ??         90h
//         0050acfd     NOP
//         0050acfe     NOP
//         0050acff     NOP
    return;
}

void TRIBE_Command::command_allied_victory(short param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall command_allied_victory(TRIBE_Command * this, short p
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050ad1a(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050ad16(R)
//                               ?command_allied_victory@TRIBE_Command@@QAEXFE@Z              XREF[4]:     action:0043d932(c),
//                               TRIBE_Command::command_allied_victory                                     processAICommand:004e6784(c),
//                                                                                                         processAICommand:004e67ab(c),
//                                                                                                         processAICommand:004e67d8(c)
//                              tcommand.cpp:1227 (2)
//         0050ad00     PUSH       ESI
//         0050ad01     PUSH       EDI
//                              tcommand.cpp:1234 (16)
//         0050ad02     PUSH       0x10
//         0050ad04     MOV        EDI,this
//         0050ad06     PUSH       0x1
//         0050ad08     CALL       calloc                                           undefined calloc()
//         0050ad0d     MOV        ESI,EAX
//         0050ad0f     ADD        ESP,0x8
//                              tcommand.cpp:1236 (4)
//         0050ad12     TEST       ESI,ESI
//         0050ad14     JZ         LAB_0050ad62
//                              tcommand.cpp:1239 (18)
//         0050ad16     MOV        EAX,dword ptr [ESP + param_2]
//         0050ad1a     MOV        this,word ptr [ESP + param_1]
//         0050ad1f     XOR        DX,DX
//         0050ad22     MOV        word ptr [ESI + 0x2],this
//         0050ad26     MOV        DL,AL
//                              tcommand.cpp:1245 (48)
//         0050ad28     AND        EAX,0xff
//         0050ad2d     PUSH       EAX
//         0050ad2e     MOV        word ptr [ESI + 0x4],DX
//         0050ad32     MOVSX      EAX,this
//         0050ad35     MOV        dword ptr [ESI + 0x8],0x0
//                              language.dll match for 0x67: "Comic Sans MS"
//         0050ad3c     MOV        byte ptr [ESI],0x67
//         0050ad3f     MOV        byte ptr [ESI + 0x1],0x5
//         0050ad43     MOV        this,dword ptr [L]                               = 00000000
//         0050ad49     PUSH       EAX
//         0050ad4a     PUSH       s_______>SEND_CMD_ALLIED_VIC_(PLR=               = "      >SEND CMD ALLIED VIC (PLR=%d,FLAG=%d)"
//         0050ad4f     PUSH       this
//         0050ad50     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050ad55     ADD        ESP,0x10
//                              tcommand.cpp:1248 (10)
//         0050ad58     MOV        this,EDI
//         0050ad5a     PUSH       0x10
//         0050ad5c     PUSH       ESI
//         0050ad5d     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ad62                                                 XREF[1]:     0050ad14(j)
//                              tcommand.cpp:1250 (5)
//         0050ad62     POP        EDI
//         0050ad63     POP        ESI
//         0050ad64     RET        0x8
//         0050ad67     ??         90h
//         0050ad68     NOP
//         0050ad69     NOP
//         0050ad6a     NOP
//         0050ad6b     NOP
//         0050ad6c     NOP
//         0050ad6d     NOP
//         0050ad6e     NOP
//         0050ad6f     NOP
    return;
}

void TRIBE_Command::command_relation(short param_1, short param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall command_relation(TRIBE_Command * this, short param_1
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[3]:     0050ad8b(R), 0050ad99(W), 0050ada1(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0050ad90(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     0050ad86(R)
//                               ?command_relation@TRIBE_Command@@QAEXFFF@Z                   XREF[2]:     action:0043d9dc(c),
//                               TRIBE_Command::command_relation                                           setDiplomaticStance:005153c5(c)
//                              tcommand.cpp:1256 (2)
//         0050ad70     PUSH       EBX
//         0050ad71     PUSH       ESI
//                              tcommand.cpp:1264 (16)
//         0050ad72     PUSH       0x10
//         0050ad74     MOV        EBX,this
//         0050ad76     PUSH       0x1
//         0050ad78     CALL       calloc                                           undefined calloc()
//         0050ad7d     MOV        ESI,EAX
//         0050ad7f     ADD        ESP,0x8
//                              tcommand.cpp:1266 (4)
//         0050ad82     TEST       ESI,ESI
//         0050ad84     JZ         LAB_0050adde
//                              tcommand.cpp:1270 (31)
//         0050ad86     MOV        DX,word ptr [ESP + param_3]
//         0050ad8b     MOV        AX,word ptr [ESP + param_1]
//         0050ad90     MOV        this,word ptr [ESP + param_2]
//         0050ad95     PUSH       EDI
//         0050ad96     MOVSX      EDI,DX
//         0050ad99     MOV        dword ptr [ESP + param_1],EDI
//         0050ad9d     MOV        word ptr [ESI + 0x4],this
//         0050ada1     FILD       dword ptr [ESP + param_1]
//                              tcommand.cpp:1271 (4)
//         0050ada5     MOV        word ptr [ESI + 0xc],DX
//                              tcommand.cpp:1276 (42)
//         0050ada9     PUSH       EDI
//         0050adaa     MOVSX      this,this
//         0050adad     FSTP       float ptr [ESI + 0x8]
//         0050adb0     MOVSX      EDX,AX
//         0050adb3     MOV        word ptr [ESI + 0x2],AX
//                              language.dll match for 0x67: "Comic Sans MS"
//         0050adb7     MOV        byte ptr [ESI],0x67
//         0050adba     MOV        byte ptr [ESI + 0x1],0x0
//         0050adbe     MOV        EAX,[L]                                          = 00000000
//         0050adc3     PUSH       this
//         0050adc4     PUSH       EDX
//         0050adc5     PUSH       s_______>SEND_CMD_RELATION_(PLR=%d               = "      >SEND CMD RELATION (PLR=%d,TAR=%d,RE
//         0050adca     PUSH       EAX
//         0050adcb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050add0     ADD        ESP,0x14
//                              tcommand.cpp:1279 (11)
//         0050add3     MOV        this,EBX
//         0050add5     PUSH       0x10
//         0050add7     PUSH       ESI
//         0050add8     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//         0050addd     POP        EDI
//                               LAB_0050adde                                                 XREF[1]:     0050ad84(j)
//                              tcommand.cpp:1281 (5)
//         0050adde     POP        ESI
//         0050addf     POP        EBX
//         0050ade0     RET        0xc
//         0050ade3     ??         90h
//         0050ade4     NOP
//         0050ade5     NOP
//         0050ade6     NOP
//         0050ade7     NOP
//         0050ade8     NOP
//         0050ade9     NOP
//         0050adea     NOP
//         0050adeb     NOP
//         0050adec     NOP
//         0050aded     NOP
//         0050adee     NOP
//         0050adef     NOP
    return;
}

void TRIBE_Command::command_game_speed(float param_1) {
    /* TODO: Stub */
//                              void __thiscall command_game_speed(TRIBE_Command * this, float param
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0050ae06(R)
//                               ?command_game_speed@TRIBE_Command@@QAEXM@Z                   XREF[2]:     action:0043c504(c),
//                               TRIBE_Command::command_game_speed                                         command_game_speed:0049c510(c)
//                              tcommand.cpp:1287 (2)
//         0050adf0     PUSH       ESI
//         0050adf1     PUSH       EDI
//                              tcommand.cpp:1294 (16)
//         0050adf2     PUSH       0x10
//         0050adf4     MOV        EDI,this
//         0050adf6     PUSH       0x1
//         0050adf8     CALL       calloc                                           undefined calloc()
//         0050adfd     MOV        ESI,EAX
//         0050adff     ADD        ESP,0x8
//                              tcommand.cpp:1296 (4)
//         0050ae02     TEST       ESI,ESI
//         0050ae04     JZ         LAB_0050ae32
//                              tcommand.cpp:1298 (4)
//         0050ae06     MOV        EAX,dword ptr [ESP + param_1]
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1299 (6)
//         0050ae0a     MOV        byte ptr [ESI],0x67
//         0050ae0d     MOV        dword ptr [ESI + 0x8],EAX
//                              tcommand.cpp:1300 (4)
//         0050ae10     MOV        byte ptr [ESI + 0x1],0x1
//                              tcommand.cpp:1303 (20)
//         0050ae14     MOV        this,dword ptr [L]                               = 00000000
//         0050ae1a     PUSH       s_______>SEND_CMD_GAME_SPD                       = "      >SEND CMD GAME SPD"
//         0050ae1f     PUSH       this
//         0050ae20     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050ae25     ADD        ESP,0x8
//                              tcommand.cpp:1306 (10)
//         0050ae28     MOV        this,EDI
//         0050ae2a     PUSH       0x10
//         0050ae2c     PUSH       ESI
//         0050ae2d     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ae32                                                 XREF[1]:     0050ae04(j)
//                              tcommand.cpp:1308 (5)
//         0050ae32     POP        EDI
//         0050ae33     POP        ESI
//         0050ae34     RET        0x4
//         0050ae37     ??         90h
//         0050ae38     NOP
//         0050ae39     NOP
//         0050ae3a     NOP
//         0050ae3b     NOP
//         0050ae3c     NOP
//         0050ae3d     NOP
//         0050ae3e     NOP
//         0050ae3f     NOP
    return;
}

void TRIBE_Command::command_save_game() {
    /* TODO: Stub */
//                              void __thiscall command_save_game(TRIBE_Command * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//                               ?command_save_game@TRIBE_Command@@QAEXXZ                     XREF[1]:     action_user_command:00529c52(c)
//                               TRIBE_Command::command_save_game
//                              tcommand.cpp:1314 (2)
//         0050ae40     PUSH       ESI
//         0050ae41     PUSH       EDI
//                              tcommand.cpp:1321 (16)
//         0050ae42     PUSH       0x10
//         0050ae44     MOV        EDI,this
//         0050ae46     PUSH       0x1
//         0050ae48     CALL       calloc                                           undefined calloc()
//         0050ae4d     MOV        ESI,EAX
//         0050ae4f     ADD        ESP,0x8
//                              tcommand.cpp:1323 (4)
//         0050ae52     TEST       ESI,ESI
//         0050ae54     JZ         LAB_0050ae7a
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1325 (3)
//         0050ae56     MOV        byte ptr [ESI],0x67
//                              tcommand.cpp:1326 (4)
//         0050ae59     MOV        byte ptr [ESI + 0x1],0x8
//                              tcommand.cpp:1329 (19)
//         0050ae5d     MOV        EAX,[L]                                          = 00000000
//         0050ae62     PUSH       s_______>SEND_CMD_SAVEGAME                       = "      >SEND CMD SAVEGAME"
//         0050ae67     PUSH       EAX
//         0050ae68     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050ae6d     ADD        ESP,0x8
//                              tcommand.cpp:1332 (10)
//         0050ae70     MOV        this,EDI
//         0050ae72     PUSH       0x10
//         0050ae74     PUSH       ESI
//         0050ae75     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050ae7a                                                 XREF[1]:     0050ae54(j)
//                              tcommand.cpp:1334 (3)
//         0050ae7a     POP        EDI
//         0050ae7b     POP        ESI
//         0050ae7c     RET
//         0050ae7d     ??         90h
//         0050ae7e     NOP
//         0050ae7f     NOP
    return;
}

void TRIBE_Command::command_inventory(short param_1, short param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall command_inventory(TRIBE_Command * this, short param_
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050ae9f(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0050ae96(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0050ae9b(R)
//                               ?command_inventory@TRIBE_Command@@QAEXFFM@Z
//                               TRIBE_Command::command_inventory
//                              tcommand.cpp:1340 (2)
//         0050ae80     PUSH       ESI
//         0050ae81     PUSH       EDI
//                              tcommand.cpp:1347 (16)
//         0050ae82     PUSH       0x10
//         0050ae84     MOV        EDI,this
//         0050ae86     PUSH       0x1
//         0050ae88     CALL       calloc                                           undefined calloc()
//         0050ae8d     MOV        ESI,EAX
//         0050ae8f     ADD        ESP,0x8
//                              tcommand.cpp:1349 (4)
//         0050ae92     TEST       ESI,ESI
//         0050ae94     JZ         LAB_0050aedb
//                              tcommand.cpp:1352 (5)
//         0050ae96     MOV        this,word ptr [ESP + param_2]
//                              tcommand.cpp:1353 (20)
//         0050ae9b     MOV        EDX,dword ptr [ESP + param_3]
//         0050ae9f     MOV        AX,word ptr [ESP + param_1]
//         0050aea4     MOV        word ptr [ESI + 0x4],this
//         0050aea8     MOV        dword ptr [ESI + 0x8],EDX
//         0050aeab     MOV        word ptr [ESI + 0x2],AX
//                              tcommand.cpp:1358 (34)
//         0050aeaf     MOVSX      this,this
//         0050aeb2     MOVSX      EDX,AX
//                              language.dll match for 0x67: "Comic Sans MS"
//         0050aeb5     MOV        byte ptr [ESI],0x67
//         0050aeb8     MOV        byte ptr [ESI + 0x1],0x2
//         0050aebc     MOV        EAX,[L]                                          = 00000000
//         0050aec1     PUSH       this
//         0050aec2     PUSH       EDX
//         0050aec3     PUSH       s_______>SEND_CMD_INV_(PLR=%d,INV=               = "      >SEND CMD INV (PLR=%d,INV=%d)"
//         0050aec8     PUSH       EAX
//         0050aec9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050aece     ADD        ESP,0x10
//                              tcommand.cpp:1361 (10)
//         0050aed1     MOV        this,EDI
//         0050aed3     PUSH       0x10
//         0050aed5     PUSH       ESI
//         0050aed6     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050aedb                                                 XREF[1]:     0050ae94(j)
//                              tcommand.cpp:1363 (5)
//         0050aedb     POP        EDI
//         0050aedc     POP        ESI
//         0050aedd     RET        0xc
    return;
}

void TRIBE_Command::command_upgrade_town(short param_1) {
    /* TODO: Stub */
//                              void __thiscall command_upgrade_town(TRIBE_Command * this, short par
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050aef6(R)
//                               ?command_upgrade_town@TRIBE_Command@@QAEXF@Z
//                               TRIBE_Command::command_upgrade_town
//                              tcommand.cpp:1369 (2)
//         0050aee0     PUSH       ESI
//         0050aee1     PUSH       EDI
//                              tcommand.cpp:1376 (16)
//         0050aee2     PUSH       0x10
//         0050aee4     MOV        EDI,this
//         0050aee6     PUSH       0x1
//         0050aee8     CALL       calloc                                           undefined calloc()
//         0050aeed     MOV        ESI,EAX
//         0050aeef     ADD        ESP,0x8
//                              tcommand.cpp:1378 (4)
//         0050aef2     TEST       ESI,ESI
//         0050aef4     JZ         LAB_0050af24
//                              tcommand.cpp:1380 (5)
//         0050aef6     MOV        AX,word ptr [ESP + param_1]
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1381 (7)
//         0050aefb     MOV        byte ptr [ESI],0x67
//         0050aefe     MOV        word ptr [ESI + 0x2],AX
//                              tcommand.cpp:1382 (4)
//         0050af02     MOV        byte ptr [ESI + 0x1],0x3
//                              tcommand.cpp:1385 (20)
//         0050af06     MOV        this,dword ptr [L]                               = 00000000
//         0050af0c     PUSH       s_______>SEND_CMD_UPG_TOWN                       = "      >SEND CMD UPG TOWN"
//         0050af11     PUSH       this
//         0050af12     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050af17     ADD        ESP,0x8
//                              tcommand.cpp:1388 (10)
//         0050af1a     MOV        this,EDI
//         0050af1c     PUSH       0x10
//         0050af1e     PUSH       ESI
//         0050af1f     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050af24                                                 XREF[1]:     0050aef4(j)
//                              tcommand.cpp:1390 (5)
//         0050af24     POP        EDI
//         0050af25     POP        ESI
//         0050af26     RET        0x4
//         0050af29     ??         90h
//         0050af2a     NOP
//         0050af2b     NOP
//         0050af2c     NOP
//         0050af2d     NOP
//         0050af2e     NOP
//         0050af2f     NOP
    return;
}

void TRIBE_Command::command_quick_build(short param_1) {
    /* TODO: Stub */
//                              void __thiscall command_quick_build(TRIBE_Command * this, short para
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050af46(R)
//                               ?command_quick_build@TRIBE_Command@@QAEXF@Z                  XREF[2]:     command_quick_build:0049caaf(c),
//                               TRIBE_Command::command_quick_build                                        processCheatCode:005283c0(c)
//                              tcommand.cpp:1396 (2)
//         0050af30     PUSH       ESI
//         0050af31     PUSH       EDI
//                              tcommand.cpp:1403 (16)
//         0050af32     PUSH       0x10
//         0050af34     MOV        EDI,this
//         0050af36     PUSH       0x1
//         0050af38     CALL       calloc                                           undefined calloc()
//         0050af3d     MOV        ESI,EAX
//         0050af3f     ADD        ESP,0x8
//                              tcommand.cpp:1405 (4)
//         0050af42     TEST       ESI,ESI
//         0050af44     JZ         LAB_0050af74
//                              tcommand.cpp:1407 (5)
//         0050af46     MOV        AX,word ptr [ESP + param_1]
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1408 (7)
//         0050af4b     MOV        byte ptr [ESI],0x67
//         0050af4e     MOV        word ptr [ESI + 0x2],AX
//                              tcommand.cpp:1409 (4)
//         0050af52     MOV        byte ptr [ESI + 0x1],0x4
//                              tcommand.cpp:1412 (20)
//         0050af56     MOV        this,dword ptr [L]                               = 00000000
//         0050af5c     PUSH       s_______>SEND_CMD_QUICKBLD                       = "      >SEND CMD QUICKBLD"
//         0050af61     PUSH       this
//         0050af62     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050af67     ADD        ESP,0x8
//                              tcommand.cpp:1415 (10)
//         0050af6a     MOV        this,EDI
//         0050af6c     PUSH       0x10
//         0050af6e     PUSH       ESI
//         0050af6f     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050af74                                                 XREF[1]:     0050af44(j)
//                              tcommand.cpp:1417 (5)
//         0050af74     POP        EDI
//         0050af75     POP        ESI
//         0050af76     RET        0x4
//         0050af79     ??         90h
//         0050af7a     NOP
//         0050af7b     NOP
//         0050af7c     NOP
//         0050af7d     NOP
//         0050af7e     NOP
//         0050af7f     NOP
    return;
}

void TRIBE_Command::command_shared_los(short param_1) {
    /* TODO: Stub */
//                              void __thiscall command_shared_los(TRIBE_Command * this, short param
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050af96(R)
//                               ?command_shared_los@TRIBE_Command@@QAEXF@Z
//                               TRIBE_Command::command_shared_los
//                              tcommand.cpp:1423 (2)
//         0050af80     PUSH       ESI
//         0050af81     PUSH       EDI
//                              tcommand.cpp:1430 (16)
//         0050af82     PUSH       0x10
//         0050af84     MOV        EDI,this
//         0050af86     PUSH       0x1
//         0050af88     CALL       calloc                                           undefined calloc()
//         0050af8d     MOV        ESI,EAX
//         0050af8f     ADD        ESP,0x8
//                              tcommand.cpp:1432 (4)
//         0050af92     TEST       ESI,ESI
//         0050af94     JZ         LAB_0050afc4
//                              tcommand.cpp:1434 (5)
//         0050af96     MOV        AX,word ptr [ESP + param_1]
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1435 (7)
//         0050af9b     MOV        byte ptr [ESI],0x67
//         0050af9e     MOV        word ptr [ESI + 0x2],AX
//                              tcommand.cpp:1436 (4)
//         0050afa2     MOV        byte ptr [ESI + 0x1],0x7
//                              tcommand.cpp:1439 (20)
//         0050afa6     MOV        this,dword ptr [L]                               = 00000000
//         0050afac     PUSH       s_______>SEND_CMD_SHAREDLOS                      = "      >SEND CMD SHAREDLOS"
//         0050afb1     PUSH       this
//         0050afb2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050afb7     ADD        ESP,0x8
//                              tcommand.cpp:1442 (10)
//         0050afba     MOV        this,EDI
//         0050afbc     PUSH       0x10
//         0050afbe     PUSH       ESI
//         0050afbf     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050afc4                                                 XREF[1]:     0050af94(j)
//                              tcommand.cpp:1444 (5)
//         0050afc4     POP        EDI
//         0050afc5     POP        ESI
//         0050afc6     RET        0x4
//         0050afc9     ??         90h
//         0050afca     NOP
//         0050afcb     NOP
//         0050afcc     NOP
//         0050afcd     NOP
//         0050afce     NOP
//         0050afcf     NOP
    return;
}

void TRIBE_Command::command_cancel_build(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall command_cancel_build(TRIBE_Command * this, RGE_Stati
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050afe6(R)
//                               ?command_cancel_build@TRIBE_Command@@QAEXPAVRGE_Static_Obje  XREF[2]:     command_building_cancel:0051377e(c
//                               TRIBE_Command::command_cancel_build                                       command_delete_object:005137b4(c)
//                              tcommand.cpp:1450 (2)
//         0050afd0     PUSH       ESI
//         0050afd1     PUSH       EDI
//                              tcommand.cpp:1457 (16)
//         0050afd2     PUSH       0x8
//         0050afd4     MOV        EDI,this
//         0050afd6     PUSH       0x1
//         0050afd8     CALL       calloc                                           undefined calloc()
//         0050afdd     MOV        ESI,EAX
//         0050afdf     ADD        ESP,0x8
//                              tcommand.cpp:1459 (4)
//         0050afe2     TEST       ESI,ESI
//         0050afe4     JZ         LAB_0050b011
//                              tcommand.cpp:1462 (7)
//         0050afe6     MOV        EAX,dword ptr [ESP + param_1]
//         0050afea     MOV        byte ptr [ESI],0x6a
//                              tcommand.cpp:1466 (26)
//         0050afed     PUSH       s_______>SEND_CMD_CANCELBLD                      = "      >SEND CMD CANCELBLD"
//         0050aff2     MOV        this,dword ptr [EAX + 0x4]
//         0050aff5     MOV        dword ptr [ESI + 0x4],this
//         0050aff8     MOV        EDX,dword ptr [L]                                = 00000000
//         0050affe     PUSH       EDX
//         0050afff     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b004     ADD        ESP,0x8
//                              tcommand.cpp:1469 (10)
//         0050b007     MOV        this,EDI
//         0050b009     PUSH       0x8
//         0050b00b     PUSH       ESI
//         0050b00c     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b011                                                 XREF[1]:     0050afe4(j)
//                              tcommand.cpp:1471 (5)
//         0050b011     POP        EDI
//         0050b012     POP        ESI
//         0050b013     RET        0x4
//         0050b016     ??         90h
//         0050b017     NOP
//         0050b018     NOP
//         0050b019     NOP
//         0050b01a     NOP
//         0050b01b     NOP
//         0050b01c     NOP
//         0050b01d     NOP
//         0050b01e     NOP
//         0050b01f     NOP
    return;
}

void TRIBE_Command::command_attack_ground(RGE_Static_Object** param_1, short param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall command_attack_ground(TRIBE_Command * this, RGE_Stat
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050b023(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     0050b035(R), 0050b082(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0050b086(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0050b08a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b02b(W), 0050b0ac(R)
//                               ?command_attack_ground@TRIBE_Command@@QAEXPAPAVRGE_Static_O  XREF[1]:     command_attack_ground:005138ab(c)
//                               TRIBE_Command::command_attack_ground
//                              tcommand.cpp:1477 (3)
//         0050b020     PUSH       this
//         0050b021     PUSH       EBX
//         0050b022     PUSH       EBP
//                              tcommand.cpp:1484 (29)
//         0050b023     MOV        EBP,dword ptr [ESP + param_1]
//         0050b027     PUSH       ESI
//         0050b028     TEST       EBP,EBP
//         0050b02a     PUSH       EDI
//         0050b02b     MOV        dword ptr [ESP + local_4],this
//         0050b02f     JZ         LAB_0050b0ba
//         0050b035     MOV        AX,word ptr [ESP + param_2]
//         0050b03a     CMP        AX,0x1
//         0050b03e     JL         LAB_0050b0ba
//                              tcommand.cpp:1488 (10)
//         0050b040     MOVSX      EDI,AX
//         0050b043     LEA        EBX,[EDI*0x4 + 0xc]
//                              tcommand.cpp:1489 (13)
//         0050b04a     PUSH       EBX
//         0050b04b     PUSH       0x1
//         0050b04d     CALL       calloc                                           undefined calloc()
//         0050b052     MOV        ESI,EAX
//         0050b054     ADD        ESP,0x8
//                              tcommand.cpp:1494 (7)
//         0050b057     TEST       ESI,ESI
//         0050b059     LEA        EAX,[ESI + 0xc]
//         0050b05c     JZ         LAB_0050b0ba
//                              tcommand.cpp:1498 (4)
//         0050b05e     TEST       EDI,EDI
//         0050b060     JLE        LAB_0050b082
//                              tcommand.cpp:1504 (2)
//         0050b062     MOV        EDX,EBP
//                              tcommand.cpp:1519 (18)
//         0050b064     MOV        EBP,EDI
//         0050b066     SUB        EDX,EAX
//                               LAB_0050b068                                                 XREF[1]:     0050b080(j)
//         0050b068     MOV        this,dword ptr [EDX + EAX*0x1]
//         0050b06b     TEST       this,this
//         0050b06d     JZ         LAB_0050b076
//         0050b06f     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050b072     MOV        dword ptr [EAX],this
//         0050b074     JMP        LAB_0050b07c
//                               LAB_0050b076                                                 XREF[1]:     0050b06d(j)
//                              tcommand.cpp:1504 (6)
//         0050b076     MOV        dword ptr [EAX],0xffffffff
//                               LAB_0050b07c                                                 XREF[1]:     0050b074(j)
//                              tcommand.cpp:1498 (6)
//         0050b07c     ADD        EAX,0x4
//         0050b07f     DEC        EBP
//         0050b080     JNZ        LAB_0050b068
//                               LAB_0050b082                                                 XREF[1]:     0050b060(j)
//                              tcommand.cpp:1510 (4)
//         0050b082     MOV        DL,byte ptr [ESP + param_2]
//                              tcommand.cpp:1511 (4)
//         0050b086     MOV        EAX,dword ptr [ESP + param_3]
//                              tcommand.cpp:1512 (16)
//         0050b08a     MOV        this,dword ptr [ESP + param_4]
//         0050b08e     MOV        byte ptr [ESI],0x6b
//         0050b091     MOV        byte ptr [ESI + 0x1],DL
//         0050b094     MOV        dword ptr [ESI + 0x4],EAX
//         0050b097     MOV        dword ptr [ESI + 0x8],this
//                              tcommand.cpp:1515 (18)
//         0050b09a     MOV        EDX,dword ptr [L]                                = 00000000
//         0050b0a0     PUSH       EDI
//         0050b0a1     PUSH       s_______>SEND_CMD_ATTACK_GRND_(CNT               = "      >SEND CMD ATTACK GRND (CNT=%d)"
//         0050b0a6     PUSH       EDX
//         0050b0a7     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1518 (14)
//         0050b0ac     MOV        this,dword ptr [ESP + local_4]
//         0050b0b0     ADD        ESP,0xc
//         0050b0b3     PUSH       EBX
//         0050b0b4     PUSH       ESI
//         0050b0b5     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b0ba                                                 XREF[3]:     0050b02f(j), 0050b03e(j),
//                                                                                                         0050b05c(j)
//                              tcommand.cpp:1519 (8)
//         0050b0ba     POP        EDI
//         0050b0bb     POP        ESI
//         0050b0bc     POP        EBP
//         0050b0bd     POP        EBX
//         0050b0be     POP        this
//         0050b0bf     RET        0x10
//         0050b0c2     ??         90h
//         0050b0c3     NOP
//         0050b0c4     NOP
//         0050b0c5     NOP
//         0050b0c6     NOP
//         0050b0c7     NOP
//         0050b0c8     NOP
//         0050b0c9     NOP
//         0050b0ca     NOP
//         0050b0cb     NOP
//         0050b0cc     NOP
//         0050b0cd     NOP
//         0050b0ce     NOP
//         0050b0cf     NOP
    return;
}

void TRIBE_Command::command_cheat(short param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall command_cheat(TRIBE_Command * this, short param_1, s
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0050b0e6(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0050b0f2(R)
//                               ?command_cheat@TRIBE_Command@@QAEXFF@Z                       XREF[1]:     send_cheat:00530acd(c)
//                               TRIBE_Command::command_cheat
//                              tcommand.cpp:1525 (2)
//         0050b0d0     PUSH       ESI
//         0050b0d1     PUSH       EDI
//                              tcommand.cpp:1532 (16)
//         0050b0d2     PUSH       0x10
//         0050b0d4     MOV        EDI,this
//         0050b0d6     PUSH       0x1
//         0050b0d8     CALL       calloc                                           undefined calloc()
//         0050b0dd     MOV        ESI,EAX
//         0050b0df     ADD        ESP,0x8
//                              tcommand.cpp:1534 (4)
//         0050b0e2     TEST       ESI,ESI
//         0050b0e4     JZ         LAB_0050b121
//                              tcommand.cpp:1536 (5)
//         0050b0e6     MOV        AX,word ptr [ESP + param_1]
//                              language.dll match for 0x67: "Comic Sans MS"
//                              tcommand.cpp:1538 (12)
//         0050b0eb     MOV        byte ptr [ESI],0x67
//         0050b0ee     MOV        word ptr [ESI + 0x2],AX
//         0050b0f2     MOV        AX,word ptr [ESP + param_2]
//                              tcommand.cpp:1542 (32)
//         0050b0f7     MOVSX      this,AX
//         0050b0fa     MOV        word ptr [ESI + 0x4],AX
//         0050b0fe     MOV        byte ptr [ESI + 0x1],0x6
//         0050b102     MOV        EDX,dword ptr [L]                                = 00000000
//         0050b108     PUSH       this
//         0050b109     PUSH       s_______>SEND_CMD_CHEAT_%d                       = "      >SEND CMD CHEAT %d"
//         0050b10e     PUSH       EDX
//         0050b10f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b114     ADD        ESP,0xc
//                              tcommand.cpp:1545 (10)
//         0050b117     MOV        this,EDI
//         0050b119     PUSH       0x10
//         0050b11b     PUSH       ESI
//         0050b11c     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b121                                                 XREF[1]:     0050b0e4(j)
//                              tcommand.cpp:1547 (5)
//         0050b121     POP        EDI
//         0050b122     POP        ESI
//         0050b123     RET        0x8
//         0050b126     ??         90h
//         0050b127     NOP
//         0050b128     NOP
//         0050b129     NOP
//         0050b12a     NOP
//         0050b12b     NOP
//         0050b12c     NOP
//         0050b12d     NOP
//         0050b12e     NOP
//         0050b12f     NOP
    return;
}

void TRIBE_Command::command_give_attribute(int param_1, int param_2, int param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall command_give_attribute(TRIBE_Command * this, int par
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050b147(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0050b141(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0050b13d(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0050b151(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0050b158(R)
//                               ?command_give_attribute@TRIBE_Command@@UAEXHHHMM@Z           XREF[1]:     0057656c(*)
//                               TRIBE_Command::command_give_attribute
//                              tcommand.cpp:1553 (2)
//         0050b130     PUSH       ESI
//         0050b131     PUSH       EDI
//                              tcommand.cpp:1564 (11)
//         0050b132     PUSH       0xc
//         0050b134     MOV        EDI,this
//         0050b136     PUSH       0x1
//         0050b138     CALL       calloc                                           undefined calloc()
//                              tcommand.cpp:1570 (20)
//         0050b13d     MOV        DL,byte ptr [ESP + param_3]
//         0050b141     MOV        this,dword ptr [ESP + param_2]
//         0050b145     MOV        ESI,EAX
//         0050b147     MOV        EAX,dword ptr [ESP + param_1]
//         0050b14b     ADD        ESP,0x8
//         0050b14e     MOV        byte ptr [ESI + 0x3],DL
//                              tcommand.cpp:1571 (7)
//         0050b151     MOV        EDX,dword ptr [ESP + param_4]
//         0050b155     MOV        dword ptr [ESI + 0x4],EDX
//                              tcommand.cpp:1572 (4)
//         0050b158     MOV        EDX,dword ptr [ESP + param_5]
//                              tcommand.cpp:1575 (33)
//         0050b15c     PUSH       this
//         0050b15d     MOV        byte ptr [ESI],0x6c
//         0050b160     MOV        byte ptr [ESI + 0x1],AL
//         0050b163     MOV        byte ptr [ESI + 0x2],this
//         0050b166     MOV        dword ptr [ESI + 0x8],EDX
//         0050b169     PUSH       EAX
//         0050b16a     MOV        EAX,[L]                                          = 00000000
//         0050b16f     PUSH       s_______>SEND_CMD_GIVE_ATTR_(PLR=%               = "      >SEND CMD GIVE ATTR (PLR=%d,TO=%d)"
//         0050b174     PUSH       EAX
//         0050b175     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b17a     ADD        ESP,0x10
//                              tcommand.cpp:1578 (10)
//         0050b17d     MOV        this,EDI
//         0050b17f     PUSH       0xc
//         0050b181     PUSH       ESI
//         0050b182     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                              tcommand.cpp:1579 (5)
//         0050b187     POP        EDI
//         0050b188     POP        ESI
//         0050b189     RET        0x14
//         0050b18c     ??         90h
//         0050b18d     NOP
//         0050b18e     NOP
//         0050b18f     NOP
    return;
}

void TRIBE_Command::command_trade_attribute(RGE_Static_Object** param_1, short param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall command_trade_attribute(TRIBE_Command * this, int pa
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050b24d(R)
//              int               Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0050b251(R)
//                               ?command_trade_attribute@TRIBE_Command@@QAEXHHJ@Z            XREF[1]:     command_trade_attribute:00513855(c
//                               TRIBE_Command::command_trade_attribute
//                              tcommand.cpp:1632 (2)
//         0050b230     PUSH       ESI
//         0050b231     PUSH       EDI
//                              tcommand.cpp:1639 (16)
//         0050b232     PUSH       0xc
//         0050b234     MOV        EDI,this
//         0050b236     PUSH       0x1
//         0050b238     CALL       calloc                                           undefined calloc()
//         0050b23d     MOV        ESI,EAX
//         0050b23f     ADD        ESP,0x8
//                              tcommand.cpp:1643 (11)
//         0050b242     TEST       ESI,ESI
//         0050b244     LEA        EAX,[ESI + 0x8]
//         0050b247     JZ         LAB_0050b27e
//         0050b249     TEST       EAX,EAX
//         0050b24b     JZ         LAB_0050b27e
//                              tcommand.cpp:1647 (4)
//         0050b24d     MOV        this,dword ptr [ESP + param_1]
//                              tcommand.cpp:1653 (16)
//         0050b251     MOV        EDX,dword ptr [ESP + param_3]
//         0050b255     MOV        dword ptr [EAX],this
//         0050b257     MOV        byte ptr [ESI],0x6d
//         0050b25a     MOV        byte ptr [ESI + 0x1],0x1
//         0050b25e     MOV        dword ptr [ESI + 0x4],EDX
//                              tcommand.cpp:1656 (19)
//         0050b261     MOV        EAX,[L]                                          = 00000000
//         0050b266     PUSH       s_______>SEND_CMD_TRADE_ATTR2                    = "      >SEND CMD TRADE ATTR2"
//         0050b26b     PUSH       EAX
//         0050b26c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b271     ADD        ESP,0x8
//                              tcommand.cpp:1659 (10)
//         0050b274     MOV        this,EDI
//         0050b276     PUSH       0xc
//         0050b278     PUSH       ESI
//         0050b279     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b27e                                                 XREF[2]:     0050b247(j), 0050b24b(j)
//                              tcommand.cpp:1660 (5)
//         0050b27e     POP        EDI
//         0050b27f     POP        ESI
//         0050b280     RET        0xc
//         0050b283     ??         90h
//         0050b284     NOP
//         0050b285     NOP
//         0050b286     NOP
//         0050b287     NOP
//         0050b288     NOP
//         0050b289     NOP
//         0050b28a     NOP
//         0050b28b     NOP
//         0050b28c     NOP
//         0050b28d     NOP
//         0050b28e     NOP
//         0050b28f     NOP
    return;
}

void TRIBE_Command::command_trade_attribute(int param_1, int param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall command_trade_attribute(TRIBE_Command * this, int pa
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0050b24d(R)
//              int               Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0050b251(R)
//                               ?command_trade_attribute@TRIBE_Command@@QAEXHHJ@Z            XREF[1]:     command_trade_attribute:00513855(c
//                               TRIBE_Command::command_trade_attribute
//                              tcommand.cpp:1632 (2)
//         0050b230     PUSH       ESI
//         0050b231     PUSH       EDI
//                              tcommand.cpp:1639 (16)
//         0050b232     PUSH       0xc
//         0050b234     MOV        EDI,this
//         0050b236     PUSH       0x1
//         0050b238     CALL       calloc                                           undefined calloc()
//         0050b23d     MOV        ESI,EAX
//         0050b23f     ADD        ESP,0x8
//                              tcommand.cpp:1643 (11)
//         0050b242     TEST       ESI,ESI
//         0050b244     LEA        EAX,[ESI + 0x8]
//         0050b247     JZ         LAB_0050b27e
//         0050b249     TEST       EAX,EAX
//         0050b24b     JZ         LAB_0050b27e
//                              tcommand.cpp:1647 (4)
//         0050b24d     MOV        this,dword ptr [ESP + param_1]
//                              tcommand.cpp:1653 (16)
//         0050b251     MOV        EDX,dword ptr [ESP + param_3]
//         0050b255     MOV        dword ptr [EAX],this
//         0050b257     MOV        byte ptr [ESI],0x6d
//         0050b25a     MOV        byte ptr [ESI + 0x1],0x1
//         0050b25e     MOV        dword ptr [ESI + 0x4],EDX
//                              tcommand.cpp:1656 (19)
//         0050b261     MOV        EAX,[L]                                          = 00000000
//         0050b266     PUSH       s_______>SEND_CMD_TRADE_ATTR2                    = "      >SEND CMD TRADE ATTR2"
//         0050b26b     PUSH       EAX
//         0050b26c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b271     ADD        ESP,0x8
//                              tcommand.cpp:1659 (10)
//         0050b274     MOV        this,EDI
//         0050b276     PUSH       0xc
//         0050b278     PUSH       ESI
//         0050b279     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b27e                                                 XREF[2]:     0050b247(j), 0050b24b(j)
//                              tcommand.cpp:1660 (5)
//         0050b27e     POP        EDI
//         0050b27f     POP        ESI
//         0050b280     RET        0xc
//         0050b283     ??         90h
//         0050b284     NOP
//         0050b285     NOP
//         0050b286     NOP
//         0050b287     NOP
//         0050b288     NOP
//         0050b289     NOP
//         0050b28a     NOP
//         0050b28b     NOP
//         0050b28c     NOP
//         0050b28d     NOP
//         0050b28e     NOP
//         0050b28f     NOP
    return;
}

void TRIBE_Command::command_repair(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              void __thiscall command_repair(TRIBE_Command * this, RGE_Static_Obje
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050b29d(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     0050b291(R), 0050b2f2(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     0050b2ee(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b2a3(W), 0050b314(R)
//                               ?command_repair@TRIBE_Command@@QAEXPAPAVRGE_Static_Object@@  XREF[1]:     command_make_repair:00513a52(c)
//                               TRIBE_Command::command_repair
//                              tcommand.cpp:1666 (1)
//         0050b290     PUSH       this
//                              tcommand.cpp:1669 (12)
//         0050b291     MOV        AX,word ptr [ESP + param_2]
//         0050b296     PUSH       EBX
//         0050b297     PUSH       EBP
//         0050b298     PUSH       ESI
//         0050b299     MOVSX      EBP,AX
//         0050b29c     PUSH       EDI
//                              tcommand.cpp:1679 (25)
//         0050b29d     MOV        EDI,dword ptr [ESP + param_1]
//         0050b2a1     TEST       EDI,EDI
//         0050b2a3     MOV        dword ptr [ESP + local_4],this
//         0050b2a7     LEA        EBX,[EBP*0x4 + 0x8]
//         0050b2ae     JZ         LAB_0050b322
//         0050b2b0     CMP        AX,0x1
//         0050b2b4     JL         LAB_0050b322
//                              tcommand.cpp:1683 (13)
//         0050b2b6     PUSH       EBX
//         0050b2b7     PUSH       0x1
//         0050b2b9     CALL       calloc                                           undefined calloc()
//         0050b2be     MOV        ESI,EAX
//         0050b2c0     ADD        ESP,0x8
//                              tcommand.cpp:1687 (7)
//         0050b2c3     TEST       ESI,ESI
//         0050b2c5     LEA        EAX,[ESI + 0x8]
//         0050b2c8     JZ         LAB_0050b322
//                              tcommand.cpp:1690 (4)
//         0050b2ca     TEST       EBP,EBP
//         0050b2cc     JLE        LAB_0050b2ee
//                              tcommand.cpp:1698 (2)
//         0050b2ce     MOV        EDX,EDI
//                              tcommand.cpp:1716 (18)
//         0050b2d0     MOV        EDI,EBP
//         0050b2d2     SUB        EDX,EAX
//                               LAB_0050b2d4                                                 XREF[1]:     0050b2ec(j)
//         0050b2d4     MOV        this,dword ptr [EDX + EAX*0x1]
//         0050b2d7     TEST       this,this
//         0050b2d9     JZ         LAB_0050b2e2
//         0050b2db     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050b2de     MOV        dword ptr [EAX],this
//         0050b2e0     JMP        LAB_0050b2e8
//                               LAB_0050b2e2                                                 XREF[1]:     0050b2d9(j)
//                              tcommand.cpp:1698 (6)
//         0050b2e2     MOV        dword ptr [EAX],0xffffffff
//                               LAB_0050b2e8                                                 XREF[1]:     0050b2e0(j)
//                              tcommand.cpp:1690 (6)
//         0050b2e8     ADD        EAX,0x4
//         0050b2eb     DEC        EDI
//         0050b2ec     JNZ        LAB_0050b2d4
//                               LAB_0050b2ee                                                 XREF[1]:     0050b2cc(j)
//                              tcommand.cpp:1703 (4)
//         0050b2ee     MOV        EDX,dword ptr [ESP + param_3]
//                              tcommand.cpp:1708 (4)
//         0050b2f2     MOV        this,byte ptr [ESP + param_2]
//                              tcommand.cpp:1711 (30)
//         0050b2f6     PUSH       EBP
//         0050b2f7     PUSH       s_______>SEND_CMD_REPAIR_(CNT=%d)                = "      >SEND CMD REPAIR (CNT=%d)"
//         0050b2fc     MOV        EAX,dword ptr [EDX + 0x4]
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         0050b2ff     MOV        byte ptr [ESI],0x6e
//         0050b302     MOV        dword ptr [ESI + 0x4],EAX
//         0050b305     MOV        byte ptr [ESI + 0x1],this
//         0050b308     MOV        EDX,dword ptr [L]                                = 00000000
//         0050b30e     PUSH       EDX
//         0050b30f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1714 (14)
//         0050b314     MOV        this,dword ptr [ESP + local_4]
//         0050b318     ADD        ESP,0xc
//         0050b31b     PUSH       EBX
//         0050b31c     PUSH       ESI
//         0050b31d     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b322                                                 XREF[3]:     0050b2ae(j), 0050b2b4(j),
//                                                                                                         0050b2c8(j)
//                              tcommand.cpp:1716 (8)
//         0050b322     POP        EDI
//         0050b323     POP        ESI
//         0050b324     POP        EBP
//         0050b325     POP        EBX
//         0050b326     POP        this
//         0050b327     RET        0xc
//         0050b32a     ??         90h
//         0050b32b     NOP
//         0050b32c     NOP
//         0050b32d     NOP
//         0050b32e     NOP
//         0050b32f     NOP
    return;
}

void TRIBE_Command::command_unload(RGE_Static_Object** param_1, short param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall command_unload(TRIBE_Command * this, RGE_Static_Obje
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050b333(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     0050b345(R), 0050b392(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0050b396(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0050b39a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b33b(W), 0050b3bc(R)
//                               ?command_unload@TRIBE_Command@@QAEXPAPAVRGE_Static_Object@@  XREF[1]:     command_make_unload:00513acb(c)
//                               TRIBE_Command::command_unload
//                              tcommand.cpp:1722 (3)
//         0050b330     PUSH       this
//         0050b331     PUSH       EBX
//         0050b332     PUSH       EBP
//                              tcommand.cpp:1729 (29)
//         0050b333     MOV        EBP,dword ptr [ESP + param_1]
//         0050b337     PUSH       ESI
//         0050b338     TEST       EBP,EBP
//         0050b33a     PUSH       EDI
//         0050b33b     MOV        dword ptr [ESP + local_4],this
//         0050b33f     JZ         LAB_0050b3ca
//         0050b345     MOV        AX,word ptr [ESP + param_2]
//         0050b34a     CMP        AX,0x1
//         0050b34e     JL         LAB_0050b3ca
//                              tcommand.cpp:1733 (10)
//         0050b350     MOVSX      EDI,AX
//         0050b353     LEA        EBX,[EDI*0x4 + 0xc]
//                              tcommand.cpp:1734 (13)
//         0050b35a     PUSH       EBX
//         0050b35b     PUSH       0x1
//         0050b35d     CALL       calloc                                           undefined calloc()
//         0050b362     MOV        ESI,EAX
//         0050b364     ADD        ESP,0x8
//                              tcommand.cpp:1739 (7)
//         0050b367     TEST       ESI,ESI
//         0050b369     LEA        EAX,[ESI + 0xc]
//         0050b36c     JZ         LAB_0050b3ca
//                              tcommand.cpp:1743 (4)
//         0050b36e     TEST       EDI,EDI
//         0050b370     JLE        LAB_0050b392
//                              tcommand.cpp:1749 (2)
//         0050b372     MOV        EDX,EBP
//                              tcommand.cpp:1764 (18)
//         0050b374     MOV        EBP,EDI
//         0050b376     SUB        EDX,EAX
//                               LAB_0050b378                                                 XREF[1]:     0050b390(j)
//         0050b378     MOV        this,dword ptr [EDX + EAX*0x1]
//         0050b37b     TEST       this,this
//         0050b37d     JZ         LAB_0050b386
//         0050b37f     MOV        this,dword ptr [ECX + this->field4_0x4]
//         0050b382     MOV        dword ptr [EAX],this
//         0050b384     JMP        LAB_0050b38c
//                               LAB_0050b386                                                 XREF[1]:     0050b37d(j)
//                              tcommand.cpp:1749 (6)
//         0050b386     MOV        dword ptr [EAX],0xffffffff
//                               LAB_0050b38c                                                 XREF[1]:     0050b384(j)
//                              tcommand.cpp:1743 (6)
//         0050b38c     ADD        EAX,0x4
//         0050b38f     DEC        EBP
//         0050b390     JNZ        LAB_0050b378
//                               LAB_0050b392                                                 XREF[1]:     0050b370(j)
//                              tcommand.cpp:1755 (4)
//         0050b392     MOV        DL,byte ptr [ESP + param_2]
//                              tcommand.cpp:1756 (4)
//         0050b396     MOV        EAX,dword ptr [ESP + param_3]
//                              tcommand.cpp:1757 (16)
//         0050b39a     MOV        this,dword ptr [ESP + param_4]
//                              language.dll match for 0x6f: "12"
//         0050b39e     MOV        byte ptr [ESI],0x6f
//         0050b3a1     MOV        byte ptr [ESI + 0x1],DL
//         0050b3a4     MOV        dword ptr [ESI + 0x4],EAX
//         0050b3a7     MOV        dword ptr [ESI + 0x8],this
//                              tcommand.cpp:1760 (18)
//         0050b3aa     MOV        EDX,dword ptr [L]                                = 00000000
//         0050b3b0     PUSH       EDI
//         0050b3b1     PUSH       s_______>SEND_CMD_UNLOAD_(CNT=%d)                = "      >SEND CMD UNLOAD (CNT=%d)"
//         0050b3b6     PUSH       EDX
//         0050b3b7     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              tcommand.cpp:1763 (14)
//         0050b3bc     MOV        this,dword ptr [ESP + local_4]
//         0050b3c0     ADD        ESP,0xc
//         0050b3c3     PUSH       EBX
//         0050b3c4     PUSH       ESI
//         0050b3c5     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b3ca                                                 XREF[3]:     0050b33f(j), 0050b34e(j),
//                                                                                                         0050b36c(j)
//                              tcommand.cpp:1764 (8)
//         0050b3ca     POP        EDI
//         0050b3cb     POP        ESI
//         0050b3cc     POP        EBP
//         0050b3cd     POP        EBX
//         0050b3ce     POP        this
//         0050b3cf     RET        0x10
//         0050b3d2     ??         90h
//         0050b3d3     NOP
//         0050b3d4     NOP
//         0050b3d5     NOP
//         0050b3d6     NOP
//         0050b3d7     NOP
//         0050b3d8     NOP
//         0050b3d9     NOP
//         0050b3da     NOP
//         0050b3db     NOP
//         0050b3dc     NOP
//         0050b3dd     NOP
//         0050b3de     NOP
//         0050b3df     NOP
    return;
}

void TRIBE_Command::command_queue(RGE_Static_Object* param_1, short param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall command_queue(TRIBE_Command * this, RGE_Static_Objec
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050b3f6(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0050b40c(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     0050b3fa(R)
//                               ?command_queue@TRIBE_Command@@QAEXPAVRGE_Static_Object@@FF@Z XREF[1]:     command_train:0049cf06(c)
//                               TRIBE_Command::command_queue
//                              tcommand.cpp:1770 (2)
//         0050b3e0     PUSH       ESI
//         0050b3e1     PUSH       EDI
//                              tcommand.cpp:1779 (16)
//         0050b3e2     PUSH       0xc
//         0050b3e4     MOV        EDI,this
//         0050b3e6     PUSH       0x1
//         0050b3e8     CALL       calloc                                           undefined calloc()
//         0050b3ed     MOV        ESI,EAX
//         0050b3ef     ADD        ESP,0x8
//                              tcommand.cpp:1782 (4)
//         0050b3f2     TEST       ESI,ESI
//         0050b3f4     JZ         LAB_0050b43e
//                              tcommand.cpp:1786 (4)
//         0050b3f6     MOV        EAX,dword ptr [ESP + param_1]
//                              tcommand.cpp:1788 (23)
//         0050b3fa     MOV        DX,word ptr [ESP + param_3]
//                              language.dll match for 0x77: "Arial"
//         0050b3ff     MOV        byte ptr [ESI],0x77
//         0050b402     MOV        this,dword ptr [EAX + 0x4]
//         0050b405     MOV        word ptr [ESI + 0xa],DX
//         0050b409     MOV        dword ptr [ESI + 0x4],this
//         0050b40c     MOV        this,word ptr [ESP + param_2]
//                              tcommand.cpp:1791 (35)
//         0050b411     MOVSX      EDX,DX
//         0050b414     MOV        word ptr [ESI + 0x8],this
//         0050b418     PUSH       EDX
//         0050b419     MOV        EDX,dword ptr [EAX + 0x4]
//         0050b41c     MOV        EAX,[L]                                          = 00000000
//         0050b421     MOVSX      this,this
//         0050b424     PUSH       this
//         0050b425     PUSH       EDX
//         0050b426     PUSH       s_______>SEND_CMD_QUEUE_(B=%d,T=%d               = "      >SEND CMD QUEUE (B=%d,T=%d,C=%d)"
//         0050b42b     PUSH       EAX
//         0050b42c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         0050b431     ADD        ESP,0x14
//                              tcommand.cpp:1794 (10)
//         0050b434     MOV        this,EDI
//         0050b436     PUSH       0xc
//         0050b438     PUSH       ESI
//         0050b439     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
//                               LAB_0050b43e                                                 XREF[1]:     0050b3f4(j)
//                              tcommand.cpp:1796 (5)
//         0050b43e     POP        EDI
//         0050b43f     POP        ESI
//         0050b440     RET        0xc
//         0050b443     ??         90h
//         0050b444     NOP
//         0050b445     NOP
//         0050b446     NOP
//         0050b447     NOP
//         0050b448     NOP
//         0050b449     NOP
//         0050b44a     NOP
//         0050b44b     NOP
//         0050b44c     NOP
//         0050b44d     NOP
//         0050b44e     NOP
//         0050b44f     NOP
    return;
}

TRIBE_Command::~TRIBE_Command() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Command(TRIBE_Command * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Command *   ECX:4 (auto)   this
//                               ??1TRIBE_Command@@UAE@XZ                                     XREF[1]:     `vector_deleting_destructor':00509
//                               TRIBE_Command::~TRIBE_Command
//         00509760     JMP        RGE_Command::~RGE_Command
//         00509765     ??         90h
//         00509766     NOP
//         00509767     NOP
//         00509768     NOP
//         00509769     NOP
//         0050976a     NOP
//         0050976b     NOP
//         0050976c     NOP
//         0050976d     NOP
//         0050976e     NOP
//         0050976f     NOP
}

