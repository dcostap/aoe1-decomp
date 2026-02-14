// Auto-generated scaffold unit: bucket_050C.asm
#include "../include/common.h"

// Offset: 0x0050C2FA
long get_help_message(TRIBE_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Tech::get_help_message(short)                                           *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_message(TRIBE_Tech * this, short param_1)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050c301(R), 0050c309(R), 0050c31d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050c2fe(W), 0050c30d(R), 0050c324(R)  
    //                               ?get_help_message@TRIBE_Tech@@QAEJF@Z                        XREF[1]:     get_help_message:0050d412(c)  
    //                               TRIBE_Tech::get_help_message
    //         0050c2fa     PUSH       EBP
    //         0050c2fb     MOV        EBP,ESP
    //         0050c2fd     PUSH       this
    //         0050c2fe     MOV        dword ptr [EBP + local_8],this
    //         0050c301     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c305     TEST       EAX,EAX
    //         0050c307     JL         LAB_0050c318
    //         0050c309     MOVSX      this,word ptr [EBP + param_1]
    //         0050c30d     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c310     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050c314     CMP        this,EAX
    //         0050c316     JLE        LAB_0050c31d
    //                               LAB_0050c318                                                 XREF[1]:     0050c307(j)  
    //         0050c318     OR         EAX,0xffffffff
    //         0050c31b     JMP        LAB_0050c32d
    //                               LAB_0050c31d                                                 XREF[1]:     0050c316(j)  
    //         0050c31d     MOVSX      this,word ptr [EBP + param_1]
    //         0050c321     IMUL       this,this,0x3c
    //         0050c324     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c327     MOV        EAX,dword ptr [EDX]
    //         0050c329     MOV        EAX,dword ptr [EAX + this->tech_tree*0x1 + 0x30]
    //                               LAB_0050c32d                                                 XREF[1]:     0050c31b(j)  
    //         0050c32d     MOV        ESP,EBP
    //         0050c32f     POP        EBP
    //         0050c330     RET        0x4
}

// Offset: 0x0050C333
long get_help_page(TRIBE_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Tech::get_help_page(short)                                              *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_page(TRIBE_Tech * this, short param_1)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050c33a(R), 0050c342(R), 0050c356(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050c337(W), 0050c346(R), 0050c35d(R)  
    //                               ?get_help_page@TRIBE_Tech@@QAEJF@Z                           XREF[1]:     get_help_page:0050d42f(c)  
    //                               TRIBE_Tech::get_help_page
    //         0050c333     PUSH       EBP
    //         0050c334     MOV        EBP,ESP
    //         0050c336     PUSH       this
    //         0050c337     MOV        dword ptr [EBP + local_8],this
    //         0050c33a     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c33e     TEST       EAX,EAX
    //         0050c340     JL         LAB_0050c351
    //         0050c342     MOVSX      this,word ptr [EBP + param_1]
    //         0050c346     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c349     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050c34d     CMP        this,EAX
    //         0050c34f     JLE        LAB_0050c356
    //                               LAB_0050c351                                                 XREF[1]:     0050c340(j)  
    //         0050c351     OR         EAX,0xffffffff
    //         0050c354     JMP        LAB_0050c366
    //                               LAB_0050c356                                                 XREF[1]:     0050c34f(j)  
    //         0050c356     MOVSX      this,word ptr [EBP + param_1]
    //         0050c35a     IMUL       this,this,0x3c
    //         0050c35d     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c360     MOV        EAX,dword ptr [EDX]
    //         0050c362     MOV        EAX,dword ptr [EAX + this->tech_tree*0x1 + 0x34]
    //                               LAB_0050c366                                                 XREF[1]:     0050c354(j)  
    //         0050c366     MOV        ESP,EBP
    //         0050c368     POP        EBP
    //         0050c369     RET        0x4
}

// Offset: 0x0050C36C
long get_hotkey(TRIBE_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Tech::get_hotkey(short)                                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall get_hotkey(TRIBE_Tech * this, short param_1)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Tech *      ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050c373(R), 0050c37b(R), 0050c38f(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050c370(W), 0050c37f(R), 0050c396(R)  
    //                               ?get_hotkey@TRIBE_Tech@@QAEJF@Z                              XREF[1]:     get_hotkey:0050d44c(c)  
    //                               TRIBE_Tech::get_hotkey
    //         0050c36c     PUSH       EBP
    //         0050c36d     MOV        EBP,ESP
    //         0050c36f     PUSH       this
    //         0050c370     MOV        dword ptr [EBP + local_8],this
    //         0050c373     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c377     TEST       EAX,EAX
    //         0050c379     JL         LAB_0050c38a
    //         0050c37b     MOVSX      this,word ptr [EBP + param_1]
    //         0050c37f     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c382     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050c386     CMP        this,EAX
    //         0050c388     JLE        LAB_0050c38f
    //                               LAB_0050c38a                                                 XREF[1]:     0050c379(j)  
    //         0050c38a     OR         EAX,0xffffffff
    //         0050c38d     JMP        LAB_0050c39f
    //                               LAB_0050c38f                                                 XREF[1]:     0050c388(j)  
    //         0050c38f     MOVSX      this,word ptr [EBP + param_1]
    //         0050c393     IMUL       this,this,0x3c
    //         0050c396     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c399     MOV        EAX,dword ptr [EDX]
    //         0050c39b     MOV        EAX,dword ptr [EAX + this->tech_tree*0x1 + 0x38]
    //                               LAB_0050c39f                                                 XREF[1]:     0050c38d(j)  
    //         0050c39f     MOV        ESP,EBP
    //         0050c3a1     POP        EBP
    //         0050c3a2     RET        0x4
}

// Offset: 0x0050C3A5
undefined TRIBE_Player_Tech(TRIBE_Player_Tech* this_, int param_2, TRIBE_Tech* param_3, RGE_Player* param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Player_Tech::TRIBE_Player_Tech(int,class TRIBE_Tech *,class RGE_Player *,... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Player_Tech(TRIBE_Player_Tech * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0050c3b7(R), 0050c440(R), 0050c45d(R), 0050c479(R)  
    //              TRIBE_Tech *      Stack[0x8]:4   param_2                   XREF[1]:     0050c3c6(R)  
    //              RGE_Player *      Stack[0xc]:4   param_3                   XREF[1]:     0050c3cf(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0050c48a(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[14]:    0050c3fb(W), 0050c403(R), 0050c40b(W), 0050c40f(R), 
    //                                                                                     0050c433(R), 0050c450(R), 0050c46b(R), 0050c496(W), 
    //                                                                                     0050c49e(R), 0050c4a6(W), 0050c4aa(R), 0050c4b9(R), 
    //                                                                                     0050c4cc(R), 0050c4dc(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[17]:    0050c3ab(W), 0050c3b0(R), 0050c3c3(R), 0050c3cc(R), 
    //                                                                                     0050c3d5(R), 0050c3e4(R), 0050c3f6(R), 0050c413(R), 
    //                                                                                     0050c437(R), 0050c454(R), 0050c46f(R), 0050c4ae(R), 
    //                                                                                     0050c4bd(R), 0050c4d0(R), 0050c4e1(R), 0050c4eb(R), 
    //                                                                                     0050c4f3(R)  
    //                               ??0TRIBE_Player_Tech@@QAE@HPAVTRIBE_Tech@@PAVRGE_Player@@E@Z XREF[2]:     TRIBE_Player:00511c90(c), 
    //                               TRIBE_Player_Tech::TRIBE_Player_Tech                                      scenario_load:005127a1(c)  
    //         0050c3a5     PUSH       EBP
    //         0050c3a6     MOV        EBP,ESP
    //         0050c3a8     SUB        ESP,0x8
    //         0050c3ab     MOV        dword ptr [EBP + local_c],this
    //         0050c3ae     PUSH       0x2
    //         0050c3b0     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c3b3     ADD        EAX,0x4
    //         0050c3b6     PUSH       EAX
    //         0050c3b7     MOV        this,dword ptr [EBP + param_1]
    //         0050c3ba     PUSH       this
    //         0050c3bb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050c3c0     ADD        ESP,0xc
    //         0050c3c3     MOV        EDX,dword ptr [EBP + local_c]
    //         0050c3c6     MOV        EAX,dword ptr [EBP + param_2]
    //         0050c3c9     MOV        dword ptr [EDX + 0x8],EAX
    //         0050c3cc     MOV        this,dword ptr [EBP + local_c]
    //         0050c3cf     MOV        EDX,dword ptr [EBP + param_3]
    //         0050c3d2     MOV        dword ptr [ECX + this->owner],EDX
    //         0050c3d5     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c3d8     MOVSX      this,word ptr [EAX + 0x4]
    //         0050c3dc     TEST       this,this
    //         0050c3de     JLE        LAB_0050c4f3
    //         0050c3e4     MOV        EDX,dword ptr [EBP + local_c]
    //         0050c3e7     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050c3eb     PUSH       EAX
    //         0050c3ec     PUSH       0x8
    //         0050c3ee     CALL       calloc                                           undefined calloc()
    //         0050c3f3     ADD        ESP,0x8
    //         0050c3f6     MOV        this,dword ptr [EBP + local_c]
    //         0050c3f9     MOV        dword ptr [this->tech_player_tree],EAX
    //         0050c3fb     MOV        word ptr [EBP + local_8],0x0
    //         0050c401     JMP        LAB_0050c40f
    //                               LAB_0050c403                                                 XREF[1]:     0050c485(j)  
    //         0050c403     MOV        DX,word ptr [EBP + local_8]
    //         0050c407     ADD        DX,0x1
    //         0050c40b     MOV        word ptr [EBP + local_8],DX
    //                               LAB_0050c40f                                                 XREF[1]:     0050c401(j)  
    //         0050c40f     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c413     MOV        this,dword ptr [EBP + local_c]
    //         0050c416     MOVSX      EDX,word ptr [ECX + this->tech_player_tree_num]
    //         0050c41a     CMP        EAX,EDX
    //         0050c41c     JGE        LAB_0050c48a
    //         0050c41e     FLD        float ptr [save_game_version]                    = 7.23
    //         0050c424     FCOMP      float ptr [DAT_005766c0]                         = C3h
    //         0050c42a     FNSTSW     AX
    //         0050c42c     TEST       AH,0x41
    //         0050c42f     JZ         LAB_0050c44e
    //         0050c431     PUSH       0x2
    //         0050c433     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c437     MOV        this,dword ptr [EBP + local_c]
    //         0050c43a     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c43c     LEA        EAX,[EDX + EAX*0x8]
    //         0050c43f     PUSH       EAX
    //         0050c440     MOV        this,dword ptr [EBP + param_1]
    //         0050c443     PUSH       this
    //         0050c444     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050c449     ADD        ESP,0xc
    //         0050c44c     JMP        LAB_0050c469
    //                               LAB_0050c44e                                                 XREF[1]:     0050c42f(j)  
    //         0050c44e     PUSH       0x4
    //         0050c450     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c454     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c457     MOV        this,dword ptr [EAX]
    //         0050c459     LEA        EDX,[this->tech_player_tree + EDX*0x8]
    //         0050c45c     PUSH       EDX
    //         0050c45d     MOV        EAX,dword ptr [EBP + param_1]
    //         0050c460     PUSH       EAX
    //         0050c461     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050c466     ADD        ESP,0xc
    //                               LAB_0050c469                                                 XREF[1]:     0050c44c(j)  
    //         0050c469     PUSH       0x2
    //         0050c46b     MOVSX      this,word ptr [EBP + local_8]
    //         0050c46f     MOV        EDX,dword ptr [EBP + local_c]
    //         0050c472     MOV        EAX,dword ptr [EDX]
    //         0050c474     LEA        this,[EAX + this->tech_player_tree*0x8 + 0x4]
    //         0050c478     PUSH       this
    //         0050c479     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c47c     PUSH       EDX
    //         0050c47d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050c482     ADD        ESP,0xc
    //         0050c485     JMP        LAB_0050c403
    //                               LAB_0050c48a                                                 XREF[1]:     0050c41c(j)  
    //         0050c48a     MOV        EAX,dword ptr [EBP + param_4]
    //         0050c48d     AND        EAX,0xff
    //         0050c492     TEST       EAX,EAX
    //         0050c494     JZ         LAB_0050c4f3
    //         0050c496     MOV        word ptr [EBP + local_8],0x0
    //         0050c49c     JMP        LAB_0050c4aa
    //                               LAB_0050c49e                                                 XREF[1]:     0050c4e9(j)  
    //         0050c49e     MOV        this,word ptr [EBP + local_8]
    //         0050c4a2     ADD        this,0x1
    //         0050c4a6     MOV        word ptr [EBP + local_8],this
    //                               LAB_0050c4aa                                                 XREF[1]:     0050c49c(j)  
    //         0050c4aa     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c4ae     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c4b1     MOVSX      this,word ptr [EAX + 0x4]
    //         0050c4b5     CMP        EDX,this
    //         0050c4b7     JGE        LAB_0050c4eb
    //         0050c4b9     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050c4bd     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c4c0     MOV        this,dword ptr [EAX]
    //         0050c4c2     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050c4c7     CMP        EDX,0x3
    //         0050c4ca     JNZ        LAB_0050c4e9
    //         0050c4cc     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050c4d0     MOV        this,dword ptr [EBP + local_c]
    //         0050c4d3     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c4d5     MOV        word ptr [EDX + EAX*0x8 + 0x4],0x1
    //         0050c4dc     MOV        AX,word ptr [EBP + local_8]
    //         0050c4e0     PUSH       EAX
    //         0050c4e1     MOV        this,dword ptr [EBP + local_c]
    //         0050c4e4     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //                               LAB_0050c4e9                                                 XREF[1]:     0050c4ca(j)  
    //         0050c4e9     JMP        LAB_0050c49e
    //                               LAB_0050c4eb                                                 XREF[1]:     0050c4b7(j)  
    //         0050c4eb     MOV        this,dword ptr [EBP + local_c]
    //         0050c4ee     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech * 
    //                               LAB_0050c4f3                                                 XREF[2]:     0050c3de(j), 0050c494(j)  
    //         0050c4f3     MOV        EAX,dword ptr [EBP + local_c]
    //         0050c4f6     MOV        ESP,EBP
    //         0050c4f8     POP        EBP
    //         0050c4f9     RET        0x10
}

// Offset: 0x0050C4FC
undefined TRIBE_Player_Tech(TRIBE_Player_Tech* this_, TRIBE_Tech* param_2, RGE_Player* param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Player_Tech::TRIBE_Player_Tech(class TRIBE_Tech *,class RGE_Player *,unsi... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Player_Tech(TRIBE_Player_Tech * this, TRI
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              TRIBE_Tech *      Stack[0x4]:4   param_1                   XREF[2]:     0050c506(R), 0050c518(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0050c50f(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0050c545(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[9]:     0050c500(W), 0050c503(R), 0050c50c(R), 0050c515(R), 
    //                                                                                     0050c523(R), 0050c52e(R), 0050c540(R), 0050c551(R), 
    //                                                                                     0050c559(R)  
    //                               ??0TRIBE_Player_Tech@@QAE@PAVTRIBE_Tech@@PAVRGE_Player@@E@Z  XREF[2]:     TRIBE_Player:005120ab(c), 
    //                               TRIBE_Player_Tech::TRIBE_Player_Tech                                      scenario_load:00512803(c)  
    //         0050c4fc     PUSH       EBP
    //         0050c4fd     MOV        EBP,ESP
    //         0050c4ff     PUSH       this
    //         0050c500     MOV        dword ptr [EBP + local_8],this
    //         0050c503     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c506     MOV        this,dword ptr [EBP + param_1]
    //         0050c509     MOV        dword ptr [EAX + 0x8],this
    //         0050c50c     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c50f     MOV        EAX,dword ptr [EBP + param_2]
    //         0050c512     MOV        dword ptr [EDX + 0xc],EAX
    //         0050c515     MOV        this,dword ptr [EBP + local_8]
    //         0050c518     MOV        EDX,dword ptr [EBP + param_1]
    //         0050c51b     MOV        AX,word ptr [EDX + 0x4]
    //         0050c51f     MOV        word ptr [ECX + this->tech_player_tree_num],AX
    //         0050c523     MOV        this,dword ptr [EBP + local_8]
    //         0050c526     MOVSX      EDX,word ptr [ECX + this->tech_player_tree_num]
    //         0050c52a     TEST       EDX,EDX
    //         0050c52c     JLE        LAB_0050c545
    //         0050c52e     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c531     MOVSX      this,word ptr [EAX + 0x4]
    //         0050c535     PUSH       this
    //         0050c536     PUSH       0x8
    //         0050c538     CALL       calloc                                           undefined calloc()
    //         0050c53d     ADD        ESP,0x8
    //         0050c540     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c543     MOV        dword ptr [EDX],EAX
    //                               LAB_0050c545                                                 XREF[1]:     0050c52c(j)  
    //         0050c545     MOV        EAX,dword ptr [EBP + param_3]
    //         0050c548     AND        EAX,0xff
    //         0050c54d     TEST       EAX,EAX
    //         0050c54f     JZ         LAB_0050c559
    //         0050c551     MOV        this,dword ptr [EBP + local_8]
    //         0050c554     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech * 
    //                               LAB_0050c559                                                 XREF[1]:     0050c54f(j)  
    //         0050c559     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c55c     MOV        ESP,EBP
    //         0050c55e     POP        EBP
    //         0050c55f     RET        0xc
}

// Offset: 0x0050C562
void TRIBE_Player_Tech(TRIBE_Player_Tech* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Player_Tech::~TRIBE_Player_Tech(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Player_Tech(TRIBE_Player_Tech * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     0050c566(W), 0050c569(R), 0050c571(R), 0050c57f(R)  
    //                               ??1TRIBE_Player_Tech@@QAE@XZ                                 XREF[2]:     ~TRIBE_Player:00512127(c), 
    //                               TRIBE_Player_Tech::~TRIBE_Player_Tech                                     scenario_load:005126cc(c)  
    //         0050c562     PUSH       EBP
    //         0050c563     MOV        EBP,ESP
    //         0050c565     PUSH       this
    //         0050c566     MOV        dword ptr [EBP + local_8],this
    //         0050c569     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c56c     CMP        dword ptr [EAX],0x0
    //         0050c56f     JZ         LAB_0050c588
    //         0050c571     MOV        this,dword ptr [EBP + local_8]
    //         0050c574     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c576     PUSH       EDX
    //         0050c577     CALL       free                                             undefined free()
    //         0050c57c     ADD        ESP,0x4
    //         0050c57f     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c582     MOV        dword ptr [EAX],0x0
    //                               LAB_0050c588                                                 XREF[1]:     0050c56f(j)  
    //         0050c588     MOV        ESP,EBP
    //         0050c58a     POP        EBP
    //         0050c58b     RET
}

// Offset: 0x0050C58C
short get_tech_state(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: short __thiscall TRIBE_Player_Tech::get_tech_state(short)                                     *
    //                              *********************************************************************************************************
    //                              short __thiscall get_tech_state(TRIBE_Player_Tech * this, short para
    //              short             AX:2           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050c593(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050c590(W), 0050c597(R)  
    //                               ?get_tech_state@TRIBE_Player_Tech@@QAEFF@Z                   XREF[5]:     TribeDiplomacyDialog:0043d602(c), 
    //                               TRIBE_Player_Tech::get_tech_state                                         setup_buttons:0049a291(c), 
    //                                                                                                         researchEverAvailable:005146bb(c), 
    //                                                                                                         researchState:005146eb(c), 
    //                                                                                                         handle_tech:0052c98e(c)  
    //         0050c58c     PUSH       EBP
    //         0050c58d     MOV        EBP,ESP
    //         0050c58f     PUSH       this
    //         0050c590     MOV        dword ptr [EBP + local_8],this
    //         0050c593     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c597     MOV        this,dword ptr [EBP + local_8]
    //         0050c59a     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c59c     MOV        AX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050c5a1     MOV        ESP,EBP
    //         0050c5a3     POP        EBP
    //         0050c5a4     RET        0x4
}

// Offset: 0x0050C5A7
uchar undo_tech(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::undo_tech(short)                                  *
    //                              *********************************************************************************************************
    //                              uchar __thiscall undo_tech(TRIBE_Player_Tech * this, short param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050c5ae(R), 0050c5c1(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     0050c5ab(W), 0050c5b2(R), 0050c5c5(R), 0050c5d1(R)  
    //                               ?undo_tech@TRIBE_Player_Tech@@QAEEF@Z                        XREF[4]:     set_object_state:004c8a1a(c), 
    //                               TRIBE_Player_Tech::undo_tech                                              set_object_state:004c8a2a(c), 
    //                                                                                                         set_object_state:004c8a3a(c), 
    //                                                                                                         set_object_state:004c8a4a(c)  
    //         0050c5a7     PUSH       EBP
    //         0050c5a8     MOV        EBP,ESP
    //         0050c5aa     PUSH       this
    //         0050c5ab     MOV        dword ptr [EBP + local_8],this
    //         0050c5ae     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c5b2     MOV        this,dword ptr [EBP + local_8]
    //         0050c5b5     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c5b7     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050c5bc     CMP        EAX,0x1
    //         0050c5bf     JL         LAB_0050c5dd
    //         0050c5c1     MOVSX      this,word ptr [EBP + param_1]
    //         0050c5c5     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c5c8     MOV        EAX,dword ptr [EDX]
    //         0050c5ca     MOV        word ptr [EAX + this->tech_player_tree*0x8 + 0
    //         0050c5d1     MOV        this,dword ptr [EBP + local_8]
    //         0050c5d4     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech * 
    //         0050c5d9     MOV        AL,0x1
    //         0050c5db     JMP        LAB_0050c5df
    //                               LAB_0050c5dd                                                 XREF[1]:     0050c5bf(j)  
    //         0050c5dd     XOR        AL,AL
    //                               LAB_0050c5df                                                 XREF[1]:     0050c5db(j)  
    //         0050c5df     MOV        ESP,EBP
    //         0050c5e1     POP        EBP
    //         0050c5e2     RET        0x4
}

// Offset: 0x0050C5E5
uchar do_tech(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::do_tech(short)                                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_tech(TRIBE_Player_Tech * this, short param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[7]:     0050c5ec(R), 0050c603(R), 0050c61a(R), 0050c631(R), 
    //                                                                                     0050c649(R), 0050c667(R), 0050c685(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[10]:    0050c5e9(W), 0050c5f0(R), 0050c607(R), 0050c61e(R), 
    //                                                                                     0050c62a(R), 0050c636(R), 0050c641(R), 0050c654(R), 
    //                                                                                     0050c672(R), 0050c690(R)  
    //                               ?do_tech@TRIBE_Player_Tech@@QAEEF@Z                          XREF[8]:     set_object_state:004c894f(c), 
    //                               TRIBE_Player_Tech::do_tech                                                change_ownership:004c8dfe(c), 
    //                                                                                                         TRIBE_Player_Tech:0050c4e4(c), 
    //                                                                                                         research:0050c71a(c), 
    //                                                                                                         check_for_new_tech:0050cfad(c), 
    //                                                                                                         do_rev_tech:0050d276(c), 
    //                                                                                                         rev_tech:0050d292(c), 
    //                                                                                                         rev_tech:00513ee7(c)  
    //         0050c5e5     PUSH       EBP
    //         0050c5e6     MOV        EBP,ESP
    //         0050c5e8     PUSH       this
    //         0050c5e9     MOV        dword ptr [EBP + local_8],this
    //         0050c5ec     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c5f0     MOV        this,dword ptr [EBP + local_8]
    //         0050c5f3     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c5f5     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050c5fa     CMP        EAX,0x3
    //         0050c5fd     JGE        LAB_0050c6a5
    //         0050c603     MOVSX      this,word ptr [EBP + param_1]
    //         0050c607     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c60a     MOV        EAX,dword ptr [EDX]
    //         0050c60c     MOVSX      this,word ptr [EAX + this->tech_player_tree*0x
    //         0050c611     CMP        this,-0x1
    //         0050c614     JLE        LAB_0050c6a5
    //         0050c61a     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050c61e     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c621     MOV        this,dword ptr [EAX]
    //         0050c623     MOV        word ptr [ECX + EDX*0x8 + this->tech_player_tr
    //         0050c62a     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c62d     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050c630     PUSH       EAX
    //         0050c631     MOV        this,word ptr [EBP + param_1]
    //         0050c635     PUSH       this
    //         0050c636     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c639     MOV        this,dword ptr [EDX + 0x8]
    //         0050c63c     CALL       TRIBE_Tech::do_tech                              uchar do_tech(TRIBE_Tech * this, short param_
    //         0050c641     MOV        this,dword ptr [EBP + local_8]
    //         0050c644     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech * 
    //         0050c649     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c64d     CMP        EAX,0x65
    //         0050c650     JNZ        LAB_0050c667
    //         0050c652     PUSH       0x0
    //         0050c654     MOV        this,dword ptr [EBP + local_8]
    //         0050c657     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050c65a     MOV        this,dword ptr [EDX + 0x83c]
    //         0050c660     CALL       TRIBE_History_Info::add_history_event            void add_history_event(TRIBE_History_Info * t
    //         0050c665     JMP        LAB_0050c6a1
    //                               LAB_0050c667                                                 XREF[1]:     0050c650(j)  
    //         0050c667     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c66b     CMP        EAX,0x66
    //         0050c66e     JNZ        LAB_0050c685
    //         0050c670     PUSH       0x1
    //         0050c672     MOV        this,dword ptr [EBP + local_8]
    //         0050c675     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050c678     MOV        this,dword ptr [EDX + 0x83c]
    //         0050c67e     CALL       TRIBE_History_Info::add_history_event            void add_history_event(TRIBE_History_Info * t
    //         0050c683     JMP        LAB_0050c6a1
    //                               LAB_0050c685                                                 XREF[1]:     0050c66e(j)  
    //         0050c685     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c689     CMP        EAX,0x67
    //         0050c68c     JNZ        LAB_0050c6a1
    //         0050c68e     PUSH       0x2
    //         0050c690     MOV        this,dword ptr [EBP + local_8]
    //         0050c693     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050c696     MOV        this,dword ptr [EDX + 0x83c]
    //         0050c69c     CALL       TRIBE_History_Info::add_history_event            void add_history_event(TRIBE_History_Info * t
    //                               LAB_0050c6a1                                                 XREF[3]:     0050c665(j), 0050c683(j), 
    //                                                                                                         0050c68c(j)  
    //         0050c6a1     MOV        AL,0x1
    //         0050c6a3     JMP        LAB_0050c6a7
    //                               LAB_0050c6a5                                                 XREF[2]:     0050c5fd(j), 0050c614(j)  
    //         0050c6a5     XOR        AL,AL
    //                               LAB_0050c6a7                                                 XREF[1]:     0050c6a3(j)  
    //         0050c6a7     MOV        ESP,EBP
    //         0050c6a9     POP        EBP
    //         0050c6aa     RET        0x4
}

// Offset: 0x0050C6AD
uchar research(TRIBE_Player_Tech* this_, short param_2, float param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::research(short,float)                             *
    //                              *********************************************************************************************************
    //                              uchar __thiscall research(TRIBE_Player_Tech * this, short param_1, f
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[6]:     0050c6b7(R), 0050c6ca(R), 0050c6d9(R), 0050c6e5(R), 
    //                                                                                     0050c6f4(R), 0050c712(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0050c6d6(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[7]:     0050c6b4(W), 0050c6bb(R), 0050c6ce(R), 0050c6dd(R), 
    //                                                                                     0050c6e9(R), 0050c6ee(R), 0050c717(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050c702(W), 0050c705(R)  
    //                               ?research@TRIBE_Player_Tech@@QAEEFM@Z                        XREF[1]:     update:004d24b7(c)  
    //                               TRIBE_Player_Tech::research
    //         0050c6ad     PUSH       EBP
    //         0050c6ae     MOV        EBP,ESP
    //         0050c6b0     SUB        ESP,0x8
    //         0050c6b3     PUSH       ESI
    //         0050c6b4     MOV        dword ptr [EBP + local_8],this
    //         0050c6b7     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050c6bb     MOV        this,dword ptr [EBP + local_8]
    //         0050c6be     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050c6c0     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050c6c5     CMP        EAX,0x2
    //         0050c6c8     JNZ        LAB_0050c727
    //         0050c6ca     MOVSX      this,word ptr [EBP + param_1]
    //         0050c6ce     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c6d1     MOV        EAX,dword ptr [EDX]
    //         0050c6d3     FLD        float ptr [EAX + this->tech_player_tree*0x8]
    //         0050c6d6     FADD       float ptr [EBP + param_2]
    //         0050c6d9     MOVSX      this,word ptr [EBP + param_1]
    //         0050c6dd     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c6e0     MOV        EAX,dword ptr [EDX]
    //         0050c6e2     FSTP       float ptr [EAX + this->tech_player_tree*0x8]
    //         0050c6e5     MOVSX      this,word ptr [EBP + param_1]
    //         0050c6e9     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c6ec     MOV        EAX,dword ptr [EDX]
    //         0050c6ee     MOV        EDX,dword ptr [EBP + local_8]
    //         0050c6f1     MOV        EDX,dword ptr [EDX + 0x8]
    //         0050c6f4     MOVSX      ESI,word ptr [EBP + param_1]
    //         0050c6f8     IMUL       ESI,ESI,0x3c
    //         0050c6fb     MOV        EDX,dword ptr [EDX]
    //         0050c6fd     MOVSX      EDX,word ptr [EDX + ESI*0x1 + 0x1e]
    //         0050c702     MOV        dword ptr [EBP + local_c],EDX
    //         0050c705     FILD       dword ptr [EBP + local_c]
    //         0050c708     FCOMP      float ptr [EAX + this->tech_player_tree*0x8]
    //         0050c70b     FNSTSW     AX
    //         0050c70d     TEST       AH,0x41
    //         0050c710     JZ         LAB_0050c723
    //         0050c712     MOV        AX,word ptr [EBP + param_1]
    //         0050c716     PUSH       EAX
    //         0050c717     MOV        this,dword ptr [EBP + local_8]
    //         0050c71a     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //         0050c71f     XOR        AL,AL
    //         0050c721     JMP        LAB_0050c729
    //                               LAB_0050c723                                                 XREF[1]:     0050c710(j)  
    //         0050c723     MOV        AL,0x1
    //         0050c725     JMP        LAB_0050c729
    //                               LAB_0050c727                                                 XREF[1]:     0050c6c8(j)  
    //         0050c727     XOR        AL,AL
    //                               LAB_0050c729                                                 XREF[2]:     0050c721(j), 0050c725(j)  
    //         0050c729     POP        ESI
    //         0050c72a     MOV        ESP,EBP
    //         0050c72c     POP        EBP
    //         0050c72d     RET        0x8
}

// Offset: 0x0050C730
void tech_cost(TRIBE_Player_Tech* this_, short param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Player_Tech::tech_cost(short,short &,short &,short &,short &,short &... *
    //                              *********************************************************************************************************
    //                              void __thiscall tech_cost(TRIBE_Player_Tech * this, short param_1, s
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050c740(R), 0050c786(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[10]:    0050c754(R), 0050c7c3(R), 0050c7d0(R), 0050c7f1(R), 
    //                                                                                     0050c828(R), 0050c84f(R), 0050c9d9(R), 0050c9e4(R), 
    //                                                                                     0050c9ef(R), 0050ca6b(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[8]:     0050c75c(R), 0050c7de(R), 0050c7fa(R), 0050c81c(R), 
    //                                                                                     0050c860(R), 0050c9f7(R), 0050ca01(R), 0050ca61(R)  
    //              short *           Stack[0x10]:4  param_4                   XREF[10]:    0050c764(R), 0050c876(R), 0050c883(R), 0050c8a4(R), 
    //                                                                                     0050c8dc(R), 0050c903(R), 0050ca09(R), 0050ca14(R), 
    //                                                                                     0050ca1f(R), 0050ca7d(R)  
    //              short *           Stack[0x14]:4  param_5                   XREF[8]:     0050c76c(R), 0050c891(R), 0050c8ad(R), 0050c8d0(R), 
    //                                                                                     0050c914(R), 0050ca27(R), 0050ca31(R), 0050ca73(R)  
    //              short *           Stack[0x18]:4  param_6                   XREF[10]:    0050c774(R), 0050c92a(R), 0050c937(R), 0050c958(R), 
    //                                                                                     0050c98f(R), 0050c9b6(R), 0050ca39(R), 0050ca44(R), 
    //                                                                                     0050ca4f(R), 0050ca8f(R)  
    //              short *           Stack[0x1c]:4  param_7                   XREF[7]:     0050c77c(R), 0050c945(R), 0050c961(R), 0050c983(R), 
    //                                                                                     0050c9c7(R), 0050ca57(R), 0050ca85(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[5]:     0050c793(W), 0050c7af(W), 0050c810(R), 0050c8c3(R), 
    //                                                                                     0050c977(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[11]:    0050c74e(W), 0050c83e(R), 0050c845(W), 0050c8f2(R), 
    //                                                                                     0050c8f9(W), 0050c9a5(R), 0050c9ac(W), 0050c9cd(R), 
    //                                                                                     0050c9fd(R), 0050ca2d(R), 0050ca5a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[10]:    0050c74b(W), 0050c7b3(R), 0050c7c6(R), 0050c7e1(R), 
    //                                                                                     0050c866(R), 0050c879(R), 0050c894(R), 0050c91a(R), 
    //                                                                                     0050c92d(R), 0050c948(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[13]:    0050c737(W), 0050c73a(R), 0050c78b(R), 0050c796(R), 
    //                                                                                     0050c7eb(R), 0050c822(R), 0050c849(R), 0050c89e(R), 
    //                                                                                     0050c8d6(R), 0050c8fd(R), 0050c952(R), 0050c989(R), 
    //                                                                                     0050c9b0(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     0050c800(W), 0050c803(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     0050c8b3(W), 0050c8b6(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0050c967(W), 0050c96a(R)  
    //                               ?tech_cost@TRIBE_Player_Tech@@QAEXFAAF00000@Z                XREF[4]:     setup_buttons:0049a2f4(c), 
    //                               TRIBE_Player_Tech::tech_cost                                              tech_cost:00512c19(c), 
    //                                                                                                         interface_tech_avail:00513110(c), 
    //                                                                                                         researchCost:0051460d(c)  
    //         0050c730     PUSH       EBP
    //         0050c731     MOV        EBP,ESP
    //         0050c733     SUB        ESP,0x1c
    //         0050c736     PUSH       ESI
    //         0050c737     MOV        dword ptr [EBP + local_14],this
    //         0050c73a     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c73d     MOV        this,dword ptr [EAX + 0x8]
    //         0050c740     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050c744     IMUL       EDX,EDX,0x3c
    //         0050c747     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050c749     ADD        EAX,EDX
    //         0050c74b     MOV        dword ptr [EBP + local_10],EAX
    //         0050c74e     MOV        word ptr [EBP + local_c],0x0
    //         0050c754     MOV        this,dword ptr [EBP + param_2]
    //         0050c757     MOV        word ptr [this->tech_player_tree],0xffff
    //         0050c75c     MOV        EDX,dword ptr [EBP + param_3]
    //         0050c75f     MOV        word ptr [EDX],0x0
    //         0050c764     MOV        EAX,dword ptr [EBP + param_4]
    //         0050c767     MOV        word ptr [EAX],0xffff
    //         0050c76c     MOV        this,dword ptr [EBP + param_5]
    //         0050c76f     MOV        word ptr [this->tech_player_tree],0x0
    //         0050c774     MOV        EDX,dword ptr [EBP + param_6]
    //         0050c777     MOV        word ptr [EDX],0xffff
    //         0050c77c     MOV        EAX,dword ptr [EBP + param_7]
    //         0050c77f     MOV        word ptr [EAX],0x0
    //         0050c784     PUSH       0x0
    //         0050c786     MOV        this,word ptr [EBP + param_1]
    //         0050c78a     PUSH       this
    //         0050c78b     MOV        this,dword ptr [EBP + local_14]
    //         0050c78e     CALL       TRIBE_Player_Tech::check_tech_cost               uchar check_tech_cost(TRIBE_Player_Tech * thi
    //         0050c793     MOV        byte ptr [EBP + local_8],AL
    //         0050c796     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c799     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050c79c     MOV        this,dword ptr [EAX + 0x50]
    //         0050c79f     FLD        float ptr [this->tech_player_tree + 0x74]
    //         0050c7a2     FCOMP      double ptr [DAT_005766c8]
    //         0050c7a8     FNSTSW     AX
    //         0050c7aa     TEST       AH,0x1
    //         0050c7ad     JZ         LAB_0050c7b3
    //         0050c7af     MOV        byte ptr [EBP + local_8],0x0
    //                               LAB_0050c7b3                                                 XREF[1]:     0050c7ad(j)  
    //         0050c7b3     MOV        EDX,dword ptr [EBP + local_10]
    //         0050c7b6     XOR        EAX,EAX
    //         0050c7b8     MOV        AL,byte ptr [EDX + 0x1a]
    //         0050c7bb     TEST       EAX,EAX
    //         0050c7bd     JZ         LAB_0050c866
    //         0050c7c3     MOV        this,dword ptr [EBP + param_2]
    //         0050c7c6     MOV        EDX,dword ptr [EBP + local_10]
    //         0050c7c9     MOV        AX,word ptr [EDX + 0xe]
    //         0050c7cd     MOV        word ptr [this->tech_player_tree],AX
    //         0050c7d0     MOV        this,dword ptr [EBP + param_2]
    //         0050c7d3     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050c7d6     TEST       EDX,EDX
    //         0050c7d8     JL         LAB_0050c866
    //         0050c7de     MOV        EAX,dword ptr [EBP + param_3]
    //         0050c7e1     MOV        this,dword ptr [EBP + local_10]
    //         0050c7e4     MOV        DX,word ptr [this->tech_player_tree + 0x14]
    //         0050c7e8     MOV        word ptr [EAX],DX
    //         0050c7eb     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c7ee     MOV        this,dword ptr [EAX + 0xc]
    //         0050c7f1     MOV        EDX,dword ptr [EBP + param_2]
    //         0050c7f4     MOVSX      EAX,word ptr [EDX]
    //         0050c7f7     MOV        this,dword ptr [this->tech_player_tree + 0x50]
    //         0050c7fa     MOV        EDX,dword ptr [EBP + param_3]
    //         0050c7fd     MOVSX      EDX,word ptr [EDX]
    //         0050c800     MOV        dword ptr [EBP + local_18],EDX
    //         0050c803     FILD       dword ptr [EBP + local_18]
    //         0050c806     FCOMP      float ptr [this->tech_player_tree + EAX*0x4]
    //         0050c809     FNSTSW     AX
    //         0050c80b     TEST       AH,0x41
    //         0050c80e     JNZ        LAB_0050c866
    //         0050c810     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c813     AND        EAX,0xff
    //         0050c818     TEST       EAX,EAX
    //         0050c81a     JZ         LAB_0050c866
    //         0050c81c     MOV        this,dword ptr [EBP + param_3]
    //         0050c81f     MOVSX      ESI,word ptr [this->tech_player_tree]
    //         0050c822     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c825     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050c828     MOV        this,dword ptr [EBP + param_2]
    //         0050c82b     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050c82e     MOV        EAX,dword ptr [EAX + 0x50]
    //         0050c831     FLD        float ptr [EAX + EDX*0x4]
    //         0050c834     CALL       __ftol                                           undefined __ftol()
    //         0050c839     MOVSX      this,AX
    //         0050c83c     SUB        ESI,this
    //         0050c83e     MOV        DX,word ptr [EBP + local_c]
    //         0050c842     ADD        DX,SI
    //         0050c845     MOV        word ptr [EBP + local_c],DX
    //         0050c849     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c84c     MOV        this,dword ptr [EAX + 0xc]
    //         0050c84f     MOV        EDX,dword ptr [EBP + param_2]
    //         0050c852     MOVSX      EAX,word ptr [EDX]
    //         0050c855     MOV        this,dword ptr [this->tech_player_tree + 0x50]
    //         0050c858     FLD        float ptr [this->tech_player_tree + EAX*0x4]
    //         0050c85b     CALL       __ftol                                           undefined __ftol()
    //         0050c860     MOV        EDX,dword ptr [EBP + param_3]
    //         0050c863     MOV        word ptr [EDX],AX
    //                               LAB_0050c866                                                 XREF[4]:     0050c7bd(j), 0050c7d8(j), 
    //                                                                                                         0050c80e(j), 0050c81a(j)  
    //         0050c866     MOV        EAX,dword ptr [EBP + local_10]
    //         0050c869     XOR        this,this
    //         0050c86b     MOV        this,byte ptr [EAX + 0x1b]
    //         0050c86e     TEST       this,this
    //         0050c870     JZ         LAB_0050c91a
    //         0050c876     MOV        EDX,dword ptr [EBP + param_4]
    //         0050c879     MOV        EAX,dword ptr [EBP + local_10]
    //         0050c87c     MOV        this,word ptr [EAX + 0x10]
    //         0050c880     MOV        word ptr [EDX],this
    //         0050c883     MOV        EDX,dword ptr [EBP + param_4]
    //         0050c886     MOVSX      EAX,word ptr [EDX]
    //         0050c889     TEST       EAX,EAX
    //         0050c88b     JL         LAB_0050c91a
    //         0050c891     MOV        this,dword ptr [EBP + param_5]
    //         0050c894     MOV        EDX,dword ptr [EBP + local_10]
    //         0050c897     MOV        AX,word ptr [EDX + 0x16]
    //         0050c89b     MOV        word ptr [this->tech_player_tree],AX
    //         0050c89e     MOV        this,dword ptr [EBP + local_14]
    //         0050c8a1     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050c8a4     MOV        EAX,dword ptr [EBP + param_4]
    //         0050c8a7     MOVSX      this,word ptr [EAX]
    //         0050c8aa     MOV        EDX,dword ptr [EDX + 0x50]
    //         0050c8ad     MOV        EAX,dword ptr [EBP + param_5]
    //         0050c8b0     MOVSX      EAX,word ptr [EAX]
    //         0050c8b3     MOV        dword ptr [EBP + local_1c],EAX
    //         0050c8b6     FILD       dword ptr [EBP + local_1c]
    //         0050c8b9     FCOMP      float ptr [EDX + this->tech_player_tree*0x4]
    //         0050c8bc     FNSTSW     AX
    //         0050c8be     TEST       AH,0x41
    //         0050c8c1     JNZ        LAB_0050c91a
    //         0050c8c3     MOV        this,dword ptr [EBP + local_8]
    //         0050c8c6     AND        this,0xff
    //         0050c8cc     TEST       this,this
    //         0050c8ce     JZ         LAB_0050c91a
    //         0050c8d0     MOV        EDX,dword ptr [EBP + param_5]
    //         0050c8d3     MOVSX      ESI,word ptr [EDX]
    //         0050c8d6     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c8d9     MOV        this,dword ptr [EAX + 0xc]
    //         0050c8dc     MOV        EDX,dword ptr [EBP + param_4]
    //         0050c8df     MOVSX      EAX,word ptr [EDX]
    //         0050c8e2     MOV        this,dword ptr [this->tech_player_tree + 0x50]
    //         0050c8e5     FLD        float ptr [this->tech_player_tree + EAX*0x4]
    //         0050c8e8     CALL       __ftol                                           undefined __ftol()
    //         0050c8ed     MOVSX      EDX,AX
    //         0050c8f0     SUB        ESI,EDX
    //         0050c8f2     MOV        AX,word ptr [EBP + local_c]
    //         0050c8f6     ADD        AX,SI
    //         0050c8f9     MOV        word ptr [EBP + local_c],AX
    //         0050c8fd     MOV        this,dword ptr [EBP + local_14]
    //         0050c900     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050c903     MOV        EAX,dword ptr [EBP + param_4]
    //         0050c906     MOVSX      this,word ptr [EAX]
    //         0050c909     MOV        EDX,dword ptr [EDX + 0x50]
    //         0050c90c     FLD        float ptr [EDX + this->tech_player_tree*0x4]
    //         0050c90f     CALL       __ftol                                           undefined __ftol()
    //         0050c914     MOV        this,dword ptr [EBP + param_5]
    //         0050c917     MOV        word ptr [this->tech_player_tree],AX
    //                               LAB_0050c91a                                                 XREF[4]:     0050c870(j), 0050c88b(j), 
    //                                                                                                         0050c8c1(j), 0050c8ce(j)  
    //         0050c91a     MOV        EDX,dword ptr [EBP + local_10]
    //         0050c91d     XOR        EAX,EAX
    //         0050c91f     MOV        AL,byte ptr [EDX + 0x1c]
    //         0050c922     TEST       EAX,EAX
    //         0050c924     JZ         LAB_0050c9cd
    //         0050c92a     MOV        this,dword ptr [EBP + param_6]
    //         0050c92d     MOV        EDX,dword ptr [EBP + local_10]
    //         0050c930     MOV        AX,word ptr [EDX + 0x12]
    //         0050c934     MOV        word ptr [this->tech_player_tree],AX
    //         0050c937     MOV        this,dword ptr [EBP + param_6]
    //         0050c93a     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050c93d     TEST       EDX,EDX
    //         0050c93f     JL         LAB_0050c9cd
    //         0050c945     MOV        EAX,dword ptr [EBP + param_7]
    //         0050c948     MOV        this,dword ptr [EBP + local_10]
    //         0050c94b     MOV        DX,word ptr [this->tech_player_tree + 0x18]
    //         0050c94f     MOV        word ptr [EAX],DX
    //         0050c952     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c955     MOV        this,dword ptr [EAX + 0xc]
    //         0050c958     MOV        EDX,dword ptr [EBP + param_6]
    //         0050c95b     MOVSX      EAX,word ptr [EDX]
    //         0050c95e     MOV        this,dword ptr [this->tech_player_tree + 0x50]
    //         0050c961     MOV        EDX,dword ptr [EBP + param_7]
    //         0050c964     MOVSX      EDX,word ptr [EDX]
    //         0050c967     MOV        dword ptr [EBP + local_20],EDX
    //         0050c96a     FILD       dword ptr [EBP + local_20]
    //         0050c96d     FCOMP      float ptr [this->tech_player_tree + EAX*0x4]
    //         0050c970     FNSTSW     AX
    //         0050c972     TEST       AH,0x41
    //         0050c975     JNZ        LAB_0050c9cd
    //         0050c977     MOV        EAX,dword ptr [EBP + local_8]
    //         0050c97a     AND        EAX,0xff
    //         0050c97f     TEST       EAX,EAX
    //         0050c981     JZ         LAB_0050c9cd
    //         0050c983     MOV        this,dword ptr [EBP + param_7]
    //         0050c986     MOVSX      ESI,word ptr [this->tech_player_tree]
    //         0050c989     MOV        EDX,dword ptr [EBP + local_14]
    //         0050c98c     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050c98f     MOV        this,dword ptr [EBP + param_6]
    //         0050c992     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050c995     MOV        EAX,dword ptr [EAX + 0x50]
    //         0050c998     FLD        float ptr [EAX + EDX*0x4]
    //         0050c99b     CALL       __ftol                                           undefined __ftol()
    //         0050c9a0     MOVSX      this,AX
    //         0050c9a3     SUB        ESI,this
    //         0050c9a5     MOV        DX,word ptr [EBP + local_c]
    //         0050c9a9     ADD        DX,SI
    //         0050c9ac     MOV        word ptr [EBP + local_c],DX
    //         0050c9b0     MOV        EAX,dword ptr [EBP + local_14]
    //         0050c9b3     MOV        this,dword ptr [EAX + 0xc]
    //         0050c9b6     MOV        EDX,dword ptr [EBP + param_6]
    //         0050c9b9     MOVSX      EAX,word ptr [EDX]
    //         0050c9bc     MOV        this,dword ptr [this->tech_player_tree + 0x50]
    //         0050c9bf     FLD        float ptr [this->tech_player_tree + EAX*0x4]
    //         0050c9c2     CALL       __ftol                                           undefined __ftol()
    //         0050c9c7     MOV        EDX,dword ptr [EBP + param_7]
    //         0050c9ca     MOV        word ptr [EDX],AX
    //                               LAB_0050c9cd                                                 XREF[4]:     0050c924(j), 0050c93f(j), 
    //                                                                                                         0050c975(j), 0050c981(j)  
    //         0050c9cd     MOVSX      EAX,word ptr [EBP + local_c]
    //         0050c9d1     TEST       EAX,EAX
    //         0050c9d3     JLE        LAB_0050ca61
    //         0050c9d9     MOV        this,dword ptr [EBP + param_2]
    //         0050c9dc     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050c9df     CMP        EDX,0x3
    //         0050c9e2     JZ         LAB_0050c9ef
    //         0050c9e4     MOV        EAX,dword ptr [EBP + param_2]
    //         0050c9e7     MOVSX      this,word ptr [EAX]
    //         0050c9ea     CMP        this,-0x1
    //         0050c9ed     JNZ        LAB_0050ca09
    //                               LAB_0050c9ef                                                 XREF[1]:     0050c9e2(j)  
    //         0050c9ef     MOV        EDX,dword ptr [EBP + param_2]
    //         0050c9f2     MOV        word ptr [EDX],0x3
    //         0050c9f7     MOV        EAX,dword ptr [EBP + param_3]
    //         0050c9fa     MOV        this,word ptr [EAX]
    //         0050c9fd     ADD        this,word ptr [EBP + local_c]
    //         0050ca01     MOV        EDX,dword ptr [EBP + param_3]
    //         0050ca04     MOV        word ptr [EDX],this
    //         0050ca07     JMP        LAB_0050ca61
    //                               LAB_0050ca09                                                 XREF[1]:     0050c9ed(j)  
    //         0050ca09     MOV        EAX,dword ptr [EBP + param_4]
    //         0050ca0c     MOVSX      this,word ptr [EAX]
    //         0050ca0f     CMP        this,0x3
    //         0050ca12     JZ         LAB_0050ca1f
    //         0050ca14     MOV        EDX,dword ptr [EBP + param_4]
    //         0050ca17     MOVSX      EAX,word ptr [EDX]
    //         0050ca1a     CMP        EAX,-0x1
    //         0050ca1d     JNZ        LAB_0050ca39
    //                               LAB_0050ca1f                                                 XREF[1]:     0050ca12(j)  
    //         0050ca1f     MOV        this,dword ptr [EBP + param_4]
    //         0050ca22     MOV        word ptr [this->tech_player_tree],0x3
    //         0050ca27     MOV        EDX,dword ptr [EBP + param_5]
    //         0050ca2a     MOV        AX,word ptr [EDX]
    //         0050ca2d     ADD        AX,word ptr [EBP + local_c]
    //         0050ca31     MOV        this,dword ptr [EBP + param_5]
    //         0050ca34     MOV        word ptr [this->tech_player_tree],AX
    //         0050ca37     JMP        LAB_0050ca61
    //                               LAB_0050ca39                                                 XREF[1]:     0050ca1d(j)  
    //         0050ca39     MOV        EDX,dword ptr [EBP + param_6]
    //         0050ca3c     MOVSX      EAX,word ptr [EDX]
    //         0050ca3f     CMP        EAX,0x3
    //         0050ca42     JZ         LAB_0050ca4f
    //         0050ca44     MOV        this,dword ptr [EBP + param_6]
    //         0050ca47     MOVSX      EDX,word ptr [this->tech_player_tree]
    //         0050ca4a     CMP        EDX,-0x1
    //         0050ca4d     JNZ        LAB_0050ca61
    //                               LAB_0050ca4f                                                 XREF[1]:     0050ca42(j)  
    //         0050ca4f     MOV        EAX,dword ptr [EBP + param_6]
    //         0050ca52     MOV        word ptr [EAX],0x3
    //         0050ca57     MOV        this,dword ptr [EBP + param_7]
    //         0050ca5a     MOV        DX,word ptr [EBP + local_c]
    //         0050ca5e     MOV        word ptr [this->tech_player_tree],DX
    //                               LAB_0050ca61                                                 XREF[4]:     0050c9d3(j), 0050ca07(j), 
    //                                                                                                         0050ca37(j), 0050ca4d(j)  
    //         0050ca61     MOV        EAX,dword ptr [EBP + param_3]
    //         0050ca64     MOVSX      this,word ptr [EAX]
    //         0050ca67     TEST       this,this
    //         0050ca69     JG         LAB_0050ca73
    //         0050ca6b     MOV        EDX,dword ptr [EBP + param_2]
    //         0050ca6e     MOV        word ptr [EDX],0xffff
    //                               LAB_0050ca73                                                 XREF[1]:     0050ca69(j)  
    //         0050ca73     MOV        EAX,dword ptr [EBP + param_5]
    //         0050ca76     MOVSX      this,word ptr [EAX]
    //         0050ca79     TEST       this,this
    //         0050ca7b     JG         LAB_0050ca85
    //         0050ca7d     MOV        EDX,dword ptr [EBP + param_4]
    //         0050ca80     MOV        word ptr [EDX],0xffff
    //                               LAB_0050ca85                                                 XREF[1]:     0050ca7b(j)  
    //         0050ca85     MOV        EAX,dword ptr [EBP + param_7]
    //         0050ca88     MOVSX      this,word ptr [EAX]
    //         0050ca8b     TEST       this,this
    //         0050ca8d     JG         LAB_0050ca97
    //         0050ca8f     MOV        EDX,dword ptr [EBP + param_6]
    //         0050ca92     MOV        word ptr [EDX],0xffff
    //                               LAB_0050ca97                                                 XREF[1]:     0050ca8d(j)  
    //         0050ca97     POP        ESI
    //         0050ca98     MOV        ESP,EBP
    //         0050ca9a     POP        EBP
    //         0050ca9b     RET        0x1c
}

// Offset: 0x0050CA9E
uchar check_tech_cost(TRIBE_Player_Tech* this_, short param_2, short* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::check_tech_cost(short,short *)                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_tech_cost(TRIBE_Player_Tech * this, short par
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050caad(R), 0050caf4(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[6]:     0050cb91(R), 0050cb97(R), 0050cbda(R), 0050cbe0(R), 
    //                                                                                     0050cc0f(R), 0050cc15(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050caea(W), 0050caf0(W), 0050cb66(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0050cb63(W), 0050cb7b(R), 0050cbb4(R), 0050cbd0(R), 
    //                                                                                     0050cbfa(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[8]:     0050cac7(W), 0050cae3(W), 0050cb78(R), 0050cb7e(W), 
    //                                                                                     0050cb81(R), 0050cbca(R), 0050cc00(R), 0050cc03(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     0050cab8(W), 0050cb2a(R), 0050cb3f(R), 0050cb55(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[8]:     0050cb32(W), 0050cb35(R), 0050cb72(R), 0050cb9a(R), 
    //                                                                                     0050cbae(R), 0050cbc7(R), 0050cbe3(R), 0050cbf7(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[7]:     0050cb0b(W), 0050cb14(R), 0050cb1a(W), 0050cb1d(R), 
    //                                                                                     0050cb27(R), 0050cb42(R), 0050cb52(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[8]:     0050caa4(W), 0050caa7(R), 0050cabb(R), 0050caca(R), 
    //                                                                                     0050caf8(R), 0050cba5(R), 0050cbbe(R), 0050cbee(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[2]:     0050cb5d(W), 0050cb60(R)  
    //                               ?check_tech_cost@TRIBE_Player_Tech@@QAEEFPAF@Z               XREF[3]:     tech_cost:0050c78e(c), 
    //                               TRIBE_Player_Tech::check_tech_cost                                        start_research:0050cc4e(c), 
    //                                                                                                         check_tech_cost:00513d70(c)  
    //         0050ca9e     PUSH       EBP
    //         0050ca9f     MOV        EBP,ESP
    //         0050caa1     SUB        ESP,0x20
    //         0050caa4     MOV        dword ptr [EBP + local_20],this
    //         0050caa7     MOV        EAX,dword ptr [EBP + local_20]
    //         0050caaa     MOV        this,dword ptr [EAX + 0x8]
    //         0050caad     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050cab1     IMUL       EDX,EDX,0x3c
    //         0050cab4     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050cab6     ADD        EAX,EDX
    //         0050cab8     MOV        dword ptr [EBP + local_14],EAX
    //         0050cabb     MOV        this,dword ptr [EBP + local_20]
    //         0050cabe     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050cac1     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050cac4     MOV        this,dword ptr [EAX + 0xc]
    //         0050cac7     MOV        dword ptr [EBP + local_10],this
    //         0050caca     MOV        EDX,dword ptr [EBP + local_20]
    //         0050cacd     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050cad0     MOV        this,dword ptr [EAX + 0x50]
    //         0050cad3     FLD        float ptr [this->tech_player_tree + 0x74]
    //         0050cad6     FCOMP      double ptr [DAT_005766c8]
    //         0050cadc     FNSTSW     AX
    //         0050cade     TEST       AH,0x1
    //         0050cae1     JZ         LAB_0050caf0
    //         0050cae3     MOV        dword ptr [EBP + local_10],0x0
    //         0050caea     MOV        byte ptr [EBP + local_8],0x0
    //         0050caee     JMP        LAB_0050caf4
    //                               LAB_0050caf0                                                 XREF[1]:     0050cae1(j)  
    //         0050caf0     MOV        byte ptr [EBP + local_8],0x1
    //                               LAB_0050caf4                                                 XREF[1]:     0050caee(j)  
    //         0050caf4     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050caf8     MOV        EAX,dword ptr [EBP + local_20]
    //         0050cafb     MOV        this,dword ptr [EAX]
    //         0050cafd     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050cb02     CMP        EDX,0x1
    //         0050cb05     JNZ        LAB_0050cc0f
    //         0050cb0b     MOV        dword ptr [EBP + local_1c],0x0
    //         0050cb12     JMP        LAB_0050cb1d
    //                               LAB_0050cb14                                                 XREF[1]:     0050cc06(j)  
    //         0050cb14     MOV        EAX,dword ptr [EBP + local_1c]
    //         0050cb17     ADD        EAX,0x1
    //         0050cb1a     MOV        dword ptr [EBP + local_1c],EAX
    //                               LAB_0050cb1d                                                 XREF[1]:     0050cb12(j)  
    //         0050cb1d     CMP        dword ptr [EBP + local_1c],0x3
    //         0050cb21     JGE        LAB_0050cc0b
    //         0050cb27     MOV        this,dword ptr [EBP + local_1c]
    //         0050cb2a     MOV        EDX,dword ptr [EBP + local_14]
    //         0050cb2d     MOVSX      EAX,word ptr [EDX + this->tech_player_tree*0x2
    //         0050cb32     MOV        dword ptr [EBP + local_18],EAX
    //         0050cb35     CMP        dword ptr [EBP + local_18],0x0
    //         0050cb39     JL         LAB_0050cc06
    //         0050cb3f     MOV        this,dword ptr [EBP + local_14]
    //         0050cb42     ADD        this,dword ptr [EBP + local_1c]
    //         0050cb45     XOR        EDX,EDX
    //         0050cb47     MOV        DL,byte ptr [this->tech_player_tree + 0x1a]
    //         0050cb4a     TEST       EDX,EDX
    //         0050cb4c     JZ         LAB_0050cc06
    //         0050cb52     MOV        EAX,dword ptr [EBP + local_1c]
    //         0050cb55     MOV        this,dword ptr [EBP + local_14]
    //         0050cb58     MOVSX      EDX,word ptr [this->tech_player_tree + EAX*0x2
    //         0050cb5d     MOV        dword ptr [EBP + local_24],EDX
    //         0050cb60     FILD       dword ptr [EBP + local_24]
    //         0050cb63     FSTP       float ptr [EBP + local_c]
    //         0050cb66     MOV        EAX,dword ptr [EBP + local_8]
    //         0050cb69     AND        EAX,0xff
    //         0050cb6e     TEST       EAX,EAX
    //         0050cb70     JZ         LAB_0050cba5
    //         0050cb72     CMP        dword ptr [EBP + local_18],0x3
    //         0050cb76     JNZ        LAB_0050cba5
    //         0050cb78     FLD        float ptr [EBP + local_10]
    //         0050cb7b     FSUB       float ptr [EBP + local_c]
    //         0050cb7e     FSTP       float ptr [EBP + local_10]
    //         0050cb81     FLD        float ptr [EBP + local_10]
    //         0050cb84     FCOMP      float ptr [DAT_005766d0]
    //         0050cb8a     FNSTSW     AX
    //         0050cb8c     TEST       AH,0x1
    //         0050cb8f     JZ         LAB_0050cba5
    //         0050cb91     CMP        dword ptr [EBP + param_2],0x0
    //         0050cb95     JZ         LAB_0050cba1
    //         0050cb97     MOV        this,dword ptr [EBP + param_2]
    //         0050cb9a     MOV        DX,word ptr [EBP + local_18]
    //         0050cb9e     MOV        word ptr [this->tech_player_tree],DX
    //                               LAB_0050cba1                                                 XREF[1]:     0050cb95(j)  
    //         0050cba1     XOR        AL,AL
    //         0050cba3     JMP        LAB_0050cc1f
    //                               LAB_0050cba5                                                 XREF[3]:     0050cb70(j), 0050cb76(j), 
    //                                                                                                         0050cb8f(j)  
    //         0050cba5     MOV        EAX,dword ptr [EBP + local_20]
    //         0050cba8     MOV        this,dword ptr [EAX + 0xc]
    //         0050cbab     MOV        EDX,dword ptr [this->tech_player_tree + 0x50]
    //         0050cbae     MOV        EAX,dword ptr [EBP + local_18]
    //         0050cbb1     FLD        float ptr [EDX + EAX*0x4]
    //         0050cbb4     FCOMP      float ptr [EBP + local_c]
    //         0050cbb7     FNSTSW     AX
    //         0050cbb9     TEST       AH,0x1
    //         0050cbbc     JZ         LAB_0050cc06
    //         0050cbbe     MOV        this,dword ptr [EBP + local_20]
    //         0050cbc1     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050cbc4     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050cbc7     MOV        this,dword ptr [EBP + local_18]
    //         0050cbca     FLD        float ptr [EBP + local_10]
    //         0050cbcd     FADD       float ptr [EAX + this->tech_player_tree*0x4]
    //         0050cbd0     FCOMP      float ptr [EBP + local_c]
    //         0050cbd3     FNSTSW     AX
    //         0050cbd5     TEST       AH,0x1
    //         0050cbd8     JZ         LAB_0050cbee
    //         0050cbda     CMP        dword ptr [EBP + param_2],0x0
    //         0050cbde     JZ         LAB_0050cbea
    //         0050cbe0     MOV        EDX,dword ptr [EBP + param_2]
    //         0050cbe3     MOV        AX,word ptr [EBP + local_18]
    //         0050cbe7     MOV        word ptr [EDX],AX
    //                               LAB_0050cbea                                                 XREF[1]:     0050cbde(j)  
    //         0050cbea     XOR        AL,AL
    //         0050cbec     JMP        LAB_0050cc1f
    //                               LAB_0050cbee                                                 XREF[1]:     0050cbd8(j)  
    //         0050cbee     MOV        this,dword ptr [EBP + local_20]
    //         0050cbf1     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050cbf4     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050cbf7     MOV        this,dword ptr [EBP + local_18]
    //         0050cbfa     FLD        float ptr [EBP + local_c]
    //         0050cbfd     FSUB       float ptr [EAX + this->tech_player_tree*0x4]
    //         0050cc00     FSUBR      float ptr [EBP + local_10]
    //         0050cc03     FSTP       float ptr [EBP + local_10]
    //                               LAB_0050cc06                                                 XREF[3]:     0050cb39(j), 0050cb4c(j), 
    //                                                                                                         0050cbbc(j)  
    //         0050cc06     JMP        LAB_0050cb14
    //                               LAB_0050cc0b                                                 XREF[1]:     0050cb21(j)  
    //         0050cc0b     MOV        AL,0x1
    //         0050cc0d     JMP        LAB_0050cc1f
    //                               LAB_0050cc0f                                                 XREF[1]:     0050cb05(j)  
    //         0050cc0f     CMP        dword ptr [EBP + param_2],0x0
    //         0050cc13     JZ         LAB_0050cc1d
    //         0050cc15     MOV        EDX,dword ptr [EBP + param_2]
    //         0050cc18     MOV        word ptr [EDX],0xffff
    //                               LAB_0050cc1d                                                 XREF[1]:     0050cc13(j)  
    //         0050cc1d     XOR        AL,AL
    //                               LAB_0050cc1f                                                 XREF[3]:     0050cba3(j), 0050cbec(j), 
    //                                                                                                         0050cc0d(j)  
    //         0050cc1f     MOV        ESP,EBP
    //         0050cc21     POP        EBP
    //         0050cc22     RET        0x8
}

// Offset: 0x0050CC25
uchar start_research(TRIBE_Player_Tech* this_, short param_2, uchar param_3, short* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::start_research(short,unsigned char,short *)       *
    //                              *********************************************************************************************************
    //                              uchar __thiscall start_research(TRIBE_Player_Tech * this, short para
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050cc34(R), 0050cc46(R), 0050cd49(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050cc60(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[3]:     0050cc42(R), 0050cd5d(R), 0050cd63(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     0050ccc8(W), 0050ccda(R), 0050ccf9(R), 0050cd32(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     0050cc3f(W), 0050cc8f(R), 0050cca4(R), 0050ccba(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[7]:     0050cc97(W), 0050cc9a(R), 0050ccd4(R), 0050ccf6(R), 
    //                                                                                     0050cd17(R), 0050cd2c(R), 0050cd3e(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[7]:     0050cc70(W), 0050cc79(R), 0050cc7f(W), 0050cc82(R), 
    //                                                                                     0050cc8c(R), 0050cca7(R), 0050ccb7(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[11]:    0050cc2b(W), 0050cc2e(R), 0050cc4b(R), 0050cccb(R), 
    //                                                                                     0050cce4(R), 0050cced(R), 0050cd02(R), 0050cd0e(R), 
    //                                                                                     0050cd23(R), 0050cd35(R), 0050cd4d(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     0050ccc2(W), 0050ccc5(R)  
    //                               ?start_research@TRIBE_Player_Tech@@QAEEFEPAF@Z               XREF[2]:     first_in_stack:004d23d9(c), 
    //                               TRIBE_Player_Tech::start_research                                         pay_tech_cost:00513d8f(c)  
    //         0050cc25     PUSH       EBP
    //         0050cc26     MOV        EBP,ESP
    //         0050cc28     SUB        ESP,0x18
    //         0050cc2b     MOV        dword ptr [EBP + local_18],this
    //         0050cc2e     MOV        EAX,dword ptr [EBP + local_18]
    //         0050cc31     MOV        this,dword ptr [EAX + 0x8]
    //         0050cc34     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050cc38     IMUL       EDX,EDX,0x3c
    //         0050cc3b     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050cc3d     ADD        EAX,EDX
    //         0050cc3f     MOV        dword ptr [EBP + local_c],EAX
    //         0050cc42     MOV        this,dword ptr [EBP + param_3]
    //         0050cc45     PUSH       this
    //         0050cc46     MOV        DX,word ptr [EBP + param_1]
    //         0050cc4a     PUSH       EDX
    //         0050cc4b     MOV        this,dword ptr [EBP + local_18]
    //         0050cc4e     CALL       TRIBE_Player_Tech::check_tech_cost               uchar check_tech_cost(TRIBE_Player_Tech * thi
    //         0050cc53     AND        EAX,0xff
    //         0050cc58     TEST       EAX,EAX
    //         0050cc5a     JZ         LAB_0050cd5d
    //         0050cc60     MOV        EAX,dword ptr [EBP + param_2]
    //         0050cc63     AND        EAX,0xff
    //         0050cc68     TEST       EAX,EAX
    //         0050cc6a     JZ         LAB_0050cd59
    //         0050cc70     MOV        dword ptr [EBP + local_14],0x0
    //         0050cc77     JMP        LAB_0050cc82
    //                               LAB_0050cc79                                                 XREF[1]:     0050cd44(j)  
    //         0050cc79     MOV        this,dword ptr [EBP + local_14]
    //         0050cc7c     ADD        this,0x1
    //         0050cc7f     MOV        dword ptr [EBP + local_14],this
    //                               LAB_0050cc82                                                 XREF[1]:     0050cc77(j)  
    //         0050cc82     CMP        dword ptr [EBP + local_14],0x3
    //         0050cc86     JGE        LAB_0050cd49
    //         0050cc8c     MOV        EDX,dword ptr [EBP + local_14]
    //         0050cc8f     MOV        EAX,dword ptr [EBP + local_c]
    //         0050cc92     MOVSX      this,word ptr [EAX + EDX*0x2 + 0xe]
    //         0050cc97     MOV        dword ptr [EBP + local_10],this
    //         0050cc9a     CMP        dword ptr [EBP + local_10],0x0
    //         0050cc9e     JL         LAB_0050cd44
    //         0050cca4     MOV        EDX,dword ptr [EBP + local_c]
    //         0050cca7     ADD        EDX,dword ptr [EBP + local_14]
    //         0050ccaa     XOR        EAX,EAX
    //         0050ccac     MOV        AL,byte ptr [EDX + 0x1a]
    //         0050ccaf     TEST       EAX,EAX
    //         0050ccb1     JZ         LAB_0050cd44
    //         0050ccb7     MOV        this,dword ptr [EBP + local_14]
    //         0050ccba     MOV        EDX,dword ptr [EBP + local_c]
    //         0050ccbd     MOVSX      EAX,word ptr [EDX + this->tech_player_tree*0x2
    //         0050ccc2     MOV        dword ptr [EBP + local_1c],EAX
    //         0050ccc5     FILD       dword ptr [EBP + local_1c]
    //         0050ccc8     FSTP       float ptr [EBP + local_8]
    //         0050cccb     MOV        this,dword ptr [EBP + local_18]
    //         0050ccce     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050ccd1     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050ccd4     MOV        this,dword ptr [EBP + local_10]
    //         0050ccd7     FLD        float ptr [EAX + this->tech_player_tree*0x4]
    //         0050ccda     FCOMP      float ptr [EBP + local_8]
    //         0050ccdd     FNSTSW     AX
    //         0050ccdf     TEST       AH,0x1
    //         0050cce2     JZ         LAB_0050cd23
    //         0050cce4     MOV        EDX,dword ptr [EBP + local_18]
    //         0050cce7     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050ccea     MOV        this,dword ptr [EAX + 0x50]
    //         0050cced     MOV        EDX,dword ptr [EBP + local_18]
    //         0050ccf0     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050ccf3     MOV        EDX,dword ptr [EAX + 0x50]
    //         0050ccf6     MOV        EAX,dword ptr [EBP + local_10]
    //         0050ccf9     FLD        float ptr [EBP + local_8]
    //         0050ccfc     FSUB       float ptr [EDX + EAX*0x4]
    //         0050ccff     FSUBR      float ptr [ECX + this->owner]
    //         0050cd02     MOV        this,dword ptr [EBP + local_18]
    //         0050cd05     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050cd08     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050cd0b     FSTP       float ptr [EAX + 0xc]
    //         0050cd0e     MOV        this,dword ptr [EBP + local_18]
    //         0050cd11     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050cd14     MOV        EAX,dword ptr [EDX + 0x50]
    //         0050cd17     MOV        this,dword ptr [EBP + local_10]
    //         0050cd1a     MOV        dword ptr [EAX + this->tech_player_tree*0x4],0x0
    //         0050cd21     JMP        LAB_0050cd44
    //                               LAB_0050cd23                                                 XREF[1]:     0050cce2(j)  
    //         0050cd23     MOV        EDX,dword ptr [EBP + local_18]
    //         0050cd26     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050cd29     MOV        this,dword ptr [EAX + 0x50]
    //         0050cd2c     MOV        EDX,dword ptr [EBP + local_10]
    //         0050cd2f     FLD        float ptr [this->tech_player_tree + EDX*0x4]
    //         0050cd32     FSUB       float ptr [EBP + local_8]
    //         0050cd35     MOV        EAX,dword ptr [EBP + local_18]
    //         0050cd38     MOV        this,dword ptr [EAX + 0xc]
    //         0050cd3b     MOV        EDX,dword ptr [this->tech_player_tree + 0x50]
    //         0050cd3e     MOV        EAX,dword ptr [EBP + local_10]
    //         0050cd41     FSTP       float ptr [EDX + EAX*0x4]
    //                               LAB_0050cd44                                                 XREF[3]:     0050cc9e(j), 0050ccb1(j), 
    //                                                                                                         0050cd21(j)  
    //         0050cd44     JMP        LAB_0050cc79
    //                               LAB_0050cd49                                                 XREF[1]:     0050cc86(j)  
    //         0050cd49     MOVSX      this,word ptr [EBP + param_1]
    //         0050cd4d     MOV        EDX,dword ptr [EBP + local_18]
    //         0050cd50     MOV        EAX,dword ptr [EDX]
    //         0050cd52     MOV        word ptr [EAX + this->tech_player_tree*0x8 + 0
    //                               LAB_0050cd59                                                 XREF[1]:     0050cc6a(j)  
    //         0050cd59     MOV        AL,0x1
    //         0050cd5b     JMP        LAB_0050cd6d
    //                               LAB_0050cd5d                                                 XREF[1]:     0050cc5a(j)  
    //         0050cd5d     CMP        dword ptr [EBP + param_3],0x0
    //         0050cd61     JZ         LAB_0050cd6b
    //         0050cd63     MOV        this,dword ptr [EBP + param_3]
    //         0050cd66     MOV        word ptr [this->tech_player_tree],0xffff
    //                               LAB_0050cd6b                                                 XREF[1]:     0050cd61(j)  
    //         0050cd6b     XOR        AL,AL
    //                               LAB_0050cd6d                                                 XREF[1]:     0050cd5b(j)  
    //         0050cd6d     MOV        ESP,EBP
    //         0050cd6f     POP        EBP
    //         0050cd70     RET        0xc
}

// Offset: 0x0050CD73
uchar cancel_research(TRIBE_Player_Tech* this_, short param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::cancel_research(short,unsigned char)              *
    //                              *********************************************************************************************************
    //                              uchar __thiscall cancel_research(TRIBE_Player_Tech * this, short par
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[4]:     0050cd83(R), 0050cd91(R), 0050ce3b(R), 0050ce4b(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050cda8(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[6]:     0050cd8e(W), 0050cdda(R), 0050cdea(R), 0050ce01(R), 
    //                                                                                     0050ce10(R), 0050ce2b(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[9]:     0050cdb9(W), 0050cdc1(R), 0050cdc9(W), 0050cdcd(R), 
    //                                                                                     0050cdd6(R), 0050cde6(R), 0050cdfd(R), 0050ce0c(R), 
    //                                                                                     0050ce27(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[7]:     0050cd7a(W), 0050cd7d(R), 0050cd95(R), 0050cdf7(R), 
    //                                                                                     0050ce21(R), 0050ce3f(R), 0050ce4f(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0050ce18(W), 0050ce1b(R)  
    //                               ?cancel_research@TRIBE_Player_Tech@@QAEEFE@Z                 XREF[2]:     ~TRIBE_Action_Make_Tech:004d22d9(c
    //                               TRIBE_Player_Tech::cancel_research                                        stop:004d256e(c)  
    //         0050cd73     PUSH       EBP
    //         0050cd74     MOV        EBP,ESP
    //         0050cd76     SUB        ESP,0x10
    //         0050cd79     PUSH       ESI
    //         0050cd7a     MOV        dword ptr [EBP + local_10],this
    //         0050cd7d     MOV        EAX,dword ptr [EBP + local_10]
    //         0050cd80     MOV        this,dword ptr [EAX + 0x8]
    //         0050cd83     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050cd87     IMUL       EDX,EDX,0x3c
    //         0050cd8a     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050cd8c     ADD        EAX,EDX
    //         0050cd8e     MOV        dword ptr [EBP + local_8],EAX
    //         0050cd91     MOVSX      this,word ptr [EBP + param_1]
    //         0050cd95     MOV        EDX,dword ptr [EBP + local_10]
    //         0050cd98     MOV        EAX,dword ptr [EDX]
    //         0050cd9a     MOVSX      this,word ptr [EAX + this->tech_player_tree*0x
    //         0050cd9f     CMP        this,0x2
    //         0050cda2     JNZ        LAB_0050ce5f
    //         0050cda8     MOV        EDX,dword ptr [EBP + param_2]
    //         0050cdab     AND        EDX,0xff
    //         0050cdb1     TEST       EDX,EDX
    //         0050cdb3     JZ         LAB_0050ce3b
    //         0050cdb9     MOV        word ptr [EBP + local_c],0x0
    //         0050cdbf     JMP        LAB_0050cdcd
    //                               LAB_0050cdc1                                                 XREF[1]:     0050ce39(j)  
    //         0050cdc1     MOV        AX,word ptr [EBP + local_c]
    //         0050cdc5     ADD        AX,0x1
    //         0050cdc9     MOV        word ptr [EBP + local_c],AX
    //                               LAB_0050cdcd                                                 XREF[1]:     0050cdbf(j)  
    //         0050cdcd     MOVSX      this,word ptr [EBP + local_c]
    //         0050cdd1     CMP        this,0x3
    //         0050cdd4     JGE        LAB_0050ce3b
    //         0050cdd6     MOVSX      EDX,word ptr [EBP + local_c]
    //         0050cdda     MOV        EAX,dword ptr [EBP + local_8]
    //         0050cddd     MOVSX      this,word ptr [EAX + EDX*0x2 + 0xe]
    //         0050cde2     TEST       this,this
    //         0050cde4     JL         LAB_0050ce39
    //         0050cde6     MOVSX      EDX,word ptr [EBP + local_c]
    //         0050cdea     MOV        EAX,dword ptr [EBP + local_8]
    //         0050cded     XOR        this,this
    //         0050cdef     MOV        this,byte ptr [EAX + EDX*0x1 + 0x1a]
    //         0050cdf3     TEST       this,this
    //         0050cdf5     JZ         LAB_0050ce39
    //         0050cdf7     MOV        EDX,dword ptr [EBP + local_10]
    //         0050cdfa     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050cdfd     MOVSX      this,word ptr [EBP + local_c]
    //         0050ce01     MOV        EDX,dword ptr [EBP + local_8]
    //         0050ce04     MOVSX      this,word ptr [EDX + this->tech_player_tree*0x
    //         0050ce09     MOV        EDX,dword ptr [EAX + 0x50]
    //         0050ce0c     MOVSX      EAX,word ptr [EBP + local_c]
    //         0050ce10     MOV        ESI,dword ptr [EBP + local_8]
    //         0050ce13     MOVSX      EAX,word ptr [ESI + EAX*0x2 + 0x14]
    //         0050ce18     MOV        dword ptr [EBP + local_14],EAX
    //         0050ce1b     FILD       dword ptr [EBP + local_14]
    //         0050ce1e     FADD       float ptr [EDX + this->tech_player_tree*0x4]
    //         0050ce21     MOV        this,dword ptr [EBP + local_10]
    //         0050ce24     MOV        EDX,dword ptr [ECX + this->owner]
    //         0050ce27     MOVSX      EAX,word ptr [EBP + local_c]
    //         0050ce2b     MOV        this,dword ptr [EBP + local_8]
    //         0050ce2e     MOVSX      EAX,word ptr [ECX + EAX*0x2 + this+0xe]
    //         0050ce33     MOV        this,dword ptr [EDX + 0x50]
    //         0050ce36     FSTP       float ptr [this->tech_player_tree + EAX*0x4]
    //                               LAB_0050ce39                                                 XREF[2]:     0050cde4(j), 0050cdf5(j)  
    //         0050ce39     JMP        LAB_0050cdc1
    //                               LAB_0050ce3b                                                 XREF[2]:     0050cdb3(j), 0050cdd4(j)  
    //         0050ce3b     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050ce3f     MOV        EAX,dword ptr [EBP + local_10]
    //         0050ce42     MOV        this,dword ptr [EAX]
    //         0050ce44     MOV        word ptr [ECX + EDX*0x8 + this->tech_player_tr
    //         0050ce4b     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050ce4f     MOV        EAX,dword ptr [EBP + local_10]
    //         0050ce52     MOV        this,dword ptr [EAX]
    //         0050ce54     MOV        dword ptr [this->tech_player_tree + EDX*0x8],0x0
    //         0050ce5b     MOV        AL,0x1
    //         0050ce5d     JMP        LAB_0050ce61
    //                               LAB_0050ce5f                                                 XREF[1]:     0050cda2(j)  
    //         0050ce5f     XOR        AL,AL
    //                               LAB_0050ce61                                                 XREF[1]:     0050ce5d(j)  
    //         0050ce61     POP        ESI
    //         0050ce62     MOV        ESP,EBP
    //         0050ce64     POP        EBP
    //         0050ce65     RET        0x8
}

// Offset: 0x0050CE68
uchar check_for_new_tech(TRIBE_Player_Tech* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::check_for_new_tech(void)                          *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_for_new_tech(TRIBE_Player_Tech * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050ce82(W), 0050d02d(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[8]:     0050ce71(W), 0050cedb(R), 0050cee3(W), 0050cfb2(R), 
    //                                                                                     0050cfba(W), 0050d01c(R), 0050d024(W), 0050d03d(R)  
    //              undefined2        Stack[-0x10]:2 local_10                  XREF[3]:     0050ceeb(W), 0050cf27(R), 0050cf2f(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     0050cee7(W), 0050cf57(R), 0050cf5c(W), 0050cf61(R)  
    //              undefined2        Stack[-0x18]:2 local_18                  XREF[6]:     0050cef1(W), 0050cef9(R), 0050cf01(W), 0050cf05(R), 
    //                                                                                     0050cf1a(R), 0050cf3f(R)  
    //              undefined2        Stack[-0x1c]:2 local_1c                  XREF[17]:    0050ce86(W), 0050ce8e(R), 0050ce96(W), 0050ce9a(R), 
    //                                                                                     0050cead(R), 0050cec4(R), 0050cf0e(R), 0050cf33(R), 
    //                                                                                     0050cf6a(R), 0050cf7d(R), 0050cf92(R), 0050cfa5(R), 
    //                                                                                     0050cfc0(R), 0050cfd3(R), 0050cfe5(R), 0050cff7(R), 
    //                                                                                     0050d009(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[5]:     0050ce7f(W), 0050cf15(R), 0050cf3a(R), 0050cf71(R), 
    //                                                                                     0050cf84(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[15]:    0050ce6e(W), 0050ce77(R), 0050ce9e(R), 0050ceb1(R), 
    //                                                                                     0050cec8(R), 0050cf48(R), 0050cf96(R), 0050cfaa(R), 
    //                                                                                     0050cfc4(R), 0050cfd7(R), 0050cfe9(R), 0050cffb(R), 
    //                                                                                     0050d00d(R), 0050d045(R), 0050d061(R)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[2]:     0050cf8c(W), 0050cf8f(R)  
    //                               ?check_for_new_tech@TRIBE_Player_Tech@@QAEEXZ                XREF[6]:     TRIBE_Player_Tech:0050c4ee(c), 
    //                               TRIBE_Player_Tech::check_for_new_tech                                     TRIBE_Player_Tech:0050c554(c), 
    //                                                                                                         undo_tech:0050c5d4(c), 
    //                                                                                                         do_tech:0050c644(c), 
    //                                                                                                         scenario_load:00512887(c), 
    //                                                                                                         set_player_tech:0052c355(c)  
    //         0050ce68     PUSH       EBP
    //         0050ce69     MOV        EBP,ESP
    //         0050ce6b     SUB        ESP,0x24
    //         0050ce6e     MOV        dword ptr [EBP + local_24],this
    //         0050ce71     MOV        word ptr [EBP + local_c],0x0
    //         0050ce77     MOV        EAX,dword ptr [EBP + local_24]
    //         0050ce7a     MOV        this,dword ptr [EAX + 0x8]
    //         0050ce7d     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050ce7f     MOV        dword ptr [EBP + local_20],EDX
    //                               LAB_0050ce82                                                 XREF[1]:     0050d037(j)  
    //         0050ce82     MOV        byte ptr [EBP + local_8],0x0
    //         0050ce86     MOV        word ptr [EBP + local_1c],0x0
    //         0050ce8c     JMP        LAB_0050ce9a
    //                               LAB_0050ce8e                                                 XREF[1]:     0050d028(j)  
    //         0050ce8e     MOV        AX,word ptr [EBP + local_1c]
    //         0050ce92     ADD        AX,0x1
    //         0050ce96     MOV        word ptr [EBP + local_1c],AX
    //                               LAB_0050ce9a                                                 XREF[1]:     0050ce8c(j)  
    //         0050ce9a     MOVSX      this,word ptr [EBP + local_1c]
    //         0050ce9e     MOV        EDX,dword ptr [EBP + local_24]
    //         0050cea1     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050cea5     CMP        this,EAX
    //         0050cea7     JGE        LAB_0050d02d
    //         0050cead     MOVSX      this,word ptr [EBP + local_1c]
    //         0050ceb1     MOV        EDX,dword ptr [EBP + local_24]
    //         0050ceb4     MOV        EAX,dword ptr [EDX]
    //         0050ceb6     MOVSX      this,word ptr [EAX + this->tech_player_tree*0x
    //         0050cebb     CMP        this,0x2
    //         0050cebe     JGE        LAB_0050d009
    //         0050cec4     MOVSX      EDX,word ptr [EBP + local_1c]
    //         0050cec8     MOV        EAX,dword ptr [EBP + local_24]
    //         0050cecb     MOV        this,dword ptr [EAX]
    //         0050cecd     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050ced2     CMP        EDX,-0x1
    //         0050ced5     JLE        LAB_0050d009
    //         0050cedb     MOV        AX,word ptr [EBP + local_c]
    //         0050cedf     ADD        AX,0x1
    //         0050cee3     MOV        word ptr [EBP + local_c],AX
    //         0050cee7     MOV        byte ptr [EBP + local_14],0x0
    //         0050ceeb     MOV        word ptr [EBP + local_10],0x0
    //         0050cef1     MOV        word ptr [EBP + local_18],0x0
    //         0050cef7     JMP        LAB_0050cf05
    //                               LAB_0050cef9                                                 XREF[1]:     0050cf5f(j)  
    //         0050cef9     MOV        this,word ptr [EBP + local_18]
    //         0050cefd     ADD        this,0x1
    //         0050cf01     MOV        word ptr [EBP + local_18],this
    //                               LAB_0050cf05                                                 XREF[1]:     0050cef7(j)  
    //         0050cf05     MOVSX      EDX,word ptr [EBP + local_18]
    //         0050cf09     CMP        EDX,0x4
    //         0050cf0c     JGE        LAB_0050cf61
    //         0050cf0e     MOVSX      EAX,word ptr [EBP + local_1c]
    //         0050cf12     IMUL       EAX,EAX,0x3c
    //         0050cf15     MOV        this,dword ptr [EBP + local_20]
    //         0050cf18     ADD        this,EAX
    //         0050cf1a     MOVSX      EDX,word ptr [EBP + local_18]
    //         0050cf1e     MOVSX      EAX,word ptr [ECX + EDX*0x2 + this->tech_playe
    //         0050cf23     TEST       EAX,EAX
    //         0050cf25     JL         LAB_0050cf5f
    //         0050cf27     MOV        this,word ptr [EBP + local_10]
    //         0050cf2b     ADD        this,0x1
    //         0050cf2f     MOV        word ptr [EBP + local_10],this
    //         0050cf33     MOVSX      EDX,word ptr [EBP + local_1c]
    //         0050cf37     IMUL       EDX,EDX,0x3c
    //         0050cf3a     MOV        EAX,dword ptr [EBP + local_20]
    //         0050cf3d     ADD        EAX,EDX
    //         0050cf3f     MOVSX      this,word ptr [EBP + local_18]
    //         0050cf43     MOVSX      EDX,word ptr [EAX + this->tech_player_tree*0x2
    //         0050cf48     MOV        EAX,dword ptr [EBP + local_24]
    //         0050cf4b     MOV        this,dword ptr [EAX]
    //         0050cf4d     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050cf52     CMP        EDX,0x3
    //         0050cf55     JNZ        LAB_0050cf5f
    //         0050cf57     MOV        AL,byte ptr [EBP + local_14]
    //         0050cf5a     ADD        AL,0x1
    //         0050cf5c     MOV        byte ptr [EBP + local_14],AL
    //                               LAB_0050cf5f                                                 XREF[2]:     0050cf25(j), 0050cf55(j)  
    //         0050cf5f     JMP        LAB_0050cef9
    //                               LAB_0050cf61                                                 XREF[1]:     0050cf0c(j)  
    //         0050cf61     MOV        this,dword ptr [EBP + local_14]
    //         0050cf64     AND        this,0xff
    //         0050cf6a     MOVSX      EDX,word ptr [EBP + local_1c]
    //         0050cf6e     IMUL       EDX,EDX,0x3c
    //         0050cf71     MOV        EAX,dword ptr [EBP + local_20]
    //         0050cf74     MOVSX      EDX,word ptr [EAX + EDX*0x1 + 0xc]
    //         0050cf79     CMP        this,EDX
    //         0050cf7b     JL         LAB_0050cfe5
    //         0050cf7d     MOVSX      EAX,word ptr [EBP + local_1c]
    //         0050cf81     IMUL       EAX,EAX,0x3c
    //         0050cf84     MOV        this,dword ptr [EBP + local_20]
    //         0050cf87     MOVSX      EDX,word ptr [this->tech_player_tree + EAX*0x1
    //         0050cf8c     MOV        dword ptr [EBP + local_28],EDX
    //         0050cf8f     FILD       dword ptr [EBP + local_28]
    //         0050cf92     MOVSX      EAX,word ptr [EBP + local_1c]
    //         0050cf96     MOV        this,dword ptr [EBP + local_24]
    //         0050cf99     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050cf9b     FCOMP      float ptr [EDX + EAX*0x8]
    //         0050cf9e     FNSTSW     AX
    //         0050cfa0     TEST       AH,0x41
    //         0050cfa3     JZ         LAB_0050cfc0
    //         0050cfa5     MOV        AX,word ptr [EBP + local_1c]
    //         0050cfa9     PUSH       EAX
    //         0050cfaa     MOV        this,dword ptr [EBP + local_24]
    //         0050cfad     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //         0050cfb2     MOV        this,word ptr [EBP + local_c]
    //         0050cfb6     SUB        this,0x1
    //         0050cfba     MOV        word ptr [EBP + local_c],this
    //         0050cfbe     JMP        LAB_0050cfe3
    //                               LAB_0050cfc0                                                 XREF[1]:     0050cfa3(j)  
    //         0050cfc0     MOVSX      EDX,word ptr [EBP + local_1c]
    //         0050cfc4     MOV        EAX,dword ptr [EBP + local_24]
    //         0050cfc7     MOV        this,dword ptr [EAX]
    //         0050cfc9     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050cfce     CMP        EDX,0x1
    //         0050cfd1     JGE        LAB_0050cfe3
    //         0050cfd3     MOVSX      EAX,word ptr [EBP + local_1c]
    //         0050cfd7     MOV        this,dword ptr [EBP + local_24]
    //         0050cfda     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050cfdc     MOV        word ptr [EDX + EAX*0x8 + 0x4],0x1
    //                               LAB_0050cfe3                                                 XREF[2]:     0050cfbe(j), 0050cfd1(j)  
    //         0050cfe3     JMP        LAB_0050d007
    //                               LAB_0050cfe5                                                 XREF[1]:     0050cf7b(j)  
    //         0050cfe5     MOVSX      EAX,word ptr [EBP + local_1c]
    //         0050cfe9     MOV        this,dword ptr [EBP + local_24]
    //         0050cfec     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050cfee     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050cff3     TEST       EAX,EAX
    //         0050cff5     JLE        LAB_0050d007
    //         0050cff7     MOVSX      this,word ptr [EBP + local_1c]
    //         0050cffb     MOV        EDX,dword ptr [EBP + local_24]
    //         0050cffe     MOV        EAX,dword ptr [EDX]
    //         0050d000     MOV        word ptr [EAX + this->tech_player_tree*0x8 + 0
    //                               LAB_0050d007                                                 XREF[2]:     0050cfe3(j), 0050cff5(j)  
    //         0050d007     JMP        LAB_0050d028
    //                               LAB_0050d009                                                 XREF[2]:     0050cebe(j), 0050ced5(j)  
    //         0050d009     MOVSX      this,word ptr [EBP + local_1c]
    //         0050d00d     MOV        EDX,dword ptr [EBP + local_24]
    //         0050d010     MOV        EAX,dword ptr [EDX]
    //         0050d012     MOVSX      this,word ptr [EAX + this->tech_player_tree*0x
    //         0050d017     CMP        this,0x2
    //         0050d01a     JNZ        LAB_0050d028
    //         0050d01c     MOV        DX,word ptr [EBP + local_c]
    //         0050d020     ADD        DX,0x1
    //         0050d024     MOV        word ptr [EBP + local_c],DX
    //                               LAB_0050d028                                                 XREF[2]:     0050d007(j), 0050d01a(j)  
    //         0050d028     JMP        LAB_0050ce8e
    //                               LAB_0050d02d                                                 XREF[1]:     0050cea7(j)  
    //         0050d02d     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d030     AND        EAX,0xff
    //         0050d035     TEST       EAX,EAX
    //         0050d037     JNZ        LAB_0050ce82
    //         0050d03d     MOVSX      this,word ptr [EBP + local_c]
    //         0050d041     TEST       this,this
    //         0050d043     JNZ        LAB_0050d074
    //         0050d045     MOV        EDX,dword ptr [EBP + local_24]
    //         0050d048     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050d04b     MOV        this,dword ptr [EAX + 0x50]
    //         0050d04e     FLD        float ptr [this->tech_player_tree + 0x9c]
    //         0050d054     FCOMP      double ptr [DAT_005766d8]
    //         0050d05a     FNSTSW     AX
    //         0050d05c     TEST       AH,0x40
    //         0050d05f     JZ         LAB_0050d074
    //         0050d061     MOV        EDX,dword ptr [EBP + local_24]
    //         0050d064     MOV        EAX,dword ptr [EDX + 0xc]
    //         0050d067     MOV        this,dword ptr [EAX + 0x50]
    //         0050d06a     MOV        dword ptr [this->tech_player_tree + 0x9c],0x3f
    //                               LAB_0050d074                                                 XREF[2]:     0050d043(j), 0050d05f(j)  
    //         0050d074     MOV        AL,0x1
    //         0050d076     MOV        ESP,EBP
    //         0050d078     POP        EBP
    //         0050d079     RET
}

