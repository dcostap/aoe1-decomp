#include "../common.h"
#include "aibitm.h"

BaseItem::BaseItem() {
    /* TODO: Stub */
//                              undefined __thiscall BaseItem(BaseItem * this, BaseItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              BaseItem *        Stack[0x4]:4   param_1                   XREF[1]:     00407ef0(R)
//                               ??0BaseItem@@QAE@ABV0@@Z                                     XREF[2]:     BuildItem:004083b9(c),
//                               BaseItem::BaseItem                                                        ConstructionItem:0040a919(c)
//                              aibitm.cpp:82 (69)
//         00407ef0     MOV        EAX,dword ptr [ESP + param_1]
//         00407ef4     MOV        EDX,this
//         00407ef6     PUSH       EBX
//         00407ef7     PUSH       ESI
//         00407ef8     MOV        this,dword ptr [EAX + 0x4]
//         00407efb     PUSH       EDI
//         00407efc     MOV        dword ptr [EDX + 0x4],this
//         00407eff     MOV        this,dword ptr [EAX + 0x8]
//         00407f02     MOV        dword ptr [EDX + 0x8],this
//         00407f05     MOV        this,dword ptr [EAX + 0xc]
//         00407f08     MOV        dword ptr [EDX + 0xc],this
//         00407f0b     MOV        this,dword ptr [EAX + 0x50]
//         00407f0e     MOV        dword ptr [EDX + 0x50],this
//         00407f11     MOV        this,dword ptr [EAX + 0x54]
//         00407f14     MOV        dword ptr [EDX + 0x54],this
//         00407f17     MOV        this,dword ptr [EAX + 0x58]
//         00407f1a     MOV        dword ptr [EDX + 0x58],this
//         00407f1d     MOV        this,dword ptr [EAX + 0x5c]
//         00407f20     MOV        dword ptr [EDX + 0x5c],this
//         00407f23     MOV        this,dword ptr [EAX + 0x60]
//         00407f26     MOV        dword ptr [EDX + 0x60],this
//         00407f29     MOV        this,dword ptr [EAX + 0x64]
//         00407f2c     MOV        dword ptr [EDX + 0x64],this
//         00407f2f     MOV        this,dword ptr [EAX + 0x68]
//         00407f32     MOV        dword ptr [EDX + 0x68],this
//                              aibitm.cpp:83 (36)
//         00407f35     LEA        EDI,[EAX + 0x10]
//         00407f38     OR         this,0xffffffff
//         00407f3b     XOR        EAX,EAX
//         00407f3d     MOV        dword ptr [EDX],BaseItem::`vftable'              = 00407de0
//         00407f43     LEA        EBX,[EDX + 0x10]
//         00407f46     SCASB.RE   ES:EDI
//         00407f48     NOT        this
//         00407f4a     SUB        EDI,this
//         00407f4c     MOV        EAX,this
//         00407f4e     MOV        ESI,EDI
//         00407f50     MOV        EDI,EBX
//         00407f52     SHR        this,0x2
//         00407f55     MOVSD.REP  ES:EDI,ESI
//         00407f57     MOV        this,EAX
//                              aibitm.cpp:84 (13)
//         00407f59     MOV        EAX,EDX
//         00407f5b     AND        this,0x3
//         00407f5e     MOVSB.REP  ES:EDI,ESI
//         00407f60     POP        EDI
//         00407f61     POP        ESI
//         00407f62     POP        EBX
//         00407f63     RET        0x4
//         00407f66     ??         90h
//         00407f67     NOP
//         00407f68     NOP
//         00407f69     NOP
//         00407f6a     NOP
//         00407f6b     NOP
//         00407f6c     NOP
//         00407f6d     NOP
//         00407f6e     NOP
//         00407f6f     NOP
}

BaseItem::BaseItem(int param_1, int param_2, int param_3, char* param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10) {
    /* TODO: Stub */
//                              undefined __thiscall BaseItem(BaseItem * this, BaseItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              BaseItem *        Stack[0x4]:4   param_1                   XREF[1]:     00407ef0(R)
//                               ??0BaseItem@@QAE@ABV0@@Z                                     XREF[2]:     BuildItem:004083b9(c),
//                               BaseItem::BaseItem                                                        ConstructionItem:0040a919(c)
//                              aibitm.cpp:82 (69)
//         00407ef0     MOV        EAX,dword ptr [ESP + param_1]
//         00407ef4     MOV        EDX,this
//         00407ef6     PUSH       EBX
//         00407ef7     PUSH       ESI
//         00407ef8     MOV        this,dword ptr [EAX + 0x4]
//         00407efb     PUSH       EDI
//         00407efc     MOV        dword ptr [EDX + 0x4],this
//         00407eff     MOV        this,dword ptr [EAX + 0x8]
//         00407f02     MOV        dword ptr [EDX + 0x8],this
//         00407f05     MOV        this,dword ptr [EAX + 0xc]
//         00407f08     MOV        dword ptr [EDX + 0xc],this
//         00407f0b     MOV        this,dword ptr [EAX + 0x50]
//         00407f0e     MOV        dword ptr [EDX + 0x50],this
//         00407f11     MOV        this,dword ptr [EAX + 0x54]
//         00407f14     MOV        dword ptr [EDX + 0x54],this
//         00407f17     MOV        this,dword ptr [EAX + 0x58]
//         00407f1a     MOV        dword ptr [EDX + 0x58],this
//         00407f1d     MOV        this,dword ptr [EAX + 0x5c]
//         00407f20     MOV        dword ptr [EDX + 0x5c],this
//         00407f23     MOV        this,dword ptr [EAX + 0x60]
//         00407f26     MOV        dword ptr [EDX + 0x60],this
//         00407f29     MOV        this,dword ptr [EAX + 0x64]
//         00407f2c     MOV        dword ptr [EDX + 0x64],this
//         00407f2f     MOV        this,dword ptr [EAX + 0x68]
//         00407f32     MOV        dword ptr [EDX + 0x68],this
//                              aibitm.cpp:83 (36)
//         00407f35     LEA        EDI,[EAX + 0x10]
//         00407f38     OR         this,0xffffffff
//         00407f3b     XOR        EAX,EAX
//         00407f3d     MOV        dword ptr [EDX],BaseItem::`vftable'              = 00407de0
//         00407f43     LEA        EBX,[EDX + 0x10]
//         00407f46     SCASB.RE   ES:EDI
//         00407f48     NOT        this
//         00407f4a     SUB        EDI,this
//         00407f4c     MOV        EAX,this
//         00407f4e     MOV        ESI,EDI
//         00407f50     MOV        EDI,EBX
//         00407f52     SHR        this,0x2
//         00407f55     MOVSD.REP  ES:EDI,ESI
//         00407f57     MOV        this,EAX
//                              aibitm.cpp:84 (13)
//         00407f59     MOV        EAX,EDX
//         00407f5b     AND        this,0x3
//         00407f5e     MOVSB.REP  ES:EDI,ESI
//         00407f60     POP        EDI
//         00407f61     POP        ESI
//         00407f62     POP        EBX
//         00407f63     RET        0x4
//         00407f66     ??         90h
//         00407f67     NOP
//         00407f68     NOP
//         00407f69     NOP
//         00407f6a     NOP
//         00407f6b     NOP
//         00407f6c     NOP
//         00407f6d     NOP
//         00407f6e     NOP
//         00407f6f     NOP
}

BaseItem::BaseItem(BaseItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall BaseItem(BaseItem * this, BaseItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              BaseItem *        Stack[0x4]:4   param_1                   XREF[1]:     00407ef0(R)
//                               ??0BaseItem@@QAE@ABV0@@Z                                     XREF[2]:     BuildItem:004083b9(c),
//                               BaseItem::BaseItem                                                        ConstructionItem:0040a919(c)
//                              aibitm.cpp:82 (69)
//         00407ef0     MOV        EAX,dword ptr [ESP + param_1]
//         00407ef4     MOV        EDX,this
//         00407ef6     PUSH       EBX
//         00407ef7     PUSH       ESI
//         00407ef8     MOV        this,dword ptr [EAX + 0x4]
//         00407efb     PUSH       EDI
//         00407efc     MOV        dword ptr [EDX + 0x4],this
//         00407eff     MOV        this,dword ptr [EAX + 0x8]
//         00407f02     MOV        dword ptr [EDX + 0x8],this
//         00407f05     MOV        this,dword ptr [EAX + 0xc]
//         00407f08     MOV        dword ptr [EDX + 0xc],this
//         00407f0b     MOV        this,dword ptr [EAX + 0x50]
//         00407f0e     MOV        dword ptr [EDX + 0x50],this
//         00407f11     MOV        this,dword ptr [EAX + 0x54]
//         00407f14     MOV        dword ptr [EDX + 0x54],this
//         00407f17     MOV        this,dword ptr [EAX + 0x58]
//         00407f1a     MOV        dword ptr [EDX + 0x58],this
//         00407f1d     MOV        this,dword ptr [EAX + 0x5c]
//         00407f20     MOV        dword ptr [EDX + 0x5c],this
//         00407f23     MOV        this,dword ptr [EAX + 0x60]
//         00407f26     MOV        dword ptr [EDX + 0x60],this
//         00407f29     MOV        this,dword ptr [EAX + 0x64]
//         00407f2c     MOV        dword ptr [EDX + 0x64],this
//         00407f2f     MOV        this,dword ptr [EAX + 0x68]
//         00407f32     MOV        dword ptr [EDX + 0x68],this
//                              aibitm.cpp:83 (36)
//         00407f35     LEA        EDI,[EAX + 0x10]
//         00407f38     OR         this,0xffffffff
//         00407f3b     XOR        EAX,EAX
//         00407f3d     MOV        dword ptr [EDX],BaseItem::`vftable'              = 00407de0
//         00407f43     LEA        EBX,[EDX + 0x10]
//         00407f46     SCASB.RE   ES:EDI
//         00407f48     NOT        this
//         00407f4a     SUB        EDI,this
//         00407f4c     MOV        EAX,this
//         00407f4e     MOV        ESI,EDI
//         00407f50     MOV        EDI,EBX
//         00407f52     SHR        this,0x2
//         00407f55     MOVSD.REP  ES:EDI,ESI
//         00407f57     MOV        this,EAX
//                              aibitm.cpp:84 (13)
//         00407f59     MOV        EAX,EDX
//         00407f5b     AND        this,0x3
//         00407f5e     MOVSB.REP  ES:EDI,ESI
//         00407f60     POP        EDI
//         00407f61     POP        ESI
//         00407f62     POP        EBX
//         00407f63     RET        0x4
//         00407f66     ??         90h
//         00407f67     NOP
//         00407f68     NOP
//         00407f69     NOP
//         00407f6a     NOP
//         00407f6b     NOP
//         00407f6c     NOP
//         00407f6d     NOP
//         00407f6e     NOP
//         00407f6f     NOP
}

BaseItem::BaseItem(BaseItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall BaseItem(BaseItem * this, BaseItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              BaseItem *        Stack[0x4]:4   param_1                   XREF[1]:     00407ef0(R)
//                               ??0BaseItem@@QAE@ABV0@@Z                                     XREF[2]:     BuildItem:004083b9(c),
//                               BaseItem::BaseItem                                                        ConstructionItem:0040a919(c)
//                              aibitm.cpp:82 (69)
//         00407ef0     MOV        EAX,dword ptr [ESP + param_1]
//         00407ef4     MOV        EDX,this
//         00407ef6     PUSH       EBX
//         00407ef7     PUSH       ESI
//         00407ef8     MOV        this,dword ptr [EAX + 0x4]
//         00407efb     PUSH       EDI
//         00407efc     MOV        dword ptr [EDX + 0x4],this
//         00407eff     MOV        this,dword ptr [EAX + 0x8]
//         00407f02     MOV        dword ptr [EDX + 0x8],this
//         00407f05     MOV        this,dword ptr [EAX + 0xc]
//         00407f08     MOV        dword ptr [EDX + 0xc],this
//         00407f0b     MOV        this,dword ptr [EAX + 0x50]
//         00407f0e     MOV        dword ptr [EDX + 0x50],this
//         00407f11     MOV        this,dword ptr [EAX + 0x54]
//         00407f14     MOV        dword ptr [EDX + 0x54],this
//         00407f17     MOV        this,dword ptr [EAX + 0x58]
//         00407f1a     MOV        dword ptr [EDX + 0x58],this
//         00407f1d     MOV        this,dword ptr [EAX + 0x5c]
//         00407f20     MOV        dword ptr [EDX + 0x5c],this
//         00407f23     MOV        this,dword ptr [EAX + 0x60]
//         00407f26     MOV        dword ptr [EDX + 0x60],this
//         00407f29     MOV        this,dword ptr [EAX + 0x64]
//         00407f2c     MOV        dword ptr [EDX + 0x64],this
//         00407f2f     MOV        this,dword ptr [EAX + 0x68]
//         00407f32     MOV        dword ptr [EDX + 0x68],this
//                              aibitm.cpp:83 (36)
//         00407f35     LEA        EDI,[EAX + 0x10]
//         00407f38     OR         this,0xffffffff
//         00407f3b     XOR        EAX,EAX
//         00407f3d     MOV        dword ptr [EDX],BaseItem::`vftable'              = 00407de0
//         00407f43     LEA        EBX,[EDX + 0x10]
//         00407f46     SCASB.RE   ES:EDI
//         00407f48     NOT        this
//         00407f4a     SUB        EDI,this
//         00407f4c     MOV        EAX,this
//         00407f4e     MOV        ESI,EDI
//         00407f50     MOV        EDI,EBX
//         00407f52     SHR        this,0x2
//         00407f55     MOVSD.REP  ES:EDI,ESI
//         00407f57     MOV        this,EAX
//                              aibitm.cpp:84 (13)
//         00407f59     MOV        EAX,EDX
//         00407f5b     AND        this,0x3
//         00407f5e     MOVSB.REP  ES:EDI,ESI
//         00407f60     POP        EDI
//         00407f61     POP        ESI
//         00407f62     POP        EBX
//         00407f63     RET        0x4
//         00407f66     ??         90h
//         00407f67     NOP
//         00407f68     NOP
//         00407f69     NOP
//         00407f6a     NOP
//         00407f6b     NOP
//         00407f6c     NOP
//         00407f6d     NOP
//         00407f6e     NOP
//         00407f6f     NOP
}

BaseItem::~BaseItem() {
    /* TODO: Stub */
//                              void __thiscall ~BaseItem(BaseItem * this)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ??1BaseItem@@UAE@XZ                                          XREF[3]:     `scalar_deleting_destructor':00407
//                               BaseItem::~BaseItem                                                       ~BuildItem:00408476(c),
//                                                                                                         ~ConstructionItem:0040a956(c)
//                              aibitm.cpp:89 (6)
//         00407f70     MOV        dword ptr [this->_padding_],BaseItem::`vftable'  = 00407de0
//                              aibitm.cpp:90 (1)
//         00407f76     RET
//         00407f77     ??         90h
//         00407f78     NOP
//         00407f79     NOP
//         00407f7a     NOP
//         00407f7b     NOP
//         00407f7c     NOP
//         00407f7d     NOP
//         00407f7e     NOP
//         00407f7f     NOP
}

int BaseItem::typeID() {
    /* TODO: Stub */
//                              int __thiscall typeID(BaseItem * this)
//              int               EAX:4          <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?typeID@BaseItem@@QBEHXZ                                     XREF[93]:    numberItemsOfType:00409c9b(c),
//                               BaseItem::typeID                                                          numberUnbuiltItemsOfType:00409d6b(
//                                                                                                         initialize:004d3ddf(c),
//                                                                                                         initialize:004d3df4(c),
//                                                                                                         initialize:004d3e17(c),
//                                                                                                         initialize:004d3e2c(c),
//                                                                                                         initialize:004d3e38(c),
//                                                                                                         initialize:004d3e44(c),
//                                                                                                         initialize:004d3e50(c),
//                                                                                                         initialize:004d3e8e(c),
//                                                                                                         initialize:004d3ea5(c),
//                                                                                                         initialize:004d3eba(c),
//                                                                                                         initialize:004d3ed1(c),
//                                                                                                         initialize:004d3ee7(c),
//                                                                                                         initialize:004d3efd(c),
//                                                                                                         initialize:004d4240(c),
//                                                                                                         mostNeededResource:004d5024(c),
//                                                                                                         mostNeededResource:004d5044(c),
//                                                                                                         taskTrain:004fb5c5(c),
//                                                                                                         taskTrain:004fb6c3(c), [more]
//                              aibitm.cpp:131 (3)
//         00408020     MOV        EAX,dword ptr [ECX + this->typeIDValue]
//                              aibitm.cpp:133 (1)
//         00408023     RET
//         00408024     ??         90h
//         00408025     NOP
//         00408026     NOP
//         00408027     NOP
//         00408028     NOP
//         00408029     NOP
//         0040802a     NOP
//         0040802b     NOP
//         0040802c     NOP
//         0040802d     NOP
//         0040802e     NOP
//         0040802f     NOP
    return 0;
}

int BaseItem::gameID() {
    /* TODO: Stub */
//                              int __thiscall gameID(BaseItem * this)
//              int               EAX:4          <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?gameID@BaseItem@@QBEHXZ                                     XREF[6]:     save:0040906d(c),
//                               BaseItem::gameID                                                          displayBuildList:00409389(c),
//                                                                                                         displayBuildList:004093fb(c),
//                                                                                                         save:0040b329(c),
//                                                                                                         save:0040b52c(c),
//                                                                                                         removeBuiltItem:004d5292(c)
//                              aibitm.cpp:138 (3)
//         00408030     MOV        EAX,dword ptr [ECX + this->gameIDValue]
//                              aibitm.cpp:140 (1)
//         00408033     RET
//         00408034     ??         90h
//         00408035     NOP
//         00408036     NOP
//         00408037     NOP
//         00408038     NOP
//         00408039     NOP
//         0040803a     NOP
//         0040803b     NOP
//         0040803c     NOP
//         0040803d     NOP
//         0040803e     NOP
//         0040803f     NOP
    return 0;
}

int BaseItem::uniqueID() {
    /* TODO: Stub */
//                              int __thiscall uniqueID(BaseItem * this)
//              int               EAX:4          <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?uniqueID@BaseItem@@QBEHXZ                                   XREF[27]:    displayBuildList:00409379(c),
//                               BaseItem::uniqueID                                                        displayBuildList:004093eb(c),
//                                                                                                         specificBuildListItem:00409f6d(c),
//                                                                                                         save:0040b344(c),
//                                                                                                         save:0040b547(c),
//                                                                                                         initialize:004d3e9a(c),
//                                                                                                         initialize:004d3eb1(c),
//                                                                                                         initialize:004d3ec6(c),
//                                                                                                         nextBuildableItem:004d4904(c),
//                                                                                                         nextBuildableItem:004d492b(c),
//                                                                                                         nextBuildableItem:004d4955(c),
//                                                                                                         nextBuildableItem:004d497c(c),
//                                                                                                         addBuiltItem:004d51ca(c),
//                                                                                                         addBuiltItem:004d5231(c),
//                                                                                                         cancelTrainUnit:004d5643(c),
//                                                                                                         cancelResearch:004d5733(c),
//                                                                                                         placeStructure:004d6665(c),
//                                                                                                         taskBuilder:004f9d82(c),
//                                                                                                         taskTrain:004fb5bd(c),
//                                                                                                         taskTrain:004fb6b7(c), [more]
//                              aibitm.cpp:145 (3)
//         00408040     MOV        EAX,dword ptr [ECX + this->uniqueIDValue]
//                              aibitm.cpp:147 (1)
//         00408043     RET
//         00408044     ??         90h
//         00408045     NOP
//         00408046     NOP
//         00408047     NOP
//         00408048     NOP
//         00408049     NOP
//         0040804a     NOP
//         0040804b     NOP
//         0040804c     NOP
//         0040804d     NOP
//         0040804e     NOP
//         0040804f     NOP
    return 0;
}

char* BaseItem::name() {
    /* TODO: Stub */
//                              char * __thiscall name(BaseItem * this)
//              char *            EAX:4          <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?name@BaseItem@@QAEPADXZ                                     XREF[13]:    save:00408fe9(c),
//                               BaseItem::name                                                            displayBuildList:00409391(c),
//                                                                                                         displayBuildList:00409403(c),
//                                                                                                         save:0040b2af(c),
//                                                                                                         save:0040b4b2(c),
//                                                                                                         nextBuildableItem:004d48ed(c),
//                                                                                                         nextBuildableItem:004d4914(c),
//                                                                                                         nextBuildableItem:004d493e(c),
//                                                                                                         nextBuildableItem:004d4965(c),
//                                                                                                         addBuiltItem:004d521a(c),
//                                                                                                         placeDock:004d9e47(c),
//                                                                                                         influencePlaceStructure:004db34c(c
//                                                                                                         doSomething:004f04d8(c)
//                              aibitm.cpp:152 (3)
//         00408050     LEA        EAX,[ECX + this->nameValue[0]]
//                              aibitm.cpp:154 (1)
//         00408053     RET
//         00408054     ??         90h
//         00408055     NOP
//         00408056     NOP
//         00408057     NOP
//         00408058     NOP
//         00408059     NOP
//         0040805a     NOP
//         0040805b     NOP
//         0040805c     NOP
//         0040805d     NOP
//         0040805e     NOP
//         0040805f     NOP
    return 0;
}

float BaseItem::x() {
    /* TODO: Stub */
//                              float __thiscall x(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?x@BaseItem@@QBEMXZ                                          XREF[18]:    save:004090a3(c),
//                               BaseItem::x                                                               save:0040b35f(c),
//                                                                                                         save:0040b562(c),
//                                                                                                         setReferencePoint:0040ba26(c),
//                                                                                                         setReferencePoint:0040ba68(c),
//                                                                                                         setReferencePoint:0040babe(c),
//                                                                                                         unplaceStructure:0040bc98(c),
//                                                                                                         lot:0040bd8b(c), lot:0040bdca(c),
//                                                                                                         randomLot:0040be28(c),
//                                                                                                         cancelBuildItem:004d53ee(c),
//                                                                                                         cancelBuildItem:004d542e(c),
//                                                                                                         placeStructure:004d638f(c),
//                                                                                                         placeStructure:004d6641(c),
//                                                                                                         setBuilt:004d6832(c),
//                                                                                                         taskBuilder:004f9b46(c),
//                                                                                                         taskBuilder:004f9bbb(c),
//                                                                                                         taskBuilder:004f9d95(c)
//                              aibitm.cpp:159 (3)
//         00408060     FLD        float ptr [ECX + this->xValue]
//                              aibitm.cpp:161 (1)
//         00408063     RET
//         00408064     ??         90h
//         00408065     NOP
//         00408066     NOP
//         00408067     NOP
//         00408068     NOP
//         00408069     NOP
//         0040806a     NOP
//         0040806b     NOP
//         0040806c     NOP
//         0040806d     NOP
//         0040806e     NOP
//         0040806f     NOP
    return 0;
}

float BaseItem::y() {
    /* TODO: Stub */
//                              float __thiscall y(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?y@BaseItem@@QBEMXZ                                          XREF[18]:    save:004090be(c),
//                               BaseItem::y                                                               save:0040b37a(c),
//                                                                                                         save:0040b57d(c),
//                                                                                                         setReferencePoint:0040ba3c(c),
//                                                                                                         setReferencePoint:0040ba95(c),
//                                                                                                         setReferencePoint:0040baf2(c),
//                                                                                                         unplaceStructure:0040bcaa(c),
//                                                                                                         lot:0040bd9d(c), lot:0040bddc(c),
//                                                                                                         randomLot:0040be3a(c),
//                                                                                                         cancelBuildItem:004d53ce(c),
//                                                                                                         cancelBuildItem:004d540e(c),
//                                                                                                         placeStructure:004d63ac(c),
//                                                                                                         placeStructure:004d6636(c),
//                                                                                                         setBuilt:004d6843(c),
//                                                                                                         taskBuilder:004f9b56(c),
//                                                                                                         taskBuilder:004f9bc9(c),
//                                                                                                         taskBuilder:004f9d8a(c)
//                              aibitm.cpp:166 (3)
//         00408070     FLD        float ptr [ECX + this->yValue]
//                              aibitm.cpp:168 (1)
//         00408073     RET
//         00408074     ??         90h
//         00408075     NOP
//         00408076     NOP
//         00408077     NOP
//         00408078     NOP
//         00408079     NOP
//         0040807a     NOP
//         0040807b     NOP
//         0040807c     NOP
//         0040807d     NOP
//         0040807e     NOP
//         0040807f     NOP
    return 0;
}

float BaseItem::z() {
    /* TODO: Stub */
//                              float __thiscall z(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?z@BaseItem@@QBEMXZ                                          XREF[4]:     save:004090d9(c),
//                               BaseItem::z                                                               save:0040b395(c),
//                                                                                                         save:0040b598(c),
//                                                                                                         setReferencePoint:0040ba52(c)
//                              aibitm.cpp:173 (3)
//         00408080     FLD        float ptr [ECX + this->zValue]
//                              aibitm.cpp:175 (1)
//         00408083     RET
//         00408084     ??         90h
//         00408085     NOP
//         00408086     NOP
//         00408087     NOP
//         00408088     NOP
//         00408089     NOP
//         0040808a     NOP
//         0040808b     NOP
//         0040808c     NOP
//         0040808d     NOP
//         0040808e     NOP
//         0040808f     NOP
    return 0;
}

float BaseItem::xSize() {
    /* TODO: Stub */
//                              float __thiscall xSize(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?xSize@BaseItem@@QBEMXZ                                      XREF[15]:    save:004090f4(c),
//                               BaseItem::xSize                                                           save:0040b3b0(c),
//                                                                                                         save:0040b5b3(c),
//                                                                                                         setReferencePoint:0040ba73(c),
//                                                                                                         setReferencePoint:0040bac9(c),
//                                                                                                         cancelBuildItem:004d53f9(c),
//                                                                                                         cancelBuildItem:004d5439(c),
//                                                                                                         canPlace:004d6009(c),
//                                                                                                         canPlace:004d6014(c),
//                                                                                                         placeStructure:004d632d(c),
//                                                                                                         placeStructure:004d6338(c),
//                                                                                                         placeStructure:004d639a(c),
//                                                                                                         placeStructure:004d63cb(c),
//                                                                                                         placeDock:004d9e6d(c),
//                                                                                                         influencePlaceStructure:004db33c(c
//                              aibitm.cpp:180 (3)
//         00408090     FLD        float ptr [ECX + this->xSizeValue]
//                              aibitm.cpp:182 (1)
//         00408093     RET
//         00408094     ??         90h
//         00408095     NOP
//         00408096     NOP
//         00408097     NOP
//         00408098     NOP
//         00408099     NOP
//         0040809a     NOP
//         0040809b     NOP
//         0040809c     NOP
//         0040809d     NOP
//         0040809e     NOP
//         0040809f     NOP
    return 0;
}

float BaseItem::ySize() {
    /* TODO: Stub */
//                              float __thiscall ySize(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?ySize@BaseItem@@QBEMXZ                                      XREF[14]:    save:0040910f(c),
//                               BaseItem::ySize                                                           save:0040b3cb(c),
//                                                                                                         save:0040b5ce(c),
//                                                                                                         setReferencePoint:0040baa0(c),
//                                                                                                         setReferencePoint:0040bafd(c),
//                                                                                                         cancelBuildItem:004d53d9(c),
//                                                                                                         cancelBuildItem:004d5419(c),
//                                                                                                         canPlace:004d6026(c),
//                                                                                                         canPlace:004d6031(c),
//                                                                                                         placeStructure:004d634e(c),
//                                                                                                         placeStructure:004d6359(c),
//                                                                                                         placeStructure:004d63b7(c),
//                                                                                                         placeStructure:004d63df(c),
//                                                                                                         placeDock:004d9e62(c)
//                              aibitm.cpp:187 (3)
//         004080a0     FLD        float ptr [ECX + this->ySizeValue]
//                              aibitm.cpp:189 (1)
//         004080a3     RET
//         004080a4     ??         90h
//         004080a5     NOP
//         004080a6     NOP
//         004080a7     NOP
//         004080a8     NOP
//         004080a9     NOP
//         004080aa     NOP
//         004080ab     NOP
//         004080ac     NOP
//         004080ad     NOP
//         004080ae     NOP
//         004080af     NOP
    return 0;
}

float BaseItem::zSize() {
    /* TODO: Stub */
//                              float __thiscall zSize(BaseItem * this)
//              float             ST0:10         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?zSize@BaseItem@@QBEMXZ                                      XREF[4]:     save:0040912a(c),
//                               BaseItem::zSize                                                           save:0040b3e6(c),
//                                                                                                         save:0040b5e9(c),
//                                                                                                         placeDock:004d9e57(c)
//                              aibitm.cpp:194 (3)
//         004080b0     FLD        float ptr [ECX + this->zSizeValue]
//                              aibitm.cpp:196 (1)
//         004080b3     RET
//         004080b4     ??         90h
//         004080b5     NOP
//         004080b6     NOP
//         004080b7     NOP
//         004080b8     NOP
//         004080b9     NOP
//         004080ba     NOP
//         004080bb     NOP
//         004080bc     NOP
//         004080bd     NOP
//         004080be     NOP
//         004080bf     NOP
    return 0;
}

int BaseItem::skip() {
    /* TODO: Stub */
//                              int __thiscall skip(BaseItem * this)
//              int               EAX:4          <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//                               ?skip@BaseItem@@QBEHXZ                                       XREF[11]:    save:00409145(c),
//                               BaseItem::skip                                                            displayBuildList:00409361(c),
//                                                                                                         displayBuildList:004093d3(c),
//                                                                                                         save:0040b401(c),
//                                                                                                         save:0040b604(c),
//                                                                                                         skipNextBuildListItem:004d449a(c),
//                                                                                                         nextBuildableItem:004d4a67(c),
//                                                                                                         nextBuildableItem:004d4a95(c),
//                                                                                                         nextBuildableItem:004d4b96(c),
//                                                                                                         nextBuildListItemCategory:004d4dde
//                                                                                                         blockingResource:004d4e5d(c)
//                              aibitm.cpp:201 (3)
//         004080c0     MOV        EAX,dword ptr [ECX + this->skipValue]
//                              aibitm.cpp:203 (1)
//         004080c3     RET
//         004080c4     ??         90h
//         004080c5     NOP
//         004080c6     NOP
//         004080c7     NOP
//         004080c8     NOP
//         004080c9     NOP
//         004080ca     NOP
//         004080cb     NOP
//         004080cc     NOP
//         004080cd     NOP
//         004080ce     NOP
//         004080cf     NOP
    return 0;
}

void BaseItem::setTypeID(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setTypeID(BaseItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004080d0(R)
//                               ?setTypeID@BaseItem@@QAEXH@Z                                 XREF[1]:     placeStructure:004d66b3(c)
//                               BaseItem::setTypeID
//                              aibitm.cpp:208 (7)
//         004080d0     MOV        EAX,dword ptr [ESP + param_1]
//         004080d4     MOV        dword ptr [ECX + this->typeIDValue],EAX
//                              aibitm.cpp:210 (3)
//         004080d7     RET        0x4
//         004080da     ??         90h
//         004080db     NOP
//         004080dc     NOP
//         004080dd     NOP
//         004080de     NOP
//         004080df     NOP
    return;
}

void BaseItem::setGameID(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setGameID(BaseItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004080e0(R)
//                               ?setGameID@BaseItem@@QAEXH@Z                                 XREF[8]:     BuildAIModule:00408c78(c),
//                               BaseItem::setGameID                                                       insertItem:00409ad2(c),
//                                                                                                         ConstructionAIModule:0040aec4(c),
//                                                                                                         ConstructionAIModule:0040b0af(c),
//                                                                                                         addItem:004d5117(c),
//                                                                                                         addBuiltItem:004d51f0(c),
//                                                                                                         removeBuiltItem:004d52bd(c),
//                                                                                                         addTrainedUnit:004d55bd(c)
//                              aibitm.cpp:215 (7)
//         004080e0     MOV        EAX,dword ptr [ESP + param_1]
//         004080e4     MOV        dword ptr [ECX + this->gameIDValue],EAX
//                              aibitm.cpp:217 (3)
//         004080e7     RET        0x4
//         004080ea     ??         90h
//         004080eb     NOP
//         004080ec     NOP
//         004080ed     NOP
//         004080ee     NOP
//         004080ef     NOP
    return;
}

void BaseItem::setUniqueID(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setUniqueID(BaseItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004080f0(R)
//                               ?setUniqueID@BaseItem@@QAEXH@Z                               XREF[5]:     ConstructionAIModule:0040aed0(c),
//                               BaseItem::setUniqueID                                                     ConstructionAIModule:0040b0bb(c),
//                                                                                                         unplaceStructure:0040bc58(c),
//                                                                                                         unplaceStructure:0040bce8(c),
//                                                                                                         placeStructure:004d666d(c)
//                              aibitm.cpp:222 (7)
//         004080f0     MOV        EAX,dword ptr [ESP + param_1]
//         004080f4     MOV        dword ptr [ECX + this->uniqueIDValue],EAX
//                              aibitm.cpp:224 (3)
//         004080f7     RET        0x4
//         004080fa     ??         90h
//         004080fb     NOP
//         004080fc     NOP
//         004080fd     NOP
//         004080fe     NOP
//         004080ff     NOP
    return;
}

void BaseItem::setName(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall setName(BaseItem * this, char * param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00408100(R)
//                               ?setName@BaseItem@@QAEXPAD@Z
//                               BaseItem::setName
//                              aibitm.cpp:230 (19)
//         00408100     MOV        EAX,dword ptr [ESP + param_1]
//         00408104     PUSH       0x3f
//         00408106     ADD        this,0x10
//         00408109     PUSH       EAX
//         0040810a     PUSH       this
//         0040810b     CALL       strncpy                                          undefined strncpy()
//         00408110     ADD        ESP,0xc
//                              aibitm.cpp:232 (3)
//         00408113     RET        0x4
//         00408116     ??         90h
//         00408117     NOP
//         00408118     NOP
//         00408119     NOP
//         0040811a     NOP
//         0040811b     NOP
//         0040811c     NOP
//         0040811d     NOP
//         0040811e     NOP
//         0040811f     NOP
    return;
}

void BaseItem::setX(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setX(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408120(R)
//                               ?setX@BaseItem@@QAEXM@Z                                      XREF[3]:     BuildAIModule:00408c84(c),
//                               BaseItem::setX                                                            insertItem:00409ade(c),
//                                                                                                         setReferencePoint:0040ba35(c)
//                              aibitm.cpp:237 (7)
//         00408120     MOV        EAX,dword ptr [ESP + param_1]
//         00408124     MOV        dword ptr [ECX + this->xValue],EAX
//                              aibitm.cpp:239 (3)
//         00408127     RET        0x4
//         0040812a     ??         90h
//         0040812b     NOP
//         0040812c     NOP
//         0040812d     NOP
//         0040812e     NOP
//         0040812f     NOP
    return;
}

void BaseItem::setY(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setY(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408130(R)
//                               ?setY@BaseItem@@QAEXM@Z                                      XREF[3]:     BuildAIModule:00408c90(c),
//                               BaseItem::setY                                                            insertItem:00409aea(c),
//                                                                                                         setReferencePoint:0040ba4b(c)
//                              aibitm.cpp:244 (7)
//         00408130     MOV        EAX,dword ptr [ESP + param_1]
//         00408134     MOV        dword ptr [ECX + this->yValue],EAX
//                              aibitm.cpp:246 (3)
//         00408137     RET        0x4
//         0040813a     ??         90h
//         0040813b     NOP
//         0040813c     NOP
//         0040813d     NOP
//         0040813e     NOP
//         0040813f     NOP
    return;
}

void BaseItem::setZ(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setZ(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408140(R)
//                               ?setZ@BaseItem@@QAEXM@Z                                      XREF[3]:     BuildAIModule:00408c9c(c),
//                               BaseItem::setZ                                                            insertItem:00409af6(c),
//                                                                                                         setReferencePoint:0040ba61(c)
//                              aibitm.cpp:251 (7)
//         00408140     MOV        EAX,dword ptr [ESP + param_1]
//         00408144     MOV        dword ptr [ECX + this->zValue],EAX
//                              aibitm.cpp:253 (3)
//         00408147     RET        0x4
//         0040814a     ??         90h
//         0040814b     NOP
//         0040814c     NOP
//         0040814d     NOP
//         0040814e     NOP
//         0040814f     NOP
    return;
}

void BaseItem::setXSize(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setXSize(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408150(R)
//                               ?setXSize@BaseItem@@QAEXM@Z
//                               BaseItem::setXSize
//                              aibitm.cpp:258 (7)
//         00408150     MOV        EAX,dword ptr [ESP + param_1]
//         00408154     MOV        dword ptr [ECX + this->xSizeValue],EAX
//                              aibitm.cpp:260 (3)
//         00408157     RET        0x4
//         0040815a     ??         90h
//         0040815b     NOP
//         0040815c     NOP
//         0040815d     NOP
//         0040815e     NOP
//         0040815f     NOP
    return;
}

void BaseItem::setYSize(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setYSize(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408160(R)
//                               ?setYSize@BaseItem@@QAEXM@Z
//                               BaseItem::setYSize
//                              aibitm.cpp:265 (7)
//         00408160     MOV        EAX,dword ptr [ESP + param_1]
//         00408164     MOV        dword ptr [ECX + this->ySizeValue],EAX
//                              aibitm.cpp:267 (3)
//         00408167     RET        0x4
//         0040816a     ??         90h
//         0040816b     NOP
//         0040816c     NOP
//         0040816d     NOP
//         0040816e     NOP
//         0040816f     NOP
    return;
}

void BaseItem::setZSize(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setZSize(BaseItem * this, float param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00408170(R)
//                               ?setZSize@BaseItem@@QAEXM@Z
//                               BaseItem::setZSize
//                              aibitm.cpp:272 (7)
//         00408170     MOV        EAX,dword ptr [ESP + param_1]
//         00408174     MOV        dword ptr [ECX + this->zSizeValue],EAX
//                              aibitm.cpp:274 (3)
//         00408177     RET        0x4
//         0040817a     ??         90h
//         0040817b     NOP
//         0040817c     NOP
//         0040817d     NOP
//         0040817e     NOP
//         0040817f     NOP
    return;
}

void BaseItem::setSkip(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setSkip(BaseItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BaseItem *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408180(R)
//                               ?setSkip@BaseItem@@QAEXH@Z                                   XREF[8]:     BuildAIModule:00408c6c(c),
//                               BaseItem::setSkip                                                         insertItem:00409ac9(c),
//                                                                                                         ConstructionAIModule:0040aedc(c),
//                                                                                                         ConstructionAIModule:0040b0c7(c),
//                                                                                                         skipNextBuildListItem:004d44fd(c),
//                                                                                                         nextBuildableItem:004d4aae(c),
//                                                                                                         nextBuildableItem:004d4bf9(c),
//                                                                                                         unskipBuildList:004d5dad(c)
//                              aibitm.cpp:279 (7)
//         00408180     MOV        EAX,dword ptr [ESP + param_1]
//         00408184     MOV        dword ptr [ECX + this->skipValue],EAX
//                              aibitm.cpp:281 (3)
//         00408187     RET        0x4
//         0040818a     ??         90h
//         0040818b     NOP
//         0040818c     NOP
//         0040818d     NOP
//         0040818e     NOP
//         0040818f     NOP
    return;
}

