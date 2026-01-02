#include "../common.h"
#include "airesitm.h"

ResourceItem::ResourceItem() {
    /* TODO: Stub */
//                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem
//              undefined         <UNASSIGNED>   <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412055(R)
//                               ??0ResourceItem@@QAE@PAV0@@Z                                 XREF[1]:     TechnologyItem:00412d1e(c)
//                               ResourceItem::ResourceItem
//                              airesitm.cpp:92 (26)
//         00412050     PUSH       EBX
//         00412051     PUSH       ESI
//         00412052     MOV        EAX,this
//         00412054     PUSH       EDI
//         00412055     MOV        this,dword ptr [ESP + param_1]
//         00412059     XOR        EDI,EDI
//         0041205b     MOV        dword ptr [EAX + 0x4],EDI
//         0041205e     MOV        dword ptr [EAX + 0x8],EDI
//         00412061     MOV        EDX,dword ptr [ECX + this->numberValue]
//         00412064     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
//                              airesitm.cpp:93 (20)
//         0041206a     CMP        EDX,EDI
//         0041206c     MOV        dword ptr [EAX + 0x6c],EDX
//         0041206f     JLE        LAB_0041209c
//         00412071     LEA        ESI,[ECX + this->sortedIndexValue[0]]
//         00412074     LEA        EDX,[EAX + 0xc]
//         00412077     SUB        this,EAX
//                               LAB_00412079                                                 XREF[1]:     0041209a(j)
//         00412079     CMP        EDI,0x8
//         0041207c     JGE        LAB_0041209c
//                              airesitm.cpp:94 (6)
//         0041207e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
//         00412081     INC        EDI
//         00412082     MOV        dword ptr [EDX],EBX
//                              airesitm.cpp:95 (6)
//         00412084     MOV        EBX,dword ptr [ESI + -0x20]
//         00412087     MOV        dword ptr [EDX + 0x20],EBX
//                              airesitm.cpp:96 (18)
//         0041208a     MOV        EBX,dword ptr [ESI]
//         0041208c     MOV        dword ptr [EDX + 0x40],EBX
//         0041208f     MOV        EBX,dword ptr [EAX + 0x6c]
//         00412092     ADD        EDX,0x4
//         00412095     ADD        ESI,0x4
//         00412098     CMP        EDI,EBX
//         0041209a     JL         LAB_00412079
//                               LAB_0041209c                                                 XREF[2]:     0041206f(j), 0041207c(j)
//                              airesitm.cpp:98 (6)
//         0041209c     POP        EDI
//         0041209d     POP        ESI
//         0041209e     POP        EBX
//         0041209f     RET        0x4
//         004120a2     ??         90h
//         004120a3     NOP
//         004120a4     NOP
//         004120a5     NOP
//         004120a6     NOP
//         004120a7     NOP
//         004120a8     NOP
//         004120a9     NOP
//         004120aa     NOP
//         004120ab     NOP
//         004120ac     NOP
//         004120ad     NOP
//         004120ae     NOP
//         004120af     NOP
}

ResourceItem::ResourceItem(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem
//              undefined         <UNASSIGNED>   <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412055(R)
//                               ??0ResourceItem@@QAE@PAV0@@Z                                 XREF[1]:     TechnologyItem:00412d1e(c)
//                               ResourceItem::ResourceItem
//                              airesitm.cpp:92 (26)
//         00412050     PUSH       EBX
//         00412051     PUSH       ESI
//         00412052     MOV        EAX,this
//         00412054     PUSH       EDI
//         00412055     MOV        this,dword ptr [ESP + param_1]
//         00412059     XOR        EDI,EDI
//         0041205b     MOV        dword ptr [EAX + 0x4],EDI
//         0041205e     MOV        dword ptr [EAX + 0x8],EDI
//         00412061     MOV        EDX,dword ptr [ECX + this->numberValue]
//         00412064     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
//                              airesitm.cpp:93 (20)
//         0041206a     CMP        EDX,EDI
//         0041206c     MOV        dword ptr [EAX + 0x6c],EDX
//         0041206f     JLE        LAB_0041209c
//         00412071     LEA        ESI,[ECX + this->sortedIndexValue[0]]
//         00412074     LEA        EDX,[EAX + 0xc]
//         00412077     SUB        this,EAX
//                               LAB_00412079                                                 XREF[1]:     0041209a(j)
//         00412079     CMP        EDI,0x8
//         0041207c     JGE        LAB_0041209c
//                              airesitm.cpp:94 (6)
//         0041207e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
//         00412081     INC        EDI
//         00412082     MOV        dword ptr [EDX],EBX
//                              airesitm.cpp:95 (6)
//         00412084     MOV        EBX,dword ptr [ESI + -0x20]
//         00412087     MOV        dword ptr [EDX + 0x20],EBX
//                              airesitm.cpp:96 (18)
//         0041208a     MOV        EBX,dword ptr [ESI]
//         0041208c     MOV        dword ptr [EDX + 0x40],EBX
//         0041208f     MOV        EBX,dword ptr [EAX + 0x6c]
//         00412092     ADD        EDX,0x4
//         00412095     ADD        ESI,0x4
//         00412098     CMP        EDI,EBX
//         0041209a     JL         LAB_00412079
//                               LAB_0041209c                                                 XREF[2]:     0041206f(j), 0041207c(j)
//                              airesitm.cpp:98 (6)
//         0041209c     POP        EDI
//         0041209d     POP        ESI
//         0041209e     POP        EBX
//         0041209f     RET        0x4
//         004120a2     ??         90h
//         004120a3     NOP
//         004120a4     NOP
//         004120a5     NOP
//         004120a6     NOP
//         004120a7     NOP
//         004120a8     NOP
//         004120a9     NOP
//         004120aa     NOP
//         004120ab     NOP
//         004120ac     NOP
//         004120ad     NOP
//         004120ae     NOP
//         004120af     NOP
}

ResourceItem::ResourceItem(int param_1, int* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem
//              undefined         <UNASSIGNED>   <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412055(R)
//                               ??0ResourceItem@@QAE@PAV0@@Z                                 XREF[1]:     TechnologyItem:00412d1e(c)
//                               ResourceItem::ResourceItem
//                              airesitm.cpp:92 (26)
//         00412050     PUSH       EBX
//         00412051     PUSH       ESI
//         00412052     MOV        EAX,this
//         00412054     PUSH       EDI
//         00412055     MOV        this,dword ptr [ESP + param_1]
//         00412059     XOR        EDI,EDI
//         0041205b     MOV        dword ptr [EAX + 0x4],EDI
//         0041205e     MOV        dword ptr [EAX + 0x8],EDI
//         00412061     MOV        EDX,dword ptr [ECX + this->numberValue]
//         00412064     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
//                              airesitm.cpp:93 (20)
//         0041206a     CMP        EDX,EDI
//         0041206c     MOV        dword ptr [EAX + 0x6c],EDX
//         0041206f     JLE        LAB_0041209c
//         00412071     LEA        ESI,[ECX + this->sortedIndexValue[0]]
//         00412074     LEA        EDX,[EAX + 0xc]
//         00412077     SUB        this,EAX
//                               LAB_00412079                                                 XREF[1]:     0041209a(j)
//         00412079     CMP        EDI,0x8
//         0041207c     JGE        LAB_0041209c
//                              airesitm.cpp:94 (6)
//         0041207e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
//         00412081     INC        EDI
//         00412082     MOV        dword ptr [EDX],EBX
//                              airesitm.cpp:95 (6)
//         00412084     MOV        EBX,dword ptr [ESI + -0x20]
//         00412087     MOV        dword ptr [EDX + 0x20],EBX
//                              airesitm.cpp:96 (18)
//         0041208a     MOV        EBX,dword ptr [ESI]
//         0041208c     MOV        dword ptr [EDX + 0x40],EBX
//         0041208f     MOV        EBX,dword ptr [EAX + 0x6c]
//         00412092     ADD        EDX,0x4
//         00412095     ADD        ESI,0x4
//         00412098     CMP        EDI,EBX
//         0041209a     JL         LAB_00412079
//                               LAB_0041209c                                                 XREF[2]:     0041206f(j), 0041207c(j)
//                              airesitm.cpp:98 (6)
//         0041209c     POP        EDI
//         0041209d     POP        ESI
//         0041209e     POP        EBX
//         0041209f     RET        0x4
//         004120a2     ??         90h
//         004120a3     NOP
//         004120a4     NOP
//         004120a5     NOP
//         004120a6     NOP
//         004120a7     NOP
//         004120a8     NOP
//         004120a9     NOP
//         004120aa     NOP
//         004120ab     NOP
//         004120ac     NOP
//         004120ad     NOP
//         004120ae     NOP
//         004120af     NOP
}

ResourceItem::ResourceItem(ResourceItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem
//              undefined         <UNASSIGNED>   <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412055(R)
//                               ??0ResourceItem@@QAE@PAV0@@Z                                 XREF[1]:     TechnologyItem:00412d1e(c)
//                               ResourceItem::ResourceItem
//                              airesitm.cpp:92 (26)
//         00412050     PUSH       EBX
//         00412051     PUSH       ESI
//         00412052     MOV        EAX,this
//         00412054     PUSH       EDI
//         00412055     MOV        this,dword ptr [ESP + param_1]
//         00412059     XOR        EDI,EDI
//         0041205b     MOV        dword ptr [EAX + 0x4],EDI
//         0041205e     MOV        dword ptr [EAX + 0x8],EDI
//         00412061     MOV        EDX,dword ptr [ECX + this->numberValue]
//         00412064     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
//                              airesitm.cpp:93 (20)
//         0041206a     CMP        EDX,EDI
//         0041206c     MOV        dword ptr [EAX + 0x6c],EDX
//         0041206f     JLE        LAB_0041209c
//         00412071     LEA        ESI,[ECX + this->sortedIndexValue[0]]
//         00412074     LEA        EDX,[EAX + 0xc]
//         00412077     SUB        this,EAX
//                               LAB_00412079                                                 XREF[1]:     0041209a(j)
//         00412079     CMP        EDI,0x8
//         0041207c     JGE        LAB_0041209c
//                              airesitm.cpp:94 (6)
//         0041207e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
//         00412081     INC        EDI
//         00412082     MOV        dword ptr [EDX],EBX
//                              airesitm.cpp:95 (6)
//         00412084     MOV        EBX,dword ptr [ESI + -0x20]
//         00412087     MOV        dword ptr [EDX + 0x20],EBX
//                              airesitm.cpp:96 (18)
//         0041208a     MOV        EBX,dword ptr [ESI]
//         0041208c     MOV        dword ptr [EDX + 0x40],EBX
//         0041208f     MOV        EBX,dword ptr [EAX + 0x6c]
//         00412092     ADD        EDX,0x4
//         00412095     ADD        ESI,0x4
//         00412098     CMP        EDI,EBX
//         0041209a     JL         LAB_00412079
//                               LAB_0041209c                                                 XREF[2]:     0041206f(j), 0041207c(j)
//                              airesitm.cpp:98 (6)
//         0041209c     POP        EDI
//         0041209d     POP        ESI
//         0041209e     POP        EBX
//         0041209f     RET        0x4
//         004120a2     ??         90h
//         004120a3     NOP
//         004120a4     NOP
//         004120a5     NOP
//         004120a6     NOP
//         004120a7     NOP
//         004120a8     NOP
//         004120a9     NOP
//         004120aa     NOP
//         004120ab     NOP
//         004120ac     NOP
//         004120ad     NOP
//         004120ae     NOP
//         004120af     NOP
}

ResourceItem::ResourceItem(ResourceItem* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem
//              undefined         <UNASSIGNED>   <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412055(R)
//                               ??0ResourceItem@@QAE@PAV0@@Z                                 XREF[1]:     TechnologyItem:00412d1e(c)
//                               ResourceItem::ResourceItem
//                              airesitm.cpp:92 (26)
//         00412050     PUSH       EBX
//         00412051     PUSH       ESI
//         00412052     MOV        EAX,this
//         00412054     PUSH       EDI
//         00412055     MOV        this,dword ptr [ESP + param_1]
//         00412059     XOR        EDI,EDI
//         0041205b     MOV        dword ptr [EAX + 0x4],EDI
//         0041205e     MOV        dword ptr [EAX + 0x8],EDI
//         00412061     MOV        EDX,dword ptr [ECX + this->numberValue]
//         00412064     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
//                              airesitm.cpp:93 (20)
//         0041206a     CMP        EDX,EDI
//         0041206c     MOV        dword ptr [EAX + 0x6c],EDX
//         0041206f     JLE        LAB_0041209c
//         00412071     LEA        ESI,[ECX + this->sortedIndexValue[0]]
//         00412074     LEA        EDX,[EAX + 0xc]
//         00412077     SUB        this,EAX
//                               LAB_00412079                                                 XREF[1]:     0041209a(j)
//         00412079     CMP        EDI,0x8
//         0041207c     JGE        LAB_0041209c
//                              airesitm.cpp:94 (6)
//         0041207e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
//         00412081     INC        EDI
//         00412082     MOV        dword ptr [EDX],EBX
//                              airesitm.cpp:95 (6)
//         00412084     MOV        EBX,dword ptr [ESI + -0x20]
//         00412087     MOV        dword ptr [EDX + 0x20],EBX
//                              airesitm.cpp:96 (18)
//         0041208a     MOV        EBX,dword ptr [ESI]
//         0041208c     MOV        dword ptr [EDX + 0x40],EBX
//         0041208f     MOV        EBX,dword ptr [EAX + 0x6c]
//         00412092     ADD        EDX,0x4
//         00412095     ADD        ESI,0x4
//         00412098     CMP        EDI,EBX
//         0041209a     JL         LAB_00412079
//                               LAB_0041209c                                                 XREF[2]:     0041206f(j), 0041207c(j)
//                              airesitm.cpp:98 (6)
//         0041209c     POP        EDI
//         0041209d     POP        ESI
//         0041209e     POP        EBX
//         0041209f     RET        0x4
//         004120a2     ??         90h
//         004120a3     NOP
//         004120a4     NOP
//         004120a5     NOP
//         004120a6     NOP
//         004120a7     NOP
//         004120a8     NOP
//         004120a9     NOP
//         004120aa     NOP
//         004120ab     NOP
//         004120ac     NOP
//         004120ad     NOP
//         004120ae     NOP
//         004120af     NOP
}

ResourceItem::~ResourceItem() {
    /* TODO: Stub */
//                              void __thiscall ~ResourceItem(ResourceItem * this)
//              void              <VOID>         <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//                               ??1ResourceItem@@UAE@XZ                                      XREF[15]:    ResearchAIModule:00411907(c),
//                               ResourceItem::~ResourceItem                                               loadTechnologyTree:00411d5c(c),
//                                                                                                         `scalar_deleting_destructor':00411
//                                                                                                         TechnologyItem:00412cad(c),
//                                                                                                         initialize:004d4436(c),
//                                                                                                         nextBuildableItem:004d48d1(c),
//                                                                                                         nextBuildableItem:004d4992(c),
//                                                                                                         nextBuildableItem:004d4a60(c),
//                                                                                                         nextBuildableItem:004d4d8e(c),
//                                                                                                         blockingResource:004d4f3e(c),
//                                                                                                         blockingResource:004d4f66(c),
//                                                                                                         ~TribeTacticalAIModule:004eeb7e(c)
//                                                                                                         checkForBuildInsertion:0050207f(c)
//                                                                                                         FUN_005024b3:00502589(c),
//                                                                                                         FUN_0055c7d0:0055c7d6(c)
//                              airesitm.cpp:103 (6)
//         004120b0     MOV        dword ptr [this->_padding_],ResourceItem::`vft   = 00411ef0
//                              airesitm.cpp:104 (1)
//         004120b6     RET
//         004120b7     ??         90h
//         004120b8     NOP
//         004120b9     NOP
//         004120ba     NOP
//         004120bb     NOP
//         004120bc     NOP
//         004120bd     NOP
//         004120be     NOP
//         004120bf     NOP
}

ResourceItem* ResourceItem::operator+=(ResourceItem* param_1) {
    /* TODO: Stub */
//                              ResourceItem * __thiscall operator+=(ResourceItem * this, ResourceIt
//              ResourceItem *    EAX:4          <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     004120c3(R)
//                               ??YResourceItem@@QAEAAV0@ABV0@@Z
//                               ResourceItem::operator+=
//                              airesitm.cpp:109 (3)
//         004120c0     MOV        EAX,this
//         004120c2     PUSH       ESI
//                              airesitm.cpp:110 (12)
//         004120c3     MOV        this,dword ptr [ESP + param_1]
//         004120c7     MOV        EDX,dword ptr [EAX + 0x6c]
//         004120ca     CMP        EDX,dword ptr [ECX + this->numberValue]
//         004120cd     JNZ        LAB_004120f2
//                              airesitm.cpp:111 (8)
//         004120cf     XOR        ESI,ESI
//         004120d1     TEST       EDX,EDX
//         004120d3     JLE        LAB_004120f2
//         004120d5     PUSH       EDI
//         004120d6     PUSH       EBX
//                              airesitm.cpp:115 (31)
//         004120d7     LEA        EDX,[EAX + 0xc]
//         004120da     SUB        this,EAX
//                               LAB_004120dc                                                 XREF[1]:     004120ee(j)
//         004120dc     MOV        EDI,dword ptr [this->_padding_ + EDX*0x1]
//         004120df     MOV        EBX,dword ptr [EDX]
//         004120e1     ADD        EBX,EDI
//         004120e3     INC        ESI
//         004120e4     MOV        dword ptr [EDX],EBX
//         004120e6     MOV        EDI,dword ptr [EAX + 0x6c]
//         004120e9     ADD        EDX,0x4
//         004120ec     CMP        ESI,EDI
//         004120ee     JL         LAB_004120dc
//         004120f0     POP        EBX
//         004120f1     POP        EDI
//                               LAB_004120f2                                                 XREF[2]:     004120cd(j), 004120d3(j)
//         004120f2     POP        ESI
//         004120f3     RET        0x4
//         004120f6     ??         90h
//         004120f7     NOP
//         004120f8     NOP
//         004120f9     NOP
//         004120fa     NOP
//         004120fb     NOP
//         004120fc     NOP
//         004120fd     NOP
//         004120fe     NOP
//         004120ff     NOP
    return 0;
}

int ResourceItem::value(int param_1) {
    /* TODO: Stub */
//                              int __thiscall value(ResourceItem * this, int param_1)
//              int               EAX:4          <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00412180(R)
//                               ?value@ResourceItem@@QBEHH@Z                                 XREF[17]:    save:00411afa(c),
//                               ResourceItem::value                                                       resourcesAvailable:004125fc(c),
//                                                                                                         unavailableResource:00412674(c),
//                                                                                                         setResources:0041279c(c),
//                                                                                                         incrementResources:0041284c(c),
//                                                                                                         decrementResources:004128fc(c),
//                                                                                                         initialize:004d43b4(c),
//                                                                                                         initialize:004d43d1(c),
//                                                                                                         resourcesAvailable:004e6cee(c),
//                                                                                                         unavailableResource:004e6d85(c),
//                                                                                                         save:004eff34(c),
//                                                                                                         neededResourceAmount:004f61bb(c),
//                                                                                                         updateNeededResources:004f8cc3(c),
//                                                                                                         updateNeededResources:004f8d6d(c),
//                                                                                                         requiredGatherAmount:00501ad5(c),
//                                                                                                         checkForBuildInsertion:00501de1(c)
//                                                                                                         checkForBuildInsertion:00501fb7(c)
//                              airesitm.cpp:146 (13)
//         00412180     MOV        EAX,dword ptr [ESP + param_1]
//         00412184     TEST       EAX,EAX
//         00412186     JL         LAB_00412194
//         00412188     CMP        EAX,dword ptr [ECX + this->numberValue]
//         0041218b     JGE        LAB_00412194
//                              airesitm.cpp:149 (4)
//         0041218d     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->valueValu
//                              airesitm.cpp:150 (3)
//         00412191     RET        0x4
//                               LAB_00412194                                                 XREF[2]:     00412186(j), 0041218b(j)
//                              airesitm.cpp:148 (3)
//         00412194     OR         EAX,0xffffffff
//                              airesitm.cpp:150 (3)
//         00412197     RET        0x4
//         0041219a     ??         90h
//         0041219b     NOP
//         0041219c     NOP
//         0041219d     NOP
//         0041219e     NOP
//         0041219f     NOP
    return 0;
}

void ResourceItem::setValue(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setValue(ResourceItem * this, int param_1, int param
//              void              <VOID>         <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004121a0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004121ad(R)
//                               ?setValue@ResourceItem@@QAEXHH@Z                             XREF[3]:     TribeTacticalAIModule:004ee7a8(c),
//                               ResourceItem::setValue                                                    checkForBuildInsertion:00501def(c)
//                                                                                                         checkForBuildInsertion:00501fc5(c)
//                              airesitm.cpp:155 (13)
//         004121a0     MOV        EAX,dword ptr [ESP + param_1]
//         004121a4     TEST       EAX,EAX
//         004121a6     JL         LAB_004121b5
//         004121a8     CMP        EAX,dword ptr [ECX + this->numberValue]
//         004121ab     JGE        LAB_004121b5
//                              airesitm.cpp:158 (8)
//         004121ad     MOV        EDX,dword ptr [ESP + param_2]
//         004121b1     MOV        dword ptr [ECX + EAX*0x4 + this->valueValue[0]
//                               LAB_004121b5                                                 XREF[2]:     004121a6(j), 004121ab(j)
//                              airesitm.cpp:159 (3)
//         004121b5     RET        0x8
//         004121b8     ??         90h
//         004121b9     NOP
//         004121ba     NOP
//         004121bb     NOP
//         004121bc     NOP
//         004121bd     NOP
//         004121be     NOP
//         004121bf     NOP
    return;
}

void ResourceItem::incrementValue(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall incrementValue(ResourceItem * this, int param_1, int
//              void              <VOID>         <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004121c0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004121cd(R)
//                               ?incrementValue@ResourceItem@@QAEXHH@Z                       XREF[6]:     objectCost:00514555(c),
//                               ResourceItem::incrementValue                                              objectCost:00514568(c),
//                                                                                                         objectCost:0051457b(c),
//                                                                                                         researchCost:00514624(c),
//                                                                                                         researchCost:00514637(c),
//                                                                                                         researchCost:0051464a(c)
//                              airesitm.cpp:164 (13)
//         004121c0     MOV        EAX,dword ptr [ESP + param_1]
//         004121c4     TEST       EAX,EAX
//         004121c6     JL         LAB_004121dd
//         004121c8     CMP        EAX,dword ptr [ECX + this->numberValue]
//         004121cb     JGE        LAB_004121dd
//                              airesitm.cpp:167 (16)
//         004121cd     MOV        EDX,dword ptr [ESP + param_2]
//         004121d1     PUSH       ESI
//         004121d2     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->valueValu
//         004121d6     ADD        ESI,EDX
//         004121d8     MOV        dword ptr [ECX + EAX*0x4 + this->valueValue[0]
//         004121dc     POP        ESI
//                               LAB_004121dd                                                 XREF[2]:     004121c6(j), 004121cb(j)
//                              airesitm.cpp:168 (3)
//         004121dd     RET        0x8
    return;
}

void ResourceItem::setAllValues(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setAllValues(ResourceItem * this, int param_1)
//              void              <VOID>         <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004121e0(R)
//                               ?setAllValues@ResourceItem@@QAEXH@Z                          XREF[3]:     initialize:004d4310(c),
//                               ResourceItem::setAllValues                                                initialize:004d43f3(c),
//                                                                                                         mostNeededResource:004d4f8e(c)
//                              airesitm.cpp:173 (15)
//         004121e0     MOV        EAX,dword ptr [ESP + param_1]
//         004121e4     PUSH       EDI
//         004121e5     LEA        EDI,[ECX + this->valueValue[0]]
//         004121e8     MOV        this,0x8
//         004121ed     STOSD.REP  ES:EDI
//                              airesitm.cpp:176 (4)
//         004121ef     POP        EDI
//         004121f0     RET        0x4
//         004121f3     ??         90h
//         004121f4     NOP
//         004121f5     NOP
//         004121f6     NOP
//         004121f7     NOP
//         004121f8     NOP
//         004121f9     NOP
//         004121fa     NOP
//         004121fb     NOP
//         004121fc     NOP
//         004121fd     NOP
//         004121fe     NOP
//         004121ff     NOP
    return;
}

int ResourceItem::number() {
    /* TODO: Stub */
//                              int __thiscall number(ResourceItem * this)
//              int               EAX:4          <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//                               ?number@ResourceItem@@QBEHXZ                                 XREF[21]:    resourcesAvailable:004125d7(c),
//                               ResourceItem::number                                                      resourcesAvailable:004125f0(c),
//                                                                                                         resourcesAvailable:0041260f(c),
//                                                                                                         unavailableResource:00412657(c),
//                                                                                                         unavailableResource:00412668(c),
//                                                                                                         unavailableResource:00412687(c),
//                                                                                                         setResources:0041277f(c),
//                                                                                                         setResources:00412790(c),
//                                                                                                         setResources:004127ad(c),
//                                                                                                         incrementResources:0041282f(c),
//                                                                                                         incrementResources:00412840(c),
//                                                                                                         incrementResources:0041285d(c),
//                                                                                                         decrementResources:004128df(c),
//                                                                                                         decrementResources:004128f0(c),
//                                                                                                         decrementResources:0041290d(c),
//                                                                                                         resourcesAvailable:004e6cb9(c),
//                                                                                                         resourcesAvailable:004e6cd3(c),
//                                                                                                         resourcesAvailable:004e6d09(c),
//                                                                                                         unavailableResource:004e6d59(c),
//                                                                                                         unavailableResource:004e6d6a(c),
//                                                                                                         [more]
//                              airesitm.cpp:181 (3)
//         00412200     MOV        EAX,dword ptr [ECX + this->numberValue]
//                              airesitm.cpp:183 (1)
//         00412203     RET
//         00412204     ??         90h
//         00412205     NOP
//         00412206     NOP
//         00412207     NOP
//         00412208     NOP
//         00412209     NOP
//         0041220a     NOP
//         0041220b     NOP
//         0041220c     NOP
//         0041220d     NOP
//         0041220e     NOP
//         0041220f     NOP
    return 0;
}

int ResourceItem::largestValueIndex(int param_1) {
    /* TODO: Stub */
//                              int __thiscall largestValueIndex(ResourceItem * this, int param_1)
//              int               EAX:4          <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00412214(R)
//                               ?largestValueIndex@ResourceItem@@QAEHH@Z
//                               ResourceItem::largestValueIndex
//                              airesitm.cpp:188 (4)
//         00412210     PUSH       ESI
//         00412211     MOV        ESI,this
//         00412213     PUSH       EDI
//                              airesitm.cpp:190 (7)
//         00412214     MOV        EDI,dword ptr [ESP + param_1]
//         00412218     CMP        dword ptr [ESI + 0x6c],EDI
//                              airesitm.cpp:191 (2)
//         0041221b     JL         LAB_00412230
//                              airesitm.cpp:192 (10)
//         0041221d     CALL       ResourceItem::sortLarge                          int sortLarge(ResourceItem * this)
//         00412222     CMP        EAX,0x1
//         00412225     JNZ        LAB_00412230
//                              airesitm.cpp:193 (4)
//         00412227     MOV        EAX,dword ptr [ESI + EDI*0x4 + 0x48]
//                              airesitm.cpp:195 (13)
//         0041222b     POP        EDI
//         0041222c     POP        ESI
//         0041222d     RET        0x4
//                               LAB_00412230                                                 XREF[2]:     0041221b(j), 00412225(j)
//         00412230     POP        EDI
//         00412231     OR         EAX,0xffffffff
//         00412234     POP        ESI
//         00412235     RET        0x4
//         00412238     ??         90h
//         00412239     NOP
//         0041223a     NOP
//         0041223b     NOP
//         0041223c     NOP
//         0041223d     NOP
//         0041223e     NOP
//         0041223f     NOP
    return 0;
}

int ResourceItem::sortLarge() {
    /* TODO: Stub */
//                              int __thiscall sortLarge(ResourceItem * this)
//              int               EAX:4          <RETURN>
//              ResourceItem *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041228c(W), 004122c5(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00412281(W), 00412292(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0041226d(W), 004122c9(R), 004122f5(W)
//              int               Stack[-0x10]:4 i                         XREF[4]:     0041229b(W), 0041229f(R), 004122b5(R), 004122bf(W)
//                               ?sortLarge@ResourceItem@@IAEHXZ                              XREF[1]:     largestValueIndex:0041221d(c)
//                               ResourceItem::sortLarge
//                              airesitm.cpp:200 (19)
//         00412240     MOV        EAX,dword ptr [ECX + this->numberValue]
//         00412243     SUB        ESP,0x10
//         00412246     XOR        EDX,EDX
//         00412248     PUSH       EBX
//         00412249     PUSH       EBP
//         0041224a     PUSH       ESI
//         0041224b     PUSH       EDI
//         0041224c     TEST       EAX,EAX
//         0041224e     JLE        LAB_00412266
//         00412250     LEA        EAX,[ECX + this->sortedValue[0]]
//                               LAB_00412253                                                 XREF[1]:     00412264(j)
//                              airesitm.cpp:203 (5)
//         00412253     MOV        ESI,dword ptr [EAX + -0x20]
//         00412256     MOV        dword ptr [EAX],ESI
//                              airesitm.cpp:204 (14)
//         00412258     MOV        dword ptr [EAX + 0x20],EDX
//         0041225b     MOV        ESI,dword ptr [ECX + this->numberValue]
//         0041225e     INC        EDX
//         0041225f     ADD        EAX,0x4
//         00412262     CMP        EDX,ESI
//         00412264     JL         LAB_00412253
//                               LAB_00412266                                                 XREF[1]:     0041224e(j)
//                              airesitm.cpp:216 (34)
//         00412266     MOV        EDI,dword ptr [ECX + this->numberValue]
//         00412269     XOR        EBX,EBX
//         0041226b     TEST       EDI,EDI
//         0041226d     MOV        dword ptr [ESP + local_c],EBX
//         00412271     JLE        LAB_004122fb
//         00412277     MOV        EAX,0xffffffd4
//         0041227c     LEA        ESI,[ECX + this->sortedValue[0]]
//         0041227f     SUB        EAX,this
//         00412281     MOV        dword ptr [ESP + local_8],EAX
//                               LAB_00412285                                                 XREF[1]:     004122f9(j)
//         00412285     LEA        EAX,[EBX + 0x1]
//                              airesitm.cpp:226 (2)
//         00412288     MOV        EDX,EBX
//                              airesitm.cpp:227 (21)
//         0041228a     CMP        EAX,EDI
//         0041228c     MOV        dword ptr [ESP + local_4],EAX
//         00412290     JGE        LAB_004122cd
//         00412292     MOV        EBX,dword ptr [ESP + local_8]
//         00412296     LEA        EBP,[ESI + 0x4]
//         00412299     ADD        EBX,ESI
//         0041229b     MOV        dword ptr [ESP + i],EBP
//                               LAB_0041229f                                                 XREF[1]:     004122c3(j)
//                              airesitm.cpp:237 (13)
//         0041229f     MOV        EBP,dword ptr [ESP + i]
//         004122a3     MOV        EBP,dword ptr [EBP]
//         004122a6     CMP        EBP,dword ptr [ECX + EBX*0x1 + this->sortedVal
//         004122aa     JLE        LAB_004122b5
//                              airesitm.cpp:246 (33)
//         004122ac     MOV        EDX,EAX
//         004122ae     LEA        EBX,[EAX*0x4 + 0x0]
//                               LAB_004122b5                                                 XREF[1]:     004122aa(j)
//         004122b5     MOV        EBP,dword ptr [ESP + i]
//         004122b9     INC        EAX
//         004122ba     ADD        EBP,0x4
//         004122bd     CMP        EAX,EDI
//         004122bf     MOV        dword ptr [ESP + i],EBP
//         004122c3     JL         LAB_0041229f
//         004122c5     MOV        EAX,dword ptr [ESP + local_4]
//         004122c9     MOV        EBX,dword ptr [ESP + local_c]
//                               LAB_004122cd                                                 XREF[1]:     00412290(j)
//                              airesitm.cpp:254 (4)
//         004122cd     CMP        EDX,EBX
//         004122cf     JZ         LAB_004122eb
//                              airesitm.cpp:265 (8)
//         004122d1     MOV        EBX,dword ptr [ECX + EDX*0x4 + this->sortedVal
//         004122d5     MOV        EDI,dword ptr [ESI]
//         004122d7     MOV        dword ptr [ESI],EBX
//                              airesitm.cpp:266 (4)
//         004122d9     MOV        dword ptr [ECX + EDX*0x4 + this->sortedValue[0
//                              airesitm.cpp:286 (10)
//         004122dd     MOV        EBX,dword ptr [ECX + EDX*0x4 + this->sortedInd
//         004122e1     MOV        EDI,dword ptr [ESI + 0x20]
//         004122e4     MOV        dword ptr [ESI + 0x20],EBX
//                              airesitm.cpp:296 (20)
//         004122e7     MOV        dword ptr [ECX + EDX*0x4 + this->sortedIndexVa
//                               LAB_004122eb                                                 XREF[1]:     004122cf(j)
//         004122eb     MOV        EDI,dword ptr [ECX + this->numberValue]
//         004122ee     MOV        EBX,EAX
//         004122f0     ADD        ESI,0x4
//         004122f3     CMP        EBX,EDI
//         004122f5     MOV        dword ptr [ESP + local_c],EBX
//         004122f9     JL         LAB_00412285
//                               LAB_004122fb                                                 XREF[1]:     00412271(j)
//                              airesitm.cpp:327 (13)
//         004122fb     POP        EDI
//         004122fc     POP        ESI
//         004122fd     POP        EBP
//         004122fe     MOV        EAX,0x1
//         00412303     POP        EBX
//         00412304     ADD        ESP,0x10
//         00412307     RET
//         00412308     ??         90h
//         00412309     NOP
//         0041230a     NOP
//         0041230b     NOP
//         0041230c     NOP
//         0041230d     NOP
//         0041230e     NOP
//         0041230f     NOP
    return 0;
}

