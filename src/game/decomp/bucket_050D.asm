// Auto-generated scaffold unit: bucket_050D.asm
#include "../include/common.h"

// Offset: 0x0050D07A
void save(TRIBE_Player_Tech* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Player_Tech::save(int)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall save(TRIBE_Player_Tech * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0050d08c(R), 0050d0ca(R), 0050d0e6(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[6]:     0050d098(W), 0050d0a0(R), 0050d0a8(W), 0050d0ac(R), 
    //                                                                                     0050d0bd(R), 0050d0d8(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0050d080(W), 0050d085(R), 0050d0b0(R), 0050d0c1(R), 
    //                                                                                     0050d0dc(R)  
    //                               ?save@TRIBE_Player_Tech@@QAEXH@Z                             XREF[1]:     save:005122da(c)  
    //                               TRIBE_Player_Tech::save
    //         0050d07a     PUSH       EBP
    //         0050d07b     MOV        EBP,ESP
    //         0050d07d     SUB        ESP,0x8
    //         0050d080     MOV        dword ptr [EBP + local_c],this
    //         0050d083     PUSH       0x2
    //         0050d085     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d088     ADD        EAX,0x4
    //         0050d08b     PUSH       EAX
    //         0050d08c     MOV        this,dword ptr [EBP + param_1]
    //         0050d08f     PUSH       this
    //         0050d090     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d095     ADD        ESP,0xc
    //         0050d098     MOV        word ptr [EBP + local_8],0x0
    //         0050d09e     JMP        LAB_0050d0ac
    //                               LAB_0050d0a0                                                 XREF[1]:     0050d0f2(j)  
    //         0050d0a0     MOV        DX,word ptr [EBP + local_8]
    //         0050d0a4     ADD        DX,0x1
    //         0050d0a8     MOV        word ptr [EBP + local_8],DX
    //                               LAB_0050d0ac                                                 XREF[1]:     0050d09e(j)  
    //         0050d0ac     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050d0b0     MOV        this,dword ptr [EBP + local_c]
    //         0050d0b3     MOVSX      EDX,word ptr [ECX + this->tech_player_tree_num]
    //         0050d0b7     CMP        EAX,EDX
    //         0050d0b9     JGE        LAB_0050d0f4
    //         0050d0bb     PUSH       0x4
    //         0050d0bd     MOVSX      EAX,word ptr [EBP + local_8]
    //         0050d0c1     MOV        this,dword ptr [EBP + local_c]
    //         0050d0c4     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d0c6     LEA        EAX,[EDX + EAX*0x8]
    //         0050d0c9     PUSH       EAX
    //         0050d0ca     MOV        this,dword ptr [EBP + param_1]
    //         0050d0cd     PUSH       this
    //         0050d0ce     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d0d3     ADD        ESP,0xc
    //         0050d0d6     PUSH       0x2
    //         0050d0d8     MOVSX      EDX,word ptr [EBP + local_8]
    //         0050d0dc     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d0df     MOV        this,dword ptr [EAX]
    //         0050d0e1     LEA        EDX,[ECX + EDX*0x8 + this->tech_player_tree_num]
    //         0050d0e5     PUSH       EDX
    //         0050d0e6     MOV        EAX,dword ptr [EBP + param_1]
    //         0050d0e9     PUSH       EAX
    //         0050d0ea     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d0ef     ADD        ESP,0xc
    //         0050d0f2     JMP        LAB_0050d0a0
    //                               LAB_0050d0f4                                                 XREF[1]:     0050d0b9(j)  
    //         0050d0f4     MOV        ESP,EBP
    //         0050d0f6     POP        EBP
    //         0050d0f7     RET        0x4
}

// Offset: 0x0050D0FA
short get_progress(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: short __thiscall TRIBE_Player_Tech::get_progress(short)                                       *
    //                              *********************************************************************************************************
    //                              short __thiscall get_progress(TRIBE_Player_Tech * this, short param_1)
    //              short             AX:2           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[4]:     0050d103(R), 0050d116(R), 0050d12e(R), 0050d14d(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[4]:     0050d147(W), 0050d160(W), 0050d168(W), 0050d16e(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0050d100(W), 0050d107(R), 0050d11a(R), 0050d128(R), 
    //                                                                                     0050d151(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0050d13c(W), 0050d13f(R)  
    //                               ?get_progress@TRIBE_Player_Tech@@QAEFF@Z                     XREF[1]:     get_info:004d2613(c)  
    //                               TRIBE_Player_Tech::get_progress
    //         0050d0fa     PUSH       EBP
    //         0050d0fb     MOV        EBP,ESP
    //         0050d0fd     SUB        ESP,0xc
    //         0050d100     MOV        dword ptr [EBP + local_c],this
    //         0050d103     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d107     MOV        this,dword ptr [EBP + local_c]
    //         0050d10a     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d10c     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050d111     CMP        EAX,0x2
    //         0050d114     JNZ        LAB_0050d14d
    //         0050d116     MOVSX      this,word ptr [EBP + param_1]
    //         0050d11a     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d11d     MOV        EAX,dword ptr [EDX]
    //         0050d11f     FLD        float ptr [EAX + this->tech_player_tree*0x8]
    //         0050d122     FMUL       float ptr [DAT_005766e0]
    //         0050d128     MOV        this,dword ptr [EBP + local_c]
    //         0050d12b     MOV        EDX,dword ptr [ECX + this->base_tech]
    //         0050d12e     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d132     IMUL       EAX,EAX,0x3c
    //         0050d135     MOV        this,dword ptr [EDX]
    //         0050d137     MOVSX      EDX,word ptr [this->tech_player_tree + EAX*0x1
    //         0050d13c     MOV        dword ptr [EBP + local_10],EDX
    //         0050d13f     FIDIV      dword ptr [EBP + local_10]
    //         0050d142     CALL       __ftol                                           undefined __ftol()
    //         0050d147     MOV        word ptr [EBP + local_8],AX
    //         0050d14b     JMP        LAB_0050d16e
    //                               LAB_0050d14d                                                 XREF[1]:     0050d114(j)  
    //         0050d14d     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d151     MOV        this,dword ptr [EBP + local_c]
    //         0050d154     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d156     MOVSX      EAX,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050d15b     CMP        EAX,0x3
    //         0050d15e     JNZ        LAB_0050d168
    //         0050d160     MOV        word ptr [EBP + local_8],0x64
    //         0050d166     JMP        LAB_0050d16e
    //                               LAB_0050d168                                                 XREF[1]:     0050d15e(j)  
    //         0050d168     MOV        word ptr [EBP + local_8],0x0
    //                               LAB_0050d16e                                                 XREF[2]:     0050d14b(j), 0050d166(j)  
    //         0050d16e     MOV        AX,word ptr [EBP + local_8]
    //         0050d172     MOV        ESP,EBP
    //         0050d174     POP        EBP
    //         0050d175     RET        0x4
}

// Offset: 0x0050D178
char* get_name(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TRIBE_Player_Tech::get_name(short)                                          *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_name(TRIBE_Player_Tech * this, short param_1)
    //              char *            EAX:4          <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d185(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d17c(W), 0050d17f(R)  
    //                               ?get_name@TRIBE_Player_Tech@@QAEPADF@Z                       XREF[1]:     get_info:004d263e(c)  
    //                               TRIBE_Player_Tech::get_name
    //         0050d178     PUSH       EBP
    //         0050d179     MOV        EBP,ESP
    //         0050d17b     PUSH       this
    //         0050d17c     MOV        dword ptr [EBP + local_8],this
    //         0050d17f     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d182     MOV        this,dword ptr [EAX + 0x8]
    //         0050d185     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d189     IMUL       EDX,EDX,0x3c
    //         0050d18c     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050d18e     MOV        EAX,dword ptr [EAX + EDX*0x1]
    //         0050d191     MOV        ESP,EBP
    //         0050d193     POP        EBP
    //         0050d194     RET        0x4
}

// Offset: 0x0050D197
short get_string_id(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: short __thiscall TRIBE_Player_Tech::get_string_id(short)                                      *
    //                              *********************************************************************************************************
    //                              short __thiscall get_string_id(TRIBE_Player_Tech * this, short param
    //              short             AX:2           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d1a4(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d19b(W), 0050d19e(R)  
    //                               ?get_string_id@TRIBE_Player_Tech@@QAEFF@Z                    XREF[1]:     setup_buttons:0049a403(c)  
    //                               TRIBE_Player_Tech::get_string_id
    //         0050d197     PUSH       EBP
    //         0050d198     MOV        EBP,ESP
    //         0050d19a     PUSH       this
    //         0050d19b     MOV        dword ptr [EBP + local_8],this
    //         0050d19e     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d1a1     MOV        this,dword ptr [EAX + 0x8]
    //         0050d1a4     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d1a8     IMUL       EDX,EDX,0x3c
    //         0050d1ab     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050d1ad     MOV        AX,word ptr [EAX + EDX*0x1 + 0x2a]
    //         0050d1b2     MOV        ESP,EBP
    //         0050d1b4     POP        EBP
    //         0050d1b5     RET        0x4
}

// Offset: 0x0050D1B8
short get_string_id2(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: short __thiscall TRIBE_Player_Tech::get_string_id2(short)                                     *
    //                              *********************************************************************************************************
    //                              short __thiscall get_string_id2(TRIBE_Player_Tech * this, short para
    //              short             AX:2           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d1c5(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d1bc(W), 0050d1bf(R)  
    //                               ?get_string_id2@TRIBE_Player_Tech@@QAEFF@Z                   XREF[1]:     setup_buttons:0049a428(c)  
    //                               TRIBE_Player_Tech::get_string_id2
    //         0050d1b8     PUSH       EBP
    //         0050d1b9     MOV        EBP,ESP
    //         0050d1bb     PUSH       this
    //         0050d1bc     MOV        dword ptr [EBP + local_8],this
    //         0050d1bf     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d1c2     MOV        this,dword ptr [EAX + 0x8]
    //         0050d1c5     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d1c9     IMUL       EDX,EDX,0x3c
    //         0050d1cc     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050d1ce     MOV        AX,word ptr [EAX + EDX*0x1 + 0x2c]
    //         0050d1d3     MOV        ESP,EBP
    //         0050d1d5     POP        EBP
    //         0050d1d6     RET        0x4
}

// Offset: 0x0050D1D9
uchar get_button_location(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::get_button_location(short)                        *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_button_location(TRIBE_Player_Tech * this, short
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d1e6(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d1dd(W), 0050d1e0(R)  
    //                               ?get_button_location@TRIBE_Player_Tech@@QAEEF@Z              XREF[1]:     setup_buttons:0049a457(c)  
    //                               TRIBE_Player_Tech::get_button_location
    //         0050d1d9     PUSH       EBP
    //         0050d1da     MOV        EBP,ESP
    //         0050d1dc     PUSH       this
    //         0050d1dd     MOV        dword ptr [EBP + local_8],this
    //         0050d1e0     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d1e3     MOV        this,dword ptr [EAX + 0x8]
    //         0050d1e6     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d1ea     IMUL       EDX,EDX,0x3c
    //         0050d1ed     MOV        EAX,dword ptr [this->tech_player_tree]
    //         0050d1ef     MOV        AL,byte ptr [EAX + EDX*0x1 + 0x26]
    //         0050d1f3     MOV        ESP,EBP
    //         0050d1f5     POP        EBP
    //         0050d1f6     RET        0x4
}

// Offset: 0x0050D1F9
void do_rev_tech(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Player_Tech::do_rev_tech(short)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall do_rev_tech(TRIBE_Player_Tech * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050d220(R), 0050d26e(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[5]:     0050d233(W), 0050d236(R), 0050d241(R), 0050d253(R), 
    //                                                                                     0050d25f(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0050d202(W), 0050d20b(R), 0050d211(W), 0050d214(R), 
    //                                                                                     0050d22b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[6]:     0050d1ff(W), 0050d21a(R), 0050d23c(R), 0050d24e(R), 
    //                                                                                     0050d264(R), 0050d273(R)  
    //                               ?do_rev_tech@TRIBE_Player_Tech@@QAEXF@Z                      XREF[2]:     0050d267(c), rev_tech:0050d2f5(c)  
    //                               TRIBE_Player_Tech::do_rev_tech
    //         0050d1f9     PUSH       EBP
    //         0050d1fa     MOV        EBP,ESP
    //         0050d1fc     SUB        ESP,0xc
    //         0050d1ff     MOV        dword ptr [EBP + local_10],this
    //         0050d202     MOV        dword ptr [EBP + local_c],0x0
    //         0050d209     JMP        LAB_0050d214
    //                               LAB_0050d20b                                                 XREF[1]:     0050d26c(j)  
    //         0050d20b     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d20e     ADD        EAX,0x1
    //         0050d211     MOV        dword ptr [EBP + local_c],EAX
    //                               LAB_0050d214                                                 XREF[1]:     0050d209(j)  
    //         0050d214     CMP        dword ptr [EBP + local_c],0x4
    //         0050d218     JGE        LAB_0050d26e
    //         0050d21a     MOV        this,dword ptr [EBP + local_10]
    //         0050d21d     MOV        EDX,dword ptr [ECX + this->base_tech]
    //         0050d220     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d224     IMUL       EAX,EAX,0x3c
    //         0050d227     MOV        this,dword ptr [EDX]
    //         0050d229     ADD        this,EAX
    //         0050d22b     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d22e     MOVSX      EAX,word ptr [ECX + EDX*0x2 + this->tech_playe
    //         0050d233     MOV        dword ptr [EBP + local_8],EAX
    //         0050d236     CMP        dword ptr [EBP + local_8],0x0
    //         0050d23a     JL         LAB_0050d26c
    //         0050d23c     MOV        this,dword ptr [EBP + local_10]
    //         0050d23f     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d241     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d244     MOVSX      this,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050d249     CMP        this,0x3
    //         0050d24c     JGE        LAB_0050d26c
    //         0050d24e     MOV        EDX,dword ptr [EBP + local_10]
    //         0050d251     MOV        EAX,dword ptr [EDX]
    //         0050d253     MOV        this,dword ptr [EBP + local_8]
    //         0050d256     MOVSX      EDX,word ptr [EAX + this->tech_player_tree*0x8
    //         0050d25b     TEST       EDX,EDX
    //         0050d25d     JL         LAB_0050d26c
    //         0050d25f     MOV        AX,word ptr [EBP + local_8]
    //         0050d263     PUSH       EAX
    //         0050d264     MOV        this,dword ptr [EBP + local_10]
    //         0050d267     CALL       TRIBE_Player_Tech::do_rev_tech                   void do_rev_tech(TRIBE_Player_Tech * this, sh
    //                               LAB_0050d26c                                                 XREF[3]:     0050d23a(j), 0050d24c(j), 
    //                                                                                                         0050d25d(j)  
    //         0050d26c     JMP        LAB_0050d20b
    //                               LAB_0050d26e                                                 XREF[1]:     0050d218(j)  
    //         0050d26e     MOV        this,word ptr [EBP + param_1]
    //         0050d272     PUSH       this
    //         0050d273     MOV        this,dword ptr [EBP + local_10]
    //         0050d276     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //         0050d27b     MOV        ESP,EBP
    //         0050d27d     POP        EBP
    //         0050d27e     RET        0x4
}

// Offset: 0x0050D281
uchar rev_tech(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Player_Tech::rev_tech(short)                                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall rev_tech(TRIBE_Player_Tech * this, short param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050d28a(R), 0050d2e5(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[6]:     0050d297(W), 0050d2a0(R), 0050d2a6(W), 0050d2b0(R), 
    //                                                                                     0050d2d3(R), 0050d2ed(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0050d2b5(W), 0050d2be(R), 0050d2c4(W), 0050d2c7(R), 
    //                                                                                     0050d2dd(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[5]:     0050d287(W), 0050d28f(R), 0050d2a9(R), 0050d2cd(R), 
    //                                                                                     0050d2f2(R)  
    //                               ?rev_tech@TRIBE_Player_Tech@@QAEEF@Z                         XREF[6]:     rev_tech:00513e24(c), 
    //                               TRIBE_Player_Tech::rev_tech                                               rev_tech:00513e8b(c), 
    //                                                                                                         rev_tech:00513eb9(c), 
    //                                                                                                         rev_tech:00513f30(c), 
    //                                                                                                         rev_tech:00513f5e(c), 
    //                                                                                                         rev_tech:00513f8c(c)  
    //         0050d281     PUSH       EBP
    //         0050d282     MOV        EBP,ESP
    //         0050d284     SUB        ESP,0xc
    //         0050d287     MOV        dword ptr [EBP + local_10],this
    //         0050d28a     MOV        AX,word ptr [EBP + param_1]
    //         0050d28e     PUSH       EAX
    //         0050d28f     MOV        this,dword ptr [EBP + local_10]
    //         0050d292     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //         0050d297     MOV        dword ptr [EBP + local_8],0x0
    //         0050d29e     JMP        LAB_0050d2a9
    //                               LAB_0050d2a0                                                 XREF[1]:     0050d2fc(j)  
    //         0050d2a0     MOV        this,dword ptr [EBP + local_8]
    //         0050d2a3     ADD        this,0x1
    //         0050d2a6     MOV        dword ptr [EBP + local_8],this
    //                               LAB_0050d2a9                                                 XREF[1]:     0050d29e(j)  
    //         0050d2a9     MOV        EDX,dword ptr [EBP + local_10]
    //         0050d2ac     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050d2b0     CMP        dword ptr [EBP + local_8],EAX
    //         0050d2b3     JGE        LAB_0050d2fe
    //         0050d2b5     MOV        dword ptr [EBP + local_c],0x0
    //         0050d2bc     JMP        LAB_0050d2c7
    //                               LAB_0050d2be                                                 XREF[1]:     0050d2fa(j)  
    //         0050d2be     MOV        this,dword ptr [EBP + local_c]
    //         0050d2c1     ADD        this,0x1
    //         0050d2c4     MOV        dword ptr [EBP + local_c],this
    //                               LAB_0050d2c7                                                 XREF[1]:     0050d2bc(j)  
    //         0050d2c7     CMP        dword ptr [EBP + local_c],0x4
    //         0050d2cb     JGE        LAB_0050d2fc
    //         0050d2cd     MOV        EDX,dword ptr [EBP + local_10]
    //         0050d2d0     MOV        EAX,dword ptr [EDX + 0x8]
    //         0050d2d3     MOV        this,dword ptr [EBP + local_8]
    //         0050d2d6     IMUL       this,this,0x3c
    //         0050d2d9     MOV        EDX,dword ptr [EAX]
    //         0050d2db     ADD        EDX,this
    //         0050d2dd     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d2e0     MOVSX      this,word ptr [EDX + EAX*0x2 + 0x4]
    //         0050d2e5     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d2e9     CMP        this,EDX
    //         0050d2eb     JNZ        LAB_0050d2fa
    //         0050d2ed     MOV        AX,word ptr [EBP + local_8]
    //         0050d2f1     PUSH       EAX
    //         0050d2f2     MOV        this,dword ptr [EBP + local_10]
    //         0050d2f5     CALL       TRIBE_Player_Tech::do_rev_tech                   void do_rev_tech(TRIBE_Player_Tech * this, sh
    //                               LAB_0050d2fa                                                 XREF[1]:     0050d2eb(j)  
    //         0050d2fa     JMP        LAB_0050d2be
    //                               LAB_0050d2fc                                                 XREF[1]:     0050d2cb(j)  
    //         0050d2fc     JMP        LAB_0050d2a0
    //                               LAB_0050d2fe                                                 XREF[1]:     0050d2b3(j)  
    //         0050d2fe     MOV        AL,0x1
    //         0050d300     MOV        ESP,EBP
    //         0050d302     POP        EBP
    //         0050d303     RET        0x4
}

// Offset: 0x0050D306
void disable(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Player_Tech::disable(short)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall disable(TRIBE_Player_Tech * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050d30f(R), 0050d35a(R), 0050d36d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[6]:     0050d317(W), 0050d320(R), 0050d326(W), 0050d330(R), 
    //                                                                                     0050d33a(R), 0050d34c(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     0050d30c(W), 0050d329(R), 0050d335(R), 0050d347(R), 
    //                                                                                     0050d35e(R), 0050d371(R)  
    //                               ?disable@TRIBE_Player_Tech@@QAEXF@Z                          XREF[6]:     tech_abling:00513dc6(c), 
    //                               TRIBE_Player_Tech::disable                                                rev_tech:00513e0d(c), 
    //                                                                                                         rev_tech:00513e5d(c), 
    //                                                                                                         rev_tech:00513e74(c), 
    //                                                                                                         rev_tech:00513f02(c), 
    //                                                                                                         rev_tech:00513f19(c)  
    //         0050d306     PUSH       EBP
    //         0050d307     MOV        EBP,ESP
    //         0050d309     SUB        ESP,0x8
    //         0050d30c     MOV        dword ptr [EBP + local_c],this
    //         0050d30f     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d313     TEST       EAX,EAX
    //         0050d315     JGE        LAB_0050d35a
    //         0050d317     MOV        dword ptr [EBP + local_8],0x0
    //         0050d31e     JMP        LAB_0050d329
    //                               LAB_0050d320                                                 XREF[1]:     0050d356(j)  
    //         0050d320     MOV        this,dword ptr [EBP + local_8]
    //         0050d323     ADD        this,0x1
    //         0050d326     MOV        dword ptr [EBP + local_8],this
    //                               LAB_0050d329                                                 XREF[1]:     0050d31e(j)  
    //         0050d329     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d32c     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050d330     CMP        dword ptr [EBP + local_8],EAX
    //         0050d333     JGE        LAB_0050d358
    //         0050d335     MOV        this,dword ptr [EBP + local_c]
    //         0050d338     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d33a     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d33d     MOVSX      this,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050d342     CMP        this,0x3
    //         0050d345     JZ         LAB_0050d356
    //         0050d347     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d34a     MOV        EAX,dword ptr [EDX]
    //         0050d34c     MOV        this,dword ptr [EBP + local_8]
    //         0050d34f     MOV        word ptr [EAX + this->tech_player_tree*0x8 + 0
    //                               LAB_0050d356                                                 XREF[1]:     0050d345(j)  
    //         0050d356     JMP        LAB_0050d320
    //                               LAB_0050d358                                                 XREF[1]:     0050d333(j)  
    //         0050d358     JMP        LAB_0050d37d
    //                               LAB_0050d35a                                                 XREF[1]:     0050d315(j)  
    //         0050d35a     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d35e     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d361     MOV        this,dword ptr [EAX]
    //         0050d363     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050d368     CMP        EDX,0x3
    //         0050d36b     JZ         LAB_0050d37d
    //         0050d36d     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d371     MOV        this,dword ptr [EBP + local_c]
    //         0050d374     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d376     MOV        word ptr [EDX + EAX*0x8 + 0x4],0xffff
    //                               LAB_0050d37d                                                 XREF[2]:     0050d358(j), 0050d36b(j)  
    //         0050d37d     MOV        ESP,EBP
    //         0050d37f     POP        EBP
    //         0050d380     RET        0x4
}

// Offset: 0x0050D383
void enable(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Player_Tech::enable(short)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall enable(TRIBE_Player_Tech * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0050d38c(R), 0050d3d7(R), 0050d3ea(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[6]:     0050d394(W), 0050d39d(R), 0050d3a3(W), 0050d3ad(R), 
    //                                                                                     0050d3b7(R), 0050d3c9(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     0050d389(W), 0050d3a6(R), 0050d3b2(R), 0050d3c4(R), 
    //                                                                                     0050d3db(R), 0050d3ee(R)  
    //                               ?enable@TRIBE_Player_Tech@@QAEXF@Z                           XREF[6]:     tech_abling:00513db3(c), 
    //                               TRIBE_Player_Tech::enable                                                 rev_tech:00513e3b(c), 
    //                                                                                                         rev_tech:00513ea2(c), 
    //                                                                                                         rev_tech:00513ed0(c), 
    //                                                                                                         rev_tech:00513f47(c), 
    //                                                                                                         rev_tech:00513f75(c)  
    //         0050d383     PUSH       EBP
    //         0050d384     MOV        EBP,ESP
    //         0050d386     SUB        ESP,0x8
    //         0050d389     MOV        dword ptr [EBP + local_c],this
    //         0050d38c     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d390     TEST       EAX,EAX
    //         0050d392     JGE        LAB_0050d3d7
    //         0050d394     MOV        dword ptr [EBP + local_8],0x0
    //         0050d39b     JMP        LAB_0050d3a6
    //                               LAB_0050d39d                                                 XREF[1]:     0050d3d3(j)  
    //         0050d39d     MOV        this,dword ptr [EBP + local_8]
    //         0050d3a0     ADD        this,0x1
    //         0050d3a3     MOV        dword ptr [EBP + local_8],this
    //                               LAB_0050d3a6                                                 XREF[1]:     0050d39b(j)  
    //         0050d3a6     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d3a9     MOVSX      EAX,word ptr [EDX + 0x4]
    //         0050d3ad     CMP        dword ptr [EBP + local_8],EAX
    //         0050d3b0     JGE        LAB_0050d3d5
    //         0050d3b2     MOV        this,dword ptr [EBP + local_c]
    //         0050d3b5     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d3b7     MOV        EAX,dword ptr [EBP + local_8]
    //         0050d3ba     MOVSX      this,word ptr [EDX + EAX*0x8 + 0x4]
    //         0050d3bf     CMP        this,-0x1
    //         0050d3c2     JNZ        LAB_0050d3d3
    //         0050d3c4     MOV        EDX,dword ptr [EBP + local_c]
    //         0050d3c7     MOV        EAX,dword ptr [EDX]
    //         0050d3c9     MOV        this,dword ptr [EBP + local_8]
    //         0050d3cc     MOV        word ptr [EAX + this->tech_player_tree*0x8 + 0
    //                               LAB_0050d3d3                                                 XREF[1]:     0050d3c2(j)  
    //         0050d3d3     JMP        LAB_0050d39d
    //                               LAB_0050d3d5                                                 XREF[1]:     0050d3b0(j)  
    //         0050d3d5     JMP        LAB_0050d3fa
    //                               LAB_0050d3d7                                                 XREF[1]:     0050d392(j)  
    //         0050d3d7     MOVSX      EDX,word ptr [EBP + param_1]
    //         0050d3db     MOV        EAX,dword ptr [EBP + local_c]
    //         0050d3de     MOV        this,dword ptr [EAX]
    //         0050d3e0     MOVSX      EDX,word ptr [ECX + EDX*0x8 + this->tech_playe
    //         0050d3e5     CMP        EDX,-0x1
    //         0050d3e8     JNZ        LAB_0050d3fa
    //         0050d3ea     MOVSX      EAX,word ptr [EBP + param_1]
    //         0050d3ee     MOV        this,dword ptr [EBP + local_c]
    //         0050d3f1     MOV        EDX,dword ptr [this->tech_player_tree]
    //         0050d3f3     MOV        word ptr [EDX + EAX*0x8 + 0x4],0x0
    //                               LAB_0050d3fa                                                 XREF[2]:     0050d3d5(j), 0050d3e8(j)  
    //         0050d3fa     MOV        ESP,EBP
    //         0050d3fc     POP        EBP
    //         0050d3fd     RET        0x4
}

// Offset: 0x0050D400
long get_help_message(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Player_Tech::get_help_message(short)                                    *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_message(TRIBE_Player_Tech * this, short par
    //              long              EAX:4          <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d407(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d404(W), 0050d40c(R)  
    //                               ?get_help_message@TRIBE_Player_Tech@@QAEJF@Z                 XREF[2]:     setup_buttons:0049a3a0(c), 
    //                               TRIBE_Player_Tech::get_help_message                                       interface_tech_avail:00513179(c)  
    //         0050d400     PUSH       EBP
    //         0050d401     MOV        EBP,ESP
    //         0050d403     PUSH       this
    //         0050d404     MOV        dword ptr [EBP + local_8],this
    //         0050d407     MOV        AX,word ptr [EBP + param_1]
    //         0050d40b     PUSH       EAX
    //         0050d40c     MOV        this,dword ptr [EBP + local_8]
    //         0050d40f     MOV        this,dword ptr [ECX + this->base_tech]
    //         0050d412     CALL       TRIBE_Tech::get_help_message                     long get_help_message(TRIBE_Tech * this, shor
    //         0050d417     MOV        ESP,EBP
    //         0050d419     POP        EBP
    //         0050d41a     RET        0x4
}

// Offset: 0x0050D41D
long get_help_page(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Player_Tech::get_help_page(short)                                       *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_page(TRIBE_Player_Tech * this, short param_1)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d424(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d421(W), 0050d429(R)  
    //                               ?get_help_page@TRIBE_Player_Tech@@QAEJF@Z                    XREF[2]:     setup_buttons:0049a3b2(c), 
    //                               TRIBE_Player_Tech::get_help_page                                          interface_tech_avail:0051318b(c)  
    //         0050d41d     PUSH       EBP
    //         0050d41e     MOV        EBP,ESP
    //         0050d420     PUSH       this
    //         0050d421     MOV        dword ptr [EBP + local_8],this
    //         0050d424     MOV        AX,word ptr [EBP + param_1]
    //         0050d428     PUSH       EAX
    //         0050d429     MOV        this,dword ptr [EBP + local_8]
    //         0050d42c     MOV        this,dword ptr [ECX + this->base_tech]
    //         0050d42f     CALL       TRIBE_Tech::get_help_page                        long get_help_page(TRIBE_Tech * this, short p
    //         0050d434     MOV        ESP,EBP
    //         0050d436     POP        EBP
    //         0050d437     RET        0x4
}

// Offset: 0x0050D43A
long get_hotkey(TRIBE_Player_Tech* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Player_Tech::get_hotkey(short)                                          *
    //                              *********************************************************************************************************
    //                              long __thiscall get_hotkey(TRIBE_Player_Tech * this, short param_1)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Player_T    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d441(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d43e(W), 0050d446(R)  
    //                               ?get_hotkey@TRIBE_Player_Tech@@QAEJF@Z                       XREF[1]:     setup_buttons:0049a49d(c)  
    //                               TRIBE_Player_Tech::get_hotkey
    //         0050d43a     PUSH       EBP
    //         0050d43b     MOV        EBP,ESP
    //         0050d43d     PUSH       this
    //         0050d43e     MOV        dword ptr [EBP + local_8],this
    //         0050d441     MOV        AX,word ptr [EBP + param_1]
    //         0050d445     PUSH       EAX
    //         0050d446     MOV        this,dword ptr [EBP + local_8]
    //         0050d449     MOV        this,dword ptr [ECX + this->base_tech]
    //         0050d44c     CALL       TRIBE_Tech::get_hotkey                           long get_hotkey(TRIBE_Tech * this, short para
    //         0050d451     MOV        ESP,EBP
    //         0050d453     POP        EBP
    //         0050d454     RET        0x4
}

// Offset: 0x0050D4A0
void TRIBE_Effects(TRIBE_Effects* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Effects::~TRIBE_Effects(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Effects(TRIBE_Effects * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //                               ??1TRIBE_Effects@@UAE@XZ                                     XREF[1]:     `vector_deleting_destructor':0050d
    //                               TRIBE_Effects::~TRIBE_Effects
    //         0050d4a0     JMP        RGE_Effects::~RGE_Effects
}

