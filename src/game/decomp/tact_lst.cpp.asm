// Auto-generated scaffold unit: tact_lst.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tact_lst.cpp
#include "../include/common.h"

// Offset: 0x004D0150
undefined TRIBE_Action_List(TRIBE_Action_List* this_, RGE_Action_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Action_List::TRIBE_Action_List(class RGE_Action_Object *)                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Action_List(TRIBE_Action_List * this, RGE
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Action_L    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d0150(R)  
    //                               ??0TRIBE_Action_List@@QAE@PAVRGE_Action_Object@@@Z           XREF[2]:     create_action_list:004ca546(c), 
    //                               TRIBE_Action_List::TRIBE_Action_List                                      create_action_list:004d3a49(c)  
    //                              tact_lst.cpp:37 (19)
    //         004d0150     MOV        EAX,dword ptr [ESP + param_1]
    //         004d0154     PUSH       ESI
    //         004d0155     MOV        ESI,this
    //         004d0157     PUSH       EAX
    //         004d0158     CALL       RGE_Action_List::RGE_Action_List                 undefined RGE_Action_List(RGE_Action_List * t
    //         004d015d     MOV        dword ptr [ESI],TRIBE_Action_List::`vftable'     = 004d0170
    //                              tact_lst.cpp:38 (6)
    //         004d0163     MOV        EAX,ESI
    //         004d0165     POP        ESI
    //         004d0166     RET        0x4
}

// Offset: 0x004D0170
RGE_Action* TRIBE_Action_List::create_action(int param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Action * __thiscall TRIBE_Action_List::create_action(int,short)             *
    //                              *********************************************************************************************************
    //                              RGE_Action * __thiscall create_action(TRIBE_Action_List * this, int 
    //              RGE_Action *      EAX:4          <RETURN>
    //              TRIBE_Action_L    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[14]:    004d01cb(R), 004d020b(R), 004d024b(R), 004d028b(R), 
    //                                                                                     004d02cb(R), 004d030b(R), 004d034b(R), 004d038b(R), 
    //                                                                                     004d03cb(R), 004d040b(R), 004d044d(R), 004d0489(R), 
    //                                                                                     004d04c5(R), 004d04f8(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[14]:    004d0188(R), 004d01b4(W), 004d01f4(W), 004d0234(W), 
    //                                                                                     004d0274(W), 004d02b4(W), 004d02f4(W), 004d0334(W), 
    //                                                                                     004d0374(W), 004d03b4(W), 004d03f4(W), 004d0436(W), 
    //                                                                                     004d0476(W), 004d04b2(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[13]:    004d01ba(W), 004d01fa(W), 004d023a(W), 004d027a(W), 
    //                                                                                     004d02ba(W), 004d02fa(W), 004d033a(W), 004d037a(W), 
    //                                                                                     004d03ba(W), 004d03fa(W), 004d043c(W), 004d047c(W), 
    //                                                                                     004d04b8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[15]:    004d01d8(R), 004d0218(R), 004d0258(R), 004d0298(R), 
    //                                                                                     004d02d8(R), 004d0318(R), 004d0358(R), 004d0398(R), 
    //                                                                                     004d03d8(R), 004d041a(R), 004d045a(R), 004d0496(R), 
    //                                                                                     004d04d2(R), 004d04e6(R), 004d0505(R)  
    //                               ?create_action@TRIBE_Action_List@@UAEPAVRGE_Action@@HF@Z     XREF[1]:     00575170(*)  
    //                               TRIBE_Action_List::create_action
    //                              tact_lst.cpp:43 (24)
    //         004d0170     MOV        EAX,FS:[0x0]
    //         004d0176     PUSH       -0x1
    //         004d0178     PUSH       FUN_0055ffaf
    //         004d017d     PUSH       EAX
    //         004d017e     MOV        dword ptr FS:[0x0],ESP
    //         004d0185     PUSH       ESI
    //         004d0186     MOV        ESI,this
    //                              tact_lst.cpp:44 (34)
    //         004d0188     MOV        this,dword ptr [ESP + param_2]
    //         004d018c     MOVSX      EAX,this
    //         004d018f     ADD        EAX,-0x3
    //         004d0192     CMP        EAX,0x75
    //         004d0195     JA         switchD_004d01a3::caseD_4
    //         004d019b     XOR        EDX,EDX
    //         004d019d     MOV        DL,byte ptr [EAX + 0x4d0550]=>PTR_caseD_4_004d
    //                               switchD_004d01a3::switchD
    //         004d01a3     JMP        dword ptr [EDX*0x4 + switchD_004d01a3::switchd   = 004d04a8
    //                               switchD_004d01a3::caseD_65                                   XREF[2]:     004d01a3(j), 004d0520(*)  
    //                              tact_lst.cpp:47 (46)
    //         004d01aa     PUSH       0x40
    //         004d01ac     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d01b1     ADD        ESP,0x4
    //         004d01b4     MOV        dword ptr [ESP + param_2],EAX
    //         004d01b8     TEST       EAX,EAX
    //         004d01ba     MOV        dword ptr [ESP + local_4],0x0
    //         004d01c2     JZ         LAB_004d04e4
    //         004d01c8     MOV        this,dword ptr [ESI + 0x4]
    //         004d01cb     MOV        EDX,dword ptr [ESP + param_1]
    //         004d01cf     PUSH       this
    //         004d01d0     PUSH       EDX
    //         004d01d1     MOV        this,EAX
    //         004d01d3     CALL       TRIBE_Action_Build::TRIBE_Action_Build           undefined TRIBE_Action_Build(TRIBE_Action_Bui
    //                              tact_lst.cpp:88 (18)
    //         004d01d8     MOV        this,dword ptr [ESP + local_c]
    //         004d01dc     MOV        dword ptr FS:[0x0],this
    //         004d01e3     POP        ESI
    //         004d01e4     ADD        ESP,0xc
    //         004d01e7     RET        0x8
    //                               switchD_004d01a3::caseD_66                                   XREF[2]:     004d01a3(j), 004d0524(*)  
    //                              tact_lst.cpp:50 (46)
    //         004d01ea     PUSH       0x50
    //         004d01ec     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d01f1     ADD        ESP,0x4
    //         004d01f4     MOV        dword ptr [ESP + param_2],EAX
    //         004d01f8     TEST       EAX,EAX
    //         004d01fa     MOV        dword ptr [ESP + local_4],0x1
    //         004d0202     JZ         LAB_004d04e4
    //         004d0208     MOV        this,dword ptr [ESI + 0x4]
    //         004d020b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d020f     PUSH       this
    //         004d0210     PUSH       EDX
    //         004d0211     MOV        this,EAX
    //         004d0213     CALL       TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj     undefined TRIBE_Action_Make_Obj(TRIBE_Action_
    //                              tact_lst.cpp:88 (18)
    //         004d0218     MOV        this,dword ptr [ESP + local_c]
    //         004d021c     MOV        dword ptr FS:[0x0],this
    //         004d0223     POP        ESI
    //         004d0224     ADD        ESP,0xc
    //         004d0227     RET        0x8
    //                               switchD_004d01a3::caseD_67                                   XREF[2]:     004d01a3(j), 004d0528(*)  
    //                              tact_lst.cpp:53 (46)
    //         004d022a     PUSH       0x48
    //         004d022c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0231     ADD        ESP,0x4
    //         004d0234     MOV        dword ptr [ESP + param_2],EAX
    //         004d0238     TEST       EAX,EAX
    //         004d023a     MOV        dword ptr [ESP + local_4],0x2
    //         004d0242     JZ         LAB_004d04e4
    //         004d0248     MOV        this,dword ptr [ESI + 0x4]
    //         004d024b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d024f     PUSH       this
    //         004d0250     PUSH       EDX
    //         004d0251     MOV        this,EAX
    //         004d0253     CALL       TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech   undefined TRIBE_Action_Make_Tech(TRIBE_Action
    //                              tact_lst.cpp:88 (18)
    //         004d0258     MOV        this,dword ptr [ESP + local_c]
    //         004d025c     MOV        dword ptr FS:[0x0],this
    //         004d0263     POP        ESI
    //         004d0264     ADD        ESP,0xc
    //         004d0267     RET        0x8
    //                               switchD_004d01a3::caseD_68                                   XREF[2]:     004d01a3(j), 004d052c(*)  
    //                              tact_lst.cpp:56 (46)
    //         004d026a     PUSH       0x48
    //         004d026c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0271     ADD        ESP,0x4
    //         004d0274     MOV        dword ptr [ESP + param_2],EAX
    //         004d0278     TEST       EAX,EAX
    //         004d027a     MOV        dword ptr [ESP + local_4],0x3
    //         004d0282     JZ         LAB_004d04e4
    //         004d0288     MOV        this,dword ptr [ESI + 0x4]
    //         004d028b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d028f     PUSH       this
    //         004d0290     PUSH       EDX
    //         004d0291     MOV        this,EAX
    //         004d0293     CALL       TRIBE_Action_Convert::TRIBE_Action_Convert       undefined TRIBE_Action_Convert(TRIBE_Action_C
    //                              tact_lst.cpp:88 (18)
    //         004d0298     MOV        this,dword ptr [ESP + local_c]
    //         004d029c     MOV        dword ptr FS:[0x0],this
    //         004d02a3     POP        ESI
    //         004d02a4     ADD        ESP,0xc
    //         004d02a7     RET        0x8
    //                               switchD_004d01a3::caseD_69                                   XREF[2]:     004d01a3(j), 004d0530(*)  
    //                              tact_lst.cpp:59 (46)
    //         004d02aa     PUSH       0x40
    //         004d02ac     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d02b1     ADD        ESP,0x4
    //         004d02b4     MOV        dword ptr [ESP + param_2],EAX
    //         004d02b8     TEST       EAX,EAX
    //         004d02ba     MOV        dword ptr [ESP + local_4],0x4
    //         004d02c2     JZ         LAB_004d04e4
    //         004d02c8     MOV        this,dword ptr [ESI + 0x4]
    //         004d02cb     MOV        EDX,dword ptr [ESP + param_1]
    //         004d02cf     PUSH       this
    //         004d02d0     PUSH       EDX
    //         004d02d1     MOV        this,EAX
    //         004d02d3     CALL       TRIBE_Action_Heal::TRIBE_Action_Heal             undefined TRIBE_Action_Heal(TRIBE_Action_Heal
    //                              tact_lst.cpp:88 (18)
    //         004d02d8     MOV        this,dword ptr [ESP + local_c]
    //         004d02dc     MOV        dword ptr FS:[0x0],this
    //         004d02e3     POP        ESI
    //         004d02e4     ADD        ESP,0xc
    //         004d02e7     RET        0x8
    //                               switchD_004d01a3::caseD_6b                                   XREF[2]:     004d01a3(j), 004d0538(*)  
    //                              tact_lst.cpp:62 (46)
    //         004d02ea     PUSH       0x40
    //         004d02ec     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d02f1     ADD        ESP,0x4
    //         004d02f4     MOV        dword ptr [ESP + param_2],EAX
    //         004d02f8     TEST       EAX,EAX
    //         004d02fa     MOV        dword ptr [ESP + local_4],0x5
    //         004d0302     JZ         LAB_004d04e4
    //         004d0308     MOV        this,dword ptr [ESI + 0x4]
    //         004d030b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d030f     PUSH       this
    //         004d0310     PUSH       EDX
    //         004d0311     MOV        this,EAX
    //         004d0313     CALL       TRIBE_Action_Artifact::TRIBE_Action_Artifact     undefined TRIBE_Action_Artifact(TRIBE_Action_
    //                              tact_lst.cpp:88 (18)
    //         004d0318     MOV        this,dword ptr [ESP + local_c]
    //         004d031c     MOV        dword ptr FS:[0x0],this
    //         004d0323     POP        ESI
    //         004d0324     ADD        ESP,0xc
    //         004d0327     RET        0x8
    //                               switchD_004d01a3::caseD_78                                   XREF[2]:     004d01a3(j), 004d0548(*)  
    //                              tact_lst.cpp:65 (46)
    //         004d032a     PUSH       0x40
    //         004d032c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0331     ADD        ESP,0x4
    //         004d0334     MOV        dword ptr [ESP + param_2],EAX
    //         004d0338     TEST       EAX,EAX
    //         004d033a     MOV        dword ptr [ESP + local_4],0x6
    //         004d0342     JZ         LAB_004d04e4
    //         004d0348     MOV        this,dword ptr [ESI + 0x4]
    //         004d034b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d034f     PUSH       this
    //         004d0350     PUSH       EDX
    //         004d0351     MOV        this,EAX
    //         004d0353     CALL       TRIBE_Action_Wonder::TRIBE_Action_Wonder         undefined TRIBE_Action_Wonder(TRIBE_Action_Wo
    //                              tact_lst.cpp:88 (18)
    //         004d0358     MOV        this,dword ptr [ESP + local_c]
    //         004d035c     MOV        dword ptr FS:[0x0],this
    //         004d0363     POP        ESI
    //         004d0364     ADD        ESP,0xc
    //         004d0367     RET        0x8
    //                               switchD_004d01a3::caseD_6c                                   XREF[2]:     004d01a3(j), 004d053c(*)  
    //                              tact_lst.cpp:68 (46)
    //         004d036a     PUSH       0x44
    //         004d036c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0371     ADD        ESP,0x4
    //         004d0374     MOV        dword ptr [ESP + param_2],EAX
    //         004d0378     TEST       EAX,EAX
    //         004d037a     MOV        dword ptr [ESP + local_4],0x7
    //         004d0382     JZ         LAB_004d04e4
    //         004d0388     MOV        this,dword ptr [ESI + 0x4]
    //         004d038b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d038f     PUSH       this
    //         004d0390     PUSH       EDX
    //         004d0391     MOV        this,EAX
    //         004d0393     CALL       TRIBE_Action_Discovery_Artifact::TRIBE_Action_   undefined TRIBE_Action_Discovery_Artifact(TRI
    //                              tact_lst.cpp:88 (18)
    //         004d0398     MOV        this,dword ptr [ESP + local_c]
    //         004d039c     MOV        dword ptr FS:[0x0],this
    //         004d03a3     POP        ESI
    //         004d03a4     ADD        ESP,0xc
    //         004d03a7     RET        0x8
    //                               switchD_004d01a3::caseD_6e                                   XREF[2]:     004d01a3(j), 004d0540(*)  
    //                              tact_lst.cpp:71 (46)
    //         004d03aa     PUSH       0x44
    //         004d03ac     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d03b1     ADD        ESP,0x4
    //         004d03b4     MOV        dword ptr [ESP + param_2],EAX
    //         004d03b8     TEST       EAX,EAX
    //         004d03ba     MOV        dword ptr [ESP + local_4],0x8
    //         004d03c2     JZ         LAB_004d04e4
    //         004d03c8     MOV        this,dword ptr [ESI + 0x4]
    //         004d03cb     MOV        EDX,dword ptr [ESP + param_1]
    //         004d03cf     PUSH       this
    //         004d03d0     PUSH       EDX
    //         004d03d1     MOV        this,EAX
    //         004d03d3     CALL       TRIBE_Action_Hunt::TRIBE_Action_Hunt             undefined TRIBE_Action_Hunt(TRIBE_Action_Hunt
    //                              tact_lst.cpp:88 (18)
    //         004d03d8     MOV        this,dword ptr [ESP + local_c]
    //         004d03dc     MOV        dword ptr FS:[0x0],this
    //         004d03e3     POP        ESI
    //         004d03e4     ADD        ESP,0xc
    //         004d03e7     RET        0x8
    //                               switchD_004d01a3::caseD_6a                                   XREF[2]:     004d01a3(j), 004d0534(*)  
    //                              tact_lst.cpp:74 (48)
    //         004d03ea     PUSH       0x44
    //         004d03ec     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d03f1     ADD        ESP,0x4
    //         004d03f4     MOV        dword ptr [ESP + param_2],EAX
    //         004d03f8     TEST       EAX,EAX
    //         004d03fa     MOV        dword ptr [ESP + local_4],0x9
    //         004d0402     JZ         LAB_004d04e4
    //         004d0408     MOV        this,dword ptr [ESI + 0x4]
    //         004d040b     MOV        EDX,dword ptr [ESP + param_1]
    //         004d040f     PUSH       0x1
    //         004d0411     PUSH       this
    //         004d0412     PUSH       EDX
    //         004d0413     MOV        this,EAX
    //         004d0415     CALL       TRIBE_Action_Repair::TRIBE_Action_Repair         undefined TRIBE_Action_Repair(TRIBE_Action_Re
    //                              tact_lst.cpp:88 (18)
    //         004d041a     MOV        this,dword ptr [ESP + local_c]
    //         004d041e     MOV        dword ptr FS:[0x0],this
    //         004d0425     POP        ESI
    //         004d0426     ADD        ESP,0xc
    //         004d0429     RET        0x8
    //                               switchD_004d01a3::caseD_6f                                   XREF[2]:     004d01a3(j), 004d0544(*)  
    //                              tact_lst.cpp:77 (46)
    //         004d042c     PUSH       0x48
    //         004d042e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0433     ADD        ESP,0x4
    //         004d0436     MOV        dword ptr [ESP + param_2],EAX
    //         004d043a     TEST       EAX,EAX
    //         004d043c     MOV        dword ptr [ESP + local_4],0xa
    //         004d0444     JZ         LAB_004d04e4
    //         004d044a     MOV        this,dword ptr [ESI + 0x4]
    //         004d044d     MOV        EDX,dword ptr [ESP + param_1]
    //         004d0451     PUSH       this
    //         004d0452     PUSH       EDX
    //         004d0453     MOV        this,EAX
    //         004d0455     CALL       TRIBE_Action_Trade::TRIBE_Action_Trade           undefined TRIBE_Action_Trade(TRIBE_Action_Tra
    //                              tact_lst.cpp:88 (18)
    //         004d045a     MOV        this,dword ptr [ESP + local_c]
    //         004d045e     MOV        dword ptr FS:[0x0],this
    //         004d0465     POP        ESI
    //         004d0466     ADD        ESP,0xc
    //         004d0469     RET        0x8
    //                               switchD_004d01a3::caseD_c                                    XREF[2]:     004d01a3(j), 004d051c(*)  
    //                              tact_lst.cpp:80 (42)
    //         004d046c     PUSH       0x40
    //         004d046e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0473     ADD        ESP,0x4
    //         004d0476     MOV        dword ptr [ESP + param_2],EAX
    //         004d047a     TEST       EAX,EAX
    //         004d047c     MOV        dword ptr [ESP + local_4],0xb
    //         004d0484     JZ         LAB_004d04e4
    //         004d0486     MOV        this,dword ptr [ESI + 0x4]
    //         004d0489     MOV        EDX,dword ptr [ESP + param_1]
    //         004d048d     PUSH       this
    //         004d048e     PUSH       EDX
    //         004d048f     MOV        this,EAX
    //         004d0491     CALL       RGE_Action_Transport::RGE_Action_Transport       undefined RGE_Action_Transport(RGE_Action_Tra
    //                              tact_lst.cpp:88 (18)
    //         004d0496     MOV        this,dword ptr [ESP + local_c]
    //         004d049a     MOV        dword ptr FS:[0x0],this
    //         004d04a1     POP        ESI
    //         004d04a2     ADD        ESP,0xc
    //         004d04a5     RET        0x8
    //                               switchD_004d01a3::caseD_3                                    XREF[2]:     004d01a3(j), 004d0518(*)  
    //                              tact_lst.cpp:83 (42)
    //         004d04a8     PUSH       0x40
    //         004d04aa     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d04af     ADD        ESP,0x4
    //         004d04b2     MOV        dword ptr [ESP + param_2],EAX
    //         004d04b6     TEST       EAX,EAX
    //         004d04b8     MOV        dword ptr [ESP + local_4],0xc
    //         004d04c0     JZ         LAB_004d04e4
    //         004d04c2     MOV        this,dword ptr [ESI + 0x4]
    //         004d04c5     MOV        EDX,dword ptr [ESP + param_1]
    //         004d04c9     PUSH       this
    //         004d04ca     PUSH       EDX
    //         004d04cb     MOV        this,EAX
    //         004d04cd     CALL       RGE_Action_Enter::RGE_Action_Enter               undefined RGE_Action_Enter(RGE_Action_Enter *
    //                              tact_lst.cpp:88 (18)
    //         004d04d2     MOV        this,dword ptr [ESP + local_c]
    //         004d04d6     MOV        dword ptr FS:[0x0],this
    //         004d04dd     POP        ESI
    //         004d04de     ADD        ESP,0xc
    //         004d04e1     RET        0x8
    //                               LAB_004d04e4                                                 XREF[13]:    004d01c2(j), 004d0202(j), 
    //                                                                                                         004d0242(j), 004d0282(j), 
    //                                                                                                         004d02c2(j), 004d0302(j), 
    //                                                                                                         004d0342(j), 004d0382(j), 
    //                                                                                                         004d03c2(j), 004d0402(j), 
    //                                                                                                         004d0444(j), 004d0484(j), 
    //                                                                                                         004d04c0(j)  
    //                              tact_lst.cpp:83 (2)
    //         004d04e4     XOR        EAX,EAX
    //                              tact_lst.cpp:88 (18)
    //         004d04e6     MOV        this,dword ptr [ESP + local_c]
    //         004d04ea     MOV        dword ptr FS:[0x0],this
    //         004d04f1     POP        ESI
    //         004d04f2     ADD        ESP,0xc
    //         004d04f5     RET        0x8
    //                               switchD_004d01a3::caseD_5                                    XREF[3]:     004d0195(j), 004d01a3(j), 
    //                               switchD_004d01a3::caseD_6                                                 004d054c(*)  
    //                               switchD_004d01a3::caseD_7
    //                               switchD_004d01a3::caseD_8
    //                               switchD_004d01a3::caseD_9
    //                               switchD_004d01a3::caseD_a
    //                               switchD_004d01a3::caseD_b
    //                               switchD_004d01a3::caseD_d
    //                               switchD_004d01a3::caseD_e
    //                               switchD_004d01a3::caseD_f
    //                               switchD_004d01a3::caseD_10
    //                               switchD_004d01a3::caseD_11
    //                               switchD_004d01a3::caseD_12
    //                               switchD_004d01a3::caseD_13
    //                               switchD_004d01a3::caseD_14
    //                               switchD_004d01a3::caseD_15
    //                               switchD_004d01a3::caseD_16
    //                               switchD_004d01a3::caseD_17
    //                               switchD_004d01a3::caseD_18
    //                               switchD_004d01a3::caseD_19
    //                               switchD_004d01a3::caseD_1a
    //                               switchD_004d01a3::caseD_1b
    //                               switchD_004d01a3::caseD_1c
    //                               switchD_004d01a3::caseD_1d
    //                               switchD_004d01a3::caseD_1e
    //                               switchD_004d01a3::caseD_1f
    //                               switchD_004d01a3::caseD_20
    //                               switchD_004d01a3::caseD_21
    //                               switchD_004d01a3::caseD_22
    //                               switchD_004d01a3::caseD_23
    //                               switchD_004d01a3::caseD_24
    //                               switchD_004d01a3::caseD_25
    //                               switchD_004d01a3::caseD_26
    //                               switchD_004d01a3::caseD_27
    //                               switchD_004d01a3::caseD_28
    //                               switchD_004d01a3::caseD_29
    //                               switchD_004d01a3::caseD_2a
    //                               switchD_004d01a3::caseD_2b
    //                               switchD_004d01a3::caseD_2c
    //                               switchD_004d01a3::caseD_2d
    //                               switchD_004d01a3::caseD_2e
    //                               switchD_004d01a3::caseD_2f
    //                               switchD_004d01a3::caseD_30
    //                               switchD_004d01a3::caseD_31
    //                               switchD_004d01a3::caseD_32
    //                               switchD_004d01a3::caseD_33
    //                               switchD_004d01a3::caseD_34
    //                               switchD_004d01a3::caseD_35
    //                               switchD_004d01a3::caseD_36
    //                               switchD_004d01a3::caseD_37
    //                               switchD_004d01a3::caseD_38
    //                               switchD_004d01a3::caseD_39
    //                               switchD_004d01a3::caseD_3a
    //                               switchD_004d01a3::caseD_3b
    //                               switchD_004d01a3::caseD_3c
    //                               switchD_004d01a3::caseD_3d
    //                               switchD_004d01a3::caseD_3e
    //                               switchD_004d01a3::caseD_3f
    //                               switchD_004d01a3::caseD_40
    //                               switchD_004d01a3::caseD_41
    //                               switchD_004d01a3::caseD_42
    //                               switchD_004d01a3::caseD_43
    //                               switchD_004d01a3::caseD_44
    //                               switchD_004d01a3::caseD_45
    //                               switchD_004d01a3::caseD_46
    //                               switchD_004d01a3::caseD_47
    //                               switchD_004d01a3::caseD_48
    //                               switchD_004d01a3::caseD_49
    //                               switchD_004d01a3::caseD_4a
    //                               switchD_004d01a3::caseD_4b
    //                               switchD_004d01a3::caseD_4c
    //                               switchD_004d01a3::caseD_4d
    //                               switchD_004d01a3::caseD_4e
    //                               switchD_004d01a3::caseD_4f
    //                               switchD_004d01a3::caseD_50
    //                               switchD_004d01a3::caseD_51
    //                               switchD_004d01a3::caseD_52
    //                               switchD_004d01a3::caseD_53
    //                               switchD_004d01a3::caseD_54
    //                               switchD_004d01a3::caseD_55
    //                               switchD_004d01a3::caseD_56
    //                               switchD_004d01a3::caseD_57
    //                               switchD_004d01a3::caseD_58
    //                               switchD_004d01a3::caseD_59
    //                               switchD_004d01a3::caseD_5a
    //                               switchD_004d01a3::caseD_5b
    //                               switchD_004d01a3::caseD_5c
    //                               switchD_004d01a3::caseD_5d
    //                               switchD_004d01a3::caseD_5e
    //                               switchD_004d01a3::caseD_5f
    //                               switchD_004d01a3::caseD_60
    //                               switchD_004d01a3::caseD_61
    //                               switchD_004d01a3::caseD_62
    //                               switchD_004d01a3::caseD_63
    //                               switchD_004d01a3::caseD_64
    //                               switchD_004d01a3::caseD_6d
    //                               switchD_004d01a3::caseD_70
    //                               switchD_004d01a3::caseD_71
    //                               switchD_004d01a3::caseD_72
    //                               switchD_004d01a3::caseD_73
    //                               switchD_004d01a3::caseD_74
    //                               switchD_004d01a3::caseD_75
    //                               switchD_004d01a3::caseD_76
    //                               switchD_004d01a3::caseD_77
    //                               switchD_004d01a3::caseD_4
    //                              tact_lst.cpp:86 (13)
    //         004d04f8     MOV        EAX,dword ptr [ESP + param_1]
    //         004d04fc     PUSH       this
    //         004d04fd     PUSH       EAX
    //         004d04fe     MOV        this,ESI
    //         004d0500     CALL       RGE_Action_List::create_action                   RGE_Action * create_action(RGE_Action_List * 
    //                              tact_lst.cpp:88 (193)
    //         004d0505     MOV        this,dword ptr [ESP + local_c]
    //         004d0509     POP        ESI
    //         004d050a     MOV        dword ptr FS:[0x0],this
    //         004d0511     ADD        ESP,0xc
    //         004d0514     RET        0x8
}

// Offset: 0x004D05D0
RGE_Action* TRIBE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Action * __thiscall TRIBE_Action_List::create_task_action(class RGE_Task... *
    //                              *********************************************************************************************************
    //                              RGE_Action * __thiscall create_task_action(TRIBE_Action_List * this,
    //              RGE_Action *      EAX:4          <RETURN>
    //              TRIBE_Action_L    ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     004d05e8(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[19]:    004d060d(R), 004d065c(W), 004d069f(R), 004d06ee(W), 
    //                                                                                     004d0731(R), 004d0780(W), 004d07c3(R), 004d0812(W), 
    //                                                                                     004d0892(R), 004d08e1(W), 004d0924(R), 004d0973(W), 
    //                                                                                     004d09b6(R), 004d0a05(W), 004d0a48(R), 004d0a97(W), 
    //                                                                                     004d0af4(R), 004d0b23(W), 004d0b85(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[10]:    004d0679(R), 004d070b(R), 004d079d(R), 004d082f(R), 
    //                                                                                     004d08fe(R), 004d0990(R), 004d0a22(R), 004d0ab4(R), 
    //                                                                                     004d0b3c(R), 004d0b80(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[10]:    004d0674(R), 004d0706(R), 004d0798(R), 004d082a(R), 
    //                                                                                     004d08f9(R), 004d098b(R), 004d0a1d(R), 004d0aaf(R), 
    //                                                                                     004d0b37(R), 004d0b7c(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[20]:    004d061f(W), 004d0670(R), 004d06b1(W), 004d0702(R), 
    //                                                                                     004d0743(W), 004d0794(R), 004d07d5(W), 004d0826(R), 
    //                                                                                     004d085f(W), 004d08a4(W), 004d08f5(R), 004d0936(W), 
    //                                                                                     004d0987(R), 004d09c8(W), 004d0a19(R), 004d0a5a(W), 
    //                                                                                     004d0aab(R), 004d0ae4(W), 004d0b33(R), 004d0b78(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[19]:    004d0625(W), 004d0662(W), 004d06b7(W), 004d06f4(W), 
    //                                                                                     004d0749(W), 004d0786(W), 004d07db(W), 004d0818(W), 
    //                                                                                     004d0865(W), 004d08aa(W), 004d08e7(W), 004d093c(W), 
    //                                                                                     004d0979(W), 004d09ce(W), 004d0a0b(W), 004d0a60(W), 
    //                                                                                     004d0a9d(W), 004d0aea(W), 004d0b29(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[21]:    004d0640(R), 004d068b(R), 004d06d2(R), 004d071d(R), 
    //                                                                                     004d0764(R), 004d07af(R), 004d07f6(R), 004d0841(R), 
    //                                                                                     004d087e(R), 004d08c5(R), 004d0910(R), 004d0957(R), 
    //                                                                                     004d09a2(R), 004d09e9(R), 004d0a34(R), 004d0a7b(R), 
    //                                                                                     004d0ac6(R), 004d0b05(R), 004d0b4e(R), 004d0b64(R)  
    //                               ?create_task_action@TRIBE_Action_List@@UAEPAVRGE_Action@@PA  XREF[1]:     00575174(*)  
    //                               TRIBE_Action_List::create_task_action
    //                              tact_lst.cpp:93 (24)
    //         004d05d0     MOV        EAX,FS:[0x0]
    //         004d05d6     PUSH       -0x1
    //         004d05d8     PUSH       FUN_00560091
    //         004d05dd     PUSH       EAX
    //         004d05de     MOV        dword ptr FS:[0x0],ESP
    //         004d05e5     PUSH       EBX
    //         004d05e6     PUSH       ESI
    //         004d05e7     PUSH       EDI
    //                              tact_lst.cpp:94 (37)
    //         004d05e8     MOV        EDI,dword ptr [ESP + param_1]
    //         004d05ec     MOV        ESI,this
    //         004d05ee     MOVSX      EAX,word ptr [EDI + 0x6]
    //         004d05f2     ADD        EAX,-0x3
    //         004d05f5     CMP        EAX,0x75
    //         004d05f8     JA         switchD_004d0606::caseD_4
    //         004d05fe     XOR        this,this
    //         004d0600     MOV        this,byte ptr [EAX + 0x4d0bd8]=>PTR_caseD_4_00
    //                               switchD_004d0606::switchD
    //         004d0606     JMP        dword ptr [this->field0_0x0*0x4 + switchD_004d   = 004d0ada
    //                               switchD_004d0606::caseD_65                                   XREF[2]:     004d0606(j), 004d0bb0(*)  
    //                              tact_lst.cpp:97 (4)
    //         004d060d     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:98 (47)
    //         004d0611     PUSH       0x40
    //         004d0613     TEST       EBX,EBX
    //         004d0615     JZ         LAB_004d0654
    //         004d0617     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d061c     ADD        ESP,0x4
    //         004d061f     MOV        dword ptr [ESP + param_5],EAX
    //         004d0623     TEST       EAX,EAX
    //         004d0625     MOV        dword ptr [ESP + local_4],0x0
    //         004d062d     JZ         LAB_004d0b62
    //         004d0633     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0636     PUSH       EBX
    //         004d0637     PUSH       EDI
    //         004d0638     PUSH       EDX
    //         004d0639     MOV        this,EAX
    //         004d063b     CALL       TRIBE_Action_Build::TRIBE_Action_Build           undefined TRIBE_Action_Build(TRIBE_Action_Bui
    //                              tact_lst.cpp:156 (20)
    //         004d0640     MOV        this,dword ptr [ESP + local_c]
    //         004d0644     MOV        dword ptr FS:[0x0],this
    //         004d064b     POP        EDI
    //         004d064c     POP        ESI
    //         004d064d     POP        EBX
    //         004d064e     ADD        ESP,0xc
    //         004d0651     RET        0x14
    //                               LAB_004d0654                                                 XREF[1]:     004d0615(j)  
    //                              tact_lst.cpp:100 (55)
    //         004d0654     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0659     ADD        ESP,0x4
    //         004d065c     MOV        dword ptr [ESP + param_2],EAX
    //         004d0660     TEST       EAX,EAX
    //         004d0662     MOV        dword ptr [ESP + local_4],0x1
    //         004d066a     JZ         LAB_004d0b62
    //         004d0670     MOV        this,dword ptr [ESP + param_5]
    //         004d0674     MOV        EDX,dword ptr [ESP + param_4]
    //         004d0678     PUSH       this
    //         004d0679     MOV        this,dword ptr [ESP + param_3]
    //         004d067d     PUSH       EDX
    //         004d067e     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0681     PUSH       this
    //         004d0682     PUSH       EDI
    //         004d0683     PUSH       EDX
    //         004d0684     MOV        this,EAX
    //         004d0686     CALL       TRIBE_Action_Build::TRIBE_Action_Build           undefined TRIBE_Action_Build(TRIBE_Action_Bui
    //                              tact_lst.cpp:156 (20)
    //         004d068b     MOV        this,dword ptr [ESP + local_c]
    //         004d068f     MOV        dword ptr FS:[0x0],this
    //         004d0696     POP        EDI
    //         004d0697     POP        ESI
    //         004d0698     POP        EBX
    //         004d0699     ADD        ESP,0xc
    //         004d069c     RET        0x14
    //                               switchD_004d0606::caseD_68                                   XREF[2]:     004d0606(j), 004d0bb4(*)  
    //                              tact_lst.cpp:103 (4)
    //         004d069f     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:104 (47)
    //         004d06a3     PUSH       0x48
    //         004d06a5     TEST       EBX,EBX
    //         004d06a7     JZ         LAB_004d06e6
    //         004d06a9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d06ae     ADD        ESP,0x4
    //         004d06b1     MOV        dword ptr [ESP + param_5],EAX
    //         004d06b5     TEST       EAX,EAX
    //         004d06b7     MOV        dword ptr [ESP + local_4],0x2
    //         004d06bf     JZ         LAB_004d0b62
    //         004d06c5     MOV        this,dword ptr [ESI + 0x4]
    //         004d06c8     PUSH       EBX
    //         004d06c9     PUSH       EDI
    //         004d06ca     PUSH       this
    //         004d06cb     MOV        this,EAX
    //         004d06cd     CALL       TRIBE_Action_Convert::TRIBE_Action_Convert       undefined TRIBE_Action_Convert(TRIBE_Action_C
    //                              tact_lst.cpp:156 (20)
    //         004d06d2     MOV        this,dword ptr [ESP + local_c]
    //         004d06d6     MOV        dword ptr FS:[0x0],this
    //         004d06dd     POP        EDI
    //         004d06de     POP        ESI
    //         004d06df     POP        EBX
    //         004d06e0     ADD        ESP,0xc
    //         004d06e3     RET        0x14
    //                               LAB_004d06e6                                                 XREF[1]:     004d06a7(j)  
    //                              tact_lst.cpp:106 (55)
    //         004d06e6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d06eb     ADD        ESP,0x4
    //         004d06ee     MOV        dword ptr [ESP + param_2],EAX
    //         004d06f2     TEST       EAX,EAX
    //         004d06f4     MOV        dword ptr [ESP + local_4],0x3
    //         004d06fc     JZ         LAB_004d0b62
    //         004d0702     MOV        EDX,dword ptr [ESP + param_5]
    //         004d0706     MOV        this,dword ptr [ESP + param_4]
    //         004d070a     PUSH       EDX
    //         004d070b     MOV        EDX,dword ptr [ESP + param_3]
    //         004d070f     PUSH       this
    //         004d0710     MOV        this,dword ptr [ESI + 0x4]
    //         004d0713     PUSH       EDX
    //         004d0714     PUSH       EDI
    //         004d0715     PUSH       this
    //         004d0716     MOV        this,EAX
    //         004d0718     CALL       TRIBE_Action_Convert::TRIBE_Action_Convert       undefined TRIBE_Action_Convert(TRIBE_Action_C
    //                              tact_lst.cpp:156 (20)
    //         004d071d     MOV        this,dword ptr [ESP + local_c]
    //         004d0721     MOV        dword ptr FS:[0x0],this
    //         004d0728     POP        EDI
    //         004d0729     POP        ESI
    //         004d072a     POP        EBX
    //         004d072b     ADD        ESP,0xc
    //         004d072e     RET        0x14
    //                               switchD_004d0606::caseD_69                                   XREF[2]:     004d0606(j), 004d0bb8(*)  
    //                              tact_lst.cpp:109 (4)
    //         004d0731     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:110 (47)
    //         004d0735     PUSH       0x40
    //         004d0737     TEST       EBX,EBX
    //         004d0739     JZ         LAB_004d0778
    //         004d073b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0740     ADD        ESP,0x4
    //         004d0743     MOV        dword ptr [ESP + param_5],EAX
    //         004d0747     TEST       EAX,EAX
    //         004d0749     MOV        dword ptr [ESP + local_4],0x4
    //         004d0751     JZ         LAB_004d0b62
    //         004d0757     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d075a     PUSH       EBX
    //         004d075b     PUSH       EDI
    //         004d075c     PUSH       EDX
    //         004d075d     MOV        this,EAX
    //         004d075f     CALL       TRIBE_Action_Heal::TRIBE_Action_Heal             undefined TRIBE_Action_Heal(TRIBE_Action_Heal
    //                              tact_lst.cpp:156 (20)
    //         004d0764     MOV        this,dword ptr [ESP + local_c]
    //         004d0768     MOV        dword ptr FS:[0x0],this
    //         004d076f     POP        EDI
    //         004d0770     POP        ESI
    //         004d0771     POP        EBX
    //         004d0772     ADD        ESP,0xc
    //         004d0775     RET        0x14
    //                               LAB_004d0778                                                 XREF[1]:     004d0739(j)  
    //                              tact_lst.cpp:112 (55)
    //         004d0778     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d077d     ADD        ESP,0x4
    //         004d0780     MOV        dword ptr [ESP + param_2],EAX
    //         004d0784     TEST       EAX,EAX
    //         004d0786     MOV        dword ptr [ESP + local_4],0x5
    //         004d078e     JZ         LAB_004d0b62
    //         004d0794     MOV        this,dword ptr [ESP + param_5]
    //         004d0798     MOV        EDX,dword ptr [ESP + param_4]
    //         004d079c     PUSH       this
    //         004d079d     MOV        this,dword ptr [ESP + param_3]
    //         004d07a1     PUSH       EDX
    //         004d07a2     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d07a5     PUSH       this
    //         004d07a6     PUSH       EDI
    //         004d07a7     PUSH       EDX
    //         004d07a8     MOV        this,EAX
    //         004d07aa     CALL       TRIBE_Action_Heal::TRIBE_Action_Heal             undefined TRIBE_Action_Heal(TRIBE_Action_Heal
    //                              tact_lst.cpp:156 (20)
    //         004d07af     MOV        this,dword ptr [ESP + local_c]
    //         004d07b3     MOV        dword ptr FS:[0x0],this
    //         004d07ba     POP        EDI
    //         004d07bb     POP        ESI
    //         004d07bc     POP        EBX
    //         004d07bd     ADD        ESP,0xc
    //         004d07c0     RET        0x14
    //                               switchD_004d0606::caseD_6b                                   XREF[2]:     004d0606(j), 004d0bc0(*)  
    //                              tact_lst.cpp:115 (4)
    //         004d07c3     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:116 (47)
    //         004d07c7     PUSH       0x40
    //         004d07c9     TEST       EBX,EBX
    //         004d07cb     JZ         LAB_004d080a
    //         004d07cd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d07d2     ADD        ESP,0x4
    //         004d07d5     MOV        dword ptr [ESP + param_5],EAX
    //         004d07d9     TEST       EAX,EAX
    //         004d07db     MOV        dword ptr [ESP + local_4],0x6
    //         004d07e3     JZ         LAB_004d0b62
    //         004d07e9     MOV        this,dword ptr [ESI + 0x4]
    //         004d07ec     PUSH       EBX
    //         004d07ed     PUSH       EDI
    //         004d07ee     PUSH       this
    //         004d07ef     MOV        this,EAX
    //         004d07f1     CALL       TRIBE_Action_Artifact::TRIBE_Action_Artifact     undefined TRIBE_Action_Artifact(TRIBE_Action_
    //                              tact_lst.cpp:156 (20)
    //         004d07f6     MOV        this,dword ptr [ESP + local_c]
    //         004d07fa     MOV        dword ptr FS:[0x0],this
    //         004d0801     POP        EDI
    //         004d0802     POP        ESI
    //         004d0803     POP        EBX
    //         004d0804     ADD        ESP,0xc
    //         004d0807     RET        0x14
    //                               LAB_004d080a                                                 XREF[1]:     004d07cb(j)  
    //                              tact_lst.cpp:118 (55)
    //         004d080a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d080f     ADD        ESP,0x4
    //         004d0812     MOV        dword ptr [ESP + param_2],EAX
    //         004d0816     TEST       EAX,EAX
    //         004d0818     MOV        dword ptr [ESP + local_4],0x7
    //         004d0820     JZ         LAB_004d0b62
    //         004d0826     MOV        EDX,dword ptr [ESP + param_5]
    //         004d082a     MOV        this,dword ptr [ESP + param_4]
    //         004d082e     PUSH       EDX
    //         004d082f     MOV        EDX,dword ptr [ESP + param_3]
    //         004d0833     PUSH       this
    //         004d0834     MOV        this,dword ptr [ESI + 0x4]
    //         004d0837     PUSH       EDX
    //         004d0838     PUSH       EDI
    //         004d0839     PUSH       this
    //         004d083a     MOV        this,EAX
    //         004d083c     CALL       TRIBE_Action_Artifact::TRIBE_Action_Artifact     undefined TRIBE_Action_Artifact(TRIBE_Action_
    //                              tact_lst.cpp:156 (20)
    //         004d0841     MOV        this,dword ptr [ESP + local_c]
    //         004d0845     MOV        dword ptr FS:[0x0],this
    //         004d084c     POP        EDI
    //         004d084d     POP        ESI
    //         004d084e     POP        EBX
    //         004d084f     ADD        ESP,0xc
    //         004d0852     RET        0x14
    //                               switchD_004d0606::caseD_78                                   XREF[2]:     004d0606(j), 004d0bd0(*)  
    //                              tact_lst.cpp:121 (41)
    //         004d0855     PUSH       0x40
    //         004d0857     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d085c     ADD        ESP,0x4
    //         004d085f     MOV        dword ptr [ESP + param_5],EAX
    //         004d0863     TEST       EAX,EAX
    //         004d0865     MOV        dword ptr [ESP + local_4],0x8
    //         004d086d     JZ         LAB_004d0b62
    //         004d0873     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0876     MOV        this,EAX
    //         004d0878     PUSH       EDX
    //         004d0879     CALL       TRIBE_Action_Wonder::TRIBE_Action_Wonder         undefined TRIBE_Action_Wonder(TRIBE_Action_Wo
    //                              tact_lst.cpp:156 (20)
    //         004d087e     MOV        this,dword ptr [ESP + local_c]
    //         004d0882     MOV        dword ptr FS:[0x0],this
    //         004d0889     POP        EDI
    //         004d088a     POP        ESI
    //         004d088b     POP        EBX
    //         004d088c     ADD        ESP,0xc
    //         004d088f     RET        0x14
    //                               switchD_004d0606::caseD_6c                                   XREF[2]:     004d0606(j), 004d0bc4(*)  
    //                              tact_lst.cpp:124 (4)
    //         004d0892     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:125 (47)
    //         004d0896     PUSH       0x44
    //         004d0898     TEST       EBX,EBX
    //         004d089a     JZ         LAB_004d08d9
    //         004d089c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d08a1     ADD        ESP,0x4
    //         004d08a4     MOV        dword ptr [ESP + param_5],EAX
    //         004d08a8     TEST       EAX,EAX
    //         004d08aa     MOV        dword ptr [ESP + local_4],0x9
    //         004d08b2     JZ         LAB_004d0b62
    //         004d08b8     MOV        this,dword ptr [ESI + 0x4]
    //         004d08bb     PUSH       EBX
    //         004d08bc     PUSH       EDI
    //         004d08bd     PUSH       this
    //         004d08be     MOV        this,EAX
    //         004d08c0     CALL       TRIBE_Action_Discovery_Artifact::TRIBE_Action_   undefined TRIBE_Action_Discovery_Artifact(TRI
    //                              tact_lst.cpp:156 (20)
    //         004d08c5     MOV        this,dword ptr [ESP + local_c]
    //         004d08c9     MOV        dword ptr FS:[0x0],this
    //         004d08d0     POP        EDI
    //         004d08d1     POP        ESI
    //         004d08d2     POP        EBX
    //         004d08d3     ADD        ESP,0xc
    //         004d08d6     RET        0x14
    //                               LAB_004d08d9                                                 XREF[1]:     004d089a(j)  
    //                              tact_lst.cpp:127 (55)
    //         004d08d9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d08de     ADD        ESP,0x4
    //         004d08e1     MOV        dword ptr [ESP + param_2],EAX
    //         004d08e5     TEST       EAX,EAX
    //         004d08e7     MOV        dword ptr [ESP + local_4],0xa
    //         004d08ef     JZ         LAB_004d0b62
    //         004d08f5     MOV        EDX,dword ptr [ESP + param_5]
    //         004d08f9     MOV        this,dword ptr [ESP + param_4]
    //         004d08fd     PUSH       EDX
    //         004d08fe     MOV        EDX,dword ptr [ESP + param_3]
    //         004d0902     PUSH       this
    //         004d0903     MOV        this,dword ptr [ESI + 0x4]
    //         004d0906     PUSH       EDX
    //         004d0907     PUSH       EDI
    //         004d0908     PUSH       this
    //         004d0909     MOV        this,EAX
    //         004d090b     CALL       TRIBE_Action_Discovery_Artifact::TRIBE_Action_   undefined TRIBE_Action_Discovery_Artifact(TRI
    //                              tact_lst.cpp:156 (20)
    //         004d0910     MOV        this,dword ptr [ESP + local_c]
    //         004d0914     MOV        dword ptr FS:[0x0],this
    //         004d091b     POP        EDI
    //         004d091c     POP        ESI
    //         004d091d     POP        EBX
    //         004d091e     ADD        ESP,0xc
    //         004d0921     RET        0x14
    //                               switchD_004d0606::caseD_6e                                   XREF[2]:     004d0606(j), 004d0bc8(*)  
    //                              tact_lst.cpp:130 (4)
    //         004d0924     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:131 (47)
    //         004d0928     PUSH       0x44
    //         004d092a     TEST       EBX,EBX
    //         004d092c     JZ         LAB_004d096b
    //         004d092e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0933     ADD        ESP,0x4
    //         004d0936     MOV        dword ptr [ESP + param_5],EAX
    //         004d093a     TEST       EAX,EAX
    //         004d093c     MOV        dword ptr [ESP + local_4],0xb
    //         004d0944     JZ         LAB_004d0b62
    //         004d094a     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d094d     PUSH       EBX
    //         004d094e     PUSH       EDI
    //         004d094f     PUSH       EDX
    //         004d0950     MOV        this,EAX
    //         004d0952     CALL       TRIBE_Action_Hunt::TRIBE_Action_Hunt             undefined TRIBE_Action_Hunt(TRIBE_Action_Hunt
    //                              tact_lst.cpp:156 (20)
    //         004d0957     MOV        this,dword ptr [ESP + local_c]
    //         004d095b     MOV        dword ptr FS:[0x0],this
    //         004d0962     POP        EDI
    //         004d0963     POP        ESI
    //         004d0964     POP        EBX
    //         004d0965     ADD        ESP,0xc
    //         004d0968     RET        0x14
    //                               LAB_004d096b                                                 XREF[1]:     004d092c(j)  
    //                              tact_lst.cpp:133 (55)
    //         004d096b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0970     ADD        ESP,0x4
    //         004d0973     MOV        dword ptr [ESP + param_2],EAX
    //         004d0977     TEST       EAX,EAX
    //         004d0979     MOV        dword ptr [ESP + local_4],0xc
    //         004d0981     JZ         LAB_004d0b62
    //         004d0987     MOV        this,dword ptr [ESP + param_5]
    //         004d098b     MOV        EDX,dword ptr [ESP + param_4]
    //         004d098f     PUSH       this
    //         004d0990     MOV        this,dword ptr [ESP + param_3]
    //         004d0994     PUSH       EDX
    //         004d0995     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0998     PUSH       this
    //         004d0999     PUSH       EDI
    //         004d099a     PUSH       EDX
    //         004d099b     MOV        this,EAX
    //         004d099d     CALL       TRIBE_Action_Hunt::TRIBE_Action_Hunt             undefined TRIBE_Action_Hunt(TRIBE_Action_Hunt
    //                              tact_lst.cpp:156 (20)
    //         004d09a2     MOV        this,dword ptr [ESP + local_c]
    //         004d09a6     MOV        dword ptr FS:[0x0],this
    //         004d09ad     POP        EDI
    //         004d09ae     POP        ESI
    //         004d09af     POP        EBX
    //         004d09b0     ADD        ESP,0xc
    //         004d09b3     RET        0x14
    //                               switchD_004d0606::caseD_6a                                   XREF[2]:     004d0606(j), 004d0bbc(*)  
    //                              tact_lst.cpp:136 (4)
    //         004d09b6     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:137 (47)
    //         004d09ba     PUSH       0x44
    //         004d09bc     TEST       EBX,EBX
    //         004d09be     JZ         LAB_004d09fd
    //         004d09c0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d09c5     ADD        ESP,0x4
    //         004d09c8     MOV        dword ptr [ESP + param_5],EAX
    //         004d09cc     TEST       EAX,EAX
    //         004d09ce     MOV        dword ptr [ESP + local_4],0xd
    //         004d09d6     JZ         LAB_004d0b62
    //         004d09dc     MOV        this,dword ptr [ESI + 0x4]
    //         004d09df     PUSH       EBX
    //         004d09e0     PUSH       EDI
    //         004d09e1     PUSH       this
    //         004d09e2     MOV        this,EAX
    //         004d09e4     CALL       TRIBE_Action_Repair::TRIBE_Action_Repair         undefined TRIBE_Action_Repair(TRIBE_Action_Re
    //                              tact_lst.cpp:156 (20)
    //         004d09e9     MOV        this,dword ptr [ESP + local_c]
    //         004d09ed     MOV        dword ptr FS:[0x0],this
    //         004d09f4     POP        EDI
    //         004d09f5     POP        ESI
    //         004d09f6     POP        EBX
    //         004d09f7     ADD        ESP,0xc
    //         004d09fa     RET        0x14
    //                               LAB_004d09fd                                                 XREF[1]:     004d09be(j)  
    //                              tact_lst.cpp:139 (55)
    //         004d09fd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0a02     ADD        ESP,0x4
    //         004d0a05     MOV        dword ptr [ESP + param_2],EAX
    //         004d0a09     TEST       EAX,EAX
    //         004d0a0b     MOV        dword ptr [ESP + local_4],0xe
    //         004d0a13     JZ         LAB_004d0b62
    //         004d0a19     MOV        EDX,dword ptr [ESP + param_5]
    //         004d0a1d     MOV        this,dword ptr [ESP + param_4]
    //         004d0a21     PUSH       EDX
    //         004d0a22     MOV        EDX,dword ptr [ESP + param_3]
    //         004d0a26     PUSH       this
    //         004d0a27     MOV        this,dword ptr [ESI + 0x4]
    //         004d0a2a     PUSH       EDX
    //         004d0a2b     PUSH       EDI
    //         004d0a2c     PUSH       this
    //         004d0a2d     MOV        this,EAX
    //         004d0a2f     CALL       TRIBE_Action_Repair::TRIBE_Action_Repair         undefined TRIBE_Action_Repair(TRIBE_Action_Re
    //                              tact_lst.cpp:156 (20)
    //         004d0a34     MOV        this,dword ptr [ESP + local_c]
    //         004d0a38     MOV        dword ptr FS:[0x0],this
    //         004d0a3f     POP        EDI
    //         004d0a40     POP        ESI
    //         004d0a41     POP        EBX
    //         004d0a42     ADD        ESP,0xc
    //         004d0a45     RET        0x14
    //                               switchD_004d0606::caseD_6f                                   XREF[2]:     004d0606(j), 004d0bcc(*)  
    //                              tact_lst.cpp:142 (4)
    //         004d0a48     MOV        EBX,dword ptr [ESP + param_2]
    //                              tact_lst.cpp:143 (47)
    //         004d0a4c     PUSH       0x48
    //         004d0a4e     TEST       EBX,EBX
    //         004d0a50     JZ         LAB_004d0a8f
    //         004d0a52     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0a57     ADD        ESP,0x4
    //         004d0a5a     MOV        dword ptr [ESP + param_5],EAX
    //         004d0a5e     TEST       EAX,EAX
    //         004d0a60     MOV        dword ptr [ESP + local_4],0xf
    //         004d0a68     JZ         LAB_004d0b62
    //         004d0a6e     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0a71     PUSH       EBX
    //         004d0a72     PUSH       EDI
    //         004d0a73     PUSH       EDX
    //         004d0a74     MOV        this,EAX
    //         004d0a76     CALL       TRIBE_Action_Trade::TRIBE_Action_Trade           undefined TRIBE_Action_Trade(TRIBE_Action_Tra
    //                              tact_lst.cpp:156 (20)
    //         004d0a7b     MOV        this,dword ptr [ESP + local_c]
    //         004d0a7f     MOV        dword ptr FS:[0x0],this
    //         004d0a86     POP        EDI
    //         004d0a87     POP        ESI
    //         004d0a88     POP        EBX
    //         004d0a89     ADD        ESP,0xc
    //         004d0a8c     RET        0x14
    //                               LAB_004d0a8f                                                 XREF[1]:     004d0a50(j)  
    //                              tact_lst.cpp:145 (55)
    //         004d0a8f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0a94     ADD        ESP,0x4
    //         004d0a97     MOV        dword ptr [ESP + param_2],EAX
    //         004d0a9b     TEST       EAX,EAX
    //         004d0a9d     MOV        dword ptr [ESP + local_4],0x10
    //         004d0aa5     JZ         LAB_004d0b62
    //         004d0aab     MOV        this,dword ptr [ESP + param_5]
    //         004d0aaf     MOV        EDX,dword ptr [ESP + param_4]
    //         004d0ab3     PUSH       this
    //         004d0ab4     MOV        this,dword ptr [ESP + param_3]
    //         004d0ab8     PUSH       EDX
    //         004d0ab9     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0abc     PUSH       this
    //         004d0abd     PUSH       EDI
    //         004d0abe     PUSH       EDX
    //         004d0abf     MOV        this,EAX
    //         004d0ac1     CALL       TRIBE_Action_Trade::TRIBE_Action_Trade           undefined TRIBE_Action_Trade(TRIBE_Action_Tra
    //                              tact_lst.cpp:156 (20)
    //         004d0ac6     MOV        this,dword ptr [ESP + local_c]
    //         004d0aca     MOV        dword ptr FS:[0x0],this
    //         004d0ad1     POP        EDI
    //         004d0ad2     POP        ESI
    //         004d0ad3     POP        EBX
    //         004d0ad4     ADD        ESP,0xc
    //         004d0ad7     RET        0x14
    //                               switchD_004d0606::caseD_3                                    XREF[2]:     004d0606(j), 004d0ba8(*)  
    //                              tact_lst.cpp:148 (43)
    //         004d0ada     PUSH       0x40
    //         004d0adc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0ae1     ADD        ESP,0x4
    //         004d0ae4     MOV        dword ptr [ESP + param_5],EAX
    //         004d0ae8     TEST       EAX,EAX
    //         004d0aea     MOV        dword ptr [ESP + local_4],0x11
    //         004d0af2     JZ         LAB_004d0b62
    //         004d0af4     MOV        this,dword ptr [ESP + param_2]
    //         004d0af8     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0afb     PUSH       this
    //         004d0afc     PUSH       EDI
    //         004d0afd     PUSH       EDX
    //         004d0afe     MOV        this,EAX
    //         004d0b00     CALL       RGE_Action_Enter::RGE_Action_Enter               undefined RGE_Action_Enter(RGE_Action_Enter *
    //                              tact_lst.cpp:156 (20)
    //         004d0b05     MOV        this,dword ptr [ESP + local_c]
    //         004d0b09     MOV        dword ptr FS:[0x0],this
    //         004d0b10     POP        EDI
    //         004d0b11     POP        ESI
    //         004d0b12     POP        EBX
    //         004d0b13     ADD        ESP,0xc
    //         004d0b16     RET        0x14
    //                               switchD_004d0606::caseD_c                                    XREF[2]:     004d0606(j), 004d0bac(*)  
    //                              tact_lst.cpp:151 (53)
    //         004d0b19     PUSH       0x40
    //         004d0b1b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d0b20     ADD        ESP,0x4
    //         004d0b23     MOV        dword ptr [ESP + param_2],EAX
    //         004d0b27     TEST       EAX,EAX
    //         004d0b29     MOV        dword ptr [ESP + local_4],0x12
    //         004d0b31     JZ         LAB_004d0b62
    //         004d0b33     MOV        this,dword ptr [ESP + param_5]
    //         004d0b37     MOV        EDX,dword ptr [ESP + param_4]
    //         004d0b3b     PUSH       this
    //         004d0b3c     MOV        this,dword ptr [ESP + param_3]
    //         004d0b40     PUSH       EDX
    //         004d0b41     MOV        EDX,dword ptr [ESI + 0x4]
    //         004d0b44     PUSH       this
    //         004d0b45     PUSH       EDI
    //         004d0b46     PUSH       EDX
    //         004d0b47     MOV        this,EAX
    //         004d0b49     CALL       RGE_Action_Transport::RGE_Action_Transport       undefined RGE_Action_Transport(RGE_Action_Tra
    //                              tact_lst.cpp:156 (20)
    //         004d0b4e     MOV        this,dword ptr [ESP + local_c]
    //         004d0b52     MOV        dword ptr FS:[0x0],this
    //         004d0b59     POP        EDI
    //         004d0b5a     POP        ESI
    //         004d0b5b     POP        EBX
    //         004d0b5c     ADD        ESP,0xc
    //         004d0b5f     RET        0x14
    //                               LAB_004d0b62                                                 XREF[19]:    004d062d(j), 004d066a(j), 
    //                                                                                                         004d06bf(j), 004d06fc(j), 
    //                                                                                                         004d0751(j), 004d078e(j), 
    //                                                                                                         004d07e3(j), 004d0820(j), 
    //                                                                                                         004d086d(j), 004d08b2(j), 
    //                                                                                                         004d08ef(j), 004d0944(j), 
    //                                                                                                         004d0981(j), 004d09d6(j), 
    //                                                                                                         004d0a13(j), 004d0a68(j), 
    //                                                                                                         004d0aa5(j), 004d0af2(j), 
    //                                                                                                         004d0b31(j)  
    //                              tact_lst.cpp:151 (2)
    //         004d0b62     XOR        EAX,EAX
    //                              tact_lst.cpp:156 (20)
    //         004d0b64     MOV        this,dword ptr [ESP + local_c]
    //         004d0b68     MOV        dword ptr FS:[0x0],this
    //         004d0b6f     POP        EDI
    //         004d0b70     POP        ESI
    //         004d0b71     POP        EBX
    //         004d0b72     ADD        ESP,0xc
    //         004d0b75     RET        0x14
    //                               switchD_004d0606::caseD_5                                    XREF[3]:     004d05f8(j), 004d0606(j), 
    //                               switchD_004d0606::caseD_6                                                 004d0bd4(*)  
    //                               switchD_004d0606::caseD_7
    //                               switchD_004d0606::caseD_8
    //                               switchD_004d0606::caseD_9
    //                               switchD_004d0606::caseD_a
    //                               switchD_004d0606::caseD_b
    //                               switchD_004d0606::caseD_d
    //                               switchD_004d0606::caseD_e
    //                               switchD_004d0606::caseD_f
    //                               switchD_004d0606::caseD_10
    //                               switchD_004d0606::caseD_11
    //                               switchD_004d0606::caseD_12
    //                               switchD_004d0606::caseD_13
    //                               switchD_004d0606::caseD_14
    //                               switchD_004d0606::caseD_15
    //                               switchD_004d0606::caseD_16
    //                               switchD_004d0606::caseD_17
    //                               switchD_004d0606::caseD_18
    //                               switchD_004d0606::caseD_19
    //                               switchD_004d0606::caseD_1a
    //                               switchD_004d0606::caseD_1b
    //                               switchD_004d0606::caseD_1c
    //                               switchD_004d0606::caseD_1d
    //                               switchD_004d0606::caseD_1e
    //                               switchD_004d0606::caseD_1f
    //                               switchD_004d0606::caseD_20
    //                               switchD_004d0606::caseD_21
    //                               switchD_004d0606::caseD_22
    //                               switchD_004d0606::caseD_23
    //                               switchD_004d0606::caseD_24
    //                               switchD_004d0606::caseD_25
    //                               switchD_004d0606::caseD_26
    //                               switchD_004d0606::caseD_27
    //                               switchD_004d0606::caseD_28
    //                               switchD_004d0606::caseD_29
    //                               switchD_004d0606::caseD_2a
    //                               switchD_004d0606::caseD_2b
    //                               switchD_004d0606::caseD_2c
    //                               switchD_004d0606::caseD_2d
    //                               switchD_004d0606::caseD_2e
    //                               switchD_004d0606::caseD_2f
    //                               switchD_004d0606::caseD_30
    //                               switchD_004d0606::caseD_31
    //                               switchD_004d0606::caseD_32
    //                               switchD_004d0606::caseD_33
    //                               switchD_004d0606::caseD_34
    //                               switchD_004d0606::caseD_35
    //                               switchD_004d0606::caseD_36
    //                               switchD_004d0606::caseD_37
    //                               switchD_004d0606::caseD_38
    //                               switchD_004d0606::caseD_39
    //                               switchD_004d0606::caseD_3a
    //                               switchD_004d0606::caseD_3b
    //                               switchD_004d0606::caseD_3c
    //                               switchD_004d0606::caseD_3d
    //                               switchD_004d0606::caseD_3e
    //                               switchD_004d0606::caseD_3f
    //                               switchD_004d0606::caseD_40
    //                               switchD_004d0606::caseD_41
    //                               switchD_004d0606::caseD_42
    //                               switchD_004d0606::caseD_43
    //                               switchD_004d0606::caseD_44
    //                               switchD_004d0606::caseD_45
    //                               switchD_004d0606::caseD_46
    //                               switchD_004d0606::caseD_47
    //                               switchD_004d0606::caseD_48
    //                               switchD_004d0606::caseD_49
    //                               switchD_004d0606::caseD_4a
    //                               switchD_004d0606::caseD_4b
    //                               switchD_004d0606::caseD_4c
    //                               switchD_004d0606::caseD_4d
    //                               switchD_004d0606::caseD_4e
    //                               switchD_004d0606::caseD_4f
    //                               switchD_004d0606::caseD_50
    //                               switchD_004d0606::caseD_51
    //                               switchD_004d0606::caseD_52
    //                               switchD_004d0606::caseD_53
    //                               switchD_004d0606::caseD_54
    //                               switchD_004d0606::caseD_55
    //                               switchD_004d0606::caseD_56
    //                               switchD_004d0606::caseD_57
    //                               switchD_004d0606::caseD_58
    //                               switchD_004d0606::caseD_59
    //                               switchD_004d0606::caseD_5a
    //                               switchD_004d0606::caseD_5b
    //                               switchD_004d0606::caseD_5c
    //                               switchD_004d0606::caseD_5d
    //                               switchD_004d0606::caseD_5e
    //                               switchD_004d0606::caseD_5f
    //                               switchD_004d0606::caseD_60
    //                               switchD_004d0606::caseD_61
    //                               switchD_004d0606::caseD_62
    //                               switchD_004d0606::caseD_63
    //                               switchD_004d0606::caseD_64
    //                               switchD_004d0606::caseD_66
    //                               switchD_004d0606::caseD_67
    //                               switchD_004d0606::caseD_6d
    //                               switchD_004d0606::caseD_70
    //                               switchD_004d0606::caseD_71
    //                               switchD_004d0606::caseD_72
    //                               switchD_004d0606::caseD_73
    //                               switchD_004d0606::caseD_74
    //                               switchD_004d0606::caseD_75
    //                               switchD_004d0606::caseD_76
    //                               switchD_004d0606::caseD_77
    //                               switchD_004d0606::caseD_4
    //                              tact_lst.cpp:154 (28)
    //         004d0b78     MOV        EAX,dword ptr [ESP + param_5]
    //         004d0b7c     MOV        this,dword ptr [ESP + param_4]
    //         004d0b80     MOV        EDX,dword ptr [ESP + param_3]
    //         004d0b84     PUSH       EAX
    //         004d0b85     MOV        EAX,dword ptr [ESP + param_2]
    //         004d0b89     PUSH       this
    //         004d0b8a     PUSH       EDX
    //         004d0b8b     PUSH       EAX
    //         004d0b8c     PUSH       EDI
    //         004d0b8d     MOV        this,ESI
    //         004d0b8f     CALL       RGE_Action_List::create_task_action              RGE_Action * create_task_action(RGE_Action_Li
    //                              tact_lst.cpp:156 (186)
    //         004d0b94     MOV        this,dword ptr [ESP + local_c]
    //         004d0b98     POP        EDI
    //         004d0b99     POP        ESI
    //         004d0b9a     MOV        dword ptr FS:[0x0],this
    //         004d0ba1     POP        EBX
    //         004d0ba2     ADD        ESP,0xc
    //         004d0ba5     RET        0x14
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004d0606::switchdataD_004d0ba8                       XREF[1]:     create_task_action:004d0606(*)  
}

// Offset: 0x004D0C50
void TRIBE_Action_List::get_action_name(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Action_List::get_action_name(char *)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall get_action_name(TRIBE_Action_List * this, char * par
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_L    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     004d0cdb(R), 004d0d04(R), 004d0d19(R)  
    //                               ?get_action_name@TRIBE_Action_List@@UAEXPAD@Z                XREF[1]:     00575180(*)  
    //                               TRIBE_Action_List::get_action_name
    //                              tact_lst.cpp:160 (9)
    //         004d0c50     MOV        EAX,dword ptr [ECX + this->field8_0x8]
    //         004d0c53     PUSH       ESI
    //         004d0c54     TEST       EAX,EAX
    //         004d0c56     PUSH       EDI
    //         004d0c57     JNZ        LAB_004d0c60
    //                              tact_lst.cpp:163 (5)
    //         004d0c59     MOV        EDI,s_None                                       = 4Eh
    //                              tact_lst.cpp:164 (2)
    //         004d0c5e     JMP        LAB_004d0ccc
    //                               LAB_004d0c60                                                 XREF[1]:     004d0c57(j)  
    //                              tact_lst.cpp:167 (33)
    //         004d0c60     MOV        EDX,dword ptr [EAX]
    //         004d0c62     MOVSX      EAX,word ptr [EDX + 0x4]
    //         004d0c66     ADD        EAX,-0x3
    //         004d0c69     CMP        EAX,0x6c
    //         004d0c6c     JA         switchD_004d0c7a::caseD_4
    //         004d0c72     XOR        EDX,EDX
    //         004d0c74     MOV        DL,byte ptr [EAX + 0x4d0d5c]=>PTR_caseD_4_004d
    //                               switchD_004d0c7a::switchD
    //         004d0c7a     JMP        dword ptr [EDX*0x4 + switchD_004d0c7a::switchd   = 004d0cc7
    //                               switchD_004d0c7a::caseD_65                                   XREF[2]:     004d0c7a(j), 004d0d30(*)  
    //                              tact_lst.cpp:169 (7)
    //         004d0c81     MOV        EDI,s_Build                                      = "Build"
    //         004d0c86     JMP        LAB_004d0ccc
    //                               switchD_004d0c7a::caseD_66                                   XREF[2]:     004d0c7a(j), 004d0d34(*)  
    //                              tact_lst.cpp:170 (7)
    //         004d0c88     MOV        EDI,s_MakeObject                                 = "MakeObject"
    //         004d0c8d     JMP        LAB_004d0cf5
    //                               switchD_004d0c7a::caseD_67                                   XREF[2]:     004d0c7a(j), 004d0d38(*)  
    //                              tact_lst.cpp:171 (7)
    //         004d0c8f     MOV        EDI,s_MakeTech                                   = "MakeTech"
    //         004d0c94     JMP        LAB_004d0ccc
    //                               switchD_004d0c7a::caseD_68                                   XREF[2]:     004d0c7a(j), 004d0d3c(*)  
    //                              tact_lst.cpp:172 (7)
    //         004d0c96     MOV        EDI,s_Convert                                    = "Convert"
    //         004d0c9b     JMP        LAB_004d0cf5
    //                               switchD_004d0c7a::caseD_69                                   XREF[2]:     004d0c7a(j), 004d0d40(*)  
    //                              tact_lst.cpp:173 (7)
    //         004d0c9d     MOV        EDI,s_Heal                                       = 48h
    //         004d0ca2     JMP        LAB_004d0ccc
    //                               switchD_004d0c7a::caseD_6b                                   XREF[2]:     004d0c7a(j), 004d0d48(*)  
    //                              tact_lst.cpp:174 (7)
    //         004d0ca4     MOV        EDI,s_Artifact                                   = "Artifact"
    //         004d0ca9     JMP        LAB_004d0cf5
    //                               switchD_004d0c7a::caseD_6c                                   XREF[2]:     004d0c7a(j), 004d0d4c(*)  
    //                              tact_lst.cpp:175 (7)
    //         004d0cab     MOV        EDI,s_DiscoveryArtifact                          = "DiscoveryArtifact"
    //         004d0cb0     JMP        LAB_004d0ccc
    //                               switchD_004d0c7a::caseD_6e                                   XREF[2]:     004d0c7a(j), 004d0d50(*)  
    //                              tact_lst.cpp:176 (7)
    //         004d0cb2     MOV        EDI,s_Hunt                                       = "Hunt"
    //         004d0cb7     JMP        LAB_004d0cf5
    //                               switchD_004d0c7a::caseD_6a                                   XREF[2]:     004d0c7a(j), 004d0d44(*)  
    //                              tact_lst.cpp:177 (7)
    //         004d0cb9     MOV        EDI,s_Repair                                     = "Repair"
    //         004d0cbe     JMP        LAB_004d0ccc
    //                               switchD_004d0c7a::caseD_6f                                   XREF[2]:     004d0c7a(j), 004d0d54(*)  
    //                              tact_lst.cpp:178 (7)
    //         004d0cc0     MOV        EDI,s_Trade                                      = 54h    T
    //         004d0cc5     JMP        LAB_004d0cf5
    //                               switchD_004d0c7a::caseD_3                                    XREF[2]:     004d0c7a(j), 004d0d28(*)  
    //                              tact_lst.cpp:179 (36)
    //         004d0cc7     MOV        EDI,s_Enter                                      = "Enter"
    //                               LAB_004d0ccc                                                 XREF[6]:     004d0c5e(j), 004d0c86(j), 
    //                                                                                                         004d0c94(j), 004d0ca2(j), 
    //                                                                                                         004d0cb0(j), 004d0cbe(j)  
    //         004d0ccc     OR         this,0xffffffff
    //         004d0ccf     XOR        EAX,EAX
    //         004d0cd1     SCASB.RE   ES:EDI=>s_None                                   = 4Eh
    //                                                                                  = 00656e6f
    //                                                                                  = 48h
    //                                                                                  = "Enter"
    //                                                                                  = "Repair"
    //                                                                                  = "DiscoveryArtifact"
    //         004d0cd3     NOT        this
    //         004d0cd5     SUB        EDI,this
    //         004d0cd7     MOV        EAX,this
    //         004d0cd9     MOV        ESI,EDI
    //         004d0cdb     MOV        EDI,dword ptr [ESP + param_1]
    //         004d0cdf     SHR        this,0x2
    //         004d0ce2     MOVSD.REP  ES:EDI,ESI
    //         004d0ce4     MOV        this,EAX
    //         004d0ce6     AND        this,0x3
    //         004d0ce9     MOVSB.REP  ES:EDI,ESI
    //                              tact_lst.cpp:183 (5)
    //         004d0ceb     POP        EDI
    //         004d0cec     POP        ESI
    //         004d0ced     RET        0x4
    //                               switchD_004d0c7a::caseD_c                                    XREF[2]:     004d0c7a(j), 004d0d2c(*)  
    //                              tact_lst.cpp:180 (36)
    //         004d0cf0     MOV        EDI,s_Transport                                  = "Transport"
    //                               LAB_004d0cf5                                                 XREF[5]:     004d0c8d(j), 004d0c9b(j), 
    //                                                                                                         004d0ca9(j), 004d0cb7(j), 
    //                                                                                                         004d0cc5(j)  
    //         004d0cf5     OR         this,0xffffffff
    //         004d0cf8     XOR        EAX,EAX
    //         004d0cfa     SCASB.RE   ES:EDI=>s_Trade                                  = "Transport"
    //                                                                                  = 54h    T
    //                                                                                  = 72h
    //                                                                                  = "Hunt"
    //                                                                                  = "Artifact"
    //                                                                                  = "Convert"
    //         004d0cfc     NOT        this
    //         004d0cfe     SUB        EDI,this
    //         004d0d00     MOV        EDX,this
    //         004d0d02     MOV        ESI,EDI
    //         004d0d04     MOV        EDI,dword ptr [ESP + param_1]
    //         004d0d08     SHR        this,0x2
    //         004d0d0b     MOVSD.REP  ES:EDI,ESI
    //         004d0d0d     MOV        this,EDX
    //         004d0d0f     AND        this,0x3
    //         004d0d12     MOVSB.REP  ES:EDI,ESI
    //                              tact_lst.cpp:183 (5)
    //         004d0d14     POP        EDI
    //         004d0d15     POP        ESI
    //         004d0d16     RET        0x4
    //                               switchD_004d0c7a::caseD_5                                    XREF[3]:     004d0c6c(j), 004d0c7a(j), 
    //                               switchD_004d0c7a::caseD_6                                                 004d0d58(*)  
    //                               switchD_004d0c7a::caseD_7
    //                               switchD_004d0c7a::caseD_8
    //                               switchD_004d0c7a::caseD_9
    //                               switchD_004d0c7a::caseD_a
    //                               switchD_004d0c7a::caseD_b
    //                               switchD_004d0c7a::caseD_d
    //                               switchD_004d0c7a::caseD_e
    //                               switchD_004d0c7a::caseD_f
    //                               switchD_004d0c7a::caseD_10
    //                               switchD_004d0c7a::caseD_11
    //                               switchD_004d0c7a::caseD_12
    //                               switchD_004d0c7a::caseD_13
    //                               switchD_004d0c7a::caseD_14
    //                               switchD_004d0c7a::caseD_15
    //                               switchD_004d0c7a::caseD_16
    //                               switchD_004d0c7a::caseD_17
    //                               switchD_004d0c7a::caseD_18
    //                               switchD_004d0c7a::caseD_19
    //                               switchD_004d0c7a::caseD_1a
    //                               switchD_004d0c7a::caseD_1b
    //                               switchD_004d0c7a::caseD_1c
    //                               switchD_004d0c7a::caseD_1d
    //                               switchD_004d0c7a::caseD_1e
    //                               switchD_004d0c7a::caseD_1f
    //                               switchD_004d0c7a::caseD_20
    //                               switchD_004d0c7a::caseD_21
    //                               switchD_004d0c7a::caseD_22
    //                               switchD_004d0c7a::caseD_23
    //                               switchD_004d0c7a::caseD_24
    //                               switchD_004d0c7a::caseD_25
    //                               switchD_004d0c7a::caseD_26
    //                               switchD_004d0c7a::caseD_27
    //                               switchD_004d0c7a::caseD_28
    //                               switchD_004d0c7a::caseD_29
    //                               switchD_004d0c7a::caseD_2a
    //                               switchD_004d0c7a::caseD_2b
    //                               switchD_004d0c7a::caseD_2c
    //                               switchD_004d0c7a::caseD_2d
    //                               switchD_004d0c7a::caseD_2e
    //                               switchD_004d0c7a::caseD_2f
    //                               switchD_004d0c7a::caseD_30
    //                               switchD_004d0c7a::caseD_31
    //                               switchD_004d0c7a::caseD_32
    //                               switchD_004d0c7a::caseD_33
    //                               switchD_004d0c7a::caseD_34
    //                               switchD_004d0c7a::caseD_35
    //                               switchD_004d0c7a::caseD_36
    //                               switchD_004d0c7a::caseD_37
    //                               switchD_004d0c7a::caseD_38
    //                               switchD_004d0c7a::caseD_39
    //                               switchD_004d0c7a::caseD_3a
    //                               switchD_004d0c7a::caseD_3b
    //                               switchD_004d0c7a::caseD_3c
    //                               switchD_004d0c7a::caseD_3d
    //                               switchD_004d0c7a::caseD_3e
    //                               switchD_004d0c7a::caseD_3f
    //                               switchD_004d0c7a::caseD_40
    //                               switchD_004d0c7a::caseD_41
    //                               switchD_004d0c7a::caseD_42
    //                               switchD_004d0c7a::caseD_43
    //                               switchD_004d0c7a::caseD_44
    //                               switchD_004d0c7a::caseD_45
    //                               switchD_004d0c7a::caseD_46
    //                               switchD_004d0c7a::caseD_47
    //                               switchD_004d0c7a::caseD_48
    //                               switchD_004d0c7a::caseD_49
    //                               switchD_004d0c7a::caseD_4a
    //                               switchD_004d0c7a::caseD_4b
    //                               switchD_004d0c7a::caseD_4c
    //                               switchD_004d0c7a::caseD_4d
    //                               switchD_004d0c7a::caseD_4e
    //                               switchD_004d0c7a::caseD_4f
    //                               switchD_004d0c7a::caseD_50
    //                               switchD_004d0c7a::caseD_51
    //                               switchD_004d0c7a::caseD_52
    //                               switchD_004d0c7a::caseD_53
    //                               switchD_004d0c7a::caseD_54
    //                               switchD_004d0c7a::caseD_55
    //                               switchD_004d0c7a::caseD_56
    //                               switchD_004d0c7a::caseD_57
    //                               switchD_004d0c7a::caseD_58
    //                               switchD_004d0c7a::caseD_59
    //                               switchD_004d0c7a::caseD_5a
    //                               switchD_004d0c7a::caseD_5b
    //                               switchD_004d0c7a::caseD_5c
    //                               switchD_004d0c7a::caseD_5d
    //                               switchD_004d0c7a::caseD_5e
    //                               switchD_004d0c7a::caseD_5f
    //                               switchD_004d0c7a::caseD_60
    //                               switchD_004d0c7a::caseD_61
    //                               switchD_004d0c7a::caseD_62
    //                               switchD_004d0c7a::caseD_63
    //                               switchD_004d0c7a::caseD_64
    //                               switchD_004d0c7a::caseD_6d
    //                               switchD_004d0c7a::caseD_4
    //                              tact_lst.cpp:181 (10)
    //         004d0d19     MOV        EAX,dword ptr [ESP + param_1]
    //         004d0d1d     PUSH       EAX
    //         004d0d1e     CALL       RGE_Action_List::get_action_name                 void get_action_name(RGE_Action_List * this, 
    //                              tact_lst.cpp:183 (166)
    //         004d0d23     POP        EDI
    //         004d0d24     POP        ESI
    //         004d0d25     RET        0x4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004d0c7a::switchdataD_004d0d28                       XREF[1]:     get_action_name:004d0c7a(*)  
}

