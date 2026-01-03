#include "../common.h"
#include "tplayer.h"

TRIBE_Player::TRIBE_Player(int param_1, TRIBE_World* param_2, uchar param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Player(TRIBE_Player * this, int param_1,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00511bf2(R)
//              TRIBE_World *     Stack[0x8]:4   param_2                   XREF[2]:     00511bec(R), 00511dbb(W)
//              uchar             Stack[0xc]:1   param_3                   XREF[7]:     00511be6(R), 00511c77(W), 00511cd2(W), 00511cf9(W),
//                                                                                     00511d7e(W), 00511d89(*), 00511da8(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     00511c0d(W), 00511c7d(W), 00511c9f(W), 00511cd8(W),
//                                                                                     00511cff(W), 00511d19(W), 00511dc1(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00511de7(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00511bfb(W)
//                               ??0TRIBE_Player@@QAE@HPAVTRIBE_World@@E@Z                    XREF[2]:     TRIBE_Gaia:00519b1f(c),
//                               TRIBE_Player::TRIBE_Player                                                load_player:0052e8df(c)
//                              tplayer.cpp:232 (52)
//         00511bd0     PUSH       -0x1
//         00511bd2     PUSH       FUN_00561154
//         00511bd7     MOV        EAX,FS:[0x0]
//         00511bdd     PUSH       EAX
//         00511bde     MOV        dword ptr FS:[0x0],ESP
//         00511be5     PUSH       this
//         00511be6     MOV        EAX,dword ptr [ESP + param_3]
//         00511bea     PUSH       EBX
//         00511beb     PUSH       EBP
//         00511bec     MOV        EBP,dword ptr [ESP + param_2]
//         00511bf0     PUSH       ESI
//         00511bf1     PUSH       EDI
//         00511bf2     MOV        EDI,dword ptr [ESP + param_1]
//         00511bf6     PUSH       EAX
//         00511bf7     MOV        ESI,this
//         00511bf9     PUSH       EBP
//         00511bfa     PUSH       EDI
//         00511bfb     MOV        dword ptr [ESP + local_10],ESI
//         00511bff     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, int p
//                              tplayer.cpp:233 (33)
//         00511c04     LEA        EAX,[ESI + 0x48]
//         00511c07     PUSH       0x1
//         00511c09     XOR        EBX,EBX
//         00511c0b     PUSH       EAX
//         00511c0c     PUSH       EDI
//         00511c0d     MOV        dword ptr [ESP + local_4],EBX
//         00511c11     MOV        dword ptr [ESI + 0x238],EBX
//         00511c17     MOV        dword ptr [ESI],TRIBE_Player::`vftable'          = 00511e00
//         00511c1d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511c22     ADD        ESP,0xc
//                              tplayer.cpp:234 (18)
//         00511c25     LEA        this,[ESI + 0x228]
//         00511c2b     PUSH       0x4
//         00511c2d     PUSH       this
//         00511c2e     PUSH       EDI
//         00511c2f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511c34     ADD        ESP,0xc
//                              tplayer.cpp:235 (18)
//         00511c37     LEA        EDX,[ESI + 0x230]
//         00511c3d     PUSH       0x4
//         00511c3f     PUSH       EDX
//         00511c40     PUSH       EDI
//         00511c41     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511c46     ADD        ESP,0xc
//                              tplayer.cpp:236 (18)
//         00511c49     LEA        EAX,[ESI + 0x224]
//         00511c4f     PUSH       0x4
//         00511c51     PUSH       EAX
//         00511c52     PUSH       EDI
//         00511c53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511c58     ADD        ESP,0xc
//                              tplayer.cpp:237 (18)
//         00511c5b     LEA        this,[ESI + 0x234]
//         00511c61     PUSH       0x4
//         00511c63     PUSH       this
//         00511c64     PUSH       EDI
//         00511c65     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511c6a     ADD        ESP,0xc
//                              tplayer.cpp:238 (54)
//         00511c6d     PUSH       0x10
//         00511c6f     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511c74     ADD        ESP,0x4
//         00511c77     MOV        dword ptr [ESP + param_3],EAX
//         00511c7b     CMP        EAX,EBX
//         00511c7d     MOV        byte ptr [ESP + local_4],0x1
//         00511c82     JZ         LAB_00511c97
//         00511c84     MOV        EDX,dword ptr [EBP + 0x104]
//         00511c8a     PUSH       EBX
//         00511c8b     PUSH       ESI
//         00511c8c     PUSH       EDX
//         00511c8d     PUSH       EDI
//         00511c8e     MOV        this,EAX
//         00511c90     CALL       TRIBE_Player_Tech::TRIBE_Player_Tech             undefined TRIBE_Player_Tech(TRIBE_Player_Tech
//         00511c95     JMP        LAB_00511c99
//                               LAB_00511c97                                                 XREF[1]:     00511c82(j)
//         00511c97     XOR        EAX,EAX
//                               LAB_00511c99                                                 XREF[1]:     00511c95(j)
//         00511c99     MOV        dword ptr [ESI + 0x220],EAX
//         00511c9f     MOV        byte ptr [ESP + local_4],BL
//                              tplayer.cpp:240 (19)
//         00511ca3     FLD        float ptr [save_game_version]                    = 7.23
//         00511ca9     FCOMP      float ptr [DAT_00576818]                         = align(2)
//         00511caf     FNSTSW     AX
//         00511cb1     TEST       AH,0x41
//         00511cb4     JNZ        LAB_00511ce9
//                              tplayer.cpp:242 (18)
//         00511cb6     LEA        EAX,[ESI + 0x22c]
//         00511cbc     PUSH       0x4
//         00511cbe     PUSH       EAX
//         00511cbf     PUSH       EDI
//         00511cc0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511cc5     ADD        ESP,0xc
//                              tplayer.cpp:243 (24)
//         00511cc8     PUSH       0x14
//         00511cca     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511ccf     ADD        ESP,0x4
//         00511cd2     MOV        dword ptr [ESP + param_3],EAX
//         00511cd6     CMP        EAX,EBX
//         00511cd8     MOV        byte ptr [ESP + local_4],0x2
//         00511cdd     JZ         LAB_00511d11
//         00511cdf     PUSH       EDI
//                              tplayer.cpp:248 (61)
//         00511ce0     MOV        this,EAX
//         00511ce2     CALL       TRIBE_History_Info::TRIBE_History_Info           undefined TRIBE_History_Info(TRIBE_History_In
//         00511ce7     JMP        LAB_00511d13
//                               LAB_00511ce9                                                 XREF[1]:     00511cb4(j)
//         00511ce9     PUSH       0x14
//         00511ceb     MOV        dword ptr [ESI + 0x22c],EBX
//         00511cf1     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511cf6     ADD        ESP,0x4
//         00511cf9     MOV        dword ptr [ESP + param_3],EAX
//         00511cfd     CMP        EAX,EBX
//         00511cff     MOV        byte ptr [ESP + local_4],0x3
//         00511d04     JZ         LAB_00511d11
//         00511d06     PUSH       -0x1
//         00511d08     MOV        this,EAX
//         00511d0a     CALL       TRIBE_History_Info::TRIBE_History_Info           undefined TRIBE_History_Info(TRIBE_History_In
//         00511d0f     JMP        LAB_00511d13
//                               LAB_00511d11                                                 XREF[2]:     00511cdd(j), 00511d04(j)
//         00511d11     XOR        EAX,EAX
//                               LAB_00511d13                                                 XREF[2]:     00511ce7(j), 00511d0f(j)
//         00511d13     MOV        dword ptr [ESI + 0x83c],EAX
//         00511d19     MOV        byte ptr [ESP + local_4],BL
//                              tplayer.cpp:251 (19)
//         00511d1d     FLD        float ptr [save_game_version]                    = 7.23
//         00511d23     FCOMP      float ptr [DAT_0057681c]                         = 9Ah
//         00511d29     FNSTSW     AX
//         00511d2b     TEST       AH,0x1
//         00511d2e     JNZ        LAB_00511d56
//                              tplayer.cpp:253 (18)
//         00511d30     LEA        this,[ESI + 0x840]
//         00511d36     PUSH       0x4
//         00511d38     PUSH       this
//         00511d39     PUSH       EDI
//         00511d3a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511d3f     ADD        ESP,0xc
//                              tplayer.cpp:254 (18)
//         00511d42     LEA        EDX,[ESI + 0x844]
//         00511d48     PUSH       0x4
//         00511d4a     PUSH       EDX
//         00511d4b     PUSH       EDI
//         00511d4c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511d51     ADD        ESP,0xc
//                              tplayer.cpp:256 (2)
//         00511d54     JMP        LAB_00511d67
//                               LAB_00511d56                                                 XREF[1]:     00511d2e(j)
//                              tplayer.cpp:258 (11)
//         00511d56     MOV        EAX,0xbf800000
//         00511d5b     MOV        dword ptr [ESI + 0x840],EAX
//                              tplayer.cpp:259 (6)
//         00511d61     MOV        dword ptr [ESI + 0x844],EAX
//                               LAB_00511d67                                                 XREF[1]:     00511d54(j)
//                              tplayer.cpp:263 (6)
//         00511d67     CMP        byte ptr [ESI + 0x48],0x3
//         00511d6b     JNZ        LAB_00511de7
//                              tplayer.cpp:268 (28)
//         00511d6d     FLD        float ptr [save_game_version]                    = 7.23
//         00511d73     FCOMP      float ptr [DAT_00576820]                         = C3h
//         00511d79     MOV        EBP,0x1
//         00511d7e     MOV        dword ptr [ESP + param_3],EBP
//         00511d82     FNSTSW     AX
//         00511d84     TEST       AH,0x1
//         00511d87     JNZ        LAB_00511d99
//                              tplayer.cpp:269 (16)
//         00511d89     LEA        EAX=>param_3,[ESP + 0x2c]
//         00511d8d     PUSH       0x4
//         00511d8f     PUSH       EAX
//         00511d90     PUSH       EDI
//         00511d91     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00511d96     ADD        ESP,0xc
//                               LAB_00511d99                                                 XREF[1]:     00511d87(j)
//                              tplayer.cpp:270 (21)
//         00511d99     MOV        this,dword ptr [comm]                            = 00000000
//         00511d9f     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         00511da4     CMP        EAX,EBP
//         00511da6     JNZ        LAB_00511de4
//         00511da8     CMP        dword ptr [ESP + param_3],EBP
//         00511dac     JNZ        LAB_00511de4
//                              tplayer.cpp:272 (54)
//         00511dae     PUSH       0x125c8
//         00511db3     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511db8     ADD        ESP,0x4
//         00511dbb     MOV        dword ptr [ESP + param_2],EAX
//         00511dbf     CMP        EAX,EBX
//         00511dc1     MOV        byte ptr [ESP + local_4],0x4
//         00511dc6     JZ         LAB_00511ddc
//         00511dc8     MOVSX      EDX,word ptr [ESI + 0x4a]
//         00511dcc     MOV        this,dword ptr [ESI + 0x44]
//         00511dcf     PUSH       EDI
//         00511dd0     PUSH       ESI
//         00511dd1     PUSH       this
//         00511dd2     PUSH       EDX
//         00511dd3     MOV        this,EAX
//         00511dd5     CALL       TribeMainDecisionAIModule::TribeMainDecisionAI   undefined TribeMainDecisionAIModule(TribeMain
//         00511dda     JMP        LAB_00511dde
//                               LAB_00511ddc                                                 XREF[1]:     00511dc6(j)
//         00511ddc     XOR        EAX,EAX
//                               LAB_00511dde                                                 XREF[1]:     00511dda(j)
//         00511dde     MOV        dword ptr [ESI + 0x238],EAX
//                               LAB_00511de4                                                 XREF[2]:     00511da6(j), 00511dac(j)
//                              tplayer.cpp:276 (3)
//         00511de4     MOV        dword ptr [ESI + 0x4],EBP
//                               LAB_00511de7                                                 XREF[1]:     00511d6b(j)
//                              tplayer.cpp:278 (23)
//         00511de7     MOV        this,dword ptr [ESP + local_c]
//         00511deb     MOV        EAX,ESI
//         00511ded     POP        EDI
//         00511dee     POP        ESI
//         00511def     POP        EBP
//         00511df0     MOV        dword ptr FS:[0x0],this
//         00511df7     POP        EBX
//         00511df8     ADD        ESP,0x10
//         00511dfb     RET        0xc
//         00511dfe     ??         90h
//         00511dff     NOP
}

TRIBE_Player::TRIBE_Player(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6, uchar param_7, char* param_8, char* param_9, char* param_10) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Player(TRIBE_Player * this, TRIBE_World *
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              TRIBE_World *     Stack[0x4]:4   param_1                   XREF[1]:     00511e40(R)
//              RGE_Master_Pla    Stack[0x8]:4   param_2                   XREF[1]:     00511e50(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00511e3a(R)
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     00511e49(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[2]:     00511e36(R), 00511e7d(W)
//              uchar             Stack[0x18]:1  param_6                   XREF[8]:     00511e9e(R), 00511ed8(W), 00511f2a(W), 00511f5b(W),
//                                                                                     00511f8c(W), 00511fc2(W), 00512064(W), 00512092(W)
//              uchar             Stack[0x1c]:1  param_7                   XREF[1]:     00511f14(R)
//              char *            Stack[0x20]:4  param_8                   XREF[1]:     00511eee(R)
//              char *            Stack[0x24]:4  param_9                   XREF[1]:     00511ee9(R)
//              char *            Stack[0x28]:4  param_10                  XREF[1]:     00511ee5(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[16]:    00511e65(W), 00511e83(W), 00511ea4(W), 00511ede(W),
//                                                                                     00511f0a(W), 00511f30(W), 00511f4a(W), 00511f61(W),
//                                                                                     00511f7b(W), 00511f92(W), 00511fac(W), 00511fc8(W),
//                                                                                     00511fdf(W), 0051206a(W), 00512080(W), 00512098(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005120b4(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00511e5a(W)
//                               ??0TRIBE_Player@@QAE@PAVTRIBE_World@@PAVRGE_Master_Player@@  XREF[5]:     TRIBE_Gaia:00519bf8(c),
//                               TRIBE_Player::TRIBE_Player                                                setup_players:0052ea3c(c),
//                                                                                                         setup_players:0052ea84(c),
//                                                                                                         scenario_make_player:0052ed82(c),
//                                                                                                         scenario_make_player:0052edca(c)
//                              tplayer.cpp:287 (67)
//         00511e20     PUSH       -0x1
//         00511e22     PUSH       FUN_005611c0
//         00511e27     MOV        EAX,FS:[0x0]
//         00511e2d     PUSH       EAX
//         00511e2e     MOV        dword ptr FS:[0x0],ESP
//         00511e35     PUSH       this
//         00511e36     MOV        EAX,dword ptr [ESP + param_5]
//         00511e3a     MOV        EDX,dword ptr [ESP + param_3]
//         00511e3e     PUSH       EBX
//         00511e3f     PUSH       EBP
//         00511e40     MOV        EBP,dword ptr [ESP + param_1]
//         00511e44     PUSH       ESI
//         00511e45     MOV        ESI,this
//         00511e47     XOR        EBX,EBX
//         00511e49     MOV        this,dword ptr [ESP + param_4]
//         00511e4d     PUSH       EDI
//         00511e4e     PUSH       EBX
//         00511e4f     PUSH       EAX
//         00511e50     MOV        EAX,dword ptr [ESP + param_2]
//         00511e54     PUSH       this
//         00511e55     PUSH       EDX
//         00511e56     PUSH       EAX
//         00511e57     PUSH       EBP
//         00511e58     MOV        this,ESI
//         00511e5a     MOV        dword ptr [ESP + local_10],ESI
//         00511e5e     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, RGE_G
//                              tplayer.cpp:289 (59)
//         00511e63     PUSH       0x14
//         00511e65     MOV        dword ptr [ESP + local_4],EBX
//         00511e69     MOV        dword ptr [ESI + 0x238],EBX
//         00511e6f     MOV        dword ptr [ESI],TRIBE_Player::`vftable'          = 00511e00
//         00511e75     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511e7a     ADD        ESP,0x4
//         00511e7d     MOV        dword ptr [ESP + param_5],EAX
//         00511e81     CMP        EAX,EBX
//         00511e83     MOV        byte ptr [ESP + local_4],0x1
//         00511e88     JZ         LAB_00511e96
//         00511e8a     PUSH       0x5
//         00511e8c     PUSH       ESI
//         00511e8d     MOV        this,EAX
//         00511e8f     CALL       Visible_Resource_Manager::Visible_Resource_Man   undefined Visible_Resource_Manager(Visible_Re
//         00511e94     JMP        LAB_00511e98
//                               LAB_00511e96                                                 XREF[1]:     00511e88(j)
//         00511e96     XOR        EAX,EAX
//                               LAB_00511e98                                                 XREF[1]:     00511e94(j)
//         00511e98     MOV        dword ptr [ESI + 0x110],EAX
//                              tplayer.cpp:291 (12)
//         00511e9e     MOV        AL,byte ptr [ESP + param_6]
//         00511ea2     CMP        AL,BL
//         00511ea4     MOV        byte ptr [ESP + local_4],BL
//         00511ea8     JNZ        LAB_00511eb0
//                              tplayer.cpp:292 (4)
//         00511eaa     MOV        byte ptr [ESI + 0x48],0x1
//                              tplayer.cpp:293 (2)
//         00511eae     JMP        LAB_00511f14
//                               LAB_00511eb0                                                 XREF[1]:     00511ea8(j)
//                              tplayer.cpp:295 (4)
//         00511eb0     MOV        byte ptr [ESI + 0x48],0x3
//                              tplayer.cpp:296 (7)
//         00511eb4     MOV        dword ptr [ESI + 0x4],0x1
//                              tplayer.cpp:297 (16)
//         00511ebb     MOV        this,dword ptr [comm]                            = 00000000
//         00511ec1     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         00511ec6     CMP        EAX,0x1
//         00511ec9     JNZ        LAB_00511f14
//                              tplayer.cpp:299 (73)
//         00511ecb     PUSH       0x125c8
//         00511ed0     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511ed5     ADD        ESP,0x4
//         00511ed8     MOV        dword ptr [ESP + param_6],EAX
//         00511edc     CMP        EAX,EBX
//         00511ede     MOV        byte ptr [ESP + local_4],0x2
//         00511ee3     JZ         LAB_00511f08
//         00511ee5     MOV        this,dword ptr [ESP + param_10]
//         00511ee9     MOV        EDX,dword ptr [ESP + param_9]
//         00511eed     PUSH       this
//         00511eee     MOV        this,dword ptr [ESP + param_8]
//         00511ef2     PUSH       EDX
//         00511ef3     MOV        EDX,dword ptr [ESI + 0x44]
//         00511ef6     PUSH       this
//         00511ef7     PUSH       ESI
//         00511ef8     MOVSX      this,word ptr [ESI + 0x4a]
//         00511efc     PUSH       EDX
//         00511efd     PUSH       this
//         00511efe     PUSH       EBX
//         00511eff     MOV        this,EAX
//         00511f01     CALL       TribeMainDecisionAIModule::TribeMainDecisionAI   undefined TribeMainDecisionAIModule(TribeMain
//         00511f06     JMP        LAB_00511f0a
//                               LAB_00511f08                                                 XREF[1]:     00511ee3(j)
//         00511f08     XOR        EAX,EAX
//                               LAB_00511f0a                                                 XREF[1]:     00511f06(j)
//         00511f0a     MOV        byte ptr [ESP + local_4],BL
//         00511f0e     MOV        dword ptr [ESI + 0x238],EAX
//                               LAB_00511f14                                                 XREF[2]:     00511eae(j), 00511ec9(j)
//                              tplayer.cpp:302 (10)
//         00511f14     CMP        byte ptr [ESP + param_7],BL
//         00511f18     JZ         LAB_00511fe6
//                              tplayer.cpp:304 (42)
//         00511f1e     PUSH       0xc
//         00511f20     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511f25     MOV        EDI,EAX
//         00511f27     ADD        ESP,0x4
//         00511f2a     MOV        dword ptr [ESP + param_6],EDI
//         00511f2e     CMP        EDI,EBX
//         00511f30     MOV        byte ptr [ESP + local_4],0x3
//         00511f35     JZ         LAB_00511f46
//         00511f37     MOV        this,EDI
//         00511f39     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         00511f3e     MOV        dword ptr [EDI],TRIBE_Object_List::`vftable'     = 00511b00
//         00511f44     JMP        LAB_00511f48
//                               LAB_00511f46                                                 XREF[1]:     00511f35(j)
//         00511f46     XOR        EDI,EDI
//                               LAB_00511f48                                                 XREF[1]:     00511f44(j)
//                              tplayer.cpp:305 (49)
//         00511f48     PUSH       0xc
//         00511f4a     MOV        byte ptr [ESP + local_4],BL
//         00511f4e     MOV        dword ptr [ESI + 0x28],EDI
//         00511f51     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511f56     MOV        EDI,EAX
//         00511f58     ADD        ESP,0x4
//         00511f5b     MOV        dword ptr [ESP + param_6],EDI
//         00511f5f     CMP        EDI,EBX
//         00511f61     MOV        byte ptr [ESP + local_4],0x4
//         00511f66     JZ         LAB_00511f77
//         00511f68     MOV        this,EDI
//         00511f6a     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         00511f6f     MOV        dword ptr [EDI],TRIBE_Object_List::`vftable'     = 00511b00
//         00511f75     JMP        LAB_00511f79
//                               LAB_00511f77                                                 XREF[1]:     00511f66(j)
//         00511f77     XOR        EDI,EDI
//                               LAB_00511f79                                                 XREF[1]:     00511f75(j)
//                              tplayer.cpp:306 (49)
//         00511f79     PUSH       0xc
//         00511f7b     MOV        byte ptr [ESP + local_4],BL
//         00511f7f     MOV        dword ptr [ESI + 0x2c],EDI
//         00511f82     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511f87     MOV        EDI,EAX
//         00511f89     ADD        ESP,0x4
//         00511f8c     MOV        dword ptr [ESP + param_6],EDI
//         00511f90     CMP        EDI,EBX
//         00511f92     MOV        byte ptr [ESP + local_4],0x5
//         00511f97     JZ         LAB_00511fa8
//         00511f99     MOV        this,EDI
//         00511f9b     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         00511fa0     MOV        dword ptr [EDI],TRIBE_Object_List::`vftable'     = 00511b00
//         00511fa6     JMP        LAB_00511faa
//                               LAB_00511fa8                                                 XREF[1]:     00511f97(j)
//         00511fa8     XOR        EDI,EDI
//                               LAB_00511faa                                                 XREF[1]:     00511fa6(j)
//                              tplayer.cpp:308 (14)
//         00511faa     MOV        this,ESI
//         00511fac     MOV        byte ptr [ESP + local_4],BL
//         00511fb0     MOV        dword ptr [ESI + 0x30],EDI
//         00511fb3     CALL       TRIBE_Player::new_victory                        void new_victory(TRIBE_Player * this)
//                              tplayer.cpp:309 (46)
//         00511fb8     PUSH       0x38
//         00511fba     CALL       operator_new                                     void * operator_new(uint param_1)
//         00511fbf     ADD        ESP,0x4
//         00511fc2     MOV        dword ptr [ESP + param_6],EAX
//         00511fc6     CMP        EAX,EBX
//         00511fc8     MOV        byte ptr [ESP + local_4],0x6
//         00511fcd     JZ         LAB_00511fdd
//         00511fcf     MOV        EDX,dword ptr [EBP + 0x28]
//         00511fd2     PUSH       ESI
//         00511fd3     PUSH       EDX
//         00511fd4     MOV        this,EAX
//         00511fd6     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         00511fdb     JMP        LAB_00511fdf
//                               LAB_00511fdd                                                 XREF[1]:     00511fcd(j)
//         00511fdd     XOR        EAX,EAX
//                               LAB_00511fdf                                                 XREF[1]:     00511fdb(j)
//         00511fdf     MOV        byte ptr [ESP + local_4],BL
//         00511fe3     MOV        dword ptr [ESI + 0x38],EAX
//                               LAB_00511fe6                                                 XREF[1]:     00511f18(j)
//                              tplayer.cpp:313 (14)
//         00511fe6     MOV        EAX,dword ptr [ESI + 0x3c]
//         00511fe9     MOV        EDI,0x1
//         00511fee     CMP        word ptr [EAX + 0x3c],DI
//         00511ff2     JLE        LAB_00512012
//                               LAB_00511ff4                                                 XREF[1]:     00512010(j)
//                              tplayer.cpp:314 (8)
//         00511ff4     MOVSX      this,word ptr [ESI + 0x4a]
//         00511ff8     CMP        EDI,this
//         00511ffa     JZ         LAB_00512006
//                              tplayer.cpp:315 (22)
//         00511ffc     PUSH       0x3
//         00511ffe     PUSH       EDI
//         00511fff     MOV        this,ESI
//         00512001     CALL       RGE_Player::set_relation                         void set_relation(RGE_Player * this, long par
//                               LAB_00512006                                                 XREF[1]:     00511ffa(j)
//         00512006     MOV        EDX,dword ptr [ESI + 0x3c]
//         00512009     INC        EDI
//         0051200a     MOVSX      EAX,word ptr [EDX + 0x3c]
//         0051200e     CMP        EDI,EAX
//         00512010     JL         LAB_00511ff4
//                               LAB_00512012                                                 XREF[1]:     00511ff2(j)
//                              tplayer.cpp:320 (53)
//         00512012     PUSH       0x140
//         00512017     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051201c     MOV        dword ptr [ESI + 0x228],EBX
//         00512022     MOV        dword ptr [ESI + 0x22c],EBX
//         00512028     MOV        dword ptr [ESI + 0x230],EBX
//         0051202e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00512033     LEA        this,[EAX + EAX*0x2]
//         00512036     MOV        EAX,0x80010003
//         0051203b     IMUL       this
//         0051203d     ADD        EDX,this
//         0051203f     ADD        ESP,0x8
//         00512042     SAR        EDX,0xe
//         00512045     MOV        this,EDX
//                              tplayer.cpp:322 (55)
//         00512047     PUSH       0x14
//         00512049     SHR        this,0x1f
//         0051204c     MOV        dword ptr [ESI + 0x234],EBX
//         00512052     LEA        EDX,[EDX + this->_padding_*0x1 + 0x3]
//         00512056     MOV        dword ptr [ESI + 0x224],EDX
//         0051205c     CALL       operator_new                                     void * operator_new(uint param_1)
//         00512061     ADD        ESP,0x4
//         00512064     MOV        dword ptr [ESP + param_6],EAX
//         00512068     CMP        EAX,EBX
//         0051206a     MOV        byte ptr [ESP + local_4],0x7
//         0051206f     JZ         LAB_0051207c
//         00512071     PUSH       -0x1
//         00512073     MOV        this,EAX
//         00512075     CALL       TRIBE_History_Info::TRIBE_History_Info           undefined TRIBE_History_Info(TRIBE_History_In
//         0051207a     JMP        LAB_0051207e
//                               LAB_0051207c                                                 XREF[1]:     0051206f(j)
//         0051207c     XOR        EAX,EAX
//                               LAB_0051207e                                                 XREF[1]:     0051207a(j)
//                              tplayer.cpp:323 (54)
//         0051207e     PUSH       0x10
//         00512080     MOV        byte ptr [ESP + local_4],BL
//         00512084     MOV        dword ptr [ESI + 0x83c],EAX
//         0051208a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051208f     ADD        ESP,0x4
//         00512092     MOV        dword ptr [ESP + param_6],EAX
//         00512096     CMP        EAX,EBX
//         00512098     MOV        byte ptr [ESP + local_4],0x8
//         0051209d     JZ         LAB_005120b2
//         0051209f     MOV        this,dword ptr [EBP + 0x104]
//         005120a5     PUSH       0x1
//         005120a7     PUSH       ESI
//         005120a8     PUSH       this
//         005120a9     MOV        this,EAX
//         005120ab     CALL       TRIBE_Player_Tech::TRIBE_Player_Tech             undefined TRIBE_Player_Tech(TRIBE_Player_Tech
//         005120b0     JMP        LAB_005120b4
//                               LAB_005120b2                                                 XREF[1]:     0051209d(j)
//         005120b2     XOR        EAX,EAX
//                               LAB_005120b4                                                 XREF[1]:     005120b0(j)
//                              tplayer.cpp:329 (46)
//         005120b4     MOV        this,dword ptr [ESP + local_c]
//         005120b8     MOV        dword ptr [ESI + 0x220],EAX
//         005120be     MOV        EAX,0xbf800000
//         005120c3     POP        EDI
//         005120c4     MOV        dword ptr [ESI + 0x840],EAX
//         005120ca     MOV        dword ptr [ESI + 0x844],EAX
//         005120d0     MOV        EAX,ESI
//         005120d2     POP        ESI
//         005120d3     POP        EBP
//         005120d4     MOV        dword ptr FS:[0x0],this
//         005120db     POP        EBX
//         005120dc     ADD        ESP,0x10
//         005120df     RET        0x28
//         005120e2     ??         90h
//         005120e3     NOP
//         005120e4     NOP
//         005120e5     NOP
//         005120e6     NOP
//         005120e7     NOP
//         005120e8     NOP
//         005120e9     NOP
//         005120ea     NOP
//         005120eb     NOP
//         005120ec     NOP
//         005120ed     NOP
//         005120ee     NOP
//         005120ef     NOP
}

TRIBE_Player::~TRIBE_Player() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Player(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0051211f(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051210b(W)
//                               ??1TRIBE_Player@@UAE@XZ                                      XREF[2]:     `vector_deleting_destructor':00511
//                               TRIBE_Player::~TRIBE_Player                                               ~TRIBE_Player:00519bbe(T),
//                                                                                                         ~TRIBE_Gaia:00519bc0(j)
//                              tplayer.cpp:333 (37)
//         005120f0     PUSH       -0x1
//         005120f2     PUSH       FUN_005611d8
//         005120f7     MOV        EAX,FS:[0x0]
//         005120fd     PUSH       EAX
//         005120fe     MOV        dword ptr FS:[0x0],ESP
//         00512105     PUSH       this
//         00512106     PUSH       EBX
//         00512107     PUSH       ESI
//         00512108     MOV        ESI,this
//         0051210a     PUSH       EDI
//         0051210b     MOV        dword ptr [ESP + local_10],ESI
//         0051210f     MOV        dword ptr [ESI],TRIBE_Player::`vftable'          = 00511e00
//                              tplayer.cpp:334 (16)
//         00512115     MOV        EDI,dword ptr [ESI + 0x220]
//         0051211b     XOR        EBX,EBX
//         0051211d     CMP        EDI,EBX
//         0051211f     MOV        dword ptr [ESP + local_4],EBX
//         00512123     JZ         LAB_0051213b
//                              tplayer.cpp:336 (16)
//         00512125     MOV        this,EDI
//         00512127     CALL       TRIBE_Player_Tech::~TRIBE_Player_Tech            void ~TRIBE_Player_Tech(TRIBE_Player_Tech * t
//         0051212c     PUSH       EDI
//         0051212d     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00512132     ADD        ESP,0x4
//                              tplayer.cpp:337 (6)
//         00512135     MOV        dword ptr [ESI + 0x220],EBX
//                               LAB_0051213b                                                 XREF[1]:     00512123(j)
//                              tplayer.cpp:340 (10)
//         0051213b     MOV        this,dword ptr [ESI + 0x238]
//         00512141     CMP        this,EBX
//         00512143     JZ         LAB_00512151
//                              tplayer.cpp:342 (6)
//         00512145     MOV        EAX,dword ptr [this->_padding_]
//         00512147     PUSH       0x1
//         00512149     CALL       dword ptr [EAX]
//                              tplayer.cpp:343 (6)
//         0051214b     MOV        dword ptr [ESI + 0x238],EBX
//                               LAB_00512151                                                 XREF[1]:     00512143(j)
//                              tplayer.cpp:346 (10)
//         00512151     MOV        EDI,dword ptr [ESI + 0x83c]
//         00512157     CMP        EDI,EBX
//         00512159     JZ         LAB_00512171
//                              tplayer.cpp:348 (16)
//         0051215b     MOV        this,EDI
//         0051215d     CALL       TRIBE_History_Info::~TRIBE_History_Info          void ~TRIBE_History_Info(TRIBE_History_Info *
//         00512162     PUSH       EDI
//         00512163     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00512168     ADD        ESP,0x4
//                              tplayer.cpp:349 (8)
//         0051216b     MOV        dword ptr [ESI + 0x83c],EBX
//                               LAB_00512171                                                 XREF[1]:     00512159(j)
//         00512171     MOV        this,ESI
//                              tplayer.cpp:351 (31)
//         00512173     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0051217b     CALL       RGE_Player::~RGE_Player                          void ~RGE_Player(RGE_Player * this)
//         00512180     MOV        this,dword ptr [ESP + 0x10]
//         00512184     POP        EDI
//         00512185     POP        ESI
//         00512186     MOV        dword ptr FS:[0x0],this
//         0051218d     POP        EBX
//         0051218e     ADD        ESP,0x10
//         00512191     RET
//         00512192     ??         90h
//         00512193     NOP
//         00512194     NOP
//         00512195     NOP
//         00512196     NOP
//         00512197     NOP
//         00512198     NOP
//         00512199     NOP
//         0051219a     NOP
//         0051219b     NOP
//         0051219c     NOP
//         0051219d     NOP
//         0051219e     NOP
//         0051219f     NOP
}

RGE_Static_Object* TRIBE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_scenario_obj(TRIBE_Player * this
//              RGE_Static_Obj    EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     005121c6(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     005121c1(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     005121ba(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     005121a4(R)
//              uchar             Stack[0x14]:1  param_5
//              float             Stack[0x18]:4  param_6
//                               ?make_scenario_obj@TRIBE_Player@@UAEPAVRGE_Static_Object@@M  XREF[2]:     005768d0(*), 00576a00(*)
//                               TRIBE_Player::make_scenario_obj
//                              tplayer.cpp:356 (4)
//         005121a0     PUSH       EBX
//         005121a1     PUSH       EBP
//         005121a2     PUSH       ESI
//         005121a3     PUSH       EDI
//                              tplayer.cpp:359 (22)
//         005121a4     MOVSX      EDI,word ptr [ESP + param_4]
//         005121a9     MOV        EBP,this
//         005121ab     XOR        ESI,ESI
//         005121ad     SHL        EDI,0x2
//         005121b0     MOV        EAX,dword ptr [EBP + 0x24]
//         005121b3     MOV        this,dword ptr [EAX + EDI*0x1]
//         005121b6     TEST       this,this
//         005121b8     JZ         LAB_00512239
//                              tplayer.cpp:361 (21)
//         005121ba     MOV        EAX,dword ptr [ESP + param_3]
//         005121be     MOV        EDX,dword ptr [this->_padding_]
//         005121c0     PUSH       EAX
//         005121c1     MOV        EAX,dword ptr [ESP + param_2]
//         005121c5     PUSH       EAX
//         005121c6     MOV        EAX,dword ptr [ESP + param_1]
//         005121ca     PUSH       EAX
//         005121cb     PUSH       EBP
//         005121cc     CALL       dword ptr [EDX + 0x18]
//                              tplayer.cpp:362 (11)
//         005121cf     MOV        BL,byte ptr [ESP + 0x24]
//         005121d3     MOV        ESI,EAX
//         005121d5     CMP        BL,0x7
//         005121d8     JC         LAB_005121e3
//                              tplayer.cpp:363 (7)
//         005121da     MOV        EDX,dword ptr [ESI]
//         005121dc     MOV        this,ESI
//         005121de     CALL       dword ptr [EDX + 0x68]
//                              tplayer.cpp:364 (7)
//         005121e1     JMP        LAB_0051221c
//                               LAB_005121e3                                                 XREF[1]:     005121d8(j)
//         005121e3     CMP        BL,0x2
//         005121e6     JBE        LAB_005121f1
//                              tplayer.cpp:365 (7)
//         005121e8     MOV        EAX,dword ptr [ESI]
//         005121ea     MOV        this,ESI
//         005121ec     CALL       dword ptr [EAX + 0x6c]
//                              tplayer.cpp:366 (2)
//         005121ef     JMP        LAB_0051221c
//                               LAB_005121f1                                                 XREF[1]:     005121e6(j)
//                              tplayer.cpp:368 (14)
//         005121f1     MOV        this,dword ptr [ESI + 0x8]
//         005121f4     MOV        AL,byte ptr [ECX + this->_padding_]
//         005121f7     CMP        AL,0x1e
//         005121f9     JBE        LAB_00512210
//         005121fb     CMP        AL,0x5a
//         005121fd     JNC        LAB_00512210
//                              tplayer.cpp:369 (15)
//         005121ff     MOV        EAX,dword ptr [ESP + 0x28]
//         00512203     MOV        EDX,dword ptr [ESI]
//         00512205     PUSH       EAX
//         00512206     MOV        this,ESI
//         00512208     CALL       dword ptr [EDX + 0xb4]
//                              tplayer.cpp:370 (2)
//         0051220e     JMP        LAB_0051221c
//                               LAB_00512210                                                 XREF[2]:     005121f9(j), 005121fd(j)
//                              tplayer.cpp:371 (12)
//         00512210     FLD        float ptr [ESP + 0x28]
//         00512214     CALL       __ftol                                           undefined __ftol()
//         00512219     MOV        byte ptr [ESI + 0x35],AL
//                               LAB_0051221c                                                 XREF[3]:     005121e1(j), 005121ef(j),
//                                                                                                         0051220e(j)
//                              tplayer.cpp:374 (12)
//         0051221c     MOV        this,dword ptr [EBP + 0x24]
//         0051221f     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
//         00512222     CMP        byte ptr [EDX + 0x4],0x50
//         00512226     JNZ        LAB_00512239
//                              tplayer.cpp:375 (5)
//         00512228     CMP        BL,0x2
//         0051222b     JNZ        LAB_00512239
//                              tplayer.cpp:376 (12)
//         0051222d     PUSH       0x461c4000
//         00512232     MOV        this,ESI
//         00512234     CALL       TRIBE_Building_Object::build                     uchar build(TRIBE_Building_Object * this, flo
//                               LAB_00512239                                                 XREF[3]:     005121b8(j), 00512226(j),
//                                                                                                         0051222b(j)
//                              tplayer.cpp:379 (2)
//         00512239     MOV        EAX,ESI
//                              tplayer.cpp:380 (7)
//         0051223b     POP        EDI
//         0051223c     POP        ESI
//         0051223d     POP        EBP
//         0051223e     POP        EBX
//         0051223f     RET        0x18
//         00512242     ??         90h
//         00512243     NOP
//         00512244     NOP
//         00512245     NOP
//         00512246     NOP
//         00512247     NOP
//         00512248     NOP
//         00512249     NOP
//         0051224a     NOP
//         0051224b     NOP
//         0051224c     NOP
//         0051224d     NOP
//         0051224e     NOP
//         0051224f     NOP
    return 0;
}

void TRIBE_Player::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0051225f(R), 00512351(*), 00512359(W), 00512384(*),
//                                                                                     0051238c(W)
//                               ?save@TRIBE_Player@@UAEXH@Z                                  XREF[2]:     save:00519c49(c), 005768f4(*)
//                               TRIBE_Player::save
//                              tplayer.cpp:384 (2)
//         00512250     PUSH       ESI
//         00512251     PUSH       EDI
//                              tplayer.cpp:385 (13)
//         00512252     PUSH       0x2
//         00512254     PUSH       0x16
//         00512256     MOV        ESI,this
//         00512258     PUSH       0x16
//         0051225a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              tplayer.cpp:387 (15)
//         0051225f     MOV        EDI,dword ptr [ESP + param_1]
//         00512263     ADD        ESP,0xc
//         00512266     MOV        this,ESI
//         00512268     PUSH       EDI
//         00512269     CALL       RGE_Player::save                                 void save(RGE_Player * this, int param_1)
//                              tplayer.cpp:389 (14)
//         0051226e     PUSH       0x2
//         00512270     PUSH       0x24
//         00512272     PUSH       0x16
//         00512274     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00512279     ADD        ESP,0xc
//                              tplayer.cpp:391 (15)
//         0051227c     LEA        EAX,[ESI + 0x48]
//         0051227f     PUSH       0x1
//         00512281     PUSH       EAX
//         00512282     PUSH       EDI
//         00512283     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00512288     ADD        ESP,0xc
//                              tplayer.cpp:392 (18)
//         0051228b     LEA        this,[ESI + 0x228]
//         00512291     PUSH       0x4
//         00512293     PUSH       this
//         00512294     PUSH       EDI
//         00512295     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0051229a     ADD        ESP,0xc
//                              tplayer.cpp:393 (18)
//         0051229d     LEA        EDX,[ESI + 0x230]
//         005122a3     PUSH       0x4
//         005122a5     PUSH       EDX
//         005122a6     PUSH       EDI
//         005122a7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         005122ac     ADD        ESP,0xc
//                              tplayer.cpp:394 (18)
//         005122af     LEA        EAX,[ESI + 0x224]
//         005122b5     PUSH       0x4
//         005122b7     PUSH       EAX
//         005122b8     PUSH       EDI
//         005122b9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         005122be     ADD        ESP,0xc
//                              tplayer.cpp:395 (15)
//         005122c1     LEA        this,[ESI + 0x234]
//         005122c7     PUSH       0x4
//         005122c9     PUSH       this
//         005122ca     PUSH       EDI
//         005122cb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:396 (15)
//         005122d0     MOV        this,dword ptr [ESI + 0x220]
//         005122d6     ADD        ESP,0xc
//         005122d9     PUSH       EDI
//         005122da     CALL       TRIBE_Player_Tech::save                          void save(TRIBE_Player_Tech * this, int param
//                              tplayer.cpp:397 (15)
//         005122df     LEA        EDX,[ESI + 0x22c]
//         005122e5     PUSH       0x4
//         005122e7     PUSH       EDX
//         005122e8     PUSH       EDI
//         005122e9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:398 (15)
//         005122ee     MOV        this,dword ptr [ESI + 0x83c]
//         005122f4     ADD        ESP,0xc
//         005122f7     PUSH       EDI
//         005122f8     CALL       TRIBE_History_Info::save                         void save(TRIBE_History_Info * this, int para
//                              tplayer.cpp:399 (18)
//         005122fd     LEA        EAX,[ESI + 0x840]
//         00512303     PUSH       0x4
//         00512305     PUSH       EAX
//         00512306     PUSH       EDI
//         00512307     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0051230c     ADD        ESP,0xc
//                              tplayer.cpp:400 (18)
//         0051230f     LEA        this,[ESI + 0x844]
//         00512315     PUSH       0x4
//         00512317     PUSH       this
//         00512318     PUSH       EDI
//         00512319     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0051231e     ADD        ESP,0xc
//                              tplayer.cpp:402 (11)
//         00512321     PUSH       0x2
//         00512323     PUSH       0x4c
//         00512325     PUSH       0x16
//         00512327     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              tplayer.cpp:406 (11)
//         0051232c     MOV        EAX,dword ptr [ESI + 0x4]
//         0051232f     ADD        ESP,0xc
//         00512332     CMP        EAX,0x1
//         00512335     JNZ        LAB_0051239c
//                              tplayer.cpp:409 (26)
//         00512337     MOV        EAX,dword ptr [ESI + 0x238]
//         0051233d     TEST       EAX,EAX
//         0051233f     JZ         LAB_00512384
//         00512341     MOV        this,dword ptr [comm]                            = 00000000
//         00512347     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         0051234c     CMP        EAX,0x1
//         0051234f     JNZ        LAB_00512384
//                              tplayer.cpp:412 (17)
//         00512351     LEA        EDX=>param_1,[ESP + 0xc]
//         00512355     PUSH       0x4
//         00512357     PUSH       EDX
//         00512358     PUSH       EDI
//         00512359     MOV        dword ptr [ESP + param_1],EAX
//         0051235d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:413 (15)
//         00512362     MOV        this,dword ptr [ESI + 0x238]
//         00512368     ADD        ESP,0xc
//         0051236b     MOV        EAX,dword ptr [this->_padding_]
//         0051236d     PUSH       EDI
//         0051236e     CALL       dword ptr [EAX + 0x3c]
//                              tplayer.cpp:423 (14)
//         00512371     PUSH       0x2
//         00512373     PUSH       offset DAT_fffffff8
//         00512375     PUSH       offset DAT_fffffff4
//         00512377     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0051237c     ADD        ESP,0xc
//                              tplayer.cpp:424 (5)
//         0051237f     POP        EDI
//         00512380     POP        ESI
//         00512381     RET        0x4
//                               LAB_00512384                                                 XREF[2]:     0051233f(j), 0051234f(j)
//                              tplayer.cpp:419 (24)
//         00512384     LEA        this=>param_1,[ESP + 0xc]
//         00512388     PUSH       0x4
//         0051238a     PUSH       this
//         0051238b     PUSH       EDI
//         0051238c     MOV        dword ptr [ESP + param_1],0x0
//         00512394     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00512399     ADD        ESP,0xc
//                               LAB_0051239c                                                 XREF[1]:     00512335(j)
//                              tplayer.cpp:423 (14)
//         0051239c     PUSH       0x2
//         0051239e     PUSH       0x5f
//         005123a0     PUSH       0x16
//         005123a2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         005123a7     ADD        ESP,0xc
//                              tplayer.cpp:424 (5)
//         005123aa     POP        EDI
//         005123ab     POP        ESI
//         005123ac     RET        0x4
//         005123af     ??         90h
    return;
}

void TRIBE_Player::update() {
    /* TODO: Stub */
//                              void __thiscall update(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?update@TRIBE_Player@@UAEXXZ                                 XREF[1]:     005768ec(*)
//                               TRIBE_Player::update
//                              tplayer.cpp:440 (5)
//         005123b0     PUSH       EBX
//         005123b1     PUSH       EBP
//         005123b2     PUSH       ESI
//         005123b3     MOV        ESI,this
//                              tplayer.cpp:508 (41)
//         005123b5     XOR        EBP,EBP
//         005123b7     PUSH       EDI
//         005123b8     MOV        EAX,dword ptr [ESI + 0x3c]
//         005123bb     FLD        float ptr [EAX + 0x84]
//         005123c1     FADD       float ptr [ESI + 0x234]
//         005123c7     FST        float ptr [ESI + 0x234]
//         005123cd     FCOMP      float ptr [DAT_00576824]
//         005123d3     FNSTSW     AX
//         005123d5     TEST       AH,0x41
//         005123d8     JNZ        LAB_00512557
//                              tplayer.cpp:549 (76)
//         005123de     MOV        EDI,0x42c80000
//         005123e3     MOV        EBX,0x2
//                               LAB_005123e8                                                 XREF[1]:     00512551(j)
//         005123e8     FLD        float ptr [ESI + 0x234]
//         005123ee     MOV        EDX,dword ptr [ESI + 0x22c]
//         005123f4     FSUB       float ptr [DAT_00576824]
//         005123fa     INC        EDX
//         005123fb     MOV        EAX,EDX
//         005123fd     MOV        dword ptr [ESI + 0x22c],EDX
//         00512403     CMP        EAX,0xf
//         00512406     FSTP       float ptr [ESI + 0x234]
//         0051240c     JL         LAB_00512442
//         0051240e     MOV        this,dword ptr [ESI + 0x50]
//         00512411     ADD        EAX,-0xf
//         00512414     MOV        dword ptr [ESI + 0x22c],EAX
//         0051241a     FLD        float ptr [ECX + this->_padding_]
//         0051241d     FCOMP      float ptr [DAT_00576828]
//         00512423     FNSTSW     AX
//         00512425     TEST       AH,0x1
//         00512428     JZ         LAB_0051242d
//                              tplayer.cpp:519 (1)
//         0051242a     PUSH       EBP
//                              tplayer.cpp:520 (2)
//         0051242b     JMP        LAB_00512436
//                               LAB_0051242d                                                 XREF[1]:     00512428(j)
//                              tplayer.cpp:521 (21)
//         0051242d     FLD        float ptr [ECX + this->_padding_]
//         00512430     CALL       __ftol                                           undefined __ftol()
//         00512435     PUSH       EAX
//                               LAB_00512436                                                 XREF[1]:     0051242b(j)
//         00512436     MOV        this,dword ptr [ESI + 0x83c]
//         0051243c     PUSH       EBP=>DAT_fffffff8
//         0051243d     CALL       TRIBE_History_Info::add_history_entry            void add_history_entry(TRIBE_History_Info * t
//                               LAB_00512442                                                 XREF[1]:     0051240c(j)
//                              tplayer.cpp:525 (15)
//         00512442     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00512448     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//         0051244d     TEST       EAX,EAX
//         0051244f     JZ         LAB_00512459
//                              tplayer.cpp:526 (6)
//         00512451     MOV        this,dword ptr [ESI + 0x50]
//         00512454     MOV        dword ptr [ECX + this->_padding_],EDI
//                              tplayer.cpp:527 (2)
//         00512457     JMP        LAB_0051246d
//                               LAB_00512459                                                 XREF[1]:     0051244f(j)
//                              tplayer.cpp:528 (20)
//         00512459     MOV        this,dword ptr [ESI + 0x38]
//         0051245c     CALL       RGE_Visible_Map::percentExplored                 float percentExplored(RGE_Visible_Map * this)
//         00512461     FMUL       float ptr [DAT_0057682c]
//         00512467     MOV        EDX,dword ptr [ESI + 0x50]
//         0051246a     FSTP       float ptr [EDX + 0x58]
//                               LAB_0051246d                                                 XREF[1]:     00512457(j)
//                              tplayer.cpp:531 (18)
//         0051246d     MOV        EAX,dword ptr [ESI + 0x50]
//         00512470     FLD        float ptr [EAX + 0x4c]
//         00512473     FSUB       float ptr [EAX + 0x2c]
//         00512476     FSUBR      float ptr [EAX + 0x50]
//         00512479     FSTP       float ptr [EAX + 0xb0]
//                              tplayer.cpp:532 (22)
//         0051247f     MOV        this,dword ptr [ESI + 0x50]
//         00512482     FLD        float ptr [ECX + this->_padding_]
//         00512488     FCOMP      double ptr [DAT_00576830]
//         0051248e     FNSTSW     AX
//         00512490     TEST       AH,0x1
//         00512493     JZ         LAB_0051249b
//                              tplayer.cpp:533 (6)
//         00512495     MOV        dword ptr [ECX + this->_padding_],EBP
//                               LAB_0051249b                                                 XREF[1]:     00512493(j)
//                              tplayer.cpp:536 (12)
//         0051249b     MOV        EAX,dword ptr [ESI + 0x50]
//         0051249e     FLD        float ptr [EAX + 0x28]
//         005124a1     FADD       float ptr [EAX + 0x24]
//         005124a4     FSTP       float ptr [EAX + 0x24]
//                              tplayer.cpp:537 (19)
//         005124a7     MOV        this,dword ptr [ESI + 0x50]
//         005124aa     FLD        float ptr [ECX + this->_padding_]
//         005124ad     FCOMP      double ptr [DAT_00576838]
//         005124b3     FNSTSW     AX
//         005124b5     TEST       AH,0x41
//         005124b8     JNZ        LAB_005124bd
//                              tplayer.cpp:538 (3)
//         005124ba     MOV        dword ptr [ECX + this->_padding_],EDI
//                               LAB_005124bd                                                 XREF[1]:     005124b8(j)
//                              tplayer.cpp:542 (10)
//         005124bd     MOV        EAX,dword ptr [ESI + 0x228]
//         005124c3     CMP        EAX,EBP
//         005124c5     JLE        LAB_005124ce
//                              tplayer.cpp:543 (7)
//         005124c7     DEC        EAX
//         005124c8     MOV        dword ptr [ESI + 0x228],EAX
//                               LAB_005124ce                                                 XREF[1]:     005124c5(j)
//                              tplayer.cpp:544 (10)
//         005124ce     MOV        EAX,dword ptr [ESI + 0x230]
//         005124d4     CMP        EAX,EBP
//         005124d6     JLE        LAB_005124df
//                              tplayer.cpp:545 (7)
//         005124d8     DEC        EAX
//         005124d9     MOV        dword ptr [ESI + 0x230],EAX
//                               LAB_005124df                                                 XREF[1]:     005124d6(j)
//                              tplayer.cpp:549 (6)
//         005124df     CMP        word ptr [ESI + 0x4a],BP
//         005124e3     JLE        LAB_00512540
//                              tplayer.cpp:551 (10)
//         005124e5     MOV        EAX,dword ptr [ESI + 0x28]
//         005124e8     MOV        this,dword ptr [EAX + 0x4]
//         005124eb     CMP        this,EBP
//         005124ed     JZ         LAB_0051252f
//                               LAB_005124ef                                                 XREF[1]:     00512529(j)
//                              tplayer.cpp:553 (9)
//         005124ef     MOV        EDX,dword ptr [this->_padding_]
//         005124f1     MOV        EAX,dword ptr [EDX + 0x8]
//         005124f4     MOVSX      EAX,word ptr [EAX + 0x14]
//                              tplayer.cpp:562 (44)
//         005124f8     CMP        EAX,0xb
//         005124fb     JZ         LAB_00512524
//         005124fd     CMP        EAX,0x1e
//         00512500     JZ         LAB_00512524
//         00512502     CMP        EAX,0x1b
//         00512505     JZ         LAB_00512524
//         00512507     CMP        EAX,0x1
//         0051250a     JZ         LAB_00512524
//         0051250c     CMP        EAX,0x15
//         0051250f     JZ         LAB_00512524
//         00512511     CMP        EAX,0x14
//         00512514     JZ         LAB_00512524
//         00512516     CMP        EAX,EBX
//         00512518     JZ         LAB_00512524
//         0051251a     CMP        EAX,0x25
//         0051251d     JZ         LAB_00512524
//         0051251f     CMP        byte ptr [EDX + 0x48],BL
//         00512522     JZ         LAB_0051252b
//                               LAB_00512524                                                 XREF[8]:     005124fb(j), 00512500(j),
//                                                                                                         00512505(j), 0051250a(j),
//                                                                                                         0051250f(j), 00512514(j),
//                                                                                                         00512518(j), 0051251d(j)
//                              tplayer.cpp:551 (7)
//         00512524     MOV        this,dword ptr [ECX + this->_padding_]
//         00512527     CMP        this,EBP
//         00512529     JNZ        LAB_005124ef
//                               LAB_0051252b                                                 XREF[1]:     00512522(j)
//                              tplayer.cpp:567 (4)
//         0051252b     CMP        this,EBP
//         0051252d     JNZ        LAB_00512540
//                               LAB_0051252f                                                 XREF[1]:     005124ed(j)
//                              tplayer.cpp:569 (8)
//         0051252f     MOV        EDX,dword ptr [ESI]
//         00512531     PUSH       EBX
//         00512532     MOV        this,ESI
//         00512534     CALL       dword ptr [EDX + 0x4]
//                              tplayer.cpp:570 (32)
//         00512537     MOV        EAX,dword ptr [ESI + 0x50]
//         0051253a     MOV        dword ptr [EAX + 0xb4],EBP
//                               LAB_00512540                                                 XREF[2]:     005124e3(j), 0051252d(j)
//         00512540     FLD        float ptr [ESI + 0x234]
//         00512546     FCOMP      float ptr [DAT_00576824]
//         0051254c     FNSTSW     AX
//         0051254e     TEST       AH,0x41
//         00512551     JZ         LAB_005123e8
//                               LAB_00512557                                                 XREF[1]:     005123d8(j)
//                              tplayer.cpp:583 (7)
//         00512557     MOV        this,ESI
//         00512559     CALL       RGE_Player::update                               void update(RGE_Player * this)
//                              tplayer.cpp:589 (31)
//         0051255e     MOV        this,dword ptr [ESI + 0x3c]
//         00512561     MOV        EAX,dword ptr [ESI + 0x50]
//         00512564     FLD        float ptr [ECX + this->_padding_]
//         0051256a     FMUL       float ptr [EAX + 0x84]
//         00512570     FMUL       float ptr [EAX + 0x2c]
//         00512573     FMUL       float ptr [DAT_00576840]                         = 89h
//         00512579     FSUBR      float ptr [EAX]
//         0051257b     FSTP       float ptr [EAX]
//                              tplayer.cpp:590 (18)
//         0051257d     MOV        this,dword ptr [ESI + 0x50]
//         00512580     FLD        float ptr [this->_padding_]
//         00512582     FCOMP      double ptr [DAT_00576830]
//         00512588     FNSTSW     AX
//         0051258a     TEST       AH,0x1
//         0051258d     JZ         LAB_00512591
//                              tplayer.cpp:591 (2)
//         0051258f     MOV        dword ptr [this->_padding_],EBP
//                               LAB_00512591                                                 XREF[1]:     0051258d(j)
//                              tplayer.cpp:607 (15)
//         00512591     PUSH       0x25f
//         00512596     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051259b     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//                              tplayer.cpp:609 (8)
//         005125a0     MOV        EDI,dword ptr [debug_random_on]
//         005125a6     MOV        EBX,EAX
//                              tplayer.cpp:610 (6)
//         005125a8     MOV        dword ptr [global_save_debug_random_on1],EDI
//                              tplayer.cpp:611 (6)
//         005125ae     MOV        dword ptr [debug_random_on],EBP
//                              tplayer.cpp:615 (29)
//         005125b4     MOV        EAX,dword ptr [ESI + 0x238]
//         005125ba     ADD        ESP,0x8
//         005125bd     CMP        EAX,EBP
//         005125bf     JZ         LAB_005125f0
//         005125c1     MOV        this,dword ptr [comm]                            = 00000000
//         005125c7     CALL       TCommunications_Handler::ComputerPlayerGameStart int ComputerPlayerGameStart(TCommunications_H
//         005125cc     CMP        EAX,0x1
//         005125cf     JNZ        LAB_005125f0
//                              tplayer.cpp:618 (12)
//         005125d1     MOV        this,dword ptr [ESI + 0x3c]
//         005125d4     CMP        dword ptr [ECX + this->_padding_],-0x1
//         005125db     JNZ        LAB_005125e4
//                              tplayer.cpp:619 (7)
//         005125dd     PUSH       0x3
//         005125df     CALL       RGE_Game_World::selectNextComputerPlayer         void selectNextComputerPlayer(RGE_Game_World
//                               LAB_005125e4                                                 XREF[1]:     005125db(j)
//                              tplayer.cpp:621 (12)
//         005125e4     MOV        this,dword ptr [ESI + 0x238]
//         005125ea     PUSH       EBP
//         005125eb     MOV        EDX,dword ptr [this->_padding_]
//         005125ed     CALL       dword ptr [EDX + 0x30]
//                               LAB_005125f0                                                 XREF[2]:     005125bf(j), 005125cf(j)
//                              tplayer.cpp:631 (22)
//         005125f0     PUSH       EBX
//         005125f1     PUSH       offset DAT_fffffff8
//         005125f6     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005125fb     MOV        dword ptr [debug_random_on],EDI
//         00512601     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
//                              tplayer.cpp:635 (13)
//         00512606     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         0051260c     ADD        ESP,0xc
//         0051260f     CMP        this,EBP
//         00512611     JZ         LAB_00512618
//                              tplayer.cpp:636 (5)
//         00512613     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00512618                                                 XREF[1]:     00512611(j)
//                              tplayer.cpp:642 (5)
//         00512618     POP        EDI
//         00512619     POP        ESI
//         0051261a     POP        EBP
//         0051261b     POP        EBX
//         0051261c     RET
    return;
}

void TRIBE_Player::update_dopplegangers() {
    /* TODO: Stub */
//                              void __thiscall update_dopplegangers(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?update_dopplegangers@TRIBE_Player@@UAEXXZ                   XREF[2]:     005768f0(*), 00576a20(*)
//                               TRIBE_Player::update_dopplegangers
//                              tplayer.cpp:645 (5)
//         00512620     JMP        RGE_Player::update_dopplegangers
//         00512625     ??         90h
//         00512626     NOP
//         00512627     NOP
//         00512628     NOP
//         00512629     NOP
//         0051262a     NOP
//         0051262b     NOP
//         0051262c     NOP
//         0051262d     NOP
//         0051262e     NOP
//         0051262f     NOP
    return;
}

void TRIBE_Player::scenario_save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall scenario_save(TRIBE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00512632(R)
//                               ?scenario_save@TRIBE_Player@@UAEXH@Z                         XREF[2]:     005768d4(*), 00576a04(*)
//                               TRIBE_Player::scenario_save
//                              tplayer.cpp:652 (2)
//         00512630     PUSH       ESI
//         00512631     PUSH       EDI
//                              tplayer.cpp:653 (12)
//         00512632     MOV        EDI,dword ptr [ESP + param_1]
//         00512636     MOV        ESI,this
//         00512638     PUSH       EDI
//         00512639     CALL       RGE_Player::scenario_save                        void scenario_save(RGE_Player * this, int par
//                              tplayer.cpp:656 (12)
//         0051263e     MOV        EAX,dword ptr [ESI + 0x50]
//         00512641     PUSH       0x4
//         00512643     PUSH       EAX
//         00512644     PUSH       EDI
//         00512645     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:657 (18)
//         0051264a     MOV        this,dword ptr [ESI + 0x50]
//         0051264d     ADD        ESP,0xc
//         00512650     ADD        this,0x4
//         00512653     PUSH       0x4
//         00512655     PUSH       this
//         00512656     PUSH       EDI
//         00512657     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:658 (18)
//         0051265c     MOV        EDX,dword ptr [ESI + 0x50]
//         0051265f     ADD        ESP,0xc
//         00512662     ADD        EDX,0xc
//         00512665     PUSH       0x4
//         00512667     PUSH       EDX
//         00512668     PUSH       EDI
//         00512669     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              tplayer.cpp:659 (21)
//         0051266e     MOV        EAX,dword ptr [ESI + 0x50]
//         00512671     ADD        ESP,0xc
//         00512674     ADD        EAX,0x8
//         00512677     PUSH       0x4
//         00512679     PUSH       EAX
//         0051267a     PUSH       EDI
//         0051267b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00512680     ADD        ESP,0xc
//                              tplayer.cpp:661 (5)
//         00512683     POP        EDI
//         00512684     POP        ESI
//         00512685     RET        0x4
//         00512688     ??         90h
//         00512689     NOP
//         0051268a     NOP
//         0051268b     NOP
//         0051268c     NOP
//         0051268d     NOP
//         0051268e     NOP
//         0051268f     NOP
    return;
}

void TRIBE_Player::scenario_load(int param_1, long* param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall scenario_load(TRIBE_Player * this, int param_1, long
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005126aa(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     005126b1(R)
//              float             Stack[0xc]:4   param_3                   XREF[5]:     0051269e(R), 005126fc(R), 00512757(R), 00512781(W),
//                                                                                     005127e4(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00512787(W), 005127ea(W), 0051281a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     005127ac(R), 005127c8(R), 0051288c(R)
//                               ?scenario_load@TRIBE_Player@@UAEXHPAJM@Z                     XREF[2]:     005768d8(*), 00576a08(*)
//                               TRIBE_Player::scenario_load
//                              tplayer.cpp:665 (14)
//         00512690     MOV        EAX,FS:[0x0]
//         00512696     PUSH       -0x1
//         00512698     PUSH       FUN_00561206
//         0051269d     PUSH       EAX
//                              tplayer.cpp:668 (34)
//         0051269e     MOV        EAX,dword ptr [ESP + param_3]
//         005126a2     MOV        dword ptr FS:[0x0],ESP
//         005126a9     PUSH       EBX
//         005126aa     MOV        EBX,dword ptr [ESP + param_1]
//         005126ae     PUSH       ESI
//         005126af     MOV        ESI,this
//         005126b1     MOV        this,dword ptr [ESP + param_2]
//         005126b5     PUSH       EDI
//         005126b6     PUSH       EAX
//         005126b7     PUSH       this
//         005126b8     PUSH       EBX
//         005126b9     MOV        this,ESI
//         005126bb     CALL       RGE_Player::scenario_load                        void scenario_load(RGE_Player * this, int par
//                              tplayer.cpp:670 (10)
//         005126c0     MOV        EDI,dword ptr [ESI + 0x220]
//         005126c6     TEST       EDI,EDI
//         005126c8     JZ         LAB_005126da
//                              tplayer.cpp:671 (16)
//         005126ca     MOV        this,EDI
//         005126cc     CALL       TRIBE_Player_Tech::~TRIBE_Player_Tech            void ~TRIBE_Player_Tech(TRIBE_Player_Tech * t
//         005126d1     PUSH       EDI
//         005126d2     CALL       operator_delete                                  void operator_delete(void * param_1)
//         005126d7     ADD        ESP,0x4
//                               LAB_005126da                                                 XREF[1]:     005126c8(j)
//                              tplayer.cpp:673 (8)
//         005126da     XOR        EDI,EDI
//         005126dc     CMP        word ptr [ESI + 0x22],DI
//         005126e0     JLE        LAB_005126fc
//                               LAB_005126e2                                                 XREF[1]:     005126fa(j)
//                              tplayer.cpp:674 (10)
//         005126e2     MOV        EDX,dword ptr [ESI + 0x24]
//         005126e5     MOV        this,dword ptr [EDX + EDI*0x4]
//         005126e8     TEST       this,this
//         005126ea     JZ         LAB_005126f3
//                              tplayer.cpp:675 (16)
//         005126ec     PUSH       0x0
//         005126ee     CALL       RGE_Master_Static_Object::make_available         void make_available(RGE_Master_Static_Object
//                               LAB_005126f3                                                 XREF[1]:     005126ea(j)
//         005126f3     MOVSX      EAX,word ptr [ESI + 0x22]
//         005126f7     INC        EDI
//         005126f8     CMP        EDI,EAX
//         005126fa     JL         LAB_005126e2
//                               LAB_005126fc                                                 XREF[1]:     005126e0(j)
//                              tplayer.cpp:678 (17)
//         005126fc     FLD        float ptr [ESP + param_3]
//         00512700     FCOMP      double ptr [DAT_00576848]                        = F6h
//         00512706     FNSTSW     AX
//         00512708     TEST       AH,0x41
//         0051270b     JNZ        LAB_00512752
//                              tplayer.cpp:680 (12)
//         0051270d     MOV        this,dword ptr [ESI + 0x50]
//         00512710     PUSH       0x4
//         00512712     PUSH       this
//         00512713     PUSH       EBX
//         00512714     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:681 (18)
//         00512719     MOV        EDX,dword ptr [ESI + 0x50]
//         0051271c     ADD        ESP,0xc
//         0051271f     ADD        EDX,0x4
//         00512722     PUSH       0x4
//         00512724     PUSH       EDX
//         00512725     PUSH       EBX
//         00512726     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:682 (18)
//         0051272b     MOV        EAX,dword ptr [ESI + 0x50]
//         0051272e     ADD        ESP,0xc
//         00512731     ADD        EAX,0xc
//         00512734     PUSH       0x4
//         00512736     PUSH       EAX
//         00512737     PUSH       EBX
//         00512738     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:683 (21)
//         0051273d     MOV        this,dword ptr [ESI + 0x50]
//         00512740     ADD        ESP,0xc
//         00512743     ADD        this,0x8
//         00512746     PUSH       0x4
//         00512748     PUSH       this
//         00512749     PUSH       EBX
//         0051274a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0051274f     ADD        ESP,0xc
//                               LAB_00512752                                                 XREF[1]:     0051270b(j)
//                              tplayer.cpp:685 (3)
//         00512752     MOV        EDX,dword ptr [ESI + 0x50]
//                              tplayer.cpp:689 (87)
//         00512755     PUSH       0x10
//         00512757     FLD        float ptr [ESP + param_3]
//         0051275b     FCOMP      double ptr [DAT_00576850]                        = 7Bh    {
//         00512761     MOV        dword ptr [EDX + 0x78],0x0
//         00512768     MOV        EAX,dword ptr [ESI + 0x50]
//         0051276b     MOV        dword ptr [EAX + 0x54],0x0
//         00512772     FNSTSW     AX
//         00512774     TEST       AH,0x41
//         00512777     JZ         LAB_005127dc
//         00512779     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051277e     ADD        ESP,0x4
//         00512781     MOV        dword ptr [ESP + param_3],EAX
//         00512785     TEST       EAX,EAX
//         00512787     MOV        dword ptr [ESP + local_4],0x0
//         0051278f     JZ         LAB_005127c0
//         00512791     MOV        this,dword ptr [ESI + 0x3c]
//         00512794     PUSH       0x1
//         00512796     PUSH       ESI
//         00512797     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051279d     MOV        this,EAX
//         0051279f     PUSH       EDX
//         005127a0     PUSH       EBX
//         005127a1     CALL       TRIBE_Player_Tech::TRIBE_Player_Tech             undefined TRIBE_Player_Tech(TRIBE_Player_Tech
//         005127a6     MOV        dword ptr [ESI + 0x220],EAX
//                              tplayer.cpp:706 (20)
//         005127ac     MOV        this,dword ptr [ESP + local_c]
//         005127b0     MOV        dword ptr FS:[0x0],this
//         005127b7     POP        EDI
//         005127b8     POP        ESI
//         005127b9     POP        EBX
//         005127ba     ADD        ESP,0xc
//         005127bd     RET        0xc
//                               LAB_005127c0                                                 XREF[1]:     0051278f(j)
//                              tplayer.cpp:689 (8)
//         005127c0     XOR        EAX,EAX
//         005127c2     MOV        dword ptr [ESI + 0x220],EAX
//                              tplayer.cpp:706 (20)
//         005127c8     MOV        this,dword ptr [ESP + local_c]
//         005127cc     MOV        dword ptr FS:[0x0],this
//         005127d3     POP        EDI
//         005127d4     POP        ESI
//         005127d5     POP        EBX
//         005127d6     ADD        ESP,0xc
//         005127d9     RET        0xc
//                               LAB_005127dc                                                 XREF[1]:     00512777(j)
//                              tplayer.cpp:692 (54)
//         005127dc     CALL       operator_new                                     void * operator_new(uint param_1)
//         005127e1     ADD        ESP,0x4
//         005127e4     MOV        dword ptr [ESP + param_3],EAX
//         005127e8     TEST       EAX,EAX
//         005127ea     MOV        dword ptr [ESP + local_4],0x1
//         005127f2     JZ         LAB_0051280a
//         005127f4     MOV        this,dword ptr [ESI + 0x3c]
//         005127f7     PUSH       0x0
//         005127f9     PUSH       ESI
//         005127fa     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00512800     MOV        this,EAX
//         00512802     PUSH       EDX
//         00512803     CALL       TRIBE_Player_Tech::TRIBE_Player_Tech             undefined TRIBE_Player_Tech(TRIBE_Player_Tech
//         00512808     JMP        LAB_0051280c
//                               LAB_0051280a                                                 XREF[1]:     005127f2(j)
//         0051280a     XOR        EAX,EAX
//                               LAB_0051280c                                                 XREF[1]:     00512808(j)
//         0051280c     MOV        dword ptr [ESI + 0x220],EAX
//                              tplayer.cpp:693 (50)
//         00512812     MOV        EAX,dword ptr [ESI + 0x10c]
//         00512818     TEST       EAX,EAX
//         0051281a     MOV        dword ptr [ESP + local_4],0xffffffff
//         00512822     JL         LAB_00512855
//         00512824     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051282a     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
//         0051282f     TEST       EAX,EAX
//         00512831     JNZ        LAB_00512855
//         00512833     MOV        EAX,dword ptr [ESI + 0x3c]
//         00512836     PUSH       0x2
//         00512838     MOV        this,dword ptr [EAX + 0x5c]
//         0051283b     CALL       T_Scenario::GetScenarioOption                    int GetScenarioOption(T_Scenario * this, int
//         00512840     TEST       EAX,EAX
//         00512842     JNZ        LAB_00512855
//                              tplayer.cpp:694 (15)
//         00512844     MOV        this,word ptr [ESI + 0x10c]
//         0051284b     MOV        EDX,dword ptr [ESI + 0x3c]
//         0051284e     PUSH       ESI
//         0051284f     PUSH       this
//         00512850     MOV        this,dword ptr [EDX + 0x4c]
//                              tplayer.cpp:695 (2)
//         00512853     JMP        LAB_00512861
//                               LAB_00512855                                                 XREF[3]:     00512822(j), 00512831(j),
//                                                                                                         00512842(j)
//                              tplayer.cpp:696 (17)
//         00512855     MOV        EAX,dword ptr [ESI + 0x3c]
//         00512858     PUSH       ESI
//         00512859     PUSH       0xd2
//         0051285e     MOV        this,dword ptr [EAX + 0x4c]
//                               LAB_00512861                                                 XREF[1]:     00512853(j)
//         00512861     CALL       TRIBE_Effects::do_tech_effect                    void do_tech_effect(TRIBE_Effects * this, sho
//                              tplayer.cpp:699 (15)
//         00512866     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051286c     CMP        dword ptr [ECX + this->_padding_],0x7
//         00512873     JZ         LAB_00512881
//                              tplayer.cpp:700 (12)
//         00512875     MOV        EDX,dword ptr [ESI + 0x3c]
//         00512878     PUSH       ESI
//         00512879     MOV        this,dword ptr [EDX + 0x5c]
//         0051287c     CALL       T_Scenario::set_player_tech                      void set_player_tech(T_Scenario * this, TRIBE
//                               LAB_00512881                                                 XREF[1]:     00512873(j)
//                              tplayer.cpp:703 (11)
//         00512881     MOV        this,dword ptr [ESI + 0x220]
//         00512887     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech *
//                              tplayer.cpp:706 (20)
//         0051288c     MOV        this,dword ptr [ESP + local_c]
//         00512890     POP        EDI
//         00512891     POP        ESI
//         00512892     MOV        dword ptr FS:[0x0],this
//         00512899     POP        EBX
//         0051289a     ADD        ESP,0xc
//         0051289d     RET        0xc
    return;
}

void TRIBE_Player::load(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load(TRIBE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     005128b7(R), 0051290f(*), 0051291f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[10]:    00512954(W), 00512973(W), 00512988(W), 005129a1(W),
//                                                                                     005129bb(W), 005129dd(W), 005129fb(W), 00512a1b(W),
//                                                                                     00512a39(W), 00512a53(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00512a74(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[5]:     0051294e(W), 00512982(W), 005129b5(W), 005129f5(W),
//                                                                                     00512a33(W)
//                               ?load@TRIBE_Player@@UAEXH@Z                                  XREF[2]:     005768e4(*), 00576a14(*)
//                               TRIBE_Player::load
//                              tplayer.cpp:710 (23)
//         005128a0     PUSH       -0x1
//         005128a2     PUSH       FUN_00561247
//         005128a7     MOV        EAX,FS:[0x0]
//         005128ad     PUSH       EAX
//         005128ae     MOV        dword ptr FS:[0x0],ESP
//         005128b5     PUSH       this
//         005128b6     PUSH       EBX
//                              tplayer.cpp:714 (21)
//         005128b7     MOV        EBX,dword ptr [ESP + param_1]
//         005128bb     PUSH       EBP
//         005128bc     PUSH       ESI
//         005128bd     MOV        ESI,this
//         005128bf     PUSH       EDI
//         005128c0     PUSH       0x2
//         005128c2     LEA        EBP,[ESI + 0x22]
//         005128c5     PUSH       EBP
//         005128c6     PUSH       EBX
//         005128c7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:715 (14)
//         005128cc     MOV        AX,word ptr [EBP]
//         005128d0     XOR        EDI,EDI
//         005128d2     ADD        ESP,0xc
//         005128d5     CMP        AX,DI
//         005128d8     JLE        LAB_00512941
//                              tplayer.cpp:717 (11)
//         005128da     MOVSX      EAX,AX
//         005128dd     PUSH       0x4
//         005128df     PUSH       EAX
//         005128e0     CALL       calloc                                           undefined calloc()
//                              tplayer.cpp:718 (24)
//         005128e5     MOVSX      this,word ptr [EBP]
//         005128e9     ADD        ESP,0x8
//         005128ec     MOV        dword ptr [ESI + 0x24],EAX
//         005128ef     SHL        this,0x2
//         005128f2     PUSH       this
//         005128f3     PUSH       EAX
//         005128f4     PUSH       EBX
//         005128f5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         005128fa     ADD        ESP,0xc
//                              tplayer.cpp:719 (6)
//         005128fd     CMP        word ptr [EBP],DI
//         00512901     JLE        LAB_00512944
//                               LAB_00512903                                                 XREF[1]:     0051293d(j)
//                              tplayer.cpp:720 (12)
//         00512903     MOV        EAX,dword ptr [ESI + 0x24]
//         00512906     MOVSX      EDX,DI
//         00512909     CMP        dword ptr [EAX + EDX*0x4],0x0
//         0051290d     JZ         LAB_00512938
//                              tplayer.cpp:722 (13)
//         0051290f     LEA        this=>param_1,[ESP + 0x24]
//         00512913     PUSH       0x1
//         00512915     PUSH       this
//         00512916     PUSH       EBX
//         00512917     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:723 (35)
//         0051291c     MOV        EAX,dword ptr [ESI + 0x3c]
//         0051291f     MOV        this,dword ptr [ESP + param_1]
//         00512923     ADD        ESP,0xc
//         00512926     MOV        EDX,dword ptr [EAX + 0x30]
//         00512929     MOV        EAX,dword ptr [EAX + 0x38]
//         0051292c     PUSH       EDX
//         0051292d     PUSH       EAX
//         0051292e     PUSH       this
//         0051292f     PUSH       EDI
//         00512930     PUSH       EBX
//         00512931     MOV        this,ESI
//         00512933     CALL       TRIBE_Player::load_master_object                 void load_master_object(TRIBE_Player * this,
//                               LAB_00512938                                                 XREF[1]:     0051290d(j)
//         00512938     INC        EDI
//         00512939     CMP        DI,word ptr [EBP]
//         0051293d     JL         LAB_00512903
//                              tplayer.cpp:726 (2)
//         0051293f     JMP        LAB_00512944
//                               LAB_00512941                                                 XREF[1]:     005128d8(j)
//                              tplayer.cpp:727 (3)
//         00512941     MOV        dword ptr [ESI + 0x24],EDI
//                               LAB_00512944                                                 XREF[2]:     00512901(j), 0051293f(j)
//                              tplayer.cpp:729 (45)
//         00512944     PUSH       0x38
//         00512946     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051294b     ADD        ESP,0x4
//         0051294e     MOV        dword ptr [ESP + local_10],EAX
//         00512952     TEST       EAX,EAX
//         00512954     MOV        dword ptr [ESP + local_4],0x0
//         0051295c     JZ         LAB_0051296c
//         0051295e     MOV        EDX,dword ptr [ESI + 0x3c]
//         00512961     MOV        this,EAX
//         00512963     PUSH       EDX
//         00512964     PUSH       EBX
//         00512965     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         0051296a     JMP        LAB_0051296e
//                               LAB_0051296c                                                 XREF[1]:     0051295c(j)
//         0051296c     XOR        EAX,EAX
//                               LAB_0051296e                                                 XREF[1]:     0051296a(j)
//         0051296e     OR         EBP,0xffffffff
//                              tplayer.cpp:730 (46)
//         00512971     PUSH       0x14
//         00512973     MOV        dword ptr [ESP + local_4],EBP
//         00512977     MOV        dword ptr [ESI + 0x38],EAX
//         0051297a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051297f     ADD        ESP,0x4
//         00512982     MOV        dword ptr [ESP + local_10],EAX
//         00512986     TEST       EAX,EAX
//         00512988     MOV        dword ptr [ESP + local_4],0x1
//         00512990     JZ         LAB_0051299d
//         00512992     PUSH       ESI
//         00512993     PUSH       EBX
//         00512994     MOV        this,EAX
//         00512996     CALL       Visible_Resource_Manager::Visible_Resource_Man   undefined Visible_Resource_Manager(Visible_Re
//         0051299b     JMP        LAB_0051299f
//                               LAB_0051299d                                                 XREF[1]:     00512990(j)
//         0051299d     XOR        EAX,EAX
//                               LAB_0051299f                                                 XREF[1]:     0051299b(j)
//                              tplayer.cpp:731 (55)
//         0051299f     PUSH       0xc
//         005129a1     MOV        dword ptr [ESP + local_4],EBP
//         005129a5     MOV        dword ptr [ESI + 0x110],EAX
//         005129ab     CALL       operator_new                                     void * operator_new(uint param_1)
//         005129b0     MOV        EDI,EAX
//         005129b2     ADD        ESP,0x4
//         005129b5     MOV        dword ptr [ESP + local_10],EDI
//         005129b9     TEST       EDI,EDI
//         005129bb     MOV        dword ptr [ESP + local_4],0x2
//         005129c3     JZ         LAB_005129d4
//         005129c5     MOV        this,EDI
//         005129c7     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         005129cc     MOV        dword ptr [EDI],TRIBE_Object_List::`vftable'     = 00511b00
//         005129d2     JMP        LAB_005129d6
//                               LAB_005129d4                                                 XREF[1]:     005129c3(j)
//         005129d4     XOR        EDI,EDI
//                               LAB_005129d6                                                 XREF[1]:     005129d2(j)
//                              tplayer.cpp:732 (19)
//         005129d6     MOV        EAX,dword ptr [ESI + 0x3c]
//         005129d9     MOV        this,EDI
//         005129db     PUSH       EAX
//         005129dc     PUSH       EBX
//         005129dd     MOV        dword ptr [ESP + local_4],EBP
//         005129e1     MOV        dword ptr [ESI + 0x28],EDI
//         005129e4     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                              tplayer.cpp:733 (47)
//         005129e9     PUSH       0xc
//         005129eb     CALL       operator_new                                     void * operator_new(uint param_1)
//         005129f0     MOV        EDI,EAX
//         005129f2     ADD        ESP,0x4
//         005129f5     MOV        dword ptr [ESP + local_10],EDI
//         005129f9     TEST       EDI,EDI
//         005129fb     MOV        dword ptr [ESP + local_4],0x3
//         00512a03     JZ         LAB_00512a16
//         00512a05     MOV        this,EDI
//         00512a07     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         00512a0c     MOV        dword ptr [EDI],TRIBE_Object_List::`vftable'     = 00511b00
//         00512a12     MOV        this,EDI
//         00512a14     JMP        LAB_00512a18
//                               LAB_00512a16                                                 XREF[1]:     00512a03(j)
//         00512a16     XOR        this,this
//                               LAB_00512a18                                                 XREF[1]:     00512a14(j)
//                              tplayer.cpp:734 (17)
//         00512a18     MOV        EDX,dword ptr [ESI + 0x3c]
//         00512a1b     MOV        dword ptr [ESP + local_4],EBP
//         00512a1f     PUSH       EDX
//         00512a20     PUSH       EBX
//         00512a21     MOV        dword ptr [ESI + 0x2c],this
//         00512a24     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                              tplayer.cpp:736 (46)
//         00512a29     PUSH       0xc
//         00512a2b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00512a30     ADD        ESP,0x4
//         00512a33     MOV        dword ptr [ESP + local_10],EAX
//         00512a37     TEST       EAX,EAX
//         00512a39     MOV        dword ptr [ESP + local_4],0x4
//         00512a41     JZ         LAB_00512a4e
//         00512a43     MOV        this,EAX
//         00512a45     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         00512a4a     MOV        this,EAX
//         00512a4c     JMP        LAB_00512a50
//                               LAB_00512a4e                                                 XREF[1]:     00512a41(j)
//         00512a4e     XOR        this,this
//                               LAB_00512a50                                                 XREF[1]:     00512a4c(j)
//         00512a50     MOV        dword ptr [ESI + 0x30],this
//         00512a53     MOV        dword ptr [ESP + local_4],EBP
//                              tplayer.cpp:737 (19)
//         00512a57     FLD        float ptr [save_game_version]                    = 7.23
//         00512a5d     FCOMP      float ptr [DAT_00576858]                         = 48h    H
//         00512a63     FNSTSW     AX
//         00512a65     TEST       AH,0x1
//         00512a68     JNZ        LAB_00512a74
//                              tplayer.cpp:738 (10)
//         00512a6a     MOV        EAX,dword ptr [ESI + 0x3c]
//         00512a6d     PUSH       EAX
//         00512a6e     PUSH       EBX
//         00512a6f     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                               LAB_00512a74                                                 XREF[1]:     00512a68(j)
//                              tplayer.cpp:741 (21)
//         00512a74     MOV        this,dword ptr [ESP + local_c]
//         00512a78     POP        EDI
//         00512a79     POP        ESI
//         00512a7a     POP        EBP
//         00512a7b     MOV        dword ptr FS:[0x0],this
//         00512a82     POP        EBX
//         00512a83     ADD        ESP,0x10
//         00512a86     RET        0x4
//         00512a89     ??         90h
//         00512a8a     NOP
//         00512a8b     NOP
//         00512a8c     NOP
//         00512a8d     NOP
//         00512a8e     NOP
//         00512a8f     NOP
    return;
}

void TRIBE_Player::load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5) {
    /* TODO: Stub */
//                              void __thiscall load_master_object(TRIBE_Player * this, int param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00512ac5(R), 00512b16(R), 00512b50(R), 00512bc1(R)
//              short             Stack[0x8]:2   param_2                   XREF[4]:     00512acb(R), 00512b5d(R), 00512b7a(R), 00512bd2(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[4]:     00512a9e(R), 00512af7(W), 00512b35(W), 00512ba6(W)
//              RGE_Sprite * *    Stack[0x10]:4  param_4                   XREF[4]:     00512ac0(R), 00512b0f(R), 00512b49(R), 00512bba(R)
//              RGE_Sound * *     Stack[0x14]:4  param_5                   XREF[4]:     00512abc(R), 00512b0b(R), 00512b45(R), 00512bb6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00512afd(W), 00512b3b(W), 00512bac(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00512ad8(R), 00512b68(R), 00512b87(R), 00512bde(*)
//                               ?load_master_object@TRIBE_Player@@QAEXHFEPAPAVRGE_Sprite@@P  XREF[2]:     load:00512933(c),
//                               TRIBE_Player::load_master_object                                          load_master_object:00519d29(c)
//                              tplayer.cpp:746 (14)
//         00512a90     MOV        EAX,FS:[0x0]
//         00512a96     PUSH       -0x1
//         00512a98     PUSH       FUN_00561281
//         00512a9d     PUSH       EAX
//                              tplayer.cpp:747 (30)
//         00512a9e     MOV        EAX,dword ptr [ESP + param_3]
//         00512aa2     MOV        dword ptr FS:[0x0],ESP
//         00512aa9     PUSH       ESI
//         00512aaa     CMP        AL,0x46
//         00512aac     MOV        ESI,this
//         00512aae     JZ         LAB_00512b99
//         00512ab4     CMP        AL,0x50
//         00512ab6     JZ         LAB_00512b28
//         00512ab8     CMP        AL,0x5a
//         00512aba     JZ         LAB_00512aea
//                              tplayer.cpp:760 (28)
//         00512abc     MOV        this,dword ptr [ESP + param_5]
//         00512ac0     MOV        EDX,dword ptr [ESP + param_4]
//         00512ac4     PUSH       this
//         00512ac5     MOV        this,dword ptr [ESP + param_1]
//         00512ac9     PUSH       EDX
//         00512aca     PUSH       EAX
//         00512acb     MOV        EAX,dword ptr [ESP + param_2]
//         00512acf     PUSH       EAX
//         00512ad0     PUSH       this
//         00512ad1     MOV        this,ESI
//         00512ad3     CALL       RGE_Player::load_master_object                   void load_master_object(RGE_Player * this, in
//                              tplayer.cpp:763 (18)
//         00512ad8     MOV        this,dword ptr [ESP + local_c]
//         00512adc     MOV        dword ptr FS:[0x0],this
//         00512ae3     POP        ESI
//         00512ae4     ADD        ESP,0xc
//         00512ae7     RET        0x14
//                               LAB_00512aea                                                 XREF[1]:     00512aba(j)
//                              tplayer.cpp:756 (57)
//         00512aea     PUSH       0xb8
//         00512aef     CALL       operator_new                                     void * operator_new(uint param_1)
//         00512af4     ADD        ESP,0x4
//         00512af7     MOV        dword ptr [ESP + param_3],EAX
//         00512afb     TEST       EAX,EAX
//         00512afd     MOV        dword ptr [ESP + local_4],0x2
//         00512b05     JZ         LAB_00512bd0
//         00512b0b     MOV        EDX,dword ptr [ESP + param_5]
//         00512b0f     MOV        this,dword ptr [ESP + param_4]
//         00512b13     PUSH       0x1
//         00512b15     PUSH       EDX
//         00512b16     MOV        EDX,dword ptr [ESP + param_1]
//         00512b1a     PUSH       this
//         00512b1b     PUSH       EDX
//         00512b1c     MOV        this,EAX
//         00512b1e     CALL       TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Ob   undefined TRIBE_Master_Tree_Object(TRIBE_Mast
//                              tplayer.cpp:757 (5)
//         00512b23     JMP        LAB_00512bd2
//                               LAB_00512b28                                                 XREF[1]:     00512ab6(j)
//                              tplayer.cpp:753 (64)
//         00512b28     PUSH       0x17c
//         00512b2d     CALL       operator_new                                     void * operator_new(uint param_1)
//         00512b32     ADD        ESP,0x4
//         00512b35     MOV        dword ptr [ESP + param_3],EAX
//         00512b39     TEST       EAX,EAX
//         00512b3b     MOV        dword ptr [ESP + local_4],0x1
//         00512b43     JZ         LAB_00512b7a
//         00512b45     MOV        this,dword ptr [ESP + param_5]
//         00512b49     MOV        EDX,dword ptr [ESP + param_4]
//         00512b4d     PUSH       0x1
//         00512b4f     PUSH       this
//         00512b50     MOV        this,dword ptr [ESP + param_1]
//         00512b54     PUSH       EDX
//         00512b55     PUSH       this
//         00512b56     MOV        this,EAX
//         00512b58     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
//         00512b5d     MOVSX      EDX,word ptr [ESP + param_2]
//         00512b62     MOV        this,dword ptr [ESI + 0x24]
//         00512b65     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              tplayer.cpp:763 (18)
//         00512b68     MOV        this,dword ptr [ESP + local_c]
//         00512b6c     MOV        dword ptr FS:[0x0],this
//         00512b73     POP        ESI
//         00512b74     ADD        ESP,0xc
//         00512b77     RET        0x14
//                               LAB_00512b7a                                                 XREF[1]:     00512b43(j)
//                              tplayer.cpp:753 (13)
//         00512b7a     MOVSX      EDX,word ptr [ESP + param_2]
//         00512b7f     MOV        this,dword ptr [ESI + 0x24]
//         00512b82     XOR        EAX,EAX
//         00512b84     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              tplayer.cpp:763 (18)
//         00512b87     MOV        this,dword ptr [ESP + local_c]
//         00512b8b     MOV        dword ptr FS:[0x0],this
//         00512b92     POP        ESI
//         00512b93     ADD        ESP,0xc
//         00512b96     RET        0x14
//                               LAB_00512b99                                                 XREF[1]:     00512aae(j)
//                              tplayer.cpp:750 (65)
//         00512b99     PUSH       0x164
//         00512b9e     CALL       operator_new                                     void * operator_new(uint param_1)
//         00512ba3     ADD        ESP,0x4
//         00512ba6     MOV        dword ptr [ESP + param_3],EAX
//         00512baa     TEST       EAX,EAX
//         00512bac     MOV        dword ptr [ESP + local_4],0x0
//         00512bb4     JZ         LAB_00512bd0
//         00512bb6     MOV        EDX,dword ptr [ESP + param_5]
//         00512bba     MOV        this,dword ptr [ESP + param_4]
//         00512bbe     PUSH       0x1
//         00512bc0     PUSH       EDX
//         00512bc1     MOV        EDX,dword ptr [ESP + param_1]
//         00512bc5     PUSH       this
//         00512bc6     PUSH       EDX
//         00512bc7     MOV        this,EAX
//         00512bc9     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
//         00512bce     JMP        LAB_00512bd2
//                               LAB_00512bd0                                                 XREF[2]:     00512b05(j), 00512bb4(j)
//         00512bd0     XOR        EAX,EAX
//                               LAB_00512bd2                                                 XREF[2]:     00512b23(j), 00512bce(j)
//         00512bd2     MOVSX      this,word ptr [ESP + param_2]
//         00512bd7     MOV        EDX,dword ptr [ESI + 0x24]
//                              tplayer.cpp:763 (21)
//         00512bda     POP        ESI
//         00512bdb     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
//         00512bde     MOV        this,dword ptr [ESP]=>local_c
//         00512be2     MOV        dword ptr FS:[0x0],this
//         00512be9     ADD        ESP,0xc
//         00512bec     RET        0x14
//         00512bef     ??         90h
    return;
}

void TRIBE_Player::tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7) {
    /* TODO: Stub */
//                              void __thiscall tech_cost(TRIBE_Player * this, short param_1, short
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00512c13(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00512c0e(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     00512c09(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     00512c04(R)
//              short *           Stack[0x14]:4  param_5                   XREF[1]:     00512bf9(R)
//              short *           Stack[0x18]:4  param_6                   XREF[1]:     00512bf4(R)
//              short *           Stack[0x1c]:4  param_7                   XREF[1]:     00512bf0(R)
//                               ?tech_cost@TRIBE_Player@@QAEXFAAF00000@Z
//                               TRIBE_Player::tech_cost
//                              tplayer.cpp:767 (46)
//         00512bf0     MOV        EAX,dword ptr [ESP + param_7]
//         00512bf4     MOV        EDX,dword ptr [ESP + param_6]
//         00512bf8     PUSH       EAX
//         00512bf9     MOV        EAX,dword ptr [ESP + param_5]
//         00512bfd     MOV        this,dword ptr [ECX + this->tech_tree]
//         00512c03     PUSH       EDX
//         00512c04     MOV        EDX,dword ptr [ESP + param_4]
//         00512c08     PUSH       EAX
//         00512c09     MOV        EAX,dword ptr [ESP + param_3]
//         00512c0d     PUSH       EDX
//         00512c0e     MOV        EDX,dword ptr [ESP + param_2]
//         00512c12     PUSH       EAX
//         00512c13     MOV        EAX,dword ptr [ESP + param_1]
//         00512c17     PUSH       EDX
//         00512c18     PUSH       EAX
//         00512c19     CALL       TRIBE_Player_Tech::tech_cost                     void tech_cost(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:769 (3)
//         00512c1e     RET        0x1c
//         00512c21     ??         90h
//         00512c22     NOP
//         00512c23     NOP
//         00512c24     NOP
//         00512c25     NOP
//         00512c26     NOP
//         00512c27     NOP
//         00512c28     NOP
//         00512c29     NOP
//         00512c2a     NOP
//         00512c2b     NOP
//         00512c2c     NOP
//         00512c2d     NOP
//         00512c2e     NOP
//         00512c2f     NOP
    return;
}

void TRIBE_Player::obj_cost(short param_1, char** param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8, float param_9) {
    /* TODO: Stub */
//                              void __thiscall obj_cost(TRIBE_Player * this, short param_1, char *
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[5]:     00512c46(R), 00512c7f(W), 00512d08(R), 00512d86(R),
//                                                                                     00512dfe(R)
//              char * *          Stack[0x8]:4   param_2                   XREF[9]:     00512c9b(R), 00512ccc(W), 00512cd0(R), 00512cf4(W),
//                                                                                     00512cfb(R), 00512d4a(W), 00512d4e(R), 00512d72(W),
//                                                                                     00512d79(R)
//              short *           Stack[0xc]:4   param_3                   XREF[4]:     00512c30(R), 00512cb9(R), 00512ce1(R), 00512e18(R)
//              short *           Stack[0x10]:4  param_4                   XREF[5]:     00512c42(R), 00512cdd(R), 00512d17(R), 00512e6d(R),
//                                                                                     00512e79(R)
//              short *           Stack[0x14]:4  param_5                   XREF[5]:     00512c34(R), 00512d37(R), 00512d5f(R), 00512e30(R),
//                                                                                     00512e92(R)
//              short *           Stack[0x18]:4  param_6                   XREF[5]:     00512c51(R), 00512d5b(R), 00512d95(R), 00512e62(R),
//                                                                                     00512e88(R)
//              short *           Stack[0x1c]:4  param_7                   XREF[7]:     00512c3a(R), 00512d22(R), 00512da0(R), 00512dc5(W),
//                                                                                     00512dc9(R), 00512dea(W), 00512df1(R)
//              short *           Stack[0x20]:4  param_8                   XREF[5]:     00512c58(R), 00512dd9(R), 00512e0d(R), 00512e53(R),
//                                                                                     00512e9b(R)
//              float             Stack[0x24]:4  param_9                   XREF[3]:     00512cd4(R), 00512d52(R), 00512dcd(R)
//                               ?obj_cost@TRIBE_Player@@QAEXFPAPADAAF11111M@Z                XREF[4]:     interface_item_avail:00513342(c),
//                               TRIBE_Player::obj_cost                                                    interface_item_avail:00513450(c),
//                                                                                                         objectCost:0051453e(c),
//                                                                                                         objectCostByType:005145bd(c)
//                              tplayer.cpp:775 (4)
//         00512c30     MOV        EAX,dword ptr [ESP + param_3]
//                              tplayer.cpp:782 (6)
//         00512c34     MOV        EDX,dword ptr [ESP + param_5]
//         00512c38     PUSH       EBX
//         00512c39     PUSH       EBP
//                              tplayer.cpp:784 (12)
//         00512c3a     MOV        EBP,dword ptr [ESP + param_7]
//         00512c3e     PUSH       ESI
//         00512c3f     PUSH       EDI
//         00512c40     MOV        EDI,this
//         00512c42     MOV        this,dword ptr [ESP + param_4]
//                              tplayer.cpp:787 (54)
//         00512c46     MOV        ESI,dword ptr [ESP + param_1]
//         00512c4a     XOR        EBX,EBX
//         00512c4c     MOV        word ptr [EAX],0xffff
//         00512c51     MOV        EAX,dword ptr [ESP + param_6]
//         00512c55     MOV        word ptr [this->_padding_],BX
//         00512c58     MOV        this,dword ptr [ESP + param_8]
//         00512c5c     MOV        word ptr [EDX],0xffff
//         00512c61     MOV        word ptr [EAX],BX
//         00512c64     PUSH       EBX
//         00512c65     MOV        word ptr [EBP],0xffff
//         00512c6b     PUSH       0x3f800000
//         00512c70     MOV        word ptr [this->_padding_],BX
//         00512c73     PUSH       EBX
//         00512c74     PUSH       ESI
//         00512c75     MOV        this,EDI
//         00512c77     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
//                              tplayer.cpp:789 (31)
//         00512c7c     MOVSX      EDX,SI
//         00512c7f     MOV        byte ptr [ESP + param_1],AL
//         00512c83     MOV        EAX,dword ptr [EDI + 0x24]
//         00512c86     MOV        ESI,dword ptr [EAX + EDX*0x4]
//         00512c89     TEST       ESI,ESI
//         00512c8b     JZ         LAB_00512eab
//         00512c91     CMP        byte ptr [ESI + 0x4],0x46
//         00512c95     JC         LAB_00512eab
//                              tplayer.cpp:792 (8)
//         00512c9b     MOV        EAX,dword ptr [ESP + param_2]
//         00512c9f     TEST       EAX,EAX
//         00512ca1     JZ         LAB_00512ca8
//                              tplayer.cpp:793 (5)
//         00512ca3     MOV        this,dword ptr [ESI + 0x8]
//         00512ca6     MOV        dword ptr [EAX],this
//                               LAB_00512ca8                                                 XREF[1]:     00512ca1(j)
//                              tplayer.cpp:795 (10)
//         00512ca8     MOV        AL,byte ptr [ESI + 0x14c]
//         00512cae     TEST       AL,AL
//         00512cb0     JZ         LAB_00512d26
//                              tplayer.cpp:797 (11)
//         00512cb2     MOV        AX,word ptr [ESI + 0x148]
//         00512cb9     MOV        EDX,dword ptr [ESP + param_3]
//                              tplayer.cpp:798 (8)
//         00512cbd     TEST       AX,AX
//         00512cc0     MOV        word ptr [EDX],AX
//         00512cc3     JL         LAB_00512d26
//                              tplayer.cpp:800 (28)
//         00512cc5     MOVSX      EAX,word ptr [ESI + 0x14a]
//         00512ccc     MOV        dword ptr [ESP + param_2],EAX
//         00512cd0     FILD       dword ptr [ESP + param_2]
//         00512cd4     FMUL       float ptr [ESP + param_9]
//         00512cd8     CALL       __ftol                                           undefined __ftol()
//         00512cdd     MOV        this,dword ptr [ESP + param_4]
//                              tplayer.cpp:801 (47)
//         00512ce1     MOV        EDX,dword ptr [ESP + param_3]
//         00512ce5     MOV        BP,AX
//         00512ce8     MOV        word ptr [this->_padding_],BP
//         00512ceb     MOV        this,dword ptr [EDI + 0x50]
//         00512cee     MOVSX      EAX,word ptr [EDX]
//         00512cf1     MOVSX      EDX,BP
//         00512cf4     MOV        dword ptr [ESP + param_2],EDX
//         00512cf8     LEA        this,[this->_padding_ + EAX*0x4]
//         00512cfb     FILD       dword ptr [ESP + param_2]
//         00512cff     FCOMP      float ptr [this->_padding_]
//         00512d01     FNSTSW     AX
//         00512d03     TEST       AH,0x41
//         00512d06     JNZ        LAB_00512d22
//         00512d08     MOV        AL,byte ptr [ESP + param_1]
//         00512d0c     TEST       AL,AL
//         00512d0e     JZ         LAB_00512d22
//                              tplayer.cpp:803 (7)
//         00512d10     FLD        float ptr [this->_padding_]
//         00512d12     CALL       __ftol                                           undefined __ftol()
//                              tplayer.cpp:804 (15)
//         00512d17     MOV        this,dword ptr [ESP + param_4]
//         00512d1b     SUB        EBP,EAX
//         00512d1d     MOV        EBX,EBP
//         00512d1f     MOV        word ptr [this->_padding_],AX
//                               LAB_00512d22                                                 XREF[2]:     00512d06(j), 00512d0e(j)
//         00512d22     MOV        EBP,dword ptr [ESP + param_7]
//                               LAB_00512d26                                                 XREF[2]:     00512cb0(j), 00512cc3(j)
//                              tplayer.cpp:809 (10)
//         00512d26     MOV        AL,byte ptr [ESI + 0x152]
//         00512d2c     TEST       AL,AL
//         00512d2e     JZ         LAB_00512da4
//                              tplayer.cpp:811 (11)
//         00512d30     MOV        AX,word ptr [ESI + 0x14e]
//         00512d37     MOV        EDX,dword ptr [ESP + param_5]
//                              tplayer.cpp:812 (8)
//         00512d3b     TEST       AX,AX
//         00512d3e     MOV        word ptr [EDX],AX
//         00512d41     JL         LAB_00512da4
//                              tplayer.cpp:814 (28)
//         00512d43     MOVSX      EAX,word ptr [ESI + 0x150]
//         00512d4a     MOV        dword ptr [ESP + param_2],EAX
//         00512d4e     FILD       dword ptr [ESP + param_2]
//         00512d52     FMUL       float ptr [ESP + param_9]
//         00512d56     CALL       __ftol                                           undefined __ftol()
//         00512d5b     MOV        this,dword ptr [ESP + param_6]
//                              tplayer.cpp:815 (47)
//         00512d5f     MOV        EDX,dword ptr [ESP + param_5]
//         00512d63     MOV        BP,AX
//         00512d66     MOV        word ptr [this->_padding_],BP
//         00512d69     MOV        this,dword ptr [EDI + 0x50]
//         00512d6c     MOVSX      EAX,word ptr [EDX]
//         00512d6f     MOVSX      EDX,BP
//         00512d72     MOV        dword ptr [ESP + param_2],EDX
//         00512d76     LEA        this,[this->_padding_ + EAX*0x4]
//         00512d79     FILD       dword ptr [ESP + param_2]
//         00512d7d     FCOMP      float ptr [this->_padding_]
//         00512d7f     FNSTSW     AX
//         00512d81     TEST       AH,0x41
//         00512d84     JNZ        LAB_00512da0
//         00512d86     MOV        AL,byte ptr [ESP + param_1]
//         00512d8a     TEST       AL,AL
//         00512d8c     JZ         LAB_00512da0
//                              tplayer.cpp:817 (7)
//         00512d8e     FLD        float ptr [this->_padding_]
//         00512d90     CALL       __ftol                                           undefined __ftol()
//                              tplayer.cpp:818 (15)
//         00512d95     MOV        this,dword ptr [ESP + param_6]
//         00512d99     SUB        EBP,EAX
//         00512d9b     ADD        EBX,EBP
//         00512d9d     MOV        word ptr [this->_padding_],AX
//                               LAB_00512da0                                                 XREF[2]:     00512d84(j), 00512d8c(j)
//         00512da0     MOV        EBP,dword ptr [ESP + param_7]
//                               LAB_00512da4                                                 XREF[2]:     00512d2e(j), 00512d41(j)
//                              tplayer.cpp:823 (10)
//         00512da4     MOV        AL,byte ptr [ESI + 0x158]
//         00512daa     TEST       AL,AL
//         00512dac     JZ         LAB_00512e18
//                              tplayer.cpp:825 (7)
//         00512dae     MOV        AX,word ptr [ESI + 0x154]
//                              tplayer.cpp:826 (9)
//         00512db5     TEST       AX,AX
//         00512db8     MOV        word ptr [EBP],AX
//         00512dbc     JL         LAB_00512e18
//                              tplayer.cpp:828 (34)
//         00512dbe     MOVSX      EDX,word ptr [ESI + 0x156]
//         00512dc5     MOV        dword ptr [ESP + param_7],EDX
//         00512dc9     FILD       dword ptr [ESP + param_7]
//         00512dcd     FMUL       float ptr [ESP + param_9]
//         00512dd1     CALL       __ftol                                           undefined __ftol()
//         00512dd6     MOV        SI,AX
//         00512dd9     MOV        EAX,dword ptr [ESP + param_8]
//         00512ddd     MOV        word ptr [EAX],SI
//                              tplayer.cpp:829 (38)
//         00512de0     MOV        EDX,dword ptr [EDI + 0x50]
//         00512de3     MOVSX      this,word ptr [EBP]
//         00512de7     MOVSX      EAX,SI
//         00512dea     MOV        dword ptr [ESP + param_7],EAX
//         00512dee     LEA        this,[EDX + this->_padding_*0x4]
//         00512df1     FILD       dword ptr [ESP + param_7]
//         00512df5     FCOMP      float ptr [this->_padding_]
//         00512df7     FNSTSW     AX
//         00512df9     TEST       AH,0x41
//         00512dfc     JNZ        LAB_00512e18
//         00512dfe     MOV        AL,byte ptr [ESP + param_1]
//         00512e02     TEST       AL,AL
//         00512e04     JZ         LAB_00512e18
//                              tplayer.cpp:831 (7)
//         00512e06     FLD        float ptr [this->_padding_]
//         00512e08     CALL       __ftol                                           undefined __ftol()
//                              tplayer.cpp:832 (11)
//         00512e0d     MOV        this,dword ptr [ESP + param_8]
//         00512e11     SUB        ESI,EAX
//         00512e13     ADD        EBX,ESI
//         00512e15     MOV        word ptr [this->_padding_],AX
//                               LAB_00512e18                                                 XREF[4]:     00512dac(j), 00512dbc(j),
//                                                                                                         00512dfc(j), 00512e04(j)
//                              tplayer.cpp:839 (24)
//         00512e18     MOV        this,dword ptr [ESP + param_3]
//         00512e1c     TEST       BX,BX
//         00512e1f     JLE        LAB_00512e79
//         00512e21     MOV        AX,word ptr [this->_padding_]
//         00512e24     CMP        AX,0x3
//         00512e28     JZ         LAB_00512e6d
//         00512e2a     CMP        AX,0xffff
//         00512e2e     JZ         LAB_00512e6d
//                              tplayer.cpp:844 (19)
//         00512e30     MOV        EDX,dword ptr [ESP + param_5]
//         00512e34     MOV        AX,word ptr [EDX]
//         00512e37     CMP        AX,0x3
//         00512e3b     JZ         LAB_00512e62
//         00512e3d     CMP        AX,0xffff
//         00512e41     JZ         LAB_00512e62
//                              tplayer.cpp:849 (16)
//         00512e43     MOV        AX,word ptr [EBP]
//         00512e47     CMP        AX,0x3
//         00512e4b     JZ         LAB_00512e53
//         00512e4d     CMP        AX,0xffff
//         00512e51     JNZ        LAB_00512e79
//                               LAB_00512e53                                                 XREF[1]:     00512e4b(j)
//                              tplayer.cpp:852 (13)
//         00512e53     MOV        EDX,dword ptr [ESP + param_8]
//         00512e57     MOV        word ptr [EBP],0x3
//         00512e5d     MOV        word ptr [EDX],BX
//                              tplayer.cpp:854 (2)
//         00512e60     JMP        LAB_00512e79
//                               LAB_00512e62                                                 XREF[2]:     00512e3b(j), 00512e41(j)
//                              tplayer.cpp:847 (9)
//         00512e62     MOV        EAX,dword ptr [ESP + param_6]
//         00512e66     MOV        word ptr [EDX],0x3
//                              tplayer.cpp:849 (2)
//         00512e6b     JMP        LAB_00512e76
//                               LAB_00512e6d                                                 XREF[2]:     00512e28(j), 00512e2e(j)
//                              tplayer.cpp:842 (12)
//         00512e6d     MOV        EAX,dword ptr [ESP + param_4]
//         00512e71     MOV        word ptr [this->_padding_],0x3
//                               LAB_00512e76                                                 XREF[1]:     00512e6b(j)
//         00512e76     ADD        word ptr [EAX],BX
//                               LAB_00512e79                                                 XREF[3]:     00512e1f(j), 00512e51(j),
//                                                                                                         00512e60(j)
//                              tplayer.cpp:860 (10)
//         00512e79     MOV        EAX,dword ptr [ESP + param_4]
//         00512e7d     CMP        word ptr [EAX],0x0
//         00512e81     JG         LAB_00512e88
//                              tplayer.cpp:861 (5)
//         00512e83     MOV        word ptr [this->_padding_],0xffff
//                               LAB_00512e88                                                 XREF[1]:     00512e81(j)
//                              tplayer.cpp:862 (10)
//         00512e88     MOV        this,dword ptr [ESP + param_6]
//         00512e8c     CMP        word ptr [this->_padding_],0x0
//         00512e90     JG         LAB_00512e9b
//                              tplayer.cpp:863 (9)
//         00512e92     MOV        EDX,dword ptr [ESP + param_5]
//         00512e96     MOV        word ptr [EDX],0xffff
//                               LAB_00512e9b                                                 XREF[1]:     00512e90(j)
//                              tplayer.cpp:864 (10)
//         00512e9b     MOV        EAX,dword ptr [ESP + param_8]
//         00512e9f     CMP        word ptr [EAX],0x0
//         00512ea3     JG         LAB_00512eab
//                              tplayer.cpp:865 (6)
//         00512ea5     MOV        word ptr [EBP],0xffff
//                               LAB_00512eab                                                 XREF[3]:     00512c8b(j), 00512c95(j),
//                                                                                                         00512ea3(j)
//                              tplayer.cpp:867 (7)
//         00512eab     POP        EDI
//         00512eac     POP        ESI
//         00512ead     POP        EBP
//         00512eae     POP        EBX
//         00512eaf     RET        0x24
//         00512eb2     ??         90h
//         00512eb3     NOP
//         00512eb4     NOP
//         00512eb5     NOP
//         00512eb6     NOP
//         00512eb7     NOP
//         00512eb8     NOP
//         00512eb9     NOP
//         00512eba     NOP
//         00512ebb     NOP
//         00512ebc     NOP
//         00512ebd     NOP
//         00512ebe     NOP
//         00512ebf     NOP
    return;
}

RGE_Static_Object* TRIBE_Player::find_obj(short param_1, RGE_Static_Object* param_2) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall find_obj(TRIBE_Player * this, short p
//              RGE_Static_Obj    EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00512ec1(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00512ec9(R)
//                               ?find_obj@TRIBE_Player@@QAEPAVRGE_Static_Object@@FPAV2@@Z    XREF[2]:     command_select_building:0049cd63(c
//                               TRIBE_Player::find_obj                                                    command_view_tribe:0049d127(c)
//                              tplayer.cpp:871 (1)
//         00512ec0     PUSH       EBX
//                              tplayer.cpp:875 (16)
//         00512ec1     MOV        BX,word ptr [ESP + param_1]
//         00512ec6     PUSH       EBP
//         00512ec7     PUSH       ESI
//         00512ec8     PUSH       EDI
//         00512ec9     MOV        EDI,dword ptr [ESP + param_2]
//         00512ecd     TEST       EDI,EDI
//         00512ecf     JZ         LAB_00512f08
//                              tplayer.cpp:878 (12)
//         00512ed1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00512ed4     XOR        ESI,ESI
//         00512ed6     MOV        EDX,dword ptr [EAX + 0x4]
//         00512ed9     TEST       EDX,EDX
//         00512edb     JZ         LAB_00512f08
//                               LAB_00512edd                                                 XREF[1]:     00512f06(j)
//                              tplayer.cpp:880 (6)
//         00512edd     MOV        EAX,dword ptr [EDX]
//         00512edf     TEST       EAX,EAX
//         00512ee1     JZ         LAB_00512f01
//                              tplayer.cpp:882 (4)
//         00512ee3     TEST       ESI,ESI
//         00512ee5     JZ         LAB_00512ef8
//                              tplayer.cpp:884 (15)
//         00512ee7     MOV        EBP,dword ptr [EAX + 0x8]
//         00512eea     CMP        word ptr [EBP + 0x10],BX
//         00512eee     JNZ        LAB_00512f01
//         00512ef0     CMP        byte ptr [EAX + 0x48],0x2
//         00512ef4     JBE        LAB_00512f49
//                              tplayer.cpp:887 (2)
//         00512ef6     JMP        LAB_00512f01
//                               LAB_00512ef8                                                 XREF[1]:     00512ee5(j)
//                              tplayer.cpp:889 (4)
//         00512ef8     CMP        EAX,EDI
//         00512efa     JNZ        LAB_00512f01
//                              tplayer.cpp:890 (5)
//         00512efc     MOV        ESI,0x1
//                               LAB_00512f01                                                 XREF[4]:     00512ee1(j), 00512eee(j),
//                                                                                                         00512ef6(j), 00512efa(j)
//                              tplayer.cpp:878 (7)
//         00512f01     MOV        EDX,dword ptr [EDX + 0x4]
//         00512f04     TEST       EDX,EDX
//         00512f06     JNZ        LAB_00512edd
//                               LAB_00512f08                                                 XREF[2]:     00512ecf(j), 00512edb(j)
//                              tplayer.cpp:896 (10)
//         00512f08     MOV        this,dword ptr [ECX + this->_padding_]
//         00512f0b     MOV        this,dword ptr [ECX + this->_padding_]
//         00512f0e     TEST       this,this
//         00512f10     JZ         LAB_00512f40
//                               LAB_00512f12                                                 XREF[1]:     00512f2c(j)
//                              tplayer.cpp:897 (21)
//         00512f12     MOV        EAX,dword ptr [this->_padding_]
//         00512f14     TEST       EAX,EAX
//         00512f16     JZ         LAB_00512f27
//         00512f18     MOV        EDX,dword ptr [EAX + 0x8]
//         00512f1b     CMP        word ptr [EDX + 0x10],BX
//         00512f1f     JNZ        LAB_00512f27
//         00512f21     CMP        byte ptr [EAX + 0x48],0x2
//         00512f25     JZ         LAB_00512f37
//                               LAB_00512f27                                                 XREF[2]:     00512f16(j), 00512f1f(j)
//                              tplayer.cpp:896 (7)
//         00512f27     MOV        this,dword ptr [ECX + this->_padding_]
//         00512f2a     TEST       this,this
//         00512f2c     JNZ        LAB_00512f12
//                              tplayer.cpp:900 (2)
//         00512f2e     XOR        EAX,EAX
//                              tplayer.cpp:901 (7)
//         00512f30     POP        EDI
//         00512f31     POP        ESI
//         00512f32     POP        EBP
//         00512f33     POP        EBX
//         00512f34     RET        0x8
//                               LAB_00512f37                                                 XREF[1]:     00512f25(j)
//                              tplayer.cpp:898 (2)
//         00512f37     MOV        EAX,dword ptr [this->_padding_]
//                              tplayer.cpp:901 (7)
//         00512f39     POP        EDI
//         00512f3a     POP        ESI
//         00512f3b     POP        EBP
//         00512f3c     POP        EBX
//         00512f3d     RET        0x8
//                               LAB_00512f40                                                 XREF[1]:     00512f10(j)
//                              tplayer.cpp:900 (2)
//         00512f40     XOR        EAX,EAX
//                              tplayer.cpp:901 (7)
//         00512f42     POP        EDI
//         00512f43     POP        ESI
//         00512f44     POP        EBP
//         00512f45     POP        EBX
//         00512f46     RET        0x8
//                               LAB_00512f49                                                 XREF[1]:     00512ef4(j)
//                              tplayer.cpp:885 (2)
//         00512f49     MOV        EAX,dword ptr [EDX]
//                              tplayer.cpp:901 (7)
//         00512f4b     POP        EDI
//         00512f4c     POP        ESI
//         00512f4d     POP        EBP
//         00512f4e     POP        EBX
//         00512f4f     RET        0x8
//         00512f52     ??         90h
//         00512f53     NOP
//         00512f54     NOP
//         00512f55     NOP
//         00512f56     NOP
//         00512f57     NOP
//         00512f58     NOP
//         00512f59     NOP
//         00512f5a     NOP
//         00512f5b     NOP
//         00512f5c     NOP
//         00512f5d     NOP
//         00512f5e     NOP
//         00512f5f     NOP
    return 0;
}

RGE_Static_Object* TRIBE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_object(TRIBE_Player * this,
//              RGE_Static_Obj    EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00512f6e(R), 00512f94(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     00512f6a(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00512f65(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00512f77(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     00512f60(R), 00512f8c(R)
//                               ?make_new_object@TRIBE_Player@@UAEPAVRGE_Static_Object@@JMM  XREF[2]:     00576904(*), 00576a34(*)
//                               TRIBE_Player::make_new_object
//                              tplayer.cpp:905 (40)
//         00512f60     MOV        EAX,dword ptr [ESP + param_5]
//         00512f64     PUSH       EBX
//         00512f65     MOV        EBX,dword ptr [ESP + param_3]
//         00512f69     PUSH       EBP
//         00512f6a     MOV        EBP,dword ptr [ESP + param_2]
//         00512f6e     MOV        EDX,dword ptr [ESP + param_1]
//         00512f72     PUSH       ESI
//         00512f73     PUSH       EDI
//         00512f74     MOV        EDI,this
//         00512f76     PUSH       EAX
//         00512f77     MOV        this,dword ptr [ESP + param_4]
//         00512f7b     PUSH       this
//         00512f7c     PUSH       EBX
//         00512f7d     PUSH       EBP
//         00512f7e     PUSH       EDX
//         00512f7f     MOV        this,EDI
//         00512f81     CALL       RGE_Player::make_new_object                      RGE_Static_Object * make_new_object(RGE_Playe
//         00512f86     MOV        ESI,EAX
//                              tplayer.cpp:910 (4)
//         00512f88     TEST       ESI,ESI
//         00512f8a     JZ         LAB_00512fee
//                              tplayer.cpp:912 (8)
//         00512f8c     MOV        EAX,dword ptr [ESP + param_5]
//         00512f90     TEST       EAX,EAX
//         00512f92     JZ         LAB_00512fbf
//                              tplayer.cpp:914 (22)
//         00512f94     MOV        EAX,dword ptr [ESP + param_1]
//         00512f98     MOV        this,word ptr [EDI + 0x4a]
//         00512f9c     PUSH       0x0
//         00512f9e     PUSH       EBX
//         00512f9f     PUSH       EBP
//         00512fa0     PUSH       EAX
//         00512fa1     PUSH       this
//         00512fa2     MOV        this,dword ptr [EDI + 0x3c]
//         00512fa5     CALL       TRIBE_World::check_destructables                 void check_destructables(TRIBE_World * this,
//                              tplayer.cpp:915 (9)
//         00512faa     MOV        EDX,dword ptr [ESI + 0x8]
//         00512fad     CMP        byte ptr [EDX + 0x4],0x50
//         00512fb1     JNZ        LAB_00512fbf
//                              tplayer.cpp:916 (12)
//         00512fb3     PUSH       0x461c4000
//         00512fb8     MOV        this,ESI
//         00512fba     CALL       TRIBE_Building_Object::build                     uchar build(TRIBE_Building_Object * this, flo
//                               LAB_00512fbf                                                 XREF[2]:     00512f92(j), 00512fb1(j)
//                              tplayer.cpp:921 (33)
//         00512fbf     MOV        EAX,[rge_base_game]                              = 00000000
//         00512fc4     CMP        dword ptr [EAX + 0x1b0],0x7
//         00512fcb     JNZ        LAB_00512fee
//         00512fcd     MOV        this,dword ptr [ESI + 0x8]
//         00512fd0     MOV        AX,word ptr [ECX + this->_padding_]
//         00512fd4     CMP        AX,0x5
//         00512fd8     JZ         LAB_00512fe0
//         00512fda     CMP        AX,0x21
//         00512fde     JNZ        LAB_00512fee
//                               LAB_00512fe0                                                 XREF[1]:     00512fd8(j)
//                              tplayer.cpp:922 (14)
//         00512fe0     MOV        this,dword ptr [ESI + 0x18]
//         00512fe3     MOV        EAX,dword ptr [ESI + 0x10]
//         00512fe6     PUSH       0x5
//         00512fe8     PUSH       EAX
//         00512fe9     MOV        EDX,dword ptr [this->_padding_]
//         00512feb     CALL       dword ptr [EDX + 0x1c]
//                               LAB_00512fee                                                 XREF[3]:     00512f8a(j), 00512fcb(j),
//                                                                                                         00512fde(j)
//                              tplayer.cpp:925 (2)
//         00512fee     MOV        EAX,ESI
//                              tplayer.cpp:926 (7)
//         00512ff0     POP        EDI
//         00512ff1     POP        ESI
//         00512ff2     POP        EBP
//         00512ff3     POP        EBX
//         00512ff4     RET        0x14
//         00512ff7     ??         90h
//         00512ff8     NOP
//         00512ff9     NOP
//         00512ffa     NOP
//         00512ffb     NOP
//         00512ffc     NOP
//         00512ffd     NOP
//         00512ffe     NOP
//         00512fff     NOP
    return 0;
}

void TRIBE_Player::interface_tech_avail(Item_Avail** param_1, short* param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall interface_tech_avail(TRIBE_Player * this, Item_Avail
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              Item_Avail * *    Stack[0x4]:4   param_1                   XREF[3]:     0051304e(R), 00513103(*), 00513117(R)
//              short *           Stack[0x8]:4   param_2                   XREF[5]:     00513067(R), 00513093(W), 005130c7(R), 00513196(R),
//                                                                                     0051319f(W)
//              short             Stack[0xc]:2   param_3                   XREF[2]:     0051303a(R), 005130ae(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00513023(W), 0051319a(R)
//              Tech_Tree *       Stack[-0x8]:4  base_tech                 XREF[6]:     00513129(W), 0051312d(R), 00513148(W), 0051314c(R),
//                                                                                     00513167(W), 0051316b(R)
//              undefined2        Stack[-0xa]:2  local_a                   XREF[2]:     005130e8(*), 00513162(R)
//              undefined2        Stack[-0xc]:2  local_c                   XREF[2]:     005130ef(*), 00513156(R)
//              short             Stack[-0xe]:2  inv_amt_3                 XREF[2]:     005130f4(*), 00513143(R)
//              short             Stack[-0x10]:2 inv_3                     XREF[2]:     005130f9(*), 00513137(R)
//              short             Stack[-0x12]:2 inv_amt_2                 XREF[2]:     005130fe(*), 00513124(R)
//              short             Stack[-0x14]:2 inv_2
//              short             Stack[-0x16]:2 inv_amt_1
//                               ?interface_tech_avail@TRIBE_Player@@QAEXPAPAUItem_Avail@@PA  XREF[2]:     setup_buttons:0049a005(c),
//                               TRIBE_Player::interface_tech_avail                                        create_research_list:0050b75d(c)
//                              tplayer.cpp:930 (8)
//         00513000     SUB        ESP,0x14
//         00513003     PUSH       EBX
//         00513004     PUSH       EBP
//         00513005     MOV        EBP,this
//         00513007     PUSH       ESI
//                              tplayer.cpp:932 (3)
//         00513008     XOR        EBX,EBX
//         0051300a     PUSH       EDI
//                              tplayer.cpp:939 (9)
//         0051300b     MOV        EAX,dword ptr [EBP + 0x3c]
//         0051300e     MOV        this,dword ptr [EAX + 0x104]
//                              tplayer.cpp:941 (32)
//         00513014     MOV        EAX,dword ptr [EBP + 0x220]
//         0051301a     MOV        DX,word ptr [EAX + 0x4]
//         0051301e     MOV        ESI,dword ptr [this->_padding_]
//         00513020     TEST       DX,DX
//         00513023     MOV        dword ptr [ESP + local_4],ESI
//         00513027     JLE        LAB_0051304e
//         00513029     MOV        EAX,dword ptr [EAX]
//         0051302b     LEA        this,[ESI + 0x28]
//         0051302e     ADD        EAX,0x4
//         00513031     MOVSX      EDX,DX
//                               LAB_00513034                                                 XREF[1]:     0051304c(j)
//                              tplayer.cpp:942 (16)
//         00513034     CMP        word ptr [EAX],0x1
//         00513038     JNZ        LAB_00513045
//         0051303a     MOV        DI,word ptr [ESP + param_3]
//         0051303f     CMP        word ptr [this->_padding_],DI
//         00513042     JNZ        LAB_00513045
//                              tplayer.cpp:943 (1)
//         00513044     INC        EBX
//                               LAB_00513045                                                 XREF[2]:     00513038(j), 00513042(j)
//                              tplayer.cpp:941 (9)
//         00513045     ADD        EAX,0x8
//         00513048     ADD        this,0x3c
//         0051304b     DEC        EDX
//         0051304c     JNZ        LAB_00513034
//                               LAB_0051304e                                                 XREF[1]:     00513027(j)
//                              tplayer.cpp:945 (10)
//         0051304e     MOV        EDI,dword ptr [ESP + param_1]
//         00513052     MOV        EAX,dword ptr [EDI]
//         00513054     TEST       EAX,EAX
//         00513056     JZ         LAB_00513067
//                              tplayer.cpp:947 (9)
//         00513058     PUSH       EAX
//         00513059     CALL       free                                             undefined free()
//         0051305e     ADD        ESP,0x4
//                              tplayer.cpp:948 (6)
//         00513061     MOV        dword ptr [EDI],0x0
//                               LAB_00513067                                                 XREF[1]:     00513056(j)
//                              tplayer.cpp:951 (4)
//         00513067     MOV        EDX,dword ptr [ESP + param_2]
//                              tplayer.cpp:952 (12)
//         0051306b     TEST       BX,BX
//         0051306e     MOV        word ptr [EDX],BX
//         00513071     JZ         LAB_005131b4
//                              tplayer.cpp:955 (13)
//         00513077     MOVSX      EAX,BX
//         0051307a     PUSH       0x28
//         0051307c     PUSH       EAX
//         0051307d     CALL       calloc                                           undefined calloc()
//         00513082     MOV        dword ptr [EDI],EAX
//                              tplayer.cpp:958 (25)
//         00513084     MOV        this,dword ptr [EBP + 0x220]
//         0051308a     XOR        EBX,EBX
//         0051308c     ADD        ESP,0x8
//         0051308f     CMP        word ptr [ECX + this->_padding_],BX
//         00513093     MOV        dword ptr [ESP + param_2],EBX
//         00513097     JLE        LAB_005131b4
//                               LAB_0051309d                                                 XREF[1]:     005131ae(j)
//                              tplayer.cpp:959 (42)
//         0051309d     MOV        this,dword ptr [this->_padding_]
//         0051309f     MOVSX      EAX,BX
//         005130a2     CMP        word ptr [ECX + EAX*0x8 + this->_padding_],0x1
//         005130a8     JNZ        LAB_005131a3
//         005130ae     MOV        this,word ptr [ESP + param_3]
//         005130b3     LEA        EAX,[EAX + EAX*0x2]
//         005130b6     LEA        EDX,[EAX + EAX*0x4]
//         005130b9     CMP        word ptr [ESI + EDX*0x4 + 0x28],this
//         005130be     LEA        EAX,[ESI + EDX*0x4]
//         005130c1     JNZ        LAB_005131a3
//                              tplayer.cpp:961 (18)
//         005130c7     MOVSX      this,word ptr [ESP + param_2]
//         005130cc     MOV        EDX,dword ptr [EDI]
//         005130ce     LEA        ESI,[ECX + ECX*0x4]
//         005130d1     SHL        ESI,0x3
//         005130d4     MOV        word ptr [EDX + ESI*0x1 + 0x4],BX
//                              tplayer.cpp:962 (11)
//         005130d9     MOV        this,dword ptr [EDI]
//         005130db     MOV        DX,word ptr [EAX + 0x24]
//         005130df     MOV        word ptr [ECX + ESI*0x1 + this+0x6],DX
//                              tplayer.cpp:963 (4)
//         005130e4     MOV        this,dword ptr [EDI]
//         005130e6     MOV        EDX,dword ptr [EAX]
//                              tplayer.cpp:964 (45)
//         005130e8     LEA        EAX=>local_a,[ESP + 0x1a]
//         005130ec     MOV        dword ptr [this->_padding_ + ESI*0x1],EDX
//         005130ef     LEA        this=>local_c,[ESP + 0x18]
//         005130f3     PUSH       EAX
//         005130f4     LEA        EDX=>inv_amt_3,[ESP + 0x1a]
//         005130f8     PUSH       this
//         005130f9     LEA        EAX=>inv_3,[ESP + 0x1c]
//         005130fd     PUSH       EDX
//         005130fe     LEA        this=>inv_amt_2,[ESP + 0x1e]
//         00513102     PUSH       EAX
//         00513103     LEA        EDX=>param_1,[ESP + 0x38]
//         00513107     PUSH       this
//         00513108     MOV        this,dword ptr [EBP + 0x220]
//         0051310e     PUSH       EDX
//         0051310f     PUSH       EBX
//         00513110     CALL       TRIBE_Player_Tech::tech_cost                     void tech_cost(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:965 (7)
//         00513115     MOV        EAX,dword ptr [EDI]
//         00513117     MOV        this,word ptr [ESP + param_1]
//                              tplayer.cpp:971 (100)
//         0051311c     PUSH       EBX
//         0051311d     MOV        word ptr [EAX + ESI*0x1 + 0x8],this
//         00513122     MOV        EAX,dword ptr [EDI]
//         00513124     MOVSX      EDX,word ptr [ESP + inv_amt_2]
//         00513129     MOV        dword ptr [ESP + base_tech],EDX
//         0051312d     FILD       dword ptr [ESP + base_tech]
//         00513131     FSTP       float ptr [EAX + ESI*0x1 + 0xc]
//         00513135     MOV        this,dword ptr [EDI]
//         00513137     MOV        DX,word ptr [ESP + inv_3]
//         0051313c     MOV        word ptr [ECX + ESI*0x1 + this->_padding_],DX
//         00513141     MOV        this,dword ptr [EDI]
//         00513143     MOVSX      EAX,word ptr [ESP + inv_amt_3]
//         00513148     MOV        dword ptr [ESP + base_tech],EAX
//         0051314c     FILD       dword ptr [ESP + base_tech]
//         00513150     FSTP       float ptr [ECX + ESI*0x1 + this->_padding_]
//         00513154     MOV        EDX,dword ptr [EDI]
//         00513156     MOV        AX,word ptr [ESP + local_c]
//         0051315b     MOV        word ptr [EDX + ESI*0x1 + 0x18],AX
//         00513160     MOV        EDX,dword ptr [EDI]
//         00513162     MOVSX      this,word ptr [ESP + local_a]
//         00513167     MOV        dword ptr [ESP + base_tech],this
//         0051316b     FILD       dword ptr [ESP + base_tech]
//         0051316f     FSTP       float ptr [EDX + ESI*0x1 + 0x1c]
//         00513173     MOV        this,dword ptr [EBP + 0x220]
//         00513179     CALL       TRIBE_Player_Tech::get_help_message              long get_help_message(TRIBE_Player_Tech * thi
//         0051317e     MOV        this,dword ptr [EDI]
//                              tplayer.cpp:972 (22)
//         00513180     PUSH       EBX
//         00513181     MOV        dword ptr [ECX + ESI*0x1 + this->_padding_],EAX
//         00513185     MOV        this,dword ptr [EBP + 0x220]
//         0051318b     CALL       TRIBE_Player_Tech::get_help_page                 long get_help_page(TRIBE_Player_Tech * this,
//         00513190     MOV        EDX,dword ptr [EDI]
//         00513192     MOV        dword ptr [EDX + ESI*0x1 + 0x24],EAX
//                              tplayer.cpp:973 (30)
//         00513196     MOV        EAX,dword ptr [ESP + param_2]
//         0051319a     MOV        ESI,dword ptr [ESP + local_4]
//         0051319e     INC        EAX
//         0051319f     MOV        dword ptr [ESP + param_2],EAX
//                               LAB_005131a3                                                 XREF[2]:     005130a8(j), 005130c1(j)
//         005131a3     MOV        this,dword ptr [EBP + 0x220]
//         005131a9     INC        EBX
//         005131aa     CMP        BX,word ptr [ECX + this->_padding_]
//         005131ae     JL         LAB_0051309d
//                               LAB_005131b4                                                 XREF[2]:     00513071(j), 00513097(j)
//                              tplayer.cpp:975 (10)
//         005131b4     POP        EDI
//         005131b5     POP        ESI
//         005131b6     POP        EBP
//         005131b7     POP        EBX
//         005131b8     ADD        ESP,0x14
//         005131bb     RET        0xc
//         005131be     ??         90h
//         005131bf     NOP
    return;
}

void TRIBE_Player::interface_item_avail(Item_Avail** param_1, short* param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall interface_item_avail(TRIBE_Player * this, Item_Avail
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              Item_Avail * *    Stack[0x4]:4   param_1                   XREF[5]:     00513266(R), 00513337(*), 00513349(R), 00513445(*),
//                                                                                     00513457(R)
//              short *           Stack[0x8]:4   param_2                   XREF[4]:     0051327b(R), 005132a3(W), 005133c6(R), 005133cb(W)
//              short             Stack[0xc]:2   param_3                   XREF[9]:     005131f2(R), 00513207(R), 005132d9(R), 00513468(W),
//                                                                                     0051346c(R), 00513487(W), 0051348b(R), 005134a6(W),
//                                                                                     005134aa(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0051335a(W), 0051335e(R), 00513379(W), 0051337d(R),
//                                                                                     00513398(W), 0051339c(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     005132a7(W), 005133d1(R), 005133da(W)
//              short             Stack[-0xc]:2  index                     XREF[5]:     005131d4(W), 00513238(W), 00513253(W), 0051325e(R),
//                                                                                     005133e6(R)
//              undefined2        Stack[-0xe]:2  local_e                   XREF[4]:     0051331f(*), 00513393(R), 0051342a(*), 005134a1(R)
//              short             Stack[-0x10]:2 tribe_flag                XREF[4]:     00513323(*), 00513387(R), 00513431(*), 00513495(R)
//              short             Stack[-0x12]:2 inv_amt_3                 XREF[4]:     00513329(*), 00513374(R), 00513436(*), 00513482(R)
//              short             Stack[-0x14]:2 inv_3                     XREF[4]:     0051332d(*), 00513368(R), 0051343b(*), 00513476(R)
//              short             Stack[-0x16]:2 inv_amt_2                 XREF[4]:     00513333(*), 00513355(R), 00513440(*), 00513463(R)
//              short             Stack[-0x18]:2 inv_2
//              short             Stack[-0x1a]:2 inv_amt_1
//                               ?interface_item_avail@TRIBE_Player@@QAEXPAPAUItem_Avail@@PA  XREF[4]:     setup_buttons:0049976d(c),
//                               TRIBE_Player::interface_item_avail                                        setup_buttons:0049a026(c),
//                                                                                                         create_build_list:0050b521(c),
//                                                                                                         create_train_list:0050b63d(c)
//                              tplayer.cpp:979 (8)
//         005131c0     SUB        ESP,0x18
//         005131c3     PUSH       EBX
//         005131c4     PUSH       EBP
//         005131c5     MOV        EBP,this
//         005131c7     PUSH       ESI
//                              tplayer.cpp:981 (4)
//         005131c8     XOR        EBX,EBX
//         005131ca     XOR        ESI,ESI
//                              tplayer.cpp:991 (20)
//         005131cc     MOV        AX,word ptr [EBP + 0x22]
//         005131d0     PUSH       EDI
//         005131d1     CMP        AX,BX
//         005131d4     MOV        dword ptr [ESP + index],EBX
//         005131d8     JLE        LAB_00513207
//         005131da     MOV        this,dword ptr [EBP + 0x24]
//         005131dd     MOVSX      EDX,AX
//                               LAB_005131e0                                                 XREF[1]:     00513205(j)
//                              tplayer.cpp:992 (12)
//         005131e0     MOV        EAX,dword ptr [this->_padding_]
//         005131e2     CMP        EAX,EBX
//         005131e4     JZ         LAB_00513201
//         005131e6     CMP        byte ptr [EAX + 0x4],0x46
//         005131ea     JC         LAB_00513201
//                              tplayer.cpp:993 (20)
//         005131ec     CMP        byte ptr [EAX + 0x52],0x0
//         005131f0     JZ         LAB_00513201
//         005131f2     MOV        DI,word ptr [ESP + param_3]
//         005131f7     CMP        word ptr [EAX + 0x15c],DI
//         005131fe     JNZ        LAB_00513201
//                              tplayer.cpp:994 (1)
//         00513200     INC        ESI
//                               LAB_00513201                                                 XREF[4]:     005131e4(j), 005131ea(j),
//                                                                                                         005131f0(j), 005131fe(j)
//                              tplayer.cpp:991 (6)
//         00513201     ADD        this,0x4
//         00513204     DEC        EDX
//         00513205     JNZ        LAB_005131e0
//                               LAB_00513207                                                 XREF[1]:     005131d8(j)
//                              tplayer.cpp:997 (30)
//         00513207     CMP        word ptr [ESP + param_3],0x76
//         0051320d     JNZ        LAB_0051325e
//         0051320f     MOV        EAX,dword ptr [EBP + 0x50]
//         00513212     FLD        float ptr [EAX + 0xc0]
//         00513218     FCOMP      float ptr [DAT_00576828]
//         0051321e     FNSTSW     AX
//         00513220     TEST       AH,0x40
//         00513223     JZ         LAB_0051325e
//                              tplayer.cpp:998 (16)
//         00513225     MOV        this,dword ptr [EBP + 0x24]
//         00513228     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051322e     MOV        AL,byte ptr [EDX + 0x52]
//         00513231     TEST       AL,AL
//         00513233     JNZ        LAB_0051325e
//                              tplayer.cpp:1001 (18)
//         00513235     MOV        EAX,dword ptr [EBP + 0x28]
//         00513238     MOV        dword ptr [ESP + index],0x1
//         00513240     MOV        EAX,dword ptr [EAX + 0x4]
//         00513243     CMP        EAX,EBX
//         00513245     JZ         LAB_0051325e
//                               LAB_00513247                                                 XREF[1]:     0051325c(j)
//                              tplayer.cpp:1002 (12)
//         00513247     MOV        this,dword ptr [EAX]
//         00513249     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051324c     CMP        word ptr [EDX + 0x10],0x6d
//         00513251     JNZ        LAB_00513257
//                              tplayer.cpp:1003 (4)
//         00513253     MOV        dword ptr [ESP + index],EBX
//                               LAB_00513257                                                 XREF[1]:     00513251(j)
//                              tplayer.cpp:1001 (7)
//         00513257     MOV        EAX,dword ptr [EAX + 0x4]
//         0051325a     CMP        EAX,EBX
//         0051325c     JNZ        LAB_00513247
//                               LAB_0051325e                                                 XREF[4]:     0051320d(j), 00513223(j),
//                                                                                                         00513233(j), 00513245(j)
//                              tplayer.cpp:1007 (7)
//         0051325e     CMP        word ptr [ESP + index],BX
//         00513263     JZ         LAB_00513266
//                              tplayer.cpp:1008 (1)
//         00513265     INC        ESI
//                               LAB_00513266                                                 XREF[1]:     00513263(j)
//                              tplayer.cpp:1010 (10)
//         00513266     MOV        EDI,dword ptr [ESP + param_1]
//         0051326a     MOV        EAX,dword ptr [EDI]
//         0051326c     CMP        EAX,EBX
//         0051326e     JZ         LAB_0051327b
//                              tplayer.cpp:1012 (9)
//         00513270     PUSH       EAX
//         00513271     CALL       free                                             undefined free()
//         00513276     ADD        ESP,0x4
//                              tplayer.cpp:1013 (2)
//         00513279     MOV        dword ptr [EDI],EBX
//                               LAB_0051327b                                                 XREF[1]:     0051326e(j)
//                              tplayer.cpp:1016 (4)
//         0051327b     MOV        EAX,dword ptr [ESP + param_2]
//                              tplayer.cpp:1017 (12)
//         0051327f     CMP        SI,BX
//         00513282     MOV        word ptr [EAX],SI
//         00513285     JZ         LAB_005134da
//                              tplayer.cpp:1020 (16)
//         0051328b     MOVSX      this,SI
//         0051328e     PUSH       0x28
//         00513290     PUSH       this
//         00513291     CALL       calloc                                           undefined calloc()
//         00513296     MOV        dword ptr [EDI],EAX
//         00513298     ADD        ESP,0x8
//                              tplayer.cpp:1022 (2)
//         0051329b     XOR        EDX,EDX
//                              tplayer.cpp:1023 (20)
//         0051329d     XOR        EAX,EAX
//         0051329f     CMP        word ptr [EBP + 0x22],BX
//         005132a3     MOV        dword ptr [ESP + param_2],EDX
//         005132a7     MOV        dword ptr [ESP + local_8],EAX
//         005132ab     JLE        LAB_005133e6
//                               LAB_005132b1                                                 XREF[1]:     005133de(j)
//                              tplayer.cpp:1024 (30)
//         005132b1     MOV        this,dword ptr [EBP + 0x24]
//         005132b4     MOVSX      EBX,AX
//         005132b7     SHL        EBX,0x2
//         005132ba     MOV        this,dword ptr [EBX + this->_padding_*0x1]
//         005132bd     TEST       this,this
//         005132bf     JZ         LAB_005133d5
//         005132c5     CMP        byte ptr [ECX + this->_padding_],0x46
//         005132c9     JC         LAB_005133d5
//                              tplayer.cpp:1025 (28)
//         005132cf     CMP        byte ptr [ECX + this+0x52],0x0
//         005132d3     JZ         LAB_005133d5
//         005132d9     MOV        SI,word ptr [ESP + param_3]
//         005132de     CMP        word ptr [ECX + this->_padding_],SI
//         005132e5     JNZ        LAB_005133d5
//                              tplayer.cpp:1027 (5)
//         005132eb     MOVSX      ESI,DX
//         005132ee     MOV        EDX,dword ptr [EDI]
//                              tplayer.cpp:1030 (87)
//         005132f0     PUSH       0x3f800000
//         005132f5     LEA        ESI,[ESI + ESI*0x4]
//         005132f8     SHL        ESI,0x3
//         005132fb     MOV        word ptr [EDX + ESI*0x1 + 0x4],AX
//         00513300     MOV        this,dword ptr [EBP + 0x24]
//         00513303     MOV        EDX,dword ptr [EBX + this->_padding_*0x1]
//         00513306     MOV        this,dword ptr [EDI]
//         00513308     MOV        DX,word ptr [EDX + 0x4c]
//         0051330c     MOV        word ptr [ECX + ESI*0x1 + this+0x6],DX
//         00513311     MOV        this,dword ptr [EBP + 0x24]
//         00513314     MOV        EDX,dword ptr [EBX + this->_padding_*0x1]
//         00513317     MOV        this,dword ptr [EDI]
//         00513319     MOV        EDX,dword ptr [EDX + 0x8]
//         0051331c     MOV        dword ptr [this->_padding_ + ESI*0x1],EDX
//         0051331f     LEA        this=>local_e,[ESP + 0x1e]
//         00513323     LEA        EDX=>tribe_flag,[ESP + 0x1c]
//         00513327     PUSH       this
//         00513328     PUSH       EDX
//         00513329     LEA        this=>inv_amt_3,[ESP + 0x22]
//         0051332d     LEA        EDX=>inv_3,[ESP + 0x20]
//         00513331     PUSH       this
//         00513332     PUSH       EDX
//         00513333     LEA        this=>inv_amt_2,[ESP + 0x26]
//         00513337     LEA        EDX=>param_1,[ESP + 0x40]
//         0051333b     PUSH       this
//         0051333c     PUSH       EDX
//         0051333d     PUSH       0x0
//         0051333f     PUSH       EAX
//         00513340     MOV        this,EBP
//         00513342     CALL       TRIBE_Player::obj_cost                           void obj_cost(TRIBE_Player * this, short para
//                              tplayer.cpp:1031 (12)
//         00513347     MOV        EAX,dword ptr [EDI]
//         00513349     MOV        this,word ptr [ESP + param_1]
//         0051334e     MOV        word ptr [EAX + ESI*0x1 + 0x8],this
//                              tplayer.cpp:1032 (19)
//         00513353     MOV        EAX,dword ptr [EDI]
//         00513355     MOVSX      EDX,word ptr [ESP + inv_amt_2]
//         0051335a     MOV        dword ptr [ESP + local_4],EDX
//         0051335e     FILD       dword ptr [ESP + local_4]
//         00513362     FSTP       float ptr [EAX + ESI*0x1 + 0xc]
//                              tplayer.cpp:1033 (12)
//         00513366     MOV        this,dword ptr [EDI]
//         00513368     MOV        DX,word ptr [ESP + inv_3]
//         0051336d     MOV        word ptr [ECX + ESI*0x1 + this->_padding_],DX
//                              tplayer.cpp:1034 (19)
//         00513372     MOV        this,dword ptr [EDI]
//         00513374     MOVSX      EAX,word ptr [ESP + inv_amt_3]
//         00513379     MOV        dword ptr [ESP + local_4],EAX
//         0051337d     FILD       dword ptr [ESP + local_4]
//         00513381     FSTP       float ptr [ECX + ESI*0x1 + this->_padding_]
//                              tplayer.cpp:1035 (12)
//         00513385     MOV        EDX,dword ptr [EDI]
//         00513387     MOV        AX,word ptr [ESP + tribe_flag]
//         0051338c     MOV        word ptr [EDX + ESI*0x1 + 0x18],AX
//                              tplayer.cpp:1036 (19)
//         00513391     MOV        EDX,dword ptr [EDI]
//         00513393     MOVSX      this,word ptr [ESP + local_e]
//         00513398     MOV        dword ptr [ESP + local_4],this
//         0051339c     FILD       dword ptr [ESP + local_4]
//         005133a0     FSTP       float ptr [EDX + ESI*0x1 + 0x1c]
//                              tplayer.cpp:1037 (17)
//         005133a4     MOV        EAX,dword ptr [EBP + 0x24]
//         005133a7     MOV        this,dword ptr [EBX + EAX*0x1]
//         005133aa     CALL       RGE_Master_Static_Object::get_help_message       long get_help_message(RGE_Master_Static_Objec
//         005133af     MOV        this,dword ptr [EDI]
//         005133b1     MOV        dword ptr [ECX + ESI*0x1 + this->_padding_],EAX
//                              tplayer.cpp:1038 (17)
//         005133b5     MOV        EDX,dword ptr [EBP + 0x24]
//         005133b8     MOV        this,dword ptr [EBX + EDX*0x1]
//         005133bb     CALL       RGE_Master_Static_Object::get_help_page          long get_help_page(RGE_Master_Static_Object *
//         005133c0     MOV        this,dword ptr [EDI]
//         005133c2     MOV        dword ptr [ECX + ESI*0x1 + this->_padding_],EAX
//                              tplayer.cpp:1039 (30)
//         005133c6     MOV        EAX,dword ptr [ESP + param_2]
//         005133ca     INC        EAX
//         005133cb     MOV        dword ptr [ESP + param_2],EAX
//         005133cf     MOV        EDX,EAX
//         005133d1     MOV        EAX,dword ptr [ESP + local_8]
//                               LAB_005133d5                                                 XREF[4]:     005132bf(j), 005132c9(j),
//                                                                                                         005132d3(j), 005132e5(j)
//         005133d5     INC        EAX
//         005133d6     CMP        AX,word ptr [EBP + 0x22]
//         005133da     MOV        dword ptr [ESP + local_8],EAX
//         005133de     JL         LAB_005132b1
//                              tplayer.cpp:1023 (2)
//         005133e4     XOR        EBX,EBX
//                               LAB_005133e6                                                 XREF[1]:     005132ab(j)
//                              tplayer.cpp:1043 (11)
//         005133e6     CMP        word ptr [ESP + index],BX
//         005133eb     JZ         LAB_005134da
//                              tplayer.cpp:1045 (5)
//         005133f1     MOVSX      ESI,DX
//         005133f4     MOV        EDX,dword ptr [EDI]
//                              tplayer.cpp:1048 (95)
//         005133f6     PUSH       0x3f800000
//         005133fb     LEA        ESI,[ESI + ESI*0x4]
//         005133fe     SHL        ESI,0x3
//         00513401     MOV        word ptr [EDX + ESI*0x1 + 0x4],0x6d
//         00513408     MOV        EAX,dword ptr [EBP + 0x24]
//         0051340b     MOV        EDX,dword ptr [EDI]
//         0051340d     MOV        this,dword ptr [EAX + 0x1b4]
//         00513413     MOV        AX,word ptr [ECX + this->_padding_]
//         00513417     MOV        word ptr [EDX + ESI*0x1 + 0x6],AX
//         0051341c     MOV        this,dword ptr [EBP + 0x24]
//         0051341f     MOV        EAX,dword ptr [EDI]
//         00513421     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00513427     MOV        this,dword ptr [EDX + 0x8]
//         0051342a     LEA        EDX=>local_e,[ESP + 0x1e]
//         0051342e     MOV        dword ptr [EAX + ESI*0x1],this
//         00513431     LEA        EAX=>tribe_flag,[ESP + 0x1c]
//         00513435     PUSH       EDX
//         00513436     LEA        this=>inv_amt_3,[ESP + 0x1e]
//         0051343a     PUSH       EAX
//         0051343b     LEA        EDX=>inv_3,[ESP + 0x20]
//         0051343f     PUSH       this
//         00513440     LEA        EAX=>inv_amt_2,[ESP + 0x22]
//         00513444     PUSH       EDX
//         00513445     LEA        this=>param_1,[ESP + 0x40]
//         00513449     PUSH       EAX
//         0051344a     PUSH       this
//         0051344b     PUSH       EBX
//         0051344c     PUSH       0x6d
//         0051344e     MOV        this,EBP
//         00513450     CALL       TRIBE_Player::obj_cost                           void obj_cost(TRIBE_Player * this, short para
//                              tplayer.cpp:1049 (12)
//         00513455     MOV        EDX,dword ptr [EDI]
//         00513457     MOV        AX,word ptr [ESP + param_1]
//         0051345c     MOV        word ptr [EDX + ESI*0x1 + 0x8],AX
//                              tplayer.cpp:1050 (19)
//         00513461     MOV        EDX,dword ptr [EDI]
//         00513463     MOVSX      this,word ptr [ESP + inv_amt_2]
//         00513468     MOV        dword ptr [ESP + param_3],this
//         0051346c     FILD       dword ptr [ESP + param_3]
//         00513470     FSTP       float ptr [EDX + ESI*0x1 + 0xc]
//                              tplayer.cpp:1051 (12)
//         00513474     MOV        EAX,dword ptr [EDI]
//         00513476     MOV        this,word ptr [ESP + inv_3]
//         0051347b     MOV        word ptr [EAX + ESI*0x1 + 0x10],this
//                              tplayer.cpp:1052 (19)
//         00513480     MOV        EAX,dword ptr [EDI]
//         00513482     MOVSX      EDX,word ptr [ESP + inv_amt_3]
//         00513487     MOV        dword ptr [ESP + param_3],EDX
//         0051348b     FILD       dword ptr [ESP + param_3]
//         0051348f     FSTP       float ptr [EAX + ESI*0x1 + 0x14]
//                              tplayer.cpp:1053 (12)
//         00513493     MOV        this,dword ptr [EDI]
//         00513495     MOV        DX,word ptr [ESP + tribe_flag]
//         0051349a     MOV        word ptr [ECX + ESI*0x1 + this->_padding_],DX
//                              tplayer.cpp:1054 (19)
//         0051349f     MOV        this,dword ptr [EDI]
//         005134a1     MOVSX      EAX,word ptr [ESP + local_e]
//         005134a6     MOV        dword ptr [ESP + param_3],EAX
//         005134aa     FILD       dword ptr [ESP + param_3]
//         005134ae     FSTP       float ptr [ECX + ESI*0x1 + this->_padding_]
//                              tplayer.cpp:1055 (20)
//         005134b2     MOV        EDX,dword ptr [EBP + 0x24]
//         005134b5     MOV        this,dword ptr [EDX + 0x1b4]
//         005134bb     CALL       RGE_Master_Static_Object::get_help_message       long get_help_message(RGE_Master_Static_Objec
//         005134c0     MOV        this,dword ptr [EDI]
//         005134c2     MOV        dword ptr [ECX + ESI*0x1 + this->_padding_],EAX
//                              tplayer.cpp:1056 (20)
//         005134c6     MOV        EDX,dword ptr [EBP + 0x24]
//         005134c9     MOV        this,dword ptr [EDX + 0x1b4]
//         005134cf     CALL       RGE_Master_Static_Object::get_help_page          long get_help_page(RGE_Master_Static_Object *
//         005134d4     MOV        this,dword ptr [EDI]
//         005134d6     MOV        dword ptr [ECX + ESI*0x1 + this->_padding_],EAX
//                               LAB_005134da                                                 XREF[2]:     00513285(j), 005133eb(j)
//                              tplayer.cpp:1059 (10)
//         005134da     POP        EDI
//         005134db     POP        ESI
//         005134dc     POP        EBP
//         005134dd     POP        EBX
//         005134de     ADD        ESP,0x18
//         005134e1     RET        0xc
//         005134e4     ??         90h
//         005134e5     NOP
//         005134e6     NOP
//         005134e7     NOP
//         005134e8     NOP
//         005134e9     NOP
//         005134ea     NOP
//         005134eb     NOP
//         005134ec     NOP
//         005134ed     NOP
//         005134ee     NOP
//         005134ef     NOP
    return;
}

void TRIBE_Player::interface_trade_avail(Trade_Avail** param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall interface_trade_avail(TRIBE_Player * this, Trade_Ava
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              Trade_Avail * *   Stack[0x4]:4   param_1                   XREF[1]:     00513589(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     005135a5(R)
//              RGE_Static_Obj    Stack[-0x184   dock_list                 XREF[3,4]:   00513508(W), 0051354e(R), 00513575(R), 0051352a(*),
//                                                                                     00513565(*), 005135c4(*), 005135ca(*)
//              undefined4        Stack[-0x188   local_188                 XREF[3]:     0051350c(W), 00513571(R), 0051357d(W)
//              int               Stack[-0x18c   i
//                               ?interface_trade_avail@TRIBE_Player@@QAEXPAPAUTrade_Avail@@
//                               TRIBE_Player::interface_trade_avail
//                              tplayer.cpp:1063 (6)
//         005134f0     SUB        ESP,0x188
//                              tplayer.cpp:1073 (28)
//         005134f6     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005134f9     PUSH       EBX
//         005134fa     PUSH       EBP
//         005134fb     MOV        EDX,0x1
//         00513500     XOR        EBP,EBP
//         00513502     CMP        word ptr [EAX + 0x3c],DX
//         00513506     PUSH       ESI
//         00513507     PUSH       EDI
//         00513508     MOV        dword ptr [ESP + dock_list[0]],this
//         0051350c     MOV        dword ptr [ESP + local_188],EDX
//         00513510     JLE        LAB_00513589
//                               LAB_00513512                                                 XREF[1]:     00513587(j)
//                              tplayer.cpp:1075 (8)
//         00513512     MOVSX      ESI,word ptr [ECX + this+0x4a]
//         00513516     CMP        EDX,ESI
//         00513518     JZ         LAB_00513579
//                              tplayer.cpp:1077 (16)
//         0051351a     MOV        EAX,dword ptr [EAX + 0x40]
//         0051351d     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00513520     MOV        EAX,dword ptr [EAX + 0x28]
//         00513523     MOV        ESI,dword ptr [EAX + 0x4]
//         00513526     TEST       ESI,ESI
//         00513528     JZ         LAB_00513579
//                              tplayer.cpp:1114 (4)
//         0051352a     LEA        EBX=>dock_list[1],[ESP + EBP*0x4 + 0x18]
//                               LAB_0051352e                                                 XREF[1]:     0051356f(j)
//                              tplayer.cpp:1079 (12)
//         0051352e     MOV        EDI,dword ptr [ESI]
//         00513530     MOV        this,dword ptr [EDI + 0x8]
//         00513533     CMP        word ptr [ECX + this->_padding_],0x2d
//         00513538     JNZ        LAB_0051356a
//                              tplayer.cpp:1082 (40)
//         0051353a     FLD        float ptr [EDI + 0x3c]
//         0051353d     CALL       __ftol                                           undefined __ftol()
//         00513542     FLD        float ptr [EDI + 0x38]
//         00513545     MOVSX      EDX,AX
//         00513548     PUSH       EDX
//         00513549     CALL       __ftol                                           undefined __ftol()
//         0051354e     MOV        this,dword ptr [ESP + dock_list[0]]
//         00513552     MOVSX      EAX,AX
//         00513555     MOV        this,dword ptr [ECX + this->_padding_]
//         00513558     PUSH       EAX
//         00513559     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         0051355e     TEST       AL,AL
//         00513560     JZ         LAB_0051356a
//                              tplayer.cpp:1084 (2)
//         00513562     MOV        EDX,dword ptr [ESI]
//                              tplayer.cpp:1085 (37)
//         00513564     INC        EBP
//         00513565     MOV        dword ptr [EBX]=>dock_list[1],EDX
//         00513567     ADD        EBX,0x4
//                               LAB_0051356a                                                 XREF[2]:     00513538(j), 00513560(j)
//         0051356a     MOV        ESI,dword ptr [ESI + 0x4]
//         0051356d     TEST       ESI,ESI
//         0051356f     JNZ        LAB_0051352e
//         00513571     MOV        EDX,dword ptr [ESP + local_188]
//         00513575     MOV        this,dword ptr [ESP + dock_list[0]]
//                               LAB_00513579                                                 XREF[2]:     00513518(j), 00513528(j)
//         00513579     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051357c     INC        EDX
//         0051357d     MOV        dword ptr [ESP + local_188],EDX
//         00513581     MOVSX      ESI,word ptr [EAX + 0x3c]
//         00513585     CMP        EDX,ESI
//         00513587     JL         LAB_00513512
//                               LAB_00513589                                                 XREF[1]:     00513510(j)
//                              tplayer.cpp:1092 (13)
//         00513589     MOV        ESI,dword ptr [ESP + param_1]
//         00513590     MOV        EAX,dword ptr [ESI]
//         00513592     TEST       EAX,EAX
//         00513594     JZ         LAB_005135a5
//                              tplayer.cpp:1094 (9)
//         00513596     PUSH       EAX
//         00513597     CALL       free                                             undefined free()
//         0051359c     ADD        ESP,0x4
//                              tplayer.cpp:1095 (6)
//         0051359f     MOV        dword ptr [ESI],0x0
//                               LAB_005135a5                                                 XREF[1]:     00513594(j)
//                              tplayer.cpp:1099 (7)
//         005135a5     MOV        EAX,dword ptr [ESP + param_2]
//                              tplayer.cpp:1100 (7)
//         005135ac     TEST       EBP,EBP
//         005135ae     MOV        word ptr [EAX],BP
//         005135b1     JZ         LAB_005135e4
//                              tplayer.cpp:1103 (13)
//         005135b3     PUSH       0xc
//         005135b5     PUSH       EBP
//         005135b6     CALL       calloc                                           undefined calloc()
//         005135bb     ADD        ESP,0x8
//         005135be     MOV        dword ptr [ESI],EAX
//                              tplayer.cpp:1107 (4)
//         005135c0     TEST       EBP,EBP
//         005135c2     JLE        LAB_005135e4
//                              tplayer.cpp:1114 (45)
//         005135c4     LEA        EDX=>dock_list[1],[ESP + 0x18]
//         005135c8     MOV        ESI,EBP
//                               LAB_005135ca                                                 XREF[1]:     005135e2(j)
//         005135ca     MOV        this,dword ptr [EDX]=>dock_list[1]
//         005135cc     ADD        EAX,0xc
//         005135cf     ADD        EDX,0x4
//         005135d2     DEC        ESI
//         005135d3     MOV        EDI,dword ptr [ECX + this->_padding_]
//         005135d6     MOV        dword ptr [EAX + -0x8],this
//         005135d9     MOV        dword ptr [EAX + -0xc],EDI
//         005135dc     MOV        this,dword ptr [ECX + this->_padding_]
//         005135df     MOV        dword ptr [EAX + -0x4],this
//         005135e2     JNZ        LAB_005135ca
//                               LAB_005135e4                                                 XREF[2]:     005135b1(j), 005135c2(j)
//         005135e4     POP        EDI
//         005135e5     POP        ESI
//         005135e6     POP        EBP
//         005135e7     POP        EBX
//         005135e8     ADD        ESP,0x188
//         005135ee     RET        0x8
//         005135f1     ??         90h
//         005135f2     NOP
//         005135f3     NOP
//         005135f4     NOP
//         005135f5     NOP
//         005135f6     NOP
//         005135f7     NOP
//         005135f8     NOP
//         005135f9     NOP
//         005135fa     NOP
//         005135fb     NOP
//         005135fc     NOP
//         005135fd     NOP
//         005135fe     NOP
//         005135ff     NOP
    return;
}

uchar TRIBE_Player::command_make_building(short param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_building(TRIBE_Player * this, short pa
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     00513603(R), 0051362f(*)
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00513629(*)
//              short             Stack[-0x8]:2  list_num
//                               ?command_make_building@TRIBE_Player@@QAEEFMM@Z               XREF[1]:     command_place_object:0052d2fc(c)
//                               TRIBE_Player::command_make_building
//                              tplayer.cpp:1119 (3)
//         00513600     PUSH       this
//         00513601     PUSH       ESI
//         00513602     PUSH       EDI
//                              tplayer.cpp:1123 (32)
//         00513603     MOV        EDI,dword ptr [ESP + param_1]
//         00513607     MOV        ESI,this
//         00513609     MOVSX      EAX,DI
//         0051360c     MOV        this,dword ptr [ESI + 0x24]
//         0051360f     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
//         00513612     TEST       EAX,EAX
//         00513614     JZ         LAB_00513683
//         00513616     MOV        this,byte ptr [EAX + 0x52]
//         00513619     TEST       this,this
//         0051361b     JNZ        LAB_00513623
//         0051361d     CMP        DI,0x6d
//         00513621     JNZ        LAB_00513683
//                               LAB_00513623                                                 XREF[1]:     0051361b(j)
//                              tplayer.cpp:1124 (29)
//         00513623     PUSH       -0x1
//         00513625     PUSH       -0x1
//         00513627     PUSH       0x4
//         00513629     LEA        EDX=>local_4,[ESP + 0x14]
//         0051362d     PUSH       0x4
//         0051362f     LEA        EAX=>param_1,[ESP + 0x20]
//         00513633     PUSH       EDX
//         00513634     PUSH       EAX
//         00513635     MOV        this,ESI
//         00513637     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0051363c     TEST       AL,AL
//         0051363e     JZ         LAB_00513683
//                              tplayer.cpp:1127 (14)
//         00513640     MOV        this,dword ptr [ESI + 0x24]
//         00513643     MOV        this,dword ptr [ECX + this->_padding_]
//         00513649     MOV        EDX,dword ptr [this->_padding_]
//         0051364b     CALL       dword ptr [EDX + 0x2c]
//                              tplayer.cpp:1129 (32)
//         0051364e     MOV        EAX,dword ptr [ESP + 0x18]
//         00513652     MOV        this,dword ptr [ESP + 0x14]
//         00513656     MOV        EDX,dword ptr [ESP + 0x8]
//         0051365a     PUSH       EAX
//         0051365b     MOV        EAX,dword ptr [ESP + 0x14]
//         0051365f     PUSH       this=>DAT_fffffff8
//         00513660     MOV        this,dword ptr [ESI + 0x3c]
//         00513663     PUSH       EDI=>DAT_fffffff4
//         00513664     PUSH       EDX=>DAT_fffffff0
//         00513665     PUSH       EAX
//         00513666     MOV        this,dword ptr [ECX + this->_padding_]
//         00513669     CALL       TRIBE_Command::command_build                     void command_build(TRIBE_Command * this, RGE_
//                              tplayer.cpp:1130 (13)
//         0051366e     MOV        EDX,dword ptr [ESP + 0x10]
//         00513672     PUSH       EDX
//         00513673     CALL       free                                             undefined free()
//         00513678     ADD        ESP,0x4
//                              tplayer.cpp:1131 (2)
//         0051367b     MOV        AL,0x1
//                              tplayer.cpp:1135 (14)
//         0051367d     POP        EDI
//         0051367e     POP        ESI
//         0051367f     POP        this
//         00513680     RET        0xc
//                               LAB_00513683                                                 XREF[3]:     00513614(j), 00513621(j),
//                                                                                                         0051363e(j)
//         00513683     POP        EDI
//         00513684     XOR        AL,AL
//         00513686     POP        ESI
//         00513687     POP        this
//         00513688     RET        0xc
//         0051368b     ??         90h
//         0051368c     NOP
//         0051368d     NOP
//         0051368e     NOP
//         0051368f     NOP
    return 0;
}

uchar TRIBE_Player::command_make_wall(short param_1, long param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_wall(TRIBE_Player * this, short param_
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     00513693(R), 005136b9(*)
//              long              Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//              long              Stack[0x14]:4  param_5
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     005136b3(*)
//              short             Stack[-0x8]:2  list_num
//                               ?command_make_wall@TRIBE_Player@@QAEEFJJJJ@Z                 XREF[1]:     command_place_multi_object:0052d4a
//                               TRIBE_Player::command_make_wall
//                              tplayer.cpp:1140 (3)
//         00513690     PUSH       this
//         00513691     PUSH       ESI
//         00513692     PUSH       EDI
//                              tplayer.cpp:1144 (26)
//         00513693     MOV        EDI,dword ptr [ESP + param_1]
//         00513697     MOV        ESI,this
//         00513699     MOVSX      EAX,DI
//         0051369c     MOV        this,dword ptr [ESI + 0x24]
//         0051369f     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
//         005136a2     TEST       EAX,EAX
//         005136a4     JZ         LAB_00513717
//         005136a6     MOV        this,byte ptr [EAX + 0x52]
//         005136a9     TEST       this,this
//         005136ab     JZ         LAB_00513717
//                              tplayer.cpp:1145 (29)
//         005136ad     PUSH       -0x1
//         005136af     PUSH       -0x1
//         005136b1     PUSH       0x4
//         005136b3     LEA        EDX=>local_4,[ESP + 0x14]
//         005136b7     PUSH       0x4
//         005136b9     LEA        EAX=>param_1,[ESP + 0x20]
//         005136bd     PUSH       EDX
//         005136be     PUSH       EAX
//         005136bf     MOV        this,ESI
//         005136c1     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         005136c6     TEST       AL,AL
//         005136c8     JZ         LAB_00513717
//                              tplayer.cpp:1148 (14)
//         005136ca     MOV        this,dword ptr [ESI + 0x24]
//         005136cd     MOV        this,dword ptr [ECX + this->_padding_]
//         005136d3     MOV        EDX,dword ptr [this->_padding_]
//         005136d5     CALL       dword ptr [EDX + 0x2c]
//                              tplayer.cpp:1150 (42)
//         005136d8     MOV        EAX,dword ptr [ESP + 0x20]
//         005136dc     MOV        this,dword ptr [ESP + 0x1c]
//         005136e0     MOV        EDX,dword ptr [ESP + 0x18]
//         005136e4     PUSH       EAX
//         005136e5     MOV        EAX,dword ptr [ESP + 0x18]
//         005136e9     PUSH       this=>DAT_fffffff8
//         005136ea     MOV        this,dword ptr [ESP + 0x10]
//         005136ee     PUSH       EDX=>DAT_fffffff4
//         005136ef     MOV        EDX,dword ptr [ESP + 0x1c]
//         005136f3     PUSH       EAX=>DAT_fffffff0
//         005136f4     MOV        EAX,dword ptr [ESI + 0x3c]
//         005136f7     PUSH       EDI
//         005136f8     PUSH       this
//         005136f9     PUSH       EDX
//         005136fa     MOV        this,dword ptr [EAX + 0x58]
//         005136fd     CALL       TRIBE_Command::command_build_wall                void command_build_wall(TRIBE_Command * this,
//                              tplayer.cpp:1151 (13)
//         00513702     MOV        this,dword ptr [ESP + 0x10]
//         00513706     PUSH       this
//         00513707     CALL       free                                             undefined free()
//         0051370c     ADD        ESP,0x4
//                              tplayer.cpp:1152 (2)
//         0051370f     MOV        AL,0x1
//                              tplayer.cpp:1156 (14)
//         00513711     POP        EDI
//         00513712     POP        ESI
//         00513713     POP        this
//         00513714     RET        0x14
//                               LAB_00513717                                                 XREF[3]:     005136a4(j), 005136ab(j),
//                                                                                                         005136c8(j)
//         00513717     POP        EDI
//         00513718     XOR        AL,AL
//         0051371a     POP        ESI
//         0051371b     POP        this
//         0051371c     RET        0x14
//         0051371f     ??         90h
    return 0;
}

uchar TRIBE_Player::command_building_make_tech(short param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_building_make_tech(TRIBE_Player * this, sho
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00513733(R)
//                               ?command_building_make_tech@TRIBE_Player@@QAEEF@Z            XREF[1]:     command_research:0049cb3a(c)
//                               TRIBE_Player::command_building_make_tech
//                              tplayer.cpp:1162 (19)
//         00513720     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00513726     TEST       EAX,EAX
//         00513728     JZ         LAB_00513749
//         0051372a     MOV        EDX,dword ptr [EAX + 0x8]
//         0051372d     CMP        byte ptr [EDX + 0x4],0x50
//         00513731     JNZ        LAB_00513749
//                              tplayer.cpp:1165 (17)
//         00513733     MOV        EDX,dword ptr [ESP + param_1]
//         00513737     PUSH       EDX
//         00513738     PUSH       EAX
//         00513739     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051373c     MOV        this,dword ptr [EAX + 0x58]
//         0051373f     CALL       TRIBE_Command::command_research                  void command_research(TRIBE_Command * this, R
//                              tplayer.cpp:1166 (2)
//         00513744     MOV        AL,0x1
//                              tplayer.cpp:1170 (3)
//         00513746     RET        0x4
//                               LAB_00513749                                                 XREF[2]:     00513728(j), 00513731(j)
//                              tplayer.cpp:1169 (2)
//         00513749     XOR        AL,AL
//                              tplayer.cpp:1170 (3)
//         0051374b     RET        0x4
//         0051374e     ??         90h
//         0051374f     NOP
    return 0;
}

uchar TRIBE_Player::command_building_cancel() {
    /* TODO: Stub */
//                              uchar __thiscall command_building_cancel(TRIBE_Player * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?command_building_cancel@TRIBE_Player@@QAEEXZ                XREF[1]:     command_cancel_building:0049bf3c(c
//                               TRIBE_Player::command_building_cancel
//                              tplayer.cpp:1175 (39)
//         00513750     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00513756     PUSH       EBX
//         00513757     TEST       EAX,EAX
//         00513759     JZ         LAB_00513787
//         0051375b     CMP        dword ptr [EAX + 0xc],this
//         0051375e     JNZ        LAB_00513787
//         00513760     MOV        EDX,dword ptr [EAX + 0x8]
//         00513763     MOV        BL,byte ptr [EDX + 0x4]
//         00513766     CMP        BL,0x50
//         00513769     JZ         LAB_00513770
//         0051376b     CMP        BL,0x46
//         0051376e     JNZ        LAB_00513787
//                               LAB_00513770                                                 XREF[1]:     00513769(j)
//         00513770     CMP        word ptr [EDX + 0x14],0x1
//         00513775     JZ         LAB_00513787
//                              tplayer.cpp:1181 (12)
//         00513777     PUSH       EAX
//         00513778     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051377b     MOV        this,dword ptr [EAX + 0x58]
//         0051377e     CALL       TRIBE_Command::command_cancel_build              void command_cancel_build(TRIBE_Command * thi
//                              tplayer.cpp:1182 (2)
//         00513783     MOV        AL,0x1
//                              tplayer.cpp:1186 (2)
//         00513785     POP        EBX
//         00513786     RET
//                               LAB_00513787                                                 XREF[4]:     00513759(j), 0051375e(j),
//                                                                                                         0051376e(j), 00513775(j)
//                              tplayer.cpp:1185 (2)
//         00513787     XOR        AL,AL
//                              tplayer.cpp:1186 (2)
//         00513789     POP        EBX
//         0051378a     RET
//         0051378b     ??         90h
//         0051378c     NOP
//         0051378d     NOP
//         0051378e     NOP
//         0051378f     NOP
    return 0;
}

uchar TRIBE_Player::command_delete_object(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_delete_object(TRIBE_Player * this, RGE_Stat
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00513790(R)
//                               ?command_delete_object@TRIBE_Player@@QAEEPAVRGE_Static_Obje  XREF[1]:     deleteUnit:00501b74(c)
//                               TRIBE_Player::command_delete_object
//                              tplayer.cpp:1189 (29)
//         00513790     MOV        EAX,dword ptr [ESP + param_1]
//         00513794     TEST       EAX,EAX
//         00513796     JZ         LAB_005137be
//         00513798     CMP        dword ptr [EAX + 0xc],this
//         0051379b     JNZ        LAB_005137be
//         0051379d     MOV        EDX,dword ptr [EAX + 0x8]
//         005137a0     MOV        DL,byte ptr [EDX + 0x4]
//         005137a3     CMP        DL,0x50
//         005137a6     JZ         LAB_005137ad
//         005137a8     CMP        DL,0x46
//         005137ab     JNZ        LAB_005137be
//                               LAB_005137ad                                                 XREF[1]:     005137a6(j)
//                              tplayer.cpp:1192 (12)
//         005137ad     PUSH       EAX
//         005137ae     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005137b1     MOV        this,dword ptr [EAX + 0x58]
//         005137b4     CALL       TRIBE_Command::command_cancel_build              void command_cancel_build(TRIBE_Command * thi
//                              tplayer.cpp:1193 (2)
//         005137b9     MOV        AL,0x1
//                              tplayer.cpp:1197 (3)
//         005137bb     RET        0x4
//                               LAB_005137be                                                 XREF[3]:     00513796(j), 0051379b(j),
//                                                                                                         005137ab(j)
//                              tplayer.cpp:1196 (2)
//         005137be     XOR        AL,AL
//                              tplayer.cpp:1197 (3)
//         005137c0     RET        0x4
//         005137c3     ??         90h
//         005137c4     NOP
//         005137c5     NOP
//         005137c6     NOP
//         005137c7     NOP
//         005137c8     NOP
//         005137c9     NOP
//         005137ca     NOP
//         005137cb     NOP
//         005137cc     NOP
//         005137cd     NOP
//         005137ce     NOP
//         005137cf     NOP
    return 0;
}

uchar TRIBE_Player::command_trade_attribute(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_trade_attribute(TRIBE_Player * this, long p
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     005137d3(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     005137e2(*), 005137f3(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_trade_attribute@TRIBE_Player@@QAEEJ@Z               XREF[1]:     command_trade_attribute:0049d361(c
//                               TRIBE_Player::command_trade_attribute
//                              tplayer.cpp:1202 (3)
//         005137d0     SUB        ESP,0x8
//                              tplayer.cpp:1206 (32)
//         005137d3     LEA        EAX=>local_4,[ESP + 0x4]
//         005137d7     PUSH       ESI
//         005137d8     PUSH       0x5
//         005137da     MOV        ESI,this
//         005137dc     PUSH       -0x1
//         005137de     PUSH       -0x1
//         005137e0     PUSH       0x4
//         005137e2     LEA        this=>list_num,[ESP + 0x14]
//         005137e6     PUSH       EAX
//         005137e7     PUSH       this
//         005137e8     MOV        this,ESI
//         005137ea     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         005137ef     TEST       AL,AL
//         005137f1     JZ         LAB_00513831
//                              tplayer.cpp:1208 (14)
//         005137f3     MOV        EDX,dword ptr [ESP + list_num]
//         005137f7     MOV        this,dword ptr [EDX]
//         005137f9     MOV        EAX,dword ptr [this->_padding_]
//         005137fb     CALL       dword ptr [EAX + 0xac]
//                              tplayer.cpp:1209 (26)
//         00513801     MOV        this,dword ptr [ESP + 0x10]
//         00513805     MOV        EDX,dword ptr [ESP + 0x8]
//         00513809     MOV        EAX,dword ptr [ESP + 0x4]
//         0051380d     PUSH       this
//         0051380e     MOV        this,dword ptr [ESI + 0x3c]
//         00513811     PUSH       EDX=>DAT_fffffff8
//         00513812     PUSH       EAX=>DAT_fffffff4
//         00513813     MOV        this,dword ptr [ECX + this->_padding_]
//         00513816     CALL       TRIBE_Command::command_trade_attribute           void command_trade_attribute(TRIBE_Command *
//                              tplayer.cpp:1210 (13)
//         0051381b     MOV        EDX,dword ptr [ESP + 0x4]
//         0051381f     PUSH       EDX
//         00513820     CALL       free                                             undefined free()
//         00513825     ADD        ESP,0x4
//                              tplayer.cpp:1211 (2)
//         00513828     MOV        AL,0x1
//                              tplayer.cpp:1215 (7)
//         0051382a     POP        ESI
//         0051382b     ADD        ESP,0x8
//         0051382e     RET        0x4
//                               LAB_00513831                                                 XREF[1]:     005137f1(j)
//                              tplayer.cpp:1214 (2)
//         00513831     XOR        AL,AL
//                              tplayer.cpp:1215 (7)
//         00513833     POP        ESI
//         00513834     ADD        ESP,0x8
//         00513837     RET        0x4
//         0051383a     ??         90h
//         0051383b     NOP
//         0051383c     NOP
//         0051383d     NOP
//         0051383e     NOP
//         0051383f     NOP
    return 0;
}

uchar TRIBE_Player::command_trade_attribute(int param_1, long param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_trade_attribute(TRIBE_Player * this, int pa
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0051384c(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00513840(R)
//                               ?command_trade_attribute@TRIBE_Player@@QAEEHJ@Z              XREF[1]:     checkTradeBoats:00503454(c)
//                               TRIBE_Player::command_trade_attribute
//                              tplayer.cpp:1220 (26)
//         00513840     MOV        EAX,dword ptr [ESP + param_2]
//         00513844     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         00513848     MOV        this,dword ptr [ECX + this->_padding_]
//         0051384b     PUSH       EAX
//         0051384c     MOV        EAX,dword ptr [ESP + param_1]
//         00513850     PUSH       EDX
//         00513851     MOV        this,dword ptr [ECX + this->_padding_]
//         00513854     PUSH       EAX
//         00513855     CALL       TRIBE_Command::command_trade_attribute           void command_trade_attribute(TRIBE_Command *
//                              tplayer.cpp:1222 (2)
//         0051385a     MOV        AL,0x1
//                              tplayer.cpp:1223 (3)
//         0051385c     RET        0x8
//         0051385f     ??         90h
    return 0;
}

uchar TRIBE_Player::command_attack_ground(float param_1, float param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_attack_ground(TRIBE_Player * this, float pa
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00513863(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     00513872(*), 00513883(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_attack_ground@TRIBE_Player@@QAEEMM@Z                XREF[2]:     mouse_left_up_action:0052d6b9(c),
//                               TRIBE_Player::command_attack_ground                                       mouse_right_up_action:0052da29(c)
//                              tplayer.cpp:1228 (3)
//         00513860     SUB        ESP,0x8
//                              tplayer.cpp:1232 (32)
//         00513863     LEA        EAX=>local_4,[ESP + 0x4]
//         00513867     PUSH       ESI
//         00513868     PUSH       0x4
//         0051386a     MOV        ESI,this
//         0051386c     PUSH       -0x1
//         0051386e     PUSH       -0x1
//         00513870     PUSH       0x4
//         00513872     LEA        this=>list_num,[ESP + 0x14]
//         00513876     PUSH       EAX
//         00513877     PUSH       this
//         00513878     MOV        this,ESI
//         0051387a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0051387f     TEST       AL,AL
//         00513881     JZ         LAB_005138c6
//                              tplayer.cpp:1234 (14)
//         00513883     MOV        EDX,dword ptr [ESP + list_num]
//         00513887     MOV        this,dword ptr [EDX]
//         00513889     MOV        EAX,dword ptr [this->_padding_]
//         0051388b     CALL       dword ptr [EAX + 0xac]
//                              tplayer.cpp:1235 (31)
//         00513891     MOV        this,dword ptr [ESP + 0x14]
//         00513895     MOV        EDX,dword ptr [ESP + 0x10]
//         00513899     MOV        EAX,dword ptr [ESP + 0x8]
//         0051389d     PUSH       this
//         0051389e     MOV        this,dword ptr [ESP + 0x8]
//         005138a2     PUSH       EDX=>DAT_fffffff8
//         005138a3     MOV        EDX,dword ptr [ESI + 0x3c]
//         005138a6     PUSH       EAX=>DAT_fffffff4
//         005138a7     PUSH       this=>DAT_fffffff0
//         005138a8     MOV        this,dword ptr [EDX + 0x58]
//         005138ab     CALL       TRIBE_Command::command_attack_ground             void command_attack_ground(TRIBE_Command * th
//                              tplayer.cpp:1236 (13)
//         005138b0     MOV        EAX,dword ptr [ESP + 0x4]
//         005138b4     PUSH       EAX
//         005138b5     CALL       free                                             undefined free()
//         005138ba     ADD        ESP,0x4
//                              tplayer.cpp:1237 (2)
//         005138bd     MOV        AL,0x1
//                              tplayer.cpp:1241 (7)
//         005138bf     POP        ESI
//         005138c0     ADD        ESP,0x8
//         005138c3     RET        0x8
//                               LAB_005138c6                                                 XREF[1]:     00513881(j)
//                              tplayer.cpp:1240 (2)
//         005138c6     XOR        AL,AL
//                              tplayer.cpp:1241 (7)
//         005138c8     POP        ESI
//         005138c9     ADD        ESP,0x8
//         005138cc     RET        0x8
//         005138cf     ??         90h
    return 0;
}

uchar TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              uchar __thiscall command_give_attribute(TRIBE_Player * this, int par
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00513903(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005138d0(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     005138db(R), 005138fb(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     005138ec(R)
//                               ?command_give_attribute@TRIBE_Player@@UAEEHHMM@Z             XREF[2]:     00576968(*), 00576a98(*)
//                               TRIBE_Player::command_give_attribute
//                              tplayer.cpp:1246 (28)
//         005138d0     MOV        EDX,dword ptr [ESP + param_2]
//         005138d4     PUSH       ESI
//         005138d5     CMP        EDX,-0x1
//         005138d8     PUSH       EDI
//         005138d9     JZ         LAB_00513915
//         005138db     FLD        float ptr [ESP + param_3]
//         005138df     FCOMP      float ptr [DAT_00576828]
//         005138e5     FNSTSW     AX
//         005138e7     TEST       AH,0x40
//         005138ea     JNZ        LAB_00513915
//                              tplayer.cpp:1250 (34)
//         005138ec     MOV        EDI,dword ptr [ESP + param_4]
//         005138f0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005138f3     MOVSX      this,word ptr [ECX + this+0x4a]
//         005138f7     MOV        EAX,dword ptr [EAX + 0x58]
//         005138fa     PUSH       EDI
//         005138fb     MOV        EDI,dword ptr [ESP + param_3]
//         005138ff     MOV        ESI,dword ptr [EAX]
//         00513901     PUSH       EDI
//         00513902     PUSH       EDX
//         00513903     MOV        EDX,dword ptr [ESP + param_1]
//         00513907     PUSH       EDX
//         00513908     PUSH       this
//         00513909     MOV        this,EAX
//         0051390b     CALL       dword ptr [ESI + 0x14]
//                              tplayer.cpp:1251 (2)
//         0051390e     MOV        AL,0x1
//                              tplayer.cpp:1252 (12)
//         00513910     POP        EDI
//         00513911     POP        ESI
//         00513912     RET        0x10
//                               LAB_00513915                                                 XREF[2]:     005138d9(j), 005138ea(j)
//         00513915     POP        EDI
//         00513916     XOR        AL,AL
//         00513918     POP        ESI
//         00513919     RET        0x10
//         0051391c     ??         90h
//         0051391d     NOP
//         0051391e     NOP
//         0051391f     NOP
    return 0;
}

uchar TRIBE_Player::command_building_make_obj(short param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_building_make_obj(TRIBE_Player * this, shor
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00513933(R)
//                               ?command_building_make_obj@TRIBE_Player@@QAEEF@Z             XREF[1]:     command_train:0049cf5a(c)
//                               TRIBE_Player::command_building_make_obj
//                              tplayer.cpp:1258 (19)
//         00513920     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00513926     TEST       EAX,EAX
//         00513928     JZ         LAB_00513949
//         0051392a     MOV        EDX,dword ptr [EAX + 0x8]
//         0051392d     CMP        byte ptr [EDX + 0x4],0x50
//         00513931     JNZ        LAB_00513949
//                              tplayer.cpp:1261 (17)
//         00513933     MOV        EDX,dword ptr [ESP + param_1]
//         00513937     PUSH       EDX
//         00513938     PUSH       EAX
//         00513939     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051393c     MOV        this,dword ptr [EAX + 0x58]
//         0051393f     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tplayer.cpp:1262 (2)
//         00513944     MOV        AL,0x1
//                              tplayer.cpp:1266 (3)
//         00513946     RET        0x4
//                               LAB_00513949                                                 XREF[2]:     00513928(j), 00513931(j)
//                              tplayer.cpp:1265 (2)
//         00513949     XOR        AL,AL
//                              tplayer.cpp:1266 (3)
//         0051394b     RET        0x4
//         0051394e     ??         90h
//         0051394f     NOP
    return 0;
}

uchar TRIBE_Player::command_make_repair(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_repair(TRIBE_Player * this, RGE_Static
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00513954(R)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     0051397d(W), 00513981(R)
//                               ?command_make_repair@TRIBE_Player@@QAEEPAVRGE_Static_Object  XREF[2]:     mouse_left_up_action:0052d866(c),
//                               TRIBE_Player::command_make_repair                                         mouse_right_up_action:0052dbd6(c)
//                              tplayer.cpp:1271 (4)
//         00513950     SUB        ESP,0x8
//         00513953     PUSH       ESI
//                              tplayer.cpp:1280 (65)
//         00513954     MOV        ESI,dword ptr [ESP + param_1]
//         00513958     PUSH       EDI
//         00513959     MOV        EDI,this
//         0051395b     MOV        EAX,dword ptr [ESI + 0xc]
//         0051395e     CMP        EAX,EDI
//         00513960     JZ         LAB_00513970
//         00513962     MOVSX      EAX,word ptr [EAX + 0x4a]
//         00513966     MOV        EDX,dword ptr [EDI]
//         00513968     PUSH       EAX
//         00513969     CALL       dword ptr [EDX + 0x1c]
//         0051396c     TEST       EAX,EAX
//         0051396e     JZ         LAB_00513995
//                               LAB_00513970                                                 XREF[1]:     00513960(j)
//         00513970     MOV        EAX,dword ptr [ESI + 0x8]
//         00513973     CMP        byte ptr [EAX + 0x4],0x50
//         00513977     JNZ        LAB_00513995
//         00513979     MOVSX      this,word ptr [EAX + 0x26]
//         0051397d     MOV        dword ptr [ESP + list_num],this
//         00513981     FILD       dword ptr [ESP + list_num]
//         00513985     FCOMP      float ptr [ESI + 0x30]
//         00513988     FNSTSW     AX
//         0051398a     TEST       AH,0x41
//         0051398d     JNZ        LAB_00513995
//         0051398f     CMP        byte ptr [ESI + 0x48],0x3
//         00513993     JC         LAB_00513a04
//                               LAB_00513995                                                 XREF[3]:     0051396e(j), 00513977(j),
//                                                                                                         0051398d(j)
//                              tplayer.cpp:1288 (111)
//         00513995     MOV        EAX,dword ptr [ESI + 0xc]
//         00513998     CMP        EAX,EDI
//         0051399a     JZ         LAB_005139c5
//         0051399c     MOVSX      EAX,word ptr [EAX + 0x4a]
//         005139a0     MOV        EDX,dword ptr [EDI]
//         005139a2     PUSH       EAX
//         005139a3     MOV        this,EDI
//         005139a5     CALL       dword ptr [EDX + 0x1c]
//         005139a8     TEST       EAX,EAX
//         005139aa     JZ         LAB_00513a6e
//         005139b0     MOV        this,dword ptr [ESI + 0xc]
//         005139b3     MOVSX      EAX,word ptr [EDI + 0x4a]
//         005139b7     MOV        EDX,dword ptr [this->_padding_]
//         005139b9     PUSH       EAX
//         005139ba     CALL       dword ptr [EDX + 0x1c]
//         005139bd     TEST       EAX,EAX
//         005139bf     JZ         LAB_00513a6e
//                               LAB_005139c5                                                 XREF[1]:     0051399a(j)
//         005139c5     MOV        this,dword ptr [ESI + 0x8]
//         005139c8     MOV        AX,word ptr [ECX + this->_padding_]
//         005139cc     CMP        AX,0x2
//         005139d0     JZ         LAB_005139e8
//         005139d2     CMP        AX,0x14
//         005139d6     JZ         LAB_005139e8
//         005139d8     CMP        AX,0x15
//         005139dc     JZ         LAB_005139e8
//         005139de     CMP        AX,0x16
//         005139e2     JNZ        LAB_00513a6e
//                               LAB_005139e8                                                 XREF[3]:     005139d0(j), 005139d6(j),
//                                                                                                         005139dc(j)
//         005139e8     MOVSX      this,word ptr [ECX + this+0x26]
//         005139ec     MOV        dword ptr [ESP + 0x8],this
//         005139f0     FILD       dword ptr [ESP + 0x8]
//         005139f4     FCOMP      float ptr [ESI + 0x30]
//         005139f7     FNSTSW     AX
//         005139f9     TEST       AH,0x41
//         005139fc     JNZ        LAB_00513a6e
//         005139fe     CMP        byte ptr [ESI + 0x48],0x3
//         00513a02     JNC        LAB_00513a6e
//                               LAB_00513a04                                                 XREF[1]:     00513993(j)
//                              tplayer.cpp:1293 (29)
//         00513a04     PUSH       -0x1
//         00513a06     PUSH       offset DAT_fffffff8
//         00513a08     PUSH       offset DAT_fffffff4
//         00513a0a     LEA        EDX,[ESP + 0x18]
//         00513a0e     PUSH       offset DAT_fffffff0
//         00513a10     LEA        EAX,[ESP + 0x24]
//         00513a14     PUSH       EDX
//         00513a15     PUSH       EAX
//         00513a16     MOV        this,EDI
//         00513a18     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00513a1d     TEST       AL,AL
//         00513a1f     JZ         LAB_00513a6e
//                              tplayer.cpp:1295 (21)
//         00513a21     MOV        this,dword ptr [ESP + 0x14]
//         00513a25     PUSH       0x0
//         00513a27     PUSH       0x0=>DAT_fffffff8
//         00513a29     PUSH       0x0=>DAT_fffffff4
//         00513a2b     MOV        this,dword ptr [this->_padding_]
//         00513a2d     PUSH       ESI=>DAT_fffffff0
//         00513a2e     MOV        EDX,dword ptr [this->_padding_]
//         00513a30     CALL       dword ptr [EDX + 0xbc]
//                              tplayer.cpp:1296 (4)
//         00513a36     TEST       EAX,EAX
//         00513a38     JZ         LAB_00513a41
//                              tplayer.cpp:1297 (7)
//         00513a3a     MOV        EDX,dword ptr [EAX]
//         00513a3c     MOV        this,EAX
//         00513a3e     CALL       dword ptr [EDX + 0x2c]
//                               LAB_00513a41                                                 XREF[1]:     00513a38(j)
//                              tplayer.cpp:1299 (22)
//         00513a41     MOV        EAX,dword ptr [ESP + 0xc]
//         00513a45     MOV        this,dword ptr [ESP + 0x14]
//         00513a49     MOV        EDX,dword ptr [EDI + 0x3c]
//         00513a4c     PUSH       ESI
//         00513a4d     PUSH       EAX=>DAT_fffffff8
//         00513a4e     PUSH       this=>DAT_fffffff4
//         00513a4f     MOV        this,dword ptr [EDX + 0x58]
//         00513a52     CALL       TRIBE_Command::command_repair                    void command_repair(TRIBE_Command * this, RGE
//                              tplayer.cpp:1300 (13)
//         00513a57     MOV        EAX,dword ptr [ESP + 0x14]
//         00513a5b     PUSH       EAX
//         00513a5c     CALL       free                                             undefined free()
//         00513a61     ADD        ESP,0x4
//                              tplayer.cpp:1301 (2)
//         00513a64     MOV        AL,0x1
//                              tplayer.cpp:1305 (18)
//         00513a66     POP        EDI
//         00513a67     POP        ESI
//         00513a68     ADD        ESP,0x8
//         00513a6b     RET        0x4
//                               LAB_00513a6e                                                 XREF[6]:     005139aa(j), 005139bf(j),
//                                                                                                         005139e2(j), 005139fc(j),
//                                                                                                         00513a02(j), 00513a1f(j)
//         00513a6e     POP        EDI
//         00513a6f     XOR        AL,AL
//         00513a71     POP        ESI
//         00513a72     ADD        ESP,0x8
//         00513a75     RET        0x4
//         00513a78     ??         90h
//         00513a79     NOP
//         00513a7a     NOP
//         00513a7b     NOP
//         00513a7c     NOP
//         00513a7d     NOP
//         00513a7e     NOP
//         00513a7f     NOP
    return 0;
}

uchar TRIBE_Player::command_make_unload(float param_1, float param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_unload(TRIBE_Player * this, float para
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00513a83(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     00513a92(*), 00513aa3(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_make_unload@TRIBE_Player@@QAEEMM@Z                  XREF[2]:     mouse_left_up_action:0052d8f7(c),
//                               TRIBE_Player::command_make_unload                                         mouse_right_up_action:0052dc67(c)
//                              tplayer.cpp:1310 (3)
//         00513a80     SUB        ESP,0x8
//                              tplayer.cpp:1314 (32)
//         00513a83     LEA        EAX=>local_4,[ESP + 0x4]
//         00513a87     PUSH       ESI
//         00513a88     PUSH       0x7
//         00513a8a     MOV        ESI,this
//         00513a8c     PUSH       -0x1
//         00513a8e     PUSH       -0x1
//         00513a90     PUSH       0x4
//         00513a92     LEA        this=>list_num,[ESP + 0x14]
//         00513a96     PUSH       EAX
//         00513a97     PUSH       this
//         00513a98     MOV        this,ESI
//         00513a9a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00513a9f     TEST       AL,AL
//         00513aa1     JZ         LAB_00513ae6
//                              tplayer.cpp:1316 (14)
//         00513aa3     MOV        EDX,dword ptr [ESP + list_num]
//         00513aa7     MOV        this,dword ptr [EDX]
//         00513aa9     MOV        EAX,dword ptr [this->_padding_]
//         00513aab     CALL       dword ptr [EAX + 0xac]
//                              tplayer.cpp:1317 (31)
//         00513ab1     MOV        this,dword ptr [ESP + 0x14]
//         00513ab5     MOV        EDX,dword ptr [ESP + 0x10]
//         00513ab9     MOV        EAX,dword ptr [ESP + 0x8]
//         00513abd     PUSH       this
//         00513abe     MOV        this,dword ptr [ESP + 0x8]
//         00513ac2     PUSH       EDX=>DAT_fffffff8
//         00513ac3     MOV        EDX,dword ptr [ESI + 0x3c]
//         00513ac6     PUSH       EAX=>DAT_fffffff4
//         00513ac7     PUSH       this=>DAT_fffffff0
//         00513ac8     MOV        this,dword ptr [EDX + 0x58]
//         00513acb     CALL       TRIBE_Command::command_unload                    void command_unload(TRIBE_Command * this, RGE
//                              tplayer.cpp:1318 (13)
//         00513ad0     MOV        EAX,dword ptr [ESP + 0x4]
//         00513ad4     PUSH       EAX
//         00513ad5     CALL       free                                             undefined free()
//         00513ada     ADD        ESP,0x4
//                              tplayer.cpp:1319 (2)
//         00513add     MOV        AL,0x1
//                              tplayer.cpp:1323 (7)
//         00513adf     POP        ESI
//         00513ae0     ADD        ESP,0x8
//         00513ae3     RET        0x8
//                               LAB_00513ae6                                                 XREF[1]:     00513aa1(j)
//                              tplayer.cpp:1322 (2)
//         00513ae6     XOR        AL,AL
//                              tplayer.cpp:1323 (7)
//         00513ae8     POP        ESI
//         00513ae9     ADD        ESP,0x8
//         00513aec     RET        0x8
//         00513aef     ??         90h
    return 0;
}

uchar TRIBE_Player::check_obj_cost(short param_1, short* param_2, float param_3, int param_4) {
    /* TODO: Stub */
//                              uchar __thiscall check_obj_cost(TRIBE_Player * this, short param_1,
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[8]:     00513b2e(R), 00513b66(W), 00513b6d(R), 00513b75(W),
//                                                                                     00513b9c(R), 00513bb0(R), 00513bd0(R), 00513bdb(R)
//              short *           Stack[0x8]:4   param_2                   XREF[4]:     00513af4(R), 00513b22(W), 00513b29(W), 00513b8f(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00513b71(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00513b4b(R)
//                               ?check_obj_cost@TRIBE_Player@@QAEEFPAFMH@Z                   XREF[8]:     command_building:0049bded(c),
//                               TRIBE_Player::check_obj_cost                                              command_train:0049cf37(c),
//                                                                                                         add_to_production_queue:004c98bf(c
//                                                                                                         add_to_production_queue:004c9987(c
//                                                                                                         add_to_production_queue:004c9a6f(c
//                                                                                                         canRepair:004cc599(c),
//                                                                                                         obj_cost:00512c77(c),
//                                                                                                         pay_obj_cost:00513c66(c)
//                              tplayer.cpp:1327 (4)
//         00513af0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00513af3     PUSH       EBX
//                              tplayer.cpp:1335 (14)
//         00513af4     MOV        EBX,dword ptr [ESP + param_2]
//         00513af8     PUSH       EBP
//         00513af9     FLD        float ptr [EAX + 0xc]
//         00513afc     PUSH       ESI
//         00513afd     PUSH       EDI
//         00513afe     TEST       EBX,EBX
//         00513b00     JZ         LAB_00513b07
//                              tplayer.cpp:1336 (5)
//         00513b02     MOV        word ptr [EBX],0xffff
//                               LAB_00513b07                                                 XREF[1]:     00513b00(j)
//                              tplayer.cpp:1339 (21)
//         00513b07     MOV        ESI,dword ptr [ECX + this->_padding_]
//         00513b0a     FLD        float ptr [ESI + 0x74]
//         00513b0d     FCOMP      double ptr [DAT_00576860]
//         00513b13     FNSTSW     AX
//         00513b15     TEST       AH,0x1
//         00513b18     JZ         LAB_00513b29
//         00513b1a     FSTP       ST0
//                              tplayer.cpp:1341 (6)
//         00513b1c     FLD        float ptr [DAT_00576828]
//                              tplayer.cpp:1342 (5)
//         00513b22     MOV        byte ptr [ESP + param_2],0x0
//                              tplayer.cpp:1344 (2)
//         00513b27     JMP        LAB_00513b2e
//                               LAB_00513b29                                                 XREF[1]:     00513b18(j)
//                              tplayer.cpp:1345 (5)
//         00513b29     MOV        byte ptr [ESP + param_2],0x1
//                               LAB_00513b2e                                                 XREF[1]:     00513b27(j)
//                              tplayer.cpp:1347 (29)
//         00513b2e     MOVSX      EDX,word ptr [ESP + param_1]
//         00513b33     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00513b36     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00513b39     TEST       EAX,EAX
//         00513b3b     JZ         LAB_00513c36
//         00513b41     CMP        byte ptr [EAX + 0x4],0x46
//         00513b45     JC         LAB_00513c36
//                              tplayer.cpp:1406 (48)
//         00513b4b     MOV        EBP,dword ptr [ESP + param_4]
//         00513b4f     XOR        EDI,EDI
//         00513b51     LEA        EDX,[EAX + 0x14a]
//                               LAB_00513b57                                                 XREF[1]:     00513beb(j)
//         00513b57     MOVSX      this,word ptr [EDX + -0x2]
//         00513b5b     TEST       this,this
//         00513b5d     JL         LAB_00513be4
//         00513b63     MOVSX      EAX,word ptr [EDX]
//         00513b66     MOV        dword ptr [ESP + param_1],EAX
//         00513b6a     CMP        this,0x4
//         00513b6d     FILD       dword ptr [ESP + param_1]
//         00513b71     FMUL       float ptr [ESP + param_3]
//         00513b75     FSTP       float ptr [ESP + param_1]
//         00513b79     JNZ        LAB_00513b8f
//                              tplayer.cpp:1362 (4)
//         00513b7b     TEST       EBP,EBP
//         00513b7d     JNZ        LAB_00513b8f
//                              tplayer.cpp:1363 (16)
//         00513b7f     FLD        float ptr [ESI + 0x2c]
//         00513b82     FCOMP      float ptr [ESI + 0x80]
//         00513b88     FNSTSW     AX
//         00513b8a     TEST       AH,0x1
//         00513b8d     JZ         LAB_00513bfc
//                               LAB_00513b8f                                                 XREF[2]:     00513b79(j), 00513b7d(j)
//                              tplayer.cpp:1371 (13)
//         00513b8f     MOV        AL,byte ptr [ESP + param_2]
//         00513b93     TEST       AL,AL
//         00513b95     JZ         LAB_00513bad
//         00513b97     CMP        this,0x3
//         00513b9a     JNZ        LAB_00513bad
//                              tplayer.cpp:1373 (4)
//         00513b9c     FSUB       float ptr [ESP + param_1]
//                              tplayer.cpp:1374 (13)
//         00513ba0     FCOM       float ptr [DAT_00576828]
//         00513ba6     FNSTSW     AX
//         00513ba8     TEST       AH,0x1
//         00513bab     JNZ        LAB_00513c10
//                               LAB_00513bad                                                 XREF[2]:     00513b95(j), 00513b9a(j)
//                              tplayer.cpp:1383 (23)
//         00513bad     FLD        float ptr [ESI + this->_padding_*0x4]
//         00513bb0     FCOMP      float ptr [ESP + param_1]
//         00513bb4     FNSTSW     AX
//         00513bb6     TEST       AH,0x1
//         00513bb9     JZ         LAB_00513be4
//         00513bbb     CMP        this,0x4
//         00513bbe     JNZ        LAB_00513bc4
//         00513bc0     TEST       EBP,EBP
//         00513bc2     JNZ        LAB_00513be4
//                               LAB_00513bc4                                                 XREF[1]:     00513bbe(j)
//                              tplayer.cpp:1386 (23)
//         00513bc4     MOV        AL,byte ptr [EDX + 0x2]
//         00513bc7     TEST       AL,AL
//         00513bc9     JZ         LAB_00513c24
//         00513bcb     FLD        ST0
//         00513bcd     FADD       float ptr [ESI + this->_padding_*0x4]
//         00513bd0     FCOMP      float ptr [ESP + param_1]
//         00513bd4     FNSTSW     AX
//         00513bd6     TEST       AH,0x1
//         00513bd9     JNZ        LAB_00513c24
//                              tplayer.cpp:1395 (24)
//         00513bdb     FLD        float ptr [ESP + param_1]
//         00513bdf     FSUB       float ptr [ESI + this->_padding_*0x4]
//         00513be2     FSUBP
//                               LAB_00513be4                                                 XREF[3]:     00513b5d(j), 00513bb9(j),
//                                                                                                         00513bc2(j)
//         00513be4     INC        EDI
//         00513be5     ADD        EDX,0x6
//         00513be8     CMP        EDI,0x3
//         00513beb     JL         LAB_00513b57
//         00513bf1     FSTP       ST0
//                              tplayer.cpp:1400 (2)
//         00513bf3     MOV        AL,0x1
//                              tplayer.cpp:1406 (7)
//         00513bf5     POP        EDI
//         00513bf6     POP        ESI
//         00513bf7     POP        EBP
//         00513bf8     POP        EBX
//         00513bf9     RET        0x10
//                               LAB_00513bfc                                                 XREF[1]:     00513b8d(j)
//                              tplayer.cpp:1365 (6)
//         00513bfc     TEST       EBX,EBX
//         00513bfe     FSTP       ST0
//         00513c00     JZ         LAB_00513c41
//                              tplayer.cpp:1366 (5)
//         00513c02     MOV        word ptr [EBX],0x20
//                              tplayer.cpp:1405 (2)
//         00513c07     XOR        AL,AL
//                              tplayer.cpp:1406 (7)
//         00513c09     POP        EDI
//         00513c0a     POP        ESI
//         00513c0b     POP        EBP
//         00513c0c     POP        EBX
//         00513c0d     RET        0x10
//                               LAB_00513c10                                                 XREF[1]:     00513bab(j)
//                              tplayer.cpp:1376 (6)
//         00513c10     TEST       EBX,EBX
//         00513c12     FSTP       ST0
//         00513c14     JZ         LAB_00513c41
//                              tplayer.cpp:1377 (5)
//         00513c16     MOV        word ptr [EBX],0x3
//                              tplayer.cpp:1405 (2)
//         00513c1b     XOR        AL,AL
//                              tplayer.cpp:1406 (7)
//         00513c1d     POP        EDI
//         00513c1e     POP        ESI
//         00513c1f     POP        EBP
//         00513c20     POP        EBX
//         00513c21     RET        0x10
//                               LAB_00513c24                                                 XREF[2]:     00513bc9(j), 00513bd9(j)
//                              tplayer.cpp:1389 (6)
//         00513c24     TEST       EBX,EBX
//         00513c26     FSTP       ST0
//         00513c28     JZ         LAB_00513c41
//                              tplayer.cpp:1390 (3)
//         00513c2a     MOV        word ptr [EBX],this
//                              tplayer.cpp:1405 (2)
//         00513c2d     XOR        AL,AL
//                              tplayer.cpp:1406 (7)
//         00513c2f     POP        EDI
//         00513c30     POP        ESI
//         00513c31     POP        EBP
//         00513c32     POP        EBX
//         00513c33     RET        0x10
//                               LAB_00513c36                                                 XREF[2]:     00513b3b(j), 00513b45(j)
//                              tplayer.cpp:1403 (6)
//         00513c36     TEST       EBX,EBX
//         00513c38     FSTP       ST0
//         00513c3a     JZ         LAB_00513c41
//                              tplayer.cpp:1404 (5)
//         00513c3c     MOV        word ptr [EBX],0xffff
//                               LAB_00513c41                                                 XREF[4]:     00513c00(j), 00513c14(j),
//                                                                                                         00513c28(j), 00513c3a(j)
//                              tplayer.cpp:1406 (9)
//         00513c41     POP        EDI
//         00513c42     POP        ESI
//         00513c43     POP        EBP
//         00513c44     XOR        AL,AL
//         00513c46     POP        EBX
//         00513c47     RET        0x10
//         00513c4a     ??         90h
//         00513c4b     NOP
//         00513c4c     NOP
//         00513c4d     NOP
//         00513c4e     NOP
//         00513c4f     NOP
    return 0;
}

uchar TRIBE_Player::pay_obj_cost(short param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              uchar __thiscall pay_obj_cost(TRIBE_Player * this, short param_1, fl
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00513c5a(R)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     00513c50(R), 00513cb0(R)
//              int               Stack[0xc]:4   param_3                   XREF[3]:     00513c55(R), 00513c9e(W), 00513ca5(R)
//                               ?pay_obj_cost@TRIBE_Player@@QAEEFMH@Z                        XREF[7]:     heal:004c871f(c),
//                               TRIBE_Player::pay_obj_cost                                                add_to_production_queue:004c98d3(c
//                                                                                                         add_to_production_queue:004c9a83(c
//                                                                                                         heal:004cc54c(c),
//                                                                                                         first_in_stack:004d105a(c),
//                                                                                                         do_command_build:00509d3d(c),
//                                                                                                         place_line_of_walls:0050a0cb(c)
//                              tplayer.cpp:1410 (31)
//         00513c50     MOV        EAX,dword ptr [ESP + param_2]
//         00513c54     PUSH       EBP
//         00513c55     MOV        EBP,dword ptr [ESP + param_3]
//         00513c59     PUSH       ESI
//         00513c5a     MOV        ESI,dword ptr [ESP + param_1]
//         00513c5e     PUSH       EDI
//         00513c5f     PUSH       EBP
//         00513c60     PUSH       EAX
//         00513c61     PUSH       0x0
//         00513c63     MOV        EDI,this
//         00513c65     PUSH       ESI
//         00513c66     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
//         00513c6b     TEST       AL,AL
//         00513c6d     JZ         LAB_00513cec
//                              tplayer.cpp:1418 (21)
//         00513c6f     MOV        EDX,dword ptr [EDI + 0x24]
//         00513c72     PUSH       EBX
//         00513c73     MOVSX      this,SI
//         00513c76     MOV        EBX,0x3
//         00513c7b     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         00513c7e     LEA        ESI,[EAX + 0x14c]
//                               LAB_00513c84                                                 XREF[1]:     00513ce1(j)
//                              tplayer.cpp:1424 (4)
//         00513c84     MOVSX      EAX,word ptr [ESI + -0x4]
//                              tplayer.cpp:1425 (18)
//         00513c88     TEST       EAX,EAX
//         00513c8a     JL         LAB_00513cdd
//         00513c8c     CMP        byte ptr [ESI],0x0
//         00513c8f     JZ         LAB_00513cdd
//         00513c91     TEST       EBP,EBP
//         00513c93     JZ         LAB_00513c9a
//         00513c95     CMP        EAX,0x4
//         00513c98     JZ         LAB_00513cdd
//                               LAB_00513c9a                                                 XREF[1]:     00513c93(j)
//                              tplayer.cpp:1428 (8)
//         00513c9a     MOVSX      this,word ptr [ESI + -0x2]
//         00513c9e     MOV        dword ptr [ESP + param_3],this
//                              tplayer.cpp:1431 (28)
//         00513ca2     MOV        this,dword ptr [EDI + 0x50]
//         00513ca5     FILD       dword ptr [ESP + param_3]
//         00513ca9     LEA        EDX,[EAX*0x4 + 0x0]
//         00513cb0     FMUL       float ptr [ESP + param_2]
//         00513cb4     FCOM       float ptr [this->_padding_ + EDX*0x1]
//         00513cb7     FNSTSW     AX
//         00513cb9     TEST       AH,0x41
//         00513cbc     JNZ        LAB_00513cd3
//                              tplayer.cpp:1433 (9)
//         00513cbe     FSUB       float ptr [this->_padding_ + EDX*0x1]
//         00513cc1     FSUBR      float ptr [ECX + this->_padding_]
//         00513cc4     FSTP       float ptr [ECX + this->_padding_]
//                              tplayer.cpp:1434 (10)
//         00513cc7     MOV        EAX,dword ptr [EDI + 0x50]
//         00513cca     MOV        dword ptr [EAX + EDX*0x1],0x0
//                              tplayer.cpp:1436 (2)
//         00513cd1     JMP        LAB_00513cdd
//                               LAB_00513cd3                                                 XREF[1]:     00513cbc(j)
//                              tplayer.cpp:1437 (16)
//         00513cd3     FLD        float ptr [this->_padding_ + EDX*0x1]
//         00513cd6     FSUB       ST0,ST1
//         00513cd8     FSTP       float ptr [this->_padding_ + EDX*0x1]
//         00513cdb     FSTP       ST0
//                               LAB_00513cdd                                                 XREF[4]:     00513c8a(j), 00513c8f(j),
//                                                                                                         00513c98(j), 00513cd1(j)
//         00513cdd     ADD        ESI,0x6
//         00513ce0     DEC        EBX
//         00513ce1     JNZ        LAB_00513c84
//                              tplayer.cpp:1441 (2)
//         00513ce3     MOV        AL,0x1
//                              tplayer.cpp:1410 (1)
//         00513ce5     POP        EBX
//                              tplayer.cpp:1445 (14)
//         00513ce6     POP        EDI
//         00513ce7     POP        ESI
//         00513ce8     POP        EBP
//         00513ce9     RET        0xc
//                               LAB_00513cec                                                 XREF[1]:     00513c6d(j)
//         00513cec     POP        EDI
//         00513ced     POP        ESI
//         00513cee     XOR        AL,AL
//         00513cf0     POP        EBP
//         00513cf1     RET        0xc
//         00513cf4     ??         90h
//         00513cf5     NOP
//         00513cf6     NOP
//         00513cf7     NOP
//         00513cf8     NOP
//         00513cf9     NOP
//         00513cfa     NOP
//         00513cfb     NOP
//         00513cfc     NOP
//         00513cfd     NOP
//         00513cfe     NOP
//         00513cff     NOP
    return 0;
}

void TRIBE_Player::reimburse_obj_cost(short param_1) {
    /* TODO: Stub */
//                              void __thiscall reimburse_obj_cost(TRIBE_Player * this, short param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[3]:     00513d00(R), 00513d3a(W), 00513d3e(R)
//                               ?reimburse_obj_cost@TRIBE_Player@@QAEXF@Z                    XREF[3]:     remove_from_production_queue:004c9
//                               TRIBE_Player::reimburse_obj_cost                                          update:004d1197(c),
//                                                                                                         stop:004d159a(c)
//                              tplayer.cpp:1465 (20)
//         00513d00     MOVSX      EAX,word ptr [ESP + param_1]
//         00513d05     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00513d08     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         00513d0b     CMP        byte ptr [EAX + 0x4],0x46
//         00513d0f     JC         LAB_00513d4f
//         00513d11     PUSH       EDI
//         00513d12     PUSH       ESI
//         00513d13     PUSH       EBX
//                              tplayer.cpp:1478 (62)
//         00513d14     ADD        EAX,0x148
//         00513d19     MOV        ESI,0x3
//                               LAB_00513d1e                                                 XREF[1]:     00513d4a(j)
//         00513d1e     MOV        DX,word ptr [EAX]
//         00513d21     TEST       DX,DX
//         00513d24     JL         LAB_00513d46
//         00513d26     MOV        BL,byte ptr [EAX + 0x4]
//         00513d29     TEST       BL,BL
//         00513d2b     JZ         LAB_00513d46
//         00513d2d     MOV        EDI,dword ptr [ECX + this->_padding_]
//         00513d30     MOVSX      EDX,DX
//         00513d33     LEA        EDX,[EDI + EDX*0x4]
//         00513d36     MOVSX      EDI,word ptr [EAX + 0x2]
//         00513d3a     MOV        dword ptr [ESP + param_1],EDI
//         00513d3e     FILD       dword ptr [ESP + param_1]
//         00513d42     FADD       float ptr [EDX]
//         00513d44     FSTP       float ptr [EDX]
//                               LAB_00513d46                                                 XREF[2]:     00513d24(j), 00513d2b(j)
//         00513d46     ADD        EAX,0x6
//         00513d49     DEC        ESI
//         00513d4a     JNZ        LAB_00513d1e
//         00513d4c     POP        EBX
//         00513d4d     POP        ESI
//         00513d4e     POP        EDI
//                               LAB_00513d4f                                                 XREF[1]:     00513d0f(j)
//         00513d4f     RET        0x4
//         00513d52     ??         90h
//         00513d53     NOP
//         00513d54     NOP
//         00513d55     NOP
//         00513d56     NOP
//         00513d57     NOP
//         00513d58     NOP
//         00513d59     NOP
//         00513d5a     NOP
//         00513d5b     NOP
//         00513d5c     NOP
//         00513d5d     NOP
//         00513d5e     NOP
//         00513d5f     NOP
    return;
}

uchar TRIBE_Player::check_tech_cost(short param_1, short* param_2) {
    /* TODO: Stub */
//                              uchar __thiscall check_tech_cost(TRIBE_Player * this, short param_1,
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00513d64(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00513d60(R)
//                               ?check_tech_cost@TRIBE_Player@@QAEEFPAF@Z                    XREF[1]:     command_research:0049cb23(c)
//                               TRIBE_Player::check_tech_cost
//                              tplayer.cpp:1482 (21)
//         00513d60     MOV        EAX,dword ptr [ESP + param_2]
//         00513d64     MOV        EDX,dword ptr [ESP + param_1]
//         00513d68     MOV        this,dword ptr [ECX + this->tech_tree]
//         00513d6e     PUSH       EAX
//         00513d6f     PUSH       EDX
//         00513d70     CALL       TRIBE_Player_Tech::check_tech_cost               uchar check_tech_cost(TRIBE_Player_Tech * thi
//                              tplayer.cpp:1485 (3)
//         00513d75     RET        0x8
//         00513d78     ??         90h
//         00513d79     NOP
//         00513d7a     NOP
//         00513d7b     NOP
//         00513d7c     NOP
//         00513d7d     NOP
//         00513d7e     NOP
//         00513d7f     NOP
    return 0;
}

uchar TRIBE_Player::pay_tech_cost(short param_1) {
    /* TODO: Stub */
//                              uchar __thiscall pay_tech_cost(TRIBE_Player * this, short param_1)
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00513d80(R)
//                               ?pay_tech_cost@TRIBE_Player@@QAEEF@Z
//                               TRIBE_Player::pay_tech_cost
//                              tplayer.cpp:1489 (20)
//         00513d80     MOV        EAX,dword ptr [ESP + param_1]
//         00513d84     MOV        this,dword ptr [ECX + this->tech_tree]
//         00513d8a     PUSH       0x0
//         00513d8c     PUSH       0x1
//         00513d8e     PUSH       EAX
//         00513d8f     CALL       TRIBE_Player_Tech::start_research                uchar start_research(TRIBE_Player_Tech * this
//                              tplayer.cpp:1491 (3)
//         00513d94     RET        0x4
//         00513d97     ??         90h
//         00513d98     NOP
//         00513d99     NOP
//         00513d9a     NOP
//         00513d9b     NOP
//         00513d9c     NOP
//         00513d9d     NOP
//         00513d9e     NOP
//         00513d9f     NOP
    return 0;
}

void TRIBE_Player::tech_abling(long param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall tech_abling(TRIBE_Player * this, long param_1, uchar
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00513da8(R), 00513dbb(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00513da0(R)
//                               ?tech_abling@TRIBE_Player@@QAEXJE@Z                          XREF[34]:    do_effect:0050d521(c),
//                               TRIBE_Player::tech_abling                                                 do_tech_effect:0050d592(c),
//                                                                                                         WriteDisabledTechnologiesToMainSys
//                                                                                                         WriteDisabledTechnologiesToMainSys
//                                                                                                         WriteDisabledTechnologiesToMainSys
//                                                                                                         set_player_tech:0052c25a(c),
//                                                                                                         set_player_tech:0052c26a(c),
//                                                                                                         set_player_tech:0052c27a(c),
//                                                                                                         set_player_tech:0052c28a(c),
//                                                                                                         set_player_tech:0052c29a(c),
//                                                                                                         set_player_tech:0052c2aa(c),
//                                                                                                         set_player_tech:0052c2ba(c),
//                                                                                                         set_player_tech:0052c2ca(c),
//                                                                                                         set_player_tech:0052c2da(c),
//                                                                                                         set_player_tech:0052c2ea(c),
//                                                                                                         set_player_tech:0052c2fa(c),
//                                                                                                         set_player_tech:0052c30a(c),
//                                                                                                         set_player_tech:0052c31a(c),
//                                                                                                         set_player_tech:0052c32a(c),
//                                                                                                         set_player_tech:0052c33a(c), [more]
//                              tplayer.cpp:1496 (8)
//         00513da0     MOV        AL,byte ptr [ESP + param_2]
//         00513da4     TEST       AL,AL
//         00513da6     JZ         LAB_00513dbb
//                              tplayer.cpp:1498 (16)
//         00513da8     MOV        EAX,dword ptr [ESP + param_1]
//         00513dac     MOV        this,dword ptr [ECX + this->tech_tree]
//         00513db2     PUSH       EAX
//         00513db3     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1501 (3)
//         00513db8     RET        0x8
//                               LAB_00513dbb                                                 XREF[1]:     00513da6(j)
//                              tplayer.cpp:1500 (16)
//         00513dbb     MOV        EDX,dword ptr [ESP + param_1]
//         00513dbf     MOV        this,dword ptr [ECX + this->tech_tree]
//         00513dc5     PUSH       EDX
//         00513dc6     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1501 (3)
//         00513dcb     RET        0x8
//         00513dce     ??         90h
//         00513dcf     NOP
    return;
}

void TRIBE_Player::rev_tech(long param_1) {
    /* TODO: Stub */
//                              void __thiscall rev_tech(TRIBE_Player * this, long param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00513dd0(R)
//                               ?rev_tech@TRIBE_Player@@QAEXJ@Z                              XREF[4]:     set_player_tech:0052c3a7(c),
//                               TRIBE_Player::rev_tech                                                    new_game:0052ff13(c),
//                                                                                                         new_game:0052ff33(c),
//                                                                                                         new_game:0052ff53(c)
//                              tplayer.cpp:1505 (32)
//         00513dd0     MOV        EAX,dword ptr [ESP + param_1]
//         00513dd4     PUSH       ESI
//         00513dd5     DEC        EAX
//         00513dd6     MOV        ESI,this
//         00513dd8     CMP        EAX,0x18
//         00513ddb     JA         switchD_00513de9::caseD_2
//         00513de1     XOR        this,this
//         00513de3     MOV        this,byte ptr [EAX + 0x513fac]=>PTR_caseD_2_00
//                               switchD_00513de9::switchD
//         00513de9     JMP        dword ptr [this->_padding_*0x4 + switchD_00513   = 00513ef0
//                               switchD_00513de9::caseD_19                                   XREF[2]:     00513de9(j), 00513fa4(*)
//                              tplayer.cpp:1509 (6)
//         00513df0     MOV        EDX,dword ptr [ESI + 0x50]
//         00513df3     FLD        float ptr [EDX + 0x64]
//                              tplayer.cpp:1510 (5)
//         00513df6     JMP        LAB_00513edb
//                               switchD_00513de9::caseD_17                                   XREF[2]:     00513de9(j), 00513f9c(*)
//                              tplayer.cpp:1514 (23)
//         00513dfb     MOV        EAX,dword ptr [ESI + 0x50]
//         00513dfe     FLD        float ptr [EAX + 0x5c]
//         00513e01     CALL       __ftol                                           undefined __ftol()
//         00513e06     MOV        this,dword ptr [ESI + 0x220]
//         00513e0c     PUSH       EAX
//         00513e0d     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1515 (23)
//         00513e12     MOV        this,dword ptr [ESI + 0x50]
//         00513e15     FLD        float ptr [ECX + this->_padding_]
//         00513e18     CALL       __ftol                                           undefined __ftol()
//         00513e1d     MOV        this,dword ptr [ESI + 0x220]
//         00513e23     PUSH       EAX
//         00513e24     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1517 (23)
//         00513e29     MOV        EDX,dword ptr [ESI + 0x50]
//         00513e2c     FLD        float ptr [EDX + 0x5c]
//         00513e2f     CALL       __ftol                                           undefined __ftol()
//         00513e34     MOV        this,dword ptr [ESI + 0x220]
//         00513e3a     PUSH       EAX
//         00513e3b     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1518 (6)
//         00513e40     MOV        EAX,dword ptr [ESI + 0x50]
//         00513e43     FLD        float ptr [EAX + 0x5c]
//                              tplayer.cpp:1519 (5)
//         00513e46     JMP        LAB_00513edb
//                               switchD_00513de9::caseD_18                                   XREF[2]:     00513de9(j), 00513fa0(*)
//                              tplayer.cpp:1524 (23)
//         00513e4b     MOV        this,dword ptr [ESI + 0x50]
//         00513e4e     FLD        float ptr [ECX + this->_padding_]
//         00513e51     CALL       __ftol                                           undefined __ftol()
//         00513e56     MOV        this,dword ptr [ESI + 0x220]
//         00513e5c     PUSH       EAX
//         00513e5d     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1525 (23)
//         00513e62     MOV        EDX,dword ptr [ESI + 0x50]
//         00513e65     FLD        float ptr [EDX + 0x60]
//         00513e68     CALL       __ftol                                           undefined __ftol()
//         00513e6d     MOV        this,dword ptr [ESI + 0x220]
//         00513e73     PUSH       EAX
//         00513e74     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1526 (23)
//         00513e79     MOV        EAX,dword ptr [ESI + 0x50]
//         00513e7c     FLD        float ptr [EAX + 0x64]
//         00513e7f     CALL       __ftol                                           undefined __ftol()
//         00513e84     MOV        this,dword ptr [ESI + 0x220]
//         00513e8a     PUSH       EAX
//         00513e8b     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1528 (23)
//         00513e90     MOV        this,dword ptr [ESI + 0x50]
//         00513e93     FLD        float ptr [ECX + this->_padding_]
//         00513e96     CALL       __ftol                                           undefined __ftol()
//         00513e9b     MOV        this,dword ptr [ESI + 0x220]
//         00513ea1     PUSH       EAX
//         00513ea2     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1529 (23)
//         00513ea7     MOV        EDX,dword ptr [ESI + 0x50]
//         00513eaa     FLD        float ptr [EDX + 0x5c]
//         00513ead     CALL       __ftol                                           undefined __ftol()
//         00513eb2     MOV        this,dword ptr [ESI + 0x220]
//         00513eb8     PUSH       EAX
//         00513eb9     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1531 (23)
//         00513ebe     MOV        EAX,dword ptr [ESI + 0x50]
//         00513ec1     FLD        float ptr [EAX + 0x60]
//         00513ec4     CALL       __ftol                                           undefined __ftol()
//         00513ec9     MOV        this,dword ptr [ESI + 0x220]
//         00513ecf     PUSH       EAX
//         00513ed0     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1532 (23)
//         00513ed5     MOV        this,dword ptr [ESI + 0x50]
//         00513ed8     FLD        float ptr [ECX + this->_padding_]
//                               LAB_00513edb                                                 XREF[2]:     00513df6(j), 00513e46(j)
//         00513edb     CALL       __ftol                                           undefined __ftol()
//         00513ee0     MOV        this,dword ptr [ESI + 0x220]
//         00513ee6     PUSH       EAX
//         00513ee7     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1549 (4)
//         00513eec     POP        ESI
//         00513eed     RET        0x4
//                               switchD_00513de9::caseD_1                                    XREF[2]:     00513de9(j), 00513f98(*)
//                              tplayer.cpp:1538 (23)
//         00513ef0     MOV        EDX,dword ptr [ESI + 0x50]
//         00513ef3     FLD        float ptr [EDX + 0x5c]
//         00513ef6     CALL       __ftol                                           undefined __ftol()
//         00513efb     MOV        this,dword ptr [ESI + 0x220]
//         00513f01     PUSH       EAX
//         00513f02     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1539 (23)
//         00513f07     MOV        EAX,dword ptr [ESI + 0x50]
//         00513f0a     FLD        float ptr [EAX + 0x60]
//         00513f0d     CALL       __ftol                                           undefined __ftol()
//         00513f12     MOV        this,dword ptr [ESI + 0x220]
//         00513f18     PUSH       EAX
//         00513f19     CALL       TRIBE_Player_Tech::disable                       void disable(TRIBE_Player_Tech * this, short
//                              tplayer.cpp:1540 (23)
//         00513f1e     MOV        this,dword ptr [ESI + 0x50]
//         00513f21     FLD        float ptr [ECX + this->_padding_]
//         00513f24     CALL       __ftol                                           undefined __ftol()
//         00513f29     MOV        this,dword ptr [ESI + 0x220]
//         00513f2f     PUSH       EAX
//         00513f30     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1542 (23)
//         00513f35     MOV        EDX,dword ptr [ESI + 0x50]
//         00513f38     FLD        float ptr [EDX + 0x5c]
//         00513f3b     CALL       __ftol                                           undefined __ftol()
//         00513f40     MOV        this,dword ptr [ESI + 0x220]
//         00513f46     PUSH       EAX
//         00513f47     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1543 (23)
//         00513f4c     MOV        EAX,dword ptr [ESI + 0x50]
//         00513f4f     FLD        float ptr [EAX + 0x5c]
//         00513f52     CALL       __ftol                                           undefined __ftol()
//         00513f57     MOV        this,dword ptr [ESI + 0x220]
//         00513f5d     PUSH       EAX
//         00513f5e     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1545 (23)
//         00513f63     MOV        this,dword ptr [ESI + 0x50]
//         00513f66     FLD        float ptr [ECX + this->_padding_]
//         00513f69     CALL       __ftol                                           undefined __ftol()
//         00513f6e     MOV        this,dword ptr [ESI + 0x220]
//         00513f74     PUSH       EAX
//         00513f75     CALL       TRIBE_Player_Tech::enable                        void enable(TRIBE_Player_Tech * this, short p
//                              tplayer.cpp:1546 (23)
//         00513f7a     MOV        EDX,dword ptr [ESI + 0x50]
//         00513f7d     FLD        float ptr [EDX + 0x60]
//         00513f80     CALL       __ftol                                           undefined __ftol()
//         00513f85     MOV        this,dword ptr [ESI + 0x220]
//         00513f8b     PUSH       EAX
//         00513f8c     CALL       TRIBE_Player_Tech::rev_tech                      uchar rev_tech(TRIBE_Player_Tech * this, shor
//                               switchD_00513de9::caseD_3                                    XREF[3]:     00513ddb(j), 00513de9(j),
//                               switchD_00513de9::caseD_4                                                 00513fa8(*)
//                               switchD_00513de9::caseD_5
//                               switchD_00513de9::caseD_6
//                               switchD_00513de9::caseD_7
//                               switchD_00513de9::caseD_8
//                               switchD_00513de9::caseD_9
//                               switchD_00513de9::caseD_a
//                               switchD_00513de9::caseD_b
//                               switchD_00513de9::caseD_c
//                               switchD_00513de9::caseD_d
//                               switchD_00513de9::caseD_e
//                               switchD_00513de9::caseD_f
//                               switchD_00513de9::caseD_10
//                               switchD_00513de9::caseD_11
//                               switchD_00513de9::caseD_12
//                               switchD_00513de9::caseD_13
//                               switchD_00513de9::caseD_14
//                               switchD_00513de9::caseD_15
//                               switchD_00513de9::caseD_16
//                               switchD_00513de9::caseD_2
//                              tplayer.cpp:1549 (52)
//         00513f91     POP        ESI
//         00513f92     RET        0x4
    return;
}

void TRIBE_Player::add_population_entry() {
    /* TODO: Stub */
//                              void __thiscall add_population_entry(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?add_population_entry@TRIBE_Player@@QAEXXZ                   XREF[1]:     new_game:005302a3(c)
//                               TRIBE_Player::add_population_entry
//                              tplayer.cpp:1554 (3)
//         00513fd0     PUSH       ESI
//         00513fd1     MOV        ESI,this
//                              tplayer.cpp:1555 (19)
//         00513fd3     MOV        this,dword ptr [ESI + 0x50]
//         00513fd6     FLD        float ptr [ECX + this->_padding_]
//         00513fd9     FCOMP      float ptr [DAT_00576828]
//         00513fdf     FNSTSW     AX
//         00513fe1     TEST       AH,0x1
//         00513fe4     JZ         LAB_00513ff7
//                              tplayer.cpp:1558 (15)
//         00513fe6     MOV        this,dword ptr [ESI + 0x83c]
//         00513fec     PUSH       0x0
//         00513fee     PUSH       0x0
//         00513ff0     CALL       TRIBE_History_Info::add_history_entry            void add_history_entry(TRIBE_History_Info * t
//                              tplayer.cpp:1559 (2)
//         00513ff5     POP        ESI
//         00513ff6     RET
//                               LAB_00513ff7                                                 XREF[1]:     00513fe4(j)
//                              tplayer.cpp:1558 (22)
//         00513ff7     FLD        float ptr [ECX + this->_padding_]
//         00513ffa     CALL       __ftol                                           undefined __ftol()
//         00513fff     MOV        this,dword ptr [ESI + 0x83c]
//         00514005     PUSH       EAX
//         00514006     PUSH       0x0
//         00514008     CALL       TRIBE_History_Info::add_history_entry            void add_history_entry(TRIBE_History_Info * t
//                              tplayer.cpp:1559 (2)
//         0051400d     POP        ESI
//         0051400e     RET
//         0051400f     ??         90h
    return;
}

void TRIBE_Player::random_start() {
    /* TODO: Stub */
//                              void __thiscall random_start(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              long              Stack[-0x8]:4  w2                        XREF[4]:     0051406e(W), 00514072(R), 005140b3(W), 005140b7(R)
//              float             Stack[-0x10]:4 w
//              float             Stack[-0x14]:4 h                         XREF[2]:     005140c1(W), 005140ec(R)
//              float             Stack[-0x18]:4 w1                        XREF[2]:     0051407c(W), 005140ca(R)
//              float             Stack[-0x1c]:4 h1                        XREF[0,1]:   00514019(W)
//              uchar             Stack[-0x1d]:1 found_ally
//              undefined4        Stack[-0x4c]:4 local_4c                  XREF[1]:     005140e9(*)
//              undefined4        Stack[-0x50]:4 local_50                  XREF[1]:     005140f7(*)
//                               ?random_start@TRIBE_Player@@UAEXXZ                           XREF[1]:     00576900(*)
//                               TRIBE_Player::random_start
//                              tplayer.cpp:1564 (9)
//         00514010     SUB        ESP,0x1c
//         00514013     PUSH       EBX
//         00514014     PUSH       EBP
//         00514015     PUSH       ESI
//         00514016     MOV        ESI,this
//         00514018     PUSH       EDI
//                              tplayer.cpp:1575 (5)
//         00514019     MOV        byte ptr [ESP + h1+0x3],0x0
//                              tplayer.cpp:1579 (14)
//         0051401e     MOV        this,dword ptr [ESI + 0x28]
//         00514021     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00514024     TEST       EAX,EAX
//         00514026     JNZ        LAB_0051436f
//                              tplayer.cpp:1585 (26)
//         0051402c     PUSH       0x631
//         00514031     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514036     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0051403b     MOV        this,EAX
//         0051403d     MOV        EAX,dword ptr [ESI + 0x3c]
//         00514040     ADD        ESP,0x8
//         00514043     MOV        EDX,dword ptr [EAX + 0x28]
//                              tplayer.cpp:1586 (71)
//         00514046     PUSH       0x632
//         0051404b     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514050     MOV        EAX,dword ptr [EDX + 0xc]
//         00514053     SUB        EAX,0x1e
//         00514056     IMUL       this,EAX
//         00514059     MOV        EAX,0x80010003
//         0051405e     IMUL       this
//         00514060     ADD        EDX,this
//         00514062     SAR        EDX,0xe
//         00514065     MOV        this,EDX
//         00514067     SHR        this,0x1f
//         0051406a     LEA        EDX,[EDX + this->_padding_*0x1 + 0xf]
//         0051406e     MOV        dword ptr [ESP + w2],EDX
//         00514072     FILD       dword ptr [ESP + w2]
//         00514076     FSUB       float ptr [DAT_00576868]
//         0051407c     FSTP       float ptr [ESP + w1]
//         00514080     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00514085     MOV        this,EAX
//         00514087     MOV        EAX,dword ptr [ESI + 0x3c]
//         0051408a     ADD        ESP,0x8
//                              tplayer.cpp:1588 (56)
//         0051408d     MOV        EDI,0x1
//         00514092     MOV        EDX,dword ptr [EAX + 0x28]
//         00514095     MOV        EAX,dword ptr [EDX + 0x8]
//         00514098     SUB        EAX,0x1e
//         0051409b     IMUL       this,EAX
//         0051409e     MOV        EAX,0x80010003
//         005140a3     IMUL       this
//         005140a5     ADD        EDX,this
//         005140a7     SAR        EDX,0xe
//         005140aa     MOV        this,EDX
//         005140ac     SHR        this,0x1f
//         005140af     LEA        EDX,[EDX + this->_padding_*0x1 + 0xf]
//         005140b3     MOV        dword ptr [ESP + w2],EDX
//         005140b7     FILD       dword ptr [ESP + w2]
//         005140bb     FSUB       float ptr [DAT_00576868]
//         005140c1     FSTP       float ptr [ESP + h]
//                               LAB_005140c5                                                 XREF[1]:     005141a1(j)
//                              tplayer.cpp:1593 (226)
//         005140c5     MOV        EAX,dword ptr [ESI + 0x24]
//         005140c8     PUSH       0x1
//         005140ca     FLD        float ptr [ESP + w1]
//         005140ce     MOV        this,dword ptr [EAX + 0x1b4]
//         005140d4     PUSH       offset DAT_fffffff8
//         005140d6     FSUB       float ptr [DAT_00576868]
//         005140dc     MOV        EDX,dword ptr [this->_padding_]
//         005140de     PUSH       offset DAT_fffffff4
//         005140e0     PUSH       offset DAT_fffffff0
//         005140e2     PUSH       0x1
//         005140e4     PUSH       0x0
//         005140e6     PUSH       0x0
//         005140e8     PUSH       this
//         005140e9     FSTP       float ptr [ESP]=>local_4c
//         005140ec     FLD        float ptr [ESP + h]
//         005140f0     FSUB       float ptr [DAT_00576868]
//         005140f6     PUSH       this
//         005140f7     FSTP       float ptr [ESP]=>local_50
//         005140fa     PUSH       ESI
//         005140fb     CALL       dword ptr [EDX + 0x20]
//         005140fe     TEST       AL,AL
//         00514100     JZ         LAB_005141a7
//         00514106     PUSH       0x631
//         0051410b     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514110     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00514115     MOV        this,EAX
//         00514117     MOV        EAX,dword ptr [ESI + 0x3c]
//         0051411a     ADD        ESP,0x8
//         0051411d     MOV        EDX,dword ptr [EAX + 0x28]
//         00514120     PUSH       0x632
//         00514125     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051412a     MOV        EAX,dword ptr [EDX + 0xc]
//         0051412d     SUB        EAX,0x1e
//         00514130     IMUL       this,EAX
//         00514133     MOV        EAX,0x80010003
//         00514138     IMUL       this
//         0051413a     ADD        EDX,this
//         0051413c     SAR        EDX,0xe
//         0051413f     MOV        this,EDX
//         00514141     SHR        this,0x1f
//         00514144     LEA        EDX,[EDX + this->_padding_*0x1 + 0xf]
//         00514148     MOV        dword ptr [ESP + 0x2c],EDX
//         0051414c     FILD       dword ptr [ESP + 0x2c]
//         00514150     FSUB       float ptr [DAT_00576868]
//         00514156     FSTP       float ptr [ESP + 0x1c]
//         0051415a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0051415f     MOV        this,EAX
//         00514161     MOV        EAX,dword ptr [ESI + 0x3c]
//         00514164     ADD        ESP,0x8
//         00514167     MOV        EDX,dword ptr [EAX + 0x28]
//         0051416a     MOV        EAX,dword ptr [EDX + 0x8]
//         0051416d     SUB        EAX,0x1e
//         00514170     IMUL       this,EAX
//         00514173     MOV        EAX,0x80010003
//         00514178     IMUL       this
//         0051417a     ADD        EDX,this
//         0051417c     SAR        EDX,0xe
//         0051417f     MOV        this,EDX
//         00514181     SHR        this,0x1f
//         00514184     INC        EDI
//         00514185     LEA        EDX,[EDX + this->_padding_*0x1 + 0xf]
//         00514189     CMP        EDI,0x1388
//         0051418f     MOV        dword ptr [ESP + 0x24],EDX
//         00514193     FILD       dword ptr [ESP + 0x24]
//         00514197     FSUB       float ptr [DAT_00576868]
//         0051419d     FSTP       float ptr [ESP + 0x18]
//         005141a1     JL         LAB_005140c5
//                               LAB_005141a7                                                 XREF[1]:     00514100(j)
//                              tplayer.cpp:1595 (12)
//         005141a7     CMP        EDI,0x1388
//         005141ad     JGE        LAB_005143b6
//                              tplayer.cpp:1597 (27)
//         005141b3     MOV        EAX,dword ptr [ESI + 0x24]
//         005141b6     MOV        EDI,dword ptr [ESP + 0x14]
//         005141ba     MOV        EBX,dword ptr [ESP + 0x18]
//         005141be     PUSH       0x0
//         005141c0     MOV        this,dword ptr [EAX + 0x1b4]
//         005141c6     PUSH       EDI=>DAT_fffffff8
//         005141c7     PUSH       EBX=>DAT_fffffff4
//         005141c8     PUSH       ESI=>DAT_fffffff0
//         005141c9     MOV        EDX,dword ptr [this->_padding_]
//         005141cb     CALL       dword ptr [EDX + 0x18]
//                              tplayer.cpp:1598 (29)
//         005141ce     FLD        float ptr [ESP + 0x14]
//         005141d2     MOV        EBP,EAX
//         005141d4     CALL       __ftol                                           undefined __ftol()
//         005141d9     FLD        float ptr [ESP + 0x18]
//         005141dd     PUSH       EAX
//         005141de     CALL       __ftol                                           undefined __ftol()
//         005141e3     PUSH       EAX=>DAT_fffffff8
//         005141e4     MOV        this,ESI
//         005141e6     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
//                              tplayer.cpp:1599 (9)
//         005141eb     PUSH       EDI
//         005141ec     PUSH       EBX=>DAT_fffffff8
//         005141ed     MOV        this,ESI
//         005141ef     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                              tplayer.cpp:1600 (12)
//         005141f4     PUSH       0x461c4000
//         005141f9     MOV        this,EBP
//         005141fb     CALL       TRIBE_Building_Object::build                     uchar build(TRIBE_Building_Object * this, flo
//                              tplayer.cpp:1654 (8)
//         00514200     MOV        dword ptr [ESP + 0x24],0x3
//                               LAB_00514208                                                 XREF[1]:     00514367(j)
//                              tplayer.cpp:1603 (2)
//         00514208     MOV        BL,0x1
//                               LAB_0051420a                                                 XREF[1]:     00514358(j)
//                              tplayer.cpp:1606 (37)
//         0051420a     PUSH       0x646
//         0051420f     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514214     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00514219     LEA        this,[EAX + EAX*0x2]
//         0051421c     MOV        EAX,0x80010003
//         00514221     SHL        this,0x1
//         00514223     IMUL       this
//         00514225     ADD        EDX,this
//         00514227     ADD        ESP,0x8
//         0051422a     SAR        EDX,0xe
//         0051422d     MOV        EAX,EDX
//                              tplayer.cpp:1607 (38)
//         0051422f     PUSH       0x647
//         00514234     SHR        EAX,0x1f
//         00514237     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051423c     LEA        this,[EDX + EAX*0x1 + -0x3]
//         00514240     MOV        dword ptr [ESP + 0x28],this
//         00514244     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00514249     LEA        this,[EAX + EAX*0x2]
//         0051424c     MOV        EAX,0x80010003
//         00514251     SHL        this,0x1
//         00514253     IMUL       this
//                              tplayer.cpp:1608 (55)
//         00514255     FILD       dword ptr [ESP + 0x28]
//         00514259     FSTP       float ptr [ESP + 0x24]
//         0051425d     ADD        EDX,this
//         0051425f     ADD        ESP,0x8
//         00514262     SAR        EDX,0xe
//         00514265     MOV        EAX,EDX
//         00514267     PUSH       0x648
//         0051426c     SHR        EAX,0x1f
//         0051426f     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514274     LEA        this,[EDX + EAX*0x1 + -0x3]
//         00514278     MOV        dword ptr [ESP + 0x30],this
//         0051427c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00514281     MOV        dword ptr [ESP + 0x28],EAX
//         00514285     ADD        ESP,0x8
//         00514288     FILD       dword ptr [ESP + 0x20]
//                              tplayer.cpp:1609 (70)
//         0051428c     PUSH       0x649
//         00514291     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00514296     FMUL       float ptr [DAT_0057686c]
//         0051429c     FSUBR      float ptr [ESP + 0x24]
//         005142a0     FADD       float ptr [ESP + 0x1c]
//         005142a4     FSTP       float ptr [ESP + 0x24]
//         005142a8     FILD       dword ptr [ESP + 0x30]
//         005142ac     FSTP       float ptr [ESP + 0x28]
//         005142b0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005142b5     MOV        dword ptr [ESP + 0x30],EAX
//         005142b9     ADD        ESP,0x8
//         005142bc     FILD       dword ptr [ESP + 0x28]
//         005142c0     FMUL       float ptr [DAT_0057686c]
//         005142c6     FSUBR      float ptr [ESP + 0x20]
//         005142ca     FADD       float ptr [ESP + 0x18]
//         005142ce     FSTP       float ptr [ESP + 0x20]
//                              tplayer.cpp:1611 (111)
//         005142d2     FLD        float ptr [ESP + 0x1c]
//         005142d6     FCOMP      float ptr [DAT_00576828]
//         005142dc     FNSTSW     AX
//         005142de     TEST       AH,0x1
//         005142e1     JNZ        LAB_00514356
//         005142e3     MOV        EDX,dword ptr [ESI + 0x3c]
//         005142e6     MOV        this,dword ptr [EDX + 0x28]
//         005142e9     FILD       dword ptr [ECX + this->_padding_]
//         005142ec     FCOMP      float ptr [ESP + 0x1c]
//         005142f0     FNSTSW     AX
//         005142f2     TEST       AH,0x41
//         005142f5     JNZ        LAB_00514356
//         005142f7     FLD        float ptr [ESP + 0x20]
//         005142fb     FCOMP      float ptr [DAT_00576828]
//         00514301     FNSTSW     AX
//         00514303     TEST       AH,0x1
//         00514306     JNZ        LAB_00514356
//         00514308     FILD       dword ptr [ECX + this->_padding_]
//         0051430b     FCOMP      float ptr [ESP + 0x20]
//         0051430f     FNSTSW     AX
//         00514311     TEST       AH,0x41
//         00514314     JNZ        LAB_00514356
//         00514316     MOV        EAX,dword ptr [ESI + 0x24]
//         00514319     MOV        EDI,dword ptr [ESP + 0x1c]
//         0051431d     MOV        EBP,dword ptr [ESP + 0x20]
//         00514321     PUSH       0x1
//         00514323     MOV        this,dword ptr [EAX + 0x14c]
//         00514329     PUSH       offset DAT_fffffff8
//         0051432b     PUSH       offset DAT_fffffff4
//         0051432d     PUSH       offset DAT_fffffff0
//         0051432f     MOV        EDX,dword ptr [this->_padding_]
//         00514331     PUSH       0x1
//         00514333     PUSH       0x0
//         00514335     PUSH       0x0
//         00514337     PUSH       EDI
//         00514338     PUSH       EBP
//         00514339     PUSH       ESI
//         0051433a     CALL       dword ptr [EDX + 0x20]
//         0051433d     TEST       AL,AL
//         0051433f     JNZ        LAB_00514356
//                              tplayer.cpp:1613 (19)
//         00514341     MOV        EAX,dword ptr [ESI + 0x24]
//         00514344     PUSH       0x0
//         00514346     PUSH       EDI=>DAT_fffffff8
//         00514347     PUSH       EBP=>DAT_fffffff4
//         00514348     MOV        this,dword ptr [EAX + 0x14c]
//         0051434e     PUSH       ESI=>DAT_fffffff0
//         0051434f     MOV        EDX,dword ptr [this->_padding_]
//         00514351     CALL       dword ptr [EDX + 0x18]
//                              tplayer.cpp:1614 (2)
//         00514354     XOR        BL,BL
//                               LAB_00514356                                                 XREF[5]:     005142e1(j), 005142f5(j),
//                                                                                                         00514306(j), 00514314(j),
//                                                                                                         0051433f(j)
//                              tplayer.cpp:1604 (23)
//         00514356     TEST       BL,BL
//         00514358     JNZ        LAB_0051420a
//         0051435e     MOV        EAX,dword ptr [ESP + 0x24]
//         00514362     DEC        EAX
//         00514363     MOV        dword ptr [ESP + 0x24],EAX
//         00514367     JNZ        LAB_00514208
//                              tplayer.cpp:1620 (2)
//         0051436d     JMP        LAB_005143b6
//                               LAB_0051436f                                                 XREF[1]:     00514026(j)
//                              tplayer.cpp:1623 (19)
//         0051436f     PUSH       0x0
//         00514371     PUSH       0x0
//         00514373     PUSH       0x0
//         00514375     PUSH       0x0
//         00514377     PUSH       0x0
//         00514379     PUSH       0x6d
//         0051437b     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//         00514380     MOV        EDI,EAX
//                              tplayer.cpp:1624 (4)
//         00514382     TEST       EDI,EDI
//         00514384     JNZ        LAB_0051438e
//                              tplayer.cpp:1625 (8)
//         00514386     MOV        EAX,dword ptr [ESI + 0x28]
//         00514389     MOV        this,dword ptr [EAX + 0x4]
//         0051438c     MOV        EDI,dword ptr [this->_padding_]
//                               LAB_0051438e                                                 XREF[1]:     00514384(j)
//                              tplayer.cpp:1626 (25)
//         0051438e     FLD        float ptr [EDI + 0x3c]
//         00514391     CALL       __ftol                                           undefined __ftol()
//         00514396     FLD        float ptr [EDI + 0x38]
//         00514399     PUSH       EAX
//         0051439a     CALL       __ftol                                           undefined __ftol()
//         0051439f     PUSH       EAX
//         005143a0     MOV        this,ESI
//         005143a2     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
//                              tplayer.cpp:1627 (15)
//         005143a7     MOV        EDX,dword ptr [EDI + 0x3c]
//         005143aa     MOV        EAX,dword ptr [EDI + 0x38]
//         005143ad     PUSH       EDX
//         005143ae     PUSH       EAX
//         005143af     MOV        this,ESI
//         005143b1     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_005143b6                                                 XREF[2]:     005141ad(j), 0051436d(j)
//                              tplayer.cpp:1631 (34)
//         005143b6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005143bc     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         005143c1     TEST       EAX,EAX
//         005143c3     JNZ        LAB_005143d8
//         005143c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005143cb     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         005143d0     TEST       EAX,EAX
//         005143d2     JZ         LAB_00514498
//                               LAB_005143d8                                                 XREF[1]:     005143c3(j)
//                              tplayer.cpp:1632 (18)
//         005143d8     MOV        this,dword ptr [ESI + 0x3c]
//         005143db     MOV        EBX,0x1
//         005143e0     CMP        word ptr [ECX + this->_padding_],BX
//         005143e4     JLE        LAB_00514498
//                              tplayer.cpp:1633 (32)
//         005143ea     MOV        EDX,dword ptr [ESI]
//         005143ec     MOV        EAX,dword ptr [EDX + 0x1c]
//         005143ef     MOV        dword ptr [ESP + 0x28],EAX
//                               LAB_005143f3                                                 XREF[1]:     00514492(j)
//         005143f3     PUSH       EBX
//         005143f4     MOV        this,ESI
//         005143f6     CALL       dword ptr [ESP + 0x2c]
//         005143fa     TEST       EAX,EAX
//         005143fc     JZ         LAB_00514488
//         00514402     MOVSX      this,word ptr [ESI + 0x4a]
//         00514406     CMP        EBX,this
//         00514408     JZ         LAB_00514488
//                              tplayer.cpp:1635 (22)
//         0051440a     MOV        this,dword ptr [ESI + 0x28]
//         0051440d     PUSH       0x0
//         0051440f     PUSH       0x0=>DAT_fffffff8
//         00514411     PUSH       0x0=>DAT_fffffff4
//         00514413     PUSH       0x0=>DAT_fffffff0
//         00514415     PUSH       0x0
//         00514417     PUSH       0x6d
//         00514419     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//         0051441e     MOV        EDI,EAX
//                              tplayer.cpp:1636 (4)
//         00514420     TEST       EDI,EDI
//         00514422     JNZ        LAB_00514430
//                              tplayer.cpp:1637 (8)
//         00514424     MOV        EDX,dword ptr [ESI + 0x28]
//         00514427     MOV        EAX,dword ptr [EDX + 0x4]
//         0051442a     MOV        EDI,dword ptr [EAX]
//                              tplayer.cpp:1638 (4)
//         0051442c     TEST       EDI,EDI
//         0051442e     JZ         LAB_0051445e
//                               LAB_00514430                                                 XREF[1]:     00514422(j)
//                              tplayer.cpp:1640 (24)
//         00514430     MOV        this,dword ptr [ESI + 0x3c]
//         00514433     MOV        EBP,dword ptr [EDI]
//         00514435     PUSH       -0x1
//         00514437     PUSH       0x0=>DAT_fffffff8
//         00514439     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051443c     MOV        this,EDI
//         0051443e     MOV        EAX,dword ptr [EDX + EBX*0x4]
//         00514441     PUSH       EAX=>DAT_fffffff4
//         00514442     CALL       dword ptr [EBP + 0xd8]
//                              tplayer.cpp:1641 (22)
//         00514448     MOV        this,dword ptr [ESI + 0x3c]
//         0051444b     PUSH       -0x1
//         0051444d     PUSH       0x0=>DAT_fffffff8
//         0051444f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00514452     MOV        this,EDI
//         00514454     MOV        EAX,dword ptr [EDX + EBX*0x4]
//         00514457     PUSH       EAX=>DAT_fffffff4
//         00514458     CALL       dword ptr [EBP + 0xdc]
//                               LAB_0051445e                                                 XREF[1]:     0051442e(j)
//                              tplayer.cpp:1643 (37)
//         0051445e     MOV        this,dword ptr [ESI + 0x3c]
//         00514461     PUSH       0x0
//         00514463     PUSH       0x0=>DAT_fffffff8
//         00514465     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00514468     MOV        this,dword ptr [EDX + EBX*0x4]
//         0051446b     MOV        EDX,dword ptr [ESI + 0x118]
//         00514471     PUSH       EDX=>DAT_fffffff4
//         00514472     MOV        EDX,dword ptr [ESI + 0x114]
//         00514478     MOV        EAX,dword ptr [this->_padding_]
//         0051447a     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x70: "B"
//         0051447b     PUSH       0x70
//         0051447d     CALL       dword ptr [EAX + 0x94]
//                              tplayer.cpp:1644 (21)
//         00514483     MOV        byte ptr [ESP + 0x13],0x1
//                               LAB_00514488                                                 XREF[2]:     005143fc(j), 00514408(j)
//         00514488     MOV        EAX,dword ptr [ESI + 0x3c]
//         0051448b     INC        EBX
//         0051448c     MOVSX      this,word ptr [EAX + 0x3c]
//         00514490     CMP        EBX,this
//         00514492     JL         LAB_005143f3
//                               LAB_00514498                                                 XREF[2]:     005143d2(j), 005143e4(j)
//                              tplayer.cpp:1648 (21)
//         00514498     MOV        EAX,dword ptr [ESI + 0x3c]
//         0051449b     MOV        DX,word ptr [EAX + 0x7c]
//         0051449f     CMP        DX,word ptr [ESI + 0x4a]
//         005144a3     JNZ        LAB_005144fc
//         005144a5     MOV        this,byte ptr [ESP + 0x13]
//         005144a9     TEST       this,this
//         005144ab     JZ         LAB_005144fc
//                              tplayer.cpp:1649 (11)
//         005144ad     MOV        EBX,0x1
//         005144b2     CMP        word ptr [EAX + 0x3c],BX
//         005144b6     JLE        LAB_005144fc
//                               LAB_005144b8                                                 XREF[1]:     005144fa(j)
//                              tplayer.cpp:1650 (8)
//         005144b8     MOVSX      EAX,word ptr [ESI + 0x4a]
//         005144bc     CMP        EBX,EAX
//         005144be     JZ         LAB_005144f0
//                              tplayer.cpp:1651 (5)
//         005144c0     MOV        EDI,0x1
//                               LAB_005144c5                                                 XREF[1]:     005144ee(j)
//                              tplayer.cpp:1652 (16)
//         005144c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005144cb     PUSH       EDI
//         005144cc     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//         005144d1     CMP        EAX,EBX
//         005144d3     JNZ        LAB_005144ea
//                              tplayer.cpp:1653 (27)
//         005144d5     MOV        EDX,dword ptr [ESI]
//         005144d7     PUSH       EBX
//         005144d8     MOV        this,ESI
//         005144da     CALL       dword ptr [EDX + 0x1c]
//         005144dd     MOV        this,dword ptr [chat]                            = 00000000
//         005144e3     PUSH       EAX
//         005144e4     PUSH       EDI=>DAT_fffffff8
//         005144e5     CALL       TChat::setInChatGroup                            void setInChatGroup(TChat * this, int param_1
//                               LAB_005144ea                                                 XREF[1]:     005144d3(j)
//         005144ea     INC        EDI
//         005144eb     CMP        EDI,0x9
//         005144ee     JL         LAB_005144c5
//                               LAB_005144f0                                                 XREF[1]:     005144be(j)
//                              tplayer.cpp:1649 (12)
//         005144f0     MOV        EAX,dword ptr [ESI + 0x3c]
//         005144f3     INC        EBX
//         005144f4     MOVSX      this,word ptr [EAX + 0x3c]
//         005144f8     CMP        EBX,this
//         005144fa     JL         LAB_005144b8
//                               LAB_005144fc                                                 XREF[3]:     005144a3(j), 005144ab(j),
//                                                                                                         005144b6(j)
//                              tplayer.cpp:1654 (8)
//         005144fc     POP        EDI
//         005144fd     POP        ESI
//         005144fe     POP        EBP
//         005144ff     POP        EBX
//         00514500     ADD        ESP,0x1c
//         00514503     RET
//         00514504     ??         90h
//         00514505     NOP
//         00514506     NOP
//         00514507     NOP
//         00514508     NOP
//         00514509     NOP
//         0051450a     NOP
//         0051450b     NOP
//         0051450c     NOP
//         0051450d     NOP
//         0051450e     NOP
//         0051450f     NOP
    return;
}

void TRIBE_Player::objectCost(int param_1, int param_2, ResourceItem* param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall objectCost(TRIBE_Player * this, int param_1, int par
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0051452d(*), 00514536(*), 00514543(R)
//              int               Stack[0x8]:4   param_2
//              ResourceItem *    Stack[0xc]:4   param_3                   XREF[1]:     0051454d(R)
//              int               Stack[0x10]:4  param_4
//              undefined2        Stack[-0x2]:2  local_2                   XREF[2]:     00514517(*), 00514572(R)
//              undefined2        Stack[-0x4]:2  local_4                   XREF[2]:     00514513(*), 0051456d(R)
//              short             Stack[-0x6]:2  inv_3                     XREF[2]:     00514527(*), 0051455f(R)
//              short             Stack[-0x8]:2  inv_amt_3                 XREF[2]:     00514523(*), 0051455a(R)
//              short             Stack[-0xa]:2  inv_2                     XREF[2]:     00514531(*), 00514548(R)
//              short             Stack[-0xc]:2  inv_amt_2
//              short             Stack[-0xe]:2  inv_1
//                               ?objectCost@TRIBE_Player@@QAEXHHPAVResourceItem@@H@Z         XREF[7]:     initialize:004d4379(c),
//                               TRIBE_Player::objectCost                                                  nextBuildableItem:004d4d1e(c),
//                                                                                                         blockingResource:004d4ed4(c),
//                                                                                                         mostNeededResource:004d5036(c),
//                                                                                                         checkForBuildInsertion:00501e12(c)
//                                                                                                         checkForBuildInsertion:00501fe8(c)
//                                                                                                         FUN_005024b3:00502533(c)
//                              tplayer.cpp:1660 (3)
//         00514510     SUB        ESP,0xc
//                              tplayer.cpp:1670 (48)
//         00514513     LEA        EAX=>local_4,[ESP + 0x8]
//         00514517     LEA        EDX=>local_2,[ESP + 0xa]
//         0051451b     PUSH       ESI
//         0051451c     PUSH       0x3f800000
//         00514521     PUSH       EAX
//         00514522     PUSH       EDX
//         00514523     LEA        EAX=>inv_amt_3,[ESP + 0x14]
//         00514527     LEA        EDX=>inv_3,[ESP + 0x16]
//         0051452b     PUSH       EAX
//         0051452c     PUSH       EDX
//         0051452d     LEA        EAX=>param_1,[ESP + 0x28]
//         00514531     LEA        EDX=>inv_2,[ESP + 0x1a]
//         00514535     PUSH       EAX
//         00514536     MOV        EAX=>param_1,dword ptr [ESP + 0x2c]
//         0051453a     PUSH       EDX
//         0051453b     PUSH       0x0
//         0051453d     PUSH       EAX
//         0051453e     CALL       TRIBE_Player::obj_cost                           void obj_cost(TRIBE_Player * this, short para
//                              tplayer.cpp:1672 (23)
//         00514543     MOVSX      this,word ptr [ESP + param_1]
//         00514548     MOVSX      EDX,word ptr [ESP + inv_2]
//         0051454d     MOV        ESI,dword ptr [ESP + param_3]
//         00514551     PUSH       this
//         00514552     PUSH       EDX
//         00514553     MOV        this,ESI
//         00514555     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1673 (19)
//         0051455a     MOVSX      EAX,word ptr [ESP + inv_amt_3]
//         0051455f     MOVSX      this,word ptr [ESP + inv_3]
//         00514564     PUSH       EAX
//         00514565     PUSH       this
//         00514566     MOV        this,ESI
//         00514568     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1674 (19)
//         0051456d     MOVSX      EDX,word ptr [ESP + local_4]
//         00514572     MOVSX      EAX,word ptr [ESP + local_2]
//         00514577     PUSH       EDX
//         00514578     PUSH       EAX
//         00514579     MOV        this,ESI
//         0051457b     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1675 (7)
//         00514580     POP        ESI
//         00514581     ADD        ESP,0xc
//         00514584     RET        0x10
//         00514587     ??         90h
//         00514588     NOP
//         00514589     NOP
//         0051458a     NOP
//         0051458b     NOP
//         0051458c     NOP
//         0051458d     NOP
//         0051458e     NOP
//         0051458f     NOP
    return;
}

int TRIBE_Player::objectCostByType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall objectCostByType(TRIBE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     005145ac(*), 005145b5(*), 005145c2(R)
//              undefined         Stack[-0x2]:1  local_2                   XREF[1]:     005145b0(*)
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     005145a6(*)
//              short             Stack[-0x6]:2  inv_1                     XREF[1]:     00514597(*)
//              short             Stack[-0x8]:2  inv_2                     XREF[2]:     005145a2(*), 005145cc(R)
//              short             Stack[-0xa]:2  inv_3                     XREF[2]:     00514593(*), 005145c7(R)
//              short             Stack[-0xc]:2  inv_amt_2
//              short             Stack[-0xe]:2  inv_amt_3
//                               ?objectCostByType@TRIBE_Player@@UAEHH@Z                      XREF[2]:     005768c8(*), 005769f8(*)
//                               TRIBE_Player::objectCostByType
//                              tplayer.cpp:1680 (3)
//         00514590     SUB        ESP,0xc
//                              tplayer.cpp:1691 (47)
//         00514593     LEA        EAX=>inv_3,[ESP + 0x2]
//         00514597     LEA        EDX=>inv_1,[ESP + 0x6]
//         0051459b     PUSH       0x3f800000
//         005145a0     PUSH       EAX
//         005145a1     PUSH       EDX
//         005145a2     LEA        EAX=>inv_2,[ESP + 0x10]
//         005145a6     LEA        EDX=>local_4,[ESP + 0x14]
//         005145aa     PUSH       EAX
//         005145ab     PUSH       EDX
//         005145ac     LEA        EAX=>param_1,[ESP + 0x24]
//         005145b0     LEA        EDX=>local_2,[ESP + 0x1e]
//         005145b4     PUSH       EAX
//         005145b5     MOV        EAX=>param_1,dword ptr [ESP + 0x28]
//         005145b9     PUSH       EDX
//         005145ba     PUSH       0x0
//         005145bc     PUSH       EAX
//         005145bd     CALL       TRIBE_Player::obj_cost                           void obj_cost(TRIBE_Player * this, short para
//                              tplayer.cpp:1697 (19)
//         005145c2     MOVSX      EAX,word ptr [ESP + param_1]
//         005145c7     MOVSX      this,word ptr [ESP + inv_3]
//         005145cc     MOVSX      EDX,word ptr [ESP + inv_2]
//         005145d1     ADD        EAX,this
//         005145d3     ADD        EAX,EDX
//                              tplayer.cpp:1698 (6)
//         005145d5     ADD        ESP,0xc
//         005145d8     RET        0x4
//         005145db     ??         90h
//         005145dc     NOP
//         005145dd     NOP
//         005145de     NOP
//         005145df     NOP
    return 0;
}

void TRIBE_Player::researchCost(int param_1, int param_2, ResourceItem* param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall researchCost(TRIBE_Player * this, int param_1, int p
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     005145fd(*), 00514603(*), 00514612(R)
//              int               Stack[0x8]:4   param_2
//              ResourceItem *    Stack[0xc]:4   param_3                   XREF[1]:     0051461c(R)
//              int               Stack[0x10]:4  param_4
//              undefined2        Stack[-0x2]:2  local_2                   XREF[2]:     005145e7(*), 00514641(R)
//              undefined2        Stack[-0x4]:2  local_4                   XREF[2]:     005145e3(*), 0051463c(R)
//              short             Stack[-0x6]:2  inv_3                     XREF[2]:     005145f9(*), 0051462e(R)
//              short             Stack[-0x8]:2  inv_amt_3                 XREF[2]:     005145f3(*), 00514629(R)
//              short             Stack[-0xa]:2  inv_2                     XREF[2]:     00514607(*), 00514617(R)
//              short             Stack[-0xc]:2  inv_amt_2
//              short             Stack[-0xe]:2  inv_1
//                               ?researchCost@TRIBE_Player@@QAEXHHPAVResourceItem@@H@Z       XREF[5]:     initialize:004d439d(c),
//                               TRIBE_Player::researchCost                                                nextBuildableItem:004d4a02(c),
//                                                                                                         nextBuildableItem:004d4cfa(c),
//                                                                                                         blockingResource:004d4ef8(c),
//                                                                                                         mostNeededResource:004d5056(c)
//                              tplayer.cpp:1704 (3)
//         005145e0     SUB        ESP,0xc
//                              tplayer.cpp:1712 (47)
//         005145e3     LEA        EAX=>local_4,[ESP + 0x8]
//         005145e7     LEA        EDX=>local_2,[ESP + 0xa]
//         005145eb     MOV        this,dword ptr [ECX + this->tech_tree]
//         005145f1     PUSH       ESI
//         005145f2     PUSH       EAX
//         005145f3     LEA        EAX=>inv_amt_3,[ESP + 0xc]
//         005145f7     PUSH       EDX
//         005145f8     PUSH       EAX
//         005145f9     LEA        EDX=>inv_3,[ESP + 0x16]
//         005145fd     LEA        EAX=>param_1,[ESP + 0x20]
//         00514601     PUSH       EDX
//         00514602     PUSH       EAX
//         00514603     MOV        EAX=>param_1,dword ptr [ESP + 0x28]
//         00514607     LEA        EDX=>inv_2,[ESP + 0x1a]
//         0051460b     PUSH       EDX
//         0051460c     PUSH       EAX
//         0051460d     CALL       TRIBE_Player_Tech::tech_cost                     void tech_cost(TRIBE_Player_Tech * this, shor
//                              tplayer.cpp:1714 (23)
//         00514612     MOVSX      this,word ptr [ESP + param_1]
//         00514617     MOVSX      EDX,word ptr [ESP + inv_2]
//         0051461c     MOV        ESI,dword ptr [ESP + param_3]
//         00514620     PUSH       this
//         00514621     PUSH       EDX
//         00514622     MOV        this,ESI
//         00514624     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1715 (19)
//         00514629     MOVSX      EAX,word ptr [ESP + inv_amt_3]
//         0051462e     MOVSX      this,word ptr [ESP + inv_3]
//         00514633     PUSH       EAX
//         00514634     PUSH       this
//         00514635     MOV        this,ESI
//         00514637     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1716 (19)
//         0051463c     MOVSX      EDX,word ptr [ESP + local_4]
//         00514641     MOVSX      EAX,word ptr [ESP + local_2]
//         00514646     PUSH       EDX
//         00514647     PUSH       EAX
//         00514648     MOV        this,ESI
//         0051464a     CALL       ResourceItem::incrementValue                     void incrementValue(ResourceItem * this, int
//                              tplayer.cpp:1717 (7)
//         0051464f     POP        ESI
//         00514650     ADD        ESP,0xc
//         00514653     RET        0x10
//         00514656     ??         90h
//         00514657     NOP
//         00514658     NOP
//         00514659     NOP
//         0051465a     NOP
//         0051465b     NOP
//         0051465c     NOP
//         0051465d     NOP
//         0051465e     NOP
//         0051465f     NOP
    return;
}

int TRIBE_Player::objectAvailable(int param_1) {
    /* TODO: Stub */
//                              int __thiscall objectAvailable(TRIBE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00514663(R)
//                               ?objectAvailable@TRIBE_Player@@QAEHH@Z                       XREF[4]:     nextBuildableItem:004d4cb3(c),
//                               TRIBE_Player::objectAvailable                                             checkForBuildInsertion:00501e4f(c)
//                                                                                                         checkForBuildInsertion:00502015(c)
//                                                                                                         FUN_005024b3:005024ca(c)
//                              tplayer.cpp:1722 (26)
//         00514660     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00514663     MOV        this,dword ptr [ESP + param_1]
//         00514667     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
//         0051466a     TEST       EAX,EAX
//         0051466c     JZ         LAB_00514675
//         0051466e     MOV        DL,byte ptr [EAX + 0x52]
//         00514671     TEST       DL,DL
//         00514673     JNZ        LAB_0051467a
//                               LAB_00514675                                                 XREF[1]:     0051466c(j)
//         00514675     CMP        this,0x6d
//         00514678     JNZ        LAB_00514682
//                               LAB_0051467a                                                 XREF[1]:     00514673(j)
//                              tplayer.cpp:1725 (5)
//         0051467a     MOV        EAX,0x1
//                              tplayer.cpp:1727 (3)
//         0051467f     RET        0x4
//                               LAB_00514682                                                 XREF[1]:     00514678(j)
//                              tplayer.cpp:1726 (2)
//         00514682     XOR        EAX,EAX
//                              tplayer.cpp:1727 (3)
//         00514684     RET        0x4
//         00514687     ??         90h
//         00514688     NOP
//         00514689     NOP
//         0051468a     NOP
//         0051468b     NOP
//         0051468c     NOP
//         0051468d     NOP
//         0051468e     NOP
//         0051468f     NOP
    return 0;
}

int TRIBE_Player::researchAvailable(int param_1) {
    /* TODO: Stub */
//                              int __thiscall researchAvailable(TRIBE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00514696(R)
//                               ?researchAvailable@TRIBE_Player@@QAEHH@Z                     XREF[2]:     nextBuildableItem:004d4a1b(c),
//                               TRIBE_Player::researchAvailable                                           nextBuildableItem:004d4c93(c)
//                              tplayer.cpp:1732 (23)
//         00514690     MOV        EAX,dword ptr [ECX + this->tech_tree]
//         00514696     MOV        EDX,dword ptr [ESP + param_1]
//         0051469a     MOV        this,dword ptr [EAX]
//         0051469c     XOR        EAX,EAX
//         0051469e     CMP        word ptr [ECX + EDX*0x8 + this->_padding_],0x1
//         005146a4     SETZ       AL
//                              tplayer.cpp:1736 (3)
//         005146a7     RET        0x4
//         005146aa     ??         90h
//         005146ab     NOP
//         005146ac     NOP
//         005146ad     NOP
//         005146ae     NOP
//         005146af     NOP
    return 0;
}

int TRIBE_Player::researchEverAvailable(int param_1) {
    /* TODO: Stub */
//                              int __thiscall researchEverAvailable(TRIBE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005146b0(R)
//                               ?researchEverAvailable@TRIBE_Player@@QAEHH@Z                 XREF[1]:     nextBuildableItem:004d487f(c)
//                               TRIBE_Player::researchEverAvailable
//                              tplayer.cpp:1741 (16)
//         005146b0     MOV        EAX,dword ptr [ESP + param_1]
//         005146b4     MOV        this,dword ptr [ECX + this->tech_tree]
//         005146ba     PUSH       EAX
//         005146bb     CALL       TRIBE_Player_Tech::get_tech_state                short get_tech_state(TRIBE_Player_Tech * this
//                              tplayer.cpp:1745 (12)
//         005146c0     CMP        AX,0x3
//         005146c4     JZ         LAB_005146d4
//         005146c6     CMP        AX,0xffff
//         005146ca     JZ         LAB_005146d4
//                              tplayer.cpp:1747 (5)
//         005146cc     MOV        EAX,0x1
//                              tplayer.cpp:1748 (3)
//         005146d1     RET        0x4
//                               LAB_005146d4                                                 XREF[2]:     005146c4(j), 005146ca(j)
//                              tplayer.cpp:1746 (2)
//         005146d4     XOR        EAX,EAX
//                              tplayer.cpp:1748 (3)
//         005146d6     RET        0x4
//         005146d9     ??         90h
//         005146da     NOP
//         005146db     NOP
//         005146dc     NOP
//         005146dd     NOP
//         005146de     NOP
//         005146df     NOP
    return 0;
}

uchar TRIBE_Player::researchState(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall researchState(TRIBE_Player * this, int param_1)
//              uchar             AL:1           <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005146e0(R)
//                               ?researchState@TRIBE_Player@@QAEEH@Z                         XREF[5]:     nextBuildableItem:004d4606(c),
//                               TRIBE_Player::researchState                                               readyToResearch:004d5cc4(c),
//                                                                                                         readyToResearch:004d5ce2(c),
//                                                                                                         readyToResearch:004d5cfa(c),
//                                                                                                         readyToResearch:004d5d1e(c)
//                              tplayer.cpp:1753 (16)
//         005146e0     MOV        EAX,dword ptr [ESP + param_1]
//         005146e4     MOV        this,dword ptr [ECX + this->tech_tree]
//         005146ea     PUSH       EAX
//         005146eb     CALL       TRIBE_Player_Tech::get_tech_state                short get_tech_state(TRIBE_Player_Tech * this
//                              tplayer.cpp:1756 (3)
//         005146f0     RET        0x4
//         005146f3     ??         90h
//         005146f4     NOP
//         005146f5     NOP
//         005146f6     NOP
//         005146f7     NOP
//         005146f8     NOP
//         005146f9     NOP
//         005146fa     NOP
//         005146fb     NOP
//         005146fc     NOP
//         005146fd     NOP
//         005146fe     NOP
//         005146ff     NOP
    return 0;
}

void TRIBE_Player::changeToHumanPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToHumanPlayer(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?changeToHumanPlayer@TRIBE_Player@@UAEXXZ                    XREF[2]:     0057687c(*), 005769ac(*)
//                               TRIBE_Player::changeToHumanPlayer
//                              tplayer.cpp:1761 (1)
//         00514700     RET
//         00514701     ??         90h
//         00514702     NOP
//         00514703     NOP
//         00514704     NOP
//         00514705     NOP
//         00514706     NOP
//         00514707     NOP
//         00514708     NOP
//         00514709     NOP
//         0051470a     NOP
//         0051470b     NOP
//         0051470c     NOP
//         0051470d     NOP
//         0051470e     NOP
//         0051470f     NOP
    return;
}

void TRIBE_Player::changeToComputerPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToComputerPlayer(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?changeToComputerPlayer@TRIBE_Player@@UAEXXZ                 XREF[2]:     00576880(*), 005769b0(*)
//                               TRIBE_Player::changeToComputerPlayer
//                              tplayer.cpp:1778 (1)
//         00514710     RET
//         00514711     ??         90h
//         00514712     NOP
//         00514713     NOP
//         00514714     NOP
//         00514715     NOP
//         00514716     NOP
//         00514717     NOP
//         00514718     NOP
//         00514719     NOP
//         0051471a     NOP
//         0051471b     NOP
//         0051471c     NOP
//         0051471d     NOP
//         0051471e     NOP
//         0051471f     NOP
    return;
}

char* TRIBE_Player::aiStatus(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall aiStatus(TRIBE_Player * this, int param_1)
//              char *            EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     005147a7(R), 00514f0b(W), 00514f14(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00514edd(W), 00514f5a(R)
//                               ?aiStatus@TRIBE_Player@@UAEPADH@Z                            XREF[2]:     00576884(*), 005769b4(*)
//                               TRIBE_Player::aiStatus
//                              tplayer.cpp:1804 (7)
//         00514720     PUSH       this
//         00514721     PUSH       EBX
//         00514722     PUSH       EBP
//         00514723     PUSH       ESI
//         00514724     MOV        ESI,this
//         00514726     PUSH       EDI
//                              tplayer.cpp:1805 (10)
//         00514727     MOV        EAX,dword ptr [ESI + 0x238]
//         0051472d     TEST       EAX,EAX
//         0051472f     JNZ        LAB_005147a7
//                              tplayer.cpp:1807 (24)
//         00514731     MOV        EAX,dword ptr [ESI + 0x3c]
//         00514734     MOV        this,dword ptr [EAX + 0xfc]
//         0051473a     CMP        this,-0x1
//         0051473d     JZ         LAB_0051479a
//         0051473f     MOV        EAX,dword ptr [EAX + 0x40]
//         00514742     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
//         00514745     TEST       EAX,EAX
//         00514747     JZ         LAB_0051479a
//                              tplayer.cpp:1815 (71)
//         00514749     MOV        EAX,dword ptr [EAX + 0x238]
//         0051474f     MOV        EDI,dword ptr [ESI + 0x3c]
//         00514752     ADD        ESI,0x23c
//         00514758     MOV        EBX,dword ptr [EAX + 0x12468]
//         0051475e     MOV        EBP,dword ptr [EAX + 0x1246c]
//         00514764     LEA        this,[EAX + 0x1146c]
//         0051476a     CALL       TribeTacticalAIModule::updateAreaName            char * updateAreaName(TribeTacticalAIModule *
//         0051476f     MOV        this,dword ptr [EDI + 0xfc]
//         00514775     PUSH       EAX
//         00514776     XOR        EDX,EDX
//         00514778     PUSH       EBX
//         00514779     MOV        DL,byte ptr [EDI + 0x11d]
//         0051477f     PUSH       EBP
//         00514780     PUSH       this
//         00514781     PUSH       EDX
//         00514782     PUSH       s_ConCP=%d,_CurCP=%d,_AveUAms=%3d,               = "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=
//         00514787     PUSH       ESI
//         00514788     CALL       sprintf                                          undefined sprintf()
//         0051478d     ADD        ESP,0x1c
//                              tplayer.cpp:1816 (2)
//         00514790     MOV        EAX,ESI
//                              tplayer.cpp:1928 (8)
//         00514792     POP        EDI
//         00514793     POP        ESI
//         00514794     POP        EBP
//         00514795     POP        EBX
//         00514796     POP        this
//         00514797     RET        0x4
//                               LAB_0051479a                                                 XREF[2]:     0051473d(j), 00514747(j)
//                              tplayer.cpp:1808 (5)
//         0051479a     MOV        EAX,s_Invalid_currentUpdateComputerPla           = "Invalid currentUpdateComputerPlayer..."
//                              tplayer.cpp:1928 (8)
//         0051479f     POP        EDI
//         005147a0     POP        ESI
//         005147a1     POP        EBP
//         005147a2     POP        EBX
//         005147a3     POP        this
//         005147a4     RET        0x4
//                               LAB_005147a7                                                 XREF[1]:     0051472f(j)
//                              tplayer.cpp:1819 (13)
//         005147a7     MOV        this,dword ptr [ESP + param_1]
//         005147ab     CMP        this,0x1
//         005147ae     JNZ        LAB_0051484a
//                              tplayer.cpp:1828 (140)
//         005147b4     LEA        this,[EAX + 0x104]
//         005147ba     LEA        EDI,[ESI + 0x23c]
//         005147c0     CALL       BuildAIModule::buildListLength                   int buildListLength(BuildAIModule * this)
//         005147c5     MOV        this,dword ptr [ESI + 0x238]
//         005147cb     PUSH       EAX
//         005147cc     ADD        this,0x104
//         005147d2     CALL       BuildAIModule::numberItemsIntoBuildList          int numberItemsIntoBuildList(BuildAIModule *
//         005147d7     MOV        this,dword ptr [ESI + 0x238]
//         005147dd     PUSH       EAX
//         005147de     ADD        this,0x104
//         005147e4     CALL       BuildAIModule::lastBuildItemRequested            char * lastBuildItemRequested(BuildAIModule *
//         005147e9     MOV        this,dword ptr [ESI + 0x238]
//         005147ef     PUSH       EAX
//         005147f0     ADD        this,0x104
//         005147f6     CALL       BuildAIModule::nextBuildItemRequested            char * nextBuildItemRequested(BuildAIModule *
//         005147fb     MOV        this,dword ptr [ESI + 0x238]
//         00514801     PUSH       EAX
//         00514802     ADD        this,0x104
//         00514808     CALL       BuildAIModule::currentBuildItemRequested         char * currentBuildItemRequested(BuildAIModul
//         0051480d     MOV        this,dword ptr [ESI + 0x238]
//         00514813     PUSH       EAX
//         00514814     ADD        this,0x6c4
//         0051481a     CALL       ConstructionAIModule::constructionPlanName       char * constructionPlanName(ConstructionAIMod
//         0051481f     MOV        this,dword ptr [ESI + 0x238]
//         00514825     PUSH       EAX
//         00514826     ADD        this,0x104
//         0051482c     CALL       BuildAIModule::buildListName                     char * buildListName(BuildAIModule * this)
//         00514831     PUSH       EAX
//         00514832     PUSH       s_Build_List:%s,_City_Plan:%s,_Bui               = "Build List:%s, City Plan:%s, BuildAI(C=%s,
//         00514837     PUSH       EDI
//         00514838     CALL       sprintf                                          undefined sprintf()
//         0051483d     ADD        ESP,0x24
//                              tplayer.cpp:1829 (2)
//         00514840     MOV        EAX,EDI
//                              tplayer.cpp:1928 (8)
//         00514842     POP        EDI
//         00514843     POP        ESI
//         00514844     POP        EBP
//         00514845     POP        EBX
//         00514846     POP        this
//         00514847     RET        0x4
//                               LAB_0051484a                                                 XREF[1]:     005147ae(j)
//                              tplayer.cpp:1831 (9)
//         0051484a     CMP        this,0x2
//         0051484d     JNZ        LAB_00514a3b
//                              tplayer.cpp:1849 (478)
//         00514853     PUSH       0x3
//         00514855     LEA        this,[EAX + 0x1146c]
//         0051485b     LEA        EDI,[ESI + 0x33c]
//         00514861     CALL       TribeTacticalAIModule::resourceDifference        int resourceDifference(TribeTacticalAIModule
//         00514866     MOV        this,dword ptr [ESI + 0x238]
//         0051486c     PUSH       EAX
//         0051486d     PUSH       0x3
//         0051486f     ADD        this,0x1146c
//         00514875     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         0051487a     MOV        this,dword ptr [ESI + 0x238]
//         00514880     PUSH       EAX
//         00514881     ADD        this,0x10d7c
//         00514887     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         0051488c     MOV        this,dword ptr [ESI + 0x238]
//         00514892     PUSH       EAX
//         00514893     PUSH       0x2
//         00514895     ADD        this,0x1146c
//         0051489b     CALL       TribeTacticalAIModule::resourceDifference        int resourceDifference(TribeTacticalAIModule
//         005148a0     MOV        this,dword ptr [ESI + 0x238]
//         005148a6     PUSH       EAX
//         005148a7     PUSH       0x2
//         005148a9     ADD        this,0x1146c
//         005148af     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         005148b4     MOV        this,dword ptr [ESI + 0x238]
//         005148ba     PUSH       EAX
//         005148bb     ADD        this,0x10d7c
//         005148c1     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         005148c6     MOV        this,dword ptr [ESI + 0x238]
//         005148cc     PUSH       EAX
//         005148cd     PUSH       0x1
//         005148cf     ADD        this,0x1146c
//         005148d5     CALL       TribeTacticalAIModule::resourceDifference        int resourceDifference(TribeTacticalAIModule
//         005148da     MOV        this,dword ptr [ESI + 0x238]
//         005148e0     PUSH       EAX
//         005148e1     PUSH       0x1
//         005148e3     ADD        this,0x1146c
//         005148e9     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         005148ee     MOV        this,dword ptr [ESI + 0x238]
//         005148f4     PUSH       EAX
//         005148f5     ADD        this,0x10d7c
//         005148fb     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514900     MOV        this,dword ptr [ESI + 0x238]
//         00514906     PUSH       EAX
//         00514907     PUSH       0x0
//         00514909     ADD        this,0x1146c
//         0051490f     CALL       TribeTacticalAIModule::resourceDifference        int resourceDifference(TribeTacticalAIModule
//         00514914     MOV        this,dword ptr [ESI + 0x238]
//         0051491a     PUSH       EAX
//         0051491b     PUSH       0x0
//         0051491d     ADD        this,0x1146c
//         00514923     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514928     MOV        this,dword ptr [ESI + 0x238]
//         0051492e     PUSH       EAX
//         0051492f     ADD        this,0x10d7c
//         00514935     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         0051493a     MOV        this,dword ptr [ESI + 0x238]
//         00514940     PUSH       EAX
//         00514941     PUSH       0x3
//         00514943     ADD        this,0x1146c
//         00514949     CALL       TribeTacticalAIModule::neededResourceAmount      int neededResourceAmount(TribeTacticalAIModul
//         0051494e     MOV        this,dword ptr [ESI + 0x238]
//         00514954     PUSH       EAX
//         00514955     PUSH       0x3
//         00514957     ADD        this,0x1146c
//         0051495d     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514962     MOV        this,dword ptr [ESI + 0x238]
//         00514968     PUSH       EAX
//         00514969     ADD        this,0x10d7c
//         0051496f     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514974     MOV        this,dword ptr [ESI + 0x238]
//         0051497a     PUSH       EAX
//         0051497b     PUSH       0x2
//         0051497d     ADD        this,0x1146c
//         00514983     CALL       TribeTacticalAIModule::neededResourceAmount      int neededResourceAmount(TribeTacticalAIModul
//         00514988     MOV        this,dword ptr [ESI + 0x238]
//         0051498e     PUSH       EAX
//         0051498f     PUSH       0x2
//         00514991     ADD        this,0x1146c
//         00514997     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         0051499c     MOV        this,dword ptr [ESI + 0x238]
//         005149a2     PUSH       EAX
//         005149a3     ADD        this,0x10d7c
//         005149a9     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         005149ae     MOV        this,dword ptr [ESI + 0x238]
//         005149b4     PUSH       EAX
//         005149b5     PUSH       0x1
//         005149b7     ADD        this,0x1146c
//         005149bd     CALL       TribeTacticalAIModule::neededResourceAmount      int neededResourceAmount(TribeTacticalAIModul
//         005149c2     MOV        this,dword ptr [ESI + 0x238]
//         005149c8     PUSH       EAX
//         005149c9     PUSH       0x1
//         005149cb     ADD        this,0x1146c
//         005149d1     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         005149d6     MOV        this,dword ptr [ESI + 0x238]
//         005149dc     PUSH       EAX
//         005149dd     ADD        this,0x10d7c
//         005149e3     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         005149e8     MOV        this,dword ptr [ESI + 0x238]
//         005149ee     PUSH       EAX
//         005149ef     PUSH       0x0
//         005149f1     ADD        this,0x1146c
//         005149f7     CALL       TribeTacticalAIModule::neededResourceAmount      int neededResourceAmount(TribeTacticalAIModul
//         005149fc     MOV        this,dword ptr [ESI + 0x238]
//         00514a02     PUSH       EAX
//         00514a03     PUSH       0x0
//         00514a05     ADD        this,0x1146c
//         00514a0b     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514a10     MOV        this,dword ptr [ESI + 0x238]
//         00514a16     PUSH       EAX
//         00514a17     ADD        this,0x10d7c
//         00514a1d     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514a22     PUSH       EAX
//         00514a23     PUSH       s_NeedRes:_%s=%d,_%s=%d,_%s=%d,_%s               = "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDi
//         00514a28     PUSH       EDI
//         00514a29     CALL       sprintf                                          undefined sprintf()
//         00514a2e     ADD        ESP,0x48
//                              tplayer.cpp:1850 (2)
//         00514a31     MOV        EAX,EDI
//                              tplayer.cpp:1928 (8)
//         00514a33     POP        EDI
//         00514a34     POP        ESI
//         00514a35     POP        EBP
//         00514a36     POP        EBX
//         00514a37     POP        this
//         00514a38     RET        0x4
//                               LAB_00514a3b                                                 XREF[1]:     0051484d(j)
//                              tplayer.cpp:1852 (9)
//         00514a3b     CMP        this,0x3
//         00514a3e     JNZ        LAB_00514bca
//                              tplayer.cpp:1869 (380)
//         00514a44     LEA        this,[EAX + 0x1146c]
//         00514a4a     LEA        EDI,[ESI + 0x43c]
//         00514a50     CALL       TribeTacticalAIModule::numberBoats               int numberBoats(TribeTacticalAIModule * this)
//         00514a55     MOV        this,dword ptr [ESI + 0x238]
//         00514a5b     PUSH       EAX
//         00514a5c     ADD        this,0x1146c
//         00514a62     CALL       TribeTacticalAIModule::numberSoldiers            int numberSoldiers(TribeTacticalAIModule * th
//         00514a67     MOV        this,dword ptr [ESI + 0x238]
//         00514a6d     PUSH       EAX
//         00514a6e     ADD        this,0x1146c
//         00514a74     CALL       TribeTacticalAIModule::numberCivilians           int numberCivilians(TribeTacticalAIModule * t
//         00514a79     MOV        this,dword ptr [ESI + 0x238]
//         00514a7f     PUSH       EAX
//         00514a80     PUSH       0x3
//         00514a82     ADD        this,0x1146c
//         00514a88     CALL       TribeTacticalAIModule::desiredGathererCount      int desiredGathererCount(TribeTacticalAIModul
//         00514a8d     MOV        this,dword ptr [ESI + 0x238]
//         00514a93     PUSH       EAX
//         00514a94     PUSH       0x3
//         00514a96     ADD        this,0x1146c
//         00514a9c     CALL       TribeTacticalAIModule::actualGathererCount       int actualGathererCount(TribeTacticalAIModule
//         00514aa1     MOV        this,dword ptr [ESI + 0x238]
//         00514aa7     PUSH       EAX
//         00514aa8     PUSH       0x3
//         00514aaa     ADD        this,0x1146c
//         00514ab0     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514ab5     MOV        this,dword ptr [ESI + 0x238]
//         00514abb     PUSH       EAX
//         00514abc     ADD        this,0x10d7c
//         00514ac2     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514ac7     MOV        this,dword ptr [ESI + 0x238]
//         00514acd     PUSH       EAX
//         00514ace     PUSH       0x2
//         00514ad0     ADD        this,0x1146c
//         00514ad6     CALL       TribeTacticalAIModule::desiredGathererCount      int desiredGathererCount(TribeTacticalAIModul
//         00514adb     MOV        this,dword ptr [ESI + 0x238]
//         00514ae1     PUSH       EAX
//         00514ae2     PUSH       0x2
//         00514ae4     ADD        this,0x1146c
//         00514aea     CALL       TribeTacticalAIModule::actualGathererCount       int actualGathererCount(TribeTacticalAIModule
//         00514aef     MOV        this,dword ptr [ESI + 0x238]
//         00514af5     PUSH       EAX
//         00514af6     PUSH       0x2
//         00514af8     ADD        this,0x1146c
//         00514afe     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514b03     MOV        this,dword ptr [ESI + 0x238]
//         00514b09     PUSH       EAX
//         00514b0a     ADD        this,0x10d7c
//         00514b10     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514b15     MOV        this,dword ptr [ESI + 0x238]
//         00514b1b     PUSH       EAX
//         00514b1c     PUSH       0x1
//         00514b1e     ADD        this,0x1146c
//         00514b24     CALL       TribeTacticalAIModule::desiredGathererCount      int desiredGathererCount(TribeTacticalAIModul
//         00514b29     MOV        this,dword ptr [ESI + 0x238]
//         00514b2f     PUSH       EAX
//         00514b30     PUSH       0x1
//         00514b32     ADD        this,0x1146c
//         00514b38     CALL       TribeTacticalAIModule::actualGathererCount       int actualGathererCount(TribeTacticalAIModule
//         00514b3d     MOV        this,dword ptr [ESI + 0x238]
//         00514b43     PUSH       EAX
//         00514b44     PUSH       0x1
//         00514b46     ADD        this,0x1146c
//         00514b4c     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514b51     MOV        this,dword ptr [ESI + 0x238]
//         00514b57     PUSH       EAX
//         00514b58     ADD        this,0x10d7c
//         00514b5e     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514b63     MOV        this,dword ptr [ESI + 0x238]
//         00514b69     PUSH       EAX
//         00514b6a     PUSH       0x0
//         00514b6c     ADD        this,0x1146c
//         00514b72     CALL       TribeTacticalAIModule::desiredGathererCount      int desiredGathererCount(TribeTacticalAIModul
//         00514b77     MOV        this,dword ptr [ESI + 0x238]
//         00514b7d     PUSH       EAX
//         00514b7e     PUSH       0x0
//         00514b80     ADD        this,0x1146c
//         00514b86     CALL       TribeTacticalAIModule::actualGathererCount       int actualGathererCount(TribeTacticalAIModule
//         00514b8b     MOV        this,dword ptr [ESI + 0x238]
//         00514b91     PUSH       EAX
//         00514b92     PUSH       0x0
//         00514b94     ADD        this,0x1146c
//         00514b9a     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00514b9f     MOV        this,dword ptr [ESI + 0x238]
//         00514ba5     PUSH       EAX
//         00514ba6     ADD        this,0x10d7c
//         00514bac     CALL       TribeResourceAIModule::resourceName              char * resourceName(TribeResourceAIModule * t
//         00514bb1     PUSH       EAX
//         00514bb2     PUSH       s_Gat(Act/Des):_%s=(%d/%d),_%s=(%d               = "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(
//         00514bb7     PUSH       EDI
//         00514bb8     CALL       sprintf                                          undefined sprintf()
//         00514bbd     ADD        ESP,0x44
//                              tplayer.cpp:1870 (2)
//         00514bc0     MOV        EAX,EDI
//                              tplayer.cpp:1928 (8)
//         00514bc2     POP        EDI
//         00514bc3     POP        ESI
//         00514bc4     POP        EBP
//         00514bc5     POP        EBX
//         00514bc6     POP        this
//         00514bc7     RET        0x4
//                               LAB_00514bca                                                 XREF[1]:     00514a3e(j)
//                              tplayer.cpp:1872 (9)
//         00514bca     CMP        this,0x4
//         00514bcd     JNZ        LAB_00514c97
//                              tplayer.cpp:1882 (186)
//         00514bd3     PUSH       0x9e
//         00514bd8     LEA        this,[EAX + 0x1146c]
//         00514bde     LEA        EDI,[ESI + 0x53c]
//         00514be4     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514be9     MOV        this,dword ptr [ESI + 0x238]
//         00514bef     PUSH       EAX
//                              language.dll match for 0x77: "Arial"
//         00514bf0     PUSH       0x77
//         00514bf2     ADD        this,0x1146c
//         00514bf8     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514bfd     MOV        this,dword ptr [ESI + 0x238]
//         00514c03     PUSH       EAX
//         00514c04     PUSH       0x9f
//         00514c09     ADD        this,0x1146c
//         00514c0f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c14     MOV        this,dword ptr [ESI + 0x238]
//         00514c1a     PUSH       EAX
//                              language.dll match for 0x76: "B"
//         00514c1b     PUSH       0x76
//         00514c1d     ADD        this,0x1146c
//         00514c23     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c28     MOV        this,dword ptr [ESI + 0x238]
//         00514c2e     PUSH       EAX
//         00514c2f     PUSH       0x9d
//         00514c34     ADD        this,0x1146c
//         00514c3a     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c3f     MOV        this,dword ptr [ESI + 0x238]
//         00514c45     PUSH       EAX
//                              language.dll match for 0x78: "10"
//         00514c46     PUSH       0x78
//         00514c48     ADD        this,0x1146c
//         00514c4e     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c53     MOV        this,dword ptr [ESI + 0x238]
//         00514c59     PUSH       EAX
//         00514c5a     PUSH       0x9c
//         00514c5f     ADD        this,0x1146c
//         00514c65     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c6a     MOV        this,dword ptr [ESI + 0x238]
//         00514c70     PUSH       EAX
//                              language.dll match for 0x75: "12"
//         00514c71     PUSH       0x75
//         00514c73     ADD        this,0x1146c
//         00514c79     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514c7e     PUSH       EAX
//         00514c7f     PUSH       s_Pers_(Spec/BL):_Food=(%d/%d),_Wo               = "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d)
//         00514c84     PUSH       EDI
//         00514c85     CALL       sprintf                                          undefined sprintf()
//         00514c8a     ADD        ESP,0x28
//                              tplayer.cpp:1883 (2)
//         00514c8d     MOV        EAX,EDI
//                              tplayer.cpp:1928 (8)
//         00514c8f     POP        EDI
//         00514c90     POP        ESI
//         00514c91     POP        EBP
//         00514c92     POP        EBX
//         00514c93     POP        this
//         00514c94     RET        0x4
//                               LAB_00514c97                                                 XREF[1]:     00514bcd(j)
//                              tplayer.cpp:1885 (9)
//         00514c97     CMP        this,0x5
//         00514c9a     JNZ        LAB_00514ec8
//                              tplayer.cpp:1911 (542)
//         00514ca0     PUSH       0x2
//         00514ca2     PUSH       0x8
//         00514ca4     LEA        this,[EAX + 0x9dc]
//         00514caa     LEA        EDI,[ESI + 0x63c]
//         00514cb0     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514cb5     MOV        this,dword ptr [ESI + 0x238]
//         00514cbb     PUSH       EAX
//         00514cbc     PUSH       0x1
//         00514cbe     PUSH       0x8
//         00514cc0     ADD        this,0x9dc
//         00514cc6     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514ccb     MOV        this,dword ptr [ESI + 0x238]
//         00514cd1     PUSH       EAX
//         00514cd2     PUSH       0x0
//         00514cd4     PUSH       0x8
//         00514cd6     ADD        this,0x9dc
//         00514cdc     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514ce1     MOV        this,dword ptr [ESI + 0x238]
//         00514ce7     PUSH       EAX
//         00514ce8     PUSH       0x2
//         00514cea     PUSH       0x7
//         00514cec     ADD        this,0x9dc
//         00514cf2     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514cf7     MOV        this,dword ptr [ESI + 0x238]
//         00514cfd     PUSH       EAX
//         00514cfe     PUSH       0x1
//         00514d00     PUSH       0x7
//         00514d02     ADD        this,0x9dc
//         00514d08     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d0d     MOV        this,dword ptr [ESI + 0x238]
//         00514d13     PUSH       EAX
//         00514d14     PUSH       0x0
//         00514d16     PUSH       0x7
//         00514d18     ADD        this,0x9dc
//         00514d1e     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d23     MOV        this,dword ptr [ESI + 0x238]
//         00514d29     PUSH       EAX
//         00514d2a     PUSH       0x2
//         00514d2c     PUSH       0x6
//         00514d2e     ADD        this,0x9dc
//         00514d34     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d39     MOV        this,dword ptr [ESI + 0x238]
//         00514d3f     PUSH       EAX
//         00514d40     PUSH       0x1
//         00514d42     PUSH       0x6
//         00514d44     ADD        this,0x9dc
//         00514d4a     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d4f     MOV        this,dword ptr [ESI + 0x238]
//         00514d55     PUSH       EAX
//         00514d56     PUSH       0x0
//         00514d58     PUSH       0x6
//         00514d5a     ADD        this,0x9dc
//         00514d60     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d65     MOV        this,dword ptr [ESI + 0x238]
//         00514d6b     PUSH       EAX
//         00514d6c     PUSH       0x2
//         00514d6e     PUSH       0x5
//         00514d70     ADD        this,0x9dc
//         00514d76     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d7b     MOV        this,dword ptr [ESI + 0x238]
//         00514d81     PUSH       EAX
//         00514d82     PUSH       0x1
//         00514d84     PUSH       0x5
//         00514d86     ADD        this,0x9dc
//         00514d8c     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514d91     MOV        this,dword ptr [ESI + 0x238]
//         00514d97     PUSH       EAX
//         00514d98     PUSH       0x0
//         00514d9a     PUSH       0x5
//         00514d9c     ADD        this,0x9dc
//         00514da2     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514da7     MOV        this,dword ptr [ESI + 0x238]
//         00514dad     PUSH       EAX
//         00514dae     PUSH       0x2
//         00514db0     PUSH       0x4
//         00514db2     ADD        this,0x9dc
//         00514db8     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514dbd     MOV        this,dword ptr [ESI + 0x238]
//         00514dc3     PUSH       EAX
//         00514dc4     PUSH       0x1
//         00514dc6     PUSH       0x4
//         00514dc8     ADD        this,0x9dc
//         00514dce     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514dd3     MOV        this,dword ptr [ESI + 0x238]
//         00514dd9     PUSH       EAX
//         00514dda     PUSH       0x0
//         00514ddc     PUSH       0x4
//         00514dde     ADD        this,0x9dc
//         00514de4     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514de9     MOV        this,dword ptr [ESI + 0x238]
//         00514def     PUSH       EAX
//         00514df0     PUSH       0x2
//         00514df2     PUSH       0x3
//         00514df4     ADD        this,0x9dc
//         00514dfa     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514dff     MOV        this,dword ptr [ESI + 0x238]
//         00514e05     PUSH       EAX
//         00514e06     PUSH       0x1
//         00514e08     PUSH       0x3
//         00514e0a     ADD        this,0x9dc
//         00514e10     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e15     MOV        this,dword ptr [ESI + 0x238]
//         00514e1b     PUSH       EAX
//         00514e1c     PUSH       0x0
//         00514e1e     PUSH       0x3
//         00514e20     ADD        this,0x9dc
//         00514e26     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e2b     MOV        this,dword ptr [ESI + 0x238]
//         00514e31     PUSH       EAX
//         00514e32     PUSH       0x2
//         00514e34     PUSH       0x2
//         00514e36     ADD        this,0x9dc
//         00514e3c     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e41     MOV        this,dword ptr [ESI + 0x238]
//         00514e47     PUSH       EAX
//         00514e48     PUSH       0x1
//         00514e4a     PUSH       0x2
//         00514e4c     ADD        this,0x9dc
//         00514e52     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e57     MOV        this,dword ptr [ESI + 0x238]
//         00514e5d     PUSH       EAX
//         00514e5e     PUSH       0x0
//         00514e60     PUSH       0x2
//         00514e62     ADD        this,0x9dc
//         00514e68     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e6d     MOV        this,dword ptr [ESI + 0x238]
//         00514e73     PUSH       EAX
//         00514e74     PUSH       0x2
//         00514e76     PUSH       0x1
//         00514e78     ADD        this,0x9dc
//         00514e7e     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e83     MOV        this,dword ptr [ESI + 0x238]
//         00514e89     PUSH       EAX
//         00514e8a     PUSH       0x1
//         00514e8c     PUSH       0x1
//         00514e8e     ADD        this,0x9dc
//         00514e94     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514e99     MOV        this,dword ptr [ESI + 0x238]
//         00514e9f     PUSH       EAX
//         00514ea0     PUSH       0x0
//         00514ea2     PUSH       0x1
//         00514ea4     ADD        this,0x9dc
//         00514eaa     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
//         00514eaf     PUSH       EAX
//         00514eb0     PUSH       s_Dip:_P1(%d/%d/%d),_P2(%d/%d/%d),               = "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/
//         00514eb5     PUSH       EDI
//         00514eb6     CALL       sprintf                                          undefined sprintf()
//         00514ebb     ADD        ESP,0x68
//                              tplayer.cpp:1912 (2)
//         00514ebe     MOV        EAX,EDI
//                              tplayer.cpp:1928 (8)
//         00514ec0     POP        EDI
//         00514ec1     POP        ESI
//         00514ec2     POP        EBP
//         00514ec3     POP        EBX
//         00514ec4     POP        this
//         00514ec5     RET        0x4
//                               LAB_00514ec8                                                 XREF[1]:     00514c9a(j)
//                              tplayer.cpp:1914 (9)
//         00514ec8     CMP        this,0x6
//         00514ecb     JNZ        LAB_00514f83
//                              tplayer.cpp:1924 (168)
//         00514ed1     MOV        this,dword ptr [ESI + 0x3c]
//         00514ed4     MOV        EAX,dword ptr [EAX + 0x12284]
//         00514eda     MOV        EDI,dword ptr [ESI + 0x3c]
//         00514edd     MOV        dword ptr [ESP + local_4],EAX
//         00514ee1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00514ee7     MOV        this,dword ptr [ECX + this->_padding_]
//         00514eea     LEA        EBX,[ESI + 0x73c]
//         00514ef0     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         00514ef3     MOV        this,dword ptr [EDX + 0x238]
//         00514ef9     MOV        EBP,dword ptr [this->_padding_ + 0x12468]
//         00514eff     MOV        EDX,dword ptr [this->_padding_ + 0x1246c]
//         00514f05     ADD        this,0x1146c
//         00514f0b     MOV        dword ptr [ESP + param_1],EDX
//         00514f0f     CALL       TribeTacticalAIModule::updateAreaName            char * updateAreaName(TribeTacticalAIModule *
//         00514f14     MOV        this,dword ptr [ESP + param_1]
//         00514f18     MOV        EDX,dword ptr [EDI + 0xfc]
//         00514f1e     PUSH       EAX
//         00514f1f     XOR        EAX,EAX
//         00514f21     MOV        AL,byte ptr [EDI + 0x11d]
//         00514f27     PUSH       EBP
//         00514f28     PUSH       this
//         00514f29     MOV        this,dword ptr [ESI + 0x238]
//         00514f2f     PUSH       EDX
//         00514f30     PUSH       EAX
//                              language.dll match for 0x68: "Arial"
//         00514f31     PUSH       0x68
//         00514f33     ADD        this,0x1146c
//         00514f39     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//         00514f3e     MOV        this,EAX
//         00514f40     MOV        EAX,0x88888889
//         00514f45     IMUL       this
//         00514f47     ADD        EDX,this
//         00514f49     SAR        EDX,0x5
//         00514f4c     MOV        this,EDX
//         00514f4e     SHR        this,0x1f
//         00514f51     ADD        EDX,this
//         00514f53     MOV        this,dword ptr [ESI + 0x238]
//         00514f59     PUSH       EDX
//         00514f5a     MOV        EDX,dword ptr [ESP + local_4]
//         00514f5e     PUSH       EDX
//         00514f5f     ADD        this,0x10e74
//         00514f65     CALL       TribeStrategyAIModule::ruleSetName               char * ruleSetName(TribeStrategyAIModule * th
//         00514f6a     PUSH       EAX
//         00514f6b     PUSH       s_Per:_%s,_AttEnab=%d,_AttDly=%d_M               = "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=
//         00514f70     PUSH       EBX
//         00514f71     CALL       sprintf                                          undefined sprintf()
//         00514f76     ADD        ESP,0x28
//                              tplayer.cpp:1925 (2)
//         00514f79     MOV        EAX,EBX
//                              tplayer.cpp:1928 (21)
//         00514f7b     POP        EDI
//         00514f7c     POP        ESI
//         00514f7d     POP        EBP
//         00514f7e     POP        EBX
//         00514f7f     POP        this
//         00514f80     RET        0x4
//                               LAB_00514f83                                                 XREF[1]:     00514ecb(j)
//         00514f83     POP        EDI
//         00514f84     POP        ESI
//         00514f85     POP        EBP
//         00514f86     MOV        EAX,s_Invalid_status_line_number.                = "Invalid status line number."
//         00514f8b     POP        EBX
//         00514f8c     POP        this
//         00514f8d     RET        0x4
    return 0;
}

void TRIBE_Player::kickAI(int param_1) {
    /* TODO: Stub */
//                              void __thiscall kickAI(TRIBE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00514f9a(R)
//                               ?kickAI@TRIBE_Player@@UAEXH@Z                                XREF[2]:     005768a8(*), 005769d8(*)
//                               TRIBE_Player::kickAI
//                              tplayer.cpp:1933 (10)
//         00514f90     MOV        this,dword ptr [ECX + this->playerAI]
//         00514f96     TEST       this,this
//         00514f98     JZ         LAB_00514fa4
//                              tplayer.cpp:1935 (10)
//         00514f9a     MOV        EAX,dword ptr [ESP + param_1]
//         00514f9e     PUSH       EAX
//         00514f9f     CALL       TribeMainDecisionAIModule::kick                  void kick(TribeMainDecisionAIModule * this, i
//                               LAB_00514fa4                                                 XREF[1]:     00514f98(j)
//                              tplayer.cpp:1936 (3)
//         00514fa4     RET        0x4
//         00514fa7     ??         90h
//         00514fa8     NOP
//         00514fa9     NOP
//         00514faa     NOP
//         00514fab     NOP
//         00514fac     NOP
//         00514fad     NOP
//         00514fae     NOP
//         00514faf     NOP
    return;
}

int TRIBE_Player::strategicNumber(int param_1) {
    /* TODO: Stub */
//                              int __thiscall strategicNumber(TRIBE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00514fba(R)
//                               ?strategicNumber@TRIBE_Player@@UAEHH@Z                       XREF[2]:     005768ac(*), 005769dc(*)
//                               TRIBE_Player::strategicNumber
//                              tplayer.cpp:1941 (10)
//         00514fb0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00514fb6     TEST       EAX,EAX
//         00514fb8     JZ         LAB_00514fcd
//                              tplayer.cpp:1943 (16)
//         00514fba     MOV        this,dword ptr [ESP + param_1]
//         00514fbe     PUSH       this
//         00514fbf     LEA        this,[EAX + 0x1146c]
//         00514fc5     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
//                              tplayer.cpp:1945 (3)
//         00514fca     RET        0x4
//                               LAB_00514fcd                                                 XREF[1]:     00514fb8(j)
//                              tplayer.cpp:1944 (3)
//         00514fcd     OR         EAX,0xffffffff
//                              tplayer.cpp:1945 (3)
//         00514fd0     RET        0x4
//         00514fd3     ??         90h
//         00514fd4     NOP
//         00514fd5     NOP
//         00514fd6     NOP
//         00514fd7     NOP
//         00514fd8     NOP
//         00514fd9     NOP
//         00514fda     NOP
//         00514fdb     NOP
//         00514fdc     NOP
//         00514fdd     NOP
//         00514fde     NOP
//         00514fdf     NOP
    return 0;
}

void TRIBE_Player::logMessage(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall logMessage(TRIBE_Player * this, char * param_1, ...)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00514fe7(R)
//              char[1024]        Stack[-0x404   textOut                   XREF[0,2]:   00515007(*), 0051501b(*)
//                               ?logMessage@TRIBE_Player@@UAAXPADZZ                          XREF[2]:     00576954(*), 00576a84(*)
//                               TRIBE_Player::logMessage
//                              tplayer.cpp:1950 (7)
//         00514fe0     SUB        ESP,0x400
//         00514fe6     PUSH       ESI
//                              tplayer.cpp:1951 (17)
//         00514fe7     MOV        ESI,dword ptr [ESP + param_1]
//         00514fee     MOV        EAX,dword ptr [ESI + 0x238]
//         00514ff4     TEST       EAX,EAX
//         00514ff6     JZ         LAB_00515029
//                              tplayer.cpp:1955 (26)
//         00514ff8     MOV        this,dword ptr [ESP + Stack[0x8]]
//         00514fff     LEA        EAX=>Stack[0xc],[ESP + 0x410]
//         00515006     PUSH       EAX
//         00515007     LEA        EDX=>textOut[4],[ESP + 0x8]
//         0051500b     PUSH       this
//         0051500c     PUSH       EDX
//         0051500d     CALL       vsprintf                                         undefined vsprintf()
//                              tplayer.cpp:1957 (23)
//         00515012     MOV        this,dword ptr [ESI + 0x238]
//         00515018     ADD        ESP,0xc
//         0051501b     LEA        EAX=>textOut[4],[ESP + 0x4]
//         0051501f     PUSH       EAX
//         00515020     PUSH       this
//         00515021     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         00515026     ADD        ESP,0x8
//                               LAB_00515029                                                 XREF[1]:     00514ff6(j)
//                              tplayer.cpp:1959 (8)
//         00515029     POP        ESI
//         0051502a     ADD        ESP,0x400
//         00515030     RET
//         00515031     ??         90h
//         00515032     NOP
//         00515033     NOP
//         00515034     NOP
//         00515035     NOP
//         00515036     NOP
//         00515037     NOP
//         00515038     NOP
//         00515039     NOP
//         0051503a     NOP
//         0051503b     NOP
//         0051503c     NOP
//         0051503d     NOP
//         0051503e     NOP
//         0051503f     NOP
    return;
}

int TRIBE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall sendAICommand(TRIBE_Player * this, int param_1, int p
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515062(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0051505d(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515058(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00515053(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0051504f(R)
//                               ?sendAICommand@TRIBE_Player@@UAEHHHHHH@Z                     XREF[2]:     005768c4(*), 005769f4(*)
//                               TRIBE_Player::sendAICommand
//                              tplayer.cpp:1964 (10)
//         00515040     MOV        this,dword ptr [ECX + this->playerAI]
//         00515046     TEST       this,this
//         00515048     JNZ        LAB_0051504f
//                              tplayer.cpp:1967 (2)
//         0051504a     XOR        EAX,EAX
//                              tplayer.cpp:1969 (3)
//         0051504c     RET        0x14
//                               LAB_0051504f                                                 XREF[1]:     00515048(j)
//                              tplayer.cpp:1968 (30)
//         0051504f     MOV        EAX,dword ptr [ESP + param_5]
//         00515053     MOV        EDX,dword ptr [ESP + param_4]
//         00515057     PUSH       EAX
//         00515058     MOV        EAX,dword ptr [ESP + param_3]
//         0051505c     PUSH       EDX
//         0051505d     MOV        EDX,dword ptr [ESP + param_2]
//         00515061     PUSH       EAX
//         00515062     MOV        EAX,dword ptr [ESP + param_1]
//         00515066     PUSH       EDX
//         00515067     PUSH       EAX
//         00515068     CALL       TribeMainDecisionAIModule::processAICommand      int processAICommand(TribeMainDecisionAIModul
//                              tplayer.cpp:1969 (3)
//         0051506d     RET        0x14
    return 0;
}

RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              RGE_Object_Node * __thiscall addObject(TRIBE_Player * this, RGE_Stat
//              RGE_Object_Nod    EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0051507d(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515078(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515070(R)
//                               ?addObject@TRIBE_Player@@UAEPAURGE_Object_Node@@PAVRGE_Stat  XREF[2]:     0057694c(*), 00576a7c(*)
//                               TRIBE_Player::addObject
//                              tplayer.cpp:1974 (27)
//         00515070     MOV        EAX,dword ptr [ESP + param_3]
//         00515074     PUSH       EBX
//         00515075     PUSH       ESI
//         00515076     MOV        ESI,this
//         00515078     MOV        this,dword ptr [ESP + param_2]
//         0051507c     PUSH       EDI
//         0051507d     MOV        EDI,dword ptr [ESP + param_1]
//         00515081     PUSH       EAX
//         00515082     PUSH       this
//         00515083     PUSH       EDI
//         00515084     MOV        this,ESI
//         00515086     CALL       RGE_Player::addObject                            RGE_Object_Node * addObject(RGE_Player * this
//                              tplayer.cpp:1982 (10)
//         0051508b     MOV        EDX,dword ptr [EDI + 0x8]
//         0051508e     MOV        EBX,EAX
//         00515090     CMP        word ptr [EDX + 0x14],0xb
//                              tplayer.cpp:1983 (2)
//         00515095     JZ         LAB_005150d1
//                              tplayer.cpp:1986 (17)
//         00515097     MOV        this,dword ptr [ESI + 0x238]
//         0051509d     TEST       this,this
//         0051509f     JZ         LAB_005150d1
//         005150a1     MOV        EAX,dword ptr [EDI + 0x4]
//         005150a4     TEST       EAX,EAX
//         005150a6     JL         LAB_005150d1
//                              tplayer.cpp:1987 (6)
//         005150a8     MOV        EAX,dword ptr [this->_padding_]
//         005150aa     PUSH       EDI
//         005150ab     CALL       dword ptr [EAX + 0x40]
//                              tplayer.cpp:1991 (14)
//         005150ae     MOV        this,dword ptr [ESI + 0x3c]
//         005150b1     MOV        EAX,0x1
//         005150b6     CMP        byte ptr [ECX + this+0x1d],0x2
//         005150ba     JNZ        LAB_005150be
//                              tplayer.cpp:1992 (2)
//         005150bc     XOR        EAX,EAX
//                               LAB_005150be                                                 XREF[1]:     005150ba(j)
//                              tplayer.cpp:1993 (19)
//         005150be     MOV        this,dword ptr [ESI + 0x238]
//         005150c4     PUSH       EAX
//         005150c5     PUSH       EDI
//         005150c6     ADD        this,0x104
//         005150cc     CALL       TribeBuildAIModule::addItem                      int addItem(TribeBuildAIModule * this, RGE_St
//                               LAB_005150d1                                                 XREF[3]:     00515095(j), 0051509f(j),
//                                                                                                         005150a6(j)
//                              tplayer.cpp:1997 (8)
//         005150d1     POP        EDI
//         005150d2     MOV        EAX,EBX
//         005150d4     POP        ESI
//         005150d5     POP        EBX
//         005150d6     RET        0xc
//         005150d9     ??         90h
//         005150da     NOP
//         005150db     NOP
//         005150dc     NOP
//         005150dd     NOP
//         005150de     NOP
//         005150df     NOP
    return 0;
}

void TRIBE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) {
    /* TODO: Stub */
//                              void __thiscall removeObject(TRIBE_Player * this, RGE_Static_Object
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     005150f0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005150e4(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005150eb(R)
//              RGE_Object_Nod    Stack[0x10]:4  param_4                   XREF[1]:     005150e0(R)
//                               ?removeObject@TRIBE_Player@@UAEXPAVRGE_Static_Object@@HHPAU  XREF[2]:     00576950(*), 00576a80(*)
//                               TRIBE_Player::removeObject
//                              tplayer.cpp:2003 (31)
//         005150e0     MOV        EAX,dword ptr [ESP + param_4]
//         005150e4     MOV        EDX,dword ptr [ESP + param_2]
//         005150e8     PUSH       ESI
//         005150e9     MOV        ESI,this
//         005150eb     MOV        this,dword ptr [ESP + param_3]
//         005150ef     PUSH       EDI
//         005150f0     MOV        EDI,dword ptr [ESP + param_1]
//         005150f4     PUSH       EAX
//         005150f5     PUSH       this
//         005150f6     PUSH       EDX
//         005150f7     PUSH       EDI
//         005150f8     MOV        this,ESI
//         005150fa     CALL       RGE_Player::removeObject                         void removeObject(RGE_Player * this, RGE_Stat
//                              tplayer.cpp:2011 (27)
//         005150ff     MOV        this,dword ptr [ESI + 0x238]
//         00515105     TEST       this,this
//         00515107     JZ         LAB_00515120
//         00515109     MOV        EAX,dword ptr [EDI + 0x8]
//         0051510c     CMP        word ptr [EAX + 0x14],0xb
//         00515111     JZ         LAB_00515120
//         00515113     MOV        EAX,dword ptr [EDI + 0x4]
//         00515116     TEST       EAX,EAX
//         00515118     JL         LAB_00515120
//                              tplayer.cpp:2012 (6)
//         0051511a     MOV        EDX,dword ptr [this->_padding_]
//         0051511c     PUSH       EAX
//         0051511d     CALL       dword ptr [EDX + 0x44]
//                               LAB_00515120                                                 XREF[3]:     00515107(j), 00515111(j),
//                                                                                                         00515118(j)
//                              tplayer.cpp:2013 (5)
//         00515120     POP        EDI
//         00515121     POP        ESI
//         00515122     RET        0x10
//         00515125     ??         90h
//         00515126     NOP
//         00515127     NOP
//         00515128     NOP
//         00515129     NOP
//         0051512a     NOP
//         0051512b     NOP
//         0051512c     NOP
//         0051512d     NOP
//         0051512e     NOP
//         0051512f     NOP
    return;
}

void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5) {
    /* TODO: Stub */
//                              void __thiscall buildObject(TRIBE_Player * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515147(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515155(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00515150(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00515141(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0051513d(R)
//                               ?buildObject@TRIBE_Player@@UAEXHHMMH@Z                       XREF[2]:     0057696c(*), 00576a9c(*)
//                               TRIBE_Player::buildObject
//                              tplayer.cpp:2018 (2)
//         00515130     PUSH       ESI
//         00515131     PUSH       EDI
//                              tplayer.cpp:2020 (11)
//         00515132     PUSH       0x4
//         00515134     MOV        EDI,this
//         00515136     PUSH       0x1
//         00515138     CALL       calloc                                           undefined calloc()
//                              tplayer.cpp:2023 (50)
//         0051513d     MOV        this,dword ptr [ESP + param_5]
//         00515141     MOV        EDX,dword ptr [ESP + param_4]
//         00515145     MOV        ESI,EAX
//         00515147     MOV        EAX,dword ptr [ESP + param_1]
//         0051514b     ADD        ESP,0x8
//         0051514e     MOV        dword ptr [ESI],EAX
//         00515150     MOV        EAX,dword ptr [ESP + param_3]
//         00515154     PUSH       this
//         00515155     MOV        this,dword ptr [ESP + param_2]
//         00515159     PUSH       EDX
//         0051515a     PUSH       EAX
//         0051515b     MOVSX      EDX,word ptr [EDI + 0x4a]
//         0051515f     MOV        EAX,dword ptr [EDI + 0x3c]
//         00515162     PUSH       this
//         00515163     PUSH       0x1
//         00515165     PUSH       ESI
//         00515166     MOV        this,dword ptr [EAX + 0x58]
//         00515169     PUSH       EDX
//         0051516a     CALL       TRIBE_Command::command_build                     void command_build(TRIBE_Command * this, int
//                              tplayer.cpp:2025 (9)
//         0051516f     PUSH       ESI
//         00515170     CALL       free                                             undefined free()
//         00515175     ADD        ESP,0x4
//                              tplayer.cpp:2026 (5)
//         00515178     POP        EDI
//         00515179     POP        ESI
//         0051517a     RET        0x14
//         0051517d     ??         90h
//         0051517e     NOP
//         0051517f     NOP
    return;
}

void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              void __thiscall cancelBuild(TRIBE_Player * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005151a7(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005151a2(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0051519d(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00515198(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     00515193(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0051518e(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0051518a(R)
//                               ?cancelBuild@TRIBE_Player@@UAEXHHHMMHH@Z                     XREF[2]:     00576970(*), 00576aa0(*)
//                               TRIBE_Player::cancelBuild
//                              tplayer.cpp:2032 (10)
//         00515180     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00515186     TEST       EAX,EAX
//         00515188     JZ         LAB_005151b8
//                              tplayer.cpp:2035 (46)
//         0051518a     MOV        this,dword ptr [ESP + param_7]
//         0051518e     MOV        EDX,dword ptr [ESP + param_6]
//         00515192     PUSH       this
//         00515193     MOV        this,dword ptr [ESP + param_5]
//         00515197     PUSH       EDX
//         00515198     MOV        EDX,dword ptr [ESP + param_4]
//         0051519c     PUSH       this
//         0051519d     MOV        this,dword ptr [ESP + param_3]
//         005151a1     PUSH       EDX
//         005151a2     MOV        EDX,dword ptr [ESP + param_2]
//         005151a6     PUSH       this
//         005151a7     MOV        this,dword ptr [ESP + param_1]
//         005151ab     PUSH       EDX
//         005151ac     PUSH       this
//         005151ad     LEA        this,[EAX + 0x104]
//         005151b3     CALL       TribeBuildAIModule::cancelBuildItem              int cancelBuildItem(TribeBuildAIModule * this
//                               LAB_005151b8                                                 XREF[1]:     00515188(j)
//                              tplayer.cpp:2036 (3)
//         005151b8     RET        0x1c
//         005151bb     ??         90h
//         005151bc     NOP
//         005151bd     NOP
//         005151be     NOP
//         005151bf     NOP
    return;
}

void TRIBE_Player::registerBuild(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall registerBuild(TRIBE_Player * this, RGE_Static_Object
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     005151ce(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005151ca(R)
//                               ?registerBuild@TRIBE_Player@@UAEXPAVRGE_Static_Object@@H@Z   XREF[2]:     00576974(*), 00576aa4(*)
//                               TRIBE_Player::registerBuild
//                              tplayer.cpp:2041 (10)
//         005151c0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005151c6     TEST       EAX,EAX
//         005151c8     JZ         LAB_005151df
//                              tplayer.cpp:2043 (21)
//         005151ca     MOV        this,dword ptr [ESP + param_2]
//         005151ce     MOV        EDX,dword ptr [ESP + param_1]
//         005151d2     PUSH       this
//         005151d3     PUSH       EDX
//         005151d4     LEA        this,[EAX + 0x104]
//         005151da     CALL       TribeBuildAIModule::addBuiltItem                 int addBuiltItem(TribeBuildAIModule * this, R
//                               LAB_005151df                                                 XREF[1]:     005151c8(j)
//                              tplayer.cpp:2044 (3)
//         005151df     RET        0x8
//         005151e2     ??         90h
//         005151e3     NOP
//         005151e4     NOP
//         005151e5     NOP
//         005151e6     NOP
//         005151e7     NOP
//         005151e8     NOP
//         005151e9     NOP
//         005151ea     NOP
//         005151eb     NOP
//         005151ec     NOP
//         005151ed     NOP
//         005151ee     NOP
//         005151ef     NOP
    return;
}

void TRIBE_Player::trainUnit(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall trainUnit(TRIBE_Player * this, int param_1, int para
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005151f4(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005151f9(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005151f0(R)
//                               ?trainUnit@TRIBE_Player@@UAEXHHH@Z                           XREF[2]:     00576978(*), 00576aa8(*)
//                               TRIBE_Player::trainUnit
//                              tplayer.cpp:2049 (31)
//         005151f0     MOV        EAX,dword ptr [ESP + param_3]
//         005151f4     MOV        EDX,dword ptr [ESP + param_1]
//         005151f8     PUSH       EAX
//         005151f9     MOV        EAX,dword ptr [ESP + param_2]
//         005151fd     PUSH       EDX
//         005151fe     PUSH       EAX
//         005151ff     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         00515203     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00515206     PUSH       EDX
//         00515207     MOV        this,dword ptr [EAX + 0x58]
//         0051520a     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, int p
//                              tplayer.cpp:2052 (3)
//         0051520f     RET        0xc
//         00515212     ??         90h
//         00515213     NOP
//         00515214     NOP
//         00515215     NOP
//         00515216     NOP
//         00515217     NOP
//         00515218     NOP
//         00515219     NOP
//         0051521a     NOP
//         0051521b     NOP
//         0051521c     NOP
//         0051521d     NOP
//         0051521e     NOP
//         0051521f     NOP
    return;
}

void TRIBE_Player::cancelTrain(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall cancelTrain(TRIBE_Player * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515238(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515233(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0051522e(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0051522a(R)
//                               ?cancelTrain@TRIBE_Player@@UAEXHHHH@Z                        XREF[2]:     0057697c(*), 00576aac(*)
//                               TRIBE_Player::cancelTrain
//                              tplayer.cpp:2058 (10)
//         00515220     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00515226     TEST       EAX,EAX
//         00515228     JZ         LAB_00515249
//                              tplayer.cpp:2060 (31)
//         0051522a     MOV        this,dword ptr [ESP + param_4]
//         0051522e     MOV        EDX,dword ptr [ESP + param_3]
//         00515232     PUSH       this
//         00515233     MOV        this,dword ptr [ESP + param_2]
//         00515237     PUSH       EDX
//         00515238     MOV        EDX,dword ptr [ESP + param_1]
//         0051523c     PUSH       this
//         0051523d     PUSH       EDX
//         0051523e     LEA        this,[EAX + 0x104]
//         00515244     CALL       TribeBuildAIModule::cancelTrainUnit              int cancelTrainUnit(TribeBuildAIModule * this
//                               LAB_00515249                                                 XREF[1]:     00515228(j)
//                              tplayer.cpp:2061 (3)
//         00515249     RET        0x10
//         0051524c     ??         90h
//         0051524d     NOP
//         0051524e     NOP
//         0051524f     NOP
    return;
}

void TRIBE_Player::registerTrain(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall registerTrain(TRIBE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515268(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515263(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0051525e(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0051525a(R)
//                               ?registerTrain@TRIBE_Player@@UAEXHHHH@Z                      XREF[2]:     00576980(*), 00576ab0(*)
//                               TRIBE_Player::registerTrain
//                              tplayer.cpp:2067 (10)
//         00515250     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00515256     TEST       EAX,EAX
//         00515258     JZ         LAB_00515279
//                              tplayer.cpp:2069 (31)
//         0051525a     MOV        this,dword ptr [ESP + param_4]
//         0051525e     MOV        EDX,dword ptr [ESP + param_3]
//         00515262     PUSH       this
//         00515263     MOV        this,dword ptr [ESP + param_2]
//         00515267     PUSH       EDX
//         00515268     MOV        EDX,dword ptr [ESP + param_1]
//         0051526c     PUSH       this
//         0051526d     PUSH       EDX
//         0051526e     LEA        this,[EAX + 0x104]
//         00515274     CALL       TribeBuildAIModule::addTrainedUnit               int addTrainedUnit(TribeBuildAIModule * this,
//                               LAB_00515279                                                 XREF[1]:     00515258(j)
//                              tplayer.cpp:2070 (3)
//         00515279     RET        0x10
//         0051527c     ??         90h
//         0051527d     NOP
//         0051527e     NOP
//         0051527f     NOP
    return;
}

void TRIBE_Player::research(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall research(TRIBE_Player * this, int param_1, int param
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515284(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515289(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515280(R)
//                               ?research@TRIBE_Player@@UAEXHHH@Z                            XREF[2]:     00576984(*), 00576ab4(*)
//                               TRIBE_Player::research
//                              tplayer.cpp:2075 (31)
//         00515280     MOV        EAX,dword ptr [ESP + param_3]
//         00515284     MOV        EDX,dword ptr [ESP + param_1]
//         00515288     PUSH       EAX
//         00515289     MOV        EAX,dword ptr [ESP + param_2]
//         0051528d     PUSH       EDX
//         0051528e     PUSH       EAX
//         0051528f     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         00515293     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00515296     PUSH       EDX
//         00515297     MOV        this,dword ptr [EAX + 0x58]
//         0051529a     CALL       TRIBE_Command::command_research                  void command_research(TRIBE_Command * this, i
//                              tplayer.cpp:2078 (3)
//         0051529f     RET        0xc
//         005152a2     ??         90h
//         005152a3     NOP
//         005152a4     NOP
//         005152a5     NOP
//         005152a6     NOP
//         005152a7     NOP
//         005152a8     NOP
//         005152a9     NOP
//         005152aa     NOP
//         005152ab     NOP
//         005152ac     NOP
//         005152ad     NOP
//         005152ae     NOP
//         005152af     NOP
    return;
}

void TRIBE_Player::cancelResearch(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall cancelResearch(TRIBE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005152c8(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005152c3(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005152be(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     005152ba(R)
//                               ?cancelResearch@TRIBE_Player@@UAEXHHHH@Z                     XREF[2]:     00576988(*), 00576ab8(*)
//                               TRIBE_Player::cancelResearch
//                              tplayer.cpp:2084 (10)
//         005152b0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005152b6     TEST       EAX,EAX
//         005152b8     JZ         LAB_005152d9
//                              tplayer.cpp:2086 (31)
//         005152ba     MOV        this,dword ptr [ESP + param_4]
//         005152be     MOV        EDX,dword ptr [ESP + param_3]
//         005152c2     PUSH       this
//         005152c3     MOV        this,dword ptr [ESP + param_2]
//         005152c7     PUSH       EDX
//         005152c8     MOV        EDX,dword ptr [ESP + param_1]
//         005152cc     PUSH       this
//         005152cd     PUSH       EDX
//         005152ce     LEA        this,[EAX + 0x104]
//         005152d4     CALL       TribeBuildAIModule::cancelResearch               int cancelResearch(TribeBuildAIModule * this,
//                               LAB_005152d9                                                 XREF[1]:     005152b8(j)
//                              tplayer.cpp:2087 (3)
//         005152d9     RET        0x10
//         005152dc     ??         90h
//         005152dd     NOP
//         005152de     NOP
//         005152df     NOP
    return;
}

void TRIBE_Player::registerResearch(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall registerResearch(TRIBE_Player * this, int param_1, i
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005152f3(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005152ee(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005152ea(R)
//                               ?registerResearch@TRIBE_Player@@UAEXHHH@Z                    XREF[2]:     0057698c(*), 00576abc(*)
//                               TRIBE_Player::registerResearch
//                              tplayer.cpp:2092 (10)
//         005152e0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005152e6     TEST       EAX,EAX
//         005152e8     JZ         LAB_00515304
//                              tplayer.cpp:2094 (26)
//         005152ea     MOV        this,dword ptr [ESP + param_3]
//         005152ee     MOV        EDX,dword ptr [ESP + param_2]
//         005152f2     PUSH       this
//         005152f3     MOV        this,dword ptr [ESP + param_1]
//         005152f7     PUSH       EDX
//         005152f8     PUSH       this
//         005152f9     LEA        this,[EAX + 0x104]
//         005152ff     CALL       TribeBuildAIModule::addResearch                  int addResearch(TribeBuildAIModule * this, in
//                               LAB_00515304                                                 XREF[1]:     005152e8(j)
//                              tplayer.cpp:2095 (3)
//         00515304     RET        0xc
//         00515307     ??         90h
//         00515308     NOP
//         00515309     NOP
//         0051530a     NOP
//         0051530b     NOP
//         0051530c     NOP
//         0051530d     NOP
//         0051530e     NOP
//         0051530f     NOP
    return;
}

void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall taskTrader(TRIBE_Player * this, int param_1, int par
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515327(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515335(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515330(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00515321(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0051531d(R)
//                               ?taskTrader@TRIBE_Player@@UAEXHHHMM@Z                        XREF[2]:     00576990(*), 00576ac0(*)
//                               TRIBE_Player::taskTrader
//                              tplayer.cpp:2101 (2)
//         00515310     PUSH       ESI
//         00515311     PUSH       EDI
//                              tplayer.cpp:2104 (11)
//         00515312     PUSH       0x4
//         00515314     MOV        EDI,this
//         00515316     PUSH       0x1
//         00515318     CALL       calloc                                           undefined calloc()
//                              tplayer.cpp:2107 (50)
//         0051531d     MOV        this,dword ptr [ESP + param_5]
//         00515321     MOV        EDX,dword ptr [ESP + param_4]
//         00515325     MOV        ESI,EAX
//         00515327     MOV        EAX,dword ptr [ESP + param_1]
//         0051532b     ADD        ESP,0x8
//         0051532e     MOV        dword ptr [ESI],EAX
//         00515330     MOV        EAX,dword ptr [ESP + param_3]
//         00515334     PUSH       this
//         00515335     MOV        this,dword ptr [ESP + param_2]
//         00515339     PUSH       EDX
//         0051533a     PUSH       EAX
//         0051533b     MOVSX      EDX,word ptr [EDI + 0x4a]
//         0051533f     MOV        EAX,dword ptr [EDI + 0x3c]
//         00515342     PUSH       this
//         00515343     PUSH       0x1
//         00515345     PUSH       ESI
//         00515346     MOV        this,dword ptr [EAX + 0x58]
//         00515349     PUSH       EDX
//         0051534a     CALL       RGE_Command::command_work                        void command_work(RGE_Command * this, int par
//                              tplayer.cpp:2109 (9)
//         0051534f     PUSH       ESI
//         00515350     CALL       free                                             undefined free()
//         00515355     ADD        ESP,0x4
//                              tplayer.cpp:2110 (5)
//         00515358     POP        EDI
//         00515359     POP        ESI
//         0051535a     RET        0x14
//         0051535d     ??         90h
//         0051535e     NOP
//         0051535f     NOP
    return;
}

void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall taskResourceGatherer(TRIBE_Player * this, int param_
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515377(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515385(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515380(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00515371(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0051536d(R)
//                               ?taskResourceGatherer@TRIBE_Player@@UAEXHHHMM@Z              XREF[2]:     00576994(*), 00576ac4(*)
//                               TRIBE_Player::taskResourceGatherer
//                              tplayer.cpp:2116 (2)
//         00515360     PUSH       ESI
//         00515361     PUSH       EDI
//                              tplayer.cpp:2119 (11)
//         00515362     PUSH       0x4
//         00515364     MOV        EDI,this
//         00515366     PUSH       0x1
//         00515368     CALL       calloc                                           undefined calloc()
//                              tplayer.cpp:2122 (50)
//         0051536d     MOV        this,dword ptr [ESP + param_5]
//         00515371     MOV        EDX,dword ptr [ESP + param_4]
//         00515375     MOV        ESI,EAX
//         00515377     MOV        EAX,dword ptr [ESP + param_1]
//         0051537b     ADD        ESP,0x8
//         0051537e     MOV        dword ptr [ESI],EAX
//         00515380     MOV        EAX,dword ptr [ESP + param_3]
//         00515384     PUSH       this
//         00515385     MOV        this,dword ptr [ESP + param_2]
//         00515389     PUSH       EDX
//         0051538a     PUSH       EAX
//         0051538b     MOVSX      EDX,word ptr [EDI + 0x4a]
//         0051538f     MOV        EAX,dword ptr [EDI + 0x3c]
//         00515392     PUSH       this
//         00515393     PUSH       0x1
//         00515395     PUSH       ESI
//         00515396     MOV        this,dword ptr [EAX + 0x58]
//         00515399     PUSH       EDX
//         0051539a     CALL       RGE_Command::command_work                        void command_work(RGE_Command * this, int par
//                              tplayer.cpp:2124 (9)
//         0051539f     PUSH       ESI
//         005153a0     CALL       free                                             undefined free()
//         005153a5     ADD        ESP,0x4
//                              tplayer.cpp:2125 (5)
//         005153a8     POP        EDI
//         005153a9     POP        ESI
//         005153aa     RET        0x14
//         005153ad     ??         90h
//         005153ae     NOP
//         005153af     NOP
    return;
}

void TRIBE_Player::setDiplomaticStance(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setDiplomaticStance(TRIBE_Player * this, int param_1
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005153b4(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005153b0(R)
//                               ?setDiplomaticStance@TRIBE_Player@@UAEXHH@Z                  XREF[2]:     00576898(*), 005769c8(*)
//                               TRIBE_Player::setDiplomaticStance
//                              tplayer.cpp:2131 (26)
//         005153b0     MOV        EAX,dword ptr [ESP + param_2]
//         005153b4     MOV        EDX,dword ptr [ESP + param_1]
//         005153b8     PUSH       EAX
//         005153b9     MOV        AX,word ptr [ECX + this+0x4a]
//         005153bd     MOV        this,dword ptr [ECX + this->_padding_]
//         005153c0     PUSH       EDX
//         005153c1     PUSH       EAX
//         005153c2     MOV        this,dword ptr [ECX + this->_padding_]
//         005153c5     CALL       TRIBE_Command::command_relation                  void command_relation(TRIBE_Command * this, s
//                              tplayer.cpp:2138 (3)
//         005153ca     RET        0x8
//         005153cd     ??         90h
//         005153ce     NOP
//         005153cf     NOP
    return;
}

void TRIBE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              void __thiscall loadAIInformation(TRIBE_Player * this, char * param_
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//              char *            Stack[0x8]:4   param_2
//              char *            Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              char[256]         Stack[-0x104   noneString                XREF[0,1]:   00515488(*)
//              char[256]         Stack[-0x204   randomString
//              char[256]         Stack[-0x304   ruleSetName
//              char[256]         Stack[-0x404   buildListName             XREF[2]:     005153eb(W), 0051598d(R)
//              int               Stack[-0x408   saveRand                  XREF[2]:     005153f4(W), 00515991(R)
//              int               Stack[-0x40c   save_debug_random_on
//                               ?loadAIInformation@TRIBE_Player@@UAEXPAD00HH@Z               XREF[2]:     0057689c(*), 005769cc(*)
//                               TRIBE_Player::loadAIInformation
//                              tplayer.cpp:2145 (10)
//         005153d0     SUB        ESP,0x408
//         005153d6     PUSH       EBX
//         005153d7     PUSH       EBP
//         005153d8     PUSH       ESI
//         005153d9     PUSH       EDI
//                              tplayer.cpp:2147 (21)
//         005153da     PUSH       0x863
//         005153df     MOV        EBX,this
//         005153e1     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005153e6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005153eb     MOV        dword ptr [ESP + buildListName[0]],EAX
//                              tplayer.cpp:2150 (9)
//         005153ef     MOV        EAX,[debug_random_on]
//         005153f4     MOV        dword ptr [ESP + saveRand],EAX
//                              tplayer.cpp:2151 (5)
//         005153f8     MOV        [global_save_debug_random_on2],EAX
//                              tplayer.cpp:2152 (10)
//         005153fd     MOV        dword ptr [debug_random_on],0x0
//                              tplayer.cpp:2156 (17)
//         00515407     MOV        EAX,dword ptr [EBX + 0x238]
//         0051540d     ADD        ESP,0x8
//         00515410     TEST       EAX,EAX
//         00515412     JZ         LAB_0051598d
//                              tplayer.cpp:2158 (23)
//         00515418     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051541e     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         00515423     CMP        EAX,0x4
//         00515426     JA         switchD_00515428::default
//                               switchD_00515428::switchD
//         00515428     JMP        dword ptr [EAX*0x4 + switchD_00515428::switchd   = 0051542f
//                               switchD_00515428::caseD_0                                    XREF[2]:     00515428(j), 005159bc(*)
//                              tplayer.cpp:2160 (12)
//         0051542f     MOV        EAX,dword ptr [EBX + 0x238]
//         00515435     PUSH       s_We_have_an_all_water_map.                      = "We have an all water map."
//         0051543a     PUSH       EAX
//                              tplayer.cpp:2161 (2)
//         0051543b     JMP        LAB_0051547a
//                               switchD_00515428::caseD_1                                    XREF[2]:     00515428(j), 005159c0(*)
//                              tplayer.cpp:2163 (12)
//         0051543d     MOV        this,dword ptr [EBX + 0x238]
//         00515443     PUSH       s_We_have_a_mostly_water_map.                    = "We have a mostly water map."
//         00515448     PUSH       this
//                              tplayer.cpp:2164 (2)
//         00515449     JMP        LAB_0051547a
//                               switchD_00515428::caseD_2                                    XREF[2]:     00515428(j), 005159c4(*)
//                              tplayer.cpp:2166 (5)
//         0051544b     PUSH       s_We_have_a_land_and_water_map.                  = "We have a land and water map."
//                              tplayer.cpp:2167 (2)
//         00515450     JMP        LAB_00515473
//                               switchD_00515428::caseD_3                                    XREF[2]:     00515428(j), 005159c8(*)
//                              tplayer.cpp:2169 (12)
//         00515452     MOV        EAX,dword ptr [EBX + 0x238]
//         00515458     PUSH       s_We_have_a_mostly_land_map.                     = "We have a mostly land map."
//         0051545d     PUSH       EAX
//                              tplayer.cpp:2170 (2)
//         0051545e     JMP        LAB_0051547a
//                               switchD_00515428::caseD_4                                    XREF[2]:     00515428(j), 005159cc(*)
//                              tplayer.cpp:2172 (12)
//         00515460     MOV        this,dword ptr [EBX + 0x238]
//         00515466     PUSH       s_We_have_an_all_land_map.                       = "We have an all land map."
//         0051546b     PUSH       this
//                              tplayer.cpp:2173 (2)
//         0051546c     JMP        LAB_0051547a
//                               switchD_00515428::default                                    XREF[1]:     00515426(j)
//                              tplayer.cpp:2175 (17)
//         0051546e     PUSH       s_We_don't_have_a_specific_map_typ               = "We don't have a specific map type (i.e. th
//                               LAB_00515473                                                 XREF[1]:     00515450(j)
//         00515473     MOV        EDX,dword ptr [EBX + 0x238]
//         00515479     PUSH       EDX
//                               LAB_0051547a                                                 XREF[4]:     0051543b(j), 00515449(j),
//                                                                                                         0051545e(j), 0051546c(j)
//         0051547a     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2182 (32)
//         0051547f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515485     ADD        ESP,0x8
//         00515488     LEA        EDX=>noneString[4],[ESP + 0x318]
//         0051548f     MOV        EAX,dword ptr [this->_padding_]
//         00515491     PUSH       0x100
//         00515496     PUSH       EDX
//                              language.dll match for 0x2775: " <None> "
//         00515497     PUSH       0x2775
//         0051549c     CALL       dword ptr [EAX + 0x20]
//                              tplayer.cpp:2183 (29)
//         0051549f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005154a5     LEA        EDX,[ESP + 0x218]
//         005154ac     PUSH       0x100
//         005154b1     PUSH       EDX=>DAT_fffffff8
//         005154b2     MOV        EAX,dword ptr [this->_padding_]
//                              language.dll match for 0x277b: "Random"
//         005154b4     PUSH       offset DAT_fffffff4
//         005154b9     CALL       dword ptr [EAX + 0x20]
//                              tplayer.cpp:2187 (20)
//         005154bc     MOV        EDI,s_                                           = ""
//         005154c1     OR         this,0xffffffff
//         005154c4     XOR        EAX,EAX
//         005154c6     LEA        EDX,[ESP + 0x18]
//         005154ca     SCASB.RE   ES:EDI=>s_                                       = ""
//         005154cc     NOT        this
//         005154ce     SUB        EDI,this
//                              tplayer.cpp:2190 (74)
//         005154d0     MOV        EBP,dword ptr [ESP + 0x41c]
//         005154d7     MOV        EAX,this
//         005154d9     MOV        ESI,EDI
//         005154db     MOV        EDI,EDX
//         005154dd     LEA        EDX,[ESP + 0x118]
//         005154e4     SHR        this,0x2
//         005154e7     MOVSD.REP  ES:EDI,ESI
//         005154e9     MOV        this,EAX
//         005154eb     XOR        EAX,EAX
//         005154ed     AND        this,0x3
//         005154f0     MOVSB.REP  ES:EDI,ESI
//         005154f2     MOV        EDI,s_                                           = ""
//         005154f7     OR         this,0xffffffff
//         005154fa     SCASB.RE   ES:EDI=>s_                                       = ""
//         005154fc     NOT        this
//         005154fe     SUB        EDI,this
//         00515500     MOV        EAX,this
//         00515502     MOV        ESI,EDI
//         00515504     MOV        EDI,EDX
//         00515506     SHR        this,0x2
//         00515509     MOVSD.REP  ES:EDI,ESI
//         0051550b     MOV        this,EAX
//         0051550d     AND        this,0x3
//         00515510     TEST       EBP,EBP
//         00515512     MOVSB.REP  ES:EDI,ESI
//         00515514     JZ         LAB_005155f7
//                              tplayer.cpp:2191 (58)
//         0051551a     LEA        EDI,[ESP + 0x218]
//         00515521     MOV        ESI,EBP
//                               LAB_00515523                                                 XREF[1]:     00515545(j)
//         00515523     MOV        this,byte ptr [ESI]
//         00515525     MOV        DL,byte ptr [EDI]
//         00515527     MOV        AL,this
//         00515529     CMP        this,DL
//         0051552b     JNZ        LAB_0051554b
//         0051552d     TEST       AL,AL
//         0051552f     JZ         LAB_00515547
//         00515531     MOV        DL,byte ptr [ESI + 0x1]
//         00515534     MOV        this,byte ptr [EDI + 0x1]
//         00515537     MOV        AL,DL
//         00515539     CMP        DL,this
//         0051553b     JNZ        LAB_0051554b
//         0051553d     ADD        ESI,0x2
//         00515540     ADD        EDI,0x2
//         00515543     TEST       AL,AL
//         00515545     JNZ        LAB_00515523
//                               LAB_00515547                                                 XREF[1]:     0051552f(j)
//         00515547     XOR        EAX,EAX
//         00515549     JMP        LAB_00515550
//                               LAB_0051554b                                                 XREF[2]:     0051552b(j), 0051553b(j)
//         0051554b     SBB        EAX,EAX
//         0051554d     SBB        EAX,-0x1
//                               LAB_00515550                                                 XREF[1]:     00515549(j)
//         00515550     TEST       EAX,EAX
//         00515552     JNZ        LAB_005155c9
//                               LAB_00515554                                                 XREF[1]:     005155c2(j)
//                              tplayer.cpp:2196 (56)
//         00515554     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051555a     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         0051555f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515565     PUSH       EAX
//         00515566     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0051556b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515571     PUSH       EAX=>DAT_fffffff8
//         00515572     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         00515577     PUSH       EAX=>DAT_fffffff4
//         00515578     LEA        EAX,[ESP + 0x124]
//         0051557f     LEA        this,[ESP + 0x24]
//         00515583     PUSH       EAX=>DAT_fffffff0
//         00515584     PUSH       this
//         00515585     MOV        this,EBX
//         00515587     CALL       TRIBE_Player::intelligentBuildListAndRulesSele   void intelligentBuildListAndRulesSelection(TR
//                              tplayer.cpp:2197 (22)
//         0051558c     MOV        EAX,dword ptr [EBX + 0x238]
//         00515592     LEA        EDX,[ESP + 0x18]
//         00515596     PUSH       EDX
//         00515597     PUSH       s_Loading_random_game_selected_bui               = "Loading random game selected build list=%s."
//         0051559c     PUSH       EAX=>DAT_fffffff4
//         0051559d     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2198 (34)
//         005155a2     MOV        EAX,dword ptr [EBX + 0x238]
//         005155a8     ADD        ESP,0xc
//         005155ab     MOV        EDX,dword ptr [EAX + 0x104]
//         005155b1     LEA        this,[EAX + 0x104]
//         005155b7     LEA        EAX,[ESP + 0x18]
//         005155bb     PUSH       EBX
//         005155bc     PUSH       EAX=>DAT_fffffff8
//         005155bd     CALL       dword ptr [EDX + 0x44]
//         005155c0     TEST       EAX,EAX
//         005155c2     JZ         LAB_00515554
//                              tplayer.cpp:2200 (5)
//         005155c4     JMP        LAB_00515667
//                               LAB_005155c9                                                 XREF[1]:     00515552(j)
//                              tplayer.cpp:2201 (18)
//         005155c9     MOV        this,dword ptr [EBX + 0x238]
//         005155cf     PUSH       EBP
//         005155d0     PUSH       s_Loading_build_list=%s.                         = "Loading build list=%s."
//         005155d5     PUSH       this=>DAT_fffffff4
//         005155d6     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2202 (26)
//         005155db     MOV        EAX,dword ptr [EBX + 0x238]
//         005155e1     ADD        ESP,0xc
//         005155e4     MOV        EDX,dword ptr [EAX + 0x104]
//         005155ea     LEA        this,[EAX + 0x104]
//         005155f0     PUSH       EBX
//         005155f1     PUSH       EBP=>DAT_fffffff8
//         005155f2     CALL       dword ptr [EDX + 0x44]
//                              tplayer.cpp:2205 (2)
//         005155f5     JMP        LAB_00515667
//                               LAB_005155f7                                                 XREF[2]:     00515514(j), 00515665(j)
//                              tplayer.cpp:2210 (56)
//         005155f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005155fd     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         00515602     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515608     PUSH       EAX
//         00515609     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0051560e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515614     PUSH       EAX=>DAT_fffffff8
//         00515615     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         0051561a     PUSH       EAX=>DAT_fffffff4
//         0051561b     LEA        EAX,[ESP + 0x124]
//         00515622     LEA        this,[ESP + 0x24]
//         00515626     PUSH       EAX=>DAT_fffffff0
//         00515627     PUSH       this
//         00515628     MOV        this,EBX
//         0051562a     CALL       TRIBE_Player::intelligentBuildListAndRulesSele   void intelligentBuildListAndRulesSelection(TR
//                              tplayer.cpp:2211 (22)
//         0051562f     MOV        EAX,dword ptr [EBX + 0x238]
//         00515635     LEA        EDX,[ESP + 0x18]
//         00515639     PUSH       EDX
//         0051563a     PUSH       s_Loading_default_build_list=%s.                 = "Loading default build list=%s."
//         0051563f     PUSH       EAX=>DAT_fffffff4
//         00515640     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2212 (34)
//         00515645     MOV        EAX,dword ptr [EBX + 0x238]
//         0051564b     ADD        ESP,0xc
//         0051564e     MOV        EDX,dword ptr [EAX + 0x104]
//         00515654     LEA        this,[EAX + 0x104]
//         0051565a     LEA        EAX,[ESP + 0x18]
//         0051565e     PUSH       EBX
//         0051565f     PUSH       EAX=>DAT_fffffff8
//         00515660     CALL       dword ptr [EDX + 0x44]
//         00515663     TEST       EAX,EAX
//         00515665     JZ         LAB_005155f7
//                               LAB_00515667                                                 XREF[2]:     005155c4(j), 005155f5(j)
//                              tplayer.cpp:2216 (15)
//         00515667     MOV        EBP,dword ptr [ESP + 0x420]
//         0051566e     TEST       EBP,EBP
//         00515670     JZ         LAB_005156f8
//                              tplayer.cpp:2217 (58)
//         00515676     LEA        EDI,[ESP + 0x218]
//         0051567d     MOV        ESI,EBP
//                               LAB_0051567f                                                 XREF[1]:     005156a1(j)
//         0051567f     MOV        this,byte ptr [ESI]
//         00515681     MOV        DL,byte ptr [EDI]
//         00515683     MOV        AL,this
//         00515685     CMP        this,DL
//         00515687     JNZ        LAB_005156a7
//         00515689     TEST       AL,AL
//         0051568b     JZ         LAB_005156a3
//         0051568d     MOV        DL,byte ptr [ESI + 0x1]
//         00515690     MOV        this,byte ptr [EDI + 0x1]
//         00515693     MOV        AL,DL
//         00515695     CMP        DL,this
//         00515697     JNZ        LAB_005156a7
//         00515699     ADD        ESI,0x2
//         0051569c     ADD        EDI,0x2
//         0051569f     TEST       AL,AL
//         005156a1     JNZ        LAB_0051567f
//                               LAB_005156a3                                                 XREF[1]:     0051568b(j)
//         005156a3     XOR        EAX,EAX
//         005156a5     JMP        LAB_005156ac
//                               LAB_005156a7                                                 XREF[2]:     00515687(j), 00515697(j)
//         005156a7     SBB        EAX,EAX
//         005156a9     SBB        EAX,-0x1
//                               LAB_005156ac                                                 XREF[1]:     005156a5(j)
//         005156ac     TEST       EAX,EAX
//         005156ae     JNZ        LAB_005156be
//                              tplayer.cpp:2218 (12)
//         005156b0     MOV        EAX,dword ptr [EBX + 0x238]
//         005156b6     PUSH       s_Loading_no_city_plan_(influence_               = "Loading no city plan (influence placement
//         005156bb     PUSH       EAX=>DAT_fffffff8
//                              tplayer.cpp:2223 (2)
//         005156bc     JMP        LAB_00515704
//                               LAB_005156be                                                 XREF[1]:     005156ae(j)
//                              tplayer.cpp:2224 (18)
//         005156be     MOV        this,dword ptr [EBX + 0x238]
//         005156c4     PUSH       EBP
//         005156c5     PUSH       s_Loading_city_plan=%s.                          = "Loading city plan=%s."
//         005156ca     PUSH       this=>DAT_fffffff4
//         005156cb     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2227 (38)
//         005156d0     MOV        EAX,dword ptr [EBX + 0x238]
//         005156d6     MOV        EDX,dword ptr [EBX + 0x3c]
//         005156d9     ADD        ESP,0xc
//         005156dc     LEA        this,[EAX + 0x6c4]
//         005156e2     MOV        EAX,dword ptr [EDX + 0x28]
//         005156e5     PUSH       0x0
//         005156e7     PUSH       0x0=>DAT_fffffff8
//         005156e9     MOV        ESI,dword ptr [EAX + 0xc]
//         005156ec     MOV        EAX,dword ptr [EAX + 0x8]
//         005156ef     MOV        EDX,dword ptr [this->_padding_]
//         005156f1     PUSH       0x0=>DAT_fffffff4
//         005156f3     PUSH       ESI=>DAT_fffffff0
//         005156f4     PUSH       EAX
//         005156f5     PUSH       EBP
//                              tplayer.cpp:2230 (2)
//         005156f6     JMP        LAB_00515733
//                               LAB_005156f8                                                 XREF[1]:     00515670(j)
//                              tplayer.cpp:2231 (17)
//         005156f8     MOV        this,dword ptr [EBX + 0x238]
//         005156fe     PUSH       s_Loading_no_city_plan_(influence_               = "Loading no city plan (influence placement
//         00515703     PUSH       this=>DAT_fffffff8
//                               LAB_00515704                                                 XREF[1]:     005156bc(j)
//         00515704     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2234 (45)
//         00515709     MOV        EAX,dword ptr [EBX + 0x238]
//         0051570f     MOV        EDX,dword ptr [EBX + 0x3c]
//         00515712     ADD        ESP,0x8
//         00515715     LEA        this,[EAX + 0x6c4]
//         0051571b     MOV        EAX,dword ptr [EDX + 0x28]
//         0051571e     PUSH       0x0
//         00515720     PUSH       0x0=>DAT_fffffff8
//         00515722     MOV        ESI,dword ptr [EAX + 0xc]
//         00515725     MOV        EAX,dword ptr [EAX + 0x8]
//         00515728     MOV        EDX,dword ptr [this->_padding_]
//         0051572a     PUSH       0x0=>DAT_fffffff4
//         0051572c     PUSH       ESI=>DAT_fffffff0
//         0051572d     PUSH       EAX
//         0051572e     PUSH       s_NONE                                           = 4Eh
//                               LAB_00515733                                                 XREF[1]:     005156f6(j)
//         00515733     CALL       dword ptr [EDX + 0x40]
//                              tplayer.cpp:2238 (69)
//         00515736     MOV        EBP,dword ptr [ESP + 0x424]
//         0051573d     TEST       EBP,EBP
//         0051573f     JZ         LAB_00515793
//         00515741     LEA        EDI,[ESP + 0x218]
//         00515748     MOV        ESI,EBP
//                               LAB_0051574a                                                 XREF[1]:     0051576c(j)
//         0051574a     MOV        this,byte ptr [ESI]
//         0051574c     MOV        DL,byte ptr [EDI]
//         0051574e     MOV        AL,this
//         00515750     CMP        this,DL
//         00515752     JNZ        LAB_00515772
//         00515754     TEST       AL,AL
//         00515756     JZ         LAB_0051576e
//         00515758     MOV        DL,byte ptr [ESI + 0x1]
//         0051575b     MOV        this,byte ptr [EDI + 0x1]
//         0051575e     MOV        AL,DL
//         00515760     CMP        DL,this
//         00515762     JNZ        LAB_00515772
//         00515764     ADD        ESI,0x2
//         00515767     ADD        EDI,0x2
//         0051576a     TEST       AL,AL
//         0051576c     JNZ        LAB_0051574a
//                               LAB_0051576e                                                 XREF[1]:     00515756(j)
//         0051576e     XOR        EAX,EAX
//         00515770     JMP        LAB_00515777
//                               LAB_00515772                                                 XREF[2]:     00515752(j), 00515762(j)
//         00515772     SBB        EAX,EAX
//         00515774     SBB        EAX,-0x1
//                               LAB_00515777                                                 XREF[1]:     00515770(j)
//         00515777     TEST       EAX,EAX
//         00515779     JZ         LAB_00515793
//                              tplayer.cpp:2239 (21)
//         0051577b     MOV        EAX,dword ptr [EBX + 0x238]
//         00515781     PUSH       EBP
//         00515782     PUSH       s_Loading_rule_set=%s.                           = "Loading rule set=%s."
//         00515787     PUSH       EAX=>DAT_fffffff4
//         00515788     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         0051578d     ADD        ESP,0xc
//                              tplayer.cpp:2240 (1)
//         00515790     PUSH       EBP
//                              tplayer.cpp:2242 (63)
//         00515791     JMP        LAB_005157f4
//                               LAB_00515793                                                 XREF[2]:     0051573f(j), 00515779(j)
//         00515793     MOV        EDI,s_RandomGameSpecialized                      = 52h
//         00515798     LEA        ESI,[ESP + 0x118]
//                               LAB_0051579f                                                 XREF[1]:     005157c1(j)
//         0051579f     MOV        this,byte ptr [ESI]
//         005157a1     MOV        DL,byte ptr [EDI]=>s_RandomGameSpecialized       = 52h
//                                                                                  = 6Eh
//         005157a3     MOV        AL,this
//         005157a5     CMP        this,DL
//         005157a7     JNZ        LAB_005157c7
//         005157a9     TEST       AL,AL
//         005157ab     JZ         LAB_005157c3
//         005157ad     MOV        DL,byte ptr [ESI + 0x1]
//         005157b0     MOV        this,byte ptr [EDI + 0x1]=>DAT_0058af79          = 61h
//                                                                                  = "domGameSpecialized"
//         005157b3     MOV        AL,DL
//         005157b5     CMP        DL,this
//         005157b7     JNZ        LAB_005157c7
//         005157b9     ADD        ESI,0x2
//         005157bc     ADD        EDI,0x2
//         005157bf     TEST       AL,AL
//         005157c1     JNZ        LAB_0051579f
//                               LAB_005157c3                                                 XREF[1]:     005157ab(j)
//         005157c3     XOR        EAX,EAX
//         005157c5     JMP        LAB_005157cc
//                               LAB_005157c7                                                 XREF[2]:     005157a7(j), 005157b7(j)
//         005157c7     SBB        EAX,EAX
//         005157c9     SBB        EAX,-0x1
//                               LAB_005157cc                                                 XREF[1]:     005157c5(j)
//         005157cc     TEST       EAX,EAX
//         005157ce     JZ         LAB_00515807
//                              tplayer.cpp:2243 (28)
//         005157d0     MOV        this,dword ptr [EBX + 0x238]
//         005157d6     LEA        EAX,[ESP + 0x118]
//         005157dd     PUSH       EAX
//         005157de     PUSH       s_Loading_random_game_selected_rul               = "Loading random game selected rule set=%s."
//         005157e3     PUSH       this=>DAT_fffffff4
//         005157e4     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         005157e9     ADD        ESP,0xc
//                              tplayer.cpp:2244 (25)
//         005157ec     LEA        EDX,[ESP + 0x118]
//         005157f3     PUSH       EDX
//                               LAB_005157f4                                                 XREF[1]:     00515791(j)
//         005157f4     MOV        this,dword ptr [EBX + 0x238]
//         005157fa     ADD        this,0x10e74
//         00515800     CALL       TribeStrategyAIModule::loadRules                 int loadRules(TribeStrategyAIModule * this, c
//                              tplayer.cpp:2246 (2)
//         00515805     JMP        LAB_0051581b
//                               LAB_00515807                                                 XREF[1]:     005157ce(j)
//                              tplayer.cpp:2247 (20)
//         00515807     MOV        EAX,dword ptr [EBX + 0x238]
//         0051580d     PUSH       s_Rule_set_has_been_initialized_wi               = "Rule set has been initialized with code-co
//         00515812     PUSH       EAX=>DAT_fffffff8
//         00515813     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         00515818     ADD        ESP,0x8
//                               LAB_0051581b                                                 XREF[1]:     00515805(j)
//                              tplayer.cpp:2250 (11)
//         0051581b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515821     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//                              tplayer.cpp:2251 (20)
//         00515826     MOV        this,dword ptr [EBX + 0x238]
//         0051582c     MOV        ESI,EAX
//         0051582e     PUSH       ESI
//         0051582f     PUSH       s_Setting_difficulty_level_to_%d.                = "Setting difficulty level to %d."
//         00515834     PUSH       this=>DAT_fffffff4
//         00515835     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:2252 (21)
//         0051583a     MOV        this,dword ptr [EBX + 0x238]
//         00515840     ADD        ESP,0xc
//         00515843     ADD        this,0x10e74
//         00515849     PUSH       ESI
//         0051584a     CALL       TribeStrategyAIModule::setDifficultyLevel        void setDifficultyLevel(TribeStrategyAIModule
//                              tplayer.cpp:2255 (11)
//         0051584f     MOV        this,dword ptr [EBX + 0x238]
//         00515855     CALL       TribeMainDecisionAIModule::updateBuildAIWithOb   void updateBuildAIWithObjects(TribeMainDecisi
//                              tplayer.cpp:2258 (18)
//         0051585a     MOV        EDX,dword ptr [EBX + 0x3c]
//         0051585d     MOV        ESI,0x1
//         00515862     CMP        word ptr [EDX + 0x3c],SI
//         00515866     JLE        LAB_005158fa
//                               LAB_0051586c                                                 XREF[1]:     005158f4(j)
//                              tplayer.cpp:2259 (8)
//         0051586c     MOVSX      EAX,word ptr [EBX + 0x4a]
//         00515870     CMP        ESI,EAX
//         00515872     JNZ        LAB_0051588e
//                              tplayer.cpp:2261 (22)
//         00515874     MOV        this,dword ptr [EBX + 0x238]
//         0051587a     PUSH       0x0
//         0051587c     PUSH       0x0=>DAT_fffffff8
//         0051587e     PUSH       ESI=>DAT_fffffff4
//         0051587f     ADD        this,0x9dc
//         00515885     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int
//                              tplayer.cpp:2263 (2)
//         0051588a     PUSH       0x64
//                              tplayer.cpp:2265 (14)
//         0051588c     JMP        LAB_005158d6
//                               LAB_0051588e                                                 XREF[1]:     00515872(j)
//         0051588e     MOV        EDI,dword ptr [EBX]
//         00515890     PUSH       ESI
//         00515891     MOV        this,EBX
//         00515893     CALL       dword ptr [EDI + 0x18]
//         00515896     TEST       EAX,EAX
//         00515898     JZ         LAB_005158b4
//                              tplayer.cpp:2267 (22)
//         0051589a     MOV        this,dword ptr [EBX + 0x238]
//         005158a0     PUSH       0x4a
//         005158a2     PUSH       0x0=>DAT_fffffff8
//         005158a4     PUSH       ESI=>DAT_fffffff4
//         005158a5     ADD        this,0x9dc
//         005158ab     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int
//                              tplayer.cpp:2269 (2)
//         005158b0     PUSH       0x18
//                              tplayer.cpp:2271 (12)
//         005158b2     JMP        LAB_005158d6
//                               LAB_005158b4                                                 XREF[1]:     00515898(j)
//         005158b4     PUSH       ESI
//         005158b5     MOV        this,EBX
//         005158b7     CALL       dword ptr [EDI + 0x1c]
//         005158ba     TEST       EAX,EAX
//         005158bc     JZ         LAB_005158ea
//                              tplayer.cpp:2273 (22)
//         005158be     MOV        this,dword ptr [EBX + 0x238]
//         005158c4     PUSH       0x18
//         005158c6     PUSH       0x0=>DAT_fffffff8
//         005158c8     PUSH       ESI=>DAT_fffffff4
//         005158c9     ADD        this,0x9dc
//         005158cf     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int
//                              tplayer.cpp:2275 (38)
//         005158d4     PUSH       0x4a
//                               LAB_005158d6                                                 XREF[2]:     0051588c(j), 005158b2(j)
//         005158d6     MOV        this,dword ptr [EBX + 0x238]
//         005158dc     PUSH       offset DAT_fffffff8
//         005158de     PUSH       ESI=>DAT_fffffff4
//         005158df     ADD        this,0x9dc
//         005158e5     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int
//                               LAB_005158ea                                                 XREF[1]:     005158bc(j)
//         005158ea     MOV        this,dword ptr [EBX + 0x3c]
//         005158ed     INC        ESI
//         005158ee     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         005158f2     CMP        ESI,EDX
//         005158f4     JL         LAB_0051586c
//                               LAB_005158fa                                                 XREF[1]:     00515866(j)
//                              tplayer.cpp:2279 (14)
//         005158fa     MOV        EAX,dword ptr [EBX + 0x3c]
//         005158fd     MOV        ESI,0x1
//         00515902     CMP        word ptr [EAX + 0x3c],SI
//         00515906     JLE        LAB_00515944
//                              tplayer.cpp:2280 (24)
//         00515908     MOV        EDI,dword ptr [EBX]
//         0051590a     MOV        EBP,dword ptr [EDI + 0x18]
//                               LAB_0051590d                                                 XREF[1]:     00515942(j)
//         0051590d     PUSH       ESI
//         0051590e     MOV        this,EBX
//         00515910     CALL       EBP
//         00515912     TEST       EAX,EAX
//         00515914     JNZ        LAB_00515924
//         00515916     PUSH       ESI
//         00515917     MOV        this,EBX
//         00515919     CALL       dword ptr [EDI + 0x1c]
//         0051591c     TEST       EAX,EAX
//         0051591e     JNZ        LAB_00515924
//                              tplayer.cpp:2283 (4)
//         00515920     PUSH       0x1
//         00515922     JMP        LAB_00515926
//                               LAB_00515924                                                 XREF[2]:     00515914(j), 0051591e(j)
//                              tplayer.cpp:2281 (32)
//         00515924     PUSH       0x0
//                               LAB_00515926                                                 XREF[1]:     00515922(j)
//         00515926     MOV        this,dword ptr [EBX + 0x238]
//         0051592c     PUSH       ESI=>DAT_fffffff8
//         0051592d     ADD        this,0x9dc
//         00515933     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this,
//         00515938     MOV        this,dword ptr [EBX + 0x3c]
//         0051593b     INC        ESI
//         0051593c     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         00515940     CMP        ESI,EDX
//         00515942     JL         LAB_0051590d
//                               LAB_00515944                                                 XREF[1]:     00515906(j)
//                              tplayer.cpp:2287 (25)
//         00515944     MOV        EAX,dword ptr [ESP + 0x428]
//         0051594b     MOV        this,dword ptr [EBX + 0x238]
//         00515951     PUSH       EAX
//         00515952     ADD        this,0xb2c
//         00515958     CALL       EmotionalAIModule::setOverallState               void setOverallState(EmotionalAIModule * this
//                              tplayer.cpp:2291 (30)
//         0051595d     MOV        this,dword ptr [EBX + 0x3c]
//         00515960     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00515963     MOV        EDX,dword ptr [EDX + 0x1010]
//         00515969     TEST       EDX,EDX
//         0051596b     JZ         LAB_0051598d
//         0051596d     MOV        EDI,EDX
//         0051596f     OR         this,0xffffffff
//         00515972     XOR        EAX,EAX
//         00515974     SCASB.RE   ES:EDI
//         00515976     NOT        this
//         00515978     DEC        this
//         00515979     JZ         LAB_0051598d
//                              tplayer.cpp:2292 (18)
//         0051597b     MOV        this,dword ptr [EBX + 0x238]
//         00515981     PUSH       EDX
//         00515982     ADD        this,0xcec
//         00515988     CALL       TribeInformationAIModule::loadLearnInfo          void loadLearnInfo(TribeInformationAIModule *
//                               LAB_0051598d                                                 XREF[3]:     00515412(j), 0051596b(j),
//                                                                                                         00515979(j)
//                              tplayer.cpp:2301 (32)
//         0051598d     MOV        this,dword ptr [ESP + buildListName[0]]
//         00515991     MOV        EAX,dword ptr [ESP + saveRand]
//         00515995     PUSH       this
//                              language.dll match for 0x8fd: "You traitorous wretch! Vengean
//         00515996     PUSH       offset DAT_fffffff8
//         0051599b     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005159a0     MOV        [debug_random_on],EAX
//         005159a5     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
//         005159aa     ADD        ESP,0xc
//                              tplayer.cpp:2302 (35)
//         005159ad     POP        EDI
//         005159ae     POP        ESI
//         005159af     POP        EBP
//         005159b0     POP        EBX
//         005159b1     ADD        ESP,0x408
//         005159b7     RET        0x14
    return;
}

void TRIBE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notify(TRIBE_Player * this, int param_1, int param_2
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005159d1(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     00515a06(R), 00515abb(R)
//              long              Stack[0x14]:4  param_5
//              long              Stack[0x18]:4  param_6
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00515a1f(W), 00515a7f(R)
//              RGE_Static_Obj    Stack[-0x8]:4  attackingObject
//                               ?notify@TRIBE_Player@@UAEXHHHJJJ@Z                           XREF[2]:     00576958(*), 00576a88(*)
//                               TRIBE_Player::notify
//                              tplayer.cpp:2308 (1)
//         005159d0     PUSH       this
//                              tplayer.cpp:2320 (39)
//         005159d1     MOV        EAX,dword ptr [ESP + param_3]
//         005159d5     PUSH       EBX
//         005159d6     ADD        EAX,0xfffffdff
//         005159db     PUSH       EBP
//         005159dc     PUSH       ESI
//         005159dd     CMP        EAX,0xb
//         005159e0     PUSH       EDI
//         005159e1     MOV        ESI,this
//         005159e3     JA         switchD_005159f1::caseD_202
//         005159e9     XOR        this,this
//         005159eb     MOV        this,byte ptr [EAX + switchD_005159f1::switchd
//                               switchD_005159f1::switchD
//         005159f1     JMP        dword ptr [this->_padding_*0x4 + switchD_00515   = 005159f8
//                               switchD_005159f1::caseD_201                                  XREF[2]:     005159f1(j), 00515b88(*)
//                              tplayer.cpp:2323 (14)
//         005159f8     MOV        EAX,dword ptr [ESI + 0x228]
//         005159fe     TEST       EAX,EAX
//         00515a00     JNZ        switchD_005159f1::caseD_202
//                              tplayer.cpp:2327 (23)
//         00515a06     MOV        EDX,dword ptr [ESP + param_4]
//         00515a0a     MOV        this,dword ptr [ESI + 0x3c]
//         00515a0d     PUSH       EDX
//         00515a0e     MOV        dword ptr [ESI + 0x228],0x14
//         00515a18     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              tplayer.cpp:2333 (12)
//         00515a1d     TEST       EAX,EAX
//         00515a1f     MOV        dword ptr [ESP + local_4],EAX
//         00515a23     JZ         switchD_005159f1::caseD_202
//                              tplayer.cpp:2336 (15)
//         00515a29     PUSH       0x920
//         00515a2e     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00515a33     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//                              tplayer.cpp:2338 (6)
//         00515a38     MOV        EBX,dword ptr [debug_random_on]
//                              tplayer.cpp:2340 (16)
//         00515a3e     MOV        dword ptr [debug_random_on],0x0
//         00515a48     MOV        dword ptr [global_save_debug_random_on3],EBX
//                              tplayer.cpp:2342 (18)
//         00515a4e     MOV        EDI,dword ptr [ESI + 0x3c]
//         00515a51     MOV        EBP,EAX
//         00515a53     ADD        ESP,0x8
//         00515a56     MOV        AX,word ptr [EDI + 0x7c]
//         00515a5a     CMP        AX,word ptr [ESI + 0x4a]
//         00515a5e     JNZ        LAB_00515aa0
//                              tplayer.cpp:2344 (24)
//         00515a60     MOV        this,dword ptr [ESI + 0x50]
//         00515a63     FLD        float ptr [ECX + this->_padding_]
//         00515a66     CALL       __ftol                                           undefined __ftol()
//         00515a6b     MOVSX      EDX,AX
//         00515a6e     MOV        EAX,dword ptr [EDI + 0x30]
//         00515a71     MOV        this,dword ptr [EAX + EDX*0x4]
//         00515a74     TEST       this,this
//         00515a76     JZ         LAB_00515a7f
//                              tplayer.cpp:2345 (7)
//         00515a78     PUSH       0x1
//         00515a7a     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_00515a7f                                                 XREF[1]:     00515a76(j)
//                              tplayer.cpp:2346 (33)
//         00515a7f     MOV        EDI,dword ptr [ESP + local_4]
//         00515a83     FLD        float ptr [EDI + 0x3c]
//         00515a86     CALL       __ftol                                           undefined __ftol()
//         00515a8b     FLD        float ptr [EDI + 0x38]
//         00515a8e     PUSH       EAX
//         00515a8f     CALL       __ftol                                           undefined __ftol()
//         00515a94     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515a9a     PUSH       EAX
//         00515a9b     CALL       TRIBE_Game::add_notification_loc                 void add_notification_loc(TRIBE_Game * this,
//                               LAB_00515aa0                                                 XREF[1]:     00515a5e(j)
//                              tplayer.cpp:2353 (25)
//         00515aa0     PUSH       EBP
//         00515aa1     PUSH       0x931
//         00515aa6     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00515aab     MOV        dword ptr [debug_random_on],EBX
//         00515ab1     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
//         00515ab6     ADD        ESP,0xc
//                              tplayer.cpp:2355 (2)
//         00515ab9     JMP        switchD_005159f1::caseD_202
//                               switchD_005159f1::caseD_20c                                  XREF[2]:     005159f1(j), 00515b94(*)
//                              tplayer.cpp:2361 (10)
//         00515abb     CMP        dword ptr [ESP + param_4],0x267
//         00515ac3     JNZ        switchD_005159f1::caseD_202
//                              tplayer.cpp:2362 (21)
//         00515ac5     MOVSX      EAX,word ptr [ESI + 0x4a]
//         00515ac9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515acf     PUSH       0x0
//         00515ad1     PUSH       0x0
//         00515ad3     PUSH       0x0
//         00515ad5     MOV        EDX,dword ptr [this->_padding_]
//         00515ad7     PUSH       EAX
//         00515ad8     PUSH       0x3
//                              tplayer.cpp:2363 (2)
//         00515ada     JMP        LAB_00515b08
//                               switchD_005159f1::caseD_207                                  XREF[2]:     005159f1(j), 00515b90(*)
//                              tplayer.cpp:2367 (21)
//         00515adc     MOVSX      EAX,word ptr [ESI + 0x4a]
//         00515ae0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515ae6     PUSH       0x0
//         00515ae8     PUSH       0x0
//         00515aea     PUSH       0x0
//         00515aec     MOV        EDX,dword ptr [this->_padding_]
//         00515aee     PUSH       EAX
//         00515aef     PUSH       0x1
//                              tplayer.cpp:2368 (2)
//         00515af1     JMP        LAB_00515b08
//                               switchD_005159f1::caseD_206                                  XREF[2]:     005159f1(j), 00515b8c(*)
//                              tplayer.cpp:2372 (24)
//         00515af3     MOVSX      EAX,word ptr [ESI + 0x4a]
//         00515af7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515afd     PUSH       0x0
//         00515aff     PUSH       0x0
//         00515b01     PUSH       0x0
//         00515b03     MOV        EDX,dword ptr [this->_padding_]
//         00515b05     PUSH       EAX
//         00515b06     PUSH       0x2
//                               LAB_00515b08                                                 XREF[2]:     00515ada(j), 00515af1(j)
//         00515b08     CALL       dword ptr [EDX + 0x40]
//                               switchD_005159f1::caseD_203                                  XREF[7]:     005159e3(j), 005159f1(j),
//                               switchD_005159f1::caseD_204                                               00515a00(j), 00515a23(j),
//                               switchD_005159f1::caseD_205                                               00515ab9(j), 00515ac3(j),
//                               switchD_005159f1::caseD_208                                               00515b98(*)
//                               switchD_005159f1::caseD_209
//                               switchD_005159f1::caseD_20a
//                               switchD_005159f1::caseD_20b
//                               switchD_005159f1::caseD_202
//                              tplayer.cpp:2377 (15)
//         00515b0b     PUSH       0x949
//         00515b10     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00515b15     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//                              tplayer.cpp:2379 (8)
//         00515b1a     MOV        EDI,dword ptr [debug_random_on]
//         00515b20     MOV        EBX,EAX
//                              tplayer.cpp:2380 (6)
//         00515b22     MOV        dword ptr [global_save_debug_random_on4],EDI
//                              tplayer.cpp:2381 (10)
//         00515b28     MOV        dword ptr [debug_random_on],0x0
//                              tplayer.cpp:2383 (13)
//         00515b32     MOV        EAX,dword ptr [ESI + 0x238]
//         00515b38     ADD        ESP,0x8
//         00515b3b     TEST       EAX,EAX
//         00515b3d     JZ         LAB_00515b67
//                              tplayer.cpp:2384 (40)
//         00515b3f     MOV        EAX,dword ptr [ESP + 0x2c]
//         00515b43     MOV        this,dword ptr [ESP + 0x28]
//         00515b47     MOV        EDX,dword ptr [ESI]
//         00515b49     PUSH       EAX
//         00515b4a     MOV        EAX,dword ptr [ESP + 0x28]
//         00515b4e     PUSH       this
//         00515b4f     MOV        this,dword ptr [ESP + 0x28]
//         00515b53     PUSH       EAX
//         00515b54     MOV        EAX,dword ptr [ESP + 0x28]
//         00515b58     PUSH       this
//         00515b59     MOV        this,dword ptr [ESP + 0x28]
//         00515b5d     PUSH       EAX
//         00515b5e     PUSH       this
//         00515b5f     MOV        this,ESI
//         00515b61     CALL       dword ptr [EDX + 0x128]
//                               LAB_00515b67                                                 XREF[1]:     00515b3d(j)
//                              tplayer.cpp:2390 (25)
//         00515b67     PUSH       EBX
//         00515b68     PUSH       0x956
//         00515b6d     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00515b72     MOV        dword ptr [debug_random_on],EDI
//         00515b78     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
//         00515b7d     ADD        ESP,0xc
//                              tplayer.cpp:2395 (40)
//         00515b80     POP        EDI
//         00515b81     POP        ESI
//         00515b82     POP        EBP
//         00515b83     POP        EBX
//         00515b84     POP        this
//         00515b85     RET        0x18
//                              Symbol Ref: No symbol: NONAME
//                               switchD_005159f1::switchdataD_00515b88                       XREF[1]:     notify:005159f1(*)
//         00515b88     addr       switchD_005159f1::caseD_201
//         00515b8c     addr       switchD_005159f1::caseD_206
//         00515b90     addr       switchD_005159f1::caseD_207
//         00515b94     addr       switchD_005159f1::caseD_20c
//         00515b98     addr       switchD_005159f1::caseD_202
//                              Symbol Ref: No symbol: NONAME
//                               switchD_005159f1::switchdataD_00515b9c                       XREF[1]:     notify:005159eb(*)
//         00515b9c     db         0h
//         00515b9d     db         4h
//         00515b9e     db         4h
//         00515b9f     db         4h
//         00515ba0     db         4h
//         00515ba1     db         1h
//         00515ba2     db         2h
//         00515ba3     db         4h
//         00515ba4     db         4h
//         00515ba5     db         4h
//         00515ba6     db         4h
//         00515ba7     db         3h
//         00515ba8     ??         90h
//         00515ba9     ??         90h
//         00515baa     ??         90h
//         00515bab     ??         90h
//         00515bac     ??         90h
//         00515bad     ??         90h
//         00515bae     ??         90h
//         00515baf     ??         90h
    return;
}

void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notifyAI(TRIBE_Player * this, int param_1, int param
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00515bb1(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00515d95(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515bc3(R)
//              long              Stack[0x10]:4  param_4                   XREF[8]:     00515c17(R), 00515c8f(R), 00515cbc(*), 00515ce2(R),
//                                                                                     00515d1e(R), 00515d5b(R), 00515d8a(R), 00515da6(R)
//              long              Stack[0x14]:4  param_5                   XREF[4]:     00515cc0(*), 00515ce6(R), 00515d57(R), 00515d7f(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00515d74(R)
//                               ?notifyAI@TRIBE_Player@@UAEXHHHJJJ@Z                         XREF[2]:     00576998(*), 00576ac8(*)
//                               TRIBE_Player::notifyAI
//                              tplayer.cpp:2401 (1)
//         00515bb0     PUSH       EBX
//                              tplayer.cpp:2410 (18)
//         00515bb1     MOV        EBX,dword ptr [ESP + param_1]
//         00515bb5     PUSH       EBP
//         00515bb6     PUSH       ESI
//         00515bb7     MOV        ESI,this
//         00515bb9     PUSH       EDI
//         00515bba     PUSH       EBX
//         00515bbb     MOV        this,dword ptr [ESI + 0x3c]
//         00515bbe     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              tplayer.cpp:2415 (24)
//         00515bc3     MOV        EDI,dword ptr [ESP + param_3]
//         00515bc7     MOV        EBP,EAX
//         00515bc9     CMP        EDI,0x20a
//         00515bcf     JZ         LAB_00515bf2
//         00515bd1     CMP        EDI,0x72
//         00515bd4     JZ         LAB_00515bf2
//         00515bd6     CMP        EDI,0x74
//         00515bd9     JZ         LAB_00515bf2
//                              tplayer.cpp:2417 (17)
//         00515bdb     TEST       EBP,EBP
//         00515bdd     JZ         switchD_00515c88::caseD_203
//         00515be3     MOV        this,EBP
//         00515be5     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         00515bea     TEST       EAX,EAX
//                              tplayer.cpp:2418 (6)
//         00515bec     JZ         switchD_00515c88::caseD_203
//                               LAB_00515bf2                                                 XREF[3]:     00515bcf(j), 00515bd4(j),
//                                                                                                         00515bd9(j)
//                              tplayer.cpp:2422 (30)
//         00515bf2     CMP        EDI,0x1f9
//         00515bf8     JG         LAB_00515c71
//         00515bfa     JZ         LAB_00515c17
//         00515bfc     MOV        EAX,EDI
//         00515bfe     SUB        EAX,0x72
//         00515c01     JZ         switchD_00515c88::caseD_201
//         00515c07     SUB        EAX,0x2
//         00515c0a     JZ         switchD_00515c88::caseD_201
//                              tplayer.cpp:2534 (7)
//         00515c10     POP        EDI
//         00515c11     POP        ESI
//         00515c12     POP        EBP
//         00515c13     POP        EBX
//         00515c14     RET        0x18
//                               LAB_00515c17                                                 XREF[1]:     00515bfa(j)
//                              tplayer.cpp:2430 (14)
//         00515c17     CMP        dword ptr [ESP + param_4],0x25d
//         00515c1f     JNZ        switchD_00515c88::caseD_203
//                              tplayer.cpp:2431 (20)
//         00515c25     MOV        this,dword ptr [ESI + 0x238]
//         00515c2b     PUSH       EBX
//         00515c2c     ADD        this,0x1146c
//         00515c32     CALL       TribeTacticalAIModule::groupUnitIsIn             TacticalAIGroup * groupUnitIsIn(TribeTactical
//         00515c37     MOV        EDI,EAX
//                              tplayer.cpp:2433 (24)
//         00515c39     TEST       EDI,EDI
//         00515c3b     JZ         switchD_00515c88::caseD_203
//         00515c41     MOV        this,EDI
//         00515c43     CALL       TacticalAIGroup::type                            int type(TacticalAIGroup * this)
//         00515c48     CMP        EAX,0x6b
//         00515c4b     JNZ        switchD_00515c88::caseD_203
//                              tplayer.cpp:2437 (25)
//         00515c51     MOV        this,EDI
//         00515c53     CALL       TacticalAIGroup::id                              int id(TacticalAIGroup * this)
//         00515c58     MOV        this,dword ptr [ESI + 0x238]
//         00515c5e     PUSH       EAX
//         00515c5f     ADD        this,0x1146c
//         00515c65     CALL       TribeTacticalAIModule::removeGroup               int removeGroup(TribeTacticalAIModule * this,
//                              tplayer.cpp:2534 (7)
//         00515c6a     POP        EDI
//         00515c6b     POP        ESI
//         00515c6c     POP        EBP
//         00515c6d     POP        EBX
//         00515c6e     RET        0x18
//                               LAB_00515c71                                                 XREF[1]:     00515bf8(j)
//                              tplayer.cpp:2422 (30)
//         00515c71     LEA        EAX,[EDI + 0xfffffdff]
//         00515c77     CMP        EAX,0xc
//         00515c7a     JA         switchD_00515c88::caseD_203
//         00515c80     XOR        this,this
//         00515c82     MOV        this,byte ptr [EAX + switchD_00515c88::switchd
//                               switchD_00515c88::switchD
//         00515c88     JMP        dword ptr [this->_padding_*0x4 + switchD_00515   = 00515d74
//                               switchD_00515c88::caseD_202                                  XREF[2]:     00515c88(j), 00515dc8(*)
//                              tplayer.cpp:2450 (20)
//         00515c8f     MOV        EAX,dword ptr [ESP + param_4]
//         00515c93     SUB        EAX,0x25d
//         00515c98     JZ         LAB_00515ca3
//         00515c9a     SUB        EAX,0x12
//         00515c9d     JNZ        switchD_00515c88::caseD_203
//                               LAB_00515ca3                                                 XREF[1]:     00515c98(j)
//                              tplayer.cpp:2466 (63)
//         00515ca3     MOV        this,dword ptr [ESI + 0x238]
//         00515ca9     PUSH       EBX
//         00515caa     ADD        this,0xcec
//         00515cb0     CALL       TribeInformationAIModule::fullyExploredZone      int fullyExploredZone(TribeInformationAIModul
//         00515cb5     TEST       EAX,EAX
//         00515cb7     JZ         LAB_00515d05
//         00515cb9     MOV        this,dword ptr [EBP + 0x3c]
//         00515cbc     LEA        EDX=>param_4,[ESP + 0x20]
//         00515cc0     LEA        EAX=>param_5,[ESP + 0x24]
//         00515cc4     PUSH       EDX
//         00515cc5     MOV        EDX,dword ptr [EBP + 0x38]
//         00515cc8     PUSH       EAX
//         00515cc9     PUSH       this
//         00515cca     MOV        this,dword ptr [ESI + 0x238]
//         00515cd0     PUSH       EDX
//         00515cd1     PUSH       EBX
//         00515cd2     ADD        this,0xcec
//         00515cd8     CALL       TribeInformationAIModule::closestUnexploredTile  int closestUnexploredTile(TribeInformationAIM
//         00515cdd     CMP        EAX,0x1
//         00515ce0     JNZ        LAB_00515d05
//                              tplayer.cpp:2470 (28)
//         00515ce2     MOV        EAX,dword ptr [ESP + param_4]
//         00515ce6     MOV        this,dword ptr [ESP + param_5]
//         00515cea     PUSH       EAX
//         00515ceb     PUSH       this
//         00515cec     MOV        this,dword ptr [ESI + 0x238]
//         00515cf2     PUSH       EBX
//         00515cf3     ADD        this,0x1146c
//         00515cf9     CALL       TribeTacticalAIModule::taskExplorer              int taskExplorer(TribeTacticalAIModule * this
//                              tplayer.cpp:2534 (7)
//         00515cfe     POP        EDI
//         00515cff     POP        ESI
//         00515d00     POP        EBP
//         00515d01     POP        EBX
//         00515d02     RET        0x18
//                               LAB_00515d05                                                 XREF[2]:     00515cb7(j), 00515ce0(j)
//                              tplayer.cpp:2476 (18)
//         00515d05     MOV        this,dword ptr [ESI + 0x238]
//         00515d0b     PUSH       EBX
//         00515d0c     ADD        this,0x1146c
//         00515d12     CALL       TribeTacticalAIModule::detask                    void detask(TribeTacticalAIModule * this, int
//                              tplayer.cpp:2534 (7)
//         00515d17     POP        EDI
//         00515d18     POP        ESI
//         00515d19     POP        EBP
//         00515d1a     POP        EBX
//         00515d1b     RET        0x18
//                               switchD_00515c88::caseD_209                                  XREF[2]:     00515c88(j), 00515dcc(*)
//                              tplayer.cpp:2492 (13)
//         00515d1e     MOV        EDX,dword ptr [ESP + param_4]
//         00515d22     MOV        this,dword ptr [ESI + 0x3c]
//         00515d25     PUSH       EDX
//         00515d26     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              tplayer.cpp:2493 (8)
//         00515d2b     TEST       EAX,EAX
//         00515d2d     JZ         switchD_00515c88::caseD_203
//                              tplayer.cpp:2506 (29)
//         00515d33     MOV        EAX,dword ptr [EAX + 0xc]
//         00515d36     PUSH       0xa
//         00515d38     PUSH       0x0
//         00515d3a     MOVSX      this,word ptr [EAX + 0x4a]
//         00515d3e     PUSH       this
//         00515d3f     MOV        this,dword ptr [ESI + 0x238]
//         00515d45     ADD        this,0x9dc
//         00515d4b     CALL       DiplomacyAIModule::changeStance                  void changeStance(DiplomacyAIModule * this, i
//                              tplayer.cpp:2534 (7)
//         00515d50     POP        EDI
//         00515d51     POP        ESI
//         00515d52     POP        EBP
//         00515d53     POP        EBX
//         00515d54     RET        0x18
//                               switchD_00515c88::caseD_20a                                  XREF[2]:     00515c88(j), 00515dd0(*)
//                              tplayer.cpp:2519 (22)
//         00515d57     MOV        EDX,dword ptr [ESP + param_5]
//         00515d5b     MOV        EAX,dword ptr [ESP + param_4]
//         00515d5f     MOV        this,dword ptr [ESI + 0x238]
//         00515d65     PUSH       EDX
//         00515d66     PUSH       EAX
//         00515d67     PUSH       EBX
//         00515d68     CALL       TribeMainDecisionAIModule::tributeNotify         void tributeNotify(TribeMainDecisionAIModule
//                              tplayer.cpp:2534 (7)
//         00515d6d     POP        EDI
//         00515d6e     POP        ESI
//         00515d6f     POP        EBP
//         00515d70     POP        EBX
//         00515d71     RET        0x18
//                               switchD_00515c88::caseD_201                                  XREF[4]:     00515c01(j), 00515c0a(j),
//                                                                                                         00515c88(j), 00515dc4(*)
//                              tplayer.cpp:2526 (43)
//         00515d74     MOV        EAX,dword ptr [ESP + param_6]
//         00515d78     MOV        ESI,dword ptr [ESI + 0x238]
//         00515d7e     PUSH       EAX
//         00515d7f     MOV        EAX,dword ptr [ESP + param_5]
//         00515d83     MOV        EDX,dword ptr [ESI + 0x1146c]
//         00515d89     PUSH       EAX
//         00515d8a     MOV        EAX,dword ptr [ESP + param_4]
//         00515d8e     LEA        this,[ESI + 0x1146c]
//         00515d94     PUSH       EAX
//         00515d95     MOV        EAX,dword ptr [ESP + param_2]
//         00515d99     PUSH       EDI
//         00515d9a     PUSH       EAX
//         00515d9b     PUSH       EBX
//         00515d9c     CALL       dword ptr [EDX + 0x40]
//                              tplayer.cpp:2534 (7)
//         00515d9f     POP        EDI
//         00515da0     POP        ESI
//         00515da1     POP        EBP
//         00515da2     POP        EBX
//         00515da3     RET        0x18
//                               switchD_00515c88::caseD_20d                                  XREF[2]:     00515c88(j), 00515dd4(*)
//                              tplayer.cpp:2531 (22)
//         00515da6     MOV        this,dword ptr [ESP + param_4]
//         00515daa     PUSH       this
//         00515dab     MOV        this,dword ptr [ESI + 0x238]
//         00515db1     ADD        this,0xcec
//         00515db7     CALL       TribeInformationAIModule::addImportantObject     int addImportantObject(TribeInformationAIModu
//                               switchD_00515c88::caseD_204                                  XREF[10]:    00515bdd(j), 00515bec(j),
//                               switchD_00515c88::caseD_205                                               00515c1f(j), 00515c3b(j),
//                               switchD_00515c88::caseD_206                                               00515c4b(j), 00515c7a(j),
//                               switchD_00515c88::caseD_207                                               00515c88(j), 00515c9d(j),
//                               switchD_00515c88::caseD_208                                               00515d2d(j), 00515dd8(*)
//                               switchD_00515c88::caseD_20b
//                               switchD_00515c88::caseD_20c
//                               switchD_00515c88::caseD_203
//                              tplayer.cpp:2534 (45)
//         00515dbc     POP        EDI
//         00515dbd     POP        ESI
//         00515dbe     POP        EBP
//         00515dbf     POP        EBX
//         00515dc0     RET        0x18
//         00515dc3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00515c88::switchdataD_00515dc4                       XREF[1]:     notifyAI:00515c88(*)
//         00515dc4     addr       switchD_00515c88::caseD_201
//         00515dc8     addr       switchD_00515c88::caseD_202
//         00515dcc     addr       switchD_00515c88::caseD_209
//         00515dd0     addr       switchD_00515c88::caseD_20a
//         00515dd4     addr       switchD_00515c88::caseD_20d
//         00515dd8     addr       switchD_00515c88::caseD_203
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00515c88::switchdataD_00515ddc                       XREF[1]:     notifyAI:00515c82(*)
//         00515ddc     db         0h
//         00515ddd     db         1h
//         00515dde     db         5h
//         00515ddf     db         5h
//         00515de0     db         5h
//         00515de1     db         5h
//         00515de2     db         5h
//         00515de3     db         5h
//         00515de4     db         2h
//         00515de5     db         3h
//         00515de6     db         5h
//         00515de7     db         5h
//         00515de8     db         4h
//         00515de9     ??         90h
//         00515dea     ??         90h
//         00515deb     ??         90h
//         00515dec     ??         90h
//         00515ded     ??         90h
//         00515dee     ??         90h
//         00515def     ??         90h
    return;
}

int TRIBE_Player::intelligentCivSelection(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall intelligentCivSelection(TRIBE_Player * this, int para
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?intelligentCivSelection@TRIBE_Player@@QAEHHHH@Z
//                               TRIBE_Player::intelligentCivSelection
//                              tplayer.cpp:2541 (2)
//         00515df0     XOR        EAX,EAX
//                              tplayer.cpp:2543 (3)
//         00515df2     RET        0xc
//         00515df5     ??         90h
//         00515df6     NOP
//         00515df7     NOP
//         00515df8     NOP
//         00515df9     NOP
//         00515dfa     NOP
//         00515dfb     NOP
//         00515dfc     NOP
//         00515dfd     NOP
//         00515dfe     NOP
//         00515dff     NOP
    return 0;
}

void TRIBE_Player::intelligentBuildListAndRulesSelection(char* param_1, char* param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              void __thiscall intelligentBuildListAndRulesSelection(TRIBE_Player *
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00516b01(R)
//              char *            Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00515e4a(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00515e34(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00515e43(R)
//              char[256]         Stack[-0x104   tempString                XREF[2]:     005160d0(W), 005160e8(*)
//              int               Stack[-0x108   mostBuiltUnit2
//              int[125]          Stack[-0x2fc   buildLists                XREF[1,266]: 00515e25(W), 00515e30(*), 00515e64(*), 00515e78(*),
//                                                                                     00515e8c(*), 00515ea0(*), 00515eb4(*), 00515ec8(*),
//                                                                                     00515edc(*), 00515ef0(*), 00515f04(*), 00515f15(*),
//                                                                                     00515f26(*), 00515f37(*), 00515f48(*), 00515f59(*),
//                                                                                     00515f6a(*), 00515f7b(*), 00516180(R), 0051619a(W)
//              int               Stack[-0x300   difficultyLevel           XREF[7]:     005160cc(W), 005160ef(*), 00516106(R), 005162bd(W),
//                                                                                     005162c8(R), 00516a6f(R), 00516a77(W)
//              int               Stack[-0x304   mostBuiltUnit1
//                               ?intelligentBuildListAndRulesSelection@TRIBE_Player@@QAEXPA  XREF[2]:     loadAIInformation:00515587(c),
//                               TRIBE_Player::intelligentBuildListAndRulesSelection                       loadAIInformation:0051562a(c)
//                              tplayer.cpp:2550 (11)
//         00515e00     SUB        ESP,0x300
//         00515e06     PUSH       EBX
//         00515e07     PUSH       EBP
//         00515e08     MOV        EBP,this
//         00515e0a     PUSH       ESI
//                              tplayer.cpp:2551 (15)
//         00515e0b     XOR        ESI,ESI
//         00515e0d     PUSH       EDI
//         00515e0e     CMP        dword ptr [EBP + 0x238],ESI
//         00515e14     JZ         LAB_005176af
//                              tplayer.cpp:2555 (15)
//         00515e1a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515e20     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         00515e25     MOV        dword ptr [ESP + buildLists[0]],EAX
//                              tplayer.cpp:2609 (11)
//         00515e29     MOV        this,0x7d
//         00515e2e     XOR        EAX,EAX
//         00515e30     LEA        EDI=>buildLists[1],[ESP + 0x18]
//                              tplayer.cpp:2611 (46)
//         00515e34     MOV        EDX,dword ptr [ESP + param_4]
//         00515e3b     STOSD.REP  ES:EDI
//         00515e3d     MOV        AL,byte ptr [EBP + 0x105]
//         00515e43     MOV        this,dword ptr [ESP + param_5]
//         00515e4a     MOV        EDI,dword ptr [ESP + param_3]
//         00515e51     DEC        EAX
//         00515e52     CMP        EAX,0xf
//         00515e55     JA         switchD_00515e5b::default
//                               switchD_00515e5b::switchD
//         00515e5b     JMP        dword ptr [EAX*0x4 + switchD_00515e5b::switchd   = 00515e62
//                               switchD_00515e5b::caseD_1                                    XREF[2]:     00515e5b(j), 005177e8(*)
//                              tplayer.cpp:2614 (15)
//         00515e62     PUSH       this
//         00515e63     PUSH       EDX
//         00515e64     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515e68     PUSH       EDI
//         00515e69     PUSH       EAX
//         00515e6a     MOV        this,EBP
//         00515e6c     CALL       TRIBE_Player::setupEgyptian                      void setupEgyptian(TRIBE_Player * this, int *
//                              tplayer.cpp:2615 (5)
//         00515e71     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_2                                    XREF[2]:     00515e5b(j), 005177ec(*)
//                              tplayer.cpp:2618 (15)
//         00515e76     PUSH       this
//         00515e77     PUSH       EDX
//         00515e78     LEA        this=>buildLists[1],[ESP + 0x20]
//         00515e7c     PUSH       EDI
//         00515e7d     PUSH       this
//         00515e7e     MOV        this,EBP
//         00515e80     CALL       TRIBE_Player::setupGreek                         void setupGreek(TRIBE_Player * this, int * pa
//                              tplayer.cpp:2619 (5)
//         00515e85     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_3                                    XREF[2]:     00515e5b(j), 005177f0(*)
//                              tplayer.cpp:2622 (15)
//         00515e8a     PUSH       this
//         00515e8b     PUSH       EDX
//         00515e8c     LEA        EDX=>buildLists[1],[ESP + 0x20]
//         00515e90     PUSH       EDI
//         00515e91     PUSH       EDX
//         00515e92     MOV        this,EBP
//         00515e94     CALL       TRIBE_Player::setupBabylonian                    void setupBabylonian(TRIBE_Player * this, int
//                              tplayer.cpp:2623 (5)
//         00515e99     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_4                                    XREF[2]:     00515e5b(j), 005177f4(*)
//                              tplayer.cpp:2626 (15)
//         00515e9e     PUSH       this
//         00515e9f     PUSH       EDX
//         00515ea0     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515ea4     PUSH       EDI
//         00515ea5     PUSH       EAX
//         00515ea6     MOV        this,EBP
//         00515ea8     CALL       TRIBE_Player::setupAssyrian                      void setupAssyrian(TRIBE_Player * this, int *
//                              tplayer.cpp:2627 (5)
//         00515ead     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_5                                    XREF[2]:     00515e5b(j), 005177f8(*)
//                              tplayer.cpp:2630 (15)
//         00515eb2     PUSH       this
//         00515eb3     PUSH       EDX
//         00515eb4     LEA        this=>buildLists[1],[ESP + 0x20]
//         00515eb8     PUSH       EDI
//         00515eb9     PUSH       this
//         00515eba     MOV        this,EBP
//         00515ebc     CALL       TRIBE_Player::setupMinoan                        void setupMinoan(TRIBE_Player * this, int * p
//                              tplayer.cpp:2631 (5)
//         00515ec1     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_6                                    XREF[2]:     00515e5b(j), 005177fc(*)
//                              tplayer.cpp:2634 (15)
//         00515ec6     PUSH       this
//         00515ec7     PUSH       EDX
//         00515ec8     LEA        EDX=>buildLists[1],[ESP + 0x20]
//         00515ecc     PUSH       EDI
//         00515ecd     PUSH       EDX
//         00515ece     MOV        this,EBP
//         00515ed0     CALL       TRIBE_Player::setupHittite                       void setupHittite(TRIBE_Player * this, int *
//                              tplayer.cpp:2635 (5)
//         00515ed5     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_7                                    XREF[2]:     00515e5b(j), 00517800(*)
//                              tplayer.cpp:2638 (15)
//         00515eda     PUSH       this
//         00515edb     PUSH       EDX
//         00515edc     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515ee0     PUSH       EDI
//         00515ee1     PUSH       EAX
//         00515ee2     MOV        this,EBP
//         00515ee4     CALL       TRIBE_Player::setupPhoenician                    void setupPhoenician(TRIBE_Player * this, int
//                              tplayer.cpp:2639 (5)
//         00515ee9     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_8                                    XREF[2]:     00515e5b(j), 00517804(*)
//                              tplayer.cpp:2642 (15)
//         00515eee     PUSH       this
//         00515eef     PUSH       EDX
//         00515ef0     LEA        this=>buildLists[1],[ESP + 0x20]
//         00515ef4     PUSH       EDI
//         00515ef5     PUSH       this
//         00515ef6     MOV        this,EBP
//         00515ef8     CALL       TRIBE_Player::setupSumerian                      void setupSumerian(TRIBE_Player * this, int *
//                              tplayer.cpp:2643 (5)
//         00515efd     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_9                                    XREF[2]:     00515e5b(j), 00517808(*)
//                              tplayer.cpp:2646 (15)
//         00515f02     PUSH       this
//         00515f03     PUSH       EDX
//         00515f04     LEA        EDX=>buildLists[1],[ESP + 0x20]
//         00515f08     PUSH       EDI
//         00515f09     PUSH       EDX
//         00515f0a     MOV        this,EBP
//         00515f0c     CALL       TRIBE_Player::setupPersian                       void setupPersian(TRIBE_Player * this, int *
//                              tplayer.cpp:2647 (2)
//         00515f11     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_a                                    XREF[2]:     00515e5b(j), 0051780c(*)
//                              tplayer.cpp:2650 (15)
//         00515f13     PUSH       this
//         00515f14     PUSH       EDX
//         00515f15     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515f19     PUSH       EDI
//         00515f1a     PUSH       EAX
//         00515f1b     MOV        this,EBP
//         00515f1d     CALL       TRIBE_Player::setupShang                         void setupShang(TRIBE_Player * this, int * pa
//                              tplayer.cpp:2651 (2)
//         00515f22     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_b                                    XREF[2]:     00515e5b(j), 00517810(*)
//                              tplayer.cpp:2654 (15)
//         00515f24     PUSH       this
//         00515f25     PUSH       EDX
//         00515f26     LEA        this=>buildLists[1],[ESP + 0x20]
//         00515f2a     PUSH       EDI
//         00515f2b     PUSH       this
//         00515f2c     MOV        this,EBP
//         00515f2e     CALL       TRIBE_Player::setupYamato                        void setupYamato(TRIBE_Player * this, int * p
//                              tplayer.cpp:2655 (2)
//         00515f33     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_c                                    XREF[2]:     00515e5b(j), 00517814(*)
//                              tplayer.cpp:2658 (15)
//         00515f35     PUSH       this
//         00515f36     PUSH       EDX
//         00515f37     LEA        EDX=>buildLists[1],[ESP + 0x20]
//         00515f3b     PUSH       EDI
//         00515f3c     PUSH       EDX
//         00515f3d     MOV        this,EBP
//         00515f3f     CALL       TRIBE_Player::setupChoson                        void setupChoson(TRIBE_Player * this, int * p
//                              tplayer.cpp:2659 (2)
//         00515f44     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_d                                    XREF[2]:     00515e5b(j), 00517818(*)
//                              tplayer.cpp:2662 (15)
//         00515f46     PUSH       this
//         00515f47     PUSH       EDX
//         00515f48     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515f4c     PUSH       EDI
//         00515f4d     PUSH       EAX
//         00515f4e     MOV        this,EBP
//         00515f50     CALL       TRIBE_Player::setupRoman                         void setupRoman(TRIBE_Player * this, int * pa
//                              tplayer.cpp:2663 (2)
//         00515f55     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_e                                    XREF[2]:     00515e5b(j), 0051781c(*)
//                              tplayer.cpp:2666 (15)
//         00515f57     PUSH       this
//         00515f58     PUSH       EDX
//         00515f59     LEA        this=>buildLists[1],[ESP + 0x20]
//         00515f5d     PUSH       EDI
//         00515f5e     PUSH       this
//         00515f5f     MOV        this,EBP
//         00515f61     CALL       TRIBE_Player::setupCarthaginian                  void setupCarthaginian(TRIBE_Player * this, i
//                              tplayer.cpp:2667 (2)
//         00515f66     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_f                                    XREF[2]:     00515e5b(j), 00517820(*)
//                              tplayer.cpp:2670 (15)
//         00515f68     PUSH       this
//         00515f69     PUSH       EDX
//         00515f6a     LEA        EDX=>buildLists[1],[ESP + 0x20]
//         00515f6e     PUSH       EDI
//         00515f6f     PUSH       EDX
//         00515f70     MOV        this,EBP
//         00515f72     CALL       TRIBE_Player::setupPalmyran                      void setupPalmyran(TRIBE_Player * this, int *
//                              tplayer.cpp:2671 (2)
//         00515f77     JMP        switchD_00515e5b::default
//                               switchD_00515e5b::caseD_10                                   XREF[2]:     00515e5b(j), 00517824(*)
//                              tplayer.cpp:2674 (15)
//         00515f79     PUSH       this
//         00515f7a     PUSH       EDX
//         00515f7b     LEA        EAX=>buildLists[1],[ESP + 0x20]
//         00515f7f     PUSH       EDI
//         00515f80     PUSH       EAX
//         00515f81     MOV        this,EBP
//         00515f83     CALL       TRIBE_Player::setupMacedonian                    void setupMacedonian(TRIBE_Player * this, int
//                               switchD_00515e5b::default                                    XREF[16]:    00515e55(j), 00515e71(j),
//                                                                                                         00515e85(j), 00515e99(j),
//                                                                                                         00515ead(j), 00515ec1(j),
//                                                                                                         00515ed5(j), 00515ee9(j),
//                                                                                                         00515efd(j), 00515f11(j),
//                                                                                                         00515f22(j), 00515f33(j),
//                                                                                                         00515f44(j), 00515f55(j),
//                                                                                                         00515f66(j), 00515f77(j)
//                              tplayer.cpp:2682 (29)
//         00515f88     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00515f8e     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00515f93     TEST       AL,AL
//         00515f95     MOV        EBX,0x32
//         00515f9a     MOV        EDX,0x64
//         00515f9f     JNZ        LAB_00516094
//                              tplayer.cpp:2691 (52)
//         00515fa5     XOR        EAX,EAX
//         00515fa7     MOV        AL,byte ptr [EBP + 0x105]
//         00515fad     DEC        EAX
//         00515fae     CMP        EAX,0x3
//         00515fb1     JZ         LAB_00515fd9
//         00515fb3     CMP        EAX,ESI
//         00515fb5     JZ         LAB_00515fd9
//         00515fb7     CMP        EAX,0x1
//         00515fba     JZ         LAB_00515fd9
//         00515fbc     CMP        EAX,0x4
//         00515fbf     JZ         LAB_00515fd9
//         00515fc1     CMP        EAX,0x8
//         00515fc4     JZ         LAB_00515fd9
//         00515fc6     CMP        EAX,0x6
//         00515fc9     JZ         LAB_00515fd9
//         00515fcb     CMP        EAX,0x7
//         00515fce     JZ         LAB_00515fd9
//         00515fd0     CMP        EAX,0xa
//         00515fd3     JNZ        LAB_00516094
//                               LAB_00515fd9                                                 XREF[7]:     00515fb1(j), 00515fb5(j),
//                                                                                                         00515fba(j), 00515fbf(j),
//                                                                                                         00515fc4(j), 00515fc9(j),
//                                                                                                         00515fce(j)
//                              tplayer.cpp:2692 (15)
//         00515fd9     MOV        this,dword ptr [DAT_00886c48]
//         00515fdf     MOV        EAX,[DAT_00886c44]
//         00515fe4     CMP        EDI,ESI
//         00515fe6     JNZ        LAB_00516011
//                              tplayer.cpp:2694 (4)
//         00515fe8     CMP        EAX,ESI
//         00515fea     JLE        LAB_00516009
//                              tplayer.cpp:2695 (4)
//         00515fec     CMP        this,ESI
//         00515fee     JNZ        LAB_00515fff
//                              tplayer.cpp:2696 (9)
//         00515ff0     MOV        EDX,0x12c
//         00515ff5     ADD        dword ptr [ESP + buildLists[14]],EDX
//                              tplayer.cpp:2697 (4)
//         00515ff9     ADD        dword ptr [ESP + buildLists[15]],EDX
//                              tplayer.cpp:2699 (2)
//         00515ffd     JMP        LAB_00516011
//                               LAB_00515fff                                                 XREF[1]:     00515fee(j)
//                              tplayer.cpp:2700 (4)
//         00515fff     ADD        dword ptr [ESP + buildLists[14]],EDX
//                              tplayer.cpp:2701 (4)
//         00516003     ADD        dword ptr [ESP + buildLists[15]],EDX
//                              tplayer.cpp:2705 (2)
//         00516007     JMP        LAB_00516011
//                               LAB_00516009                                                 XREF[1]:     00515fea(j)
//                              tplayer.cpp:2706 (4)
//         00516009     MOV        dword ptr [ESP + buildLists[14]],ESI
//                              tplayer.cpp:2707 (4)
//         0051600d     MOV        dword ptr [ESP + buildLists[15]],ESI
//                               LAB_00516011                                                 XREF[3]:     00515fe6(j), 00515ffd(j),
//                                                                                                         00516007(j)
//                              tplayer.cpp:2710 (5)
//         00516011     CMP        EDI,0x1
//         00516014     JNZ        LAB_00516044
//                              tplayer.cpp:2712 (4)
//         00516016     CMP        EAX,ESI
//         00516018     JLE        LAB_0051603c
//                              tplayer.cpp:2713 (4)
//         0051601a     CMP        this,ESI
//         0051601c     JNZ        LAB_0051602d
//                              tplayer.cpp:2714 (9)
//         0051601e     MOV        EDX,0xfa
//         00516023     ADD        dword ptr [ESP + buildLists[14]],EDX
//                              tplayer.cpp:2715 (4)
//         00516027     ADD        dword ptr [ESP + buildLists[15]],EDX
//                              tplayer.cpp:2717 (2)
//         0051602b     JMP        LAB_00516044
//                               LAB_0051602d                                                 XREF[1]:     0051601c(j)
//                              tplayer.cpp:2718 (9)
//         0051602d     MOV        EDX,0x4b
//         00516032     ADD        dword ptr [ESP + buildLists[14]],EDX
//                              tplayer.cpp:2719 (4)
//         00516036     ADD        dword ptr [ESP + buildLists[15]],EDX
//                              tplayer.cpp:2723 (2)
//         0051603a     JMP        LAB_00516044
//                               LAB_0051603c                                                 XREF[1]:     00516018(j)
//                              tplayer.cpp:2724 (4)
//         0051603c     MOV        dword ptr [ESP + buildLists[14]],ESI
//                              tplayer.cpp:2725 (4)
//         00516040     MOV        dword ptr [ESP + buildLists[15]],ESI
//                               LAB_00516044                                                 XREF[3]:     00516014(j), 0051602b(j),
//                                                                                                         0051603a(j)
//                              tplayer.cpp:2730 (15)
//         00516044     CMP        EDI,0x2
//         00516047     JZ         LAB_00516053
//         00516049     CMP        EDI,0x6
//         0051604c     JZ         LAB_00516053
//         0051604e     CMP        EDI,0x8
//         00516051     JNZ        LAB_00516094
//                               LAB_00516053                                                 XREF[2]:     00516047(j), 0051604c(j)
//                              tplayer.cpp:2733 (4)
//         00516053     CMP        EAX,ESI
//         00516055     JLE        LAB_0051608c
//                              tplayer.cpp:2734 (4)
//         00516057     CMP        this,ESI
//         00516059     JNZ        LAB_00516076
//                              tplayer.cpp:2735 (4)
//         0051605b     MOV        EDX,dword ptr [ESP + buildLists[14]]
//                              tplayer.cpp:2736 (21)
//         0051605f     MOV        this,dword ptr [ESP + buildLists[15]]
//         00516063     MOV        EAX,0xc8
//         00516068     ADD        EDX,EAX
//         0051606a     ADD        this,EAX
//         0051606c     MOV        dword ptr [ESP + buildLists[14]],EDX
//         00516070     MOV        dword ptr [ESP + buildLists[15]],this
//                              tplayer.cpp:2738 (2)
//         00516074     JMP        LAB_00516094
//                               LAB_00516076                                                 XREF[1]:     00516059(j)
//                              tplayer.cpp:2739 (4)
//         00516076     MOV        this,dword ptr [ESP + buildLists[14]]
//                              tplayer.cpp:2740 (16)
//         0051607a     MOV        EAX,dword ptr [ESP + buildLists[15]]
//         0051607e     ADD        this,EBX
//         00516080     ADD        EAX,EBX
//         00516082     MOV        dword ptr [ESP + buildLists[14]],this
//         00516086     MOV        dword ptr [ESP + buildLists[15]],EAX
//                              tplayer.cpp:2744 (2)
//         0051608a     JMP        LAB_00516094
//                               LAB_0051608c                                                 XREF[1]:     00516055(j)
//                              tplayer.cpp:2745 (4)
//         0051608c     MOV        dword ptr [ESP + buildLists[14]],ESI
//                              tplayer.cpp:2746 (4)
//         00516090     MOV        dword ptr [ESP + buildLists[15]],ESI
//                               LAB_00516094                                                 XREF[5]:     00515f9f(j), 00515fd3(j),
//                                                                                                         00516051(j), 00516074(j),
//                                                                                                         0051608a(j)
//                              tplayer.cpp:2753 (24)
//         00516094     MOV        this,dword ptr [EBP + 0x238]
//         0051609a     PUSH       0x1
//         0051609c     PUSH       0xc9
//         005160a1     ADD        this,0x10e74
//         005160a7     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:2755 (32)
//         005160ac     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005160b2     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         005160b7     OR         this,0xffffffff
//         005160ba     MOV        EBX,0x1e
//         005160bf     TEST       AL,AL
//         005160c1     MOV        EDI,0x19
//         005160c6     JNZ        LAB_005162ab
//                              tplayer.cpp:2758 (4)
//         005160cc     MOV        dword ptr [ESP + difficultyLevel],this
//                              tplayer.cpp:2759 (7)
//         005160d0     MOV        dword ptr [ESP + tempString[0]],this
//                              tplayer.cpp:2762 (17)
//         005160d7     MOV        this,dword ptr [EBP + 0x238]
//         005160dd     ADD        this,0xcec
//         005160e3     CALL       TribeInformationAIModule::loadUnitHistory        void loadUnitHistory(TribeInformationAIModule
//                              tplayer.cpp:2763 (30)
//         005160e8     LEA        this=>tempString,[ESP + 0x20c]
//         005160ef     LEA        EDX=>difficultyLevel,[ESP + 0x10]
//         005160f3     PUSH       this
//         005160f4     MOV        this,dword ptr [EBP + 0x238]
//         005160fa     PUSH       EDX
//         005160fb     ADD        this,0xcec
//         00516101     CALL       TribeInformationAIModule::unitsThatAreMostBuilt  void unitsThatAreMostBuilt(TribeInformationAI
//                              tplayer.cpp:2766 (20)
//         00516106     MOV        EAX,dword ptr [ESP + difficultyLevel]
//         0051610a     CMP        EAX,0xa
//         0051610d     JA         LAB_005162ab
//                               switchD_00516113::switchD
//         00516113     JMP        dword ptr [EAX*0x4 + switchD_00516113::switchd   = 0051611a
//                               switchD_00516113::caseD_0                                    XREF[2]:     00516113(j), 00517828(*)
//                              tplayer.cpp:2769 (4)
//         0051611a     MOV        this,dword ptr [ESP + buildLists[7]]
//                              tplayer.cpp:2770 (16)
//         0051611e     MOV        EAX,dword ptr [ESP + buildLists[8]]
//         00516122     ADD        this,EDI
//         00516124     ADD        EAX,EDI
//         00516126     MOV        dword ptr [ESP + buildLists[7]],this
//         0051612a     MOV        dword ptr [ESP + buildLists[8]],EAX
//                              tplayer.cpp:2771 (5)
//         0051612e     JMP        LAB_005162ab
//                               switchD_00516113::caseD_1                                    XREF[2]:     00516113(j), 0051782c(*)
//                              tplayer.cpp:2774 (4)
//         00516133     MOV        this,dword ptr [ESP + buildLists[7]]
//                              tplayer.cpp:2775 (16)
//         00516137     MOV        EAX,dword ptr [ESP + buildLists[8]]
//         0051613b     ADD        this,EBX
//         0051613d     ADD        EAX,EBX
//         0051613f     MOV        dword ptr [ESP + buildLists[7]],this
//         00516143     MOV        dword ptr [ESP + buildLists[8]],EAX
//                              tplayer.cpp:2776 (5)
//         00516147     JMP        LAB_005162ab
//                               switchD_00516113::caseD_2                                    XREF[2]:     00516113(j), 00517830(*)
//                              tplayer.cpp:2779 (4)
//         0051614c     MOV        EAX,dword ptr [ESP + buildLists[18]]
//                              tplayer.cpp:2780 (4)
//         00516150     MOV        this,dword ptr [ESP + buildLists[19]]
//                              tplayer.cpp:2781 (4)
//         00516154     MOV        EDI,dword ptr [ESP + buildLists[4]]
//                              tplayer.cpp:2782 (35)
//         00516158     MOV        EDX,dword ptr [ESP + buildLists[5]]
//         0051615c     ADD        EAX,0x14
//         0051615f     ADD        this,0x14
//         00516162     MOV        dword ptr [ESP + buildLists[18]],EAX
//         00516166     MOV        EAX,0x28
//         0051616b     ADD        EDI,EAX
//         0051616d     ADD        EDX,EAX
//         0051616f     MOV        dword ptr [ESP + buildLists[19]],this
//         00516173     MOV        dword ptr [ESP + buildLists[4]],EDI
//         00516177     MOV        dword ptr [ESP + buildLists[5]],EDX
//                              tplayer.cpp:2783 (5)
//         0051617b     JMP        LAB_005162af
//                               switchD_00516113::caseD_3                                    XREF[2]:     00516113(j), 00517834(*)
//                              tplayer.cpp:2786 (4)
//         00516180     MOV        EAX,dword ptr [ESP + buildLists[1]]
//                              tplayer.cpp:2792 (35)
//         00516184     MOV        this,dword ptr [ESP + buildLists[18]]
//         00516188     MOV        EBX,dword ptr [ESP + buildLists[2]]
//         0051618c     MOV        EDI,dword ptr [ESP + buildLists[20]]
//         00516190     MOV        EDX,dword ptr [ESP + buildLists[21]]
//         00516194     ADD        EAX,0x28
//         00516197     SUB        this,0x3c
//         0051619a     MOV        dword ptr [ESP + buildLists[1]],EAX
//         0051619e     MOV        EAX,0x14
//         005161a3     MOV        dword ptr [ESP + buildLists[18]],this
//                              tplayer.cpp:2793 (29)
//         005161a7     MOV        this,dword ptr [ESP + buildLists[19]]
//         005161ab     ADD        EBX,EAX
//         005161ad     ADD        EDI,EAX
//         005161af     ADD        EDX,EAX
//         005161b1     SUB        this,0x3c
//         005161b4     MOV        dword ptr [ESP + buildLists[2]],EBX
//         005161b8     MOV        dword ptr [ESP + buildLists[20]],EDI
//         005161bc     MOV        dword ptr [ESP + buildLists[21]],EDX
//         005161c0     MOV        dword ptr [ESP + buildLists[19]],this
//                              tplayer.cpp:2794 (5)
//         005161c4     JMP        LAB_005162af
//                               switchD_00516113::caseD_4                                    XREF[2]:     00516113(j), 00517838(*)
//                              tplayer.cpp:2797 (4)
//         005161c9     MOV        EBX,dword ptr [ESP + buildLists[7]]
//                              tplayer.cpp:2798 (21)
//         005161cd     MOV        EDI,dword ptr [ESP + buildLists[8]]
//         005161d1     MOV        EAX,0xf
//         005161d6     ADD        EBX,EAX
//         005161d8     ADD        EDI,EAX
//         005161da     MOV        dword ptr [ESP + buildLists[7]],EBX
//         005161de     MOV        dword ptr [ESP + buildLists[8]],EDI
//                              tplayer.cpp:2800 (5)
//         005161e2     MOV        EAX,0x14
//                              tplayer.cpp:2802 (5)
//         005161e7     JMP        LAB_00516297
//                               switchD_00516113::caseD_5                                    XREF[2]:     00516113(j), 0051783c(*)
//                              tplayer.cpp:2805 (4)
//         005161ec     MOV        EBX,dword ptr [ESP + buildLists[7]]
//                              tplayer.cpp:2806 (4)
//         005161f0     MOV        EDI,dword ptr [ESP + buildLists[8]]
//                              tplayer.cpp:2808 (4)
//         005161f4     MOV        EDX,dword ptr [ESP + buildLists[1]]
//                              tplayer.cpp:2809 (38)
//         005161f8     MOV        this,dword ptr [ESP + buildLists[2]]
//         005161fc     MOV        EAX,0xf
//         00516201     ADD        EBX,EAX
//         00516203     ADD        EDI,EAX
//         00516205     MOV        EAX,0xa
//         0051620a     MOV        dword ptr [ESP + buildLists[7]],EBX
//         0051620e     ADD        EDX,EAX
//         00516210     ADD        this,EAX
//         00516212     MOV        dword ptr [ESP + buildLists[8]],EDI
//         00516216     MOV        dword ptr [ESP + buildLists[1]],EDX
//         0051621a     MOV        dword ptr [ESP + buildLists[2]],this
//                              tplayer.cpp:2810 (5)
//         0051621e     JMP        LAB_005162ab
//                               switchD_00516113::caseD_6                                    XREF[2]:     00516113(j), 00517840(*)
//                              tplayer.cpp:2813 (4)
//         00516223     MOV        EDX,dword ptr [ESP + buildLists[7]]
//                              tplayer.cpp:2814 (21)
//         00516227     MOV        this,dword ptr [ESP + buildLists[8]]
//         0051622b     MOV        EAX,0xf
//         00516230     ADD        EDX,EAX
//         00516232     ADD        this,EAX
//         00516234     MOV        dword ptr [ESP + buildLists[7]],EDX
//         00516238     MOV        dword ptr [ESP + buildLists[8]],this
//                              tplayer.cpp:2815 (2)
//         0051623c     JMP        LAB_005162ab
//                               switchD_00516113::caseD_a                                    XREF[3]:     00516113(j), 00517844(*),
//                               switchD_00516113::caseD_7                                                 00517850(*)
//                              tplayer.cpp:2819 (4)
//         0051623e     MOV        EDX,dword ptr [ESP + buildLists[20]]
//                              tplayer.cpp:2820 (17)
//         00516242     MOV        this,dword ptr [ESP + buildLists[21]]
//         00516246     MOV        EAX,0x3c
//         0051624b     SUB        EDX,EAX
//         0051624d     SUB        this,EAX
//         0051624f     MOV        dword ptr [ESP + buildLists[20]],EDX
//                              tplayer.cpp:2821 (2)
//         00516253     JMP        LAB_005162a7
//                               switchD_00516113::caseD_8                                    XREF[2]:     00516113(j), 00517848(*)
//                              tplayer.cpp:2824 (4)
//         00516255     MOV        EDX,dword ptr [ESP + buildLists[20]]
//                              tplayer.cpp:2825 (13)
//         00516259     MOV        this,dword ptr [ESP + buildLists[21]]
//         0051625d     MOV        EAX,0x28
//         00516262     ADD        EDX,EAX
//         00516264     ADD        this,EAX
//                              tplayer.cpp:2827 (17)
//         00516266     MOV        EAX,[DAT_00886c44]
//         0051626b     MOV        dword ptr [ESP + buildLists[20]],EDX
//         0051626f     CMP        EAX,ESI
//         00516271     MOV        dword ptr [ESP + buildLists[21]],this
//         00516275     JLE        LAB_005162ab
//                              tplayer.cpp:2828 (4)
//         00516277     MOV        EDX,dword ptr [ESP + buildLists[14]]
//                              tplayer.cpp:2829 (21)
//         0051627b     MOV        this,dword ptr [ESP + buildLists[15]]
//         0051627f     MOV        EAX,0x32
//         00516284     ADD        EDX,EAX
//         00516286     ADD        this,EAX
//         00516288     MOV        dword ptr [ESP + buildLists[14]],EDX
//         0051628c     MOV        dword ptr [ESP + buildLists[15]],this
//                              tplayer.cpp:2831 (2)
//         00516290     JMP        LAB_005162ab
//                               switchD_00516113::caseD_9                                    XREF[2]:     00516113(j), 0051784c(*)
//                              tplayer.cpp:2834 (9)
//         00516292     MOV        EAX,0x64
//                               LAB_00516297                                                 XREF[1]:     005161e7(j)
//         00516297     MOV        EDX,dword ptr [ESP + buildLists[20]]
//                              tplayer.cpp:2835 (16)
//         0051629b     MOV        this,dword ptr [ESP + buildLists[21]]
//         0051629f     ADD        EDX,EAX
//         005162a1     ADD        this,EAX
//         005162a3     MOV        dword ptr [ESP + buildLists[20]],EDX
//                               LAB_005162a7                                                 XREF[1]:     00516253(j)
//         005162a7     MOV        dword ptr [ESP + buildLists[21]],this
//                               LAB_005162ab                                                 XREF[8]:     005160c6(j), 0051610d(j),
//                                                                                                         0051612e(j), 00516147(j),
//                                                                                                         0051621e(j), 0051623c(j),
//                                                                                                         00516275(j), 00516290(j)
//                              tplayer.cpp:2831 (4)
//         005162ab     MOV        this,dword ptr [ESP + buildLists[19]]
//                               LAB_005162af                                                 XREF[2]:     0051617b(j), 005161c4(j)
//                              tplayer.cpp:2853 (25)
//         005162af     MOV        EDI,dword ptr [ESP + buildLists[52]]
//         005162b6     MOV        EBX,dword ptr [ESP + buildLists[51]]
//         005162bd     MOV        dword ptr [ESP + difficultyLevel],ESI
//         005162c1     MOV        ESI,dword ptr [ESP + buildLists[42]]
//                               LAB_005162c8                                                 XREF[1]:     00516a7b(j)
//                              tplayer.cpp:2854 (20)
//         005162c8     MOV        EAX,dword ptr [ESP + difficultyLevel]
//         005162cc     CMP        EAX,0x6
//         005162cf     JA         switchD_005162d5::default
//                               switchD_005162d5::switchD
//         005162d5     JMP        dword ptr [EAX*0x4 + switchD_005162d5::switchd   = 005162dc
//                               switchD_005162d5::caseD_0                                    XREF[2]:     005162d5(j), 00517854(*)
//                              tplayer.cpp:2856 (8)
//         005162dc     MOV        EAX,dword ptr [ESP + buildLists[20]]
//         005162e0     TEST       EAX,EAX
//         005162e2     JLE        LAB_005162f8
//                              tplayer.cpp:2857 (20)
//         005162e4     MOV        EAX,0x55555556
//         005162e9     IMUL       dword ptr [ESP + buildLists[20]]
//         005162ed     MOV        EAX,EDX
//         005162ef     SHR        EAX,0x1f
//         005162f2     ADD        EDX,EAX
//         005162f4     MOV        dword ptr [ESP + buildLists[20]],EDX
//                               LAB_005162f8                                                 XREF[1]:     005162e2(j)
//                              tplayer.cpp:2858 (8)
//         005162f8     MOV        EAX,dword ptr [ESP + buildLists[21]]
//         005162fc     TEST       EAX,EAX
//         005162fe     JLE        LAB_00516314
//                              tplayer.cpp:2859 (20)
//         00516300     MOV        EAX,0x55555556
//         00516305     IMUL       dword ptr [ESP + buildLists[21]]
//         00516309     MOV        EAX,EDX
//         0051630b     SHR        EAX,0x1f
//         0051630e     ADD        EDX,EAX
//         00516310     MOV        dword ptr [ESP + buildLists[21]],EDX
//                               LAB_00516314                                                 XREF[1]:     005162fe(j)
//                              tplayer.cpp:2860 (12)
//         00516314     MOV        EAX,dword ptr [ESP + buildLists[22]]
//         00516318     TEST       EAX,EAX
//         0051631a     JLE        switchD_005162d5::default
//                              tplayer.cpp:2861 (20)
//         00516320     MOV        EAX,0x55555556
//         00516325     IMUL       dword ptr [ESP + buildLists[22]]
//         00516329     MOV        EAX,EDX
//         0051632b     SHR        EAX,0x1f
//         0051632e     ADD        EDX,EAX
//         00516330     MOV        dword ptr [ESP + buildLists[22]],EDX
//                              tplayer.cpp:2862 (5)
//         00516334     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_1                                    XREF[2]:     005162d5(j), 00517858(*)
//                              tplayer.cpp:2864 (8)
//         00516339     MOV        EAX,dword ptr [ESP + buildLists[7]]
//         0051633d     TEST       EAX,EAX
//         0051633f     JLE        LAB_00516355
//                              tplayer.cpp:2865 (20)
//         00516341     MOV        EAX,0x55555556
//         00516346     IMUL       dword ptr [ESP + buildLists[7]]
//         0051634a     MOV        EAX,EDX
//         0051634c     SHR        EAX,0x1f
//         0051634f     ADD        EDX,EAX
//         00516351     MOV        dword ptr [ESP + buildLists[7]],EDX
//                               LAB_00516355                                                 XREF[1]:     0051633f(j)
//                              tplayer.cpp:2866 (8)
//         00516355     MOV        EAX,dword ptr [ESP + buildLists[8]]
//         00516359     TEST       EAX,EAX
//         0051635b     JLE        LAB_00516371
//                              tplayer.cpp:2867 (20)
//         0051635d     MOV        EAX,0x55555556
//         00516362     IMUL       dword ptr [ESP + buildLists[8]]
//         00516366     MOV        EAX,EDX
//         00516368     SHR        EAX,0x1f
//         0051636b     ADD        EDX,EAX
//         0051636d     MOV        dword ptr [ESP + buildLists[8]],EDX
//                               LAB_00516371                                                 XREF[1]:     0051635b(j)
//                              tplayer.cpp:2868 (8)
//         00516371     MOV        EAX,dword ptr [ESP + buildLists[9]]
//         00516375     TEST       EAX,EAX
//         00516377     JLE        LAB_0051638d
//                              tplayer.cpp:2869 (20)
//         00516379     MOV        EAX,0x55555556
//         0051637e     IMUL       dword ptr [ESP + buildLists[9]]
//         00516382     MOV        EAX,EDX
//         00516384     SHR        EAX,0x1f
//         00516387     ADD        EDX,EAX
//         00516389     MOV        dword ptr [ESP + buildLists[9]],EDX
//                               LAB_0051638d                                                 XREF[1]:     00516377(j)
//                              tplayer.cpp:2870 (11)
//         0051638d     MOV        EAX,dword ptr [ESP + buildLists[60]]
//         00516394     TEST       EAX,EAX
//         00516396     JLE        LAB_005163b2
//                              tplayer.cpp:2871 (26)
//         00516398     MOV        EAX,0x55555556
//         0051639d     IMUL       dword ptr [ESP + buildLists[60]]
//         005163a4     MOV        EAX,EDX
//         005163a6     SHR        EAX,0x1f
//         005163a9     ADD        EDX,EAX
//         005163ab     MOV        dword ptr [ESP + buildLists[60]],EDX
//                               LAB_005163b2                                                 XREF[1]:     00516396(j)
//                              tplayer.cpp:2872 (11)
//         005163b2     MOV        EAX,dword ptr [ESP + buildLists[59]]
//         005163b9     TEST       EAX,EAX
//         005163bb     JLE        LAB_005163d7
//                              tplayer.cpp:2873 (26)
//         005163bd     MOV        EAX,0x55555556
//         005163c2     IMUL       dword ptr [ESP + buildLists[59]]
//         005163c9     MOV        EAX,EDX
//         005163cb     SHR        EAX,0x1f
//         005163ce     ADD        EDX,EAX
//         005163d0     MOV        dword ptr [ESP + buildLists[59]],EDX
//                               LAB_005163d7                                                 XREF[1]:     005163bb(j)
//                              tplayer.cpp:2874 (11)
//         005163d7     MOV        EAX,dword ptr [ESP + buildLists[55]]
//         005163de     TEST       EAX,EAX
//         005163e0     JLE        LAB_005163fc
//                              tplayer.cpp:2875 (26)
//         005163e2     MOV        EAX,0x55555556
//         005163e7     IMUL       dword ptr [ESP + buildLists[55]]
//         005163ee     MOV        EAX,EDX
//         005163f0     SHR        EAX,0x1f
//         005163f3     ADD        EDX,EAX
//         005163f5     MOV        dword ptr [ESP + buildLists[55]],EDX
//                               LAB_005163fc                                                 XREF[1]:     005163e0(j)
//                              tplayer.cpp:2876 (11)
//         005163fc     MOV        EAX,dword ptr [ESP + buildLists[56]]
//         00516403     TEST       EAX,EAX
//         00516405     JLE        LAB_00516421
//                              tplayer.cpp:2877 (26)
//         00516407     MOV        EAX,0x55555556
//         0051640c     IMUL       dword ptr [ESP + buildLists[56]]
//         00516413     MOV        EAX,EDX
//         00516415     SHR        EAX,0x1f
//         00516418     ADD        EDX,EAX
//         0051641a     MOV        dword ptr [ESP + buildLists[56]],EDX
//                               LAB_00516421                                                 XREF[1]:     00516405(j)
//                              tplayer.cpp:2878 (15)
//         00516421     MOV        EAX,dword ptr [ESP + buildLists[105]]
//         00516428     TEST       EAX,EAX
//         0051642a     JLE        switchD_005162d5::default
//                              tplayer.cpp:2879 (26)
//         00516430     MOV        EAX,0x55555556
//         00516435     IMUL       dword ptr [ESP + buildLists[105]]
//         0051643c     MOV        EAX,EDX
//         0051643e     SHR        EAX,0x1f
//         00516441     ADD        EDX,EAX
//         00516443     MOV        dword ptr [ESP + buildLists[105]],EDX
//                              tplayer.cpp:2880 (5)
//         0051644a     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_2                                    XREF[2]:     005162d5(j), 0051785c(*)
//                              tplayer.cpp:2882 (8)
//         0051644f     MOV        EAX,dword ptr [ESP + buildLists[17]]
//         00516453     TEST       EAX,EAX
//         00516455     JLE        LAB_0051646b
//                              tplayer.cpp:2883 (20)
//         00516457     MOV        EAX,0x55555556
//         0051645c     IMUL       dword ptr [ESP + buildLists[17]]
//         00516460     MOV        EAX,EDX
//         00516462     SHR        EAX,0x1f
//         00516465     ADD        EDX,EAX
//         00516467     MOV        dword ptr [ESP + buildLists[17]],EDX
//                               LAB_0051646b                                                 XREF[1]:     00516455(j)
//                              tplayer.cpp:2884 (11)
//         0051646b     MOV        EAX,dword ptr [ESP + buildLists[50]]
//         00516472     TEST       EAX,EAX
//         00516474     JLE        LAB_00516490
//                              tplayer.cpp:2885 (26)
//         00516476     MOV        EAX,0x55555556
//         0051647b     IMUL       dword ptr [ESP + buildLists[50]]
//         00516482     MOV        EAX,EDX
//         00516484     SHR        EAX,0x1f
//         00516487     ADD        EDX,EAX
//         00516489     MOV        dword ptr [ESP + buildLists[50]],EDX
//                               LAB_00516490                                                 XREF[1]:     00516474(j)
//                              tplayer.cpp:2886 (15)
//         00516490     MOV        EAX,dword ptr [ESP + buildLists[109]]
//         00516497     TEST       EAX,EAX
//         00516499     JLE        switchD_005162d5::default
//                              tplayer.cpp:2887 (26)
//         0051649f     MOV        EAX,0x55555556
//         005164a4     IMUL       dword ptr [ESP + buildLists[109]]
//         005164ab     MOV        EAX,EDX
//         005164ad     SHR        EAX,0x1f
//         005164b0     ADD        EDX,EAX
//         005164b2     MOV        dword ptr [ESP + buildLists[109]],EDX
//                              tplayer.cpp:2888 (5)
//         005164b9     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_3                                    XREF[2]:     005162d5(j), 00517860(*)
//                              tplayer.cpp:2890 (11)
//         005164be     MOV        EAX,dword ptr [ESP + buildLists[47]]
//         005164c5     TEST       EAX,EAX
//         005164c7     JLE        LAB_005164e3
//                              tplayer.cpp:2891 (26)
//         005164c9     MOV        EAX,0x55555556
//         005164ce     IMUL       dword ptr [ESP + buildLists[47]]
//         005164d5     MOV        EAX,EDX
//         005164d7     SHR        EAX,0x1f
//         005164da     ADD        EDX,EAX
//         005164dc     MOV        dword ptr [ESP + buildLists[47]],EDX
//                               LAB_005164e3                                                 XREF[1]:     005164c7(j)
//                              tplayer.cpp:2892 (11)
//         005164e3     MOV        EAX,dword ptr [ESP + buildLists[54]]
//         005164ea     TEST       EAX,EAX
//         005164ec     JLE        LAB_00516508
//                              tplayer.cpp:2893 (26)
//         005164ee     MOV        EAX,0x55555556
//         005164f3     IMUL       dword ptr [ESP + buildLists[54]]
//         005164fa     MOV        EAX,EDX
//         005164fc     SHR        EAX,0x1f
//         005164ff     ADD        EDX,EAX
//         00516501     MOV        dword ptr [ESP + buildLists[54]],EDX
//                               LAB_00516508                                                 XREF[1]:     005164ec(j)
//                              tplayer.cpp:2894 (8)
//         00516508     MOV        EAX,dword ptr [ESP + buildLists[18]]
//         0051650c     TEST       EAX,EAX
//         0051650e     JLE        LAB_00516524
//                              tplayer.cpp:2895 (20)
//         00516510     MOV        EAX,0x55555556
//         00516515     IMUL       dword ptr [ESP + buildLists[18]]
//         00516519     MOV        EAX,EDX
//         0051651b     SHR        EAX,0x1f
//         0051651e     ADD        EDX,EAX
//         00516520     MOV        dword ptr [ESP + buildLists[18]],EDX
//                               LAB_00516524                                                 XREF[1]:     0051650e(j)
//                              tplayer.cpp:2896 (4)
//         00516524     TEST       this,this
//         00516526     JLE        LAB_00516538
//                              tplayer.cpp:2897 (16)
//         00516528     MOV        EAX,0x55555556
//         0051652d     IMUL       this
//         0051652f     MOV        this,EDX
//         00516531     SHR        this,0x1f
//         00516534     ADD        EDX,this
//         00516536     MOV        this,EDX
//                               LAB_00516538                                                 XREF[1]:     00516526(j)
//                              tplayer.cpp:2898 (11)
//         00516538     MOV        EAX,dword ptr [ESP + buildLists[100]]
//         0051653f     TEST       EAX,EAX
//         00516541     JLE        LAB_0051655d
//                              tplayer.cpp:2899 (26)
//         00516543     MOV        EAX,0x55555556
//         00516548     IMUL       dword ptr [ESP + buildLists[100]]
//         0051654f     MOV        EAX,EDX
//         00516551     SHR        EAX,0x1f
//         00516554     ADD        EDX,EAX
//         00516556     MOV        dword ptr [ESP + buildLists[100]],EDX
//                               LAB_0051655d                                                 XREF[1]:     00516541(j)
//                              tplayer.cpp:2900 (11)
//         0051655d     MOV        EAX,dword ptr [ESP + buildLists[103]]
//         00516564     TEST       EAX,EAX
//         00516566     JLE        LAB_00516582
//                              tplayer.cpp:2901 (26)
//         00516568     MOV        EAX,0x55555556
//         0051656d     IMUL       dword ptr [ESP + buildLists[103]]
//         00516574     MOV        EAX,EDX
//         00516576     SHR        EAX,0x1f
//         00516579     ADD        EDX,EAX
//         0051657b     MOV        dword ptr [ESP + buildLists[103]],EDX
//                               LAB_00516582                                                 XREF[1]:     00516566(j)
//                              tplayer.cpp:2902 (11)
//         00516582     MOV        EAX,dword ptr [ESP + buildLists[110]]
//         00516589     TEST       EAX,EAX
//         0051658b     JLE        LAB_005165a7
//                              tplayer.cpp:2903 (26)
//         0051658d     MOV        EAX,0x55555556
//         00516592     IMUL       dword ptr [ESP + buildLists[110]]
//         00516599     MOV        EAX,EDX
//         0051659b     SHR        EAX,0x1f
//         0051659e     ADD        EDX,EAX
//         005165a0     MOV        dword ptr [ESP + buildLists[110]],EDX
//                               LAB_005165a7                                                 XREF[1]:     0051658b(j)
//                              tplayer.cpp:2904 (8)
//         005165a7     TEST       this,this
//         005165a9     JLE        switchD_005162d5::default
//                              tplayer.cpp:2905 (16)
//         005165af     MOV        EAX,0x55555556
//         005165b4     IMUL       this
//         005165b6     MOV        this,EDX
//         005165b8     SHR        this,0x1f
//         005165bb     ADD        EDX,this
//         005165bd     MOV        this,EDX
//                              tplayer.cpp:2906 (5)
//         005165bf     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_4                                    XREF[2]:     005162d5(j), 00517864(*)
//                              tplayer.cpp:2908 (8)
//         005165c4     MOV        EAX,dword ptr [ESP + buildLists[4]]
//         005165c8     TEST       EAX,EAX
//         005165ca     JLE        LAB_005165e0
//                              tplayer.cpp:2909 (20)
//         005165cc     MOV        EAX,0x55555556
//         005165d1     IMUL       dword ptr [ESP + buildLists[4]]
//         005165d5     MOV        EAX,EDX
//         005165d7     SHR        EAX,0x1f
//         005165da     ADD        EDX,EAX
//         005165dc     MOV        dword ptr [ESP + buildLists[4]],EDX
//                               LAB_005165e0                                                 XREF[1]:     005165ca(j)
//                              tplayer.cpp:2910 (8)
//         005165e0     MOV        EAX,dword ptr [ESP + buildLists[5]]
//         005165e4     TEST       EAX,EAX
//         005165e6     JLE        LAB_005165fc
//                              tplayer.cpp:2911 (20)
//         005165e8     MOV        EAX,0x55555556
//         005165ed     IMUL       dword ptr [ESP + buildLists[5]]
//         005165f1     MOV        EAX,EDX
//         005165f3     SHR        EAX,0x1f
//         005165f6     ADD        EDX,EAX
//         005165f8     MOV        dword ptr [ESP + buildLists[5]],EDX
//                               LAB_005165fc                                                 XREF[1]:     005165e6(j)
//                              tplayer.cpp:2912 (8)
//         005165fc     MOV        EAX,dword ptr [ESP + buildLists[6]]
//         00516600     TEST       EAX,EAX
//         00516602     JLE        LAB_00516618
//                              tplayer.cpp:2913 (20)
//         00516604     MOV        EAX,0x55555556
//         00516609     IMUL       dword ptr [ESP + buildLists[6]]
//         0051660d     MOV        EAX,EDX
//         0051660f     SHR        EAX,0x1f
//         00516612     ADD        EDX,EAX
//         00516614     MOV        dword ptr [ESP + buildLists[6]],EDX
//                               LAB_00516618                                                 XREF[1]:     00516602(j)
//                              tplayer.cpp:2914 (8)
//         00516618     MOV        EAX,dword ptr [ESP + buildLists[10]]
//         0051661c     TEST       EAX,EAX
//         0051661e     JLE        LAB_00516634
//                              tplayer.cpp:2915 (20)
//         00516620     MOV        EAX,0x55555556
//         00516625     IMUL       dword ptr [ESP + buildLists[10]]
//         00516629     MOV        EAX,EDX
//         0051662b     SHR        EAX,0x1f
//         0051662e     ADD        EDX,EAX
//         00516630     MOV        dword ptr [ESP + buildLists[10]],EDX
//                               LAB_00516634                                                 XREF[1]:     0051661e(j)
//                              tplayer.cpp:2916 (8)
//         00516634     MOV        EAX,dword ptr [ESP + buildLists[11]]
//         00516638     TEST       EAX,EAX
//         0051663a     JLE        LAB_00516650
//                              tplayer.cpp:2917 (20)
//         0051663c     MOV        EAX,0x55555556
//         00516641     IMUL       dword ptr [ESP + buildLists[11]]
//         00516645     MOV        EAX,EDX
//         00516647     SHR        EAX,0x1f
//         0051664a     ADD        EDX,EAX
//         0051664c     MOV        dword ptr [ESP + buildLists[11]],EDX
//                               LAB_00516650                                                 XREF[1]:     0051663a(j)
//                              tplayer.cpp:2918 (8)
//         00516650     MOV        EAX,dword ptr [ESP + buildLists[12]]
//         00516654     TEST       EAX,EAX
//         00516656     JLE        LAB_0051666c
//                              tplayer.cpp:2919 (20)
//         00516658     MOV        EAX,0x55555556
//         0051665d     IMUL       dword ptr [ESP + buildLists[12]]
//         00516661     MOV        EAX,EDX
//         00516663     SHR        EAX,0x1f
//         00516666     ADD        EDX,EAX
//         00516668     MOV        dword ptr [ESP + buildLists[12]],EDX
//                               LAB_0051666c                                                 XREF[1]:     00516656(j)
//                              tplayer.cpp:2920 (8)
//         0051666c     MOV        EAX,dword ptr [ESP + buildLists[13]]
//         00516670     TEST       EAX,EAX
//         00516672     JLE        LAB_00516688
//                              tplayer.cpp:2921 (20)
//         00516674     MOV        EAX,0x55555556
//         00516679     IMUL       dword ptr [ESP + buildLists[13]]
//         0051667d     MOV        EAX,EDX
//         0051667f     SHR        EAX,0x1f
//         00516682     ADD        EDX,EAX
//         00516684     MOV        dword ptr [ESP + buildLists[13]],EDX
//                               LAB_00516688                                                 XREF[1]:     00516672(j)
//                              tplayer.cpp:2922 (11)
//         00516688     MOV        EAX,dword ptr [ESP + buildLists[43]]
//         0051668f     TEST       EAX,EAX
//         00516691     JLE        LAB_005166ad
//                              tplayer.cpp:2923 (26)
//         00516693     MOV        EAX,0x55555556
//         00516698     IMUL       dword ptr [ESP + buildLists[43]]
//         0051669f     MOV        EAX,EDX
//         005166a1     SHR        EAX,0x1f
//         005166a4     ADD        EDX,EAX
//         005166a6     MOV        dword ptr [ESP + buildLists[43]],EDX
//                               LAB_005166ad                                                 XREF[1]:     00516691(j)
//                              tplayer.cpp:2924 (11)
//         005166ad     MOV        EAX,dword ptr [ESP + buildLists[45]]
//         005166b4     TEST       EAX,EAX
//         005166b6     JLE        LAB_005166d2
//                              tplayer.cpp:2925 (26)
//         005166b8     MOV        EAX,0x55555556
//         005166bd     IMUL       dword ptr [ESP + buildLists[45]]
//         005166c4     MOV        EAX,EDX
//         005166c6     SHR        EAX,0x1f
//         005166c9     ADD        EDX,EAX
//         005166cb     MOV        dword ptr [ESP + buildLists[45]],EDX
//                               LAB_005166d2                                                 XREF[1]:     005166b6(j)
//                              tplayer.cpp:2926 (11)
//         005166d2     MOV        EAX,dword ptr [ESP + buildLists[46]]
//         005166d9     TEST       EAX,EAX
//         005166db     JLE        LAB_005166f7
//                              tplayer.cpp:2927 (26)
//         005166dd     MOV        EAX,0x55555556
//         005166e2     IMUL       dword ptr [ESP + buildLists[46]]
//         005166e9     MOV        EAX,EDX
//         005166eb     SHR        EAX,0x1f
//         005166ee     ADD        EDX,EAX
//         005166f0     MOV        dword ptr [ESP + buildLists[46]],EDX
//                               LAB_005166f7                                                 XREF[1]:     005166db(j)
//                              tplayer.cpp:2928 (11)
//         005166f7     MOV        EAX,dword ptr [ESP + buildLists[48]]
//         005166fe     TEST       EAX,EAX
//         00516700     JLE        LAB_0051671c
//                              tplayer.cpp:2929 (26)
//         00516702     MOV        EAX,0x55555556
//         00516707     IMUL       dword ptr [ESP + buildLists[48]]
//         0051670e     MOV        EAX,EDX
//         00516710     SHR        EAX,0x1f
//         00516713     ADD        EDX,EAX
//         00516715     MOV        dword ptr [ESP + buildLists[48]],EDX
//                               LAB_0051671c                                                 XREF[1]:     00516700(j)
//                              tplayer.cpp:2930 (11)
//         0051671c     MOV        EAX,dword ptr [ESP + buildLists[49]]
//         00516723     TEST       EAX,EAX
//         00516725     JLE        LAB_00516741
//                              tplayer.cpp:2931 (26)
//         00516727     MOV        EAX,0x55555556
//         0051672c     IMUL       dword ptr [ESP + buildLists[49]]
//         00516733     MOV        EAX,EDX
//         00516735     SHR        EAX,0x1f
//         00516738     ADD        EDX,EAX
//         0051673a     MOV        dword ptr [ESP + buildLists[49]],EDX
//                               LAB_00516741                                                 XREF[1]:     00516725(j)
//                              tplayer.cpp:2932 (11)
//         00516741     MOV        EAX,dword ptr [ESP + buildLists[57]]
//         00516748     TEST       EAX,EAX
//         0051674a     JLE        LAB_00516766
//                              tplayer.cpp:2933 (26)
//         0051674c     MOV        EAX,0x55555556
//         00516751     IMUL       dword ptr [ESP + buildLists[57]]
//         00516758     MOV        EAX,EDX
//         0051675a     SHR        EAX,0x1f
//         0051675d     ADD        EDX,EAX
//         0051675f     MOV        dword ptr [ESP + buildLists[57]],EDX
//                               LAB_00516766                                                 XREF[1]:     0051674a(j)
//                              tplayer.cpp:2934 (11)
//         00516766     MOV        EAX,dword ptr [ESP + buildLists[75]]
//         0051676d     TEST       EAX,EAX
//         0051676f     JLE        LAB_0051678b
//                              tplayer.cpp:2935 (26)
//         00516771     MOV        EAX,0x55555556
//         00516776     IMUL       dword ptr [ESP + buildLists[75]]
//         0051677d     MOV        EAX,EDX
//         0051677f     SHR        EAX,0x1f
//         00516782     ADD        EDX,EAX
//         00516784     MOV        dword ptr [ESP + buildLists[75]],EDX
//                               LAB_0051678b                                                 XREF[1]:     0051676f(j)
//                              tplayer.cpp:2936 (11)
//         0051678b     MOV        EAX,dword ptr [ESP + buildLists[99]]
//         00516792     TEST       EAX,EAX
//         00516794     JLE        LAB_005167b0
//                              tplayer.cpp:2937 (26)
//         00516796     MOV        EAX,0x55555556
//         0051679b     IMUL       dword ptr [ESP + buildLists[99]]
//         005167a2     MOV        EAX,EDX
//         005167a4     SHR        EAX,0x1f
//         005167a7     ADD        EDX,EAX
//         005167a9     MOV        dword ptr [ESP + buildLists[99]],EDX
//                               LAB_005167b0                                                 XREF[1]:     00516794(j)
//                              tplayer.cpp:2938 (11)
//         005167b0     MOV        EAX,dword ptr [ESP + buildLists[104]]
//         005167b7     TEST       EAX,EAX
//         005167b9     JLE        LAB_005167d5
//                              tplayer.cpp:2939 (26)
//         005167bb     MOV        EAX,0x55555556
//         005167c0     IMUL       dword ptr [ESP + buildLists[104]]
//         005167c7     MOV        EAX,EDX
//         005167c9     SHR        EAX,0x1f
//         005167cc     ADD        EDX,EAX
//         005167ce     MOV        dword ptr [ESP + buildLists[104]],EDX
//                               LAB_005167d5                                                 XREF[1]:     005167b9(j)
//                              tplayer.cpp:2940 (11)
//         005167d5     MOV        EAX,dword ptr [ESP + buildLists[113]]
//         005167dc     TEST       EAX,EAX
//         005167de     JLE        LAB_005167fa
//                              tplayer.cpp:2941 (26)
//         005167e0     MOV        EAX,0x55555556
//         005167e5     IMUL       dword ptr [ESP + buildLists[113]]
//         005167ec     MOV        EAX,EDX
//         005167ee     SHR        EAX,0x1f
//         005167f1     ADD        EDX,EAX
//         005167f3     MOV        dword ptr [ESP + buildLists[113]],EDX
//                               LAB_005167fa                                                 XREF[1]:     005167de(j)
//                              tplayer.cpp:2942 (15)
//         005167fa     MOV        EAX,dword ptr [ESP + buildLists[114]]
//         00516801     TEST       EAX,EAX
//         00516803     JLE        switchD_005162d5::default
//                              tplayer.cpp:2943 (26)
//         00516809     MOV        EAX,0x55555556
//         0051680e     IMUL       dword ptr [ESP + buildLists[114]]
//         00516815     MOV        EAX,EDX
//         00516817     SHR        EAX,0x1f
//         0051681a     ADD        EDX,EAX
//         0051681c     MOV        dword ptr [ESP + buildLists[114]],EDX
//                              tplayer.cpp:2944 (5)
//         00516823     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_5                                    XREF[2]:     005162d5(j), 00517868(*)
//                              tplayer.cpp:2946 (4)
//         00516828     TEST       ESI,ESI
//         0051682a     JLE        LAB_0051683c
//                              tplayer.cpp:2947 (16)
//         0051682c     MOV        EAX,0x55555556
//         00516831     IMUL       ESI
//         00516833     MOV        EAX,EDX
//         00516835     SHR        EAX,0x1f
//         00516838     ADD        EDX,EAX
//         0051683a     MOV        ESI,EDX
//                               LAB_0051683c                                                 XREF[1]:     0051682a(j)
//                              tplayer.cpp:2948 (8)
//         0051683c     MOV        EAX,dword ptr [ESP + buildLists[1]]
//         00516840     TEST       EAX,EAX
//         00516842     JLE        LAB_00516858
//                              tplayer.cpp:2949 (20)
//         00516844     MOV        EAX,0x55555556
//         00516849     IMUL       dword ptr [ESP + buildLists[1]]
//         0051684d     MOV        EAX,EDX
//         0051684f     SHR        EAX,0x1f
//         00516852     ADD        EDX,EAX
//         00516854     MOV        dword ptr [ESP + buildLists[1]],EDX
//                               LAB_00516858                                                 XREF[1]:     00516842(j)
//                              tplayer.cpp:2950 (8)
//         00516858     MOV        EAX,dword ptr [ESP + buildLists[2]]
//         0051685c     TEST       EAX,EAX
//         0051685e     JLE        LAB_00516874
//                              tplayer.cpp:2951 (20)
//         00516860     MOV        EAX,0x55555556
//         00516865     IMUL       dword ptr [ESP + buildLists[2]]
//         00516869     MOV        EAX,EDX
//         0051686b     SHR        EAX,0x1f
//         0051686e     ADD        EDX,EAX
//         00516870     MOV        dword ptr [ESP + buildLists[2]],EDX
//                               LAB_00516874                                                 XREF[1]:     0051685e(j)
//                              tplayer.cpp:2952 (8)
//         00516874     MOV        EAX,dword ptr [ESP + buildLists[3]]
//         00516878     TEST       EAX,EAX
//         0051687a     JLE        LAB_00516890
//                              tplayer.cpp:2953 (20)
//         0051687c     MOV        EAX,0x55555556
//         00516881     IMUL       dword ptr [ESP + buildLists[3]]
//         00516885     MOV        EAX,EDX
//         00516887     SHR        EAX,0x1f
//         0051688a     ADD        EDX,EAX
//         0051688c     MOV        dword ptr [ESP + buildLists[3]],EDX
//                               LAB_00516890                                                 XREF[1]:     0051687a(j)
//                              tplayer.cpp:2954 (4)
//         00516890     TEST       ESI,ESI
//         00516892     JLE        LAB_005168a4
//                              tplayer.cpp:2955 (16)
//         00516894     MOV        EAX,0x55555556
//         00516899     IMUL       ESI
//         0051689b     MOV        EAX,EDX
//         0051689d     SHR        EAX,0x1f
//         005168a0     ADD        EDX,EAX
//         005168a2     MOV        ESI,EDX
//                               LAB_005168a4                                                 XREF[1]:     00516892(j)
//                              tplayer.cpp:2956 (4)
//         005168a4     TEST       EBX,EBX
//         005168a6     JLE        LAB_005168b8
//                              tplayer.cpp:2957 (16)
//         005168a8     MOV        EAX,0x55555556
//         005168ad     IMUL       EBX
//         005168af     MOV        EAX,EDX
//         005168b1     SHR        EAX,0x1f
//         005168b4     ADD        EDX,EAX
//         005168b6     MOV        EBX,EDX
//                               LAB_005168b8                                                 XREF[1]:     005168a6(j)
//                              tplayer.cpp:2958 (4)
//         005168b8     TEST       EDI,EDI
//         005168ba     JLE        LAB_005168cc
//                              tplayer.cpp:2959 (16)
//         005168bc     MOV        EAX,0x55555556
//         005168c1     IMUL       EDI
//         005168c3     MOV        EAX,EDX
//         005168c5     SHR        EAX,0x1f
//         005168c8     ADD        EDX,EAX
//         005168ca     MOV        EDI,EDX
//                               LAB_005168cc                                                 XREF[1]:     005168ba(j)
//                              tplayer.cpp:2960 (11)
//         005168cc     MOV        EAX,dword ptr [ESP + buildLists[73]]
//         005168d3     TEST       EAX,EAX
//         005168d5     JLE        LAB_005168f1
//                              tplayer.cpp:2961 (26)
//         005168d7     MOV        EAX,0x55555556
//         005168dc     IMUL       dword ptr [ESP + buildLists[73]]
//         005168e3     MOV        EAX,EDX
//         005168e5     SHR        EAX,0x1f
//         005168e8     ADD        EDX,EAX
//         005168ea     MOV        dword ptr [ESP + buildLists[73]],EDX
//                               LAB_005168f1                                                 XREF[1]:     005168d5(j)
//                              tplayer.cpp:2962 (11)
//         005168f1     MOV        EAX,dword ptr [ESP + buildLists[74]]
//         005168f8     TEST       EAX,EAX
//         005168fa     JLE        LAB_00516916
//                              tplayer.cpp:2963 (26)
//         005168fc     MOV        EAX,0x55555556
//         00516901     IMUL       dword ptr [ESP + buildLists[74]]
//         00516908     MOV        EAX,EDX
//         0051690a     SHR        EAX,0x1f
//         0051690d     ADD        EDX,EAX
//         0051690f     MOV        dword ptr [ESP + buildLists[74]],EDX
//                               LAB_00516916                                                 XREF[1]:     005168fa(j)
//                              tplayer.cpp:2964 (4)
//         00516916     TEST       EBX,EBX
//         00516918     JLE        LAB_0051692a
//                              tplayer.cpp:2965 (16)
//         0051691a     MOV        EAX,0x55555556
//         0051691f     IMUL       EBX
//         00516921     MOV        EAX,EDX
//         00516923     SHR        EAX,0x1f
//         00516926     ADD        EDX,EAX
//         00516928     MOV        EBX,EDX
//                               LAB_0051692a                                                 XREF[1]:     00516918(j)
//                              tplayer.cpp:2966 (4)
//         0051692a     TEST       EDI,EDI
//         0051692c     JLE        LAB_0051693e
//                              tplayer.cpp:2967 (16)
//         0051692e     MOV        EAX,0x55555556
//         00516933     IMUL       EDI
//         00516935     MOV        EAX,EDX
//         00516937     SHR        EAX,0x1f
//         0051693a     ADD        EDX,EAX
//         0051693c     MOV        EDI,EDX
//                               LAB_0051693e                                                 XREF[1]:     0051692c(j)
//                              tplayer.cpp:2968 (11)
//         0051693e     MOV        EAX,dword ptr [ESP + buildLists[81]]
//         00516945     TEST       EAX,EAX
//         00516947     JLE        LAB_00516963
//                              tplayer.cpp:2969 (26)
//         00516949     MOV        EAX,0x55555556
//         0051694e     IMUL       dword ptr [ESP + buildLists[81]]
//         00516955     MOV        EAX,EDX
//         00516957     SHR        EAX,0x1f
//         0051695a     ADD        EDX,EAX
//         0051695c     MOV        dword ptr [ESP + buildLists[81]],EDX
//                               LAB_00516963                                                 XREF[1]:     00516947(j)
//                              tplayer.cpp:2970 (11)
//         00516963     MOV        EAX,dword ptr [ESP + buildLists[82]]
//         0051696a     TEST       EAX,EAX
//         0051696c     JLE        LAB_00516988
//                              tplayer.cpp:2971 (26)
//         0051696e     MOV        EAX,0x55555556
//         00516973     IMUL       dword ptr [ESP + buildLists[82]]
//         0051697a     MOV        EAX,EDX
//         0051697c     SHR        EAX,0x1f
//         0051697f     ADD        EDX,EAX
//         00516981     MOV        dword ptr [ESP + buildLists[82]],EDX
//                               LAB_00516988                                                 XREF[1]:     0051696c(j)
//                              tplayer.cpp:2972 (11)
//         00516988     MOV        EAX,dword ptr [ESP + buildLists[83]]
//         0051698f     TEST       EAX,EAX
//         00516991     JLE        LAB_005169ad
//                              tplayer.cpp:2973 (26)
//         00516993     MOV        EAX,0x55555556
//         00516998     IMUL       dword ptr [ESP + buildLists[83]]
//         0051699f     MOV        EAX,EDX
//         005169a1     SHR        EAX,0x1f
//         005169a4     ADD        EDX,EAX
//         005169a6     MOV        dword ptr [ESP + buildLists[83]],EDX
//                               LAB_005169ad                                                 XREF[1]:     00516991(j)
//                              tplayer.cpp:2974 (15)
//         005169ad     MOV        EAX,dword ptr [ESP + buildLists[108]]
//         005169b4     TEST       EAX,EAX
//         005169b6     JLE        switchD_005162d5::default
//                              tplayer.cpp:2975 (26)
//         005169bc     MOV        EAX,0x55555556
//         005169c1     IMUL       dword ptr [ESP + buildLists[108]]
//         005169c8     MOV        EAX,EDX
//         005169ca     SHR        EAX,0x1f
//         005169cd     ADD        EDX,EAX
//         005169cf     MOV        dword ptr [ESP + buildLists[108]],EDX
//                              tplayer.cpp:2976 (5)
//         005169d6     JMP        switchD_005162d5::default
//                               switchD_005162d5::caseD_6                                    XREF[2]:     005162d5(j), 0051786c(*)
//                              tplayer.cpp:2978 (11)
//         005169db     MOV        EAX,dword ptr [ESP + buildLists[41]]
//         005169e2     TEST       EAX,EAX
//         005169e4     JLE        LAB_00516a00
//                              tplayer.cpp:2979 (26)
//         005169e6     MOV        EAX,0x55555556
//         005169eb     IMUL       dword ptr [ESP + buildLists[41]]
//         005169f2     MOV        EAX,EDX
//         005169f4     SHR        EAX,0x1f
//         005169f7     ADD        EDX,EAX
//         005169f9     MOV        dword ptr [ESP + buildLists[41]],EDX
//                               LAB_00516a00                                                 XREF[1]:     005169e4(j)
//                              tplayer.cpp:2980 (11)
//         00516a00     MOV        EAX,dword ptr [ESP + buildLists[58]]
//         00516a07     TEST       EAX,EAX
//         00516a09     JLE        LAB_00516a25
//                              tplayer.cpp:2981 (26)
//         00516a0b     MOV        EAX,0x55555556
//         00516a10     IMUL       dword ptr [ESP + buildLists[58]]
//         00516a17     MOV        EAX,EDX
//         00516a19     SHR        EAX,0x1f
//         00516a1c     ADD        EDX,EAX
//         00516a1e     MOV        dword ptr [ESP + buildLists[58]],EDX
//                               LAB_00516a25                                                 XREF[1]:     00516a09(j)
//                              tplayer.cpp:2982 (11)
//         00516a25     MOV        EAX,dword ptr [ESP + buildLists[115]]
//         00516a2c     TEST       EAX,EAX
//         00516a2e     JLE        LAB_00516a4a
//                              tplayer.cpp:2983 (26)
//         00516a30     MOV        EAX,0x55555556
//         00516a35     IMUL       dword ptr [ESP + buildLists[115]]
//         00516a3c     MOV        EAX,EDX
//         00516a3e     SHR        EAX,0x1f
//         00516a41     ADD        EDX,EAX
//         00516a43     MOV        dword ptr [ESP + buildLists[115]],EDX
//                               LAB_00516a4a                                                 XREF[1]:     00516a2e(j)
//                              tplayer.cpp:2984 (11)
//         00516a4a     MOV        EAX,dword ptr [ESP + buildLists[85]]
//         00516a51     TEST       EAX,EAX
//         00516a53     JLE        switchD_005162d5::default
//                              tplayer.cpp:2985 (69)
//         00516a55     MOV        EAX,0x55555556
//         00516a5a     IMUL       dword ptr [ESP + buildLists[85]]
//         00516a61     MOV        EAX,EDX
//         00516a63     SHR        EAX,0x1f
//         00516a66     ADD        EDX,EAX
//         00516a68     MOV        dword ptr [ESP + buildLists[85]],EDX
//                               switchD_005162d5::default                                    XREF[14]:    005162cf(j), 0051631a(j),
//                                                                                                         00516334(j), 0051642a(j),
//                                                                                                         0051644a(j), 00516499(j),
//                                                                                                         005164b9(j), 005165a9(j),
//                                                                                                         005165bf(j), 00516803(j),
//                                                                                                         00516823(j), 005169b6(j),
//                                                                                                         005169d6(j), 00516a53(j)
//         00516a6f     MOV        EAX,dword ptr [ESP + difficultyLevel]
//         00516a73     INC        EAX
//         00516a74     CMP        EAX,0x7
//         00516a77     MOV        dword ptr [ESP + difficultyLevel],EAX
//         00516a7b     JL         LAB_005162c8
//         00516a81     MOV        dword ptr [ESP + buildLists[19]],this
//         00516a85     MOV        dword ptr [ESP + buildLists[52]],EDI
//         00516a8c     MOV        dword ptr [ESP + buildLists[51]],EBX
//         00516a93     MOV        dword ptr [ESP + buildLists[42]],ESI
//                              tplayer.cpp:3937 (14)
//         00516a9a     LEA        EAX=>buildLists[1],[ESP + 0x18]
//         00516a9e     MOV        this,0x7d
//                               LAB_00516aa3                                                 XREF[1]:     00516ab2(j)
//         00516aa3     CMP        dword ptr [EAX]=>buildLists[1],0x0
//         00516aa6     JGE        LAB_00516aae
//                              tplayer.cpp:3128 (6)
//         00516aa8     MOV        dword ptr [EAX]=>buildLists[1],0x0
//                               LAB_00516aae                                                 XREF[1]:     00516aa6(j)
//                              tplayer.cpp:3126 (6)
//         00516aae     ADD        EAX,0x4
//         00516ab1     DEC        this
//         00516ab2     JNZ        LAB_00516aa3
//                              tplayer.cpp:3132 (2)
//         00516ab4     XOR        ESI,ESI
//                              tplayer.cpp:3937 (67)
//         00516ab6     LEA        EAX=>buildLists[1],[ESP + 0x18]
//                              language.dll match for 0x7d: "Arial"
//         00516aba     MOV        this,0x7d
//                               LAB_00516abf                                                 XREF[1]:     00516ac7(j)
//         00516abf     MOV        EBX,dword ptr [EAX]=>buildLists[1]
//         00516ac1     ADD        EAX,0x4
//         00516ac4     ADD        ESI,EBX
//         00516ac6     DEC        this
//         00516ac7     JNZ        LAB_00516abf
//         00516ac9     PUSH       0xc41
//         00516ace     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516ad3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516ad8     CDQ
//         00516ad9     IDIV       ESI
//         00516adb     ADD        ESP,0x8
//         00516ade     XOR        EBX,EBX
//         00516ae0     XOR        ESI,ESI
//         00516ae2     XOR        EAX,EAX
//         00516ae4     LEA        this=>buildLists[1],[ESP + 0x18]
//                               LAB_00516ae8                                                 XREF[1]:     00516af5(j)
//         00516ae8     ADD        ESI,dword ptr [this->_padding_]=>buildLists[1]
//         00516aea     CMP        ESI,EDX
//         00516aec     JG         LAB_00516af9
//         00516aee     INC        EAX
//         00516aef     ADD        this,0x4
//         00516af2     CMP        EAX,0x7d
//         00516af5     JL         LAB_00516ae8
//         00516af7     JMP        LAB_00516afb
//                               LAB_00516af9                                                 XREF[1]:     00516aec(j)
//                              tplayer.cpp:3145 (2)
//         00516af9     MOV        EBX,EAX
//                               LAB_00516afb                                                 XREF[1]:     00516af7(j)
//                              tplayer.cpp:3152 (31)
//         00516afb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00516b01     MOV        ESI,dword ptr [ESP + param_1]
//         00516b08     PUSH       0x100
//         00516b0d     LEA        EAX,[EBX + 0x26930]
//         00516b13     MOV        EDX,dword ptr [this->_padding_]
//         00516b15     PUSH       ESI
//         00516b16     PUSH       EAX
//         00516b17     CALL       dword ptr [EDX + 0x20]
//                              tplayer.cpp:3153 (16)
//         00516b1a     CMP        EBX,0x7c
//         00516b1d     JA         switchD_00516b23::caseD_3
//                               switchD_00516b23::switchD
//         00516b23     JMP        dword ptr [EBX*0x4 + ->switchD_00516b23::caseD   = 00516bba
//                               switchD_00516b23::caseD_e                                    XREF[4]:     00516b23(j), 005178a4(*),
//                               switchD_00516b23::caseD_f                                                 005178a8(*), 005178ac(*)
//                               switchD_00516b23::caseD_d
//                              tplayer.cpp:3238 (21)
//         00516b2a     MOV        this,dword ptr [EBP + 0x238]
//         00516b30     PUSH       0x4
//         00516b32     PUSH       offset DAT_fffffff8
//         00516b34     ADD        this,0x10e74
//         00516b3a     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3239 (21)
//         00516b3f     MOV        this,dword ptr [EBP + 0x238]
//         00516b45     PUSH       0xa
//         00516b47     PUSH       offset DAT_fffffff8
//         00516b49     ADD        this,0x10e74
//         00516b4f     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3240 (6)
//         00516b54     MOV        this,dword ptr [DAT_00886c34]
//                              tplayer.cpp:3241 (18)
//         00516b5a     MOV        EAX,[DAT_00886c48]
//         00516b5f     INC        this
//         00516b60     INC        EAX
//         00516b61     MOV        dword ptr [DAT_00886c34],this
//         00516b67     MOV        [DAT_00886c48],EAX
//                              tplayer.cpp:3242 (2)
//         00516b6c     JMP        LAB_00516be6
//                               switchD_00516b23::caseD_14                                   XREF[4]:     00516b23(j), 005178bc(*),
//                               switchD_00516b23::caseD_15                                                005178c0(*), 005178c4(*)
//                               switchD_00516b23::caseD_13
//                              tplayer.cpp:3270 (6)
//         00516b6e     INC        dword ptr [computerPlayerSetup]                  = 00000000
//                              tplayer.cpp:3349 (2)
//         00516b74     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_3d                                   XREF[44]:    00517960(*), 00517964(*),
//                               switchD_00516b23::caseD_3e                                                00517968(*), 0051796c(*),
//                               switchD_00516b23::caseD_3f                                                00517970(*), 00517974(*),
//                               switchD_00516b23::caseD_40                                                00517978(*), 0051797c(*),
//                               switchD_00516b23::caseD_41                                                00517980(*), 00517984(*),
//                               switchD_00516b23::caseD_42                                                00517988(*), 0051798c(*),
//                               switchD_00516b23::caseD_43                                                0051799c(*), 005179a0(*),
//                               switchD_00516b23::caseD_44                                                005179a4(*), 005179a8(*),
//                               switchD_00516b23::caseD_45                                                005179ac(*), 005179bc(*),
//                               switchD_00516b23::caseD_46                                                005179c4(*), 005179c8(*), [more]
//                               switchD_00516b23::caseD_47
//                               switchD_00516b23::caseD_4b
//                               switchD_00516b23::caseD_4c
//                               switchD_00516b23::caseD_4d
//                               switchD_00516b23::caseD_4e
//                               switchD_00516b23::caseD_4f
//                               switchD_00516b23::caseD_53
//                               switchD_00516b23::caseD_55
//                               switchD_00516b23::caseD_56
//                               switchD_00516b23::caseD_57
//                               switchD_00516b23::caseD_58
//                               switchD_00516b23::caseD_59
//                               switchD_00516b23::caseD_5a
//                               switchD_00516b23::caseD_5b
//                               switchD_00516b23::caseD_5c
//                               switchD_00516b23::caseD_5d
//                               switchD_00516b23::caseD_5e
//                               switchD_00516b23::caseD_5f
//                               switchD_00516b23::caseD_60
//                               switchD_00516b23::caseD_61
//                               switchD_00516b23::caseD_64
//                               switchD_00516b23::caseD_65
//                               switchD_00516b23::caseD_69
//                               switchD_00516b23::caseD_6a
//                               switchD_00516b23::caseD_6e
//                               switchD_00516b23::caseD_6f
//                               switchD_00516b23::caseD_73
//                               switchD_00516b23::caseD_74
//                               switchD_00516b23::caseD_79
//                               switchD_00516b23::caseD_7a
//                               switchD_00516b23::caseD_7b
//                               switchD_00516b23::caseD_7c
//                               switchD_00516b23::caseD_3c
//                              tplayer.cpp:3489 (6)
//         00516b76     INC        dword ptr [DAT_00886c48]
//                              tplayer.cpp:3490 (2)
//         00516b7c     JMP        LAB_00516be6
//                               switchD_00516b23::caseD_49                                   XREF[3]:     00516b23(j), 00517990(*),
//                               switchD_00516b23::caseD_48                                                00517994(*)
//                              tplayer.cpp:3496 (6)
//         00516b7e     MOV        this,dword ptr [DAT_00886c44]
//                              tplayer.cpp:3497 (18)
//         00516b84     MOV        EAX,[DAT_00886c2c]
//         00516b89     INC        this
//         00516b8a     INC        EAX
//         00516b8b     MOV        dword ptr [DAT_00886c44],this
//         00516b91     MOV        [DAT_00886c2c],EAX
//                              tplayer.cpp:3498 (2)
//         00516b96     JMP        LAB_00516be6
//                               switchD_00516b23::caseD_4a                                   XREF[2]:     00516b23(j), 00517998(*)
//                              tplayer.cpp:3500 (6)
//         00516b98     MOV        this,dword ptr [DAT_00886c44]
//                              tplayer.cpp:3501 (18)
//         00516b9e     MOV        EAX,[DAT_00886c28]
//         00516ba3     INC        this
//         00516ba4     INC        EAX
//         00516ba5     MOV        dword ptr [DAT_00886c44],this
//         00516bab     MOV        [DAT_00886c28],EAX
//                              tplayer.cpp:3502 (2)
//         00516bb0     JMP        LAB_00516be6
//                               switchD_00516b23::caseD_7                                    XREF[10]:    00516b23(j), 00517888(*),
//                               switchD_00516b23::caseD_8                                                 0051788c(*), 00517890(*),
//                               switchD_00516b23::caseD_2b                                                0051791c(*), 00517948(*),
//                               switchD_00516b23::caseD_36                                                0051794c(*), 00517958(*),
//                               switchD_00516b23::caseD_37                                                0051795c(*), 00517a10(*)
//                               switchD_00516b23::caseD_3a
//                               switchD_00516b23::caseD_3b
//                               switchD_00516b23::caseD_68
//                               switchD_00516b23::caseD_6
//                              tplayer.cpp:3536 (6)
//         00516bb2     INC        dword ptr [DAT_00886c1c]
//                              tplayer.cpp:3538 (2)
//         00516bb8     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_1                                    XREF[11]:    00516b23(j), 00517870(*),
//                               switchD_00516b23::caseD_2                                                 00517874(*), 00517878(*),
//                               switchD_00516b23::caseD_29                                                00517914(*), 00517938(*),
//                               switchD_00516b23::caseD_32                                                0051793c(*), 005179b0(*),
//                               switchD_00516b23::caseD_33                                                005179b4(*), 005179b8(*),
//                               switchD_00516b23::caseD_50                                                00517a1c(*)
//                               switchD_00516b23::caseD_51
//                               switchD_00516b23::caseD_52
//                               switchD_00516b23::caseD_6b
//                               switchD_00516b23::caseD_0
//                              tplayer.cpp:3540 (6)
//         00516bba     INC        dword ptr [DAT_00886c2c]
//                              tplayer.cpp:3542 (2)
//         00516bc0     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_31                                   XREF[4]:     00516b23(j), 005178b0(*),
//                               switchD_00516b23::caseD_6c                                                00517934(*), 00517a20(*)
//                               switchD_00516b23::caseD_10
//                              tplayer.cpp:3544 (6)
//         00516bc2     INC        dword ptr [DAT_00886c20]                         = align(8)
//                              tplayer.cpp:3546 (2)
//         00516bc8     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_12                                   XREF[9]:     00516b23(j), 005178b4(*),
//                               switchD_00516b23::caseD_2e                                                005178b8(*), 00517928(*),
//                               switchD_00516b23::caseD_34                                                00517940(*), 00517944(*),
//                               switchD_00516b23::caseD_35                                                005179fc(*), 00517a08(*),
//                               switchD_00516b23::caseD_63                                                00517a24(*)
//                               switchD_00516b23::caseD_66
//                               switchD_00516b23::caseD_6d
//                               switchD_00516b23::caseD_11
//                              tplayer.cpp:3548 (6)
//         00516bca     INC        dword ptr [null_00886c24]                        = align(4)
//                              tplayer.cpp:3550 (2)
//         00516bd0     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_39                                   XREF[5]:     00516b23(j), 00517910(*),
//                               switchD_00516b23::caseD_54                                                00517954(*), 005179c0(*),
//                               switchD_00516b23::caseD_72                                                00517a38(*)
//                               switchD_00516b23::caseD_28
//                              tplayer.cpp:3560 (6)
//         00516bd2     INC        dword ptr [DAT_00886c30]                         = align(4)
//                              tplayer.cpp:3562 (2)
//         00516bd8     JMP        switchD_00516b23::caseD_16
//                               switchD_00516b23::caseD_4                                    XREF[19]:    00516b1d(j), 00516b23(j),
//                               switchD_00516b23::caseD_5                                                 0051787c(*), 00517880(*),
//                               switchD_00516b23::caseD_9                                                 00517884(*), 00517894(*),
//                               switchD_00516b23::caseD_a                                                 00517898(*), 0051789c(*),
//                               switchD_00516b23::caseD_b                                                 005178a0(*), 00517918(*),
//                               switchD_00516b23::caseD_c                                                 00517920(*), 00517924(*),
//                               switchD_00516b23::caseD_2a                                                0051792c(*), 00517930(*),
//                               switchD_00516b23::caseD_2c                                                00517950(*), 005179f8(*),
//                               switchD_00516b23::caseD_2d                                                00517a0c(*), 00517a30(*),
//                               switchD_00516b23::caseD_2f                                                00517a34(*)
//                               switchD_00516b23::caseD_30
//                               switchD_00516b23::caseD_38
//                               switchD_00516b23::caseD_62
//                               switchD_00516b23::caseD_67
//                               switchD_00516b23::caseD_70
//                               switchD_00516b23::caseD_71
//                               switchD_00516b23::caseD_3
//                              tplayer.cpp:3577 (6)
//         00516bda     INC        dword ptr [DAT_00886c28]
//                               switchD_00516b23::caseD_17                                   XREF[29]:    005178c8(*), 005178cc(*),
//                               switchD_00516b23::caseD_18                                                005178d0(*), 005178d4(*),
//                               switchD_00516b23::caseD_19                                                005178d8(*), 005178dc(*),
//                               switchD_00516b23::caseD_1a                                                005178e0(*), 005178e4(*),
//                               switchD_00516b23::caseD_1b                                                005178e8(*), 005178ec(*),
//                               switchD_00516b23::caseD_1c                                                005178f0(*), 005178f4(*),
//                               switchD_00516b23::caseD_1d                                                005178f8(*), 005178fc(*),
//                               switchD_00516b23::caseD_1e                                                00517900(*), 00517904(*),
//                               switchD_00516b23::caseD_1f                                                00517908(*), 0051790c(*),
//                               switchD_00516b23::caseD_20                                                00517a44(*), 00517a48(*), [more]
//                               switchD_00516b23::caseD_21
//                               switchD_00516b23::caseD_22
//                               switchD_00516b23::caseD_23
//                               switchD_00516b23::caseD_24
//                               switchD_00516b23::caseD_25
//                               switchD_00516b23::caseD_26
//                               switchD_00516b23::caseD_27
//                               switchD_00516b23::caseD_75
//                               switchD_00516b23::caseD_76
//                               switchD_00516b23::caseD_77
//                               switchD_00516b23::caseD_78
//                               switchD_00516b23::caseD_16
//                              tplayer.cpp:3578 (6)
//         00516be0     INC        dword ptr [DAT_00886c44]
//                               LAB_00516be6                                                 XREF[4]:     00516b6c(j), 00516b7c(j),
//                                                                                                         00516b96(j), 00516bb0(j)
//                              tplayer.cpp:3583 (38)
//         00516be6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00516bec     LEA        EAX,[ESP + 0x210]
//         00516bf3     PUSH       0x100
//         00516bf8     PUSH       EAX=>DAT_fffffff8
//         00516bf9     MOV        EDX,dword ptr [this->_padding_]
//         00516bfb     XOR        EAX,EAX
//         00516bfd     MOV        AL,byte ptr [EBP + 0x105]
//         00516c03     ADD        EAX,0x27f6
//         00516c08     PUSH       EAX=>DAT_fffffff4
//         00516c09     CALL       dword ptr [EDX + 0x20]
//                              tplayer.cpp:3584 (35)
//         00516c0c     MOV        EAX,dword ptr [EBP + 0x238]
//         00516c12     XOR        this,this
//         00516c14     MOV        this,byte ptr [EBP + 0x105]
//         00516c1a     LEA        EDX,[ESP + 0x210]
//         00516c21     DEC        this
//         00516c22     PUSH       this
//         00516c23     PUSH       EDX=>DAT_fffffff8
//         00516c24     PUSH       s_I_am_the_%s_civ_(culture_#%d):                 = "I am the %s civ (culture #%d):"
//         00516c29     PUSH       EAX=>DAT_fffffff0
//         00516c2a     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:3585 (21)
//         00516c2f     MOV        this,dword ptr [EBP + 0x238]
//         00516c35     ADD        ESP,0x10
//         00516c38     PUSH       ESI
//         00516c39     PUSH       s_Selected_a_best_build_list_of_'%               = "Selected a best build list of '%s'."
//         00516c3e     PUSH       this=>DAT_fffffff4
//         00516c3f     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:3588 (19)
//         00516c44     MOV        EDI,s_RandomGameSpecialized                      = 52h
//         00516c49     OR         this,0xffffffff
//         00516c4c     XOR        EAX,EAX
//         00516c4e     ADD        ESP,0xc
//         00516c51     SCASB.RE   ES:EDI=>s_RandomGameSpecialized                  = 52h
//                                                                                  = 61h
//         00516c53     NOT        this
//         00516c55     SUB        EDI,this
//                              tplayer.cpp:3589 (40)
//         00516c57     PUSH       s_Setting_AI_Personality:                        = "Setting AI Personality:"
//         00516c5c     MOV        EDX,this
//         00516c5e     MOV        ESI,EDI
//         00516c60     MOV        EDI,dword ptr [ESP + 0x31c]
//         00516c67     SHR        this,0x2
//         00516c6a     MOVSD.REP  ES:EDI,ESI
//         00516c6c     MOV        this,EDX
//         00516c6e     AND        this,0x3
//         00516c71     MOVSB.REP  ES:EDI,ESI
//         00516c73     MOV        EAX,dword ptr [EBP + 0x238]
//         00516c79     PUSH       EAX=>DAT_fffffff8
//         00516c7a     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:3590 (24)
//         00516c7f     MOV        EAX,dword ptr [ESP + 0x328]
//         00516c86     ADD        ESP,0x8
//         00516c89     CMP        EAX,0x5
//         00516c8c     JA         LAB_00516cc1
//         00516c8e     MOV        ESI,EAX
//                               switchD_00516c90::switchD
//         00516c90     JMP        dword ptr [ESI*0x4 + switchD_00516c90::switchd   = 00516c97
//                               switchD_00516c90::caseD_1                                    XREF[3]:     00516c90(j), 00517a64(*),
//                               switchD_00516c90::caseD_0                                                 00517a68(*)
//                              tplayer.cpp:3593 (21)
//         00516c97     MOV        this,dword ptr [EBP + 0x238]
//         00516c9d     PUSH       0x5
//         00516c9f     PUSH       offset DAT_fffffff8
//         00516ca1     ADD        this,0x10e74
//         00516ca7     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3594 (21)
//         00516cac     MOV        this,dword ptr [EBP + 0x238]
//         00516cb2     PUSH       0x5
//         00516cb4     PUSH       offset DAT_fffffff8
//         00516cb6     ADD        this,0x10e74
//         00516cbc     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_00516cc1                                                 XREF[1]:     00516c8c(j)
//                              tplayer.cpp:3595 (7)
//         00516cc1     MOV        EDI,dword ptr [ESP + 0x31c]
//                               switchD_00516c90::default                                    XREF[2]:     0051776f(j), 005177e2(j)
//                              tplayer.cpp:3638 (15)
//         00516cc8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00516cce     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00516cd3     CMP        AL,0x1
//         00516cd5     JNZ        LAB_00516cec
//                              tplayer.cpp:3639 (21)
//         00516cd7     MOV        this,dword ptr [EBP + 0x238]
//         00516cdd     PUSH       0xa
//         00516cdf     PUSH       offset DAT_fffffff8
//         00516ce1     ADD        this,0x10e74
//         00516ce7     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_00516cec                                                 XREF[1]:     00516cd5(j)
//                              tplayer.cpp:3642 (38)
//         00516cec     PUSH       0xe3a
//         00516cf1     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516cf6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516cfb     CDQ
//         00516cfc     MOV        this,0xc
//         00516d01     ADD        ESP,0x8
//         00516d04     IDIV       this
//         00516d06     ADD        EDX,0x1c
//         00516d09     LEA        EDX,[EDX + EDX*0x2]
//         00516d0c     LEA        ESI,[EDX + EDX*0x4]
//         00516d0f     SHL        ESI,0x2
//                              tplayer.cpp:3643 (24)
//         00516d12     CMP        EBX,0x73
//         00516d15     JA         switchD_00516d23::caseD_1
//         00516d1b     XOR        EDX,EDX
//         00516d1d     MOV        DL,byte ptr [EBX + switchD_00516d23::switchdat
//                               switchD_00516d23::switchD
//         00516d23     JMP        dword ptr [EDX*0x4 + switchD_00516d23::switchd   = 00516d2a
//                               switchD_00516d23::caseD_3                                    XREF[22]:    00517a7c(*), 00517a80(*),
//                               switchD_00516d23::caseD_b                                                 00517a8c(*), 00517a90(*),
//                               switchD_00516d23::caseD_c                                                 00517a9c(*), 00517aa4(*),
//                               switchD_00516d23::caseD_d                                                 00517aa8(*), 00517ab0(*),
//                               switchD_00516d23::caseD_13                                                00517ab8(*), 00517abc(*),
//                               switchD_00516d23::caseD_2f                                                00517ac0(*), 00517ac4(*),
//                               switchD_00516d23::caseD_30                                                00517ac8(*), 00517acc(*),
//                               switchD_00516d23::caseD_33                                                00517ad0(*), 00517ad4(*),
//                               switchD_00516d23::caseD_37                                                00517ad8(*), 00517adc(*),
//                               switchD_00516d23::caseD_39                                                00517ae0(*), 00517ae4(*), [more]
//                               switchD_00516d23::caseD_48
//                               switchD_00516d23::caseD_4a
//                               switchD_00516d23::caseD_4b
//                               switchD_00516d23::caseD_4e
//                               switchD_00516d23::caseD_51
//                               switchD_00516d23::caseD_55
//                               switchD_00516d23::caseD_58
//                               switchD_00516d23::caseD_5a
//                               switchD_00516d23::caseD_5e
//                               switchD_00516d23::caseD_60
//                               switchD_00516d23::caseD_64
//                               switchD_00516d23::caseD_69
//                               switchD_00516d23::caseD_6e
//                               switchD_00516d23::caseD_73
//                               switchD_00516d23::caseD_0
//                              tplayer.cpp:3671 (5)
//         00516d2a     MOV        EAX,[DAT_00886c3c]
//                              tplayer.cpp:3672 (44)
//         00516d2f     PUSH       0xe58
//         00516d34     INC        EAX
//         00516d35     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516d3a     MOV        [DAT_00886c3c],EAX
//         00516d3f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516d44     CDQ
//         00516d45     MOV        this,0x6
//         00516d4a     ADD        ESP,0x8
//         00516d4d     IDIV       this
//         00516d4f     ADD        EDX,0x14
//         00516d52     LEA        EAX,[EDX + EDX*0x2]
//         00516d55     LEA        ESI,[EAX + EAX*0x4]
//         00516d58     SHL        ESI,0x2
//                              tplayer.cpp:3673 (2)
//         00516d5b     JMP        LAB_00516dd3
//                               switchD_00516d23::caseD_29                                   XREF[7]:     00516d23(j), 00517a88(*),
//                               switchD_00516d23::caseD_2b                                                00517a94(*), 00517a98(*),
//                               switchD_00516d23::caseD_2c                                                00517aa0(*), 00517ab4(*),
//                               switchD_00516d23::caseD_2d                                                00517ae8(*)
//                               switchD_00516d23::caseD_32
//                               switchD_00516d23::caseD_3a
//                               switchD_00516d23::caseD_71
//                               switchD_00516d23::caseD_a
//                              tplayer.cpp:3683 (6)
//         00516d5d     MOV        EBX,dword ptr [DAT_00886c38]
//                              tplayer.cpp:3684 (49)
//         00516d63     PUSH       0xe64
//         00516d68     INC        EBX
//         00516d69     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516d6e     MOV        dword ptr [DAT_00886c38],EBX
//         00516d74     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516d79     CDQ
//         00516d7a     XOR        EAX,EDX
//         00516d7c     ADD        ESP,0x8
//         00516d7f     SUB        EAX,EDX
//         00516d81     AND        EAX,0x3
//         00516d84     XOR        EAX,EDX
//         00516d86     SUB        EAX,EDX
//         00516d88     ADD        EAX,0xb
//         00516d8b     LEA        EAX,[EAX + EAX*0x2]
//         00516d8e     LEA        ESI,[EAX + EAX*0x4]
//         00516d91     SHL        ESI,0x2
//                              tplayer.cpp:3685 (2)
//         00516d94     JMP        LAB_00516dd3
//                               switchD_00516d23::caseD_38                                   XREF[3]:     00516d23(j), 00517a84(*),
//                               switchD_00516d23::caseD_9                                                 00517aac(*)
//                              tplayer.cpp:3689 (39)
//         00516d96     PUSH       0xe69
//         00516d9b     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516da0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516da5     CDQ
//         00516da6     XOR        EAX,EDX
//         00516da8     ADD        ESP,0x8
//         00516dab     SUB        EAX,EDX
//         00516dad     AND        EAX,0x1
//         00516db0     XOR        EAX,EDX
//         00516db2     SUB        EAX,EDX
//         00516db4     ADD        EAX,0x5
//         00516db7     LEA        EAX,[EAX + EAX*0x2]
//         00516dba     LEA        ESI,[EAX + EAX*0x4]
//                              tplayer.cpp:3690 (14)
//         00516dbd     MOV        EAX,[DAT_00886c38]
//         00516dc2     SHL        ESI,0x2
//         00516dc5     INC        EAX
//         00516dc6     MOV        [DAT_00886c38],EAX
//                              tplayer.cpp:3691 (2)
//         00516dcb     JMP        LAB_00516dd3
//                               switchD_00516d23::caseD_2                                    XREF[3]:     00516d15(j), 00516d23(j),
//                               switchD_00516d23::caseD_4                                                 00517af0(*)
//                               switchD_00516d23::caseD_5
//                               switchD_00516d23::caseD_6
//                               switchD_00516d23::caseD_7
//                               switchD_00516d23::caseD_8
//                               switchD_00516d23::caseD_e
//                               switchD_00516d23::caseD_f
//                               switchD_00516d23::caseD_10
//                               switchD_00516d23::caseD_11
//                               switchD_00516d23::caseD_12
//                               switchD_00516d23::caseD_14
//                               switchD_00516d23::caseD_15
//                               switchD_00516d23::caseD_16
//                               switchD_00516d23::caseD_17
//                               switchD_00516d23::caseD_18
//                               switchD_00516d23::caseD_19
//                               switchD_00516d23::caseD_1a
//                               switchD_00516d23::caseD_1b
//                               switchD_00516d23::caseD_1c
//                               switchD_00516d23::caseD_1d
//                               switchD_00516d23::caseD_1e
//                               switchD_00516d23::caseD_1f
//                               switchD_00516d23::caseD_20
//                               switchD_00516d23::caseD_21
//                               switchD_00516d23::caseD_22
//                               switchD_00516d23::caseD_23
//                               switchD_00516d23::caseD_24
//                               switchD_00516d23::caseD_25
//                               switchD_00516d23::caseD_26
//                               switchD_00516d23::caseD_27
//                               switchD_00516d23::caseD_28
//                               switchD_00516d23::caseD_2a
//                               switchD_00516d23::caseD_2e
//                               switchD_00516d23::caseD_31
//                               switchD_00516d23::caseD_34
//                               switchD_00516d23::caseD_35
//                               switchD_00516d23::caseD_36
//                               switchD_00516d23::caseD_3b
//                               switchD_00516d23::caseD_3c
//                               switchD_00516d23::caseD_3d
//                               switchD_00516d23::caseD_3e
//                               switchD_00516d23::caseD_3f
//                               switchD_00516d23::caseD_40
//                               switchD_00516d23::caseD_41
//                               switchD_00516d23::caseD_42
//                               switchD_00516d23::caseD_43
//                               switchD_00516d23::caseD_44
//                               switchD_00516d23::caseD_45
//                               switchD_00516d23::caseD_46
//                               switchD_00516d23::caseD_47
//                               switchD_00516d23::caseD_49
//                               switchD_00516d23::caseD_4c
//                               switchD_00516d23::caseD_4d
//                               switchD_00516d23::caseD_4f
//                               switchD_00516d23::caseD_50
//                               switchD_00516d23::caseD_52
//                               switchD_00516d23::caseD_53
//                               switchD_00516d23::caseD_54
//                               switchD_00516d23::caseD_56
//                               switchD_00516d23::caseD_57
//                               switchD_00516d23::caseD_59
//                               switchD_00516d23::caseD_5b
//                               switchD_00516d23::caseD_5c
//                               switchD_00516d23::caseD_5d
//                               switchD_00516d23::caseD_5f
//                               switchD_00516d23::caseD_61
//                               switchD_00516d23::caseD_62
//                               switchD_00516d23::caseD_63
//                               switchD_00516d23::caseD_65
//                               switchD_00516d23::caseD_66
//                               switchD_00516d23::caseD_67
//                               switchD_00516d23::caseD_68
//                               switchD_00516d23::caseD_6a
//                               switchD_00516d23::caseD_6b
//                               switchD_00516d23::caseD_6c
//                               switchD_00516d23::caseD_6d
//                               switchD_00516d23::caseD_6f
//                               switchD_00516d23::caseD_70
//                               switchD_00516d23::caseD_72
//                               switchD_00516d23::caseD_1
//                              tplayer.cpp:3693 (6)
//         00516dcd     INC        dword ptr [DAT_00886c40]                         = align(4)
//                               LAB_00516dd3                                                 XREF[3]:     00516d5b(j), 00516d94(j),
//                                                                                                         00516dcb(j)
//                              tplayer.cpp:3698 (8)
//         00516dd3     MOV        EBX,dword ptr [ESP + 0x14]
//         00516dd7     TEST       EBX,EBX
//         00516dd9     JNZ        LAB_00516dff
//                              tplayer.cpp:3699 (26)
//         00516ddb     PUSH       0xe73
//         00516de0     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516de5     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516dea     CDQ
//         00516deb     MOV        this,0x3
//         00516df0     ADD        ESP,0x8
//         00516df3     IDIV       this
//                              tplayer.cpp:3700 (4)
//         00516df5     TEST       EDX,EDX
//         00516df7     JNZ        LAB_00516dff
//                              tplayer.cpp:3701 (6)
//         00516df9     SUB        ESI,0x12c
//                               LAB_00516dff                                                 XREF[2]:     00516dd9(j), 00516df7(j)
//                              tplayer.cpp:3703 (20)
//         00516dff     MOV        this,dword ptr [EBP + 0x238]
//         00516e05     PUSH       ESI
//                              language.dll match for 0x68: "Arial"
//         00516e06     PUSH       offset DAT_fffffff8
//         00516e08     ADD        this,0x10e74
//         00516e0e     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3706 (21)
//         00516e13     MOV        this,dword ptr [EBP + 0x238]
//         00516e19     PUSH       0x2
//         00516e1b     PUSH       offset DAT_fffffff8
//         00516e1d     ADD        this,0x10e74
//         00516e23     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3707 (21)
//         00516e28     MOV        this,dword ptr [EBP + 0x238]
//         00516e2e     PUSH       0xa
//         00516e30     PUSH       offset DAT_fffffff8
//         00516e32     ADD        this,0x10e74
//         00516e38     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3708 (21)
//         00516e3d     MOV        this,dword ptr [EBP + 0x238]
//         00516e43     PUSH       0x1
//         00516e45     PUSH       offset DAT_fffffff8
//         00516e47     ADD        this,0x10e74
//         00516e4d     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3709 (21)
//         00516e52     MOV        this,dword ptr [EBP + 0x238]
//         00516e58     PUSH       0x4
//         00516e5a     PUSH       offset DAT_fffffff8
//         00516e5c     ADD        this,0x10e74
//         00516e62     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              language.dll match for 0xe80: "Click to mine for gold."
//                              tplayer.cpp:3712 (26)
//         00516e67     PUSH       0xe80
//         00516e6c     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516e71     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516e76     CDQ
//         00516e77     MOV        this,0x3
//         00516e7c     ADD        ESP,0x8
//         00516e7f     IDIV       this
//                              tplayer.cpp:3713 (4)
//         00516e81     TEST       EDX,EDX
//         00516e83     JNZ        LAB_00516e88
//                              tplayer.cpp:3714 (1)
//         00516e85     PUSH       EDX
//                              tplayer.cpp:3715 (2)
//         00516e86     JMP        LAB_00516e8a
//                               LAB_00516e88                                                 XREF[1]:     00516e83(j)
//                              tplayer.cpp:3716 (24)
//         00516e88     PUSH       0x1
//                               LAB_00516e8a                                                 XREF[1]:     00516e86(j)
//         00516e8a     MOV        this,dword ptr [EBP + 0x238]
//         00516e90     PUSH       offset DAT_fffffff8
//         00516e95     ADD        this,0x10e74
//         00516e9b     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3718 (26)
//         00516ea0     PUSH       0xe86
//         00516ea5     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516eaa     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516eaf     CDQ
//         00516eb0     MOV        this,0x28
//         00516eb5     ADD        ESP,0x8
//         00516eb8     IDIV       this
//                              tplayer.cpp:3719 (26)
//         00516eba     MOV        this,dword ptr [EBP + 0x238]
//         00516ec0     ADD        this,0x10e74
//         00516ec6     ADD        EDX,0xa
//         00516ec9     PUSH       EDX
//         00516eca     PUSH       offset DAT_fffffff8
//         00516ecf     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3722 (26)
//         00516ed4     PUSH       0xe8a
//         00516ed9     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516ede     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516ee3     CDQ
//         00516ee4     MOV        this,0x46
//         00516ee9     ADD        ESP,0x8
//         00516eec     IDIV       this
//                              tplayer.cpp:3723 (26)
//         00516eee     MOV        this,dword ptr [EBP + 0x238]
//         00516ef4     ADD        this,0x10e74
//         00516efa     ADD        EDX,0x1e
//         00516efd     PUSH       EDX
//         00516efe     PUSH       offset DAT_fffffff8
//         00516f03     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3726 (28)
//         00516f08     PUSH       0xe8e
//         00516f0d     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516f12     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516f17     CDQ
//         00516f18     MOV        this,0x5
//         00516f1d     ADD        ESP,0x8
//         00516f20     IDIV       this
//         00516f22     ADD        EDX,this
//                              tplayer.cpp:3727 (26)
//         00516f24     MOV        this,dword ptr [EBP + 0x238]
//         00516f2a     IMUL       EDX,EBX
//         00516f2d     PUSH       EDX
//         00516f2e     PUSH       offset DAT_fffffff8
//         00516f33     ADD        this,0x10e74
//         00516f39     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3730 (28)
//         00516f3e     PUSH       0xe92
//         00516f43     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516f48     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516f4d     CDQ
//         00516f4e     MOV        this,0xa
//         00516f53     ADD        ESP,0x8
//         00516f56     IDIV       this
//         00516f58     ADD        EDX,this
//                              tplayer.cpp:3731 (26)
//         00516f5a     MOV        this,dword ptr [EBP + 0x238]
//         00516f60     IMUL       EDX,EBX
//         00516f63     PUSH       EDX
//         00516f64     PUSH       offset DAT_fffffff8
//         00516f69     ADD        this,0x10e74
//         00516f6f     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3734 (24)
//         00516f74     MOV        this,dword ptr [EBP + 0x238]
//         00516f7a     PUSH       0x4
//         00516f7c     PUSH       offset DAT_fffffff8
//         00516f81     ADD        this,0x10e74
//         00516f87     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3738 (7)
//         00516f8c     MOV        EAX,dword ptr [ESP + 0x324]
//                              tplayer.cpp:3739 (4)
//         00516f93     TEST       EDI,EDI
//         00516f95     JNZ        LAB_00516f9c
//                              tplayer.cpp:3740 (3)
//         00516f97     ADD        EAX,-0x2
//                              tplayer.cpp:3741 (7)
//         00516f9a     JMP        LAB_00516fa2
//                               LAB_00516f9c                                                 XREF[1]:     00516f95(j)
//         00516f9c     CMP        EDI,0x1
//         00516f9f     JNZ        LAB_00516fa2
//                              tplayer.cpp:3742 (1)
//         00516fa1     DEC        EAX
//                               LAB_00516fa2                                                 XREF[2]:     00516f9a(j), 00516f9f(j)
//                              tplayer.cpp:3743 (19)
//         00516fa2     ADD        EAX,0x2
//         00516fa5     CMP        EAX,0x6
//         00516fa8     JA         switchD_00516fae::default
//                               switchD_00516fae::switchD
//         00516fae     JMP        dword ptr [EAX*0x4 + switchD_00516fae::switchd   = 00516fb5
//                               switchD_00516fae::caseD_ffffffff                             XREF[3]:     00516fae(j), 00517b68(*),
//                               switchD_00516fae::caseD_fffffffe                                          00517b6c(*)
//                              tplayer.cpp:3746 (53)
//         00516fb5     PUSH       0xea2
//         00516fba     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00516fbf     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00516fc4     CDQ
//         00516fc5     XOR        EAX,EDX
//         00516fc7     MOV        this,dword ptr [EBP + 0x238]
//         00516fcd     SUB        EAX,EDX
//         00516fcf     ADD        ESP,0x8
//         00516fd2     AND        EAX,0x1
//         00516fd5     ADD        this,0x10e74
//         00516fdb     XOR        EAX,EDX
//         00516fdd     SUB        EAX,EDX
//         00516fdf     ADD        EAX,0xe
//         00516fe2     PUSH       EAX
//         00516fe3     PUSH       offset DAT_fffffff8
//         00516fe5     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3748 (55)
//         00516fea     MOV        this,dword ptr [EBP + 0x238]
//         00516ff0     PUSH       0x49
//         00516ff2     ADD        this,0x10e74
//         00516ff8     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         00516ffd     PUSH       0xea4
//         00517002     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517007     MOV        ESI,EAX
//         00517009     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0051700e     CDQ
//         0051700f     XOR        EAX,EDX
//         00517011     ADD        ESP,0x8
//         00517014     SUB        EAX,EDX
//         00517016     AND        EAX,0x3
//         00517019     XOR        EAX,EDX
//         0051701b     SUB        EAX,EDX
//         0051701d     LEA        EDX,[ESI + EAX*0x1 + 0x1]
//                              tplayer.cpp:3749 (5)
//         00517021     JMP        LAB_005172a0
//                              language.dll match for 0xea7: "Click to convert this unit."
//                               switchD_00516fae::caseD_0                                    XREF[2]:     00516fae(j), 00517b70(*)
//                              tplayer.cpp:3751 (53)
//         00517026     PUSH       0xea7
//         0051702b     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517030     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517035     CDQ
//         00517036     XOR        EAX,EDX
//         00517038     MOV        this,dword ptr [EBP + 0x238]
//         0051703e     SUB        EAX,EDX
//         00517040     ADD        ESP,0x8
//         00517043     AND        EAX,0x1
//         00517046     ADD        this,0x10e74
//         0051704c     XOR        EAX,EDX
//         0051704e     SUB        EAX,EDX
//         00517050     ADD        EAX,0xf
//         00517053     PUSH       EAX
//         00517054     PUSH       offset DAT_fffffff8
//         00517056     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3753 (56)
//         0051705b     MOV        this,dword ptr [EBP + 0x238]
//         00517061     PUSH       0x49
//         00517063     ADD        this,0x10e74
//         00517069     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         0051706e     PUSH       0xea9
//         00517073     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517078     MOV        ESI,EAX
//         0051707a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0051707f     CDQ
//         00517080     XOR        EAX,EDX
//         00517082     ADD        ESP,0x8
//         00517085     SUB        EAX,EDX
//         00517087     AND        EAX,0x3
//         0051708a     XOR        EAX,EDX
//         0051708c     SUB        EAX,EDX
//         0051708e     LEA        EAX,[ESI + EAX*0x1 + 0x1]
//         00517092     PUSH       EAX
//                              tplayer.cpp:3754 (5)
//         00517093     JMP        LAB_005172a1
//                               switchD_00516fae::caseD_1                                    XREF[2]:     00516fae(j), 00517b74(*)
//                              tplayer.cpp:3756 (49)
//         00517098     PUSH       0xeac
//         0051709d     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005170a2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005170a7     CDQ
//         005170a8     MOV        this,0x3
//         005170ad     ADD        ESP,0x8
//         005170b0     IDIV       this
//         005170b2     MOV        this,dword ptr [EBP + 0x238]
//         005170b8     ADD        this,0x10e74
//         005170be     ADD        EDX,0x10
//         005170c1     PUSH       EDX
//         005170c2     PUSH       offset DAT_fffffff8
//         005170c4     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3758 (45)
//         005170c9     MOV        this,dword ptr [EBP + 0x238]
//         005170cf     PUSH       0x49
//         005170d1     ADD        this,0x10e74
//         005170d7     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         005170dc     PUSH       0xeae
//         005170e1     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005170e6     MOV        ESI,EAX
//         005170e8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005170ed     ADD        ESP,0x8
//         005170f0     MOV        this,0x5
//         005170f5     CDQ
//                              tplayer.cpp:3759 (5)
//         005170f6     JMP        LAB_0051729a
//                               switchD_00516fae::caseD_2                                    XREF[2]:     00516fae(j), 00517b78(*)
//                              tplayer.cpp:3761 (53)
//         005170fb     PUSH       0xeb1
//         00517100     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517105     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0051710a     CDQ
//         0051710b     XOR        EAX,EDX
//         0051710d     MOV        this,dword ptr [EBP + 0x238]
//         00517113     SUB        EAX,EDX
//         00517115     ADD        ESP,0x8
//         00517118     AND        EAX,0x1
//         0051711b     ADD        this,0x10e74
//         00517121     XOR        EAX,EDX
//         00517123     SUB        EAX,EDX
//         00517125     ADD        EAX,0x11
//         00517128     PUSH       EAX
//         00517129     PUSH       offset DAT_fffffff8
//         0051712b     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3763 (45)
//         00517130     MOV        this,dword ptr [EBP + 0x238]
//         00517136     PUSH       0x49
//         00517138     ADD        this,0x10e74
//         0051713e     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         00517143     PUSH       0xeb3
//         00517148     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051714d     MOV        ESI,EAX
//         0051714f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517154     ADD        ESP,0x8
//         00517157     MOV        this,0x6
//         0051715c     CDQ
//                              tplayer.cpp:3764 (5)
//         0051715d     JMP        LAB_0051729a
//                               switchD_00516fae::caseD_3                                    XREF[2]:     00516fae(j), 00517b7c(*)
//                              tplayer.cpp:3766 (53)
//         00517162     PUSH       0xeb6
//         00517167     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051716c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517171     CDQ
//         00517172     XOR        EAX,EDX
//         00517174     MOV        this,dword ptr [EBP + 0x238]
//         0051717a     SUB        EAX,EDX
//         0051717c     ADD        ESP,0x8
//         0051717f     AND        EAX,0x1
//         00517182     ADD        this,0x10e74
//         00517188     XOR        EAX,EDX
//         0051718a     SUB        EAX,EDX
//         0051718c     ADD        EAX,0x12
//         0051718f     PUSH       EAX
//         00517190     PUSH       offset DAT_fffffff8
//         00517192     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3768 (45)
//         00517197     MOV        this,dword ptr [EBP + 0x238]
//         0051719d     PUSH       0x49
//         0051719f     ADD        this,0x10e74
//         005171a5     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         005171aa     PUSH       0xeb8
//         005171af     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005171b4     MOV        ESI,EAX
//         005171b6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005171bb     ADD        ESP,0x8
//         005171be     MOV        this,0x7
//         005171c3     CDQ
//                              tplayer.cpp:3769 (5)
//         005171c4     JMP        LAB_0051729a
//                               switchD_00516fae::caseD_4                                    XREF[2]:     00516fae(j), 00517b80(*)
//                              tplayer.cpp:3771 (53)
//         005171c9     PUSH       0xebb
//         005171ce     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         005171d3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         005171d8     CDQ
//         005171d9     XOR        EAX,EDX
//         005171db     MOV        this,dword ptr [EBP + 0x238]
//         005171e1     SUB        EAX,EDX
//         005171e3     ADD        ESP,0x8
//         005171e6     AND        EAX,0x3
//         005171e9     ADD        this,0x10e74
//         005171ef     XOR        EAX,EDX
//         005171f1     SUB        EAX,EDX
//         005171f3     ADD        EAX,0x12
//         005171f6     PUSH       EAX
//         005171f7     PUSH       offset DAT_fffffff8
//         005171f9     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3773 (56)
//         005171fe     MOV        this,dword ptr [EBP + 0x238]
//         00517204     PUSH       0x49
//         00517206     ADD        this,0x10e74
//         0051720c     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         00517211     PUSH       0xebd
//         00517216     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051721b     MOV        ESI,EAX
//         0051721d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517222     CDQ
//         00517223     XOR        EAX,EDX
//         00517225     ADD        ESP,0x8
//         00517228     SUB        EAX,EDX
//         0051722a     AND        EAX,0x7
//         0051722d     XOR        EAX,EDX
//         0051722f     SUB        EAX,EDX
//         00517231     LEA        EAX,[ESI + EAX*0x1 + 0x1]
//         00517235     PUSH       EAX
//                              tplayer.cpp:3774 (2)
//         00517236     JMP        LAB_005172a1
//                               switchD_00516fae::default                                    XREF[1]:     00516fa8(j)
//                              tplayer.cpp:3777 (53)
//         00517238     PUSH       0xec1
//         0051723d     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517242     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517247     CDQ
//         00517248     XOR        EAX,EDX
//         0051724a     MOV        this,dword ptr [EBP + 0x238]
//         00517250     SUB        EAX,EDX
//         00517252     ADD        ESP,0x8
//         00517255     AND        EAX,0x1
//         00517258     ADD        this,0x10e74
//         0051725e     XOR        EAX,EDX
//         00517260     SUB        EAX,EDX
//         00517262     ADD        EAX,0x12
//         00517265     PUSH       EAX
//         00517266     PUSH       offset DAT_fffffff8
//         00517268     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3779 (71)
//         0051726d     MOV        this,dword ptr [EBP + 0x238]
//         00517273     PUSH       0x49
//         00517275     ADD        this,0x10e74
//         0051727b     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//         00517280     PUSH       0xec3
//         00517285     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051728a     MOV        ESI,EAX
//         0051728c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517291     ADD        ESP,0x8
//         00517294     MOV        this,0x9
//         00517299     CDQ
//                               LAB_0051729a                                                 XREF[3]:     005170f6(j), 0051715d(j),
//                                                                                                         005171c4(j)
//         0051729a     IDIV       this
//         0051729c     LEA        EDX,[ESI + EDX*0x1 + 0x1]
//                               LAB_005172a0                                                 XREF[1]:     00517021(j)
//         005172a0     PUSH       EDX
//                               LAB_005172a1                                                 XREF[2]:     00517093(j), 00517236(j)
//         005172a1     MOV        this,dword ptr [EBP + 0x238]
//         005172a7     PUSH       offset DAT_fffffff8
//         005172a9     ADD        this,0x10e74
//         005172af     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3784 (24)
//         005172b4     MOV        this,dword ptr [EBP + 0x238]
//         005172ba     PUSH       0x1
//         005172bc     PUSH       offset DAT_fffffff8
//         005172c1     ADD        this,0x10e74
//         005172c7     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3785 (24)
//         005172cc     MOV        this,dword ptr [EBP + 0x238]
//         005172d2     PUSH       0x1
//         005172d4     PUSH       offset DAT_fffffff8
//         005172d9     ADD        this,0x10e74
//         005172df     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3786 (24)
//         005172e4     MOV        this,dword ptr [EBP + 0x238]
//         005172ea     PUSH       0x1
//         005172ec     PUSH       offset DAT_fffffff8
//         005172f1     ADD        this,0x10e74
//         005172f7     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3787 (24)
//         005172fc     MOV        this,dword ptr [EBP + 0x238]
//         00517302     PUSH       0x1
//         00517304     PUSH       offset DAT_fffffff8
//         00517309     ADD        this,0x10e74
//         0051730f     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3788 (4)
//         00517314     TEST       EDI,EDI
//         00517316     JNZ        LAB_00517367
//                              tplayer.cpp:3793 (24)
//         00517318     MOV        this,dword ptr [EBP + 0x238]
//         0051731e     PUSH       0x3
//         00517320     PUSH       offset DAT_fffffff8
//         00517325     ADD        this,0x10e74
//         0051732b     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3794 (24)
//         00517330     MOV        this,dword ptr [EBP + 0x238]
//         00517336     PUSH       0x6
//         00517338     PUSH       offset DAT_fffffff8
//         0051733d     ADD        this,0x10e74
//         00517343     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3795 (24)
//         00517348     MOV        this,dword ptr [EBP + 0x238]
//         0051734e     PUSH       0x2
//         00517350     PUSH       offset DAT_fffffff8
//         00517355     ADD        this,0x10e74
//         0051735b     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3796 (2)
//         00517360     PUSH       0x6
//                              tplayer.cpp:3798 (10)
//         00517362     JMP        LAB_00517478
//                               LAB_00517367                                                 XREF[1]:     00517316(j)
//         00517367     CMP        EDI,0x1
//         0051736a     JNZ        LAB_005173bb
//                              tplayer.cpp:3803 (24)
//         0051736c     MOV        this,dword ptr [EBP + 0x238]
//         00517372     PUSH       0x2
//         00517374     PUSH       offset DAT_fffffff8
//         00517379     ADD        this,0x10e74
//         0051737f     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3804 (24)
//         00517384     MOV        this,dword ptr [EBP + 0x238]
//         0051738a     PUSH       0x5
//         0051738c     PUSH       offset DAT_fffffff8
//         00517391     ADD        this,0x10e74
//         00517397     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3805 (24)
//         0051739c     MOV        this,dword ptr [EBP + 0x238]
//         005173a2     PUSH       0x2
//         005173a4     PUSH       offset DAT_fffffff8
//         005173a9     ADD        this,0x10e74
//         005173af     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3806 (2)
//         005173b4     PUSH       0x4
//                              tplayer.cpp:3808 (5)
//         005173b6     JMP        LAB_00517478
//                               LAB_005173bb                                                 XREF[1]:     0051736a(j)
//                              tplayer.cpp:3811 (20)
//         005173bb     CMP        EDI,0x2
//         005173be     JZ         LAB_0051742e
//         005173c0     CMP        EDI,0x6
//         005173c3     JZ         LAB_0051742e
//         005173c5     CMP        EDI,0x5
//         005173c8     JZ         LAB_0051742e
//         005173ca     CMP        EDI,0x8
//         005173cd     JZ         LAB_0051742e
//                              tplayer.cpp:3824 (19)
//         005173cf     CMP        EDI,0x3
//         005173d2     JZ         LAB_005173e2
//         005173d4     CMP        EDI,0x4
//         005173d7     JZ         LAB_005173e2
//         005173d9     CMP        EDI,0x7
//         005173dc     JNZ        LAB_0051748e
//                               LAB_005173e2                                                 XREF[2]:     005173d2(j), 005173d7(j)
//                              tplayer.cpp:3829 (24)
//         005173e2     MOV        this,dword ptr [EBP + 0x238]
//         005173e8     PUSH       0x0
//         005173ea     PUSH       offset DAT_fffffff8
//         005173ef     ADD        this,0x10e74
//         005173f5     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3830 (24)
//         005173fa     MOV        this,dword ptr [EBP + 0x238]
//         00517400     PUSH       0x0
//         00517402     PUSH       offset DAT_fffffff8
//         00517407     ADD        this,0x10e74
//         0051740d     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3831 (24)
//         00517412     MOV        this,dword ptr [EBP + 0x238]
//         00517418     PUSH       0x0
//         0051741a     PUSH       offset DAT_fffffff8
//         0051741f     ADD        this,0x10e74
//         00517425     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3832 (4)
//         0051742a     PUSH       0x0
//         0051742c     JMP        LAB_00517478
//                               LAB_0051742e                                                 XREF[4]:     005173be(j), 005173c3(j),
//                                                                                                         005173c8(j), 005173cd(j)
//                              tplayer.cpp:3817 (24)
//         0051742e     MOV        this,dword ptr [EBP + 0x238]
//         00517434     PUSH       0x1
//         00517436     PUSH       offset DAT_fffffff8
//         0051743b     ADD        this,0x10e74
//         00517441     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3818 (24)
//         00517446     MOV        this,dword ptr [EBP + 0x238]
//         0051744c     PUSH       0x4
//         0051744e     PUSH       offset DAT_fffffff8
//         00517453     ADD        this,0x10e74
//         00517459     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3819 (24)
//         0051745e     MOV        this,dword ptr [EBP + 0x238]
//         00517464     PUSH       0x1
//         00517466     PUSH       offset DAT_fffffff8
//         0051746b     ADD        this,0x10e74
//         00517471     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3820 (24)
//         00517476     PUSH       0x3
//                               LAB_00517478                                                 XREF[3]:     00517362(j), 005173b6(j),
//                                                                                                         0051742c(j)
//         00517478     MOV        this,dword ptr [EBP + 0x238]
//         0051747e     PUSH       offset DAT_fffffff8
//         00517483     ADD        this,0x10e74
//         00517489     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_0051748e                                                 XREF[1]:     005173dc(j)
//                              tplayer.cpp:3836 (9)
//         0051748e     MOV        EAX,[allowAIToCheat]                             = 1h
//         00517493     TEST       EAX,EAX
//         00517495     JZ         LAB_00517512
//                              tplayer.cpp:3841 (16)
//         00517497     MOV        this,dword ptr [ESP + 0x14]
//         0051749b     XOR        EAX,EAX
//         0051749d     XOR        EBX,EBX
//         0051749f     XOR        ESI,ESI
//         005174a1     XOR        EDI,EDI
//         005174a3     TEST       this,this
//         005174a5     JNZ        LAB_005174b2
//                              language.dll match for 0x7d0: "place holder"
//                              tplayer.cpp:3843 (5)
//         005174a7     MOV        EAX,0x7d0
//                              tplayer.cpp:3844 (2)
//         005174ac     MOV        ESI,EAX
//                              tplayer.cpp:3845 (2)
//         005174ae     MOV        EDI,EAX
//                              tplayer.cpp:3846 (2)
//         005174b0     MOV        EBX,EAX
//                               LAB_005174b2                                                 XREF[1]:     005174a5(j)
//                              tplayer.cpp:3873 (23)
//         005174b2     MOV        this,dword ptr [EBP + 0x238]
//         005174b8     PUSH       EAX
//         005174b9     PUSH       offset DAT_fffffff8
//         005174be     ADD        this,0x10e74
//         005174c4     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3874 (23)
//         005174c9     MOV        this,dword ptr [EBP + 0x238]
//         005174cf     PUSH       ESI
//         005174d0     PUSH       offset DAT_fffffff8
//         005174d5     ADD        this,0x10e74
//         005174db     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3875 (23)
//         005174e0     MOV        this,dword ptr [EBP + 0x238]
//         005174e6     PUSH       EDI
//         005174e7     PUSH       offset DAT_fffffff8
//         005174ec     ADD        this,0x10e74
//         005174f2     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3876 (27)
//         005174f7     MOV        this,dword ptr [EBP + 0x238]
//         005174fd     PUSH       EBX
//         005174fe     PUSH       offset DAT_fffffff8
//         00517503     ADD        this,0x10e74
//         00517509     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//         0051750e     MOV        EBX,dword ptr [ESP + 0x14]
//                               LAB_00517512                                                 XREF[1]:     00517495(j)
//                              tplayer.cpp:3880 (24)
//         00517512     MOV        this,dword ptr [EBP + 0x238]
//         00517518     PUSH       0x0
//         0051751a     PUSH       offset DAT_fffffff8
//         0051751f     ADD        this,0x10e74
//         00517525     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3886 (24)
//         0051752a     MOV        this,dword ptr [EBP + 0x238]
//         00517530     PUSH       0x0
//         00517532     PUSH       offset DAT_fffffff8
//         00517537     ADD        this,0x10e74
//         0051753d     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3890 (5)
//         00517542     CMP        EBX,0x3
//         00517545     JGE        LAB_00517563
//                              tplayer.cpp:3891 (24)
//         00517547     MOV        this,dword ptr [EBP + 0x238]
//         0051754d     PUSH       0x1
//         0051754f     PUSH       offset DAT_fffffff8
//         00517554     ADD        this,0x10e74
//         0051755a     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3892 (2)
//         0051755f     PUSH       0x2
//                              tplayer.cpp:3894 (2)
//         00517561     JMP        LAB_0051757d
//                               LAB_00517563                                                 XREF[1]:     00517545(j)
//                              tplayer.cpp:3895 (24)
//         00517563     MOV        this,dword ptr [EBP + 0x238]
//         00517569     PUSH       0x0
//         0051756b     PUSH       offset DAT_fffffff8
//         00517570     ADD        this,0x10e74
//         00517576     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3896 (21)
//         0051757b     PUSH       0x1
//                               LAB_0051757d                                                 XREF[1]:     00517561(j)
//         0051757d     MOV        this,dword ptr [EBP + 0x238]
//         00517583     PUSH       offset DAT_fffffff8
//         00517585     ADD        this,0x10e74
//         0051758b     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3901 (4)
//         00517590     TEST       EBX,EBX
//         00517592     JNZ        LAB_005175b6
//                              tplayer.cpp:3902 (27)
//         00517594     MOV        this,dword ptr [EBP + 0x238]
//         0051759a     PUSH       0xb4
//         0051759f     PUSH       offset DAT_fffffff8
//         005175a4     ADD        this,0x10e74
//         005175aa     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3903 (5)
//         005175af     PUSH       0xc8
//                              tplayer.cpp:3905 (7)
//         005175b4     JMP        LAB_00517623
//                               LAB_005175b6                                                 XREF[1]:     00517592(j)
//         005175b6     CMP        EBX,0x1
//         005175b9     JNZ        LAB_005175dd
//                              tplayer.cpp:3906 (27)
//         005175bb     MOV        this,dword ptr [EBP + 0x238]
//         005175c1     PUSH       0xb4
//         005175c6     PUSH       offset DAT_fffffff8
//         005175cb     ADD        this,0x10e74
//         005175d1     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3907 (5)
//         005175d6     PUSH       0x96
//                              tplayer.cpp:3909 (7)
//         005175db     JMP        LAB_00517623
//                               LAB_005175dd                                                 XREF[1]:     005175b9(j)
//         005175dd     CMP        EBX,0x2
//         005175e0     JNZ        LAB_00517601
//                              tplayer.cpp:3910 (27)
//         005175e2     MOV        this,dword ptr [EBP + 0x238]
//         005175e8     PUSH       0xb4
//         005175ed     PUSH       offset DAT_fffffff8
//         005175f2     ADD        this,0x10e74
//         005175f8     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3911 (2)
//         005175fd     PUSH       0x64
//                              tplayer.cpp:3913 (7)
//         005175ff     JMP        LAB_00517623
//                               LAB_00517601                                                 XREF[1]:     005175e0(j)
//         00517601     CMP        EBX,0x3
//         00517604     JNZ        LAB_00517639
//                              tplayer.cpp:3914 (27)
//         00517606     MOV        this,dword ptr [EBP + 0x238]
//         0051760c     PUSH       0xb4
//         00517611     PUSH       offset DAT_fffffff8
//         00517616     ADD        this,0x10e74
//         0051761c     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3915 (24)
//         00517621     PUSH       0x32
//                               LAB_00517623                                                 XREF[3]:     005175b4(j), 005175db(j),
//                                                                                                         005175ff(j)
//         00517623     MOV        this,dword ptr [EBP + 0x238]
//         00517629     PUSH       offset DAT_fffffff8
//         0051762e     ADD        this,0x10e74
//         00517634     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_00517639                                                 XREF[1]:     00517604(j)
//                              tplayer.cpp:3920 (26)
//         00517639     PUSH       0xf50
//         0051763e     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         00517643     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517648     CDQ
//         00517649     MOV        this,0x6
//         0051764e     ADD        ESP,0x8
//         00517651     IDIV       this
//                              tplayer.cpp:3921 (5)
//         00517653     CMP        EDX,0x5
//         00517656     JGE        LAB_0051765c
//                              tplayer.cpp:3922 (2)
//         00517658     PUSH       0x1
//                              tplayer.cpp:3923 (2)
//         0051765a     JMP        LAB_0051765e
//                               LAB_0051765c                                                 XREF[1]:     00517656(j)
//                              tplayer.cpp:3924 (24)
//         0051765c     PUSH       0x0
//                               LAB_0051765e                                                 XREF[1]:     0051765a(j)
//         0051765e     MOV        this,dword ptr [EBP + 0x238]
//         00517664     PUSH       offset DAT_fffffff8
//         00517669     ADD        this,0x10e74
//         0051766f     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3926 (26)
//         00517674     PUSH       0xf56
//         00517679     PUSH       s_C:\msdev\work\age1_x1\tplayer.cp               = "C:\\msdev\\work\\age1_x1\\tplayer.cpp"
//         0051767e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00517683     CDQ
//         00517684     MOV        this,0x3
//         00517689     ADD        ESP,0x8
//         0051768c     IDIV       this
//                              tplayer.cpp:3927 (5)
//         0051768e     CMP        EDX,0x1
//         00517691     JGE        LAB_00517697
//                              tplayer.cpp:3928 (2)
//         00517693     PUSH       0x1
//                              tplayer.cpp:3929 (2)
//         00517695     JMP        LAB_00517699
//                               LAB_00517697                                                 XREF[1]:     00517691(j)
//                              tplayer.cpp:3930 (24)
//         00517697     PUSH       0x0
//                               LAB_00517699                                                 XREF[1]:     00517695(j)
//         00517699     MOV        this,dword ptr [EBP + 0x238]
//         0051769f     PUSH       offset DAT_fffffff8
//         005176a4     ADD        this,0x10e74
//         005176aa     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_005176af                                                 XREF[1]:     00515e14(j)
//                              tplayer.cpp:3937 (13)
//         005176af     POP        EDI
//         005176b0     POP        ESI
//         005176b1     POP        EBP
//         005176b2     POP        EBX
//         005176b3     ADD        ESP,0x300
//         005176b9     RET        0x14
//                               switchD_00516c90::caseD_3                                    XREF[5]:     00516c90(j), 00517a6c(*),
//                               switchD_00516c90::caseD_4                                                 00517a70(*), 00517a74(*),
//                               switchD_00516c90::caseD_5                                                 00517a78(*)
//                               switchD_00516c90::caseD_2
//                              tplayer.cpp:3603 (19)
//         005176bc     MOV        this,dword ptr [EBP + 0x238]
//         005176c2     PUSH       0x1
//         005176c4     ADD        this,0x10e74
//         005176ca     CALL       TribeStrategyAIModule::rule                      int rule(TribeStrategyAIModule * this, int pa
//                              tplayer.cpp:3604 (25)
//         005176cf     MOV        this,dword ptr [EBP + 0x238]
//         005176d5     PUSH       0x32
//         005176d7     TEST       EAX,EAX
//         005176d9     PUSH       0x0=>DAT_fffffff8
//         005176db     JLE        LAB_00517701
//         005176dd     ADD        this,0x10e74
//         005176e3     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3605 (21)
//         005176e8     MOV        this,dword ptr [EBP + 0x238]
//         005176ee     PUSH       0x19
//         005176f0     PUSH       offset DAT_fffffff8
//         005176f2     ADD        this,0x10e74
//         005176f8     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3606 (2)
//         005176fd     PUSH       0x19
//                              tplayer.cpp:3608 (2)
//         005176ff     JMP        LAB_0051770e
//                               LAB_00517701                                                 XREF[1]:     005176db(j)
//                              tplayer.cpp:3609 (11)
//         00517701     ADD        this,0x10e74
//         00517707     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3610 (21)
//         0051770c     PUSH       0x32
//                               LAB_0051770e                                                 XREF[1]:     005176ff(j)
//         0051770e     MOV        this,dword ptr [EBP + 0x238]
//         00517714     PUSH       offset DAT_fffffff8
//         00517716     ADD        this,0x10e74
//         0051771c     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3612 (12)
//         00517721     MOV        EDI,dword ptr [ESP + 0x31c]
//         00517728     CMP        EDI,0x1
//         0051772b     JLE        LAB_00517742
//                              tplayer.cpp:3613 (21)
//         0051772d     MOV        this,dword ptr [EBP + 0x238]
//         00517733     PUSH       0x5
//         00517735     PUSH       offset DAT_fffffff8
//         00517737     ADD        this,0x10e74
//         0051773d     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                               LAB_00517742                                                 XREF[1]:     0051772b(j)
//                              tplayer.cpp:3615 (21)
//         00517742     MOV        this,dword ptr [EBP + 0x238]
//         00517748     PUSH       0x2
//         0051774a     PUSH       offset DAT_fffffff8
//         0051774c     ADD        this,0x10e74
//         00517752     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3617 (21)
//         00517757     MOV        this,dword ptr [EBP + 0x238]
//         0051775d     PUSH       0x2
//         0051775f     PUSH       offset DAT_fffffff8
//         00517761     ADD        this,0x10e74
//         00517767     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3619 (9)
//         0051776c     CMP        ESI,0x2
//         0051776f     JZ         switchD_00516c90::default
//                              tplayer.cpp:3623 (28)
//         00517775     MOV        this,dword ptr [ESP + 0x324]
//         0051777c     INC        this
//         0051777d     PUSH       this
//         0051777e     MOV        this,dword ptr [EBP + 0x238]
//         00517784     PUSH       offset DAT_fffffff8
//         00517786     ADD        this,0x10e74
//         0051778c     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3624 (21)
//         00517791     MOV        this,dword ptr [EBP + 0x238]
//         00517797     PUSH       0x1
//         00517799     PUSH       offset DAT_fffffff8
//         0051779b     ADD        this,0x10e74
//         005177a1     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3625 (5)
//         005177a6     CMP        ESI,0x3
//         005177a9     JNZ        LAB_005177af
//                              tplayer.cpp:3626 (2)
//         005177ab     PUSH       0x1
//                              tplayer.cpp:3627 (2)
//         005177ad     JMP        LAB_005177b1
//                               LAB_005177af                                                 XREF[1]:     005177a9(j)
//                              tplayer.cpp:3628 (21)
//         005177af     PUSH       0x5
//                               LAB_005177b1                                                 XREF[1]:     005177ad(j)
//         005177b1     MOV        this,dword ptr [EBP + 0x238]
//         005177b7     PUSH       offset DAT_fffffff8
//         005177b9     ADD        this,0x10e74
//         005177bf     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//                              tplayer.cpp:3630 (5)
//         005177c4     CMP        ESI,0x4
//         005177c7     JNZ        LAB_005177cd
//                              tplayer.cpp:3631 (2)
//         005177c9     PUSH       0x1
//                              tplayer.cpp:3632 (2)
//         005177cb     JMP        LAB_005177cf
//                               LAB_005177cd                                                 XREF[1]:     005177c7(j)
//                              tplayer.cpp:3633 (26)
//         005177cd     PUSH       0x5
//                               LAB_005177cf                                                 XREF[1]:     005177cb(j)
//         005177cf     MOV        this,dword ptr [EBP + 0x238]
//         005177d5     PUSH       offset DAT_fffffff8
//         005177d7     ADD        this,0x10e74
//         005177dd     CALL       TribeStrategyAIModule::setRule                   void setRule(TribeStrategyAIModule * this, in
//         005177e2     JMP        switchD_00516c90::default
//                              tplayer.cpp:3937 (925)
//         005177e7     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00515e5b::switchdataD_005177e8                       XREF[1]:     intelligentBuildListAndRulesSelect
//         005177e8     addr       switchD_00515e5b::caseD_1
//         005177ec     addr       switchD_00515e5b::caseD_2
//         005177f0     addr       switchD_00515e5b::caseD_3
//         005177f4     addr       switchD_00515e5b::caseD_4
//         005177f8     addr       switchD_00515e5b::caseD_5
//         005177fc     addr       switchD_00515e5b::caseD_6
//         00517800     addr       switchD_00515e5b::caseD_7
//         00517804     addr       switchD_00515e5b::caseD_8
//         00517808     addr       switchD_00515e5b::caseD_9
//         0051780c     addr       switchD_00515e5b::caseD_a
//         00517810     addr       switchD_00515e5b::caseD_b
//         00517814     addr       switchD_00515e5b::caseD_c
//         00517818     addr       switchD_00515e5b::caseD_d
//         0051781c     addr       switchD_00515e5b::caseD_e
//         00517820     addr       switchD_00515e5b::caseD_f
//         00517824     addr       switchD_00515e5b::caseD_10
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516113::switchdataD_00517828                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517828     addr       switchD_00516113::caseD_0
//         0051782c     addr       switchD_00516113::caseD_1
//         00517830     addr       switchD_00516113::caseD_2
//         00517834     addr       switchD_00516113::caseD_3
//         00517838     addr       switchD_00516113::caseD_4
//         0051783c     addr       switchD_00516113::caseD_5
//         00517840     addr       switchD_00516113::caseD_6
//         00517844     addr       switchD_00516113::caseD_7
//         00517848     addr       switchD_00516113::caseD_8
//         0051784c     addr       switchD_00516113::caseD_9
//         00517850     addr       switchD_00516113::caseD_7
//                              Symbol Ref: No symbol: NONAME
//                               switchD_005162d5::switchdataD_00517854                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517854     addr       switchD_005162d5::caseD_0
//         00517858     addr       switchD_005162d5::caseD_1
//         0051785c     addr       switchD_005162d5::caseD_2
//         00517860     addr       switchD_005162d5::caseD_3
//         00517864     addr       switchD_005162d5::caseD_4
//         00517868     addr       switchD_005162d5::caseD_5
//         0051786c     addr       switchD_005162d5::caseD_6
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516b23::switchdataD_00517870                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517870     addr       switchD_00516b23::caseD_0
//         00517874     addr       switchD_00516b23::caseD_0
//         00517878     addr       switchD_00516b23::caseD_0
//         0051787c     addr       switchD_00516b23::caseD_3
//         00517880     addr       switchD_00516b23::caseD_3
//         00517884     addr       switchD_00516b23::caseD_3
//         00517888     addr       switchD_00516b23::caseD_6
//         0051788c     addr       switchD_00516b23::caseD_6
//         00517890     addr       switchD_00516b23::caseD_6
//         00517894     addr       switchD_00516b23::caseD_3
//         00517898     addr       switchD_00516b23::caseD_3
//         0051789c     addr       switchD_00516b23::caseD_3
//         005178a0     addr       switchD_00516b23::caseD_3
//         005178a4     addr       switchD_00516b23::caseD_d
//         005178a8     addr       switchD_00516b23::caseD_d
//         005178ac     addr       switchD_00516b23::caseD_d
//         005178b0     addr       switchD_00516b23::caseD_10
//         005178b4     addr       switchD_00516b23::caseD_11
//         005178b8     addr       switchD_00516b23::caseD_11
//         005178bc     addr       switchD_00516b23::caseD_13
//         005178c0     addr       switchD_00516b23::caseD_13
//         005178c4     addr       switchD_00516b23::caseD_13
//         005178c8     addr       switchD_00516b23::caseD_16
//         005178cc     addr       switchD_00516b23::caseD_16
//         005178d0     addr       switchD_00516b23::caseD_16
//         005178d4     addr       switchD_00516b23::caseD_16
//         005178d8     addr       switchD_00516b23::caseD_16
//         005178dc     addr       switchD_00516b23::caseD_16
//         005178e0     addr       switchD_00516b23::caseD_16
//         005178e4     addr       switchD_00516b23::caseD_16
//         005178e8     addr       switchD_00516b23::caseD_16
//         005178ec     addr       switchD_00516b23::caseD_16
//         005178f0     addr       switchD_00516b23::caseD_16
//         005178f4     addr       switchD_00516b23::caseD_16
//         005178f8     addr       switchD_00516b23::caseD_16
//         005178fc     addr       switchD_00516b23::caseD_16
//         00517900     addr       switchD_00516b23::caseD_16
//         00517904     addr       switchD_00516b23::caseD_16
//         00517908     addr       switchD_00516b23::caseD_16
//         0051790c     addr       switchD_00516b23::caseD_16
//         00517910     addr       switchD_00516b23::caseD_28
//         00517914     addr       switchD_00516b23::caseD_0
//         00517918     addr       switchD_00516b23::caseD_3
//         0051791c     addr       switchD_00516b23::caseD_6
//         00517920     addr       switchD_00516b23::caseD_3
//         00517924     addr       switchD_00516b23::caseD_3
//         00517928     addr       switchD_00516b23::caseD_11
//         0051792c     addr       switchD_00516b23::caseD_3
//         00517930     addr       switchD_00516b23::caseD_3
//         00517934     addr       switchD_00516b23::caseD_10
//         00517938     addr       switchD_00516b23::caseD_0
//         0051793c     addr       switchD_00516b23::caseD_0
//         00517940     addr       switchD_00516b23::caseD_11
//         00517944     addr       switchD_00516b23::caseD_11
//         00517948     addr       switchD_00516b23::caseD_6
//         0051794c     addr       switchD_00516b23::caseD_6
//         00517950     addr       switchD_00516b23::caseD_3
//         00517954     addr       switchD_00516b23::caseD_28
//         00517958     addr       switchD_00516b23::caseD_6
//         0051795c     addr       switchD_00516b23::caseD_6
//         00517960     addr       switchD_00516b23::caseD_3c
//         00517964     addr       switchD_00516b23::caseD_3c
//         00517968     addr       switchD_00516b23::caseD_3c
//         0051796c     addr       switchD_00516b23::caseD_3c
//         00517970     addr       switchD_00516b23::caseD_3c
//         00517974     addr       switchD_00516b23::caseD_3c
//         00517978     addr       switchD_00516b23::caseD_3c
//         0051797c     addr       switchD_00516b23::caseD_3c
//         00517980     addr       switchD_00516b23::caseD_3c
//         00517984     addr       switchD_00516b23::caseD_3c
//         00517988     addr       switchD_00516b23::caseD_3c
//         0051798c     addr       switchD_00516b23::caseD_3c
//         00517990     addr       switchD_00516b23::caseD_48
//         00517994     addr       switchD_00516b23::caseD_48
//         00517998     addr       switchD_00516b23::caseD_4a
//         0051799c     addr       switchD_00516b23::caseD_3c
//         005179a0     addr       switchD_00516b23::caseD_3c
//         005179a4     addr       switchD_00516b23::caseD_3c
//         005179a8     addr       switchD_00516b23::caseD_3c
//         005179ac     addr       switchD_00516b23::caseD_3c
//         005179b0     addr       switchD_00516b23::caseD_0
//         005179b4     addr       switchD_00516b23::caseD_0
//         005179b8     addr       switchD_00516b23::caseD_0
//         005179bc     addr       switchD_00516b23::caseD_3c
//         005179c0     addr       switchD_00516b23::caseD_28
//         005179c4     addr       switchD_00516b23::caseD_3c
//         005179c8     addr       switchD_00516b23::caseD_3c
//         005179cc     addr       switchD_00516b23::caseD_3c
//         005179d0     addr       switchD_00516b23::caseD_3c
//         005179d4     addr       switchD_00516b23::caseD_3c
//         005179d8     addr       switchD_00516b23::caseD_3c
//         005179dc     addr       switchD_00516b23::caseD_3c
//         005179e0     addr       switchD_00516b23::caseD_3c
//         005179e4     addr       switchD_00516b23::caseD_3c
//         005179e8     addr       switchD_00516b23::caseD_3c
//         005179ec     addr       switchD_00516b23::caseD_3c
//         005179f0     addr       switchD_00516b23::caseD_3c
//         005179f4     addr       switchD_00516b23::caseD_3c
//         005179f8     addr       switchD_00516b23::caseD_3
//         005179fc     addr       switchD_00516b23::caseD_11
//         00517a00     addr       switchD_00516b23::caseD_3c
//         00517a04     addr       switchD_00516b23::caseD_3c
//         00517a08     addr       switchD_00516b23::caseD_11
//         00517a0c     addr       switchD_00516b23::caseD_3
//         00517a10     addr       switchD_00516b23::caseD_6
//         00517a14     addr       switchD_00516b23::caseD_3c
//         00517a18     addr       switchD_00516b23::caseD_3c
//         00517a1c     addr       switchD_00516b23::caseD_0
//         00517a20     addr       switchD_00516b23::caseD_10
//         00517a24     addr       switchD_00516b23::caseD_11
//         00517a28     addr       switchD_00516b23::caseD_3c
//         00517a2c     addr       switchD_00516b23::caseD_3c
//         00517a30     addr       switchD_00516b23::caseD_3
//         00517a34     addr       switchD_00516b23::caseD_3
//         00517a38     addr       switchD_00516b23::caseD_28
//         00517a3c     addr       switchD_00516b23::caseD_3c
//         00517a40     addr       switchD_00516b23::caseD_3c
//         00517a44     addr       switchD_00516b23::caseD_16
//         00517a48     addr       switchD_00516b23::caseD_16
//         00517a4c     addr       switchD_00516b23::caseD_16
//         00517a50     addr       switchD_00516b23::caseD_16
//         00517a54     addr       switchD_00516b23::caseD_3c
//         00517a58     addr       switchD_00516b23::caseD_3c
//         00517a5c     addr       switchD_00516b23::caseD_3c
//         00517a60     addr       switchD_00516b23::caseD_3c
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516c90::switchdataD_00517a64                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517a64     addr       switchD_00516c90::caseD_0
//         00517a68     addr       switchD_00516c90::caseD_0
//         00517a6c     addr       switchD_00516c90::caseD_2
//         00517a70     addr       switchD_00516c90::caseD_2
//         00517a74     addr       switchD_00516c90::caseD_2
//         00517a78     addr       switchD_00516c90::caseD_2
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516d23::switchdataD_00517a7c                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517a7c     addr       switchD_00516d23::caseD_0
//         00517a80     addr       switchD_00516d23::caseD_0
//         00517a84     addr       switchD_00516d23::caseD_9
//         00517a88     addr       switchD_00516d23::caseD_a
//         00517a8c     addr       switchD_00516d23::caseD_0
//         00517a90     addr       switchD_00516d23::caseD_0
//         00517a94     addr       switchD_00516d23::caseD_a
//         00517a98     addr       switchD_00516d23::caseD_a
//         00517a9c     addr       switchD_00516d23::caseD_0
//         00517aa0     addr       switchD_00516d23::caseD_a
//         00517aa4     addr       switchD_00516d23::caseD_0
//         00517aa8     addr       switchD_00516d23::caseD_0
//         00517aac     addr       switchD_00516d23::caseD_9
//         00517ab0     addr       switchD_00516d23::caseD_0
//         00517ab4     addr       switchD_00516d23::caseD_a
//         00517ab8     addr       switchD_00516d23::caseD_0
//         00517abc     addr       switchD_00516d23::caseD_0
//         00517ac0     addr       switchD_00516d23::caseD_0
//         00517ac4     addr       switchD_00516d23::caseD_0
//         00517ac8     addr       switchD_00516d23::caseD_0
//         00517acc     addr       switchD_00516d23::caseD_0
//         00517ad0     addr       switchD_00516d23::caseD_0
//         00517ad4     addr       switchD_00516d23::caseD_0
//         00517ad8     addr       switchD_00516d23::caseD_0
//         00517adc     addr       switchD_00516d23::caseD_0
//         00517ae0     addr       switchD_00516d23::caseD_0
//         00517ae4     addr       switchD_00516d23::caseD_0
//         00517ae8     addr       switchD_00516d23::caseD_a
//         00517aec     addr       switchD_00516d23::caseD_0
//         00517af0     addr       switchD_00516d23::caseD_1
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516d23::switchdataD_00517af4                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517af4     db         0h
//         00517af5     db         1Dh
//         00517af6     db         1Dh
//         00517af7     db         1h
//         00517af8     db         1Dh
//         00517af9     db         1Dh
//         00517afa     db         1Dh
//         00517afb     db         1Dh
//         00517afc     db         1Dh
//         00517afd     db         2h
//         00517afe     db         3h
//         00517aff     db         4h
//         00517b00     db         4h
//         00517b01     db         4h
//         00517b02     db         1Dh
//         00517b03     db         1Dh
//         00517b04     db         1Dh
//         00517b05     db         1Dh
//         00517b06     db         1Dh
//         00517b07     db         5h
//         00517b08     db         1Dh
//         00517b09     db         1Dh
//         00517b0a     db         1Dh
//         00517b0b     db         1Dh
//         00517b0c     db         1Dh
//         00517b0d     db         1Dh
//         00517b0e     db         1Dh
//         00517b0f     db         1Dh
//         00517b10     db         1Dh
//         00517b11     db         1Dh
//         00517b12     db         1Dh
//         00517b13     db         1Dh
//         00517b14     db         1Dh
//         00517b15     db         1Dh
//         00517b16     db         1Dh
//         00517b17     db         1Dh
//         00517b18     db         1Dh
//         00517b19     db         1Dh
//         00517b1a     db         1Dh
//         00517b1b     db         1Dh
//         00517b1c     db         1Dh
//         00517b1d     db         6h
//         00517b1e     db         1Dh
//         00517b1f     db         7h
//         00517b20     db         7h
//         00517b21     db         7h
//         00517b22     db         1Dh
//         00517b23     db         8h
//         00517b24     db         8h
//         00517b25     db         1Dh
//         00517b26     db         9h
//         00517b27     db         Ah
//         00517b28     db         1Dh
//         00517b29     db         1Dh
//         00517b2a     db         1Dh
//         00517b2b     db         Bh
//         00517b2c     db         Ch
//         00517b2d     db         Dh
//         00517b2e     db         Eh
//         00517b2f     db         1Dh
//         00517b30     db         1Dh
//         00517b31     db         1Dh
//         00517b32     db         1Dh
//         00517b33     db         1Dh
//         00517b34     db         1Dh
//         00517b35     db         1Dh
//         00517b36     db         1Dh
//         00517b37     db         1Dh
//         00517b38     db         1Dh
//         00517b39     db         1Dh
//         00517b3a     db         1Dh
//         00517b3b     db         1Dh
//         00517b3c     db         Fh
//         00517b3d     db         1Dh
//         00517b3e     db         10h
//         00517b3f     db         10h
//         00517b40     db         1Dh
//         00517b41     db         1Dh
//         00517b42     db         11h
//         00517b43     db         1Dh
//         00517b44     db         1Dh
//         00517b45     db         12h
//         00517b46     db         1Dh
//         00517b47     db         1Dh
//         00517b48     db         1Dh
//         00517b49     db         13h
//         00517b4a     db         1Dh
//         00517b4b     db         1Dh
//         00517b4c     db         14h
//         00517b4d     db         1Dh
//         00517b4e     db         15h
//         00517b4f     db         1Dh
//         00517b50     db         1Dh
//         00517b51     db         1Dh
//         00517b52     db         16h
//         00517b53     db         1Dh
//         00517b54     db         17h
//         00517b55     db         1Dh
//         00517b56     db         1Dh
//         00517b57     db         1Dh
//         00517b58     db         18h
//         00517b59     db         1Dh
//         00517b5a     db         1Dh
//         00517b5b     db         1Dh
//         00517b5c     db         1Dh
//         00517b5d     db         19h
//         00517b5e     db         1Dh
//         00517b5f     db         1Dh
//         00517b60     db         1Dh
//         00517b61     db         1Dh
//         00517b62     db         1Ah
//         00517b63     db         1Dh
//         00517b64     db         1Dh
//         00517b65     db         1Bh
//         00517b66     db         1Dh
//         00517b67     db         1Ch
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00516fae::switchdataD_00517b68                       XREF[1]:     intelligentBuildListAndRulesSelect
//         00517b68     addr       switchD_00516fae::caseD_fffffffe
//         00517b6c     addr       switchD_00516fae::caseD_fffffffe
//         00517b70     addr       switchD_00516fae::caseD_0
//         00517b74     addr       switchD_00516fae::caseD_1
//         00517b78     addr       switchD_00516fae::caseD_2
//         00517b7c     addr       switchD_00516fae::caseD_3
//         00517b80     addr       switchD_00516fae::caseD_4
//         00517b84     ??         90h
//         00517b85     ??         90h
//         00517b86     ??         90h
//         00517b87     ??         90h
//         00517b88     ??         90h
//         00517b89     ??         90h
//         00517b8a     ??         90h
//         00517b8b     ??         90h
//         00517b8c     ??         90h
//         00517b8d     ??         90h
//         00517b8e     ??         90h
//         00517b8f     ??         90h
    return;
}

void TRIBE_Player::setupEgyptian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupEgyptian(TRIBE_Player * this, int * param_1, in
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[6]:     00517bd4(R), 00517be2(R), 00517bfa(R), 00517c12(R),
//                                                                                     00517c33(R), 00517c44(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00517bb3(R), 00517c77(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupEgyptian@TRIBE_Player@@QAEXPAHHHH@Z                    XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupEgyptian
//                              tplayer.cpp:3943 (17)
//         00517b90     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00517b96     PUSH       s_Setting_up_as_Egyptians.                       = "Setting up as Egyptians."
//         00517b9b     PUSH       EAX
//         00517b9c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:3946 (18)
//         00517ba1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517ba7     ADD        ESP,0x8
//         00517baa     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00517baf     CMP        AL,0x1
//         00517bb1     JNZ        LAB_00517c23
//                              tplayer.cpp:3948 (13)
//         00517bb3     MOV        EAX,dword ptr [ESP + param_2]
//         00517bb7     TEST       EAX,EAX
//         00517bb9     JZ         LAB_00517c12
//         00517bbb     CMP        EAX,0x1
//         00517bbe     JZ         LAB_00517c12
//                              tplayer.cpp:3950 (10)
//         00517bc0     CMP        EAX,0x2
//         00517bc3     JZ         LAB_00517bfa
//         00517bc5     CMP        EAX,0x6
//         00517bc8     JZ         LAB_00517bfa
//                              tplayer.cpp:3955 (10)
//         00517bca     CMP        EAX,0x5
//         00517bcd     JZ         LAB_00517be2
//         00517bcf     CMP        EAX,0x8
//         00517bd2     JZ         LAB_00517be2
//                              tplayer.cpp:3961 (11)
//         00517bd4     MOV        this,dword ptr [ESP + param_1]
//         00517bd8     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:3987 (3)
//         00517bdf     RET        0x10
//                               LAB_00517be2                                                 XREF[2]:     00517bcd(j), 00517bd2(j)
//                              tplayer.cpp:3957 (11)
//         00517be2     MOV        EAX,dword ptr [ESP + param_1]
//         00517be6     MOV        dword ptr [EAX + 0x64],0x50
//                              tplayer.cpp:3958 (10)
//         00517bed     MOV        dword ptr [EAX + 0xfc],0x14
//                              tplayer.cpp:3987 (3)
//         00517bf7     RET        0x10
//                               LAB_00517bfa                                                 XREF[2]:     00517bc3(j), 00517bc8(j)
//                              tplayer.cpp:3952 (11)
//         00517bfa     MOV        EAX,dword ptr [ESP + param_1]
//         00517bfe     MOV        dword ptr [EAX + 0x64],0x3c
//                              tplayer.cpp:3953 (10)
//         00517c05     MOV        dword ptr [EAX + 0xfc],0x28
//                              tplayer.cpp:3987 (3)
//         00517c0f     RET        0x10
//                               LAB_00517c12                                                 XREF[2]:     00517bb9(j), 00517bbe(j)
//                              tplayer.cpp:3949 (14)
//         00517c12     MOV        EDX,dword ptr [ESP + param_1]
//         00517c16     MOV        dword ptr [EDX + 0xfc],0x64
//                              tplayer.cpp:3987 (3)
//         00517c20     RET        0x10
//                               LAB_00517c23                                                 XREF[1]:     00517bb1(j)
//                              tplayer.cpp:3965 (16)
//         00517c23     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517c29     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         00517c2e     CMP        EAX,0x1
//         00517c31     JGE        LAB_00517c44
//                              tplayer.cpp:3967 (14)
//         00517c33     MOV        EAX,dword ptr [ESP + param_1]
//         00517c37     MOV        dword ptr [EAX + 0x8c],0x64
//                              tplayer.cpp:3987 (3)
//         00517c41     RET        0x10
//                               LAB_00517c44                                                 XREF[1]:     00517c31(j)
//                              tplayer.cpp:3971 (9)
//         00517c44     MOV        EAX,dword ptr [ESP + param_1]
//         00517c48     MOV        this,0xa
//                              tplayer.cpp:3978 (42)
//         00517c4d     MOV        EDX,0x64
//         00517c52     MOV        dword ptr [EAX + 0xc],this
//         00517c55     MOV        dword ptr [EAX + 0x24],this
//         00517c58     MOV        dword ptr [EAX + 0x28],this
//         00517c5b     MOV        this,0x28
//         00517c60     MOV        dword ptr [EAX + 0x44],this
//         00517c63     MOV        dword ptr [EAX + 0x48],this
//         00517c66     MOV        this,0x32
//         00517c6b     MOV        dword ptr [EAX + 0xb8],EDX
//         00517c71     MOV        dword ptr [EAX + 0x4c],this
//         00517c74     MOV        dword ptr [EAX + 0x50],this
//                              tplayer.cpp:3983 (45)
//         00517c77     MOV        this,dword ptr [ESP + param_2]
//         00517c7b     MOV        dword ptr [EAX + 0xbc],EDX
//         00517c81     TEST       this,this
//         00517c83     MOV        dword ptr [EAX + 0x140],EDX
//         00517c89     MOV        dword ptr [EAX + 0x144],0x1e
//         00517c93     MOV        dword ptr [EAX + 0x148],0x14
//         00517c9d     JZ         LAB_00517cc1
//         00517c9f     CMP        this,0x1
//         00517ca2     JZ         LAB_00517cc1
//                              tplayer.cpp:3985 (20)
//         00517ca4     CMP        this,0x2
//         00517ca7     JZ         LAB_00517cb8
//         00517ca9     CMP        this,0x6
//         00517cac     JZ         LAB_00517cb8
//         00517cae     CMP        this,0x8
//         00517cb1     JZ         LAB_00517cb8
//         00517cb3     CMP        this,0x5
//         00517cb6     JNZ        LAB_00517ccb
//                               LAB_00517cb8                                                 XREF[3]:     00517ca7(j), 00517cac(j),
//                                                                                                         00517cb1(j)
//                              tplayer.cpp:3986 (6)
//         00517cb8     MOV        dword ptr [EAX + 0x14c],EDX
//                              tplayer.cpp:3987 (3)
//         00517cbe     RET        0x10
//                               LAB_00517cc1                                                 XREF[2]:     00517c9d(j), 00517ca2(j)
//                              tplayer.cpp:3984 (10)
//         00517cc1     MOV        dword ptr [EAX + 0x14c],0xc8
//                               LAB_00517ccb                                                 XREF[1]:     00517cb6(j)
//                              tplayer.cpp:3987 (3)
//         00517ccb     RET        0x10
//         00517cce     ??         90h
//         00517ccf     NOP
    return;
}

void TRIBE_Player::setupGreek(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupGreek(TRIBE_Player * this, int * param_1, int p
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00517d14(R), 00517d22(R), 00517d3a(R), 00517d52(R),
//                                                                                     00517d71(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00517cf3(R), 00517d97(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupGreek@TRIBE_Player@@QAEXPAHHHH@Z                       XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupGreek
//                              tplayer.cpp:3992 (17)
//         00517cd0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00517cd6     PUSH       s_Setting_up_as_Greeks.                          = "Setting up as Greeks."
//         00517cdb     PUSH       EAX
//         00517cdc     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:3995 (18)
//         00517ce1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517ce7     ADD        ESP,0x8
//         00517cea     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00517cef     CMP        AL,0x1
//         00517cf1     JNZ        LAB_00517d63
//                              tplayer.cpp:3997 (13)
//         00517cf3     MOV        EAX,dword ptr [ESP + param_2]
//         00517cf7     TEST       EAX,EAX
//         00517cf9     JZ         LAB_00517d52
//         00517cfb     CMP        EAX,0x1
//         00517cfe     JZ         LAB_00517d52
//                              tplayer.cpp:3999 (10)
//         00517d00     CMP        EAX,0x2
//         00517d03     JZ         LAB_00517d3a
//         00517d05     CMP        EAX,0x6
//         00517d08     JZ         LAB_00517d3a
//                              tplayer.cpp:4004 (10)
//         00517d0a     CMP        EAX,0x5
//         00517d0d     JZ         LAB_00517d22
//         00517d0f     CMP        EAX,0x8
//         00517d12     JZ         LAB_00517d22
//                              tplayer.cpp:4010 (11)
//         00517d14     MOV        this,dword ptr [ESP + param_1]
//         00517d18     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4041 (3)
//         00517d1f     RET        0x10
//                               LAB_00517d22                                                 XREF[2]:     00517d0d(j), 00517d12(j)
//                              tplayer.cpp:4006 (11)
//         00517d22     MOV        EAX,dword ptr [ESP + param_1]
//         00517d26     MOV        dword ptr [EAX + 0x68],0x50
//                              tplayer.cpp:4007 (10)
//         00517d2d     MOV        dword ptr [EAX + 0x100],0x14
//                              tplayer.cpp:4041 (3)
//         00517d37     RET        0x10
//                               LAB_00517d3a                                                 XREF[2]:     00517d03(j), 00517d08(j)
//                              tplayer.cpp:4001 (11)
//         00517d3a     MOV        EAX,dword ptr [ESP + param_1]
//         00517d3e     MOV        dword ptr [EAX + 0x68],0x3c
//                              tplayer.cpp:4002 (10)
//         00517d45     MOV        dword ptr [EAX + 0x100],0x28
//                              tplayer.cpp:4041 (3)
//         00517d4f     RET        0x10
//                               LAB_00517d52                                                 XREF[2]:     00517cf9(j), 00517cfe(j)
//                              tplayer.cpp:3998 (14)
//         00517d52     MOV        EDX,dword ptr [ESP + param_1]
//         00517d56     MOV        dword ptr [EDX + 0x100],0x64
//                              tplayer.cpp:4041 (3)
//         00517d60     RET        0x10
//                               LAB_00517d63                                                 XREF[1]:     00517cf1(j)
//                              tplayer.cpp:4014 (14)
//         00517d63     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517d69     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         00517d6e     CMP        EAX,0x1
//                              tplayer.cpp:4016 (16)
//         00517d71     MOV        EAX,dword ptr [ESP + param_1]
//         00517d75     JGE        LAB_00517d84
//         00517d77     MOV        dword ptr [EAX + 0x90],0x64
//                              tplayer.cpp:4041 (3)
//         00517d81     RET        0x10
//                               LAB_00517d84                                                 XREF[1]:     00517d75(j)
//                              tplayer.cpp:4022 (5)
//         00517d84     MOV        this,0x1e
//                              tplayer.cpp:4024 (8)
//         00517d89     MOV        EDX,0xa
//         00517d8e     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4026 (3)
//         00517d91     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4028 (3)
//         00517d94     MOV        dword ptr [EAX + 0x50],this
//                              tplayer.cpp:4031 (64)
//         00517d97     MOV        this,dword ptr [ESP + param_2]
//         00517d9b     MOV        dword ptr [EAX + 0x24],EDX
//         00517d9e     MOV        dword ptr [EAX + 0x28],EDX
//         00517da1     MOV        EDX,0x64
//         00517da6     MOV        dword ptr [EAX + 0xc],0x46
//         00517dad     TEST       this,this
//         00517daf     MOV        dword ptr [EAX + 0x10],0x32
//         00517db6     MOV        dword ptr [EAX + 0x1c],0x14
//         00517dbd     MOV        dword ptr [EAX + 0x4c],0x32
//         00517dc4     MOV        dword ptr [EAX + 0xc0],EDX
//         00517dca     MOV        dword ptr [EAX + 0x150],EDX
//         00517dd0     JZ         LAB_00517dfa
//         00517dd2     CMP        this,0x1
//         00517dd5     JZ         LAB_00517dfa
//                              tplayer.cpp:4036 (20)
//         00517dd7     CMP        this,0x2
//         00517dda     JZ         LAB_00517deb
//         00517ddc     CMP        this,0x6
//         00517ddf     JZ         LAB_00517deb
//         00517de1     CMP        this,0x8
//         00517de4     JZ         LAB_00517deb
//         00517de6     CMP        this,0x5
//         00517de9     JNZ        LAB_00517e0b
//                               LAB_00517deb                                                 XREF[3]:     00517dda(j), 00517ddf(j),
//                                                                                                         00517de4(j)
//                              tplayer.cpp:4038 (6)
//         00517deb     MOV        dword ptr [EAX + 0x154],EDX
//                              tplayer.cpp:4039 (6)
//         00517df1     MOV        dword ptr [EAX + 0x158],EDX
//                              tplayer.cpp:4041 (3)
//         00517df7     RET        0x10
//                               LAB_00517dfa                                                 XREF[2]:     00517dd0(j), 00517dd5(j)
//                              tplayer.cpp:4033 (11)
//         00517dfa     MOV        this,0xc8
//         00517dff     MOV        dword ptr [EAX + 0x154],this
//                              tplayer.cpp:4034 (6)
//         00517e05     MOV        dword ptr [EAX + 0x158],this
//                               LAB_00517e0b                                                 XREF[1]:     00517de9(j)
//                              tplayer.cpp:4041 (3)
//         00517e0b     RET        0x10
//         00517e0e     ??         90h
//         00517e0f     NOP
    return;
}

void TRIBE_Player::setupBabylonian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupBabylonian(TRIBE_Player * this, int * param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00517e54(R), 00517e62(R), 00517e7a(R), 00517e92(R),
//                                                                                     00517ea3(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00517e33(R), 00517ee2(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupBabylonian@TRIBE_Player@@QAEXPAHHHH@Z                  XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupBabylonian
//                              tplayer.cpp:4046 (17)
//         00517e10     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00517e16     PUSH       s_Setting_up_as_Babylonians.                     = "Setting up as Babylonians."
//         00517e1b     PUSH       EAX
//         00517e1c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4049 (18)
//         00517e21     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517e27     ADD        ESP,0x8
//         00517e2a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00517e2f     CMP        AL,0x1
//         00517e31     JNZ        LAB_00517ea3
//                              tplayer.cpp:4051 (13)
//         00517e33     MOV        EAX,dword ptr [ESP + param_2]
//         00517e37     TEST       EAX,EAX
//         00517e39     JZ         LAB_00517e92
//         00517e3b     CMP        EAX,0x1
//         00517e3e     JZ         LAB_00517e92
//                              tplayer.cpp:4053 (10)
//         00517e40     CMP        EAX,0x2
//         00517e43     JZ         LAB_00517e7a
//         00517e45     CMP        EAX,0x6
//         00517e48     JZ         LAB_00517e7a
//                              tplayer.cpp:4058 (10)
//         00517e4a     CMP        EAX,0x5
//         00517e4d     JZ         LAB_00517e62
//         00517e4f     CMP        EAX,0x8
//         00517e52     JZ         LAB_00517e62
//                              tplayer.cpp:4064 (11)
//         00517e54     MOV        this,dword ptr [ESP + param_1]
//         00517e58     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4084 (3)
//         00517e5f     RET        0x10
//                               LAB_00517e62                                                 XREF[2]:     00517e4d(j), 00517e52(j)
//                              tplayer.cpp:4060 (11)
//         00517e62     MOV        EAX,dword ptr [ESP + param_1]
//         00517e66     MOV        dword ptr [EAX + 0x5c],0x50
//                              tplayer.cpp:4061 (10)
//         00517e6d     MOV        dword ptr [EAX + 0xf4],0x14
//                              tplayer.cpp:4084 (3)
//         00517e77     RET        0x10
//                               LAB_00517e7a                                                 XREF[2]:     00517e43(j), 00517e48(j)
//                              tplayer.cpp:4055 (11)
//         00517e7a     MOV        EAX,dword ptr [ESP + param_1]
//         00517e7e     MOV        dword ptr [EAX + 0x5c],0x3c
//                              tplayer.cpp:4056 (10)
//         00517e85     MOV        dword ptr [EAX + 0xf4],0x28
//                              tplayer.cpp:4084 (3)
//         00517e8f     RET        0x10
//                               LAB_00517e92                                                 XREF[2]:     00517e39(j), 00517e3e(j)
//                              tplayer.cpp:4052 (14)
//         00517e92     MOV        EDX,dword ptr [ESP + param_1]
//         00517e96     MOV        dword ptr [EDX + 0xf4],0x64
//                              tplayer.cpp:4084 (3)
//         00517ea0     RET        0x10
//                               LAB_00517ea3                                                 XREF[1]:     00517e31(j)
//                              tplayer.cpp:4068 (4)
//         00517ea3     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4069 (13)
//         00517ea7     MOV        this,0xa
//         00517eac     MOV        EDX,0x14
//         00517eb1     MOV        dword ptr [EAX + 0x4],this
//                              tplayer.cpp:4072 (3)
//         00517eb4     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4073 (3)
//         00517eb7     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4075 (3)
//         00517eba     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4076 (10)
//         00517ebd     MOV        this,0x28
//         00517ec2     MOV        dword ptr [EAX],EDX
//         00517ec4     MOV        dword ptr [EAX + 0x4c],this
//                              tplayer.cpp:4077 (3)
//         00517ec7     MOV        dword ptr [EAX + 0x50],this
//                              tplayer.cpp:4078 (18)
//         00517eca     MOV        this,0x64
//         00517ecf     MOV        dword ptr [EAX + 0x40],0x1e
//         00517ed6     MOV        dword ptr [EAX + 0xa8],this
//                              tplayer.cpp:4079 (6)
//         00517edc     MOV        dword ptr [EAX + 0xac],this
//                              tplayer.cpp:4080 (19)
//         00517ee2     MOV        this,dword ptr [ESP + param_2]
//         00517ee6     MOV        dword ptr [EAX + 0xc],EDX
//         00517ee9     TEST       this,this
//         00517eeb     MOV        dword ptr [EAX + 0x28],EDX
//         00517eee     JZ         LAB_00517f16
//         00517ef0     CMP        this,0x1
//         00517ef3     JZ         LAB_00517f16
//                              tplayer.cpp:4082 (20)
//         00517ef5     CMP        this,0x2
//         00517ef8     JZ         LAB_00517f09
//         00517efa     CMP        this,0x6
//         00517efd     JZ         LAB_00517f09
//         00517eff     CMP        this,0x8
//         00517f02     JZ         LAB_00517f09
//         00517f04     CMP        this,0x5
//         00517f07     JNZ        LAB_00517f20
//                               LAB_00517f09                                                 XREF[3]:     00517ef8(j), 00517efd(j),
//                                                                                                         00517f02(j)
//                              tplayer.cpp:4083 (10)
//         00517f09     MOV        dword ptr [EAX + 0x134],0x1e
//                              tplayer.cpp:4084 (3)
//         00517f13     RET        0x10
//                               LAB_00517f16                                                 XREF[2]:     00517eee(j), 00517ef3(j)
//                              tplayer.cpp:4081 (10)
//         00517f16     MOV        dword ptr [EAX + 0x134],0x3c
//                               LAB_00517f20                                                 XREF[1]:     00517f07(j)
//                              tplayer.cpp:4084 (3)
//         00517f20     RET        0x10
//         00517f23     ??         90h
//         00517f24     NOP
//         00517f25     NOP
//         00517f26     NOP
//         00517f27     NOP
//         00517f28     NOP
//         00517f29     NOP
//         00517f2a     NOP
//         00517f2b     NOP
//         00517f2c     NOP
//         00517f2d     NOP
//         00517f2e     NOP
//         00517f2f     NOP
    return;
}

void TRIBE_Player::setupAssyrian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupAssyrian(TRIBE_Player * this, int * param_1, in
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[6]:     00517f74(R), 00517f82(R), 00517f9a(R), 00517fb2(R),
//                                                                                     00517fd3(R), 00517fe4(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00517f53(R), 00518018(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupAssyrian@TRIBE_Player@@QAEXPAHHHH@Z                    XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupAssyrian
//                              tplayer.cpp:4089 (17)
//         00517f30     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00517f36     PUSH       s_Setting_up_as_Assyrians.                       = "Setting up as Assyrians."
//         00517f3b     PUSH       EAX
//         00517f3c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4092 (18)
//         00517f41     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517f47     ADD        ESP,0x8
//         00517f4a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00517f4f     CMP        AL,0x1
//         00517f51     JNZ        LAB_00517fc3
//                              tplayer.cpp:4094 (13)
//         00517f53     MOV        EAX,dword ptr [ESP + param_2]
//         00517f57     TEST       EAX,EAX
//         00517f59     JZ         LAB_00517fb2
//         00517f5b     CMP        EAX,0x1
//         00517f5e     JZ         LAB_00517fb2
//                              tplayer.cpp:4096 (10)
//         00517f60     CMP        EAX,0x2
//         00517f63     JZ         LAB_00517f9a
//         00517f65     CMP        EAX,0x6
//         00517f68     JZ         LAB_00517f9a
//                              tplayer.cpp:4101 (10)
//         00517f6a     CMP        EAX,0x5
//         00517f6d     JZ         LAB_00517f82
//         00517f6f     CMP        EAX,0x8
//         00517f72     JZ         LAB_00517f82
//                              tplayer.cpp:4107 (11)
//         00517f74     MOV        this,dword ptr [ESP + param_1]
//         00517f78     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4142 (3)
//         00517f7f     RET        0x10
//                               LAB_00517f82                                                 XREF[2]:     00517f6d(j), 00517f72(j)
//                              tplayer.cpp:4103 (11)
//         00517f82     MOV        EAX,dword ptr [ESP + param_1]
//         00517f86     MOV        dword ptr [EAX + 0x58],0x50
//                              tplayer.cpp:4104 (10)
//         00517f8d     MOV        dword ptr [EAX + 0xf0],0x14
//                              tplayer.cpp:4142 (3)
//         00517f97     RET        0x10
//                               LAB_00517f9a                                                 XREF[2]:     00517f63(j), 00517f68(j)
//                              tplayer.cpp:4098 (11)
//         00517f9a     MOV        EAX,dword ptr [ESP + param_1]
//         00517f9e     MOV        dword ptr [EAX + 0x58],0x3c
//                              tplayer.cpp:4099 (10)
//         00517fa5     MOV        dword ptr [EAX + 0xf0],0x28
//                              tplayer.cpp:4142 (3)
//         00517faf     RET        0x10
//                               LAB_00517fb2                                                 XREF[2]:     00517f59(j), 00517f5e(j)
//                              tplayer.cpp:4095 (14)
//         00517fb2     MOV        EDX,dword ptr [ESP + param_1]
//         00517fb6     MOV        dword ptr [EDX + 0xf0],0x64
//                              tplayer.cpp:4142 (3)
//         00517fc0     RET        0x10
//                               LAB_00517fc3                                                 XREF[1]:     00517f51(j)
//                              tplayer.cpp:4112 (16)
//         00517fc3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00517fc9     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         00517fce     CMP        EAX,0x1
//         00517fd1     JGE        LAB_00517fe4
//                              tplayer.cpp:4114 (14)
//         00517fd3     MOV        EAX,dword ptr [ESP + param_1]
//         00517fd7     MOV        dword ptr [EAX + 0x88],0x64
//                              tplayer.cpp:4142 (3)
//         00517fe1     RET        0x10
//                               LAB_00517fe4                                                 XREF[1]:     00517fd1(j)
//                              tplayer.cpp:4118 (4)
//         00517fe4     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4119 (13)
//         00517fe8     MOV        this,0xa
//         00517fed     MOV        EDX,0x28
//         00517ff2     MOV        dword ptr [EAX + 0xc],this
//                              tplayer.cpp:4121 (3)
//         00517ff5     MOV        dword ptr [EAX + 0x1c],this
//                              tplayer.cpp:4122 (3)
//         00517ff8     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4123 (3)
//         00517ffb     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4126 (3)
//         00517ffe     MOV        dword ptr [EAX + 0x50],this
//                              tplayer.cpp:4129 (11)
//         00518001     MOV        this,0x50
//         00518006     MOV        dword ptr [EAX + 0x120],this
//                              tplayer.cpp:4130 (6)
//         0051800c     MOV        dword ptr [EAX + 0x124],this
//                              tplayer.cpp:4131 (6)
//         00518012     MOV        dword ptr [EAX + 0x128],this
//                              tplayer.cpp:4132 (50)
//         00518018     MOV        this,dword ptr [ESP + param_2]
//         0051801c     MOV        dword ptr [EAX + 0x40],EDX
//         0051801f     MOV        dword ptr [EAX + 0x2c],EDX
//         00518022     MOV        EDX,0x64
//         00518027     MOV        dword ptr [EAX + 0x18],0x14
//         0051802e     TEST       this,this
//         00518030     MOV        dword ptr [EAX + 0x4c],0x14
//         00518037     MOV        dword ptr [EAX + 0xa0],EDX
//         0051803d     MOV        dword ptr [EAX + 0xa4],EDX
//         00518043     JZ         LAB_00518072
//         00518045     CMP        this,0x1
//         00518048     JZ         LAB_00518072
//                              tplayer.cpp:4137 (20)
//         0051804a     CMP        this,0x2
//         0051804d     JZ         LAB_0051805e
//         0051804f     CMP        this,0x6
//         00518052     JZ         LAB_0051805e
//         00518054     CMP        this,0x8
//         00518057     JZ         LAB_0051805e
//         00518059     CMP        this,0x5
//         0051805c     JNZ        LAB_0051807e
//                               LAB_0051805e                                                 XREF[3]:     0051804d(j), 00518052(j),
//                                                                                                         00518057(j)
//                              tplayer.cpp:4139 (11)
//         0051805e     MOV        this,0x32
//         00518063     MOV        dword ptr [EAX + 0x12c],this
//                              tplayer.cpp:4140 (6)
//         00518069     MOV        dword ptr [EAX + 0x130],this
//                              tplayer.cpp:4142 (3)
//         0051806f     RET        0x10
//                               LAB_00518072                                                 XREF[2]:     00518043(j), 00518048(j)
//                              tplayer.cpp:4134 (6)
//         00518072     MOV        dword ptr [EAX + 0x12c],EDX
//                              tplayer.cpp:4135 (6)
//         00518078     MOV        dword ptr [EAX + 0x130],EDX
//                               LAB_0051807e                                                 XREF[1]:     0051805c(j)
//                              tplayer.cpp:4142 (3)
//         0051807e     RET        0x10
//         00518081     ??         90h
//         00518082     NOP
//         00518083     NOP
//         00518084     NOP
//         00518085     NOP
//         00518086     NOP
//         00518087     NOP
//         00518088     NOP
//         00518089     NOP
//         0051808a     NOP
//         0051808b     NOP
//         0051808c     NOP
//         0051808d     NOP
//         0051808e     NOP
//         0051808f     NOP
    return;
}

void TRIBE_Player::setupMinoan(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupMinoan(TRIBE_Player * this, int * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     005180d4(R), 005180e2(R), 005180fa(R), 00518112(R),
//                                                                                     00518131(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     005180b3(R), 0051815d(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupMinoan@TRIBE_Player@@QAEXPAHHHH@Z                      XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupMinoan
//                              tplayer.cpp:4147 (17)
//         00518090     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518096     PUSH       s_Setting_up_as_Minoans.                         = "Setting up as Minoans."
//         0051809b     PUSH       EAX
//         0051809c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4150 (18)
//         005180a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005180a7     ADD        ESP,0x8
//         005180aa     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         005180af     CMP        AL,0x1
//         005180b1     JNZ        LAB_00518123
//                              tplayer.cpp:4152 (13)
//         005180b3     MOV        EAX,dword ptr [ESP + param_2]
//         005180b7     TEST       EAX,EAX
//         005180b9     JZ         LAB_00518112
//         005180bb     CMP        EAX,0x1
//         005180be     JZ         LAB_00518112
//                              tplayer.cpp:4154 (10)
//         005180c0     CMP        EAX,0x2
//         005180c3     JZ         LAB_005180fa
//         005180c5     CMP        EAX,0x6
//         005180c8     JZ         LAB_005180fa
//                              tplayer.cpp:4159 (10)
//         005180ca     CMP        EAX,0x5
//         005180cd     JZ         LAB_005180e2
//         005180cf     CMP        EAX,0x8
//         005180d2     JZ         LAB_005180e2
//                              tplayer.cpp:4165 (11)
//         005180d4     MOV        this,dword ptr [ESP + param_1]
//         005180d8     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4195 (3)
//         005180df     RET        0x10
//                               LAB_005180e2                                                 XREF[2]:     005180cd(j), 005180d2(j)
//                              tplayer.cpp:4161 (11)
//         005180e2     MOV        EAX,dword ptr [ESP + param_1]
//         005180e6     MOV        dword ptr [EAX + 0x70],0x50
//                              tplayer.cpp:4162 (10)
//         005180ed     MOV        dword ptr [EAX + 0x108],0x14
//                              tplayer.cpp:4195 (3)
//         005180f7     RET        0x10
//                               LAB_005180fa                                                 XREF[2]:     005180c3(j), 005180c8(j)
//                              tplayer.cpp:4156 (11)
//         005180fa     MOV        EAX,dword ptr [ESP + param_1]
//         005180fe     MOV        dword ptr [EAX + 0x70],0x3c
//                              tplayer.cpp:4157 (10)
//         00518105     MOV        dword ptr [EAX + 0x108],0x28
//                              tplayer.cpp:4195 (3)
//         0051810f     RET        0x10
//                               LAB_00518112                                                 XREF[2]:     005180b9(j), 005180be(j)
//                              tplayer.cpp:4153 (14)
//         00518112     MOV        EDX,dword ptr [ESP + param_1]
//         00518116     MOV        dword ptr [EDX + 0x108],0x64
//                              tplayer.cpp:4195 (3)
//         00518120     RET        0x10
//                               LAB_00518123                                                 XREF[1]:     005180b1(j)
//                              tplayer.cpp:4170 (14)
//         00518123     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518129     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         0051812e     CMP        EAX,0x1
//                              tplayer.cpp:4172 (16)
//         00518131     MOV        EAX,dword ptr [ESP + param_1]
//         00518135     JGE        LAB_00518144
//         00518137     MOV        dword ptr [EAX + 0x94],0x64
//                              tplayer.cpp:4195 (3)
//         00518141     RET        0x10
//                               LAB_00518144                                                 XREF[1]:     00518135(j)
//                              tplayer.cpp:4179 (5)
//         00518144     MOV        this,0xa
//                              tplayer.cpp:4184 (20)
//         00518149     MOV        EDX,0x64
//         0051814e     MOV        dword ptr [EAX + 0x10],this
//         00518151     MOV        dword ptr [EAX + 0x18],this
//         00518154     MOV        dword ptr [EAX + 0x24],this
//         00518157     MOV        dword ptr [EAX + 0x28],this
//         0051815a     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4185 (39)
//         0051815d     MOV        this,dword ptr [ESP + param_2]
//         00518161     TEST       this,this
//         00518163     MOV        dword ptr [EAX],0x3c
//         00518169     MOV        dword ptr [EAX + 0x4],0x50
//         00518170     MOV        dword ptr [EAX + 0xc],0x14
//         00518177     MOV        dword ptr [EAX + 0xcc],EDX
//         0051817d     JZ         LAB_005181a7
//         0051817f     CMP        this,0x1
//         00518182     JZ         LAB_005181a7
//                              tplayer.cpp:4190 (20)
//         00518184     CMP        this,0x2
//         00518187     JZ         LAB_00518198
//         00518189     CMP        this,0x6
//         0051818c     JZ         LAB_00518198
//         0051818e     CMP        this,0x8
//         00518191     JZ         LAB_00518198
//         00518193     CMP        this,0x5
//         00518196     JNZ        LAB_005181b8
//                               LAB_00518198                                                 XREF[3]:     00518187(j), 0051818c(j),
//                                                                                                         00518191(j)
//                              tplayer.cpp:4192 (6)
//         00518198     MOV        dword ptr [EAX + 0x160],EDX
//                              tplayer.cpp:4193 (6)
//         0051819e     MOV        dword ptr [EAX + 0x164],EDX
//                              tplayer.cpp:4195 (3)
//         005181a4     RET        0x10
//                               LAB_005181a7                                                 XREF[2]:     0051817d(j), 00518182(j)
//                              tplayer.cpp:4187 (11)
//         005181a7     MOV        this,0xc8
//         005181ac     MOV        dword ptr [EAX + 0x160],this
//                              tplayer.cpp:4188 (6)
//         005181b2     MOV        dword ptr [EAX + 0x164],this
//                               LAB_005181b8                                                 XREF[1]:     00518196(j)
//                              tplayer.cpp:4195 (3)
//         005181b8     RET        0x10
//         005181bb     ??         90h
//         005181bc     NOP
//         005181bd     NOP
//         005181be     NOP
//         005181bf     NOP
    return;
}

void TRIBE_Player::setupHittite(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupHittite(TRIBE_Player * this, int * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518204(R), 00518212(R), 0051822a(R), 00518242(R),
//                                                                                     00518253(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     005181e3(R), 0051827f(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupHittite@TRIBE_Player@@QAEXPAHHHH@Z                     XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupHittite
//                              tplayer.cpp:4200 (17)
//         005181c0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005181c6     PUSH       s_Setting_up_as_Hittites.                        = "Setting up as Hittites."
//         005181cb     PUSH       EAX
//         005181cc     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4203 (18)
//         005181d1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005181d7     ADD        ESP,0x8
//         005181da     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         005181df     CMP        AL,0x1
//         005181e1     JNZ        LAB_00518253
//                              tplayer.cpp:4205 (13)
//         005181e3     MOV        EAX,dword ptr [ESP + param_2]
//         005181e7     TEST       EAX,EAX
//         005181e9     JZ         LAB_00518242
//         005181eb     CMP        EAX,0x1
//         005181ee     JZ         LAB_00518242
//                              tplayer.cpp:4207 (10)
//         005181f0     CMP        EAX,0x2
//         005181f3     JZ         LAB_0051822a
//         005181f5     CMP        EAX,0x6
//         005181f8     JZ         LAB_0051822a
//                              tplayer.cpp:4212 (10)
//         005181fa     CMP        EAX,0x5
//         005181fd     JZ         LAB_00518212
//         005181ff     CMP        EAX,0x8
//         00518202     JZ         LAB_00518212
//                              tplayer.cpp:4218 (11)
//         00518204     MOV        this,dword ptr [ESP + param_1]
//         00518208     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4243 (3)
//         0051820f     RET        0x10
//                               LAB_00518212                                                 XREF[2]:     005181fd(j), 00518202(j)
//                              tplayer.cpp:4214 (11)
//         00518212     MOV        EAX,dword ptr [ESP + param_1]
//         00518216     MOV        dword ptr [EAX + 0x6c],0x50
//                              tplayer.cpp:4215 (10)
//         0051821d     MOV        dword ptr [EAX + 0x104],0x14
//                              tplayer.cpp:4243 (3)
//         00518227     RET        0x10
//                               LAB_0051822a                                                 XREF[2]:     005181f3(j), 005181f8(j)
//                              tplayer.cpp:4209 (11)
//         0051822a     MOV        EAX,dword ptr [ESP + param_1]
//         0051822e     MOV        dword ptr [EAX + 0x6c],0x3c
//                              tplayer.cpp:4210 (10)
//         00518235     MOV        dword ptr [EAX + 0x104],0x28
//                              tplayer.cpp:4243 (3)
//         0051823f     RET        0x10
//                               LAB_00518242                                                 XREF[2]:     005181e9(j), 005181ee(j)
//                              tplayer.cpp:4206 (14)
//         00518242     MOV        EDX,dword ptr [ESP + param_1]
//         00518246     MOV        dword ptr [EDX + 0x104],0x64
//                              tplayer.cpp:4243 (3)
//         00518250     RET        0x10
//                               LAB_00518253                                                 XREF[1]:     005181e1(j)
//                              tplayer.cpp:4222 (4)
//         00518253     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4224 (5)
//         00518257     MOV        this,0x28
//                              tplayer.cpp:4226 (8)
//         0051825c     MOV        EDX,0xa
//         00518261     MOV        dword ptr [EAX + 0x10],this
//                              tplayer.cpp:4230 (3)
//         00518264     MOV        dword ptr [EAX + 0x48],this
//                              tplayer.cpp:4231 (18)
//         00518267     MOV        this,0x64
//         0051826c     MOV        dword ptr [EAX + 0x40],0x50
//         00518273     MOV        dword ptr [EAX + 0xc4],this
//                              tplayer.cpp:4232 (6)
//         00518279     MOV        dword ptr [EAX + 0xc8],this
//                              tplayer.cpp:4233 (43)
//         0051827f     MOV        this,dword ptr [ESP + param_2]
//         00518283     MOV        dword ptr [EAX + 0xc],0x1e
//         0051828a     TEST       this,this
//         0051828c     MOV        dword ptr [EAX + 0x18],0x14
//         00518293     MOV        dword ptr [EAX + 0x24],EDX
//         00518296     MOV        dword ptr [EAX + 0x28],EDX
//         00518299     MOV        dword ptr [EAX + 0x2c],EDX
//         0051829c     MOV        dword ptr [EAX + 0x44],0x14
//         005182a3     JZ         LAB_005182cd
//         005182a5     CMP        this,0x1
//         005182a8     JZ         LAB_005182cd
//                              tplayer.cpp:4238 (20)
//         005182aa     CMP        this,0x2
//         005182ad     JZ         LAB_005182be
//         005182af     CMP        this,0x6
//         005182b2     JZ         LAB_005182be
//         005182b4     CMP        this,0x8
//         005182b7     JZ         LAB_005182be
//         005182b9     CMP        this,0x5
//         005182bc     JNZ        LAB_005182dd
//                               LAB_005182be                                                 XREF[3]:     005182ad(j), 005182b2(j),
//                                                                                                         005182b7(j)
//                              tplayer.cpp:4240 (10)
//         005182be     MOV        dword ptr [EAX + 0x15c],0x50
//                              tplayer.cpp:4241 (2)
//         005182c8     MOV        dword ptr [EAX],EDX
//                              tplayer.cpp:4243 (3)
//         005182ca     RET        0x10
//                               LAB_005182cd                                                 XREF[2]:     005182a3(j), 005182a8(j)
//                              tplayer.cpp:4235 (10)
//         005182cd     MOV        dword ptr [EAX + 0x15c],0xa0
//                              tplayer.cpp:4236 (6)
//         005182d7     MOV        dword ptr [EAX],0x14
//                               LAB_005182dd                                                 XREF[1]:     005182bc(j)
//                              tplayer.cpp:4243 (3)
//         005182dd     RET        0x10
    return;
}

void TRIBE_Player::setupPhoenician(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupPhoenician(TRIBE_Player * this, int * param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518324(R), 00518332(R), 0051834a(R), 00518362(R),
//                                                                                     00518373(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518303(R), 0051839b(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupPhoenician@TRIBE_Player@@QAEXPAHHHH@Z                  XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupPhoenician
//                              tplayer.cpp:4248 (17)
//         005182e0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005182e6     PUSH       s_Setting_up_as_Phoenicians.                     = "Setting up as Phoenicians."
//         005182eb     PUSH       EAX
//         005182ec     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4251 (18)
//         005182f1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005182f7     ADD        ESP,0x8
//         005182fa     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         005182ff     CMP        AL,0x1
//         00518301     JNZ        LAB_00518373
//                              tplayer.cpp:4253 (13)
//         00518303     MOV        EAX,dword ptr [ESP + param_2]
//         00518307     TEST       EAX,EAX
//         00518309     JZ         LAB_00518362
//         0051830b     CMP        EAX,0x1
//         0051830e     JZ         LAB_00518362
//                              tplayer.cpp:4255 (10)
//         00518310     CMP        EAX,0x2
//         00518313     JZ         LAB_0051834a
//         00518315     CMP        EAX,0x6
//         00518318     JZ         LAB_0051834a
//                              tplayer.cpp:4260 (10)
//         0051831a     CMP        EAX,0x5
//         0051831d     JZ         LAB_00518332
//         0051831f     CMP        EAX,0x8
//         00518322     JZ         LAB_00518332
//                              tplayer.cpp:4266 (11)
//         00518324     MOV        this,dword ptr [ESP + param_1]
//         00518328     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4287 (3)
//         0051832f     RET        0x10
//                               LAB_00518332                                                 XREF[2]:     0051831d(j), 00518322(j)
//                              tplayer.cpp:4262 (11)
//         00518332     MOV        EAX,dword ptr [ESP + param_1]
//         00518336     MOV        dword ptr [EAX + 0x78],0x50
//                              tplayer.cpp:4263 (10)
//         0051833d     MOV        dword ptr [EAX + 0x110],0x14
//                              tplayer.cpp:4287 (3)
//         00518347     RET        0x10
//                               LAB_0051834a                                                 XREF[2]:     00518313(j), 00518318(j)
//                              tplayer.cpp:4257 (11)
//         0051834a     MOV        EAX,dword ptr [ESP + param_1]
//         0051834e     MOV        dword ptr [EAX + 0x78],0x3c
//                              tplayer.cpp:4258 (10)
//         00518355     MOV        dword ptr [EAX + 0x110],0x28
//                              tplayer.cpp:4287 (3)
//         0051835f     RET        0x10
//                               LAB_00518362                                                 XREF[2]:     00518309(j), 0051830e(j)
//                              tplayer.cpp:4254 (14)
//         00518362     MOV        EDX,dword ptr [ESP + param_1]
//         00518366     MOV        dword ptr [EDX + 0x110],0x64
//                              tplayer.cpp:4287 (3)
//         00518370     RET        0x10
//                               LAB_00518373                                                 XREF[1]:     00518301(j)
//                              tplayer.cpp:4270 (4)
//         00518373     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4272 (13)
//         00518377     MOV        this,0xa
//         0051837c     MOV        EDX,0x14
//         00518381     MOV        dword ptr [EAX + 0xc],this
//                              tplayer.cpp:4273 (3)
//         00518384     MOV        dword ptr [EAX + 0x10],this
//                              tplayer.cpp:4275 (3)
//         00518387     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4276 (3)
//         0051838a     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4277 (3)
//         0051838d     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4278 (8)
//         00518390     MOV        this,0x46
//         00518395     MOV        dword ptr [EAX + 0x44],this
//                              tplayer.cpp:4279 (3)
//         00518398     MOV        dword ptr [EAX + 0x48],this
//                              tplayer.cpp:4283 (46)
//         0051839b     MOV        this,dword ptr [ESP + param_2]
//         0051839f     MOV        dword ptr [EAX],EDX
//         005183a1     MOV        dword ptr [EAX + 0x18],EDX
//         005183a4     MOV        dword ptr [EAX + 0x4c],EDX
//         005183a7     MOV        EDX,0x64
//         005183ac     MOV        dword ptr [EAX + 0x4],0x28
//         005183b3     TEST       this,this
//         005183b5     MOV        dword ptr [EAX + 0x50],0x1e
//         005183bc     MOV        dword ptr [EAX + 0xd4],EDX
//         005183c2     JZ         LAB_005183e6
//         005183c4     CMP        this,0x1
//         005183c7     JZ         LAB_005183e6
//                              tplayer.cpp:4285 (20)
//         005183c9     CMP        this,0x2
//         005183cc     JZ         LAB_005183dd
//         005183ce     CMP        this,0x6
//         005183d1     JZ         LAB_005183dd
//         005183d3     CMP        this,0x8
//         005183d6     JZ         LAB_005183dd
//         005183d8     CMP        this,0x5
//         005183db     JNZ        LAB_005183f0
//                               LAB_005183dd                                                 XREF[3]:     005183cc(j), 005183d1(j),
//                                                                                                         005183d6(j)
//                              tplayer.cpp:4286 (6)
//         005183dd     MOV        dword ptr [EAX + 0x170],EDX
//                              tplayer.cpp:4287 (3)
//         005183e3     RET        0x10
//                               LAB_005183e6                                                 XREF[2]:     005183c2(j), 005183c7(j)
//                              tplayer.cpp:4284 (10)
//         005183e6     MOV        dword ptr [EAX + 0x170],0xc8
//                               LAB_005183f0                                                 XREF[1]:     005183db(j)
//                              tplayer.cpp:4287 (3)
//         005183f0     RET        0x10
//         005183f3     ??         90h
//         005183f4     NOP
//         005183f5     NOP
//         005183f6     NOP
//         005183f7     NOP
//         005183f8     NOP
//         005183f9     NOP
//         005183fa     NOP
//         005183fb     NOP
//         005183fc     NOP
//         005183fd     NOP
//         005183fe     NOP
//         005183ff     NOP
    return;
}

void TRIBE_Player::setupSumerian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupSumerian(TRIBE_Player * this, int * param_1, in
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518444(R), 00518455(R), 00518470(R), 0051848b(R),
//                                                                                     005184aa(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518423(R), 005184d3(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupSumerian@TRIBE_Player@@QAEXPAHHHH@Z                    XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupSumerian
//                              tplayer.cpp:4292 (17)
//         00518400     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518406     PUSH       s_Setting_up_as_Sumerians.                       = "Setting up as Sumerians."
//         0051840b     PUSH       EAX
//         0051840c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4295 (18)
//         00518411     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518417     ADD        ESP,0x8
//         0051841a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         0051841f     CMP        AL,0x1
//         00518421     JNZ        LAB_0051849c
//                              tplayer.cpp:4297 (13)
//         00518423     MOV        EAX,dword ptr [ESP + param_2]
//         00518427     TEST       EAX,EAX
//         00518429     JZ         LAB_0051848b
//         0051842b     CMP        EAX,0x1
//         0051842e     JZ         LAB_0051848b
//                              tplayer.cpp:4299 (10)
//         00518430     CMP        EAX,0x2
//         00518433     JZ         LAB_00518470
//         00518435     CMP        EAX,0x6
//         00518438     JZ         LAB_00518470
//                              tplayer.cpp:4304 (10)
//         0051843a     CMP        EAX,0x5
//         0051843d     JZ         LAB_00518455
//         0051843f     CMP        EAX,0x8
//         00518442     JZ         LAB_00518455
//                              tplayer.cpp:4310 (14)
//         00518444     MOV        this,dword ptr [ESP + param_1]
//         00518448     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4340 (3)
//         00518452     RET        0x10
//                               LAB_00518455                                                 XREF[2]:     0051843d(j), 00518442(j)
//                              tplayer.cpp:4306 (14)
//         00518455     MOV        EAX,dword ptr [ESP + param_1]
//         00518459     MOV        dword ptr [EAX + 0x80],0x50
//                              tplayer.cpp:4307 (10)
//         00518463     MOV        dword ptr [EAX + 0x118],0x14
//                              tplayer.cpp:4340 (3)
//         0051846d     RET        0x10
//                               LAB_00518470                                                 XREF[2]:     00518433(j), 00518438(j)
//                              tplayer.cpp:4301 (14)
//         00518470     MOV        EAX,dword ptr [ESP + param_1]
//         00518474     MOV        dword ptr [EAX + 0x80],0x3c
//                              tplayer.cpp:4302 (10)
//         0051847e     MOV        dword ptr [EAX + 0x118],0x28
//                              tplayer.cpp:4340 (3)
//         00518488     RET        0x10
//                               LAB_0051848b                                                 XREF[2]:     00518429(j), 0051842e(j)
//                              tplayer.cpp:4298 (14)
//         0051848b     MOV        EDX,dword ptr [ESP + param_1]
//         0051848f     MOV        dword ptr [EDX + 0x118],0x64
//                              tplayer.cpp:4340 (3)
//         00518499     RET        0x10
//                               LAB_0051849c                                                 XREF[1]:     00518421(j)
//                              tplayer.cpp:4315 (14)
//         0051849c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005184a2     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         005184a7     CMP        EAX,0x1
//                              tplayer.cpp:4317 (16)
//         005184aa     MOV        EAX,dword ptr [ESP + param_1]
//         005184ae     JGE        LAB_005184bd
//         005184b0     MOV        dword ptr [EAX + 0x98],0x64
//                              tplayer.cpp:4340 (3)
//         005184ba     RET        0x10
//                               LAB_005184bd                                                 XREF[1]:     005184ae(j)
//                              tplayer.cpp:4322 (5)
//         005184bd     MOV        this,0xa
//                              tplayer.cpp:4323 (8)
//         005184c2     MOV        EDX,0x14
//         005184c7     MOV        dword ptr [EAX + 0xc],this
//                              tplayer.cpp:4324 (3)
//         005184ca     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4325 (3)
//         005184cd     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4326 (3)
//         005184d0     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4330 (43)
//         005184d3     MOV        this,dword ptr [ESP + param_2]
//         005184d7     MOV        dword ptr [EAX + 0x10],EDX
//         005184da     MOV        dword ptr [EAX + 0x44],EDX
//         005184dd     MOV        EDX,0x64
//         005184e2     TEST       this,this
//         005184e4     MOV        dword ptr [EAX + 0x40],0x1e
//         005184eb     MOV        dword ptr [EAX + 0xe4],EDX
//         005184f1     MOV        dword ptr [EAX + 0xe8],EDX
//         005184f7     JZ         LAB_00518521
//         005184f9     CMP        this,0x1
//         005184fc     JZ         LAB_00518521
//                              tplayer.cpp:4335 (20)
//         005184fe     CMP        this,0x2
//         00518501     JZ         LAB_00518512
//         00518503     CMP        this,0x6
//         00518506     JZ         LAB_00518512
//         00518508     CMP        this,0x8
//         0051850b     JZ         LAB_00518512
//         0051850d     CMP        this,0x5
//         00518510     JNZ        LAB_00518532
//                               LAB_00518512                                                 XREF[3]:     00518501(j), 00518506(j),
//                                                                                                         0051850b(j)
//                              tplayer.cpp:4337 (6)
//         00518512     MOV        dword ptr [EAX + 0x178],EDX
//                              tplayer.cpp:4338 (6)
//         00518518     MOV        dword ptr [EAX + 0x17c],EDX
//                              tplayer.cpp:4340 (3)
//         0051851e     RET        0x10
//                               LAB_00518521                                                 XREF[2]:     005184f7(j), 005184fc(j)
//                              tplayer.cpp:4332 (11)
//         00518521     MOV        this,0xc8
//         00518526     MOV        dword ptr [EAX + 0x178],this
//                              tplayer.cpp:4333 (6)
//         0051852c     MOV        dword ptr [EAX + 0x17c],this
//                               LAB_00518532                                                 XREF[1]:     00518510(j)
//                              tplayer.cpp:4340 (3)
//         00518532     RET        0x10
//         00518535     ??         90h
//         00518536     NOP
//         00518537     NOP
//         00518538     NOP
//         00518539     NOP
//         0051853a     NOP
//         0051853b     NOP
//         0051853c     NOP
//         0051853d     NOP
//         0051853e     NOP
//         0051853f     NOP
    return;
}

void TRIBE_Player::setupPersian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupPersian(TRIBE_Player * this, int * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518584(R), 00518592(R), 005185aa(R), 005185c2(R),
//                                                                                     005185d3(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518563(R), 005185f5(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupPersian@TRIBE_Player@@QAEXPAHHHH@Z                     XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupPersian
//                              tplayer.cpp:4345 (17)
//         00518540     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518546     PUSH       s_Setting_up_as_Persians.                        = "Setting up as Persians."
//         0051854b     PUSH       EAX
//         0051854c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4348 (18)
//         00518551     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518557     ADD        ESP,0x8
//         0051855a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         0051855f     CMP        AL,0x1
//         00518561     JNZ        LAB_005185d3
//                              tplayer.cpp:4350 (13)
//         00518563     MOV        EAX,dword ptr [ESP + param_2]
//         00518567     TEST       EAX,EAX
//         00518569     JZ         LAB_005185c2
//         0051856b     CMP        EAX,0x1
//         0051856e     JZ         LAB_005185c2
//                              tplayer.cpp:4352 (10)
//         00518570     CMP        EAX,0x2
//         00518573     JZ         LAB_005185aa
//         00518575     CMP        EAX,0x6
//         00518578     JZ         LAB_005185aa
//                              tplayer.cpp:4357 (10)
//         0051857a     CMP        EAX,0x5
//         0051857d     JZ         LAB_00518592
//         0051857f     CMP        EAX,0x8
//         00518582     JZ         LAB_00518592
//                              tplayer.cpp:4363 (11)
//         00518584     MOV        this,dword ptr [ESP + param_1]
//         00518588     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4390 (3)
//         0051858f     RET        0x10
//                               LAB_00518592                                                 XREF[2]:     0051857d(j), 00518582(j)
//                              tplayer.cpp:4359 (11)
//         00518592     MOV        EAX,dword ptr [ESP + param_1]
//         00518596     MOV        dword ptr [EAX + 0x74],0x50
//                              tplayer.cpp:4360 (10)
//         0051859d     MOV        dword ptr [EAX + 0x10c],0x14
//                              tplayer.cpp:4390 (3)
//         005185a7     RET        0x10
//                               LAB_005185aa                                                 XREF[2]:     00518573(j), 00518578(j)
//                              tplayer.cpp:4354 (11)
//         005185aa     MOV        EAX,dword ptr [ESP + param_1]
//         005185ae     MOV        dword ptr [EAX + 0x74],0x3c
//                              tplayer.cpp:4355 (10)
//         005185b5     MOV        dword ptr [EAX + 0x10c],0x28
//                              tplayer.cpp:4390 (3)
//         005185bf     RET        0x10
//                               LAB_005185c2                                                 XREF[2]:     00518569(j), 0051856e(j)
//                              tplayer.cpp:4351 (14)
//         005185c2     MOV        EDX,dword ptr [ESP + param_1]
//         005185c6     MOV        dword ptr [EDX + 0x10c],0x64
//                              tplayer.cpp:4390 (3)
//         005185d0     RET        0x10
//                               LAB_005185d3                                                 XREF[1]:     00518561(j)
//                              tplayer.cpp:4367 (4)
//         005185d3     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4370 (13)
//         005185d7     MOV        this,0xa
//         005185dc     MOV        EDX,0x28
//         005185e1     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4372 (3)
//         005185e4     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4373 (3)
//         005185e7     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4375 (8)
//         005185ea     MOV        this,0x3c
//         005185ef     MOV        dword ptr [EAX + 0x44],this
//                              tplayer.cpp:4376 (3)
//         005185f2     MOV        dword ptr [EAX + 0x48],this
//                              tplayer.cpp:4380 (60)
//         005185f5     MOV        this,dword ptr [ESP + param_2]
//         005185f9     MOV        dword ptr [EAX + 0x4],EDX
//         005185fc     MOV        dword ptr [EAX + 0x2c],EDX
//         005185ff     MOV        dword ptr [EAX + 0x50],EDX
//         00518602     MOV        EDX,0x64
//         00518607     MOV        dword ptr [EAX],0x14
//         0051860d     TEST       this,this
//         0051860f     MOV        dword ptr [EAX + 0x40],0x14
//         00518616     MOV        dword ptr [EAX + 0x1c],0x32
//         0051861d     MOV        dword ptr [EAX + 0x4c],0x14
//         00518624     MOV        dword ptr [EAX + 0xd0],EDX
//         0051862a     JZ         LAB_00518654
//         0051862c     CMP        this,0x1
//         0051862f     JZ         LAB_00518654
//                              tplayer.cpp:4385 (20)
//         00518631     CMP        this,0x2
//         00518634     JZ         LAB_00518645
//         00518636     CMP        this,0x6
//         00518639     JZ         LAB_00518645
//         0051863b     CMP        this,0x8
//         0051863e     JZ         LAB_00518645
//         00518640     CMP        this,0x5
//         00518643     JNZ        LAB_00518665
//                               LAB_00518645                                                 XREF[3]:     00518634(j), 00518639(j),
//                                                                                                         0051863e(j)
//                              tplayer.cpp:4387 (6)
//         00518645     MOV        dword ptr [EAX + 0x168],EDX
//                              tplayer.cpp:4388 (6)
//         0051864b     MOV        dword ptr [EAX + 0x16c],EDX
//                              tplayer.cpp:4390 (3)
//         00518651     RET        0x10
//                               LAB_00518654                                                 XREF[2]:     0051862a(j), 0051862f(j)
//                              tplayer.cpp:4382 (11)
//         00518654     MOV        this,0xc8
//         00518659     MOV        dword ptr [EAX + 0x168],this
//                              tplayer.cpp:4383 (6)
//         0051865f     MOV        dword ptr [EAX + 0x16c],this
//                               LAB_00518665                                                 XREF[1]:     00518643(j)
//                              tplayer.cpp:4390 (3)
//         00518665     RET        0x10
//         00518668     ??         90h
//         00518669     NOP
//         0051866a     NOP
//         0051866b     NOP
//         0051866c     NOP
//         0051866d     NOP
//         0051866e     NOP
//         0051866f     NOP
    return;
}

void TRIBE_Player::setupShang(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupShang(TRIBE_Player * this, int * param_1, int p
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     005186b4(R), 005186c2(R), 005186da(R), 005186f2(R),
//                                                                                     00518703(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518693(R), 0051872d(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupShang@TRIBE_Player@@QAEXPAHHHH@Z                       XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupShang
//                              tplayer.cpp:4395 (17)
//         00518670     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518676     PUSH       s_Setting_up_as_Shang.                           = "Setting up as Shang."
//         0051867b     PUSH       EAX
//         0051867c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4398 (18)
//         00518681     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518687     ADD        ESP,0x8
//         0051868a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         0051868f     CMP        AL,0x1
//         00518691     JNZ        LAB_00518703
//                              tplayer.cpp:4400 (13)
//         00518693     MOV        EAX,dword ptr [ESP + param_2]
//         00518697     TEST       EAX,EAX
//         00518699     JZ         LAB_005186f2
//         0051869b     CMP        EAX,0x1
//         0051869e     JZ         LAB_005186f2
//                              tplayer.cpp:4402 (10)
//         005186a0     CMP        EAX,0x2
//         005186a3     JZ         LAB_005186da
//         005186a5     CMP        EAX,0x6
//         005186a8     JZ         LAB_005186da
//                              tplayer.cpp:4407 (10)
//         005186aa     CMP        EAX,0x5
//         005186ad     JZ         LAB_005186c2
//         005186af     CMP        EAX,0x8
//         005186b2     JZ         LAB_005186c2
//                              tplayer.cpp:4413 (11)
//         005186b4     MOV        this,dword ptr [ESP + param_1]
//         005186b8     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4435 (3)
//         005186bf     RET        0x10
//                               LAB_005186c2                                                 XREF[2]:     005186ad(j), 005186b2(j)
//                              tplayer.cpp:4409 (11)
//         005186c2     MOV        EAX,dword ptr [ESP + param_1]
//         005186c6     MOV        dword ptr [EAX + 0x7c],0x50
//                              tplayer.cpp:4410 (10)
//         005186cd     MOV        dword ptr [EAX + 0x114],0x14
//                              tplayer.cpp:4435 (3)
//         005186d7     RET        0x10
//                               LAB_005186da                                                 XREF[2]:     005186a3(j), 005186a8(j)
//                              tplayer.cpp:4404 (11)
//         005186da     MOV        EAX,dword ptr [ESP + param_1]
//         005186de     MOV        dword ptr [EAX + 0x7c],0x3c
//                              tplayer.cpp:4405 (10)
//         005186e5     MOV        dword ptr [EAX + 0x114],0x28
//                              tplayer.cpp:4435 (3)
//         005186ef     RET        0x10
//                               LAB_005186f2                                                 XREF[2]:     00518699(j), 0051869e(j)
//                              tplayer.cpp:4401 (14)
//         005186f2     MOV        EDX,dword ptr [ESP + param_1]
//         005186f6     MOV        dword ptr [EDX + 0x114],0x64
//                              tplayer.cpp:4435 (3)
//         00518700     RET        0x10
//                               LAB_00518703                                                 XREF[1]:     00518691(j)
//                              tplayer.cpp:4417 (9)
//         00518703     MOV        EAX,dword ptr [ESP + param_1]
//         00518707     MOV        EDX,0xa
//                              tplayer.cpp:4421 (10)
//         0051870c     MOV        this,0x32
//         00518711     MOV        dword ptr [EAX],EDX
//         00518713     MOV        dword ptr [EAX + 0xc],EDX
//                              tplayer.cpp:4423 (3)
//         00518716     MOV        dword ptr [EAX + 0x24],EDX
//                              tplayer.cpp:4424 (3)
//         00518719     MOV        dword ptr [EAX + 0x28],EDX
//                              tplayer.cpp:4425 (11)
//         0051871c     MOV        EDX,0x1e
//         00518721     MOV        dword ptr [EAX + 0x18],this
//         00518724     MOV        dword ptr [EAX + 0x1c],this
//                              tplayer.cpp:4430 (6)
//         00518727     MOV        dword ptr [EAX + 0xe0],this
//                              tplayer.cpp:4431 (57)
//         0051872d     MOV        this,dword ptr [ESP + param_2]
//         00518731     MOV        dword ptr [EAX + 0x2c],EDX
//         00518734     MOV        dword ptr [EAX + 0x50],EDX
//         00518737     MOV        EDX,0x64
//         0051873c     TEST       this,this
//         0051873e     MOV        dword ptr [EAX + 0x4],0x14
//         00518745     MOV        dword ptr [EAX + 0x40],0x14
//         0051874c     MOV        dword ptr [EAX + 0x4c],0x14
//         00518753     MOV        dword ptr [EAX + 0xd8],EDX
//         00518759     MOV        dword ptr [EAX + 0xdc],EDX
//         0051875f     JZ         LAB_00518787
//         00518761     CMP        this,0x1
//         00518764     JZ         LAB_00518787
//                              tplayer.cpp:4433 (20)
//         00518766     CMP        this,0x2
//         00518769     JZ         LAB_0051877a
//         0051876b     CMP        this,0x6
//         0051876e     JZ         LAB_0051877a
//         00518770     CMP        this,0x8
//         00518773     JZ         LAB_0051877a
//         00518775     CMP        this,0x5
//         00518778     JNZ        LAB_00518791
//                               LAB_0051877a                                                 XREF[3]:     00518769(j), 0051876e(j),
//                                                                                                         00518773(j)
//                              tplayer.cpp:4434 (10)
//         0051877a     MOV        dword ptr [EAX + 0x174],0x50
//                              tplayer.cpp:4435 (3)
//         00518784     RET        0x10
//                               LAB_00518787                                                 XREF[2]:     0051875f(j), 00518764(j)
//                              tplayer.cpp:4432 (10)
//         00518787     MOV        dword ptr [EAX + 0x174],0xa0
//                               LAB_00518791                                                 XREF[1]:     00518778(j)
//                              tplayer.cpp:4435 (3)
//         00518791     RET        0x10
//         00518794     ??         90h
//         00518795     NOP
//         00518796     NOP
//         00518797     NOP
//         00518798     NOP
//         00518799     NOP
//         0051879a     NOP
//         0051879b     NOP
//         0051879c     NOP
//         0051879d     NOP
//         0051879e     NOP
//         0051879f     NOP
    return;
}

void TRIBE_Player::setupYamato(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupYamato(TRIBE_Player * this, int * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     005187e4(R), 005187f5(R), 00518810(R), 0051882b(R),
//                                                                                     0051884a(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     005187c3(R), 00518873(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupYamato@TRIBE_Player@@QAEXPAHHHH@Z                      XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupYamato
//                              tplayer.cpp:4440 (17)
//         005187a0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005187a6     PUSH       s_Setting_up_as_Yamato.                          = "Setting up as Yamato."
//         005187ab     PUSH       EAX
//         005187ac     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4443 (18)
//         005187b1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005187b7     ADD        ESP,0x8
//         005187ba     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         005187bf     CMP        AL,0x1
//         005187c1     JNZ        LAB_0051883c
//                              tplayer.cpp:4445 (13)
//         005187c3     MOV        EAX,dword ptr [ESP + param_2]
//         005187c7     TEST       EAX,EAX
//         005187c9     JZ         LAB_0051882b
//         005187cb     CMP        EAX,0x1
//         005187ce     JZ         LAB_0051882b
//                              tplayer.cpp:4447 (10)
//         005187d0     CMP        EAX,0x2
//         005187d3     JZ         LAB_00518810
//         005187d5     CMP        EAX,0x6
//         005187d8     JZ         LAB_00518810
//                              tplayer.cpp:4452 (10)
//         005187da     CMP        EAX,0x5
//         005187dd     JZ         LAB_005187f5
//         005187df     CMP        EAX,0x8
//         005187e2     JZ         LAB_005187f5
//                              tplayer.cpp:4458 (14)
//         005187e4     MOV        this,dword ptr [ESP + param_1]
//         005187e8     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4490 (3)
//         005187f2     RET        0x10
//                               LAB_005187f5                                                 XREF[2]:     005187dd(j), 005187e2(j)
//                              tplayer.cpp:4454 (14)
//         005187f5     MOV        EAX,dword ptr [ESP + param_1]
//         005187f9     MOV        dword ptr [EAX + 0x84],0x50
//                              tplayer.cpp:4455 (10)
//         00518803     MOV        dword ptr [EAX + 0x11c],0x14
//                              tplayer.cpp:4490 (3)
//         0051880d     RET        0x10
//                               LAB_00518810                                                 XREF[2]:     005187d3(j), 005187d8(j)
//                              tplayer.cpp:4449 (14)
//         00518810     MOV        EAX,dword ptr [ESP + param_1]
//         00518814     MOV        dword ptr [EAX + 0x84],0x3c
//                              tplayer.cpp:4450 (10)
//         0051881e     MOV        dword ptr [EAX + 0x11c],0x28
//                              tplayer.cpp:4490 (3)
//         00518828     RET        0x10
//                               LAB_0051882b                                                 XREF[2]:     005187c9(j), 005187ce(j)
//                              tplayer.cpp:4446 (14)
//         0051882b     MOV        EDX,dword ptr [ESP + param_1]
//         0051882f     MOV        dword ptr [EDX + 0x11c],0x64
//                              tplayer.cpp:4490 (3)
//         00518839     RET        0x10
//                               LAB_0051883c                                                 XREF[1]:     005187c1(j)
//                              tplayer.cpp:4463 (14)
//         0051883c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518842     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         00518847     CMP        EAX,0x1
//                              tplayer.cpp:4465 (16)
//         0051884a     MOV        EAX,dword ptr [ESP + param_1]
//         0051884e     JGE        LAB_0051885d
//         00518850     MOV        dword ptr [EAX + 0x9c],0x64
//                              tplayer.cpp:4490 (3)
//         0051885a     RET        0x10
//                               LAB_0051885d                                                 XREF[1]:     0051884e(j)
//                              tplayer.cpp:4472 (5)
//         0051885d     MOV        this,0xa
//                              tplayer.cpp:4474 (11)
//         00518862     MOV        EDX,0x32
//         00518867     MOV        dword ptr [EAX + 0xc],this
//         0051886a     MOV        dword ptr [EAX + 0x10],this
//                              tplayer.cpp:4476 (3)
//         0051886d     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4477 (3)
//         00518870     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4480 (57)
//         00518873     MOV        this,dword ptr [ESP + param_2]
//         00518877     MOV        dword ptr [EAX + 0x18],EDX
//         0051887a     MOV        dword ptr [EAX + 0x1c],EDX
//         0051887d     MOV        EDX,0x64
//         00518882     TEST       this,this
//         00518884     MOV        dword ptr [EAX],0x14
//         0051888a     MOV        dword ptr [EAX + 0x4],0x14
//         00518891     MOV        dword ptr [EAX + 0x40],0x28
//         00518898     MOV        dword ptr [EAX + 0x2c],0x14
//         0051889f     MOV        dword ptr [EAX + 0xec],EDX
//         005188a5     JZ         LAB_005188cf
//         005188a7     CMP        this,0x1
//         005188aa     JZ         LAB_005188cf
//                              tplayer.cpp:4485 (20)
//         005188ac     CMP        this,0x2
//         005188af     JZ         LAB_005188c0
//         005188b1     CMP        this,0x6
//         005188b4     JZ         LAB_005188c0
//         005188b6     CMP        this,0x8
//         005188b9     JZ         LAB_005188c0
//         005188bb     CMP        this,0x5
//         005188be     JNZ        LAB_005188e0
//                               LAB_005188c0                                                 XREF[3]:     005188af(j), 005188b4(j),
//                                                                                                         005188b9(j)
//                              tplayer.cpp:4487 (6)
//         005188c0     MOV        dword ptr [EAX + 0x180],EDX
//                              tplayer.cpp:4488 (6)
//         005188c6     MOV        dword ptr [EAX + 0x184],EDX
//                              tplayer.cpp:4490 (3)
//         005188cc     RET        0x10
//                               LAB_005188cf                                                 XREF[2]:     005188a5(j), 005188aa(j)
//                              tplayer.cpp:4482 (11)
//         005188cf     MOV        this,0xc8
//         005188d4     MOV        dword ptr [EAX + 0x180],this
//                              tplayer.cpp:4483 (6)
//         005188da     MOV        dword ptr [EAX + 0x184],this
//                               LAB_005188e0                                                 XREF[1]:     005188be(j)
//                              tplayer.cpp:4490 (3)
//         005188e0     RET        0x10
//         005188e3     ??         90h
//         005188e4     NOP
//         005188e5     NOP
//         005188e6     NOP
//         005188e7     NOP
//         005188e8     NOP
//         005188e9     NOP
//         005188ea     NOP
//         005188eb     NOP
//         005188ec     NOP
//         005188ed     NOP
//         005188ee     NOP
//         005188ef     NOP
    return;
}

void TRIBE_Player::setupChoson(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupChoson(TRIBE_Player * this, int * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518934(R), 00518942(R), 0051895a(R), 00518972(R),
//                                                                                     00518983(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518913(R), 005189a8(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupChoson@TRIBE_Player@@QAEXPAHHHH@Z                      XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupChoson
//                              tplayer.cpp:4495 (17)
//         005188f0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005188f6     PUSH       s_Setting_up_as_Choson.                          = "Setting up as Choson."
//         005188fb     PUSH       EAX
//         005188fc     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4498 (18)
//         00518901     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518907     ADD        ESP,0x8
//         0051890a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         0051890f     CMP        AL,0x1
//         00518911     JNZ        LAB_00518983
//                              tplayer.cpp:4500 (13)
//         00518913     MOV        EAX,dword ptr [ESP + param_2]
//         00518917     TEST       EAX,EAX
//         00518919     JZ         LAB_00518972
//         0051891b     CMP        EAX,0x1
//         0051891e     JZ         LAB_00518972
//                              tplayer.cpp:4502 (10)
//         00518920     CMP        EAX,0x2
//         00518923     JZ         LAB_0051895a
//         00518925     CMP        EAX,0x6
//         00518928     JZ         LAB_0051895a
//                              tplayer.cpp:4507 (10)
//         0051892a     CMP        EAX,0x5
//         0051892d     JZ         LAB_00518942
//         0051892f     CMP        EAX,0x8
//         00518932     JZ         LAB_00518942
//                              tplayer.cpp:4513 (11)
//         00518934     MOV        this,dword ptr [ESP + param_1]
//         00518938     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4540 (3)
//         0051893f     RET        0x10
//                               LAB_00518942                                                 XREF[2]:     0051892d(j), 00518932(j)
//                              tplayer.cpp:4509 (11)
//         00518942     MOV        EAX,dword ptr [ESP + param_1]
//         00518946     MOV        dword ptr [EAX + 0x60],0x50
//                              tplayer.cpp:4510 (10)
//         0051894d     MOV        dword ptr [EAX + 0xf8],0x14
//                              tplayer.cpp:4540 (3)
//         00518957     RET        0x10
//                               LAB_0051895a                                                 XREF[2]:     00518923(j), 00518928(j)
//                              tplayer.cpp:4504 (11)
//         0051895a     MOV        EAX,dword ptr [ESP + param_1]
//         0051895e     MOV        dword ptr [EAX + 0x60],0x3c
//                              tplayer.cpp:4505 (10)
//         00518965     MOV        dword ptr [EAX + 0xf8],0x28
//                              tplayer.cpp:4540 (3)
//         0051896f     RET        0x10
//                               LAB_00518972                                                 XREF[2]:     00518919(j), 0051891e(j)
//                              tplayer.cpp:4501 (14)
//         00518972     MOV        EDX,dword ptr [ESP + param_1]
//         00518976     MOV        dword ptr [EDX + 0xf8],0x64
//                              tplayer.cpp:4540 (3)
//         00518980     RET        0x10
//                               LAB_00518983                                                 XREF[1]:     00518911(j)
//                              tplayer.cpp:4517 (4)
//         00518983     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4518 (5)
//         00518987     MOV        this,0xa
//                              tplayer.cpp:4528 (28)
//         0051898c     MOV        EDX,0x64
//         00518991     MOV        dword ptr [EAX + 0x4],this
//         00518994     MOV        dword ptr [EAX + 0x40],this
//         00518997     MOV        dword ptr [EAX + 0xc],this
//         0051899a     MOV        this,0x1e
//         0051899f     MOV        dword ptr [EAX + 0x1c],this
//         005189a2     MOV        dword ptr [EAX + 0x24],this
//         005189a5     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4530 (59)
//         005189a8     MOV        this,dword ptr [ESP + param_2]
//         005189ac     TEST       this,this
//         005189ae     MOV        dword ptr [EAX],0x14
//         005189b4     MOV        dword ptr [EAX + 0x18],0x14
//         005189bb     MOV        dword ptr [EAX + 0x2c],0x46
//         005189c2     MOV        dword ptr [EAX + 0x4c],0x32
//         005189c9     MOV        dword ptr [EAX + 0x50],0x5a
//         005189d0     MOV        dword ptr [EAX + 0xb0],EDX
//         005189d6     MOV        dword ptr [EAX + 0xb4],EDX
//         005189dc     JZ         LAB_00518a06
//         005189de     CMP        this,0x1
//         005189e1     JZ         LAB_00518a06
//                              tplayer.cpp:4535 (20)
//         005189e3     CMP        this,0x2
//         005189e6     JZ         LAB_005189f7
//         005189e8     CMP        this,0x6
//         005189eb     JZ         LAB_005189f7
//         005189ed     CMP        this,0x8
//         005189f0     JZ         LAB_005189f7
//         005189f2     CMP        this,0x5
//         005189f5     JNZ        LAB_00518a17
//                               LAB_005189f7                                                 XREF[3]:     005189e6(j), 005189eb(j),
//                                                                                                         005189f0(j)
//                              tplayer.cpp:4537 (6)
//         005189f7     MOV        dword ptr [EAX + 0x138],EDX
//                              tplayer.cpp:4538 (6)
//         005189fd     MOV        dword ptr [EAX + 0x13c],EDX
//                              tplayer.cpp:4540 (3)
//         00518a03     RET        0x10
//                               LAB_00518a06                                                 XREF[2]:     005189dc(j), 005189e1(j)
//                              tplayer.cpp:4532 (11)
//         00518a06     MOV        this,0xc8
//         00518a0b     MOV        dword ptr [EAX + 0x138],this
//                              tplayer.cpp:4533 (6)
//         00518a11     MOV        dword ptr [EAX + 0x13c],this
//                               LAB_00518a17                                                 XREF[1]:     005189f5(j)
//                              tplayer.cpp:4540 (3)
//         00518a17     RET        0x10
//         00518a1a     ??         90h
//         00518a1b     NOP
//         00518a1c     NOP
//         00518a1d     NOP
//         00518a1e     NOP
//         00518a1f     NOP
    return;
}

void TRIBE_Player::setupRoman(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupRoman(TRIBE_Player * this, int * param_1, int p
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518a64(R), 00518a75(R), 00518a90(R), 00518aab(R),
//                                                                                     00518abc(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518a43(R), 00518adb(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupRoman@TRIBE_Player@@QAEXPAHHHH@Z                       XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupRoman
//                              tplayer.cpp:4545 (17)
//         00518a20     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518a26     PUSH       s_Setting_up_as_Roman.                           = "Setting up as Roman."
//         00518a2b     PUSH       EAX
//         00518a2c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4548 (18)
//         00518a31     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518a37     ADD        ESP,0x8
//         00518a3a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00518a3f     CMP        AL,0x1
//         00518a41     JNZ        LAB_00518abc
//                              tplayer.cpp:4550 (13)
//         00518a43     MOV        EAX,dword ptr [ESP + param_2]
//         00518a47     TEST       EAX,EAX
//         00518a49     JZ         LAB_00518aab
//         00518a4b     CMP        EAX,0x1
//         00518a4e     JZ         LAB_00518aab
//                              tplayer.cpp:4552 (10)
//         00518a50     CMP        EAX,0x2
//         00518a53     JZ         LAB_00518a90
//         00518a55     CMP        EAX,0x6
//         00518a58     JZ         LAB_00518a90
//                              tplayer.cpp:4557 (10)
//         00518a5a     CMP        EAX,0x5
//         00518a5d     JZ         LAB_00518a75
//         00518a5f     CMP        EAX,0x8
//         00518a62     JZ         LAB_00518a75
//                              tplayer.cpp:4563 (14)
//         00518a64     MOV        this,dword ptr [ESP + param_1]
//         00518a68     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4589 (3)
//         00518a72     RET        0x10
//                               LAB_00518a75                                                 XREF[2]:     00518a5d(j), 00518a62(j)
//                              tplayer.cpp:4559 (14)
//         00518a75     MOV        EAX,dword ptr [ESP + param_1]
//         00518a79     MOV        dword ptr [EAX + 0x1e0],0x50
//                              tplayer.cpp:4560 (10)
//         00518a83     MOV        dword ptr [EAX + 0x1f0],0x14
//                              tplayer.cpp:4589 (3)
//         00518a8d     RET        0x10
//                               LAB_00518a90                                                 XREF[2]:     00518a53(j), 00518a58(j)
//                              tplayer.cpp:4554 (14)
//         00518a90     MOV        EAX,dword ptr [ESP + param_1]
//         00518a94     MOV        dword ptr [EAX + 0x1e0],0x3c
//                              tplayer.cpp:4555 (10)
//         00518a9e     MOV        dword ptr [EAX + 0x1f0],0x28
//                              tplayer.cpp:4589 (3)
//         00518aa8     RET        0x10
//                               LAB_00518aab                                                 XREF[2]:     00518a49(j), 00518a4e(j)
//                              tplayer.cpp:4551 (14)
//         00518aab     MOV        EDX,dword ptr [ESP + param_1]
//         00518aaf     MOV        dword ptr [EDX + 0x1f0],0x64
//                              tplayer.cpp:4589 (3)
//         00518ab9     RET        0x10
//                               LAB_00518abc                                                 XREF[1]:     00518a41(j)
//                              tplayer.cpp:4567 (9)
//         00518abc     MOV        EAX,dword ptr [ESP + param_1]
//         00518ac0     MOV        this,0xa
//                              tplayer.cpp:4568 (7)
//         00518ac5     MOV        EDX,0x14
//         00518aca     MOV        dword ptr [EAX],this
//                              tplayer.cpp:4570 (3)
//         00518acc     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4571 (3)
//         00518acf     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4572 (3)
//         00518ad2     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4574 (3)
//         00518ad5     MOV        dword ptr [EAX + 0x4c],this
//                              tplayer.cpp:4575 (3)
//         00518ad8     MOV        dword ptr [EAX + 0x50],this
//                              tplayer.cpp:4579 (53)
//         00518adb     MOV        this,dword ptr [ESP + param_2]
//         00518adf     MOV        dword ptr [EAX + 0xc],EDX
//         00518ae2     MOV        dword ptr [EAX + 0x10],EDX
//         00518ae5     MOV        EDX,0x50
//         00518aea     TEST       this,this
//         00518aec     MOV        dword ptr [EAX + 0x2c],EDX
//         00518aef     MOV        dword ptr [EAX + 0x1c0],0x64
//         00518af9     MOV        dword ptr [EAX + 0x1c4],0x3c
//         00518b03     MOV        dword ptr [EAX + 0x1c8],EDX
//         00518b09     JZ         LAB_00518b3b
//         00518b0b     CMP        this,0x1
//         00518b0e     JZ         LAB_00518b3b
//                              tplayer.cpp:4584 (20)
//         00518b10     CMP        this,0x2
//         00518b13     JZ         LAB_00518b24
//         00518b15     CMP        this,0x6
//         00518b18     JZ         LAB_00518b24
//         00518b1a     CMP        this,0x8
//         00518b1d     JZ         LAB_00518b24
//         00518b1f     CMP        this,0x5
//         00518b22     JNZ        LAB_00518b4c
//                               LAB_00518b24                                                 XREF[3]:     00518b13(j), 00518b18(j),
//                                                                                                         00518b1d(j)
//                              tplayer.cpp:4586 (10)
//         00518b24     MOV        dword ptr [EAX + 0x1cc],0x64
//                              tplayer.cpp:4587 (10)
//         00518b2e     MOV        dword ptr [EAX + 0x1d0],0x64
//                              tplayer.cpp:4589 (3)
//         00518b38     RET        0x10
//                               LAB_00518b3b                                                 XREF[2]:     00518b09(j), 00518b0e(j)
//                              tplayer.cpp:4581 (11)
//         00518b3b     MOV        this,0xc8
//         00518b40     MOV        dword ptr [EAX + 0x1cc],this
//                              tplayer.cpp:4582 (6)
//         00518b46     MOV        dword ptr [EAX + 0x1d0],this
//                               LAB_00518b4c                                                 XREF[1]:     00518b22(j)
//                              tplayer.cpp:4589 (3)
//         00518b4c     RET        0x10
//         00518b4f     ??         90h
    return;
}

void TRIBE_Player::setupCarthaginian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupCarthaginian(TRIBE_Player * this, int * param_1
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518b94(R), 00518ba5(R), 00518bc0(R), 00518bdb(R),
//                                                                                     00518bec(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518b73(R), 00518c2c(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupCarthaginian@TRIBE_Player@@QAEXPAHHHH@Z                XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupCarthaginian
//                              tplayer.cpp:4594 (17)
//         00518b50     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518b56     PUSH       s_Setting_up_as_Carthaginian.                    = "Setting up as Carthaginian."
//         00518b5b     PUSH       EAX
//         00518b5c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4597 (18)
//         00518b61     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518b67     ADD        ESP,0x8
//         00518b6a     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00518b6f     CMP        AL,0x1
//         00518b71     JNZ        LAB_00518bec
//                              tplayer.cpp:4599 (13)
//         00518b73     MOV        EAX,dword ptr [ESP + param_2]
//         00518b77     TEST       EAX,EAX
//         00518b79     JZ         LAB_00518bdb
//         00518b7b     CMP        EAX,0x1
//         00518b7e     JZ         LAB_00518bdb
//                              tplayer.cpp:4601 (10)
//         00518b80     CMP        EAX,0x2
//         00518b83     JZ         LAB_00518bc0
//         00518b85     CMP        EAX,0x6
//         00518b88     JZ         LAB_00518bc0
//                              tplayer.cpp:4606 (10)
//         00518b8a     CMP        EAX,0x5
//         00518b8d     JZ         LAB_00518ba5
//         00518b8f     CMP        EAX,0x8
//         00518b92     JZ         LAB_00518ba5
//                              tplayer.cpp:4612 (14)
//         00518b94     MOV        this,dword ptr [ESP + param_1]
//         00518b98     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4640 (3)
//         00518ba2     RET        0x10
//                               LAB_00518ba5                                                 XREF[2]:     00518b8d(j), 00518b92(j)
//                              tplayer.cpp:4608 (14)
//         00518ba5     MOV        EAX,dword ptr [ESP + param_1]
//         00518ba9     MOV        dword ptr [EAX + 0x1d4],0x50
//                              tplayer.cpp:4609 (10)
//         00518bb3     MOV        dword ptr [EAX + 0x1e4],0x14
//                              tplayer.cpp:4640 (3)
//         00518bbd     RET        0x10
//                               LAB_00518bc0                                                 XREF[2]:     00518b83(j), 00518b88(j)
//                              tplayer.cpp:4603 (14)
//         00518bc0     MOV        EAX,dword ptr [ESP + param_1]
//         00518bc4     MOV        dword ptr [EAX + 0x1d4],0x3c
//                              tplayer.cpp:4604 (10)
//         00518bce     MOV        dword ptr [EAX + 0x1e4],0x28
//                              tplayer.cpp:4640 (3)
//         00518bd8     RET        0x10
//                               LAB_00518bdb                                                 XREF[2]:     00518b79(j), 00518b7e(j)
//                              tplayer.cpp:4600 (14)
//         00518bdb     MOV        EDX,dword ptr [ESP + param_1]
//         00518bdf     MOV        dword ptr [EDX + 0x1e4],0x64
//                              tplayer.cpp:4640 (3)
//         00518be9     RET        0x10
//                               LAB_00518bec                                                 XREF[1]:     00518b71(j)
//                              tplayer.cpp:4616 (11)
//         00518bec     MOV        EAX,dword ptr [ESP + param_1]
//         00518bf0     MOV        this,0xa
//         00518bf5     MOV        dword ptr [EAX],this
//                              tplayer.cpp:4617 (3)
//         00518bf7     MOV        dword ptr [EAX + 0x4],this
//                              tplayer.cpp:4618 (3)
//         00518bfa     MOV        dword ptr [EAX + 0x40],this
//                              tplayer.cpp:4622 (3)
//         00518bfd     MOV        dword ptr [EAX + 0x1c],this
//                              tplayer.cpp:4623 (3)
//         00518c00     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4624 (3)
//         00518c03     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4625 (3)
//         00518c06     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4626 (8)
//         00518c09     MOV        this,0x3c
//         00518c0e     MOV        dword ptr [EAX + 0x44],this
//                              tplayer.cpp:4627 (3)
//         00518c11     MOV        dword ptr [EAX + 0x48],this
//                              tplayer.cpp:4628 (18)
//         00518c14     MOV        this,0x50
//         00518c19     MOV        dword ptr [EAX + 0xc],0x46
//         00518c20     MOV        dword ptr [EAX + 0x188],this
//                              tplayer.cpp:4629 (6)
//         00518c26     MOV        dword ptr [EAX + 0x18c],this
//                              tplayer.cpp:4630 (27)
//         00518c2c     MOV        this,dword ptr [ESP + param_2]
//         00518c30     MOV        dword ptr [EAX + 0x10],0x32
//         00518c37     TEST       this,this
//         00518c39     MOV        dword ptr [EAX + 0x18],0x1e
//         00518c40     JZ         LAB_00518c6f
//         00518c42     CMP        this,0x1
//         00518c45     JZ         LAB_00518c6f
//                              tplayer.cpp:4635 (20)
//         00518c47     CMP        this,0x2
//         00518c4a     JZ         LAB_00518c5b
//         00518c4c     CMP        this,0x6
//         00518c4f     JZ         LAB_00518c5b
//         00518c51     CMP        this,0x8
//         00518c54     JZ         LAB_00518c5b
//         00518c56     CMP        this,0x5
//         00518c59     JNZ        LAB_00518c80
//                               LAB_00518c5b                                                 XREF[3]:     00518c4a(j), 00518c4f(j),
//                                                                                                         00518c54(j)
//                              tplayer.cpp:4637 (17)
//         00518c5b     MOV        this,0x64
//         00518c60     MOV        dword ptr [EAX + 0x190],this
//         00518c66     MOV        dword ptr [EAX + 0x194],this
//                              tplayer.cpp:4640 (3)
//         00518c6c     RET        0x10
//                               LAB_00518c6f                                                 XREF[2]:     00518c40(j), 00518c45(j)
//                              tplayer.cpp:4632 (11)
//         00518c6f     MOV        this,0xc8
//         00518c74     MOV        dword ptr [EAX + 0x190],this
//                              tplayer.cpp:4633 (6)
//         00518c7a     MOV        dword ptr [EAX + 0x194],this
//                               LAB_00518c80                                                 XREF[1]:     00518c59(j)
//                              tplayer.cpp:4640 (3)
//         00518c80     RET        0x10
//         00518c83     ??         90h
//         00518c84     NOP
//         00518c85     NOP
//         00518c86     NOP
//         00518c87     NOP
//         00518c88     NOP
//         00518c89     NOP
//         00518c8a     NOP
//         00518c8b     NOP
//         00518c8c     NOP
//         00518c8d     NOP
//         00518c8e     NOP
//         00518c8f     NOP
    return;
}

void TRIBE_Player::setupPalmyran(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupPalmyran(TRIBE_Player * this, int * param_1, in
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518cd4(R), 00518ce5(R), 00518d00(R), 00518d1b(R),
//                                                                                     00518d2c(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518cb3(R), 00518d75(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupPalmyran@TRIBE_Player@@QAEXPAHHHH@Z                    XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupPalmyran
//                              tplayer.cpp:4645 (17)
//         00518c90     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518c96     PUSH       s_Setting_up_as_Palmyran.                        = "Setting up as Palmyran."
//         00518c9b     PUSH       EAX
//         00518c9c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4648 (18)
//         00518ca1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518ca7     ADD        ESP,0x8
//         00518caa     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00518caf     CMP        AL,0x1
//         00518cb1     JNZ        LAB_00518d2c
//                              tplayer.cpp:4650 (13)
//         00518cb3     MOV        EAX,dword ptr [ESP + param_2]
//         00518cb7     TEST       EAX,EAX
//         00518cb9     JZ         LAB_00518d1b
//         00518cbb     CMP        EAX,0x1
//         00518cbe     JZ         LAB_00518d1b
//                              tplayer.cpp:4652 (10)
//         00518cc0     CMP        EAX,0x2
//         00518cc3     JZ         LAB_00518d00
//         00518cc5     CMP        EAX,0x6
//         00518cc8     JZ         LAB_00518d00
//                              tplayer.cpp:4657 (10)
//         00518cca     CMP        EAX,0x5
//         00518ccd     JZ         LAB_00518ce5
//         00518ccf     CMP        EAX,0x8
//         00518cd2     JZ         LAB_00518ce5
//                              tplayer.cpp:4663 (14)
//         00518cd4     MOV        this,dword ptr [ESP + param_1]
//         00518cd8     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4691 (3)
//         00518ce2     RET        0x10
//                               LAB_00518ce5                                                 XREF[2]:     00518ccd(j), 00518cd2(j)
//                              tplayer.cpp:4659 (14)
//         00518ce5     MOV        EAX,dword ptr [ESP + param_1]
//         00518ce9     MOV        dword ptr [EAX + 0x1dc],0x50
//                              tplayer.cpp:4660 (10)
//         00518cf3     MOV        dword ptr [EAX + 0x1ec],0x14
//                              tplayer.cpp:4691 (3)
//         00518cfd     RET        0x10
//                               LAB_00518d00                                                 XREF[2]:     00518cc3(j), 00518cc8(j)
//                              tplayer.cpp:4654 (14)
//         00518d00     MOV        EAX,dword ptr [ESP + param_1]
//         00518d04     MOV        dword ptr [EAX + 0x1dc],0x3c
//                              tplayer.cpp:4655 (10)
//         00518d0e     MOV        dword ptr [EAX + 0x1ec],0x28
//                              tplayer.cpp:4691 (3)
//         00518d18     RET        0x10
//                               LAB_00518d1b                                                 XREF[2]:     00518cb9(j), 00518cbe(j)
//                              tplayer.cpp:4651 (14)
//         00518d1b     MOV        EDX,dword ptr [ESP + param_1]
//         00518d1f     MOV        dword ptr [EDX + 0x1ec],0x64
//                              tplayer.cpp:4691 (3)
//         00518d29     RET        0x10
//                               LAB_00518d2c                                                 XREF[1]:     00518cb1(j)
//                              tplayer.cpp:4667 (4)
//         00518d2c     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4670 (13)
//         00518d30     MOV        this,0x28
//         00518d35     MOV        EDX,0x3c
//         00518d3a     MOV        dword ptr [EAX + 0xc],this
//                              tplayer.cpp:4672 (3)
//         00518d3d     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4673 (14)
//         00518d40     MOV        this,0xa
//         00518d45     MOV        dword ptr [EAX],0x1e
//         00518d4b     MOV        dword ptr [EAX + 0x1c],this
//                              tplayer.cpp:4674 (3)
//         00518d4e     MOV        dword ptr [EAX + 0x24],this
//                              tplayer.cpp:4675 (3)
//         00518d51     MOV        dword ptr [EAX + 0x28],this
//                              tplayer.cpp:4676 (3)
//         00518d54     MOV        dword ptr [EAX + 0x2c],this
//                              tplayer.cpp:4678 (18)
//         00518d57     MOV        this,0x50
//         00518d5c     MOV        dword ptr [EAX + 0x4],0x1e
//         00518d63     MOV        dword ptr [EAX + 0x1ac],this
//                              tplayer.cpp:4679 (6)
//         00518d69     MOV        dword ptr [EAX + 0x1b0],this
//                              tplayer.cpp:4680 (6)
//         00518d6f     MOV        dword ptr [EAX + 0x1b4],this
//                              tplayer.cpp:4681 (26)
//         00518d75     MOV        this,dword ptr [ESP + param_2]
//         00518d79     TEST       this,this
//         00518d7b     MOV        dword ptr [EAX + 0x40],EDX
//         00518d7e     MOV        dword ptr [EAX + 0x10],0x14
//         00518d85     MOV        dword ptr [EAX + 0x44],EDX
//         00518d88     JZ         LAB_00518db7
//         00518d8a     CMP        this,0x1
//         00518d8d     JZ         LAB_00518db7
//                              tplayer.cpp:4686 (20)
//         00518d8f     CMP        this,0x2
//         00518d92     JZ         LAB_00518da3
//         00518d94     CMP        this,0x6
//         00518d97     JZ         LAB_00518da3
//         00518d99     CMP        this,0x8
//         00518d9c     JZ         LAB_00518da3
//         00518d9e     CMP        this,0x5
//         00518da1     JNZ        LAB_00518dc8
//                               LAB_00518da3                                                 XREF[3]:     00518d92(j), 00518d97(j),
//                                                                                                         00518d9c(j)
//                              tplayer.cpp:4688 (17)
//         00518da3     MOV        this,0x64
//         00518da8     MOV        dword ptr [EAX + 0x1b8],this
//         00518dae     MOV        dword ptr [EAX + 0x1bc],this
//                              tplayer.cpp:4691 (3)
//         00518db4     RET        0x10
//                               LAB_00518db7                                                 XREF[2]:     00518d88(j), 00518d8d(j)
//                              tplayer.cpp:4683 (11)
//         00518db7     MOV        this,0xc8
//         00518dbc     MOV        dword ptr [EAX + 0x1b8],this
//                              tplayer.cpp:4684 (6)
//         00518dc2     MOV        dword ptr [EAX + 0x1bc],this
//                               LAB_00518dc8                                                 XREF[1]:     00518da1(j)
//                              tplayer.cpp:4691 (3)
//         00518dc8     RET        0x10
//         00518dcb     ??         90h
//         00518dcc     NOP
//         00518dcd     NOP
//         00518dce     NOP
//         00518dcf     NOP
    return;
}

void TRIBE_Player::setupMacedonian(int* param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall setupMacedonian(TRIBE_Player * this, int * param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int *             Stack[0x4]:4   param_1                   XREF[5]:     00518e14(R), 00518e25(R), 00518e40(R), 00518e5b(R),
//                                                                                     00518e6c(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00518df3(R), 00518ea6(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?setupMacedonian@TRIBE_Player@@QAEXPAHHHH@Z                  XREF[1]:     intelligentBuildListAndRulesSelect
//                               TRIBE_Player::setupMacedonian
//                              tplayer.cpp:4696 (17)
//         00518dd0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         00518dd6     PUSH       s_Setting_up_as_Macedonian.                      = "Setting up as Macedonian."
//         00518ddb     PUSH       EAX
//         00518ddc     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              tplayer.cpp:4699 (18)
//         00518de1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518de7     ADD        ESP,0x8
//         00518dea     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         00518def     CMP        AL,0x1
//         00518df1     JNZ        LAB_00518e6c
//                              tplayer.cpp:4701 (13)
//         00518df3     MOV        EAX,dword ptr [ESP + param_2]
//         00518df7     TEST       EAX,EAX
//         00518df9     JZ         LAB_00518e5b
//         00518dfb     CMP        EAX,0x1
//         00518dfe     JZ         LAB_00518e5b
//                              tplayer.cpp:4703 (10)
//         00518e00     CMP        EAX,0x2
//         00518e03     JZ         LAB_00518e40
//         00518e05     CMP        EAX,0x6
//         00518e08     JZ         LAB_00518e40
//                              tplayer.cpp:4708 (10)
//         00518e0a     CMP        EAX,0x5
//         00518e0d     JZ         LAB_00518e25
//         00518e0f     CMP        EAX,0x8
//         00518e12     JZ         LAB_00518e25
//                              tplayer.cpp:4714 (14)
//         00518e14     MOV        this,dword ptr [ESP + param_1]
//         00518e18     MOV        dword ptr [ECX + this->_padding_],0x64
//                              tplayer.cpp:4739 (3)
//         00518e22     RET        0x10
//                               LAB_00518e25                                                 XREF[2]:     00518e0d(j), 00518e12(j)
//                              tplayer.cpp:4710 (14)
//         00518e25     MOV        EAX,dword ptr [ESP + param_1]
//         00518e29     MOV        dword ptr [EAX + 0x1d8],0x50
//                              tplayer.cpp:4711 (10)
//         00518e33     MOV        dword ptr [EAX + 0x1e8],0x14
//                              tplayer.cpp:4739 (3)
//         00518e3d     RET        0x10
//                               LAB_00518e40                                                 XREF[2]:     00518e03(j), 00518e08(j)
//                              tplayer.cpp:4705 (14)
//         00518e40     MOV        EAX,dword ptr [ESP + param_1]
//         00518e44     MOV        dword ptr [EAX + 0x1d8],0x3c
//                              tplayer.cpp:4706 (10)
//         00518e4e     MOV        dword ptr [EAX + 0x1e8],0x28
//                              tplayer.cpp:4739 (3)
//         00518e58     RET        0x10
//                               LAB_00518e5b                                                 XREF[2]:     00518df9(j), 00518dfe(j)
//                              tplayer.cpp:4702 (14)
//         00518e5b     MOV        EDX,dword ptr [ESP + param_1]
//         00518e5f     MOV        dword ptr [EDX + 0x1e8],0x64
//                              tplayer.cpp:4739 (3)
//         00518e69     RET        0x10
//                               LAB_00518e6c                                                 XREF[1]:     00518df1(j)
//                              tplayer.cpp:4718 (4)
//         00518e6c     MOV        EAX,dword ptr [ESP + param_1]
//                              tplayer.cpp:4721 (8)
//         00518e70     MOV        this,0x28
//         00518e75     MOV        dword ptr [EAX + 0xc],this
//                              tplayer.cpp:4722 (3)
//         00518e78     MOV        dword ptr [EAX + 0x10],this
//                              tplayer.cpp:4723 (14)
//         00518e7b     MOV        this,0x1e
//         00518e80     MOV        dword ptr [EAX],0xa
//         00518e86     MOV        dword ptr [EAX + 0x18],this
//                              tplayer.cpp:4724 (3)
//         00518e89     MOV        dword ptr [EAX + 0x1c],this
//                              tplayer.cpp:4725 (3)
//         00518e8c     MOV        dword ptr [EAX + 0x44],this
//                              tplayer.cpp:4726 (11)
//         00518e8f     MOV        this,0x50
//         00518e94     MOV        dword ptr [EAX + 0x1a0],this
//                              tplayer.cpp:4727 (6)
//         00518e9a     MOV        dword ptr [EAX + 0x198],this
//                              tplayer.cpp:4728 (6)
//         00518ea0     MOV        dword ptr [EAX + 0x19c],this
//                              tplayer.cpp:4729 (27)
//         00518ea6     MOV        this,dword ptr [ESP + param_2]
//         00518eaa     TEST       this,this
//         00518eac     MOV        dword ptr [EAX + 0x4],0xa
//         00518eb3     MOV        dword ptr [EAX + 0x40],0x14
//         00518eba     JZ         LAB_00518ee9
//         00518ebc     CMP        this,0x1
//         00518ebf     JZ         LAB_00518ee9
//                              tplayer.cpp:4734 (20)
//         00518ec1     CMP        this,0x2
//         00518ec4     JZ         LAB_00518ed5
//         00518ec6     CMP        this,0x6
//         00518ec9     JZ         LAB_00518ed5
//         00518ecb     CMP        this,0x8
//         00518ece     JZ         LAB_00518ed5
//         00518ed0     CMP        this,0x5
//         00518ed3     JNZ        LAB_00518efa
//                               LAB_00518ed5                                                 XREF[3]:     00518ec4(j), 00518ec9(j),
//                                                                                                         00518ece(j)
//                              tplayer.cpp:4736 (17)
//         00518ed5     MOV        this,0x64
//         00518eda     MOV        dword ptr [EAX + 0x1a4],this
//         00518ee0     MOV        dword ptr [EAX + 0x1a8],this
//                              tplayer.cpp:4739 (3)
//         00518ee6     RET        0x10
//                               LAB_00518ee9                                                 XREF[2]:     00518eba(j), 00518ebf(j)
//                              tplayer.cpp:4731 (11)
//         00518ee9     MOV        this,0xc8
//         00518eee     MOV        dword ptr [EAX + 0x1a4],this
//                              tplayer.cpp:4732 (6)
//         00518ef4     MOV        dword ptr [EAX + 0x1a8],this
//                               LAB_00518efa                                                 XREF[1]:     00518ed3(j)
//                              tplayer.cpp:4739 (3)
//         00518efa     RET        0x10
//         00518efd     ??         90h
//         00518efe     NOP
//         00518eff     NOP
    return;
}

void TRIBE_Player::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall logStatus(TRIBE_Player * this, _iobuf * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     00518f08(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00518f29(R)
//              char[256]         Stack[-0x104   tempString                XREF[0,1]:   00518f42(*)
//                               ?logStatus@TRIBE_Player@@UAEXPAU_iobuf@@H@Z                  XREF[2]:     0057695c(*), 00576a8c(*)
//                               TRIBE_Player::logStatus
//                              tplayer.cpp:4744 (8)
//         00518f00     SUB        ESP,0x100
//         00518f06     PUSH       ESI
//         00518f07     PUSH       EDI
//                              tplayer.cpp:4746 (17)
//         00518f08     MOV        EDI,dword ptr [ESP + param_1]
//         00518f0f     MOV        ESI,this
//         00518f11     TEST       EDI,EDI
//         00518f13     JZ         LAB_005192d7
//                              tplayer.cpp:4748 (16)
//         00518f19     MOVSX      EAX,word ptr [ESI + 0x4a]
//         00518f1d     PUSH       EAX
//         00518f1e     PUSH       s_Player_%d:_                                    = "Player %d:\n"
//         00518f23     PUSH       EDI
//         00518f24     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4751 (19)
//         00518f29     MOV        EAX,dword ptr [ESP + param_2]
//         00518f30     ADD        ESP,0xc
//         00518f33     CMP        EAX,0x1
//         00518f36     JNZ        LAB_00518fe8
//                              tplayer.cpp:4754 (35)
//         00518f3c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00518f42     LEA        EAX=>tempString[4],[ESP + 0x8]
//         00518f46     PUSH       0x100
//         00518f4b     PUSH       EAX
//         00518f4c     MOV        EDX,dword ptr [this->_padding_]
//         00518f4e     XOR        EAX,EAX
//         00518f50     MOV        AL,byte ptr [ESI + 0x105]
//         00518f56     ADD        EAX,0x27f6
//         00518f5b     PUSH       EAX
//         00518f5c     CALL       dword ptr [EDX + 0x20]
//                              tplayer.cpp:4755 (10)
//         00518f5f     MOV        EAX,dword ptr [ESI + 0x238]
//         00518f65     TEST       EAX,EAX
//         00518f67     JNZ        LAB_00518f75
//                              tplayer.cpp:4756 (10)
//         00518f69     LEA        this,[ESP + 0x8]
//         00518f6d     PUSH       this
//         00518f6e     PUSH       s___Human_Player,_%s._                           = "  Human Player, %s.\n"
//                              tplayer.cpp:4757 (2)
//         00518f73     JMP        LAB_00518fdf
//                               LAB_00518f75                                                 XREF[1]:     00518f67(j)
//                              tplayer.cpp:4758 (16)
//         00518f75     LEA        EDX,[ESP + 0x8]
//         00518f79     PUSH       EDX
//         00518f7a     PUSH       s___Computer_Player,_%s._                        = "  Computer Player, %s.\n"
//         00518f7f     PUSH       EDI=>DAT_fffffff4
//         00518f80     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4759 (32)
//         00518f85     MOV        this,dword ptr [ESI + 0x238]
//         00518f8b     ADD        ESP,0xc
//         00518f8e     ADD        this,0x104
//         00518f94     CALL       BuildAIModule::buildListName                     char * buildListName(BuildAIModule * this)
//         00518f99     PUSH       EAX
//         00518f9a     PUSH       s___Build_List:______%s._                        = "  Build List:      %s.\n"
//         00518f9f     PUSH       EDI=>DAT_fffffff4
//         00518fa0     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4760 (32)
//         00518fa5     MOV        this,dword ptr [ESI + 0x238]
//         00518fab     ADD        ESP,0xc
//         00518fae     ADD        this,0x6c4
//         00518fb4     CALL       ConstructionAIModule::constructionPlanName       char * constructionPlanName(ConstructionAIMod
//         00518fb9     PUSH       EAX
//         00518fba     PUSH       s___City_Plan:_______%s._                        = "  City Plan:       %s.\n"
//         00518fbf     PUSH       EDI=>DAT_fffffff4
//         00518fc0     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4761 (35)
//         00518fc5     MOV        this,dword ptr [ESI + 0x238]
//         00518fcb     ADD        ESP,0xc
//         00518fce     ADD        this,0x10e74
//         00518fd4     CALL       TribeStrategyAIModule::ruleSetName               char * ruleSetName(TribeStrategyAIModule * th
//         00518fd9     PUSH       EAX
//         00518fda     PUSH       s___VC_File:_________%s._                        = "  VC File:         %s.\n"
//                               LAB_00518fdf                                                 XREF[1]:     00518f73(j)
//         00518fdf     PUSH       EDI=>DAT_fffffff4
//         00518fe0     CALL       fprintf                                          undefined fprintf()
//         00518fe5     ADD        ESP,0xc
//                               LAB_00518fe8                                                 XREF[1]:     00518f36(j)
//                              tplayer.cpp:4766 (11)
//         00518fe8     PUSH       s___Points:_                                     = "  Points:\n"
//         00518fed     PUSH       EDI=>DAT_fffffff8
//         00518fee     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4767 (25)
//         00518ff3     MOV        this,dword ptr [ESI + 0x34]
//         00518ff6     ADD        ESP,0x8
//         00518ff9     PUSH       0x0
//         00518ffb     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         00519000     PUSH       EAX
//         00519001     PUSH       s_____Combat_________%d._                        = "    Combat         %d.\n"
//         00519006     PUSH       EDI=>DAT_fffffff4
//         00519007     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4768 (25)
//         0051900c     MOV        this,dword ptr [ESI + 0x34]
//         0051900f     ADD        ESP,0xc
//         00519012     PUSH       0x1
//         00519014     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         00519019     PUSH       EAX
//         0051901a     PUSH       s_____Economy________%d._                        = "    Economy        %d.\n"
//         0051901f     PUSH       EDI=>DAT_fffffff4
//         00519020     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4769 (25)
//         00519025     MOV        this,dword ptr [ESI + 0x34]
//         00519028     ADD        ESP,0xc
//         0051902b     PUSH       0x2
//         0051902d     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         00519032     PUSH       EAX
//         00519033     PUSH       s_____Religion_______%d._                        = "    Religion       %d.\n"
//         00519038     PUSH       EDI=>DAT_fffffff4
//         00519039     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4770 (25)
//         0051903e     MOV        this,dword ptr [ESI + 0x34]
//         00519041     ADD        ESP,0xc
//         00519044     PUSH       0x3
//         00519046     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         0051904b     PUSH       EAX
//         0051904c     PUSH       s_____Science________%d._                        = "    Science        %d.\n"
//         00519051     PUSH       EDI=>DAT_fffffff4
//         00519052     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4771 (25)
//         00519057     MOV        this,dword ptr [ESI + 0x34]
//         0051905a     ADD        ESP,0xc
//         0051905d     PUSH       0x16
//         0051905f     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
//         00519064     PUSH       EAX
//         00519065     PUSH       s_____Survival_______%d._                        = "    Survival       %d.\n"
//         0051906a     PUSH       EDI=>DAT_fffffff4
//         0051906b     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4772 (25)
//         00519070     MOV        this,dword ptr [ESI + 0x34]
//         00519073     ADD        ESP,0xc
//         00519076     PUSH       0x17
//         00519078     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
//         0051907d     PUSH       EAX
//         0051907e     PUSH       s_____Wonder_________%d._                        = "    Wonder         %d.\n"
//         00519083     PUSH       EDI=>DAT_fffffff4
//         00519084     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4773 (23)
//         00519089     MOV        this,dword ptr [ESI + 0x34]
//         0051908c     ADD        ESP,0xc
//         0051908f     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
//         00519094     PUSH       EAX
//         00519095     PUSH       s_______Total:_______%d._                        = "      Total:       %d.\n"
//         0051909a     PUSH       EDI=>DAT_fffffff4
//         0051909b     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4774 (26)
//         005190a0     MOV        EAX,dword ptr [ESI + 0x50]
//         005190a3     ADD        ESP,0xc
//         005190a6     FLD        float ptr [EAX + 0x2c]
//         005190a9     CALL       __ftol                                           undefined __ftol()
//         005190ae     PUSH       EAX
//         005190af     PUSH       s___Population:______%d._                        = "  Population:      %d.\n"
//         005190b4     PUSH       EDI=>DAT_fffffff4
//         005190b5     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4775 (25)
//         005190ba     MOV        this,dword ptr [ESI + 0x34]
//         005190bd     ADD        ESP,0xc
//         005190c0     PUSH       0x0
//         005190c2     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions
//         005190c7     PUSH       EAX
//         005190c8     PUSH       s___Kills:___________%d._                        = "  Kills:           %d.\n"
//         005190cd     PUSH       EDI=>DAT_fffffff4
//         005190ce     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4776 (25)
//         005190d3     MOV        this,dword ptr [ESI + 0x34]
//         005190d6     ADD        ESP,0xc
//         005190d9     PUSH       0x2
//         005190db     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions
//         005190e0     PUSH       EAX
//         005190e1     PUSH       s___Kill_Ratio:______%d._                        = "  Kill Ratio:      %d.\n"
//         005190e6     PUSH       EDI=>DAT_fffffff4
//         005190e7     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4777 (25)
//         005190ec     MOV        this,dword ptr [ESI + 0x34]
//         005190ef     ADD        ESP,0xc
//         005190f2     PUSH       0x1
//         005190f4     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions
//         005190f9     PUSH       EAX
//         005190fa     PUSH       s___Razings:_________%d._                        = "  Razings:         %d.\n"
//         005190ff     PUSH       EDI=>DAT_fffffff4
//         00519100     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4778 (25)
//         00519105     MOV        this,dword ptr [ESI + 0x50]
//         00519108     ADD        ESP,0xc
//         0051910b     FLD        float ptr [this->_padding_]
//         0051910d     CALL       __ftol                                           undefined __ftol()
//         00519112     PUSH       EAX
//         00519113     PUSH       s___Food:____________%d._                        = "  Food:            %d.\n"
//         00519118     PUSH       EDI=>DAT_fffffff4
//         00519119     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4779 (26)
//         0051911e     MOV        EDX,dword ptr [ESI + 0x50]
//         00519121     ADD        ESP,0xc
//         00519124     FLD        float ptr [EDX + 0xc]
//         00519127     CALL       __ftol                                           undefined __ftol()
//         0051912c     PUSH       EAX
//         0051912d     PUSH       s___Gold:____________%d._                        = "  Gold:            %d.\n"
//         00519132     PUSH       EDI=>DAT_fffffff4
//         00519133     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4780 (26)
//         00519138     MOV        EAX,dword ptr [ESI + 0x50]
//         0051913b     ADD        ESP,0xc
//         0051913e     FLD        float ptr [EAX + 0x8]
//         00519141     CALL       __ftol                                           undefined __ftol()
//         00519146     PUSH       EAX
//         00519147     PUSH       s___Stone:___________%d._                        = "  Stone:           %d.\n"
//         0051914c     PUSH       EDI=>DAT_fffffff4
//         0051914d     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4781 (26)
//         00519152     MOV        this,dword ptr [ESI + 0x50]
//         00519155     ADD        ESP,0xc
//         00519158     FLD        float ptr [ECX + this->_padding_]
//         0051915b     CALL       __ftol                                           undefined __ftol()
//         00519160     PUSH       EAX
//         00519161     PUSH       s___Wood:____________%d._                        = "  Wood:            %d.\n"
//         00519166     PUSH       EDI=>DAT_fffffff4
//         00519167     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4782 (25)
//         0051916c     MOV        this,dword ptr [ESI + 0x34]
//         0051916f     ADD        ESP,0xc
//         00519172     PUSH       0x11
//         00519174     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions
//         00519179     PUSH       EAX
//         0051917a     PUSH       s___Technology:______%d._                        = "  Technology:      %d.\n"
//         0051917f     PUSH       EDI=>DAT_fffffff4
//         00519180     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4783 (25)
//         00519185     MOV        this,dword ptr [ESI + 0x34]
//         00519188     ADD        ESP,0xc
//         0051918b     PUSH       0x7
//         0051918d     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions
//         00519192     PUSH       EAX
//         00519193     PUSH       s___Exploration:_____%d._                        = "  Exploration:     %d.\n"
//         00519198     PUSH       EDI=>DAT_fffffff4
//         00519199     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4786 (17)
//         0051919e     MOV        EAX,dword ptr [ESI + 0x238]
//         005191a4     ADD        ESP,0xc
//         005191a7     TEST       EAX,EAX
//         005191a9     JZ         LAB_005192d7
//                              tplayer.cpp:4791 (77)
//         005191af     LEA        this,[EAX + 0x104]
//         005191b5     CALL       BuildAIModule::buildListLength                   int buildListLength(BuildAIModule * this)
//         005191ba     MOV        this,dword ptr [ESI + 0x238]
//         005191c0     PUSH       EAX
//         005191c1     ADD        this,0x104
//         005191c7     CALL       BuildAIModule::numberItemsIntoBuildList          int numberItemsIntoBuildList(BuildAIModule *
//         005191cc     MOV        this,dword ptr [ESI + 0x238]
//         005191d2     PUSH       EAX=>DAT_fffffff8
//         005191d3     ADD        this,0x104
//         005191d9     CALL       BuildAIModule::lastBuildItemRequested            char * lastBuildItemRequested(BuildAIModule *
//         005191de     MOV        this,dword ptr [ESI + 0x238]
//         005191e4     PUSH       EAX=>DAT_fffffff4
//         005191e5     ADD        this,0x104
//         005191eb     CALL       BuildAIModule::currentBuildItemRequested         char * currentBuildItemRequested(BuildAIModul
//         005191f0     PUSH       EAX=>DAT_fffffff0
//         005191f1     PUSH       s_Build_AI:_last=%s,_last2=%s,_Pro               = "Build AI: last=%s, last2=%s, Progress=%d/%
//         005191f6     PUSH       EDI
//         005191f7     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4802 (184)
//         005191fc     MOV        this,dword ptr [ESI + 0x238]
//         00519202     ADD        ESP,0x18
//         00519205     ADD        this,0x1146c
//         0051920b     PUSH       0x3
//         0051920d     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00519212     MOV        this,dword ptr [ESI + 0x238]
//         00519218     PUSH       EAX
//         00519219     PUSH       offset DAT_fffffff8
//         0051921b     ADD        this,0x1146c
//         00519221     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         00519226     MOV        this,dword ptr [ESI + 0x238]
//         0051922c     PUSH       EAX=>DAT_fffffff8
//         0051922d     PUSH       offset DAT_fffffff4
//         0051922f     ADD        this,0x1146c
//         00519235     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         0051923a     MOV        this,dword ptr [ESI + 0x238]
//         00519240     PUSH       EAX=>DAT_fffffff4
//         00519241     PUSH       0x0=>DAT_fffffff0
//         00519243     ADD        this,0x1146c
//         00519249     CALL       TribeTacticalAIModule::neededResource            int neededResource(TribeTacticalAIModule * th
//         0051924e     MOV        this,dword ptr [ESI + 0x238]
//         00519254     PUSH       EAX=>DAT_fffffff0
//         00519255     ADD        this,0x1146c
//         0051925b     CALL       TribeTacticalAIModule::desiredNumberGatherers    int desiredNumberGatherers(TribeTacticalAIMod
//         00519260     MOV        this,dword ptr [ESI + 0x238]
//         00519266     PUSH       EAX
//         00519267     ADD        this,0x1146c
//         0051926d     CALL       TribeTacticalAIModule::numberGatherers           int numberGatherers(TribeTacticalAIModule * t
//         00519272     MOV        this,dword ptr [ESI + 0x238]
//         00519278     PUSH       EAX
//         00519279     ADD        this,0x1146c
//         0051927f     CALL       TribeTacticalAIModule::desiredNumberCivilianEx   int desiredNumberCivilianExplorers(TribeTacti
//         00519284     MOV        this,dword ptr [ESI + 0x238]
//         0051928a     PUSH       EAX
//         0051928b     ADD        this,0x1146c
//         00519291     CALL       TribeTacticalAIModule::numberCivilianExplorers   int numberCivilianExplorers(TribeTacticalAIMo
//         00519296     MOV        this,dword ptr [ESI + 0x238]
//         0051929c     PUSH       EAX
//         0051929d     ADD        this,0x1146c
//         005192a3     CALL       TribeTacticalAIModule::numberCivilians           int numberCivilians(TribeTacticalAIModule * t
//         005192a8     PUSH       EAX
//         005192a9     PUSH       s_Civilians:_Total=%d,_Exp(%d/%d),               = "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d
//         005192ae     PUSH       EDI
//         005192af     CALL       fprintf                                          undefined fprintf()
//                              tplayer.cpp:4803 (35)
//         005192b4     MOV        this,dword ptr [ESI + 0x238]
//         005192ba     ADD        ESP,0x2c
//         005192bd     ADD        this,0x1146c
//         005192c3     CALL       TribeTacticalAIModule::numberSoldiers            int numberSoldiers(TribeTacticalAIModule * th
//         005192c8     PUSH       EAX
//         005192c9     PUSH       s_Number_Soldiers=%d._                           = "Number Soldiers=%d.\n"
//         005192ce     PUSH       EDI=>DAT_fffffff4
//         005192cf     CALL       fprintf                                          undefined fprintf()
//         005192d4     ADD        ESP,0xc
//                               LAB_005192d7                                                 XREF[2]:     00518f13(j), 005191a9(j)
//                              tplayer.cpp:4805 (11)
//         005192d7     POP        EDI
//         005192d8     POP        ESI
//         005192d9     ADD        ESP,0x100
//         005192df     RET        0x8
//         005192e2     ??         90h
//         005192e3     NOP
//         005192e4     NOP
//         005192e5     NOP
//         005192e6     NOP
//         005192e7     NOP
//         005192e8     NOP
//         005192e9     NOP
//         005192ea     NOP
//         005192eb     NOP
//         005192ec     NOP
//         005192ed     NOP
//         005192ee     NOP
//         005192ef     NOP
    return;
}

void TRIBE_Player::trackUnitGather(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall trackUnitGather(TRIBE_Player * this, int param_1, in
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00519303(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     005192fe(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005192fa(R)
//                               ?trackUnitGather@TRIBE_Player@@UAEXHHH@Z                     XREF[2]:     005768cc(*), 005769fc(*)
//                               TRIBE_Player::trackUnitGather
//                              tplayer.cpp:4810 (10)
//         005192f0     MOV        EAX,dword ptr [ECX + this->playerAI]
//         005192f6     TEST       EAX,EAX
//         005192f8     JZ         LAB_00519314
//                              tplayer.cpp:4814 (26)
//         005192fa     MOV        this,dword ptr [ESP + param_3]
//         005192fe     MOV        EDX,dword ptr [ESP + param_2]
//         00519302     PUSH       this
//         00519303     MOV        this,dword ptr [ESP + param_1]
//         00519307     PUSH       EDX
//         00519308     PUSH       this
//         00519309     LEA        this,[EAX + 0x1146c]
//         0051930f     CALL       TribeTacticalAIModule::trackUnitGather           void trackUnitGather(TribeTacticalAIModule *
//                               LAB_00519314                                                 XREF[1]:     005192f8(j)
//                              tplayer.cpp:4815 (3)
//         00519314     RET        0xc
//         00519317     ??         90h
//         00519318     NOP
//         00519319     NOP
//         0051931a     NOP
//         0051931b     NOP
//         0051931c     NOP
//         0051931d     NOP
//         0051931e     NOP
//         0051931f     NOP
    return;
}

void TRIBE_Player::get_achievement(uchar param_1, char* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_achievement(TRIBE_Player * this, uchar param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00519320(R)
//              char *            Stack[0x8]:4   param_2                   XREF[7]:     0051934d(R), 00519373(R), 00519396(R), 005193b9(R),
//                                                                                     005193e7(R), 00519415(R), 00519448(R)
//              undefined8        Stack[-0x10]:8 local_10                  XREF[6]:     0051937d(*), 005193a0(*), 005193c3(*), 005193ee(*),
//                                                                                     0051941c(W), 0051944f(*)
//              undefined8        Stack[-0x18]:8 local_18                  XREF[1]:     00519423(*)
//              undefined8        Stack[-0x20]:8 local_20                  XREF[1]:     0051942c(*)
//                               ?get_achievement@TRIBE_Player@@QAEXEPAD@Z                    XREF[1]:     get_achievement:00530a98(c)
//                               TRIBE_Player::get_achievement
//                              tplayer.cpp:4819 (27)
//         00519320     MOV        EAX,dword ptr [ESP + param_1]
//         00519324     PUSH       ESI
//         00519325     AND        EAX,0xff
//         0051932a     PUSH       EDI
//         0051932b     CMP        EAX,0x8
//         0051932e     JA         switchD_00519334::default
//                               switchD_00519334::switchD
//         00519334     JMP        dword ptr [EAX*0x4 + switchD_00519334::switchd   = 0051933b
//                               switchD_00519334::caseD_0                                    XREF[2]:     00519334(j), 00519468(*)
//                              tplayer.cpp:4828 (34)
//         0051933b     MOV        EDI,dword ptr [ECX + this->_padding_]
//         0051933e     OR         this,0xffffffff
//         00519341     XOR        EAX,EAX
//         00519343     SCASB.RE   ES:EDI
//         00519345     NOT        this
//         00519347     SUB        EDI,this
//         00519349     MOV        EAX,this
//         0051934b     MOV        ESI,EDI
//         0051934d     MOV        EDI,dword ptr [ESP + param_2]
//         00519351     SHR        this,0x2
//         00519354     MOVSD.REP  ES:EDI,ESI
//         00519356     MOV        this,EAX
//         00519358     AND        this,0x3
//         0051935b     MOVSB.REP  ES:EDI,ESI
//                              tplayer.cpp:4855 (5)
//         0051935d     POP        EDI
//         0051935e     POP        ESI
//         0051935f     RET        0x8
//                               switchD_00519334::caseD_1                                    XREF[2]:     00519334(j), 0051946c(*)
//                              tplayer.cpp:4831 (9)
//         00519362     MOV        this,dword ptr [ECX + this->_padding_]
//         00519365     FLD        float ptr [ECX + this->_padding_]
//         00519368     FSUB       float ptr [ECX + this->_padding_]
//                              tplayer.cpp:4832 (5)
//         0051936b     JMP        LAB_00519448
//                               switchD_00519334::caseD_2                                    XREF[2]:     00519334(j), 00519470(*)
//                              tplayer.cpp:4834 (22)
//         00519370     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00519373     MOV        EAX,dword ptr [ESP + param_2]
//         00519377     SUB        ESP,0x8
//         0051937a     FLD        float ptr [EDX + 0x50]
//         0051937d     FSTP       double ptr [ESP]=>local_10
//         00519380     PUSH       s_%4.f                                           = "%4.f"
//         00519385     PUSH       EAX
//                              tplayer.cpp:4852 (8)
//         00519386     CALL       sprintf                                          undefined sprintf()
//         0051938b     ADD        ESP,0x10
//                              tplayer.cpp:4855 (5)
//         0051938e     POP        EDI
//         0051938f     POP        ESI
//         00519390     RET        0x8
//                               switchD_00519334::caseD_3                                    XREF[2]:     00519334(j), 00519474(*)
//                              tplayer.cpp:4837 (22)
//         00519393     MOV        this,dword ptr [ECX + this->_padding_]
//         00519396     MOV        EDX,dword ptr [ESP + param_2]
//         0051939a     SUB        ESP,0x8
//         0051939d     FLD        float ptr [ECX + this->_padding_]
//         005193a0     FSTP       double ptr [ESP]=>local_10
//         005193a3     PUSH       s_%4.f                                           = "%4.f"
//         005193a8     PUSH       EDX
//                              tplayer.cpp:4852 (8)
//         005193a9     CALL       sprintf                                          undefined sprintf()
//         005193ae     ADD        ESP,0x10
//                              tplayer.cpp:4855 (5)
//         005193b1     POP        EDI
//         005193b2     POP        ESI
//         005193b3     RET        0x8
//                               switchD_00519334::caseD_4                                    XREF[2]:     00519334(j), 00519478(*)
//                              tplayer.cpp:4840 (3)
//         005193b6     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              tplayer.cpp:4852 (27)
//         005193b9     MOV        this,dword ptr [ESP + param_2]
//         005193bd     SUB        ESP,0x8
//         005193c0     FLD        float ptr [EAX + 0xc]
//         005193c3     FSTP       double ptr [ESP]=>local_10
//         005193c6     PUSH       s_%5.f                                           = "%5.f"
//         005193cb     PUSH       this
//         005193cc     CALL       sprintf                                          undefined sprintf()
//         005193d1     ADD        ESP,0x10
//                              tplayer.cpp:4855 (5)
//         005193d4     POP        EDI
//         005193d5     POP        ESI
//         005193d6     RET        0x8
//                               switchD_00519334::caseD_5                                    XREF[2]:     00519334(j), 0051947c(*)
//                              tplayer.cpp:4843 (30)
//         005193d9     MOV        this,dword ptr [ECX + this->_padding_]
//         005193dc     CALL       RGE_Visible_Map::percentExplored                 float percentExplored(RGE_Visible_Map * this)
//         005193e1     FMUL       float ptr [DAT_0057682c]
//         005193e7     MOV        EDX,dword ptr [ESP + param_2]
//         005193eb     SUB        ESP,0x8
//         005193ee     FSTP       double ptr [ESP]=>local_10
//         005193f1     PUSH       s_%3.f%%                                         = "%3.f%%"
//         005193f6     PUSH       EDX
//                              tplayer.cpp:4852 (8)
//         005193f7     CALL       sprintf                                          undefined sprintf()
//         005193fc     ADD        ESP,0x10
//                              tplayer.cpp:4855 (5)
//         005193ff     POP        EDI
//         00519400     POP        ESI
//         00519401     RET        0x8
//                               switchD_00519334::caseD_6                                    XREF[2]:     00519334(j), 00519480(*)
//                              tplayer.cpp:4846 (6)
//         00519404     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00519407     FLD        float ptr [EAX + 0x4c]
//                              tplayer.cpp:4847 (2)
//         0051940a     JMP        LAB_00519448
//                               switchD_00519334::caseD_7                                    XREF[2]:     00519334(j), 00519484(*)
//                              tplayer.cpp:4849 (49)
//         0051940c     MOV        this,dword ptr [ECX + this->_padding_]
//         0051940f     SUB        ESP,0x8
//         00519412     SUB        ESP,0x8
//         00519415     MOV        EDX,dword ptr [ESP + param_2]
//         00519419     FLD        float ptr [ECX + this->_padding_]
//         0051941c     FSTP       double ptr [ESP + local_10]
//         00519420     FLD        float ptr [ECX + this->_padding_]
//         00519423     FSTP       double ptr [ESP]=>local_18
//         00519426     FLD        float ptr [ECX + this->_padding_]
//         00519429     SUB        ESP,0x8
//         0051942c     FSTP       double ptr [ESP]=>local_20
//         0051942f     PUSH       s_%4.f/%4.f/%4.f                                 = "%4.f/%4.f/%4.f"
//         00519434     PUSH       EDX
//         00519435     CALL       sprintf                                          undefined sprintf()
//         0051943a     ADD        ESP,0x20
//                              tplayer.cpp:4855 (5)
//         0051943d     POP        EDI
//         0051943e     POP        ESI
//         0051943f     RET        0x8
//                               switchD_00519334::caseD_8                                    XREF[2]:     00519334(j), 00519488(*)
//                              tplayer.cpp:4852 (30)
//         00519442     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00519445     FLD        float ptr [EAX + 0x54]
//                               LAB_00519448                                                 XREF[2]:     0051936b(j), 0051940a(j)
//         00519448     MOV        this,dword ptr [ESP + param_2]
//         0051944c     SUB        ESP,0x8
//         0051944f     FSTP       double ptr [ESP]=>local_10
//         00519452     PUSH       s_%4.f                                           = "%4.f"
//         00519457     PUSH       this
//         00519458     CALL       sprintf                                          undefined sprintf()
//         0051945d     ADD        ESP,0x10
//                               switchD_00519334::default                                    XREF[1]:     0051932e(j)
//                              tplayer.cpp:4855 (44)
//         00519460     POP        EDI
//         00519461     POP        ESI
//         00519462     RET        0x8
    return;
}

void TRIBE_Player::load_victory(int param_1, long* param_2, uchar param_3) {
    /* TODO: Stub */
//                              void __thiscall load_victory(TRIBE_Player * this, int param_1, long
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005194cc(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     005194c7(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     005194c3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005194b9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005194de(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     005194b3(W)
//                               ?load_victory@TRIBE_Player@@UAEXHPAJE@Z                      XREF[2]:     00576960(*), 00576a90(*)
//                               TRIBE_Player::load_victory
//                              tplayer.cpp:4859 (25)
//         00519490     PUSH       -0x1
//         00519492     PUSH       FUN_0056129b
//         00519497     MOV        EAX,FS:[0x0]
//         0051949d     PUSH       EAX
//         0051949e     MOV        dword ptr FS:[0x0],ESP
//         005194a5     PUSH       this
//         005194a6     PUSH       ESI
//         005194a7     MOV        ESI,this
//                              tplayer.cpp:4860 (53)
//         005194a9     PUSH       0x20
//         005194ab     CALL       operator_new                                     void * operator_new(uint param_1)
//         005194b0     ADD        ESP,0x4
//         005194b3     MOV        dword ptr [ESP + local_10],EAX
//         005194b7     TEST       EAX,EAX
//         005194b9     MOV        dword ptr [ESP + local_4],0x0
//         005194c1     JZ         LAB_005194dc
//         005194c3     MOV        this,dword ptr [ESP + param_3]
//         005194c7     MOV        EDX,dword ptr [ESP + param_2]
//         005194cb     PUSH       this
//         005194cc     MOV        this,dword ptr [ESP + param_1]
//         005194d0     PUSH       EDX
//         005194d1     PUSH       this
//         005194d2     PUSH       ESI
//         005194d3     MOV        this,EAX
//         005194d5     CALL       TRIBE_Victory_Conditions::TRIBE_Victory_Condit   undefined TRIBE_Victory_Conditions(TRIBE_Vict
//         005194da     JMP        LAB_005194de
//                               LAB_005194dc                                                 XREF[1]:     005194c1(j)
//         005194dc     XOR        EAX,EAX
//                               LAB_005194de                                                 XREF[1]:     005194da(j)
//                              tplayer.cpp:4861 (21)
//         005194de     MOV        this,dword ptr [ESP + local_c]
//         005194e2     MOV        dword ptr [ESI + 0x34],EAX
//         005194e5     MOV        dword ptr FS:[0x0],this
//         005194ec     POP        ESI
//         005194ed     ADD        ESP,0x10
//         005194f0     RET        0xc
//         005194f3     ??         90h
//         005194f4     NOP
//         005194f5     NOP
//         005194f6     NOP
//         005194f7     NOP
//         005194f8     NOP
//         005194f9     NOP
//         005194fa     NOP
//         005194fb     NOP
//         005194fc     NOP
//         005194fd     NOP
//         005194fe     NOP
//         005194ff     NOP
    return;
}

void TRIBE_Player::new_victory() {
    /* TODO: Stub */
//                              void __thiscall new_victory(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00519529(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0051953e(R), 0051954e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00519523(W)
//                               ?new_victory@TRIBE_Player@@UAEXXZ                            XREF[3]:     TRIBE_Player:00511fb3(c),
//                               TRIBE_Player::new_victory                                                 00576964(*), 00576a94(*)
//                              tplayer.cpp:4865 (25)
//         00519500     PUSH       -0x1
//         00519502     PUSH       FUN_005612bb
//         00519507     MOV        EAX,FS:[0x0]
//         0051950d     PUSH       EAX
//         0051950e     MOV        dword ptr FS:[0x0],ESP
//         00519515     PUSH       this
//         00519516     PUSH       ESI
//         00519517     MOV        ESI,this
//                              tplayer.cpp:4866 (37)
//         00519519     PUSH       0x20
//         0051951b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00519520     ADD        ESP,0x4
//         00519523     MOV        dword ptr [ESP + local_10],EAX
//         00519527     TEST       EAX,EAX
//         00519529     MOV        dword ptr [ESP + local_4],0x0
//         00519531     JZ         LAB_0051954e
//         00519533     PUSH       ESI
//         00519534     MOV        this,EAX
//         00519536     CALL       TRIBE_Victory_Conditions::TRIBE_Victory_Condit   undefined TRIBE_Victory_Conditions(TRIBE_Vict
//         0051953b     MOV        dword ptr [ESI + 0x34],EAX
//                              tplayer.cpp:4867 (37)
//         0051953e     MOV        this,dword ptr [ESP + local_c]
//         00519542     MOV        dword ptr FS:[0x0],this
//         00519549     POP        ESI
//         0051954a     ADD        ESP,0x10
//         0051954d     RET
//                               LAB_0051954e                                                 XREF[1]:     00519531(j)
//         0051954e     MOV        this,dword ptr [ESP + local_c]
//         00519552     XOR        EAX,EAX
//         00519554     MOV        dword ptr [ESI + 0x34],EAX
//         00519557     MOV        dword ptr FS:[0x0],this
//         0051955e     POP        ESI
//         0051955f     ADD        ESP,0x10
//         00519562     RET
//         00519563     ??         90h
//         00519564     NOP
//         00519565     NOP
//         00519566     NOP
//         00519567     NOP
//         00519568     NOP
//         00519569     NOP
//         0051956a     NOP
//         0051956b     NOP
//         0051956c     NOP
//         0051956d     NOP
//         0051956e     NOP
//         0051956f     NOP
    return;
}

void TRIBE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) {
    /* TODO: Stub */
//                              void __thiscall add_attribute_num(TRIBE_Player * this, short param_1
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00519577(R)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     0051958a(R), 005195b2(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00519571(R)
//                               ?add_attribute_num@TRIBE_Player@@UAEXFME@Z                   XREF[2]:     005768e8(*), 00576a18(*)
//                               TRIBE_Player::add_attribute_num
//                              tplayer.cpp:4873 (1)
//         00519570     PUSH       EBX
//                              tplayer.cpp:4874 (22)
//         00519571     MOV        EBX,dword ptr [ESP + param_3]
//         00519575     PUSH       ESI
//         00519576     PUSH       EDI
//         00519577     MOV        EDI,dword ptr [ESP + param_1]
//         0051957b     MOV        ESI,this
//         0051957d     CMP        DI,0x3
//         00519581     JNZ        LAB_0051959a
//         00519583     TEST       BL,BL
//         00519585     JZ         LAB_0051959a
//                              tplayer.cpp:4875 (19)
//         00519587     MOV        EAX,dword ptr [ESI + 0x50]
//         0051958a     FLD        float ptr [ESP + param_2]
//         0051958e     FADD       float ptr [EAX + 0xc4]
//         00519594     FSTP       float ptr [EAX + 0xc4]
//                               LAB_0051959a                                                 XREF[2]:     00519581(j), 00519585(j)
//                              tplayer.cpp:4877 (6)
//         0051959a     CMP        DI,0x32
//         0051959e     JNZ        LAB_005195b2
//                              tplayer.cpp:4880 (18)
//         005195a0     MOV        this,dword ptr [ESI + 0x3c]
//         005195a3     MOV        dword ptr [ESI + 0x100],0x1
//         005195ad     CALL       RGE_Game_World::update_mutual_allies             void update_mutual_allies(RGE_Game_World * th
//                               LAB_005195b2                                                 XREF[1]:     0051959e(j)
//                              tplayer.cpp:4883 (14)
//         005195b2     MOV        EAX,dword ptr [ESP + param_2]
//         005195b6     PUSH       EBX
//         005195b7     PUSH       EAX
//         005195b8     PUSH       EDI
//         005195b9     MOV        this,ESI
//         005195bb     CALL       RGE_Player::add_attribute_num                    void add_attribute_num(RGE_Player * this, sho
//                              tplayer.cpp:4884 (6)
//         005195c0     POP        EDI
//         005195c1     POP        ESI
//         005195c2     POP        EBX
//         005195c3     RET        0xc
//         005195c6     ??         90h
//         005195c7     NOP
//         005195c8     NOP
//         005195c9     NOP
//         005195ca     NOP
//         005195cb     NOP
//         005195cc     NOP
//         005195cd     NOP
//         005195ce     NOP
//         005195cf     NOP
    return;
}

void TRIBE_Player::analyize_selected_objects() {
    /* TODO: Stub */
//                              void __thiscall analyize_selected_objects(TRIBE_Player * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//                               ?analyize_selected_objects@TRIBE_Player@@UAEXXZ              XREF[2]:     00576908(*), 00576a38(*)
//                               TRIBE_Player::analyize_selected_objects
//                              tplayer.cpp:4896 (3)
//         005195d0     PUSH       EBX
//         005195d1     PUSH       EBP
//         005195d2     PUSH       ESI
//                              tplayer.cpp:4899 (8)
//         005195d3     XOR        ESI,ESI
//         005195d5     MOV        dword ptr [DAT_0086bc8c],ESI
//                              tplayer.cpp:4903 (20)
//         005195db     CMP        word ptr [ECX + this->_padding_],SI
//         005195e2     PUSH       EDI
//         005195e3     MOV        dword ptr [ECX + this->_padding_],ESI
//         005195e9     JZ         LAB_005196d5
//                              tplayer.cpp:4905 (2)
//         005195ef     XOR        EDI,EDI
//                              tplayer.cpp:4950 (72)
//         005195f1     LEA        EDX,[ECX + this->_padding_]
//         005195f7     MOV        EBX,0x16
//                               LAB_005195fc                                                 XREF[1]:     005196cf(j)
//         005195fc     MOVSX      EAX,word ptr [ECX + this->_padding_]
//         00519603     CMP        EDI,EAX
//         00519605     JGE        LAB_005196d5
//         0051960b     MOV        EAX,dword ptr [EDX]
//         0051960d     TEST       EAX,EAX
//         0051960f     JZ         LAB_005196c8
//         00519615     MOV        EBP,dword ptr [EAX + 0xc]
//         00519618     MOV        BP,word ptr [EBP + 0x4a]
//         0051961c     CMP        BP,word ptr [ECX + this+0x4a]
//         00519620     JNZ        LAB_005196c7
//         00519626     MOV        EAX,dword ptr [EAX + 0x8]
//         00519629     MOVSX      EAX,word ptr [EAX + 0x14]
//         0051962d     TEST       EAX,EAX
//         0051962f     JL         LAB_00519698
//         00519631     CMP        EAX,dword ptr [tribe_group_properties_num]       = 28h
//         00519637     JGE        LAB_00519698
//                              tplayer.cpp:4916 (5)
//         00519639     CMP        EAX,0x12
//         0051963c     JNZ        LAB_00519683
//                              tplayer.cpp:4918 (14)
//         0051963e     MOV        EBP,dword ptr [ECX + this->_padding_]
//         00519644     OR         EBP,EBX
//         00519646     MOV        dword ptr [ECX + this->_padding_],EBP
//                              tplayer.cpp:4919 (11)
//         0051964c     MOV        EAX,[DAT_0086bc8c]
//         00519651     INC        EAX
//         00519652     MOV        [DAT_0086bc8c],EAX
//                              tplayer.cpp:4920 (10)
//         00519657     MOV        EAX,dword ptr [EDX]
//         00519659     MOV        EAX,dword ptr [EAX + 0x4]
//         0051965c     MOV        [DAT_0086bc88],EAX
//                              tplayer.cpp:4922 (18)
//         00519661     MOV        EAX,dword ptr [EDX]
//         00519663     FLD        float ptr [EAX + 0x44]
//         00519666     FCOMP      float ptr [DAT_0057682c]
//         0051966c     FNSTSW     AX
//         0051966e     TEST       AH,0x1
//         00519671     JNZ        LAB_00519698
//                              tplayer.cpp:4924 (14)
//         00519673     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00519679     OR         AL,0x80
//         0051967b     MOV        dword ptr [ECX + this->_padding_],EAX
//                              tplayer.cpp:4927 (2)
//         00519681     JMP        LAB_00519698
//                               LAB_00519683                                                 XREF[1]:     0051963c(j)
//                              tplayer.cpp:4929 (21)
//         00519683     MOV        EAX,dword ptr [EAX*0x4 + tribe_group_properties] = 00000007
//         0051968a     MOV        EBP,dword ptr [ECX + this->_padding_]
//         00519690     OR         EBP,EAX
//         00519692     MOV        dword ptr [ECX + this->_padding_],EBP
//                               LAB_00519698                                                 XREF[4]:     0051962f(j), 00519637(j),
//                                                                                                         00519671(j), 00519681(j)
//                              tplayer.cpp:4937 (9)
//         00519698     MOV        EAX,dword ptr [EDX]
//         0051969a     MOV        EAX,dword ptr [EAX + 0x8]
//         0051969d     MOVSX      EAX,word ptr [EAX + 0x10]
//                              tplayer.cpp:4939 (24)
//         005196a1     CMP        EAX,0x4f
//         005196a4     JZ         LAB_005196b9
//         005196a6     CMP        EAX,0xc7
//         005196ab     JZ         LAB_005196b9
//         005196ad     CMP        EAX,0x45
//         005196b0     JZ         LAB_005196b9
//         005196b2     CMP        EAX,0x116
//         005196b7     JNZ        LAB_005196c7
//                               LAB_005196b9                                                 XREF[3]:     005196a4(j), 005196ab(j),
//                                                                                                         005196b0(j)
//                              tplayer.cpp:4941 (14)
//         005196b9     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005196bf     OR         AL,0x1
//         005196c1     MOV        dword ptr [ECX + this->_padding_],EAX
//                               LAB_005196c7                                                 XREF[2]:     00519620(j), 005196b7(j)
//                              tplayer.cpp:4946 (1)
//         005196c7     INC        EDI
//                               LAB_005196c8                                                 XREF[1]:     0051960f(j)
//                              tplayer.cpp:4905 (13)
//         005196c8     INC        ESI
//         005196c9     ADD        EDX,0x4
//         005196cc     CMP        ESI,0x19
//         005196cf     JL         LAB_005195fc
//                               LAB_005196d5                                                 XREF[2]:     005195e9(j), 00519605(j)
//                              tplayer.cpp:4950 (5)
//         005196d5     POP        EDI
//         005196d6     POP        ESI
//         005196d7     POP        EBP
//         005196d8     POP        EBX
//         005196d9     RET
//         005196da     ??         90h
//         005196db     NOP
//         005196dc     NOP
//         005196dd     NOP
//         005196de     NOP
//         005196df     NOP
    return;
}

int TRIBE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) {
    /* TODO: Stub */
//                              int __thiscall get_mouse_pointer_action_vars(TRIBE_Player * this, in
//              int               EAX:4          <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     005196e3(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     005196fa(R)
//              int *             Stack[0xc]:4   param_3                   XREF[1]:     005196fe(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005196ee(W)
//              int               Stack[-0xc]:4  RtClickTable              XREF[2]:     0051973e(W), 00519762(W)
//              int               Stack[-0x10]:4 MstrObjId                 XREF[2]:     00519742(W), 0051976e(W)
//              int               Stack[-0x14]:4 MaxHp                     XREF[1]:     0051970c(W)
//              RGE_Static_Obj    Stack[-0x18]:4 thisObj                   XREF[3]:     0051972a(W), 0051975e(W), 0051976a(R)
//              int               Stack[-0x1c]:4 ObjPlayer                 XREF[2]:     00519732(W), 00519752(W)
//              int               Stack[-0x20]:4 ObjectType
//                               ?get_mouse_pointer_action_vars@TRIBE_Player@@UAEHHAAH0@Z     XREF[2]:     0057690c(*), 00576a3c(*)
//                               TRIBE_Player::get_mouse_pointer_action_vars
//                              tplayer.cpp:4960 (3)
//         005196e0     SUB        ESP,0x1c
//                              tplayer.cpp:4966 (23)
//         005196e3     MOV        EAX,dword ptr [ESP + param_1]
//         005196e7     PUSH       EBX
//         005196e8     PUSH       EBP
//         005196e9     PUSH       ESI
//         005196ea     PUSH       EDI
//         005196eb     MOV        EDI,this
//         005196ed     PUSH       EAX
//         005196ee     MOV        dword ptr [ESP + local_4],EDI
//         005196f2     MOV        this,dword ptr [EDI + 0x3c]
//         005196f5     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              tplayer.cpp:4976 (4)
//         005196fa     MOV        EBX,dword ptr [ESP + param_2]
//                              tplayer.cpp:4977 (8)
//         005196fe     MOV        EDX,dword ptr [ESP + param_3]
//         00519702     MOV        this,EAX
//         00519704     XOR        ESI,ESI
//                              tplayer.cpp:4978 (4)
//         00519706     XOR        EBP,EBP
//         00519708     MOV        dword ptr [EBX],ESI
//                              tplayer.cpp:4980 (14)
//         0051970a     TEST       this,this
//         0051970c     MOV        dword ptr [ESP + MaxHp],this
//         00519710     MOV        dword ptr [EDX],ESI
//         00519712     JZ         LAB_00519928
//                              tplayer.cpp:4984 (6)
//         00519718     CMP        byte ptr [ECX + this+0x4e],0x19
//         0051971c     JNZ        LAB_00519748
//                              tplayer.cpp:4986 (6)
//         0051971e     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              tplayer.cpp:4987 (18)
//         00519724     MOV        this,dword ptr [ECX + this->_padding_]
//         0051972a     MOV        dword ptr [ESP + thisObj],this
//         0051972e     MOVSX      EDX,word ptr [EAX + 0x14]
//         00519732     MOV        dword ptr [ESP + ObjPlayer],EDX
//                              tplayer.cpp:4988 (4)
//         00519736     MOVSX      EDX,word ptr [EAX + 0x10]
//                              tplayer.cpp:4989 (12)
//         0051973a     MOVSX      EAX,word ptr [EAX + 0x26]
//         0051973e     MOV        dword ptr [ESP + RtClickTable],EDX
//         00519742     MOV        dword ptr [ESP + MstrObjId],EAX
//                              tplayer.cpp:4991 (2)
//         00519746     JMP        LAB_00519772
//                               LAB_00519748                                                 XREF[1]:     0051971c(j)
//                              tplayer.cpp:4993 (3)
//         00519748     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              tplayer.cpp:4994 (15)
//         0051974b     MOV        this,dword ptr [ECX + this->_padding_]
//         0051974e     MOVSX      EDX,word ptr [EAX + 0x14]
//         00519752     MOV        dword ptr [ESP + ObjPlayer],EDX
//         00519756     MOVSX      EDX,word ptr [ECX + this+0x4a]
//                              tplayer.cpp:4995 (12)
//         0051975a     MOVSX      this,word ptr [EAX + 0x10]
//         0051975e     MOV        dword ptr [ESP + thisObj],EDX
//         00519762     MOV        dword ptr [ESP + RtClickTable],this
//                              tplayer.cpp:4996 (12)
//         00519766     MOVSX      EDX,word ptr [EAX + 0x26]
//         0051976a     MOV        this,dword ptr [ESP + thisObj]
//         0051976e     MOV        dword ptr [ESP + MstrObjId],EDX
//                               LAB_00519772                                                 XREF[1]:     00519746(j)
//                              tplayer.cpp:5001 (23)
//         00519772     TEST       this,this
//         00519774     JL         LAB_00519928
//         0051977a     MOV        EAX,dword ptr [EDI + 0x3c]
//         0051977d     MOVSX      EDX,word ptr [EAX + 0x3c]
//         00519781     CMP        this,EDX
//         00519783     JGE        LAB_00519928
//                              tplayer.cpp:5009 (10)
//         00519789     MOV        EAX,dword ptr [EDI]
//         0051978b     MOV        this,EDI
//         0051978d     CALL       dword ptr [EAX + 0x98]
//                              tplayer.cpp:5014 (18)
//         00519793     MOV        EAX,dword ptr [ESP + 0x20]
//         00519797     CMP        EAX,0x9e
//         0051979c     JZ         LAB_005197a5
//         0051979e     CMP        EAX,0xa3
//         005197a3     JNZ        LAB_005197aa
//                               LAB_005197a5                                                 XREF[1]:     0051979c(j)
//                              tplayer.cpp:5015 (5)
//         005197a5     MOV        EBP,0x32
//                              Symbol Ref: No symbol: retry_table
//                               LAB_005197aa                                                 XREF[2]:     005197a3(j), 00519923(j)
//                              tplayer.cpp:5020 (20)
//         005197aa     CMP        word ptr [EDI + 0x19c],0x0
//         005197b2     JZ         LAB_005197d9
//         005197b4     MOV        EAX,dword ptr [EDI + 0x198]
//         005197ba     TEST       EAX,EAX
//         005197bc     JZ         LAB_005197d9
//                              tplayer.cpp:5028 (5)
//         005197be     MOV        EAX,[rge_base_game]                              = 00000000
//                              tplayer.cpp:5030 (22)
//         005197c3     MOV        dword ptr [ESP + 0x24],0x1
//         005197cb     MOV        EDI,dword ptr [EAX + 0xa24]
//         005197d1     MOV        this,dword ptr [EAX + 0xa28]
//         005197d7     JMP        LAB_005197f2
//                               LAB_005197d9                                                 XREF[2]:     005197b2(j), 005197bc(j)
//                              tplayer.cpp:5022 (5)
//         005197d9     MOV        EAX,[rge_base_game]                              = 00000000
//                              tplayer.cpp:5024 (20)
//         005197de     MOV        dword ptr [ESP + 0x24],0x0
//         005197e6     MOV        EDI,dword ptr [EAX + 0xa2c]
//         005197ec     MOV        this,dword ptr [EAX + 0xa30]
//                               LAB_005197f2                                                 XREF[1]:     005197d7(j)
//                              tplayer.cpp:5035 (12)
//         005197f2     MOV        EDX,dword ptr [ESP + 0x10]
//         005197f6     TEST       EDX,EDX
//         005197f8     JL         LAB_0051980e
//         005197fa     CMP        EDX,this
//         005197fc     JGE        LAB_0051980e
//                              tplayer.cpp:5036 (14)
//         005197fe     LEA        EAX,[EDX + EDX*0x4]
//         00519801     LEA        EAX,[EDX + EAX*0x2]
//         00519804     CMP        dword ptr [EDI + EAX*0x4],EDX
//         00519807     LEA        EAX,[EDI + EAX*0x4]
//         0051980a     JNZ        LAB_0051980e
//                              tplayer.cpp:5037 (2)
//         0051980c     MOV        ESI,EAX
//                               LAB_0051980e                                                 XREF[3]:     005197f8(j), 005197fc(j),
//                                                                                                         0051980a(j)
//                              tplayer.cpp:5041 (4)
//         0051980e     TEST       ESI,ESI
//         00519810     JNZ        LAB_00519845
//                              tplayer.cpp:5043 (6)
//         00519812     XOR        EAX,EAX
//         00519814     TEST       this,this
//         00519816     JLE        LAB_0051983d
//                              tplayer.cpp:5248 (2)
//         00519818     MOV        EDX,EDI
//                               LAB_0051981a                                                 XREF[1]:     00519828(j)
//                              tplayer.cpp:5045 (18)
//         0051981a     MOV        EBX,dword ptr [ESP + 0x10]
//         0051981e     CMP        dword ptr [EDX],EBX
//         00519820     JZ         LAB_0051982c
//         00519822     INC        EAX
//         00519823     ADD        EDX,0x2c
//         00519826     CMP        EAX,this
//         00519828     JL         LAB_0051981a
//         0051982a     JMP        LAB_00519835
//                               LAB_0051982c                                                 XREF[1]:     00519820(j)
//                              tplayer.cpp:5047 (17)
//         0051982c     LEA        this,[EAX + EAX*0x4]
//         0051982f     LEA        EDX,[EAX + this->_padding_*0x2]
//         00519832     LEA        ESI,[EDI + EDX*0x4]
//                               LAB_00519835                                                 XREF[1]:     0051982a(j)
//         00519835     MOV        EBX,dword ptr [ESP + 0x34]
//         00519839     MOV        EDX,dword ptr [ESP + 0x10]
//                               LAB_0051983d                                                 XREF[1]:     00519816(j)
//                              tplayer.cpp:5055 (8)
//         0051983d     TEST       ESI,ESI
//         0051983f     JZ         LAB_00519928
//                               LAB_00519845                                                 XREF[1]:     00519810(j)
//                              tplayer.cpp:5059 (27)
//         00519845     MOV        EDI,dword ptr [ESP + 0x28]
//         00519849     MOV        EAX,dword ptr [ESP + 0x14]
//         0051984d     MOV        EAX,dword ptr [EDI + EAX*0x4 + 0x88]
//         00519854     CMP        EAX,0x4
//         00519857     JA         switchD_00519859::default
//                               switchD_00519859::switchD
//         00519859     JMP        dword ptr [EAX*0x4 + switchD_00519859::switchd   = 00519860
//                               switchD_00519859::caseD_0                                    XREF[2]:     00519859(j), 00519ab4(*)
//                              tplayer.cpp:5063 (3)
//         00519860     MOV        EAX,dword ptr [ESI + 0xc]
//                              tplayer.cpp:5064 (3)
//         00519863     MOV        ESI,dword ptr [ESI + 0x10]
//                              tplayer.cpp:5065 (2)
//         00519866     JMP        LAB_0051988e
//                               switchD_00519859::caseD_1                                    XREF[2]:     00519859(j), 00519ab8(*)
//                              tplayer.cpp:5070 (3)
//         00519868     MOV        EAX,dword ptr [ESI + 0x4]
//                              tplayer.cpp:5071 (3)
//         0051986b     MOV        ESI,dword ptr [ESI + 0x8]
//                              tplayer.cpp:5072 (2)
//         0051986e     JMP        LAB_0051988e
//                               switchD_00519859::caseD_2                                    XREF[2]:     00519859(j), 00519abc(*)
//                              tplayer.cpp:5077 (3)
//         00519870     MOV        EAX,dword ptr [ESI + 0x14]
//                              tplayer.cpp:5078 (3)
//         00519873     MOV        ESI,dword ptr [ESI + 0x18]
//                              tplayer.cpp:5079 (2)
//         00519876     JMP        LAB_0051988e
//                               switchD_00519859::caseD_3                                    XREF[2]:     00519859(j), 00519ac0(*)
//                              tplayer.cpp:5084 (3)
//         00519878     MOV        EAX,dword ptr [ESI + 0x1c]
//                              tplayer.cpp:5085 (3)
//         0051987b     MOV        ESI,dword ptr [ESI + 0x20]
//                              tplayer.cpp:5086 (2)
//         0051987e     JMP        LAB_0051988e
//                               switchD_00519859::caseD_4                                    XREF[2]:     00519859(j), 00519ac4(*)
//                              tplayer.cpp:5091 (3)
//         00519880     MOV        EAX,dword ptr [ESI + 0x24]
//                              tplayer.cpp:5092 (3)
//         00519883     MOV        ESI,dword ptr [ESI + 0x28]
//                              tplayer.cpp:5093 (2)
//         00519886     JMP        LAB_0051988e
//                               switchD_00519859::default                                    XREF[1]:     00519857(j)
//                              tplayer.cpp:5098 (3)
//         00519888     OR         EAX,0xffffffff
//                              tplayer.cpp:5099 (3)
//         0051988b     OR         ESI,0xffffffff
//                               LAB_0051988e                                                 XREF[5]:     00519866(j), 0051986e(j),
//                                                                                                         00519876(j), 0051987e(j),
//                                                                                                         00519886(j)
//                              tplayer.cpp:5106 (9)
//         0051988e     CMP        EAX,-0x1
//         00519891     JZ         LAB_00519928
//                              tplayer.cpp:5112 (12)
//         00519897     CMP        EAX,0x9
//         0051989a     JA         switchD_0051989c::default
//                              Symbol Ref: No symbol: redo_mouseFunc
//                               switchD_0051989c::switchD                                    XREF[1]:     005198ea(j)
//         0051989c     JMP        dword ptr [EAX*0x4 + switchD_0051989c::switchd   = 00519934
//                                                                                  = 005198a3
//                               switchD_0051989c::caseD_8                                    XREF[3]:     0051989c(j), 00519acc(*),
//                               switchD_0051989c::caseD_1                                                 00519ae8(*)
//                              tplayer.cpp:5124 (23)
//         005198a3     TEST       byte ptr [EDI + 0x198],0x1
//         005198aa     JZ         LAB_005198ba
//         005198ac     MOV        this,dword ptr [ESP + 0x18]
//         005198b0     CMP        byte ptr [ECX + this->_padding_],0x2
//         005198b4     JBE        LAB_00519946
//                               LAB_005198ba                                                 XREF[1]:     005198aa(j)
//                              tplayer.cpp:5131 (5)
//         005198ba     CMP        EAX,0x8
//         005198bd     JNZ        LAB_005198fc
//                              tplayer.cpp:5133 (5)
//         005198bf     MOV        EBP,0x32
//                              tplayer.cpp:5134 (5)
//         005198c4     MOV        EAX,0x7
//                              tplayer.cpp:5135 (2)
//         005198c9     JMP        LAB_005198e7
//                               switchD_0051989c::caseD_9                                    XREF[3]:     0051989c(j), 00519ae0(*),
//                               switchD_0051989c::caseD_6                                                 00519aec(*)
//                              tplayer.cpp:5194 (13)
//         005198cb     TEST       byte ptr [EDI + 0x198],0x40
//         005198d2     JNZ        LAB_00519a27
//                              tplayer.cpp:5201 (5)
//         005198d8     CMP        EAX,0x9
//         005198db     JNZ        LAB_005198fc
//                              tplayer.cpp:5203 (5)
//         005198dd     MOV        EBP,0x32
//                              tplayer.cpp:5204 (5)
//         005198e2     MOV        EAX,0x1
//                               LAB_005198e7                                                 XREF[1]:     005198c9(j)
//                              tplayer.cpp:5112 (5)
//         005198e7     CMP        EAX,0x9
//         005198ea     JBE        switchD_0051989c::switchD
//                               switchD_0051989c::default                                    XREF[1]:     0051989a(j)
//                              tplayer.cpp:5232 (16)
//         005198ec     MOV        this,dword ptr [ESP + 0x38]
//         005198f0     MOV        dword ptr [EBX],0x0
//         005198f6     MOV        dword ptr [this->_padding_],0x0
//                               LAB_005198fc                                                 XREF[23]:    005198bd(j), 005198db(j),
//                                                                                                         00519944(j), 00519956(j),
//                                                                                                         0051995f(j), 0051996a(j),
//                                                                                                         0051997c(j), 00519988(j),
//                                                                                                         005199a2(j), 005199b6(j),
//                                                                                                         005199c0(j), 005199d6(j),
//                                                                                                         005199e2(j), 00519a02(j),
//                                                                                                         00519a0c(j), 00519a22(j),
//                                                                                                         00519a37(j), 00519a43(j),
//                                                                                                         00519a5f(j), 00519a7b(j), [more]
//                              tplayer.cpp:5239 (29)
//         005198fc     MOV        this,dword ptr [ESP + 0x24]
//         00519900     MOV        EAX,0x1
//         00519905     CMP        this,EAX
//         00519907     JNZ        LAB_0051992a
//         00519909     MOV        this,dword ptr [EBX]
//         0051990b     XOR        ESI,ESI
//         0051990d     CMP        this,ESI
//         0051990f     JNZ        LAB_0051992a
//         00519911     MOV        EDX,dword ptr [ESP + 0x38]
//         00519915     CMP        dword ptr [EDX],ESI
//         00519917     JNZ        LAB_0051992a
//                              tplayer.cpp:5241 (6)
//         00519919     MOV        dword ptr [EDI + 0x198],ESI
//                              tplayer.cpp:5243 (9)
//         0051991f     MOV        EDI,dword ptr [ESP + 0x28]
//         00519923     JMP        LAB_005197aa
//                               LAB_00519928                                                 XREF[5]:     00519712(j), 00519774(j),
//                                                                                                         00519783(j), 0051983f(j),
//                                                                                                         00519891(j)
//                              tplayer.cpp:5001 (2)
//         00519928     XOR        EAX,EAX
//                               LAB_0051992a                                                 XREF[3]:     00519907(j), 0051990f(j),
//                                                                                                         00519917(j)
//                              tplayer.cpp:5248 (10)
//         0051992a     POP        EDI
//         0051992b     POP        ESI
//         0051992c     POP        EBP
//         0051992d     POP        EBX
//         0051992e     ADD        ESP,0x1c
//         00519931     RET        0xc
//                               switchD_0051989c::caseD_0                                    XREF[2]:     0051989c(j), 00519ac8(*)
//                              tplayer.cpp:5117 (16)
//         00519934     MOV        EAX,dword ptr [ESP + 0x38]
//         00519938     LEA        EDX,[EBP + ESI*0x1]
//         0051993c     MOV        dword ptr [EBX],0x0
//         00519942     MOV        dword ptr [EAX],EDX
//                              tplayer.cpp:5118 (2)
//         00519944     JMP        LAB_005198fc
//                               LAB_00519946                                                 XREF[1]:     005198b4(j)
//                              tplayer.cpp:5127 (16)
//         00519946     MOV        EDX,dword ptr [ESP + 0x38]
//         0051994a     LEA        this,[EBP + ESI*0x1]
//         0051994e     MOV        dword ptr [EBX],0x4
//         00519954     MOV        dword ptr [EDX],this
//                              tplayer.cpp:5138 (2)
//         00519956     JMP        LAB_005198fc
//                               switchD_0051989c::caseD_2                                    XREF[2]:     0051989c(j), 00519ad0(*)
//                              tplayer.cpp:5143 (9)
//         00519958     TEST       byte ptr [EDI + 0x198],0x2
//         0051995f     JZ         LAB_005198fc
//                              tplayer.cpp:5148 (2)
//         00519961     JMP        LAB_005199c6
//                               switchD_0051989c::caseD_3                                    XREF[2]:     0051989c(j), 00519ad4(*)
//                              tplayer.cpp:5153 (9)
//         00519963     TEST       byte ptr [EDI + 0x198],0x4
//         0051996a     JZ         LAB_005198fc
//                              tplayer.cpp:5156 (16)
//         0051996c     MOV        EAX,dword ptr [ESP + 0x38]
//         00519970     LEA        EDX,[EBP + ESI*0x1]
//         00519974     MOV        dword ptr [EBX],0x5
//         0051997a     MOV        dword ptr [EAX],EDX
//                              tplayer.cpp:5158 (5)
//         0051997c     JMP        LAB_005198fc
//                               switchD_0051989c::caseD_4                                    XREF[2]:     0051989c(j), 00519ad8(*)
//                              tplayer.cpp:5163 (13)
//         00519981     TEST       byte ptr [EDI + 0x198],0x10
//         00519988     JZ         LAB_005198fc
//                              tplayer.cpp:5165 (26)
//         0051998e     CMP        dword ptr [DAT_0086bc8c],0x1
//         00519995     JNZ        LAB_005199a8
//         00519997     MOV        this,dword ptr [ESP + 0x30]
//         0051999b     MOV        EAX,[DAT_0086bc88]
//         005199a0     CMP        this,EAX
//         005199a2     JZ         LAB_005198fc
//                               LAB_005199a8                                                 XREF[1]:     00519995(j)
//                              tplayer.cpp:5167 (12)
//         005199a8     MOV        EDX,dword ptr [ESP + 0x18]
//         005199ac     FLD        float ptr [EDX + 0x30]
//         005199af     CALL       __ftol                                           undefined __ftol()
//                              tplayer.cpp:5168 (18)
//         005199b4     TEST       EAX,EAX
//         005199b6     JLE        LAB_005198fc
//         005199bc     CMP        EAX,dword ptr [ESP + 0x1c]
//         005199c0     JGE        LAB_005198fc
//                               LAB_005199c6                                                 XREF[1]:     00519961(j)
//                              tplayer.cpp:5171 (21)
//         005199c6     MOV        this,dword ptr [ESP + 0x38]
//         005199ca     LEA        EAX,[EBP + ESI*0x1]
//         005199ce     MOV        dword ptr [EBX],0x5
//         005199d4     MOV        dword ptr [this->_padding_],EAX
//         005199d6     JMP        LAB_005198fc
//                               switchD_0051989c::caseD_5                                    XREF[2]:     0051989c(j), 00519adc(*)
//                              tplayer.cpp:5178 (13)
//         005199db     TEST       byte ptr [EDI + 0x198],0x20
//         005199e2     JZ         LAB_005198fc
//                              tplayer.cpp:5180 (16)
//         005199e8     MOV        EAX,dword ptr [ESP + 0x18]
//         005199ec     MOV        this,byte ptr [EAX + 0x48]
//         005199ef     TEST       this,this
//         005199f1     JNZ        LAB_005199f8
//         005199f3     MOV        EBP,0x32
//                               LAB_005199f8                                                 XREF[1]:     005199f1(j)
//                              tplayer.cpp:5182 (8)
//         005199f8     FLD        float ptr [EAX + 0x30]
//         005199fb     CALL       __ftol                                           undefined __ftol()
//                              tplayer.cpp:5183 (18)
//         00519a00     TEST       EAX,EAX
//         00519a02     JLE        LAB_005198fc
//         00519a08     CMP        EAX,dword ptr [ESP + 0x1c]
//         00519a0c     JGE        LAB_005198fc
//                              tplayer.cpp:5186 (21)
//         00519a12     MOV        EAX,dword ptr [ESP + 0x38]
//         00519a16     LEA        EDX,[EBP + ESI*0x1]
//         00519a1a     MOV        dword ptr [EBX],0x3
//         00519a20     MOV        dword ptr [EAX],EDX
//         00519a22     JMP        LAB_005198fc
//                               LAB_00519a27                                                 XREF[1]:     005198d2(j)
//                              tplayer.cpp:5197 (16)
//         00519a27     MOV        EDX,dword ptr [ESP + 0x38]
//         00519a2b     LEA        this,[EBP + ESI*0x1]
//         00519a2f     MOV        dword ptr [EBX],0x3
//         00519a35     MOV        dword ptr [EDX],this
//                              tplayer.cpp:5208 (5)
//         00519a37     JMP        LAB_005198fc
//                               switchD_0051989c::caseD_7                                    XREF[2]:     0051989c(j), 00519ae4(*)
//                              tplayer.cpp:5213 (13)
//         00519a3c     TEST       byte ptr [EDI + 0x198],0x80
//         00519a43     JZ         LAB_005198fc
//                              tplayer.cpp:5216 (28)
//         00519a49     CMP        EDX,0x12
//         00519a4c     JNZ        LAB_00519a65
//         00519a4e     MOV        EAX,dword ptr [EDI + 0x50]
//         00519a51     FLD        float ptr [EAX + 0x6c]
//         00519a54     FCOMP      float ptr [DAT_00576828]
//         00519a5a     FNSTSW     AX
//         00519a5c     TEST       AH,0x40
//         00519a5f     JNZ        LAB_005198fc
//                               LAB_00519a65                                                 XREF[1]:     00519a4c(j)
//                              tplayer.cpp:5217 (28)
//         00519a65     CMP        EDX,0x3
//         00519a68     JNZ        LAB_00519a9d
//         00519a6a     MOV        this,dword ptr [EDI + 0x50]
//         00519a6d     FLD        float ptr [ECX + this->_padding_]
//         00519a70     FCOMP      float ptr [DAT_00576828]
//         00519a76     FNSTSW     AX
//         00519a78     TEST       AH,0x40
//         00519a7b     JNZ        LAB_005198fc
//                              tplayer.cpp:5220 (4)
//         00519a81     CMP        EDX,EDX
//         00519a83     JNZ        LAB_00519a9d
//                              tplayer.cpp:5221 (24)
//         00519a85     MOV        EAX,dword ptr [ESP + 0x20]
//         00519a89     CMP        EAX,0x6d
//         00519a8c     JZ         LAB_005198fc
//         00519a92     CMP        EAX,0x114
//         00519a97     JZ         LAB_005198fc
//                               LAB_00519a9d                                                 XREF[2]:     00519a68(j), 00519a83(j)
//                              tplayer.cpp:5224 (16)
//         00519a9d     MOV        EAX,dword ptr [ESP + 0x38]
//         00519aa1     LEA        EDX,[EBP + ESI*0x1]
//         00519aa5     MOV        dword ptr [EBX],0x5
//         00519aab     MOV        dword ptr [EAX],EDX
//                              tplayer.cpp:5226 (5)
//         00519aad     JMP        LAB_005198fc
    return 0;
}

TRIBE_Gaia::TRIBE_Gaia(int param_1, TRIBE_World* param_2, uchar param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Gaia(TRIBE_Gaia * this, int param_1, TRIB
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00519b12(R)
//              TRIBE_World *     Stack[0x8]:4   param_2                   XREF[1]:     00519b0e(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00519b06(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00519b2e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00519b7b(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00519b1b(W)
//                               ??0TRIBE_Gaia@@QAE@HPAVTRIBE_World@@E@Z                      XREF[1]:     load_player:0052e8ae(c)
//                               TRIBE_Gaia::TRIBE_Gaia
//                              tplayer.cpp:5263 (52)
//         00519af0     PUSH       -0x1
//         00519af2     PUSH       FUN_005612d8
//         00519af7     MOV        EAX,FS:[0x0]
//         00519afd     PUSH       EAX
//         00519afe     MOV        dword ptr FS:[0x0],ESP
//         00519b05     PUSH       this
//         00519b06     MOV        EAX,dword ptr [ESP + param_3]
//         00519b0a     PUSH       ESI
//         00519b0b     MOV        ESI,this
//         00519b0d     PUSH       EDI
//         00519b0e     MOV        this,dword ptr [ESP + param_2]
//         00519b12     MOV        EDI,dword ptr [ESP + param_1]
//         00519b16     PUSH       EAX
//         00519b17     PUSH       this
//         00519b18     PUSH       EDI
//         00519b19     MOV        this,ESI
//         00519b1b     MOV        dword ptr [ESP + local_10],ESI
//         00519b1f     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, i
//                              tplayer.cpp:5266 (36)
//         00519b24     LEA        EDX,[ESI + 0x848]
//         00519b2a     PUSH       0x4
//         00519b2c     PUSH       EDX
//         00519b2d     PUSH       EDI
//         00519b2e     MOV        dword ptr [ESP + local_4],0x0
//         00519b36     MOV        dword ptr [ESI],TRIBE_Gaia::`vftable'            = 00519ba0
//         00519b3c     MOV        byte ptr [ESI + 0x48],0x2
//         00519b40     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00519b45     ADD        ESP,0xc
//                              tplayer.cpp:5267 (18)
//         00519b48     LEA        EAX,[ESI + 0x84c]
//         00519b4e     PUSH       0x4
//         00519b50     PUSH       EAX
//         00519b51     PUSH       EDI
//         00519b52     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00519b57     ADD        ESP,0xc
//                              tplayer.cpp:5268 (18)
//         00519b5a     LEA        this,[ESI + 0x854]
//         00519b60     PUSH       0x4
//         00519b62     PUSH       this
//         00519b63     PUSH       EDI
//         00519b64     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00519b69     ADD        ESP,0xc
//                              tplayer.cpp:5269 (15)
//         00519b6c     LEA        EDX,[ESI + 0x850]
//         00519b72     PUSH       0x4
//         00519b74     PUSH       EDX
//         00519b75     PUSH       EDI
//         00519b76     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tplayer.cpp:5270 (24)
//         00519b7b     MOV        this,dword ptr [ESP + local_c]
//         00519b7f     ADD        ESP,0xc
//         00519b82     MOV        EAX,ESI
//         00519b84     MOV        dword ptr FS:[0x0],this
//         00519b8b     POP        EDI
//         00519b8c     POP        ESI
//         00519b8d     ADD        ESP,0x10
//         00519b90     RET        0xc
//         00519b93     ??         90h
//         00519b94     NOP
//         00519b95     NOP
//         00519b96     NOP
//         00519b97     NOP
//         00519b98     NOP
//         00519b99     NOP
//         00519b9a     NOP
//         00519b9b     NOP
//         00519b9c     NOP
//         00519b9d     NOP
//         00519b9e     NOP
//         00519b9f     NOP
}

TRIBE_Gaia::TRIBE_Gaia(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Gaia(TRIBE_Gaia * this, TRIBE_World * par
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//              TRIBE_World *     Stack[0x4]:4   param_1                   XREF[1]:     00519bef(R)
//              RGE_Master_Pla    Stack[0x8]:4   param_2                   XREF[1]:     00519bea(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00519bd4(R)
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     00519bdf(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00519bd0(R)
//                               ??0TRIBE_Gaia@@QAE@PAVTRIBE_World@@PAVRGE_Master_Player@@EP  XREF[1]:     setup_gaia:0052e968(c)
//                               TRIBE_Gaia::TRIBE_Gaia
//                              tplayer.cpp:5275 (51)
//         00519bd0     MOV        EAX,dword ptr [ESP + param_5]
//         00519bd4     MOV        EDX,dword ptr [ESP + param_3]
//         00519bd8     PUSH       ESI
//         00519bd9     PUSH       0x0
//         00519bdb     PUSH       0x0
//         00519bdd     MOV        ESI,this
//         00519bdf     MOV        this,dword ptr [ESP + param_4]
//         00519be3     PUSH       0x0
//         00519be5     PUSH       0x1
//         00519be7     PUSH       0x0
//         00519be9     PUSH       EAX
//         00519bea     MOV        EAX,dword ptr [ESP + param_2]
//         00519bee     PUSH       this
//         00519bef     MOV        this,dword ptr [ESP + param_1]
//         00519bf3     PUSH       EDX
//         00519bf4     PUSH       EAX
//         00519bf5     PUSH       this
//         00519bf6     MOV        this,ESI
//         00519bf8     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, T
//         00519bfd     MOV        dword ptr [ESI],TRIBE_Gaia::`vftable'            = 00519ba0
//                              tplayer.cpp:5276 (4)
//         00519c03     MOV        byte ptr [ESI + 0x48],0x2
//                              tplayer.cpp:5278 (10)
//         00519c07     MOV        dword ptr [ESI + 0x848],0x0
//                              tplayer.cpp:5279 (10)
//         00519c11     MOV        dword ptr [ESI + 0x84c],0x1d
//                              tplayer.cpp:5280 (10)
//         00519c1b     MOV        dword ptr [ESI + 0x854],0x0
//                              tplayer.cpp:5281 (10)
//         00519c25     MOV        dword ptr [ESI + 0x850],0x0
//                              tplayer.cpp:5282 (6)
//         00519c2f     MOV        EAX,ESI
//         00519c31     POP        ESI
//         00519c32     RET        0x14
//         00519c35     ??         90h
//         00519c36     NOP
//         00519c37     NOP
//         00519c38     NOP
//         00519c39     NOP
//         00519c3a     NOP
//         00519c3b     NOP
//         00519c3c     NOP
//         00519c3d     NOP
//         00519c3e     NOP
//         00519c3f     NOP
}

void TRIBE_Gaia::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Gaia * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00519c42(R)
//                               ?save@TRIBE_Gaia@@UAEXH@Z                                    XREF[1]:     00576a24(*)
//                               TRIBE_Gaia::save
//                              tplayer.cpp:5286 (2)
//         00519c40     PUSH       ESI
//         00519c41     PUSH       EDI
//                              tplayer.cpp:5287 (12)
//         00519c42     MOV        EDI,dword ptr [ESP + param_1]
//         00519c46     MOV        ESI,this
//         00519c48     PUSH       EDI
//         00519c49     CALL       TRIBE_Player::save                               void save(TRIBE_Player * this, int param_1)
//                              tplayer.cpp:5289 (18)
//         00519c4e     LEA        EAX,[ESI + 0x848]
//         00519c54     PUSH       0x4
//         00519c56     PUSH       EAX
//         00519c57     PUSH       EDI
//         00519c58     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00519c5d     ADD        ESP,0xc
//                              tplayer.cpp:5290 (18)
//         00519c60     LEA        this,[ESI + 0x84c]
//         00519c66     PUSH       0x4
//         00519c68     PUSH       this
//         00519c69     PUSH       EDI
//         00519c6a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00519c6f     ADD        ESP,0xc
//                              tplayer.cpp:5291 (18)
//         00519c72     LEA        EDX,[ESI + 0x854]
//         00519c78     PUSH       0x4
//         00519c7a     PUSH       EDX
//         00519c7b     PUSH       EDI
//         00519c7c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00519c81     ADD        ESP,0xc
//                              tplayer.cpp:5292 (18)
//         00519c84     ADD        ESI,0x850
//         00519c8a     PUSH       0x4
//         00519c8c     PUSH       ESI
//         00519c8d     PUSH       EDI
//         00519c8e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00519c93     ADD        ESP,0xc
//                              tplayer.cpp:5293 (5)
//         00519c96     POP        EDI
//         00519c97     POP        ESI
//         00519c98     RET        0x4
//         00519c9b     ??         90h
//         00519c9c     NOP
//         00519c9d     NOP
//         00519c9e     NOP
//         00519c9f     NOP
    return;
}

void TRIBE_Gaia::update() {
    /* TODO: Stub */
//                              void __thiscall update(TRIBE_Gaia * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//                               ?update@TRIBE_Gaia@@UAEXXZ                                   XREF[1]:     00576a1c(*)
//                               TRIBE_Gaia::update
//                              tplayer.cpp:5297 (15)
//         00519ca0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00519ca3     FLD        float ptr [EAX + 0x84]
//         00519ca9     FADD       float ptr [ECX + this->update_time]
//                              tplayer.cpp:5299 (19)
//         00519caf     FCOM       float ptr [DAT_00576824]
//         00519cb5     FSTP       float ptr [ECX + this->update_time]
//         00519cbb     FNSTSW     AX
//         00519cbd     TEST       AH,0x41
//         00519cc0     JNZ        LAB_00519d01
//                              tplayer.cpp:5302 (2)
//         00519cc2     XOR        EDX,EDX
//                               LAB_00519cc4                                                 XREF[1]:     00519cff(j)
//                              tplayer.cpp:5301 (12)
//         00519cc4     FLD        float ptr [ECX + this->update_time]
//         00519cca     FSUB       float ptr [DAT_00576824]
//                              tplayer.cpp:5302 (7)
//         00519cd0     MOV        EAX,dword ptr [ECX + this->update_nature]
//         00519cd6     INC        EAX
//                              tplayer.cpp:5303 (17)
//         00519cd7     CMP        EAX,0x1e
//         00519cda     MOV        dword ptr [ECX + this->update_nature],EAX
//         00519ce0     FSTP       float ptr [ECX + this->update_time]
//         00519ce6     JNZ        LAB_00519cee
//                              tplayer.cpp:5305 (6)
//         00519ce8     MOV        dword ptr [ECX + this->update_nature],EDX
//                               LAB_00519cee                                                 XREF[1]:     00519ce6(j)
//                              tplayer.cpp:5299 (19)
//         00519cee     FLD        float ptr [ECX + this->update_time]
//         00519cf4     FCOMP      float ptr [DAT_00576824]
//         00519cfa     FNSTSW     AX
//         00519cfc     TEST       AH,0x41
//         00519cff     JZ         LAB_00519cc4
//                               LAB_00519d01                                                 XREF[1]:     00519cc0(j)
//                              tplayer.cpp:5309 (5)
//         00519d01     JMP        RGE_Player::update                               void update(RGE_Player * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00519d06     ??         90h
//         00519d07     NOP
//         00519d08     NOP
//         00519d09     NOP
//         00519d0a     NOP
//         00519d0b     NOP
//         00519d0c     NOP
//         00519d0d     NOP
//         00519d0e     NOP
//         00519d0f     NOP
    return;
}

void TRIBE_Gaia::load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5) {
    /* TODO: Stub */
//                              void __thiscall load_master_object(TRIBE_Gaia * this, int param_1, s
//              void              <VOID>         <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00519d23(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00519d1e(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00519d19(R)
//              RGE_Sprite * *    Stack[0x10]:4  param_4                   XREF[1]:     00519d14(R)
//              RGE_Sound * *     Stack[0x14]:4  param_5                   XREF[1]:     00519d10(R)
//                               ?load_master_object@TRIBE_Gaia@@QAEXHFEPAPAVRGE_Sprite@@PAP
//                               TRIBE_Gaia::load_master_object
//                              tplayer.cpp:5315 (30)
//         00519d10     MOV        EAX,dword ptr [ESP + param_5]
//         00519d14     MOV        EDX,dword ptr [ESP + param_4]
//         00519d18     PUSH       EAX
//         00519d19     MOV        EAX,dword ptr [ESP + param_3]
//         00519d1d     PUSH       EDX
//         00519d1e     MOV        EDX,dword ptr [ESP + param_2]
//         00519d22     PUSH       EAX
//         00519d23     MOV        EAX,dword ptr [ESP + param_1]
//         00519d27     PUSH       EDX
//         00519d28     PUSH       EAX
//         00519d29     CALL       TRIBE_Player::load_master_object                 void load_master_object(TRIBE_Player * this,
//                              tplayer.cpp:5317 (3)
//         00519d2e     RET        0x14
//         00519d31     ??         90h
//         00519d32     NOP
//         00519d33     NOP
//         00519d34     NOP
//         00519d35     NOP
//         00519d36     NOP
//         00519d37     NOP
//         00519d38     NOP
//         00519d39     NOP
//         00519d3a     NOP
//         00519d3b     NOP
//         00519d3c     NOP
//         00519d3d     NOP
//         00519d3e     NOP
//         00519d3f     NOP
    return;
}

void TRIBE_Gaia::random_start() {
    /* TODO: Stub */
//                              void __thiscall random_start(TRIBE_Gaia * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//                               ?random_start@TRIBE_Gaia@@UAEXXZ                             XREF[1]:     00576a30(*)
//                               TRIBE_Gaia::random_start
//                              tplayer.cpp:5321 (1)
//         00519d40     RET
//         00519d41     ??         90h
//         00519d42     NOP
//         00519d43     NOP
//         00519d44     NOP
//         00519d45     NOP
//         00519d46     NOP
//         00519d47     NOP
//         00519d48     NOP
//         00519d49     NOP
//         00519d4a     NOP
//         00519d4b     NOP
//         00519d4c     NOP
//         00519d4d     NOP
//         00519d4e     NOP
//         00519d4f     NOP
    return;
}

void TRIBE_Player::scenario_postload(int param_1, long* param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall scenario_postload(TRIBE_Player * this, int param_1,
//              void              <VOID>         <RETURN>
//              TRIBE_Player *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00519d54(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00519d5b(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00519d50(R)
//                               ?scenario_postload@TRIBE_Player@@UAEXHPAJM@Z                 XREF[2]:     005768e0(*), 00576a10(*)
//                               TRIBE_Player::scenario_postload
//                              tplayer.cpp:5326 (25)
//         00519d50     MOV        EAX,dword ptr [ESP + param_3]
//         00519d54     MOV        EDX,dword ptr [ESP + param_1]
//         00519d58     PUSH       ESI
//         00519d59     MOV        ESI,this
//         00519d5b     MOV        this,dword ptr [ESP + param_2]
//         00519d5f     PUSH       EAX
//         00519d60     PUSH       this
//         00519d61     PUSH       EDX
//         00519d62     MOV        this,ESI
//         00519d64     CALL       RGE_Player::scenario_postload                    void scenario_postload(RGE_Player * this, int
//                              tplayer.cpp:5329 (22)
//         00519d69     MOV        EAX,dword ptr [ESI + 0x50]
//         00519d6c     FLD        float ptr [EAX + 0xc8]
//         00519d72     FCOMP      double ptr [DAT_00576830]
//         00519d78     FNSTSW     AX
//         00519d7a     TEST       AH,0x41
//         00519d7d     JNZ        LAB_00519d91
//                              tplayer.cpp:5332 (18)
//         00519d7f     MOV        this,dword ptr [ESI + 0x3c]
//         00519d82     MOV        dword ptr [ESI + 0x100],0x1
//         00519d8c     CALL       RGE_Game_World::update_mutual_allies             void update_mutual_allies(RGE_Game_World * th
//                               LAB_00519d91                                                 XREF[1]:     00519d7d(j)
//                              tplayer.cpp:5335 (4)
//         00519d91     POP        ESI
//         00519d92     RET        0xc
//         00519d95     ??         90h
//         00519d96     NOP
//         00519d97     NOP
//         00519d98     NOP
//         00519d99     NOP
//         00519d9a     NOP
//         00519d9b     NOP
//         00519d9c     NOP
//         00519d9d     NOP
//         00519d9e     NOP
//         00519d9f     NOP
    return;
}

TRIBE_Gaia::~TRIBE_Gaia() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Gaia(TRIBE_Gaia * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Gaia *      ECX:4 (auto)   this
//                               ??1TRIBE_Gaia@@UAE@XZ                                        XREF[1]:     `vector_deleting_destructor':00519
//                               TRIBE_Gaia::~TRIBE_Gaia
//         00519bc0     JMP        TRIBE_Player::~TRIBE_Player
//         00519bc5     ??         90h
//         00519bc6     NOP
//         00519bc7     NOP
//         00519bc8     NOP
//         00519bc9     NOP
//         00519bca     NOP
//         00519bcb     NOP
//         00519bcc     NOP
//         00519bcd     NOP
//         00519bce     NOP
//         00519bcf     NOP
}

