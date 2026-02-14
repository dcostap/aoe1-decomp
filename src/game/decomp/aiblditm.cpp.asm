// Auto-generated scaffold unit: aiblditm.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aiblditm.cpp
#include "../include/common.h"

// Offset: 0x00408190
undefined BuildItem(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BuildItem::BuildItem(void)                                                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BuildItem(BuildItem * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ??0BuildItem@@QAE@XZ                                         XREF[2]:     BuildAIModule:004086f8(c), 
    //                               BuildItem::BuildItem                                                      BuildAIModule:00408891(c)  
    //                              aiblditm.cpp:36 (94)
    //         00408190     PUSH       ESI
    //         00408191     MOV        ESI,this
    //         00408193     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this)
    //         00408198     XOR        EAX,EAX
    //         0040819a     OR         this,0xffffffff
    //         0040819d     MOV        dword ptr [ESI + 0x6c],EAX
    //         004081a0     MOV        dword ptr [ESI + 0x70],EAX
    //         004081a3     MOV        dword ptr [ESI + 0x78],EAX
    //         004081a6     MOV        dword ptr [ESI + 0x7c],EAX
    //         004081a9     MOV        dword ptr [ESI + 0x80],EAX
    //         004081af     MOV        dword ptr [ESI + 0x84],EAX
    //         004081b5     MOV        dword ptr [ESI + 0x88],EAX
    //         004081bb     MOV        dword ptr [ESI + 0x9c],EAX
    //         004081c1     MOV        dword ptr [ESI + 0xa0],EAX
    //         004081c7     MOV        dword ptr [ESI + 0xa8],EAX
    //         004081cd     MOV        byte ptr [ESI + 0xac],AL
    //         004081d3     MOV        dword ptr [ESI + 0x74],this
    //         004081d6     MOV        dword ptr [ESI + 0x8c],this
    //         004081dc     MOV        dword ptr [ESI + 0x90],this
    //         004081e2     MOV        dword ptr [ESI + 0xa4],this
    //         004081e8     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
    //                              aiblditm.cpp:37 (6)
    //         004081ee     MOV        dword ptr [ESI + 0x94],this
    //                              aiblditm.cpp:38 (6)
    //         004081f4     MOV        dword ptr [ESI + 0x98],this
    //                              aiblditm.cpp:39 (4)
    //         004081fa     MOV        EAX,ESI
    //         004081fc     POP        ESI
    //         004081fd     RET
}

// Offset: 0x00408220
undefined BuildItem(BuildItem* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, char* param_8, float param_9, float param_10, float param_11, int param_12, int param_13, int param_14, int param_15) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BuildItem::BuildItem(int,int,int,int,int,int,char *,float,float,float,int,int,i... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BuildItem(BuildItem * this, int param_1, int pa
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00408259(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040823a(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00408235(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040825d(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00408264(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040826d(R)  
    //              char *            Stack[0x1c]:4  param_7                   XREF[1]:     00408230(R)  
    //              float             Stack[0x20]:4  param_8                   XREF[1]:     00408224(R)  
    //              float             Stack[0x24]:4  param_9                   XREF[1]:     0040822b(R)  
    //              float             Stack[0x28]:4  param_10                  XREF[1]:     00408220(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[1]:     00408274(R)  
    //              int               Stack[0x30]:4  param_12                  XREF[1]:     004082a2(R)  
    //              int               Stack[0x34]:4  param_13                  XREF[1]:     004082b6(R)  
    //              int               Stack[0x38]:4  param_14                  XREF[1]:     004082ac(R)  
    //                               ??0BuildItem@@QAE@HHHHHHPADMMMHHHH@Z                         XREF[3]:     BuildAIModule:00408c2e(c), 
    //                               BuildItem::BuildItem                                                      loadBuildList:00409733(c), 
    //                                                                                                         insertItem:00409a93(c)  
    //                              aiblditm.cpp:63 (130)
    //         00408220     MOV        EAX,dword ptr [ESP + param_10]
    //         00408224     MOV        EDX,dword ptr [ESP + param_8]
    //         00408228     PUSH       ESI
    //         00408229     MOV        ESI,this
    //         0040822b     MOV        this,dword ptr [ESP + param_9]
    //         0040822f     PUSH       EAX
    //         00408230     MOV        EAX,dword ptr [ESP + param_7]
    //         00408234     PUSH       this
    //         00408235     MOV        this,dword ptr [ESP + param_3]
    //         00408239     PUSH       EDX
    //         0040823a     MOV        EDX,dword ptr [ESP + param_2]
    //         0040823e     PUSH       0xbf800000
    //         00408243     PUSH       0xbf800000
    //         00408248     PUSH       0xbf800000
    //         0040824d     PUSH       EAX
    //         0040824e     PUSH       this
    //         0040824f     PUSH       -0x1
    //         00408251     PUSH       EDX
    //         00408252     MOV        this,ESI
    //         00408254     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, int param
    //         00408259     MOV        this,dword ptr [ESP + param_1]
    //         0040825d     MOV        EDX,dword ptr [ESP + param_4]
    //         00408261     MOV        dword ptr [ESI + 0x74],this
    //         00408264     MOV        this,dword ptr [ESP + param_5]
    //         00408268     XOR        EAX,EAX
    //         0040826a     MOV        dword ptr [ESI + 0x78],EDX
    //         0040826d     MOV        EDX,dword ptr [ESP + param_6]
    //         00408271     MOV        dword ptr [ESI + 0x7c],this
    //         00408274     MOV        this,dword ptr [ESP + param_11]
    //         00408278     MOV        dword ptr [ESI + 0x6c],EAX
    //         0040827b     MOV        dword ptr [ESI + 0x70],EAX
    //         0040827e     MOV        dword ptr [ESI + 0x80],EAX
    //         00408284     MOV        dword ptr [ESI + 0x84],EAX
    //         0040828a     MOV        dword ptr [ESI + 0x88],EAX
    //         00408290     MOV        dword ptr [ESI + 0xa0],EAX
    //         00408296     MOV        dword ptr [ESI + 0xa8],EAX
    //         0040829c     MOV        byte ptr [ESI + 0xac],AL
    //                              aiblditm.cpp:64 (20)
    //         004082a2     MOV        EAX,dword ptr [ESP + param_12]
    //         004082a6     MOV        dword ptr [ESI + 0x8c],EDX
    //         004082ac     MOV        EDX,dword ptr [ESP + param_14]
    //         004082b0     MOV        dword ptr [ESI + 0x90],this
    //                              aiblditm.cpp:65 (38)
    //         004082b6     MOV        this,dword ptr [ESP + param_13]
    //         004082ba     MOV        dword ptr [ESI + 0x94],EAX
    //         004082c0     MOV        dword ptr [ESI + 0x9c],EDX
    //         004082c6     MOV        dword ptr [ESI + 0xa4],0xffffffff
    //         004082d0     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
    //         004082d6     MOV        dword ptr [ESI + 0x98],this
    //                              aiblditm.cpp:66 (6)
    //         004082dc     MOV        EAX,ESI
    //         004082de     POP        ESI
    //         004082df     RET        0x38
}

// Offset: 0x004082F0
undefined BuildItem(BuildItem* this_, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BuildItem::BuildItem(class BuildItem *)                                            *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BuildItem(BuildItem * this, BuildItem * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004082f2(R)  
    //                               ??0BuildItem@@QAE@PAV0@@Z
    //                               BuildItem::BuildItem
    //                              aiblditm.cpp:87 (146)
    //         004082f0     PUSH       ESI
    //         004082f1     PUSH       EDI
    //         004082f2     MOV        EDI,dword ptr [ESP + param_1]
    //         004082f6     MOV        ESI,this
    //         004082f8     PUSH       EDI
    //         004082f9     CALL       BaseItem::BaseItem                               undefined BaseItem(BaseItem * this, BaseItem 
    //         004082fe     XOR        EAX,EAX
    //         00408300     MOV        dword ptr [ESI + 0x6c],EAX
    //         00408303     MOV        dword ptr [ESI + 0x70],EAX
    //         00408306     MOV        this,dword ptr [EDI + 0x74]
    //         00408309     MOV        dword ptr [ESI + 0x74],this
    //         0040830c     MOV        EDX,dword ptr [EDI + 0x78]
    //         0040830f     MOV        dword ptr [ESI + 0x78],EDX
    //         00408312     MOV        this,dword ptr [EDI + 0x7c]
    //         00408315     MOV        dword ptr [ESI + 0x7c],this
    //         00408318     MOV        EDX,dword ptr [EDI + 0x80]
    //         0040831e     MOV        dword ptr [ESI + 0x80],EDX
    //         00408324     MOV        this,dword ptr [EDI + 0x80]
    //         0040832a     MOV        dword ptr [ESI + 0x84],this
    //         00408330     MOV        EDX,dword ptr [EDI + 0x88]
    //         00408336     MOV        dword ptr [ESI + 0x88],EDX
    //         0040833c     MOV        this,dword ptr [EDI + 0x8c]
    //         00408342     MOV        dword ptr [ESI + 0x8c],this
    //         00408348     MOV        EDX,dword ptr [EDI + 0x90]
    //         0040834e     MOV        dword ptr [ESI + 0x90],EDX
    //         00408354     MOV        this,dword ptr [EDI + 0x9c]
    //         0040835a     MOV        dword ptr [ESI + 0x9c],this
    //         00408360     MOV        dword ptr [ESI + 0xa0],EAX
    //         00408366     MOV        dword ptr [ESI + 0xa4],0xffffffff
    //         00408370     MOV        dword ptr [ESI + 0xa8],EAX
    //         00408376     MOV        byte ptr [ESI + 0xac],AL
    //         0040837c     MOV        dword ptr [ESI],BuildItem::`vftable'             = 00408200
    //                              aiblditm.cpp:88 (12)
    //         00408382     MOV        EDX,dword ptr [EDI + 0x94]
    //         00408388     MOV        dword ptr [ESI + 0x94],EDX
    //                              aiblditm.cpp:89 (12)
    //         0040838e     MOV        EAX,dword ptr [EDI + 0x98]
    //         00408394     MOV        dword ptr [ESI + 0x98],EAX
    //                              aiblditm.cpp:90 (7)
    //         0040839a     MOV        EAX,ESI
    //         0040839c     POP        EDI
    //         0040839d     POP        ESI
    //         0040839e     RET        0x4
}

// Offset: 0x004083B0
undefined BuildItem(BuildItem* this_, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BuildItem::BuildItem(class BuildItem const &)                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408470
void BuildItem(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall BuildItem::~BuildItem(void)                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408480
int operator(BuildItem* param_1, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class BuildItem const &,class BuildItem const &)                               *
    //                              *********************************************************************************************************
    //                              int __cdecl operator==(BuildItem * param_1, BuildItem * param_2)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     00408480(R)  
    //              BuildItem *       Stack[0x8]:4   param_2                   XREF[1]:     00408484(R)  
    //                               ??8@YAHABVBuildItem@@0@Z
    //                               operator==
    //                              aiblditm.cpp:125 (22)
    //         00408480     MOV        EAX,dword ptr [ESP + param_1]
    //         00408484     MOV        EDX,dword ptr [ESP + param_2]
    //         00408488     PUSH       ESI
    //         00408489     MOV        ECX,dword ptr [EAX + 0x4]
    //         0040848c     MOV        ESI,dword ptr [EDX + 0x4]
    //         0040848f     XOR        EAX,EAX
    //         00408491     CMP        ECX,ESI
    //         00408493     SETZ       AL
    //                              aiblditm.cpp:129 (2)
    //         00408496     POP        ESI
    //         00408497     RET
}

// Offset: 0x004084A0
int operator(BuildItem* param_1, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class BuildItem const &,class BuildItem const &)                               *
    //                              *********************************************************************************************************
    //                              int __cdecl operator!=(BuildItem * param_1, BuildItem * param_2)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004084a0(R)  
    //              BuildItem *       Stack[0x8]:4   param_2                   XREF[1]:     004084a4(R)  
    //                               ??9@YAHABVBuildItem@@0@Z
    //                               operator!=
    //                              aiblditm.cpp:134 (22)
    //         004084a0     MOV        EAX,dword ptr [ESP + param_1]
    //         004084a4     MOV        EDX,dword ptr [ESP + param_2]
    //         004084a8     PUSH       ESI
    //         004084a9     MOV        ECX,dword ptr [EAX + 0x4]
    //         004084ac     MOV        ESI,dword ptr [EDX + 0x4]
    //         004084af     XOR        EAX,EAX
    //         004084b1     CMP        ECX,ESI
    //         004084b3     SETNZ      AL
    //                              aiblditm.cpp:138 (2)
    //         004084b6     POP        ESI
    //         004084b7     RET
}

// Offset: 0x004084C0
int operator(BuildItem* param_1, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator<(class BuildItem const &,class BuildItem const &)                                *
    //                              *********************************************************************************************************
    //                              int __cdecl operator<(BuildItem * param_1, BuildItem * param_2)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004084c0(R)  
    //              BuildItem *       Stack[0x8]:4   param_2                   XREF[1]:     004084c4(R)  
    //                               ??M@YAHABVBuildItem@@0@Z
    //                               operator<
    //                              aiblditm.cpp:143 (22)
    //         004084c0     MOV        EAX,dword ptr [ESP + param_1]
    //         004084c4     MOV        EDX,dword ptr [ESP + param_2]
    //         004084c8     PUSH       ESI
    //         004084c9     MOV        ECX,dword ptr [EAX + 0x4]
    //         004084cc     MOV        ESI,dword ptr [EDX + 0x4]
    //         004084cf     XOR        EAX,EAX
    //         004084d1     CMP        ECX,ESI
    //         004084d3     SETL       AL
    //                              aiblditm.cpp:147 (2)
    //         004084d6     POP        ESI
    //         004084d7     RET
}

// Offset: 0x004084E0
int operator(BuildItem* param_1, BuildItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator>(class BuildItem const &,class BuildItem const &)                                *
    //                              *********************************************************************************************************
    //                              int __cdecl operator>(BuildItem * param_1, BuildItem * param_2)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       Stack[0x4]:4   param_1                   XREF[1]:     004084e0(R)  
    //              BuildItem *       Stack[0x8]:4   param_2                   XREF[1]:     004084e4(R)  
    //                               ??O@YAHABVBuildItem@@0@Z
    //                               operator>
    //                              aiblditm.cpp:152 (22)
    //         004084e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004084e4     MOV        EDX,dword ptr [ESP + param_2]
    //         004084e8     PUSH       ESI
    //         004084e9     MOV        ECX,dword ptr [EAX + 0x4]
    //         004084ec     MOV        ESI,dword ptr [EDX + 0x4]
    //         004084ef     XOR        EAX,EAX
    //         004084f1     CMP        ECX,ESI
    //         004084f3     SETG       AL
    //                              aiblditm.cpp:156 (2)
    //         004084f6     POP        ESI
    //         004084f7     RET
}

// Offset: 0x00408500
int buildCategory(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::buildCategory(void)const                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408510
int number(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::number(void)const                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall number(BuildItem * this)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?number@BuildItem@@QBEHXZ
    //                               BuildItem::number
    //                              aiblditm.cpp:168 (3)
    //         00408510     MOV        EAX,dword ptr [ECX + this->numberValue]
    //                              aiblditm.cpp:170 (1)
    //         00408513     RET
}

// Offset: 0x00408520
int priority(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::priority(void)const                                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall priority(BuildItem * this)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?priority@BuildItem@@QBEHXZ
    //                               BuildItem::priority
    //                              aiblditm.cpp:175 (3)
    //         00408520     MOV        EAX,dword ptr [ECX + this->priorityValue]
    //                              aiblditm.cpp:177 (1)
    //         00408523     RET
}

// Offset: 0x00408530
int inProgress(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::inProgress(void)const                                               *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408540
int built(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::built(void)const                                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408550
int buildAttempts(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::buildAttempts(void)const                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408560
int buildFrom(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::buildFrom(void)const                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408570
int terrainSet(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::terrainSet(void)const                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall terrainSet(BuildItem * this)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?terrainSet@BuildItem@@QBEHXZ                                XREF[1]:     save:004091e7(c)  
    //                               BuildItem::terrainSet
    //                              aiblditm.cpp:210 (6)
    //         00408570     MOV        EAX,dword ptr [ECX + this->terrainSetValue]
    //                              aiblditm.cpp:212 (1)
    //         00408576     RET
}

// Offset: 0x00408580
int terrainAdjacency(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::terrainAdjacency(int)const                                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004085A0
int placeOnElevation(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::placeOnElevation(void)const                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall placeOnElevation(BuildItem * this)
    //              int               EAX:4          <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?placeOnElevation@BuildItem@@QBEHXZ                          XREF[1]:     save:0040923c(c)  
    //                               BuildItem::placeOnElevation
    //                              aiblditm.cpp:226 (6)
    //         004085a0     MOV        EAX,dword ptr [ECX + this->placeOnElevationVal
    //                              aiblditm.cpp:228 (1)
    //         004085a6     RET
}

// Offset: 0x004085B0
void setInProgress(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setInProgress(int)                                                 *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004085C0
void setBuilt(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setBuilt(int)                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004085D0
void setBuildAttempts(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setBuildAttempts(int)                                              *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004085E0
void incrementBuildAttempts(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::incrementBuildAttempts(void)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementBuildAttempts(BuildItem * this)
    //              void              <VOID>         <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?incrementBuildAttempts@BuildItem@@QAEXXZ                    XREF[1]:     nextBuildableItem:004d4b6b(c)  
    //                               BuildItem::incrementBuildAttempts
    //                              aiblditm.cpp:254 (6)
    //         004085e0     INC        dword ptr [ECX + this->buildAttemptsValue]
    //                              aiblditm.cpp:256 (1)
    //         004085e6     RET
}

// Offset: 0x004085F0
void decrementBuildAttempts(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::decrementBuildAttempts(void)                                       *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408610
int numberBuilds(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::numberBuilds(void)                                                  *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408620
void incrementNumberBuilds(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::incrementNumberBuilds(void)                                        *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408630
void setNumberBuilds(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setNumberBuilds(int)                                               *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408640
int buildCap(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::buildCap(void)                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408650
void setBuildCap(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setBuildCap(int)                                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408660
int skipCycles(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BuildItem::skipCycles(void)                                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408670
void incrementSkipCycles(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::incrementSkipCycles(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementSkipCycles(BuildItem * this)
    //              void              <VOID>         <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //                               ?incrementSkipCycles@BuildItem@@QAEXXZ                       XREF[1]:     skipNextBuildListItem:004d4504(c)  
    //                               BuildItem::incrementSkipCycles
    //                              aiblditm.cpp:312 (6)
    //         00408670     INC        dword ptr [ECX + this->skipCyclesValue]
    //                              aiblditm.cpp:314 (1)
    //         00408676     RET
}

// Offset: 0x00408680
void setSkipCycles(BuildItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setSkipCycles(int)                                                 *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00408690
uchar permanentSkip(BuildItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall BuildItem::permanentSkip(void)                                       *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004086A0
void setPermanentSkip(BuildItem* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BuildItem::setPermanentSkip(unsigned char)                                    *
    //                              *********************************************************************************************************
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
}

