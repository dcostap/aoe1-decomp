// Auto-generated scaffold unit: airesitm.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/airesitm.cpp
#include "../include/common.h"

// Offset: 0x00411EC0
undefined ResourceItem(ResourceItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ResourceItem::ResourceItem(void)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ResourceItem(ResourceItem * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ResourceItem *    ECX:4 (auto)   this
    //                               ??0ResourceItem@@QAE@XZ
    //                               ResourceItem::ResourceItem
    //                              airesitm.cpp:26 (31)
    //         00411ec0     MOV        EAX,this
    //         00411ec2     PUSH       ESI
    //         00411ec3     XOR        this,this
    //         00411ec5     MOV        ESI,0x8
    //         00411eca     MOV        dword ptr [EAX + 0x4],this
    //         00411ecd     MOV        dword ptr [EAX + 0x8],this
    //         00411ed0     MOV        dword ptr [EAX + 0x6c],this
    //         00411ed3     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
    //         00411ed9     LEA        EDX,[EAX + 0x2c]
    //         00411edc     OR         this,0xffffffff
    //                               LAB_00411edf                                                 XREF[1]:     00411eeb(j)  
    //                              airesitm.cpp:28 (3)
    //         00411edf     MOV        dword ptr [EDX + -0x20],this
    //                              airesitm.cpp:29 (2)
    //         00411ee2     MOV        dword ptr [EDX],this
    //                              airesitm.cpp:30 (9)
    //         00411ee4     MOV        dword ptr [EDX + 0x20],this
    //         00411ee7     ADD        EDX,0x4
    //         00411eea     DEC        ESI
    //         00411eeb     JNZ        LAB_00411edf
    //                              airesitm.cpp:32 (2)
    //         00411eed     POP        ESI
    //         00411eee     RET
}

// Offset: 0x00411F10
undefined ResourceItem(ResourceItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ResourceItem::ResourceItem(int)                                                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ResourceItem(ResourceItem * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ResourceItem *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00411f13(R)  
    //                               ??0ResourceItem@@QAE@H@Z                                     XREF[9]:     initialize:004d42fd(c), 
    //                               ResourceItem::ResourceItem                                                nextBuildableItem:004d49d0(c), 
    //                                                                                                         nextBuildableItem:004d4cc6(c), 
    //                                                                                                         blockingResource:004d4e8f(c), 
    //                                                                                                         TribeTacticalAIModule:004ed3ae(c), 
    //                                                                                                         TribeTacticalAIModule:004ed69e(c), 
    //                                                                                                         checkForBuildInsertion:00501dbf(c)
    //                                                                                                         checkForBuildInsertion:00501f99(c)
    //                                                                                                         FUN_005024b3:0050250d(c)  
    //                              airesitm.cpp:40 (11)
    //         00411f10     PUSH       EBX
    //         00411f11     MOV        EAX,this
    //         00411f13     MOV        this,dword ptr [ESP + param_1]
    //         00411f17     PUSH       ESI
    //         00411f18     PUSH       EDI
    //         00411f19     XOR        EBX,EBX
    //                              airesitm.cpp:41 (24)
    //         00411f1b     XOR        ESI,ESI
    //         00411f1d     OR         EDI,0xffffffff
    //         00411f20     CMP        this,EBX
    //         00411f22     MOV        dword ptr [EAX + 0x4],EBX
    //         00411f25     MOV        dword ptr [EAX + 0x8],EBX
    //         00411f28     MOV        dword ptr [EAX + 0x6c],this
    //         00411f2b     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
    //         00411f31     JLE        LAB_00411f4e
    //                              airesitm.cpp:40 (3)
    //         00411f33     LEA        EDX,[EAX + 0x2c]
    //                               LAB_00411f36                                                 XREF[1]:     00411f4c(j)  
    //                              airesitm.cpp:41 (5)
    //         00411f36     CMP        ESI,0x8
    //         00411f39     JGE        LAB_00411f6c
    //                              airesitm.cpp:42 (3)
    //         00411f3b     MOV        dword ptr [EDX + -0x20],EBX
    //                              airesitm.cpp:43 (2)
    //         00411f3e     MOV        dword ptr [EDX],EDI
    //                              airesitm.cpp:44 (14)
    //         00411f40     MOV        dword ptr [EDX + 0x20],EDI
    //         00411f43     MOV        this,dword ptr [EAX + 0x6c]
    //         00411f46     INC        ESI
    //         00411f47     ADD        EDX,0x4
    //         00411f4a     CMP        ESI,this
    //         00411f4c     JL         LAB_00411f36
    //                               LAB_00411f4e                                                 XREF[1]:     00411f31(j)  
    //                              airesitm.cpp:46 (16)
    //         00411f4e     CMP        ESI,0x8
    //         00411f51     JGE        LAB_00411f6c
    //         00411f53     MOV        this,0x8
    //         00411f58     LEA        EDX,[EAX + ESI*0x4 + 0x2c]
    //         00411f5c     SUB        this,ESI
    //                               LAB_00411f5e                                                 XREF[1]:     00411f6a(j)  
    //                              airesitm.cpp:47 (3)
    //         00411f5e     MOV        dword ptr [EDX + -0x20],EDI
    //                              airesitm.cpp:48 (2)
    //         00411f61     MOV        dword ptr [EDX],EDI
    //                              airesitm.cpp:49 (9)
    //         00411f63     MOV        dword ptr [EDX + 0x20],EDI
    //         00411f66     ADD        EDX,0x4
    //         00411f69     DEC        this
    //         00411f6a     JNZ        LAB_00411f5e
    //                               LAB_00411f6c                                                 XREF[2]:     00411f39(j), 00411f51(j)  
    //                              airesitm.cpp:51 (6)
    //         00411f6c     POP        EDI
    //         00411f6d     POP        ESI
    //         00411f6e     POP        EBX
    //         00411f6f     RET        0x4
}

// Offset: 0x00411F80
undefined ResourceItem(ResourceItem* this_, int param_2, int* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ResourceItem::ResourceItem(int,int *)                                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ResourceItem(ResourceItem * this, int param_1, 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ResourceItem *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00411f83(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     00411fa1(R)  
    //                               ??0ResourceItem@@QAE@HPAH@Z                                  XREF[2]:     ResearchAIModule:00411883(c), 
    //                               ResourceItem::ResourceItem                                                loadTechnologyTree:00411ccb(c)  
    //                              airesitm.cpp:59 (11)
    //         00411f80     PUSH       EBX
    //         00411f81     MOV        EAX,this
    //         00411f83     MOV        this,dword ptr [ESP + param_1]
    //         00411f87     PUSH       ESI
    //         00411f88     PUSH       EDI
    //         00411f89     XOR        ESI,ESI
    //                              airesitm.cpp:60 (34)
    //         00411f8b     OR         EDI,0xffffffff
    //         00411f8e     CMP        this,ESI
    //         00411f90     MOV        dword ptr [EAX + 0x4],ESI
    //         00411f93     MOV        dword ptr [EAX + 0x8],ESI
    //         00411f96     MOV        dword ptr [EAX + 0x6c],this
    //         00411f99     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
    //         00411f9f     JLE        LAB_00411fc5
    //         00411fa1     MOV        this,dword ptr [ESP + param_2]
    //         00411fa5     LEA        EDX,[EAX + 0x2c]
    //                               LAB_00411fa8                                                 XREF[1]:     00411fc3(j)  
    //         00411fa8     CMP        ESI,0x8
    //         00411fab     JGE        LAB_00411fe3
    //                              airesitm.cpp:61 (6)
    //         00411fad     MOV        EBX,dword ptr [this->_padding_]
    //         00411faf     INC        ESI
    //         00411fb0     MOV        dword ptr [EDX + -0x20],EBX
    //                              airesitm.cpp:62 (2)
    //         00411fb3     MOV        dword ptr [EDX],EDI
    //                              airesitm.cpp:63 (16)
    //         00411fb5     MOV        dword ptr [EDX + 0x20],EDI
    //         00411fb8     MOV        EBX,dword ptr [EAX + 0x6c]
    //         00411fbb     ADD        this,0x4
    //         00411fbe     ADD        EDX,0x4
    //         00411fc1     CMP        ESI,EBX
    //         00411fc3     JL         LAB_00411fa8
    //                               LAB_00411fc5                                                 XREF[1]:     00411f9f(j)  
    //                              airesitm.cpp:65 (16)
    //         00411fc5     CMP        ESI,0x8
    //         00411fc8     JGE        LAB_00411fe3
    //         00411fca     MOV        this,0x8
    //         00411fcf     LEA        EDX,[EAX + ESI*0x4 + 0x2c]
    //         00411fd3     SUB        this,ESI
    //                               LAB_00411fd5                                                 XREF[1]:     00411fe1(j)  
    //                              airesitm.cpp:66 (3)
    //         00411fd5     MOV        dword ptr [EDX + -0x20],EDI
    //                              airesitm.cpp:67 (2)
    //         00411fd8     MOV        dword ptr [EDX],EDI
    //                              airesitm.cpp:68 (9)
    //         00411fda     MOV        dword ptr [EDX + 0x20],EDI
    //         00411fdd     ADD        EDX,0x4
    //         00411fe0     DEC        this
    //         00411fe1     JNZ        LAB_00411fd5
    //                               LAB_00411fe3                                                 XREF[2]:     00411fab(j), 00411fc8(j)  
    //                              airesitm.cpp:70 (6)
    //         00411fe3     POP        EDI
    //         00411fe4     POP        ESI
    //         00411fe5     POP        EBX
    //         00411fe6     RET        0x8
}

// Offset: 0x00411FF0
undefined ResourceItem(ResourceItem* this_, ResourceItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ResourceItem::ResourceItem(class ResourceItem const &)                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ResourceItem(ResourceItem * this, ResourceItem 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ResourceItem *    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00411ff5(R)  
    //                               ??0ResourceItem@@QAE@ABV0@@Z                                 XREF[3]:     ResearchAIModule:004118c0(c), 
    //                               ResourceItem::ResourceItem                                                loadTechnologyTree:00411d0b(c), 
    //                                                                                                         TechnologyItem:00412c71(c)  
    //                              airesitm.cpp:78 (26)
    //         00411ff0     PUSH       EBX
    //         00411ff1     PUSH       ESI
    //         00411ff2     MOV        EAX,this
    //         00411ff4     PUSH       EDI
    //         00411ff5     MOV        this,dword ptr [ESP + param_1]
    //         00411ff9     XOR        EDI,EDI
    //         00411ffb     MOV        dword ptr [EAX + 0x4],EDI
    //         00411ffe     MOV        dword ptr [EAX + 0x8],EDI
    //         00412001     MOV        EDX,dword ptr [ECX + this->numberValue]
    //         00412004     MOV        dword ptr [EAX],ResourceItem::`vftable'          = 00411ef0
    //                              airesitm.cpp:79 (20)
    //         0041200a     CMP        EDX,EDI
    //         0041200c     MOV        dword ptr [EAX + 0x6c],EDX
    //         0041200f     JLE        LAB_0041203c
    //         00412011     LEA        ESI,[ECX + this->sortedIndexValue[0]]
    //         00412014     LEA        EDX,[EAX + 0xc]
    //         00412017     SUB        this,EAX
    //                               LAB_00412019                                                 XREF[1]:     0041203a(j)  
    //         00412019     CMP        EDI,0x8
    //         0041201c     JGE        LAB_0041203c
    //                              airesitm.cpp:80 (6)
    //         0041201e     MOV        EBX,dword ptr [this->_padding_ + EDX*0x1]
    //         00412021     INC        EDI
    //         00412022     MOV        dword ptr [EDX],EBX
    //                              airesitm.cpp:81 (6)
    //         00412024     MOV        EBX,dword ptr [ESI + -0x20]
    //         00412027     MOV        dword ptr [EDX + 0x20],EBX
    //                              airesitm.cpp:82 (18)
    //         0041202a     MOV        EBX,dword ptr [ESI]
    //         0041202c     MOV        dword ptr [EDX + 0x40],EBX
    //         0041202f     MOV        EBX,dword ptr [EAX + 0x6c]
    //         00412032     ADD        EDX,0x4
    //         00412035     ADD        ESI,0x4
    //         00412038     CMP        EDI,EBX
    //         0041203a     JL         LAB_00412019
    //                               LAB_0041203c                                                 XREF[2]:     0041200f(j), 0041201c(j)  
    //                              airesitm.cpp:84 (6)
    //         0041203c     POP        EDI
    //         0041203d     POP        ESI
    //         0041203e     POP        EBX
    //         0041203f     RET        0x4
}

// Offset: 0x00412050
undefined ResourceItem(ResourceItem* this_, ResourceItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ResourceItem::ResourceItem(class ResourceItem *)                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004120B0
void ResourceItem(ResourceItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall ResourceItem::~ResourceItem(void)                                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004120C0
ResourceItem* operator(ResourceItem* this_, ResourceItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ResourceItem & __thiscall ResourceItem::operator+=(class ResourceItem const &)          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412100
int operator(ResourceItem* param_1, ResourceItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class ResourceItem const &,class ResourceItem const &)                         *
    //                              *********************************************************************************************************
    //                              int __cdecl operator==(ResourceItem * param_1, ResourceItem * param_2)
    //              int               EAX:4          <RETURN>
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412102(R)  
    //              ResourceItem *    Stack[0x8]:4   param_2                   XREF[1]:     00412107(R)  
    //                               ??8@YAHABVResourceItem@@0@Z
    //                               operator==
    //                              airesitm.cpp:120 (2)
    //         00412100     PUSH       EBX
    //         00412101     PUSH       ESI
    //                              airesitm.cpp:121 (17)
    //         00412102     MOV        ESI,dword ptr [ESP + param_1]
    //         00412106     PUSH       EDI
    //         00412107     MOV        EDI,dword ptr [ESP + param_2]
    //         0041210b     MOV        EDX,dword ptr [ESI + 0x6c]
    //         0041210e     CMP        EDX,dword ptr [EDI + 0x6c]
    //         00412111     JNZ        LAB_00412138
    //                              airesitm.cpp:122 (6)
    //         00412113     XOR        ECX,ECX
    //         00412115     TEST       EDX,EDX
    //         00412117     JLE        LAB_0041212f
    //                              airesitm.cpp:128 (22)
    //         00412119     LEA        EAX,[ESI + 0xc]
    //         0041211c     SUB        EDI,ESI
    //                               LAB_0041211e                                                 XREF[1]:     0041212d(j)  
    //         0041211e     MOV        ESI,dword ptr [EAX]
    //         00412120     MOV        EBX,dword ptr [EDI + EAX*0x1]
    //         00412123     CMP        ESI,EBX
    //         00412125     JNZ        LAB_00412138
    //         00412127     INC        ECX
    //         00412128     ADD        EAX,0x4
    //         0041212b     CMP        ECX,EDX
    //         0041212d     JL         LAB_0041211e
    //                               LAB_0041212f                                                 XREF[1]:     00412117(j)  
    //                              airesitm.cpp:125 (5)
    //         0041212f     MOV        EAX,0x1
    //                              airesitm.cpp:128 (10)
    //         00412134     POP        EDI
    //         00412135     POP        ESI
    //         00412136     POP        EBX
    //         00412137     RET
    //                               LAB_00412138                                                 XREF[2]:     00412111(j), 00412125(j)  
    //         00412138     POP        EDI
    //         00412139     POP        ESI
    //         0041213a     XOR        EAX,EAX
    //         0041213c     POP        EBX
    //         0041213d     RET
}

// Offset: 0x00412140
int operator(ResourceItem* param_1, ResourceItem* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class ResourceItem const &,class ResourceItem const &)                         *
    //                              *********************************************************************************************************
    //                              int __cdecl operator!=(ResourceItem * param_1, ResourceItem * param_2)
    //              int               EAX:4          <RETURN>
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412142(R)  
    //              ResourceItem *    Stack[0x8]:4   param_2                   XREF[1]:     00412147(R)  
    //                               ??9@YAHABVResourceItem@@0@Z
    //                               operator!=
    //                              airesitm.cpp:133 (2)
    //         00412140     PUSH       EBX
    //         00412141     PUSH       ESI
    //                              airesitm.cpp:134 (17)
    //         00412142     MOV        ESI,dword ptr [ESP + param_1]
    //         00412146     PUSH       EDI
    //         00412147     MOV        EDI,dword ptr [ESP + param_2]
    //         0041214b     MOV        EDX,dword ptr [ESI + 0x6c]
    //         0041214e     CMP        EDX,dword ptr [EDI + 0x6c]
    //         00412151     JNZ        LAB_00412175
    //                              airesitm.cpp:135 (6)
    //         00412153     XOR        ECX,ECX
    //         00412155     TEST       EDX,EDX
    //         00412157     JLE        LAB_0041216f
    //                              airesitm.cpp:141 (22)
    //         00412159     LEA        EAX,[ESI + 0xc]
    //         0041215c     SUB        EDI,ESI
    //                               LAB_0041215e                                                 XREF[1]:     0041216d(j)  
    //         0041215e     MOV        ESI,dword ptr [EAX]
    //         00412160     MOV        EBX,dword ptr [EDI + EAX*0x1]
    //         00412163     CMP        ESI,EBX
    //         00412165     JNZ        LAB_00412175
    //         00412167     INC        ECX
    //         00412168     ADD        EAX,0x4
    //         0041216b     CMP        ECX,EDX
    //         0041216d     JL         LAB_0041215e
    //                               LAB_0041216f                                                 XREF[1]:     00412157(j)  
    //                              airesitm.cpp:138 (2)
    //         0041216f     XOR        EAX,EAX
    //                              airesitm.cpp:141 (13)
    //         00412171     POP        EDI
    //         00412172     POP        ESI
    //         00412173     POP        EBX
    //         00412174     RET
    //                               LAB_00412175                                                 XREF[2]:     00412151(j), 00412165(j)  
    //         00412175     POP        EDI
    //         00412176     POP        ESI
    //         00412177     MOV        EAX,0x1
    //         0041217c     POP        EBX
    //         0041217d     RET
}

// Offset: 0x00412180
int value(ResourceItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall ResourceItem::value(int)const                                                  *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004121A0
void setValue(ResourceItem* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall ResourceItem::setValue(int,int)                                               *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004121C0
void incrementValue(ResourceItem* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall ResourceItem::incrementValue(int,int)                                         *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004121E0
void setAllValues(ResourceItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall ResourceItem::setAllValues(int)                                               *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412200
int number(ResourceItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall ResourceItem::number(void)const                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412210
int largestValueIndex(ResourceItem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall ResourceItem::largestValueIndex(int)                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412240
int sortLarge(ResourceItem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall ResourceItem::sortLarge(void)                                               *
    //                              *********************************************************************************************************
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
}

