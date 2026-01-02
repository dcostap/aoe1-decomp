#include "../common.h"
#include "rmm_cntr.h"

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_RMM_Controller(RGE_RMM_Controller * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     004821bf(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00482223(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004821d8(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004821df(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004821f8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048223a(R)
//              RGE_Land_Info     Stack[-0x144   land_info                 XREF[0,3]:   004821ed(*), 0048220e(*), 0048222a(*)
//              RGE_Terrain_In    Stack[-0x26e   terrain_info              XREF[1,1]:   004821cf(W), 00482216(*)
//                               ??0RGE_RMM_Controller@@QAE@PAVRGE_Map@@PAVRGE_Game_World@@E
//                               RGE_RMM_Controller::RGE_RMM_Controller
//                              rmm_cntr.cpp:42 (56)
//         004821a0     MOV        EAX,FS:[0x0]
//         004821a6     PUSH       -0x1
//         004821a8     PUSH       FUN_0055e5db
//         004821ad     PUSH       EAX
//         004821ae     MOV        EAX,0x26d4
//         004821b3     MOV        dword ptr FS:[0x0],ESP
//         004821ba     CALL       __alloca_probe                                   undefined __alloca_probe()
//         004821bf     MOV        EAX,dword ptr [ESP + param_1]
//         004821c6     PUSH       ESI
//         004821c7     PUSH       EDI
//         004821c8     PUSH       0x1
//         004821ca     MOV        ESI,this
//         004821cc     PUSH       0x0
//         004821ce     PUSH       EAX
//         004821cf     MOV        dword ptr [ESP + terrain_info.terrain[0].terra
//         004821d3     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
//                              rmm_cntr.cpp:46 (54)
//         004821d8     MOV        EDI,dword ptr [ESP + param_3]
//         004821df     MOV        this,dword ptr [ESP + param_4]
//         004821e6     AND        EDI,0xff
//         004821ec     PUSH       this
//         004821ed     LEA        EDX=>land_info+0x4,[ESP + 0x12a8]
//         004821f4     PUSH       EDI
//         004821f5     PUSH       EDX
//         004821f6     MOV        this,ESI
//         004821f8     MOV        dword ptr [ESP + local_4],0x0
//         00482203     MOV        dword ptr [ESI],RGE_RMM_Controller::`vftable'    = 00482260
//         00482209     CALL       RGE_RMM_Controller::add_land_module              void add_land_module(RGE_RMM_Controller * thi
//                              rmm_cntr.cpp:47 (21)
//         0048220e     LEA        EAX=>land_info+0x4,[ESP + 0x12a4]
//         00482215     PUSH       EDI
//         00482216     LEA        this=>terrain_info+0x4,[ESP + 0x10]
//         0048221a     PUSH       EAX
//         0048221b     PUSH       this
//         0048221c     MOV        this,ESI
//         0048221e     CALL       RGE_RMM_Controller::add_terrain_module           void add_terrain_module(RGE_RMM_Controller *
//                              rmm_cntr.cpp:48 (23)
//         00482223     MOV        EAX,dword ptr [ESP + param_2]
//         0048222a     LEA        EDX=>land_info+0x4,[ESP + 0x12a4]
//         00482231     PUSH       EDX
//         00482232     PUSH       EAX
//         00482233     MOV        this,ESI
//         00482235     CALL       RGE_RMM_Controller::add_object_module            void add_object_module(RGE_RMM_Controller * t
//                              rmm_cntr.cpp:49 (27)
//         0048223a     MOV        this,dword ptr [ESP + local_c]
//         00482241     MOV        EAX,ESI
//         00482243     POP        EDI
//         00482244     MOV        dword ptr FS:[0x0],this
//         0048224b     POP        ESI
//         0048224c     ADD        ESP,0x26e0
//         00482252     RET        0x10
//         00482255     ??         90h
//         00482256     NOP
//         00482257     NOP
//         00482258     NOP
//         00482259     NOP
//         0048225a     NOP
//         0048225b     NOP
//         0048225c     NOP
//         0048225d     NOP
//         0048225e     NOP
//         0048225f     NOP
}

uchar RGE_RMM_Controller::generate() {
    /* TODO: Stub */
//                              uchar __thiscall generate(RGE_RMM_Controller * this)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//                               ?generate@RGE_RMM_Controller@@UAEEXZ                         XREF[1]:     00571e68(*)
//                               RGE_RMM_Controller::generate
//                              rmm_cntr.cpp:53 (5)
//         00482260     JMP        RGE_Random_Map_Module::generate
//         00482265     ??         90h
//         00482266     NOP
//         00482267     NOP
//         00482268     NOP
//         00482269     NOP
//         0048226a     NOP
//         0048226b     NOP
//         0048226c     NOP
//         0048226d     NOP
//         0048226e     NOP
//         0048226f     NOP
    return 0;
}

void RGE_RMM_Controller::add_land_module(RGE_Land_Info* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall add_land_module(RGE_RMM_Controller * this, RGE_Land_
//              void              <VOID>         <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//              RGE_Land_Info *   Stack[0x4]:4   param_1                   XREF[4]:     00482290(R), 004825c3(R), 00482645(R), 00482684(W)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0048229c(R), 004824e2(R)
//              long              Stack[0xc]:4   param_3                   XREF[8]:     00482288(R), 004823ec(R), 004824c5(R), 00482530(W),
//                                                                                     004825a9(W), 004825fe(R), 00482618(W), 00482635(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048268a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048269d(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004823fe(W), 00482641(R)
//              long              Stack[-0x14]:4 land_tile_num             XREF[2]:     004822a3(W), 00482631(R)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     00482417(W), 004825f3(R)
//              float             Stack[-0x1c]:4 bound_square
//              undefined8        Stack[-0x28]:8 local_28                  XREF[12]:    004823e4(W), 004823e8(R), 00482407(W), 0048241b(R),
//                                                                                     0048243c(W), 00482440(R), 0048245d(W), 00482461(R),
//                                                                                     0048246e(R), 00482486(W), 004824c1(W), 004825a3(R)
//              long              Stack[-0x2c]:4 mid_y2                    XREF[4]:     004825b7(W), 0048260a(R), 0048261d(R), 0048262b(W)
//              long              Stack[-0x30]:4 index2                    XREF[4]:     00482459(W), 00482494(R), 0048249a(W), 0048259d(R)
//              long              Stack[-0x34]:4 mid_y1                    XREF[4]:     00482472(W), 004824a2(R), 004824b0(W), 00482597(R)
//              long              Stack[-0x38]:4 mid_x2                    XREF[4]:     00482430(W), 0048247b(R), 0048248c(W), 0048258f(R)
//              long              Stack[-0x3c]:4 mid_x1                    XREF[7]:     004824cd(W), 004824dc(R), 004825b3(R), 00482606(R),
//                                                                                     00482621(R), 0048265c(R), 00482669(W)
//              long              Stack[-0x40]:4 index
//                               ?add_land_module@RGE_RMM_Controller@@IAEXAAURGE_Land_Info@@  XREF[1]:     RGE_RMM_Controller:00482209(c)
//                               RGE_RMM_Controller::add_land_module
//                              rmm_cntr.cpp:60 (24)
//         00482270     PUSH       -0x1
//         00482272     PUSH       FUN_0055e5fb
//         00482277     MOV        EAX,FS:[0x0]
//         0048227d     PUSH       EAX
//         0048227e     MOV        dword ptr FS:[0x0],ESP
//         00482285     SUB        ESP,0x30
//                              rmm_cntr.cpp:79 (20)
//         00482288     MOV        EAX,dword ptr [ESP + param_3]
//         0048228c     PUSH       EBX
//         0048228d     PUSH       EBP
//         0048228e     PUSH       ESI
//         0048228f     PUSH       EDI
//         00482290     MOV        EDI,dword ptr [ESP + param_1]
//         00482294     MOV        EBX,this
//         00482296     MOV        dword ptr [EDI + 0x141c],EAX
//                              rmm_cntr.cpp:81 (24)
//         0048229c     MOV        EAX,dword ptr [ESP + param_2]
//         004822a0     CMP        EAX,0x3
//         004822a3     MOV        dword ptr [ESP + land_tile_num],EBX
//         004822a7     JA         switchD_004822ad::default
//                               switchD_004822ad::switchD
//         004822ad     JMP        dword ptr [EAX*0x4 + switchD_004822ad::switchd   = 00482365
//                               switchD_004822ad::caseD_3                                    XREF[2]:     004822ad(j), 004826c0(*)
//                              rmm_cntr.cpp:99 (20)
//         004822b4     XOR        EBP,EBP
//         004822b6     MOV        byte ptr [EDI + 0x1420],0x1
//         004822bd     MOV        EAX,0x5a
//         004822c2     MOV        dword ptr [EDI + 0x1424],EBP
//                              rmm_cntr.cpp:100 (6)
//         004822c8     MOV        dword ptr [EDI + 0x1428],EBP
//                              rmm_cntr.cpp:101 (6)
//         004822ce     MOV        dword ptr [EDI + 0x142c],EBP
//                              rmm_cntr.cpp:102 (6)
//         004822d4     MOV        dword ptr [EDI + 0x1430],EBP
//                              rmm_cntr.cpp:103 (7)
//         004822da     MOV        byte ptr [EDI + 0x1434],0x0
//                              rmm_cntr.cpp:105 (5)
//         004822e1     JMP        LAB_004823cc
//                               switchD_004822ad::caseD_2                                    XREF[2]:     004822ad(j), 004826bc(*)
//                              rmm_cntr.cpp:110 (18)
//         004822e6     MOV        this,0x4
//         004822eb     MOV        byte ptr [EDI + 0x1420],0x1
//         004822f2     MOV        dword ptr [EDI + 0x1424],this
//                              rmm_cntr.cpp:111 (6)
//         004822f8     MOV        dword ptr [EDI + 0x1428],this
//                              rmm_cntr.cpp:112 (17)
//         004822fe     MOV        this,dword ptr [EBX + 0x14]
//         00482301     MOV        EAX,0x46
//         00482306     SUB        this,0x5
//         00482309     MOV        dword ptr [EDI + 0x142c],this
//                              rmm_cntr.cpp:113 (6)
//         0048230f     MOV        EDX,dword ptr [EBX + 0x18]
//         00482312     SUB        EDX,0x5
//                              rmm_cntr.cpp:114 (13)
//         00482315     MOV        byte ptr [EDI + 0x1434],0x22
//         0048231c     MOV        dword ptr [EDI + 0x1430],EDX
//                              rmm_cntr.cpp:116 (5)
//         00482322     JMP        LAB_004823ca
//                               switchD_004822ad::caseD_1                                    XREF[2]:     004822ad(j), 004826b8(*)
//                              rmm_cntr.cpp:121 (18)
//         00482327     MOV        this,0x6
//         0048232c     MOV        byte ptr [EDI + 0x1420],0x1
//         00482333     MOV        dword ptr [EDI + 0x1424],this
//                              rmm_cntr.cpp:122 (6)
//         00482339     MOV        dword ptr [EDI + 0x1428],this
//                              rmm_cntr.cpp:123 (17)
//         0048233f     MOV        this,dword ptr [EBX + 0x14]
//         00482342     MOV        EAX,0x32
//         00482347     SUB        this,0x7
//         0048234a     MOV        dword ptr [EDI + 0x142c],this
//                              rmm_cntr.cpp:124 (6)
//         00482350     MOV        EDX,dword ptr [EBX + 0x18]
//         00482353     SUB        EDX,0x7
//                              rmm_cntr.cpp:125 (13)
//         00482356     MOV        byte ptr [EDI + 0x1434],0x14
//         0048235d     MOV        dword ptr [EDI + 0x1430],EDX
//                              rmm_cntr.cpp:127 (2)
//         00482363     JMP        LAB_004823ca
//                               switchD_004822ad::caseD_0                                    XREF[2]:     004822ad(j), 004826b4(*)
//                              rmm_cntr.cpp:132 (18)
//         00482365     MOV        this,0x8
//         0048236a     MOV        byte ptr [EDI + 0x1420],0x1
//         00482371     MOV        dword ptr [EDI + 0x1424],this
//                              rmm_cntr.cpp:133 (6)
//         00482377     MOV        dword ptr [EDI + 0x1428],this
//                              rmm_cntr.cpp:134 (17)
//         0048237d     MOV        this,dword ptr [EBX + 0x14]
//         00482380     MOV        EAX,0x1e
//         00482385     SUB        this,0x9
//         00482388     MOV        dword ptr [EDI + 0x142c],this
//                              rmm_cntr.cpp:135 (6)
//         0048238e     MOV        EDX,dword ptr [EBX + 0x18]
//         00482391     SUB        EDX,0x9
//                              rmm_cntr.cpp:136 (13)
//         00482394     MOV        byte ptr [EDI + 0x1434],0x14
//         0048239b     MOV        dword ptr [EDI + 0x1430],EDX
//                              rmm_cntr.cpp:138 (2)
//         004823a1     JMP        LAB_004823ca
//                               switchD_004822ad::default                                    XREF[1]:     004822a7(j)
//                              rmm_cntr.cpp:86 (9)
//         004823a3     XOR        EAX,EAX
//         004823a5     MOV        byte ptr [EDI + 0x1420],0x0
//                              rmm_cntr.cpp:88 (6)
//         004823ac     MOV        dword ptr [EDI + 0x1424],EAX
//                              rmm_cntr.cpp:89 (6)
//         004823b2     MOV        dword ptr [EDI + 0x1428],EAX
//                              rmm_cntr.cpp:90 (6)
//         004823b8     MOV        dword ptr [EDI + 0x142c],EAX
//                              rmm_cntr.cpp:91 (6)
//         004823be     MOV        dword ptr [EDI + 0x1430],EAX
//                              rmm_cntr.cpp:92 (8)
//         004823c4     MOV        byte ptr [EDI + 0x1434],AL
//                               LAB_004823ca                                                 XREF[3]:     00482322(j), 00482363(j),
//                                                                                                         004823a1(j)
//         004823ca     XOR        EBP,EBP
//                               LAB_004823cc                                                 XREF[1]:     004822e1(j)
//                              rmm_cntr.cpp:141 (21)
//         004823cc     MOV        this,dword ptr [EBX + 0x18]
//         004823cf     MOV        ESI,dword ptr [EBX + 0x14]
//         004823d2     IMUL       EAX,this
//         004823d5     IMUL       EAX,ESI
//         004823d8     MOV        this,EAX
//         004823da     MOV        EAX,0x51eb851f
//         004823df     IMUL       this
//                              rmm_cntr.cpp:148 (27)
//         004823e1     LEA        this,[ESI + -0x10]
//         004823e4     MOV        dword ptr [ESP + local_28],this
//         004823e8     FILD       dword ptr [ESP + local_28]
//         004823ec     FILD       dword ptr [ESP + param_3]
//         004823f0     SAR        EDX,0x5
//         004823f3     MOV        EAX,EDX
//         004823f5     FSQRT
//         004823f7     SHR        EAX,0x1f
//         004823fa     ADD        EDX,EAX
//                              rmm_cntr.cpp:151 (56)
//         004823fc     MOV        EAX,ESI
//         004823fe     MOV        dword ptr [ESP + local_10],EDX
//         00482402     CDQ
//         00482403     SUB        EAX,EDX
//         00482405     SAR        EAX,0x1
//         00482407     MOV        dword ptr [ESP + local_28],EAX
//         0048240b     FDIVP
//         0048240d     FMUL       double ptr [DAT_00571e70]                        = 9Ah
//         00482413     FLD        ST0
//         00482415     FMUL       ST1
//         00482417     FSTP       float ptr [ESP + local_18]
//         0048241b     FILD       dword ptr [ESP + local_28]
//         0048241f     FLD        ST1
//         00482421     FMUL       double ptr [DAT_00571e78]                        = CDh
//         00482427     FLD        ST1
//         00482429     FSUB       ST0,ST1
//         0048242b     CALL       __ftol                                           undefined __ftol()
//         00482430     MOV        dword ptr [ESP + mid_x2],EAX
//                              rmm_cntr.cpp:152 (29)
//         00482434     MOV        EAX,dword ptr [EBX + 0x18]
//         00482437     CDQ
//         00482438     SUB        EAX,EDX
//         0048243a     SAR        EAX,0x1
//         0048243c     MOV        dword ptr [ESP + local_28],EAX
//         00482440     FILD       dword ptr [ESP + local_28]
//         00482444     FST        double ptr [ESP + Stack[-0x20]]
//         00482448     FSUB       ST0,ST1
//         0048244a     CALL       __ftol                                           undefined __ftol()
//         0048244f     FSTP       ST0
//                              rmm_cntr.cpp:153 (25)
//         00482451     FXCH
//         00482453     FMUL       double ptr [DAT_00571e80]                        = CDh
//         00482459     MOV        dword ptr [ESP + index2],EAX
//         0048245d     FSTP       double ptr [ESP + local_28]
//         00482461     FSUB       double ptr [ESP + local_28]
//         00482465     CALL       __ftol                                           undefined __ftol()
//                              rmm_cntr.cpp:154 (17)
//         0048246a     FLD        double ptr [ESP + Stack[-0x20]]
//         0048246e     FSUB       double ptr [ESP + local_28]
//         00482472     MOV        dword ptr [ESP + mid_y1],EAX
//         00482476     CALL       __ftol                                           undefined __ftol()
//                              rmm_cntr.cpp:156 (17)
//         0048247b     MOV        EDX,dword ptr [ESP + mid_x2]
//         0048247f     MOV        this,0x8
//         00482484     CMP        EDX,this
//         00482486     MOV        dword ptr [ESP + local_28],EAX
//         0048248a     JG         LAB_00482494
//                              rmm_cntr.cpp:157 (8)
//         0048248c     MOV        dword ptr [ESP + mid_x2],0x9
//                               LAB_00482494                                                 XREF[1]:     0048248a(j)
//                              rmm_cntr.cpp:159 (6)
//         00482494     CMP        dword ptr [ESP + index2],this
//         00482498     JG         LAB_004824a2
//                              rmm_cntr.cpp:160 (8)
//         0048249a     MOV        dword ptr [ESP + index2],0x9
//                               LAB_004824a2                                                 XREF[1]:     00482498(j)
//                              rmm_cntr.cpp:162 (11)
//         004824a2     MOV        this,dword ptr [ESP + mid_y1]
//         004824a6     LEA        EDX,[ESI + -0x9]
//         004824a9     CMP        this,EDX
//         004824ab     JL         LAB_004824b4
//                              rmm_cntr.cpp:163 (7)
//         004824ad     ADD        ESI,-0xa
//         004824b0     MOV        dword ptr [ESP + mid_y1],ESI
//                               LAB_004824b4                                                 XREF[1]:     004824ab(j)
//                              rmm_cntr.cpp:165 (10)
//         004824b4     MOV        this,dword ptr [EBX + 0x18]
//         004824b7     LEA        EDX,[this->field0_0x0 + -0x9]
//         004824ba     CMP        EAX,EDX
//         004824bc     JL         LAB_004824c5
//                              rmm_cntr.cpp:166 (7)
//         004824be     ADD        this,-0xa
//         004824c1     MOV        dword ptr [ESP + local_28],this
//                               LAB_004824c5                                                 XREF[1]:     004824bc(j)
//                              rmm_cntr.cpp:168 (29)
//         004824c5     MOV        this,dword ptr [ESP + param_3]
//         004824c9     XOR        EAX,EAX
//         004824cb     CMP        this,EBP
//         004824cd     MOV        dword ptr [ESP + mid_x1],EAX
//         004824d1     JLE        LAB_00482677
//         004824d7     ADD        EDI,0x14
//         004824da     JMP        LAB_004824e2
//                               LAB_004824dc                                                 XREF[1]:     0048266d(j)
//         004824dc     MOV        EAX,dword ptr [ESP + mid_x1]
//         004824e0     XOR        EBP,EBP
//                               LAB_004824e2                                                 XREF[1]:     004824da(j)
//                              rmm_cntr.cpp:172 (16)
//         004824e2     MOV        this,dword ptr [ESP + param_2]
//         004824e6     CMP        this,0x4
//         004824e9     JA         switchD_004824eb::default
//                               switchD_004824eb::switchD
//         004824eb     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0048   = 00482513
//                               switchD_004824eb::caseD_3                                    XREF[4]:     004824eb(j), 004826cc(*),
//                               switchD_004824eb::caseD_4                                                 004826d0(*), 004826d4(*)
//                               switchD_004824eb::caseD_2
//                              rmm_cntr.cpp:187 (3)
//         004824f2     MOV        dword ptr [EDI + -0x10],EBP
//                              rmm_cntr.cpp:188 (6)
//         004824f5     MOV        dword ptr [EDI],0x3
//                              rmm_cntr.cpp:189 (7)
//         004824fb     MOV        dword ptr [EDI + -0x4],0x5
//                              rmm_cntr.cpp:190 (4)
//         00482502     MOV        byte ptr [EDI + 0x4],0x0
//                              rmm_cntr.cpp:191 (2)
//         00482506     JMP        switchD_004824eb::default
//                               switchD_004824eb::caseD_1                                    XREF[2]:     004824eb(j), 004826c8(*)
//                              rmm_cntr.cpp:193 (3)
//         00482508     MOV        dword ptr [EDI + -0x10],EBP
//                              rmm_cntr.cpp:194 (6)
//         0048250b     MOV        dword ptr [EDI],0x4
//                              rmm_cntr.cpp:197 (2)
//         00482511     JMP        LAB_0048251c
//                               switchD_004824eb::caseD_0                                    XREF[2]:     004824eb(j), 004826c4(*)
//                              rmm_cntr.cpp:199 (3)
//         00482513     MOV        dword ptr [EDI + -0x10],EBP
//                              rmm_cntr.cpp:200 (6)
//         00482516     MOV        dword ptr [EDI],0x7
//                               LAB_0048251c                                                 XREF[1]:     00482511(j)
//                              rmm_cntr.cpp:201 (7)
//         0048251c     MOV        dword ptr [EDI + -0x4],0x5
//                              rmm_cntr.cpp:202 (3)
//         00482523     MOV        byte ptr [EDI + 0x4],AL
//                               switchD_004824eb::default                                    XREF[3]:     004824e9(j), 00482506(j),
//                                                                                                         0048263b(j)
//                              rmm_cntr.cpp:209 (39)
//         00482526     PUSH       0xd1
//         0048252b     PUSH       s_C:\msdev\work\age1_x1\rmm_cntr.c               = "C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp"
//         00482530     MOV        byte ptr [ESP + param_3],0x0
//         00482535     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0048253a     MOV        this,EAX
//         0048253c     MOV        EAX,dword ptr [EBX + 0x14]
//         0048253f     SUB        EAX,0x10
//         00482542     ADD        ESP,0x8
//         00482545     IMUL       this,EAX
//         00482548     MOV        EAX,0x80010003
//                              rmm_cntr.cpp:210 (66)
//         0048254d     PUSH       0xd2
//         00482552     IMUL       this
//         00482554     ADD        EDX,this
//         00482556     PUSH       s_C:\msdev\work\age1_x1\rmm_cntr.c               = "C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp"
//         0048255b     SAR        EDX,0xe
//         0048255e     MOV        this,EDX
//         00482560     SHR        this,0x1f
//         00482563     LEA        ESI,[EDX + this->field0_0x0*0x1 + 0x8]
//         00482567     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0048256c     MOV        EDX,dword ptr [EBX + 0x18]
//         0048256f     MOV        this,EAX
//         00482571     SUB        EDX,0x10
//         00482574     MOV        EAX,0x80010003
//         00482579     IMUL       this,EDX
//         0048257c     IMUL       this
//         0048257e     ADD        EDX,this
//         00482580     ADD        ESP,0x8
//         00482583     SAR        EDX,0xe
//         00482586     MOV        EAX,EDX
//         00482588     SHR        EAX,0x1f
//         0048258b     LEA        EBP,[EDX + EAX*0x1 + 0x8]
//                              rmm_cntr.cpp:212 (26)
//         0048258f     MOV        EAX,dword ptr [ESP + mid_x2]
//         00482593     CMP        ESI,EAX
//         00482595     JLE        LAB_004825b3
//         00482597     CMP        ESI,dword ptr [ESP + mid_y1]
//         0048259b     JGE        LAB_004825b3
//         0048259d     CMP        EBP,dword ptr [ESP + index2]
//         004825a1     JLE        LAB_004825b3
//         004825a3     CMP        EBP,dword ptr [ESP + local_28]
//         004825a7     JGE        LAB_004825b3
//                              rmm_cntr.cpp:213 (5)
//         004825a9     MOV        byte ptr [ESP + param_3],0x1
//                              rmm_cntr.cpp:214 (5)
//         004825ae     JMP        LAB_00482635
//                               LAB_004825b3                                                 XREF[4]:     00482595(j), 0048259b(j),
//                                                                                                         004825a1(j), 004825a7(j)
//                              rmm_cntr.cpp:215 (29)
//         004825b3     MOV        EAX,dword ptr [ESP + mid_x1]
//         004825b7     MOV        dword ptr [ESP + mid_y2],0x0
//         004825bf     TEST       EAX,EAX
//         004825c1     JLE        LAB_00482635
//         004825c3     MOV        this,dword ptr [ESP + param_1]
//         004825c7     LEA        EDX,[ECX + this->field8_0x8]
//                               LAB_004825ca                                                 XREF[1]:     0048262f(j)
//         004825ca     MOV        EAX,dword ptr [EDX]
//         004825cc     MOV        this,ESI
//         004825ce     SUB        this,EAX
//                              rmm_cntr.cpp:218 (2)
//         004825d0     JNS        LAB_004825d4
//                              rmm_cntr.cpp:219 (2)
//         004825d2     NEG        this
//                               LAB_004825d4                                                 XREF[1]:     004825d0(j)
//                              rmm_cntr.cpp:215 (7)
//         004825d4     MOV        EBX,dword ptr [EDX + 0x4]
//         004825d7     MOV        EAX,EBP
//         004825d9     SUB        EAX,EBX
//                              rmm_cntr.cpp:222 (2)
//         004825db     JNS        LAB_004825df
//                              rmm_cntr.cpp:223 (2)
//         004825dd     NEG        EAX
//                               LAB_004825df                                                 XREF[1]:     004825db(j)
//                              rmm_cntr.cpp:225 (31)
//         004825df     MOV        EBX,this
//         004825e1     IMUL       EBX,this
//         004825e4     MOV        this,EAX
//         004825e6     IMUL       this,EAX
//         004825e9     ADD        EBX,this
//         004825eb     MOV        dword ptr [ESP + Stack[-0x20]],EBX
//         004825ef     FILD       dword ptr [ESP + Stack[-0x20]]
//         004825f3     FCOMP      float ptr [ESP + local_18]
//         004825f7     FNSTSW     AX
//         004825f9     TEST       AH,0x41
//         004825fc     JZ         LAB_0048261d
//                              rmm_cntr.cpp:227 (21)
//         004825fe     MOV        AL,byte ptr [ESP + param_3]
//         00482602     TEST       AL,AL
//         00482604     JNZ        LAB_00482618
//         00482606     MOV        EAX,dword ptr [ESP + mid_x1]
//         0048260a     MOV        this,dword ptr [ESP + mid_y2]
//         0048260e     DEC        EAX
//         0048260f     CMP        this,EAX
//         00482611     JNZ        LAB_00482618
//                              rmm_cntr.cpp:229 (3)
//         00482613     MOV        dword ptr [EDX + 0x4],EBP
//                              rmm_cntr.cpp:230 (2)
//         00482616     MOV        dword ptr [EDX],ESI
//                               LAB_00482618                                                 XREF[2]:     00482604(j), 00482611(j)
//                              rmm_cntr.cpp:232 (5)
//         00482618     MOV        byte ptr [ESP + param_3],0x1
//                               LAB_0048261d                                                 XREF[1]:     004825fc(j)
//                              rmm_cntr.cpp:215 (24)
//         0048261d     MOV        EAX,dword ptr [ESP + mid_y2]
//         00482621     MOV        this,dword ptr [ESP + mid_x1]
//         00482625     INC        EAX
//         00482626     ADD        EDX,0x34
//         00482629     CMP        EAX,this
//         0048262b     MOV        dword ptr [ESP + mid_y2],EAX
//         0048262f     JL         LAB_004825ca
//         00482631     MOV        EBX,dword ptr [ESP + land_tile_num]
//                               LAB_00482635                                                 XREF[2]:     004825ae(j), 004825c1(j)
//                              rmm_cntr.cpp:206 (12)
//         00482635     MOV        AL,byte ptr [ESP + param_3]
//         00482639     TEST       AL,AL
//         0048263b     JNZ        switchD_004824eb::default
//                              rmm_cntr.cpp:238 (54)
//         00482641     MOV        EAX,dword ptr [ESP + local_10]
//         00482645     MOV        this,dword ptr [ESP + param_1]
//         00482649     CDQ
//         0048264a     MOV        dword ptr [EDI + -0xc],ESI
//         0048264d     MOV        dword ptr [EDI + -0x8],EBP
//         00482650     IDIV       dword ptr [this->field0_0x0 + 0x141c]
//         00482656     ADD        EDI,0x34
//         00482659     MOV        dword ptr [EDI + -0x48],EAX
//         0048265c     MOV        EAX,dword ptr [ESP + mid_x1]
//         00482660     MOV        EDX,dword ptr [this->field0_0x0 + 0x141c]
//         00482666     INC        EAX
//         00482667     CMP        EAX,EDX
//         00482669     MOV        dword ptr [ESP + mid_x1],EAX
//         0048266d     JL         LAB_004824dc
//         00482673     XOR        EBP,EBP
//         00482675     MOV        EDI,this
//                              language.dll match for 0x1468: "Stone path 5"
//                               LAB_00482677                                                 XREF[1]:     004824d1(j)
//                              rmm_cntr.cpp:241 (38)
//         00482677     PUSH       0x1468
//         0048267c     CALL       operator_new                                     void * operator_new(uint param_1)
//         00482681     ADD        ESP,0x4
//         00482684     MOV        dword ptr [ESP + param_1],EAX
//         00482688     CMP        EAX,EBP
//         0048268a     MOV        dword ptr [ESP + local_4],EBP
//         0048268e     JZ         LAB_0048269d
//         00482690     MOV        this,dword ptr [EBX + 0xc]
//         00482693     PUSH       EDI
//         00482694     PUSH       EBX
//         00482695     PUSH       this
//         00482696     MOV        this,EAX
//         00482698     CALL       RGE_RMM_Land_Generator::RGE_RMM_Land_Generator   undefined RGE_RMM_Land_Generator(RGE_RMM_Land
//                               LAB_0048269d                                                 XREF[1]:     0048268e(j)
//                              rmm_cntr.cpp:242 (59)
//         0048269d     MOV        this,dword ptr [ESP + local_c]
//         004826a1     POP        EDI
//         004826a2     POP        ESI
//         004826a3     POP        EBP
//         004826a4     MOV        dword ptr FS:[0x0],this
//         004826ab     POP        EBX
//         004826ac     ADD        ESP,0x3c
//         004826af     RET        0xc
    return;
}

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info* param_1, RGE_Land_Info* param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall add_terrain_module(RGE_RMM_Controller * this, RGE_Te
//              void              <VOID>         <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//              RGE_Terrain_In    Stack[0x4]:4   param_1                   XREF[2]:     004826fc(R), 00482850(W)
//              RGE_Land_Info *   Stack[0x8]:4   param_2                   XREF[1]:     004827fb(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     004826ee(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00482856(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00482869(R)
//                               ?add_terrain_module@RGE_RMM_Controller@@IAEXAAURGE_Terrain_  XREF[1]:     RGE_RMM_Controller:0048221e(c)
//                               RGE_RMM_Controller::add_terrain_module
//                              rmm_cntr.cpp:247 (14)
//         004826e0     MOV        EAX,FS:[0x0]
//         004826e6     PUSH       -0x1
//         004826e8     PUSH       FUN_0055e61b
//         004826ed     PUSH       EAX
//                              rmm_cntr.cpp:252 (50)
//         004826ee     MOV        EAX,dword ptr [ESP + param_3]
//         004826f2     MOV        dword ptr FS:[0x0],ESP
//         004826f9     PUSH       EBX
//         004826fa     PUSH       EBP
//         004826fb     PUSH       ESI
//         004826fc     MOV        ESI,dword ptr [ESP + param_1]
//         00482700     MOV        EBP,0x2
//         00482705     XOR        EBX,EBX
//         00482707     PUSH       EDI
//         00482708     CMP        EAX,0x4
//         0048270b     MOV        EDI,this
//         0048270d     MOV        dword ptr [ESI + 0xc60],EBP
//         00482713     JA         switchD_00482719::default
//                               switchD_00482719::switchD
//         00482719     JMP        dword ptr [EAX*0x4 + switchD_00482719::switchd   = 0048278a
//                               switchD_00482719::caseD_4                                    XREF[3]:     00482719(j), 0048288c(*),
//                               switchD_00482719::caseD_3                                                 00482890(*)
//                              rmm_cntr.cpp:256 (7)
//         00482720     MOV        EAX,dword ptr [EDI + 0x18]
//         00482723     IMUL       EAX,dword ptr [EDI + 0x14]
//                              rmm_cntr.cpp:257 (7)
//         00482727     MOV        dword ptr [ESI + 0x8],0xa
//                              rmm_cntr.cpp:258 (25)
//         0048272e     MOV        dword ptr [ESI + 0xc],0x1e
//         00482735     LEA        this,[EAX + EAX*0x4]
//         00482738     MOV        EAX,0x51eb851f
//         0048273d     SHL        this,0x2
//         00482740     IMUL       this
//         00482742     SAR        EDX,0x5
//         00482745     MOV        EAX,EDX
//                              rmm_cntr.cpp:259 (8)
//         00482747     MOV        dword ptr [ESI + 0x14],EBX
//         0048274a     SHR        EAX,0x1f
//         0048274d     ADD        EDX,EAX
//                              rmm_cntr.cpp:260 (5)
//         0048274f     MOV        dword ptr [ESI + 0x4],EBX
//         00482752     MOV        dword ptr [ESI],EDX
//                              rmm_cntr.cpp:261 (3)
//         00482754     MOV        dword ptr [ESI + 0x10],EBP
//                              rmm_cntr.cpp:262 (7)
//         00482757     MOV        EAX,dword ptr [EDI + 0x18]
//         0048275a     IMUL       EAX,dword ptr [EDI + 0x14]
//                              rmm_cntr.cpp:263 (7)
//         0048275e     MOV        dword ptr [ESI + 0x28],0x6
//                              rmm_cntr.cpp:264 (35)
//         00482765     MOV        dword ptr [ESI + 0x2c],0x11
//         0048276c     LEA        EAX,[EAX + EAX*0x2]
//         0048276f     LEA        this,[EAX + EAX*0x4]
//         00482772     MOV        EAX,0x51eb851f
//         00482777     SHL        this,0x1
//         00482779     IMUL       this
//         0048277b     SAR        EDX,0x5
//         0048277e     MOV        this,EDX
//         00482780     SHR        this,0x1f
//         00482783     ADD        EDX,this
//         00482785     MOV        dword ptr [ESI + 0x20],EDX
//                              rmm_cntr.cpp:268 (2)
//         00482788     JMP        LAB_004827f2
//                               switchD_00482719::caseD_1                                    XREF[4]:     00482719(j), 00482880(*),
//                               switchD_00482719::caseD_2                                                 00482884(*), 00482888(*)
//                               switchD_00482719::caseD_0
//                              rmm_cntr.cpp:272 (7)
//         0048278a     MOV        EAX,dword ptr [EDI + 0x18]
//         0048278d     IMUL       EAX,dword ptr [EDI + 0x14]
//                              rmm_cntr.cpp:273 (7)
//         00482791     MOV        dword ptr [ESI + 0x8],0xa
//                              rmm_cntr.cpp:274 (25)
//         00482798     MOV        dword ptr [ESI + 0xc],0x14
//         0048279f     LEA        this,[EAX + EAX*0x4]
//         004827a2     MOV        EAX,0x51eb851f
//         004827a7     SHL        this,0x2
//         004827aa     IMUL       this
//         004827ac     SAR        EDX,0x5
//         004827af     MOV        EAX,EDX
//                              rmm_cntr.cpp:275 (8)
//         004827b1     MOV        dword ptr [ESI + 0x14],EBX
//         004827b4     SHR        EAX,0x1f
//         004827b7     ADD        EDX,EAX
//                              rmm_cntr.cpp:276 (5)
//         004827b9     MOV        dword ptr [ESI + 0x4],EBX
//         004827bc     MOV        dword ptr [ESI],EDX
//                              rmm_cntr.cpp:277 (3)
//         004827be     MOV        dword ptr [ESI + 0x10],EBP
//                              rmm_cntr.cpp:278 (7)
//         004827c1     MOV        EAX,dword ptr [EDI + 0x18]
//         004827c4     IMUL       EAX,dword ptr [EDI + 0x14]
//                              rmm_cntr.cpp:279 (7)
//         004827c8     MOV        dword ptr [ESI + 0x28],0x6
//                              rmm_cntr.cpp:280 (35)
//         004827cf     MOV        dword ptr [ESI + 0x2c],0x7
//         004827d6     LEA        EAX,[EAX + EAX*0x2]
//         004827d9     LEA        this,[EAX + EAX*0x4]
//         004827dc     MOV        EAX,0x51eb851f
//         004827e1     SHL        this,0x1
//         004827e3     IMUL       this
//         004827e5     SAR        EDX,0x5
//         004827e8     MOV        this,EDX
//         004827ea     SHR        this,0x1f
//         004827ed     ADD        EDX,this
//         004827ef     MOV        dword ptr [ESI + 0x20],EDX
//                               LAB_004827f2                                                 XREF[1]:     00482788(j)
//                              rmm_cntr.cpp:281 (3)
//         004827f2     MOV        dword ptr [ESI + 0x34],EBX
//                              rmm_cntr.cpp:282 (3)
//         004827f5     MOV        dword ptr [ESI + 0x24],EBX
//                              rmm_cntr.cpp:283 (3)
//         004827f8     MOV        dword ptr [ESI + 0x30],EBX
//                               switchD_00482719::default                                    XREF[1]:     00482713(j)
//                              rmm_cntr.cpp:288 (4)
//         004827fb     MOV        this,dword ptr [ESP + param_2]
//                              rmm_cntr.cpp:289 (27)
//         004827ff     XOR        EDX,EDX
//         00482801     MOV        EAX,dword ptr [this->field0_0x0 + 0x141c]
//         00482807     CMP        EAX,EBX
//         00482809     MOV        dword ptr [ESI + 0x1294],EAX
//         0048280f     JLE        LAB_00482843
//         00482811     LEA        EAX,[ESI + 0xc68]
//         00482817     ADD        this,0xc
//                               LAB_0048281a                                                 XREF[1]:     00482841(j)
//                              rmm_cntr.cpp:291 (7)
//         0048281a     MOV        EBP,dword ptr [this->field0_0x0 + -0x4]
//         0048281d     INC        EDX
//         0048281e     MOV        dword ptr [EAX + -0x4],EBP
//                              rmm_cntr.cpp:292 (4)
//         00482821     MOV        EBP,dword ptr [this->field0_0x0]
//         00482823     MOV        dword ptr [EAX],EBP
//                              rmm_cntr.cpp:293 (7)
//         00482825     MOV        dword ptr [EAX + 0x4],0xc
//                              rmm_cntr.cpp:294 (23)
//         0048282c     MOV        dword ptr [EAX + 0x8],0x14
//         00482833     MOV        EBP,dword ptr [ESI + 0x1294]
//         00482839     ADD        this,0x34
//         0048283c     ADD        EAX,0x10
//         0048283f     CMP        EDX,EBP
//         00482841     JL         LAB_0048281a
//                               LAB_00482843                                                 XREF[1]:     0048280f(j)
//                              rmm_cntr.cpp:297 (38)
//         00482843     PUSH       0x12cc
//         00482848     CALL       operator_new                                     void * operator_new(uint param_1)
//         0048284d     ADD        ESP,0x4
//         00482850     MOV        dword ptr [ESP + param_1],EAX
//         00482854     CMP        EAX,EBX
//         00482856     MOV        dword ptr [ESP + local_4],EBX
//         0048285a     JZ         LAB_00482869
//         0048285c     MOV        EDX,dword ptr [EDI + 0xc]
//         0048285f     PUSH       ESI
//         00482860     PUSH       EDI
//         00482861     PUSH       EDX
//         00482862     MOV        this,EAX
//         00482864     CALL       RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Gen   undefined RGE_RMM_Terrain_Generator(RGE_RMM_T
//                               LAB_00482869                                                 XREF[1]:     0048285a(j)
//                              rmm_cntr.cpp:298 (43)
//         00482869     MOV        this,dword ptr [ESP + local_c]
//         0048286d     POP        EDI
//         0048286e     POP        ESI
//         0048286f     POP        EBP
//         00482870     MOV        dword ptr FS:[0x0],this
//         00482877     POP        EBX
//         00482878     ADD        ESP,0xc
//         0048287b     RET        0xc
    return;
}

long RGE_RMM_Controller::count_map_tiles(uchar param_1) {
    /* TODO: Stub */
//                              long __thiscall count_map_tiles(RGE_RMM_Controller * this, uchar par
//              long              EAX:4          <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?count_map_tiles@RGE_RMM_Controller@@IAEJE@Z
//                               RGE_RMM_Controller::count_map_tiles
//                              rmm_cntr.cpp:304 (7)
//         004828a0     MOV        EAX,dword ptr [ECX + this->field20_0x14]
//         004828a3     IMUL       EAX,dword ptr [ECX + this->field24_0x18]
//                              rmm_cntr.cpp:316 (3)
//         004828a7     RET        0x4
//         004828aa     ??         90h
//         004828ab     NOP
//         004828ac     NOP
//         004828ad     NOP
//         004828ae     NOP
//         004828af     NOP
    return 0;
}

void RGE_RMM_Controller::add_object_module(RGE_Game_World* param_1, RGE_Land_Info* param_2) {
    /* TODO: Stub */
//                              void __thiscall add_object_module(RGE_RMM_Controller * this, RGE_Gam
//              void              <VOID>         <RETURN>
//              RGE_RMM_Contro    ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     00482b2e(R)
//              RGE_Land_Info *   Stack[0x8]:4   param_2                   XREF[1]:     00482a8f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00482b25(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00482b4c(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00482ae4(W)
//              RGE_Object_Info   Stack[-0x18d   object_info               XREF[1,77]:  00482b1f(W), 00482926(W), 00482b35(*), 0048292e(W),
//                                                                                     00482932(W), 00482936(W), 0048293a(W), 0048293e(W),
//                                                                                     00482942(W), 00482946(W), 0048294a(W), 0048294e(W),
//                                                                                     00482952(W), 00482956(W), 0048295e(W), 00482962(W),
//                                                                                     00482966(W), 0048296a(W), 0048296e(W), 00482972(W)
//              undefined4        Stack[-0x18d   local_18dc                XREF[2]:     004828dc(W), 00482b3b(R)
//                               ?add_object_module@RGE_RMM_Controller@@IAEXPAVRGE_Game_Worl  XREF[1]:     RGE_RMM_Controller:00482235(c)
//                               RGE_RMM_Controller::add_object_module
//                              rmm_cntr.cpp:320 (34)
//         004828b0     PUSH       -0x1
//         004828b2     MOV        EAX,FS:[0x0]
//         004828b8     PUSH       FUN_0055e63e
//         004828bd     PUSH       EAX
//                              language.dll match for 0x18d0: "Build Fire Galley (G)"
//         004828be     MOV        EAX,0x18d0
//         004828c3     MOV        dword ptr FS:[0x0],ESP
//         004828ca     CALL       __alloca_probe                                   undefined __alloca_probe()
//         004828cf     PUSH       EBX
//         004828d0     PUSH       EBP
//         004828d1     PUSH       ESI
//                              rmm_cntr.cpp:324 (5)
//         004828d2     MOV        ESI,0x6
//                              rmm_cntr.cpp:348 (23)
//         004828d7     MOV        EBP,0x4
//         004828dc     MOV        dword ptr [ESP + local_18dc],this
//         004828e0     PUSH       EDI
//         004828e1     MOV        dword ptr [ESP + object_info.lands[0].x],ESI
//         004828e8     XOR        EBX,EBX
//         004828ea     MOV        dword ptr [ESP + object_info+0x5c],EBP
//                              rmm_cntr.cpp:354 (7)
//         004828ee     MOV        dword ptr [ESP + object_info+0x70],ESI
//                              rmm_cntr.cpp:367 (7)
//         004828f5     MOV        dword ptr [ESP + object_info+0xa0],ESI
//                              rmm_cntr.cpp:370 (7)
//         004828fc     MOV        dword ptr [ESP + object_info+0xac],EBP
//                              rmm_cntr.cpp:380 (30)
//         00482903     MOV        dword ptr [ESP + object_info+0xd0],ESI
//         0048290a     MOV        EDI,0x1
//         0048290f     OR         EAX,0xffffffff
//         00482912     MOV        EDX,0x3
//         00482917     MOV        this,0x2
//         0048291c     MOV        EBP,0xf
//                              rmm_cntr.cpp:386 (334)
//         00482921     MOV        ESI,0x9
//         00482926     MOV        dword ptr [ESP + object_info+0x4],0x6d
//         0048292e     MOV        dword ptr [ESP + object_info+0x8],EBX
//         00482932     MOV        byte ptr [ESP + object_info+0xc],BL
//         00482936     MOV        byte ptr [ESP + object_info+0xd],BL
//         0048293a     MOV        dword ptr [ESP + object_info+0x10],EDI
//         0048293e     MOV        dword ptr [ESP + object_info+0x14],EBX
//         00482942     MOV        dword ptr [ESP + object_info+0x18],EDI
//         00482946     MOV        dword ptr [ESP + object_info+0x20],EAX
//         0048294a     MOV        dword ptr [ESP + object_info+0x24],EBX
//         0048294e     MOV        dword ptr [ESP + object_info+0x28],EBX
//         00482952     MOV        dword ptr [ESP + object_info+0x2c],EBX
//         00482956     MOV        dword ptr [ESP + object_info+0x34],0x53
//         0048295e     MOV        dword ptr [ESP + object_info+0x38],EBX
//         00482962     MOV        byte ptr [ESP + object_info+0x3c],BL
//         00482966     MOV        byte ptr [ESP + object_info+0x3d],BL
//         0048296a     MOV        dword ptr [ESP + object_info+0x40],EDI
//         0048296e     MOV        dword ptr [ESP + object_info+0x44],EBX
//         00482972     MOV        dword ptr [ESP + object_info+0x48],EDX
//         00482976     MOV        dword ptr [ESP + object_info+0x50],EAX
//         0048297a     MOV        dword ptr [ESP + object_info+0x54],EBX
//         0048297e     MOV        dword ptr [ESP + object_info+0x58],this
//         00482982     MOV        dword ptr [ESP + object_info+0x64],0x41
//         0048298a     MOV        dword ptr [ESP + object_info+0x68],EBX
//         0048298e     MOV        byte ptr [ESP + object_info+0x6c],0x1
//         00482996     MOV        byte ptr [ESP + object_info+0x6d],0x1
//         0048299e     MOV        dword ptr [ESP + object_info+0x74],EDX
//         004829a5     MOV        dword ptr [ESP + object_info+0x78],0xa
//         004829b0     MOV        dword ptr [ESP + object_info+0x7c],EDX
//         004829b7     MOV        dword ptr [ESP + object_info+0x80],EBX
//         004829be     MOV        dword ptr [ESP + object_info+0x84],EAX
//         004829c5     MOV        dword ptr [ESP + object_info+0x88],EAX
//         004829cc     MOV        dword ptr [ESP + object_info+0x8c],EAX
//         004829d3     MOV        dword ptr [ESP + object_info+0x94],0x66
//         004829de     MOV        dword ptr [ESP + object_info+0x98],EAX
//         004829e5     MOV        byte ptr [ESP + object_info+0x9c],this
//         004829ec     MOV        byte ptr [ESP + object_info+0x9d],BL
//         004829f3     MOV        dword ptr [ESP + object_info+0xa4],this
//         004829fa     MOV        dword ptr [ESP + object_info+0xa8],EDI
//         00482a01     MOV        dword ptr [ESP + object_info+0xb0],EBX
//         00482a08     MOV        dword ptr [ESP + object_info+0xb4],EBX
//         00482a0f     MOV        dword ptr [ESP + object_info+0xb8],0x9
//         00482a1a     MOV        dword ptr [ESP + object_info+0xbc],EBP
//         00482a21     MOV        dword ptr [ESP + object_info+0xc4],0x42
//         00482a2c     MOV        dword ptr [ESP + object_info+0xc8],EAX
//         00482a33     MOV        byte ptr [ESP + object_info+0xcc],this
//         00482a3a     MOV        byte ptr [ESP + object_info+0xcd],BL
//         00482a41     MOV        dword ptr [ESP + object_info+0xd4],this
//         00482a48     MOV        dword ptr [ESP + object_info+0xd8],EDI
//         00482a4f     MOV        dword ptr [ESP + object_info+0xdc],0x4
//         00482a5a     MOV        dword ptr [ESP + object_info+0xe0],EBX
//         00482a61     MOV        dword ptr [ESP + object_info+0xe4],EBX
//         00482a68     MOV        dword ptr [ESP + object_info+0xe8],ESI
//                              rmm_cntr.cpp:387 (7)
//         00482a6f     MOV        dword ptr [ESP + object_info+0xec],EBP
//                              rmm_cntr.cpp:389 (11)
//         00482a76     MOV        dword ptr [ESP + object_info+0xf4],0x3b
//                              rmm_cntr.cpp:390 (7)
//         00482a81     MOV        dword ptr [ESP + object_info+0xf8],EAX
//                              rmm_cntr.cpp:396 (7)
//         00482a88     MOV        dword ptr [ESP + object_info+0x10c],EDX
//                              rmm_cntr.cpp:402 (27)
//         00482a8f     MOV        EDX,dword ptr [ESP + param_2]
//         00482a96     MOV        dword ptr [ESP + object_info+0x118],ESI
//         00482a9d     MOV        dword ptr [ESP + object_info+0x104],this
//         00482aa4     MOV        ESI,dword ptr [EDX + 0x141c]
//                              rmm_cntr.cpp:403 (77)
//         00482aaa     XOR        this,this
//         00482aac     CMP        ESI,EBX
//         00482aae     MOV        byte ptr [ESP + object_info+0xfc],0x1
//         00482ab6     MOV        byte ptr [ESP + object_info+0xfd],BL
//         00482abd     MOV        dword ptr [ESP + object_info+0x100],0x5
//         00482ac8     MOV        dword ptr [ESP + object_info+0x108],EDI
//         00482acf     MOV        dword ptr [ESP + object_info+0x110],EBX
//         00482ad6     MOV        dword ptr [ESP + object_info+0x114],EBX
//         00482add     MOV        dword ptr [ESP + object_info+0x11c],EBP
//         00482ae4     MOV        dword ptr [ESP + local_10],ESI
//         00482aeb     JLE        LAB_00482b12
//         00482aed     LEA        EAX=>object_info+0x129c,[ESP + 0x12b0]
//         00482af4     ADD        EDX,0xc
//                               LAB_00482af7                                                 XREF[1]:     00482b10(j)
//                              rmm_cntr.cpp:405 (7)
//         00482af7     MOV        EBP,dword ptr [EDX + -0x4]
//         00482afa     INC        this
//         00482afb     MOV        dword ptr [EAX + object_info+0x1298],EBP
//                              rmm_cntr.cpp:406 (4)
//         00482afe     MOV        EBP,dword ptr [EDX]
//         00482b00     MOV        dword ptr [EAX]=>object_info+0x129c,EBP
//                              rmm_cntr.cpp:407 (3)
//         00482b02     MOV        dword ptr [EAX + object_info+0x12a0],EBX
//                              rmm_cntr.cpp:408 (13)
//         00482b05     MOV        dword ptr [EAX + object_info+0x12a4],this
//         00482b08     ADD        EDX,0x34
//         00482b0b     ADD        EAX,0x10
//         00482b0e     CMP        this,ESI
//         00482b10     JL         LAB_00482af7
//                               LAB_00482b12                                                 XREF[1]:     00482aeb(j)
//                              rmm_cntr.cpp:411 (58)
//         00482b12     PUSH       0x1920
//         00482b17     CALL       operator_new                                     void * operator_new(uint param_1)
//         00482b1c     ADD        ESP,0x4
//         00482b1f     MOV        dword ptr [ESP + object_info.objects[0].obj_id
//         00482b23     CMP        EAX,EBX
//         00482b25     MOV        dword ptr [ESP + local_4],EBX
//         00482b2c     JZ         LAB_00482b4c
//         00482b2e     MOV        EDX,dword ptr [ESP + param_1]
//         00482b35     LEA        this=>object_info+0x4,[ESP + 0x18]
//         00482b39     PUSH       EDI
//         00482b3a     PUSH       this
//         00482b3b     MOV        this,dword ptr [ESP + local_18dc]
//         00482b3f     PUSH       EDX
//         00482b40     PUSH       this
//         00482b41     MOV        this,dword ptr [ECX + this->field12_0xc]
//         00482b44     PUSH       this
//         00482b45     MOV        this,EAX
//         00482b47     CALL       RGE_RMM_Object_Generator::RGE_RMM_Object_Gener   undefined RGE_RMM_Object_Generator(RGE_RMM_Ob
//                               LAB_00482b4c                                                 XREF[1]:     00482b2c(j)
//                              rmm_cntr.cpp:412 (27)
//         00482b4c     MOV        this,dword ptr [ESP + local_c]
//         00482b53     POP        EDI
//         00482b54     POP        ESI
//         00482b55     POP        EBP
//         00482b56     MOV        dword ptr FS:[0x0],this
//         00482b5d     POP        EBX
//         00482b5e     ADD        ESP,0x18dc
//         00482b64     RET        0x8
//         00482b67     ??         90h
//         00482b68     NOP
//         00482b69     NOP
//         00482b6a     NOP
//         00482b6b     NOP
//         00482b6c     NOP
//         00482b6d     NOP
//         00482b6e     NOP
//         00482b6f     NOP
    return;
}

