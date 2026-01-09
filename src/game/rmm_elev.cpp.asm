#include "common.h"
#include "rmm_elev.h"

uchar RGE_RMM_Elevation_Generator::generate() {
    /* TODO: Stub */
    //                              uchar __thiscall generate(RGE_RMM_Elevation_Generator * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0048476e(W), 00484772(R), 004847a1(R), 004847b1(W)  
    //                               ?generate@RGE_RMM_Elevation_Generator@@UAEEXZ                XREF[1]:     00571ec4(*)  
    //                               RGE_RMM_Elevation_Generator::generate
    //                              rmm_elev.cpp:29 (7)
    //         00484700     PUSH       this
    //         00484701     PUSH       EBX
    //         00484702     PUSH       EBP
    //         00484703     PUSH       ESI
    //         00484704     PUSH       EDI
    //         00484705     MOV        EBX,this
    //                              rmm_elev.cpp:36 (5)
    //         00484707     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
    //                              rmm_elev.cpp:38 (10)
    //         0048470c     MOV        EAX,dword ptr [EBX + 0x978]
    //         00484712     TEST       EAX,EAX
    //         00484714     JLE        LAB_00484758
    //                              rmm_elev.cpp:39 (9)
    //         00484716     MOV        this,dword ptr [EBX + 0x18]
    //         00484719     XOR        EAX,EAX
    //         0048471b     TEST       this,this
    //         0048471d     JLE        LAB_00484758
    //                               LAB_0048471f                                                 XREF[1]:     00484756(j)  
    //                              rmm_elev.cpp:40 (11)
    //         0048471f     MOV        this,dword ptr [EBX + 0x14]
    //         00484722     XOR        EBP,EBP
    //         00484724     TEST       this,this
    //         00484726     JLE        LAB_00484750
    //         00484728     XOR        EDI,EDI
    //                               LAB_0048472a                                                 XREF[1]:     0048474e(j)  
    //                              rmm_elev.cpp:41 (38)
    //         0048472a     MOV        this,dword ptr [EBX + 0x10]
    //         0048472d     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         00484730     MOV        this,byte ptr [EDX + EDI*0x1 + 0x5]
    //         00484734     AND        this,0x1f
    //         00484737     LEA        ESI,[EDX + EDI*0x1 + 0x5]
    //         0048473b     MOV        DL,byte ptr [EBX + 0x40]
    //         0048473e     SHL        DL,0x5
    //         00484741     OR         this,DL
    //         00484743     INC        EBP
    //         00484744     MOV        byte ptr [ESI],this
    //         00484746     MOV        this,dword ptr [EBX + 0x14]
    //         00484749     ADD        EDI,0x18
    //         0048474c     CMP        EBP,this
    //         0048474e     JL         LAB_0048472a
    //                               LAB_00484750                                                 XREF[1]:     00484726(j)  
    //                              rmm_elev.cpp:39 (8)
    //         00484750     MOV        this,dword ptr [EBX + 0x18]
    //         00484753     INC        EAX
    //         00484754     CMP        EAX,this
    //         00484756     JL         LAB_0048471f
    //                               LAB_00484758                                                 XREF[2]:     00484714(j), 0048471d(j)  
    //                              rmm_elev.cpp:43 (7)
    //         00484758     MOV        this,EBX
    //         0048475a     CALL       RGE_RMM_Elevation_Generator::generate_modifiers  void generate_modifiers(RGE_RMM_Elevation_Gen
    //                              rmm_elev.cpp:47 (19)
    //         0048475f     MOV        EAX,dword ptr [EBX + 0x978]
    //         00484765     XOR        EBP,EBP
    //         00484767     TEST       EAX,EAX
    //         00484769     JLE        LAB_004847b7
    //         0048476b     LEA        EAX,[EBX + 0x30]
    //         0048476e     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00484772                                                 XREF[1]:     004847b5(j)  
    //                              rmm_elev.cpp:49 (23)
    //         00484772     MOV        ESI,dword ptr [ESP + local_4]
    //         00484776     SUB        ESP,0x18
    //         00484779     MOV        this,0x6
    //         0048477e     MOV        EDI,ESP
    //         00484780     MOVSD.REP  ES:EDI,ESI
    //         00484782     MOV        this,EBX
    //         00484784     CALL       RGE_RMM_Elevation_Generator::base_elevation_ge   uchar base_elevation_generate(RGE_RMM_Elevati
    //                              rmm_elev.cpp:50 (46)
    //         00484789     MOV        this,dword ptr [EBX + 0x18]
    //         0048478c     MOV        EDX,dword ptr [EBX + 0x14]
    //         0048478f     DEC        this
    //         00484790     PUSH       0x8
    //         00484792     DEC        EDX
    //         00484793     PUSH       this
    //         00484794     MOV        this,dword ptr [EBX + 0xc]
    //         00484797     PUSH       EDX
    //         00484798     PUSH       0x0
    //         0048479a     PUSH       0x0
    //         0048479c     CALL       RGE_Map::clean_elevation                         void clean_elevation(RGE_Map * this, long par
    //         004847a1     MOV        this,dword ptr [ESP + local_4]
    //         004847a5     MOV        EAX,dword ptr [EBX + 0x978]
    //         004847ab     INC        EBP
    //         004847ac     ADD        this,0x18
    //         004847af     CMP        EBP,EAX
    //         004847b1     MOV        dword ptr [ESP + local_4],this
    //         004847b5     JL         LAB_00484772
    //                               LAB_004847b7                                                 XREF[1]:     00484769(j)  
    //                              rmm_elev.cpp:59 (8)
    //         004847b7     POP        EDI
    //         004847b8     POP        ESI
    //         004847b9     POP        EBP
    //         004847ba     MOV        AL,0x1
    //         004847bc     POP        EBX
    //         004847bd     POP        this
    //         004847be     RET
    //         004847bf     ??         90h
    //                              * protected: unsigned char __thiscall RGE_RMM_Elevation_Generator::check_start_elevation(long,long,u... *
    //                              uchar __thiscall check_start_elevation(RGE_RMM_Elevation_Generator *
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     004847c8(R), 00484814(W), 00484866(R), 0048487c(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004847cd(R), 0048482e(W), 00484862(R), 0048486f(W)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0048482a(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0048484b(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[5]:     004847c1(R), 004847e5(W), 00484805(W), 0048480c(R), 
    //                                                                                     00484876(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00484820(W), 0048485e(R)  
    //                               ?check_start_elevation@RGE_RMM_Elevation_Generator@@IAEEJJE  XREF[1]:     base_elevation_generate:00484de5(c
    //                               RGE_RMM_Elevation_Generator::check_start_elevation
    //                              rmm_elev.cpp:64 (1)
    //         004847c0     PUSH       this
    //                              rmm_elev.cpp:79 (34)
    //         004847c1     MOV        EAX,dword ptr [ESP + param_5]
    //         004847c5     PUSH       EBX
    //         004847c6     PUSH       EBP
    //         004847c7     PUSH       ESI
    //         004847c8     MOV        ESI,dword ptr [ESP + param_1]
    //         004847cc     PUSH       EDI
    //         004847cd     MOV        EDI,dword ptr [ESP + param_2]
    //         004847d1     AND        EAX,0xff
    //         004847d6     MOV        EBP,ESI
    //         004847d8     MOV        EDX,EDI
    //         004847da     SUB        EBP,EAX
    //         004847dc     SUB        EDX,EAX
    //         004847de     ADD        EDI,EAX
    //         004847e0     LEA        EBX,[ESI + EAX*0x1]
    //                              rmm_elev.cpp:81 (10)
    //         004847e3     TEST       EBP,EBP
    //         004847e5     MOV        dword ptr [ESP + param_5],EDI
    //         004847e9     JGE        LAB_004847ed
    //         004847eb     XOR        EBP,EBP
    //                               LAB_004847ed                                                 XREF[1]:     004847e9(j)  
    //                              rmm_elev.cpp:82 (6)
    //         004847ed     TEST       EDX,EDX
    //         004847ef     JGE        LAB_004847f3
    //         004847f1     XOR        EDX,EDX
    //                               LAB_004847f3                                                 XREF[1]:     004847ef(j)  
    //                              rmm_elev.cpp:83 (10)
    //         004847f3     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004847f6     CMP        EBX,EAX
    //         004847f8     JL         LAB_004847fd
    //         004847fa     LEA        EBX,[EAX + -0x1]
    //                               LAB_004847fd                                                 XREF[1]:     004847f8(j)  
    //                              rmm_elev.cpp:84 (12)
    //         004847fd     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00484800     CMP        EDI,EAX
    //         00484802     JL         LAB_00484809
    //         00484804     DEC        EAX
    //         00484805     MOV        dword ptr [ESP + param_5],EAX
    //                               LAB_00484809                                                 XREF[1]:     00484802(j)  
    //                              rmm_elev.cpp:86 (3)
    //         00484809     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              rmm_elev.cpp:88 (38)
    //         0048480c     MOV        EDI,dword ptr [ESP + param_5]
    //         00484810     LEA        ESI,[EBP + EBP*0x2]
    //         00484814     MOV        dword ptr [ESP + param_1],EDX
    //         00484818     LEA        this,[EAX + EDX*0x4]
    //         0048481b     SHL        ESI,0x3
    //         0048481e     MOV        EAX,dword ptr [this->_padding_]
    //         00484820     MOV        dword ptr [ESP + local_4],ESI
    //         00484824     ADD        EAX,ESI
    //         00484826     CMP        EDX,EDI
    //         00484828     JG         LAB_00484896
    //         0048482a     MOV        DL,byte ptr [ESP + param_3]
    //         0048482e     MOV        dword ptr [ESP + param_2],this
    //                               LAB_00484832                                                 XREF[1]:     00484880(j)  
    //                              rmm_elev.cpp:89 (9)
    //         00484832     CMP        EBP,EBX
    //         00484834     MOV        EDI,EBP
    //         00484836     JG         LAB_00484862
    //         00484838     LEA        ESI,[EAX + 0x5]
    //                               LAB_0048483b                                                 XREF[1]:     0048485c(j)  
    //                              rmm_elev.cpp:91 (35)
    //         0048483b     CMP        DL,0xff
    //         0048483e     JZ         LAB_0048488c
    //         00484840     MOV        AL,byte ptr [ESI]
    //         00484842     MOV        this,AL
    //         00484844     AND        this,0x1f
    //         00484847     CMP        this,DL
    //         00484849     JNZ        LAB_0048488c
    //         0048484b     MOV        this,byte ptr [ESP + param_4]
    //         0048484f     SHR        AL,0x5
    //         00484852     CMP        AL,this
    //         00484854     JC         LAB_0048488c
    //         00484856     INC        EDI
    //         00484857     ADD        ESI,0x18
    //         0048485a     CMP        EDI,EBX
    //         0048485c     JLE        LAB_0048483b
    //                              rmm_elev.cpp:89 (4)
    //         0048485e     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_00484862                                                 XREF[1]:     00484836(j)  
    //                              rmm_elev.cpp:88 (32)
    //         00484862     MOV        EDI,dword ptr [ESP + param_2]
    //         00484866     MOV        this,dword ptr [ESP + param_1]
    //         0048486a     ADD        EDI,0x4
    //         0048486d     MOV        EAX,ESI
    //         0048486f     MOV        dword ptr [ESP + param_2],EDI
    //         00484873     INC        this
    //         00484874     ADD        EAX,dword ptr [EDI]
    //         00484876     MOV        EDI,dword ptr [ESP + param_5]
    //         0048487a     CMP        this,EDI
    //         0048487c     MOV        dword ptr [ESP + param_1],this
    //         00484880     JLE        LAB_00484832
    //                              rmm_elev.cpp:94 (2)
    //         00484882     MOV        AL,0x1
    //                              rmm_elev.cpp:95 (8)
    //         00484884     POP        EDI
    //         00484885     POP        ESI
    //         00484886     POP        EBP
    //         00484887     POP        EBX
    //         00484888     POP        this
    //         00484889     RET        0x14
    //                               LAB_0048488c                                                 XREF[3]:     0048483e(j), 00484849(j), 
    //                                                                                                         00484854(j)  
    //                              rmm_elev.cpp:92 (2)
    //         0048488c     XOR        AL,AL
    //                              rmm_elev.cpp:95 (18)
    //         0048488e     POP        EDI
    //         0048488f     POP        ESI
    //         00484890     POP        EBP
    //         00484891     POP        EBX
    //         00484892     POP        this
    //         00484893     RET        0x14
    //                               LAB_00484896                                                 XREF[1]:     00484828(j)  
    //         00484896     POP        EDI
    //         00484897     POP        ESI
    //         00484898     POP        EBP
    //         00484899     MOV        AL,0x1
    //         0048489b     POP        EBX
    //         0048489c     POP        this
    //         0048489d     RET        0x14
    //                              * protected: unsigned char __thiscall RGE_RMM_Elevation_Generator::check_elevation(unsigned char,lon... *
    //                              uchar __thiscall check_elevation(RGE_RMM_Elevation_Generator * this,
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004849e2(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004848bf(R), 00484989(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     004848c3(R), 0048498d(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     004848a3(R), 004848d6(W), 004848f6(W), 0048490a(R), 
    //                                                                                     00484977(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[4]:     0048491c(R), 0048499f(W), 004849b7(W), 00484a05(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[4]:     00484944(R), 004849de(W), 00484a13(R), 00484a18(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00484912(W), 0048495b(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     004848ad(W), 00484985(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00484920(W), 0048496a(R), 00484971(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     004848b1(W), 004849fb(RW), 00484a1e(R)  
    //              long              Stack[-0x14]:4 count                     XREF[4]:     00484916(W), 0048495f(R), 00484966(W), 0048497d(R)  
    //              long              Stack[-0x18]:4 index1
    //                               ?check_elevation@RGE_RMM_Elevation_Generator@@IAEEEJJJEE@Z   XREF[1]:     base_elevation_generate:00484f9f(c
    //                               RGE_RMM_Elevation_Generator::check_elevation
    //                              rmm_elev.cpp:100 (3)
    //         004848a0     SUB        ESP,0x14
    //                              rmm_elev.cpp:112 (28)
    //         004848a3     MOV        EDX,dword ptr [ESP + param_4]
    //         004848a7     PUSH       EBX
    //         004848a8     PUSH       EBP
    //         004848a9     PUSH       ESI
    //         004848aa     TEST       EDX,EDX
    //         004848ac     PUSH       EDI
    //         004848ad     MOV        dword ptr [ESP + local_8],this
    //         004848b1     MOV        dword ptr [ESP + local_10],0x0
    //         004848b9     JLE        LAB_00484989
    //                              rmm_elev.cpp:117 (21)
    //         004848bf     MOV        EDI,dword ptr [ESP + param_2]
    //         004848c3     MOV        EAX,dword ptr [ESP + param_3]
    //         004848c7     MOV        EBP,EDI
    //         004848c9     MOV        ESI,EAX
    //         004848cb     SUB        EBP,EDX
    //         004848cd     SUB        ESI,EDX
    //         004848cf     ADD        EAX,EDX
    //         004848d1     LEA        EBX,[EDX + EDI*0x1]
    //                              rmm_elev.cpp:119 (10)
    //         004848d4     TEST       EBP,EBP
    //         004848d6     MOV        dword ptr [ESP + param_4],EAX
    //         004848da     JGE        LAB_004848de
    //         004848dc     XOR        EBP,EBP
    //                               LAB_004848de                                                 XREF[1]:     004848da(j)  
    //                              rmm_elev.cpp:120 (6)
    //         004848de     TEST       ESI,ESI
    //         004848e0     JGE        LAB_004848e4
    //         004848e2     XOR        ESI,ESI
    //                               LAB_004848e4                                                 XREF[1]:     004848e0(j)  
    //                              rmm_elev.cpp:121 (10)
    //         004848e4     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004848e7     CMP        EBX,EDX
    //         004848e9     JL         LAB_004848ee
    //         004848eb     LEA        EBX,[EDX + -0x1]
    //                               LAB_004848ee                                                 XREF[1]:     004848e9(j)  
    //                              rmm_elev.cpp:122 (12)
    //         004848ee     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004848f1     CMP        EAX,EDX
    //         004848f3     JL         LAB_004848fa
    //         004848f5     DEC        EDX
    //         004848f6     MOV        dword ptr [ESP + param_4],EDX
    //                               LAB_004848fa                                                 XREF[1]:     004848f3(j)  
    //                              rmm_elev.cpp:124 (16)
    //         004848fa     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004848fd     LEA        this,[EBP + EBP*0x2]
    //         00484901     SHL        this,0x3
    //         00484904     MOV        EDX,dword ptr [EAX + ESI*0x4]
    //         00484907     LEA        EDI,[EAX + ESI*0x4]
    //                              rmm_elev.cpp:126 (26)
    //         0048490a     MOV        EAX,dword ptr [ESP + param_4]
    //         0048490e     ADD        EDX,this
    //         00484910     CMP        ESI,EAX
    //         00484912     MOV        dword ptr [ESP + local_4],this
    //         00484916     MOV        dword ptr [ESP + count],ESI
    //         0048491a     JG         LAB_00484985
    //         0048491c     MOV        AL,byte ptr [ESP + param_5]
    //         00484920     MOV        dword ptr [ESP + local_c],EDI
    //                               LAB_00484924                                                 XREF[1]:     00484983(j)  
    //                              rmm_elev.cpp:127 (9)
    //         00484924     CMP        EBP,EBX
    //         00484926     MOV        EDI,EBP
    //         00484928     JG         LAB_0048495f
    //         0048492a     LEA        ESI,[EDX + 0x5]
    //                               LAB_0048492d                                                 XREF[1]:     00484959(j)  
    //                              rmm_elev.cpp:129 (46)
    //         0048492d     CMP        AL,0xff
    //         0048492f     JZ         LAB_00484a2c
    //         00484935     MOV        DL,byte ptr [ESI]
    //         00484937     MOV        this,DL
    //         00484939     AND        this,0x1f
    //         0048493c     CMP        this,AL
    //         0048493e     JNZ        LAB_00484a2c
    //         00484944     MOV        this,byte ptr [ESP + param_6]
    //         00484948     SHR        DL,0x5
    //         0048494b     CMP        DL,this
    //         0048494d     JC         LAB_00484a2c
    //         00484953     INC        EDI
    //         00484954     ADD        ESI,0x18
    //         00484957     CMP        EDI,EBX
    //         00484959     JLE        LAB_0048492d
    //                              rmm_elev.cpp:127 (4)
    //         0048495b     MOV        this,dword ptr [ESP + local_4]
    //                               LAB_0048495f                                                 XREF[1]:     00484928(j)  
    //                              rmm_elev.cpp:126 (42)
    //         0048495f     MOV        ESI,dword ptr [ESP + count]
    //         00484963     MOV        EDX,this
    //         00484965     INC        ESI
    //         00484966     MOV        dword ptr [ESP + count],ESI
    //         0048496a     MOV        ESI,dword ptr [ESP + local_c]
    //         0048496e     ADD        ESI,0x4
    //         00484971     MOV        dword ptr [ESP + local_c],ESI
    //         00484975     MOV        EDI,dword ptr [ESI]
    //         00484977     MOV        ESI,dword ptr [ESP + param_4]
    //         0048497b     ADD        EDX,EDI
    //         0048497d     MOV        EDI,dword ptr [ESP + count]
    //         00484981     CMP        EDI,ESI
    //         00484983     JLE        LAB_00484924
    //                               LAB_00484985                                                 XREF[1]:     0048491a(j)  
    //         00484985     MOV        this,dword ptr [ESP + local_8]
    //                               LAB_00484989                                                 XREF[1]:     004848b9(j)  
    //                              rmm_elev.cpp:137 (20)
    //         00484989     MOV        EAX,dword ptr [ESP + param_2]
    //         0048498d     MOV        EDX,dword ptr [ESP + param_3]
    //         00484991     LEA        EBP,[EAX + -0x2]
    //         00484994     LEA        ESI,[EDX + -0x2]
    //         00484997     ADD        EAX,0x2
    //         0048499a     ADD        EDX,0x2
    //                              rmm_elev.cpp:139 (10)
    //         0048499d     TEST       EBP,EBP
    //         0048499f     MOV        dword ptr [ESP + param_5],EAX
    //         004849a3     JGE        LAB_004849a7
    //         004849a5     XOR        EBP,EBP
    //                               LAB_004849a7                                                 XREF[1]:     004849a3(j)  
    //                              rmm_elev.cpp:140 (6)
    //         004849a7     TEST       ESI,ESI
    //         004849a9     JGE        LAB_004849ad
    //         004849ab     XOR        ESI,ESI
    //                               LAB_004849ad                                                 XREF[1]:     004849a9(j)  
    //                              rmm_elev.cpp:141 (14)
    //         004849ad     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004849b0     CMP        EAX,EDI
    //         004849b2     JL         LAB_004849bb
    //         004849b4     LEA        EAX,[EDI + -0x1]
    //         004849b7     MOV        dword ptr [ESP + param_5],EAX
    //                               LAB_004849bb                                                 XREF[1]:     004849b2(j)  
    //                              rmm_elev.cpp:142 (10)
    //         004849bb     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004849be     CMP        EDX,EDI
    //         004849c0     JL         LAB_004849c5
    //         004849c2     LEA        EDX,[EDI + -0x1]
    //                               LAB_004849c5                                                 XREF[1]:     004849c0(j)  
    //                              rmm_elev.cpp:144 (18)
    //         004849c5     MOV        this,dword ptr [ECX + this->_padding_]
    //         004849c8     LEA        EBX,[EBP + EBP*0x2]
    //         004849cc     SHL        EBX,0x3
    //         004849cf     LEA        EDI,[this->_padding_ + ESI*0x4]
    //         004849d2     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
    //         004849d5     ADD        this,EBX
    //                              rmm_elev.cpp:146 (15)
    //         004849d7     CMP        ESI,EDX
    //         004849d9     JG         LAB_00484a1e
    //         004849db     SUB        EDX,ESI
    //         004849dd     INC        EDX
    //         004849de     MOV        dword ptr [ESP + param_6],EDX
    //         004849e2     MOV        DL,byte ptr [ESP + param_1]
    //                               LAB_004849e6                                                 XREF[1]:     00484a1c(j)  
    //                              rmm_elev.cpp:147 (12)
    //         004849e6     CMP        EBP,EAX
    //         004849e8     JG         LAB_00484a09
    //         004849ea     LEA        ESI,[ECX + this+0x5]
    //         004849ed     MOV        this,EAX
    //         004849ef     SUB        this,EBP
    //         004849f1     INC        this
    //                               LAB_004849f2                                                 XREF[1]:     00484a03(j)  
    //                              rmm_elev.cpp:148 (9)
    //         004849f2     MOV        AL,byte ptr [ESI]
    //         004849f4     SHR        AL,0x5
    //         004849f7     CMP        AL,DL
    //         004849f9     JNZ        LAB_004849ff
    //                              rmm_elev.cpp:149 (10)
    //         004849fb     INC        dword ptr [ESP + local_10]
    //                               LAB_004849ff                                                 XREF[1]:     004849f9(j)  
    //         004849ff     ADD        ESI,0x18
    //         00484a02     DEC        this
    //         00484a03     JNZ        LAB_004849f2
    //                              rmm_elev.cpp:147 (4)
    //         00484a05     MOV        EAX,dword ptr [ESP + param_5]
    //                               LAB_00484a09                                                 XREF[1]:     004849e8(j)  
    //                              rmm_elev.cpp:146 (21)
    //         00484a09     MOV        ESI,dword ptr [EDI + 0x4]
    //         00484a0c     ADD        EDI,0x4
    //         00484a0f     MOV        this,EBX
    //         00484a11     ADD        this,ESI
    //         00484a13     MOV        ESI,dword ptr [ESP + param_6]
    //         00484a17     DEC        ESI
    //         00484a18     MOV        dword ptr [ESP + param_6],ESI
    //         00484a1c     JNZ        LAB_004849e6
    //                               LAB_00484a1e                                                 XREF[1]:     004849d9(j)  
    //                              rmm_elev.cpp:152 (4)
    //         00484a1e     MOV        AL,byte ptr [ESP + local_10]
    //                              rmm_elev.cpp:153 (22)
    //         00484a22     POP        EDI
    //         00484a23     POP        ESI
    //         00484a24     POP        EBP
    //         00484a25     POP        EBX
    //         00484a26     ADD        ESP,0x14
    //         00484a29     RET        0x18
    //                               LAB_00484a2c                                                 XREF[3]:     0048492f(j), 0048493e(j), 
    //                                                                                                         0048494d(j)  
    //         00484a2c     POP        EDI
    //         00484a2d     POP        ESI
    //         00484a2e     POP        EBP
    //         00484a2f     XOR        AL,AL
    //         00484a31     POP        EBX
    //         00484a32     ADD        ESP,0x14
    //         00484a35     RET        0x18
    //         00484a38     ??         90h
    //         00484a39     NOP
    //         00484a3a     NOP
    //         00484a3b     NOP
    //         00484a3c     NOP
    //         00484a3d     NOP
    //         00484a3e     NOP
    //         00484a3f     NOP
    return 0;
}

void RGE_RMM_Elevation_Generator::generate_modifiers() {
    /* TODO: Stub */
    //                              void __thiscall generate_modifiers(RGE_RMM_Elevation_Generator * this)
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00484abc(W), 00484ac0(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00484a93(W), 00484ae4(R), 00484aec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00484a87(W), 00484ad7(R), 00484ae0(W), 00484af2(R)  
    //              long              Stack[-0x10]:4 modifier
    //                               ?generate_modifiers@RGE_RMM_Elevation_Generator@@IAEXXZ      XREF[1]:     generate:0048475a(c)  
    //                               RGE_RMM_Elevation_Generator::generate_modifiers
    //                              rmm_elev.cpp:159 (3)
    //         00484a40     SUB        ESP,0xc
    //                              rmm_elev.cpp:169 (19)
    //         00484a43     XOR        EAX,EAX
    //         00484a45     PUSH       EBX
    //         00484a46     MOV        EBX,this
    //         00484a48     PUSH       EBP
    //         00484a49     PUSH       EDI
    //         00484a4a     MOV        this,dword ptr [EBX + 0x18]
    //         00484a4d     MOV        EDI,dword ptr [EBX + 0x20]
    //         00484a50     IMUL       this,dword ptr [EBX + 0x14]
    //         00484a54     MOV        EDX,this
    //                              rmm_elev.cpp:171 (25)
    //         00484a56     XOR        EBP,EBP
    //         00484a58     SHR        this,0x2
    //         00484a5b     STOSD.REP  ES:EDI
    //         00484a5d     MOV        this,EDX
    //         00484a5f     AND        this,0x3
    //         00484a62     STOSB.REP  ES:EDI
    //         00484a64     MOV        EAX,dword ptr [EBX + 0x18]
    //         00484a67     TEST       EAX,EAX
    //         00484a69     JLE        LAB_00484b29
    //                              rmm_elev.cpp:159 (1)
    //         00484a6f     PUSH       ESI
    //                               LAB_00484a70                                                 XREF[1]:     00484b22(j)  
    //                              rmm_elev.cpp:172 (13)
    //         00484a70     MOV        EAX,dword ptr [EBX + 0x14]
    //         00484a73     XOR        EDI,EDI
    //         00484a75     TEST       EAX,EAX
    //         00484a77     JLE        LAB_00484b1c
    //                               LAB_00484a7d                                                 XREF[1]:     00484b16(j)  
    //                              rmm_elev.cpp:175 (39)
    //         00484a7d     MOV        EAX,dword ptr [EBX + 0xfac]
    //         00484a83     XOR        this,this
    //         00484a85     TEST       EAX,EAX
    //         00484a87     MOV        dword ptr [ESP + local_c],this
    //         00484a8b     JLE        LAB_00484af6
    //         00484a8d     LEA        ESI,[EBX + 0x980]
    //         00484a93     MOV        dword ptr [ESP + local_8],EAX
    //                               LAB_00484a97                                                 XREF[1]:     00484af0(j)  
    //         00484a97     MOV        this,dword ptr [ESI + -0x4]
    //         00484a9a     MOV        EDX,dword ptr [ESI]
    //         00484a9c     MOV        EAX,EDI
    //         00484a9e     SUB        EAX,this
    //         00484aa0     MOV        this,EBP
    //         00484aa2     SUB        this,EDX
    //                              rmm_elev.cpp:179 (6)
    //         00484aa4     TEST       EAX,EAX
    //         00484aa6     JGE        LAB_00484aaa
    //         00484aa8     NEG        EAX
    //                               LAB_00484aaa                                                 XREF[1]:     00484aa6(j)  
    //                              rmm_elev.cpp:180 (6)
    //         00484aaa     TEST       this,this
    //         00484aac     JGE        LAB_00484ab0
    //         00484aae     NEG        this
    //                               LAB_00484ab0                                                 XREF[1]:     00484aac(j)  
    //                              rmm_elev.cpp:183 (32)
    //         00484ab0     MOV        EDX,EAX
    //         00484ab2     IMUL       EDX,EAX
    //         00484ab5     MOV        EAX,this
    //         00484ab7     IMUL       EAX,this
    //         00484aba     ADD        EDX,EAX
    //         00484abc     MOV        dword ptr [ESP + local_4],EDX
    //         00484ac0     FILD       dword ptr [ESP + local_4]
    //         00484ac4     FSQRT
    //         00484ac6     CALL       __ftol                                           undefined __ftol()
    //         00484acb     MOV        this,dword ptr [ESI + 0x4]
    //         00484ace     SUB        this,EAX
    //                              rmm_elev.cpp:184 (4)
    //         00484ad0     TEST       this,this
    //         00484ad2     JLE        LAB_00484ae4
    //                              rmm_elev.cpp:185 (30)
    //         00484ad4     MOV        EDX,dword ptr [ESI + 0x8]
    //         00484ad7     MOV        EAX,dword ptr [ESP + local_c]
    //         00484adb     IMUL       EDX,this
    //         00484ade     ADD        EAX,EDX
    //         00484ae0     MOV        dword ptr [ESP + local_c],EAX
    //                               LAB_00484ae4                                                 XREF[1]:     00484ad2(j)  
    //         00484ae4     MOV        EAX,dword ptr [ESP + local_8]
    //         00484ae8     ADD        ESI,0x10
    //         00484aeb     DEC        EAX
    //         00484aec     MOV        dword ptr [ESP + local_8],EAX
    //         00484af0     JNZ        LAB_00484a97
    //                              rmm_elev.cpp:175 (4)
    //         00484af2     MOV        this,dword ptr [ESP + local_c]
    //                               LAB_00484af6                                                 XREF[1]:     00484a8b(j)  
    //                              rmm_elev.cpp:188 (5)
    //         00484af6     CMP        this,0x64
    //         00484af9     JLE        LAB_00484b07
    //                              rmm_elev.cpp:189 (10)
    //         00484afb     MOV        EAX,dword ptr [EBX + 0x24]
    //         00484afe     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00484b01     MOV        byte ptr [this->_padding_ + EDI*0x1],0x65
    //                              rmm_elev.cpp:190 (2)
    //         00484b05     JMP        LAB_00484b10
    //                               LAB_00484b07                                                 XREF[1]:     00484af9(j)  
    //                              rmm_elev.cpp:191 (21)
    //         00484b07     MOV        EDX,dword ptr [EBX + 0x24]
    //         00484b0a     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         00484b0d     MOV        byte ptr [EAX + EDI*0x1],this
    //                               LAB_00484b10                                                 XREF[1]:     00484b05(j)  
    //         00484b10     MOV        EAX,dword ptr [EBX + 0x14]
    //         00484b13     INC        EDI
    //         00484b14     CMP        EDI,EAX
    //         00484b16     JL         LAB_00484a7d
    //                               LAB_00484b1c                                                 XREF[1]:     00484a77(j)  
    //                              rmm_elev.cpp:171 (12)
    //         00484b1c     MOV        EAX,dword ptr [EBX + 0x18]
    //         00484b1f     INC        EBP
    //         00484b20     CMP        EBP,EAX
    //         00484b22     JL         LAB_00484a70
    //                              rmm_elev.cpp:159 (1)
    //         00484b28     POP        ESI
    //                               LAB_00484b29                                                 XREF[1]:     00484a69(j)  
    //                              rmm_elev.cpp:193 (7)
    //         00484b29     POP        EDI
    //         00484b2a     POP        EBP
    //         00484b2b     POP        EBX
    //         00484b2c     ADD        ESP,0xc
    //         00484b2f     RET
    return;
}

float RGE_RMM_Elevation_Generator::fig_chance(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
    //                              float __thiscall fig_chance(RGE_RMM_Elevation_Generator * this, long
    //              float             ST0:10         <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     00484b30(R), 00484b41(W), 00484b45(R)  
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //                               ?fig_chance@RGE_RMM_Elevation_Generator@@IAEMJJJ@Z           XREF[1]:     base_elevation_generate:00484fce(c
    //                               RGE_RMM_Elevation_Generator::fig_chance
    //                              rmm_elev.cpp:198 (25)
    //         00484b30     MOV        EAX,dword ptr [ESP + param_1]
    //         00484b34     MOV        this,0xfa
    //         00484b39     LEA        EAX,[EAX + EAX*0x2]
    //         00484b3c     LEA        EAX,[EAX + EAX*0x4]
    //         00484b3f     SUB        this,EAX
    //         00484b41     MOV        dword ptr [ESP + param_1],this
    //         00484b45     FILD       dword ptr [ESP + param_1]
    //                              rmm_elev.cpp:205 (3)
    //         00484b49     RET        0xc
    //         00484b4c     ??         90h
    //         00484b4d     NOP
    //         00484b4e     NOP
    //         00484b4f     NOP
    return 0;
}

long RGE_RMM_Elevation_Generator::count_map_tiles(uchar param_1) {
    /* TODO: Stub */
    //                              long __thiscall count_map_tiles(RGE_RMM_Elevation_Generator * this, 
    //              long              EAX:4          <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00484b6a(R)  
    //                               ?count_map_tiles@RGE_RMM_Elevation_Generator@@IAEJE@Z
    //                               RGE_RMM_Elevation_Generator::count_map_tiles
    //                              rmm_elev.cpp:211 (5)
    //         00484b50     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00484b53     PUSH       ESI
    //         00484b54     PUSH       EDI
    //                              rmm_elev.cpp:214 (17)
    //         00484b55     XOR        EDI,EDI
    //         00484b57     MOV        EDX,dword ptr [EAX]
    //         00484b59     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00484b5c     IMUL       EAX,dword ptr [ECX + this->_padding_]
    //         00484b60     LEA        this,[EAX + EAX*0x2]
    //         00484b63     LEA        ESI,[EDX + this->_padding_*0x8]
    //                              rmm_elev.cpp:216 (8)
    //         00484b66     CMP        EDX,ESI
    //         00484b68     JNC        LAB_00484b7f
    //         00484b6a     MOV        this,byte ptr [ESP + param_1]
    //                               LAB_00484b6e                                                 XREF[1]:     00484b7d(j)  
    //                              rmm_elev.cpp:217 (9)
    //         00484b6e     MOV        AL,byte ptr [EDX + 0x5]
    //         00484b71     AND        AL,0x1f
    //         00484b73     CMP        AL,this
    //         00484b75     JNZ        LAB_00484b78
    //                              rmm_elev.cpp:218 (1)
    //         00484b77     INC        EDI
    //                               LAB_00484b78                                                 XREF[1]:     00484b75(j)  
    //                              rmm_elev.cpp:216 (7)
    //         00484b78     ADD        EDX,0x18
    //         00484b7b     CMP        EDX,ESI
    //         00484b7d     JC         LAB_00484b6e
    //                               LAB_00484b7f                                                 XREF[1]:     00484b68(j)  
    //                              rmm_elev.cpp:220 (2)
    //         00484b7f     MOV        EAX,EDI
    //                              rmm_elev.cpp:221 (5)
    //         00484b81     POP        EDI
    //         00484b82     POP        ESI
    //         00484b83     RET        0x4
    //         00484b86     ??         90h
    //         00484b87     NOP
    //         00484b88     NOP
    //         00484b89     NOP
    //         00484b8a     NOP
    //         00484b8b     NOP
    //         00484b8c     NOP
    //         00484b8d     NOP
    //         00484b8e     NOP
    //         00484b8f     NOP
    return 0;
}

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1) {
    /* TODO: Stub */
    //                              void __thiscall link_stack_randomly(RGE_RMM_Elevation_Generator * th
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              Map_Stack *       Stack[0x4]:4   param_1                   XREF[2]:     00484b97(R), 00484c5a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00484bf4(W), 00484c67(R), 00484c6c(W)  
    //                               ?link_stack_randomly@RGE_RMM_Elevation_Generator@@IAEXPAUMa  XREF[1]:     base_elevation_generate:00484d4e(c
    //                               RGE_RMM_Elevation_Generator::link_stack_randomly
    //                              rmm_elev.cpp:225 (7)
    //         00484b90     PUSH       this
    //         00484b91     PUSH       EBX
    //         00484b92     PUSH       EBP
    //         00484b93     PUSH       ESI
    //         00484b94     PUSH       EDI
    //         00484b95     MOV        EDI,this
    //                              rmm_elev.cpp:237 (38)
    //         00484b97     MOV        ESI,dword ptr [ESP + param_1]
    //         00484b9b     MOV        EAX,dword ptr [EDI + 0x18]
    //         00484b9e     MOV        this,dword ptr [EDI + 0x14]
    //         00484ba1     MOV        EDX,dword ptr [EDI + 0x28]
    //         00484ba4     LEA        EBP,[EAX + -0x1]
    //         00484ba7     IMUL       EAX,this
    //         00484baa     LEA        EAX,[EAX + EAX*0x2]
    //         00484bad     LEA        EBX,[this->_padding_ + -0x1]
    //         00484bb0     MOV        dword ptr [EDX + 0x14],ESI
    //         00484bb3     LEA        this,[EDX + EAX*0x8 + -0x18]
    //         00484bb7     LEA        EAX,[EDX + 0x18]
    //         00484bba     MOV        dword ptr [EDX + 0x10],EAX
    //                              rmm_elev.cpp:241 (20)
    //         00484bbd     CMP        EAX,this
    //         00484bbf     LEA        EDX,[this->_padding_ + -0x18]
    //         00484bc2     MOV        dword ptr [ECX + this->_padding_],0x0
    //         00484bc9     MOV        dword ptr [ECX + this->_padding_],EDX
    //         00484bcc     JNC        LAB_00484be0
    //                               LAB_00484bce                                                 XREF[1]:     00484bde(j)  
    //         00484bce     LEA        EDX,[EAX + 0x18]
    //                              rmm_elev.cpp:244 (15)
    //         00484bd1     LEA        ESI,[EAX + -0x18]
    //         00484bd4     MOV        dword ptr [EAX + 0x10],EDX
    //         00484bd7     MOV        dword ptr [EAX + 0x14],ESI
    //         00484bda     MOV        EAX,EDX
    //         00484bdc     CMP        EAX,this
    //         00484bde     JC         LAB_00484bce
    //                               LAB_00484be0                                                 XREF[1]:     00484bcc(j)  
    //                              rmm_elev.cpp:247 (16)
    //         00484be0     MOV        EAX,dword ptr [EDI + 0x18]
    //         00484be3     IMUL       EAX,dword ptr [EDI + 0x14]
    //         00484be7     CDQ
    //         00484be8     AND        EDX,0xf
    //         00484beb     ADD        EAX,EDX
    //         00484bed     SAR        EAX,0x4
    //                              rmm_elev.cpp:248 (4)
    //         00484bf0     TEST       EAX,EAX
    //         00484bf2     JLE        LAB_00484c72
    //                              rmm_elev.cpp:247 (4)
    //         00484bf4     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00484bf8                                                 XREF[1]:     00484c70(j)  
    //                              rmm_elev.cpp:250 (37)
    //         00484bf8     PUSH       0xfa
    //         00484bfd     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         00484c02     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00484c07     MOV        this,EAX
    //         00484c09     MOV        EAX,0x80010003
    //         00484c0e     IMUL       this,EBX
    //         00484c11     IMUL       this
    //         00484c13     ADD        EDX,this
    //         00484c15     ADD        ESP,0x8
    //         00484c18     SAR        EDX,0xe
    //         00484c1b     MOV        EAX,EDX
    //                              rmm_elev.cpp:251 (36)
    //         00484c1d     PUSH       0xfb
    //         00484c22     SHR        EAX,0x1f
    //         00484c25     ADD        EDX,EAX
    //         00484c27     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         00484c2c     MOV        ESI,EDX
    //         00484c2e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00484c33     MOV        this,EAX
    //         00484c35     MOV        EAX,0x80010003
    //         00484c3a     IMUL       this,EBP
    //         00484c3d     IMUL       this
    //         00484c3f     ADD        EDX,this
    //                              rmm_elev.cpp:252 (49)
    //         00484c41     MOV        EAX,dword ptr [EDI + 0x2c]
    //         00484c44     SAR        EDX,0xe
    //         00484c47     MOV        this,EDX
    //         00484c49     ADD        ESP,0x8
    //         00484c4c     SHR        this,0x1f
    //         00484c4f     ADD        EDX,this
    //         00484c51     LEA        this,[ESI + ESI*0x2]
    //         00484c54     MOV        EDX,dword ptr [EAX + EDX*0x4]
    //         00484c57     LEA        EAX,[EDX + this->_padding_*0x8]
    //         00484c5a     MOV        this,dword ptr [ESP + param_1]
    //         00484c5e     PUSH       EAX
    //         00484c5f     PUSH       this
    //         00484c60     MOV        this,EDI
    //         00484c62     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
    //         00484c67     MOV        EAX,dword ptr [ESP + local_4]
    //         00484c6b     DEC        EAX
    //         00484c6c     MOV        dword ptr [ESP + local_4],EAX
    //         00484c70     JNZ        LAB_00484bf8
    //                               LAB_00484c72                                                 XREF[1]:     00484bf2(j)  
    //                              rmm_elev.cpp:260 (8)
    //         00484c72     POP        EDI
    //         00484c73     POP        ESI
    //         00484c74     POP        EBP
    //         00484c75     POP        EBX
    //         00484c76     POP        this
    //         00484c77     RET        0x4
    //         00484c7a     ??         90h
    //         00484c7b     NOP
    //         00484c7c     NOP
    //         00484c7d     NOP
    //         00484c7e     NOP
    //         00484c7f     NOP
    return;
}

void RGE_RMM_Elevation_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
    //                              void __thiscall remove_area_from_lists(RGE_RMM_Elevation_Generator *
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     00484c80(R), 00484c9d(W), 00484cb3(W), 00484ce8(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00484c84(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     00484c8e(R), 00484cbb(W), 00484cd1(R), 00484cec(R), 
    //                                                                                     00484cf3(W)  
    //                               ?remove_area_from_lists@RGE_RMM_Elevation_Generator@@IAEXJJ  XREF[1]:     base_elevation_generate:00484dff(c
    //                               RGE_RMM_Elevation_Generator::remove_area_from_lists
    //                              rmm_elev.cpp:264 (27)
    //         00484c80     MOV        EDX,dword ptr [ESP + param_1]
    //         00484c84     MOV        EAX,dword ptr [ESP + param_2]
    //         00484c88     PUSH       EBX
    //         00484c89     PUSH       EBP
    //         00484c8a     MOV        EBP,this
    //         00484c8c     MOV        EBX,EDX
    //         00484c8e     MOV        this,dword ptr [ESP + param_3]
    //         00484c92     PUSH       ESI
    //         00484c93     PUSH       EDI
    //         00484c94     SUB        EBX,this
    //         00484c96     SUB        EAX,this
    //         00484c98     LEA        EDI,[this->_padding_ + EDX*0x1]
    //                              rmm_elev.cpp:277 (10)
    //         00484c9b     TEST       EBX,EBX
    //         00484c9d     MOV        dword ptr [ESP + param_1],EDI
    //         00484ca1     JGE        LAB_00484ca5
    //         00484ca3     XOR        EBX,EBX
    //                               LAB_00484ca5                                                 XREF[1]:     00484ca1(j)  
    //                              rmm_elev.cpp:278 (6)
    //         00484ca5     TEST       EAX,EAX
    //         00484ca7     JGE        LAB_00484cab
    //         00484ca9     XOR        EAX,EAX
    //                               LAB_00484cab                                                 XREF[1]:     00484ca7(j)  
    //                              rmm_elev.cpp:279 (14)
    //         00484cab     MOV        this,dword ptr [EBP + 0x14]
    //         00484cae     CMP        EDI,this
    //         00484cb0     JL         LAB_00484cb9
    //         00484cb2     DEC        this
    //         00484cb3     MOV        dword ptr [ESP + param_1],this
    //         00484cb7     MOV        EDI,this
    //                               LAB_00484cb9                                                 XREF[1]:     00484cb0(j)  
    //                              rmm_elev.cpp:282 (8)
    //         00484cb9     CMP        EAX,EDI
    //         00484cbb     MOV        dword ptr [ESP + param_3],EAX
    //         00484cbf     JG         LAB_00484cf9
    //                               LAB_00484cc1                                                 XREF[1]:     00484cf7(j)  
    //                              rmm_elev.cpp:283 (13)
    //         00484cc1     CMP        EBX,EDI
    //         00484cc3     JG         LAB_00484cec
    //         00484cc5     LEA        ESI,[EBX + EBX*0x2]
    //         00484cc8     SUB        EDI,EBX
    //         00484cca     SHL        ESI,0x3
    //         00484ccd     INC        EDI
    //                               LAB_00484cce                                                 XREF[1]:     00484ce6(j)  
    //                              rmm_elev.cpp:284 (26)
    //         00484cce     MOV        EAX,dword ptr [EBP + 0x2c]
    //         00484cd1     MOV        this,dword ptr [ESP + param_3]
    //         00484cd5     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         00484cd8     MOV        this,EBP
    //         00484cda     ADD        EDX,ESI
    //         00484cdc     PUSH       EDX
    //         00484cdd     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module 
    //         00484ce2     ADD        ESI,0x18
    //         00484ce5     DEC        EDI
    //         00484ce6     JNZ        LAB_00484cce
    //                              rmm_elev.cpp:283 (4)
    //         00484ce8     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_00484cec                                                 XREF[1]:     00484cc3(j)  
    //                              rmm_elev.cpp:282 (13)
    //         00484cec     MOV        EAX,dword ptr [ESP + param_3]
    //         00484cf0     INC        EAX
    //         00484cf1     CMP        EAX,EDI
    //         00484cf3     MOV        dword ptr [ESP + param_3],EAX
    //         00484cf7     JLE        LAB_00484cc1
    //                               LAB_00484cf9                                                 XREF[1]:     00484cbf(j)  
    //                              rmm_elev.cpp:285 (7)
    //         00484cf9     POP        EDI
    //         00484cfa     POP        ESI
    //         00484cfb     POP        EBP
    //         00484cfc     POP        EBX
    //         00484cfd     RET        0xc
    //                              * protected: unsigned char __thiscall RGE_RMM_Elevation_Generator::base_elevation_generate(struct RG... *
    //                              uchar __thiscall base_elevation_generate(RGE_RMM_Elevation_Generator
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Elevat    ECX:4 (auto)   this
    //              RGE_Elevation_    Stack[0x4]:24  param_1                   XREF[2,16]:  00484d53(R), 00484ee1(R), 00484e15(R), 00484f93(R), 
    //                                                                                     00484fd3(R), 00484d0b(R), 00484d5a(R), 00484d79(R), 
    //                                                                                     00484ead(R), 00484eba(R), 00484ece(R), 004851bf(R), 
    //                                                                                     00484dc9(R), 00484f86(R), 00484dd1(R), 00484f6e(R), 
    //                                                                                     00484dd9(R), 00484f7f(R)  
    //              Map_Stack[99]     Stack[-0x94c   stack                     XREF[1,4]:   00484d4a(W), 00484d2d(*), 00484d8a(*), 00484ed5(*), 
    //                                                                                     004851d6(*)  
    //              Map_Stack         Stack[-0x964   loc_stack                 XREF[2,3]:   00484d1d(W), 00485056(R), 00484d3f(*), 00484d9c(*), 
    //                                                                                     00484d46(W)  
    //              long              Stack[-0x968   max_x                     XREF[2]:     00484d8e(*), 00484ef0(*)  
    //              float             Stack[-0x96c   in_zone                   XREF[2]:     00484d27(W), 00485135(R)  
    //              long              Stack[-0x970   max_y                     XREF[3]:     00484ed9(W), 004851ad(R), 004851b5(W)  
    //              undefined4        Stack[-0x974   local_974                 XREF[5]:     00484fdd(W), 0048503f(R), 004850aa(R), 0048511e(R), 
    //                                                                                     00485190(R)  
    //              float             Stack[-0x978   chance                    XREF[5]:     00484d19(W), 00484ea0(R), 00484ea6(W), 00484edd(R), 
    //                                                                                     004851a3(RW)  
    //              long              Stack[-0x97c   clump_size                XREF[8]:     00485032(W), 0048503a(R), 0048509d(W), 004850a5(R), 
    //                                                                                     00485112(W), 0048511a(R), 00485184(W), 0048518c(R)  
    //              undefined1        Stack[-0x97d   local_97d                 XREF[3]:     00484ec3(W), 00484f2e(W), 004851c6(R)  
    //              uchar             Stack[-0x981   done
    //              long              Stack[-0x988   y                         XREF[18]:    00484d97(*), 00484db8(R), 00484df6(R), 00484e07(R), 
    //                                                                                     00484e2c(R), 00484e47(R), 00484e66(R), 00484e85(R), 
    //                                                                                     00484ef9(*), 00484f2a(R), 00484f6a(R), 00484fc5(R), 
    //                                                                                     00484feb(R), 00485036(R), 00485052(R), 004850a1(R), 
    //                                                                                     00485116(R), 00485188(R)  
    //              long              Stack[-0x98c   x
    //              undefined4        Stack[-0x99c   local_99c                 XREF[4]:     00485043(*), 004850ae(*), 00485122(*), 00485194(*)  
    //                               ?base_elevation_generate@RGE_RMM_Elevation_Generator@@IAEEU  XREF[1]:     generate:00484784(c)  
    //                               RGE_RMM_Elevation_Generator::base_elevation_generate
    //                              rmm_elev.cpp:290 (11)
    //         00484d00     SUB        ESP,0x988
    //         00484d06     PUSH       EBX
    //         00484d07     PUSH       EBP
    //         00484d08     PUSH       ESI
    //         00484d09     MOV        ESI,this
    //                              rmm_elev.cpp:314 (34)
    //         00484d0b     MOV        EBX,dword ptr [ESP + param_1.clumps]
    //         00484d12     XOR        EBP,EBP
    //         00484d14     MOV        EAX,dword ptr [ESI + 0x14]
    //         00484d17     PUSH       EDI
    //         00484d18     DEC        EAX
    //         00484d19     MOV        dword ptr [ESP + chance],EBP
    //         00484d1d     MOV        dword ptr [ESP + loc_stack.x],EAX
    //         00484d21     MOV        EAX,dword ptr [ESI + 0x18]
    //         00484d24     DEC        EAX
    //         00484d25     CMP        EBX,EBP
    //         00484d27     MOV        dword ptr [ESP + in_zone],EAX
    //         00484d2b     JLE        LAB_00484d3f
    //                              rmm_elev.cpp:292 (4)
    //         00484d2d     LEA        EDI=>stack[0].y,[ESP + 0x50]
    //                               LAB_00484d31                                                 XREF[1]:     00484d3d(j)  
    //                              rmm_elev.cpp:315 (14)
    //         00484d31     PUSH       EDI
    //         00484d32     MOV        this,ESI
    //         00484d34     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
    //         00484d39     ADD        EDI,0x18
    //         00484d3c     DEC        EBX
    //         00484d3d     JNZ        LAB_00484d31
    //                               LAB_00484d3f                                                 XREF[1]:     00484d2b(j)  
    //                              rmm_elev.cpp:321 (20)
    //         00484d3f     LEA        EAX=>loc_stack.y,[ESP + 0x38]
    //         00484d43     MOV        this,ESI
    //         00484d45     PUSH       EAX
    //         00484d46     MOV        dword ptr [ESP + loc_stack.prev],EBP
    //         00484d4a     MOV        dword ptr [ESP + stack[0].x],EBP
    //         00484d4e     CALL       RGE_RMM_Elevation_Generator::link_stack_randomly void link_stack_randomly(RGE_RMM_Elevation_Ge
    //                              rmm_elev.cpp:324 (28)
    //         00484d53     FILD       dword ptr [ESP + param_1.elevation_size]
    //         00484d5a     FIDIV      dword ptr [ESP + param_1.clumps]
    //         00484d61     FSQRT
    //         00484d63     CALL       __ftol                                           undefined __ftol()
    //         00484d68     CDQ
    //         00484d69     SUB        EAX,EDX
    //         00484d6b     MOV        EBP,EAX
    //         00484d6d     SAR        EBP,0x1
    //                              rmm_elev.cpp:325 (5)
    //         00484d6f     CMP        EBP,0x2
    //         00484d72     JGE        LAB_00484d79
    //                              rmm_elev.cpp:326 (5)
    //         00484d74     MOV        EBP,0x2
    //                               LAB_00484d79                                                 XREF[1]:     00484d72(j)  
    //                              rmm_elev.cpp:329 (17)
    //         00484d79     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //         00484d80     XOR        EBX,EBX
    //         00484d82     TEST       EAX,EAX
    //         00484d84     JLE        LAB_00484ec1
    //                              rmm_elev.cpp:328 (4)
    //         00484d8a     LEA        EDI=>stack[0].y,[ESP + 0x50]
    //                               LAB_00484d8e                                                 XREF[1]:     00484eb4(j)  
    //                              rmm_elev.cpp:330 (35)
    //         00484d8e     LEA        this=>max_x,[ESP + 0x30]
    //         00484d92     LEA        EDX=>Stack[-0x984],[ESP + 0x14]
    //         00484d96     PUSH       this
    //         00484d97     LEA        EAX=>y,[ESP + 0x14]
    //         00484d9b     PUSH       EDX
    //         00484d9c     LEA        this=>loc_stack.y,[ESP + 0x40]
    //         00484da0     PUSH       EAX
    //         00484da1     PUSH       this
    //         00484da2     MOV        this,ESI
    //         00484da4     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00484da9     TEST       EAX,EAX
    //         00484dab     JZ         LAB_00484eba
    //                              rmm_elev.cpp:333 (65)
    //         00484db1     MOV        EDX,dword ptr [ESI + 0x24]
    //         00484db4     MOV        EAX,dword ptr [ESP + Stack[-0x984]]
    //         00484db8     MOV        this,dword ptr [ESP + y]
    //         00484dbc     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         00484dbf     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         00484dc3     JNZ        LAB_00484ead
    //         00484dc9     MOV        EDX,dword ptr [ESP + param_1.spacing]
    //         00484dd0     PUSH       EDX
    //         00484dd1     MOV        EDX,dword ptr [ESP + param_1.base_elevation]
    //         00484dd8     PUSH       EDX
    //         00484dd9     MOV        EDX,dword ptr [ESP + param_1.base_terrain_type]
    //         00484de0     PUSH       EDX
    //         00484de1     PUSH       EAX
    //         00484de2     PUSH       this
    //         00484de3     MOV        this,ESI
    //         00484de5     CALL       RGE_RMM_Elevation_Generator::check_start_eleva   uchar check_start_elevation(RGE_RMM_Elevation
    //         00484dea     TEST       AL,AL
    //         00484dec     JZ         LAB_00484ead
    //                              rmm_elev.cpp:336 (18)
    //         00484df2     MOV        EAX,dword ptr [ESP + Stack[-0x984]]
    //         00484df6     MOV        this,dword ptr [ESP + y]
    //         00484dfa     PUSH       EBP
    //         00484dfb     PUSH       EAX
    //         00484dfc     PUSH       this
    //         00484dfd     MOV        this,ESI
    //         00484dff     CALL       RGE_RMM_Elevation_Generator::remove_area_from_   void remove_area_from_lists(RGE_RMM_Elevation
    //                              rmm_elev.cpp:339 (40)
    //         00484e04     MOV        EDX,dword ptr [ESI + 0x10]
    //         00484e07     MOV        EAX,dword ptr [ESP + y]
    //         00484e0b     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484e0f     LEA        EAX,[EAX + EAX*0x2]
    //         00484e12     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
    //         00484e15     MOV        this,byte ptr [ESP + param_1.elevation]
    //         00484e1c     SHL        this,0x5
    //         00484e1f     LEA        EAX,[EDX + EAX*0x8 + 0x5]
    //         00484e23     MOV        DL,byte ptr [EAX]
    //         00484e25     AND        DL,0x1f
    //         00484e28     OR         this,DL
    //         00484e2a     MOV        byte ptr [EAX],this
    //                              rmm_elev.cpp:340 (8)
    //         00484e2c     MOV        EAX,dword ptr [ESP + y]
    //         00484e30     TEST       EAX,EAX
    //         00484e32     JLE        LAB_00484e4b
    //                              rmm_elev.cpp:341 (23)
    //         00484e34     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484e38     PUSH       0x0
    //         00484e3a     PUSH       0x0
    //         00484e3c     DEC        EAX
    //         00484e3d     PUSH       this
    //         00484e3e     PUSH       EAX
    //         00484e3f     PUSH       EDI
    //         00484e40     MOV        this,ESI
    //         00484e42     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00484e47     MOV        EAX,dword ptr [ESP + y]
    //                               LAB_00484e4b                                                 XREF[1]:     00484e32(j)  
    //                              rmm_elev.cpp:343 (8)
    //         00484e4b     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484e4f     TEST       this,this
    //         00484e51     JLE        LAB_00484e6a
    //                              rmm_elev.cpp:344 (23)
    //         00484e53     PUSH       0x0
    //         00484e55     DEC        this
    //         00484e56     PUSH       0x0
    //         00484e58     PUSH       this
    //         00484e59     PUSH       EAX
    //         00484e5a     PUSH       EDI
    //         00484e5b     MOV        this,ESI
    //         00484e5d     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00484e62     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484e66     MOV        EAX,dword ptr [ESP + y]
    //                               LAB_00484e6a                                                 XREF[1]:     00484e51(j)  
    //                              rmm_elev.cpp:346 (8)
    //         00484e6a     MOV        EDX,dword ptr [ESI + 0x14]
    //         00484e6d     DEC        EDX
    //         00484e6e     CMP        EAX,EDX
    //         00484e70     JGE        LAB_00484e89
    //                              rmm_elev.cpp:347 (23)
    //         00484e72     PUSH       0x0
    //         00484e74     PUSH       0x0
    //         00484e76     INC        EAX
    //         00484e77     PUSH       this
    //         00484e78     PUSH       EAX
    //         00484e79     PUSH       EDI
    //         00484e7a     MOV        this,ESI
    //         00484e7c     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00484e81     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484e85     MOV        EAX,dword ptr [ESP + y]
    //                               LAB_00484e89                                                 XREF[1]:     00484e70(j)  
    //                              rmm_elev.cpp:349 (8)
    //         00484e89     MOV        EDX,dword ptr [ESI + 0x18]
    //         00484e8c     DEC        EDX
    //         00484e8d     CMP        this,EDX
    //         00484e8f     JGE        LAB_00484ea0
    //                              rmm_elev.cpp:350 (15)
    //         00484e91     PUSH       0x0
    //         00484e93     INC        this
    //         00484e94     PUSH       0x0
    //         00484e96     PUSH       this
    //         00484e97     PUSH       EAX
    //         00484e98     PUSH       EDI
    //         00484e99     MOV        this,ESI
    //         00484e9b     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_00484ea0                                                 XREF[1]:     00484e8f(j)  
    //                              rmm_elev.cpp:352 (5)
    //         00484ea0     MOV        EDX,dword ptr [ESP + chance]
    //         00484ea4     INC        EDX
    //                              rmm_elev.cpp:353 (21)
    //         00484ea5     INC        EBX
    //         00484ea6     MOV        dword ptr [ESP + chance],EDX
    //         00484eaa     ADD        EDI,0x18
    //                               LAB_00484ead                                                 XREF[2]:     00484dc3(j), 00484dec(j)  
    //         00484ead     CMP        EBX,dword ptr [ESP + param_1.clumps]
    //         00484eb4     JL         LAB_00484d8e
    //                               LAB_00484eba                                                 XREF[1]:     00484dab(j)  
    //                              rmm_elev.cpp:329 (7)
    //         00484eba     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //                               LAB_00484ec1                                                 XREF[2]:     00484d84(j), 004851cc(j)  
    //                              rmm_elev.cpp:364 (28)
    //         00484ec1     TEST       EAX,EAX
    //         00484ec3     MOV        byte ptr [ESP + local_97d],0x1
    //         00484ec8     JLE        LAB_004851c6
    //         00484ece     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //         00484ed5     LEA        EBX=>stack[0].y,[ESP + 0x50]
    //         00484ed9     MOV        dword ptr [ESP + max_y],EAX
    //                               LAB_00484edd                                                 XREF[1]:     004851b9(j)  
    //                              rmm_elev.cpp:365 (19)
    //         00484edd     MOV        this,dword ptr [ESP + chance]
    //         00484ee1     MOV        EAX,dword ptr [ESP + param_1.elevation_size]
    //         00484ee8     CMP        this,EAX
    //         00484eea     JGE        LAB_004851ad
    //                              rmm_elev.cpp:366 (31)
    //         00484ef0     LEA        EDX=>max_x,[ESP + 0x30]
    //         00484ef4     LEA        EAX=>Stack[-0x984],[ESP + 0x14]
    //         00484ef8     PUSH       EDX
    //         00484ef9     LEA        this=>y,[ESP + 0x14]
    //         00484efd     PUSH       EAX
    //         00484efe     PUSH       this
    //         00484eff     PUSH       EBX
    //         00484f00     MOV        this,ESI
    //         00484f02     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00484f07     TEST       EAX,EAX
    //         00484f09     JZ         LAB_004851ad
    //                              rmm_elev.cpp:369 (88)
    //         00484f0f     MOV        EDX,dword ptr [ESP + Stack[-0x984]]
    //         00484f13     MOV        EAX,dword ptr [ESI + 0x24]
    //         00484f16     PUSH       0x171
    //         00484f1b     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         00484f20     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00484f23     LEA        EDI,[EDX*0x4 + 0x0]
    //         00484f2a     MOV        EDX,dword ptr [ESP + y]
    //         00484f2e     MOV        byte ptr [ESP + local_97d],0x0
    //         00484f33     LEA        EBP,[this->_padding_ + EDX*0x1]
    //         00484f36     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00484f3b     LEA        EAX,[EAX + EAX*0x4]
    //         00484f3e     ADD        ESP,0x8
    //         00484f41     LEA        this,[EAX + EAX*0x4]
    //         00484f44     MOV        EAX,0x80010003
    //         00484f49     SHL        this,0x2
    //         00484f4c     IMUL       this
    //         00484f4e     ADD        EDX,this
    //         00484f50     XOR        this,this
    //         00484f52     MOV        this,byte ptr [EBP]
    //         00484f55     SAR        EDX,0xe
    //         00484f58     MOV        EAX,EDX
    //         00484f5a     SHR        EAX,0x1f
    //         00484f5d     ADD        EDX,EAX
    //         00484f5f     CMP        this,EDX
    //         00484f61     JG         LAB_004851a9
    //                              rmm_elev.cpp:371 (7)
    //         00484f67     MOV        EDX,dword ptr [ESI + 0x10]
    //         00484f6a     MOV        EAX,dword ptr [ESP + y]
    //                              rmm_elev.cpp:372 (54)
    //         00484f6e     MOV        EBP,dword ptr [ESP + param_1.base_elevation]
    //         00484f75     MOV        EDX,dword ptr [EDX + EDI*0x1]
    //         00484f78     LEA        this,[EAX + EAX*0x2]
    //         00484f7b     PUSH       EBP
    //         00484f7c     LEA        EDI,[EDX + this->_padding_*0x8]
    //         00484f7f     MOV        this,dword ptr [ESP + param_1.base_terrain_type]
    //         00484f86     MOV        EDX,dword ptr [ESP + param_1.spacing]
    //         00484f8d     PUSH       this
    //         00484f8e     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00484f92     PUSH       EDX
    //         00484f93     MOV        EDX,dword ptr [ESP + param_1.elevation]
    //         00484f9a     PUSH       this
    //         00484f9b     PUSH       EAX
    //         00484f9c     PUSH       EDX
    //         00484f9d     MOV        this,ESI
    //         00484f9f     CALL       RGE_RMM_Elevation_Generator::check_elevation     uchar check_elevation(RGE_RMM_Elevation_Gener
    //                              rmm_elev.cpp:374 (29)
    //         00484fa4     XOR        this,this
    //         00484fa6     AND        EAX,0xff
    //         00484fab     MOV        this,byte ptr [EDI + 0x5]
    //         00484fae     SHR        this,0x5
    //         00484fb1     CMP        this,EBP
    //         00484fb3     JNZ        LAB_004851ad
    //         00484fb9     TEST       EAX,EAX
    //         00484fbb     JLE        LAB_004851ad
    //                              rmm_elev.cpp:376 (18)
    //         00484fc1     MOV        EDX,dword ptr [ESP + Stack[-0x984]]
    //         00484fc5     MOV        this,dword ptr [ESP + y]
    //         00484fc9     PUSH       EDX
    //         00484fca     PUSH       this
    //         00484fcb     PUSH       EAX
    //         00484fcc     MOV        this,ESI
    //         00484fce     CALL       RGE_RMM_Elevation_Generator::fig_chance          float fig_chance(RGE_RMM_Elevation_Generator 
    //                              rmm_elev.cpp:377 (24)
    //         00484fd3     MOV        DL,byte ptr [ESP + param_1.elevation]
    //         00484fda     MOV        AL,byte ptr [EDI + 0x5]
    //         00484fdd     FSTP       float ptr [ESP + local_974]
    //         00484fe1     SHL        DL,0x5
    //         00484fe4     AND        AL,0x1f
    //         00484fe6     OR         DL,AL
    //         00484fe8     MOV        byte ptr [EDI + 0x5],DL
    //                              rmm_elev.cpp:380 (20)
    //         00484feb     MOV        EAX,dword ptr [ESP + y]
    //         00484fef     TEST       EAX,EAX
    //         00484ff1     JLE        LAB_00485052
    //         00484ff3     XOR        this,this
    //         00484ff5     MOV        this,byte ptr [EDI + -0x13]
    //         00484ff8     SHR        this,0x5
    //         00484ffb     CMP        this,EBP
    //         00484ffd     JNZ        LAB_00485052
    //                              rmm_elev.cpp:381 (83)
    //         00484fff     PUSH       0x17d
    //         00485004     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         00485009     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0048500e     LEA        EAX,[EAX + EAX*0x4]
    //         00485011     ADD        ESP,0x8
    //         00485014     LEA        this,[EAX + EAX*0x4]
    //         00485017     MOV        EAX,0x80010003
    //         0048501c     SHL        this,0x2
    //         0048501f     IMUL       this
    //         00485021     ADD        EDX,this
    //         00485023     PUSH       this
    //         00485024     SAR        EDX,0xe
    //         00485027     MOV        EAX,EDX
    //         00485029     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         0048502d     SHR        EAX,0x1f
    //         00485030     ADD        EDX,EAX
    //         00485032     MOV        dword ptr [ESP + clump_size],EDX
    //         00485036     MOV        EDX,dword ptr [ESP + y]
    //         0048503a     FILD       dword ptr [ESP + clump_size]
    //         0048503e     DEC        EDX
    //         0048503f     FADD       float ptr [ESP + local_974]
    //         00485043     FSTP       float ptr [ESP]=>local_99c
    //         00485046     PUSH       0x0
    //         00485048     PUSH       this
    //         00485049     PUSH       EDX
    //         0048504a     PUSH       EBX
    //         0048504b     MOV        this,ESI
    //         0048504d     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_00485052                                                 XREF[2]:     00484ff1(j), 00484ffd(j)  
    //                              rmm_elev.cpp:382 (24)
    //         00485052     MOV        EAX,dword ptr [ESP + y]
    //         00485056     MOV        this,dword ptr [ESP + loc_stack.x]
    //         0048505a     CMP        EAX,this
    //         0048505c     JGE        LAB_004850bd
    //         0048505e     XOR        this,this
    //         00485060     MOV        this,byte ptr [EDI + 0x1d]
    //         00485063     SHR        this,0x5
    //         00485066     CMP        this,EBP
    //         00485068     JNZ        LAB_004850bd
    //                              rmm_elev.cpp:383 (83)
    //         0048506a     PUSH       0x17f
    //         0048506f     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         00485074     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00485079     LEA        EAX,[EAX + EAX*0x4]
    //         0048507c     ADD        ESP,0x8
    //         0048507f     LEA        this,[EAX + EAX*0x4]
    //         00485082     MOV        EAX,0x80010003
    //         00485087     SHL        this,0x2
    //         0048508a     IMUL       this
    //         0048508c     ADD        EDX,this
    //         0048508e     PUSH       this
    //         0048508f     SAR        EDX,0xe
    //         00485092     MOV        EAX,EDX
    //         00485094     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         00485098     SHR        EAX,0x1f
    //         0048509b     ADD        EDX,EAX
    //         0048509d     MOV        dword ptr [ESP + clump_size],EDX
    //         004850a1     MOV        EDX,dword ptr [ESP + y]
    //         004850a5     FILD       dword ptr [ESP + clump_size]
    //         004850a9     INC        EDX
    //         004850aa     FADD       float ptr [ESP + local_974]
    //         004850ae     FSTP       float ptr [ESP]=>local_99c
    //         004850b1     PUSH       0x0
    //         004850b3     PUSH       this
    //         004850b4     PUSH       EDX
    //         004850b5     PUSH       EBX
    //         004850b6     MOV        this,ESI
    //         004850b8     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_004850bd                                                 XREF[2]:     0048505c(j), 00485068(j)  
    //                              rmm_elev.cpp:384 (33)
    //         004850bd     MOV        EAX,dword ptr [ESP + Stack[-0x984]]
    //         004850c1     TEST       EAX,EAX
    //         004850c3     JLE        LAB_00485131
    //         004850c5     MOV        EAX,dword ptr [ESI + 0x14]
    //         004850c8     MOV        this,EDI
    //         004850ca     XOR        EDX,EDX
    //         004850cc     LEA        EAX,[EAX + EAX*0x2]
    //         004850cf     SHL        EAX,0x3
    //         004850d2     SUB        this,EAX
    //         004850d4     MOV        DL,byte ptr [ECX + this+0x5]
    //         004850d7     SHR        EDX,0x5
    //         004850da     CMP        EDX,EBP
    //         004850dc     JNZ        LAB_00485131
    //                              rmm_elev.cpp:385 (83)
    //         004850de     PUSH       0x181
    //         004850e3     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         004850e8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004850ed     LEA        EAX,[EAX + EAX*0x4]
    //         004850f0     ADD        ESP,0x8
    //         004850f3     LEA        this,[EAX + EAX*0x4]
    //         004850f6     MOV        EAX,0x80010003
    //         004850fb     SHL        this,0x2
    //         004850fe     IMUL       this
    //         00485100     ADD        EDX,this
    //         00485102     PUSH       this
    //         00485103     SAR        EDX,0xe
    //         00485106     MOV        EAX,EDX
    //         00485108     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         0048510c     SHR        EAX,0x1f
    //         0048510f     ADD        EDX,EAX
    //         00485111     DEC        this
    //         00485112     MOV        dword ptr [ESP + clump_size],EDX
    //         00485116     MOV        EDX,dword ptr [ESP + y]
    //         0048511a     FILD       dword ptr [ESP + clump_size]
    //         0048511e     FADD       float ptr [ESP + local_974]
    //         00485122     FSTP       float ptr [ESP]=>local_99c
    //         00485125     PUSH       0x0
    //         00485127     PUSH       this
    //         00485128     PUSH       EDX
    //         00485129     PUSH       EBX
    //         0048512a     MOV        this,ESI
    //         0048512c     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_00485131                                                 XREF[2]:     004850c3(j), 004850dc(j)  
    //                              rmm_elev.cpp:386 (31)
    //         00485131     MOV        EAX,dword ptr [ESP + Stack[-0x984]]
    //         00485135     MOV        this,dword ptr [ESP + in_zone]
    //         00485139     CMP        EAX,this
    //         0048513b     JGE        LAB_004851a3
    //         0048513d     MOV        EAX,dword ptr [ESI + 0x14]
    //         00485140     XOR        EDX,EDX
    //         00485142     LEA        this,[EAX + EAX*0x2]
    //         00485145     MOV        DL,byte ptr [EDI + this->_padding_*0x8 + 0x5]
    //         00485149     SHR        EDX,0x5
    //         0048514c     CMP        EDX,EBP
    //         0048514e     JNZ        LAB_004851a3
    //                              rmm_elev.cpp:387 (83)
    //         00485150     PUSH       0x183
    //         00485155     PUSH       s_C:\msdev\work\age1_x1\rmm_elev.c               = "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp"
    //         0048515a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0048515f     LEA        EAX,[EAX + EAX*0x4]
    //         00485162     ADD        ESP,0x8
    //         00485165     LEA        this,[EAX + EAX*0x4]
    //         00485168     MOV        EAX,0x80010003
    //         0048516d     SHL        this,0x2
    //         00485170     IMUL       this
    //         00485172     ADD        EDX,this
    //         00485174     PUSH       this
    //         00485175     SAR        EDX,0xe
    //         00485178     MOV        EAX,EDX
    //         0048517a     MOV        this,dword ptr [ESP + Stack[-0x984]]
    //         0048517e     SHR        EAX,0x1f
    //         00485181     ADD        EDX,EAX
    //         00485183     INC        this
    //         00485184     MOV        dword ptr [ESP + clump_size],EDX
    //         00485188     MOV        EDX,dword ptr [ESP + y]
    //         0048518c     FILD       dword ptr [ESP + clump_size]
    //         00485190     FADD       float ptr [ESP + local_974]
    //         00485194     FSTP       float ptr [ESP]=>local_99c
    //         00485197     PUSH       0x0
    //         00485199     PUSH       this
    //         0048519a     PUSH       EDX
    //         0048519b     PUSH       EBX
    //         0048519c     MOV        this,ESI
    //         0048519e     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_004851a3                                                 XREF[2]:     0048513b(j), 0048514e(j)  
    //                              rmm_elev.cpp:388 (4)
    //         004851a3     INC        dword ptr [ESP + chance]
    //                              rmm_elev.cpp:391 (2)
    //         004851a7     JMP        LAB_004851ad
    //                               LAB_004851a9                                                 XREF[1]:     00484f61(j)  
    //                              rmm_elev.cpp:394 (4)
    //         004851a9     MOV        byte ptr [EBP],0x65
    //                               LAB_004851ad                                                 XREF[5]:     00484eea(j), 00484f09(j), 
    //                                                                                                         00484fb3(j), 00484fbb(j), 
    //                                                                                                         004851a7(j)  
    //                              rmm_elev.cpp:364 (25)
    //         004851ad     MOV        EAX,dword ptr [ESP + max_y]
    //         004851b1     ADD        EBX,0x18
    //         004851b4     DEC        EAX
    //         004851b5     MOV        dword ptr [ESP + max_y],EAX
    //         004851b9     JNZ        LAB_00484edd
    //         004851bf     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //                               LAB_004851c6                                                 XREF[1]:     00484ec8(j)  
    //                              rmm_elev.cpp:361 (12)
    //         004851c6     MOV        this,byte ptr [ESP + local_97d]
    //         004851ca     TEST       this,this
    //         004851cc     JZ         LAB_00484ec1
    //                              rmm_elev.cpp:399 (4)
    //         004851d2     TEST       EAX,EAX
    //         004851d4     JLE        LAB_004851ea
    //                              rmm_elev.cpp:403 (35)
    //         004851d6     LEA        EDI=>stack[0].y,[ESP + 0x50]
    //         004851da     MOV        EBX,EAX
    //                               LAB_004851dc                                                 XREF[1]:     004851e8(j)  
    //         004851dc     PUSH       EDI
    //         004851dd     MOV        this,ESI
    //         004851df     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
    //         004851e4     ADD        EDI,0x18
    //         004851e7     DEC        EBX
    //         004851e8     JNZ        LAB_004851dc
    //                               LAB_004851ea                                                 XREF[1]:     004851d4(j)  
    //         004851ea     POP        EDI
    //         004851eb     POP        ESI
    //         004851ec     POP        EBP
    //         004851ed     MOV        AL,0x1
    //         004851ef     POP        EBX
    //         004851f0     ADD        ESP,0x988
    //         004851f6     RET        0x18
    //         004851f9     ??         90h
    //         004851fa     NOP
    //         004851fb     NOP
    //         004851fc     NOP
    //         004851fd     NOP
    //         004851fe     NOP
    //         004851ff     NOP
    //                              * public: __thiscall RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(class RGE_Map *,class RGE_Random... *
    //                              undefined __thiscall RGE_RMM_Land_Generator(RGE_RMM_Land_Generator *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00485208(R)  
    //              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     00485200(R)  
    //              RGE_Land_Info *   Stack[0xc]:4   param_3                   XREF[1]:     00485218(R)  
    //                               ??0RGE_RMM_Land_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random_Ma  XREF[2]:     add_land_module:00482698(c), 
    //                               RGE_RMM_Land_Generator::RGE_RMM_Land_Generator                            generate:004834a9(c)  
    //                              rmm_land.cpp:25 (24)
    //         00485200     MOV        EAX,dword ptr [ESP + param_2]
    //         00485204     PUSH       EBX
    //         00485205     PUSH       ESI
    //         00485206     MOV        EBX,this
    //         00485208     MOV        this,dword ptr [ESP + param_1]
    //         0048520c     PUSH       EDI
    //         0048520d     PUSH       0x1
    //         0048520f     PUSH       EAX
    //         00485210     PUSH       this
    //         00485211     MOV        this,EBX
    //         00485213     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_land.cpp:28 (25)
    //         00485218     MOV        ESI,dword ptr [ESP + param_3]
    //         0048521c     MOV        this,0x50e
    //         00485221     LEA        EDI,[EBX + 0x30]
    //         00485224     MOV        dword ptr [EBX],RGE_RMM_Land_Generator::`vftab   = 00485240
    //         0048522a     MOV        dword ptr [EBX + 0x1c],0x3f800000
    //                              rmm_land.cpp:29 (10)
    //         00485231     MOV        EAX,EBX
    //         00485233     MOVSD.REP  ES:EDI,ESI
    //         00485235     POP        EDI
    //         00485236     POP        ESI
    //         00485237     POP        EBX
    //         00485238     RET        0xc
    //         0048523b     ??         90h
    //         0048523c     NOP
    //         0048523d     NOP
    //         0048523e     NOP
    //         0048523f     NOP
    return;
}

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Elevation_Info* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

uchar RGE_RMM_Elevation_Generator::check_start_elevation(long param_1, long param_2, uchar param_3, uchar param_4, uchar param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_RMM_Elevation_Generator::check_elevation(uchar param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_RMM_Elevation_Generator::base_elevation_generate(RGE_Elevation_Info_Line param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

