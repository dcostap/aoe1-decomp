#include "common.h"
#include "dpl_obj.h"

RGE_Doppleganger_Object::RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, RGE_Static_Object* param_7) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Doppleganger_Object(RGE_Doppleganger_Object
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     00441a90(R), 00441b04(*), 00441b11(R), 00441b4c(*), 
    //                                                                                     00441b59(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[2]:     00441a86(R), 00441af7(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00441aa2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00441aae(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00441b97(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00441a99(W)  
    //                               ??0RGE_Doppleganger_Object@@QAE@HPAVRGE_Game_World@@H@Z      XREF[1]:     load:00463a22(c)  
    //                               RGE_Doppleganger_Object::RGE_Doppleganger_Object
    //                              dpl_obj.cpp:121 (50)
    //         00441a70     PUSH       -0x1
    //         00441a72     PUSH       FUN_0055d2b8
    //         00441a77     MOV        EAX,FS:[0x0]
    //         00441a7d     PUSH       EAX
    //         00441a7e     MOV        dword ptr FS:[0x0],ESP
    //         00441a85     PUSH       this
    //         00441a86     MOV        EAX,dword ptr [ESP + param_2]
    //         00441a8a     PUSH       EBX
    //         00441a8b     PUSH       EBP
    //         00441a8c     PUSH       ESI
    //         00441a8d     XOR        EBX,EBX
    //         00441a8f     PUSH       EDI
    //         00441a90     MOV        EDI,dword ptr [ESP + param_1]
    //         00441a94     PUSH       EBX
    //         00441a95     MOV        ESI,this
    //         00441a97     PUSH       EAX
    //         00441a98     PUSH       EDI
    //         00441a99     MOV        dword ptr [ESP + local_10],ESI
    //         00441a9d     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
    //                              dpl_obj.cpp:136 (85)
    //         00441aa2     MOV        EAX,dword ptr [ESP + param_3]
    //         00441aa6     LEA        EBP,[ESI + 0x98]
    //         00441aac     CMP        EAX,EBX
    //         00441aae     MOV        dword ptr [ESP + local_4],EBX
    //         00441ab2     MOV        dword ptr [ESI],RGE_Doppleganger_Object::`vfta   = 00441a40
    //         00441ab8     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441abe     MOV        dword ptr [ESI + 0x90],EBX
    //         00441ac4     MOV        dword ptr [ESI + 0x94],EBX
    //         00441aca     MOV        dword ptr [EBP],EBX
    //         00441acd     MOV        dword ptr [ESI + 0x9c],EBX
    //         00441ad3     MOV        dword ptr [ESI + 0xa0],EBX
    //         00441ad9     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441adf     MOV        byte ptr [ESI + 0xa8],BL
    //         00441ae5     MOV        byte ptr [ESI + 0xa9],BL
    //         00441aeb     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441af5     JZ         LAB_00441b04
    //                              dpl_obj.cpp:137 (13)
    //         00441af7     MOV        this,dword ptr [ESP + param_2]
    //         00441afb     PUSH       this
    //         00441afc     PUSH       EDI
    //         00441afd     MOV        this,ESI
    //         00441aff     CALL       RGE_Doppleganger_Object::setup                   int setup(RGE_Doppleganger_Object * this, int
    //                               LAB_00441b04                                                 XREF[1]:     00441af5(j)  
    //                              dpl_obj.cpp:139 (13)
    //         00441b04     LEA        EDX=>param_1,[ESP + 0x24]
    //         00441b08     PUSH       0x4
    //         00441b0a     PUSH       EDX
    //         00441b0b     PUSH       EDI
    //         00441b0c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:140 (13)
    //         00441b11     MOV        EAX,dword ptr [ESP + param_1]
    //         00441b15     ADD        ESP,0xc
    //         00441b18     MOV        dword ptr [ESI + 0x8c],EAX
    //                              dpl_obj.cpp:146 (28)
    //         00441b1e     LEA        EAX,[ESI + 0xa8]
    //         00441b24     PUSH       0x1
    //         00441b26     PUSH       EAX
    //         00441b27     PUSH       EDI
    //         00441b28     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441b32     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b37     ADD        ESP,0xc
    //                              dpl_obj.cpp:147 (18)
    //         00441b3a     LEA        EAX,[ESI + 0xa9]
    //         00441b40     PUSH       0x4
    //         00441b42     PUSH       EAX
    //         00441b43     PUSH       EDI
    //         00441b44     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b49     ADD        ESP,0xc
    //                              dpl_obj.cpp:150 (13)
    //         00441b4c     LEA        this=>param_1,[ESP + 0x24]
    //         00441b50     PUSH       0x4
    //         00441b52     PUSH       this
    //         00441b53     PUSH       EDI
    //         00441b54     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:151 (13)
    //         00441b59     MOV        EDX,dword ptr [ESP + param_1]
    //         00441b5d     ADD        ESP,0xc
    //         00441b60     MOV        dword ptr [ESI + 0x94],EDX
    //                              dpl_obj.cpp:153 (9)
    //         00441b66     PUSH       0x4
    //         00441b68     PUSH       EBP
    //         00441b69     PUSH       EDI
    //         00441b6a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:156 (22)
    //         00441b6f     FLD        float ptr [save_game_version]                    = 7.23
    //         00441b75     FCOMP      float ptr [DAT_00570418]                         = 85h
    //         00441b7b     ADD        ESP,0xc
    //         00441b7e     FNSTSW     AX
    //         00441b80     TEST       AH,0x1
    //         00441b83     JNZ        LAB_00441b97
    //                              dpl_obj.cpp:158 (18)
    //         00441b85     LEA        EAX,[ESI + 0xa4]
    //         00441b8b     PUSH       0x4
    //         00441b8d     PUSH       EAX
    //         00441b8e     PUSH       EDI
    //         00441b8f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b94     ADD        ESP,0xc
    //                               LAB_00441b97                                                 XREF[1]:     00441b83(j)  
    //                              dpl_obj.cpp:162 (23)
    //         00441b97     MOV        this,dword ptr [ESP + local_c]
    //         00441b9b     MOV        EAX,ESI
    //         00441b9d     POP        EDI
    //         00441b9e     POP        ESI
    //         00441b9f     POP        EBP
    //         00441ba0     MOV        dword ptr FS:[0x0],this
    //         00441ba7     POP        EBX
    //         00441ba8     ADD        ESP,0x10
    //         00441bab     RET        0xc
    //         00441bae     ??         90h
    //         00441baf     NOP
    //                              * public: virtual void __thiscall RGE_Doppleganger_Object::recycle_in_to_game(class RGE_Master_Stati... *
    //                              void __thiscall recycle_in_to_game(RGE_Doppleganger_Object * this, R
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00441bc8(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00441bc3(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00441bb4(R), 00441cb7(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     00441bbd(R), 00441ca8(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00441bb0(R)  
    //              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[1]:     00441c17(R)  
    //                               ?recycle_in_to_game@RGE_Doppleganger_Object@@UAEXPAVRGE_Mas  XREF[1]:     0057040c(*)  
    //                               RGE_Doppleganger_Object::recycle_in_to_game
    //                              dpl_obj.cpp:166 (103)
    //         00441bb0     MOV        EAX,dword ptr [ESP + param_5]
    //         00441bb4     MOV        EDX,dword ptr [ESP + param_3]
    //         00441bb8     PUSH       EBX
    //         00441bb9     PUSH       EBP
    //         00441bba     PUSH       ESI
    //         00441bbb     MOV        ESI,this
    //         00441bbd     MOV        this,dword ptr [ESP + param_4]
    //         00441bc1     PUSH       EDI
    //         00441bc2     PUSH       EAX
    //         00441bc3     MOV        EAX,dword ptr [ESP + param_2]
    //         00441bc7     PUSH       this
    //         00441bc8     MOV        this,dword ptr [ESP + param_1]
    //         00441bcc     PUSH       EDX
    //         00441bcd     PUSH       EAX
    //         00441bce     XOR        EBX,EBX
    //         00441bd0     OR         EDI,0xffffffff
    //         00441bd3     PUSH       this
    //         00441bd4     MOV        this,ESI
    //         00441bd6     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441bdc     MOV        dword ptr [ESI + 0x90],EBX
    //         00441be2     MOV        dword ptr [ESI + 0x94],EBX
    //         00441be8     MOV        dword ptr [ESI + 0x98],EBX
    //         00441bee     MOV        dword ptr [ESI + 0x9c],EBX
    //         00441bf4     MOV        dword ptr [ESI + 0xa0],EBX
    //         00441bfa     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441c00     MOV        byte ptr [ESI + 0xa8],BL
    //         00441c06     MOV        byte ptr [ESI + 0xa9],BL
    //         00441c0c     MOV        dword ptr [ESI + 0xac],EDI
    //         00441c12     CALL       RGE_Animated_Object::recycle_in_to_game          void recycle_in_to_game(RGE_Animated_Object *
    //                              dpl_obj.cpp:184 (8)
    //         00441c17     MOV        EAX,dword ptr [ESP + param_6]
    //         00441c1b     MOV        byte ptr [ESI + 0x4e],0x19
    //                              dpl_obj.cpp:185 (14)
    //         00441c1f     CMP        EAX,EBX
    //         00441c21     MOV        dword ptr [ESI + 0x8c],EAX
    //         00441c27     JZ         LAB_00441d06
    //                              dpl_obj.cpp:187 (9)
    //         00441c2d     MOV        EDX,dword ptr [EAX + 0x8]
    //         00441c30     MOV        dword ptr [ESI + 0x94],EDX
    //                              dpl_obj.cpp:188 (13)
    //         00441c36     MOV        this,dword ptr [EAX + 0xc]
    //         00441c39     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         00441c3d     MOV        dword ptr [ESI + 0x98],EDX
    //                              dpl_obj.cpp:189 (9)
    //         00441c43     MOV        this,dword ptr [EAX + 0x4]
    //         00441c46     MOV        dword ptr [ESI + 0xac],this
    //                              dpl_obj.cpp:191 (6)
    //         00441c4c     MOV        EDX,dword ptr [EAX + 0x10]
    //         00441c4f     MOV        dword ptr [ESI + 0x10],EDX
    //                              dpl_obj.cpp:192 (17)
    //         00441c52     MOV        this,dword ptr [EAX + 0x18]
    //         00441c55     CALL       RGE_Active_Sprite_List::copy_sprite_list         RGE_Active_Sprite_Node * copy_sprite_list(RGE
    //         00441c5a     MOV        this,dword ptr [ESI + 0x18]
    //         00441c5d     PUSH       EAX
    //         00441c5e     CALL       RGE_Active_Sprite_List::use_sprite_list          void use_sprite_list(RGE_Active_Sprite_List *
    //                              dpl_obj.cpp:193 (12)
    //         00441c63     MOV        EDI,dword ptr [ESI + 0x8c]
    //         00441c69     MOV        AL,byte ptr [EDI + 0x35]
    //         00441c6c     MOV        byte ptr [ESI + 0x35],AL
    //                              dpl_obj.cpp:194 (15)
    //         00441c6f     MOV        this,dword ptr [EDI + 0xc]
    //         00441c72     MOV        EDX,dword ptr [this->_padding_ + 0x108]
    //         00441c78     MOV        dword ptr [ESI + 0x90],EDX
    //                              dpl_obj.cpp:198 (9)
    //         00441c7e     MOV        EAX,dword ptr [EDI + 0x8]
    //         00441c81     MOV        AL,byte ptr [EAX + 0x8e]
    //                              dpl_obj.cpp:200 (10)
    //         00441c87     CMP        AL,0x3
    //         00441c89     MOV        byte ptr [ESI + 0xa8],AL
    //         00441c8f     JNZ        LAB_00441c9c
    //                              dpl_obj.cpp:201 (9)
    //         00441c91     MOV        this,dword ptr [EDI + 0x8]
    //         00441c94     MOV        DL,byte ptr [ECX + this->draw_color]
    //                              dpl_obj.cpp:202 (2)
    //         00441c9a     JMP        LAB_00441ca8
    //                               LAB_00441c9c                                                 XREF[1]:     00441c8f(j)  
    //                              dpl_obj.cpp:203 (12)
    //         00441c9c     MOV        EAX,dword ptr [EDI + 0xc]
    //         00441c9f     MOV        this,dword ptr [EAX + 0x108]
    //         00441ca5     MOV        DL,byte ptr [ECX + this+0x25]
    //                               LAB_00441ca8                                                 XREF[1]:     00441c9a(j)  
    //                              dpl_obj.cpp:207 (33)
    //         00441ca8     FLD        float ptr [ESP + param_4]
    //         00441cac     MOV        byte ptr [ESI + 0xa9],DL
    //         00441cb2     CALL       __ftol                                           undefined __ftol()
    //         00441cb7     FLD        float ptr [ESP + param_3]
    //         00441cbb     MOV        EBP,EAX
    //         00441cbd     CALL       __ftol                                           undefined __ftol()
    //         00441cc2     MOV        this,dword ptr [EBP*0x4 + unified_map_offsets]   = 00000000
    //                              dpl_obj.cpp:209 (6)
    //         00441cc9     MOV        dword ptr [ESI + 0xa0],EBX
    //                              dpl_obj.cpp:210 (15)
    //         00441ccf     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441cd5     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         00441cd8     MOV        dword ptr [ESI + 0x9c],EDX
    //                              dpl_obj.cpp:213 (7)
    //         00441cde     MOV        AL,byte ptr [EDI + 0x48]
    //         00441ce1     CMP        AL,0x7
    //         00441ce3     JC         LAB_00441d1f
    //                              dpl_obj.cpp:232 (26)
    //         00441ce5     MOV        EDX,dword ptr [ESI]
    //         00441ce7     MOV        this,ESI
    //         00441ce9     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441cef     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441cf9     CALL       dword ptr [EDX + 0x1f0]
    //                              dpl_obj.cpp:235 (7)
    //         00441cff     POP        EDI
    //         00441d00     POP        ESI
    //         00441d01     POP        EBP
    //         00441d02     POP        EBX
    //         00441d03     RET        0x18
    //                               LAB_00441d06                                                 XREF[1]:     00441c27(j)  
    //                              dpl_obj.cpp:228 (25)
    //         00441d06     MOV        EAX,dword ptr [ESI]
    //         00441d08     MOV        this,ESI
    //         00441d0a     MOV        dword ptr [ESI + 0xac],EDI
    //         00441d10     MOV        dword ptr [ESI + 0x94],EBX
    //         00441d16     MOV        dword ptr [ESI + 0x98],EBX
    //         00441d1c     CALL       dword ptr [EAX + 0x68]
    //                               LAB_00441d1f                                                 XREF[1]:     00441ce3(j)  
    //                              dpl_obj.cpp:232 (10)
    //         00441d1f     MOV        EDX,dword ptr [ESI]
    //         00441d21     MOV        this,ESI
    //         00441d23     CALL       dword ptr [EDX + 0x1f0]
    //                              dpl_obj.cpp:235 (7)
    //         00441d29     POP        EDI
    //         00441d2a     POP        ESI
    //         00441d2b     POP        EBP
    //         00441d2c     POP        EBX
    //         00441d2d     RET        0x18
    //                              * protected: virtual int __thiscall RGE_Doppleganger_Object::setup(class RGE_Master_Doppleganger_Obj... *
    //                              int __thiscall setup(RGE_Doppleganger_Object * this, RGE_Master_Dopp
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Master_Dop    Stack[0x4]:4   param_1                   XREF[1]:     00441d46(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00441d41(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00441d34(R), 00441d61(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     00441d3b(R), 00441d54(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00441d30(R)  
    //                               ?setup@RGE_Doppleganger_Object@@MAEHPAVRGE_Master_Dopplegan  XREF[2]:     RGE_Doppleganger_Object:00441948(c
    //                               RGE_Doppleganger_Object::setup                                            00570414(*)  
    //                              dpl_obj.cpp:239 (36)
    //         00441d30     MOV        EAX,dword ptr [ESP + param_5]
    //         00441d34     MOV        EDX,dword ptr [ESP + param_3]
    //         00441d38     PUSH       ESI
    //         00441d39     MOV        ESI,this
    //         00441d3b     MOV        this,dword ptr [ESP + param_4]
    //         00441d3f     PUSH       EDI
    //         00441d40     PUSH       EAX
    //         00441d41     MOV        EAX,dword ptr [ESP + param_2]
    //         00441d45     PUSH       this
    //         00441d46     MOV        this,dword ptr [ESP + param_1]
    //         00441d4a     PUSH       EDX
    //         00441d4b     PUSH       EAX
    //         00441d4c     PUSH       this
    //         00441d4d     MOV        this,ESI
    //         00441d4f     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, RGE_Mas
    //                              dpl_obj.cpp:244 (31)
    //         00441d54     FLD        float ptr [ESP + param_4]
    //         00441d58     MOV        byte ptr [ESI + 0x4e],0x19
    //         00441d5c     CALL       __ftol                                           undefined __ftol()
    //         00441d61     FLD        float ptr [ESP + param_3]
    //         00441d65     MOV        EDI,EAX
    //         00441d67     CALL       __ftol                                           undefined __ftol()
    //         00441d6c     MOV        EDX,dword ptr [EDI*0x4 + unified_map_offsets]    = 00000000
    //                              dpl_obj.cpp:250 (33)
    //         00441d73     POP        EDI
    //         00441d74     LEA        EAX,[EDX + EAX*0x4]
    //         00441d77     MOV        dword ptr [ESI + 0x9c],EAX
    //         00441d7d     XOR        EAX,EAX
    //         00441d7f     MOV        dword ptr [ESI + 0xa0],EAX
    //         00441d85     MOV        dword ptr [ESI + 0xa4],EAX
    //         00441d8b     MOV        EAX,0x1
    //         00441d90     POP        ESI
    //         00441d91     RET        0x14
    //         00441d94     ??         90h
    //         00441d95     NOP
    //         00441d96     NOP
    //         00441d97     NOP
    //         00441d98     NOP
    //         00441d99     NOP
    //         00441d9a     NOP
    //         00441d9b     NOP
    //         00441d9c     NOP
    //         00441d9d     NOP
    //         00441d9e     NOP
    //         00441d9f     NOP
}

RGE_Doppleganger_Object::RGE_Doppleganger_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Doppleganger_Object(RGE_Doppleganger_Object
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     00441a90(R), 00441b04(*), 00441b11(R), 00441b4c(*), 
    //                                                                                     00441b59(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[2]:     00441a86(R), 00441af7(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00441aa2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00441aae(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00441b97(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00441a99(W)  
    //                               ??0RGE_Doppleganger_Object@@QAE@HPAVRGE_Game_World@@H@Z      XREF[1]:     load:00463a22(c)  
    //                               RGE_Doppleganger_Object::RGE_Doppleganger_Object
    //                              dpl_obj.cpp:121 (50)
    //         00441a70     PUSH       -0x1
    //         00441a72     PUSH       FUN_0055d2b8
    //         00441a77     MOV        EAX,FS:[0x0]
    //         00441a7d     PUSH       EAX
    //         00441a7e     MOV        dword ptr FS:[0x0],ESP
    //         00441a85     PUSH       this
    //         00441a86     MOV        EAX,dword ptr [ESP + param_2]
    //         00441a8a     PUSH       EBX
    //         00441a8b     PUSH       EBP
    //         00441a8c     PUSH       ESI
    //         00441a8d     XOR        EBX,EBX
    //         00441a8f     PUSH       EDI
    //         00441a90     MOV        EDI,dword ptr [ESP + param_1]
    //         00441a94     PUSH       EBX
    //         00441a95     MOV        ESI,this
    //         00441a97     PUSH       EAX
    //         00441a98     PUSH       EDI
    //         00441a99     MOV        dword ptr [ESP + local_10],ESI
    //         00441a9d     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
    //                              dpl_obj.cpp:136 (85)
    //         00441aa2     MOV        EAX,dword ptr [ESP + param_3]
    //         00441aa6     LEA        EBP,[ESI + 0x98]
    //         00441aac     CMP        EAX,EBX
    //         00441aae     MOV        dword ptr [ESP + local_4],EBX
    //         00441ab2     MOV        dword ptr [ESI],RGE_Doppleganger_Object::`vfta   = 00441a40
    //         00441ab8     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441abe     MOV        dword ptr [ESI + 0x90],EBX
    //         00441ac4     MOV        dword ptr [ESI + 0x94],EBX
    //         00441aca     MOV        dword ptr [EBP],EBX
    //         00441acd     MOV        dword ptr [ESI + 0x9c],EBX
    //         00441ad3     MOV        dword ptr [ESI + 0xa0],EBX
    //         00441ad9     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441adf     MOV        byte ptr [ESI + 0xa8],BL
    //         00441ae5     MOV        byte ptr [ESI + 0xa9],BL
    //         00441aeb     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441af5     JZ         LAB_00441b04
    //                              dpl_obj.cpp:137 (13)
    //         00441af7     MOV        this,dword ptr [ESP + param_2]
    //         00441afb     PUSH       this
    //         00441afc     PUSH       EDI
    //         00441afd     MOV        this,ESI
    //         00441aff     CALL       RGE_Doppleganger_Object::setup                   int setup(RGE_Doppleganger_Object * this, int
    //                               LAB_00441b04                                                 XREF[1]:     00441af5(j)  
    //                              dpl_obj.cpp:139 (13)
    //         00441b04     LEA        EDX=>param_1,[ESP + 0x24]
    //         00441b08     PUSH       0x4
    //         00441b0a     PUSH       EDX
    //         00441b0b     PUSH       EDI
    //         00441b0c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:140 (13)
    //         00441b11     MOV        EAX,dword ptr [ESP + param_1]
    //         00441b15     ADD        ESP,0xc
    //         00441b18     MOV        dword ptr [ESI + 0x8c],EAX
    //                              dpl_obj.cpp:146 (28)
    //         00441b1e     LEA        EAX,[ESI + 0xa8]
    //         00441b24     PUSH       0x1
    //         00441b26     PUSH       EAX
    //         00441b27     PUSH       EDI
    //         00441b28     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441b32     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b37     ADD        ESP,0xc
    //                              dpl_obj.cpp:147 (18)
    //         00441b3a     LEA        EAX,[ESI + 0xa9]
    //         00441b40     PUSH       0x4
    //         00441b42     PUSH       EAX
    //         00441b43     PUSH       EDI
    //         00441b44     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b49     ADD        ESP,0xc
    //                              dpl_obj.cpp:150 (13)
    //         00441b4c     LEA        this=>param_1,[ESP + 0x24]
    //         00441b50     PUSH       0x4
    //         00441b52     PUSH       this
    //         00441b53     PUSH       EDI
    //         00441b54     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:151 (13)
    //         00441b59     MOV        EDX,dword ptr [ESP + param_1]
    //         00441b5d     ADD        ESP,0xc
    //         00441b60     MOV        dword ptr [ESI + 0x94],EDX
    //                              dpl_obj.cpp:153 (9)
    //         00441b66     PUSH       0x4
    //         00441b68     PUSH       EBP
    //         00441b69     PUSH       EDI
    //         00441b6a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              dpl_obj.cpp:156 (22)
    //         00441b6f     FLD        float ptr [save_game_version]                    = 7.23
    //         00441b75     FCOMP      float ptr [DAT_00570418]                         = 85h
    //         00441b7b     ADD        ESP,0xc
    //         00441b7e     FNSTSW     AX
    //         00441b80     TEST       AH,0x1
    //         00441b83     JNZ        LAB_00441b97
    //                              dpl_obj.cpp:158 (18)
    //         00441b85     LEA        EAX,[ESI + 0xa4]
    //         00441b8b     PUSH       0x4
    //         00441b8d     PUSH       EAX
    //         00441b8e     PUSH       EDI
    //         00441b8f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00441b94     ADD        ESP,0xc
    //                               LAB_00441b97                                                 XREF[1]:     00441b83(j)  
    //                              dpl_obj.cpp:162 (23)
    //         00441b97     MOV        this,dword ptr [ESP + local_c]
    //         00441b9b     MOV        EAX,ESI
    //         00441b9d     POP        EDI
    //         00441b9e     POP        ESI
    //         00441b9f     POP        EBP
    //         00441ba0     MOV        dword ptr FS:[0x0],this
    //         00441ba7     POP        EBX
    //         00441ba8     ADD        ESP,0x10
    //         00441bab     RET        0xc
    //         00441bae     ??         90h
    //         00441baf     NOP
    //                              * public: virtual void __thiscall RGE_Doppleganger_Object::recycle_in_to_game(class RGE_Master_Stati... *
    //                              void __thiscall recycle_in_to_game(RGE_Doppleganger_Object * this, R
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00441bc8(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00441bc3(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00441bb4(R), 00441cb7(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     00441bbd(R), 00441ca8(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00441bb0(R)  
    //              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[1]:     00441c17(R)  
    //                               ?recycle_in_to_game@RGE_Doppleganger_Object@@UAEXPAVRGE_Mas  XREF[1]:     0057040c(*)  
    //                               RGE_Doppleganger_Object::recycle_in_to_game
    //                              dpl_obj.cpp:166 (103)
    //         00441bb0     MOV        EAX,dword ptr [ESP + param_5]
    //         00441bb4     MOV        EDX,dword ptr [ESP + param_3]
    //         00441bb8     PUSH       EBX
    //         00441bb9     PUSH       EBP
    //         00441bba     PUSH       ESI
    //         00441bbb     MOV        ESI,this
    //         00441bbd     MOV        this,dword ptr [ESP + param_4]
    //         00441bc1     PUSH       EDI
    //         00441bc2     PUSH       EAX
    //         00441bc3     MOV        EAX,dword ptr [ESP + param_2]
    //         00441bc7     PUSH       this
    //         00441bc8     MOV        this,dword ptr [ESP + param_1]
    //         00441bcc     PUSH       EDX
    //         00441bcd     PUSH       EAX
    //         00441bce     XOR        EBX,EBX
    //         00441bd0     OR         EDI,0xffffffff
    //         00441bd3     PUSH       this
    //         00441bd4     MOV        this,ESI
    //         00441bd6     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441bdc     MOV        dword ptr [ESI + 0x90],EBX
    //         00441be2     MOV        dword ptr [ESI + 0x94],EBX
    //         00441be8     MOV        dword ptr [ESI + 0x98],EBX
    //         00441bee     MOV        dword ptr [ESI + 0x9c],EBX
    //         00441bf4     MOV        dword ptr [ESI + 0xa0],EBX
    //         00441bfa     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441c00     MOV        byte ptr [ESI + 0xa8],BL
    //         00441c06     MOV        byte ptr [ESI + 0xa9],BL
    //         00441c0c     MOV        dword ptr [ESI + 0xac],EDI
    //         00441c12     CALL       RGE_Animated_Object::recycle_in_to_game          void recycle_in_to_game(RGE_Animated_Object *
    //                              dpl_obj.cpp:184 (8)
    //         00441c17     MOV        EAX,dword ptr [ESP + param_6]
    //         00441c1b     MOV        byte ptr [ESI + 0x4e],0x19
    //                              dpl_obj.cpp:185 (14)
    //         00441c1f     CMP        EAX,EBX
    //         00441c21     MOV        dword ptr [ESI + 0x8c],EAX
    //         00441c27     JZ         LAB_00441d06
    //                              dpl_obj.cpp:187 (9)
    //         00441c2d     MOV        EDX,dword ptr [EAX + 0x8]
    //         00441c30     MOV        dword ptr [ESI + 0x94],EDX
    //                              dpl_obj.cpp:188 (13)
    //         00441c36     MOV        this,dword ptr [EAX + 0xc]
    //         00441c39     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         00441c3d     MOV        dword ptr [ESI + 0x98],EDX
    //                              dpl_obj.cpp:189 (9)
    //         00441c43     MOV        this,dword ptr [EAX + 0x4]
    //         00441c46     MOV        dword ptr [ESI + 0xac],this
    //                              dpl_obj.cpp:191 (6)
    //         00441c4c     MOV        EDX,dword ptr [EAX + 0x10]
    //         00441c4f     MOV        dword ptr [ESI + 0x10],EDX
    //                              dpl_obj.cpp:192 (17)
    //         00441c52     MOV        this,dword ptr [EAX + 0x18]
    //         00441c55     CALL       RGE_Active_Sprite_List::copy_sprite_list         RGE_Active_Sprite_Node * copy_sprite_list(RGE
    //         00441c5a     MOV        this,dword ptr [ESI + 0x18]
    //         00441c5d     PUSH       EAX
    //         00441c5e     CALL       RGE_Active_Sprite_List::use_sprite_list          void use_sprite_list(RGE_Active_Sprite_List *
    //                              dpl_obj.cpp:193 (12)
    //         00441c63     MOV        EDI,dword ptr [ESI + 0x8c]
    //         00441c69     MOV        AL,byte ptr [EDI + 0x35]
    //         00441c6c     MOV        byte ptr [ESI + 0x35],AL
    //                              dpl_obj.cpp:194 (15)
    //         00441c6f     MOV        this,dword ptr [EDI + 0xc]
    //         00441c72     MOV        EDX,dword ptr [this->_padding_ + 0x108]
    //         00441c78     MOV        dword ptr [ESI + 0x90],EDX
    //                              dpl_obj.cpp:198 (9)
    //         00441c7e     MOV        EAX,dword ptr [EDI + 0x8]
    //         00441c81     MOV        AL,byte ptr [EAX + 0x8e]
    //                              dpl_obj.cpp:200 (10)
    //         00441c87     CMP        AL,0x3
    //         00441c89     MOV        byte ptr [ESI + 0xa8],AL
    //         00441c8f     JNZ        LAB_00441c9c
    //                              dpl_obj.cpp:201 (9)
    //         00441c91     MOV        this,dword ptr [EDI + 0x8]
    //         00441c94     MOV        DL,byte ptr [ECX + this->draw_color]
    //                              dpl_obj.cpp:202 (2)
    //         00441c9a     JMP        LAB_00441ca8
    //                               LAB_00441c9c                                                 XREF[1]:     00441c8f(j)  
    //                              dpl_obj.cpp:203 (12)
    //         00441c9c     MOV        EAX,dword ptr [EDI + 0xc]
    //         00441c9f     MOV        this,dword ptr [EAX + 0x108]
    //         00441ca5     MOV        DL,byte ptr [ECX + this+0x25]
    //                               LAB_00441ca8                                                 XREF[1]:     00441c9a(j)  
    //                              dpl_obj.cpp:207 (33)
    //         00441ca8     FLD        float ptr [ESP + param_4]
    //         00441cac     MOV        byte ptr [ESI + 0xa9],DL
    //         00441cb2     CALL       __ftol                                           undefined __ftol()
    //         00441cb7     FLD        float ptr [ESP + param_3]
    //         00441cbb     MOV        EBP,EAX
    //         00441cbd     CALL       __ftol                                           undefined __ftol()
    //         00441cc2     MOV        this,dword ptr [EBP*0x4 + unified_map_offsets]   = 00000000
    //                              dpl_obj.cpp:209 (6)
    //         00441cc9     MOV        dword ptr [ESI + 0xa0],EBX
    //                              dpl_obj.cpp:210 (15)
    //         00441ccf     MOV        dword ptr [ESI + 0xa4],EBX
    //         00441cd5     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         00441cd8     MOV        dword ptr [ESI + 0x9c],EDX
    //                              dpl_obj.cpp:213 (7)
    //         00441cde     MOV        AL,byte ptr [EDI + 0x48]
    //         00441ce1     CMP        AL,0x7
    //         00441ce3     JC         LAB_00441d1f
    //                              dpl_obj.cpp:232 (26)
    //         00441ce5     MOV        EDX,dword ptr [ESI]
    //         00441ce7     MOV        this,ESI
    //         00441ce9     MOV        dword ptr [ESI + 0x8c],EBX
    //         00441cef     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441cf9     CALL       dword ptr [EDX + 0x1f0]
    //                              dpl_obj.cpp:235 (7)
    //         00441cff     POP        EDI
    //         00441d00     POP        ESI
    //         00441d01     POP        EBP
    //         00441d02     POP        EBX
    //         00441d03     RET        0x18
    //                               LAB_00441d06                                                 XREF[1]:     00441c27(j)  
    //                              dpl_obj.cpp:228 (25)
    //         00441d06     MOV        EAX,dword ptr [ESI]
    //         00441d08     MOV        this,ESI
    //         00441d0a     MOV        dword ptr [ESI + 0xac],EDI
    //         00441d10     MOV        dword ptr [ESI + 0x94],EBX
    //         00441d16     MOV        dword ptr [ESI + 0x98],EBX
    //         00441d1c     CALL       dword ptr [EAX + 0x68]
    //                               LAB_00441d1f                                                 XREF[1]:     00441ce3(j)  
    //                              dpl_obj.cpp:232 (10)
    //         00441d1f     MOV        EDX,dword ptr [ESI]
    //         00441d21     MOV        this,ESI
    //         00441d23     CALL       dword ptr [EDX + 0x1f0]
    //                              dpl_obj.cpp:235 (7)
    //         00441d29     POP        EDI
    //         00441d2a     POP        ESI
    //         00441d2b     POP        EBP
    //         00441d2c     POP        EBX
    //         00441d2d     RET        0x18
    //                              * protected: virtual int __thiscall RGE_Doppleganger_Object::setup(class RGE_Master_Doppleganger_Obj... *
    //                              int __thiscall setup(RGE_Doppleganger_Object * this, RGE_Master_Dopp
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Master_Dop    Stack[0x4]:4   param_1                   XREF[1]:     00441d46(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00441d41(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00441d34(R), 00441d61(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     00441d3b(R), 00441d54(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00441d30(R)  
    //                               ?setup@RGE_Doppleganger_Object@@MAEHPAVRGE_Master_Dopplegan  XREF[2]:     RGE_Doppleganger_Object:00441948(c
    //                               RGE_Doppleganger_Object::setup                                            00570414(*)  
    //                              dpl_obj.cpp:239 (36)
    //         00441d30     MOV        EAX,dword ptr [ESP + param_5]
    //         00441d34     MOV        EDX,dword ptr [ESP + param_3]
    //         00441d38     PUSH       ESI
    //         00441d39     MOV        ESI,this
    //         00441d3b     MOV        this,dword ptr [ESP + param_4]
    //         00441d3f     PUSH       EDI
    //         00441d40     PUSH       EAX
    //         00441d41     MOV        EAX,dword ptr [ESP + param_2]
    //         00441d45     PUSH       this
    //         00441d46     MOV        this,dword ptr [ESP + param_1]
    //         00441d4a     PUSH       EDX
    //         00441d4b     PUSH       EAX
    //         00441d4c     PUSH       this
    //         00441d4d     MOV        this,ESI
    //         00441d4f     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, RGE_Mas
    //                              dpl_obj.cpp:244 (31)
    //         00441d54     FLD        float ptr [ESP + param_4]
    //         00441d58     MOV        byte ptr [ESI + 0x4e],0x19
    //         00441d5c     CALL       __ftol                                           undefined __ftol()
    //         00441d61     FLD        float ptr [ESP + param_3]
    //         00441d65     MOV        EDI,EAX
    //         00441d67     CALL       __ftol                                           undefined __ftol()
    //         00441d6c     MOV        EDX,dword ptr [EDI*0x4 + unified_map_offsets]    = 00000000
    //                              dpl_obj.cpp:250 (33)
    //         00441d73     POP        EDI
    //         00441d74     LEA        EAX,[EDX + EAX*0x4]
    //         00441d77     MOV        dword ptr [ESI + 0x9c],EAX
    //         00441d7d     XOR        EAX,EAX
    //         00441d7f     MOV        dword ptr [ESI + 0xa0],EAX
    //         00441d85     MOV        dword ptr [ESI + 0xa4],EAX
    //         00441d8b     MOV        EAX,0x1
    //         00441d90     POP        ESI
    //         00441d91     RET        0x14
    //         00441d94     ??         90h
    //         00441d95     NOP
    //         00441d96     NOP
    //         00441d97     NOP
    //         00441d98     NOP
    //         00441d99     NOP
    //         00441d9a     NOP
    //         00441d9b     NOP
    //         00441d9c     NOP
    //         00441d9d     NOP
    //         00441d9e     NOP
    //         00441d9f     NOP
}

int RGE_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Doppleganger_Object * this, int param_1, RG
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00441da8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00441da0(R)  
    //                               ?setup@RGE_Doppleganger_Object@@MAEHHPAVRGE_Game_World@@@Z   XREF[2]:     RGE_Doppleganger_Object:00441aff(c
    //                               RGE_Doppleganger_Object::setup                                            005703f8(*)  
    //                              dpl_obj.cpp:254 (21)
    //         00441da0     MOV        EAX,dword ptr [ESP + param_2]
    //         00441da4     PUSH       ESI
    //         00441da5     MOV        ESI,this
    //         00441da7     PUSH       EDI
    //         00441da8     MOV        this,dword ptr [ESP + param_1]
    //         00441dac     PUSH       EAX
    //         00441dad     PUSH       this
    //         00441dae     MOV        this,ESI
    //         00441db0     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, int par
    //                              dpl_obj.cpp:259 (29)
    //         00441db5     FLD        float ptr [ESI + 0x3c]
    //         00441db8     MOV        byte ptr [ESI + 0x4e],0x19
    //         00441dbc     CALL       __ftol                                           undefined __ftol()
    //         00441dc1     FLD        float ptr [ESI + 0x38]
    //         00441dc4     MOV        EDI,EAX
    //         00441dc6     CALL       __ftol                                           undefined __ftol()
    //         00441dcb     MOV        EDX,dword ptr [EDI*0x4 + unified_map_offsets]    = 00000000
    //                              dpl_obj.cpp:276 (33)
    //         00441dd2     POP        EDI
    //         00441dd3     LEA        EAX,[EDX + EAX*0x4]
    //         00441dd6     MOV        dword ptr [ESI + 0x9c],EAX
    //         00441ddc     XOR        EAX,EAX
    //         00441dde     MOV        dword ptr [ESI + 0xa0],EAX
    //         00441de4     MOV        dword ptr [ESI + 0xa4],EAX
    //         00441dea     MOV        EAX,0x1
    //         00441def     POP        ESI
    //         00441df0     RET        0x8
    //         00441df3     ??         90h
    //         00441df4     NOP
    //         00441df5     NOP
    //         00441df6     NOP
    //         00441df7     NOP
    //         00441df8     NOP
    //         00441df9     NOP
    //         00441dfa     NOP
    //         00441dfb     NOP
    //         00441dfc     NOP
    //         00441dfd     NOP
    //         00441dfe     NOP
    //         00441dff     NOP
    return 0;
}

int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Doppleganger_Object * this, int param_1, RG
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00441da8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00441da0(R)  
    //                               ?setup@RGE_Doppleganger_Object@@MAEHHPAVRGE_Game_World@@@Z   XREF[2]:     RGE_Doppleganger_Object:00441aff(c
    //                               RGE_Doppleganger_Object::setup                                            005703f8(*)  
    //                              dpl_obj.cpp:254 (21)
    //         00441da0     MOV        EAX,dword ptr [ESP + param_2]
    //         00441da4     PUSH       ESI
    //         00441da5     MOV        ESI,this
    //         00441da7     PUSH       EDI
    //         00441da8     MOV        this,dword ptr [ESP + param_1]
    //         00441dac     PUSH       EAX
    //         00441dad     PUSH       this
    //         00441dae     MOV        this,ESI
    //         00441db0     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, int par
    //                              dpl_obj.cpp:259 (29)
    //         00441db5     FLD        float ptr [ESI + 0x3c]
    //         00441db8     MOV        byte ptr [ESI + 0x4e],0x19
    //         00441dbc     CALL       __ftol                                           undefined __ftol()
    //         00441dc1     FLD        float ptr [ESI + 0x38]
    //         00441dc4     MOV        EDI,EAX
    //         00441dc6     CALL       __ftol                                           undefined __ftol()
    //         00441dcb     MOV        EDX,dword ptr [EDI*0x4 + unified_map_offsets]    = 00000000
    //                              dpl_obj.cpp:276 (33)
    //         00441dd2     POP        EDI
    //         00441dd3     LEA        EAX,[EDX + EAX*0x4]
    //         00441dd6     MOV        dword ptr [ESI + 0x9c],EAX
    //         00441ddc     XOR        EAX,EAX
    //         00441dde     MOV        dword ptr [ESI + 0xa0],EAX
    //         00441de4     MOV        dword ptr [ESI + 0xa4],EAX
    //         00441dea     MOV        EAX,0x1
    //         00441def     POP        ESI
    //         00441df0     RET        0x8
    //         00441df3     ??         90h
    //         00441df4     NOP
    //         00441df5     NOP
    //         00441df6     NOP
    //         00441df7     NOP
    //         00441df8     NOP
    //         00441df9     NOP
    //         00441dfa     NOP
    //         00441dfb     NOP
    //         00441dfc     NOP
    //         00441dfd     NOP
    //         00441dfe     NOP
    //         00441dff     NOP
    return 0;
}

void RGE_Doppleganger_Object::rehook() {
    /* TODO: Stub */
    //                              void __thiscall rehook(RGE_Doppleganger_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //                               ?rehook@RGE_Doppleganger_Object@@UAEXXZ                      XREF[1]:     0057024c(*)  
    //                               RGE_Doppleganger_Object::rehook
    //                              dpl_obj.cpp:280 (3)
    //         00441e00     PUSH       ESI
    //         00441e01     MOV        ESI,this
    //                              dpl_obj.cpp:284 (5)
    //         00441e03     CALL       RGE_Static_Object::rehook                        void rehook(RGE_Static_Object * this)
    //                              dpl_obj.cpp:286 (10)
    //         00441e08     MOV        this,dword ptr [ESI + 0x8c]
    //         00441e0e     TEST       this,this
    //         00441e10     JL         LAB_00441e32
    //                              dpl_obj.cpp:289 (8)
    //         00441e12     PUSH       this
    //         00441e13     MOV        this,ESI
    //         00441e15     CALL       RGE_Static_Object::get_object_pointer            RGE_Static_Object * get_object_pointer(RGE_St
    //                              dpl_obj.cpp:294 (10)
    //         00441e1a     TEST       EAX,EAX
    //         00441e1c     MOV        dword ptr [ESI + 0x8c],EAX
    //         00441e22     JZ         LAB_00441e63
    //                              dpl_obj.cpp:296 (9)
    //         00441e24     MOV        this,dword ptr [EAX + 0x4]
    //         00441e27     MOV        dword ptr [ESI + 0xac],this
    //                              dpl_obj.cpp:297 (3)
    //         00441e2d     MOV        EDX,dword ptr [EAX + 0xc]
    //                              dpl_obj.cpp:300 (2)
    //         00441e30     JMP        LAB_00441e57
    //                               LAB_00441e32                                                 XREF[1]:     00441e10(j)  
    //                              dpl_obj.cpp:302 (3)
    //         00441e32     OR         EAX,0xffffffff
    //                              dpl_obj.cpp:303 (12)
    //         00441e35     MOV        dword ptr [ESI + 0x8c],0x0
    //         00441e3f     SUB        EAX,this
    //                              dpl_obj.cpp:305 (34)
    //         00441e41     MOV        this,dword ptr [ESI + 0xc]
    //         00441e44     MOV        dword ptr [ESI + 0xac],0xffffffff
    //         00441e4e     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00441e51     MOV        this,dword ptr [EDX + 0x40]
    //         00441e54     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //                               LAB_00441e57                                                 XREF[1]:     00441e30(j)  
    //         00441e57     MOV        EAX,dword ptr [EDX + 0x108]
    //         00441e5d     MOV        dword ptr [ESI + 0x90],EAX
    //                               LAB_00441e63                                                 XREF[1]:     00441e22(j)  
    //                              dpl_obj.cpp:308 (6)
    //         00441e63     MOV        EAX,dword ptr [ESI + 0x94]
    //                              dpl_obj.cpp:309 (30)
    //         00441e69     TEST       EAX,EAX
    //         00441e6b     JL         LAB_00441e95
    //         00441e6d     MOV        this,dword ptr [ESI + 0xc]
    //         00441e70     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00441e73     MOV        this,dword ptr [ESI + 0x98]
    //         00441e79     MOV        EDX,dword ptr [EDX + 0x40]
    //         00441e7c     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00441e7f     MOVSX      EDX,word ptr [ECX + this+0x22]
    //         00441e83     CMP        EAX,EDX
    //         00441e85     JGE        LAB_00441e95
    //                              dpl_obj.cpp:311 (12)
    //         00441e87     MOV        this,dword ptr [ECX + this->_padding_]
    //         00441e8a     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         00441e8d     MOV        dword ptr [ESI + 0x94],EDX
    //                              dpl_obj.cpp:327 (2)
    //         00441e93     POP        ESI
    //         00441e94     RET
    //                               LAB_00441e95                                                 XREF[2]:     00441e6b(j), 00441e85(j)  
    //                              dpl_obj.cpp:323 (17)
    //         00441e95     MOV        EAX,dword ptr [ESI]
    //         00441e97     MOV        this,ESI
    //         00441e99     MOV        dword ptr [ESI + 0x94],0x0
    //         00441ea3     CALL       dword ptr [EAX + 0x68]
    //                              dpl_obj.cpp:327 (2)
    //         00441ea6     POP        ESI
    //         00441ea7     RET
    //         00441ea8     ??         90h
    //         00441ea9     NOP
    //         00441eaa     NOP
    //         00441eab     NOP
    //         00441eac     NOP
    //         00441ead     NOP
    //         00441eae     NOP
    //         00441eaf     NOP
    return;
}

uchar RGE_Doppleganger_Object::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Doppleganger_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //                               ?update@RGE_Doppleganger_Object@@UAEEXZ                      XREF[1]:     00570244(*)  
    //                               RGE_Doppleganger_Object::update
    //                              dpl_obj.cpp:331 (6)
    //         00441eb0     PUSH       EBX
    //         00441eb1     PUSH       EBP
    //         00441eb2     PUSH       ESI
    //         00441eb3     PUSH       EDI
    //         00441eb4     MOV        ESI,this
    //                              dpl_obj.cpp:341 (7)
    //         00441eb6     CALL       RGE_Animated_Object::update                      uchar update(RGE_Animated_Object * this)
    //         00441ebb     MOV        BL,AL
    //                              dpl_obj.cpp:343 (10)
    //         00441ebd     MOV        EAX,dword ptr [ESI + 0x8c]
    //         00441ec3     TEST       EAX,EAX
    //         00441ec5     JZ         LAB_00441ed7
    //                              dpl_obj.cpp:345 (6)
    //         00441ec7     CMP        byte ptr [EAX + 0x48],0x7
    //         00441ecb     JC         LAB_00441ee1
    //                              dpl_obj.cpp:347 (10)
    //         00441ecd     MOV        dword ptr [ESI + 0x8c],0x0
    //                               LAB_00441ed7                                                 XREF[1]:     00441ec5(j)  
    //                              dpl_obj.cpp:353 (10)
    //         00441ed7     MOV        dword ptr [ESI + 0xac],0xffffffff
    //                               LAB_00441ee1                                                 XREF[1]:     00441ecb(j)  
    //                              dpl_obj.cpp:358 (8)
    //         00441ee1     MOV        EAX,dword ptr [ESI + 0x9c]
    //         00441ee7     MOV        EDI,dword ptr [EAX]
    //                              dpl_obj.cpp:360 (10)
    //         00441ee9     MOV        EAX,dword ptr [ESI + 0xa0]
    //         00441eef     CMP        EDI,EAX
    //         00441ef1     JZ         LAB_00441f6d
    //                              dpl_obj.cpp:364 (11)
    //         00441ef3     MOV        EAX,dword ptr [ESI + 0xc]
    //         00441ef6     TEST       dword ptr [EAX + 0xd4],EDI
    //         00441efc     JZ         LAB_00441f33
    //                              dpl_obj.cpp:366 (6)
    //         00441efe     CMP        byte ptr [ESI + 0x48],0x3
    //         00441f02     JNC        LAB_00441f33
    //                              dpl_obj.cpp:369 (40)
    //         00441f04     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         00441f0a     TEST       this,this
    //         00441f0c     JZ         LAB_00441f2c
    //         00441f0e     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         00441f12     MOV        EAX,dword ptr [EAX + 0x3c]
    //         00441f15     PUSH       EDX
    //         00441f16     MOV        EDX,dword ptr [ESI + 0x4]
    //         00441f19     PUSH       EDX
    //         00441f1a     MOV        EDX,dword ptr [EAX + 0x4]
    //         00441f1d     PUSH       EDX
    //         00441f1e     PUSH       s_DIE_DOP_(@%d)_id=%d_own=%d_                    = "DIE DOP (@%d) id=%d own=%d\n"
    //         00441f23     PUSH       this
    //         00441f24     CALL       fprintf                                          undefined fprintf()
    //         00441f29     ADD        ESP,0x14
    //                               LAB_00441f2c                                                 XREF[1]:     00441f0c(j)  
    //                              dpl_obj.cpp:372 (7)
    //         00441f2c     MOV        EAX,dword ptr [ESI]
    //         00441f2e     MOV        this,ESI
    //         00441f30     CALL       dword ptr [EAX + 0x68]
    //                               LAB_00441f33                                                 XREF[2]:     00441efc(j), 00441f02(j)  
    //                              dpl_obj.cpp:380 (11)
    //         00441f33     MOV        this,dword ptr [ESI + 0xc]
    //         00441f36     MOV        EAX,dword ptr [this->_padding_ + 0xd8]
    //         00441f3c     AND        EAX,EDI
    //                              dpl_obj.cpp:382 (2)
    //         00441f3e     JZ         LAB_00441f67
    //                              dpl_obj.cpp:378 (6)
    //         00441f40     ADD        this,0xdc
    //                               LAB_00441f46                                                 XREF[1]:     00441f65(j)  
    //                              dpl_obj.cpp:384 (10)
    //         00441f46     MOV        EDX,EAX
    //         00441f48     AND        EDX,0x1
    //         00441f4b     CMP        DL,0x1
    //         00441f4e     JNZ        LAB_00441f60
    //                              dpl_obj.cpp:386 (16)
    //         00441f50     MOV        EDX,dword ptr [this->_padding_]
    //         00441f52     MOV        EBP,dword ptr [ESI + 0xa4]
    //         00441f58     OR         EBP,EDX
    //         00441f5a     MOV        dword ptr [ESI + 0xa4],EBP
    //                               LAB_00441f60                                                 XREF[1]:     00441f4e(j)  
    //                              dpl_obj.cpp:388 (3)
    //         00441f60     ADD        this,0x4
    //                              dpl_obj.cpp:389 (4)
    //         00441f63     SHR        EAX,0x1
    //         00441f65     JNZ        LAB_00441f46
    //                               LAB_00441f67                                                 XREF[1]:     00441f3e(j)  
    //                              dpl_obj.cpp:392 (6)
    //         00441f67     MOV        dword ptr [ESI + 0xa0],EDI
    //                               LAB_00441f6d                                                 XREF[1]:     00441ef1(j)  
    //                              dpl_obj.cpp:414 (7)
    //         00441f6d     POP        EDI
    //         00441f6e     POP        ESI
    //         00441f6f     MOV        AL,BL
    //         00441f71     POP        EBP
    //         00441f72     POP        EBX
    //         00441f73     RET
    //         00441f74     ??         90h
    //         00441f75     NOP
    //         00441f76     NOP
    //         00441f77     NOP
    //         00441f78     NOP
    //         00441f79     NOP
    //         00441f7a     NOP
    //         00441f7b     NOP
    //         00441f7c     NOP
    //         00441f7d     NOP
    //         00441f7e     NOP
    //         00441f7f     NOP
    return 0;
}

void RGE_Doppleganger_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Doppleganger_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     00441f82(R), 00441f9b(W), 00441fac(W), 00441fb0(*), 
    //                                                                                     00441ff2(W), 00441ff8(W), 00442000(*)  
    //                               ?save@RGE_Doppleganger_Object@@UAEXH@Z                       XREF[1]:     00570250(*)  
    //                               RGE_Doppleganger_Object::save
    //                              dpl_obj.cpp:418 (2)
    //         00441f80     PUSH       ESI
    //         00441f81     PUSH       EDI
    //                              dpl_obj.cpp:421 (12)
    //         00441f82     MOV        EDI,dword ptr [ESP + param_1]
    //         00441f86     MOV        ESI,this
    //         00441f88     PUSH       EDI
    //         00441f89     CALL       RGE_Animated_Object::save                        void save(RGE_Animated_Object * this, int par
    //                              dpl_obj.cpp:423 (10)
    //         00441f8e     MOV        EAX,dword ptr [ESI + 0x8c]
    //         00441f94     TEST       EAX,EAX
    //         00441f96     JZ         LAB_00441fa1
    //                              dpl_obj.cpp:424 (7)
    //         00441f98     MOV        EAX,dword ptr [EAX + 0x4]
    //         00441f9b     MOV        dword ptr [ESP + param_1],EAX
    //                              dpl_obj.cpp:425 (2)
    //         00441f9f     JMP        LAB_00441fb0
    //                               LAB_00441fa1                                                 XREF[1]:     00441f96(j)  
    //                              dpl_obj.cpp:427 (15)
    //         00441fa1     MOV        EAX,dword ptr [ESI + 0x98]
    //         00441fa7     OR         this,0xffffffff
    //         00441faa     SUB        this,EAX
    //         00441fac     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00441fb0                                                 XREF[1]:     00441f9f(j)  
    //                              dpl_obj.cpp:437 (16)
    //         00441fb0     LEA        EDX=>param_1,[ESP + 0xc]
    //         00441fb4     PUSH       0x4
    //         00441fb6     PUSH       EDX
    //         00441fb7     PUSH       EDI
    //         00441fb8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00441fbd     ADD        ESP,0xc
    //                              dpl_obj.cpp:439 (18)
    //         00441fc0     LEA        EAX,[ESI + 0xa8]
    //         00441fc6     PUSH       0x1
    //         00441fc8     PUSH       EAX
    //         00441fc9     PUSH       EDI
    //         00441fca     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00441fcf     ADD        ESP,0xc
    //                              dpl_obj.cpp:440 (15)
    //         00441fd2     LEA        this,[ESI + 0xa9]
    //         00441fd8     PUSH       0x4
    //         00441fda     PUSH       this
    //         00441fdb     PUSH       EDI
    //         00441fdc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              dpl_obj.cpp:442 (13)
    //         00441fe1     MOV        EAX,dword ptr [ESI + 0x94]
    //         00441fe7     ADD        ESP,0xc
    //         00441fea     TEST       EAX,EAX
    //         00441fec     JZ         LAB_00441ff8
    //                              dpl_obj.cpp:443 (8)
    //         00441fee     MOVSX      EDX,word ptr [EAX + 0x10]
    //         00441ff2     MOV        dword ptr [ESP + param_1],EDX
    //                              dpl_obj.cpp:444 (2)
    //         00441ff6     JMP        LAB_00442000
    //                               LAB_00441ff8                                                 XREF[1]:     00441fec(j)  
    //                              dpl_obj.cpp:446 (8)
    //         00441ff8     MOV        dword ptr [ESP + param_1],0xffffffff
    //                               LAB_00442000                                                 XREF[1]:     00441ff6(j)  
    //                              dpl_obj.cpp:452 (16)
    //         00442000     LEA        EAX=>param_1,[ESP + 0xc]
    //         00442004     PUSH       0x4
    //         00442006     PUSH       EAX
    //         00442007     PUSH       EDI
    //         00442008     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044200d     ADD        ESP,0xc
    //                              dpl_obj.cpp:454 (15)
    //         00442010     LEA        this,[ESI + 0x98]
    //         00442016     PUSH       0x4
    //         00442018     PUSH       this
    //         00442019     PUSH       EDI
    //         0044201a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              dpl_obj.cpp:456 (22)
    //         0044201f     FLD        float ptr [save_game_version]                    = 7.23
    //         00442025     FCOMP      float ptr [DAT_00570418]                         = 85h
    //         0044202b     ADD        ESP,0xc
    //         0044202e     FNSTSW     AX
    //         00442030     TEST       AH,0x1
    //         00442033     JNZ        LAB_00442047
    //                              dpl_obj.cpp:458 (18)
    //         00442035     ADD        ESI,0xa4
    //         0044203b     PUSH       0x4
    //         0044203d     PUSH       ESI
    //         0044203e     PUSH       EDI
    //         0044203f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00442044     ADD        ESP,0xc
    //                               LAB_00442047                                                 XREF[1]:     00442033(j)  
    //                              dpl_obj.cpp:462 (5)
    //         00442047     POP        EDI
    //         00442048     POP        ESI
    //         00442049     RET        0x4
    //         0044204c     ??         90h
    //         0044204d     NOP
    //         0044204e     NOP
    //         0044204f     NOP
    return;
}

void RGE_Doppleganger_Object::validate() {
    /* TODO: Stub */
    //                              void __thiscall validate(RGE_Doppleganger_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //                               ?validate@RGE_Doppleganger_Object@@UAEXXZ                    XREF[2]:     RGE_Doppleganger_Object:00441a1e(c
    //                               RGE_Doppleganger_Object::validate                                         00570410(*)  
    //                              dpl_obj.cpp:467 (5)
    //         00442050     PUSH       EBX
    //         00442051     PUSH       ESI
    //         00442052     MOV        ESI,this
    //         00442054     PUSH       EDI
    //                              dpl_obj.cpp:473 (43)
    //         00442055     MOV        EAX,dword ptr [ESI + 0xc]
    //         00442058     FLD        float ptr [ESI + 0x3c]
    //         0044205b     MOV        this,dword ptr [EAX + 0x3c]
    //         0044205e     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         00442061     CALL       __ftol                                           undefined __ftol()
    //         00442066     FLD        float ptr [ESI + 0x38]
    //         00442069     MOV        EDI,dword ptr [EDI + 0x8d8c]
    //         0044206f     MOV        EBX,EAX
    //         00442071     CALL       __ftol                                           undefined __ftol()
    //         00442076     LEA        EDX,[EAX + EAX*0x2]
    //         00442079     MOV        EAX,dword ptr [EDI + EBX*0x4]
    //         0044207c     MOV        EDI,dword ptr [EAX + EDX*0x8 + 0x10]
    //                              dpl_obj.cpp:476 (7)
    //         00442080     TEST       EDI,EDI
    //         00442082     JZ         LAB_004420f8
    //         00442084     PUSH       EBP
    //         00442085     MOV        BL,0x2
    //                               LAB_00442087                                                 XREF[1]:     004420f5(j)  
    //                              dpl_obj.cpp:478 (2)
    //         00442087     MOV        EAX,dword ptr [EDI]
    //                              dpl_obj.cpp:480 (4)
    //         00442089     TEST       EAX,EAX
    //         0044208b     JZ         LAB_004420f0
    //                              dpl_obj.cpp:482 (6)
    //         0044208d     CMP        byte ptr [EAX + 0x4e],0x19
    //         00442091     JNZ        LAB_004420f0
    //                              dpl_obj.cpp:486 (31)
    //         00442093     MOV        this,dword ptr [EAX + 0x4]
    //         00442096     MOV        EDX,dword ptr [ESI + 0x4]
    //         00442099     CMP        this,EDX
    //         0044209b     JZ         LAB_004420f0
    //         0044209d     MOV        EDX,dword ptr [EAX + 0xac]
    //         004420a3     MOV        this,dword ptr [ESI + 0xac]
    //         004420a9     CMP        EDX,this
    //         004420ab     JNZ        LAB_004420f0
    //         004420ad     CMP        byte ptr [EAX + 0x48],BL
    //         004420b0     JNZ        LAB_004420f0
    //                              dpl_obj.cpp:488 (16)
    //         004420b2     MOV        this,dword ptr [ESI + 0xc]
    //         004420b5     MOV        EDX,dword ptr [EAX + 0xc]
    //         004420b8     MOV        this,word ptr [ECX + this+0x4a]
    //         004420bc     CMP        word ptr [EDX + 0x4a],this
    //         004420c0     JNZ        LAB_004420cb
    //                              dpl_obj.cpp:490 (7)
    //         004420c2     MOV        EDX,dword ptr [EAX]
    //         004420c4     MOV        this,EAX
    //         004420c6     CALL       dword ptr [EDX + 0x68]
    //                              dpl_obj.cpp:492 (2)
    //         004420c9     JMP        LAB_004420f0
    //                               LAB_004420cb                                                 XREF[1]:     004420c0(j)  
    //                              dpl_obj.cpp:494 (21)
    //         004420cb     MOV        EBP,0x1
    //         004420d0     SHL        EBP,this
    //         004420d2     MOV        this,dword ptr [EAX + 0xa4]
    //         004420d8     OR         this,EBP
    //         004420da     MOV        dword ptr [EAX + 0xa4],this
    //                              dpl_obj.cpp:495 (16)
    //         004420e0     MOV        this,byte ptr [EDX + 0x4a]
    //         004420e3     MOV        EAX,0x1
    //         004420e8     SHL        EAX,this
    //         004420ea     OR         dword ptr [ESI + 0xa4],EAX
    //                               LAB_004420f0                                                 XREF[6]:     0044208b(j), 00442091(j), 
    //                                                                                                         0044209b(j), 004420ab(j), 
    //                                                                                                         004420b0(j), 004420c9(j)  
    //                              dpl_obj.cpp:502 (7)
    //         004420f0     MOV        EDI,dword ptr [EDI + 0x4]
    //         004420f3     TEST       EDI,EDI
    //         004420f5     JNZ        LAB_00442087
    //                              dpl_obj.cpp:467 (1)
    //         004420f7     POP        EBP
    //                               LAB_004420f8                                                 XREF[1]:     00442082(j)  
    //                              dpl_obj.cpp:506 (4)
    //         004420f8     POP        EDI
    //         004420f9     POP        ESI
    //         004420fa     POP        EBX
    //         004420fb     RET
    //         004420fc     ??         90h
    //         004420fd     NOP
    //         004420fe     NOP
    //         004420ff     NOP
    return;
}

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Player* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Doppleganger_Creator(RGE_Doppleganger_Creat
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0044213d(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00442102(R)  
    //                               ??0RGE_Doppleganger_Creator@@QAE@PAVRGE_Player@@H@Z          XREF[2]:     RGE_Player:0046e54b(c), 
    //                               RGE_Doppleganger_Creator::RGE_Doppleganger_Creator                        RGE_Player:0046e9eb(c)  
    //                              dpl_obj.cpp:515 (2)
    //         00442100     PUSH       ESI
    //         00442101     PUSH       EDI
    //                              dpl_obj.cpp:516 (20)
    //         00442102     MOV        EDI,dword ptr [ESP + param_2]
    //         00442106     PUSH       0x4
    //         00442108     MOV        ESI,this
    //         0044210a     PUSH       EDI
    //         0044210b     CALL       calloc                                           undefined calloc()
    //         00442110     ADD        ESP,0x8
    //         00442113     MOV        dword ptr [ESI + 0xc],EAX
    //                              dpl_obj.cpp:517 (14)
    //         00442116     PUSH       0x4
    //         00442118     PUSH       EDI
    //         00442119     CALL       calloc                                           undefined calloc()
    //         0044211e     ADD        ESP,0x8
    //         00442121     MOV        dword ptr [ESI + 0x10],EAX
    //                              dpl_obj.cpp:518 (14)
    //         00442124     PUSH       0x4
    //         00442126     PUSH       EDI
    //         00442127     CALL       calloc                                           undefined calloc()
    //         0044212c     ADD        ESP,0x8
    //         0044212f     MOV        dword ptr [ESI + 0x14],EAX
    //                              dpl_obj.cpp:519 (11)
    //         00442132     PUSH       0x4
    //         00442134     PUSH       EDI
    //         00442135     CALL       calloc                                           undefined calloc()
    //         0044213a     MOV        dword ptr [ESI + 0x18],EAX
    //                              dpl_obj.cpp:524 (16)
    //         0044213d     MOV        EAX,dword ptr [ESP + param_1]
    //         00442141     MOV        dword ptr [ESI + 0x4],EDI
    //         00442144     MOV        dword ptr [ESI + 0x8],0x0
    //         0044214b     MOV        dword ptr [ESI],EAX
    //                              dpl_obj.cpp:527 (12)
    //         0044214d     MOV        EAX,[DDlogf]                                     = 00000000
    //         00442152     ADD        ESP,0x8
    //         00442155     TEST       EAX,EAX
    //         00442157     JNZ        LAB_00442170
    //                              dpl_obj.cpp:529 (23)
    //         00442159     PUSH       s_w                                              = "w"
    //         0044215e     PUSH       s_c:\aoedoppl.txt                                = "c:\\aoedoppl.txt"
    //         00442163     CALL       fopen                                            undefined fopen()
    //         00442168     ADD        ESP,0x8
    //         0044216b     MOV        [DDlogf],EAX                                     = 00000000
    //                               LAB_00442170                                                 XREF[1]:     00442157(j)  
    //                              dpl_obj.cpp:533 (7)
    //         00442170     MOV        EAX,ESI
    //         00442172     POP        EDI
    //         00442173     POP        ESI
    //         00442174     RET        0x8
    //         00442177     ??         90h
    //         00442178     NOP
    //         00442179     NOP
    //         0044217a     NOP
    //         0044217b     NOP
    //         0044217c     NOP
    //         0044217d     NOP
    //         0044217e     NOP
    //         0044217f     NOP
}

RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Doppleganger_Creator(RGE_Doppleganger_Creator *
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //                               ??1RGE_Doppleganger_Creator@@QAE@XZ                          XREF[1]:     ~RGE_Player:0046ebfd(c)  
    //                               RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator
    //                              dpl_obj.cpp:538 (3)
    //         00442180     PUSH       ESI
    //         00442181     MOV        ESI,this
    //                              dpl_obj.cpp:539 (16)
    //         00442183     MOV        EAX,dword ptr [ESI + 0xc]
    //         00442186     TEST       EAX,EAX
    //         00442188     JZ         LAB_00442193
    //         0044218a     PUSH       EAX
    //         0044218b     CALL       free                                             undefined free()
    //         00442190     ADD        ESP,0x4
    //                               LAB_00442193                                                 XREF[1]:     00442188(j)  
    //                              dpl_obj.cpp:540 (16)
    //         00442193     MOV        EAX,dword ptr [ESI + 0x10]
    //         00442196     TEST       EAX,EAX
    //         00442198     JZ         LAB_004421a3
    //         0044219a     PUSH       EAX
    //         0044219b     CALL       free                                             undefined free()
    //         004421a0     ADD        ESP,0x4
    //                               LAB_004421a3                                                 XREF[1]:     00442198(j)  
    //                              dpl_obj.cpp:541 (16)
    //         004421a3     MOV        EAX,dword ptr [ESI + 0x14]
    //         004421a6     TEST       EAX,EAX
    //         004421a8     JZ         LAB_004421b3
    //         004421aa     PUSH       EAX
    //         004421ab     CALL       free                                             undefined free()
    //         004421b0     ADD        ESP,0x4
    //                               LAB_004421b3                                                 XREF[1]:     004421a8(j)  
    //                              dpl_obj.cpp:542 (16)
    //         004421b3     MOV        ESI,dword ptr [ESI + 0x18]
    //         004421b6     TEST       ESI,ESI
    //         004421b8     JZ         LAB_004421c3
    //         004421ba     PUSH       ESI
    //         004421bb     CALL       free                                             undefined free()
    //         004421c0     ADD        ESP,0x4
    //                               LAB_004421c3                                                 XREF[1]:     004421b8(j)  
    //                              dpl_obj.cpp:545 (9)
    //         004421c3     MOV        EAX,[DDlogf]                                     = 00000000
    //         004421c8     TEST       EAX,EAX
    //         004421ca     JZ         LAB_004421df
    //                              dpl_obj.cpp:547 (9)
    //         004421cc     PUSH       EAX
    //         004421cd     CALL       fclose                                           undefined fclose()
    //         004421d2     ADD        ESP,0x4
    //                              dpl_obj.cpp:548 (10)
    //         004421d5     MOV        dword ptr [DDlogf],0x0                           = 00000000
    //                               LAB_004421df                                                 XREF[1]:     004421ca(j)  
    //                              dpl_obj.cpp:552 (2)
    //         004421df     POP        ESI
    //         004421e0     RET
    //         004421e1     ??         90h
    //         004421e2     NOP
    //         004421e3     NOP
    //         004421e4     NOP
    //         004421e5     NOP
    //         004421e6     NOP
    //         004421e7     NOP
    //         004421e8     NOP
    //         004421e9     NOP
    //         004421ea     NOP
    //         004421eb     NOP
    //         004421ec     NOP
    //         004421ed     NOP
    //         004421ee     NOP
    //         004421ef     NOP
    //                              * public: int __thiscall RGE_Doppleganger_Creator::add_doppleganger_check(class RGE_Static_Object *,... *
    //                              int __thiscall add_doppleganger_check(RGE_Doppleganger_Creator * thi
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004421fa(R)  
    //              ulong *           Stack[0x8]:4   param_2                   XREF[1]:     0044226a(R)  
    //                               ?add_doppleganger_check@RGE_Doppleganger_Creator@@QAEHPAVRG  XREF[4]:     create_doppleganger_when_dying:004
    //                               RGE_Doppleganger_Creator::add_doppleganger_check                          TRIBE_Building_Object:004c8041(c), 
    //                                                                                                         TRIBE_Building_Object:004c8184(c), 
    //                                                                                                         TRIBE_Building_Object:004c827d(c)  
    //                              dpl_obj.cpp:557 (4)
    //         004421f0     PUSH       ESI
    //         004421f1     MOV        ESI,this
    //         004421f3     PUSH       EDI
    //                              dpl_obj.cpp:560 (14)
    //         004421f4     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         004421fa     MOV        EDI,dword ptr [ESP + param_1]
    //         004421fe     TEST       this,this
    //         00442200     JZ         LAB_00442222
    //                              dpl_obj.cpp:561 (32)
    //         00442202     MOV        EAX,dword ptr [ESI]
    //         00442204     MOV        EDX,dword ptr [EDI + 0x4]
    //         00442207     PUSH       EDX
    //         00442208     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0044220c     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0044220f     PUSH       EDX
    //         00442210     MOV        EDX,dword ptr [EAX + 0x4]
    //         00442213     PUSH       EDX
    //         00442214     PUSH       s_ADC_(@%d)_p=%d__id=%d_                         = "ADC (@%d) p=%d  id=%d\n"
    //         00442219     PUSH       this
    //         0044221a     CALL       fprintf                                          undefined fprintf()
    //         0044221f     ADD        ESP,0x14
    //                               LAB_00442222                                                 XREF[1]:     00442200(j)  
    //                              dpl_obj.cpp:564 (19)
    //         00442222     MOV        EAX,dword ptr [ESI + 0x8]
    //         00442225     MOV        this,dword ptr [ESI + 0x4]
    //         00442228     CMP        EAX,this
    //         0044222a     JL         LAB_00442235
    //         0044222c     PUSH       0x1e
    //         0044222e     MOV        this,ESI
    //         00442230     CALL       RGE_Doppleganger_Creator::expand_allocations     void expand_allocations(RGE_Doppleganger_Crea
    //                               LAB_00442235                                                 XREF[1]:     0044222a(j)  
    //                              dpl_obj.cpp:566 (17)
    //         00442235     MOV        this,dword ptr [EDI + 0xc]
    //         00442238     MOV        EDX,dword ptr [ESI]
    //         0044223a     MOV        AX,word ptr [this->owner + 0x4a]
    //         0044223e     CMP        AX,word ptr [EDX + 0x4a]
    //         00442242     JZ         LAB_0044224b
    //         00442244     XOR        EAX,EAX
    //                              dpl_obj.cpp:584 (5)
    //         00442246     POP        EDI
    //         00442247     POP        ESI
    //         00442248     RET        0x8
    //                               LAB_0044224b                                                 XREF[1]:     00442242(j)  
    //                              dpl_obj.cpp:570 (7)
    //         0044224b     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044224e     TEST       EDX,EDX
    //         00442250     JLE        LAB_00442267
    //                              dpl_obj.cpp:572 (6)
    //         00442252     XOR        EAX,EAX
    //         00442254     TEST       EDX,EDX
    //         00442256     JLE        LAB_00442267
    //                              dpl_obj.cpp:584 (3)
    //         00442258     MOV        this,dword ptr [ESI + 0xc]
    //                               LAB_0044225b                                                 XREF[1]:     00442265(j)  
    //                              dpl_obj.cpp:573 (12)
    //         0044225b     CMP        dword ptr [this->owner],EDI
    //         0044225d     JZ         LAB_004422a2
    //         0044225f     INC        EAX
    //         00442260     ADD        this,0x4
    //         00442263     CMP        EAX,EDX
    //         00442265     JL         LAB_0044225b
    //                               LAB_00442267                                                 XREF[2]:     00442250(j), 00442256(j)  
    //                              dpl_obj.cpp:576 (3)
    //         00442267     MOV        this,dword ptr [ESI + 0xc]
    //                              dpl_obj.cpp:577 (16)
    //         0044226a     MOV        EAX,dword ptr [ESP + param_2]
    //         0044226e     MOV        dword ptr [this->owner + EDX*0x4],EDI
    //         00442271     MOV        EDX,dword ptr [ESI + 0x8]
    //         00442274     MOV        this,dword ptr [ESI + 0x10]
    //         00442277     MOV        dword ptr [this->owner + EDX*0x4],EAX
    //                              dpl_obj.cpp:578 (11)
    //         0044227a     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044227d     MOV        this,dword ptr [ESI + 0x14]
    //         00442280     MOV        EAX,dword ptr [EAX]
    //         00442282     MOV        dword ptr [this->owner + EDX*0x4],EAX
    //                              dpl_obj.cpp:579 (12)
    //         00442285     MOV        this,dword ptr [ESI + 0x8]
    //         00442288     MOV        EDX,dword ptr [ESI + 0x18]
    //         0044228b     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044228e     MOV        dword ptr [EDX + this->owner*0x4],EAX
    //                              dpl_obj.cpp:581 (7)
    //         00442291     MOV        EAX,dword ptr [ESI + 0x8]
    //         00442294     INC        EAX
    //         00442295     MOV        dword ptr [ESI + 0x8],EAX
    //                              dpl_obj.cpp:583 (5)
    //         00442298     MOV        EAX,0x1
    //                              dpl_obj.cpp:584 (12)
    //         0044229d     POP        EDI
    //         0044229e     POP        ESI
    //         0044229f     RET        0x8
    //                               LAB_004422a2                                                 XREF[1]:     0044225d(j)  
    //         004422a2     POP        EDI
    //         004422a3     POP        ESI
    //         004422a4     XOR        EAX,EAX
    //         004422a6     RET        0x8
    //         004422a9     ??         90h
    //         004422aa     NOP
    //         004422ab     NOP
    //         004422ac     NOP
    //         004422ad     NOP
    //         004422ae     NOP
    //         004422af     NOP
}

int RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall remove_doppleganger_check(RGE_Doppleganger_Creator * 
    //              int               EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004422b1(R)  
    //                               ?remove_doppleganger_check@RGE_Doppleganger_Creator@@QAEHPA  XREF[5]:     perform_doppleganger_checks:004424
    //                               RGE_Doppleganger_Creator::remove_doppleganger_check                       remove_visible_resource:004c5205(c
    //                                                                                                         ~TRIBE_Building_Object:004c82d3(c)
    //                                                                                                         destroy_obj:004c86a9(c), 
    //                                                                                                         set_object_state:004c89b4(c)  
    //                              dpl_obj.cpp:589 (1)
    //         004422b0     PUSH       EBX
    //                              dpl_obj.cpp:593 (18)
    //         004422b1     MOV        EBX,dword ptr [ESP + param_1]
    //         004422b5     PUSH       ESI
    //         004422b6     MOV        ESI,this
    //         004422b8     PUSH       EDI
    //         004422b9     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         004422bf     TEST       this,this
    //         004422c1     JZ         LAB_004422e3
    //                              dpl_obj.cpp:594 (32)
    //         004422c3     MOV        EAX,dword ptr [ESI]
    //         004422c5     MOV        EDX,dword ptr [EBX + 0x4]
    //         004422c8     PUSH       EDX
    //         004422c9     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         004422cd     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004422d0     PUSH       EDX
    //         004422d1     MOV        EDX,dword ptr [EAX + 0x4]
    //         004422d4     PUSH       EDX
    //         004422d5     PUSH       s_RDC_(@%d)__p=%d__id=%d_                        = "RDC (@%d)  p=%d  id=%d\n"
    //         004422da     PUSH       this
    //         004422db     CALL       fprintf                                          undefined fprintf()
    //         004422e0     ADD        ESP,0x14
    //                               LAB_004422e3                                                 XREF[1]:     004422c1(j)  
    //                              dpl_obj.cpp:597 (11)
    //         004422e3     MOV        EDX,dword ptr [ESI + 0x8]
    //         004422e6     TEST       EDX,EDX
    //         004422e8     JLE        LAB_00442387
    //                              dpl_obj.cpp:599 (10)
    //         004422ee     XOR        EAX,EAX
    //         004422f0     TEST       EDX,EDX
    //         004422f2     JLE        LAB_00442387
    //                              dpl_obj.cpp:601 (3)
    //         004422f8     MOV        EDI,dword ptr [ESI + 0xc]
    //                              dpl_obj.cpp:623 (14)
    //         004422fb     MOV        this,EDI
    //                               LAB_004422fd                                                 XREF[1]:     00442307(j)  
    //         004422fd     CMP        dword ptr [this->owner],EBX
    //         004422ff     JZ         LAB_00442311
    //         00442301     INC        EAX
    //         00442302     ADD        this,0x4
    //         00442305     CMP        EAX,EDX
    //         00442307     JL         LAB_004422fd
    //                              dpl_obj.cpp:622 (2)
    //         00442309     XOR        EAX,EAX
    //                              dpl_obj.cpp:623 (6)
    //         0044230b     POP        EDI
    //         0044230c     POP        ESI
    //         0044230d     POP        EBX
    //         0044230e     RET        0x4
    //                               LAB_00442311                                                 XREF[1]:     004422ff(j)  
    //                              dpl_obj.cpp:603 (3)
    //         00442311     LEA        this,[EDX + -0x1]
    //                              dpl_obj.cpp:605 (7)
    //         00442314     CMP        EAX,this
    //         00442316     MOV        dword ptr [ESI + 0x8],this
    //         00442319     JGE        LAB_00442348
    //                              dpl_obj.cpp:607 (9)
    //         0044231b     MOV        this,dword ptr [EDI + this->owner*0x4]
    //         0044231e     SHL        EAX,0x2
    //         00442321     MOV        dword ptr [EDI + EAX*0x1],this
    //                              dpl_obj.cpp:608 (12)
    //         00442324     MOV        this,dword ptr [ESI + 0x10]
    //         00442327     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044232a     MOV        EDX,dword ptr [this->owner + EDX*0x4]
    //         0044232d     MOV        dword ptr [this->owner + EAX*0x1],EDX
    //                              dpl_obj.cpp:609 (12)
    //         00442330     MOV        this,dword ptr [ESI + 0x14]
    //         00442333     MOV        EDX,dword ptr [ESI + 0x8]
    //         00442336     MOV        EDX,dword ptr [this->owner + EDX*0x4]
    //         00442339     MOV        dword ptr [this->owner + EAX*0x1],EDX
    //                              dpl_obj.cpp:610 (12)
    //         0044233c     MOV        this,dword ptr [ESI + 0x18]
    //         0044233f     MOV        EDX,dword ptr [ESI + 0x8]
    //         00442342     MOV        EDX,dword ptr [this->owner + EDX*0x4]
    //         00442345     MOV        dword ptr [this->owner + EAX*0x1],EDX
    //                               LAB_00442348                                                 XREF[1]:     00442319(j)  
    //                              dpl_obj.cpp:613 (13)
    //         00442348     MOV        EAX,dword ptr [ESI + 0x8]
    //         0044234b     MOV        this,dword ptr [ESI + 0xc]
    //         0044234e     MOV        dword ptr [this->owner + EAX*0x4],0x0
    //                              dpl_obj.cpp:614 (13)
    //         00442355     MOV        EDX,dword ptr [ESI + 0x8]
    //         00442358     MOV        EAX,dword ptr [ESI + 0x10]
    //         0044235b     MOV        dword ptr [EAX + EDX*0x4],0x0
    //                              dpl_obj.cpp:615 (13)
    //         00442362     MOV        this,dword ptr [ESI + 0x8]
    //         00442365     MOV        EDX,dword ptr [ESI + 0x14]
    //         00442368     MOV        dword ptr [EDX + this->owner*0x4],0x0
    //                              dpl_obj.cpp:616 (13)
    //         0044236f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00442372     MOV        this,dword ptr [ESI + 0x18]
    //         00442375     MOV        dword ptr [this->owner + EAX*0x4],0x0
    //                              dpl_obj.cpp:618 (5)
    //         0044237c     MOV        EAX,0x1
    //                              dpl_obj.cpp:623 (14)
    //         00442381     POP        EDI
    //         00442382     POP        ESI
    //         00442383     POP        EBX
    //         00442384     RET        0x4
    //                               LAB_00442387                                                 XREF[2]:     004422e8(j), 004422f2(j)  
    //         00442387     POP        EDI
    //         00442388     POP        ESI
    //         00442389     XOR        EAX,EAX
    //         0044238b     POP        EBX
    //         0044238c     RET        0x4
    //         0044238f     ??         90h
    return 0;
}

void RGE_Doppleganger_Creator::perform_doppleganger_checks() {
    /* TODO: Stub */
    //                              void __thiscall perform_doppleganger_checks(RGE_Doppleganger_Creator
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0044242c(W), 00442463(R), 00442499(W), 004424be(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     00442436(W), 00442468(R), 004424ac(W), 004424c4(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0044239e(W), 004424ee(R), 0044250c(W)  
    //              RGE_Static_Obj    Stack[-0x10]:4 remove_me                 XREF[3]:     004423ae(W), 00442487(R), 004424e4(W)  
    //              int               Stack[-0x14]:4 x                         XREF[2]:     004423c8(W), 004424d4(R)  
    //              ulong             Stack[-0x18]:4 Unified_Map_Value
    //                               ?perform_doppleganger_checks@RGE_Doppleganger_Creator@@QAEXXZ XREF[2]:     update_dopplegangers:0047019d(c), 
    //                               RGE_Doppleganger_Creator::perform_doppleganger_checks                     update:0054310e(c)  
    //                              dpl_obj.cpp:628 (8)
    //         00442390     SUB        ESP,0x14
    //         00442393     PUSH       EBX
    //         00442394     PUSH       EBP
    //         00442395     PUSH       ESI
    //         00442396     MOV        ESI,this
    //                              dpl_obj.cpp:632 (3)
    //         00442398     XOR        this,this
    //         0044239a     PUSH       EDI
    //                              dpl_obj.cpp:634 (15)
    //         0044239b     MOV        EAX,dword ptr [ESI + 0x8]
    //         0044239e     MOV        dword ptr [ESP + local_c],this
    //         004423a2     TEST       EAX,EAX
    //         004423a4     JLE        LAB_004424fe
    //                              dpl_obj.cpp:636 (14)
    //         004423aa     XOR        EDI,EDI
    //         004423ac     TEST       EAX,EAX
    //         004423ae     MOV        dword ptr [ESP + remove_me],EDI
    //         004423b2     JLE        LAB_004424f2
    //                               LAB_004423b8                                                 XREF[1]:     004424e8(j)  
    //                              dpl_obj.cpp:638 (3)
    //         004423b8     MOV        EAX,dword ptr [ESI + 0x10]
    //                              dpl_obj.cpp:640 (23)
    //         004423bb     MOV        EDX,dword ptr [ESI + 0x14]
    //         004423be     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004423c1     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         004423c4     MOV        EBP,dword ptr [this->owner]
    //         004423c6     CMP        EBP,EAX
    //         004423c8     MOV        dword ptr [ESP + x],EBP
    //         004423cc     JZ         LAB_004424de
    //                              dpl_obj.cpp:642 (44)
    //         004423d2     MOV        EAX,dword ptr [ESI + 0xc]
    //         004423d5     MOV        EBX,dword ptr [EAX + EDI*0x4]
    //         004423d8     TEST       EBX,EBX
    //         004423da     JZ         LAB_00442506
    //         004423e0     MOV        EDX,dword ptr [ESI + 0x18]
    //         004423e3     MOV        this,EAX
    //         004423e5     MOV        EBX,dword ptr [this->owner + EDI*0x4]
    //         004423e8     MOV        this,dword ptr [ESI]
    //         004423ea     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         004423ed     MOV        this,dword ptr [this->owner + 0x3c]
    //         004423f0     PUSH       EAX
    //         004423f1     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004423f6     CMP        EAX,EBX
    //         004423f8     JNZ        LAB_00442506
    //                              dpl_obj.cpp:653 (3)
    //         004423fe     MOV        EDX,dword ptr [ESI + 0x14]
    //                              dpl_obj.cpp:655 (22)
    //         00442401     MOV        EBX,0x1
    //         00442406     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         00442409     XOR        EBP,EAX
    //         0044240b     SHR        EBP,0x1
    //         0044240d     SHR        EAX,0x1
    //         0044240f     AND        EBP,EAX
    //         00442411     AND        EBP,0x7fff
    //                              dpl_obj.cpp:656 (6)
    //         00442417     JZ         LAB_004424d4
    //                               LAB_0044241d                                                 XREF[1]:     004424ce(j)  
    //                              dpl_obj.cpp:658 (35)
    //         0044241d     MOV        EAX,EBP
    //         0044241f     AND        EAX,0x1
    //         00442422     CMP        AL,0x1
    //         00442424     JNZ        LAB_004424cb
    //         0044242a     MOV        EAX,dword ptr [ESI]
    //         0044242c     MOV        dword ptr [ESP + local_4],EAX
    //         00442430     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         00442434     CMP        EBX,EAX
    //         00442436     MOV        dword ptr [ESP + local_8],EAX
    //         0044243a     JZ         LAB_004424cb
    //                              dpl_obj.cpp:661 (78)
    //         00442440     MOV        EAX,[DDlogf]                                     = 00000000
    //         00442445     TEST       EAX,EAX
    //         00442447     JZ         LAB_0044248e
    //         00442449     MOV        this,dword ptr [ESI + 0xc]
    //         0044244c     MOV        EDI,dword ptr [this->owner + EDI*0x4]
    //         0044244f     FLD        float ptr [EDI + 0x3c]
    //         00442452     CALL       __ftol                                           undefined __ftol()
    //         00442457     FLD        float ptr [EDI + 0x38]
    //         0044245a     PUSH       EAX
    //         0044245b     CALL       __ftol                                           undefined __ftol()
    //         00442460     MOV        EDX,dword ptr [EDI + 0x4]
    //         00442463     MOV        this,dword ptr [ESP + local_4]
    //         00442467     PUSH       EAX
    //         00442468     MOV        EAX,dword ptr [ESP + local_8]
    //         0044246c     PUSH       EDX
    //         0044246d     MOV        EDX,dword ptr [this->owner + 0x3c]
    //         00442470     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         00442476     PUSH       EBX
    //         00442477     PUSH       EAX
    //         00442478     MOV        EAX,dword ptr [EDX + 0x4]
    //         0044247b     PUSH       EAX
    //         0044247c     PUSH       s_NEW_DOP_(@%d)_by_p=%d_for_p=%d_o               = "NEW DOP (@%d) by p=%d for p=%d of id=%d (x
    //         00442481     PUSH       this
    //         00442482     CALL       fprintf                                          undefined fprintf()
    //         00442487     MOV        EDI,dword ptr [ESP + remove_me]
    //         0044248b     ADD        ESP,0x20
    //                               LAB_0044248e                                                 XREF[1]:     00442447(j)  
    //                              dpl_obj.cpp:665 (61)
    //         0044248e     MOV        EDX,dword ptr [ESI]
    //         00442490     MOV        EAX,dword ptr [EDX + 0x3c]
    //         00442493     MOV        this,dword ptr [EAX + 0x40]
    //         00442496     MOV        EAX,dword ptr [this->owner + EBX*0x4]
    //         00442499     MOV        dword ptr [ESP + local_4],EAX
    //         0044249d     MOV        EDX,dword ptr [EAX + 0x24]
    //         004424a0     MOV        EAX,dword ptr [ESI + 0xc]
    //         004424a3     MOV        this,dword ptr [EDX + 0x3cc]
    //         004424a9     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         004424ac     MOV        dword ptr [ESP + local_8],this
    //         004424b0     PUSH       EAX
    //         004424b1     MOV        EDX,dword ptr [this->owner]
    //         004424b3     MOV        this,dword ptr [EAX + 0x40]
    //         004424b6     PUSH       this
    //         004424b7     MOV        this,dword ptr [EAX + 0x3c]
    //         004424ba     MOV        EAX,dword ptr [EAX + 0x38]
    //         004424bd     PUSH       this
    //         004424be     MOV        this,dword ptr [ESP + local_4]
    //         004424c2     PUSH       EAX
    //         004424c3     PUSH       this
    //         004424c4     MOV        this,dword ptr [ESP + local_8]
    //         004424c8     CALL       dword ptr [EDX + 0x38]
    //                               LAB_004424cb                                                 XREF[2]:     00442424(j), 0044243a(j)  
    //                              dpl_obj.cpp:667 (1)
    //         004424cb     INC        EBX
    //                              dpl_obj.cpp:668 (8)
    //         004424cc     SHR        EBP,0x1
    //         004424ce     JNZ        LAB_0044241d
    //                               LAB_004424d4                                                 XREF[1]:     00442417(j)  
    //                              dpl_obj.cpp:646 (4)
    //         004424d4     MOV        EBP,dword ptr [ESP + x]
    //                               LAB_004424d8                                                 XREF[2]:     00442512(j), 00442537(j)  
    //                              dpl_obj.cpp:671 (22)
    //         004424d8     MOV        EAX,dword ptr [ESI + 0x14]
    //         004424db     MOV        dword ptr [EAX + EDI*0x4],EBP
    //                               LAB_004424de                                                 XREF[1]:     004423cc(j)  
    //         004424de     MOV        EAX,dword ptr [ESI + 0x8]
    //         004424e1     INC        EDI
    //         004424e2     CMP        EDI,EAX
    //         004424e4     MOV        dword ptr [ESP + remove_me],EDI
    //         004424e8     JL         LAB_004423b8
    //                              dpl_obj.cpp:636 (4)
    //         004424ee     MOV        this,dword ptr [ESP + local_c]
    //                               LAB_004424f2                                                 XREF[1]:     004423b2(j)  
    //                              dpl_obj.cpp:675 (12)
    //         004424f2     TEST       this,this
    //         004424f4     JZ         LAB_004424fe
    //         004424f6     PUSH       this
    //         004424f7     MOV        this,ESI
    //         004424f9     CALL       RGE_Doppleganger_Creator::remove_doppleganger_   int remove_doppleganger_check(RGE_Dopplegange
    //                               LAB_004424fe                                                 XREF[2]:     004423a4(j), 004424f4(j)  
    //                              dpl_obj.cpp:677 (8)
    //         004424fe     POP        EDI
    //         004424ff     POP        ESI
    //         00442500     POP        EBP
    //         00442501     POP        EBX
    //         00442502     ADD        ESP,0x14
    //         00442505     RET
    //                               LAB_00442506                                                 XREF[2]:     004423da(j), 004423f8(j)  
    //                              dpl_obj.cpp:646 (51)
    //         00442506     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         0044250c     MOV        dword ptr [ESP + local_c],EBX
    //         00442510     TEST       this,this
    //         00442512     JZ         LAB_004424d8
    //         00442514     MOV        EDX,dword ptr [ESI + 0x18]
    //         00442517     MOV        EAX,dword ptr [ESI]
    //         00442519     MOV        EDX,dword ptr [EDX + EDI*0x4]
    //         0044251c     PUSH       EDX
    //         0044251d     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         00442521     MOV        EAX,dword ptr [EAX + 0x3c]
    //         00442524     PUSH       EDX=>DAT_fffffff8
    //         00442525     MOV        EDX,dword ptr [EAX + 0x4]
    //         00442528     PUSH       EDX=>DAT_fffffff4
    //         00442529     PUSH       s_***_REMOVE_CHECK_(@%d)_by_p=%d_i               = "*** REMOVE CHECK (@%d) by p=%d id=%d\n"
    //         0044252e     PUSH       this
    //         0044252f     CALL       fprintf                                          undefined fprintf()
    //         00442534     ADD        ESP,0x14
    //         00442537     JMP        LAB_004424d8
    //         00442539     ??         90h
    //         0044253a     NOP
    //         0044253b     NOP
    //         0044253c     NOP
    //         0044253d     NOP
    //         0044253e     NOP
    //         0044253f     NOP
    return;
}

void RGE_Doppleganger_Creator::expand_allocations(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall expand_allocations(RGE_Doppleganger_Creator * this, 
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0044254e(R), 0044259c(W), 004425e0(R), 00442656(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004425ce(W), 0044265e(R)  
    //              int *             Stack[-0x8]:4  TObject_ids               XREF[3]:     004425ae(W), 004425fb(R), 0044265a(R)  
    //              ulong *           Stack[-0xc]:4  TLast_Map_Value
    //                               ?expand_allocations@RGE_Doppleganger_Creator@@IAEXH@Z        XREF[1]:     add_doppleganger_check:00442230(c)
    //                               RGE_Doppleganger_Creator::expand_allocations
    //                              dpl_obj.cpp:681 (6)
    //         00442540     SUB        ESP,0x8
    //         00442543     PUSH       EBX
    //         00442544     MOV        EBX,this
    //                              dpl_obj.cpp:683 (17)
    //         00442546     MOV        this,dword ptr [DDlogf]                          = 00000000
    //         0044254c     PUSH       EBP
    //         0044254d     PUSH       ESI
    //         0044254e     MOV        ESI,dword ptr [ESP + param_1]
    //         00442552     TEST       this,this
    //         00442554     PUSH       EDI
    //         00442555     JZ         LAB_00442574
    //                              dpl_obj.cpp:684 (29)
    //         00442557     MOV        EAX,dword ptr [EBX]
    //         00442559     PUSH       ESI
    //         0044255a     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0044255e     MOV        EAX,dword ptr [EAX + 0x3c]
    //         00442561     PUSH       EDX
    //         00442562     MOV        EDX,dword ptr [EAX + 0x4]
    //         00442565     PUSH       EDX
    //         00442566     PUSH       s_RESIZE_(@%d)_p=%d__grow=%d_                    = "RESIZE (@%d) p=%d  grow=%d\n"
    //         0044256b     PUSH       this
    //         0044256c     CALL       fprintf                                          undefined fprintf()
    //         00442571     ADD        ESP,0x14
    //                               LAB_00442574                                                 XREF[1]:     00442555(j)  
    //                              dpl_obj.cpp:688 (3)
    //         00442574     MOV        EDX,dword ptr [EBX + 0x4]
    //                              dpl_obj.cpp:690 (20)
    //         00442577     PUSH       0x4
    //         00442579     ADD        EDX,ESI
    //         0044257b     MOV        EAX,EDX
    //         0044257d     MOV        dword ptr [EBX + 0x4],EDX
    //         00442580     PUSH       EAX
    //         00442581     CALL       calloc                                           undefined calloc()
    //         00442586     ADD        ESP,0x8
    //         00442589     MOV        EBP,EAX
    //                              dpl_obj.cpp:691 (11)
    //         0044258b     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044258e     PUSH       0x4
    //         00442590     PUSH       EAX
    //         00442591     CALL       calloc                                           undefined calloc()
    //                              dpl_obj.cpp:692 (18)
    //         00442596     MOV        this,dword ptr [EBX + 0x4]
    //         00442599     ADD        ESP,0x8
    //         0044259c     MOV        dword ptr [ESP + param_1],EAX
    //         004425a0     PUSH       0x4
    //         004425a2     PUSH       this
    //         004425a3     CALL       calloc                                           undefined calloc()
    //                              dpl_obj.cpp:693 (18)
    //         004425a8     MOV        EDX,dword ptr [EBX + 0x4]
    //         004425ab     ADD        ESP,0x8
    //         004425ae     MOV        dword ptr [ESP + TObject_ids],EAX
    //         004425b2     PUSH       0x4
    //         004425b4     PUSH       EDX
    //         004425b5     CALL       calloc                                           undefined calloc()
    //                              dpl_obj.cpp:695 (32)
    //         004425ba     MOV        this,dword ptr [EBX + 0x8]
    //         004425bd     MOV        ESI,dword ptr [EBX + 0xc]
    //         004425c0     SHL        this,0x2
    //         004425c3     MOV        EDX,this
    //         004425c5     MOV        EDI,EBP
    //         004425c7     SHR        this,0x2
    //         004425ca     MOVSD.REP  ES:EDI,ESI
    //         004425cc     MOV        this,EDX
    //         004425ce     MOV        dword ptr [ESP + local_4],EAX
    //         004425d2     AND        this,0x3
    //         004425d5     ADD        ESP,0x8
    //         004425d8     MOVSB.REP  ES:EDI,ESI
    //                              dpl_obj.cpp:696 (27)
    //         004425da     MOV        this,dword ptr [EBX + 0x8]
    //         004425dd     MOV        ESI,dword ptr [EBX + 0x10]
    //         004425e0     MOV        EDI,dword ptr [ESP + param_1]
    //         004425e4     SHL        this,0x2
    //         004425e7     MOV        EDX,this
    //         004425e9     SHR        this,0x2
    //         004425ec     MOVSD.REP  ES:EDI,ESI
    //         004425ee     MOV        this,EDX
    //         004425f0     AND        this,0x3
    //         004425f3     MOVSB.REP  ES:EDI,ESI
    //                              dpl_obj.cpp:697 (27)
    //         004425f5     MOV        this,dword ptr [EBX + 0x8]
    //         004425f8     MOV        ESI,dword ptr [EBX + 0x14]
    //         004425fb     MOV        EDI,dword ptr [ESP + TObject_ids]
    //         004425ff     SHL        this,0x2
    //         00442602     MOV        EDX,this
    //         00442604     SHR        this,0x2
    //         00442607     MOVSD.REP  ES:EDI,ESI
    //         00442609     MOV        this,EDX
    //         0044260b     AND        this,0x3
    //         0044260e     MOVSB.REP  ES:EDI,ESI
    //                              dpl_obj.cpp:698 (25)
    //         00442610     MOV        this,dword ptr [EBX + 0x8]
    //         00442613     MOV        ESI,dword ptr [EBX + 0x18]
    //         00442616     SHL        this,0x2
    //         00442619     MOV        EDI,EAX
    //         0044261b     MOV        EAX,this
    //         0044261d     SHR        this,0x2
    //         00442620     MOVSD.REP  ES:EDI,ESI
    //         00442622     MOV        this,EAX
    //         00442624     AND        this,0x3
    //         00442627     MOVSB.REP  ES:EDI,ESI
    //                              dpl_obj.cpp:700 (9)
    //         00442629     MOV        this,dword ptr [EBX + 0xc]
    //         0044262c     PUSH       this
    //         0044262d     CALL       free                                             undefined free()
    //                              dpl_obj.cpp:701 (12)
    //         00442632     MOV        EDX,dword ptr [EBX + 0x10]
    //         00442635     ADD        ESP,0x4
    //         00442638     PUSH       EDX
    //         00442639     CALL       free                                             undefined free()
    //                              dpl_obj.cpp:702 (12)
    //         0044263e     MOV        EAX,dword ptr [EBX + 0x14]
    //         00442641     ADD        ESP,0x4
    //         00442644     PUSH       EAX
    //         00442645     CALL       free                                             undefined free()
    //                              dpl_obj.cpp:703 (12)
    //         0044264a     MOV        this,dword ptr [EBX + 0x18]
    //         0044264d     ADD        ESP,0x4
    //         00442650     PUSH       this
    //         00442651     CALL       free                                             undefined free()
    //                              dpl_obj.cpp:706 (4)
    //         00442656     MOV        EDX,dword ptr [ESP + param_1]
    //                              dpl_obj.cpp:707 (4)
    //         0044265a     MOV        EAX,dword ptr [ESP + TObject_ids]
    //                              dpl_obj.cpp:708 (13)
    //         0044265e     MOV        this,dword ptr [ESP + local_4]
    //         00442662     ADD        ESP,0x4
    //         00442665     MOV        dword ptr [EBX + 0xc],EBP
    //         00442668     MOV        dword ptr [EBX + 0x10],EDX
    //                              dpl_obj.cpp:710 (16)
    //         0044266b     POP        EDI
    //         0044266c     POP        ESI
    //         0044266d     MOV        dword ptr [EBX + 0x14],EAX
    //         00442670     MOV        dword ptr [EBX + 0x18],this
    //         00442673     POP        EBP
    //         00442674     POP        EBX
    //         00442675     ADD        ESP,0x8
    //         00442678     RET        0x4
    //         0044267b     ??         90h
    //         0044267c     NOP
    //         0044267d     NOP
    //         0044267e     NOP
    //         0044267f     NOP
    return;
}

RGE_Doppleganger_Object::~RGE_Doppleganger_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Doppleganger_Object(RGE_Doppleganger_Object * t
    //              void              <VOID>         <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //                               ??1RGE_Doppleganger_Object@@UAE@XZ                           XREF[1]:     `scalar_deleting_destructor':00441
    //                               RGE_Doppleganger_Object::~RGE_Doppleganger_Object
    //         00441a60     JMP        RGE_Static_Object::~RGE_Static_Object
    //         00441a65     ??         90h
    //         00441a66     NOP
    //         00441a67     NOP
    //         00441a68     NOP
    //         00441a69     NOP
    //         00441a6a     NOP
    //         00441a6b     NOP
    //         00441a6c     NOP
    //         00441a6d     NOP
    //         00441a6e     NOP
    //         00441a6f     NOP
}

void RGE_Doppleganger_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, RGE_Static_Object* param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

int RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Static_Object* param_1, ulong* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

