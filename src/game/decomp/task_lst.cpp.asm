// Auto-generated scaffold unit: task_lst.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/task_lst.cpp
#include "../include/common.h"

// Offset: 0x00508E00
undefined RGE_Task_List(RGE_Task_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Task_List::RGE_Task_List(void)                                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Task_List(RGE_Task_List * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //                               ??0RGE_Task_List@@QAE@XZ                                     XREF[2]:     create_task_list:0044f572(c), 
    //                               RGE_Task_List::RGE_Task_List                                              create_task_list:0050ede3(c)  
    //                              task_lst.cpp:27 (2)
    //         00508e00     MOV        EAX,this
    //                              task_lst.cpp:28 (12)
    //         00508e02     XOR        this,this
    //         00508e04     MOV        dword ptr [EAX],RGE_Task_List::`vftable'         = 005090b0
    //         00508e0a     MOV        word ptr [EAX + 0x8],this
    //                              task_lst.cpp:29 (3)
    //         00508e0e     MOV        dword ptr [EAX + 0x4],this
    //                              task_lst.cpp:30 (1)
    //         00508e11     RET
}

// Offset: 0x00508E20
void RGE_Task_List(RGE_Task_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Task_List::~RGE_Task_List(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Task_List(RGE_Task_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //                               ??1RGE_Task_List@@QAE@XZ                                     XREF[1]:     ~RGE_Master_Action_Object:0044f508
    //                               RGE_Task_List::~RGE_Task_List
    //                              task_lst.cpp:35 (6)
    //         00508e20     MOV        dword ptr [this->_padding_],RGE_Task_List::`vf   = 005090b0
    //                              task_lst.cpp:36 (5)
    //         00508e26     JMP        RGE_Task_List::delete_list                       void delete_list(RGE_Task_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00508E30
void copy(RGE_Task_List* this_, RGE_Task_List* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Task_List::copy(class RGE_Task_List *)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall copy(RGE_Task_List * this, RGE_Task_List * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              RGE_Task_List *   Stack[0x4]:4   param_1                   XREF[3]:     00508e42(R), 00508e70(W), 00508e87(R)  
    //                               ?copy@RGE_Task_List@@QAEXPAV1@@Z                             XREF[2]:     setup:0044f27a(c), 
    //                               RGE_Task_List::copy                                                       copy_obj:0044f7e1(c)  
    //                              task_lst.cpp:42 (6)
    //         00508e30     PUSH       EBX
    //         00508e31     PUSH       EBP
    //         00508e32     PUSH       ESI
    //         00508e33     PUSH       EDI
    //         00508e34     MOV        EDI,this
    //                              task_lst.cpp:45 (7)
    //         00508e36     MOV        EAX,dword ptr [EDI + 0x4]
    //         00508e39     TEST       EAX,EAX
    //         00508e3b     JZ         LAB_00508e42
    //                              task_lst.cpp:46 (5)
    //         00508e3d     CALL       RGE_Task_List::delete_list                       void delete_list(RGE_Task_List * this)
    //                               LAB_00508e42                                                 XREF[1]:     00508e3b(j)  
    //                              task_lst.cpp:48 (8)
    //         00508e42     MOV        EBP,dword ptr [ESP + param_1]
    //         00508e46     MOV        AX,word ptr [EBP + 0x8]
    //                              task_lst.cpp:49 (9)
    //         00508e4a     TEST       AX,AX
    //         00508e4d     MOV        word ptr [EDI + 0x8],AX
    //         00508e51     JLE        LAB_00508eaa
    //                              task_lst.cpp:51 (11)
    //         00508e53     MOVSX      EAX,AX
    //         00508e56     PUSH       0x4
    //         00508e58     PUSH       EAX
    //         00508e59     CALL       calloc                                           undefined calloc()
    //                              task_lst.cpp:52 (14)
    //         00508e5e     XOR        EBX,EBX
    //         00508e60     ADD        ESP,0x8
    //         00508e63     CMP        word ptr [EDI + 0x8],BX
    //         00508e67     MOV        dword ptr [EDI + 0x4],EAX
    //         00508e6a     JLE        LAB_00508eaa
    //                              task_lst.cpp:54 (37)
    //         00508e6c     MOV        this,dword ptr [EDI]
    //         00508e6e     MOV        EDX,dword ptr [this->_padding_]
    //         00508e70     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00508e74                                                 XREF[1]:     00508ea8(j)  
    //         00508e74     MOV        EAX,dword ptr [EBP + 0x4]
    //         00508e77     PUSH       EBX
    //         00508e78     MOVSX      ESI,BX
    //         00508e7b     SHL        ESI,0x2
    //         00508e7e     MOV        this,dword ptr [EAX + ESI*0x1]
    //         00508e81     MOV        DX,word ptr [this->_padding_]
    //         00508e84     MOV        this,EDI
    //         00508e86     PUSH       EDX=>DAT_fffffff8
    //         00508e87     CALL       dword ptr [ESP + param_1]
    //         00508e8b     MOV        this,dword ptr [EDI + 0x4]
    //         00508e8e     MOV        dword ptr [this->_padding_ + ESI*0x1],EAX
    //                              task_lst.cpp:55 (25)
    //         00508e91     MOV        EDX,dword ptr [EBP + 0x4]
    //         00508e94     MOV        this,dword ptr [EDI + 0x4]
    //         00508e97     MOV        EAX,dword ptr [EDX + ESI*0x1]
    //         00508e9a     MOV        this,dword ptr [this->_padding_ + ESI*0x1]
    //         00508e9d     PUSH       EAX
    //         00508e9e     CALL       RGE_Task::copy                                   void copy(RGE_Task * this, RGE_Task * param_1)
    //         00508ea3     INC        EBX
    //         00508ea4     CMP        BX,word ptr [EDI + 0x8]
    //         00508ea8     JL         LAB_00508e74
    //                               LAB_00508eaa                                                 XREF[2]:     00508e51(j), 00508e6a(j)  
    //                              task_lst.cpp:58 (7)
    //         00508eaa     POP        EDI
    //         00508eab     POP        ESI
    //         00508eac     POP        EBP
    //         00508ead     POP        EBX
    //         00508eae     RET        0x4
}

// Offset: 0x00508EC0
void load(RGE_Task_List* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Task_List::load(int,class RGE_Sprite * *,class RGE_Sound * *)             *
    //                              *********************************************************************************************************
    //                              void __thiscall load(RGE_Task_List * this, int param_1, RGE_Sprite *
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     00508ed3(R), 00508f0a(W), 00508f2c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2
    //              RGE_Sound * *     Stack[0xc]:4   param_3
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00508f0e(*), 00508f1b(R)  
    //              short             Stack[-0x8]:2  task_type
    //                               ?load@RGE_Task_List@@QAEXHPAPAVRGE_Sprite@@PAPAVRGE_Sound@@@Z XREF[1]:     setup:0044f3ad(c)  
    //                               RGE_Task_List::load
    //                              task_lst.cpp:63 (6)
    //         00508ec0     PUSH       this
    //         00508ec1     PUSH       EBX
    //         00508ec2     MOV        EBX,this
    //         00508ec4     PUSH       EBP
    //         00508ec5     PUSH       ESI
    //                              task_lst.cpp:67 (8)
    //         00508ec6     MOV        EAX,dword ptr [EBX + 0x4]
    //         00508ec9     PUSH       EDI
    //         00508eca     TEST       EAX,EAX
    //         00508ecc     JZ         LAB_00508ed3
    //                              task_lst.cpp:68 (5)
    //         00508ece     CALL       RGE_Task_List::delete_list                       void delete_list(RGE_Task_List * this)
    //                               LAB_00508ed3                                                 XREF[1]:     00508ecc(j)  
    //                              task_lst.cpp:70 (16)
    //         00508ed3     MOV        EBP,dword ptr [ESP + param_1]
    //         00508ed7     LEA        ESI,[EBX + 0x8]
    //         00508eda     PUSH       0x2
    //         00508edc     PUSH       ESI
    //         00508edd     PUSH       EBP
    //         00508ede     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task_lst.cpp:71 (11)
    //         00508ee3     MOV        AX,word ptr [ESI]
    //         00508ee6     ADD        ESP,0xc
    //         00508ee9     TEST       AX,AX
    //         00508eec     JLE        LAB_00508f53
    //                              task_lst.cpp:73 (11)
    //         00508eee     MOVSX      EAX,AX
    //         00508ef1     PUSH       0x4
    //         00508ef3     PUSH       EAX
    //         00508ef4     CALL       calloc                                           undefined calloc()
    //                              task_lst.cpp:74 (13)
    //         00508ef9     XOR        EDI,EDI
    //         00508efb     ADD        ESP,0x8
    //         00508efe     CMP        word ptr [ESI],DI
    //         00508f01     MOV        dword ptr [EBX + 0x4],EAX
    //         00508f04     JLE        LAB_00508f53
    //                              task_lst.cpp:77 (45)
    //         00508f06     MOV        this,dword ptr [EBX]
    //         00508f08     MOV        EDX,dword ptr [this->_padding_]
    //         00508f0a     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00508f0e                                                 XREF[1]:     00508f51(j)  
    //         00508f0e     LEA        EAX=>local_4,[ESP + 0x10]
    //         00508f12     PUSH       0x2
    //         00508f14     PUSH       EAX=>DAT_fffffff8
    //         00508f15     PUSH       EBP=>DAT_fffffff4
    //         00508f16     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508f1b     MOV        this,dword ptr [ESP + local_4]
    //         00508f1f     ADD        ESP,0xc
    //         00508f22     MOVSX      ESI,DI
    //         00508f25     PUSH       EDI
    //         00508f26     PUSH       this
    //         00508f27     MOV        this,EBX
    //         00508f29     SHL        ESI,0x2
    //         00508f2c     CALL       dword ptr [ESP + param_1]
    //         00508f30     MOV        EDX,dword ptr [EBX + 0x4]
    //                              task_lst.cpp:78 (32)
    //         00508f33     MOV        this,dword ptr [ESP + 0x1c]
    //         00508f37     MOV        dword ptr [EDX + ESI*0x1],EAX
    //         00508f3a     MOV        EAX,dword ptr [ESP + 0x20]
    //         00508f3e     MOV        EDX,dword ptr [EBX + 0x4]
    //         00508f41     PUSH       EAX
    //         00508f42     PUSH       this=>DAT_fffffff8
    //         00508f43     PUSH       EBP=>DAT_fffffff4
    //         00508f44     MOV        this,dword ptr [EDX + ESI*0x1]
    //         00508f47     CALL       RGE_Task::load                                   void load(RGE_Task * this, int param_1, RGE_S
    //         00508f4c     INC        EDI
    //         00508f4d     CMP        DI,word ptr [EBX + 0x8]
    //         00508f51     JL         LAB_00508f0e
    //                               LAB_00508f53                                                 XREF[2]:     00508eec(j), 00508f04(j)  
    //                              task_lst.cpp:81 (8)
    //         00508f53     POP        EDI
    //         00508f54     POP        ESI
    //         00508f55     POP        EBP
    //         00508f56     POP        EBX
    //         00508f57     POP        this
    //         00508f58     RET        0xc
}

// Offset: 0x00508F60
void load(RGE_Task_List* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Task_List::load(struct _iobuf *,class RGE_Sprite * *,class RGE_Sound * *) *
    //                              *********************************************************************************************************
    //                              void __thiscall load(RGE_Task_List * this, _iobuf * param_1, RGE_Spr
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00508f73(R), 00508fad(W), 00508fd2(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2
    //              RGE_Sound * *     Stack[0xc]:4   param_3
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00508fb1(*), 00508fc1(R)  
    //              short             Stack[-0x8]:2  task_type
    //                               ?load@RGE_Task_List@@QAEXPAU_iobuf@@PAPAVRGE_Sprite@@PAPAVR  XREF[1]:     setup:0044f47b(c)  
    //                               RGE_Task_List::load
    //                              task_lst.cpp:86 (6)
    //         00508f60     PUSH       this
    //         00508f61     PUSH       EBX
    //         00508f62     MOV        EBX,this
    //         00508f64     PUSH       EBP
    //         00508f65     PUSH       ESI
    //                              task_lst.cpp:90 (8)
    //         00508f66     MOV        EAX,dword ptr [EBX + 0x4]
    //         00508f69     PUSH       EDI
    //         00508f6a     TEST       EAX,EAX
    //         00508f6c     JZ         LAB_00508f73
    //                              task_lst.cpp:91 (5)
    //         00508f6e     CALL       RGE_Task_List::delete_list                       void delete_list(RGE_Task_List * this)
    //                               LAB_00508f73                                                 XREF[1]:     00508f6c(j)  
    //                              task_lst.cpp:93 (19)
    //         00508f73     MOV        EBP,dword ptr [ESP + param_1]
    //         00508f77     LEA        ESI,[EBX + 0x8]
    //         00508f7a     PUSH       ESI
    //         00508f7b     PUSH       s_%hd                                            = "%hd"
    //         00508f80     PUSH       EBP
    //         00508f81     CALL       fscanf                                           undefined fscanf()
    //                              task_lst.cpp:96 (11)
    //         00508f86     MOV        AX,word ptr [ESI]
    //         00508f89     ADD        ESP,0xc
    //         00508f8c     TEST       AX,AX
    //         00508f8f     JLE        LAB_00508ff9
    //                              task_lst.cpp:98 (11)
    //         00508f91     MOVSX      EAX,AX
    //         00508f94     PUSH       0x4
    //         00508f96     PUSH       EAX
    //         00508f97     CALL       calloc                                           undefined calloc()
    //                              task_lst.cpp:99 (13)
    //         00508f9c     XOR        EDI,EDI
    //         00508f9e     ADD        ESP,0x8
    //         00508fa1     CMP        word ptr [ESI],DI
    //         00508fa4     MOV        dword ptr [EBX + 0x4],EAX
    //         00508fa7     JLE        LAB_00508ff9
    //                              task_lst.cpp:103 (48)
    //         00508fa9     MOV        this,dword ptr [EBX]
    //         00508fab     MOV        EDX,dword ptr [this->_padding_]
    //         00508fad     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00508fb1                                                 XREF[1]:     00508ff7(j)  
    //         00508fb1     LEA        EAX=>local_4,[ESP + 0x10]
    //         00508fb5     PUSH       EAX
    //         00508fb6     PUSH       s_%hd                                            = "%hd"
    //         00508fbb     PUSH       EBP=>DAT_fffffff4
    //         00508fbc     CALL       fscanf                                           undefined fscanf()
    //         00508fc1     MOV        this,dword ptr [ESP + local_4]
    //         00508fc5     ADD        ESP,0xc
    //         00508fc8     MOVSX      ESI,DI
    //         00508fcb     PUSH       EDI
    //         00508fcc     PUSH       this
    //         00508fcd     MOV        this,EBX
    //         00508fcf     SHL        ESI,0x2
    //         00508fd2     CALL       dword ptr [ESP + param_1]
    //         00508fd6     MOV        EDX,dword ptr [EBX + 0x4]
    //                              task_lst.cpp:104 (32)
    //         00508fd9     MOV        this,dword ptr [ESP + 0x1c]
    //         00508fdd     MOV        dword ptr [EDX + ESI*0x1],EAX
    //         00508fe0     MOV        EAX,dword ptr [ESP + 0x20]
    //         00508fe4     MOV        EDX,dword ptr [EBX + 0x4]
    //         00508fe7     PUSH       EAX
    //         00508fe8     PUSH       this=>DAT_fffffff8
    //         00508fe9     PUSH       EBP=>DAT_fffffff4
    //         00508fea     MOV        this,dword ptr [EDX + ESI*0x1]
    //         00508fed     CALL       RGE_Task::load                                   void load(RGE_Task * this, _iobuf * param_1, 
    //         00508ff2     INC        EDI
    //         00508ff3     CMP        DI,word ptr [EBX + 0x8]
    //         00508ff7     JL         LAB_00508fb1
    //                               LAB_00508ff9                                                 XREF[2]:     00508f8f(j), 00508fa7(j)  
    //                              task_lst.cpp:107 (8)
    //         00508ff9     POP        EDI
    //         00508ffa     POP        ESI
    //         00508ffb     POP        EBP
    //         00508ffc     POP        EBX
    //         00508ffd     POP        this
    //         00508ffe     RET        0xc
}

// Offset: 0x00509010
void save(RGE_Task_List* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Task_List::save(int)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Task_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00509012(R)  
    //                               ?save@RGE_Task_List@@QAEXH@Z                                 XREF[1]:     save:0044f965(c)  
    //                               RGE_Task_List::save
    //                              task_lst.cpp:112 (2)
    //         00509010     PUSH       EBX
    //         00509011     PUSH       EBP
    //                              task_lst.cpp:115 (20)
    //         00509012     MOV        EBP,dword ptr [ESP + param_1]
    //         00509016     MOV        EBX,this
    //         00509018     PUSH       ESI
    //         00509019     PUSH       EDI
    //         0050901a     LEA        EDI,[EBX + 0x8]
    //         0050901d     PUSH       0x2
    //         0050901f     PUSH       EDI
    //         00509020     PUSH       EBP
    //         00509021     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task_lst.cpp:117 (10)
    //         00509026     XOR        ESI,ESI
    //         00509028     ADD        ESP,0xc
    //         0050902b     CMP        word ptr [EDI],SI
    //         0050902e     JLE        LAB_00509045
    //                               LAB_00509030                                                 XREF[1]:     00509043(j)  
    //                              task_lst.cpp:118 (21)
    //         00509030     MOV        this,dword ptr [EBX + 0x4]
    //         00509033     PUSH       EBP
    //         00509034     MOVSX      EAX,SI
    //         00509037     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0050903a     CALL       RGE_Task::save                                   void save(RGE_Task * this, int param_1)
    //         0050903f     INC        ESI
    //         00509040     CMP        SI,word ptr [EDI]
    //         00509043     JL         LAB_00509030
    //                               LAB_00509045                                                 XREF[1]:     0050902e(j)  
    //                              task_lst.cpp:119 (7)
    //         00509045     POP        EDI
    //         00509046     POP        ESI
    //         00509047     POP        EBP
    //         00509048     POP        EBX
    //         00509049     RET        0x4
}

// Offset: 0x00509050
void delete_list(RGE_Task_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Task_List::delete_list(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_list(RGE_Task_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //                               ?delete_list@RGE_Task_List@@QAEXXZ                           XREF[4]:     ~RGE_Task_List:00508e26(c), 
    //                               RGE_Task_List::delete_list                                                copy:00508e3d(c), 
    //                                                                                                         load:00508ece(c), 
    //                                                                                                         load:00508f6e(c)  
    //                              task_lst.cpp:124 (4)
    //         00509050     PUSH       EBX
    //         00509051     MOV        EBX,this
    //         00509053     PUSH       EBP
    //                              task_lst.cpp:127 (7)
    //         00509054     XOR        EBP,EBP
    //         00509056     CMP        dword ptr [EBX + 0x4],EBP
    //         00509059     JZ         LAB_005090a7
    //                              task_lst.cpp:129 (8)
    //         0050905b     CMP        word ptr [EBX + 0x8],BP
    //         0050905f     JLE        LAB_00509096
    //         00509061     PUSH       EDI
    //         00509062     PUSH       ESI
    //                               LAB_00509063                                                 XREF[1]:     00509092(j)  
    //                              task_lst.cpp:131 (16)
    //         00509063     MOV        EAX,dword ptr [EBX + 0x4]
    //         00509066     MOVSX      ESI,BP
    //         00509069     SHL        ESI,0x2
    //         0050906c     MOV        EDI,dword ptr [EAX + ESI*0x1]
    //         0050906f     TEST       EDI,EDI
    //         00509071     JZ         LAB_0050908d
    //                              task_lst.cpp:133 (13)
    //         00509073     MOV        this,EDI
    //         00509075     CALL       RGE_Task::~RGE_Task                              void ~RGE_Task(RGE_Task * this)
    //         0050907a     PUSH       EDI
    //         0050907b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              task_lst.cpp:134 (22)
    //         00509080     MOV        this,dword ptr [EBX + 0x4]
    //         00509083     ADD        ESP,0x4
    //         00509086     MOV        dword ptr [this->_padding_ + ESI*0x1],0x0
    //                               LAB_0050908d                                                 XREF[1]:     00509071(j)  
    //         0050908d     INC        EBP
    //         0050908e     CMP        BP,word ptr [EBX + 0x8]
    //         00509092     JL         LAB_00509063
    //         00509094     POP        ESI
    //         00509095     POP        EDI
    //                               LAB_00509096                                                 XREF[1]:     0050905f(j)  
    //                              task_lst.cpp:137 (12)
    //         00509096     MOV        EDX,dword ptr [EBX + 0x4]
    //         00509099     PUSH       EDX
    //         0050909a     CALL       free                                             undefined free()
    //         0050909f     ADD        ESP,0x4
    //                              task_lst.cpp:138 (5)
    //         005090a2     XOR        EBP,EBP
    //         005090a4     MOV        dword ptr [EBX + 0x4],EBP
    //                               LAB_005090a7                                                 XREF[1]:     00509059(j)  
    //                              task_lst.cpp:141 (4)
    //         005090a7     MOV        word ptr [EBX + 0x8],BP
    //                              task_lst.cpp:142 (3)
    //         005090ab     POP        EBP
    //         005090ac     POP        EBX
    //         005090ad     RET
}

// Offset: 0x005090B0
RGE_Task* RGE_Task_List::create_task(short param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Task * __thiscall RGE_Task_List::create_task(short,short)                   *
    //                              *********************************************************************************************************
    //                              RGE_Task * __thiscall create_task(RGE_Task_List * this, short param_
    //              RGE_Task *        EAX:4          <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     005090b6(R), 005090d7(W)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     005090e7(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005090dd(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     005090f3(*), 00509104(*)  
    //                               ?create_task@RGE_Task_List@@UAEPAVRGE_Task@@FF@Z             XREF[2]:     00576530(*), 00576780(*)  
    //                               RGE_Task_List::create_task
    //                              task_lst.cpp:148 (6)
    //         005090b0     MOV        EAX,FS:[0x0]
    //                              task_lst.cpp:149 (23)
    //         005090b6     CMP        word ptr [ESP + param_1],0x1
    //         005090bc     PUSH       -0x1
    //         005090be     PUSH       FUN_00560d8b
    //         005090c3     PUSH       EAX
    //         005090c4     MOV        dword ptr FS:[0x0],ESP
    //         005090cb     JNZ        LAB_00509104
    //                              task_lst.cpp:150 (38)
    //         005090cd     PUSH       0x4c
    //         005090cf     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005090d4     ADD        ESP,0x4
    //         005090d7     MOV        dword ptr [ESP + param_1],EAX
    //         005090db     TEST       EAX,EAX
    //         005090dd     MOV        dword ptr [ESP + local_4],0x0
    //         005090e5     JZ         LAB_00509104
    //         005090e7     MOV        this,dword ptr [ESP + param_2]
    //         005090eb     PUSH       this
    //         005090ec     MOV        this,EAX
    //         005090ee     CALL       RGE_Task::RGE_Task                               undefined RGE_Task(RGE_Task * this, short par
    //                              task_lst.cpp:154 (36)
    //         005090f3     MOV        this,dword ptr [ESP]=>local_c
    //         005090f7     MOV        dword ptr FS:[0x0],this
    //         005090fe     ADD        ESP,0xc
    //         00509101     RET        0x8
    //                               LAB_00509104                                                 XREF[2]:     005090cb(j), 005090e5(j)  
    //         00509104     MOV        this,dword ptr [ESP]=>local_c
    //         00509108     XOR        EAX,EAX
    //         0050910a     MOV        dword ptr FS:[0x0],this
    //         00509111     ADD        ESP,0xc
    //         00509114     RET        0x8
}

// Offset: 0x00509120
RGE_Task* RGE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Task * __thiscall RGE_Task_List::get_target_task(class RGE_Action_Object... *
    //                              *********************************************************************************************************
    //                              RGE_Task * __thiscall get_target_task(RGE_Task_List * this, RGE_Acti
    //              RGE_Task *        EAX:4          <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[2]:     00509159(R), 00509193(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00509133(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00509233(R), 00509255(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00509244(R)  
    //              float             Stack[0x14]:4  param_5
    //                               ?get_target_task@RGE_Task_List@@UAEPAVRGE_Task@@PAVRGE_Acti  XREF[2]:     get_target_task:0052c894(c), 
    //                               RGE_Task_List::get_target_task                                            00576534(*)  
    //                              task_lst.cpp:159 (6)
    //         00509120     PUSH       EBX
    //         00509121     PUSH       EBP
    //         00509122     PUSH       ESI
    //         00509123     MOV        ESI,this
    //         00509125     PUSH       EDI
    //                              task_lst.cpp:168 (7)
    //         00509126     MOV        AX,word ptr [ESI + 0x8]
    //         0050912a     TEST       AX,AX
    //                              task_lst.cpp:169 (6)
    //         0050912d     JZ         LAB_005092bc
    //                              task_lst.cpp:171 (12)
    //         00509133     MOV        EDI,dword ptr [ESP + param_2]
    //         00509137     TEST       EDI,EDI
    //         00509139     JZ         LAB_00509233
    //                              task_lst.cpp:176 (7)
    //         0050913f     MOV        this,byte ptr [EDI + 0x48]
    //         00509142     TEST       this,this
    //         00509144     JNZ        LAB_00509178
    //                              task_lst.cpp:178 (7)
    //         00509146     XOR        EBP,EBP
    //         00509148     TEST       AX,AX
    //         0050914b     JLE        LAB_00509178
    //                               LAB_0050914d                                                 XREF[1]:     00509176(j)  
    //                              task_lst.cpp:180 (6)
    //         0050914d     MOV        EAX,dword ptr [ESI + 0x4]
    //         00509150     MOV        EBX,dword ptr [EAX + EBP*0x4]
    //                              task_lst.cpp:181 (28)
    //         00509153     CMP        byte ptr [EBX + 0x12],0x1
    //         00509157     JNZ        LAB_0050916f
    //         00509159     MOV        EAX,dword ptr [ESP + param_1]
    //         0050915d     MOV        EDX,dword ptr [ESI]
    //         0050915f     PUSH       EDI
    //         00509160     PUSH       EAX=>DAT_fffffff8
    //         00509161     PUSH       EBX=>DAT_fffffff4
    //         00509162     MOV        this,ESI
    //         00509164     CALL       dword ptr [EDX + 0xc]
    //         00509167     TEST       EAX,EAX
    //         00509169     JNZ        LAB_005092c5
    //                               LAB_0050916f                                                 XREF[1]:     00509157(j)  
    //                              task_lst.cpp:178 (9)
    //         0050916f     MOVSX      this,word ptr [ESI + 0x8]
    //         00509173     INC        EBP
    //         00509174     CMP        EBP,this
    //         00509176     JL         LAB_0050914d
    //                               LAB_00509178                                                 XREF[2]:     00509144(j), 0050914b(j)  
    //                              task_lst.cpp:186 (8)
    //         00509178     XOR        EBP,EBP
    //         0050917a     CMP        word ptr [ESI + 0x8],BP
    //         0050917e     JLE        LAB_005091b2
    //                               LAB_00509180                                                 XREF[1]:     005091b0(j)  
    //                              task_lst.cpp:188 (3)
    //         00509180     MOV        EDX,dword ptr [ESI + 0x4]
    //                              task_lst.cpp:189 (38)
    //         00509183     MOV        EAX,dword ptr [EDI + 0x8]
    //         00509186     MOV        EBX,dword ptr [EDX + EBP*0x4]
    //         00509189     MOV        this,word ptr [EBX + 0xa]
    //         0050918d     CMP        this,word ptr [EAX + 0x10]
    //         00509191     JNZ        LAB_005091a9
    //         00509193     MOV        EAX,dword ptr [ESP + param_1]
    //         00509197     MOV        EDX,dword ptr [ESI]
    //         00509199     PUSH       EDI
    //         0050919a     PUSH       EAX=>DAT_fffffff8
    //         0050919b     PUSH       EBX=>DAT_fffffff4
    //         0050919c     MOV        this,ESI
    //         0050919e     CALL       dword ptr [EDX + 0xc]
    //         005091a1     TEST       EAX,EAX
    //         005091a3     JNZ        LAB_005092c5
    //                               LAB_005091a9                                                 XREF[1]:     00509191(j)  
    //                              task_lst.cpp:186 (9)
    //         005091a9     MOVSX      this,word ptr [ESI + 0x8]
    //         005091ad     INC        EBP
    //         005091ae     CMP        EBP,this
    //         005091b0     JL         LAB_00509180
    //                               LAB_005091b2                                                 XREF[1]:     0050917e(j)  
    //                              task_lst.cpp:193 (8)
    //         005091b2     XOR        EBP,EBP
    //         005091b4     CMP        word ptr [ESI + 0x8],BP
    //         005091b8     JLE        LAB_005091ec
    //                               LAB_005091ba                                                 XREF[1]:     005091ea(j)  
    //                              task_lst.cpp:195 (3)
    //         005091ba     MOV        EDX,dword ptr [ESI + 0x4]
    //                              task_lst.cpp:196 (38)
    //         005091bd     MOV        EAX,dword ptr [EDI + 0x8]
    //         005091c0     MOV        EBX,dword ptr [EDX + EBP*0x4]
    //         005091c3     MOV        this,word ptr [EBX + 0x8]
    //         005091c7     CMP        this,word ptr [EAX + 0x14]
    //         005091cb     JNZ        LAB_005091e3
    //         005091cd     MOV        EAX,dword ptr [ESP + 0x14]
    //         005091d1     MOV        EDX,dword ptr [ESI]
    //         005091d3     PUSH       EDI
    //         005091d4     PUSH       EAX=>DAT_fffffff8
    //         005091d5     PUSH       EBX=>DAT_fffffff4
    //         005091d6     MOV        this,ESI
    //         005091d8     CALL       dword ptr [EDX + 0xc]
    //         005091db     TEST       EAX,EAX
    //         005091dd     JNZ        LAB_005092c5
    //                               LAB_005091e3                                                 XREF[1]:     005091cb(j)  
    //                              task_lst.cpp:193 (9)
    //         005091e3     MOVSX      this,word ptr [ESI + 0x8]
    //         005091e7     INC        EBP
    //         005091e8     CMP        EBP,this
    //         005091ea     JL         LAB_005091ba
    //                               LAB_005091ec                                                 XREF[1]:     005091b8(j)  
    //                              task_lst.cpp:203 (19)
    //         005091ec     CMP        byte ptr [EDI + 0x48],0x3
    //         005091f0     JNC        LAB_00509233
    //         005091f2     MOV        EDX,dword ptr [EDI + 0x8]
    //         005091f5     MOV        AL,byte ptr [EDX + 0x8c]
    //         005091fb     TEST       AL,AL
    //         005091fd     JBE        LAB_00509233
    //                              task_lst.cpp:206 (8)
    //         005091ff     XOR        EBP,EBP
    //         00509201     CMP        word ptr [ESI + 0x8],BP
    //         00509205     JLE        LAB_00509233
    //                               LAB_00509207                                                 XREF[1]:     00509231(j)  
    //                              task_lst.cpp:208 (6)
    //         00509207     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050920a     MOV        EBX,dword ptr [EAX + EBP*0x4]
    //                              task_lst.cpp:210 (29)
    //         0050920d     MOV        AL,byte ptr [EBX + 0xc]
    //         00509210     TEST       AL,AL
    //         00509212     JBE        LAB_0050922a
    //         00509214     MOV        EAX,dword ptr [ESP + 0x14]
    //         00509218     MOV        EDX,dword ptr [ESI]
    //         0050921a     PUSH       EDI
    //         0050921b     PUSH       EAX=>DAT_fffffff8
    //         0050921c     PUSH       EBX=>DAT_fffffff4
    //         0050921d     MOV        this,ESI
    //         0050921f     CALL       dword ptr [EDX + 0xc]
    //         00509222     TEST       EAX,EAX
    //         00509224     JNZ        LAB_005092c5
    //                               LAB_0050922a                                                 XREF[1]:     00509212(j)  
    //                              task_lst.cpp:206 (9)
    //         0050922a     MOVSX      this,word ptr [ESI + 0x8]
    //         0050922e     INC        EBP
    //         0050922f     CMP        EBP,this
    //         00509231     JL         LAB_00509207
    //                               LAB_00509233                                                 XREF[4]:     00509139(j), 005091f0(j), 
    //                                                                                                         005091fd(j), 00509205(j)  
    //                              task_lst.cpp:216 (34)
    //         00509233     FLD        float ptr [ESP + param_3]
    //         00509237     FCOMP      float ptr [DAT_00576540]                         = align(2)
    //         0050923d     FNSTSW     AX
    //         0050923f     TEST       AH,0x40
    //         00509242     JNZ        LAB_005092bc
    //         00509244     FLD        float ptr [ESP + param_4]
    //         00509248     FCOMP      float ptr [DAT_00576540]                         = align(2)
    //         0050924e     FNSTSW     AX
    //         00509250     TEST       AH,0x40
    //         00509253     JNZ        LAB_005092bc
    //                              task_lst.cpp:218 (9)
    //         00509255     FLD        float ptr [ESP + param_3]
    //         00509259     CALL       __ftol                                           undefined __ftol()
    //                              task_lst.cpp:219 (11)
    //         0050925e     FLD        float ptr [ESP + 0x20]
    //         00509262     MOV        EDI,EAX
    //         00509264     CALL       __ftol                                           undefined __ftol()
    //                              task_lst.cpp:221 (4)
    //         00509269     MOV        EDX,dword ptr [ESP + 0x14]
    //                              task_lst.cpp:223 (39)
    //         0050926d     TEST       DI,DI
    //         00509270     MOV        this,dword ptr [EDX + 0xc]
    //         00509273     MOV        EDX,dword ptr [this->_padding_ + 0x3c]
    //         00509276     MOV        this,dword ptr [EDX + 0x28]
    //         00509279     JL         LAB_005092bc
    //         0050927b     MOV        EBX,dword ptr [ECX + this->list_num]
    //         0050927e     MOVSX      EDX,DI
    //         00509281     CMP        EDX,EBX
    //         00509283     JGE        LAB_005092bc
    //         00509285     TEST       AX,AX
    //         00509288     JL         LAB_005092bc
    //         0050928a     MOV        EBX,dword ptr [ECX + this+0xc]
    //         0050928d     MOVSX      EDX,AX
    //         00509290     CMP        EDX,EBX
    //         00509292     JGE        LAB_005092bc
    //                              task_lst.cpp:225 (7)
    //         00509294     PUSH       EAX
    //         00509295     PUSH       EDI=>DAT_fffffff8
    //         00509296     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              task_lst.cpp:227 (14)
    //         0050929b     MOVSX      EDX,word ptr [ESI + 0x8]
    //         0050929f     XOR        this,this
    //         005092a1     TEST       EDX,EDX
    //         005092a3     MOVZX      DI,AL
    //         005092a7     JLE        LAB_005092bc
    //                              task_lst.cpp:237 (3)
    //         005092a9     MOV        ESI,dword ptr [ESI + 0x4]
    //                               LAB_005092ac                                                 XREF[1]:     005092ba(j)  
    //                              task_lst.cpp:229 (2)
    //         005092ac     MOV        EAX,dword ptr [ESI]
    //                              task_lst.cpp:230 (14)
    //         005092ae     CMP        word ptr [EAX + 0xe],DI
    //         005092b2     JZ         LAB_005092be
    //         005092b4     INC        this
    //         005092b5     ADD        ESI,0x4
    //         005092b8     CMP        this,EDX
    //         005092ba     JL         LAB_005092ac
    //                               LAB_005092bc                                                 XREF[8]:     0050912d(j), 00509242(j), 
    //                                                                                                         00509253(j), 00509279(j), 
    //                                                                                                         00509283(j), 00509288(j), 
    //                                                                                                         00509292(j), 005092a7(j)  
    //                              task_lst.cpp:236 (2)
    //         005092bc     XOR        EAX,EAX
    //                               LAB_005092be                                                 XREF[1]:     005092b2(j)  
    //                              task_lst.cpp:237 (16)
    //         005092be     POP        EDI
    //         005092bf     POP        ESI
    //         005092c0     POP        EBP
    //         005092c1     POP        EBX
    //         005092c2     RET        0x14
    //                               LAB_005092c5                                                 XREF[4]:     00509169(j), 005091a3(j), 
    //                                                                                                         005091dd(j), 00509224(j)  
    //         005092c5     POP        EDI
    //         005092c6     POP        ESI
    //         005092c7     MOV        EAX,EBX
    //         005092c9     POP        EBP
    //         005092ca     POP        EBX
    //         005092cb     RET        0x14
}

// Offset: 0x005092D0
int RGE_Task_List::is_attack_task(RGE_Task* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Task_List::is_attack_task(class RGE_Task *)                        *
    //                              *********************************************************************************************************
    //                              int __thiscall is_attack_task(RGE_Task_List * this, RGE_Task * param
    //              int               EAX:4          <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     005092d0(R)  
    //                               ?is_attack_task@RGE_Task_List@@UAEHPAVRGE_Task@@@Z           XREF[2]:     is_attack_task:0052c8e4(c), 
    //                               RGE_Task_List::is_attack_task                                             00576538(*)  
    //                              task_lst.cpp:242 (14)
    //         005092d0     MOV        this,dword ptr [ESP + param_1]
    //         005092d4     XOR        EAX,EAX
    //         005092d6     CMP        word ptr [ECX + this+0x6],0x7
    //         005092db     SETZ       AL
    //                              task_lst.cpp:247 (3)
    //         005092de     RET        0x4
}

// Offset: 0x005092F0
int RGE_Task_List::check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall RGE_Task_List::check_task(class RGE_Task *,class RGE_Action_Obje... *
    //                              *********************************************************************************************************
    //                              int __thiscall check_task(RGE_Task_List * this, RGE_Task * param_1, 
    //              int               EAX:4          <RETURN>
    //              RGE_Task_List *   ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     005092f0(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[2]:     00509322(R), 00509399(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     005092f5(R)  
    //                               ?check_task@RGE_Task_List@@MAEHPAVRGE_Task@@PAVRGE_Action_O  XREF[2]:     0057653c(*), 0057678c(*)  
    //                               RGE_Task_List::check_task
    //                              task_lst.cpp:252 (16)
    //         005092f0     MOV        this,dword ptr [ESP + param_1]
    //         005092f4     PUSH       ESI
    //         005092f5     MOV        ESI,dword ptr [ESP + param_3]
    //         005092f9     PUSH       EDI
    //         005092fa     CMP        byte ptr [this->_padding_ + 0x11],0x1
    //         005092fe     JNZ        LAB_00509322
    //                              task_lst.cpp:255 (27)
    //         00509300     CMP        word ptr [ESI + 0x4c],-0x1
    //         00509305     JZ         LAB_0050941c
    //         0050930b     FLD        float ptr [ESI + 0x44]
    //         0050930e     FCOMP      float ptr [DAT_00576544]
    //         00509314     FNSTSW     AX
    //         00509316     TEST       AH,0x41
    //         00509319     JZ         LAB_00509322
    //                              task_lst.cpp:256 (2)
    //         0050931b     XOR        EAX,EAX
    //                              task_lst.cpp:297 (5)
    //         0050931d     POP        EDI
    //         0050931e     POP        ESI
    //         0050931f     RET        0xc
    //                               LAB_00509322                                                 XREF[2]:     005092fe(j), 00509319(j)  
    //                              task_lst.cpp:259 (26)
    //         00509322     MOV        EDI,dword ptr [ESP + param_2]
    //         00509326     XOR        EAX,EAX
    //         00509328     MOV        AL,byte ptr [this->_padding_ + 0x10]
    //         0050932b     DEC        EAX
    //         0050932c     CMP        EAX,0x4
    //         0050932f     JA         switchD_00509335::default
    //                               switchD_00509335::switchD
    //         00509335     JMP        dword ptr [EAX*0x4 + switchD_00509335::switchd   = 0050933c
    //                               switchD_00509335::caseD_1                                    XREF[2]:     00509335(j), 00509430(*)  
    //                              task_lst.cpp:262 (14)
    //         0050933c     MOV        EAX,dword ptr [ESI + 0xc]
    //         0050933f     MOV        this,dword ptr [EDI + 0xc]
    //         00509342     CMP        EAX,this
    //         00509344     JZ         switchD_00509335::default
    //                              task_lst.cpp:263 (2)
    //         0050934a     XOR        EAX,EAX
    //                              task_lst.cpp:297 (5)
    //         0050934c     POP        EDI
    //         0050934d     POP        ESI
    //         0050934e     RET        0xc
    //                               switchD_00509335::caseD_2                                    XREF[2]:     00509335(j), 00509434(*)  
    //                              task_lst.cpp:267 (44)
    //         00509351     MOV        EAX,dword ptr [ESI + 0xc]
    //         00509354     MOV        this,dword ptr [EDI + 0xc]
    //         00509357     CMP        EAX,this
    //         00509359     JZ         LAB_0050941c
    //         0050935f     MOV        AX,word ptr [EAX + 0x4a]
    //         00509363     TEST       AX,AX
    //         00509366     JZ         LAB_0050941c
    //         0050936c     MOVSX      EDX,AX
    //         0050936f     PUSH       EDX
    //         00509370     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //         00509375     TEST       AL,AL
    //         00509377     JNZ        switchD_00509335::default
    //                              task_lst.cpp:268 (2)
    //         0050937d     XOR        EAX,EAX
    //                              task_lst.cpp:297 (5)
    //         0050937f     POP        EDI
    //         00509380     POP        ESI
    //         00509381     RET        0xc
    //                               switchD_00509335::caseD_3                                    XREF[2]:     00509335(j), 00509438(*)  
    //                              task_lst.cpp:272 (14)
    //         00509384     MOV        EAX,dword ptr [ESI + 0xc]
    //         00509387     CMP        word ptr [EAX + 0x4a],0x0
    //         0050938c     JZ         switchD_00509335::default
    //                              task_lst.cpp:273 (2)
    //         00509392     XOR        EAX,EAX
    //                              task_lst.cpp:297 (5)
    //         00509394     POP        EDI
    //         00509395     POP        ESI
    //         00509396     RET        0xc
    //                               switchD_00509335::caseD_4                                    XREF[2]:     00509335(j), 0050943c(*)  
    //                              task_lst.cpp:277 (14)
    //         00509399     MOV        EDI,dword ptr [ESP + param_2]
    //         0050939d     MOV        EAX,dword ptr [ESI + 0xc]
    //         005093a0     MOV        this,dword ptr [EDI + 0xc]
    //         005093a3     CMP        EAX,this
    //         005093a5     JNZ        LAB_005093b1
    //                              task_lst.cpp:278 (5)
    //         005093a7     MOV        EAX,0x1
    //                              task_lst.cpp:297 (5)
    //         005093ac     POP        EDI
    //         005093ad     POP        ESI
    //         005093ae     RET        0xc
    //                               LAB_005093b1                                                 XREF[1]:     005093a5(j)  
    //                              task_lst.cpp:279 (42)
    //         005093b1     MOV        AX,word ptr [EAX + 0x4a]
    //         005093b5     TEST       AX,AX
    //         005093b8     JZ         LAB_0050941c
    //         005093ba     MOV        EDX,dword ptr [this->_padding_]
    //         005093bc     MOVSX      EAX,AX
    //         005093bf     PUSH       EAX
    //         005093c0     CALL       dword ptr [EDX + 0x1c]
    //         005093c3     TEST       EAX,EAX
    //         005093c5     JZ         LAB_0050941c
    //         005093c7     MOV        EAX,dword ptr [EDI + 0xc]
    //         005093ca     MOV        this,dword ptr [ESI + 0xc]
    //         005093cd     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         005093d1     MOV        EDX,dword ptr [this->_padding_]
    //         005093d3     PUSH       EAX
    //         005093d4     CALL       dword ptr [EDX + 0x1c]
    //         005093d7     TEST       EAX,EAX
    //         005093d9     JZ         LAB_0050941c
    //                              task_lst.cpp:280 (5)
    //         005093db     MOV        EAX,0x1
    //                              task_lst.cpp:297 (5)
    //         005093e0     POP        EDI
    //         005093e1     POP        ESI
    //         005093e2     RET        0xc
    //                               switchD_00509335::caseD_5                                    XREF[2]:     00509335(j), 00509440(*)  
    //                              task_lst.cpp:288 (53)
    //         005093e5     MOV        EAX,dword ptr [ESI + 0xc]
    //         005093e8     MOV        this,dword ptr [EDI + 0xc]
    //         005093eb     CMP        EAX,this
    //         005093ed     JZ         LAB_0050941c
    //         005093ef     MOV        AX,word ptr [EAX + 0x4a]
    //         005093f3     TEST       AX,AX
    //         005093f6     JZ         LAB_00509405
    //         005093f8     MOVSX      EDX,AX
    //         005093fb     PUSH       EDX
    //         005093fc     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //         00509401     TEST       AL,AL
    //         00509403     JZ         LAB_0050941c
    //                               LAB_00509405                                                 XREF[1]:     005093f6(j)  
    //         00509405     MOV        EAX,dword ptr [ESI + 0xc]
    //         00509408     CMP        word ptr [EAX + 0x4a],0x0
    //         0050940d     JNZ        switchD_00509335::default
    //         0050940f     MOV        this,dword ptr [EDI + 0x8]
    //         00509412     MOV        AL,byte ptr [this->_padding_ + 0x8c]
    //         00509418     TEST       AL,AL
    //                              task_lst.cpp:290 (2)
    //         0050941a     JNZ        switchD_00509335::default
    //                               LAB_0050941c                                                 XREF[8]:     00509305(j), 00509359(j), 
    //                                                                                                         00509366(j), 005093b8(j), 
    //                                                                                                         005093c5(j), 005093d9(j), 
    //                                                                                                         005093ed(j), 00509403(j)  
    //                              task_lst.cpp:289 (2)
    //         0050941c     XOR        EAX,EAX
    //                              task_lst.cpp:297 (5)
    //         0050941e     POP        EDI
    //         0050941f     POP        ESI
    //         00509420     RET        0xc
    //                               switchD_00509335::default                                    XREF[6]:     0050932f(j), 00509344(j), 
    //                                                                                                         00509377(j), 0050938c(j), 
    //                                                                                                         0050940d(j), 0050941a(j)  
    //                              task_lst.cpp:293 (4)
    //         00509423     XOR        EAX,EAX
    //         00509425     CMP        EDI,ESI
    //                              task_lst.cpp:297 (29)
    //         00509427     POP        EDI
    //         00509428     POP        ESI
    //         00509429     SETNZ      AL
    //         0050942c     RET        0xc
}

