#include "common.h"
#include "task.h"

RGE_Task::RGE_Task(short param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Task(RGE_Task * this, short param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00508675(R)  
    //                               ??0RGE_Task@@QAE@F@Z                                         XREF[1]:     create_task:005090ee(c)  
    //                               RGE_Task::RGE_Task
    //                              task.cpp:26 (2)
    //         00508670     MOV        EAX,this
    //                              task.cpp:34 (38)
    //         00508672     OR         EDX,0xffffffff
    //         00508675     MOV        this,word ptr [ESP + param_1]
    //         0050867a     MOV        word ptr [EAX + 0x2],this
    //         0050867e     XOR        this,this
    //         00508680     MOV        word ptr [EAX],0x1
    //         00508685     MOV        byte ptr [EAX + 0x4],this
    //         00508688     MOV        word ptr [EAX + 0x6],this
    //         0050868c     MOV        word ptr [EAX + 0x8],this
    //         00508690     MOV        word ptr [EAX + 0xa],this
    //         00508694     MOV        word ptr [EAX + 0xe],DX
    //                              task.cpp:35 (4)
    //         00508698     MOV        word ptr [EAX + 0x14],DX
    //                              task.cpp:36 (4)
    //         0050869c     MOV        word ptr [EAX + 0x16],DX
    //                              task.cpp:37 (4)
    //         005086a0     MOV        word ptr [EAX + 0x18],DX
    //                              task.cpp:38 (4)
    //         005086a4     MOV        word ptr [EAX + 0x1a],DX
    //                              task.cpp:39 (3)
    //         005086a8     MOV        dword ptr [EAX + 0x1c],this
    //                              task.cpp:40 (3)
    //         005086ab     MOV        dword ptr [EAX + 0x20],this
    //                              task.cpp:41 (3)
    //         005086ae     MOV        dword ptr [EAX + 0x24],this
    //                              task.cpp:42 (3)
    //         005086b1     MOV        byte ptr [EAX + 0x28],this
    //                              task.cpp:43 (3)
    //         005086b4     MOV        dword ptr [EAX + 0x2c],this
    //                              task.cpp:44 (3)
    //         005086b7     MOV        byte ptr [EAX + 0xc],this
    //                              task.cpp:45 (3)
    //         005086ba     MOV        byte ptr [EAX + 0xd],this
    //                              task.cpp:46 (4)
    //         005086bd     MOV        word ptr [EAX + 0x30],this
    //                              task.cpp:47 (4)
    //         005086c1     MOV        word ptr [EAX + 0x32],this
    //                              task.cpp:48 (3)
    //         005086c5     MOV        byte ptr [EAX + 0x10],this
    //                              task.cpp:49 (3)
    //         005086c8     MOV        byte ptr [EAX + 0x11],this
    //                              task.cpp:50 (3)
    //         005086cb     MOV        byte ptr [EAX + 0x12],this
    //                              task.cpp:51 (3)
    //         005086ce     MOV        dword ptr [EAX + 0x34],this
    //                              task.cpp:52 (3)
    //         005086d1     MOV        dword ptr [EAX + 0x38],this
    //                              task.cpp:53 (3)
    //         005086d4     MOV        dword ptr [EAX + 0x3c],this
    //                              task.cpp:54 (3)
    //         005086d7     MOV        dword ptr [EAX + 0x40],this
    //                              task.cpp:55 (3)
    //         005086da     MOV        dword ptr [EAX + 0x44],this
    //                              task.cpp:56 (3)
    //         005086dd     MOV        dword ptr [EAX + 0x48],this
    //                              task.cpp:57 (3)
    //         005086e0     RET        0x4
    //         005086e3     ??         90h
    //         005086e4     NOP
    //         005086e5     NOP
    //         005086e6     NOP
    //         005086e7     NOP
    //         005086e8     NOP
    //         005086e9     NOP
    //         005086ea     NOP
    //         005086eb     NOP
    //         005086ec     NOP
    //         005086ed     NOP
    //         005086ee     NOP
    //         005086ef     NOP
}

RGE_Task::~RGE_Task() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Task(RGE_Task * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //                               ??1RGE_Task@@QAE@XZ                                          XREF[1]:     delete_list:00509075(c)  
    //                               RGE_Task::~RGE_Task
    //                              task.cpp:62 (1)
    //         005086f0     RET
    //         005086f1     ??         90h
    //         005086f2     NOP
    //         005086f3     NOP
    //         005086f4     NOP
    //         005086f5     NOP
    //         005086f6     NOP
    //         005086f7     NOP
    //         005086f8     NOP
    //         005086f9     NOP
    //         005086fa     NOP
    //         005086fb     NOP
    //         005086fc     NOP
    //         005086fd     NOP
    //         005086fe     NOP
    //         005086ff     NOP
}

void RGE_Task::copy(RGE_Task* param_1) {
    /* TODO: Stub */
    //                              void __thiscall copy(RGE_Task * this, RGE_Task * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     00508700(R)  
    //                               ?copy@RGE_Task@@QAEXPAV1@@Z                                  XREF[1]:     copy:00508e9e(c)  
    //                               RGE_Task::copy
    //                              task.cpp:68 (10)
    //         00508700     MOV        EAX,dword ptr [ESP + param_1]
    //         00508704     MOV        DL,byte ptr [EAX + 0x4]
    //         00508707     MOV        byte ptr [ECX + this->is_default],DL
    //                              task.cpp:70 (8)
    //         0050870a     MOV        DX,word ptr [EAX + 0x6]
    //         0050870e     MOV        word ptr [ECX + this->action_type],DX
    //                              task.cpp:71 (8)
    //         00508712     MOV        DX,word ptr [EAX + 0x8]
    //         00508716     MOV        word ptr [ECX + this->object_group],DX
    //                              task.cpp:72 (8)
    //         0050871a     MOV        DX,word ptr [EAX + 0xa]
    //         0050871e     MOV        word ptr [ECX + this->object_id],DX
    //                              task.cpp:73 (8)
    //         00508722     MOV        DX,word ptr [EAX + 0xe]
    //         00508726     MOV        word ptr [ECX + this->terrain_id],DX
    //                              task.cpp:74 (8)
    //         0050872a     MOV        DX,word ptr [EAX + 0x14]
    //         0050872e     MOV        word ptr [ECX + this->attribute_type],DX
    //                              task.cpp:75 (8)
    //         00508732     MOV        DX,word ptr [EAX + 0x16]
    //         00508736     MOV        word ptr [ECX + this->attribute_type2],DX
    //                              task.cpp:76 (8)
    //         0050873a     MOV        DX,word ptr [EAX + 0x18]
    //         0050873e     MOV        word ptr [ECX + this->attribute_type3],DX
    //                              task.cpp:77 (8)
    //         00508742     MOV        DX,word ptr [EAX + 0x1a]
    //         00508746     MOV        word ptr [ECX + this->attribute_type4],DX
    //                              task.cpp:78 (6)
    //         0050874a     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0050874d     MOV        dword ptr [ECX + this->work_val1],EDX
    //                              task.cpp:79 (6)
    //         00508750     MOV        EDX,dword ptr [EAX + 0x20]
    //         00508753     MOV        dword ptr [ECX + this->work_val2],EDX
    //                              task.cpp:80 (6)
    //         00508756     MOV        EDX,dword ptr [EAX + 0x24]
    //         00508759     MOV        dword ptr [ECX + this->work_range],EDX
    //                              task.cpp:81 (6)
    //         0050875c     MOV        DL,byte ptr [EAX + 0x28]
    //         0050875f     MOV        byte ptr [ECX + this->search_flag],DL
    //                              task.cpp:82 (6)
    //         00508762     MOV        EDX,dword ptr [EAX + 0x2c]
    //         00508765     MOV        dword ptr [ECX + this->search_wait_time],EDX
    //                              task.cpp:83 (6)
    //         00508768     MOV        DL,byte ptr [EAX + 0xc]
    //         0050876b     MOV        byte ptr [ECX + this->combat_level],DL
    //                              task.cpp:84 (6)
    //         0050876e     MOV        DL,byte ptr [EAX + 0xd]
    //         00508771     MOV        byte ptr [ECX + this->combat_level_flag],DL
    //                              task.cpp:85 (8)
    //         00508774     MOV        DX,word ptr [EAX + 0x30]
    //         00508778     MOV        word ptr [ECX + this->work_flag],DX
    //                              task.cpp:86 (8)
    //         0050877c     MOV        DX,word ptr [EAX + 0x32]
    //         00508780     MOV        word ptr [ECX + this->work_flag2],DX
    //                              task.cpp:87 (6)
    //         00508784     MOV        DL,byte ptr [EAX + 0x10]
    //         00508787     MOV        byte ptr [ECX + this->owner_type],DL
    //                              task.cpp:88 (6)
    //         0050878a     MOV        DL,byte ptr [EAX + 0x11]
    //         0050878d     MOV        byte ptr [ECX + this->holding_attr],DL
    //                              task.cpp:89 (6)
    //         00508790     MOV        DL,byte ptr [EAX + 0x12]
    //         00508793     MOV        byte ptr [ECX + this->state_building],DL
    //                              task.cpp:91 (6)
    //         00508796     MOV        EDX,dword ptr [EAX + 0x34]
    //         00508799     MOV        dword ptr [ECX + this->move_sprite],EDX
    //                              task.cpp:92 (6)
    //         0050879c     MOV        EDX,dword ptr [EAX + 0x38]
    //         0050879f     MOV        dword ptr [ECX + this->work_sprite],EDX
    //                              task.cpp:93 (6)
    //         005087a2     MOV        EDX,dword ptr [EAX + 0x3c]
    //         005087a5     MOV        dword ptr [ECX + this->work_sprite2],EDX
    //                              task.cpp:94 (6)
    //         005087a8     MOV        EDX,dword ptr [EAX + 0x40]
    //         005087ab     MOV        dword ptr [ECX + this->carry_sprite],EDX
    //                              task.cpp:96 (6)
    //         005087ae     MOV        EDX,dword ptr [EAX + 0x44]
    //         005087b1     MOV        dword ptr [ECX + this->work_sound],EDX
    //                              task.cpp:97 (6)
    //         005087b4     MOV        EAX,dword ptr [EAX + 0x48]
    //         005087b7     MOV        dword ptr [ECX + this->work_sound2],EAX
    //                              task.cpp:98 (3)
    //         005087ba     RET        0x4
    //         005087bd     ??         90h
    //         005087be     NOP
    //         005087bf     NOP
    return;
}

void RGE_Task::load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
    //                              void __thiscall load(RGE_Task * this, int param_1, RGE_Sprite * * pa
    //              void              <VOID>         <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[13]:    005087c2(R), 00508913(*), 00508920(R), 0050893f(*), 
    //                                                                                     0050894c(R), 00508964(*), 00508974(R), 0050898c(*), 
    //                                                                                     0050899c(R), 005089b7(*), 005089c4(R), 005089e0(*), 
    //                                                                                     005089f0(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00508925(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     005089c9(R)  
    //                               ?load@RGE_Task@@QAEXHPAPAVRGE_Sprite@@PAPAVRGE_Sound@@@Z     XREF[1]:     load:00508f47(c)  
    //                               RGE_Task::load
    //                              task.cpp:103 (2)
    //         005087c0     PUSH       EBX
    //         005087c1     PUSH       ESI
    //                              task.cpp:109 (22)
    //         005087c2     MOV        ESI,dword ptr [ESP + param_1]
    //         005087c6     PUSH       EDI
    //         005087c7     MOV        EDI,this
    //         005087c9     PUSH       0x2
    //         005087cb     LEA        EAX,[EDI + 0x2]
    //         005087ce     PUSH       EAX
    //         005087cf     PUSH       ESI
    //         005087d0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005087d5     ADD        ESP,0xc
    //                              task.cpp:110 (15)
    //         005087d8     LEA        this,[EDI + 0x4]
    //         005087db     PUSH       0x1
    //         005087dd     PUSH       this
    //         005087de     PUSH       ESI
    //         005087df     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005087e4     ADD        ESP,0xc
    //                              task.cpp:111 (15)
    //         005087e7     LEA        EDX,[EDI + 0x6]
    //         005087ea     PUSH       0x2
    //         005087ec     PUSH       EDX
    //         005087ed     PUSH       ESI
    //         005087ee     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005087f3     ADD        ESP,0xc
    //                              task.cpp:112 (15)
    //         005087f6     LEA        EAX,[EDI + 0x8]
    //         005087f9     PUSH       0x2
    //         005087fb     PUSH       EAX
    //         005087fc     PUSH       ESI
    //         005087fd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508802     ADD        ESP,0xc
    //                              task.cpp:113 (15)
    //         00508805     LEA        this,[EDI + 0xa]
    //         00508808     PUSH       0x2
    //         0050880a     PUSH       this
    //         0050880b     PUSH       ESI
    //         0050880c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508811     ADD        ESP,0xc
    //                              task.cpp:114 (15)
    //         00508814     LEA        EDX,[EDI + 0xe]
    //         00508817     PUSH       0x2
    //         00508819     PUSH       EDX
    //         0050881a     PUSH       ESI
    //         0050881b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508820     ADD        ESP,0xc
    //                              task.cpp:115 (15)
    //         00508823     LEA        EAX,[EDI + 0x14]
    //         00508826     PUSH       0x2
    //         00508828     PUSH       EAX
    //         00508829     PUSH       ESI
    //         0050882a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050882f     ADD        ESP,0xc
    //                              task.cpp:116 (15)
    //         00508832     LEA        this,[EDI + 0x16]
    //         00508835     PUSH       0x2
    //         00508837     PUSH       this
    //         00508838     PUSH       ESI
    //         00508839     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050883e     ADD        ESP,0xc
    //                              task.cpp:117 (15)
    //         00508841     LEA        EDX,[EDI + 0x18]
    //         00508844     PUSH       0x2
    //         00508846     PUSH       EDX
    //         00508847     PUSH       ESI
    //         00508848     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050884d     ADD        ESP,0xc
    //                              task.cpp:118 (15)
    //         00508850     LEA        EAX,[EDI + 0x1a]
    //         00508853     PUSH       0x2
    //         00508855     PUSH       EAX
    //         00508856     PUSH       ESI
    //         00508857     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050885c     ADD        ESP,0xc
    //                              task.cpp:119 (15)
    //         0050885f     LEA        this,[EDI + 0x1c]
    //         00508862     PUSH       0x4
    //         00508864     PUSH       this
    //         00508865     PUSH       ESI
    //         00508866     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050886b     ADD        ESP,0xc
    //                              task.cpp:120 (15)
    //         0050886e     LEA        EDX,[EDI + 0x20]
    //         00508871     PUSH       0x4
    //         00508873     PUSH       EDX
    //         00508874     PUSH       ESI
    //         00508875     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050887a     ADD        ESP,0xc
    //                              task.cpp:121 (15)
    //         0050887d     LEA        EAX,[EDI + 0x24]
    //         00508880     PUSH       0x4
    //         00508882     PUSH       EAX
    //         00508883     PUSH       ESI
    //         00508884     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508889     ADD        ESP,0xc
    //                              task.cpp:122 (15)
    //         0050888c     LEA        this,[EDI + 0x28]
    //         0050888f     PUSH       0x1
    //         00508891     PUSH       this
    //         00508892     PUSH       ESI
    //         00508893     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508898     ADD        ESP,0xc
    //                              task.cpp:123 (15)
    //         0050889b     LEA        EDX,[EDI + 0x2c]
    //         0050889e     PUSH       0x4
    //         005088a0     PUSH       EDX
    //         005088a1     PUSH       ESI
    //         005088a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088a7     ADD        ESP,0xc
    //                              task.cpp:124 (15)
    //         005088aa     LEA        EAX,[EDI + 0xc]
    //         005088ad     PUSH       0x1
    //         005088af     PUSH       EAX
    //         005088b0     PUSH       ESI
    //         005088b1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088b6     ADD        ESP,0xc
    //                              task.cpp:125 (15)
    //         005088b9     LEA        this,[EDI + 0xd]
    //         005088bc     PUSH       0x1
    //         005088be     PUSH       this
    //         005088bf     PUSH       ESI
    //         005088c0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088c5     ADD        ESP,0xc
    //                              task.cpp:126 (15)
    //         005088c8     LEA        EDX,[EDI + 0x30]
    //         005088cb     PUSH       0x2
    //         005088cd     PUSH       EDX
    //         005088ce     PUSH       ESI
    //         005088cf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088d4     ADD        ESP,0xc
    //                              task.cpp:127 (15)
    //         005088d7     LEA        EAX,[EDI + 0x32]
    //         005088da     PUSH       0x2
    //         005088dc     PUSH       EAX
    //         005088dd     PUSH       ESI
    //         005088de     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088e3     ADD        ESP,0xc
    //                              task.cpp:128 (15)
    //         005088e6     LEA        this,[EDI + 0x10]
    //         005088e9     PUSH       0x1
    //         005088eb     PUSH       this
    //         005088ec     PUSH       ESI
    //         005088ed     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005088f2     ADD        ESP,0xc
    //                              task.cpp:129 (15)
    //         005088f5     LEA        EDX,[EDI + 0x11]
    //         005088f8     PUSH       0x1
    //         005088fa     PUSH       EDX
    //         005088fb     PUSH       ESI
    //         005088fc     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508901     ADD        ESP,0xc
    //                              task.cpp:130 (15)
    //         00508904     LEA        EAX,[EDI + 0x12]
    //         00508907     PUSH       0x1
    //         00508909     PUSH       EAX
    //         0050890a     PUSH       ESI
    //         0050890b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00508910     ADD        ESP,0xc
    //                              task.cpp:132 (13)
    //         00508913     LEA        this=>param_1,[ESP + 0x10]
    //         00508917     PUSH       0x2
    //         00508919     PUSH       this
    //         0050891a     PUSH       ESI
    //         0050891b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:133 (31)
    //         00508920     MOV        AX,word ptr [ESP + param_1]
    //         00508925     MOV        EBX,dword ptr [ESP + param_2]
    //         00508929     ADD        ESP,0xc
    //         0050892c     CMP        AX,0xffff
    //         00508930     JNZ        LAB_00508936
    //         00508932     XOR        EAX,EAX
    //         00508934     JMP        LAB_0050893c
    //                               LAB_00508936                                                 XREF[1]:     00508930(j)  
    //         00508936     MOVSX      EDX,AX
    //         00508939     MOV        EAX,dword ptr [EBX + EDX*0x4]
    //                               LAB_0050893c                                                 XREF[1]:     00508934(j)  
    //         0050893c     MOV        dword ptr [EDI + 0x34],EAX
    //                              task.cpp:135 (13)
    //         0050893f     LEA        EAX=>param_1,[ESP + 0x10]
    //         00508943     PUSH       0x2
    //         00508945     PUSH       EAX
    //         00508946     PUSH       ESI
    //         00508947     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:136 (24)
    //         0050894c     MOV        AX,word ptr [ESP + param_1]
    //         00508951     ADD        ESP,0xc
    //         00508954     CMP        AX,0xffff
    //         00508958     JNZ        LAB_0050895e
    //         0050895a     XOR        EAX,EAX
    //         0050895c     JMP        LAB_00508964
    //                               LAB_0050895e                                                 XREF[1]:     00508958(j)  
    //         0050895e     MOVSX      this,AX
    //         00508961     MOV        EAX,dword ptr [EBX + this->task_type*0x4]
    //                               LAB_00508964                                                 XREF[1]:     0050895c(j)  
    //                              task.cpp:138 (16)
    //         00508964     LEA        EDX=>param_1,[ESP + 0x10]
    //         00508968     PUSH       0x2
    //         0050896a     PUSH       EDX
    //         0050896b     PUSH       ESI
    //         0050896c     MOV        dword ptr [EDI + 0x38],EAX
    //         0050896f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:139 (24)
    //         00508974     MOV        AX,word ptr [ESP + param_1]
    //         00508979     ADD        ESP,0xc
    //         0050897c     CMP        AX,0xffff
    //         00508980     JNZ        LAB_00508986
    //         00508982     XOR        EAX,EAX
    //         00508984     JMP        LAB_0050898c
    //                               LAB_00508986                                                 XREF[1]:     00508980(j)  
    //         00508986     MOVSX      EAX,AX
    //         00508989     MOV        EAX,dword ptr [EBX + EAX*0x4]
    //                               LAB_0050898c                                                 XREF[1]:     00508984(j)  
    //                              task.cpp:141 (16)
    //         0050898c     LEA        this=>param_1,[ESP + 0x10]
    //         00508990     PUSH       0x2
    //         00508992     PUSH       this
    //         00508993     PUSH       ESI
    //         00508994     MOV        dword ptr [EDI + 0x3c],EAX
    //         00508997     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:142 (27)
    //         0050899c     MOV        AX,word ptr [ESP + param_1]
    //         005089a1     ADD        ESP,0xc
    //         005089a4     CMP        AX,0xffff
    //         005089a8     JNZ        LAB_005089ae
    //         005089aa     XOR        EAX,EAX
    //         005089ac     JMP        LAB_005089b4
    //                               LAB_005089ae                                                 XREF[1]:     005089a8(j)  
    //         005089ae     MOVSX      EDX,AX
    //         005089b1     MOV        EAX,dword ptr [EBX + EDX*0x4]
    //                               LAB_005089b4                                                 XREF[1]:     005089ac(j)  
    //         005089b4     MOV        dword ptr [EDI + 0x40],EAX
    //                              task.cpp:144 (13)
    //         005089b7     LEA        EAX=>param_1,[ESP + 0x10]
    //         005089bb     PUSH       0x2
    //         005089bd     PUSH       EAX
    //         005089be     PUSH       ESI
    //         005089bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:145 (28)
    //         005089c4     MOV        AX,word ptr [ESP + param_1]
    //         005089c9     MOV        EBX,dword ptr [ESP + param_3]
    //         005089cd     ADD        ESP,0xc
    //         005089d0     CMP        AX,0xffff
    //         005089d4     JNZ        LAB_005089da
    //         005089d6     XOR        EAX,EAX
    //         005089d8     JMP        LAB_005089e0
    //                               LAB_005089da                                                 XREF[1]:     005089d4(j)  
    //         005089da     MOVSX      this,AX
    //         005089dd     MOV        EAX,dword ptr [EBX + this->task_type*0x4]
    //                               LAB_005089e0                                                 XREF[1]:     005089d8(j)  
    //                              task.cpp:147 (16)
    //         005089e0     LEA        EDX=>param_1,[ESP + 0x10]
    //         005089e4     PUSH       0x2
    //         005089e6     PUSH       EDX
    //         005089e7     PUSH       ESI
    //         005089e8     MOV        dword ptr [EDI + 0x44],EAX
    //         005089eb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              task.cpp:148 (19)
    //         005089f0     MOV        AX,word ptr [ESP + param_1]
    //         005089f5     ADD        ESP,0xc
    //         005089f8     CMP        AX,0xffff
    //         005089fc     JNZ        LAB_00508a09
    //         005089fe     XOR        EAX,EAX
    //         00508a00     MOV        dword ptr [EDI + 0x48],EAX
    //                              task.cpp:149 (6)
    //         00508a03     POP        EDI
    //         00508a04     POP        ESI
    //         00508a05     POP        EBX
    //         00508a06     RET        0xc
    //                               LAB_00508a09                                                 XREF[1]:     005089fc(j)  
    //                              task.cpp:148 (9)
    //         00508a09     MOVSX      EAX,AX
    //         00508a0c     MOV        EAX,dword ptr [EBX + EAX*0x4]
    //         00508a0f     MOV        dword ptr [EDI + 0x48],EAX
    //                              task.cpp:149 (6)
    //         00508a12     POP        EDI
    //         00508a13     POP        ESI
    //         00508a14     POP        EBX
    //         00508a15     RET        0xc
    //         00508a18     ??         90h
    //         00508a19     NOP
    //         00508a1a     NOP
    //         00508a1b     NOP
    //         00508a1c     NOP
    //         00508a1d     NOP
    //         00508a1e     NOP
    //         00508a1f     NOP
    return;
}

void RGE_Task::load(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
    //                              void __thiscall load(RGE_Task * this, _iobuf * param_1, RGE_Sprite *
    //              void              <VOID>         <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00508a99(*), 00508aa1(R), 00508ab8(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00508b00(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00508b5f(R)  
    //              undefined2        Stack[-0x2]:2  local_2                   XREF[2]:     00508a23(*), 00508b7e(R)  
    //              undefined2        Stack[-0x4]:2  local_4                   XREF[2]:     00508a2e(*), 00508b66(R)  
    //              short             Stack[-0x6]:2  work_sound2_id            XREF[2]:     00508a27(*), 00508b4a(R)  
    //              short             Stack[-0x8]:2  work_sound_id             XREF[2]:     00508a34(*), 00508b32(R)  
    //              short             Stack[-0xa]:2  carry_sprite_id           XREF[2]:     00508a39(*), 00508b1a(R)  
    //              short             Stack[-0xc]:2  work_sprite2_id           XREF[2]:     00508a3e(*), 00508af2(R)  
    //              short             Stack[-0xe]:2  work_sprite_id            XREF[2]:     00508a43(*), 00508ae8(R)  
    //              short             Stack[-0x10]:2 move_sprite_id            XREF[2]:     00508a48(*), 00508ade(R)  
    //              short             Stack[-0x12]:2 temp_state_building       XREF[2]:     00508a4d(*), 00508ad4(R)  
    //              short             Stack[-0x14]:2 temp_holding_attr         XREF[2]:     00508a68(*), 00508aca(R)  
    //              short             Stack[-0x16]:2 temp_owner_type           XREF[2]:     00508a5a(*), 00508ac3(R)  
    //              short             Stack[-0x18]:2 temp_search_flag          XREF[2]:     00508a5f(*), 00508abf(R)  
    //              short             Stack[-0x1a]:2 temp_combat_level_flag
    //              short             Stack[-0x1c]:2 temp_combat_level
    //                               ?load@RGE_Task@@QAEXPAU_iobuf@@PAPAVRGE_Sprite@@PAPAVRGE_So  XREF[1]:     load:00508fed(c)  
    //                               RGE_Task::load
    //                              task.cpp:154 (3)
    //         00508a20     SUB        ESP,0x18
    //                              task.cpp:200 (149)
    //         00508a23     LEA        EAX=>local_2,[ESP + 0x16]
    //         00508a27     LEA        EDX=>work_sound2_id,[ESP + 0x12]
    //         00508a2b     PUSH       ESI
    //         00508a2c     MOV        ESI,this
    //         00508a2e     LEA        this=>local_4,[ESP + 0x18]
    //         00508a32     PUSH       EAX
    //         00508a33     PUSH       this
    //         00508a34     LEA        EAX=>work_sound_id,[ESP + 0x1c]
    //         00508a38     PUSH       EDX
    //         00508a39     LEA        this=>carry_sprite_id,[ESP + 0x1e]
    //         00508a3d     PUSH       EAX
    //         00508a3e     LEA        EDX=>work_sprite2_id,[ESP + 0x20]
    //         00508a42     PUSH       this
    //         00508a43     LEA        EAX=>work_sprite_id,[ESP + 0x22]
    //         00508a47     PUSH       EDX
    //         00508a48     LEA        this=>move_sprite_id,[ESP + 0x24]
    //         00508a4c     PUSH       EAX
    //         00508a4d     LEA        EDX=>temp_state_building,[ESP + 0x26]
    //         00508a51     PUSH       this
    //         00508a52     LEA        EAX,[ESI + 0x32]
    //         00508a55     PUSH       EDX
    //         00508a56     LEA        this,[ESI + 0x30]
    //         00508a59     PUSH       EAX
    //         00508a5a     LEA        EDX=>temp_owner_type,[ESP + 0x2e]
    //         00508a5e     PUSH       this
    //         00508a5f     LEA        EAX=>temp_search_flag,[ESP + 0x30]
    //         00508a63     PUSH       EDX
    //         00508a64     LEA        this,[ESI + 0x2c]
    //         00508a67     PUSH       EAX
    //         00508a68     LEA        EDX=>temp_holding_attr,[ESP + 0x3c]
    //         00508a6c     PUSH       this
    //         00508a6d     LEA        EAX,[ESI + 0x24]
    //         00508a70     PUSH       EDX
    //         00508a71     LEA        this,[ESI + 0x20]
    //         00508a74     PUSH       EAX
    //         00508a75     LEA        EDX,[ESI + 0x1c]
    //         00508a78     PUSH       this
    //         00508a79     LEA        EAX,[ESI + 0x1a]
    //         00508a7c     PUSH       EDX
    //         00508a7d     LEA        this,[ESI + 0x18]
    //         00508a80     PUSH       EAX
    //         00508a81     LEA        EDX,[ESI + 0x16]
    //         00508a84     PUSH       this
    //         00508a85     LEA        EAX,[ESI + 0x14]
    //         00508a88     PUSH       EDX
    //         00508a89     LEA        this,[ESI + 0xe]
    //         00508a8c     PUSH       EAX
    //         00508a8d     LEA        EDX,[ESI + 0xa]
    //         00508a90     PUSH       this
    //         00508a91     LEA        EAX,[ESI + 0x8]
    //         00508a94     PUSH       EDX
    //         00508a95     LEA        this,[ESI + 0x6]
    //         00508a98     PUSH       EAX
    //         00508a99     LEA        EDX=>param_1,[ESP + 0x84]
    //         00508aa0     PUSH       this
    //         00508aa1     MOV        this,dword ptr [ESP + param_1]
    //         00508aa8     LEA        EAX,[ESI + 0x2]
    //         00508aab     PUSH       EDX
    //         00508aac     PUSH       EAX
    //         00508aad     PUSH       s_%hd_%hd_%hd_%hd_%hd_%hd_%hd_%hd_               = "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f
    //         00508ab2     PUSH       this
    //         00508ab3     CALL       fscanf                                           undefined fscanf()
    //                              task.cpp:203 (7)
    //         00508ab8     MOV        DL,byte ptr [ESP + param_1]
    //                              task.cpp:204 (4)
    //         00508abf     MOV        AL,byte ptr [ESP + temp_search_flag]
    //                              task.cpp:205 (7)
    //         00508ac3     MOV        this,byte ptr [ESP + temp_owner_type]
    //         00508ac7     MOV        byte ptr [ESI + 0x4],DL
    //                              task.cpp:206 (10)
    //         00508aca     MOV        DL,byte ptr [ESP + temp_holding_attr]
    //         00508ad1     MOV        byte ptr [ESI + 0xc],AL
    //                              task.cpp:207 (10)
    //         00508ad4     MOV        AL,byte ptr [ESP + temp_state_building]
    //         00508adb     MOV        byte ptr [ESI + 0xd],this
    //                              task.cpp:208 (10)
    //         00508ade     MOV        this,byte ptr [ESP + move_sprite_id]
    //         00508ae5     MOV        byte ptr [ESI + 0x28],DL
    //                              task.cpp:209 (10)
    //         00508ae8     MOV        DL,byte ptr [ESP + work_sprite_id]
    //         00508aef     MOV        byte ptr [ESI + 0x10],AL
    //                              task.cpp:211 (40)
    //         00508af2     MOV        AX,word ptr [ESP + work_sprite2_id]
    //         00508afa     ADD        ESP,0x78
    //         00508afd     MOV        byte ptr [ESI + 0x11],this
    //         00508b00     MOV        this,dword ptr [ESP + param_2]
    //         00508b04     MOV        byte ptr [ESI + 0x12],DL
    //         00508b07     CMP        AX,0xffff
    //         00508b0b     JNZ        LAB_00508b11
    //         00508b0d     XOR        EAX,EAX
    //         00508b0f     JMP        LAB_00508b17
    //                               LAB_00508b11                                                 XREF[1]:     00508b0b(j)  
    //         00508b11     MOVSX      EAX,AX
    //         00508b14     MOV        EAX,dword ptr [this->task_type + EAX*0x4]
    //                               LAB_00508b17                                                 XREF[1]:     00508b0f(j)  
    //         00508b17     MOV        dword ptr [ESI + 0x34],EAX
    //                              task.cpp:212 (24)
    //         00508b1a     MOV        AX,word ptr [ESP + carry_sprite_id]
    //         00508b1f     CMP        AX,0xffff
    //         00508b23     JNZ        LAB_00508b29
    //         00508b25     XOR        EAX,EAX
    //         00508b27     JMP        LAB_00508b2f
    //                               LAB_00508b29                                                 XREF[1]:     00508b23(j)  
    //         00508b29     MOVSX      EDX,AX
    //         00508b2c     MOV        EAX,dword ptr [this->task_type + EDX*0x4]
    //                               LAB_00508b2f                                                 XREF[1]:     00508b27(j)  
    //         00508b2f     MOV        dword ptr [ESI + 0x38],EAX
    //                              task.cpp:213 (24)
    //         00508b32     MOV        AX,word ptr [ESP + work_sound_id]
    //         00508b37     CMP        AX,0xffff
    //         00508b3b     JNZ        LAB_00508b41
    //         00508b3d     XOR        EAX,EAX
    //         00508b3f     JMP        LAB_00508b47
    //                               LAB_00508b41                                                 XREF[1]:     00508b3b(j)  
    //         00508b41     MOVSX      EAX,AX
    //         00508b44     MOV        EAX,dword ptr [this->task_type + EAX*0x4]
    //                               LAB_00508b47                                                 XREF[1]:     00508b3f(j)  
    //         00508b47     MOV        dword ptr [ESI + 0x3c],EAX
    //                              task.cpp:214 (21)
    //         00508b4a     MOV        AX,word ptr [ESP + work_sound2_id]
    //         00508b4f     CMP        AX,0xffff
    //         00508b53     JNZ        LAB_00508b59
    //         00508b55     XOR        EAX,EAX
    //         00508b57     JMP        LAB_00508b5f
    //                               LAB_00508b59                                                 XREF[1]:     00508b53(j)  
    //         00508b59     MOVSX      EDX,AX
    //         00508b5c     MOV        EAX,dword ptr [this->task_type + EDX*0x4]
    //                               LAB_00508b5f                                                 XREF[1]:     00508b57(j)  
    //                              task.cpp:216 (31)
    //         00508b5f     MOV        this,dword ptr [ESP + param_3]
    //         00508b63     MOV        dword ptr [ESI + 0x40],EAX
    //         00508b66     MOV        AX,word ptr [ESP + local_4]
    //         00508b6b     CMP        AX,0xffff
    //         00508b6f     JNZ        LAB_00508b75
    //         00508b71     XOR        EAX,EAX
    //         00508b73     JMP        LAB_00508b7b
    //                               LAB_00508b75                                                 XREF[1]:     00508b6f(j)  
    //         00508b75     MOVSX      EAX,AX
    //         00508b78     MOV        EAX,dword ptr [this->task_type + EAX*0x4]
    //                               LAB_00508b7b                                                 XREF[1]:     00508b73(j)  
    //         00508b7b     MOV        dword ptr [ESI + 0x44],EAX
    //                              task.cpp:217 (16)
    //         00508b7e     MOV        AX,word ptr [ESP + local_2]
    //         00508b83     CMP        AX,0xffff
    //         00508b87     JNZ        LAB_00508b95
    //         00508b89     XOR        EAX,EAX
    //         00508b8b     MOV        dword ptr [ESI + 0x48],EAX
    //                              task.cpp:218 (7)
    //         00508b8e     POP        ESI
    //         00508b8f     ADD        ESP,0x18
    //         00508b92     RET        0xc
    //                               LAB_00508b95                                                 XREF[1]:     00508b87(j)  
    //                              task.cpp:217 (9)
    //         00508b95     MOVSX      EDX,AX
    //         00508b98     MOV        EAX,dword ptr [this->task_type + EDX*0x4]
    //         00508b9b     MOV        dword ptr [ESI + 0x48],EAX
    //                              task.cpp:218 (7)
    //         00508b9e     POP        ESI
    //         00508b9f     ADD        ESP,0x18
    //         00508ba2     RET        0xc
    //         00508ba5     ??         90h
    //         00508ba6     NOP
    //         00508ba7     NOP
    //         00508ba8     NOP
    //         00508ba9     NOP
    //         00508baa     NOP
    //         00508bab     NOP
    //         00508bac     NOP
    //         00508bad     NOP
    //         00508bae     NOP
    //         00508baf     NOP
    return;
}

void RGE_Task::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Task * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Task *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[19]:    00508bb3(R), 00508d19(W), 00508d23(W), 00508d27(*), 
    //                                                                                     00508d3e(W), 00508d48(W), 00508d4c(*), 00508d63(W), 
    //                                                                                     00508d6d(W), 00508d71(*), 00508d88(W), 00508d92(W), 
    //                                                                                     00508d96(*), 00508dad(W), 00508db7(W), 00508dbb(*), 
    //                                                                                     00508dd2(W), 00508ddc(W), 00508de0(*)  
    //                               ?save@RGE_Task@@QAEXH@Z                                      XREF[1]:     save:0050903a(c)  
    //                               RGE_Task::save
    //                              task.cpp:223 (3)
    //         00508bb0     PUSH       EBX
    //         00508bb1     PUSH       ESI
    //         00508bb2     PUSH       EDI
    //                              task.cpp:226 (18)
    //         00508bb3     MOV        EDI,dword ptr [ESP + param_1]
    //         00508bb7     MOV        ESI,this
    //         00508bb9     PUSH       0x2
    //         00508bbb     PUSH       ESI
    //         00508bbc     PUSH       EDI
    //         00508bbd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508bc2     ADD        ESP,0xc
    //                              task.cpp:227 (15)
    //         00508bc5     LEA        EAX,[ESI + 0x2]
    //         00508bc8     PUSH       0x2
    //         00508bca     PUSH       EAX
    //         00508bcb     PUSH       EDI
    //         00508bcc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508bd1     ADD        ESP,0xc
    //                              task.cpp:228 (15)
    //         00508bd4     LEA        this,[ESI + 0x4]
    //         00508bd7     PUSH       0x1
    //         00508bd9     PUSH       this
    //         00508bda     PUSH       EDI
    //         00508bdb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508be0     ADD        ESP,0xc
    //                              task.cpp:229 (15)
    //         00508be3     LEA        EDX,[ESI + 0x6]
    //         00508be6     PUSH       0x2
    //         00508be8     PUSH       EDX
    //         00508be9     PUSH       EDI
    //         00508bea     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508bef     ADD        ESP,0xc
    //                              task.cpp:230 (15)
    //         00508bf2     LEA        EAX,[ESI + 0x8]
    //         00508bf5     PUSH       0x2
    //         00508bf7     PUSH       EAX
    //         00508bf8     PUSH       EDI
    //         00508bf9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508bfe     ADD        ESP,0xc
    //                              task.cpp:231 (15)
    //         00508c01     LEA        this,[ESI + 0xa]
    //         00508c04     PUSH       0x2
    //         00508c06     PUSH       this
    //         00508c07     PUSH       EDI
    //         00508c08     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c0d     ADD        ESP,0xc
    //                              task.cpp:232 (15)
    //         00508c10     LEA        EDX,[ESI + 0xe]
    //         00508c13     PUSH       0x2
    //         00508c15     PUSH       EDX
    //         00508c16     PUSH       EDI
    //         00508c17     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c1c     ADD        ESP,0xc
    //                              task.cpp:233 (15)
    //         00508c1f     LEA        EAX,[ESI + 0x14]
    //         00508c22     PUSH       0x2
    //         00508c24     PUSH       EAX
    //         00508c25     PUSH       EDI
    //         00508c26     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c2b     ADD        ESP,0xc
    //                              task.cpp:234 (15)
    //         00508c2e     LEA        this,[ESI + 0x16]
    //         00508c31     PUSH       0x2
    //         00508c33     PUSH       this
    //         00508c34     PUSH       EDI
    //         00508c35     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c3a     ADD        ESP,0xc
    //                              task.cpp:235 (15)
    //         00508c3d     LEA        EDX,[ESI + 0x18]
    //         00508c40     PUSH       0x2
    //         00508c42     PUSH       EDX
    //         00508c43     PUSH       EDI
    //         00508c44     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c49     ADD        ESP,0xc
    //                              task.cpp:236 (15)
    //         00508c4c     LEA        EAX,[ESI + 0x1a]
    //         00508c4f     PUSH       0x2
    //         00508c51     PUSH       EAX
    //         00508c52     PUSH       EDI
    //         00508c53     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c58     ADD        ESP,0xc
    //                              task.cpp:237 (15)
    //         00508c5b     LEA        this,[ESI + 0x1c]
    //         00508c5e     PUSH       0x4
    //         00508c60     PUSH       this
    //         00508c61     PUSH       EDI
    //         00508c62     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c67     ADD        ESP,0xc
    //                              task.cpp:238 (15)
    //         00508c6a     LEA        EDX,[ESI + 0x20]
    //         00508c6d     PUSH       0x4
    //         00508c6f     PUSH       EDX
    //         00508c70     PUSH       EDI
    //         00508c71     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c76     ADD        ESP,0xc
    //                              task.cpp:239 (15)
    //         00508c79     LEA        EAX,[ESI + 0x24]
    //         00508c7c     PUSH       0x4
    //         00508c7e     PUSH       EAX
    //         00508c7f     PUSH       EDI
    //         00508c80     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c85     ADD        ESP,0xc
    //                              task.cpp:240 (15)
    //         00508c88     LEA        this,[ESI + 0x28]
    //         00508c8b     PUSH       0x1
    //         00508c8d     PUSH       this
    //         00508c8e     PUSH       EDI
    //         00508c8f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508c94     ADD        ESP,0xc
    //                              task.cpp:241 (15)
    //         00508c97     LEA        EDX,[ESI + 0x2c]
    //         00508c9a     PUSH       0x4
    //         00508c9c     PUSH       EDX
    //         00508c9d     PUSH       EDI
    //         00508c9e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508ca3     ADD        ESP,0xc
    //                              task.cpp:242 (15)
    //         00508ca6     LEA        EAX,[ESI + 0xc]
    //         00508ca9     PUSH       0x1
    //         00508cab     PUSH       EAX
    //         00508cac     PUSH       EDI
    //         00508cad     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cb2     ADD        ESP,0xc
    //                              task.cpp:243 (15)
    //         00508cb5     LEA        this,[ESI + 0xd]
    //         00508cb8     PUSH       0x1
    //         00508cba     PUSH       this
    //         00508cbb     PUSH       EDI
    //         00508cbc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cc1     ADD        ESP,0xc
    //                              task.cpp:244 (15)
    //         00508cc4     LEA        EDX,[ESI + 0x30]
    //         00508cc7     PUSH       0x2
    //         00508cc9     PUSH       EDX
    //         00508cca     PUSH       EDI
    //         00508ccb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cd0     ADD        ESP,0xc
    //                              task.cpp:245 (15)
    //         00508cd3     LEA        EAX,[ESI + 0x32]
    //         00508cd6     PUSH       0x2
    //         00508cd8     PUSH       EAX
    //         00508cd9     PUSH       EDI
    //         00508cda     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cdf     ADD        ESP,0xc
    //                              task.cpp:246 (15)
    //         00508ce2     LEA        this,[ESI + 0x10]
    //         00508ce5     PUSH       0x1
    //         00508ce7     PUSH       this
    //         00508ce8     PUSH       EDI
    //         00508ce9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cee     ADD        ESP,0xc
    //                              task.cpp:247 (15)
    //         00508cf1     LEA        EDX,[ESI + 0x11]
    //         00508cf4     PUSH       0x1
    //         00508cf6     PUSH       EDX
    //         00508cf7     PUSH       EDI
    //         00508cf8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508cfd     ADD        ESP,0xc
    //                              task.cpp:248 (12)
    //         00508d00     LEA        EAX,[ESI + 0x12]
    //         00508d03     PUSH       0x1
    //         00508d05     PUSH       EAX
    //         00508d06     PUSH       EDI
    //         00508d07     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:250 (27)
    //         00508d0c     MOV        EAX,dword ptr [ESI + 0x34]
    //         00508d0f     ADD        ESP,0xc
    //         00508d12     OR         EBX,0xffffffff
    //         00508d15     TEST       EAX,EAX
    //         00508d17     JNZ        LAB_00508d1f
    //         00508d19     MOV        dword ptr [ESP + param_1],EBX
    //         00508d1d     JMP        LAB_00508d27
    //                               LAB_00508d1f                                                 XREF[1]:     00508d17(j)  
    //         00508d1f     MOV        this,word ptr [EAX + 0x72]
    //         00508d23     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00508d27                                                 XREF[1]:     00508d1d(j)  
    //                              task.cpp:251 (13)
    //         00508d27     LEA        EDX=>param_1,[ESP + 0x10]
    //         00508d2b     PUSH       0x2
    //         00508d2d     PUSH       EDX
    //         00508d2e     PUSH       EDI
    //         00508d2f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:253 (24)
    //         00508d34     MOV        EAX,dword ptr [ESI + 0x38]
    //         00508d37     ADD        ESP,0xc
    //         00508d3a     TEST       EAX,EAX
    //         00508d3c     JNZ        LAB_00508d44
    //         00508d3e     MOV        dword ptr [ESP + param_1],EBX
    //         00508d42     JMP        LAB_00508d4c
    //                               LAB_00508d44                                                 XREF[1]:     00508d3c(j)  
    //         00508d44     MOV        AX,word ptr [EAX + 0x72]
    //         00508d48     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_00508d4c                                                 XREF[1]:     00508d42(j)  
    //                              task.cpp:254 (13)
    //         00508d4c     LEA        this=>param_1,[ESP + 0x10]
    //         00508d50     PUSH       0x2
    //         00508d52     PUSH       this
    //         00508d53     PUSH       EDI
    //         00508d54     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:256 (24)
    //         00508d59     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00508d5c     ADD        ESP,0xc
    //         00508d5f     TEST       EAX,EAX
    //         00508d61     JNZ        LAB_00508d69
    //         00508d63     MOV        dword ptr [ESP + param_1],EBX
    //         00508d67     JMP        LAB_00508d71
    //                               LAB_00508d69                                                 XREF[1]:     00508d61(j)  
    //         00508d69     MOV        DX,word ptr [EAX + 0x72]
    //         00508d6d     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00508d71                                                 XREF[1]:     00508d67(j)  
    //                              task.cpp:257 (13)
    //         00508d71     LEA        EAX=>param_1,[ESP + 0x10]
    //         00508d75     PUSH       0x2
    //         00508d77     PUSH       EAX
    //         00508d78     PUSH       EDI
    //         00508d79     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:259 (24)
    //         00508d7e     MOV        EAX,dword ptr [ESI + 0x40]
    //         00508d81     ADD        ESP,0xc
    //         00508d84     TEST       EAX,EAX
    //         00508d86     JNZ        LAB_00508d8e
    //         00508d88     MOV        dword ptr [ESP + param_1],EBX
    //         00508d8c     JMP        LAB_00508d96
    //                               LAB_00508d8e                                                 XREF[1]:     00508d86(j)  
    //         00508d8e     MOV        this,word ptr [EAX + 0x72]
    //         00508d92     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00508d96                                                 XREF[1]:     00508d8c(j)  
    //                              task.cpp:260 (13)
    //         00508d96     LEA        EDX=>param_1,[ESP + 0x10]
    //         00508d9a     PUSH       0x2
    //         00508d9c     PUSH       EDX
    //         00508d9d     PUSH       EDI
    //         00508d9e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:262 (24)
    //         00508da3     MOV        EAX,dword ptr [ESI + 0x44]
    //         00508da6     ADD        ESP,0xc
    //         00508da9     TEST       EAX,EAX
    //         00508dab     JNZ        LAB_00508db3
    //         00508dad     MOV        dword ptr [ESP + param_1],EBX
    //         00508db1     JMP        LAB_00508dbb
    //                               LAB_00508db3                                                 XREF[1]:     00508dab(j)  
    //         00508db3     MOV        AX,word ptr [EAX + 0xc]
    //         00508db7     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_00508dbb                                                 XREF[1]:     00508db1(j)  
    //                              task.cpp:263 (13)
    //         00508dbb     LEA        this=>param_1,[ESP + 0x10]
    //         00508dbf     PUSH       0x2
    //         00508dc1     PUSH       this
    //         00508dc2     PUSH       EDI
    //         00508dc3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              task.cpp:265 (24)
    //         00508dc8     MOV        ESI,dword ptr [ESI + 0x48]
    //         00508dcb     ADD        ESP,0xc
    //         00508dce     TEST       ESI,ESI
    //         00508dd0     JNZ        LAB_00508dd8
    //         00508dd2     MOV        dword ptr [ESP + param_1],EBX
    //         00508dd6     JMP        LAB_00508de0
    //                               LAB_00508dd8                                                 XREF[1]:     00508dd0(j)  
    //         00508dd8     MOV        DX,word ptr [ESI + 0xc]
    //         00508ddc     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00508de0                                                 XREF[1]:     00508dd6(j)  
    //                              task.cpp:266 (16)
    //         00508de0     LEA        EAX=>param_1,[ESP + 0x10]
    //         00508de4     PUSH       0x2
    //         00508de6     PUSH       EAX
    //         00508de7     PUSH       EDI
    //         00508de8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00508ded     ADD        ESP,0xc
    //                              task.cpp:267 (6)
    //         00508df0     POP        EDI
    //         00508df1     POP        ESI
    //         00508df2     POP        EBX
    //         00508df3     RET        0x4
    //         00508df6     ??         90h
    //         00508df7     NOP
    //         00508df8     NOP
    //         00508df9     NOP
    //         00508dfa     NOP
    //         00508dfb     NOP
    //         00508dfc     NOP
    //         00508dfd     NOP
    //         00508dfe     NOP
    //         00508dff     NOP
    return;
}

