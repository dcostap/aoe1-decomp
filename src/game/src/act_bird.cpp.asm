// Auto-generated scaffold unit: act_bird.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/act_bird.cpp
#include "../include/common.h"

// Offset: 0x00401FE0
undefined RGE_Action_Bird(RGE_Action_Bird* this_, int param_2, RGE_Action_Object* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Bird::RGE_Action_Bird(int,class RGE_Action_Object *)                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Bird(RGE_Action_Bird * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00401fe9(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00401fe0(R)  
    //                               ??0RGE_Action_Bird@@QAE@HPAVRGE_Action_Object@@@Z            XREF[1]:     create_action:0040405f(c)  
    //                               RGE_Action_Bird::RGE_Action_Bird
    //                              act_bird.cpp:30 (28)
    //         00401fe0     MOV        EAX,dword ptr [ESP + param_2]
    //         00401fe4     PUSH       ESI
    //         00401fe5     MOV        ESI,this
    //         00401fe7     PUSH       0x1
    //         00401fe9     MOV        this,dword ptr [ESP + param_1]
    //         00401fed     PUSH       EAX
    //         00401fee     PUSH       this
    //         00401fef     MOV        this,ESI
    //         00401ff1     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //         00401ff6     MOV        dword ptr [ESI],RGE_Action_Bird::`vftable'       = 00402010
    //                              act_bird.cpp:31 (6)
    //         00401ffc     MOV        word ptr [ESI + 0x4],0xa
    //                              act_bird.cpp:32 (6)
    //         00402002     MOV        EAX,ESI
    //         00402004     POP        ESI
    //         00402005     RET        0x8
}

// Offset: 0x00402040
undefined RGE_Action_Bird(RGE_Action_Bird* this_, RGE_Action_Object* param_2, RGE_Task* param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Bird::RGE_Action_Bird(class RGE_Action_Object *,class RGE_Task *,flo... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Bird(RGE_Action_Bird * this, RGE_Act
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00402040(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     0040204f(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00402057(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00402053(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0040205e(R)  
    //                               ??0RGE_Action_Bird@@QAE@PAVRGE_Action_Object@@PAVRGE_Task@@  XREF[1]:     create_task_action:00404272(c)  
    //                               RGE_Action_Bird::RGE_Action_Bird
    //                              act_bird.cpp:37 (15)
    //         00402040     MOV        EAX,dword ptr [ESP + param_1]
    //         00402044     PUSH       ESI
    //         00402045     PUSH       0x1
    //         00402047     MOV        ESI,this
    //         00402049     PUSH       EAX
    //         0040204a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              act_bird.cpp:40 (4)
    //         0040204f     MOV        this,dword ptr [ESP + param_2]
    //                              act_bird.cpp:42 (11)
    //         00402053     MOV        EAX,dword ptr [ESP + param_4]
    //         00402057     MOV        EDX,dword ptr [ESP + param_3]
    //         0040205b     MOV        dword ptr [ESI + 0x30],this
    //                              act_bird.cpp:43 (25)
    //         0040205e     MOV        this,dword ptr [ESP + param_5]
    //         00402062     MOV        dword ptr [ESI + 0x24],EAX
    //         00402065     MOV        dword ptr [ESI],RGE_Action_Bird::`vftable'       = 00402010
    //         0040206b     MOV        word ptr [ESI + 0x4],0xa
    //         00402071     MOV        dword ptr [ESI + 0x20],EDX
    //         00402074     MOV        dword ptr [ESI + 0x28],this
    //                              act_bird.cpp:44 (6)
    //         00402077     MOV        EAX,ESI
    //         00402079     POP        ESI
    //         0040207a     RET        0x14
}

// Offset: 0x00402080
void RGE_Action_Bird::first_in_stack(uchar param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Bird::first_in_stack(unsigned char)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall first_in_stack(RGE_Action_Bird * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00402080(R)  
    //                               ?first_in_stack@RGE_Action_Bird@@UAEXE@Z                     XREF[1]:     0056e0f4(*)  
    //                               RGE_Action_Bird::first_in_stack
    //                              act_bird.cpp:48 (11)
    //         00402080     MOV        AL,byte ptr [ESP + param_1]
    //         00402084     PUSH       ESI
    //         00402085     TEST       AL,AL
    //         00402087     MOV        ESI,this
    //         00402089     JZ         LAB_004020af
    //                              act_bird.cpp:52 (21)
    //         0040208b     MOV        this,dword ptr [ESI + 0x8]
    //         0040208e     PUSH       0x40c00000
    //         00402093     MOV        EDX,dword ptr [ECX + this->field60_0x3c]
    //         00402096     MOV        EAX,dword ptr [this->field0_0x0]
    //         00402098     PUSH       EDX
    //         00402099     MOV        EDX,dword ptr [ECX + this->field56_0x38]
    //         0040209c     PUSH       EDX
    //         0040209d     CALL       dword ptr [EAX + 0x34]
    //                              act_bird.cpp:53 (11)
    //         004020a0     MOV        EAX,dword ptr [ESI]
    //         004020a2     PUSH       0x3
    //         004020a4     MOV        this,ESI
    //         004020a6     FSTP       ST0
    //         004020a8     CALL       dword ptr [EAX + 0x5c]
    //                              act_bird.cpp:57 (4)
    //         004020ab     POP        ESI
    //         004020ac     RET        0x4
    //                               LAB_004020af                                                 XREF[1]:     00402089(j)  
    //                              act_bird.cpp:56 (9)
    //         004020af     MOV        EDX,dword ptr [ESI]
    //         004020b1     PUSH       0x3
    //         004020b3     MOV        this,ESI
    //         004020b5     CALL       dword ptr [EDX + 0x5c]
    //                              act_bird.cpp:57 (4)
    //         004020b8     POP        ESI
    //         004020b9     RET        0x4
}

// Offset: 0x004020C0
void RGE_Action_Bird::set_state(uchar param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Action_Bird::set_state(unsigned char)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state(RGE_Action_Bird * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[5]:     004020c0(R), 00402111(W), 00402115(R), 0040214d(W), 
    //                                                                                     00402151(R)  
    //                               ?set_state@RGE_Action_Bird@@MAEXE@Z                          XREF[1]:     0056e134(*)  
    //                               RGE_Action_Bird::set_state
    //                              act_bird.cpp:61 (10)
    //         004020c0     MOV        EAX,dword ptr [ESP + param_1]
    //         004020c4     PUSH       ESI
    //         004020c5     MOV        ESI,this
    //         004020c7     MOV        byte ptr [ESI + 0xc],AL
    //                              act_bird.cpp:65 (15)
    //         004020ca     AND        EAX,0xff
    //         004020cf     SUB        EAX,0x4
    //         004020d2     JZ         LAB_00402121
    //         004020d4     SUB        EAX,0x2
    //         004020d7     JZ         LAB_004020e5
    //                              act_bird.cpp:85 (8)
    //         004020d9     MOV        this,dword ptr [ESI + 0x34]
    //         004020dc     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              act_bird.cpp:87 (4)
    //         004020e1     POP        ESI
    //         004020e2     RET        0x4
    //                               LAB_004020e5                                                 XREF[1]:     004020d7(j)  
    //                              act_bird.cpp:76 (41)
    //         004020e5     PUSH       0x4c
    //         004020e7     PUSH       s_C:\msdev\work\age1_x1\act_bird.c               = "C:\\msdev\\work\\age1_x1\\act_bird.cpp"
    //         004020ec     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004020f1     LEA        this,[EAX + EAX*0x4]
    //         004020f4     MOV        EAX,0x80010003
    //         004020f9     SHL        this,0x1
    //         004020fb     IMUL       this
    //         004020fd     ADD        EDX,this
    //         004020ff     ADD        ESP,0x8
    //         00402102     SAR        EDX,0xe
    //         00402105     MOV        EAX,EDX
    //         00402107     SHR        EAX,0x1f
    //         0040210a     LEA        this,[EDX + EAX*0x1 + 0x5]
    //                              act_bird.cpp:77 (17)
    //         0040210e     MOV        EDX,dword ptr [ESI + 0x30]
    //         00402111     MOV        dword ptr [ESP + param_1],this
    //         00402115     FILD       dword ptr [ESP + param_1]
    //         00402119     FSTP       float ptr [ESI + 0x2c]
    //         0040211c     MOV        EAX,dword ptr [EDX + 0x38]
    //                              act_bird.cpp:79 (2)
    //         0040211f     JMP        LAB_0040215b
    //                               LAB_00402121                                                 XREF[1]:     004020d2(j)  
    //                              act_bird.cpp:68 (41)
    //         00402121     PUSH       0x44
    //         00402123     PUSH       s_C:\msdev\work\age1_x1\act_bird.c               = "C:\\msdev\\work\\age1_x1\\act_bird.cpp"
    //         00402128     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0040212d     LEA        this,[EAX + EAX*0x4]
    //         00402130     MOV        EAX,0x80010003
    //         00402135     SHL        this,0x1
    //         00402137     IMUL       this
    //         00402139     ADD        EDX,this
    //         0040213b     ADD        ESP,0x8
    //         0040213e     SAR        EDX,0xe
    //         00402141     MOV        EAX,EDX
    //         00402143     SHR        EAX,0x1f
    //         00402146     LEA        this,[EDX + EAX*0x1 + 0x5]
    //                              act_bird.cpp:69 (17)
    //         0040214a     MOV        EDX,dword ptr [ESI + 0x30]
    //         0040214d     MOV        dword ptr [ESP + param_1],this
    //         00402151     FILD       dword ptr [ESP + param_1]
    //         00402155     FSTP       float ptr [ESI + 0x2c]
    //         00402158     MOV        EAX,dword ptr [EDX + 0x34]
    //                               LAB_0040215b                                                 XREF[1]:     0040211f(j)  
    //                              act_bird.cpp:70 (13)
    //         0040215b     MOV        this,dword ptr [ESI + 0x8]
    //         0040215e     TEST       EAX,EAX
    //         00402160     JZ         LAB_0040216c
    //         00402162     MOV        EDX,dword ptr [this->field0_0x0]
    //         00402164     PUSH       EAX
    //         00402165     CALL       dword ptr [EDX + 0x38]
    //                              act_bird.cpp:87 (4)
    //         00402168     POP        ESI
    //         00402169     RET        0x4
    //                               LAB_0040216c                                                 XREF[1]:     00402160(j)  
    //                              act_bird.cpp:72 (12)
    //         0040216c     MOV        EDX,dword ptr [ECX + this->field8_0x8]
    //         0040216f     MOV        EAX,dword ptr [this->field0_0x0]
    //         00402171     MOV        EDX,dword ptr [EDX + 0x18]
    //         00402174     PUSH       EDX
    //         00402175     CALL       dword ptr [EAX + 0x38]
    //                              act_bird.cpp:87 (4)
    //         00402178     POP        ESI
    //         00402179     RET        0x4
}

// Offset: 0x00402180
uchar RGE_Action_Bird::update() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Action_Bird::update(void)                                *
    //                              *********************************************************************************************************
    //                              uchar __thiscall update(RGE_Action_Bird * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004022f8(W), 0040232a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00402377(R), 00402388(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[5]:     004022a8(W), 004022ac(R), 004022d6(W), 004022dd(R), 
    //                                                                                     004022f2(W)  
    //                               ?update@RGE_Action_Bird@@UAEEXZ                              XREF[1]:     0056e100(*)  
    //                               RGE_Action_Bird::update
    //                              act_bird.cpp:91 (26)
    //         00402180     PUSH       -0x1
    //         00402182     PUSH       FUN_0055c11b
    //         00402187     MOV        EAX,FS:[0x0]
    //         0040218d     PUSH       EAX
    //         0040218e     MOV        dword ptr FS:[0x0],ESP
    //         00402195     PUSH       this
    //         00402196     PUSH       ESI
    //         00402197     MOV        ESI,this
    //         00402199     PUSH       EDI
    //                              act_bird.cpp:95 (16)
    //         0040219a     FLD        float ptr [ESI + 0x2c]
    //         0040219d     FCOMP      double ptr [DAT_0056e138]                        = align(8)
    //         004021a3     FNSTSW     AX
    //         004021a5     TEST       AH,0x41
    //         004021a8     JNZ        LAB_004021bf
    //                              act_bird.cpp:96 (21)
    //         004021aa     MOV        EAX,dword ptr [ESI + 0x8]
    //         004021ad     FLD        float ptr [ESI + 0x2c]
    //         004021b0     MOV        this,dword ptr [EAX + 0xc]
    //         004021b3     MOV        EDX,dword ptr [ECX + this->field60_0x3c]
    //         004021b6     FSUB       float ptr [EDX + 0x84]
    //         004021bc     FSTP       float ptr [ESI + 0x2c]
    //                               LAB_004021bf                                                 XREF[1]:     004021a8(j)  
    //                              act_bird.cpp:98 (22)
    //         004021bf     XOR        EAX,EAX
    //         004021c1     MOV        AL,byte ptr [ESI + 0xc]
    //         004021c4     DEC        EAX
    //         004021c5     CMP        EAX,0x5
    //         004021c8     JA         switchD_004021ce::caseD_1
    //                               switchD_004021ce::switchD
    //         004021ce     JMP        dword ptr [EAX*0x4 + switchD_004021ce::switchd   = 00402375
    //                               switchD_004021ce::caseD_3                                    XREF[2]:     004021ce(j), 004023a8(*)  
    //                              act_bird.cpp:102 (16)
    //         004021d5     FLD        float ptr [ESI + 0x2c]
    //         004021d8     FCOMP      double ptr [DAT_0056e138]                        = align(8)
    //         004021de     FNSTSW     AX
    //         004021e0     TEST       AH,0x41
    //         004021e3     JZ         LAB_004021ee
    //                              act_bird.cpp:103 (9)
    //         004021e5     MOV        EAX,dword ptr [ESI]
    //         004021e7     PUSH       0x6
    //         004021e9     MOV        this,ESI
    //         004021eb     CALL       dword ptr [EAX + 0x5c]
    //                               LAB_004021ee                                                 XREF[1]:     004021e3(j)  
    //                              act_bird.cpp:105 (20)
    //         004021ee     MOV        this,dword ptr [ESI + 0x34]
    //         004021f1     MOV        EDX,dword ptr [this->field0_0x0]
    //         004021f3     CALL       dword ptr [EDX + 0xc]
    //         004021f6     AND        EAX,0xff
    //         004021fb     DEC        EAX
    //         004021fc     JNZ        switchD_004021ce::caseD_1
    //                              act_bird.cpp:109 (9)
    //         00402202     MOV        EAX,dword ptr [ESI]
    //         00402204     PUSH       0x3
    //         00402206     MOV        this,ESI
    //         00402208     CALL       dword ptr [EAX + 0x5c]
    //                              act_bird.cpp:151 (2)
    //         0040220b     XOR        AL,AL
    //                              act_bird.cpp:152 (17)
    //         0040220d     MOV        this,dword ptr [ESP + 0xc]
    //         00402211     MOV        dword ptr FS:[0x0],this
    //         00402218     POP        EDI
    //         00402219     POP        ESI
    //         0040221a     ADD        ESP,0x10
    //         0040221d     RET
    //                               switchD_004021ce::caseD_5                                    XREF[2]:     004021ce(j), 004023b0(*)  
    //                              act_bird.cpp:116 (16)
    //         0040221e     FLD        float ptr [ESI + 0x2c]
    //         00402221     FCOMP      double ptr [DAT_0056e138]                        = align(8)
    //         00402227     FNSTSW     AX
    //         00402229     TEST       AH,0x41
    //         0040222c     JZ         LAB_00402237
    //                              act_bird.cpp:117 (9)
    //         0040222e     MOV        EDX,dword ptr [ESI]
    //         00402230     PUSH       0x4
    //         00402232     MOV        this,ESI
    //         00402234     CALL       dword ptr [EDX + 0x5c]
    //                               LAB_00402237                                                 XREF[1]:     0040222c(j)  
    //                              act_bird.cpp:119 (20)
    //         00402237     MOV        this,dword ptr [ESI + 0x34]
    //         0040223a     MOV        EAX,dword ptr [this->field0_0x0]
    //         0040223c     CALL       dword ptr [EAX + 0xc]
    //         0040223f     AND        EAX,0xff
    //         00402244     DEC        EAX
    //         00402245     JNZ        switchD_004021ce::caseD_1
    //                              act_bird.cpp:123 (9)
    //         0040224b     MOV        EDX,dword ptr [ESI]
    //         0040224d     PUSH       0x3
    //         0040224f     MOV        this,ESI
    //         00402251     CALL       dword ptr [EDX + 0x5c]
    //                              act_bird.cpp:151 (2)
    //         00402254     XOR        AL,AL
    //                              act_bird.cpp:152 (17)
    //         00402256     MOV        this,dword ptr [ESP + 0xc]
    //         0040225a     MOV        dword ptr FS:[0x0],this
    //         00402261     POP        EDI
    //         00402262     POP        ESI
    //         00402263     ADD        ESP,0x10
    //         00402266     RET
    //                               switchD_004021ce::caseD_2                                    XREF[2]:     004021ce(j), 004023a4(*)  
    //                              act_bird.cpp:130 (3)
    //         00402267     MOV        EAX,dword ptr [ESI + 0x8]
    //                              language.dll match for 0x84: "8"
    //                              act_bird.cpp:132 (47)
    //         0040226a     PUSH       0x84
    //         0040226f     PUSH       s_C:\msdev\work\age1_x1\act_bird.c               = "C:\\msdev\\work\\age1_x1\\act_bird.cpp"
    //         00402274     MOV        this,dword ptr [EAX + 0xc]
    //         00402277     MOV        EDX,dword ptr [ECX + this->field60_0x3c]
    //         0040227a     MOV        EDI,dword ptr [EDX + 0x28]
    //         0040227d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00402282     MOV        this,EAX
    //         00402284     MOV        EAX,0x80010003
    //         00402289     IMUL       this,dword ptr [EDI + 0x8]
    //         0040228d     IMUL       this
    //         0040228f     ADD        EDX,this
    //         00402291     ADD        ESP,0x8
    //         00402294     SAR        EDX,0xe
    //         00402297     MOV        EAX,EDX
    //                              language.dll match for 0x85: "N"
    //                              act_bird.cpp:133 (54)
    //         00402299     PUSH       0x85
    //         0040229e     SHR        EAX,0x1f
    //         004022a1     ADD        EDX,EAX
    //         004022a3     PUSH       s_C:\msdev\work\age1_x1\act_bird.c               = "C:\\msdev\\work\\age1_x1\\act_bird.cpp"
    //         004022a8     MOV        dword ptr [ESP + local_10],EDX
    //         004022ac     FILD       dword ptr [ESP + local_10]
    //         004022b0     FSTP       float ptr [ESI + 0x20]
    //         004022b3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004022b8     MOV        this,EAX
    //         004022ba     MOV        EAX,0x80010003
    //         004022bf     IMUL       this,dword ptr [EDI + 0xc]
    //         004022c3     IMUL       this
    //         004022c5     ADD        EDX,this
    //         004022c7     ADD        ESP,0x8
    //         004022ca     SAR        EDX,0xe
    //         004022cd     MOV        this,EDX
    //                              act_bird.cpp:137 (89)
    //         004022cf     PUSH       0x44
    //         004022d1     SHR        this,0x1f
    //         004022d4     ADD        EDX,this
    //         004022d6     MOV        dword ptr [ESP + local_10],EDX
    //         004022da     MOV        EDX,dword ptr [ESI + 0x8]
    //         004022dd     FILD       dword ptr [ESP + local_10]
    //         004022e1     FSTP       float ptr [ESI + 0x24]
    //         004022e4     MOV        EAX,dword ptr [EDX + 0x40]
    //         004022e7     MOV        dword ptr [ESI + 0x28],EAX
    //         004022ea     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004022ef     ADD        ESP,0x4
    //         004022f2     MOV        dword ptr [ESP + local_10],EAX
    //         004022f6     TEST       EAX,EAX
    //         004022f8     MOV        dword ptr [ESP + local_4],0x0
    //         00402300     JZ         LAB_00402326
    //         00402302     MOV        this,dword ptr [ESI + 0x8]
    //         00402305     MOV        EDX,dword ptr [ECX + this->field16_0x10]
    //         00402308     PUSH       EDX
    //         00402309     MOV        EDX,dword ptr [ESI + 0x30]
    //         0040230c     MOV        EDX,dword ptr [EDX + 0x24]
    //         0040230f     PUSH       EDX
    //         00402310     MOV        EDX,dword ptr [ESI + 0x28]
    //         00402313     PUSH       EDX
    //         00402314     MOV        EDX,dword ptr [ESI + 0x24]
    //         00402317     PUSH       EDX
    //         00402318     MOV        EDX,dword ptr [ESI + 0x20]
    //         0040231b     PUSH       EDX
    //         0040231c     PUSH       this
    //         0040231d     MOV        this,EAX
    //         0040231f     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         00402324     JMP        LAB_00402328
    //                               LAB_00402326                                                 XREF[1]:     00402300(j)  
    //         00402326     XOR        EAX,EAX
    //                               LAB_00402328                                                 XREF[1]:     00402324(j)  
    //                              act_bird.cpp:138 (12)
    //         00402328     TEST       EAX,EAX
    //         0040232a     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00402332     JNZ        LAB_00402350
    //                              act_bird.cpp:139 (9)
    //         00402334     MOV        EAX,dword ptr [ESI]
    //         00402336     PUSH       0x3
    //         00402338     MOV        this,ESI
    //         0040233a     CALL       dword ptr [EAX + 0x5c]
    //                              act_bird.cpp:151 (2)
    //         0040233d     XOR        AL,AL
    //                              act_bird.cpp:152 (17)
    //         0040233f     MOV        this,dword ptr [ESP + 0xc]
    //         00402343     MOV        dword ptr FS:[0x0],this
    //         0040234a     POP        EDI
    //         0040234b     POP        ESI
    //         0040234c     ADD        ESP,0x10
    //         0040234f     RET
    //                               LAB_00402350                                                 XREF[1]:     00402332(j)  
    //                              act_bird.cpp:142 (9)
    //         00402350     MOV        this,dword ptr [ESI + 0x34]
    //         00402353     PUSH       EAX
    //         00402354     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                              act_bird.cpp:143 (9)
    //         00402359     MOV        EDX,dword ptr [ESI]
    //         0040235b     PUSH       0x4
    //         0040235d     MOV        this,ESI
    //         0040235f     CALL       dword ptr [EDX + 0x5c]
    //                              act_bird.cpp:151 (2)
    //         00402362     XOR        AL,AL
    //                              act_bird.cpp:152 (17)
    //         00402364     MOV        this,dword ptr [ESP + 0xc]
    //         00402368     MOV        dword ptr FS:[0x0],this
    //         0040236f     POP        EDI
    //         00402370     POP        ESI
    //         00402371     ADD        ESP,0x10
    //         00402374     RET
    //                               switchD_004021ce::caseD_0                                    XREF[2]:     004021ce(j), 0040239c(*)  
    //                              act_bird.cpp:148 (2)
    //         00402375     MOV        AL,0x1
    //                              act_bird.cpp:152 (61)
    //         00402377     MOV        this,dword ptr [ESP + local_c]
    //         0040237b     MOV        dword ptr FS:[0x0],this
    //         00402382     POP        EDI
    //         00402383     POP        ESI
    //         00402384     ADD        ESP,0x10
    //         00402387     RET
    //                               switchD_004021ce::caseD_4                                    XREF[6]:     004021c8(j), 004021ce(j), 
    //                               switchD_004021ce::caseD_1                                                 004021fc(j), 00402245(j), 
    //                                                                                                         004023a0(*), 004023ac(*)  
    //         00402388     MOV        this,dword ptr [ESP + local_c]
    //         0040238c     POP        EDI
    //         0040238d     XOR        AL,AL
    //         0040238f     MOV        dword ptr FS:[0x0],this
    //         00402396     POP        ESI
    //         00402397     ADD        ESP,0x10
    //         0040239a     RET
}

