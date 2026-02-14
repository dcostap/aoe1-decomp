// Auto-generated scaffold unit: act_gath.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/ACT_GATH.cpp
#include "../include/common.h"

// Offset: 0x00402EA0
undefined RGE_Action_Gather(RGE_Action_Gather* this_, int param_2, RGE_Action_Object* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Gather::RGE_Action_Gather(int,class RGE_Action_Object *)                *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Gather(RGE_Action_Gather * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00402ebc(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00402eb6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00402ed6(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00402eef(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00402ec6(W)  
    //                               ??0RGE_Action_Gather@@QAE@HPAVRGE_Action_Object@@@Z          XREF[1]:     create_action:004040df(c)  
    //                               RGE_Action_Gather::RGE_Action_Gather
    //                              ACT_GATH.cpp:63 (47)
    //         00402ea0     PUSH       -0x1
    //         00402ea2     PUSH       FUN_0055c198
    //         00402ea7     MOV        EAX,FS:[0x0]
    //         00402ead     PUSH       EAX
    //         00402eae     MOV        dword ptr FS:[0x0],ESP
    //         00402eb5     PUSH       this
    //         00402eb6     MOV        EAX,dword ptr [ESP + param_2]
    //         00402eba     PUSH       ESI
    //         00402ebb     PUSH       EDI
    //         00402ebc     MOV        EDI,dword ptr [ESP + param_1]
    //         00402ec0     PUSH       0x1
    //         00402ec2     MOV        ESI,this
    //         00402ec4     PUSH       EAX
    //         00402ec5     PUSH       EDI
    //         00402ec6     MOV        dword ptr [ESP + local_10],ESI
    //         00402eca     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //                              ACT_GATH.cpp:65 (32)
    //         00402ecf     LEA        this,[ESI + 0x40]
    //         00402ed2     PUSH       0x4
    //         00402ed4     PUSH       this
    //         00402ed5     PUSH       EDI
    //         00402ed6     MOV        dword ptr [ESP + local_4],0x0
    //         00402ede     MOV        dword ptr [ESI],RGE_Action_Gather::`vftable'     = 00402f10
    //         00402ee4     MOV        word ptr [ESI + 0x4],0x5
    //         00402eea     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              ACT_GATH.cpp:66 (24)
    //         00402eef     MOV        this,dword ptr [ESP + local_c]
    //         00402ef3     ADD        ESP,0xc
    //         00402ef6     MOV        EAX,ESI
    //         00402ef8     MOV        dword ptr FS:[0x0],this
    //         00402eff     POP        EDI
    //         00402f00     POP        ESI
    //         00402f01     ADD        ESP,0x10
    //         00402f04     RET        0x8
}

// Offset: 0x00402F40
undefined RGE_Action_Gather(RGE_Action_Gather* this_, RGE_Action_Object* param_2, RGE_Task* param_3, RGE_Static_Object* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Gather::RGE_Action_Gather(class RGE_Action_Object *,class RGE_Task *... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Gather(RGE_Action_Gather * this, RGE
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00402f56(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00402f6a(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00402f6e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00402f78(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00402fb1(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00402f61(W)  
    //                               ??0RGE_Action_Gather@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[2]:     create_task_action:004043f8(c), 
    //                               RGE_Action_Gather::RGE_Action_Gather                                      gather:00430fd2(c)  
    //                              ACT_GATH.cpp:74 (42)
    //         00402f40     PUSH       -0x1
    //         00402f42     PUSH       FUN_0055c1b8
    //         00402f47     MOV        EAX,FS:[0x0]
    //         00402f4d     PUSH       EAX
    //         00402f4e     MOV        dword ptr FS:[0x0],ESP
    //         00402f55     PUSH       this
    //         00402f56     MOV        EAX,dword ptr [ESP + param_1]
    //         00402f5a     PUSH       ESI
    //         00402f5b     PUSH       EDI
    //         00402f5c     MOV        ESI,this
    //         00402f5e     PUSH       0x1
    //         00402f60     PUSH       EAX
    //         00402f61     MOV        dword ptr [ESP + local_10],ESI
    //         00402f65     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              ACT_GATH.cpp:77 (4)
    //         00402f6a     MOV        this,dword ptr [ESP + param_2]
    //                              ACT_GATH.cpp:78 (35)
    //         00402f6e     MOV        EDI,dword ptr [ESP + param_3]
    //         00402f72     MOV        dword ptr [ESI + 0x30],this
    //         00402f75     PUSH       EDI
    //         00402f76     MOV        this,ESI
    //         00402f78     MOV        dword ptr [ESP + local_4],0x0
    //         00402f80     MOV        dword ptr [ESI],RGE_Action_Gather::`vftable'     = 00402f10
    //         00402f86     MOV        word ptr [ESI + 0x4],0x5
    //         00402f8c     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
    //                              ACT_GATH.cpp:79 (4)
    //         00402f91     TEST       EDI,EDI
    //         00402f93     JZ         LAB_00402fb1
    //                              ACT_GATH.cpp:81 (6)
    //         00402f95     MOV        EDX,dword ptr [EDI + 0x38]
    //         00402f98     MOV        dword ptr [ESI + 0x20],EDX
    //                              ACT_GATH.cpp:82 (6)
    //         00402f9b     MOV        EAX,dword ptr [EDI + 0x3c]
    //         00402f9e     MOV        dword ptr [ESI + 0x24],EAX
    //                              ACT_GATH.cpp:83 (6)
    //         00402fa1     MOV        this,dword ptr [EDI + 0x40]
    //         00402fa4     MOV        dword ptr [ESI + 0x28],this
    //                              ACT_GATH.cpp:84 (10)
    //         00402fa7     MOV        EDX,dword ptr [EDI + 0x8]
    //         00402faa     MOVSX      EAX,word ptr [EDX + 0x10]
    //         00402fae     MOV        dword ptr [ESI + 0x40],EAX
    //                               LAB_00402fb1                                                 XREF[1]:     00402f93(j)  
    //                              ACT_GATH.cpp:90 (21)
    //         00402fb1     MOV        this,dword ptr [ESP + local_c]
    //         00402fb5     MOV        EAX,ESI
    //         00402fb7     POP        EDI
    //         00402fb8     MOV        dword ptr FS:[0x0],this
    //         00402fbf     POP        ESI
    //         00402fc0     ADD        ESP,0x10
    //         00402fc3     RET        0xc
}

// Offset: 0x00402FD0
undefined RGE_Action_Gather(RGE_Action_Gather* this_, RGE_Action_Object* param_2, RGE_Task* param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Gather::RGE_Action_Gather(class RGE_Action_Object *,class RGE_Task *... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Gather(RGE_Action_Gather * this, RGE
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00402fd0(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00402fdf(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00402fe7(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00402fe3(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00402fee(R)  
    //                               ??0RGE_Action_Gather@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[1]:     create_task_action:0040442d(c)  
    //                               RGE_Action_Gather::RGE_Action_Gather
    //                              ACT_GATH.cpp:98 (15)
    //         00402fd0     MOV        EAX,dword ptr [ESP + param_1]
    //         00402fd4     PUSH       ESI
    //         00402fd5     PUSH       0x1
    //         00402fd7     MOV        ESI,this
    //         00402fd9     PUSH       EAX
    //         00402fda     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              ACT_GATH.cpp:101 (4)
    //         00402fdf     MOV        this,dword ptr [ESP + param_2]
    //                              ACT_GATH.cpp:103 (11)
    //         00402fe3     MOV        EAX,dword ptr [ESP + param_4]
    //         00402fe7     MOV        EDX,dword ptr [ESP + param_3]
    //         00402feb     MOV        dword ptr [ESI + 0x30],this
    //                              ACT_GATH.cpp:104 (25)
    //         00402fee     MOV        this,dword ptr [ESP + param_5]
    //         00402ff2     MOV        dword ptr [ESI + 0x24],EAX
    //         00402ff5     MOV        dword ptr [ESI],RGE_Action_Gather::`vftable'     = 00402f10
    //         00402ffb     MOV        word ptr [ESI + 0x4],0x5
    //         00403001     MOV        dword ptr [ESI + 0x20],EDX
    //         00403004     MOV        dword ptr [ESI + 0x28],this
    //                              ACT_GATH.cpp:105 (7)
    //         00403007     MOV        dword ptr [ESI + 0x40],0xffffffff
    //                              ACT_GATH.cpp:110 (6)
    //         0040300e     MOV        EAX,ESI
    //         00403010     POP        ESI
    //         00403011     RET        0x14
}

// Offset: 0x00403020
void RGE_Action_Gather::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Gather::save(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Action_Gather * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00403022(R)  
    //                               ?save@RGE_Action_Gather@@UAEXH@Z                             XREF[1]:     0056e22c(*)  
    //                               RGE_Action_Gather::save
    //                              ACT_GATH.cpp:116 (2)
    //         00403020     PUSH       ESI
    //         00403021     PUSH       EDI
    //                              ACT_GATH.cpp:117 (12)
    //         00403022     MOV        EDI,dword ptr [ESP + param_1]
    //         00403026     MOV        ESI,this
    //         00403028     PUSH       EDI
    //         00403029     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
    //                              ACT_GATH.cpp:118 (15)
    //         0040302e     ADD        ESI,0x40
    //         00403031     PUSH       0x4
    //         00403033     PUSH       ESI
    //         00403034     PUSH       EDI
    //         00403035     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040303a     ADD        ESP,0xc
    //                              ACT_GATH.cpp:119 (5)
    //         0040303d     POP        EDI
    //         0040303e     POP        ESI
    //         0040303f     RET        0x4
}

// Offset: 0x00403050
void RGE_Action_Gather::first_in_stack(uchar param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Gather::first_in_stack(unsigned char)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall first_in_stack(RGE_Action_Gather * this, uchar param
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040306f(R)  
    //                               ?first_in_stack@RGE_Action_Gather@@UAEXE@Z                   XREF[1]:     0056e234(*)  
    //                               RGE_Action_Gather::first_in_stack
    //                              ACT_GATH.cpp:125 (4)
    //         00403050     PUSH       ESI
    //         00403051     MOV        ESI,this
    //         00403053     PUSH       EDI
    //                              ACT_GATH.cpp:129 (3)
    //         00403054     MOV        EAX,dword ptr [ESI + 0x30]
    //                              ACT_GATH.cpp:130 (13)
    //         00403057     MOV        this,dword ptr [ESI + 0x8]
    //         0040305a     MOV        AX,word ptr [EAX + 0x14]
    //         0040305e     CMP        word ptr [this->_padding_ + 0x4c],AX
    //         00403062     JZ         LAB_0040306f
    //                              ACT_GATH.cpp:131 (11)
    //         00403064     MOV        EDX,dword ptr [this->_padding_]
    //         00403066     PUSH       0x0
    //         00403068     PUSH       EAX
    //         00403069     CALL       dword ptr [EDX + 0x80]
    //                               LAB_0040306f                                                 XREF[1]:     00403062(j)  
    //                              ACT_GATH.cpp:133 (12)
    //         0040306f     MOV        AL,byte ptr [ESP + param_1]
    //         00403073     TEST       AL,AL
    //         00403075     JZ         LAB_004030fe
    //                              ACT_GATH.cpp:135 (7)
    //         0040307b     MOV        this,dword ptr [ESI + 0x10]
    //         0040307e     TEST       this,this
    //         00403080     JZ         LAB_004030f0
    //                              ACT_GATH.cpp:142 (55)
    //         00403082     MOV        EDI,dword ptr [ESI + 0x8]
    //         00403085     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00403088     CMP        EAX,dword ptr [EDI + 0xc]
    //         0040308b     JNZ        LAB_004030e2
    //         0040308d     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00403090     MOV        EAX,dword ptr [EDI + 0x8]
    //         00403093     MOV        DX,word ptr [EDX + 0x10]
    //         00403097     CMP        DX,word ptr [EAX + 0xe8]
    //         0040309e     JZ         LAB_004030a9
    //         004030a0     CMP        DX,word ptr [EAX + 0xea]
    //         004030a7     JNZ        LAB_004030e2
    //                               LAB_004030a9                                                 XREF[1]:     0040309e(j)  
    //         004030a9     FLD        float ptr [EDI + 0x44]
    //         004030ac     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         004030b2     FNSTSW     AX
    //         004030b4     TEST       AH,0x41
    //         004030b7     JNZ        LAB_004030e2
    //                              ACT_GATH.cpp:144 (8)
    //         004030b9     MOV        EDI,dword ptr [ESI]
    //         004030bb     PUSH       this
    //         004030bc     MOV        this,ESI
    //         004030be     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:145 (7)
    //         004030c1     PUSH       0x0
    //         004030c3     MOV        this,ESI
    //         004030c5     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:146 (5)
    //         004030c8     MOV        EAX,0xbf800000
    //                              ACT_GATH.cpp:149 (16)
    //         004030cd     PUSH       0x8
    //         004030cf     MOV        this,ESI
    //         004030d1     MOV        dword ptr [ESI + 0x20],EAX
    //         004030d4     MOV        dword ptr [ESI + 0x24],EAX
    //         004030d7     MOV        dword ptr [ESI + 0x28],EAX
    //         004030da     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:159 (5)
    //         004030dd     POP        EDI
    //         004030de     POP        ESI
    //         004030df     RET        0x4
    //                               LAB_004030e2                                                 XREF[3]:     0040308b(j), 004030a7(j), 
    //                                                                                                         004030b7(j)  
    //                              ACT_GATH.cpp:152 (4)
    //         004030e2     MOV        EAX,dword ptr [ESI]
    //         004030e4     PUSH       0x4
    //                              ACT_GATH.cpp:158 (5)
    //         004030e6     MOV        this,ESI
    //         004030e8     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:159 (5)
    //         004030eb     POP        EDI
    //         004030ec     POP        ESI
    //         004030ed     RET        0x4
    //                               LAB_004030f0                                                 XREF[1]:     00403080(j)  
    //                              ACT_GATH.cpp:155 (9)
    //         004030f0     MOV        EDX,dword ptr [ESI]
    //         004030f2     PUSH       0x3
    //         004030f4     MOV        this,ESI
    //         004030f6     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:159 (5)
    //         004030f9     POP        EDI
    //         004030fa     POP        ESI
    //         004030fb     RET        0x4
    //                               LAB_004030fe                                                 XREF[1]:     00403075(j)  
    //                              ACT_GATH.cpp:158 (9)
    //         004030fe     MOV        EAX,dword ptr [ESI]
    //         00403100     PUSH       0x3
    //         00403102     MOV        this,ESI
    //         00403104     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:159 (5)
    //         00403107     POP        EDI
    //         00403108     POP        ESI
    //         00403109     RET        0x4
}

// Offset: 0x00403110
void RGE_Action_Gather::set_state(uchar param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Action_Gather::set_state(unsigned char)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state(RGE_Action_Gather * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[3]:     00403131(R), 004031d8(W), 004032a9(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004031de(W), 00403216(W), 004032af(W), 0040344d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0040324e(R), 0040353c(R)  
    //                               ?set_state@RGE_Action_Gather@@MAEXE@Z                        XREF[1]:     0056e274(*)  
    //                               RGE_Action_Gather::set_state
    //                              ACT_GATH.cpp:165 (25)
    //         00403110     MOV        EAX,FS:[0x0]
    //         00403116     PUSH       -0x1
    //         00403118     PUSH       FUN_0055c1f1
    //         0040311d     PUSH       EAX
    //         0040311e     MOV        dword ptr FS:[0x0],ESP
    //         00403125     PUSH       ESI
    //         00403126     MOV        ESI,this
    //         00403128     PUSH       EDI
    //                              ACT_GATH.cpp:175 (8)
    //         00403129     MOV        this,dword ptr [ESI + 0x34]
    //         0040312c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              ACT_GATH.cpp:178 (7)
    //         00403131     MOV        EAX,dword ptr [ESP + param_1]
    //         00403135     MOV        byte ptr [ESI + 0xc],AL
    //                              ACT_GATH.cpp:180 (22)
    //         00403138     AND        EAX,0xff
    //         0040313d     DEC        EAX
    //         0040313e     CMP        EAX,0xe
    //         00403141     JA         switchD_00403147::caseD_4
    //                               switchD_00403147::switchD
    //         00403147     JMP        dword ptr [EAX*0x4 + switchD_00403147::switchd   = 00403522
    //                               switchD_00403147::caseD_2                                    XREF[2]:     00403147(j), 00403558(*)  
    //                              ACT_GATH.cpp:189 (32)
    //         0040314e     MOV        this,dword ptr [ESI + 0x8]
    //         00403151     MOV        EDI,dword ptr [ESI + 0x40]
    //         00403154     PUSH       0x0
    //         00403156     PUSH       EDI
    //         00403157     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040315a     MOV        EDX,dword ptr [this->_padding_]
    //         0040315c     PUSH       0x261
    //         00403161     PUSH       0x202
    //         00403166     PUSH       EAX
    //         00403167     PUSH       EAX
    //         00403168     CALL       dword ptr [EDX + 0x148]
    //                              ACT_GATH.cpp:191 (7)
    //         0040316e     MOV        dword ptr [ESI + 0x2c],0xc1200000
    //                              ACT_GATH.cpp:193 (5)
    //         00403175     JMP        LAB_00403529
    //                               switchD_00403147::caseD_1                                    XREF[2]:     00403147(j), 00403554(*)  
    //                              ACT_GATH.cpp:198 (26)
    //         0040317a     MOV        this,dword ptr [ESI + 0x8]
    //         0040317d     MOV        dword ptr [ESI + 0x2c],0x0
    //         00403184     MOV        EDI,dword ptr [this->_padding_]
    //         00403186     MOV        this,ESI
    //         00403188     CALL       RGE_Action_Gather::get_wait_sprite               RGE_Sprite * get_wait_sprite(RGE_Action_Gathe
    //         0040318d     MOV        this,dword ptr [ESI + 0x8]
    //         00403190     PUSH       EAX
    //         00403191     CALL       dword ptr [EDI + 0x38]
    //                              ACT_GATH.cpp:199 (9)
    //         00403194     MOV        EDI,dword ptr [ESI]
    //         00403196     PUSH       0x0
    //         00403198     MOV        this,ESI
    //         0040319a     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:200 (7)
    //         0040319d     PUSH       0x0
    //         0040319f     MOV        this,ESI
    //         004031a1     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:201 (8)
    //         004031a4     MOV        EAX,0xbf800000
    //         004031a9     MOV        dword ptr [ESI + 0x20],EAX
    //                              ACT_GATH.cpp:202 (3)
    //         004031ac     MOV        dword ptr [ESI + 0x24],EAX
    //                              ACT_GATH.cpp:203 (3)
    //         004031af     MOV        dword ptr [ESI + 0x28],EAX
    //                              ACT_GATH.cpp:377 (19)
    //         004031b2     MOV        this,dword ptr [ESP + 0x8]
    //         004031b6     MOV        dword ptr FS:[0x0],this
    //         004031bd     POP        EDI
    //         004031be     POP        ESI
    //         004031bf     ADD        ESP,0xc
    //         004031c2     RET        0x4
    //                               switchD_00403147::caseD_e                                    XREF[3]:     00403147(j), 00403578(*), 
    //                               switchD_00403147::caseD_a                                                 00403588(*)  
    //                              ACT_GATH.cpp:216 (79)
    //         004031c5     PUSH       0x44
    //         004031c7     MOV        dword ptr [ESI + 0x2c],0x0
    //         004031ce     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004031d3     MOV        EDI,EAX
    //         004031d5     ADD        ESP,0x4
    //         004031d8     MOV        dword ptr [ESP + param_1],EDI
    //         004031dc     TEST       EDI,EDI
    //         004031de     MOV        dword ptr [ESP + local_4],0x0
    //         004031e6     JZ         LAB_00403212
    //         004031e8     MOV        this,ESI
    //         004031ea     CALL       RGE_Action_Gather::get_move_sprite               RGE_Sprite * get_move_sprite(RGE_Action_Gathe
    //         004031ef     MOV        EDX,dword ptr [ESI + 0x30]
    //         004031f2     MOV        this,dword ptr [ESI + 0x28]
    //         004031f5     PUSH       EAX
    //         004031f6     MOV        EAX,dword ptr [EDX + 0x24]
    //         004031f9     MOV        EDX,dword ptr [ESI + 0x24]
    //         004031fc     PUSH       EAX
    //         004031fd     MOV        EAX,dword ptr [ESI + 0x20]
    //         00403200     PUSH       this
    //         00403201     MOV        this,dword ptr [ESI + 0x8]
    //         00403204     PUSH       EDX
    //         00403205     PUSH       EAX
    //         00403206     PUSH       this
    //         00403207     MOV        this,EDI
    //         00403209     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         0040320e     MOV        EDI,EAX
    //         00403210     JMP        LAB_00403214
    //                               LAB_00403212                                                 XREF[1]:     004031e6(j)  
    //         00403212     XOR        EDI,EDI
    //                               LAB_00403214                                                 XREF[1]:     00403210(j)  
    //                              ACT_GATH.cpp:217 (12)
    //         00403214     TEST       EDI,EDI
    //         00403216     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0040321e     JNZ        LAB_0040323c
    //                              ACT_GATH.cpp:219 (9)
    //         00403220     MOV        EDX,dword ptr [ESI]
    //         00403222     PUSH       0xd
    //         00403224     MOV        this,ESI
    //         00403226     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:377 (19)
    //         00403229     MOV        this,dword ptr [ESP + 0x8]
    //         0040322d     MOV        dword ptr FS:[0x0],this
    //         00403234     POP        EDI
    //         00403235     POP        ESI
    //         00403236     ADD        ESP,0xc
    //         00403239     RET        0x4
    //                               LAB_0040323c                                                 XREF[1]:     0040321e(j)  
    //                              ACT_GATH.cpp:222 (9)
    //         0040323c     PUSH       0x1
    //         0040323e     MOV        this,EDI
    //         00403240     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
    //                              ACT_GATH.cpp:223 (9)
    //         00403245     MOV        this,dword ptr [ESI + 0x34]
    //         00403248     PUSH       EDI
    //         00403249     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                              ACT_GATH.cpp:377 (19)
    //         0040324e     MOV        this,dword ptr [ESP + local_c]
    //         00403252     MOV        dword ptr FS:[0x0],this
    //         00403259     POP        EDI
    //         0040325a     POP        ESI
    //         0040325b     ADD        ESP,0xc
    //         0040325e     RET        0x4
    //                               switchD_00403147::caseD_3                                    XREF[2]:     00403147(j), 0040355c(*)  
    //                              ACT_GATH.cpp:231 (14)
    //         00403261     MOV        EAX,dword ptr [ESI + 0x10]
    //         00403264     MOV        dword ptr [ESI + 0x2c],0x0
    //         0040326b     TEST       EAX,EAX
    //         0040326d     JNZ        LAB_0040328b
    //                              ACT_GATH.cpp:233 (9)
    //         0040326f     MOV        EAX,dword ptr [ESI]
    //         00403271     PUSH       0xd
    //         00403273     MOV        this,ESI
    //         00403275     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:377 (19)
    //         00403278     MOV        this,dword ptr [ESP + 0x8]
    //         0040327c     MOV        dword ptr FS:[0x0],this
    //         00403283     POP        EDI
    //         00403284     POP        ESI
    //         00403285     ADD        ESP,0xc
    //         00403288     RET        0x4
    //                               LAB_0040328b                                                 XREF[1]:     0040326d(j)  
    //                              ACT_GATH.cpp:237 (3)
    //         0040328b     MOV        this,dword ptr [EAX + 0x38]
    //                              ACT_GATH.cpp:242 (64)
    //         0040328e     PUSH       0x44
    //         00403290     MOV        dword ptr [ESI + 0x20],this
    //         00403293     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00403296     MOV        dword ptr [ESI + 0x24],EDX
    //         00403299     MOV        EAX,dword ptr [EAX + 0x40]
    //         0040329c     MOV        dword ptr [ESI + 0x28],EAX
    //         0040329f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004032a4     MOV        EDI,EAX
    //         004032a6     ADD        ESP,0x4
    //         004032a9     MOV        dword ptr [ESP + param_1],EDI
    //         004032ad     TEST       EDI,EDI
    //         004032af     MOV        dword ptr [ESP + local_4],0x1
    //         004032b7     JZ         LAB_00403449
    //         004032bd     MOV        this,ESI
    //         004032bf     CALL       RGE_Action_Gather::get_move_sprite               RGE_Sprite * get_move_sprite(RGE_Action_Gathe
    //         004032c4     MOV        this,dword ptr [ESI + 0x30]
    //         004032c7     PUSH       EAX
    //         004032c8     MOV        EAX,dword ptr [ESI + 0x10]
    //         004032cb     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              ACT_GATH.cpp:325 (20)
    //         004032ce     MOV        this,dword ptr [ESI + 0x8]
    //         004032d1     PUSH       EDX
    //         004032d2     PUSH       EAX
    //         004032d3     PUSH       this
    //         004032d4     MOV        this,EDI
    //         004032d6     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         004032db     MOV        EDI,EAX
    //         004032dd     JMP        LAB_0040344b
    //                               switchD_00403147::caseD_5                                    XREF[2]:     00403147(j), 00403564(*)  
    //                              ACT_GATH.cpp:256 (19)
    //         004032e2     MOV        EAX,dword ptr [ESI + 0x8]
    //         004032e5     MOV        this,ESI
    //         004032e7     MOV        dword ptr [ESI + 0x2c],0x0
    //         004032ee     MOV        EDI,dword ptr [EAX]
    //         004032f0     CALL       RGE_Action_Gather::get_move_sprite               RGE_Sprite * get_move_sprite(RGE_Action_Gathe
    //                              ACT_GATH.cpp:257 (5)
    //         004032f5     JMP        LAB_00403535
    //                               switchD_00403147::caseD_6                                    XREF[2]:     00403147(j), 00403568(*)  
    //                              ACT_GATH.cpp:265 (14)
    //         004032fa     MOV        this,dword ptr [ESI + 0x30]
    //         004032fd     MOV        dword ptr [ESI + 0x2c],0x0
    //         00403304     MOV        AX,word ptr [ECX + this->_padding_]
    //                              ACT_GATH.cpp:266 (9)
    //         00403308     MOV        this,dword ptr [ESI + 0x8]
    //         0040330b     CMP        word ptr [this->_padding_ + 0x4c],AX
    //         0040330f     JZ         LAB_0040331c
    //                              ACT_GATH.cpp:267 (11)
    //         00403311     MOV        EDX,dword ptr [this->_padding_]
    //         00403313     PUSH       0x0
    //         00403315     PUSH       EAX
    //         00403316     CALL       dword ptr [EDX + 0x80]
    //                               LAB_0040331c                                                 XREF[1]:     0040330f(j)  
    //                              ACT_GATH.cpp:270 (15)
    //         0040331c     MOV        EDX,dword ptr [ESI + 0x30]
    //         0040331f     MOV        this,dword ptr [ESI + 0x8]
    //         00403322     MOV        EDX,dword ptr [EDX + 0x38]
    //         00403325     MOV        EAX,dword ptr [this->_padding_]
    //         00403327     PUSH       EDX
    //         00403328     CALL       dword ptr [EAX + 0x38]
    //                              ACT_GATH.cpp:273 (14)
    //         0040332b     MOV        EAX,dword ptr [ESI + 0x30]
    //         0040332e     MOV        this,dword ptr [EAX + 0x44]
    //         00403331     TEST       this,this
    //         00403333     JZ         switchD_00403147::caseD_4
    //                              ACT_GATH.cpp:274 (7)
    //         00403339     PUSH       0x1
    //         0040333b     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
    //                              ACT_GATH.cpp:377 (19)
    //         00403340     MOV        this,dword ptr [ESP + 0x8]
    //         00403344     MOV        dword ptr FS:[0x0],this
    //         0040334b     POP        EDI
    //         0040334c     POP        ESI
    //         0040334d     ADD        ESP,0xc
    //         00403350     RET        0x4
    //                               switchD_00403147::caseD_7                                    XREF[2]:     00403147(j), 0040356c(*)  
    //                              ACT_GATH.cpp:282 (23)
    //         00403353     MOV        this,dword ptr [ESI + 0x8]
    //         00403356     FLD        float ptr [ECX + this+0x44]
    //         00403359     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         0040335f     FNSTSW     AX
    //         00403361     TEST       AH,0x41
    //         00403364     JNZ        LAB_004034d2
    //                              ACT_GATH.cpp:285 (11)
    //         0040336a     MOV        EAX,dword ptr [ESI + 0x14]
    //         0040336d     TEST       EAX,EAX
    //         0040336f     JNZ        LAB_0040340b
    //                              ACT_GATH.cpp:290 (13)
    //         00403375     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00403378     CMP        word ptr [EDX + 0xe8],-0x1
    //         00403380     JZ         LAB_004033f7
    //                              ACT_GATH.cpp:295 (8)
    //         00403382     MOV        EAX,dword ptr [this->_padding_]
    //         00403384     CALL       dword ptr [EAX + 0x140]
    //                              ACT_GATH.cpp:299 (58)
    //         0040338a     MOV        EDI,dword ptr [ESI]
    //         0040338c     CMP        AL,0x1
    //         0040338e     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403391     MOV        this,dword ptr [EAX + 0x8]
    //         00403394     JNZ        LAB_004033c6
    //         00403396     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00403399     PUSH       EAX
    //         0040339a     PUSH       offset DAT_fffffff8
    //         0040339c     PUSH       offset DAT_fffffff4
    //         0040339e     PUSH       EDX=>DAT_fffffff0
    //         0040339f     MOV        EDX,dword ptr [EAX + 0x38]
    //         004033a2     PUSH       EDX
    //         004033a3     MOVSX      EDX,word ptr [this->_padding_ + 0xea]
    //         004033aa     MOVSX      this,word ptr [this->_padding_ + 0xe8]
    //         004033b1     PUSH       EDX
    //         004033b2     MOV        EDX,dword ptr [EAX + 0xc]
    //         004033b5     PUSH       this
    //         004033b6     MOV        this,dword ptr [EDX + 0x28]
    //         004033b9     CALL       RGE_Object_List::find_by_master_ids              RGE_Static_Object * find_by_master_ids(RGE_Ob
    //         004033be     PUSH       EAX
    //         004033bf     MOV        this,ESI
    //         004033c1     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:301 (2)
    //         004033c4     JMP        LAB_00403400
    //                               LAB_004033c6                                                 XREF[1]:     00403394(j)  
    //                              ACT_GATH.cpp:305 (47)
    //         004033c6     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004033c9     PUSH       0x0
    //         004033cb     PUSH       offset DAT_fffffff8
    //         004033cd     PUSH       offset DAT_fffffff4
    //         004033cf     PUSH       EDX=>DAT_fffffff0
    //         004033d0     MOV        EDX,dword ptr [EAX + 0x38]
    //         004033d3     PUSH       EDX
    //         004033d4     MOVSX      EDX,word ptr [this->_padding_ + 0xea]
    //         004033db     MOVSX      this,word ptr [this->_padding_ + 0xe8]
    //         004033e2     PUSH       EDX
    //         004033e3     MOV        EDX,dword ptr [EAX + 0xc]
    //         004033e6     PUSH       this
    //         004033e7     MOV        this,dword ptr [EDX + 0x28]
    //         004033ea     CALL       RGE_Object_List::find_by_master_ids              RGE_Static_Object * find_by_master_ids(RGE_Ob
    //         004033ef     PUSH       EAX
    //         004033f0     MOV        this,ESI
    //         004033f2     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:308 (2)
    //         004033f5     JMP        LAB_00403400
    //                               LAB_004033f7                                                 XREF[1]:     00403380(j)  
    //                              ACT_GATH.cpp:313 (9)
    //         004033f7     MOV        EAX,dword ptr [ESI]
    //         004033f9     PUSH       0x0
    //         004033fb     MOV        this,ESI
    //         004033fd     CALL       dword ptr [EAX + 0x58]
    //                               LAB_00403400                                                 XREF[2]:     004033c4(j), 004033f5(j)  
    //                              ACT_GATH.cpp:317 (11)
    //         00403400     MOV        EAX,dword ptr [ESI + 0x14]
    //         00403403     TEST       EAX,EAX
    //         00403405     JZ         LAB_00403498
    //                               LAB_0040340b                                                 XREF[1]:     0040336f(j)  
    //                              ACT_GATH.cpp:325 (64)
    //         0040340b     PUSH       0x44
    //         0040340d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00403412     MOV        EDI,EAX
    //         00403414     ADD        ESP,0x4
    //         00403417     MOV        dword ptr [ESP + 0x18],EDI
    //         0040341b     TEST       EDI,EDI
    //         0040341d     MOV        dword ptr [ESP + 0x10],0x2
    //         00403425     JZ         LAB_00403449
    //         00403427     MOV        this,ESI
    //         00403429     CALL       RGE_Action_Gather::get_move_sprite               RGE_Sprite * get_move_sprite(RGE_Action_Gathe
    //         0040342e     MOV        this,dword ptr [ESI + 0x30]
    //         00403431     PUSH       EAX
    //         00403432     MOV        EAX,dword ptr [ESI + 0x14]
    //         00403435     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00403438     MOV        this,dword ptr [ESI + 0x8]
    //         0040343b     PUSH       EDX=>DAT_fffffff8
    //         0040343c     PUSH       EAX=>DAT_fffffff4
    //         0040343d     PUSH       this=>DAT_fffffff0
    //         0040343e     MOV        this,EDI
    //         00403440     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         00403445     MOV        EDI,EAX
    //         00403447     JMP        LAB_0040344b
    //                               LAB_00403449                                                 XREF[2]:     004032b7(j), 00403425(j)  
    //         00403449     XOR        EDI,EDI
    //                               LAB_0040344b                                                 XREF[2]:     004032dd(j), 00403447(j)  
    //                              ACT_GATH.cpp:326 (12)
    //         0040344b     TEST       EDI,EDI
    //         0040344d     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00403455     JNZ        LAB_00403473
    //                              ACT_GATH.cpp:328 (9)
    //         00403457     MOV        EDX,dword ptr [ESI]
    //         00403459     PUSH       0xd
    //         0040345b     MOV        this,ESI
    //         0040345d     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:377 (19)
    //         00403460     MOV        this,dword ptr [ESP + 0x8]
    //         00403464     MOV        dword ptr FS:[0x0],this
    //         0040346b     POP        EDI
    //         0040346c     POP        ESI
    //         0040346d     ADD        ESP,0xc
    //         00403470     RET        0x4
    //                               LAB_00403473                                                 XREF[1]:     00403455(j)  
    //                              ACT_GATH.cpp:331 (9)
    //         00403473     MOV        this,dword ptr [ESI + 0x34]
    //         00403476     PUSH       EDI
    //         00403477     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                              ACT_GATH.cpp:332 (9)
    //         0040347c     PUSH       0x1
    //         0040347e     MOV        this,EDI
    //         00403480     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
    //                              ACT_GATH.cpp:377 (19)
    //         00403485     MOV        this,dword ptr [ESP + 0x8]
    //         00403489     MOV        dword ptr FS:[0x0],this
    //         00403490     POP        EDI
    //         00403491     POP        ESI
    //         00403492     ADD        ESP,0xc
    //         00403495     RET        0x4
    //                               LAB_00403498                                                 XREF[1]:     00403405(j)  
    //                              ACT_GATH.cpp:340 (30)
    //         00403498     MOV        this,dword ptr [ESI + 0x8]
    //         0040349b     PUSH       0x0
    //         0040349d     PUSH       0x0=>DAT_fffffff8
    //         0040349f     PUSH       offset DAT_fffffff4
    //         004034a4     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004034a7     MOV        EDX,dword ptr [this->_padding_]
    //         004034a9     PUSH       offset DAT_fffffff0
    //         004034ae     PUSH       EAX
    //         004034af     PUSH       EAX
    //         004034b0     CALL       dword ptr [EDX + 0x148]
    //                              ACT_GATH.cpp:341 (9)
    //         004034b6     MOV        EAX,dword ptr [ESI]
    //         004034b8     PUSH       0xd
    //         004034ba     MOV        this,ESI
    //         004034bc     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:377 (19)
    //         004034bf     MOV        this,dword ptr [ESP + 0x8]
    //         004034c3     MOV        dword ptr FS:[0x0],this
    //         004034ca     POP        EDI
    //         004034cb     POP        ESI
    //         004034cc     ADD        ESP,0xc
    //         004034cf     RET        0x4
    //                               LAB_004034d2                                                 XREF[1]:     00403364(j)  
    //                              ACT_GATH.cpp:352 (43)
    //         004034d2     MOV        EDX,dword ptr [ESI + 0x10]
    //         004034d5     TEST       EDX,EDX
    //         004034d7     JZ         LAB_00403506
    //         004034d9     FLD        float ptr [EDX + 0x44]
    //         004034dc     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         004034e2     FNSTSW     AX
    //         004034e4     TEST       AH,0x41
    //         004034e7     JZ         LAB_00403506
    //         004034e9     MOV        EDX,dword ptr [EDX + 0x8]
    //         004034ec     MOV        EAX,dword ptr [this->_padding_]
    //         004034ee     MOVSX      EDX,word ptr [EDX + 0x10]
    //         004034f2     PUSH       EDX
    //         004034f3     CALL       dword ptr [EAX + 0x138]
    //         004034f9     TEST       AL,AL
    //         004034fb     JNZ        LAB_00403506
    //                              ACT_GATH.cpp:357 (9)
    //         004034fd     MOV        EAX,dword ptr [ESI]
    //         004034ff     PUSH       0x0
    //         00403501     MOV        this,ESI
    //         00403503     CALL       dword ptr [EAX + 0x54]
    //                               LAB_00403506                                                 XREF[3]:     004034d7(j), 004034e7(j), 
    //                                                                                                         004034fb(j)  
    //                              ACT_GATH.cpp:362 (9)
    //         00403506     MOV        EDX,dword ptr [ESI]
    //         00403508     PUSH       0x3
    //         0040350a     MOV        this,ESI
    //         0040350c     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:377 (19)
    //         0040350f     MOV        this,dword ptr [ESP + 0x8]
    //         00403513     MOV        dword ptr FS:[0x0],this
    //         0040351a     POP        EDI
    //         0040351b     POP        ESI
    //         0040351c     ADD        ESP,0xc
    //         0040351f     RET        0x4
    //                               switchD_00403147::caseD_c                                    XREF[4]:     00403147(j), 00403550(*), 
    //                               switchD_00403147::caseD_d                                                 00403580(*), 00403584(*)  
    //                               switchD_00403147::caseD_0
    //                              ACT_GATH.cpp:373 (7)
    //         00403522     MOV        dword ptr [ESI + 0x2c],0x0
    //                               LAB_00403529                                                 XREF[1]:     00403175(j)  
    //                              ACT_GATH.cpp:374 (19)
    //         00403529     MOV        EAX,dword ptr [ESI + 0x8]
    //         0040352c     MOV        this,ESI
    //         0040352e     MOV        EDI,dword ptr [EAX]
    //         00403530     CALL       RGE_Action_Gather::get_wait_sprite               RGE_Sprite * get_wait_sprite(RGE_Action_Gathe
    //                               LAB_00403535                                                 XREF[1]:     004032f5(j)  
    //         00403535     MOV        this,dword ptr [ESI + 0x8]
    //         00403538     PUSH       EAX
    //         00403539     CALL       dword ptr [EDI + 0x38]
    //                               switchD_00403147::caseD_8                                    XREF[7]:     00403141(j), 00403147(j), 
    //                               switchD_00403147::caseD_9                                                 00403333(j), 00403560(*), 
    //                               switchD_00403147::caseD_b                                                 00403570(*), 00403574(*), 
    //                               switchD_00403147::caseD_4                                                 0040357c(*)  
    //                              ACT_GATH.cpp:377 (80)
    //         0040353c     MOV        this,dword ptr [ESP + local_c]
    //         00403540     POP        EDI
    //         00403541     MOV        dword ptr FS:[0x0],this
    //         00403548     POP        ESI
    //         00403549     ADD        ESP,0xc
    //         0040354c     RET        0x4
}

// Offset: 0x00403590
uchar RGE_Action_Gather::update() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Action_Gather::update(void)                              *
    //                              *********************************************************************************************************
    //                              uchar __thiscall update(RGE_Action_Gather * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              float             Stack[-0x8]:2  max_hold
    //              float             Stack[-0xc]:4  modifier
    //              float             Stack[-0x10]:4 give_amount
    //                               ?update@RGE_Action_Gather@@UAEEXZ                            XREF[1]:     0056e240(*)  
    //                               RGE_Action_Gather::update
    //                              ACT_GATH.cpp:383 (9)
    //         00403590     SUB        ESP,0xc
    //         00403593     PUSH       EBX
    //         00403594     PUSH       EBP
    //         00403595     PUSH       ESI
    //         00403596     MOV        ESI,this
    //         00403598     PUSH       EDI
    //                              ACT_GATH.cpp:416 (27)
    //         00403599     MOV        EAX,dword ptr [ESI + 0x18]
    //         0040359c     CMP        EAX,-0x1
    //         0040359f     JZ         LAB_004035bc
    //         004035a1     PUSH       EAX
    //         004035a2     MOV        EAX,dword ptr [ESI + 0x8]
    //         004035a5     MOV        this,dword ptr [EAX + 0xc]
    //         004035a8     MOV        this,dword ptr [ECX + this->_padding_]
    //         004035ab     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004035b0     TEST       EAX,EAX
    //         004035b2     JNZ        LAB_004035bc
    //                              ACT_GATH.cpp:417 (8)
    //         004035b4     MOV        EDX,dword ptr [ESI]
    //         004035b6     PUSH       EAX
    //         004035b7     MOV        this,ESI
    //         004035b9     CALL       dword ptr [EDX + 0x54]
    //                               LAB_004035bc                                                 XREF[2]:     0040359f(j), 004035b2(j)  
    //                              ACT_GATH.cpp:418 (27)
    //         004035bc     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004035bf     CMP        EAX,-0x1
    //         004035c2     JZ         LAB_004035df
    //         004035c4     PUSH       EAX
    //         004035c5     MOV        EAX,dword ptr [ESI + 0x8]
    //         004035c8     MOV        this,dword ptr [EAX + 0xc]
    //         004035cb     MOV        this,dword ptr [ECX + this->_padding_]
    //         004035ce     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004035d3     TEST       EAX,EAX
    //         004035d5     JNZ        LAB_004035df
    //                              ACT_GATH.cpp:419 (8)
    //         004035d7     MOV        EDX,dword ptr [ESI]
    //         004035d9     PUSH       EAX
    //         004035da     MOV        this,ESI
    //         004035dc     CALL       dword ptr [EDX + 0x58]
    //                               LAB_004035df                                                 XREF[2]:     004035c2(j), 004035d5(j)  
    //                              ACT_GATH.cpp:421 (17)
    //         004035df     MOV        EAX,dword ptr [ESI + 0x10]
    //         004035e2     MOV        EBX,0x7
    //         004035e7     TEST       EAX,EAX
    //         004035e9     JZ         LAB_004035f9
    //         004035eb     CMP        byte ptr [EAX + 0x48],BL
    //         004035ee     JC         LAB_004035f9
    //                              ACT_GATH.cpp:422 (9)
    //         004035f0     MOV        EAX,dword ptr [ESI]
    //         004035f2     PUSH       0x0
    //         004035f4     MOV        this,ESI
    //         004035f6     CALL       dword ptr [EAX + 0x54]
    //                               LAB_004035f9                                                 XREF[2]:     004035e9(j), 004035ee(j)  
    //                              ACT_GATH.cpp:424 (12)
    //         004035f9     MOV        EAX,dword ptr [ESI + 0x14]
    //         004035fc     TEST       EAX,EAX
    //         004035fe     JZ         LAB_0040360e
    //         00403600     CMP        byte ptr [EAX + 0x48],BL
    //         00403603     JC         LAB_0040360e
    //                              ACT_GATH.cpp:425 (9)
    //         00403605     MOV        EDX,dword ptr [ESI]
    //         00403607     PUSH       0x0
    //         00403609     MOV        this,ESI
    //         0040360b     CALL       dword ptr [EDX + 0x58]
    //                               LAB_0040360e                                                 XREF[2]:     004035fe(j), 00403603(j)  
    //                              ACT_GATH.cpp:430 (31)
    //         0040360e     MOV        this,dword ptr [ESI + 0x10]
    //         00403611     TEST       this,this
    //         00403613     JZ         LAB_00403660
    //         00403615     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00403618     MOV        AX,word ptr [EAX + 0x4a]
    //         0040361c     TEST       AX,AX
    //         0040361f     JZ         LAB_00403660
    //         00403621     MOV        EDX,dword ptr [ESI + 0x8]
    //         00403624     MOV        EDX,dword ptr [EDX + 0xc]
    //         00403627     CMP        AX,word ptr [EDX + 0x4a]
    //         0040362b     JZ         LAB_00403660
    //                              ACT_GATH.cpp:432 (9)
    //         0040362d     MOV        EAX,dword ptr [ESI]
    //         0040362f     PUSH       0x1
    //         00403631     MOV        this,ESI
    //         00403633     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:433 (32)
    //         00403636     MOV        ESI,dword ptr [ESI + 0x8]
    //         00403639     PUSH       0x0
    //         0040363b     PUSH       0x0
    //         0040363d     PUSH       0x261
    //         00403642     MOV        EAX,dword ptr [ESI + 0x4]
    //         00403645     MOV        EDX,dword ptr [ESI]
    //         00403647     PUSH       0x1fb
    //         0040364c     PUSH       EAX
    //         0040364d     PUSH       EAX
    //         0040364e     MOV        this,ESI
    //         00403650     CALL       dword ptr [EDX + 0x148]
    //                              ACT_GATH.cpp:434 (2)
    //         00403656     MOV        AL,0x4
    //                              ACT_GATH.cpp:752 (8)
    //         00403658     POP        EDI
    //         00403659     POP        ESI
    //         0040365a     POP        EBP
    //         0040365b     POP        EBX
    //         0040365c     ADD        ESP,0xc
    //         0040365f     RET
    //                               LAB_00403660                                                 XREF[3]:     00403613(j), 0040361f(j), 
    //                                                                                                         0040362b(j)  
    //                              ACT_GATH.cpp:437 (22)
    //         00403660     XOR        EAX,EAX
    //         00403662     MOV        AL,byte ptr [ESI + 0xc]
    //         00403665     DEC        EAX
    //         00403666     CMP        EAX,0xe
    //         00403669     JA         switchD_0040366f::caseD_1
    //                               switchD_0040366f::switchD
    //         0040366f     JMP        dword ptr [EAX*0x4 + switchD_0040366f::switchd   = 00403b7d
    //                               switchD_0040366f::caseD_2                                    XREF[2]:     0040366f(j), 00403bec(*)  
    //                              ACT_GATH.cpp:442 (20)
    //         00403676     FLD        float ptr [ESI + 0x2c]
    //         00403679     FCOMP      double ptr [null_0056e280]                       = align(10)
    //         0040367f     FNSTSW     AX
    //         00403681     TEST       AH,0x1
    //         00403684     JZ         switchD_0040366f::caseD_1
    //                              ACT_GATH.cpp:444 (18)
    //         0040368a     MOV        this,dword ptr [ESI + 0x8]
    //         0040368d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00403690     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00403693     FLD        float ptr [EDX + 0x84]
    //         00403699     FADD       float ptr [ESI + 0x2c]
    //                              ACT_GATH.cpp:445 (20)
    //         0040369c     FCOM       double ptr [null_0056e280]                       = align(10)
    //         004036a2     FSTP       float ptr [ESI + 0x2c]
    //         004036a5     FNSTSW     AX
    //         004036a7     TEST       AH,0x41
    //         004036aa     JNZ        switchD_0040366f::caseD_1
    //                              ACT_GATH.cpp:448 (36)
    //         004036b0     MOV        EDX,dword ptr [this->_padding_]
    //         004036b2     MOV        dword ptr [ESI + 0x2c],0xc1200000
    //         004036b9     MOV        ESI,dword ptr [ESI + 0x40]
    //         004036bc     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004036bf     PUSH       0x0
    //         004036c1     PUSH       ESI
    //         004036c2     PUSH       0x261
    //         004036c7     PUSH       0x202
    //         004036cc     PUSH       EAX
    //         004036cd     PUSH       EAX
    //         004036ce     CALL       dword ptr [EDX + 0x148]
    //                              ACT_GATH.cpp:751 (2)
    //         004036d4     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         004036d6     POP        EDI
    //         004036d7     POP        ESI
    //         004036d8     POP        EBP
    //         004036d9     POP        EBX
    //         004036da     ADD        ESP,0xc
    //         004036dd     RET
    //                               switchD_0040366f::caseD_e                                    XREF[3]:     0040366f(j), 00403c0c(*), 
    //                               switchD_0040366f::caseD_a                                                 00403c1c(*)  
    //                              ACT_GATH.cpp:459 (30)
    //         004036de     MOV        this,dword ptr [ESI + 0x34]
    //         004036e1     MOV        EAX,dword ptr [this->_padding_]
    //         004036e3     CALL       dword ptr [EAX + 0xc]
    //         004036e6     AND        EAX,0xff
    //         004036eb     DEC        EAX
    //         004036ec     CMP        EAX,0x4
    //         004036ef     JA         switchD_0040366f::caseD_1
    //                               switchD_004036f5::switchD
    //         004036f5     JMP        dword ptr [EAX*0x4 + switchD_004036f5::switchd   = 00403735
    //                               switchD_004036f5::caseD_3                                    XREF[2]:     004036f5(j), 00403c2c(*)  
    //                              ACT_GATH.cpp:467 (9)
    //         004036fc     MOV        EDI,dword ptr [ESI]
    //         004036fe     PUSH       0x0
    //         00403700     MOV        this,ESI
    //         00403702     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:468 (6)
    //         00403705     CMP        byte ptr [ESI + 0xc],0xb
    //         00403709     JNZ        LAB_0040371c
    //                              ACT_GATH.cpp:469 (7)
    //         0040370b     PUSH       0xb
    //         0040370d     MOV        this,ESI
    //         0040370f     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403712     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403714     POP        EDI
    //         00403715     POP        ESI
    //         00403716     POP        EBP
    //         00403717     POP        EBX
    //         00403718     ADD        ESP,0xc
    //         0040371b     RET
    //                               LAB_0040371c                                                 XREF[1]:     00403709(j)  
    //                              ACT_GATH.cpp:471 (7)
    //         0040371c     PUSH       0xf
    //         0040371e     MOV        this,ESI
    //         00403720     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403723     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403725     POP        EDI
    //         00403726     POP        ESI
    //         00403727     POP        EBP
    //         00403728     POP        EBX
    //         00403729     ADD        ESP,0xc
    //         0040372c     RET
    //                               switchD_004036f5::caseD_2                                    XREF[2]:     004036f5(j), 00403c28(*)  
    //                              ACT_GATH.cpp:479 (6)
    //         0040372d     MOV        this,dword ptr [ESI + 0x8]
    //         00403730     MOV        this,dword ptr [ECX + this->_padding_]
    //                              ACT_GATH.cpp:483 (2)
    //         00403733     JMP        LAB_00403790
    //                               switchD_004036f5::caseD_1                                    XREF[4]:     004036f5(j), 00403c20(*), 
    //                               switchD_004036f5::caseD_4                                                 00403c24(*), 00403c30(*)  
    //                               switchD_004036f5::caseD_0
    //                              ACT_GATH.cpp:491 (10)
    //         00403735     CMP        byte ptr [ESI + 0xc],0xb
    //         00403739     JNZ        LAB_00403b35
    //                              ACT_GATH.cpp:492 (4)
    //         0040373f     MOV        EDX,dword ptr [ESI]
    //         00403741     PUSH       0x3
    //                              ACT_GATH.cpp:718 (5)
    //         00403743     MOV        this,ESI
    //         00403745     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403748     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         0040374a     POP        EDI
    //         0040374b     POP        ESI
    //         0040374c     POP        EBP
    //         0040374d     POP        EBX
    //         0040374e     ADD        ESP,0xc
    //         00403751     RET
    //                               switchD_0040366f::caseD_3                                    XREF[2]:     0040366f(j), 00403bf0(*)  
    //                              ACT_GATH.cpp:506 (30)
    //         00403752     MOV        this,dword ptr [ESI + 0x34]
    //         00403755     MOV        EDX,dword ptr [this->_padding_]
    //         00403757     CALL       dword ptr [EDX + 0xc]
    //         0040375a     AND        EAX,0xff
    //         0040375f     DEC        EAX
    //         00403760     CMP        EAX,0x4
    //         00403763     JA         switchD_0040366f::caseD_1
    //                               switchD_00403769::switchD
    //         00403769     JMP        dword ptr [EAX*0x4 + switchD_00403769::switchd   = 004037b1
    //                               switchD_00403769::caseD_4                                    XREF[3]:     00403769(j), 00403c40(*), 
    //                               switchD_00403769::caseD_3                                                 00403c44(*)  
    //                              ACT_GATH.cpp:515 (9)
    //         00403770     MOV        EDI,dword ptr [ESI]
    //         00403772     PUSH       0x0
    //         00403774     MOV        this,ESI
    //         00403776     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:516 (7)
    //         00403779     PUSH       0xb
    //         0040377b     MOV        this,ESI
    //         0040377d     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403780     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403782     POP        EDI
    //         00403783     POP        ESI
    //         00403784     POP        EBP
    //         00403785     POP        EBX
    //         00403786     ADD        ESP,0xc
    //         00403789     RET
    //                               switchD_00403769::caseD_2                                    XREF[2]:     00403769(j), 00403c3c(*)  
    //                              ACT_GATH.cpp:524 (20)
    //         0040378a     MOV        EAX,dword ptr [ESI + 0x8]
    //         0040378d     MOV        this,dword ptr [EAX + 0xc]
    //                               LAB_00403790                                                 XREF[1]:     00403733(j)  
    //         00403790     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00403795     CMP        EAX,0x1
    //         00403798     JNZ        LAB_00403875
    //                              ACT_GATH.cpp:525 (4)
    //         0040379e     MOV        EDX,dword ptr [ESI]
    //         004037a0     PUSH       0xd
    //                              ACT_GATH.cpp:718 (5)
    //         004037a2     MOV        this,ESI
    //         004037a4     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         004037a7     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         004037a9     POP        EDI
    //         004037aa     POP        ESI
    //         004037ab     POP        EBP
    //         004037ac     POP        EBX
    //         004037ad     ADD        ESP,0xc
    //         004037b0     RET
    //                               switchD_00403769::caseD_1                                    XREF[3]:     00403769(j), 00403c34(*), 
    //                               switchD_00403769::caseD_0                                                 00403c38(*)  
    //                              ACT_GATH.cpp:532 (9)
    //         004037b1     MOV        EDX,dword ptr [ESI]
    //         004037b3     PUSH       0x6
    //         004037b5     MOV        this,ESI
    //         004037b7     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         004037ba     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         004037bc     POP        EDI
    //         004037bd     POP        ESI
    //         004037be     POP        EBP
    //         004037bf     POP        EBX
    //         004037c0     ADD        ESP,0xc
    //         004037c3     RET
    //                               switchD_0040366f::caseD_5                                    XREF[2]:     0040366f(j), 00403bf8(*)  
    //                              ACT_GATH.cpp:540 (4)
    //         004037c4     TEST       this,this
    //         004037c6     JNZ        LAB_004037db
    //                              ACT_GATH.cpp:542 (9)
    //         004037c8     MOV        EAX,dword ptr [ESI]
    //         004037ca     PUSH       0x3
    //         004037cc     MOV        this,ESI
    //         004037ce     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         004037d1     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         004037d3     POP        EDI
    //         004037d4     POP        ESI
    //         004037d5     POP        EBP
    //         004037d6     POP        EBX
    //         004037d7     ADD        ESP,0xc
    //         004037da     RET
    //                               LAB_004037db                                                 XREF[1]:     004037c6(j)  
    //                              ACT_GATH.cpp:547 (26)
    //         004037db     MOV        EAX,dword ptr [ESI + 0x8]
    //         004037de     PUSH       0x0
    //         004037e0     PUSH       0x0
    //         004037e2     PUSH       this
    //         004037e3     MOV        EDX,dword ptr [EAX]
    //         004037e5     MOV        this,EAX
    //         004037e7     CALL       dword ptr [EDX + 0x1f0]
    //         004037ed     TEST       AL,AL
    //         004037ef     JZ         switchD_0040366f::caseD_1
    //                              ACT_GATH.cpp:552 (42)
    //         004037f5     MOV        EDX,dword ptr [ESI + 0x10]
    //         004037f8     FLD        float ptr [EDX + 0x44]
    //         004037fb     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         00403801     FNSTSW     AX
    //         00403803     TEST       AH,0x41
    //         00403806     JZ         LAB_00403839
    //         00403808     MOV        EDX,dword ptr [EDX + 0x8]
    //         0040380b     MOV        this,dword ptr [ESI + 0x8]
    //         0040380e     MOVSX      EDX,word ptr [EDX + 0x10]
    //         00403812     MOV        EAX,dword ptr [this->_padding_]
    //         00403814     PUSH       EDX
    //         00403815     CALL       dword ptr [EAX + 0x138]
    //         0040381b     TEST       AL,AL
    //         0040381d     JNZ        LAB_00403839
    //                              ACT_GATH.cpp:554 (9)
    //         0040381f     MOV        EDI,dword ptr [ESI]
    //         00403821     PUSH       0x0
    //         00403823     MOV        this,ESI
    //         00403825     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:555 (7)
    //         00403828     PUSH       0x3
    //         0040382a     MOV        this,ESI
    //         0040382c     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         0040382f     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403831     POP        EDI
    //         00403832     POP        ESI
    //         00403833     POP        EBP
    //         00403834     POP        EBX
    //         00403835     ADD        ESP,0xc
    //         00403838     RET
    //                               LAB_00403839                                                 XREF[2]:     00403806(j), 0040381d(j)  
    //                              ACT_GATH.cpp:558 (8)
    //         00403839     MOV        EAX,dword ptr [ESI]
    //         0040383b     PUSH       EBX
    //         0040383c     MOV        this,ESI
    //         0040383e     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403841     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403843     POP        EDI
    //         00403844     POP        ESI
    //         00403845     POP        EBP
    //         00403846     POP        EBX
    //         00403847     ADD        ESP,0xc
    //         0040384a     RET
    //                               switchD_0040366f::caseD_6                                    XREF[2]:     0040366f(j), 00403bfc(*)  
    //                              ACT_GATH.cpp:566 (4)
    //         0040384b     TEST       this,this
    //         0040384d     JNZ        LAB_00403888
    //                              ACT_GATH.cpp:568 (19)
    //         0040384f     MOV        this,dword ptr [ESI + 0x8]
    //         00403852     FLD        float ptr [ECX + this+0x44]
    //         00403855     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         0040385b     FNSTSW     AX
    //         0040385d     TEST       AH,0x41
    //         00403860     JNZ        LAB_00403875
    //                              ACT_GATH.cpp:569 (9)
    //         00403862     MOV        EDX,dword ptr [ESI]
    //         00403864     PUSH       0x8
    //         00403866     MOV        this,ESI
    //         00403868     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         0040386b     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         0040386d     POP        EDI
    //         0040386e     POP        ESI
    //         0040386f     POP        EBP
    //         00403870     POP        EBX
    //         00403871     ADD        ESP,0xc
    //         00403874     RET
    //                               LAB_00403875                                                 XREF[2]:     00403798(j), 00403860(j)  
    //                              ACT_GATH.cpp:571 (9)
    //         00403875     MOV        EAX,dword ptr [ESI]
    //         00403877     PUSH       0x3
    //         00403879     MOV        this,ESI
    //         0040387b     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         0040387e     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403880     POP        EDI
    //         00403881     POP        ESI
    //         00403882     POP        EBP
    //         00403883     POP        EBX
    //         00403884     ADD        ESP,0xc
    //         00403887     RET
    //                               LAB_00403888                                                 XREF[1]:     0040384d(j)  
    //                              ACT_GATH.cpp:579 (16)
    //         00403888     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0040388e     MOV        EAX,dword ptr [EDX + 0x9a8]
    //         00403894     TEST       EAX,EAX
    //         00403896     JZ         LAB_0040389d
    //                              ACT_GATH.cpp:580 (3)
    //         00403898     FLD        float ptr [ECX + this+0x44]
    //                              ACT_GATH.cpp:581 (2)
    //         0040389b     JMP        LAB_004038bb
    //                               LAB_0040389d                                                 XREF[1]:     00403896(j)  
    //                              ACT_GATH.cpp:583 (30)
    //         0040389d     MOV        EAX,dword ptr [ESI + 0x8]
    //         004038a0     MOV        EDX,dword ptr [ESI + 0x30]
    //         004038a3     MOV        EDI,dword ptr [EAX + 0x8]
    //         004038a6     MOV        EAX,dword ptr [EAX + 0xc]
    //         004038a9     FLD        float ptr [EDX + 0x1c]
    //         004038ac     FMUL       float ptr [EDI + 0xe4]
    //         004038b2     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004038b5     FMUL       float ptr [EDX + 0x84]
    //                               LAB_004038bb                                                 XREF[1]:     0040389b(j)  
    //                              ACT_GATH.cpp:584 (12)
    //         004038bb     FCOM       float ptr [ECX + this+0x44]
    //         004038be     FNSTSW     AX
    //         004038c0     TEST       AH,0x41
    //         004038c3     JNZ        LAB_004038ca
    //         004038c5     FSTP       ST0
    //                              ACT_GATH.cpp:585 (3)
    //         004038c7     FLD        float ptr [ECX + this+0x44]
    //                               LAB_004038ca                                                 XREF[1]:     004038c3(j)  
    //                              ACT_GATH.cpp:587 (13)
    //         004038ca     MOV        EAX,dword ptr [ESI + 0x30]
    //         004038cd     MOV        AX,word ptr [EAX + 0x16]
    //         004038d1     CMP        AX,0xffff
    //         004038d5     JZ         LAB_004038ec
    //                              ACT_GATH.cpp:588 (19)
    //         004038d7     MOV        EDX,dword ptr [ESI + 0x8]
    //         004038da     MOVSX      EAX,AX
    //         004038dd     MOV        EDX,dword ptr [EDX + 0xc]
    //         004038e0     MOV        EDX,dword ptr [EDX + 0x50]
    //         004038e3     FLD        float ptr [EDX + EAX*0x4]
    //         004038e6     FSTP       float ptr [ESP + 0x14]
    //                              ACT_GATH.cpp:589 (2)
    //         004038ea     JMP        LAB_004038f4
    //                               LAB_004038ec                                                 XREF[1]:     004038d5(j)  
    //                              ACT_GATH.cpp:590 (8)
    //         004038ec     MOV        dword ptr [ESP + 0x14],0x3f800000
    //                               LAB_004038f4                                                 XREF[1]:     004038ea(j)  
    //                              ACT_GATH.cpp:591 (3)
    //         004038f4     MOV        EAX,dword ptr [ESI + 0x8]
    //                              ACT_GATH.cpp:592 (29)
    //         004038f7     FLD        float ptr [ESP + 0x14]
    //         004038fb     MOV        EDX,dword ptr [EAX + 0x8]
    //         004038fe     FMUL       ST1
    //         00403900     MOVSX      EDX,word ptr [EDX + 0x7c]
    //         00403904     MOV        dword ptr [ESP + 0x18],EDX
    //         00403908     FILD       dword ptr [ESP + 0x18]
    //         0040390c     FXCH
    //         0040390e     FST        float ptr [ESP + 0x10]
    //         00403912     FXCH
    //                              ACT_GATH.cpp:593 (22)
    //         00403914     FMUL       float ptr [ESP + 0x14]
    //         00403918     FST        float ptr [ESP + 0x18]
    //         0040391c     FSUB       float ptr [EAX + 0x44]
    //         0040391f     FXCH
    //         00403921     FCOMP
    //         00403923     FNSTSW     AX
    //         00403925     TEST       AH,0x41
    //         00403928     JNZ        LAB_00403944
    //                              ACT_GATH.cpp:595 (4)
    //         0040392a     FSUBR      float ptr [ESP + 0x10]
    //                              ACT_GATH.cpp:596 (4)
    //         0040392e     FLD        float ptr [ESP + 0x10]
    //                              ACT_GATH.cpp:597 (18)
    //         00403932     FLD        ST1
    //         00403934     FDIV       float ptr [ESP + 0x14]
    //         00403938     FXCH
    //         0040393a     FSUB       ST0,ST2
    //         0040393c     FXCH
    //         0040393e     FSUBP      ST3,ST0
    //         00403940     FSTP       float ptr [ESP + 0x10]
    //                               LAB_00403944                                                 XREF[1]:     00403928(j)  
    //                              ACT_GATH.cpp:600 (20)
    //         00403944     MOV        EAX,dword ptr [this->_padding_]
    //         00403946     PUSH       0x1
    //         00403948     FSTP       ST0
    //         0040394a     PUSH       0x1
    //         0040394c     PUSH       this
    //         0040394d     FCHS
    //         0040394f     FSTP       float ptr [ESP]
    //         00403952     CALL       dword ptr [EAX + 0x84]
    //                              ACT_GATH.cpp:601 (20)
    //         00403958     MOV        this,dword ptr [ESI + 0x8]
    //         0040395b     MOV        EAX,dword ptr [ESP + 0x10]
    //         0040395f     PUSH       0x0
    //         00403961     PUSH       0x1
    //         00403963     MOV        EDX,dword ptr [this->_padding_]
    //         00403965     PUSH       EAX
    //         00403966     CALL       dword ptr [EDX + 0x84]
    //                              ACT_GATH.cpp:606 (58)
    //         0040396c     MOV        this,dword ptr [ESI + 0x8]
    //         0040396f     FLD        float ptr [ECX + this+0x44]
    //         00403972     FCOMP      float ptr [ESP + 0x18]
    //         00403976     FNSTSW     AX
    //         00403978     TEST       AH,0x1
    //         0040397b     JZ         LAB_004039ac
    //         0040397d     MOV        EDX,dword ptr [ESI + 0x10]
    //         00403980     FLD        float ptr [EDX + 0x44]
    //         00403983     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         00403989     FNSTSW     AX
    //         0040398b     TEST       AH,0x41
    //         0040398e     JZ         switchD_0040366f::caseD_1
    //         00403994     MOV        EDX,dword ptr [EDX + 0x8]
    //         00403997     MOV        EAX,dword ptr [this->_padding_]
    //         00403999     MOVSX      EDX,word ptr [EDX + 0x10]
    //         0040399d     PUSH       EDX
    //         0040399e     CALL       dword ptr [EAX + 0x138]
    //         004039a4     TEST       AL,AL
    //                              ACT_GATH.cpp:611 (6)
    //         004039a6     JNZ        switchD_0040366f::caseD_1
    //                               LAB_004039ac                                                 XREF[1]:     0040397b(j)  
    //                              ACT_GATH.cpp:608 (9)
    //         004039ac     MOV        EAX,dword ptr [ESI]
    //         004039ae     PUSH       0x8
    //         004039b0     MOV        this,ESI
    //         004039b2     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         004039b5     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         004039b7     POP        EDI
    //         004039b8     POP        ESI
    //         004039b9     POP        EBP
    //         004039ba     POP        EBX
    //         004039bb     ADD        ESP,0xc
    //         004039be     RET
    //                               switchD_0040366f::caseD_7                                    XREF[2]:     0040366f(j), 00403c00(*)  
    //                              ACT_GATH.cpp:619 (16)
    //         004039bf     FLD        float ptr [ESI + 0x2c]
    //         004039c2     FCOMP      double ptr [null_0056e280]                       = align(10)
    //         004039c8     FNSTSW     AX
    //         004039ca     TEST       AH,0x1
    //         004039cd     JZ         LAB_00403a0f
    //                              ACT_GATH.cpp:625 (18)
    //         004039cf     MOV        this,dword ptr [ESI + 0x8]
    //         004039d2     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004039d5     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004039d8     FLD        float ptr [EAX + 0x84]
    //         004039de     FADD       float ptr [ESI + 0x2c]
    //                              ACT_GATH.cpp:626 (20)
    //         004039e1     FCOM       double ptr [null_0056e280]                       = align(10)
    //         004039e7     FSTP       float ptr [ESI + 0x2c]
    //         004039ea     FNSTSW     AX
    //         004039ec     TEST       AH,0x41
    //         004039ef     JNZ        switchD_0040366f::caseD_1
    //                              ACT_GATH.cpp:632 (16)
    //         004039f5     MOV        EDX,dword ptr [ESI]
    //         004039f7     PUSH       0x8
    //         004039f9     MOV        this,ESI
    //         004039fb     MOV        dword ptr [ESI + 0x2c],0x0
    //         00403a02     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403a05     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403a07     POP        EDI
    //         00403a08     POP        ESI
    //         00403a09     POP        EBP
    //         00403a0a     POP        EBX
    //         00403a0b     ADD        ESP,0xc
    //         00403a0e     RET
    //                               LAB_00403a0f                                                 XREF[1]:     004039cd(j)  
    //                              ACT_GATH.cpp:638 (30)
    //         00403a0f     MOV        this,dword ptr [ESI + 0x34]
    //         00403a12     MOV        EAX,dword ptr [this->_padding_]
    //         00403a14     CALL       dword ptr [EAX + 0xc]
    //         00403a17     AND        EAX,0xff
    //         00403a1c     DEC        EAX
    //         00403a1d     CMP        EAX,0x4
    //         00403a20     JA         switchD_0040366f::caseD_1
    //                               switchD_00403a26::switchD
    //         00403a26     JMP        dword ptr [EAX*0x4 + switchD_00403a26::switchd   = 00403a49
    //                               switchD_00403a26::caseD_3                                    XREF[4]:     00403a26(j), 00403c50(*), 
    //                               switchD_00403a26::caseD_4                                                 00403c54(*), 00403c58(*)  
    //                               switchD_00403a26::caseD_2
    //                              ACT_GATH.cpp:648 (18)
    //         00403a2d     MOV        this,dword ptr [ESI + 0x8]
    //         00403a30     MOV        dword ptr [ESI + 0x2c],0xc0400000
    //         00403a37     MOV        EDX,dword ptr [this->_padding_]
    //         00403a39     CALL       dword ptr [EDX + 0x1ec]
    //                              ACT_GATH.cpp:751 (2)
    //         00403a3f     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403a41     POP        EDI
    //         00403a42     POP        ESI
    //         00403a43     POP        EBP
    //         00403a44     POP        EBX
    //         00403a45     ADD        ESP,0xc
    //         00403a48     RET
    //                               switchD_00403a26::caseD_1                                    XREF[3]:     00403a26(j), 00403c48(*), 
    //                               switchD_00403a26::caseD_0                                                 00403c4c(*)  
    //                              ACT_GATH.cpp:655 (11)
    //         00403a49     MOV        EAX,dword ptr [ESI + 0x14]
    //         00403a4c     TEST       EAX,EAX
    //         00403a4e     JZ         LAB_00403b6a
    //                              ACT_GATH.cpp:657 (9)
    //         00403a54     MOV        this,dword ptr [ESI + 0x8]
    //         00403a57     PUSH       EAX
    //         00403a58     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //                              ACT_GATH.cpp:664 (13)
    //         00403a5d     FCOMP      double ptr [DAT_0056e290]
    //         00403a63     FNSTSW     AX
    //         00403a65     TEST       AH,0x41
    //         00403a68     JNZ        LAB_00403a86
    //                              ACT_GATH.cpp:667 (18)
    //         00403a6a     MOV        this,dword ptr [ESI + 0x8]
    //         00403a6d     MOV        dword ptr [ESI + 0x2c],0xc0400000
    //         00403a74     MOV        EAX,dword ptr [this->_padding_]
    //         00403a76     CALL       dword ptr [EAX + 0x1ec]
    //                              ACT_GATH.cpp:751 (2)
    //         00403a7c     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403a7e     POP        EDI
    //         00403a7f     POP        ESI
    //         00403a80     POP        EBP
    //         00403a81     POP        EBX
    //         00403a82     ADD        ESP,0xc
    //         00403a85     RET
    //                               LAB_00403a86                                                 XREF[1]:     00403a68(j)  
    //                              ACT_GATH.cpp:673 (10)
    //         00403a86     MOV        this,dword ptr [ESI + 0x30]
    //         00403a89     MOV        this,dword ptr [this->_padding_ + 0x48]
    //         00403a8c     TEST       this,this
    //         00403a8e     JZ         LAB_00403a97
    //                              ACT_GATH.cpp:674 (7)
    //         00403a90     PUSH       0x1
    //         00403a92     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
    //                               LAB_00403a97                                                 XREF[1]:     00403a8e(j)  
    //                              ACT_GATH.cpp:676 (11)
    //         00403a97     MOV        EDX,dword ptr [ESI + 0x30]
    //         00403a9a     MOV        DX,word ptr [EDX + 0x18]
    //         00403a9e     CMP        DX,-0x1
    //                              ACT_GATH.cpp:678 (2)
    //         00403aa2     JNZ        LAB_00403aab
    //                              ACT_GATH.cpp:679 (7)
    //         00403aa4     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403aa7     MOV        DX,word ptr [EAX + 0x4c]
    //                               LAB_00403aab                                                 XREF[1]:     00403aa2(j)  
    //                              ACT_GATH.cpp:681 (22)
    //         00403aab     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403aae     PUSH       0x1
    //         00403ab0     MOV        dword ptr [ESP + 0x1c],EDX
    //         00403ab4     MOV        this,dword ptr [EAX + 0xc]
    //         00403ab7     MOV        EAX,dword ptr [EAX + 0x44]
    //         00403aba     PUSH       EAX
    //         00403abb     PUSH       EDX
    //         00403abc     MOV        EDI,dword ptr [this->_padding_]
    //         00403abe     CALL       dword ptr [EDI + 0x78]
    //                              ACT_GATH.cpp:682 (32)
    //         00403ac1     MOV        EDI,dword ptr [ESI + 0x8]
    //         00403ac4     MOV        EBX,dword ptr [EDI + 0xc]
    //         00403ac7     FLD        float ptr [EDI + 0x44]
    //         00403aca     MOV        EBP,dword ptr [EBX]
    //         00403acc     CALL       __ftol                                           undefined __ftol()
    //         00403ad1     MOVSX      this,word ptr [ESP + 0x18]
    //         00403ad6     MOV        EDX,dword ptr [EDI + 0x4]
    //         00403ad9     PUSH       EAX
    //         00403ada     PUSH       this
    //         00403adb     PUSH       EDX
    //         00403adc     MOV        this,EBX
    //         00403ade     CALL       dword ptr [EBP + 0x5c]
    //                              ACT_GATH.cpp:683 (15)
    //         00403ae1     MOV        this,dword ptr [ESI + 0x8]
    //         00403ae4     PUSH       0x0
    //         00403ae6     PUSH       -0x1
    //         00403ae8     MOV        EAX,dword ptr [this->_padding_]
    //         00403aea     CALL       dword ptr [EAX + 0x80]
    //                              ACT_GATH.cpp:688 (7)
    //         00403af0     MOV        EAX,dword ptr [ESI + 0x10]
    //         00403af3     TEST       EAX,EAX
    //         00403af5     JZ         LAB_00403b11
    //                              ACT_GATH.cpp:696 (9)
    //         00403af7     MOV        EDI,dword ptr [ESI]
    //         00403af9     PUSH       0x0
    //         00403afb     MOV        this,ESI
    //         00403afd     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:697 (7)
    //         00403b00     PUSH       0x4
    //         00403b02     MOV        this,ESI
    //         00403b04     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403b07     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403b09     POP        EDI
    //         00403b0a     POP        ESI
    //         00403b0b     POP        EBP
    //         00403b0c     POP        EBX
    //         00403b0d     ADD        ESP,0xc
    //         00403b10     RET
    //                               LAB_00403b11                                                 XREF[1]:     00403af5(j)  
    //                              ACT_GATH.cpp:699 (17)
    //         00403b11     MOV        this,dword ptr [ESI + 0x20]
    //         00403b14     MOV        EAX,0xbf800000
    //         00403b19     CMP        this,EAX
    //         00403b1b     JZ         LAB_00403b35
    //         00403b1d     CMP        dword ptr [ESI + 0x24],EAX
    //         00403b20     JZ         LAB_00403b35
    //                              ACT_GATH.cpp:705 (9)
    //         00403b22     MOV        EDX,dword ptr [ESI]
    //         00403b24     PUSH       0xb
    //         00403b26     MOV        this,ESI
    //         00403b28     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403b2b     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403b2d     POP        EDI
    //         00403b2e     POP        ESI
    //         00403b2f     POP        EBP
    //         00403b30     POP        EBX
    //         00403b31     ADD        ESP,0xc
    //         00403b34     RET
    //                               LAB_00403b35                                                 XREF[3]:     00403739(j), 00403b1b(j), 
    //                                                                                                         00403b20(j)  
    //                              ACT_GATH.cpp:711 (16)
    //         00403b35     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403b38     MOV        this,dword ptr [EAX + 0xc]
    //         00403b3b     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00403b40     CMP        EAX,0x1
    //         00403b43     JNZ        LAB_00403b57
    //                              ACT_GATH.cpp:712 (8)
    //         00403b45     MOV        EDX,dword ptr [ESI]
    //         00403b47     PUSH       EAX
    //         00403b48     MOV        this,ESI
    //         00403b4a     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403b4d     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403b4f     POP        EDI
    //         00403b50     POP        ESI
    //         00403b51     POP        EBP
    //         00403b52     POP        EBX
    //         00403b53     ADD        ESP,0xc
    //         00403b56     RET
    //                               LAB_00403b57                                                 XREF[1]:     00403b43(j)  
    //                              ACT_GATH.cpp:714 (9)
    //         00403b57     MOV        EAX,dword ptr [ESI]
    //         00403b59     PUSH       0x2
    //         00403b5b     MOV        this,ESI
    //         00403b5d     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403b60     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403b62     POP        EDI
    //         00403b63     POP        ESI
    //         00403b64     POP        EBP
    //         00403b65     POP        EBX
    //         00403b66     ADD        ESP,0xc
    //         00403b69     RET
    //                               LAB_00403b6a                                                 XREF[1]:     00403a4e(j)  
    //                              ACT_GATH.cpp:718 (9)
    //         00403b6a     MOV        EDX,dword ptr [ESI]
    //         00403b6c     PUSH       0x8
    //         00403b6e     MOV        this,ESI
    //         00403b70     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:751 (2)
    //         00403b73     XOR        AL,AL
    //                              ACT_GATH.cpp:752 (8)
    //         00403b75     POP        EDI
    //         00403b76     POP        ESI
    //         00403b77     POP        EBP
    //         00403b78     POP        EBX
    //         00403b79     ADD        ESP,0xc
    //         00403b7c     RET
    //                               switchD_0040366f::caseD_0                                    XREF[2]:     0040366f(j), 00403be4(*)  
    //                              ACT_GATH.cpp:732 (2)
    //         00403b7d     MOV        AL,0x1
    //                              ACT_GATH.cpp:752 (8)
    //         00403b7f     POP        EDI
    //         00403b80     POP        ESI
    //         00403b81     POP        EBP
    //         00403b82     POP        EBX
    //         00403b83     ADD        ESP,0xc
    //         00403b86     RET
    //                               switchD_0040366f::caseD_c                                    XREF[2]:     0040366f(j), 00403c14(*)  
    //                              ACT_GATH.cpp:737 (30)
    //         00403b87     MOV        this,dword ptr [ESI + 0x8]
    //         00403b8a     PUSH       0x0
    //         00403b8c     PUSH       0x0
    //         00403b8e     PUSH       0x261
    //         00403b93     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00403b96     MOV        EDX,dword ptr [this->_padding_]
    //         00403b98     PUSH       0x1f9
    //         00403b9d     PUSH       EAX
    //         00403b9e     PUSH       EAX
    //         00403b9f     CALL       dword ptr [EDX + 0x148]
    //                              ACT_GATH.cpp:738 (16)
    //         00403ba5     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403ba8     MOV        this,dword ptr [EAX + 0xc]
    //         00403bab     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00403bb0     CMP        EAX,0x1
    //         00403bb3     JNZ        LAB_00403bc7
    //                              ACT_GATH.cpp:739 (8)
    //         00403bb5     MOV        EDX,dword ptr [ESI]
    //         00403bb7     PUSH       EAX
    //         00403bb8     MOV        this,ESI
    //         00403bba     CALL       dword ptr [EDX + 0x5c]
    //                              ACT_GATH.cpp:745 (2)
    //         00403bbd     MOV        AL,0x3
    //                              ACT_GATH.cpp:752 (8)
    //         00403bbf     POP        EDI
    //         00403bc0     POP        ESI
    //         00403bc1     POP        EBP
    //         00403bc2     POP        EBX
    //         00403bc3     ADD        ESP,0xc
    //         00403bc6     RET
    //                               LAB_00403bc7                                                 XREF[1]:     00403bb3(j)  
    //                              ACT_GATH.cpp:741 (9)
    //         00403bc7     MOV        EAX,dword ptr [ESI]
    //         00403bc9     PUSH       0x2
    //         00403bcb     MOV        this,ESI
    //         00403bcd     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:745 (2)
    //         00403bd0     MOV        AL,0x3
    //                              ACT_GATH.cpp:752 (138)
    //         00403bd2     POP        EDI
    //         00403bd3     POP        ESI
    //         00403bd4     POP        EBP
    //         00403bd5     POP        EBX
    //         00403bd6     ADD        ESP,0xc
    //         00403bd9     RET
    //                               switchD_0040366f::caseD_4                                    XREF[17]:    00403669(j), 0040366f(j), 
    //                               switchD_0040366f::caseD_8                                                 00403684(j), 004036aa(j), 
    //                               switchD_0040366f::caseD_9                                                 004036ef(j), 00403763(j), 
    //                               switchD_0040366f::caseD_b                                                 004037ef(j), 0040398e(j), 
    //                               switchD_0040366f::caseD_d                                                 004039a6(j), 004039ef(j), 
    //                               switchD_004036f5::default                                                 00403a20(j), 00403be8(*), 
    //                               switchD_00403a26::default                                                 00403bf4(*), 00403c04(*), 
    //                               switchD_00403769::default                                                 00403c08(*), 00403c10(*), 
    //                               switchD_0040366f::caseD_1                                                 00403c18(*)  
    //         00403bda     POP        EDI
    //         00403bdb     POP        ESI
    //         00403bdc     POP        EBP
    //         00403bdd     XOR        AL,AL
    //         00403bdf     POP        EBX
    //         00403be0     ADD        ESP,0xc
    //         00403be3     RET
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040366f::switchdataD_00403be4                       XREF[1]:     update:0040366f(*)  
}

// Offset: 0x00403C60
RGE_Sprite* get_move_sprite(RGE_Action_Gather* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class RGE_Sprite * __thiscall RGE_Action_Gather::get_move_sprite(void)                     *
    //                              *********************************************************************************************************
    //                              RGE_Sprite * __thiscall get_move_sprite(RGE_Action_Gather * this)
    //              RGE_Sprite *      EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //                               ?get_move_sprite@RGE_Action_Gather@@IAEPAVRGE_Sprite@@XZ     XREF[4]:     set_state:004031ea(c), 
    //                               RGE_Action_Gather::get_move_sprite                                        set_state:004032bf(c), 
    //                                                                                                         set_state:004032f0(c), 
    //                                                                                                         set_state:00403429(c)  
    //                              ACT_GATH.cpp:758 (1)
    //         00403c60     PUSH       ESI
    //                              ACT_GATH.cpp:760 (7)
    //         00403c61     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         00403c64     MOV        AX,word ptr [ESI + 0x14]
    //                              ACT_GATH.cpp:763 (32)
    //         00403c68     CMP        AX,0xffff
    //         00403c6c     JZ         LAB_00403c8a
    //         00403c6e     MOV        this,dword ptr [ECX + this->_padding_]
    //         00403c71     CMP        word ptr [this->_padding_ + 0x4c],AX
    //         00403c75     JNZ        LAB_00403c8a
    //         00403c77     FLD        float ptr [ECX + this+0x44]
    //         00403c7a     CALL       __ftol                                           undefined __ftol()
    //         00403c7f     TEST       EAX,EAX
    //         00403c81     JLE        LAB_00403c8a
    //         00403c83     MOV        EAX,dword ptr [ESI + 0x40]
    //         00403c86     TEST       EAX,EAX
    //                              ACT_GATH.cpp:764 (2)
    //         00403c88     JNZ        LAB_00403c8d
    //                               LAB_00403c8a                                                 XREF[3]:     00403c6c(j), 00403c75(j), 
    //                                                                                                         00403c81(j)  
    //                              ACT_GATH.cpp:766 (3)
    //         00403c8a     MOV        EAX,dword ptr [ESI + 0x34]
    //                               LAB_00403c8d                                                 XREF[1]:     00403c88(j)  
    //                              ACT_GATH.cpp:767 (2)
    //         00403c8d     POP        ESI
    //         00403c8e     RET
}

// Offset: 0x00403C90
RGE_Sprite* get_wait_sprite(RGE_Action_Gather* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class RGE_Sprite * __thiscall RGE_Action_Gather::get_wait_sprite(void)                     *
    //                              *********************************************************************************************************
    //                              RGE_Sprite * __thiscall get_wait_sprite(RGE_Action_Gather * this)
    //              RGE_Sprite *      EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //                               ?get_wait_sprite@RGE_Action_Gather@@IAEPAVRGE_Sprite@@XZ     XREF[2]:     set_state:00403188(c), 
    //                               RGE_Action_Gather::get_wait_sprite                                        set_state:00403530(c)  
    //                              ACT_GATH.cpp:773 (4)
    //         00403c90     PUSH       ESI
    //         00403c91     MOV        ESI,this
    //         00403c93     PUSH       EDI
    //                              ACT_GATH.cpp:776 (39)
    //         00403c94     MOV        EDI,dword ptr [ESI + 0x30]
    //         00403c97     MOV        AX,word ptr [EDI + 0x14]
    //         00403c9b     CMP        AX,0xffff
    //         00403c9f     JZ         LAB_00403cbd
    //         00403ca1     MOV        this,dword ptr [ESI + 0x8]
    //         00403ca4     CMP        AX,word ptr [this->_padding_ + 0x4c]
    //         00403ca8     JNZ        LAB_00403cbd
    //         00403caa     FLD        float ptr [ECX + this+0x44]
    //         00403cad     CALL       __ftol                                           undefined __ftol()
    //         00403cb2     TEST       EAX,EAX
    //         00403cb4     JLE        LAB_00403cbd
    //         00403cb6     MOV        EAX,dword ptr [EDI + 0x40]
    //         00403cb9     TEST       EAX,EAX
    //                              ACT_GATH.cpp:777 (2)
    //         00403cbb     JNZ        LAB_00403cc6
    //                               LAB_00403cbd                                                 XREF[3]:     00403c9f(j), 00403ca8(j), 
    //                                                                                                         00403cb4(j)  
    //                              ACT_GATH.cpp:779 (9)
    //         00403cbd     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403cc0     MOV        this,dword ptr [EAX + 0x8]
    //         00403cc3     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                               LAB_00403cc6                                                 XREF[1]:     00403cbb(j)  
    //                              ACT_GATH.cpp:780 (3)
    //         00403cc6     POP        EDI
    //         00403cc7     POP        ESI
    //         00403cc8     RET
}

// Offset: 0x00403CD0
int RGE_Action_Gather::stop() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Action_Gather::stop(void)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall stop(RGE_Action_Gather * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //                               ?stop@RGE_Action_Gather@@UAEHXZ                              XREF[1]:     0056e244(*)  
    //                               RGE_Action_Gather::stop
    //                              ACT_GATH.cpp:786 (7)
    //         00403cd0     MOV        EAX,dword ptr [this->_padding_]
    //         00403cd2     PUSH       0x2
    //         00403cd4     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_GATH.cpp:788 (5)
    //         00403cd7     MOV        EAX,0x1
    //                              ACT_GATH.cpp:789 (1)
    //         00403cdc     RET
}

// Offset: 0x00403CE0
int RGE_Action_Gather::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Action_Gather::move_to(class RGE_Static_Object *,float,float,fl... *
    //                              *********************************************************************************************************
    //                              int __thiscall move_to(RGE_Action_Gather * this, RGE_Static_Object *
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00403ce1(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00403d62(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00403d66(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00403d5e(R)  
    //                               ?move_to@RGE_Action_Gather@@UAEHPAVRGE_Static_Object@@MMM@Z  XREF[1]:     0056e248(*)  
    //                               RGE_Action_Gather::move_to
    //                              ACT_GATH.cpp:796 (1)
    //         00403ce0     PUSH       EBX
    //                              ACT_GATH.cpp:806 (67)
    //         00403ce1     MOV        EBX,dword ptr [ESP + param_1]
    //         00403ce5     PUSH       ESI
    //         00403ce6     PUSH       EDI
    //         00403ce7     TEST       EBX,EBX
    //         00403ce9     MOV        ESI,this
    //         00403ceb     JZ         LAB_00403d5e
    //         00403ced     MOV        EDX,dword ptr [ESI + 0x8]
    //         00403cf0     MOV        EAX,dword ptr [EBX + 0xc]
    //         00403cf3     CMP        EAX,dword ptr [EDX + 0xc]
    //         00403cf6     JNZ        LAB_00403d5e
    //         00403cf8     MOV        this,dword ptr [EBX + 0x8]
    //         00403cfb     MOV        EAX,dword ptr [EDX + 0x8]
    //         00403cfe     MOV        this,word ptr [ECX + this->_padding_]
    //         00403d02     CMP        this,word ptr [EAX + 0xe8]
    //         00403d09     JZ         LAB_00403d14
    //         00403d0b     CMP        this,word ptr [EAX + 0xea]
    //         00403d12     JNZ        LAB_00403d5e
    //                               LAB_00403d14                                                 XREF[1]:     00403d09(j)  
    //         00403d14     FLD        float ptr [EDX + 0x44]
    //         00403d17     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         00403d1d     FNSTSW     AX
    //         00403d1f     TEST       AH,0x41
    //         00403d22     JNZ        LAB_00403d5e
    //                              ACT_GATH.cpp:810 (9)
    //         00403d24     CMP        EBX,dword ptr [ESI + 0x14]
    //         00403d27     JNZ        LAB_00403d2f
    //         00403d29     CMP        byte ptr [ESI + 0xc],0x8
    //                              ACT_GATH.cpp:811 (2)
    //         00403d2d     JZ         LAB_00403d83
    //                               LAB_00403d2f                                                 XREF[1]:     00403d27(j)  
    //                              ACT_GATH.cpp:814 (9)
    //         00403d2f     MOV        EDI,dword ptr [ESI]
    //         00403d31     PUSH       0x0
    //         00403d33     MOV        this,ESI
    //         00403d35     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:815 (5)
    //         00403d38     MOV        EAX,0xbf800000
    //                              ACT_GATH.cpp:819 (15)
    //         00403d3d     PUSH       EBX
    //         00403d3e     MOV        this,ESI
    //         00403d40     MOV        dword ptr [ESI + 0x20],EAX
    //         00403d43     MOV        dword ptr [ESI + 0x24],EAX
    //         00403d46     MOV        dword ptr [ESI + 0x28],EAX
    //         00403d49     CALL       dword ptr [EDI + 0x58]
    //                              ACT_GATH.cpp:820 (2)
    //         00403d4c     PUSH       0x8
    //                              ACT_GATH.cpp:828 (5)
    //         00403d4e     MOV        this,ESI
    //         00403d50     CALL       dword ptr [EDI + 0x5c]
    //                              ACT_GATH.cpp:830 (5)
    //         00403d53     MOV        EAX,0x1
    //                              ACT_GATH.cpp:831 (6)
    //         00403d58     POP        EDI
    //         00403d59     POP        ESI
    //         00403d5a     POP        EBX
    //         00403d5b     RET        0x10
    //                               LAB_00403d5e                                                 XREF[4]:     00403ceb(j), 00403cf6(j), 
    //                                                                                                         00403d12(j), 00403d22(j)  
    //                              ACT_GATH.cpp:826 (12)
    //         00403d5e     MOV        this,dword ptr [ESP + param_4]
    //         00403d62     MOV        EDX,dword ptr [ESP + param_2]
    //         00403d66     MOV        EAX,dword ptr [ESP + param_3]
    //                              ACT_GATH.cpp:827 (18)
    //         00403d6a     MOV        EDI,dword ptr [ESI]
    //         00403d6c     MOV        dword ptr [ESI + 0x28],this
    //         00403d6f     PUSH       0x0
    //         00403d71     MOV        this,ESI
    //         00403d73     MOV        dword ptr [ESI + 0x20],EDX
    //         00403d76     MOV        dword ptr [ESI + 0x24],EAX
    //         00403d79     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:828 (7)
    //         00403d7c     PUSH       0xf
    //         00403d7e     MOV        this,ESI
    //         00403d80     CALL       dword ptr [EDI + 0x5c]
    //                               LAB_00403d83                                                 XREF[1]:     00403d2d(j)  
    //                              ACT_GATH.cpp:831 (11)
    //         00403d83     POP        EDI
    //         00403d84     POP        ESI
    //         00403d85     MOV        EAX,0x1
    //         00403d8a     POP        EBX
    //         00403d8b     RET        0x10
}

// Offset: 0x00403D90
int RGE_Action_Gather::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Action_Gather::work(class RGE_Static_Object *,float,float,float)   *
    //                              *********************************************************************************************************
    //                              int __thiscall work(RGE_Action_Gather * this, RGE_Static_Object * pa
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00403d93(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00403e65(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00403e69(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00403e61(R)  
    //                               ?work@RGE_Action_Gather@@UAEHPAVRGE_Static_Object@@MMM@Z     XREF[1]:     0056e24c(*)  
    //                               RGE_Action_Gather::work
    //                              ACT_GATH.cpp:837 (3)
    //         00403d90     PUSH       EBX
    //         00403d91     PUSH       ESI
    //         00403d92     PUSH       EDI
    //                              ACT_GATH.cpp:845 (14)
    //         00403d93     MOV        EDI,dword ptr [ESP + param_1]
    //         00403d97     TEST       EDI,EDI
    //         00403d99     MOV        ESI,this
    //         00403d9b     JZ         LAB_00403e61
    //                              ACT_GATH.cpp:850 (26)
    //         00403da1     CMP        EDI,dword ptr [ESI + 0x10]
    //         00403da4     JNZ        LAB_00403dc1
    //         00403da6     MOV        AL,byte ptr [ESI + 0xc]
    //         00403da9     CMP        AL,0x4
    //         00403dab     JZ         LAB_00403e86
    //         00403db1     CMP        AL,0x6
    //         00403db3     JZ         LAB_00403e86
    //         00403db9     CMP        AL,0x7
    //                              ACT_GATH.cpp:851 (6)
    //         00403dbb     JZ         LAB_00403e86
    //                               LAB_00403dc1                                                 XREF[1]:     00403da4(j)  
    //                              ACT_GATH.cpp:856 (55)
    //         00403dc1     MOV        EDX,dword ptr [ESI + 0x8]
    //         00403dc4     MOV        EAX,dword ptr [EDI + 0xc]
    //         00403dc7     CMP        EAX,dword ptr [EDX + 0xc]
    //         00403dca     JNZ        LAB_00403e2e
    //         00403dcc     MOV        this,dword ptr [EDI + 0x8]
    //         00403dcf     MOV        EAX,dword ptr [EDX + 0x8]
    //         00403dd2     MOV        this,word ptr [ECX + this->_padding_]
    //         00403dd6     CMP        this,word ptr [EAX + 0xe8]
    //         00403ddd     JZ         LAB_00403de8
    //         00403ddf     CMP        this,word ptr [EAX + 0xea]
    //         00403de6     JNZ        LAB_00403e2e
    //                               LAB_00403de8                                                 XREF[1]:     00403ddd(j)  
    //         00403de8     FLD        float ptr [EDX + 0x44]
    //         00403deb     FCOMP      float ptr [DAT_0056e278]                         = align(18)
    //         00403df1     FNSTSW     AX
    //         00403df3     TEST       AH,0x41
    //         00403df6     JNZ        LAB_00403e2e
    //                              ACT_GATH.cpp:860 (16)
    //         00403df8     MOV        EBX,dword ptr [ESI]
    //         00403dfa     PUSH       0x0
    //         00403dfc     MOV        this,ESI
    //         00403dfe     MOV        dword ptr [ESI + 0x2c],0x0
    //         00403e05     CALL       dword ptr [EBX + 0x54]
    //                              ACT_GATH.cpp:861 (5)
    //         00403e08     MOV        EAX,0xbf800000
    //                              ACT_GATH.cpp:865 (15)
    //         00403e0d     PUSH       EDI
    //         00403e0e     MOV        this,ESI
    //         00403e10     MOV        dword ptr [ESI + 0x20],EAX
    //         00403e13     MOV        dword ptr [ESI + 0x24],EAX
    //         00403e16     MOV        dword ptr [ESI + 0x28],EAX
    //         00403e19     CALL       dword ptr [EBX + 0x58]
    //                              ACT_GATH.cpp:866 (7)
    //         00403e1c     PUSH       0x8
    //         00403e1e     MOV        this,ESI
    //         00403e20     CALL       dword ptr [EBX + 0x5c]
    //                              ACT_GATH.cpp:886 (5)
    //         00403e23     MOV        EAX,0x1
    //                              ACT_GATH.cpp:887 (6)
    //         00403e28     POP        EDI
    //         00403e29     POP        ESI
    //         00403e2a     POP        EBX
    //         00403e2b     RET        0x10
    //                               LAB_00403e2e                                                 XREF[3]:     00403dca(j), 00403de6(j), 
    //                                                                                                         00403df6(j)  
    //                              ACT_GATH.cpp:870 (8)
    //         00403e2e     MOV        EBX,dword ptr [ESI]
    //         00403e30     PUSH       EDI
    //         00403e31     MOV        this,ESI
    //         00403e33     CALL       dword ptr [EBX + 0x54]
    //                              ACT_GATH.cpp:871 (3)
    //         00403e36     MOV        EDX,dword ptr [EDI + 0x38]
    //                              ACT_GATH.cpp:875 (22)
    //         00403e39     PUSH       0x0
    //         00403e3b     MOV        dword ptr [ESI + 0x20],EDX
    //         00403e3e     MOV        EAX,dword ptr [EDI + 0x3c]
    //         00403e41     MOV        dword ptr [ESI + 0x24],EAX
    //         00403e44     MOV        this,dword ptr [EDI + 0x40]
    //         00403e47     MOV        dword ptr [ESI + 0x28],this
    //         00403e4a     MOV        this,ESI
    //         00403e4c     CALL       dword ptr [EBX + 0x58]
    //                              ACT_GATH.cpp:876 (7)
    //         00403e4f     PUSH       0x4
    //         00403e51     MOV        this,ESI
    //         00403e53     CALL       dword ptr [EBX + 0x5c]
    //                              ACT_GATH.cpp:886 (5)
    //         00403e56     MOV        EAX,0x1
    //                              ACT_GATH.cpp:887 (6)
    //         00403e5b     POP        EDI
    //         00403e5c     POP        ESI
    //         00403e5d     POP        EBX
    //         00403e5e     RET        0x10
    //                               LAB_00403e61                                                 XREF[1]:     00403d9b(j)  
    //                              ACT_GATH.cpp:882 (12)
    //         00403e61     MOV        this,dword ptr [ESP + param_4]
    //         00403e65     MOV        EDX,dword ptr [ESP + param_2]
    //         00403e69     MOV        EAX,dword ptr [ESP + param_3]
    //                              ACT_GATH.cpp:883 (18)
    //         00403e6d     MOV        EDI,dword ptr [ESI]
    //         00403e6f     MOV        dword ptr [ESI + 0x28],this
    //         00403e72     PUSH       0x0
    //         00403e74     MOV        this,ESI
    //         00403e76     MOV        dword ptr [ESI + 0x20],EDX
    //         00403e79     MOV        dword ptr [ESI + 0x24],EAX
    //         00403e7c     CALL       dword ptr [EDI + 0x54]
    //                              ACT_GATH.cpp:884 (7)
    //         00403e7f     PUSH       0xf
    //         00403e81     MOV        this,ESI
    //         00403e83     CALL       dword ptr [EDI + 0x5c]
    //                               LAB_00403e86                                                 XREF[3]:     00403dab(j), 00403db3(j), 
    //                                                                                                         00403dbb(j)  
    //                              ACT_GATH.cpp:887 (11)
    //         00403e86     POP        EDI
    //         00403e87     POP        ESI
    //         00403e88     MOV        EAX,0x1
    //         00403e8d     POP        EBX
    //         00403e8e     RET        0x10
}

