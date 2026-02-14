// Auto-generated scaffold unit: bucket_050B.asm
#include "../include/common.h"

// Offset: 0x0050B490
void TRIBE_Dialog_List(TRIBE_Dialog_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Dialog_List::~TRIBE_Dialog_List(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Dialog_List(TRIBE_Dialog_List * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //                               ??1TRIBE_Dialog_List@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':0050b
    //                               TRIBE_Dialog_List::~TRIBE_Dialog_List
    //         0050b490     JMP        RGE_Dialog_List::~RGE_Dialog_List
}

// Offset: 0x0050B840
undefined TRIBE_Tech(TRIBE_Tech* this_, int param_2, TRIBE_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Tech::TRIBE_Tech(int,class TRIBE_World *)                                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Tech(TRIBE_Tech * this, int param_1, TRIB
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[19]:    0050b85b(R), 0050b8ea(R), 0050b92e(R), 0050b953(R), 
    //                                                                                     0050b978(R), 0050b99c(R), 0050b9bb(R), 0050b9da(R), 
    //                                                                                     0050b9f9(R), 0050ba18(R), 0050ba37(R), 0050ba56(R), 
    //                                                                                     0050ba75(R), 0050ba94(R), 0050bab3(R), 0050bad2(R), 
    //                                                                                     0050baf1(R), 0050bb03(R), 0050bb4a(R)  
    //              TRIBE_World *     Stack[0x8]:4   param_2                   XREF[1]:     0050b84c(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[23]:    0050b88d(W), 0050b895(R), 0050b89d(W), 0050b8a1(R), 
    //                                                                                     0050b8d3(R), 0050b917(R), 0050b93c(R), 0050b961(R), 
    //                                                                                     0050b98b(R), 0050b9aa(R), 0050b9c9(R), 0050b9e8(R), 
    //                                                                                     0050ba07(R), 0050ba26(R), 0050ba45(R), 0050ba64(R), 
    //                                                                                     0050ba83(R), 0050baa2(R), 0050bac1(R), 0050bae0(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[4]:     0050baff(*), 0050bb0f(R), 0050bb17(R), 0050bb35(R)  
    //              undefined2        Stack[-0x10]:2 local_10                  XREF[12]:    0050b8b4(W), 0050b8bc(R), 0050b8c4(W), 0050b8c8(R), 
    //                                                                                     0050b8e1(R), 0050b8f8(W), 0050b900(R), 0050b908(W), 
    //                                                                                     0050b90c(R), 0050b925(R), 0050b94a(R), 0050b96f(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[28]:    0050b846(W), 0050b849(R), 0050b854(R), 0050b867(R), 
    //                                                                                     0050b876(R), 0050b888(R), 0050b8a5(R), 0050b8da(R), 
    //                                                                                     0050b91e(R), 0050b943(R), 0050b968(R), 0050b992(R), 
    //                                                                                     0050b9b1(R), 0050b9d0(R), 0050b9ef(R), 0050ba0e(R), 
    //                                                                                     0050ba2d(R), 0050ba4c(R), 0050ba6b(R), 0050ba8a(R)  
    //                               ??0TRIBE_Tech@@QAE@HPAVTRIBE_World@@@Z                       XREF[1]:     world_init:0052e6fc(c)  
    //                               TRIBE_Tech::TRIBE_Tech
    //         0050b840     PUSH       EBP
    //         0050b841     MOV        EBP,ESP
    //         0050b843     SUB        ESP,0x10
    //         0050b846     MOV        dword ptr [EBP + local_14],this
    //         0050b849     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b84c     MOV        this,dword ptr [EBP + param_2]
    //         0050b84f     MOV        dword ptr [EAX + 0x8],this
    //         0050b852     PUSH       0x2
    //         0050b854     MOV        EDX,dword ptr [EBP + local_14]
    //         0050b857     ADD        EDX,0x4
    //         0050b85a     PUSH       EDX
    //         0050b85b     MOV        EAX,dword ptr [EBP + param_1]
    //         0050b85e     PUSH       EAX
    //         0050b85f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b864     ADD        ESP,0xc
    //         0050b867     MOV        this,dword ptr [EBP + local_14]
    //         0050b86a     MOVSX      EDX,word ptr [ECX + this->tech_tree_num]
    //         0050b86e     TEST       EDX,EDX
    //         0050b870     JLE        LAB_0050bb72
    //         0050b876     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b879     MOVSX      this,word ptr [EAX + 0x4]
    //         0050b87d     PUSH       this
    //         0050b87e     PUSH       0x3c
    //         0050b880     CALL       calloc                                           undefined calloc()
    //         0050b885     ADD        ESP,0x8
    //         0050b888     MOV        EDX,dword ptr [EBP + local_14]
    //         0050b88b     MOV        dword ptr [EDX],EAX
    //         0050b88d     MOV        word ptr [EBP + local_8],0x0
    //         0050b893     JMP        LAB_0050b8a1
    //                               LAB_0050b895                                                 XREF[1]:     0050bb6b(j)  
    //         0050b895     MOV        AX,word ptr [EBP + local_8]
    //         0050b899     ADD        AX,0x1
    //         0050b89d     MOV        word ptr [EBP + local_8],AX
    //                               LAB_0050b8a1                                                 XREF[1]:     0050b893(j)  
    //         0050b8a1     MOVSX      this,word ptr [EBP + local_8]
    //         0050b8a5     MOV        EDX,dword ptr [EBP + local_14]
    //         0050b8a8     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050b8ac     CMP        this,EAX
    //         0050b8ae     JGE        LAB_0050bb70
    //         0050b8b4     MOV        word ptr [EBP + local_10],0x0
    //         0050b8ba     JMP        LAB_0050b8c8
    //                               LAB_0050b8bc                                                 XREF[1]:     0050b8f6(j)  
    //         0050b8bc     MOV        this,word ptr [EBP + local_10]
    //         0050b8c0     ADD        this,0x1
    //         0050b8c4     MOV        word ptr [EBP + local_10],this
    //                               LAB_0050b8c8                                                 XREF[1]:     0050b8ba(j)  
    //         0050b8c8     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050b8cc     CMP        EDX,0x4
    //         0050b8cf     JGE        LAB_0050b8f8
    //         0050b8d1     PUSH       0x2
    //         0050b8d3     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050b8d7     IMUL       EAX,EAX,0x3c
    //         0050b8da     MOV        this,dword ptr [EBP + local_14]
    //         0050b8dd     MOV        EDX,dword ptr [this->tech_tree]
    //         0050b8df     ADD        EDX,EAX
    //         0050b8e1     MOVSX      EAX,word ptr [EBP + local_10]
    //         0050b8e5     LEA        this,[EDX + EAX*0x2 + 0x4]
    //         0050b8e9     PUSH       this
    //         0050b8ea     MOV        EDX,dword ptr [EBP + param_1]
    //         0050b8ed     PUSH       EDX
    //         0050b8ee     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b8f3     ADD        ESP,0xc
    //         0050b8f6     JMP        LAB_0050b8bc
    //                               LAB_0050b8f8                                                 XREF[1]:     0050b8cf(j)  
    //         0050b8f8     MOV        word ptr [EBP + local_10],0x0
    //         0050b8fe     JMP        LAB_0050b90c
    //                               LAB_0050b900                                                 XREF[1]:     0050b984(j)  
    //         0050b900     MOV        AX,word ptr [EBP + local_10]
    //         0050b904     ADD        AX,0x1
    //         0050b908     MOV        word ptr [EBP + local_10],AX
    //                               LAB_0050b90c                                                 XREF[1]:     0050b8fe(j)  
    //         0050b90c     MOVSX      this,word ptr [EBP + local_10]
    //         0050b910     CMP        this,0x3
    //         0050b913     JGE        LAB_0050b989
    //         0050b915     PUSH       0x2
    //         0050b917     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050b91b     IMUL       EDX,EDX,0x3c
    //         0050b91e     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b921     MOV        this,dword ptr [EAX]
    //         0050b923     ADD        this,EDX
    //         0050b925     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050b929     LEA        EAX,[this->tech_tree + EDX*0x2 + 0xe]
    //         0050b92d     PUSH       EAX
    //         0050b92e     MOV        this,dword ptr [EBP + param_1]
    //         0050b931     PUSH       this
    //         0050b932     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b937     ADD        ESP,0xc
    //         0050b93a     PUSH       0x2
    //         0050b93c     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050b940     IMUL       EDX,EDX,0x3c
    //         0050b943     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b946     MOV        this,dword ptr [EAX]
    //         0050b948     ADD        this,EDX
    //         0050b94a     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050b94e     LEA        EAX,[this->tech_tree + EDX*0x2 + 0x14]
    //         0050b952     PUSH       EAX
    //         0050b953     MOV        this,dword ptr [EBP + param_1]
    //         0050b956     PUSH       this
    //         0050b957     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b95c     ADD        ESP,0xc
    //         0050b95f     PUSH       0x1
    //         0050b961     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050b965     IMUL       EDX,EDX,0x3c
    //         0050b968     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b96b     MOV        this,dword ptr [EAX]
    //         0050b96d     ADD        this,EDX
    //         0050b96f     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050b973     LEA        EAX,[this->tech_tree + EDX*0x1 + 0x1a]
    //         0050b977     PUSH       EAX
    //         0050b978     MOV        this,dword ptr [EBP + param_1]
    //         0050b97b     PUSH       this
    //         0050b97c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b981     ADD        ESP,0xc
    //         0050b984     JMP        LAB_0050b900
    //                               LAB_0050b989                                                 XREF[1]:     0050b913(j)  
    //         0050b989     PUSH       0x2
    //         0050b98b     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050b98f     IMUL       EDX,EDX,0x3c
    //         0050b992     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b995     MOV        this,dword ptr [EAX]
    //         0050b997     LEA        EDX,[ECX + EDX*0x1 + this+0xc]
    //         0050b99b     PUSH       EDX
    //         0050b99c     MOV        EAX,dword ptr [EBP + param_1]
    //         0050b99f     PUSH       EAX
    //         0050b9a0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b9a5     ADD        ESP,0xc
    //         0050b9a8     PUSH       0x2
    //         0050b9aa     MOVSX      this,word ptr [EBP + local_8]
    //         0050b9ae     IMUL       this,this,0x3c
    //         0050b9b1     MOV        EDX,dword ptr [EBP + local_14]
    //         0050b9b4     MOV        EAX,dword ptr [EDX]
    //         0050b9b6     LEA        this,[EAX + this->tech_tree*0x1 + 0x28]
    //         0050b9ba     PUSH       this
    //         0050b9bb     MOV        EDX,dword ptr [EBP + param_1]
    //         0050b9be     PUSH       EDX
    //         0050b9bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b9c4     ADD        ESP,0xc
    //         0050b9c7     PUSH       0x2
    //         0050b9c9     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050b9cd     IMUL       EAX,EAX,0x3c
    //         0050b9d0     MOV        this,dword ptr [EBP + local_14]
    //         0050b9d3     MOV        EDX,dword ptr [this->tech_tree]
    //         0050b9d5     LEA        EAX,[EDX + EAX*0x1 + 0x2a]
    //         0050b9d9     PUSH       EAX
    //         0050b9da     MOV        this,dword ptr [EBP + param_1]
    //         0050b9dd     PUSH       this
    //         0050b9de     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050b9e3     ADD        ESP,0xc
    //         0050b9e6     PUSH       0x2
    //         0050b9e8     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050b9ec     IMUL       EDX,EDX,0x3c
    //         0050b9ef     MOV        EAX,dword ptr [EBP + local_14]
    //         0050b9f2     MOV        this,dword ptr [EAX]
    //         0050b9f4     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x2c]
    //         0050b9f8     PUSH       EDX
    //         0050b9f9     MOV        EAX,dword ptr [EBP + param_1]
    //         0050b9fc     PUSH       EAX
    //         0050b9fd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba02     ADD        ESP,0xc
    //         0050ba05     PUSH       0x2
    //         0050ba07     MOVSX      this,word ptr [EBP + local_8]
    //         0050ba0b     IMUL       this,this,0x3c
    //         0050ba0e     MOV        EDX,dword ptr [EBP + local_14]
    //         0050ba11     MOV        EAX,dword ptr [EDX]
    //         0050ba13     LEA        this,[EAX + this->tech_tree*0x1 + 0x1e]
    //         0050ba17     PUSH       this
    //         0050ba18     MOV        EDX,dword ptr [EBP + param_1]
    //         0050ba1b     PUSH       EDX
    //         0050ba1c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba21     ADD        ESP,0xc
    //         0050ba24     PUSH       0x2
    //         0050ba26     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050ba2a     IMUL       EAX,EAX,0x3c
    //         0050ba2d     MOV        this,dword ptr [EBP + local_14]
    //         0050ba30     MOV        EDX,dword ptr [this->tech_tree]
    //         0050ba32     LEA        EAX,[EDX + EAX*0x1 + 0x20]
    //         0050ba36     PUSH       EAX
    //         0050ba37     MOV        this,dword ptr [EBP + param_1]
    //         0050ba3a     PUSH       this
    //         0050ba3b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba40     ADD        ESP,0xc
    //         0050ba43     PUSH       0x2
    //         0050ba45     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050ba49     IMUL       EDX,EDX,0x3c
    //         0050ba4c     MOV        EAX,dword ptr [EBP + local_14]
    //         0050ba4f     MOV        this,dword ptr [EAX]
    //         0050ba51     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x22]
    //         0050ba55     PUSH       EDX
    //         0050ba56     MOV        EAX,dword ptr [EBP + param_1]
    //         0050ba59     PUSH       EAX
    //         0050ba5a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba5f     ADD        ESP,0xc
    //         0050ba62     PUSH       0x2
    //         0050ba64     MOVSX      this,word ptr [EBP + local_8]
    //         0050ba68     IMUL       this,this,0x3c
    //         0050ba6b     MOV        EDX,dword ptr [EBP + local_14]
    //         0050ba6e     MOV        EAX,dword ptr [EDX]
    //         0050ba70     LEA        this,[EAX + this->tech_tree*0x1 + 0x24]
    //         0050ba74     PUSH       this
    //         0050ba75     MOV        EDX,dword ptr [EBP + param_1]
    //         0050ba78     PUSH       EDX
    //         0050ba79     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba7e     ADD        ESP,0xc
    //         0050ba81     PUSH       0x1
    //         0050ba83     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050ba87     IMUL       EAX,EAX,0x3c
    //         0050ba8a     MOV        this,dword ptr [EBP + local_14]
    //         0050ba8d     MOV        EDX,dword ptr [this->tech_tree]
    //         0050ba8f     LEA        EAX,[EDX + EAX*0x1 + 0x26]
    //         0050ba93     PUSH       EAX
    //         0050ba94     MOV        this,dword ptr [EBP + param_1]
    //         0050ba97     PUSH       this
    //         0050ba98     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ba9d     ADD        ESP,0xc
    //         0050baa0     PUSH       0x4
    //         0050baa2     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050baa6     IMUL       EDX,EDX,0x3c
    //         0050baa9     MOV        EAX,dword ptr [EBP + local_14]
    //         0050baac     MOV        this,dword ptr [EAX]
    //         0050baae     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x30]
    //         0050bab2     PUSH       EDX
    //         0050bab3     MOV        EAX,dword ptr [EBP + param_1]
    //         0050bab6     PUSH       EAX
    //         0050bab7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050babc     ADD        ESP,0xc
    //         0050babf     PUSH       0x4
    //         0050bac1     MOVSX      this,word ptr [EBP + local_8]
    //         0050bac5     IMUL       this,this,0x3c
    //         0050bac8     MOV        EDX,dword ptr [EBP + local_14]
    //         0050bacb     MOV        EAX,dword ptr [EDX]
    //         0050bacd     LEA        this,[EAX + this->tech_tree*0x1 + 0x34]
    //         0050bad1     PUSH       this
    //         0050bad2     MOV        EDX,dword ptr [EBP + param_1]
    //         0050bad5     PUSH       EDX
    //         0050bad6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050badb     ADD        ESP,0xc
    //         0050bade     PUSH       0x4
    //         0050bae0     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050bae4     IMUL       EAX,EAX,0x3c
    //         0050bae7     MOV        this,dword ptr [EBP + local_14]
    //         0050baea     MOV        EDX,dword ptr [this->tech_tree]
    //         0050baec     LEA        EAX,[EDX + EAX*0x1 + 0x38]
    //         0050baf0     PUSH       EAX
    //         0050baf1     MOV        this,dword ptr [EBP + param_1]
    //         0050baf4     PUSH       this
    //         0050baf5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050bafa     ADD        ESP,0xc
    //         0050bafd     PUSH       0x2
    //         0050baff     LEA        EDX=>local_c,[EBP + -0x8]
    //         0050bb02     PUSH       EDX
    //         0050bb03     MOV        EAX,dword ptr [EBP + param_1]
    //         0050bb06     PUSH       EAX
    //         0050bb07     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050bb0c     ADD        ESP,0xc
    //         0050bb0f     MOVSX      this,word ptr [EBP + local_c]
    //         0050bb13     TEST       this,this
    //         0050bb15     JLE        LAB_0050bb58
    //         0050bb17     MOVSX      EDX,word ptr [EBP + local_c]
    //         0050bb1b     PUSH       EDX
    //         0050bb1c     PUSH       0x1
    //         0050bb1e     CALL       calloc                                           undefined calloc()
    //         0050bb23     ADD        ESP,0x8
    //         0050bb26     MOVSX      this,word ptr [EBP + local_8]
    //         0050bb2a     IMUL       this,this,0x3c
    //         0050bb2d     MOV        EDX,dword ptr [EBP + local_14]
    //         0050bb30     MOV        EDX,dword ptr [EDX]
    //         0050bb32     MOV        dword ptr [EDX + this->tech_tree*0x1],EAX
    //         0050bb35     MOVSX      EAX,word ptr [EBP + local_c]
    //         0050bb39     PUSH       EAX
    //         0050bb3a     MOVSX      this,word ptr [EBP + local_8]
    //         0050bb3e     IMUL       this,this,0x3c
    //         0050bb41     MOV        EDX,dword ptr [EBP + local_14]
    //         0050bb44     MOV        EAX,dword ptr [EDX]
    //         0050bb46     MOV        this,dword ptr [EAX + this->tech_tree*0x1]
    //         0050bb49     PUSH       this
    //         0050bb4a     MOV        EDX,dword ptr [EBP + param_1]
    //         0050bb4d     PUSH       EDX
    //         0050bb4e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050bb53     ADD        ESP,0xc
    //         0050bb56     JMP        LAB_0050bb6b
    //                               LAB_0050bb58                                                 XREF[1]:     0050bb15(j)  
    //         0050bb58     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050bb5c     IMUL       EAX,EAX,0x3c
    //         0050bb5f     MOV        this,dword ptr [EBP + local_14]
    //         0050bb62     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bb64     MOV        dword ptr [EDX + EAX*0x1],0x0
    //                               LAB_0050bb6b                                                 XREF[1]:     0050bb56(j)  
    //         0050bb6b     JMP        LAB_0050b895
    //                               LAB_0050bb70                                                 XREF[1]:     0050b8ae(j)  
    //         0050bb70     JMP        LAB_0050bb7b
    //                               LAB_0050bb72                                                 XREF[1]:     0050b870(j)  
    //         0050bb72     MOV        EAX,dword ptr [EBP + local_14]
    //         0050bb75     MOV        dword ptr [EAX],0x0
    //                               LAB_0050bb7b                                                 XREF[1]:     0050bb70(j)  
    //         0050bb7b     MOV        EAX,dword ptr [EBP + local_14]
    //         0050bb7e     MOV        ESP,EBP
    //         0050bb80     POP        EBP
    //         0050bb81     RET        0x8
}

// Offset: 0x0050BB84
undefined TRIBE_Tech(TRIBE_Tech* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Tech::TRIBE_Tech(char *)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Tech(TRIBE_Tech * this, char * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0050bba4(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050bd18(W), 0050bd30(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[2]:     0050bbbd(*), 0050bc2c(R)  
    //              undefined         Stack[-0x10]:1 local_10                  XREF[2]:     0050be0b(*), 0050be7b(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[6]:     0050bd1b(W), 0050bd24(R), 0050bd2a(W), 0050bd2d(R), 
    //                                                                                     0050bd35(R), 0050bd42(R)  
    //              undefined         Stack[-0x18]:1 local_18                  XREF[2]:     0050bc67(*), 0050bd05(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[9]:     0050bbb0(W), 0050bbb3(R), 0050bbd0(R), 0050bc44(R), 
    //                                                                                     0050bce7(R), 0050bdd4(R), 0050be54(R), 0050beff(R), 
    //                                                                                     0050bf10(R)  
    //              undefined2        Stack[-0x20]:2 local_20                  XREF[4]:     0050bc14(W), 0050bc1c(R), 0050bc24(W), 0050bc28(R)  
    //              undefined         Stack[-0x84]:1 local_84                  XREF[3]:     0050bcde(*), 0050bd0c(*), 0050bd65(*)  
    //              undefined2        Stack[-0x88]:2 local_88                  XREF[12]:    0050bd86(W), 0050bd91(R), 0050bd9c(W), 0050bda3(R), 
    //                                                                                     0050bdc3(R), 0050bde2(W), 0050bded(R), 0050bdf8(W), 
    //                                                                                     0050bdff(R), 0050be23(R), 0050be43(R), 0050be74(R)  
    //              undefined2        Stack[-0x8c]:2 local_8c                  XREF[19]:    0050bc38(*), 0050bc50(R), 0050bc6b(R), 0050bc82(R), 
    //                                                                                     0050bc99(R), 0050bcb0(R), 0050bcc7(R), 0050bcf3(R), 
    //                                                                                     0050bd4c(R), 0050bd69(R), 0050bdaf(R), 0050be0f(R), 
    //                                                                                     0050be2f(R), 0050be60(R), 0050be87(R), 0050be9e(R), 
    //                                                                                     0050beb5(R), 0050becc(R), 0050bee3(R)  
    //              undefined4        Stack[-0x90]:4 local_90                  XREF[25]:    0050bb8d(W), 0050bb93(R), 0050bbc1(R), 0050bbe5(R), 
    //                                                                                     0050bbf7(R), 0050bc0c(R), 0050bc5a(R), 0050bc75(R), 
    //                                                                                     0050bc8c(R), 0050bca3(R), 0050bcba(R), 0050bcd1(R), 
    //                                                                                     0050bcfd(R), 0050bd56(R), 0050bd73(R), 0050bdb9(R), 
    //                                                                                     0050be19(R), 0050be39(R), 0050be6a(R), 0050be91(R)  
    //                               ??0TRIBE_Tech@@QAE@PAD@Z                                     XREF[1]:     data_load_world:0052e3a9(c)  
    //                               TRIBE_Tech::TRIBE_Tech
    //         0050bb84     PUSH       EBP
    //         0050bb85     MOV        EBP,ESP
    //         0050bb87     SUB        ESP,0x8c
    //         0050bb8d     MOV        dword ptr [EBP + local_90],this
    //         0050bb93     MOV        EAX,dword ptr [EBP + local_90]
    //         0050bb99     MOV        dword ptr [EAX],0x0
    //         0050bb9f     PUSH       DAT_00588f74                                     = 72h    r
    //         0050bba4     MOV        this,dword ptr [EBP + param_1]
    //         0050bba7     PUSH       this
    //         0050bba8     CALL       fopen                                            undefined fopen()
    //         0050bbad     ADD        ESP,0x8
    //         0050bbb0     MOV        dword ptr [EBP + local_1c],EAX
    //         0050bbb3     CMP        dword ptr [EBP + local_1c],0x0
    //         0050bbb7     JZ         LAB_0050bf1c
    //         0050bbbd     LEA        EDX=>local_c,[EBP + -0x8]
    //         0050bbc0     PUSH       EDX
    //         0050bbc1     MOV        EAX,dword ptr [EBP + local_90]
    //         0050bbc7     ADD        EAX,0x4
    //         0050bbca     PUSH       EAX
    //         0050bbcb     PUSH       s_%d_%d_00588f78                                 = "%d %d"
    //         0050bbd0     MOV        this,dword ptr [EBP + local_1c]
    //         0050bbd3     PUSH       this
    //         0050bbd4     CALL       fscanf                                           undefined fscanf()
    //         0050bbd9     ADD        ESP,0x10
    //         0050bbdc     CMP        EAX,-0x1
    //         0050bbdf     JZ         LAB_0050bf10
    //         0050bbe5     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bbeb     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050bbef     TEST       EAX,EAX
    //         0050bbf1     JLE        LAB_0050bf10
    //         0050bbf7     MOV        this,dword ptr [EBP + local_90]
    //         0050bbfd     MOVSX      EDX,word ptr [ECX + this->tech_tree_num]
    //         0050bc01     PUSH       EDX
    //         0050bc02     PUSH       0x3c
    //         0050bc04     CALL       calloc                                           undefined calloc()
    //         0050bc09     ADD        ESP,0x8
    //         0050bc0c     MOV        this,dword ptr [EBP + local_90]
    //         0050bc12     MOV        dword ptr [this->tech_tree],EAX
    //         0050bc14     MOV        word ptr [EBP + local_20],0x0
    //         0050bc1a     JMP        LAB_0050bc28
    //                               LAB_0050bc1c                                                 XREF[1]:     0050bf0b(j)  
    //         0050bc1c     MOV        DX,word ptr [EBP + local_20]
    //         0050bc20     ADD        DX,0x1
    //         0050bc24     MOV        word ptr [EBP + local_20],DX
    //                               LAB_0050bc28                                                 XREF[1]:     0050bc1a(j)  
    //         0050bc28     MOVSX      EAX,word ptr [EBP + local_20]
    //         0050bc2c     MOVSX      this,word ptr [EBP + local_c]
    //         0050bc30     CMP        EAX,this
    //         0050bc32     JGE        LAB_0050bf10
    //         0050bc38     LEA        EDX=>local_8c,[EBP + 0xffffff78]
    //         0050bc3e     PUSH       EDX
    //         0050bc3f     PUSH       DAT_00588f80                                     = 25h    %
    //         0050bc44     MOV        EAX,dword ptr [EBP + local_1c]
    //         0050bc47     PUSH       EAX
    //         0050bc48     CALL       fscanf                                           undefined fscanf()
    //         0050bc4d     ADD        ESP,0xc
    //         0050bc50     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bc57     IMUL       this,this,0x3c
    //         0050bc5a     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bc60     MOV        EAX,dword ptr [EDX]
    //         0050bc62     LEA        this,[EAX + this->tech_tree*0x1 + 0x28]
    //         0050bc66     PUSH       this
    //         0050bc67     LEA        EDX=>local_18,[EBP + -0x14]
    //         0050bc6a     PUSH       EDX
    //         0050bc6b     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050bc72     IMUL       EAX,EAX,0x3c
    //         0050bc75     MOV        this,dword ptr [EBP + local_90]
    //         0050bc7b     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bc7d     LEA        EAX,[EDX + EAX*0x1 + 0x24]
    //         0050bc81     PUSH       EAX
    //         0050bc82     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bc89     IMUL       this,this,0x3c
    //         0050bc8c     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bc92     MOV        EAX,dword ptr [EDX]
    //         0050bc94     LEA        this,[EAX + this->tech_tree*0x1 + 0x22]
    //         0050bc98     PUSH       this
    //         0050bc99     MOVSX      EDX,word ptr [EBP + local_8c]
    //         0050bca0     IMUL       EDX,EDX,0x3c
    //         0050bca3     MOV        EAX,dword ptr [EBP + local_90]
    //         0050bca9     MOV        this,dword ptr [EAX]
    //         0050bcab     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x20]
    //         0050bcaf     PUSH       EDX
    //         0050bcb0     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050bcb7     IMUL       EAX,EAX,0x3c
    //         0050bcba     MOV        this,dword ptr [EBP + local_90]
    //         0050bcc0     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bcc2     LEA        EAX,[EDX + EAX*0x1 + 0x1e]
    //         0050bcc6     PUSH       EAX
    //         0050bcc7     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bcce     IMUL       this,this,0x3c
    //         0050bcd1     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bcd7     MOV        EAX,dword ptr [EDX]
    //         0050bcd9     LEA        this,[EAX + this->tech_tree*0x1 + 0xc]
    //         0050bcdd     PUSH       this
    //         0050bcde     LEA        EDX=>local_84,[EBP + -0x80]
    //         0050bce1     PUSH       EDX
    //         0050bce2     PUSH       s_%s_%hd_%hd_%hd_%hd_%hd_%hd_%hd_00588f84        = "%s %hd %hd %hd %hd %hd %hd %hd"
    //         0050bce7     MOV        EAX,dword ptr [EBP + local_1c]
    //         0050bcea     PUSH       EAX
    //         0050bceb     CALL       fscanf                                           undefined fscanf()
    //         0050bcf0     ADD        ESP,0x28
    //         0050bcf3     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bcfa     IMUL       this,this,0x3c
    //         0050bcfd     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bd03     MOV        EAX,dword ptr [EDX]
    //         0050bd05     MOV        DL,byte ptr [EBP + local_18]
    //         0050bd08     MOV        byte ptr [EAX + this->tech_tree*0x1 + 0x26],DL
    //         0050bd0c     LEA        EAX=>local_84,[EBP + -0x80]
    //         0050bd0f     PUSH       EAX
    //         0050bd10     CALL       strlen                                           undefined strlen()
    //         0050bd15     ADD        ESP,0x4
    //         0050bd18     MOV        dword ptr [EBP + local_8],EAX
    //         0050bd1b     MOV        dword ptr [EBP + local_14],0x0
    //         0050bd22     JMP        LAB_0050bd2d
    //                               LAB_0050bd24                                                 XREF[1]:     0050bd4a(j)  
    //         0050bd24     MOV        this,dword ptr [EBP + local_14]
    //         0050bd27     ADD        this,0x1
    //         0050bd2a     MOV        dword ptr [EBP + local_14],this
    //                               LAB_0050bd2d                                                 XREF[1]:     0050bd22(j)  
    //         0050bd2d     MOV        EDX,dword ptr [EBP + local_14]
    //         0050bd30     CMP        EDX,dword ptr [EBP + local_8]
    //         0050bd33     JGE        LAB_0050bd4c
    //         0050bd35     MOV        EAX,dword ptr [EBP + local_14]
    //         0050bd38     MOVSX      this,byte ptr [EBP + EAX*0x1 + -0x80]
    //         0050bd3d     CMP        this,0x5f
    //         0050bd40     JNZ        LAB_0050bd4a
    //         0050bd42     MOV        EDX,dword ptr [EBP + local_14]
    //         0050bd45     MOV        byte ptr [EBP + EDX*0x1 + -0x80],0x20
    //                               LAB_0050bd4a                                                 XREF[1]:     0050bd40(j)  
    //         0050bd4a     JMP        LAB_0050bd24
    //                               LAB_0050bd4c                                                 XREF[1]:     0050bd33(j)  
    //         0050bd4c     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050bd53     IMUL       EAX,EAX,0x3c
    //         0050bd56     MOV        this,dword ptr [EBP + local_90]
    //         0050bd5c     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bd5e     MOV        dword ptr [EDX + EAX*0x1],0x0
    //         0050bd65     LEA        EAX=>local_84,[EBP + -0x80]
    //         0050bd68     PUSH       EAX
    //         0050bd69     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bd70     IMUL       this,this,0x3c
    //         0050bd73     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bd79     MOV        EAX,dword ptr [EDX]
    //         0050bd7b     ADD        EAX,this
    //         0050bd7d     PUSH       EAX
    //         0050bd7e     CALL       getstring                                        void getstring(char * * param_1, char * param
    //         0050bd83     ADD        ESP,0x8
    //         0050bd86     MOV        word ptr [EBP + local_88],0x0
    //         0050bd8f     JMP        LAB_0050bda3
    //                               LAB_0050bd91                                                 XREF[1]:     0050bde0(j)  
    //         0050bd91     MOV        this,word ptr [EBP + local_88]
    //         0050bd98     ADD        this,0x1
    //         0050bd9c     MOV        word ptr [EBP + local_88],this
    //                               LAB_0050bda3                                                 XREF[1]:     0050bd8f(j)  
    //         0050bda3     MOVSX      EDX,word ptr [EBP + local_88]
    //         0050bdaa     CMP        EDX,0x4
    //         0050bdad     JGE        LAB_0050bde2
    //         0050bdaf     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050bdb6     IMUL       EAX,EAX,0x3c
    //         0050bdb9     MOV        this,dword ptr [EBP + local_90]
    //         0050bdbf     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bdc1     ADD        EDX,EAX
    //         0050bdc3     MOVSX      EAX,word ptr [EBP + local_88]
    //         0050bdca     LEA        this,[EDX + EAX*0x2 + 0x4]
    //         0050bdce     PUSH       this
    //         0050bdcf     PUSH       PTR_aiPathSystem.MGP_costValue[29][208]+1_0058   = 00646825
    //         0050bdd4     MOV        EDX,dword ptr [EBP + local_1c]
    //         0050bdd7     PUSH       EDX
    //         0050bdd8     CALL       fscanf                                           undefined fscanf()
    //         0050bddd     ADD        ESP,0xc
    //         0050bde0     JMP        LAB_0050bd91
    //                               LAB_0050bde2                                                 XREF[1]:     0050bdad(j)  
    //         0050bde2     MOV        word ptr [EBP + local_88],0x0
    //         0050bdeb     JMP        LAB_0050bdff
    //                               LAB_0050bded                                                 XREF[1]:     0050be82(j)  
    //         0050bded     MOV        AX,word ptr [EBP + local_88]
    //         0050bdf4     ADD        AX,0x1
    //         0050bdf8     MOV        word ptr [EBP + local_88],AX
    //                               LAB_0050bdff                                                 XREF[1]:     0050bdeb(j)  
    //         0050bdff     MOVSX      this,word ptr [EBP + local_88]
    //         0050be06     CMP        this,0x3
    //         0050be09     JGE        LAB_0050be87
    //         0050be0b     LEA        EDX=>local_10,[EBP + -0xc]
    //         0050be0e     PUSH       EDX
    //         0050be0f     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050be16     IMUL       EAX,EAX,0x3c
    //         0050be19     MOV        this,dword ptr [EBP + local_90]
    //         0050be1f     MOV        EDX,dword ptr [this->tech_tree]
    //         0050be21     ADD        EDX,EAX
    //         0050be23     MOVSX      EAX,word ptr [EBP + local_88]
    //         0050be2a     LEA        this,[EDX + EAX*0x2 + 0x14]
    //         0050be2e     PUSH       this
    //         0050be2f     MOVSX      EDX,word ptr [EBP + local_8c]
    //         0050be36     IMUL       EDX,EDX,0x3c
    //         0050be39     MOV        EAX,dword ptr [EBP + local_90]
    //         0050be3f     MOV        this,dword ptr [EAX]
    //         0050be41     ADD        this,EDX
    //         0050be43     MOVSX      EDX,word ptr [EBP + local_88]
    //         0050be4a     LEA        EAX,[this->tech_tree + EDX*0x2 + 0xe]
    //         0050be4e     PUSH       EAX
    //         0050be4f     PUSH       s_%hd_%hd_%hd_00588fa8                           = "%hd %hd %hd"
    //         0050be54     MOV        this,dword ptr [EBP + local_1c]
    //         0050be57     PUSH       this
    //         0050be58     CALL       fscanf                                           undefined fscanf()
    //         0050be5d     ADD        ESP,0x14
    //         0050be60     MOVSX      EDX,word ptr [EBP + local_8c]
    //         0050be67     IMUL       EDX,EDX,0x3c
    //         0050be6a     MOV        EAX,dword ptr [EBP + local_90]
    //         0050be70     MOV        this,dword ptr [EAX]
    //         0050be72     ADD        this,EDX
    //         0050be74     MOVSX      EDX,word ptr [EBP + local_88]
    //         0050be7b     MOV        AL,byte ptr [EBP + local_10]
    //         0050be7e     MOV        byte ptr [this->tech_tree + EDX*0x1 + 0x1a],AL
    //         0050be82     JMP        LAB_0050bded
    //                               LAB_0050be87                                                 XREF[1]:     0050be09(j)  
    //         0050be87     MOVSX      this,word ptr [EBP + local_8c]
    //         0050be8e     IMUL       this,this,0x3c
    //         0050be91     MOV        EDX,dword ptr [EBP + local_90]
    //         0050be97     MOV        EAX,dword ptr [EDX]
    //         0050be99     LEA        this,[EAX + this->tech_tree*0x1 + 0x38]
    //         0050be9d     PUSH       this
    //         0050be9e     MOVSX      EDX,word ptr [EBP + local_8c]
    //         0050bea5     IMUL       EDX,EDX,0x3c
    //         0050bea8     MOV        EAX,dword ptr [EBP + local_90]
    //         0050beae     MOV        this,dword ptr [EAX]
    //         0050beb0     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x34]
    //         0050beb4     PUSH       EDX
    //         0050beb5     MOVSX      EAX,word ptr [EBP + local_8c]
    //         0050bebc     IMUL       EAX,EAX,0x3c
    //         0050bebf     MOV        this,dword ptr [EBP + local_90]
    //         0050bec5     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bec7     LEA        EAX,[EDX + EAX*0x1 + 0x30]
    //         0050becb     PUSH       EAX
    //         0050becc     MOVSX      this,word ptr [EBP + local_8c]
    //         0050bed3     IMUL       this,this,0x3c
    //         0050bed6     MOV        EDX,dword ptr [EBP + local_90]
    //         0050bedc     MOV        EAX,dword ptr [EDX]
    //         0050bede     LEA        this,[EAX + this->tech_tree*0x1 + 0x2c]
    //         0050bee2     PUSH       this
    //         0050bee3     MOVSX      EDX,word ptr [EBP + local_8c]
    //         0050beea     IMUL       EDX,EDX,0x3c
    //         0050beed     MOV        EAX,dword ptr [EBP + local_90]
    //         0050bef3     MOV        this,dword ptr [EAX]
    //         0050bef5     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x2a]
    //         0050bef9     PUSH       EDX
    //         0050befa     PUSH       s_%hd_%hd_%d_%d_%d_00588fb4                      = "%hd %hd %d %d %d"
    //         0050beff     MOV        EAX,dword ptr [EBP + local_1c]
    //         0050bf02     PUSH       EAX
    //         0050bf03     CALL       fscanf                                           undefined fscanf()
    //         0050bf08     ADD        ESP,0x1c
    //         0050bf0b     JMP        LAB_0050bc1c
    //                               LAB_0050bf10                                                 XREF[3]:     0050bbdf(j), 0050bbf1(j), 
    //                                                                                                         0050bc32(j)  
    //         0050bf10     MOV        this,dword ptr [EBP + local_1c]
    //         0050bf13     PUSH       this
    //         0050bf14     CALL       fclose                                           undefined fclose()
    //         0050bf19     ADD        ESP,0x4
    //                               LAB_0050bf1c                                                 XREF[1]:     0050bbb7(j)  
    //         0050bf1c     MOV        EAX,dword ptr [EBP + local_90]
    //         0050bf22     MOV        ESP,EBP
    //         0050bf24     POP        EBP
    //         0050bf25     RET        0x4
}

// Offset: 0x0050BF28
void TRIBE_Tech(TRIBE_Tech* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Tech::~TRIBE_Tech(void)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Tech(TRIBE_Tech * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[6]:     0050bf39(W), 0050bf42(R), 0050bf48(W), 0050bf52(R), 
    //                                                                                     0050bf57(R), 0050bf68(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[7]:     0050bf2e(W), 0050bf31(R), 0050bf4b(R), 0050bf5d(R), 
    //                                                                                     0050bf6e(R), 0050bf81(R), 0050bf8f(R)  
    //                               ??1TRIBE_Tech@@QAE@XZ                                        XREF[1]:     ~TRIBE_World:0052e078(c)  
    //                               TRIBE_Tech::~TRIBE_Tech
    //         0050bf28     PUSH       EBP
    //         0050bf29     MOV        EBP,ESP
    //         0050bf2b     SUB        ESP,0x8
    //         0050bf2e     MOV        dword ptr [EBP + local_c],this
    //         0050bf31     MOV        EAX,dword ptr [EBP + local_c]
    //         0050bf34     CMP        dword ptr [EAX],0x0
    //         0050bf37     JZ         LAB_0050bf98
    //         0050bf39     MOV        dword ptr [EBP + local_8],0x0
    //         0050bf40     JMP        LAB_0050bf4b
    //                               LAB_0050bf42                                                 XREF[1]:     0050bf7f(j)  
    //         0050bf42     MOV        this,dword ptr [EBP + local_8]
    //         0050bf45     ADD        this,0x1
    //         0050bf48     MOV        dword ptr [EBP + local_8],this
    //                               LAB_0050bf4b                                                 XREF[1]:     0050bf40(j)  
    //         0050bf4b     MOV        EDX,dword ptr [EBP + local_c]
    //         0050bf4e     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050bf52     CMP        dword ptr [EBP + local_8],EAX
    //         0050bf55     JGE        LAB_0050bf81
    //         0050bf57     MOV        this,dword ptr [EBP + local_8]
    //         0050bf5a     IMUL       this,this,0x3c
    //         0050bf5d     MOV        EDX,dword ptr [EBP + local_c]
    //         0050bf60     MOV        EAX,dword ptr [EDX]
    //         0050bf62     CMP        dword ptr [EAX + this->tech_tree*0x1],0x0
    //         0050bf66     JZ         LAB_0050bf7f
    //         0050bf68     MOV        this,dword ptr [EBP + local_8]
    //         0050bf6b     IMUL       this,this,0x3c
    //         0050bf6e     MOV        EDX,dword ptr [EBP + local_c]
    //         0050bf71     MOV        EAX,dword ptr [EDX]
    //         0050bf73     MOV        this,dword ptr [EAX + this->tech_tree*0x1]
    //         0050bf76     PUSH       this
    //         0050bf77     CALL       free                                             undefined free()
    //         0050bf7c     ADD        ESP,0x4
    //                               LAB_0050bf7f                                                 XREF[1]:     0050bf66(j)  
    //         0050bf7f     JMP        LAB_0050bf42
    //                               LAB_0050bf81                                                 XREF[1]:     0050bf55(j)  
    //         0050bf81     MOV        EDX,dword ptr [EBP + local_c]
    //         0050bf84     MOV        EAX,dword ptr [EDX]
    //         0050bf86     PUSH       EAX
    //         0050bf87     CALL       free                                             undefined free()
    //         0050bf8c     ADD        ESP,0x4
    //         0050bf8f     MOV        this,dword ptr [EBP + local_c]
    //         0050bf92     MOV        dword ptr [this->tech_tree],0x0
    //                               LAB_0050bf98                                                 XREF[1]:     0050bf37(j)  
    //         0050bf98     MOV        ESP,EBP
    //         0050bf9a     POP        EBP
    //         0050bf9b     RET
}

// Offset: 0x0050BF9C
uchar do_tech(TRIBE_Tech* this_, short param_2, RGE_Player* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Tech::do_tech(short,class RGE_Player *)                        *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_tech(TRIBE_Tech * this, short param_1, RGE_Playe
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050bfa3(R), 0050bfbc(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0050bfb8(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[5]:     0050bfa0(W), 0050bfaa(R), 0050bfc3(R), 0050bfce(R), 
    //                                                                                     0050bfd7(R)  
    //                               ?do_tech@TRIBE_Tech@@QAEEFPAVRGE_Player@@@Z                  XREF[1]:     do_tech:0050c63c(c)  
    //                               TRIBE_Tech::do_tech
    //         0050bf9c     PUSH       EBP
    //         0050bf9d     MOV        EBP,ESP
    //         0050bf9f     PUSH       this
    //         0050bfa0     MOV        dword ptr [EBP + local_8],this
    //         0050bfa3     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050bfa7     IMUL       EAX,EAX,0x3c
    //         0050bfaa     MOV        this,dword ptr [EBP + local_8]
    //         0050bfad     MOV        EDX,dword ptr [this->tech_tree]
    //         0050bfaf     MOVSX      EAX,word ptr [EDX + EAX*0x1 + 0x20]
    //         0050bfb4     TEST       EAX,EAX
    //         0050bfb6     JL         LAB_0050bfe5
    //         0050bfb8     MOV        this,dword ptr [EBP + param_2]
    //         0050bfbb     PUSH       this
    //         0050bfbc     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050bfc0     IMUL       EDX,EDX,0x3c
    //         0050bfc3     MOV        EAX,dword ptr [EBP + local_8]
    //         0050bfc6     MOV        this,dword ptr [EAX]
    //         0050bfc8     MOV        DX,word ptr [this->tech_tree + EDX*0x1 + 0x20]
    //         0050bfcd     PUSH       EDX
    //         0050bfce     MOV        EAX,dword ptr [EBP + local_8]
    //         0050bfd1     MOV        this,dword ptr [EAX + 0x8]
    //         0050bfd4     MOV        this,dword ptr [this->tech_tree + 0x4c]
    //         0050bfd7     MOV        EDX,dword ptr [EBP + local_8]
    //         0050bfda     MOV        EAX,dword ptr [EDX + 0x8]
    //         0050bfdd     MOV        EDX,dword ptr [EAX + 0x4c]
    //         0050bfe0     MOV        EAX,dword ptr [EDX]
    //         0050bfe2     CALL       dword ptr [EAX + 0x8]
    //                               LAB_0050bfe5                                                 XREF[1]:     0050bfb6(j)  
    //         0050bfe5     MOV        AL,0x1
    //         0050bfe7     MOV        ESP,EBP
    //         0050bfe9     POP        EBP
    //         0050bfea     RET        0x8
}

// Offset: 0x0050BFED
void save(TRIBE_Tech* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Tech::save(int)                                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall save(TRIBE_Tech * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[19]:    0050bfff(R), 0050c0a1(R), 0050c0e5(R), 0050c10a(R), 
    //                                                                                     0050c12f(R), 0050c153(R), 0050c172(R), 0050c191(R), 
    //                                                                                     0050c1b0(R), 0050c1cf(R), 0050c1ee(R), 0050c20d(R), 
    //                                                                                     0050c22c(R), 0050c24b(R), 0050c26a(R), 0050c289(R), 
    //                                                                                     0050c2a8(R), 0050c2ba(R), 0050c2e3(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[23]:    0050c00b(W), 0050c013(R), 0050c01b(W), 0050c01f(R), 
    //                                                                                     0050c032(R), 0050c044(R), 0050c08a(R), 0050c0ce(R), 
    //                                                                                     0050c0f3(R), 0050c118(R), 0050c142(R), 0050c161(R), 
    //                                                                                     0050c180(R), 0050c19f(R), 0050c1be(R), 0050c1dd(R), 
    //                                                                                     0050c1fc(R), 0050c21b(R), 0050c23a(R), 0050c259(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[5]:     0050c05f(W), 0050c065(W), 0050c2b6(*), 0050c2c6(R), 
    //                                                                                     0050c2ce(R)  
    //              undefined2        Stack[-0x10]:2 local_10                  XREF[12]:    0050c06b(W), 0050c073(R), 0050c07b(W), 0050c07f(R), 
    //                                                                                     0050c098(R), 0050c0af(W), 0050c0b7(R), 0050c0bf(W), 
    //                                                                                     0050c0c3(R), 0050c0dc(R), 0050c101(R), 0050c126(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[22]:    0050bff3(W), 0050bff8(R), 0050c023(R), 0050c039(R), 
    //                                                                                     0050c04b(R), 0050c091(R), 0050c0d5(R), 0050c0fa(R), 
    //                                                                                     0050c11f(R), 0050c149(R), 0050c168(R), 0050c187(R), 
    //                                                                                     0050c1a6(R), 0050c1c5(R), 0050c1e4(R), 0050c203(R), 
    //                                                                                     0050c222(R), 0050c241(R), 0050c260(R), 0050c27f(R)  
    //                               ?save@TRIBE_Tech@@QAEXH@Z                                    XREF[1]:     base_save:0052e785(c)  
    //                               TRIBE_Tech::save
    //         0050bfed     PUSH       EBP
    //         0050bfee     MOV        EBP,ESP
    //         0050bff0     SUB        ESP,0x10
    //         0050bff3     MOV        dword ptr [EBP + local_14],this
    //         0050bff6     PUSH       0x2
    //         0050bff8     MOV        EAX,dword ptr [EBP + local_14]
    //         0050bffb     ADD        EAX,0x4
    //         0050bffe     PUSH       EAX
    //         0050bfff     MOV        this,dword ptr [EBP + param_1]
    //         0050c002     PUSH       this
    //         0050c003     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c008     ADD        ESP,0xc
    //         0050c00b     MOV        word ptr [EBP + local_8],0x0
    //         0050c011     JMP        LAB_0050c01f
    //                               LAB_0050c013                                                 XREF[1]:     0050c2ef(j)  
    //         0050c013     MOV        DX,word ptr [EBP + local_8]
    //         0050c017     ADD        DX,0x1
    //         0050c01b     MOV        word ptr [EBP + local_8],DX
    //                               LAB_0050c01f                                                 XREF[1]:     0050c011(j)  
    //         0050c01f     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c023     MOV        this,dword ptr [EBP + local_14]
    //         0050c026     MOVSX      EDX,word ptr [ECX + this->tech_tree_num]
    //         0050c02a     CMP        EAX,EDX
    //         0050c02c     JGE        LAB_0050c2f4
    //         0050c032     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c036     IMUL       EAX,EAX,0x3c
    //         0050c039     MOV        this,dword ptr [EBP + local_14]
    //         0050c03c     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c03e     CMP        dword ptr [EDX + EAX*0x1],0x0
    //         0050c042     JZ         LAB_0050c065
    //         0050c044     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c048     IMUL       EAX,EAX,0x3c
    //         0050c04b     MOV        this,dword ptr [EBP + local_14]
    //         0050c04e     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c050     MOV        EAX,dword ptr [EDX + EAX*0x1]
    //         0050c053     PUSH       EAX
    //         0050c054     CALL       strlen                                           undefined strlen()
    //         0050c059     ADD        ESP,0x4
    //         0050c05c     ADD        EAX,0x1
    //         0050c05f     MOV        word ptr [EBP + local_c],AX
    //         0050c063     JMP        LAB_0050c06b
    //                               LAB_0050c065                                                 XREF[1]:     0050c042(j)  
    //         0050c065     MOV        word ptr [EBP + local_c],0x0
    //                               LAB_0050c06b                                                 XREF[1]:     0050c063(j)  
    //         0050c06b     MOV        word ptr [EBP + local_10],0x0
    //         0050c071     JMP        LAB_0050c07f
    //                               LAB_0050c073                                                 XREF[1]:     0050c0ad(j)  
    //         0050c073     MOV        this,word ptr [EBP + local_10]
    //         0050c077     ADD        this,0x1
    //         0050c07b     MOV        word ptr [EBP + local_10],this
    //                               LAB_0050c07f                                                 XREF[1]:     0050c071(j)  
    //         0050c07f     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050c083     CMP        EDX,0x4
    //         0050c086     JGE        LAB_0050c0af
    //         0050c088     PUSH       0x2
    //         0050c08a     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c08e     IMUL       EAX,EAX,0x3c
    //         0050c091     MOV        this,dword ptr [EBP + local_14]
    //         0050c094     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c096     ADD        EDX,EAX
    //         0050c098     MOVSX      EAX,word ptr [EBP + local_10]
    //         0050c09c     LEA        this,[EDX + EAX*0x2 + 0x4]
    //         0050c0a0     PUSH       this
    //         0050c0a1     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c0a4     PUSH       EDX
    //         0050c0a5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c0aa     ADD        ESP,0xc
    //         0050c0ad     JMP        LAB_0050c073
    //                               LAB_0050c0af                                                 XREF[1]:     0050c086(j)  
    //         0050c0af     MOV        word ptr [EBP + local_10],0x0
    //         0050c0b5     JMP        LAB_0050c0c3
    //                               LAB_0050c0b7                                                 XREF[1]:     0050c13b(j)  
    //         0050c0b7     MOV        AX,word ptr [EBP + local_10]
    //         0050c0bb     ADD        AX,0x1
    //         0050c0bf     MOV        word ptr [EBP + local_10],AX
    //                               LAB_0050c0c3                                                 XREF[1]:     0050c0b5(j)  
    //         0050c0c3     MOVSX      this,word ptr [EBP + local_10]
    //         0050c0c7     CMP        this,0x3
    //         0050c0ca     JGE        LAB_0050c140
    //         0050c0cc     PUSH       0x2
    //         0050c0ce     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c0d2     IMUL       EDX,EDX,0x3c
    //         0050c0d5     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c0d8     MOV        this,dword ptr [EAX]
    //         0050c0da     ADD        this,EDX
    //         0050c0dc     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050c0e0     LEA        EAX,[this->tech_tree + EDX*0x2 + 0xe]
    //         0050c0e4     PUSH       EAX
    //         0050c0e5     MOV        this,dword ptr [EBP + param_1]
    //         0050c0e8     PUSH       this
    //         0050c0e9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c0ee     ADD        ESP,0xc
    //         0050c0f1     PUSH       0x2
    //         0050c0f3     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c0f7     IMUL       EDX,EDX,0x3c
    //         0050c0fa     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c0fd     MOV        this,dword ptr [EAX]
    //         0050c0ff     ADD        this,EDX
    //         0050c101     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050c105     LEA        EAX,[this->tech_tree + EDX*0x2 + 0x14]
    //         0050c109     PUSH       EAX
    //         0050c10a     MOV        this,dword ptr [EBP + param_1]
    //         0050c10d     PUSH       this
    //         0050c10e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c113     ADD        ESP,0xc
    //         0050c116     PUSH       0x1
    //         0050c118     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c11c     IMUL       EDX,EDX,0x3c
    //         0050c11f     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c122     MOV        this,dword ptr [EAX]
    //         0050c124     ADD        this,EDX
    //         0050c126     MOVSX      EDX,word ptr [EBP + local_10]
    //         0050c12a     LEA        EAX,[this->tech_tree + EDX*0x1 + 0x1a]
    //         0050c12e     PUSH       EAX
    //         0050c12f     MOV        this,dword ptr [EBP + param_1]
    //         0050c132     PUSH       this
    //         0050c133     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c138     ADD        ESP,0xc
    //         0050c13b     JMP        LAB_0050c0b7
    //                               LAB_0050c140                                                 XREF[1]:     0050c0ca(j)  
    //         0050c140     PUSH       0x2
    //         0050c142     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c146     IMUL       EDX,EDX,0x3c
    //         0050c149     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c14c     MOV        this,dword ptr [EAX]
    //         0050c14e     LEA        EDX,[ECX + EDX*0x1 + this+0xc]
    //         0050c152     PUSH       EDX
    //         0050c153     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c156     PUSH       EAX
    //         0050c157     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c15c     ADD        ESP,0xc
    //         0050c15f     PUSH       0x2
    //         0050c161     MOVSX      this,word ptr [EBP + local_8]
    //         0050c165     IMUL       this,this,0x3c
    //         0050c168     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c16b     MOV        EAX,dword ptr [EDX]
    //         0050c16d     LEA        this,[EAX + this->tech_tree*0x1 + 0x28]
    //         0050c171     PUSH       this
    //         0050c172     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c175     PUSH       EDX
    //         0050c176     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c17b     ADD        ESP,0xc
    //         0050c17e     PUSH       0x2
    //         0050c180     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c184     IMUL       EAX,EAX,0x3c
    //         0050c187     MOV        this,dword ptr [EBP + local_14]
    //         0050c18a     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c18c     LEA        EAX,[EDX + EAX*0x1 + 0x2a]
    //         0050c190     PUSH       EAX
    //         0050c191     MOV        this,dword ptr [EBP + param_1]
    //         0050c194     PUSH       this
    //         0050c195     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c19a     ADD        ESP,0xc
    //         0050c19d     PUSH       0x2
    //         0050c19f     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c1a3     IMUL       EDX,EDX,0x3c
    //         0050c1a6     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c1a9     MOV        this,dword ptr [EAX]
    //         0050c1ab     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x2c]
    //         0050c1af     PUSH       EDX
    //         0050c1b0     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c1b3     PUSH       EAX
    //         0050c1b4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c1b9     ADD        ESP,0xc
    //         0050c1bc     PUSH       0x2
    //         0050c1be     MOVSX      this,word ptr [EBP + local_8]
    //         0050c1c2     IMUL       this,this,0x3c
    //         0050c1c5     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c1c8     MOV        EAX,dword ptr [EDX]
    //         0050c1ca     LEA        this,[EAX + this->tech_tree*0x1 + 0x1e]
    //         0050c1ce     PUSH       this
    //         0050c1cf     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c1d2     PUSH       EDX
    //         0050c1d3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c1d8     ADD        ESP,0xc
    //         0050c1db     PUSH       0x2
    //         0050c1dd     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c1e1     IMUL       EAX,EAX,0x3c
    //         0050c1e4     MOV        this,dword ptr [EBP + local_14]
    //         0050c1e7     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c1e9     LEA        EAX,[EDX + EAX*0x1 + 0x20]
    //         0050c1ed     PUSH       EAX
    //         0050c1ee     MOV        this,dword ptr [EBP + param_1]
    //         0050c1f1     PUSH       this
    //         0050c1f2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c1f7     ADD        ESP,0xc
    //         0050c1fa     PUSH       0x2
    //         0050c1fc     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c200     IMUL       EDX,EDX,0x3c
    //         0050c203     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c206     MOV        this,dword ptr [EAX]
    //         0050c208     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x22]
    //         0050c20c     PUSH       EDX
    //         0050c20d     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c210     PUSH       EAX
    //         0050c211     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c216     ADD        ESP,0xc
    //         0050c219     PUSH       0x2
    //         0050c21b     MOVSX      this,word ptr [EBP + local_8]
    //         0050c21f     IMUL       this,this,0x3c
    //         0050c222     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c225     MOV        EAX,dword ptr [EDX]
    //         0050c227     LEA        this,[EAX + this->tech_tree*0x1 + 0x24]
    //         0050c22b     PUSH       this
    //         0050c22c     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c22f     PUSH       EDX
    //         0050c230     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c235     ADD        ESP,0xc
    //         0050c238     PUSH       0x1
    //         0050c23a     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c23e     IMUL       EAX,EAX,0x3c
    //         0050c241     MOV        this,dword ptr [EBP + local_14]
    //         0050c244     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c246     LEA        EAX,[EDX + EAX*0x1 + 0x26]
    //         0050c24a     PUSH       EAX
    //         0050c24b     MOV        this,dword ptr [EBP + param_1]
    //         0050c24e     PUSH       this
    //         0050c24f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c254     ADD        ESP,0xc
    //         0050c257     PUSH       0x4
    //         0050c259     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c25d     IMUL       EDX,EDX,0x3c
    //         0050c260     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c263     MOV        this,dword ptr [EAX]
    //         0050c265     LEA        EDX,[this->tech_tree + EDX*0x1 + 0x30]
    //         0050c269     PUSH       EDX
    //         0050c26a     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c26d     PUSH       EAX
    //         0050c26e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c273     ADD        ESP,0xc
    //         0050c276     PUSH       0x4
    //         0050c278     MOVSX      this,word ptr [EBP + local_8]
    //         0050c27c     IMUL       this,this,0x3c
    //         0050c27f     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c282     MOV        EAX,dword ptr [EDX]
    //         0050c284     LEA        this,[EAX + this->tech_tree*0x1 + 0x34]
    //         0050c288     PUSH       this
    //         0050c289     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c28c     PUSH       EDX
    //         0050c28d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c292     ADD        ESP,0xc
    //         0050c295     PUSH       0x4
    //         0050c297     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c29b     IMUL       EAX,EAX,0x3c
    //         0050c29e     MOV        this,dword ptr [EBP + local_14]
    //         0050c2a1     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c2a3     LEA        EAX,[EDX + EAX*0x1 + 0x38]
    //         0050c2a7     PUSH       EAX
    //         0050c2a8     MOV        this,dword ptr [EBP + param_1]
    //         0050c2ab     PUSH       this
    //         0050c2ac     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c2b1     ADD        ESP,0xc
    //         0050c2b4     PUSH       0x2
    //         0050c2b6     LEA        EDX=>local_c,[EBP + -0x8]
    //         0050c2b9     PUSH       EDX
    //         0050c2ba     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c2bd     PUSH       EAX
    //         0050c2be     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c2c3     ADD        ESP,0xc
    //         0050c2c6     MOVSX      this,word ptr [EBP + local_c]
    //         0050c2ca     TEST       this,this
    //         0050c2cc     JLE        LAB_0050c2ef
    //         0050c2ce     MOVSX      EDX,word ptr [EBP + local_c]
    //         0050c2d2     PUSH       EDX
    //         0050c2d3     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c2d7     IMUL       EAX,EAX,0x3c
    //         0050c2da     MOV        this,dword ptr [EBP + local_14]
    //         0050c2dd     MOV        EDX,dword ptr [this->tech_tree]
    //         0050c2df     MOV        EAX,dword ptr [EDX + EAX*0x1]
    //         0050c2e2     PUSH       EAX
    //         0050c2e3     MOV        this,dword ptr [EBP + param_1]
    //         0050c2e6     PUSH       this
    //         0050c2e7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050c2ec     ADD        ESP,0xc
    //                               LAB_0050c2ef                                                 XREF[1]:     0050c2cc(j)  
    //         0050c2ef     JMP        LAB_0050c013
    //                               LAB_0050c2f4                                                 XREF[1]:     0050c02c(j)  
    //         0050c2f4     MOV        ESP,EBP
    //         0050c2f6     POP        EBP
    //         0050c2f7     RET        0x4
}

