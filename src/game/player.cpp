#include "../common.h"
#include "player.h"

RGE_Player::RGE_Player(int param_1, RGE_Game_World* param_2, uchar param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Player(RGE_Player * this, RGE_Game_World *
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0046e7c5(R)
//              RGE_Master_Pla    Stack[0x8]:4   param_2                   XREF[1]:     0046e885(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0046e7de(R)
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     0046e7fb(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0046e7c1(R)
//              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0046e8f2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046e7b8(W), 0046e7e6(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0046e799(W)
//                               ??0RGE_Player@@QAE@PAVRGE_Game_World@@PAVRGE_Master_Player@  XREF[4]:     TRIBE_Player:00511e5e(c),
//                               RGE_Player::RGE_Player                                                    setup_gaia:005424ca(c),
//                                                                                                         setup_players:00542573(c),
//                                                                                                         scenario_make_player:005442af(c)
//                              player.cpp:177 (81)
//         0046e770     PUSH       -0x1
//         0046e772     PUSH       FUN_0055e29d
//         0046e777     MOV        EAX,FS:[0x0]
//         0046e77d     PUSH       EAX
//         0046e77e     MOV        dword ptr FS:[0x0],ESP
//         0046e785     PUSH       this
//         0046e786     PUSH       EBX
//         0046e787     PUSH       EBP
//         0046e788     PUSH       ESI
//         0046e789     MOV        EBP,this
//         0046e78b     XOR        ESI,ESI
//         0046e78d     PUSH       EDI
//         0046e78e     MOV        dword ptr [EBP + 0x4],ESI
//         0046e791     PUSH       0x190
//         0046e796     LEA        this,[EBP + 0x58]
//         0046e799     MOV        dword ptr [ESP + local_10],EBP
//         0046e79d     MOV        dword ptr [EBP + 0x8],0x5
//         0046e7a4     MOV        dword ptr [EBP + 0xc],0xa
//         0046e7ab     CALL       RGE_Tile_List::RGE_Tile_List                     undefined RGE_Tile_List(RGE_Tile_List * this,
//         0046e7b0     PUSH       0x190
//         0046e7b5     LEA        this,[EBP + 0x6c]
//         0046e7b8     MOV        dword ptr [ESP + local_4],ESI
//         0046e7bc     CALL       RGE_Tile_List::RGE_Tile_List                     undefined RGE_Tile_List(RGE_Tile_List * this,
//                              player.cpp:188 (4)
//         0046e7c1     MOV        this,byte ptr [ESP + param_5]
//                              player.cpp:190 (25)
//         0046e7c5     MOV        EDX,dword ptr [ESP + param_1]
//         0046e7c9     MOV        dword ptr [EBP],RGE_Player::`vftable'            = 0046e750
//         0046e7d0     MOV        EAX,[pathingCapValue]                            = 2h
//         0046e7d5     MOV        dword ptr [EBP + 0x8],EAX
//         0046e7d8     MOV        byte ptr [EBP + 0x105],this
//                              player.cpp:191 (6)
//         0046e7de     MOVZX      AX,byte ptr [ESP + param_3]
//                              player.cpp:192 (23)
//         0046e7e4     MOV        this,EBP
//         0046e7e6     MOV        byte ptr [ESP + local_4],0x1
//         0046e7eb     MOV        byte ptr [EBP + 0x48],0x0
//         0046e7ef     MOV        dword ptr [EBP + 0x3c],EDX
//         0046e7f2     MOV        word ptr [EBP + 0x4a],AX
//         0046e7f6     CALL       RGE_Player::reset_selected                       void reset_selected(RGE_Player * this)
//                              player.cpp:195 (13)
//         0046e7fb     MOV        this,dword ptr [ESP + param_4]
//         0046e7ff     LEA        EAX,[EBP + 0x44]
//         0046e802     CMP        this,ESI
//         0046e804     MOV        dword ptr [EAX],ESI
//         0046e806     JZ         LAB_0046e812
//                              player.cpp:196 (10)
//         0046e808     PUSH       this
//         0046e809     PUSH       EAX
//         0046e80a     CALL       getstring                                        void getstring(char * * param_1, char * param
//         0046e80f     ADD        ESP,0x8
//                               LAB_0046e812                                                 XREF[1]:     0046e806(j)
//                              player.cpp:198 (31)
//         0046e812     MOV        this,dword ptr [EBP + 0x3c]
//         0046e815     MOV        EBX,0x1
//         0046e81a     MOVSX      EDX,word ptr [ECX + this->world]
//         0046e81e     PUSH       EDX
//         0046e81f     PUSH       EBX
//         0046e820     CALL       calloc                                           undefined calloc()
//         0046e825     LEA        EDX,[EBP + 0x88]
//         0046e82b     MOV        dword ptr [EBP + 0x84],EAX
//                              player.cpp:200 (15)
//         0046e831     MOV        this,0x9
//         0046e836     OR         EAX,0xffffffff
//         0046e839     MOV        EDI,EDX
//         0046e83b     ADD        ESP,0x8
//         0046e83e     STOSD.REP  ES:EDI
//                              player.cpp:201 (11)
//         0046e840     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046e843     XOR        this,this
//         0046e845     CMP        word ptr [EAX + 0x3c],SI
//         0046e849     JLE        LAB_0046e885
//                               LAB_0046e84b                                                 XREF[1]:     0046e883(j)
//                              player.cpp:203 (13)
//         0046e84b     MOV        EDI,dword ptr [EBP + 0x84]
//         0046e851     MOVSX      EAX,this
//         0046e854     MOV        byte ptr [EAX + EDI*0x1],0x1
//                              player.cpp:205 (6)
//         0046e858     CMP        this,word ptr [EBP + 0x4a]
//         0046e85c     JNZ        LAB_0046e867
//                              player.cpp:206 (7)
//         0046e85e     MOV        dword ptr [EBP + EAX*0x4 + 0x88],EBX
//                              player.cpp:207 (7)
//         0046e865     JMP        LAB_0046e87b
//                               LAB_0046e867                                                 XREF[1]:     0046e85c(j)
//         0046e867     CMP        this,SI
//         0046e86a     JNZ        LAB_0046e870
//                              player.cpp:208 (2)
//         0046e86c     MOV        dword ptr [EDX],ESI
//                              player.cpp:209 (2)
//         0046e86e     JMP        LAB_0046e87b
//                               LAB_0046e870                                                 XREF[1]:     0046e86a(j)
//                              player.cpp:210 (11)
//         0046e870     MOV        dword ptr [EBP + EAX*0x4 + 0x88],0x3
//                               LAB_0046e87b                                                 XREF[2]:     0046e865(j), 0046e86e(j)
//                              player.cpp:201 (10)
//         0046e87b     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046e87e     INC        this
//         0046e87f     CMP        this,word ptr [EAX + 0x3c]
//         0046e883     JL         LAB_0046e84b
//                               LAB_0046e885                                                 XREF[1]:     0046e849(j)
//                              player.cpp:220 (39)
//         0046e885     MOV        EBX,dword ptr [ESP + param_2]
//         0046e889     MOV        dword ptr [EBP + 0xd0],ESI
//         0046e88f     MOV        dword ptr [EBP + 0xd4],ESI
//         0046e895     MOV        dword ptr [EBP + 0xd8],ESI
//         0046e89b     MOV        dword ptr [EBP + 0x100],ESI
//         0046e8a1     MOV        byte ptr [EBP + 0x104],0x0
//         0046e8a8     MOV        AX,word ptr [EBX + 0x18]
//                              player.cpp:221 (9)
//         0046e8ac     CMP        AX,SI
//         0046e8af     MOV        word ptr [EBP + 0x22],AX
//         0046e8b3     JLE        LAB_0046e8f2
//                              player.cpp:223 (14)
//         0046e8b5     MOVSX      this,AX
//         0046e8b8     PUSH       0x4
//         0046e8ba     PUSH       this
//         0046e8bb     CALL       calloc                                           undefined calloc()
//         0046e8c0     ADD        ESP,0x8
//                              player.cpp:224 (11)
//         0046e8c3     XOR        EDI,EDI
//         0046e8c5     CMP        word ptr [EBP + 0x22],SI
//         0046e8c9     MOV        dword ptr [EBP + 0x24],EAX
//         0046e8cc     JLE        LAB_0046e8f2
//                               LAB_0046e8ce                                                 XREF[1]:     0046e8ee(j)
//                              player.cpp:225 (16)
//         0046e8ce     MOV        EDX,dword ptr [EBX + 0x1c]
//         0046e8d1     MOVSX      ESI,DI
//         0046e8d4     SHL        ESI,0x2
//         0046e8d7     MOV        this,dword ptr [ESI + EDX*0x1]
//         0046e8da     TEST       this,this
//         0046e8dc     JZ         LAB_0046e8e9
//                              player.cpp:226 (18)
//         0046e8de     MOV        EAX,dword ptr [this->_padding_]
//         0046e8e0     CALL       dword ptr [EAX + 0x1c]
//         0046e8e3     MOV        this,dword ptr [EBP + 0x24]
//         0046e8e6     MOV        dword ptr [ESI + this->_padding_*0x1],EAX
//                               LAB_0046e8e9                                                 XREF[1]:     0046e8dc(j)
//         0046e8e9     INC        EDI
//         0046e8ea     CMP        DI,word ptr [EBP + 0x22]
//         0046e8ee     JL         LAB_0046e8ce
//                              player.cpp:224 (2)
//         0046e8f0     XOR        ESI,ESI
//                               LAB_0046e8f2                                                 XREF[2]:     0046e8b3(j), 0046e8cc(j)
//                              player.cpp:229 (12)
//         0046e8f2     MOV        AL,byte ptr [ESP + param_6]
//         0046e8f6     TEST       AL,AL
//         0046e8f8     JZ         LAB_0046e9c0
//                              player.cpp:231 (34)
//         0046e8fe     PUSH       0xc
//         0046e900     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e905     ADD        ESP,0x4
//         0046e908     MOV        dword ptr [ESP + 0x34],EAX
//         0046e90c     CMP        EAX,ESI
//         0046e90e     MOV        byte ptr [ESP + 0x1c],0x2
//         0046e913     JZ         LAB_0046e91e
//         0046e915     MOV        this,EAX
//         0046e917     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e91c     JMP        LAB_0046e920
//                               LAB_0046e91e                                                 XREF[1]:     0046e913(j)
//         0046e91e     XOR        EAX,EAX
//                               LAB_0046e920                                                 XREF[1]:     0046e91c(j)
//                              player.cpp:232 (42)
//         0046e920     PUSH       0xc
//         0046e922     MOV        byte ptr [ESP + 0x20],0x1
//         0046e927     MOV        dword ptr [EBP + 0x28],EAX
//         0046e92a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e92f     ADD        ESP,0x4
//         0046e932     MOV        dword ptr [ESP + 0x34],EAX
//         0046e936     CMP        EAX,ESI
//         0046e938     MOV        byte ptr [ESP + 0x1c],0x3
//         0046e93d     JZ         LAB_0046e948
//         0046e93f     MOV        this,EAX
//         0046e941     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e946     JMP        LAB_0046e94a
//                               LAB_0046e948                                                 XREF[1]:     0046e93d(j)
//         0046e948     XOR        EAX,EAX
//                               LAB_0046e94a                                                 XREF[1]:     0046e946(j)
//                              player.cpp:233 (42)
//         0046e94a     PUSH       0xc
//         0046e94c     MOV        byte ptr [ESP + 0x20],0x1
//         0046e951     MOV        dword ptr [EBP + 0x2c],EAX
//         0046e954     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e959     ADD        ESP,0x4
//         0046e95c     MOV        dword ptr [ESP + 0x34],EAX
//         0046e960     CMP        EAX,ESI
//         0046e962     MOV        byte ptr [ESP + 0x1c],0x4
//         0046e967     JZ         LAB_0046e972
//         0046e969     MOV        this,EAX
//         0046e96b     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e970     JMP        LAB_0046e974
//                               LAB_0046e972                                                 XREF[1]:     0046e967(j)
//         0046e972     XOR        EAX,EAX
//                               LAB_0046e974                                                 XREF[1]:     0046e970(j)
//                              player.cpp:235 (15)
//         0046e974     MOV        this,EBP
//         0046e976     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e97b     MOV        dword ptr [EBP + 0x30],EAX
//         0046e97e     CALL       RGE_Player::new_victory                          void new_victory(RGE_Player * this)
//                              player.cpp:236 (47)
//         0046e983     PUSH       0x38
//         0046e985     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e98a     ADD        ESP,0x4
//         0046e98d     MOV        dword ptr [ESP + 0x34],EAX
//         0046e991     CMP        EAX,ESI
//         0046e993     MOV        byte ptr [ESP + 0x1c],0x5
//         0046e998     JZ         LAB_0046e9b4
//         0046e99a     MOV        EDX,dword ptr [ESP + 0x24]
//         0046e99e     PUSH       EBP
//         0046e99f     MOV        this,dword ptr [EDX + 0x28]
//         0046e9a2     PUSH       this=>DAT_fffffff8
//         0046e9a3     MOV        this,EAX
//         0046e9a5     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         0046e9aa     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e9af     MOV        dword ptr [EBP + 0x38],EAX
//                              player.cpp:238 (2)
//         0046e9b2     JMP        LAB_0046e9cf
//                               LAB_0046e9b4                                                 XREF[1]:     0046e998(j)
//                              player.cpp:236 (10)
//         0046e9b4     XOR        EAX,EAX
//         0046e9b6     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e9bb     MOV        dword ptr [EBP + 0x38],EAX
//                              player.cpp:238 (2)
//         0046e9be     JMP        LAB_0046e9cf
//                               LAB_0046e9c0                                                 XREF[1]:     0046e8f8(j)
//                              player.cpp:240 (3)
//         0046e9c0     MOV        dword ptr [EBP + 0x28],ESI
//                              player.cpp:241 (3)
//         0046e9c3     MOV        dword ptr [EBP + 0x2c],ESI
//                              player.cpp:242 (3)
//         0046e9c6     MOV        dword ptr [EBP + 0x30],ESI
//                              player.cpp:243 (3)
//         0046e9c9     MOV        dword ptr [EBP + 0x34],ESI
//                              player.cpp:244 (3)
//         0046e9cc     MOV        dword ptr [EBP + 0x38],ESI
//                               LAB_0046e9cf                                                 XREF[2]:     0046e9b2(j), 0046e9be(j)
//                              player.cpp:247 (40)
//         0046e9cf     PUSH       0x1c
//         0046e9d1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e9d6     ADD        ESP,0x4
//         0046e9d9     MOV        dword ptr [ESP + 0x34],EAX
//         0046e9dd     CMP        EAX,ESI
//         0046e9df     MOV        byte ptr [ESP + 0x1c],0x6
//         0046e9e4     JZ         LAB_0046e9f2
//         0046e9e6     PUSH       0x64
//         0046e9e8     PUSH       EBP=>DAT_fffffff8
//         0046e9e9     MOV        this,EAX
//         0046e9eb     CALL       RGE_Doppleganger_Creator::RGE_Doppleganger_Cre   undefined RGE_Doppleganger_Creator(RGE_Dopple
//         0046e9f0     JMP        LAB_0046e9f4
//                               LAB_0046e9f2                                                 XREF[1]:     0046e9e4(j)
//         0046e9f2     XOR        EAX,EAX
//                               LAB_0046e9f4                                                 XREF[1]:     0046e9f0(j)
//         0046e9f4     MOV        dword ptr [EBP + 0x40],EAX
//                              player.cpp:249 (4)
//         0046e9f7     MOV        AX,word ptr [EBX + 0x20]
//                              player.cpp:250 (14)
//         0046e9fb     CMP        AX,SI
//         0046e9fe     MOV        byte ptr [ESP + 0x1c],0x1
//         0046ea03     MOV        word ptr [EBP + 0x4c],AX
//         0046ea07     JLE        LAB_0046ea38
//                              player.cpp:252 (11)
//         0046ea09     MOVSX      EDX,AX
//         0046ea0c     PUSH       0x4
//         0046ea0e     PUSH       EDX=>DAT_fffffff8
//         0046ea0f     CALL       calloc                                           undefined calloc()
//                              player.cpp:253 (32)
//         0046ea14     MOVSX      this,word ptr [EBP + 0x4c]
//         0046ea18     SHL        this,0x2
//         0046ea1b     MOV        dword ptr [EBP + 0x50],EAX
//         0046ea1e     MOV        ESI,dword ptr [EBX + 0x24]
//         0046ea21     MOV        EDI,EAX
//         0046ea23     MOV        EAX,this
//         0046ea25     SHR        this,0x2
//         0046ea28     MOVSD.REP  ES:EDI,ESI
//         0046ea2a     MOV        this,EAX
//         0046ea2c     ADD        ESP,0x8
//         0046ea2f     AND        this,0x3
//         0046ea32     MOVSB.REP  ES:EDI,ESI
//                              player.cpp:255 (4)
//         0046ea34     XOR        ESI,ESI
//         0046ea36     JMP        LAB_0046ea3b
//                               LAB_0046ea38                                                 XREF[1]:     0046ea07(j)
//                              player.cpp:256 (3)
//         0046ea38     MOV        dword ptr [EBP + 0x50],ESI
//                               LAB_0046ea3b                                                 XREF[1]:     0046ea36(j)
//                              player.cpp:258 (3)
//         0046ea3b     MOV        this,byte ptr [EBX + 0x28]
//                              player.cpp:260 (56)
//         0046ea3e     MOV        EDX,dword ptr [EBP + 0x3c]
//         0046ea41     MOV        byte ptr [EBP + 0x54],this
//         0046ea44     MOV        this,dword ptr [EDX + 0x28]
//         0046ea47     PUSH       this
//         0046ea48     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//         0046ea4b     CDQ
//         0046ea4c     SUB        EAX,EDX
//         0046ea4e     SAR        EAX,0x1
//         0046ea50     MOV        dword ptr [ESP + 0x38],EAX
//         0046ea54     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0046ea57     FILD       dword ptr [ESP + 0x38]
//         0046ea5b     CDQ
//         0046ea5c     FSTP       float ptr [ESP]
//         0046ea5f     SUB        EAX,EDX
//         0046ea61     PUSH       this=>DAT_fffffff8
//         0046ea62     SAR        EAX,0x1
//         0046ea64     MOV        dword ptr [ESP + 0x3c],EAX
//         0046ea68     MOV        this,EBP
//         0046ea6a     FILD       dword ptr [ESP + 0x3c]
//         0046ea6e     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0046ea71     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                              player.cpp:261 (31)
//         0046ea76     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046ea79     MOV        this,dword ptr [EAX + 0x28]
//         0046ea7c     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//         0046ea7f     CDQ
//         0046ea80     SUB        EAX,EDX
//         0046ea82     SAR        EAX,0x1
//         0046ea84     PUSH       EAX
//         0046ea85     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0046ea88     CDQ
//         0046ea89     SUB        EAX,EDX
//         0046ea8b     MOV        this,EBP
//         0046ea8d     SAR        EAX,0x1
//         0046ea8f     PUSH       EAX=>DAT_fffffff8
//         0046ea90     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
//                              player.cpp:268 (42)
//         0046ea95     MOV        this,byte ptr [ESP + 0x38]
//         0046ea99     MOV        byte ptr [EBP + 0x80],0x0
//         0046eaa0     MOV        byte ptr [EBP + 0x81],0x0
//         0046eaa7     MOV        dword ptr [EBP + 0x108],ESI
//         0046eaad     MOVSX      EAX,word ptr [EBX + 0x2a]
//         0046eab1     TEST       this,this
//         0046eab3     MOV        dword ptr [EBP + 0x10c],EAX
//         0046eab9     JZ         LAB_0046ead3
//         0046eabb     CMP        EAX,ESI
//         0046eabd     JL         LAB_0046ead3
//                              player.cpp:269 (20)
//         0046eabf     MOV        this,dword ptr [EBP + 0x3c]
//         0046eac2     MOV        AX,word ptr [EBP + 0x10c]
//         0046eac9     PUSH       EBP
//         0046eaca     PUSH       EAX=>DAT_fffffff8
//         0046eacb     MOV        this,dword ptr [ECX + this->attribute_num]
//         0046eace     MOV        EDX,dword ptr [this->_padding_]
//         0046ead0     CALL       dword ptr [EDX + 0x8]
//                               LAB_0046ead3                                                 XREF[2]:     0046eab9(j), 0046eabd(j)
//                              player.cpp:274 (30)
//         0046ead3     MOV        this,dword ptr [ESP + 0x14]
//         0046ead7     MOV        dword ptr [EBP + 0x14],ESI
//         0046eada     POP        EDI
//         0046eadb     MOV        byte ptr [EBP + 0x20],0x0
//         0046eadf     MOV        EAX,EBP
//         0046eae1     POP        ESI
//         0046eae2     POP        EBP
//         0046eae3     MOV        dword ptr FS:[0x0],this
//         0046eaea     POP        EBX
//         0046eaeb     ADD        ESP,0x10
//         0046eaee     RET        0x18
//         0046eaf1     ??         90h
//         0046eaf2     NOP
//         0046eaf3     NOP
//         0046eaf4     NOP
//         0046eaf5     NOP
//         0046eaf6     NOP
//         0046eaf7     NOP
//         0046eaf8     NOP
//         0046eaf9     NOP
//         0046eafa     NOP
//         0046eafb     NOP
//         0046eafc     NOP
//         0046eafd     NOP
//         0046eafe     NOP
//         0046eaff     NOP
}

RGE_Player::RGE_Player(RGE_Game_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Player(RGE_Player * this, RGE_Game_World *
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0046e7c5(R)
//              RGE_Master_Pla    Stack[0x8]:4   param_2                   XREF[1]:     0046e885(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0046e7de(R)
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     0046e7fb(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0046e7c1(R)
//              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0046e8f2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046e7b8(W), 0046e7e6(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0046e799(W)
//                               ??0RGE_Player@@QAE@PAVRGE_Game_World@@PAVRGE_Master_Player@  XREF[4]:     TRIBE_Player:00511e5e(c),
//                               RGE_Player::RGE_Player                                                    setup_gaia:005424ca(c),
//                                                                                                         setup_players:00542573(c),
//                                                                                                         scenario_make_player:005442af(c)
//                              player.cpp:177 (81)
//         0046e770     PUSH       -0x1
//         0046e772     PUSH       FUN_0055e29d
//         0046e777     MOV        EAX,FS:[0x0]
//         0046e77d     PUSH       EAX
//         0046e77e     MOV        dword ptr FS:[0x0],ESP
//         0046e785     PUSH       this
//         0046e786     PUSH       EBX
//         0046e787     PUSH       EBP
//         0046e788     PUSH       ESI
//         0046e789     MOV        EBP,this
//         0046e78b     XOR        ESI,ESI
//         0046e78d     PUSH       EDI
//         0046e78e     MOV        dword ptr [EBP + 0x4],ESI
//         0046e791     PUSH       0x190
//         0046e796     LEA        this,[EBP + 0x58]
//         0046e799     MOV        dword ptr [ESP + local_10],EBP
//         0046e79d     MOV        dword ptr [EBP + 0x8],0x5
//         0046e7a4     MOV        dword ptr [EBP + 0xc],0xa
//         0046e7ab     CALL       RGE_Tile_List::RGE_Tile_List                     undefined RGE_Tile_List(RGE_Tile_List * this,
//         0046e7b0     PUSH       0x190
//         0046e7b5     LEA        this,[EBP + 0x6c]
//         0046e7b8     MOV        dword ptr [ESP + local_4],ESI
//         0046e7bc     CALL       RGE_Tile_List::RGE_Tile_List                     undefined RGE_Tile_List(RGE_Tile_List * this,
//                              player.cpp:188 (4)
//         0046e7c1     MOV        this,byte ptr [ESP + param_5]
//                              player.cpp:190 (25)
//         0046e7c5     MOV        EDX,dword ptr [ESP + param_1]
//         0046e7c9     MOV        dword ptr [EBP],RGE_Player::`vftable'            = 0046e750
//         0046e7d0     MOV        EAX,[pathingCapValue]                            = 2h
//         0046e7d5     MOV        dword ptr [EBP + 0x8],EAX
//         0046e7d8     MOV        byte ptr [EBP + 0x105],this
//                              player.cpp:191 (6)
//         0046e7de     MOVZX      AX,byte ptr [ESP + param_3]
//                              player.cpp:192 (23)
//         0046e7e4     MOV        this,EBP
//         0046e7e6     MOV        byte ptr [ESP + local_4],0x1
//         0046e7eb     MOV        byte ptr [EBP + 0x48],0x0
//         0046e7ef     MOV        dword ptr [EBP + 0x3c],EDX
//         0046e7f2     MOV        word ptr [EBP + 0x4a],AX
//         0046e7f6     CALL       RGE_Player::reset_selected                       void reset_selected(RGE_Player * this)
//                              player.cpp:195 (13)
//         0046e7fb     MOV        this,dword ptr [ESP + param_4]
//         0046e7ff     LEA        EAX,[EBP + 0x44]
//         0046e802     CMP        this,ESI
//         0046e804     MOV        dword ptr [EAX],ESI
//         0046e806     JZ         LAB_0046e812
//                              player.cpp:196 (10)
//         0046e808     PUSH       this
//         0046e809     PUSH       EAX
//         0046e80a     CALL       getstring                                        void getstring(char * * param_1, char * param
//         0046e80f     ADD        ESP,0x8
//                               LAB_0046e812                                                 XREF[1]:     0046e806(j)
//                              player.cpp:198 (31)
//         0046e812     MOV        this,dword ptr [EBP + 0x3c]
//         0046e815     MOV        EBX,0x1
//         0046e81a     MOVSX      EDX,word ptr [ECX + this->world]
//         0046e81e     PUSH       EDX
//         0046e81f     PUSH       EBX
//         0046e820     CALL       calloc                                           undefined calloc()
//         0046e825     LEA        EDX,[EBP + 0x88]
//         0046e82b     MOV        dword ptr [EBP + 0x84],EAX
//                              player.cpp:200 (15)
//         0046e831     MOV        this,0x9
//         0046e836     OR         EAX,0xffffffff
//         0046e839     MOV        EDI,EDX
//         0046e83b     ADD        ESP,0x8
//         0046e83e     STOSD.REP  ES:EDI
//                              player.cpp:201 (11)
//         0046e840     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046e843     XOR        this,this
//         0046e845     CMP        word ptr [EAX + 0x3c],SI
//         0046e849     JLE        LAB_0046e885
//                               LAB_0046e84b                                                 XREF[1]:     0046e883(j)
//                              player.cpp:203 (13)
//         0046e84b     MOV        EDI,dword ptr [EBP + 0x84]
//         0046e851     MOVSX      EAX,this
//         0046e854     MOV        byte ptr [EAX + EDI*0x1],0x1
//                              player.cpp:205 (6)
//         0046e858     CMP        this,word ptr [EBP + 0x4a]
//         0046e85c     JNZ        LAB_0046e867
//                              player.cpp:206 (7)
//         0046e85e     MOV        dword ptr [EBP + EAX*0x4 + 0x88],EBX
//                              player.cpp:207 (7)
//         0046e865     JMP        LAB_0046e87b
//                               LAB_0046e867                                                 XREF[1]:     0046e85c(j)
//         0046e867     CMP        this,SI
//         0046e86a     JNZ        LAB_0046e870
//                              player.cpp:208 (2)
//         0046e86c     MOV        dword ptr [EDX],ESI
//                              player.cpp:209 (2)
//         0046e86e     JMP        LAB_0046e87b
//                               LAB_0046e870                                                 XREF[1]:     0046e86a(j)
//                              player.cpp:210 (11)
//         0046e870     MOV        dword ptr [EBP + EAX*0x4 + 0x88],0x3
//                               LAB_0046e87b                                                 XREF[2]:     0046e865(j), 0046e86e(j)
//                              player.cpp:201 (10)
//         0046e87b     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046e87e     INC        this
//         0046e87f     CMP        this,word ptr [EAX + 0x3c]
//         0046e883     JL         LAB_0046e84b
//                               LAB_0046e885                                                 XREF[1]:     0046e849(j)
//                              player.cpp:220 (39)
//         0046e885     MOV        EBX,dword ptr [ESP + param_2]
//         0046e889     MOV        dword ptr [EBP + 0xd0],ESI
//         0046e88f     MOV        dword ptr [EBP + 0xd4],ESI
//         0046e895     MOV        dword ptr [EBP + 0xd8],ESI
//         0046e89b     MOV        dword ptr [EBP + 0x100],ESI
//         0046e8a1     MOV        byte ptr [EBP + 0x104],0x0
//         0046e8a8     MOV        AX,word ptr [EBX + 0x18]
//                              player.cpp:221 (9)
//         0046e8ac     CMP        AX,SI
//         0046e8af     MOV        word ptr [EBP + 0x22],AX
//         0046e8b3     JLE        LAB_0046e8f2
//                              player.cpp:223 (14)
//         0046e8b5     MOVSX      this,AX
//         0046e8b8     PUSH       0x4
//         0046e8ba     PUSH       this
//         0046e8bb     CALL       calloc                                           undefined calloc()
//         0046e8c0     ADD        ESP,0x8
//                              player.cpp:224 (11)
//         0046e8c3     XOR        EDI,EDI
//         0046e8c5     CMP        word ptr [EBP + 0x22],SI
//         0046e8c9     MOV        dword ptr [EBP + 0x24],EAX
//         0046e8cc     JLE        LAB_0046e8f2
//                               LAB_0046e8ce                                                 XREF[1]:     0046e8ee(j)
//                              player.cpp:225 (16)
//         0046e8ce     MOV        EDX,dword ptr [EBX + 0x1c]
//         0046e8d1     MOVSX      ESI,DI
//         0046e8d4     SHL        ESI,0x2
//         0046e8d7     MOV        this,dword ptr [ESI + EDX*0x1]
//         0046e8da     TEST       this,this
//         0046e8dc     JZ         LAB_0046e8e9
//                              player.cpp:226 (18)
//         0046e8de     MOV        EAX,dword ptr [this->_padding_]
//         0046e8e0     CALL       dword ptr [EAX + 0x1c]
//         0046e8e3     MOV        this,dword ptr [EBP + 0x24]
//         0046e8e6     MOV        dword ptr [ESI + this->_padding_*0x1],EAX
//                               LAB_0046e8e9                                                 XREF[1]:     0046e8dc(j)
//         0046e8e9     INC        EDI
//         0046e8ea     CMP        DI,word ptr [EBP + 0x22]
//         0046e8ee     JL         LAB_0046e8ce
//                              player.cpp:224 (2)
//         0046e8f0     XOR        ESI,ESI
//                               LAB_0046e8f2                                                 XREF[2]:     0046e8b3(j), 0046e8cc(j)
//                              player.cpp:229 (12)
//         0046e8f2     MOV        AL,byte ptr [ESP + param_6]
//         0046e8f6     TEST       AL,AL
//         0046e8f8     JZ         LAB_0046e9c0
//                              player.cpp:231 (34)
//         0046e8fe     PUSH       0xc
//         0046e900     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e905     ADD        ESP,0x4
//         0046e908     MOV        dword ptr [ESP + 0x34],EAX
//         0046e90c     CMP        EAX,ESI
//         0046e90e     MOV        byte ptr [ESP + 0x1c],0x2
//         0046e913     JZ         LAB_0046e91e
//         0046e915     MOV        this,EAX
//         0046e917     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e91c     JMP        LAB_0046e920
//                               LAB_0046e91e                                                 XREF[1]:     0046e913(j)
//         0046e91e     XOR        EAX,EAX
//                               LAB_0046e920                                                 XREF[1]:     0046e91c(j)
//                              player.cpp:232 (42)
//         0046e920     PUSH       0xc
//         0046e922     MOV        byte ptr [ESP + 0x20],0x1
//         0046e927     MOV        dword ptr [EBP + 0x28],EAX
//         0046e92a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e92f     ADD        ESP,0x4
//         0046e932     MOV        dword ptr [ESP + 0x34],EAX
//         0046e936     CMP        EAX,ESI
//         0046e938     MOV        byte ptr [ESP + 0x1c],0x3
//         0046e93d     JZ         LAB_0046e948
//         0046e93f     MOV        this,EAX
//         0046e941     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e946     JMP        LAB_0046e94a
//                               LAB_0046e948                                                 XREF[1]:     0046e93d(j)
//         0046e948     XOR        EAX,EAX
//                               LAB_0046e94a                                                 XREF[1]:     0046e946(j)
//                              player.cpp:233 (42)
//         0046e94a     PUSH       0xc
//         0046e94c     MOV        byte ptr [ESP + 0x20],0x1
//         0046e951     MOV        dword ptr [EBP + 0x2c],EAX
//         0046e954     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e959     ADD        ESP,0x4
//         0046e95c     MOV        dword ptr [ESP + 0x34],EAX
//         0046e960     CMP        EAX,ESI
//         0046e962     MOV        byte ptr [ESP + 0x1c],0x4
//         0046e967     JZ         LAB_0046e972
//         0046e969     MOV        this,EAX
//         0046e96b     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046e970     JMP        LAB_0046e974
//                               LAB_0046e972                                                 XREF[1]:     0046e967(j)
//         0046e972     XOR        EAX,EAX
//                               LAB_0046e974                                                 XREF[1]:     0046e970(j)
//                              player.cpp:235 (15)
//         0046e974     MOV        this,EBP
//         0046e976     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e97b     MOV        dword ptr [EBP + 0x30],EAX
//         0046e97e     CALL       RGE_Player::new_victory                          void new_victory(RGE_Player * this)
//                              player.cpp:236 (47)
//         0046e983     PUSH       0x38
//         0046e985     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e98a     ADD        ESP,0x4
//         0046e98d     MOV        dword ptr [ESP + 0x34],EAX
//         0046e991     CMP        EAX,ESI
//         0046e993     MOV        byte ptr [ESP + 0x1c],0x5
//         0046e998     JZ         LAB_0046e9b4
//         0046e99a     MOV        EDX,dword ptr [ESP + 0x24]
//         0046e99e     PUSH       EBP
//         0046e99f     MOV        this,dword ptr [EDX + 0x28]
//         0046e9a2     PUSH       this=>DAT_fffffff8
//         0046e9a3     MOV        this,EAX
//         0046e9a5     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         0046e9aa     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e9af     MOV        dword ptr [EBP + 0x38],EAX
//                              player.cpp:238 (2)
//         0046e9b2     JMP        LAB_0046e9cf
//                               LAB_0046e9b4                                                 XREF[1]:     0046e998(j)
//                              player.cpp:236 (10)
//         0046e9b4     XOR        EAX,EAX
//         0046e9b6     MOV        byte ptr [ESP + 0x1c],0x1
//         0046e9bb     MOV        dword ptr [EBP + 0x38],EAX
//                              player.cpp:238 (2)
//         0046e9be     JMP        LAB_0046e9cf
//                               LAB_0046e9c0                                                 XREF[1]:     0046e8f8(j)
//                              player.cpp:240 (3)
//         0046e9c0     MOV        dword ptr [EBP + 0x28],ESI
//                              player.cpp:241 (3)
//         0046e9c3     MOV        dword ptr [EBP + 0x2c],ESI
//                              player.cpp:242 (3)
//         0046e9c6     MOV        dword ptr [EBP + 0x30],ESI
//                              player.cpp:243 (3)
//         0046e9c9     MOV        dword ptr [EBP + 0x34],ESI
//                              player.cpp:244 (3)
//         0046e9cc     MOV        dword ptr [EBP + 0x38],ESI
//                               LAB_0046e9cf                                                 XREF[2]:     0046e9b2(j), 0046e9be(j)
//                              player.cpp:247 (40)
//         0046e9cf     PUSH       0x1c
//         0046e9d1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046e9d6     ADD        ESP,0x4
//         0046e9d9     MOV        dword ptr [ESP + 0x34],EAX
//         0046e9dd     CMP        EAX,ESI
//         0046e9df     MOV        byte ptr [ESP + 0x1c],0x6
//         0046e9e4     JZ         LAB_0046e9f2
//         0046e9e6     PUSH       0x64
//         0046e9e8     PUSH       EBP=>DAT_fffffff8
//         0046e9e9     MOV        this,EAX
//         0046e9eb     CALL       RGE_Doppleganger_Creator::RGE_Doppleganger_Cre   undefined RGE_Doppleganger_Creator(RGE_Dopple
//         0046e9f0     JMP        LAB_0046e9f4
//                               LAB_0046e9f2                                                 XREF[1]:     0046e9e4(j)
//         0046e9f2     XOR        EAX,EAX
//                               LAB_0046e9f4                                                 XREF[1]:     0046e9f0(j)
//         0046e9f4     MOV        dword ptr [EBP + 0x40],EAX
//                              player.cpp:249 (4)
//         0046e9f7     MOV        AX,word ptr [EBX + 0x20]
//                              player.cpp:250 (14)
//         0046e9fb     CMP        AX,SI
//         0046e9fe     MOV        byte ptr [ESP + 0x1c],0x1
//         0046ea03     MOV        word ptr [EBP + 0x4c],AX
//         0046ea07     JLE        LAB_0046ea38
//                              player.cpp:252 (11)
//         0046ea09     MOVSX      EDX,AX
//         0046ea0c     PUSH       0x4
//         0046ea0e     PUSH       EDX=>DAT_fffffff8
//         0046ea0f     CALL       calloc                                           undefined calloc()
//                              player.cpp:253 (32)
//         0046ea14     MOVSX      this,word ptr [EBP + 0x4c]
//         0046ea18     SHL        this,0x2
//         0046ea1b     MOV        dword ptr [EBP + 0x50],EAX
//         0046ea1e     MOV        ESI,dword ptr [EBX + 0x24]
//         0046ea21     MOV        EDI,EAX
//         0046ea23     MOV        EAX,this
//         0046ea25     SHR        this,0x2
//         0046ea28     MOVSD.REP  ES:EDI,ESI
//         0046ea2a     MOV        this,EAX
//         0046ea2c     ADD        ESP,0x8
//         0046ea2f     AND        this,0x3
//         0046ea32     MOVSB.REP  ES:EDI,ESI
//                              player.cpp:255 (4)
//         0046ea34     XOR        ESI,ESI
//         0046ea36     JMP        LAB_0046ea3b
//                               LAB_0046ea38                                                 XREF[1]:     0046ea07(j)
//                              player.cpp:256 (3)
//         0046ea38     MOV        dword ptr [EBP + 0x50],ESI
//                               LAB_0046ea3b                                                 XREF[1]:     0046ea36(j)
//                              player.cpp:258 (3)
//         0046ea3b     MOV        this,byte ptr [EBX + 0x28]
//                              player.cpp:260 (56)
//         0046ea3e     MOV        EDX,dword ptr [EBP + 0x3c]
//         0046ea41     MOV        byte ptr [EBP + 0x54],this
//         0046ea44     MOV        this,dword ptr [EDX + 0x28]
//         0046ea47     PUSH       this
//         0046ea48     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//         0046ea4b     CDQ
//         0046ea4c     SUB        EAX,EDX
//         0046ea4e     SAR        EAX,0x1
//         0046ea50     MOV        dword ptr [ESP + 0x38],EAX
//         0046ea54     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0046ea57     FILD       dword ptr [ESP + 0x38]
//         0046ea5b     CDQ
//         0046ea5c     FSTP       float ptr [ESP]
//         0046ea5f     SUB        EAX,EDX
//         0046ea61     PUSH       this=>DAT_fffffff8
//         0046ea62     SAR        EAX,0x1
//         0046ea64     MOV        dword ptr [ESP + 0x3c],EAX
//         0046ea68     MOV        this,EBP
//         0046ea6a     FILD       dword ptr [ESP + 0x3c]
//         0046ea6e     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0046ea71     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                              player.cpp:261 (31)
//         0046ea76     MOV        EAX,dword ptr [EBP + 0x3c]
//         0046ea79     MOV        this,dword ptr [EAX + 0x28]
//         0046ea7c     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//         0046ea7f     CDQ
//         0046ea80     SUB        EAX,EDX
//         0046ea82     SAR        EAX,0x1
//         0046ea84     PUSH       EAX
//         0046ea85     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0046ea88     CDQ
//         0046ea89     SUB        EAX,EDX
//         0046ea8b     MOV        this,EBP
//         0046ea8d     SAR        EAX,0x1
//         0046ea8f     PUSH       EAX=>DAT_fffffff8
//         0046ea90     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
//                              player.cpp:268 (42)
//         0046ea95     MOV        this,byte ptr [ESP + 0x38]
//         0046ea99     MOV        byte ptr [EBP + 0x80],0x0
//         0046eaa0     MOV        byte ptr [EBP + 0x81],0x0
//         0046eaa7     MOV        dword ptr [EBP + 0x108],ESI
//         0046eaad     MOVSX      EAX,word ptr [EBX + 0x2a]
//         0046eab1     TEST       this,this
//         0046eab3     MOV        dword ptr [EBP + 0x10c],EAX
//         0046eab9     JZ         LAB_0046ead3
//         0046eabb     CMP        EAX,ESI
//         0046eabd     JL         LAB_0046ead3
//                              player.cpp:269 (20)
//         0046eabf     MOV        this,dword ptr [EBP + 0x3c]
//         0046eac2     MOV        AX,word ptr [EBP + 0x10c]
//         0046eac9     PUSH       EBP
//         0046eaca     PUSH       EAX=>DAT_fffffff8
//         0046eacb     MOV        this,dword ptr [ECX + this->attribute_num]
//         0046eace     MOV        EDX,dword ptr [this->_padding_]
//         0046ead0     CALL       dword ptr [EDX + 0x8]
//                               LAB_0046ead3                                                 XREF[2]:     0046eab9(j), 0046eabd(j)
//                              player.cpp:274 (30)
//         0046ead3     MOV        this,dword ptr [ESP + 0x14]
//         0046ead7     MOV        dword ptr [EBP + 0x14],ESI
//         0046eada     POP        EDI
//         0046eadb     MOV        byte ptr [EBP + 0x20],0x0
//         0046eadf     MOV        EAX,EBP
//         0046eae1     POP        ESI
//         0046eae2     POP        EBP
//         0046eae3     MOV        dword ptr FS:[0x0],this
//         0046eaea     POP        EBX
//         0046eaeb     ADD        ESP,0x10
//         0046eaee     RET        0x18
//         0046eaf1     ??         90h
//         0046eaf2     NOP
//         0046eaf3     NOP
//         0046eaf4     NOP
//         0046eaf5     NOP
//         0046eaf6     NOP
//         0046eaf7     NOP
//         0046eaf8     NOP
//         0046eaf9     NOP
//         0046eafa     NOP
//         0046eafb     NOP
//         0046eafc     NOP
//         0046eafd     NOP
//         0046eafe     NOP
//         0046eaff     NOP
}

RGE_Player::~RGE_Player() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Player(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0046eb2c(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0046eb1b(W)
//                               ??1RGE_Player@@UAE@XZ                                        XREF[3]:     `scalar_deleting_destructor':0046e
//                               RGE_Player::~RGE_Player                                                   ~TRIBE_Player:0051217b(c),
//                                                                                                         FUN_00561120:00561123(c)
//                              player.cpp:279 (37)
//         0046eb00     PUSH       -0x1
//         0046eb02     PUSH       FUN_0055e2c6
//         0046eb07     MOV        EAX,FS:[0x0]
//         0046eb0d     PUSH       EAX
//         0046eb0e     MOV        dword ptr FS:[0x0],ESP
//         0046eb15     PUSH       this
//         0046eb16     PUSH       EBX
//         0046eb17     PUSH       ESI
//         0046eb18     MOV        ESI,this
//         0046eb1a     PUSH       EDI
//         0046eb1b     MOV        dword ptr [ESP + local_10],ESI
//         0046eb1f     MOV        dword ptr [ESI],RGE_Player::`vftable'            = 0046e750
//                              player.cpp:282 (33)
//         0046eb25     MOV        EDI,dword ptr [ESI + 0x28]
//         0046eb28     XOR        EBX,EBX
//         0046eb2a     CMP        EDI,EBX
//         0046eb2c     MOV        dword ptr [ESP + local_4],0x1
//         0046eb34     JZ         LAB_0046eb46
//         0046eb36     MOV        this,EDI
//         0046eb38     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
//         0046eb3d     PUSH       EDI
//         0046eb3e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046eb43     ADD        ESP,0x4
//                               LAB_0046eb46                                                 XREF[1]:     0046eb34(j)
//                              player.cpp:283 (23)
//         0046eb46     MOV        EDI,dword ptr [ESI + 0x2c]
//         0046eb49     CMP        EDI,EBX
//         0046eb4b     JZ         LAB_0046eb5d
//         0046eb4d     MOV        this,EDI
//         0046eb4f     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
//         0046eb54     PUSH       EDI
//         0046eb55     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046eb5a     ADD        ESP,0x4
//                               LAB_0046eb5d                                                 XREF[1]:     0046eb4b(j)
//                              player.cpp:284 (23)
//         0046eb5d     MOV        EDI,dword ptr [ESI + 0x30]
//         0046eb60     CMP        EDI,EBX
//         0046eb62     JZ         LAB_0046eb74
//         0046eb64     MOV        this,EDI
//         0046eb66     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
//         0046eb6b     PUSH       EDI
//         0046eb6c     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046eb71     ADD        ESP,0x4
//                               LAB_0046eb74                                                 XREF[1]:     0046eb62(j)
//                              player.cpp:285 (23)
//         0046eb74     MOV        EDI,dword ptr [ESI + 0x34]
//         0046eb77     CMP        EDI,EBX
//         0046eb79     JZ         LAB_0046eb8b
//         0046eb7b     MOV        this,EDI
//         0046eb7d     CALL       RGE_Victory_Conditions::~RGE_Victory_Conditions  void ~RGE_Victory_Conditions(RGE_Victory_Cond
//         0046eb82     PUSH       EDI
//         0046eb83     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046eb88     ADD        ESP,0x4
//                               LAB_0046eb8b                                                 XREF[1]:     0046eb79(j)
//                              player.cpp:287 (12)
//         0046eb8b     MOV        EAX,dword ptr [ESI + 0x84]
//         0046eb91     PUSH       EAX
//         0046eb92     CALL       free                                             undefined free()
//                              player.cpp:290 (18)
//         0046eb97     MOV        AX,word ptr [ESI + 0x22]
//         0046eb9b     ADD        ESP,0x4
//         0046eb9e     CMP        AX,BX
//         0046eba1     MOV        dword ptr [ESI + 0x84],EBX
//         0046eba7     JLE        LAB_0046ebdd
//                              player.cpp:292 (7)
//         0046eba9     XOR        EDI,EDI
//         0046ebab     CMP        AX,BX
//         0046ebae     JLE        LAB_0046ebca
//                               LAB_0046ebb0                                                 XREF[1]:     0046ebc8(j)
//                              player.cpp:293 (13)
//         0046ebb0     MOV        EDX,dword ptr [ESI + 0x24]
//         0046ebb3     MOVSX      this,DI
//         0046ebb6     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         0046ebb9     CMP        this,EBX
//         0046ebbb     JZ         LAB_0046ebc3
//                              player.cpp:294 (13)
//         0046ebbd     MOV        EAX,dword ptr [this->_padding_]
//         0046ebbf     PUSH       0x1
//         0046ebc1     CALL       dword ptr [EAX]
//                               LAB_0046ebc3                                                 XREF[1]:     0046ebbb(j)
//         0046ebc3     INC        EDI
//         0046ebc4     CMP        DI,word ptr [ESI + 0x22]
//         0046ebc8     JL         LAB_0046ebb0
//                               LAB_0046ebca                                                 XREF[1]:     0046ebae(j)
//                              player.cpp:296 (12)
//         0046ebca     MOV        this,dword ptr [ESI + 0x24]
//         0046ebcd     PUSH       this
//         0046ebce     CALL       free                                             undefined free()
//         0046ebd3     ADD        ESP,0x4
//                              player.cpp:297 (3)
//         0046ebd6     MOV        dword ptr [ESI + 0x24],EBX
//                              player.cpp:298 (4)
//         0046ebd9     MOV        word ptr [ESI + 0x22],BX
//                               LAB_0046ebdd                                                 XREF[1]:     0046eba7(j)
//                              player.cpp:300 (23)
//         0046ebdd     MOV        EDI,dword ptr [ESI + 0x38]
//         0046ebe0     CMP        EDI,EBX
//         0046ebe2     JZ         LAB_0046ebf4
//         0046ebe4     MOV        this,EDI
//         0046ebe6     CALL       RGE_Visible_Map::~RGE_Visible_Map                void ~RGE_Visible_Map(RGE_Visible_Map * this)
//         0046ebeb     PUSH       EDI
//         0046ebec     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046ebf1     ADD        ESP,0x4
//                               LAB_0046ebf4                                                 XREF[1]:     0046ebe2(j)
//                              player.cpp:301 (23)
//         0046ebf4     MOV        EDI,dword ptr [ESI + 0x40]
//         0046ebf7     CMP        EDI,EBX
//         0046ebf9     JZ         LAB_0046ec0b
//         0046ebfb     MOV        this,EDI
//         0046ebfd     CALL       RGE_Doppleganger_Creator::~RGE_Doppleganger_Cr   void ~RGE_Doppleganger_Creator(RGE_Dopplegang
//         0046ec02     PUSH       EDI
//         0046ec03     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046ec08     ADD        ESP,0x4
//                               LAB_0046ec0b                                                 XREF[1]:     0046ebf9(j)
//                              player.cpp:302 (26)
//         0046ec0b     MOV        EDI,dword ptr [ESI + 0x110]
//         0046ec11     CMP        EDI,EBX
//         0046ec13     JZ         LAB_0046ec25
//         0046ec15     MOV        this,EDI
//         0046ec17     CALL       Visible_Resource_Manager::~Visible_Resource_Ma   void ~Visible_Resource_Manager(Visible_Resour
//         0046ec1c     PUSH       EDI
//         0046ec1d     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046ec22     ADD        ESP,0x4
//                               LAB_0046ec25                                                 XREF[1]:     0046ec13(j)
//                              player.cpp:304 (7)
//         0046ec25     MOV        EAX,dword ptr [ESI + 0x44]
//         0046ec28     CMP        EAX,EBX
//         0046ec2a     JZ         LAB_0046ec38
//                              player.cpp:306 (9)
//         0046ec2c     PUSH       EAX
//         0046ec2d     CALL       free                                             undefined free()
//         0046ec32     ADD        ESP,0x4
//                              player.cpp:307 (3)
//         0046ec35     MOV        dword ptr [ESI + 0x44],EBX
//                               LAB_0046ec38                                                 XREF[1]:     0046ec2a(j)
//                              player.cpp:310 (6)
//         0046ec38     CMP        word ptr [ESI + 0x4c],BX
//         0046ec3c     JLE        LAB_0046ec4e
//                              player.cpp:313 (12)
//         0046ec3e     MOV        EDX,dword ptr [ESI + 0x50]
//         0046ec41     PUSH       EDX
//         0046ec42     CALL       free                                             undefined free()
//         0046ec47     ADD        ESP,0x4
//                              player.cpp:314 (7)
//         0046ec4a     MOV        word ptr [ESI + 0x4c],BX
//                               LAB_0046ec4e                                                 XREF[1]:     0046ec3c(j)
//         0046ec4e     LEA        this,[ESI + 0x6c]
//                              player.cpp:325 (43)
//         0046ec51     MOV        byte ptr [ESP + 0x18],BL
//         0046ec55     CALL       RGE_Tile_List::~RGE_Tile_List                    void ~RGE_Tile_List(RGE_Tile_List * this)
//         0046ec5a     LEA        this,[ESI + 0x58]
//         0046ec5d     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0046ec65     CALL       RGE_Tile_List::~RGE_Tile_List                    void ~RGE_Tile_List(RGE_Tile_List * this)
//         0046ec6a     MOV        this,dword ptr [ESP + 0x10]
//         0046ec6e     POP        EDI
//         0046ec6f     POP        ESI
//         0046ec70     MOV        dword ptr FS:[0x0],this
//         0046ec77     POP        EBX
//         0046ec78     ADD        ESP,0x10
//         0046ec7b     RET
//         0046ec7c     ??         90h
//         0046ec7d     NOP
//         0046ec7e     NOP
//         0046ec7f     NOP
}

void RGE_Player::set_game_status(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_game_status(RGE_Player * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0046ece2(R)
//                               ?set_game_status@RGE_Player@@UAEXE@Z                         XREF[3]:     00570ed4(*), 00576874(*),
//                               RGE_Player::set_game_status                                               005769a4(*)
//                              player.cpp:331 (2)
//         0046ece0     MOV        EAX,this
//                              player.cpp:332 (12)
//         0046ece2     MOV        this,byte ptr [ESP + param_1]
//         0046ece6     CMP        this,byte ptr [EAX + 0x80]
//         0046ecec     JZ         LAB_0046ed24
//                              player.cpp:338 (15)
//         0046ecee     MOV        DL,byte ptr [EAX + 0x81]
//         0046ecf4     TEST       DL,DL
//         0046ecf6     JZ         LAB_0046ecfd
//         0046ecf8     CMP        this,0x2
//         0046ecfb     JNZ        LAB_0046ed24
//                               LAB_0046ecfd                                                 XREF[1]:     0046ecf6(j)
//                              player.cpp:343 (15)
//         0046ecfd     CMP        this,0x2
//         0046ed00     MOV        byte ptr [EAX + 0x80],this
//         0046ed06     JNZ        LAB_0046ed24
//         0046ed08     TEST       DL,DL
//         0046ed0a     JNZ        LAB_0046ed24
//                              player.cpp:346 (24)
//         0046ed0c     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0046ed10     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046ed16     PUSH       0x0
//         0046ed18     PUSH       0x0
//         0046ed1a     PUSH       0x0
//         0046ed1c     MOV        EDX,dword ptr [this->_padding_]
//         0046ed1e     PUSH       EAX
//         0046ed1f     PUSH       0x6
//         0046ed21     CALL       dword ptr [EDX + 0x40]
//                               LAB_0046ed24                                                 XREF[4]:     0046ecec(j), 0046ecfb(j),
//                                                                                                         0046ed06(j), 0046ed0a(j)
//                              player.cpp:353 (3)
//         0046ed24     RET        0x4
//         0046ed27     ??         90h
//         0046ed28     NOP
//         0046ed29     NOP
//         0046ed2a     NOP
//         0046ed2b     NOP
//         0046ed2c     NOP
//         0046ed2d     NOP
//         0046ed2e     NOP
//         0046ed2f     NOP
    return;
}

void RGE_Player::do_resign(int param_1) {
    /* TODO: Stub */
//                              void __thiscall do_resign(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?do_resign@RGE_Player@@UAEXH@Z                               XREF[3]:     00570ed8(*), 00576878(*),
//                               RGE_Player::do_resign                                                     005769a8(*)
//                              player.cpp:359 (4)
//         0046ed50     PUSH       EBX
//         0046ed51     PUSH       ESI
//         0046ed52     MOV        ESI,this
//                              player.cpp:363 (20)
//         0046ed54     PUSH       0x2
//         0046ed56     MOV        EAX,dword ptr [ESI]
//         0046ed58     MOV        BL,byte ptr [ESI + 0x81]
//         0046ed5e     MOV        byte ptr [ESI + 0x81],0x1
//         0046ed65     CALL       dword ptr [EAX + 0x4]
//                              player.cpp:374 (4)
//         0046ed68     TEST       BL,BL
//         0046ed6a     JNZ        LAB_0046ed87
//                              player.cpp:375 (27)
//         0046ed6c     MOV        EAX,dword ptr [ESP + 0xc]
//         0046ed70     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046ed76     PUSH       0x0
//         0046ed78     PUSH       0x0=>DAT_fffffff8
//         0046ed7a     MOV        EDX,dword ptr [this->_padding_]
//         0046ed7c     PUSH       EAX=>DAT_fffffff4
//         0046ed7d     MOVSX      EAX,word ptr [ESI + 0x4a]
//         0046ed81     PUSH       EAX=>DAT_fffffff0
//         0046ed82     PUSH       0x5
//         0046ed84     CALL       dword ptr [EDX + 0x40]
//                               LAB_0046ed87                                                 XREF[1]:     0046ed6a(j)
//                              player.cpp:382 (5)
//         0046ed87     POP        ESI
//         0046ed88     POP        EBX
//         0046ed89     RET        0x4
//         0046ed8c     ??         90h
//         0046ed8d     NOP
//         0046ed8e     NOP
//         0046ed8f     NOP
    return;
}

uchar RGE_Player::get_resigned() {
    /* TODO: Stub */
//                              uchar __thiscall get_resigned(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?get_resigned@RGE_Player@@QAEEXZ
//                               RGE_Player::get_resigned
//                              player.cpp:388 (6)
//         0046ed90     MOV        AL,byte ptr [ECX + this->resigned]
//                              player.cpp:390 (1)
//         0046ed96     RET
//         0046ed97     ??         90h
//         0046ed98     NOP
//         0046ed99     NOP
//         0046ed9a     NOP
//         0046ed9b     NOP
//         0046ed9c     NOP
//         0046ed9d     NOP
//         0046ed9e     NOP
//         0046ed9f     NOP
    return 0;
}

char* RGE_Player::aiStatus(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall aiStatus(RGE_Player * this, int param_1)
//              char *            EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?aiStatus@RGE_Player@@UAEPADH@Z                              XREF[1]:     00570ee4(*)
//                               RGE_Player::aiStatus
//                              player.cpp:395 (2)
//         0046eda0     XOR        EAX,EAX
//                              player.cpp:397 (3)
//         0046eda2     RET        0x4
//         0046eda5     ??         90h
//         0046eda6     NOP
//         0046eda7     NOP
//         0046eda8     NOP
//         0046eda9     NOP
//         0046edaa     NOP
//         0046edab     NOP
//         0046edac     NOP
//         0046edad     NOP
//         0046edae     NOP
//         0046edaf     NOP
    return 0;
}

int RGE_Player::computerPlayer() {
    /* TODO: Stub */
//                              int __thiscall computerPlayer(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?computerPlayer@RGE_Player@@QBEHXZ                           XREF[84]:    RGE_Action_Enter:004024a4(c),
//                               RGE_Player::computerPlayer                                                RGE_Action_Enter:004024b3(c),
//                                                                                                         update:00413ca7(c),
//                                                                                                         update:00413fcc(c),
//                                                                                                         update:00430795(c),
//                                                                                                         findTilePath:0046bed3(c),
//                                                                                                         removeAllFromPathingGroup:004c7e56
//                                                                                                         first_in_stack:004cdca4(c),
//                                                                                                         first_in_stack:004cdd09(c),
//                                                                                                         first_in_stack:004cdd4e(c),
//                                                                                                         addObjectMemory:004da71d(c),
//                                                                                                         addImportantObject:004dac6f(c),
//                                                                                                         checkForCoopAttack:00502dce(c),
//                                                                                                         checkForCoopAttack:00502e2b(c),
//                                                                                                         processNotify:0050721a(c),
//                                                                                                         processNotify:005073a7(c),
//                                                                                                         show_ai:00524b18(c),
//                                                                                                         show_ai:00524cf1(c),
//                                                                                                         create_game:00527776(c),
//                                                                                                         fill_in_score:00531262(c), [more]
//                              player.cpp:402 (3)
//         0046edb0     MOV        EAX,dword ptr [ECX + this->computerPlayerValue]
//                              player.cpp:404 (1)
//         0046edb3     RET
//         0046edb4     ??         90h
//         0046edb5     NOP
//         0046edb6     NOP
//         0046edb7     NOP
//         0046edb8     NOP
//         0046edb9     NOP
//         0046edba     NOP
//         0046edbb     NOP
//         0046edbc     NOP
//         0046edbd     NOP
//         0046edbe     NOP
//         0046edbf     NOP
    return 0;
}

int RGE_Player::isEnemy(int param_1) {
    /* TODO: Stub */
//                              int __thiscall isEnemy(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046edc4(R)
//                               ?isEnemy@RGE_Player@@UAEHH@Z                                 XREF[3]:     00570ee8(*), 00576888(*),
//                               RGE_Player::isEnemy                                                       005769b8(*)
//                              player.cpp:410 (10)
//         0046edc0     MOVSX      EDX,word ptr [ECX + this->id]
//         0046edc4     MOV        EAX,dword ptr [ESP + param_1]
//         0046edc8     CMP        EAX,EDX
//                              player.cpp:416 (2)
//         0046edca     JZ         LAB_0046edef
//                              player.cpp:419 (15)
//         0046edcc     TEST       EAX,EAX
//         0046edce     JLE        LAB_0046edef
//         0046edd0     MOV        EDX,dword ptr [ECX + this->world]
//         0046edd3     MOVSX      EDX,word ptr [EDX + 0x3c]
//         0046edd7     CMP        EAX,EDX
//         0046edd9     JGE        LAB_0046edef
//                              player.cpp:421 (12)
//         0046eddb     MOV        this,dword ptr [ECX + this->relations]
//         0046ede1     CMP        byte ptr [this->_padding_ + EAX*0x1],0x3
//         0046ede5     JNZ        LAB_0046edef
//                              player.cpp:422 (5)
//         0046ede7     MOV        EAX,0x1
//                              player.cpp:425 (3)
//         0046edec     RET        0x4
//                               LAB_0046edef                                                 XREF[4]:     0046edca(j), 0046edce(j),
//                                                                                                         0046edd9(j), 0046ede5(j)
//                              player.cpp:424 (2)
//         0046edef     XOR        EAX,EAX
//                              player.cpp:425 (3)
//         0046edf1     RET        0x4
//         0046edf4     ??         90h
//         0046edf5     NOP
//         0046edf6     NOP
//         0046edf7     NOP
//         0046edf8     NOP
//         0046edf9     NOP
//         0046edfa     NOP
//         0046edfb     NOP
//         0046edfc     NOP
//         0046edfd     NOP
//         0046edfe     NOP
//         0046edff     NOP
    return 0;
}

int RGE_Player::isAlly(int param_1) {
    /* TODO: Stub */
//                              int __thiscall isAlly(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ee04(R)
//                               ?isAlly@RGE_Player@@UAEHH@Z                                  XREF[3]:     00570eec(*), 0057688c(*),
//                               RGE_Player::isAlly                                                        005769bc(*)
//                              player.cpp:431 (12)
//         0046ee00     MOVSX      EDX,word ptr [ECX + this->id]
//         0046ee04     MOV        EAX,dword ptr [ESP + param_1]
//         0046ee08     CMP        EAX,EDX
//         0046ee0a     JNZ        LAB_0046ee14
//                              player.cpp:437 (5)
//         0046ee0c     MOV        EAX,0x1
//                              player.cpp:446 (3)
//         0046ee11     RET        0x4
//                               LAB_0046ee14                                                 XREF[1]:     0046ee0a(j)
//                              player.cpp:440 (15)
//         0046ee14     TEST       EAX,EAX
//         0046ee16     JLE        LAB_0046ee37
//         0046ee18     MOV        EDX,dword ptr [ECX + this->world]
//         0046ee1b     MOVSX      EDX,word ptr [EDX + 0x3c]
//         0046ee1f     CMP        EAX,EDX
//         0046ee21     JGE        LAB_0046ee37
//                              player.cpp:442 (12)
//         0046ee23     MOV        this,dword ptr [ECX + this->relations]
//         0046ee29     CMP        byte ptr [this->_padding_ + EAX*0x1],0x0
//         0046ee2d     JNZ        LAB_0046ee37
//                              player.cpp:443 (5)
//         0046ee2f     MOV        EAX,0x1
//                              player.cpp:446 (3)
//         0046ee34     RET        0x4
//                               LAB_0046ee37                                                 XREF[3]:     0046ee16(j), 0046ee21(j),
//                                                                                                         0046ee2d(j)
//                              player.cpp:445 (2)
//         0046ee37     XOR        EAX,EAX
//                              player.cpp:446 (3)
//         0046ee39     RET        0x4
//         0046ee3c     ??         90h
//         0046ee3d     NOP
//         0046ee3e     NOP
//         0046ee3f     NOP
    return 0;
}

int RGE_Player::isNeutral(int param_1) {
    /* TODO: Stub */
//                              int __thiscall isNeutral(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ee44(R)
//                               ?isNeutral@RGE_Player@@UAEHH@Z                               XREF[3]:     00570ef0(*), 00576890(*),
//                               RGE_Player::isNeutral                                                     005769c0(*)
//                              player.cpp:452 (10)
//         0046ee40     MOVSX      EDX,word ptr [ECX + this->id]
//         0046ee44     MOV        EAX,dword ptr [ESP + param_1]
//         0046ee48     CMP        EAX,EDX
//                              player.cpp:458 (2)
//         0046ee4a     JZ         LAB_0046ee6f
//                              player.cpp:461 (15)
//         0046ee4c     TEST       EAX,EAX
//         0046ee4e     JLE        LAB_0046ee6f
//         0046ee50     MOV        EDX,dword ptr [ECX + this->world]
//         0046ee53     MOVSX      EDX,word ptr [EDX + 0x3c]
//         0046ee57     CMP        EAX,EDX
//         0046ee59     JGE        LAB_0046ee6f
//                              player.cpp:462 (12)
//         0046ee5b     MOV        this,dword ptr [ECX + this->relations]
//         0046ee61     CMP        byte ptr [this->_padding_ + EAX*0x1],0x1
//         0046ee65     JNZ        LAB_0046ee6f
//                              player.cpp:463 (5)
//         0046ee67     MOV        EAX,0x1
//                              player.cpp:467 (3)
//         0046ee6c     RET        0x4
//                               LAB_0046ee6f                                                 XREF[4]:     0046ee4a(j), 0046ee4e(j),
//                                                                                                         0046ee59(j), 0046ee65(j)
//                              player.cpp:466 (2)
//         0046ee6f     XOR        EAX,EAX
//                              player.cpp:467 (3)
//         0046ee71     RET        0x4
//         0046ee74     ??         90h
//         0046ee75     NOP
//         0046ee76     NOP
//         0046ee77     NOP
//         0046ee78     NOP
//         0046ee79     NOP
//         0046ee7a     NOP
//         0046ee7b     NOP
//         0046ee7c     NOP
//         0046ee7d     NOP
//         0046ee7e     NOP
//         0046ee7f     NOP
    return 0;
}

int RGE_Player::isAllNeutral() {
    /* TODO: Stub */
//                              int __thiscall isAllNeutral(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?isAllNeutral@RGE_Player@@UAEHXZ                             XREF[3]:     00570ef4(*), 00576894(*),
//                               RGE_Player::isAllNeutral                                                  005769c4(*)
//                              player.cpp:472 (4)
//         0046ee80     PUSH       ESI
//         0046ee81     MOV        ESI,this
//         0046ee83     PUSH       EDI
//                              player.cpp:473 (14)
//         0046ee84     MOV        EDI,0x1
//         0046ee89     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046ee8c     CMP        word ptr [EAX + 0x3c],DI
//         0046ee90     JLE        LAB_0046eebf
//                               LAB_0046ee92                                                 XREF[1]:     0046eeb0(j)
//                              player.cpp:474 (8)
//         0046ee92     MOVSX      this,word ptr [ESI + 0x4a]
//         0046ee96     CMP        EDI,this
//         0046ee98     JZ         LAB_0046eea6
//                              player.cpp:476 (12)
//         0046ee9a     MOV        EDX,dword ptr [ESI]
//         0046ee9c     PUSH       EDI
//         0046ee9d     MOV        this,ESI
//         0046ee9f     CALL       dword ptr [EDX + 0x20]
//         0046eea2     TEST       EAX,EAX
//         0046eea4     JZ         LAB_0046eeba
//                               LAB_0046eea6                                                 XREF[1]:     0046ee98(j)
//                              player.cpp:473 (12)
//         0046eea6     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046eea9     INC        EDI
//         0046eeaa     MOVSX      this,word ptr [EAX + 0x3c]
//         0046eeae     CMP        EDI,this
//         0046eeb0     JL         LAB_0046ee92
//                              player.cpp:479 (5)
//         0046eeb2     MOV        EAX,0x1
//                              player.cpp:480 (3)
//         0046eeb7     POP        EDI
//         0046eeb8     POP        ESI
//         0046eeb9     RET
//                               LAB_0046eeba                                                 XREF[1]:     0046eea4(j)
//                              player.cpp:477 (2)
//         0046eeba     XOR        EAX,EAX
//                              player.cpp:480 (11)
//         0046eebc     POP        EDI
//         0046eebd     POP        ESI
//         0046eebe     RET
//                               LAB_0046eebf                                                 XREF[1]:     0046ee90(j)
//         0046eebf     POP        EDI
//         0046eec0     MOV        EAX,0x1
//         0046eec5     POP        ESI
//         0046eec6     RET
//         0046eec7     ??         90h
//         0046eec8     NOP
//         0046eec9     NOP
//         0046eeca     NOP
//         0046eecb     NOP
//         0046eecc     NOP
//         0046eecd     NOP
//         0046eece     NOP
//         0046eecf     NOP
    return 0;
}

void RGE_Player::setDiplomaticStance(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setDiplomaticStance(RGE_Player * this, int param_1,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?setDiplomaticStance@RGE_Player@@UAEXHH@Z                    XREF[1]:     00570ef8(*)
//                               RGE_Player::setDiplomaticStance
//                              player.cpp:486 (3)
//         0046eed0     RET        0x8
//         0046eed3     ??         90h
//         0046eed4     NOP
//         0046eed5     NOP
//         0046eed6     NOP
//         0046eed7     NOP
//         0046eed8     NOP
//         0046eed9     NOP
//         0046eeda     NOP
//         0046eedb     NOP
//         0046eedc     NOP
//         0046eedd     NOP
//         0046eede     NOP
//         0046eedf     NOP
    return;
}

void RGE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              void __thiscall loadAIInformation(RGE_Player * this, char * param_1,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//              char *            Stack[0x8]:4   param_2
//              char *            Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?loadAIInformation@RGE_Player@@UAEXPAD00HH@Z                 XREF[1]:     00570efc(*)
//                               RGE_Player::loadAIInformation
//                              player.cpp:494 (3)
//         0046eee0     RET        0x14
//         0046eee3     ??         90h
//         0046eee4     NOP
//         0046eee5     NOP
//         0046eee6     NOP
//         0046eee7     NOP
//         0046eee8     NOP
//         0046eee9     NOP
//         0046eeea     NOP
//         0046eeeb     NOP
//         0046eeec     NOP
//         0046eeed     NOP
//         0046eeee     NOP
//         0046eeef     NOP
    return;
}

void RGE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {
    /* TODO: Stub */
//                              void __thiscall sendUnitAIOrder(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ef2d(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0046ef27(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0046ef1f(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0046ef1a(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0046ef12(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     0046ef0d(R)
//              float             Stack[0x1c]:4  param_7                   XREF[1]:     0046ef08(R)
//              float             Stack[0x20]:4  param_8                   XREF[1]:     0046ef03(R)
//              float             Stack[0x24]:4  param_9                   XREF[1]:     0046eefe(R)
//              int               Stack[0x28]:4  param_10                  XREF[1]:     0046eef9(R)
//              int               Stack[0x2c]:4  param_11                  XREF[1]:     0046eef4(R)
//              int               Stack[0x30]:4  param_12                  XREF[1]:     0046eef0(R)
//                               ?sendUnitAIOrder@RGE_Player@@UAEXHHHHHMMMMHHH@Z              XREF[3]:     00570f00(*), 005768a0(*),
//                               RGE_Player::sendUnitAIOrder                                               005769d0(*)
//                              player.cpp:503 (72)
//         0046eef0     MOV        EAX,dword ptr [ESP + param_12]
//         0046eef4     MOV        EDX,dword ptr [ESP + param_11]
//         0046eef8     PUSH       EAX
//         0046eef9     MOV        EAX,dword ptr [ESP + param_10]
//         0046eefd     PUSH       EDX
//         0046eefe     MOV        EDX,dword ptr [ESP + param_9]
//         0046ef02     PUSH       EAX
//         0046ef03     MOV        EAX,dword ptr [ESP + param_8]
//         0046ef07     PUSH       EDX
//         0046ef08     MOV        EDX,dword ptr [ESP + param_7]
//         0046ef0c     PUSH       EAX
//         0046ef0d     MOV        EAX,dword ptr [ESP + param_6]
//         0046ef11     PUSH       EDX
//         0046ef12     MOV        EDX,dword ptr [ESP + param_5]
//         0046ef16     MOV        this,dword ptr [ECX + this->world]
//         0046ef19     PUSH       EAX
//         0046ef1a     MOV        EAX,dword ptr [ESP + param_4]
//         0046ef1e     PUSH       EDX
//         0046ef1f     MOV        EDX,dword ptr [ESP + param_3]
//         0046ef23     MOV        this,dword ptr [ECX + this->tile_list.list_size]
//         0046ef26     PUSH       EAX
//         0046ef27     MOV        EAX,dword ptr [ESP + param_2]
//         0046ef2b     PUSH       EDX
//         0046ef2c     PUSH       EAX
//         0046ef2d     MOV        EAX,dword ptr [ESP + param_1]
//         0046ef31     PUSH       EAX
//         0046ef32     PUSH       EAX
//         0046ef33     CALL       RGE_Command::command_ai_order                    void command_ai_order(RGE_Command * this, int
//                              player.cpp:507 (3)
//         0046ef38     RET        0x30
//         0046ef3b     ??         90h
//         0046ef3c     NOP
//         0046ef3d     NOP
//         0046ef3e     NOP
//         0046ef3f     NOP
    return;
}

void RGE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {
    /* TODO: Stub */
//                              void __thiscall processAIOrder(RGE_Player * this, int param_1, int p
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ef9a(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0046ef40(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0046ef95(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0046ef90(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0046ef8b(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     0046ef86(R)
//              float             Stack[0x1c]:4  param_7                   XREF[1]:     0046ef81(R)
//              float             Stack[0x20]:4  param_8                   XREF[1]:     0046ef7c(R)
//              float             Stack[0x24]:4  param_9                   XREF[1]:     0046ef77(R)
//              int               Stack[0x28]:4  param_10                  XREF[1]:     0046ef72(R)
//              int               Stack[0x2c]:4  param_11                  XREF[1]:     0046ef6d(R)
//              int               Stack[0x30]:4  param_12                  XREF[1]:     0046ef66(R)
//                               ?processAIOrder@RGE_Player@@UAEXHHHHHMMMMHHH@Z               XREF[3]:     00570f04(*), 005768a4(*),
//                               RGE_Player::processAIOrder                                                005769d4(*)
//                              player.cpp:515 (16)
//         0046ef40     MOV        EAX,dword ptr [ESP + param_2]
//         0046ef44     MOV        this,dword ptr [ECX + this->world]
//         0046ef47     PUSH       ESI
//         0046ef48     PUSH       EAX
//         0046ef49     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0046ef4e     MOV        ESI,EAX
//                              player.cpp:517 (15)
//         0046ef50     TEST       ESI,ESI
//         0046ef52     JZ         LAB_0046efa4
//         0046ef54     MOV        this,ESI
//         0046ef56     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         0046ef5b     TEST       EAX,EAX
//         0046ef5d     JZ         LAB_0046efa4
//                              player.cpp:520 (69)
//         0046ef5f     MOV        this,ESI
//         0046ef61     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
//         0046ef66     MOV        this,dword ptr [ESP + param_12]
//         0046ef6a     MOV        EDX,dword ptr [EAX]
//         0046ef6c     PUSH       this
//         0046ef6d     MOV        this,dword ptr [ESP + param_11]
//         0046ef71     PUSH       this
//         0046ef72     MOV        this,dword ptr [ESP + param_10]
//         0046ef76     PUSH       this
//         0046ef77     MOV        this,dword ptr [ESP + param_9]
//         0046ef7b     PUSH       this
//         0046ef7c     MOV        this,dword ptr [ESP + param_8]
//         0046ef80     PUSH       this
//         0046ef81     MOV        this,dword ptr [ESP + param_7]
//         0046ef85     PUSH       this
//         0046ef86     MOV        this,dword ptr [ESP + param_6]
//         0046ef8a     PUSH       this
//         0046ef8b     MOV        this,dword ptr [ESP + param_5]
//         0046ef8f     PUSH       this
//         0046ef90     MOV        this,dword ptr [ESP + param_4]
//         0046ef94     PUSH       this
//         0046ef95     MOV        this,dword ptr [ESP + param_3]
//         0046ef99     PUSH       this
//         0046ef9a     MOV        this,dword ptr [ESP + param_1]
//         0046ef9e     PUSH       this
//         0046ef9f     MOV        this,EAX
//         0046efa1     CALL       dword ptr [EDX + 0x10]
//                               LAB_0046efa4                                                 XREF[2]:     0046ef52(j), 0046ef5d(j)
//                              player.cpp:522 (4)
//         0046efa4     POP        ESI
//         0046efa5     RET        0x30
//         0046efa8     ??         90h
//         0046efa9     NOP
//         0046efaa     NOP
//         0046efab     NOP
//         0046efac     NOP
//         0046efad     NOP
//         0046efae     NOP
//         0046efaf     NOP
    return;
}

void RGE_Player::sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall sendGameOrder(RGE_Player * this, RGE_Static_Object *
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     0046efb0(R), 0046efbb(W), 0046efcd(*)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0046efc4(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0046efbf(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0046efb4(R)
//                               ?sendGameOrder@RGE_Player@@UAEXPAVRGE_Static_Object@@0MM@Z   XREF[3]:     00570f10(*), 005768b0(*),
//                               RGE_Player::sendGameOrder                                                 005769e0(*)
//                              player.cpp:528 (4)
//         0046efb0     MOV        EAX,dword ptr [ESP + param_1]
//                              player.cpp:532 (37)
//         0046efb4     MOV        EDX,dword ptr [ESP + param_4]
//         0046efb8     MOV        this,dword ptr [ECX + this->world]
//         0046efbb     MOV        dword ptr [ESP + param_1],EAX
//         0046efbf     MOV        EAX,dword ptr [ESP + param_3]
//         0046efc3     PUSH       EDX
//         0046efc4     MOV        EDX,dword ptr [ESP + param_2]
//         0046efc8     MOV        this,dword ptr [ECX + this->tile_list.list_size]
//         0046efcb     PUSH       EAX
//         0046efcc     PUSH       EDX
//         0046efcd     LEA        EAX=>param_1,[ESP + 0x10]
//         0046efd1     PUSH       0x1
//         0046efd3     PUSH       EAX
//         0046efd4     CALL       RGE_Command::command_order                       void command_order(RGE_Command * this, RGE_St
//                              player.cpp:533 (3)
//         0046efd9     RET        0x10
//         0046efdc     ??         90h
//         0046efdd     NOP
//         0046efde     NOP
//         0046efdf     NOP
    return;
}

void RGE_Player::sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall sendAddWaypointCommand(RGE_Player * this, int param_
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046efe9(R)
//              XYZBYTEPoint *    Stack[0x8]:4   param_2                   XREF[1]:     0046efe4(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0046efe0(R)
//                               ?sendAddWaypointCommand@RGE_Player@@UAEXHPAUXYZBYTEPoint@@H@Z XREF[3]:     00570f14(*), 005768b4(*),
//                               RGE_Player::sendAddWaypointCommand                                        005769e4(*)
//                              player.cpp:540 (31)
//         0046efe0     MOV        EAX,dword ptr [ESP + param_3]
//         0046efe4     MOV        EDX,dword ptr [ESP + param_2]
//         0046efe8     PUSH       EAX
//         0046efe9     MOV        EAX,dword ptr [ESP + param_1]
//         0046efed     PUSH       EDX
//         0046efee     PUSH       EAX
//         0046efef     MOVSX      EDX,word ptr [ECX + this->id]
//         0046eff3     MOV        EAX,dword ptr [ECX + this->world]
//         0046eff6     PUSH       EDX
//         0046eff7     MOV        this,dword ptr [EAX + 0x58]
//         0046effa     CALL       RGE_Command::command_add_waypoint                void command_add_waypoint(RGE_Command * this,
//                              player.cpp:543 (3)
//         0046efff     RET        0xc
//         0046f002     ??         90h
//         0046f003     NOP
//         0046f004     NOP
//         0046f005     NOP
//         0046f006     NOP
//         0046f007     NOP
//         0046f008     NOP
//         0046f009     NOP
//         0046f00a     NOP
//         0046f00b     NOP
//         0046f00c     NOP
//         0046f00d     NOP
//         0046f00e     NOP
//         0046f00f     NOP
    return;
}

void RGE_Player::processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall processAddWaypointCommand(RGE_Player * this, int par
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f010(R)
//              XYZBYTEPoint *    Stack[0x8]:4   param_2                   XREF[1]:     0046f030(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0046f025(R)
//                               ?processAddWaypointCommand@RGE_Player@@UAEXHPAUXYZBYTEPoint  XREF[3]:     00570f18(*), 005768b8(*),
//                               RGE_Player::processAddWaypointCommand                                     005769e8(*)
//                              player.cpp:550 (17)
//         0046f010     MOV        EAX,dword ptr [ESP + param_1]
//         0046f014     MOV        this,dword ptr [ECX + this->world]
//         0046f017     PUSH       EBX
//         0046f018     PUSH       EDI
//         0046f019     PUSH       EAX
//         0046f01a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0046f01f     MOV        EDI,EAX
//                              player.cpp:552 (4)
//         0046f021     TEST       EDI,EDI
//         0046f023     JZ         LAB_0046f04a
//                              player.cpp:553 (8)
//         0046f025     MOV        EBX,dword ptr [ESP + param_3]
//         0046f029     TEST       EBX,EBX
//         0046f02b     JLE        LAB_0046f04a
//                              player.cpp:554 (3)
//         0046f02d     MOV        this,dword ptr [EDI]
//         0046f02f     PUSH       ESI
//                              player.cpp:556 (31)
//         0046f030     MOV        ESI,dword ptr [ESP + param_2]
//         0046f034     PUSH       EBP
//         0046f035     MOV        EBP,dword ptr [ECX + this+0x1bc]
//                               LAB_0046f03b                                                 XREF[1]:     0046f046(j)
//         0046f03b     PUSH       0x1
//         0046f03d     PUSH       ESI=>DAT_fffffff8
//         0046f03e     MOV        this,EDI
//         0046f040     CALL       EBP
//         0046f042     ADD        ESI,0x3
//         0046f045     DEC        EBX
//         0046f046     JNZ        LAB_0046f03b
//         0046f048     POP        EBP
//         0046f049     POP        ESI
//                               LAB_0046f04a                                                 XREF[2]:     0046f023(j), 0046f02b(j)
//         0046f04a     POP        EDI
//         0046f04b     POP        EBX
//         0046f04c     RET        0xc
//         0046f04f     ??         90h
    return;
}

void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall sendPlayCommand(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f141(R)
//              int *             Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?sendPlayCommand@RGE_Player@@UAEXHPAHHHH@Z                   XREF[3]:     00570f1c(*), 005768bc(*),
//                               RGE_Player::sendPlayCommand                                               005769ec(*)
//                              player.cpp:610 (1)
//         0046f140     PUSH       EBX
//                              player.cpp:615 (18)
//         0046f141     MOV        EBX,dword ptr [ESP + param_1]
//         0046f145     PUSH       EBP
//         0046f146     PUSH       ESI
//         0046f147     MOV        ESI,this
//         0046f149     PUSH       EDI
//         0046f14a     PUSH       EBX
//         0046f14b     MOV        EDI,dword ptr [ESI]
//         0046f14d     CALL       dword ptr [EDI + 0xd0]
//                              player.cpp:619 (23)
//         0046f153     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046f156     MOV        EBP,dword ptr [ESP + 0x24]
//         0046f15a     PUSH       EBP
//         0046f15b     MOV        this,dword ptr [EAX + 0xa0]
//         0046f161     CALL       AIPlayBook::play                                 AIPlay * play(AIPlayBook * this, int param_1)
//         0046f166     TEST       EAX,EAX
//         0046f168     JNZ        LAB_0046f19e
//                              player.cpp:641 (45)
//         0046f16a     MOVSX      this,word ptr [ESI + 0x4a]
//         0046f16e     PUSH       0x64
//         0046f170     PUSH       EAX=>DAT_fffffff8
//         0046f171     PUSH       offset DAT_fffffff4
//         0046f173     PUSH       offset DAT_fffffff0
//         0046f178     PUSH       0xbf800000
//         0046f17d     PUSH       0xbf800000
//         0046f182     PUSH       0xbf800000
//         0046f187     PUSH       -0x1
//         0046f189     PUSH       -0x1
//         0046f18b     PUSH       0x2d7
//         0046f190     PUSH       EBX
//         0046f191     PUSH       this
//         0046f192     MOV        this,ESI
//         0046f194     CALL       dword ptr [EDI + 0x30]
//                              player.cpp:642 (7)
//         0046f197     POP        EDI
//         0046f198     POP        ESI
//         0046f199     POP        EBP
//         0046f19a     POP        EBX
//         0046f19b     RET        0x14
//                               LAB_0046f19e                                                 XREF[1]:     0046f168(j)
//                              player.cpp:628 (8)
//         0046f19e     MOV        EAX,dword ptr [ESP + 0x1c]
//         0046f1a2     TEST       EAX,EAX
//         0046f1a4     JZ         LAB_0046f1ea
//                              player.cpp:630 (20)
//         0046f1a6     MOV        EDX,dword ptr [ESP + 0x18]
//         0046f1aa     PUSH       0x40000000
//         0046f1af     PUSH       EAX=>DAT_fffffff8
//         0046f1b0     PUSH       EDX=>DAT_fffffff4
//         0046f1b1     PUSH       EBX=>DAT_fffffff0
//         0046f1b2     MOV        this,ESI
//         0046f1b4     CALL       dword ptr [EDI + 0xc4]
//                              player.cpp:641 (48)
//         0046f1ba     MOV        EAX,dword ptr [ESP + 0x20]
//         0046f1be     PUSH       0x64
//         0046f1c0     MOVSX      this,word ptr [ESI + 0x4a]
//         0046f1c4     PUSH       0x0=>DAT_fffffff8
//         0046f1c6     PUSH       offset DAT_fffffff4
//         0046f1c8     PUSH       offset DAT_fffffff0
//         0046f1cd     PUSH       0xbf800000
//         0046f1d2     PUSH       0xbf800000
//         0046f1d7     PUSH       0xbf800000
//         0046f1dc     PUSH       EBP
//         0046f1dd     PUSH       EAX
//         0046f1de     PUSH       0x2d6
//         0046f1e3     PUSH       EBX
//         0046f1e4     PUSH       this
//         0046f1e5     MOV        this,ESI
//         0046f1e7     CALL       dword ptr [EDI + 0x30]
//                               LAB_0046f1ea                                                 XREF[1]:     0046f1a4(j)
//                              player.cpp:642 (7)
//         0046f1ea     POP        EDI
//         0046f1eb     POP        ESI
//         0046f1ec     POP        EBP
//         0046f1ed     POP        EBX
//         0046f1ee     RET        0x14
//         0046f1f1     ??         90h
//         0046f1f2     NOP
//         0046f1f3     NOP
//         0046f1f4     NOP
//         0046f1f5     NOP
//         0046f1f6     NOP
//         0046f1f7     NOP
//         0046f1f8     NOP
//         0046f1f9     NOP
//         0046f1fa     NOP
//         0046f1fb     NOP
//         0046f1fc     NOP
//         0046f1fd     NOP
//         0046f1fe     NOP
//         0046f1ff     NOP
    return;
}

void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              void __thiscall sendPlayCommand(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f141(R)
//              int *             Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?sendPlayCommand@RGE_Player@@UAEXHPAHHHH@Z                   XREF[3]:     00570f1c(*), 005768bc(*),
//                               RGE_Player::sendPlayCommand                                               005769ec(*)
//                              player.cpp:610 (1)
//         0046f140     PUSH       EBX
//                              player.cpp:615 (18)
//         0046f141     MOV        EBX,dword ptr [ESP + param_1]
//         0046f145     PUSH       EBP
//         0046f146     PUSH       ESI
//         0046f147     MOV        ESI,this
//         0046f149     PUSH       EDI
//         0046f14a     PUSH       EBX
//         0046f14b     MOV        EDI,dword ptr [ESI]
//         0046f14d     CALL       dword ptr [EDI + 0xd0]
//                              player.cpp:619 (23)
//         0046f153     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046f156     MOV        EBP,dword ptr [ESP + 0x24]
//         0046f15a     PUSH       EBP
//         0046f15b     MOV        this,dword ptr [EAX + 0xa0]
//         0046f161     CALL       AIPlayBook::play                                 AIPlay * play(AIPlayBook * this, int param_1)
//         0046f166     TEST       EAX,EAX
//         0046f168     JNZ        LAB_0046f19e
//                              player.cpp:641 (45)
//         0046f16a     MOVSX      this,word ptr [ESI + 0x4a]
//         0046f16e     PUSH       0x64
//         0046f170     PUSH       EAX=>DAT_fffffff8
//         0046f171     PUSH       offset DAT_fffffff4
//         0046f173     PUSH       offset DAT_fffffff0
//         0046f178     PUSH       0xbf800000
//         0046f17d     PUSH       0xbf800000
//         0046f182     PUSH       0xbf800000
//         0046f187     PUSH       -0x1
//         0046f189     PUSH       -0x1
//         0046f18b     PUSH       0x2d7
//         0046f190     PUSH       EBX
//         0046f191     PUSH       this
//         0046f192     MOV        this,ESI
//         0046f194     CALL       dword ptr [EDI + 0x30]
//                              player.cpp:642 (7)
//         0046f197     POP        EDI
//         0046f198     POP        ESI
//         0046f199     POP        EBP
//         0046f19a     POP        EBX
//         0046f19b     RET        0x14
//                               LAB_0046f19e                                                 XREF[1]:     0046f168(j)
//                              player.cpp:628 (8)
//         0046f19e     MOV        EAX,dword ptr [ESP + 0x1c]
//         0046f1a2     TEST       EAX,EAX
//         0046f1a4     JZ         LAB_0046f1ea
//                              player.cpp:630 (20)
//         0046f1a6     MOV        EDX,dword ptr [ESP + 0x18]
//         0046f1aa     PUSH       0x40000000
//         0046f1af     PUSH       EAX=>DAT_fffffff8
//         0046f1b0     PUSH       EDX=>DAT_fffffff4
//         0046f1b1     PUSH       EBX=>DAT_fffffff0
//         0046f1b2     MOV        this,ESI
//         0046f1b4     CALL       dword ptr [EDI + 0xc4]
//                              player.cpp:641 (48)
//         0046f1ba     MOV        EAX,dword ptr [ESP + 0x20]
//         0046f1be     PUSH       0x64
//         0046f1c0     MOVSX      this,word ptr [ESI + 0x4a]
//         0046f1c4     PUSH       0x0=>DAT_fffffff8
//         0046f1c6     PUSH       offset DAT_fffffff4
//         0046f1c8     PUSH       offset DAT_fffffff0
//         0046f1cd     PUSH       0xbf800000
//         0046f1d2     PUSH       0xbf800000
//         0046f1d7     PUSH       0xbf800000
//         0046f1dc     PUSH       EBP
//         0046f1dd     PUSH       EAX
//         0046f1de     PUSH       0x2d6
//         0046f1e3     PUSH       EBX
//         0046f1e4     PUSH       this
//         0046f1e5     MOV        this,ESI
//         0046f1e7     CALL       dword ptr [EDI + 0x30]
//                               LAB_0046f1ea                                                 XREF[1]:     0046f1a4(j)
//                              player.cpp:642 (7)
//         0046f1ea     POP        EDI
//         0046f1eb     POP        ESI
//         0046f1ec     POP        EBP
//         0046f1ed     POP        EBX
//         0046f1ee     RET        0x14
//         0046f1f1     ??         90h
//         0046f1f2     NOP
//         0046f1f3     NOP
//         0046f1f4     NOP
//         0046f1f5     NOP
//         0046f1f6     NOP
//         0046f1f7     NOP
//         0046f1f8     NOP
//         0046f1f9     NOP
//         0046f1fa     NOP
//         0046f1fb     NOP
//         0046f1fc     NOP
//         0046f1fd     NOP
//         0046f1fe     NOP
//         0046f1ff     NOP
    return;
}

int RGE_Player::pathingAttemptCap() {
    /* TODO: Stub */
//                              int __thiscall pathingAttemptCap(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?pathingAttemptCap@RGE_Player@@QAEHXZ
//                               RGE_Player::pathingAttemptCap
//                              player.cpp:647 (3)
//         0046f200     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//                              player.cpp:649 (1)
//         0046f203     RET
//         0046f204     ??         90h
//         0046f205     NOP
//         0046f206     NOP
//         0046f207     NOP
//         0046f208     NOP
//         0046f209     NOP
//         0046f20a     NOP
//         0046f20b     NOP
//         0046f20c     NOP
//         0046f20d     NOP
//         0046f20e     NOP
//         0046f20f     NOP
    return 0;
}

void RGE_Player::setPathingAttemptCap(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setPathingAttemptCap(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f210(R)
//                               ?setPathingAttemptCap@RGE_Player@@QAEXH@Z
//                               RGE_Player::setPathingAttemptCap
//                              player.cpp:654 (7)
//         0046f210     MOV        EAX,dword ptr [ESP + param_1]
//         0046f214     MOV        dword ptr [ECX + this->pathingAttemptCapValue]
//                              player.cpp:656 (3)
//         0046f217     RET        0x4
//         0046f21a     ??         90h
//         0046f21b     NOP
//         0046f21c     NOP
//         0046f21d     NOP
//         0046f21e     NOP
//         0046f21f     NOP
    return;
}

int RGE_Player::pathingDelayCap() {
    /* TODO: Stub */
//                              int __thiscall pathingDelayCap(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?pathingDelayCap@RGE_Player@@QAEHXZ
//                               RGE_Player::pathingDelayCap
//                              player.cpp:661 (3)
//         0046f220     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//                              player.cpp:663 (1)
//         0046f223     RET
//         0046f224     ??         90h
//         0046f225     NOP
//         0046f226     NOP
//         0046f227     NOP
//         0046f228     NOP
//         0046f229     NOP
//         0046f22a     NOP
//         0046f22b     NOP
//         0046f22c     NOP
//         0046f22d     NOP
//         0046f22e     NOP
//         0046f22f     NOP
    return 0;
}

void RGE_Player::setPathingDelayCap(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setPathingDelayCap(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f230(R)
//                               ?setPathingDelayCap@RGE_Player@@QAEXH@Z
//                               RGE_Player::setPathingDelayCap
//                              player.cpp:668 (7)
//         0046f230     MOV        EAX,dword ptr [ESP + param_1]
//         0046f234     MOV        dword ptr [ECX + this->pathingDelayCapValue],EAX
//                              player.cpp:670 (3)
//         0046f237     RET        0x4
//         0046f23a     ??         90h
//         0046f23b     NOP
//         0046f23c     NOP
//         0046f23d     NOP
//         0046f23e     NOP
//         0046f23f     NOP
    return;
}

int RGE_Player::currentUpdatePathingAttempts() {
    /* TODO: Stub */
//                              int __thiscall currentUpdatePathingAttempts(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?currentUpdatePathingAttempts@RGE_Player@@QAEHXZ
//                               RGE_Player::currentUpdatePathingAttempts
//                              player.cpp:675 (3)
//         0046f240     MOV        EAX,dword ptr [ECX + this->currentUpdatePathin
//                              player.cpp:677 (1)
//         0046f243     RET
//         0046f244     ??         90h
//         0046f245     NOP
//         0046f246     NOP
//         0046f247     NOP
//         0046f248     NOP
//         0046f249     NOP
//         0046f24a     NOP
//         0046f24b     NOP
//         0046f24c     NOP
//         0046f24d     NOP
//         0046f24e     NOP
//         0046f24f     NOP
    return 0;
}

int RGE_Player::availablePathingAttempts(int param_1) {
    /* TODO: Stub */
//                              int __thiscall availablePathingAttempts(RGE_Player * this, int param
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f259(R)
//                               ?availablePathingAttempts@RGE_Player@@QAEHH@Z                XREF[4]:     findPath:0045d79b(c),
//                               RGE_Player::availablePathingAttempts                                      doMove:0045dfe9(c),
//                                                                                                         doMove:0045e4fa(c),
//                                                                                                         doTrivialMove:0045ef06(c)
//                              player.cpp:682 (15)
//         0046f250     MOV        EAX,dword ptr [ECX + this->pathingDelayCapValue]
//         0046f253     PUSH       ESI
//         0046f254     CMP        EAX,-0x1
//         0046f257     JZ         LAB_0046f268
//         0046f259     CMP        dword ptr [ESP + param_1],EAX
//         0046f25d     JLE        LAB_0046f268
//                              player.cpp:685 (5)
//         0046f25f     MOV        EAX,0x1
//                              player.cpp:693 (4)
//         0046f264     POP        ESI
//         0046f265     RET        0x4
//                               LAB_0046f268                                                 XREF[2]:     0046f257(j), 0046f25d(j)
//                              player.cpp:687 (8)
//         0046f268     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0046f26b     CMP        EAX,-0x1
//         0046f26e     JNZ        LAB_0046f279
//                              player.cpp:688 (5)
//         0046f270     MOV        EAX,0x1
//                              player.cpp:693 (4)
//         0046f275     POP        ESI
//         0046f276     RET        0x4
//                               LAB_0046f279                                                 XREF[1]:     0046f26e(j)
//                              player.cpp:690 (7)
//         0046f279     MOV        ESI,dword ptr [ECX + this->currentUpdatePathin
//         0046f27c     XOR        EDX,EDX
//         0046f27e     CMP        ESI,EAX
//                              player.cpp:693 (9)
//         0046f280     POP        ESI
//         0046f281     SETL       DL
//         0046f284     MOV        EAX,EDX
//         0046f286     RET        0x4
//         0046f289     ??         90h
//         0046f28a     NOP
//         0046f28b     NOP
//         0046f28c     NOP
//         0046f28d     NOP
//         0046f28e     NOP
//         0046f28f     NOP
    return 0;
}

void RGE_Player::incrementPathingAttempts() {
    /* TODO: Stub */
//                              void __thiscall incrementPathingAttempts(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?incrementPathingAttempts@RGE_Player@@QAEXXZ                 XREF[4]:     findPath:0045d7c2(c),
//                               RGE_Player::incrementPathingAttempts                                      doMove:0045e016(c),
//                                                                                                         doMove:0045e52b(c),
//                                                                                                         doTrivialMove:0045ef2e(c)
//                              player.cpp:698 (3)
//         0046f290     INC        dword ptr [ECX + this->currentUpdatePathingAtt
//                              player.cpp:700 (1)
//         0046f293     RET
//         0046f294     ??         90h
//         0046f295     NOP
//         0046f296     NOP
//         0046f297     NOP
//         0046f298     NOP
//         0046f299     NOP
//         0046f29a     NOP
//         0046f29b     NOP
//         0046f29c     NOP
//         0046f29d     NOP
//         0046f29e     NOP
//         0046f29f     NOP
    return;
}

void RGE_Player::sendChatMessage(int param_1, int param_2, char* param_3) {
    /* TODO: Stub */
//                              void __thiscall sendChatMessage(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f2e7(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0046f2ee(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     0046f332(R)
//              char[1025]        Stack[-0x408   textOut                   XREF[0,4]:   0046f2b1(*), 0046f2c0(*), 0046f30c(*), 0046f36f(*)
//                               ?sendChatMessage@RGE_Player@@QAAXHHPADZZ                     XREF[8]:     update:004e5407(c),
//                               RGE_Player::sendChatMessage                                               update:004e5459(c),
//                                                                                                         update:004e553e(c),
//                                                                                                         update:004e565c(c),
//                                                                                                         update:004e56c3(c),
//                                                                                                         tributeNotify:004e6399(c),
//                                                                                                         tributeNotify:004e6473(c),
//                                                                                                         revokeTributeAlliance:004e6550(c)
//                              player.cpp:706 (32)
//         0046f2a0     MOV        this,dword ptr [ESP + Stack[0x10]]
//         0046f2a4     SUB        ESP,0x404
//         0046f2aa     LEA        EAX=>Stack[0x14],[ESP + 0x418]
//         0046f2b1     LEA        EDX=>textOut[4],[ESP]
//         0046f2b5     PUSH       EBX
//         0046f2b6     PUSH       ESI
//         0046f2b7     PUSH       EDI
//         0046f2b8     PUSH       EAX
//         0046f2b9     PUSH       this
//         0046f2ba     PUSH       EDX
//         0046f2bb     CALL       vsprintf                                         undefined vsprintf()
//                              player.cpp:712 (23)
//         0046f2c0     LEA        EDI=>textOut[4],[ESP + 0x18]
//         0046f2c4     OR         this,0xffffffff
//         0046f2c7     XOR        EAX,EAX
//         0046f2c9     ADD        ESP,0xc
//         0046f2cc     SCASB.RE   ES:EDI
//         0046f2ce     NOT        this
//         0046f2d0     DEC        this
//         0046f2d1     JZ         LAB_0046f391
//                              player.cpp:714 (34)
//         0046f2d7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f2dd     MOV        ESI,0x1
//         0046f2e2     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         0046f2e7     MOV        EDI,dword ptr [ESP + param_1]
//         0046f2ee     MOV        EBX,dword ptr [ESP + param_2]
//         0046f2f5     CMP        EAX,ESI
//         0046f2f7     JL         LAB_0046f332
//                               LAB_0046f2f9                                                 XREF[1]:     0046f330(j)
//                              player.cpp:715 (12)
//         0046f2f9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f2ff     PUSH       ESI
//         0046f300     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//                              player.cpp:716 (4)
//         0046f305     CMP        EAX,EBX
//         0046f307     JNZ        LAB_0046f322
//                              player.cpp:717 (41)
//         0046f309     MOV        EDX,dword ptr [EDI + 0x3c]
//         0046f30c     LEA        EAX=>textOut[4],[ESP + 0xc]
//         0046f310     MOVSX      this,word ptr [EDI + 0x4a]
//         0046f314     PUSH       EAX
//         0046f315     MOV        EAX,dword ptr [EDX + 0x58]
//         0046f318     PUSH       ESI
//         0046f319     PUSH       this
//         0046f31a     MOV        this,dword ptr [EAX + 0x14]
//         0046f31d     CALL       TCommunications_Handler::SendChatMsg             void SendChatMsg(TCommunications_Handler * th
//                               LAB_0046f322                                                 XREF[1]:     0046f307(j)
//         0046f322     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f328     INC        ESI
//         0046f329     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         0046f32e     CMP        ESI,EAX
//         0046f330     JLE        LAB_0046f2f9
//                               LAB_0046f332                                                 XREF[1]:     0046f2f7(j)
//                              player.cpp:721 (18)
//         0046f332     CMP        dword ptr [ESP + param_3],0x1
//         0046f33a     JNZ        LAB_0046f391
//         0046f33c     MOVSX      this,word ptr [EDI + 0x4a]
//         0046f340     CMP        EBX,this
//         0046f342     JZ         LAB_0046f391
//                              player.cpp:722 (20)
//         0046f344     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f34a     MOV        ESI,0x1
//         0046f34f     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         0046f354     CMP        EAX,ESI
//         0046f356     JL         LAB_0046f391
//                               LAB_0046f358                                                 XREF[1]:     0046f38f(j)
//                              player.cpp:723 (12)
//         0046f358     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f35e     PUSH       ESI
//         0046f35f     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//                              player.cpp:724 (8)
//         0046f364     MOVSX      this,word ptr [EDI + 0x4a]
//         0046f368     CMP        EAX,this
//         0046f36a     JNZ        LAB_0046f381
//                              player.cpp:725 (37)
//         0046f36c     MOV        EAX,dword ptr [EDI + 0x3c]
//         0046f36f     LEA        EDX=>textOut[4],[ESP + 0xc]
//         0046f373     PUSH       EDX
//         0046f374     PUSH       ESI
//         0046f375     PUSH       this
//         0046f376     MOV        this,dword ptr [EAX + 0x58]
//         0046f379     MOV        this,dword ptr [ECX + this->checksum]
//         0046f37c     CALL       TCommunications_Handler::SendChatMsg             void SendChatMsg(TCommunications_Handler * th
//                               LAB_0046f381                                                 XREF[1]:     0046f36a(j)
//         0046f381     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f387     INC        ESI
//         0046f388     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         0046f38d     CMP        ESI,EAX
//         0046f38f     JLE        LAB_0046f358
//                               LAB_0046f391                                                 XREF[4]:     0046f2d1(j), 0046f33a(j),
//                                                                                                         0046f342(j), 0046f356(j)
//                              player.cpp:729 (10)
//         0046f391     POP        EDI
//         0046f392     POP        ESI
//         0046f393     POP        EBX
//         0046f394     ADD        ESP,0x404
//         0046f39a     RET
//         0046f39b     ??         90h
//         0046f39c     NOP
//         0046f39d     NOP
//         0046f39e     NOP
//         0046f39f     NOP
    return;
}

RGE_Static_Object* RGE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_scenario_obj(RGE_Player * this,
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0046f3be(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0046f3b9(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0046f3b2(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0046f3a0(R)
//              uchar             Stack[0x14]:1  param_5
//              float             Stack[0x18]:4  param_6
//                               ?make_scenario_obj@RGE_Player@@UAEPAVRGE_Static_Object@@MMM  XREF[1]:     00570f30(*)
//                               RGE_Player::make_scenario_obj
//                              player.cpp:734 (18)
//         0046f3a0     MOVSX      EAX,word ptr [ESP + param_4]
//         0046f3a5     MOV        EDX,dword ptr [ECX + this->master_objects]
//         0046f3a8     PUSH       ESI
//         0046f3a9     XOR        ESI,ESI
//         0046f3ab     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         0046f3ae     TEST       EAX,EAX
//         0046f3b0     JZ         LAB_0046f400
//                              player.cpp:739 (25)
//         0046f3b2     MOV        ESI,dword ptr [ESP + param_3]
//         0046f3b6     MOV        EDX,dword ptr [EAX]
//         0046f3b8     PUSH       ESI
//         0046f3b9     MOV        ESI,dword ptr [ESP + param_2]
//         0046f3bd     PUSH       ESI
//         0046f3be     MOV        ESI,dword ptr [ESP + param_1]
//         0046f3c2     PUSH       ESI
//         0046f3c3     PUSH       this
//         0046f3c4     MOV        this,EAX
//         0046f3c6     CALL       dword ptr [EDX + 0x18]
//         0046f3c9     MOV        ESI,EAX
//                              player.cpp:740 (8)
//         0046f3cb     MOV        AL,byte ptr [ESP + 0x18]
//         0046f3cf     CMP        AL,0x7
//         0046f3d1     JC         LAB_0046f3e0
//                              player.cpp:741 (7)
//         0046f3d3     MOV        EAX,dword ptr [ESI]
//         0046f3d5     MOV        this,ESI
//         0046f3d7     CALL       dword ptr [EAX + 0x68]
//                              player.cpp:748 (2)
//         0046f3da     MOV        EAX,ESI
//                              player.cpp:749 (4)
//         0046f3dc     POP        ESI
//         0046f3dd     RET        0x18
//                               LAB_0046f3e0                                                 XREF[1]:     0046f3d1(j)
//                              player.cpp:742 (4)
//         0046f3e0     CMP        AL,0x2
//         0046f3e2     JBE        LAB_0046f3f1
//                              player.cpp:743 (7)
//         0046f3e4     MOV        EDX,dword ptr [ESI]
//         0046f3e6     MOV        this,ESI
//         0046f3e8     CALL       dword ptr [EDX + 0x6c]
//                              player.cpp:748 (2)
//         0046f3eb     MOV        EAX,ESI
//                              player.cpp:749 (4)
//         0046f3ed     POP        ESI
//         0046f3ee     RET        0x18
//                               LAB_0046f3f1                                                 XREF[1]:     0046f3e2(j)
//                              player.cpp:745 (15)
//         0046f3f1     MOV        this,dword ptr [ESP + 0x1c]
//         0046f3f5     MOV        EAX,dword ptr [ESI]
//         0046f3f7     PUSH       this
//         0046f3f8     MOV        this,ESI
//         0046f3fa     CALL       dword ptr [EAX + 0xb4]
//                               LAB_0046f400                                                 XREF[1]:     0046f3b0(j)
//                              player.cpp:748 (2)
//         0046f400     MOV        EAX,ESI
//                              player.cpp:749 (4)
//         0046f402     POP        ESI
//         0046f403     RET        0x18
//         0046f406     ??         90h
//         0046f407     NOP
//         0046f408     NOP
//         0046f409     NOP
//         0046f40a     NOP
//         0046f40b     NOP
//         0046f40c     NOP
//         0046f40d     NOP
//         0046f40e     NOP
//         0046f40f     NOP
    return 0;
}

void RGE_Player::scenario_save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall scenario_save(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?scenario_save@RGE_Player@@UAEXH@Z                           XREF[2]:     scenario_save:00512639(c),
//                               RGE_Player::scenario_save                                                 00570f34(*)
//                              player.cpp:753 (3)
//         0046f410     RET        0x4
//         0046f413     ??         90h
//         0046f414     NOP
//         0046f415     NOP
//         0046f416     NOP
//         0046f417     NOP
//         0046f418     NOP
//         0046f419     NOP
//         0046f41a     NOP
//         0046f41b     NOP
//         0046f41c     NOP
//         0046f41d     NOP
//         0046f41e     NOP
//         0046f41f     NOP
    return;
}

void RGE_Player::scenario_load(int param_1, long* param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall scenario_load(RGE_Player * this, int param_1, long *
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0046f43d(R), 0046f5bc(*), 0046f5f1(R), 0046f619(R)
//              long *            Stack[0x8]:4   param_2                   XREF[2]:     0046f5d0(R), 0046f691(R)
//              float             Stack[0xc]:4   param_3                   XREF[3]:     0046f420(R), 0046f54e(R), 0046f657(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0046f4e7(W), 0046f54a(W), 0046f5b8(R)
//              int               Stack[-0x8]:4  has_team                  XREF[3,3]:   0046f442(*), 0046f44f(R), 0046f467(R), 0046f59a(*),
//                                                                                     0046f5aa(R), 0046f64c(R)
//              short             Stack[-0xa]:2  player_count              XREF[0,2]:   0046f55f(*), 0046f573(R)
//              short             Stack[-0xc]:2  count
//              uchar             Stack[-0xd]:1  temp_byte
//                               ?scenario_load@RGE_Player@@UAEXHPAJM@Z                       XREF[2]:     scenario_load:005126bb(c),
//                               RGE_Player::scenario_load                                                 00570f38(*)
//                              player.cpp:758 (29)
//         0046f420     FLD        float ptr [ESP + param_3]
//         0046f424     FCOMP      double ptr [DAT_00570e98]                        = CDh
//         0046f42a     SUB        ESP,0xc
//         0046f42d     PUSH       ESI
//         0046f42e     MOV        ESI,this
//         0046f430     FNSTSW     AX
//         0046f432     TEST       AH,0x41
//         0046f435     JZ         LAB_0046f6a6
//         0046f43b     PUSH       EDI
//         0046f43c     PUSH       EBP
//                              player.cpp:768 (18)
//         0046f43d     MOV        EBP,dword ptr [ESP + param_1]
//         0046f441     PUSH       EBX
//         0046f442     LEA        EAX=>has_team,[ESP + 0x14]
//         0046f446     PUSH       0x2
//         0046f448     PUSH       EAX
//         0046f449     PUSH       EBP
//         0046f44a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:769 (13)
//         0046f44f     MOV        AX,word ptr [ESP + has_team]
//         0046f454     ADD        ESP,0xc
//         0046f457     TEST       AX,AX
//         0046f45a     JLE        LAB_0046f491
//                              player.cpp:771 (11)
//         0046f45c     MOVSX      this,AX
//         0046f45f     PUSH       0x1
//         0046f461     PUSH       this
//         0046f462     CALL       calloc                                           undefined calloc()
//                              player.cpp:772 (18)
//         0046f467     MOVSX      EDX,word ptr [ESP + has_team]
//         0046f46c     ADD        ESP,0x8
//         0046f46f     MOV        EDI,EAX
//         0046f471     PUSH       EDX
//         0046f472     PUSH       EDI
//         0046f473     PUSH       EBP
//         0046f474     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:773 (10)
//         0046f479     MOV        EAX,dword ptr [ESI + 0x44]
//         0046f47c     ADD        ESP,0xc
//         0046f47f     TEST       EAX,EAX
//         0046f481     JNZ        LAB_0046f488
//                              player.cpp:774 (3)
//         0046f483     MOV        dword ptr [ESI + 0x44],EDI
//                              player.cpp:775 (2)
//         0046f486     JMP        LAB_0046f491
//                               LAB_0046f488                                                 XREF[1]:     0046f481(j)
//                              player.cpp:776 (9)
//         0046f488     PUSH       EDI
//         0046f489     CALL       free                                             undefined free()
//         0046f48e     ADD        ESP,0x4
//                               LAB_0046f491                                                 XREF[2]:     0046f45a(j), 0046f486(j)
//                              player.cpp:779 (18)
//         0046f491     LEA        EAX,[ESI + 0x114]
//         0046f497     PUSH       0x4
//         0046f499     PUSH       EAX
//         0046f49a     PUSH       EBP
//         0046f49b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f4a0     ADD        ESP,0xc
//                              player.cpp:780 (18)
//         0046f4a3     LEA        this,[ESI + 0x118]
//         0046f4a9     PUSH       0x4
//         0046f4ab     PUSH       this
//         0046f4ac     PUSH       EBP
//         0046f4ad     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f4b2     ADD        ESP,0xc
//                              player.cpp:781 (18)
//         0046f4b5     LEA        EDX,[ESI + 0x11c]
//         0046f4bb     PUSH       0x2
//         0046f4bd     PUSH       EDX
//         0046f4be     PUSH       EBP
//         0046f4bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f4c4     ADD        ESP,0xc
//                              player.cpp:782 (15)
//         0046f4c7     LEA        EAX,[ESI + 0x11e]
//         0046f4cd     PUSH       0x2
//         0046f4cf     PUSH       EAX
//         0046f4d0     PUSH       EBP
//         0046f4d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:789 (26)
//         0046f4d6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f4dc     ADD        ESP,0xc
//         0046f4df     XOR        EBX,EBX
//         0046f4e1     MOV        EAX,dword ptr [ECX + this+0x1b0]
//         0046f4e7     MOV        dword ptr [ESP + local_4],EBX
//         0046f4eb     CMP        EAX,0x7
//         0046f4ee     JZ         LAB_0046f54e
//                              player.cpp:791 (5)
//         0046f4f0     MOV        EDI,0x1
//                               LAB_0046f4f5                                                 XREF[1]:     0046f52f(j)
//                              player.cpp:793 (54)
//         0046f4f5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f4fb     PUSH       EDI
//         0046f4fc     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//         0046f501     MOVSX      EDX,word ptr [ESI + 0x4a]
//         0046f505     CMP        EAX,EDX
//         0046f507     JNZ        LAB_0046f52b
//         0046f509     MOV        this,dword ptr [comm]                            = 00000000
//         0046f50f     PUSH       EDI
//         0046f510     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         0046f515     CMP        EAX,0x2
//         0046f518     JZ         LAB_0046f533
//         0046f51a     MOV        this,dword ptr [comm]                            = 00000000
//         0046f520     PUSH       EDI
//         0046f521     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         0046f526     CMP        EAX,0x4
//         0046f529     JZ         LAB_0046f533
//                               LAB_0046f52b                                                 XREF[1]:     0046f507(j)
//                              player.cpp:791 (8)
//         0046f52b     INC        EDI
//         0046f52c     CMP        EDI,0x9
//         0046f52f     JL         LAB_0046f4f5
//         0046f531     JMP        LAB_0046f54e
//                               LAB_0046f533                                                 XREF[2]:     0046f518(j), 0046f529(j)
//                              player.cpp:795 (18)
//         0046f533     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f539     DEC        EDI
//         0046f53a     PUSH       EDI
//         0046f53b     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         0046f540     CMP        EAX,0x1
//         0046f543     JLE        LAB_0046f54e
//                              player.cpp:796 (9)
//         0046f545     MOV        EBX,0x1
//         0046f54a     MOV        dword ptr [ESP + local_4],EBX
//                               LAB_0046f54e                                                 XREF[3]:     0046f4ee(j), 0046f531(j),
//                                                                                                         0046f543(j)
//                              player.cpp:803 (17)
//         0046f54e     FLD        float ptr [ESP + param_3]
//         0046f552     FCOMP      double ptr [DAT_00570ea0]
//         0046f558     FNSTSW     AX
//         0046f55a     TEST       AH,0x41
//         0046f55d     JNZ        LAB_0046f57d
//                              player.cpp:806 (16)
//         0046f55f     LEA        EAX=>player_count+0x1,[ESP + 0x13]
//         0046f563     PUSH       0x1
//         0046f565     PUSH       EAX
//         0046f566     PUSH       EBP
//         0046f567     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f56c     ADD        ESP,0xc
//                              player.cpp:807 (4)
//         0046f56f     TEST       EBX,EBX
//         0046f571     JNZ        LAB_0046f57d
//                              player.cpp:808 (10)
//         0046f573     MOV        this,byte ptr [ESP + player_count+0x1]
//         0046f577     MOV        byte ptr [ESI + 0x104],this
//                               LAB_0046f57d                                                 XREF[2]:     0046f55d(j), 0046f571(j)
//                              player.cpp:811 (2)
//         0046f57d     XOR        EDI,EDI
//                              player.cpp:815 (12)
//         0046f57f     CMP        word ptr [ESI + 0x4c],DI
//         0046f583     MOV        dword ptr [ESI + 0x100],EDI
//         0046f589     JLE        LAB_0046f59a
//                              player.cpp:816 (15)
//         0046f58b     MOV        EDX,dword ptr [ESI + 0x50]
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         0046f58e     PUSH       0x74
//         0046f590     PUSH       EDX
//         0046f591     PUSH       EBP
//         0046f592     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f597     ADD        ESP,0xc
//                               LAB_0046f59a                                                 XREF[1]:     0046f589(j)
//                              player.cpp:819 (16)
//         0046f59a     LEA        EAX=>has_team+0x2,[ESP + 0x16]
//         0046f59e     PUSH       0x2
//         0046f5a0     PUSH       EAX
//         0046f5a1     PUSH       EBP
//         0046f5a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f5a7     ADD        ESP,0xc
//                              player.cpp:820 (18)
//         0046f5aa     CMP        word ptr [ESP + has_team+0x2],0x0
//         0046f5b0     JLE        LAB_0046f657
//         0046f5b6     JMP        LAB_0046f5bc
//                               LAB_0046f5b8                                                 XREF[1]:     0046f651(j)
//         0046f5b8     MOV        EBX,dword ptr [ESP + local_4]
//                               LAB_0046f5bc                                                 XREF[1]:     0046f5b6(j)
//                              player.cpp:822 (16)
//         0046f5bc     LEA        this=>param_1,[ESP + 0x20]
//         0046f5c0     PUSH       0x1
//         0046f5c2     PUSH       this
//         0046f5c3     PUSH       EBP
//         0046f5c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f5c9     ADD        ESP,0xc
//                              player.cpp:823 (4)
//         0046f5cc     TEST       EBX,EBX
//         0046f5ce     JNZ        LAB_0046f64b
//                              player.cpp:825 (27)
//         0046f5d0     MOV        EAX,dword ptr [ESP + param_2]
//         0046f5d4     MOVSX      EDX,DI
//         0046f5d7     LEA        this,[EAX + EDX*0x4]
//         0046f5da     MOV        EDX,dword ptr [ESI + 0x3c]
//         0046f5dd     MOVSX      EDX,word ptr [EDX + 0x3c]
//         0046f5e1     MOV        EAX,dword ptr [this->_padding_]
//         0046f5e3     CMP        EAX,EDX
//         0046f5e5     JGE        LAB_0046f64b
//         0046f5e7     TEST       EAX,EAX
//         0046f5e9     JL         LAB_0046f64b
//                              player.cpp:827 (13)
//         0046f5eb     MOV        EDX,dword ptr [ESI + 0x84]
//         0046f5f1     MOV        BL,byte ptr [ESP + param_1]
//         0046f5f5     MOV        byte ptr [EDX + EAX*0x1],BL
//                              player.cpp:828 (6)
//         0046f5f8     MOV        EAX,dword ptr [this->_padding_]
//         0046f5fa     TEST       EAX,EAX
//         0046f5fc     JNZ        LAB_0046f606
//                              player.cpp:829 (6)
//         0046f5fe     MOV        dword ptr [ESI + 0x88],EAX
//                              player.cpp:830 (8)
//         0046f604     JMP        LAB_0046f64b
//                               LAB_0046f606                                                 XREF[1]:     0046f5fc(j)
//         0046f606     CMP        DI,word ptr [ESI + 0x4a]
//         0046f60a     JNZ        LAB_0046f619
//                              player.cpp:831 (11)
//         0046f60c     MOV        dword ptr [ESI + EAX*0x4 + 0x88],0x1
//                              player.cpp:832 (10)
//         0046f617     JMP        LAB_0046f64b
//                               LAB_0046f619                                                 XREF[1]:     0046f60a(j)
//         0046f619     MOV        this,byte ptr [ESP + param_1]
//         0046f61d     TEST       this,this
//         0046f61f     JNZ        LAB_0046f62e
//                              player.cpp:833 (11)
//         0046f621     MOV        dword ptr [ESI + EAX*0x4 + 0x88],0x2
//                              player.cpp:834 (7)
//         0046f62c     JMP        LAB_0046f64b
//                               LAB_0046f62e                                                 XREF[1]:     0046f61f(j)
//         0046f62e     CMP        this,0x1
//         0046f631     JNZ        LAB_0046f640
//                              player.cpp:835 (11)
//         0046f633     MOV        dword ptr [ESI + EAX*0x4 + 0x88],0x3
//                              player.cpp:836 (2)
//         0046f63e     JMP        LAB_0046f64b
//                               LAB_0046f640                                                 XREF[1]:     0046f631(j)
//                              player.cpp:837 (11)
//         0046f640     MOV        dword ptr [ESI + EAX*0x4 + 0x88],0x4
//                               LAB_0046f64b                                                 XREF[7]:     0046f5ce(j), 0046f5e5(j),
//                                                                                                         0046f5e9(j), 0046f604(j),
//                                                                                                         0046f617(j), 0046f62c(j),
//                                                                                                         0046f63e(j)
//                              player.cpp:820 (12)
//         0046f64b     INC        EDI
//         0046f64c     CMP        DI,word ptr [ESP + has_team+0x2]
//         0046f651     JL         LAB_0046f5b8
//                               LAB_0046f657                                                 XREF[1]:     0046f5b0(j)
//                              player.cpp:842 (17)
//         0046f657     FLD        float ptr [ESP + param_3]
//         0046f65b     FCOMP      double ptr [DAT_00570ea8]                        = 48h    H
//         0046f661     FNSTSW     AX
//         0046f663     TEST       AH,0x41
//         0046f666     JNZ        LAB_0046f67a
//                              player.cpp:843 (18)
//         0046f668     LEA        EAX,[ESI + 0x88]
//         0046f66e     PUSH       0x24
//         0046f670     PUSH       EAX
//         0046f671     PUSH       EBP
//         0046f672     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f677     ADD        ESP,0xc
//                               LAB_0046f67a                                                 XREF[1]:     0046f666(j)
//                              player.cpp:845 (7)
//         0046f67a     MOV        EDI,dword ptr [ESI + 0x34]
//         0046f67d     TEST       EDI,EDI
//         0046f67f     JZ         LAB_0046f691
//                              player.cpp:846 (16)
//         0046f681     MOV        this,EDI
//         0046f683     CALL       RGE_Victory_Conditions::~RGE_Victory_Conditions  void ~RGE_Victory_Conditions(RGE_Victory_Cond
//         0046f688     PUSH       EDI
//         0046f689     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046f68e     ADD        ESP,0x4
//                               LAB_0046f691                                                 XREF[1]:     0046f67f(j)
//                              player.cpp:849 (21)
//         0046f691     MOV        EAX,dword ptr [ESP + param_2]
//         0046f695     MOV        EDX,dword ptr [ESI]
//         0046f697     PUSH       0x0
//         0046f699     PUSH       EAX
//         0046f69a     PUSH       EBP
//         0046f69b     MOV        this,ESI
//         0046f69d     CALL       dword ptr [EDX + 0xf0]
//         0046f6a3     POP        EBX
//         0046f6a4     POP        EBP
//         0046f6a5     POP        EDI
//                               LAB_0046f6a6                                                 XREF[1]:     0046f435(j)
//                              player.cpp:851 (7)
//         0046f6a6     POP        ESI
//         0046f6a7     ADD        ESP,0xc
//         0046f6aa     RET        0xc
//         0046f6ad     ??         90h
//         0046f6ae     NOP
//         0046f6af     NOP
    return;
}

void RGE_Player::scenario_postsave(int param_1) {
    /* TODO: Stub */
//                              void __thiscall scenario_postsave(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046f6bf(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0046f6c3(*), 0046f6cd(W), 0046f6d6(R)
//              short             Stack[-0x8]:2  count
//                               ?scenario_postsave@RGE_Player@@UAEXH@Z                       XREF[3]:     00570f3c(*), 005768dc(*),
//                               RGE_Player::scenario_postsave                                             00576a0c(*)
//                              player.cpp:855 (5)
//         0046f6b0     PUSH       this
//         0046f6b1     PUSH       ESI
//         0046f6b2     MOV        ESI,this
//         0046f6b4     PUSH       EDI
//                              player.cpp:858 (10)
//         0046f6b5     OR         this,0xffffffff
//         0046f6b8     MOV        EDI,dword ptr [ESI + 0x44]
//         0046f6bb     XOR        EAX,EAX
//         0046f6bd     SCASB.RE   ES:EDI
//                              player.cpp:859 (23)
//         0046f6bf     MOV        EDI,dword ptr [ESP + param_1]
//         0046f6c3     LEA        EAX=>local_4,[ESP + 0x8]
//         0046f6c7     PUSH       0x2
//         0046f6c9     PUSH       EAX
//         0046f6ca     NOT        this
//         0046f6cc     PUSH       EDI
//         0046f6cd     MOV        dword ptr [ESP + local_4],this
//         0046f6d1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:860 (22)
//         0046f6d6     MOVSX      this,word ptr [ESP + local_4]
//         0046f6db     MOV        EDX,dword ptr [ESI + 0x44]
//         0046f6de     ADD        ESP,0xc
//         0046f6e1     PUSH       this
//         0046f6e2     PUSH       EDX
//         0046f6e3     PUSH       EDI
//         0046f6e4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f6e9     ADD        ESP,0xc
//                              player.cpp:862 (18)
//         0046f6ec     LEA        EAX,[ESI + 0x114]
//         0046f6f2     PUSH       0x4
//         0046f6f4     PUSH       EAX
//         0046f6f5     PUSH       EDI
//         0046f6f6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f6fb     ADD        ESP,0xc
//                              player.cpp:863 (18)
//         0046f6fe     LEA        this,[ESI + 0x118]
//         0046f704     PUSH       0x4
//         0046f706     PUSH       this
//         0046f707     PUSH       EDI
//         0046f708     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f70d     ADD        ESP,0xc
//                              player.cpp:864 (18)
//         0046f710     LEA        EDX,[ESI + 0x11c]
//         0046f716     PUSH       0x2
//         0046f718     PUSH       EDX
//         0046f719     PUSH       EDI
//         0046f71a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f71f     ADD        ESP,0xc
//                              player.cpp:865 (18)
//         0046f722     LEA        EAX,[ESI + 0x11e]
//         0046f728     PUSH       0x2
//         0046f72a     PUSH       EAX
//         0046f72b     PUSH       EDI
//         0046f72c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f731     ADD        ESP,0xc
//                              player.cpp:866 (15)
//         0046f734     LEA        this,[ESI + 0x104]
//         0046f73a     PUSH       0x1
//         0046f73c     PUSH       this
//         0046f73d     PUSH       EDI
//         0046f73e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:869 (18)
//         0046f743     MOV        EDX,dword ptr [ESI + 0x3c]
//         0046f746     ADD        ESP,0xc
//         0046f749     ADD        EDX,0x3c
//         0046f74c     PUSH       0x2
//         0046f74e     PUSH       EDX
//         0046f74f     PUSH       EDI
//         0046f750     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:870 (27)
//         0046f755     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046f758     MOV        EDX,dword ptr [ESI + 0x84]
//         0046f75e     ADD        ESP,0xc
//         0046f761     MOVSX      this,word ptr [EAX + 0x3c]
//         0046f765     PUSH       this
//         0046f766     PUSH       EDX
//         0046f767     PUSH       EDI
//         0046f768     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0046f76d     ADD        ESP,0xc
//                              player.cpp:871 (15)
//         0046f770     LEA        EAX,[ESI + 0x88]
//         0046f776     PUSH       0x24
//         0046f778     PUSH       EAX
//         0046f779     PUSH       EDI
//         0046f77a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:873 (12)
//         0046f77f     MOV        this,dword ptr [ESI + 0x34]
//         0046f782     ADD        ESP,0xc
//         0046f785     MOV        EDX,dword ptr [this->_padding_]
//         0046f787     PUSH       EDI
//         0046f788     CALL       dword ptr [EDX + 0xc]
//                              player.cpp:874 (6)
//         0046f78b     POP        EDI
//         0046f78c     POP        ESI
//         0046f78d     POP        this
//         0046f78e     RET        0x4
//         0046f791     ??         90h
//         0046f792     NOP
//         0046f793     NOP
//         0046f794     NOP
//         0046f795     NOP
//         0046f796     NOP
//         0046f797     NOP
//         0046f798     NOP
//         0046f799     NOP
//         0046f79a     NOP
//         0046f79b     NOP
//         0046f79c     NOP
//         0046f79d     NOP
//         0046f79e     NOP
//         0046f79f     NOP
    return;
}

void RGE_Player::scenario_postload(int param_1, long* param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall scenario_postload(RGE_Player * this, int param_1, lo
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0046f7a9(R), 0046f936(*), 0046f975(R), 0046f9a3(R)
//              long *            Stack[0x8]:4   param_2                   XREF[2]:     0046f92c(R), 0046f9d4(R)
//              float             Stack[0xc]:4   param_3                   XREF[4]:     0046f8b6(R), 0046f8e9(R), 0046f9e4(R), 0046fa1e(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046f84c(W), 0046f8ae(W), 0046f8d4(R), 0046f943(R)
//              int               Stack[-0x8]:4  has_team                  XREF[3,3]:   0046f7a3(*), 0046f7ba(R), 0046f7d4(R), 0046f915(*),
//                                                                                     0046f927(R), 0046f9d9(R)
//              short             Stack[-0xa]:2  player_count              XREF[0,2]:   0046f8c7(*), 0046f8df(R)
//              short             Stack[-0xc]:2  count
//              uchar             Stack[-0xd]:1  temp_byte
//                               ?scenario_postload@RGE_Player@@UAEXHPAJM@Z                   XREF[2]:     scenario_postload:00519d64(c),
//                               RGE_Player::scenario_postload                                             00570f40(*)
//                              player.cpp:879 (3)
//         0046f7a0     SUB        ESP,0xc
//                              player.cpp:888 (23)
//         0046f7a3     LEA        EAX=>has_team,[ESP + 0x4]
//         0046f7a7     PUSH       EBX
//         0046f7a8     PUSH       EBP
//         0046f7a9     MOV        EBP,dword ptr [ESP + param_1]
//         0046f7ad     PUSH       ESI
//         0046f7ae     PUSH       EDI
//         0046f7af     PUSH       0x2
//         0046f7b1     PUSH       EAX
//         0046f7b2     MOV        ESI,this
//         0046f7b4     PUSH       EBP
//         0046f7b5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:889 (15)
//         0046f7ba     MOV        AX,word ptr [ESP + has_team]
//         0046f7bf     XOR        EBX,EBX
//         0046f7c1     ADD        ESP,0xc
//         0046f7c4     CMP        AX,BX
//         0046f7c7     JLE        LAB_0046f7fe
//                              player.cpp:891 (11)
//         0046f7c9     MOVSX      this,AX
//         0046f7cc     PUSH       0x1
//         0046f7ce     PUSH       this
//         0046f7cf     CALL       calloc                                           undefined calloc()
//                              player.cpp:892 (18)
//         0046f7d4     MOVSX      EDX,word ptr [ESP + has_team]
//         0046f7d9     ADD        ESP,0x8
//         0046f7dc     MOV        EDI,EAX
//         0046f7de     PUSH       EDX
//         0046f7df     PUSH       EDI
//         0046f7e0     PUSH       EBP
//         0046f7e1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:893 (10)
//         0046f7e6     MOV        EAX,dword ptr [ESI + 0x44]
//         0046f7e9     ADD        ESP,0xc
//         0046f7ec     CMP        EAX,EBX
//         0046f7ee     JNZ        LAB_0046f7f5
//                              player.cpp:894 (3)
//         0046f7f0     MOV        dword ptr [ESI + 0x44],EDI
//                              player.cpp:895 (2)
//         0046f7f3     JMP        LAB_0046f7fe
//                               LAB_0046f7f5                                                 XREF[1]:     0046f7ee(j)
//                              player.cpp:896 (9)
//         0046f7f5     PUSH       EDI
//         0046f7f6     CALL       free                                             undefined free()
//         0046f7fb     ADD        ESP,0x4
//                               LAB_0046f7fe                                                 XREF[2]:     0046f7c7(j), 0046f7f3(j)
//                              player.cpp:899 (18)
//         0046f7fe     LEA        EAX,[ESI + 0x114]
//         0046f804     PUSH       0x4
//         0046f806     PUSH       EAX
//         0046f807     PUSH       EBP
//         0046f808     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f80d     ADD        ESP,0xc
//                              player.cpp:900 (18)
//         0046f810     LEA        this,[ESI + 0x118]
//         0046f816     PUSH       0x4
//         0046f818     PUSH       this
//         0046f819     PUSH       EBP
//         0046f81a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f81f     ADD        ESP,0xc
//                              player.cpp:901 (18)
//         0046f822     LEA        EDX,[ESI + 0x11c]
//         0046f828     PUSH       0x2
//         0046f82a     PUSH       EDX
//         0046f82b     PUSH       EBP
//         0046f82c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f831     ADD        ESP,0xc
//                              player.cpp:902 (15)
//         0046f834     LEA        EAX,[ESI + 0x11e]
//         0046f83a     PUSH       0x2
//         0046f83c     PUSH       EAX
//         0046f83d     PUSH       EBP
//         0046f83e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:908 (22)
//         0046f843     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f849     ADD        ESP,0xc
//         0046f84c     MOV        dword ptr [ESP + local_4],EBX
//         0046f850     CMP        dword ptr [ECX + this+0x1b0],0x7
//         0046f857     JZ         LAB_0046f8b6
//                              player.cpp:910 (5)
//         0046f859     MOV        EDI,0x1
//                               LAB_0046f85e                                                 XREF[1]:     0046f898(j)
//                              player.cpp:912 (54)
//         0046f85e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f864     PUSH       EDI
//         0046f865     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//         0046f86a     MOVSX      EDX,word ptr [ESI + 0x4a]
//         0046f86e     CMP        EAX,EDX
//         0046f870     JNZ        LAB_0046f894
//         0046f872     MOV        this,dword ptr [comm]                            = 00000000
//         0046f878     PUSH       EDI
//         0046f879     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         0046f87e     CMP        EAX,0x2
//         0046f881     JZ         LAB_0046f89c
//         0046f883     MOV        this,dword ptr [comm]                            = 00000000
//         0046f889     PUSH       EDI
//         0046f88a     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         0046f88f     CMP        EAX,0x4
//         0046f892     JZ         LAB_0046f89c
//                               LAB_0046f894                                                 XREF[1]:     0046f870(j)
//                              player.cpp:910 (8)
//         0046f894     INC        EDI
//         0046f895     CMP        EDI,0x9
//         0046f898     JL         LAB_0046f85e
//         0046f89a     JMP        LAB_0046f8b6
//                               LAB_0046f89c                                                 XREF[2]:     0046f881(j), 0046f892(j)
//                              player.cpp:914 (18)
//         0046f89c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0046f8a2     DEC        EDI
//         0046f8a3     PUSH       EDI
//         0046f8a4     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         0046f8a9     CMP        EAX,0x1
//         0046f8ac     JLE        LAB_0046f8b6
//                              player.cpp:915 (8)
//         0046f8ae     MOV        dword ptr [ESP + local_4],0x1
//                               LAB_0046f8b6                                                 XREF[3]:     0046f857(j), 0046f89a(j),
//                                                                                                         0046f8ac(j)
//                              player.cpp:921 (17)
//         0046f8b6     FLD        float ptr [ESP + param_3]
//         0046f8ba     FCOMP      double ptr [DAT_00570ea0]
//         0046f8c0     FNSTSW     AX
//         0046f8c2     TEST       AH,0x41
//         0046f8c5     JNZ        LAB_0046f8e9
//                              player.cpp:924 (13)
//         0046f8c7     LEA        EAX=>player_count+0x1,[ESP + 0x13]
//         0046f8cb     PUSH       0x1
//         0046f8cd     PUSH       EAX
//         0046f8ce     PUSH       EBP
//         0046f8cf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:925 (11)
//         0046f8d4     MOV        EAX,dword ptr [ESP + local_4]
//         0046f8d8     ADD        ESP,0xc
//         0046f8db     CMP        EAX,EBX
//         0046f8dd     JNZ        LAB_0046f8e9
//                              player.cpp:926 (10)
//         0046f8df     MOV        this,byte ptr [ESP + player_count+0x1]
//         0046f8e3     MOV        byte ptr [ESI + 0x104],this
//                               LAB_0046f8e9                                                 XREF[2]:     0046f8c5(j), 0046f8dd(j)
//                              player.cpp:932 (23)
//         0046f8e9     FLD        float ptr [ESP + param_3]
//         0046f8ed     FCOMP      double ptr [DAT_00570eb0]                        = F6h
//         0046f8f3     MOV        dword ptr [ESI + 0x100],EBX
//         0046f8f9     FNSTSW     AX
//         0046f8fb     TEST       AH,0x41
//         0046f8fe     JZ         LAB_0046f915
//                              player.cpp:933 (6)
//         0046f900     CMP        word ptr [ESI + 0x4c],BX
//         0046f904     JLE        LAB_0046f915
//                              player.cpp:934 (15)
//         0046f906     MOV        EDX,dword ptr [ESI + 0x50]
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         0046f909     PUSH       0x74
//         0046f90b     PUSH       EDX
//         0046f90c     PUSH       EBP
//         0046f90d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f912     ADD        ESP,0xc
//                               LAB_0046f915                                                 XREF[2]:     0046f8fe(j), 0046f904(j)
//                              player.cpp:937 (16)
//         0046f915     LEA        EAX=>has_team+0x2,[ESP + 0x16]
//         0046f919     PUSH       0x2
//         0046f91b     PUSH       EAX
//         0046f91c     PUSH       EBP
//         0046f91d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046f922     ADD        ESP,0xc
//                              player.cpp:938 (17)
//         0046f925     XOR        EDI,EDI
//         0046f927     CMP        word ptr [ESP + has_team+0x2],BX
//         0046f92c     MOV        EBX,dword ptr [ESP + param_2]
//         0046f930     JLE        LAB_0046f9e4
//                               LAB_0046f936                                                 XREF[1]:     0046f9de(j)
//                              player.cpp:940 (13)
//         0046f936     LEA        this=>param_1,[ESP + 0x20]
//         0046f93a     PUSH       0x1
//         0046f93c     PUSH       this
//         0046f93d     PUSH       EBP
//         0046f93e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:941 (15)
//         0046f943     MOV        EAX,dword ptr [ESP + local_4]
//         0046f947     ADD        ESP,0xc
//         0046f94a     TEST       EAX,EAX
//         0046f94c     JNZ        LAB_0046f9d4
//                              player.cpp:943 (4)
//         0046f952     TEST       EBX,EBX
//         0046f954     JZ         LAB_0046f95f
//                              player.cpp:944 (7)
//         0046f956     MOVSX      EDX,DI
//         0046f959     MOV        AX,word ptr [EBX + EDX*0x4]
//                              player.cpp:945 (2)
//         0046f95d     JMP        LAB_0046f961
//                               LAB_0046f95f                                                 XREF[1]:     0046f954(j)
//                              player.cpp:946 (2)
//         0046f95f     MOV        EAX,EDI
//                               LAB_0046f961                                                 XREF[1]:     0046f95d(j)
//                              player.cpp:948 (14)
//         0046f961     MOV        this,dword ptr [ESI + 0x3c]
//         0046f964     CMP        AX,word ptr [ECX + this->world]
//         0046f968     JGE        LAB_0046f9d4
//         0046f96a     TEST       AX,AX
//         0046f96d     JL         LAB_0046f9d4
//                              player.cpp:950 (13)
//         0046f96f     MOV        EDX,dword ptr [ESI + 0x84]
//         0046f975     MOV        BL,byte ptr [ESP + param_1]
//         0046f979     MOVSX      this,AX
//                              player.cpp:951 (8)
//         0046f97c     TEST       AX,AX
//         0046f97f     MOV        byte ptr [EDX + this->_padding_*0x1],BL
//         0046f982     JNZ        LAB_0046f990
//                              player.cpp:952 (10)
//         0046f984     MOV        dword ptr [ESI + 0x88],0x0
//                              player.cpp:953 (8)
//         0046f98e     JMP        LAB_0046f9d4
//                               LAB_0046f990                                                 XREF[1]:     0046f982(j)
//         0046f990     CMP        AX,word ptr [ESI + 0x4a]
//         0046f994     JNZ        LAB_0046f9a3
//                              player.cpp:954 (11)
//         0046f996     MOV        dword ptr [ESI + this->_padding_*0x4 + 0x88],0x1
//                              player.cpp:955 (10)
//         0046f9a1     JMP        LAB_0046f9d4
//                               LAB_0046f9a3                                                 XREF[1]:     0046f994(j)
//         0046f9a3     MOV        AL,byte ptr [ESP + param_1]
//         0046f9a7     TEST       AL,AL
//         0046f9a9     JNZ        LAB_0046f9b8
//                              player.cpp:956 (11)
//         0046f9ab     MOV        dword ptr [ESI + this->_padding_*0x4 + 0x88],0x2
//                              player.cpp:957 (6)
//         0046f9b6     JMP        LAB_0046f9d4
//                               LAB_0046f9b8                                                 XREF[1]:     0046f9a9(j)
//         0046f9b8     CMP        AL,0x1
//         0046f9ba     JNZ        LAB_0046f9c9
//                              player.cpp:958 (11)
//         0046f9bc     MOV        dword ptr [ESI + this->_padding_*0x4 + 0x88],0x3
//                              player.cpp:959 (2)
//         0046f9c7     JMP        LAB_0046f9d4
//                               LAB_0046f9c9                                                 XREF[1]:     0046f9ba(j)
//                              player.cpp:960 (11)
//         0046f9c9     MOV        dword ptr [ESI + this->_padding_*0x4 + 0x88],0x4
//                               LAB_0046f9d4                                                 XREF[7]:     0046f94c(j), 0046f968(j),
//                                                                                                         0046f96d(j), 0046f98e(j),
//                                                                                                         0046f9a1(j), 0046f9b6(j),
//                                                                                                         0046f9c7(j)
//                              player.cpp:938 (16)
//         0046f9d4     MOV        EBX,dword ptr [ESP + param_2]
//         0046f9d8     INC        EDI
//         0046f9d9     CMP        DI,word ptr [ESP + has_team+0x2]
//         0046f9de     JL         LAB_0046f936
//                               LAB_0046f9e4                                                 XREF[1]:     0046f930(j)
//                              player.cpp:965 (17)
//         0046f9e4     FLD        float ptr [ESP + param_3]
//         0046f9e8     FCOMP      double ptr [DAT_00570ea8]                        = 48h    H
//         0046f9ee     FNSTSW     AX
//         0046f9f0     TEST       AH,0x1
//         0046f9f3     JNZ        LAB_0046fa07
//                              player.cpp:966 (18)
//         0046f9f5     LEA        EAX,[ESI + 0x88]
//         0046f9fb     PUSH       0x24
//         0046f9fd     PUSH       EAX
//         0046f9fe     PUSH       EBP
//         0046f9ff     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046fa04     ADD        ESP,0xc
//                               LAB_0046fa07                                                 XREF[1]:     0046f9f3(j)
//                              player.cpp:968 (7)
//         0046fa07     MOV        EDI,dword ptr [ESI + 0x34]
//         0046fa0a     TEST       EDI,EDI
//         0046fa0c     JZ         LAB_0046fa1e
//                              player.cpp:969 (16)
//         0046fa0e     MOV        this,EDI
//         0046fa10     CALL       RGE_Victory_Conditions::~RGE_Victory_Conditions  void ~RGE_Victory_Conditions(RGE_Victory_Cond
//         0046fa15     PUSH       EDI
//         0046fa16     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0046fa1b     ADD        ESP,0x4
//                               LAB_0046fa1e                                                 XREF[1]:     0046fa0c(j)
//                              player.cpp:971 (17)
//         0046fa1e     FLD        float ptr [ESP + param_3]
//         0046fa22     FCOMP      double ptr [DAT_00570eb8]                        = 71h    q
//         0046fa28     FNSTSW     AX
//         0046fa2a     TEST       AH,0x1
//         0046fa2d     JNZ        LAB_0046fa47
//                              player.cpp:972 (14)
//         0046fa2f     MOV        EDX,dword ptr [ESI]
//         0046fa31     PUSH       0x1
//         0046fa33     PUSH       EBX
//         0046fa34     PUSH       EBP
//         0046fa35     MOV        this,ESI
//         0046fa37     CALL       dword ptr [EDX + 0xf0]
//                              player.cpp:1016 (10)
//         0046fa3d     POP        EDI
//         0046fa3e     POP        ESI
//         0046fa3f     POP        EBP
//         0046fa40     POP        EBX
//         0046fa41     ADD        ESP,0xc
//         0046fa44     RET        0xc
//                               LAB_0046fa47                                                 XREF[1]:     0046fa2d(j)
//                              player.cpp:975 (14)
//         0046fa47     MOV        EAX,dword ptr [ESI]
//         0046fa49     PUSH       0x0
//         0046fa4b     PUSH       EBX
//         0046fa4c     PUSH       EBP
//         0046fa4d     MOV        this,ESI
//         0046fa4f     CALL       dword ptr [EAX + 0xf0]
//                              player.cpp:1016 (10)
//         0046fa55     POP        EDI
//         0046fa56     POP        ESI
//         0046fa57     POP        EBP
//         0046fa58     POP        EBX
//         0046fa59     ADD        ESP,0xc
//         0046fa5c     RET        0xc
//         0046fa5f     ??         90h
    return;
}

void RGE_Player::load(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0046fa77(R), 0046facf(*), 0046fadf(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[10]:    0046fb14(W), 0046fb33(W), 0046fb48(W), 0046fb61(W),
//                                                                                     0046fb79(W), 0046fb91(W), 0046fbb1(W), 0046fbc8(W),
//                                                                                     0046fbdd(W), 0046fbfa(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046fc26(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[5]:     0046fb0e(W), 0046fb42(W), 0046fb73(W), 0046fbab(W),
//                                                                                     0046fbd7(W)
//                               ?load@RGE_Player@@UAEXH@Z                                    XREF[1]:     00570f44(*)
//                               RGE_Player::load
//                              player.cpp:1020 (23)
//         0046fa60     PUSH       -0x1
//         0046fa62     PUSH       FUN_0055e307
//         0046fa67     MOV        EAX,FS:[0x0]
//         0046fa6d     PUSH       EAX
//         0046fa6e     MOV        dword ptr FS:[0x0],ESP
//         0046fa75     PUSH       this
//         0046fa76     PUSH       EBX
//                              player.cpp:1024 (21)
//         0046fa77     MOV        EBX,dword ptr [ESP + param_1]
//         0046fa7b     PUSH       EBP
//         0046fa7c     PUSH       ESI
//         0046fa7d     MOV        ESI,this
//         0046fa7f     PUSH       EDI
//         0046fa80     PUSH       0x2
//         0046fa82     LEA        EBP,[ESI + 0x22]
//         0046fa85     PUSH       EBP
//         0046fa86     PUSH       EBX
//         0046fa87     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:1025 (14)
//         0046fa8c     MOV        AX,word ptr [EBP]
//         0046fa90     XOR        EDI,EDI
//         0046fa92     ADD        ESP,0xc
//         0046fa95     CMP        AX,DI
//         0046fa98     JLE        LAB_0046fb01
//                              player.cpp:1027 (11)
//         0046fa9a     MOVSX      EAX,AX
//         0046fa9d     PUSH       0x4
//         0046fa9f     PUSH       EAX
//         0046faa0     CALL       calloc                                           undefined calloc()
//                              player.cpp:1028 (24)
//         0046faa5     MOVSX      this,word ptr [EBP]
//         0046faa9     ADD        ESP,0x8
//         0046faac     MOV        dword ptr [ESI + 0x24],EAX
//         0046faaf     SHL        this,0x2
//         0046fab2     PUSH       this
//         0046fab3     PUSH       EAX
//         0046fab4     PUSH       EBX
//         0046fab5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0046faba     ADD        ESP,0xc
//                              player.cpp:1029 (6)
//         0046fabd     CMP        word ptr [EBP],DI
//         0046fac1     JLE        LAB_0046fb04
//                               LAB_0046fac3                                                 XREF[1]:     0046fafd(j)
//                              player.cpp:1030 (12)
//         0046fac3     MOV        EAX,dword ptr [ESI + 0x24]
//         0046fac6     MOVSX      EDX,DI
//         0046fac9     CMP        dword ptr [EAX + EDX*0x4],0x0
//         0046facd     JZ         LAB_0046faf8
//                              player.cpp:1032 (13)
//         0046facf     LEA        this=>param_1,[ESP + 0x24]
//         0046fad3     PUSH       0x1
//         0046fad5     PUSH       this
//         0046fad6     PUSH       EBX
//         0046fad7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              player.cpp:1033 (35)
//         0046fadc     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046fadf     MOV        this,dword ptr [ESP + param_1]
//         0046fae3     ADD        ESP,0xc
//         0046fae6     MOV        EDX,dword ptr [EAX + 0x30]
//         0046fae9     MOV        EAX,dword ptr [EAX + 0x38]
//         0046faec     PUSH       EDX
//         0046faed     PUSH       EAX
//         0046faee     PUSH       this
//         0046faef     PUSH       EDI
//         0046faf0     PUSH       EBX
//         0046faf1     MOV        this,ESI
//         0046faf3     CALL       RGE_Player::load_master_object                   void load_master_object(RGE_Player * this, in
//                               LAB_0046faf8                                                 XREF[1]:     0046facd(j)
//         0046faf8     INC        EDI
//         0046faf9     CMP        DI,word ptr [EBP]
//         0046fafd     JL         LAB_0046fac3
//                              player.cpp:1036 (2)
//         0046faff     JMP        LAB_0046fb04
//                               LAB_0046fb01                                                 XREF[1]:     0046fa98(j)
//                              player.cpp:1037 (3)
//         0046fb01     MOV        dword ptr [ESI + 0x24],EDI
//                               LAB_0046fb04                                                 XREF[2]:     0046fac1(j), 0046faff(j)
//                              player.cpp:1039 (45)
//         0046fb04     PUSH       0x38
//         0046fb06     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fb0b     ADD        ESP,0x4
//         0046fb0e     MOV        dword ptr [ESP + local_10],EAX
//         0046fb12     TEST       EAX,EAX
//         0046fb14     MOV        dword ptr [ESP + local_4],0x0
//         0046fb1c     JZ         LAB_0046fb2c
//         0046fb1e     MOV        EDX,dword ptr [ESI + 0x3c]
//         0046fb21     MOV        this,EAX
//         0046fb23     PUSH       EDX
//         0046fb24     PUSH       EBX
//         0046fb25     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         0046fb2a     JMP        LAB_0046fb2e
//                               LAB_0046fb2c                                                 XREF[1]:     0046fb1c(j)
//         0046fb2c     XOR        EAX,EAX
//                               LAB_0046fb2e                                                 XREF[1]:     0046fb2a(j)
//         0046fb2e     OR         EDI,0xffffffff
//                              player.cpp:1040 (46)
//         0046fb31     PUSH       0x14
//         0046fb33     MOV        dword ptr [ESP + local_4],EDI
//         0046fb37     MOV        dword ptr [ESI + 0x38],EAX
//         0046fb3a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fb3f     ADD        ESP,0x4
//         0046fb42     MOV        dword ptr [ESP + local_10],EAX
//         0046fb46     TEST       EAX,EAX
//         0046fb48     MOV        dword ptr [ESP + local_4],0x1
//         0046fb50     JZ         LAB_0046fb5d
//         0046fb52     PUSH       ESI
//         0046fb53     PUSH       EBX
//         0046fb54     MOV        this,EAX
//         0046fb56     CALL       Visible_Resource_Manager::Visible_Resource_Man   undefined Visible_Resource_Manager(Visible_Re
//         0046fb5b     JMP        LAB_0046fb5f
//                               LAB_0046fb5d                                                 XREF[1]:     0046fb50(j)
//         0046fb5d     XOR        EAX,EAX
//                               LAB_0046fb5f                                                 XREF[1]:     0046fb5b(j)
//                              player.cpp:1041 (47)
//         0046fb5f     PUSH       0xc
//         0046fb61     MOV        dword ptr [ESP + local_4],EDI
//         0046fb65     MOV        dword ptr [ESI + 0x110],EAX
//         0046fb6b     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fb70     ADD        ESP,0x4
//         0046fb73     MOV        dword ptr [ESP + local_10],EAX
//         0046fb77     TEST       EAX,EAX
//         0046fb79     MOV        dword ptr [ESP + local_4],0x2
//         0046fb81     JZ         LAB_0046fb8c
//         0046fb83     MOV        this,EAX
//         0046fb85     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046fb8a     JMP        LAB_0046fb8e
//                               LAB_0046fb8c                                                 XREF[1]:     0046fb81(j)
//         0046fb8c     XOR        EAX,EAX
//                               LAB_0046fb8e                                                 XREF[1]:     0046fb8a(j)
//                              player.cpp:1042 (19)
//         0046fb8e     MOV        this,dword ptr [ESI + 0x3c]
//         0046fb91     MOV        dword ptr [ESP + local_4],EDI
//         0046fb95     PUSH       this
//         0046fb96     PUSH       EBX
//         0046fb97     MOV        this,EAX
//         0046fb99     MOV        dword ptr [ESI + 0x28],EAX
//         0046fb9c     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                              player.cpp:1043 (37)
//         0046fba1     PUSH       0xc
//         0046fba3     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fba8     ADD        ESP,0x4
//         0046fbab     MOV        dword ptr [ESP + local_10],EAX
//         0046fbaf     TEST       EAX,EAX
//         0046fbb1     MOV        dword ptr [ESP + local_4],0x3
//         0046fbb9     JZ         LAB_0046fbc4
//         0046fbbb     MOV        this,EAX
//         0046fbbd     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046fbc2     JMP        LAB_0046fbc6
//                               LAB_0046fbc4                                                 XREF[1]:     0046fbb9(j)
//         0046fbc4     XOR        EAX,EAX
//                               LAB_0046fbc6                                                 XREF[1]:     0046fbc2(j)
//                              player.cpp:1044 (44)
//         0046fbc6     PUSH       0xc
//         0046fbc8     MOV        dword ptr [ESP + local_4],EDI
//         0046fbcc     MOV        dword ptr [ESI + 0x2c],EAX
//         0046fbcf     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fbd4     ADD        ESP,0x4
//         0046fbd7     MOV        dword ptr [ESP + local_10],EAX
//         0046fbdb     TEST       EAX,EAX
//         0046fbdd     MOV        dword ptr [ESP + local_4],0x4
//         0046fbe5     JZ         LAB_0046fbf0
//         0046fbe7     MOV        this,EAX
//         0046fbe9     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
//         0046fbee     JMP        LAB_0046fbf2
//                               LAB_0046fbf0                                                 XREF[1]:     0046fbe5(j)
//         0046fbf0     XOR        EAX,EAX
//                               LAB_0046fbf2                                                 XREF[1]:     0046fbee(j)
//                              player.cpp:1045 (20)
//         0046fbf2     MOV        EDX,dword ptr [ESI + 0x3c]
//         0046fbf5     MOV        this,dword ptr [ESI + 0x2c]
//         0046fbf8     PUSH       EDX
//         0046fbf9     PUSH       EBX
//         0046fbfa     MOV        dword ptr [ESP + local_4],EDI
//         0046fbfe     MOV        dword ptr [ESI + 0x30],EAX
//         0046fc01     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                              player.cpp:1047 (19)
//         0046fc06     FLD        float ptr [save_game_version]                    = 7.23
//         0046fc0c     FCOMP      float ptr [DAT_00570ec0]                         = 48h    H
//         0046fc12     FNSTSW     AX
//         0046fc14     TEST       AH,0x1
//         0046fc17     JNZ        LAB_0046fc26
//                              player.cpp:1048 (13)
//         0046fc19     MOV        EAX,dword ptr [ESI + 0x3c]
//         0046fc1c     MOV        this,dword ptr [ESI + 0x30]
//         0046fc1f     PUSH       EAX
//         0046fc20     PUSH       EBX
//         0046fc21     CALL       RGE_Object_List::load_list                       void load_list(RGE_Object_List * this, int pa
//                               LAB_0046fc26                                                 XREF[1]:     0046fc17(j)
//                              player.cpp:1072 (21)
//         0046fc26     MOV        this,dword ptr [ESP + local_c]
//         0046fc2a     POP        EDI
//         0046fc2b     POP        ESI
//         0046fc2c     POP        EBP
//         0046fc2d     MOV        dword ptr FS:[0x0],this
//         0046fc34     POP        EBX
//         0046fc35     ADD        ESP,0x10
//         0046fc38     RET        0x4
//         0046fc3b     ??         90h
//         0046fc3c     NOP
//         0046fc3d     NOP
//         0046fc3e     NOP
//         0046fc3f     NOP
    return;
}

void RGE_Player::load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5) {
    /* TODO: Stub */
//                              void __thiscall load_master_object(RGE_Player * this, int param_1, s
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[7]:     0046fca8(R), 0046fce6(R), 0046fd3c(R), 0046fd7a(R),
//                                                                                     0046fdd0(R), 0046fe0a(R), 0046fe7b(R)
//              short             Stack[0x8]:2   param_2                   XREF[5]:     0046fcf3(R), 0046fd87(R), 0046fe17(R), 0046fe34(R),
//                                                                                     0046fe8c(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[8]:     0046fc4e(R), 0046fc89(W), 0046fcc7(W), 0046fd1d(W),
//                                                                                     0046fd5b(W), 0046fdb1(W), 0046fdef(W), 0046fe60(W)
//              RGE_Sprite * *    Stack[0x10]:4  param_4                   XREF[7]:     0046fca1(R), 0046fcdf(R), 0046fd35(R), 0046fd73(R),
//                                                                                     0046fdc9(R), 0046fe03(R), 0046fe74(R)
//              RGE_Sound * *     Stack[0x14]:4  param_5                   XREF[7]:     0046fc9d(R), 0046fcdb(R), 0046fd31(R), 0046fd6f(R),
//                                                                                     0046fdc5(R), 0046fdff(R), 0046fe70(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0046fc8f(W), 0046fccd(W), 0046fd23(W), 0046fd61(W),
//                                                                                     0046fdb7(W), 0046fdf5(W), 0046fe66(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0046fcfe(R), 0046fd92(R), 0046fe22(R), 0046fe41(R),
//                                                                                     0046fe97(R)
//                               ?load_master_object@RGE_Player@@QAEXHFEPAPAVRGE_Sprite@@PAP  XREF[2]:     load:0046faf3(c),
//                               RGE_Player::load_master_object                                            load_master_object:00512ad3(c)
//                              player.cpp:1077 (14)
//         0046fc40     MOV        EAX,FS:[0x0]
//         0046fc46     PUSH       -0x1
//         0046fc48     PUSH       FUN_0055e36d
//         0046fc4d     PUSH       EAX
//                              player.cpp:1078 (46)
//         0046fc4e     MOV        EAX,dword ptr [ESP + param_3]
//         0046fc52     MOV        dword ptr FS:[0x0],ESP
//         0046fc59     AND        EAX,0xff
//         0046fc5e     PUSH       ESI
//         0046fc5f     ADD        EAX,-0xa
//         0046fc62     MOV        ESI,this
//         0046fc64     CMP        EAX,0x32
//         0046fc67     JA         switchD_0046fc75::caseD_b
//         0046fc6d     XOR        this,this
//         0046fc6f     MOV        this,byte ptr [EAX + 0x46fecc]=>PTR_caseD_32_0
//                               switchD_0046fc75::switchD
//         0046fc75     JMP        dword ptr [this->_padding_*0x4 + switchD_0046f   = 0046fc7c
//                               switchD_0046fc75::caseD_a                                    XREF[2]:     0046fc75(j), 0046feac(*)
//                              player.cpp:1081 (57)
//         0046fc7c     PUSH       0xb8
//         0046fc81     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fc86     ADD        ESP,0x4
//         0046fc89     MOV        dword ptr [ESP + param_3],EAX
//         0046fc8d     TEST       EAX,EAX
//         0046fc8f     MOV        dword ptr [ESP + local_4],0x0
//         0046fc97     JZ         LAB_0046fe8a
//         0046fc9d     MOV        EDX,dword ptr [ESP + param_5]
//         0046fca1     MOV        this,dword ptr [ESP + param_4]
//         0046fca5     PUSH       0x1
//         0046fca7     PUSH       EDX
//         0046fca8     MOV        EDX,dword ptr [ESP + param_1]
//         0046fcac     PUSH       this
//         0046fcad     PUSH       EDX
//         0046fcae     MOV        this,EAX
//         0046fcb0     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
//                              player.cpp:1082 (5)
//         0046fcb5     JMP        LAB_0046fe8c
//                               switchD_0046fc75::caseD_14                                   XREF[2]:     0046fc75(j), 0046feb0(*)
//                              player.cpp:1084 (57)
//         0046fcba     PUSH       0xbc
//         0046fcbf     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fcc4     ADD        ESP,0x4
//         0046fcc7     MOV        dword ptr [ESP + param_3],EAX
//         0046fccb     TEST       EAX,EAX
//         0046fccd     MOV        dword ptr [ESP + local_4],0x1
//         0046fcd5     JZ         LAB_0046fe34
//         0046fcdb     MOV        this,dword ptr [ESP + param_5]
//         0046fcdf     MOV        EDX,dword ptr [ESP + param_4]
//         0046fce3     PUSH       0x1
//         0046fce5     PUSH       this
//         0046fce6     MOV        this,dword ptr [ESP + param_1]
//         0046fcea     PUSH       EDX
//         0046fceb     PUSH       this
//         0046fcec     MOV        this,EAX
//         0046fcee     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
//                              player.cpp:1096 (11)
//         0046fcf3     MOVSX      EDX,word ptr [ESP + param_2]
//         0046fcf8     MOV        this,dword ptr [ESI + 0x24]
//         0046fcfb     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              player.cpp:1106 (18)
//         0046fcfe     MOV        this,dword ptr [ESP + local_c]
//         0046fd02     MOV        dword ptr FS:[0x0],this
//         0046fd09     POP        ESI
//         0046fd0a     ADD        ESP,0xc
//         0046fd0d     RET        0x14
//                               switchD_0046fc75::caseD_1e                                   XREF[2]:     0046fc75(j), 0046feb8(*)
//                              player.cpp:1087 (62)
//         0046fd10     PUSH       0xd8
//         0046fd15     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fd1a     ADD        ESP,0x4
//         0046fd1d     MOV        dword ptr [ESP + param_3],EAX
//         0046fd21     TEST       EAX,EAX
//         0046fd23     MOV        dword ptr [ESP + local_4],0x2
//         0046fd2b     JZ         LAB_0046fe8a
//         0046fd31     MOV        EDX,dword ptr [ESP + param_5]
//         0046fd35     MOV        this,dword ptr [ESP + param_4]
//         0046fd39     PUSH       0x1
//         0046fd3b     PUSH       EDX
//         0046fd3c     MOV        EDX,dword ptr [ESP + param_1]
//         0046fd40     PUSH       this
//         0046fd41     PUSH       EDX
//         0046fd42     MOV        this,EAX
//         0046fd44     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
//         0046fd49     JMP        LAB_0046fe8c
//                               switchD_0046fc75::caseD_3c                                   XREF[2]:     0046fc75(j), 0046fec4(*)
//                              player.cpp:1090 (57)
//         0046fd4e     PUSH       0x154
//         0046fd53     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fd58     ADD        ESP,0x4
//         0046fd5b     MOV        dword ptr [ESP + param_3],EAX
//         0046fd5f     TEST       EAX,EAX
//         0046fd61     MOV        dword ptr [ESP + local_4],0x3
//         0046fd69     JZ         LAB_0046fe34
//         0046fd6f     MOV        this,dword ptr [ESP + param_5]
//         0046fd73     MOV        EDX,dword ptr [ESP + param_4]
//         0046fd77     PUSH       0x1
//         0046fd79     PUSH       this
//         0046fd7a     MOV        this,dword ptr [ESP + param_1]
//         0046fd7e     PUSH       EDX
//         0046fd7f     PUSH       this
//         0046fd80     MOV        this,EAX
//         0046fd82     CALL       RGE_Master_Missile_Object::RGE_Master_Missile_   undefined RGE_Master_Missile_Object(RGE_Maste
//                              player.cpp:1096 (11)
//         0046fd87     MOVSX      EDX,word ptr [ESP + param_2]
//         0046fd8c     MOV        this,dword ptr [ESI + 0x24]
//         0046fd8f     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              player.cpp:1106 (18)
//         0046fd92     MOV        this,dword ptr [ESP + local_c]
//         0046fd96     MOV        dword ptr FS:[0x0],this
//         0046fd9d     POP        ESI
//         0046fd9e     ADD        ESP,0xc
//         0046fda1     RET        0x14
//                               switchD_0046fc75::caseD_28                                   XREF[2]:     0046fc75(j), 0046febc(*)
//                              player.cpp:1093 (62)
//         0046fda4     PUSH       0xfc
//         0046fda9     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fdae     ADD        ESP,0x4
//         0046fdb1     MOV        dword ptr [ESP + param_3],EAX
//         0046fdb5     TEST       EAX,EAX
//         0046fdb7     MOV        dword ptr [ESP + local_4],0x4
//         0046fdbf     JZ         LAB_0046fe8a
//         0046fdc5     MOV        EDX,dword ptr [ESP + param_5]
//         0046fdc9     MOV        this,dword ptr [ESP + param_4]
//         0046fdcd     PUSH       0x1
//         0046fdcf     PUSH       EDX
//         0046fdd0     MOV        EDX,dword ptr [ESP + param_1]
//         0046fdd4     PUSH       this
//         0046fdd5     PUSH       EDX
//         0046fdd6     MOV        this,EAX
//         0046fdd8     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
//         0046fddd     JMP        LAB_0046fe8c
//                               switchD_0046fc75::caseD_32                                   XREF[2]:     0046fc75(j), 0046fec0(*)
//                              player.cpp:1096 (64)
//         0046fde2     PUSH       0x148
//         0046fde7     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fdec     ADD        ESP,0x4
//         0046fdef     MOV        dword ptr [ESP + param_3],EAX
//         0046fdf3     TEST       EAX,EAX
//         0046fdf5     MOV        dword ptr [ESP + local_4],0x5
//         0046fdfd     JZ         LAB_0046fe34
//         0046fdff     MOV        this,dword ptr [ESP + param_5]
//         0046fe03     MOV        EDX,dword ptr [ESP + param_4]
//         0046fe07     PUSH       0x1
//         0046fe09     PUSH       this
//         0046fe0a     MOV        this,dword ptr [ESP + param_1]
//         0046fe0e     PUSH       EDX
//         0046fe0f     PUSH       this
//         0046fe10     MOV        this,EAX
//         0046fe12     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
//         0046fe17     MOVSX      EDX,word ptr [ESP + param_2]
//         0046fe1c     MOV        this,dword ptr [ESI + 0x24]
//         0046fe1f     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              player.cpp:1106 (18)
//         0046fe22     MOV        this,dword ptr [ESP + local_c]
//         0046fe26     MOV        dword ptr FS:[0x0],this
//         0046fe2d     POP        ESI
//         0046fe2e     ADD        ESP,0xc
//         0046fe31     RET        0x14
//                               LAB_0046fe34                                                 XREF[3]:     0046fcd5(j), 0046fd69(j),
//                                                                                                         0046fdfd(j)
//                              player.cpp:1096 (13)
//         0046fe34     MOVSX      EDX,word ptr [ESP + param_2]
//         0046fe39     MOV        this,dword ptr [ESI + 0x24]
//         0046fe3c     XOR        EAX,EAX
//         0046fe3e     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
//                              player.cpp:1106 (18)
//         0046fe41     MOV        this,dword ptr [ESP + local_c]
//         0046fe45     MOV        dword ptr FS:[0x0],this
//         0046fe4c     POP        ESI
//         0046fe4d     ADD        ESP,0xc
//         0046fe50     RET        0x14
//                               switchD_0046fc75::caseD_19                                   XREF[2]:     0046fc75(j), 0046feb4(*)
//                              player.cpp:1099 (68)
//         0046fe53     PUSH       0xbc
//         0046fe58     CALL       operator_new                                     void * operator_new(uint param_1)
//         0046fe5d     ADD        ESP,0x4
//         0046fe60     MOV        dword ptr [ESP + param_3],EAX
//         0046fe64     TEST       EAX,EAX
//         0046fe66     MOV        dword ptr [ESP + local_4],0x6
//         0046fe6e     JZ         LAB_0046fe8a
//         0046fe70     MOV        EDX,dword ptr [ESP + param_5]
//         0046fe74     MOV        this,dword ptr [ESP + param_4]
//         0046fe78     PUSH       0x1
//         0046fe7a     PUSH       EDX
//         0046fe7b     MOV        EDX,dword ptr [ESP + param_1]
//         0046fe7f     PUSH       this
//         0046fe80     PUSH       EDX
//         0046fe81     MOV        this,EAX
//         0046fe83     CALL       RGE_Master_Doppleganger_Object::RGE_Master_Dop   undefined RGE_Master_Doppleganger_Object(RGE_
//         0046fe88     JMP        LAB_0046fe8c
//                               LAB_0046fe8a                                                 XREF[4]:     0046fc97(j), 0046fd2b(j),
//                                                                                                         0046fdbf(j), 0046fe6e(j)
//         0046fe8a     XOR        EAX,EAX
//                               LAB_0046fe8c                                                 XREF[4]:     0046fcb5(j), 0046fd49(j),
//                                                                                                         0046fddd(j), 0046fe88(j)
//         0046fe8c     MOVSX      this,word ptr [ESP + param_2]
//         0046fe91     MOV        EDX,dword ptr [ESI + 0x24]
//         0046fe94     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
//                               switchD_0046fc75::caseD_c                                    XREF[3]:     0046fc67(j), 0046fc75(j),
//                               switchD_0046fc75::caseD_d                                                 0046fec8(*)
//                               switchD_0046fc75::caseD_e
//                               switchD_0046fc75::caseD_f
//                               switchD_0046fc75::caseD_10
//                               switchD_0046fc75::caseD_11
//                               switchD_0046fc75::caseD_12
//                               switchD_0046fc75::caseD_13
//                               switchD_0046fc75::caseD_15
//                               switchD_0046fc75::caseD_16
//                               switchD_0046fc75::caseD_17
//                               switchD_0046fc75::caseD_18
//                               switchD_0046fc75::caseD_1a
//                               switchD_0046fc75::caseD_1b
//                               switchD_0046fc75::caseD_1c
//                               switchD_0046fc75::caseD_1d
//                               switchD_0046fc75::caseD_1f
//                               switchD_0046fc75::caseD_20
//                               switchD_0046fc75::caseD_21
//                               switchD_0046fc75::caseD_22
//                               switchD_0046fc75::caseD_23
//                               switchD_0046fc75::caseD_24
//                               switchD_0046fc75::caseD_25
//                               switchD_0046fc75::caseD_26
//                               switchD_0046fc75::caseD_27
//                               switchD_0046fc75::caseD_29
//                               switchD_0046fc75::caseD_2a
//                               switchD_0046fc75::caseD_2b
//                               switchD_0046fc75::caseD_2c
//                               switchD_0046fc75::caseD_2d
//                               switchD_0046fc75::caseD_2e
//                               switchD_0046fc75::caseD_2f
//                               switchD_0046fc75::caseD_30
//                               switchD_0046fc75::caseD_31
//                               switchD_0046fc75::caseD_33
//                               switchD_0046fc75::caseD_34
//                               switchD_0046fc75::caseD_35
//                               switchD_0046fc75::caseD_36
//                               switchD_0046fc75::caseD_37
//                               switchD_0046fc75::caseD_38
//                               switchD_0046fc75::caseD_39
//                               switchD_0046fc75::caseD_3a
//                               switchD_0046fc75::caseD_3b
//                               switchD_0046fc75::caseD_b
//                              player.cpp:1106 (104)
//         0046fe97     MOV        this,dword ptr [ESP + local_c]
//         0046fe9b     POP        ESI
//         0046fe9c     MOV        dword ptr FS:[0x0],this
//         0046fea3     ADD        ESP,0xc
//         0046fea6     RET        0x14
    return;
}

void RGE_Player::load_info(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load_info(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ff03(R)
//                               ?load_info@RGE_Player@@QAEXH@Z                               XREF[1]:     load_world:005422cc(c)
//                               RGE_Player::load_info
//                              player.cpp:1111 (3)
//         0046ff00     PUSH       ESI
//         0046ff01     MOV        ESI,this
//                              player.cpp:1113 (19)
//         0046ff03     MOV        this,dword ptr [ESP + param_1]
//         0046ff07     PUSH       0x1
//         0046ff09     MOV        EAX,dword ptr [ESI]
//         0046ff0b     PUSH       0x0
//         0046ff0d     PUSH       this
//         0046ff0e     MOV        this,ESI
//         0046ff10     CALL       dword ptr [EAX + 0xf0]
//                              player.cpp:1114 (8)
//         0046ff16     MOV        this,dword ptr [ESI + 0x28]
//         0046ff19     CALL       RGE_Object_List::rehook_list                     void rehook_list(RGE_Object_List * this)
//                              player.cpp:1115 (8)
//         0046ff1e     MOV        this,dword ptr [ESI + 0x2c]
//         0046ff21     CALL       RGE_Object_List::rehook_list                     void rehook_list(RGE_Object_List * this)
//                              player.cpp:1116 (8)
//         0046ff26     MOV        this,dword ptr [ESI + 0x30]
//         0046ff29     CALL       RGE_Object_List::rehook_list                     void rehook_list(RGE_Object_List * this)
//                              player.cpp:1117 (4)
//         0046ff2e     POP        ESI
//         0046ff2f     RET        0x4
//         0046ff32     ??         90h
//         0046ff33     NOP
//         0046ff34     NOP
//         0046ff35     NOP
//         0046ff36     NOP
//         0046ff37     NOP
//         0046ff38     NOP
//         0046ff39     NOP
//         0046ff3a     NOP
//         0046ff3b     NOP
//         0046ff3c     NOP
//         0046ff3d     NOP
//         0046ff3e     NOP
//         0046ff3f     NOP
    return;
}

long RGE_Player::get_checksum() {
    /* TODO: Stub */
//                              long __thiscall get_checksum(RGE_Player * this)
//              long              EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?get_checksum@RGE_Player@@QAEJXZ                             XREF[3]:     GetChecksum:0042293c(c),
//                               RGE_Player::get_checksum                                                  GetChecksum:00422952(c),
//                                                                                                         GetWorldChecksum:00422a2f(c)
//                              player.cpp:1122 (3)
//         0046ff40     PUSH       ESI
//         0046ff41     MOV        ESI,this
//                              player.cpp:1123 (7)
//         0046ff43     MOV        AL,byte ptr [ESI + 0x20]
//         0046ff46     TEST       AL,AL
//         0046ff48     JNZ        LAB_0046ff4f
//                              player.cpp:1124 (5)
//         0046ff4a     CALL       RGE_Player::create_checksum                      long create_checksum(RGE_Player * this)
//                               LAB_0046ff4f                                                 XREF[1]:     0046ff48(j)
//                              player.cpp:1125 (3)
//         0046ff4f     MOV        EAX,dword ptr [ESI + 0x14]
//                              player.cpp:1126 (2)
//         0046ff52     POP        ESI
//         0046ff53     RET
//         0046ff54     ??         90h
//         0046ff55     NOP
//         0046ff56     NOP
//         0046ff57     NOP
//         0046ff58     NOP
//         0046ff59     NOP
//         0046ff5a     NOP
//         0046ff5b     NOP
//         0046ff5c     NOP
//         0046ff5d     NOP
//         0046ff5e     NOP
//         0046ff5f     NOP
    return 0;
}

uchar RGE_Player::get_checksums(long* param_1, long* param_2, long* param_3) {
    /* TODO: Stub */
//                              uchar __thiscall get_checksums(RGE_Player * this, long * param_1, lo
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     0046ff6f(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     0046ff78(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     0046ff81(R)
//                               ?get_checksums@RGE_Player@@QAEEAAJ00@Z                       XREF[1]:     GetWorldChecksums:004229b1(c)
//                               RGE_Player::get_checksums
//                              player.cpp:1131 (3)
//         0046ff60     PUSH       ESI
//         0046ff61     MOV        ESI,this
//                              player.cpp:1132 (7)
//         0046ff63     MOV        AL,byte ptr [ESI + 0x20]
//         0046ff66     TEST       AL,AL
//         0046ff68     JNZ        LAB_0046ff6f
//                              player.cpp:1133 (5)
//         0046ff6a     CALL       RGE_Player::create_checksum                      long create_checksum(RGE_Player * this)
//                               LAB_0046ff6f                                                 XREF[1]:     0046ff68(j)
//                              player.cpp:1135 (9)
//         0046ff6f     MOV        this,dword ptr [ESP + param_1]
//         0046ff73     MOV        EAX,dword ptr [ESI + 0x14]
//         0046ff76     MOV        dword ptr [this->_padding_],EAX
//                              player.cpp:1136 (9)
//         0046ff78     MOV        EAX,dword ptr [ESP + param_2]
//         0046ff7c     MOV        EDX,dword ptr [ESI + 0x18]
//         0046ff7f     MOV        dword ptr [EAX],EDX
//                              player.cpp:1137 (7)
//         0046ff81     MOV        EDX,dword ptr [ESP + param_3]
//         0046ff85     MOV        this,dword ptr [ESI + 0x1c]
//                              player.cpp:1138 (4)
//         0046ff88     MOV        AL,0x1
//         0046ff8a     MOV        dword ptr [EDX],this
//                              player.cpp:1139 (4)
//         0046ff8c     POP        ESI
//         0046ff8d     RET        0xc
    return 0;
}

long RGE_Player::create_checksum() {
    /* TODO: Stub */
//                              long __thiscall create_checksum(RGE_Player * this)
//              long              EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0046ffd0(W)
//              long              Stack[-0x8]:4  num4                      XREF[2]:     0046ffc4(W), 0047001c(R)
//              long              Stack[-0xc]:4  num2                      XREF[3]:     0046ffd9(W), 0046ffed(R), 0046fff6(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0046ffcc(W), 00470082(R)
//              float             Stack[-0x14]:4 temp_position_checksum    XREF[4]:     0046ffc0(W), 0046ffe4(R), 0046fff2(W), 00470079(R)
//              long              Stack[-0x18]:4 num1                      XREF[2]:     0046ffc8(W), 00470075(R)
//              long              Stack[-0x1c]:4 num3
//                               ?create_checksum@RGE_Player@@QAEJXZ                          XREF[2]:     get_checksum:0046ff4a(c),
//                               RGE_Player::create_checksum                                               get_checksums:0046ff6a(c)
//                              player.cpp:1144 (6)
//         0046ff90     SUB        ESP,0x18
//         0046ff93     PUSH       EBX
//         0046ff94     MOV        EBX,this
//                              player.cpp:1149 (3)
//         0046ff96     XOR        this,this
//         0046ff98     PUSH       EBP
//                              player.cpp:1161 (31)
//         0046ff99     MOV        EAX,dword ptr [EBX + 0x2c]
//         0046ff9c     PUSH       ESI
//         0046ff9d     MOVSX      ESI,word ptr [EBX + 0x4a]
//         0046ffa1     MOV        byte ptr [EBX + 0x20],0x1
//         0046ffa5     MOV        dword ptr [EBX + 0x1c],this
//         0046ffa8     MOVSX      EDX,word ptr [EAX + 0x8]
//         0046ffac     MOV        EAX,dword ptr [EBX + 0x30]
//         0046ffaf     ADD        ESI,EDX
//         0046ffb1     XOR        EBP,EBP
//         0046ffb3     PUSH       EDI
//         0046ffb4     MOVSX      EDX,word ptr [EAX + 0x8]
//                              player.cpp:1165 (37)
//         0046ffb8     MOVSX      EAX,word ptr [EBX + 0x4c]
//         0046ffbc     ADD        ESI,EDX
//         0046ffbe     CMP        EAX,this
//         0046ffc0     MOV        dword ptr [ESP + temp_position_checksum],this
//         0046ffc4     MOV        dword ptr [ESP + num4],EBP
//         0046ffc8     MOV        dword ptr [ESP + num1],this
//         0046ffcc     MOV        dword ptr [ESP + local_10],EBP
//         0046ffd0     MOV        dword ptr [ESP + local_4],ESI
//         0046ffd4     JLE        LAB_0046fffe
//         0046ffd6     MOV        EDI,dword ptr [EBX + 0x50]
//         0046ffd9     MOV        dword ptr [ESP + num2],EAX
//                               LAB_0046ffdd                                                 XREF[1]:     0046fffa(j)
//                              player.cpp:1166 (31)
//         0046ffdd     FLD        float ptr [EDI]
//         0046ffdf     CALL       __ftol                                           undefined __ftol()
//         0046ffe4     MOV        EDX,dword ptr [ESP + temp_position_checksum]
//         0046ffe8     ADD        EDI,0x4
//         0046ffeb     ADD        EDX,EAX
//         0046ffed     MOV        EAX,dword ptr [ESP + num2]
//         0046fff1     DEC        EAX
//         0046fff2     MOV        dword ptr [ESP + temp_position_checksum],EDX
//         0046fff6     MOV        dword ptr [ESP + num2],EAX
//         0046fffa     JNZ        LAB_0046ffdd
//                              player.cpp:1165 (2)
//         0046fffc     XOR        this,this
//                               LAB_0046fffe                                                 XREF[1]:     0046ffd4(j)
//                              player.cpp:1169 (10)
//         0046fffe     MOV        EAX,dword ptr [EBX + 0x28]
//         00470001     MOV        EDI,dword ptr [EAX + 0x4]
//         00470004     CMP        EDI,this
//         00470006     JZ         LAB_00470075
//                               LAB_00470008                                                 XREF[1]:     0047006f(j)
//                              player.cpp:1173 (30)
//         00470008     MOV        ESI,dword ptr [EDI]
//         0047000a     XOR        this,this
//         0047000c     MOV        this,byte ptr [ESI + 0x48]
//         0047000f     FLD        float ptr [ESI + 0x44]
//         00470012     MOV        EBP,this
//         00470014     CALL       __ftol                                           undefined __ftol()
//         00470019     MOV        EDX,dword ptr [ESI + 0x8]
//         0047001c     MOV        this,dword ptr [ESP + num4]
//         00470020     ADD        EBP,EAX
//         00470022     MOVSX      EAX,word ptr [EDX + 0x10]
//                              player.cpp:1174 (14)
//         00470026     MOV        EDX,dword ptr [ESI]
//         00470028     ADD        EAX,this
//         0047002a     MOV        this,ESI
//         0047002c     ADD        EBP,EAX
//         0047002e     CALL       dword ptr [EDX + 0x1d4]
//                              player.cpp:1177 (16)
//         00470034     MOV        this,dword ptr [EDI]
//         00470036     MOV        EDX,dword ptr [ESP + 0x10]
//         0047003a     ADD        EBP,EAX
//         0047003c     INC        EDX
//         0047003d     FLD        float ptr [ECX + this->visible]
//         00470040     FADD       float ptr [ESP + 0x18]
//                              player.cpp:1181 (45)
//         00470044     MOV        EAX,dword ptr [this->_padding_]
//         00470046     MOV        dword ptr [ESP + 0x20],EBP
//         0047004a     MOV        dword ptr [ESP + 0x10],EDX
//         0047004e     FADD       float ptr [ECX + this->world]
//         00470051     FLD        float ptr [ECX + this->doppleganger_creator]
//         00470054     FADD       ST0,ST1
//         00470056     FSTP       float ptr [ESP + 0x18]
//         0047005a     FSTP       ST0
//         0047005c     CALL       dword ptr [EAX + 0x1d0]
//         00470062     MOV        this,dword ptr [EBX + 0x1c]
//         00470065     ADD        this,EAX
//         00470067     MOV        dword ptr [EBX + 0x1c],this
//         0047006a     MOV        EDI,dword ptr [EDI + 0x4]
//         0047006d     TEST       EDI,EDI
//         0047006f     JNZ        LAB_00470008
//                              player.cpp:1169 (4)
//         00470071     MOV        ESI,dword ptr [ESP + 0x24]
//                               LAB_00470075                                                 XREF[1]:     00470006(j)
//                              player.cpp:1198 (13)
//         00470075     MOV        EDI,dword ptr [ESP + num1]
//         00470079     MOV        this,dword ptr [ESP + temp_position_checksum]
//         0047007d     SHL        ESI,0x8
//         00470080     ADD        ESI,EDI
//                              player.cpp:1199 (25)
//         00470082     FLD        float ptr [ESP + local_10]
//         00470086     SHL        ESI,0x8
//         00470089     ADD        ESI,EBP
//         0047008b     SHL        ESI,0x8
//         0047008e     ADD        ESI,this
//         00470090     MOV        dword ptr [EBX + 0x14],ESI
//         00470093     CALL       __ftol                                           undefined __ftol()
//         00470098     MOV        dword ptr [EBX + 0x18],EAX
//                              player.cpp:1201 (2)
//         0047009b     MOV        EAX,ESI
//                              player.cpp:1202 (8)
//         0047009d     POP        EDI
//         0047009e     POP        ESI
//         0047009f     POP        EBP
//         004700a0     POP        EBX
//         004700a1     ADD        ESP,0x18
//         004700a4     RET
//         004700a5     ??         90h
//         004700a6     NOP
//         004700a7     NOP
//         004700a8     NOP
//         004700a9     NOP
//         004700aa     NOP
//         004700ab     NOP
//         004700ac     NOP
//         004700ad     NOP
//         004700ae     NOP
//         004700af     NOP
    return 0;
}

void RGE_Player::new_attribute_num(short param_1, float param_2) {
    /* TODO: Stub */
//                              void __thiscall new_attribute_num(RGE_Player * this, short param_1,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     004700b0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004700c3(R)
//                               ?new_attribute_num@RGE_Player@@QAEXFM@Z                      XREF[15]:    do_effect:0044969b(c),
//                               RGE_Player::new_attribute_num                                             SaveAttributesIntoPlayers:0052badc
//                                                                                                         SaveAttributesIntoPlayers:0052bb00
//                                                                                                         SaveAttributesIntoPlayers:0052bb24
//                                                                                                         SaveAttributesIntoPlayers:0052bb48
//                                                                                                         new_game:0052ff8e(c),
//                                                                                                         new_game:0052ff9d(c),
//                                                                                                         new_game:0052ffaf(c),
//                                                                                                         new_game:0052ffbd(c),
//                                                                                                         new_game:0052fffd(c),
//                                                                                                         new_game:0053000c(c),
//                                                                                                         new_game:0053004d(c),
//                                                                                                         new_game:0053005c(c),
//                                                                                                         new_game:0053006e(c),
//                                                                                                         new_game:00530080(c)
//                              player.cpp:1207 (16)
//         004700b0     MOV        AX,word ptr [ESP + param_1]
//         004700b5     TEST       AX,AX
//         004700b8     JL         LAB_004700cd
//         004700ba     CMP        AX,word ptr [ECX + this->attribute_num]
//         004700be     JGE        LAB_004700cd
//                              player.cpp:1209 (13)
//         004700c0     MOV        this,dword ptr [ECX + this->attributes]
//         004700c3     FLD        float ptr [ESP + param_2]
//         004700c7     MOVSX      EAX,AX
//         004700ca     FSTP       float ptr [this->_padding_ + EAX*0x4]
//                               LAB_004700cd                                                 XREF[2]:     004700b8(j), 004700be(j)
//                              player.cpp:1210 (3)
//         004700cd     RET        0x8
    return;
}

void RGE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) {
    /* TODO: Stub */
//                              void __thiscall add_attribute_num(RGE_Player * this, short param_1,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     004700d0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004700e3(R)
//              uchar             Stack[0xc]:1   param_3
//                               ?add_attribute_num@RGE_Player@@UAEXFME@Z                     XREF[2]:     add_attribute_num:005195bb(c),
//                               RGE_Player::add_attribute_num                                             00570f48(*)
//                              player.cpp:1215 (16)
//         004700d0     MOV        AX,word ptr [ESP + param_1]
//         004700d5     TEST       AX,AX
//         004700d8     JL         LAB_004700f2
//         004700da     CMP        AX,word ptr [ECX + this->attribute_num]
//         004700de     JGE        LAB_004700f2
//                              player.cpp:1217 (18)
//         004700e0     MOV        this,dword ptr [ECX + this->attributes]
//         004700e3     FLD        float ptr [ESP + param_2]
//         004700e7     MOVSX      EAX,AX
//         004700ea     FADD       float ptr [this->_padding_ + EAX*0x4]
//         004700ed     LEA        EAX,[this->_padding_ + EAX*0x4]
//         004700f0     FSTP       float ptr [EAX]
//                               LAB_004700f2                                                 XREF[2]:     004700d8(j), 004700de(j)
//                              player.cpp:1218 (3)
//         004700f2     RET        0xc
//         004700f5     ??         90h
//         004700f6     NOP
//         004700f7     NOP
//         004700f8     NOP
//         004700f9     NOP
//         004700fa     NOP
//         004700fb     NOP
//         004700fc     NOP
//         004700fd     NOP
//         004700fe     NOP
//         004700ff     NOP
    return;
}

void RGE_Player::make_available(short param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall make_available(RGE_Player * this, short param_1, uch
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00470100(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0047010f(R)
//                               ?make_available@RGE_Player@@QAEXFE@Z                         XREF[1]:     do_effect:004496c4(c)
//                               RGE_Player::make_available
//                              player.cpp:1223 (15)
//         00470100     MOVSX      EAX,word ptr [ESP + param_1]
//         00470105     MOV        this,dword ptr [ECX + this->master_objects]
//         00470108     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
//         0047010b     TEST       this,this
//         0047010d     JZ         LAB_00470119
//                              player.cpp:1225 (10)
//         0047010f     MOV        EDX,dword ptr [ESP + param_2]
//         00470113     PUSH       EDX
//         00470114     CALL       RGE_Master_Static_Object::make_available         void make_available(RGE_Master_Static_Object
//                               LAB_00470119                                                 XREF[1]:     0047010d(j)
//                              player.cpp:1226 (3)
//         00470119     RET        0x8
//         0047011c     ??         90h
//         0047011d     NOP
//         0047011e     NOP
//         0047011f     NOP
    return;
}

void RGE_Player::update() {
    /* TODO: Stub */
//                              void __thiscall update(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?update@RGE_Player@@UAEXXZ                                   XREF[3]:     update:00512559(c),
//                               RGE_Player::update                                                        update:00519d01(c), 00570f4c(*)
//                              player.cpp:1231 (3)
//         00470120     PUSH       ESI
//         00470121     MOV        ESI,this
//                              player.cpp:1235 (10)
//         00470123     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00470129     TEST       this,this
//         0047012b     JZ         LAB_00470132
//                              player.cpp:1236 (5)
//         0047012d     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00470132                                                 XREF[1]:     0047012b(j)
//                              player.cpp:1242 (15)
//         00470132     MOV        this,dword ptr [ESI + 0x28]
//         00470135     MOV        dword ptr [ESI + 0x10],0x0
//         0047013c     CALL       RGE_Object_List::update                          void update(RGE_Object_List * this)
//                              player.cpp:1243 (7)
//         00470141     MOV        this,ESI
//         00470143     CALL       RGE_Player::update_selected                      void update_selected(RGE_Player * this)
//                              player.cpp:1244 (12)
//         00470148     MOV        this,dword ptr [ESI + 0x34]
//         0047014b     CALL       RGE_Victory_Conditions::update                   uchar update(RGE_Victory_Conditions * this)
//         00470150     CMP        AL,0x1
//         00470152     JNZ        LAB_0047015d
//                              player.cpp:1245 (9)
//         00470154     MOV        EAX,dword ptr [ESI]
//         00470156     PUSH       0x2
//         00470158     MOV        this,ESI
//         0047015a     CALL       dword ptr [EAX + 0x4]
//                               LAB_0047015d                                                 XREF[1]:     00470152(j)
//                              player.cpp:1251 (14)
//         0047015d     MOV        this,dword ptr [ESI + 0x110]
//         00470163     MOV        byte ptr [ESI + 0x20],0x0
//         00470167     TEST       this,this
//         00470169     JZ         LAB_00470174
//                              player.cpp:1252 (9)
//         0047016b     ADD        ESI,0x58
//         0047016e     PUSH       ESI
//         0047016f     CALL       Visible_Resource_Manager::Process_New_Tiles      void Process_New_Tiles(Visible_Resource_Manag
//                               LAB_00470174                                                 XREF[1]:     00470169(j)
//                              player.cpp:1254 (2)
//         00470174     POP        ESI
//         00470175     RET
//         00470176     ??         90h
//         00470177     NOP
//         00470178     NOP
//         00470179     NOP
//         0047017a     NOP
//         0047017b     NOP
//         0047017c     NOP
//         0047017d     NOP
//         0047017e     NOP
//         0047017f     NOP
    return;
}

void RGE_Player::update_dopplegangers() {
    /* TODO: Stub */
//                              void __thiscall update_dopplegangers(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?update_dopplegangers@RGE_Player@@UAEXXZ                     XREF[2]:     update_dopplegangers:0051261d(T),
//                               RGE_Player::update_dopplegangers                                          update_dopplegangers:00512620(j),
//                                                                                                         00570f50(*)
//                              player.cpp:1257 (3)
//         00470180     PUSH       ESI
//         00470181     MOV        ESI,this
//                              player.cpp:1258 (10)
//         00470183     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00470189     TEST       this,this
//         0047018b     JZ         LAB_00470192
//                              player.cpp:1259 (5)
//         0047018d     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00470192                                                 XREF[1]:     0047018b(j)
//                              player.cpp:1261 (8)
//         00470192     MOV        this,dword ptr [ESI + 0x30]
//         00470195     CALL       RGE_Object_List::update                          void update(RGE_Object_List * this)
//                              player.cpp:1262 (8)
//         0047019a     MOV        this,dword ptr [ESI + 0x40]
//         0047019d     CALL       RGE_Doppleganger_Creator::perform_doppleganger   void perform_doppleganger_checks(RGE_Dopplega
//                              player.cpp:1264 (2)
//         004701a2     POP        ESI
//         004701a3     RET
//         004701a4     ??         90h
//         004701a5     NOP
//         004701a6     NOP
//         004701a7     NOP
//         004701a8     NOP
//         004701a9     NOP
//         004701aa     NOP
//         004701ab     NOP
//         004701ac     NOP
//         004701ad     NOP
//         004701ae     NOP
//         004701af     NOP
    return;
}

void RGE_Player::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004701c3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00470233(W), 00470237(*), 00470244(R)
//              undefined1        Stack[-0x5]:1  local_5                   XREF[3]:     00470326(W), 0047032c(W), 00470331(*)
//              short             Stack[-0x8]:2  index
//              uchar             Stack[-0x9]:1  table
//                               ?save@RGE_Player@@UAEXH@Z                                    XREF[2]:     save:00512269(c), 00570f54(*)
//                               RGE_Player::save
//                              player.cpp:1271 (6)
//         004701b0     SUB        ESP,0x8
//         004701b3     PUSH       EBX
//         004701b4     PUSH       ESI
//         004701b5     PUSH       EDI
//                              player.cpp:1275 (13)
//         004701b6     PUSH       0x3
//         004701b8     PUSH       0x32
//         004701ba     MOV        ESI,this
//         004701bc     PUSH       0x32
//         004701be     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1277 (19)
//         004701c3     MOV        EBX,dword ptr [ESP + param_1]
//         004701c7     ADD        ESP,0xc
//         004701ca     LEA        EAX,[ESI + 0x48]
//         004701cd     PUSH       0x1
//         004701cf     PUSH       EAX
//         004701d0     PUSH       EBX
//         004701d1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1279 (27)
//         004701d6     MOV        this,dword ptr [ESI + 0x3c]
//         004701d9     MOV        EAX,dword ptr [ESI + 0x84]
//         004701df     ADD        ESP,0xc
//         004701e2     MOVSX      EDX,word ptr [ECX + this->world]
//         004701e6     PUSH       EDX
//         004701e7     PUSH       EAX
//         004701e8     PUSH       EBX
//         004701e9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004701ee     ADD        ESP,0xc
//                              player.cpp:1280 (18)
//         004701f1     LEA        this,[ESI + 0x88]
//         004701f7     PUSH       0x24
//         004701f9     PUSH       this
//         004701fa     PUSH       EBX
//         004701fb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00470200     ADD        ESP,0xc
//                              player.cpp:1281 (18)
//         00470203     LEA        EDX,[ESI + 0x100]
//         00470209     PUSH       0x4
//         0047020b     PUSH       EDX
//         0047020c     PUSH       EBX
//         0047020d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00470212     ADD        ESP,0xc
//                              player.cpp:1282 (15)
//         00470215     LEA        EAX,[ESI + 0x104]
//         0047021b     PUSH       0x1
//         0047021d     PUSH       EAX
//         0047021e     PUSH       EBX
//         0047021f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1284 (19)
//         00470224     MOV        EDI,dword ptr [ESI + 0x44]
//         00470227     OR         this,0xffffffff
//         0047022a     XOR        EAX,EAX
//         0047022c     ADD        ESP,0xc
//         0047022f     SCASB.RE   ES:EDI
//         00470231     NOT        this
//         00470233     MOV        dword ptr [ESP + local_4],this
//                              player.cpp:1285 (13)
//         00470237     LEA        this=>local_4,[ESP + 0x10]
//         0047023b     PUSH       0x2
//         0047023d     PUSH       this
//         0047023e     PUSH       EBX
//         0047023f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1286 (12)
//         00470244     MOV        EAX,dword ptr [ESP + local_4]
//         00470248     ADD        ESP,0xc
//         0047024b     TEST       AX,AX
//         0047024e     JLE        LAB_00470261
//                              player.cpp:1287 (17)
//         00470250     MOVSX      EDX,AX
//         00470253     MOV        EAX,dword ptr [ESI + 0x44]
//         00470256     PUSH       EDX
//         00470257     PUSH       EAX
//         00470258     PUSH       EBX
//         00470259     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0047025e     ADD        ESP,0xc
//                               LAB_00470261                                                 XREF[1]:     0047024e(j)
//                              player.cpp:1289 (12)
//         00470261     LEA        EDI,[ESI + 0x4c]
//         00470264     PUSH       0x2
//         00470266     PUSH       EDI
//         00470267     PUSH       EBX
//         00470268     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1290 (11)
//         0047026d     MOV        DI,word ptr [EDI]
//         00470270     ADD        ESP,0xc
//         00470273     TEST       DI,DI
//         00470276     JLE        LAB_0047028c
//                              player.cpp:1291 (20)
//         00470278     MOV        EDX,dword ptr [ESI + 0x50]
//         0047027b     MOVSX      this,DI
//         0047027e     SHL        this,0x2
//         00470281     PUSH       this
//         00470282     PUSH       EDX
//         00470283     PUSH       EBX
//         00470284     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00470289     ADD        ESP,0xc
//                               LAB_0047028c                                                 XREF[1]:     00470276(j)
//                              player.cpp:1293 (18)
//         0047028c     LEA        EAX,[ESI + 0x114]
//         00470292     PUSH       0x4
//         00470294     PUSH       EAX
//         00470295     PUSH       EBX
//         00470296     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0047029b     ADD        ESP,0xc
//                              player.cpp:1294 (18)
//         0047029e     LEA        this,[ESI + 0x118]
//         004702a4     PUSH       0x4
//         004702a6     PUSH       this
//         004702a7     PUSH       EBX
//         004702a8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004702ad     ADD        ESP,0xc
//                              player.cpp:1295 (18)
//         004702b0     LEA        EDX,[ESI + 0x11c]
//         004702b6     PUSH       0x2
//         004702b8     PUSH       EDX
//         004702b9     PUSH       EBX
//         004702ba     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004702bf     ADD        ESP,0xc
//                              player.cpp:1296 (18)
//         004702c2     LEA        EAX,[ESI + 0x11e]
//         004702c8     PUSH       0x2
//         004702ca     PUSH       EAX
//         004702cb     PUSH       EBX
//         004702cc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004702d1     ADD        ESP,0xc
//                              player.cpp:1297 (15)
//         004702d4     LEA        this,[ESI + 0x54]
//         004702d7     PUSH       0x1
//         004702d9     PUSH       this
//         004702da     PUSH       EBX
//         004702db     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004702e0     ADD        ESP,0xc
//                              player.cpp:1298 (18)
//         004702e3     LEA        EDX,[ESI + 0x105]
//         004702e9     PUSH       0x1
//         004702eb     PUSH       EDX
//         004702ec     PUSH       EBX
//         004702ed     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004702f2     ADD        ESP,0xc
//                              player.cpp:1300 (18)
//         004702f5     LEA        EAX,[ESI + 0x80]
//         004702fb     PUSH       0x1
//         004702fd     PUSH       EAX
//         004702fe     PUSH       EBX
//         004702ff     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00470304     ADD        ESP,0xc
//                              player.cpp:1301 (15)
//         00470307     LEA        this,[ESI + 0x81]
//         0047030d     PUSH       0x1
//         0047030f     PUSH       this
//         00470310     PUSH       EBX
//         00470311     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1303 (27)
//         00470316     MOV        EAX,dword ptr [ESI + 0x108]
//         0047031c     ADD        ESP,0xc
//         0047031f     TEST       EAX,EAX
//         00470321     JZ         LAB_0047032c
//         00470323     MOV        DL,byte ptr [EAX + 0x26]
//         00470326     MOV        byte ptr [ESP + local_5],DL
//         0047032a     JMP        LAB_00470331
//                               LAB_0047032c                                                 XREF[1]:     00470321(j)
//         0047032c     MOV        byte ptr [ESP + local_5],0x0
//                               LAB_00470331                                                 XREF[1]:     0047032a(j)
//                              player.cpp:1304 (16)
//         00470331     LEA        EAX=>local_5,[ESP + 0xf]
//         00470335     PUSH       0x1
//         00470337     PUSH       EAX
//         00470338     PUSH       EBX
//         00470339     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0047033e     ADD        ESP,0xc
//                              player.cpp:1306 (15)
//         00470341     LEA        this,[ESI + 0x8]
//         00470344     PUSH       0x4
//         00470346     PUSH       this
//         00470347     PUSH       EBX
//         00470348     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0047034d     ADD        ESP,0xc
//                              player.cpp:1307 (15)
//         00470350     ADD        ESI,0xc
//         00470353     PUSH       0x4
//         00470355     PUSH       ESI
//         00470356     PUSH       EBX
//         00470357     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0047035c     ADD        ESP,0xc
//                              player.cpp:1309 (14)
//         0047035f     PUSH       0x3
//         00470361     PUSH       0x5f
//         00470363     PUSH       0x32
//         00470365     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0047036a     ADD        ESP,0xc
//                              player.cpp:1310 (9)
//         0047036d     POP        EDI
//         0047036e     POP        ESI
//         0047036f     POP        EBX
//         00470370     ADD        ESP,0x8
//         00470373     RET        0x4
//         00470376     ??         90h
//         00470377     NOP
//         00470378     NOP
//         00470379     NOP
//         0047037a     NOP
//         0047037b     NOP
//         0047037c     NOP
//         0047037d     NOP
//         0047037e     NOP
//         0047037f     NOP
    return;
}

void RGE_Player::save2(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save2(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00470390(R), 004703bf(W), 004703c5(W), 004703cd(*)
//                               ?save2@RGE_Player@@UAEXH@Z                                   XREF[3]:     00570f58(*), 005768f8(*),
//                               RGE_Player::save2                                                         00576a28(*)
//                              player.cpp:1314 (3)
//         00470380     PUSH       EBX
//         00470381     PUSH       EBP
//         00470382     PUSH       ESI
//                              player.cpp:1317 (13)
//         00470383     PUSH       0x4
//         00470385     PUSH       0x4c
//         00470387     MOV        ESI,this
//         00470389     PUSH       0x4c
//         0047038b     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1319 (19)
//         00470390     MOV        EBX,dword ptr [ESP + param_1]
//         00470394     ADD        ESP,0xc
//         00470397     LEA        EBP,[ESI + 0x22]
//         0047039a     PUSH       0x2
//         0047039c     PUSH       EBP
//         0047039d     PUSH       EBX
//         0047039e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              player.cpp:1320 (13)
//         004703a3     MOV        AX,word ptr [EBP]
//         004703a7     ADD        ESP,0xc
//         004703aa     TEST       AX,AX
//         004703ad     JLE        LAB_00470409
//         004703af     PUSH       EDI
//                              player.cpp:1323 (7)
//         004703b0     XOR        EDI,EDI
//         004703b2     TEST       AX,AX
//         004703b5     JLE        LAB_004703e6
//                               LAB_004703b7                                                 XREF[1]:     004703e4(j)
//                              player.cpp:1325 (6)
//         004703b7     MOV        EAX,dword ptr [ESI + 0x24]
//         004703ba     MOV        EAX,dword ptr [EAX + EDI*0x4]
//                              player.cpp:1326 (16)
//         004703bd     TEST       EAX,EAX
//         004703bf     MOV        dword ptr [ESP + param_1],EAX
//         004703c3     JZ         LAB_004703cd
//         004703c5     MOV        dword ptr [ESP + param_1],0x1
//                               LAB_004703cd                                                 XREF[1]:     004703c3(j)
//                              player.cpp:1327 (25)
//         004703cd     LEA        this=>param_1,[ESP + 0x14]
//         004703d1     PUSH       0x4
//         004703d3     PUSH       this
//         004703d4     PUSH       EBX
//         004703d5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004703da     MOVSX      EDX,word ptr [EBP]
//         004703de     ADD        ESP,0xc
//         004703e1     INC        EDI
//         004703e2     CMP        EDI,EDX
//         004703e4     JL         LAB_004703b7
//                               LAB_004703e6                                                 XREF[1]:     004703b5(j)
//                              player.cpp:1331 (8)
//         004703e6     XOR        EDI,EDI
//         004703e8     CMP        word ptr [EBP],DI
//         004703ec     JLE        LAB_00470408
//                               LAB_004703ee                                                 XREF[1]:     00470406(j)
//                              player.cpp:1332 (13)
//         004703ee     MOV        this,dword ptr [ESI + 0x24]
//         004703f1     MOVSX      EAX,DI
//         004703f4     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
//         004703f7     TEST       this,this
//         004703f9     JZ         LAB_00470401
//                              player.cpp:1333 (13)
//         004703fb     MOV        EDX,dword ptr [this->_padding_]
//         004703fd     PUSH       EBX
//         004703fe     CALL       dword ptr [EDX + 0x14]
//                               LAB_00470401                                                 XREF[1]:     004703f9(j)
//         00470401     INC        EDI
//         00470402     CMP        DI,word ptr [EBP]
//         00470406     JL         LAB_004703ee
//                               LAB_00470408                                                 XREF[1]:     004703ec(j)
//                              player.cpp:1314 (1)
//         00470408     POP        EDI
//                               LAB_00470409                                                 XREF[1]:     004703ad(j)
//                              player.cpp:1336 (11)
//         00470409     PUSH       0x4
//         0047040b     PUSH       0x24
//         0047040d     PUSH       offset DAT_fffffff8
//         0047040f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1338 (12)
//         00470414     MOV        this,dword ptr [ESI + 0x38]
//         00470417     ADD        ESP,0xc
//         0047041a     PUSH       EBX
//         0047041b     CALL       RGE_Visible_Map::save                            void save(RGE_Visible_Map * this, int param_1)
//                              player.cpp:1339 (12)
//         00470420     MOV        this,dword ptr [ESI + 0x110]
//         00470426     PUSH       EBX
//         00470427     CALL       Visible_Resource_Manager::save                   void save(Visible_Resource_Manager * this, in
//                              player.cpp:1341 (11)
//         0047042c     PUSH       0x4
//         0047042e     PUSH       0x16
//         00470430     PUSH       offset DAT_fffffff8
//         00470432     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1343 (12)
//         00470437     MOV        this,dword ptr [ESI + 0x28]
//         0047043a     ADD        ESP,0xc
//         0047043d     PUSH       EBX
//         0047043e     CALL       RGE_Object_List::save                            void save(RGE_Object_List * this, int param_1)
//                              player.cpp:1345 (11)
//         00470443     PUSH       0x4
//         00470445     PUSH       0x32
//         00470447     PUSH       offset DAT_fffffff8
//         00470449     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1347 (12)
//         0047044e     MOV        this,dword ptr [ESI + 0x2c]
//         00470451     ADD        ESP,0xc
//         00470454     PUSH       EBX
//         00470455     CALL       RGE_Object_List::save                            void save(RGE_Object_List * this, int param_1)
//                              player.cpp:1349 (11)
//         0047045a     PUSH       0x4
//         0047045c     PUSH       0x32
//         0047045e     PUSH       offset DAT_fffffff8
//         00470460     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              player.cpp:1351 (12)
//         00470465     MOV        this,dword ptr [ESI + 0x30]
//         00470468     ADD        ESP,0xc
//         0047046b     PUSH       EBX
//         0047046c     CALL       RGE_Object_List::save                            void save(RGE_Object_List * this, int param_1)
//                              player.cpp:1353 (14)
//         00470471     PUSH       0x4
//         00470473     PUSH       0x5f
//         00470475     PUSH       offset DAT_fffffff8
//         00470477     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0047047c     ADD        ESP,0xc
//                              player.cpp:1367 (6)
//         0047047f     POP        ESI
//         00470480     POP        EBP
//         00470481     POP        EBX
//         00470482     RET        0x4
//         00470485     ??         90h
//         00470486     NOP
//         00470487     NOP
//         00470488     NOP
//         00470489     NOP
//         0047048a     NOP
//         0047048b     NOP
//         0047048c     NOP
//         0047048d     NOP
//         0047048e     NOP
//         0047048f     NOP
    return;
}

void RGE_Player::save_info(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save_info(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00470493(R)
//                               ?save_info@RGE_Player@@UAEXH@Z                               XREF[3]:     00570f5c(*), 005768fc(*),
//                               RGE_Player::save_info                                                     00576a2c(*)
//                              player.cpp:1371 (13)
//         00470490     MOV        this,dword ptr [ECX + this->victory_conditions]
//         00470493     MOV        EDX,dword ptr [ESP + param_1]
//         00470497     PUSH       EDX
//         00470498     MOV        EAX,dword ptr [this->_padding_]
//         0047049a     CALL       dword ptr [EAX + 0xc]
//                              player.cpp:1373 (3)
//         0047049d     RET        0x4
    return;
}

void RGE_Player::set_map_loc(short param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall set_map_loc(RGE_Player * this, short param_1, short
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     004704a0(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     004704a5(R)
//                               ?set_map_loc@RGE_Player@@QAEXFF@Z                            XREF[9]:     RGE_Player:0046ea90(c),
//                               RGE_Player::set_map_loc                                                   command_select_building:0049cdcc(c
//                                                                                                         command_view_selected:0049d0ee(c),
//                                                                                                         command_view_tribe:0049d190(c),
//                                                                                                         set_unit_player:004ab378(c),
//                                                                                                         action:004ac3c0(c),
//                                                                                                         action:004ac7b6(c),
//                                                                                                         random_start:005141e6(c),
//                                                                                                         random_start:005143a2(c)
//                              player.cpp:1377 (5)
//         004704a0     MOV        AX,word ptr [ESP + param_1]
//                              player.cpp:1379 (19)
//         004704a5     MOV        DX,word ptr [ESP + param_2]
//         004704aa     MOV        word ptr [ECX + this->map_x],AX
//         004704b1     MOV        word ptr [ECX + this->map_y],DX
//                              player.cpp:1380 (3)
//         004704b8     RET        0x8
//         004704bb     ??         90h
//         004704bc     NOP
//         004704bd     NOP
//         004704be     NOP
//         004704bf     NOP
    return;
}

void RGE_Player::set_view_loc(float param_1, float param_2) {
    /* TODO: Stub */
//                              void __thiscall set_view_loc(RGE_Player * this, float param_1, float
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[5]:     004704c1(R), 004704cb(R), 00470502(R), 0047053e(W),
//                                                                                     00470542(R)
//              float             Stack[0x8]:4   param_2                   XREF[3]:     004704cf(R), 00470519(R), 00470546(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004704fa(*), 004704fe(*)
//                               ?set_view_loc@RGE_Player@@QAEXMM@Z                           XREF[22]:    start_scroll_view:004386e1(c),
//                               RGE_Player::set_view_loc                                                  handle_scroll_view:00438780(c),
//                                                                                                         RGE_Player:0046ea71(c),
//                                                                                                         command_select_building:0049cda8(c
//                                                                                                         command_view_selected:0049d0ca(c),
//                                                                                                         command_view_tribe:0049d16c(c),
//                                                                                                         set_unit_player:004ab36b(c),
//                                                                                                         action:004ac39a(c),
//                                                                                                         action:004ac7c9(c),
//                                                                                                         random_start:005141ef(c),
//                                                                                                         random_start:005143b1(c),
//                                                                                                         goto_notification_loc:0052a717(c),
//                                                                                                         start_scroll_view:0053a25a(c),
//                                                                                                         handle_scroll_view:0053a37d(c),
//                                                                                                         handle_scroll_view:0053a557(c),
//                                                                                                         handle_scroll_view:0053a729(c),
//                                                                                                         handle_scroll_view:0053a784(c),
//                                                                                                         do_auto_scroll:0053ddea(c),
//                                                                                                         do_auto_scroll:0053de44(c),
//                                                                                                         handle_keys:0053e1a6(c), [more]
//                              player.cpp:1384 (1)
//         004704c0     PUSH       this
//                              player.cpp:1388 (39)
//         004704c1     FLD        float ptr [ESP + param_1]
//         004704c5     FCOMP      float ptr [DAT_00570ec4]
//         004704cb     MOV        EAX,dword ptr [ESP + param_1]
//         004704cf     MOV        EDX,dword ptr [ESP + param_2]
//         004704d3     MOV        dword ptr [ECX + this->view_x],EAX
//         004704d9     MOV        dword ptr [ECX + this->view_y],EDX
//         004704df     XOR        EDX,EDX
//         004704e1     FNSTSW     AX
//         004704e3     TEST       AH,0x1
//         004704e6     JZ         LAB_004704f0
//                              player.cpp:1389 (6)
//         004704e8     MOV        dword ptr [ECX + this->view_x],EDX
//                              player.cpp:1390 (33)
//         004704ee     JMP        LAB_00470519
//                               LAB_004704f0                                                 XREF[1]:     004704e6(j)
//         004704f0     MOV        EAX,dword ptr [ECX + this->world]
//         004704f3     MOV        EAX,dword ptr [EAX + 0x28]
//         004704f6     MOV        EAX,dword ptr [EAX + 0x8]
//         004704f9     DEC        EAX
//         004704fa     MOV        dword ptr [ESP]=>local_4,EAX
//         004704fe     FILD       dword ptr [ESP]=>local_4
//         00470502     FLD        float ptr [ESP + param_1]
//         00470506     FCOMP
//         00470508     FNSTSW     AX
//         0047050a     TEST       AH,0x41
//         0047050d     JNZ        LAB_00470517
//                              player.cpp:1391 (6)
//         0047050f     FSTP       float ptr [ECX + this->view_x]
//                              player.cpp:1390 (4)
//         00470515     JMP        LAB_00470519
//                               LAB_00470517                                                 XREF[1]:     0047050d(j)
//         00470517     FSTP       ST0
//                               LAB_00470519                                                 XREF[2]:     004704ee(j), 00470515(j)
//                              player.cpp:1393 (17)
//         00470519     FLD        float ptr [ESP + param_2]
//         0047051d     FCOMP      float ptr [DAT_00570ec4]
//         00470523     FNSTSW     AX
//         00470525     TEST       AH,0x1
//         00470528     JZ         LAB_00470534
//                              player.cpp:1394 (6)
//         0047052a     MOV        dword ptr [ECX + this->view_y],EDX
//                              player.cpp:1397 (4)
//         00470530     POP        this
//         00470531     RET        0x8
//                               LAB_00470534                                                 XREF[1]:     00470528(j)
//                              player.cpp:1395 (31)
//         00470534     MOV        EDX,dword ptr [ECX + this->world]
//         00470537     MOV        EAX,dword ptr [EDX + 0x28]
//         0047053a     MOV        EDX,dword ptr [EAX + 0xc]
//         0047053d     DEC        EDX
//         0047053e     MOV        dword ptr [ESP + param_1],EDX
//         00470542     FILD       dword ptr [ESP + param_1]
//         00470546     FLD        float ptr [ESP + param_2]
//         0047054a     FCOMP
//         0047054c     FNSTSW     AX
//         0047054e     TEST       AH,0x41
//         00470551     JNZ        LAB_0047055d
//                              player.cpp:1396 (6)
//         00470553     FSTP       float ptr [ECX + this->view_y]
//                              player.cpp:1397 (4)
//         00470559     POP        this
//         0047055a     RET        0x8
//                               LAB_0047055d                                                 XREF[1]:     00470551(j)
//                              player.cpp:1395 (2)
//         0047055d     FSTP       ST0
//                              player.cpp:1397 (4)
//         0047055f     POP        this
//         00470560     RET        0x8
//         00470563     ??         90h
//         00470564     NOP
//         00470565     NOP
//         00470566     NOP
//         00470567     NOP
//         00470568     NOP
//         00470569     NOP
//         0047056a     NOP
//         0047056b     NOP
//         0047056c     NOP
//         0047056d     NOP
//         0047056e     NOP
//         0047056f     NOP
    return;
}

void RGE_Player::random_start() {
    /* TODO: Stub */
//                              void __thiscall random_start(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?random_start@RGE_Player@@UAEXXZ                             XREF[1]:     00570f60(*)
//                               RGE_Player::random_start
//                              player.cpp:1401 (1)
//         00470570     RET
//         00470571     ??         90h
//         00470572     NOP
//         00470573     NOP
//         00470574     NOP
//         00470575     NOP
//         00470576     NOP
//         00470577     NOP
//         00470578     NOP
//         00470579     NOP
//         0047057a     NOP
//         0047057b     NOP
//         0047057c     NOP
//         0047057d     NOP
//         0047057e     NOP
//         0047057f     NOP
    return;
}

void RGE_Player::destroy_objects() {
    /* TODO: Stub */
//                              void __thiscall destroy_objects(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?destroy_objects@RGE_Player@@QAEXXZ                          XREF[1]:     del_game_info:00541fde(c)
//                               RGE_Player::destroy_objects
//                              player.cpp:1406 (11)
//         00470580     MOV        EAX,dword ptr [ECX + this->objects]
//         00470583     PUSH       ESI
//         00470584     MOV        ESI,dword ptr [EAX + 0x4]
//         00470587     TEST       ESI,ESI
//         00470589     JZ         LAB_00470599
//                               LAB_0047058b                                                 XREF[1]:     00470597(j)
//                              player.cpp:1410 (14)
//         0047058b     MOV        this,dword ptr [ESI]
//         0047058d     MOV        EDX,dword ptr [this->_padding_]
//         0047058f     CALL       dword ptr [EDX + 0x68]
//         00470592     MOV        ESI,dword ptr [ESI + 0x4]
//         00470595     TEST       ESI,ESI
//         00470597     JNZ        LAB_0047058b
//                               LAB_00470599                                                 XREF[1]:     00470589(j)
//                              player.cpp:1411 (2)
//         00470599     POP        ESI
//         0047059a     RET
//         0047059b     ??         90h
//         0047059c     NOP
//         0047059d     NOP
//         0047059e     NOP
//         0047059f     NOP
    return;
}

void RGE_Player::set_color_table(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_color_table(RGE_Player * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004705a3(R)
//                               ?set_color_table@RGE_Player@@QAEXE@Z                         XREF[6]:     RGE_Player:0046e703(c),
//                               RGE_Player::set_color_table                                               setup_player_colors:005425c3(c),
//                                                                                                         setup_player_colors:0054264a(c),
//                                                                                                         setup_player_colors:005426a4(c),
//                                                                                                         setup_player_colors:005426f0(c),
//                                                                                                         setup_player_colors:0054272d(c)
//                              player.cpp:1415 (24)
//         004705a0     MOV        EDX,dword ptr [ECX + this->world]
//         004705a3     MOV        EAX,dword ptr [ESP + param_1]
//         004705a7     AND        EAX,0xff
//         004705ac     MOV        EDX,dword ptr [EDX + 0x64]
//         004705af     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         004705b2     MOV        dword ptr [ECX + this->color_table],EAX
//                              player.cpp:1417 (3)
//         004705b8     RET        0x4
//         004705bb     ??         90h
//         004705bc     NOP
//         004705bd     NOP
//         004705be     NOP
//         004705bf     NOP
    return;
}

void RGE_Player::victory_if_game_on() {
    /* TODO: Stub */
//                              void __thiscall victory_if_game_on(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?victory_if_game_on@RGE_Player@@QAEXXZ                       XREF[3]:     win_game_now:00470604(c),
//                               RGE_Player::victory_if_game_on                                            win_game_now:0047065f(c),
//                                                                                                         check_game_state:005434c0(c)
//                              player.cpp:1421 (10)
//         004705c0     MOV        AL,byte ptr [ECX + this->game_status]
//         004705c6     TEST       AL,AL
//         004705c8     JNZ        LAB_004705d1
//                              player.cpp:1423 (7)
//         004705ca     MOV        EAX,dword ptr [this->_padding_]
//         004705cc     PUSH       0x1
//         004705ce     CALL       dword ptr [EAX + 0x4]
//                               LAB_004705d1                                                 XREF[1]:     004705c8(j)
//                              player.cpp:1424 (1)
//         004705d1     RET
//         004705d2     ??         90h
//         004705d3     NOP
//         004705d4     NOP
//         004705d5     NOP
//         004705d6     NOP
//         004705d7     NOP
//         004705d8     NOP
//         004705d9     NOP
//         004705da     NOP
//         004705db     NOP
//         004705dc     NOP
//         004705dd     NOP
//         004705de     NOP
//         004705df     NOP
    return;
}

void RGE_Player::loss_if_game_on() {
    /* TODO: Stub */
//                              void __thiscall loss_if_game_on(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?loss_if_game_on@RGE_Player@@QAEXXZ                          XREF[6]:     win_game_now:0047066f(c),
//                               RGE_Player::loss_if_game_on                                               do_command_game:0050a37c(c),
//                                                                                                         action_user_command:00529bb4(c),
//                                                                                                         action_user_command:00529d46(c),
//                                                                                                         cheat:00530fc4(c),
//                                                                                                         check_game_state:0054347b(c)
//                              player.cpp:1428 (10)
//         004705e0     MOV        AL,byte ptr [ECX + this->game_status]
//         004705e6     TEST       AL,AL
//         004705e8     JNZ        LAB_004705f1
//                              player.cpp:1430 (7)
//         004705ea     MOV        EAX,dword ptr [this->_padding_]
//         004705ec     PUSH       0x2
//         004705ee     CALL       dword ptr [EAX + 0x4]
//                               LAB_004705f1                                                 XREF[1]:     004705e8(j)
//                              player.cpp:1431 (1)
//         004705f1     RET
//         004705f2     ??         90h
//         004705f3     NOP
//         004705f4     NOP
//         004705f5     NOP
//         004705f6     NOP
//         004705f7     NOP
//         004705f8     NOP
//         004705f9     NOP
//         004705fa     NOP
//         004705fb     NOP
//         004705fc     NOP
//         004705fd     NOP
//         004705fe     NOP
//         004705ff     NOP
    return;
}

void RGE_Player::win_game_now() {
    /* TODO: Stub */
//                              void __thiscall win_game_now(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?win_game_now@RGE_Player@@QAEXXZ                             XREF[5]:     update:004d38a2(c),
//                               RGE_Player::win_game_now                                                  check_game_state:0053054b(c),
//                                                                                                         check_game_state:005307e3(c),
//                                                                                                         check_game_state:005309be(c),
//                                                                                                         cheat:00530fa9(c)
//                              player.cpp:1435 (4)
//         00470600     PUSH       ESI
//         00470601     PUSH       EDI
//         00470602     MOV        ESI,this
//                              player.cpp:1440 (5)
//         00470604     CALL       RGE_Player::victory_if_game_on                   void victory_if_game_on(RGE_Player * this)
//                              player.cpp:1445 (14)
//         00470609     MOV        EAX,dword ptr [ESI + 0x3c]
//         0047060c     MOV        EDI,0x1
//         00470611     CMP        word ptr [EAX + 0x3c],DI
//         00470615     JLE        LAB_00470680
//                               LAB_00470617                                                 XREF[1]:     0047067e(j)
//                              player.cpp:1446 (8)
//         00470617     MOVSX      this,word ptr [ESI + 0x4a]
//         0047061b     CMP        EDI,this
//         0047061d     JZ         LAB_00470674
//                              player.cpp:1448 (64)
//         0047061f     MOV        AL,byte ptr [ESI + 0x104]
//         00470625     TEST       AL,AL
//         00470627     JZ         LAB_00470666
//         00470629     PUSH       EDI
//         0047062a     MOV        this,ESI
//         0047062c     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         00470631     TEST       AL,AL
//         00470633     JNZ        LAB_00470666
//         00470635     MOV        EAX,dword ptr [ESI + 0x3c]
//         00470638     MOVSX      EDX,word ptr [ESI + 0x4a]
//         0047063c     MOV        this,dword ptr [EAX + 0x40]
//         0047063f     PUSH       EDX
//         00470640     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
//         00470643     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         00470648     TEST       AL,AL
//         0047064a     JNZ        LAB_00470666
//         0047064c     MOV        EDX,dword ptr [ESI + 0x3c]
//         0047064f     MOV        EAX,dword ptr [EDX + 0x40]
//         00470652     MOV        this,dword ptr [EAX + EDI*0x4]
//         00470655     MOV        AL,byte ptr [ECX + this->allied_victory]
//         0047065b     TEST       AL,AL
//         0047065d     JZ         LAB_00470666
//                              player.cpp:1449 (5)
//         0047065f     CALL       RGE_Player::victory_if_game_on                   void victory_if_game_on(RGE_Player * this)
//                              player.cpp:1450 (2)
//         00470664     JMP        LAB_00470674
//                               LAB_00470666                                                 XREF[4]:     00470627(j), 00470633(j),
//                                                                                                         0047064a(j), 0047065d(j)
//                              player.cpp:1451 (26)
//         00470666     MOV        this,dword ptr [ESI + 0x3c]
//         00470669     MOV        EDX,dword ptr [ECX + this->doppleganger_creator]
//         0047066c     MOV        this,dword ptr [EDX + EDI*0x4]
//         0047066f     CALL       RGE_Player::loss_if_game_on                      void loss_if_game_on(RGE_Player * this)
//                               LAB_00470674                                                 XREF[2]:     0047061d(j), 00470664(j)
//         00470674     MOV        EAX,dword ptr [ESI + 0x3c]
//         00470677     INC        EDI
//         00470678     MOVSX      this,word ptr [EAX + 0x3c]
//         0047067c     CMP        EDI,this
//         0047067e     JL         LAB_00470617
//                               LAB_00470680                                                 XREF[1]:     00470615(j)
//                              player.cpp:1453 (3)
//         00470680     POP        EDI
//         00470681     POP        ESI
//         00470682     RET
//         00470683     ??         90h
//         00470684     NOP
//         00470685     NOP
//         00470686     NOP
//         00470687     NOP
//         00470688     NOP
//         00470689     NOP
//         0047068a     NOP
//         0047068b     NOP
//         0047068c     NOP
//         0047068d     NOP
//         0047068e     NOP
//         0047068f     NOP
    return;
}

uchar RGE_Player::check_victory_conditions() {
    /* TODO: Stub */
//                              uchar __thiscall check_victory_conditions(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?check_victory_conditions@RGE_Player@@QAEEXZ                 XREF[1]:     check_victory:004707ff(c)
//                               RGE_Player::check_victory_conditions
//                              player.cpp:1459 (9)
//         00470690     CMP        byte ptr [ECX + this->game_status],0x2
//         00470697     JZ         LAB_004706a1
//                              player.cpp:1461 (8)
//         00470699     MOV        this,dword ptr [ECX + this->victory_conditions]
//         0047069c     JMP        RGE_Victory_Conditions::victory_achieved         uchar victory_achieved(RGE_Victory_Conditions
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_004706a1                                                 XREF[1]:     00470697(j)
//                              player.cpp:1462 (2)
//         004706a1     MOV        AL,0x1
//                              player.cpp:1463 (1)
//         004706a3     RET
//         004706a4     ??         90h
//         004706a5     NOP
//         004706a6     NOP
//         004706a7     NOP
//         004706a8     NOP
//         004706a9     NOP
//         004706aa     NOP
//         004706ab     NOP
//         004706ac     NOP
//         004706ad     NOP
//         004706ae     NOP
//         004706af     NOP
    return 0;
}

uchar RGE_Player::check_ally_group(long* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall check_ally_group(RGE_Player * this, long * param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[3]:     004706b2(R), 004706c2(W), 0047072c(R)
//                               ?check_ally_group@RGE_Player@@QAEEAAJ@Z                      XREF[1]:     check_victory:004707b8(c)
//                               RGE_Player::check_ally_group
//                              player.cpp:1468 (2)
//         004706b0     PUSH       EBX
//         004706b1     PUSH       EBP
//                              player.cpp:1470 (11)
//         004706b2     MOV        EBP,dword ptr [ESP + param_1]
//         004706b6     PUSH       ESI
//         004706b7     MOV        ESI,this
//         004706b9     PUSH       EDI
//         004706ba     MOV        EAX,dword ptr [EBP]
//                              player.cpp:1471 (9)
//         004706bd     MOV        EBX,0x1
//         004706c2     MOV        dword ptr [ESP + param_1],EAX
//                              player.cpp:1473 (10)
//         004706c6     MOV        AL,byte ptr [ESI + 0x80]
//         004706cc     CMP        AL,0x2
//         004706ce     JZ         LAB_0047072c
//                              player.cpp:1475 (7)
//         004706d0     MOV        dword ptr [EBP],0x0
//                              player.cpp:1477 (11)
//         004706d7     MOV        EAX,dword ptr [ESI + 0x3c]
//         004706da     MOV        EDI,EBX
//         004706dc     CMP        word ptr [EAX + 0x3c],BX
//         004706e0     JLE        LAB_0047072c
//                               LAB_004706e2                                                 XREF[1]:     00470726(j)
//                              player.cpp:1478 (51)
//         004706e2     MOV        this,dword ptr [ESI + 0x84]
//         004706e8     CMP        byte ptr [EDI + this->_padding_*0x1],0x0
//         004706ec     JNZ        LAB_00470715
//         004706ee     MOVSX      EDX,word ptr [ESI + 0x4a]
//         004706f2     MOV        EAX,dword ptr [EAX + 0x40]
//         004706f5     PUSH       EDX
//         004706f6     MOV        this,dword ptr [EAX + EDI*0x4]
//         004706f9     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         004706fe     TEST       AL,AL
//         00470700     JNZ        LAB_0047072a
//         00470702     MOV        this,dword ptr [ESI + 0x3c]
//         00470705     MOV        EDX,dword ptr [ECX + this->doppleganger_creator]
//         00470708     MOV        EAX,dword ptr [EDX + EDI*0x4]
//         0047070b     MOV        this,byte ptr [EAX + 0x104]
//         00470711     TEST       this,this
//         00470713     JZ         LAB_0047072a
//                               LAB_00470715                                                 XREF[1]:     004706ec(j)
//                              player.cpp:1484 (21)
//         00470715     MOV        this,dword ptr [EBP]
//         00470718     INC        this
//         00470719     INC        EDI
//         0047071a     MOV        dword ptr [EBP],this
//         0047071d     MOV        EAX,dword ptr [ESI + 0x3c]
//         00470720     MOVSX      this,word ptr [EAX + 0x3c]
//         00470724     CMP        EDI,this
//         00470726     JL         LAB_004706e2
//         00470728     JMP        LAB_0047072c
//                               LAB_0047072a                                                 XREF[2]:     00470700(j), 00470713(j)
//                              player.cpp:1480 (2)
//         0047072a     XOR        BL,BL
//                               LAB_0047072c                                                 XREF[3]:     004706ce(j), 004706e0(j),
//                                                                                                         00470728(j)
//                              player.cpp:1488 (13)
//         0047072c     MOV        EAX,dword ptr [ESP + param_1]
//         00470730     TEST       EAX,EAX
//         00470732     JL         LAB_0047073b
//         00470734     CMP        dword ptr [EBP],EAX
//         00470737     JZ         LAB_0047073b
//                              player.cpp:1489 (2)
//         00470739     XOR        BL,BL
//                               LAB_0047073b                                                 XREF[2]:     00470732(j), 00470737(j)
//                              player.cpp:1492 (9)
//         0047073b     POP        EDI
//         0047073c     POP        ESI
//         0047073d     MOV        AL,BL
//         0047073f     POP        EBP
//         00470740     POP        EBX
//         00470741     RET        0x4
//         00470744     ??         90h
//         00470745     NOP
//         00470746     NOP
//         00470747     NOP
//         00470748     NOP
//         00470749     NOP
//         0047074a     NOP
//         0047074b     NOP
//         0047074c     NOP
//         0047074d     NOP
//         0047074e     NOP
//         0047074f     NOP
    return 0;
}

uchar RGE_Player::check_victory() {
    /* TODO: Stub */
//                              uchar __thiscall check_victory(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00470756(W), 004707b0(*)
//              long              Stack[-0x8]:4  count
//                               ?check_victory@RGE_Player@@QAEEXZ                            XREF[1]:     check_game_state:005433ea(c)
//                               RGE_Player::check_victory
//                              player.cpp:1497 (6)
//         00470750     PUSH       this
//         00470751     PUSH       EBX
//         00470752     PUSH       ESI
//         00470753     MOV        ESI,this
//         00470755     PUSH       EDI
//                              player.cpp:1499 (8)
//         00470756     MOV        dword ptr [ESP + local_4],0xffffffff
//                              player.cpp:1503 (29)
//         0047075e     CMP        byte ptr [ESI + 0x80],0x2
//         00470765     JZ         LAB_0047082c
//         0047076b     MOV        this,dword ptr [ESI + 0x34]
//         0047076e     CALL       RGE_Victory_Conditions::victory_achieved         uchar victory_achieved(RGE_Victory_Conditions
//         00470773     TEST       AL,AL
//         00470775     JZ         LAB_0047082c
//                              player.cpp:1507 (16)
//         0047077b     MOV        AL,byte ptr [ESI + 0x104]
//         00470781     XOR        BL,BL
//         00470783     TEST       AL,AL
//         00470785     JZ         LAB_00470818
//                              player.cpp:1508 (14)
//         0047078b     MOV        EAX,dword ptr [ESI + 0x3c]
//         0047078e     MOV        EDI,0x1
//         00470793     CMP        word ptr [EAX + 0x3c],DI
//         00470797     JLE        LAB_004707d1
//                               LAB_00470799                                                 XREF[1]:     004707cb(j)
//                              player.cpp:1509 (20)
//         00470799     MOVSX      this,word ptr [ESI + 0x4a]
//         0047079d     CMP        EDI,this
//         0047079f     JZ         LAB_004707ad
//         004707a1     MOV        EDX,dword ptr [ESI + 0x84]
//         004707a7     CMP        byte ptr [EDX + EDI*0x1],0x0
//         004707ab     JNZ        LAB_004707c1
//                               LAB_004707ad                                                 XREF[1]:     0047079f(j)
//                              player.cpp:1510 (20)
//         004707ad     MOV        EDX,dword ptr [EAX + 0x40]
//         004707b0     LEA        this=>local_4,[ESP + 0xc]
//         004707b4     PUSH       this
//         004707b5     MOV        this,dword ptr [EDX + EDI*0x4]
//         004707b8     CALL       RGE_Player::check_ally_group                     uchar check_ally_group(RGE_Player * this, lon
//         004707bd     TEST       AL,AL
//         004707bf     JZ         LAB_004707cf
//                               LAB_004707c1                                                 XREF[1]:     004707ab(j)
//                              player.cpp:1508 (14)
//         004707c1     MOV        EAX,dword ptr [ESI + 0x3c]
//         004707c4     INC        EDI
//         004707c5     MOVSX      this,word ptr [EAX + 0x3c]
//         004707c9     CMP        EDI,this
//         004707cb     JL         LAB_00470799
//         004707cd     JMP        LAB_004707d1
//                               LAB_004707cf                                                 XREF[1]:     004707bf(j)
//                              player.cpp:1512 (2)
//         004707cf     MOV        BL,0x1
//                               LAB_004707d1                                                 XREF[2]:     00470797(j), 004707cd(j)
//                              player.cpp:1517 (10)
//         004707d1     MOV        AL,byte ptr [ESI + 0x104]
//         004707d7     TEST       AL,AL
//         004707d9     JZ         LAB_00470818
//                              player.cpp:1518 (4)
//         004707db     TEST       BL,BL
//         004707dd     JNZ        LAB_0047082c
//                              player.cpp:1519 (14)
//         004707df     MOV        EAX,dword ptr [ESI + 0x3c]
//         004707e2     MOV        EDI,0x1
//         004707e7     CMP        word ptr [EAX + 0x3c],DI
//         004707eb     JLE        LAB_00470818
//                               LAB_004707ed                                                 XREF[1]:     00470812(j)
//                              player.cpp:1520 (27)
//         004707ed     MOV        EDX,dword ptr [ESI + 0x84]
//         004707f3     CMP        byte ptr [EDI + EDX*0x1],0x0
//         004707f7     JNZ        LAB_00470808
//         004707f9     MOV        EAX,dword ptr [EAX + 0x40]
//         004707fc     MOV        this,dword ptr [EAX + EDI*0x4]
//         004707ff     CALL       RGE_Player::check_victory_conditions             uchar check_victory_conditions(RGE_Player * t
//         00470804     TEST       AL,AL
//         00470806     JZ         LAB_00470816
//                               LAB_00470808                                                 XREF[1]:     004707f7(j)
//                              player.cpp:1519 (14)
//         00470808     MOV        EAX,dword ptr [ESI + 0x3c]
//         0047080b     INC        EDI
//         0047080c     MOVSX      this,word ptr [EAX + 0x3c]
//         00470810     CMP        EDI,this
//         00470812     JL         LAB_004707ed
//         00470814     JMP        LAB_00470818
//                               LAB_00470816                                                 XREF[1]:     00470806(j)
//                              player.cpp:1522 (2)
//         00470816     MOV        BL,0x1
//                               LAB_00470818                                                 XREF[4]:     00470785(j), 004707d9(j),
//                                                                                                         004707eb(j), 00470814(j)
//                              player.cpp:1527 (4)
//         00470818     TEST       BL,BL
//         0047081a     JNZ        LAB_0047082c
//                              player.cpp:1529 (9)
//         0047081c     MOV        EDX,dword ptr [ESI]
//         0047081e     PUSH       0x1
//         00470820     MOV        this,ESI
//         00470822     CALL       dword ptr [EDX + 0x4]
//                              player.cpp:1530 (7)
//         00470825     MOV        EAX,dword ptr [ESI + 0x3c]
//         00470828     MOV        byte ptr [EAX + 0x1e],0x2
//                               LAB_0047082c                                                 XREF[4]:     00470765(j), 00470775(j),
//                                                                                                         004707dd(j), 0047081a(j)
//                              player.cpp:1533 (6)
//         0047082c     MOV        AL,byte ptr [ESI + 0x80]
//                              player.cpp:1534 (5)
//         00470832     POP        EDI
//         00470833     POP        ESI
//         00470834     POP        EBX
//         00470835     POP        this
//         00470836     RET
//         00470837     ??         90h
//         00470838     NOP
//         00470839     NOP
//         0047083a     NOP
//         0047083b     NOP
//         0047083c     NOP
//         0047083d     NOP
//         0047083e     NOP
//         0047083f     NOP
    return 0;
}

void RGE_Player::modify_tobj(short param_1, short param_2, float param_3, uchar param_4) {
    /* TODO: Stub */
//                              void __thiscall modify_tobj(RGE_Player * this, short param_1, short
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     00470840(R), 004708ba(W)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     004708ac(R), 004708d4(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     00470866(R), 004708c0(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[3]:     00470882(R), 00470897(R), 004708fa(R)
//                               ?modify_tobj@RGE_Player@@QAEXFFME@Z                          XREF[1]:     do_effect:00449674(c)
//                               RGE_Player::modify_tobj
//                              player.cpp:1539 (16)
//         00470840     MOV        AX,word ptr [ESP + param_1]
//         00470845     PUSH       EBX
//         00470846     PUSH       EBP
//         00470847     PUSH       ESI
//         00470848     TEST       AX,AX
//         0047084b     PUSH       EDI
//         0047084c     MOV        EBX,this
//         0047084e     JL         LAB_004708ac
//                              player.cpp:1545 (19)
//         00470850     MOVSX      EDI,AX
//         00470853     MOV        EAX,dword ptr [EBX + 0x24]
//         00470856     SHL        EDI,0x2
//         00470859     CMP        dword ptr [EAX + EDI*0x1],0x0
//         0047085d     JZ         LAB_0047092c
//                              player.cpp:1547 (11)
//         00470863     MOV        EAX,dword ptr [EBX + 0x28]
//         00470866     MOV        EBP,dword ptr [ESP + param_3]
//         0047086a     TEST       EAX,EAX
//         0047086c     JZ         LAB_00470894
//                              player.cpp:1548 (7)
//         0047086e     MOV        ESI,dword ptr [EAX + 0x4]
//         00470871     TEST       ESI,ESI
//         00470873     JZ         LAB_00470894
//                               LAB_00470875                                                 XREF[1]:     00470892(j)
//                              player.cpp:1549 (13)
//         00470875     MOV        this,dword ptr [ESI]
//         00470877     MOV        EDX,dword ptr [EBX + 0x24]
//         0047087a     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0047087d     CMP        EAX,dword ptr [EDX + EDI*0x1]
//         00470880     JNZ        LAB_0047088d
//                              player.cpp:1550 (18)
//         00470882     MOV        EAX,dword ptr [ESP + param_4]
//         00470886     MOV        EDX,dword ptr [this->_padding_]
//         00470888     PUSH       EAX
//         00470889     PUSH       EBP=>DAT_fffffff8
//         0047088a     CALL       dword ptr [EDX + 0x48]
//                               LAB_0047088d                                                 XREF[1]:     00470880(j)
//         0047088d     MOV        ESI,dword ptr [ESI + 0x4]
//         00470890     TEST       ESI,ESI
//         00470892     JNZ        LAB_00470875
//                               LAB_00470894                                                 XREF[2]:     0047086c(j), 00470873(j)
//                              player.cpp:1551 (17)
//         00470894     MOV        this,dword ptr [EBX + 0x24]
//         00470897     MOV        EAX,dword ptr [ESP + param_4]
//         0047089b     PUSH       EAX
//         0047089c     PUSH       EBP=>DAT_fffffff8
//         0047089d     MOV        this,dword ptr [this->_padding_ + EDI*0x1]
//         004708a0     MOV        EDX,dword ptr [this->_padding_]
//         004708a2     CALL       dword ptr [EDX + 0x8]
//                              player.cpp:1566 (7)
//         004708a5     POP        EDI
//         004708a6     POP        ESI
//         004708a7     POP        EBP
//         004708a8     POP        EBX
//         004708a9     RET        0x10
//                               LAB_004708ac                                                 XREF[1]:     0047084e(j)
//                              player.cpp:1554 (8)
//         004708ac     CMP        word ptr [ESP + param_2],0x0
//         004708b2     JL         LAB_0047092c
//                              player.cpp:1556 (12)
//         004708b4     XOR        this,this
//         004708b6     CMP        word ptr [EBX + 0x22],this
//         004708ba     MOV        dword ptr [ESP + param_1],this
//         004708be     JLE        LAB_0047092c
//                              player.cpp:1557 (31)
//         004708c0     MOV        EBP,dword ptr [ESP + param_3]
//                               LAB_004708c4                                                 XREF[1]:     0047092a(j)
//         004708c4     MOV        EDX,dword ptr [EBX + 0x24]
//         004708c7     MOVSX      ESI,this
//         004708ca     SHL        ESI,0x2
//         004708cd     MOV        EAX,dword ptr [EDX + ESI*0x1]
//         004708d0     TEST       EAX,EAX
//         004708d2     JZ         LAB_00470921
//         004708d4     MOV        DX,word ptr [ESP + param_2]
//         004708d9     CMP        word ptr [EAX + 0x14],DX
//         004708dd     JNZ        LAB_00470921
//                              player.cpp:1559 (7)
//         004708df     MOV        EAX,dword ptr [EBX + 0x28]
//         004708e2     TEST       EAX,EAX
//         004708e4     JZ         LAB_0047090c
//                              player.cpp:1560 (7)
//         004708e6     MOV        EDI,dword ptr [EAX + 0x4]
//         004708e9     TEST       EDI,EDI
//         004708eb     JZ         LAB_0047090c
//                               LAB_004708ed                                                 XREF[1]:     0047090a(j)
//                              player.cpp:1561 (13)
//         004708ed     MOV        this,dword ptr [EDI]
//         004708ef     MOV        EAX,dword ptr [EBX + 0x24]
//         004708f2     MOV        EDX,dword ptr [ECX + this->pathingAttemptCapVa
//         004708f5     CMP        EDX,dword ptr [EAX + ESI*0x1]
//         004708f8     JNZ        LAB_00470905
//                              player.cpp:1562 (18)
//         004708fa     MOV        EDX,dword ptr [ESP + param_4]
//         004708fe     MOV        EAX,dword ptr [this->_padding_]
//         00470900     PUSH       EDX
//         00470901     PUSH       EBP=>DAT_fffffff8
//         00470902     CALL       dword ptr [EAX + 0x48]
//                               LAB_00470905                                                 XREF[1]:     004708f8(j)
//         00470905     MOV        EDI,dword ptr [EDI + 0x4]
//         00470908     TEST       EDI,EDI
//         0047090a     JNZ        LAB_004708ed
//                               LAB_0047090c                                                 XREF[2]:     004708e4(j), 004708eb(j)
//                              player.cpp:1563 (32)
//         0047090c     MOV        EAX,dword ptr [EBX + 0x24]
//         0047090f     MOV        this,dword ptr [EAX + ESI*0x1]
//         00470912     MOV        EAX,dword ptr [ESP + 0x20]
//         00470916     PUSH       EAX
//         00470917     PUSH       EBP=>DAT_fffffff8
//         00470918     MOV        EDX,dword ptr [this->_padding_]
//         0047091a     CALL       dword ptr [EDX + 0x8]
//         0047091d     MOV        this,dword ptr [ESP + 0x14]
//                               LAB_00470921                                                 XREF[2]:     004708d2(j), 004708dd(j)
//         00470921     INC        this
//         00470922     CMP        this,word ptr [EBX + 0x22]
//         00470926     MOV        dword ptr [ESP + 0x14],this
//         0047092a     JL         LAB_004708c4
//                               LAB_0047092c                                                 XREF[3]:     0047085d(j), 004708b2(j),
//                                                                                                         004708be(j)
//                              player.cpp:1566 (7)
//         0047092c     POP        EDI
//         0047092d     POP        ESI
//         0047092e     POP        EBP
//         0047092f     POP        EBX
//         00470930     RET        0x10
//         00470933     ??         90h
//         00470934     NOP
//         00470935     NOP
//         00470936     NOP
//         00470937     NOP
//         00470938     NOP
//         00470939     NOP
//         0047093a     NOP
//         0047093b     NOP
//         0047093c     NOP
//         0047093d     NOP
//         0047093e     NOP
//         0047093f     NOP
    return;
}

void RGE_Player::modify_tobj_delta(short param_1, short param_2, float param_3, uchar param_4) {
    /* TODO: Stub */
//                              void __thiscall modify_tobj_delta(RGE_Player * this, short param_1,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     00470940(R), 004709ba(W)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     004709ac(R), 004709d4(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     00470966(R), 004709c0(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[3]:     00470982(R), 00470997(R), 004709fa(R)
//                               ?modify_tobj_delta@RGE_Player@@QAEXFFME@Z                    XREF[1]:     do_effect:00449630(c)
//                               RGE_Player::modify_tobj_delta
//                              player.cpp:1571 (16)
//         00470940     MOV        AX,word ptr [ESP + param_1]
//         00470945     PUSH       EBX
//         00470946     PUSH       EBP
//         00470947     PUSH       ESI
//         00470948     TEST       AX,AX
//         0047094b     PUSH       EDI
//         0047094c     MOV        EBX,this
//         0047094e     JL         LAB_004709ac
//                              player.cpp:1577 (19)
//         00470950     MOVSX      EDI,AX
//         00470953     MOV        EAX,dword ptr [EBX + 0x24]
//         00470956     SHL        EDI,0x2
//         00470959     CMP        dword ptr [EAX + EDI*0x1],0x0
//         0047095d     JZ         LAB_00470a2c
//                              player.cpp:1579 (11)
//         00470963     MOV        EAX,dword ptr [EBX + 0x28]
//         00470966     MOV        EBP,dword ptr [ESP + param_3]
//         0047096a     TEST       EAX,EAX
//         0047096c     JZ         LAB_00470994
//                              player.cpp:1580 (7)
//         0047096e     MOV        ESI,dword ptr [EAX + 0x4]
//         00470971     TEST       ESI,ESI
//         00470973     JZ         LAB_00470994
//                               LAB_00470975                                                 XREF[1]:     00470992(j)
//                              player.cpp:1581 (13)
//         00470975     MOV        this,dword ptr [ESI]
//         00470977     MOV        EDX,dword ptr [EBX + 0x24]
//         0047097a     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         0047097d     CMP        EAX,dword ptr [EDX + EDI*0x1]
//         00470980     JNZ        LAB_0047098d
//                              player.cpp:1582 (18)
//         00470982     MOV        EAX,dword ptr [ESP + param_4]
//         00470986     MOV        EDX,dword ptr [this->_padding_]
//         00470988     PUSH       EAX
//         00470989     PUSH       EBP=>DAT_fffffff8
//         0047098a     CALL       dword ptr [EDX + 0x4c]
//                               LAB_0047098d                                                 XREF[1]:     00470980(j)
//         0047098d     MOV        ESI,dword ptr [ESI + 0x4]
//         00470990     TEST       ESI,ESI
//         00470992     JNZ        LAB_00470975
//                               LAB_00470994                                                 XREF[2]:     0047096c(j), 00470973(j)
//                              player.cpp:1583 (17)
//         00470994     MOV        this,dword ptr [EBX + 0x24]
//         00470997     MOV        EAX,dword ptr [ESP + param_4]
//         0047099b     PUSH       EAX
//         0047099c     PUSH       EBP=>DAT_fffffff8
//         0047099d     MOV        this,dword ptr [this->_padding_ + EDI*0x1]
//         004709a0     MOV        EDX,dword ptr [this->_padding_]
//         004709a2     CALL       dword ptr [EDX + 0xc]
//                              player.cpp:1598 (7)
//         004709a5     POP        EDI
//         004709a6     POP        ESI
//         004709a7     POP        EBP
//         004709a8     POP        EBX
//         004709a9     RET        0x10
//                               LAB_004709ac                                                 XREF[1]:     0047094e(j)
//                              player.cpp:1586 (8)
//         004709ac     CMP        word ptr [ESP + param_2],0x0
//         004709b2     JL         LAB_00470a2c
//                              player.cpp:1588 (12)
//         004709b4     XOR        this,this
//         004709b6     CMP        word ptr [EBX + 0x22],this
//         004709ba     MOV        dword ptr [ESP + param_1],this
//         004709be     JLE        LAB_00470a2c
//                              player.cpp:1589 (31)
//         004709c0     MOV        EBP,dword ptr [ESP + param_3]
//                               LAB_004709c4                                                 XREF[1]:     00470a2a(j)
//         004709c4     MOV        EDX,dword ptr [EBX + 0x24]
//         004709c7     MOVSX      ESI,this
//         004709ca     SHL        ESI,0x2
//         004709cd     MOV        EAX,dword ptr [EDX + ESI*0x1]
//         004709d0     TEST       EAX,EAX
//         004709d2     JZ         LAB_00470a21
//         004709d4     MOV        DX,word ptr [ESP + param_2]
//         004709d9     CMP        word ptr [EAX + 0x14],DX
//         004709dd     JNZ        LAB_00470a21
//                              player.cpp:1591 (7)
//         004709df     MOV        EAX,dword ptr [EBX + 0x28]
//         004709e2     TEST       EAX,EAX
//         004709e4     JZ         LAB_00470a0c
//                              player.cpp:1592 (7)
//         004709e6     MOV        EDI,dword ptr [EAX + 0x4]
//         004709e9     TEST       EDI,EDI
//         004709eb     JZ         LAB_00470a0c
//                               LAB_004709ed                                                 XREF[1]:     00470a0a(j)
//                              player.cpp:1593 (13)
//         004709ed     MOV        this,dword ptr [EDI]
//         004709ef     MOV        EAX,dword ptr [EBX + 0x24]
//         004709f2     MOV        EDX,dword ptr [ECX + this->pathingAttemptCapVa
//         004709f5     CMP        EDX,dword ptr [EAX + ESI*0x1]
//         004709f8     JNZ        LAB_00470a05
//                              player.cpp:1594 (18)
//         004709fa     MOV        EDX,dword ptr [ESP + param_4]
//         004709fe     MOV        EAX,dword ptr [this->_padding_]
//         00470a00     PUSH       EDX
//         00470a01     PUSH       EBP=>DAT_fffffff8
//         00470a02     CALL       dword ptr [EAX + 0x4c]
//                               LAB_00470a05                                                 XREF[1]:     004709f8(j)
//         00470a05     MOV        EDI,dword ptr [EDI + 0x4]
//         00470a08     TEST       EDI,EDI
//         00470a0a     JNZ        LAB_004709ed
//                               LAB_00470a0c                                                 XREF[2]:     004709e4(j), 004709eb(j)
//                              player.cpp:1595 (32)
//         00470a0c     MOV        EAX,dword ptr [EBX + 0x24]
//         00470a0f     MOV        this,dword ptr [EAX + ESI*0x1]
//         00470a12     MOV        EAX,dword ptr [ESP + 0x20]
//         00470a16     PUSH       EAX
//         00470a17     PUSH       EBP=>DAT_fffffff8
//         00470a18     MOV        EDX,dword ptr [this->_padding_]
//         00470a1a     CALL       dword ptr [EDX + 0xc]
//         00470a1d     MOV        this,dword ptr [ESP + 0x14]
//                               LAB_00470a21                                                 XREF[2]:     004709d2(j), 004709dd(j)
//         00470a21     INC        this
//         00470a22     CMP        this,word ptr [EBX + 0x22]
//         00470a26     MOV        dword ptr [ESP + 0x14],this
//         00470a2a     JL         LAB_004709c4
//                               LAB_00470a2c                                                 XREF[3]:     0047095d(j), 004709b2(j),
//                                                                                                         004709be(j)
//                              player.cpp:1598 (7)
//         00470a2c     POP        EDI
//         00470a2d     POP        ESI
//         00470a2e     POP        EBP
//         00470a2f     POP        EBX
//         00470a30     RET        0x10
//         00470a33     ??         90h
//         00470a34     NOP
//         00470a35     NOP
//         00470a36     NOP
//         00470a37     NOP
//         00470a38     NOP
//         00470a39     NOP
//         00470a3a     NOP
//         00470a3b     NOP
//         00470a3c     NOP
//         00470a3d     NOP
//         00470a3e     NOP
//         00470a3f     NOP
    return;
}

void RGE_Player::modify_tobj_percent(short param_1, short param_2, float param_3, uchar param_4) {
    /* TODO: Stub */
//                              void __thiscall modify_tobj_percent(RGE_Player * this, short param_1
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     00470a40(R), 00470aba(W)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     00470aac(R), 00470ad4(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     00470a66(R), 00470ac0(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[3]:     00470a82(R), 00470a97(R), 00470afa(R)
//                               ?modify_tobj_percent@RGE_Player@@QAEXFFME@Z                  XREF[1]:     do_effect:00449652(c)
//                               RGE_Player::modify_tobj_percent
//                              player.cpp:1603 (16)
//         00470a40     MOV        AX,word ptr [ESP + param_1]
//         00470a45     PUSH       EBX
//         00470a46     PUSH       EBP
//         00470a47     PUSH       ESI
//         00470a48     TEST       AX,AX
//         00470a4b     PUSH       EDI
//         00470a4c     MOV        EBX,this
//         00470a4e     JL         LAB_00470aac
//                              player.cpp:1609 (19)
//         00470a50     MOVSX      EDI,AX
//         00470a53     MOV        EAX,dword ptr [EBX + 0x24]
//         00470a56     SHL        EDI,0x2
//         00470a59     CMP        dword ptr [EAX + EDI*0x1],0x0
//         00470a5d     JZ         LAB_00470b2c
//                              player.cpp:1611 (11)
//         00470a63     MOV        EAX,dword ptr [EBX + 0x28]
//         00470a66     MOV        EBP,dword ptr [ESP + param_3]
//         00470a6a     TEST       EAX,EAX
//         00470a6c     JZ         LAB_00470a94
//                              player.cpp:1612 (7)
//         00470a6e     MOV        ESI,dword ptr [EAX + 0x4]
//         00470a71     TEST       ESI,ESI
//         00470a73     JZ         LAB_00470a94
//                               LAB_00470a75                                                 XREF[1]:     00470a92(j)
//                              player.cpp:1613 (13)
//         00470a75     MOV        this,dword ptr [ESI]
//         00470a77     MOV        EDX,dword ptr [EBX + 0x24]
//         00470a7a     MOV        EAX,dword ptr [ECX + this->pathingAttemptCapVa
//         00470a7d     CMP        EAX,dword ptr [EDX + EDI*0x1]
//         00470a80     JNZ        LAB_00470a8d
//                              player.cpp:1614 (18)
//         00470a82     MOV        EAX,dword ptr [ESP + param_4]
//         00470a86     MOV        EDX,dword ptr [this->_padding_]
//         00470a88     PUSH       EAX
//         00470a89     PUSH       EBP=>DAT_fffffff8
//         00470a8a     CALL       dword ptr [EDX + 0x50]
//                               LAB_00470a8d                                                 XREF[1]:     00470a80(j)
//         00470a8d     MOV        ESI,dword ptr [ESI + 0x4]
//         00470a90     TEST       ESI,ESI
//         00470a92     JNZ        LAB_00470a75
//                               LAB_00470a94                                                 XREF[2]:     00470a6c(j), 00470a73(j)
//                              player.cpp:1615 (17)
//         00470a94     MOV        this,dword ptr [EBX + 0x24]
//         00470a97     MOV        EAX,dword ptr [ESP + param_4]
//         00470a9b     PUSH       EAX
//         00470a9c     PUSH       EBP=>DAT_fffffff8
//         00470a9d     MOV        this,dword ptr [this->_padding_ + EDI*0x1]
//         00470aa0     MOV        EDX,dword ptr [this->_padding_]
//         00470aa2     CALL       dword ptr [EDX + 0x10]
//                              player.cpp:1630 (7)
//         00470aa5     POP        EDI
//         00470aa6     POP        ESI
//         00470aa7     POP        EBP
//         00470aa8     POP        EBX
//         00470aa9     RET        0x10
//                               LAB_00470aac                                                 XREF[1]:     00470a4e(j)
//                              player.cpp:1618 (8)
//         00470aac     CMP        word ptr [ESP + param_2],0x0
//         00470ab2     JL         LAB_00470b2c
//                              player.cpp:1620 (12)
//         00470ab4     XOR        this,this
//         00470ab6     CMP        word ptr [EBX + 0x22],this
//         00470aba     MOV        dword ptr [ESP + param_1],this
//         00470abe     JLE        LAB_00470b2c
//                              player.cpp:1621 (31)
//         00470ac0     MOV        EBP,dword ptr [ESP + param_3]
//                               LAB_00470ac4                                                 XREF[1]:     00470b2a(j)
//         00470ac4     MOV        EDX,dword ptr [EBX + 0x24]
//         00470ac7     MOVSX      ESI,this
//         00470aca     SHL        ESI,0x2
//         00470acd     MOV        EAX,dword ptr [EDX + ESI*0x1]
//         00470ad0     TEST       EAX,EAX
//         00470ad2     JZ         LAB_00470b21
//         00470ad4     MOV        DX,word ptr [ESP + param_2]
//         00470ad9     CMP        word ptr [EAX + 0x14],DX
//         00470add     JNZ        LAB_00470b21
//                              player.cpp:1623 (7)
//         00470adf     MOV        EAX,dword ptr [EBX + 0x28]
//         00470ae2     TEST       EAX,EAX
//         00470ae4     JZ         LAB_00470b0c
//                              player.cpp:1624 (7)
//         00470ae6     MOV        EDI,dword ptr [EAX + 0x4]
//         00470ae9     TEST       EDI,EDI
//         00470aeb     JZ         LAB_00470b0c
//                               LAB_00470aed                                                 XREF[1]:     00470b0a(j)
//                              player.cpp:1625 (13)
//         00470aed     MOV        this,dword ptr [EDI]
//         00470aef     MOV        EAX,dword ptr [EBX + 0x24]
//         00470af2     MOV        EDX,dword ptr [ECX + this->pathingAttemptCapVa
//         00470af5     CMP        EDX,dword ptr [EAX + ESI*0x1]
//         00470af8     JNZ        LAB_00470b05
//                              player.cpp:1626 (18)
//         00470afa     MOV        EDX,dword ptr [ESP + param_4]
//         00470afe     MOV        EAX,dword ptr [this->_padding_]
//         00470b00     PUSH       EDX
//         00470b01     PUSH       EBP=>DAT_fffffff8
//         00470b02     CALL       dword ptr [EAX + 0x50]
//                               LAB_00470b05                                                 XREF[1]:     00470af8(j)
//         00470b05     MOV        EDI,dword ptr [EDI + 0x4]
//         00470b08     TEST       EDI,EDI
//         00470b0a     JNZ        LAB_00470aed
//                               LAB_00470b0c                                                 XREF[2]:     00470ae4(j), 00470aeb(j)
//                              player.cpp:1627 (32)
//         00470b0c     MOV        EAX,dword ptr [EBX + 0x24]
//         00470b0f     MOV        this,dword ptr [EAX + ESI*0x1]
//         00470b12     MOV        EAX,dword ptr [ESP + 0x20]
//         00470b16     PUSH       EAX
//         00470b17     PUSH       EBP=>DAT_fffffff8
//         00470b18     MOV        EDX,dword ptr [this->_padding_]
//         00470b1a     CALL       dword ptr [EDX + 0x10]
//         00470b1d     MOV        this,dword ptr [ESP + 0x14]
//                               LAB_00470b21                                                 XREF[2]:     00470ad2(j), 00470add(j)
//         00470b21     INC        this
//         00470b22     CMP        this,word ptr [EBX + 0x22]
//         00470b26     MOV        dword ptr [ESP + 0x14],this
//         00470b2a     JL         LAB_00470ac4
//                               LAB_00470b2c                                                 XREF[3]:     00470a5d(j), 00470ab2(j),
//                                                                                                         00470abe(j)
//                              player.cpp:1630 (7)
//         00470b2c     POP        EDI
//         00470b2d     POP        ESI
//         00470b2e     POP        EBP
//         00470b2f     POP        EBX
//         00470b30     RET        0x10
//         00470b33     ??         90h
//         00470b34     NOP
//         00470b35     NOP
//         00470b36     NOP
//         00470b37     NOP
//         00470b38     NOP
//         00470b39     NOP
//         00470b3a     NOP
//         00470b3b     NOP
//         00470b3c     NOP
//         00470b3d     NOP
//         00470b3e     NOP
//         00470b3f     NOP
    return;
}

void RGE_Player::copy_obj(short param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Player * this, short param_1, short par
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00470b45(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00470b56(R)
//                               ?copy_obj@RGE_Player@@QAEXFF@Z                               XREF[1]:     do_effect:004496d7(c)
//                               RGE_Player::copy_obj
//                              player.cpp:1636 (5)
//         00470b40     PUSH       EBX
//         00470b41     PUSH       EBP
//         00470b42     PUSH       EDI
//         00470b43     MOV        EBX,this
//                              player.cpp:1639 (32)
//         00470b45     MOVSX      EDI,word ptr [ESP + param_1]
//         00470b4a     MOV        EAX,dword ptr [EBX + 0x24]
//         00470b4d     SHL        EDI,0x2
//         00470b50     CMP        dword ptr [EAX + EDI*0x1],0x0
//         00470b54     JZ         LAB_00470ba3
//         00470b56     MOVSX      EBP,word ptr [ESP + param_2]
//         00470b5b     SHL        EBP,0x2
//         00470b5e     CMP        dword ptr [EBP + EAX*0x1],0x0
//         00470b63     JZ         LAB_00470ba3
//                              player.cpp:1642 (8)
//         00470b65     MOV        EAX,dword ptr [EBX + 0x28]
//         00470b68     PUSH       ESI
//         00470b69     TEST       EAX,EAX
//         00470b6b     JZ         LAB_00470b92
//                              player.cpp:1643 (7)
//         00470b6d     MOV        ESI,dword ptr [EAX + 0x4]
//         00470b70     TEST       ESI,ESI
//         00470b72     JZ         LAB_00470b92
//                               LAB_00470b74                                                 XREF[1]:     00470b90(j)
//                              player.cpp:1644 (13)
//         00470b74     MOV        this,dword ptr [ESI]
//         00470b76     MOV        EAX,dword ptr [EBX + 0x24]
//         00470b79     MOV        EDX,dword ptr [ECX + this->pathingAttemptCapVa
//         00470b7c     CMP        EDX,dword ptr [EAX + EDI*0x1]
//         00470b7f     JNZ        LAB_00470b8b
//                              player.cpp:1645 (17)
//         00470b81     MOV        EAX,dword ptr [EBP + EAX*0x1]
//         00470b85     MOV        EDX,dword ptr [this->_padding_]
//         00470b87     PUSH       EAX
//         00470b88     CALL       dword ptr [EDX + 0x58]
//                               LAB_00470b8b                                                 XREF[1]:     00470b7f(j)
//         00470b8b     MOV        ESI,dword ptr [ESI + 0x4]
//         00470b8e     TEST       ESI,ESI
//         00470b90     JNZ        LAB_00470b74
//                               LAB_00470b92                                                 XREF[2]:     00470b6b(j), 00470b72(j)
//                              player.cpp:1647 (17)
//         00470b92     MOV        EBX,dword ptr [EBX + 0x24]
//         00470b95     MOV        this,dword ptr [EBX + EDI*0x1]
//         00470b98     MOV        EAX,dword ptr [EBP + EBX*0x1]
//         00470b9c     PUSH       EAX
//         00470b9d     MOV        EDX,dword ptr [this->_padding_]
//         00470b9f     CALL       dword ptr [EDX + 0x4]
//         00470ba2     POP        ESI
//                               LAB_00470ba3                                                 XREF[2]:     00470b54(j), 00470b63(j)
//                              player.cpp:1648 (6)
//         00470ba3     POP        EDI
//         00470ba4     POP        EBP
//         00470ba5     POP        EBX
//         00470ba6     RET        0x8
//         00470ba9     ??         90h
//         00470baa     NOP
//         00470bab     NOP
//         00470bac     NOP
//         00470bad     NOP
//         00470bae     NOP
//         00470baf     NOP
    return;
}

void RGE_Player::set_allied_victory(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_allied_victory(RGE_Player * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00470bb0(R)
//                               ?set_allied_victory@RGE_Player@@QAEXE@Z                      XREF[4]:     do_command_game:0050a21d(c),
//                               RGE_Player::set_allied_victory                                            SaveAttributesIntoPlayers:0052bb8e
//                                                                                                         new_game:005429b7(c),
//                                                                                                         new_game:00542a86(c)
//                              player.cpp:1652 (10)
//         00470bb0     MOV        AL,byte ptr [ESP + param_1]
//         00470bb4     MOV        byte ptr [ECX + this->allied_victory],AL
//                              player.cpp:1654 (3)
//         00470bba     RET        0x4
//         00470bbd     ??         90h
//         00470bbe     NOP
//         00470bbf     NOP
    return;
}

uchar RGE_Player::get_allied_victory() {
    /* TODO: Stub */
//                              uchar __thiscall get_allied_victory(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?get_allied_victory@RGE_Player@@QAEEXZ                       XREF[2]:     TribeDiplomacyDialog:0043d241(c),
//                               RGE_Player::get_allied_victory                                            action:0043d8f8(c)
//                              player.cpp:1658 (6)
//         00470bc0     MOV        AL,byte ptr [ECX + this->allied_victory]
//                              player.cpp:1660 (1)
//         00470bc6     RET
//         00470bc7     ??         90h
//         00470bc8     NOP
//         00470bc9     NOP
//         00470bca     NOP
//         00470bcb     NOP
//         00470bcc     NOP
//         00470bcd     NOP
//         00470bce     NOP
//         00470bcf     NOP
    return 0;
}

uchar RGE_Player::relation(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall relation(RGE_Player * this, long param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00470bd6(R)
//                               ?relation@RGE_Player@@QAEEJ@Z                                XREF[30]:    TribeDiplomacyDialog:0043cfff(c),
//                               RGE_Player::relation                                                      action:0043d9b8(c),
//                                                                                                         win_game_now:0047062c(c),
//                                                                                                         win_game_now:00470643(c),
//                                                                                                         check_ally_group:004706f9(c),
//                                                                                                         add_land_module:00483e2f(c),
//                                                                                                         reset_clocks:0049ae85(c),
//                                                                                                         reset_clocks:0049ae9b(c),
//                                                                                                         reset_clocks:0049af41(c),
//                                                                                                         reset_clocks:0049af57(c),
//                                                                                                         reset_score_display:0049b1a8(c),
//                                                                                                         reset_score_display:0049b1c5(c),
//                                                                                                         check_task:00509370(c),
//                                                                                                         check_game_state:005304c1(c),
//                                                                                                         check_game_state:005304d1(c),
//                                                                                                         check_game_state:00530632(c),
//                                                                                                         check_game_state:0053064a(c),
//                                                                                                         fill_in_score:0053130a(c),
//                                                                                                         fill_in_score:0053131a(c),
//                                                                                                         check_game_state:00543430(c),
//                                                                                                         [more]
//                              player.cpp:1664 (13)
//         00470bd0     MOV        EAX,dword ptr [ECX + this->relations]
//         00470bd6     MOV        this,dword ptr [ESP + param_1]
//         00470bda     MOV        AL,byte ptr [EAX + this->_padding_*0x1]
//                              player.cpp:1666 (3)
//         00470bdd     RET        0x4
    return 0;
}

void RGE_Player::set_relation(long param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall set_relation(RGE_Player * this, long param_1, uchar
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00470bed(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00470be7(R)
//                               ?set_relation@RGE_Player@@QAEXJE@Z                           XREF[5]:     do_command_game:0050a242(c),
//                               RGE_Player::set_relation                                                  TRIBE_Player:00512001(c),
//                                                                                                         SaveAttributesIntoPlayers:0052bb6d
//                                                                                                         new_game:005429aa(c),
//                                                                                                         new_game:00542a79(c)
//                              player.cpp:1670 (17)
//         00470be0     MOV        EAX,dword ptr [ECX + this->relations]
//         00470be6     PUSH       EBX
//         00470be7     MOV        EBX,dword ptr [ESP + param_2]
//         00470beb     PUSH       ESI
//         00470bec     PUSH       EDI
//         00470bed     MOV        EDI,dword ptr [ESP + param_1]
//                              player.cpp:1679 (7)
//         00470bf1     TEST       EDI,EDI
//         00470bf3     MOV        byte ptr [EAX + EDI*0x1],BL
//         00470bf6     JNZ        LAB_00470c00
//                              player.cpp:1680 (6)
//         00470bf8     MOV        dword ptr [ECX + this->unitDiplomacy[0]],EDI
//                              player.cpp:1681 (10)
//         00470bfe     JMP        LAB_00470c43
//                               LAB_00470c00                                                 XREF[1]:     00470bf6(j)
//         00470c00     MOVSX      EDX,word ptr [ECX + this->id]
//         00470c04     CMP        EDI,EDX
//         00470c06     JNZ        LAB_00470c15
//                              player.cpp:1682 (11)
//         00470c08     MOV        dword ptr [ECX + EDI*0x4 + this->unitDiplomacy
//                              player.cpp:1683 (6)
//         00470c13     JMP        LAB_00470c43
//                               LAB_00470c15                                                 XREF[1]:     00470c06(j)
//         00470c15     TEST       BL,BL
//         00470c17     JNZ        LAB_00470c26
//                              player.cpp:1684 (11)
//         00470c19     MOV        dword ptr [ECX + EDI*0x4 + this->unitDiplomacy
//                              player.cpp:1685 (7)
//         00470c24     JMP        LAB_00470c43
//                               LAB_00470c26                                                 XREF[1]:     00470c17(j)
//         00470c26     CMP        BL,0x1
//         00470c29     JNZ        LAB_00470c38
//                              player.cpp:1686 (11)
//         00470c2b     MOV        dword ptr [ECX + EDI*0x4 + this->unitDiplomacy
//                              player.cpp:1687 (2)
//         00470c36     JMP        LAB_00470c43
//                               LAB_00470c38                                                 XREF[1]:     00470c29(j)
//                              player.cpp:1688 (11)
//         00470c38     MOV        dword ptr [ECX + EDI*0x4 + this->unitDiplomacy
//                               LAB_00470c43                                                 XREF[4]:     00470bfe(j), 00470c13(j),
//                                                                                                         00470c24(j), 00470c36(j)
//                              player.cpp:1693 (10)
//         00470c43     MOV        EAX,dword ptr [ECX + this->objects]
//         00470c46     MOV        ESI,dword ptr [EAX + 0x4]
//         00470c49     TEST       ESI,ESI
//         00470c4b     JZ         LAB_00470c60
//                               LAB_00470c4d                                                 XREF[1]:     00470c5e(j)
//                              player.cpp:1694 (19)
//         00470c4d     MOV        this,dword ptr [ESI]
//         00470c4f     PUSH       EBX
//         00470c50     PUSH       EDI
//         00470c51     MOV        EDX,dword ptr [this->_padding_]
//         00470c53     CALL       dword ptr [EDX + 0x94]
//         00470c59     MOV        ESI,dword ptr [ESI + 0x4]
//         00470c5c     TEST       ESI,ESI
//         00470c5e     JNZ        LAB_00470c4d
//                               LAB_00470c60                                                 XREF[1]:     00470c4b(j)
//                              player.cpp:1734 (6)
//         00470c60     POP        EDI
//         00470c61     POP        ESI
//         00470c62     POP        EBX
//         00470c63     RET        0x8
//         00470c66     ??         90h
//         00470c67     NOP
//         00470c68     NOP
//         00470c69     NOP
//         00470c6a     NOP
//         00470c6b     NOP
//         00470c6c     NOP
//         00470c6d     NOP
//         00470c6e     NOP
//         00470c6f     NOP
    return;
}

RGE_Static_Object* RGE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_object(RGE_Player * this, lo
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00470c70(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     00470c8f(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00470c8a(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00470c83(R)
//              int               Stack[0x14]:4  param_5
//                               ?make_new_object@RGE_Player@@UAEPAVRGE_Static_Object@@JMMMH@Z XREF[2]:     make_new_object:00512f81(c),
//                               RGE_Player::make_new_object                                               00570f64(*)
//                              player.cpp:1739 (19)
//         00470c70     MOV        EAX,dword ptr [ESP + param_1]
//         00470c74     PUSH       ESI
//         00470c75     TEST       EAX,EAX
//         00470c77     JL         LAB_00470c9e
//         00470c79     MOV        EDX,dword ptr [ECX + this->master_objects]
//         00470c7c     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         00470c7f     TEST       EAX,EAX
//         00470c81     JZ         LAB_00470c9e
//                              player.cpp:1741 (23)
//         00470c83     MOV        ESI,dword ptr [ESP + param_4]
//         00470c87     MOV        EDX,dword ptr [EAX]
//         00470c89     PUSH       ESI
//         00470c8a     MOV        ESI,dword ptr [ESP + param_3]
//         00470c8e     PUSH       ESI
//         00470c8f     MOV        ESI,dword ptr [ESP + param_2]
//         00470c93     PUSH       ESI
//         00470c94     PUSH       this
//         00470c95     MOV        this,EAX
//         00470c97     CALL       dword ptr [EDX + 0x18]
//                              player.cpp:1744 (4)
//         00470c9a     POP        ESI
//         00470c9b     RET        0x14
//                               LAB_00470c9e                                                 XREF[2]:     00470c77(j), 00470c81(j)
//                              player.cpp:1743 (2)
//         00470c9e     XOR        EAX,EAX
//                              player.cpp:1744 (4)
//         00470ca0     POP        ESI
//         00470ca1     RET        0x14
//         00470ca4     ??         90h
//         00470ca5     NOP
//         00470ca6     NOP
//         00470ca7     NOP
//         00470ca8     NOP
//         00470ca9     NOP
//         00470caa     NOP
//         00470cab     NOP
//         00470cac     NOP
//         00470cad     NOP
//         00470cae     NOP
//         00470caf     NOP
    return 0;
}

void RGE_Player::reset_selected() {
    /* TODO: Stub */
//                              void __thiscall reset_selected(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?reset_selected@RGE_Player@@QAEXXZ                           XREF[3]:     RGE_Player:0046e52a(c),
//                               RGE_Player::reset_selected                                                RGE_Player:0046e7f6(c),
//                                                                                                         action:004ac720(c)
//                              player.cpp:1748 (2)
//         00470cb0     MOV        EDX,this
//                              player.cpp:1751 (4)
//         00470cb2     OR         EAX,0xffffffff
//         00470cb5     PUSH       EDI
//                              player.cpp:1763 (77)
//         00470cb6     MOV        this,0x19
//         00470cbb     MOV        word ptr [EDX + 0x120],AX
//         00470cc2     MOV        word ptr [EDX + 0x122],AX
//         00470cc9     MOV        word ptr [EDX + 0x124],AX
//         00470cd0     MOV        word ptr [EDX + 0x126],AX
//         00470cd7     MOV        word ptr [EDX + 0x128],AX
//         00470cde     MOV        word ptr [EDX + 0x12a],AX
//         00470ce5     MOV        word ptr [EDX + 0x12c],AX
//         00470cec     XOR        EAX,EAX
//         00470cee     LEA        EDI,[EDX + 0x134]
//         00470cf4     MOV        word ptr [EDX + 0x19c],AX
//         00470cfb     MOV        dword ptr [EDX + 0x130],EAX
//         00470d01     STOSD.REP  ES:EDI
//                              player.cpp:1767 (18)
//         00470d03     LEA        EDI,[EDX + 0x19e]
//         00470d09     MOV        this,0x1f
//         00470d0e     STOSD.REP  ES:EDI
//         00470d10     STOSW      ES:EDI
//         00470d12     STOSB      ES:EDI
//         00470d13     POP        EDI
//         00470d14     RET
//         00470d15     ??         90h
//         00470d16     NOP
//         00470d17     NOP
//         00470d18     NOP
//         00470d19     NOP
//         00470d1a     NOP
//         00470d1b     NOP
//         00470d1c     NOP
//         00470d1d     NOP
//         00470d1e     NOP
//         00470d1f     NOP
    return;
}

int RGE_Player::select_object(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall select_object(RGE_Player * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00470d21(R)
//                               ?select_object@RGE_Player@@QAEHPAVRGE_Static_Object@@@Z      XREF[6]:     command_select_building:0049cd8e(c
//                               RGE_Player::select_object                                                 command_view_tribe:0049d152(c),
//                                                                                                         mouse_left_up_action:0053eb27(c),
//                                                                                                         mouse_left_up_action:0053ee2a(c),
//                                                                                                         mouse_left_up_action:0053f02b(c),
//                                                                                                         mouse_left_up_action:0053f0a8(c)
//                              player.cpp:1771 (1)
//         00470d20     PUSH       EBP
//                              player.cpp:1776 (19)
//         00470d21     MOV        EBP,dword ptr [ESP + param_1]
//         00470d25     PUSH       EDI
//         00470d26     PUSH       0x1
//         00470d28     MOV        EDI,this
//         00470d2a     PUSH       EBP
//         00470d2b     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00470d30     TEST       EAX,EAX
//         00470d32     JNZ        LAB_00470d39
//                              player.cpp:1799 (5)
//         00470d34     POP        EDI
//         00470d35     POP        EBP
//         00470d36     RET        0x4
//                               LAB_00470d39                                                 XREF[1]:     00470d32(j)
//                              player.cpp:1771 (1)
//         00470d39     PUSH       EBX
//                              player.cpp:1780 (3)
//         00470d3a     MOV        BL,byte ptr [EBP + 0x37]
//                              player.cpp:1781 (5)
//         00470d3d     CMP        BL,0xa
//         00470d40     JBE        LAB_00470d6e
//                              player.cpp:1783 (11)
//         00470d42     MOV        EAX,dword ptr [EDI + 0x28]
//         00470d45     PUSH       ESI
//         00470d46     MOV        ESI,dword ptr [EAX + 0x4]
//         00470d49     TEST       ESI,ESI
//         00470d4b     JZ         LAB_00470d6d
//                               LAB_00470d4d                                                 XREF[1]:     00470d6b(j)
//                              player.cpp:1785 (2)
//         00470d4d     MOV        EAX,dword ptr [ESI]
//                              player.cpp:1786 (9)
//         00470d4f     CMP        EAX,EBP
//         00470d51     JZ         LAB_00470d66
//         00470d53     CMP        byte ptr [EAX + 0x37],BL
//         00470d56     JNZ        LAB_00470d66
//                              player.cpp:1788 (14)
//         00470d58     PUSH       0x0
//         00470d5a     PUSH       EAX
//         00470d5b     MOV        this,EDI
//         00470d5d     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00470d62     TEST       EAX,EAX
//         00470d64     JZ         LAB_00470d6d
//                               LAB_00470d66                                                 XREF[2]:     00470d51(j), 00470d56(j)
//                              player.cpp:1783 (7)
//         00470d66     MOV        ESI,dword ptr [ESI + 0x4]
//         00470d69     TEST       ESI,ESI
//         00470d6b     JNZ        LAB_00470d4d
//                               LAB_00470d6d                                                 XREF[2]:     00470d4b(j), 00470d64(j)
//                              player.cpp:1771 (1)
//         00470d6d     POP        ESI
//                               LAB_00470d6e                                                 XREF[1]:     00470d40(j)
//                              player.cpp:1796 (7)
//         00470d6e     MOV        dword ptr [EDI + 0x130],EBP
//         00470d74     POP        EBX
//                              player.cpp:1799 (10)
//         00470d75     POP        EDI
//         00470d76     MOV        EAX,0x1
//         00470d7b     POP        EBP
//         00470d7c     RET        0x4
//         00470d7f     ??         90h
    return 0;
}

int RGE_Player::select_one_object(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall select_one_object(RGE_Player * this, RGE_Static_Objec
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00470dd0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00470dde(R)
//                               ?select_one_object@RGE_Player@@QAEHPAVRGE_Static_Object@@H@Z XREF[23]:    select_object:00470d2b(c),
//                               RGE_Player::select_one_object                                             select_object:00470d5d(c),
//                                                                                                         select_group:004710e9(c),
//                                                                                                         select_group:004710fb(c),
//                                                                                                         action:004abd1f(c),
//                                                                                                         action:004abd3e(c),
//                                                                                                         action:004abe27(c),
//                                                                                                         action:004abe46(c),
//                                                                                                         action:004ac257(c),
//                                                                                                         action:004ac2bf(c),
//                                                                                                         action:004ac482(c),
//                                                                                                         action:004ac4a1(c),
//                                                                                                         mouse_left_dbl_click_action:0052de
//                                                                                                         mouse_left_dbl_click_action:0052df
//                                                                                                         mouse_left_dbl_click_action:0052df
//                                                                                                         pick_multi:00535af2(c),
//                                                                                                         pick_multi:00535c52(c),
//                                                                                                         hit_object:00539fa1(c),
//                                                                                                         mouse_left_down_action:0053e3fb(c)
//                                                                                                         mouse_left_up_action:0053eb19(c),
//                                                                                                         [more]
//                              player.cpp:1803 (5)
//         00470d80     MOV        EAX,this
//         00470d82     PUSH       EBX
//         00470d83     PUSH       ESI
//         00470d84     PUSH       EDI
//                              player.cpp:1807 (17)
//         00470d85     MOV        DX,word ptr [EAX + 0x19c]
//         00470d8c     CMP        DX,0x19
//         00470d90     JGE        LAB_00470e21
//                              player.cpp:1811 (17)
//         00470d96     MOVSX      this,DX
//         00470d99     OR         ESI,0xffffffff
//         00470d9c     MOV        EDI,dword ptr [EAX + this->_padding_*0x4 + 0x1
//         00470da3     TEST       EDI,EDI
//         00470da5     JNZ        LAB_00470dab
//                              player.cpp:1812 (2)
//         00470da7     MOV        ESI,EDX
//                              player.cpp:1813 (2)
//         00470da9     JMP        LAB_00470dca
//                               LAB_00470dab                                                 XREF[1]:     00470da5(j)
//                              player.cpp:1815 (7)
//         00470dab     XOR        this,this
//         00470dad     TEST       DX,DX
//         00470db0     JLE        LAB_00470dca
//                               LAB_00470db2                                                 XREF[1]:     00470dc4(j)
//                              player.cpp:1817 (22)
//         00470db2     MOVSX      EDI,this
//         00470db5     MOV        EBX,dword ptr [EAX + EDI*0x4 + 0x134]
//         00470dbc     TEST       EBX,EBX
//         00470dbe     JZ         LAB_00470dc8
//         00470dc0     INC        this
//         00470dc1     CMP        this,DX
//         00470dc4     JL         LAB_00470db2
//         00470dc6     JMP        LAB_00470dca
//                               LAB_00470dc8                                                 XREF[1]:     00470dbe(j)
//                              player.cpp:1819 (2)
//         00470dc8     MOV        ESI,this
//                               LAB_00470dca                                                 XREF[3]:     00470da9(j), 00470db0(j),
//                                                                                                         00470dc6(j)
//                              player.cpp:1825 (6)
//         00470dca     CMP        SI,-0x1
//         00470dce     JZ         LAB_00470e21
//                              player.cpp:1828 (14)
//         00470dd0     MOV        EDX,dword ptr [ESP + param_1]
//         00470dd4     MOVSX      this,SI
//         00470dd7     MOV        dword ptr [EAX + this->_padding_*0x4 + 0x134],
//                              player.cpp:1834 (49)
//         00470dde     MOV        this,dword ptr [ESP + param_2]
//         00470de2     INC        word ptr [EAX + 0x19c]
//         00470de9     MOV        dword ptr [EAX + 0x130],EDX
//         00470def     TEST       this,this
//         00470df1     MOV        byte ptr [EDX + 0x36],0x1
//         00470df5     JZ         LAB_00470e16
//         00470df7     MOV        this,dword ptr [EDX + 0x8]
//         00470dfa     MOV        this,dword ptr [ECX + this->world]
//         00470dfd     TEST       this,this
//         00470dff     JZ         LAB_00470e16
//         00470e01     MOV        EDX,dword ptr [EDX + 0xc]
//         00470e04     CMP        EDX,EAX
//         00470e06     JZ         LAB_00470e0f
//         00470e08     CMP        word ptr [EDX + 0x4a],0x0
//         00470e0d     JNZ        LAB_00470e16
//                               LAB_00470e0f                                                 XREF[1]:     00470e06(j)
//                              player.cpp:1835 (7)
//         00470e0f     PUSH       0x1
//         00470e11     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_00470e16                                                 XREF[3]:     00470df5(j), 00470dff(j),
//                                                                                                         00470e0d(j)
//                              player.cpp:1837 (5)
//         00470e16     MOV        EAX,0x1
//                              player.cpp:1842 (14)
//         00470e1b     POP        EDI
//         00470e1c     POP        ESI
//         00470e1d     POP        EBX
//         00470e1e     RET        0x8
//                               LAB_00470e21                                                 XREF[2]:     00470d90(j), 00470dce(j)
//         00470e21     POP        EDI
//         00470e22     POP        ESI
//         00470e23     XOR        EAX,EAX
//         00470e25     POP        EBX
//         00470e26     RET        0x8
//         00470e29     ??         90h
//         00470e2a     NOP
//         00470e2b     NOP
//         00470e2c     NOP
//         00470e2d     NOP
//         00470e2e     NOP
//         00470e2f     NOP
    return 0;
}

void RGE_Player::unselect_object() {
    /* TODO: Stub */
//                              void __thiscall unselect_object(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?unselect_object@RGE_Player@@QAEXXZ                          XREF[36]:    action:0048a21e(c),
//                               RGE_Player::unselect_object                                               game_mode_changed:0048a549(c),
//                                                                                                         game_mode_changed:0048a5cb(c),
//                                                                                                         command_select_group:0049c737(c),
//                                                                                                         command_player:0049ca2f(c),
//                                                                                                         command_select_building:0049cd7b(c
//                                                                                                         command_unselect:0049d05f(c),
//                                                                                                         command_view_tribe:0049d13f(c),
//                                                                                                         set_scenario_mode:004aa179(c),
//                                                                                                         set_player:004aae41(c),
//                                                                                                         action:004abde4(c),
//                                                                                                         action:004ac1ac(c),
//                                                                                                         action:004ac1cd(c),
//                                                                                                         command_cancel:004ad24d(c),
//                                                                                                         processCheatCode:005281b6(c),
//                                                                                                         mouse_left_dbl_click_action:0052de
//                                                                                                         start_scroll_view:0053a204(c),
//                                                                                                         mouse_right_up_action:0053d884(c),
//                                                                                                         mouse_left_up_action:0053eaff(c),
//                                                                                                         mouse_right_down_action:0053f28e(c
//                                                                                                         [more]
//                              player.cpp:1846 (1)
//         00470e30     PUSH       EBX
//                              player.cpp:1849 (13)
//         00470e31     XOR        EBX,EBX
//         00470e33     CMP        word ptr [ECX + this->sel_count],BX
//         00470e3a     JLE        LAB_00470e7c
//         00470e3c     PUSH       EDI
//         00470e3d     PUSH       ESI
//                              player.cpp:1853 (19)
//         00470e3e     XOR        ESI,ESI
//         00470e40     MOV        dword ptr [ECX + this->selected_obj],EBX
//         00470e46     XOR        EDI,EDI
//                               LAB_00470e48                                                 XREF[1]:     00470e71(j)
//         00470e48     CMP        DI,word ptr [ECX + this->sel_count]
//         00470e4f     JGE        LAB_00470e73
//                              player.cpp:1855 (21)
//         00470e51     MOVSX      EAX,SI
//         00470e54     MOV        EDX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         00470e5b     LEA        EAX,[ECX + EAX*0x4 + this->sel_list[0]]
//         00470e62     CMP        EDX,EBX
//         00470e64     JZ         LAB_00470e6c
//                              player.cpp:1858 (4)
//         00470e66     MOV        byte ptr [EDX + 0x36],BL
//         00470e69     INC        EDI
//                              player.cpp:1859 (9)
//         00470e6a     MOV        dword ptr [EAX],EBX
//                               LAB_00470e6c                                                 XREF[1]:     00470e64(j)
//         00470e6c     INC        ESI
//         00470e6d     CMP        SI,0x19
//         00470e71     JL         LAB_00470e48
//                               LAB_00470e73                                                 XREF[1]:     00470e4f(j)
//                              player.cpp:1846 (1)
//         00470e73     POP        ESI
//                              player.cpp:1863 (8)
//         00470e74     MOV        word ptr [ECX + this->sel_count],BX
//         00470e7b     POP        EDI
//                               LAB_00470e7c                                                 XREF[1]:     00470e3a(j)
//                              player.cpp:1865 (2)
//         00470e7c     POP        EBX
//         00470e7d     RET
//         00470e7e     ??         90h
//         00470e7f     NOP
    return;
}

void RGE_Player::unselect_one_object(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall unselect_one_object(RGE_Player * this, short param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00470ed0(R)
//                               ?unselect_one_object@RGE_Player@@QAEXF@Z                     XREF[2]:     unselect_one_object:00470ebd(c),
//                               RGE_Player::unselect_one_object                                           update_selected:00471465(c)
//                              player.cpp:1892 (14)
//         00470ed0     MOVSX      EAX,word ptr [ESP + param_1]
//         00470ed5     PUSH       EBX
//         00470ed6     PUSH       ESI
//         00470ed7     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->sel_list[
//                              player.cpp:1897 (11)
//         00470ede     XOR        EBX,EBX
//         00470ee0     CMP        ESI,EBX
//         00470ee2     PUSH       EDI
//         00470ee3     JZ         LAB_00470f6d
//                              player.cpp:1900 (3)
//         00470ee9     MOV        byte ptr [ESI + 0x36],BL
//                              player.cpp:1902 (14)
//         00470eec     MOVSX      EDX,word ptr [ECX + this->sel_count]
//         00470ef3     LEA        EDI,[EDX + -0x1]
//         00470ef6     CMP        EAX,EDI
//         00470ef8     JL         LAB_00470f03
//                              player.cpp:1903 (7)
//         00470efa     MOV        dword ptr [ECX + EAX*0x4 + this->sel_list[0]],
//                              player.cpp:1904 (2)
//         00470f01     JMP        LAB_00470f1f
//                               LAB_00470f03                                                 XREF[1]:     00470ef8(j)
//                              player.cpp:1906 (14)
//         00470f03     MOV        EDX,dword ptr [ECX + EDX*0x4 + this->selected_
//         00470f0a     MOV        dword ptr [ECX + EAX*0x4 + this->sel_list[0]],
//                              player.cpp:1907 (14)
//         00470f11     MOVSX      EAX,word ptr [ECX + this->sel_count]
//         00470f18     MOV        dword ptr [ECX + EAX*0x4 + this->selected_obj]
//                               LAB_00470f1f                                                 XREF[1]:     00470f01(j)
//                              player.cpp:1912 (24)
//         00470f1f     MOV        EDX,dword ptr [ECX + this->selected_obj]
//         00470f25     DEC        word ptr [ECX + this->sel_count]
//         00470f2c     MOV        AX,word ptr [ECX + this->sel_count]
//         00470f33     CMP        EDX,ESI
//         00470f35     JNZ        LAB_00470f6d
//                              player.cpp:1915 (11)
//         00470f37     CMP        AX,BX
//         00470f3a     MOV        dword ptr [ECX + this->selected_obj],EBX
//         00470f40     JLE        LAB_00470f6d
//                              player.cpp:1917 (2)
//         00470f42     XOR        EAX,EAX
//                               LAB_00470f44                                                 XREF[1]:     00470f55(j)
//                              player.cpp:1919 (19)
//         00470f44     MOVSX      EDX,AX
//         00470f47     CMP        dword ptr [ECX + EDX*0x4 + this->sel_list[0]],
//         00470f4e     JNZ        LAB_00470f5d
//         00470f50     INC        EAX
//         00470f51     CMP        AX,0x19
//         00470f55     JL         LAB_00470f44
//                              player.cpp:1927 (6)
//         00470f57     POP        EDI
//         00470f58     POP        ESI
//         00470f59     POP        EBX
//         00470f5a     RET        0x4
//                               LAB_00470f5d                                                 XREF[1]:     00470f4e(j)
//                              player.cpp:1921 (16)
//         00470f5d     MOVSX      EAX,AX
//         00470f60     MOV        EDX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         00470f67     MOV        dword ptr [ECX + this->selected_obj],EDX
//                               LAB_00470f6d                                                 XREF[3]:     00470ee3(j), 00470f35(j),
//                                                                                                         00470f40(j)
//                              player.cpp:1927 (6)
//         00470f6d     POP        EDI
//         00470f6e     POP        ESI
//         00470f6f     POP        EBX
//         00470f70     RET        0x4
//         00470f73     ??         90h
//         00470f74     NOP
//         00470f75     NOP
//         00470f76     NOP
//         00470f77     NOP
//         00470f78     NOP
//         00470f79     NOP
//         00470f7a     NOP
//         00470f7b     NOP
//         00470f7c     NOP
//         00470f7d     NOP
//         00470f7e     NOP
//         00470f7f     NOP
    return;
}

void RGE_Player::unselect_one_object(short param_1) {
    /* TODO: Stub */
//                              void __thiscall unselect_one_object(RGE_Player * this, short param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00470ed0(R)
//                               ?unselect_one_object@RGE_Player@@QAEXF@Z                     XREF[2]:     unselect_one_object:00470ebd(c),
//                               RGE_Player::unselect_one_object                                           update_selected:00471465(c)
//                              player.cpp:1892 (14)
//         00470ed0     MOVSX      EAX,word ptr [ESP + param_1]
//         00470ed5     PUSH       EBX
//         00470ed6     PUSH       ESI
//         00470ed7     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->sel_list[
//                              player.cpp:1897 (11)
//         00470ede     XOR        EBX,EBX
//         00470ee0     CMP        ESI,EBX
//         00470ee2     PUSH       EDI
//         00470ee3     JZ         LAB_00470f6d
//                              player.cpp:1900 (3)
//         00470ee9     MOV        byte ptr [ESI + 0x36],BL
//                              player.cpp:1902 (14)
//         00470eec     MOVSX      EDX,word ptr [ECX + this->sel_count]
//         00470ef3     LEA        EDI,[EDX + -0x1]
//         00470ef6     CMP        EAX,EDI
//         00470ef8     JL         LAB_00470f03
//                              player.cpp:1903 (7)
//         00470efa     MOV        dword ptr [ECX + EAX*0x4 + this->sel_list[0]],
//                              player.cpp:1904 (2)
//         00470f01     JMP        LAB_00470f1f
//                               LAB_00470f03                                                 XREF[1]:     00470ef8(j)
//                              player.cpp:1906 (14)
//         00470f03     MOV        EDX,dword ptr [ECX + EDX*0x4 + this->selected_
//         00470f0a     MOV        dword ptr [ECX + EAX*0x4 + this->sel_list[0]],
//                              player.cpp:1907 (14)
//         00470f11     MOVSX      EAX,word ptr [ECX + this->sel_count]
//         00470f18     MOV        dword ptr [ECX + EAX*0x4 + this->selected_obj]
//                               LAB_00470f1f                                                 XREF[1]:     00470f01(j)
//                              player.cpp:1912 (24)
//         00470f1f     MOV        EDX,dword ptr [ECX + this->selected_obj]
//         00470f25     DEC        word ptr [ECX + this->sel_count]
//         00470f2c     MOV        AX,word ptr [ECX + this->sel_count]
//         00470f33     CMP        EDX,ESI
//         00470f35     JNZ        LAB_00470f6d
//                              player.cpp:1915 (11)
//         00470f37     CMP        AX,BX
//         00470f3a     MOV        dword ptr [ECX + this->selected_obj],EBX
//         00470f40     JLE        LAB_00470f6d
//                              player.cpp:1917 (2)
//         00470f42     XOR        EAX,EAX
//                               LAB_00470f44                                                 XREF[1]:     00470f55(j)
//                              player.cpp:1919 (19)
//         00470f44     MOVSX      EDX,AX
//         00470f47     CMP        dword ptr [ECX + EDX*0x4 + this->sel_list[0]],
//         00470f4e     JNZ        LAB_00470f5d
//         00470f50     INC        EAX
//         00470f51     CMP        AX,0x19
//         00470f55     JL         LAB_00470f44
//                              player.cpp:1927 (6)
//         00470f57     POP        EDI
//         00470f58     POP        ESI
//         00470f59     POP        EBX
//         00470f5a     RET        0x4
//                               LAB_00470f5d                                                 XREF[1]:     00470f4e(j)
//                              player.cpp:1921 (16)
//         00470f5d     MOVSX      EAX,AX
//         00470f60     MOV        EDX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         00470f67     MOV        dword ptr [ECX + this->selected_obj],EDX
//                               LAB_00470f6d                                                 XREF[3]:     00470ee3(j), 00470f35(j),
//                                                                                                         00470f40(j)
//                              player.cpp:1927 (6)
//         00470f6d     POP        EDI
//         00470f6e     POP        ESI
//         00470f6f     POP        EBX
//         00470f70     RET        0x4
//         00470f73     ??         90h
//         00470f74     NOP
//         00470f75     NOP
//         00470f76     NOP
//         00470f77     NOP
//         00470f78     NOP
//         00470f79     NOP
//         00470f7a     NOP
//         00470f7b     NOP
//         00470f7c     NOP
//         00470f7d     NOP
//         00470f7e     NOP
//         00470f7f     NOP
    return;
}

int RGE_Player::group_objects(int param_1) {
    /* TODO: Stub */
//                              int __thiscall group_objects(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00470f97(R), 00470fbe(R), 00470ffd(W), 00471003(R)
//                               ?group_objects@RGE_Player@@QAEHH@Z                           XREF[2]:     command_group:0049c55e(c),
//                               RGE_Player::group_objects                                                 command_group_by_number:0049c59a(c
//                              player.cpp:1933 (5)
//         00470f80     MOV        EDX,this
//         00470f82     PUSH       EBX
//         00470f83     PUSH       ESI
//         00470f84     PUSH       EDI
//                              player.cpp:1939 (10)
//         00470f85     CMP        word ptr [EDX + 0x19c],0x0
//         00470f8d     JNZ        LAB_00470f97
//                              player.cpp:1940 (2)
//         00470f8f     XOR        EAX,EAX
//                              player.cpp:2009 (6)
//         00470f91     POP        EDI
//         00470f92     POP        ESI
//         00470f93     POP        EBX
//         00470f94     RET        0x4
//                               LAB_00470f97                                                 XREF[1]:     00470f8d(j)
//                              player.cpp:1943 (13)
//         00470f97     MOV        this,dword ptr [ESP + param_1]
//         00470f9b     CMP        this,-0x1
//         00470f9e     JNZ        LAB_0047105d
//                              player.cpp:1945 (5)
//         00470fa4     MOV        EAX,0xb
//                               LAB_00470fa9                                                 XREF[1]:     00470fbc(j)
//                              player.cpp:1947 (21)
//         00470fa9     MOVSX      this,AX
//         00470fac     MOV        BL,byte ptr [EDX + this->_padding_*0x1 + 0x19e]
//         00470fb3     TEST       BL,BL
//         00470fb5     JZ         LAB_00470fc4
//         00470fb7     INC        EAX
//         00470fb8     CMP        AX,0x7f
//         00470fbc     JL         LAB_00470fa9
//                              player.cpp:1950 (19)
//         00470fbe     MOV        BL,byte ptr [ESP + param_1]
//         00470fc2     JMP        LAB_00470fd1
//                               LAB_00470fc4                                                 XREF[1]:     00470fb5(j)
//         00470fc4     MOVSX      this,AX
//         00470fc7     MOV        BL,AL
//         00470fc9     MOV        byte ptr [EDX + this->_padding_*0x1 + 0x19e],0x1
//                               LAB_00470fd1                                                 XREF[1]:     00470fc2(j)
//                              player.cpp:1955 (10)
//         00470fd1     CMP        AX,0x7f
//         00470fd5     JNZ        LAB_0047107b
//                              player.cpp:2009 (27)
//         00470fdb     LEA        EDI,[EDX + 0x19f]
//         00470fe1     MOV        this,0x1f
//         00470fe6     XOR        EAX,EAX
//         00470fe8     STOSD.REP  ES:EDI
//         00470fea     STOSW      ES:EDI
//         00470fec     MOV        EAX,dword ptr [EDX + 0x28]
//         00470fef     MOV        this,dword ptr [EAX + 0x4]
//         00470ff2     TEST       this,this
//         00470ff4     JZ         LAB_00471027
//                               LAB_00470ff6                                                 XREF[1]:     00471025(j)
//                              player.cpp:1963 (5)
//         00470ff6     MOV        EAX,dword ptr [this->_padding_]
//         00470ff8     MOV        BL,byte ptr [EAX + 0x37]
//                              player.cpp:1964 (34)
//         00470ffb     TEST       BL,BL
//         00470ffd     MOV        byte ptr [ESP + param_1],BL
//         00471001     JZ         LAB_00471020
//         00471003     MOV        EAX,dword ptr [ESP + param_1]
//         00471007     AND        EAX,0xff
//         0047100c     CMP        byte ptr [EDX + EAX*0x1 + 0x19e],0x0
//         00471014     LEA        EAX,[EDX + EAX*0x1 + 0x19e]
//         0047101b     JNZ        LAB_00471020
//                              player.cpp:1965 (3)
//         0047101d     MOV        byte ptr [EAX],0x1
//                               LAB_00471020                                                 XREF[2]:     00471001(j), 0047101b(j)
//                              player.cpp:1961 (7)
//         00471020     MOV        this,dword ptr [ECX + this->computerPlayerValue]
//         00471023     TEST       this,this
//         00471025     JNZ        LAB_00470ff6
//                               LAB_00471027                                                 XREF[1]:     00470ff4(j)
//                              player.cpp:1969 (5)
//         00471027     MOV        EAX,0x1
//                               LAB_0047102c                                                 XREF[1]:     0047103e(j)
//                              player.cpp:1971 (22)
//         0047102c     MOVSX      this,AX
//         0047102f     CMP        byte ptr [EDX + this->_padding_*0x1 + 0x19e],0x0
//         00471037     JZ         LAB_00471042
//         00471039     INC        EAX
//         0047103a     CMP        AX,0x7f
//         0047103e     JL         LAB_0047102c
//         00471040     JMP        LAB_0047104f
//                               LAB_00471042                                                 XREF[1]:     00471037(j)
//                              player.cpp:1974 (13)
//         00471042     MOVSX      this,AX
//         00471045     MOV        BL,AL
//         00471047     MOV        byte ptr [EDX + this->_padding_*0x1 + 0x19e],0x1
//                               LAB_0047104f                                                 XREF[1]:     00471040(j)
//                              player.cpp:1979 (6)
//         0047104f     CMP        AX,0x7f
//         00471053     JNZ        LAB_0047107b
//                              player.cpp:1982 (2)
//         00471055     XOR        EAX,EAX
//                              player.cpp:2009 (6)
//         00471057     POP        EDI
//         00471058     POP        ESI
//         00471059     POP        EBX
//         0047105a     RET        0x4
//                               LAB_0047105d                                                 XREF[1]:     00470f9e(j)
//                              player.cpp:1991 (12)
//         0047105d     MOV        EAX,dword ptr [EDX + 0x28]
//         00471060     MOV        BL,this
//         00471062     MOV        EAX,dword ptr [EAX + 0x4]
//         00471065     TEST       EAX,EAX
//         00471067     JZ         LAB_0047107b
//                               LAB_00471069                                                 XREF[1]:     00471079(j)
//                              player.cpp:1993 (7)
//         00471069     MOV        ESI,dword ptr [EAX]
//         0047106b     CMP        byte ptr [ESI + 0x37],this
//         0047106e     JNZ        LAB_00471074
//                              player.cpp:1994 (4)
//         00471070     MOV        byte ptr [ESI + 0x37],0x0
//                               LAB_00471074                                                 XREF[1]:     0047106e(j)
//                              player.cpp:1991 (7)
//         00471074     MOV        EAX,dword ptr [EAX + 0x4]
//         00471077     TEST       EAX,EAX
//         00471079     JNZ        LAB_00471069
//                               LAB_0047107b                                                 XREF[3]:     00470fd5(j), 00471053(j),
//                                                                                                         00471067(j)
//                              player.cpp:1999 (13)
//         0047107b     XOR        ESI,ESI
//         0047107d     XOR        EDI,EDI
//                               LAB_0047107f                                                 XREF[1]:     004710a4(j)
//         0047107f     CMP        DI,word ptr [EDX + 0x19c]
//         00471086     JGE        LAB_004710a6
//                              player.cpp:2001 (19)
//         00471088     MOVSX      this,SI
//         0047108b     MOV        EAX,dword ptr [EDX + this->_padding_*0x4 + 0x1
//         00471092     TEST       EAX,EAX
//         00471094     JZ         LAB_0047109f
//         00471096     CMP        dword ptr [EAX + 0xc],EDX
//         00471099     JNZ        LAB_0047109f
//                              player.cpp:2003 (1)
//         0047109b     INC        EDI
//                              player.cpp:2004 (10)
//         0047109c     MOV        byte ptr [EAX + 0x37],BL
//                               LAB_0047109f                                                 XREF[2]:     00471094(j), 00471099(j)
//         0047109f     INC        ESI
//         004710a0     CMP        SI,0x19
//         004710a4     JL         LAB_0047107f
//                               LAB_004710a6                                                 XREF[1]:     00471086(j)
//                              player.cpp:2009 (11)
//         004710a6     POP        EDI
//         004710a7     POP        ESI
//         004710a8     MOV        EAX,0x1
//         004710ad     POP        EBX
//         004710ae     RET        0x4
//         004710b1     ??         90h
//         004710b2     NOP
//         004710b3     NOP
//         004710b4     NOP
//         004710b5     NOP
//         004710b6     NOP
//         004710b7     NOP
//         004710b8     NOP
//         004710b9     NOP
//         004710ba     NOP
//         004710bb     NOP
//         004710bc     NOP
//         004710bd     NOP
//         004710be     NOP
//         004710bf     NOP
    return 0;
}

int RGE_Player::select_group(int param_1) {
    /* TODO: Stub */
//                              int __thiscall select_group(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004710d5(R)
//                               ?select_group@RGE_Player@@QAEHH@Z                            XREF[1]:     command_select_group:0049c757(c)
//                               RGE_Player::select_group
//                              player.cpp:2013 (6)
//         004710c0     PUSH       EBX
//         004710c1     PUSH       EBP
//         004710c2     PUSH       ESI
//         004710c3     PUSH       EDI
//         004710c4     MOV        EDI,this
//                              player.cpp:2020 (5)
//         004710c6     MOV        EBP,0x1
//                              player.cpp:2022 (14)
//         004710cb     MOV        EAX,dword ptr [EDI + 0x28]
//         004710ce     MOV        ESI,dword ptr [EAX + 0x4]
//         004710d1     TEST       ESI,ESI
//         004710d3     JZ         LAB_0047110b
//         004710d5     MOV        BL,byte ptr [ESP + param_1]
//                               LAB_004710d9                                                 XREF[1]:     00471109(j)
//                              player.cpp:2024 (2)
//         004710d9     MOV        EAX,dword ptr [ESI]
//                              player.cpp:2025 (5)
//         004710db     CMP        byte ptr [EAX + 0x37],BL
//         004710de     JNZ        LAB_00471104
//                              player.cpp:2027 (4)
//         004710e0     TEST       EBP,EBP
//         004710e2     JZ         LAB_004710f6
//                              player.cpp:2029 (14)
//         004710e4     PUSH       0x1
//         004710e6     PUSH       EAX
//         004710e7     MOV        this,EDI
//         004710e9     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         004710ee     TEST       EAX,EAX
//         004710f0     JZ         LAB_0047110b
//                              player.cpp:2031 (2)
//         004710f2     XOR        EBP,EBP
//                              player.cpp:2033 (2)
//         004710f4     JMP        LAB_00471104
//                               LAB_004710f6                                                 XREF[1]:     004710e2(j)
//                              player.cpp:2035 (14)
//         004710f6     PUSH       0x0
//         004710f8     PUSH       EAX
//         004710f9     MOV        this,EDI
//         004710fb     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00471100     TEST       EAX,EAX
//         00471102     JZ         LAB_0047110b
//                               LAB_00471104                                                 XREF[2]:     004710de(j), 004710f4(j)
//                              player.cpp:2022 (7)
//         00471104     MOV        ESI,dword ptr [ESI + 0x4]
//         00471107     TEST       ESI,ESI
//         00471109     JNZ        LAB_004710d9
//                               LAB_0047110b                                                 XREF[3]:     004710d3(j), 004710f0(j),
//                                                                                                         00471102(j)
//                              player.cpp:2041 (2)
//         0047110b     XOR        EAX,EAX
//                              player.cpp:2045 (12)
//         0047110d     POP        EDI
//         0047110e     TEST       EBP,EBP
//         00471110     POP        ESI
//         00471111     POP        EBP
//         00471112     SETZ       AL
//         00471115     POP        EBX
//         00471116     RET        0x4
//         00471119     ??         90h
//         0047111a     NOP
//         0047111b     NOP
//         0047111c     NOP
//         0047111d     NOP
//         0047111e     NOP
//         0047111f     NOP
    return 0;
}

int RGE_Player::own_selected() {
    /* TODO: Stub */
//                              int __thiscall own_selected(RGE_Player * this)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?own_selected@RGE_Player@@QAEHXZ                             XREF[2]:     create_train_list:0050b60e(c),
//                               RGE_Player::own_selected                                                  create_research_list:0050b72e(c)
//                              player.cpp:2049 (3)
//         00471120     PUSH       EBX
//         00471121     PUSH       ESI
//         00471122     PUSH       EDI
//                              player.cpp:2052 (16)
//         00471123     MOV        DI,word ptr [ECX + this->sel_count]
//         0047112a     XOR        EDX,EDX
//         0047112c     XOR        ESI,ESI
//                               LAB_0047112e                                                 XREF[1]:     0047114e(j)
//         0047112e     CMP        SI,DI
//         00471131     JGE        LAB_0047115f
//                              player.cpp:2054 (14)
//         00471133     MOVSX      EAX,DX
//         00471136     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         0047113d     TEST       EAX,EAX
//         0047113f     JZ         LAB_00471149
//                              player.cpp:2057 (8)
//         00471141     MOV        EBX,dword ptr [EAX + 0xc]
//         00471144     INC        ESI
//         00471145     CMP        EBX,this
//         00471147     JZ         LAB_00471156
//                               LAB_00471149                                                 XREF[1]:     0047113f(j)
//                              player.cpp:2052 (7)
//         00471149     INC        EDX
//         0047114a     CMP        DX,0x19
//         0047114e     JL         LAB_0047112e
//                              player.cpp:2062 (2)
//         00471150     XOR        EAX,EAX
//                              player.cpp:2063 (4)
//         00471152     POP        EDI
//         00471153     POP        ESI
//         00471154     POP        EBX
//         00471155     RET
//                               LAB_00471156                                                 XREF[1]:     00471147(j)
//                              player.cpp:2058 (5)
//         00471156     MOV        EAX,0x1
//                              player.cpp:2063 (10)
//         0047115b     POP        EDI
//         0047115c     POP        ESI
//         0047115d     POP        EBX
//         0047115e     RET
//                               LAB_0047115f                                                 XREF[1]:     00471131(j)
//         0047115f     POP        EDI
//         00471160     POP        ESI
//         00471161     XOR        EAX,EAX
//         00471163     POP        EBX
//         00471164     RET
//         00471165     ??         90h
//         00471166     NOP
//         00471167     NOP
//         00471168     NOP
//         00471169     NOP
//         0047116a     NOP
//         0047116b     NOP
//         0047116c     NOP
//         0047116d     NOP
//         0047116e     NOP
//         0047116f     NOP
    return 0;
}

int RGE_Player::is_category_selected(short param_1) {
    /* TODO: Stub */
//                              int __thiscall is_category_selected(RGE_Player * this, short param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0047117a(R)
//                               ?is_category_selected@RGE_Player@@QAEHF@Z
//                               RGE_Player::is_category_selected
//                              player.cpp:2067 (1)
//         00471170     PUSH       EBX
//                              player.cpp:2070 (23)
//         00471171     MOV        BX,word ptr [ECX + this->sel_count]
//         00471178     PUSH       ESI
//         00471179     PUSH       EDI
//         0047117a     MOV        DI,word ptr [ESP + param_1]
//         0047117f     XOR        EDX,EDX
//         00471181     XOR        ESI,ESI
//                               LAB_00471183                                                 XREF[1]:     004711a5(j)
//         00471183     CMP        SI,BX
//         00471186     JGE        LAB_004711ba
//                              player.cpp:2072 (14)
//         00471188     MOVSX      EAX,DX
//         0047118b     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         00471192     TEST       EAX,EAX
//         00471194     JZ         LAB_004711a0
//                              player.cpp:2075 (10)
//         00471196     MOV        EAX,dword ptr [EAX + 0x8]
//         00471199     INC        ESI
//         0047119a     CMP        word ptr [EAX + 0x10],DI
//         0047119e     JZ         LAB_004711af
//                               LAB_004711a0                                                 XREF[1]:     00471194(j)
//                              player.cpp:2070 (7)
//         004711a0     INC        EDX
//         004711a1     CMP        DX,0x19
//         004711a5     JL         LAB_00471183
//                              player.cpp:2080 (2)
//         004711a7     XOR        EAX,EAX
//                              player.cpp:2081 (6)
//         004711a9     POP        EDI
//         004711aa     POP        ESI
//         004711ab     POP        EBX
//         004711ac     RET        0x4
//                               LAB_004711af                                                 XREF[1]:     0047119e(j)
//                              player.cpp:2076 (5)
//         004711af     MOV        EAX,0x1
//                              player.cpp:2081 (14)
//         004711b4     POP        EDI
//         004711b5     POP        ESI
//         004711b6     POP        EBX
//         004711b7     RET        0x4
//                               LAB_004711ba                                                 XREF[1]:     00471186(j)
//         004711ba     POP        EDI
//         004711bb     POP        ESI
//         004711bc     XOR        EAX,EAX
//         004711be     POP        EBX
//         004711bf     RET        0x4
//         004711c2     ??         90h
//         004711c3     NOP
//         004711c4     NOP
//         004711c5     NOP
//         004711c6     NOP
//         004711c7     NOP
//         004711c8     NOP
//         004711c9     NOP
//         004711ca     NOP
//         004711cb     NOP
//         004711cc     NOP
//         004711cd     NOP
//         004711ce     NOP
//         004711cf     NOP
    return 0;
}

int RGE_Player::is_group_selected(short param_1) {
    /* TODO: Stub */
//                              int __thiscall is_group_selected(RGE_Player * this, short param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     004711da(R)
//                               ?is_group_selected@RGE_Player@@QAEHF@Z                       XREF[3]:     setup_buttons:0049a639(c),
//                               RGE_Player::is_group_selected                                             setup_buttons:0049a750(c),
//                                                                                                         create_build_list:0050b4fa(c)
//                              player.cpp:2085 (1)
//         004711d0     PUSH       EBX
//                              player.cpp:2088 (23)
//         004711d1     MOV        BX,word ptr [ECX + this->sel_count]
//         004711d8     PUSH       ESI
//         004711d9     PUSH       EDI
//         004711da     MOV        DI,word ptr [ESP + param_1]
//         004711df     XOR        EDX,EDX
//         004711e1     XOR        ESI,ESI
//                               LAB_004711e3                                                 XREF[1]:     00471205(j)
//         004711e3     CMP        SI,BX
//         004711e6     JGE        LAB_0047121a
//                              player.cpp:2090 (14)
//         004711e8     MOVSX      EAX,DX
//         004711eb     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         004711f2     TEST       EAX,EAX
//         004711f4     JZ         LAB_00471200
//                              player.cpp:2093 (10)
//         004711f6     MOV        EAX,dword ptr [EAX + 0x8]
//         004711f9     INC        ESI
//         004711fa     CMP        word ptr [EAX + 0x14],DI
//         004711fe     JZ         LAB_0047120f
//                               LAB_00471200                                                 XREF[1]:     004711f4(j)
//                              player.cpp:2088 (7)
//         00471200     INC        EDX
//         00471201     CMP        DX,0x19
//         00471205     JL         LAB_004711e3
//                              player.cpp:2098 (2)
//         00471207     XOR        EAX,EAX
//                              player.cpp:2099 (6)
//         00471209     POP        EDI
//         0047120a     POP        ESI
//         0047120b     POP        EBX
//         0047120c     RET        0x4
//                               LAB_0047120f                                                 XREF[1]:     004711fe(j)
//                              player.cpp:2094 (5)
//         0047120f     MOV        EAX,0x1
//                              player.cpp:2099 (14)
//         00471214     POP        EDI
//         00471215     POP        ESI
//         00471216     POP        EBX
//         00471217     RET        0x4
//                               LAB_0047121a                                                 XREF[1]:     004711e6(j)
//         0047121a     POP        EDI
//         0047121b     POP        ESI
//         0047121c     XOR        EAX,EAX
//         0047121e     POP        EBX
//         0047121f     RET        0x4
//         00471222     ??         90h
//         00471223     NOP
//         00471224     NOP
//         00471225     NOP
//         00471226     NOP
//         00471227     NOP
//         00471228     NOP
//         00471229     NOP
//         0047122a     NOP
//         0047122b     NOP
//         0047122c     NOP
//         0047122d     NOP
//         0047122e     NOP
//         0047122f     NOP
    return 0;
}

uchar RGE_Player::unit_level_selected() {
    /* TODO: Stub */
//                              uchar __thiscall unit_level_selected(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?unit_level_selected@RGE_Player@@QAEEXZ                      XREF[1]:     setup_buttons:00499981(c)
//                               RGE_Player::unit_level_selected
//                              player.cpp:2105 (1)
//         00471230     PUSH       EBX
//                              player.cpp:2111 (21)
//         00471231     MOV        BX,word ptr [ECX + this->sel_count]
//         00471238     PUSH       EBP
//         00471239     PUSH       ESI
//         0047123a     PUSH       EDI
//         0047123b     XOR        AL,AL
//         0047123d     XOR        ESI,ESI
//         0047123f     XOR        EDI,EDI
//                               LAB_00471241                                                 XREF[1]:     00471273(j)
//         00471241     CMP        DI,BX
//         00471244     JGE        LAB_0047127c
//                              player.cpp:2113 (14)
//         00471246     MOVSX      EDX,SI
//         00471249     MOV        EDX,dword ptr [ECX + EDX*0x4 + this->sel_list[
//         00471250     TEST       EDX,EDX
//         00471252     JZ         LAB_0047126e
//                              player.cpp:2115 (16)
//         00471254     TEST       DI,DI
//         00471257     JZ         LAB_00471264
//         00471259     MOV        EBP,dword ptr [EDX + 0x8]
//         0047125c     CMP        byte ptr [EBP + 0x8f],AL
//         00471262     JNZ        LAB_0047127a
//                               LAB_00471264                                                 XREF[1]:     00471257(j)
//                              player.cpp:2117 (3)
//         00471264     MOV        EAX,dword ptr [EDX + 0x8]
//                              player.cpp:2118 (14)
//         00471267     INC        EDI
//         00471268     MOV        AL,byte ptr [EAX + 0x8f]
//                               LAB_0047126e                                                 XREF[1]:     00471252(j)
//         0047126e     INC        ESI
//         0047126f     CMP        SI,0x19
//         00471273     JL         LAB_00471241
//                              player.cpp:2123 (5)
//         00471275     POP        EDI
//         00471276     POP        ESI
//         00471277     POP        EBP
//         00471278     POP        EBX
//         00471279     RET
//                               LAB_0047127a                                                 XREF[1]:     00471262(j)
//                              player.cpp:2116 (2)
//         0047127a     XOR        AL,AL
//                               LAB_0047127c                                                 XREF[1]:     00471244(j)
//                              player.cpp:2123 (5)
//         0047127c     POP        EDI
//         0047127d     POP        ESI
//         0047127e     POP        EBP
//         0047127f     POP        EBX
//         00471280     RET
//         00471281     ??         90h
//         00471282     NOP
//         00471283     NOP
//         00471284     NOP
//         00471285     NOP
//         00471286     NOP
//         00471287     NOP
//         00471288     NOP
//         00471289     NOP
//         0047128a     NOP
//         0047128b     NOP
//         0047128c     NOP
//         0047128d     NOP
//         0047128e     NOP
//         0047128f     NOP
    return 0;
}

uchar RGE_Player::get_select_level() {
    /* TODO: Stub */
//                              uchar __thiscall get_select_level(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004712a0(W), 004712d3(W), 004712d7(R)
//              uchar             Stack[-0x8]:1  select_level
//                               ?get_select_level@RGE_Player@@QAEEXZ                         XREF[1]:     mouse_left_up_action:0053eae5(c)
//                               RGE_Player::get_select_level
//                              player.cpp:2128 (3)
//         00471290     PUSH       this
//         00471291     PUSH       EBX
//         00471292     PUSH       ESI
//                              player.cpp:2132 (4)
//         00471293     OR         BL,0xff
//         00471296     PUSH       EDI
//                              player.cpp:2134 (20)
//         00471297     MOV        DI,word ptr [ECX + this->sel_count]
//         0047129e     XOR        EDX,EDX
//         004712a0     MOV        byte ptr [ESP + local_4],BL
//         004712a4     XOR        ESI,ESI
//                               LAB_004712a6                                                 XREF[1]:     004712ce(j)
//         004712a6     CMP        SI,DI
//         004712a9     JGE        LAB_004712d0
//                              player.cpp:2136 (14)
//         004712ab     MOVSX      EAX,DX
//         004712ae     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->sel_list[
//         004712b5     TEST       EAX,EAX
//         004712b7     JZ         LAB_004712c9
//                              player.cpp:2138 (13)
//         004712b9     MOV        EAX,dword ptr [EAX + 0x8]
//         004712bc     MOV        AL,byte ptr [EAX + 0x8d]
//         004712c2     CMP        AL,BL
//         004712c4     JNC        LAB_004712c8
//                              player.cpp:2139 (2)
//         004712c6     MOV        BL,AL
//                               LAB_004712c8                                                 XREF[1]:     004712c4(j)
//                              player.cpp:2140 (1)
//         004712c8     INC        ESI
//                               LAB_004712c9                                                 XREF[1]:     004712b7(j)
//                              player.cpp:2134 (7)
//         004712c9     INC        EDX
//         004712ca     CMP        DX,0x19
//         004712ce     JL         LAB_004712a6
//                               LAB_004712d0                                                 XREF[1]:     004712a9(j)
//                              player.cpp:2144 (11)
//         004712d0     CMP        BL,0xff
//         004712d3     MOV        byte ptr [ESP + local_4],BL
//         004712d7     MOV        this,dword ptr [ESP + local_4]
//                              player.cpp:2148 (11)
//         004712db     POP        EDI
//         004712dc     SETZ       AL
//         004712df     DEC        EAX
//         004712e0     POP        ESI
//         004712e1     AND        EAX,this
//         004712e3     POP        EBX
//         004712e4     POP        this
//         004712e5     RET
//         004712e6     ??         90h
//         004712e7     NOP
//         004712e8     NOP
//         004712e9     NOP
//         004712ea     NOP
//         004712eb     NOP
//         004712ec     NOP
//         004712ed     NOP
//         004712ee     NOP
//         004712ef     NOP
    return 0;
}

uchar RGE_Player::get_selected_objects_to_command(RGE_Static_Object*** param_1, short* param_2, short param_3, short param_4, short param_5, short param_6) {
    /* TODO: Stub */
//                              uchar __thiscall get_selected_objects_to_command(RGE_Player * this,
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     004712f0(R), 0047140c(R)
//              short *           Stack[0x8]:4   param_2                   XREF[2]:     004712fc(R), 00471414(R)
//              short             Stack[0xc]:2   param_3                   XREF[3]:     00471330(R), 0047133c(W), 0047137b(R)
//              short             Stack[0x10]:2  param_4                   XREF[2]:     00471389(R), 00471391(R)
//              short             Stack[0x14]:2  param_5                   XREF[2]:     0047139d(R), 004713a5(R)
//              short             Stack[0x18]:2  param_6                   XREF[2]:     004713b1(R), 004713b9(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00471336(W), 004713d2(R), 004713f3(R), 00471410(R)
//              RGE_Static_Obj    Stack[-0x8]:4  list                      XREF[3]:     00471344(W), 00471355(R), 004713dd(RW)
//              long              Stack[-0xc]:4  j
//                               ?get_selected_objects_to_command@RGE_Player@@QAEEPAPAPAVRGE  XREF[21]:    command_make_move:0047156a(c),
//                               RGE_Player::get_selected_objects_to_command                               command_make_work:004715ea(c),
//                                                                                                         command_make_do:004716ea(c),
//                                                                                                         command_stop:0047177a(c),
//                                                                                                         command_formation:004718e6(c),
//                                                                                                         command_stand_ground:0047195a(c),
//                                                                                                         command_add_waypoint:00471aba(c),
//                                                                                                         command_move:0049c8c4(c),
//                                                                                                         command_work:0049d234(c),
//                                                                                                         command_make_building:00513637(c),
//                                                                                                         command_make_wall:005136c1(c),
//                                                                                                         command_trade_attribute:005137ea(c
//                                                                                                         command_attack_ground:0051387a(c),
//                                                                                                         command_make_repair:00513a18(c),
//                                                                                                         command_make_unload:00513a9a(c),
//                                                                                                         mouse_left_up_action:0053f12d(c),
//                                                                                                         mouse_right_up_action:0053f52a(c),
//                                                                                                         command_make_do:0053fa3e(c),
//                                                                                                         pick_best_target:00540081(c),
//                                                                                                         command_make_move:0054037c(c),
//                                                                                                         [more]
//                              player.cpp:2158 (12)
//         004712f0     MOV        EAX,dword ptr [ESP + param_1]
//         004712f4     SUB        ESP,0x8
//         004712f7     PUSH       EBX
//         004712f8     PUSH       EBP
//         004712f9     PUSH       ESI
//         004712fa     MOV        ESI,this
//                              player.cpp:2166 (8)
//         004712fc     MOV        this,dword ptr [ESP + param_2]
//         00471300     XOR        EBP,EBP
//         00471302     MOV        dword ptr [EAX],EBP
//                              player.cpp:2169 (5)
//         00471304     XOR        EBX,EBX
//         00471306     MOV        word ptr [this->_padding_],BP
//                              player.cpp:2171 (13)
//         00471309     MOV        AX,word ptr [ESI + 0x19c]
//         00471310     CMP        AX,BP
//         00471313     PUSH       EDI
//         00471314     JNZ        LAB_00471322
//                              player.cpp:2172 (2)
//         00471316     XOR        AL,AL
//                              player.cpp:2209 (10)
//         00471318     POP        EDI
//         00471319     POP        ESI
//         0047131a     POP        EBP
//         0047131b     POP        EBX
//         0047131c     ADD        ESP,0x8
//         0047131f     RET        0x18
//                               LAB_00471322                                                 XREF[1]:     00471314(j)
//                              player.cpp:2174 (14)
//         00471322     MOVSX      EDX,AX
//         00471325     PUSH       EDX
//         00471326     PUSH       0x4
//         00471328     CALL       calloc                                           undefined calloc()
//         0047132d     ADD        ESP,0x8
//                              player.cpp:2176 (12)
//         00471330     CMP        word ptr [ESP + param_3],-0x1
//         00471336     MOV        dword ptr [ESP + local_4],EAX
//         0047133a     JNZ        LAB_00471344
//                              player.cpp:2177 (8)
//         0047133c     MOV        dword ptr [ESP + param_3],0x4
//                               LAB_00471344                                                 XREF[1]:     0047133a(j)
//                              player.cpp:2179 (27)
//         00471344     MOV        dword ptr [ESP + list],EBP
//         00471348     LEA        EDI,[ESI + 0x134]
//                               LAB_0047134e                                                 XREF[1]:     004713e8(j)
//         0047134e     MOVSX      EAX,word ptr [ESI + 0x19c]
//         00471355     CMP        dword ptr [ESP + list],EAX
//         00471359     JGE        LAB_004713ee
//                              player.cpp:2181 (2)
//         0047135f     MOV        EDX,dword ptr [EDI]
//                              player.cpp:2182 (4)
//         00471361     TEST       EDX,EDX
//         00471363     JZ         LAB_004713e1
//                              player.cpp:2190 (109)
//         00471365     CMP        byte ptr [EDX + 0x48],0x2
//         00471369     JNZ        LAB_004713dd
//         0047136b     CMP        dword ptr [EDX + 0xc],ESI
//         0047136e     JNZ        LAB_004713dd
//         00471370     MOV        this,dword ptr [EDX + 0x8]
//         00471373     MOVZX      AX,byte ptr [ECX + this+0x8d]
//         0047137b     CMP        AX,word ptr [ESP + param_3]
//         00471380     JGE        LAB_00471389
//         00471382     CMP        word ptr [ESI + 0x4a],0x0
//         00471387     JNZ        LAB_004713dd
//                               LAB_00471389                                                 XREF[1]:     00471380(j)
//         00471389     CMP        word ptr [ESP + param_4],-0x1
//         0047138f     JZ         LAB_0047139d
//         00471391     MOVZX      AX,byte ptr [ESP + param_4]
//         00471397     CMP        word ptr [ECX + this->checksum],AX
//         0047139b     JNZ        LAB_004713dd
//                               LAB_0047139d                                                 XREF[1]:     0047138f(j)
//         0047139d     CMP        word ptr [ESP + param_5],-0x1
//         004713a3     JZ         LAB_004713b1
//         004713a5     MOVZX      AX,byte ptr [ESP + param_5]
//         004713ab     CMP        word ptr [ECX + this->currentUpdatePathingAtte
//         004713af     JNZ        LAB_004713dd
//                               LAB_004713b1                                                 XREF[1]:     004713a3(j)
//         004713b1     CMP        word ptr [ESP + param_6],-0x1
//         004713b7     JZ         LAB_004713c5
//         004713b9     MOV        AL,byte ptr [ESP + param_6]
//         004713bd     CMP        byte ptr [ECX + this+0x8f],AL
//         004713c3     JNZ        LAB_004713dd
//                               LAB_004713c5                                                 XREF[1]:     004713b7(j)
//         004713c5     MOV        this,byte ptr [ECX + this->computerPlayerValue]
//         004713c8     CMP        this,0x28
//         004713cb     JC         LAB_004713dd
//         004713cd     CMP        this,0x5a
//         004713d0     JZ         LAB_004713dd
//                              player.cpp:2192 (7)
//         004713d2     MOV        EAX,dword ptr [ESP + local_4]
//         004713d6     MOVSX      this,BX
//                              player.cpp:2193 (4)
//         004713d9     INC        EBX
//         004713da     MOV        dword ptr [EAX + this->_padding_*0x4],EDX
//                               LAB_004713dd                                                 XREF[8]:     00471369(j), 0047136e(j),
//                                                                                                         00471387(j), 0047139b(j),
//                                                                                                         004713af(j), 004713c3(j),
//                                                                                                         004713cb(j), 004713d0(j)
//                              player.cpp:2195 (17)
//         004713dd     INC        dword ptr [ESP + list]
//                               LAB_004713e1                                                 XREF[1]:     00471363(j)
//         004713e1     INC        EBP
//         004713e2     ADD        EDI,0x4
//         004713e5     CMP        EBP,0x19
//         004713e8     JL         LAB_0047134e
//                               LAB_004713ee                                                 XREF[1]:     00471359(j)
//                              player.cpp:2199 (5)
//         004713ee     TEST       BX,BX
//         004713f1     JNZ        LAB_0047140c
//                              player.cpp:2201 (13)
//         004713f3     MOV        this,dword ptr [ESP + local_4]
//         004713f7     PUSH       this
//         004713f8     CALL       free                                             undefined free()
//         004713fd     ADD        ESP,0x4
//                              player.cpp:2202 (2)
//         00471400     XOR        AL,AL
//                              player.cpp:2209 (10)
//         00471402     POP        EDI
//         00471403     POP        ESI
//         00471404     POP        EBP
//         00471405     POP        EBX
//         00471406     ADD        ESP,0x8
//         00471409     RET        0x18
//                               LAB_0047140c                                                 XREF[1]:     004713f1(j)
//                              player.cpp:2205 (8)
//         0047140c     MOV        EDX,dword ptr [ESP + param_1]
//         00471410     MOV        EAX,dword ptr [ESP + local_4]
//                              player.cpp:2206 (4)
//         00471414     MOV        this,dword ptr [ESP + param_2]
//                              player.cpp:2209 (17)
//         00471418     POP        EDI
//         00471419     MOV        dword ptr [EDX],EAX
//         0047141b     POP        ESI
//         0047141c     MOV        word ptr [this->_padding_],BX
//         0047141f     POP        EBP
//         00471420     MOV        AL,0x1
//         00471422     POP        EBX
//         00471423     ADD        ESP,0x8
//         00471426     RET        0x18
//         00471429     ??         90h
//         0047142a     NOP
//         0047142b     NOP
//         0047142c     NOP
//         0047142d     NOP
//         0047142e     NOP
//         0047142f     NOP
    return 0;
}

void RGE_Player::update_selected() {
    /* TODO: Stub */
//                              void __thiscall update_selected(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?update_selected@RGE_Player@@QAEXXZ                          XREF[1]:     update:00470143(c)
//                               RGE_Player::update_selected
//                              player.cpp:2218 (4)
//         00471430     PUSH       EBX
//         00471431     PUSH       EBP
//         00471432     PUSH       ESI
//         00471433     PUSH       EDI
//                              player.cpp:2221 (17)
//         00471434     XOR        ESI,ESI
//         00471436     MOV        EDI,this
//         00471438     XOR        EBP,EBP
//         0047143a     MOV        BL,0x7
//                               LAB_0047143c                                                 XREF[1]:     0047146f(j)
//         0047143c     CMP        BP,word ptr [EDI + 0x19c]
//         00471443     JGE        LAB_00471471
//                              player.cpp:2223 (14)
//         00471445     MOVSX      EAX,SI
//         00471448     MOV        EAX,dword ptr [EDI + EAX*0x4 + 0x134]
//         0047144f     TEST       EAX,EAX
//         00471451     JZ         LAB_0047146a
//                              player.cpp:2225 (12)
//         00471453     CMP        byte ptr [EAX + 0x48],BL
//         00471456     JNC        LAB_00471462
//         00471458     MOV        this,dword ptr [EAX + 0x20]
//         0047145b     TEST       this,this
//         0047145d     JNZ        LAB_00471462
//                              player.cpp:2230 (3)
//         0047145f     INC        EBP
//         00471460     JMP        LAB_0047146a
//                               LAB_00471462                                                 XREF[2]:     00471456(j), 0047145d(j)
//                              player.cpp:2226 (15)
//         00471462     PUSH       ESI
//         00471463     MOV        this,EDI
//         00471465     CALL       RGE_Player::unselect_one_object                  void unselect_one_object(RGE_Player * this, s
//                               LAB_0047146a                                                 XREF[2]:     00471451(j), 00471460(j)
//         0047146a     INC        ESI
//         0047146b     CMP        SI,0x19
//         0047146f     JL         LAB_0047143c
//                               LAB_00471471                                                 XREF[1]:     00471443(j)
//                              player.cpp:2233 (5)
//         00471471     POP        EDI
//         00471472     POP        ESI
//         00471473     POP        EBP
//         00471474     POP        EBX
//         00471475     RET
//         00471476     ??         90h
//         00471477     NOP
//         00471478     NOP
//         00471479     NOP
//         0047147a     NOP
//         0047147b     NOP
//         0047147c     NOP
//         0047147d     NOP
//         0047147e     NOP
//         0047147f     NOP
    return;
}

void RGE_Player::select_area(short param_1, short param_2, short param_3, short param_4) {
    /* TODO: Stub */
//                              void __thiscall select_area(RGE_Player * this, short param_1, short
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00471480(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00471485(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     00471491(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0047149d(R)
//                               ?select_area@RGE_Player@@QAEXFFFF@Z
//                               RGE_Player::select_area
//                              player.cpp:2237 (5)
//         00471480     MOV        AX,word ptr [ESP + param_1]
//                              player.cpp:2239 (12)
//         00471485     MOV        DX,word ptr [ESP + param_2]
//         0047148a     MOV        word ptr [ECX + this->selected_start_col],AX
//                              player.cpp:2240 (12)
//         00471491     MOV        AX,word ptr [ESP + param_3]
//         00471496     MOV        word ptr [ECX + this->selected_start_row],DX
//                              player.cpp:2241 (19)
//         0047149d     MOV        DX,word ptr [ESP + param_4]
//         004714a2     MOV        word ptr [ECX + this->selected_end_col],AX
//         004714a9     MOV        word ptr [ECX + this->selected_end_row],DX
//                              player.cpp:2242 (3)
//         004714b0     RET        0x10
//         004714b3     ??         90h
//         004714b4     NOP
//         004714b5     NOP
//         004714b6     NOP
//         004714b7     NOP
//         004714b8     NOP
//         004714b9     NOP
//         004714ba     NOP
//         004714bb     NOP
//         004714bc     NOP
//         004714bd     NOP
//         004714be     NOP
//         004714bf     NOP
    return;
}

void RGE_Player::unselect_area() {
    /* TODO: Stub */
//                              void __thiscall unselect_area(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?unselect_area@RGE_Player@@QAEXXZ                            XREF[2]:     command_unselect:0049d071(c),
//                               RGE_Player::unselect_area                                                 command_cancel:004ad25f(c)
//                              player.cpp:2246 (10)
//         004714c0     OR         EAX,0xffffffff
//         004714c3     MOV        word ptr [ECX + this->selected_start_col],AX
//                              player.cpp:2248 (7)
//         004714ca     MOV        word ptr [ECX + this->selected_start_row],AX
//                              player.cpp:2249 (7)
//         004714d1     MOV        word ptr [ECX + this->selected_end_col],AX
//                              player.cpp:2250 (7)
//         004714d8     MOV        word ptr [ECX + this->selected_end_row],AX
//                              player.cpp:2251 (1)
//         004714df     RET
    return;
}

void RGE_Player::ungroup_objects() {
    /* TODO: Stub */
//                              void __thiscall ungroup_objects(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?ungroup_objects@RGE_Player@@QAEXXZ                          XREF[1]:     command_ungroup:0049cfcf(c)
//                               RGE_Player::ungroup_objects
//                              player.cpp:2257 (3)
//         004714e0     PUSH       EBX
//         004714e1     PUSH       ESI
//         004714e2     PUSH       EDI
//                              player.cpp:2259 (23)
//         004714e3     XOR        EBX,EBX
//         004714e5     XOR        ESI,ESI
//         004714e7     XOR        EDI,EDI
//         004714e9     LEA        EDX,[ECX + this->sel_list[0]]
//                               LAB_004714ef                                                 XREF[1]:     0047150b(j)
//         004714ef     MOVSX      EAX,word ptr [ECX + this->sel_count]
//         004714f6     CMP        EDI,EAX
//         004714f8     JGE        LAB_0047150d
//                              player.cpp:2261 (6)
//         004714fa     MOV        EAX,dword ptr [EDX]
//         004714fc     CMP        EAX,EBX
//         004714fe     JZ         LAB_00471504
//                              player.cpp:2272 (1)
//         00471500     INC        EDI
//                              player.cpp:2273 (12)
//         00471501     MOV        byte ptr [EAX + 0x37],BL
//                               LAB_00471504                                                 XREF[1]:     004714fe(j)
//         00471504     INC        ESI
//         00471505     ADD        EDX,0x4
//         00471508     CMP        ESI,0x19
//         0047150b     JL         LAB_004714ef
//                               LAB_0047150d                                                 XREF[1]:     004714f8(j)
//                              player.cpp:2277 (4)
//         0047150d     POP        EDI
//         0047150e     POP        ESI
//         0047150f     POP        EBX
//         00471510     RET
//         00471511     ??         90h
//         00471512     NOP
//         00471513     NOP
//         00471514     NOP
//         00471515     NOP
//         00471516     NOP
//         00471517     NOP
//         00471518     NOP
//         00471519     NOP
//         0047151a     NOP
//         0047151b     NOP
//         0047151c     NOP
//         0047151d     NOP
//         0047151e     NOP
//         0047151f     NOP
    return;
}

void RGE_Player::analyize_selected_objects() {
    /* TODO: Stub */
//                              void __thiscall analyize_selected_objects(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?analyize_selected_objects@RGE_Player@@UAEXXZ                XREF[1]:     00570f68(*)
//                               RGE_Player::analyize_selected_objects
//                              player.cpp:2293 (1)
//         00471520     RET
//         00471521     ??         90h
//         00471522     NOP
//         00471523     NOP
//         00471524     NOP
//         00471525     NOP
//         00471526     NOP
//         00471527     NOP
//         00471528     NOP
//         00471529     NOP
//         0047152a     NOP
//         0047152b     NOP
//         0047152c     NOP
//         0047152d     NOP
//         0047152e     NOP
//         0047152f     NOP
    return;
}

int RGE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) {
    /* TODO: Stub */
//                              int __thiscall get_mouse_pointer_action_vars(RGE_Player * this, int
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     00471530(R)
//              int *             Stack[0xc]:4   param_3                   XREF[1]:     00471534(R)
//                               ?get_mouse_pointer_action_vars@RGE_Player@@UAEHHAAH0@Z       XREF[1]:     00570f6c(*)
//                               RGE_Player::get_mouse_pointer_action_vars
//                              player.cpp:2301 (4)
//         00471530     MOV        EAX,dword ptr [ESP + param_2]
//                              player.cpp:2303 (16)
//         00471534     MOV        this,dword ptr [ESP + param_3]
//         00471538     MOV        dword ptr [EAX],0x0
//         0047153e     MOV        dword ptr [this->_padding_],0x0
//                              player.cpp:2304 (2)
//         00471544     XOR        EAX,EAX
//                              player.cpp:2305 (3)
//         00471546     RET        0xc
//         00471549     ??         90h
//         0047154a     NOP
//         0047154b     NOP
//         0047154c     NOP
//         0047154d     NOP
//         0047154e     NOP
//         0047154f     NOP
    return 0;
}

uchar RGE_Player::command_make_move(RGE_Static_Object* param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_move(RGE_Player * this, RGE_Static_Obj
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00471553(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     00471562(*), 00471573(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_make_move@RGE_Player@@UAEEPAVRGE_Static_Object@@MM@Z XREF[3]:     00570f70(*), 00576910(*),
//                               RGE_Player::command_make_move                                             00576a40(*)
//                              player.cpp:2312 (3)
//         00471550     SUB        ESP,0x8
//                              player.cpp:2316 (32)
//         00471553     LEA        EAX=>local_4,[ESP + 0x4]
//         00471557     PUSH       ESI
//         00471558     PUSH       -0x1
//         0047155a     MOV        ESI,this
//         0047155c     PUSH       -0x1
//         0047155e     PUSH       -0x1
//         00471560     PUSH       -0x1
//         00471562     LEA        this=>list_num,[ESP + 0x14]
//         00471566     PUSH       EAX
//         00471567     PUSH       this
//         00471568     MOV        this,ESI
//         0047156a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0047156f     TEST       AL,AL
//         00471571     JZ         LAB_004715bb
//                              player.cpp:2318 (14)
//         00471573     MOV        EDX,dword ptr [ESP + list_num]
//         00471577     MOV        this,dword ptr [EDX]
//         00471579     MOV        EAX,dword ptr [this->_padding_]
//         0047157b     CALL       dword ptr [EAX + 0xb0]
//                              player.cpp:2319 (36)
//         00471581     MOV        this,dword ptr [ESP + 0x18]
//         00471585     MOV        EDX,dword ptr [ESP + 0x14]
//         00471589     MOV        EAX,dword ptr [ESP + 0x10]
//         0047158d     PUSH       this
//         0047158e     MOV        this,dword ptr [ESP + 0xc]
//         00471592     PUSH       EDX=>DAT_fffffff8
//         00471593     MOV        EDX,dword ptr [ESP + 0xc]
//         00471597     PUSH       EAX=>DAT_fffffff4
//         00471598     MOV        EAX,dword ptr [ESI + 0x3c]
//         0047159b     PUSH       this=>DAT_fffffff0
//         0047159c     PUSH       EDX
//         0047159d     MOV        this,dword ptr [EAX + 0x58]
//         004715a0     CALL       RGE_Command::command_move                        void command_move(RGE_Command * this, RGE_Sta
//                              player.cpp:2320 (13)
//         004715a5     MOV        this,dword ptr [ESP + 0x4]
//         004715a9     PUSH       this
//         004715aa     CALL       free                                             undefined free()
//         004715af     ADD        ESP,0x4
//                              player.cpp:2321 (2)
//         004715b2     MOV        AL,0x1
//                              player.cpp:2325 (7)
//         004715b4     POP        ESI
//         004715b5     ADD        ESP,0x8
//         004715b8     RET        0xc
//                               LAB_004715bb                                                 XREF[1]:     00471571(j)
//                              player.cpp:2324 (2)
//         004715bb     XOR        AL,AL
//                              player.cpp:2325 (7)
//         004715bd     POP        ESI
//         004715be     ADD        ESP,0x8
//         004715c1     RET        0xc
//         004715c4     ??         90h
//         004715c5     NOP
//         004715c6     NOP
//         004715c7     NOP
//         004715c8     NOP
//         004715c9     NOP
//         004715ca     NOP
//         004715cb     NOP
//         004715cc     NOP
//         004715cd     NOP
//         004715ce     NOP
//         004715cf     NOP
    return 0;
}

uchar RGE_Player::command_make_work(RGE_Static_Object* param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_work(RGE_Player * this, RGE_Static_Obj
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00471603(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     00471608(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004715fc(R)
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     004715d3(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     004715e2(*), 004715f7(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_make_work@RGE_Player@@UAEEPAVRGE_Static_Object@@MM@Z XREF[3]:     00570f74(*), 00576914(*),
//                               RGE_Player::command_make_work                                             00576a44(*)
//                              player.cpp:2330 (3)
//         004715d0     SUB        ESP,0x8
//                              player.cpp:2335 (36)
//         004715d3     LEA        EAX=>local_4,[ESP + 0x4]
//         004715d7     PUSH       EBX
//         004715d8     PUSH       -0x1
//         004715da     MOV        EBX,this
//         004715dc     PUSH       -0x1
//         004715de     PUSH       -0x1
//         004715e0     PUSH       -0x1
//         004715e2     LEA        this=>list_num,[ESP + 0x14]
//         004715e6     PUSH       EAX
//         004715e7     PUSH       this
//         004715e8     MOV        this,EBX
//         004715ea     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         004715ef     TEST       AL,AL
//         004715f1     JZ         LAB_004716b9
//                              player.cpp:2338 (34)
//         004715f7     MOV        EDX,dword ptr [ESP + list_num]
//         004715fb     PUSH       EDI
//         004715fc     MOV        EDI,dword ptr [ESP + param_3]
//         00471600     PUSH       ESI
//         00471601     MOV        this,dword ptr [EDX]
//         00471603     MOV        ESI,dword ptr [ESP + param_1]
//         00471607     PUSH       EBP
//         00471608     MOV        EBP,dword ptr [ESP + param_2]
//         0047160c     MOV        EAX,dword ptr [this->_padding_]
//         0047160e     PUSH       0x0
//         00471610     PUSH       EDI
//         00471611     PUSH       EBP
//         00471612     PUSH       ESI
//         00471613     CALL       dword ptr [EAX + 0xbc]
//                              player.cpp:2339 (4)
//         00471619     TEST       EAX,EAX
//         0047161b     JZ         LAB_00471624
//                              player.cpp:2340 (7)
//         0047161d     MOV        EDX,dword ptr [EAX]
//         0047161f     MOV        this,EAX
//         00471621     CALL       dword ptr [EDX + 0x2c]
//                               LAB_00471624                                                 XREF[1]:     0047161b(j)
//                              player.cpp:2342 (24)
//         00471624     MOV        EAX,dword ptr [ESP + 0x14]
//         00471628     MOV        this,dword ptr [ESP + 0x10]
//         0047162c     MOV        EDX,dword ptr [EBX + 0x3c]
//         0047162f     PUSH       EDI
//         00471630     PUSH       EBP=>DAT_fffffff8
//         00471631     PUSH       ESI=>DAT_fffffff4
//         00471632     PUSH       EAX=>DAT_fffffff0
//         00471633     PUSH       this
//         00471634     MOV        this,dword ptr [EDX + 0x58]
//         00471637     CALL       RGE_Command::command_work                        void command_work(RGE_Command * this, RGE_Sta
//                              player.cpp:2345 (4)
//         0047163c     TEST       ESI,ESI
//         0047163e     JZ         LAB_004716a0
//                              player.cpp:2347 (9)
//         00471640     XOR        EDI,EDI
//         00471642     CMP        word ptr [ESP + 0x14],DI
//         00471647     JLE        LAB_004716a0
//                              player.cpp:2353 (87)
//         00471649     MOV        EAX,dword ptr [EBX]
//         0047164b     MOV        EBP,dword ptr [EAX + 0x30]
//                               LAB_0047164e                                                 XREF[1]:     0047169e(j)
//         0047164e     MOV        this,dword ptr [ESI + 0x8]
//         00471651     MOV        EDX,dword ptr [ESI + 0x3c]
//         00471654     PUSH       0x64
//         00471656     PUSH       0x0=>DAT_fffffff8
//         00471658     FLD        float ptr [ECX + this->objects]
//         0047165b     FMUL       float ptr [DAT_00570ec8]
//         00471661     PUSH       0x0=>DAT_fffffff4
//         00471663     MOV        EAX,dword ptr [ESI + 0x38]
//         00471666     PUSH       this=>DAT_fffffff0
//         00471667     MOV        this,dword ptr [ESI + 0xc]
//         0047166a     FSTP       float ptr [ESP]=>DAT_fffffff0
//         0047166d     PUSH       0x3f800000
//         00471672     PUSH       EDX
//         00471673     MOVSX      EDX,word ptr [ECX + this->id]
//         00471677     MOV        this,dword ptr [ESP + 0x28]
//         0047167b     PUSH       EAX
//         0047167c     MOV        EAX,dword ptr [ESI + 0x4]
//         0047167f     PUSH       EDX
//         00471680     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
//         00471683     PUSH       EAX
//         00471684     MOVSX      this,word ptr [EBX + 0x4a]
//         00471688     MOV        EAX,dword ptr [EDX + 0x4]
//         0047168b     PUSH       0x2bd
//         00471690     PUSH       EAX
//         00471691     PUSH       this
//         00471692     MOV        this,EBX
//         00471694     CALL       EBP
//         00471696     MOVSX      EDX,word ptr [ESP + 0x14]
//         0047169b     INC        EDI
//         0047169c     CMP        EDI,EDX
//         0047169e     JL         LAB_0047164e
//                               LAB_004716a0                                                 XREF[2]:     0047163e(j), 00471647(j)
//                              player.cpp:2357 (13)
//         004716a0     MOV        EAX,dword ptr [ESP + 0x10]
//         004716a4     PUSH       EAX
//         004716a5     CALL       free                                             undefined free()
//         004716aa     ADD        ESP,0x4
//                              player.cpp:2358 (5)
//         004716ad     MOV        AL,0x1
//         004716af     POP        EBP
//         004716b0     POP        ESI
//         004716b1     POP        EDI
//                              player.cpp:2362 (7)
//         004716b2     POP        EBX
//         004716b3     ADD        ESP,0x8
//         004716b6     RET        0xc
//                               LAB_004716b9                                                 XREF[1]:     004715f1(j)
//                              player.cpp:2361 (2)
//         004716b9     XOR        AL,AL
//                              player.cpp:2362 (7)
//         004716bb     POP        EBX
//         004716bc     ADD        ESP,0x8
//         004716bf     RET        0xc
//         004716c2     ??         90h
//         004716c3     NOP
//         004716c4     NOP
//         004716c5     NOP
//         004716c6     NOP
//         004716c7     NOP
//         004716c8     NOP
//         004716c9     NOP
//         004716ca     NOP
//         004716cb     NOP
//         004716cc     NOP
//         004716cd     NOP
//         004716ce     NOP
//         004716cf     NOP
    return 0;
}

uchar RGE_Player::command_make_do(RGE_Static_Object* param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_make_do(RGE_Player * this, RGE_Static_Objec
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00471704(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004716f8(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004716ff(R)
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     004716d3(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     004716e2(*), 004716f3(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_make_do@RGE_Player@@UAEEPAVRGE_Static_Object@@MM@Z  XREF[3]:     00570f78(*), 00576918(*),
//                               RGE_Player::command_make_do                                               00576a48(*)
//                              player.cpp:2367 (3)
//         004716d0     SUB        ESP,0x8
//                              player.cpp:2372 (32)
//         004716d3     LEA        EAX=>local_4,[ESP + 0x4]
//         004716d7     PUSH       EBP
//         004716d8     PUSH       -0x1
//         004716da     MOV        EBP,this
//         004716dc     PUSH       -0x1
//         004716de     PUSH       -0x1
//         004716e0     PUSH       -0x1
//         004716e2     LEA        this=>list_num,[ESP + 0x14]
//         004716e6     PUSH       EAX
//         004716e7     PUSH       this
//         004716e8     MOV        this,EBP
//         004716ea     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         004716ef     TEST       AL,AL
//         004716f1     JZ         LAB_00471751
//                              player.cpp:2375 (34)
//         004716f3     MOV        EDX,dword ptr [ESP + list_num]
//         004716f7     PUSH       EDI
//         004716f8     MOV        EDI,dword ptr [ESP + param_2]
//         004716fc     PUSH       ESI
//         004716fd     MOV        this,dword ptr [EDX]
//         004716ff     MOV        ESI,dword ptr [ESP + param_3]
//         00471703     PUSH       EBX
//         00471704     MOV        EBX,dword ptr [ESP + param_1]
//         00471708     MOV        EAX,dword ptr [this->_padding_]
//         0047170a     PUSH       0x0
//         0047170c     PUSH       ESI
//         0047170d     PUSH       EDI
//         0047170e     PUSH       EBX
//         0047170f     CALL       dword ptr [EAX + 0xbc]
//                              player.cpp:2376 (4)
//         00471715     TEST       EAX,EAX
//         00471717     JZ         LAB_00471720
//                              player.cpp:2377 (7)
//         00471719     MOV        EDX,dword ptr [EAX]
//         0047171b     MOV        this,EAX
//         0047171d     CALL       dword ptr [EDX + 0x2c]
//                               LAB_00471720                                                 XREF[1]:     00471717(j)
//                              player.cpp:2379 (24)
//         00471720     MOV        EAX,dword ptr [ESP + 0x14]
//         00471724     MOV        this,dword ptr [ESP + 0x10]
//         00471728     MOV        EDX,dword ptr [EBP + 0x3c]
//         0047172b     PUSH       ESI
//         0047172c     PUSH       EDI=>DAT_fffffff8
//         0047172d     PUSH       EBX=>DAT_fffffff4
//         0047172e     PUSH       EAX=>DAT_fffffff0
//         0047172f     PUSH       this
//         00471730     MOV        this,dword ptr [EDX + 0x58]
//         00471733     CALL       RGE_Command::command_order                       void command_order(RGE_Command * this, RGE_St
//                              player.cpp:2380 (13)
//         00471738     MOV        EAX,dword ptr [ESP + 0x10]
//         0047173c     PUSH       EAX
//         0047173d     CALL       free                                             undefined free()
//         00471742     ADD        ESP,0x4
//                              player.cpp:2381 (5)
//         00471745     MOV        AL,0x1
//         00471747     POP        EBX
//         00471748     POP        ESI
//         00471749     POP        EDI
//                              player.cpp:2385 (7)
//         0047174a     POP        EBP
//         0047174b     ADD        ESP,0x8
//         0047174e     RET        0xc
//                               LAB_00471751                                                 XREF[1]:     004716f1(j)
//                              player.cpp:2384 (2)
//         00471751     XOR        AL,AL
//                              player.cpp:2385 (7)
//         00471753     POP        EBP
//         00471754     ADD        ESP,0x8
//         00471757     RET        0xc
//         0047175a     ??         90h
//         0047175b     NOP
//         0047175c     NOP
//         0047175d     NOP
//         0047175e     NOP
//         0047175f     NOP
    return 0;
}

uchar RGE_Player::command_stop() {
    /* TODO: Stub */
//                              uchar __thiscall command_stop(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00471763(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     00471772(*), 00471783(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_stop@RGE_Player@@UAEEXZ                             XREF[3]:     00570f7c(*), 0057691c(*),
//                               RGE_Player::command_stop                                                  00576a4c(*)
//                              player.cpp:2390 (3)
//         00471760     SUB        ESP,0x8
//                              player.cpp:2394 (32)
//         00471763     LEA        EAX=>local_4,[ESP + 0x4]
//         00471767     PUSH       ESI
//         00471768     PUSH       -0x1
//         0047176a     MOV        ESI,this
//         0047176c     PUSH       -0x1
//         0047176e     PUSH       -0x1
//         00471770     PUSH       0x3
//         00471772     LEA        this=>list_num,[ESP + 0x14]
//         00471776     PUSH       EAX
//         00471777     PUSH       this
//         00471778     MOV        this,ESI
//         0047177a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0047177f     TEST       AL,AL
//         00471781     JZ         LAB_004717ba
//                              player.cpp:2396 (14)
//         00471783     MOV        EDX,dword ptr [ESP + list_num]
//         00471787     MOV        this,dword ptr [EDX]
//         00471789     MOV        EAX,dword ptr [this->_padding_]
//         0047178b     CALL       dword ptr [EAX + 0xac]
//                              player.cpp:2397 (21)
//         00471791     MOV        this,dword ptr [ESP + 0x8]
//         00471795     MOV        EAX,dword ptr [ESI + 0x3c]
//         00471798     MOV        EDX,dword ptr [ESP + 0x4]
//         0047179c     PUSH       this
//         0047179d     MOV        this,dword ptr [EAX + 0x58]
//         004717a0     PUSH       EDX=>DAT_fffffff8
//         004717a1     CALL       RGE_Command::command_stop                        void command_stop(RGE_Command * this, RGE_Sta
//                              player.cpp:2398 (13)
//         004717a6     MOV        this,dword ptr [ESP + 0x4]
//         004717aa     PUSH       this
//         004717ab     CALL       free                                             undefined free()
//         004717b0     ADD        ESP,0x4
//                              player.cpp:2399 (2)
//         004717b3     MOV        AL,0x1
//                              player.cpp:2403 (5)
//         004717b5     POP        ESI
//         004717b6     ADD        ESP,0x8
//         004717b9     RET
//                               LAB_004717ba                                                 XREF[1]:     00471781(j)
//                              player.cpp:2402 (2)
//         004717ba     XOR        AL,AL
//                              player.cpp:2403 (5)
//         004717bc     POP        ESI
//         004717bd     ADD        ESP,0x8
//         004717c0     RET
//         004717c1     ??         90h
//         004717c2     NOP
//         004717c3     NOP
//         004717c4     NOP
//         004717c5     NOP
//         004717c6     NOP
//         004717c7     NOP
//         004717c8     NOP
//         004717c9     NOP
//         004717ca     NOP
//         004717cb     NOP
//         004717cc     NOP
//         004717cd     NOP
//         004717ce     NOP
//         004717cf     NOP
    return 0;
}

uchar RGE_Player::command_place_object(short param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              uchar __thiscall command_place_object(RGE_Player * this, short param
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     004717d0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004717f1(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004717ec(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004717e7(R)
//                               ?command_place_object@RGE_Player@@UAEEFMMM@Z                 XREF[3]:     00570f80(*), 00576920(*),
//                               RGE_Player::command_place_object                                          00576a50(*)
//                              player.cpp:2408 (23)
//         004717d0     MOV        EAX,dword ptr [ESP + param_1]
//         004717d4     PUSH       ESI
//         004717d5     CMP        AX,0xffff
//         004717d9     JZ         LAB_0047180d
//         004717db     MOV        ESI,dword ptr [ECX + this->master_objects]
//         004717de     MOVSX      EDX,AX
//         004717e1     CMP        dword ptr [ESI + EDX*0x4],0x0
//         004717e5     JZ         LAB_0047180d
//                              player.cpp:2412 (32)
//         004717e7     MOV        EDX,dword ptr [ESP + param_4]
//         004717eb     PUSH       EDX
//         004717ec     MOV        EDX,dword ptr [ESP + param_3]
//         004717f0     PUSH       EDX
//         004717f1     MOV        EDX,dword ptr [ESP + param_2]
//         004717f5     PUSH       EDX
//         004717f6     MOV        DX,word ptr [ECX + this->id]
//         004717fa     PUSH       EDX
//         004717fb     PUSH       EAX
//         004717fc     MOV        EAX,dword ptr [ECX + this->world]
//         004717ff     MOV        this,dword ptr [EAX + 0x58]
//         00471802     CALL       RGE_Command::command_create                      void command_create(RGE_Command * this, short
//                              player.cpp:2413 (2)
//         00471807     MOV        AL,0x1
//                              player.cpp:2414 (10)
//         00471809     POP        ESI
//         0047180a     RET        0x10
//                               LAB_0047180d                                                 XREF[2]:     004717d9(j), 004717e5(j)
//         0047180d     XOR        AL,AL
//         0047180f     POP        ESI
//         00471810     RET        0x10
//         00471813     ??         90h
//         00471814     NOP
//         00471815     NOP
//         00471816     NOP
//         00471817     NOP
//         00471818     NOP
//         00471819     NOP
//         0047181a     NOP
//         0047181b     NOP
//         0047181c     NOP
//         0047181d     NOP
//         0047181e     NOP
//         0047181f     NOP
    return 0;
}

uchar RGE_Player::command_add_attribute(int param_1, float param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_add_attribute(RGE_Player * this, int param_
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471820(R)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     00471829(R), 0047183a(R)
//                               ?command_add_attribute@RGE_Player@@UAEEHM@Z                  XREF[3]:     00570f84(*), 00576924(*),
//                               RGE_Player::command_add_attribute                                         00576a54(*)
//                              player.cpp:2419 (26)
//         00471820     MOV        EDX,dword ptr [ESP + param_1]
//         00471824     CMP        EDX,-0x1
//         00471827     JZ         LAB_00471855
//         00471829     FLD        float ptr [ESP + param_2]
//         0047182d     FCOMP      float ptr [DAT_00570ec4]
//         00471833     FNSTSW     AX
//         00471835     TEST       AH,0x40
//         00471838     JNZ        LAB_00471855
//                              player.cpp:2423 (22)
//         0047183a     MOV        EAX,dword ptr [ESP + param_2]
//         0047183e     PUSH       EAX
//         0047183f     MOV        EAX,dword ptr [ECX + this->world]
//         00471842     PUSH       EDX
//         00471843     MOVSX      EDX,word ptr [ECX + this->id]
//         00471847     MOV        this,dword ptr [EAX + 0x58]
//         0047184a     PUSH       EDX
//         0047184b     CALL       RGE_Command::command_add_attribute               void command_add_attribute(RGE_Command * this
//                              player.cpp:2424 (2)
//         00471850     MOV        AL,0x1
//                              player.cpp:2425 (3)
//         00471852     RET        0x8
//                               LAB_00471855                                                 XREF[2]:     00471827(j), 00471838(j)
//                              player.cpp:2421 (2)
//         00471855     XOR        AL,AL
//                              player.cpp:2425 (3)
//         00471857     RET        0x8
//         0047185a     ??         90h
//         0047185b     NOP
//         0047185c     NOP
//         0047185d     NOP
//         0047185e     NOP
//         0047185f     NOP
    return 0;
}

uchar RGE_Player::command_give_attribute(int param_1, int param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_give_attribute(RGE_Player * this, int param
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047189d(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471860(R)
//              float             Stack[0xc]:4   param_3                   XREF[3]:     0047186b(R), 0047187f(R), 0047188d(R)
//                               ?command_give_attribute@RGE_Player@@UAEEHHM@Z                XREF[3]:     00570f88(*), 00576928(*),
//                               RGE_Player::command_give_attribute                                        00576a58(*)
//                              player.cpp:2430 (45)
//         00471860     MOV        EDX,dword ptr [ESP + param_2]
//         00471864     PUSH       ESI
//         00471865     CMP        EDX,-0x1
//         00471868     PUSH       EDI
//         00471869     JZ         LAB_004718b1
//         0047186b     FLD        float ptr [ESP + param_3]
//         0047186f     FCOMP      float ptr [DAT_00570ec4]
//         00471875     FNSTSW     AX
//         00471877     TEST       AH,0x40
//         0047187a     JNZ        LAB_004718b1
//         0047187c     MOV        EAX,dword ptr [ECX + this->attributes]
//         0047187f     FLD        float ptr [ESP + param_3]
//         00471883     FCOMP      float ptr [EAX + EDX*0x4]
//         00471886     FNSTSW     AX
//         00471888     TEST       AH,0x41
//         0047188b     JZ         LAB_004718b1
//                              player.cpp:2434 (29)
//         0047188d     MOV        EDI,dword ptr [ESP + param_3]
//         00471891     MOV        EAX,dword ptr [ECX + this->world]
//         00471894     MOVSX      this,word ptr [ECX + this->id]
//         00471898     MOV        EAX,dword ptr [EAX + 0x58]
//         0047189b     PUSH       EDI
//         0047189c     PUSH       EDX
//         0047189d     MOV        EDX,dword ptr [ESP + param_1]
//         004718a1     MOV        ESI,dword ptr [EAX]
//         004718a3     PUSH       EDX
//         004718a4     PUSH       this
//         004718a5     MOV        this,EAX
//         004718a7     CALL       dword ptr [ESI + 0xc]
//                              player.cpp:2435 (2)
//         004718aa     MOV        AL,0x1
//                              player.cpp:2436 (12)
//         004718ac     POP        EDI
//         004718ad     POP        ESI
//         004718ae     RET        0xc
//                               LAB_004718b1                                                 XREF[3]:     00471869(j), 0047187a(j),
//                                                                                                         0047188b(j)
//         004718b1     POP        EDI
//         004718b2     XOR        AL,AL
//         004718b4     POP        ESI
//         004718b5     RET        0xc
//         004718b8     ??         90h
//         004718b9     NOP
//         004718ba     NOP
//         004718bb     NOP
//         004718bc     NOP
//         004718bd     NOP
//         004718be     NOP
//         004718bf     NOP
    return 0;
}

uchar RGE_Player::command_formation(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_formation(RGE_Player * this, int param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     004718c3(R), 004718d8(*)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004718de(*), 004718ef(R)
//              RGE_Static_Obj    Stack[-0x8]:4  list
//                               ?command_formation@RGE_Player@@UAEEH@Z                       XREF[3]:     00570f8c(*), 0057692c(*),
//                               RGE_Player::command_formation                                             00576a5c(*)
//                              player.cpp:2440 (3)
//         004718c0     PUSH       this
//         004718c1     PUSH       ESI
//         004718c2     PUSH       EDI
//                              player.cpp:2442 (15)
//         004718c3     MOV        EDI,dword ptr [ESP + param_1]
//         004718c7     MOV        ESI,this
//         004718c9     TEST       EDI,EDI
//         004718cb     JL         LAB_00471929
//         004718cd     CMP        EDI,0x5
//         004718d0     JG         LAB_00471929
//                              player.cpp:2447 (29)
//         004718d2     PUSH       -0x1
//         004718d4     PUSH       -0x1
//         004718d6     PUSH       -0x1
//         004718d8     LEA        EAX=>param_1,[ESP + 0x1c]
//         004718dc     PUSH       -0x1
//         004718de     LEA        this=>local_4,[ESP + 0x18]
//         004718e2     PUSH       EAX
//         004718e3     PUSH       this
//         004718e4     MOV        this,ESI
//         004718e6     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         004718eb     TEST       AL,AL
//         004718ed     JZ         LAB_00471929
//                              player.cpp:2448 (14)
//         004718ef     MOV        EDX,dword ptr [ESP + local_4]
//         004718f3     MOV        this,dword ptr [EDX]
//         004718f5     MOV        EAX,dword ptr [this->_padding_]
//         004718f7     CALL       dword ptr [EAX + 0xac]
//                              player.cpp:2449 (23)
//         004718fd     MOVSX      this,word ptr [ESP + 0x10]
//         00471902     MOV        EAX,dword ptr [ESI + 0x3c]
//         00471905     MOV        EDX,dword ptr [ESP + 0x8]
//         00471909     PUSH       EDI
//         0047190a     PUSH       this=>DAT_fffffff8
//         0047190b     MOV        this,dword ptr [EAX + 0x58]
//         0047190e     PUSH       EDX=>DAT_fffffff4
//         0047190f     CALL       RGE_Command::command_formation                   void command_formation(RGE_Command * this, RG
//                              player.cpp:2450 (13)
//         00471914     MOV        this,dword ptr [ESP + 0x8]
//         00471918     PUSH       this
//         00471919     CALL       free                                             undefined free()
//         0047191e     ADD        ESP,0x4
//                              player.cpp:2451 (2)
//         00471921     MOV        AL,0x1
//                              player.cpp:2455 (14)
//         00471923     POP        EDI
//         00471924     POP        ESI
//         00471925     POP        this
//         00471926     RET        0x4
//                               LAB_00471929                                                 XREF[3]:     004718cb(j), 004718d0(j),
//                                                                                                         004718ed(j)
//         00471929     POP        EDI
//         0047192a     XOR        AL,AL
//         0047192c     POP        ESI
//         0047192d     POP        this
//         0047192e     RET        0x4
//         00471931     ??         90h
//         00471932     NOP
//         00471933     NOP
//         00471934     NOP
//         00471935     NOP
//         00471936     NOP
//         00471937     NOP
//         00471938     NOP
//         00471939     NOP
//         0047193a     NOP
//         0047193b     NOP
//         0047193c     NOP
//         0047193d     NOP
//         0047193e     NOP
//         0047193f     NOP
    return 0;
}

uchar RGE_Player::command_stand_ground() {
    /* TODO: Stub */
//                              uchar __thiscall command_stand_ground(RGE_Player * this)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00471943(*)
//              short             Stack[-0x8]:2  listNum                   XREF[2]:     00471952(*), 00471963(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_stand_ground@RGE_Player@@UAEEXZ                     XREF[3]:     00570f90(*), 00576930(*),
//                               RGE_Player::command_stand_ground                                          00576a60(*)
//                              player.cpp:2459 (3)
//         00471940     SUB        ESP,0x8
//                              player.cpp:2462 (32)
//         00471943     LEA        EAX=>local_4,[ESP + 0x4]
//         00471947     PUSH       ESI
//         00471948     PUSH       -0x1
//         0047194a     MOV        ESI,this
//         0047194c     PUSH       -0x1
//         0047194e     PUSH       -0x1
//         00471950     PUSH       -0x1
//         00471952     LEA        this=>listNum,[ESP + 0x14]
//         00471956     PUSH       EAX
//         00471957     PUSH       this
//         00471958     MOV        this,ESI
//         0047195a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0047195f     TEST       AL,AL
//         00471961     JZ         LAB_004719c3
//                              player.cpp:2463 (14)
//         00471963     MOV        EDX,dword ptr [ESP + listNum]
//         00471967     MOV        this,dword ptr [EDX]
//         00471969     MOV        EAX,dword ptr [this->_padding_]
//         0047196b     CALL       dword ptr [EAX + 0xac]
//                              player.cpp:2483 (62)
//         00471971     MOVSX      EAX,word ptr [ESI + 0x4a]
//         00471975     PUSH       0x64
//         00471977     MOV        this,dword ptr [ESP + 0xc]
//         0047197b     PUSH       0x0=>DAT_fffffff8
//         0047197d     MOV        EDX,dword ptr [ESP + 0xc]
//         00471981     PUSH       offset DAT_fffffff4
//         00471983     PUSH       offset DAT_fffffff0
//         00471988     PUSH       0xbf800000
//         0047198d     PUSH       0xbf800000
//         00471992     PUSH       0xbf800000
//         00471997     PUSH       -0x1
//         00471999     PUSH       -0x1
//         0047199b     PUSH       0x2d5
//         004719a0     PUSH       this
//         004719a1     PUSH       EDX
//         004719a2     PUSH       EAX
//         004719a3     PUSH       EAX
//         004719a4     MOV        EAX,dword ptr [ESI + 0x3c]
//         004719a7     MOV        this,dword ptr [EAX + 0x58]
//         004719aa     CALL       RGE_Command::command_group_ai_order              void command_group_ai_order(RGE_Command * thi
//                              player.cpp:2485 (13)
//         004719af     MOV        this,dword ptr [ESP + 0x4]
//         004719b3     PUSH       this
//         004719b4     CALL       free                                             undefined free()
//         004719b9     ADD        ESP,0x4
//                              player.cpp:2486 (2)
//         004719bc     MOV        AL,0x1
//                              player.cpp:2490 (5)
//         004719be     POP        ESI
//         004719bf     ADD        ESP,0x8
//         004719c2     RET
//                               LAB_004719c3                                                 XREF[1]:     00471961(j)
//                              player.cpp:2489 (2)
//         004719c3     XOR        AL,AL
//                              player.cpp:2490 (5)
//         004719c5     POP        ESI
//         004719c6     ADD        ESP,0x8
//         004719c9     RET
//         004719ca     ??         90h
//         004719cb     NOP
//         004719cc     NOP
//         004719cd     NOP
//         004719ce     NOP
//         004719cf     NOP
    return 0;
}

uchar RGE_Player::command_create_group(int param_1, int* param_2, int param_3, float param_4) {
    /* TODO: Stub */
//                              uchar __thiscall command_create_group(RGE_Player * this, int param_1
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004719de(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     004719d9(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004719d4(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004719d0(R)
//                               ?command_create_group@RGE_Player@@UAEEHPAHHM@Z               XREF[3]:     00570f94(*), 00576934(*),
//                               RGE_Player::command_create_group                                          00576a64(*)
//                              player.cpp:2495 (36)
//         004719d0     MOV        EAX,dword ptr [ESP + param_4]
//         004719d4     MOV        EDX,dword ptr [ESP + param_3]
//         004719d8     PUSH       EAX
//         004719d9     MOV        EAX,dword ptr [ESP + param_2]
//         004719dd     PUSH       EDX
//         004719de     MOV        EDX,dword ptr [ESP + param_1]
//         004719e2     PUSH       EAX
//         004719e3     PUSH       EDX
//         004719e4     MOVSX      EAX,word ptr [ECX + this->id]
//         004719e8     MOV        this,dword ptr [ECX + this->world]
//         004719eb     PUSH       EAX
//         004719ec     MOV        this,dword ptr [ECX + this->tile_list.list_size]
//         004719ef     CALL       RGE_Command::command_create_group                void command_create_group(RGE_Command * this,
//                              player.cpp:2498 (2)
//         004719f4     MOV        AL,0x1
//                              player.cpp:2499 (3)
//         004719f6     RET        0x10
//         004719f9     ??         90h
//         004719fa     NOP
//         004719fb     NOP
//         004719fc     NOP
//         004719fd     NOP
//         004719fe     NOP
//         004719ff     NOP
    return 0;
}

uchar RGE_Player::command_add_to_group(int param_1, int param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_add_to_group(RGE_Player * this, int param_1
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471a09(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471a04(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00471a00(R)
//                               ?command_add_to_group@RGE_Player@@UAEEHHM@Z                  XREF[3]:     00570f98(*), 00576938(*),
//                               RGE_Player::command_add_to_group                                          00576a68(*)
//                              player.cpp:2503 (31)
//         00471a00     MOV        EAX,dword ptr [ESP + param_3]
//         00471a04     MOV        EDX,dword ptr [ESP + param_2]
//         00471a08     PUSH       EAX
//         00471a09     MOV        EAX,dword ptr [ESP + param_1]
//         00471a0d     PUSH       EDX
//         00471a0e     PUSH       EAX
//         00471a0f     MOVSX      EDX,word ptr [ECX + this->id]
//         00471a13     MOV        EAX,dword ptr [ECX + this->world]
//         00471a16     PUSH       EDX
//         00471a17     MOV        this,dword ptr [EAX + 0x58]
//         00471a1a     CALL       RGE_Command::command_add_to_group                void command_add_to_group(RGE_Command * this,
//                              player.cpp:2505 (2)
//         00471a1f     MOV        AL,0x1
//                              player.cpp:2506 (3)
//         00471a21     RET        0xc
//         00471a24     ??         90h
//         00471a25     NOP
//         00471a26     NOP
//         00471a27     NOP
//         00471a28     NOP
//         00471a29     NOP
//         00471a2a     NOP
//         00471a2b     NOP
//         00471a2c     NOP
//         00471a2d     NOP
//         00471a2e     NOP
//         00471a2f     NOP
    return 0;
}

uchar RGE_Player::command_remove_from_group(int param_1, int param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_remove_from_group(RGE_Player * this, int pa
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471a34(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471a30(R)
//                               ?command_remove_from_group@RGE_Player@@UAEEHH@Z              XREF[3]:     00570f9c(*), 0057693c(*),
//                               RGE_Player::command_remove_from_group                                     00576a6c(*)
//                              player.cpp:2510 (26)
//         00471a30     MOV        EAX,dword ptr [ESP + param_2]
//         00471a34     MOV        EDX,dword ptr [ESP + param_1]
//         00471a38     PUSH       EAX
//         00471a39     PUSH       EDX
//         00471a3a     MOVSX      EAX,word ptr [ECX + this->id]
//         00471a3e     MOV        this,dword ptr [ECX + this->world]
//         00471a41     PUSH       EAX
//         00471a42     MOV        this,dword ptr [ECX + this->tile_list.list_size]
//         00471a45     CALL       RGE_Command::command_remove_from_group           void command_remove_from_group(RGE_Command *
//                              player.cpp:2512 (2)
//         00471a4a     MOV        AL,0x1
//                              player.cpp:2513 (3)
//         00471a4c     RET        0x8
//         00471a4f     ??         90h
    return 0;
}

uchar RGE_Player::command_destroy_group(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall command_destroy_group(RGE_Player * this, int param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471a50(R)
//                               ?command_destroy_group@RGE_Player@@UAEEH@Z                   XREF[3]:     00570fa0(*), 00576940(*),
//                               RGE_Player::command_destroy_group                                         00576a70(*)
//                              player.cpp:2517 (21)
//         00471a50     MOV        EAX,dword ptr [ESP + param_1]
//         00471a54     MOVSX      EDX,word ptr [ECX + this->id]
//         00471a58     PUSH       EAX
//         00471a59     MOV        EAX,dword ptr [ECX + this->world]
//         00471a5c     PUSH       EDX
//         00471a5d     MOV        this,dword ptr [EAX + 0x58]
//         00471a60     CALL       RGE_Command::command_destroy_group               void command_destroy_group(RGE_Command * this
//                              player.cpp:2519 (2)
//         00471a65     MOV        AL,0x1
//                              player.cpp:2520 (3)
//         00471a67     RET        0x4
//         00471a6a     ??         90h
//         00471a6b     NOP
//         00471a6c     NOP
//         00471a6d     NOP
//         00471a6e     NOP
//         00471a6f     NOP
    return 0;
}

uchar RGE_Player::command_resign(int param_1, int param_2) {
    /* TODO: Stub */
//                              uchar __thiscall command_resign(RGE_Player * this, int param_1, int
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471a7e(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471a7a(R)
//                               ?command_resign@RGE_Player@@UAEEHH@Z                         XREF[3]:     00570fa4(*), 00576944(*),
//                               RGE_Player::command_resign                                                00576a74(*)
//                              player.cpp:2524 (10)
//         00471a70     MOV        AL,byte ptr [ECX + this->game_status]
//         00471a76     TEST       AL,AL
//         00471a78     JNZ        LAB_00471a99
//                              player.cpp:2527 (26)
//         00471a7a     MOV        EAX,dword ptr [ESP + param_2]
//         00471a7e     MOV        EDX,dword ptr [ESP + param_1]
//         00471a82     PUSH       EAX
//         00471a83     PUSH       EDX
//         00471a84     MOVSX      EAX,word ptr [ECX + this->id]
//         00471a88     MOV        this,dword ptr [ECX + this->world]
//         00471a8b     PUSH       EAX
//         00471a8c     MOV        this,dword ptr [ECX + this->tile_list.list_size]
//         00471a8f     CALL       RGE_Command::command_resign                      void command_resign(RGE_Command * this, int p
//                              player.cpp:2528 (2)
//         00471a94     MOV        AL,0x1
//                              player.cpp:2531 (3)
//         00471a96     RET        0x8
//                               LAB_00471a99                                                 XREF[1]:     00471a78(j)
//                              player.cpp:2530 (2)
//         00471a99     XOR        AL,AL
//                              player.cpp:2531 (3)
//         00471a9b     RET        0x8
//         00471a9e     ??         90h
//         00471a9f     NOP
    return 0;
}

uchar RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall command_add_waypoint(RGE_Player * this, float param
//              uchar             AL:1           <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00471aa3(*)
//              short             Stack[-0x8]:2  list_num                  XREF[2]:     00471ab2(*), 00471ac3(R)
//              RGE_Static_Obj    Stack[-0xc]:4  list
//                               ?command_add_waypoint@RGE_Player@@UAEEMMM@Z                  XREF[3]:     00570fa8(*), 00576948(*),
//                               RGE_Player::command_add_waypoint                                          00576a78(*)
//                              player.cpp:2538 (3)
//         00471aa0     SUB        ESP,0x8
//                              player.cpp:2542 (32)
//         00471aa3     LEA        EAX=>local_4,[ESP + 0x4]
//         00471aa7     PUSH       ESI
//         00471aa8     PUSH       -0x1
//         00471aaa     MOV        ESI,this
//         00471aac     PUSH       -0x1
//         00471aae     PUSH       -0x1
//         00471ab0     PUSH       -0x1
//         00471ab2     LEA        this=>list_num,[ESP + 0x14]
//         00471ab6     PUSH       EAX
//         00471ab7     PUSH       this
//         00471ab8     MOV        this,ESI
//         00471aba     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00471abf     TEST       AL,AL
//         00471ac1     JZ         LAB_00471b10
//                              player.cpp:2544 (14)
//         00471ac3     MOV        EDX,dword ptr [ESP + list_num]
//         00471ac7     MOV        this,dword ptr [EDX]
//         00471ac9     MOV        EAX,dword ptr [this->_padding_]
//         00471acb     CALL       dword ptr [EAX + 0xac]
//                              player.cpp:2545 (41)
//         00471ad1     FLD        float ptr [ESP + 0x14]
//         00471ad5     CALL       __ftol                                           undefined __ftol()
//         00471ada     FLD        float ptr [ESP + 0x10]
//         00471ade     PUSH       EAX
//         00471adf     CALL       __ftol                                           undefined __ftol()
//         00471ae4     MOV        this,dword ptr [ESP + 0xc]
//         00471ae8     MOV        EDX,dword ptr [ESP + 0x8]
//         00471aec     PUSH       EAX=>DAT_fffffff8
//         00471aed     MOV        EAX,dword ptr [ESI + 0x3c]
//         00471af0     PUSH       this=>DAT_fffffff4
//         00471af1     PUSH       EDX=>DAT_fffffff0
//         00471af2     MOV        this,dword ptr [EAX + 0x58]
//         00471af5     CALL       RGE_Command::command_group_waypoint              void command_group_waypoint(RGE_Command * thi
//                              player.cpp:2546 (13)
//         00471afa     MOV        this,dword ptr [ESP + 0x4]
//         00471afe     PUSH       this
//         00471aff     CALL       free                                             undefined free()
//         00471b04     ADD        ESP,0x4
//                              player.cpp:2547 (2)
//         00471b07     MOV        AL,0x1
//                              player.cpp:2551 (7)
//         00471b09     POP        ESI
//         00471b0a     ADD        ESP,0x8
//         00471b0d     RET        0xc
//                               LAB_00471b10                                                 XREF[1]:     00471ac1(j)
//                              player.cpp:2550 (2)
//         00471b10     XOR        AL,AL
//                              player.cpp:2551 (7)
//         00471b12     POP        ESI
//         00471b13     ADD        ESP,0x8
//         00471b16     RET        0xc
//         00471b19     ??         90h
//         00471b1a     NOP
//         00471b1b     NOP
//         00471b1c     NOP
//         00471b1d     NOP
//         00471b1e     NOP
//         00471b1f     NOP
    return 0;
}

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              RGE_Object_Node * __thiscall addObject(RGE_Player * this, RGE_Static
//              RGE_Object_Nod    EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     00471b2d(R), 00471b3b(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471b20(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00471b37(R)
//                               ?addObject@RGE_Player@@UAEPAURGE_Object_Node@@PAVRGE_Static  XREF[2]:     addObject:00515086(c),
//                               RGE_Player::addObject                                                     00570fac(*)
//                              player.cpp:2557 (13)
//         00471b20     MOV        EAX,dword ptr [ESP + param_2]
//         00471b24     PUSH       EBX
//         00471b25     PUSH       ESI
//         00471b26     PUSH       EDI
//         00471b27     TEST       EAX,EAX
//         00471b29     MOV        ESI,this
//         00471b2b     JZ         LAB_00471b37
//                              player.cpp:2561 (8)
//         00471b2d     MOV        EDI,dword ptr [ESP + param_1]
//         00471b31     MOV        this,dword ptr [ESI + 0x2c]
//         00471b34     PUSH       EDI
//                              player.cpp:2562 (6)
//         00471b35     JMP        LAB_00471b4c
//                               LAB_00471b37                                                 XREF[1]:     00471b2b(j)
//         00471b37     MOV        EAX,dword ptr [ESP + param_3]
//                              player.cpp:2563 (12)
//         00471b3b     MOV        EDI,dword ptr [ESP + param_1]
//         00471b3f     TEST       EAX,EAX
//         00471b41     PUSH       EDI
//         00471b42     JZ         LAB_00471b49
//         00471b44     MOV        this,dword ptr [ESI + 0x30]
//                              player.cpp:2564 (2)
//         00471b47     JMP        LAB_00471b4c
//                               LAB_00471b49                                                 XREF[1]:     00471b42(j)
//                              player.cpp:2565 (8)
//         00471b49     MOV        this,dword ptr [ESI + 0x28]
//                               LAB_00471b4c                                                 XREF[2]:     00471b35(j), 00471b47(j)
//         00471b4c     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List *
//                              player.cpp:2569 (14)
//         00471b51     MOV        this,dword ptr [ESI + 0x3c]
//         00471b54     MOV        EBX,EAX
//         00471b56     PUSH       EDI
//         00471b57     MOV        EAX,dword ptr [this->_padding_]
//         00471b59     CALL       dword ptr [EAX + 0xf8]
//                              player.cpp:2572 (8)
//         00471b5f     POP        EDI
//         00471b60     MOV        EAX,EBX
//         00471b62     POP        ESI
//         00471b63     POP        EBX
//         00471b64     RET        0xc
//         00471b67     ??         90h
//         00471b68     NOP
//         00471b69     NOP
//         00471b6a     NOP
//         00471b6b     NOP
//         00471b6c     NOP
//         00471b6d     NOP
//         00471b6e     NOP
//         00471b6f     NOP
    return 0;
}

void RGE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) {
    /* TODO: Stub */
//                              void __thiscall removeObject(RGE_Player * this, RGE_Static_Object *
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     00471b80(R), 00471b97(R), 00471ba6(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471b70(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00471b8b(R)
//              RGE_Object_Nod    Stack[0x10]:4  param_4                   XREF[3]:     00471b7c(R), 00471b93(R), 00471ba2(R)
//                               ?removeObject@RGE_Player@@UAEXPAVRGE_Static_Object@@HHPAURG  XREF[2]:     removeObject:005150fa(c),
//                               RGE_Player::removeObject                                                  00570fb0(*)
//                              player.cpp:2578 (12)
//         00471b70     MOV        EAX,dword ptr [ESP + param_2]
//         00471b74     PUSH       ESI
//         00471b75     TEST       EAX,EAX
//         00471b77     PUSH       EDI
//         00471b78     MOV        ESI,this
//         00471b7a     JZ         LAB_00471b8b
//                              player.cpp:2580 (13)
//         00471b7c     MOV        EAX,dword ptr [ESP + param_4]
//         00471b80     MOV        EDI,dword ptr [ESP + param_1]
//         00471b84     MOV        this,dword ptr [ESI + 0x2c]
//         00471b87     PUSH       EAX
//         00471b88     PUSH       EDI
//                              player.cpp:2581 (10)
//         00471b89     JMP        LAB_00471baf
//                               LAB_00471b8b                                                 XREF[1]:     00471b7a(j)
//         00471b8b     MOV        EAX,dword ptr [ESP + param_3]
//         00471b8f     TEST       EAX,EAX
//         00471b91     JZ         LAB_00471ba2
//                              player.cpp:2582 (13)
//         00471b93     MOV        this,dword ptr [ESP + param_4]
//         00471b97     MOV        EDI,dword ptr [ESP + param_1]
//         00471b9b     PUSH       this
//         00471b9c     MOV        this,dword ptr [ESI + 0x30]
//         00471b9f     PUSH       EDI
//                              player.cpp:2583 (2)
//         00471ba0     JMP        LAB_00471baf
//                               LAB_00471ba2                                                 XREF[1]:     00471b91(j)
//                              player.cpp:2584 (18)
//         00471ba2     MOV        EDX,dword ptr [ESP + param_4]
//         00471ba6     MOV        EDI,dword ptr [ESP + param_1]
//         00471baa     MOV        this,dword ptr [ESI + 0x28]
//         00471bad     PUSH       EDX
//         00471bae     PUSH       EDI
//                               LAB_00471baf                                                 XREF[2]:     00471b89(j), 00471ba0(j)
//         00471baf     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
//                              player.cpp:2588 (15)
//         00471bb4     MOV        this,dword ptr [ESI + 0x3c]
//         00471bb7     MOV        EDX,dword ptr [EDI + 0x4]
//         00471bba     PUSH       EDX
//         00471bbb     MOV        EAX,dword ptr [this->_padding_]
//         00471bbd     CALL       dword ptr [EAX + 0xfc]
//                              player.cpp:2589 (5)
//         00471bc3     POP        EDI
//         00471bc4     POP        ESI
//         00471bc5     RET        0x10
//         00471bc8     ??         90h
//         00471bc9     NOP
//         00471bca     NOP
//         00471bcb     NOP
//         00471bcc     NOP
//         00471bcd     NOP
//         00471bce     NOP
//         00471bcf     NOP
    return;
}

void RGE_Player::logMessage(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall logMessage(RGE_Player * this, char * param_1, ...)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//                               ?logMessage@RGE_Player@@UAAXPADZZ                            XREF[1]:     00570fb4(*)
//                               RGE_Player::logMessage
//                              player.cpp:2594 (1)
//         00471bd0     RET
//         00471bd1     ??         90h
//         00471bd2     NOP
//         00471bd3     NOP
//         00471bd4     NOP
//         00471bd5     NOP
//         00471bd6     NOP
//         00471bd7     NOP
//         00471bd8     NOP
//         00471bd9     NOP
//         00471bda     NOP
//         00471bdb     NOP
//         00471bdc     NOP
//         00471bdd     NOP
//         00471bde     NOP
//         00471bdf     NOP
    return;
}

void RGE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notify(RGE_Player * this, int param_1, int param_2,
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//              long              Stack[0x14]:4  param_5
//              long              Stack[0x18]:4  param_6
//                               ?notify@RGE_Player@@UAEXHHHJJJ@Z                             XREF[1]:     00570fb8(*)
//                               RGE_Player::notify
//                              player.cpp:2601 (3)
//         00471be0     RET        0x18
//         00471be3     ??         90h
//         00471be4     NOP
//         00471be5     NOP
//         00471be6     NOP
//         00471be7     NOP
//         00471be8     NOP
//         00471be9     NOP
//         00471bea     NOP
//         00471beb     NOP
//         00471bec     NOP
//         00471bed     NOP
//         00471bee     NOP
//         00471bef     NOP
    return;
}

void RGE_Player::set_map_visible() {
    /* TODO: Stub */
//                              void __thiscall set_map_visible(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?set_map_visible@RGE_Player@@QAEXXZ                          XREF[2]:     action:004ac7f8(c),
//                               RGE_Player::set_map_visible                                               new_scenario:00542cea(c)
//                              player.cpp:2702 (10)
//         00471bf0     MOV        this,dword ptr [ECX + this->visible]
//         00471bf3     PUSH       0x1
//         00471bf5     CALL       RGE_Visible_Map::set_all                         void set_all(RGE_Visible_Map * this, uchar pa
//                              player.cpp:2704 (1)
//         00471bfa     RET
//         00471bfb     ??         90h
//         00471bfc     NOP
//         00471bfd     NOP
//         00471bfe     NOP
//         00471bff     NOP
    return;
}

void RGE_Player::remake_visible_map() {
    /* TODO: Stub */
//                              void __thiscall remake_visible_map(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00471c41(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00471c5d(R), 00471c6e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00471c3b(W)
//                               ?remake_visible_map@RGE_Player@@QAEXXZ                       XREF[9]:     reset_player_visible_maps:00541ec6
//                               RGE_Player::remake_visible_map                                            load_scenario1:00544374(c),
//                                                                                                         load_scenario2:0054463d(c),
//                                                                                                         load_scenario3:0054494f(c),
//                                                                                                         load_scenario4:00544c61(c),
//                                                                                                         load_scenario5:00544f41(c),
//                                                                                                         load_scenario6:00545271(c),
//                                                                                                         load_scenario7:005455a1(c),
//                                                                                                         load_scenario8:005458d1(c)
//                              player.cpp:2710 (26)
//         00471c00     PUSH       -0x1
//         00471c02     PUSH       FUN_0055e38b
//         00471c07     MOV        EAX,FS:[0x0]
//         00471c0d     PUSH       EAX
//         00471c0e     MOV        dword ptr FS:[0x0],ESP
//         00471c15     PUSH       this
//         00471c16     PUSH       ESI
//         00471c17     MOV        ESI,this
//         00471c19     PUSH       EDI
//                              player.cpp:2711 (7)
//         00471c1a     MOV        EDI,dword ptr [ESI + 0x38]
//         00471c1d     TEST       EDI,EDI
//         00471c1f     JZ         LAB_00471c31
//                              player.cpp:2712 (16)
//         00471c21     MOV        this,EDI
//         00471c23     CALL       RGE_Visible_Map::~RGE_Visible_Map                void ~RGE_Visible_Map(RGE_Visible_Map * this)
//         00471c28     PUSH       EDI
//         00471c29     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00471c2e     ADD        ESP,0x4
//                               LAB_00471c31                                                 XREF[1]:     00471c1f(j)
//                              player.cpp:2713 (44)
//         00471c31     PUSH       0x38
//         00471c33     CALL       operator_new                                     void * operator_new(uint param_1)
//         00471c38     ADD        ESP,0x4
//         00471c3b     MOV        dword ptr [ESP + local_10],EAX
//         00471c3f     TEST       EAX,EAX
//         00471c41     MOV        dword ptr [ESP + local_4],0x0
//         00471c49     JZ         LAB_00471c6e
//         00471c4b     MOV        this,dword ptr [ESI + 0x3c]
//         00471c4e     PUSH       ESI
//         00471c4f     MOV        EDX,dword ptr [ECX + this->objects]
//         00471c52     MOV        this,EAX
//         00471c54     PUSH       EDX
//         00471c55     CALL       RGE_Visible_Map::RGE_Visible_Map                 undefined RGE_Visible_Map(RGE_Visible_Map * t
//         00471c5a     MOV        dword ptr [ESI + 0x38],EAX
//                              player.cpp:2714 (39)
//         00471c5d     MOV        this,dword ptr [ESP + local_c]
//         00471c61     MOV        dword ptr FS:[0x0],this
//         00471c68     POP        EDI
//         00471c69     POP        ESI
//         00471c6a     ADD        ESP,0x10
//         00471c6d     RET
//                               LAB_00471c6e                                                 XREF[1]:     00471c49(j)
//         00471c6e     MOV        this,dword ptr [ESP + local_c]
//         00471c72     XOR        EAX,EAX
//         00471c74     MOV        dword ptr [ESI + 0x38],EAX
//         00471c77     POP        EDI
//         00471c78     MOV        dword ptr FS:[0x0],this
//         00471c7f     POP        ESI
//         00471c80     ADD        ESP,0x10
//         00471c83     RET
//         00471c84     ??         90h
//         00471c85     NOP
//         00471c86     NOP
//         00471c87     NOP
//         00471c88     NOP
//         00471c89     NOP
//         00471c8a     NOP
//         00471c8b     NOP
//         00471c8c     NOP
//         00471c8d     NOP
//         00471c8e     NOP
//         00471c8f     NOP
    return;
}

void RGE_Player::load_victory(int param_1, long* param_2, uchar param_3) {
    /* TODO: Stub */
//                              void __thiscall load_victory(RGE_Player * this, int param_1, long *
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471ccc(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00471cc7(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00471cc3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00471cb9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00471cde(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00471cb3(W)
//                               ?load_victory@RGE_Player@@UAEXHPAJE@Z                        XREF[1]:     00570fc0(*)
//                               RGE_Player::load_victory
//                              player.cpp:2718 (25)
//         00471c90     PUSH       -0x1
//         00471c92     PUSH       FUN_0055e3ab
//         00471c97     MOV        EAX,FS:[0x0]
//         00471c9d     PUSH       EAX
//         00471c9e     MOV        dword ptr FS:[0x0],ESP
//         00471ca5     PUSH       this
//         00471ca6     PUSH       ESI
//         00471ca7     MOV        ESI,this
//                              player.cpp:2719 (53)
//         00471ca9     PUSH       0x20
//         00471cab     CALL       operator_new                                     void * operator_new(uint param_1)
//         00471cb0     ADD        ESP,0x4
//         00471cb3     MOV        dword ptr [ESP + local_10],EAX
//         00471cb7     TEST       EAX,EAX
//         00471cb9     MOV        dword ptr [ESP + local_4],0x0
//         00471cc1     JZ         LAB_00471cdc
//         00471cc3     MOV        this,dword ptr [ESP + param_3]
//         00471cc7     MOV        EDX,dword ptr [ESP + param_2]
//         00471ccb     PUSH       this
//         00471ccc     MOV        this,dword ptr [ESP + param_1]
//         00471cd0     PUSH       EDX
//         00471cd1     PUSH       this
//         00471cd2     PUSH       ESI
//         00471cd3     MOV        this,EAX
//         00471cd5     CALL       RGE_Victory_Conditions::RGE_Victory_Conditions   undefined RGE_Victory_Conditions(RGE_Victory_
//         00471cda     JMP        LAB_00471cde
//                               LAB_00471cdc                                                 XREF[1]:     00471cc1(j)
//         00471cdc     XOR        EAX,EAX
//                               LAB_00471cde                                                 XREF[1]:     00471cda(j)
//                              player.cpp:2720 (21)
//         00471cde     MOV        this,dword ptr [ESP + local_c]
//         00471ce2     MOV        dword ptr [ESI + 0x34],EAX
//         00471ce5     MOV        dword ptr FS:[0x0],this
//         00471cec     POP        ESI
//         00471ced     ADD        ESP,0x10
//         00471cf0     RET        0xc
//         00471cf3     ??         90h
//         00471cf4     NOP
//         00471cf5     NOP
//         00471cf6     NOP
//         00471cf7     NOP
//         00471cf8     NOP
//         00471cf9     NOP
//         00471cfa     NOP
//         00471cfb     NOP
//         00471cfc     NOP
//         00471cfd     NOP
//         00471cfe     NOP
//         00471cff     NOP
    return;
}

void RGE_Player::new_victory() {
    /* TODO: Stub */
//                              void __thiscall new_victory(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00471d29(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00471d3e(R), 00471d4e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00471d23(W)
//                               ?new_victory@RGE_Player@@UAEXXZ                              XREF[2]:     RGE_Player:0046e97e(c),
//                               RGE_Player::new_victory                                                   00570fc4(*)
//                              player.cpp:2724 (25)
//         00471d00     PUSH       -0x1
//         00471d02     PUSH       FUN_0055e3cb
//         00471d07     MOV        EAX,FS:[0x0]
//         00471d0d     PUSH       EAX
//         00471d0e     MOV        dword ptr FS:[0x0],ESP
//         00471d15     PUSH       this
//         00471d16     PUSH       ESI
//         00471d17     MOV        ESI,this
//                              player.cpp:2725 (37)
//         00471d19     PUSH       0x20
//         00471d1b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00471d20     ADD        ESP,0x4
//         00471d23     MOV        dword ptr [ESP + local_10],EAX
//         00471d27     TEST       EAX,EAX
//         00471d29     MOV        dword ptr [ESP + local_4],0x0
//         00471d31     JZ         LAB_00471d4e
//         00471d33     PUSH       ESI
//         00471d34     MOV        this,EAX
//         00471d36     CALL       RGE_Victory_Conditions::RGE_Victory_Conditions   undefined RGE_Victory_Conditions(RGE_Victory_
//         00471d3b     MOV        dword ptr [ESI + 0x34],EAX
//                              player.cpp:2726 (37)
//         00471d3e     MOV        this,dword ptr [ESP + local_c]
//         00471d42     MOV        dword ptr FS:[0x0],this
//         00471d49     POP        ESI
//         00471d4a     ADD        ESP,0x10
//         00471d4d     RET
//                               LAB_00471d4e                                                 XREF[1]:     00471d31(j)
//         00471d4e     MOV        this,dword ptr [ESP + local_c]
//         00471d52     XOR        EAX,EAX
//         00471d54     MOV        dword ptr [ESI + 0x34],EAX
//         00471d57     MOV        dword ptr FS:[0x0],this
//         00471d5e     POP        ESI
//         00471d5f     ADD        ESP,0x10
//         00471d62     RET
//         00471d63     ??         90h
//         00471d64     NOP
//         00471d65     NOP
//         00471d66     NOP
//         00471d67     NOP
//         00471d68     NOP
//         00471d69     NOP
//         00471d6a     NOP
//         00471d6b     NOP
//         00471d6c     NOP
//         00471d6d     NOP
//         00471d6e     NOP
//         00471d6f     NOP
    return;
}

void RGE_Tile_List::add_node(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall add_node(RGE_Tile_List * this, int param_1, int para
//              void              <VOID>         <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471dc4(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00471dd1(R)
//                               ?add_node@RGE_Tile_List@@QAEXHH@Z                            XREF[13]:    set_elev:00459873(c),
//                               RGE_Tile_List::add_node                                                   set_terrain:00459997(c),
//                                                                                                         change_terrain:0050fb06(c),
//                                                                                                         change_terrain:0050fbec(c),
//                                                                                                         make_new_cliff:00510237(c),
//                                                                                                         remove_cliff_edge:00510387(c),
//                                                                                                         add_cliff_edge:005104dd(c),
//                                                                                                         delete_cliff:00510a19(c),
//                                                                                                         explore_all:0053c645(c),
//                                                                                                         explore_terrain:0053c88f(c),
//                                                                                                         explore_terrain:0053c8a6(c),
//                                                                                                         explore_terrain_sq:0053cc5c(c),
//                                                                                                         explore_terrain_sq:0053cc73(c)
//                              player.cpp:2734 (3)
//         00471d70     PUSH       EBX
//         00471d71     MOV        EBX,this
//                              player.cpp:2736 (12)
//         00471d73     MOV        EAX,dword ptr [EBX]
//         00471d75     MOV        this,dword ptr [EBX + 0x4]
//         00471d78     CMP        this,EAX
//         00471d7a     JL         LAB_00471dbe
//         00471d7c     PUSH       EDI
//         00471d7d     PUSH       ESI
//         00471d7e     PUSH       EBP
//                              player.cpp:2744 (10)
//         00471d7f     ADD        EAX,EAX
//         00471d81     PUSH       0x8
//         00471d83     PUSH       EAX
//         00471d84     CALL       calloc                                           undefined calloc()
//                              player.cpp:2747 (29)
//         00471d89     MOV        this,dword ptr [EBX]
//         00471d8b     MOV        ESI,dword ptr [EBX + 0x10]
//         00471d8e     SHL        this,0x3
//         00471d91     MOV        EBP,EAX
//         00471d93     MOV        EDX,this
//         00471d95     MOV        EDI,EBP
//         00471d97     ADD        ESP,0x8
//         00471d9a     SHR        this,0x2
//         00471d9d     MOVSD.REP  ES:EDI,ESI
//         00471d9f     MOV        this,EDX
//         00471da1     AND        this,0x3
//         00471da4     MOVSB.REP  ES:EDI,ESI
//                              player.cpp:2750 (9)
//         00471da6     MOV        EAX,dword ptr [EBX + 0x10]
//         00471da9     PUSH       EAX
//         00471daa     CALL       free                                             undefined free()
//                              player.cpp:2752 (15)
//         00471daf     MOV        this,dword ptr [EBX]
//         00471db1     ADD        ESP,0x4
//         00471db4     MOV        dword ptr [EBX + 0x10],EBP
//         00471db7     SHL        this,0x1
//         00471db9     POP        EBP
//         00471dba     POP        ESI
//         00471dbb     MOV        dword ptr [EBX],this
//         00471dbd     POP        EDI
//                               LAB_00471dbe                                                 XREF[1]:     00471d7a(j)
//                              player.cpp:2757 (13)
//         00471dbe     MOV        EDX,dword ptr [EBX + 0x4]
//         00471dc1     MOV        EAX,dword ptr [EBX + 0x10]
//         00471dc4     MOV        this,dword ptr [ESP + param_1]
//         00471dc8     MOV        dword ptr [EAX + EDX*0x8],this
//                              player.cpp:2758 (14)
//         00471dcb     MOV        EDX,dword ptr [EBX + 0x4]
//         00471dce     MOV        EAX,dword ptr [EBX + 0x10]
//         00471dd1     MOV        this,dword ptr [ESP + param_2]
//         00471dd5     MOV        dword ptr [EAX + EDX*0x8 + 0x4],this
//                              player.cpp:2760 (3)
//         00471dd9     MOV        this,dword ptr [EBX + 0x4]
//                              player.cpp:2761 (11)
//         00471ddc     MOV        EAX,dword ptr [EBX + 0x8]
//         00471ddf     INC        this
//         00471de0     INC        EAX
//         00471de1     MOV        dword ptr [EBX + 0x4],this
//         00471de4     MOV        dword ptr [EBX + 0x8],EAX
//                              player.cpp:2763 (4)
//         00471de7     POP        EBX
//         00471de8     RET        0x8
//         00471deb     ??         90h
//         00471dec     NOP
//         00471ded     NOP
//         00471dee     NOP
//         00471def     NOP
    return;
}

void RGE_Tile_List::del_list() {
    /* TODO: Stub */
//                              void __thiscall del_list(RGE_Tile_List * this)
//              void              <VOID>         <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//                               ?del_list@RGE_Tile_List@@QAEXXZ                              XREF[3]:     draw:00437412(c),
//                               RGE_Tile_List::del_list                                                   action:004ac7e7(c),
//                                                                                                         update:005430a2(c)
//                              player.cpp:2767 (3)
//         00471df0     PUSH       ESI
//         00471df1     MOV        ESI,this
//                              player.cpp:2771 (21)
//         00471df3     MOV        EAX,dword ptr [ESI + 0xc]
//         00471df6     MOV        dword ptr [ESI + 0x4],0x0
//         00471dfd     TEST       EAX,EAX
//         00471dff     MOV        dword ptr [ESI + 0x8],0x0
//         00471e06     JZ         LAB_00471e30
//                              player.cpp:2773 (12)
//         00471e08     MOV        EAX,dword ptr [ESI + 0x10]
//         00471e0b     PUSH       EAX
//         00471e0c     CALL       free                                             undefined free()
//         00471e11     ADD        ESP,0x4
//                              player.cpp:2774 (6)
//         00471e14     MOV        dword ptr [ESI],0x8
//                              player.cpp:2775 (15)
//         00471e1a     PUSH       0x8
//         00471e1c     PUSH       0x8
//         00471e1e     CALL       calloc                                           undefined calloc()
//         00471e23     ADD        ESP,0x8
//         00471e26     MOV        dword ptr [ESI + 0x10],EAX
//                              player.cpp:2776 (7)
//         00471e29     MOV        dword ptr [ESI + 0xc],0x0
//                               LAB_00471e30                                                 XREF[1]:     00471e06(j)
//                              player.cpp:2779 (2)
//         00471e30     POP        ESI
//         00471e31     RET
//         00471e32     ??         90h
//         00471e33     NOP
//         00471e34     NOP
//         00471e35     NOP
//         00471e36     NOP
//         00471e37     NOP
//         00471e38     NOP
//         00471e39     NOP
//         00471e3a     NOP
//         00471e3b     NOP
//         00471e3c     NOP
//         00471e3d     NOP
//         00471e3e     NOP
//         00471e3f     NOP
    return;
}

RGE_Tile_List::RGE_Tile_List(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Tile_List(RGE_Tile_List * this, int param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00471e42(R)
//                               ??0RGE_Tile_List@@QAE@H@Z                                    XREF[4]:     RGE_Player:0046e4ef(c),
//                               RGE_Tile_List::RGE_Tile_List                                              RGE_Player:0046e500(c),
//                                                                                                         RGE_Player:0046e7ab(c),
//                                                                                                         RGE_Player:0046e7bc(c)
//                              player.cpp:2783 (2)
//         00471e40     PUSH       ESI
//         00471e41     PUSH       EDI
//                              player.cpp:2786 (20)
//         00471e42     MOV        EDI,dword ptr [ESP + param_1]
//         00471e46     PUSH       0x8
//         00471e48     MOV        ESI,this
//         00471e4a     PUSH       EDI
//         00471e4b     CALL       calloc                                           undefined calloc()
//         00471e50     MOV        dword ptr [ESI + 0x10],EAX
//         00471e53     ADD        ESP,0x8
//                              player.cpp:2789 (7)
//         00471e56     XOR        EAX,EAX
//         00471e58     MOV        dword ptr [ESI],EDI
//         00471e5a     MOV        dword ptr [ESI + 0x4],EAX
//                              player.cpp:2790 (3)
//         00471e5d     MOV        dword ptr [ESI + 0x8],EAX
//                              player.cpp:2791 (3)
//         00471e60     MOV        dword ptr [ESI + 0xc],EAX
//                              player.cpp:2793 (7)
//         00471e63     MOV        EAX,ESI
//         00471e65     POP        EDI
//         00471e66     POP        ESI
//         00471e67     RET        0x4
//         00471e6a     ??         90h
//         00471e6b     NOP
//         00471e6c     NOP
//         00471e6d     NOP
//         00471e6e     NOP
//         00471e6f     NOP
}

RGE_Tile_List::~RGE_Tile_List() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Tile_List(RGE_Tile_List * this)
//              void              <VOID>         <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//                               ??1RGE_Tile_List@@QAE@XZ                                     XREF[2]:     ~RGE_Player:0046ec55(c),
//                               RGE_Tile_List::~RGE_Tile_List                                             ~RGE_Player:0046ec65(c)
//                              player.cpp:2797 (16)
//         00471e70     MOV        EAX,dword ptr [ECX + this->list]
//         00471e73     TEST       EAX,EAX
//         00471e75     JZ         LAB_00471e80
//         00471e77     PUSH       EAX
//         00471e78     CALL       free                                             undefined free()
//         00471e7d     ADD        ESP,0x4
//                               LAB_00471e80                                                 XREF[1]:     00471e75(j)
//                              player.cpp:2799 (1)
//         00471e80     RET
//         00471e81     ??         90h
//         00471e82     NOP
//         00471e83     NOP
//         00471e84     NOP
//         00471e85     NOP
//         00471e86     NOP
//         00471e87     NOP
//         00471e88     NOP
//         00471e89     NOP
//         00471e8a     NOP
//         00471e8b     NOP
//         00471e8c     NOP
//         00471e8d     NOP
//         00471e8e     NOP
//         00471e8f     NOP
}

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node** param_1, int* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_list_info(RGE_Tile_List * this, RGE_Tile_List_No
//              void              <VOID>         <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//              RGE_Tile_List_    Stack[0x4]:4   param_1                   XREF[1]:     00471e90(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     00471e9c(R)
//                               ?get_list_info@RGE_Tile_List@@QAEXAAPAURGE_Tile_List_Node@@  XREF[4]:     draw_explored_tiles:004376e9(c),
//                               RGE_Tile_List::get_list_info                                              update:004d8323(c),
//                                                                                                         view_function:0053605d(c),
//                                                                                                         Process_New_Tiles:0053be15(c)
//                              player.cpp:2803 (9)
//         00471e90     MOV        EDX,dword ptr [ESP + param_1]
//         00471e94     MOV        EAX,dword ptr [ECX + this->list]
//         00471e97     MOV        dword ptr [EDX],EAX
//                              player.cpp:2805 (9)
//         00471e99     MOV        EAX,dword ptr [ECX + this->num_active]
//         00471e9c     MOV        this,dword ptr [ESP + param_2]
//         00471ea0     MOV        dword ptr [this->list_size],EAX
//                              player.cpp:2806 (3)
//         00471ea2     RET        0x8
//         00471ea5     ??         90h
//         00471ea6     NOP
//         00471ea7     NOP
//         00471ea8     NOP
//         00471ea9     NOP
//         00471eaa     NOP
//         00471eab     NOP
//         00471eac     NOP
//         00471ead     NOP
//         00471eae     NOP
//         00471eaf     NOP
    return;
}

int RGE_Tile_List::get_new_count() {
    /* TODO: Stub */
//                              int __thiscall get_new_count(RGE_Tile_List * this)
//              int               EAX:4          <RETURN>
//              RGE_Tile_List *   ECX:4 (auto)   this
//                               ?get_new_count@RGE_Tile_List@@QAEHXZ                         XREF[1]:     update:004d8337(c)
//                               RGE_Tile_List::get_new_count
//                              player.cpp:2810 (3)
//         00471eb0     MOV        EAX,dword ptr [ECX + this->new_count]
//                              player.cpp:2814 (7)
//         00471eb3     MOV        dword ptr [ECX + this->new_count],0x0
//                              player.cpp:2816 (1)
//         00471eba     RET
//         00471ebb     ??         90h
//         00471ebc     NOP
//         00471ebd     NOP
//         00471ebe     NOP
//         00471ebf     NOP
    return 0;
}

