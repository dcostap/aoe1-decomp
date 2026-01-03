#include "../common.h"
#include "aiconitm.h"

ConstructionItem::ConstructionItem() {
    /* TODO: Stub */
//                              undefined __thiscall ConstructionItem(ConstructionItem * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ??0ConstructionItem@@QAE@XZ                                  XREF[6]:     ConstructionAIModule:0040aadf(c),
//                               ConstructionItem::ConstructionItem                                        ConstructionAIModule:0040aaf7(c),
//                                                                                                         ConstructionAIModule:0040ac0d(c),
//                                                                                                         ConstructionAIModule:0040ac2c(c),
//                                                                                                         canPlace:004d5fb9(c),
//                                                                                                         placeStructure:004d62b5(c)
//                              aiconitm.cpp:26 (31)
//         0040a820     PUSH       ESI
//         0040a821     MOV        ESI,this
//         0040a823     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this)
//         0040a828     XOR        EAX,EAX
//         0040a82a     MOV        dword ptr [ESI],ConstructionItem::`vftable'      = 0040a850
//         0040a830     MOV        dword ptr [ESI + 0x6c],EAX
//         0040a833     MOV        dword ptr [ESI + 0x70],EAX
//         0040a836     MOV        dword ptr [ESI + 0x74],EAX
//         0040a839     MOV        dword ptr [ESI + 0x78],EAX
//         0040a83c     MOV        dword ptr [ESI + 0x7c],EAX
//                              aiconitm.cpp:27 (4)
//         0040a83f     MOV        EAX,ESI
//         0040a841     POP        ESI
//         0040a842     RET
//         0040a843     ??         90h
//         0040a844     NOP
//         0040a845     NOP
//         0040a846     NOP
//         0040a847     NOP
//         0040a848     NOP
//         0040a849     NOP
//         0040a84a     NOP
//         0040a84b     NOP
//         0040a84c     NOP
//         0040a84d     NOP
//         0040a84e     NOP
//         0040a84f     NOP
}

ConstructionItem::ConstructionItem(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7, char* param_8) {
    /* TODO: Stub */
//                              undefined __thiscall ConstructionItem(ConstructionItem * this, float
//              undefined         <UNASSIGNED>   <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a88a(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0040a885(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0040a880(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0040a874(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0040a87b(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     0040a870(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0040a894(R)
//              char *            Stack[0x20]:4  param_8                   XREF[1]:     0040a88f(R)
//                               ??0ConstructionItem@@QAE@MMMMMMHPAD@Z                        XREF[8]:     ConstructionAIModule:0040ae86(c),
//                               ConstructionItem::ConstructionItem                                        ConstructionAIModule:0040b071(c),
//                                                                                                         loadConstructionPlan:0040b89d(c),
//                                                                                                         placeDock:004d9e96(c),
//                                                                                                         influencePlaceStructure:004db774(c
//                                                                                                         influencePlaceStructure:004db7f0(c
//                                                                                                         influencePlaceStructure:004dc00b(c
//                                                                                                         influencePlaceStructure:004dc068(c
//                              aiconitm.cpp:39 (77)
//         0040a870     MOV        EAX,dword ptr [ESP + param_6]
//         0040a874     MOV        EDX,dword ptr [ESP + param_4]
//         0040a878     PUSH       ESI
//         0040a879     MOV        ESI,this
//         0040a87b     MOV        this,dword ptr [ESP + param_5]
//         0040a87f     PUSH       EAX
//         0040a880     MOV        EAX,dword ptr [ESP + param_3]
//         0040a884     PUSH       this
//         0040a885     MOV        this,dword ptr [ESP + param_2]
//         0040a889     PUSH       EDX
//         0040a88a     MOV        EDX,dword ptr [ESP + param_1]
//         0040a88e     PUSH       EAX
//         0040a88f     MOV        EAX,dword ptr [ESP + param_8]
//         0040a893     PUSH       this
//         0040a894     MOV        this,dword ptr [ESP + param_7]
//         0040a898     PUSH       EDX
//         0040a899     PUSH       EAX
//         0040a89a     PUSH       -0x1
//         0040a89c     PUSH       -0x1
//         0040a89e     PUSH       this
//         0040a89f     MOV        this,ESI
//         0040a8a1     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, int param
//         0040a8a6     XOR        EAX,EAX
//         0040a8a8     MOV        dword ptr [ESI],ConstructionItem::`vftable'      = 0040a850
//         0040a8ae     MOV        dword ptr [ESI + 0x6c],EAX
//         0040a8b1     MOV        dword ptr [ESI + 0x70],EAX
//         0040a8b4     MOV        dword ptr [ESI + 0x74],EAX
//         0040a8b7     MOV        dword ptr [ESI + 0x78],EAX
//         0040a8ba     MOV        dword ptr [ESI + 0x7c],EAX
//                              aiconitm.cpp:40 (6)
//         0040a8bd     MOV        EAX,ESI
//         0040a8bf     POP        ESI
//         0040a8c0     RET        0x20
//         0040a8c3     ??         90h
//         0040a8c4     NOP
//         0040a8c5     NOP
//         0040a8c6     NOP
//         0040a8c7     NOP
//         0040a8c8     NOP
//         0040a8c9     NOP
//         0040a8ca     NOP
//         0040a8cb     NOP
//         0040a8cc     NOP
//         0040a8cd     NOP
//         0040a8ce     NOP
//         0040a8cf     NOP
}

ConstructionItem::ConstructionItem(ConstructionItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall ConstructionItem(ConstructionItem * this, Const
//              undefined         <UNASSIGNED>   <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              ConstructionIt    Stack[0x4]:4   param_1                   XREF[1]:     0040a8d2(R)
//                               ??0ConstructionItem@@QAE@PAV0@@Z                             XREF[3]:     placeStructure:004d61ad(c),
//                               ConstructionItem::ConstructionItem                                        placeStructure:004d64ba(c),
//                                                                                                         placeStructure:004d669a(c)
//                              aiconitm.cpp:51 (46)
//         0040a8d0     PUSH       ESI
//         0040a8d1     PUSH       EDI
//         0040a8d2     MOV        EDI,dword ptr [ESP + param_1]
//         0040a8d6     MOV        ESI,this
//         0040a8d8     PUSH       EDI
//         0040a8d9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         0040a8de     XOR        EAX,EAX
//         0040a8e0     MOV        dword ptr [ESI + 0x6c],EAX
//         0040a8e3     MOV        dword ptr [ESI + 0x70],EAX
//         0040a8e6     MOV        EAX,dword ptr [EDI + 0x74]
//         0040a8e9     MOV        dword ptr [ESI + 0x74],EAX
//         0040a8ec     MOV        this,dword ptr [EDI + 0x78]
//         0040a8ef     MOV        dword ptr [ESI + 0x78],this
//         0040a8f2     MOV        EDX,dword ptr [EDI + 0x7c]
//         0040a8f5     MOV        dword ptr [ESI + 0x7c],EDX
//         0040a8f8     MOV        dword ptr [ESI],ConstructionItem::`vftable'      = 0040a850
//                              aiconitm.cpp:52 (7)
//         0040a8fe     MOV        EAX,ESI
//         0040a900     POP        EDI
//         0040a901     POP        ESI
//         0040a902     RET        0x4
//         0040a905     ??         90h
//         0040a906     NOP
//         0040a907     NOP
//         0040a908     NOP
//         0040a909     NOP
//         0040a90a     NOP
//         0040a90b     NOP
//         0040a90c     NOP
//         0040a90d     NOP
//         0040a90e     NOP
//         0040a90f     NOP
}

ConstructionItem::ConstructionItem(ConstructionItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall ConstructionItem(ConstructionItem * this, Const
//              undefined         <UNASSIGNED>   <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              ConstructionIt    Stack[0x4]:4   param_1                   XREF[1]:     0040a912(R)
//                               ??0ConstructionItem@@QAE@ABV0@@Z
//                               ConstructionItem::ConstructionItem
//                              aiconitm.cpp:63 (46)
//         0040a910     PUSH       ESI
//         0040a911     PUSH       EDI
//         0040a912     MOV        EDI,dword ptr [ESP + param_1]
//         0040a916     MOV        ESI,this
//         0040a918     PUSH       EDI
//         0040a919     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         0040a91e     XOR        EAX,EAX
//         0040a920     MOV        dword ptr [ESI + 0x6c],EAX
//         0040a923     MOV        dword ptr [ESI + 0x70],EAX
//         0040a926     MOV        EAX,dword ptr [EDI + 0x74]
//         0040a929     MOV        dword ptr [ESI + 0x74],EAX
//         0040a92c     MOV        this,dword ptr [EDI + 0x78]
//         0040a92f     MOV        dword ptr [ESI + 0x78],this
//         0040a932     MOV        EDX,dword ptr [EDI + 0x7c]
//         0040a935     MOV        dword ptr [ESI + 0x7c],EDX
//         0040a938     MOV        dword ptr [ESI],ConstructionItem::`vftable'      = 0040a850
//                              aiconitm.cpp:64 (7)
//         0040a93e     MOV        EAX,ESI
//         0040a940     POP        EDI
//         0040a941     POP        ESI
//         0040a942     RET        0x4
//         0040a945     ??         90h
//         0040a946     NOP
//         0040a947     NOP
//         0040a948     NOP
//         0040a949     NOP
//         0040a94a     NOP
//         0040a94b     NOP
//         0040a94c     NOP
//         0040a94d     NOP
//         0040a94e     NOP
//         0040a94f     NOP
}

ConstructionItem::~ConstructionItem() {
    /* TODO: Stub */
//                              void __thiscall ~ConstructionItem(ConstructionItem * this)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ??1ConstructionItem@@UAE@XZ                                  XREF[10]:    `scalar_deleting_destructor':0040a
//                               ConstructionItem::~ConstructionItem                                       ~ConstructionAIModule:0040b165(c),
//                                                                                                         ~ConstructionAIModule:0040b175(c),
//                                                                                                         canPlace:004d6079(c),
//                                                                                                         canPlace:004d6091(c),
//                                                                                                         placeStructure:004d658a(c),
//                                                                                                         placeStructure:004d65b7(c),
//                                                                                                         placeStructure:004d66ed(c),
//                                                                                                         FUN_0055c54b:0055c557(c),
//                                                                                                         FUN_0055c55c:0055c568(c)
//                              aiconitm.cpp:69 (11)
//         0040a950     MOV        dword ptr [this->_padding_],ConstructionItem::   = 0040a850
//         0040a956     JMP        BaseItem::~BaseItem                              void ~BaseItem(BaseItem * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0040a95b     ??         90h
//         0040a95c     NOP
//         0040a95d     NOP
//         0040a95e     NOP
//         0040a95f     NOP
}

int ConstructionItem::inProgress() {
    /* TODO: Stub */
//                              int __thiscall inProgress(ConstructionItem * this)
//              int               EAX:4          <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ?inProgress@ConstructionItem@@QBEHXZ                         XREF[4]:     save:0040b41c(c),
//                               ConstructionItem::inProgress                                              save:0040b61f(c),
//                                                                                                         canPlace:004d605a(c),
//                                                                                                         placeStructure:004d637f(c)
//                              aiconitm.cpp:113 (3)
//         0040aa00     MOV        EAX,dword ptr [ECX + this->inProgressValue]
//                              aiconitm.cpp:115 (1)
//         0040aa03     RET
//         0040aa04     ??         90h
//         0040aa05     NOP
//         0040aa06     NOP
//         0040aa07     NOP
//         0040aa08     NOP
//         0040aa09     NOP
//         0040aa0a     NOP
//         0040aa0b     NOP
//         0040aa0c     NOP
//         0040aa0d     NOP
//         0040aa0e     NOP
//         0040aa0f     NOP
    return 0;
}

int ConstructionItem::built() {
    /* TODO: Stub */
//                              int __thiscall built(ConstructionItem * this)
//              int               EAX:4          <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ?built@ConstructionItem@@QBEHXZ                              XREF[4]:     save:0040b437(c),
//                               ConstructionItem::built                                                   save:0040b63a(c),
//                                                                                                         canPlace:004d604f(c),
//                                                                                                         placeStructure:004d636f(c)
//                              aiconitm.cpp:120 (3)
//         0040aa10     MOV        EAX,dword ptr [ECX + this->builtValue]
//                              aiconitm.cpp:122 (1)
//         0040aa13     RET
//         0040aa14     ??         90h
//         0040aa15     NOP
//         0040aa16     NOP
//         0040aa17     NOP
//         0040aa18     NOP
//         0040aa19     NOP
//         0040aa1a     NOP
//         0040aa1b     NOP
//         0040aa1c     NOP
//         0040aa1d     NOP
//         0040aa1e     NOP
//         0040aa1f     NOP
    return 0;
}

int ConstructionItem::buildAttempts() {
    /* TODO: Stub */
//                              int __thiscall buildAttempts(ConstructionItem * this)
//              int               EAX:4          <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ?buildAttempts@ConstructionItem@@QBEHXZ                      XREF[8]:     save:0040b452(c),
//                               ConstructionItem::buildAttempts                                           save:0040b655(c),
//                                                                                                         placeStructure:004d6501(c),
//                                                                                                         placeStructure:004d650c(c),
//                                                                                                         placeStructure:004d65e7(c),
//                                                                                                         placeStructure:004d65f0(c),
//                                                                                                         compare:004d68a9(c),
//                                                                                                         compare:004d68b6(c)
//                              aiconitm.cpp:127 (3)
//         0040aa20     MOV        EAX,dword ptr [ECX + this->buildAttemptsValue]
//                              aiconitm.cpp:129 (1)
//         0040aa23     RET
//         0040aa24     ??         90h
//         0040aa25     NOP
//         0040aa26     NOP
//         0040aa27     NOP
//         0040aa28     NOP
//         0040aa29     NOP
//         0040aa2a     NOP
//         0040aa2b     NOP
//         0040aa2c     NOP
//         0040aa2d     NOP
//         0040aa2e     NOP
//         0040aa2f     NOP
    return 0;
}

void ConstructionItem::setInProgress(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setInProgress(ConstructionItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040aa30(R)
//                               ?setInProgress@ConstructionItem@@QAEXH@Z                     XREF[5]:     ConstructionAIModule:0040aea0(c),
//                               ConstructionItem::setInProgress                                           ConstructionAIModule:0040b08b(c),
//                                                                                                         unplaceStructure:0040bc3d(c),
//                                                                                                         unplaceStructure:0040bccd(c),
//                                                                                                         placeStructure:004d6657(c)
//                              aiconitm.cpp:134 (7)
//         0040aa30     MOV        EAX,dword ptr [ESP + param_1]
//         0040aa34     MOV        dword ptr [ECX + this->inProgressValue],EAX
//                              aiconitm.cpp:136 (3)
//         0040aa37     RET        0x4
//         0040aa3a     ??         90h
//         0040aa3b     NOP
//         0040aa3c     NOP
//         0040aa3d     NOP
//         0040aa3e     NOP
//         0040aa3f     NOP
    return;
}

void ConstructionItem::setBuilt(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setBuilt(ConstructionItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040aa40(R)
//                               ?setBuilt@ConstructionItem@@QAEXH@Z                          XREF[6]:     ConstructionAIModule:0040aeac(c),
//                               ConstructionItem::setBuilt                                                ConstructionAIModule:0040b097(c),
//                                                                                                         setBuilt:0040bbed(c),
//                                                                                                         unplaceStructure:0040bc46(c),
//                                                                                                         unplaceStructure:0040bcd6(c),
//                                                                                                         setBuilt:004d6894(c)
//                              aiconitm.cpp:141 (7)
//         0040aa40     MOV        EAX,dword ptr [ESP + param_1]
//         0040aa44     MOV        dword ptr [ECX + this->builtValue],EAX
//                              aiconitm.cpp:143 (3)
//         0040aa47     RET        0x4
//         0040aa4a     ??         90h
//         0040aa4b     NOP
//         0040aa4c     NOP
//         0040aa4d     NOP
//         0040aa4e     NOP
//         0040aa4f     NOP
    return;
}

void ConstructionItem::incrementBuildAttempts() {
    /* TODO: Stub */
//                              void __thiscall incrementBuildAttempts(ConstructionItem * this)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ?incrementBuildAttempts@ConstructionItem@@QAEXXZ             XREF[2]:     incrementBuildAttempts:0040bd61(c)
//                               ConstructionItem::incrementBuildAttempts                                  placeStructure:004d665e(c)
//                              aiconitm.cpp:148 (3)
//         0040aa50     INC        dword ptr [ECX + this->buildAttemptsValue]
//                              aiconitm.cpp:150 (1)
//         0040aa53     RET
//         0040aa54     ??         90h
//         0040aa55     NOP
//         0040aa56     NOP
//         0040aa57     NOP
//         0040aa58     NOP
//         0040aa59     NOP
//         0040aa5a     NOP
//         0040aa5b     NOP
//         0040aa5c     NOP
//         0040aa5d     NOP
//         0040aa5e     NOP
//         0040aa5f     NOP
    return;
}

void ConstructionItem::decrementBuildAttempts() {
    /* TODO: Stub */
//                              void __thiscall decrementBuildAttempts(ConstructionItem * this)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//                               ?decrementBuildAttempts@ConstructionItem@@QAEXXZ             XREF[3]:     unplaceStructure:0040bc66(c),
//                               ConstructionItem::decrementBuildAttempts                                  unplaceStructure:0040bcf6(c),
//                                                                                                         decrementBuildAttempts:0040bd31(c)
//                              aiconitm.cpp:155 (7)
//         0040aa60     MOV        EAX,dword ptr [ECX + this->buildAttemptsValue]
//         0040aa63     DEC        EAX
//         0040aa64     MOV        dword ptr [ECX + this->buildAttemptsValue],EAX
//                              aiconitm.cpp:157 (2)
//         0040aa67     JNS        LAB_0040aa70
//                              aiconitm.cpp:158 (7)
//         0040aa69     MOV        dword ptr [ECX + this->buildAttemptsValue],0x0
//                               LAB_0040aa70                                                 XREF[1]:     0040aa67(j)
//                              aiconitm.cpp:159 (1)
//         0040aa70     RET
//         0040aa71     ??         90h
//         0040aa72     NOP
//         0040aa73     NOP
//         0040aa74     NOP
//         0040aa75     NOP
//         0040aa76     NOP
//         0040aa77     NOP
//         0040aa78     NOP
//         0040aa79     NOP
//         0040aa7a     NOP
//         0040aa7b     NOP
//         0040aa7c     NOP
//         0040aa7d     NOP
//         0040aa7e     NOP
//         0040aa7f     NOP
    return;
}

void ConstructionItem::setBuildAttempts(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setBuildAttempts(ConstructionItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              ConstructionIt    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040aa80(R)
//                               ?setBuildAttempts@ConstructionItem@@QAEXH@Z                  XREF[2]:     ConstructionAIModule:0040aeb8(c),
//                               ConstructionItem::setBuildAttempts                                        ConstructionAIModule:0040b0a3(c)
//                              aiconitm.cpp:164 (7)
//         0040aa80     MOV        EAX,dword ptr [ESP + param_1]
//         0040aa84     MOV        dword ptr [ECX + this->buildAttemptsValue],EAX
//                              aiconitm.cpp:166 (3)
//         0040aa87     RET        0x4
//         0040aa8a     ??         90h
//         0040aa8b     NOP
//         0040aa8c     NOP
//         0040aa8d     NOP
//         0040aa8e     NOP
//         0040aa8f     NOP
    return;
}

