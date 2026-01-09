#include "common.h"
#include "aitchitm.h"

TechnologyItem::TechnologyItem() {
    /* TODO: Stub */
    //                              undefined __thiscall TechnologyItem(TechnologyItem * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //                               ??0TechnologyItem@@QAE@XZ                                    XREF[2]:     ResearchAIModule:004116be(c), 
    //                               TechnologyItem::TechnologyItem                                            ResearchAIModule:00411794(c)  
    //                              aitchitm.cpp:25 (7)
    //         00412bb0     PUSH       EBX
    //         00412bb1     PUSH       ESI
    //         00412bb2     MOV        EDX,this
    //         00412bb4     PUSH       EDI
    //         00412bb5     XOR        EAX,EAX
    //                              aitchitm.cpp:26 (48)
    //         00412bb7     MOV        EDI,s_                                           = ""
    //         00412bbc     OR         this,0xffffffff
    //         00412bbf     MOV        dword ptr [EDX + 0x4],EAX
    //         00412bc2     MOV        dword ptr [EDX + 0x8],EAX
    //         00412bc5     MOV        dword ptr [EDX + 0xc],EAX
    //         00412bc8     MOV        dword ptr [EDX + 0x50],EAX
    //         00412bcb     MOV        dword ptr [EDX],TechnologyItem::`vftable'        = 00412c00
    //         00412bd1     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00412bd3     NOT        this
    //         00412bd5     SUB        EDI,this
    //         00412bd7     LEA        EBX,[EDX + 0x10]
    //         00412bda     MOV        EAX,this
    //         00412bdc     MOV        ESI,EDI
    //         00412bde     MOV        EDI,EBX
    //         00412be0     SHR        this,0x2
    //         00412be3     MOVSD.REP  ES:EDI,ESI
    //         00412be5     MOV        this,EAX
    //                              aitchitm.cpp:27 (11)
    //         00412be7     MOV        EAX,EDX
    //         00412be9     AND        this,0x3
    //         00412bec     MOVSB.REP  ES:EDI,ESI
    //         00412bee     POP        EDI
    //         00412bef     POP        ESI
    //         00412bf0     POP        EBX
    //         00412bf1     RET
    //         00412bf2     ??         90h
    //         00412bf3     NOP
    //         00412bf4     NOP
    //         00412bf5     NOP
    //         00412bf6     NOP
    //         00412bf7     NOP
    //         00412bf8     NOP
    //         00412bf9     NOP
    //         00412bfa     NOP
    //         00412bfb     NOP
    //         00412bfc     NOP
    //         00412bfd     NOP
    //         00412bfe     NOP
    //         00412bff     NOP
}

TechnologyItem::TechnologyItem(int param_1, char* param_2, ResourceItem param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall TechnologyItem(TechnologyItem * this, int param
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00412c3a(R), 00412c5d(W)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00412c7a(R)  
    //              ResourceItem      Stack[0xc]:112 param_3                   XREF[2]:     00412c6a(*), 00412ca9(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00412c42(W), 00412c63(W), 00412c95(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00412cb2(R)  
    //                               ??0TechnologyItem@@QAE@HPADVResourceItem@@@Z                 XREF[2]:     ResearchAIModule:004118d7(c), 
    //                               TechnologyItem::TechnologyItem                                            loadTechnologyTree:00411d22(c)  
    //                              aitchitm.cpp:35 (32)
    //         00412c20     MOV        EAX,FS:[0x0]
    //         00412c26     PUSH       -0x1
    //         00412c28     PUSH       FUN_0055c853
    //         00412c2d     PUSH       EAX
    //         00412c2e     MOV        dword ptr FS:[0x0],ESP
    //         00412c35     PUSH       EBX
    //         00412c36     PUSH       ESI
    //         00412c37     PUSH       EDI
    //         00412c38     MOV        EBX,this
    //         00412c3a     MOV        EAX,dword ptr [ESP + param_1]
    //         00412c3e     XOR        ESI,ESI
    //                              language.dll match for 0x70: "B"
    //                              aitchitm.cpp:36 (58)
    //         00412c40     PUSH       0x70
    //         00412c42     MOV        dword ptr [ESP + local_4],ESI
    //         00412c46     MOV        dword ptr [EBX + 0x4],ESI
    //         00412c49     MOV        dword ptr [EBX + 0x8],ESI
    //         00412c4c     MOV        dword ptr [EBX + 0xc],EAX
    //         00412c4f     MOV        dword ptr [EBX],TechnologyItem::`vftable'        = 00412c00
    //         00412c55     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00412c5a     ADD        ESP,0x4
    //         00412c5d     MOV        dword ptr [ESP + param_1],EAX
    //         00412c61     CMP        EAX,ESI
    //         00412c63     MOV        byte ptr [ESP + local_4],0x1
    //         00412c68     JZ         LAB_00412c78
    //         00412c6a     LEA        this=>param_3,[ESP + 0x24]
    //         00412c6e     PUSH       this
    //         00412c6f     MOV        this,EAX
    //         00412c71     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, R
    //         00412c76     JMP        LAB_00412c7a
    //                               LAB_00412c78                                                 XREF[1]:     00412c68(j)  
    //         00412c78     XOR        EAX,EAX
    //                               LAB_00412c7a                                                 XREF[1]:     00412c76(j)  
    //                              aitchitm.cpp:37 (27)
    //         00412c7a     MOV        EDI,dword ptr [ESP + param_2]
    //         00412c7e     MOV        dword ptr [EBX + 0x50],EAX
    //         00412c81     OR         this,0xffffffff
    //         00412c84     XOR        EAX,EAX
    //         00412c86     SCASB.RE   ES:EDI
    //         00412c88     NOT        this
    //         00412c8a     SUB        EDI,this
    //         00412c8c     LEA        EDX,[EBX + 0x10]
    //         00412c8f     MOV        EAX,this
    //         00412c91     MOV        ESI,EDI
    //         00412c93     MOV        EDI,EDX
    //                              aitchitm.cpp:38 (51)
    //         00412c95     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00412c9d     SHR        this,0x2
    //         00412ca0     MOVSD.REP  ES:EDI,ESI
    //         00412ca2     MOV        this,EAX
    //         00412ca4     AND        this,0x3
    //         00412ca7     MOVSB.REP  ES:EDI,ESI
    //         00412ca9     LEA        this=>param_3,[ESP + 0x24]
    //         00412cad     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         00412cb2     MOV        this,dword ptr [ESP + local_c]
    //         00412cb6     POP        EDI
    //         00412cb7     MOV        EAX,EBX
    //         00412cb9     POP        ESI
    //         00412cba     MOV        dword ptr FS:[0x0],this
    //         00412cc1     POP        EBX
    //         00412cc2     ADD        ESP,0xc
    //         00412cc5     RET        0x78
    //         00412cc8     ??         90h
    //         00412cc9     NOP
    //         00412cca     NOP
    //         00412ccb     NOP
    //         00412ccc     NOP
    //         00412ccd     NOP
    //         00412cce     NOP
    //         00412ccf     NOP
}

TechnologyItem::TechnologyItem(TechnologyItem* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TechnologyItem(TechnologyItem * this, Technolog
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //              TechnologyItem    Stack[0x4]:4   param_1                   XREF[2]:     00412ce7(R), 00412d0c(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00412d12(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00412d4f(R)  
    //                               ??0TechnologyItem@@QAE@ABV0@@Z
    //                               TechnologyItem::TechnologyItem
    //                              aitchitm.cpp:46 (32)
    //         00412cd0     MOV        EAX,FS:[0x0]
    //         00412cd6     PUSH       -0x1
    //         00412cd8     PUSH       FUN_0055c86b
    //         00412cdd     PUSH       EAX
    //         00412cde     MOV        dword ptr FS:[0x0],ESP
    //         00412ce5     PUSH       EBX
    //         00412ce6     PUSH       ESI
    //         00412ce7     MOV        ESI,dword ptr [ESP + param_1]
    //         00412ceb     PUSH       EDI
    //         00412cec     MOV        EBX,this
    //         00412cee     XOR        EDI,EDI
    //                              language.dll match for 0x70: "B"
    //                              aitchitm.cpp:47 (58)
    //         00412cf0     PUSH       0x70
    //         00412cf2     MOV        dword ptr [EBX + 0x4],EDI
    //         00412cf5     MOV        dword ptr [EBX + 0x8],EDI
    //         00412cf8     MOV        EAX,dword ptr [ESI + 0xc]
    //         00412cfb     MOV        dword ptr [EBX],TechnologyItem::`vftable'        = 00412c00
    //         00412d01     MOV        dword ptr [EBX + 0xc],EAX
    //         00412d04     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00412d09     ADD        ESP,0x4
    //         00412d0c     MOV        dword ptr [ESP + param_1],EAX
    //         00412d10     CMP        EAX,EDI
    //         00412d12     MOV        dword ptr [ESP + local_4],EDI
    //         00412d16     JZ         LAB_00412d25
    //         00412d18     MOV        this,dword ptr [ESI + 0x50]
    //         00412d1b     PUSH       this
    //         00412d1c     MOV        this,EAX
    //         00412d1e     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, R
    //         00412d23     JMP        LAB_00412d27
    //                               LAB_00412d25                                                 XREF[1]:     00412d16(j)  
    //         00412d25     XOR        EAX,EAX
    //                               LAB_00412d27                                                 XREF[1]:     00412d23(j)  
    //         00412d27     MOV        dword ptr [EBX + 0x50],EAX
    //                              aitchitm.cpp:48 (30)
    //         00412d2a     LEA        EDI,[ESI + 0x10]
    //         00412d2d     OR         this,0xffffffff
    //         00412d30     XOR        EAX,EAX
    //         00412d32     SCASB.RE   ES:EDI
    //         00412d34     NOT        this
    //         00412d36     SUB        EDI,this
    //         00412d38     LEA        EDX,[EBX + 0x10]
    //         00412d3b     MOV        EAX,this
    //         00412d3d     MOV        ESI,EDI
    //         00412d3f     MOV        EDI,EDX
    //         00412d41     SHR        this,0x2
    //         00412d44     MOVSD.REP  ES:EDI,ESI
    //         00412d46     MOV        this,EAX
    //                              aitchitm.cpp:49 (27)
    //         00412d48     MOV        EAX,EBX
    //         00412d4a     AND        this,0x3
    //         00412d4d     MOVSB.REP  ES:EDI,ESI
    //         00412d4f     MOV        this,dword ptr [ESP + local_c]
    //         00412d53     POP        EDI
    //         00412d54     POP        ESI
    //         00412d55     MOV        dword ptr FS:[0x0],this
    //         00412d5c     POP        EBX
    //         00412d5d     ADD        ESP,0xc
    //         00412d60     RET        0x4
    //         00412d63     ??         90h
    //         00412d64     NOP
    //         00412d65     NOP
    //         00412d66     NOP
    //         00412d67     NOP
    //         00412d68     NOP
    //         00412d69     NOP
    //         00412d6a     NOP
    //         00412d6b     NOP
    //         00412d6c     NOP
    //         00412d6d     NOP
    //         00412d6e     NOP
    //         00412d6f     NOP
}

TechnologyItem::~TechnologyItem() {
    /* TODO: Stub */
    //                              void __thiscall ~TechnologyItem(TechnologyItem * this)
    //              void              <VOID>         <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //                               ??1TechnologyItem@@UAE@XZ                                    XREF[2]:     ~ResearchAIModule:00411985(c), 
    //                               TechnologyItem::~TechnologyItem                                           `scalar_deleting_destructor':00412
    //                              aitchitm.cpp:54 (6)
    //         00412d70     MOV        dword ptr [this->_padding_],TechnologyItem::`v   = 00412c00
    //                              aitchitm.cpp:55 (7)
    //         00412d76     MOV        this,dword ptr [ECX + this->resourceCostValue]
    //         00412d79     TEST       this,this
    //         00412d7b     JZ         LAB_00412d83
    //                              aitchitm.cpp:56 (6)
    //         00412d7d     MOV        EAX,dword ptr [this->_padding_]
    //         00412d7f     PUSH       0x1
    //         00412d81     CALL       dword ptr [EAX]
    //                               LAB_00412d83                                                 XREF[1]:     00412d7b(j)  
    //                              aitchitm.cpp:57 (1)
    //         00412d83     RET
    //         00412d84     ??         90h
    //         00412d85     NOP
    //         00412d86     NOP
    //         00412d87     NOP
    //         00412d88     NOP
    //         00412d89     NOP
    //         00412d8a     NOP
    //         00412d8b     NOP
    //         00412d8c     NOP
    //         00412d8d     NOP
    //         00412d8e     NOP
    //         00412d8f     NOP
    //                              * int __cdecl operator==(class TechnologyItem const &,class TechnologyItem const &)                     *
    //                              int __cdecl operator==(TechnologyItem * param_1, TechnologyItem * pa
    //              int               EAX:4          <RETURN>
    //              TechnologyItem    Stack[0x4]:4   param_1                   XREF[1]:     00412d90(R)  
    //              TechnologyItem    Stack[0x8]:4   param_2                   XREF[1]:     00412d94(R)  
    //                               ??8@YAHABVTechnologyItem@@0@Z
    //                               operator==
    //                              aitchitm.cpp:62 (22)
    //         00412d90     MOV        EAX,dword ptr [ESP + param_1]
    //         00412d94     MOV        EDX,dword ptr [ESP + param_2]
    //         00412d98     PUSH       ESI
    //         00412d99     MOV        ECX,dword ptr [EAX + 0xc]
    //         00412d9c     MOV        ESI,dword ptr [EDX + 0xc]
    //         00412d9f     XOR        EAX,EAX
    //         00412da1     CMP        ECX,ESI
    //         00412da3     SETZ       AL
    //                              aitchitm.cpp:66 (2)
    //         00412da6     POP        ESI
    //         00412da7     RET
    //         00412da8     ??         90h
    //         00412da9     NOP
    //         00412daa     NOP
    //         00412dab     NOP
    //         00412dac     NOP
    //         00412dad     NOP
    //         00412dae     NOP
    //         00412daf     NOP
    //                              * int __cdecl operator!=(class TechnologyItem const &,class TechnologyItem const &)                     *
    //                              int __cdecl operator!=(TechnologyItem * param_1, TechnologyItem * pa
    //              int               EAX:4          <RETURN>
    //              TechnologyItem    Stack[0x4]:4   param_1                   XREF[1]:     00412db0(R)  
    //              TechnologyItem    Stack[0x8]:4   param_2                   XREF[1]:     00412db4(R)  
    //                               ??9@YAHABVTechnologyItem@@0@Z
    //                               operator!=
    //                              aitchitm.cpp:71 (22)
    //         00412db0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412db4     MOV        EDX,dword ptr [ESP + param_2]
    //         00412db8     PUSH       ESI
    //         00412db9     MOV        ECX,dword ptr [EAX + 0xc]
    //         00412dbc     MOV        ESI,dword ptr [EDX + 0xc]
    //         00412dbf     XOR        EAX,EAX
    //         00412dc1     CMP        ECX,ESI
    //         00412dc3     SETNZ      AL
    //                              aitchitm.cpp:75 (2)
    //         00412dc6     POP        ESI
    //         00412dc7     RET
    //         00412dc8     ??         90h
    //         00412dc9     NOP
    //         00412dca     NOP
    //         00412dcb     NOP
    //         00412dcc     NOP
    //         00412dcd     NOP
    //         00412dce     NOP
    //         00412dcf     NOP
    //                              * int __cdecl operator<(class TechnologyItem const &,class TechnologyItem const &)                      *
    //                              int __cdecl operator<(TechnologyItem * param_1, TechnologyItem * par
    //              int               EAX:4          <RETURN>
    //              TechnologyItem    Stack[0x4]:4   param_1                   XREF[1]:     00412dd0(R)  
    //              TechnologyItem    Stack[0x8]:4   param_2                   XREF[1]:     00412dd4(R)  
    //                               ??M@YAHABVTechnologyItem@@0@Z
    //                               operator<
    //                              aitchitm.cpp:80 (22)
    //         00412dd0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412dd4     MOV        EDX,dword ptr [ESP + param_2]
    //         00412dd8     PUSH       ESI
    //         00412dd9     MOV        ECX,dword ptr [EAX + 0xc]
    //         00412ddc     MOV        ESI,dword ptr [EDX + 0xc]
    //         00412ddf     XOR        EAX,EAX
    //         00412de1     CMP        ECX,ESI
    //         00412de3     SETL       AL
    //                              aitchitm.cpp:84 (2)
    //         00412de6     POP        ESI
    //         00412de7     RET
    //         00412de8     ??         90h
    //         00412de9     NOP
    //         00412dea     NOP
    //         00412deb     NOP
    //         00412dec     NOP
    //         00412ded     NOP
    //         00412dee     NOP
    //         00412def     NOP
    //                              * int __cdecl operator>(class TechnologyItem const &,class TechnologyItem const &)                      *
    //                              int __cdecl operator>(TechnologyItem * param_1, TechnologyItem * par
    //              int               EAX:4          <RETURN>
    //              TechnologyItem    Stack[0x4]:4   param_1                   XREF[1]:     00412df0(R)  
    //              TechnologyItem    Stack[0x8]:4   param_2                   XREF[1]:     00412df4(R)  
    //                               ??O@YAHABVTechnologyItem@@0@Z
    //                               operator>
    //                              aitchitm.cpp:89 (22)
    //         00412df0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412df4     MOV        EDX,dword ptr [ESP + param_2]
    //         00412df8     PUSH       ESI
    //         00412df9     MOV        ECX,dword ptr [EAX + 0xc]
    //         00412dfc     MOV        ESI,dword ptr [EDX + 0xc]
    //         00412dff     XOR        EAX,EAX
    //         00412e01     CMP        ECX,ESI
    //         00412e03     SETG       AL
    //                              aitchitm.cpp:93 (2)
    //         00412e06     POP        ESI
    //         00412e07     RET
    //         00412e08     ??         90h
    //         00412e09     NOP
    //         00412e0a     NOP
    //         00412e0b     NOP
    //         00412e0c     NOP
    //         00412e0d     NOP
    //         00412e0e     NOP
    //         00412e0f     NOP
    //                              * public: int __thiscall TechnologyItem::id(void)const                                                  *
    //                              int __thiscall id(TechnologyItem * this)
    //              int               EAX:4          <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //                               ?id@TechnologyItem@@QBEHXZ                                   XREF[2]:     save:00411ad3(c), 
    //                               TechnologyItem::id                                                        item:00411e8d(c)  
    //                              aitchitm.cpp:98 (3)
    //         00412e10     MOV        EAX,dword ptr [ECX + this->idValue]
    //                              aitchitm.cpp:100 (1)
    //         00412e13     RET
    //         00412e14     ??         90h
    //         00412e15     NOP
    //         00412e16     NOP
    //         00412e17     NOP
    //         00412e18     NOP
    //         00412e19     NOP
    //         00412e1a     NOP
    //         00412e1b     NOP
    //         00412e1c     NOP
    //         00412e1d     NOP
    //         00412e1e     NOP
    //         00412e1f     NOP
}

char* TechnologyItem::name() {
    /* TODO: Stub */
    //                              char * __thiscall name(TechnologyItem * this)
    //              char *            EAX:4          <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //                               ?name@TechnologyItem@@QAEPADXZ                               XREF[1]:     save:00411a74(c)  
    //                               TechnologyItem::name
    //                              aitchitm.cpp:105 (3)
    //         00412e20     LEA        EAX,[ECX + this->nameValue[0]]
    //                              aitchitm.cpp:107 (1)
    //         00412e23     RET
    //         00412e24     ??         90h
    //         00412e25     NOP
    //         00412e26     NOP
    //         00412e27     NOP
    //         00412e28     NOP
    //         00412e29     NOP
    //         00412e2a     NOP
    //         00412e2b     NOP
    //         00412e2c     NOP
    //         00412e2d     NOP
    //         00412e2e     NOP
    //         00412e2f     NOP
    return 0;
}

ResourceItem* TechnologyItem::resourceCost() {
    /* TODO: Stub */
    //                              ResourceItem * __thiscall resourceCost(TechnologyItem * this)
    //              ResourceItem *    EAX:4          <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //                               ?resourceCost@TechnologyItem@@QAEPAVResourceItem@@XZ         XREF[2]:     save:00411aee(c), 
    //                               TechnologyItem::resourceCost                                              resourceCost:00411b53(c)  
    //                              aitchitm.cpp:112 (3)
    //         00412e30     MOV        EAX,dword ptr [ECX + this->resourceCostValue]
    //                              aitchitm.cpp:114 (1)
    //         00412e33     RET
    //         00412e34     ??         90h
    //         00412e35     NOP
    //         00412e36     NOP
    //         00412e37     NOP
    //         00412e38     NOP
    //         00412e39     NOP
    //         00412e3a     NOP
    //         00412e3b     NOP
    //         00412e3c     NOP
    //         00412e3d     NOP
    //         00412e3e     NOP
    //         00412e3f     NOP
    return 0;
}

int TechnologyItem::id() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

