#include "common.h"
#include "rmm_cntr.h"

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
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004826b2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004826b2
    //         004826b2     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004822ad::switchdataD_004826b4                       XREF[1]:     add_land_module:004822ad(*)  
    //         004826b4     addr       switchD_004822ad::caseD_0
    //         004826b8     addr       switchD_004822ad::caseD_1
    //         004826bc     addr       switchD_004822ad::caseD_2
    //         004826c0     addr       switchD_004822ad::caseD_3
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004824eb::switchdataD_004826c4                       XREF[1]:     add_land_module:004824eb(*)  
    //         004826c4     addr       switchD_004824eb::caseD_0
    //         004826c8     addr       switchD_004824eb::caseD_1
    //         004826cc     addr       switchD_004824eb::caseD_2
    //         004826d0     addr       switchD_004824eb::caseD_2
    //         004826d4     addr       switchD_004824eb::caseD_2
    //         004826d8     ??         90h
    //         004826d9     ??         90h
    //         004826da     ??         90h
    //         004826db     ??         90h
    //         004826dc     ??         90h
    //         004826dd     ??         90h
    //         004826de     ??         90h
    //         004826df     ??         90h
    //                              * protected: void __thiscall RGE_RMM_Controller::add_terrain_module(struct RGE_Terrain_Info &,struct... *
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
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048287e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048287e
    //         0048287e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00482719::switchdataD_00482880                       XREF[1]:     add_terrain_module:00482719(*)  
    //         00482880     addr       switchD_00482719::caseD_0
    //         00482884     addr       switchD_00482719::caseD_0
    //         00482888     addr       switchD_00482719::caseD_0
    //         0048288c     addr       switchD_00482719::caseD_3
    //         00482890     addr       switchD_00482719::caseD_3
    //         00482894     ??         90h
    //         00482895     ??         90h
    //         00482896     ??         90h
    //         00482897     ??         90h
    //         00482898     ??         90h
    //         00482899     ??         90h
    //         0048289a     ??         90h
    //         0048289b     ??         90h
    //         0048289c     ??         90h
    //         0048289d     ??         90h
    //         0048289e     ??         90h
    //         0048289f     ??         90h
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
    //                              * protected: void __thiscall RGE_RMM_Controller::add_object_module(class RGE_Game_World *,struct RGE... *
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
    //                              * public: __thiscall RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(char *,char *,char *,c... *
    //                              undefined __thiscall RGE_RMM_Database_Controller(RGE_RMM_Database_Co
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Databa    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00482c52(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00482dd1(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00482ec6(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[10]:    00482b87(R), 00482c8b(W), 00482db3(R), 00482dbe(W), 
    //                                                                                     00482e06(W), 00482ea8(R), 00482eb3(W), 00482efb(W), 
    //                                                                                     00482fc6(R), 00482fd1(W)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[2]:     00482f7f(*), 00482fac(R)  
    //              long              Stack[-0x8]:4  temp_scale_flag           XREF[2]:     00482f85(*), 00482f9d(R)  
    //              long              Stack[-0xc]:4  temp_group_flag           XREF[2]:     00482d1e(*), 00482d8b(R)  
    //              long              Stack[-0x10]:4 temp_by_player_flag       XREF[2]:     00482d24(*), 00482d80(R)  
    //              long              Stack[-0x14]:4 temp_amount_of_land_used  XREF[2]:     00482d30(*), 00482d75(R)  
    //              long              Stack[-0x18]:4 temp_placement_type       XREF[2]:     00482d36(*), 00482d6a(R)  
    //              long              Stack[-0x1c]:4 temp_zone                 XREF[2]:     00482d42(*), 00482d5b(R)  
    //              long              Stack[-0x20]:4 temp_terrain_type         XREF[3]:     00482ee2(*), 00482ef2(R), 00482fca(R)  
    //              long              Stack[-0x24]:4 object_num                XREF[3]:     00482ded(*), 00482dfd(R), 00482eac(R)  
    //              long              Stack[-0x28]:4 terrain_num               XREF[3]:     00482c72(*), 00482c82(R), 00482db7(R)  
    //              long              Stack[-0x2c]:4 land_num                  XREF[4]:     00482b7e(W), 00482dab(R), 00482e9f(R), 00482fbd(R)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[6]:     00482c99(*), 00482ca9(R), 00482e14(*), 00482e24(R), 
    //                                                                                     00482f09(*), 00482f19(R)  
    //              long              Stack[-0x34]:4 map_id                    XREF[6]:     00482bb0(W), 00482bfa(R), 00482c18(R), 00482c68(W), 
    //                                                                                     00482d47(R), 00482daf(R)  
    //              _iobuf *          Stack[-0x38]:4 infile
    //                               ??0RGE_RMM_Database_Controller@@QAE@PAD000@Z                 XREF[2]:     load_random_map:0045586c(c), 
    //                               RGE_RMM_Database_Controller::RGE_RMM_Database_Controller                  TRIBE_RMM_Database_Controller:0048
    //                              rmm_dbct.cpp:29 (23)
    //         00482b70     SUB        ESP,0x34
    //         00482b73     PUSH       EBX
    //         00482b74     PUSH       EBP
    //         00482b75     PUSH       ESI
    //         00482b76     XOR        ESI,ESI
    //         00482b78     PUSH       EDI
    //         00482b79     PUSH       ESI
    //         00482b7a     MOV        EDI,this
    //         00482b7c     PUSH       ESI
    //         00482b7d     PUSH       ESI
    //         00482b7e     MOV        dword ptr [ESP + land_num],EDI
    //         00482b82     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_dbct.cpp:55 (39)
    //         00482b87     MOV        EAX,dword ptr [ESP + param_4]
    //         00482b8b     PUSH       s_r                                              = "r"
    //         00482b90     PUSH       EAX
    //         00482b91     MOV        dword ptr [EDI],RGE_RMM_Database_Controller::`   = 00483430
    //         00482b97     MOV        dword ptr [EDI + 0x30],ESI
    //         00482b9a     MOV        dword ptr [EDI + 0x34],0xffffffff
    //         00482ba1     MOV        dword ptr [EDI + 0x38],ESI
    //         00482ba4     CALL       fopen                                            undefined fopen()
    //         00482ba9     MOV        EBX,EAX
    //         00482bab     ADD        ESP,0x8
    //                              rmm_dbct.cpp:56 (12)
    //         00482bae     CMP        EBX,ESI
    //         00482bb0     MOV        dword ptr [ESP + map_id],EBX
    //         00482bb4     JZ         LAB_00482c3a
    //                              rmm_dbct.cpp:58 (18)
    //         00482bba     LEA        EBP,[EDI + 0x4f54]
    //         00482bc0     PUSH       EBP
    //         00482bc1     PUSH       s__%d                                            = " %d"
    //         00482bc6     PUSH       EBX
    //         00482bc7     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:60 (10)
    //         00482bcc     MOV        EAX,dword ptr [EBP]
    //         00482bcf     ADD        ESP,0xc
    //         00482bd2     CMP        EAX,ESI
    //         00482bd4     JLE        LAB_00482c29
    //                              rmm_dbct.cpp:62 (14)
    //         00482bd6     PUSH       0x48
    //         00482bd8     PUSH       EAX
    //         00482bd9     CALL       calloc                                           undefined calloc()
    //         00482bde     MOV        dword ptr [EDI + 0x4f58],EAX
    //                              rmm_dbct.cpp:63 (10)
    //         00482be4     MOV        EAX,dword ptr [EBP]
    //         00482be7     ADD        ESP,0x8
    //         00482bea     CMP        EAX,ESI
    //         00482bec     JLE        LAB_00482c2f
    //                              rmm_dbct.cpp:242 (2)
    //         00482bee     XOR        EBX,EBX
    //                               LAB_00482bf0                                                 XREF[1]:     00482c16(j)  
    //                              rmm_dbct.cpp:64 (40)
    //         00482bf0     MOV        EDX,dword ptr [EDI + 0x4f58]
    //         00482bf6     MOV        this,EBX
    //         00482bf8     ADD        this,EDX
    //         00482bfa     MOV        EDX,dword ptr [ESP + map_id]
    //         00482bfe     PUSH       this
    //         00482bff     PUSH       s_%d                                             = 6425h
    //         00482c04     PUSH       EDX
    //         00482c05     CALL       fscanf                                           undefined fscanf()
    //         00482c0a     MOV        EAX,dword ptr [EBP]
    //         00482c0d     ADD        ESP,0xc
    //         00482c10     INC        ESI
    //         00482c11     ADD        EBX,0x48
    //         00482c14     CMP        ESI,EAX
    //         00482c16     JL         LAB_00482bf0
    //                              rmm_dbct.cpp:66 (6)
    //         00482c18     MOV        EBX,dword ptr [ESP + map_id]
    //         00482c1c     XOR        ESI,ESI
    //                              rmm_dbct.cpp:69 (9)
    //         00482c1e     PUSH       EBX
    //         00482c1f     CALL       fclose                                           undefined fclose()
    //         00482c24     ADD        ESP,0x4
    //                              rmm_dbct.cpp:71 (2)
    //         00482c27     JMP        LAB_00482c49
    //                               LAB_00482c29                                                 XREF[1]:     00482bd4(j)  
    //                              rmm_dbct.cpp:67 (6)
    //         00482c29     MOV        dword ptr [EDI + 0x4f58],ESI
    //                               LAB_00482c2f                                                 XREF[1]:     00482bec(j)  
    //                              rmm_dbct.cpp:69 (9)
    //         00482c2f     PUSH       EBX
    //         00482c30     CALL       fclose                                           undefined fclose()
    //         00482c35     ADD        ESP,0x4
    //                              rmm_dbct.cpp:71 (2)
    //         00482c38     JMP        LAB_00482c49
    //                               LAB_00482c3a                                                 XREF[1]:     00482bb4(j)  
    //                              rmm_dbct.cpp:74 (15)
    //         00482c3a     LEA        EBP,[EDI + 0x4f54]
    //         00482c40     MOV        dword ptr [EDI + 0x4f58],ESI
    //         00482c46     MOV        dword ptr [EBP],ESI
    //                               LAB_00482c49                                                 XREF[2]:     00482c27(j), 00482c38(j)  
    //                              rmm_dbct.cpp:77 (9)
    //         00482c49     CMP        dword ptr [EBP],ESI
    //         00482c4c     JLE        LAB_00482ff0
    //                              rmm_dbct.cpp:81 (20)
    //         00482c52     MOV        EAX,dword ptr [ESP + param_1]
    //         00482c56     PUSH       s_r                                              = "r"
    //         00482c5b     PUSH       EAX
    //         00482c5c     CALL       fopen                                            undefined fopen()
    //         00482c61     MOV        EBP,EAX
    //         00482c63     ADD        ESP,0x8
    //                              rmm_dbct.cpp:82 (12)
    //         00482c66     TEST       EBP,EBP
    //         00482c68     MOV        dword ptr [ESP + map_id],EBP
    //         00482c6c     JZ         LAB_00482dd1
    //                              rmm_dbct.cpp:84 (16)
    //         00482c72     LEA        this=>terrain_num,[ESP + 0x1c]
    //         00482c76     PUSH       this
    //         00482c77     PUSH       s_%d                                             = 6425h
    //         00482c7c     PUSH       EBP
    //         00482c7d     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:85 (23)
    //         00482c82     MOV        EAX,dword ptr [ESP + terrain_num]
    //         00482c86     ADD        ESP,0xc
    //         00482c89     TEST       EAX,EAX
    //         00482c8b     MOV        dword ptr [ESP + param_4],0x0
    //         00482c93     JLE        LAB_00482dc8
    //                               LAB_00482c99                                                 XREF[1]:     00482dc2(j)  
    //                              rmm_dbct.cpp:87 (16)
    //         00482c99     LEA        EDX=>local_30,[ESP + 0x14]
    //         00482c9d     PUSH       EDX
    //         00482c9e     PUSH       s_%d                                             = 6425h
    //         00482ca3     PUSH       EBP
    //         00482ca4     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:88 (20)
    //         00482ca9     MOV        EAX,dword ptr [ESP + local_30]
    //         00482cad     MOV        this,dword ptr [EDI + 0x4f58]
    //         00482cb3     ADD        ESP,0xc
    //         00482cb6     LEA        EAX,[EAX + EAX*0x8]
    //         00482cb9     LEA        ESI,[ECX + EAX*0x8 + this->_padding_]
    //                              rmm_dbct.cpp:98 (44)
    //         00482cbd     LEA        EDX,[ESI + 0x1c]
    //         00482cc0     LEA        EAX,[ESI + 0x18]
    //         00482cc3     PUSH       EDX
    //         00482cc4     LEA        this,[ESI + 0x14]
    //         00482cc7     PUSH       EAX
    //         00482cc8     LEA        EDX,[ESI + 0x10]
    //         00482ccb     PUSH       this
    //         00482ccc     LEA        EAX,[ESI + 0xc]
    //         00482ccf     PUSH       EDX
    //         00482cd0     LEA        this,[ESI + 0x8]
    //         00482cd3     PUSH       EAX
    //         00482cd4     LEA        EDX,[ESI + 0x4]
    //         00482cd7     PUSH       this
    //         00482cd8     LEA        EBX,[ESI + 0x24]
    //         00482cdb     PUSH       EDX
    //         00482cdc     PUSH       ESI
    //         00482cdd     PUSH       EBX
    //         00482cde     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d                     = "%d %d %d %d %d %d %d %d %d"
    //         00482ce3     PUSH       EBP
    //         00482ce4     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:100 (13)
    //         00482ce9     MOV        EAX,dword ptr [EBX]
    //         00482ceb     ADD        ESP,0x2c
    //         00482cee     TEST       EAX,EAX
    //         00482cf0     JLE        LAB_00483005
    //                              rmm_dbct.cpp:102 (11)
    //         00482cf6     PUSH       0x2c
    //         00482cf8     PUSH       EAX
    //         00482cf9     CALL       calloc                                           undefined calloc()
    //         00482cfe     MOV        dword ptr [ESI + 0x28],EAX
    //                              rmm_dbct.cpp:103 (15)
    //         00482d01     MOV        EAX,dword ptr [EBX]
    //         00482d03     ADD        ESP,0x8
    //         00482d06     XOR        EBP,EBP
    //         00482d08     TEST       EAX,EAX
    //         00482d0a     JLE        LAB_00482daf
    //                              rmm_dbct.cpp:242 (2)
    //         00482d10     XOR        EDI,EDI
    //                               LAB_00482d12                                                 XREF[1]:     00482da5(j)  
    //                              rmm_dbct.cpp:117 (70)
    //         00482d12     MOV        EAX,dword ptr [ESI + 0x28]
    //         00482d15     ADD        EAX,EDI
    //         00482d17     LEA        this,[EAX + 0x24]
    //         00482d1a     LEA        EDX,[EAX + 0x20]
    //         00482d1d     PUSH       this
    //         00482d1e     LEA        this=>temp_group_flag,[ESP + 0x3c]
    //         00482d22     PUSH       EDX
    //         00482d23     PUSH       this
    //         00482d24     LEA        EDX=>temp_by_player_flag,[ESP + 0x40]
    //         00482d28     LEA        this,[EAX + 0x18]
    //         00482d2b     PUSH       EDX
    //         00482d2c     PUSH       this
    //         00482d2d     LEA        EDX,[EAX + 0x14]
    //         00482d30     LEA        this=>temp_amount_of_land_used_percent,[ESP + 
    //         00482d34     PUSH       EDX
    //         00482d35     PUSH       this
    //         00482d36     LEA        EDX=>temp_placement_type,[ESP + 0x48]
    //         00482d3a     LEA        this,[EAX + 0xc]
    //         00482d3d     PUSH       EDX
    //         00482d3e     PUSH       this
    //         00482d3f     LEA        EDX,[EAX + 0x8]
    //         00482d42     LEA        this=>temp_zone,[ESP + 0x4c]
    //         00482d46     PUSH       EDX
    //         00482d47     MOV        EDX,dword ptr [ESP + map_id]
    //         00482d4b     PUSH       this
    //         00482d4c     PUSH       EAX
    //         00482d4d     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d               = "%d %d %d %d %d %d %d %d %d %d %d %d"
    //         00482d52     PUSH       EDX
    //         00482d53     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:119 (15)
    //         00482d58     MOV        EAX,dword ptr [ESI + 0x28]
    //         00482d5b     MOV        this,byte ptr [ESP + temp_zone]
    //         00482d5f     ADD        ESP,0x38
    //         00482d62     INC        EBP
    //         00482d63     MOV        byte ptr [EAX + EDI*0x1 + 0x4],this
    //                              rmm_dbct.cpp:120 (11)
    //         00482d67     MOV        EDX,dword ptr [ESI + 0x28]
    //         00482d6a     MOV        AL,byte ptr [ESP + temp_placement_type]
    //         00482d6e     MOV        byte ptr [EDX + EDI*0x1 + 0x10],AL
    //                              rmm_dbct.cpp:121 (11)
    //         00482d72     MOV        this,dword ptr [ESI + 0x28]
    //         00482d75     MOV        DL,byte ptr [ESP + temp_amount_of_land_used_pe
    //         00482d79     MOV        byte ptr [ECX + EDI*0x1 + this+0x11],DL
    //                              rmm_dbct.cpp:122 (11)
    //         00482d7d     MOV        EAX,dword ptr [ESI + 0x28]
    //         00482d80     MOV        this,byte ptr [ESP + temp_by_player_flag]
    //         00482d84     MOV        byte ptr [EAX + EDI*0x1 + 0x1c],this
    //                              rmm_dbct.cpp:123 (11)
    //         00482d88     MOV        EDX,dword ptr [ESI + 0x28]
    //         00482d8b     MOV        AL,byte ptr [ESP + temp_group_flag]
    //         00482d8f     MOV        byte ptr [EDX + EDI*0x1 + 0x1d],AL
    //                              rmm_dbct.cpp:125 (24)
    //         00482d93     MOV        this,dword ptr [ESI + 0x28]
    //         00482d96     MOV        dword ptr [ECX + EDI*0x1 + this->_padding_],0x8
    //         00482d9e     MOV        EAX,dword ptr [EBX]
    //         00482da0     ADD        EDI,0x2c
    //         00482da3     CMP        EBP,EAX
    //         00482da5     JL         LAB_00482d12
    //                              rmm_dbct.cpp:128 (8)
    //         00482dab     MOV        EDI,dword ptr [ESP + land_num]
    //                               LAB_00482daf                                                 XREF[1]:     00482d0a(j)  
    //         00482daf     MOV        EBP,dword ptr [ESP + map_id]
    //                               LAB_00482db3                                                 XREF[1]:     0048300c(j)  
    //                              rmm_dbct.cpp:85 (21)
    //         00482db3     MOV        EAX,dword ptr [ESP + param_4]
    //         00482db7     MOV        this,dword ptr [ESP + terrain_num]
    //         00482dbb     INC        EAX
    //         00482dbc     CMP        EAX,this
    //         00482dbe     MOV        dword ptr [ESP + param_4],EAX
    //         00482dc2     JL         LAB_00482c99
    //                               LAB_00482dc8                                                 XREF[1]:     00482c93(j)  
    //                              rmm_dbct.cpp:131 (9)
    //         00482dc8     PUSH       EBP
    //         00482dc9     CALL       fclose                                           undefined fclose()
    //         00482dce     ADD        ESP,0x4
    //                               LAB_00482dd1                                                 XREF[1]:     00482c6c(j)  
    //                              rmm_dbct.cpp:135 (20)
    //         00482dd1     MOV        EDX,dword ptr [ESP + param_2]
    //         00482dd5     PUSH       s_r                                              = "r"
    //         00482dda     PUSH       EDX
    //         00482ddb     CALL       fopen                                            undefined fopen()
    //         00482de0     MOV        EBP,EAX
    //         00482de2     ADD        ESP,0x8
    //                              rmm_dbct.cpp:136 (8)
    //         00482de5     TEST       EBP,EBP
    //         00482de7     JZ         LAB_00482ec6
    //                              rmm_dbct.cpp:138 (16)
    //         00482ded     LEA        EAX=>object_num,[ESP + 0x20]
    //         00482df1     PUSH       EAX
    //         00482df2     PUSH       s_%d                                             = 6425h
    //         00482df7     PUSH       EBP
    //         00482df8     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:139 (23)
    //         00482dfd     MOV        EAX,dword ptr [ESP + object_num]
    //         00482e01     ADD        ESP,0xc
    //         00482e04     TEST       EAX,EAX
    //         00482e06     MOV        dword ptr [ESP + param_4],0x0
    //         00482e0e     JLE        LAB_00482ebd
    //                               LAB_00482e14                                                 XREF[1]:     00482eb7(j)  
    //                              rmm_dbct.cpp:141 (16)
    //         00482e14     LEA        this=>local_30,[ESP + 0x14]
    //         00482e18     PUSH       this
    //         00482e19     PUSH       s_%d                                             = 6425h
    //         00482e1e     PUSH       EBP
    //         00482e1f     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:142 (20)
    //         00482e24     MOV        EAX,dword ptr [ESP + local_30]
    //         00482e28     ADD        ESP,0xc
    //         00482e2b     LEA        EDX,[EAX + EAX*0x8]
    //         00482e2e     MOV        EAX,dword ptr [EDI + 0x4f58]
    //         00482e34     LEA        ESI,[EAX + EDX*0x8 + 0x30]
    //                              rmm_dbct.cpp:143 (12)
    //         00482e38     PUSH       ESI
    //         00482e39     PUSH       s_%d                                             = 6425h
    //         00482e3e     PUSH       EBP
    //         00482e3f     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:145 (11)
    //         00482e44     MOV        EAX,dword ptr [ESI]
    //         00482e46     XOR        EBX,EBX
    //         00482e48     ADD        ESP,0xc
    //         00482e4b     CMP        EAX,EBX
    //         00482e4d     JLE        LAB_00482ea5
    //                              rmm_dbct.cpp:147 (11)
    //         00482e4f     PUSH       0x18
    //         00482e51     PUSH       EAX
    //         00482e52     CALL       calloc                                           undefined calloc()
    //         00482e57     MOV        dword ptr [ESI + 0x4],EAX
    //                              rmm_dbct.cpp:148 (9)
    //         00482e5a     MOV        EAX,dword ptr [ESI]
    //         00482e5c     ADD        ESP,0x8
    //         00482e5f     TEST       EAX,EAX
    //         00482e61     JLE        LAB_00482ea8
    //                              rmm_dbct.cpp:242 (2)
    //         00482e63     XOR        EDI,EDI
    //                               LAB_00482e65                                                 XREF[1]:     00482e9d(j)  
    //                              rmm_dbct.cpp:155 (34)
    //         00482e65     MOV        this,dword ptr [ESI + 0x4]
    //         00482e68     LEA        EAX,[this->_padding_ + EDI*0x1]
    //         00482e6b     LEA        EDX,[EAX + 0x10]
    //         00482e6e     LEA        this,[EAX + 0xc]
    //         00482e71     PUSH       EDX
    //         00482e72     PUSH       this
    //         00482e73     LEA        EDX,[EAX + 0x8]
    //         00482e76     LEA        this,[EAX + 0x4]
    //         00482e79     PUSH       EDX
    //         00482e7a     PUSH       this
    //         00482e7b     PUSH       EAX
    //         00482e7c     PUSH       s_%d_%d_%d_%d_%d                                 = "%d %d %d %d %d"
    //         00482e81     PUSH       EBP
    //         00482e82     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:156 (24)
    //         00482e87     MOV        EDX,dword ptr [ESI + 0x4]
    //         00482e8a     ADD        ESP,0x1c
    //         00482e8d     INC        EBX
    //         00482e8e     MOV        dword ptr [EDX + EDI*0x1 + 0x14],0x14
    //         00482e96     MOV        EAX,dword ptr [ESI]
    //         00482e98     ADD        EDI,0x18
    //         00482e9b     CMP        EBX,EAX
    //         00482e9d     JL         LAB_00482e65
    //                              rmm_dbct.cpp:159 (6)
    //         00482e9f     MOV        EDI,dword ptr [ESP + land_num]
    //         00482ea3     JMP        LAB_00482ea8
    //                               LAB_00482ea5                                                 XREF[1]:     00482e4d(j)  
    //                              rmm_dbct.cpp:160 (3)
    //         00482ea5     MOV        dword ptr [ESI + 0x4],EBX
    //                               LAB_00482ea8                                                 XREF[2]:     00482e61(j), 00482ea3(j)  
    //                              rmm_dbct.cpp:139 (21)
    //         00482ea8     MOV        EAX,dword ptr [ESP + param_4]
    //         00482eac     MOV        this,dword ptr [ESP + object_num]
    //         00482eb0     INC        EAX
    //         00482eb1     CMP        EAX,this
    //         00482eb3     MOV        dword ptr [ESP + param_4],EAX
    //         00482eb7     JL         LAB_00482e14
    //                               LAB_00482ebd                                                 XREF[1]:     00482e0e(j)  
    //                              rmm_dbct.cpp:162 (9)
    //         00482ebd     PUSH       EBP
    //         00482ebe     CALL       fclose                                           undefined fclose()
    //         00482ec3     ADD        ESP,0x4
    //                               LAB_00482ec6                                                 XREF[1]:     00482de7(j)  
    //                              rmm_dbct.cpp:166 (20)
    //         00482ec6     MOV        EAX,dword ptr [ESP + param_3]
    //         00482eca     PUSH       s_r                                              = "r"
    //         00482ecf     PUSH       EAX
    //         00482ed0     CALL       fopen                                            undefined fopen()
    //         00482ed5     MOV        EBP,EAX
    //         00482ed7     ADD        ESP,0x8
    //                              rmm_dbct.cpp:167 (8)
    //         00482eda     TEST       EBP,EBP
    //         00482edc     JZ         LAB_00482ff9
    //                              rmm_dbct.cpp:169 (16)
    //         00482ee2     LEA        this=>temp_terrain_type,[ESP + 0x24]
    //         00482ee6     PUSH       this
    //         00482ee7     PUSH       s_%d                                             = 6425h
    //         00482eec     PUSH       EBP
    //         00482eed     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:170 (23)
    //         00482ef2     MOV        EAX,dword ptr [ESP + temp_terrain_type]
    //         00482ef6     ADD        ESP,0xc
    //         00482ef9     TEST       EAX,EAX
    //         00482efb     MOV        dword ptr [ESP + param_4],0x0
    //         00482f03     JLE        LAB_00482fdb
    //                               LAB_00482f09                                                 XREF[1]:     00482fd5(j)  
    //                              rmm_dbct.cpp:172 (16)
    //         00482f09     LEA        EDX=>local_30,[ESP + 0x14]
    //         00482f0d     PUSH       EDX
    //         00482f0e     PUSH       s_%d                                             = 6425h
    //         00482f13     PUSH       EBP
    //         00482f14     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:173 (20)
    //         00482f19     MOV        EAX,dword ptr [ESP + local_30]
    //         00482f1d     MOV        this,dword ptr [EDI + 0x4f58]
    //         00482f23     ADD        ESP,0xc
    //         00482f26     LEA        EAX,[EAX + EAX*0x8]
    //         00482f29     LEA        ESI,[ECX + EAX*0x8 + this->number_of_players]
    //                              rmm_dbct.cpp:174 (12)
    //         00482f2d     PUSH       ESI
    //         00482f2e     PUSH       s_%d                                             = 6425h
    //         00482f33     PUSH       EBP
    //         00482f34     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:176 (11)
    //         00482f39     MOV        EAX,dword ptr [ESI]
    //         00482f3b     XOR        EBX,EBX
    //         00482f3d     ADD        ESP,0xc
    //         00482f40     CMP        EAX,EBX
    //         00482f42     JLE        LAB_00482fc3
    //                              rmm_dbct.cpp:178 (11)
    //         00482f44     PUSH       0x2c
    //         00482f46     PUSH       EAX
    //         00482f47     CALL       calloc                                           undefined calloc()
    //         00482f4c     MOV        dword ptr [ESI + 0x4],EAX
    //                              rmm_dbct.cpp:179 (9)
    //         00482f4f     MOV        EAX,dword ptr [ESI]
    //         00482f51     ADD        ESP,0x8
    //         00482f54     TEST       EAX,EAX
    //         00482f56     JLE        LAB_00482fc6
    //                              rmm_dbct.cpp:242 (2)
    //         00482f58     XOR        EDI,EDI
    //                               LAB_00482f5a                                                 XREF[1]:     00482fbb(j)  
    //                              rmm_dbct.cpp:193 (64)
    //         00482f5a     MOV        EDX,dword ptr [ESI + 0x4]
    //         00482f5d     LEA        EAX,[EDX + EDI*0x1]
    //         00482f60     LEA        this,[EAX + 0x28]
    //         00482f63     LEA        EDX,[EAX + 0x24]
    //         00482f66     PUSH       this
    //         00482f67     LEA        this,[EAX + 0x20]
    //         00482f6a     PUSH       EDX
    //         00482f6b     PUSH       this
    //         00482f6c     LEA        EDX,[EAX + 0x1c]
    //         00482f6f     LEA        this,[EAX + 0x18]
    //         00482f72     PUSH       EDX
    //         00482f73     PUSH       this
    //         00482f74     LEA        EDX,[EAX + 0x14]
    //         00482f77     LEA        this,[EAX + 0x10]
    //         00482f7a     PUSH       EDX
    //         00482f7b     PUSH       this
    //         00482f7c     LEA        EDX,[EAX + 0xc]
    //         00482f7f     LEA        this=>local_4,[ESP + 0x5c]
    //         00482f83     PUSH       EDX
    //         00482f84     PUSH       this
    //         00482f85     LEA        EDX=>temp_scale_flag,[ESP + 0x60]
    //         00482f89     LEA        this,[EAX + 0x4]
    //         00482f8c     PUSH       EDX
    //         00482f8d     PUSH       this
    //         00482f8e     PUSH       EAX
    //         00482f8f     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d               = "%d %d %d %d %d %d %d %d %d %d %d %d"
    //         00482f94     PUSH       EBP
    //         00482f95     CALL       fscanf                                           undefined fscanf()
    //                              rmm_dbct.cpp:194 (15)
    //         00482f9a     MOV        EDX,dword ptr [ESI + 0x4]
    //         00482f9d     MOV        AL,byte ptr [ESP + temp_scale_flag]
    //         00482fa1     ADD        ESP,0x38
    //         00482fa4     INC        EBX
    //         00482fa5     MOV        byte ptr [EDX + EDI*0x1 + 0x8],AL
    //                              rmm_dbct.cpp:195 (20)
    //         00482fa9     MOV        this,dword ptr [ESI + 0x4]
    //         00482fac     MOV        DL,byte ptr [ESP + local_4]
    //         00482fb0     MOV        byte ptr [ECX + EDI*0x1 + this+0x9],DL
    //         00482fb4     MOV        EAX,dword ptr [ESI]
    //         00482fb6     ADD        EDI,0x2c
    //         00482fb9     CMP        EBX,EAX
    //         00482fbb     JL         LAB_00482f5a
    //                              rmm_dbct.cpp:198 (6)
    //         00482fbd     MOV        EDI,dword ptr [ESP + land_num]
    //         00482fc1     JMP        LAB_00482fc6
    //                               LAB_00482fc3                                                 XREF[1]:     00482f42(j)  
    //                              rmm_dbct.cpp:199 (3)
    //         00482fc3     MOV        dword ptr [ESI + 0x4],EBX
    //                               LAB_00482fc6                                                 XREF[2]:     00482f56(j), 00482fc1(j)  
    //                              rmm_dbct.cpp:170 (21)
    //         00482fc6     MOV        EAX,dword ptr [ESP + param_4]
    //         00482fca     MOV        this,dword ptr [ESP + temp_terrain_type]
    //         00482fce     INC        EAX
    //         00482fcf     CMP        EAX,this
    //         00482fd1     MOV        dword ptr [ESP + param_4],EAX
    //         00482fd5     JL         LAB_00482f09
    //                               LAB_00482fdb                                                 XREF[1]:     00482f03(j)  
    //                              rmm_dbct.cpp:201 (9)
    //         00482fdb     PUSH       EBP
    //         00482fdc     CALL       fclose                                           undefined fclose()
    //         00482fe1     ADD        ESP,0x4
    //                              rmm_dbct.cpp:242 (12)
    //         00482fe4     MOV        EAX,EDI
    //         00482fe6     POP        EDI
    //         00482fe7     POP        ESI
    //         00482fe8     POP        EBP
    //         00482fe9     POP        EBX
    //         00482fea     ADD        ESP,0x34
    //         00482fed     RET        0x10
    //                               LAB_00482ff0                                                 XREF[1]:     00482c4c(j)  
    //                              rmm_dbct.cpp:239 (3)
    //         00482ff0     MOV        dword ptr [EBP],ESI
    //                              rmm_dbct.cpp:240 (6)
    //         00482ff3     MOV        dword ptr [EDI + 0x4f58],ESI
    //                               LAB_00482ff9                                                 XREF[1]:     00482edc(j)  
    //                              rmm_dbct.cpp:242 (12)
    //         00482ff9     MOV        EAX,EDI
    //         00482ffb     POP        EDI
    //         00482ffc     POP        ESI
    //         00482ffd     POP        EBP
    //         00482ffe     POP        EBX
    //         00482fff     ADD        ESP,0x34
    //         00483002     RET        0x10
    //                               LAB_00483005                                                 XREF[1]:     00482cf0(j)  
    //                              rmm_dbct.cpp:129 (7)
    //         00483005     MOV        dword ptr [ESI + 0x28],0x0
    //                              rmm_dbct.cpp:128 (5)
    //         0048300c     JMP        LAB_00482db3
    //         00483011     ??         90h
    //         00483012     NOP
    //         00483013     NOP
    //         00483014     NOP
    //         00483015     NOP
    //         00483016     NOP
    //         00483017     NOP
    //         00483018     NOP
    //         00483019     NOP
    //         0048301a     NOP
    //         0048301b     NOP
    //         0048301c     NOP
    //         0048301d     NOP
    //         0048301e     NOP
    //         0048301f     NOP
    return 0;
}

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info* param_1, RGE_Land_Info* param_2, long param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_RMM_Controller::add_object_module(RGE_Game_World* param_1, RGE_Land_Info* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

