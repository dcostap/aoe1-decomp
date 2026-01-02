#include "../common.h"
#include "taiconmd.h"

TribeConstructionAIModule::TribeConstructionAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TribeConstructionAIModule(TribeConstructionAIMo
//              undefined         <UNASSIGNED>   <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5eb8(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5eb0(R)
//                               ??0TribeConstructionAIModule@@QAE@HH@Z                       XREF[1]:     TribeMainDecisionAIModule:004e4bd6
//                               TribeConstructionAIModule::TribeConstructionAIModule
//                              taiconmd.cpp:45 (36)
//         004d5eb0     MOV        EAX,dword ptr [ESP + param_2]
//         004d5eb4     PUSH       ESI
//         004d5eb5     MOV        ESI,this
//         004d5eb7     PUSH       EAX
//         004d5eb8     MOV        this,dword ptr [ESP + param_1]
//         004d5ebc     PUSH       this
//         004d5ebd     MOV        this,ESI
//         004d5ebf     CALL       ConstructionAIModule::ConstructionAIModule       undefined ConstructionAIModule(ConstructionAI
//         004d5ec4     MOV        dword ptr [ESI + 0x314],0x0
//         004d5ece     MOV        dword ptr [ESI],TribeConstructionAIModule::`vf   = 004d5e90
//                              taiconmd.cpp:46 (6)
//         004d5ed4     MOV        EAX,ESI
//         004d5ed6     POP        ESI
//         004d5ed7     RET        0x8
//         004d5eda     ??         90h
//         004d5edb     NOP
//         004d5edc     NOP
//         004d5edd     NOP
//         004d5ede     NOP
//         004d5edf     NOP
}

TribeConstructionAIModule::TribeConstructionAIModule(int param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TribeConstructionAIModule(TribeConstructionAIMo
//              undefined         <UNASSIGNED>   <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5eb8(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5eb0(R)
//                               ??0TribeConstructionAIModule@@QAE@HH@Z                       XREF[1]:     TribeMainDecisionAIModule:004e4bd6
//                               TribeConstructionAIModule::TribeConstructionAIModule
//                              taiconmd.cpp:45 (36)
//         004d5eb0     MOV        EAX,dword ptr [ESP + param_2]
//         004d5eb4     PUSH       ESI
//         004d5eb5     MOV        ESI,this
//         004d5eb7     PUSH       EAX
//         004d5eb8     MOV        this,dword ptr [ESP + param_1]
//         004d5ebc     PUSH       this
//         004d5ebd     MOV        this,ESI
//         004d5ebf     CALL       ConstructionAIModule::ConstructionAIModule       undefined ConstructionAIModule(ConstructionAI
//         004d5ec4     MOV        dword ptr [ESI + 0x314],0x0
//         004d5ece     MOV        dword ptr [ESI],TribeConstructionAIModule::`vf   = 004d5e90
//                              taiconmd.cpp:46 (6)
//         004d5ed4     MOV        EAX,ESI
//         004d5ed6     POP        ESI
//         004d5ed7     RET        0x8
//         004d5eda     ??         90h
//         004d5edb     NOP
//         004d5edc     NOP
//         004d5edd     NOP
//         004d5ede     NOP
//         004d5edf     NOP
}

TribeConstructionAIModule::~TribeConstructionAIModule() {
    /* TODO: Stub */
//                              void __thiscall ~TribeConstructionAIModule(TribeConstructionAIModule
//              void              <VOID>         <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//                               ??1TribeConstructionAIModule@@UAE@XZ                         XREF[4]:     `scalar_deleting_destructor':004d5
//                               TribeConstructionAIModule::~TribeConstructionAIModule                     ~TribeMainDecisionAIModule:004e4f6
//                                                                                                         FUN_00560636:0056063f(c),
//                                                                                                         FUN_005606c6:005606cf(c)
//                              taiconmd.cpp:51 (11)
//         004d5ee0     MOV        dword ptr [this->_padding_],TribeConstructionA   = 004d5e90
//         004d5ee6     JMP        ConstructionAIModule::~ConstructionAIModule      void ~ConstructionAIModule(ConstructionAIModu
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         004d5eeb     ??         90h
//         004d5eec     NOP
//         004d5eed     NOP
//         004d5eee     NOP
//         004d5eef     NOP
}

void TribeConstructionAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    /* TODO: Stub */
//                              void __thiscall setMainDecisionAI(TribeConstructionAIModule * this,
//              void              <VOID>         <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              TribeMainDecis    Stack[0x4]:4   param_1                   XREF[1]:     004d5ef0(R)
//                               ?setMainDecisionAI@TribeConstructionAIModule@@QAEXPAVTribeM  XREF[2]:     TribeMainDecisionAIModule:004e4989
//                               TribeConstructionAIModule::setMainDecisionAI                              TribeMainDecisionAIModule:004e4ccc
//                              taiconmd.cpp:57 (10)
//         004d5ef0     MOV        EAX,dword ptr [ESP + param_1]
//         004d5ef4     MOV        dword ptr [ECX + this->md],EAX
//                              taiconmd.cpp:59 (3)
//         004d5efa     RET        0x4
//         004d5efd     ??         90h
//         004d5efe     NOP
//         004d5eff     NOP
    return;
}

int TribeConstructionAIModule::canPlace(BuildItem* param_1) {
    /* TODO: Stub */
//                              int __thiscall canPlace(TribeConstructionAIModule * this, BuildItem
//              int               EAX:4          <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[2]:     004d5f7d(R), 004d60a0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004d5fd4(W), 004d606e(W), 004d6086(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d60b9(R)
//              ConstructionIt    Stack[-0x90]   tempLots                  XREF[4,7]:   004d600e(W), 004d6019(R), 004d602b(W), 004d6036(R),
//                                                                                     004d5fb5(*), 004d5fca(*), 004d5fce(*), 004d606a(*),
//                                                                                     004d6082(*), 004d5fdf(W), 004d5fe6(W)
//                               ?canPlace@TribeConstructionAIModule@@QAEHPAVBuildItem@@@Z    XREF[1]:     nextBuildableItem:004d4d54(c)
//                               TribeConstructionAIModule::canPlace
//                              taiconmd.cpp:64 (33)
//         004d5f00     MOV        EAX,FS:[0x0]
//         004d5f06     PUSH       -0x1
//         004d5f08     PUSH       FUN_005602db
//         004d5f0d     PUSH       EAX
//         004d5f0e     MOV        dword ptr FS:[0x0],ESP
//         004d5f15     SUB        ESP,0x84
//         004d5f1b     PUSH       EBX
//         004d5f1c     PUSH       EBP
//         004d5f1d     PUSH       ESI
//         004d5f1e     PUSH       EDI
//         004d5f1f     MOV        EDI,this
//                              taiconmd.cpp:68 (92)
//         004d5f21     FLD        float ptr [EDI + 0x2fc]
//         004d5f27     FCOMP      double ptr [null_00575500]                       = align(11)
//         004d5f2d     FNSTSW     AX
//         004d5f2f     TEST       AH,0x41
//         004d5f32     JNZ        LAB_004d60a0
//         004d5f38     FLD        float ptr [EDI + 0x300]
//         004d5f3e     FCOMP      double ptr [null_00575500]                       = align(11)
//         004d5f44     FNSTSW     AX
//         004d5f46     TEST       AH,0x41
//         004d5f49     JNZ        LAB_004d60a0
//         004d5f4f     FILD       dword ptr [EDI + 0x308]
//         004d5f55     FCOMP      float ptr [EDI + 0x2fc]
//         004d5f5b     FNSTSW     AX
//         004d5f5d     TEST       AH,0x41
//         004d5f60     JNZ        LAB_004d60a0
//         004d5f66     FILD       dword ptr [EDI + 0x30c]
//         004d5f6c     FCOMP      float ptr [EDI + 0x300]
//         004d5f72     FNSTSW     AX
//         004d5f74     TEST       AH,0x41
//         004d5f77     JNZ        LAB_004d60a0
//                              taiconmd.cpp:74 (19)
//         004d5f7d     MOV        EBX,dword ptr [ESP + param_1]
//         004d5f84     MOV        this,EBX
//         004d5f86     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d5f8b     CMP        EAX,0x2d
//         004d5f8e     JNZ        LAB_004d5f9a
//                              taiconmd.cpp:75 (10)
//         004d5f90     MOV        EAX,0x1
//         004d5f95     JMP        LAB_004d60b9
//                               LAB_004d5f9a                                                 XREF[1]:     004d5f8e(j)
//                              taiconmd.cpp:80 (27)
//         004d5f9a     CMP        dword ptr [useInfluencePlacement],0x1
//         004d5fa1     JZ         LAB_004d609d
//         004d5fa7     MOV        EAX,dword ptr [EDI + 0xf0]
//         004d5fad     TEST       EAX,EAX
//         004d5faf     JZ         LAB_004d609d
//                              taiconmd.cpp:86 (9)
//         004d5fb5     LEA        this=>tempLots._padding_,[ESP + 0x14]
//         004d5fb9     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
//                              taiconmd.cpp:90 (6)
//         004d5fbe     MOV        ESI,dword ptr [EDI + 0x160]
//                              taiconmd.cpp:91 (47)
//         004d5fc4     ADD        EDI,0xf4
//         004d5fca     LEA        EAX=>tempLots._padding_,[ESP + 0x14]
//         004d5fce     LEA        this=>tempLots._padding_,[ESP + 0x14]
//         004d5fd2     CMP        ESI,EDI
//         004d5fd4     MOV        dword ptr [ESP + local_4],0x0
//         004d5fdf     MOV        dword ptr [ESP + tempLots.prev],EAX
//         004d5fe6     MOV        dword ptr [ESP + tempLots.inProgressValue],this
//         004d5fed     JZ         LAB_004d606a
//                               LAB_004d5fef                                                 XREF[1]:     004d6068(j)
//         004d5fef     TEST       ESI,ESI
//         004d5ff1     JZ         LAB_004d606a
//                              taiconmd.cpp:99 (112)
//         004d5ff3     MOV        this,ESI
//         004d5ff5     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d5ffa     MOV        this,EBX
//         004d5ffc     MOV        EBP,EAX
//         004d5ffe     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6003     CMP        EBP,EAX
//         004d6005     JZ         LAB_004d604d
//         004d6007     MOV        this,ESI
//         004d6009     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d600e     FSTP       float ptr [ESP + tempLots._padding_]
//         004d6012     MOV        this,EBX
//         004d6014     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d6019     FCOMP      float ptr [ESP + tempLots._padding_]
//         004d601d     FNSTSW     AX
//         004d601f     TEST       AH,0x40
//         004d6022     JZ         LAB_004d6063
//         004d6024     MOV        this,ESI
//         004d6026     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d602b     FSTP       float ptr [ESP + tempLots._padding_]
//         004d602f     MOV        this,EBX
//         004d6031     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d6036     FCOMP      float ptr [ESP + tempLots._padding_]
//         004d603a     FNSTSW     AX
//         004d603c     TEST       AH,0x40
//         004d603f     JZ         LAB_004d6063
//         004d6041     MOV        this,ESI
//         004d6043     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6048     CMP        EAX,-0x1
//         004d604b     JNZ        LAB_004d6063
//                               LAB_004d604d                                                 XREF[1]:     004d6005(j)
//         004d604d     MOV        this,ESI
//         004d604f     CALL       ConstructionItem::built                          int built(ConstructionItem * this)
//         004d6054     TEST       EAX,EAX
//         004d6056     JNZ        LAB_004d6063
//         004d6058     MOV        this,ESI
//         004d605a     CALL       ConstructionItem::inProgress                     int inProgress(ConstructionItem * this)
//         004d605f     TEST       EAX,EAX
//         004d6061     JZ         LAB_004d6082
//                               LAB_004d6063                                                 XREF[4]:     004d6022(j), 004d603f(j),
//                                                                                                         004d604b(j), 004d6056(j)
//                              taiconmd.cpp:102 (11)
//         004d6063     MOV        ESI,dword ptr [ESI + 0x6c]
//         004d6066     CMP        ESI,EDI
//         004d6068     JNZ        LAB_004d5fef
//                               LAB_004d606a                                                 XREF[2]:     004d5fed(j), 004d5ff1(j)
//         004d606a     LEA        this=>tempLots._padding_,[ESP + 0x14]
//                              taiconmd.cpp:104 (24)
//         004d606e     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d6079     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
//         004d607e     XOR        EAX,EAX
//         004d6080     JMP        LAB_004d60b9
//                               LAB_004d6082                                                 XREF[1]:     004d6061(j)
//         004d6082     LEA        this=>tempLots._padding_,[ESP + 0x14]
//                              taiconmd.cpp:100 (23)
//         004d6086     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d6091     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
//         004d6096     MOV        EAX,0x1
//         004d609b     JMP        LAB_004d60b9
//                               LAB_004d609d                                                 XREF[2]:     004d5fa1(j), 004d5faf(j)
//                              taiconmd.cpp:81 (3)
//         004d609d     PUSH       EBX
//         004d609e     JMP        LAB_004d60a8
//                               LAB_004d60a0                                                 XREF[4]:     004d5f32(j), 004d5f49(j),
//                                                                                                         004d5f60(j), 004d5f77(j)
//                              taiconmd.cpp:69 (25)
//         004d60a0     MOV        EDX,dword ptr [ESP + param_1]
//         004d60a7     PUSH       EDX
//                               LAB_004d60a8                                                 XREF[1]:     004d609e(j)
//         004d60a8     MOV        this,dword ptr [EDI + 0x314]
//         004d60ae     ADD        this,0xcec
//         004d60b4     CALL       TribeInformationAIModule::influenceCanPlaceStr   int influenceCanPlaceStructure(TribeInformati
//                               LAB_004d60b9                                                 XREF[3]:     004d5f95(j), 004d6080(j),
//                                                                                                         004d609b(j)
//                              taiconmd.cpp:105 (27)
//         004d60b9     MOV        this,dword ptr [ESP + local_c]
//         004d60c0     POP        EDI
//         004d60c1     POP        ESI
//         004d60c2     POP        EBP
//         004d60c3     MOV        dword ptr FS:[0x0],this
//         004d60ca     POP        EBX
//         004d60cb     ADD        ESP,0x90
//         004d60d1     RET        0x4
//         004d60d4     ??         90h
//         004d60d5     NOP
//         004d60d6     NOP
//         004d60d7     NOP
//         004d60d8     NOP
//         004d60d9     NOP
//         004d60da     NOP
//         004d60db     NOP
//         004d60dc     NOP
//         004d60dd     NOP
//         004d60de     NOP
//         004d60df     NOP
    return 0;
}

ConstructionItem* TribeConstructionAIModule::placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4) {
    /* TODO: Stub */
//                              ConstructionItem * __thiscall placeStructure(TribeConstructionAIModu
//              ConstructionIt    EAX:4          <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[3]:     004d6161(R), 004d6515(R), 004d6735(R)
//              int               Stack[0x8]:4   param_2                   XREF[4]:     004d6286(R), 004d654b(R), 004d6704(R), 004d672d(R)
//              PlacementState    Stack[0xc]:4   param_3                   XREF[3]:     004d6544(R), 004d66fd(R), 004d6726(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[3]:     004d653d(R), 004d66f6(R), 004d671f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d6199(W), 004d62d0(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d675e(R)
//              ConstructionIt    Stack[-0x90]   tempLots                  XREF[2,5]:   004d629b(W), 004d6439(R), 004d62b1(*), 004d62c6(*),
//                                                                                     004d62ca(*), 004d62d7(W), 004d62de(W)
//              RGE_Static_Obj    Stack[-0x94]:4 builderObj                XREF[2]:     004d627c(W), 004d6456(R)
//              RGE_Static_Obj    Stack[-0x98]:4 protoBuilder              XREF[3]:     004d63c7(W), 004d63eb(R), 004d642d(R)
//              int               Stack[-0x9c]:4 minY                      XREF[2]:     004d6427(W), 004d6468(R)
//              int               Stack[-0xa0]:4 i                         XREF[2]:     004d6433(W), 004d6452(R)
//              int               Stack[-0xa4]:4 j                         XREF[1]:     004d62e5(W)
//              int               Stack[-0xa8]:4 numberTempLots            XREF[3]:     004d6193(W), 004d62f5(W), 004d6523(R)
//              undefined4        Stack[-0xac]:4 local_ac                  XREF[2]:     004d62ed(W), 004d652f(R)
//              int               Stack[-0xb0]:4 minBuildAttempts          XREF[3]:     004d610d(W), 004d6401(R), 004d651c(R)
//              undefined4        Stack[-0xb4]:4 local_b4                  XREF[10]:    004d6332(W), 004d633d(R), 004d6353(W), 004d635e(R),
//                                                                                     004d6394(W), 004d639f(R), 004d63b1(W), 004d63bc(R),
//                                                                                     004d63db(W), 004d641f(R)
//              int               Stack[-0xb8]:4 maxX                      XREF[0,3]:   004d629f(W), 004d62ad(W), 004d6448(R)
//              uchar             Stack[-0xb9]:1 builderZone
//                               ?placeStructure@TribeConstructionAIModule@@QAEPAVConstructi  XREF[2]:     doSomething:004f08b7(c),
//                               TribeConstructionAIModule::placeStructure                                 taskBuilder:004f9b2a(c)
//                              taiconmd.cpp:111 (32)
//         004d60e0     PUSH       -0x1
//         004d60e2     PUSH       FUN_00560325
//         004d60e7     MOV        EAX,FS:[0x0]
//         004d60ed     PUSH       EAX
//         004d60ee     MOV        dword ptr FS:[0x0],ESP
//         004d60f5     SUB        ESP,0xac
//         004d60fb     PUSH       EBX
//         004d60fc     MOV        EBX,this
//         004d60fe     PUSH       EBP
//         004d60ff     PUSH       ESI
//                              taiconmd.cpp:121 (97)
//         004d6100     FLD        float ptr [EBX + 0x2fc]
//         004d6106     FCOMP      double ptr [null_00575500]                       = align(11)
//         004d610c     PUSH       EDI
//         004d610d     MOV        dword ptr [ESP + minBuildAttempts],EBX
//         004d6111     FNSTSW     AX
//         004d6113     TEST       AH,0x41
//         004d6116     JNZ        LAB_004d671f
//         004d611c     FLD        float ptr [EBX + 0x300]
//         004d6122     FCOMP      double ptr [null_00575500]                       = align(11)
//         004d6128     FNSTSW     AX
//         004d612a     TEST       AH,0x41
//         004d612d     JNZ        LAB_004d671f
//         004d6133     FILD       dword ptr [EBX + 0x308]
//         004d6139     FCOMP      float ptr [EBX + 0x2fc]
//         004d613f     FNSTSW     AX
//         004d6141     TEST       AH,0x41
//         004d6144     JNZ        LAB_004d671f
//         004d614a     FILD       dword ptr [EBX + 0x30c]
//         004d6150     FCOMP      float ptr [EBX + 0x300]
//         004d6156     FNSTSW     AX
//         004d6158     TEST       AH,0x41
//         004d615b     JNZ        LAB_004d671f
//                              taiconmd.cpp:133 (19)
//         004d6161     MOV        EBP,dword ptr [ESP + param_1]
//         004d6168     MOV        this,EBP
//         004d616a     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d616f     CMP        EAX,0x2d
//         004d6172     JNZ        LAB_004d61b7
//                              taiconmd.cpp:134 (10)
//         004d6174     PUSH       EBP
//         004d6175     MOV        this,EBX
//         004d6177     CALL       TribeConstructionAIModule::placeDock             ConstructionItem * placeDock(TribeConstructio
//         004d617c     MOV        ESI,EAX
//                              taiconmd.cpp:135 (8)
//         004d617e     TEST       ESI,ESI
//         004d6180     JZ         LAB_004d65bc
//                              language.dll match for 0x80: "Arial"
//                              taiconmd.cpp:136 (49)
//         004d6186     PUSH       0x80
//         004d618b     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d6190     ADD        ESP,0x4
//         004d6193     MOV        dword ptr [ESP + numberTempLots],EAX
//         004d6197     TEST       EAX,EAX
//         004d6199     MOV        dword ptr [ESP + local_4],0x0
//         004d61a4     JZ         LAB_004d65bc
//         004d61aa     PUSH       ESI
//         004d61ab     MOV        this,EAX
//         004d61ad     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
//         004d61b2     JMP        LAB_004d675e
//                               LAB_004d61b7                                                 XREF[1]:     004d6172(j)
//                              taiconmd.cpp:151 (164)
//         004d61b7     MOV        this,EBP
//         004d61b9     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d61be     CMP        EAX,0x67
//         004d61c1     JZ         LAB_004d66f6
//         004d61c7     MOV        this,EBP
//         004d61c9     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d61ce     CMP        EAX,0x44
//         004d61d1     JZ         LAB_004d66f6
//         004d61d7     MOV        this,EBP
//         004d61d9     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d61de     CMP        EAX,0x4f
//         004d61e1     JZ         LAB_004d66f6
//         004d61e7     MOV        this,EBP
//         004d61e9     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d61ee     CMP        EAX,0xc7
//         004d61f3     JZ         LAB_004d66f6
//         004d61f9     MOV        this,EBP
//         004d61fb     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6200     CMP        EAX,0x45
//         004d6203     JZ         LAB_004d66f6
//         004d6209     MOV        this,EBP
//         004d620b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6210     CMP        EAX,0x48
//         004d6213     JZ         LAB_004d66f6
//         004d6219     MOV        this,EBP
//         004d621b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6220     CMP        EAX,0x75
//         004d6223     JZ         LAB_004d66f6
//         004d6229     MOV        this,EBP
//         004d622b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6230     CMP        EAX,0x9b
//         004d6235     JZ         LAB_004d66f6
//         004d623b     MOV        EAX,[useInfluencePlacement]
//         004d6240     MOV        ESI,0x1
//         004d6245     CMP        EAX,ESI
//         004d6247     JZ         LAB_004d66f6
//         004d624d     MOV        EAX,dword ptr [EBX + 0xf0]
//         004d6253     TEST       EAX,EAX
//         004d6255     JZ         LAB_004d66f6
//                              taiconmd.cpp:159 (31)
//         004d625b     PUSH       -0x1
//         004d625d     PUSH       -0x1
//         004d625f     MOV        this,dword ptr [EBX + 0x314]
//         004d6265     PUSH       -0x1
//         004d6267     PUSH       -0x1
//         004d6269     PUSH       -0x1
//         004d626b     PUSH       -0x1
//         004d626d     PUSH       -0x1
//         004d626f     PUSH       0x4
//         004d6271     PUSH       -0x1
//         004d6273     PUSH       -0x1
//         004d6275     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
//                              taiconmd.cpp:160 (12)
//         004d627a     TEST       EAX,EAX
//         004d627c     MOV        dword ptr [ESP + builderObj],EAX
//         004d6280     JZ         LAB_004d675e
//                              taiconmd.cpp:164 (19)
//         004d6286     MOV        EAX,dword ptr [ESP + param_2]
//         004d628d     MOV        this,dword ptr [EBX + 0x314]
//         004d6293     PUSH       EAX
//         004d6294     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
//                              taiconmd.cpp:166 (13)
//         004d6299     TEST       EAX,EAX
//         004d629b     MOV        dword ptr [ESP + tempLots._padding_],EAX
//         004d629f     MOV        byte ptr [ESP + maxX+0x3],0x0
//         004d62a4     JZ         LAB_004d62b1
//                              taiconmd.cpp:167 (11)
//         004d62a6     MOV        this,EAX
//         004d62a8     CALL       RGE_Static_Object::currentZone                   uchar currentZone(RGE_Static_Object * this)
//         004d62ad     MOV        byte ptr [ESP + maxX+0x3],AL
//                               LAB_004d62b1                                                 XREF[1]:     004d62a4(j)
//                              taiconmd.cpp:172 (9)
//         004d62b1     LEA        this=>tempLots._padding_,[ESP + 0x3c]
//         004d62b5     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
//                              taiconmd.cpp:176 (6)
//         004d62ba     MOV        EDI,dword ptr [EBX + 0x160]
//                              taiconmd.cpp:179 (71)
//         004d62c0     LEA        EAX,[EBX + 0xf4]
//         004d62c6     LEA        this=>tempLots._padding_,[ESP + 0x3c]
//         004d62ca     LEA        EDX=>tempLots._padding_,[ESP + 0x3c]
//         004d62ce     CMP        EDI,EAX
//         004d62d0     MOV        dword ptr [ESP + local_4],ESI
//         004d62d7     MOV        dword ptr [ESP + tempLots.prev],this
//         004d62de     MOV        dword ptr [ESP + tempLots.inProgressValue],EDX
//         004d62e5     MOV        dword ptr [ESP + j],0x0
//         004d62ed     MOV        dword ptr [ESP + local_ac],0xffffffff
//         004d62f5     MOV        dword ptr [ESP + numberTempLots],EAX
//         004d62f9     JZ         LAB_004d652f
//                               LAB_004d62ff                                                 XREF[1]:     004d6529(j)
//         004d62ff     TEST       EDI,EDI
//         004d6301     JZ         LAB_004d652f
//                              taiconmd.cpp:188 (134)
//         004d6307     MOV        this,EBP
//         004d6309     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d630e     MOV        this,EDI
//         004d6310     MOV        ESI,EAX
//         004d6312     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6317     CMP        EAX,ESI
//         004d6319     JZ         LAB_004d632b
//         004d631b     MOV        this,EDI
//         004d631d     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6322     CMP        EAX,-0x1
//         004d6325     JNZ        LAB_004d6520
//                               LAB_004d632b                                                 XREF[1]:     004d6319(j)
//         004d632b     MOV        this,EDI
//         004d632d     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d6332     FSTP       float ptr [ESP + local_b4]
//         004d6336     MOV        this,EBP
//         004d6338     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d633d     FCOMP      float ptr [ESP + local_b4]
//         004d6341     FNSTSW     AX
//         004d6343     TEST       AH,0x40
//         004d6346     JZ         LAB_004d6520
//         004d634c     MOV        this,EDI
//         004d634e     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d6353     FSTP       float ptr [ESP + local_b4]
//         004d6357     MOV        this,EBP
//         004d6359     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d635e     FCOMP      float ptr [ESP + local_b4]
//         004d6362     FNSTSW     AX
//         004d6364     TEST       AH,0x40
//         004d6367     JZ         LAB_004d6520
//         004d636d     MOV        this,EDI
//         004d636f     CALL       ConstructionItem::built                          int built(ConstructionItem * this)
//         004d6374     CMP        EAX,0x1
//         004d6377     JZ         LAB_004d6520
//         004d637d     MOV        this,EDI
//         004d637f     CALL       ConstructionItem::inProgress                     int inProgress(ConstructionItem * this)
//         004d6384     CMP        EAX,0x1
//         004d6387     JZ         LAB_004d6520
//                              taiconmd.cpp:197 (27)
//         004d638d     MOV        this,EDI
//         004d638f     CALL       BaseItem::x                                      float x(BaseItem * this)
//         004d6394     FSTP       float ptr [ESP + local_b4]
//         004d6398     MOV        this,EDI
//         004d639a     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d639f     FSUBR      float ptr [ESP + local_b4]
//         004d63a3     CALL       __ftol                                           undefined __ftol()
//                              taiconmd.cpp:198 (29)
//         004d63a8     MOV        this,EDI
//         004d63aa     MOV        ESI,EAX
//         004d63ac     CALL       BaseItem::y                                      float y(BaseItem * this)
//         004d63b1     FSTP       float ptr [ESP + local_b4]
//         004d63b5     MOV        this,EDI
//         004d63b7     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d63bc     FSUBR      float ptr [ESP + local_b4]
//         004d63c0     CALL       __ftol                                           undefined __ftol()
//                              taiconmd.cpp:199 (18)
//         004d63c5     MOV        this,EDI
//         004d63c7     MOV        dword ptr [ESP + protoBuilder],EAX
//         004d63cb     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004d63d0     CALL       __ftol                                           undefined __ftol()
//         004d63d5     MOV        EBP,EAX
//                              taiconmd.cpp:200 (26)
//         004d63d7     MOV        this,EDI
//         004d63d9     ADD        EBP,ESI
//         004d63db     MOV        dword ptr [ESP + local_b4],EBP
//         004d63df     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         004d63e4     CALL       __ftol                                           undefined __ftol()
//         004d63e9     MOV        EBX,EAX
//         004d63eb     MOV        EAX,dword ptr [ESP + protoBuilder]
//         004d63ef     ADD        EBX,EAX
//                              taiconmd.cpp:203 (46)
//         004d63f1     TEST       ESI,ESI
//         004d63f3     JL         LAB_004d6515
//         004d63f9     TEST       EAX,EAX
//         004d63fb     JL         LAB_004d6515
//         004d6401     MOV        EAX,dword ptr [ESP + minBuildAttempts]
//         004d6405     CMP        EBP,dword ptr [EAX + 0x308]
//         004d640b     JGE        LAB_004d6515
//         004d6411     MOV        this,EAX
//         004d6413     CMP        EBX,dword ptr [ECX + this->_padding_]
//         004d6419     JGE        LAB_004d6515
//                              taiconmd.cpp:206 (14)
//         004d641f     MOV        EAX,dword ptr [ESP + local_b4]
//         004d6423     MOV        EBP,ESI
//         004d6425     CMP        ESI,EAX
//         004d6427     MOV        dword ptr [ESP + minY],EBP
//         004d642b     JGE        LAB_004d649a
//                               LAB_004d642d                                                 XREF[1]:     004d6498(j)
//                              taiconmd.cpp:207 (12)
//         004d642d     MOV        ESI,dword ptr [ESP + protoBuilder]
//         004d6431     CMP        ESI,EBX
//         004d6433     MOV        dword ptr [ESP + i],ESI
//         004d6437     JGE        LAB_004d648d
//                               LAB_004d6439                                                 XREF[1]:     004d648b(j)
//                              taiconmd.cpp:208 (8)
//         004d6439     MOV        this,dword ptr [ESP + tempLots._padding_]
//         004d643d     TEST       this,this
//         004d643f     JZ         LAB_004d6452
//                              taiconmd.cpp:209 (7)
//         004d6441     PUSH       ESI
//         004d6442     PUSH       EBP=>DAT_fffffff8
//         004d6443     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
//                              taiconmd.cpp:210 (10)
//         004d6448     CMP        AL,byte ptr [ESP + maxX+0x3]
//         004d644c     JNZ        LAB_004d6515
//                               LAB_004d6452                                                 XREF[1]:     004d643f(j)
//                              taiconmd.cpp:217 (59)
//         004d6452     FILD       dword ptr [ESP + i]
//         004d6456     MOV        this,dword ptr [ESP + builderObj]
//         004d645a     PUSH       0x1
//         004d645c     PUSH       this=>DAT_fffffff8
//         004d645d     FSUB       float ptr [null_00575508]                        = align(3)
//         004d6463     MOV        EDX,dword ptr [this->_padding_]
//         004d6465     FSTP       float ptr [ESP]=>DAT_fffffff8
//         004d6468     FILD       dword ptr [ESP + minY]
//         004d646c     PUSH       this=>DAT_fffffff4
//         004d646d     FSUB       float ptr [null_00575508]                        = align(3)
//         004d6473     FSTP       float ptr [ESP]=>DAT_fffffff4
//         004d6476     CALL       dword ptr [EDX + 0x114]
//         004d647c     TEST       EAX,EAX
//         004d647e     JZ         LAB_004d6515
//         004d6484     INC        ESI
//         004d6485     CMP        ESI,EBX
//         004d6487     MOV        dword ptr [ESP + 0x28],ESI
//         004d648b     JL         LAB_004d6439
//                               LAB_004d648d                                                 XREF[1]:     004d6437(j)
//                              taiconmd.cpp:206 (13)
//         004d648d     MOV        EAX,dword ptr [ESP + 0x14]
//         004d6491     INC        EBP
//         004d6492     CMP        EBP,EAX
//         004d6494     MOV        dword ptr [ESP + 0x2c],EBP
//         004d6498     JL         LAB_004d642d
//                              language.dll match for 0x80: "Arial"
//                               LAB_004d649a                                                 XREF[1]:     004d642b(j)
//                              taiconmd.cpp:231 (41)
//         004d649a     PUSH       0x80
//         004d649f     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d64a4     ADD        ESP,0x4
//         004d64a7     MOV        dword ptr [ESP + 0x14],EAX
//         004d64ab     TEST       EAX,EAX
//         004d64ad     MOV        byte ptr [ESP + 0xc4],0x2
//         004d64b5     JZ         LAB_004d64c1
//         004d64b7     PUSH       EDI
//         004d64b8     MOV        this,EAX
//         004d64ba     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
//         004d64bf     JMP        LAB_004d64c3
//                               LAB_004d64c1                                                 XREF[1]:     004d64b5(j)
//         004d64c1     XOR        EAX,EAX
//                               LAB_004d64c3                                                 XREF[1]:     004d64bf(j)
//                              taiconmd.cpp:232 (4)
//         004d64c3     LEA        this,[ESP + 0x3c]
//                              taiconmd.cpp:239 (67)
//         004d64c7     MOV        ESI,dword ptr [ESP + 0x1c]
//         004d64cb     MOV        dword ptr [EAX + 0x6c],this
//         004d64ce     MOV        EDX,dword ptr [ESP + 0xac]
//         004d64d5     MOV        dword ptr [EAX + 0x70],EDX
//         004d64d8     MOV        this,dword ptr [ESP + 0xac]
//         004d64df     MOV        byte ptr [ESP + 0xc4],0x1
//         004d64e7     MOV        dword ptr [ECX + this->_padding_],EAX
//         004d64ea     MOV        this,dword ptr [ESP + 0x24]
//         004d64ee     INC        this
//         004d64ef     CMP        ESI,-0x1
//         004d64f2     MOV        dword ptr [ESP + 0xac],EAX
//         004d64f9     MOV        dword ptr [ESP + 0x24],this
//         004d64fd     JZ         LAB_004d650a
//         004d64ff     MOV        this,EDI
//         004d6501     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d6506     CMP        ESI,EAX
//         004d6508     JLE        LAB_004d6515
//                               LAB_004d650a                                                 XREF[1]:     004d64fd(j)
//                              taiconmd.cpp:240 (22)
//         004d650a     MOV        this,EDI
//         004d650c     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d6511     MOV        dword ptr [ESP + 0x1c],EAX
//                               LAB_004d6515                                                 XREF[7]:     004d63f3(j), 004d63fb(j),
//                                                                                                         004d640b(j), 004d6419(j),
//                                                                                                         004d644c(j), 004d647e(j),
//                                                                                                         004d6508(j)
//         004d6515     MOV        EBP,dword ptr [ESP + param_1]
//         004d651c     MOV        EBX,dword ptr [ESP + minBuildAttempts]
//                              Symbol Ref: No symbol: LoopDone
//                               LAB_004d6520                                                 XREF[5]:     004d6325(j), 004d6346(j),
//                                                                                                         004d6367(j), 004d6377(j),
//                                                                                                         004d6387(j)
//                              taiconmd.cpp:243 (15)
//         004d6520     MOV        EDI,dword ptr [EDI + 0x6c]
//         004d6523     MOV        EAX,dword ptr [ESP + numberTempLots]
//         004d6527     CMP        EDI,EAX
//         004d6529     JNZ        LAB_004d62ff
//                               LAB_004d652f                                                 XREF[2]:     004d62f9(j), 004d6301(j)
//                              taiconmd.cpp:248 (14)
//         004d652f     MOV        EAX,dword ptr [ESP + local_ac]
//         004d6533     CMP        EAX,0x2
//         004d6536     JGE        LAB_004d653d
//         004d6538     CMP        EAX,-0x1
//         004d653b     JNZ        LAB_004d6596
//                               LAB_004d653d                                                 XREF[1]:     004d6536(j)
//                              taiconmd.cpp:253 (58)
//         004d653d     MOV        EDX,dword ptr [ESP + param_4]
//         004d6544     MOV        EAX,dword ptr [ESP + param_3]
//         004d654b     MOV        this,dword ptr [ESP + param_2]
//         004d6552     PUSH       EDX
//         004d6553     PUSH       EAX=>DAT_fffffff8
//         004d6554     PUSH       offset DAT_fffffff4
//         004d6556     PUSH       offset DAT_fffffff0
//         004d6558     PUSH       -0x1
//         004d655a     PUSH       -0x1
//         004d655c     PUSH       0x0
//         004d655e     PUSH       0x0
//         004d6560     PUSH       -0x1
//         004d6562     PUSH       this
//         004d6563     MOV        this,dword ptr [EBX + 0x314]
//         004d6569     PUSH       EBP
//         004d656a     ADD        this,0xcec
//         004d6570     CALL       TribeInformationAIModule::influencePlaceStruct   ConstructionItem * influencePlaceStructure(Tr
//         004d6575     MOV        ESI,EAX
//                              taiconmd.cpp:254 (8)
//         004d6577     TEST       ESI,ESI
//         004d6579     JZ         LAB_004d6596
//         004d657b     LEA        this,[ESP + 0x3c]
//                              taiconmd.cpp:258 (23)
//         004d657f     MOV        dword ptr [ESP + 0xc4],0xffffffff
//         004d658a     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
//         004d658f     MOV        EAX,ESI
//         004d6591     JMP        LAB_004d675e
//                               LAB_004d6596                                                 XREF[2]:     004d653b(j), 004d6579(j)
//                              taiconmd.cpp:267 (12)
//         004d6596     MOV        EAX,dword ptr [ESP + 0x24]
//         004d659a     TEST       EAX,EAX
//         004d659c     JNZ        LAB_004d65c3
//         004d659e     LEA        this,[ESP + 0x3c]
//                              taiconmd.cpp:271 (10)
//         004d65a2     MOV        dword ptr [EBX + 0x310],0x5
//                              taiconmd.cpp:272 (23)
//         004d65ac     MOV        dword ptr [ESP + 0xc4],0xffffffff
//         004d65b7     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
//                               LAB_004d65bc                                                 XREF[2]:     004d6180(j), 004d61a4(j)
//         004d65bc     XOR        EAX,EAX
//         004d65be     JMP        LAB_004d675e
//                               LAB_004d65c3                                                 XREF[1]:     004d659c(j)
//                              taiconmd.cpp:283 (7)
//         004d65c3     MOV        EDI,dword ptr [ESP + 0xa8]
//                              taiconmd.cpp:285 (15)
//         004d65ca     MOV        this,EBP
//         004d65cc     MOV        ESI,dword ptr [EDI + 0x6c]
//         004d65cf     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d65d4     CMP        EAX,0x48
//         004d65d7     JNZ        LAB_004d6612
//                              taiconmd.cpp:286 (12)
//         004d65d9     LEA        EDX,[ESP + 0x3c]
//         004d65dd     CMP        ESI,EDX
//         004d65df     JZ         LAB_004d6634
//                               LAB_004d65e1                                                 XREF[1]:     004d660e(j)
//         004d65e1     TEST       ESI,ESI
//         004d65e3     JZ         LAB_004d6634
//                              taiconmd.cpp:287 (23)
//         004d65e5     MOV        this,EDI
//         004d65e7     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d65ec     MOV        this,ESI
//         004d65ee     MOV        EBP,EAX
//         004d65f0     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d65f5     ADD        EAX,0x5
//         004d65f8     CMP        EBP,EAX
//         004d65fa     JLE        LAB_004d65fe
//                              taiconmd.cpp:288 (2)
//         004d65fc     MOV        EDI,ESI
//                               LAB_004d65fe                                                 XREF[1]:     004d65fa(j)
//                              taiconmd.cpp:289 (3)
//         004d65fe     MOV        ESI,dword ptr [ESI + 0x6c]
//                              taiconmd.cpp:292 (17)
//         004d6601     MOV        EBP,dword ptr [ESP + 0xcc]
//         004d6608     LEA        EAX,[ESP + 0x3c]
//         004d660c     CMP        ESI,EAX
//         004d660e     JNZ        LAB_004d65e1
//         004d6610     JMP        LAB_004d6634
//                               LAB_004d6612                                                 XREF[1]:     004d65d7(j)
//                              taiconmd.cpp:293 (12)
//         004d6612     LEA        this,[ESP + 0x3c]
//         004d6616     CMP        ESI,this
//         004d6618     JZ         LAB_004d6634
//                               LAB_004d661a                                                 XREF[1]:     004d6632(j)
//         004d661a     TEST       ESI,ESI
//         004d661c     JZ         LAB_004d6634
//                              taiconmd.cpp:294 (9)
//         004d661e     PUSH       ESI
//         004d661f     PUSH       EDI=>DAT_fffffff8
//         004d6620     MOV        this,EBX
//         004d6622     CALL       TribeConstructionAIModule::compare               ConstructionItem * compare(TribeConstructionA
//                              taiconmd.cpp:295 (13)
//         004d6627     MOV        ESI,dword ptr [ESI + 0x6c]
//         004d662a     LEA        EDX,[ESP + 0x3c]
//         004d662e     CMP        ESI,EDX
//         004d6630     MOV        EDI,EAX
//         004d6632     JNZ        LAB_004d661a
//                               LAB_004d6634                                                 XREF[5]:     004d65df(j), 004d65e3(j),
//                                                                                                         004d6610(j), 004d6618(j),
//                                                                                                         004d661c(j)
//                              taiconmd.cpp:301 (31)
//         004d6634     MOV        this,EDI
//         004d6636     CALL       BaseItem::y                                      float y(BaseItem * this)
//         004d663b     PUSH       this
//         004d663c     MOV        this,EDI
//         004d663e     FSTP       float ptr [ESP]
//         004d6641     CALL       BaseItem::x                                      float x(BaseItem * this)
//         004d6646     PUSH       this=>DAT_fffffff8
//         004d6647     MOV        this,EBX
//         004d6649     FSTP       float ptr [ESP]=>DAT_fffffff8
//         004d664c     CALL       ConstructionAIModule::lot                        ConstructionItem * lot(ConstructionAIModule *
//         004d6651     MOV        ESI,EAX
//                              taiconmd.cpp:305 (9)
//         004d6653     PUSH       0x1
//         004d6655     MOV        this,ESI
//         004d6657     CALL       ConstructionItem::setInProgress                  void setInProgress(ConstructionItem * this, i
//                              taiconmd.cpp:306 (7)
//         004d665c     MOV        this,ESI
//         004d665e     CALL       ConstructionItem::incrementBuildAttempts         void incrementBuildAttempts(ConstructionItem
//                              taiconmd.cpp:307 (15)
//         004d6663     MOV        this,EBP
//         004d6665     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
//         004d666a     PUSH       EAX
//         004d666b     MOV        this,ESI
//         004d666d     CALL       BaseItem::setUniqueID                            void setUniqueID(BaseItem * this, int param_1)
//                              taiconmd.cpp:308 (2)
//         004d6672     XOR        EDI,EDI
//                              language.dll match for 0x80: "Arial"
//                              taiconmd.cpp:317 (45)
//         004d6674     PUSH       0x80
//         004d6679     MOV        dword ptr [EBX + 0x310],EDI
//         004d667f     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d6684     ADD        ESP,0x4
//         004d6687     MOV        dword ptr [ESP + 0x20],EAX
//         004d668b     CMP        EAX,EDI
//         004d668d     MOV        byte ptr [ESP + 0xc4],0x3
//         004d6695     JZ         LAB_004d66a1
//         004d6697     PUSH       ESI
//         004d6698     MOV        this,EAX
//         004d669a     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
//         004d669f     MOV        EDI,EAX
//                               LAB_004d66a1                                                 XREF[1]:     004d6695(j)
//                              taiconmd.cpp:319 (23)
//         004d66a1     MOV        this,EBP
//         004d66a3     MOV        byte ptr [ESP + 0xc4],0x1
//         004d66ab     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d66b0     PUSH       EAX
//         004d66b1     MOV        this,EDI
//         004d66b3     CALL       BaseItem::setTypeID                              void setTypeID(BaseItem * this, int param_1)
//                              taiconmd.cpp:324 (7)
//         004d66b8     MOV        this,dword ptr [ESP + 0xa8]
//                              taiconmd.cpp:326 (12)
//         004d66bf     LEA        EAX,[ESP + 0x3c]
//         004d66c3     CMP        this,EAX
//         004d66c5     JZ         LAB_004d66de
//                               LAB_004d66c7                                                 XREF[1]:     004d66dc(j)
//         004d66c7     TEST       this,this
//         004d66c9     JZ         LAB_004d66de
//                              taiconmd.cpp:328 (13)
//         004d66cb     MOV        EDX,dword ptr [this->_padding_]
//         004d66cd     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004d66d0     PUSH       0x1
//         004d66d2     CALL       dword ptr [EDX]
//         004d66d4     LEA        EAX,[ESP + 0x3c]
//                              taiconmd.cpp:329 (10)
//         004d66d8     MOV        this,ESI
//         004d66da     CMP        ESI,EAX
//         004d66dc     JNZ        LAB_004d66c7
//                               LAB_004d66de                                                 XREF[2]:     004d66c5(j), 004d66c9(j)
//         004d66de     LEA        this,[ESP + 0x3c]
//                              taiconmd.cpp:332 (20)
//         004d66e2     MOV        dword ptr [ESP + 0xc4],0xffffffff
//         004d66ed     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
//         004d66f2     MOV        EAX,EDI
//         004d66f4     JMP        LAB_004d675e
//                               LAB_004d66f6                                                 XREF[10]:    004d61c1(j), 004d61d1(j),
//                                                                                                         004d61e1(j), 004d61f3(j),
//                                                                                                         004d6203(j), 004d6213(j),
//                                                                                                         004d6223(j), 004d6235(j),
//                                                                                                         004d6247(j), 004d6255(j)
//                              taiconmd.cpp:153 (39)
//         004d66f6     MOV        this,dword ptr [ESP + param_4]
//         004d66fd     MOV        EDX,dword ptr [ESP + param_3]
//         004d6704     MOV        EAX,dword ptr [ESP + param_2]
//         004d670b     PUSH       this
//         004d670c     PUSH       EDX
//         004d670d     PUSH       -0x1
//         004d670f     PUSH       -0x1
//         004d6711     PUSH       -0x1
//         004d6713     PUSH       -0x1
//         004d6715     PUSH       0x0
//         004d6717     PUSH       0x0
//         004d6719     PUSH       -0x1
//         004d671b     PUSH       EAX
//         004d671c     PUSH       EBP
//                              taiconmd.cpp:154 (2)
//         004d671d     JMP        LAB_004d674d
//                               LAB_004d671f                                                 XREF[4]:     004d6116(j), 004d612d(j),
//                                                                                                         004d6144(j), 004d615b(j)
//                              taiconmd.cpp:127 (63)
//         004d671f     MOV        this,dword ptr [ESP + param_4]
//         004d6726     MOV        EDX,dword ptr [ESP + param_3]
//         004d672d     MOV        EAX,dword ptr [ESP + param_2]
//         004d6734     PUSH       this
//         004d6735     MOV        this,dword ptr [ESP + param_1]
//         004d673c     PUSH       EDX
//         004d673d     PUSH       -0x1
//         004d673f     PUSH       -0x1
//         004d6741     PUSH       -0x1
//         004d6743     PUSH       -0x1
//         004d6745     PUSH       0x0
//         004d6747     PUSH       0x0
//         004d6749     PUSH       -0x1
//         004d674b     PUSH       EAX
//         004d674c     PUSH       this
//                               LAB_004d674d                                                 XREF[1]:     004d671d(j)
//         004d674d     MOV        this,dword ptr [EBX + 0x314]
//         004d6753     ADD        this,0xcec
//         004d6759     CALL       TribeInformationAIModule::influencePlaceStruct   ConstructionItem * influencePlaceStructure(Tr
//                               LAB_004d675e                                                 XREF[5]:     004d61b2(j), 004d6280(j),
//                                                                                                         004d6591(j), 004d65be(j),
//                                                                                                         004d66f4(j)
//                              taiconmd.cpp:333 (27)
//         004d675e     MOV        this,dword ptr [ESP + local_c]
//         004d6765     POP        EDI
//         004d6766     POP        ESI
//         004d6767     POP        EBP
//         004d6768     MOV        dword ptr FS:[0x0],this
//         004d676f     POP        EBX
//         004d6770     ADD        ESP,0xb8
//         004d6776     RET        0x10
//         004d6779     ??         90h
//         004d677a     NOP
//         004d677b     NOP
//         004d677c     NOP
//         004d677d     NOP
//         004d677e     NOP
//         004d677f     NOP
    return 0;
}

ConstructionItem* TribeConstructionAIModule::placeDock(BuildItem* param_1) {
    /* TODO: Stub */
//                              ConstructionItem * __thiscall placeDock(TribeConstructionAIModule *
//              ConstructionIt    EAX:4          <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004d6781(R)
//                               ?placeDock@TribeConstructionAIModule@@QAEPAVConstructionIte  XREF[1]:     placeStructure:004d6177(c)
//                               TribeConstructionAIModule::placeDock
//                              taiconmd.cpp:338 (1)
//         004d6780     PUSH       ESI
//                              taiconmd.cpp:342 (42)
//         004d6781     MOV        EDX,dword ptr [ESP + param_1]
//         004d6785     MOV        ESI,this
//         004d6787     PUSH       0x2
//         004d6789     PUSH       0x1
//         004d678b     MOV        EAX,dword ptr [ESI + 0x300]
//         004d6791     MOV        this,dword ptr [ESI + 0x2fc]
//         004d6797     PUSH       EAX
//         004d6798     PUSH       this
//         004d6799     MOV        this,dword ptr [ESI + 0x314]
//         004d679f     PUSH       EDX
//         004d67a0     ADD        this,0xcec
//         004d67a6     CALL       TribeInformationAIModule::placeDock              ConstructionItem * placeDock(TribeInformation
//                              taiconmd.cpp:344 (4)
//         004d67ab     TEST       EAX,EAX
//         004d67ad     JZ         LAB_004d67e5
//                              taiconmd.cpp:345 (9)
//         004d67af     LEA        this,[ESI + 0x178]
//         004d67b5     MOV        dword ptr [EAX + 0x6c],this
//                              taiconmd.cpp:346 (9)
//         004d67b8     MOV        this,dword ptr [ESI + 0x1e8]
//         004d67be     MOV        dword ptr [EAX + 0x70],this
//                              taiconmd.cpp:347 (3)
//         004d67c1     MOV        dword ptr [ECX + this->_padding_],EAX
//                              taiconmd.cpp:349 (19)
//         004d67c4     MOV        this,dword ptr [ESI + 0x174]
//         004d67ca     INC        this
//         004d67cb     MOV        dword ptr [ESI + 0x1e8],EAX
//         004d67d1     MOV        dword ptr [ESI + 0x174],this
//                              taiconmd.cpp:350 (10)
//         004d67d7     MOV        dword ptr [ESI + 0x310],0x0
//                              taiconmd.cpp:358 (4)
//         004d67e1     POP        ESI
//         004d67e2     RET        0x4
//                               LAB_004d67e5                                                 XREF[1]:     004d67ad(j)
//                              taiconmd.cpp:356 (10)
//         004d67e5     MOV        dword ptr [ESI + 0x310],0x5
//                              taiconmd.cpp:357 (2)
//         004d67ef     XOR        EAX,EAX
//                              taiconmd.cpp:358 (4)
//         004d67f1     POP        ESI
//         004d67f2     RET        0x4
//         004d67f5     ??         90h
//         004d67f6     NOP
//         004d67f7     NOP
//         004d67f8     NOP
//         004d67f9     NOP
//         004d67fa     NOP
//         004d67fb     NOP
//         004d67fc     NOP
//         004d67fd     NOP
//         004d67fe     NOP
//         004d67ff     NOP
    return 0;
}

void TribeConstructionAIModule::setBuilt(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setBuilt(TribeConstructionAIModule * this, RGE_Stati
//              void              <VOID>         <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d6806(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004d688d(R)
//                               ?setBuilt@TribeConstructionAIModule@@QAEXPAVRGE_Static_Obje  XREF[1]:     addItem:004d50bf(c)
//                               TribeConstructionAIModule::setBuilt
//                              taiconmd.cpp:363 (6)
//         004d6800     PUSH       EBX
//         004d6801     PUSH       EBP
//         004d6802     MOV        EBP,this
//         004d6804     PUSH       ESI
//         004d6805     PUSH       EDI
//                              taiconmd.cpp:366 (24)
//         004d6806     MOV        EDI,dword ptr [ESP + param_1]
//         004d680a     MOV        ESI,dword ptr [EBP + 0x160]
//         004d6810     LEA        EBX,[EBP + 0xf4]
//         004d6816     CMP        ESI,EBX
//         004d6818     JZ         LAB_004d6859
//                               LAB_004d681a                                                 XREF[1]:     004d6857(j)
//         004d681a     TEST       ESI,ESI
//         004d681c     JZ         LAB_004d6859
//                              taiconmd.cpp:369 (52)
//         004d681e     MOV        this,ESI
//         004d6820     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         004d6825     MOV        this,dword ptr [EDI + 0x8]
//         004d6828     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         004d682c     CMP        EAX,EDX
//         004d682e     JNZ        LAB_004d6852
//         004d6830     MOV        this,ESI
//         004d6832     CALL       BaseItem::x                                      float x(BaseItem * this)
//         004d6837     FCOMP      float ptr [EDI + 0x38]
//         004d683a     FNSTSW     AX
//         004d683c     TEST       AH,0x40
//         004d683f     JZ         LAB_004d6852
//         004d6841     MOV        this,ESI
//         004d6843     CALL       BaseItem::y                                      float y(BaseItem * this)
//         004d6848     FCOMP      float ptr [EDI + 0x3c]
//         004d684b     FNSTSW     AX
//         004d684d     TEST       AH,0x40
//         004d6850     JNZ        LAB_004d688d
//                               LAB_004d6852                                                 XREF[2]:     004d682e(j), 004d683f(j)
//                              taiconmd.cpp:373 (7)
//         004d6852     MOV        ESI,dword ptr [ESI + 0x6c]
//         004d6855     CMP        ESI,EBX
//         004d6857     JNZ        LAB_004d681a
//                               LAB_004d6859                                                 XREF[2]:     004d6818(j), 004d681c(j)
//                              taiconmd.cpp:378 (45)
//         004d6859     FLD        float ptr [EDI + 0x3c]
//         004d685c     PUSH       0x1
//         004d685e     CALL       __ftol                                           undefined __ftol()
//         004d6863     FLD        float ptr [EDI + 0x38]
//         004d6866     PUSH       EAX
//         004d6867     CALL       __ftol                                           undefined __ftol()
//         004d686c     MOV        this,dword ptr [EDI + 0x8]
//         004d686f     PUSH       EAX
//         004d6870     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         004d6874     MOV        this,dword ptr [EBP + 0x314]
//         004d687a     PUSH       EDX
//         004d687b     ADD        this,0xcec
//         004d6881     CALL       TribeInformationAIModule::storeLot               void storeLot(TribeInformationAIModule * this
//                              taiconmd.cpp:379 (7)
//         004d6886     POP        EDI
//         004d6887     POP        ESI
//         004d6888     POP        EBP
//         004d6889     POP        EBX
//         004d688a     RET        0x8
//                               LAB_004d688d                                                 XREF[1]:     004d6850(j)
//                              taiconmd.cpp:370 (12)
//         004d688d     MOV        EAX,dword ptr [ESP + param_2]
//         004d6891     MOV        this,ESI
//         004d6893     PUSH       EAX
//         004d6894     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
//                              taiconmd.cpp:379 (7)
//         004d6899     POP        EDI
//         004d689a     POP        ESI
//         004d689b     POP        EBP
//         004d689c     POP        EBX
//         004d689d     RET        0x8
    return;
}

ConstructionItem* TribeConstructionAIModule::compare(ConstructionItem* param_1, ConstructionItem* param_2) {
    /* TODO: Stub */
//                              ConstructionItem * __thiscall compare(TribeConstructionAIModule * th
//              ConstructionIt    EAX:4          <RETURN>
//              TribeConstruct    ECX:4 (auto)   this
//              ConstructionIt    Stack[0x4]:4   param_1                   XREF[1]:     004d68a2(R)
//              ConstructionIt    Stack[0x8]:4   param_2                   XREF[1]:     004d68ae(R)
//                               ?compare@TribeConstructionAIModule@@IAEPAVConstructionItem@  XREF[1]:     placeStructure:004d6622(c)
//                               TribeConstructionAIModule::compare
//                              taiconmd.cpp:385 (2)
//         004d68a0     PUSH       EBX
//         004d68a1     PUSH       ESI
//                              taiconmd.cpp:386 (27)
//         004d68a2     MOV        ESI,dword ptr [ESP + param_1]
//         004d68a6     PUSH       EDI
//         004d68a7     MOV        this,ESI
//         004d68a9     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d68ae     MOV        EDI,dword ptr [ESP + param_2]
//         004d68b2     MOV        EBX,EAX
//         004d68b4     MOV        this,EDI
//         004d68b6     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
//         004d68bb     CMP        EBX,EAX
//                              taiconmd.cpp:387 (4)
//         004d68bd     MOV        EAX,EDI
//         004d68bf     JG         LAB_004d68c3
//                              taiconmd.cpp:388 (2)
//         004d68c1     MOV        EAX,ESI
//                               LAB_004d68c3                                                 XREF[1]:     004d68bf(j)
//                              taiconmd.cpp:389 (6)
//         004d68c3     POP        EDI
//         004d68c4     POP        ESI
//         004d68c5     POP        EBX
//         004d68c6     RET        0x8
//         004d68c9     ??         90h
//         004d68ca     NOP
//         004d68cb     NOP
//         004d68cc     NOP
//         004d68cd     NOP
//         004d68ce     NOP
//         004d68cf     NOP
    return 0;
}

