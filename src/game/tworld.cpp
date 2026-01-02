#include "../common.h"
#include "tworld.h"

TRIBE_World::TRIBE_World() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_World(TRIBE_World * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0052df89(W), 0052dfd8(W), 0052dfec(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e004(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052dfd2(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0052df7c(W)
//                               ??0TRIBE_World@@QAE@XZ                                       XREF[1]:     create_world:005227a5(c)
//                               TRIBE_World::TRIBE_World
//                              tworld.cpp:124 (39)
//         0052df60     PUSH       -0x1
//         0052df62     PUSH       FUN_005618d3
//         0052df67     MOV        EAX,FS:[0x0]
//         0052df6d     PUSH       EAX
//         0052df6e     MOV        dword ptr FS:[0x0],ESP
//         0052df75     SUB        ESP,0x8
//         0052df78     PUSH       EBX
//         0052df79     PUSH       ESI
//         0052df7a     MOV        ESI,this
//         0052df7c     MOV        dword ptr [ESP + local_14],ESI
//         0052df80     CALL       RGE_Game_World::RGE_Game_World                   undefined RGE_Game_World(RGE_Game_World * this)
//         0052df85     XOR        EBX,EBX
//                              tworld.cpp:135 (99)
//         0052df87     PUSH       0x50
//         0052df89     MOV        dword ptr [ESP + local_4],EBX
//         0052df8d     MOV        byte ptr [ESI + 0x11d],0xff
//         0052df94     MOV        dword ptr [ESI],TRIBE_World::`vftable'           = 0052e350
//         0052df9a     MOV        dword ptr [ESI + 0x104],EBX
//         0052dfa0     MOV        dword ptr [ESI + 0x108],EBX
//         0052dfa6     MOV        dword ptr [ESI + 0x10c],EBX
//         0052dfac     MOV        dword ptr [ESI + 0x110],EBX
//         0052dfb2     MOV        dword ptr [ESI + 0x120],EBX
//         0052dfb8     MOV        byte ptr [ESI + 0x114],BL
//         0052dfbe     MOV        dword ptr [ESI + 0x118],EBX
//         0052dfc4     MOV        byte ptr [ESI + 0x11c],BL
//         0052dfca     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052dfcf     ADD        ESP,0x4
//         0052dfd2     MOV        dword ptr [ESP + local_10],EAX
//         0052dfd6     CMP        EAX,EBX
//         0052dfd8     MOV        byte ptr [ESP + local_4],0x1
//         0052dfdd     JZ         LAB_0052dfe8
//         0052dfdf     MOV        this,EAX
//         0052dfe1     CALL       TribeAIPlayBook::TribeAIPlayBook                 undefined TribeAIPlayBook(TribeAIPlayBook * t
//         0052dfe6     JMP        LAB_0052dfea
//                               LAB_0052dfe8                                                 XREF[1]:     0052dfdd(j)
//         0052dfe8     XOR        EAX,EAX
//                               LAB_0052dfea                                                 XREF[1]:     0052dfe6(j)
//                              tworld.cpp:136 (14)
//         0052dfea     CMP        EAX,EBX
//         0052dfec     MOV        byte ptr [ESP + local_4],BL
//         0052dff0     MOV        dword ptr [ESI + 0xa0],EAX
//         0052dff6     JZ         LAB_0052e004
//                              tworld.cpp:137 (12)
//         0052dff8     PUSH       s_data\aoe.ply                                   = "data\\aoe.ply"
//         0052dffd     MOV        this,EAX
//         0052dfff     CALL       AIPlayBook::loadPlays                            int loadPlays(AIPlayBook * this, char * param
//                               LAB_0052e004                                                 XREF[1]:     0052dff6(j)
//                              tworld.cpp:138 (19)
//         0052e004     MOV        this,dword ptr [ESP + local_c]
//         0052e008     MOV        EAX,ESI
//         0052e00a     POP        ESI
//         0052e00b     MOV        dword ptr FS:[0x0],this
//         0052e012     POP        EBX
//         0052e013     ADD        ESP,0x14
//         0052e016     RET
//         0052e017     ??         90h
//         0052e018     NOP
//         0052e019     NOP
//         0052e01a     NOP
//         0052e01b     NOP
//         0052e01c     NOP
//         0052e01d     NOP
//         0052e01e     NOP
//         0052e01f     NOP
}

TRIBE_World::~TRIBE_World() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_World(TRIBE_World * this)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052e06a(W), 0052e092(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e09f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e05a(W)
//                               ??1TRIBE_World@@UAE@XZ                                       XREF[1]:     `scalar_deleting_destructor':0052e
//                               TRIBE_World::~TRIBE_World
//                              tworld.cpp:143 (36)
//         0052e040     PUSH       -0x1
//         0052e042     PUSH       FUN_005618e8
//         0052e047     MOV        EAX,FS:[0x0]
//         0052e04d     PUSH       EAX
//         0052e04e     MOV        dword ptr FS:[0x0],ESP
//         0052e055     PUSH       this
//         0052e056     PUSH       ESI
//         0052e057     MOV        ESI,this
//         0052e059     PUSH       EDI
//         0052e05a     MOV        dword ptr [ESP + local_10],ESI
//         0052e05e     MOV        dword ptr [ESI],TRIBE_World::`vftable'           = 0052e350
//                              tworld.cpp:144 (18)
//         0052e064     MOV        EDI,dword ptr [ESI + 0x104]
//         0052e06a     MOV        dword ptr [ESP + local_4],0x0
//         0052e072     TEST       EDI,EDI
//         0052e074     JZ         LAB_0052e090
//                              tworld.cpp:146 (16)
//         0052e076     MOV        this,EDI
//         0052e078     CALL       TRIBE_Tech::~TRIBE_Tech                          void ~TRIBE_Tech(TRIBE_Tech * this)
//         0052e07d     PUSH       EDI
//         0052e07e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0052e083     ADD        ESP,0x4
//                              tworld.cpp:147 (12)
//         0052e086     MOV        dword ptr [ESI + 0x104],0x0
//                               LAB_0052e090                                                 XREF[1]:     0052e074(j)
//         0052e090     MOV        this,ESI
//                              tworld.cpp:149 (30)
//         0052e092     MOV        dword ptr [ESP + local_4],0xffffffff
//         0052e09a     CALL       RGE_Game_World::~RGE_Game_World                  void ~RGE_Game_World(RGE_Game_World * this)
//         0052e09f     MOV        this,dword ptr [ESP + local_c]
//         0052e0a3     POP        EDI
//         0052e0a4     MOV        dword ptr FS:[0x0],this
//         0052e0ab     POP        ESI
//         0052e0ac     ADD        ESP,0x10
//         0052e0af     RET
}

void TRIBE_World::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall logStatus(TRIBE_World * this, _iobuf * param_1, int
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0052e0b7(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052e0c9(R)
//              char[256]         Stack[-0x104   tempString                XREF[2,1]:   0052e0e5(*), 0052e0f2(*), 0052e166(*)
//              long              Stack[-0x108   clock
//                               ?logStatus@TRIBE_World@@MAEXPAU_iobuf@@H@Z                   XREF[1]:     005774f4(*)
//                               TRIBE_World::logStatus
//                              tworld.cpp:155 (7)
//         0052e0b0     SUB        ESP,0x104
//         0052e0b6     PUSH       ESI
//                              tworld.cpp:157 (18)
//         0052e0b7     MOV        ESI,dword ptr [ESP + param_1]
//         0052e0be     PUSH       EDI
//         0052e0bf     MOV        EDI,this
//         0052e0c1     TEST       ESI,ESI
//         0052e0c3     JZ         LAB_0052e20b
//                              tworld.cpp:161 (14)
//         0052e0c9     CMP        dword ptr [ESP + param_2],0x1
//         0052e0d1     JNZ        LAB_0052e20b
//                              tworld.cpp:163 (14)
//         0052e0d7     PUSH       s____*****************************               = "\n\n\n************************************
//         0052e0dc     PUSH       ESI
//         0052e0dd     CALL       fprintf                                          undefined fprintf()
//         0052e0e2     ADD        ESP,0x8
//                              tworld.cpp:165 (13)
//         0052e0e5     LEA        EAX=>tempString,[ESP + 0x8]
//         0052e0e9     PUSH       EAX
//         0052e0ea     CALL       time                                             undefined time()
//         0052e0ef     ADD        ESP,0x4
//                              tworld.cpp:166 (13)
//         0052e0f2     LEA        this=>tempString,[ESP + 0x8]
//         0052e0f6     PUSH       this
//         0052e0f7     CALL       localtime                                        undefined localtime()
//         0052e0fc     ADD        ESP,0x4
//                              tworld.cpp:167 (21)
//         0052e0ff     PUSH       EAX
//         0052e100     CALL       asctime                                          undefined asctime()
//         0052e105     ADD        ESP,0x4
//         0052e108     PUSH       EAX
//         0052e109     PUSH       s_AI_Log_file_for_Game_Started_%s                = "AI Log file for Game Started %s"
//         0052e10e     PUSH       ESI
//         0052e10f     CALL       fprintf                                          undefined fprintf()
//                              tworld.cpp:168 (20)
//         0052e114     MOVSX      EDX,word ptr [EDI + 0x3c]
//         0052e118     ADD        ESP,0xc
//         0052e11b     DEC        EDX
//         0052e11c     PUSH       EDX
//         0052e11d     PUSH       s_Number_Players:__________%d_                   = "Number Players:          %d\n"
//         0052e122     PUSH       ESI
//         0052e123     CALL       fprintf                                          undefined fprintf()
//                              tworld.cpp:170 (30)
//         0052e128     MOV        EAX,dword ptr [EDI + 0x5c]
//         0052e12b     ADD        ESP,0xc
//         0052e12e     MOV        EDX,dword ptr [EAX + 0x1010]
//         0052e134     TEST       EDX,EDX
//         0052e136     JZ         LAB_0052e160
//         0052e138     MOV        EDI,EDX
//         0052e13a     OR         this,0xffffffff
//         0052e13d     XOR        EAX,EAX
//         0052e13f     SCASB.RE   ES:EDI
//         0052e141     NOT        this
//         0052e143     DEC        this
//         0052e144     JZ         LAB_0052e160
//                              tworld.cpp:171 (6)
//         0052e146     PUSH       EDX
//         0052e147     PUSH       s_Scenario:________________%s_                   = "Scenario:                %s\n"
//                              tworld.cpp:180 (9)
//         0052e14c     PUSH       ESI
//         0052e14d     CALL       fprintf                                          undefined fprintf()
//         0052e152     ADD        ESP,0xc
//                              tworld.cpp:183 (11)
//         0052e155     POP        EDI
//         0052e156     POP        ESI
//         0052e157     ADD        ESP,0x104
//         0052e15d     RET        0x8
//                               LAB_0052e160                                                 XREF[2]:     0052e136(j), 0052e144(j)
//                              tworld.cpp:175 (38)
//         0052e160     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e166     LEA        EDX=>tempString[4],[ESP + 0xc]
//         0052e16a     PUSH       0x100
//         0052e16f     PUSH       EDX
//         0052e170     MOV        EDI,dword ptr [this->_padding_]
//         0052e172     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         0052e177     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e17d     ADD        EAX,0x2973
//         0052e182     PUSH       EAX
//         0052e183     CALL       dword ptr [EDI + 0x20]
//                              tworld.cpp:176 (16)
//         0052e186     LEA        EAX,[ESP + 0xc]
//         0052e18a     PUSH       EAX
//         0052e18b     PUSH       s_Map_Size:________________%s_                   = "Map Size:                %s\n"
//         0052e190     PUSH       ESI
//         0052e191     CALL       fprintf                                          undefined fprintf()
//                              tworld.cpp:177 (41)
//         0052e196     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e19c     ADD        ESP,0xc
//         0052e19f     LEA        EDX,[ESP + 0xc]
//         0052e1a3     MOV        EDI,dword ptr [this->_padding_]
//         0052e1a5     PUSH       0x100
//         0052e1aa     PUSH       EDX
//         0052e1ab     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         0052e1b0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e1b6     ADD        EAX,0x296a
//         0052e1bb     PUSH       EAX
//         0052e1bc     CALL       dword ptr [EDI + 0x20]
//                              tworld.cpp:178 (16)
//         0052e1bf     LEA        EAX,[ESP + 0xc]
//         0052e1c3     PUSH       EAX
//         0052e1c4     PUSH       s_Map_Type:________________%s_                   = "Map Type:                %s\n"
//         0052e1c9     PUSH       ESI
//         0052e1ca     CALL       fprintf                                          undefined fprintf()
//                              tworld.cpp:179 (41)
//         0052e1cf     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e1d5     ADD        ESP,0xc
//         0052e1d8     LEA        EDX,[ESP + 0xc]
//         0052e1dc     MOV        EDI,dword ptr [this->_padding_]
//         0052e1de     PUSH       0x100
//         0052e1e3     PUSH       EDX
//         0052e1e4     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052e1e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052e1ef     ADD        EAX,0x28a6
//         0052e1f4     PUSH       EAX
//         0052e1f5     CALL       dword ptr [EDI + 0x20]
//                              tworld.cpp:180 (19)
//         0052e1f8     LEA        EAX,[ESP + 0xc]
//         0052e1fc     PUSH       EAX
//         0052e1fd     PUSH       s_Victory_Condition:_______%s_                   = "Victory Condition:       %s\n"
//         0052e202     PUSH       ESI
//         0052e203     CALL       fprintf                                          undefined fprintf()
//         0052e208     ADD        ESP,0xc
//                               LAB_0052e20b                                                 XREF[2]:     0052e0c3(j), 0052e0d1(j)
//                              tworld.cpp:183 (11)
//         0052e20b     POP        EDI
//         0052e20c     POP        ESI
//         0052e20d     ADD        ESP,0x104
//         0052e213     RET        0x8
//         0052e216     ??         90h
//         0052e217     NOP
//         0052e218     NOP
//         0052e219     NOP
//         0052e21a     NOP
//         0052e21b     NOP
//         0052e21c     NOP
//         0052e21d     NOP
//         0052e21e     NOP
//         0052e21f     NOP
    return;
}

void TRIBE_World::data_load_players_type(short param_1, short param_2, _iobuf* param_3) {
    /* TODO: Stub */
//                              void __thiscall data_load_players_type(TRIBE_World * this, short par
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     0052e248(R), 0052e290(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     0052e238(R), 0052e270(W)
//              _iobuf *          Stack[0xc]:4   param_3                   XREF[2]:     0052e242(R), 0052e280(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e276(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0052e254(R), 0052e29c(*)
//                               ?data_load_players_type@TRIBE_World@@UAEXFFPAU_iobuf@@@Z     XREF[1]:     00577474(*)
//                               TRIBE_World::data_load_players_type
//                              tworld.cpp:187 (24)
//         0052e220     MOV        EAX,FS:[0x0]
//         0052e226     PUSH       -0x1
//         0052e228     PUSH       FUN_0056190b
//         0052e22d     PUSH       EAX
//         0052e22e     MOV        dword ptr FS:[0x0],ESP
//         0052e235     PUSH       ESI
//         0052e236     MOV        ESI,this
//                              tworld.cpp:188 (10)
//         0052e238     MOV        this,dword ptr [ESP + param_2]
//         0052e23c     MOVSX      EAX,this
//         0052e23f     DEC        EAX
//         0052e240     JZ         LAB_0052e266
//                              tworld.cpp:194 (18)
//         0052e242     MOV        EAX,dword ptr [ESP + param_3]
//         0052e246     PUSH       EAX
//         0052e247     PUSH       this
//         0052e248     MOV        this,dword ptr [ESP + param_1]
//         0052e24c     PUSH       this
//         0052e24d     MOV        this,ESI
//         0052e24f     CALL       RGE_Game_World::data_load_players_type           void data_load_players_type(RGE_Game_World *
//                              tworld.cpp:197 (18)
//         0052e254     MOV        this,dword ptr [ESP + local_c]
//         0052e258     MOV        dword ptr FS:[0x0],this
//         0052e25f     POP        ESI
//         0052e260     ADD        ESP,0xc
//         0052e263     RET        0xc
//                               LAB_0052e266                                                 XREF[1]:     0052e240(j)
//                              tworld.cpp:191 (50)
//         0052e266     PUSH       0x2c
//         0052e268     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e26d     ADD        ESP,0x4
//         0052e270     MOV        dword ptr [ESP + param_2],EAX
//         0052e274     TEST       EAX,EAX
//         0052e276     MOV        dword ptr [ESP + local_4],0x0
//         0052e27e     JZ         LAB_0052e28e
//         0052e280     MOV        EDX,dword ptr [ESP + param_3]
//         0052e284     MOV        this,EAX
//         0052e286     PUSH       EDX
//         0052e287     CALL       TRIBE_Master_Player::TRIBE_Master_Player         undefined TRIBE_Master_Player(TRIBE_Master_Pl
//         0052e28c     JMP        LAB_0052e290
//                               LAB_0052e28e                                                 XREF[1]:     0052e27e(j)
//         0052e28e     XOR        EAX,EAX
//                               LAB_0052e290                                                 XREF[1]:     0052e28c(j)
//         0052e290     MOVSX      this,word ptr [ESP + param_1]
//         0052e295     MOV        EDX,dword ptr [ESI + 0x48]
//                              tworld.cpp:197 (21)
//         0052e298     POP        ESI
//         0052e299     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
//         0052e29c     MOV        this,dword ptr [ESP]=>local_c
//         0052e2a0     MOV        dword ptr FS:[0x0],this
//         0052e2a7     ADD        ESP,0xc
//         0052e2aa     RET        0xc
//         0052e2ad     ??         90h
//         0052e2ae     NOP
//         0052e2af     NOP
    return;
}

void TRIBE_World::data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9) {
    /* TODO: Stub */
//                              void __thiscall data_load_map(TRIBE_World * this, char * param_1, ch
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0052e308(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     0052e303(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     0052e2fe(R)
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     0052e2f9(R)
//              short             Stack[0x14]:2  param_5                   XREF[1]:     0052e2f4(R)
//              short             Stack[0x18]:2  param_6                   XREF[1]:     0052e2ef(R)
//              short             Stack[0x1c]:2  param_7                   XREF[1]:     0052e2ea(R)
//              RGE_Sound * *     Stack[0x20]:4  param_8                   XREF[1]:     0052e2e6(R)
//              char *            Stack[0x24]:4  param_9                   XREF[1]:     0052e319(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052e2dc(W), 0052e31d(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e330(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e2d6(W)
//                               ?data_load_map@TRIBE_World@@UAEXPAD000FFFPAPAVRGE_Sound@@0@Z XREF[1]:     0057747c(*)
//                               TRIBE_World::data_load_map
//                              tworld.cpp:201 (25)
//         0052e2b0     PUSH       -0x1
//         0052e2b2     PUSH       FUN_0056192b
//         0052e2b7     MOV        EAX,FS:[0x0]
//         0052e2bd     PUSH       EAX
//         0052e2be     MOV        dword ptr FS:[0x0],ESP
//         0052e2c5     PUSH       this
//         0052e2c6     PUSH       ESI
//         0052e2c7     MOV        ESI,this
//                              tworld.cpp:204 (80)
//         0052e2c9     PUSH       0xb5f8
//         0052e2ce     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e2d3     ADD        ESP,0x4
//         0052e2d6     MOV        dword ptr [ESP + local_10],EAX
//         0052e2da     TEST       EAX,EAX
//         0052e2dc     MOV        dword ptr [ESP + local_4],0x0
//         0052e2e4     JZ         LAB_0052e317
//         0052e2e6     MOV        this,dword ptr [ESP + param_8]
//         0052e2ea     MOV        EDX,dword ptr [ESP + param_7]
//         0052e2ee     PUSH       this
//         0052e2ef     MOV        this,dword ptr [ESP + param_6]
//         0052e2f3     PUSH       EDX
//         0052e2f4     MOV        EDX,dword ptr [ESP + param_5]
//         0052e2f8     PUSH       this
//         0052e2f9     MOV        this,dword ptr [ESP + param_4]
//         0052e2fd     PUSH       EDX
//         0052e2fe     MOV        EDX,dword ptr [ESP + param_3]
//         0052e302     PUSH       this
//         0052e303     MOV        this,dword ptr [ESP + param_2]
//         0052e307     PUSH       EDX
//         0052e308     MOV        EDX,dword ptr [ESP + param_1]
//         0052e30c     PUSH       this
//         0052e30d     PUSH       EDX
//         0052e30e     MOV        this,EAX
//         0052e310     CALL       TRIBE_Map::TRIBE_Map                             undefined TRIBE_Map(TRIBE_Map * this, char *
//         0052e315     JMP        LAB_0052e319
//                               LAB_0052e317                                                 XREF[1]:     0052e2e4(j)
//         0052e317     XOR        EAX,EAX
//                               LAB_0052e319                                                 XREF[1]:     0052e315(j)
//                              tworld.cpp:205 (23)
//         0052e319     MOV        this,dword ptr [ESP + param_9]
//         0052e31d     MOV        dword ptr [ESP + local_4],0xffffffff
//         0052e325     PUSH       this
//         0052e326     MOV        this,EAX
//         0052e328     MOV        dword ptr [ESI + 0x28],EAX
//         0052e32b     CALL       RGE_Map::load_terrain_obj_types                  void load_terrain_obj_types(RGE_Map * this, c
//                              tworld.cpp:206 (18)
//         0052e330     MOV        this,dword ptr [ESP + local_c]
//         0052e334     POP        ESI
//         0052e335     MOV        dword ptr FS:[0x0],this
//         0052e33c     ADD        ESP,0x10
//         0052e33f     RET        0x24
//         0052e342     ??         90h
//         0052e343     NOP
//         0052e344     NOP
//         0052e345     NOP
//         0052e346     NOP
//         0052e347     NOP
//         0052e348     NOP
//         0052e349     NOP
//         0052e34a     NOP
//         0052e34b     NOP
//         0052e34c     NOP
//         0052e34d     NOP
//         0052e34e     NOP
//         0052e34f     NOP
    return;
}

uchar TRIBE_World::data_load_world(_iobuf* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall data_load_world(TRIBE_World * this, _iobuf * param_1)
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0052e36b(R), 0052e394(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e39c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e3b2(R)
//              char[23]          Stack[-0x28]   tech_file                 XREF[0,2]:   0052e377(*), 0052e3a2(*)
//                               ?data_load_world@TRIBE_World@@UAEEPAU_iobuf@@@Z              XREF[1]:     00577458(*)
//                               TRIBE_World::data_load_world
//                              tworld.cpp:210 (27)
//         0052e350     PUSH       -0x1
//         0052e352     PUSH       FUN_0056194b
//         0052e357     MOV        EAX,FS:[0x0]
//         0052e35d     PUSH       EAX
//         0052e35e     MOV        dword ptr FS:[0x0],ESP
//         0052e365     SUB        ESP,0x18
//         0052e368     PUSH       EBX
//         0052e369     PUSH       ESI
//         0052e36a     PUSH       EDI
//                              tworld.cpp:213 (12)
//         0052e36b     MOV        EDI,dword ptr [ESP + param_1]
//         0052e36f     MOV        ESI,this
//         0052e371     PUSH       EDI
//         0052e372     CALL       RGE_Game_World::data_load_world                  uchar data_load_world(RGE_Game_World * this,
//                              tworld.cpp:215 (19)
//         0052e377     LEA        EAX=>tech_file[4],[ESP + 0xc]
//         0052e37b     PUSH       EAX
//         0052e37c     PUSH       s_%s_                                            = "%s "
//         0052e381     PUSH       EDI
//         0052e382     CALL       fscanf                                           undefined fscanf()
//         0052e387     ADD        ESP,0xc
//                              tworld.cpp:217 (40)
//         0052e38a     PUSH       0xc
//         0052e38c     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e391     ADD        ESP,0x4
//         0052e394     MOV        dword ptr [ESP + param_1],EAX
//         0052e398     XOR        EBX,EBX
//         0052e39a     CMP        EAX,EBX
//         0052e39c     MOV        dword ptr [ESP + local_4],EBX
//         0052e3a0     JZ         LAB_0052e3b0
//         0052e3a2     LEA        this=>tech_file[4],[ESP + 0xc]
//         0052e3a6     PUSH       this
//         0052e3a7     MOV        this,EAX
//         0052e3a9     CALL       TRIBE_Tech::TRIBE_Tech                           undefined TRIBE_Tech(TRIBE_Tech * this, char
//         0052e3ae     JMP        LAB_0052e3b2
//                               LAB_0052e3b0                                                 XREF[1]:     0052e3a0(j)
//         0052e3b0     XOR        EAX,EAX
//                               LAB_0052e3b2                                                 XREF[1]:     0052e3ae(j)
//                              tworld.cpp:227 (64)
//         0052e3b2     MOV        this,dword ptr [ESP + local_c]
//         0052e3b6     MOV        dword ptr [ESI + 0x104],EAX
//         0052e3bc     MOV        dword ptr [ESI + 0x108],EBX
//         0052e3c2     MOV        dword ptr [ESI + 0x10c],EBX
//         0052e3c8     MOV        dword ptr [ESI + 0x110],EBX
//         0052e3ce     MOV        byte ptr [ESI + 0x114],BL
//         0052e3d4     MOV        dword ptr [ESI + 0x118],EBX
//         0052e3da     MOV        byte ptr [ESI + 0x11c],BL
//         0052e3e0     POP        EDI
//         0052e3e1     POP        ESI
//         0052e3e2     MOV        AL,0x1
//         0052e3e4     MOV        dword ptr FS:[0x0],this
//         0052e3eb     POP        EBX
//         0052e3ec     ADD        ESP,0x24
//         0052e3ef     RET        0x4
//         0052e3f2     ??         90h
//         0052e3f3     NOP
//         0052e3f4     NOP
//         0052e3f5     NOP
//         0052e3f6     NOP
//         0052e3f7     NOP
//         0052e3f8     NOP
//         0052e3f9     NOP
//         0052e3fa     NOP
//         0052e3fb     NOP
//         0052e3fc     NOP
//         0052e3fd     NOP
//         0052e3fe     NOP
//         0052e3ff     NOP
    return 0;
}

uchar TRIBE_World::init_player_type(int param_1, short param_2, uchar param_3) {
    /* TODO: Stub */
//                              uchar __thiscall init_player_type(TRIBE_World * this, int param_1, s
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     0052e42b(R), 0052e459(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     0052e426(R), 0052e475(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0052e418(R), 0052e455(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052e45d(W), 0052e47d(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e438(R)
//                               ?init_player_type@TRIBE_World@@UAEEHFE@Z                     XREF[1]:     00577484(*)
//                               TRIBE_World::init_player_type
//                              tworld.cpp:231 (24)
//         0052e400     MOV        EAX,FS:[0x0]
//         0052e406     PUSH       -0x1
//         0052e408     PUSH       FUN_0056196b
//         0052e40d     PUSH       EAX
//         0052e40e     MOV        dword ptr FS:[0x0],ESP
//         0052e415     PUSH       ESI
//         0052e416     MOV        ESI,this
//                              tworld.cpp:232 (14)
//         0052e418     MOV        this,dword ptr [ESP + param_3]
//         0052e41c     MOV        EAX,this
//         0052e41e     AND        EAX,0xff
//         0052e423     DEC        EAX
//         0052e424     JZ         LAB_0052e44a
//                              tworld.cpp:239 (18)
//         0052e426     MOV        EAX,dword ptr [ESP + param_2]
//         0052e42a     PUSH       this
//         0052e42b     MOV        this,dword ptr [ESP + param_1]
//         0052e42f     PUSH       EAX
//         0052e430     PUSH       this
//         0052e431     MOV        this,ESI
//         0052e433     CALL       RGE_Game_World::init_player_type                 uchar init_player_type(RGE_Game_World * this,
//                              tworld.cpp:244 (18)
//         0052e438     MOV        this,dword ptr [ESP + local_c]
//         0052e43c     MOV        dword ptr FS:[0x0],this
//         0052e443     POP        ESI
//         0052e444     ADD        ESP,0xc
//         0052e447     RET        0xc
//                               LAB_0052e44a                                                 XREF[1]:     0052e424(j)
//                              tworld.cpp:231 (1)
//         0052e44a     PUSH       EDI
//                              tworld.cpp:235 (64)
//         0052e44b     PUSH       0x2c
//         0052e44d     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e452     ADD        ESP,0x4
//         0052e455     MOV        dword ptr [ESP + param_3],EAX
//         0052e459     MOV        EDI,dword ptr [ESP + param_1]
//         0052e45d     MOV        dword ptr [ESP + local_4],0x0
//         0052e465     TEST       EAX,EAX
//         0052e467     JZ         LAB_0052e473
//         0052e469     PUSH       EDI
//         0052e46a     MOV        this,EAX
//         0052e46c     CALL       TRIBE_Master_Player::TRIBE_Master_Player         undefined TRIBE_Master_Player(TRIBE_Master_Pl
//         0052e471     JMP        LAB_0052e475
//                               LAB_0052e473                                                 XREF[1]:     0052e467(j)
//         0052e473     XOR        EAX,EAX
//                               LAB_0052e475                                                 XREF[1]:     0052e471(j)
//         0052e475     MOVSX      this,word ptr [ESP + param_2]
//         0052e47a     MOV        EDX,dword ptr [ESI + 0x48]
//         0052e47d     MOV        dword ptr [ESP + local_4],0xffffffff
//         0052e485     SHL        this,0x2
//         0052e488     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
//                              tworld.cpp:236 (20)
//         0052e48b     MOV        EAX,dword ptr [ESI + 0x48]
//         0052e48e     MOV        this,dword ptr [EAX + this->_padding_*0x1]
//         0052e491     MOV        EAX,dword ptr [ESI + 0x30]
//         0052e494     PUSH       EAX
//         0052e495     MOV        EAX,dword ptr [ESI + 0x38]
//         0052e498     MOV        EDX,dword ptr [this->_padding_]
//         0052e49a     PUSH       EAX
//         0052e49b     PUSH       EDI
//         0052e49c     CALL       dword ptr [EDX + 0x4]
//                              tworld.cpp:244 (21)
//         0052e49f     MOV        this,dword ptr [ESP + 0x8]
//         0052e4a3     POP        EDI
//         0052e4a4     MOV        AL,0x1
//         0052e4a6     MOV        dword ptr FS:[0x0],this
//         0052e4ad     POP        ESI
//         0052e4ae     ADD        ESP,0xc
//         0052e4b1     RET        0xc
//         0052e4b4     ??         90h
//         0052e4b5     NOP
//         0052e4b6     NOP
//         0052e4b7     NOP
//         0052e4b8     NOP
//         0052e4b9     NOP
//         0052e4ba     NOP
//         0052e4bb     NOP
//         0052e4bc     NOP
//         0052e4bd     NOP
//         0052e4be     NOP
//         0052e4bf     NOP
    return 0;
}

void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
    /* TODO: Stub */
//                              void __thiscall map_init(TRIBE_World * this, int param_1, TSound_Dri
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052e4f9(R)
//              TSound_Driver *   Stack[0x8]:4   param_2
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e4ec(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e50c(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e4e6(W)
//                               ?map_init@TRIBE_World@@UAEXHPAVTSound_Driver@@@Z             XREF[1]:     005774a0(*)
//                               TRIBE_World::map_init
//                              tworld.cpp:249 (25)
//         0052e4c0     PUSH       -0x1
//         0052e4c2     PUSH       FUN_0056198b
//         0052e4c7     MOV        EAX,FS:[0x0]
//         0052e4cd     PUSH       EAX
//         0052e4ce     MOV        dword ptr FS:[0x0],ESP
//         0052e4d5     PUSH       this
//         0052e4d6     PUSH       ESI
//         0052e4d7     MOV        ESI,this
//                              tworld.cpp:251 (51)
//         0052e4d9     PUSH       0xb5f8
//         0052e4de     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e4e3     ADD        ESP,0x4
//         0052e4e6     MOV        dword ptr [ESP + local_10],EAX
//         0052e4ea     TEST       EAX,EAX
//         0052e4ec     MOV        dword ptr [ESP + local_4],0x0
//         0052e4f4     JZ         LAB_0052e50a
//         0052e4f6     MOV        this,dword ptr [ESI + 0x30]
//         0052e4f9     MOV        EDX,dword ptr [ESP + param_1]
//         0052e4fd     PUSH       0x1
//         0052e4ff     PUSH       this
//         0052e500     PUSH       EDX
//         0052e501     MOV        this,EAX
//         0052e503     CALL       TRIBE_Map::TRIBE_Map                             undefined TRIBE_Map(TRIBE_Map * this, int par
//         0052e508     JMP        LAB_0052e50c
//                               LAB_0052e50a                                                 XREF[1]:     0052e4f4(j)
//         0052e50a     XOR        EAX,EAX
//                               LAB_0052e50c                                                 XREF[1]:     0052e508(j)
//                              tworld.cpp:252 (21)
//         0052e50c     MOV        this,dword ptr [ESP + local_c]
//         0052e510     MOV        dword ptr [ESI + 0x28],EAX
//         0052e513     MOV        dword ptr FS:[0x0],this
//         0052e51a     POP        ESI
//         0052e51b     ADD        ESP,0x10
//         0052e51e     RET        0x8
//         0052e521     ??         90h
//         0052e522     NOP
//         0052e523     NOP
//         0052e524     NOP
//         0052e525     NOP
//         0052e526     NOP
//         0052e527     NOP
//         0052e528     NOP
//         0052e529     NOP
//         0052e52a     NOP
//         0052e52b     NOP
//         0052e52c     NOP
//         0052e52d     NOP
//         0052e52e     NOP
//         0052e52f     NOP
    return;
}

void TRIBE_World::command_init(int param_1, TCommunications_Handler* param_2) {
    /* TODO: Stub */
//                              void __thiscall command_init(TRIBE_World * this, int param_1, TCommu
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              TCommunication    Stack[0x8]:4   param_2                   XREF[1]:     0052e563(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e559(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e574(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e553(W)
//                               ?command_init@TRIBE_World@@UAEXHPAVTCommunications_Handler@  XREF[1]:     005774ac(*)
//                               TRIBE_World::command_init
//                              tworld.cpp:257 (25)
//         0052e530     PUSH       -0x1
//         0052e532     PUSH       FUN_005619ab
//         0052e537     MOV        EAX,FS:[0x0]
//         0052e53d     PUSH       EAX
//         0052e53e     MOV        dword ptr FS:[0x0],ESP
//         0052e545     PUSH       this
//         0052e546     PUSH       ESI
//         0052e547     MOV        ESI,this
//                              tworld.cpp:258 (43)
//         0052e549     PUSH       0x18
//         0052e54b     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e550     ADD        ESP,0x4
//         0052e553     MOV        dword ptr [ESP + local_10],EAX
//         0052e557     TEST       EAX,EAX
//         0052e559     MOV        dword ptr [ESP + local_4],0x0
//         0052e561     JZ         LAB_0052e572
//         0052e563     MOV        this,dword ptr [ESP + param_2]
//         0052e567     PUSH       this
//         0052e568     PUSH       ESI
//         0052e569     MOV        this,EAX
//         0052e56b     CALL       TRIBE_Command::TRIBE_Command                     undefined TRIBE_Command(TRIBE_Command * this,
//         0052e570     JMP        LAB_0052e574
//                               LAB_0052e572                                                 XREF[1]:     0052e561(j)
//         0052e572     XOR        EAX,EAX
//                               LAB_0052e574                                                 XREF[1]:     0052e570(j)
//                              tworld.cpp:259 (21)
//         0052e574     MOV        this,dword ptr [ESP + local_c]
//         0052e578     MOV        dword ptr [ESI + 0x58],EAX
//         0052e57b     MOV        dword ptr FS:[0x0],this
//         0052e582     POP        ESI
//         0052e583     ADD        ESP,0x10
//         0052e586     RET        0x8
//         0052e589     ??         90h
//         0052e58a     NOP
//         0052e58b     NOP
//         0052e58c     NOP
//         0052e58d     NOP
//         0052e58e     NOP
//         0052e58f     NOP
    return;
}

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
//                              void __thiscall scenario_init(TRIBE_World * this, RGE_Game_World * p
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0052e626(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e61c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e636(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e616(W)
//                               ?scenario_init@TRIBE_World@@UAEXPAVRGE_Game_World@@@Z        XREF[1]:     00577548(*)
//                               TRIBE_World::scenario_init
//                              tworld.cpp:269 (25)
//         0052e5f0     PUSH       -0x1
//         0052e5f2     PUSH       FUN_005619eb
//         0052e5f7     MOV        EAX,FS:[0x0]
//         0052e5fd     PUSH       EAX
//         0052e5fe     MOV        dword ptr FS:[0x0],ESP
//         0052e605     PUSH       this
//         0052e606     PUSH       ESI
//         0052e607     MOV        ESI,this
//                              tworld.cpp:270 (45)
//         0052e609     PUSH       0x514c
//         0052e60e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e613     ADD        ESP,0x4
//         0052e616     MOV        dword ptr [ESP + local_10],EAX
//         0052e61a     TEST       EAX,EAX
//         0052e61c     MOV        dword ptr [ESP + local_4],0x0
//         0052e624     JZ         LAB_0052e634
//         0052e626     MOV        this,dword ptr [ESP + param_1]
//         0052e62a     PUSH       this
//         0052e62b     MOV        this,EAX
//         0052e62d     CALL       T_Scenario::T_Scenario                           undefined T_Scenario(T_Scenario * this, RGE_G
//         0052e632     JMP        LAB_0052e636
//                               LAB_0052e634                                                 XREF[1]:     0052e624(j)
//         0052e634     XOR        EAX,EAX
//                               LAB_0052e636                                                 XREF[1]:     0052e632(j)
//                              tworld.cpp:271 (21)
//         0052e636     MOV        this,dword ptr [ESP + local_c]
//         0052e63a     MOV        dword ptr [ESI + 0x5c],EAX
//         0052e63d     MOV        dword ptr FS:[0x0],this
//         0052e644     POP        ESI
//         0052e645     ADD        ESP,0x10
//         0052e648     RET        0x4
//         0052e64b     ??         90h
//         0052e64c     NOP
//         0052e64d     NOP
//         0052e64e     NOP
//         0052e64f     NOP
    return;
}

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    /* TODO: Stub */
//                              void __thiscall scenario_init(TRIBE_World * this, RGE_Game_World * p
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0052e626(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e61c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e636(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e616(W)
//                               ?scenario_init@TRIBE_World@@UAEXPAVRGE_Game_World@@@Z        XREF[1]:     00577548(*)
//                               TRIBE_World::scenario_init
//                              tworld.cpp:269 (25)
//         0052e5f0     PUSH       -0x1
//         0052e5f2     PUSH       FUN_005619eb
//         0052e5f7     MOV        EAX,FS:[0x0]
//         0052e5fd     PUSH       EAX
//         0052e5fe     MOV        dword ptr FS:[0x0],ESP
//         0052e605     PUSH       this
//         0052e606     PUSH       ESI
//         0052e607     MOV        ESI,this
//                              tworld.cpp:270 (45)
//         0052e609     PUSH       0x514c
//         0052e60e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e613     ADD        ESP,0x4
//         0052e616     MOV        dword ptr [ESP + local_10],EAX
//         0052e61a     TEST       EAX,EAX
//         0052e61c     MOV        dword ptr [ESP + local_4],0x0
//         0052e624     JZ         LAB_0052e634
//         0052e626     MOV        this,dword ptr [ESP + param_1]
//         0052e62a     PUSH       this
//         0052e62b     MOV        this,EAX
//         0052e62d     CALL       T_Scenario::T_Scenario                           undefined T_Scenario(T_Scenario * this, RGE_G
//         0052e632     JMP        LAB_0052e636
//                               LAB_0052e634                                                 XREF[1]:     0052e624(j)
//         0052e634     XOR        EAX,EAX
//                               LAB_0052e636                                                 XREF[1]:     0052e632(j)
//                              tworld.cpp:271 (21)
//         0052e636     MOV        this,dword ptr [ESP + local_c]
//         0052e63a     MOV        dword ptr [ESI + 0x5c],EAX
//         0052e63d     MOV        dword ptr FS:[0x0],this
//         0052e644     POP        ESI
//         0052e645     ADD        ESP,0x10
//         0052e648     RET        0x4
//         0052e64b     ??         90h
//         0052e64c     NOP
//         0052e64d     NOP
//         0052e64e     NOP
//         0052e64f     NOP
    return;
}

void TRIBE_World::effects_init(int param_1) {
    /* TODO: Stub */
//                              void __thiscall effects_init(TRIBE_World * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052e683(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e679(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e693(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e673(W)
//                               ?effects_init@TRIBE_World@@UAEXH@Z                           XREF[1]:     005774a4(*)
//                               TRIBE_World::effects_init
//                              tworld.cpp:276 (25)
//         0052e650     PUSH       -0x1
//         0052e652     PUSH       FUN_00561a0b
//         0052e657     MOV        EAX,FS:[0x0]
//         0052e65d     PUSH       EAX
//         0052e65e     MOV        dword ptr FS:[0x0],ESP
//         0052e665     PUSH       this
//         0052e666     PUSH       ESI
//         0052e667     MOV        ESI,this
//                              tworld.cpp:277 (42)
//         0052e669     PUSH       0xc
//         0052e66b     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e670     ADD        ESP,0x4
//         0052e673     MOV        dword ptr [ESP + local_10],EAX
//         0052e677     TEST       EAX,EAX
//         0052e679     MOV        dword ptr [ESP + local_4],0x0
//         0052e681     JZ         LAB_0052e691
//         0052e683     MOV        this,dword ptr [ESP + param_1]
//         0052e687     PUSH       this
//         0052e688     MOV        this,EAX
//         0052e68a     CALL       TRIBE_Effects::TRIBE_Effects                     undefined TRIBE_Effects(TRIBE_Effects * this,
//         0052e68f     JMP        LAB_0052e693
//                               LAB_0052e691                                                 XREF[1]:     0052e681(j)
//         0052e691     XOR        EAX,EAX
//                               LAB_0052e693                                                 XREF[1]:     0052e68f(j)
//                              tworld.cpp:278 (21)
//         0052e693     MOV        this,dword ptr [ESP + local_c]
//         0052e697     MOV        dword ptr [ESI + 0x4c],EAX
//         0052e69a     MOV        dword ptr FS:[0x0],this
//         0052e6a1     POP        ESI
//         0052e6a2     ADD        ESP,0x10
//         0052e6a5     RET        0x4
//         0052e6a8     ??         90h
//         0052e6a9     NOP
//         0052e6aa     NOP
//         0052e6ab     NOP
//         0052e6ac     NOP
//         0052e6ad     NOP
//         0052e6ae     NOP
//         0052e6af     NOP
    return;
}

void TRIBE_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    /* TODO: Stub */
//                              void __thiscall world_init(TRIBE_World * this, int param_1, TSound_D
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052e6d2(R)
//              TSound_Driver *   Stack[0x8]:4   param_2                   XREF[1]:     0052e6ce(R)
//              TCommunication    Stack[0xc]:4   param_3                   XREF[2]:     0052e6be(R), 0052e6ea(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e6f2(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e705(R)
//                               ?world_init@TRIBE_World@@UAEXHPAVTSound_Driver@@PAVTCommuni  XREF[1]:     005774b0(*)
//                               TRIBE_World::world_init
//                              tworld.cpp:282 (14)
//         0052e6b0     MOV        EAX,FS:[0x0]
//         0052e6b6     PUSH       -0x1
//         0052e6b8     PUSH       FUN_00561a2b
//         0052e6bd     PUSH       EAX
//                              tworld.cpp:283 (34)
//         0052e6be     MOV        EAX,dword ptr [ESP + param_3]
//         0052e6c2     MOV        dword ptr FS:[0x0],ESP
//         0052e6c9     PUSH       EBX
//         0052e6ca     PUSH       ESI
//         0052e6cb     MOV        ESI,this
//         0052e6cd     PUSH       EDI
//         0052e6ce     MOV        this,dword ptr [ESP + param_2]
//         0052e6d2     MOV        EDI,dword ptr [ESP + param_1]
//         0052e6d6     PUSH       EAX
//         0052e6d7     PUSH       this
//         0052e6d8     PUSH       EDI
//         0052e6d9     MOV        this,ESI
//         0052e6db     CALL       RGE_Game_World::world_init                       void world_init(RGE_Game_World * this, int pa
//                              tworld.cpp:285 (37)
//         0052e6e0     PUSH       0xc
//         0052e6e2     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e6e7     ADD        ESP,0x4
//         0052e6ea     MOV        dword ptr [ESP + param_3],EAX
//         0052e6ee     XOR        EBX,EBX
//         0052e6f0     CMP        EAX,EBX
//         0052e6f2     MOV        dword ptr [ESP + local_4],EBX
//         0052e6f6     JZ         LAB_0052e703
//         0052e6f8     PUSH       ESI
//         0052e6f9     PUSH       EDI
//         0052e6fa     MOV        this,EAX
//         0052e6fc     CALL       TRIBE_Tech::TRIBE_Tech                           undefined TRIBE_Tech(TRIBE_Tech * this, int p
//         0052e701     JMP        LAB_0052e705
//                               LAB_0052e703                                                 XREF[1]:     0052e6f6(j)
//         0052e703     XOR        EAX,EAX
//                               LAB_0052e705                                                 XREF[1]:     0052e701(j)
//                              tworld.cpp:293 (62)
//         0052e705     MOV        this,dword ptr [ESP + local_c]
//         0052e709     MOV        dword ptr [ESI + 0x104],EAX
//         0052e70f     MOV        dword ptr [ESI + 0x108],EBX
//         0052e715     MOV        dword ptr [ESI + 0x10c],EBX
//         0052e71b     MOV        dword ptr [ESI + 0x110],EBX
//         0052e721     MOV        byte ptr [ESI + 0x114],BL
//         0052e727     MOV        dword ptr [ESI + 0x118],EBX
//         0052e72d     MOV        byte ptr [ESI + 0x11c],BL
//         0052e733     POP        EDI
//         0052e734     POP        ESI
//         0052e735     MOV        dword ptr FS:[0x0],this
//         0052e73c     POP        EBX
//         0052e73d     ADD        ESP,0xc
//         0052e740     RET        0xc
//         0052e743     ??         90h
//         0052e744     NOP
//         0052e745     NOP
//         0052e746     NOP
//         0052e747     NOP
//         0052e748     NOP
//         0052e749     NOP
//         0052e74a     NOP
//         0052e74b     NOP
//         0052e74c     NOP
//         0052e74d     NOP
//         0052e74e     NOP
//         0052e74f     NOP
    return;
}

uchar TRIBE_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    /* TODO: Stub */
//                              uchar __thiscall init(TRIBE_World * this, char * param_1, TSound_Dri
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0052e759(R)
//              TSound_Driver *   Stack[0x8]:4   param_2                   XREF[1]:     0052e754(R)
//              TCommunication    Stack[0xc]:4   param_3                   XREF[1]:     0052e750(R)
//                               ?init@TRIBE_World@@UAEEPADPAVTSound_Driver@@PAVTCommunicati  XREF[1]:     00577508(*)
//                               TRIBE_World::init
//                              tworld.cpp:297 (20)
//         0052e750     MOV        EAX,dword ptr [ESP + param_3]
//         0052e754     MOV        EDX,dword ptr [ESP + param_2]
//         0052e758     PUSH       EAX
//         0052e759     MOV        EAX,dword ptr [ESP + param_1]
//         0052e75d     PUSH       EDX
//         0052e75e     PUSH       EAX
//         0052e75f     CALL       RGE_Game_World::init                             uchar init(RGE_Game_World * this, char * para
//                              tworld.cpp:303 (3)
//         0052e764     RET        0xc
//         0052e767     ??         90h
//         0052e768     NOP
//         0052e769     NOP
//         0052e76a     NOP
//         0052e76b     NOP
//         0052e76c     NOP
//         0052e76d     NOP
//         0052e76e     NOP
//         0052e76f     NOP
    return 0;
}

void TRIBE_World::base_save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall base_save(TRIBE_World * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052e772(R)
//                               ?base_save@TRIBE_World@@UAEXH@Z                              XREF[1]:     00577538(*)
//                               TRIBE_World::base_save
//                              tworld.cpp:307 (2)
//         0052e770     PUSH       ESI
//         0052e771     PUSH       EDI
//                              tworld.cpp:308 (12)
//         0052e772     MOV        EDI,dword ptr [ESP + param_1]
//         0052e776     MOV        ESI,this
//         0052e778     PUSH       EDI
//         0052e779     CALL       RGE_Game_World::base_save                        void base_save(RGE_Game_World * this, int par
//                              tworld.cpp:309 (12)
//         0052e77e     MOV        this,dword ptr [ESI + 0x104]
//         0052e784     PUSH       EDI
//         0052e785     CALL       TRIBE_Tech::save                                 void save(TRIBE_Tech * this, int param_1)
//                              tworld.cpp:310 (5)
//         0052e78a     POP        EDI
//         0052e78b     POP        ESI
//         0052e78c     RET        0x4
//         0052e78f     ??         90h
    return;
}

void TRIBE_World::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_World * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052e792(R)
//                               ?save@TRIBE_World@@UAEXH@Z                                   XREF[1]:     005774c0(*)
//                               TRIBE_World::save
//                              tworld.cpp:314 (2)
//         0052e790     PUSH       ESI
//         0052e791     PUSH       EDI
//                              tworld.cpp:315 (12)
//         0052e792     MOV        EDI,dword ptr [ESP + param_1]
//         0052e796     MOV        ESI,this
//         0052e798     PUSH       EDI
//         0052e799     CALL       RGE_Game_World::save                             void save(RGE_Game_World * this, int param_1)
//                              tworld.cpp:317 (18)
//         0052e79e     LEA        EAX,[ESI + 0x108]
//         0052e7a4     PUSH       0x4
//         0052e7a6     PUSH       EAX
//         0052e7a7     PUSH       EDI
//         0052e7a8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e7ad     ADD        ESP,0xc
//                              tworld.cpp:318 (18)
//         0052e7b0     LEA        this,[ESI + 0x10c]
//         0052e7b6     PUSH       0x4
//         0052e7b8     PUSH       this
//         0052e7b9     PUSH       EDI
//         0052e7ba     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e7bf     ADD        ESP,0xc
//                              tworld.cpp:319 (18)
//         0052e7c2     LEA        EDX,[ESI + 0x110]
//         0052e7c8     PUSH       0x4
//         0052e7ca     PUSH       EDX
//         0052e7cb     PUSH       EDI
//         0052e7cc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e7d1     ADD        ESP,0xc
//                              tworld.cpp:320 (18)
//         0052e7d4     LEA        EAX,[ESI + 0x114]
//         0052e7da     PUSH       0x1
//         0052e7dc     PUSH       EAX
//         0052e7dd     PUSH       EDI
//         0052e7de     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e7e3     ADD        ESP,0xc
//                              tworld.cpp:321 (18)
//         0052e7e6     LEA        this,[ESI + 0x118]
//         0052e7ec     PUSH       0x4
//         0052e7ee     PUSH       this
//         0052e7ef     PUSH       EDI
//         0052e7f0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e7f5     ADD        ESP,0xc
//                              tworld.cpp:322 (18)
//         0052e7f8     LEA        EDX,[ESI + 0x11c]
//         0052e7fe     PUSH       0x1
//         0052e800     PUSH       EDX
//         0052e801     PUSH       EDI
//         0052e802     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e807     ADD        ESP,0xc
//                              tworld.cpp:323 (18)
//         0052e80a     ADD        ESI,0x11d
//         0052e810     PUSH       0x1
//         0052e812     PUSH       ESI
//         0052e813     PUSH       EDI
//         0052e814     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052e819     ADD        ESP,0xc
//                              tworld.cpp:324 (5)
//         0052e81c     POP        EDI
//         0052e81d     POP        ESI
//         0052e81e     RET        0x4
//         0052e821     ??         90h
//         0052e822     NOP
//         0052e823     NOP
//         0052e824     NOP
//         0052e825     NOP
//         0052e826     NOP
//         0052e827     NOP
//         0052e828     NOP
//         0052e829     NOP
//         0052e82a     NOP
//         0052e82b     NOP
//         0052e82c     NOP
//         0052e82d     NOP
//         0052e82e     NOP
//         0052e82f     NOP
    return;
}

void TRIBE_World::load_player(int param_1, uchar param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall load_player(TRIBE_World * this, int param_1, uchar p
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0052e864(R), 0052e895(R), 0052e8c6(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[3]:     0052e849(R), 0052e891(W), 0052e8c2(W)
//              short             Stack[0xc]:2   param_3                   XREF[3]:     0052e85e(R), 0052e899(R), 0052e8ca(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0052e89f(W), 0052e8d0(W), 0052e8f2(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e870(R)
//                               ?load_player@TRIBE_World@@UAEXHEF@Z                          XREF[1]:     0057748c(*)
//                               TRIBE_World::load_player
//                              tworld.cpp:328 (25)
//         0052e830     MOV        EAX,FS:[0x0]
//         0052e836     PUSH       -0x1
//         0052e838     PUSH       FUN_00561a56
//         0052e83d     PUSH       EAX
//         0052e83e     MOV        dword ptr FS:[0x0],ESP
//         0052e845     PUSH       EBX
//         0052e846     PUSH       ESI
//         0052e847     MOV        ESI,this
//                              tworld.cpp:329 (21)
//         0052e849     MOV        this,dword ptr [ESP + param_2]
//         0052e84d     PUSH       EDI
//         0052e84e     MOV        EAX,this
//         0052e850     AND        EAX,0xff
//         0052e855     DEC        EAX
//         0052e856     JZ         LAB_0052e8b5
//         0052e858     DEC        EAX
//         0052e859     JZ         LAB_0052e884
//         0052e85b     DEC        EAX
//         0052e85c     JZ         LAB_0052e8b5
//                              tworld.cpp:341 (18)
//         0052e85e     MOV        EAX,dword ptr [ESP + param_3]
//         0052e862     PUSH       EAX
//         0052e863     PUSH       this
//         0052e864     MOV        this,dword ptr [ESP + param_1]
//         0052e868     PUSH       this
//         0052e869     MOV        this,ESI
//         0052e86b     CALL       RGE_Game_World::load_player                      void load_player(RGE_Game_World * this, int p
//                              tworld.cpp:344 (20)
//         0052e870     MOV        this,dword ptr [ESP + local_c]
//         0052e874     MOV        dword ptr FS:[0x0],this
//         0052e87b     POP        EDI
//         0052e87c     POP        ESI
//         0052e87d     POP        EBX
//         0052e87e     ADD        ESP,0xc
//         0052e881     RET        0xc
//                               LAB_0052e884                                                 XREF[1]:     0052e859(j)
//                              tworld.cpp:337 (47)
//         0052e884     PUSH       0x858
//         0052e889     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e88e     ADD        ESP,0x4
//         0052e891     MOV        dword ptr [ESP + param_2],EAX
//         0052e895     MOV        EDI,dword ptr [ESP + param_1]
//         0052e899     MOV        EBX,dword ptr [ESP + param_3]
//         0052e89d     TEST       EAX,EAX
//         0052e89f     MOV        dword ptr [ESP + local_4],0x1
//         0052e8a7     JZ         LAB_0052e8e6
//         0052e8a9     PUSH       EBX
//         0052e8aa     PUSH       ESI
//         0052e8ab     PUSH       EDI
//         0052e8ac     MOV        this,EAX
//         0052e8ae     CALL       TRIBE_Gaia::TRIBE_Gaia                           undefined TRIBE_Gaia(TRIBE_Gaia * this, int p
//                              tworld.cpp:339 (2)
//         0052e8b3     JMP        LAB_0052e8e8
//                               LAB_0052e8b5                                                 XREF[2]:     0052e856(j), 0052e85c(j)
//                              tworld.cpp:333 (54)
//         0052e8b5     PUSH       0x848
//         0052e8ba     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e8bf     ADD        ESP,0x4
//         0052e8c2     MOV        dword ptr [ESP + param_2],EAX
//         0052e8c6     MOV        EDI,dword ptr [ESP + param_1]
//         0052e8ca     MOV        EBX,dword ptr [ESP + param_3]
//         0052e8ce     TEST       EAX,EAX
//         0052e8d0     MOV        dword ptr [ESP + local_4],0x0
//         0052e8d8     JZ         LAB_0052e8e6
//         0052e8da     PUSH       EBX
//         0052e8db     PUSH       ESI
//         0052e8dc     PUSH       EDI
//         0052e8dd     MOV        this,EAX
//         0052e8df     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, i
//         0052e8e4     JMP        LAB_0052e8e8
//                               LAB_0052e8e6                                                 XREF[2]:     0052e8a7(j), 0052e8d8(j)
//         0052e8e6     XOR        EAX,EAX
//                               LAB_0052e8e8                                                 XREF[2]:     0052e8b3(j), 0052e8e4(j)
//         0052e8e8     MOV        EDX,dword ptr [ESI + 0x40]
//                              tworld.cpp:334 (29)
//         0052e8eb     PUSH       EDI
//         0052e8ec     MOVSX      this,BX
//         0052e8ef     SHL        this,0x2
//         0052e8f2     MOV        dword ptr [ESP + local_4],0xffffffff
//         0052e8fa     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
//         0052e8fd     MOV        EAX,dword ptr [ESI + 0x40]
//         0052e900     MOV        this,dword ptr [EAX + this->_padding_*0x1]
//         0052e903     MOV        EDX,dword ptr [this->_padding_]
//         0052e905     CALL       dword ptr [EDX + 0x74]
//                              tworld.cpp:344 (20)
//         0052e908     MOV        this,dword ptr [ESP + 0xc]
//         0052e90c     POP        EDI
//         0052e90d     POP        ESI
//         0052e90e     MOV        dword ptr FS:[0x0],this
//         0052e915     POP        EBX
//         0052e916     ADD        ESP,0xc
//         0052e919     RET        0xc
//         0052e91c     ??         90h
//         0052e91d     NOP
//         0052e91e     NOP
//         0052e91f     NOP
    return;
}

void TRIBE_World::setup_gaia() {
    /* TODO: Stub */
//                              void __thiscall setup_gaia(TRIBE_World * this)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052e94c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052e977(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052e946(W)
//                               ?setup_gaia@TRIBE_World@@UAEXXZ                              XREF[1]:     005774b4(*)
//                               TRIBE_World::setup_gaia
//                              tworld.cpp:348 (25)
//         0052e920     PUSH       -0x1
//         0052e922     PUSH       FUN_00561a6b
//         0052e927     MOV        EAX,FS:[0x0]
//         0052e92d     PUSH       EAX
//         0052e92e     MOV        dword ptr FS:[0x0],ESP
//         0052e935     PUSH       this
//         0052e936     PUSH       ESI
//         0052e937     MOV        ESI,this
//                              tworld.cpp:349 (59)
//         0052e939     PUSH       0x858
//         0052e93e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e943     ADD        ESP,0x4
//         0052e946     MOV        dword ptr [ESP + local_10],EAX
//         0052e94a     TEST       EAX,EAX
//         0052e94c     MOV        dword ptr [ESP + local_4],0x0
//         0052e954     JZ         LAB_0052e96f
//         0052e956     MOV        this,dword ptr [ESI + 0x48]
//         0052e959     PUSH       0x0
//         0052e95b     PUSH       s_GAIA                                           = "GAIA"
//         0052e960     PUSH       0x0
//         0052e962     MOV        EDX,dword ptr [this->_padding_]
//         0052e964     MOV        this,EAX
//         0052e966     PUSH       EDX
//         0052e967     PUSH       ESI
//         0052e968     CALL       TRIBE_Gaia::TRIBE_Gaia                           undefined TRIBE_Gaia(TRIBE_Gaia * this, TRIBE
//         0052e96d     JMP        LAB_0052e971
//                               LAB_0052e96f                                                 XREF[1]:     0052e954(j)
//         0052e96f     XOR        EAX,EAX
//                               LAB_0052e971                                                 XREF[1]:     0052e96d(j)
//         0052e971     MOV        this,dword ptr [ESI + 0x40]
//                              tworld.cpp:351 (18)
//         0052e974     POP        ESI
//         0052e975     MOV        dword ptr [this->_padding_],EAX
//         0052e977     MOV        this,dword ptr [ESP + local_c]
//         0052e97b     MOV        dword ptr FS:[0x0],this
//         0052e982     ADD        ESP,0x10
//         0052e985     RET
//         0052e986     ??         90h
//         0052e987     NOP
//         0052e988     NOP
//         0052e989     NOP
//         0052e98a     NOP
//         0052e98b     NOP
//         0052e98c     NOP
//         0052e98d     NOP
//         0052e98e     NOP
//         0052e98f     NOP
    return;
}

void TRIBE_World::setup_players(RGE_Player_Info* param_1) {
    /* TODO: Stub */
//                              void __thiscall setup_players(TRIBE_World * this, RGE_Player_Info *
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[4]:     0052e9ba(R), 0052e9ea(W), 0052ea08(W), 0052ea50(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0052e9f0(W), 0052ea0e(W), 0052ea56(W), 0052ea90(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052eaad(R)
//                               ?setup_players@TRIBE_World@@UAEXAAURGE_Player_Info@@@Z       XREF[1]:     005774b8(*)
//                               TRIBE_World::setup_players
//                              tworld.cpp:355 (25)
//         0052e990     MOV        EAX,FS:[0x0]
//         0052e996     PUSH       -0x1
//         0052e998     PUSH       FUN_00561aa1
//         0052e99d     PUSH       EAX
//         0052e99e     MOV        dword ptr FS:[0x0],ESP
//         0052e9a5     PUSH       ESI
//         0052e9a6     PUSH       EDI
//         0052e9a7     MOV        EDI,this
//                              tworld.cpp:358 (17)
//         0052e9a9     MOV        ESI,0x1
//         0052e9ae     CMP        word ptr [EDI + 0x3c],SI
//         0052e9b2     JLE        LAB_0052eaad
//         0052e9b8     PUSH       EBP
//         0052e9b9     PUSH       EBX
//                              tworld.cpp:360 (26)
//         0052e9ba     MOV        EBX,dword ptr [ESP + param_1]
//         0052e9be     LEA        EBP,[EBX + 0x41]
//                               LAB_0052e9c1                                                 XREF[1]:     0052eaa5(j)
//         0052e9c1     MOV        AL,byte ptr [ESI + EBX*0x1 + 0x248]
//         0052e9c8     TEST       AL,AL
//         0052e9ca     JZ         LAB_0052ea43
//         0052e9cc     CMP        AL,0x4
//         0052e9ce     JNZ        LAB_0052ea9b
//                              tworld.cpp:367 (5)
//         0052e9d4     MOV        EAX,[useComputerPlayers]                         = 1h
//                              tworld.cpp:370 (37)
//         0052e9d9     PUSH       0x848
//         0052e9de     TEST       EAX,EAX
//         0052e9e0     JNZ        LAB_0052ea00
//         0052e9e2     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052e9e7     ADD        ESP,0x4
//         0052e9ea     MOV        dword ptr [ESP + param_1],EAX
//         0052e9ee     TEST       EAX,EAX
//         0052e9f0     MOV        dword ptr [ESP + local_4],0x1
//         0052e9f8     JZ         LAB_0052ea8b
//                              tworld.cpp:371 (2)
//         0052e9fe     JMP        LAB_0052ea60
//                               LAB_0052ea00                                                 XREF[1]:     0052e9e0(j)
//                              tworld.cpp:374 (67)
//         0052ea00     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052ea05     ADD        ESP,0x4
//         0052ea08     MOV        dword ptr [ESP + param_1],EAX
//         0052ea0c     TEST       EAX,EAX
//         0052ea0e     MOV        dword ptr [ESP + local_4],0x2
//         0052ea16     JZ         LAB_0052ea8b
//         0052ea18     MOV        DL,byte ptr [ESI + EBX*0x1 + 0x251]
//         0052ea1f     PUSH       0x0
//         0052ea21     PUSH       0x0
//         0052ea23     PUSH       0x0
//         0052ea25     PUSH       0x1
//         0052ea27     PUSH       0x1
//         0052ea29     PUSH       EDX
//         0052ea2a     LEA        this,[EBP + -0x41]
//         0052ea2d     MOVSX      EDX,DL
//         0052ea30     PUSH       this
//         0052ea31     MOV        this,dword ptr [EDI + 0x48]
//         0052ea34     PUSH       ESI
//         0052ea35     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0052ea38     MOV        this,EAX
//         0052ea3a     PUSH       EDX
//         0052ea3b     PUSH       EDI
//         0052ea3c     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, T
//         0052ea41     JMP        LAB_0052ea8d
//                               LAB_0052ea43                                                 XREF[1]:     0052e9ca(j)
//                              tworld.cpp:364 (106)
//         0052ea43     PUSH       0x848
//         0052ea48     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052ea4d     ADD        ESP,0x4
//         0052ea50     MOV        dword ptr [ESP + param_1],EAX
//         0052ea54     TEST       EAX,EAX
//         0052ea56     MOV        dword ptr [ESP + local_4],0x0
//         0052ea5e     JZ         LAB_0052ea8b
//                               LAB_0052ea60                                                 XREF[1]:     0052e9fe(j)
//         0052ea60     MOV        DL,byte ptr [ESI + EBX*0x1 + 0x251]
//         0052ea67     PUSH       0x0
//         0052ea69     PUSH       0x0
//         0052ea6b     PUSH       0x0
//         0052ea6d     PUSH       0x1
//         0052ea6f     PUSH       0x0
//         0052ea71     PUSH       EDX
//         0052ea72     LEA        this,[EBP + -0x41]
//         0052ea75     MOVSX      EDX,DL
//         0052ea78     PUSH       this
//         0052ea79     MOV        this,dword ptr [EDI + 0x48]
//         0052ea7c     PUSH       ESI
//         0052ea7d     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0052ea80     MOV        this,EAX
//         0052ea82     PUSH       EDX
//         0052ea83     PUSH       EDI
//         0052ea84     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, T
//         0052ea89     JMP        LAB_0052ea8d
//                               LAB_0052ea8b                                                 XREF[3]:     0052e9f8(j), 0052ea16(j),
//                                                                                                         0052ea5e(j)
//         0052ea8b     XOR        EAX,EAX
//                               LAB_0052ea8d                                                 XREF[2]:     0052ea41(j), 0052ea89(j)
//         0052ea8d     MOV        this,dword ptr [EDI + 0x40]
//         0052ea90     MOV        dword ptr [ESP + local_4],0xffffffff
//         0052ea98     MOV        dword ptr [this->_padding_ + ESI*0x4],EAX
//                               LAB_0052ea9b                                                 XREF[1]:     0052e9ce(j)
//         0052ea9b     MOVSX      EDX,word ptr [EDI + 0x3c]
//         0052ea9f     INC        ESI
//         0052eaa0     ADD        EBP,0x41
//         0052eaa3     CMP        ESI,EDX
//         0052eaa5     JL         LAB_0052e9c1
//         0052eaab     POP        EBX
//         0052eaac     POP        EBP
//                               LAB_0052eaad                                                 XREF[1]:     0052e9b2(j)
//                              tworld.cpp:380 (19)
//         0052eaad     MOV        this,dword ptr [ESP + local_c]
//         0052eab1     POP        EDI
//         0052eab2     MOV        dword ptr FS:[0x0],this
//         0052eab9     POP        ESI
//         0052eaba     ADD        ESP,0xc
//         0052eabd     RET        0x4
    return;
}

void TRIBE_World::check_destructables(short param_1, short param_2, float param_3, float param_4, uchar param_5) {
    /* TODO: Stub */
//                              void __thiscall check_destructables(TRIBE_World * this, short param_
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[5]:     0052eac3(R), 0052eb3b(W), 0052eb6f(W), 0052eb77(R),
//                                                                                     0052ecc0(R)
//              short             Stack[0x8]:2   param_2                   XREF[4]:     0052ead0(R), 0052eb61(W), 0052eb90(W), 0052ecc4(R)
//              float             Stack[0xc]:4   param_3                   XREF[3]:     0052eb20(R), 0052eb44(R), 0052ec37(R)
//              float             Stack[0x10]:4  param_4                   XREF[3]:     0052eb2f(R), 0052eb55(R), 0052ec30(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0052ec8f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052ebd1(W), 0052ecc8(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0052ec4b(W), 0052ec7c(R)
//              float             Stack[-0xc]:4  ry2                       XREF[2]:     0052ebbd(W), 0052ebfc(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0052ebd9(W), 0052ecd0(R), 0052ecdc(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0052eaf6(W), 0052eb0b(R), 0052ec80(R)
//              float             Stack[-0x18]:4 ry                        XREF[3]:     0052eaf2(W), 0052eafa(R), 0052ec6d(R)
//              float             Stack[-0x1c]:4 rx                        XREF[3]:     0052eac8(W), 0052eb7b(R), 0052ebdd(R)
//              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     0052ebd5(W), 0052ebea(R), 0052eccc(R), 0052ecd8(W)
//                               ?check_destructables@TRIBE_World@@QAEXFFMME@Z                XREF[3]:     setup:004c8472(c),
//                               TRIBE_World::check_destructables                                          make_new_cliff:00510276(c),
//                                                                                                         make_new_object:00512fa5(c)
//                              tworld.cpp:384 (3)
//         0052eac0     SUB        ESP,0x20
//                              tworld.cpp:401 (33)
//         0052eac3     MOVSX      EAX,word ptr [ESP + param_1]
//         0052eac8     MOV        dword ptr [ESP + rx],this
//         0052eacc     MOV        this,dword ptr [ECX + this->_padding_]
//         0052eacf     PUSH       EBX
//         0052ead0     MOV        BX,word ptr [ESP + param_2]
//         0052ead5     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
//         0052ead8     PUSH       EBP
//         0052ead9     MOVSX      EAX,BX
//         0052eadc     MOV        this,dword ptr [EDX + 0x24]
//         0052eadf     PUSH       ESI
//         0052eae0     PUSH       EDI
//         0052eae1     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
//                              tworld.cpp:403 (8)
//         0052eae4     TEST       EAX,EAX
//         0052eae6     JZ         LAB_0052ece6
//                              tworld.cpp:407 (3)
//         0052eaec     MOV        EDX,dword ptr [EAX + 0x30]
//                              tworld.cpp:410 (49)
//         0052eaef     MOV        EAX,dword ptr [EAX + 0x34]
//         0052eaf2     MOV        dword ptr [ESP + ry],EDX
//         0052eaf6     MOV        dword ptr [ESP + local_14],EAX
//         0052eafa     FLD        float ptr [ESP + ry]
//         0052eafe     FCOMP      float ptr [DAT_00577558]                         = align(6)
//         0052eb04     FNSTSW     AX
//         0052eb06     TEST       AH,0x41
//         0052eb09     JZ         LAB_0052eb20
//         0052eb0b     FLD        float ptr [ESP + local_14]
//         0052eb0f     FCOMP      float ptr [DAT_00577558]                         = align(6)
//         0052eb15     FNSTSW     AX
//         0052eb17     TEST       AH,0x41
//         0052eb1a     JNZ        LAB_0052ece6
//                               LAB_0052eb20                                                 XREF[1]:     0052eb09(j)
//                              tworld.cpp:413 (15)
//         0052eb20     FLD        float ptr [ESP + param_3]
//         0052eb24     FSUB       float ptr [null_0057755c]                        = align(2)
//         0052eb2a     CALL       __ftol                                           undefined __ftol()
//                              tworld.cpp:414 (21)
//         0052eb2f     FLD        float ptr [ESP + param_4]
//         0052eb33     FSUB       float ptr [null_0057755c]                        = align(2)
//         0052eb39     MOV        EBP,EAX
//         0052eb3b     MOV        dword ptr [ESP + param_1],EBP
//         0052eb3f     CALL       __ftol                                           undefined __ftol()
//                              tworld.cpp:415 (17)
//         0052eb44     FLD        float ptr [ESP + param_3]
//         0052eb48     FSUB       float ptr [DAT_00577560]
//         0052eb4e     MOV        ESI,EAX
//         0052eb50     CALL       __ftol                                           undefined __ftol()
//                              tworld.cpp:416 (21)
//         0052eb55     FLD        float ptr [ESP + param_4]
//         0052eb59     FSUB       float ptr [DAT_00577560]
//         0052eb5f     MOV        EDI,EAX
//         0052eb61     MOV        dword ptr [ESP + param_2],EDI
//         0052eb65     CALL       __ftol                                           undefined __ftol()
//                              tworld.cpp:418 (17)
//         0052eb6a     TEST       BP,BP
//         0052eb6d     JGE        LAB_0052eb7b
//         0052eb6f     MOV        dword ptr [ESP + param_1],0x0
//         0052eb77     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_0052eb7b                                                 XREF[1]:     0052eb6d(j)
//                              tworld.cpp:419 (27)
//         0052eb7b     MOV        this,dword ptr [ESP + rx]
//         0052eb7f     MOVSX      EDX,DI
//         0052eb82     MOV        this,dword ptr [ECX + this->_padding_]
//         0052eb85     CMP        EDX,dword ptr [ECX + this->_padding_]
//         0052eb88     JL         LAB_0052eb96
//         0052eb8a     MOV        DX,word ptr [ECX + this->_padding_]
//         0052eb8e     DEC        DX
//         0052eb90     MOV        dword ptr [ESP + param_2],EDX
//         0052eb94     MOV        EDI,EDX
//                               LAB_0052eb96                                                 XREF[1]:     0052eb88(j)
//                              tworld.cpp:420 (7)
//         0052eb96     TEST       SI,SI
//         0052eb99     JGE        LAB_0052eb9d
//         0052eb9b     XOR        ESI,ESI
//                               LAB_0052eb9d                                                 XREF[1]:     0052eb99(j)
//                              tworld.cpp:421 (14)
//         0052eb9d     MOVSX      EDX,AX
//         0052eba0     CMP        EDX,dword ptr [ECX + this->_padding_]
//         0052eba3     JL         LAB_0052ebab
//         0052eba5     MOV        AX,word ptr [ECX + this->_padding_]
//         0052eba9     DEC        AX
//                               LAB_0052ebab                                                 XREF[1]:     0052eba3(j)
//                              tworld.cpp:423 (9)
//         0052ebab     CMP        SI,AX
//         0052ebae     JG         LAB_0052ece6
//                              tworld.cpp:425 (63)
//         0052ebb4     MOVSX      EDX,BP
//         0052ebb7     MOVSX      this,SI
//         0052ebba     MOVSX      EAX,AX
//         0052ebbd     MOV        dword ptr [ESP + ry2],EDX
//         0052ebc1     LEA        EDX,[EDX + EDX*0x2]
//         0052ebc4     SUB        EAX,this
//         0052ebc6     LEA        ESI,[this->_padding_*0x4 + 0x0]
//         0052ebcd     SHL        EDX,0x3
//         0052ebd0     INC        EAX
//         0052ebd1     MOV        dword ptr [ESP + local_4],EDX
//         0052ebd5     MOV        dword ptr [ESP + local_20],ESI
//         0052ebd9     MOV        dword ptr [ESP + local_10],EAX
//                               LAB_0052ebdd                                                 XREF[1]:     0052ece0(j)
//         0052ebdd     MOV        EAX,dword ptr [ESP + rx]
//         0052ebe1     MOV        this,dword ptr [EAX + 0x28]
//         0052ebe4     MOV        EAX,dword ptr [this->_padding_ + 0x8d8c]
//         0052ebea     MOV        this,dword ptr [ESP + local_20]
//         0052ebee     MOV        EAX,dword ptr [EAX + this->_padding_*0x1]
//         0052ebf1     ADD        EAX,EDX
//                              tworld.cpp:426 (22)
//         0052ebf3     CMP        BP,DI
//         0052ebf6     JG         LAB_0052eccc
//         0052ebfc     MOV        this,dword ptr [ESP + ry2]
//         0052ec00     LEA        EBP,[EAX + 0x10]
//         0052ec03     MOVSX      EDI,DI
//         0052ec06     SUB        EDI,this
//         0052ec08     INC        EDI
//                               LAB_0052ec09                                                 XREF[1]:     0052ecba(j)
//                              tworld.cpp:427 (11)
//         0052ec09     MOV        EAX,dword ptr [EBP]
//         0052ec0c     TEST       EAX,EAX
//         0052ec0e     JZ         LAB_0052ecb6
//                               LAB_0052ec14                                                 XREF[1]:     0052ecb0(j)
//                              tworld.cpp:430 (5)
//         0052ec14     MOV        this,dword ptr [EAX]
//         0052ec16     MOV        ESI,dword ptr [EAX + 0x4]
//                              tworld.cpp:432 (20)
//         0052ec19     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0052ec1c     CMP        word ptr [EAX + 0x10],BX
//         0052ec20     JZ         LAB_0052ecac
//         0052ec26     MOV        DL,byte ptr [EAX + 0x4b]
//         0052ec29     TEST       DL,DL
//         0052ec2b     JZ         LAB_0052ecac
//                              tworld.cpp:437 (19)
//         0052ec2d     FLD        float ptr [ECX + this->_padding_]
//         0052ec30     FSUB       float ptr [ESP + param_4]
//         0052ec34     FLD        float ptr [ECX + this->_padding_]
//         0052ec37     FSUB       float ptr [ESP + param_3]
//         0052ec3b     FLD        float ptr [EAX + 0x30]
//         0052ec3e     FXCH
//                              tworld.cpp:439 (28)
//         0052ec40     FLD        ST2
//         0052ec42     FCOMP      float ptr [DAT_00577558]                         = align(6)
//         0052ec48     MOV        EDX,dword ptr [EAX + 0x34]
//         0052ec4b     MOV        dword ptr [ESP + local_8],EDX
//         0052ec4f     FNSTSW     AX
//         0052ec51     TEST       AH,0x1
//         0052ec54     JZ         LAB_0052ec5c
//         0052ec56     FXCH       ST2
//         0052ec58     FCHS
//         0052ec5a     FXCH       ST2
//                               LAB_0052ec5c                                                 XREF[1]:     0052ec54(j)
//                              tworld.cpp:440 (15)
//         0052ec5c     FCOM       float ptr [DAT_00577558]                         = align(6)
//         0052ec62     FNSTSW     AX
//         0052ec64     TEST       AH,0x1
//         0052ec67     JZ         LAB_0052ec6b
//         0052ec69     FCHS
//                               LAB_0052ec6b                                                 XREF[1]:     0052ec67(j)
//                              tworld.cpp:442 (36)
//         0052ec6b     FXCH
//         0052ec6d     FADD       float ptr [ESP + ry]
//         0052ec71     FXCH
//         0052ec73     FCOMPP
//         0052ec75     FNSTSW     AX
//         0052ec77     TEST       AH,0x1
//         0052ec7a     JZ         LAB_0052ecaa
//         0052ec7c     FLD        float ptr [ESP + local_8]
//         0052ec80     FADD       float ptr [ESP + local_14]
//         0052ec84     FXCH
//         0052ec86     FCOMPP
//         0052ec88     FNSTSW     AX
//         0052ec8a     TEST       AH,0x1
//         0052ec8d     JZ         LAB_0052ecac
//                              tworld.cpp:444 (8)
//         0052ec8f     MOV        AL,byte ptr [ESP + param_5]
//         0052ec93     TEST       AL,AL
//         0052ec95     JZ         LAB_0052eca3
//                              tworld.cpp:445 (10)
//         0052ec97     TEST       this,this
//         0052ec99     JZ         LAB_0052ecac
//         0052ec9b     MOV        EAX,dword ptr [this->_padding_]
//         0052ec9d     PUSH       0x1
//         0052ec9f     CALL       dword ptr [EAX]
//                              tworld.cpp:446 (2)
//         0052eca1     JMP        LAB_0052ecac
//                               LAB_0052eca3                                                 XREF[1]:     0052ec95(j)
//                              tworld.cpp:447 (7)
//         0052eca3     MOV        EDX,dword ptr [this->_padding_]
//         0052eca5     CALL       dword ptr [EDX + 0x68]
//         0052eca8     JMP        LAB_0052ecac
//                               LAB_0052ecaa                                                 XREF[1]:     0052ec7a(j)
//                              tworld.cpp:442 (2)
//         0052ecaa     FSTP       ST0
//                               LAB_0052ecac                                                 XREF[6]:     0052ec20(j), 0052ec2b(j),
//                                                                                                         0052ec8d(j), 0052ec99(j),
//                                                                                                         0052eca1(j), 0052eca8(j)
//                              tworld.cpp:427 (10)
//         0052ecac     TEST       ESI,ESI
//         0052ecae     MOV        EAX,ESI
//         0052ecb0     JNZ        LAB_0052ec14
//                               LAB_0052ecb6                                                 XREF[1]:     0052ec0e(j)
//                              tworld.cpp:426 (48)
//         0052ecb6     ADD        EBP,0x18
//         0052ecb9     DEC        EDI
//         0052ecba     JNZ        LAB_0052ec09
//         0052ecc0     MOV        EBP,dword ptr [ESP + param_1]
//         0052ecc4     MOV        EDI,dword ptr [ESP + param_2]
//         0052ecc8     MOV        EDX,dword ptr [ESP + local_4]
//                               LAB_0052eccc                                                 XREF[1]:     0052ebf6(j)
//         0052eccc     MOV        this,dword ptr [ESP + local_20]
//         0052ecd0     MOV        EAX,dword ptr [ESP + local_10]
//         0052ecd4     ADD        this,0x4
//         0052ecd7     DEC        EAX
//         0052ecd8     MOV        dword ptr [ESP + local_20],this
//         0052ecdc     MOV        dword ptr [ESP + local_10],EAX
//         0052ece0     JNZ        LAB_0052ebdd
//                               LAB_0052ece6                                                 XREF[3]:     0052eae6(j), 0052eb1a(j),
//                                                                                                         0052ebae(j)
//                              tworld.cpp:454 (10)
//         0052ece6     POP        EDI
//         0052ece7     POP        ESI
//         0052ece8     POP        EBP
//         0052ece9     POP        EBX
//         0052ecea     ADD        ESP,0x20
//         0052eced     RET        0x14
    return;
}

void TRIBE_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    /* TODO: Stub */
//                              void __thiscall scenario_make_player(TRIBE_World * this, short param
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[3]:     0052ed22(R), 0052ed4d(R), 0052ed95(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[2]:     0052ed5d(R), 0052eda5(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[4]:     0052ecfe(R), 0052ed1e(W), 0052ed49(W), 0052ed91(W)
//              uchar             Stack[0x10]:1  param_4
//              char *            Stack[0x14]:4  param_5                   XREF[2]:     0052ed61(R), 0052eda9(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0052ed26(W), 0052ed51(W), 0052ed99(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052edde(*)
//                               ?scenario_make_player@TRIBE_World@@UAEXFEEEPAD@Z             XREF[1]:     005774c4(*)
//                               TRIBE_World::scenario_make_player
//                              tworld.cpp:458 (14)
//         0052ecf0     MOV        EAX,FS:[0x0]
//         0052ecf6     PUSH       -0x1
//         0052ecf8     PUSH       FUN_00561ad1
//         0052ecfd     PUSH       EAX
//                              tworld.cpp:459 (19)
//         0052ecfe     MOV        AL,byte ptr [ESP + param_3]
//         0052ed02     MOV        dword ptr FS:[0x0],ESP
//         0052ed09     PUSH       ESI
//         0052ed0a     PUSH       EDI
//         0052ed0b     TEST       AL,AL
//         0052ed0d     MOV        ESI,this
//         0052ed0f     JNZ        LAB_0052ed38
//                              tworld.cpp:461 (37)
//         0052ed11     PUSH       0x848
//         0052ed16     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052ed1b     ADD        ESP,0x4
//         0052ed1e     MOV        dword ptr [ESP + param_3],EAX
//         0052ed22     MOV        EDI,dword ptr [ESP + param_1]
//         0052ed26     MOV        dword ptr [ESP + local_4],0x0
//         0052ed2e     TEST       EAX,EAX
//         0052ed30     JZ         LAB_0052edd1
//                              tworld.cpp:462 (4)
//         0052ed36     JMP        LAB_0052eda5
//                               LAB_0052ed38                                                 XREF[1]:     0052ed0f(j)
//         0052ed38     CMP        AL,0x4
//                              tworld.cpp:466 (79)
//         0052ed3a     PUSH       0x848
//         0052ed3f     JNZ        LAB_0052ed89
//         0052ed41     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052ed46     ADD        ESP,0x4
//         0052ed49     MOV        dword ptr [ESP + param_3],EAX
//         0052ed4d     MOV        EDI,dword ptr [ESP + param_1]
//         0052ed51     MOV        dword ptr [ESP + local_4],0x1
//         0052ed59     TEST       EAX,EAX
//         0052ed5b     JZ         LAB_0052edd1
//         0052ed5d     MOV        EDX,dword ptr [ESP + param_2]
//         0052ed61     MOV        this,dword ptr [ESP + param_5]
//         0052ed65     PUSH       0x0
//         0052ed67     PUSH       0x0
//         0052ed69     PUSH       0x0
//         0052ed6b     PUSH       0x1
//         0052ed6d     PUSH       0x1
//         0052ed6f     PUSH       EDX
//         0052ed70     PUSH       this
//         0052ed71     MOV        this,dword ptr [ESI + 0x48]
//         0052ed74     AND        EDX,0xff
//         0052ed7a     PUSH       EDI
//         0052ed7b     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0052ed7e     MOV        this,EAX
//         0052ed80     PUSH       EDX
//         0052ed81     PUSH       ESI
//         0052ed82     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, T
//         0052ed87     JMP        LAB_0052edd3
//                               LAB_0052ed89                                                 XREF[1]:     0052ed3f(j)
//                              tworld.cpp:469 (80)
//         0052ed89     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052ed8e     ADD        ESP,0x4
//         0052ed91     MOV        dword ptr [ESP + param_3],EAX
//         0052ed95     MOV        EDI,dword ptr [ESP + param_1]
//         0052ed99     MOV        dword ptr [ESP + local_4],0x2
//         0052eda1     TEST       EAX,EAX
//         0052eda3     JZ         LAB_0052edd1
//                               LAB_0052eda5                                                 XREF[1]:     0052ed36(j)
//         0052eda5     MOV        EDX,dword ptr [ESP + param_2]
//         0052eda9     MOV        this,dword ptr [ESP + param_5]
//         0052edad     PUSH       0x0
//         0052edaf     PUSH       0x0
//         0052edb1     PUSH       0x0
//         0052edb3     PUSH       0x1
//         0052edb5     PUSH       0x0
//         0052edb7     PUSH       EDX
//         0052edb8     PUSH       this
//         0052edb9     MOV        this,dword ptr [ESI + 0x48]
//         0052edbc     AND        EDX,0xff
//         0052edc2     PUSH       EDI
//         0052edc3     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0052edc6     MOV        this,EAX
//         0052edc8     PUSH       EDX
//         0052edc9     PUSH       ESI
//         0052edca     CALL       TRIBE_Player::TRIBE_Player                       undefined TRIBE_Player(TRIBE_Player * this, T
//         0052edcf     JMP        LAB_0052edd3
//                               LAB_0052edd1                                                 XREF[3]:     0052ed30(j), 0052ed5b(j),
//                                                                                                         0052eda3(j)
//         0052edd1     XOR        EAX,EAX
//                               LAB_0052edd3                                                 XREF[2]:     0052ed87(j), 0052edcf(j)
//         0052edd3     MOV        EDX,dword ptr [ESI + 0x40]
//         0052edd6     MOVSX      this,DI
//                              tworld.cpp:470 (22)
//         0052edd9     POP        EDI
//         0052edda     POP        ESI
//         0052eddb     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
//         0052edde     MOV        this,dword ptr [ESP]=>local_c
//         0052ede2     MOV        dword ptr FS:[0x0],this
//         0052ede9     ADD        ESP,0xc
//         0052edec     RET        0x14
//         0052edef     ??         90h
    return;
}

uchar TRIBE_World::load_world(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall load_world(TRIBE_World * this, int param_1)
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052edf2(R)
//                               ?load_world@TRIBE_World@@UAEEH@Z                             XREF[1]:     00577520(*)
//                               TRIBE_World::load_world
//                              tworld.cpp:474 (2)
//         0052edf0     PUSH       ESI
//         0052edf1     PUSH       EDI
//                              tworld.cpp:475 (16)
//         0052edf2     MOV        EDI,dword ptr [ESP + param_1]
//         0052edf6     MOV        ESI,this
//         0052edf8     PUSH       EDI
//         0052edf9     CALL       RGE_Game_World::load_world                       uchar load_world(RGE_Game_World * this, int p
//         0052edfe     TEST       AL,AL
//         0052ee00     JNZ        LAB_0052ee07
//                              tworld.cpp:516 (5)
//         0052ee02     POP        EDI
//         0052ee03     POP        ESI
//         0052ee04     RET        0x4
//                               LAB_0052ee07                                                 XREF[1]:     0052ee00(j)
//                              tworld.cpp:478 (22)
//         0052ee07     FLD        float ptr [save_game_version]                    = 7.23
//         0052ee0d     FCOMP      float ptr [DAT_00577564]                         = 33h    3
//         0052ee13     PUSH       EBX
//         0052ee14     XOR        EBX,EBX
//         0052ee16     FNSTSW     AX
//         0052ee18     TEST       AH,0x1
//         0052ee1b     JNZ        LAB_0052ee31
//                              tworld.cpp:479 (18)
//         0052ee1d     LEA        EAX,[ESI + 0x108]
//         0052ee23     PUSH       0x4
//         0052ee25     PUSH       EAX
//         0052ee26     PUSH       EDI
//         0052ee27     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ee2c     ADD        ESP,0xc
//                              tworld.cpp:480 (2)
//         0052ee2f     JMP        LAB_0052ee37
//                               LAB_0052ee31                                                 XREF[1]:     0052ee1b(j)
//                              tworld.cpp:481 (6)
//         0052ee31     MOV        dword ptr [ESI + 0x108],EBX
//                               LAB_0052ee37                                                 XREF[1]:     0052ee2f(j)
//                              tworld.cpp:483 (19)
//         0052ee37     FLD        float ptr [save_game_version]                    = 7.23
//         0052ee3d     FCOMP      float ptr [DAT_00577568]                         = 9Ah
//         0052ee43     FNSTSW     AX
//         0052ee45     TEST       AH,0x1
//         0052ee48     JNZ        LAB_0052ee70
//                              tworld.cpp:485 (18)
//         0052ee4a     LEA        this,[ESI + 0x10c]
//         0052ee50     PUSH       0x4
//         0052ee52     PUSH       this
//         0052ee53     PUSH       EDI
//         0052ee54     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ee59     ADD        ESP,0xc
//                              tworld.cpp:486 (18)
//         0052ee5c     LEA        EDX,[ESI + 0x110]
//         0052ee62     PUSH       0x4
//         0052ee64     PUSH       EDX
//         0052ee65     PUSH       EDI
//         0052ee66     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ee6b     ADD        ESP,0xc
//                              tworld.cpp:488 (2)
//         0052ee6e     JMP        LAB_0052ee7c
//                               LAB_0052ee70                                                 XREF[1]:     0052ee48(j)
//                              tworld.cpp:490 (6)
//         0052ee70     MOV        dword ptr [ESI + 0x10c],EBX
//                              tworld.cpp:491 (6)
//         0052ee76     MOV        dword ptr [ESI + 0x110],EBX
//                               LAB_0052ee7c                                                 XREF[1]:     0052ee6e(j)
//                              tworld.cpp:494 (19)
//         0052ee7c     FLD        float ptr [save_game_version]                    = 7.23
//         0052ee82     FCOMP      float ptr [DAT_0057756c]                         = CDh
//         0052ee88     FNSTSW     AX
//         0052ee8a     TEST       AH,0x1
//         0052ee8d     JNZ        LAB_0052eeb5
//                              tworld.cpp:496 (18)
//         0052ee8f     LEA        EAX,[ESI + 0x114]
//         0052ee95     PUSH       0x1
//         0052ee97     PUSH       EAX
//         0052ee98     PUSH       EDI
//         0052ee99     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ee9e     ADD        ESP,0xc
//                              tworld.cpp:497 (18)
//         0052eea1     LEA        this,[ESI + 0x118]
//         0052eea7     PUSH       0x4
//         0052eea9     PUSH       this
//         0052eeaa     PUSH       EDI
//         0052eeab     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052eeb0     ADD        ESP,0xc
//                              tworld.cpp:499 (2)
//         0052eeb3     JMP        LAB_0052eec1
//                               LAB_0052eeb5                                                 XREF[1]:     0052ee8d(j)
//                              tworld.cpp:501 (6)
//         0052eeb5     MOV        byte ptr [ESI + 0x114],BL
//                              tworld.cpp:502 (6)
//         0052eebb     MOV        dword ptr [ESI + 0x118],EBX
//                               LAB_0052eec1                                                 XREF[1]:     0052eeb3(j)
//                              tworld.cpp:505 (19)
//         0052eec1     FLD        float ptr [save_game_version]                    = 7.23
//         0052eec7     FCOMP      float ptr [DAT_00577570]                         = 33h    3
//         0052eecd     FNSTSW     AX
//         0052eecf     TEST       AH,0x1
//         0052eed2     JNZ        LAB_0052eee8
//                              tworld.cpp:506 (18)
//         0052eed4     LEA        EDX,[ESI + 0x11c]
//         0052eeda     PUSH       0x1
//         0052eedc     PUSH       EDX
//         0052eedd     PUSH       EDI
//         0052eede     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052eee3     ADD        ESP,0xc
//                              tworld.cpp:507 (2)
//         0052eee6     JMP        LAB_0052eeee
//                               LAB_0052eee8                                                 XREF[1]:     0052eed2(j)
//                              tworld.cpp:508 (6)
//         0052eee8     MOV        byte ptr [ESI + 0x11c],BL
//                               LAB_0052eeee                                                 XREF[1]:     0052eee6(j)
//                              tworld.cpp:510 (19)
//         0052eeee     FLD        float ptr [save_game_version]                    = 7.23
//         0052eef4     FCOMP      float ptr [DAT_00577574]                         = 3Dh    =
//         0052eefa     FNSTSW     AX
//         0052eefc     TEST       AH,0x1
//         0052eeff     JNZ        LAB_0052ef1b
//                              tworld.cpp:511 (18)
//         0052ef01     ADD        ESI,0x11d
//         0052ef07     PUSH       0x1
//         0052ef09     PUSH       ESI
//         0052ef0a     PUSH       EDI
//         0052ef0b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ef10     ADD        ESP,0xc
//                              tworld.cpp:515 (3)
//         0052ef13     MOV        AL,0x1
//         0052ef15     POP        EBX
//                              tworld.cpp:516 (5)
//         0052ef16     POP        EDI
//         0052ef17     POP        ESI
//         0052ef18     RET        0x4
//                               LAB_0052ef1b                                                 XREF[1]:     0052eeff(j)
//                              tworld.cpp:474 (1)
//         0052ef1b     POP        EBX
//                              tworld.cpp:513 (7)
//         0052ef1c     MOV        byte ptr [ESI + 0x11d],0x2
//                              tworld.cpp:516 (7)
//         0052ef23     POP        EDI
//         0052ef24     MOV        AL,0x1
//         0052ef26     POP        ESI
//         0052ef27     RET        0x4
//         0052ef2a     ??         90h
//         0052ef2b     NOP
//         0052ef2c     NOP
//         0052ef2d     NOP
//         0052ef2e     NOP
//         0052ef2f     NOP
    return 0;
}

uchar TRIBE_World::new_game(RGE_Player_Info* param_1, int param_2) {
    /* TODO: Stub */
//                              uchar __thiscall new_game(TRIBE_World * this, RGE_Player_Info * para
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[1]:     0052ef5a(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052ef4f(R)
//              char[4096]        Stack[-0x101   description               XREF[0,4]:   0052f016(*), 0052f032(*), 0052f04e(*), 0052f06a(*)
//              char[256]         Stack[-0x111   str3
//              char[256]         Stack[-0x121   str2
//              char[256]         Stack[-0x131   str1                      XREF[0,1]:   0052ef82(W)
//              uchar             Stack[-0x131   ret_num
//              int               Stack[-0x131   victoryAmount
//                               ?new_game@TRIBE_World@@UAEEAAURGE_Player_Info@@H@Z           XREF[1]:     00577528(*)
//                               TRIBE_World::new_game
//                              tworld.cpp:525 (31)
//         0052ef30     PUSH       -0x1
//         0052ef32     MOV        EAX,FS:[0x0]
//         0052ef38     PUSH       FUN_00561aee
//         0052ef3d     PUSH       EAX
//         0052ef3e     MOV        EAX,0x1308
//         0052ef43     MOV        dword ptr FS:[0x0],ESP
//         0052ef4a     CALL       __alloca_probe                                   undefined __alloca_probe()
//                              tworld.cpp:544 (43)
//         0052ef4f     MOV        EAX,dword ptr [ESP + param_2]
//         0052ef56     PUSH       EBX
//         0052ef57     PUSH       EBP
//         0052ef58     MOV        EBP,this
//         0052ef5a     MOV        this,dword ptr [ESP + param_1]
//         0052ef61     PUSH       ESI
//         0052ef62     PUSH       EDI
//         0052ef63     PUSH       EAX
//         0052ef64     PUSH       this
//         0052ef65     MOV        this,EBP
//         0052ef67     MOV        byte ptr [EBP + 0x11c],0x0
//         0052ef6e     MOV        byte ptr [EBP + 0x11d],0xff
//         0052ef75     CALL       RGE_Game_World::new_game                         uchar new_game(RGE_Game_World * this, RGE_Pla
//                              tworld.cpp:546 (14)
//         0052ef7a     XOR        ESI,ESI
//         0052ef7c     MOV        BL,AL
//         0052ef7e     CMP        word ptr [EBP + 0x3c],SI
//         0052ef82     MOV        byte ptr [ESP + str1[3]],BL
//         0052ef86     JLE        LAB_0052ef9d
//                               LAB_0052ef88                                                 XREF[1]:     0052ef9b(j)
//                              tworld.cpp:547 (21)
//         0052ef88     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052ef8e     PUSH       ESI
//         0052ef8f     CALL       RGE_Base_Game::reset_countdown_timer             void reset_countdown_timer(RGE_Base_Game * th
//         0052ef94     MOVSX      EDX,word ptr [EBP + 0x3c]
//         0052ef98     INC        ESI
//         0052ef99     CMP        ESI,EDX
//         0052ef9b     JL         LAB_0052ef88
//                               LAB_0052ef9d                                                 XREF[1]:     0052ef86(j)
//                              tworld.cpp:549 (49)
//         0052ef9d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efa3     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
//         0052efa8     TEST       EAX,EAX
//         0052efaa     JNZ        LAB_0052efbb
//         0052efac     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efb2     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         0052efb7     TEST       EAX,EAX
//         0052efb9     JNZ        LAB_0052efce
//                               LAB_0052efbb                                                 XREF[1]:     0052efaa(j)
//         0052efbb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efc1     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052efc6     TEST       EAX,EAX
//         0052efc8     JZ         LAB_0052f765
//                               LAB_0052efce                                                 XREF[1]:     0052efb9(j)
//                              tworld.cpp:551 (30)
//         0052efce     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efd4     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
//         0052efd9     TEST       EAX,EAX
//         0052efdb     JNZ        LAB_0052eff9
//         0052efdd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efe3     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         0052efe8     TEST       EAX,EAX
//         0052efea     JZ         LAB_0052eff9
//                              tworld.cpp:552 (13)
//         0052efec     MOV        this,dword ptr [EBP + 0x5c]
//         0052efef     PUSH       s_                                               = ""
//         0052eff4     CALL       RGE_Scenario::Set_scenario_name                  void Set_scenario_name(RGE_Scenario * this, c
//                               LAB_0052eff9                                                 XREF[2]:     0052efdb(j), 0052efea(j)
//                              tworld.cpp:554 (23)
//         0052eff9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052efff     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052f004     CMP        EAX,0x9
//         0052f007     JA         switchD_0052f009::caseD_2
//                               switchD_0052f009::switchD
//         0052f009     JMP        dword ptr [EAX*0x4 + switchD_0052f009::switchd   = 0052f010
//                               switchD_0052f009::caseD_9                                    XREF[3]:     0052f009(j), 005302d4(*),
//                               switchD_0052f009::caseD_0                                                 005302f8(*)
//                              tworld.cpp:558 (26)
//         0052f010     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f016     LEA        EDX=>description[4],[ESP + 0x318]
//         0052f01d     PUSH       0x1000
//         0052f022     PUSH       EDX
//         0052f023     MOV        EAX,dword ptr [this->_padding_]
//         0052f025     PUSH       0x265c
//                              tworld.cpp:559 (2)
//         0052f02a     JMP        LAB_0052f07e
//                               switchD_0052f009::caseD_1                                    XREF[2]:     0052f009(j), 005302d8(*)
//                              tworld.cpp:562 (26)
//         0052f02c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f032     LEA        EDX=>description[4],[ESP + 0x318]
//         0052f039     PUSH       0x1000
//         0052f03e     PUSH       EDX
//         0052f03f     MOV        EAX,dword ptr [this->_padding_]
//         0052f041     PUSH       0x265f
//                              tworld.cpp:563 (2)
//         0052f046     JMP        LAB_0052f07e
//                               switchD_0052f009::caseD_7                                    XREF[2]:     0052f009(j), 005302f0(*)
//                              tworld.cpp:566 (26)
//         0052f048     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f04e     LEA        EDX=>description[4],[ESP + 0x318]
//         0052f055     PUSH       0x1000
//         0052f05a     PUSH       EDX
//         0052f05b     MOV        EAX,dword ptr [this->_padding_]
//         0052f05d     PUSH       0x265d
//                              tworld.cpp:567 (2)
//         0052f062     JMP        LAB_0052f07e
//                               switchD_0052f009::caseD_8                                    XREF[2]:     0052f009(j), 005302f4(*)
//                              tworld.cpp:570 (29)
//         0052f064     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f06a     LEA        EDX=>description[4],[ESP + 0x318]
//         0052f071     PUSH       0x1000
//         0052f076     PUSH       EDX
//         0052f077     MOV        EAX,dword ptr [this->_padding_]
//                              language.dll match for 0x265e: "Score Game: Win this game by
//         0052f079     PUSH       0x265e
//                               LAB_0052f07e                                                 XREF[3]:     0052f02a(j), 0052f046(j),
//                                                                                                         0052f062(j)
//         0052f07e     CALL       dword ptr [EAX + 0x20]
//                               switchD_0052f009::caseD_3                                    XREF[7]:     0052f007(j), 0052f009(j),
//                               switchD_0052f009::caseD_4                                                 005302dc(*), 005302e0(*),
//                               switchD_0052f009::caseD_5                                                 005302e4(*), 005302e8(*),
//                               switchD_0052f009::caseD_6                                                 005302ec(*)
//                               switchD_0052f009::caseD_2
//                              tworld.cpp:603 (27)
//         0052f081     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f087     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         0052f08c     CMP        EAX,0x5
//         0052f08f     JA         switchD_0052f095::default
//                               switchD_0052f095::switchD
//         0052f095     JMP        dword ptr [EAX*0x4 + switchD_0052f095::switchd   = 0052f09c
//                               switchD_0052f095::caseD_0                                    XREF[2]:     0052f095(j), 005302fc(*)
//                              tworld.cpp:605 (18)
//         0052f09c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x2973: "Tiny"
//         0052f0a2     PUSH       0x2973
//         0052f0a7     MOV        EAX,dword ptr [this->_padding_]
//         0052f0a9     CALL       dword ptr [EAX + 0x24]
//         0052f0ac     JMP        LAB_0052f0fa
//                               switchD_0052f095::caseD_1                                    XREF[2]:     0052f095(j), 00530300(*)
//                              tworld.cpp:606 (15)
//         0052f0ae     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f0b4     PUSH       0x2974
//         0052f0b9     MOV        EDX,dword ptr [this->_padding_]
//         0052f0bb     JMP        LAB_0052f0f7
//                               switchD_0052f095::caseD_2                                    XREF[2]:     0052f095(j), 00530304(*)
//                              tworld.cpp:607 (15)
//         0052f0bd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f0c3     PUSH       0x2975
//         0052f0c8     MOV        EDX,dword ptr [this->_padding_]
//         0052f0ca     JMP        LAB_0052f0f7
//                               switchD_0052f095::caseD_3                                    XREF[2]:     0052f095(j), 00530308(*)
//                              tworld.cpp:608 (15)
//         0052f0cc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f0d2     PUSH       0x2976
//         0052f0d7     MOV        EDX,dword ptr [this->_padding_]
//         0052f0d9     JMP        LAB_0052f0f7
//                               switchD_0052f095::caseD_4                                    XREF[2]:     0052f095(j), 0053030c(*)
//                              tworld.cpp:609 (15)
//         0052f0db     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x2977: "Huge"
//         0052f0e1     PUSH       0x2977
//         0052f0e6     MOV        EDX,dword ptr [this->_padding_]
//         0052f0e8     JMP        LAB_0052f0f7
//                               switchD_0052f095::caseD_5                                    XREF[2]:     0052f095(j), 00530310(*)
//                              tworld.cpp:610 (51)
//         0052f0ea     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x2978: "Gigantic"
//         0052f0f0     PUSH       0x2978
//         0052f0f5     MOV        EDX,dword ptr [this->_padding_]
//                               LAB_0052f0f7                                                 XREF[4]:     0052f0bb(j), 0052f0ca(j),
//                                                                                                         0052f0d9(j), 0052f0e8(j)
//         0052f0f7     CALL       dword ptr [EDX + 0x24]
//                               LAB_0052f0fa                                                 XREF[1]:     0052f0ac(j)
//         0052f0fa     MOV        EDI,EAX
//         0052f0fc     OR         this,0xffffffff
//         0052f0ff     XOR        EAX,EAX
//         0052f101     LEA        EDX,[ESP + 0x18]
//         0052f105     SCASB.RE   ES:EDI
//         0052f107     NOT        this
//         0052f109     SUB        EDI,this
//         0052f10b     MOV        EAX,this
//         0052f10d     MOV        ESI,EDI
//         0052f10f     MOV        EDI,EDX
//         0052f111     SHR        this,0x2
//         0052f114     MOVSD.REP  ES:EDI,ESI
//         0052f116     MOV        this,EAX
//         0052f118     AND        this,0x3
//         0052f11b     MOVSB.REP  ES:EDI,ESI
//                               switchD_0052f095::default                                    XREF[1]:     0052f08f(j)
//                              tworld.cpp:612 (38)
//         0052f11d     LEA        this,[ESP + 0x18]
//         0052f121     PUSH       this
//         0052f122     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25da: "Map Size: %s"
//         0052f128     PUSH       offset DAT_fffffff8
//         0052f12d     MOV        EDX,dword ptr [this->_padding_]
//         0052f12f     CALL       dword ptr [EDX + 0x24]
//         0052f132     PUSH       EAX
//         0052f133     LEA        EAX,[ESP + 0x120]
//         0052f13a     PUSH       EAX=>DAT_fffffff8
//         0052f13b     CALL       sprintf                                          undefined sprintf()
//         0052f140     ADD        ESP,0xc
//                              tworld.cpp:613 (34)
//         0052f143     LEA        this,[ESP + 0x118]
//         0052f14a     LEA        EDX,[ESP + 0x318]
//         0052f151     LEA        EAX,[ESP + 0x318]
//         0052f158     PUSH       this
//         0052f159     PUSH       EDX
//         0052f15a     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f15f     PUSH       EAX=>DAT_fffffff4
//         0052f160     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:616 (22)
//         0052f165     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f16b     ADD        ESP,0x10
//         0052f16e     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         0052f173     TEST       EAX,EAX
//         0052f175     JZ         LAB_0052f28c
//                              tworld.cpp:618 (27)
//         0052f17b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f181     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         0052f186     CMP        EAX,0x8
//         0052f189     JA         switchD_0052f18f::default
//                               switchD_0052f18f::switchD
//         0052f18f     JMP        dword ptr [EAX*0x4 + switchD_0052f18f::switchd   = 0052f196
//                               switchD_0052f18f::caseD_0                                    XREF[2]:     0052f18f(j), 00530314(*)
//                              tworld.cpp:620 (15)
//         0052f196     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f19c     PUSH       0x296a
//         0052f1a1     MOV        EDX,dword ptr [this->_padding_]
//         0052f1a3     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_1                                    XREF[2]:     0052f18f(j), 00530318(*)
//                              tworld.cpp:621 (15)
//         0052f1a5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1ab     PUSH       0x296b
//         0052f1b0     MOV        EDX,dword ptr [this->_padding_]
//         0052f1b2     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_2                                    XREF[2]:     0052f18f(j), 0053031c(*)
//                              tworld.cpp:622 (15)
//         0052f1b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1ba     PUSH       0x296c
//         0052f1bf     MOV        EDX,dword ptr [this->_padding_]
//         0052f1c1     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_3                                    XREF[2]:     0052f18f(j), 00530320(*)
//                              tworld.cpp:623 (15)
//         0052f1c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1c9     PUSH       0x296d
//         0052f1ce     MOV        EDX,dword ptr [this->_padding_]
//         0052f1d0     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_4                                    XREF[2]:     0052f18f(j), 00530324(*)
//                              tworld.cpp:624 (15)
//         0052f1d2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1d8     PUSH       0x296e
//         0052f1dd     MOV        EDX,dword ptr [this->_padding_]
//         0052f1df     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_5                                    XREF[2]:     0052f18f(j), 00530328(*)
//                              tworld.cpp:625 (15)
//         0052f1e1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1e7     PUSH       0x296f
//         0052f1ec     MOV        EDX,dword ptr [this->_padding_]
//         0052f1ee     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_6                                    XREF[2]:     0052f18f(j), 0053032c(*)
//                              tworld.cpp:626 (15)
//         0052f1f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f1f6     PUSH       0x2970
//         0052f1fb     MOV        EDX,dword ptr [this->_padding_]
//         0052f1fd     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_7                                    XREF[2]:     0052f18f(j), 00530330(*)
//                              tworld.cpp:627 (15)
//         0052f1ff     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f205     PUSH       0x2971
//         0052f20a     MOV        EDX,dword ptr [this->_padding_]
//         0052f20c     JMP        LAB_0052f21b
//                               switchD_0052f18f::caseD_8                                    XREF[2]:     0052f18f(j), 00530334(*)
//                              tworld.cpp:628 (51)
//         0052f20e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x2972: "Narrows"
//                              language.dll match for 0x2972: "******* SIZE *******"
//         0052f214     PUSH       0x2972
//         0052f219     MOV        EDX,dword ptr [this->_padding_]
//                               LAB_0052f21b                                                 XREF[8]:     0052f1a3(j), 0052f1b2(j),
//                                                                                                         0052f1c1(j), 0052f1d0(j),
//                                                                                                         0052f1df(j), 0052f1ee(j),
//                                                                                                         0052f1fd(j), 0052f20c(j)
//         0052f21b     CALL       dword ptr [EDX + 0x24]
//         0052f21e     MOV        EDI,EAX
//         0052f220     OR         this,0xffffffff
//         0052f223     XOR        EAX,EAX
//         0052f225     LEA        EDX,[ESP + 0x18]
//         0052f229     SCASB.RE   ES:EDI
//         0052f22b     NOT        this
//         0052f22d     SUB        EDI,this
//         0052f22f     MOV        EAX,this
//         0052f231     MOV        ESI,EDI
//         0052f233     MOV        EDI,EDX
//         0052f235     SHR        this,0x2
//         0052f238     MOVSD.REP  ES:EDI,ESI
//         0052f23a     MOV        this,EAX
//         0052f23c     AND        this,0x3
//         0052f23f     MOVSB.REP  ES:EDI,ESI
//                               switchD_0052f18f::default                                    XREF[1]:     0052f189(j)
//                              tworld.cpp:630 (38)
//         0052f241     LEA        this,[ESP + 0x18]
//         0052f245     PUSH       this
//         0052f246     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25b6: "Map Type: %s"
//         0052f24c     PUSH       offset DAT_fffffff8
//         0052f251     MOV        EDX,dword ptr [this->_padding_]
//         0052f253     CALL       dword ptr [EDX + 0x24]
//         0052f256     PUSH       EAX
//         0052f257     LEA        EAX,[ESP + 0x120]
//         0052f25e     PUSH       EAX=>DAT_fffffff8
//         0052f25f     CALL       sprintf                                          undefined sprintf()
//         0052f264     ADD        ESP,0xc
//                              tworld.cpp:631 (37)
//         0052f267     LEA        this,[ESP + 0x118]
//         0052f26e     LEA        EDX,[ESP + 0x318]
//         0052f275     LEA        EAX,[ESP + 0x318]
//         0052f27c     PUSH       this
//         0052f27d     PUSH       EDX
//         0052f27e     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f283     PUSH       EAX=>DAT_fffffff4
//         0052f284     CALL       sprintf                                          undefined sprintf()
//         0052f289     ADD        ESP,0x10
//                               LAB_0052f28c                                                 XREF[1]:     0052f175(j)
//                              tworld.cpp:669 (11)
//         0052f28c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f292     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
//                              tworld.cpp:670 (4)
//         0052f297     TEST       EAX,EAX
//         0052f299     JNZ        LAB_0052f2b4
//                              tworld.cpp:671 (23)
//         0052f29b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f2a1     LEA        EAX,[ESP + 0x18]
//         0052f2a5     PUSH       0x100
//         0052f2aa     PUSH       EAX
//         0052f2ab     MOV        EDX,dword ptr [this->_padding_]
//         0052f2ad     PUSH       offset DAT_fffffff8
//                              tworld.cpp:672 (2)
//         0052f2b2     JMP        LAB_0052f2dd
//                               LAB_0052f2b4                                                 XREF[1]:     0052f299(j)
//                              tworld.cpp:673 (28)
//         0052f2b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f2ba     CMP        EAX,0x1
//         0052f2bd     PUSH       0x100
//         0052f2c2     MOV        EDX,dword ptr [this->_padding_]
//         0052f2c4     JNZ        LAB_0052f2d2
//         0052f2c6     LEA        EAX,[ESP + 0x1c]
//         0052f2ca     PUSH       EAX
//                              language.dll match for 0x106e: "Nomad"
//         0052f2cb     PUSH       offset DAT_fffffff8
//                              tworld.cpp:674 (2)
//         0052f2d0     JMP        LAB_0052f2dd
//                               LAB_0052f2d2                                                 XREF[1]:     0052f2c4(j)
//                              tworld.cpp:675 (14)
//         0052f2d2     LEA        ESI,[ESP + 0x1c]
//         0052f2d6     ADD        EAX,0x1067
//         0052f2db     PUSH       ESI
//         0052f2dc     PUSH       EAX=>DAT_fffffff8
//                               LAB_0052f2dd                                                 XREF[2]:     0052f2b2(j), 0052f2d0(j)
//         0052f2dd     CALL       dword ptr [EDX + 0x20]
//                              tworld.cpp:676 (38)
//         0052f2e0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f2e6     LEA        EAX,[ESP + 0x18]
//         0052f2ea     PUSH       EAX
//                              language.dll match for 0x25e4: "Age: %s"
//         0052f2eb     PUSH       offset DAT_fffffff8
//         0052f2f0     MOV        EDX,dword ptr [this->_padding_]
//         0052f2f2     CALL       dword ptr [EDX + 0x24]
//         0052f2f5     PUSH       EAX
//         0052f2f6     LEA        EAX,[ESP + 0x120]
//         0052f2fd     PUSH       EAX=>DAT_fffffff8
//         0052f2fe     CALL       sprintf                                          undefined sprintf()
//         0052f303     ADD        ESP,0xc
//                              tworld.cpp:677 (34)
//         0052f306     LEA        this,[ESP + 0x118]
//         0052f30d     LEA        EDX,[ESP + 0x318]
//         0052f314     LEA        EAX,[ESP + 0x318]
//         0052f31b     PUSH       this
//         0052f31c     PUSH       EDX
//         0052f31d     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f322     PUSH       EAX=>DAT_fffffff4
//         0052f323     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:680 (14)
//         0052f328     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f32e     ADD        ESP,0x10
//         0052f331     CALL       TRIBE_Game::resourceLevel                        ResourceLevel resourceLevel(TRIBE_Game * this)
//                              tworld.cpp:682 (27)
//         0052f336     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f33c     PUSH       0x100
//         0052f341     TEST       EAX,EAX
//         0052f343     MOV        EDX,dword ptr [this->_padding_]
//         0052f345     JNZ        LAB_0052f353
//         0052f347     LEA        EAX,[ESP + 0x1c]
//         0052f34b     PUSH       EAX
//                              language.dll match for 0x10e7: "Default"
//         0052f34c     PUSH       offset DAT_fffffff8
//                              tworld.cpp:683 (2)
//         0052f351     JMP        LAB_0052f35e
//                               LAB_0052f353                                                 XREF[1]:     0052f345(j)
//                              tworld.cpp:684 (14)
//         0052f353     LEA        ESI,[ESP + 0x1c]
//         0052f357     ADD        EAX,0x25e5
//         0052f35c     PUSH       ESI
//         0052f35d     PUSH       EAX=>DAT_fffffff8
//                               LAB_0052f35e                                                 XREF[1]:     0052f351(j)
//         0052f35e     CALL       dword ptr [EDX + 0x20]
//                              tworld.cpp:685 (38)
//         0052f361     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f367     LEA        EAX,[ESP + 0x18]
//         0052f36b     PUSH       EAX
//                              language.dll match for 0x25e5: "Resources: %s"
//         0052f36c     PUSH       offset DAT_fffffff8
//         0052f371     MOV        EDX,dword ptr [this->_padding_]
//         0052f373     CALL       dword ptr [EDX + 0x24]
//         0052f376     PUSH       EAX
//         0052f377     LEA        EAX,[ESP + 0x120]
//         0052f37e     PUSH       EAX=>DAT_fffffff8
//         0052f37f     CALL       sprintf                                          undefined sprintf()
//         0052f384     ADD        ESP,0xc
//                              tworld.cpp:686 (34)
//         0052f387     LEA        this,[ESP + 0x118]
//         0052f38e     LEA        EDX,[ESP + 0x318]
//         0052f395     LEA        EAX,[ESP + 0x318]
//         0052f39c     PUSH       this
//         0052f39d     PUSH       EDX
//         0052f39e     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f3a3     PUSH       EAX=>DAT_fffffff4
//         0052f3a4     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:689 (14)
//         0052f3a9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f3af     ADD        ESP,0x10
//         0052f3b2     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//                              tworld.cpp:690 (38)
//         0052f3b7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f3bd     LEA        EDX,[ESP + 0x18]
//         0052f3c1     PUSH       0x100
//         0052f3c6     PUSH       EDX
//         0052f3c7     MOV        ESI,dword ptr [this->_padding_]
//         0052f3c9     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         0052f3ce     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f3d4     ADD        EAX,0x2bd0
//         0052f3d9     PUSH       EAX=>DAT_fffffff8
//         0052f3da     CALL       dword ptr [ESI + 0x20]
//                              tworld.cpp:691 (29)
//         0052f3dd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f3e3     LEA        EDX,[ESP + 0x118]
//         0052f3ea     PUSH       0x100
//         0052f3ef     PUSH       EDX=>DAT_fffffff8
//         0052f3f0     MOV        EAX,dword ptr [this->_padding_]
//                              language.dll match for 0x25e0: "Difficulty Level: %s"
//         0052f3f2     PUSH       offset DAT_fffffff4
//         0052f3f7     CALL       dword ptr [EAX + 0x20]
//                              tworld.cpp:692 (29)
//         0052f3fa     LEA        EAX,[ESP + 0x18]
//         0052f3fe     LEA        this,[ESP + 0x118]
//         0052f405     PUSH       EAX
//         0052f406     LEA        EDX,[ESP + 0x21c]
//         0052f40d     PUSH       this=>DAT_fffffff8
//         0052f40e     PUSH       EDX=>DAT_fffffff4
//         0052f40f     CALL       sprintf                                          undefined sprintf()
//         0052f414     ADD        ESP,0xc
//                              tworld.cpp:693 (34)
//         0052f417     LEA        EAX,[ESP + 0x218]
//         0052f41e     LEA        this,[ESP + 0x318]
//         0052f425     LEA        EDX,[ESP + 0x318]
//         0052f42c     PUSH       EAX
//         0052f42d     PUSH       this=>DAT_fffffff8
//         0052f42e     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f433     PUSH       EDX=>DAT_fffffff0
//         0052f434     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:696 (14)
//         0052f439     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f43f     ADD        ESP,0x10
//         0052f442     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
//                              tworld.cpp:697 (27)
//         0052f447     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f44d     LEA        EDX,[ESP + 0x18]
//         0052f451     TEST       EAX,EAX
//         0052f453     MOV        EAX,dword ptr [this->_padding_]
//         0052f455     PUSH       0x100
//         0052f45a     PUSH       EDX=>DAT_fffffff8
//         0052f45b     JZ         LAB_0052f464
//         0052f45d     PUSH       offset DAT_fffffff4
//                              tworld.cpp:698 (2)
//         0052f462     JMP        LAB_0052f469
//                              language.dll match for 0xfa3: "Yes"
//                               LAB_0052f464                                                 XREF[1]:     0052f45b(j)
//                              tworld.cpp:699 (8)
//         0052f464     PUSH       offset DAT_fffffff4
//                               LAB_0052f469                                                 XREF[1]:     0052f462(j)
//         0052f469     CALL       dword ptr [EAX + 0x20]
//                              tworld.cpp:700 (38)
//         0052f46c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f472     LEA        EAX,[ESP + 0x18]
//         0052f476     PUSH       EAX
//                              language.dll match for 0x25e9: "Fixed Positions: %s"
//         0052f477     PUSH       offset DAT_fffffff8
//         0052f47c     MOV        EDX,dword ptr [this->_padding_]
//         0052f47e     CALL       dword ptr [EDX + 0x24]
//         0052f481     PUSH       EAX
//         0052f482     LEA        EAX,[ESP + 0x120]
//         0052f489     PUSH       EAX=>DAT_fffffff8
//         0052f48a     CALL       sprintf                                          undefined sprintf()
//         0052f48f     ADD        ESP,0xc
//                              tworld.cpp:701 (34)
//         0052f492     LEA        this,[ESP + 0x118]
//         0052f499     LEA        EDX,[ESP + 0x318]
//         0052f4a0     LEA        EAX,[ESP + 0x318]
//         0052f4a7     PUSH       this
//         0052f4a8     PUSH       EDX
//         0052f4a9     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f4ae     PUSH       EAX=>DAT_fffffff4
//         0052f4af     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:704 (14)
//         0052f4b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f4ba     ADD        ESP,0x10
//         0052f4bd     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//                              tworld.cpp:705 (17)
//         0052f4c2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f4c8     TEST       EAX,EAX
//         0052f4ca     MOV        EDX,dword ptr [this->_padding_]
//         0052f4cc     JZ         LAB_0052f4d5
//         0052f4ce     PUSH       0xfa3
//                              tworld.cpp:706 (2)
//         0052f4d3     JMP        LAB_0052f4da
//                              language.dll match for 0xfa4: "No"
//                               LAB_0052f4d5                                                 XREF[1]:     0052f4cc(j)
//                              tworld.cpp:707 (43)
//         0052f4d5     PUSH       0xfa4
//                               LAB_0052f4da                                                 XREF[1]:     0052f4d3(j)
//         0052f4da     CALL       dword ptr [EDX + 0x24]
//         0052f4dd     MOV        EDI,EAX
//         0052f4df     OR         this,0xffffffff
//         0052f4e2     XOR        EAX,EAX
//         0052f4e4     LEA        EDX,[ESP + 0x18]
//         0052f4e8     SCASB.RE   ES:EDI
//         0052f4ea     NOT        this
//         0052f4ec     SUB        EDI,this
//         0052f4ee     MOV        EAX,this
//         0052f4f0     MOV        ESI,EDI
//         0052f4f2     MOV        EDI,EDX
//         0052f4f4     SHR        this,0x2
//         0052f4f7     MOVSD.REP  ES:EDI,ESI
//         0052f4f9     MOV        this,EAX
//         0052f4fb     AND        this,0x3
//         0052f4fe     MOVSB.REP  ES:EDI,ESI
//                              tworld.cpp:708 (38)
//         0052f500     LEA        this,[ESP + 0x18]
//         0052f504     PUSH       this
//         0052f505     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25b8: "Reveal Map: %s"
//         0052f50b     PUSH       offset DAT_fffffff8
//         0052f510     MOV        EDX,dword ptr [this->_padding_]
//         0052f512     CALL       dword ptr [EDX + 0x24]
//         0052f515     PUSH       EAX
//         0052f516     LEA        EAX,[ESP + 0x120]
//         0052f51d     PUSH       EAX=>DAT_fffffff8
//         0052f51e     CALL       sprintf                                          undefined sprintf()
//         0052f523     ADD        ESP,0xc
//                              tworld.cpp:709 (34)
//         0052f526     LEA        this,[ESP + 0x118]
//         0052f52d     LEA        EDX,[ESP + 0x318]
//         0052f534     LEA        EAX,[ESP + 0x318]
//         0052f53b     PUSH       this
//         0052f53c     PUSH       EDX
//         0052f53d     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f542     PUSH       EAX=>DAT_fffffff4
//         0052f543     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:712 (14)
//         0052f548     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f54e     ADD        ESP,0x10
//         0052f551     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
//                              tworld.cpp:713 (27)
//         0052f556     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f55c     PUSH       0x100
//         0052f561     TEST       EAX,EAX
//         0052f563     MOV        EDX,dword ptr [this->_padding_]
//         0052f565     LEA        EAX,[ESP + 0x1c]
//         0052f569     PUSH       EAX
//         0052f56a     JZ         LAB_0052f573
//         0052f56c     PUSH       offset DAT_fffffff8
//                              tworld.cpp:714 (2)
//         0052f571     JMP        LAB_0052f578
//                              language.dll match for 0xfa4: "No"
//                               LAB_0052f573                                                 XREF[1]:     0052f56a(j)
//                              tworld.cpp:715 (8)
//         0052f573     PUSH       offset DAT_fffffff8
//                               LAB_0052f578                                                 XREF[1]:     0052f571(j)
//         0052f578     CALL       dword ptr [EDX + 0x20]
//                              tworld.cpp:716 (38)
//         0052f57b     LEA        this,[ESP + 0x18]
//         0052f57f     PUSH       this
//         0052f580     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25ec: "Full Tech Tree: %s"
//         0052f586     PUSH       offset DAT_fffffff8
//         0052f58b     MOV        EDX,dword ptr [this->_padding_]
//         0052f58d     CALL       dword ptr [EDX + 0x24]
//         0052f590     PUSH       EAX
//         0052f591     LEA        EAX,[ESP + 0x120]
//         0052f598     PUSH       EAX=>DAT_fffffff8
//         0052f599     CALL       sprintf                                          undefined sprintf()
//         0052f59e     ADD        ESP,0xc
//                              tworld.cpp:717 (34)
//         0052f5a1     LEA        this,[ESP + 0x118]
//         0052f5a8     LEA        EDX,[ESP + 0x318]
//         0052f5af     LEA        EAX,[ESP + 0x318]
//         0052f5b6     PUSH       this
//         0052f5b7     PUSH       EDX
//         0052f5b8     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f5bd     PUSH       EAX=>DAT_fffffff4
//         0052f5be     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:720 (22)
//         0052f5c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f5c9     ADD        ESP,0x10
//         0052f5cc     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         0052f5d1     TEST       EAX,EAX
//         0052f5d3     JZ         LAB_0052f66d
//                              tworld.cpp:722 (11)
//         0052f5d9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f5df     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//                              tworld.cpp:723 (17)
//         0052f5e4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f5ea     TEST       EAX,EAX
//         0052f5ec     MOV        EDX,dword ptr [this->_padding_]
//         0052f5ee     JZ         LAB_0052f5f7
//         0052f5f0     PUSH       0xfa3
//                              tworld.cpp:724 (2)
//         0052f5f5     JMP        LAB_0052f5fc
//                              language.dll match for 0xfa4: "No"
//                               LAB_0052f5f7                                                 XREF[1]:     0052f5ee(j)
//                              tworld.cpp:725 (43)
//         0052f5f7     PUSH       0xfa4
//                               LAB_0052f5fc                                                 XREF[1]:     0052f5f5(j)
//         0052f5fc     CALL       dword ptr [EDX + 0x24]
//         0052f5ff     MOV        EDI,EAX
//         0052f601     OR         this,0xffffffff
//         0052f604     XOR        EAX,EAX
//         0052f606     LEA        EDX,[ESP + 0x18]
//         0052f60a     SCASB.RE   ES:EDI
//         0052f60c     NOT        this
//         0052f60e     SUB        EDI,this
//         0052f610     MOV        EAX,this
//         0052f612     MOV        ESI,EDI
//         0052f614     MOV        EDI,EDX
//         0052f616     SHR        this,0x2
//         0052f619     MOVSD.REP  ES:EDI,ESI
//         0052f61b     MOV        this,EAX
//         0052f61d     AND        this,0x3
//         0052f620     MOVSB.REP  ES:EDI,ESI
//                              tworld.cpp:726 (38)
//         0052f622     LEA        this,[ESP + 0x18]
//         0052f626     PUSH       this
//         0052f627     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25bb: "Enable Cheating: %s"
//         0052f62d     PUSH       offset DAT_fffffff8
//         0052f632     MOV        EDX,dword ptr [this->_padding_]
//         0052f634     CALL       dword ptr [EDX + 0x24]
//         0052f637     PUSH       EAX
//         0052f638     LEA        EAX,[ESP + 0x120]
//         0052f63f     PUSH       EAX=>DAT_fffffff8
//         0052f640     CALL       sprintf                                          undefined sprintf()
//         0052f645     ADD        ESP,0xc
//                              tworld.cpp:727 (37)
//         0052f648     LEA        this,[ESP + 0x118]
//         0052f64f     LEA        EDX,[ESP + 0x318]
//         0052f656     LEA        EAX,[ESP + 0x318]
//         0052f65d     PUSH       this
//         0052f65e     PUSH       EDX
//         0052f65f     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f664     PUSH       EAX=>DAT_fffffff4
//         0052f665     CALL       sprintf                                          undefined sprintf()
//         0052f66a     ADD        ESP,0x10
//                               LAB_0052f66d                                                 XREF[1]:     0052f5d3(j)
//                              tworld.cpp:731 (11)
//         0052f66d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f673     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//                              tworld.cpp:732 (27)
//         0052f678     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f67e     PUSH       0x100
//         0052f683     TEST       EAX,EAX
//         0052f685     MOV        ESI,dword ptr [this->_padding_]
//         0052f687     JZ         LAB_0052f695
//         0052f689     LEA        EDX,[ESP + 0x1c]
//         0052f68d     PUSH       EDX
//         0052f68e     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
//                              tworld.cpp:733 (2)
//         0052f693     JMP        LAB_0052f69f
//                               LAB_0052f695                                                 XREF[1]:     0052f687(j)
//                              tworld.cpp:734 (30)
//         0052f695     LEA        EAX,[ESP + 0x1c]
//         0052f699     PUSH       EAX
//         0052f69a     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
//                               LAB_0052f69f                                                 XREF[1]:     0052f693(j)
//         0052f69f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f6a5     AND        EAX,0xff
//         0052f6aa     ADD        EAX,0x260e
//         0052f6af     PUSH       EAX=>DAT_fffffff8
//         0052f6b0     CALL       dword ptr [ESI + 0x20]
//                              tworld.cpp:735 (38)
//         0052f6b3     LEA        this,[ESP + 0x18]
//         0052f6b7     PUSH       this
//         0052f6b8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              language.dll match for 0x25f1: "Path Finding: %s"
//         0052f6be     PUSH       offset DAT_fffffff8
//         0052f6c3     MOV        EDX,dword ptr [this->_padding_]
//         0052f6c5     CALL       dword ptr [EDX + 0x24]
//         0052f6c8     PUSH       EAX
//         0052f6c9     LEA        EAX,[ESP + 0x120]
//         0052f6d0     PUSH       EAX=>DAT_fffffff8
//         0052f6d1     CALL       sprintf                                          undefined sprintf()
//         0052f6d6     ADD        ESP,0xc
//                              tworld.cpp:736 (34)
//         0052f6d9     LEA        this,[ESP + 0x118]
//         0052f6e0     LEA        EDX,[ESP + 0x318]
//         0052f6e7     LEA        EAX,[ESP + 0x318]
//         0052f6ee     PUSH       this
//         0052f6ef     PUSH       EDX
//         0052f6f0     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f6f5     PUSH       EAX=>DAT_fffffff4
//         0052f6f6     CALL       sprintf                                          undefined sprintf()
//                              tworld.cpp:741 (53)
//         0052f6fb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f701     ADD        ESP,0x10
//         0052f704     CALL       TRIBE_Game::popLimit                             uchar popLimit(TRIBE_Game * this)
//         0052f709     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f70f     AND        EAX,0xff
//         0052f714     PUSH       EAX
//                              language.dll match for 0x25f0: "Population Limit: %d"
//         0052f715     PUSH       0x25f0
//         0052f71a     MOV        EDX,dword ptr [this->_padding_]
//         0052f71c     CALL       dword ptr [EDX + 0x24]
//         0052f71f     PUSH       EAX
//         0052f720     LEA        EAX,[ESP + 0x120]
//         0052f727     PUSH       EAX=>DAT_fffffff8
//         0052f728     CALL       sprintf                                          undefined sprintf()
//         0052f72d     ADD        ESP,0xc
//                              tworld.cpp:742 (37)
//         0052f730     LEA        this,[ESP + 0x118]
//         0052f737     LEA        EDX,[ESP + 0x318]
//         0052f73e     LEA        EAX,[ESP + 0x318]
//         0052f745     PUSH       this
//         0052f746     PUSH       EDX
//         0052f747     PUSH       s_%s_%s                                          = "%s\n%s"
//         0052f74c     PUSH       EAX=>DAT_fffffff4
//         0052f74d     CALL       sprintf                                          undefined sprintf()
//         0052f752     ADD        ESP,0x10
//                              tworld.cpp:745 (16)
//         0052f755     LEA        this,[ESP + 0x318]
//         0052f75c     PUSH       this
//         0052f75d     MOV        this,dword ptr [EBP + 0x5c]
//         0052f760     CALL       RGE_Scenario::add_description                    void add_description(RGE_Scenario * this, cha
//                               LAB_0052f765                                                 XREF[1]:     0052efc8(j)
//                              tworld.cpp:749 (8)
//         0052f765     TEST       BL,BL
//         0052f767     JZ         LAB_0052fc98
//                              tworld.cpp:754 (25)
//         0052f76d     XOR        EBX,EBX
//         0052f76f     MOV        dword ptr [EBP + 0x108],0x4
//         0052f779     MOV        byte ptr [EBP + 0x114],0x0
//         0052f780     MOV        dword ptr [EBP + 0x118],EBX
//                              tworld.cpp:756 (49)
//         0052f786     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f78c     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
//         0052f791     TEST       EAX,EAX
//         0052f793     JNZ        LAB_0052f7a4
//         0052f795     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f79b     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         0052f7a0     TEST       EAX,EAX
//         0052f7a2     JNZ        LAB_0052f7b7
//                               LAB_0052f7a4                                                 XREF[1]:     0052f793(j)
//         0052f7a4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f7aa     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052f7af     TEST       EAX,EAX
//         0052f7b1     JZ         LAB_0052f910
//                               LAB_0052f7b7                                                 XREF[1]:     0052f7a2(j)
//                              tworld.cpp:758 (9)
//         0052f7b7     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7ba     PUSH       EBX
//         0052f7bb     CALL       T_Scenario::Set_victory_all_flag                 void Set_victory_all_flag(T_Scenario * this,
//                              tworld.cpp:759 (9)
//         0052f7c0     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7c3     PUSH       EBX
//         0052f7c4     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              tworld.cpp:760 (9)
//         0052f7c9     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7cc     PUSH       EBX
//         0052f7cd     CALL       T_Scenario::Set_Multi_Ruins                      void Set_Multi_Ruins(T_Scenario * this, int p
//                              tworld.cpp:761 (9)
//         0052f7d2     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7d5     PUSH       EBX
//         0052f7d6     CALL       T_Scenario::Set_Multi_Artifacts                  void Set_Multi_Artifacts(T_Scenario * this, i
//                              tworld.cpp:762 (9)
//         0052f7db     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7de     PUSH       EBX
//         0052f7df     CALL       T_Scenario::Set_Multi_Discoveries                void Set_Multi_Discoveries(T_Scenario * this,
//                              tworld.cpp:763 (9)
//         0052f7e4     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7e7     PUSH       EBX
//         0052f7e8     CALL       T_Scenario::Set_Multi_Exploration                void Set_Multi_Exploration(T_Scenario * this,
//                              tworld.cpp:764 (9)
//         0052f7ed     MOV        this,dword ptr [EBP + 0x5c]
//         0052f7f0     PUSH       EBX
//         0052f7f1     CALL       T_Scenario::Set_Multi_Gold                       void Set_Multi_Gold(T_Scenario * this, int pa
//                              tworld.cpp:766 (11)
//         0052f7f6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f7fc     CALL       TRIBE_Game::victoryAmount                        int victoryAmount(TRIBE_Game * this)
//                              tworld.cpp:768 (33)
//         0052f801     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f807     MOV        EDI,EAX
//         0052f809     MOV        dword ptr [ESP + 0x10],EDI
//         0052f80d     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052f812     CMP        EAX,0x9
//         0052f815     JA         switchD_0052f81b::default
//                               switchD_0052f81b::switchD
//         0052f81b     JMP        dword ptr [EAX*0x4 + switchD_0052f81b::switchd   = 0052f822
//                               switchD_0052f81b::caseD_9                                    XREF[3]:     0052f81b(j), 00530338(*),
//                               switchD_0052f81b::caseD_0                                                 0053035c(*)
//                              tworld.cpp:773 (16)
//         0052f822     MOV        this,dword ptr [EBP + 0x5c]
//         0052f825     PUSH       0x1
//         0052f827     MOV        dword ptr [EBP + 0x108],EBX
//         0052f82d     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              tworld.cpp:774 (2)
//         0052f832     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_1                                    XREF[2]:     0052f81b(j), 0053033c(*)
//                              tworld.cpp:778 (20)
//         0052f834     MOV        this,dword ptr [EBP + 0x5c]
//         0052f837     PUSH       0x1
//         0052f839     MOV        dword ptr [EBP + 0x108],0x1
//         0052f843     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              tworld.cpp:779 (2)
//         0052f848     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_7                                    XREF[2]:     0052f81b(j), 00530354(*)
//                              tworld.cpp:783 (20)
//         0052f84a     MOV        this,dword ptr [EBP + 0x5c]
//         0052f84d     PUSH       0x1
//         0052f84f     MOV        dword ptr [EBP + 0x108],0x2
//         0052f859     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              tworld.cpp:784 (2)
//         0052f85e     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_8                                    XREF[2]:     0052f81b(j), 00530358(*)
//                              tworld.cpp:788 (20)
//         0052f860     MOV        this,dword ptr [EBP + 0x5c]
//         0052f863     PUSH       0x1
//         0052f865     MOV        dword ptr [EBP + 0x108],0x3
//         0052f86f     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
//                              tworld.cpp:789 (2)
//         0052f874     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_3                                    XREF[2]:     0052f81b(j), 00530344(*)
//                              tworld.cpp:792 (9)
//         0052f876     MOV        this,dword ptr [EBP + 0x5c]
//         0052f879     PUSH       EDI
//         0052f87a     CALL       T_Scenario::Set_Multi_Ruins                      void Set_Multi_Ruins(T_Scenario * this, int p
//                              tworld.cpp:793 (2)
//         0052f87f     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_4                                    XREF[2]:     0052f81b(j), 00530348(*)
//                              tworld.cpp:796 (9)
//         0052f881     MOV        this,dword ptr [EBP + 0x5c]
//         0052f884     PUSH       EDI
//         0052f885     CALL       T_Scenario::Set_Multi_Artifacts                  void Set_Multi_Artifacts(T_Scenario * this, i
//                              tworld.cpp:797 (2)
//         0052f88a     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_5                                    XREF[2]:     0052f81b(j), 0053034c(*)
//                              tworld.cpp:800 (9)
//         0052f88c     MOV        this,dword ptr [EBP + 0x5c]
//         0052f88f     PUSH       EDI
//         0052f890     CALL       T_Scenario::Set_Multi_Discoveries                void Set_Multi_Discoveries(T_Scenario * this,
//                              tworld.cpp:801 (2)
//         0052f895     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_2                                    XREF[2]:     0052f81b(j), 00530340(*)
//                              tworld.cpp:804 (9)
//         0052f897     MOV        this,dword ptr [EBP + 0x5c]
//         0052f89a     PUSH       EDI
//         0052f89b     CALL       T_Scenario::Set_Multi_Exploration                void Set_Multi_Exploration(T_Scenario * this,
//                              tworld.cpp:805 (2)
//         0052f8a0     JMP        switchD_0052f81b::default
//                               switchD_0052f81b::caseD_6                                    XREF[2]:     0052f81b(j), 00530350(*)
//                              tworld.cpp:808 (9)
//         0052f8a2     MOV        this,dword ptr [EBP + 0x5c]
//         0052f8a5     PUSH       EDI
//         0052f8a6     CALL       T_Scenario::Set_Multi_Gold                       void Set_Multi_Gold(T_Scenario * this, int pa
//                               switchD_0052f81b::default                                    XREF[9]:     0052f815(j), 0052f832(j),
//                                                                                                         0052f848(j), 0052f85e(j),
//                                                                                                         0052f874(j), 0052f87f(j),
//                                                                                                         0052f88a(j), 0052f895(j),
//                                                                                                         0052f8a0(j)
//                              tworld.cpp:813 (9)
//         0052f8ab     MOV        this,dword ptr [EBP + 0x5c]
//         0052f8ae     PUSH       EBX
//         0052f8af     CALL       T_Scenario::Save_victory_conditions_into_players void Save_victory_conditions_into_players(T_S
//                              tworld.cpp:816 (23)
//         0052f8b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f8ba     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         0052f8bf     SUB        EAX,0x7
//         0052f8c2     JZ         LAB_0052f8fa
//         0052f8c4     DEC        EAX
//         0052f8c5     JNZ        switchD_0052f93f::default
//                              tworld.cpp:824 (15)
//         0052f8cb     MOV        ESI,0x1
//         0052f8d0     CMP        word ptr [EBP + 0x3c],SI
//         0052f8d4     JLE        switchD_0052f93f::default
//                               LAB_0052f8da                                                 XREF[1]:     0052f8f3(j)
//                              tworld.cpp:825 (27)
//         0052f8da     MOV        EDX,dword ptr [EBP + 0x40]
//         0052f8dd     PUSH       0x1
//         0052f8df     PUSH       EDI
//         0052f8e0     PUSH       EBX=>DAT_fffffff8
//         0052f8e1     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         0052f8e4     MOV        this,dword ptr [EAX + 0x34]
//         0052f8e7     CALL       RGE_Victory_Conditions::add_victory_points       uchar add_victory_points(RGE_Victory_Conditio
//         0052f8ec     MOVSX      this,word ptr [EBP + 0x3c]
//         0052f8f0     INC        ESI
//         0052f8f1     CMP        ESI,this
//         0052f8f3     JL         LAB_0052f8da
//                              tworld.cpp:826 (5)
//         0052f8f5     JMP        switchD_0052f93f::default
//                               LAB_0052f8fa                                                 XREF[1]:     0052f8c2(j)
//                              tworld.cpp:820 (17)
//         0052f8fa     FILD       dword ptr [ESP + 0x10]
//         0052f8fe     MOV        byte ptr [EBP + 0x114],0x1
//         0052f905     FSTP       float ptr [EBP + 0x118]
//                              tworld.cpp:829 (39)
//         0052f90b     JMP        switchD_0052f93f::default
//                               LAB_0052f910                                                 XREF[1]:     0052f7b1(j)
//         0052f910     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f916     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
//         0052f91b     TEST       EAX,EAX
//         0052f91d     JNZ        LAB_0052f932
//         0052f91f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052f925     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         0052f92a     TEST       EAX,EAX
//         0052f92c     JZ         switchD_0052f93f::default
//                               LAB_0052f932                                                 XREF[1]:     0052f91d(j)
//                              tworld.cpp:832 (20)
//         0052f932     MOV        this,dword ptr [EBP + 0x5c]
//         0052f935     CALL       T_Scenario::GetMPVictory                         int GetMPVictory(T_Scenario * this)
//         0052f93a     CMP        EAX,0x3
//         0052f93d     JA         switchD_0052f93f::default
//                               switchD_0052f93f::switchD
//         0052f93f     JMP        dword ptr [EAX*0x4 + switchD_0052f93f::switchd   = 0052f946
//                               switchD_0052f93f::caseD_0                                    XREF[2]:     0052f93f(j), 00530360(*)
//                              tworld.cpp:835 (6)
//         0052f946     MOV        dword ptr [EBP + 0x108],EBX
//                              tworld.cpp:836 (2)
//         0052f94c     JMP        switchD_0052f93f::default
//                               switchD_0052f93f::caseD_1                                    XREF[2]:     0052f93f(j), 00530364(*)
//                              tworld.cpp:839 (10)
//         0052f94e     MOV        dword ptr [EBP + 0x108],0x1
//                              tworld.cpp:840 (2)
//         0052f958     JMP        switchD_0052f93f::default
//                               switchD_0052f93f::caseD_3                                    XREF[2]:     0052f93f(j), 0053036c(*)
//                              tworld.cpp:845 (39)
//         0052f95a     MOV        this,dword ptr [EBP + 0x5c]
//         0052f95d     MOV        dword ptr [EBP + 0x108],0x2
//         0052f967     MOV        byte ptr [EBP + 0x114],0x1
//         0052f96e     CALL       T_Scenario::GetVictoryTime                       int GetVictoryTime(T_Scenario * this)
//         0052f973     MOV        dword ptr [ESP + 0x10],EAX
//         0052f977     FILD       dword ptr [ESP + 0x10]
//         0052f97b     FSTP       float ptr [EBP + 0x118]
//                              tworld.cpp:846 (2)
//         0052f981     JMP        switchD_0052f93f::default
//                               switchD_0052f93f::caseD_2                                    XREF[2]:     0052f93f(j), 00530368(*)
//                              tworld.cpp:850 (18)
//         0052f983     MOV        this,dword ptr [EBP + 0x5c]
//         0052f986     MOV        dword ptr [EBP + 0x108],0x3
//         0052f990     CALL       T_Scenario::GetVictoryScore                      int GetVictoryScore(T_Scenario * this)
//                              tworld.cpp:851 (13)
//         0052f995     MOV        ESI,0x1
//         0052f99a     MOV        EDI,EAX
//         0052f99c     CMP        word ptr [EBP + 0x3c],SI
//         0052f9a0     JLE        switchD_0052f93f::default
//                               LAB_0052f9a2                                                 XREF[1]:     0052f9bb(j)
//                              tworld.cpp:852 (27)
//         0052f9a2     MOV        EDX,dword ptr [EBP + 0x40]
//         0052f9a5     PUSH       0x1
//         0052f9a7     PUSH       EDI
//         0052f9a8     PUSH       EBX=>DAT_fffffff8
//         0052f9a9     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         0052f9ac     MOV        this,dword ptr [EAX + 0x34]
//         0052f9af     CALL       RGE_Victory_Conditions::add_victory_points       uchar add_victory_points(RGE_Victory_Conditio
//         0052f9b4     MOVSX      this,word ptr [EBP + 0x3c]
//         0052f9b8     INC        ESI
//         0052f9b9     CMP        ESI,this
//         0052f9bb     JL         LAB_0052f9a2
//                               switchD_0052f93f::default                                    XREF[10]:    0052f8c5(j), 0052f8d4(j),
//                                                                                                         0052f8f5(j), 0052f90b(j),
//                                                                                                         0052f92c(j), 0052f93d(j),
//                                                                                                         0052f94c(j), 0052f958(j),
//                                                                                                         0052f981(j), 0052f9a0(j)
//                              tworld.cpp:859 (53)
//         0052f9bd     PUSH       0x1920
//         0052f9c2     CALL       operator_new                                     void * operator_new(uint param_1)
//         0052f9c7     ADD        ESP,0x4
//         0052f9ca     MOV        dword ptr [ESP + 0x10],EAX
//         0052f9ce     CMP        EAX,EBX
//         0052f9d0     MOV        dword ptr [ESP + 0x1320],EBX
//         0052f9d7     JZ         LAB_0052f9ee
//         0052f9d9     MOV        EDX,dword ptr [EBP + 0x28]
//         0052f9dc     PUSH       EBX
//         0052f9dd     PUSH       EBX
//         0052f9de     PUSH       EBP=>DAT_fffffff8
//         0052f9df     PUSH       EBX=>DAT_fffffff4
//         0052f9e0     PUSH       EDX=>DAT_fffffff0
//         0052f9e1     MOV        this,EAX
//         0052f9e3     CALL       RGE_RMM_Object_Generator::RGE_RMM_Object_Gener   undefined RGE_RMM_Object_Generator(RGE_RMM_Ob
//         0052f9e8     MOV        dword ptr [ESP + 0x10],EAX
//         0052f9ec     JMP        LAB_0052f9f2
//                               LAB_0052f9ee                                                 XREF[1]:     0052f9d7(j)
//         0052f9ee     MOV        dword ptr [ESP + 0x10],EBX
//                               LAB_0052f9f2                                                 XREF[1]:     0052f9ec(j)
//                              tworld.cpp:861 (19)
//         0052f9f2     MOV        this,dword ptr [EBP + 0x5c]
//         0052f9f5     MOV        dword ptr [ESP + 0x1320],0xffffffff
//         0052fa00     CALL       T_Scenario::Get_Multi_Artifacts                  int Get_Multi_Artifacts(T_Scenario * this)
//                              tworld.cpp:862 (4)
//         0052fa05     CMP        EAX,EBX
//         0052fa07     JLE        LAB_0052fa57
//                              tworld.cpp:865 (10)
//         0052fa09     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fa0d     XOR        EDI,EDI
//         0052fa0f     CMP        this,EBX
//         0052fa11     JLE        LAB_0052fa3f
//                              tworld.cpp:1128 (17)
//         0052fa13     MOV        EDX,dword ptr [EBP + 0x40]
//         0052fa16     MOV        ESI,this
//                               LAB_0052fa18                                                 XREF[1]:     0052fa3d(j)
//         0052fa18     MOV        this,dword ptr [EDX]
//         0052fa1a     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa1d     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa20     TEST       this,this
//         0052fa22     JZ         LAB_0052fa39
//                               LAB_0052fa24                                                 XREF[1]:     0052fa37(j)
//                              tworld.cpp:867 (13)
//         0052fa24     MOV        EBX,dword ptr [this->_padding_]
//         0052fa26     MOV        EBX,dword ptr [EBX + 0x8]
//         0052fa29     CMP        word ptr [EBX + 0x10],0x9f
//         0052fa2f     JNZ        LAB_0052fa32
//                              tworld.cpp:868 (1)
//         0052fa31     INC        EDI
//                               LAB_0052fa32                                                 XREF[1]:     0052fa2f(j)
//                              tworld.cpp:866 (7)
//         0052fa32     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa35     TEST       this,this
//         0052fa37     JNZ        LAB_0052fa24
//                               LAB_0052fa39                                                 XREF[1]:     0052fa22(j)
//                              tworld.cpp:865 (6)
//         0052fa39     ADD        EDX,0x4
//         0052fa3c     DEC        ESI
//         0052fa3d     JNZ        LAB_0052fa18
//                               LAB_0052fa3f                                                 XREF[1]:     0052fa11(j)
//                              tworld.cpp:870 (2)
//         0052fa3f     SUB        EAX,EDI
//                              tworld.cpp:871 (6)
//         0052fa41     XOR        EBX,EBX
//         0052fa43     CMP        EAX,EBX
//         0052fa45     JLE        LAB_0052fa57
//                              tworld.cpp:872 (16)
//         0052fa47     MOV        this,dword ptr [ESP + 0x10]
//         0052fa4b     PUSH       EBX
//         0052fa4c     PUSH       EAX
//         0052fa4d     PUSH       offset DAT_fffffff8
//         0052fa52     CALL       RGE_RMM_Object_Generator::add_quick_obj          void add_quick_obj(RGE_RMM_Object_Generator *
//                               LAB_0052fa57                                                 XREF[2]:     0052fa07(j), 0052fa45(j)
//                              tworld.cpp:876 (8)
//         0052fa57     MOV        this,dword ptr [EBP + 0x5c]
//         0052fa5a     CALL       T_Scenario::Get_Multi_Discoveries                int Get_Multi_Discoveries(T_Scenario * this)
//                              tworld.cpp:877 (4)
//         0052fa5f     CMP        EAX,EBX
//         0052fa61     JLE        LAB_0052faac
//                              tworld.cpp:880 (10)
//         0052fa63     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fa67     XOR        EDI,EDI
//         0052fa69     CMP        this,EBX
//         0052fa6b     JLE        LAB_0052fa98
//                              tworld.cpp:1128 (17)
//         0052fa6d     MOV        EDX,dword ptr [EBP + 0x40]
//         0052fa70     MOV        ESI,this
//                               LAB_0052fa72                                                 XREF[1]:     0052fa96(j)
//         0052fa72     MOV        this,dword ptr [EDX]
//         0052fa74     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa77     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa7a     TEST       this,this
//         0052fa7c     JZ         LAB_0052fa92
//                               LAB_0052fa7e                                                 XREF[1]:     0052fa90(j)
//                              tworld.cpp:882 (12)
//         0052fa7e     MOV        EBX,dword ptr [this->_padding_]
//         0052fa80     MOV        EBX,dword ptr [EBX + 0x8]
//         0052fa83     CMP        word ptr [EBX + 0x10],0xa
//         0052fa88     JNZ        LAB_0052fa8b
//                              tworld.cpp:883 (1)
//         0052fa8a     INC        EDI
//                               LAB_0052fa8b                                                 XREF[1]:     0052fa88(j)
//                              tworld.cpp:881 (7)
//         0052fa8b     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fa8e     TEST       this,this
//         0052fa90     JNZ        LAB_0052fa7e
//                               LAB_0052fa92                                                 XREF[1]:     0052fa7c(j)
//                              tworld.cpp:880 (6)
//         0052fa92     ADD        EDX,0x4
//         0052fa95     DEC        ESI
//         0052fa96     JNZ        LAB_0052fa72
//                               LAB_0052fa98                                                 XREF[1]:     0052fa6b(j)
//                              tworld.cpp:885 (2)
//         0052fa98     SUB        EAX,EDI
//                              tworld.cpp:886 (4)
//         0052fa9a     TEST       EAX,EAX
//         0052fa9c     JLE        LAB_0052faac
//                              tworld.cpp:887 (14)
//         0052fa9e     MOV        this,dword ptr [ESP + 0x10]
//         0052faa2     PUSH       0x0
//         0052faa4     PUSH       EAX
//         0052faa5     PUSH       offset DAT_fffffff8
//         0052faa7     CALL       RGE_RMM_Object_Generator::add_quick_obj          void add_quick_obj(RGE_RMM_Object_Generator *
//                               LAB_0052faac                                                 XREF[2]:     0052fa61(j), 0052fa9c(j)
//                              tworld.cpp:891 (10)
//         0052faac     MOV        this,dword ptr [EBP + 0x5c]
//         0052faaf     CALL       T_Scenario::Get_Multi_Ruins                      int Get_Multi_Ruins(T_Scenario * this)
//         0052fab4     MOV        EBX,EAX
//                              tworld.cpp:892 (4)
//         0052fab6     TEST       EBX,EBX
//         0052fab8     JLE        LAB_0052fb15
//                              tworld.cpp:895 (10)
//         0052faba     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fabe     XOR        EAX,EAX
//         0052fac0     TEST       this,this
//         0052fac2     JLE        LAB_0052fafa
//                              tworld.cpp:1128 (17)
//         0052fac4     MOV        ESI,dword ptr [EBP + 0x40]
//         0052fac7     MOV        EDI,this
//                               LAB_0052fac9                                                 XREF[1]:     0052faf8(j)
//         0052fac9     MOV        EDX,dword ptr [ESI]
//         0052facb     MOV        this,dword ptr [EDX + 0x28]
//         0052face     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fad1     TEST       this,this
//         0052fad3     JZ         LAB_0052faf4
//                               LAB_0052fad5                                                 XREF[1]:     0052faf2(j)
//                              tworld.cpp:898 (23)
//         0052fad5     MOV        EDX,dword ptr [this->_padding_]
//         0052fad7     MOV        EDX,dword ptr [EDX + 0x8]
//         0052fada     MOV        DX,word ptr [EDX + 0x10]
//         0052fade     CMP        DX,0x9e
//         0052fae3     JZ         LAB_0052faec
//         0052fae5     CMP        DX,0xa3
//         0052faea     JNZ        LAB_0052faed
//                               LAB_0052faec                                                 XREF[1]:     0052fae3(j)
//                              tworld.cpp:899 (1)
//         0052faec     INC        EAX
//                               LAB_0052faed                                                 XREF[1]:     0052faea(j)
//                              tworld.cpp:896 (7)
//         0052faed     MOV        this,dword ptr [ECX + this->_padding_]
//         0052faf0     TEST       this,this
//         0052faf2     JNZ        LAB_0052fad5
//                               LAB_0052faf4                                                 XREF[1]:     0052fad3(j)
//                              tworld.cpp:895 (6)
//         0052faf4     ADD        ESI,0x4
//         0052faf7     DEC        EDI
//         0052faf8     JNZ        LAB_0052fac9
//                               LAB_0052fafa                                                 XREF[1]:     0052fac2(j)
//                              tworld.cpp:901 (2)
//         0052fafa     SUB        EBX,EAX
//                              tworld.cpp:902 (4)
//         0052fafc     TEST       EBX,EBX
//         0052fafe     JLE        LAB_0052fb15
//                              tworld.cpp:903 (25)
//         0052fb00     PUSH       0x0
//         0052fb02     PUSH       EBX
//         0052fb03     MOV        EBX,dword ptr [ESP + 0x18]
//         0052fb07     PUSH       offset DAT_fffffff8
//         0052fb0c     MOV        this,EBX
//         0052fb0e     CALL       RGE_RMM_Object_Generator::add_quick_obj          void add_quick_obj(RGE_RMM_Object_Generator *
//         0052fb13     JMP        LAB_0052fb19
//                               LAB_0052fb15                                                 XREF[2]:     0052fab8(j), 0052fafe(j)
//         0052fb15     MOV        EBX,dword ptr [ESP + 0x10]
//                               LAB_0052fb19                                                 XREF[1]:     0052fb13(j)
//                              tworld.cpp:907 (38)
//         0052fb19     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fb1f     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
//         0052fb24     TEST       EAX,EAX
//         0052fb26     JNZ        LAB_0052fbed
//         0052fb2c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fb32     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         0052fb37     TEST       EAX,EAX
//         0052fb39     JZ         LAB_0052fbed
//                              tworld.cpp:909 (40)
//         0052fb3f     CMP        dword ptr [EBP + 0x108],0x3
//         0052fb46     JZ         LAB_0052fb67
//         0052fb48     PUSH       0x38d
//         0052fb4d     PUSH       s_C:\msdev\work\age1_x1\tworld.cpp               = "C:\\msdev\\work\\age1_x1\\tworld.cpp"
//         0052fb52     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0052fb57     CDQ
//         0052fb58     MOV        this,0x64
//         0052fb5d     ADD        ESP,0x8
//         0052fb60     IDIV       this
//         0052fb62     CMP        EDX,0x32
//         0052fb65     JGE        LAB_0052fb96
//                               LAB_0052fb67                                                 XREF[1]:     0052fb46(j)
//                              tworld.cpp:911 (37)
//         0052fb67     MOV        EDX,dword ptr [EBP + 0x28]
//         0052fb6a     MOV        EAX,0x66666667
//         0052fb6f     MOV        this,dword ptr [EDX + 0x8]
//         0052fb72     IMUL       this
//         0052fb74     SAR        EDX,0x1
//         0052fb76     MOV        EAX,EDX
//         0052fb78     MOV        this,EBX
//         0052fb7a     SHR        EAX,0x1f
//         0052fb7d     ADD        EDX,EAX
//         0052fb7f     PUSH       EDX
//         0052fb80     PUSH       0x5
//         0052fb82     PUSH       offset DAT_fffffff8
//         0052fb87     CALL       RGE_RMM_Object_Generator::add_quick_obj          void add_quick_obj(RGE_RMM_Object_Generator *
//                              tworld.cpp:913 (10)
//         0052fb8c     MOV        dword ptr [EBP + 0x10c],0x5
//                               LAB_0052fb96                                                 XREF[1]:     0052fb65(j)
//                              tworld.cpp:916 (35)
//         0052fb96     PUSH       0x394
//         0052fb9b     PUSH       s_C:\msdev\work\age1_x1\tworld.cpp               = "C:\\msdev\\work\\age1_x1\\tworld.cpp"
//         0052fba0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0052fba5     CDQ
//         0052fba6     MOV        this,0x64
//         0052fbab     ADD        ESP,0x8
//         0052fbae     IDIV       this
//         0052fbb0     CMP        EDX,0x32
//         0052fbb3     JGE        LAB_0052fc7e
//                              tworld.cpp:918 (37)
//         0052fbb9     MOV        EDX,dword ptr [EBP + 0x28]
//         0052fbbc     MOV        EAX,0x66666667
//         0052fbc1     MOV        this,dword ptr [EDX + 0x8]
//         0052fbc4     IMUL       this
//         0052fbc6     SAR        EDX,0x1
//         0052fbc8     MOV        EAX,EDX
//         0052fbca     MOV        this,EBX
//         0052fbcc     SHR        EAX,0x1f
//         0052fbcf     ADD        EDX,EAX
//         0052fbd1     PUSH       EDX
//         0052fbd2     PUSH       0x5
//         0052fbd4     PUSH       offset DAT_fffffff8
//         0052fbd9     CALL       RGE_RMM_Object_Generator::add_quick_obj          void add_quick_obj(RGE_RMM_Object_Generator *
//                              tworld.cpp:920 (10)
//         0052fbde     MOV        dword ptr [EBP + 0x110],0x5
//                              tworld.cpp:923 (5)
//         0052fbe8     JMP        LAB_0052fc7e
//                               LAB_0052fbed                                                 XREF[2]:     0052fb26(j), 0052fb39(j)
//                              tworld.cpp:929 (28)
//         0052fbed     MOVSX      ESI,word ptr [EBP + 0x3c]
//         0052fbf1     TEST       ESI,ESI
//         0052fbf3     MOV        dword ptr [EBP + 0x10c],0x0
//         0052fbfd     JLE        LAB_0052fc37
//         0052fbff     MOV        this,dword ptr [EBP + 0x40]
//         0052fc02     MOV        EDX,ESI
//         0052fc04     MOV        EDI,0x9f
//                               LAB_0052fc09                                                 XREF[1]:     0052fc35(j)
//                              tworld.cpp:930 (12)
//         0052fc09     MOV        EAX,dword ptr [this->_padding_]
//         0052fc0b     MOV        EAX,dword ptr [EAX + 0x28]
//         0052fc0e     MOV        EAX,dword ptr [EAX + 0x4]
//         0052fc11     TEST       EAX,EAX
//         0052fc13     JZ         LAB_0052fc31
//                               LAB_0052fc15                                                 XREF[1]:     0052fc2b(j)
//                              tworld.cpp:931 (11)
//         0052fc15     MOV        EBX,dword ptr [EAX]
//         0052fc17     MOV        EBX,dword ptr [EBX + 0x8]
//         0052fc1a     CMP        word ptr [EBX + 0x10],DI
//         0052fc1e     JNZ        LAB_0052fc26
//                              tworld.cpp:932 (13)
//         0052fc20     INC        dword ptr [EBP + 0x10c]
//                               LAB_0052fc26                                                 XREF[1]:     0052fc1e(j)
//         0052fc26     MOV        EAX,dword ptr [EAX + 0x4]
//         0052fc29     TEST       EAX,EAX
//         0052fc2b     JNZ        LAB_0052fc15
//                              tworld.cpp:930 (4)
//         0052fc2d     MOV        EBX,dword ptr [ESP + 0x10]
//                               LAB_0052fc31                                                 XREF[1]:     0052fc13(j)
//                              tworld.cpp:929 (6)
//         0052fc31     ADD        this,0x4
//         0052fc34     DEC        EDX
//         0052fc35     JNZ        LAB_0052fc09
//                               LAB_0052fc37                                                 XREF[1]:     0052fbfd(j)
//                              tworld.cpp:935 (14)
//         0052fc37     TEST       ESI,ESI
//         0052fc39     MOV        dword ptr [EBP + 0x110],0x0
//         0052fc43     JLE        LAB_0052fc7e
//                              tworld.cpp:934 (3)
//         0052fc45     MOV        EDX,dword ptr [EBP + 0x40]
//                               LAB_0052fc48                                                 XREF[1]:     0052fc7c(j)
//                              tworld.cpp:936 (12)
//         0052fc48     MOV        this,dword ptr [EDX]
//         0052fc4a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0052fc4d     MOV        EAX,dword ptr [EAX + 0x4]
//         0052fc50     TEST       EAX,EAX
//         0052fc52     JZ         LAB_0052fc78
//                               LAB_0052fc54                                                 XREF[1]:     0052fc76(j)
//                              tworld.cpp:938 (23)
//         0052fc54     MOV        this,dword ptr [EAX]
//         0052fc56     MOV        this,dword ptr [ECX + this->_padding_]
//         0052fc59     MOV        this,word ptr [ECX + this->_padding_]
//         0052fc5d     CMP        this,0x9e
//         0052fc62     JZ         LAB_0052fc6b
//         0052fc64     CMP        this,0xa3
//         0052fc69     JNZ        LAB_0052fc71
//                               LAB_0052fc6b                                                 XREF[1]:     0052fc62(j)
//                              tworld.cpp:939 (13)
//         0052fc6b     INC        dword ptr [EBP + 0x110]
//                               LAB_0052fc71                                                 XREF[1]:     0052fc69(j)
//         0052fc71     MOV        EAX,dword ptr [EAX + 0x4]
//         0052fc74     TEST       EAX,EAX
//         0052fc76     JNZ        LAB_0052fc54
//                               LAB_0052fc78                                                 XREF[1]:     0052fc52(j)
//                              tworld.cpp:935 (6)
//         0052fc78     ADD        EDX,0x4
//         0052fc7b     DEC        ESI
//         0052fc7c     JNZ        LAB_0052fc48
//                               LAB_0052fc7e                                                 XREF[3]:     0052fbb3(j), 0052fbe8(j),
//                                                                                                         0052fc43(j)
//                              tworld.cpp:943 (6)
//         0052fc7e     MOV        EDX,dword ptr [EBX]
//         0052fc80     MOV        this,EBX
//         0052fc82     CALL       dword ptr [EDX]
//                              tworld.cpp:944 (20)
//         0052fc84     TEST       EBX,EBX
//         0052fc86     JZ         LAB_0052fc98
//         0052fc88     MOV        this,EBX
//         0052fc8a     CALL       RGE_Random_Map_Module::~RGE_Random_Map_Module    void ~RGE_Random_Map_Module(RGE_Random_Map_Mo
//         0052fc8f     PUSH       EBX
//         0052fc90     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0052fc95     ADD        ESP,0x4
//                               LAB_0052fc98                                                 XREF[2]:     0052f767(j), 0052fc86(j)
//                              tworld.cpp:948 (13)
//         0052fc98     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fc9e     CALL       TRIBE_Game::allowTrading                         int allowTrading(TRIBE_Game * this)
//         0052fca3     TEST       EAX,EAX
//                              tworld.cpp:949 (15)
//         0052fca5     MOV        EDI,0x1
//         0052fcaa     JNZ        LAB_0052fcce
//         0052fcac     CMP        word ptr [EBP + 0x3c],DI
//         0052fcb0     MOV        ESI,EDI
//         0052fcb2     JLE        LAB_0052fcce
//                               LAB_0052fcb4                                                 XREF[1]:     0052fccc(j)
//                              tworld.cpp:950 (26)
//         0052fcb4     MOV        EDX,dword ptr [EBP + 0x40]
//         0052fcb7     MOV        this,dword ptr [EBP + 0x4c]
//         0052fcba     MOV        EDX,dword ptr [EDX + ESI*0x4]
//         0052fcbd     MOV        EAX,dword ptr [this->_padding_]
//         0052fcbf     PUSH       EDX
//         0052fcc0     PUSH       offset DAT_fffffff8
//         0052fcc2     CALL       dword ptr [EAX + 0x8]
//         0052fcc5     MOVSX      EAX,word ptr [EBP + 0x3c]
//         0052fcc9     INC        ESI
//         0052fcca     CMP        ESI,EAX
//         0052fccc     JL         LAB_0052fcb4
//                               LAB_0052fcce                                                 XREF[2]:     0052fcaa(j), 0052fcb2(j)
//                              tworld.cpp:953 (15)
//         0052fcce     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fcd4     CALL       TRIBE_Game::longCombat                           int longCombat(TRIBE_Game * this)
//         0052fcd9     CMP        EAX,EDI
//         0052fcdb     JNZ        LAB_0052fcff
//                              tworld.cpp:954 (8)
//         0052fcdd     CMP        word ptr [EBP + 0x3c],DI
//         0052fce1     MOV        ESI,EDI
//         0052fce3     JLE        LAB_0052fcff
//                               LAB_0052fce5                                                 XREF[1]:     0052fcfd(j)
//                              tworld.cpp:955 (26)
//         0052fce5     MOV        EAX,dword ptr [EBP + 0x40]
//         0052fce8     MOV        this,dword ptr [EBP + 0x4c]
//         0052fceb     MOV        EAX,dword ptr [EAX + ESI*0x4]
//         0052fcee     MOV        EDX,dword ptr [this->_padding_]
//         0052fcf0     PUSH       EAX
//         0052fcf1     PUSH       offset DAT_fffffff8
//         0052fcf3     CALL       dword ptr [EDX + 0x8]
//         0052fcf6     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fcfa     INC        ESI
//         0052fcfb     CMP        ESI,this
//         0052fcfd     JL         LAB_0052fce5
//                               LAB_0052fcff                                                 XREF[2]:     0052fcdb(j), 0052fce3(j)
//                              tworld.cpp:958 (29)
//         0052fcff     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fd05     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
//         0052fd0a     TEST       EAX,EAX
//         0052fd0c     JNZ        LAB_0052fd46
//         0052fd0e     MOV        this,dword ptr [EBP + 0x5c]
//         0052fd11     PUSH       0x2
//         0052fd13     CALL       T_Scenario::GetScenarioOption                    int GetScenarioOption(T_Scenario * this, int
//         0052fd18     TEST       EAX,EAX
//         0052fd1a     JNZ        LAB_0052fd46
//                              tworld.cpp:960 (8)
//         0052fd1c     CMP        word ptr [EBP + 0x3c],DI
//         0052fd20     MOV        ESI,EDI
//         0052fd22     JLE        LAB_0052fd6b
//                               LAB_0052fd24                                                 XREF[1]:     0052fd42(j)
//                              tworld.cpp:961 (32)
//         0052fd24     MOV        EDX,dword ptr [EBP + 0x40]
//         0052fd27     MOV        this,dword ptr [EBP + 0x4c]
//         0052fd2a     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         0052fd2d     MOV        EDX,dword ptr [this->_padding_]
//         0052fd2f     PUSH       EAX
//         0052fd30     MOV        AX,word ptr [EAX + 0x10c]
//         0052fd37     PUSH       EAX=>DAT_fffffff8
//         0052fd38     CALL       dword ptr [EDX + 0x8]
//         0052fd3b     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fd3f     INC        ESI
//         0052fd40     CMP        ESI,this
//         0052fd42     JL         LAB_0052fd24
//                              tworld.cpp:963 (2)
//         0052fd44     JMP        LAB_0052fd6b
//                               LAB_0052fd46                                                 XREF[2]:     0052fd0c(j), 0052fd1a(j)
//                              tworld.cpp:965 (8)
//         0052fd46     CMP        word ptr [EBP + 0x3c],DI
//         0052fd4a     MOV        ESI,EDI
//         0052fd4c     JLE        LAB_0052fd6b
//                               LAB_0052fd4e                                                 XREF[1]:     0052fd69(j)
//                              tworld.cpp:966 (29)
//         0052fd4e     MOV        EAX,dword ptr [EBP + 0x40]
//         0052fd51     MOV        this,dword ptr [EBP + 0x4c]
//         0052fd54     MOV        EAX,dword ptr [EAX + ESI*0x4]
//         0052fd57     MOV        EDX,dword ptr [this->_padding_]
//         0052fd59     PUSH       EAX
//         0052fd5a     PUSH       offset DAT_fffffff8
//         0052fd5f     CALL       dword ptr [EDX + 0x8]
//         0052fd62     MOVSX      this,word ptr [EBP + 0x3c]
//         0052fd66     INC        ESI
//         0052fd67     CMP        ESI,this
//         0052fd69     JL         LAB_0052fd4e
//                               LAB_0052fd6b                                                 XREF[3]:     0052fd22(j), 0052fd44(j),
//                                                                                                         0052fd4c(j)
//                              tworld.cpp:970 (33)
//         0052fd6b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fd71     CALL       TRIBE_Game::resourceLevel                        ResourceLevel resourceLevel(TRIBE_Game * this)
//         0052fd76     DEC        EAX
//         0052fd77     MOV        ESI,0x43fa0000
//         0052fd7c     JZ         LAB_0052fe36
//         0052fd82     DEC        EAX
//         0052fd83     JZ         LAB_0052fde5
//         0052fd85     DEC        EAX
//         0052fd86     JNZ        LAB_0052fe86
//                              tworld.cpp:991 (12)
//         0052fd8c     CMP        word ptr [EBP + 0x3c],DI
//         0052fd90     MOV        EAX,EDI
//         0052fd92     JLE        LAB_0052fe86
//                              tworld.cpp:996 (72)
//         0052fd98     MOV        EDX,0x447a0000
//         0052fd9d     MOV        this,0x443b8000
//         0052fda2     XOR        ESI,ESI
//                               LAB_0052fda4                                                 XREF[1]:     0052fdde(j)
//         0052fda4     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fda7     INC        EAX
//         0052fda8     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fdac     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fdaf     MOV        dword ptr [EDI],EDX
//         0052fdb1     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fdb4     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fdb8     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fdbb     MOV        dword ptr [EDI + 0x4],EDX
//         0052fdbe     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fdc1     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fdc5     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fdc8     MOV        dword ptr [EDI + 0xc],ESI
//         0052fdcb     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fdce     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fdd2     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fdd5     MOV        dword ptr [EDI + 0x8],this
//         0052fdd8     MOVSX      EDI,word ptr [EBP + 0x3c]
//         0052fddc     CMP        EAX,EDI
//         0052fdde     JL         LAB_0052fda4
//                              tworld.cpp:998 (5)
//         0052fde0     JMP        LAB_0052fe86
//                               LAB_0052fde5                                                 XREF[1]:     0052fd83(j)
//                              tworld.cpp:982 (12)
//         0052fde5     CMP        word ptr [EBP + 0x3c],DI
//         0052fde9     MOV        EAX,EDI
//         0052fdeb     JLE        LAB_0052fe86
//                              tworld.cpp:987 (67)
//         0052fdf1     MOV        this,0x437a0000
//         0052fdf6     XOR        EDX,EDX
//                               LAB_0052fdf8                                                 XREF[1]:     0052fe32(j)
//         0052fdf8     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fdfb     INC        EAX
//         0052fdfc     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe00     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe03     MOV        dword ptr [EDI],ESI
//         0052fe05     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe08     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe0c     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe0f     MOV        dword ptr [EDI + 0x4],ESI
//         0052fe12     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe15     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe19     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe1c     MOV        dword ptr [EDI + 0xc],EDX
//         0052fe1f     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe22     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe26     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe29     MOV        dword ptr [EDI + 0x8],this
//         0052fe2c     MOVSX      EDI,word ptr [EBP + 0x3c]
//         0052fe30     CMP        EAX,EDI
//         0052fe32     JL         LAB_0052fdf8
//                              tworld.cpp:989 (2)
//         0052fe34     JMP        LAB_0052fe86
//                               LAB_0052fe36                                                 XREF[1]:     0052fd7c(j)
//                              tworld.cpp:973 (8)
//         0052fe36     CMP        word ptr [EBP + 0x3c],DI
//         0052fe3a     MOV        EAX,EDI
//         0052fe3c     JLE        LAB_0052fe86
//                              tworld.cpp:978 (72)
//         0052fe3e     MOV        EDX,0x43480000
//         0052fe43     MOV        this,0x42c80000
//         0052fe48     XOR        ESI,ESI
//                               LAB_0052fe4a                                                 XREF[1]:     0052fe84(j)
//         0052fe4a     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe4d     INC        EAX
//         0052fe4e     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe52     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe55     MOV        dword ptr [EDI],EDX
//         0052fe57     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe5a     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe5e     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe61     MOV        dword ptr [EDI + 0x4],EDX
//         0052fe64     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe67     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe6b     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe6e     MOV        dword ptr [EDI + 0xc],ESI
//         0052fe71     MOV        EDI,dword ptr [EBP + 0x40]
//         0052fe74     MOV        EDI,dword ptr [EDI + EAX*0x4 + -0x4]
//         0052fe78     MOV        EDI,dword ptr [EDI + 0x50]
//         0052fe7b     MOV        dword ptr [EDI + 0x8],this
//         0052fe7e     MOVSX      EDI,word ptr [EBP + 0x3c]
//         0052fe82     CMP        EAX,EDI
//         0052fe84     JL         LAB_0052fe4a
//                               LAB_0052fe86                                                 XREF[6]:     0052fd86(j), 0052fd92(j),
//                                                                                                         0052fde0(j), 0052fdeb(j),
//                                                                                                         0052fe34(j), 0052fe3c(j)
//                              tworld.cpp:1001 (18)
//         0052fe86     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fe8c     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         0052fe91     TEST       AL,AL
//         0052fe93     MOV        EDI,0x459c4000
//                              tworld.cpp:1003 (15)
//         0052fe98     MOV        EBX,0x1
//         0052fe9d     JZ         LAB_0052feed
//         0052fe9f     CMP        word ptr [EBP + 0x3c],BX
//         0052fea3     MOV        EAX,EBX
//         0052fea5     JLE        LAB_0052feed
//                              tworld.cpp:1008 (70)
//         0052fea7     MOV        EDX,0x469c4000
//         0052feac     MOV        this,0x461c4000
//                               LAB_0052feb1                                                 XREF[1]:     0052feeb(j)
//         0052feb1     MOV        ESI,dword ptr [EBP + 0x40]
//         0052feb4     INC        EAX
//         0052feb5     MOV        ESI,dword ptr [ESI + EAX*0x4 + -0x4]
//         0052feb9     MOV        ESI,dword ptr [ESI + 0x50]
//         0052febc     MOV        dword ptr [ESI],EDX
//         0052febe     MOV        ESI,dword ptr [EBP + 0x40]
//         0052fec1     MOV        ESI,dword ptr [ESI + EAX*0x4 + -0x4]
//         0052fec5     MOV        ESI,dword ptr [ESI + 0x50]
//         0052fec8     MOV        dword ptr [ESI + 0x4],EDX
//         0052fecb     MOV        ESI,dword ptr [EBP + 0x40]
//         0052fece     MOV        ESI,dword ptr [ESI + EAX*0x4 + -0x4]
//         0052fed2     MOV        ESI,dword ptr [ESI + 0x50]
//         0052fed5     MOV        dword ptr [ESI + 0xc],this
//         0052fed8     MOV        ESI,dword ptr [EBP + 0x40]
//         0052fedb     MOV        ESI,dword ptr [ESI + EAX*0x4 + -0x4]
//         0052fedf     MOV        ESI,dword ptr [ESI + 0x50]
//         0052fee2     MOV        dword ptr [ESI + 0x8],EDI
//         0052fee5     MOVSX      ESI,word ptr [EBP + 0x3c]
//         0052fee9     CMP        EAX,ESI
//         0052feeb     JL         LAB_0052feb1
//                               LAB_0052feed                                                 XREF[2]:     0052fe9d(j), 0052fea5(j)
//                              tworld.cpp:1013 (22)
//         0052feed     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052fef3     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
//         0052fef8     SUB        EAX,0x3
//         0052fefb     JZ         LAB_0052ff43
//         0052fefd     DEC        EAX
//         0052fefe     JZ         LAB_0052ff23
//         0052ff00     DEC        EAX
//         0052ff01     JNZ        LAB_0052ff61
//                              tworld.cpp:1024 (8)
//         0052ff03     CMP        word ptr [EBP + 0x3c],BX
//         0052ff07     MOV        ESI,EBX
//         0052ff09     JLE        LAB_0052ff61
//                               LAB_0052ff0b                                                 XREF[1]:     0052ff1f(j)
//                              tworld.cpp:1025 (22)
//         0052ff0b     MOV        EDX,dword ptr [EBP + 0x40]
//         0052ff0e     PUSH       0x18
//         0052ff10     MOV        this,dword ptr [EDX + ESI*0x4]
//         0052ff13     CALL       TRIBE_Player::rev_tech                           void rev_tech(TRIBE_Player * this, long param
//         0052ff18     MOVSX      EAX,word ptr [EBP + 0x3c]
//         0052ff1c     INC        ESI
//         0052ff1d     CMP        ESI,EAX
//         0052ff1f     JL         LAB_0052ff0b
//                              tworld.cpp:1026 (2)
//         0052ff21     JMP        LAB_0052ff61
//                               LAB_0052ff23                                                 XREF[1]:     0052fefe(j)
//                              tworld.cpp:1020 (8)
//         0052ff23     CMP        word ptr [EBP + 0x3c],BX
//         0052ff27     MOV        ESI,EBX
//         0052ff29     JLE        LAB_0052ff61
//                               LAB_0052ff2b                                                 XREF[1]:     0052ff3f(j)
//                              tworld.cpp:1021 (22)
//         0052ff2b     MOV        this,dword ptr [EBP + 0x40]
//         0052ff2e     PUSH       0x17
//         0052ff30     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         0052ff33     CALL       TRIBE_Player::rev_tech                           void rev_tech(TRIBE_Player * this, long param
//         0052ff38     MOVSX      EDX,word ptr [EBP + 0x3c]
//         0052ff3c     INC        ESI
//         0052ff3d     CMP        ESI,EDX
//         0052ff3f     JL         LAB_0052ff2b
//                              tworld.cpp:1022 (2)
//         0052ff41     JMP        LAB_0052ff61
//                               LAB_0052ff43                                                 XREF[1]:     0052fefb(j)
//                              tworld.cpp:1016 (8)
//         0052ff43     CMP        word ptr [EBP + 0x3c],BX
//         0052ff47     MOV        ESI,EBX
//         0052ff49     JLE        LAB_0052ff61
//                               LAB_0052ff4b                                                 XREF[1]:     0052ff5f(j)
//                              tworld.cpp:1017 (22)
//         0052ff4b     MOV        EAX,dword ptr [EBP + 0x40]
//         0052ff4e     PUSH       0x19
//         0052ff50     MOV        this,dword ptr [EAX + ESI*0x4]
//         0052ff53     CALL       TRIBE_Player::rev_tech                           void rev_tech(TRIBE_Player * this, long param
//         0052ff58     MOVSX      this,word ptr [EBP + 0x3c]
//         0052ff5c     INC        ESI
//         0052ff5d     CMP        ESI,this
//         0052ff5f     JL         LAB_0052ff4b
//                               LAB_0052ff61                                                 XREF[6]:     0052ff01(j), 0052ff09(j),
//                                                                                                         0052ff21(j), 0052ff29(j),
//                                                                                                         0052ff41(j), 0052ff49(j)
//                              tworld.cpp:1035 (20)
//         0052ff61     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052ff67     PUSH       s_NOFOODCAP                                      = "NOFOODCAP"
//         0052ff6c     CALL       RGE_Base_Game::check_prog_argument               uchar check_prog_argument(RGE_Base_Game * thi
//         0052ff71     TEST       AL,AL
//         0052ff73     JZ         LAB_0052ffd0
//                              tworld.cpp:1038 (12)
//         0052ff75     CMP        word ptr [EBP + 0x3c],BX
//         0052ff79     MOV        ESI,EBX
//         0052ff7b     JLE        LAB_005302b5
//                               LAB_0052ff81                                                 XREF[1]:     0052ffc9(j)
//                              tworld.cpp:1040 (18)
//         0052ff81     MOV        EDX,dword ptr [EBP + 0x40]
//         0052ff84     PUSH       0x42480000
//         0052ff89     PUSH       offset DAT_fffffff8
//         0052ff8b     MOV        this,dword ptr [EDX + ESI*0x4]
//         0052ff8e     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1041 (15)
//         0052ff93     MOV        EAX,dword ptr [EBP + 0x40]
//         0052ff96     PUSH       0x0
//         0052ff98     PUSH       offset DAT_fffffff8
//         0052ff9a     MOV        this,dword ptr [EAX + ESI*0x4]
//         0052ff9d     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1042 (18)
//         0052ffa2     MOV        this,dword ptr [EBP + 0x40]
//         0052ffa5     PUSH       0x43fa0000
//         0052ffaa     PUSH       offset DAT_fffffff8
//         0052ffac     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         0052ffaf     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1043 (23)
//         0052ffb4     MOV        EDX,dword ptr [EBP + 0x40]
//         0052ffb7     PUSH       EDI
//         0052ffb8     PUSH       offset DAT_fffffff8
//         0052ffba     MOV        this,dword ptr [EDX + ESI*0x4]
//         0052ffbd     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//         0052ffc2     MOVSX      EAX,word ptr [EBP + 0x3c]
//         0052ffc6     INC        ESI
//         0052ffc7     CMP        ESI,EAX
//         0052ffc9     JL         LAB_0052ff81
//                              tworld.cpp:1046 (23)
//         0052ffcb     JMP        LAB_005302b5
//                               LAB_0052ffd0                                                 XREF[1]:     0052ff73(j)
//         0052ffd0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052ffd6     PUSH       s_SYSTEM2                                        = "SYSTEM2"
//         0052ffdb     CALL       RGE_Base_Game::check_prog_argument               uchar check_prog_argument(RGE_Base_Game * thi
//         0052ffe0     TEST       AL,AL
//                              tworld.cpp:1049 (14)
//         0052ffe2     MOV        ESI,EBX
//         0052ffe4     JZ         LAB_0053001f
//         0052ffe6     CMP        word ptr [EBP + 0x3c],BX
//         0052ffea     JLE        LAB_005302b5
//                               LAB_0052fff0                                                 XREF[1]:     00530018(j)
//                              tworld.cpp:1051 (18)
//         0052fff0     MOV        this,dword ptr [EBP + 0x40]
//         0052fff3     PUSH       0x42480000
//         0052fff8     PUSH       offset DAT_fffffff8
//         0052fffa     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         0052fffd     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1052 (24)
//         00530002     MOV        EDX,dword ptr [EBP + 0x40]
//         00530005     PUSH       0x0
//         00530007     PUSH       offset DAT_fffffff8
//         00530009     MOV        this,dword ptr [EDX + ESI*0x4]
//         0053000c     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//         00530011     MOVSX      EAX,word ptr [EBP + 0x3c]
//         00530015     INC        ESI
//         00530016     CMP        ESI,EAX
//         00530018     JL         LAB_0052fff0
//                              tworld.cpp:1055 (5)
//         0053001a     JMP        LAB_005302b5
//                               LAB_0053001f                                                 XREF[1]:     0052ffe4(j)
//                              tworld.cpp:1059 (10)
//         0053001f     CMP        word ptr [EBP + 0x3c],BX
//         00530023     JLE        LAB_005302b5
//                               LAB_00530029                                                 XREF[1]:     005302af(j)
//                              tworld.cpp:1061 (41)
//         00530029     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053002f     CALL       TRIBE_Game::popLimit                             uchar popLimit(TRIBE_Game * this)
//         00530034     AND        EAX,0xff
//         00530039     PUSH       this
//         0053003a     MOV        this,dword ptr [EBP + 0x40]
//         0053003d     MOV        dword ptr [ESP + 0x14],EAX
//         00530041     FILD       dword ptr [ESP + 0x14]
//         00530045     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         00530048     FSTP       float ptr [ESP]
//         0053004b     PUSH       offset DAT_fffffff8
//         0053004d     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1062 (15)
//         00530052     MOV        EDX,dword ptr [EBP + 0x40]
//         00530055     PUSH       0x0
//         00530057     PUSH       offset DAT_fffffff8
//         00530059     MOV        this,dword ptr [EDX + ESI*0x4]
//         0053005c     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1063 (18)
//         00530061     MOV        EAX,dword ptr [EBP + 0x40]
//         00530064     PUSH       0x43fa0000
//         00530069     PUSH       offset DAT_fffffff8
//         0053006b     MOV        this,dword ptr [EAX + ESI*0x4]
//         0053006e     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1065 (18)
//         00530073     MOV        this,dword ptr [EBP + 0x40]
//         00530076     PUSH       0x3f800000
//         0053007b     PUSH       offset DAT_fffffff8
//         0053007d     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         00530080     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tworld.cpp:1070 (23)
//         00530085     MOV        EDX,dword ptr [EBP + 0x40]
//         00530088     PUSH       EBX
//         00530089     PUSH       offset DAT_fffffff8
//         0053008b     PUSH       offset DAT_fffffff4
//         0053008d     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         00530090     PUSH       0x0=>DAT_fffffff0
//         00530092     PUSH       0x0
//         00530094     MOV        this,dword ptr [EAX + 0x34]
//         00530097     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1072 (21)
//         0053009c     MOV        this,dword ptr [EBP + 0x40]
//         0053009f     PUSH       EBX
//         005300a0     PUSH       EBX=>DAT_fffffff8
//         005300a1     PUSH       offset DAT_fffffff4
//         005300a3     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         005300a6     PUSH       EBX=>DAT_fffffff0
//         005300a7     PUSH       0x0
//         005300a9     MOV        this,dword ptr [EDX + 0x34]
//         005300ac     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1074 (22)
//         005300b1     MOV        EAX,dword ptr [EBP + 0x40]
//         005300b4     PUSH       EBX
//         005300b5     PUSH       EBX=>DAT_fffffff8
//         005300b6     PUSH       offset DAT_fffffff4
//         005300b8     MOV        this,dword ptr [EAX + ESI*0x4]
//         005300bb     PUSH       offset DAT_fffffff0
//         005300bd     PUSH       0x0
//         005300bf     MOV        this,dword ptr [ECX + this->_padding_]
//         005300c2     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1076 (23)
//         005300c7     MOV        EDX,dword ptr [EBP + 0x40]
//         005300ca     PUSH       0x19
//         005300cc     PUSH       EBX=>DAT_fffffff8
//         005300cd     PUSH       offset DAT_fffffff4
//         005300cf     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         005300d2     PUSH       offset DAT_fffffff0
//         005300d4     PUSH       0x0
//         005300d6     MOV        this,dword ptr [EAX + 0x34]
//         005300d9     CALL       RGE_Victory_Conditions::add_points_high_attrib   uchar add_points_high_attribute_once(RGE_Vict
//                              tworld.cpp:1079 (22)
//         005300de     MOV        this,dword ptr [EBP + 0x40]
//         005300e1     PUSH       EBX
//         005300e2     PUSH       offset DAT_fffffff8
//         005300e4     PUSH       offset DAT_fffffff4
//         005300e6     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         005300e9     PUSH       offset DAT_fffffff0
//         005300eb     PUSH       EBX
//         005300ec     MOV        this,dword ptr [EDX + 0x34]
//         005300ef     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1081 (22)
//         005300f4     MOV        EAX,dword ptr [EBP + 0x40]
//         005300f7     PUSH       EBX
//         005300f8     PUSH       offset DAT_fffffff8
//         005300fa     PUSH       offset DAT_fffffff4
//         005300fc     MOV        this,dword ptr [EAX + ESI*0x4]
//         005300ff     PUSH       offset DAT_fffffff0
//         00530101     PUSH       EBX
//         00530102     MOV        this,dword ptr [ECX + this->_padding_]
//         00530105     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1083 (21)
//         0053010a     PUSH       EBX
//         0053010b     MOV        EDX,dword ptr [EBP + 0x40]
//         0053010e     PUSH       EBX=>DAT_fffffff8
//         0053010f     PUSH       offset DAT_fffffff4
//         00530111     PUSH       offset DAT_fffffff0
//         00530113     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         00530116     PUSH       EBX
//         00530117     MOV        this,dword ptr [EAX + 0x34]
//         0053011a     CALL       RGE_Victory_Conditions::add_points_high_attrib   uchar add_points_high_attribute_amount(RGE_Vi
//                              tworld.cpp:1085 (22)
//         0053011f     MOV        this,dword ptr [EBP + 0x40]
//         00530122     PUSH       0x19
//         00530124     PUSH       EBX=>DAT_fffffff8
//         00530125     PUSH       offset DAT_fffffff4
//         00530127     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         0053012a     PUSH       offset DAT_fffffff0
//         0053012c     PUSH       EBX
//         0053012d     MOV        this,dword ptr [EDX + 0x34]
//         00530130     CALL       RGE_Victory_Conditions::add_points_high_attrib   uchar add_points_high_attribute_once(RGE_Vict
//                              tworld.cpp:1087 (22)
//         00530135     MOV        EAX,dword ptr [EBP + 0x40]
//         00530138     PUSH       EBX
//         00530139     PUSH       offset DAT_fffffff8
//         0053013b     PUSH       offset DAT_fffffff4
//         0053013d     MOV        this,dword ptr [EAX + ESI*0x4]
//         00530140     PUSH       offset DAT_fffffff0
//         00530142     PUSH       EBX
//         00530143     MOV        this,dword ptr [ECX + this->_padding_]
//         00530146     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1089 (15)
//         0053014b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00530151     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//         00530156     TEST       EAX,EAX
//         00530158     JNZ        LAB_00530170
//                              tworld.cpp:1090 (22)
//         0053015a     MOV        EDX,dword ptr [EBP + 0x40]
//         0053015d     PUSH       0x19
//         0053015f     PUSH       EBX=>DAT_fffffff8
//         00530160     PUSH       offset DAT_fffffff4
//         00530162     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         00530165     PUSH       offset DAT_fffffff0
//         00530167     PUSH       EBX
//         00530168     MOV        this,dword ptr [EAX + 0x34]
//         0053016b     CALL       RGE_Victory_Conditions::add_points_highest_att   uchar add_points_highest_attribute(RGE_Victor
//                               LAB_00530170                                                 XREF[1]:     00530158(j)
//                              tworld.cpp:1093 (23)
//         00530170     MOV        this,dword ptr [EBP + 0x40]
//         00530173     PUSH       0x2
//         00530175     PUSH       EBX=>DAT_fffffff8
//         00530176     PUSH       offset DAT_fffffff4
//         00530178     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         0053017b     PUSH       offset DAT_fffffff0
//         0053017d     PUSH       0x2
//         0053017f     MOV        this,dword ptr [EDX + 0x34]
//         00530182     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1095 (23)
//         00530187     MOV        EAX,dword ptr [EBP + 0x40]
//         0053018a     PUSH       0x19
//         0053018c     PUSH       EBX=>DAT_fffffff8
//         0053018d     PUSH       offset DAT_fffffff4
//         0053018f     MOV        this,dword ptr [EAX + ESI*0x4]
//         00530192     PUSH       offset DAT_fffffff0
//         00530194     PUSH       0x2
//         00530196     MOV        this,dword ptr [ECX + this->_padding_]
//         00530199     CALL       RGE_Victory_Conditions::add_points_highest_att   uchar add_points_highest_attribute(RGE_Victor
//                              tworld.cpp:1097 (23)
//         0053019e     MOV        EDX,dword ptr [EBP + 0x40]
//         005301a1     PUSH       0xa
//         005301a3     PUSH       EBX=>DAT_fffffff8
//         005301a4     PUSH       offset DAT_fffffff4
//         005301a6     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         005301a9     PUSH       offset DAT_fffffff0
//         005301ab     PUSH       0x2
//         005301ad     MOV        this,dword ptr [EAX + 0x34]
//         005301b0     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1099 (23)
//         005301b5     MOV        this,dword ptr [EBP + 0x40]
//         005301b8     PUSH       0xa
//         005301ba     PUSH       EBX=>DAT_fffffff8
//         005301bb     PUSH       offset DAT_fffffff4
//         005301bd     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         005301c0     PUSH       offset DAT_fffffff0
//         005301c2     PUSH       0x2
//         005301c4     MOV        this,dword ptr [EDX + 0x34]
//         005301c7     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1101 (23)
//         005301cc     MOV        EAX,dword ptr [EBP + 0x40]
//         005301cf     PUSH       0x3
//         005301d1     PUSH       EBX=>DAT_fffffff8
//         005301d2     PUSH       offset DAT_fffffff4
//         005301d4     MOV        this,dword ptr [EAX + ESI*0x4]
//         005301d7     PUSH       offset DAT_fffffff0
//         005301d9     PUSH       0x2
//         005301db     MOV        this,dword ptr [ECX + this->_padding_]
//         005301de     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1103 (23)
//         005301e3     MOV        EDX,dword ptr [EBP + 0x40]
//         005301e6     PUSH       0x32
//         005301e8     PUSH       EBX=>DAT_fffffff8
//         005301e9     PUSH       offset DAT_fffffff4
//         005301eb     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         005301ee     PUSH       offset DAT_fffffff0
//         005301f0     PUSH       0x2
//         005301f2     MOV        this,dword ptr [EAX + 0x34]
//         005301f5     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1105 (23)
//         005301fa     MOV        this,dword ptr [EBP + 0x40]
//         005301fd     PUSH       0x32
//         005301ff     PUSH       EBX=>DAT_fffffff8
//         00530200     PUSH       offset DAT_fffffff4
//         00530202     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         00530205     PUSH       offset DAT_fffffff0
//         00530207     PUSH       0x2
//         00530209     MOV        this,dword ptr [EDX + 0x34]
//         0053020c     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1108 (23)
//         00530211     MOV        EAX,dword ptr [EBP + 0x40]
//         00530214     PUSH       0x2
//         00530216     PUSH       EBX=>DAT_fffffff8
//         00530217     PUSH       offset DAT_fffffff4
//         00530219     MOV        this,dword ptr [EAX + ESI*0x4]
//         0053021c     PUSH       offset DAT_fffffff0
//         0053021e     PUSH       0x3
//         00530220     MOV        this,dword ptr [ECX + this->_padding_]
//         00530223     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1110 (23)
//         00530228     MOV        EDX,dword ptr [EBP + 0x40]
//         0053022b     PUSH       0x32
//         0053022d     PUSH       EBX=>DAT_fffffff8
//         0053022e     PUSH       offset DAT_fffffff4
//         00530230     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         00530233     PUSH       offset DAT_fffffff0
//         00530235     PUSH       0x3
//         00530237     MOV        this,dword ptr [EAX + 0x34]
//         0053023a     CALL       RGE_Victory_Conditions::add_points_highest_att   uchar add_points_highest_attribute(RGE_Victor
//                              tworld.cpp:1112 (24)
//         0053023f     MOV        this,dword ptr [EBP + 0x40]
//         00530242     PUSH       0x19
//         00530244     PUSH       offset DAT_fffffff8
//         00530246     PUSH       offset DAT_fffffff4
//         00530248     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         0053024b     PUSH       offset DAT_fffffff0
//         0053024d     PUSH       0x3
//         0053024f     MOV        this,dword ptr [EDX + 0x34]
//         00530252     CALL       RGE_Victory_Conditions::add_points_attribute_f   uchar add_points_attribute_first(RGE_Victory_
//                              tworld.cpp:1114 (24)
//         00530257     MOV        EAX,dword ptr [EBP + 0x40]
//         0053025a     PUSH       0x19
//         0053025c     PUSH       offset DAT_fffffff8
//         0053025e     PUSH       offset DAT_fffffff4
//         00530260     MOV        this,dword ptr [EAX + ESI*0x4]
//         00530263     PUSH       offset DAT_fffffff0
//         00530265     PUSH       0x3
//         00530267     MOV        this,dword ptr [ECX + this->_padding_]
//         0053026a     CALL       RGE_Victory_Conditions::add_points_attribute_f   uchar add_points_attribute_first(RGE_Victory_
//                              tworld.cpp:1117 (23)
//         0053026f     MOV        EDX,dword ptr [EBP + 0x40]
//         00530272     PUSH       0x64
//         00530274     PUSH       EBX=>DAT_fffffff8
//         00530275     PUSH       offset DAT_fffffff4
//         00530277     MOV        EAX,dword ptr [EDX + ESI*0x4]
//         0053027a     PUSH       offset DAT_fffffff0
//         0053027c     PUSH       0x4
//         0053027e     MOV        this,dword ptr [EAX + 0x34]
//         00530281     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1119 (23)
//         00530286     MOV        this,dword ptr [EBP + 0x40]
//         00530289     PUSH       0x64
//         0053028b     PUSH       EBX=>DAT_fffffff8
//         0053028c     PUSH       offset DAT_fffffff4
//         0053028e     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         00530291     PUSH       offset DAT_fffffff0
//         00530293     PUSH       0x4
//         00530295     MOV        this,dword ptr [EDX + 0x34]
//         00530298     CALL       RGE_Victory_Conditions::add_points_attribute_a   uchar add_points_attribute_amount(RGE_Victory
//                              tworld.cpp:1121 (24)
//         0053029d     MOV        EAX,dword ptr [EBP + 0x40]
//         005302a0     MOV        this,dword ptr [EAX + ESI*0x4]
//         005302a3     CALL       TRIBE_Player::add_population_entry               void add_population_entry(TRIBE_Player * this)
//         005302a8     MOVSX      this,word ptr [EBP + 0x3c]
//         005302ac     INC        ESI
//         005302ad     CMP        ESI,this
//         005302af     JL         LAB_00530029
//                               LAB_005302b5                                                 XREF[5]:     0052ff7b(j), 0052ffcb(j),
//                                                                                                         0052ffea(j), 0053001a(j),
//                                                                                                         00530023(j)
//                              tworld.cpp:1128 (187)
//         005302b5     MOV        this,dword ptr [ESP + 0x1318]
//         005302bc     MOV        AL,byte ptr [ESP + 0x17]
//         005302c0     POP        EDI
//         005302c1     POP        ESI
//         005302c2     POP        EBP
//         005302c3     MOV        dword ptr FS:[0x0],this
//         005302ca     POP        EBX
//         005302cb     ADD        ESP,0x1314
//         005302d1     RET        0x8
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052f009::switchdataD_005302d4                       XREF[1]:     new_game:0052f009(*)
//         005302d4     addr       switchD_0052f009::caseD_0
//         005302d8     addr       switchD_0052f009::caseD_1
//         005302dc     addr       switchD_0052f009::caseD_2
//         005302e0     addr       switchD_0052f009::caseD_2
//         005302e4     addr       switchD_0052f009::caseD_2
//         005302e8     addr       switchD_0052f009::caseD_2
//         005302ec     addr       switchD_0052f009::caseD_2
//         005302f0     addr       switchD_0052f009::caseD_7
//         005302f4     addr       switchD_0052f009::caseD_8
//         005302f8     addr       switchD_0052f009::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052f095::switchdataD_005302fc                       XREF[1]:     new_game:0052f095(*)
//         005302fc     addr       switchD_0052f095::caseD_0
//         00530300     addr       switchD_0052f095::caseD_1
//         00530304     addr       switchD_0052f095::caseD_2
//         00530308     addr       switchD_0052f095::caseD_3
//         0053030c     addr       switchD_0052f095::caseD_4
//         00530310     addr       switchD_0052f095::caseD_5
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052f18f::switchdataD_00530314                       XREF[1]:     new_game:0052f18f(*)
//         00530314     addr       switchD_0052f18f::caseD_0
//         00530318     addr       switchD_0052f18f::caseD_1
//         0053031c     addr       switchD_0052f18f::caseD_2
//         00530320     addr       switchD_0052f18f::caseD_3
//         00530324     addr       switchD_0052f18f::caseD_4
//         00530328     addr       switchD_0052f18f::caseD_5
//         0053032c     addr       switchD_0052f18f::caseD_6
//         00530330     addr       switchD_0052f18f::caseD_7
//         00530334     addr       switchD_0052f18f::caseD_8
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052f81b::switchdataD_00530338                       XREF[1]:     new_game:0052f81b(*)
//         00530338     addr       switchD_0052f81b::caseD_0
//         0053033c     addr       switchD_0052f81b::caseD_1
//         00530340     addr       switchD_0052f81b::caseD_2
//         00530344     addr       switchD_0052f81b::caseD_3
//         00530348     addr       switchD_0052f81b::caseD_4
//         0053034c     addr       switchD_0052f81b::caseD_5
//         00530350     addr       switchD_0052f81b::caseD_6
//         00530354     addr       switchD_0052f81b::caseD_7
//         00530358     addr       switchD_0052f81b::caseD_8
//         0053035c     addr       switchD_0052f81b::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052f93f::switchdataD_00530360                       XREF[1]:     new_game:0052f93f(*)
//         00530360     addr       switchD_0052f93f::caseD_0
//         00530364     addr       switchD_0052f93f::caseD_1
//         00530368     addr       switchD_0052f93f::caseD_2
//         0053036c     addr       switchD_0052f93f::caseD_3
    return 0;
}

uchar TRIBE_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    /* TODO: Stub */
//                              uchar __thiscall new_scenario(TRIBE_World * this, RGE_Player_Info *
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[1]:     00530378(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00530370(R)
//                               ?new_scenario@TRIBE_World@@UAEEAAURGE_Player_Info@@H@Z       XREF[1]:     0057752c(*)
//                               TRIBE_World::new_scenario
//                              tworld.cpp:1132 (20)
//         00530370     MOV        EAX,dword ptr [ESP + param_2]
//         00530374     PUSH       ESI
//         00530375     MOV        ESI,this
//         00530377     PUSH       EAX
//         00530378     MOV        this,dword ptr [ESP + param_1]
//         0053037c     PUSH       this
//         0053037d     MOV        this,ESI
//         0053037f     CALL       RGE_Game_World::new_scenario                     uchar new_scenario(RGE_Game_World * this, RGE
//                              tworld.cpp:1138 (14)
//         00530384     MOV        this,0x1
//         00530389     CMP        word ptr [ESI + 0x3c],this
//         0053038d     JLE        LAB_005303de
//         0053038f     PUSH       EDI
//         00530390     PUSH       EBP
//         00530391     PUSH       EBX
//                              tworld.cpp:1143 (76)
//         00530392     MOV        EBX,0x43480000
//         00530397     XOR        EDI,EDI
//         00530399     MOV        EDX,0x42c80000
//                               LAB_0053039e                                                 XREF[1]:     005303d9(j)
//         0053039e     MOV        EBP,dword ptr [ESI + 0x40]
//         005303a1     INC        this
//         005303a2     MOV        EBP,dword ptr [EBP + this->_padding_*0x4 + -0x4]
//         005303a6     MOV        EBP,dword ptr [EBP + 0x50]
//         005303a9     MOV        dword ptr [EBP],EBX
//         005303ac     MOV        EBP,dword ptr [ESI + 0x40]
//         005303af     MOV        EBP,dword ptr [EBP + this->_padding_*0x4 + -0x4]
//         005303b3     MOV        EBP,dword ptr [EBP + 0x50]
//         005303b6     MOV        dword ptr [EBP + 0x4],EBX
//         005303b9     MOV        EBP,dword ptr [ESI + 0x40]
//         005303bc     MOV        EBP,dword ptr [EBP + this->_padding_*0x4 + -0x4]
//         005303c0     MOV        EBP,dword ptr [EBP + 0x50]
//         005303c3     MOV        dword ptr [EBP + 0xc],EDI
//         005303c6     MOV        EBP,dword ptr [ESI + 0x40]
//         005303c9     MOV        EBP,dword ptr [EBP + this->_padding_*0x4 + -0x4]
//         005303cd     MOV        EBP,dword ptr [EBP + 0x50]
//         005303d0     MOV        dword ptr [EBP + 0x8],EDX
//         005303d3     MOVSX      EBP,word ptr [ESI + 0x3c]
//         005303d7     CMP        this,EBP
//         005303d9     JL         LAB_0053039e
//         005303db     POP        EBX
//         005303dc     POP        EBP
//         005303dd     POP        EDI
//                               LAB_005303de                                                 XREF[1]:     0053038d(j)
//                              tworld.cpp:1147 (4)
//         005303de     POP        ESI
//         005303df     RET        0x8
//         005303e2     ??         90h
//         005303e3     NOP
//         005303e4     NOP
//         005303e5     NOP
//         005303e6     NOP
//         005303e7     NOP
//         005303e8     NOP
//         005303e9     NOP
//         005303ea     NOP
//         005303eb     NOP
//         005303ec     NOP
//         005303ed     NOP
//         005303ee     NOP
//         005303ef     NOP
    return 0;
}

uchar TRIBE_World::check_game_state() {
    /* TODO: Stub */
//                              uchar __thiscall check_game_state(TRIBE_World * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              TRIBE_Player *    Stack[-0x148   team_player               XREF[0,10]:  005306c5(*), 005306eb(*), 00530714(*), 00530739(*),
//                                                                                     00530767(*), 0053088f(*), 005307c8(*), 005307ee(*),
//                                                                                     00530804(*), 0053082e(*)
//              int[9]            Stack[-0x16c   player_team               XREF[0,6]:   0053058a(*), 005305b5(*), 005305b9(*), 005305d2(*),
//                                                                                     0053060d(*), 0053065f(*)
//              int[9]            Stack[-0x190   team_size                 XREF[2,17]:  005306d5(W), 0053089f(W), 00530473(*), 0053057f(*),
//                                                                                     005305b1(*), 005305d7(*), 005305ec(*), 00530669(*),
//                                                                                     005306c9(*), 005306df(*), 00530893(*), 005308a9(*),
//                                                                                     00530482(*), 00530494(*), 005304f2(*), 005304fb(*),
//                                                                                     0053050a(*), 00530518(*), 00530532(*)
//              undefined4        Stack[-0x194   local_194                 XREF[2]:     00530401(W), 00530700(R)
//              undefined4        Stack[-0x198   local_198                 XREF[7]:     0053059f(W), 005305c6(R), 00530657(R), 0053067f(R),
//                                                                                     0053068f(W), 005306ab(R), 00530883(R)
//              int               Stack[-0x19c   team_count                XREF[8]:     005305ad(W), 005305ce(R), 00530683(R), 00530693(W),
//                                                                                     005306d1(W), 005306d9(R), 0053089b(W), 005308a3(R)
//              undefined4        Stack[-0x1a0   local_1a0                 XREF[9]:     005305f9(W), 00530609(R), 00530626(R), 0053063e(R),
//                                                                                     00530653(R), 0053066e(R), 00530679(W), 0053071c(W),
//                                                                                     00530720(R)
//              float             Stack[-0x1a4   held_time                 XREF[15]:    00530496(W), 005304f6(R), 005304fd(W), 0053050d(R),
//                                                                                     005305a3(W), 005305ca(R), 0053062a(R), 00530642(R),
//                                                                                     00530687(R), 005306a1(W), 005306cd(W), 005306e5(R),
//                                                                                     00530704(R), 00530897(W), 005308af(R)
//              int               Stack[-0x1a8   i
//                               ?check_game_state@TRIBE_World@@UAEEXZ                        XREF[1]:     0057751c(*)
//                               TRIBE_World::check_game_state
//                              tworld.cpp:1151 (11)
//         005303f0     SUB        ESP,0x1a4
//         005303f6     PUSH       EBX
//         005303f7     MOV        EBX,this
//         005303f9     PUSH       EBP
//         005303fa     PUSH       ESI
//                              tworld.cpp:1152 (16)
//         005303fb     MOV        AL,byte ptr [EBX + 0x1d]
//         005303fe     PUSH       EDI
//         005303ff     TEST       AL,AL
//         00530401     MOV        dword ptr [ESP + local_194],EBX
//         00530405     JNZ        LAB_00530a53
//                              tworld.cpp:1156 (27)
//         0053040b     CMP        dword ptr [EBX + 0x108],0x2
//         00530412     JNZ        LAB_00530554
//         00530418     MOV        AL,byte ptr [EBX + 0x114]
//         0053041e     TEST       AL,AL
//         00530420     JZ         LAB_00530554
//                              tworld.cpp:1158 (23)
//         00530426     FLD        float ptr [EBX + 0x118]
//         0053042c     FCOMP      float ptr [DAT_00577578]
//         00530432     FNSTSW     AX
//         00530434     TEST       AH,0x1
//         00530437     JNZ        LAB_00530554
//                              tworld.cpp:1160 (14)
//         0053043d     FLD        float ptr [EBX + 0x84]
//         00530443     FADD       ST0,ST0
//         00530445     FSUBR      float ptr [EBX + 0x118]
//                              tworld.cpp:1161 (23)
//         0053044b     FCOM       float ptr [DAT_00577578]
//         00530451     FSTP       float ptr [EBX + 0x118]
//         00530457     FNSTSW     AX
//         00530459     TEST       AH,0x1
//         0053045c     JZ         LAB_00530554
//                              tworld.cpp:1172 (29)
//         00530462     MOV        EBP,0x1
//         00530467     MOV        this,0x9
//         0053046c     OR         EAX,0xffffffff
//         0053046f     CMP        word ptr [EBX + 0x3c],BP
//         00530473     LEA        EDI=>team_size[1],[ESP + 0x28]
//         00530477     STOSD.REP  ES:EDI
//         00530479     JLE        LAB_00530520
//                               LAB_0053047f                                                 XREF[1]:     0053051a(j)
//                              tworld.cpp:1174 (18)
//         0053047f     MOV        EAX,dword ptr [EBX + 0x40]
//         00530482     LEA        EDI=>team_size[2],[ESP + EBP*0x4 + 0x28]
//         00530486     MOV        this,dword ptr [EAX + EBP*0x4]
//         00530489     MOV        this,dword ptr [ECX + this->_padding_]
//         0053048c     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
//                              tworld.cpp:1176 (26)
//         00530491     MOV        EDX,dword ptr [EBX + 0x40]
//         00530494     MOV        dword ptr [EDI]=>team_size[2],EAX
//         00530496     MOV        dword ptr [ESP + held_time],0x1
//         0053049e     MOV        EAX,dword ptr [EDX + EBP*0x4]
//         005304a1     MOV        this,byte ptr [EAX + 0x104]
//         005304a7     TEST       this,this
//         005304a9     JZ         LAB_0053050a
//                              tworld.cpp:1178 (11)
//         005304ab     MOV        ESI,0x1
//         005304b0     CMP        word ptr [EBX + 0x3c],SI
//         005304b4     JLE        LAB_0053050a
//                               LAB_005304b6                                                 XREF[1]:     00530508(j)
//                              tworld.cpp:1180 (4)
//         005304b6     CMP        ESI,EBP
//         005304b8     JZ         LAB_00530501
//                              tworld.cpp:1182 (48)
//         005304ba     MOV        this,dword ptr [EBX + 0x40]
//         005304bd     PUSH       ESI
//         005304be     MOV        this,dword ptr [this->_padding_ + EBP*0x4]
//         005304c1     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         005304c6     TEST       AL,AL
//         005304c8     JNZ        LAB_00530501
//         005304ca     MOV        EDX,dword ptr [EBX + 0x40]
//         005304cd     PUSH       EBP
//         005304ce     MOV        this,dword ptr [EDX + ESI*0x4]
//         005304d1     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         005304d6     TEST       AL,AL
//         005304d8     JNZ        LAB_00530501
//         005304da     MOV        EAX,dword ptr [EBX + 0x40]
//         005304dd     MOV        EAX,dword ptr [EAX + ESI*0x4]
//         005304e0     MOV        this,byte ptr [EAX + 0x104]
//         005304e6     TEST       this,this
//         005304e8     JZ         LAB_00530501
//                              tworld.cpp:1184 (12)
//         005304ea     MOV        this,dword ptr [EAX + 0x34]
//         005304ed     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
//         005304f2     MOV        this,dword ptr [EDI]=>team_size[2]
//         005304f4     ADD        this,EAX
//                              tworld.cpp:1185 (20)
//         005304f6     MOV        EAX,dword ptr [ESP + held_time]
//         005304fa     INC        EAX
//         005304fb     MOV        dword ptr [EDI]=>team_size[2],this
//         005304fd     MOV        dword ptr [ESP + held_time],EAX
//                               LAB_00530501                                                 XREF[4]:     005304b8(j), 005304c8(j),
//                                                                                                         005304d8(j), 005304e8(j)
//         00530501     MOVSX      this,word ptr [EBX + 0x3c]
//         00530505     INC        ESI
//         00530506     CMP        ESI,this
//         00530508     JL         LAB_005304b6
//                               LAB_0053050a                                                 XREF[2]:     005304a9(j), 005304b4(j)
//                              tworld.cpp:1190 (22)
//         0053050a     MOV        EAX,dword ptr [EDI]=>team_size[2]
//         0053050c     CDQ
//         0053050d     IDIV       dword ptr [ESP + held_time]
//         00530511     MOVSX      EDX,word ptr [EBX + 0x3c]
//         00530515     INC        EBP
//         00530516     CMP        EBP,EDX
//         00530518     MOV        dword ptr [EDI]=>team_size[2],EAX
//         0053051a     JL         LAB_0053047f
//                               LAB_00530520                                                 XREF[1]:     00530479(j)
//                              tworld.cpp:1195 (18)
//         00530520     MOVSX      EDI,word ptr [EBX + 0x3c]
//         00530524     MOV        ESI,0x1
//         00530529     XOR        this,this
//         0053052b     OR         EDX,0xffffffff
//         0053052e     CMP        EDI,ESI
//         00530530     JLE        LAB_00530547
//                               LAB_00530532                                                 XREF[1]:     00530545(j)
//                              tworld.cpp:1197 (8)
//         00530532     MOV        EAX,dword ptr [ESP + ESI*0x4 + team_size[2]]
//         00530536     CMP        EAX,EDX
//         00530538     JLE        LAB_00530542
//                              tworld.cpp:1199 (3)
//         0053053a     MOV        this,dword ptr [EBX + 0x40]
//                              tworld.cpp:1200 (10)
//         0053053d     MOV        EDX,EAX
//         0053053f     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//                               LAB_00530542                                                 XREF[1]:     00530538(j)
//         00530542     INC        ESI
//         00530543     CMP        ESI,EDI
//         00530545     JL         LAB_00530532
//                               LAB_00530547                                                 XREF[1]:     00530530(j)
//                              tworld.cpp:1204 (4)
//         00530547     TEST       this,this
//         00530549     JZ         LAB_00530554
//                              tworld.cpp:1206 (5)
//         0053054b     CALL       RGE_Player::win_game_now                         void win_game_now(RGE_Player * this)
//                              tworld.cpp:1207 (4)
//         00530550     MOV        byte ptr [EBX + 0x1e],0x67
//                               LAB_00530554                                                 XREF[5]:     00530412(j), 00530420(j),
//                                                                                                         00530437(j), 0053045c(j),
//                                                                                                         00530549(j)
//                              tworld.cpp:1216 (24)
//         00530554     MOV        EAX,dword ptr [EBX + 0x10c]
//         0053055a     TEST       EAX,EAX
//         0053055c     JG         LAB_0053056c
//         0053055e     MOV        EAX,dword ptr [EBX + 0x110]
//         00530564     TEST       EAX,EAX
//         00530566     JLE        LAB_00530a53
//                               LAB_0053056c                                                 XREF[1]:     0053055c(j)
//                              tworld.cpp:1227 (17)
//         0053056c     MOVSX      EDX,word ptr [EBX + 0x3c]
//         00530570     TEST       EDX,EDX
//         00530572     JLE        LAB_00530596
//         00530574     LEA        ESI,[EDX*0x4 + 0x0]
//         0053057b     XOR        EAX,EAX
//                              tworld.cpp:1371 (258)
//         0053057d     MOV        this,ESI
//         0053057f     LEA        EDI=>team_size[1],[ESP + 0x28]
//         00530583     SHR        this,0x2
//         00530586     STOSD.REP  ES:EDI
//         00530588     MOV        this,ESI
//         0053058a     LEA        EDI=>player_team[1],[ESP + 0x4c]
//         0053058e     SHR        this,0x2
//         00530591     OR         EAX,0xffffffff
//         00530594     STOSD.REP  ES:EDI
//                               LAB_00530596                                                 XREF[1]:     00530572(j)
//         00530596     MOV        EAX,0x1
//         0053059b     XOR        this,this
//         0053059d     CMP        EDX,EAX
//         0053059f     MOV        dword ptr [ESP + local_198],this
//         005305a3     MOV        dword ptr [ESP + held_time],EAX
//         005305a7     JLE        LAB_005306af
//         005305ad     MOV        dword ptr [ESP + team_count],this
//         005305b1     LEA        EDI=>team_size[1],[ESP + 0x28]
//                               LAB_005305b5                                                 XREF[1]:     005306a5(j)
//         005305b5     MOV        ESI,dword ptr [ESP + EAX*0x4 + player_team[2]]
//         005305b9     LEA        this=>player_team[2],[ESP + EAX*0x4 + 0x4c]
//         005305bd     CMP        ESI,-0x1
//         005305c0     JNZ        LAB_0053069a
//         005305c6     MOV        EAX,dword ptr [ESP + local_198]
//         005305ca     MOV        ESI,dword ptr [ESP + held_time]
//         005305ce     MOV        EBP,dword ptr [ESP + team_count]
//         005305d2     MOV        dword ptr [this->_padding_]=>player_team[2],EAX
//         005305d4     MOV        this,dword ptr [EBX + 0x40]
//         005305d7     MOV        EAX,dword ptr [EDI]=>team_size[1]
//         005305d9     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         005305dc     LEA        ESI,[EAX + EBP*0x1]
//         005305df     MOV        dword ptr [ESP + ESI*0x4 + 0x70],this
//         005305e3     LEA        ESI,[EAX + 0x1]
//         005305e6     MOV        AL,byte ptr [ECX + this->tech]
//         005305ec     MOV        dword ptr [EDI]=>team_size[1],ESI
//         005305ee     TEST       AL,AL
//         005305f0     JZ         LAB_0053067f
//         005305f6     CMP        EDX,0x1
//         005305f9     MOV        dword ptr [ESP + local_1a0],0x1
//         00530601     JLE        LAB_0053067f
//         00530603     ADD        EBP,ESI
//         00530605     LEA        EBP,[ESP + EBP*0x4 + 0x70]
//                               LAB_00530609                                                 XREF[1]:     0053067d(j)
//         00530609     MOV        EDX,dword ptr [ESP + local_1a0]
//         0053060d     CMP        dword ptr [ESP + EDX*0x4 + player_team[2]],-0x1
//         00530612     JNZ        LAB_0053066e
//         00530614     MOV        EAX,dword ptr [EBX + 0x40]
//         00530617     MOV        this,EDX
//         00530619     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//         0053061c     MOV        this,byte ptr [EDX + 0x104]
//         00530622     TEST       this,this
//         00530624     JZ         LAB_0053066e
//         00530626     MOV        this,dword ptr [ESP + local_1a0]
//         0053062a     MOV        EDX,dword ptr [ESP + held_time]
//         0053062e     PUSH       this
//         0053062f     MOV        this,dword ptr [EAX + EDX*0x4]
//         00530632     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         00530637     TEST       AL,AL
//         00530639     JNZ        LAB_0053066e
//         0053063b     MOV        this,dword ptr [EBX + 0x40]
//         0053063e     MOV        EDX,dword ptr [ESP + local_1a0]
//         00530642     MOV        EAX,dword ptr [ESP + held_time]
//         00530646     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
//         00530649     PUSH       EAX
//         0053064a     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         0053064f     TEST       AL,AL
//         00530651     JNZ        LAB_0053066e
//         00530653     MOV        EAX,dword ptr [ESP + local_1a0]
//         00530657     MOV        this,dword ptr [ESP + local_198]
//         0053065b     MOV        EDX,dword ptr [EBX + 0x40]
//         0053065e     INC        ESI
//         0053065f     MOV        dword ptr [ESP + EAX*0x4 + player_team[2]],this
//         00530663     ADD        EBP,0x4
//         00530666     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         00530669     MOV        dword ptr [EDI]=>team_size[1],ESI
//         0053066b     MOV        dword ptr [EBP + -0x4],EAX
//                               LAB_0053066e                                                 XREF[4]:     00530612(j), 00530624(j),
//                                                                                                         00530639(j), 00530651(j)
//         0053066e     MOV        EAX,dword ptr [ESP + local_1a0]
//         00530672     MOVSX      this,word ptr [EBX + 0x3c]
//         00530676     INC        EAX
//         00530677     CMP        EAX,this
//         00530679     MOV        dword ptr [ESP + local_1a0],EAX
//         0053067d     JL         LAB_00530609
//                               LAB_0053067f                                                 XREF[2]:     005305f0(j), 00530601(j)
//                              tworld.cpp:1258 (44)
//         0053067f     MOV        EDX,dword ptr [ESP + local_198]
//         00530683     MOV        this,dword ptr [ESP + team_count]
//         00530687     MOV        EAX,dword ptr [ESP + held_time]
//         0053068b     INC        EDX
//         0053068c     ADD        this,0x9
//         0053068f     MOV        dword ptr [ESP + local_198],EDX
//         00530693     MOV        dword ptr [ESP + team_count],this
//         00530697     ADD        EDI,0x4
//                               LAB_0053069a                                                 XREF[1]:     005305c0(j)
//         0053069a     MOVSX      EDX,word ptr [EBX + 0x3c]
//         0053069e     INC        EAX
//         0053069f     CMP        EAX,EDX
//         005306a1     MOV        dword ptr [ESP + held_time],EAX
//         005306a5     JL         LAB_005305b5
//                              tworld.cpp:1235 (4)
//         005306ab     MOV        this,dword ptr [ESP + local_198]
//                               LAB_005306af                                                 XREF[1]:     005305a7(j)
//                              tworld.cpp:1263 (14)
//         005306af     MOV        EAX,dword ptr [EBX + 0x10c]
//         005306b5     TEST       EAX,EAX
//         005306b7     JLE        LAB_00530875
//                              tworld.cpp:1265 (8)
//         005306bd     TEST       this,this
//         005306bf     JLE        LAB_00530875
//                              tworld.cpp:1371 (108)
//         005306c5     LEA        EDI=>team_player[0][1],[ESP + 0x70]
//         005306c9     LEA        EDX=>team_size[1],[ESP + 0x28]
//         005306cd     MOV        dword ptr [ESP + held_time],EDI
//         005306d1     MOV        dword ptr [ESP + team_count],EDX
//         005306d5     MOV        dword ptr [ESP + team_size[0]],this
//                               LAB_005306d9                                                 XREF[1]:     0053086f(j)
//         005306d9     MOV        EAX,dword ptr [ESP + team_count]
//         005306dd     XOR        EBP,EBP
//         005306df     MOV        ESI,dword ptr [EAX]=>team_size[1]
//         005306e1     TEST       ESI,ESI
//         005306e3     JLE        LAB_00530708
//         005306e5     MOV        EDI,dword ptr [ESP + held_time]
//         005306e9     MOV        EBX,ESI
//                               LAB_005306eb                                                 XREF[1]:     005306fe(j)
//         005306eb     MOV        this,dword ptr [EDI]=>team_player[0][1]
//         005306ed     MOV        EDX,dword ptr [ECX + this->_padding_]
//         005306f0     FLD        float ptr [EDX + 0x1c]
//         005306f3     CALL       __ftol                                           undefined __ftol()
//         005306f8     ADD        EBP,EAX
//         005306fa     ADD        EDI,0x4
//         005306fd     DEC        EBX
//         005306fe     JNZ        LAB_005306eb
//         00530700     MOV        EBX,dword ptr [ESP + local_194]
//         00530704     MOV        EDI,dword ptr [ESP + held_time]
//                               LAB_00530708                                                 XREF[1]:     005306e3(j)
//         00530708     CMP        EBP,dword ptr [EBX + 0x10c]
//         0053070e     JNZ        LAB_005307ee
//         00530714     MOV        this,dword ptr [EDI]=>team_player[0][1]
//         00530716     MOV        EAX,dword ptr [this->_padding_ + 0x844]
//         0053071c     MOV        dword ptr [ESP + local_1a0],EAX
//         00530720     FLD        float ptr [ESP + local_1a0]
//         00530724     FCOMP      float ptr [DAT_00577580]
//         0053072a     FNSTSW     AX
//         0053072c     TEST       AH,0x40
//         0053072f     JZ         LAB_00530793
//                              tworld.cpp:1275 (4)
//         00530731     TEST       ESI,ESI
//         00530733     JLE        LAB_0053074e
//                              tworld.cpp:1371 (25)
//         00530735     MOV        EAX,EDI
//         00530737     MOV        EDX,ESI
//                               LAB_00530739                                                 XREF[1]:     0053074c(j)
//         00530739     MOV        EBP,dword ptr [EAX]=>team_player[0][1]
//         0053073b     ADD        EAX,0x4
//         0053073e     DEC        EDX
//         0053073f     MOV        EBP,dword ptr [EBP + 0x50]
//         00530742     MOV        dword ptr [EBP + 0xdc],0x3f800000
//         0053074c     JNZ        LAB_00530739
//                               LAB_0053074e                                                 XREF[1]:     00530733(j)
//                              tworld.cpp:1278 (14)
//         0053074e     MOV        EAX,dword ptr [EBX + 0x108]
//         00530754     TEST       EAX,EAX
//         00530756     JNZ        LAB_00530854
//                              tworld.cpp:1280 (4)
//         0053075c     TEST       ESI,ESI
//         0053075e     JLE        LAB_00530775
//                              tworld.cpp:1371 (21)
//         00530760     MOV        EAX,EDI
//         00530762     MOV        EDX,0x44fa0000
//                               LAB_00530767                                                 XREF[1]:     00530773(j)
//         00530767     MOV        EBP,dword ptr [EAX]=>team_player[0][1]
//         00530769     ADD        EAX,0x4
//         0053076c     DEC        ESI
//         0053076d     MOV        dword ptr [EBP + 0x844],EDX
//         00530773     JNZ        LAB_00530767
//                               LAB_00530775                                                 XREF[1]:     0053075e(j)
//                              tworld.cpp:1282 (25)
//         00530775     MOVSX      this,word ptr [ECX + this+0x4a]
//         00530779     MOV        EAX,[rge_base_game]                              = 00000000
//         0053077e     PUSH       0x0
//         00530780     PUSH       0x0
//         00530782     PUSH       0x0
//         00530784     MOV        EDX,dword ptr [EAX]
//         00530786     PUSH       this
//                              language.dll match for 0x72: "21"
//         00530787     PUSH       0x72
//         00530789     MOV        this,EAX
//         0053078b     CALL       dword ptr [EDX + 0x40]
//                              tworld.cpp:1285 (26)
//         0053078e     JMP        LAB_00530854
//                               LAB_00530793                                                 XREF[1]:     0053072f(j)
//         00530793     FLD        float ptr [ESP + 0x14]
//         00530797     FCOMP      float ptr [DAT_00577578]
//         0053079d     FNSTSW     AX
//         0053079f     TEST       AH,0x1
//         005307a2     JNZ        LAB_00530854
//                              tworld.cpp:1287 (14)
//         005307a8     MOV        EAX,dword ptr [EBX + 0x108]
//         005307ae     TEST       EAX,EAX
//         005307b0     JNZ        LAB_00530854
//                              tworld.cpp:1289 (8)
//         005307b6     FLD        float ptr [EBX + 0x84]
//         005307bc     FADD       ST0,ST0
//                              tworld.cpp:1290 (8)
//         005307be     TEST       ESI,ESI
//         005307c0     FSUBR      float ptr [ESP + 0x14]
//         005307c4     JLE        LAB_005307d6
//                              tworld.cpp:1371 (2)
//         005307c6     MOV        EAX,EDI
//                               LAB_005307c8                                                 XREF[1]:     005307d4(j)
//                              tworld.cpp:1291 (14)
//         005307c8     MOV        EDX,dword ptr [EAX]=>team_player[1][1]
//         005307ca     ADD        EAX,0x4
//         005307cd     DEC        ESI
//         005307ce     FST        float ptr [EDX + 0x844]
//         005307d4     JNZ        LAB_005307c8
//                               LAB_005307d6                                                 XREF[1]:     005307c4(j)
//                              tworld.cpp:1292 (13)
//         005307d6     FCOMP      float ptr [DAT_00577578]
//         005307dc     FNSTSW     AX
//         005307de     TEST       AH,0x1
//         005307e1     JZ         LAB_00530854
//                              tworld.cpp:1294 (5)
//         005307e3     CALL       RGE_Player::win_game_now                         void win_game_now(RGE_Player * this)
//                              tworld.cpp:1295 (4)
//         005307e8     MOV        byte ptr [EBX + 0x1e],0x65
//                              tworld.cpp:1300 (16)
//         005307ec     JMP        LAB_00530854
//                               LAB_005307ee                                                 XREF[1]:     0053070e(j)
//         005307ee     MOV        EDX,dword ptr [EDI]=>team_player[1][1]
//         005307f0     CMP        dword ptr [EDX + 0x844],0xbf800000
//         005307fa     JZ         LAB_00530854
//                              tworld.cpp:1302 (4)
//         005307fc     TEST       ESI,ESI
//         005307fe     JLE        LAB_00530819
//                              tworld.cpp:1371 (25)
//         00530800     MOV        EAX,EDI
//         00530802     MOV        this,ESI
//                               LAB_00530804                                                 XREF[1]:     00530817(j)
//         00530804     MOV        EBP,dword ptr [EAX]=>team_player[1][1]
//         00530806     ADD        EAX,0x4
//         00530809     DEC        this
//         0053080a     MOV        EBP,dword ptr [EBP + 0x50]
//         0053080d     MOV        dword ptr [EBP + 0xdc],0x0
//         00530817     JNZ        LAB_00530804
//                               LAB_00530819                                                 XREF[1]:     005307fe(j)
//                              tworld.cpp:1305 (10)
//         00530819     MOV        EAX,dword ptr [EBX + 0x108]
//         0053081f     TEST       EAX,EAX
//         00530821     JNZ        LAB_00530854
//                              tworld.cpp:1307 (4)
//         00530823     TEST       ESI,ESI
//         00530825     JLE        LAB_0053083c
//                              tworld.cpp:1371 (21)
//         00530827     MOV        EAX,EDI
//         00530829     MOV        this,0xbf800000
//                               LAB_0053082e                                                 XREF[1]:     0053083a(j)
//         0053082e     MOV        EBP,dword ptr [EAX]=>team_player[1][1]
//         00530830     ADD        EAX,0x4
//         00530833     DEC        ESI
//         00530834     MOV        dword ptr [EBP + 0x844],this
//         0053083a     JNZ        LAB_0053082e
//                               LAB_0053083c                                                 XREF[1]:     00530825(j)
//                              tworld.cpp:1309 (57)
//         0053083c     MOVSX      EDX,word ptr [EDX + 0x4a]
//         00530840     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00530846     PUSH       0x0
//         00530848     PUSH       0x0=>DAT_fffffff8
//         0053084a     PUSH       0x0=>DAT_fffffff4
//         0053084c     MOV        EAX,dword ptr [this->_padding_]
//         0053084e     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x73: "B"
//         0053084f     PUSH       0x73
//         00530851     CALL       dword ptr [EAX + 0x40]
//                               LAB_00530854                                                 XREF[8]:     00530756(j), 0053078e(j),
//                                                                                                         005307a2(j), 005307b0(j),
//                                                                                                         005307e1(j), 005307ec(j),
//                                                                                                         005307fa(j), 00530821(j)
//         00530854     MOV        EDX,dword ptr [ESP + 0x18]
//         00530858     MOV        EAX,dword ptr [ESP + 0x24]
//         0053085c     ADD        EDX,0x4
//         0053085f     ADD        EDI,0x24
//         00530862     DEC        EAX
//         00530863     MOV        dword ptr [ESP + 0x18],EDX
//         00530867     MOV        dword ptr [ESP + 0x10],EDI
//         0053086b     MOV        dword ptr [ESP + 0x24],EAX
//         0053086f     JNZ        LAB_005306d9
//                               LAB_00530875                                                 XREF[2]:     005306b7(j), 005306bf(j)
//                              tworld.cpp:1316 (14)
//         00530875     MOV        EAX,dword ptr [EBX + 0x110]
//         0053087b     TEST       EAX,EAX
//         0053087d     JLE        LAB_00530a53
//                              tworld.cpp:1318 (12)
//         00530883     MOV        EAX,dword ptr [ESP + local_198]
//         00530887     TEST       EAX,EAX
//         00530889     JLE        LAB_00530a53
//                              tworld.cpp:1371 (74)
//         0053088f     LEA        EDI=>team_player[0][1],[ESP + 0x70]
//         00530893     LEA        this=>team_size[1],[ESP + 0x28]
//         00530897     MOV        dword ptr [ESP + held_time],EDI
//         0053089b     MOV        dword ptr [ESP + team_count],this
//         0053089f     MOV        dword ptr [ESP + team_size[0]],EAX
//                               LAB_005308a3                                                 XREF[1]:     00530a49(j)
//         005308a3     MOV        EDX,dword ptr [ESP + team_count]
//         005308a7     XOR        EBP,EBP
//         005308a9     MOV        ESI,dword ptr [EDX]=>team_size[1]
//         005308ab     TEST       ESI,ESI
//         005308ad     JLE        LAB_005308d9
//         005308af     MOV        EDI,dword ptr [ESP + held_time]
//         005308b3     MOV        EBX,ESI
//                               LAB_005308b5                                                 XREF[1]:     005308c8(j)
//         005308b5     MOV        EAX,dword ptr [EDI]
//         005308b7     MOV        this,dword ptr [EAX + 0x50]
//         005308ba     FLD        float ptr [ECX + this->_padding_]
//         005308bd     CALL       __ftol                                           undefined __ftol()
//         005308c2     ADD        EBP,EAX
//         005308c4     ADD        EDI,0x4
//         005308c7     DEC        EBX
//         005308c8     JNZ        LAB_005308b5
//         005308ca     MOV        EDI,dword ptr [ESP + 0x10]
//         005308ce     MOV        this,dword ptr [ESP + 0x20]
//         005308d2     MOV        EBX,0xbf800000
//         005308d7     JMP        LAB_005308e2
//                               LAB_005308d9                                                 XREF[1]:     005308ad(j)
//                              tworld.cpp:1321 (9)
//         005308d9     MOV        this,dword ptr [ESP + 0x20]
//         005308dd     MOV        EBX,0xbf800000
//                               LAB_005308e2                                                 XREF[1]:     005308d7(j)
//                              tworld.cpp:1323 (12)
//         005308e2     CMP        EBP,dword ptr [ECX + this->ruin_count]
//         005308e8     JNZ        LAB_005309cd
//                              tworld.cpp:1325 (12)
//         005308ee     MOV        EBX,dword ptr [EDI]
//         005308f0     MOV        EDX,dword ptr [EBX + 0x840]
//         005308f6     MOV        dword ptr [ESP + 0x14],EDX
//                              tworld.cpp:1326 (17)
//         005308fa     FLD        float ptr [ESP + 0x14]
//         005308fe     FCOMP      float ptr [DAT_00577580]
//         00530904     FNSTSW     AX
//         00530906     TEST       AH,0x40
//         00530909     JZ         LAB_0053096c
//                              tworld.cpp:1328 (4)
//         0053090b     TEST       ESI,ESI
//         0053090d     JLE        LAB_00530928
//                              tworld.cpp:1371 (25)
//         0053090f     MOV        EAX,EDI
//         00530911     MOV        EDX,ESI
//                               LAB_00530913                                                 XREF[1]:     00530926(j)
//         00530913     MOV        EBP,dword ptr [EAX]
//         00530915     ADD        EAX,0x4
//         00530918     DEC        EDX
//         00530919     MOV        EBP,dword ptr [EBP + 0x50]
//         0053091c     MOV        dword ptr [EBP + 0xd8],0x3f800000
//         00530926     JNZ        LAB_00530913
//                               LAB_00530928                                                 XREF[1]:     0053090d(j)
//                              tworld.cpp:1331 (14)
//         00530928     MOV        EAX,dword ptr [ECX + this->victory_type]
//         0053092e     TEST       EAX,EAX
//         00530930     JNZ        LAB_00530a2e
//                              tworld.cpp:1333 (4)
//         00530936     TEST       ESI,ESI
//         00530938     JLE        LAB_0053094e
//                              tworld.cpp:1371 (2)
//         0053093a     MOV        EAX,EDI
//                               LAB_0053093c                                                 XREF[1]:     0053094c(j)
//                              tworld.cpp:1334 (18)
//         0053093c     MOV        this,dword ptr [EAX]
//         0053093e     ADD        EAX,0x4
//         00530941     DEC        ESI
//         00530942     MOV        dword ptr [this->_padding_ + 0x840],0x44fa0000
//         0053094c     JNZ        LAB_0053093c
//                               LAB_0053094e                                                 XREF[1]:     00530938(j)
//                              tworld.cpp:1335 (25)
//         0053094e     MOVSX      this,word ptr [EBX + 0x4a]
//         00530952     MOV        EAX,[rge_base_game]                              = 00000000
//         00530957     PUSH       0x0
//         00530959     PUSH       0x0=>DAT_fffffff8
//         0053095b     PUSH       0x0=>DAT_fffffff4
//         0053095d     MOV        EDX,dword ptr [EAX]
//         0053095f     PUSH       this=>DAT_fffffff0
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         00530960     PUSH       0x74
//         00530962     MOV        this,EAX
//         00530964     CALL       dword ptr [EDX + 0x40]
//                              tworld.cpp:1338 (26)
//         00530967     JMP        LAB_00530a2e
//                               LAB_0053096c                                                 XREF[1]:     00530909(j)
//         0053096c     FLD        float ptr [ESP + 0x14]
//         00530970     FCOMP      float ptr [DAT_00577578]
//         00530976     FNSTSW     AX
//         00530978     TEST       AH,0x1
//         0053097b     JNZ        LAB_00530a2e
//                              tworld.cpp:1340 (14)
//         00530981     MOV        EAX,dword ptr [ECX + this->victory_type]
//         00530987     TEST       EAX,EAX
//         00530989     JNZ        LAB_00530a2e
//                              tworld.cpp:1342 (8)
//         0053098f     FLD        float ptr [ECX + this->_padding_]
//         00530995     FADD       ST0,ST0
//                              tworld.cpp:1343 (8)
//         00530997     TEST       ESI,ESI
//         00530999     FSUBR      float ptr [ESP + 0x14]
//         0053099d     JLE        LAB_005309af
//                              tworld.cpp:1371 (2)
//         0053099f     MOV        EAX,EDI
//                               LAB_005309a1                                                 XREF[1]:     005309ad(j)
//                              tworld.cpp:1344 (14)
//         005309a1     MOV        EDX,dword ptr [EAX]
//         005309a3     ADD        EAX,0x4
//         005309a6     DEC        ESI
//         005309a7     FST        float ptr [EDX + 0x840]
//         005309ad     JNZ        LAB_005309a1
//                               LAB_005309af                                                 XREF[1]:     0053099d(j)
//                              tworld.cpp:1345 (13)
//         005309af     FCOMP      float ptr [DAT_00577578]
//         005309b5     FNSTSW     AX
//         005309b7     TEST       AH,0x1
//         005309ba     JZ         LAB_00530a2e
//                              tworld.cpp:1347 (7)
//         005309bc     MOV        this,EBX
//         005309be     CALL       RGE_Player::win_game_now                         void win_game_now(RGE_Player * this)
//                              tworld.cpp:1348 (8)
//         005309c3     MOV        EAX,dword ptr [ESP + 0x20]
//         005309c7     MOV        byte ptr [EAX + 0x1e],0x66
//                              tworld.cpp:1353 (12)
//         005309cb     JMP        LAB_00530a2e
//                               LAB_005309cd                                                 XREF[1]:     005308e8(j)
//         005309cd     MOV        EDX,dword ptr [EDI]
//         005309cf     CMP        dword ptr [EDX + 0x840],EBX
//         005309d5     JZ         LAB_00530a2e
//                              tworld.cpp:1355 (4)
//         005309d7     TEST       ESI,ESI
//         005309d9     JLE        LAB_005309f4
//                              tworld.cpp:1371 (25)
//         005309db     MOV        EAX,EDI
//         005309dd     MOV        this,ESI
//                               LAB_005309df                                                 XREF[1]:     005309f2(j)
//         005309df     MOV        EBP,dword ptr [EAX]
//         005309e1     ADD        EAX,0x4
//         005309e4     DEC        this
//         005309e5     MOV        EBP,dword ptr [EBP + 0x50]
//         005309e8     MOV        dword ptr [EBP + 0xd8],0x0
//         005309f2     JNZ        LAB_005309df
//                               LAB_005309f4                                                 XREF[1]:     005309d9(j)
//                              tworld.cpp:1358 (14)
//         005309f4     MOV        this,dword ptr [ESP + 0x20]
//         005309f8     MOV        EAX,dword ptr [ECX + this->victory_type]
//         005309fe     TEST       EAX,EAX
//         00530a00     JNZ        LAB_00530a2e
//                              tworld.cpp:1360 (4)
//         00530a02     TEST       ESI,ESI
//         00530a04     JLE        LAB_00530a16
//                              tworld.cpp:1371 (2)
//         00530a06     MOV        EAX,EDI
//                               LAB_00530a08                                                 XREF[1]:     00530a14(j)
//                              tworld.cpp:1361 (14)
//         00530a08     MOV        this,dword ptr [EAX]
//         00530a0a     ADD        EAX,0x4
//         00530a0d     DEC        ESI
//         00530a0e     MOV        dword ptr [this->_padding_ + 0x840],EBX
//         00530a14     JNZ        LAB_00530a08
//                               LAB_00530a16                                                 XREF[1]:     00530a04(j)
//                              tworld.cpp:1362 (57)
//         00530a16     MOVSX      EDX,word ptr [EDX + 0x4a]
//         00530a1a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00530a20     PUSH       0x0
//         00530a22     PUSH       0x0=>DAT_fffffff8
//         00530a24     PUSH       0x0=>DAT_fffffff4
//         00530a26     MOV        EAX,dword ptr [this->_padding_]
//         00530a28     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x75: "12"
//         00530a29     PUSH       0x75
//         00530a2b     CALL       dword ptr [EAX + 0x40]
//                               LAB_00530a2e                                                 XREF[8]:     00530930(j), 00530967(j),
//                                                                                                         0053097b(j), 00530989(j),
//                                                                                                         005309ba(j), 005309cb(j),
//                                                                                                         005309d5(j), 00530a00(j)
//         00530a2e     MOV        EDX,dword ptr [ESP + 0x18]
//         00530a32     MOV        EAX,dword ptr [ESP + 0x24]
//         00530a36     ADD        EDX,0x4
//         00530a39     ADD        EDI,0x24
//         00530a3c     DEC        EAX
//         00530a3d     MOV        dword ptr [ESP + 0x18],EDX
//         00530a41     MOV        dword ptr [ESP + 0x10],EDI
//         00530a45     MOV        dword ptr [ESP + 0x24],EAX
//         00530a49     JNZ        LAB_005308a3
//                              tworld.cpp:1318 (4)
//         00530a4f     MOV        EBX,dword ptr [ESP + 0x20]
//                               LAB_00530a53                                                 XREF[4]:     00530405(j), 00530566(j),
//                                                                                                         0053087d(j), 00530889(j)
//                              tworld.cpp:1370 (7)
//         00530a53     MOV        this,EBX
//         00530a55     CALL       RGE_Game_World::check_game_state                 uchar check_game_state(RGE_Game_World * this)
//                              tworld.cpp:1371 (11)
//         00530a5a     POP        EDI
//         00530a5b     POP        ESI
//         00530a5c     POP        EBP
//         00530a5d     POP        EBX
//         00530a5e     ADD        ESP,0x1a4
//         00530a64     RET
//         00530a65     ??         90h
//         00530a66     NOP
//         00530a67     NOP
//         00530a68     NOP
//         00530a69     NOP
//         00530a6a     NOP
//         00530a6b     NOP
//         00530a6c     NOP
//         00530a6d     NOP
//         00530a6e     NOP
//         00530a6f     NOP
    return 0;
}

long TRIBE_World::get_achievement(uchar param_1, char** param_2) {
    /* TODO: Stub */
//                              long __thiscall get_achievement(TRIBE_World * this, uchar param_1, c
//              long              EAX:4          <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00530a80(R)
//              char * *          Stack[0x8]:4   param_2                   XREF[1]:     00530a85(R)
//                               ?get_achievement@TRIBE_World@@QAEJEPAPAD@Z                   XREF[1]:     get_achievement_info:0052a099(c)
//                               TRIBE_World::get_achievement
//                              tworld.cpp:1375 (4)
//         00530a70     PUSH       ESI
//         00530a71     PUSH       EDI
//         00530a72     MOV        EDI,this
//                              tworld.cpp:1378 (12)
//         00530a74     MOV        ESI,0x1
//         00530a79     CMP        word ptr [EDI + 0x3c],SI
//         00530a7d     JLE        LAB_00530aa8
//         00530a7f     PUSH       EBP
//                              tworld.cpp:1380 (19)
//         00530a80     MOV        EBP,dword ptr [ESP + param_1]
//         00530a84     PUSH       EBX
//         00530a85     MOV        EBX,dword ptr [ESP + param_2]
//                               LAB_00530a89                                                 XREF[1]:     00530aa4(j)
//         00530a89     MOV        EAX,dword ptr [EDI + 0x40]
//         00530a8c     MOV        this,dword ptr [EAX + ESI*0x4]
//         00530a8f     TEST       this,this
//         00530a91     JZ         LAB_00530a9d
//                              tworld.cpp:1381 (21)
//         00530a93     MOV        EDX,dword ptr [EBX + ESI*0x4]
//         00530a96     PUSH       EDX
//         00530a97     PUSH       EBP
//         00530a98     CALL       TRIBE_Player::get_achievement                    void get_achievement(TRIBE_Player * this, uch
//                               LAB_00530a9d                                                 XREF[1]:     00530a91(j)
//         00530a9d     MOVSX      EAX,word ptr [EDI + 0x3c]
//         00530aa1     INC        ESI
//         00530aa2     CMP        ESI,EAX
//         00530aa4     JL         LAB_00530a89
//         00530aa6     POP        EBX
//         00530aa7     POP        EBP
//                               LAB_00530aa8                                                 XREF[1]:     00530a7d(j)
//                              tworld.cpp:1383 (4)
//         00530aa8     MOVSX      EAX,word ptr [EDI + 0x3c]
//                              tworld.cpp:1384 (5)
//         00530aac     POP        EDI
//         00530aad     POP        ESI
//         00530aae     RET        0x8
//         00530ab1     ??         90h
//         00530ab2     NOP
//         00530ab3     NOP
//         00530ab4     NOP
//         00530ab5     NOP
//         00530ab6     NOP
//         00530ab7     NOP
//         00530ab8     NOP
//         00530ab9     NOP
//         00530aba     NOP
//         00530abb     NOP
//         00530abc     NOP
//         00530abd     NOP
//         00530abe     NOP
//         00530abf     NOP
    return 0;
}

void TRIBE_World::send_cheat(short param_1) {
    /* TODO: Stub */
//                              void __thiscall send_cheat(TRIBE_World * this, short param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00530ac0(R)
//                               ?send_cheat@TRIBE_World@@QAEXF@Z                             XREF[1]:     processCheatCode:00528492(c)
//                               TRIBE_World::send_cheat
//                              tworld.cpp:1388 (18)
//         00530ac0     MOV        EAX,dword ptr [ESP + param_1]
//         00530ac4     MOV        DX,word ptr [ECX + this->_padding_]
//         00530ac8     MOV        this,dword ptr [ECX + this->_padding_]
//         00530acb     PUSH       EAX
//         00530acc     PUSH       EDX
//         00530acd     CALL       TRIBE_Command::command_cheat                     void command_cheat(TRIBE_Command * this, shor
//                              tworld.cpp:1390 (3)
//         00530ad2     RET        0x4
//         00530ad5     ??         90h
//         00530ad6     NOP
//         00530ad7     NOP
//         00530ad8     NOP
//         00530ad9     NOP
//         00530ada     NOP
//         00530adb     NOP
//         00530adc     NOP
//         00530add     NOP
//         00530ade     NOP
//         00530adf     NOP
    return;
}

void TRIBE_World::cheat(short param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall cheat(TRIBE_World * this, short param_1, short param
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[23]:    00530b18(R), 00530b66(R), 00530bb4(R), 00530bdd(R),
//                                                                                     00530c09(R), 00530c4f(R), 00530c7b(R), 00530ca7(R),
//                                                                                     00530cd3(R), 00530cff(R), 00530d2b(R), 00530d57(R),
//                                                                                     00530d83(R), 00530daf(R), 00530dfd(R), 00530e29(R),
//                                                                                     00530e77(R), 00530ef9(R), 00530f60(R), 00530f9e(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00530af9(R)
//                               ?cheat@TRIBE_World@@QAEXFF@Z                                 XREF[1]:     do_command_game:0050a42c(c)
//                               TRIBE_World::cheat
//                              tworld.cpp:1395 (5)
//         00530ae0     PUSH       EBX
//         00530ae1     PUSH       EBP
//         00530ae2     PUSH       ESI
//         00530ae3     MOV        ESI,this
//                              tworld.cpp:1396 (20)
//         00530ae5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00530aeb     PUSH       EDI
//         00530aec     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//         00530af1     TEST       EAX,EAX
//         00530af3     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1399 (31)
//         00530af9     MOVSX      EAX,word ptr [ESP + param_2]
//         00530afe     CMP        EAX,0xe7
//         00530b03     JA         switchD_00530b11::caseD_14
//         00530b09     XOR        this,this
//         00530b0b     MOV        this,byte ptr [EAX + switchD_00530b11::switchd
//                               switchD_00530b11::switchD
//         00530b11     JMP        dword ptr [this->_padding_*0x4 + switchD_00530   = 00530b18
//                               switchD_00530b11::caseD_0                                    XREF[2]:     00530b11(j), 005310e0(*)
//                              tworld.cpp:1402 (14)
//         00530b18     MOV        AX,word ptr [ESP + param_1]
//         00530b1d     TEST       AX,AX
//         00530b20     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1404 (35)
//         00530b26     MOVSX      EDX,AX
//         00530b29     MOV        EAX,dword ptr [ESI + 0x40]
//         00530b2c     PUSH       0x0
//         00530b2e     PUSH       0x2
//         00530b30     PUSH       0x1
//         00530b32     MOV        this,dword ptr [EAX + EDX*0x4]
//         00530b35     PUSH       0xbf800000
//         00530b3a     PUSH       0xbf800000
//         00530b3f     PUSH       0x6d
//         00530b41     MOV        this,dword ptr [ECX + this->_padding_]
//         00530b44     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1405 (8)
//         00530b49     TEST       EAX,EAX
//         00530b4b     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1406 (14)
//         00530b51     MOV        this,dword ptr [ESI + 0x58]
//         00530b54     PUSH       0x112
//         00530b59     PUSH       EAX
//         00530b5a     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tworld.cpp:1606 (7)
//         00530b5f     POP        EDI
//         00530b60     POP        ESI
//         00530b61     POP        EBP
//         00530b62     POP        EBX
//         00530b63     RET        0x8
//                               switchD_00530b11::caseD_1                                    XREF[2]:     00530b11(j), 005310e4(*)
//                              tworld.cpp:1411 (14)
//         00530b66     MOV        AX,word ptr [ESP + param_1]
//         00530b6b     TEST       AX,AX
//         00530b6e     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1413 (35)
//         00530b74     MOVSX      EDX,AX
//         00530b77     MOV        EAX,dword ptr [ESI + 0x40]
//         00530b7a     PUSH       0x0
//         00530b7c     PUSH       0x2
//         00530b7e     PUSH       0x1
//         00530b80     MOV        this,dword ptr [EAX + EDX*0x4]
//         00530b83     PUSH       0xbf800000
//         00530b88     PUSH       0xbf800000
//         00530b8d     PUSH       0x6d
//         00530b8f     MOV        this,dword ptr [ECX + this->_padding_]
//         00530b92     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1414 (8)
//         00530b97     TEST       EAX,EAX
//         00530b99     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1415 (14)
//         00530b9f     MOV        this,dword ptr [ESI + 0x58]
//         00530ba2     PUSH       0xf8
//         00530ba7     PUSH       EAX
//         00530ba8     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tworld.cpp:1606 (7)
//         00530bad     POP        EDI
//         00530bae     POP        ESI
//         00530baf     POP        EBP
//         00530bb0     POP        EBX
//         00530bb1     RET        0x8
//                               switchD_00530b11::caseD_2                                    XREF[2]:     00530b11(j), 005310e8(*)
//                              tworld.cpp:1420 (14)
//         00530bb4     MOV        AX,word ptr [ESP + param_1]
//         00530bb9     TEST       AX,AX
//         00530bbc     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1421 (20)
//         00530bc2     MOV        this,dword ptr [ESI + 0x4c]
//         00530bc5     MOV        ESI,dword ptr [ESI + 0x40]
//         00530bc8     MOVSX      EAX,AX
//         00530bcb     MOV        EDX,dword ptr [this->_padding_]
//         00530bcd     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530bd0     PUSH       EAX
//                              language.dll match for 0x7f: "N"
//         00530bd1     PUSH       0x7f
//         00530bd3     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530bd6     POP        EDI
//         00530bd7     POP        ESI
//         00530bd8     POP        EBP
//         00530bd9     POP        EBX
//         00530bda     RET        0x8
//                               switchD_00530b11::caseD_3                                    XREF[2]:     00530b11(j), 005310ec(*)
//                              tworld.cpp:1425 (14)
//         00530bdd     MOV        AX,word ptr [ESP + param_1]
//         00530be2     TEST       AX,AX
//         00530be5     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1426 (23)
//         00530beb     MOV        this,dword ptr [ESI + 0x4c]
//         00530bee     MOV        ESI,dword ptr [ESI + 0x40]
//         00530bf1     MOVSX      EAX,AX
//         00530bf4     MOV        EDX,dword ptr [this->_padding_]
//         00530bf6     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530bf9     PUSH       EAX
//                              language.dll match for 0x80: "Arial"
//         00530bfa     PUSH       0x80
//         00530bff     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530c02     POP        EDI
//         00530c03     POP        ESI
//         00530c04     POP        EBP
//         00530c05     POP        EBX
//         00530c06     RET        0x8
//                               switchD_00530b11::caseD_4                                    XREF[2]:     00530b11(j), 005310f0(*)
//                              tworld.cpp:1430 (14)
//         00530c09     MOV        AX,word ptr [ESP + param_1]
//         00530c0e     TEST       AX,AX
//         00530c11     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1431 (23)
//         00530c17     MOV        this,dword ptr [ESI + 0x4c]
//         00530c1a     MOV        ESI,dword ptr [ESI + 0x40]
//         00530c1d     MOVSX      EAX,AX
//         00530c20     MOV        EDX,dword ptr [this->_padding_]
//         00530c22     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530c25     PUSH       EAX
//                              language.dll match for 0x81: "10"
//         00530c26     PUSH       0x81
//         00530c2b     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530c2e     POP        EDI
//         00530c2f     POP        ESI
//         00530c30     POP        EBP
//         00530c31     POP        EBX
//         00530c32     RET        0x8
//                               switchD_00530b11::caseD_5                                    XREF[2]:     00530b11(j), 005310f4(*)
//                              tworld.cpp:1435 (19)
//         00530c35     MOV        EAX,dword ptr [ESI + 0x40]
//         00530c38     MOV        this,dword ptr [ESI + 0x4c]
//         00530c3b     MOV        EAX,dword ptr [EAX]
//         00530c3d     MOV        EDX,dword ptr [this->_padding_]
//         00530c3f     PUSH       EAX
//                              language.dll match for 0x82: "B"
//         00530c40     PUSH       0x82
//         00530c45     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530c48     POP        EDI
//         00530c49     POP        ESI
//         00530c4a     POP        EBP
//         00530c4b     POP        EBX
//         00530c4c     RET        0x8
//                               switchD_00530b11::caseD_6                                    XREF[2]:     00530b11(j), 005310f8(*)
//                              tworld.cpp:1439 (14)
//         00530c4f     MOV        AX,word ptr [ESP + param_1]
//         00530c54     TEST       AX,AX
//         00530c57     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1440 (23)
//         00530c5d     MOV        this,dword ptr [ESI + 0x4c]
//         00530c60     MOV        ESI,dword ptr [ESI + 0x40]
//         00530c63     MOVSX      EAX,AX
//         00530c66     MOV        EDX,dword ptr [this->_padding_]
//         00530c68     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530c6b     PUSH       EAX
//                              language.dll match for 0x83: "Arial"
//         00530c6c     PUSH       0x83
//         00530c71     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530c74     POP        EDI
//         00530c75     POP        ESI
//         00530c76     POP        EBP
//         00530c77     POP        EBX
//         00530c78     RET        0x8
//                               switchD_00530b11::caseD_7                                    XREF[2]:     00530b11(j), 005310fc(*)
//                              tworld.cpp:1444 (14)
//         00530c7b     MOV        AX,word ptr [ESP + param_1]
//         00530c80     TEST       AX,AX
//         00530c83     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1445 (23)
//         00530c89     MOV        this,dword ptr [ESI + 0x4c]
//         00530c8c     MOV        ESI,dword ptr [ESI + 0x40]
//         00530c8f     MOVSX      EAX,AX
//         00530c92     MOV        EDX,dword ptr [this->_padding_]
//         00530c94     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530c97     PUSH       EAX
//                              language.dll match for 0x84: "8"
//         00530c98     PUSH       0x84
//         00530c9d     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530ca0     POP        EDI
//         00530ca1     POP        ESI
//         00530ca2     POP        EBP
//         00530ca3     POP        EBX
//         00530ca4     RET        0x8
//                               switchD_00530b11::caseD_8                                    XREF[2]:     00530b11(j), 00531100(*)
//                              tworld.cpp:1449 (14)
//         00530ca7     MOV        AX,word ptr [ESP + param_1]
//         00530cac     TEST       AX,AX
//         00530caf     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1450 (23)
//         00530cb5     MOV        this,dword ptr [ESI + 0x4c]
//         00530cb8     MOV        ESI,dword ptr [ESI + 0x40]
//         00530cbb     MOVSX      EAX,AX
//         00530cbe     MOV        EDX,dword ptr [this->_padding_]
//         00530cc0     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530cc3     PUSH       EAX
//                              language.dll match for 0x85: "N"
//         00530cc4     PUSH       0x85
//         00530cc9     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530ccc     POP        EDI
//         00530ccd     POP        ESI
//         00530cce     POP        EBP
//         00530ccf     POP        EBX
//         00530cd0     RET        0x8
//                               switchD_00530b11::caseD_9                                    XREF[2]:     00530b11(j), 00531104(*)
//                              tworld.cpp:1454 (14)
//         00530cd3     MOV        AX,word ptr [ESP + param_1]
//         00530cd8     TEST       AX,AX
//         00530cdb     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1455 (23)
//         00530ce1     MOV        this,dword ptr [ESI + 0x4c]
//         00530ce4     MOV        ESI,dword ptr [ESI + 0x40]
//         00530ce7     MOVSX      EAX,AX
//         00530cea     MOV        EDX,dword ptr [this->_padding_]
//         00530cec     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530cef     PUSH       EAX
//         00530cf0     PUSH       0x86
//         00530cf5     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530cf8     POP        EDI
//         00530cf9     POP        ESI
//         00530cfa     POP        EBP
//         00530cfb     POP        EBX
//         00530cfc     RET        0x8
//                               switchD_00530b11::caseD_a                                    XREF[2]:     00530b11(j), 00531108(*)
//                              tworld.cpp:1459 (14)
//         00530cff     MOV        AX,word ptr [ESP + param_1]
//         00530d04     TEST       AX,AX
//         00530d07     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1460 (23)
//         00530d0d     MOV        this,dword ptr [ESI + 0x4c]
//         00530d10     MOV        ESI,dword ptr [ESI + 0x40]
//         00530d13     MOVSX      EAX,AX
//         00530d16     MOV        EDX,dword ptr [this->_padding_]
//         00530d18     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530d1b     PUSH       EAX
//         00530d1c     PUSH       0x87
//         00530d21     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530d24     POP        EDI
//         00530d25     POP        ESI
//         00530d26     POP        EBP
//         00530d27     POP        EBX
//         00530d28     RET        0x8
//                               switchD_00530b11::caseD_b                                    XREF[2]:     00530b11(j), 0053110c(*)
//                              tworld.cpp:1464 (14)
//         00530d2b     MOV        AX,word ptr [ESP + param_1]
//         00530d30     TEST       AX,AX
//         00530d33     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1465 (23)
//         00530d39     MOV        this,dword ptr [ESI + 0x4c]
//         00530d3c     MOV        ESI,dword ptr [ESI + 0x40]
//         00530d3f     MOVSX      EAX,AX
//         00530d42     MOV        EDX,dword ptr [this->_padding_]
//         00530d44     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530d47     PUSH       EAX
//         00530d48     PUSH       0x88
//         00530d4d     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530d50     POP        EDI
//         00530d51     POP        ESI
//         00530d52     POP        EBP
//         00530d53     POP        EBX
//         00530d54     RET        0x8
//                               switchD_00530b11::caseD_c                                    XREF[2]:     00530b11(j), 00531110(*)
//                              tworld.cpp:1469 (14)
//         00530d57     MOV        AX,word ptr [ESP + param_1]
//         00530d5c     TEST       AX,AX
//         00530d5f     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1470 (23)
//         00530d65     MOV        this,dword ptr [ESI + 0x4c]
//         00530d68     MOV        ESI,dword ptr [ESI + 0x40]
//         00530d6b     MOVSX      EAX,AX
//         00530d6e     MOV        EDX,dword ptr [this->_padding_]
//         00530d70     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530d73     PUSH       EAX
//         00530d74     PUSH       0x89
//         00530d79     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530d7c     POP        EDI
//         00530d7d     POP        ESI
//         00530d7e     POP        EBP
//         00530d7f     POP        EBX
//         00530d80     RET        0x8
//                               switchD_00530b11::caseD_d                                    XREF[2]:     00530b11(j), 00531114(*)
//                              tworld.cpp:1474 (14)
//         00530d83     MOV        AX,word ptr [ESP + param_1]
//         00530d88     TEST       AX,AX
//         00530d8b     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1475 (23)
//         00530d91     MOV        this,dword ptr [ESI + 0x4c]
//         00530d94     MOV        ESI,dword ptr [ESI + 0x40]
//         00530d97     MOVSX      EAX,AX
//         00530d9a     MOV        EDX,dword ptr [this->_padding_]
//         00530d9c     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530d9f     PUSH       EAX
//         00530da0     PUSH       0x8a
//         00530da5     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530da8     POP        EDI
//         00530da9     POP        ESI
//         00530daa     POP        EBP
//         00530dab     POP        EBX
//         00530dac     RET        0x8
//                               switchD_00530b11::caseD_e                                    XREF[2]:     00530b11(j), 00531118(*)
//                              tworld.cpp:1479 (14)
//         00530daf     MOV        AX,word ptr [ESP + param_1]
//         00530db4     TEST       AX,AX
//         00530db7     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1481 (35)
//         00530dbd     MOV        EDX,dword ptr [ESI + 0x40]
//         00530dc0     PUSH       0x0
//         00530dc2     MOVSX      this,AX
//         00530dc5     PUSH       0x2
//         00530dc7     PUSH       0x1
//         00530dc9     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         00530dcc     PUSH       0xbf800000
//         00530dd1     PUSH       0xbf800000
//         00530dd6     PUSH       0x6d
//         00530dd8     MOV        this,dword ptr [EAX + 0x28]
//         00530ddb     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1482 (8)
//         00530de0     TEST       EAX,EAX
//         00530de2     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1483 (14)
//         00530de8     MOV        this,dword ptr [ESI + 0x58]
//         00530deb     PUSH       0x182
//         00530df0     PUSH       EAX
//         00530df1     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tworld.cpp:1606 (7)
//         00530df6     POP        EDI
//         00530df7     POP        ESI
//         00530df8     POP        EBP
//         00530df9     POP        EBX
//         00530dfa     RET        0x8
//                               switchD_00530b11::caseD_f                                    XREF[2]:     00530b11(j), 0053111c(*)
//                              tworld.cpp:1488 (14)
//         00530dfd     MOV        AX,word ptr [ESP + param_1]
//         00530e02     TEST       AX,AX
//         00530e05     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1489 (23)
//         00530e0b     MOV        this,dword ptr [ESI + 0x4c]
//         00530e0e     MOV        ESI,dword ptr [ESI + 0x40]
//         00530e11     MOVSX      EAX,AX
//         00530e14     MOV        EDX,dword ptr [this->_padding_]
//         00530e16     MOV        EAX,dword ptr [ESI + EAX*0x4]
//         00530e19     PUSH       EAX
//         00530e1a     PUSH       0xd7
//         00530e1f     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530e22     POP        EDI
//         00530e23     POP        ESI
//         00530e24     POP        EBP
//         00530e25     POP        EBX
//         00530e26     RET        0x8
//                               switchD_00530b11::caseD_10                                   XREF[2]:     00530b11(j), 00531120(*)
//                              tworld.cpp:1493 (14)
//         00530e29     MOV        AX,word ptr [ESP + param_1]
//         00530e2e     TEST       AX,AX
//         00530e31     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1495 (35)
//         00530e37     MOV        EDX,dword ptr [ESI + 0x40]
//         00530e3a     PUSH       0x0
//         00530e3c     MOVSX      this,AX
//         00530e3f     PUSH       0x2
//         00530e41     PUSH       0x1
//         00530e43     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         00530e46     PUSH       0xbf800000
//         00530e4b     PUSH       0xbf800000
//         00530e50     PUSH       0x6d
//         00530e52     MOV        this,dword ptr [EAX + 0x28]
//         00530e55     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1496 (8)
//         00530e5a     TEST       EAX,EAX
//         00530e5c     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1497 (14)
//         00530e62     MOV        this,dword ptr [ESI + 0x58]
//         00530e65     PUSH       0x18d
//         00530e6a     PUSH       EAX
//         00530e6b     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tworld.cpp:1606 (7)
//         00530e70     POP        EDI
//         00530e71     POP        ESI
//         00530e72     POP        EBP
//         00530e73     POP        EBX
//         00530e74     RET        0x8
//                               switchD_00530b11::caseD_11                                   XREF[2]:     00530b11(j), 00531124(*)
//                              tworld.cpp:1502 (14)
//         00530e77     MOV        AX,word ptr [ESP + param_1]
//         00530e7c     TEST       AX,AX
//         00530e7f     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1504 (35)
//         00530e85     MOV        EDX,dword ptr [ESI + 0x40]
//         00530e88     PUSH       0x0
//         00530e8a     MOVSX      this,AX
//         00530e8d     PUSH       0x2
//         00530e8f     PUSH       0x1
//         00530e91     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         00530e94     PUSH       0xbf800000
//         00530e99     PUSH       0xbf800000
//         00530e9e     PUSH       0x6d
//         00530ea0     MOV        this,dword ptr [EAX + 0x28]
//         00530ea3     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1606 (7)
//         00530ea8     POP        EDI
//         00530ea9     POP        ESI
//         00530eaa     POP        EBP
//         00530eab     POP        EBX
//         00530eac     RET        0x8
//                               switchD_00530b11::caseD_12                                   XREF[2]:     00530b11(j), 00531128(*)
//                              tworld.cpp:1511 (19)
//         00530eaf     MOV        EAX,dword ptr [ESI + 0x40]
//         00530eb2     MOV        this,dword ptr [ESI + 0x4c]
//         00530eb5     MOV        EAX,dword ptr [EAX]
//         00530eb7     MOV        EDX,dword ptr [this->_padding_]
//         00530eb9     PUSH       EAX
//         00530eba     PUSH       0xd8
//         00530ebf     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530ec2     POP        EDI
//         00530ec3     POP        ESI
//         00530ec4     POP        EBP
//         00530ec5     POP        EBX
//         00530ec6     RET        0x8
//                               switchD_00530b11::caseD_13                                   XREF[2]:     00530b11(j), 0053112c(*)
//                              tworld.cpp:1515 (19)
//         00530ec9     MOV        EAX,dword ptr [ESI + 0x40]
//         00530ecc     MOV        this,dword ptr [ESI + 0x4c]
//         00530ecf     MOV        EAX,dword ptr [EAX]
//         00530ed1     MOV        EDX,dword ptr [this->_padding_]
//         00530ed3     PUSH       EAX
//         00530ed4     PUSH       0xd9
//         00530ed9     CALL       dword ptr [EDX + 0x8]
//                              tworld.cpp:1606 (7)
//         00530edc     POP        EDI
//         00530edd     POP        ESI
//         00530ede     POP        EBP
//         00530edf     POP        EBX
//         00530ee0     RET        0x8
//                               switchD_00530b11::caseD_64                                   XREF[2]:     00530b11(j), 00531130(*)
//                              tworld.cpp:1522 (22)
//         00530ee3     MOV        EBP,0x1
//         00530ee8     MOV        byte ptr [die_die_die],0x1                       = 00h
//         00530eef     CMP        word ptr [ESI + 0x3c],BP
//         00530ef3     JLE        switchD_00530b11::caseD_14
//                              tworld.cpp:1524 (41)
//         00530ef9     MOVSX      EBX,word ptr [ESP + param_1]
//                               LAB_00530efe                                                 XREF[1]:     00530f57(j)
//         00530efe     CMP        EBP,EBX
//         00530f00     JNZ        LAB_00530f22
//         00530f02     MOV        this,dword ptr [ESI + 0x40]
//         00530f05     PUSH       EBP
//         00530f06     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
//         00530f09     MOV        EDX,dword ptr [this->_padding_]
//         00530f0b     CALL       dword ptr [EDX + 0x1c]
//         00530f0e     TEST       EAX,EAX
//         00530f10     JZ         LAB_00530f22
//         00530f12     MOV        EAX,dword ptr [ESI + 0x40]
//         00530f15     PUSH       EBX
//         00530f16     MOV        this,dword ptr [EAX + EBP*0x4]
//         00530f19     MOV        EDX,dword ptr [this->_padding_]
//         00530f1b     CALL       dword ptr [EDX + 0x1c]
//         00530f1e     TEST       EAX,EAX
//         00530f20     JNZ        LAB_00530f50
//                               LAB_00530f22                                                 XREF[2]:     00530f00(j), 00530f10(j)
//                              tworld.cpp:1526 (16)
//         00530f22     MOV        EAX,dword ptr [ESI + 0x40]
//         00530f25     MOV        this,dword ptr [EAX + EBP*0x4]
//         00530f28     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00530f2b     MOV        EDI,dword ptr [EDX + 0x4]
//         00530f2e     TEST       EDI,EDI
//         00530f30     JZ         LAB_00530f50
//                               LAB_00530f32                                                 XREF[1]:     00530f4e(j)
//                              tworld.cpp:1528 (18)
//         00530f32     MOV        this,dword ptr [EDI]
//         00530f34     CMP        byte ptr [ECX + this->_padding_],0x3
//         00530f38     JNC        LAB_00530f49
//         00530f3a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00530f3d     CMP        word ptr [EAX + 0x14],0x1
//         00530f42     JZ         LAB_00530f49
//                              tworld.cpp:1529 (12)
//         00530f44     MOV        EDX,dword ptr [this->_padding_]
//         00530f46     CALL       dword ptr [EDX + 0x6c]
//                               LAB_00530f49                                                 XREF[2]:     00530f38(j), 00530f42(j)
//         00530f49     MOV        EDI,dword ptr [EDI + 0x4]
//         00530f4c     TEST       EDI,EDI
//         00530f4e     JNZ        LAB_00530f32
//                               LAB_00530f50                                                 XREF[2]:     00530f20(j), 00530f30(j)
//                              tworld.cpp:1522 (9)
//         00530f50     MOVSX      EAX,word ptr [ESI + 0x3c]
//         00530f54     INC        EBP
//         00530f55     CMP        EBP,EAX
//         00530f57     JL         LAB_00530efe
//                              tworld.cpp:1606 (7)
//         00530f59     POP        EDI
//         00530f5a     POP        ESI
//         00530f5b     POP        EBP
//         00530f5c     POP        EBX
//         00530f5d     RET        0x8
//                               switchD_00530b11::caseD_65                                   XREF[2]:     00530b11(j), 00531134(*)
//                              tworld.cpp:1539 (25)
//         00530f60     MOVSX      this,word ptr [ESP + param_1]
//         00530f65     MOV        EDX,dword ptr [ESI + 0x40]
//         00530f68     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         00530f6b     MOV        this,dword ptr [EAX + 0x28]
//         00530f6e     MOV        ESI,dword ptr [ECX + this->_padding_]
//         00530f71     TEST       ESI,ESI
//         00530f73     JZ         switchD_00530b11::caseD_14
//                               LAB_00530f79                                                 XREF[1]:     00530f95(j)
//                              tworld.cpp:1541 (18)
//         00530f79     MOV        this,dword ptr [ESI]
//         00530f7b     CMP        byte ptr [ECX + this->_padding_],0x3
//         00530f7f     JNC        LAB_00530f90
//         00530f81     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00530f84     CMP        word ptr [EDX + 0x14],0x1
//         00530f89     JZ         LAB_00530f90
//                              tworld.cpp:1542 (12)
//         00530f8b     MOV        EAX,dword ptr [this->_padding_]
//         00530f8d     CALL       dword ptr [EAX + 0x6c]
//                               LAB_00530f90                                                 XREF[2]:     00530f7f(j), 00530f89(j)
//         00530f90     MOV        ESI,dword ptr [ESI + 0x4]
//         00530f93     TEST       ESI,ESI
//         00530f95     JNZ        LAB_00530f79
//                              tworld.cpp:1606 (7)
//         00530f97     POP        EDI
//         00530f98     POP        ESI
//         00530f99     POP        EBP
//         00530f9a     POP        EBX
//         00530f9b     RET        0x8
//                               switchD_00530b11::caseD_66                                   XREF[2]:     00530b11(j), 00531138(*)
//                              tworld.cpp:1549 (16)
//         00530f9e     MOVSX      this,word ptr [ESP + param_1]
//         00530fa3     MOV        EDX,dword ptr [ESI + 0x40]
//         00530fa6     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         00530fa9     CALL       RGE_Player::win_game_now                         void win_game_now(RGE_Player * this)
//                              language.dll match for 0x68: "Arial"
//                              tworld.cpp:1550 (4)
//         00530fae     MOV        byte ptr [ESI + 0x1e],0x68
//                              tworld.cpp:1606 (7)
//         00530fb2     POP        EDI
//         00530fb3     POP        ESI
//         00530fb4     POP        EBP
//         00530fb5     POP        EBX
//         00530fb6     RET        0x8
//                               switchD_00530b11::caseD_67                                   XREF[2]:     00530b11(j), 0053113c(*)
//                              tworld.cpp:1556 (16)
//         00530fb9     MOVSX      EAX,word ptr [ESP + param_1]
//         00530fbe     MOV        this,dword ptr [ESI + 0x40]
//         00530fc1     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
//         00530fc4     CALL       RGE_Player::loss_if_game_on                      void loss_if_game_on(RGE_Player * this)
//                              tworld.cpp:1606 (7)
//         00530fc9     POP        EDI
//         00530fca     POP        ESI
//         00530fcb     POP        EBP
//         00530fcc     POP        EBX
//         00530fcd     RET        0x8
//                               switchD_00530b11::caseD_c9                                   XREF[2]:     00530b11(j), 00531140(*)
//                               switchD_00530b11::caseD_ca
//                               switchD_00530b11::caseD_cb
//                               switchD_00530b11::caseD_cc
//                               switchD_00530b11::caseD_cd
//                               switchD_00530b11::caseD_ce
//                               switchD_00530b11::caseD_cf
//                               switchD_00530b11::caseD_d0
//                               switchD_00530b11::caseD_d1
//                               switchD_00530b11::caseD_c8
//                              tworld.cpp:1574 (51)
//         00530fd0     MOVSX      EBX,word ptr [ESP + param_1]
//         00530fd5     LEA        EDI,[EAX + 0xffffff38]
//         00530fdb     CMP        EDI,EBX
//         00530fdd     JNZ        LAB_00531003
//         00530fdf     MOV        EDX,dword ptr [ESI + 0x40]
//         00530fe2     PUSH       EDI
//         00530fe3     MOV        this,dword ptr [EDX + EBX*0x4]
//         00530fe6     MOV        EAX,dword ptr [this->_padding_]
//         00530fe8     CALL       dword ptr [EAX + 0x1c]
//         00530feb     TEST       EAX,EAX
//         00530fed     JZ         LAB_00531003
//         00530fef     MOV        this,dword ptr [ESI + 0x40]
//         00530ff2     PUSH       EBX
//         00530ff3     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
//         00530ff6     MOV        EDX,dword ptr [this->_padding_]
//         00530ff8     CALL       dword ptr [EDX + 0x1c]
//         00530ffb     TEST       EAX,EAX
//         00530ffd     JNZ        switchD_00530b11::caseD_14
//                               LAB_00531003                                                 XREF[2]:     00530fdd(j), 00530fed(j)
//                              tworld.cpp:1576 (20)
//         00531003     MOV        EAX,dword ptr [ESI + 0x40]
//         00531006     MOV        this,dword ptr [EAX + EDI*0x4]
//         00531009     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053100c     MOV        ESI,dword ptr [EDX + 0x4]
//         0053100f     TEST       ESI,ESI
//         00531011     JZ         switchD_00530b11::caseD_14
//                               LAB_00531017                                                 XREF[1]:     00531033(j)
//                              tworld.cpp:1578 (18)
//         00531017     MOV        this,dword ptr [ESI]
//         00531019     CMP        byte ptr [ECX + this->_padding_],0x3
//         0053101d     JNC        LAB_0053102e
//         0053101f     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00531022     CMP        word ptr [EAX + 0x14],0x1
//         00531027     JZ         LAB_0053102e
//                              tworld.cpp:1579 (12)
//         00531029     MOV        EDX,dword ptr [this->_padding_]
//         0053102b     CALL       dword ptr [EDX + 0x6c]
//                               LAB_0053102e                                                 XREF[2]:     0053101d(j), 00531027(j)
//         0053102e     MOV        ESI,dword ptr [ESI + 0x4]
//         00531031     TEST       ESI,ESI
//         00531033     JNZ        LAB_00531017
//                              tworld.cpp:1606 (7)
//         00531035     POP        EDI
//         00531036     POP        ESI
//         00531037     POP        EBP
//         00531038     POP        EBX
//         00531039     RET        0x8
//                               switchD_00530b11::caseD_dc                                   XREF[2]:     00530b11(j), 00531144(*)
//                              tworld.cpp:1587 (37)
//         0053103c     MOVSX      EAX,word ptr [ESP + param_1]
//         00531041     MOV        this,dword ptr [ESI + 0x40]
//         00531044     PUSH       0x0
//         00531046     PUSH       0x2
//         00531048     PUSH       0x1
//         0053104a     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
//         0053104d     PUSH       0xbf800000
//         00531052     PUSH       0xbf800000
//         00531057     PUSH       0x6d
//         00531059     MOV        this,dword ptr [EDX + 0x28]
//         0053105c     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
//                              tworld.cpp:1588 (4)
//         00531061     TEST       EAX,EAX
//         00531063     JZ         switchD_00530b11::caseD_14
//                              tworld.cpp:1589 (14)
//         00531065     MOV        this,dword ptr [ESI + 0x58]
//         00531068     PUSH       0x174
//         0053106d     PUSH       EAX
//         0053106e     CALL       TRIBE_Command::command_make                      void command_make(TRIBE_Command * this, RGE_S
//                              tworld.cpp:1606 (7)
//         00531073     POP        EDI
//         00531074     POP        ESI
//         00531075     POP        EBP
//         00531076     POP        EBX
//         00531077     RET        0x8
//                               switchD_00530b11::caseD_e6                                   XREF[2]:     00530b11(j), 00531148(*)
//                              tworld.cpp:1595 (13)
//         0053107a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00531080     PUSH       0x1
//         00531082     CALL       RGE_Base_Game::set_map_visible                   void set_map_visible(RGE_Base_Game * this, uc
//                              tworld.cpp:1596 (20)
//         00531087     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053108d     MOV        EAX,dword ptr [this->_padding_]
//         0053108f     CALL       dword ptr [EAX + 0x2c]
//         00531092     MOV        EDX,dword ptr [EAX]
//         00531094     PUSH       0x2
//         00531096     MOV        this,EAX
//         00531098     CALL       dword ptr [EDX + 0x20]
//                              tworld.cpp:1597 (11)
//         0053109b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005310a1     MOV        EAX,dword ptr [this->_padding_]
//         005310a3     CALL       dword ptr [EAX + 0x30]
//                              tworld.cpp:1603 (9)
//         005310a6     MOV        EDX,dword ptr [EAX]
//         005310a8     PUSH       0x2
//         005310aa     MOV        this,EAX
//         005310ac     CALL       dword ptr [EDX + 0x20]
//                              tworld.cpp:1606 (7)
//         005310af     POP        EDI
//         005310b0     POP        ESI
//         005310b1     POP        EBP
//         005310b2     POP        EBX
//         005310b3     RET        0x8
//                               switchD_00530b11::caseD_e7                                   XREF[2]:     00530b11(j), 0053114c(*)
//                              tworld.cpp:1602 (13)
//         005310b6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005310bc     PUSH       0x0
//         005310be     CALL       RGE_Base_Game::set_map_fog                       void set_map_fog(RGE_Base_Game * this, uchar
//                              tworld.cpp:1603 (20)
//         005310c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005310c9     MOV        EAX,dword ptr [this->_padding_]
//         005310cb     CALL       dword ptr [EAX + 0x2c]
//         005310ce     MOV        EDX,dword ptr [EAX]
//         005310d0     PUSH       0x2
//         005310d2     MOV        this,EAX
//         005310d4     CALL       dword ptr [EDX + 0x20]
//                               switchD_00530b11::caseD_15                                   XREF[30]:    00530af3(j), 00530b03(j),
//                               switchD_00530b11::caseD_16                                                00530b11(j), 00530b20(j),
//                               switchD_00530b11::caseD_17                                                00530b4b(j), 00530b6e(j),
//                               switchD_00530b11::caseD_18                                                00530b99(j), 00530bbc(j),
//                               switchD_00530b11::caseD_19                                                00530be5(j), 00530c11(j),
//                               switchD_00530b11::caseD_1a                                                00530c57(j), 00530c83(j),
//                               switchD_00530b11::caseD_1b                                                00530caf(j), 00530cdb(j),
//                               switchD_00530b11::caseD_1c                                                00530d07(j), 00530d33(j),
//                               switchD_00530b11::caseD_1d                                                00530d5f(j), 00530d8b(j),
//                               switchD_00530b11::caseD_1e                                                00530db7(j), 00530de2(j), [more]
//                               switchD_00530b11::caseD_1f
//                               switchD_00530b11::caseD_20
//                               switchD_00530b11::caseD_21
//                               switchD_00530b11::caseD_22
//                               switchD_00530b11::caseD_23
//                               switchD_00530b11::caseD_24
//                               switchD_00530b11::caseD_25
//                               switchD_00530b11::caseD_26
//                               switchD_00530b11::caseD_27
//                               switchD_00530b11::caseD_28
//                               switchD_00530b11::caseD_29
//                               switchD_00530b11::caseD_2a
//                               switchD_00530b11::caseD_2b
//                               switchD_00530b11::caseD_2c
//                               switchD_00530b11::caseD_2d
//                               switchD_00530b11::caseD_2e
//                               switchD_00530b11::caseD_2f
//                               switchD_00530b11::caseD_30
//                               switchD_00530b11::caseD_31
//                               switchD_00530b11::caseD_32
//                               switchD_00530b11::caseD_33
//                               switchD_00530b11::caseD_34
//                               switchD_00530b11::caseD_35
//                               switchD_00530b11::caseD_36
//                               switchD_00530b11::caseD_37
//                               switchD_00530b11::caseD_38
//                               switchD_00530b11::caseD_39
//                               switchD_00530b11::caseD_3a
//                               switchD_00530b11::caseD_3b
//                               switchD_00530b11::caseD_3c
//                               switchD_00530b11::caseD_3d
//                               switchD_00530b11::caseD_3e
//                               switchD_00530b11::caseD_3f
//                               switchD_00530b11::caseD_40
//                               switchD_00530b11::caseD_41
//                               switchD_00530b11::caseD_42
//                               switchD_00530b11::caseD_43
//                               switchD_00530b11::caseD_44
//                               switchD_00530b11::caseD_45
//                               switchD_00530b11::caseD_46
//                               switchD_00530b11::caseD_47
//                               switchD_00530b11::caseD_48
//                               switchD_00530b11::caseD_49
//                               switchD_00530b11::caseD_4a
//                               switchD_00530b11::caseD_4b
//                               switchD_00530b11::caseD_4c
//                               switchD_00530b11::caseD_4d
//                               switchD_00530b11::caseD_4e
//                               switchD_00530b11::caseD_4f
//                               switchD_00530b11::caseD_50
//                               switchD_00530b11::caseD_51
//                               switchD_00530b11::caseD_52
//                               switchD_00530b11::caseD_53
//                               switchD_00530b11::caseD_54
//                               switchD_00530b11::caseD_55
//                               switchD_00530b11::caseD_56
//                               switchD_00530b11::caseD_57
//                               switchD_00530b11::caseD_58
//                               switchD_00530b11::caseD_59
//                               switchD_00530b11::caseD_5a
//                               switchD_00530b11::caseD_5b
//                               switchD_00530b11::caseD_5c
//                               switchD_00530b11::caseD_5d
//                               switchD_00530b11::caseD_5e
//                               switchD_00530b11::caseD_5f
//                               switchD_00530b11::caseD_60
//                               switchD_00530b11::caseD_61
//                               switchD_00530b11::caseD_62
//                               switchD_00530b11::caseD_63
//                               switchD_00530b11::caseD_68
//                               switchD_00530b11::caseD_69
//                               switchD_00530b11::caseD_6a
//                               switchD_00530b11::caseD_6b
//                               switchD_00530b11::caseD_6c
//                               switchD_00530b11::caseD_6d
//                               switchD_00530b11::caseD_6e
//                               switchD_00530b11::caseD_6f
//                               switchD_00530b11::caseD_70
//                               switchD_00530b11::caseD_71
//                               switchD_00530b11::caseD_72
//                               switchD_00530b11::caseD_73
//                               switchD_00530b11::caseD_74
//                               switchD_00530b11::caseD_75
//                               switchD_00530b11::caseD_76
//                               switchD_00530b11::caseD_77
//                               switchD_00530b11::caseD_78
//                               switchD_00530b11::caseD_79
//                               switchD_00530b11::caseD_7a
//                               switchD_00530b11::caseD_7b
//                               switchD_00530b11::caseD_7c
//                               switchD_00530b11::caseD_7d
//                               switchD_00530b11::caseD_7e
//                               switchD_00530b11::caseD_7f
//                               switchD_00530b11::caseD_80
//                               switchD_00530b11::caseD_81
//                               switchD_00530b11::caseD_82
//                               switchD_00530b11::caseD_83
//                               switchD_00530b11::caseD_84
//                               switchD_00530b11::caseD_85
//                               switchD_00530b11::caseD_86
//                               switchD_00530b11::caseD_87
//                               switchD_00530b11::caseD_88
//                               switchD_00530b11::caseD_89
//                               switchD_00530b11::caseD_8a
//                               switchD_00530b11::caseD_8b
//                               switchD_00530b11::caseD_8c
//                               switchD_00530b11::caseD_8d
//                               switchD_00530b11::caseD_8e
//                               switchD_00530b11::caseD_8f
//                               switchD_00530b11::caseD_90
//                               switchD_00530b11::caseD_91
//                               switchD_00530b11::caseD_92
//                               switchD_00530b11::caseD_93
//                               switchD_00530b11::caseD_94
//                               switchD_00530b11::caseD_95
//                               switchD_00530b11::caseD_96
//                               switchD_00530b11::caseD_97
//                               switchD_00530b11::caseD_98
//                               switchD_00530b11::caseD_99
//                               switchD_00530b11::caseD_9a
//                               switchD_00530b11::caseD_9b
//                               switchD_00530b11::caseD_9c
//                               switchD_00530b11::caseD_9d
//                               switchD_00530b11::caseD_9e
//                               switchD_00530b11::caseD_9f
//                               switchD_00530b11::caseD_a0
//                               switchD_00530b11::caseD_a1
//                               switchD_00530b11::caseD_a2
//                               switchD_00530b11::caseD_a3
//                               switchD_00530b11::caseD_a4
//                               switchD_00530b11::caseD_a5
//                               switchD_00530b11::caseD_a6
//                               switchD_00530b11::caseD_a7
//                               switchD_00530b11::caseD_a8
//                               switchD_00530b11::caseD_a9
//                               switchD_00530b11::caseD_aa
//                               switchD_00530b11::caseD_ab
//                               switchD_00530b11::caseD_ac
//                               switchD_00530b11::caseD_ad
//                               switchD_00530b11::caseD_ae
//                               switchD_00530b11::caseD_af
//                               switchD_00530b11::caseD_b0
//                               switchD_00530b11::caseD_b1
//                               switchD_00530b11::caseD_b2
//                               switchD_00530b11::caseD_b3
//                               switchD_00530b11::caseD_b4
//                               switchD_00530b11::caseD_b5
//                               switchD_00530b11::caseD_b6
//                               switchD_00530b11::caseD_b7
//                               switchD_00530b11::caseD_b8
//                               switchD_00530b11::caseD_b9
//                               switchD_00530b11::caseD_ba
//                               switchD_00530b11::caseD_bb
//                               switchD_00530b11::caseD_bc
//                               switchD_00530b11::caseD_bd
//                               switchD_00530b11::caseD_be
//                               switchD_00530b11::caseD_bf
//                               switchD_00530b11::caseD_c0
//                               switchD_00530b11::caseD_c1
//                               switchD_00530b11::caseD_c2
//                               switchD_00530b11::caseD_c3
//                               switchD_00530b11::caseD_c4
//                               switchD_00530b11::caseD_c5
//                               switchD_00530b11::caseD_c6
//                               switchD_00530b11::caseD_c7
//                               switchD_00530b11::caseD_d2
//                               switchD_00530b11::caseD_d3
//                               switchD_00530b11::caseD_d4
//                               switchD_00530b11::caseD_d5
//                               switchD_00530b11::caseD_d6
//                               switchD_00530b11::caseD_d7
//                               switchD_00530b11::caseD_d8
//                               switchD_00530b11::caseD_d9
//                               switchD_00530b11::caseD_da
//                               switchD_00530b11::caseD_db
//                               switchD_00530b11::caseD_dd
//                               switchD_00530b11::caseD_de
//                               switchD_00530b11::caseD_df
//                               switchD_00530b11::caseD_e0
//                               switchD_00530b11::caseD_e1
//                               switchD_00530b11::caseD_e2
//                               switchD_00530b11::caseD_e3
//                               switchD_00530b11::caseD_e4
//                               switchD_00530b11::caseD_e5
//                               switchD_00530b11::caseD_14
//                              tworld.cpp:1606 (357)
//         005310d7     POP        EDI
//         005310d8     POP        ESI
//         005310d9     POP        EBP
//         005310da     POP        EBX
//         005310db     RET        0x8
    return;
}

void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info* param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall fill_in_score(TRIBE_World * this, TRIBE_Zone_High_Sc
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              TRIBE_Zone_Hig    Stack[0x4]:4   param_1                   XREF[2]:     0053129c(R), 00531330(R)
//              long              Stack[0x8]:4   param_2                   XREF[6]:     00531258(R), 005312b3(W), 005312d8(R), 005312dc(W),
//                                                                                     00531323(RW), 00531334(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00531252(W), 0053128f(W), 005312a0(R), 005312fb(R)
//              long              Stack[-0x8]:4  hi_player
//                               ?fill_in_score@TRIBE_World@@QAEXAAUTRIBE_Zone_High_Score_In  XREF[5]:     send_zone_score_info:0053140c(c),
//                               TRIBE_World::fill_in_score                                                send_zone_score_info:0053141d(c),
//                                                                                                         send_zone_score_info:0053142d(c),
//                                                                                                         send_zone_score_info:0053143f(c),
//                                                                                                         send_zone_score_info:00531450(c)
//                              tworld.cpp:1610 (7)
//         00531240     PUSH       this
//         00531241     PUSH       EBX
//         00531242     PUSH       EBP
//         00531243     PUSH       ESI
//         00531244     MOV        EBP,this
//         00531246     PUSH       EDI
//                              tworld.cpp:1613 (5)
//         00531247     MOV        ESI,0x1
//                              tworld.cpp:1614 (2)
//         0053124c     XOR        EDI,EDI
//                              tworld.cpp:1616 (10)
//         0053124e     CMP        word ptr [EBP + 0x3c],SI
//         00531252     MOV        dword ptr [ESP + local_4],ESI
//         00531256     JLE        LAB_0053129c
//                              tworld.cpp:1617 (19)
//         00531258     MOV        EBX,dword ptr [ESP + param_2]
//                               LAB_0053125c                                                 XREF[1]:     0053129a(j)
//         0053125c     MOV        EAX,dword ptr [EBP + 0x40]
//         0053125f     MOV        this,dword ptr [EAX + ESI*0x4]
//         00531262     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         00531267     TEST       EAX,EAX
//         00531269     JNZ        LAB_00531293
//                              tworld.cpp:1618 (19)
//         0053126b     MOV        this,dword ptr [EBP + 0x40]
//         0053126e     PUSH       EBX
//         0053126f     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         00531272     MOV        this,dword ptr [EDX + 0x34]
//         00531275     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         0053127a     CMP        EAX,EDI
//         0053127c     JLE        LAB_00531293
//                              tworld.cpp:1620 (17)
//         0053127e     MOV        EAX,dword ptr [EBP + 0x40]
//         00531281     PUSH       EBX
//         00531282     MOV        this,dword ptr [EAX + ESI*0x4]
//         00531285     MOV        this,dword ptr [ECX + this->_padding_]
//         00531288     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
//         0053128d     MOV        EDI,EAX
//                              tworld.cpp:1621 (13)
//         0053128f     MOV        dword ptr [ESP + local_4],ESI
//                               LAB_00531293                                                 XREF[2]:     00531269(j), 0053127c(j)
//         00531293     MOVSX      EDX,word ptr [EBP + 0x3c]
//         00531297     INC        ESI
//         00531298     CMP        ESI,EDX
//         0053129a     JL         LAB_0053125c
//                               LAB_0053129c                                                 XREF[1]:     00531256(j)
//                              tworld.cpp:1624 (4)
//         0053129c     MOV        EDX,dword ptr [ESP + param_1]
//                              tworld.cpp:1625 (16)
//         005312a0     MOV        EAX,dword ptr [ESP + local_4]
//         005312a4     MOV        dword ptr [EDX],EDI
//         005312a6     MOV        this,dword ptr [EBP + 0x40]
//         005312a9     LEA        EBX,[EAX*0x4 + 0x0]
//                              tworld.cpp:1626 (44)
//         005312b0     LEA        ESI,[EDX + 0x5]
//         005312b3     MOV        dword ptr [ESP + param_2],ESI
//         005312b7     MOV        EAX,dword ptr [this->_padding_ + EBX*0x1]
//         005312ba     MOV        this,byte ptr [EAX + 0x54]
//         005312bd     MOV        byte ptr [EDX + 0x4],this
//         005312c0     MOV        EAX,dword ptr [EBP + 0x40]
//         005312c3     MOV        this,dword ptr [EAX + EBX*0x1]
//         005312c6     XOR        EAX,EAX
//         005312c8     MOV        EDI,dword ptr [ECX + this->_padding_]
//         005312cb     OR         this,0xffffffff
//         005312ce     SCASB.RE   ES:EDI
//         005312d0     NOT        this
//         005312d2     SUB        EDI,this
//         005312d4     MOV        EAX,this
//         005312d6     MOV        ESI,EDI
//         005312d8     MOV        EDI,dword ptr [ESP + param_2]
//                              tworld.cpp:1629 (20)
//         005312dc     MOV        dword ptr [ESP + param_2],0x0
//         005312e4     SHR        this,0x2
//         005312e7     MOVSD.REP  ES:EDI,ESI
//         005312e9     MOV        this,EAX
//         005312eb     AND        this,0x3
//         005312ee     MOVSB.REP  ES:EDI,ESI
//                              tworld.cpp:1630 (11)
//         005312f0     MOV        ESI,0x1
//         005312f5     CMP        word ptr [EBP + 0x3c],SI
//         005312f9     JLE        LAB_00531334
//                               LAB_005312fb                                                 XREF[1]:     0053132e(j)
//                              tworld.cpp:1631 (8)
//         005312fb     MOV        EAX,dword ptr [ESP + local_4]
//         005312ff     CMP        ESI,EAX
//         00531301     JZ         LAB_00531327
//                              tworld.cpp:1633 (32)
//         00531303     MOV        this,dword ptr [EBP + 0x40]
//         00531306     PUSH       EAX
//         00531307     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         0053130a     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         0053130f     TEST       AL,AL
//         00531311     JNZ        LAB_00531327
//         00531313     MOV        EDX,dword ptr [EBP + 0x40]
//         00531316     PUSH       ESI
//         00531317     MOV        this,dword ptr [EDX + EBX*0x1]
//         0053131a     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         0053131f     TEST       AL,AL
//         00531321     JNZ        LAB_00531327
//                              tworld.cpp:1634 (13)
//         00531323     INC        dword ptr [ESP + param_2]
//                               LAB_00531327                                                 XREF[3]:     00531301(j), 00531311(j),
//                                                                                                         00531321(j)
//         00531327     MOVSX      EAX,word ptr [EBP + 0x3c]
//         0053132b     INC        ESI
//         0053132c     CMP        ESI,EAX
//         0053132e     JL         LAB_005312fb
//                              tworld.cpp:1630 (4)
//         00531330     MOV        EDX,dword ptr [ESP + param_1]
//                               LAB_00531334                                                 XREF[1]:     005312f9(j)
//                              tworld.cpp:1636 (4)
//         00531334     MOV        this,byte ptr [ESP + param_2]
//                              tworld.cpp:1637 (11)
//         00531338     POP        EDI
//         00531339     POP        ESI
//         0053133a     POP        EBP
//         0053133b     MOV        byte ptr [EDX + 0x15],this
//         0053133e     POP        EBX
//         0053133f     POP        this
//         00531340     RET        0x8
//         00531343     ??         90h
//         00531344     NOP
//         00531345     NOP
//         00531346     NOP
//         00531347     NOP
//         00531348     NOP
//         00531349     NOP
//         0053134a     NOP
//         0053134b     NOP
//         0053134c     NOP
//         0053134d     NOP
//         0053134e     NOP
//         0053134f     NOP
    return;
}

void TRIBE_World::send_zone_score_info() {
    /* TODO: Stub */
//                              void __thiscall send_zone_score_info(TRIBE_World * this)
//              void              <VOID>         <RETURN>
//              TRIBE_World *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0053169d(W)
//              TRIBE_Zone_Info   Stack[-0x200   info                      XREF[0,50]:  0053165f(R), 0053166d(R), 00531379(W), 0053139c(RW),
//                                                                                     00531680(*), 005313b9(W), 005313cc(*), 00531405(W),
//                                                                                     005313f8(*), 00531411(*), 00531422(*), 00531434(*),
//                                                                                     00531444(*), 00531471(*), 00531466(*), 005314b0(*),
//                                                                                     005314d0(W), 005314de(W), 005314e9(W), 005314f8(W)
//              TRIBE_Game_Opt    Stack[-0x26c   options                   XREF[2,8]:   00531474(W), 0053148d(R), 005315fd(*), 00531607(R),
//                                                                                     0053160b(R), 0053160f(R), 0053163b(R), 00531630(R),
//                                                                                     00531625(R), 0053161a(R)
//              undefined4        Stack[-0x270   local_270                 XREF[8]:     00531381(W), 005313a5(RW), 005313b2(R), 00531459(W),
//                                                                                     0053146d(R), 0053149d(R), 005314ac(R), 00531568(W)
//              long              Stack[-0x274   count
//                               ?send_zone_score_info@TRIBE_World@@QAEXXZ                    XREF[4]:     DoCycle:00426bda(c),
//                               TRIBE_World::send_zone_score_info                                         DropDeadPlayer:00428bd3(c),
//                                                                                                         handle_game_update:00496a5b(c),
//                                                                                                         quit_game:0052418f(c)
//                              tworld.cpp:1641 (9)
//         00531350     SUB        ESP,0x270
//         00531356     PUSH       EBX
//         00531357     MOV        EBX,this
//                              tworld.cpp:1646 (17)
//         00531359     MOV        EAX,dword ptr [EBX + 0x120]
//         0053135f     TEST       EAX,EAX
//         00531361     JNZ        LAB_005316b5
//         00531367     PUSH       EDI
//         00531368     PUSH       ESI
//         00531369     PUSH       EBP
//                              tworld.cpp:1649 (5)
//         0053136a     MOV        EBP,0x1
//                              tworld.cpp:1657 (30)
//         0053136f     CMP        word ptr [EBX + 0x3c],BP
//         00531373     MOV        dword ptr [EBX + 0x120],EBP
//         00531379     MOV        byte ptr [ESP + info+0x4],0x0
//         00531381     MOV        dword ptr [ESP + local_270],0x0
//         00531389     MOV        ESI,EBP
//         0053138b     JLE        LAB_005313b2
//                               LAB_0053138d                                                 XREF[1]:     005313b0(j)
//                              tworld.cpp:1659 (15)
//         0053138d     MOV        EAX,dword ptr [EBX + 0x40]
//         00531390     MOV        this,dword ptr [EAX + ESI*0x4]
//         00531393     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         00531398     TEST       EAX,EAX
//         0053139a     JNZ        LAB_005313a5
//                              tworld.cpp:1660 (7)
//         0053139c     INC        byte ptr [ESP + info+0x4]
//                              tworld.cpp:1661 (2)
//         005313a3     JMP        LAB_005313a9
//                               LAB_005313a5                                                 XREF[1]:     0053139a(j)
//                              tworld.cpp:1662 (13)
//         005313a5     INC        dword ptr [ESP + local_270]
//                               LAB_005313a9                                                 XREF[1]:     005313a3(j)
//         005313a9     MOVSX      this,word ptr [EBX + 0x3c]
//         005313ad     INC        ESI
//         005313ae     CMP        ESI,this
//         005313b0     JL         LAB_0053138d
//                               LAB_005313b2                                                 XREF[1]:     0053138b(j)
//                              tworld.cpp:1664 (4)
//         005313b2     MOV        DL,byte ptr [ESP + local_270]
//                              tworld.cpp:1667 (35)
//         005313b6     MOV        this,dword ptr [EBX + 0x5c]
//         005313b9     MOV        byte ptr [ESP + info+0x5],DL
//         005313c0     CALL       RGE_Scenario::Get_scenario_name                  char * Get_scenario_name(RGE_Scenario * this)
//         005313c5     MOV        EDI,EAX
//         005313c7     OR         this,0xffffffff
//         005313ca     XOR        EAX,EAX
//         005313cc     LEA        EDX=>info+0x6,[ESP + 0x86]
//         005313d3     SCASB.RE   ES:EDI
//         005313d5     NOT        this
//         005313d7     SUB        EDI,this
//                              tworld.cpp:1673 (56)
//         005313d9     PUSH       0xff
//         005313de     MOV        EAX,this
//         005313e0     MOV        ESI,EDI
//         005313e2     MOV        EDI,EDX
//         005313e4     SHR        this,0x2
//         005313e7     MOVSD.REP  ES:EDI,ESI
//         005313e9     MOV        this,EAX
//         005313eb     MOV        EAX,0x10624dd3
//         005313f0     MUL        dword ptr [EBX + 0x4]
//         005313f3     AND        this,0x3
//         005313f6     MOVSB.REP  ES:EDI,ESI
//         005313f8     LEA        this=>info+0x2c,[ESP + 0xb0]
//         005313ff     SHR        EDX,0x6
//         00531402     PUSH       this
//         00531403     MOV        this,EBX
//         00531405     MOV        dword ptr [ESP + info.total_score.score],EDX
//         0053140c     CALL       TRIBE_World::fill_in_score                       void fill_in_score(TRIBE_World * this, TRIBE_
//                              tworld.cpp:1674 (17)
//         00531411     LEA        EDX=>info+0x44,[ESP + 0xc4]
//         00531418     PUSH       0x2
//         0053141a     PUSH       EDX
//         0053141b     MOV        this,EBX
//         0053141d     CALL       TRIBE_World::fill_in_score                       void fill_in_score(TRIBE_World * this, TRIBE_
//                              tworld.cpp:1675 (16)
//         00531422     LEA        EAX=>info+0x5c,[ESP + 0xdc]
//         00531429     PUSH       EBP
//         0053142a     PUSH       EAX
//         0053142b     MOV        this,EBX
//         0053142d     CALL       TRIBE_World::fill_in_score                       void fill_in_score(TRIBE_World * this, TRIBE_
//                              tworld.cpp:1676 (18)
//         00531432     XOR        ESI,ESI
//         00531434     LEA        this=>info+0x74,[ESP + 0xf4]
//         0053143b     PUSH       ESI
//         0053143c     PUSH       this
//         0053143d     MOV        this,EBX
//         0053143f     CALL       TRIBE_World::fill_in_score                       void fill_in_score(TRIBE_World * this, TRIBE_
//                              tworld.cpp:1677 (17)
//         00531444     LEA        EDX=>info+0x8c,[ESP + 0x10c]
//         0053144b     PUSH       0x3
//         0053144d     PUSH       EDX
//         0053144e     MOV        this,EBX
//         00531450     CALL       TRIBE_World::fill_in_score                       void fill_in_score(TRIBE_World * this, TRIBE_
//                              tworld.cpp:1679 (14)
//         00531455     CMP        word ptr [EBX + 0x3c],BP
//         00531459     MOV        dword ptr [ESP + local_270],EBP
//         0053145d     JLE        LAB_00531574
//                              tworld.cpp:1682 (73)
//         00531463     MOV        EDX,dword ptr [EBX + 0x40]
//         00531466     LEA        EBP=>info+0xb4,[ESP + 0x134]
//                               LAB_0053146d                                                 XREF[1]:     0053156c(j)
//         0053146d     MOV        EAX,dword ptr [ESP + local_270]
//         00531471     LEA        ESI=>info+0xa4,[EBP + -0x10]
//         00531474     MOV        dword ptr [ESP + options.mapSizeValue],ESI
//         00531478     MOV        this,dword ptr [EDX + EAX*0x4]
//         0053147b     XOR        EAX,EAX
//         0053147d     MOV        EDI,dword ptr [ECX + this->_padding_]
//         00531480     OR         this,0xffffffff
//         00531483     SCASB.RE   ES:EDI
//         00531485     NOT        this
//         00531487     SUB        EDI,this
//         00531489     MOV        EAX,this
//         0053148b     MOV        ESI,EDI
//         0053148d     MOV        EDI,dword ptr [ESP + options.mapSizeValue]
//         00531491     SHR        this,0x2
//         00531494     MOVSD.REP  ES:EDI,ESI
//         00531496     MOV        this,EAX
//         00531498     AND        this,0x3
//         0053149b     MOVSB.REP  ES:EDI,ESI
//         0053149d     MOV        this,dword ptr [ESP + local_270]
//         005314a1     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         005314a4     MOV        this,dword ptr [EDX + 0x34]
//         005314a7     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
//                              tworld.cpp:1683 (12)
//         005314ac     MOV        EDI,dword ptr [ESP + local_270]
//         005314b0     MOV        dword ptr [EBP]=>info+0xb4,EAX
//         005314b3     MOV        EAX,dword ptr [EBX + 0x40]
//         005314b6     XOR        EDX,EDX
//                              tworld.cpp:1685 (32)
//         005314b8     LEA        ESI,[EDI + -0x1]
//         005314bb     MOV        this,dword ptr [EAX + EDI*0x4]
//         005314be     PUSH       ESI
//         005314bf     MOV        AL,byte ptr [ECX + this->_padding_]
//         005314c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005314cb     CMP        AL,0x1
//         005314cd     SETZ       DL
//         005314d0     MOV        byte ptr [EBP + info+0xb8],DL
//         005314d3     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//                              tworld.cpp:1686 (9)
//         005314d8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005314de     MOV        byte ptr [EBP + info+0xb9],AL
//                              tworld.cpp:1687 (16)
//         005314e1     PUSH       ESI
//         005314e2     MOV        AL,byte ptr [this->_padding_ + EDI*0x4 + 0xa54]
//         005314e9     MOV        byte ptr [EBP + info+0xba],AL
//         005314ec     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//                              tworld.cpp:1688 (15)
//         005314f1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005314f7     PUSH       ESI
//         005314f8     MOV        byte ptr [EBP + info+0xbb],AL
//         005314fb     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//                              tworld.cpp:1690 (6)
//         00531500     MOV        this,dword ptr [comm]                            = 00000000
//                              tworld.cpp:1698 (40)
//         00531506     MOV        EDX,dword ptr [EBX + 0x40]
//         00531509     MOV        byte ptr [EBP + info+0xbc],AL
//         0053150c     MOV        EAX,dword ptr [this->_padding_ + EDI*0x4 + 0x1
//         00531513     MOV        byte ptr [EBP + info+0xbd],AL
//         00531516     OR         EAX,0xffffffff
//         00531519     MOV        dword ptr [EBP + info+0xc0],EAX
//         0053151c     MOV        dword ptr [EBP + info+0xc4],EAX
//         0053151f     MOV        dword ptr [EBP + info+0xc8],EAX
//         00531522     MOV        EAX,dword ptr [EDX + EDI*0x4]
//         00531525     MOV        this,dword ptr [EAX + 0x83c]
//         0053152b     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              tworld.cpp:1699 (4)
//         0053152e     TEST       EAX,EAX
//         00531530     JZ         LAB_0053155e
//                               LAB_00531532                                                 XREF[1]:     0053155c(j)
//                              tworld.cpp:1701 (15)
//         00531532     XOR        this,this
//         00531534     MOV        this,byte ptr [EAX]
//         00531536     SUB        this,0x0
//         00531539     JZ         LAB_00531551
//         0053153b     DEC        this
//         0053153c     JZ         LAB_00531549
//         0053153e     DEC        this
//         0053153f     JNZ        LAB_00531557
//                              tworld.cpp:1710 (6)
//         00531541     MOV        this,dword ptr [EAX + 0x8]
//         00531544     MOV        dword ptr [EBP + info+0xc8],this
//                              tworld.cpp:1711 (2)
//         00531547     JMP        LAB_00531557
//                               LAB_00531549                                                 XREF[1]:     0053153c(j)
//                              tworld.cpp:1707 (6)
//         00531549     MOV        this,dword ptr [EAX + 0x8]
//         0053154c     MOV        dword ptr [EBP + info+0xc4],this
//                              tworld.cpp:1708 (2)
//         0053154f     JMP        LAB_00531557
//                               LAB_00531551                                                 XREF[1]:     00531539(j)
//                              tworld.cpp:1704 (6)
//         00531551     MOV        this,dword ptr [EAX + 0x8]
//         00531554     MOV        dword ptr [EBP + info+0xc0],this
//                               LAB_00531557                                                 XREF[3]:     0053153f(j), 00531547(j),
//                                                                                                         0053154f(j)
//                              tworld.cpp:1715 (7)
//         00531557     MOV        EAX,dword ptr [EAX + 0xc]
//         0053155a     TEST       EAX,EAX
//         0053155c     JNZ        LAB_00531532
//                               LAB_0053155e                                                 XREF[1]:     00531530(j)
//                              tworld.cpp:1679 (22)
//         0053155e     MOVSX      EAX,word ptr [EBX + 0x3c]
//         00531562     INC        EDI
//         00531563     ADD        EBP,0x28
//         00531566     CMP        EDI,EAX
//         00531568     MOV        dword ptr [ESP + local_270],EDI
//         0053156c     JL         LAB_0053146d
//         00531572     XOR        ESI,ESI
//                               LAB_00531574                                                 XREF[1]:     0053145d(j)
//                              tworld.cpp:1720 (18)
//         00531574     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053157a     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//         0053157f     MOV        byte ptr [ESP + info.database_checksum],AL
//                              tworld.cpp:1722 (25)
//         00531586     XOR        EAX,EAX
//         00531588     MOV        AL,byte ptr [EBX + 0x1e]
//         0053158b     CMP        EAX,0x68
//         0053158e     JA         switchD_00531598::caseD_3
//         00531590     XOR        this,this
//         00531592     MOV        this,byte ptr [EAX + switchD_00531598::switchd
//                               switchD_00531598::switchD
//         00531598     JMP        dword ptr [this->_padding_*0x4 + switchD_00531   = 0053159f
//                               switchD_00531598::caseD_0                                    XREF[2]:     00531598(j), 005316c0(*)
//                              tworld.cpp:1724 (10)
//         0053159f     MOV        byte ptr [ESP + info+0x1f1],0x0
//         005315a7     JMP        LAB_005315f7
//                               switchD_00531598::caseD_1                                    XREF[2]:     00531598(j), 005316c4(*)
//                              tworld.cpp:1725 (10)
//         005315a9     MOV        byte ptr [ESP + info+0x1f1],0x1
//         005315b1     JMP        LAB_005315f7
//                               switchD_00531598::caseD_64                                   XREF[2]:     00531598(j), 005316cc(*)
//                              tworld.cpp:1726 (10)
//         005315b3     MOV        byte ptr [ESP + info+0x1f1],0x2
//         005315bb     JMP        LAB_005315f7
//                               switchD_00531598::caseD_65                                   XREF[2]:     00531598(j), 005316d0(*)
//                              tworld.cpp:1727 (10)
//         005315bd     MOV        byte ptr [ESP + info+0x1f1],0x3
//         005315c5     JMP        LAB_005315f7
//                               switchD_00531598::caseD_66                                   XREF[2]:     00531598(j), 005316d4(*)
//                              tworld.cpp:1728 (10)
//         005315c7     MOV        byte ptr [ESP + info+0x1f1],0x4
//         005315cf     JMP        LAB_005315f7
//                               switchD_00531598::caseD_67                                   XREF[2]:     00531598(j), 005316d8(*)
//                              tworld.cpp:1729 (10)
//         005315d1     MOV        byte ptr [ESP + info+0x1f1],0x5
//         005315d9     JMP        LAB_005315f7
//                               switchD_00531598::caseD_2                                    XREF[2]:     00531598(j), 005316c8(*)
//                              tworld.cpp:1730 (10)
//         005315db     MOV        byte ptr [ESP + info+0x1f1],0x6
//         005315e3     JMP        LAB_005315f7
//                               switchD_00531598::caseD_68                                   XREF[2]:     00531598(j), 005316dc(*)
//                              tworld.cpp:1731 (10)
//         005315e5     MOV        byte ptr [ESP + info+0x1f1],0x7
//         005315ed     JMP        LAB_005315f7
//                               switchD_00531598::caseD_4                                    XREF[3]:     0053158e(j), 00531598(j),
//                               switchD_00531598::caseD_5                                                 005316e0(*)
//                               switchD_00531598::caseD_6
//                               switchD_00531598::caseD_7
//                               switchD_00531598::caseD_8
//                               switchD_00531598::caseD_9
//                               switchD_00531598::caseD_a
//                               switchD_00531598::caseD_b
//                               switchD_00531598::caseD_c
//                               switchD_00531598::caseD_d
//                               switchD_00531598::caseD_e
//                               switchD_00531598::caseD_f
//                               switchD_00531598::caseD_10
//                               switchD_00531598::caseD_11
//                               switchD_00531598::caseD_12
//                               switchD_00531598::caseD_13
//                               switchD_00531598::caseD_14
//                               switchD_00531598::caseD_15
//                               switchD_00531598::caseD_16
//                               switchD_00531598::caseD_17
//                               switchD_00531598::caseD_18
//                               switchD_00531598::caseD_19
//                               switchD_00531598::caseD_1a
//                               switchD_00531598::caseD_1b
//                               switchD_00531598::caseD_1c
//                               switchD_00531598::caseD_1d
//                               switchD_00531598::caseD_1e
//                               switchD_00531598::caseD_1f
//                               switchD_00531598::caseD_20
//                               switchD_00531598::caseD_21
//                               switchD_00531598::caseD_22
//                               switchD_00531598::caseD_23
//                               switchD_00531598::caseD_24
//                               switchD_00531598::caseD_25
//                               switchD_00531598::caseD_26
//                               switchD_00531598::caseD_27
//                               switchD_00531598::caseD_28
//                               switchD_00531598::caseD_29
//                               switchD_00531598::caseD_2a
//                               switchD_00531598::caseD_2b
//                               switchD_00531598::caseD_2c
//                               switchD_00531598::caseD_2d
//                               switchD_00531598::caseD_2e
//                               switchD_00531598::caseD_2f
//                               switchD_00531598::caseD_30
//                               switchD_00531598::caseD_31
//                               switchD_00531598::caseD_32
//                               switchD_00531598::caseD_33
//                               switchD_00531598::caseD_34
//                               switchD_00531598::caseD_35
//                               switchD_00531598::caseD_36
//                               switchD_00531598::caseD_37
//                               switchD_00531598::caseD_38
//                               switchD_00531598::caseD_39
//                               switchD_00531598::caseD_3a
//                               switchD_00531598::caseD_3b
//                               switchD_00531598::caseD_3c
//                               switchD_00531598::caseD_3d
//                               switchD_00531598::caseD_3e
//                               switchD_00531598::caseD_3f
//                               switchD_00531598::caseD_40
//                               switchD_00531598::caseD_41
//                               switchD_00531598::caseD_42
//                               switchD_00531598::caseD_43
//                               switchD_00531598::caseD_44
//                               switchD_00531598::caseD_45
//                               switchD_00531598::caseD_46
//                               switchD_00531598::caseD_47
//                               switchD_00531598::caseD_48
//                               switchD_00531598::caseD_49
//                               switchD_00531598::caseD_4a
//                               switchD_00531598::caseD_4b
//                               switchD_00531598::caseD_4c
//                               switchD_00531598::caseD_4d
//                               switchD_00531598::caseD_4e
//                               switchD_00531598::caseD_4f
//                               switchD_00531598::caseD_50
//                               switchD_00531598::caseD_51
//                               switchD_00531598::caseD_52
//                               switchD_00531598::caseD_53
//                               switchD_00531598::caseD_54
//                               switchD_00531598::caseD_55
//                               switchD_00531598::caseD_56
//                               switchD_00531598::caseD_57
//                               switchD_00531598::caseD_58
//                               switchD_00531598::caseD_59
//                               switchD_00531598::caseD_5a
//                               switchD_00531598::caseD_5b
//                               switchD_00531598::caseD_5c
//                               switchD_00531598::caseD_5d
//                               switchD_00531598::caseD_5e
//                               switchD_00531598::caseD_5f
//                               switchD_00531598::caseD_60
//                               switchD_00531598::caseD_61
//                               switchD_00531598::caseD_62
//                               switchD_00531598::caseD_63
//                               switchD_00531598::caseD_3
//                              tworld.cpp:1732 (8)
//         005315ef     MOV        byte ptr [ESP + info+0x1f1],0x8
//                               LAB_005315f7                                                 XREF[8]:     005315a7(j), 005315b1(j),
//                                                                                                         005315bb(j), 005315c5(j),
//                                                                                                         005315cf(j), 005315d9(j),
//                                                                                                         005315e3(j), 005315ed(j)
//                              tworld.cpp:1737 (16)
//         005315f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005315fd     LEA        EDX=>options.mapTypeValue,[ESP + 0x18]
//         00531601     PUSH       EDX
//         00531602     CALL       TRIBE_Game::get_tribe_options                    void get_tribe_options(TRIBE_Game * this, TRI
//                              tworld.cpp:1739 (4)
//         00531607     MOV        AL,byte ptr [ESP + options.mapTypeValue]
//                              tworld.cpp:1740 (4)
//         0053160b     MOV        this,byte ptr [ESP + options.animalsValue]
//                              tworld.cpp:1741 (11)
//         0053160f     MOV        DL,byte ptr [ESP + options.victoryAmountValue]
//         00531613     MOV        byte ptr [ESP + info+0x1e4],AL
//                              tworld.cpp:1742 (11)
//         0053161a     MOV        AL,byte ptr [ESP + options.startingUnitsValue]
//         0053161e     MOV        byte ptr [ESP + info+0x1e5],this
//                              tworld.cpp:1743 (11)
//         00531625     MOV        this,byte ptr [ESP + options.startingAgeValue]
//         00531629     MOV        byte ptr [ESP + info+0x1e8],DL
//                              tworld.cpp:1744 (11)
//         00531630     MOV        DL,byte ptr [ESP + options+0x61]
//         00531634     MOV        byte ptr [ESP + info+0x1e9],AL
//                              tworld.cpp:1745 (11)
//         0053163b     MOV        AL,byte ptr [ESP + options.resourceLevelValue]
//         0053163f     MOV        byte ptr [ESP + info+0x1ea],this
//                              tworld.cpp:1746 (25)
//         00531646     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053164c     MOV        byte ptr [ESP + info+0x1eb],DL
//         00531653     MOV        byte ptr [ESP + info.cheats_enabled],AL
//         0053165a     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//                              tworld.cpp:1747 (14)
//         0053165f     MOV        this,byte ptr [ESP + info.number_of_computer_p
//         00531666     MOV        byte ptr [ESP + info.game_end_condition_code],AL
//                              tworld.cpp:1748 (16)
//         0053166d     MOVZX      DX,byte ptr [ESP + info.scenario_name[0]]
//         00531676     MOV        byte ptr [ESP + info+0x1ee],this
//                              tworld.cpp:1756 (56)
//         0053167d     MOV        this,dword ptr [EBX + 0x58]
//         00531680     LEA        EAX=>info+0x4,[ESP + 0x84]
//         00531687     MOV        word ptr [ESP + info+0x1e6],DX
//         0053168f     MOV        dword ptr [ESP + info.code_checksum],ESI
//         00531696     MOV        dword ptr [ESP + info.program_version],ESI
//         0053169d     MOV        dword ptr [ESP + local_4],ESI
//         005316a4     MOV        this,dword ptr [ECX + this->_padding_]
//         005316a7     PUSH       0x1fc
//         005316ac     PUSH       EAX
//         005316ad     CALL       TCommunications_Handler::SendZoneMessage         int SendZoneMessage(TCommunications_Handler *
//         005316b2     POP        EBP
//         005316b3     POP        ESI
//         005316b4     POP        EDI
//                               LAB_005316b5                                                 XREF[1]:     00531361(j)
//                              tworld.cpp:1757 (152)
//         005316b5     POP        EBX
//         005316b6     ADD        ESP,0x270
//         005316bc     RET
    return;
}

