#include "../common.h"
#include "aitchitm.h"

TechnologyItem::TechnologyItem() {
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

TechnologyItem::TechnologyItem(int param_1, char* param_2, ResourceItem param_3) {
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
}

int TechnologyItem::id() {
    /* TODO: Stub */
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
    return 0;
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

