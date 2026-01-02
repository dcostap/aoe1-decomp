#include "../common.h"
#include "aiblditm.h"

BuildItem::BuildItem() {
    /* TODO: Stub */
//                              undefined __thiscall BuildItem(BuildItem * this, BuildItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004083b2(R)
//                               ??0BuildItem@@QAE@ABV0@@Z
//                               BuildItem::BuildItem
//                              aiblditm.cpp:111 (146)
//         004083b0     PUSH       ESI
//         004083b1     PUSH       EDI
//         004083b2     MOV        EDI,dword ptr [ESP + param_1]
//         004083b6     MOV        ESI,this
//         004083b8     PUSH       EDI
//         004083b9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         004083be     XOR        EAX,EAX
//         004083c0     MOV        dword ptr [ESI + 0x6c],EAX
//         004083c3     MOV        dword ptr [ESI + 0x70],EAX
//         004083c6     MOV        this,dword ptr [EDI + 0x74]
//         004083c9     MOV        dword ptr [ESI + 0x74],this
//         004083cc     MOV        EDX,dword ptr [EDI + 0x78]
//         004083cf     MOV        dword ptr [ESI + 0x78],EDX
//         004083d2     MOV        this,dword ptr [EDI + 0x7c]
//         004083d5     MOV        dword ptr [ESI + 0x7c],this
//         004083d8     MOV        EDX,dword ptr [EDI + 0x80]
//         004083de     MOV        dword ptr [ESI + 0x80],EDX
//         004083e4     MOV        this,dword ptr [EDI + 0x80]
//         004083ea     MOV        dword ptr [ESI + 0x84],this
//         004083f0     MOV        EDX,dword ptr [EDI + 0x88]
//         004083f6     MOV        dword ptr [ESI + 0x88],EDX
//         004083fc     MOV        this,dword ptr [EDI + 0x8c]
//         00408402     MOV        dword ptr [ESI + 0x8c],this
//         00408408     MOV        EDX,dword ptr [EDI + 0x90]
//         0040840e     MOV        dword ptr [ESI + 0x90],EDX
//         00408414     MOV        this,dword ptr [EDI + 0x9c]
//         0040841a     MOV        dword ptr [ESI + 0x9c],this
//         00408420     MOV        dword ptr [ESI + 0xa0],EAX
//         00408426     MOV        dword ptr [ESI + 0xa4],0xffffffff
//         00408430     MOV        dword ptr [ESI + 0xa8],EAX
//         00408436     MOV        byte ptr [ESI + 0xac],AL
//         0040843c     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
//                              aiblditm.cpp:112 (12)
//         00408442     MOV        EDX,dword ptr [EDI + 0x94]
//         00408448     MOV        dword ptr [ESI + 0x94],EDX
//                              aiblditm.cpp:113 (12)
//         0040844e     MOV        EAX,dword ptr [EDI + 0x98]
//         00408454     MOV        dword ptr [ESI + 0x98],EAX
//                              aiblditm.cpp:114 (7)
//         0040845a     MOV        EAX,ESI
//         0040845c     POP        EDI
//         0040845d     POP        ESI
//         0040845e     RET        0x4
//         00408461     ??         90h
//         00408462     NOP
//         00408463     NOP
//         00408464     NOP
//         00408465     NOP
//         00408466     NOP
//         00408467     NOP
//         00408468     NOP
//         00408469     NOP
//         0040846a     NOP
//         0040846b     NOP
//         0040846c     NOP
//         0040846d     NOP
//         0040846e     NOP
//         0040846f     NOP
}

BuildItem::BuildItem(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, char* param_7, float param_8, float param_9, float param_10, int param_11, int param_12, int param_13, int param_14) {
    /* TODO: Stub */
//                              undefined __thiscall BuildItem(BuildItem * this, BuildItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004083b2(R)
//                               ??0BuildItem@@QAE@ABV0@@Z
//                               BuildItem::BuildItem
//                              aiblditm.cpp:111 (146)
//         004083b0     PUSH       ESI
//         004083b1     PUSH       EDI
//         004083b2     MOV        EDI,dword ptr [ESP + param_1]
//         004083b6     MOV        ESI,this
//         004083b8     PUSH       EDI
//         004083b9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         004083be     XOR        EAX,EAX
//         004083c0     MOV        dword ptr [ESI + 0x6c],EAX
//         004083c3     MOV        dword ptr [ESI + 0x70],EAX
//         004083c6     MOV        this,dword ptr [EDI + 0x74]
//         004083c9     MOV        dword ptr [ESI + 0x74],this
//         004083cc     MOV        EDX,dword ptr [EDI + 0x78]
//         004083cf     MOV        dword ptr [ESI + 0x78],EDX
//         004083d2     MOV        this,dword ptr [EDI + 0x7c]
//         004083d5     MOV        dword ptr [ESI + 0x7c],this
//         004083d8     MOV        EDX,dword ptr [EDI + 0x80]
//         004083de     MOV        dword ptr [ESI + 0x80],EDX
//         004083e4     MOV        this,dword ptr [EDI + 0x80]
//         004083ea     MOV        dword ptr [ESI + 0x84],this
//         004083f0     MOV        EDX,dword ptr [EDI + 0x88]
//         004083f6     MOV        dword ptr [ESI + 0x88],EDX
//         004083fc     MOV        this,dword ptr [EDI + 0x8c]
//         00408402     MOV        dword ptr [ESI + 0x8c],this
//         00408408     MOV        EDX,dword ptr [EDI + 0x90]
//         0040840e     MOV        dword ptr [ESI + 0x90],EDX
//         00408414     MOV        this,dword ptr [EDI + 0x9c]
//         0040841a     MOV        dword ptr [ESI + 0x9c],this
//         00408420     MOV        dword ptr [ESI + 0xa0],EAX
//         00408426     MOV        dword ptr [ESI + 0xa4],0xffffffff
//         00408430     MOV        dword ptr [ESI + 0xa8],EAX
//         00408436     MOV        byte ptr [ESI + 0xac],AL
//         0040843c     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
//                              aiblditm.cpp:112 (12)
//         00408442     MOV        EDX,dword ptr [EDI + 0x94]
//         00408448     MOV        dword ptr [ESI + 0x94],EDX
//                              aiblditm.cpp:113 (12)
//         0040844e     MOV        EAX,dword ptr [EDI + 0x98]
//         00408454     MOV        dword ptr [ESI + 0x98],EAX
//                              aiblditm.cpp:114 (7)
//         0040845a     MOV        EAX,ESI
//         0040845c     POP        EDI
//         0040845d     POP        ESI
//         0040845e     RET        0x4
//         00408461     ??         90h
//         00408462     NOP
//         00408463     NOP
//         00408464     NOP
//         00408465     NOP
//         00408466     NOP
//         00408467     NOP
//         00408468     NOP
//         00408469     NOP
//         0040846a     NOP
//         0040846b     NOP
//         0040846c     NOP
//         0040846d     NOP
//         0040846e     NOP
//         0040846f     NOP
}

BuildItem::BuildItem(BuildItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall BuildItem(BuildItem * this, BuildItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004083b2(R)
//                               ??0BuildItem@@QAE@ABV0@@Z
//                               BuildItem::BuildItem
//                              aiblditm.cpp:111 (146)
//         004083b0     PUSH       ESI
//         004083b1     PUSH       EDI
//         004083b2     MOV        EDI,dword ptr [ESP + param_1]
//         004083b6     MOV        ESI,this
//         004083b8     PUSH       EDI
//         004083b9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         004083be     XOR        EAX,EAX
//         004083c0     MOV        dword ptr [ESI + 0x6c],EAX
//         004083c3     MOV        dword ptr [ESI + 0x70],EAX
//         004083c6     MOV        this,dword ptr [EDI + 0x74]
//         004083c9     MOV        dword ptr [ESI + 0x74],this
//         004083cc     MOV        EDX,dword ptr [EDI + 0x78]
//         004083cf     MOV        dword ptr [ESI + 0x78],EDX
//         004083d2     MOV        this,dword ptr [EDI + 0x7c]
//         004083d5     MOV        dword ptr [ESI + 0x7c],this
//         004083d8     MOV        EDX,dword ptr [EDI + 0x80]
//         004083de     MOV        dword ptr [ESI + 0x80],EDX
//         004083e4     MOV        this,dword ptr [EDI + 0x80]
//         004083ea     MOV        dword ptr [ESI + 0x84],this
//         004083f0     MOV        EDX,dword ptr [EDI + 0x88]
//         004083f6     MOV        dword ptr [ESI + 0x88],EDX
//         004083fc     MOV        this,dword ptr [EDI + 0x8c]
//         00408402     MOV        dword ptr [ESI + 0x8c],this
//         00408408     MOV        EDX,dword ptr [EDI + 0x90]
//         0040840e     MOV        dword ptr [ESI + 0x90],EDX
//         00408414     MOV        this,dword ptr [EDI + 0x9c]
//         0040841a     MOV        dword ptr [ESI + 0x9c],this
//         00408420     MOV        dword ptr [ESI + 0xa0],EAX
//         00408426     MOV        dword ptr [ESI + 0xa4],0xffffffff
//         00408430     MOV        dword ptr [ESI + 0xa8],EAX
//         00408436     MOV        byte ptr [ESI + 0xac],AL
//         0040843c     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
//                              aiblditm.cpp:112 (12)
//         00408442     MOV        EDX,dword ptr [EDI + 0x94]
//         00408448     MOV        dword ptr [ESI + 0x94],EDX
//                              aiblditm.cpp:113 (12)
//         0040844e     MOV        EAX,dword ptr [EDI + 0x98]
//         00408454     MOV        dword ptr [ESI + 0x98],EAX
//                              aiblditm.cpp:114 (7)
//         0040845a     MOV        EAX,ESI
//         0040845c     POP        EDI
//         0040845d     POP        ESI
//         0040845e     RET        0x4
//         00408461     ??         90h
//         00408462     NOP
//         00408463     NOP
//         00408464     NOP
//         00408465     NOP
//         00408466     NOP
//         00408467     NOP
//         00408468     NOP
//         00408469     NOP
//         0040846a     NOP
//         0040846b     NOP
//         0040846c     NOP
//         0040846d     NOP
//         0040846e     NOP
//         0040846f     NOP
}

BuildItem::BuildItem(BuildItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall BuildItem(BuildItem * this, BuildItem * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004083b2(R)
//                               ??0BuildItem@@QAE@ABV0@@Z
//                               BuildItem::BuildItem
//                              aiblditm.cpp:111 (146)
//         004083b0     PUSH       ESI
//         004083b1     PUSH       EDI
//         004083b2     MOV        EDI,dword ptr [ESP + param_1]
//         004083b6     MOV        ESI,this
//         004083b8     PUSH       EDI
//         004083b9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem
//         004083be     XOR        EAX,EAX
//         004083c0     MOV        dword ptr [ESI + 0x6c],EAX
//         004083c3     MOV        dword ptr [ESI + 0x70],EAX
//         004083c6     MOV        this,dword ptr [EDI + 0x74]
//         004083c9     MOV        dword ptr [ESI + 0x74],this
//         004083cc     MOV        EDX,dword ptr [EDI + 0x78]
//         004083cf     MOV        dword ptr [ESI + 0x78],EDX
//         004083d2     MOV        this,dword ptr [EDI + 0x7c]
//         004083d5     MOV        dword ptr [ESI + 0x7c],this
//         004083d8     MOV        EDX,dword ptr [EDI + 0x80]
//         004083de     MOV        dword ptr [ESI + 0x80],EDX
//         004083e4     MOV        this,dword ptr [EDI + 0x80]
//         004083ea     MOV        dword ptr [ESI + 0x84],this
//         004083f0     MOV        EDX,dword ptr [EDI + 0x88]
//         004083f6     MOV        dword ptr [ESI + 0x88],EDX
//         004083fc     MOV        this,dword ptr [EDI + 0x8c]
//         00408402     MOV        dword ptr [ESI + 0x8c],this
//         00408408     MOV        EDX,dword ptr [EDI + 0x90]
//         0040840e     MOV        dword ptr [ESI + 0x90],EDX
//         00408414     MOV        this,dword ptr [EDI + 0x9c]
//         0040841a     MOV        dword ptr [ESI + 0x9c],this
//         00408420     MOV        dword ptr [ESI + 0xa0],EAX
//         00408426     MOV        dword ptr [ESI + 0xa4],0xffffffff
//         00408430     MOV        dword ptr [ESI + 0xa8],EAX
//         00408436     MOV        byte ptr [ESI + 0xac],AL
//         0040843c     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
//                              aiblditm.cpp:112 (12)
//         00408442     MOV        EDX,dword ptr [EDI + 0x94]
//         00408448     MOV        dword ptr [ESI + 0x94],EDX
//                              aiblditm.cpp:113 (12)
//         0040844e     MOV        EAX,dword ptr [EDI + 0x98]
//         00408454     MOV        dword ptr [ESI + 0x98],EAX
//                              aiblditm.cpp:114 (7)
//         0040845a     MOV        EAX,ESI
//         0040845c     POP        EDI
//         0040845d     POP        ESI
//         0040845e     RET        0x4
//         00408461     ??         90h
//         00408462     NOP
//         00408463     NOP
//         00408464     NOP
//         00408465     NOP
//         00408466     NOP
//         00408467     NOP
//         00408468     NOP
//         00408469     NOP
//         0040846a     NOP
//         0040846b     NOP
//         0040846c     NOP
//         0040846d     NOP
//         0040846e     NOP
//         0040846f     NOP
}

BuildItem::~BuildItem() {
    /* TODO: Stub */
//                              void __thiscall ~BuildItem(BuildItem * this)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ??1BuildItem@@UAE@XZ                                         XREF[3]:     `vector_deleting_destructor':00408
//                               BuildItem::~BuildItem                                                     ~BuildAIModule:00408dc7(c),
//                                                                                                         FUN_0055c46b:0055c477(c)
//                              aiblditm.cpp:119 (11)
//         00408470     MOV        dword ptr [this->_padding_],BuildItem::`vftable' = 00408200
//         00408476     JMP        BaseItem::~BaseItem                              void ~BaseItem(BaseItem * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0040847b     ??         90h
//         0040847c     NOP
//         0040847d     NOP
//         0040847e     NOP
//         0040847f     NOP
}

int BuildItem::buildCategory() {
    /* TODO: Stub */
//                              int __thiscall buildCategory(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?buildCategory@BuildItem@@QBEHXZ                             XREF[47]:    displayBuildList:00409381(c),
//                               BuildItem::buildCategory                                                  displayBuildList:004093f3(c),
//                                                                                                         numberItemsOfType:00409ca6(c),
//                                                                                                         numberBuiltItemsOfType:00409d06(c)
//                                                                                                         numberUnbuiltItemsOfType:00409d76(
//                                                                                                         initialize:004d3dd4(c),
//                                                                                                         initialize:004d3e0b(c),
//                                                                                                         initialize:004d3e72(c),
//                                                                                                         initialize:004d3e7e(c),
//                                                                                                         initialize:004d4235(c),
//                                                                                                         initialize:004d424f(c),
//                                                                                                         initialize:004d4331(c),
//                                                                                                         initialize:004d4346(c),
//                                                                                                         initialize:004d4352(c),
//                                                                                                         mostNeededResource:004d4fd7(c),
//                                                                                                         mostNeededResource:004d5007(c),
//                                                                                                         mostNeededResource:004d5013(c),
//                                                                                                         allBuilt:004d5c42(c),
//                                                                                                         allBuilt:004d5c4d(c),
//                                                                                                         buildItem:004d5e25(c), [more]
//                              aiblditm.cpp:161 (3)
//         00408500     MOV        EAX,dword ptr [ECX + this->buildCategoryValue]
//                              aiblditm.cpp:163 (1)
//         00408503     RET
//         00408504     ??         90h
//         00408505     NOP
//         00408506     NOP
//         00408507     NOP
//         00408508     NOP
//         00408509     NOP
//         0040850a     NOP
//         0040850b     NOP
//         0040850c     NOP
//         0040850d     NOP
//         0040850e     NOP
//         0040850f     NOP
    return 0;
}

int BuildItem::number() {
    /* TODO: Stub */
//                              int __thiscall number(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?number@BuildItem@@QBEHXZ
//                               BuildItem::number
//                              aiblditm.cpp:168 (3)
//         00408510     MOV        EAX,dword ptr [ECX + this->numberValue]
//                              aiblditm.cpp:170 (1)
//         00408513     RET
//         00408514     ??         90h
//         00408515     NOP
//         00408516     NOP
//         00408517     NOP
//         00408518     NOP
//         00408519     NOP
//         0040851a     NOP
//         0040851b     NOP
//         0040851c     NOP
//         0040851d     NOP
//         0040851e     NOP
//         0040851f     NOP
    return 0;
}

int BuildItem::priority() {
    /* TODO: Stub */
//                              int __thiscall priority(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?priority@BuildItem@@QBEHXZ
//                               BuildItem::priority
//                              aiblditm.cpp:175 (3)
//         00408520     MOV        EAX,dword ptr [ECX + this->priorityValue]
//                              aiblditm.cpp:177 (1)
//         00408523     RET
//         00408524     ??         90h
//         00408525     NOP
//         00408526     NOP
//         00408527     NOP
//         00408528     NOP
//         00408529     NOP
//         0040852a     NOP
//         0040852b     NOP
//         0040852c     NOP
//         0040852d     NOP
//         0040852e     NOP
//         0040852f     NOP
    return 0;
}

int BuildItem::inProgress() {
    /* TODO: Stub */
//                              int __thiscall inProgress(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?inProgress@BuildItem@@QBEHXZ                                XREF[15]:    save:0040917b(c),
//                               BuildItem::inProgress                                                     displayBuildList:00409371(c),
//                                                                                                         displayBuildList:004093e3(c),
//                                                                                                         numberItemsInProgress:00409bcb(c),
//                                                                                                         numberItemsBuiltOrInProgress:00409
//                                                                                                         numberBuiltOrInProgressItemsOfType
//                                                                                                         numberInProgressItemsOfType:00409e
//                                                                                                         skipNextBuildListItem:004d448f(c),
//                                                                                                         nextBuildableItem:004d4650(c),
//                                                                                                         nextBuildListItemCategory:004d4dd3
//                                                                                                         blockingResource:004d4e52(c),
//                                                                                                         mostNeededResource:004d4fc8(c),
//                                                                                                         allBuilt:004d5c63(c),
//                                                                                                         unskipBuildList:004d5d7f(c),
//                                                                                                         buildItem:004d5e0d(c)
//                              aiblditm.cpp:182 (6)
//         00408530     MOV        EAX,dword ptr [ECX + this->progressValue]
//                              aiblditm.cpp:184 (1)
//         00408536     RET
//         00408537     ??         90h
//         00408538     NOP
//         00408539     NOP
//         0040853a     NOP
//         0040853b     NOP
//         0040853c     NOP
//         0040853d     NOP
//         0040853e     NOP
//         0040853f     NOP
    return 0;
}

int BuildItem::built() {
    /* TODO: Stub */
//                              int __thiscall built(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?built@BuildItem@@QBEHXZ                                     XREF[21]:    save:00409196(c),
//                               BuildItem::built                                                          displayBuildList:00409328(c),
//                                                                                                         numberItemsBuilt:00409b8b(c),
//                                                                                                         numberItemsBuiltOrInProgress:00409
//                                                                                                         numberBuiltItemsOfType:00409d11(c)
//                                                                                                         numberUnbuiltItemsOfType:00409d81(
//                                                                                                         numberBuiltOrInProgressItemsOfType
//                                                                                                         anyBuildListItem:00409f18(c),
//                                                                                                         skipNextBuildListItem:004d4484(c),
//                                                                                                         nextBuildableItem:004d4641(c),
//                                                                                                         nextBuildListItemCategory:004d4dc8
//                                                                                                         blockingResource:004d4e47(c),
//                                                                                                         mostNeededResource:004d4fb9(c),
//                                                                                                         addItem:004d50f8(c),
//                                                                                                         addBuiltItem:004d51b8(c),
//                                                                                                         removeBuiltItem:004d529f(c),
//                                                                                                         insert:004d58e0(c),
//                                                                                                         insertResearch:004d5b13(c),
//                                                                                                         allBuilt:004d5c58(c),
//                                                                                                         unskipBuildList:004d5d73(c), [more]
//                              aiblditm.cpp:189 (6)
//         00408540     MOV        EAX,dword ptr [ECX + this->builtValue]
//                              aiblditm.cpp:191 (1)
//         00408546     RET
//         00408547     ??         90h
//         00408548     NOP
//         00408549     NOP
//         0040854a     NOP
//         0040854b     NOP
//         0040854c     NOP
//         0040854d     NOP
//         0040854e     NOP
//         0040854f     NOP
    return 0;
}

int BuildItem::buildAttempts() {
    /* TODO: Stub */
//                              int __thiscall buildAttempts(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?buildAttempts@BuildItem@@QBEHXZ                             XREF[6]:     save:004091b1(c),
//                               BuildItem::buildAttempts                                                  displayBuildList:00409369(c),
//                                                                                                         displayBuildList:004093db(c),
//                                                                                                         nextBuildableItem:004d4a73(c),
//                                                                                                         nextBuildableItem:004d4aa1(c),
//                                                                                                         nextBuildableItem:004d4b72(c)
//                              aiblditm.cpp:196 (6)
//         00408550     MOV        EAX,dword ptr [ECX + this->buildAttemptsValue]
//                              aiblditm.cpp:198 (1)
//         00408556     RET
//         00408557     ??         90h
//         00408558     NOP
//         00408559     NOP
//         0040855a     NOP
//         0040855b     NOP
//         0040855c     NOP
//         0040855d     NOP
//         0040855e     NOP
//         0040855f     NOP
    return 0;
}

int BuildItem::buildFrom() {
    /* TODO: Stub */
//                              int __thiscall buildFrom(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?buildFrom@BuildItem@@QBEHXZ                                 XREF[7]:     save:004091cc(c),
//                               BuildItem::buildFrom                                                      displayBuildList:00409349(c),
//                                                                                                         displayBuildList:004093bb(c),
//                                                                                                         nextBuildableItem:004d47e9(c),
//                                                                                                         nextBuildableItem:004d4d66(c),
//                                                                                                         taskTrain:004fb587(c),
//                                                                                                         taskResearch:004fb747(c)
//                              aiblditm.cpp:203 (6)
//         00408560     MOV        EAX,dword ptr [ECX + this->buildFromValue]
//                              aiblditm.cpp:205 (1)
//         00408566     RET
//         00408567     ??         90h
//         00408568     NOP
//         00408569     NOP
//         0040856a     NOP
//         0040856b     NOP
//         0040856c     NOP
//         0040856d     NOP
//         0040856e     NOP
//         0040856f     NOP
    return 0;
}

int BuildItem::terrainSet() {
    /* TODO: Stub */
//                              int __thiscall terrainSet(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?terrainSet@BuildItem@@QBEHXZ                                XREF[1]:     save:004091e7(c)
//                               BuildItem::terrainSet
//                              aiblditm.cpp:210 (6)
//         00408570     MOV        EAX,dword ptr [ECX + this->terrainSetValue]
//                              aiblditm.cpp:212 (1)
//         00408576     RET
//         00408577     ??         90h
//         00408578     NOP
//         00408579     NOP
//         0040857a     NOP
//         0040857b     NOP
//         0040857c     NOP
//         0040857d     NOP
//         0040857e     NOP
//         0040857f     NOP
    return 0;
}

int BuildItem::terrainAdjacency(int param_1) {
    /* TODO: Stub */
//                              int __thiscall terrainAdjacency(BuildItem * this, int param_1)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408580(R)
//                               ?terrainAdjacency@BuildItem@@QBEHH@Z                         XREF[2]:     save:00409204(c),
//                               BuildItem::terrainAdjacency                                               save:00409221(c)
//                              aiblditm.cpp:217 (14)
//         00408580     MOV        EAX,dword ptr [ESP + param_1]
//         00408584     CMP        EAX,0x1
//         00408587     JL         LAB_00408598
//         00408589     CMP        EAX,0x2
//         0040858c     JG         LAB_00408598
//                              aiblditm.cpp:220 (7)
//         0040858e     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->terrainSe
//                              aiblditm.cpp:221 (3)
//         00408595     RET        0x4
//                               LAB_00408598                                                 XREF[2]:     00408587(j), 0040858c(j)
//                              aiblditm.cpp:219 (3)
//         00408598     OR         EAX,0xffffffff
//                              aiblditm.cpp:221 (3)
//         0040859b     RET        0x4
//         0040859e     ??         90h
//         0040859f     NOP
    return 0;
}

int BuildItem::placeOnElevation() {
    /* TODO: Stub */
//                              int __thiscall placeOnElevation(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?placeOnElevation@BuildItem@@QBEHXZ                          XREF[1]:     save:0040923c(c)
//                               BuildItem::placeOnElevation
//                              aiblditm.cpp:226 (6)
//         004085a0     MOV        EAX,dword ptr [ECX + this->placeOnElevationVal
//                              aiblditm.cpp:228 (1)
//         004085a6     RET
//         004085a7     ??         90h
//         004085a8     NOP
//         004085a9     NOP
//         004085aa     NOP
//         004085ab     NOP
//         004085ac     NOP
//         004085ad     NOP
//         004085ae     NOP
//         004085af     NOP
    return 0;
}

void BuildItem::setInProgress(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setInProgress(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004085b0(R)
//                               ?setInProgress@BuildItem@@QAEXH@Z                            XREF[15]:    BuildAIModule:00408c54(c),
//                               BuildItem::setInProgress                                                  insertItem:00409ab7(c),
//                                                                                                         nextBuildableItem:004d463a(c),
//                                                                                                         nextBuildableItem:004d4890(c),
//                                                                                                         addItem:004d5120(c),
//                                                                                                         addBuiltItem:004d51d8(c),
//                                                                                                         removeBuiltItem:004d52ac(c),
//                                                                                                         cancelBuildItem:004d5505(c),
//                                                                                                         addTrainedUnit:004d55a8(c),
//                                                                                                         cancelTrainUnit:004d565b(c),
//                                                                                                         addResearch:004d56a8(c),
//                                                                                                         cancelResearch:004d574b(c),
//                                                                                                         taskBuilder:004f9c2d(c),
//                                                                                                         taskTrain:004fb5dd(c),
//                                                                                                         taskResearch:004fb79d(c)
//                              aiblditm.cpp:233 (10)
//         004085b0     MOV        EAX,dword ptr [ESP + param_1]
//         004085b4     MOV        dword ptr [ECX + this->progressValue],EAX
//                              aiblditm.cpp:235 (3)
//         004085ba     RET        0x4
//         004085bd     ??         90h
//         004085be     NOP
//         004085bf     NOP
    return;
}

void BuildItem::setBuilt(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setBuilt(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004085c0(R)
//                               ?setBuilt@BuildItem@@QAEXH@Z                                 XREF[13]:    BuildAIModule:00408c48(c),
//                               BuildItem::setBuilt                                                       insertItem:00409aae(c),
//                                                                                                         nextBuildableItem:004d4624(c),
//                                                                                                         nextBuildableItem:004d4631(c),
//                                                                                                         nextBuildableItem:004d4899(c),
//                                                                                                         addItem:004d5129(c),
//                                                                                                         addBuiltItem:004d51e5(c),
//                                                                                                         removeBuiltItem:004d52b4(c),
//                                                                                                         addTrainedUnit:004d55b1(c),
//                                                                                                         addResearch:004d56b1(c),
//                                                                                                         taskBuilder:004f9c36(c),
//                                                                                                         taskTrain:004fb5e6(c),
//                                                                                                         taskResearch:004fb7a6(c)
//                              aiblditm.cpp:240 (10)
//         004085c0     MOV        EAX,dword ptr [ESP + param_1]
//         004085c4     MOV        dword ptr [ECX + this->builtValue],EAX
//                              aiblditm.cpp:242 (3)
//         004085ca     RET        0x4
//         004085cd     ??         90h
//         004085ce     NOP
//         004085cf     NOP
    return;
}

void BuildItem::setBuildAttempts(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setBuildAttempts(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004085d0(R)
//                               ?setBuildAttempts@BuildItem@@QAEXH@Z                         XREF[9]:     BuildAIModule:00408c60(c),
//                               BuildItem::setBuildAttempts                                               insertItem:00409ac0(c),
//                                                                                                         skipNextBuildListItem:004d44f4(c),
//                                                                                                         nextBuildableItem:004d48df(c),
//                                                                                                         nextBuildableItem:004d4aed(c),
//                                                                                                         nextBuildableItem:004d4c3c(c),
//                                                                                                         nextBuildableItem:004d4c5c(c),
//                                                                                                         removeBuiltItem:004d52c5(c),
//                                                                                                         unskipBuildList:004d5db6(c)
//                              aiblditm.cpp:247 (10)
//         004085d0     MOV        EAX,dword ptr [ESP + param_1]
//         004085d4     MOV        dword ptr [ECX + this->buildAttemptsValue],EAX
//                              aiblditm.cpp:249 (3)
//         004085da     RET        0x4
//         004085dd     ??         90h
//         004085de     NOP
//         004085df     NOP
    return;
}

void BuildItem::incrementBuildAttempts() {
    /* TODO: Stub */
//                              void __thiscall incrementBuildAttempts(BuildItem * this)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?incrementBuildAttempts@BuildItem@@QAEXXZ                    XREF[1]:     nextBuildableItem:004d4b6b(c)
//                               BuildItem::incrementBuildAttempts
//                              aiblditm.cpp:254 (6)
//         004085e0     INC        dword ptr [ECX + this->buildAttemptsValue]
//                              aiblditm.cpp:256 (1)
//         004085e6     RET
//         004085e7     ??         90h
//         004085e8     NOP
//         004085e9     NOP
//         004085ea     NOP
//         004085eb     NOP
//         004085ec     NOP
//         004085ed     NOP
//         004085ee     NOP
//         004085ef     NOP
    return;
}

void BuildItem::decrementBuildAttempts() {
    /* TODO: Stub */
//                              void __thiscall decrementBuildAttempts(BuildItem * this)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?decrementBuildAttempts@BuildItem@@QAEXXZ                    XREF[1]:     nextBuildableItem:004d4a89(c)
//                               BuildItem::decrementBuildAttempts
//                              aiblditm.cpp:261 (13)
//         004085f0     MOV        EAX,dword ptr [ECX + this->buildAttemptsValue]
//         004085f6     DEC        EAX
//         004085f7     MOV        dword ptr [ECX + this->buildAttemptsValue],EAX
//                              aiblditm.cpp:263 (2)
//         004085fd     JNS        LAB_00408609
//                              aiblditm.cpp:264 (10)
//         004085ff     MOV        dword ptr [ECX + this->buildAttemptsValue],0x0
//                               LAB_00408609                                                 XREF[1]:     004085fd(j)
//                              aiblditm.cpp:265 (1)
//         00408609     RET
//         0040860a     ??         90h
//         0040860b     NOP
//         0040860c     NOP
//         0040860d     NOP
//         0040860e     NOP
//         0040860f     NOP
    return;
}

int BuildItem::numberBuilds() {
    /* TODO: Stub */
//                              int __thiscall numberBuilds(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?numberBuilds@BuildItem@@QAEHXZ                              XREF[5]:     save:00409257(c),
//                               BuildItem::numberBuilds                                                   displayBuildList:00409359(c),
//                                                                                                         displayBuildList:004093cb(c),
//                                                                                                         nextBuildableItem:004d483e(c),
//                                                                                                         mostNeededResource:004d4ff3(c)
//                              aiblditm.cpp:270 (6)
//         00408610     MOV        EAX,dword ptr [ECX + this->numberBuildsValue]
//                              aiblditm.cpp:272 (1)
//         00408616     RET
//         00408617     ??         90h
//         00408618     NOP
//         00408619     NOP
//         0040861a     NOP
//         0040861b     NOP
//         0040861c     NOP
//         0040861d     NOP
//         0040861e     NOP
//         0040861f     NOP
    return 0;
}

void BuildItem::incrementNumberBuilds() {
    /* TODO: Stub */
//                              void __thiscall incrementNumberBuilds(BuildItem * this)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?incrementNumberBuilds@BuildItem@@QAEXXZ                     XREF[4]:     addItem:004d5130(c),
//                               BuildItem::incrementNumberBuilds                                          addBuiltItem:004d51f7(c),
//                                                                                                         addTrainedUnit:004d55c4(c),
//                                                                                                         addResearch:004d56b8(c)
//                              aiblditm.cpp:277 (6)
//         00408620     INC        dword ptr [ECX + this->numberBuildsValue]
//                              aiblditm.cpp:279 (1)
//         00408626     RET
//         00408627     ??         90h
//         00408628     NOP
//         00408629     NOP
//         0040862a     NOP
//         0040862b     NOP
//         0040862c     NOP
//         0040862d     NOP
//         0040862e     NOP
//         0040862f     NOP
    return;
}

void BuildItem::setNumberBuilds(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setNumberBuilds(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408630(R)
//                               ?setNumberBuilds@BuildItem@@QAEXH@Z                          XREF[2]:     BuildAIModule:00408ca8(c),
//                               BuildItem::setNumberBuilds                                                insertItem:00409aff(c)
//                              aiblditm.cpp:284 (10)
//         00408630     MOV        EAX,dword ptr [ESP + param_1]
//         00408634     MOV        dword ptr [ECX + this->numberBuildsValue],EAX
//                              aiblditm.cpp:286 (3)
//         0040863a     RET        0x4
//         0040863d     ??         90h
//         0040863e     NOP
//         0040863f     NOP
    return;
}

int BuildItem::buildCap() {
    /* TODO: Stub */
//                              int __thiscall buildCap(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?buildCap@BuildItem@@QAEHXZ                                  XREF[7]:     save:00409272(c),
//                               BuildItem::buildCap                                                       displayBuildList:00409351(c),
//                                                                                                         displayBuildList:004093c3(c),
//                                                                                                         nextBuildableItem:004d4829(c),
//                                                                                                         nextBuildableItem:004d4835(c),
//                                                                                                         mostNeededResource:004d4fe7(c),
//                                                                                                         mostNeededResource:004d4ffc(c)
//                              aiblditm.cpp:291 (6)
//         00408640     MOV        EAX,dword ptr [ECX + this->buildCapValue]
//                              aiblditm.cpp:293 (1)
//         00408646     RET
//         00408647     ??         90h
//         00408648     NOP
//         00408649     NOP
//         0040864a     NOP
//         0040864b     NOP
//         0040864c     NOP
//         0040864d     NOP
//         0040864e     NOP
//         0040864f     NOP
    return 0;
}

void BuildItem::setBuildCap(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setBuildCap(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408650(R)
//                               ?setBuildCap@BuildItem@@QAEXH@Z                              XREF[3]:     BuildAIModule:00408cb4(c),
//                               BuildItem::setBuildCap                                                    loadBuildList:0040976e(c),
//                                                                                                         insertItem:00409b0b(c)
//                              aiblditm.cpp:298 (10)
//         00408650     MOV        EAX,dword ptr [ESP + param_1]
//         00408654     MOV        dword ptr [ECX + this->buildCapValue],EAX
//                              aiblditm.cpp:300 (3)
//         0040865a     RET        0x4
//         0040865d     ??         90h
//         0040865e     NOP
//         0040865f     NOP
    return;
}

int BuildItem::skipCycles() {
    /* TODO: Stub */
//                              int __thiscall skipCycles(BuildItem * this)
//              int               EAX:4          <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?skipCycles@BuildItem@@QAEHXZ                                XREF[4]:     save:0040928d(c),
//                               BuildItem::skipCycles                                                     displayBuildList:00409334(c),
//                                                                                                         displayBuildList:004093a6(c),
//                                                                                                         skipNextBuildListItem:004d4523(c)
//                              aiblditm.cpp:305 (6)
//         00408660     MOV        EAX,dword ptr [ECX + this->skipCyclesValue]
//                              aiblditm.cpp:307 (1)
//         00408666     RET
//         00408667     ??         90h
//         00408668     NOP
//         00408669     NOP
//         0040866a     NOP
//         0040866b     NOP
//         0040866c     NOP
//         0040866d     NOP
//         0040866e     NOP
//         0040866f     NOP
    return 0;
}

void BuildItem::incrementSkipCycles() {
    /* TODO: Stub */
//                              void __thiscall incrementSkipCycles(BuildItem * this)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?incrementSkipCycles@BuildItem@@QAEXXZ                       XREF[1]:     skipNextBuildListItem:004d4504(c)
//                               BuildItem::incrementSkipCycles
//                              aiblditm.cpp:312 (6)
//         00408670     INC        dword ptr [ECX + this->skipCyclesValue]
//                              aiblditm.cpp:314 (1)
//         00408676     RET
//         00408677     ??         90h
//         00408678     NOP
//         00408679     NOP
//         0040867a     NOP
//         0040867b     NOP
//         0040867c     NOP
//         0040867d     NOP
//         0040867e     NOP
//         0040867f     NOP
    return;
}

void BuildItem::setSkipCycles(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setSkipCycles(BuildItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408680(R)
//                               ?setSkipCycles@BuildItem@@QAEXH@Z                            XREF[3]:     BuildAIModule:00408cc0(c),
//                               BuildItem::setSkipCycles                                                  insertItem:00409b14(c),
//                                                                                                         unskipBuildList:004d5dbf(c)
//                              aiblditm.cpp:319 (10)
//         00408680     MOV        EAX,dword ptr [ESP + param_1]
//         00408684     MOV        dword ptr [ECX + this->skipCyclesValue],EAX
//                              aiblditm.cpp:321 (3)
//         0040868a     RET        0x4
//         0040868d     ??         90h
//         0040868e     NOP
//         0040868f     NOP
    return;
}

uchar BuildItem::permanentSkip() {
    /* TODO: Stub */
//                              uchar __thiscall permanentSkip(BuildItem * this)
//              uchar             AL:1           <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//                               ?permanentSkip@BuildItem@@QAEEXZ                             XREF[7]:     save:004092a8(c),
//                               BuildItem::permanentSkip                                                  displayBuildList:0040933c(c),
//                                                                                                         displayBuildList:004093ae(c),
//                                                                                                         nextBuildableItem:004d4a7e(c),
//                                                                                                         nextBuildableItem:004d4ba5(c),
//                                                                                                         nextBuildListItemCategory:004d4dea
//                                                                                                         blockingResource:004d4e69(c)
//                              aiblditm.cpp:326 (6)
//         00408690     MOV        AL,byte ptr [ECX + this->permanentSkipValue]
//                              aiblditm.cpp:328 (1)
//         00408696     RET
//         00408697     ??         90h
//         00408698     NOP
//         00408699     NOP
//         0040869a     NOP
//         0040869b     NOP
//         0040869c     NOP
//         0040869d     NOP
//         0040869e     NOP
//         0040869f     NOP
    return 0;
}

void BuildItem::setPermanentSkip(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setPermanentSkip(BuildItem * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              BuildItem *       ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004086a0(R)
//                               ?setPermanentSkip@BuildItem@@QAEXE@Z                         XREF[4]:     BuildAIModule:00408ccc(c),
//                               BuildItem::setPermanentSkip                                               insertItem:00409b1d(c),
//                                                                                                         skipNextBuildListItem:004d4530(c),
//                                                                                                         unskipBuildList:004d5dc8(c)
//                              aiblditm.cpp:333 (10)
//         004086a0     MOV        AL,byte ptr [ESP + param_1]
//         004086a4     MOV        byte ptr [ECX + this->permanentSkipValue],AL
//                              aiblditm.cpp:335 (3)
//         004086aa     RET        0x4
//         004086ad     ??         90h
//         004086ae     NOP
//         004086af     NOP
    return;
}

