#include "common.h"
#include "World.h"

void RGE_Game_World::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall logStatus(RGE_Game_World * this, _iobuf * param_1, i
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?logStatus@RGE_Game_World@@MAEXPAU_iobuf@@H@Z                XREF[1]:     005779ac(*)  
    //                               RGE_Game_World::logStatus
    //                              world.h:107 (3)
    //         00540a10     RET        0x8
    //         00540a13     ??         90h
    //         00540a14     NOP
    //         00540a15     NOP
    //         00540a16     NOP
    //         00540a17     NOP
    //         00540a18     NOP
    //         00540a19     NOP
    //         00540a1a     NOP
    //         00540a1b     NOP
    //         00540a1c     NOP
    //         00540a1d     NOP
    //         00540a1e     NOP
    //         00540a1f     NOP
    return;
}

RGE_Game_World::RGE_Game_World() {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Game_World(RGE_Game_World * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[13]:    005408a4(W), 005408b7(W), 005408cf(W), 005408e6(W), 
    //                                                                                     005408fe(W), 00540915(W), 0054092d(W), 00540944(W), 
    //                                                                                     0054095c(W), 00540973(W), 0054098b(W), 005409a2(W), 
    //                                                                                     005409ba(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005409f7(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[7]:     0054089e(W), 005408c9(W), 005408f8(W), 00540927(W), 
    //                                                                                     00540956(W), 00540985(W), 005409b4(W)  
    //                               ??0RGE_Game_World@@QAE@XZ                                    XREF[2]:     create_world:00420085(c), 
    //                               RGE_Game_World::RGE_Game_World                                            TRIBE_World:0052df80(c)  
    //                              World.cpp:138 (111)
    //         00540750     PUSH       -0x1
    //         00540752     PUSH       FUN_00561c0d
    //         00540757     MOV        EAX,FS:[0x0]
    //         0054075d     PUSH       EAX
    //         0054075e     MOV        dword ptr FS:[0x0],ESP
    //         00540765     PUSH       this
    //         00540766     PUSH       EBX
    //         00540767     PUSH       EBP
    //         00540768     PUSH       ESI
    //         00540769     MOV        ESI,this
    //         0054076b     XOR        EBX,EBX
    //         0054076d     MOV        EAX,0x2
    //         00540772     MOV        dword ptr [ESI + 0x88],EBX
    //         00540778     MOV        dword ptr [ESI + 0x8c],EBX
    //         0054077e     MOV        dword ptr [ESI + 0x90],0x2710
    //         00540788     MOV        dword ptr [ESI + 0x94],EBX
    //         0054078e     MOV        dword ptr [ESI + 0x98],EBX
    //         00540794     MOV        dword ptr [ESI + 0x9c],0x3e8
    //         0054079e     MOV        dword ptr [ESI + 0xf4],EAX
    //         005407a4     OR         EBP,0xffffffff
    //         005407a7     MOV        dword ptr [ESI + 0xf8],EAX
    //         005407ad     MOV        dword ptr [ESI + 0xfc],EBP
    //         005407b3     MOV        dword ptr [ESI + 0x100],EBP
    //         005407b9     MOV        dword ptr [ESI],RGE_Game_World::`vftable'        = 005415b0
    //                              World.cpp:140 (6)
    //         005407bf     MOV        dword ptr [world_update_counter],EBX
    //                              World.cpp:143 (22)
    //         005407c5     MOV        EAX,dword ptr [ESI + 0x90]
    //         005407cb     SHL        EAX,0x2
    //         005407ce     PUSH       EDI
    //         005407cf     PUSH       EAX
    //         005407d0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005407d5     MOV        dword ptr [ESI + 0x88],EAX
    //                              World.cpp:148 (24)
    //         005407db     MOV        this,dword ptr [ESI + 0x9c]
    //         005407e1     ADD        ESP,0x4
    //         005407e4     SHL        this,0x2
    //         005407e7     PUSH       this
    //         005407e8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005407ed     MOV        dword ptr [ESI + 0x94],EAX
    //                              World.cpp:152 (12)
    //         005407f3     MOV        EDX,dword ptr [ESI + 0x88]
    //         005407f9     MOV        dword ptr [VIS_UNIT_objectsValue],EDX            = 00000000
    //                              World.cpp:154 (6)
    //         005407ff     MOV        dword ptr [ESI + 0xa0],EBX
    //                              World.cpp:156 (4)
    //         00540805     MOV        word ptr [ESI + 0x2c],BX
    //                              World.cpp:157 (3)
    //         00540809     MOV        dword ptr [ESI + 0x30],EBX
    //                              World.cpp:159 (4)
    //         0054080c     MOV        word ptr [ESI + 0x34],BX
    //                              World.cpp:160 (3)
    //         00540810     MOV        dword ptr [ESI + 0x38],EBX
    //                              World.cpp:162 (4)
    //         00540813     MOV        word ptr [ESI + 0x3c],BX
    //                              World.cpp:163 (3)
    //         00540817     MOV        dword ptr [ESI + 0x40],EBX
    //                              World.cpp:165 (4)
    //         0054081a     MOV        word ptr [ESI + 0x44],BX
    //                              World.cpp:166 (6)
    //         0054081e     MOV        dword ptr [ESI + 0x48],EBX
    //         00540821     ADD        ESP,0x4
    //                              World.cpp:168 (4)
    //         00540824     MOV        word ptr [ESI + 0x50],BX
    //                              World.cpp:169 (9)
    //         00540828     MOV        dword ptr [ESI + 0x54],EBX
    //         0054082b     LEA        EDI,[ESI + 0xb4]
    //                              World.cpp:201 (99)
    //         00540831     MOV        this,0x9
    //         00540836     XOR        EAX,EAX
    //         00540838     MOV        word ptr [ESI + 0x60],BX
    //         0054083c     MOV        dword ptr [ESI + 0x64],EBX
    //         0054083f     MOV        dword ptr [ESI + 0x58],EBX
    //         00540842     MOV        dword ptr [ESI + 0x5c],EBX
    //         00540845     MOV        dword ptr [ESI + 0x4c],EBX
    //         00540848     MOV        dword ptr [ESI + 0x28],EBX
    //         0054084b     MOV        dword ptr [ESI + 0x4],EBX
    //         0054084e     MOV        dword ptr [ESI + 0x8],EBX
    //         00540851     MOV        dword ptr [ESI + 0xc],EBX
    //         00540854     MOV        dword ptr [ESI + 0x84],EBX
    //         0054085a     MOV        dword ptr [ESI + 0x10],EBX
    //         0054085d     MOV        dword ptr [ESI + 0x14],EBX
    //         00540860     MOV        dword ptr [ESI + 0x18],EBX
    //         00540863     MOV        byte ptr [ESI + 0x1c],BL
    //         00540866     MOV        dword ptr [ESI + 0x68],EBX
    //         00540869     MOV        dword ptr [ESI + 0x6c],EBP
    //         0054086c     MOV        dword ptr [ESI + 0x78],0xe
    //         00540873     MOV        word ptr [ESI + 0x7c],0x1
    //         00540879     MOV        dword ptr [ESI + 0x80],EBX
    //         0054087f     MOV        byte ptr [ESI + 0x1d],0x2
    //         00540883     MOV        byte ptr [ESI + 0x1e],BL
    //         00540886     MOV        dword ptr [ESI + 0x20],EBX
    //         00540889     MOV        dword ptr [ESI + 0x24],EBX
    //         0054088c     MOV        dword ptr [ESI + 0xb0],EBX
    //         00540892     STOSD.REP  ES:EDI
    //                              World.cpp:203 (33)
    //         00540894     PUSH       0xc
    //         00540896     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054089b     ADD        ESP,0x4
    //         0054089e     MOV        dword ptr [ESP + local_10],EAX
    //         005408a2     CMP        EAX,EBX
    //         005408a4     MOV        dword ptr [ESP + local_4],EBX
    //         005408a8     JZ         LAB_005408b3
    //         005408aa     MOV        this,EAX
    //         005408ac     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         005408b1     JMP        LAB_005408b5
    //                               LAB_005408b3                                                 XREF[1]:     005408a8(j)  
    //         005408b3     XOR        EAX,EAX
    //                               LAB_005408b5                                                 XREF[1]:     005408b1(j)  
    //                              World.cpp:204 (47)
    //         005408b5     PUSH       0xc
    //         005408b7     MOV        dword ptr [ESP + local_4],EBP
    //         005408bb     MOV        dword ptr [ESI + 0xd8],EAX
    //         005408c1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005408c6     ADD        ESP,0x4
    //         005408c9     MOV        dword ptr [ESP + local_10],EAX
    //         005408cd     CMP        EAX,EBX
    //         005408cf     MOV        dword ptr [ESP + local_4],0x1
    //         005408d7     JZ         LAB_005408e2
    //         005408d9     MOV        this,EAX
    //         005408db     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         005408e0     JMP        LAB_005408e4
    //                               LAB_005408e2                                                 XREF[1]:     005408d7(j)  
    //         005408e2     XOR        EAX,EAX
    //                               LAB_005408e4                                                 XREF[1]:     005408e0(j)  
    //                              World.cpp:205 (47)
    //         005408e4     PUSH       0xc
    //         005408e6     MOV        dword ptr [ESP + local_4],EBP
    //         005408ea     MOV        dword ptr [ESI + 0xdc],EAX
    //         005408f0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005408f5     ADD        ESP,0x4
    //         005408f8     MOV        dword ptr [ESP + local_10],EAX
    //         005408fc     CMP        EAX,EBX
    //         005408fe     MOV        dword ptr [ESP + local_4],0x2
    //         00540906     JZ         LAB_00540911
    //         00540908     MOV        this,EAX
    //         0054090a     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         0054090f     JMP        LAB_00540913
    //                               LAB_00540911                                                 XREF[1]:     00540906(j)  
    //         00540911     XOR        EAX,EAX
    //                               LAB_00540913                                                 XREF[1]:     0054090f(j)  
    //                              World.cpp:206 (47)
    //         00540913     PUSH       0xc
    //         00540915     MOV        dword ptr [ESP + local_4],EBP
    //         00540919     MOV        dword ptr [ESI + 0xe0],EAX
    //         0054091f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00540924     ADD        ESP,0x4
    //         00540927     MOV        dword ptr [ESP + local_10],EAX
    //         0054092b     CMP        EAX,EBX
    //         0054092d     MOV        dword ptr [ESP + local_4],0x3
    //         00540935     JZ         LAB_00540940
    //         00540937     MOV        this,EAX
    //         00540939     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         0054093e     JMP        LAB_00540942
    //                               LAB_00540940                                                 XREF[1]:     00540935(j)  
    //         00540940     XOR        EAX,EAX
    //                               LAB_00540942                                                 XREF[1]:     0054093e(j)  
    //                              World.cpp:207 (47)
    //         00540942     PUSH       0xc
    //         00540944     MOV        dword ptr [ESP + local_4],EBP
    //         00540948     MOV        dword ptr [ESI + 0xe4],EAX
    //         0054094e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00540953     ADD        ESP,0x4
    //         00540956     MOV        dword ptr [ESP + local_10],EAX
    //         0054095a     CMP        EAX,EBX
    //         0054095c     MOV        dword ptr [ESP + local_4],0x4
    //         00540964     JZ         LAB_0054096f
    //         00540966     MOV        this,EAX
    //         00540968     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         0054096d     JMP        LAB_00540971
    //                               LAB_0054096f                                                 XREF[1]:     00540964(j)  
    //         0054096f     XOR        EAX,EAX
    //                               LAB_00540971                                                 XREF[1]:     0054096d(j)  
    //                              World.cpp:208 (47)
    //         00540971     PUSH       0xc
    //         00540973     MOV        dword ptr [ESP + local_4],EBP
    //         00540977     MOV        dword ptr [ESI + 0xe8],EAX
    //         0054097d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00540982     ADD        ESP,0x4
    //         00540985     MOV        dword ptr [ESP + local_10],EAX
    //         00540989     CMP        EAX,EBX
    //         0054098b     MOV        dword ptr [ESP + local_4],0x5
    //         00540993     JZ         LAB_0054099e
    //         00540995     MOV        this,EAX
    //         00540997     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         0054099c     JMP        LAB_005409a0
    //                               LAB_0054099e                                                 XREF[1]:     00540993(j)  
    //         0054099e     XOR        EAX,EAX
    //                               LAB_005409a0                                                 XREF[1]:     0054099c(j)  
    //                              World.cpp:209 (53)
    //         005409a0     PUSH       0xc
    //         005409a2     MOV        dword ptr [ESP + local_4],EBP
    //         005409a6     MOV        dword ptr [ESI + 0xec],EAX
    //         005409ac     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005409b1     ADD        ESP,0x4
    //         005409b4     MOV        dword ptr [ESP + local_10],EAX
    //         005409b8     CMP        EAX,EBX
    //         005409ba     MOV        dword ptr [ESP + local_4],0x6
    //         005409c2     JZ         LAB_005409cd
    //         005409c4     MOV        this,EAX
    //         005409c6     CALL       RGE_Object_List::RGE_Object_List                 undefined RGE_Object_List(RGE_Object_List * t
    //         005409cb     JMP        LAB_005409cf
    //                               LAB_005409cd                                                 XREF[1]:     005409c2(j)  
    //         005409cd     XOR        EAX,EAX
    //                               LAB_005409cf                                                 XREF[1]:     005409cb(j)  
    //         005409cf     MOV        dword ptr [ESI + 0xf0],EAX
    //                              World.cpp:211 (3)
    //         005409d5     MOV        byte ptr [ESI + 0x74],BL
    //                              World.cpp:215 (8)
    //         005409d8     CMP        dword ptr [DVlogf],EBX                           = 00000000
    //         005409de     JNZ        LAB_005409f7
    //                              World.cpp:217 (23)
    //         005409e0     PUSH       s_w                                              = "w"
    //         005409e5     PUSH       s_c:\aoeWVlog.txt                                = "c:\\aoeWVlog.txt"
    //         005409ea     CALL       fopen                                            undefined fopen()
    //         005409ef     ADD        ESP,0x8
    //         005409f2     MOV        [DVlogf],EAX                                     = 00000000
    //                               LAB_005409f7                                                 XREF[1]:     005409de(j)  
    //                              World.cpp:221 (21)
    //         005409f7     MOV        this,dword ptr [ESP + local_c]
    //         005409fb     MOV        EAX,ESI
    //         005409fd     POP        EDI
    //         005409fe     POP        ESI
    //         005409ff     POP        EBP
    //         00540a00     MOV        dword ptr FS:[0x0],this
    //         00540a07     POP        EBX
    //         00540a08     ADD        ESP,0x10
    //         00540a0b     RET
    //         00540a0c     ??         90h
    //         00540a0d     NOP
    //         00540a0e     NOP
    //         00540a0f     NOP
}

RGE_Game_World::~RGE_Game_World() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Game_World(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ??1RGE_Game_World@@UAE@XZ                                    XREF[2]:     ~TRIBE_World:0052e09a(c), 
    //                               RGE_Game_World::~RGE_Game_World                                           `scalar_deleting_destructor':00540
    //                              World.cpp:226 (5)
    //         00540a40     PUSH       EBX
    //         00540a41     PUSH       EBP
    //         00540a42     PUSH       ESI
    //         00540a43     MOV        ESI,this
    //                              World.cpp:229 (16)
    //         00540a45     XOR        EBP,EBP
    //         00540a47     PUSH       EDI
    //         00540a48     MOV        this,dword ptr [ESI + 0x58]
    //         00540a4b     MOV        dword ptr [ESI],RGE_Game_World::`vftable'        = 005415b0
    //         00540a51     CMP        this,EBP
    //         00540a53     JZ         LAB_00540a5c
    //                              World.cpp:230 (7)
    //         00540a55     MOV        EAX,dword ptr [this->_padding_]
    //         00540a57     PUSH       0x1
    //         00540a59     CALL       dword ptr [EAX + 0x4]
    //                               LAB_00540a5c                                                 XREF[1]:     00540a53(j)  
    //                              World.cpp:232 (7)
    //         00540a5c     MOV        this,ESI
    //         00540a5e     CALL       RGE_Game_World::del_game_info                    void del_game_info(RGE_Game_World * this)
    //                              World.cpp:235 (26)
    //         00540a63     MOV        EDI,dword ptr [ESI + 0xd8]
    //         00540a69     CMP        EDI,EBP
    //         00540a6b     JZ         LAB_00540a7d
    //         00540a6d     MOV        this,EDI
    //         00540a6f     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540a74     PUSH       EDI
    //         00540a75     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540a7a     ADD        ESP,0x4
    //                               LAB_00540a7d                                                 XREF[1]:     00540a6b(j)  
    //                              World.cpp:236 (26)
    //         00540a7d     MOV        EDI,dword ptr [ESI + 0xdc]
    //         00540a83     CMP        EDI,EBP
    //         00540a85     JZ         LAB_00540a97
    //         00540a87     MOV        this,EDI
    //         00540a89     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540a8e     PUSH       EDI
    //         00540a8f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540a94     ADD        ESP,0x4
    //                               LAB_00540a97                                                 XREF[1]:     00540a85(j)  
    //                              World.cpp:237 (26)
    //         00540a97     MOV        EDI,dword ptr [ESI + 0xe0]
    //         00540a9d     CMP        EDI,EBP
    //         00540a9f     JZ         LAB_00540ab1
    //         00540aa1     MOV        this,EDI
    //         00540aa3     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540aa8     PUSH       EDI
    //         00540aa9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540aae     ADD        ESP,0x4
    //                               LAB_00540ab1                                                 XREF[1]:     00540a9f(j)  
    //                              World.cpp:238 (26)
    //         00540ab1     MOV        EDI,dword ptr [ESI + 0xe4]
    //         00540ab7     CMP        EDI,EBP
    //         00540ab9     JZ         LAB_00540acb
    //         00540abb     MOV        this,EDI
    //         00540abd     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540ac2     PUSH       EDI
    //         00540ac3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540ac8     ADD        ESP,0x4
    //                               LAB_00540acb                                                 XREF[1]:     00540ab9(j)  
    //                              World.cpp:239 (26)
    //         00540acb     MOV        EDI,dword ptr [ESI + 0xe8]
    //         00540ad1     CMP        EDI,EBP
    //         00540ad3     JZ         LAB_00540ae5
    //         00540ad5     MOV        this,EDI
    //         00540ad7     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540adc     PUSH       EDI
    //         00540add     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540ae2     ADD        ESP,0x4
    //                               LAB_00540ae5                                                 XREF[1]:     00540ad3(j)  
    //                              World.cpp:240 (26)
    //         00540ae5     MOV        EDI,dword ptr [ESI + 0xec]
    //         00540aeb     CMP        EDI,EBP
    //         00540aed     JZ         LAB_00540aff
    //         00540aef     MOV        this,EDI
    //         00540af1     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540af6     PUSH       EDI
    //         00540af7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540afc     ADD        ESP,0x4
    //                               LAB_00540aff                                                 XREF[1]:     00540aed(j)  
    //                              World.cpp:241 (26)
    //         00540aff     MOV        EDI,dword ptr [ESI + 0xf0]
    //         00540b05     CMP        EDI,EBP
    //         00540b07     JZ         LAB_00540b19
    //         00540b09     MOV        this,EDI
    //         00540b0b     CALL       RGE_Object_List::~RGE_Object_List                void ~RGE_Object_List(RGE_Object_List * this)
    //         00540b10     PUSH       EDI
    //         00540b11     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540b16     ADD        ESP,0x4
    //                               LAB_00540b19                                                 XREF[1]:     00540b07(j)  
    //                              World.cpp:243 (5)
    //         00540b19     CMP        dword ptr [ESI + 0x48],EBP
    //         00540b1c     JZ         LAB_00540b54
    //                              World.cpp:245 (8)
    //         00540b1e     XOR        EDI,EDI
    //         00540b20     CMP        word ptr [ESI + 0x44],BP
    //         00540b24     JLE        LAB_00540b45
    //                               LAB_00540b26                                                 XREF[1]:     00540b43(j)  
    //                              World.cpp:247 (10)
    //         00540b26     MOV        this,dword ptr [ESI + 0x48]
    //         00540b29     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         00540b2c     CMP        this,EBP
    //         00540b2e     JZ         LAB_00540b3c
    //                              World.cpp:249 (6)
    //         00540b30     MOV        EDX,dword ptr [this->_padding_]
    //         00540b32     PUSH       0x1
    //         00540b34     CALL       dword ptr [EDX]
    //                              World.cpp:250 (15)
    //         00540b36     MOV        EAX,dword ptr [ESI + 0x48]
    //         00540b39     MOV        dword ptr [EAX + EDI*0x4],EBP
    //                               LAB_00540b3c                                                 XREF[1]:     00540b2e(j)  
    //         00540b3c     MOVSX      this,word ptr [ESI + 0x44]
    //         00540b40     INC        EDI
    //         00540b41     CMP        EDI,this
    //         00540b43     JL         LAB_00540b26
    //                               LAB_00540b45                                                 XREF[1]:     00540b24(j)  
    //                              World.cpp:253 (12)
    //         00540b45     MOV        EDX,dword ptr [ESI + 0x48]
    //         00540b48     PUSH       EDX
    //         00540b49     CALL       free                                             undefined free()
    //         00540b4e     ADD        ESP,0x4
    //                              World.cpp:254 (3)
    //         00540b51     MOV        dword ptr [ESI + 0x48],EBP
    //                               LAB_00540b54                                                 XREF[1]:     00540b1c(j)  
    //                              World.cpp:257 (7)
    //         00540b54     MOV        this,dword ptr [ESI + 0x4c]
    //         00540b57     CMP        this,EBP
    //         00540b59     JZ         LAB_00540b64
    //                              World.cpp:259 (6)
    //         00540b5b     MOV        EAX,dword ptr [this->_padding_]
    //         00540b5d     PUSH       0x1
    //         00540b5f     CALL       dword ptr [EAX]
    //                              World.cpp:260 (3)
    //         00540b61     MOV        dword ptr [ESI + 0x4c],EBP
    //                               LAB_00540b64                                                 XREF[1]:     00540b59(j)  
    //                              World.cpp:263 (7)
    //         00540b64     MOV        this,dword ptr [ESI + 0x28]
    //         00540b67     CMP        this,EBP
    //         00540b69     JZ         LAB_00540b74
    //                              World.cpp:265 (6)
    //         00540b6b     MOV        EDX,dword ptr [this->_padding_]
    //         00540b6d     PUSH       0x1
    //         00540b6f     CALL       dword ptr [EDX]
    //                              World.cpp:266 (3)
    //         00540b71     MOV        dword ptr [ESI + 0x28],EBP
    //                               LAB_00540b74                                                 XREF[1]:     00540b69(j)  
    //                              World.cpp:269 (5)
    //         00540b74     CMP        dword ptr [ESI + 0x38],EBP
    //         00540b77     JZ         LAB_00540bb3
    //                              World.cpp:271 (8)
    //         00540b79     XOR        EBX,EBX
    //         00540b7b     CMP        word ptr [ESI + 0x34],BP
    //         00540b7f     JLE        LAB_00540ba4
    //                               LAB_00540b81                                                 XREF[1]:     00540ba2(j)  
    //                              World.cpp:272 (10)
    //         00540b81     MOV        EAX,dword ptr [ESI + 0x38]
    //         00540b84     MOV        EDI,dword ptr [EAX + EBX*0x4]
    //         00540b87     CMP        EDI,EBP
    //         00540b89     JZ         LAB_00540b9b
    //                              World.cpp:273 (25)
    //         00540b8b     MOV        this,EDI
    //         00540b8d     CALL       RGE_Sprite::~RGE_Sprite                          void ~RGE_Sprite(RGE_Sprite * this)
    //         00540b92     PUSH       EDI
    //         00540b93     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540b98     ADD        ESP,0x4
    //                               LAB_00540b9b                                                 XREF[1]:     00540b89(j)  
    //         00540b9b     MOVSX      this,word ptr [ESI + 0x34]
    //         00540b9f     INC        EBX
    //         00540ba0     CMP        EBX,this
    //         00540ba2     JL         LAB_00540b81
    //                               LAB_00540ba4                                                 XREF[1]:     00540b7f(j)  
    //                              World.cpp:274 (12)
    //         00540ba4     MOV        EDX,dword ptr [ESI + 0x38]
    //         00540ba7     PUSH       EDX
    //         00540ba8     CALL       free                                             undefined free()
    //         00540bad     ADD        ESP,0x4
    //                              World.cpp:275 (3)
    //         00540bb0     MOV        dword ptr [ESI + 0x38],EBP
    //                               LAB_00540bb3                                                 XREF[1]:     00540b77(j)  
    //                              World.cpp:278 (5)
    //         00540bb3     CMP        dword ptr [ESI + 0x30],EBP
    //         00540bb6     JZ         LAB_00540bf2
    //                              World.cpp:280 (8)
    //         00540bb8     XOR        EBX,EBX
    //         00540bba     CMP        word ptr [ESI + 0x2c],BP
    //         00540bbe     JLE        LAB_00540be3
    //                               LAB_00540bc0                                                 XREF[1]:     00540be1(j)  
    //                              World.cpp:281 (10)
    //         00540bc0     MOV        EAX,dword ptr [ESI + 0x30]
    //         00540bc3     MOV        EDI,dword ptr [EAX + EBX*0x4]
    //         00540bc6     CMP        EDI,EBP
    //         00540bc8     JZ         LAB_00540bda
    //                              World.cpp:282 (25)
    //         00540bca     MOV        this,EDI
    //         00540bcc     CALL       RGE_Sound::~RGE_Sound                            void ~RGE_Sound(RGE_Sound * this)
    //         00540bd1     PUSH       EDI
    //         00540bd2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540bd7     ADD        ESP,0x4
    //                               LAB_00540bda                                                 XREF[1]:     00540bc8(j)  
    //         00540bda     MOVSX      this,word ptr [ESI + 0x2c]
    //         00540bde     INC        EBX
    //         00540bdf     CMP        EBX,this
    //         00540be1     JL         LAB_00540bc0
    //                               LAB_00540be3                                                 XREF[1]:     00540bbe(j)  
    //                              World.cpp:283 (12)
    //         00540be3     MOV        EDX,dword ptr [ESI + 0x30]
    //         00540be6     PUSH       EDX
    //         00540be7     CALL       free                                             undefined free()
    //         00540bec     ADD        ESP,0x4
    //                              World.cpp:284 (3)
    //         00540bef     MOV        dword ptr [ESI + 0x30],EBP
    //                               LAB_00540bf2                                                 XREF[1]:     00540bb6(j)  
    //                              World.cpp:288 (5)
    //         00540bf2     CMP        dword ptr [ESI + 0x54],EBP
    //         00540bf5     JZ         LAB_00540c2a
    //                              World.cpp:290 (8)
    //         00540bf7     XOR        EDI,EDI
    //         00540bf9     CMP        word ptr [ESI + 0x50],BP
    //         00540bfd     JLE        LAB_00540c1b
    //                               LAB_00540bff                                                 XREF[1]:     00540c19(j)  
    //                              World.cpp:291 (10)
    //         00540bff     MOV        EAX,dword ptr [ESI + 0x54]
    //         00540c02     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         00540c05     CMP        EAX,EBP
    //         00540c07     JZ         LAB_00540c12
    //                              World.cpp:292 (18)
    //         00540c09     PUSH       EAX
    //         00540c0a     CALL       free                                             undefined free()
    //         00540c0f     ADD        ESP,0x4
    //                               LAB_00540c12                                                 XREF[1]:     00540c07(j)  
    //         00540c12     MOVSX      this,word ptr [ESI + 0x50]
    //         00540c16     INC        EDI
    //         00540c17     CMP        EDI,this
    //         00540c19     JL         LAB_00540bff
    //                               LAB_00540c1b                                                 XREF[1]:     00540bfd(j)  
    //                              World.cpp:293 (12)
    //         00540c1b     MOV        EDX,dword ptr [ESI + 0x54]
    //         00540c1e     PUSH       EDX
    //         00540c1f     CALL       free                                             undefined free()
    //         00540c24     ADD        ESP,0x4
    //                              World.cpp:294 (3)
    //         00540c27     MOV        dword ptr [ESI + 0x54],EBP
    //                               LAB_00540c2a                                                 XREF[1]:     00540bf5(j)  
    //                              World.cpp:298 (5)
    //         00540c2a     CMP        dword ptr [ESI + 0x64],EBP
    //         00540c2d     JZ         LAB_00540c5f
    //                              World.cpp:300 (8)
    //         00540c2f     XOR        EDI,EDI
    //         00540c31     CMP        word ptr [ESI + 0x60],BP
    //         00540c35     JLE        LAB_00540c50
    //                               LAB_00540c37                                                 XREF[1]:     00540c4e(j)  
    //                              World.cpp:301 (25)
    //         00540c37     MOV        EAX,dword ptr [ESI + 0x64]
    //         00540c3a     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00540c3d     CMP        this,EBP
    //         00540c3f     JZ         LAB_00540c47
    //         00540c41     MOV        EDX,dword ptr [this->_padding_]
    //         00540c43     PUSH       0x1
    //         00540c45     CALL       dword ptr [EDX]
    //                               LAB_00540c47                                                 XREF[1]:     00540c3f(j)  
    //         00540c47     MOVSX      EAX,word ptr [ESI + 0x60]
    //         00540c4b     INC        EDI
    //         00540c4c     CMP        EDI,EAX
    //         00540c4e     JL         LAB_00540c37
    //                               LAB_00540c50                                                 XREF[1]:     00540c35(j)  
    //                              World.cpp:302 (12)
    //         00540c50     MOV        this,dword ptr [ESI + 0x64]
    //         00540c53     PUSH       this
    //         00540c54     CALL       free                                             undefined free()
    //         00540c59     ADD        ESP,0x4
    //                              World.cpp:303 (3)
    //         00540c5c     MOV        dword ptr [ESI + 0x64],EBP
    //                               LAB_00540c5f                                                 XREF[1]:     00540c2d(j)  
    //                              World.cpp:307 (10)
    //         00540c5f     MOV        EAX,dword ptr [ESI + 0x88]
    //         00540c65     CMP        EAX,EBP
    //         00540c67     JZ         LAB_00540c7e
    //                              World.cpp:309 (6)
    //         00540c69     PUSH       EAX
    //         00540c6a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              World.cpp:310 (9)
    //         00540c6f     MOV        dword ptr [ESI + 0x88],EBP
    //         00540c75     ADD        ESP,0x4
    //                              World.cpp:311 (6)
    //         00540c78     MOV        dword ptr [VIS_UNIT_objectsValue],EBP            = 00000000
    //                               LAB_00540c7e                                                 XREF[1]:     00540c67(j)  
    //                              World.cpp:316 (10)
    //         00540c7e     MOV        EAX,dword ptr [ESI + 0x94]
    //         00540c84     CMP        EAX,EBP
    //         00540c86     JZ         LAB_00540c97
    //                              World.cpp:318 (9)
    //         00540c88     PUSH       EAX
    //         00540c89     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540c8e     ADD        ESP,0x4
    //                              World.cpp:319 (6)
    //         00540c91     MOV        dword ptr [ESI + 0x94],EBP
    //                               LAB_00540c97                                                 XREF[1]:     00540c86(j)  
    //                              World.cpp:323 (9)
    //         00540c97     MOV        EAX,[logStatusFile]                              = 00000000
    //         00540c9c     CMP        EAX,EBP
    //         00540c9e     JZ         LAB_00540caf
    //                              World.cpp:325 (9)
    //         00540ca0     PUSH       EAX
    //         00540ca1     CALL       fclose                                           undefined fclose()
    //         00540ca6     ADD        ESP,0x4
    //                              World.cpp:326 (6)
    //         00540ca9     MOV        dword ptr [logStatusFile],EBP                    = 00000000
    //                               LAB_00540caf                                                 XREF[1]:     00540c9e(j)  
    //                              World.cpp:330 (10)
    //         00540caf     MOV        this,dword ptr [ESI + 0xa0]
    //         00540cb5     CMP        this,EBP
    //         00540cb7     JZ         LAB_00540cc5
    //                              World.cpp:332 (6)
    //         00540cb9     MOV        EDX,dword ptr [this->_padding_]
    //         00540cbb     PUSH       0x1
    //         00540cbd     CALL       dword ptr [EDX]
    //                              World.cpp:333 (6)
    //         00540cbf     MOV        dword ptr [ESI + 0xa0],EBP
    //                               LAB_00540cc5                                                 XREF[1]:     00540cb7(j)  
    //                              World.cpp:337 (9)
    //         00540cc5     MOV        EAX,[DVlogf]                                     = 00000000
    //         00540cca     CMP        EAX,EBP
    //         00540ccc     JZ         LAB_00540cdd
    //                              World.cpp:339 (9)
    //         00540cce     PUSH       EAX
    //         00540ccf     CALL       fclose                                           undefined fclose()
    //         00540cd4     ADD        ESP,0x4
    //                              World.cpp:340 (6)
    //         00540cd7     MOV        dword ptr [DVlogf],EBP                           = 00000000
    //                               LAB_00540cdd                                                 XREF[1]:     00540ccc(j)  
    //                              World.cpp:344 (5)
    //         00540cdd     POP        EDI
    //         00540cde     POP        ESI
    //         00540cdf     POP        EBP
    //         00540ce0     POP        EBX
    //         00540ce1     RET
    //         00540ce2     ??         90h
    //         00540ce3     NOP
    //         00540ce4     NOP
    //         00540ce5     NOP
    //         00540ce6     NOP
    //         00540ce7     NOP
    //         00540ce8     NOP
    //         00540ce9     NOP
    //         00540cea     NOP
    //         00540ceb     NOP
    //         00540cec     NOP
    //         00540ced     NOP
    //         00540cee     NOP
    //         00540cef     NOP
}

void RGE_Game_World::reset_object_count() {
    /* TODO: Stub */
    //                              void __thiscall reset_object_count(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?reset_object_count@RGE_Game_World@@QAEXXZ                   XREF[1]:     clear_map:004558cf(c)  
    //                               RGE_Game_World::reset_object_count
    //                              World.cpp:348 (6)
    //         00540cf0     XOR        EAX,EAX
    //         00540cf2     PUSH       EDI
    //         00540cf3     MOV        dword ptr [ECX + this->world_time],EAX
    //                              World.cpp:350 (3)
    //         00540cf6     MOV        dword ptr [ECX + this->old_world_time],EAX
    //                              World.cpp:351 (3)
    //         00540cf9     MOV        dword ptr [ECX + this->world_time_delta],EAX
    //                              World.cpp:352 (6)
    //         00540cfc     MOV        dword ptr [ECX + this->world_time_delta_second
    //                              World.cpp:353 (3)
    //         00540d02     MOV        dword ptr [ECX + this->timer],EAX
    //                              World.cpp:354 (3)
    //         00540d05     MOV        dword ptr [ECX + this->old_time],EAX
    //                              World.cpp:355 (3)
    //         00540d08     MOV        byte ptr [ECX + this->temp_pause],AL
    //                              World.cpp:357 (3)
    //         00540d0b     MOV        dword ptr [ECX + this->next_object_id],EAX
    //                              World.cpp:359 (12)
    //         00540d0e     MOV        dword ptr [ECX + this->player_turn],EAX
    //         00540d14     LEA        EDI,[ECX + this->player_time_delta[0]]
    //                              World.cpp:361 (7)
    //         00540d1a     MOV        this,0x9
    //         00540d1f     STOSD.REP  ES:EDI
    //                              World.cpp:362 (2)
    //         00540d21     POP        EDI
    //         00540d22     RET
    //         00540d23     ??         90h
    //         00540d24     NOP
    //         00540d25     NOP
    //         00540d26     NOP
    //         00540d27     NOP
    //         00540d28     NOP
    //         00540d29     NOP
    //         00540d2a     NOP
    //         00540d2b     NOP
    //         00540d2c     NOP
    //         00540d2d     NOP
    //         00540d2e     NOP
    //         00540d2f     NOP
    return;
}

void RGE_Game_World::pause(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall pause(RGE_Game_World * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00540d30(R)  
    //                               ?pause@RGE_Game_World@@UAEXE@Z                               XREF[2]:     00577544(*), 005779fc(*)  
    //                               RGE_Game_World::pause
    //                              World.cpp:366 (12)
    //         00540d30     MOV        AL,byte ptr [ESP + param_1]
    //         00540d34     PUSH       ESI
    //         00540d35     PUSH       EDI
    //         00540d36     MOV        EDI,this
    //         00540d38     TEST       AL,AL
    //         00540d3a     JZ         LAB_00540d58
    //                              World.cpp:372 (8)
    //         00540d3c     XOR        ESI,ESI
    //         00540d3e     CMP        word ptr [EDI + 0x2c],SI
    //         00540d42     JLE        LAB_00540d58
    //                               LAB_00540d44                                                 XREF[1]:     00540d56(j)  
    //                              World.cpp:373 (20)
    //         00540d44     MOV        EAX,dword ptr [EDI + 0x30]
    //         00540d47     MOV        this,dword ptr [EAX + ESI*0x4]
    //         00540d4a     CALL       RGE_Sound::stop                                  void stop(RGE_Sound * this)
    //         00540d4f     MOVSX      this,word ptr [EDI + 0x2c]
    //         00540d53     INC        ESI
    //         00540d54     CMP        ESI,this
    //         00540d56     JL         LAB_00540d44
    //                               LAB_00540d58                                                 XREF[2]:     00540d3a(j), 00540d42(j)  
    //                              World.cpp:375 (5)
    //         00540d58     POP        EDI
    //         00540d59     POP        ESI
    //         00540d5a     RET        0x4
    //         00540d5d     ??         90h
    //         00540d5e     NOP
    //         00540d5f     NOP
    return;
}

void RGE_Game_World::set_map_visible(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_map_visible(RGE_Game_World * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00540d67(R)  
    //                               ?set_map_visible@RGE_Game_World@@QAEXE@Z                     XREF[1]:     set_map_visible:004228cf(c)  
    //                               RGE_Game_World::set_map_visible
    //                              World.cpp:379 (7)
    //         00540d60     MOV        this,dword ptr [ECX + this->map]
    //         00540d63     TEST       this,this
    //         00540d65     JZ         LAB_00540d71
    //                              World.cpp:381 (10)
    //         00540d67     MOV        EAX,dword ptr [ESP + param_1]
    //         00540d6b     PUSH       EAX
    //         00540d6c     CALL       RGE_Map::set_map_visible                         void set_map_visible(RGE_Map * this, uchar pa
    //                               LAB_00540d71                                                 XREF[1]:     00540d65(j)  
    //                              World.cpp:382 (3)
    //         00540d71     RET        0x4
    //         00540d74     ??         90h
    //         00540d75     NOP
    //         00540d76     NOP
    //         00540d77     NOP
    //         00540d78     NOP
    //         00540d79     NOP
    //         00540d7a     NOP
    //         00540d7b     NOP
    //         00540d7c     NOP
    //         00540d7d     NOP
    //         00540d7e     NOP
    //         00540d7f     NOP
    return;
}

void RGE_Game_World::set_map_fog(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_map_fog(RGE_Game_World * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00540d87(R)  
    //                               ?set_map_fog@RGE_Game_World@@QAEXE@Z                         XREF[1]:     set_map_fog:004228ef(c)  
    //                               RGE_Game_World::set_map_fog
    //                              World.cpp:386 (7)
    //         00540d80     MOV        this,dword ptr [ECX + this->map]
    //         00540d83     TEST       this,this
    //         00540d85     JZ         LAB_00540d91
    //                              World.cpp:388 (10)
    //         00540d87     MOV        EAX,dword ptr [ESP + param_1]
    //         00540d8b     PUSH       EAX
    //         00540d8c     CALL       RGE_Map::set_map_fog                             void set_map_fog(RGE_Map * this, uchar param_1)
    //                               LAB_00540d91                                                 XREF[1]:     00540d85(j)  
    //                              World.cpp:389 (3)
    //         00540d91     RET        0x4
    //         00540d94     ??         90h
    //         00540d95     NOP
    //         00540d96     NOP
    //         00540d97     NOP
    //         00540d98     NOP
    //         00540d99     NOP
    //         00540d9a     NOP
    //         00540d9b     NOP
    //         00540d9c     NOP
    //         00540d9d     NOP
    //         00540d9e     NOP
    //         00540d9f     NOP
    return;
}

uchar RGE_Game_World::data_load_sounds(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_sounds(RGE_Game_World * this, char * para
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[4]:     00540dae(R), 00540dd9(*), 00540e08(R), 00540e68(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00540e3d(W), 00540e5c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00540e8c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00540e37(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00540e10(W), 00540e63(R), 00540e6d(W)  
    //              short             Stack[-0x18]:2 index                     XREF[3]:     00540e16(*), 00540e43(R), 00540e54(R)  
    //              short             Stack[-0x1c]:2 id
    //                               ?data_load_sounds@RGE_Game_World@@MAEEPAD@Z                  XREF[2]:     00577468(*), 00577920(*)  
    //                               RGE_Game_World::data_load_sounds
    //                              World.cpp:393 (14)
    //         00540da0     MOV        EAX,FS:[0x0]
    //         00540da6     PUSH       -0x1
    //         00540da8     PUSH       FUN_00561c2b
    //         00540dad     PUSH       EAX
    //                              World.cpp:399 (34)
    //         00540dae     MOV        EAX,dword ptr [ESP + param_1]
    //         00540db2     MOV        dword ptr FS:[0x0],ESP
    //         00540db9     SUB        ESP,0xc
    //         00540dbc     PUSH       EBX
    //         00540dbd     PUSH       EDI
    //         00540dbe     PUSH       s_r                                              = "r"
    //         00540dc3     MOV        EBX,this
    //         00540dc5     PUSH       EAX
    //         00540dc6     CALL       fopen                                            undefined fopen()
    //         00540dcb     MOV        EDI,EAX
    //         00540dcd     ADD        ESP,0x8
    //                              World.cpp:400 (9)
    //         00540dd0     TEST       EDI,EDI
    //         00540dd2     JZ         LAB_00540e8c
    //         00540dd8     PUSH       ESI
    //                              World.cpp:402 (31)
    //         00540dd9     LEA        this=>param_1,[ESP + 0x28]
    //         00540ddd     PUSH       EBP
    //         00540dde     LEA        ESI,[EBX + 0x2c]
    //         00540de1     PUSH       this
    //         00540de2     PUSH       ESI
    //         00540de3     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00540de8     PUSH       EDI
    //         00540de9     CALL       fscanf                                           undefined fscanf()
    //         00540dee     OR         EBP,0xffffffff
    //         00540df1     ADD        ESP,0x10
    //         00540df4     CMP        EAX,EBP
    //         00540df6     JZ         LAB_00540e75
    //                              World.cpp:404 (11)
    //         00540df8     MOVSX      EDX,word ptr [ESI]
    //         00540dfb     PUSH       0x4
    //         00540dfd     PUSH       EDX
    //         00540dfe     CALL       calloc                                           undefined calloc()
    //                              World.cpp:405 (19)
    //         00540e03     XOR        ESI,ESI
    //         00540e05     ADD        ESP,0x8
    //         00540e08     CMP        word ptr [ESP + param_1],SI
    //         00540e0d     MOV        dword ptr [EBX + 0x30],EAX
    //         00540e10     MOV        dword ptr [ESP + local_14],ESI
    //         00540e14     JLE        LAB_00540e81
    //                               LAB_00540e16                                                 XREF[1]:     00540e71(j)  
    //                              World.cpp:406 (23)
    //         00540e16     LEA        EAX=>index,[ESP + 0x10]
    //         00540e1a     PUSH       EAX
    //         00540e1b     PUSH       s_%hd                                            = "%hd"
    //         00540e20     PUSH       EDI
    //         00540e21     CALL       fscanf                                           undefined fscanf()
    //         00540e26     ADD        ESP,0xc
    //         00540e29     CMP        EAX,EBP
    //         00540e2b     JZ         LAB_00540e63
    //                              World.cpp:407 (70)
    //         00540e2d     PUSH       0x10
    //         00540e2f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00540e34     ADD        ESP,0x4
    //         00540e37     MOV        dword ptr [ESP + local_10],EAX
    //         00540e3b     CMP        EAX,ESI
    //         00540e3d     MOV        dword ptr [ESP + local_4],ESI
    //         00540e41     JZ         LAB_00540e52
    //         00540e43     MOV        this,dword ptr [ESP + index]
    //         00540e47     PUSH       this
    //         00540e48     PUSH       EDI
    //         00540e49     MOV        this,EAX
    //         00540e4b     CALL       RGE_Sound::RGE_Sound                             undefined RGE_Sound(RGE_Sound * this, _iobuf 
    //         00540e50     JMP        LAB_00540e54
    //                               LAB_00540e52                                                 XREF[1]:     00540e41(j)  
    //         00540e52     XOR        EAX,EAX
    //                               LAB_00540e54                                                 XREF[1]:     00540e50(j)  
    //         00540e54     MOVSX      EDX,word ptr [ESP + index]
    //         00540e59     MOV        this,dword ptr [EBX + 0x30]
    //         00540e5c     MOV        dword ptr [ESP + local_4],EBP
    //         00540e60     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                               LAB_00540e63                                                 XREF[1]:     00540e2b(j)  
    //         00540e63     MOV        EAX,dword ptr [ESP + local_14]
    //         00540e67     INC        EAX
    //         00540e68     CMP        AX,word ptr [ESP + param_1]
    //         00540e6d     MOV        dword ptr [ESP + local_14],EAX
    //         00540e71     JL         LAB_00540e16
    //                              World.cpp:409 (2)
    //         00540e73     JMP        LAB_00540e81
    //                               LAB_00540e75                                                 XREF[1]:     00540df6(j)  
    //                              World.cpp:411 (5)
    //         00540e75     MOV        word ptr [ESI],0x0
    //                              World.cpp:412 (7)
    //         00540e7a     MOV        dword ptr [EBX + 0x30],0x0
    //                               LAB_00540e81                                                 XREF[2]:     00540e14(j), 00540e73(j)  
    //                              World.cpp:414 (11)
    //         00540e81     PUSH       EDI
    //         00540e82     CALL       fclose                                           undefined fclose()
    //         00540e87     ADD        ESP,0x4
    //         00540e8a     POP        EBP
    //         00540e8b     POP        ESI
    //                               LAB_00540e8c                                                 XREF[1]:     00540dd2(j)  
    //                              World.cpp:418 (21)
    //         00540e8c     MOV        this,dword ptr [ESP + local_c]
    //         00540e90     POP        EDI
    //         00540e91     MOV        AL,0x1
    //         00540e93     MOV        dword ptr FS:[0x0],this
    //         00540e9a     POP        EBX
    //         00540e9b     ADD        ESP,0x18
    //         00540e9e     RET        0x4
    //         00540ea1     ??         90h
    //         00540ea2     NOP
    //         00540ea3     NOP
    //         00540ea4     NOP
    //         00540ea5     NOP
    //         00540ea6     NOP
    //         00540ea7     NOP
    //         00540ea8     NOP
    //         00540ea9     NOP
    //         00540eaa     NOP
    //         00540eab     NOP
    //         00540eac     NOP
    //         00540ead     NOP
    //         00540eae     NOP
    //         00540eaf     NOP
    return 0;
}

uchar RGE_Game_World::data_load_terrain_tables(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_terrain_tables(RGE_Game_World * this, cha
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[4]:     00540eb0(R), 00540f1b(*), 00540f40(R), 00540f67(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00540f09(W), 00540f94(R), 00540f9d(W)  
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[2]:     00540f57(*), 00540f72(R)  
    //              short             Stack[-0x8]:2  index                     XREF[3]:     00540f17(*), 00540f50(R), 00540f8d(R)  
    //              short             Stack[-0xa]:2  index3
    //              short             Stack[-0xc]:2  count
    //                               ?data_load_terrain_tables@RGE_Game_World@@MAEEPAD@Z          XREF[2]:     0057745c(*), 00577914(*)  
    //                               RGE_Game_World::data_load_terrain_tables
    //                              World.cpp:422 (27)
    //         00540eb0     MOV        EAX,dword ptr [ESP + param_1]
    //         00540eb4     SUB        ESP,0x8
    //         00540eb7     PUSH       EBX
    //         00540eb8     PUSH       EDI
    //         00540eb9     PUSH       s_r                                              = "r"
    //         00540ebe     MOV        EBX,this
    //         00540ec0     PUSH       EAX
    //         00540ec1     CALL       fopen                                            undefined fopen()
    //         00540ec6     MOV        EDI,EAX
    //         00540ec8     ADD        ESP,0x8
    //                              World.cpp:431 (10)
    //         00540ecb     TEST       EDI,EDI
    //         00540ecd     JZ         LAB_00540fc0
    //         00540ed3     PUSH       ESI
    //         00540ed4     PUSH       EBP
    //                              World.cpp:433 (31)
    //         00540ed5     LEA        EBP,[EBX + 0x52]
    //         00540ed8     LEA        ESI,[EBX + 0x50]
    //         00540edb     PUSH       EBP
    //         00540edc     PUSH       ESI
    //         00540edd     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00540ee2     PUSH       EDI
    //         00540ee3     CALL       fscanf                                           undefined fscanf()
    //         00540ee8     ADD        ESP,0x10
    //         00540eeb     CMP        EAX,-0x1
    //         00540eee     JZ         LAB_00540fa9
    //                              World.cpp:435 (14)
    //         00540ef4     MOVSX      this,word ptr [ESI]
    //         00540ef7     PUSH       0x4
    //         00540ef9     PUSH       this
    //         00540efa     CALL       calloc                                           undefined calloc()
    //         00540eff     ADD        ESP,0x8
    //                              World.cpp:436 (21)
    //         00540f02     CMP        word ptr [ESI],0x0
    //         00540f06     MOV        dword ptr [EBX + 0x54],EAX
    //         00540f09     MOV        dword ptr [ESP + local_4],0x0
    //         00540f11     JLE        LAB_00540fb5
    //                               LAB_00540f17                                                 XREF[1]:     00540fa1(j)  
    //                              World.cpp:437 (29)
    //         00540f17     LEA        EDX=>index,[ESP + 0x10]
    //         00540f1b     LEA        EAX=>param_1,[ESP + 0x1c]
    //         00540f1f     PUSH       EDX
    //         00540f20     PUSH       EAX
    //         00540f21     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00540f26     PUSH       EDI
    //         00540f27     CALL       fscanf                                           undefined fscanf()
    //         00540f2c     ADD        ESP,0x10
    //         00540f2f     CMP        EAX,-0x1
    //         00540f32     JZ         LAB_00540f94
    //                              World.cpp:439 (20)
    //         00540f34     MOVSX      this,word ptr [EBP]
    //         00540f38     PUSH       0x4
    //         00540f3a     PUSH       this
    //         00540f3b     CALL       calloc                                           undefined calloc()
    //         00540f40     MOVSX      EDX,word ptr [ESP + param_1]
    //         00540f45     MOV        this,dword ptr [EBX + 0x54]
    //                              World.cpp:440 (15)
    //         00540f48     XOR        ESI,ESI
    //         00540f4a     ADD        ESP,0x8
    //         00540f4d     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //         00540f50     CMP        word ptr [ESP + index],SI
    //         00540f55     JLE        LAB_00540f94
    //                               LAB_00540f57                                                 XREF[1]:     00540f92(j)  
    //                              World.cpp:442 (16)
    //         00540f57     LEA        EDX=>local_6,[ESP + 0x12]
    //         00540f5b     PUSH       EDX
    //         00540f5c     PUSH       s_%hd                                            = "%hd"
    //         00540f61     PUSH       EDI
    //         00540f62     CALL       fscanf                                           undefined fscanf()
    //                              World.cpp:443 (45)
    //         00540f67     MOVSX      EAX,word ptr [ESP + param_1]
    //         00540f6c     MOV        this,dword ptr [EBX + 0x54]
    //         00540f6f     ADD        ESP,0xc
    //         00540f72     MOVSX      EDX,word ptr [ESP + local_6]
    //         00540f77     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         00540f7a     LEA        this,[EAX + EDX*0x4]
    //         00540f7d     PUSH       this
    //         00540f7e     PUSH       s_%f                                             = "%f"
    //         00540f83     PUSH       EDI
    //         00540f84     CALL       fscanf                                           undefined fscanf()
    //         00540f89     ADD        ESP,0xc
    //         00540f8c     INC        ESI
    //         00540f8d     CMP        SI,word ptr [ESP + index]
    //         00540f92     JL         LAB_00540f57
    //                               LAB_00540f94                                                 XREF[2]:     00540f32(j), 00540f55(j)  
    //                              World.cpp:436 (19)
    //         00540f94     MOV        EAX,dword ptr [ESP + local_4]
    //         00540f98     INC        EAX
    //         00540f99     CMP        AX,word ptr [EBX + 0x50]
    //         00540f9d     MOV        dword ptr [ESP + local_4],EAX
    //         00540fa1     JL         LAB_00540f17
    //                              World.cpp:451 (2)
    //         00540fa7     JMP        LAB_00540fb5
    //                               LAB_00540fa9                                                 XREF[1]:     00540eee(j)  
    //                              World.cpp:453 (5)
    //         00540fa9     MOV        word ptr [ESI],0x0
    //                              World.cpp:454 (7)
    //         00540fae     MOV        dword ptr [EBX + 0x54],0x0
    //                               LAB_00540fb5                                                 XREF[2]:     00540f11(j), 00540fa7(j)  
    //                              World.cpp:457 (11)
    //         00540fb5     PUSH       EDI
    //         00540fb6     CALL       fclose                                           undefined fclose()
    //         00540fbb     ADD        ESP,0x4
    //         00540fbe     POP        EBP
    //         00540fbf     POP        ESI
    //                               LAB_00540fc0                                                 XREF[1]:     00540ecd(j)  
    //                              World.cpp:460 (10)
    //         00540fc0     POP        EDI
    //         00540fc1     MOV        AL,0x1
    //         00540fc3     POP        EBX
    //         00540fc4     ADD        ESP,0x8
    //         00540fc7     RET        0x4
    //         00540fca     ??         90h
    //         00540fcb     NOP
    //         00540fcc     NOP
    //         00540fcd     NOP
    //         00540fce     NOP
    //         00540fcf     NOP
    return 0;
}

uchar RGE_Game_World::data_load_color_tables(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_color_tables(RGE_Game_World * this, char 
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[4]:     00540fde(R), 00541009(*), 0054103c(R), 0054109f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00541074(W), 00541093(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005410c3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0054106e(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00541044(W), 0054109a(R), 005410a4(W)  
    //              short             Stack[-0x18]:2 index                     XREF[3]:     0054104a(*), 0054107a(R), 0054108b(R)  
    //              short             Stack[-0x1c]:2 id
    //                               ?data_load_color_tables@RGE_Game_World@@MAEEPAD@Z            XREF[2]:     0057746c(*), 00577924(*)  
    //                               RGE_Game_World::data_load_color_tables
    //                              World.cpp:464 (14)
    //         00540fd0     MOV        EAX,FS:[0x0]
    //         00540fd6     PUSH       -0x1
    //         00540fd8     PUSH       FUN_00561c4b
    //         00540fdd     PUSH       EAX
    //                              World.cpp:470 (34)
    //         00540fde     MOV        EAX,dword ptr [ESP + param_1]
    //         00540fe2     MOV        dword ptr FS:[0x0],ESP
    //         00540fe9     SUB        ESP,0xc
    //         00540fec     PUSH       EBX
    //         00540fed     PUSH       EDI
    //         00540fee     PUSH       s_r                                              = "r"
    //         00540ff3     MOV        EBX,this
    //         00540ff5     PUSH       EAX
    //         00540ff6     CALL       fopen                                            undefined fopen()
    //         00540ffb     MOV        EDI,EAX
    //         00540ffd     ADD        ESP,0x8
    //                              World.cpp:471 (9)
    //         00541000     TEST       EDI,EDI
    //         00541002     JZ         LAB_005410c3
    //         00541008     PUSH       ESI
    //                              World.cpp:473 (35)
    //         00541009     LEA        this=>param_1,[ESP + 0x28]
    //         0054100d     PUSH       EBP
    //         0054100e     LEA        ESI,[EBX + 0x60]
    //         00541011     PUSH       this
    //         00541012     PUSH       ESI
    //         00541013     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00541018     PUSH       EDI
    //         00541019     CALL       fscanf                                           undefined fscanf()
    //         0054101e     OR         EBP,0xffffffff
    //         00541021     ADD        ESP,0x10
    //         00541024     CMP        EAX,EBP
    //         00541026     JZ         LAB_005410ac
    //                              World.cpp:475 (11)
    //         0054102c     MOVSX      EDX,word ptr [ESI]
    //         0054102f     PUSH       0x4
    //         00541031     PUSH       EDX
    //         00541032     CALL       calloc                                           undefined calloc()
    //                              World.cpp:476 (19)
    //         00541037     XOR        ESI,ESI
    //         00541039     ADD        ESP,0x8
    //         0054103c     CMP        word ptr [ESP + param_1],SI
    //         00541041     MOV        dword ptr [EBX + 0x64],EAX
    //         00541044     MOV        dword ptr [ESP + local_14],ESI
    //         00541048     JLE        LAB_005410b8
    //                               LAB_0054104a                                                 XREF[1]:     005410a8(j)  
    //                              World.cpp:477 (23)
    //         0054104a     LEA        EAX=>index,[ESP + 0x10]
    //         0054104e     PUSH       EAX
    //         0054104f     PUSH       s_%hd                                            = "%hd"
    //         00541054     PUSH       EDI
    //         00541055     CALL       fscanf                                           undefined fscanf()
    //         0054105a     ADD        ESP,0xc
    //         0054105d     CMP        EAX,EBP
    //         0054105f     JZ         LAB_0054109a
    //                              World.cpp:478 (73)
    //         00541061     PUSH       0x128
    //         00541066     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054106b     ADD        ESP,0x4
    //         0054106e     MOV        dword ptr [ESP + local_10],EAX
    //         00541072     CMP        EAX,ESI
    //         00541074     MOV        dword ptr [ESP + local_4],ESI
    //         00541078     JZ         LAB_00541089
    //         0054107a     MOV        this,dword ptr [ESP + index]
    //         0054107e     PUSH       this
    //         0054107f     PUSH       EDI
    //         00541080     MOV        this,EAX
    //         00541082     CALL       RGE_Color_Table::RGE_Color_Table                 undefined RGE_Color_Table(RGE_Color_Table * t
    //         00541087     JMP        LAB_0054108b
    //                               LAB_00541089                                                 XREF[1]:     00541078(j)  
    //         00541089     XOR        EAX,EAX
    //                               LAB_0054108b                                                 XREF[1]:     00541087(j)  
    //         0054108b     MOVSX      EDX,word ptr [ESP + index]
    //         00541090     MOV        this,dword ptr [EBX + 0x64]
    //         00541093     MOV        dword ptr [ESP + local_4],EBP
    //         00541097     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                               LAB_0054109a                                                 XREF[1]:     0054105f(j)  
    //         0054109a     MOV        EAX,dword ptr [ESP + local_14]
    //         0054109e     INC        EAX
    //         0054109f     CMP        AX,word ptr [ESP + param_1]
    //         005410a4     MOV        dword ptr [ESP + local_14],EAX
    //         005410a8     JL         LAB_0054104a
    //                              World.cpp:480 (2)
    //         005410aa     JMP        LAB_005410b8
    //                               LAB_005410ac                                                 XREF[1]:     00541026(j)  
    //                              World.cpp:482 (5)
    //         005410ac     MOV        word ptr [ESI],0x0
    //                              World.cpp:483 (7)
    //         005410b1     MOV        dword ptr [EBX + 0x64],0x0
    //                               LAB_005410b8                                                 XREF[2]:     00541048(j), 005410aa(j)  
    //                              World.cpp:486 (11)
    //         005410b8     PUSH       EDI
    //         005410b9     CALL       fclose                                           undefined fclose()
    //         005410be     ADD        ESP,0x4
    //         005410c1     POP        EBP
    //         005410c2     POP        ESI
    //                               LAB_005410c3                                                 XREF[1]:     00541002(j)  
    //                              World.cpp:489 (21)
    //         005410c3     MOV        this,dword ptr [ESP + local_c]
    //         005410c7     POP        EDI
    //         005410c8     MOV        AL,0x1
    //         005410ca     MOV        dword ptr FS:[0x0],this
    //         005410d1     POP        EBX
    //         005410d2     ADD        ESP,0x18
    //         005410d5     RET        0x4
    //         005410d8     ??         90h
    //         005410d9     NOP
    //         005410da     NOP
    //         005410db     NOP
    //         005410dc     NOP
    //         005410dd     NOP
    //         005410de     NOP
    //         005410df     NOP
    return 0;
}

uchar RGE_Game_World::data_load_sprites(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_sprites(RGE_Game_World * this, char * par
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[5]:     005410ee(R), 00541119(*), 0054114a(R), 005411ae(R), 
    //                                                                                     00541203(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00541180(W), 005411a7(W), 005411df(W), 005411f8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541227(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0054117a(W), 005411d9(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00541159(*), 0054118d(R), 0054119f(R)  
    //              short             Stack[-0x18]:2 id
    //                               ?data_load_sprites@RGE_Game_World@@MAEEPAD@Z                 XREF[2]:     00577470(*), 00577928(*)  
    //                               RGE_Game_World::data_load_sprites
    //                              World.cpp:493 (14)
    //         005410e0     MOV        EAX,FS:[0x0]
    //         005410e6     PUSH       -0x1
    //         005410e8     PUSH       FUN_00561c76
    //         005410ed     PUSH       EAX
    //                              World.cpp:499 (34)
    //         005410ee     MOV        EAX,dword ptr [ESP + param_1]
    //         005410f2     MOV        dword ptr FS:[0x0],ESP
    //         005410f9     SUB        ESP,0x8
    //         005410fc     PUSH       EBX
    //         005410fd     PUSH       EDI
    //         005410fe     PUSH       s_r                                              = "r"
    //         00541103     MOV        EDI,this
    //         00541105     PUSH       EAX
    //         00541106     CALL       fopen                                            undefined fopen()
    //         0054110b     MOV        EBX,EAX
    //         0054110d     ADD        ESP,0x8
    //                              World.cpp:500 (9)
    //         00541110     TEST       EBX,EBX
    //         00541112     JZ         LAB_00541227
    //         00541118     PUSH       ESI
    //                              World.cpp:502 (35)
    //         00541119     LEA        this=>param_1,[ESP + 0x24]
    //         0054111d     PUSH       EBP
    //         0054111e     LEA        ESI,[EDI + 0x34]
    //         00541121     PUSH       this
    //         00541122     PUSH       ESI
    //         00541123     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00541128     PUSH       EBX
    //         00541129     CALL       fscanf                                           undefined fscanf()
    //         0054112e     OR         EBP,0xffffffff
    //         00541131     ADD        ESP,0x10
    //         00541134     CMP        EAX,EBP
    //         00541136     JZ         LAB_00541210
    //                              World.cpp:504 (14)
    //         0054113c     MOVSX      EDX,word ptr [ESI]
    //         0054113f     PUSH       0x4
    //         00541141     PUSH       EDX
    //         00541142     CALL       calloc                                           undefined calloc()
    //         00541147     MOV        dword ptr [EDI + 0x38],EAX
    //                              World.cpp:505 (15)
    //         0054114a     MOV        AX,word ptr [ESP + param_1]
    //         0054114f     ADD        ESP,0x8
    //         00541152     XOR        ESI,ESI
    //         00541154     TEST       AX,AX
    //         00541157     JLE        LAB_005411b9
    //                               LAB_00541159                                                 XREF[1]:     005411b7(j)  
    //                              World.cpp:506 (23)
    //         00541159     LEA        EAX=>local_14,[ESP + 0x10]
    //         0054115d     PUSH       EAX
    //         0054115e     PUSH       s_%hd                                            = "%hd"
    //         00541163     PUSH       EBX
    //         00541164     CALL       fscanf                                           undefined fscanf()
    //         00541169     ADD        ESP,0xc
    //         0054116c     CMP        EAX,EBP
    //         0054116e     JZ         LAB_005411ae
    //                              language.dll match for 0x78: "10"
    //                              World.cpp:507 (73)
    //         00541170     PUSH       0x78
    //         00541172     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541177     ADD        ESP,0x4
    //         0054117a     MOV        dword ptr [ESP + local_10],EAX
    //         0054117e     TEST       EAX,EAX
    //         00541180     MOV        dword ptr [ESP + local_4],0x0
    //         00541188     JZ         LAB_0054119d
    //         0054118a     MOV        this,dword ptr [EDI + 0x30]
    //         0054118d     MOV        EDX,dword ptr [ESP + local_14]
    //         00541191     PUSH       this
    //         00541192     PUSH       EDX
    //         00541193     PUSH       EBX
    //         00541194     MOV        this,EAX
    //         00541196     CALL       RGE_Sprite::RGE_Sprite                           undefined RGE_Sprite(RGE_Sprite * this, _iobu
    //         0054119b     JMP        LAB_0054119f
    //                               LAB_0054119d                                                 XREF[1]:     00541188(j)  
    //         0054119d     XOR        EAX,EAX
    //                               LAB_0054119f                                                 XREF[1]:     0054119b(j)  
    //         0054119f     MOVSX      this,word ptr [ESP + local_14]
    //         005411a4     MOV        EDX,dword ptr [EDI + 0x38]
    //         005411a7     MOV        dword ptr [ESP + local_4],EBP
    //         005411ab     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //                               LAB_005411ae                                                 XREF[1]:     0054116e(j)  
    //         005411ae     MOV        AX,word ptr [ESP + param_1]
    //         005411b3     INC        ESI
    //         005411b4     CMP        SI,AX
    //         005411b7     JL         LAB_00541159
    //                               LAB_005411b9                                                 XREF[1]:     00541157(j)  
    //                              World.cpp:508 (7)
    //         005411b9     XOR        EBP,EBP
    //         005411bb     TEST       AX,AX
    //         005411be     JLE        LAB_0054121c
    //                               LAB_005411c0                                                 XREF[1]:     0054120c(j)  
    //                              World.cpp:509 (15)
    //         005411c0     MOV        this,dword ptr [EDI + 0x38]
    //         005411c3     MOVSX      ESI,BP
    //         005411c6     SHL        ESI,0x2
    //         005411c9     CMP        dword ptr [this->_padding_ + ESI*0x1],0x0
    //         005411cd     JNZ        LAB_00541208
    //                              language.dll match for 0x78: "10"
    //                              World.cpp:510 (63)
    //         005411cf     PUSH       0x78
    //         005411d1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005411d6     ADD        ESP,0x4
    //         005411d9     MOV        dword ptr [ESP + local_10],EAX
    //         005411dd     TEST       EAX,EAX
    //         005411df     MOV        dword ptr [ESP + local_4],0x1
    //         005411e7     JZ         LAB_005411f3
    //         005411e9     PUSH       EBP
    //         005411ea     MOV        this,EAX
    //         005411ec     CALL       RGE_Sprite::RGE_Sprite                           undefined RGE_Sprite(RGE_Sprite * this, short
    //         005411f1     JMP        LAB_005411f5
    //                               LAB_005411f3                                                 XREF[1]:     005411e7(j)  
    //         005411f3     XOR        EAX,EAX
    //                               LAB_005411f5                                                 XREF[1]:     005411f1(j)  
    //         005411f5     MOV        EDX,dword ptr [EDI + 0x38]
    //         005411f8     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00541200     MOV        dword ptr [EDX + ESI*0x1],EAX
    //         00541203     MOV        AX,word ptr [ESP + param_1]
    //                               LAB_00541208                                                 XREF[1]:     005411cd(j)  
    //         00541208     INC        EBP
    //         00541209     CMP        BP,AX
    //         0054120c     JL         LAB_005411c0
    //                              World.cpp:512 (2)
    //         0054120e     JMP        LAB_0054121c
    //                               LAB_00541210                                                 XREF[1]:     00541136(j)  
    //                              World.cpp:514 (5)
    //         00541210     MOV        word ptr [ESI],0x0
    //                              World.cpp:515 (7)
    //         00541215     MOV        dword ptr [EDI + 0x38],0x0
    //                               LAB_0054121c                                                 XREF[2]:     005411be(j), 0054120e(j)  
    //                              World.cpp:517 (11)
    //         0054121c     PUSH       EBX
    //         0054121d     CALL       fclose                                           undefined fclose()
    //         00541222     ADD        ESP,0x4
    //         00541225     POP        EBP
    //         00541226     POP        ESI
    //                               LAB_00541227                                                 XREF[1]:     00541112(j)  
    //                              World.cpp:520 (21)
    //         00541227     MOV        this,dword ptr [ESP + local_c]
    //         0054122b     POP        EDI
    //         0054122c     MOV        AL,0x1
    //         0054122e     MOV        dword ptr FS:[0x0],this
    //         00541235     POP        EBX
    //         00541236     ADD        ESP,0x14
    //         00541239     RET        0x4
    //         0054123c     ??         90h
    //         0054123d     NOP
    //         0054123e     NOP
    //         0054123f     NOP
    //                              * protected: virtual void __thiscall RGE_Game_World::data_load_players_type(short,short,struct _iobu... *
    //                              void __thiscall data_load_players_type(RGE_Game_World * this, short 
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0054128a(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     00541246(R), 0054126a(W)  
    //              _iobuf *          Stack[0xc]:4   param_3                   XREF[1]:     0054127a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541270(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541295(R)  
    //                               ?data_load_players_type@RGE_Game_World@@MAEXFFPAU_iobuf@@@Z  XREF[2]:     data_load_players_type:0052e24f(c)
    //                               RGE_Game_World::data_load_players_type                                    0057792c(*)  
    //                              World.cpp:524 (6)
    //         00541240     MOV        EAX,FS:[0x0]
    //                              World.cpp:525 (26)
    //         00541246     CMP        word ptr [ESP + param_2],0x0
    //         0054124c     PUSH       -0x1
    //         0054124e     PUSH       FUN_00561c8b
    //         00541253     PUSH       EAX
    //         00541254     MOV        dword ptr FS:[0x0],ESP
    //         0054125b     PUSH       ESI
    //         0054125c     MOV        ESI,this
    //         0054125e     JNZ        LAB_00541295
    //                              World.cpp:528 (53)
    //         00541260     PUSH       0x2c
    //         00541262     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541267     ADD        ESP,0x4
    //         0054126a     MOV        dword ptr [ESP + param_2],EAX
    //         0054126e     TEST       EAX,EAX
    //         00541270     MOV        dword ptr [ESP + local_4],0x0
    //         00541278     JZ         LAB_00541288
    //         0054127a     MOV        this,dword ptr [ESP + param_3]
    //         0054127e     PUSH       this
    //         0054127f     MOV        this,EAX
    //         00541281     CALL       RGE_Master_Player::RGE_Master_Player             undefined RGE_Master_Player(RGE_Master_Player
    //         00541286     JMP        LAB_0054128a
    //                               LAB_00541288                                                 XREF[1]:     00541278(j)  
    //         00541288     XOR        EAX,EAX
    //                               LAB_0054128a                                                 XREF[1]:     00541286(j)  
    //         0054128a     MOVSX      EDX,word ptr [ESP + param_1]
    //         0054128f     MOV        this,dword ptr [ESI + 0x48]
    //         00541292     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                               LAB_00541295                                                 XREF[1]:     0054125e(j)  
    //                              World.cpp:535 (18)
    //         00541295     MOV        this,dword ptr [ESP + local_c]
    //         00541299     POP        ESI
    //         0054129a     MOV        dword ptr FS:[0x0],this
    //         005412a1     ADD        ESP,0xc
    //         005412a4     RET        0xc
    //         005412a7     ??         90h
    //         005412a8     NOP
    //         005412a9     NOP
    //         005412aa     NOP
    //         005412ab     NOP
    //         005412ac     NOP
    //         005412ad     NOP
    //         005412ae     NOP
    //         005412af     NOP
    return 0;
}

uchar RGE_Game_World::data_load_players(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_players(RGE_Game_World * this, char * par
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[4]:     005412b0(R), 005412d4(*), 00541300(R), 0054133a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054130e(*), 0054132b(R)  
    //              short             Stack[-0x8]:2  id                        XREF[2]:     0054130a(*), 00541327(R)  
    //              short             Stack[-0xc]:2  type
    //                               ?data_load_players@RGE_Game_World@@MAEEPAD@Z                 XREF[2]:     00577460(*), 00577918(*)  
    //                               RGE_Game_World::data_load_players
    //                              World.cpp:539 (27)
    //         005412b0     MOV        EAX,dword ptr [ESP + param_1]
    //         005412b4     SUB        ESP,0x8
    //         005412b7     PUSH       ESI
    //         005412b8     PUSH       EDI
    //         005412b9     PUSH       s_r                                              = "r"
    //         005412be     MOV        EDI,this
    //         005412c0     PUSH       EAX
    //         005412c1     CALL       fopen                                            undefined fopen()
    //         005412c6     MOV        ESI,EAX
    //         005412c8     ADD        ESP,0x8
    //                              World.cpp:547 (9)
    //         005412cb     TEST       ESI,ESI
    //         005412cd     JZ         LAB_0054136b
    //         005412d3     PUSH       EBX
    //                              World.cpp:549 (28)
    //         005412d4     LEA        this=>param_1,[ESP + 0x18]
    //         005412d8     LEA        EBX,[EDI + 0x44]
    //         005412db     PUSH       this
    //         005412dc     PUSH       EBX
    //         005412dd     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         005412e2     PUSH       ESI
    //         005412e3     CALL       fscanf                                           undefined fscanf()
    //         005412e8     ADD        ESP,0x10
    //         005412eb     CMP        EAX,-0x1
    //         005412ee     JZ         LAB_00541355
    //                              World.cpp:551 (11)
    //         005412f0     MOVSX      EDX,word ptr [EBX]
    //         005412f3     PUSH       0x4
    //         005412f5     PUSH       EDX
    //         005412f6     CALL       calloc                                           undefined calloc()
    //                              World.cpp:552 (15)
    //         005412fb     XOR        EBX,EBX
    //         005412fd     ADD        ESP,0x8
    //         00541300     CMP        word ptr [ESP + param_1],BX
    //         00541305     MOV        dword ptr [EDI + 0x48],EAX
    //         00541308     JLE        LAB_00541361
    //                               LAB_0054130a                                                 XREF[1]:     0054133f(j)  
    //                              World.cpp:553 (29)
    //         0054130a     LEA        EAX=>id,[ESP + 0xc]
    //         0054130e     LEA        this=>local_4,[ESP + 0x10]
    //         00541312     PUSH       EAX
    //         00541313     PUSH       this=>DAT_fffffff8
    //         00541314     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00541319     PUSH       ESI=>DAT_fffffff0
    //         0054131a     CALL       fscanf                                           undefined fscanf()
    //         0054131f     ADD        ESP,0x10
    //         00541322     CMP        EAX,-0x1
    //         00541325     JZ         LAB_00541339
    //                              World.cpp:554 (26)
    //         00541327     MOV        EAX,dword ptr [ESP + id]
    //         0054132b     MOV        this,dword ptr [ESP + local_4]
    //         0054132f     MOV        EDX,dword ptr [EDI]
    //         00541331     PUSH       ESI
    //         00541332     PUSH       EAX
    //         00541333     PUSH       this
    //         00541334     MOV        this,EDI
    //         00541336     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_00541339                                                 XREF[1]:     00541325(j)  
    //         00541339     INC        EBX
    //         0054133a     CMP        BX,word ptr [ESP + param_1]
    //         0054133f     JL         LAB_0054130a
    //                              World.cpp:561 (9)
    //         00541341     PUSH       ESI
    //         00541342     CALL       fclose                                           undefined fclose()
    //         00541347     ADD        ESP,0x4
    //                              World.cpp:563 (3)
    //         0054134a     MOV        AL,0x1
    //         0054134c     POP        EBX
    //                              World.cpp:564 (8)
    //         0054134d     POP        EDI
    //         0054134e     POP        ESI
    //         0054134f     ADD        ESP,0x8
    //         00541352     RET        0x4
    //                               LAB_00541355                                                 XREF[1]:     005412ee(j)  
    //                              World.cpp:558 (5)
    //         00541355     MOV        word ptr [EBX],0x0
    //                              World.cpp:559 (7)
    //         0054135a     MOV        dword ptr [EDI + 0x48],0x0
    //                               LAB_00541361                                                 XREF[1]:     00541308(j)  
    //                              World.cpp:561 (10)
    //         00541361     PUSH       ESI
    //         00541362     CALL       fclose                                           undefined fclose()
    //         00541367     ADD        ESP,0x4
    //         0054136a     POP        EBX
    //                               LAB_0054136b                                                 XREF[1]:     005412cd(j)  
    //                              World.cpp:564 (10)
    //         0054136b     POP        EDI
    //         0054136c     MOV        AL,0x1
    //         0054136e     POP        ESI
    //         0054136f     ADD        ESP,0x8
    //         00541372     RET        0x4
    //         00541375     ??         90h
    //         00541376     NOP
    //         00541377     NOP
    //         00541378     NOP
    //         00541379     NOP
    //         0054137a     NOP
    //         0054137b     NOP
    //         0054137c     NOP
    //         0054137d     NOP
    //         0054137e     NOP
    //         0054137f     NOP
    return 0;
}

uchar RGE_Game_World::data_load_objects(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_objects(RGE_Game_World * this, char * par
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     00541380(R), 005413ce(*), 005413fa(R)  
    //              short             Stack[-0x8]:2  type
    //              short             Stack[-0xc]:2  in_id                     XREF[2]:     005413ea(*), 00541408(R)  
    //              undefined2        Stack[-0xe]:2  local_e                   XREF[3]:     005413a3(*), 005413c2(R), 00541477(R)  
    //              short             Stack[-0x10]:2 count
    //              short             Stack[-0x12]:2 player_count
    //                               ?data_load_objects@RGE_Game_World@@MAEEPAD@Z                 XREF[2]:     00577464(*), 0057791c(*)  
    //                               RGE_Game_World::data_load_objects
    //                              World.cpp:568 (27)
    //         00541380     MOV        EAX,dword ptr [ESP + param_1]
    //         00541384     SUB        ESP,0x10
    //         00541387     PUSH       ESI
    //         00541388     PUSH       EDI
    //         00541389     PUSH       s_r                                              = "r"
    //         0054138e     MOV        EDI,this
    //         00541390     PUSH       EAX
    //         00541391     CALL       fopen                                            undefined fopen()
    //         00541396     MOV        ESI,EAX
    //         00541398     ADD        ESP,0x8
    //                              World.cpp:579 (8)
    //         0054139b     TEST       ESI,ESI
    //         0054139d     JZ         LAB_0054148d
    //                              World.cpp:581 (29)
    //         005413a3     LEA        this=>local_e,[ESP + 0xa]
    //         005413a7     PUSH       EBP
    //         005413a8     PUSH       this
    //         005413a9     PUSH       s_%hd                                            = "%hd"
    //         005413ae     PUSH       ESI
    //         005413af     CALL       fscanf                                           undefined fscanf()
    //         005413b4     ADD        ESP,0xc
    //         005413b7     CMP        EAX,-0x1
    //         005413ba     JZ         LAB_00541483
    //                              World.cpp:582 (13)
    //         005413c0     XOR        EBP,EBP
    //         005413c2     CMP        word ptr [ESP + local_e],BP
    //         005413c7     JLE        LAB_00541483
    //                              World.cpp:568 (1)
    //         005413cd     PUSH       EBX
    //                               LAB_005413ce                                                 XREF[1]:     0054147c(j)  
    //                              World.cpp:583 (28)
    //         005413ce     LEA        EDX=>param_1,[ESP + 0x24]
    //         005413d2     PUSH       EDX
    //         005413d3     PUSH       s_%hd                                            = "%hd"
    //         005413d8     PUSH       ESI=>DAT_fffffff4
    //         005413d9     CALL       fscanf                                           undefined fscanf()
    //         005413de     ADD        ESP,0xc
    //         005413e1     CMP        EAX,-0x1
    //         005413e4     JZ         LAB_00541476
    //                              World.cpp:586 (16)
    //         005413ea     LEA        EAX=>in_id,[ESP + 0x14]
    //         005413ee     PUSH       EAX
    //         005413ef     PUSH       s_%hd                                            = "%hd"
    //         005413f4     PUSH       ESI
    //         005413f5     CALL       fscanf                                           undefined fscanf()
    //                              World.cpp:587 (24)
    //         005413fa     MOVSX      this,word ptr [ESP + param_1]
    //         005413ff     MOV        EDX,dword ptr [EDI + 0x48]
    //         00541402     ADD        ESP,0xc
    //         00541405     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00541408     MOV        EDX,dword ptr [ESP + in_id]
    //         0054140c     PUSH       EDX
    //         0054140d     MOV        EAX,dword ptr [this->_padding_]
    //         0054140f     CALL       dword ptr [EAX + 0xc]
    //                              World.cpp:589 (16)
    //         00541412     LEA        EAX,[ESP + 0x14]
    //         00541416     PUSH       EAX
    //         00541417     PUSH       s_%hd                                            = "%hd"
    //         0054141c     PUSH       ESI=>DAT_fffffff4
    //         0054141d     CALL       fscanf                                           undefined fscanf()
    //                              World.cpp:590 (12)
    //         00541422     XOR        EBX,EBX
    //         00541424     ADD        ESP,0xc
    //         00541427     CMP        word ptr [ESP + 0x14],BX
    //         0054142c     JLE        LAB_00541476
    //                               LAB_0054142e                                                 XREF[1]:     00541474(j)  
    //                              World.cpp:591 (29)
    //         0054142e     LEA        this,[ESP + 0x18]
    //         00541432     LEA        EDX,[ESP + 0x1c]
    //         00541436     PUSH       this
    //         00541437     PUSH       EDX=>DAT_fffffff8
    //         00541438     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         0054143d     PUSH       ESI=>DAT_fffffff0
    //         0054143e     CALL       fscanf                                           undefined fscanf()
    //         00541443     ADD        ESP,0x10
    //         00541446     CMP        EAX,-0x1
    //         00541449     JZ         LAB_0054146e
    //                              World.cpp:595 (43)
    //         0054144b     MOVSX      EAX,word ptr [ESP + 0x24]
    //         00541450     MOV        this,dword ptr [EDI + 0x48]
    //         00541453     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00541456     MOV        EAX,dword ptr [ESP + 0x18]
    //         0054145a     PUSH       EAX
    //         0054145b     MOV        EAX,dword ptr [EDI + 0x30]
    //         0054145e     MOV        EDX,dword ptr [this->_padding_]
    //         00541460     PUSH       EAX=>DAT_fffffff8
    //         00541461     MOV        EAX,dword ptr [EDI + 0x38]
    //         00541464     PUSH       EAX=>DAT_fffffff4
    //         00541465     MOV        EAX,dword ptr [ESP + 0x28]
    //         00541469     PUSH       EAX=>DAT_fffffff0
    //         0054146a     PUSH       ESI
    //         0054146b     CALL       dword ptr [EDX + 0x10]
    //                               LAB_0054146e                                                 XREF[1]:     00541449(j)  
    //         0054146e     INC        EBX
    //         0054146f     CMP        BX,word ptr [ESP + 0x14]
    //         00541474     JL         LAB_0054142e
    //                               LAB_00541476                                                 XREF[2]:     005413e4(j), 0054142c(j)  
    //                              World.cpp:582 (12)
    //         00541476     INC        EBP
    //         00541477     CMP        BP,word ptr [ESP + local_e]
    //         0054147c     JL         LAB_005413ce
    //                              World.cpp:568 (1)
    //         00541482     POP        EBX
    //                               LAB_00541483                                                 XREF[2]:     005413ba(j), 005413c7(j)  
    //                              World.cpp:598 (10)
    //         00541483     PUSH       ESI
    //         00541484     CALL       fclose                                           undefined fclose()
    //         00541489     ADD        ESP,0x4
    //         0054148c     POP        EBP
    //                               LAB_0054148d                                                 XREF[1]:     0054139d(j)  
    //                              World.cpp:601 (10)
    //         0054148d     POP        EDI
    //         0054148e     MOV        AL,0x1
    //         00541490     POP        ESI
    //         00541491     ADD        ESP,0x10
    //         00541494     RET        0x4
    //         00541497     ??         90h
    //         00541498     NOP
    //         00541499     NOP
    //         0054149a     NOP
    //         0054149b     NOP
    //         0054149c     NOP
    //         0054149d     NOP
    //         0054149e     NOP
    //         0054149f     NOP
    return 0;
}

void RGE_Game_World::data_load_effects(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall data_load_effects(RGE_Game_World * this, char * para
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     005414d3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005414c9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005414e3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     005414c3(W)  
    //                               ?data_load_effects@RGE_Game_World@@MAEXPAD@Z                 XREF[2]:     00577478(*), 00577930(*)  
    //                               RGE_Game_World::data_load_effects
    //                              World.cpp:605 (25)
    //         005414a0     PUSH       -0x1
    //         005414a2     PUSH       FUN_00561cab
    //         005414a7     MOV        EAX,FS:[0x0]
    //         005414ad     PUSH       EAX
    //         005414ae     MOV        dword ptr FS:[0x0],ESP
    //         005414b5     PUSH       this
    //         005414b6     PUSH       ESI
    //         005414b7     MOV        ESI,this
    //                              World.cpp:606 (42)
    //         005414b9     PUSH       0xc
    //         005414bb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005414c0     ADD        ESP,0x4
    //         005414c3     MOV        dword ptr [ESP + local_10],EAX
    //         005414c7     TEST       EAX,EAX
    //         005414c9     MOV        dword ptr [ESP + local_4],0x0
    //         005414d1     JZ         LAB_005414e1
    //         005414d3     MOV        this,dword ptr [ESP + param_1]
    //         005414d7     PUSH       this
    //         005414d8     MOV        this,EAX
    //         005414da     CALL       RGE_Effects::RGE_Effects                         undefined RGE_Effects(RGE_Effects * this, cha
    //         005414df     JMP        LAB_005414e3
    //                               LAB_005414e1                                                 XREF[1]:     005414d1(j)  
    //         005414e1     XOR        EAX,EAX
    //                               LAB_005414e3                                                 XREF[1]:     005414df(j)  
    //                              World.cpp:607 (21)
    //         005414e3     MOV        this,dword ptr [ESP + local_c]
    //         005414e7     MOV        dword ptr [ESI + 0x4c],EAX
    //         005414ea     MOV        dword ptr FS:[0x0],this
    //         005414f1     POP        ESI
    //         005414f2     ADD        ESP,0x10
    //         005414f5     RET        0x4
    //         005414f8     ??         90h
    //         005414f9     NOP
    //         005414fa     NOP
    //         005414fb     NOP
    //         005414fc     NOP
    //         005414fd     NOP
    //         005414fe     NOP
    //         005414ff     NOP
    //                              * protected: virtual void __thiscall RGE_Game_World::data_load_map(char *,char *,char *,char *,short... *
    //                              void __thiscall data_load_map(RGE_Game_World * this, char * param_1,
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00541553(R)  
    //              char *            Stack[0x8]:4   param_2
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     0054154e(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[1]:     00541549(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[1]:     00541544(R)  
    //              short             Stack[0x18]:2  param_6                   XREF[1]:     0054153f(R)  
    //              short             Stack[0x1c]:2  param_7                   XREF[1]:     0054153a(R)  
    //              RGE_Sound * *     Stack[0x20]:4  param_8                   XREF[1]:     00541536(R)  
    //              char *            Stack[0x24]:4  param_9                   XREF[1]:     00541564(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054152c(W), 0054156b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0054157b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541526(W)  
    //                               ?data_load_map@RGE_Game_World@@MAEXPAD000FFFPAPAVRGE_Sound@  XREF[1]:     00577934(*)  
    //                               RGE_Game_World::data_load_map
    //                              World.cpp:611 (25)
    //         00541500     PUSH       -0x1
    //         00541502     PUSH       FUN_00561ccb
    //         00541507     MOV        EAX,FS:[0x0]
    //         0054150d     PUSH       EAX
    //         0054150e     MOV        dword ptr FS:[0x0],ESP
    //         00541515     PUSH       this
    //         00541516     PUSH       ESI
    //         00541517     MOV        ESI,this
    //                              World.cpp:612 (75)
    //         00541519     PUSH       0x8dd0
    //         0054151e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541523     ADD        ESP,0x4
    //         00541526     MOV        dword ptr [ESP + local_10],EAX
    //         0054152a     TEST       EAX,EAX
    //         0054152c     MOV        dword ptr [ESP + local_4],0x0
    //         00541534     JZ         LAB_00541562
    //         00541536     MOV        this,dword ptr [ESP + param_8]
    //         0054153a     MOV        EDX,dword ptr [ESP + param_7]
    //         0054153e     PUSH       this
    //         0054153f     MOV        this,dword ptr [ESP + param_6]
    //         00541543     PUSH       EDX
    //         00541544     MOV        EDX,dword ptr [ESP + param_5]
    //         00541548     PUSH       this
    //         00541549     MOV        this,dword ptr [ESP + param_4]
    //         0054154d     PUSH       EDX
    //         0054154e     MOV        EDX,dword ptr [ESP + param_3]
    //         00541552     PUSH       this
    //         00541553     MOV        this,dword ptr [ESP + param_1]
    //         00541557     PUSH       EDX
    //         00541558     PUSH       this
    //         00541559     MOV        this,EAX
    //         0054155b     CALL       RGE_Map::RGE_Map                                 undefined RGE_Map(RGE_Map * this, char * para
    //         00541560     JMP        LAB_00541564
    //                               LAB_00541562                                                 XREF[1]:     00541534(j)  
    //         00541562     XOR        EAX,EAX
    //                               LAB_00541564                                                 XREF[1]:     00541560(j)  
    //                              World.cpp:613 (23)
    //         00541564     MOV        EDX,dword ptr [ESP + param_9]
    //         00541568     MOV        this,EAX
    //         0054156a     PUSH       EDX
    //         0054156b     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00541573     MOV        dword ptr [ESI + 0x28],EAX
    //         00541576     CALL       RGE_Map::load_terrain_obj_types                  void load_terrain_obj_types(RGE_Map * this, c
    //                              World.cpp:614 (18)
    //         0054157b     MOV        this,dword ptr [ESP + local_c]
    //         0054157f     POP        ESI
    //         00541580     MOV        dword ptr FS:[0x0],this
    //         00541587     ADD        ESP,0x10
    //         0054158a     RET        0x24
    //         0054158d     ??         90h
    //         0054158e     NOP
    //         0054158f     NOP
    return;
}

void RGE_Game_World::data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {
    /* TODO: Stub */
    //                              void __thiscall data_load_random_map(RGE_Game_World * this, char * p
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     005415a4(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0054159f(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00541598(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[1]:     00541590(R)  
    //                               ?data_load_random_map@RGE_Game_World@@MAEXPAD000@Z           XREF[2]:     00577480(*), 00577938(*)  
    //                               RGE_Game_World::data_load_random_map
    //                              World.cpp:618 (28)
    //         00541590     MOV        EDX,dword ptr [ESP + param_4]
    //         00541594     MOV        this,dword ptr [ECX + this->map]
    //         00541597     PUSH       EDX
    //         00541598     MOV        EDX,dword ptr [ESP + param_3]
    //         0054159c     MOV        EAX,dword ptr [this->_padding_]
    //         0054159e     PUSH       EDX
    //         0054159f     MOV        EDX,dword ptr [ESP + param_2]
    //         005415a3     PUSH       EDX
    //         005415a4     MOV        EDX,dword ptr [ESP + param_1]
    //         005415a8     PUSH       EDX
    //         005415a9     CALL       dword ptr [EAX + 0x8]
    //                              World.cpp:620 (3)
    //         005415ac     RET        0x10
    //         005415af     ??         90h
    return;
}

uchar RGE_Game_World::data_load_world(_iobuf* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load_world(RGE_Game_World * this, _iobuf * par
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0054163a(R)  
    //              char[23]          Stack[-0x1c]   rmm_map_file              XREF[0,1]:   005415e0(*)  
    //              char[23]          Stack[-0x34]   terrain_table_file        XREF[0,2]:   00541641(*), 0054165a(*)  
    //              char[23]          Stack[-0x4c]   rmm_land_file             XREF[0,1]:   005415d8(*)  
    //              char[23]          Stack[-0x64]   sound_file                XREF[0,1]:   0054162a(*)  
    //              char[23]          Stack[-0x7c]   rmm_terr_file             XREF[0,1]:   005415d0(*)  
    //              char[23]          Stack[-0x94]   player_file               XREF[0,1]:   005415fd(*)  
    //              char[23]          Stack[-0xac]   rmm_obj_file              XREF[0,1]:   005415c8(*)  
    //              char[23]          Stack[-0xc4]   terr_obj_file             XREF[0,1]:   005415e8(*)  
    //              char[23]          Stack[-0xdc]   border_file               XREF[0,1]:   00541622(*)  
    //              char[23]          Stack[-0xf4]   obj_file                  XREF[0,1]:   005415f5(*)  
    //              char[23]          Stack[-0x10c   overlay_file              XREF[0,1]:   0054161a(*)  
    //              char[23]          Stack[-0x124   sprite_file               XREF[0,1]:   00541605(*)  
    //              char[23]          Stack[-0x13c   terrain_file              XREF[0,1]:   00541612(*)  
    //              char[23]          Stack[-0x154   color_file                XREF[0,1]:   00541632(*)  
    //              char[23]          Stack[-0x16c   map_file                  XREF[0,1]:   0054160d(*)  
    //              char[23]          Stack[-0x184   effects_file              XREF[1,1]:   005415ba(*), 005415f0(*)  
    //              short             Stack[-0x188   tile_width                XREF[1]:     005415b6(*)  
    //              short             Stack[-0x18c   elev_height               XREF[1]:     005415c2(*)  
    //              short             Stack[-0x190   tile_height
    //                               ?data_load_world@RGE_Game_World@@MAEEPAU_iobuf@@@Z           XREF[2]:     data_load_world:0052e372(c), 
    //                               RGE_Game_World::data_load_world                                           00577910(*)  
    //                              World.cpp:624 (6)
    //         005415b0     SUB        ESP,0x18c
    //                              World.cpp:665 (159)
    //         005415b6     LEA        EAX=>tile_width,[ESP + 0x4]
    //         005415ba     LEA        EDX=>effects_file,[ESP + 0x8]
    //         005415be     PUSH       ESI
    //         005415bf     MOV        ESI,this
    //         005415c1     PUSH       EDI
    //         005415c2     LEA        this=>elev_height,[ESP + 0x8]
    //         005415c6     PUSH       EAX
    //         005415c7     PUSH       this
    //         005415c8     LEA        EAX=>rmm_obj_file[4],[ESP + 0xf4]
    //         005415cf     PUSH       EDX
    //         005415d0     LEA        this=>rmm_terr_file[4],[ESP + 0x128]
    //         005415d7     PUSH       EAX
    //         005415d8     LEA        EDX=>rmm_land_file[4],[ESP + 0x15c]
    //         005415df     PUSH       this
    //         005415e0     LEA        EAX=>rmm_map_file[4],[ESP + 0x190]
    //         005415e7     PUSH       EDX
    //         005415e8     LEA        this=>terr_obj_file[4],[ESP + 0xec]
    //         005415ef     PUSH       EAX
    //         005415f0     LEA        EDX=>effects_file[4],[ESP + 0x30]
    //         005415f4     PUSH       this
    //         005415f5     LEA        EAX=>obj_file[4],[ESP + 0xc4]
    //         005415fc     PUSH       EDX
    //         005415fd     LEA        this=>player_file[4],[ESP + 0x128]
    //         00541604     PUSH       EAX
    //         00541605     LEA        EDX=>sprite_file[4],[ESP + 0x9c]
    //         0054160c     PUSH       this
    //         0054160d     LEA        EAX=>map_file[4],[ESP + 0x58]
    //         00541611     PUSH       EDX
    //         00541612     LEA        this=>terrain_file[4],[ESP + 0x8c]
    //         00541619     PUSH       EAX
    //         0054161a     LEA        EDX=>overlay_file[4],[ESP + 0xc0]
    //         00541621     PUSH       this
    //         00541622     LEA        EAX=>border_file[4],[ESP + 0xf4]
    //         00541629     PUSH       EDX
    //         0054162a     LEA        this=>sound_file[4],[ESP + 0x170]
    //         00541631     PUSH       EAX
    //         00541632     LEA        EDX=>color_file[4],[ESP + 0x84]
    //         00541639     PUSH       this
    //         0054163a     MOV        this,dword ptr [ESP + param_1]
    //         00541641     LEA        EAX=>terrain_table_file[4],[ESP + 0x1a8]
    //         00541648     PUSH       EDX
    //         00541649     PUSH       EAX
    //         0054164a     PUSH       s_%s_%s_%s_%s_%s_%s_%s_%s_%s_%s_%s               = "%s %s %s %s %s %s %s %s %s %s %s %s %s %s 
    //         0054164f     PUSH       this
    //         00541650     CALL       fscanf                                           undefined fscanf()
    //                              World.cpp:668 (18)
    //         00541655     MOV        EDI,dword ptr [ESI]
    //         00541657     ADD        ESP,0x54
    //         0054165a     LEA        EDX=>terrain_table_file[4],[ESP + 0x164]
    //         00541661     MOV        this,ESI
    //         00541663     PUSH       EDX
    //         00541664     CALL       dword ptr [EDI + 0x4]
    //                              World.cpp:671 (10)
    //         00541667     LEA        EAX,[ESP + 0x44]
    //         0054166b     MOV        this,ESI
    //         0054166d     PUSH       EAX
    //         0054166e     CALL       dword ptr [EDI + 0x14]
    //                              World.cpp:674 (13)
    //         00541671     LEA        this,[ESP + 0x134]
    //         00541678     PUSH       this
    //         00541679     MOV        this,ESI
    //         0054167b     CALL       dword ptr [EDI + 0x10]
    //                              World.cpp:677 (10)
    //         0054167e     LEA        EDX,[ESP + 0x74]
    //         00541682     MOV        this,ESI
    //         00541684     PUSH       EDX
    //         00541685     CALL       dword ptr [EDI + 0x18]
    //                              World.cpp:680 (13)
    //         00541688     LEA        EAX,[ESP + 0x104]
    //         0054168f     MOV        this,ESI
    //         00541691     PUSH       EAX
    //         00541692     CALL       dword ptr [EDI + 0x8]
    //                              World.cpp:683 (13)
    //         00541695     LEA        this,[ESP + 0xa4]
    //         0054169c     PUSH       this
    //         0054169d     MOV        this,ESI
    //         0054169f     CALL       dword ptr [EDI + 0xc]
    //                              World.cpp:686 (10)
    //         005416a2     LEA        EDX,[ESP + 0x14]
    //         005416a6     MOV        this,ESI
    //         005416a8     PUSH       EDX
    //         005416a9     CALL       dword ptr [EDI + 0x20]
    //                              World.cpp:689 (58)
    //         005416ac     MOV        this,dword ptr [ESI + 0x30]
    //         005416af     MOV        EDX,dword ptr [ESP + 0xc]
    //         005416b3     LEA        EAX,[ESP + 0xd4]
    //         005416ba     PUSH       EAX
    //         005416bb     PUSH       this=>DAT_fffffff8
    //         005416bc     MOV        EAX,dword ptr [ESP + 0x10]
    //         005416c0     MOV        this,dword ptr [ESP + 0x18]
    //         005416c4     PUSH       EDX=>DAT_fffffff4
    //         005416c5     PUSH       EAX=>DAT_fffffff0
    //         005416c6     LEA        EDX,[ESP + 0x3c]
    //         005416ca     PUSH       this
    //         005416cb     LEA        EAX,[ESP + 0x70]
    //         005416cf     PUSH       EDX
    //         005416d0     LEA        this,[ESP + 0xa4]
    //         005416d7     PUSH       EAX
    //         005416d8     LEA        EDX,[ESP + 0xd8]
    //         005416df     PUSH       this
    //         005416e0     PUSH       EDX
    //         005416e1     MOV        this,ESI
    //         005416e3     CALL       dword ptr [EDI + 0x24]
    //                              World.cpp:692 (37)
    //         005416e6     LEA        EAX,[ESP + 0xec]
    //         005416ed     LEA        this,[ESP + 0x11c]
    //         005416f4     PUSH       EAX
    //         005416f5     LEA        EDX,[ESP + 0x150]
    //         005416fc     PUSH       this=>DAT_fffffff8
    //         005416fd     LEA        EAX,[ESP + 0x184]
    //         00541704     PUSH       EDX=>DAT_fffffff4
    //         00541705     PUSH       EAX=>DAT_fffffff0
    //         00541706     MOV        this,ESI
    //         00541708     CALL       dword ptr [EDI + 0x28]
    //                              World.cpp:695 (13)
    //         0054170b     POP        EDI
    //         0054170c     MOV        AL,0x1
    //         0054170e     POP        ESI
    //         0054170f     ADD        ESP,0x18c
    //         00541715     RET        0x4
    //         00541718     ??         90h
    //         00541719     NOP
    //         0054171a     NOP
    //         0054171b     NOP
    //         0054171c     NOP
    //         0054171d     NOP
    //         0054171e     NOP
    //         0054171f     NOP
    return 0;
}

uchar RGE_Game_World::data_load(char* param_1, char* param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall data_load(RGE_Game_World * this, char * param_1, ch
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00541720(R)  
    //                               ?data_load@RGE_Game_World@@UAEEPAD0@Z                        XREF[2]:     00577504(*), 005779bc(*)  
    //                               RGE_Game_World::data_load
    //                              World.cpp:699 (24)
    //         00541720     MOV        EAX,dword ptr [ESP + param_2]
    //         00541724     PUSH       ESI
    //         00541725     PUSH       EDI
    //         00541726     PUSH       s_r                                              = "r"
    //         0054172b     MOV        ESI,this
    //         0054172d     PUSH       EAX
    //         0054172e     CALL       fopen                                            undefined fopen()
    //         00541733     MOV        EDI,EAX
    //         00541735     ADD        ESP,0x8
    //                              World.cpp:704 (5)
    //         00541738     TEST       EDI,EDI
    //         0054173a     JZ         LAB_00541762
    //         0054173c     PUSH       EBX
    //                              World.cpp:706 (7)
    //         0054173d     MOV        EBX,dword ptr [ESI]
    //         0054173f     PUSH       EDI
    //         00541740     MOV        this,ESI
    //         00541742     CALL       dword ptr [EBX]
    //                              World.cpp:707 (6)
    //         00541744     PUSH       EDI
    //         00541745     CALL       fclose                                           undefined fclose()
    //                              World.cpp:708 (16)
    //         0054174a     MOV        this,dword ptr [ESP + 0x14]
    //         0054174e     ADD        ESP,0x4
    //         00541751     PUSH       this
    //         00541752     MOV        this,ESI
    //         00541754     CALL       dword ptr [EBX + 0xdc]
    //                              World.cpp:713 (3)
    //         0054175a     MOV        AL,0x1
    //         0054175c     POP        EBX
    //                              World.cpp:714 (12)
    //         0054175d     POP        EDI
    //         0054175e     POP        ESI
    //         0054175f     RET        0x8
    //                               LAB_00541762                                                 XREF[1]:     0054173a(j)  
    //         00541762     POP        EDI
    //         00541763     XOR        AL,AL
    //         00541765     POP        ESI
    //         00541766     RET        0x8
    //         00541769     ??         90h
    //         0054176a     NOP
    //         0054176b     NOP
    //         0054176c     NOP
    //         0054176d     NOP
    //         0054176e     NOP
    //         0054176f     NOP
    return 0;
}

uchar RGE_Game_World::init_player_type(int param_1, short param_2, uchar param_3) {
    /* TODO: Stub */
    //                              uchar __thiscall init_player_type(RGE_Game_World * this, int param_1
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0054179f(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     005417bb(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0054177e(R), 0054179b(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005417a3(W), 005417c3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005417e6(R)  
    //                               ?init_player_type@RGE_Game_World@@MAEEHFE@Z                  XREF[2]:     init_player_type:0052e433(c), 
    //                               RGE_Game_World::init_player_type                                          0057793c(*)  
    //                              World.cpp:718 (14)
    //         00541770     MOV        EAX,FS:[0x0]
    //         00541776     PUSH       -0x1
    //         00541778     PUSH       FUN_00561ceb
    //         0054177d     PUSH       EAX
    //                              World.cpp:719 (19)
    //         0054177e     MOV        AL,byte ptr [ESP + param_3]
    //         00541782     MOV        dword ptr FS:[0x0],ESP
    //         00541789     PUSH       ESI
    //         0054178a     MOV        ESI,this
    //         0054178c     TEST       AL,AL
    //         0054178e     JNZ        LAB_005417e6
    //         00541790     PUSH       EDI
    //                              World.cpp:722 (64)
    //         00541791     PUSH       0x2c
    //         00541793     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541798     ADD        ESP,0x4
    //         0054179b     MOV        dword ptr [ESP + param_3],EAX
    //         0054179f     MOV        EDI,dword ptr [ESP + param_1]
    //         005417a3     MOV        dword ptr [ESP + local_4],0x0
    //         005417ab     TEST       EAX,EAX
    //         005417ad     JZ         LAB_005417b9
    //         005417af     PUSH       EDI
    //         005417b0     MOV        this,EAX
    //         005417b2     CALL       RGE_Master_Player::RGE_Master_Player             undefined RGE_Master_Player(RGE_Master_Player
    //         005417b7     JMP        LAB_005417bb
    //                               LAB_005417b9                                                 XREF[1]:     005417ad(j)  
    //         005417b9     XOR        EAX,EAX
    //                               LAB_005417bb                                                 XREF[1]:     005417b7(j)  
    //         005417bb     MOVSX      this,word ptr [ESP + param_2]
    //         005417c0     MOV        EDX,dword ptr [ESI + 0x48]
    //         005417c3     MOV        dword ptr [ESP + local_4],0xffffffff
    //         005417cb     SHL        this,0x2
    //         005417ce     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
    //                              World.cpp:723 (21)
    //         005417d1     MOV        EAX,dword ptr [ESI + 0x48]
    //         005417d4     MOV        this,dword ptr [EAX + this->_padding_*0x1]
    //         005417d7     MOV        EAX,dword ptr [ESI + 0x30]
    //         005417da     PUSH       EAX
    //         005417db     MOV        EAX,dword ptr [ESI + 0x38]
    //         005417de     MOV        EDX,dword ptr [this->_padding_]
    //         005417e0     PUSH       EAX
    //         005417e1     PUSH       EDI
    //         005417e2     CALL       dword ptr [EDX + 0x4]
    //         005417e5     POP        EDI
    //                               LAB_005417e6                                                 XREF[1]:     0054178e(j)  
    //                              World.cpp:731 (20)
    //         005417e6     MOV        this,dword ptr [ESP + local_c]
    //         005417ea     MOV        AL,0x1
    //         005417ec     MOV        dword ptr FS:[0x0],this
    //         005417f3     POP        ESI
    //         005417f4     ADD        ESP,0xc
    //         005417f7     RET        0xc
    //         005417fa     ??         90h
    //         005417fb     NOP
    //         005417fc     NOP
    //         005417fd     NOP
    //         005417fe     NOP
    //         005417ff     NOP
    return 0;
}

uchar RGE_Game_World::init_player(int param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall init_player(RGE_Game_World * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     00541807(R), 00541844(*), 00541851(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00541840(W), 0054185d(R)  
    //                               ?init_player@RGE_Game_World@@MAEEH@Z                         XREF[2]:     00577488(*), 00577940(*)  
    //                               RGE_Game_World::init_player
    //                              World.cpp:735 (7)
    //         00541800     PUSH       this
    //         00541801     PUSH       EBX
    //         00541802     PUSH       EBP
    //         00541803     MOV        EBP,this
    //         00541805     PUSH       ESI
    //         00541806     PUSH       EDI
    //                              World.cpp:739 (16)
    //         00541807     MOV        EDI,dword ptr [ESP + param_1]
    //         0054180b     LEA        EBX,[EBP + 0x44]
    //         0054180e     PUSH       0x2
    //         00541810     PUSH       EBX
    //         00541811     PUSH       EDI
    //         00541812     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:740 (11)
    //         00541817     MOV        AX,word ptr [EBX]
    //         0054181a     ADD        ESP,0xc
    //         0054181d     TEST       AX,AX
    //         00541820     JLE        LAB_00541867
    //                              World.cpp:742 (11)
    //         00541822     MOVSX      EAX,AX
    //         00541825     PUSH       0x4
    //         00541827     PUSH       EAX
    //         00541828     CALL       calloc                                           undefined calloc()
    //                              World.cpp:743 (13)
    //         0054182d     XOR        ESI,ESI
    //         0054182f     ADD        ESP,0x8
    //         00541832     CMP        word ptr [EBX],SI
    //         00541835     MOV        dword ptr [EBP + 0x48],EAX
    //         00541838     JLE        LAB_00541867
    //                              World.cpp:746 (45)
    //         0054183a     MOV        this,dword ptr [EBP]
    //         0054183d     MOV        EDX,dword ptr [ECX + this->sound_num]
    //         00541840     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_00541844                                                 XREF[1]:     00541865(j)  
    //         00541844     LEA        EAX=>param_1,[ESP + 0x18]
    //         00541848     PUSH       0x1
    //         0054184a     PUSH       EAX=>DAT_fffffff8
    //         0054184b     PUSH       EDI=>DAT_fffffff4
    //         0054184c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00541851     MOV        this,dword ptr [ESP + param_1]
    //         00541855     ADD        ESP,0xc
    //         00541858     PUSH       this
    //         00541859     PUSH       ESI
    //         0054185a     PUSH       EDI
    //         0054185b     MOV        this,EBP
    //         0054185d     CALL       dword ptr [ESP + local_4]
    //         00541861     INC        ESI
    //         00541862     CMP        SI,word ptr [EBX]
    //         00541865     JL         LAB_00541844
    //                               LAB_00541867                                                 XREF[2]:     00541820(j), 00541838(j)  
    //                              World.cpp:751 (10)
    //         00541867     POP        EDI
    //         00541868     POP        ESI
    //         00541869     POP        EBP
    //         0054186a     MOV        AL,0x1
    //         0054186c     POP        EBX
    //         0054186d     POP        this
    //         0054186e     RET        0x4
    //         00541871     ??         90h
    //         00541872     NOP
    //         00541873     NOP
    //         00541874     NOP
    //         00541875     NOP
    //         00541876     NOP
    //         00541877     NOP
    //         00541878     NOP
    //         00541879     NOP
    //         0054187a     NOP
    //         0054187b     NOP
    //         0054187c     NOP
    //         0054187d     NOP
    //         0054187e     NOP
    //         0054187f     NOP
    return 0;
}

void RGE_Game_World::terrain_tables_init(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall terrain_tables_init(RGE_Game_World * this, int param
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541882(R)  
    //                               ?terrain_tables_init@RGE_Game_World@@MAEXH@Z                 XREF[2]:     00577494(*), 0057794c(*)  
    //                               RGE_Game_World::terrain_tables_init
    //                              World.cpp:756 (2)
    //         00541880     PUSH       EBX
    //         00541881     PUSH       EBP
    //                              World.cpp:759 (23)
    //         00541882     MOV        EBP,dword ptr [ESP + param_1]
    //         00541886     PUSH       ESI
    //         00541887     MOV        ESI,this
    //         00541889     PUSH       EDI
    //         0054188a     PUSH       0x2
    //         0054188c     LEA        EBX,[ESI + 0x50]
    //         0054188f     PUSH       EBX
    //         00541890     PUSH       EBP
    //         00541891     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00541896     ADD        ESP,0xc
    //                              World.cpp:760 (12)
    //         00541899     LEA        EDI,[ESI + 0x52]
    //         0054189c     PUSH       0x2
    //         0054189e     PUSH       EDI
    //         0054189f     PUSH       EBP
    //         005418a0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:761 (17)
    //         005418a5     MOV        AX,word ptr [EBX]
    //         005418a8     ADD        ESP,0xc
    //         005418ab     TEST       AX,AX
    //         005418ae     JLE        LAB_0054191d
    //         005418b0     CMP        word ptr [EDI],0x0
    //         005418b4     JLE        LAB_0054191d
    //                              World.cpp:763 (11)
    //         005418b6     MOVSX      EAX,AX
    //         005418b9     PUSH       0x4
    //         005418bb     PUSH       EAX
    //         005418bc     CALL       calloc                                           undefined calloc()
    //                              World.cpp:764 (20)
    //         005418c1     MOVSX      this,word ptr [EBX]
    //         005418c4     ADD        ESP,0x8
    //         005418c7     MOV        dword ptr [ESI + 0x54],EAX
    //         005418ca     SHL        this,0x2
    //         005418cd     PUSH       this
    //         005418ce     PUSH       EAX
    //         005418cf     PUSH       EBP
    //         005418d0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:765 (11)
    //         005418d5     XOR        EBX,EBX
    //         005418d7     ADD        ESP,0xc
    //         005418da     CMP        word ptr [ESI + 0x50],BX
    //         005418de     JLE        LAB_0054191d
    //                               LAB_005418e0                                                 XREF[1]:     0054191b(j)  
    //                              World.cpp:766 (9)
    //         005418e0     MOV        EDX,dword ptr [ESI + 0x54]
    //         005418e3     CMP        dword ptr [EDX + EBX*0x4],0x0
    //         005418e7     JZ         LAB_00541914
    //                              World.cpp:768 (20)
    //         005418e9     MOVSX      EAX,word ptr [EDI]
    //         005418ec     PUSH       0x4
    //         005418ee     PUSH       EAX
    //         005418ef     CALL       calloc                                           undefined calloc()
    //         005418f4     MOV        this,dword ptr [ESI + 0x54]
    //         005418f7     ADD        ESP,0x8
    //         005418fa     MOV        dword ptr [this->_padding_ + EBX*0x4],EAX
    //                              World.cpp:769 (32)
    //         005418fd     MOV        EAX,dword ptr [ESI + 0x54]
    //         00541900     MOVSX      EDX,word ptr [EDI]
    //         00541903     MOV        this,dword ptr [EAX + EBX*0x4]
    //         00541906     SHL        EDX,0x2
    //         00541909     PUSH       EDX
    //         0054190a     PUSH       this
    //         0054190b     PUSH       EBP
    //         0054190c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00541911     ADD        ESP,0xc
    //                               LAB_00541914                                                 XREF[1]:     005418e7(j)  
    //         00541914     MOVSX      EDX,word ptr [ESI + 0x50]
    //         00541918     INC        EBX
    //         00541919     CMP        EBX,EDX
    //         0054191b     JL         LAB_005418e0
    //                               LAB_0054191d                                                 XREF[3]:     005418ae(j), 005418b4(j), 
    //                                                                                                         005418de(j)  
    //                              World.cpp:772 (7)
    //         0054191d     POP        EDI
    //         0054191e     POP        ESI
    //         0054191f     POP        EBP
    //         00541920     POP        EBX
    //         00541921     RET        0x4
    //         00541924     ??         90h
    //         00541925     NOP
    //         00541926     NOP
    //         00541927     NOP
    //         00541928     NOP
    //         00541929     NOP
    //         0054192a     NOP
    //         0054192b     NOP
    //         0054192c     NOP
    //         0054192d     NOP
    //         0054192e     NOP
    //         0054192f     NOP
    return;
}

void RGE_Game_World::color_table_init(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall color_table_init(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00541946(R), 0054199f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00541995(W), 005419b3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005419c3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0054198f(W)  
    //                               ?color_table_init@RGE_Game_World@@MAEXH@Z                    XREF[2]:     00577490(*), 00577948(*)  
    //                               RGE_Game_World::color_table_init
    //                              World.cpp:777 (22)
    //         00541930     PUSH       -0x1
    //         00541932     PUSH       FUN_00561d0b
    //         00541937     MOV        EAX,FS:[0x0]
    //         0054193d     PUSH       EAX
    //         0054193e     MOV        dword ptr FS:[0x0],ESP
    //         00541945     PUSH       this
    //                              World.cpp:780 (21)
    //         00541946     MOV        EAX,dword ptr [ESP + param_1]
    //         0054194a     PUSH       EBX
    //         0054194b     MOV        EBX,this
    //         0054194d     PUSH       ESI
    //         0054194e     PUSH       EDI
    //         0054194f     PUSH       0x2
    //         00541951     LEA        EDI,[EBX + 0x60]
    //         00541954     PUSH       EDI
    //         00541955     PUSH       EAX
    //         00541956     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:781 (11)
    //         0054195b     MOV        AX,word ptr [EDI]
    //         0054195e     ADD        ESP,0xc
    //         00541961     TEST       AX,AX
    //         00541964     JLE        LAB_005419c3
    //                              World.cpp:783 (11)
    //         00541966     MOVSX      this,AX
    //         00541969     PUSH       0x4
    //         0054196b     PUSH       this
    //         0054196c     CALL       calloc                                           undefined calloc()
    //                              World.cpp:784 (17)
    //         00541971     XOR        ESI,ESI
    //         00541973     ADD        ESP,0x8
    //         00541976     CMP        word ptr [EDI],SI
    //         00541979     MOV        dword ptr [EBX + 0x64],EAX
    //         0054197c     JLE        LAB_005419c3
    //         0054197e     PUSH       EBP
    //         0054197f     OR         EBP,0xffffffff
    //                               LAB_00541982                                                 XREF[1]:     005419c0(j)  
    //                              World.cpp:785 (64)
    //         00541982     PUSH       0x128
    //         00541987     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054198c     ADD        ESP,0x4
    //         0054198f     MOV        dword ptr [ESP + local_10],EAX
    //         00541993     TEST       EAX,EAX
    //         00541995     MOV        dword ptr [ESP + local_4],0x0
    //         0054199d     JZ         LAB_005419ad
    //         0054199f     MOV        EDX,dword ptr [ESP + param_1]
    //         005419a3     MOV        this,EAX
    //         005419a5     PUSH       EDX
    //         005419a6     CALL       RGE_Color_Table::RGE_Color_Table                 undefined RGE_Color_Table(RGE_Color_Table * t
    //         005419ab     JMP        LAB_005419af
    //                               LAB_005419ad                                                 XREF[1]:     0054199d(j)  
    //         005419ad     XOR        EAX,EAX
    //                               LAB_005419af                                                 XREF[1]:     005419ab(j)  
    //         005419af     MOV        this,dword ptr [EBX + 0x64]
    //         005419b2     INC        ESI
    //         005419b3     MOV        dword ptr [ESP + local_4],EBP
    //         005419b7     MOV        dword ptr [this->_padding_ + ESI*0x4 + -0x4],EAX
    //         005419bb     MOVSX      EDX,word ptr [EDI]
    //         005419be     CMP        ESI,EDX
    //         005419c0     JL         LAB_00541982
    //                              World.cpp:777 (1)
    //         005419c2     POP        EBP
    //                               LAB_005419c3                                                 XREF[2]:     00541964(j), 0054197c(j)  
    //                              World.cpp:787 (20)
    //         005419c3     MOV        this,dword ptr [ESP + local_c]
    //         005419c7     POP        EDI
    //         005419c8     POP        ESI
    //         005419c9     MOV        dword ptr FS:[0x0],this
    //         005419d0     POP        EBX
    //         005419d1     ADD        ESP,0x10
    //         005419d4     RET        0x4
    //         005419d7     ??         90h
    //         005419d8     NOP
    //         005419d9     NOP
    //         005419da     NOP
    //         005419db     NOP
    //         005419dc     NOP
    //         005419dd     NOP
    //         005419de     NOP
    //         005419df     NOP
    return;
}

void RGE_Game_World::init_sounds(int param_1, TSound_Driver* param_2) {
    /* TODO: Stub */
    //                              void __thiscall init_sounds(RGE_Game_World * this, int param_1, TSou
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     005419f7(R), 00541a30(W)  
    //              TSound_Driver *   Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00541a36(W), 00541a57(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541a6a(R)  
    //                               ?init_sounds@RGE_Game_World@@MAEXHPAVTSound_Driver@@@Z       XREF[2]:     00577498(*), 00577950(*)  
    //                               RGE_Game_World::init_sounds
    //                              World.cpp:792 (23)
    //         005419e0     MOV        EAX,FS:[0x0]
    //         005419e6     PUSH       -0x1
    //         005419e8     PUSH       FUN_00561d2b
    //         005419ed     PUSH       EAX
    //         005419ee     MOV        dword ptr FS:[0x0],ESP
    //         005419f5     PUSH       EBX
    //         005419f6     PUSH       EBP
    //                              World.cpp:795 (20)
    //         005419f7     MOV        EBP,dword ptr [ESP + param_1]
    //         005419fb     PUSH       ESI
    //         005419fc     PUSH       EDI
    //         005419fd     MOV        EDI,this
    //         005419ff     PUSH       0x2
    //         00541a01     LEA        EBX,[EDI + 0x2c]
    //         00541a04     PUSH       EBX
    //         00541a05     PUSH       EBP
    //         00541a06     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:796 (14)
    //         00541a0b     MOVSX      EAX,word ptr [EBX]
    //         00541a0e     ADD        ESP,0xc
    //         00541a11     PUSH       0x4
    //         00541a13     PUSH       EAX
    //         00541a14     CALL       calloc                                           undefined calloc()
    //                              World.cpp:797 (13)
    //         00541a19     XOR        ESI,ESI
    //         00541a1b     ADD        ESP,0x8
    //         00541a1e     CMP        word ptr [EBX],SI
    //         00541a21     MOV        dword ptr [EDI + 0x30],EAX
    //         00541a24     JLE        LAB_00541a6a
    //                               LAB_00541a26                                                 XREF[1]:     00541a68(j)  
    //                              World.cpp:798 (68)
    //         00541a26     PUSH       0x10
    //         00541a28     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541a2d     ADD        ESP,0x4
    //         00541a30     MOV        dword ptr [ESP + param_1],EAX
    //         00541a34     TEST       EAX,EAX
    //         00541a36     MOV        dword ptr [ESP + local_4],0x0
    //         00541a3e     JZ         LAB_00541a51
    //         00541a40     MOV        this,dword ptr [EDI + 0x80]
    //         00541a46     PUSH       this
    //         00541a47     PUSH       EBP
    //         00541a48     MOV        this,EAX
    //         00541a4a     CALL       RGE_Sound::RGE_Sound                             undefined RGE_Sound(RGE_Sound * this, int par
    //         00541a4f     JMP        LAB_00541a53
    //                               LAB_00541a51                                                 XREF[1]:     00541a3e(j)  
    //         00541a51     XOR        EAX,EAX
    //                               LAB_00541a53                                                 XREF[1]:     00541a4f(j)  
    //         00541a53     MOV        EDX,dword ptr [EDI + 0x30]
    //         00541a56     INC        ESI
    //         00541a57     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00541a5f     MOV        dword ptr [EDX + ESI*0x4 + -0x4],EAX
    //         00541a63     MOVSX      EAX,word ptr [EBX]
    //         00541a66     CMP        ESI,EAX
    //         00541a68     JL         LAB_00541a26
    //                               LAB_00541a6a                                                 XREF[1]:     00541a24(j)  
    //                              World.cpp:799 (21)
    //         00541a6a     MOV        this,dword ptr [ESP + local_c]
    //         00541a6e     POP        EDI
    //         00541a6f     POP        ESI
    //         00541a70     POP        EBP
    //         00541a71     MOV        dword ptr FS:[0x0],this
    //         00541a78     POP        EBX
    //         00541a79     ADD        ESP,0xc
    //         00541a7c     RET        0x8
    //         00541a7f     ??         90h
    return;
}

void RGE_Game_World::init_sprites(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall init_sprites(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00541a97(R), 00541aea(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00541af0(W), 00541b11(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541b43(R)  
    //                               ?init_sprites@RGE_Game_World@@MAEXH@Z                        XREF[2]:     0057749c(*), 00577954(*)  
    //                               RGE_Game_World::init_sprites
    //                              World.cpp:804 (23)
    //         00541a80     MOV        EAX,FS:[0x0]
    //         00541a86     PUSH       -0x1
    //         00541a88     PUSH       FUN_00561d4b
    //         00541a8d     PUSH       EAX
    //         00541a8e     MOV        dword ptr FS:[0x0],ESP
    //         00541a95     PUSH       EBX
    //         00541a96     PUSH       EBP
    //                              World.cpp:807 (20)
    //         00541a97     MOV        EBP,dword ptr [ESP + param_1]
    //         00541a9b     PUSH       ESI
    //         00541a9c     MOV        ESI,this
    //         00541a9e     PUSH       EDI
    //         00541a9f     PUSH       0x2
    //         00541aa1     LEA        EBX,[ESI + 0x34]
    //         00541aa4     PUSH       EBX
    //         00541aa5     PUSH       EBP
    //         00541aa6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:808 (14)
    //         00541aab     MOVSX      EAX,word ptr [EBX]
    //         00541aae     ADD        ESP,0xc
    //         00541ab1     PUSH       0x4
    //         00541ab3     PUSH       EAX
    //         00541ab4     CALL       calloc                                           undefined calloc()
    //                              World.cpp:809 (20)
    //         00541ab9     MOVSX      this,word ptr [EBX]
    //         00541abc     ADD        ESP,0x8
    //         00541abf     MOV        dword ptr [ESI + 0x38],EAX
    //         00541ac2     SHL        this,0x2
    //         00541ac5     PUSH       this
    //         00541ac6     PUSH       EAX
    //         00541ac7     PUSH       EBP
    //         00541ac8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:810 (10)
    //         00541acd     XOR        EDI,EDI
    //         00541acf     ADD        ESP,0xc
    //         00541ad2     CMP        word ptr [EBX],DI
    //         00541ad5     JLE        LAB_00541b24
    //                               LAB_00541ad7                                                 XREF[1]:     00541b22(j)  
    //                              World.cpp:811 (9)
    //         00541ad7     MOV        EDX,dword ptr [ESI + 0x38]
    //         00541ada     CMP        dword ptr [EDX + EDI*0x4],0x0
    //         00541ade     JZ         LAB_00541b1c
    //                              language.dll match for 0x78: "10"
    //                              World.cpp:812 (68)
    //         00541ae0     PUSH       0x78
    //         00541ae2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541ae7     ADD        ESP,0x4
    //         00541aea     MOV        dword ptr [ESP + param_1],EAX
    //         00541aee     TEST       EAX,EAX
    //         00541af0     MOV        dword ptr [ESP + local_4],0x0
    //         00541af8     JZ         LAB_00541b0c
    //         00541afa     MOV        this,dword ptr [ESI + 0x64]
    //         00541afd     MOV        EDX,dword ptr [ESI + 0x30]
    //         00541b00     PUSH       this
    //         00541b01     PUSH       EDX
    //         00541b02     PUSH       EBP
    //         00541b03     MOV        this,EAX
    //         00541b05     CALL       RGE_Sprite::RGE_Sprite                           undefined RGE_Sprite(RGE_Sprite * this, int p
    //         00541b0a     JMP        LAB_00541b0e
    //                               LAB_00541b0c                                                 XREF[1]:     00541af8(j)  
    //         00541b0c     XOR        EAX,EAX
    //                               LAB_00541b0e                                                 XREF[1]:     00541b0a(j)  
    //         00541b0e     MOV        this,dword ptr [ESI + 0x38]
    //         00541b11     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00541b19     MOV        dword ptr [this->_padding_ + EDI*0x4],EAX
    //                               LAB_00541b1c                                                 XREF[1]:     00541ade(j)  
    //         00541b1c     MOVSX      EDX,word ptr [EBX]
    //         00541b1f     INC        EDI
    //         00541b20     CMP        EDI,EDX
    //         00541b22     JL         LAB_00541ad7
    //                               LAB_00541b24                                                 XREF[1]:     00541ad5(j)  
    //                              World.cpp:813 (7)
    //         00541b24     XOR        EDI,EDI
    //         00541b26     CMP        word ptr [EBX],DI
    //         00541b29     JLE        LAB_00541b43
    //                               LAB_00541b2b                                                 XREF[1]:     00541b41(j)  
    //                              World.cpp:814 (10)
    //         00541b2b     MOV        EAX,dword ptr [ESI + 0x38]
    //         00541b2e     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00541b31     TEST       this,this
    //         00541b33     JZ         LAB_00541b3b
    //                              World.cpp:815 (14)
    //         00541b35     PUSH       EAX
    //         00541b36     CALL       RGE_Sprite::rehook                               void rehook(RGE_Sprite * this, RGE_Sprite * *
    //                               LAB_00541b3b                                                 XREF[1]:     00541b33(j)  
    //         00541b3b     MOVSX      EAX,word ptr [EBX]
    //         00541b3e     INC        EDI
    //         00541b3f     CMP        EDI,EAX
    //         00541b41     JL         LAB_00541b2b
    //                               LAB_00541b43                                                 XREF[1]:     00541b29(j)  
    //                              World.cpp:816 (21)
    //         00541b43     MOV        this,dword ptr [ESP + local_c]
    //         00541b47     POP        EDI
    //         00541b48     POP        ESI
    //         00541b49     POP        EBP
    //         00541b4a     MOV        dword ptr FS:[0x0],this
    //         00541b51     POP        EBX
    //         00541b52     ADD        ESP,0xc
    //         00541b55     RET        0x4
    //         00541b58     ??         90h
    //         00541b59     NOP
    //         00541b5a     NOP
    //         00541b5b     NOP
    //         00541b5c     NOP
    //         00541b5d     NOP
    //         00541b5e     NOP
    //         00541b5f     NOP
    return;
}

void RGE_Game_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              void __thiscall scenario_init(RGE_Game_World * this, int param_1, RG
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541b9a(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00541b96(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541b8c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541bab(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541b86(W)  
    //                               ?scenario_init@RGE_Game_World@@UAEXHPAV1@@Z                  XREF[1]:     00577a04(*)  
    //                               RGE_Game_World::scenario_init
    //                              World.cpp:820 (25)
    //         00541b60     PUSH       -0x1
    //         00541b62     PUSH       FUN_00561d6b
    //         00541b67     MOV        EAX,FS:[0x0]
    //         00541b6d     PUSH       EAX
    //         00541b6e     MOV        dword ptr FS:[0x0],ESP
    //         00541b75     PUSH       this
    //         00541b76     PUSH       ESI
    //         00541b77     MOV        ESI,this
    //                              World.cpp:821 (50)
    //         00541b79     PUSH       0x1990
    //         00541b7e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541b83     ADD        ESP,0x4
    //         00541b86     MOV        dword ptr [ESP + local_10],EAX
    //         00541b8a     TEST       EAX,EAX
    //         00541b8c     MOV        dword ptr [ESP + local_4],0x0
    //         00541b94     JZ         LAB_00541ba9
    //         00541b96     MOV        this,dword ptr [ESP + param_2]
    //         00541b9a     MOV        EDX,dword ptr [ESP + param_1]
    //         00541b9e     PUSH       this
    //         00541b9f     PUSH       EDX
    //         00541ba0     MOV        this,EAX
    //         00541ba2     CALL       RGE_Scenario::RGE_Scenario                       undefined RGE_Scenario(RGE_Scenario * this, i
    //         00541ba7     JMP        LAB_00541bab
    //                               LAB_00541ba9                                                 XREF[1]:     00541b94(j)  
    //         00541ba9     XOR        EAX,EAX
    //                               LAB_00541bab                                                 XREF[1]:     00541ba7(j)  
    //                              World.cpp:822 (21)
    //         00541bab     MOV        this,dword ptr [ESP + local_c]
    //         00541baf     MOV        dword ptr [ESI + 0x5c],EAX
    //         00541bb2     MOV        dword ptr FS:[0x0],this
    //         00541bb9     POP        ESI
    //         00541bba     ADD        ESP,0x10
    //         00541bbd     RET        0x8
    return;
}

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    /* TODO: Stub */
    //                              void __thiscall scenario_init(RGE_Game_World * this, RGE_Game_World 
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     00541bf6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541bec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541c06(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541be6(W)  
    //                               ?scenario_init@RGE_Game_World@@UAEXPAV1@@Z                   XREF[1]:     00577a00(*)  
    //                               RGE_Game_World::scenario_init
    //                              World.cpp:825 (25)
    //         00541bc0     PUSH       -0x1
    //         00541bc2     PUSH       FUN_00561d8b
    //         00541bc7     MOV        EAX,FS:[0x0]
    //         00541bcd     PUSH       EAX
    //         00541bce     MOV        dword ptr FS:[0x0],ESP
    //         00541bd5     PUSH       this
    //         00541bd6     PUSH       ESI
    //         00541bd7     MOV        ESI,this
    //                              World.cpp:826 (45)
    //         00541bd9     PUSH       0x1990
    //         00541bde     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541be3     ADD        ESP,0x4
    //         00541be6     MOV        dword ptr [ESP + local_10],EAX
    //         00541bea     TEST       EAX,EAX
    //         00541bec     MOV        dword ptr [ESP + local_4],0x0
    //         00541bf4     JZ         LAB_00541c04
    //         00541bf6     MOV        this,dword ptr [ESP + param_1]
    //         00541bfa     PUSH       this
    //         00541bfb     MOV        this,EAX
    //         00541bfd     CALL       RGE_Scenario::RGE_Scenario                       undefined RGE_Scenario(RGE_Scenario * this, R
    //         00541c02     JMP        LAB_00541c06
    //                               LAB_00541c04                                                 XREF[1]:     00541bf4(j)  
    //         00541c04     XOR        EAX,EAX
    //                               LAB_00541c06                                                 XREF[1]:     00541c02(j)  
    //                              World.cpp:827 (21)
    //         00541c06     MOV        this,dword ptr [ESP + local_c]
    //         00541c0a     MOV        dword ptr [ESI + 0x5c],EAX
    //         00541c0d     MOV        dword ptr FS:[0x0],this
    //         00541c14     POP        ESI
    //         00541c15     ADD        ESP,0x10
    //         00541c18     RET        0x4
    //         00541c1b     ??         90h
    //         00541c1c     NOP
    //         00541c1d     NOP
    //         00541c1e     NOP
    //         00541c1f     NOP
    return;
}

void RGE_Game_World::map_init(int param_1, TSound_Driver* param_2) {
    /* TODO: Stub */
    //                              void __thiscall map_init(RGE_Game_World * this, int param_1, TSound_
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541c59(R)  
    //              TSound_Driver *   Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541c4c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541c6c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541c46(W)  
    //                               ?map_init@RGE_Game_World@@MAEXHPAVTSound_Driver@@@Z          XREF[1]:     00577958(*)  
    //                               RGE_Game_World::map_init
    //                              World.cpp:831 (25)
    //         00541c20     PUSH       -0x1
    //         00541c22     PUSH       FUN_00561dab
    //         00541c27     MOV        EAX,FS:[0x0]
    //         00541c2d     PUSH       EAX
    //         00541c2e     MOV        dword ptr FS:[0x0],ESP
    //         00541c35     PUSH       this
    //         00541c36     PUSH       ESI
    //         00541c37     MOV        ESI,this
    //                              World.cpp:832 (51)
    //         00541c39     PUSH       0x8dd0
    //         00541c3e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541c43     ADD        ESP,0x4
    //         00541c46     MOV        dword ptr [ESP + local_10],EAX
    //         00541c4a     TEST       EAX,EAX
    //         00541c4c     MOV        dword ptr [ESP + local_4],0x0
    //         00541c54     JZ         LAB_00541c6a
    //         00541c56     MOV        this,dword ptr [ESI + 0x30]
    //         00541c59     MOV        EDX,dword ptr [ESP + param_1]
    //         00541c5d     PUSH       0x1
    //         00541c5f     PUSH       this
    //         00541c60     PUSH       EDX
    //         00541c61     MOV        this,EAX
    //         00541c63     CALL       RGE_Map::RGE_Map                                 undefined RGE_Map(RGE_Map * this, int param_1
    //         00541c68     JMP        LAB_00541c6c
    //                               LAB_00541c6a                                                 XREF[1]:     00541c54(j)  
    //         00541c6a     XOR        EAX,EAX
    //                               LAB_00541c6c                                                 XREF[1]:     00541c68(j)  
    //                              World.cpp:833 (21)
    //         00541c6c     MOV        this,dword ptr [ESP + local_c]
    //         00541c70     MOV        dword ptr [ESI + 0x28],EAX
    //         00541c73     MOV        dword ptr FS:[0x0],this
    //         00541c7a     POP        ESI
    //         00541c7b     ADD        ESP,0x10
    //         00541c7e     RET        0x8
    //         00541c81     ??         90h
    //         00541c82     NOP
    //         00541c83     NOP
    //         00541c84     NOP
    //         00541c85     NOP
    //         00541c86     NOP
    //         00541c87     NOP
    //         00541c88     NOP
    //         00541c89     NOP
    //         00541c8a     NOP
    //         00541c8b     NOP
    //         00541c8c     NOP
    //         00541c8d     NOP
    //         00541c8e     NOP
    //         00541c8f     NOP
    return;
}

void RGE_Game_World::effects_init(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall effects_init(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541cc3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541cb9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541cd3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541cb3(W)  
    //                               ?effects_init@RGE_Game_World@@MAEXH@Z                        XREF[1]:     0057795c(*)  
    //                               RGE_Game_World::effects_init
    //                              World.cpp:838 (25)
    //         00541c90     PUSH       -0x1
    //         00541c92     PUSH       FUN_00561dcb
    //         00541c97     MOV        EAX,FS:[0x0]
    //         00541c9d     PUSH       EAX
    //         00541c9e     MOV        dword ptr FS:[0x0],ESP
    //         00541ca5     PUSH       this
    //         00541ca6     PUSH       ESI
    //         00541ca7     MOV        ESI,this
    //                              World.cpp:839 (42)
    //         00541ca9     PUSH       0xc
    //         00541cab     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541cb0     ADD        ESP,0x4
    //         00541cb3     MOV        dword ptr [ESP + local_10],EAX
    //         00541cb7     TEST       EAX,EAX
    //         00541cb9     MOV        dword ptr [ESP + local_4],0x0
    //         00541cc1     JZ         LAB_00541cd1
    //         00541cc3     MOV        this,dword ptr [ESP + param_1]
    //         00541cc7     PUSH       this
    //         00541cc8     MOV        this,EAX
    //         00541cca     CALL       RGE_Effects::RGE_Effects                         undefined RGE_Effects(RGE_Effects * this, int
    //         00541ccf     JMP        LAB_00541cd3
    //                               LAB_00541cd1                                                 XREF[1]:     00541cc1(j)  
    //         00541cd1     XOR        EAX,EAX
    //                               LAB_00541cd3                                                 XREF[1]:     00541ccf(j)  
    //                              World.cpp:840 (21)
    //         00541cd3     MOV        this,dword ptr [ESP + local_c]
    //         00541cd7     MOV        dword ptr [ESI + 0x4c],EAX
    //         00541cda     MOV        dword ptr FS:[0x0],this
    //         00541ce1     POP        ESI
    //         00541ce2     ADD        ESP,0x10
    //         00541ce5     RET        0x4
    //         00541ce8     ??         90h
    //         00541ce9     NOP
    //         00541cea     NOP
    //         00541ceb     NOP
    //         00541cec     NOP
    //         00541ced     NOP
    //         00541cee     NOP
    //         00541cef     NOP
    return;
}

void RGE_Game_World::master_player_init(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall master_player_init(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541cf0(R)  
    //                               ?master_player_init@RGE_Game_World@@MAEXH@Z                  XREF[2]:     005774a8(*), 00577960(*)  
    //                               RGE_Game_World::master_player_init
    //                              World.cpp:844 (10)
    //         00541cf0     MOV        EDX,dword ptr [ESP + param_1]
    //         00541cf4     MOV        EAX,dword ptr [this->_padding_]
    //         00541cf6     PUSH       EDX
    //         00541cf7     CALL       dword ptr [EAX + 0x30]
    //                              World.cpp:847 (3)
    //         00541cfa     RET        0x4
    //         00541cfd     ??         90h
    //         00541cfe     NOP
    //         00541cff     NOP
    return;
}

void RGE_Game_World::command_init(int param_1, TCommunications_Handler* param_2) {
    /* TODO: Stub */
    //                              void __thiscall command_init(RGE_Game_World * this, int param_1, TCo
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              TCommunication    Stack[0x8]:4   param_2                   XREF[1]:     00541d33(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00541d29(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00541d44(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00541d23(W)  
    //                               ?command_init@RGE_Game_World@@MAEXHPAVTCommunications_Handl  XREF[1]:     00577964(*)  
    //                               RGE_Game_World::command_init
    //                              World.cpp:852 (25)
    //         00541d00     PUSH       -0x1
    //         00541d02     PUSH       FUN_00561deb
    //         00541d07     MOV        EAX,FS:[0x0]
    //         00541d0d     PUSH       EAX
    //         00541d0e     MOV        dword ptr FS:[0x0],ESP
    //         00541d15     PUSH       this
    //         00541d16     PUSH       ESI
    //         00541d17     MOV        ESI,this
    //                              World.cpp:853 (43)
    //         00541d19     PUSH       0x18
    //         00541d1b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00541d20     ADD        ESP,0x4
    //         00541d23     MOV        dword ptr [ESP + local_10],EAX
    //         00541d27     TEST       EAX,EAX
    //         00541d29     MOV        dword ptr [ESP + local_4],0x0
    //         00541d31     JZ         LAB_00541d42
    //         00541d33     MOV        this,dword ptr [ESP + param_2]
    //         00541d37     PUSH       this
    //         00541d38     PUSH       ESI
    //         00541d39     MOV        this,EAX
    //         00541d3b     CALL       RGE_Command::RGE_Command                         undefined RGE_Command(RGE_Command * this, RGE
    //         00541d40     JMP        LAB_00541d44
    //                               LAB_00541d42                                                 XREF[1]:     00541d31(j)  
    //         00541d42     XOR        EAX,EAX
    //                               LAB_00541d44                                                 XREF[1]:     00541d40(j)  
    //                              World.cpp:854 (21)
    //         00541d44     MOV        this,dword ptr [ESP + local_c]
    //         00541d48     MOV        dword ptr [ESI + 0x58],EAX
    //         00541d4b     MOV        dword ptr FS:[0x0],this
    //         00541d52     POP        ESI
    //         00541d53     ADD        ESP,0x10
    //         00541d56     RET        0x8
    //         00541d59     ??         90h
    //         00541d5a     NOP
    //         00541d5b     NOP
    //         00541d5c     NOP
    //         00541d5d     NOP
    //         00541d5e     NOP
    //         00541d5f     NOP
    //                              * protected: virtual void __thiscall RGE_Game_World::world_init(int,class TSound_Driver *,class TCom... *
    //                              void __thiscall world_init(RGE_Game_World * this, int param_1, TSoun
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00541d61(R)  
    //              TSound_Driver *   Stack[0x8]:4   param_2
    //              TCommunication    Stack[0xc]:4   param_3
    //                               ?world_init@RGE_Game_World@@MAEXHPAVTSound_Driver@@PAVTComm  XREF[2]:     world_init:0052e6db(c), 
    //                               RGE_Game_World::world_init                                                00577968(*)  
    //                              World.cpp:858 (1)
    //         00541d60     PUSH       EBX
    //                              World.cpp:859 (15)
    //         00541d61     MOV        EBX,dword ptr [ESP + param_1]
    //         00541d65     PUSH       EBP
    //         00541d66     PUSH       ESI
    //         00541d67     MOV        ESI,this
    //         00541d69     PUSH       EDI
    //         00541d6a     PUSH       EBX
    //         00541d6b     MOV        EDI,dword ptr [ESI]
    //         00541d6d     CALL       dword ptr [EDI + 0x3c]
    //                              World.cpp:860 (6)
    //         00541d70     PUSH       EBX
    //         00541d71     MOV        this,ESI
    //         00541d73     CALL       dword ptr [EDI + 0x38]
    //                              World.cpp:861 (11)
    //         00541d76     MOV        EBP,dword ptr [ESP + 0x18]
    //         00541d7a     MOV        this,ESI
    //         00541d7c     PUSH       EBP
    //         00541d7d     PUSH       EBX=>DAT_fffffff8
    //         00541d7e     CALL       dword ptr [EDI + 0x40]
    //                              World.cpp:862 (6)
    //         00541d81     PUSH       EBX
    //         00541d82     MOV        this,ESI
    //         00541d84     CALL       dword ptr [EDI + 0x44]
    //                              World.cpp:863 (7)
    //         00541d87     PUSH       EBP
    //         00541d88     PUSH       EBX=>DAT_fffffff8
    //         00541d89     MOV        this,ESI
    //         00541d8b     CALL       dword ptr [EDI + 0x48]
    //                              World.cpp:864 (6)
    //         00541d8e     PUSH       EBX
    //         00541d8f     MOV        this,ESI
    //         00541d91     CALL       dword ptr [EDI + 0x4c]
    //                              World.cpp:865 (6)
    //         00541d94     PUSH       EBX
    //         00541d95     MOV        this,ESI
    //         00541d97     CALL       dword ptr [EDI + 0x50]
    //                              World.cpp:866 (11)
    //         00541d9a     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00541d9e     MOV        this,ESI
    //         00541da0     PUSH       EAX
    //         00541da1     PUSH       EBX=>DAT_fffffff8
    //         00541da2     CALL       dword ptr [EDI + 0x54]
    //                              World.cpp:867 (7)
    //         00541da5     POP        EDI
    //         00541da6     POP        ESI
    //         00541da7     POP        EBP
    //         00541da8     POP        EBX
    //         00541da9     RET        0xc
    //         00541dac     ??         90h
    //         00541dad     NOP
    //         00541dae     NOP
    //         00541daf     NOP
    //                              * public: virtual unsigned char __thiscall RGE_Game_World::init(char *,class TSound_Driver *,class T... *
    //                              uchar __thiscall init(RGE_Game_World * this, char * param_1, TSound_
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00541db0(R)  
    //              TSound_Driver *   Stack[0x8]:4   param_2                   XREF[1]:     00541db8(R)  
    //              TCommunication    Stack[0xc]:4   param_3                   XREF[1]:     00541e3e(R)  
    //              char[8]           Stack[-0xc]:8  version                   XREF[0,4]:   00541de3(*), 00541df8(*), 00541dfc(*), 00541e08(R)  
    //                               ?init@RGE_Game_World@@UAEEPADPAVTSound_Driver@@PAVTCommunic  XREF[2]:     init:0052e75f(c), 005779c0(*)  
    //                               RGE_Game_World::init
    //                              World.cpp:871 (51)
    //         00541db0     MOV        EAX,dword ptr [ESP + param_1]
    //         00541db4     SUB        ESP,0x8
    //         00541db7     PUSH       EBX
    //         00541db8     MOV        EBX,dword ptr [ESP + param_2]
    //         00541dbc     PUSH       EBP
    //         00541dbd     PUSH       ESI
    //         00541dbe     PUSH       EDI
    //         00541dbf     MOV        EBP,this
    //         00541dc1     PUSH       0x8000
    //         00541dc6     PUSH       EAX
    //         00541dc7     MOV        dword ptr [EBP + 0x80],EBX
    //         00541dcd     MOV        dword ptr [EBP + 0x68],0x0
    //         00541dd4     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
    //         00541dd9     MOV        EDI,EAX
    //         00541ddb     ADD        ESP,0x8
    //         00541dde     CMP        EDI,-0x1
    //         00541de1     JZ         LAB_00541e62
    //                              World.cpp:882 (16)
    //         00541de3     LEA        this=>version[4],[ESP + 0x10]
    //         00541de7     PUSH       0x8
    //         00541de9     PUSH       this
    //         00541dea     PUSH       EDI
    //         00541deb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00541df0     ADD        ESP,0xc
    //                              World.cpp:883 (54)
    //         00541df3     MOV        ESI,s_VER_3.7                                    = 56h
    //         00541df8     LEA        EAX=>version[4],[ESP + 0x10]
    //                               LAB_00541dfc                                                 XREF[1]:     00541e1a(j)  
    //         00541dfc     MOV        DL,byte ptr [EAX]=>version[4]
    //         00541dfe     MOV        this,DL
    //         00541e00     CMP        DL,byte ptr [ESI]=>s_VER_3.7                     = 56h
    //                                                                                  = 52h
    //         00541e02     JNZ        LAB_00541e20
    //         00541e04     TEST       this,this
    //         00541e06     JZ         LAB_00541e1c
    //         00541e08     MOV        DL,byte ptr [EAX + version[5]]
    //         00541e0b     MOV        this,DL
    //         00541e0d     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0058ec21            = 45h
    //                                                                                  = 20h
    //         00541e10     JNZ        LAB_00541e20
    //         00541e12     ADD        EAX,0x2
    //         00541e15     ADD        ESI,0x2
    //         00541e18     TEST       this,this
    //         00541e1a     JNZ        LAB_00541dfc
    //                               LAB_00541e1c                                                 XREF[1]:     00541e06(j)  
    //         00541e1c     XOR        EAX,EAX
    //         00541e1e     JMP        LAB_00541e25
    //                               LAB_00541e20                                                 XREF[2]:     00541e02(j), 00541e10(j)  
    //         00541e20     SBB        EAX,EAX
    //         00541e22     SBB        EAX,-0x1
    //                               LAB_00541e25                                                 XREF[1]:     00541e1e(j)  
    //         00541e25     TEST       EAX,EAX
    //         00541e27     JZ         LAB_00541e3e
    //                              World.cpp:885 (9)
    //         00541e29     PUSH       EDI
    //         00541e2a     CALL       rge_close                                        int rge_close(int param_1)
    //         00541e2f     ADD        ESP,0x4
    //                              World.cpp:893 (2)
    //         00541e32     XOR        AL,AL
    //                              World.cpp:896 (10)
    //         00541e34     POP        EDI
    //         00541e35     POP        ESI
    //         00541e36     POP        EBP
    //         00541e37     POP        EBX
    //         00541e38     ADD        ESP,0x8
    //         00541e3b     RET        0xc
    //                               LAB_00541e3e                                                 XREF[1]:     00541e27(j)  
    //                              World.cpp:889 (15)
    //         00541e3e     MOV        this,dword ptr [ESP + param_3]
    //         00541e42     MOV        EAX,dword ptr [EBP]
    //         00541e45     PUSH       this
    //         00541e46     PUSH       EBX
    //         00541e47     PUSH       EDI
    //         00541e48     MOV        this,EBP
    //         00541e4a     CALL       dword ptr [EAX + 0x58]
    //                              World.cpp:890 (9)
    //         00541e4d     PUSH       EDI
    //         00541e4e     CALL       rge_close                                        int rge_close(int param_1)
    //         00541e53     ADD        ESP,0x4
    //                              World.cpp:895 (2)
    //         00541e56     MOV        AL,0x1
    //                              World.cpp:896 (22)
    //         00541e58     POP        EDI
    //         00541e59     POP        ESI
    //         00541e5a     POP        EBP
    //         00541e5b     POP        EBX
    //         00541e5c     ADD        ESP,0x8
    //         00541e5f     RET        0xc
    //                               LAB_00541e62                                                 XREF[1]:     00541de1(j)  
    //         00541e62     POP        EDI
    //         00541e63     POP        ESI
    //         00541e64     POP        EBP
    //         00541e65     XOR        AL,AL
    //         00541e67     POP        EBX
    //         00541e68     ADD        ESP,0x8
    //         00541e6b     RET        0xc
    //         00541e6e     ??         90h
    //         00541e6f     NOP
    return;
}

void RGE_Game_World::turn_sound_off() {
    /* TODO: Stub */
    //                              void __thiscall turn_sound_off(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?turn_sound_off@RGE_Game_World@@UAEXXZ                       XREF[2]:     0057750c(*), 005779c4(*)  
    //                               RGE_Game_World::turn_sound_off
    //                              World.cpp:900 (4)
    //         00541e70     PUSH       ESI
    //         00541e71     PUSH       EDI
    //         00541e72     MOV        EDI,this
    //                              World.cpp:903 (8)
    //         00541e74     XOR        ESI,ESI
    //         00541e76     CMP        word ptr [EDI + 0x2c],SI
    //         00541e7a     JLE        LAB_00541e90
    //                               LAB_00541e7c                                                 XREF[1]:     00541e8e(j)  
    //                              World.cpp:904 (20)
    //         00541e7c     MOV        EAX,dword ptr [EDI + 0x30]
    //         00541e7f     MOV        this,dword ptr [EAX + ESI*0x4]
    //         00541e82     CALL       RGE_Sound::stop                                  void stop(RGE_Sound * this)
    //         00541e87     MOVSX      this,word ptr [EDI + 0x2c]
    //         00541e8b     INC        ESI
    //         00541e8c     CMP        ESI,this
    //         00541e8e     JL         LAB_00541e7c
    //                               LAB_00541e90                                                 XREF[1]:     00541e7a(j)  
    //                              World.cpp:905 (3)
    //         00541e90     POP        EDI
    //         00541e91     POP        ESI
    //         00541e92     RET
    //         00541e93     ??         90h
    //         00541e94     NOP
    //         00541e95     NOP
    //         00541e96     NOP
    //         00541e97     NOP
    //         00541e98     NOP
    //         00541e99     NOP
    //         00541e9a     NOP
    //         00541e9b     NOP
    //         00541e9c     NOP
    //         00541e9d     NOP
    //         00541e9e     NOP
    //         00541e9f     NOP
    return;
}

void RGE_Game_World::reset_communications(TCommunications_Handler* param_1) {
    /* TODO: Stub */
    //                              void __thiscall reset_communications(RGE_Game_World * this, TCommuni
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              TCommunication    Stack[0x4]:4   param_1                   XREF[1]:     00541ea0(R)  
    //                               ?reset_communications@RGE_Game_World@@QAEXPAVTCommunication  XREF[1]:     setup_comm:0041efa0(c)  
    //                               RGE_Game_World::reset_communications
    //                              World.cpp:909 (13)
    //         00541ea0     MOV        EAX,dword ptr [ESP + param_1]
    //         00541ea4     MOV        this,dword ptr [ECX + this->commands]
    //         00541ea7     PUSH       EAX
    //         00541ea8     CALL       RGE_Command::reset_communications                void reset_communications(RGE_Command * this,
    //                              World.cpp:911 (3)
    //         00541ead     RET        0x4
    return;
}

void RGE_Game_World::reset_player_visible_maps() {
    /* TODO: Stub */
    //                              void __thiscall reset_player_visible_maps(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?reset_player_visible_maps@RGE_Game_World@@QAEXXZ            XREF[1]:     clear_map:004558f8(c)  
    //                               RGE_Game_World::reset_player_visible_maps
    //                              World.cpp:916 (4)
    //         00541eb0     PUSH       ESI
    //         00541eb1     PUSH       EDI
    //         00541eb2     MOV        EDI,this
    //                              World.cpp:919 (8)
    //         00541eb4     XOR        ESI,ESI
    //         00541eb6     CMP        word ptr [EDI + 0x3c],SI
    //         00541eba     JLE        LAB_00541ed4
    //                               LAB_00541ebc                                                 XREF[1]:     00541ed2(j)  
    //                              World.cpp:920 (10)
    //         00541ebc     MOV        EAX,dword ptr [EDI + 0x40]
    //         00541ebf     MOV        this,dword ptr [EAX + ESI*0x4]
    //         00541ec2     TEST       this,this
    //         00541ec4     JZ         LAB_00541ecb
    //                              World.cpp:921 (5)
    //         00541ec6     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //                               LAB_00541ecb                                                 XREF[1]:     00541ec4(j)  
    //                              World.cpp:919 (9)
    //         00541ecb     MOVSX      this,word ptr [EDI + 0x3c]
    //         00541ecf     INC        ESI
    //         00541ed0     CMP        ESI,this
    //         00541ed2     JL         LAB_00541ebc
    //                               LAB_00541ed4                                                 XREF[1]:     00541eba(j)  
    //                              World.cpp:922 (3)
    //         00541ed4     POP        EDI
    //         00541ed5     POP        ESI
    //         00541ed6     RET
    //         00541ed7     ??         90h
    //         00541ed8     NOP
    //         00541ed9     NOP
    //         00541eda     NOP
    //         00541edb     NOP
    //         00541edc     NOP
    //         00541edd     NOP
    //         00541ede     NOP
    //         00541edf     NOP
    return;
}

void RGE_Game_World::del_game_info() {
    /* TODO: Stub */
    //                              void __thiscall del_game_info(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?del_game_info@RGE_Game_World@@UAEXXZ                        XREF[3]:     ~RGE_Game_World:00540a5e(c), 
    //                               RGE_Game_World::del_game_info                                             00577510(*), 005779c8(*)  
    //                              World.cpp:926 (4)
    //         00541ee0     PUSH       EBX
    //         00541ee1     PUSH       ESI
    //         00541ee2     MOV        ESI,this
    //                              World.cpp:929 (9)
    //         00541ee4     XOR        EBX,EBX
    //         00541ee6     MOV        dword ptr [world_update_counter],EBX
    //         00541eec     PUSH       EDI
    //                              World.cpp:935 (18)
    //         00541eed     MOV        this,dword ptr [ESI + 0xd8]
    //         00541ef3     MOV        byte ptr [ESI + 0x1d],0x2
    //         00541ef7     MOV        byte ptr [ESI + 0x1e],BL
    //         00541efa     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:936 (11)
    //         00541eff     MOV        this,dword ptr [ESI + 0xdc]
    //         00541f05     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:937 (11)
    //         00541f0a     MOV        this,dword ptr [ESI + 0xe0]
    //         00541f10     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:938 (11)
    //         00541f15     MOV        this,dword ptr [ESI + 0xe4]
    //         00541f1b     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:939 (11)
    //         00541f20     MOV        this,dword ptr [ESI + 0xe8]
    //         00541f26     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:940 (11)
    //         00541f2b     MOV        this,dword ptr [ESI + 0xec]
    //         00541f31     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:941 (11)
    //         00541f36     MOV        this,dword ptr [ESI + 0xf0]
    //         00541f3c     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              World.cpp:952 (45)
    //         00541f41     MOV        this,dword ptr [ESI + 0x90]
    //         00541f47     OR         EAX,0xffffffff
    //         00541f4a     MOV        dword ptr [ESI + 0x6c],EAX
    //         00541f4d     MOV        dword ptr [ESI + 0xa4],EAX
    //         00541f53     MOV        dword ptr [ESI + 0xa8],EAX
    //         00541f59     MOV        dword ptr [ESI + 0xac],EAX
    //         00541f5f     MOV        dword ptr [ESI + 0x100],EAX
    //         00541f65     XOR        EAX,EAX
    //         00541f67     CMP        this,EBX
    //         00541f69     MOV        dword ptr [ESI + 0x68],EBX
    //         00541f6c     JLE        LAB_00541f83
    //                               LAB_00541f6e                                                 XREF[1]:     00541f81(j)  
    //                              World.cpp:953 (21)
    //         00541f6e     MOV        this,dword ptr [ESI + 0x88]
    //         00541f74     INC        EAX
    //         00541f75     MOV        dword ptr [this->_padding_ + EAX*0x4 + -0x4],EBX
    //         00541f79     MOV        this,dword ptr [ESI + 0x90]
    //         00541f7f     CMP        EAX,this
    //         00541f81     JL         LAB_00541f6e
    //                               LAB_00541f83                                                 XREF[1]:     00541f6c(j)  
    //                              World.cpp:956 (12)
    //         00541f83     MOV        this,dword ptr [ESI + 0x9c]
    //         00541f89     XOR        EAX,EAX
    //         00541f8b     CMP        this,EBX
    //         00541f8d     JLE        LAB_00541fa4
    //                               LAB_00541f8f                                                 XREF[1]:     00541fa2(j)  
    //                              World.cpp:957 (21)
    //         00541f8f     MOV        EDX,dword ptr [ESI + 0x94]
    //         00541f95     INC        EAX
    //         00541f96     MOV        dword ptr [EDX + EAX*0x4 + -0x4],EBX
    //         00541f9a     MOV        this,dword ptr [ESI + 0x9c]
    //         00541fa0     CMP        EAX,this
    //         00541fa2     JL         LAB_00541f8f
    //                               LAB_00541fa4                                                 XREF[1]:     00541f8d(j)  
    //                              World.cpp:960 (10)
    //         00541fa4     MOV        EAX,dword ptr [ESI]
    //         00541fa6     MOV        this,ESI
    //         00541fa8     CALL       dword ptr [EAX + 0xb4]
    //                              World.cpp:963 (7)
    //         00541fae     MOV        this,dword ptr [ESI + 0x5c]
    //         00541fb1     CMP        this,EBX
    //         00541fb3     JZ         LAB_00541fbf
    //                              World.cpp:965 (7)
    //         00541fb5     MOV        EDX,dword ptr [this->_padding_]
    //         00541fb7     PUSH       0x1
    //         00541fb9     CALL       dword ptr [EDX + 0x4]
    //                              World.cpp:966 (3)
    //         00541fbc     MOV        dword ptr [ESI + 0x5c],EBX
    //                               LAB_00541fbf                                                 XREF[1]:     00541fb3(j)  
    //                              World.cpp:970 (14)
    //         00541fbf     MOV        AX,word ptr [ESI + 0x3c]
    //         00541fc3     CMP        AX,BX
    //         00541fc6     JLE        LAB_00541fec
    //         00541fc8     CMP        dword ptr [ESI + 0x40],EBX
    //         00541fcb     JZ         LAB_00541fec
    //                              World.cpp:972 (7)
    //         00541fcd     XOR        EDI,EDI
    //         00541fcf     CMP        AX,BX
    //         00541fd2     JLE        LAB_00541fec
    //                               LAB_00541fd4                                                 XREF[1]:     00541fea(j)  
    //                              World.cpp:973 (10)
    //         00541fd4     MOV        EAX,dword ptr [ESI + 0x40]
    //         00541fd7     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00541fda     CMP        this,EBX
    //         00541fdc     JZ         LAB_00541fe3
    //                              World.cpp:974 (5)
    //         00541fde     CALL       RGE_Player::destroy_objects                      void destroy_objects(RGE_Player * this)
    //                               LAB_00541fe3                                                 XREF[1]:     00541fdc(j)  
    //                              World.cpp:972 (9)
    //         00541fe3     MOVSX      this,word ptr [ESI + 0x3c]
    //         00541fe7     INC        EDI
    //         00541fe8     CMP        EDI,this
    //         00541fea     JL         LAB_00541fd4
    //                               LAB_00541fec                                                 XREF[3]:     00541fc6(j), 00541fcb(j), 
    //                                                                                                         00541fd2(j)  
    //                              World.cpp:978 (14)
    //         00541fec     MOV        AX,word ptr [ESI + 0x3c]
    //         00541ff0     CMP        AX,BX
    //         00541ff3     JLE        LAB_00542033
    //         00541ff5     CMP        dword ptr [ESI + 0x40],EBX
    //         00541ff8     JZ         LAB_00542033
    //                              World.cpp:980 (7)
    //         00541ffa     XOR        EDI,EDI
    //         00541ffc     CMP        AX,BX
    //         00541fff     JLE        LAB_00542020
    //                               LAB_00542001                                                 XREF[1]:     0054201e(j)  
    //                              World.cpp:981 (10)
    //         00542001     MOV        EDX,dword ptr [ESI + 0x40]
    //         00542004     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00542007     CMP        this,EBX
    //         00542009     JZ         LAB_00542017
    //                              World.cpp:983 (6)
    //         0054200b     MOV        EAX,dword ptr [this->_padding_]
    //         0054200d     PUSH       0x1
    //         0054200f     CALL       dword ptr [EAX]
    //                              World.cpp:984 (15)
    //         00542011     MOV        this,dword ptr [ESI + 0x40]
    //         00542014     MOV        dword ptr [this->_padding_ + EDI*0x4],EBX
    //                               LAB_00542017                                                 XREF[1]:     00542009(j)  
    //         00542017     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         0054201b     INC        EDI
    //         0054201c     CMP        EDI,EDX
    //         0054201e     JL         LAB_00542001
    //                               LAB_00542020                                                 XREF[1]:     00541fff(j)  
    //                              World.cpp:987 (16)
    //         00542020     MOV        EAX,dword ptr [ESI + 0x40]
    //         00542023     MOV        word ptr [ESI + 0x3c],BX
    //         00542027     PUSH       EAX
    //         00542028     CALL       free                                             undefined free()
    //         0054202d     ADD        ESP,0x4
    //                              World.cpp:988 (3)
    //         00542030     MOV        dword ptr [ESI + 0x40],EBX
    //                               LAB_00542033                                                 XREF[2]:     00541ff3(j), 00541ff8(j)  
    //                              World.cpp:991 (6)
    //         00542033     LEA        EDI,[ESI + 0xb4]
    //                              World.cpp:997 (24)
    //         00542039     MOV        this,0x9
    //         0054203e     XOR        EAX,EAX
    //         00542040     MOV        dword ptr [ESI + 0x68],EBX
    //         00542043     MOV        dword ptr [ESI + 0x20],EBX
    //         00542046     MOV        dword ptr [ESI + 0x24],EBX
    //         00542049     MOV        dword ptr [ESI + 0xb0],EBX
    //         0054204f     STOSD.REP  ES:EDI
    //                              World.cpp:1001 (4)
    //         00542051     POP        EDI
    //         00542052     POP        ESI
    //         00542053     POP        EBX
    //         00542054     RET
    //         00542055     ??         90h
    //         00542056     NOP
    //         00542057     NOP
    //         00542058     NOP
    //         00542059     NOP
    //         0054205a     NOP
    //         0054205b     NOP
    //         0054205c     NOP
    //         0054205d     NOP
    //         0054205e     NOP
    //         0054205f     NOP
    return;
}

void RGE_Game_World::load_player(int param_1, uchar param_2, short param_3) {
    /* TODO: Stub */
    //                              void __thiscall load_player(RGE_Game_World * this, int param_1, ucha
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00542093(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[2]:     0054206e(R), 0054208f(W)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00542097(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054209d(W), 005420bf(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005420d7(R)  
    //                               ?load_player@RGE_Game_World@@MAEXHEF@Z                       XREF[2]:     load_player:0052e86b(c), 
    //                               RGE_Game_World::load_player                                               00577944(*)  
    //                              World.cpp:1005 (14)
    //         00542060     MOV        EAX,FS:[0x0]
    //         00542066     PUSH       -0x1
    //         00542068     PUSH       FUN_00561e0b
    //         0054206d     PUSH       EAX
    //                              World.cpp:1007 (20)
    //         0054206e     MOV        AL,byte ptr [ESP + param_2]
    //         00542072     MOV        dword ptr FS:[0x0],ESP
    //         00542079     PUSH       ESI
    //         0054207a     MOV        ESI,this
    //         0054207c     TEST       AL,AL
    //         0054207e     JNZ        LAB_005420d7
    //         00542080     PUSH       EDI
    //         00542081     PUSH       EBX
    //                              World.cpp:1010 (54)
    //         00542082     PUSH       0x220
    //         00542087     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054208c     ADD        ESP,0x4
    //         0054208f     MOV        dword ptr [ESP + param_2],EAX
    //         00542093     MOV        EDI,dword ptr [ESP + param_1]
    //         00542097     MOV        EBX,dword ptr [ESP + param_3]
    //         0054209b     TEST       EAX,EAX
    //         0054209d     MOV        dword ptr [ESP + local_4],0x0
    //         005420a5     JZ         LAB_005420b3
    //         005420a7     PUSH       EBX
    //         005420a8     PUSH       ESI
    //         005420a9     PUSH       EDI
    //         005420aa     MOV        this,EAX
    //         005420ac     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, int p
    //         005420b1     JMP        LAB_005420b5
    //                               LAB_005420b3                                                 XREF[1]:     005420a5(j)  
    //         005420b3     XOR        EAX,EAX
    //                               LAB_005420b5                                                 XREF[1]:     005420b1(j)  
    //         005420b5     MOV        EDX,dword ptr [ESI + 0x40]
    //                              World.cpp:1011 (31)
    //         005420b8     PUSH       EDI
    //         005420b9     MOVSX      this,BX
    //         005420bc     SHL        this,0x2
    //         005420bf     MOV        dword ptr [ESP + local_4],0xffffffff
    //         005420c7     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
    //         005420ca     MOV        EAX,dword ptr [ESI + 0x40]
    //         005420cd     MOV        this,dword ptr [EAX + this->_padding_*0x1]
    //         005420d0     MOV        EDX,dword ptr [this->_padding_]
    //         005420d2     CALL       dword ptr [EDX + 0x74]
    //         005420d5     POP        EBX
    //         005420d6     POP        EDI
    //                               LAB_005420d7                                                 XREF[1]:     0054207e(j)  
    //                              World.cpp:1017 (18)
    //         005420d7     MOV        this,dword ptr [ESP + local_c]
    //         005420db     POP        ESI
    //         005420dc     MOV        dword ptr FS:[0x0],this
    //         005420e3     ADD        ESP,0xc
    //         005420e6     RET        0xc
    //         005420e9     ??         90h
    //         005420ea     NOP
    //         005420eb     NOP
    //         005420ec     NOP
    //         005420ed     NOP
    //         005420ee     NOP
    //         005420ef     NOP
    return;
}

uchar RGE_Game_World::load_world(int param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall load_world(RGE_Game_World * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     005420f9(R), 005421be(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00542282(*), 0054228f(R)  
    //              uchar             Stack[-0x8]:1  type                      XREF[5]:     0054221a(W), 0054222b(R), 00542236(W), 0054227e(W), 
    //                                                                                     0054229b(R)  
    //                               ?load_world@RGE_Game_World@@UAEEH@Z                          XREF[2]:     load_world:0052edf9(c), 
    //                               RGE_Game_World::load_world                                                005779d8(*)  
    //                              World.cpp:1021 (9)
    //         005420f0     SUB        ESP,0x8
    //         005420f3     PUSH       EBX
    //         005420f4     PUSH       EBP
    //         005420f5     PUSH       ESI
    //         005420f6     MOV        ESI,this
    //         005420f8     PUSH       EDI
    //                              World.cpp:1032 (27)
    //         005420f9     MOV        EDI,dword ptr [ESP + param_1]
    //         005420fd     LEA        EAX,[ESI + 0x4]
    //         00542100     PUSH       0x4
    //         00542102     PUSH       EAX
    //         00542103     PUSH       EDI
    //         00542104     MOV        byte ptr [ESI + 0x1d],0x2
    //         00542108     MOV        byte ptr [ESI + 0x1e],0x0
    //         0054210c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542111     ADD        ESP,0xc
    //                              World.cpp:1033 (15)
    //         00542114     LEA        this,[ESI + 0x8]
    //         00542117     PUSH       0x4
    //         00542119     PUSH       this
    //         0054211a     PUSH       EDI
    //         0054211b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542120     ADD        ESP,0xc
    //                              World.cpp:1034 (15)
    //         00542123     LEA        EDX,[ESI + 0xc]
    //         00542126     PUSH       0x4
    //         00542128     PUSH       EDX
    //         00542129     PUSH       EDI
    //         0054212a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054212f     ADD        ESP,0xc
    //                              World.cpp:1035 (18)
    //         00542132     LEA        EAX,[ESI + 0x84]
    //         00542138     PUSH       0x4
    //         0054213a     PUSH       EAX
    //         0054213b     PUSH       EDI
    //         0054213c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542141     ADD        ESP,0xc
    //                              World.cpp:1036 (15)
    //         00542144     LEA        this,[ESI + 0x10]
    //         00542147     PUSH       0x4
    //         00542149     PUSH       this
    //         0054214a     PUSH       EDI
    //         0054214b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542150     ADD        ESP,0xc
    //                              World.cpp:1037 (15)
    //         00542153     LEA        EAX,[ESI + 0x18]
    //         00542156     PUSH       0x4
    //         00542158     PUSH       EAX
    //         00542159     PUSH       EDI
    //         0054215a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054215f     ADD        ESP,0xc
    //                              World.cpp:1038 (15)
    //         00542162     LEA        EDX,[ESI + 0x1c]
    //         00542165     PUSH       0x1
    //         00542167     PUSH       EDX
    //         00542168     PUSH       EDI
    //         00542169     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054216e     ADD        ESP,0xc
    //                              World.cpp:1039 (15)
    //         00542171     LEA        EAX,[ESI + 0x68]
    //         00542174     PUSH       0x4
    //         00542176     PUSH       EAX
    //         00542177     PUSH       EDI
    //         00542178     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054217d     ADD        ESP,0xc
    //                              World.cpp:1040 (15)
    //         00542180     LEA        this,[ESI + 0x6c]
    //         00542183     PUSH       0x4
    //         00542185     PUSH       this
    //         00542186     PUSH       EDI
    //         00542187     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054218c     ADD        ESP,0xc
    //                              World.cpp:1041 (15)
    //         0054218f     LEA        EDX,[ESI + 0x78]
    //         00542192     PUSH       0x4
    //         00542194     PUSH       EDX
    //         00542195     PUSH       EDI
    //         00542196     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054219b     ADD        ESP,0xc
    //                              World.cpp:1042 (15)
    //         0054219e     LEA        EAX,[ESI + 0x7c]
    //         005421a1     PUSH       0x2
    //         005421a3     PUSH       EAX
    //         005421a4     PUSH       EDI
    //         005421a5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421aa     ADD        ESP,0xc
    //                              World.cpp:1043 (15)
    //         005421ad     LEA        EBX,[ESI + 0x3c]
    //         005421b0     PUSH       0x2
    //         005421b2     PUSH       EBX
    //         005421b3     PUSH       EDI
    //         005421b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421b9     ADD        ESP,0xc
    //                              World.cpp:1048 (16)
    //         005421bc     PUSH       0x1
    //         005421be     LEA        this=>param_1,[ESP + 0x20]
    //         005421c2     PUSH       this
    //         005421c3     PUSH       EDI
    //         005421c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421c9     ADD        ESP,0xc
    //                              World.cpp:1050 (18)
    //         005421cc     LEA        EDX,[ESI + 0xa4]
    //         005421d2     PUSH       0x4
    //         005421d4     PUSH       EDX
    //         005421d5     PUSH       EDI
    //         005421d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421db     ADD        ESP,0xc
    //                              World.cpp:1051 (18)
    //         005421de     LEA        EAX,[ESI + 0xa8]
    //         005421e4     PUSH       0x4
    //         005421e6     PUSH       EAX
    //         005421e7     PUSH       EDI
    //         005421e8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421ed     ADD        ESP,0xc
    //                              World.cpp:1052 (18)
    //         005421f0     LEA        this,[ESI + 0xac]
    //         005421f6     PUSH       0x4
    //         005421f8     PUSH       this
    //         005421f9     PUSH       EDI
    //         005421fa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005421ff     ADD        ESP,0xc
    //                              World.cpp:1054 (32)
    //         00542202     LEA        EDX,[ESI + 0xb0]
    //         00542208     PUSH       0x4
    //         0054220a     PUSH       EDX
    //         0054220b     PUSH       EDI
    //         0054220c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542211     ADD        ESP,0xc
    //         00542214     LEA        EBP,[ESI + 0xb4]
    //         0054221a     MOV        dword ptr [ESP + type],0x9
    //                               LAB_00542222                                                 XREF[1]:     0054223a(j)  
    //                              World.cpp:1056 (26)
    //         00542222     PUSH       0x4
    //         00542224     PUSH       EBP
    //         00542225     PUSH       EDI
    //         00542226     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054222b     MOV        EAX,dword ptr [ESP + type]
    //         0054222f     ADD        ESP,0xc
    //         00542232     ADD        EBP,0x4
    //         00542235     DEC        EAX
    //         00542236     MOV        dword ptr [ESP + type],EAX
    //         0054223a     JNZ        LAB_00542222
    //                              World.cpp:1060 (14)
    //         0054223c     MOV        this,dword ptr [ESI + 0x28]
    //         0054223f     XOR        EBP,EBP
    //         00542241     PUSH       EDI
    //         00542242     MOV        dword ptr [ESI + 0x14],EBP
    //         00542245     CALL       RGE_Map::load_map                                void load_map(RGE_Map * this, int param_1)
    //                              World.cpp:1061 (7)
    //         0054224a     MOV        this,ESI
    //         0054224c     CALL       RGE_Game_World::initializePathingSystem          int initializePathingSystem(RGE_Game_World * 
    //                              World.cpp:1066 (18)
    //         00542251     MOV        AX,word ptr [EBX]
    //         00542254     MOV        dword ptr [ESI + 0xfc],0xffffffff
    //         0054225e     CMP        AX,BP
    //         00542261     JLE        LAB_005422a7
    //                              World.cpp:1068 (14)
    //         00542263     MOVSX      EAX,AX
    //         00542266     PUSH       EAX
    //         00542267     PUSH       0x4
    //         00542269     CALL       calloc                                           undefined calloc()
    //         0054226e     ADD        ESP,0x8
    //                              World.cpp:1069 (8)
    //         00542271     CMP        word ptr [EBX],BP
    //         00542274     MOV        dword ptr [ESI + 0x40],EAX
    //         00542277     JLE        LAB_005422a7
    //                              World.cpp:1072 (46)
    //         00542279     MOV        this,dword ptr [ESI]
    //         0054227b     MOV        EDX,dword ptr [ECX + this->sprite_num]
    //         0054227e     MOV        dword ptr [ESP + type],EDX
    //                               LAB_00542282                                                 XREF[1]:     005422a5(j)  
    //         00542282     LEA        EAX=>local_4,[ESP + 0x14]
    //         00542286     PUSH       0x1
    //         00542288     PUSH       EAX=>DAT_fffffff8
    //         00542289     PUSH       EDI=>DAT_fffffff4
    //         0054228a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054228f     MOV        this,dword ptr [ESP + local_4]
    //         00542293     ADD        ESP,0xc
    //         00542296     PUSH       EBP
    //         00542297     PUSH       this
    //         00542298     PUSH       EDI
    //         00542299     MOV        this,ESI
    //         0054229b     CALL       dword ptr [ESP + type]
    //         0054229f     MOVSX      EDX,word ptr [EBX]
    //         005422a2     INC        EBP
    //         005422a3     CMP        EBP,EDX
    //         005422a5     JL         LAB_00542282
    //                               LAB_005422a7                                                 XREF[2]:     00542261(j), 00542277(j)  
    //                              World.cpp:1081 (7)
    //         005422a7     MOV        this,ESI
    //         005422a9     CALL       RGE_Game_World::update_mutual_allies             void update_mutual_allies(RGE_Game_World * th
    //                              World.cpp:1085 (16)
    //         005422ae     MOV        EAX,dword ptr [ESI + 0x28]
    //         005422b1     PUSH       0x1
    //         005422b3     MOV        this,dword ptr [EAX + 0x8dc8]
    //         005422b9     CALL       RGE_Unified_Visible_Map::suppress_updates        void suppress_updates(RGE_Unified_Visible_Map
    //                              World.cpp:1087 (7)
    //         005422be     XOR        EBP,EBP
    //         005422c0     CMP        word ptr [EBX],BP
    //         005422c3     JLE        LAB_005422d9
    //                               LAB_005422c5                                                 XREF[1]:     005422d7(j)  
    //                              World.cpp:1088 (20)
    //         005422c5     MOV        this,dword ptr [ESI + 0x40]
    //         005422c8     PUSH       EDI
    //         005422c9     MOV        this,dword ptr [this->_padding_ + EBP*0x4]
    //         005422cc     CALL       RGE_Player::load_info                            void load_info(RGE_Player * this, int param_1)
    //         005422d1     MOVSX      EDX,word ptr [EBX]
    //         005422d4     INC        EBP
    //         005422d5     CMP        EBP,EDX
    //         005422d7     JL         LAB_005422c5
    //                               LAB_005422d9                                                 XREF[1]:     005422c3(j)  
    //                              World.cpp:1090 (16)
    //         005422d9     MOV        EAX,dword ptr [ESI + 0x28]
    //         005422dc     PUSH       0x0
    //         005422de     MOV        this,dword ptr [EAX + 0x8dc8]
    //         005422e4     CALL       RGE_Unified_Visible_Map::suppress_updates        void suppress_updates(RGE_Unified_Visible_Map
    //                              World.cpp:1092 (12)
    //         005422e9     MOV        EDX,dword ptr [ESI]
    //         005422eb     PUSH       ESI
    //         005422ec     PUSH       EDI=>DAT_fffffff8
    //         005422ed     MOV        this,ESI
    //         005422ef     CALL       dword ptr [EDX + 0xf4]
    //                              World.cpp:1095 (19)
    //         005422f5     FLD        float ptr [save_game_version]                    = 7.23
    //         005422fb     FCOMP      float ptr [DAT_00577a10]                         = B8h
    //         00542301     FNSTSW     AX
    //         00542303     TEST       AH,0x1
    //         00542306     JNZ        LAB_0054231c
    //                              World.cpp:1096 (18)
    //         00542308     LEA        EAX,[ESI + 0x100]
    //         0054230e     PUSH       0x4
    //         00542310     PUSH       EAX=>DAT_fffffff8
    //         00542311     PUSH       EDI=>DAT_fffffff4
    //         00542312     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00542317     ADD        ESP,0xc
    //                              World.cpp:1097 (2)
    //         0054231a     JMP        LAB_00542326
    //                               LAB_0054231c                                                 XREF[1]:     00542306(j)  
    //                              World.cpp:1098 (10)
    //         0054231c     MOV        dword ptr [ESI + 0x100],0xffffffff
    //                               LAB_00542326                                                 XREF[1]:     0054231a(j)  
    //                              World.cpp:1101 (15)
    //         00542326     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0054232c     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         00542331     TEST       EAX,EAX
    //         00542333     JZ         LAB_00542343
    //                              World.cpp:1102 (14)
    //         00542335     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0054233b     CALL       RGE_Base_Game::get_game_speed                    float get_game_speed(RGE_Base_Game * this)
    //         00542340     FSTP       float ptr [ESI + 0x18]
    //                               LAB_00542343                                                 XREF[1]:     00542333(j)  
    //                              World.cpp:1105 (4)
    //         00542343     MOV        this,byte ptr [ESP + 0x1c]
    //                              World.cpp:1107 (15)
    //         00542347     POP        EDI
    //         00542348     MOV        byte ptr [ESI + 0x1d],this
    //         0054234b     POP        ESI
    //         0054234c     POP        EBP
    //         0054234d     MOV        AL,0x1
    //         0054234f     POP        EBX
    //         00542350     ADD        ESP,0x8
    //         00542353     RET        0x4
    //         00542356     ??         90h
    //         00542357     NOP
    //         00542358     NOP
    //         00542359     NOP
    //         0054235a     NOP
    //         0054235b     NOP
    //         0054235c     NOP
    //         0054235d     NOP
    //         0054235e     NOP
    //         0054235f     NOP
    return 0;
}

uchar RGE_Game_World::load_game(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall load_game(RGE_Game_World * this, char * param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              char[300]         Stack[-0x130   tempname
    //              char[8]           Stack[-0x138   version
    //                               ?load_game@RGE_Game_World@@UAEEPAD@Z                         XREF[2]:     00577524(*), 005779dc(*)  
    //                               RGE_Game_World::load_game
    //                              World.cpp:1111 (6)
    //         00542360     SUB        ESP,0x134
    //                              World.cpp:1116 (16)
    //         00542366     MOV        dword ptr [world_update_counter],0x0
    //         00542370     PUSH       EBX
    //         00542371     PUSH       EBP
    //         00542372     MOV        EBP,this
    //         00542374     PUSH       ESI
    //         00542375     PUSH       EDI
    //                              World.cpp:1118 (9)
    //         00542376     MOV        EBX,dword ptr [EBP]
    //         00542379     CALL       dword ptr [EBX + 0xb8]
    //                              World.cpp:1120 (42)
    //         0054237f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542385     MOV        EAX,dword ptr [ESP + 0x148]
    //         0054238c     PUSH       EAX
    //         0054238d     LEA        EAX,[ESP + 0x1c]
    //         00542391     MOV        EDX,dword ptr [ECX + this->world_time_delta]
    //         00542394     ADD        EDX,0xb12
    //         0054239a     PUSH       EDX=>DAT_fffffff8
    //         0054239b     PUSH       s_%s%s                                           = "%s%s"
    //         005423a0     PUSH       EAX=>DAT_fffffff0
    //         005423a1     CALL       sprintf                                          undefined sprintf()
    //         005423a6     ADD        ESP,0x10
    //                              World.cpp:1121 (29)
    //         005423a9     LEA        this,[ESP + 0x18]
    //         005423ad     PUSH       0x8000
    //         005423b2     PUSH       this=>DAT_fffffff8
    //         005423b3     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
    //         005423b8     MOV        EDI,EAX
    //         005423ba     ADD        ESP,0x8
    //         005423bd     CMP        EDI,-0x1
    //         005423c0     JZ         LAB_00542454
    //                              World.cpp:1123 (16)
    //         005423c6     LEA        EDX,[ESP + 0x10]
    //         005423ca     PUSH       0x8
    //         005423cc     PUSH       EDX=>DAT_fffffff8
    //         005423cd     PUSH       EDI=>DAT_fffffff4
    //         005423ce     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005423d3     ADD        ESP,0xc
    //                              World.cpp:1124 (16)
    //         005423d6     PUSH       0x4
    //         005423d8     PUSH       save_game_version                                = 7.23
    //         005423dd     PUSH       EDI=>DAT_fffffff4
    //         005423de     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005423e3     ADD        ESP,0xc
    //                              World.cpp:1134 (52)
    //         005423e6     MOV        ESI,s_VER_8.6                                    = 56h
    //         005423eb     LEA        EAX,[ESP + 0x10]
    //                               LAB_005423ef                                                 XREF[1]:     0054240d(j)  
    //         005423ef     MOV        DL,byte ptr [EAX]
    //         005423f1     MOV        this,DL
    //         005423f3     CMP        DL,byte ptr [ESI]=>s_VER_8.6                     = 56h
    //                                                                                  = 52h
    //         005423f5     JNZ        LAB_00542413
    //         005423f7     TEST       this,this
    //         005423f9     JZ         LAB_0054240f
    //         005423fb     MOV        DL,byte ptr [EAX + 0x1]
    //         005423fe     MOV        this,DL
    //         00542400     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0058ec29            = 45h
    //                                                                                  = 20h
    //         00542403     JNZ        LAB_00542413
    //         00542405     ADD        EAX,0x2
    //         00542408     ADD        ESI,0x2
    //         0054240b     TEST       this,this
    //         0054240d     JNZ        LAB_005423ef
    //                               LAB_0054240f                                                 XREF[1]:     005423f9(j)  
    //         0054240f     XOR        EAX,EAX
    //         00542411     JMP        LAB_00542418
    //                               LAB_00542413                                                 XREF[2]:     005423f5(j), 00542403(j)  
    //         00542413     SBB        EAX,EAX
    //         00542415     SBB        EAX,-0x1
    //                               LAB_00542418                                                 XREF[1]:     00542411(j)  
    //         00542418     TEST       EAX,EAX
    //                              World.cpp:1136 (11)
    //         0054241a     PUSH       EDI
    //         0054241b     JZ         LAB_00542434
    //         0054241d     CALL       rge_close                                        int rge_close(int param_1)
    //         00542422     ADD        ESP,0x4
    //                              World.cpp:1145 (2)
    //         00542425     XOR        AL,AL
    //                              World.cpp:1146 (13)
    //         00542427     POP        EDI
    //         00542428     POP        ESI
    //         00542429     POP        EBP
    //         0054242a     POP        EBX
    //         0054242b     ADD        ESP,0x134
    //         00542431     RET        0x4
    //                               LAB_00542434                                                 XREF[1]:     0054241b(j)  
    //                              World.cpp:1140 (8)
    //         00542434     MOV        this,EBP
    //         00542436     CALL       dword ptr [EBX + 0xc8]
    //                              World.cpp:1141 (9)
    //         0054243c     PUSH       EDI
    //         0054243d     CALL       rge_close                                        int rge_close(int param_1)
    //         00542442     ADD        ESP,0x4
    //                              World.cpp:1142 (2)
    //         00542445     MOV        AL,0x1
    //                              World.cpp:1146 (28)
    //         00542447     POP        EDI
    //         00542448     POP        ESI
    //         00542449     POP        EBP
    //         0054244a     POP        EBX
    //         0054244b     ADD        ESP,0x134
    //         00542451     RET        0x4
    //                               LAB_00542454                                                 XREF[1]:     005423c0(j)  
    //         00542454     POP        EDI
    //         00542455     POP        ESI
    //         00542456     POP        EBP
    //         00542457     XOR        AL,AL
    //         00542459     POP        EBX
    //         0054245a     ADD        ESP,0x134
    //         00542460     RET        0x4
    //         00542463     ??         90h
    //         00542464     NOP
    //         00542465     NOP
    //         00542466     NOP
    //         00542467     NOP
    //         00542468     NOP
    //         00542469     NOP
    //         0054246a     NOP
    //         0054246b     NOP
    //         0054246c     NOP
    //         0054246d     NOP
    //         0054246e     NOP
    //         0054246f     NOP
    return 0;
}

void RGE_Game_World::set_game_speed(float param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_game_speed(RGE_Game_World * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     00542470(R)  
    //                               ?set_game_speed@RGE_Game_World@@QAEXM@Z                      XREF[1]:     do_command_game:0050a279(c)  
    //                               RGE_Game_World::set_game_speed
    //                              World.cpp:1150 (7)
    //         00542470     MOV        EAX,dword ptr [ESP + param_1]
    //         00542474     MOV        dword ptr [ECX + this->game_speed],EAX
    //                              World.cpp:1152 (3)
    //         00542477     RET        0x4
    //         0054247a     ??         90h
    //         0054247b     NOP
    //         0054247c     NOP
    //         0054247d     NOP
    //         0054247e     NOP
    //         0054247f     NOP
    return;
}

void RGE_Game_World::setup_gaia() {
    /* TODO: Stub */
    //                              void __thiscall setup_gaia(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005424ac(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005424d9(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     005424a6(W)  
    //                               ?setup_gaia@RGE_Game_World@@MAEXXZ                           XREF[1]:     0057796c(*)  
    //                               RGE_Game_World::setup_gaia
    //                              World.cpp:1156 (25)
    //         00542480     PUSH       -0x1
    //         00542482     PUSH       FUN_00561e2b
    //         00542487     MOV        EAX,FS:[0x0]
    //         0054248d     PUSH       EAX
    //         0054248e     MOV        dword ptr FS:[0x0],ESP
    //         00542495     PUSH       this
    //         00542496     PUSH       ESI
    //         00542497     MOV        ESI,this
    //                              World.cpp:1157 (61)
    //         00542499     PUSH       0x220
    //         0054249e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005424a3     ADD        ESP,0x4
    //         005424a6     MOV        dword ptr [ESP + local_10],EAX
    //         005424aa     TEST       EAX,EAX
    //         005424ac     MOV        dword ptr [ESP + local_4],0x0
    //         005424b4     JZ         LAB_005424d1
    //         005424b6     MOV        this,dword ptr [ESI + 0x48]
    //         005424b9     PUSH       0x1
    //         005424bb     PUSH       0x0
    //         005424bd     PUSH       s_GAIA                                           = "GAIA"
    //         005424c2     MOV        EDX,dword ptr [this->_padding_]
    //         005424c4     PUSH       0x0
    //         005424c6     PUSH       EDX
    //         005424c7     PUSH       ESI
    //         005424c8     MOV        this,EAX
    //         005424ca     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, RGE_G
    //         005424cf     JMP        LAB_005424d3
    //                               LAB_005424d1                                                 XREF[1]:     005424b4(j)  
    //         005424d1     XOR        EAX,EAX
    //                               LAB_005424d3                                                 XREF[1]:     005424cf(j)  
    //         005424d3     MOV        this,dword ptr [ESI + 0x40]
    //                              World.cpp:1159 (18)
    //         005424d6     POP        ESI
    //         005424d7     MOV        dword ptr [this->_padding_],EAX
    //         005424d9     MOV        this,dword ptr [ESP + local_c]
    //         005424dd     MOV        dword ptr FS:[0x0],this
    //         005424e4     ADD        ESP,0x10
    //         005424e7     RET
    //         005424e8     ??         90h
    //         005424e9     NOP
    //         005424ea     NOP
    //         005424eb     NOP
    //         005424ec     NOP
    //         005424ed     NOP
    //         005424ee     NOP
    //         005424ef     NOP
    return;
}

void RGE_Game_World::setup_players(RGE_Player_Info* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setup_players(RGE_Game_World * this, RGE_Player_Info
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[2]:     0054251b(R), 00542539(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054253f(W), 0054257f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00542597(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0054250f(W), 00542563(R), 0054258f(W)  
    //              short             Stack[-0x14]:2 index
    //                               ?setup_players@RGE_Game_World@@MAEXAAURGE_Player_Info@@@Z    XREF[1]:     00577970(*)  
    //                               RGE_Game_World::setup_players
    //                              World.cpp:1163 (26)
    //         005424f0     PUSH       -0x1
    //         005424f2     PUSH       FUN_00561e4b
    //         005424f7     MOV        EAX,FS:[0x0]
    //         005424fd     PUSH       EAX
    //         005424fe     MOV        dword ptr FS:[0x0],ESP
    //         00542505     PUSH       this
    //         00542506     PUSH       EBX
    //         00542507     PUSH       EDI
    //         00542508     MOV        EDI,this
    //                              World.cpp:1166 (21)
    //         0054250a     MOV        EBX,0x1
    //         0054250f     MOV        dword ptr [ESP + local_10],EBX
    //         00542513     CMP        word ptr [EDI + 0x3c],BX
    //         00542517     JLE        LAB_00542597
    //         00542519     PUSH       ESI
    //         0054251a     PUSH       EBP
    //         0054251b     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_0054251f                                                 XREF[1]:     00542593(j)  
    //                              World.cpp:1167 (13)
    //         0054251f     MOVSX      ESI,BX
    //         00542522     CMP        byte ptr [EBP + ESI*0x1 + 0x248],0xff
    //         0054252a     JZ         LAB_0054258a
    //                              World.cpp:1168 (107)
    //         0054252c     PUSH       0x220
    //         00542531     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00542536     ADD        ESP,0x4
    //         00542539     MOV        dword ptr [ESP + param_1],EAX
    //         0054253d     TEST       EAX,EAX
    //         0054253f     MOV        dword ptr [ESP + local_4],0x0
    //         00542547     JZ         LAB_0054257a
    //         00542549     MOV        DL,byte ptr [EBP + ESI*0x1 + 0x251]
    //         00542550     MOV        this,ESI
    //         00542552     SHL        this,0x6
    //         00542555     MOV        EBX,EBP
    //         00542557     PUSH       0x1
    //         00542559     ADD        EBX,this
    //         0054255b     PUSH       EDX
    //         0054255c     MOVSX      EDX,DL
    //         0054255f     LEA        this,[ESI + EBX*0x1 + -0x41]
    //         00542563     MOV        EBX,dword ptr [ESP + local_10]
    //         00542567     PUSH       this
    //         00542568     MOV        this,dword ptr [EDI + 0x48]
    //         0054256b     PUSH       EBX
    //         0054256c     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         0054256f     MOV        this,EAX
    //         00542571     PUSH       EDX
    //         00542572     PUSH       EDI
    //         00542573     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, RGE_G
    //         00542578     JMP        LAB_0054257c
    //                               LAB_0054257a                                                 XREF[1]:     00542547(j)  
    //         0054257a     XOR        EAX,EAX
    //                               LAB_0054257c                                                 XREF[1]:     00542578(j)  
    //         0054257c     MOV        this,dword ptr [EDI + 0x40]
    //         0054257f     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00542587     MOV        dword ptr [this->_padding_ + ESI*0x4],EAX
    //                               LAB_0054258a                                                 XREF[1]:     0054252a(j)  
    //         0054258a     INC        EBX
    //         0054258b     CMP        BX,word ptr [EDI + 0x3c]
    //         0054258f     MOV        dword ptr [ESP + local_10],EBX
    //         00542593     JL         LAB_0054251f
    //         00542595     POP        EBP
    //         00542596     POP        ESI
    //                               LAB_00542597                                                 XREF[1]:     00542517(j)  
    //                              World.cpp:1169 (19)
    //         00542597     MOV        this,dword ptr [ESP + local_c]
    //         0054259b     POP        EDI
    //         0054259c     MOV        dword ptr FS:[0x0],this
    //         005425a3     POP        EBX
    //         005425a4     ADD        ESP,0x10
    //         005425a7     RET        0x4
    //         005425aa     ??         90h
    //         005425ab     NOP
    //         005425ac     NOP
    //         005425ad     NOP
    //         005425ae     NOP
    //         005425af     NOP
    return;
}

void RGE_Game_World::setup_player_colors(RGE_Player_Info* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setup_player_colors(RGE_Game_World * this, RGE_Playe
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[2]:     005425c8(R), 00542615(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     005425d8(W), 005425e0(W), 0054261f(R)  
    //              long              Stack[-0x8]:4  info_player_num           XREF[4]:     0054260f(W), 00542657(R), 0054267e(R), 005426bd(R)  
    //              uchar *           Stack[-0xc]:4  players_done              XREF[4]:     005425ff(W), 00542633(R), 00542653(R), 0054266f(R)  
    //              uchar *           Stack[-0x10]:4 colors_used
    //                               ?setup_player_colors@RGE_Game_World@@UAEXAAURGE_Player_Info  XREF[2]:     00577500(*), 005779b8(*)  
    //                               RGE_Game_World::setup_player_colors
    //                              World.cpp:1173 (9)
    //         005425b0     SUB        ESP,0xc
    //         005425b3     PUSH       EBX
    //         005425b4     PUSH       EBP
    //         005425b5     PUSH       ESI
    //         005425b6     MOV        ESI,this
    //         005425b8     PUSH       EDI
    //                              World.cpp:1180 (15)
    //         005425b9     PUSH       0x7
    //         005425bb     MOV        EAX,dword ptr [ESI + 0x40]
    //         005425be     OR         EBX,0xffffffff
    //         005425c1     MOV        this,dword ptr [EAX]
    //         005425c3     CALL       RGE_Player::set_color_table                      void set_color_table(RGE_Player * this, uchar
    //                              World.cpp:1182 (4)
    //         005425c8     MOV        this,dword ptr [ESP + param_1]
    //                              World.cpp:1183 (20)
    //         005425cc     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005425d0     MOVSX      this,word ptr [this->_padding_ + 0x294]
    //         005425d7     INC        EAX
    //         005425d8     MOV        dword ptr [ESP + local_4],this
    //         005425dc     CMP        this,EAX
    //         005425de     JLE        LAB_005425e4
    //                              World.cpp:1184 (4)
    //         005425e0     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_005425e4                                                 XREF[1]:     005425de(j)  
    //                              World.cpp:1186 (21)
    //         005425e4     MOVSX      EDX,word ptr [ESI + 0x60]
    //         005425e8     MOV        EDI,0x1
    //         005425ed     PUSH       EDI
    //         005425ee     PUSH       EDX
    //         005425ef     CALL       calloc                                           undefined calloc()
    //         005425f4     MOV        EBP,EAX
    //         005425f6     ADD        ESP,0x8
    //                              World.cpp:1187 (18)
    //         005425f9     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005425fd     PUSH       EDI
    //         005425fe     PUSH       EAX
    //         005425ff     MOV        dword ptr [ESP + players_done],EBP
    //         00542603     CALL       calloc                                           undefined calloc()
    //         00542608     ADD        ESP,0x8
    //                              World.cpp:1190 (20)
    //         0054260b     CMP        word ptr [ESI + 0x3c],DI
    //         0054260f     MOV        dword ptr [ESP + info_player_num],EAX
    //         00542613     JLE        LAB_00542673
    //         00542615     MOV        this,dword ptr [ESP + param_1]
    //         00542619     LEA        EBP,[this->_padding_ + 0x25c]
    //                               LAB_0054261f                                                 XREF[1]:     0054266d(j)  
    //                              World.cpp:1191 (20)
    //         0054261f     MOV        EAX,dword ptr [ESP + local_4]
    //         00542623     LEA        EDX,[EDI + -0x1]
    //         00542626     CMP        EDX,EAX
    //         00542628     JGE        LAB_00542663
    //         0054262a     MOV        AX,word ptr [EBP]
    //         0054262e     TEST       AX,AX
    //         00542631     JL         LAB_00542663
    //                              World.cpp:1193 (13)
    //         00542633     MOV        this,dword ptr [ESP + players_done]
    //         00542637     MOVSX      EAX,AX
    //         0054263a     CMP        byte ptr [this->_padding_ + EAX*0x1],0x0
    //         0054263e     JNZ        LAB_00542663
    //                              World.cpp:1195 (15)
    //         00542640     MOV        EAX,dword ptr [ESI + 0x40]
    //         00542643     MOV        DL,byte ptr [EBP]
    //         00542646     PUSH       EDX
    //         00542647     MOV        this,dword ptr [EAX + EDI*0x4]
    //         0054264a     CALL       RGE_Player::set_color_table                      void set_color_table(RGE_Player * this, uchar
    //                              World.cpp:1196 (8)
    //         0054264f     MOVSX      this,word ptr [EBP]
    //         00542653     MOV        EDX,dword ptr [ESP + players_done]
    //                              World.cpp:1197 (24)
    //         00542657     MOV        EAX,dword ptr [ESP + info_player_num]
    //         0054265b     MOV        byte ptr [EDX + this->_padding_*0x1],0x1
    //         0054265f     MOV        byte ptr [EAX + EDI*0x1],0x1
    //                               LAB_00542663                                                 XREF[3]:     00542628(j), 00542631(j), 
    //                                                                                                         0054263e(j)  
    //         00542663     MOVSX      this,word ptr [ESI + 0x3c]
    //         00542667     INC        EDI
    //         00542668     ADD        EBP,0x2
    //         0054266b     CMP        EDI,this
    //         0054266d     JL         LAB_0054261f
    //                              World.cpp:1190 (4)
    //         0054266f     MOV        EBP,dword ptr [ESP + players_done]
    //                               LAB_00542673                                                 XREF[1]:     00542613(j)  
    //                              World.cpp:1203 (11)
    //         00542673     MOV        EDI,0x1
    //         00542678     CMP        word ptr [ESI + 0x3c],DI
    //         0054267c     JLE        LAB_005426b7
    //                               LAB_0054267e                                                 XREF[1]:     005426b5(j)  
    //                              World.cpp:1204 (10)
    //         0054267e     MOV        EDX,dword ptr [ESP + info_player_num]
    //         00542682     CMP        byte ptr [EDX + EDI*0x1],0x0
    //         00542686     JNZ        LAB_005426ae
    //                               LAB_00542688                                                 XREF[2]:     0054268f(j), 0054269b(j)  
    //                              World.cpp:1212 (21)
    //         00542688     MOV        AL,byte ptr [EBP + EBX*0x1 + 0x1]
    //         0054268c     INC        EBX
    //         0054268d     CMP        AL,0x1
    //         0054268f     JZ         LAB_00542688
    //         00542691     MOV        EAX,dword ptr [ESI + 0x64]
    //         00542694     MOV        this,dword ptr [EAX + EBX*0x4]
    //         00542697     CMP        byte ptr [ECX + this->sprite_update_index],0x1
    //         0054269b     JNZ        LAB_00542688
    //                              World.cpp:1214 (12)
    //         0054269d     MOV        EDX,dword ptr [ESI + 0x40]
    //         005426a0     PUSH       EBX
    //         005426a1     MOV        this,dword ptr [EDX + EDI*0x4]
    //         005426a4     CALL       RGE_Player::set_color_table                      void set_color_table(RGE_Player * this, uchar
    //                              World.cpp:1215 (14)
    //         005426a9     MOV        byte ptr [EBP + EBX*0x1],0x1
    //                               LAB_005426ae                                                 XREF[1]:     00542686(j)  
    //         005426ae     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005426b2     INC        EDI
    //         005426b3     CMP        EDI,EAX
    //         005426b5     JL         LAB_0054267e
    //                               LAB_005426b7                                                 XREF[1]:     0054267c(j)  
    //                              World.cpp:1218 (6)
    //         005426b7     PUSH       EBP
    //         005426b8     CALL       free                                             undefined free()
    //                              World.cpp:1219 (16)
    //         005426bd     MOV        this,dword ptr [ESP + info_player_num]
    //         005426c1     ADD        ESP,0x4
    //         005426c4     PUSH       this
    //         005426c5     CALL       free                                             undefined free()
    //         005426ca     ADD        ESP,0x4
    //                              World.cpp:1220 (10)
    //         005426cd     POP        EDI
    //         005426ce     POP        ESI
    //         005426cf     POP        EBP
    //         005426d0     POP        EBX
    //         005426d1     ADD        ESP,0xc
    //         005426d4     RET        0x4
    //         005426d7     ??         90h
    //         005426d8     NOP
    //         005426d9     NOP
    //         005426da     NOP
    //         005426db     NOP
    //         005426dc     NOP
    //         005426dd     NOP
    //         005426de     NOP
    //         005426df     NOP
    return;
}

void RGE_Game_World::setup_player_colors() {
    /* TODO: Stub */
    //                              void __thiscall setup_player_colors(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?setup_player_colors@RGE_Game_World@@UAEXXZ                  XREF[2]:     005774fc(*), 005779b4(*)  
    //                               RGE_Game_World::setup_player_colors
    //                              World.cpp:1224 (6)
    //         005426e0     PUSH       EBX
    //         005426e1     PUSH       EBP
    //         005426e2     PUSH       ESI
    //         005426e3     PUSH       EDI
    //         005426e4     MOV        EDI,this
    //                              World.cpp:1229 (15)
    //         005426e6     PUSH       0x7
    //         005426e8     OR         ESI,0xffffffff
    //         005426eb     MOV        EAX,dword ptr [EDI + 0x40]
    //         005426ee     MOV        this,dword ptr [EAX]
    //         005426f0     CALL       RGE_Player::set_color_table                      void set_color_table(RGE_Player * this, uchar
    //                              World.cpp:1231 (12)
    //         005426f5     MOVSX      this,word ptr [EDI + 0x60]
    //         005426f9     PUSH       0x1
    //         005426fb     PUSH       this
    //         005426fc     CALL       calloc                                           undefined calloc()
    //                              World.cpp:1235 (16)
    //         00542701     MOV        EBP,0x1
    //         00542706     ADD        ESP,0x8
    //         00542709     CMP        word ptr [EDI + 0x3c],BP
    //         0054270d     MOV        EBX,EAX
    //         0054270f     JLE        LAB_0054273f
    //                               LAB_00542711                                                 XREF[3]:     00542718(j), 00542724(j), 
    //                                                                                                         0054273d(j)  
    //                              World.cpp:1243 (21)
    //         00542711     MOV        AL,byte ptr [EBX + ESI*0x1 + 0x1]
    //         00542715     INC        ESI
    //         00542716     CMP        AL,0x1
    //         00542718     JZ         LAB_00542711
    //         0054271a     MOV        EDX,dword ptr [EDI + 0x64]
    //         0054271d     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         00542720     CMP        byte ptr [EAX + 0x24],0x1
    //         00542724     JNZ        LAB_00542711
    //                              World.cpp:1245 (12)
    //         00542726     MOV        this,dword ptr [EDI + 0x40]
    //         00542729     PUSH       ESI
    //         0054272a     MOV        this,dword ptr [this->_padding_ + EBP*0x4]
    //         0054272d     CALL       RGE_Player::set_color_table                      void set_color_table(RGE_Player * this, uchar
    //                              World.cpp:1246 (13)
    //         00542732     MOV        byte ptr [EBX + ESI*0x1],0x1
    //         00542736     INC        EBP
    //         00542737     MOVSX      EDX,word ptr [EDI + 0x3c]
    //         0054273b     CMP        EBP,EDX
    //         0054273d     JL         LAB_00542711
    //                               LAB_0054273f                                                 XREF[1]:     0054270f(j)  
    //                              World.cpp:1249 (9)
    //         0054273f     PUSH       EBX
    //         00542740     CALL       free                                             undefined free()
    //         00542745     ADD        ESP,0x4
    //                              World.cpp:1250 (5)
    //         00542748     POP        EDI
    //         00542749     POP        ESI
    //         0054274a     POP        EBP
    //         0054274b     POP        EBX
    //         0054274c     RET
    //         0054274d     ??         90h
    //         0054274e     NOP
    //         0054274f     NOP
    return;
}

uchar RGE_Game_World::new_game(RGE_Player_Info* param_1, int param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall new_game(RGE_Game_World * this, RGE_Player_Info * p
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              char[256]         Stack[-0x104   randomString
    //              int               Stack[-0x108   team
    //              uchar             Stack[-0x109   retval
    //                               ?new_game@RGE_Game_World@@UAEEAAURGE_Player_Info@@H@Z        XREF[2]:     new_game:0052ef75(c), 005779e0(*)  
    //                               RGE_Game_World::new_game
    //                              World.cpp:1254 (11)
    //         00542750     SUB        ESP,0x108
    //         00542756     PUSH       EBX
    //         00542757     PUSH       EBP
    //         00542758     PUSH       ESI
    //         00542759     MOV        ESI,this
    //                              World.cpp:1255 (3)
    //         0054275b     XOR        EBX,EBX
    //         0054275d     PUSH       EDI
    //                              World.cpp:1258 (16)
    //         0054275e     MOV        this,pathSystem
    //         00542763     MOV        dword ptr [world_update_counter],EBX
    //         00542769     CALL       PathingSystem::zeroObstructionMap                void zeroObstructionMap(PathingSystem * this)
    //                              World.cpp:1259 (10)
    //         0054276e     MOV        this,aiPathSystem
    //         00542773     CALL       PathingSystem::zeroObstructionMap                void zeroObstructionMap(PathingSystem * this)
    //                              World.cpp:1264 (24)
    //         00542778     MOV        this,0xd
    //         0054277d     XOR        EAX,EAX
    //         0054277f     MOV        EDI,computerPlayerSetup                          = 00000000
    //         00542784     MOV        dword ptr [ESI + 0xfc],0xffffffff
    //         0054278e     STOSD.REP  ES:EDI=>computerPlayerSetup                      = 00000000
    //                              World.cpp:1269 (10)
    //         00542790     MOV        EDI,dword ptr [ESI]
    //         00542792     MOV        this,ESI
    //         00542794     CALL       dword ptr [EDI + 0xb8]
    //                              World.cpp:1272 (5)
    //         0054279a     CALL       debug_random_reset                               void debug_random_reset(void)
    //                              World.cpp:1280 (28)
    //         0054279f     MOV        AX,word ptr [ESP + 0x120]
    //         005427a7     MOV        dword ptr [debug_timeGetTime_cnt],EBX
    //         005427ad     MOV        dword ptr [debug_timeGetTime_time],EBX
    //         005427b3     MOV        byte ptr [ESI + 0x1d],0x3
    //         005427b7     MOV        word ptr [ESI + 0x7c],AX
    //                              World.cpp:1282 (15)
    //         005427bb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005427c1     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         005427c6     TEST       EAX,EAX
    //         005427c8     JZ         LAB_005427d7
    //                              World.cpp:1283 (11)
    //         005427ca     MOV        this,dword ptr [ESI + 0x58]
    //         005427cd     MOV        this,dword ptr [ECX + this->old_time]
    //         005427d0     CALL       TCommunications_Handler::GetRandomSeed           uint GetRandomSeed(TCommunications_Handler * 
    //                              World.cpp:1284 (2)
    //         005427d5     JMP        LAB_005427f7
    //                               LAB_005427d7                                                 XREF[1]:     005427c8(j)  
    //                              World.cpp:1286 (12)
    //         005427d7     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         005427dd     MOV        EAX,dword ptr [EDX + 0x28]
    //         005427e0     CMP        EAX,-0x1
    //                              World.cpp:1288 (2)
    //         005427e3     JNZ        LAB_005427f7
    //                              World.cpp:1289 (18)
    //         005427e5     PUSH       0x509
    //         005427ea     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         005427ef     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         005427f4     ADD        ESP,0x8
    //                               LAB_005427f7                                                 XREF[2]:     005427d5(j), 005427e3(j)  
    //                              World.cpp:1292 (19)
    //         005427f7     PUSH       EAX
    //         005427f8     PUSH       offset DAT_fffffff8
    //         005427fd     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542802     MOV        dword ptr [ESI + 0x78],EAX
    //         00542805     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              World.cpp:1293 (14)
    //         0054280a     MOV        EAX,[rge_base_game]                              = 00000000
    //         0054280f     MOV        this,dword ptr [ESI + 0x78]
    //         00542812     ADD        ESP,0xc
    //         00542815     MOV        dword ptr [EAX + 0x30],this
    //                              World.cpp:1295 (21)
    //         00542818     PUSH       0x50f
    //         0054281d     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542822     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542827     ADD        ESP,0x8
    //         0054282a     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1296 (18)
    //         0054282d     MOV        EDX,dword ptr [L]                                = 00000000
    //         00542833     PUSH       EAX
    //         00542834     PUSH       s_World:_new_game_(rand=%d)                      = "World: new_game (rand=%d)"
    //         00542839     PUSH       EDX=>DAT_fffffff4
    //         0054283a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              World.cpp:1299 (23)
    //         0054283f     MOV        EBP,dword ptr [ESP + 0x128]
    //         00542846     ADD        ESP,0xc
    //         00542849     MOV        AX,word ptr [EBP + 0x294]
    //         00542850     INC        AX
    //         00542852     MOV        word ptr [ESI + 0x3c],AX
    //                              World.cpp:1300 (24)
    //         00542856     MOVSX      this,word ptr [EBP + 0x2a4]
    //         0054285d     MOVSX      EDX,word ptr [EBP + 0x2a2]
    //         00542864     PUSH       this
    //         00542865     MOV        this,dword ptr [ESI + 0x28]
    //         00542868     PUSH       EDX=>DAT_fffffff8
    //         00542869     CALL       RGE_Map::new_map                                 void new_map(RGE_Map * this, long param_1, lo
    //                              World.cpp:1302 (21)
    //         0054286e     PUSH       0x516
    //         00542873     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542878     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0054287d     ADD        ESP,0x8
    //         00542880     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1303 (17)
    //         00542883     PUSH       EAX
    //         00542884     MOV        EAX,[L]                                          = 00000000
    //         00542889     PUSH       s___World:_after_new_map_(rand=%d)               = "  World: after_new_map (rand=%d)"
    //         0054288e     PUSH       EAX=>DAT_fffffff4
    //         0054288f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              World.cpp:1306 (12)
    //         00542894     MOV        AX,word ptr [EBP + 0x294]
    //         0054289b     ADD        ESP,0xc
    //         0054289e     INC        AX
    //                              World.cpp:1307 (18)
    //         005428a0     MOVSX      this,AX
    //         005428a3     PUSH       this
    //         005428a4     PUSH       offset DAT_fffffff8
    //         005428a6     MOV        word ptr [ESI + 0x3c],AX
    //         005428aa     CALL       calloc                                           undefined calloc()
    //         005428af     ADD        ESP,0x8
    //                              World.cpp:1310 (8)
    //         005428b2     MOV        this,ESI
    //         005428b4     MOV        dword ptr [ESI + 0x40],EAX
    //         005428b7     CALL       dword ptr [EDI + 0x5c]
    //                              World.cpp:1312 (21)
    //         005428ba     PUSH       0x520
    //         005428bf     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         005428c4     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         005428c9     ADD        ESP,0x8
    //         005428cc     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1313 (21)
    //         005428cf     MOV        EDX,dword ptr [L]                                = 00000000
    //         005428d5     PUSH       EAX
    //         005428d6     PUSH       s___World:_after_gaia_(rand=%d)                  = "  World: after_gaia (rand=%d)"
    //         005428db     PUSH       EDX=>DAT_fffffff4
    //         005428dc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         005428e1     ADD        ESP,0xc
    //                              World.cpp:1316 (6)
    //         005428e4     MOV        this,ESI
    //         005428e6     PUSH       EBP
    //         005428e7     CALL       dword ptr [EDI + 0x60]
    //                              World.cpp:1318 (21)
    //         005428ea     PUSH       0x526
    //         005428ef     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         005428f4     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         005428f9     ADD        ESP,0x8
    //         005428fc     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1319 (20)
    //         005428ff     PUSH       EAX
    //         00542900     MOV        EAX,[L]                                          = 00000000
    //         00542905     PUSH       s___World:_after_players_(rand=%d)               = "  World: after_players (rand=%d)"
    //         0054290a     PUSH       EAX=>DAT_fffffff4
    //         0054290b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00542910     ADD        ESP,0xc
    //                              World.cpp:1328 (5)
    //         00542913     MOV        EBX,0x1
    //                               LAB_00542918                                                 XREF[1]:     005429cd(j)  
    //                              World.cpp:1330 (12)
    //         00542918     MOV        this,dword ptr [ESI + 0x58]
    //         0054291b     PUSH       EBX
    //         0054291c     MOV        this,dword ptr [ECX + this->old_time]
    //         0054291f     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              World.cpp:1331 (14)
    //         00542924     CMP        EAX,0x2
    //         00542927     JZ         LAB_00542932
    //         00542929     CMP        EAX,0x4
    //         0054292c     JNZ        LAB_005429c9
    //                               LAB_00542932                                                 XREF[1]:     00542927(j)  
    //                              World.cpp:1333 (17)
    //         00542932     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542938     LEA        EDX,[EBX + -0x1]
    //         0054293b     PUSH       EDX
    //         0054293c     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
    //         00542941     MOV        EDI,EAX
    //                              World.cpp:1334 (9)
    //         00542943     CMP        EDI,0x1
    //         00542946     MOV        dword ptr [ESP + 0x14],EDI
    //         0054294a     JLE        LAB_005429c9
    //                              World.cpp:1336 (11)
    //         0054294c     MOV        EBP,0x1
    //         00542951     JMP        LAB_00542957
    //                               LAB_00542953                                                 XREF[1]:     005429c0(j)  
    //         00542953     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_00542957                                                 XREF[1]:     00542951(j)  
    //                              World.cpp:1338 (12)
    //         00542957     MOV        EAX,dword ptr [ESI + 0x58]
    //         0054295a     PUSH       EBP
    //         0054295b     MOV        this,dword ptr [EAX + 0x14]
    //         0054295e     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              World.cpp:1341 (29)
    //         00542963     CMP        EAX,0x2
    //         00542966     JZ         LAB_0054296d
    //         00542968     CMP        EAX,0x4
    //         0054296b     JNZ        LAB_005429bc
    //                               LAB_0054296d                                                 XREF[1]:     00542966(j)  
    //         0054296d     LEA        this,[EBP + -0x1]
    //         00542970     PUSH       this
    //         00542971     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542977     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
    //         0054297c     CMP        EAX,EDI
    //         0054297e     JNZ        LAB_005429bc
    //                              World.cpp:1343 (12)
    //         00542980     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542986     PUSH       EBX
    //         00542987     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              World.cpp:1344 (14)
    //         0054298c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542992     PUSH       EBP
    //         00542993     MOV        EDI,EAX
    //         00542995     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              World.cpp:1349 (4)
    //         0054299a     CMP        EDI,EAX
    //         0054299c     JZ         LAB_005429bc
    //                              World.cpp:1354 (17)
    //         0054299e     MOV        EDX,dword ptr [ESI + 0x40]
    //         005429a1     PUSH       0x0
    //         005429a3     SHL        EDI,0x2
    //         005429a6     PUSH       EAX=>DAT_fffffff8
    //         005429a7     MOV        this,dword ptr [EDX + EDI*0x1]
    //         005429aa     CALL       RGE_Player::set_relation                         void set_relation(RGE_Player * this, long par
    //                              World.cpp:1355 (19)
    //         005429af     MOV        EAX,dword ptr [ESI + 0x40]
    //         005429b2     PUSH       0x1
    //         005429b4     MOV        this,dword ptr [EAX + EDI*0x1]
    //         005429b7     CALL       RGE_Player::set_allied_victory                   void set_allied_victory(RGE_Player * this, uc
    //                               LAB_005429bc                                                 XREF[3]:     0054296b(j), 0054297e(j), 
    //                                                                                                         0054299c(j)  
    //         005429bc     INC        EBP
    //         005429bd     CMP        EBP,0x9
    //         005429c0     JL         LAB_00542953
    //                              World.cpp:1336 (7)
    //         005429c2     MOV        EBP,dword ptr [ESP + 0x11c]
    //                               LAB_005429c9                                                 XREF[2]:     0054292c(j), 0054294a(j)  
    //                              World.cpp:1328 (10)
    //         005429c9     INC        EBX
    //         005429ca     CMP        EBX,0x9
    //         005429cd     JL         LAB_00542918
    //                              World.cpp:1395 (38)
    //         005429d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005429d9     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
    //         005429de     TEST       EAX,EAX
    //         005429e0     JZ         LAB_00542aa2
    //         005429e6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005429ec     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
    //         005429f1     TEST       EAX,EAX
    //         005429f3     JNZ        LAB_00542aa2
    //                              World.cpp:1397 (5)
    //         005429f9     MOV        EBX,0x1
    //                               LAB_005429fe                                                 XREF[1]:     00542a95(j)  
    //                              World.cpp:1399 (12)
    //         005429fe     MOV        this,dword ptr [ESI + 0x58]
    //         00542a01     PUSH       EBX
    //         00542a02     MOV        this,dword ptr [ECX + this->old_time]
    //         00542a05     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              World.cpp:1400 (45)
    //         00542a0a     CMP        EAX,0x4
    //         00542a0d     JZ         LAB_00542a23
    //         00542a0f     MOV        EAX,[all_cp]
    //         00542a14     CMP        EAX,0x1
    //         00542a17     JZ         LAB_00542a23
    //         00542a19     CMP        EAX,0x2
    //         00542a1c     JNZ        LAB_00542a91
    //         00542a1e     CMP        EBX,0x1
    //         00542a21     JLE        LAB_00542a91
    //                               LAB_00542a23                                                 XREF[2]:     00542a0d(j), 00542a17(j)  
    //         00542a23     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542a29     LEA        EDX,[EBX + -0x1]
    //         00542a2c     PUSH       EDX
    //         00542a2d     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
    //         00542a32     CMP        EAX,0x1
    //         00542a35     JNZ        LAB_00542a91
    //                              World.cpp:1402 (2)
    //         00542a37     MOV        EBP,EAX
    //                               LAB_00542a39                                                 XREF[1]:     00542a8f(j)  
    //                              World.cpp:1404 (12)
    //         00542a39     MOV        EAX,dword ptr [ESI + 0x58]
    //         00542a3c     PUSH       EBP
    //         00542a3d     MOV        this,dword ptr [EAX + 0x14]
    //         00542a40     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              World.cpp:1405 (10)
    //         00542a45     CMP        EAX,0x4
    //         00542a48     JZ         LAB_00542a4f
    //         00542a4a     CMP        EAX,0x2
    //         00542a4d     JNZ        LAB_00542a8b
    //                               LAB_00542a4f                                                 XREF[1]:     00542a48(j)  
    //                              World.cpp:1407 (12)
    //         00542a4f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542a55     PUSH       EBX
    //         00542a56     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              World.cpp:1408 (14)
    //         00542a5b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542a61     PUSH       EBP
    //         00542a62     MOV        EDI,EAX
    //         00542a64     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              World.cpp:1410 (4)
    //         00542a69     CMP        EDI,EAX
    //         00542a6b     JZ         LAB_00542a8b
    //                              World.cpp:1412 (17)
    //         00542a6d     MOV        this,dword ptr [ESI + 0x40]
    //         00542a70     PUSH       0x1
    //         00542a72     SHL        EDI,0x2
    //         00542a75     PUSH       EAX=>DAT_fffffff8
    //         00542a76     MOV        this,dword ptr [this->_padding_ + EDI*0x1]
    //         00542a79     CALL       RGE_Player::set_relation                         void set_relation(RGE_Player * this, long par
    //                              World.cpp:1413 (19)
    //         00542a7e     MOV        EDX,dword ptr [ESI + 0x40]
    //         00542a81     PUSH       0x1
    //         00542a83     MOV        this,dword ptr [EDX + EDI*0x1]
    //         00542a86     CALL       RGE_Player::set_allied_victory                   void set_allied_victory(RGE_Player * this, uc
    //                               LAB_00542a8b                                                 XREF[2]:     00542a4d(j), 00542a6b(j)  
    //         00542a8b     INC        EBP
    //         00542a8c     CMP        EBP,0x9
    //         00542a8f     JL         LAB_00542a39
    //                               LAB_00542a91                                                 XREF[3]:     00542a1c(j), 00542a21(j), 
    //                                                                                                         00542a35(j)  
    //                              World.cpp:1397 (17)
    //         00542a91     INC        EBX
    //         00542a92     CMP        EBX,0x9
    //         00542a95     JL         LAB_005429fe
    //         00542a9b     MOV        EBP,dword ptr [ESP + 0x11c]
    //                               LAB_00542aa2                                                 XREF[2]:     005429e0(j), 005429f3(j)  
    //                              World.cpp:1423 (5)
    //         00542aa2     XOR        EDI,EDI
    //         00542aa4     MOV        dword ptr [ESI + 0x4],EDI
    //                              World.cpp:1424 (3)
    //         00542aa7     MOV        dword ptr [ESI + 0x8],EDI
    //                              World.cpp:1425 (3)
    //         00542aaa     MOV        dword ptr [ESI + 0xc],EDI
    //                              World.cpp:1426 (3)
    //         00542aad     MOV        dword ptr [ESI + 0x14],EDI
    //                              World.cpp:1428 (15)
    //         00542ab0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542ab6     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         00542abb     TEST       EAX,EAX
    //         00542abd     JZ         LAB_00542acf
    //                              World.cpp:1429 (14)
    //         00542abf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542ac5     CALL       RGE_Base_Game::get_game_speed                    float get_game_speed(RGE_Base_Game * this)
    //         00542aca     FSTP       float ptr [ESI + 0x18]
    //                              World.cpp:1430 (2)
    //         00542acd     JMP        LAB_00542ad6
    //                               LAB_00542acf                                                 XREF[1]:     00542abd(j)  
    //                              World.cpp:1431 (7)
    //         00542acf     MOV        dword ptr [ESI + 0x18],0x3f800000
    //                               LAB_00542ad6                                                 XREF[1]:     00542acd(j)  
    //                              World.cpp:1433 (4)
    //         00542ad6     MOV        byte ptr [ESI + 0x1c],0x0
    //                              World.cpp:1434 (6)
    //         00542ada     MOV        dword ptr [ESI + 0x84],EDI
    //                              World.cpp:1437 (12)
    //         00542ae0     MOV        EAX,dword ptr [EBP + 0x298]
    //         00542ae6     XOR        EBX,EBX
    //         00542ae8     CMP        EAX,EDI
    //         00542aea     JZ         LAB_00542afb
    //                              World.cpp:1438 (13)
    //         00542aec     PUSH       EBP
    //         00542aed     PUSH       EAX=>DAT_fffffff8
    //         00542aee     MOV        EAX,dword ptr [ESI]
    //         00542af0     MOV        this,ESI
    //         00542af2     CALL       dword ptr [EAX + 0x78]
    //         00542af5     MOV        byte ptr [ESP + 0x13],AL
    //                              World.cpp:1439 (8)
    //         00542af9     JMP        LAB_00542b1f
    //                               LAB_00542afb                                                 XREF[1]:     00542aea(j)  
    //         00542afb     MOV        AL,byte ptr [EBP + 0x2a8]
    //                              World.cpp:1440 (16)
    //         00542b01     PUSH       EBP
    //         00542b02     TEST       AL,AL
    //         00542b04     MOV        EAX,dword ptr [ESI]
    //         00542b06     MOV        this,ESI
    //         00542b08     JZ         LAB_00542b13
    //         00542b0a     CALL       dword ptr [EAX + 0x74]
    //         00542b0d     MOV        byte ptr [ESP + 0x13],AL
    //                              World.cpp:1441 (2)
    //         00542b11     JMP        LAB_00542b1f
    //                               LAB_00542b13                                                 XREF[1]:     00542b08(j)  
    //                              World.cpp:1443 (7)
    //         00542b13     CALL       dword ptr [EAX + 0x64]
    //         00542b16     MOV        byte ptr [ESP + 0x13],AL
    //                              World.cpp:1444 (5)
    //         00542b1a     MOV        EBX,0x1
    //                               LAB_00542b1f                                                 XREF[2]:     00542af9(j), 00542b11(j)  
    //                              World.cpp:1448 (7)
    //         00542b1f     MOV        this,ESI
    //         00542b21     CALL       RGE_Game_World::initializePathingSystem          int initializePathingSystem(RGE_Game_World * 
    //                              World.cpp:1451 (7)
    //         00542b26     CMP        word ptr [ESI + 0x3c],0x0
    //         00542b2b     JLE        LAB_00542b48
    //                               LAB_00542b2d                                                 XREF[1]:     00542b46(j)  
    //                              World.cpp:1452 (10)
    //         00542b2d     MOV        EAX,dword ptr [ESI + 0x40]
    //         00542b30     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00542b33     TEST       this,this
    //         00542b35     JZ         LAB_00542b3f
    //                              World.cpp:1453 (17)
    //         00542b37     MOV        EDX,dword ptr [this->_padding_]
    //         00542b39     CALL       dword ptr [EDX + 0x90]
    //                               LAB_00542b3f                                                 XREF[1]:     00542b35(j)  
    //         00542b3f     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         00542b43     INC        EDI
    //         00542b44     CMP        EDI,EAX
    //         00542b46     JL         LAB_00542b2d
    //                               LAB_00542b48                                                 XREF[1]:     00542b2b(j)  
    //                              World.cpp:1455 (8)
    //         00542b48     MOV        AL,byte ptr [ESP + 0x13]
    //         00542b4c     TEST       AL,AL
    //         00542b4e     JZ         LAB_00542b54
    //                              World.cpp:1456 (4)
    //         00542b50     MOV        byte ptr [ESI + 0x1d],0x0
    //                               LAB_00542b54                                                 XREF[1]:     00542b4e(j)  
    //                              World.cpp:1458 (21)
    //         00542b54     PUSH       0x5b2
    //         00542b59     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542b5e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542b63     ADD        ESP,0x8
    //         00542b66     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1459 (18)
    //         00542b69     MOV        this,dword ptr [L]                               = 00000000
    //         00542b6f     PUSH       EAX
    //         00542b70     PUSH       s___World:_end_of_new_game_(rand=%               = "  World: end_of_new_game (rand=%d)"
    //         00542b75     PUSH       this=>DAT_fffffff4
    //         00542b76     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              World.cpp:1462 (29)
    //         00542b7b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542b81     ADD        ESP,0xc
    //         00542b84     LEA        EAX,[ESP + 0x18]
    //         00542b88     MOV        EDX,dword ptr [this->_padding_]
    //         00542b8a     PUSH       0x100
    //         00542b8f     PUSH       EAX=>DAT_fffffff8
    //                              language.dll match for 0x277b: "Random"
    //         00542b90     PUSH       offset DAT_fffffff4
    //         00542b95     CALL       dword ptr [EDX + 0x20]
    //                              World.cpp:1464 (9)
    //         00542b98     MOV        EDI,0x1
    //         00542b9d     CMP        EBX,EDI
    //         00542b9f     JNZ        LAB_00542bdf
    //                              World.cpp:1466 (6)
    //         00542ba1     CMP        word ptr [ESI + 0x3c],DI
    //         00542ba5     JLE        LAB_00542bdf
    //                               LAB_00542ba7                                                 XREF[1]:     00542bdd(j)  
    //                              World.cpp:1467 (10)
    //         00542ba7     MOV        this,dword ptr [ESI + 0x40]
    //         00542baa     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         00542bad     TEST       this,this
    //         00542baf     JZ         LAB_00542bd6
    //                              World.cpp:1469 (46)
    //         00542bb1     MOV        EAX,dword ptr [ESP + 0x11c]
    //         00542bb8     MOV        EDX,dword ptr [this->_padding_]
    //         00542bba     MOVSX      EAX,word ptr [EAX + 0x2a0]
    //         00542bc1     PUSH       EAX
    //         00542bc2     LEA        EAX,[ESP + 0x1c]
    //         00542bc6     PUSH       0x0=>DAT_fffffff8
    //         00542bc8     PUSH       EAX=>DAT_fffffff4
    //         00542bc9     LEA        EAX,[ESP + 0x24]
    //         00542bcd     PUSH       EAX=>DAT_fffffff0
    //         00542bce     LEA        EAX,[ESP + 0x28]
    //         00542bd2     PUSH       EAX
    //         00542bd3     CALL       dword ptr [EDX + 0x2c]
    //                               LAB_00542bd6                                                 XREF[1]:     00542baf(j)  
    //         00542bd6     MOVSX      this,word ptr [ESI + 0x3c]
    //         00542bda     INC        EDI
    //         00542bdb     CMP        EDI,this
    //         00542bdd     JL         LAB_00542ba7
    //                               LAB_00542bdf                                                 XREF[2]:     00542b9f(j), 00542ba5(j)  
    //                              World.cpp:1472 (4)
    //         00542bdf     MOV        AL,byte ptr [ESP + 0x13]
    //                              World.cpp:1473 (13)
    //         00542be3     POP        EDI
    //         00542be4     POP        ESI
    //         00542be5     POP        EBP
    //         00542be6     POP        EBX
    //         00542be7     ADD        ESP,0x108
    //         00542bed     RET        0x8
    return 0;
}

uchar RGE_Game_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall new_scenario(RGE_Game_World * this, RGE_Player_Info
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?new_scenario@RGE_Game_World@@UAEEAAURGE_Player_Info@@H@Z    XREF[2]:     new_scenario:0053037f(c), 
    //                               RGE_Game_World::new_scenario                                              005779e4(*)  
    //                              World.cpp:1478 (5)
    //         00542bf0     PUSH       EBX
    //         00542bf1     PUSH       EBP
    //         00542bf2     PUSH       ESI
    //         00542bf3     MOV        ESI,this
    //                              World.cpp:1482 (3)
    //         00542bf5     XOR        EBX,EBX
    //         00542bf7     PUSH       EDI
    //                              World.cpp:1484 (14)
    //         00542bf8     MOV        EBP,dword ptr [ESI]
    //         00542bfa     MOV        dword ptr [world_update_counter],EBX
    //         00542c00     CALL       dword ptr [EBP + 0xb8]
    //                              World.cpp:1489 (12)
    //         00542c06     MOV        EAX,dword ptr [ESP + 0x18]
    //         00542c0a     MOV        word ptr [ESI + 0x7c],BX
    //         00542c0e     CMP        EAX,EBX
    //         00542c10     JNZ        LAB_00542c1d
    //                              World.cpp:1490 (11)
    //         00542c12     MOV        EAX,dword ptr [ESI + 0x58]
    //         00542c15     MOV        this,dword ptr [EAX + 0x14]
    //         00542c18     CALL       TCommunications_Handler::GetRandomSeed           uint GetRandomSeed(TCommunications_Handler * 
    //                               LAB_00542c1d                                                 XREF[1]:     00542c10(j)  
    //                              World.cpp:1493 (21)
    //         00542c1d     MOV        this,EAX
    //         00542c1f     MOV        dword ptr [ESI + 0x78],EAX
    //         00542c22     PUSH       this
    //         00542c23     PUSH       0x5d5
    //         00542c28     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542c2d     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              World.cpp:1496 (31)
    //         00542c32     MOV        EDI,dword ptr [ESP + 0x20]
    //         00542c36     MOV        this,dword ptr [ESI + 0x28]
    //         00542c39     ADD        ESP,0xc
    //         00542c3c     MOVSX      EDX,word ptr [EDI + 0x2a4]
    //         00542c43     MOVSX      EAX,word ptr [EDI + 0x2a2]
    //         00542c4a     PUSH       EDX
    //         00542c4b     PUSH       EAX
    //         00542c4c     CALL       RGE_Map::new_map                                 void new_map(RGE_Map * this, long param_1, lo
    //                              World.cpp:1497 (19)
    //         00542c51     MOV        this,dword ptr [EDI + 0x29c]
    //         00542c57     PUSH       0x1
    //         00542c59     MOV        DL,byte ptr [this->_padding_]
    //         00542c5b     MOV        this,dword ptr [ESI + 0x28]
    //         00542c5e     PUSH       EDX
    //         00542c5f     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, uchar param_1,
    //                              World.cpp:1500 (13)
    //         00542c64     MOV        AX,word ptr [EDI + 0x294]
    //         00542c6b     INC        AX
    //         00542c6d     MOV        word ptr [ESI + 0x3c],AX
    //                              World.cpp:1501 (14)
    //         00542c71     MOVSX      EAX,AX
    //         00542c74     PUSH       EAX
    //         00542c75     PUSH       0x4
    //         00542c77     CALL       calloc                                           undefined calloc()
    //         00542c7c     ADD        ESP,0x8
    //                              World.cpp:1504 (8)
    //         00542c7f     MOV        this,ESI
    //         00542c81     MOV        dword ptr [ESI + 0x40],EAX
    //         00542c84     CALL       dword ptr [EBP + 0x5c]
    //                              World.cpp:1507 (6)
    //         00542c87     PUSH       EDI
    //         00542c88     MOV        this,ESI
    //         00542c8a     CALL       dword ptr [EBP + 0x60]
    //                              World.cpp:1510 (3)
    //         00542c8d     MOV        dword ptr [ESI + 0x4],EBX
    //                              World.cpp:1511 (3)
    //         00542c90     MOV        dword ptr [ESI + 0x8],EBX
    //                              World.cpp:1512 (3)
    //         00542c93     MOV        dword ptr [ESI + 0xc],EBX
    //                              World.cpp:1513 (3)
    //         00542c96     MOV        dword ptr [ESI + 0x14],EBX
    //                              World.cpp:1514 (7)
    //         00542c99     MOV        dword ptr [ESI + 0x18],0x3f800000
    //                              World.cpp:1515 (3)
    //         00542ca0     MOV        byte ptr [ESI + 0x1c],BL
    //                              World.cpp:1516 (6)
    //         00542ca3     MOV        dword ptr [ESI + 0x84],EBX
    //                              World.cpp:1518 (8)
    //         00542ca9     MOV        EAX,dword ptr [EDI + 0x298]
    //         00542caf     CMP        EAX,EBX
    //                              World.cpp:1520 (13)
    //         00542cb1     PUSH       EDI
    //         00542cb2     JZ         LAB_00542cc0
    //         00542cb4     PUSH       EAX
    //         00542cb5     MOV        this,ESI
    //         00542cb7     CALL       dword ptr [EBP + 0x78]
    //         00542cba     MOV        byte ptr [ESP + 0x18],AL
    //                              World.cpp:1521 (2)
    //         00542cbe     JMP        LAB_00542cd6
    //                               LAB_00542cc0                                                 XREF[1]:     00542cb2(j)  
    //                              World.cpp:1524 (8)
    //         00542cc0     MOV        this,ESI
    //         00542cc2     CALL       dword ptr [EBP + 0xa8]
    //                              World.cpp:1525 (9)
    //         00542cc8     PUSH       ESI
    //         00542cc9     MOV        this,ESI
    //         00542ccb     CALL       dword ptr [EBP + 0xf0]
    //                              World.cpp:1526 (5)
    //         00542cd1     MOV        byte ptr [ESP + 0x18],0x1
    //                               LAB_00542cd6                                                 XREF[1]:     00542cbe(j)  
    //                              World.cpp:1529 (6)
    //         00542cd6     CMP        byte ptr [ESP + 0x18],BL
    //         00542cda     JZ         LAB_00542cf8
    //                              World.cpp:1532 (8)
    //         00542cdc     XOR        EDI,EDI
    //         00542cde     CMP        word ptr [ESI + 0x3c],BX
    //         00542ce2     JLE        LAB_00542cf8
    //                               LAB_00542ce4                                                 XREF[1]:     00542cf6(j)  
    //                              World.cpp:1533 (20)
    //         00542ce4     MOV        this,dword ptr [ESI + 0x40]
    //         00542ce7     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         00542cea     CALL       RGE_Player::set_map_visible                      void set_map_visible(RGE_Player * this)
    //         00542cef     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         00542cf3     INC        EDI
    //         00542cf4     CMP        EDI,EDX
    //         00542cf6     JL         LAB_00542ce4
    //                               LAB_00542cf8                                                 XREF[2]:     00542cda(j), 00542ce2(j)  
    //                              World.cpp:1536 (4)
    //         00542cf8     MOV        AL,byte ptr [ESP + 0x18]
    //                              World.cpp:1537 (7)
    //         00542cfc     POP        EDI
    //         00542cfd     POP        ESI
    //         00542cfe     POP        EBP
    //         00542cff     POP        EBX
    //         00542d00     RET        0x8
    //         00542d03     ??         90h
    //         00542d04     NOP
    //         00542d05     NOP
    //         00542d06     NOP
    //         00542d07     NOP
    //         00542d08     NOP
    //         00542d09     NOP
    //         00542d0a     NOP
    //         00542d0b     NOP
    //         00542d0c     NOP
    //         00542d0d     NOP
    //         00542d0e     NOP
    //         00542d0f     NOP
    return 0;
}

uchar RGE_Game_World::new_random_game(RGE_Player_Info* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall new_random_game(RGE_Game_World * this, RGE_Player_I
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[1]:     00542d11(R)  
    //                               ?new_random_game@RGE_Game_World@@MAEEAAURGE_Player_Info@@@Z  XREF[2]:     005774bc(*), 00577974(*)  
    //                               RGE_Game_World::new_random_game
    //                              World.cpp:1541 (1)
    //         00542d10     PUSH       EBX
    //                              World.cpp:1549 (28)
    //         00542d11     MOV        EBX,dword ptr [ESP + param_1]
    //         00542d15     PUSH       EBP
    //         00542d16     PUSH       ESI
    //         00542d17     MOV        ESI,this
    //         00542d19     PUSH       EDI
    //         00542d1a     PUSH       EBX
    //         00542d1b     MOV        dword ptr [world_update_counter],0x0
    //         00542d25     MOV        EDI,dword ptr [ESI]
    //         00542d27     CALL       dword ptr [EDI + 0xa8]
    //                              World.cpp:1552 (9)
    //         00542d2d     PUSH       ESI
    //         00542d2e     MOV        this,ESI
    //         00542d30     CALL       dword ptr [EDI + 0xf0]
    //                              World.cpp:1554 (21)
    //         00542d36     PUSH       0x612
    //         00542d3b     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542d40     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542d45     ADD        ESP,0x8
    //         00542d48     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1555 (17)
    //         00542d4b     PUSH       EAX
    //         00542d4c     MOV        EAX,[L]                                          = 00000000
    //         00542d51     PUSH       s___World:_before_map_gen_(rand=%d               = "  World: before_map_gen (rand=%d)"
    //         00542d56     PUSH       EAX=>DAT_fffffff4
    //         00542d57     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              World.cpp:1558 (29)
    //         00542d5c     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         00542d60     MOV        this,dword ptr [ESI + 0x28]
    //         00542d63     ADD        ESP,0xc
    //         00542d66     DEC        EAX
    //         00542d67     MOV        EDX,dword ptr [this->_padding_]
    //         00542d69     PUSH       EAX
    //         00542d6a     MOV        AL,byte ptr [EBX + 0x2a0]
    //         00542d70     PUSH       EAX=>DAT_fffffff8
    //         00542d71     PUSH       offset DAT_fffffff4
    //         00542d73     PUSH       offset DAT_fffffff0
    //         00542d75     PUSH       ESI
    //         00542d76     CALL       dword ptr [EDX + 0x28]
    //                              World.cpp:1560 (7)
    //         00542d79     MOV        this,ESI
    //         00542d7b     CALL       RGE_Game_World::initializePathingSystem          int initializePathingSystem(RGE_Game_World * 
    //                              World.cpp:1562 (21)
    //         00542d80     PUSH       0x61a
    //         00542d85     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542d8a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542d8f     ADD        ESP,0x8
    //         00542d92     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1563 (21)
    //         00542d95     MOV        this,dword ptr [L]                               = 00000000
    //         00542d9b     PUSH       EAX
    //         00542d9c     PUSH       s___World:_after_map_gen_(rand=%d)               = "  World: after_map_gen (rand=%d)"
    //         00542da1     PUSH       this=>DAT_fffffff4
    //         00542da2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00542da7     ADD        ESP,0xc
    //                              World.cpp:1570 (21)
    //         00542daa     PUSH       0x622
    //         00542daf     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542db4     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542db9     ADD        ESP,0x8
    //         00542dbc     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1571 (18)
    //         00542dbf     MOV        EDX,dword ptr [L]                                = 00000000
    //         00542dc5     PUSH       EAX
    //         00542dc6     PUSH       s___World:_after_player_random_sta               = "  World: after_player_random_start (rand=%
    //         00542dcb     PUSH       EDX=>DAT_fffffff4
    //         00542dcc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              World.cpp:1574 (7)
    //         00542dd1     MOV        BP,word ptr [ESI + 0x7c]
    //         00542dd5     ADD        ESP,0xc
    //                              World.cpp:1575 (11)
    //         00542dd8     MOV        word ptr [ESI + 0x7c],0xffff
    //         00542dde     MOV        EBX,0x3
    //                               LAB_00542de3                                                 XREF[1]:     00542e12(j)  
    //                              World.cpp:1578 (6)
    //         00542de3     MOV        this,dword ptr [world_update_counter]
    //                              World.cpp:1579 (15)
    //         00542de9     XOR        EDI,EDI
    //         00542deb     INC        this
    //         00542dec     MOV        dword ptr [world_update_counter],this
    //         00542df2     CMP        word ptr [ESI + 0x3c],DI
    //         00542df6     JLE        LAB_00542e11
    //                               LAB_00542df8                                                 XREF[1]:     00542e0f(j)  
    //                              World.cpp:1580 (13)
    //         00542df8     MOV        this,dword ptr [ESI + 0x40]
    //         00542dfb     MOVSX      EAX,DI
    //         00542dfe     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00542e01     TEST       this,this
    //         00542e03     JZ         LAB_00542e0a
    //                              World.cpp:1581 (12)
    //         00542e05     MOV        EDX,dword ptr [this->_padding_]
    //         00542e07     CALL       dword ptr [EDX + 0x7c]
    //                               LAB_00542e0a                                                 XREF[1]:     00542e03(j)  
    //         00542e0a     INC        EDI
    //         00542e0b     CMP        DI,word ptr [ESI + 0x3c]
    //         00542e0f     JL         LAB_00542df8
    //                               LAB_00542e11                                                 XREF[1]:     00542df6(j)  
    //                              World.cpp:1576 (3)
    //         00542e11     DEC        EBX
    //         00542e12     JNZ        LAB_00542de3
    //                              World.cpp:1585 (25)
    //         00542e14     PUSH       0x631
    //         00542e19     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542e1e     MOV        word ptr [ESI + 0x7c],BP
    //         00542e22     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00542e27     ADD        ESP,0x8
    //         00542e2a     MOV        dword ptr [ESI + 0x78],EAX
    //                              World.cpp:1586 (20)
    //         00542e2d     PUSH       EAX
    //         00542e2e     MOV        EAX,[L]                                          = 00000000
    //         00542e33     PUSH       s___World:_after_player_update_(ra               = "  World: after_player_update (rand=%d)"
    //         00542e38     PUSH       EAX=>DAT_fffffff4
    //         00542e39     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00542e3e     ADD        ESP,0xc
    //                              World.cpp:1588 (2)
    //         00542e41     MOV        AL,0x1
    //                              World.cpp:1589 (7)
    //         00542e43     POP        EDI
    //         00542e44     POP        ESI
    //         00542e45     POP        EBP
    //         00542e46     POP        EBX
    //         00542e47     RET        0x4
    //         00542e4a     ??         90h
    //         00542e4b     NOP
    //         00542e4c     NOP
    //         00542e4d     NOP
    //         00542e4e     NOP
    //         00542e4f     NOP
    return 0;
}

void RGE_Game_World::update_sounds(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall update_sounds(RGE_Game_World * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00542e63(R)  
    //                               ?update_sounds@RGE_Game_World@@QAEXK@Z                       XREF[1]:     update:00542f9a(c)  
    //                               RGE_Game_World::update_sounds
    //                              World.cpp:1602 (3)
    //         00542e50     PUSH       ESI
    //         00542e51     MOV        ESI,this
    //                              World.cpp:1606 (9)
    //         00542e53     MOVSX      EAX,word ptr [ESI + 0x2c]
    //         00542e57     CMP        dword ptr [ESI + 0x20],EAX
    //         00542e5a     JL         LAB_00542e63
    //                              World.cpp:1607 (7)
    //         00542e5c     MOV        dword ptr [ESI + 0x20],0x0
    //                               LAB_00542e63                                                 XREF[1]:     00542e5a(j)  
    //                              World.cpp:1609 (19)
    //         00542e63     MOV        this,dword ptr [ESP + param_1]
    //         00542e67     MOV        EDX,dword ptr [ESI + 0x20]
    //         00542e6a     MOV        EAX,dword ptr [ESI + 0x30]
    //         00542e6d     PUSH       this
    //         00542e6e     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00542e71     CALL       RGE_Sound::update                                void update(RGE_Sound * this, ulong param_1)
    //                              World.cpp:1611 (7)
    //         00542e76     MOV        EAX,dword ptr [ESI + 0x20]
    //         00542e79     INC        EAX
    //         00542e7a     MOV        dword ptr [ESI + 0x20],EAX
    //                              World.cpp:1612 (4)
    //         00542e7d     POP        ESI
    //         00542e7e     RET        0x4
    //         00542e81     ??         90h
    //         00542e82     NOP
    //         00542e83     NOP
    //         00542e84     NOP
    //         00542e85     NOP
    //         00542e86     NOP
    //         00542e87     NOP
    //         00542e88     NOP
    //         00542e89     NOP
    //         00542e8a     NOP
    //         00542e8b     NOP
    //         00542e8c     NOP
    //         00542e8d     NOP
    //         00542e8e     NOP
    //         00542e8f     NOP
    return;
}

void RGE_Game_World::update_sprites(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall update_sprites(RGE_Game_World * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00542eb0(R)  
    //                               ?update_sprites@RGE_Game_World@@QAEXK@Z                      XREF[1]:     update:00542fa2(c)  
    //                               RGE_Game_World::update_sprites
    //                              World.cpp:1617 (3)
    //         00542e90     PUSH       ESI
    //         00542e91     MOV        ESI,this
    //                              World.cpp:1621 (9)
    //         00542e93     MOVSX      EAX,word ptr [ESI + 0x34]
    //         00542e97     CMP        dword ptr [ESI + 0x24],EAX
    //         00542e9a     JL         LAB_00542ea3
    //                              World.cpp:1622 (7)
    //         00542e9c     MOV        dword ptr [ESI + 0x24],0x0
    //                               LAB_00542ea3                                                 XREF[1]:     00542e9a(j)  
    //                              World.cpp:1624 (13)
    //         00542ea3     MOV        this,dword ptr [ESI + 0x24]
    //         00542ea6     MOV        EDX,dword ptr [ESI + 0x38]
    //         00542ea9     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00542eac     TEST       this,this
    //         00542eae     JZ         LAB_00542eba
    //                              World.cpp:1625 (10)
    //         00542eb0     MOV        EAX,dword ptr [ESP + param_1]
    //         00542eb4     PUSH       EAX
    //         00542eb5     CALL       RGE_Sprite::update                               void update(RGE_Sprite * this, ulong param_1)
    //                               LAB_00542eba                                                 XREF[1]:     00542eae(j)  
    //                              World.cpp:1627 (7)
    //         00542eba     MOV        EAX,dword ptr [ESI + 0x24]
    //         00542ebd     INC        EAX
    //         00542ebe     MOV        dword ptr [ESI + 0x24],EAX
    //                              World.cpp:1628 (4)
    //         00542ec1     POP        ESI
    //         00542ec2     RET        0x4
    //         00542ec5     ??         90h
    //         00542ec6     NOP
    //         00542ec7     NOP
    //         00542ec8     NOP
    //         00542ec9     NOP
    //         00542eca     NOP
    //         00542ecb     NOP
    //         00542ecc     NOP
    //         00542ecd     NOP
    //         00542ece     NOP
    //         00542ecf     NOP
    return;
}

uchar RGE_Game_World::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Game_World * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char[256]         Stack[-0x104   fileName                  XREF[3]:     00542fe4(W), 00543007(W), 0054304e(W)  
    //                               ?update@RGE_Game_World@@UAEEXZ                               XREF[2]:     00577514(*), 005779cc(*)  
    //                               RGE_Game_World::update
    //                              World.cpp:1634 (12)
    //         00542ed0     SUB        ESP,0x108
    //         00542ed6     PUSH       EBX
    //         00542ed7     PUSH       EBP
    //         00542ed8     PUSH       ESI
    //         00542ed9     MOV        ESI,this
    //         00542edb     PUSH       EDI
    //                              World.cpp:1678 (29)
    //         00542edc     PUSH       0x68e
    //         00542ee1     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00542ee7     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542eec     XOR        BL,BL
    //         00542eee     MOV        dword ptr [ESI + 0xf8],EAX
    //         00542ef4     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              World.cpp:1679 (20)
    //         00542ef9     MOV        this,dword ptr [ESI + 0x4]
    //         00542efc     MOV        EDX,dword ptr [ESI + 0x58]
    //         00542eff     ADD        ESP,0x8
    //         00542f02     MOV        EDI,EAX
    //         00542f04     PUSH       this
    //         00542f05     MOV        this,dword ptr [EDX + 0x14]
    //         00542f08     CALL       TCommunications_Handler::DoCycle                 int DoCycle(TCommunications_Handler * this, u
    //                              World.cpp:1680 (36)
    //         00542f0d     PUSH       0x690
    //         00542f12     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542f17     MOV        EBP,EAX
    //         00542f19     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00542f1e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00542f24     ADD        ESP,0x8
    //         00542f27     SUB        EAX,EDI
    //         00542f29     PUSH       EAX
    //         00542f2a     PUSH       0xe
    //         00542f2c     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int 
    //                              World.cpp:1682 (6)
    //         00542f31     XOR        EAX,EAX
    //         00542f33     CMP        EBP,EAX
    //         00542f35     JNZ        LAB_00542f48
    //                              World.cpp:1684 (3)
    //         00542f37     MOV        dword ptr [ESI + 0xc],EAX
    //                              World.cpp:1905 (3)
    //         00542f3a     MOV        AL,byte ptr [ESI + 0x1d]
    //                              World.cpp:1906 (11)
    //         00542f3d     POP        EDI
    //         00542f3e     POP        ESI
    //         00542f3f     POP        EBP
    //         00542f40     POP        EBX
    //         00542f41     ADD        ESP,0x108
    //         00542f47     RET
    //                               LAB_00542f48                                                 XREF[1]:     00542f35(j)  
    //                              World.cpp:1691 (17)
    //         00542f48     MOV        this,0x1
    //         00542f4d     MOV        [visible_combats],AX
    //         00542f53     MOV        dword ptr [debug_random_on],this
    //                              World.cpp:1692 (6)
    //         00542f59     MOV        dword ptr [debug_timeGetTime_on],this
    //                              World.cpp:1694 (8)
    //         00542f5f     CMP        dword ptr [do_fixed_update],EAX
    //         00542f65     JZ         LAB_00542f6d
    //                              World.cpp:1695 (6)
    //         00542f67     MOV        EBP,dword ptr [fixed_update_time]                = 64h
    //                               LAB_00542f6d                                                 XREF[1]:     00542f65(j)  
    //                              World.cpp:1698 (22)
    //         00542f6d     MOV        EAX,dword ptr [ESI + 0x78]
    //         00542f70     PUSH       EAX
    //         00542f71     PUSH       0x6a2
    //         00542f76     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542f7b     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //         00542f80     ADD        ESP,0xc
    //                              World.cpp:1700 (20)
    //         00542f83     PUSH       0x6a4
    //         00542f88     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00542f8d     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00542f92     ADD        ESP,0x8
    //         00542f95     MOV        EDI,EAX
    //                              World.cpp:1701 (8)
    //         00542f97     MOV        this,ESI
    //         00542f99     PUSH       EDI
    //         00542f9a     CALL       RGE_Game_World::update_sounds                    void update_sounds(RGE_Game_World * this, ulo
    //                              World.cpp:1702 (8)
    //         00542f9f     PUSH       EDI
    //         00542fa0     MOV        this,ESI
    //         00542fa2     CALL       RGE_Game_World::update_sprites                   void update_sprites(RGE_Game_World * this, ul
    //                              World.cpp:1704 (5)
    //         00542fa7     CMP        EBP,-0x1
    //         00542faa     JNZ        LAB_00542fc9
    //                              World.cpp:1706 (7)
    //         00542fac     MOV        this,dword ptr [ESI + 0x14]
    //         00542faf     TEST       this,this
    //         00542fb1     JNZ        LAB_00542fb9
    //                              World.cpp:1708 (2)
    //         00542fb3     MOV        BL,0x1
    //                              World.cpp:1709 (2)
    //         00542fb5     XOR        EAX,EAX
    //                              World.cpp:1711 (2)
    //         00542fb7     JMP        LAB_00542fbd
    //                               LAB_00542fb9                                                 XREF[1]:     00542fb1(j)  
    //                              World.cpp:1712 (4)
    //         00542fb9     MOV        EAX,EDI
    //         00542fbb     SUB        EAX,this
    //                               LAB_00542fbd                                                 XREF[1]:     00542fb7(j)  
    //                              World.cpp:1714 (5)
    //         00542fbd     CMP        EAX,0x64
    //         00542fc0     JBE        LAB_00542fcb
    //                              World.cpp:1715 (5)
    //         00542fc2     MOV        EAX,0x64
    //                              World.cpp:1717 (2)
    //         00542fc7     JMP        LAB_00542fcb
    //                               LAB_00542fc9                                                 XREF[1]:     00542faa(j)  
    //                              World.cpp:1718 (2)
    //         00542fc9     MOV        EAX,EBP
    //                               LAB_00542fcb                                                 XREF[2]:     00542fc0(j), 00542fc7(j)  
    //                              World.cpp:1725 (16)
    //         00542fcb     MOV        this,byte ptr [ESI + 0x1c]
    //         00542fce     MOV        dword ptr [ESI + 0x14],EDI
    //         00542fd1     MOV        EDI,dword ptr [ESI + 0x4]
    //         00542fd4     TEST       this,this
    //         00542fd6     MOV        dword ptr [ESI + 0x8],EDI
    //         00542fd9     JZ         LAB_00543003
    //                              World.cpp:1728 (5)
    //         00542fdb     CMP        EBP,-0x1
    //         00542fde     JZ         LAB_00542ffd
    //                              World.cpp:1729 (29)
    //         00542fe0     MOV        dword ptr [ESP + Stack[-0x108]],EAX
    //         00542fe4     MOV        dword ptr [ESP + fileName[0]],0x0
    //         00542fec     FILD       qword ptr [ESP + Stack[-0x108]]
    //         00542ff0     FMUL       float ptr [ESI + 0x18]
    //         00542ff3     CALL       __ftol                                           undefined __ftol()
    //         00542ff8     ADD        EAX,EDI
    //         00542ffa     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_00542ffd                                                 XREF[1]:     00542fde(j)  
    //                              World.cpp:1730 (4)
    //         00542ffd     MOV        byte ptr [ESI + 0x1c],0x0
    //                              World.cpp:1732 (2)
    //         00543001     JMP        LAB_00543020
    //                               LAB_00543003                                                 XREF[1]:     00542fd9(j)  
    //                              World.cpp:1733 (29)
    //         00543003     MOV        dword ptr [ESP + Stack[-0x108]],EAX
    //         00543007     MOV        dword ptr [ESP + fileName[0]],0x0
    //         0054300f     FILD       qword ptr [ESP + Stack[-0x108]]
    //         00543013     FMUL       float ptr [ESI + 0x18]
    //         00543016     CALL       __ftol                                           undefined __ftol()
    //         0054301b     ADD        EAX,EDI
    //         0054301d     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_00543020                                                 XREF[1]:     00543001(j)  
    //                              World.cpp:1735 (11)
    //         00543020     MOV        EAX,dword ptr [ESI + 0x4]
    //         00543023     MOV        this,dword ptr [ESI + 0x8]
    //         00543026     SUB        EAX,this
    //         00543028     MOV        dword ptr [ESI + 0xc],EAX
    //                              World.cpp:1737 (10)
    //         0054302b     JNZ        LAB_00543035
    //         0054302d     TEST       BL,BL
    //         0054302f     JZ         LAB_00543163
    //                               LAB_00543035                                                 XREF[1]:     0054302b(j)  
    //                              World.cpp:1739 (8)
    //         00543035     MOV        this,dword ptr [ESI + 0x58]
    //         00543038     CALL       RGE_Command::do_commands                         void do_commands(RGE_Command * this)
    //                              World.cpp:1740 (8)
    //         0054303d     MOV        this,dword ptr [ESI + 0x5c]
    //         00543040     CALL       RGE_Scenario::update                             void update(RGE_Scenario * this)
    //                              World.cpp:1741 (17)
    //         00543045     MOV        this,dword ptr [ESI + 0xc]
    //         00543048     XOR        EBX,EBX
    //         0054304a     MOV        dword ptr [ESP + Stack[-0x108]],this
    //         0054304e     MOV        dword ptr [ESP + fileName[0]],EBX
    //         00543052     FILD       qword ptr [ESP + Stack[-0x108]]
    //                              World.cpp:1747 (33)
    //         00543056     XOR        EBP,EBP
    //         00543058     FMUL       float ptr [DAT_00577a14]                         = 6Fh    o
    //         0054305e     FSTP       float ptr [ESI + 0x84]
    //         00543064     MOV        this,dword ptr [world_update_counter]
    //         0054306a     INC        this
    //         0054306b     MOV        dword ptr [world_update_counter],this
    //         00543071     CMP        word ptr [ESI + 0x3c],BX
    //         00543075     JLE        LAB_005430b3
    //                              World.cpp:1739 (6)
    //         00543077     LEA        EDI,[ESI + 0xb4]
    //                               LAB_0054307d                                                 XREF[1]:     005430b1(j)  
    //                              World.cpp:1748 (8)
    //         0054307d     MOV        EDX,dword ptr [ESI + 0x40]
    //         00543080     CMP        dword ptr [EDX + EBP*0x4],EBX
    //         00543083     JZ         LAB_005430a7
    //                              World.cpp:1750 (9)
    //         00543085     MOV        EAX,dword ptr [ESI + 0xc]
    //         00543088     MOV        this,dword ptr [EDI]
    //         0054308a     ADD        this,EAX
    //         0054308c     MOV        dword ptr [EDI],this
    //                              World.cpp:1752 (11)
    //         0054308e     MOV        this,dword ptr [ESI + 0x40]
    //         00543091     MOV        this,dword ptr [this->_padding_ + EBP*0x4]
    //         00543094     MOV        EDX,dword ptr [this->_padding_]
    //         00543096     CALL       dword ptr [EDX + 0x7c]
    //                              World.cpp:1754 (26)
    //         00543099     MOV        EAX,dword ptr [ESI + 0x40]
    //         0054309c     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0054309f     ADD        this,0x58
    //         005430a2     CALL       RGE_Tile_List::del_list                          void del_list(RGE_Tile_List * this)
    //                               LAB_005430a7                                                 XREF[1]:     00543083(j)  
    //         005430a7     MOVSX      this,word ptr [ESI + 0x3c]
    //         005430ab     INC        EBP
    //         005430ac     ADD        EDI,0x4
    //         005430af     CMP        EBP,this
    //         005430b1     JL         LAB_0054307d
    //                               LAB_005430b3                                                 XREF[1]:     00543075(j)  
    //                              World.cpp:1759 (10)
    //         005430b3     MOV        this,dword ptr [MouseSystem]                     = 00000000
    //         005430b9     CMP        this,EBX
    //         005430bb     JZ         LAB_005430c2
    //                              World.cpp:1760 (5)
    //         005430bd     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
    //                               LAB_005430c2                                                 XREF[1]:     005430bb(j)  
    //                              World.cpp:1762 (18)
    //         005430c2     PUSH       0x6e2
    //         005430c7     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         005430cc     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         005430d1     ADD        ESP,0x8
    //                              World.cpp:1766 (10)
    //         005430d4     XOR        EDI,EDI
    //         005430d6     CMP        word ptr [ESI + 0x3c],BX
    //         005430da     MOV        EBP,EAX
    //         005430dc     JLE        LAB_005430f9
    //                               LAB_005430de                                                 XREF[1]:     005430f7(j)  
    //                              World.cpp:1767 (10)
    //         005430de     MOV        EDX,dword ptr [ESI + 0x40]
    //         005430e1     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         005430e4     CMP        EAX,EBX
    //         005430e6     JZ         LAB_005430f0
    //                              World.cpp:1770 (17)
    //         005430e8     MOV        this,dword ptr [EAX + 0x30]
    //         005430eb     CALL       RGE_Object_List::update                          void update(RGE_Object_List * this)
    //                               LAB_005430f0                                                 XREF[1]:     005430e6(j)  
    //         005430f0     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005430f4     INC        EDI
    //         005430f5     CMP        EDI,EAX
    //         005430f7     JL         LAB_005430de
    //                               LAB_005430f9                                                 XREF[1]:     005430dc(j)  
    //                              World.cpp:1775 (8)
    //         005430f9     XOR        EDI,EDI
    //         005430fb     CMP        word ptr [ESI + 0x3c],BX
    //         005430ff     JLE        LAB_0054311c
    //                               LAB_00543101                                                 XREF[1]:     0054311a(j)  
    //                              World.cpp:1776 (10)
    //         00543101     MOV        this,dword ptr [ESI + 0x40]
    //         00543104     MOV        EAX,dword ptr [this->_padding_ + EDI*0x4]
    //         00543107     CMP        EAX,EBX
    //         00543109     JZ         LAB_00543113
    //                              World.cpp:1778 (17)
    //         0054310b     MOV        this,dword ptr [EAX + 0x40]
    //         0054310e     CALL       RGE_Doppleganger_Creator::perform_doppleganger   void perform_doppleganger_checks(RGE_Dopplega
    //                               LAB_00543113                                                 XREF[1]:     00543109(j)  
    //         00543113     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         00543117     INC        EDI
    //         00543118     CMP        EDI,EDX
    //         0054311a     JL         LAB_00543101
    //                               LAB_0054311c                                                 XREF[1]:     005430ff(j)  
    //                              World.cpp:1782 (16)
    //         0054311c     PUSH       EBP
    //         0054311d     PUSH       offset DAT_fffffff8
    //         00543122     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         00543127     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              World.cpp:1810 (16)
    //         0054312c     MOV        EAX,dword ptr [ESI + 0xb0]
    //         00543132     ADD        ESP,0xc
    //         00543135     MOV        dword ptr [ESI + EAX*0x4 + 0xb4],EBX
    //                              World.cpp:1811 (6)
    //         0054313c     MOV        EDI,dword ptr [ESI + 0xb0]
    //                              World.cpp:1812 (17)
    //         00543142     MOVSX      this,word ptr [ESI + 0x3c]
    //         00543146     INC        EDI
    //         00543147     MOV        EAX,EDI
    //         00543149     MOV        dword ptr [ESI + 0xb0],EDI
    //         0054314f     CMP        EAX,this
    //         00543151     JL         LAB_00543159
    //                              World.cpp:1813 (6)
    //         00543153     MOV        dword ptr [ESI + 0xb0],EBX
    //                               LAB_00543159                                                 XREF[1]:     00543151(j)  
    //                              World.cpp:1815 (10)
    //         00543159     MOV        EDX,dword ptr [ESI]
    //         0054315b     MOV        this,ESI
    //         0054315d     CALL       dword ptr [EDX + 0xc4]
    //                               LAB_00543163                                                 XREF[1]:     0054302f(j)  
    //                              World.cpp:1818 (15)
    //         00543163     PUSH       0x71a
    //         00543168     PUSH       s_C:\msdev\work\age1_x1\World.cpp                = "C:\\msdev\\work\\age1_x1\\World.cpp"
    //         0054316d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //                              World.cpp:1821 (11)
    //         00543172     XOR        EBX,EBX
    //         00543174     MOV        dword ptr [ESI + 0x78],EAX
    //         00543177     MOV        dword ptr [debug_random_on],EBX
    //                              World.cpp:1822 (6)
    //         0054317d     MOV        dword ptr [debug_timeGetTime_on],EBX
    //                              World.cpp:1825 (18)
    //         00543183     MOV        this,dword ptr [ESI + 0x58]
    //         00543186     MOV        EAX,dword ptr [ESI + 0x78]
    //         00543189     ADD        ESP,0x8
    //         0054318c     MOV        this,dword ptr [ECX + this->old_time]
    //         0054318f     PUSH       EAX
    //         00543190     CALL       TCommunications_Handler::LastWorldRandom         void LastWorldRandom(TCommunications_Handler 
    //                              World.cpp:1832 (54)
    //         00543195     MOV        EAX,[logStatusOn]
    //         0054319a     MOV        EDI,0x1
    //         0054319f     CMP        EAX,EDI
    //         005431a1     JNZ        LAB_005432e7
    //         005431a7     CMP        byte ptr [ESI + 0x1d],0x1
    //         005431ab     JZ         LAB_005432ed
    //         005431b1     MOV        EDX,dword ptr [ESI + 0x4]
    //         005431b4     MOV        EAX,[lastStatusLogTime]
    //         005431b9     SUB        EDX,EAX
    //         005431bb     CMP        EDX,0x7530
    //         005431c1     JA         LAB_005431cb
    //         005431c3     CMP        EAX,EBX
    //         005431c5     JNZ        LAB_005432e7
    //                               LAB_005431cb                                                 XREF[1]:     005431c1(j)  
    //                              World.cpp:1836 (10)
    //         005431cb     MOV        EBX,dword ptr [logStatusFile]                    = 00000000
    //         005431d1     TEST       EBX,EBX
    //         005431d3     JNZ        LAB_00543217
    //                              World.cpp:1838 (32)
    //         005431d5     MOV        EAX,[rge_base_game]                              = 00000000
    //         005431da     MOV        this,dword ptr [EAX + 0x4]
    //         005431dd     CALL       RGE_Game_Info::get_current_player_name           char * get_current_player_name(RGE_Game_Info 
    //         005431e2     PUSH       EAX
    //         005431e3     LEA        this,[ESP + 0x1c]
    //         005431e7     PUSH       s_AILog\%s.log                                   = "AILog\\%s.log"
    //         005431ec     PUSH       this
    //         005431ed     CALL       sprintf                                          undefined sprintf()
    //         005431f2     ADD        ESP,0xc
    //                              World.cpp:1839 (20)
    //         005431f5     LEA        EDX,[ESP + 0x18]
    //         005431f9     PUSH       s_a                                              = "a"
    //         005431fe     PUSH       EDX
    //         005431ff     CALL       fopen                                            undefined fopen()
    //         00543204     MOV        EBX,EAX
    //         00543206     ADD        ESP,0x8
    //                              World.cpp:1840 (8)
    //         00543209     TEST       EBX,EBX
    //         0054320b     MOV        dword ptr [logStatusFile],EBX                    = 00000000
    //                              World.cpp:1841 (6)
    //         00543211     JZ         LAB_00543368
    //                               LAB_00543217                                                 XREF[1]:     005431d3(j)  
    //                              World.cpp:1844 (5)
    //         00543217     MOV        EAX,0x10624dd3
    //                              World.cpp:1845 (7)
    //         0054321c     XOR        this,this
    //         0054321e     MUL        dword ptr [ESI + 0x4]
    //         00543221     MOV        EDI,EDX
    //                              World.cpp:1846 (5)
    //         00543223     XOR        EBP,EBP
    //         00543225     SHR        EDI,0x6
    //                              World.cpp:1847 (5)
    //         00543228     CMP        EDI,0x3b
    //         0054322b     JLE        LAB_00543272
    //                              World.cpp:1849 (21)
    //         0054322d     MOV        EAX,0x88888889
    //         00543232     IMUL       EDI
    //         00543234     MOV        this,EDX
    //         00543236     ADD        this,EDI
    //         00543238     SAR        this,0x5
    //         0054323b     MOV        EAX,this
    //         0054323d     SHR        EAX,0x1f
    //         00543240     ADD        this,EAX
    //                              World.cpp:1850 (9)
    //         00543242     MOV        EDX,this
    //         00543244     SHL        EDX,0x4
    //         00543247     SUB        EDX,this
    //         00543249     NEG        EDX
    //                              World.cpp:1851 (8)
    //         0054324b     CMP        this,0x3b
    //         0054324e     LEA        EDI,[EDI + EDX*0x4]
    //         00543251     JLE        LAB_00543272
    //                              World.cpp:1853 (21)
    //         00543253     MOV        EAX,0x88888889
    //         00543258     IMUL       this
    //         0054325a     ADD        EDX,this
    //         0054325c     SAR        EDX,0x5
    //         0054325f     MOV        EAX,EDX
    //         00543261     SHR        EAX,0x1f
    //         00543264     ADD        EDX,EAX
    //         00543266     MOV        EBP,EDX
    //                              World.cpp:1854 (10)
    //         00543268     SHL        EDX,0x4
    //         0054326b     SUB        EDX,EBP
    //         0054326d     NEG        EDX
    //         0054326f     LEA        this,[this->_padding_ + EDX*0x4]
    //                               LAB_00543272                                                 XREF[2]:     0054322b(j), 00543251(j)  
    //                              World.cpp:1858 (9)
    //         00543272     MOV        EAX,[lastStatusLogTime]
    //         00543277     TEST       EAX,EAX
    //         00543279     JNZ        LAB_0054328a
    //                              World.cpp:1859 (13)
    //         0054327b     MOV        EAX,dword ptr [ESI]
    //         0054327d     PUSH       0x1
    //         0054327f     PUSH       EBX
    //         00543280     MOV        this,ESI
    //         00543282     CALL       dword ptr [EAX + 0x9c]
    //                              World.cpp:1860 (2)
    //         00543288     JMP        LAB_0054329b
    //                               LAB_0054328a                                                 XREF[1]:     00543279(j)  
    //                              World.cpp:1861 (17)
    //         0054328a     PUSH       EDI
    //         0054328b     PUSH       this
    //         0054328c     PUSH       EBP
    //         0054328d     PUSH       s__Status_Log_at_GameTime_%02ld:%0               = "\nStatus Log at GameTime %02ld:%02ld:%02ld
    //         00543292     PUSH       EBX
    //         00543293     CALL       fprintf                                          undefined fprintf()
    //         00543298     ADD        ESP,0x14
    //                               LAB_0054329b                                                 XREF[1]:     00543288(j)  
    //                              World.cpp:1864 (11)
    //         0054329b     MOV        EDI,0x1
    //         005432a0     CMP        word ptr [ESI + 0x3c],DI
    //         005432a4     JLE        LAB_005432d6
    //                               LAB_005432a6                                                 XREF[1]:     005432d4(j)  
    //                              World.cpp:1866 (10)
    //         005432a6     MOV        this,dword ptr [ESI + 0x40]
    //         005432a9     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         005432ac     TEST       this,this
    //         005432ae     JZ         LAB_005432cd
    //                              World.cpp:1869 (5)
    //         005432b0     MOV        EAX,[lastStatusLogTime]
    //                              World.cpp:1870 (8)
    //         005432b5     MOV        EDX,dword ptr [this->_padding_]
    //         005432b7     TEST       EAX,EAX
    //         005432b9     JNZ        LAB_005432bf
    //         005432bb     PUSH       0x1
    //                              World.cpp:1871 (2)
    //         005432bd     JMP        LAB_005432c1
    //                               LAB_005432bf                                                 XREF[1]:     005432b9(j)  
    //                              World.cpp:1872 (23)
    //         005432bf     PUSH       0x0
    //                               LAB_005432c1                                                 XREF[1]:     005432bd(j)  
    //         005432c1     MOV        EAX,[logStatusFile]                              = 00000000
    //         005432c6     PUSH       EAX=>DAT_fffffff8
    //         005432c7     CALL       dword ptr [EDX + 0xec]
    //                               LAB_005432cd                                                 XREF[1]:     005432ae(j)  
    //         005432cd     MOVSX      this,word ptr [ESI + 0x3c]
    //         005432d1     INC        EDI
    //         005432d2     CMP        EDI,this
    //         005432d4     JL         LAB_005432a6
    //                               LAB_005432d6                                                 XREF[1]:     005432a4(j)  
    //                              World.cpp:1878 (17)
    //         005432d6     MOV        EDX,dword ptr [ESI + 0x4]
    //         005432d9     MOV        EDI,0x1
    //         005432de     INC        EDX
    //         005432df     XOR        EBX,EBX
    //         005432e1     MOV        dword ptr [lastStatusLogTime],EDX
    //                               LAB_005432e7                                                 XREF[2]:     005431a1(j), 005431c5(j)  
    //                              World.cpp:1882 (23)
    //         005432e7     CMP        byte ptr [ESI + 0x1d],0x1
    //         005432eb     JNZ        LAB_00543368
    //                               LAB_005432ed                                                 XREF[1]:     005431ab(j)  
    //         005432ed     CMP        dword ptr [logStatusOn],EDI
    //         005432f3     JNZ        LAB_00543368
    //         005432f5     MOV        EAX,[logStatusFile]                              = 00000000
    //         005432fa     CMP        EAX,EBX
    //         005432fc     JZ         LAB_00543368
    //                              World.cpp:1884 (14)
    //         005432fe     PUSH       s_GAME_OVER!_                                    = "GAME OVER!\n"
    //         00543303     PUSH       EAX=>DAT_fffffff8
    //         00543304     CALL       fprintf                                          undefined fprintf()
    //         00543309     ADD        ESP,0x8
    //                              World.cpp:1885 (6)
    //         0054330c     CMP        word ptr [ESI + 0x3c],DI
    //         00543310     JLE        LAB_00543353
    //                               LAB_00543312                                                 XREF[1]:     00543351(j)  
    //                              World.cpp:1887 (10)
    //         00543312     MOV        EAX,dword ptr [ESI + 0x40]
    //         00543315     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         00543318     CMP        EAX,EBX
    //         0054331a     JZ         LAB_0054334a
    //                              World.cpp:1890 (6)
    //         0054331c     MOV        this,byte ptr [EAX + 0x80]
    //                              World.cpp:1891 (18)
    //         00543322     PUSH       EDI
    //         00543323     CMP        this,0x1
    //         00543326     JNZ        LAB_00543336
    //         00543328     MOV        this,dword ptr [logStatusFile]                   = 00000000
    //         0054332e     PUSH       s___Player_#%d_Won._                             = "  Player #%d Won.\n"
    //         00543333     PUSH       this=>DAT_fffffff4
    //                              World.cpp:1892 (2)
    //         00543334     JMP        LAB_00543342
    //                               LAB_00543336                                                 XREF[1]:     00543326(j)  
    //                              World.cpp:1893 (29)
    //         00543336     MOV        EDX,dword ptr [logStatusFile]                    = 00000000
    //         0054333c     PUSH       s___Player_#%d_Lost._                            = "  Player #%d Lost.\n"
    //         00543341     PUSH       EDX=>DAT_fffffff4
    //                               LAB_00543342                                                 XREF[1]:     00543334(j)  
    //         00543342     CALL       fprintf                                          undefined fprintf()
    //         00543347     ADD        ESP,0xc
    //                               LAB_0054334a                                                 XREF[1]:     0054331a(j)  
    //         0054334a     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         0054334e     INC        EDI
    //         0054334f     CMP        EDI,EAX
    //         00543351     JL         LAB_00543312
    //                               LAB_00543353                                                 XREF[1]:     00543310(j)  
    //                              World.cpp:1896 (15)
    //         00543353     MOV        this,dword ptr [logStatusFile]                   = 00000000
    //         00543359     PUSH       this
    //         0054335a     CALL       fclose                                           undefined fclose()
    //         0054335f     ADD        ESP,0x4
    //                              World.cpp:1897 (6)
    //         00543362     MOV        dword ptr [logStatusFile],EBX                    = 00000000
    //                               LAB_00543368                                                 XREF[4]:     00543211(j), 005432eb(j), 
    //                                                                                                         005432f3(j), 005432fc(j)  
    //                              World.cpp:1905 (3)
    //         00543368     MOV        AL,byte ptr [ESI + 0x1d]
    //                              World.cpp:1906 (11)
    //         0054336b     POP        EDI
    //         0054336c     POP        ESI
    //         0054336d     POP        EBP
    //         0054336e     POP        EBX
    //         0054336f     ADD        ESP,0x108
    //         00543375     RET
    //         00543376     ??         90h
    //         00543377     NOP
    //         00543378     NOP
    //         00543379     NOP
    //         0054337a     NOP
    //         0054337b     NOP
    //         0054337c     NOP
    //         0054337d     NOP
    //         0054337e     NOP
    //         0054337f     NOP
    return 0;
}

int RGE_Game_World::is_player_turn(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall is_player_turn(RGE_Game_World * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00543386(R)  
    //                               ?is_player_turn@RGE_Game_World@@QAEHH@Z                      XREF[1]:     update:004307d4(c)  
    //                               RGE_Game_World::is_player_turn
    //                              World.cpp:1911 (17)
    //         00543380     MOV        this,dword ptr [ECX + this->player_turn]
    //         00543386     MOV        EDX,dword ptr [ESP + param_1]
    //         0054338a     XOR        EAX,EAX
    //         0054338c     CMP        this,EDX
    //         0054338e     SETZ       AL
    //                              World.cpp:1913 (3)
    //         00543391     RET        0x4
    //         00543394     ??         90h
    //         00543395     NOP
    //         00543396     NOP
    //         00543397     NOP
    //         00543398     NOP
    //         00543399     NOP
    //         0054339a     NOP
    //         0054339b     NOP
    //         0054339c     NOP
    //         0054339d     NOP
    //         0054339e     NOP
    //         0054339f     NOP
    return 0;
}

ulong RGE_Game_World::get_accum_time_delta(int param_1) {
    /* TODO: Stub */
    //                              ulong __thiscall get_accum_time_delta(RGE_Game_World * this, int par
    //              ulong             EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005433a0(R)  
    //                               ?get_accum_time_delta@RGE_Game_World@@QAEKH@Z                XREF[1]:     update:004307e8(c)  
    //                               RGE_Game_World::get_accum_time_delta
    //                              World.cpp:1918 (11)
    //         005433a0     MOV        EAX,dword ptr [ESP + param_1]
    //         005433a4     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->player_ti
    //                              World.cpp:1920 (3)
    //         005433ab     RET        0x4
    //         005433ae     ??         90h
    //         005433af     NOP
    return 0;
}

uchar RGE_Game_World::get_game_state() {
    /* TODO: Stub */
    //                              uchar __thiscall get_game_state(RGE_Game_World * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?get_game_state@RGE_Game_World@@UAEEXZ                       XREF[2]:     00577518(*), 005779d0(*)  
    //                               RGE_Game_World::get_game_state
    //                              World.cpp:1925 (3)
    //         005433b0     MOV        AL,byte ptr [ECX + this->game_state]
    //                              World.cpp:1927 (1)
    //         005433b3     RET
    //         005433b4     ??         90h
    //         005433b5     NOP
    //         005433b6     NOP
    //         005433b7     NOP
    //         005433b8     NOP
    //         005433b9     NOP
    //         005433ba     NOP
    //         005433bb     NOP
    //         005433bc     NOP
    //         005433bd     NOP
    //         005433be     NOP
    //         005433bf     NOP
    return 0;
}

uchar RGE_Game_World::check_game_state() {
    /* TODO: Stub */
    //                              uchar __thiscall check_game_state(RGE_Game_World * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     005433d6(W), 0054340b(R), 00543412(W), 005434a3(R)  
    //              long              Stack[-0x8]:4  games_on                  XREF[3]:     005433de(W), 005433ff(RW), 00543497(R)  
    //              long              Stack[-0xc]:4  games_lost                XREF[3]:     005433da(W), 00543405(RW), 0054345e(R)  
    //              long              Stack[-0x10]:4 games_won
    //                               ?check_game_state@RGE_Game_World@@UAEEXZ                     XREF[2]:     check_game_state:00530a55(c), 
    //                               RGE_Game_World::check_game_state                                          005779d4(*)  
    //                              World.cpp:1932 (9)
    //         005433c0     SUB        ESP,0xc
    //         005433c3     PUSH       EBX
    //         005433c4     PUSH       EBP
    //         005433c5     PUSH       ESI
    //         005433c6     PUSH       EDI
    //         005433c7     MOV        ESI,this
    //                              World.cpp:1942 (27)
    //         005433c9     MOV        EDI,0x1
    //         005433ce     XOR        EBX,EBX
    //         005433d0     XOR        EBP,EBP
    //         005433d2     CMP        word ptr [ESI + 0x3c],DI
    //         005433d6     MOV        dword ptr [ESP + local_4],EBX
    //         005433da     MOV        dword ptr [ESP + games_lost],EBX
    //         005433de     MOV        dword ptr [ESP + games_on],EBX
    //         005433e2     JLE        LAB_0054345e
    //                               LAB_005433e4                                                 XREF[1]:     0054345c(j)  
    //                              World.cpp:1943 (27)
    //         005433e4     MOV        EAX,dword ptr [ESI + 0x40]
    //         005433e7     MOV        this,dword ptr [EAX + EDI*0x4]
    //         005433ea     CALL       RGE_Player::check_victory                        uchar check_victory(RGE_Player * this)
    //         005433ef     AND        EAX,0xff
    //         005433f4     SUB        EAX,0x0
    //         005433f7     JZ         LAB_0054340b
    //         005433f9     DEC        EAX
    //         005433fa     JZ         LAB_00543405
    //         005433fc     DEC        EAX
    //         005433fd     JNZ        LAB_00543455
    //                              World.cpp:1971 (4)
    //         005433ff     INC        dword ptr [ESP + games_on]
    //                              World.cpp:1974 (2)
    //         00543403     JMP        LAB_00543455
    //                               LAB_00543405                                                 XREF[1]:     005433fa(j)  
    //                              World.cpp:1968 (4)
    //         00543405     INC        dword ptr [ESP + games_lost]
    //                              World.cpp:1969 (2)
    //         00543409     JMP        LAB_00543455
    //                               LAB_0054340b                                                 XREF[1]:     005433f7(j)  
    //                              World.cpp:1948 (5)
    //         0054340b     MOV        this,dword ptr [ESP + local_4]
    //         0054340f     INC        this
    //                              World.cpp:1949 (12)
    //         00543410     TEST       EBP,EBP
    //         00543412     MOV        dword ptr [ESP + local_4],this
    //         00543416     JLE        LAB_0054344e
    //         00543418     TEST       EBX,EBX
    //         0054341a     JZ         LAB_0054344e
    //                              World.cpp:1955 (45)
    //         0054341c     MOV        EAX,dword ptr [ESI + 0x40]
    //         0054341f     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00543422     MOV        DL,byte ptr [ECX + this+0x104]
    //         00543428     TEST       DL,DL
    //         0054342a     JZ         LAB_00543449
    //         0054342c     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0054342f     PUSH       EDI
    //         00543430     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //         00543435     TEST       AL,AL
    //         00543437     JNZ        LAB_00543449
    //         00543439     MOV        EDX,dword ptr [ESI + 0x40]
    //         0054343c     PUSH       EBP
    //         0054343d     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00543440     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //         00543445     TEST       AL,AL
    //         00543447     JZ         LAB_00543455
    //                               LAB_00543449                                                 XREF[2]:     0054342a(j), 00543437(j)  
    //                              World.cpp:1956 (3)
    //         00543449     OR         EBX,0xffffffff
    //                              World.cpp:1959 (2)
    //         0054344c     JMP        LAB_00543455
    //                               LAB_0054344e                                                 XREF[2]:     00543416(j), 0054341a(j)  
    //                              World.cpp:1962 (2)
    //         0054344e     MOV        EBP,EDI
    //                              World.cpp:1963 (14)
    //         00543450     MOV        EBX,0x1
    //                               LAB_00543455                                                 XREF[5]:     005433fd(j), 00543403(j), 
    //                                                                                                         00543409(j), 00543447(j), 
    //                                                                                                         0054344c(j)  
    //         00543455     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         00543459     INC        EDI
    //         0054345a     CMP        EDI,EAX
    //         0054345c     JL         LAB_005433e4
    //                               LAB_0054345e                                                 XREF[1]:     005433e2(j)  
    //                              World.cpp:1979 (8)
    //         0054345e     MOV        EAX,dword ptr [ESP + games_lost]
    //         00543462     TEST       EAX,EAX
    //         00543464     JLE        LAB_0054348b
    //                              World.cpp:1982 (15)
    //         00543466     MOV        EDI,0x1
    //         0054346b     MOV        byte ptr [ESI + 0x1d],0x1
    //         0054346f     CMP        word ptr [ESI + 0x3c],DI
    //         00543473     JLE        LAB_005434d2
    //                               LAB_00543475                                                 XREF[1]:     00543487(j)  
    //                              World.cpp:1983 (20)
    //         00543475     MOV        this,dword ptr [ESI + 0x40]
    //         00543478     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         0054347b     CALL       RGE_Player::loss_if_game_on                      void loss_if_game_on(RGE_Player * this)
    //         00543480     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         00543484     INC        EDI
    //         00543485     CMP        EDI,EDX
    //         00543487     JL         LAB_00543475
    //                              World.cpp:1987 (34)
    //         00543489     JMP        LAB_005434d2
    //                               LAB_0054348b                                                 XREF[1]:     00543464(j)  
    //         0054348b     MOV        this,dword ptr [ESI + 0x5c]
    //         0054348e     CALL       RGE_Scenario::Get_conquest_victory               uchar Get_conquest_victory(RGE_Scenario * this)
    //         00543493     TEST       AL,AL
    //         00543495     JZ         LAB_005434d2
    //         00543497     MOV        EAX,dword ptr [ESP + games_on]
    //         0054349b     TEST       EAX,EAX
    //         0054349d     JLE        LAB_005434a3
    //         0054349f     TEST       EBX,EBX
    //         005434a1     JG         LAB_005434ab
    //                               LAB_005434a3                                                 XREF[1]:     0054349d(j)  
    //         005434a3     MOV        EAX,dword ptr [ESP + local_4]
    //         005434a7     TEST       EAX,EAX
    //         005434a9     JNZ        LAB_005434d2
    //                               LAB_005434ab                                                 XREF[1]:     005434a1(j)  
    //                              World.cpp:1990 (15)
    //         005434ab     MOV        EDI,0x1
    //         005434b0     MOV        byte ptr [ESI + 0x1d],0x1
    //         005434b4     CMP        word ptr [ESI + 0x3c],DI
    //         005434b8     JLE        LAB_005434ce
    //                               LAB_005434ba                                                 XREF[1]:     005434cc(j)  
    //                              World.cpp:1991 (20)
    //         005434ba     MOV        EAX,dword ptr [ESI + 0x40]
    //         005434bd     MOV        this,dword ptr [EAX + EDI*0x4]
    //         005434c0     CALL       RGE_Player::victory_if_game_on                   void victory_if_game_on(RGE_Player * this)
    //         005434c5     MOVSX      this,word ptr [ESI + 0x3c]
    //         005434c9     INC        EDI
    //         005434ca     CMP        EDI,this
    //         005434cc     JL         LAB_005434ba
    //                               LAB_005434ce                                                 XREF[1]:     005434b8(j)  
    //                              World.cpp:1992 (4)
    //         005434ce     MOV        byte ptr [ESI + 0x1e],0x1
    //                               LAB_005434d2                                                 XREF[4]:     00543473(j), 00543489(j), 
    //                                                                                                         00543495(j), 005434a9(j)  
    //                              World.cpp:1995 (6)
    //         005434d2     CMP        byte ptr [ESI + 0x1d],0x1
    //         005434d6     JNZ        LAB_00543533
    //                              World.cpp:1996 (10)
    //         005434d8     MOV        EAX,dword ptr [ESI + 0xa4]
    //         005434de     TEST       EAX,EAX
    //         005434e0     JL         LAB_00543533
    //                              World.cpp:1998 (30)
    //         005434e2     MOV        EDX,dword ptr [ESI + 0xac]
    //         005434e8     MOV        this,dword ptr [ESI + 0xa8]
    //         005434ee     PUSH       EDX
    //         005434ef     PUSH       this
    //         005434f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005434f6     PUSH       EAX
    //         005434f7     CALL       RGE_Base_Game::set_campaign_info                 uchar set_campaign_info(RGE_Base_Game * this,
    //         005434fc     TEST       AL,AL
    //         005434fe     JZ         LAB_00543529
    //                              World.cpp:2000 (19)
    //         00543500     MOVSX      EDX,word ptr [ESI + 0x7c]
    //         00543504     MOV        EAX,dword ptr [ESI + 0x40]
    //         00543507     MOV        this,dword ptr [EAX + EDX*0x4]
    //         0054350a     CMP        byte ptr [ECX + this->sound_driver],0x1
    //         00543511     JNZ        LAB_00543533
    //                              World.cpp:2001 (11)
    //         00543513     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00543519     CALL       RGE_Base_Game::set_campaign_win                  void set_campaign_win(RGE_Base_Game * this)
    //                              World.cpp:2007 (3)
    //         0054351e     MOV        AL,byte ptr [ESI + 0x1d]
    //                              World.cpp:2008 (8)
    //         00543521     POP        EDI
    //         00543522     POP        ESI
    //         00543523     POP        EBP
    //         00543524     POP        EBX
    //         00543525     ADD        ESP,0xc
    //         00543528     RET
    //                               LAB_00543529                                                 XREF[1]:     005434fe(j)  
    //                              World.cpp:2004 (10)
    //         00543529     MOV        dword ptr [ESI + 0xa4],0xffffffff
    //                               LAB_00543533                                                 XREF[3]:     005434d6(j), 005434e0(j), 
    //                                                                                                         00543511(j)  
    //                              World.cpp:2007 (3)
    //         00543533     MOV        AL,byte ptr [ESI + 0x1d]
    //                              World.cpp:2008 (8)
    //         00543536     POP        EDI
    //         00543537     POP        ESI
    //         00543538     POP        EBP
    //         00543539     POP        EBX
    //         0054353a     ADD        ESP,0xc
    //         0054353d     RET
    //         0054353e     ??         90h
    //         0054353f     NOP
    return 0;
}

void RGE_Game_World::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     00543551(R), 00543676(W), 00543687(R), 00543692(W)  
    //                               ?save@RGE_Game_World@@MAEXH@Z                                XREF[2]:     save:0052e799(c), 00577978(*)  
    //                               RGE_Game_World::save
    //                              World.cpp:2012 (4)
    //         00543540     PUSH       EBX
    //         00543541     PUSH       EBP
    //         00543542     PUSH       ESI
    //         00543543     PUSH       EDI
    //                              World.cpp:2015 (13)
    //         00543544     PUSH       0x1
    //         00543546     PUSH       0x24
    //         00543548     MOV        EDI,this
    //         0054354a     PUSH       0x24
    //         0054354c     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2018 (32)
    //         00543551     MOV        ESI,dword ptr [ESP + param_1]
    //         00543555     ADD        ESP,0xc
    //         00543558     LEA        EAX,[EDI + 0x4]
    //         0054355b     MOV        dword ptr [save_game_version],0x40e75c29         = 7.23
    //         00543565     PUSH       0x4
    //         00543567     PUSH       EAX
    //         00543568     PUSH       ESI
    //         00543569     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054356e     ADD        ESP,0xc
    //                              World.cpp:2019 (15)
    //         00543571     LEA        this,[EDI + 0x8]
    //         00543574     PUSH       0x4
    //         00543576     PUSH       this
    //         00543577     PUSH       ESI
    //         00543578     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054357d     ADD        ESP,0xc
    //                              World.cpp:2020 (15)
    //         00543580     LEA        EDX,[EDI + 0xc]
    //         00543583     PUSH       0x4
    //         00543585     PUSH       EDX
    //         00543586     PUSH       ESI
    //         00543587     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054358c     ADD        ESP,0xc
    //                              World.cpp:2021 (18)
    //         0054358f     LEA        EAX,[EDI + 0x84]
    //         00543595     PUSH       0x4
    //         00543597     PUSH       EAX
    //         00543598     PUSH       ESI
    //         00543599     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054359e     ADD        ESP,0xc
    //                              World.cpp:2022 (15)
    //         005435a1     LEA        this,[EDI + 0x10]
    //         005435a4     PUSH       0x4
    //         005435a6     PUSH       this
    //         005435a7     PUSH       ESI
    //         005435a8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435ad     ADD        ESP,0xc
    //                              World.cpp:2023 (15)
    //         005435b0     LEA        EDX,[EDI + 0x18]
    //         005435b3     PUSH       0x4
    //         005435b5     PUSH       EDX
    //         005435b6     PUSH       ESI
    //         005435b7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435bc     ADD        ESP,0xc
    //                              World.cpp:2024 (15)
    //         005435bf     LEA        EAX,[EDI + 0x1c]
    //         005435c2     PUSH       0x1
    //         005435c4     PUSH       EAX
    //         005435c5     PUSH       ESI
    //         005435c6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435cb     ADD        ESP,0xc
    //                              World.cpp:2025 (15)
    //         005435ce     LEA        this,[EDI + 0x68]
    //         005435d1     PUSH       0x4
    //         005435d3     PUSH       this
    //         005435d4     PUSH       ESI
    //         005435d5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435da     ADD        ESP,0xc
    //                              World.cpp:2026 (15)
    //         005435dd     LEA        EDX,[EDI + 0x6c]
    //         005435e0     PUSH       0x4
    //         005435e2     PUSH       EDX
    //         005435e3     PUSH       ESI
    //         005435e4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435e9     ADD        ESP,0xc
    //                              World.cpp:2027 (15)
    //         005435ec     LEA        EAX,[EDI + 0x78]
    //         005435ef     PUSH       0x4
    //         005435f1     PUSH       EAX
    //         005435f2     PUSH       ESI
    //         005435f3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005435f8     ADD        ESP,0xc
    //                              World.cpp:2028 (15)
    //         005435fb     LEA        this,[EDI + 0x7c]
    //         005435fe     PUSH       0x2
    //         00543600     PUSH       this
    //         00543601     PUSH       ESI
    //         00543602     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543607     ADD        ESP,0xc
    //                              World.cpp:2029 (15)
    //         0054360a     LEA        EBP,[EDI + 0x3c]
    //         0054360d     PUSH       0x2
    //         0054360f     PUSH       EBP
    //         00543610     PUSH       ESI
    //         00543611     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543616     ADD        ESP,0xc
    //                              World.cpp:2030 (15)
    //         00543619     LEA        EDX,[EDI + 0x1d]
    //         0054361c     PUSH       0x1
    //         0054361e     PUSH       EDX
    //         0054361f     PUSH       ESI
    //         00543620     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543625     ADD        ESP,0xc
    //                              World.cpp:2031 (18)
    //         00543628     LEA        EAX,[EDI + 0xa4]
    //         0054362e     PUSH       0x4
    //         00543630     PUSH       EAX
    //         00543631     PUSH       ESI
    //         00543632     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543637     ADD        ESP,0xc
    //                              World.cpp:2032 (18)
    //         0054363a     LEA        this,[EDI + 0xa8]
    //         00543640     PUSH       0x4
    //         00543642     PUSH       this
    //         00543643     PUSH       ESI
    //         00543644     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543649     ADD        ESP,0xc
    //                              World.cpp:2033 (18)
    //         0054364c     LEA        EDX,[EDI + 0xac]
    //         00543652     PUSH       0x4
    //         00543654     PUSH       EDX
    //         00543655     PUSH       ESI
    //         00543656     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054365b     ADD        ESP,0xc
    //                              World.cpp:2035 (32)
    //         0054365e     LEA        EAX,[EDI + 0xb0]
    //         00543664     PUSH       0x4
    //         00543666     PUSH       EAX
    //         00543667     PUSH       ESI
    //         00543668     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0054366d     ADD        ESP,0xc
    //         00543670     LEA        EBX,[EDI + 0xb4]
    //         00543676     MOV        dword ptr [ESP + param_1],0x9
    //                               LAB_0054367e                                                 XREF[1]:     00543696(j)  
    //                              World.cpp:2037 (26)
    //         0054367e     PUSH       0x4
    //         00543680     PUSH       EBX
    //         00543681     PUSH       ESI
    //         00543682     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543687     MOV        EAX,dword ptr [ESP + param_1]
    //         0054368b     ADD        ESP,0xc
    //         0054368e     ADD        EBX,0x4
    //         00543691     DEC        EAX
    //         00543692     MOV        dword ptr [ESP + param_1],EAX
    //         00543696     JNZ        LAB_0054367e
    //                              World.cpp:2039 (9)
    //         00543698     MOV        this,dword ptr [EDI + 0x28]
    //         0054369b     PUSH       ESI
    //         0054369c     CALL       RGE_Map::save_map                                void save_map(RGE_Map * this, int param_1)
    //                              World.cpp:2041 (8)
    //         005436a1     XOR        EBX,EBX
    //         005436a3     CMP        word ptr [EBP],BX
    //         005436a7     JLE        LAB_005436ec
    //                               LAB_005436a9                                                 XREF[1]:     005436ea(j)  
    //                              World.cpp:2043 (11)
    //         005436a9     PUSH       0x1
    //         005436ab     PUSH       offset DAT_fffffff8
    //         005436ad     PUSH       offset DAT_fffffff4
    //         005436af     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2045 (18)
    //         005436b4     MOV        this,dword ptr [EDI + 0x40]
    //         005436b7     ADD        ESP,0xc
    //         005436ba     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
    //         005436bd     PUSH       ESI
    //         005436be     MOV        EDX,dword ptr [this->_padding_]
    //         005436c0     CALL       dword ptr [EDX + 0x84]
    //                              World.cpp:2047 (11)
    //         005436c6     PUSH       0x1
    //         005436c8     PUSH       offset DAT_fffffff8
    //         005436ca     PUSH       offset DAT_fffffff4
    //         005436cc     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2049 (27)
    //         005436d1     MOV        EAX,dword ptr [EDI + 0x40]
    //         005436d4     ADD        ESP,0xc
    //         005436d7     MOV        this,dword ptr [EAX + EBX*0x4]
    //         005436da     PUSH       ESI
    //         005436db     MOV        EDX,dword ptr [this->_padding_]
    //         005436dd     CALL       dword ptr [EDX + 0x88]
    //         005436e3     MOVSX      EAX,word ptr [EBP]
    //         005436e7     INC        EBX
    //         005436e8     CMP        EBX,EAX
    //         005436ea     JL         LAB_005436a9
    //                               LAB_005436ec                                                 XREF[1]:     005436a7(j)  
    //                              World.cpp:2052 (11)
    //         005436ec     PUSH       0x1
    //         005436ee     PUSH       offset DAT_fffffff8
    //         005436f0     PUSH       offset DAT_fffffff4
    //         005436f2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2054 (11)
    //         005436f7     XOR        EBX,EBX
    //         005436f9     ADD        ESP,0xc
    //         005436fc     CMP        word ptr [EBP],BX
    //         00543700     JLE        LAB_0054371a
    //                               LAB_00543702                                                 XREF[1]:     00543718(j)  
    //                              World.cpp:2055 (24)
    //         00543702     MOV        this,dword ptr [EDI + 0x40]
    //         00543705     PUSH       ESI
    //         00543706     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
    //         00543709     MOV        EDX,dword ptr [this->_padding_]
    //         0054370b     CALL       dword ptr [EDX + 0x8c]
    //         00543711     MOVSX      EAX,word ptr [EBP]
    //         00543715     INC        EBX
    //         00543716     CMP        EBX,EAX
    //         00543718     JL         LAB_00543702
    //                               LAB_0054371a                                                 XREF[1]:     00543700(j)  
    //                              World.cpp:2057 (11)
    //         0054371a     PUSH       0x1
    //         0054371c     PUSH       offset DAT_fffffff8
    //         0054371e     PUSH       offset DAT_fffffff4
    //         00543720     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2059 (12)
    //         00543725     MOV        this,dword ptr [EDI + 0x5c]
    //         00543728     ADD        ESP,0xc
    //         0054372b     MOV        EDX,dword ptr [this->_padding_]
    //         0054372d     PUSH       ESI
    //         0054372e     CALL       dword ptr [EDX + 0xc]
    //                              World.cpp:2061 (11)
    //         00543731     PUSH       0x1
    //         00543733     PUSH       offset DAT_fffffff8
    //         00543735     PUSH       offset DAT_fffffff4
    //         00543737     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              World.cpp:2064 (20)
    //         0054373c     MOV        EAX,dword ptr [EDI + 0x100]
    //         00543742     ADD        EDI,0x100
    //         00543748     ADD        ESP,0xc
    //         0054374b     CMP        EAX,-0x1
    //         0054374e     JNZ        LAB_0054375d
    //                              World.cpp:2065 (13)
    //         00543750     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00543756     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         0054375b     MOV        dword ptr [EDI],EAX
    //                               LAB_0054375d                                                 XREF[1]:     0054374e(j)  
    //                              World.cpp:2066 (12)
    //         0054375d     PUSH       0x4
    //         0054375f     PUSH       EDI=>DAT_fffffff8
    //         00543760     PUSH       ESI=>DAT_fffffff4
    //         00543761     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543766     ADD        ESP,0xc
    //                              World.cpp:2068 (7)
    //         00543769     POP        EDI
    //         0054376a     POP        ESI
    //         0054376b     POP        EBP
    //         0054376c     POP        EBX
    //         0054376d     RET        0x4
    return;
}

uchar RGE_Game_World::save_game(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall save_game(RGE_Game_World * this, char * param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00543776(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[0,2]:   00543792(*), 005437ae(*)  
    //                               ?save_game@RGE_Game_World@@UAEEPAD@Z                         XREF[2]:     00577530(*), 005779e8(*)  
    //                               RGE_Game_World::save_game
    //                              World.cpp:2072 (6)
    //         00543770     SUB        ESP,0x12c
    //                              World.cpp:2078 (56)
    //         00543776     MOV        EAX,dword ptr [ESP + param_1]
    //         0054377d     MOV        dword ptr [save_game_version],0x40e75c29         = 7.23
    //         00543787     PUSH       ESI
    //         00543788     PUSH       EDI
    //         00543789     MOV        EDI,this
    //         0054378b     PUSH       EAX
    //         0054378c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00543792     LEA        EAX=>tempname[4],[ESP + 0xc]
    //         00543796     MOV        EDX,dword ptr [ECX + this->world_time_delta]
    //         00543799     ADD        EDX,0xb12
    //         0054379f     PUSH       EDX
    //         005437a0     PUSH       s_%s%s                                           = "%s%s"
    //         005437a5     PUSH       EAX
    //         005437a6     CALL       sprintf                                          undefined sprintf()
    //         005437ab     ADD        ESP,0x10
    //                              World.cpp:2080 (30)
    //         005437ae     LEA        this=>tempname[4],[ESP + 0x8]
    //         005437b2     PUSH       0x180
    //         005437b7     PUSH       0x8309
    //         005437bc     PUSH       this
    //         005437bd     CALL       rge_open                                         int rge_open(char * param_1, int param_2, int
    //         005437c2     MOV        ESI,EAX
    //         005437c4     ADD        ESP,0xc
    //         005437c7     CMP        ESI,-0x1
    //         005437ca     JZ         LAB_00543837
    //                              World.cpp:2087 (26)
    //         005437cc     PUSH       0x8
    //         005437ce     PUSH       s_VER_8.6                                        = 56h
    //         005437d3     PUSH       ESI
    //         005437d4     MOV        dword ptr [rge_write_error],0x0
    //         005437de     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005437e3     ADD        ESP,0xc
    //                              World.cpp:2090 (13)
    //         005437e6     PUSH       0x4
    //         005437e8     PUSH       save_game_version                                = 7.23
    //         005437ed     PUSH       ESI
    //         005437ee     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2092 (11)
    //         005437f3     MOV        EDX,dword ptr [EDI]
    //         005437f5     ADD        ESP,0xc
    //         005437f8     MOV        this,EDI
    //         005437fa     PUSH       ESI
    //         005437fb     CALL       dword ptr [EDX + 0x68]
    //                              World.cpp:2093 (6)
    //         005437fe     PUSH       ESI
    //         005437ff     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2095 (12)
    //         00543804     MOV        EAX,[rge_write_error]
    //         00543809     ADD        ESP,0x4
    //         0054380c     TEST       EAX,EAX
    //         0054380e     JZ         LAB_0054382a
    //                              World.cpp:2097 (13)
    //         00543810     LEA        EAX,[ESP + 0x8]
    //         00543814     PUSH       EAX
    //         00543815     CALL       __unlink                                         undefined __unlink()
    //         0054381a     ADD        ESP,0x4
    //                              World.cpp:2103 (2)
    //         0054381d     XOR        AL,AL
    //                              World.cpp:2104 (11)
    //         0054381f     POP        EDI
    //         00543820     POP        ESI
    //         00543821     ADD        ESP,0x12c
    //         00543827     RET        0x4
    //                               LAB_0054382a                                                 XREF[1]:     0054380e(j)  
    //                              World.cpp:2101 (2)
    //         0054382a     MOV        AL,0x1
    //                              World.cpp:2104 (24)
    //         0054382c     POP        EDI
    //         0054382d     POP        ESI
    //         0054382e     ADD        ESP,0x12c
    //         00543834     RET        0x4
    //                               LAB_00543837                                                 XREF[1]:     005437ca(j)  
    //         00543837     POP        EDI
    //         00543838     XOR        AL,AL
    //         0054383a     POP        ESI
    //         0054383b     ADD        ESP,0x12c
    //         00543841     RET        0x4
    //         00543844     ??         90h
    //         00543845     NOP
    //         00543846     NOP
    //         00543847     NOP
    //         00543848     NOP
    //         00543849     NOP
    //         0054384a     NOP
    //         0054384b     NOP
    //         0054384c     NOP
    //         0054384d     NOP
    //         0054384e     NOP
    //         0054384f     NOP
    return 0;
}

void RGE_Game_World::base_save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall base_save(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00543854(R)  
    //                               ?base_save@RGE_Game_World@@UAEXH@Z                           XREF[2]:     base_save:0052e779(c), 
    //                               RGE_Game_World::base_save                                                 005779f0(*)  
    //                              World.cpp:2108 (4)
    //         00543850     PUSH       EBX
    //         00543851     PUSH       EBP
    //         00543852     PUSH       ESI
    //         00543853     PUSH       EDI
    //                              World.cpp:2111 (22)
    //         00543854     MOV        EDI,dword ptr [ESP + param_1]
    //         00543858     PUSH       0x8
    //         0054385a     PUSH       s_VER_3.7                                        = 56h
    //         0054385f     MOV        ESI,this
    //         00543861     PUSH       EDI
    //         00543862     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543867     ADD        ESP,0xc
    //                              World.cpp:2114 (15)
    //         0054386a     LEA        EBP,[ESI + 0x50]
    //         0054386d     PUSH       0x2
    //         0054386f     PUSH       EBP
    //         00543870     PUSH       EDI
    //         00543871     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543876     ADD        ESP,0xc
    //                              World.cpp:2115 (12)
    //         00543879     LEA        EBX,[ESI + 0x52]
    //         0054387c     PUSH       0x2
    //         0054387e     PUSH       EBX
    //         0054387f     PUSH       EDI
    //         00543880     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2116 (18)
    //         00543885     MOV        AX,word ptr [EBP]
    //         00543889     ADD        ESP,0xc
    //         0054388c     TEST       AX,AX
    //         0054388f     JLE        LAB_005438d8
    //         00543891     CMP        word ptr [EBX],0x0
    //         00543895     JLE        LAB_005438d8
    //                              World.cpp:2118 (17)
    //         00543897     MOV        this,dword ptr [ESI + 0x54]
    //         0054389a     MOVSX      EAX,AX
    //         0054389d     SHL        EAX,0x2
    //         005438a0     PUSH       EAX
    //         005438a1     PUSH       this
    //         005438a2     PUSH       EDI
    //         005438a3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2119 (11)
    //         005438a8     XOR        EBX,EBX
    //         005438aa     ADD        ESP,0xc
    //         005438ad     CMP        word ptr [EBP],BX
    //         005438b1     JLE        LAB_005438d8
    //                               LAB_005438b3                                                 XREF[1]:     005438d6(j)  
    //                              World.cpp:2120 (10)
    //         005438b3     MOV        EDX,dword ptr [ESI + 0x54]
    //         005438b6     MOV        EAX,dword ptr [EDX + EBX*0x4]
    //         005438b9     TEST       EAX,EAX
    //         005438bb     JZ         LAB_005438cf
    //                              World.cpp:2121 (27)
    //         005438bd     MOVSX      this,word ptr [ESI + 0x52]
    //         005438c1     SHL        this,0x2
    //         005438c4     PUSH       this
    //         005438c5     PUSH       EAX
    //         005438c6     PUSH       EDI
    //         005438c7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         005438cc     ADD        ESP,0xc
    //                               LAB_005438cf                                                 XREF[1]:     005438bb(j)  
    //         005438cf     MOVSX      EDX,word ptr [EBP]
    //         005438d3     INC        EBX
    //         005438d4     CMP        EBX,EDX
    //         005438d6     JL         LAB_005438b3
    //                               LAB_005438d8                                                 XREF[3]:     0054388f(j), 00543895(j), 
    //                                                                                                         005438b1(j)  
    //                              World.cpp:2125 (12)
    //         005438d8     LEA        EBP,[ESI + 0x60]
    //         005438db     PUSH       0x2
    //         005438dd     PUSH       EBP
    //         005438de     PUSH       EDI
    //         005438df     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2126 (11)
    //         005438e4     XOR        EBX,EBX
    //         005438e6     ADD        ESP,0xc
    //         005438e9     CMP        word ptr [EBP],BX
    //         005438ed     JLE        LAB_00543904
    //                               LAB_005438ef                                                 XREF[1]:     00543902(j)  
    //                              World.cpp:2127 (21)
    //         005438ef     MOV        EAX,dword ptr [ESI + 0x64]
    //         005438f2     PUSH       EDI
    //         005438f3     MOV        this,dword ptr [EAX + EBX*0x4]
    //         005438f6     CALL       RGE_Color_Table::save                            void save(RGE_Color_Table * this, int param_1)
    //         005438fb     MOVSX      this,word ptr [EBP]
    //         005438ff     INC        EBX
    //         00543900     CMP        EBX,this
    //         00543902     JL         LAB_005438ef
    //                               LAB_00543904                                                 XREF[1]:     005438ed(j)  
    //                              World.cpp:2130 (12)
    //         00543904     LEA        EBP,[ESI + 0x2c]
    //         00543907     PUSH       0x2
    //         00543909     PUSH       EBP
    //         0054390a     PUSH       EDI
    //         0054390b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2131 (11)
    //         00543910     XOR        EBX,EBX
    //         00543912     ADD        ESP,0xc
    //         00543915     CMP        word ptr [EBP],BX
    //         00543919     JLE        LAB_00543930
    //                               LAB_0054391b                                                 XREF[1]:     0054392e(j)  
    //                              World.cpp:2132 (21)
    //         0054391b     MOV        EDX,dword ptr [ESI + 0x30]
    //         0054391e     PUSH       EDI
    //         0054391f     MOV        this,dword ptr [EDX + EBX*0x4]
    //         00543922     CALL       RGE_Sound::save                                  void save(RGE_Sound * this, int param_1)
    //         00543927     MOVSX      EAX,word ptr [EBP]
    //         0054392b     INC        EBX
    //         0054392c     CMP        EBX,EAX
    //         0054392e     JL         LAB_0054391b
    //                               LAB_00543930                                                 XREF[1]:     00543919(j)  
    //                              World.cpp:2135 (12)
    //         00543930     LEA        EBP,[ESI + 0x34]
    //         00543933     PUSH       0x2
    //         00543935     PUSH       EBP
    //         00543936     PUSH       EDI
    //         00543937     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2136 (21)
    //         0054393c     MOVSX      this,word ptr [EBP]
    //         00543940     MOV        EDX,dword ptr [ESI + 0x38]
    //         00543943     ADD        ESP,0xc
    //         00543946     SHL        this,0x2
    //         00543949     PUSH       this
    //         0054394a     PUSH       EDX
    //         0054394b     PUSH       EDI
    //         0054394c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2137 (11)
    //         00543951     XOR        EBX,EBX
    //         00543953     ADD        ESP,0xc
    //         00543956     CMP        word ptr [EBP],BX
    //         0054395a     JLE        LAB_00543975
    //                               LAB_0054395c                                                 XREF[1]:     00543973(j)  
    //                              World.cpp:2138 (10)
    //         0054395c     MOV        EAX,dword ptr [ESI + 0x38]
    //         0054395f     MOV        this,dword ptr [EAX + EBX*0x4]
    //         00543962     TEST       this,this
    //         00543964     JZ         LAB_0054396c
    //                              World.cpp:2139 (15)
    //         00543966     PUSH       EDI
    //         00543967     CALL       RGE_Sprite::save                                 void save(RGE_Sprite * this, int param_1)
    //                               LAB_0054396c                                                 XREF[1]:     00543964(j)  
    //         0054396c     MOVSX      this,word ptr [EBP]
    //         00543970     INC        EBX
    //         00543971     CMP        EBX,this
    //         00543973     JL         LAB_0054395c
    //                               LAB_00543975                                                 XREF[1]:     0054395a(j)  
    //                              World.cpp:2142 (9)
    //         00543975     MOV        this,dword ptr [ESI + 0x28]
    //         00543978     PUSH       EDI
    //         00543979     MOV        EDX,dword ptr [this->_padding_]
    //         0054397b     CALL       dword ptr [EDX + 0x2c]
    //                              World.cpp:2145 (9)
    //         0054397e     MOV        this,dword ptr [ESI + 0x4c]
    //         00543981     PUSH       EDI
    //         00543982     MOV        EAX,dword ptr [this->_padding_]
    //         00543984     CALL       dword ptr [EAX + 0x4]
    //                              World.cpp:2148 (12)
    //         00543987     LEA        EBP,[ESI + 0x44]
    //         0054398a     PUSH       0x2
    //         0054398c     PUSH       EBP=>DAT_fffffff8
    //         0054398d     PUSH       EDI=>DAT_fffffff4
    //         0054398e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2149 (11)
    //         00543993     XOR        EBX,EBX
    //         00543995     ADD        ESP,0xc
    //         00543998     CMP        word ptr [EBP],BX
    //         0054399c     JLE        LAB_005439b3
    //                               LAB_0054399e                                                 XREF[1]:     005439b1(j)  
    //                              World.cpp:2150 (21)
    //         0054399e     MOV        this,dword ptr [ESI + 0x48]
    //         005439a1     PUSH       EDI
    //         005439a2     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
    //         005439a5     MOV        EDX,dword ptr [this->_padding_]
    //         005439a7     CALL       dword ptr [EDX + 0x14]
    //         005439aa     MOVSX      EAX,word ptr [EBP]
    //         005439ae     INC        EBX
    //         005439af     CMP        EBX,EAX
    //         005439b1     JL         LAB_0054399e
    //                               LAB_005439b3                                                 XREF[1]:     0054399c(j)  
    //                              World.cpp:2152 (7)
    //         005439b3     POP        EDI
    //         005439b4     POP        ESI
    //         005439b5     POP        EBP
    //         005439b6     POP        EBX
    //         005439b7     RET        0x4
    //         005439ba     ??         90h
    //         005439bb     NOP
    //         005439bc     NOP
    //         005439bd     NOP
    //         005439be     NOP
    //         005439bf     NOP
    return;
}

void RGE_Game_World::base_save(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall base_save(RGE_Game_World * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     005439c0(R)  
    //                               ?base_save@RGE_Game_World@@UAEXPAD@Z                         XREF[2]:     00577534(*), 005779ec(*)  
    //                               RGE_Game_World::base_save
    //                              World.cpp:2156 (34)
    //         005439c0     MOV        EAX,dword ptr [ESP + param_1]
    //         005439c4     PUSH       ESI
    //         005439c5     PUSH       EDI
    //         005439c6     PUSH       0x180
    //         005439cb     PUSH       0x8309
    //         005439d0     MOV        EDI,this
    //         005439d2     PUSH       EAX
    //         005439d3     CALL       rge_open                                         int rge_open(char * param_1, int param_2, int
    //         005439d8     MOV        ESI,EAX
    //         005439da     ADD        ESP,0xc
    //         005439dd     CMP        ESI,-0x1
    //         005439e0     JZ         LAB_005439f6
    //                              World.cpp:2162 (11)
    //         005439e2     MOV        EDX,dword ptr [EDI]
    //         005439e4     PUSH       ESI
    //         005439e5     MOV        this,EDI
    //         005439e7     CALL       dword ptr [EDX + 0xe0]
    //                              World.cpp:2163 (9)
    //         005439ed     PUSH       ESI
    //         005439ee     CALL       rge_close                                        int rge_close(int param_1)
    //         005439f3     ADD        ESP,0x4
    //                               LAB_005439f6                                                 XREF[1]:     005439e0(j)  
    //                              World.cpp:2165 (5)
    //         005439f6     POP        EDI
    //         005439f7     POP        ESI
    //         005439f8     RET        0x4
    //         005439fb     ??         90h
    //         005439fc     NOP
    //         005439fd     NOP
    //         005439fe     NOP
    //         005439ff     NOP
    return;
}

uchar RGE_Game_World::save_scenario(char* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall save_scenario(RGE_Game_World * this, char * param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00543a0f(R)  
    //              char[300]         Stack[-0x130   kill_name                 XREF[0,3]:   00543a16(*), 00543a44(*), 00543a3c(*)  
    //              char[300]         Stack[-0x25c   scenario_name             XREF[1,4]:   00543a1d(W), 00543a54(*), 00543a67(*), 00543a79(*), 
    //                                                                                     00543a96(*)  
    //              long              Stack[-0x260   scenario_player_num
    //              long              Stack[-0x264   index
    //              long              Stack[-0x268   count
    //              float             Stack[-0x26c   obj_angle
    //                               ?save_scenario@RGE_Game_World@@UAEEPAD@Z                     XREF[2]:     0057753c(*), 005779f4(*)  
    //                               RGE_Game_World::save_scenario
    //                              World.cpp:2186 (11)
    //         00543a00     SUB        ESP,0x268
    //         00543a06     PUSH       EBP
    //         00543a07     MOV        EBP,this
    //         00543a09     PUSH       ESI
    //         00543a0a     PUSH       EDI
    //                              World.cpp:2189 (4)
    //         00543a0b     MOVSX      EAX,word ptr [EBP + 0x3c]
    //                              World.cpp:2200 (7)
    //         00543a0f     MOV        EDI,dword ptr [ESP + param_1]
    //                              World.cpp:2203 (32)
    //         00543a16     LEA        EDX=>kill_name[4],[ESP + 0x148]
    //         00543a1d     MOV        dword ptr [ESP + scenario_name[0]],EAX
    //         00543a21     XOR        ESI,ESI
    //         00543a23     MOV        this,byte ptr [EDI]
    //         00543a25     MOV        EAX,EDI
    //         00543a27     SUB        EDX,EDI
    //                               LAB_00543a29                                                 XREF[1]:     00543a34(j)  
    //         00543a29     MOV        byte ptr [EDX + EAX*0x1],this
    //         00543a2c     MOV        this,byte ptr [EAX + 0x1]
    //         00543a2f     INC        ESI
    //         00543a30     INC        EAX
    //         00543a31     CMP        this,0x2e
    //         00543a34     JNZ        LAB_00543a29
    //                              World.cpp:2206 (49)
    //         00543a36     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         00543a3c     MOV        byte ptr [ESP + ESI*0x1 + kill_name[5]],0x0
    //         00543a44     LEA        this=>kill_name[4],[ESP + 0x148]
    //         00543a4b     MOV        EAX,dword ptr [EDX + 0xc]
    //         00543a4e     PUSH       this
    //         00543a4f     ADD        EAX,0xc17
    //         00543a54     LEA        this=>scenario_name[4],[ESP + 0x20]
    //         00543a58     PUSH       EAX
    //         00543a59     PUSH       s_%s%s.scn                                       = "%s%s.scn"
    //         00543a5e     PUSH       this
    //         00543a5f     CALL       sprintf                                          undefined sprintf()
    //         00543a64     ADD        ESP,0x10
    //                              World.cpp:2207 (10)
    //         00543a67     LEA        EDX=>scenario_name[4],[ESP + 0x1c]
    //         00543a6b     PUSH       EDX
    //         00543a6c     CALL       __unlink                                         undefined __unlink()
    //                              World.cpp:2210 (37)
    //         00543a71     MOV        EAX,[rge_base_game]                              = 00000000
    //         00543a76     ADD        ESP,0x4
    //         00543a79     LEA        EDX=>scenario_name[4],[ESP + 0x1c]
    //         00543a7d     MOV        this,dword ptr [EAX + 0xc]
    //         00543a80     PUSH       EDI
    //         00543a81     ADD        this,0xc17
    //         00543a87     PUSH       this
    //         00543a88     PUSH       s_%s%s                                           = "%s%s"
    //         00543a8d     PUSH       EDX
    //         00543a8e     CALL       sprintf                                          undefined sprintf()
    //         00543a93     ADD        ESP,0x10
    //                              World.cpp:2212 (25)
    //         00543a96     LEA        EAX=>scenario_name[4],[ESP + 0x1c]
    //         00543a9a     PUSH       0x180
    //         00543a9f     PUSH       0x8301
    //         00543aa4     PUSH       EAX
    //         00543aa5     CALL       rge_open                                         int rge_open(char * param_1, int param_2, int
    //         00543aaa     MOV        ESI,EAX
    //         00543aac     ADD        ESP,0xc
    //                              World.cpp:2213 (9)
    //         00543aaf     CMP        ESI,-0x1
    //         00543ab2     JZ         LAB_00543deb
    //                              World.cpp:2219 (28)
    //         00543ab8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00543abe     PUSH       s_TRIAL                                          = "TRIAL"
    //         00543ac3     MOV        dword ptr [rge_write_error],0x0
    //         00543acd     CALL       RGE_Base_Game::check_prog_argument               uchar check_prog_argument(RGE_Base_Game * thi
    //         00543ad2     CMP        AL,0x1
    //                              World.cpp:2220 (9)
    //         00543ad4     PUSH       0x4
    //         00543ad6     JNZ        LAB_00543adf
    //         00543ad8     PUSH       s_1.10                                           = "1.10"
    //                              World.cpp:2221 (2)
    //         00543add     JMP        LAB_00543ae4
    //                               LAB_00543adf                                                 XREF[1]:     00543ad6(j)  
    //                              World.cpp:2224 (11)
    //         00543adf     PUSH       s_1.11                                           = "1.11"
    //                               LAB_00543ae4                                                 XREF[1]:     00543add(j)  
    //         00543ae4     PUSH       ESI
    //         00543ae5     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              World.cpp:2227 (15)
    //         00543aea     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00543af0     ADD        ESP,0xc
    //         00543af3     PUSH       ESI
    //         00543af4     CALL       RGE_Base_Game::write_scenario_header             void write_scenario_header(RGE_Base_Game * th
    //                              World.cpp:2231 (12)
    //         00543af9     LEA        this,[EBP + 0x68]
    //         00543afc     PUSH       0x4
    //         00543afe     PUSH       this
    //         00543aff     PUSH       ESI
    //         00543b00     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2232 (12)
    //         00543b05     MOV        this,dword ptr [EBP + 0x5c]
    //         00543b08     ADD        ESP,0xc
    //         00543b0b     MOV        EDX,dword ptr [this->_padding_]
    //         00543b0d     PUSH       ESI
    //         00543b0e     CALL       dword ptr [EDX + 0xc]
    //                              World.cpp:2235 (9)
    //         00543b11     MOV        this,dword ptr [EBP + 0x28]
    //         00543b14     PUSH       ESI
    //         00543b15     CALL       RGE_Map::scenario_save                           void scenario_save(RGE_Map * this, int param_1)
    //                              World.cpp:2238 (13)
    //         00543b1a     LEA        EAX,[ESP + 0x18]
    //         00543b1e     PUSH       0x4
    //         00543b20     PUSH       EAX=>DAT_fffffff8
    //         00543b21     PUSH       ESI=>DAT_fffffff4
    //         00543b22     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2239 (14)
    //         00543b27     MOV        EDI,0x1
    //         00543b2c     ADD        ESP,0xc
    //         00543b2f     CMP        word ptr [EBP + 0x3c],DI
    //         00543b33     JLE        LAB_00543b4a
    //                               LAB_00543b35                                                 XREF[1]:     00543b48(j)  
    //                              World.cpp:2240 (21)
    //         00543b35     MOV        this,dword ptr [EBP + 0x40]
    //         00543b38     PUSH       ESI
    //         00543b39     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         00543b3c     MOV        EDX,dword ptr [this->_padding_]
    //         00543b3e     CALL       dword ptr [EDX + 0x64]
    //         00543b41     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00543b45     INC        EDI
    //         00543b46     CMP        EDI,EAX
    //         00543b48     JL         LAB_00543b35
    //                               LAB_00543b4a                                                 XREF[1]:     00543b33(j)  
    //                              World.cpp:2243 (25)
    //         00543b4a     XOR        EDI,EDI
    //         00543b4c     CMP        word ptr [EBP + 0x3c],DI
    //         00543b50     MOV        dword ptr [ESP + 0x14],EDI
    //         00543b54     JLE        LAB_00543d80
    //         00543b5a     JMP        LAB_00543b60
    //                               LAB_00543b5c                                                 XREF[1]:     00543d7a(j)  
    //         00543b5c     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_00543b60                                                 XREF[1]:     00543b5a(j)  
    //         00543b60     MOV        this,dword ptr [EBP + 0x40]
    //                              World.cpp:2245 (8)
    //         00543b63     MOV        dword ptr [ESP + 0x10],0x0
    //                              World.cpp:2246 (16)
    //         00543b6b     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         00543b6e     LEA        this,[this->_padding_ + EDI*0x4]
    //         00543b71     MOV        EAX,dword ptr [EDX + 0x28]
    //         00543b74     MOV        EAX,dword ptr [EAX + 0x4]
    //         00543b77     TEST       EAX,EAX
    //         00543b79     JZ         LAB_00543b91
    //                               LAB_00543b7b                                                 XREF[1]:     00543b8f(j)  
    //                              World.cpp:2247 (11)
    //         00543b7b     MOV        EDX,dword ptr [EAX]
    //         00543b7d     MOV        EDX,dword ptr [EDX + 0x8]
    //         00543b80     CMP        byte ptr [EDX + 0x4],0x19
    //         00543b84     JZ         LAB_00543b8a
    //                              World.cpp:2248 (11)
    //         00543b86     INC        dword ptr [ESP + 0x10]
    //                               LAB_00543b8a                                                 XREF[1]:     00543b84(j)  
    //         00543b8a     MOV        EAX,dword ptr [EAX + 0x4]
    //         00543b8d     TEST       EAX,EAX
    //         00543b8f     JNZ        LAB_00543b7b
    //                               LAB_00543b91                                                 XREF[1]:     00543b79(j)  
    //                              World.cpp:2249 (12)
    //         00543b91     MOV        EAX,dword ptr [this->_padding_]
    //         00543b93     MOV        this,dword ptr [EAX + 0x2c]
    //         00543b96     MOV        EAX,dword ptr [ECX + this->world_time]
    //         00543b99     TEST       EAX,EAX
    //         00543b9b     JZ         LAB_00543bb3
    //                               LAB_00543b9d                                                 XREF[1]:     00543bb1(j)  
    //                              World.cpp:2250 (11)
    //         00543b9d     MOV        EDX,dword ptr [EAX]
    //         00543b9f     MOV        this,dword ptr [EDX + 0x8]
    //         00543ba2     CMP        byte ptr [ECX + this->world_time],0x19
    //         00543ba6     JZ         LAB_00543bac
    //                              World.cpp:2251 (11)
    //         00543ba8     INC        dword ptr [ESP + 0x10]
    //                               LAB_00543bac                                                 XREF[1]:     00543ba6(j)  
    //         00543bac     MOV        EAX,dword ptr [EAX + 0x4]
    //         00543baf     TEST       EAX,EAX
    //         00543bb1     JNZ        LAB_00543b9d
    //                               LAB_00543bb3                                                 XREF[1]:     00543b9b(j)  
    //                              World.cpp:2252 (13)
    //         00543bb3     LEA        EDX,[ESP + 0x10]
    //         00543bb7     PUSH       0x4
    //         00543bb9     PUSH       EDX=>DAT_fffffff8
    //         00543bba     PUSH       ESI=>DAT_fffffff4
    //         00543bbb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2253 (23)
    //         00543bc0     MOV        EAX,dword ptr [EBP + 0x40]
    //         00543bc3     ADD        ESP,0xc
    //         00543bc6     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00543bc9     MOV        EDX,dword ptr [ECX + this->map]
    //         00543bcc     MOV        EDI,dword ptr [EDX + 0x4]
    //         00543bcf     TEST       EDI,EDI
    //         00543bd1     JZ         LAB_00543c95
    //                               LAB_00543bd7                                                 XREF[1]:     00543c8f(j)  
    //                              World.cpp:2254 (15)
    //         00543bd7     MOV        EAX,dword ptr [EDI]
    //         00543bd9     MOV        this,dword ptr [EAX + 0x8]
    //         00543bdc     CMP        byte ptr [ECX + this->world_time],0x19
    //         00543be0     JZ         LAB_00543c8a
    //                              World.cpp:2256 (12)
    //         00543be6     ADD        EAX,0x38
    //         00543be9     PUSH       0x4
    //         00543beb     PUSH       EAX=>DAT_fffffff8
    //         00543bec     PUSH       ESI=>DAT_fffffff4
    //         00543bed     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2257 (17)
    //         00543bf2     MOV        EDX,dword ptr [EDI]
    //         00543bf4     ADD        ESP,0xc
    //         00543bf7     ADD        EDX,0x3c
    //         00543bfa     PUSH       0x4
    //         00543bfc     PUSH       EDX=>DAT_fffffff8
    //         00543bfd     PUSH       ESI=>DAT_fffffff4
    //         00543bfe     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2258 (17)
    //         00543c03     MOV        EAX,dword ptr [EDI]
    //         00543c05     ADD        ESP,0xc
    //         00543c08     ADD        EAX,0x40
    //         00543c0b     PUSH       0x4
    //         00543c0d     PUSH       EAX=>DAT_fffffff8
    //         00543c0e     PUSH       ESI=>DAT_fffffff4
    //         00543c0f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2259 (17)
    //         00543c14     MOV        this,dword ptr [EDI]
    //         00543c16     ADD        ESP,0xc
    //         00543c19     ADD        this,0x4
    //         00543c1c     PUSH       0x4
    //         00543c1e     PUSH       this=>DAT_fffffff8
    //         00543c1f     PUSH       ESI=>DAT_fffffff4
    //         00543c20     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2260 (20)
    //         00543c25     MOV        EDX,dword ptr [EDI]
    //         00543c27     ADD        ESP,0xc
    //         00543c2a     MOV        EAX,dword ptr [EDX + 0x8]
    //         00543c2d     PUSH       0x2
    //         00543c2f     ADD        EAX,0x10
    //         00543c32     PUSH       EAX=>DAT_fffffff8
    //         00543c33     PUSH       ESI=>DAT_fffffff4
    //         00543c34     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2261 (17)
    //         00543c39     MOV        this,dword ptr [EDI]
    //         00543c3b     ADD        ESP,0xc
    //         00543c3e     ADD        this,0x48
    //         00543c41     PUSH       0x1
    //         00543c43     PUSH       this=>DAT_fffffff8
    //         00543c44     PUSH       ESI=>DAT_fffffff4
    //         00543c45     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2263 (19)
    //         00543c4a     MOV        this,dword ptr [EDI]
    //         00543c4c     ADD        ESP,0xc
    //         00543c4f     MOV        EDX,dword ptr [ECX + this->old_world_time]
    //         00543c52     MOV        AL,byte ptr [EDX + 0x4]
    //         00543c55     CMP        AL,0x1e
    //         00543c57     JBE        LAB_00543c69
    //         00543c59     CMP        AL,0x5a
    //         00543c5b     JNC        LAB_00543c69
    //                              World.cpp:2264 (10)
    //         00543c5d     MOV        EAX,dword ptr [ECX + this->maxNumberNegativeOb
    //         00543c63     MOV        dword ptr [ESP + 0xc],EAX
    //                              World.cpp:2265 (2)
    //         00543c67     JMP        LAB_00543c7a
    //                               LAB_00543c69                                                 XREF[2]:     00543c57(j), 00543c5b(j)  
    //                              World.cpp:2266 (17)
    //         00543c69     XOR        EDX,EDX
    //         00543c6b     MOV        DL,byte ptr [ECX + this+0x35]
    //         00543c6e     MOV        dword ptr [ESP + 0xc],EDX
    //         00543c72     FILD       dword ptr [ESP + 0xc]
    //         00543c76     FSTP       float ptr [ESP + 0xc]
    //                               LAB_00543c7a                                                 XREF[1]:     00543c67(j)  
    //                              World.cpp:2268 (27)
    //         00543c7a     LEA        EAX,[ESP + 0xc]
    //         00543c7e     PUSH       0x4
    //         00543c80     PUSH       EAX=>DAT_fffffff8
    //         00543c81     PUSH       ESI=>DAT_fffffff4
    //         00543c82     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543c87     ADD        ESP,0xc
    //                               LAB_00543c8a                                                 XREF[1]:     00543be0(j)  
    //         00543c8a     MOV        EDI,dword ptr [EDI + 0x4]
    //         00543c8d     TEST       EDI,EDI
    //         00543c8f     JNZ        LAB_00543bd7
    //                               LAB_00543c95                                                 XREF[1]:     00543bd1(j)  
    //                              World.cpp:2270 (24)
    //         00543c95     MOV        this,dword ptr [EBP + 0x40]
    //         00543c98     MOV        EDX,dword ptr [ESP + 0x14]
    //         00543c9c     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00543c9f     MOV        this,dword ptr [EAX + 0x2c]
    //         00543ca2     MOV        EDI,dword ptr [ECX + this->world_time]
    //         00543ca5     TEST       EDI,EDI
    //         00543ca7     JZ         LAB_00543d6b
    //                               LAB_00543cad                                                 XREF[1]:     00543d65(j)  
    //                              World.cpp:2271 (15)
    //         00543cad     MOV        EAX,dword ptr [EDI]
    //         00543caf     MOV        EDX,dword ptr [EAX + 0x8]
    //         00543cb2     CMP        byte ptr [EDX + 0x4],0x19
    //         00543cb6     JZ         LAB_00543d60
    //                              World.cpp:2273 (12)
    //         00543cbc     ADD        EAX,0x38
    //         00543cbf     PUSH       0x4
    //         00543cc1     PUSH       EAX=>DAT_fffffff8
    //         00543cc2     PUSH       ESI=>DAT_fffffff4
    //         00543cc3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2274 (17)
    //         00543cc8     MOV        EAX,dword ptr [EDI]
    //         00543cca     ADD        ESP,0xc
    //         00543ccd     ADD        EAX,0x3c
    //         00543cd0     PUSH       0x4
    //         00543cd2     PUSH       EAX=>DAT_fffffff8
    //         00543cd3     PUSH       ESI=>DAT_fffffff4
    //         00543cd4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2275 (17)
    //         00543cd9     MOV        this,dword ptr [EDI]
    //         00543cdb     ADD        ESP,0xc
    //         00543cde     ADD        this,0x40
    //         00543ce1     PUSH       0x4
    //         00543ce3     PUSH       this=>DAT_fffffff8
    //         00543ce4     PUSH       ESI=>DAT_fffffff4
    //         00543ce5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2276 (17)
    //         00543cea     MOV        EDX,dword ptr [EDI]
    //         00543cec     ADD        ESP,0xc
    //         00543cef     ADD        EDX,0x4
    //         00543cf2     PUSH       0x4
    //         00543cf4     PUSH       EDX=>DAT_fffffff8
    //         00543cf5     PUSH       ESI=>DAT_fffffff4
    //         00543cf6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2277 (20)
    //         00543cfb     MOV        EAX,dword ptr [EDI]
    //         00543cfd     ADD        ESP,0xc
    //         00543d00     MOV        this,dword ptr [EAX + 0x8]
    //         00543d03     PUSH       0x2
    //         00543d05     ADD        this,0x10
    //         00543d08     PUSH       this=>DAT_fffffff8
    //         00543d09     PUSH       ESI=>DAT_fffffff4
    //         00543d0a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2278 (17)
    //         00543d0f     MOV        EDX,dword ptr [EDI]
    //         00543d11     ADD        ESP,0xc
    //         00543d14     ADD        EDX,0x48
    //         00543d17     PUSH       0x1
    //         00543d19     PUSH       EDX=>DAT_fffffff8
    //         00543d1a     PUSH       ESI=>DAT_fffffff4
    //         00543d1b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2280 (19)
    //         00543d20     MOV        this,dword ptr [EDI]
    //         00543d22     ADD        ESP,0xc
    //         00543d25     MOV        EAX,dword ptr [ECX + this->old_world_time]
    //         00543d28     MOV        AL,byte ptr [EAX + 0x4]
    //         00543d2b     CMP        AL,0x1e
    //         00543d2d     JBE        LAB_00543d3f
    //         00543d2f     CMP        AL,0x5a
    //         00543d31     JNC        LAB_00543d3f
    //                              World.cpp:2281 (10)
    //         00543d33     MOV        this,dword ptr [ECX + this->maxNumberNegativeO
    //         00543d39     MOV        dword ptr [ESP + 0xc],this
    //                              World.cpp:2282 (2)
    //         00543d3d     JMP        LAB_00543d50
    //                               LAB_00543d3f                                                 XREF[2]:     00543d2d(j), 00543d31(j)  
    //                              World.cpp:2283 (17)
    //         00543d3f     XOR        EDX,EDX
    //         00543d41     MOV        DL,byte ptr [ECX + this+0x35]
    //         00543d44     MOV        dword ptr [ESP + 0xc],EDX
    //         00543d48     FILD       dword ptr [ESP + 0xc]
    //         00543d4c     FSTP       float ptr [ESP + 0xc]
    //                               LAB_00543d50                                                 XREF[1]:     00543d3d(j)  
    //                              World.cpp:2285 (27)
    //         00543d50     LEA        EAX,[ESP + 0xc]
    //         00543d54     PUSH       0x4
    //         00543d56     PUSH       EAX=>DAT_fffffff8
    //         00543d57     PUSH       ESI=>DAT_fffffff4
    //         00543d58     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00543d5d     ADD        ESP,0xc
    //                               LAB_00543d60                                                 XREF[1]:     00543cb6(j)  
    //         00543d60     MOV        EDI,dword ptr [EDI + 0x4]
    //         00543d63     TEST       EDI,EDI
    //         00543d65     JNZ        LAB_00543cad
    //                               LAB_00543d6b                                                 XREF[1]:     00543ca7(j)  
    //                              World.cpp:2243 (21)
    //         00543d6b     MOV        EAX,dword ptr [ESP + 0x14]
    //         00543d6f     MOVSX      this,word ptr [EBP + 0x3c]
    //         00543d73     INC        EAX
    //         00543d74     CMP        EAX,this
    //         00543d76     MOV        dword ptr [ESP + 0x14],EAX
    //         00543d7a     JL         LAB_00543b5c
    //                               LAB_00543d80                                                 XREF[1]:     00543b54(j)  
    //                              World.cpp:2290 (13)
    //         00543d80     LEA        EDX,[ESP + 0x18]
    //         00543d84     PUSH       0x4
    //         00543d86     PUSH       EDX=>DAT_fffffff8
    //         00543d87     PUSH       ESI=>DAT_fffffff4
    //         00543d88     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              World.cpp:2291 (14)
    //         00543d8d     MOV        EDI,0x1
    //         00543d92     ADD        ESP,0xc
    //         00543d95     CMP        word ptr [EBP + 0x3c],DI
    //         00543d99     JLE        LAB_00543db0
    //                               LAB_00543d9b                                                 XREF[1]:     00543dae(j)  
    //                              World.cpp:2292 (21)
    //         00543d9b     MOV        EAX,dword ptr [EBP + 0x40]
    //         00543d9e     PUSH       ESI
    //         00543d9f     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00543da2     MOV        EDX,dword ptr [this->_padding_]
    //         00543da4     CALL       dword ptr [EDX + 0x6c]
    //         00543da7     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00543dab     INC        EDI
    //         00543dac     CMP        EDI,EAX
    //         00543dae     JL         LAB_00543d9b
    //                               LAB_00543db0                                                 XREF[1]:     00543d99(j)  
    //                              World.cpp:2294 (6)
    //         00543db0     PUSH       ESI
    //         00543db1     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2296 (12)
    //         00543db6     MOV        EAX,[rge_write_error]
    //         00543dbb     ADD        ESP,0x4
    //         00543dbe     TEST       EAX,EAX
    //         00543dc0     JZ         LAB_00543ddd
    //                              World.cpp:2298 (13)
    //         00543dc2     LEA        this,[ESP + 0x1c]
    //         00543dc6     PUSH       this
    //         00543dc7     CALL       __unlink                                         undefined __unlink()
    //         00543dcc     ADD        ESP,0x4
    //                              World.cpp:2304 (2)
    //         00543dcf     XOR        AL,AL
    //                              World.cpp:2305 (12)
    //         00543dd1     POP        EDI
    //         00543dd2     POP        ESI
    //         00543dd3     POP        EBP
    //         00543dd4     ADD        ESP,0x268
    //         00543dda     RET        0x4
    //                               LAB_00543ddd                                                 XREF[1]:     00543dc0(j)  
    //                              World.cpp:2302 (2)
    //         00543ddd     MOV        AL,0x1
    //                              World.cpp:2305 (26)
    //         00543ddf     POP        EDI
    //         00543de0     POP        ESI
    //         00543de1     POP        EBP
    //         00543de2     ADD        ESP,0x268
    //         00543de8     RET        0x4
    //                               LAB_00543deb                                                 XREF[1]:     00543ab2(j)  
    //         00543deb     POP        EDI
    //         00543dec     POP        ESI
    //         00543ded     XOR        AL,AL
    //         00543def     POP        EBP
    //         00543df0     ADD        ESP,0x268
    //         00543df6     RET        0x4
    //         00543df9     ??         90h
    //         00543dfa     NOP
    //         00543dfb     NOP
    //         00543dfc     NOP
    //         00543dfd     NOP
    //         00543dfe     NOP
    //         00543dff     NOP
    //                              * protected: virtual unsigned char __thiscall RGE_Game_World::load_scenario(char *,struct RGE_Player... *
    //                              uchar __thiscall load_scenario(RGE_Game_World * this, char * param_1
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00543e1c(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2                   XREF[8]:     00543e82(R), 00543efd(R), 00543f30(R), 00543f63(R), 
    //                                                                                     00543f96(R), 00543fc9(R), 00543ffc(R), 0054403f(R)  
    //              char[300]         Stack[-0x130   scenario_name             XREF[2,2]:   00543e64(*), 00543e71(R), 00543e15(*), 00543e47(*)  
    //              long              Stack[-0x134   version                   XREF[3]:     00543eba(*), 00543ec7(R), 00543ee5(R)  
    //              long              Stack[-0x138   header_size
    //                               ?load_scenario@RGE_Game_World@@MAEEPADAAURGE_Player_Info@@@Z XREF[2]:     005774d0(*), 00577988(*)  
    //                               RGE_Game_World::load_scenario
    //                              World.cpp:2309 (63)
    //         00543e00     MOV        EAX,[rge_base_game]                              = 00000000
    //         00543e05     SUB        ESP,0x134
    //         00543e0b     MOV        dword ptr [world_update_counter],0x0
    //         00543e15     LEA        EDX=>scenario_name[4],[ESP + 0x8]
    //         00543e19     PUSH       EBX
    //         00543e1a     PUSH       EBP
    //         00543e1b     PUSH       ESI
    //         00543e1c     MOV        ESI,dword ptr [ESP + param_1]
    //         00543e23     PUSH       EDI
    //         00543e24     MOV        EDI,this
    //         00543e26     MOV        this,dword ptr [EAX + 0xc]
    //         00543e29     PUSH       ESI
    //         00543e2a     ADD        this,0xc17
    //         00543e30     PUSH       this
    //         00543e31     PUSH       s_%s%s                                           = "%s%s"
    //         00543e36     PUSH       EDX
    //         00543e37     CALL       sprintf                                          undefined sprintf()
    //         00543e3c     ADD        ESP,0x10
    //                              World.cpp:2320 (2)
    //         00543e3f     TEST       ESI,ESI
    //                              World.cpp:2321 (6)
    //         00543e41     JZ         LAB_00544073
    //                              World.cpp:2323 (20)
    //         00543e47     LEA        EAX=>scenario_name[4],[ESP + 0x18]
    //         00543e4b     PUSH       0x8000
    //         00543e50     PUSH       EAX
    //         00543e51     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
    //         00543e56     MOV        EBX,EAX
    //         00543e58     ADD        ESP,0x8
    //                              World.cpp:2324 (9)
    //         00543e5b     CMP        EBX,-0x1
    //         00543e5e     JZ         LAB_00544073
    //                              World.cpp:2326 (13)
    //         00543e64     LEA        this=>scenario_name,[ESP + 0x14]
    //         00543e68     PUSH       0x4
    //         00543e6a     PUSH       this
    //         00543e6b     PUSH       EBX
    //         00543e6c     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2332 (17)
    //         00543e71     MOV        EAX,dword ptr [ESP + scenario_name[0]]
    //         00543e75     MOV        this,dword ptr [s_1.01]                          = "1.01"
    //         00543e7b     ADD        ESP,0xc
    //         00543e7e     CMP        EAX,this
    //         00543e80     JNZ        LAB_00543eaa
    //                              World.cpp:2333 (16)
    //         00543e82     MOV        EBP,dword ptr [ESP + param_2]
    //         00543e89     MOV        ESI,dword ptr [EDI]
    //         00543e8b     PUSH       EBP
    //         00543e8c     PUSH       EBX
    //         00543e8d     MOV        this,EDI
    //         00543e8f     CALL       dword ptr [ESI + 0x7c]
    //                              World.cpp:2382 (9)
    //         00543e92     PUSH       EBP
    //         00543e93     MOV        this,EDI
    //         00543e95     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543e9b     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543e9d     POP        EDI
    //         00543e9e     POP        ESI
    //         00543e9f     POP        EBP
    //         00543ea0     POP        EBX
    //         00543ea1     ADD        ESP,0x134
    //         00543ea7     RET        0x8
    //                               LAB_00543eaa                                                 XREF[1]:     00543e80(j)  
    //                              World.cpp:2334 (6)
    //         00543eaa     CMP        EAX,dword ptr [s_1.02]                           = "1.02"
    //                              World.cpp:2336 (10)
    //         00543eb0     JZ         LAB_00543efd
    //         00543eb2     CMP        EAX,dword ptr [s_1.03]                           = "1.03"
    //         00543eb8     JNZ        LAB_00543f28
    //                              World.cpp:2339 (13)
    //         00543eba     LEA        EDX=>version,[ESP + 0x10]
    //         00543ebe     PUSH       0x4
    //         00543ec0     PUSH       EDX
    //         00543ec1     PUSH       EBX
    //         00543ec2     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2340 (11)
    //         00543ec7     MOV        EAX,dword ptr [ESP + version]
    //         00543ecb     ADD        ESP,0xc
    //         00543ece     TEST       EAX,EAX
    //         00543ed0     JLE        LAB_00543efd
    //                              World.cpp:2342 (11)
    //         00543ed2     PUSH       EAX
    //         00543ed3     CALL       malloc                                           undefined malloc()
    //         00543ed8     MOV        ESI,EAX
    //         00543eda     ADD        ESP,0x4
    //                              World.cpp:2343 (2)
    //         00543edd     TEST       ESI,ESI
    //                              World.cpp:2346 (6)
    //         00543edf     JZ         LAB_0054406a
    //                              World.cpp:2348 (15)
    //         00543ee5     MOV        EAX,dword ptr [ESP + version]
    //         00543ee9     PUSH       EAX
    //         00543eea     PUSH       ESI
    //         00543eeb     PUSH       EBX
    //         00543eec     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         00543ef1     ADD        ESP,0xc
    //                              World.cpp:2349 (9)
    //         00543ef4     PUSH       ESI
    //         00543ef5     CALL       free                                             undefined free()
    //         00543efa     ADD        ESP,0x4
    //                               LAB_00543efd                                                 XREF[2]:     00543eb0(j), 00543ed0(j)  
    //                              World.cpp:2351 (19)
    //         00543efd     MOV        EBP,dword ptr [ESP + param_2]
    //         00543f04     MOV        ESI,dword ptr [EDI]
    //         00543f06     PUSH       EBP
    //         00543f07     PUSH       EBX
    //         00543f08     MOV        this,EDI
    //         00543f0a     CALL       dword ptr [ESI + 0x80]
    //                              World.cpp:2382 (9)
    //         00543f10     PUSH       EBP
    //         00543f11     MOV        this,EDI
    //         00543f13     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543f19     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543f1b     POP        EDI
    //         00543f1c     POP        ESI
    //         00543f1d     POP        EBP
    //         00543f1e     POP        EBX
    //         00543f1f     ADD        ESP,0x134
    //         00543f25     RET        0x8
    //                               LAB_00543f28                                                 XREF[1]:     00543eb8(j)  
    //                              World.cpp:2353 (8)
    //         00543f28     CMP        EAX,dword ptr [s_1.04]                           = "1.04"
    //         00543f2e     JNZ        LAB_00543f5b
    //                              World.cpp:2354 (19)
    //         00543f30     MOV        EBP,dword ptr [ESP + param_2]
    //         00543f37     MOV        ESI,dword ptr [EDI]
    //         00543f39     PUSH       EBP
    //         00543f3a     PUSH       EBX
    //         00543f3b     MOV        this,EDI
    //         00543f3d     CALL       dword ptr [ESI + 0x84]
    //                              World.cpp:2382 (9)
    //         00543f43     PUSH       EBP
    //         00543f44     MOV        this,EDI
    //         00543f46     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543f4c     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543f4e     POP        EDI
    //         00543f4f     POP        ESI
    //         00543f50     POP        EBP
    //         00543f51     POP        EBX
    //         00543f52     ADD        ESP,0x134
    //         00543f58     RET        0x8
    //                               LAB_00543f5b                                                 XREF[1]:     00543f2e(j)  
    //                              World.cpp:2355 (8)
    //         00543f5b     CMP        EAX,dword ptr [s_1.05]                           = "1.05"
    //         00543f61     JNZ        LAB_00543f8e
    //                              World.cpp:2356 (19)
    //         00543f63     MOV        EBP,dword ptr [ESP + param_2]
    //         00543f6a     MOV        ESI,dword ptr [EDI]
    //         00543f6c     PUSH       EBP
    //         00543f6d     PUSH       EBX
    //         00543f6e     MOV        this,EDI
    //         00543f70     CALL       dword ptr [ESI + 0x88]
    //                              World.cpp:2382 (9)
    //         00543f76     PUSH       EBP
    //         00543f77     MOV        this,EDI
    //         00543f79     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543f7f     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543f81     POP        EDI
    //         00543f82     POP        ESI
    //         00543f83     POP        EBP
    //         00543f84     POP        EBX
    //         00543f85     ADD        ESP,0x134
    //         00543f8b     RET        0x8
    //                               LAB_00543f8e                                                 XREF[1]:     00543f61(j)  
    //                              World.cpp:2357 (8)
    //         00543f8e     CMP        EAX,dword ptr [s_1.06]                           = "1.06"
    //         00543f94     JNZ        LAB_00543fc1
    //                              World.cpp:2358 (19)
    //         00543f96     MOV        EBP,dword ptr [ESP + param_2]
    //         00543f9d     MOV        ESI,dword ptr [EDI]
    //         00543f9f     PUSH       EBP
    //         00543fa0     PUSH       EBX
    //         00543fa1     MOV        this,EDI
    //         00543fa3     CALL       dword ptr [ESI + 0x8c]
    //                              World.cpp:2382 (9)
    //         00543fa9     PUSH       EBP
    //         00543faa     MOV        this,EDI
    //         00543fac     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543fb2     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543fb4     POP        EDI
    //         00543fb5     POP        ESI
    //         00543fb6     POP        EBP
    //         00543fb7     POP        EBX
    //         00543fb8     ADD        ESP,0x134
    //         00543fbe     RET        0x8
    //                               LAB_00543fc1                                                 XREF[1]:     00543f94(j)  
    //                              World.cpp:2359 (8)
    //         00543fc1     CMP        EAX,dword ptr [s_1.07]                           = "1.07"
    //         00543fc7     JNZ        LAB_00543ff4
    //                              World.cpp:2360 (19)
    //         00543fc9     MOV        EBP,dword ptr [ESP + param_2]
    //         00543fd0     MOV        ESI,dword ptr [EDI]
    //         00543fd2     PUSH       EBP
    //         00543fd3     PUSH       EBX
    //         00543fd4     MOV        this,EDI
    //         00543fd6     CALL       dword ptr [ESI + 0x90]
    //                              World.cpp:2382 (9)
    //         00543fdc     PUSH       EBP
    //         00543fdd     MOV        this,EDI
    //         00543fdf     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00543fe5     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         00543fe7     POP        EDI
    //         00543fe8     POP        ESI
    //         00543fe9     POP        EBP
    //         00543fea     POP        EBX
    //         00543feb     ADD        ESP,0x134
    //         00543ff1     RET        0x8
    //                               LAB_00543ff4                                                 XREF[1]:     00543fc7(j)  
    //                              World.cpp:2361 (8)
    //         00543ff4     CMP        EAX,dword ptr [s_1.08]                           = "1.08"
    //         00543ffa     JNZ        LAB_00544027
    //                              World.cpp:2362 (19)
    //         00543ffc     MOV        EBP,dword ptr [ESP + param_2]
    //         00544003     MOV        ESI,dword ptr [EDI]
    //         00544005     PUSH       EBP
    //         00544006     PUSH       EBX
    //         00544007     MOV        this,EDI
    //         00544009     CALL       dword ptr [ESI + 0x94]
    //                              World.cpp:2382 (9)
    //         0054400f     PUSH       EBP
    //         00544010     MOV        this,EDI
    //         00544012     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         00544018     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         0054401a     POP        EDI
    //         0054401b     POP        ESI
    //         0054401c     POP        EBP
    //         0054401d     POP        EBX
    //         0054401e     ADD        ESP,0x134
    //         00544024     RET        0x8
    //                               LAB_00544027                                                 XREF[1]:     00543ffa(j)  
    //                              World.cpp:2364 (6)
    //         00544027     CMP        EAX,dword ptr [s_1.09]                           = "1.09"
    //                              World.cpp:2366 (8)
    //         0054402d     JZ         LAB_0054403f
    //         0054402f     CMP        EAX,dword ptr [s_1.11]                           = "1.11"
    //                              World.cpp:2369 (2)
    //         00544035     JZ         LAB_0054403f
    //                              World.cpp:2373 (8)
    //         00544037     CMP        EAX,dword ptr [s_1.10]                           = "1.10"
    //         0054403d     JNZ        LAB_0054406a
    //                               LAB_0054403f                                                 XREF[2]:     0054402d(j), 00544035(j)  
    //                              World.cpp:2374 (19)
    //         0054403f     MOV        EBP,dword ptr [ESP + param_2]
    //         00544046     MOV        ESI,dword ptr [EDI]
    //         00544048     PUSH       EBP
    //         00544049     PUSH       EBX
    //         0054404a     MOV        this,EDI
    //         0054404c     CALL       dword ptr [ESI + 0x98]
    //                              World.cpp:2382 (9)
    //         00544052     PUSH       EBP
    //         00544053     MOV        this,EDI
    //         00544055     CALL       dword ptr [ESI + 0xa8]
    //                              World.cpp:2384 (2)
    //         0054405b     MOV        AL,0x1
    //                              World.cpp:2388 (13)
    //         0054405d     POP        EDI
    //         0054405e     POP        ESI
    //         0054405f     POP        EBP
    //         00544060     POP        EBX
    //         00544061     ADD        ESP,0x134
    //         00544067     RET        0x8
    //                               LAB_0054406a                                                 XREF[2]:     00543edf(j), 0054403d(j)  
    //                              World.cpp:2377 (9)
    //         0054406a     PUSH       EBX
    //         0054406b     CALL       rge_close                                        int rge_close(int param_1)
    //         00544070     ADD        ESP,0x4
    //                               LAB_00544073                                                 XREF[2]:     00543e41(j), 00543e5e(j)  
    //                              World.cpp:2388 (15)
    //         00544073     POP        EDI
    //         00544074     POP        ESI
    //         00544075     POP        EBP
    //         00544076     XOR        AL,AL
    //         00544078     POP        EBX
    //         00544079     ADD        ESP,0x134
    //         0054407f     RET        0x8
    //         00544082     ??         90h
    //         00544083     NOP
    //         00544084     NOP
    //         00544085     NOP
    //         00544086     NOP
    //         00544087     NOP
    //         00544088     NOP
    //         00544089     NOP
    //         0054408a     NOP
    //         0054408b     NOP
    //         0054408c     NOP
    //         0054408d     NOP
    //         0054408e     NOP
    //         0054408f     NOP
    return 0;
}

uchar RGE_Game_World::load_scenario(char* param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall load_scenario(RGE_Game_World * this, RGE_Player_Inf
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[8]:     005440d7(R), 0054413c(R), 00544159(R), 00544176(R), 
    //                                                                                     00544190(R), 005441aa(R), 005441c4(R), 005441ee(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005440b9(*), 005440c6(R)  
    //              long              Stack[-0x8]:4  version                   XREF[3]:     005440f9(*), 00544106(R), 00544124(R)  
    //              long              Stack[-0xc]:4  header_size
    //                               ?load_scenario@RGE_Game_World@@MAEEAAURGE_Player_Info@@@Z    XREF[2]:     005774cc(*), 00577984(*)  
    //                               RGE_Game_World::load_scenario
    //                              World.cpp:2393 (3)
    //         00544090     SUB        ESP,0x8
    //                              World.cpp:2399 (15)
    //         00544093     MOV        dword ptr [world_update_counter],0x0
    //         0054409d     PUSH       EBX
    //         0054409e     PUSH       EBP
    //         0054409f     PUSH       ESI
    //         005440a0     MOV        ESI,this
    //                              World.cpp:2402 (14)
    //         005440a2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005440a8     PUSH       EDI
    //         005440a9     CALL       RGE_Base_Game::campaign_open_scenario            int campaign_open_scenario(RGE_Base_Game * th
    //         005440ae     MOV        EBX,EAX
    //                              World.cpp:2403 (9)
    //         005440b0     CMP        EBX,-0x1
    //         005440b3     JZ         LAB_0054423c
    //                              World.cpp:2405 (13)
    //         005440b9     LEA        EAX=>local_4,[ESP + 0x14]
    //         005440bd     PUSH       0x4
    //         005440bf     PUSH       EAX
    //         005440c0     PUSH       EBX
    //         005440c1     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2410 (17)
    //         005440c6     MOV        EAX,dword ptr [ESP + local_4]
    //         005440ca     MOV        this,dword ptr [s_1.01]                          = "1.01"
    //         005440d0     ADD        ESP,0xc
    //         005440d3     CMP        EAX,this
    //         005440d5     JNZ        LAB_005440e9
    //                              World.cpp:2411 (13)
    //         005440d7     MOV        EBP,dword ptr [ESP + param_1]
    //         005440db     MOV        EDI,dword ptr [ESI]
    //         005440dd     PUSH       EBP
    //         005440de     PUSH       EBX
    //         005440df     MOV        this,ESI
    //         005440e1     CALL       dword ptr [EDI + 0x7c]
    //                              World.cpp:2412 (11)
    //         005440e4     JMP        LAB_005441fe
    //                               LAB_005440e9                                                 XREF[1]:     005440d5(j)  
    //         005440e9     CMP        EAX,dword ptr [s_1.02]                           = "1.02"
    //                              World.cpp:2414 (10)
    //         005440ef     JZ         LAB_0054413c
    //         005440f1     CMP        EAX,dword ptr [s_1.03]                           = "1.03"
    //         005440f7     JNZ        LAB_00544151
    //                              World.cpp:2416 (13)
    //         005440f9     LEA        this=>version,[ESP + 0x10]
    //         005440fd     PUSH       0x4
    //         005440ff     PUSH       this
    //         00544100     PUSH       EBX
    //         00544101     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2417 (11)
    //         00544106     MOV        EAX,dword ptr [ESP + version]
    //         0054410a     ADD        ESP,0xc
    //         0054410d     TEST       EAX,EAX
    //         0054410f     JLE        LAB_0054413c
    //                              World.cpp:2419 (11)
    //         00544111     PUSH       EAX
    //         00544112     CALL       malloc                                           undefined malloc()
    //         00544117     MOV        EDI,EAX
    //         00544119     ADD        ESP,0x4
    //                              World.cpp:2420 (2)
    //         0054411c     TEST       EDI,EDI
    //                              World.cpp:2423 (6)
    //         0054411e     JZ         LAB_00544233
    //                              World.cpp:2425 (15)
    //         00544124     MOV        EDX,dword ptr [ESP + version]
    //         00544128     PUSH       EDX
    //         00544129     PUSH       EDI
    //         0054412a     PUSH       EBX
    //         0054412b     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         00544130     ADD        ESP,0xc
    //                              World.cpp:2426 (9)
    //         00544133     PUSH       EDI
    //         00544134     CALL       free                                             undefined free()
    //         00544139     ADD        ESP,0x4
    //                               LAB_0054413c                                                 XREF[2]:     005440ef(j), 0054410f(j)  
    //                              World.cpp:2428 (16)
    //         0054413c     MOV        EBP,dword ptr [ESP + param_1]
    //         00544140     MOV        EDI,dword ptr [ESI]
    //         00544142     PUSH       EBP
    //         00544143     PUSH       EBX
    //         00544144     MOV        this,ESI
    //         00544146     CALL       dword ptr [EDI + 0x80]
    //                              World.cpp:2430 (13)
    //         0054414c     JMP        LAB_005441fe
    //                               LAB_00544151                                                 XREF[1]:     005440f7(j)  
    //         00544151     CMP        EAX,dword ptr [s_1.04]                           = "1.04"
    //         00544157     JNZ        LAB_0054416e
    //                              World.cpp:2431 (16)
    //         00544159     MOV        EBP,dword ptr [ESP + param_1]
    //         0054415d     MOV        EDI,dword ptr [ESI]
    //         0054415f     PUSH       EBP
    //         00544160     PUSH       EBX
    //         00544161     MOV        this,ESI
    //         00544163     CALL       dword ptr [EDI + 0x84]
    //                              World.cpp:2432 (13)
    //         00544169     JMP        LAB_005441fe
    //                               LAB_0054416e                                                 XREF[1]:     00544157(j)  
    //         0054416e     CMP        EAX,dword ptr [s_1.05]                           = "1.05"
    //         00544174     JNZ        LAB_00544188
    //                              World.cpp:2433 (16)
    //         00544176     MOV        EBP,dword ptr [ESP + param_1]
    //         0054417a     MOV        EDI,dword ptr [ESI]
    //         0054417c     PUSH       EBP
    //         0054417d     PUSH       EBX
    //         0054417e     MOV        this,ESI
    //         00544180     CALL       dword ptr [EDI + 0x88]
    //                              World.cpp:2434 (10)
    //         00544186     JMP        LAB_005441fe
    //                               LAB_00544188                                                 XREF[1]:     00544174(j)  
    //         00544188     CMP        EAX,dword ptr [s_1.06]                           = "1.06"
    //         0054418e     JNZ        LAB_005441a2
    //                              World.cpp:2435 (16)
    //         00544190     MOV        EBP,dword ptr [ESP + param_1]
    //         00544194     MOV        EDI,dword ptr [ESI]
    //         00544196     PUSH       EBP
    //         00544197     PUSH       EBX
    //         00544198     MOV        this,ESI
    //         0054419a     CALL       dword ptr [EDI + 0x8c]
    //                              World.cpp:2436 (10)
    //         005441a0     JMP        LAB_005441fe
    //                               LAB_005441a2                                                 XREF[1]:     0054418e(j)  
    //         005441a2     CMP        EAX,dword ptr [s_1.07]                           = "1.07"
    //         005441a8     JNZ        LAB_005441bc
    //                              World.cpp:2437 (16)
    //         005441aa     MOV        EBP,dword ptr [ESP + param_1]
    //         005441ae     MOV        EDI,dword ptr [ESI]
    //         005441b0     PUSH       EBP
    //         005441b1     PUSH       EBX
    //         005441b2     MOV        this,ESI
    //         005441b4     CALL       dword ptr [EDI + 0x90]
    //                              World.cpp:2438 (10)
    //         005441ba     JMP        LAB_005441fe
    //                               LAB_005441bc                                                 XREF[1]:     005441a8(j)  
    //         005441bc     CMP        EAX,dword ptr [s_1.08]                           = "1.08"
    //         005441c2     JNZ        LAB_005441d6
    //                              World.cpp:2439 (16)
    //         005441c4     MOV        EBP,dword ptr [ESP + param_1]
    //         005441c8     MOV        EDI,dword ptr [ESI]
    //         005441ca     PUSH       EBP
    //         005441cb     PUSH       EBX
    //         005441cc     MOV        this,ESI
    //         005441ce     CALL       dword ptr [EDI + 0x94]
    //                              World.cpp:2441 (8)
    //         005441d4     JMP        LAB_005441fe
    //                               LAB_005441d6                                                 XREF[1]:     005441c2(j)  
    //         005441d6     CMP        EAX,dword ptr [s_1.09]                           = "1.09"
    //                              World.cpp:2443 (8)
    //         005441dc     JZ         LAB_005441ee
    //         005441de     CMP        EAX,dword ptr [s_1.11]                           = "1.11"
    //                              World.cpp:2445 (2)
    //         005441e4     JZ         LAB_005441ee
    //                              World.cpp:2449 (8)
    //         005441e6     CMP        EAX,dword ptr [s_1.10]                           = "1.10"
    //         005441ec     JNZ        LAB_00544233
    //                               LAB_005441ee                                                 XREF[2]:     005441dc(j), 005441e4(j)  
    //                              World.cpp:2450 (16)
    //         005441ee     MOV        EBP,dword ptr [ESP + param_1]
    //         005441f2     MOV        EDI,dword ptr [ESI]
    //         005441f4     PUSH       EBP
    //         005441f5     PUSH       EBX
    //         005441f6     MOV        this,ESI
    //         005441f8     CALL       dword ptr [EDI + 0x98]
    //                               LAB_005441fe                                                 XREF[7]:     005440e4(j), 0054414c(j), 
    //                                                                                                         00544169(j), 00544186(j), 
    //                                                                                                         005441a0(j), 005441ba(j), 
    //                                                                                                         005441d4(j)  
    //                              World.cpp:2458 (9)
    //         005441fe     PUSH       EBP
    //         005441ff     MOV        this,ESI
    //         00544201     CALL       dword ptr [EDI + 0xa8]
    //                              World.cpp:2460 (32)
    //         00544207     LEA        EAX,[ESI + 0xac]
    //         0054420d     LEA        this,[ESI + 0xa8]
    //         00544213     PUSH       EAX
    //         00544214     ADD        ESI,0xa4
    //         0054421a     PUSH       this=>DAT_fffffff8
    //         0054421b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00544221     PUSH       ESI=>DAT_fffffff4
    //         00544222     CALL       RGE_Base_Game::get_campaign_info                 void get_campaign_info(RGE_Base_Game * this, 
    //                              World.cpp:2461 (2)
    //         00544227     MOV        AL,0x1
    //                              World.cpp:2465 (10)
    //         00544229     POP        EDI
    //         0054422a     POP        ESI
    //         0054422b     POP        EBP
    //         0054422c     POP        EBX
    //         0054422d     ADD        ESP,0x8
    //         00544230     RET        0x4
    //                               LAB_00544233                                                 XREF[2]:     0054411e(j), 005441ec(j)  
    //                              World.cpp:2453 (9)
    //         00544233     PUSH       EBX
    //         00544234     CALL       rge_close                                        int rge_close(int param_1)
    //         00544239     ADD        ESP,0x4
    //                               LAB_0054423c                                                 XREF[1]:     005440b3(j)  
    //                              World.cpp:2465 (12)
    //         0054423c     POP        EDI
    //         0054423d     POP        ESI
    //         0054423e     POP        EBP
    //         0054423f     XOR        AL,AL
    //         00544241     POP        EBX
    //         00544242     ADD        ESP,0x8
    //         00544245     RET        0x4
    //         00544248     ??         90h
    //         00544249     NOP
    //         0054424a     NOP
    //         0054424b     NOP
    //         0054424c     NOP
    //         0054424d     NOP
    //         0054424e     NOP
    //         0054424f     NOP
    //                              * protected: virtual void __thiscall RGE_Game_World::scenario_make_player(short,unsigned char,unsign... *
    //                              void __thiscall scenario_make_player(RGE_Game_World * this, short pa
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00544282(R)  
    //              uchar             Stack[0x8]:1   param_2
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0054425e(R), 0054427e(W)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00544292(R)  
    //              char *            Stack[0x14]:4  param_5                   XREF[1]:     00544296(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00544286(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005442c2(R)  
    //                               ?scenario_make_player@RGE_Game_World@@MAEXFEEEPAD@Z          XREF[1]:     0057797c(*)  
    //                               RGE_Game_World::scenario_make_player
    //                              World.cpp:2469 (14)
    //         00544250     MOV        EAX,FS:[0x0]
    //         00544256     PUSH       -0x1
    //         00544258     PUSH       FUN_00561e6b
    //         0054425d     PUSH       EAX
    //                              World.cpp:2470 (19)
    //         0054425e     MOV        AL,byte ptr [ESP + param_3]
    //         00544262     MOV        dword ptr FS:[0x0],ESP
    //         00544269     PUSH       ESI
    //         0054426a     MOV        ESI,this
    //         0054426c     TEST       AL,AL
    //         0054426e     JNZ        LAB_005442c2
    //         00544270     PUSH       EDI
    //                              World.cpp:2473 (81)
    //         00544271     PUSH       0x220
    //         00544276     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054427b     ADD        ESP,0x4
    //         0054427e     MOV        dword ptr [ESP + param_3],EAX
    //         00544282     MOV        EDI,dword ptr [ESP + param_1]
    //         00544286     MOV        dword ptr [ESP + local_4],0x0
    //         0054428e     TEST       EAX,EAX
    //         00544290     JZ         LAB_005442b6
    //         00544292     MOV        EDX,dword ptr [ESP + param_4]
    //         00544296     MOV        this,dword ptr [ESP + param_5]
    //         0054429a     PUSH       0x1
    //         0054429c     PUSH       EDX
    //         0054429d     PUSH       this
    //         0054429e     MOV        this,dword ptr [ESI + 0x48]
    //         005442a1     AND        EDX,0xff
    //         005442a7     PUSH       EDI
    //         005442a8     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         005442ab     MOV        this,EAX
    //         005442ad     PUSH       EDX
    //         005442ae     PUSH       ESI
    //         005442af     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, RGE_G
    //         005442b4     JMP        LAB_005442b8
    //                               LAB_005442b6                                                 XREF[1]:     00544290(j)  
    //         005442b6     XOR        EAX,EAX
    //                               LAB_005442b8                                                 XREF[1]:     005442b4(j)  
    //         005442b8     MOV        EDX,dword ptr [ESI + 0x40]
    //         005442bb     MOVSX      this,DI
    //         005442be     POP        EDI
    //         005442bf     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //                               LAB_005442c2                                                 XREF[1]:     0054426e(j)  
    //                              World.cpp:2479 (18)
    //         005442c2     MOV        this,dword ptr [ESP + local_c]
    //         005442c6     POP        ESI
    //         005442c7     MOV        dword ptr FS:[0x0],this
    //         005442ce     ADD        ESP,0xc
    //         005442d1     RET        0x14
    //         005442d4     ??         90h
    //         005442d5     NOP
    //         005442d6     NOP
    //         005442d7     NOP
    //         005442d8     NOP
    //         005442d9     NOP
    //         005442da     NOP
    //         005442db     NOP
    //         005442dc     NOP
    //         005442dd     NOP
    //         005442de     NOP
    //         005442df     NOP
    return 0;
}

uchar RGE_Game_World::load_scenario(RGE_Player_Info* param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall load_scenario(RGE_Game_World * this, RGE_Player_Inf
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Player_Inf    Stack[0x4]:4   param_1                   XREF[8]:     005440d7(R), 0054413c(R), 00544159(R), 00544176(R), 
    //                                                                                     00544190(R), 005441aa(R), 005441c4(R), 005441ee(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005440b9(*), 005440c6(R)  
    //              long              Stack[-0x8]:4  version                   XREF[3]:     005440f9(*), 00544106(R), 00544124(R)  
    //              long              Stack[-0xc]:4  header_size
    //                               ?load_scenario@RGE_Game_World@@MAEEAAURGE_Player_Info@@@Z    XREF[2]:     005774cc(*), 00577984(*)  
    //                               RGE_Game_World::load_scenario
    //                              World.cpp:2393 (3)
    //         00544090     SUB        ESP,0x8
    //                              World.cpp:2399 (15)
    //         00544093     MOV        dword ptr [world_update_counter],0x0
    //         0054409d     PUSH       EBX
    //         0054409e     PUSH       EBP
    //         0054409f     PUSH       ESI
    //         005440a0     MOV        ESI,this
    //                              World.cpp:2402 (14)
    //         005440a2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005440a8     PUSH       EDI
    //         005440a9     CALL       RGE_Base_Game::campaign_open_scenario            int campaign_open_scenario(RGE_Base_Game * th
    //         005440ae     MOV        EBX,EAX
    //                              World.cpp:2403 (9)
    //         005440b0     CMP        EBX,-0x1
    //         005440b3     JZ         LAB_0054423c
    //                              World.cpp:2405 (13)
    //         005440b9     LEA        EAX=>local_4,[ESP + 0x14]
    //         005440bd     PUSH       0x4
    //         005440bf     PUSH       EAX
    //         005440c0     PUSH       EBX
    //         005440c1     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2410 (17)
    //         005440c6     MOV        EAX,dword ptr [ESP + local_4]
    //         005440ca     MOV        this,dword ptr [s_1.01]                          = "1.01"
    //         005440d0     ADD        ESP,0xc
    //         005440d3     CMP        EAX,this
    //         005440d5     JNZ        LAB_005440e9
    //                              World.cpp:2411 (13)
    //         005440d7     MOV        EBP,dword ptr [ESP + param_1]
    //         005440db     MOV        EDI,dword ptr [ESI]
    //         005440dd     PUSH       EBP
    //         005440de     PUSH       EBX
    //         005440df     MOV        this,ESI
    //         005440e1     CALL       dword ptr [EDI + 0x7c]
    //                              World.cpp:2412 (11)
    //         005440e4     JMP        LAB_005441fe
    //                               LAB_005440e9                                                 XREF[1]:     005440d5(j)  
    //         005440e9     CMP        EAX,dword ptr [s_1.02]                           = "1.02"
    //                              World.cpp:2414 (10)
    //         005440ef     JZ         LAB_0054413c
    //         005440f1     CMP        EAX,dword ptr [s_1.03]                           = "1.03"
    //         005440f7     JNZ        LAB_00544151
    //                              World.cpp:2416 (13)
    //         005440f9     LEA        this=>version,[ESP + 0x10]
    //         005440fd     PUSH       0x4
    //         005440ff     PUSH       this
    //         00544100     PUSH       EBX
    //         00544101     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2417 (11)
    //         00544106     MOV        EAX,dword ptr [ESP + version]
    //         0054410a     ADD        ESP,0xc
    //         0054410d     TEST       EAX,EAX
    //         0054410f     JLE        LAB_0054413c
    //                              World.cpp:2419 (11)
    //         00544111     PUSH       EAX
    //         00544112     CALL       malloc                                           undefined malloc()
    //         00544117     MOV        EDI,EAX
    //         00544119     ADD        ESP,0x4
    //                              World.cpp:2420 (2)
    //         0054411c     TEST       EDI,EDI
    //                              World.cpp:2423 (6)
    //         0054411e     JZ         LAB_00544233
    //                              World.cpp:2425 (15)
    //         00544124     MOV        EDX,dword ptr [ESP + version]
    //         00544128     PUSH       EDX
    //         00544129     PUSH       EDI
    //         0054412a     PUSH       EBX
    //         0054412b     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         00544130     ADD        ESP,0xc
    //                              World.cpp:2426 (9)
    //         00544133     PUSH       EDI
    //         00544134     CALL       free                                             undefined free()
    //         00544139     ADD        ESP,0x4
    //                               LAB_0054413c                                                 XREF[2]:     005440ef(j), 0054410f(j)  
    //                              World.cpp:2428 (16)
    //         0054413c     MOV        EBP,dword ptr [ESP + param_1]
    //         00544140     MOV        EDI,dword ptr [ESI]
    //         00544142     PUSH       EBP
    //         00544143     PUSH       EBX
    //         00544144     MOV        this,ESI
    //         00544146     CALL       dword ptr [EDI + 0x80]
    //                              World.cpp:2430 (13)
    //         0054414c     JMP        LAB_005441fe
    //                               LAB_00544151                                                 XREF[1]:     005440f7(j)  
    //         00544151     CMP        EAX,dword ptr [s_1.04]                           = "1.04"
    //         00544157     JNZ        LAB_0054416e
    //                              World.cpp:2431 (16)
    //         00544159     MOV        EBP,dword ptr [ESP + param_1]
    //         0054415d     MOV        EDI,dword ptr [ESI]
    //         0054415f     PUSH       EBP
    //         00544160     PUSH       EBX
    //         00544161     MOV        this,ESI
    //         00544163     CALL       dword ptr [EDI + 0x84]
    //                              World.cpp:2432 (13)
    //         00544169     JMP        LAB_005441fe
    //                               LAB_0054416e                                                 XREF[1]:     00544157(j)  
    //         0054416e     CMP        EAX,dword ptr [s_1.05]                           = "1.05"
    //         00544174     JNZ        LAB_00544188
    //                              World.cpp:2433 (16)
    //         00544176     MOV        EBP,dword ptr [ESP + param_1]
    //         0054417a     MOV        EDI,dword ptr [ESI]
    //         0054417c     PUSH       EBP
    //         0054417d     PUSH       EBX
    //         0054417e     MOV        this,ESI
    //         00544180     CALL       dword ptr [EDI + 0x88]
    //                              World.cpp:2434 (10)
    //         00544186     JMP        LAB_005441fe
    //                               LAB_00544188                                                 XREF[1]:     00544174(j)  
    //         00544188     CMP        EAX,dword ptr [s_1.06]                           = "1.06"
    //         0054418e     JNZ        LAB_005441a2
    //                              World.cpp:2435 (16)
    //         00544190     MOV        EBP,dword ptr [ESP + param_1]
    //         00544194     MOV        EDI,dword ptr [ESI]
    //         00544196     PUSH       EBP
    //         00544197     PUSH       EBX
    //         00544198     MOV        this,ESI
    //         0054419a     CALL       dword ptr [EDI + 0x8c]
    //                              World.cpp:2436 (10)
    //         005441a0     JMP        LAB_005441fe
    //                               LAB_005441a2                                                 XREF[1]:     0054418e(j)  
    //         005441a2     CMP        EAX,dword ptr [s_1.07]                           = "1.07"
    //         005441a8     JNZ        LAB_005441bc
    //                              World.cpp:2437 (16)
    //         005441aa     MOV        EBP,dword ptr [ESP + param_1]
    //         005441ae     MOV        EDI,dword ptr [ESI]
    //         005441b0     PUSH       EBP
    //         005441b1     PUSH       EBX
    //         005441b2     MOV        this,ESI
    //         005441b4     CALL       dword ptr [EDI + 0x90]
    //                              World.cpp:2438 (10)
    //         005441ba     JMP        LAB_005441fe
    //                               LAB_005441bc                                                 XREF[1]:     005441a8(j)  
    //         005441bc     CMP        EAX,dword ptr [s_1.08]                           = "1.08"
    //         005441c2     JNZ        LAB_005441d6
    //                              World.cpp:2439 (16)
    //         005441c4     MOV        EBP,dword ptr [ESP + param_1]
    //         005441c8     MOV        EDI,dword ptr [ESI]
    //         005441ca     PUSH       EBP
    //         005441cb     PUSH       EBX
    //         005441cc     MOV        this,ESI
    //         005441ce     CALL       dword ptr [EDI + 0x94]
    //                              World.cpp:2441 (8)
    //         005441d4     JMP        LAB_005441fe
    //                               LAB_005441d6                                                 XREF[1]:     005441c2(j)  
    //         005441d6     CMP        EAX,dword ptr [s_1.09]                           = "1.09"
    //                              World.cpp:2443 (8)
    //         005441dc     JZ         LAB_005441ee
    //         005441de     CMP        EAX,dword ptr [s_1.11]                           = "1.11"
    //                              World.cpp:2445 (2)
    //         005441e4     JZ         LAB_005441ee
    //                              World.cpp:2449 (8)
    //         005441e6     CMP        EAX,dword ptr [s_1.10]                           = "1.10"
    //         005441ec     JNZ        LAB_00544233
    //                               LAB_005441ee                                                 XREF[2]:     005441dc(j), 005441e4(j)  
    //                              World.cpp:2450 (16)
    //         005441ee     MOV        EBP,dword ptr [ESP + param_1]
    //         005441f2     MOV        EDI,dword ptr [ESI]
    //         005441f4     PUSH       EBP
    //         005441f5     PUSH       EBX
    //         005441f6     MOV        this,ESI
    //         005441f8     CALL       dword ptr [EDI + 0x98]
    //                               LAB_005441fe                                                 XREF[7]:     005440e4(j), 0054414c(j), 
    //                                                                                                         00544169(j), 00544186(j), 
    //                                                                                                         005441a0(j), 005441ba(j), 
    //                                                                                                         005441d4(j)  
    //                              World.cpp:2458 (9)
    //         005441fe     PUSH       EBP
    //         005441ff     MOV        this,ESI
    //         00544201     CALL       dword ptr [EDI + 0xa8]
    //                              World.cpp:2460 (32)
    //         00544207     LEA        EAX,[ESI + 0xac]
    //         0054420d     LEA        this,[ESI + 0xa8]
    //         00544213     PUSH       EAX
    //         00544214     ADD        ESI,0xa4
    //         0054421a     PUSH       this=>DAT_fffffff8
    //         0054421b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00544221     PUSH       ESI=>DAT_fffffff4
    //         00544222     CALL       RGE_Base_Game::get_campaign_info                 void get_campaign_info(RGE_Base_Game * this, 
    //                              World.cpp:2461 (2)
    //         00544227     MOV        AL,0x1
    //                              World.cpp:2465 (10)
    //         00544229     POP        EDI
    //         0054422a     POP        ESI
    //         0054422b     POP        EBP
    //         0054422c     POP        EBX
    //         0054422d     ADD        ESP,0x8
    //         00544230     RET        0x4
    //                               LAB_00544233                                                 XREF[2]:     0054411e(j), 005441ec(j)  
    //                              World.cpp:2453 (9)
    //         00544233     PUSH       EBX
    //         00544234     CALL       rge_close                                        int rge_close(int param_1)
    //         00544239     ADD        ESP,0x4
    //                               LAB_0054423c                                                 XREF[1]:     005440b3(j)  
    //                              World.cpp:2465 (12)
    //         0054423c     POP        EDI
    //         0054423d     POP        ESI
    //         0054423e     POP        EBP
    //         0054423f     XOR        AL,AL
    //         00544241     POP        EBX
    //         00544242     ADD        ESP,0x8
    //         00544245     RET        0x4
    //         00544248     ??         90h
    //         00544249     NOP
    //         0054424a     NOP
    //         0054424b     NOP
    //         0054424c     NOP
    //         0054424d     NOP
    //         0054424e     NOP
    //         0054424f     NOP
    //                              * protected: virtual void __thiscall RGE_Game_World::scenario_make_player(short,unsigned char,unsign... *
    //                              void __thiscall scenario_make_player(RGE_Game_World * this, short pa
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00544282(R)  
    //              uchar             Stack[0x8]:1   param_2
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0054425e(R), 0054427e(W)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00544292(R)  
    //              char *            Stack[0x14]:4  param_5                   XREF[1]:     00544296(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00544286(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005442c2(R)  
    //                               ?scenario_make_player@RGE_Game_World@@MAEXFEEEPAD@Z          XREF[1]:     0057797c(*)  
    //                               RGE_Game_World::scenario_make_player
    //                              World.cpp:2469 (14)
    //         00544250     MOV        EAX,FS:[0x0]
    //         00544256     PUSH       -0x1
    //         00544258     PUSH       FUN_00561e6b
    //         0054425d     PUSH       EAX
    //                              World.cpp:2470 (19)
    //         0054425e     MOV        AL,byte ptr [ESP + param_3]
    //         00544262     MOV        dword ptr FS:[0x0],ESP
    //         00544269     PUSH       ESI
    //         0054426a     MOV        ESI,this
    //         0054426c     TEST       AL,AL
    //         0054426e     JNZ        LAB_005442c2
    //         00544270     PUSH       EDI
    //                              World.cpp:2473 (81)
    //         00544271     PUSH       0x220
    //         00544276     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0054427b     ADD        ESP,0x4
    //         0054427e     MOV        dword ptr [ESP + param_3],EAX
    //         00544282     MOV        EDI,dword ptr [ESP + param_1]
    //         00544286     MOV        dword ptr [ESP + local_4],0x0
    //         0054428e     TEST       EAX,EAX
    //         00544290     JZ         LAB_005442b6
    //         00544292     MOV        EDX,dword ptr [ESP + param_4]
    //         00544296     MOV        this,dword ptr [ESP + param_5]
    //         0054429a     PUSH       0x1
    //         0054429c     PUSH       EDX
    //         0054429d     PUSH       this
    //         0054429e     MOV        this,dword ptr [ESI + 0x48]
    //         005442a1     AND        EDX,0xff
    //         005442a7     PUSH       EDI
    //         005442a8     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         005442ab     MOV        this,EAX
    //         005442ad     PUSH       EDX
    //         005442ae     PUSH       ESI
    //         005442af     CALL       RGE_Player::RGE_Player                           undefined RGE_Player(RGE_Player * this, RGE_G
    //         005442b4     JMP        LAB_005442b8
    //                               LAB_005442b6                                                 XREF[1]:     00544290(j)  
    //         005442b6     XOR        EAX,EAX
    //                               LAB_005442b8                                                 XREF[1]:     005442b4(j)  
    //         005442b8     MOV        EDX,dword ptr [ESI + 0x40]
    //         005442bb     MOVSX      this,DI
    //         005442be     POP        EDI
    //         005442bf     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //                               LAB_005442c2                                                 XREF[1]:     0054426e(j)  
    //                              World.cpp:2479 (18)
    //         005442c2     MOV        this,dword ptr [ESP + local_c]
    //         005442c6     POP        ESI
    //         005442c7     MOV        dword ptr FS:[0x0],this
    //         005442ce     ADD        ESP,0xc
    //         005442d1     RET        0x14
    //         005442d4     ??         90h
    //         005442d5     NOP
    //         005442d6     NOP
    //         005442d7     NOP
    //         005442d8     NOP
    //         005442d9     NOP
    //         005442da     NOP
    //         005442db     NOP
    //         005442dc     NOP
    //         005442dd     NOP
    //         005442de     NOP
    //         005442df     NOP
    return 0;
}

void RGE_Game_World::scenario_make_map(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall scenario_make_map(RGE_Game_World * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005442e0(R)  
    //                               ?scenario_make_map@RGE_Game_World@@MAEXH@Z                   XREF[2]:     005774c8(*), 00577980(*)  
    //                               RGE_Game_World::scenario_make_map
    //                              World.cpp:2483 (15)
    //         005442e0     MOV        EAX,dword ptr [ESP + param_1]
    //         005442e4     MOV        this,dword ptr [ECX + this->map]
    //         005442e7     PUSH       0x0
    //         005442e9     PUSH       EAX
    //         005442ea     CALL       RGE_Map::scenario_load                           void scenario_load(RGE_Map * this, int param_
    //                              World.cpp:2485 (3)
    //         005442ef     RET        0x4
    //         005442f2     ??         90h
    //         005442f3     NOP
    //         005442f4     NOP
    //         005442f5     NOP
    //         005442f6     NOP
    //         005442f7     NOP
    //         005442f8     NOP
    //         005442f9     NOP
    //         005442fa     NOP
    //         005442fb     NOP
    //         005442fc     NOP
    //         005442fd     NOP
    //         005442fe     NOP
    //         005442ff     NOP
    return;
}

void RGE_Game_World::load_scenario1(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario1(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00544309(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash
    //              char[13]          Stack[-0x38]   rem                       XREF[1]:     00544303(*)  
    //              long              Stack[-0x3c]:4 obj_id
    //              float             Stack[-0x40]:4 world_x
    //              float             Stack[-0x44]:4 world_y
    //              float             Stack[-0x48]:4 world_z
    //              short             Stack[-0x4c]:2 master_id
    //              uchar             Stack[-0x50]:1 obj_state
    //              float             Stack[-0x54]:4 obj_angle
    //              long              Stack[-0x58]:4 id
    //              long              Stack[-0x5c]:4 count
    //              long              Stack[-0x60]:4 scenario_player_num
    //              uchar             Stack[-0x61]:1 master_player_id
    //                               ?load_scenario1@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774d4(*), 0057798c(*)  
    //                               RGE_Game_World::load_scenario1
    //                              World.cpp:2489 (3)
    //         00544300     SUB        ESP,0x60
    //                              World.cpp:2508 (23)
    //         00544303     LEA        EAX=>rem,[ESP + 0x28]
    //         00544307     PUSH       EBX
    //         00544308     PUSH       EBP
    //         00544309     MOV        EBP,dword ptr [ESP + param_1]
    //         0054430d     PUSH       ESI
    //         0054430e     PUSH       EDI
    //         0054430f     PUSH       0x4
    //         00544311     PUSH       EAX
    //         00544312     MOV        ESI,this
    //         00544314     PUSH       EBP
    //         00544315     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2509 (15)
    //         0054431a     MOV        EDI,dword ptr [ESI]
    //         0054431c     ADD        ESP,0xc
    //         0054431f     MOV        this,ESI
    //         00544321     PUSH       ESI
    //         00544322     PUSH       EBP
    //         00544323     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:2512 (6)
    //         00544329     PUSH       EBP
    //         0054432a     MOV        this,ESI
    //         0054432c     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:2514 (8)
    //         0054432f     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         00544333     TEST       EDX,EDX
    //         00544335     JLE        LAB_0054434a
    //                               LAB_00544337                                                 XREF[1]:     00544348(j)  
    //                              World.cpp:2518 (19)
    //         00544337     MOV        this,0x9
    //         0054433c     OR         EAX,0xffffffff
    //         0054433f     LEA        EDI,[ESP + 0x4c]
    //         00544343     CMP        EDX,0xa
    //         00544346     STOSD.REP  ES:EDI
    //         00544348     JG         LAB_00544337
    //                               LAB_0054434a                                                 XREF[1]:     00544335(j)  
    //                              World.cpp:2521 (16)
    //         0054434a     XOR        EAX,EAX
    //         0054434c     TEST       EDX,EDX
    //         0054434e     JLE        LAB_00544368
    //         00544350     MOV        this,dword ptr [ESP + 0x78]
    //         00544354     ADD        this,0x270
    //                               LAB_0054435a                                                 XREF[1]:     00544366(j)  
    //                              World.cpp:2522 (14)
    //         0054435a     MOV        EDI,dword ptr [this->_padding_]
    //         0054435c     ADD        this,0x4
    //         0054435f     MOV        dword ptr [ESP + EDI*0x4 + 0x4c],EAX
    //         00544363     INC        EAX
    //         00544364     CMP        EAX,EDX
    //         00544366     JL         LAB_0054435a
    //                               LAB_00544368                                                 XREF[1]:     0054434e(j)  
    //                              World.cpp:2526 (6)
    //         00544368     XOR        EDI,EDI
    //         0054436a     TEST       EDX,EDX
    //         0054436c     JLE        LAB_00544382
    //                               LAB_0054436e                                                 XREF[1]:     00544380(j)  
    //                              World.cpp:2527 (20)
    //         0054436e     MOV        EDX,dword ptr [ESI + 0x40]
    //         00544371     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00544374     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00544379     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         0054437d     INC        EDI
    //         0054437e     CMP        EDI,EAX
    //         00544380     JL         LAB_0054436e
    //                               LAB_00544382                                                 XREF[1]:     0054436c(j)  
    //                              World.cpp:2535 (13)
    //         00544382     LEA        this,[ESP + 0x14]
    //         00544386     PUSH       0x4
    //         00544388     PUSH       this=>DAT_fffffff8
    //         00544389     PUSH       EBP=>DAT_fffffff4
    //         0054438a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2536 (13)
    //         0054438f     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544393     ADD        ESP,0xc
    //         00544396     XOR        EDI,EDI
    //         00544398     TEST       EAX,EAX
    //         0054439a     JLE        LAB_005443c5
    //                               LAB_0054439c                                                 XREF[1]:     005443c3(j)  
    //                              World.cpp:2539 (16)
    //         0054439c     LEA        EDX,[ESP + 0x74]
    //         005443a0     PUSH       0x1
    //         005443a2     PUSH       EDX=>DAT_fffffff8
    //         005443a3     PUSH       EBP=>DAT_fffffff4
    //         005443a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005443a9     ADD        ESP,0xc
    //                              World.cpp:2540 (25)
    //         005443ac     LEA        EAX,[ESP + 0x13]
    //         005443b0     PUSH       0x1
    //         005443b2     PUSH       EAX=>DAT_fffffff8
    //         005443b3     PUSH       EBP=>DAT_fffffff4
    //         005443b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005443b9     MOV        EAX,dword ptr [ESP + 0x20]
    //         005443bd     ADD        ESP,0xc
    //         005443c0     INC        EDI
    //         005443c1     CMP        EDI,EAX
    //         005443c3     JL         LAB_0054439c
    //                               LAB_005443c5                                                 XREF[1]:     0054439a(j)  
    //                              World.cpp:2559 (10)
    //         005443c5     XOR        EDI,EDI
    //         005443c7     TEST       EAX,EAX
    //         005443c9     JLE        LAB_005444c5
    //                               LAB_005443cf                                                 XREF[1]:     005444bf(j)  
    //                              World.cpp:2562 (13)
    //         005443cf     LEA        this,[ESP + 0x18]
    //         005443d3     PUSH       0x4
    //         005443d5     PUSH       this=>DAT_fffffff8
    //         005443d6     PUSH       EBP=>DAT_fffffff4
    //         005443d7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2563 (17)
    //         005443dc     MOV        EAX,dword ptr [ESP + 0x24]
    //         005443e0     ADD        ESP,0xc
    //         005443e3     XOR        EBX,EBX
    //         005443e5     TEST       EAX,EAX
    //         005443e7     JLE        LAB_005444b8
    //                               LAB_005443ed                                                 XREF[1]:     005444b2(j)  
    //                              World.cpp:2565 (16)
    //         005443ed     LEA        EDX,[ESP + 0x34]
    //         005443f1     PUSH       0x4
    //         005443f3     PUSH       EDX=>DAT_fffffff8
    //         005443f4     PUSH       EBP=>DAT_fffffff4
    //         005443f5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005443fa     ADD        ESP,0xc
    //                              World.cpp:2566 (16)
    //         005443fd     LEA        EAX,[ESP + 0x30]
    //         00544401     PUSH       0x4
    //         00544403     PUSH       EAX=>DAT_fffffff8
    //         00544404     PUSH       EBP=>DAT_fffffff4
    //         00544405     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054440a     ADD        ESP,0xc
    //                              World.cpp:2567 (16)
    //         0054440d     LEA        this,[ESP + 0x2c]
    //         00544411     PUSH       0x4
    //         00544413     PUSH       this=>DAT_fffffff8
    //         00544414     PUSH       EBP=>DAT_fffffff4
    //         00544415     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054441a     ADD        ESP,0xc
    //                              World.cpp:2568 (16)
    //         0054441d     LEA        EDX,[ESP + 0x1c]
    //         00544421     PUSH       0x4
    //         00544423     PUSH       EDX=>DAT_fffffff8
    //         00544424     PUSH       EBP=>DAT_fffffff4
    //         00544425     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054442a     ADD        ESP,0xc
    //                              World.cpp:2569 (16)
    //         0054442d     LEA        EAX,[ESP + 0x28]
    //         00544431     PUSH       0x2
    //         00544433     PUSH       EAX=>DAT_fffffff8
    //         00544434     PUSH       EBP=>DAT_fffffff4
    //         00544435     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054443a     ADD        ESP,0xc
    //                              World.cpp:2570 (16)
    //         0054443d     LEA        this,[ESP + 0x24]
    //         00544441     PUSH       0x1
    //         00544443     PUSH       this=>DAT_fffffff8
    //         00544444     PUSH       EBP=>DAT_fffffff4
    //         00544445     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0054444a     ADD        ESP,0xc
    //                              World.cpp:2571 (13)
    //         0054444d     LEA        EDX,[ESP + 0x20]
    //         00544451     PUSH       0x4
    //         00544453     PUSH       EDX=>DAT_fffffff8
    //         00544454     PUSH       EBP=>DAT_fffffff4
    //         00544455     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2572 (28)
    //         0054445a     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         0054445e     ADD        ESP,0xc
    //         00544461     CMP        EDI,EAX
    //         00544463     JGE        LAB_005444ab
    //         00544465     MOV        this,dword ptr [ESP + EDI*0x4 + 0x4c]
    //         00544469     TEST       this,this
    //         0054446b     JL         LAB_005444ab
    //         0054446d     MOV        EAX,dword ptr [ESI + 0x40]
    //         00544470     CMP        dword ptr [EAX + EDI*0x4],0x0
    //         00544474     JZ         LAB_005444ab
    //                              World.cpp:2574 (4)
    //         00544476     MOV        EDX,dword ptr [ESP + 0x1c]
    //                              World.cpp:2575 (7)
    //         0054447a     MOV        byte ptr [ESI + 0x74],0x1
    //         0054447e     MOV        dword ptr [ESI + 0x70],EDX
    //                              World.cpp:2577 (38)
    //         00544481     MOV        EDX,dword ptr [ESP + 0x20]
    //         00544485     PUSH       EDX
    //         00544486     MOV        EDX,dword ptr [ESP + 0x28]
    //         0054448a     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         0054448d     PUSH       EDX=>DAT_fffffff8
    //         0054448e     MOV        EDX,dword ptr [ESP + 0x30]
    //         00544492     MOV        EAX,dword ptr [this->_padding_]
    //         00544494     PUSH       EDX=>DAT_fffffff4
    //         00544495     MOV        EDX,dword ptr [ESP + 0x38]
    //         00544499     PUSH       EDX=>DAT_fffffff0
    //         0054449a     MOV        EDX,dword ptr [ESP + 0x40]
    //         0054449e     PUSH       EDX
    //         0054449f     MOV        EDX,dword ptr [ESP + 0x48]
    //         005444a3     PUSH       EDX
    //         005444a4     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:2578 (17)
    //         005444a7     MOV        byte ptr [ESI + 0x74],0x0
    //                               LAB_005444ab                                                 XREF[3]:     00544463(j), 0054446b(j), 
    //                                                                                                         00544474(j)  
    //         005444ab     MOV        EAX,dword ptr [ESP + 0x18]
    //         005444af     INC        EBX
    //         005444b0     CMP        EBX,EAX
    //         005444b2     JL         LAB_005443ed
    //                               LAB_005444b8                                                 XREF[1]:     005443e7(j)  
    //                              World.cpp:2559 (13)
    //         005444b8     MOV        EAX,dword ptr [ESP + 0x14]
    //         005444bc     INC        EDI
    //         005444bd     CMP        EDI,EAX
    //         005444bf     JL         LAB_005443cf
    //                               LAB_005444c5                                                 XREF[1]:     005443c9(j)  
    //                              World.cpp:2582 (4)
    //         005444c5     MOV        EAX,dword ptr [ESP + 0x38]
    //                              World.cpp:2584 (16)
    //         005444c9     LEA        this,[ESP + 0x3c]
    //         005444cd     PUSH       0xd
    //         005444cf     PUSH       this=>DAT_fffffff8
    //         005444d0     PUSH       EBP=>DAT_fffffff4
    //         005444d1     MOV        dword ptr [ESI + 0x68],EAX
    //         005444d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2586 (16)
    //         005444d9     MOV        EAX,dword ptr [ESP + 0x20]
    //         005444dd     MOV        EDI,0x1
    //         005444e2     ADD        ESP,0xc
    //         005444e5     CMP        EAX,EDI
    //         005444e7     JLE        LAB_00544527
    //                              World.cpp:2582 (4)
    //         005444e9     LEA        EBX,[ESP + 0x50]
    //                               LAB_005444ed                                                 XREF[1]:     00544525(j)  
    //                              World.cpp:2588 (23)
    //         005444ed     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         005444f1     CMP        EDI,EDX
    //         005444f3     JGE        LAB_00544506
    //         005444f5     MOV        EAX,dword ptr [EBX]
    //         005444f7     CMP        EAX,-0x1
    //         005444fa     JLE        LAB_00544506
    //         005444fc     MOV        this,dword ptr [ESI + 0x40]
    //         005444ff     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544502     TEST       this,this
    //                              World.cpp:2590 (2)
    //         00544504     JNZ        LAB_0054450b
    //                               LAB_00544506                                                 XREF[2]:     005444f3(j), 005444fa(j)  
    //                              World.cpp:2591 (33)
    //         00544506     MOV        this,dword ptr [ESI + 0x40]
    //         00544509     MOV        this,dword ptr [this->_padding_]
    //                               LAB_0054450b                                                 XREF[1]:     00544504(j)  
    //         0054450b     MOV        EDX,dword ptr [this->_padding_]
    //         0054450d     LEA        EAX,[ESP + 0x4c]
    //         00544511     PUSH       0x3f800000
    //         00544516     PUSH       EAX=>DAT_fffffff8
    //         00544517     PUSH       EBP=>DAT_fffffff4
    //         00544518     CALL       dword ptr [EDX + 0x68]
    //         0054451b     MOV        EAX,dword ptr [ESP + 0x14]
    //         0054451f     INC        EDI
    //         00544520     ADD        EBX,0x4
    //         00544523     CMP        EDI,EAX
    //         00544525     JL         LAB_005444ed
    //                               LAB_00544527                                                 XREF[1]:     005444e7(j)  
    //                              World.cpp:2595 (6)
    //         00544527     PUSH       EBP
    //         00544528     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2596 (24)
    //         0054452d     MOV        EDI,0x1
    //         00544532     ADD        ESP,0x4
    //         00544535     CMP        word ptr [ESI + 0x3c],DI
    //         00544539     MOV        dword ptr [ESP + 0x78],EDI
    //         0054453d     JLE        LAB_005445a9
    //                               LAB_0054453f                                                 XREF[1]:     005445a7(j)  
    //         0054453f     CMP        EDI,dword ptr [ESP + 0x14]
    //         00544543     JGE        LAB_005445a9
    //                              World.cpp:2597 (9)
    //         00544545     MOV        EAX,dword ptr [ESI + 0x40]
    //         00544548     CMP        dword ptr [EAX + EDI*0x4],0x0
    //         0054454c     JZ         LAB_0054459c
    //                              World.cpp:2600 (91)
    //         0054454e     MOV        this,dword ptr [ESP + EDI*0x4 + 0x4c]
    //         00544552     LEA        EBP,[ESP + EDI*0x4 + 0x4c]
    //         00544556     DEC        EDI
    //         00544557     PUSH       -0x1
    //         00544559     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         0054455c     MOV        this,dword ptr [ESI + 0x5c]
    //         0054455f     PUSH       EDI=>DAT_fffffff8
    //         00544560     MOV        EBX,dword ptr [EDX]
    //         00544562     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00544567     MOV        this,dword ptr [ESI + 0x5c]
    //         0054456a     PUSH       EAX=>DAT_fffffff8
    //         0054456b     PUSH       offset DAT_fffffff4
    //         0054456d     PUSH       EDI=>DAT_fffffff0
    //         0054456e     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00544573     MOV        this,dword ptr [ESI + 0x5c]
    //         00544576     PUSH       EAX=>DAT_fffffff4
    //         00544577     PUSH       offset DAT_fffffff0
    //         00544579     PUSH       EDI
    //         0054457a     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         0054457f     MOV        this,dword ptr [ESI + 0x5c]
    //         00544582     PUSH       EAX=>DAT_fffffff0
    //         00544583     PUSH       0x1
    //         00544585     PUSH       EDI
    //         00544586     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         0054458b     MOV        this,dword ptr [ESI + 0x40]
    //         0054458e     PUSH       EAX
    //         0054458f     MOV        EAX,dword ptr [EBP]
    //         00544592     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544595     CALL       dword ptr [EBX + 0x2c]
    //         00544598     MOV        EDI,dword ptr [ESP + 0x78]
    //                               LAB_0054459c                                                 XREF[1]:     0054454c(j)  
    //         0054459c     MOVSX      EDX,word ptr [ESI + 0x3c]
    //         005445a0     INC        EDI
    //         005445a1     CMP        EDI,EDX
    //         005445a3     MOV        dword ptr [ESP + 0x78],EDI
    //         005445a7     JL         LAB_0054453f
    //                               LAB_005445a9                                                 XREF[2]:     0054453d(j), 00544543(j)  
    //                              World.cpp:2604 (10)
    //         005445a9     POP        EDI
    //         005445aa     POP        ESI
    //         005445ab     POP        EBP
    //         005445ac     POP        EBX
    //         005445ad     ADD        ESP,0x60
    //         005445b0     RET        0x8
    //         005445b3     ??         90h
    //         005445b4     NOP
    //         005445b5     NOP
    //         005445b6     NOP
    //         005445b7     NOP
    //         005445b8     NOP
    //         005445b9     NOP
    //         005445ba     NOP
    //         005445bb     NOP
    //         005445bc     NOP
    //         005445bd     NOP
    //         005445be     NOP
    //         005445bf     NOP
    return;
}

void RGE_Game_World::load_scenario2(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario2(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005445ca(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash
    //              char[13]          Stack[-0x38]   rem                       XREF[1]:     005445c3(*)  
    //              long              Stack[-0x3c]:4 obj_id
    //              float             Stack[-0x40]:4 world_x
    //              float             Stack[-0x44]:4 world_y
    //              float             Stack[-0x48]:4 world_z
    //              short             Stack[-0x4c]:2 master_id
    //              uchar             Stack[-0x50]:1 obj_state
    //              float             Stack[-0x54]:4 obj_angle
    //              long              Stack[-0x58]:4 id
    //              long              Stack[-0x5c]:4 count
    //              long              Stack[-0x60]:4 scenario_player_num
    //              uchar             Stack[-0x61]:1 master_player_id
    //                               ?load_scenario2@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774d8(*), 00577990(*)  
    //                               RGE_Game_World::load_scenario2
    //                              World.cpp:2608 (3)
    //         005445c0     SUB        ESP,0x60
    //                              World.cpp:2629 (31)
    //         005445c3     LEA        EAX=>rem,[ESP + 0x28]
    //         005445c7     PUSH       EBX
    //         005445c8     PUSH       EBP
    //         005445c9     PUSH       ESI
    //         005445ca     MOV        ESI,dword ptr [ESP + param_1]
    //         005445ce     PUSH       EDI
    //         005445cf     PUSH       0x4
    //         005445d1     XOR        EBX,EBX
    //         005445d3     PUSH       EAX
    //         005445d4     MOV        EBP,this
    //         005445d6     PUSH       ESI
    //         005445d7     MOV        dword ptr [world_update_counter],EBX
    //         005445dd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2630 (16)
    //         005445e2     MOV        EDI,dword ptr [EBP]
    //         005445e5     ADD        ESP,0xc
    //         005445e8     MOV        this,EBP
    //         005445ea     PUSH       EBP
    //         005445eb     PUSH       ESI
    //         005445ec     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:2633 (6)
    //         005445f2     PUSH       ESI
    //         005445f3     MOV        this,EBP
    //         005445f5     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:2635 (8)
    //         005445f8     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         005445fc     CMP        EDX,EBX
    //         005445fe     JLE        LAB_00544613
    //                               LAB_00544600                                                 XREF[1]:     00544611(j)  
    //                              World.cpp:2639 (19)
    //         00544600     MOV        this,0x9
    //         00544605     OR         EAX,0xffffffff
    //         00544608     LEA        EDI,[ESP + 0x4c]
    //         0054460c     CMP        EDX,0xa
    //         0054460f     STOSD.REP  ES:EDI
    //         00544611     JG         LAB_00544600
    //                               LAB_00544613                                                 XREF[1]:     005445fe(j)  
    //                              World.cpp:2642 (16)
    //         00544613     XOR        EAX,EAX
    //         00544615     CMP        EDX,EBX
    //         00544617     JLE        LAB_00544631
    //         00544619     MOV        this,dword ptr [ESP + 0x78]
    //         0054461d     ADD        this,0x270
    //                               LAB_00544623                                                 XREF[1]:     0054462f(j)  
    //                              World.cpp:2643 (14)
    //         00544623     MOV        EDI,dword ptr [this->_padding_]
    //         00544625     ADD        this,0x4
    //         00544628     MOV        dword ptr [ESP + EDI*0x4 + 0x4c],EAX
    //         0054462c     INC        EAX
    //         0054462d     CMP        EAX,EDX
    //         0054462f     JL         LAB_00544623
    //                               LAB_00544631                                                 XREF[1]:     00544617(j)  
    //                              World.cpp:2646 (6)
    //         00544631     XOR        EDI,EDI
    //         00544633     CMP        EDX,EBX
    //         00544635     JLE        LAB_0054464b
    //                               LAB_00544637                                                 XREF[1]:     00544649(j)  
    //                              World.cpp:2647 (20)
    //         00544637     MOV        EDX,dword ptr [EBP + 0x40]
    //         0054463a     MOV        this,dword ptr [EDX + EDI*0x4]
    //         0054463d     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00544642     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00544646     INC        EDI
    //         00544647     CMP        EDI,EAX
    //         00544649     JL         LAB_00544637
    //                               LAB_0054464b                                                 XREF[1]:     00544635(j)  
    //                              World.cpp:2655 (13)
    //         0054464b     LEA        this,[ESP + 0x14]
    //         0054464f     PUSH       0x4
    //         00544651     PUSH       this=>DAT_fffffff8
    //         00544652     PUSH       ESI=>DAT_fffffff4
    //         00544653     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2656 (13)
    //         00544658     MOV        EAX,dword ptr [ESP + 0x20]
    //         0054465c     ADD        ESP,0xc
    //         0054465f     XOR        EDI,EDI
    //         00544661     CMP        EAX,EBX
    //         00544663     JLE        LAB_0054468e
    //                               LAB_00544665                                                 XREF[1]:     0054468c(j)  
    //                              World.cpp:2659 (16)
    //         00544665     LEA        EDX,[ESP + 0x74]
    //         00544669     PUSH       0x1
    //         0054466b     PUSH       EDX=>DAT_fffffff8
    //         0054466c     PUSH       ESI=>DAT_fffffff4
    //         0054466d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544672     ADD        ESP,0xc
    //                              World.cpp:2660 (25)
    //         00544675     LEA        EAX,[ESP + 0x13]
    //         00544679     PUSH       0x1
    //         0054467b     PUSH       EAX=>DAT_fffffff8
    //         0054467c     PUSH       ESI=>DAT_fffffff4
    //         0054467d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544682     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544686     ADD        ESP,0xc
    //         00544689     INC        EDI
    //         0054468a     CMP        EDI,EAX
    //         0054468c     JL         LAB_00544665
    //                               LAB_0054468e                                                 XREF[1]:     00544663(j)  
    //                              World.cpp:2679 (16)
    //         0054468e     CMP        EAX,EBX
    //         00544690     MOV        dword ptr [ESP + 0x78],EBX
    //         00544694     JLE        LAB_00544796
    //         0054469a     LEA        EDI,[ESP + 0x4c]
    //                               LAB_0054469e                                                 XREF[1]:     00544790(j)  
    //                              World.cpp:2682 (13)
    //         0054469e     LEA        this,[ESP + 0x18]
    //         005446a2     PUSH       0x4
    //         005446a4     PUSH       this=>DAT_fffffff8
    //         005446a5     PUSH       ESI=>DAT_fffffff4
    //         005446a6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2683 (17)
    //         005446ab     MOV        EAX,dword ptr [ESP + 0x24]
    //         005446af     ADD        ESP,0xc
    //         005446b2     XOR        EBX,EBX
    //         005446b4     TEST       EAX,EAX
    //         005446b6     JLE        LAB_0054477e
    //                               LAB_005446bc                                                 XREF[1]:     00544778(j)  
    //                              World.cpp:2685 (16)
    //         005446bc     LEA        EDX,[ESP + 0x34]
    //         005446c0     PUSH       0x4
    //         005446c2     PUSH       EDX=>DAT_fffffff8
    //         005446c3     PUSH       ESI=>DAT_fffffff4
    //         005446c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005446c9     ADD        ESP,0xc
    //                              World.cpp:2686 (16)
    //         005446cc     LEA        EAX,[ESP + 0x30]
    //         005446d0     PUSH       0x4
    //         005446d2     PUSH       EAX=>DAT_fffffff8
    //         005446d3     PUSH       ESI=>DAT_fffffff4
    //         005446d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005446d9     ADD        ESP,0xc
    //                              World.cpp:2687 (16)
    //         005446dc     LEA        this,[ESP + 0x2c]
    //         005446e0     PUSH       0x4
    //         005446e2     PUSH       this=>DAT_fffffff8
    //         005446e3     PUSH       ESI=>DAT_fffffff4
    //         005446e4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005446e9     ADD        ESP,0xc
    //                              World.cpp:2688 (16)
    //         005446ec     LEA        EDX,[ESP + 0x1c]
    //         005446f0     PUSH       0x4
    //         005446f2     PUSH       EDX=>DAT_fffffff8
    //         005446f3     PUSH       ESI=>DAT_fffffff4
    //         005446f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005446f9     ADD        ESP,0xc
    //                              World.cpp:2689 (16)
    //         005446fc     LEA        EAX,[ESP + 0x28]
    //         00544700     PUSH       0x2
    //         00544702     PUSH       EAX=>DAT_fffffff8
    //         00544703     PUSH       ESI=>DAT_fffffff4
    //         00544704     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544709     ADD        ESP,0xc
    //                              World.cpp:2690 (16)
    //         0054470c     LEA        this,[ESP + 0x24]
    //         00544710     PUSH       0x1
    //         00544712     PUSH       this=>DAT_fffffff8
    //         00544713     PUSH       ESI=>DAT_fffffff4
    //         00544714     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544719     ADD        ESP,0xc
    //                              World.cpp:2691 (13)
    //         0054471c     LEA        EDX,[ESP + 0x20]
    //         00544720     PUSH       0x4
    //         00544722     PUSH       EDX=>DAT_fffffff8
    //         00544723     PUSH       ESI=>DAT_fffffff4
    //         00544724     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2692 (20)
    //         00544729     MOV        EAX,dword ptr [EDI]
    //         0054472b     ADD        ESP,0xc
    //         0054472e     TEST       EAX,EAX
    //         00544730     JL         LAB_00544771
    //         00544732     MOV        this,dword ptr [EBP + 0x40]
    //         00544735     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         00544738     CMP        dword ptr [EAX],0x0
    //         0054473b     JZ         LAB_00544771
    //                              World.cpp:2694 (4)
    //         0054473d     MOV        EDX,dword ptr [ESP + 0x1c]
    //                              World.cpp:2695 (7)
    //         00544741     MOV        byte ptr [EBP + 0x74],0x1
    //         00544745     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:2697 (37)
    //         00544748     MOV        EDX,dword ptr [ESP + 0x20]
    //         0054474c     PUSH       EDX
    //         0054474d     MOV        EDX,dword ptr [ESP + 0x28]
    //         00544751     MOV        this,dword ptr [EAX]
    //         00544753     PUSH       EDX=>DAT_fffffff8
    //         00544754     MOV        EDX,dword ptr [ESP + 0x30]
    //         00544758     MOV        EAX,dword ptr [this->_padding_]
    //         0054475a     PUSH       EDX=>DAT_fffffff4
    //         0054475b     MOV        EDX,dword ptr [ESP + 0x38]
    //         0054475f     PUSH       EDX=>DAT_fffffff0
    //         00544760     MOV        EDX,dword ptr [ESP + 0x40]
    //         00544764     PUSH       EDX
    //         00544765     MOV        EDX,dword ptr [ESP + 0x48]
    //         00544769     PUSH       EDX
    //         0054476a     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:2698 (17)
    //         0054476d     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_00544771                                                 XREF[2]:     00544730(j), 0054473b(j)  
    //         00544771     MOV        EAX,dword ptr [ESP + 0x18]
    //         00544775     INC        EBX
    //         00544776     CMP        EBX,EAX
    //         00544778     JL         LAB_005446bc
    //                               LAB_0054477e                                                 XREF[1]:     005446b6(j)  
    //                              World.cpp:2679 (24)
    //         0054477e     MOV        EAX,dword ptr [ESP + 0x78]
    //         00544782     MOV        this,dword ptr [ESP + 0x14]
    //         00544786     INC        EAX
    //         00544787     ADD        EDI,0x4
    //         0054478a     CMP        EAX,this
    //         0054478c     MOV        dword ptr [ESP + 0x78],EAX
    //         00544790     JL         LAB_0054469e
    //                               LAB_00544796                                                 XREF[1]:     00544694(j)  
    //                              World.cpp:2702 (4)
    //         00544796     MOV        EAX,dword ptr [ESP + 0x38]
    //                              World.cpp:2704 (16)
    //         0054479a     LEA        this,[ESP + 0x3c]
    //         0054479e     PUSH       0xd
    //         005447a0     PUSH       this=>DAT_fffffff8
    //         005447a1     PUSH       ESI=>DAT_fffffff4
    //         005447a2     MOV        dword ptr [EBP + 0x68],EAX
    //         005447a5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2706 (16)
    //         005447aa     MOV        EAX,dword ptr [ESP + 0x20]
    //         005447ae     MOV        EDI,0x1
    //         005447b3     ADD        ESP,0xc
    //         005447b6     CMP        EAX,EDI
    //         005447b8     JLE        LAB_005447f8
    //                              World.cpp:2702 (4)
    //         005447ba     LEA        EBX,[ESP + 0x50]
    //                               LAB_005447be                                                 XREF[1]:     005447f6(j)  
    //                              World.cpp:2708 (23)
    //         005447be     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         005447c2     CMP        EDI,EDX
    //         005447c4     JGE        LAB_005447d7
    //         005447c6     MOV        EAX,dword ptr [EBX]
    //         005447c8     CMP        EAX,-0x1
    //         005447cb     JLE        LAB_005447d7
    //         005447cd     MOV        this,dword ptr [EBP + 0x40]
    //         005447d0     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         005447d3     TEST       this,this
    //                              World.cpp:2710 (2)
    //         005447d5     JNZ        LAB_005447dc
    //                               LAB_005447d7                                                 XREF[2]:     005447c4(j), 005447cb(j)  
    //                              World.cpp:2711 (33)
    //         005447d7     MOV        this,dword ptr [EBP + 0x40]
    //         005447da     MOV        this,dword ptr [this->_padding_]
    //                               LAB_005447dc                                                 XREF[1]:     005447d5(j)  
    //         005447dc     MOV        EDX,dword ptr [this->_padding_]
    //         005447de     LEA        EAX,[ESP + 0x4c]
    //         005447e2     PUSH       0x3f83d70a
    //         005447e7     PUSH       EAX=>DAT_fffffff8
    //         005447e8     PUSH       ESI=>DAT_fffffff4
    //         005447e9     CALL       dword ptr [EDX + 0x68]
    //         005447ec     MOV        EAX,dword ptr [ESP + 0x14]
    //         005447f0     INC        EDI
    //         005447f1     ADD        EBX,0x4
    //         005447f4     CMP        EDI,EAX
    //         005447f6     JL         LAB_005447be
    //                               LAB_005447f8                                                 XREF[1]:     005447b8(j)  
    //                              World.cpp:2720 (6)
    //         005447f8     PUSH       ESI
    //         005447f9     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2721 (20)
    //         005447fe     MOV        EDI,0x1
    //         00544803     ADD        ESP,0x4
    //         00544806     CMP        word ptr [EBP + 0x3c],DI
    //         0054480a     JLE        LAB_00544872
    //                               LAB_0054480c                                                 XREF[1]:     00544870(j)  
    //         0054480c     CMP        EDI,dword ptr [ESP + 0x14]
    //         00544810     JGE        LAB_00544872
    //                              World.cpp:2722 (18)
    //         00544812     MOV        this,dword ptr [EBP + 0x40]
    //         00544815     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00544819     JZ         LAB_00544869
    //         0054481b     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x4c]
    //         0054481f     CMP        EAX,-0x1
    //         00544822     JLE        LAB_00544869
    //                              World.cpp:2725 (78)
    //         00544824     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544827     LEA        ESI,[EDI + -0x1]
    //         0054482a     PUSH       -0x1
    //         0054482c     PUSH       ESI=>DAT_fffffff8
    //         0054482d     MOV        EBX,dword ptr [this->_padding_]
    //         0054482f     MOV        this,dword ptr [EBP + 0x5c]
    //         00544832     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00544837     MOV        this,dword ptr [EBP + 0x5c]
    //         0054483a     PUSH       EAX=>DAT_fffffff8
    //         0054483b     PUSH       offset DAT_fffffff4
    //         0054483d     PUSH       ESI=>DAT_fffffff0
    //         0054483e     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00544843     MOV        this,dword ptr [EBP + 0x5c]
    //         00544846     PUSH       EAX=>DAT_fffffff4
    //         00544847     PUSH       offset DAT_fffffff0
    //         00544849     PUSH       ESI
    //         0054484a     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         0054484f     MOV        this,dword ptr [EBP + 0x5c]
    //         00544852     PUSH       EAX=>DAT_fffffff0
    //         00544853     PUSH       0x1
    //         00544855     PUSH       ESI
    //         00544856     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         0054485b     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x5c]
    //         0054485f     PUSH       EAX
    //         00544860     MOV        EAX,dword ptr [EBP + 0x40]
    //         00544863     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00544866     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_00544869                                                 XREF[2]:     00544819(j), 00544822(j)  
    //         00544869     MOVSX      this,word ptr [EBP + 0x3c]
    //         0054486d     INC        EDI
    //         0054486e     CMP        EDI,this
    //         00544870     JL         LAB_0054480c
    //                               LAB_00544872                                                 XREF[2]:     0054480a(j), 00544810(j)  
    //                              World.cpp:2729 (10)
    //         00544872     POP        EDI
    //         00544873     POP        ESI
    //         00544874     POP        EBP
    //         00544875     POP        EBX
    //         00544876     ADD        ESP,0x60
    //         00544879     RET        0x8
    //         0054487c     ??         90h
    //         0054487d     NOP
    //         0054487e     NOP
    //         0054487f     NOP
    return;
}

void RGE_Game_World::load_scenario3(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario3(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0054488a(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash
    //              char[13]          Stack[-0x38]   rem                       XREF[1]:     005448e7(*)  
    //              long              Stack[-0x3c]:4 obj_id
    //              float             Stack[-0x40]:4 world_x
    //              float             Stack[-0x44]:4 world_y
    //              float             Stack[-0x48]:4 world_z
    //              short             Stack[-0x4c]:2 master_id
    //              uchar             Stack[-0x50]:1 obj_state
    //              float             Stack[-0x54]:4 obj_angle
    //              long              Stack[-0x58]:4 id
    //              long              Stack[-0x5c]:4 count                     XREF[3]:     00544883(*), 005448a2(R), 005448cf(R)  
    //              long              Stack[-0x60]:4 header_size
    //              long              Stack[-0x64]:4 scenario_player_num
    //              uchar             Stack[-0x65]:1 master_player_id
    //                               ?load_scenario3@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774dc(*), 00577994(*)  
    //                               RGE_Game_World::load_scenario3
    //                              World.cpp:2733 (3)
    //         00544880     SUB        ESP,0x64
    //                              World.cpp:2756 (31)
    //         00544883     LEA        EAX=>count,[ESP + 0x8]
    //         00544887     PUSH       EBX
    //         00544888     PUSH       EBP
    //         00544889     PUSH       ESI
    //         0054488a     MOV        ESI,dword ptr [ESP + param_1]
    //         0054488e     PUSH       EDI
    //         0054488f     PUSH       0x4
    //         00544891     XOR        EBX,EBX
    //         00544893     PUSH       EAX
    //         00544894     MOV        EBP,this
    //         00544896     PUSH       ESI
    //         00544897     MOV        dword ptr [world_update_counter],EBX
    //         0054489d     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2757 (11)
    //         005448a2     MOV        EAX,dword ptr [ESP + count]
    //         005448a6     ADD        ESP,0xc
    //         005448a9     CMP        EAX,EBX
    //         005448ab     JLE        LAB_005448e7
    //                              World.cpp:2759 (11)
    //         005448ad     PUSH       EAX
    //         005448ae     CALL       malloc                                           undefined malloc()
    //         005448b3     MOV        EDI,EAX
    //         005448b5     ADD        ESP,0x4
    //                              World.cpp:2760 (4)
    //         005448b8     CMP        EDI,EBX
    //         005448ba     JNZ        LAB_005448cf
    //                              World.cpp:2762 (9)
    //         005448bc     PUSH       ESI
    //         005448bd     CALL       rge_close                                        int rge_close(int param_1)
    //         005448c2     ADD        ESP,0x4
    //                              World.cpp:2852 (10)
    //         005448c5     POP        EDI
    //         005448c6     POP        ESI
    //         005448c7     POP        EBP
    //         005448c8     POP        EBX
    //         005448c9     ADD        ESP,0x64
    //         005448cc     RET        0x8
    //                               LAB_005448cf                                                 XREF[1]:     005448ba(j)  
    //                              World.cpp:2765 (15)
    //         005448cf     MOV        this,dword ptr [ESP + count]
    //         005448d3     PUSH       this
    //         005448d4     PUSH       EDI
    //         005448d5     PUSH       ESI
    //         005448d6     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         005448db     ADD        ESP,0xc
    //                              World.cpp:2766 (9)
    //         005448de     PUSH       EDI
    //         005448df     CALL       free                                             undefined free()
    //         005448e4     ADD        ESP,0x4
    //                               LAB_005448e7                                                 XREF[1]:     005448ab(j)  
    //                              World.cpp:2770 (13)
    //         005448e7     LEA        EDX=>rem,[ESP + 0x3c]
    //         005448eb     PUSH       0x4
    //         005448ed     PUSH       EDX
    //         005448ee     PUSH       ESI
    //         005448ef     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2771 (16)
    //         005448f4     MOV        EDI,dword ptr [EBP]
    //         005448f7     ADD        ESP,0xc
    //         005448fa     MOV        this,EBP
    //         005448fc     PUSH       EBP
    //         005448fd     PUSH       ESI
    //         005448fe     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:2774 (6)
    //         00544904     PUSH       ESI
    //         00544905     MOV        this,EBP
    //         00544907     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:2776 (8)
    //         0054490a     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         0054490e     CMP        EDX,EBX
    //         00544910     JLE        LAB_00544925
    //                               LAB_00544912                                                 XREF[1]:     00544923(j)  
    //                              World.cpp:2780 (19)
    //         00544912     MOV        this,0x9
    //         00544917     OR         EAX,0xffffffff
    //         0054491a     LEA        EDI,[ESP + 0x50]
    //         0054491e     CMP        EDX,0xa
    //         00544921     STOSD.REP  ES:EDI
    //         00544923     JG         LAB_00544912
    //                               LAB_00544925                                                 XREF[1]:     00544910(j)  
    //                              World.cpp:2783 (16)
    //         00544925     XOR        EAX,EAX
    //         00544927     CMP        EDX,EBX
    //         00544929     JLE        LAB_00544943
    //         0054492b     MOV        this,dword ptr [ESP + 0x7c]
    //         0054492f     ADD        this,0x270
    //                               LAB_00544935                                                 XREF[1]:     00544941(j)  
    //                              World.cpp:2784 (14)
    //         00544935     MOV        EDI,dword ptr [this->_padding_]
    //         00544937     ADD        this,0x4
    //         0054493a     MOV        dword ptr [ESP + EDI*0x4 + 0x50],EAX
    //         0054493e     INC        EAX
    //         0054493f     CMP        EAX,EDX
    //         00544941     JL         LAB_00544935
    //                               LAB_00544943                                                 XREF[1]:     00544929(j)  
    //                              World.cpp:2788 (6)
    //         00544943     XOR        EDI,EDI
    //         00544945     CMP        EDX,EBX
    //         00544947     JLE        LAB_0054495d
    //                               LAB_00544949                                                 XREF[1]:     0054495b(j)  
    //                              World.cpp:2789 (20)
    //         00544949     MOV        EDX,dword ptr [EBP + 0x40]
    //         0054494c     MOV        this,dword ptr [EDX + EDI*0x4]
    //         0054494f     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00544954     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00544958     INC        EDI
    //         00544959     CMP        EDI,EAX
    //         0054495b     JL         LAB_00544949
    //                               LAB_0054495d                                                 XREF[1]:     00544947(j)  
    //                              World.cpp:2794 (13)
    //         0054495d     LEA        this,[ESP + 0x14]
    //         00544961     PUSH       0x4
    //         00544963     PUSH       this=>DAT_fffffff8
    //         00544964     PUSH       ESI=>DAT_fffffff4
    //         00544965     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2795 (13)
    //         0054496a     MOV        EAX,dword ptr [ESP + 0x20]
    //         0054496e     ADD        ESP,0xc
    //         00544971     XOR        EDI,EDI
    //         00544973     CMP        EAX,EBX
    //         00544975     JLE        LAB_005449a0
    //                               LAB_00544977                                                 XREF[1]:     0054499e(j)  
    //                              World.cpp:2798 (16)
    //         00544977     LEA        EDX,[ESP + 0x78]
    //         0054497b     PUSH       0x1
    //         0054497d     PUSH       EDX=>DAT_fffffff8
    //         0054497e     PUSH       ESI=>DAT_fffffff4
    //         0054497f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544984     ADD        ESP,0xc
    //                              World.cpp:2799 (25)
    //         00544987     LEA        EAX,[ESP + 0x13]
    //         0054498b     PUSH       0x1
    //         0054498d     PUSH       EAX=>DAT_fffffff8
    //         0054498e     PUSH       ESI=>DAT_fffffff4
    //         0054498f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544994     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544998     ADD        ESP,0xc
    //         0054499b     INC        EDI
    //         0054499c     CMP        EDI,EAX
    //         0054499e     JL         LAB_00544977
    //                               LAB_005449a0                                                 XREF[1]:     00544975(j)  
    //                              World.cpp:2802 (16)
    //         005449a0     CMP        EAX,EBX
    //         005449a2     MOV        dword ptr [ESP + 0x7c],EBX
    //         005449a6     JLE        LAB_00544aa8
    //         005449ac     LEA        EDI,[ESP + 0x50]
    //                               LAB_005449b0                                                 XREF[1]:     00544aa2(j)  
    //                              World.cpp:2805 (13)
    //         005449b0     LEA        this,[ESP + 0x1c]
    //         005449b4     PUSH       0x4
    //         005449b6     PUSH       this=>DAT_fffffff8
    //         005449b7     PUSH       ESI=>DAT_fffffff4
    //         005449b8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2806 (17)
    //         005449bd     MOV        EAX,dword ptr [ESP + 0x28]
    //         005449c1     ADD        ESP,0xc
    //         005449c4     XOR        EBX,EBX
    //         005449c6     TEST       EAX,EAX
    //         005449c8     JLE        LAB_00544a90
    //                               LAB_005449ce                                                 XREF[1]:     00544a8a(j)  
    //                              World.cpp:2808 (16)
    //         005449ce     LEA        EDX,[ESP + 0x38]
    //         005449d2     PUSH       0x4
    //         005449d4     PUSH       EDX=>DAT_fffffff8
    //         005449d5     PUSH       ESI=>DAT_fffffff4
    //         005449d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005449db     ADD        ESP,0xc
    //                              World.cpp:2809 (16)
    //         005449de     LEA        EAX,[ESP + 0x34]
    //         005449e2     PUSH       0x4
    //         005449e4     PUSH       EAX=>DAT_fffffff8
    //         005449e5     PUSH       ESI=>DAT_fffffff4
    //         005449e6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005449eb     ADD        ESP,0xc
    //                              World.cpp:2810 (16)
    //         005449ee     LEA        this,[ESP + 0x30]
    //         005449f2     PUSH       0x4
    //         005449f4     PUSH       this=>DAT_fffffff8
    //         005449f5     PUSH       ESI=>DAT_fffffff4
    //         005449f6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005449fb     ADD        ESP,0xc
    //                              World.cpp:2811 (16)
    //         005449fe     LEA        EDX,[ESP + 0x20]
    //         00544a02     PUSH       0x4
    //         00544a04     PUSH       EDX=>DAT_fffffff8
    //         00544a05     PUSH       ESI=>DAT_fffffff4
    //         00544a06     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544a0b     ADD        ESP,0xc
    //                              World.cpp:2812 (16)
    //         00544a0e     LEA        EAX,[ESP + 0x2c]
    //         00544a12     PUSH       0x2
    //         00544a14     PUSH       EAX=>DAT_fffffff8
    //         00544a15     PUSH       ESI=>DAT_fffffff4
    //         00544a16     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544a1b     ADD        ESP,0xc
    //                              World.cpp:2813 (16)
    //         00544a1e     LEA        this,[ESP + 0x28]
    //         00544a22     PUSH       0x1
    //         00544a24     PUSH       this=>DAT_fffffff8
    //         00544a25     PUSH       ESI=>DAT_fffffff4
    //         00544a26     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544a2b     ADD        ESP,0xc
    //                              World.cpp:2814 (13)
    //         00544a2e     LEA        EDX,[ESP + 0x24]
    //         00544a32     PUSH       0x4
    //         00544a34     PUSH       EDX=>DAT_fffffff8
    //         00544a35     PUSH       ESI=>DAT_fffffff4
    //         00544a36     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2815 (20)
    //         00544a3b     MOV        EAX,dword ptr [EDI]
    //         00544a3d     ADD        ESP,0xc
    //         00544a40     TEST       EAX,EAX
    //         00544a42     JL         LAB_00544a83
    //         00544a44     MOV        this,dword ptr [EBP + 0x40]
    //         00544a47     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         00544a4a     CMP        dword ptr [EAX],0x0
    //         00544a4d     JZ         LAB_00544a83
    //                              World.cpp:2817 (4)
    //         00544a4f     MOV        EDX,dword ptr [ESP + 0x20]
    //                              World.cpp:2818 (7)
    //         00544a53     MOV        byte ptr [EBP + 0x74],0x1
    //         00544a57     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:2820 (37)
    //         00544a5a     MOV        EDX,dword ptr [ESP + 0x24]
    //         00544a5e     PUSH       EDX
    //         00544a5f     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00544a63     MOV        this,dword ptr [EAX]
    //         00544a65     PUSH       EDX=>DAT_fffffff8
    //         00544a66     MOV        EDX,dword ptr [ESP + 0x34]
    //         00544a6a     MOV        EAX,dword ptr [this->_padding_]
    //         00544a6c     PUSH       EDX=>DAT_fffffff4
    //         00544a6d     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00544a71     PUSH       EDX=>DAT_fffffff0
    //         00544a72     MOV        EDX,dword ptr [ESP + 0x44]
    //         00544a76     PUSH       EDX
    //         00544a77     MOV        EDX,dword ptr [ESP + 0x4c]
    //         00544a7b     PUSH       EDX
    //         00544a7c     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:2821 (17)
    //         00544a7f     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_00544a83                                                 XREF[2]:     00544a42(j), 00544a4d(j)  
    //         00544a83     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00544a87     INC        EBX
    //         00544a88     CMP        EBX,EAX
    //         00544a8a     JL         LAB_005449ce
    //                               LAB_00544a90                                                 XREF[1]:     005449c8(j)  
    //                              World.cpp:2802 (24)
    //         00544a90     MOV        EAX,dword ptr [ESP + 0x7c]
    //         00544a94     MOV        this,dword ptr [ESP + 0x14]
    //         00544a98     INC        EAX
    //         00544a99     ADD        EDI,0x4
    //         00544a9c     CMP        EAX,this
    //         00544a9e     MOV        dword ptr [ESP + 0x7c],EAX
    //         00544aa2     JL         LAB_005449b0
    //                               LAB_00544aa8                                                 XREF[1]:     005449a6(j)  
    //                              World.cpp:2825 (4)
    //         00544aa8     MOV        EAX,dword ptr [ESP + 0x3c]
    //                              World.cpp:2827 (16)
    //         00544aac     LEA        this,[ESP + 0x40]
    //         00544ab0     PUSH       0xd
    //         00544ab2     PUSH       this=>DAT_fffffff8
    //         00544ab3     PUSH       ESI=>DAT_fffffff4
    //         00544ab4     MOV        dword ptr [EBP + 0x68],EAX
    //         00544ab7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2829 (16)
    //         00544abc     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544ac0     MOV        EDI,0x1
    //         00544ac5     ADD        ESP,0xc
    //         00544ac8     CMP        EAX,EDI
    //         00544aca     JLE        LAB_00544b0a
    //                              World.cpp:2825 (4)
    //         00544acc     LEA        EBX,[ESP + 0x54]
    //                               LAB_00544ad0                                                 XREF[1]:     00544b08(j)  
    //                              World.cpp:2831 (23)
    //         00544ad0     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00544ad4     CMP        EDI,EDX
    //         00544ad6     JGE        LAB_00544ae9
    //         00544ad8     MOV        EAX,dword ptr [EBX]
    //         00544ada     CMP        EAX,-0x1
    //         00544add     JLE        LAB_00544ae9
    //         00544adf     MOV        this,dword ptr [EBP + 0x40]
    //         00544ae2     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544ae5     TEST       this,this
    //                              World.cpp:2833 (2)
    //         00544ae7     JNZ        LAB_00544aee
    //                               LAB_00544ae9                                                 XREF[2]:     00544ad6(j), 00544add(j)  
    //                              World.cpp:2834 (33)
    //         00544ae9     MOV        this,dword ptr [EBP + 0x40]
    //         00544aec     MOV        this,dword ptr [this->_padding_]
    //                               LAB_00544aee                                                 XREF[1]:     00544ae7(j)  
    //         00544aee     MOV        EDX,dword ptr [this->_padding_]
    //         00544af0     LEA        EAX,[ESP + 0x50]
    //         00544af4     PUSH       0x3f851eb8
    //         00544af9     PUSH       EAX=>DAT_fffffff8
    //         00544afa     PUSH       ESI=>DAT_fffffff4
    //         00544afb     CALL       dword ptr [EDX + 0x68]
    //         00544afe     MOV        EAX,dword ptr [ESP + 0x14]
    //         00544b02     INC        EDI
    //         00544b03     ADD        EBX,0x4
    //         00544b06     CMP        EDI,EAX
    //         00544b08     JL         LAB_00544ad0
    //                               LAB_00544b0a                                                 XREF[1]:     00544aca(j)  
    //                              World.cpp:2843 (6)
    //         00544b0a     PUSH       ESI
    //         00544b0b     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2844 (20)
    //         00544b10     MOV        EDI,0x1
    //         00544b15     ADD        ESP,0x4
    //         00544b18     CMP        word ptr [EBP + 0x3c],DI
    //         00544b1c     JLE        LAB_00544b84
    //                               LAB_00544b1e                                                 XREF[1]:     00544b82(j)  
    //         00544b1e     CMP        EDI,dword ptr [ESP + 0x14]
    //         00544b22     JGE        LAB_00544b84
    //                              World.cpp:2845 (18)
    //         00544b24     MOV        this,dword ptr [EBP + 0x40]
    //         00544b27     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00544b2b     JZ         LAB_00544b7b
    //         00544b2d     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x50]
    //         00544b31     CMP        EAX,-0x1
    //         00544b34     JLE        LAB_00544b7b
    //                              World.cpp:2848 (78)
    //         00544b36     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544b39     LEA        ESI,[EDI + -0x1]
    //         00544b3c     PUSH       -0x1
    //         00544b3e     PUSH       ESI=>DAT_fffffff8
    //         00544b3f     MOV        EBX,dword ptr [this->_padding_]
    //         00544b41     MOV        this,dword ptr [EBP + 0x5c]
    //         00544b44     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00544b49     MOV        this,dword ptr [EBP + 0x5c]
    //         00544b4c     PUSH       EAX=>DAT_fffffff8
    //         00544b4d     PUSH       offset DAT_fffffff4
    //         00544b4f     PUSH       ESI=>DAT_fffffff0
    //         00544b50     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00544b55     MOV        this,dword ptr [EBP + 0x5c]
    //         00544b58     PUSH       EAX=>DAT_fffffff4
    //         00544b59     PUSH       offset DAT_fffffff0
    //         00544b5b     PUSH       ESI
    //         00544b5c     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         00544b61     MOV        this,dword ptr [EBP + 0x5c]
    //         00544b64     PUSH       EAX=>DAT_fffffff0
    //         00544b65     PUSH       0x1
    //         00544b67     PUSH       ESI
    //         00544b68     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         00544b6d     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x60]
    //         00544b71     PUSH       EAX
    //         00544b72     MOV        EAX,dword ptr [EBP + 0x40]
    //         00544b75     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00544b78     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_00544b7b                                                 XREF[2]:     00544b2b(j), 00544b34(j)  
    //         00544b7b     MOVSX      this,word ptr [EBP + 0x3c]
    //         00544b7f     INC        EDI
    //         00544b80     CMP        EDI,this
    //         00544b82     JL         LAB_00544b1e
    //                               LAB_00544b84                                                 XREF[2]:     00544b1c(j), 00544b22(j)  
    //                              World.cpp:2852 (10)
    //         00544b84     POP        EDI
    //         00544b85     POP        ESI
    //         00544b86     POP        EBP
    //         00544b87     POP        EBX
    //         00544b88     ADD        ESP,0x64
    //         00544b8b     RET        0x8
    //         00544b8e     ??         90h
    //         00544b8f     NOP
    return;
}

void RGE_Game_World::load_scenario4(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario4(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00544ba4(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash            XREF[1]:     00544bf9(*)  
    //              long              Stack[-0x2c]:4 obj_id
    //              float             Stack[-0x30]:4 world_x
    //              float             Stack[-0x34]:4 world_y
    //              float             Stack[-0x38]:4 world_z
    //              short             Stack[-0x3c]:2 master_id
    //              uchar             Stack[-0x40]:1 obj_state
    //              float             Stack[-0x44]:4 obj_angle
    //              long              Stack[-0x48]:4 id
    //              long              Stack[-0x4c]:4 count                     XREF[3]:     00544b93(*), 00544bb4(R), 00544be1(R)  
    //              long              Stack[-0x50]:4 header_size
    //                               ?load_scenario4@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774e0(*), 00577998(*)  
    //                               RGE_Game_World::load_scenario4
    //                              World.cpp:2856 (3)
    //         00544b90     SUB        ESP,0x4c
    //                              World.cpp:2876 (33)
    //         00544b93     LEA        EAX=>count,[ESP]
    //         00544b97     MOV        dword ptr [world_update_counter],0x0
    //         00544ba1     PUSH       EBX
    //         00544ba2     PUSH       EBP
    //         00544ba3     PUSH       ESI
    //         00544ba4     MOV        ESI,dword ptr [ESP + param_1]
    //         00544ba8     PUSH       EDI
    //         00544ba9     PUSH       0x4
    //         00544bab     PUSH       EAX
    //         00544bac     MOV        EBP,this
    //         00544bae     PUSH       ESI
    //         00544baf     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2877 (11)
    //         00544bb4     MOV        EAX,dword ptr [ESP + count]
    //         00544bb8     ADD        ESP,0xc
    //         00544bbb     TEST       EAX,EAX
    //         00544bbd     JLE        LAB_00544bf9
    //                              World.cpp:2879 (11)
    //         00544bbf     PUSH       EAX
    //         00544bc0     CALL       malloc                                           undefined malloc()
    //         00544bc5     MOV        EDI,EAX
    //         00544bc7     ADD        ESP,0x4
    //                              World.cpp:2880 (4)
    //         00544bca     TEST       EDI,EDI
    //         00544bcc     JNZ        LAB_00544be1
    //                              World.cpp:2882 (9)
    //         00544bce     PUSH       ESI
    //         00544bcf     CALL       rge_close                                        int rge_close(int param_1)
    //         00544bd4     ADD        ESP,0x4
    //                              World.cpp:2963 (10)
    //         00544bd7     POP        EDI
    //         00544bd8     POP        ESI
    //         00544bd9     POP        EBP
    //         00544bda     POP        EBX
    //         00544bdb     ADD        ESP,0x4c
    //         00544bde     RET        0x8
    //                               LAB_00544be1                                                 XREF[1]:     00544bcc(j)  
    //                              World.cpp:2885 (15)
    //         00544be1     MOV        this,dword ptr [ESP + count]
    //         00544be5     PUSH       this
    //         00544be6     PUSH       EDI
    //         00544be7     PUSH       ESI
    //         00544be8     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         00544bed     ADD        ESP,0xc
    //                              World.cpp:2886 (9)
    //         00544bf0     PUSH       EDI
    //         00544bf1     CALL       free                                             undefined free()
    //         00544bf6     ADD        ESP,0x4
    //                               LAB_00544bf9                                                 XREF[1]:     00544bbd(j)  
    //                              World.cpp:2890 (13)
    //         00544bf9     LEA        EDX=>player_id_hash,[ESP + 0x34]
    //         00544bfd     PUSH       0x4
    //         00544bff     PUSH       EDX
    //         00544c00     PUSH       ESI
    //         00544c01     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2891 (16)
    //         00544c06     MOV        EDI,dword ptr [EBP]
    //         00544c09     ADD        ESP,0xc
    //         00544c0c     MOV        this,EBP
    //         00544c0e     PUSH       EBP
    //         00544c0f     PUSH       ESI
    //         00544c10     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:2894 (6)
    //         00544c16     PUSH       ESI
    //         00544c17     MOV        this,EBP
    //         00544c19     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:2896 (8)
    //         00544c1c     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00544c20     TEST       EDX,EDX
    //         00544c22     JLE        LAB_00544c37
    //                               LAB_00544c24                                                 XREF[1]:     00544c35(j)  
    //                              World.cpp:2900 (19)
    //         00544c24     MOV        this,0x9
    //         00544c29     OR         EAX,0xffffffff
    //         00544c2c     LEA        EDI,[ESP + 0x38]
    //         00544c30     CMP        EDX,0xa
    //         00544c33     STOSD.REP  ES:EDI
    //         00544c35     JG         LAB_00544c24
    //                               LAB_00544c37                                                 XREF[1]:     00544c22(j)  
    //                              World.cpp:2903 (16)
    //         00544c37     XOR        EAX,EAX
    //         00544c39     TEST       EDX,EDX
    //         00544c3b     JLE        LAB_00544c55
    //         00544c3d     MOV        this,dword ptr [ESP + 0x64]
    //         00544c41     ADD        this,0x270
    //                               LAB_00544c47                                                 XREF[1]:     00544c53(j)  
    //                              World.cpp:2904 (14)
    //         00544c47     MOV        EDI,dword ptr [this->_padding_]
    //         00544c49     ADD        this,0x4
    //         00544c4c     MOV        dword ptr [ESP + EDI*0x4 + 0x38],EAX
    //         00544c50     INC        EAX
    //         00544c51     CMP        EAX,EDX
    //         00544c53     JL         LAB_00544c47
    //                               LAB_00544c55                                                 XREF[1]:     00544c3b(j)  
    //                              World.cpp:2908 (6)
    //         00544c55     XOR        EDI,EDI
    //         00544c57     TEST       EDX,EDX
    //         00544c59     JLE        LAB_00544c6f
    //                               LAB_00544c5b                                                 XREF[1]:     00544c6d(j)  
    //                              World.cpp:2909 (20)
    //         00544c5b     MOV        EDX,dword ptr [EBP + 0x40]
    //         00544c5e     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00544c61     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00544c66     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00544c6a     INC        EDI
    //         00544c6b     CMP        EDI,EAX
    //         00544c6d     JL         LAB_00544c5b
    //                               LAB_00544c6f                                                 XREF[1]:     00544c59(j)  
    //                              World.cpp:2914 (13)
    //         00544c6f     LEA        this,[ESP + 0x60]
    //         00544c73     PUSH       0x4
    //         00544c75     PUSH       this=>DAT_fffffff8
    //         00544c76     PUSH       ESI=>DAT_fffffff4
    //         00544c77     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2915 (16)
    //         00544c7c     MOV        EAX,dword ptr [ESP + 0x6c]
    //         00544c80     MOV        EDI,0x1
    //         00544c85     ADD        ESP,0xc
    //         00544c88     CMP        EAX,EDI
    //         00544c8a     JLE        LAB_00544cca
    //                              World.cpp:2914 (4)
    //         00544c8c     LEA        EBX,[ESP + 0x3c]
    //                               LAB_00544c90                                                 XREF[1]:     00544cc8(j)  
    //                              World.cpp:2917 (23)
    //         00544c90     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00544c94     CMP        EDI,EDX
    //         00544c96     JGE        LAB_00544ca9
    //         00544c98     MOV        EAX,dword ptr [EBX]
    //         00544c9a     CMP        EAX,-0x1
    //         00544c9d     JLE        LAB_00544ca9
    //         00544c9f     MOV        this,dword ptr [EBP + 0x40]
    //         00544ca2     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544ca5     TEST       this,this
    //                              World.cpp:2919 (2)
    //         00544ca7     JNZ        LAB_00544cae
    //                               LAB_00544ca9                                                 XREF[2]:     00544c96(j), 00544c9d(j)  
    //                              World.cpp:2920 (33)
    //         00544ca9     MOV        this,dword ptr [EBP + 0x40]
    //         00544cac     MOV        this,dword ptr [this->_padding_]
    //                               LAB_00544cae                                                 XREF[1]:     00544ca7(j)  
    //         00544cae     MOV        EDX,dword ptr [this->_padding_]
    //         00544cb0     LEA        EAX,[ESP + 0x38]
    //         00544cb4     PUSH       0x3f851eb8
    //         00544cb9     PUSH       EAX=>DAT_fffffff8
    //         00544cba     PUSH       ESI=>DAT_fffffff4
    //         00544cbb     CALL       dword ptr [EDX + 0x68]
    //         00544cbe     MOV        EAX,dword ptr [ESP + 0x60]
    //         00544cc2     INC        EDI
    //         00544cc3     ADD        EBX,0x4
    //         00544cc6     CMP        EDI,EAX
    //         00544cc8     JL         LAB_00544c90
    //                               LAB_00544cca                                                 XREF[1]:     00544c8a(j)  
    //                              World.cpp:2923 (20)
    //         00544cca     TEST       EAX,EAX
    //         00544ccc     MOV        dword ptr [ESP + 0x64],0x0
    //         00544cd4     JLE        LAB_00544dd6
    //         00544cda     LEA        EDI,[ESP + 0x38]
    //                               LAB_00544cde                                                 XREF[1]:     00544dd0(j)  
    //                              World.cpp:2926 (13)
    //         00544cde     LEA        this,[ESP + 0x14]
    //         00544ce2     PUSH       0x4
    //         00544ce4     PUSH       this=>DAT_fffffff8
    //         00544ce5     PUSH       ESI=>DAT_fffffff4
    //         00544ce6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2927 (17)
    //         00544ceb     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544cef     ADD        ESP,0xc
    //         00544cf2     XOR        EBX,EBX
    //         00544cf4     TEST       EAX,EAX
    //         00544cf6     JLE        LAB_00544dbe
    //                               LAB_00544cfc                                                 XREF[1]:     00544db8(j)  
    //                              World.cpp:2929 (16)
    //         00544cfc     LEA        EDX,[ESP + 0x30]
    //         00544d00     PUSH       0x4
    //         00544d02     PUSH       EDX=>DAT_fffffff8
    //         00544d03     PUSH       ESI=>DAT_fffffff4
    //         00544d04     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d09     ADD        ESP,0xc
    //                              World.cpp:2930 (16)
    //         00544d0c     LEA        EAX,[ESP + 0x2c]
    //         00544d10     PUSH       0x4
    //         00544d12     PUSH       EAX=>DAT_fffffff8
    //         00544d13     PUSH       ESI=>DAT_fffffff4
    //         00544d14     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d19     ADD        ESP,0xc
    //                              World.cpp:2931 (16)
    //         00544d1c     LEA        this,[ESP + 0x28]
    //         00544d20     PUSH       0x4
    //         00544d22     PUSH       this=>DAT_fffffff8
    //         00544d23     PUSH       ESI=>DAT_fffffff4
    //         00544d24     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d29     ADD        ESP,0xc
    //                              World.cpp:2932 (16)
    //         00544d2c     LEA        EDX,[ESP + 0x18]
    //         00544d30     PUSH       0x4
    //         00544d32     PUSH       EDX=>DAT_fffffff8
    //         00544d33     PUSH       ESI=>DAT_fffffff4
    //         00544d34     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d39     ADD        ESP,0xc
    //                              World.cpp:2933 (16)
    //         00544d3c     LEA        EAX,[ESP + 0x24]
    //         00544d40     PUSH       0x2
    //         00544d42     PUSH       EAX=>DAT_fffffff8
    //         00544d43     PUSH       ESI=>DAT_fffffff4
    //         00544d44     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d49     ADD        ESP,0xc
    //                              World.cpp:2934 (16)
    //         00544d4c     LEA        this,[ESP + 0x20]
    //         00544d50     PUSH       0x1
    //         00544d52     PUSH       this=>DAT_fffffff8
    //         00544d53     PUSH       ESI=>DAT_fffffff4
    //         00544d54     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544d59     ADD        ESP,0xc
    //                              World.cpp:2935 (13)
    //         00544d5c     LEA        EDX,[ESP + 0x1c]
    //         00544d60     PUSH       0x4
    //         00544d62     PUSH       EDX=>DAT_fffffff8
    //         00544d63     PUSH       ESI=>DAT_fffffff4
    //         00544d64     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:2936 (20)
    //         00544d69     MOV        EAX,dword ptr [EDI]
    //         00544d6b     ADD        ESP,0xc
    //         00544d6e     TEST       EAX,EAX
    //         00544d70     JL         LAB_00544db1
    //         00544d72     MOV        this,dword ptr [EBP + 0x40]
    //         00544d75     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         00544d78     CMP        dword ptr [EAX],0x0
    //         00544d7b     JZ         LAB_00544db1
    //                              World.cpp:2938 (4)
    //         00544d7d     MOV        EDX,dword ptr [ESP + 0x18]
    //                              World.cpp:2939 (7)
    //         00544d81     MOV        byte ptr [EBP + 0x74],0x1
    //         00544d85     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:2941 (37)
    //         00544d88     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00544d8c     PUSH       EDX
    //         00544d8d     MOV        EDX,dword ptr [ESP + 0x24]
    //         00544d91     MOV        this,dword ptr [EAX]
    //         00544d93     PUSH       EDX=>DAT_fffffff8
    //         00544d94     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00544d98     MOV        EAX,dword ptr [this->_padding_]
    //         00544d9a     PUSH       EDX=>DAT_fffffff4
    //         00544d9b     MOV        EDX,dword ptr [ESP + 0x34]
    //         00544d9f     PUSH       EDX=>DAT_fffffff0
    //         00544da0     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00544da4     PUSH       EDX
    //         00544da5     MOV        EDX,dword ptr [ESP + 0x44]
    //         00544da9     PUSH       EDX
    //         00544daa     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:2942 (17)
    //         00544dad     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_00544db1                                                 XREF[2]:     00544d70(j), 00544d7b(j)  
    //         00544db1     MOV        EAX,dword ptr [ESP + 0x14]
    //         00544db5     INC        EBX
    //         00544db6     CMP        EBX,EAX
    //         00544db8     JL         LAB_00544cfc
    //                               LAB_00544dbe                                                 XREF[1]:     00544cf6(j)  
    //                              World.cpp:2923 (24)
    //         00544dbe     MOV        EAX,dword ptr [ESP + 0x64]
    //         00544dc2     MOV        this,dword ptr [ESP + 0x60]
    //         00544dc6     INC        EAX
    //         00544dc7     ADD        EDI,0x4
    //         00544dca     CMP        EAX,this
    //         00544dcc     MOV        dword ptr [ESP + 0x64],EAX
    //         00544dd0     JL         LAB_00544cde
    //                               LAB_00544dd6                                                 XREF[1]:     00544cd4(j)  
    //                              World.cpp:2946 (4)
    //         00544dd6     MOV        EAX,dword ptr [ESP + 0x34]
    //                              World.cpp:2954 (9)
    //         00544dda     PUSH       ESI
    //         00544ddb     MOV        dword ptr [EBP + 0x68],EAX
    //         00544dde     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:2955 (20)
    //         00544de3     MOV        EDI,0x1
    //         00544de8     ADD        ESP,0x4
    //         00544deb     CMP        word ptr [EBP + 0x3c],DI
    //         00544def     JLE        LAB_00544e57
    //                               LAB_00544df1                                                 XREF[1]:     00544e55(j)  
    //         00544df1     CMP        EDI,dword ptr [ESP + 0x60]
    //         00544df5     JGE        LAB_00544e57
    //                              World.cpp:2956 (18)
    //         00544df7     MOV        this,dword ptr [EBP + 0x40]
    //         00544dfa     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00544dfe     JZ         LAB_00544e4e
    //         00544e00     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x38]
    //         00544e04     CMP        EAX,-0x1
    //         00544e07     JLE        LAB_00544e4e
    //                              World.cpp:2959 (78)
    //         00544e09     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544e0c     LEA        ESI,[EDI + -0x1]
    //         00544e0f     PUSH       -0x1
    //         00544e11     PUSH       ESI=>DAT_fffffff8
    //         00544e12     MOV        EBX,dword ptr [this->_padding_]
    //         00544e14     MOV        this,dword ptr [EBP + 0x5c]
    //         00544e17     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00544e1c     MOV        this,dword ptr [EBP + 0x5c]
    //         00544e1f     PUSH       EAX=>DAT_fffffff8
    //         00544e20     PUSH       offset DAT_fffffff4
    //         00544e22     PUSH       ESI=>DAT_fffffff0
    //         00544e23     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00544e28     MOV        this,dword ptr [EBP + 0x5c]
    //         00544e2b     PUSH       EAX=>DAT_fffffff4
    //         00544e2c     PUSH       offset DAT_fffffff0
    //         00544e2e     PUSH       ESI
    //         00544e2f     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         00544e34     MOV        this,dword ptr [EBP + 0x5c]
    //         00544e37     PUSH       EAX=>DAT_fffffff0
    //         00544e38     PUSH       0x1
    //         00544e3a     PUSH       ESI
    //         00544e3b     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         00544e40     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x48]
    //         00544e44     PUSH       EAX
    //         00544e45     MOV        EAX,dword ptr [EBP + 0x40]
    //         00544e48     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00544e4b     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_00544e4e                                                 XREF[2]:     00544dfe(j), 00544e07(j)  
    //         00544e4e     MOVSX      this,word ptr [EBP + 0x3c]
    //         00544e52     INC        EDI
    //         00544e53     CMP        EDI,this
    //         00544e55     JL         LAB_00544df1
    //                               LAB_00544e57                                                 XREF[2]:     00544def(j), 00544df5(j)  
    //                              World.cpp:2963 (10)
    //         00544e57     POP        EDI
    //         00544e58     POP        ESI
    //         00544e59     POP        EBP
    //         00544e5a     POP        EBX
    //         00544e5b     ADD        ESP,0x4c
    //         00544e5e     RET        0x8
    //         00544e61     ??         90h
    //         00544e62     NOP
    //         00544e63     NOP
    //         00544e64     NOP
    //         00544e65     NOP
    //         00544e66     NOP
    //         00544e67     NOP
    //         00544e68     NOP
    //         00544e69     NOP
    //         00544e6a     NOP
    //         00544e6b     NOP
    //         00544e6c     NOP
    //         00544e6d     NOP
    //         00544e6e     NOP
    //         00544e6f     NOP
    return;
}

void RGE_Game_World::load_scenario5(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario5(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00544e84(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash            XREF[1]:     00544ed9(*)  
    //              long              Stack[-0x2c]:4 obj_id
    //              float             Stack[-0x30]:4 world_x
    //              float             Stack[-0x34]:4 world_y
    //              float             Stack[-0x38]:4 world_z
    //              short             Stack[-0x3c]:2 master_id
    //              uchar             Stack[-0x40]:1 obj_state
    //              float             Stack[-0x44]:4 obj_angle
    //              long              Stack[-0x48]:4 id
    //              long              Stack[-0x4c]:4 count                     XREF[3]:     00544e73(*), 00544e94(R), 00544ec1(R)  
    //              long              Stack[-0x50]:4 header_size
    //                               ?load_scenario5@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774e4(*), 0057799c(*)  
    //                               RGE_Game_World::load_scenario5
    //                              World.cpp:2967 (3)
    //         00544e70     SUB        ESP,0x4c
    //                              World.cpp:2987 (33)
    //         00544e73     LEA        EAX=>count,[ESP]
    //         00544e77     MOV        dword ptr [world_update_counter],0x0
    //         00544e81     PUSH       EBX
    //         00544e82     PUSH       EBP
    //         00544e83     PUSH       ESI
    //         00544e84     MOV        ESI,dword ptr [ESP + param_1]
    //         00544e88     PUSH       EDI
    //         00544e89     PUSH       0x4
    //         00544e8b     PUSH       EAX
    //         00544e8c     MOV        EBP,this
    //         00544e8e     PUSH       ESI
    //         00544e8f     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:2988 (11)
    //         00544e94     MOV        EAX,dword ptr [ESP + count]
    //         00544e98     ADD        ESP,0xc
    //         00544e9b     TEST       EAX,EAX
    //         00544e9d     JLE        LAB_00544ed9
    //                              World.cpp:2990 (11)
    //         00544e9f     PUSH       EAX
    //         00544ea0     CALL       malloc                                           undefined malloc()
    //         00544ea5     MOV        EDI,EAX
    //         00544ea7     ADD        ESP,0x4
    //                              World.cpp:2991 (4)
    //         00544eaa     TEST       EDI,EDI
    //         00544eac     JNZ        LAB_00544ec1
    //                              World.cpp:2993 (9)
    //         00544eae     PUSH       ESI
    //         00544eaf     CALL       rge_close                                        int rge_close(int param_1)
    //         00544eb4     ADD        ESP,0x4
    //                              World.cpp:3085 (10)
    //         00544eb7     POP        EDI
    //         00544eb8     POP        ESI
    //         00544eb9     POP        EBP
    //         00544eba     POP        EBX
    //         00544ebb     ADD        ESP,0x4c
    //         00544ebe     RET        0x8
    //                               LAB_00544ec1                                                 XREF[1]:     00544eac(j)  
    //                              World.cpp:2996 (15)
    //         00544ec1     MOV        this,dword ptr [ESP + count]
    //         00544ec5     PUSH       this
    //         00544ec6     PUSH       EDI
    //         00544ec7     PUSH       ESI
    //         00544ec8     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         00544ecd     ADD        ESP,0xc
    //                              World.cpp:2997 (9)
    //         00544ed0     PUSH       EDI
    //         00544ed1     CALL       free                                             undefined free()
    //         00544ed6     ADD        ESP,0x4
    //                               LAB_00544ed9                                                 XREF[1]:     00544e9d(j)  
    //                              World.cpp:3001 (13)
    //         00544ed9     LEA        EDX=>player_id_hash,[ESP + 0x34]
    //         00544edd     PUSH       0x4
    //         00544edf     PUSH       EDX
    //         00544ee0     PUSH       ESI
    //         00544ee1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3002 (16)
    //         00544ee6     MOV        EDI,dword ptr [EBP]
    //         00544ee9     ADD        ESP,0xc
    //         00544eec     MOV        this,EBP
    //         00544eee     PUSH       EBP
    //         00544eef     PUSH       ESI
    //         00544ef0     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:3005 (6)
    //         00544ef6     PUSH       ESI
    //         00544ef7     MOV        this,EBP
    //         00544ef9     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:3007 (8)
    //         00544efc     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00544f00     TEST       EDX,EDX
    //         00544f02     JLE        LAB_00544f17
    //                               LAB_00544f04                                                 XREF[1]:     00544f15(j)  
    //                              World.cpp:3011 (19)
    //         00544f04     MOV        this,0x9
    //         00544f09     OR         EAX,0xffffffff
    //         00544f0c     LEA        EDI,[ESP + 0x38]
    //         00544f10     CMP        EDX,0xa
    //         00544f13     STOSD.REP  ES:EDI
    //         00544f15     JG         LAB_00544f04
    //                               LAB_00544f17                                                 XREF[1]:     00544f02(j)  
    //                              World.cpp:3014 (16)
    //         00544f17     XOR        EAX,EAX
    //         00544f19     TEST       EDX,EDX
    //         00544f1b     JLE        LAB_00544f35
    //         00544f1d     MOV        this,dword ptr [ESP + 0x64]
    //         00544f21     ADD        this,0x270
    //                               LAB_00544f27                                                 XREF[1]:     00544f33(j)  
    //                              World.cpp:3015 (14)
    //         00544f27     MOV        EDI,dword ptr [this->_padding_]
    //         00544f29     ADD        this,0x4
    //         00544f2c     MOV        dword ptr [ESP + EDI*0x4 + 0x38],EAX
    //         00544f30     INC        EAX
    //         00544f31     CMP        EAX,EDX
    //         00544f33     JL         LAB_00544f27
    //                               LAB_00544f35                                                 XREF[1]:     00544f1b(j)  
    //                              World.cpp:3019 (6)
    //         00544f35     XOR        EDI,EDI
    //         00544f37     TEST       EDX,EDX
    //         00544f39     JLE        LAB_00544f4f
    //                               LAB_00544f3b                                                 XREF[1]:     00544f4d(j)  
    //                              World.cpp:3020 (20)
    //         00544f3b     MOV        EDX,dword ptr [EBP + 0x40]
    //         00544f3e     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00544f41     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00544f46     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         00544f4a     INC        EDI
    //         00544f4b     CMP        EDI,EAX
    //         00544f4d     JL         LAB_00544f3b
    //                               LAB_00544f4f                                                 XREF[1]:     00544f39(j)  
    //                              World.cpp:3025 (13)
    //         00544f4f     LEA        this,[ESP + 0x60]
    //         00544f53     PUSH       0x4
    //         00544f55     PUSH       this=>DAT_fffffff8
    //         00544f56     PUSH       ESI=>DAT_fffffff4
    //         00544f57     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3026 (16)
    //         00544f5c     MOV        EAX,dword ptr [ESP + 0x6c]
    //         00544f60     MOV        EDI,0x1
    //         00544f65     ADD        ESP,0xc
    //         00544f68     CMP        EAX,EDI
    //         00544f6a     JLE        LAB_00544faa
    //                              World.cpp:3025 (4)
    //         00544f6c     LEA        EBX,[ESP + 0x3c]
    //                               LAB_00544f70                                                 XREF[1]:     00544fa8(j)  
    //                              World.cpp:3028 (23)
    //         00544f70     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00544f74     CMP        EDI,EDX
    //         00544f76     JGE        LAB_00544f89
    //         00544f78     MOV        EAX,dword ptr [EBX]
    //         00544f7a     CMP        EAX,-0x1
    //         00544f7d     JLE        LAB_00544f89
    //         00544f7f     MOV        this,dword ptr [EBP + 0x40]
    //         00544f82     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00544f85     TEST       this,this
    //                              World.cpp:3030 (2)
    //         00544f87     JNZ        LAB_00544f8e
    //                               LAB_00544f89                                                 XREF[2]:     00544f76(j), 00544f7d(j)  
    //                              World.cpp:3031 (33)
    //         00544f89     MOV        this,dword ptr [EBP + 0x40]
    //         00544f8c     MOV        this,dword ptr [this->_padding_]
    //                               LAB_00544f8e                                                 XREF[1]:     00544f87(j)  
    //         00544f8e     MOV        EDX,dword ptr [this->_padding_]
    //         00544f90     LEA        EAX,[ESP + 0x38]
    //         00544f94     PUSH       0x3f87ae14
    //         00544f99     PUSH       EAX=>DAT_fffffff8
    //         00544f9a     PUSH       ESI=>DAT_fffffff4
    //         00544f9b     CALL       dword ptr [EDX + 0x68]
    //         00544f9e     MOV        EAX,dword ptr [ESP + 0x60]
    //         00544fa2     INC        EDI
    //         00544fa3     ADD        EBX,0x4
    //         00544fa6     CMP        EDI,EAX
    //         00544fa8     JL         LAB_00544f70
    //                               LAB_00544faa                                                 XREF[1]:     00544f6a(j)  
    //                              World.cpp:3034 (20)
    //         00544faa     TEST       EAX,EAX
    //         00544fac     MOV        dword ptr [ESP + 0x64],0x0
    //         00544fb4     JLE        LAB_005450b6
    //         00544fba     LEA        EDI,[ESP + 0x38]
    //                               LAB_00544fbe                                                 XREF[1]:     005450b0(j)  
    //                              World.cpp:3037 (13)
    //         00544fbe     LEA        this,[ESP + 0x14]
    //         00544fc2     PUSH       0x4
    //         00544fc4     PUSH       this=>DAT_fffffff8
    //         00544fc5     PUSH       ESI=>DAT_fffffff4
    //         00544fc6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3038 (17)
    //         00544fcb     MOV        EAX,dword ptr [ESP + 0x20]
    //         00544fcf     ADD        ESP,0xc
    //         00544fd2     XOR        EBX,EBX
    //         00544fd4     TEST       EAX,EAX
    //         00544fd6     JLE        LAB_0054509e
    //                               LAB_00544fdc                                                 XREF[1]:     00545098(j)  
    //                              World.cpp:3040 (16)
    //         00544fdc     LEA        EDX,[ESP + 0x30]
    //         00544fe0     PUSH       0x4
    //         00544fe2     PUSH       EDX=>DAT_fffffff8
    //         00544fe3     PUSH       ESI=>DAT_fffffff4
    //         00544fe4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544fe9     ADD        ESP,0xc
    //                              World.cpp:3041 (16)
    //         00544fec     LEA        EAX,[ESP + 0x2c]
    //         00544ff0     PUSH       0x4
    //         00544ff2     PUSH       EAX=>DAT_fffffff8
    //         00544ff3     PUSH       ESI=>DAT_fffffff4
    //         00544ff4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00544ff9     ADD        ESP,0xc
    //                              World.cpp:3042 (16)
    //         00544ffc     LEA        this,[ESP + 0x28]
    //         00545000     PUSH       0x4
    //         00545002     PUSH       this=>DAT_fffffff8
    //         00545003     PUSH       ESI=>DAT_fffffff4
    //         00545004     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545009     ADD        ESP,0xc
    //                              World.cpp:3043 (16)
    //         0054500c     LEA        EDX,[ESP + 0x18]
    //         00545010     PUSH       0x4
    //         00545012     PUSH       EDX=>DAT_fffffff8
    //         00545013     PUSH       ESI=>DAT_fffffff4
    //         00545014     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545019     ADD        ESP,0xc
    //                              World.cpp:3044 (16)
    //         0054501c     LEA        EAX,[ESP + 0x24]
    //         00545020     PUSH       0x2
    //         00545022     PUSH       EAX=>DAT_fffffff8
    //         00545023     PUSH       ESI=>DAT_fffffff4
    //         00545024     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545029     ADD        ESP,0xc
    //                              World.cpp:3045 (16)
    //         0054502c     LEA        this,[ESP + 0x20]
    //         00545030     PUSH       0x1
    //         00545032     PUSH       this=>DAT_fffffff8
    //         00545033     PUSH       ESI=>DAT_fffffff4
    //         00545034     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545039     ADD        ESP,0xc
    //                              World.cpp:3046 (13)
    //         0054503c     LEA        EDX,[ESP + 0x1c]
    //         00545040     PUSH       0x4
    //         00545042     PUSH       EDX=>DAT_fffffff8
    //         00545043     PUSH       ESI=>DAT_fffffff4
    //         00545044     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3047 (20)
    //         00545049     MOV        EAX,dword ptr [EDI]
    //         0054504b     ADD        ESP,0xc
    //         0054504e     TEST       EAX,EAX
    //         00545050     JL         LAB_00545091
    //         00545052     MOV        this,dword ptr [EBP + 0x40]
    //         00545055     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         00545058     CMP        dword ptr [EAX],0x0
    //         0054505b     JZ         LAB_00545091
    //                              World.cpp:3049 (4)
    //         0054505d     MOV        EDX,dword ptr [ESP + 0x18]
    //                              World.cpp:3050 (7)
    //         00545061     MOV        byte ptr [EBP + 0x74],0x1
    //         00545065     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:3052 (37)
    //         00545068     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0054506c     PUSH       EDX
    //         0054506d     MOV        EDX,dword ptr [ESP + 0x24]
    //         00545071     MOV        this,dword ptr [EAX]
    //         00545073     PUSH       EDX=>DAT_fffffff8
    //         00545074     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00545078     MOV        EAX,dword ptr [this->_padding_]
    //         0054507a     PUSH       EDX=>DAT_fffffff4
    //         0054507b     MOV        EDX,dword ptr [ESP + 0x34]
    //         0054507f     PUSH       EDX=>DAT_fffffff0
    //         00545080     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00545084     PUSH       EDX
    //         00545085     MOV        EDX,dword ptr [ESP + 0x44]
    //         00545089     PUSH       EDX
    //         0054508a     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:3054 (17)
    //         0054508d     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_00545091                                                 XREF[2]:     00545050(j), 0054505b(j)  
    //         00545091     MOV        EAX,dword ptr [ESP + 0x14]
    //         00545095     INC        EBX
    //         00545096     CMP        EBX,EAX
    //         00545098     JL         LAB_00544fdc
    //                               LAB_0054509e                                                 XREF[1]:     00544fd6(j)  
    //                              World.cpp:3034 (24)
    //         0054509e     MOV        EAX,dword ptr [ESP + 0x64]
    //         005450a2     MOV        this,dword ptr [ESP + 0x60]
    //         005450a6     INC        EAX
    //         005450a7     ADD        EDI,0x4
    //         005450aa     CMP        EAX,this
    //         005450ac     MOV        dword ptr [ESP + 0x64],EAX
    //         005450b0     JL         LAB_00544fbe
    //                               LAB_005450b6                                                 XREF[1]:     00544fb4(j)  
    //                              World.cpp:3058 (4)
    //         005450b6     MOV        EAX,dword ptr [ESP + 0x34]
    //                              World.cpp:3061 (16)
    //         005450ba     LEA        this,[ESP + 0x60]
    //         005450be     PUSH       0x4
    //         005450c0     PUSH       this=>DAT_fffffff8
    //         005450c1     PUSH       ESI=>DAT_fffffff4
    //         005450c2     MOV        dword ptr [EBP + 0x68],EAX
    //         005450c5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3062 (16)
    //         005450ca     MOV        EAX,dword ptr [ESP + 0x6c]
    //         005450ce     MOV        EDI,0x1
    //         005450d3     ADD        ESP,0xc
    //         005450d6     CMP        EAX,EDI
    //         005450d8     JLE        LAB_00545118
    //                              World.cpp:3058 (4)
    //         005450da     LEA        EBX,[ESP + 0x3c]
    //                               LAB_005450de                                                 XREF[1]:     00545116(j)  
    //                              World.cpp:3064 (23)
    //         005450de     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         005450e2     CMP        EDI,EDX
    //         005450e4     JGE        LAB_005450f7
    //         005450e6     MOV        EAX,dword ptr [EBX]
    //         005450e8     CMP        EAX,-0x1
    //         005450eb     JLE        LAB_005450f7
    //         005450ed     MOV        this,dword ptr [EBP + 0x40]
    //         005450f0     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         005450f3     TEST       this,this
    //                              World.cpp:3066 (2)
    //         005450f5     JNZ        LAB_005450fc
    //                               LAB_005450f7                                                 XREF[2]:     005450e4(j), 005450eb(j)  
    //                              World.cpp:3067 (33)
    //         005450f7     MOV        this,dword ptr [EBP + 0x40]
    //         005450fa     MOV        this,dword ptr [this->_padding_]
    //                               LAB_005450fc                                                 XREF[1]:     005450f5(j)  
    //         005450fc     MOV        EDX,dword ptr [this->_padding_]
    //         005450fe     LEA        EAX,[ESP + 0x38]
    //         00545102     PUSH       0x3f87ae14
    //         00545107     PUSH       EAX=>DAT_fffffff8
    //         00545108     PUSH       ESI=>DAT_fffffff4
    //         00545109     CALL       dword ptr [EDX + 0x70]
    //         0054510c     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545110     INC        EDI
    //         00545111     ADD        EBX,0x4
    //         00545114     CMP        EDI,EAX
    //         00545116     JL         LAB_005450de
    //                               LAB_00545118                                                 XREF[1]:     005450d8(j)  
    //                              World.cpp:3076 (6)
    //         00545118     PUSH       ESI
    //         00545119     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:3077 (20)
    //         0054511e     MOV        EDI,0x1
    //         00545123     ADD        ESP,0x4
    //         00545126     CMP        word ptr [EBP + 0x3c],DI
    //         0054512a     JLE        LAB_00545192
    //                               LAB_0054512c                                                 XREF[1]:     00545190(j)  
    //         0054512c     CMP        EDI,dword ptr [ESP + 0x60]
    //         00545130     JGE        LAB_00545192
    //                              World.cpp:3078 (18)
    //         00545132     MOV        this,dword ptr [EBP + 0x40]
    //         00545135     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00545139     JZ         LAB_00545189
    //         0054513b     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x38]
    //         0054513f     CMP        EAX,-0x1
    //         00545142     JLE        LAB_00545189
    //                              World.cpp:3081 (78)
    //         00545144     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545147     LEA        ESI,[EDI + -0x1]
    //         0054514a     PUSH       -0x1
    //         0054514c     PUSH       ESI=>DAT_fffffff8
    //         0054514d     MOV        EBX,dword ptr [this->_padding_]
    //         0054514f     MOV        this,dword ptr [EBP + 0x5c]
    //         00545152     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00545157     MOV        this,dword ptr [EBP + 0x5c]
    //         0054515a     PUSH       EAX=>DAT_fffffff8
    //         0054515b     PUSH       offset DAT_fffffff4
    //         0054515d     PUSH       ESI=>DAT_fffffff0
    //         0054515e     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00545163     MOV        this,dword ptr [EBP + 0x5c]
    //         00545166     PUSH       EAX=>DAT_fffffff4
    //         00545167     PUSH       offset DAT_fffffff0
    //         00545169     PUSH       ESI
    //         0054516a     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         0054516f     MOV        this,dword ptr [EBP + 0x5c]
    //         00545172     PUSH       EAX=>DAT_fffffff0
    //         00545173     PUSH       0x1
    //         00545175     PUSH       ESI
    //         00545176     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         0054517b     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x48]
    //         0054517f     PUSH       EAX
    //         00545180     MOV        EAX,dword ptr [EBP + 0x40]
    //         00545183     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00545186     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_00545189                                                 XREF[2]:     00545139(j), 00545142(j)  
    //         00545189     MOVSX      this,word ptr [EBP + 0x3c]
    //         0054518d     INC        EDI
    //         0054518e     CMP        EDI,this
    //         00545190     JL         LAB_0054512c
    //                               LAB_00545192                                                 XREF[2]:     0054512a(j), 00545130(j)  
    //                              World.cpp:3085 (10)
    //         00545192     POP        EDI
    //         00545193     POP        ESI
    //         00545194     POP        EBP
    //         00545195     POP        EBX
    //         00545196     ADD        ESP,0x4c
    //         00545199     RET        0x8
    //         0054519c     ??         90h
    //         0054519d     NOP
    //         0054519e     NOP
    //         0054519f     NOP
    return;
}

void RGE_Game_World::load_scenario6(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario6(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005451b4(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash            XREF[1]:     00545209(*)  
    //              long              Stack[-0x2c]:4 obj_id
    //              float             Stack[-0x30]:4 world_x
    //              float             Stack[-0x34]:4 world_y
    //              float             Stack[-0x38]:4 world_z
    //              short             Stack[-0x3c]:2 master_id
    //              uchar             Stack[-0x40]:1 obj_state
    //              float             Stack[-0x44]:4 obj_angle
    //              long              Stack[-0x48]:4 id
    //              long              Stack[-0x4c]:4 count                     XREF[3]:     005451a3(*), 005451c4(R), 005451f1(R)  
    //              long              Stack[-0x50]:4 header_size
    //                               ?load_scenario6@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774e8(*), 005779a0(*)  
    //                               RGE_Game_World::load_scenario6
    //                              World.cpp:3089 (3)
    //         005451a0     SUB        ESP,0x4c
    //                              World.cpp:3109 (33)
    //         005451a3     LEA        EAX=>count,[ESP]
    //         005451a7     MOV        dword ptr [world_update_counter],0x0
    //         005451b1     PUSH       EBX
    //         005451b2     PUSH       EBP
    //         005451b3     PUSH       ESI
    //         005451b4     MOV        ESI,dword ptr [ESP + param_1]
    //         005451b8     PUSH       EDI
    //         005451b9     PUSH       0x4
    //         005451bb     PUSH       EAX
    //         005451bc     MOV        EBP,this
    //         005451be     PUSH       ESI
    //         005451bf     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:3110 (11)
    //         005451c4     MOV        EAX,dword ptr [ESP + count]
    //         005451c8     ADD        ESP,0xc
    //         005451cb     TEST       EAX,EAX
    //         005451cd     JLE        LAB_00545209
    //                              World.cpp:3112 (11)
    //         005451cf     PUSH       EAX
    //         005451d0     CALL       malloc                                           undefined malloc()
    //         005451d5     MOV        EDI,EAX
    //         005451d7     ADD        ESP,0x4
    //                              World.cpp:3113 (4)
    //         005451da     TEST       EDI,EDI
    //         005451dc     JNZ        LAB_005451f1
    //                              World.cpp:3115 (9)
    //         005451de     PUSH       ESI
    //         005451df     CALL       rge_close                                        int rge_close(int param_1)
    //         005451e4     ADD        ESP,0x4
    //                              World.cpp:3207 (10)
    //         005451e7     POP        EDI
    //         005451e8     POP        ESI
    //         005451e9     POP        EBP
    //         005451ea     POP        EBX
    //         005451eb     ADD        ESP,0x4c
    //         005451ee     RET        0x8
    //                               LAB_005451f1                                                 XREF[1]:     005451dc(j)  
    //                              World.cpp:3118 (15)
    //         005451f1     MOV        this,dword ptr [ESP + count]
    //         005451f5     PUSH       this
    //         005451f6     PUSH       EDI
    //         005451f7     PUSH       ESI
    //         005451f8     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         005451fd     ADD        ESP,0xc
    //                              World.cpp:3119 (9)
    //         00545200     PUSH       EDI
    //         00545201     CALL       free                                             undefined free()
    //         00545206     ADD        ESP,0x4
    //                               LAB_00545209                                                 XREF[1]:     005451cd(j)  
    //                              World.cpp:3123 (13)
    //         00545209     LEA        EDX=>player_id_hash,[ESP + 0x34]
    //         0054520d     PUSH       0x4
    //         0054520f     PUSH       EDX
    //         00545210     PUSH       ESI
    //         00545211     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3124 (16)
    //         00545216     MOV        EDI,dword ptr [EBP]
    //         00545219     ADD        ESP,0xc
    //         0054521c     MOV        this,EBP
    //         0054521e     PUSH       EBP
    //         0054521f     PUSH       ESI
    //         00545220     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:3127 (6)
    //         00545226     PUSH       ESI
    //         00545227     MOV        this,EBP
    //         00545229     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:3129 (8)
    //         0054522c     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545230     TEST       EDX,EDX
    //         00545232     JLE        LAB_00545247
    //                               LAB_00545234                                                 XREF[1]:     00545245(j)  
    //                              World.cpp:3133 (19)
    //         00545234     MOV        this,0x9
    //         00545239     OR         EAX,0xffffffff
    //         0054523c     LEA        EDI,[ESP + 0x38]
    //         00545240     CMP        EDX,0xa
    //         00545243     STOSD.REP  ES:EDI
    //         00545245     JG         LAB_00545234
    //                               LAB_00545247                                                 XREF[1]:     00545232(j)  
    //                              World.cpp:3136 (16)
    //         00545247     XOR        EAX,EAX
    //         00545249     TEST       EDX,EDX
    //         0054524b     JLE        LAB_00545265
    //         0054524d     MOV        this,dword ptr [ESP + 0x64]
    //         00545251     ADD        this,0x270
    //                               LAB_00545257                                                 XREF[1]:     00545263(j)  
    //                              World.cpp:3137 (14)
    //         00545257     MOV        EDI,dword ptr [this->_padding_]
    //         00545259     ADD        this,0x4
    //         0054525c     MOV        dword ptr [ESP + EDI*0x4 + 0x38],EAX
    //         00545260     INC        EAX
    //         00545261     CMP        EAX,EDX
    //         00545263     JL         LAB_00545257
    //                               LAB_00545265                                                 XREF[1]:     0054524b(j)  
    //                              World.cpp:3141 (6)
    //         00545265     XOR        EDI,EDI
    //         00545267     TEST       EDX,EDX
    //         00545269     JLE        LAB_0054527f
    //                               LAB_0054526b                                                 XREF[1]:     0054527d(j)  
    //                              World.cpp:3142 (20)
    //         0054526b     MOV        EDX,dword ptr [EBP + 0x40]
    //         0054526e     MOV        this,dword ptr [EDX + EDI*0x4]
    //         00545271     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         00545276     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         0054527a     INC        EDI
    //         0054527b     CMP        EDI,EAX
    //         0054527d     JL         LAB_0054526b
    //                               LAB_0054527f                                                 XREF[1]:     00545269(j)  
    //                              World.cpp:3147 (13)
    //         0054527f     LEA        this,[ESP + 0x60]
    //         00545283     PUSH       0x4
    //         00545285     PUSH       this=>DAT_fffffff8
    //         00545286     PUSH       ESI=>DAT_fffffff4
    //         00545287     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3148 (16)
    //         0054528c     MOV        EAX,dword ptr [ESP + 0x6c]
    //         00545290     MOV        EDI,0x1
    //         00545295     ADD        ESP,0xc
    //         00545298     CMP        EAX,EDI
    //         0054529a     JLE        LAB_005452da
    //                              World.cpp:3147 (4)
    //         0054529c     LEA        EBX,[ESP + 0x3c]
    //                               LAB_005452a0                                                 XREF[1]:     005452d8(j)  
    //                              World.cpp:3150 (23)
    //         005452a0     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         005452a4     CMP        EDI,EDX
    //         005452a6     JGE        LAB_005452b9
    //         005452a8     MOV        EAX,dword ptr [EBX]
    //         005452aa     CMP        EAX,-0x1
    //         005452ad     JLE        LAB_005452b9
    //         005452af     MOV        this,dword ptr [EBP + 0x40]
    //         005452b2     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         005452b5     TEST       this,this
    //                              World.cpp:3152 (2)
    //         005452b7     JNZ        LAB_005452be
    //                               LAB_005452b9                                                 XREF[2]:     005452a6(j), 005452ad(j)  
    //                              World.cpp:3153 (33)
    //         005452b9     MOV        this,dword ptr [EBP + 0x40]
    //         005452bc     MOV        this,dword ptr [this->_padding_]
    //                               LAB_005452be                                                 XREF[1]:     005452b7(j)  
    //         005452be     MOV        EDX,dword ptr [this->_padding_]
    //         005452c0     LEA        EAX,[ESP + 0x38]
    //         005452c4     PUSH       0x3f88f5c3
    //         005452c9     PUSH       EAX=>DAT_fffffff8
    //         005452ca     PUSH       ESI=>DAT_fffffff4
    //         005452cb     CALL       dword ptr [EDX + 0x68]
    //         005452ce     MOV        EAX,dword ptr [ESP + 0x60]
    //         005452d2     INC        EDI
    //         005452d3     ADD        EBX,0x4
    //         005452d6     CMP        EDI,EAX
    //         005452d8     JL         LAB_005452a0
    //                               LAB_005452da                                                 XREF[1]:     0054529a(j)  
    //                              World.cpp:3156 (20)
    //         005452da     TEST       EAX,EAX
    //         005452dc     MOV        dword ptr [ESP + 0x64],0x0
    //         005452e4     JLE        LAB_005453e6
    //         005452ea     LEA        EDI,[ESP + 0x38]
    //                               LAB_005452ee                                                 XREF[1]:     005453e0(j)  
    //                              World.cpp:3159 (13)
    //         005452ee     LEA        this,[ESP + 0x14]
    //         005452f2     PUSH       0x4
    //         005452f4     PUSH       this=>DAT_fffffff8
    //         005452f5     PUSH       ESI=>DAT_fffffff4
    //         005452f6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3160 (17)
    //         005452fb     MOV        EAX,dword ptr [ESP + 0x20]
    //         005452ff     ADD        ESP,0xc
    //         00545302     XOR        EBX,EBX
    //         00545304     TEST       EAX,EAX
    //         00545306     JLE        LAB_005453ce
    //                               LAB_0054530c                                                 XREF[1]:     005453c8(j)  
    //                              World.cpp:3162 (16)
    //         0054530c     LEA        EDX,[ESP + 0x30]
    //         00545310     PUSH       0x4
    //         00545312     PUSH       EDX=>DAT_fffffff8
    //         00545313     PUSH       ESI=>DAT_fffffff4
    //         00545314     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545319     ADD        ESP,0xc
    //                              World.cpp:3163 (16)
    //         0054531c     LEA        EAX,[ESP + 0x2c]
    //         00545320     PUSH       0x4
    //         00545322     PUSH       EAX=>DAT_fffffff8
    //         00545323     PUSH       ESI=>DAT_fffffff4
    //         00545324     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545329     ADD        ESP,0xc
    //                              World.cpp:3164 (16)
    //         0054532c     LEA        this,[ESP + 0x28]
    //         00545330     PUSH       0x4
    //         00545332     PUSH       this=>DAT_fffffff8
    //         00545333     PUSH       ESI=>DAT_fffffff4
    //         00545334     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545339     ADD        ESP,0xc
    //                              World.cpp:3165 (16)
    //         0054533c     LEA        EDX,[ESP + 0x18]
    //         00545340     PUSH       0x4
    //         00545342     PUSH       EDX=>DAT_fffffff8
    //         00545343     PUSH       ESI=>DAT_fffffff4
    //         00545344     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545349     ADD        ESP,0xc
    //                              World.cpp:3166 (16)
    //         0054534c     LEA        EAX,[ESP + 0x24]
    //         00545350     PUSH       0x2
    //         00545352     PUSH       EAX=>DAT_fffffff8
    //         00545353     PUSH       ESI=>DAT_fffffff4
    //         00545354     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545359     ADD        ESP,0xc
    //                              World.cpp:3167 (16)
    //         0054535c     LEA        this,[ESP + 0x20]
    //         00545360     PUSH       0x1
    //         00545362     PUSH       this=>DAT_fffffff8
    //         00545363     PUSH       ESI=>DAT_fffffff4
    //         00545364     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545369     ADD        ESP,0xc
    //                              World.cpp:3168 (13)
    //         0054536c     LEA        EDX,[ESP + 0x1c]
    //         00545370     PUSH       0x4
    //         00545372     PUSH       EDX=>DAT_fffffff8
    //         00545373     PUSH       ESI=>DAT_fffffff4
    //         00545374     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3169 (20)
    //         00545379     MOV        EAX,dword ptr [EDI]
    //         0054537b     ADD        ESP,0xc
    //         0054537e     TEST       EAX,EAX
    //         00545380     JL         LAB_005453c1
    //         00545382     MOV        this,dword ptr [EBP + 0x40]
    //         00545385     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         00545388     CMP        dword ptr [EAX],0x0
    //         0054538b     JZ         LAB_005453c1
    //                              World.cpp:3171 (4)
    //         0054538d     MOV        EDX,dword ptr [ESP + 0x18]
    //                              World.cpp:3172 (7)
    //         00545391     MOV        byte ptr [EBP + 0x74],0x1
    //         00545395     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:3174 (37)
    //         00545398     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0054539c     PUSH       EDX
    //         0054539d     MOV        EDX,dword ptr [ESP + 0x24]
    //         005453a1     MOV        this,dword ptr [EAX]
    //         005453a3     PUSH       EDX=>DAT_fffffff8
    //         005453a4     MOV        EDX,dword ptr [ESP + 0x2c]
    //         005453a8     MOV        EAX,dword ptr [this->_padding_]
    //         005453aa     PUSH       EDX=>DAT_fffffff4
    //         005453ab     MOV        EDX,dword ptr [ESP + 0x34]
    //         005453af     PUSH       EDX=>DAT_fffffff0
    //         005453b0     MOV        EDX,dword ptr [ESP + 0x3c]
    //         005453b4     PUSH       EDX
    //         005453b5     MOV        EDX,dword ptr [ESP + 0x44]
    //         005453b9     PUSH       EDX
    //         005453ba     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:3176 (17)
    //         005453bd     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_005453c1                                                 XREF[2]:     00545380(j), 0054538b(j)  
    //         005453c1     MOV        EAX,dword ptr [ESP + 0x14]
    //         005453c5     INC        EBX
    //         005453c6     CMP        EBX,EAX
    //         005453c8     JL         LAB_0054530c
    //                               LAB_005453ce                                                 XREF[1]:     00545306(j)  
    //                              World.cpp:3156 (24)
    //         005453ce     MOV        EAX,dword ptr [ESP + 0x64]
    //         005453d2     MOV        this,dword ptr [ESP + 0x60]
    //         005453d6     INC        EAX
    //         005453d7     ADD        EDI,0x4
    //         005453da     CMP        EAX,this
    //         005453dc     MOV        dword ptr [ESP + 0x64],EAX
    //         005453e0     JL         LAB_005452ee
    //                               LAB_005453e6                                                 XREF[1]:     005452e4(j)  
    //                              World.cpp:3180 (4)
    //         005453e6     MOV        EAX,dword ptr [ESP + 0x34]
    //                              World.cpp:3183 (16)
    //         005453ea     LEA        this,[ESP + 0x60]
    //         005453ee     PUSH       0x4
    //         005453f0     PUSH       this=>DAT_fffffff8
    //         005453f1     PUSH       ESI=>DAT_fffffff4
    //         005453f2     MOV        dword ptr [EBP + 0x68],EAX
    //         005453f5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3184 (16)
    //         005453fa     MOV        EAX,dword ptr [ESP + 0x6c]
    //         005453fe     MOV        EDI,0x1
    //         00545403     ADD        ESP,0xc
    //         00545406     CMP        EAX,EDI
    //         00545408     JLE        LAB_00545448
    //                              World.cpp:3180 (4)
    //         0054540a     LEA        EBX,[ESP + 0x3c]
    //                               LAB_0054540e                                                 XREF[1]:     00545446(j)  
    //                              World.cpp:3186 (23)
    //         0054540e     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545412     CMP        EDI,EDX
    //         00545414     JGE        LAB_00545427
    //         00545416     MOV        EAX,dword ptr [EBX]
    //         00545418     CMP        EAX,-0x1
    //         0054541b     JLE        LAB_00545427
    //         0054541d     MOV        this,dword ptr [EBP + 0x40]
    //         00545420     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545423     TEST       this,this
    //                              World.cpp:3188 (2)
    //         00545425     JNZ        LAB_0054542c
    //                               LAB_00545427                                                 XREF[2]:     00545414(j), 0054541b(j)  
    //                              World.cpp:3189 (33)
    //         00545427     MOV        this,dword ptr [EBP + 0x40]
    //         0054542a     MOV        this,dword ptr [this->_padding_]
    //                               LAB_0054542c                                                 XREF[1]:     00545425(j)  
    //         0054542c     MOV        EDX,dword ptr [this->_padding_]
    //         0054542e     LEA        EAX,[ESP + 0x38]
    //         00545432     PUSH       0x3f88f5c3
    //         00545437     PUSH       EAX=>DAT_fffffff8
    //         00545438     PUSH       ESI=>DAT_fffffff4
    //         00545439     CALL       dword ptr [EDX + 0x70]
    //         0054543c     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545440     INC        EDI
    //         00545441     ADD        EBX,0x4
    //         00545444     CMP        EDI,EAX
    //         00545446     JL         LAB_0054540e
    //                               LAB_00545448                                                 XREF[1]:     00545408(j)  
    //                              World.cpp:3198 (6)
    //         00545448     PUSH       ESI
    //         00545449     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:3199 (20)
    //         0054544e     MOV        EDI,0x1
    //         00545453     ADD        ESP,0x4
    //         00545456     CMP        word ptr [EBP + 0x3c],DI
    //         0054545a     JLE        LAB_005454c2
    //                               LAB_0054545c                                                 XREF[1]:     005454c0(j)  
    //         0054545c     CMP        EDI,dword ptr [ESP + 0x60]
    //         00545460     JGE        LAB_005454c2
    //                              World.cpp:3200 (18)
    //         00545462     MOV        this,dword ptr [EBP + 0x40]
    //         00545465     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00545469     JZ         LAB_005454b9
    //         0054546b     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x38]
    //         0054546f     CMP        EAX,-0x1
    //         00545472     JLE        LAB_005454b9
    //                              World.cpp:3203 (78)
    //         00545474     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545477     LEA        ESI,[EDI + -0x1]
    //         0054547a     PUSH       -0x1
    //         0054547c     PUSH       ESI=>DAT_fffffff8
    //         0054547d     MOV        EBX,dword ptr [this->_padding_]
    //         0054547f     MOV        this,dword ptr [EBP + 0x5c]
    //         00545482     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00545487     MOV        this,dword ptr [EBP + 0x5c]
    //         0054548a     PUSH       EAX=>DAT_fffffff8
    //         0054548b     PUSH       offset DAT_fffffff4
    //         0054548d     PUSH       ESI=>DAT_fffffff0
    //         0054548e     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00545493     MOV        this,dword ptr [EBP + 0x5c]
    //         00545496     PUSH       EAX=>DAT_fffffff4
    //         00545497     PUSH       offset DAT_fffffff0
    //         00545499     PUSH       ESI
    //         0054549a     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         0054549f     MOV        this,dword ptr [EBP + 0x5c]
    //         005454a2     PUSH       EAX=>DAT_fffffff0
    //         005454a3     PUSH       0x1
    //         005454a5     PUSH       ESI
    //         005454a6     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         005454ab     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x48]
    //         005454af     PUSH       EAX
    //         005454b0     MOV        EAX,dword ptr [EBP + 0x40]
    //         005454b3     MOV        this,dword ptr [EAX + EDX*0x4]
    //         005454b6     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_005454b9                                                 XREF[2]:     00545469(j), 00545472(j)  
    //         005454b9     MOVSX      this,word ptr [EBP + 0x3c]
    //         005454bd     INC        EDI
    //         005454be     CMP        EDI,this
    //         005454c0     JL         LAB_0054545c
    //                               LAB_005454c2                                                 XREF[2]:     0054545a(j), 00545460(j)  
    //                              World.cpp:3207 (10)
    //         005454c2     POP        EDI
    //         005454c3     POP        ESI
    //         005454c4     POP        EBP
    //         005454c5     POP        EBX
    //         005454c6     ADD        ESP,0x4c
    //         005454c9     RET        0x8
    //         005454cc     ??         90h
    //         005454cd     NOP
    //         005454ce     NOP
    //         005454cf     NOP
    return;
}

void RGE_Game_World::load_scenario7(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario7(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005454e4(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash            XREF[1]:     00545539(*)  
    //              long              Stack[-0x2c]:4 obj_id
    //              float             Stack[-0x30]:4 world_x
    //              float             Stack[-0x34]:4 world_y
    //              float             Stack[-0x38]:4 world_z
    //              short             Stack[-0x3c]:2 master_id
    //              uchar             Stack[-0x40]:1 obj_state
    //              float             Stack[-0x44]:4 obj_angle
    //              long              Stack[-0x48]:4 id
    //              long              Stack[-0x4c]:4 count                     XREF[3]:     005454d3(*), 005454f4(R), 00545521(R)  
    //              long              Stack[-0x50]:4 header_size
    //                               ?load_scenario7@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774ec(*), 005779a4(*)  
    //                               RGE_Game_World::load_scenario7
    //                              World.cpp:3211 (3)
    //         005454d0     SUB        ESP,0x4c
    //                              World.cpp:3231 (33)
    //         005454d3     LEA        EAX=>count,[ESP]
    //         005454d7     MOV        dword ptr [world_update_counter],0x0
    //         005454e1     PUSH       EBX
    //         005454e2     PUSH       EBP
    //         005454e3     PUSH       ESI
    //         005454e4     MOV        ESI,dword ptr [ESP + param_1]
    //         005454e8     PUSH       EDI
    //         005454e9     PUSH       0x4
    //         005454eb     PUSH       EAX
    //         005454ec     MOV        EBP,this
    //         005454ee     PUSH       ESI
    //         005454ef     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:3232 (11)
    //         005454f4     MOV        EAX,dword ptr [ESP + count]
    //         005454f8     ADD        ESP,0xc
    //         005454fb     TEST       EAX,EAX
    //         005454fd     JLE        LAB_00545539
    //                              World.cpp:3234 (11)
    //         005454ff     PUSH       EAX
    //         00545500     CALL       malloc                                           undefined malloc()
    //         00545505     MOV        EDI,EAX
    //         00545507     ADD        ESP,0x4
    //                              World.cpp:3235 (4)
    //         0054550a     TEST       EDI,EDI
    //         0054550c     JNZ        LAB_00545521
    //                              World.cpp:3237 (9)
    //         0054550e     PUSH       ESI
    //         0054550f     CALL       rge_close                                        int rge_close(int param_1)
    //         00545514     ADD        ESP,0x4
    //                              World.cpp:3329 (10)
    //         00545517     POP        EDI
    //         00545518     POP        ESI
    //         00545519     POP        EBP
    //         0054551a     POP        EBX
    //         0054551b     ADD        ESP,0x4c
    //         0054551e     RET        0x8
    //                               LAB_00545521                                                 XREF[1]:     0054550c(j)  
    //                              World.cpp:3240 (15)
    //         00545521     MOV        this,dword ptr [ESP + count]
    //         00545525     PUSH       this
    //         00545526     PUSH       EDI
    //         00545527     PUSH       ESI
    //         00545528     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0054552d     ADD        ESP,0xc
    //                              World.cpp:3241 (9)
    //         00545530     PUSH       EDI
    //         00545531     CALL       free                                             undefined free()
    //         00545536     ADD        ESP,0x4
    //                               LAB_00545539                                                 XREF[1]:     005454fd(j)  
    //                              World.cpp:3245 (13)
    //         00545539     LEA        EDX=>player_id_hash,[ESP + 0x34]
    //         0054553d     PUSH       0x4
    //         0054553f     PUSH       EDX
    //         00545540     PUSH       ESI
    //         00545541     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3246 (16)
    //         00545546     MOV        EDI,dword ptr [EBP]
    //         00545549     ADD        ESP,0xc
    //         0054554c     MOV        this,EBP
    //         0054554e     PUSH       EBP
    //         0054554f     PUSH       ESI
    //         00545550     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:3249 (6)
    //         00545556     PUSH       ESI
    //         00545557     MOV        this,EBP
    //         00545559     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:3251 (8)
    //         0054555c     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545560     TEST       EDX,EDX
    //         00545562     JLE        LAB_00545577
    //                               LAB_00545564                                                 XREF[1]:     00545575(j)  
    //                              World.cpp:3255 (19)
    //         00545564     MOV        this,0x9
    //         00545569     OR         EAX,0xffffffff
    //         0054556c     LEA        EDI,[ESP + 0x38]
    //         00545570     CMP        EDX,0xa
    //         00545573     STOSD.REP  ES:EDI
    //         00545575     JG         LAB_00545564
    //                               LAB_00545577                                                 XREF[1]:     00545562(j)  
    //                              World.cpp:3258 (16)
    //         00545577     XOR        EAX,EAX
    //         00545579     TEST       EDX,EDX
    //         0054557b     JLE        LAB_00545595
    //         0054557d     MOV        this,dword ptr [ESP + 0x64]
    //         00545581     ADD        this,0x270
    //                               LAB_00545587                                                 XREF[1]:     00545593(j)  
    //                              World.cpp:3259 (14)
    //         00545587     MOV        EDI,dword ptr [this->_padding_]
    //         00545589     ADD        this,0x4
    //         0054558c     MOV        dword ptr [ESP + EDI*0x4 + 0x38],EAX
    //         00545590     INC        EAX
    //         00545591     CMP        EAX,EDX
    //         00545593     JL         LAB_00545587
    //                               LAB_00545595                                                 XREF[1]:     0054557b(j)  
    //                              World.cpp:3263 (6)
    //         00545595     XOR        EDI,EDI
    //         00545597     TEST       EDX,EDX
    //         00545599     JLE        LAB_005455af
    //                               LAB_0054559b                                                 XREF[1]:     005455ad(j)  
    //                              World.cpp:3264 (20)
    //         0054559b     MOV        EDX,dword ptr [EBP + 0x40]
    //         0054559e     MOV        this,dword ptr [EDX + EDI*0x4]
    //         005455a1     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         005455a6     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         005455aa     INC        EDI
    //         005455ab     CMP        EDI,EAX
    //         005455ad     JL         LAB_0054559b
    //                               LAB_005455af                                                 XREF[1]:     00545599(j)  
    //                              World.cpp:3269 (13)
    //         005455af     LEA        this,[ESP + 0x60]
    //         005455b3     PUSH       0x4
    //         005455b5     PUSH       this=>DAT_fffffff8
    //         005455b6     PUSH       ESI=>DAT_fffffff4
    //         005455b7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3270 (16)
    //         005455bc     MOV        EAX,dword ptr [ESP + 0x6c]
    //         005455c0     MOV        EDI,0x1
    //         005455c5     ADD        ESP,0xc
    //         005455c8     CMP        EAX,EDI
    //         005455ca     JLE        LAB_0054560a
    //                              World.cpp:3269 (4)
    //         005455cc     LEA        EBX,[ESP + 0x3c]
    //                               LAB_005455d0                                                 XREF[1]:     00545608(j)  
    //                              World.cpp:3272 (23)
    //         005455d0     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         005455d4     CMP        EDI,EDX
    //         005455d6     JGE        LAB_005455e9
    //         005455d8     MOV        EAX,dword ptr [EBX]
    //         005455da     CMP        EAX,-0x1
    //         005455dd     JLE        LAB_005455e9
    //         005455df     MOV        this,dword ptr [EBP + 0x40]
    //         005455e2     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         005455e5     TEST       this,this
    //                              World.cpp:3274 (2)
    //         005455e7     JNZ        LAB_005455ee
    //                               LAB_005455e9                                                 XREF[2]:     005455d6(j), 005455dd(j)  
    //                              World.cpp:3275 (33)
    //         005455e9     MOV        this,dword ptr [EBP + 0x40]
    //         005455ec     MOV        this,dword ptr [this->_padding_]
    //                               LAB_005455ee                                                 XREF[1]:     005455e7(j)  
    //         005455ee     MOV        EDX,dword ptr [this->_padding_]
    //         005455f0     LEA        EAX,[ESP + 0x38]
    //         005455f4     PUSH       0x3f8a3d71
    //         005455f9     PUSH       EAX=>DAT_fffffff8
    //         005455fa     PUSH       ESI=>DAT_fffffff4
    //         005455fb     CALL       dword ptr [EDX + 0x68]
    //         005455fe     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545602     INC        EDI
    //         00545603     ADD        EBX,0x4
    //         00545606     CMP        EDI,EAX
    //         00545608     JL         LAB_005455d0
    //                               LAB_0054560a                                                 XREF[1]:     005455ca(j)  
    //                              World.cpp:3278 (20)
    //         0054560a     TEST       EAX,EAX
    //         0054560c     MOV        dword ptr [ESP + 0x64],0x0
    //         00545614     JLE        LAB_00545716
    //         0054561a     LEA        EDI,[ESP + 0x38]
    //                               LAB_0054561e                                                 XREF[1]:     00545710(j)  
    //                              World.cpp:3281 (13)
    //         0054561e     LEA        this,[ESP + 0x14]
    //         00545622     PUSH       0x4
    //         00545624     PUSH       this=>DAT_fffffff8
    //         00545625     PUSH       ESI=>DAT_fffffff4
    //         00545626     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3282 (17)
    //         0054562b     MOV        EAX,dword ptr [ESP + 0x20]
    //         0054562f     ADD        ESP,0xc
    //         00545632     XOR        EBX,EBX
    //         00545634     TEST       EAX,EAX
    //         00545636     JLE        LAB_005456fe
    //                               LAB_0054563c                                                 XREF[1]:     005456f8(j)  
    //                              World.cpp:3284 (16)
    //         0054563c     LEA        EDX,[ESP + 0x30]
    //         00545640     PUSH       0x4
    //         00545642     PUSH       EDX=>DAT_fffffff8
    //         00545643     PUSH       ESI=>DAT_fffffff4
    //         00545644     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545649     ADD        ESP,0xc
    //                              World.cpp:3285 (16)
    //         0054564c     LEA        EAX,[ESP + 0x2c]
    //         00545650     PUSH       0x4
    //         00545652     PUSH       EAX=>DAT_fffffff8
    //         00545653     PUSH       ESI=>DAT_fffffff4
    //         00545654     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545659     ADD        ESP,0xc
    //                              World.cpp:3286 (16)
    //         0054565c     LEA        this,[ESP + 0x28]
    //         00545660     PUSH       0x4
    //         00545662     PUSH       this=>DAT_fffffff8
    //         00545663     PUSH       ESI=>DAT_fffffff4
    //         00545664     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545669     ADD        ESP,0xc
    //                              World.cpp:3287 (16)
    //         0054566c     LEA        EDX,[ESP + 0x18]
    //         00545670     PUSH       0x4
    //         00545672     PUSH       EDX=>DAT_fffffff8
    //         00545673     PUSH       ESI=>DAT_fffffff4
    //         00545674     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545679     ADD        ESP,0xc
    //                              World.cpp:3288 (16)
    //         0054567c     LEA        EAX,[ESP + 0x24]
    //         00545680     PUSH       0x2
    //         00545682     PUSH       EAX=>DAT_fffffff8
    //         00545683     PUSH       ESI=>DAT_fffffff4
    //         00545684     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545689     ADD        ESP,0xc
    //                              World.cpp:3289 (16)
    //         0054568c     LEA        this,[ESP + 0x20]
    //         00545690     PUSH       0x1
    //         00545692     PUSH       this=>DAT_fffffff8
    //         00545693     PUSH       ESI=>DAT_fffffff4
    //         00545694     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545699     ADD        ESP,0xc
    //                              World.cpp:3290 (13)
    //         0054569c     LEA        EDX,[ESP + 0x1c]
    //         005456a0     PUSH       0x4
    //         005456a2     PUSH       EDX=>DAT_fffffff8
    //         005456a3     PUSH       ESI=>DAT_fffffff4
    //         005456a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3291 (20)
    //         005456a9     MOV        EAX,dword ptr [EDI]
    //         005456ab     ADD        ESP,0xc
    //         005456ae     TEST       EAX,EAX
    //         005456b0     JL         LAB_005456f1
    //         005456b2     MOV        this,dword ptr [EBP + 0x40]
    //         005456b5     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         005456b8     CMP        dword ptr [EAX],0x0
    //         005456bb     JZ         LAB_005456f1
    //                              World.cpp:3293 (4)
    //         005456bd     MOV        EDX,dword ptr [ESP + 0x18]
    //                              World.cpp:3294 (7)
    //         005456c1     MOV        byte ptr [EBP + 0x74],0x1
    //         005456c5     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:3296 (37)
    //         005456c8     MOV        EDX,dword ptr [ESP + 0x1c]
    //         005456cc     PUSH       EDX
    //         005456cd     MOV        EDX,dword ptr [ESP + 0x24]
    //         005456d1     MOV        this,dword ptr [EAX]
    //         005456d3     PUSH       EDX=>DAT_fffffff8
    //         005456d4     MOV        EDX,dword ptr [ESP + 0x2c]
    //         005456d8     MOV        EAX,dword ptr [this->_padding_]
    //         005456da     PUSH       EDX=>DAT_fffffff4
    //         005456db     MOV        EDX,dword ptr [ESP + 0x34]
    //         005456df     PUSH       EDX=>DAT_fffffff0
    //         005456e0     MOV        EDX,dword ptr [ESP + 0x3c]
    //         005456e4     PUSH       EDX
    //         005456e5     MOV        EDX,dword ptr [ESP + 0x44]
    //         005456e9     PUSH       EDX
    //         005456ea     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:3298 (17)
    //         005456ed     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_005456f1                                                 XREF[2]:     005456b0(j), 005456bb(j)  
    //         005456f1     MOV        EAX,dword ptr [ESP + 0x14]
    //         005456f5     INC        EBX
    //         005456f6     CMP        EBX,EAX
    //         005456f8     JL         LAB_0054563c
    //                               LAB_005456fe                                                 XREF[1]:     00545636(j)  
    //                              World.cpp:3278 (24)
    //         005456fe     MOV        EAX,dword ptr [ESP + 0x64]
    //         00545702     MOV        this,dword ptr [ESP + 0x60]
    //         00545706     INC        EAX
    //         00545707     ADD        EDI,0x4
    //         0054570a     CMP        EAX,this
    //         0054570c     MOV        dword ptr [ESP + 0x64],EAX
    //         00545710     JL         LAB_0054561e
    //                               LAB_00545716                                                 XREF[1]:     00545614(j)  
    //                              World.cpp:3302 (4)
    //         00545716     MOV        EAX,dword ptr [ESP + 0x34]
    //                              World.cpp:3305 (16)
    //         0054571a     LEA        this,[ESP + 0x60]
    //         0054571e     PUSH       0x4
    //         00545720     PUSH       this=>DAT_fffffff8
    //         00545721     PUSH       ESI=>DAT_fffffff4
    //         00545722     MOV        dword ptr [EBP + 0x68],EAX
    //         00545725     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3306 (16)
    //         0054572a     MOV        EAX,dword ptr [ESP + 0x6c]
    //         0054572e     MOV        EDI,0x1
    //         00545733     ADD        ESP,0xc
    //         00545736     CMP        EAX,EDI
    //         00545738     JLE        LAB_00545778
    //                              World.cpp:3302 (4)
    //         0054573a     LEA        EBX,[ESP + 0x3c]
    //                               LAB_0054573e                                                 XREF[1]:     00545776(j)  
    //                              World.cpp:3308 (23)
    //         0054573e     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545742     CMP        EDI,EDX
    //         00545744     JGE        LAB_00545757
    //         00545746     MOV        EAX,dword ptr [EBX]
    //         00545748     CMP        EAX,-0x1
    //         0054574b     JLE        LAB_00545757
    //         0054574d     MOV        this,dword ptr [EBP + 0x40]
    //         00545750     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545753     TEST       this,this
    //                              World.cpp:3310 (2)
    //         00545755     JNZ        LAB_0054575c
    //                               LAB_00545757                                                 XREF[2]:     00545744(j), 0054574b(j)  
    //                              World.cpp:3311 (33)
    //         00545757     MOV        this,dword ptr [EBP + 0x40]
    //         0054575a     MOV        this,dword ptr [this->_padding_]
    //                               LAB_0054575c                                                 XREF[1]:     00545755(j)  
    //         0054575c     MOV        EDX,dword ptr [this->_padding_]
    //         0054575e     LEA        EAX,[ESP + 0x38]
    //         00545762     PUSH       0x3f8a3d71
    //         00545767     PUSH       EAX=>DAT_fffffff8
    //         00545768     PUSH       ESI=>DAT_fffffff4
    //         00545769     CALL       dword ptr [EDX + 0x70]
    //         0054576c     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545770     INC        EDI
    //         00545771     ADD        EBX,0x4
    //         00545774     CMP        EDI,EAX
    //         00545776     JL         LAB_0054573e
    //                               LAB_00545778                                                 XREF[1]:     00545738(j)  
    //                              World.cpp:3320 (6)
    //         00545778     PUSH       ESI
    //         00545779     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:3321 (20)
    //         0054577e     MOV        EDI,0x1
    //         00545783     ADD        ESP,0x4
    //         00545786     CMP        word ptr [EBP + 0x3c],DI
    //         0054578a     JLE        LAB_005457f2
    //                               LAB_0054578c                                                 XREF[1]:     005457f0(j)  
    //         0054578c     CMP        EDI,dword ptr [ESP + 0x60]
    //         00545790     JGE        LAB_005457f2
    //                              World.cpp:3322 (18)
    //         00545792     MOV        this,dword ptr [EBP + 0x40]
    //         00545795     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00545799     JZ         LAB_005457e9
    //         0054579b     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x38]
    //         0054579f     CMP        EAX,-0x1
    //         005457a2     JLE        LAB_005457e9
    //                              World.cpp:3325 (78)
    //         005457a4     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         005457a7     LEA        ESI,[EDI + -0x1]
    //         005457aa     PUSH       -0x1
    //         005457ac     PUSH       ESI=>DAT_fffffff8
    //         005457ad     MOV        EBX,dword ptr [this->_padding_]
    //         005457af     MOV        this,dword ptr [EBP + 0x5c]
    //         005457b2     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         005457b7     MOV        this,dword ptr [EBP + 0x5c]
    //         005457ba     PUSH       EAX=>DAT_fffffff8
    //         005457bb     PUSH       offset DAT_fffffff4
    //         005457bd     PUSH       ESI=>DAT_fffffff0
    //         005457be     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         005457c3     MOV        this,dword ptr [EBP + 0x5c]
    //         005457c6     PUSH       EAX=>DAT_fffffff4
    //         005457c7     PUSH       offset DAT_fffffff0
    //         005457c9     PUSH       ESI
    //         005457ca     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         005457cf     MOV        this,dword ptr [EBP + 0x5c]
    //         005457d2     PUSH       EAX=>DAT_fffffff0
    //         005457d3     PUSH       0x1
    //         005457d5     PUSH       ESI
    //         005457d6     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         005457db     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x48]
    //         005457df     PUSH       EAX
    //         005457e0     MOV        EAX,dword ptr [EBP + 0x40]
    //         005457e3     MOV        this,dword ptr [EAX + EDX*0x4]
    //         005457e6     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_005457e9                                                 XREF[2]:     00545799(j), 005457a2(j)  
    //         005457e9     MOVSX      this,word ptr [EBP + 0x3c]
    //         005457ed     INC        EDI
    //         005457ee     CMP        EDI,this
    //         005457f0     JL         LAB_0054578c
    //                               LAB_005457f2                                                 XREF[2]:     0054578a(j), 00545790(j)  
    //                              World.cpp:3329 (10)
    //         005457f2     POP        EDI
    //         005457f3     POP        ESI
    //         005457f4     POP        EBP
    //         005457f5     POP        EBX
    //         005457f6     ADD        ESP,0x4c
    //         005457f9     RET        0x8
    //         005457fc     ??         90h
    //         005457fd     NOP
    //         005457fe     NOP
    //         005457ff     NOP
    return;
}

void RGE_Game_World::load_scenario8(int param_1, RGE_Player_Info* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_scenario8(RGE_Game_World * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00545814(R)  
    //              RGE_Player_Inf    Stack[0x8]:4   param_2
    //              long[9]           Stack[-0x28]   player_id_hash            XREF[1]:     00545869(*)  
    //              long              Stack[-0x2c]:4 obj_id
    //              float             Stack[-0x30]:4 world_x
    //              float             Stack[-0x34]:4 world_y
    //              float             Stack[-0x38]:4 world_z
    //              short             Stack[-0x3c]:2 master_id
    //              uchar             Stack[-0x40]:1 obj_state
    //              float             Stack[-0x44]:4 obj_angle
    //              long              Stack[-0x48]:4 id
    //              long              Stack[-0x4c]:4 count                     XREF[3]:     00545803(*), 00545824(R), 00545851(R)  
    //              long              Stack[-0x50]:4 header_size
    //                               ?load_scenario8@RGE_Game_World@@MAEXHAAURGE_Player_Info@@@Z  XREF[2]:     005774f0(*), 005779a8(*)  
    //                               RGE_Game_World::load_scenario8
    //                              World.cpp:3333 (3)
    //         00545800     SUB        ESP,0x4c
    //                              World.cpp:3353 (33)
    //         00545803     LEA        EAX=>count,[ESP]
    //         00545807     MOV        dword ptr [world_update_counter],0x0
    //         00545811     PUSH       EBX
    //         00545812     PUSH       EBP
    //         00545813     PUSH       ESI
    //         00545814     MOV        ESI,dword ptr [ESP + param_1]
    //         00545818     PUSH       EDI
    //         00545819     PUSH       0x4
    //         0054581b     PUSH       EAX
    //         0054581c     MOV        EBP,this
    //         0054581e     PUSH       ESI
    //         0054581f     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              World.cpp:3354 (11)
    //         00545824     MOV        EAX,dword ptr [ESP + count]
    //         00545828     ADD        ESP,0xc
    //         0054582b     TEST       EAX,EAX
    //         0054582d     JLE        LAB_00545869
    //                              World.cpp:3356 (11)
    //         0054582f     PUSH       EAX
    //         00545830     CALL       malloc                                           undefined malloc()
    //         00545835     MOV        EDI,EAX
    //         00545837     ADD        ESP,0x4
    //                              World.cpp:3357 (4)
    //         0054583a     TEST       EDI,EDI
    //         0054583c     JNZ        LAB_00545851
    //                              World.cpp:3359 (9)
    //         0054583e     PUSH       ESI
    //         0054583f     CALL       rge_close                                        int rge_close(int param_1)
    //         00545844     ADD        ESP,0x4
    //                              World.cpp:3455 (10)
    //         00545847     POP        EDI
    //         00545848     POP        ESI
    //         00545849     POP        EBP
    //         0054584a     POP        EBX
    //         0054584b     ADD        ESP,0x4c
    //         0054584e     RET        0x8
    //                               LAB_00545851                                                 XREF[1]:     0054583c(j)  
    //                              World.cpp:3362 (15)
    //         00545851     MOV        this,dword ptr [ESP + count]
    //         00545855     PUSH       this
    //         00545856     PUSH       EDI
    //         00545857     PUSH       ESI
    //         00545858     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0054585d     ADD        ESP,0xc
    //                              World.cpp:3363 (9)
    //         00545860     PUSH       EDI
    //         00545861     CALL       free                                             undefined free()
    //         00545866     ADD        ESP,0x4
    //                               LAB_00545869                                                 XREF[1]:     0054582d(j)  
    //                              World.cpp:3367 (13)
    //         00545869     LEA        EDX=>player_id_hash,[ESP + 0x34]
    //         0054586d     PUSH       0x4
    //         0054586f     PUSH       EDX
    //         00545870     PUSH       ESI
    //         00545871     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3368 (16)
    //         00545876     MOV        EDI,dword ptr [EBP]
    //         00545879     ADD        ESP,0xc
    //         0054587c     MOV        this,EBP
    //         0054587e     PUSH       EBP
    //         0054587f     PUSH       ESI
    //         00545880     CALL       dword ptr [EDI + 0xf4]
    //                              World.cpp:3371 (6)
    //         00545886     PUSH       ESI
    //         00545887     MOV        this,EBP
    //         00545889     CALL       dword ptr [EDI + 0x70]
    //                              World.cpp:3373 (8)
    //         0054588c     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545890     TEST       EDX,EDX
    //         00545892     JLE        LAB_005458a7
    //                               LAB_00545894                                                 XREF[1]:     005458a5(j)  
    //                              World.cpp:3377 (19)
    //         00545894     MOV        this,0x9
    //         00545899     OR         EAX,0xffffffff
    //         0054589c     LEA        EDI,[ESP + 0x38]
    //         005458a0     CMP        EDX,0xa
    //         005458a3     STOSD.REP  ES:EDI
    //         005458a5     JG         LAB_00545894
    //                               LAB_005458a7                                                 XREF[1]:     00545892(j)  
    //                              World.cpp:3380 (16)
    //         005458a7     XOR        EAX,EAX
    //         005458a9     TEST       EDX,EDX
    //         005458ab     JLE        LAB_005458c5
    //         005458ad     MOV        this,dword ptr [ESP + 0x64]
    //         005458b1     ADD        this,0x270
    //                               LAB_005458b7                                                 XREF[1]:     005458c3(j)  
    //                              World.cpp:3381 (14)
    //         005458b7     MOV        EDI,dword ptr [this->_padding_]
    //         005458b9     ADD        this,0x4
    //         005458bc     MOV        dword ptr [ESP + EDI*0x4 + 0x38],EAX
    //         005458c0     INC        EAX
    //         005458c1     CMP        EAX,EDX
    //         005458c3     JL         LAB_005458b7
    //                               LAB_005458c5                                                 XREF[1]:     005458ab(j)  
    //                              World.cpp:3385 (6)
    //         005458c5     XOR        EDI,EDI
    //         005458c7     TEST       EDX,EDX
    //         005458c9     JLE        LAB_005458df
    //                               LAB_005458cb                                                 XREF[1]:     005458dd(j)  
    //                              World.cpp:3386 (20)
    //         005458cb     MOV        EDX,dword ptr [EBP + 0x40]
    //         005458ce     MOV        this,dword ptr [EDX + EDI*0x4]
    //         005458d1     CALL       RGE_Player::remake_visible_map                   void remake_visible_map(RGE_Player * this)
    //         005458d6     MOVSX      EAX,word ptr [EBP + 0x3c]
    //         005458da     INC        EDI
    //         005458db     CMP        EDI,EAX
    //         005458dd     JL         LAB_005458cb
    //                               LAB_005458df                                                 XREF[1]:     005458c9(j)  
    //                              World.cpp:3391 (13)
    //         005458df     LEA        this,[ESP + 0x60]
    //         005458e3     PUSH       0x4
    //         005458e5     PUSH       this=>DAT_fffffff8
    //         005458e6     PUSH       ESI=>DAT_fffffff4
    //         005458e7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3392 (16)
    //         005458ec     MOV        EAX,dword ptr [ESP + 0x6c]
    //         005458f0     MOV        EDI,0x1
    //         005458f5     ADD        ESP,0xc
    //         005458f8     CMP        EAX,EDI
    //         005458fa     JLE        LAB_0054593a
    //                              World.cpp:3391 (4)
    //         005458fc     LEA        EBX,[ESP + 0x3c]
    //                               LAB_00545900                                                 XREF[1]:     00545938(j)  
    //                              World.cpp:3394 (23)
    //         00545900     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545904     CMP        EDI,EDX
    //         00545906     JGE        LAB_00545919
    //         00545908     MOV        EAX,dword ptr [EBX]
    //         0054590a     CMP        EAX,-0x1
    //         0054590d     JLE        LAB_00545919
    //         0054590f     MOV        this,dword ptr [EBP + 0x40]
    //         00545912     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545915     TEST       this,this
    //                              World.cpp:3397 (2)
    //         00545917     JNZ        LAB_0054591e
    //                               LAB_00545919                                                 XREF[2]:     00545906(j), 0054590d(j)  
    //                              World.cpp:3399 (33)
    //         00545919     MOV        this,dword ptr [EBP + 0x40]
    //         0054591c     MOV        this,dword ptr [this->_padding_]
    //                               LAB_0054591e                                                 XREF[1]:     00545917(j)  
    //         0054591e     MOV        EDX,dword ptr [this->_padding_]
    //         00545920     LEA        EAX,[ESP + 0x38]
    //         00545924     PUSH       0x3f8e147b
    //         00545929     PUSH       EAX=>DAT_fffffff8
    //         0054592a     PUSH       ESI=>DAT_fffffff4
    //         0054592b     CALL       dword ptr [EDX + 0x68]
    //         0054592e     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545932     INC        EDI
    //         00545933     ADD        EBX,0x4
    //         00545936     CMP        EDI,EAX
    //         00545938     JL         LAB_00545900
    //                               LAB_0054593a                                                 XREF[1]:     005458fa(j)  
    //                              World.cpp:3402 (20)
    //         0054593a     TEST       EAX,EAX
    //         0054593c     MOV        dword ptr [ESP + 0x64],0x0
    //         00545944     JLE        LAB_00545a46
    //         0054594a     LEA        EDI,[ESP + 0x38]
    //                               LAB_0054594e                                                 XREF[1]:     00545a40(j)  
    //                              World.cpp:3405 (13)
    //         0054594e     LEA        this,[ESP + 0x14]
    //         00545952     PUSH       0x4
    //         00545954     PUSH       this=>DAT_fffffff8
    //         00545955     PUSH       ESI=>DAT_fffffff4
    //         00545956     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3406 (17)
    //         0054595b     MOV        EAX,dword ptr [ESP + 0x20]
    //         0054595f     ADD        ESP,0xc
    //         00545962     XOR        EBX,EBX
    //         00545964     TEST       EAX,EAX
    //         00545966     JLE        LAB_00545a2e
    //                               LAB_0054596c                                                 XREF[1]:     00545a28(j)  
    //                              World.cpp:3408 (16)
    //         0054596c     LEA        EDX,[ESP + 0x30]
    //         00545970     PUSH       0x4
    //         00545972     PUSH       EDX=>DAT_fffffff8
    //         00545973     PUSH       ESI=>DAT_fffffff4
    //         00545974     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545979     ADD        ESP,0xc
    //                              World.cpp:3409 (16)
    //         0054597c     LEA        EAX,[ESP + 0x2c]
    //         00545980     PUSH       0x4
    //         00545982     PUSH       EAX=>DAT_fffffff8
    //         00545983     PUSH       ESI=>DAT_fffffff4
    //         00545984     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545989     ADD        ESP,0xc
    //                              World.cpp:3410 (16)
    //         0054598c     LEA        this,[ESP + 0x28]
    //         00545990     PUSH       0x4
    //         00545992     PUSH       this=>DAT_fffffff8
    //         00545993     PUSH       ESI=>DAT_fffffff4
    //         00545994     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00545999     ADD        ESP,0xc
    //                              World.cpp:3411 (16)
    //         0054599c     LEA        EDX,[ESP + 0x18]
    //         005459a0     PUSH       0x4
    //         005459a2     PUSH       EDX=>DAT_fffffff8
    //         005459a3     PUSH       ESI=>DAT_fffffff4
    //         005459a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005459a9     ADD        ESP,0xc
    //                              World.cpp:3412 (16)
    //         005459ac     LEA        EAX,[ESP + 0x24]
    //         005459b0     PUSH       0x2
    //         005459b2     PUSH       EAX=>DAT_fffffff8
    //         005459b3     PUSH       ESI=>DAT_fffffff4
    //         005459b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005459b9     ADD        ESP,0xc
    //                              World.cpp:3413 (16)
    //         005459bc     LEA        this,[ESP + 0x20]
    //         005459c0     PUSH       0x1
    //         005459c2     PUSH       this=>DAT_fffffff8
    //         005459c3     PUSH       ESI=>DAT_fffffff4
    //         005459c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         005459c9     ADD        ESP,0xc
    //                              World.cpp:3414 (13)
    //         005459cc     LEA        EDX,[ESP + 0x1c]
    //         005459d0     PUSH       0x4
    //         005459d2     PUSH       EDX=>DAT_fffffff8
    //         005459d3     PUSH       ESI=>DAT_fffffff4
    //         005459d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3415 (20)
    //         005459d9     MOV        EAX,dword ptr [EDI]
    //         005459db     ADD        ESP,0xc
    //         005459de     TEST       EAX,EAX
    //         005459e0     JL         LAB_00545a21
    //         005459e2     MOV        this,dword ptr [EBP + 0x40]
    //         005459e5     LEA        EAX,[this->_padding_ + EAX*0x4]
    //         005459e8     CMP        dword ptr [EAX],0x0
    //         005459eb     JZ         LAB_00545a21
    //                              World.cpp:3417 (4)
    //         005459ed     MOV        EDX,dword ptr [ESP + 0x18]
    //                              World.cpp:3418 (7)
    //         005459f1     MOV        byte ptr [EBP + 0x74],0x1
    //         005459f5     MOV        dword ptr [EBP + 0x70],EDX
    //                              World.cpp:3420 (37)
    //         005459f8     MOV        EDX,dword ptr [ESP + 0x1c]
    //         005459fc     PUSH       EDX
    //         005459fd     MOV        EDX,dword ptr [ESP + 0x24]
    //         00545a01     MOV        this,dword ptr [EAX]
    //         00545a03     PUSH       EDX=>DAT_fffffff8
    //         00545a04     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00545a08     MOV        EAX,dword ptr [this->_padding_]
    //         00545a0a     PUSH       EDX=>DAT_fffffff4
    //         00545a0b     MOV        EDX,dword ptr [ESP + 0x34]
    //         00545a0f     PUSH       EDX=>DAT_fffffff0
    //         00545a10     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00545a14     PUSH       EDX
    //         00545a15     MOV        EDX,dword ptr [ESP + 0x44]
    //         00545a19     PUSH       EDX
    //         00545a1a     CALL       dword ptr [EAX + 0x60]
    //                              World.cpp:3422 (17)
    //         00545a1d     MOV        byte ptr [EBP + 0x74],0x0
    //                               LAB_00545a21                                                 XREF[2]:     005459e0(j), 005459eb(j)  
    //         00545a21     MOV        EAX,dword ptr [ESP + 0x14]
    //         00545a25     INC        EBX
    //         00545a26     CMP        EBX,EAX
    //         00545a28     JL         LAB_0054596c
    //                               LAB_00545a2e                                                 XREF[1]:     00545966(j)  
    //                              World.cpp:3402 (24)
    //         00545a2e     MOV        EAX,dword ptr [ESP + 0x64]
    //         00545a32     MOV        this,dword ptr [ESP + 0x60]
    //         00545a36     INC        EAX
    //         00545a37     ADD        EDI,0x4
    //         00545a3a     CMP        EAX,this
    //         00545a3c     MOV        dword ptr [ESP + 0x64],EAX
    //         00545a40     JL         LAB_0054594e
    //                               LAB_00545a46                                                 XREF[1]:     00545944(j)  
    //                              World.cpp:3426 (4)
    //         00545a46     MOV        EAX,dword ptr [ESP + 0x34]
    //                              World.cpp:3429 (16)
    //         00545a4a     LEA        this,[ESP + 0x60]
    //         00545a4e     PUSH       0x4
    //         00545a50     PUSH       this=>DAT_fffffff8
    //         00545a51     PUSH       ESI=>DAT_fffffff4
    //         00545a52     MOV        dword ptr [EBP + 0x68],EAX
    //         00545a55     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              World.cpp:3430 (16)
    //         00545a5a     MOV        EAX,dword ptr [ESP + 0x6c]
    //         00545a5e     MOV        EDI,0x1
    //         00545a63     ADD        ESP,0xc
    //         00545a66     CMP        EAX,EDI
    //         00545a68     JLE        LAB_00545aa8
    //                              World.cpp:3426 (4)
    //         00545a6a     LEA        EBX,[ESP + 0x3c]
    //                               LAB_00545a6e                                                 XREF[1]:     00545aa6(j)  
    //                              World.cpp:3432 (23)
    //         00545a6e     MOVSX      EDX,word ptr [EBP + 0x3c]
    //         00545a72     CMP        EDI,EDX
    //         00545a74     JGE        LAB_00545a87
    //         00545a76     MOV        EAX,dword ptr [EBX]
    //         00545a78     CMP        EAX,-0x1
    //         00545a7b     JLE        LAB_00545a87
    //         00545a7d     MOV        this,dword ptr [EBP + 0x40]
    //         00545a80     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545a83     TEST       this,this
    //                              World.cpp:3435 (2)
    //         00545a85     JNZ        LAB_00545a8c
    //                               LAB_00545a87                                                 XREF[2]:     00545a74(j), 00545a7b(j)  
    //                              World.cpp:3437 (33)
    //         00545a87     MOV        this,dword ptr [EBP + 0x40]
    //         00545a8a     MOV        this,dword ptr [this->_padding_]
    //                               LAB_00545a8c                                                 XREF[1]:     00545a85(j)  
    //         00545a8c     MOV        EDX,dword ptr [this->_padding_]
    //         00545a8e     LEA        EAX,[ESP + 0x38]
    //         00545a92     PUSH       0x3f8e147b
    //         00545a97     PUSH       EAX=>DAT_fffffff8
    //         00545a98     PUSH       ESI=>DAT_fffffff4
    //         00545a99     CALL       dword ptr [EDX + 0x70]
    //         00545a9c     MOV        EAX,dword ptr [ESP + 0x60]
    //         00545aa0     INC        EDI
    //         00545aa1     ADD        EBX,0x4
    //         00545aa4     CMP        EDI,EAX
    //         00545aa6     JL         LAB_00545a6e
    //                               LAB_00545aa8                                                 XREF[1]:     00545a68(j)  
    //                              World.cpp:3446 (6)
    //         00545aa8     PUSH       ESI
    //         00545aa9     CALL       rge_close                                        int rge_close(int param_1)
    //                              World.cpp:3447 (20)
    //         00545aae     MOV        EDI,0x1
    //         00545ab3     ADD        ESP,0x4
    //         00545ab6     CMP        word ptr [EBP + 0x3c],DI
    //         00545aba     JLE        LAB_00545b22
    //                               LAB_00545abc                                                 XREF[1]:     00545b20(j)  
    //         00545abc     CMP        EDI,dword ptr [ESP + 0x60]
    //         00545ac0     JGE        LAB_00545b22
    //                              World.cpp:3448 (18)
    //         00545ac2     MOV        this,dword ptr [EBP + 0x40]
    //         00545ac5     CMP        dword ptr [this->_padding_ + EDI*0x4],0x0
    //         00545ac9     JZ         LAB_00545b19
    //         00545acb     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x38]
    //         00545acf     CMP        EAX,-0x1
    //         00545ad2     JLE        LAB_00545b19
    //                              World.cpp:3451 (78)
    //         00545ad4     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         00545ad7     LEA        ESI,[EDI + -0x1]
    //         00545ada     PUSH       -0x1
    //         00545adc     PUSH       ESI=>DAT_fffffff8
    //         00545add     MOV        EBX,dword ptr [this->_padding_]
    //         00545adf     MOV        this,dword ptr [EBP + 0x5c]
    //         00545ae2     CALL       RGE_Scenario::GetPlayerPosture                   int GetPlayerPosture(RGE_Scenario * this, int
    //         00545ae7     MOV        this,dword ptr [EBP + 0x5c]
    //         00545aea     PUSH       EAX=>DAT_fffffff8
    //         00545aeb     PUSH       offset DAT_fffffff4
    //         00545aed     PUSH       ESI=>DAT_fffffff0
    //         00545aee     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         00545af3     MOV        this,dword ptr [EBP + 0x5c]
    //         00545af6     PUSH       EAX=>DAT_fffffff4
    //         00545af7     PUSH       offset DAT_fffffff0
    //         00545af9     PUSH       ESI
    //         00545afa     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         00545aff     MOV        this,dword ptr [EBP + 0x5c]
    //         00545b02     PUSH       EAX=>DAT_fffffff0
    //         00545b03     PUSH       0x1
    //         00545b05     PUSH       ESI
    //         00545b06     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         00545b0b     MOV        EDX,dword ptr [ESP + EDI*0x4 + 0x48]
    //         00545b0f     PUSH       EAX
    //         00545b10     MOV        EAX,dword ptr [EBP + 0x40]
    //         00545b13     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00545b16     CALL       dword ptr [EBX + 0x2c]
    //                               LAB_00545b19                                                 XREF[2]:     00545ac9(j), 00545ad2(j)  
    //         00545b19     MOVSX      this,word ptr [EBP + 0x3c]
    //         00545b1d     INC        EDI
    //         00545b1e     CMP        EDI,this
    //         00545b20     JL         LAB_00545abc
    //                               LAB_00545b22                                                 XREF[2]:     00545aba(j), 00545ac0(j)  
    //                              World.cpp:3455 (10)
    //         00545b22     POP        EDI
    //         00545b23     POP        ESI
    //         00545b24     POP        EBP
    //         00545b25     POP        EBX
    //         00545b26     ADD        ESP,0x4c
    //         00545b29     RET        0x8
    //         00545b2c     ??         90h
    //         00545b2d     NOP
    //         00545b2e     NOP
    //         00545b2f     NOP
    return;
}

void RGE_Game_World::selectNextComputerPlayer(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall selectNextComputerPlayer(RGE_Game_World * this, int 
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00545b4e(R), 00545b94(R)  
    //                               ?selectNextComputerPlayer@RGE_Game_World@@QAEXH@Z            XREF[2]:     doSomething:004f0b4d(c), 
    //                               RGE_Game_World::selectNextComputerPlayer                                  update:005125df(c)  
    //                              World.cpp:3460 (6)
    //         00545b30     PUSH       EBX
    //         00545b31     PUSH       EBP
    //         00545b32     MOV        EBP,this
    //         00545b34     PUSH       ESI
    //         00545b35     PUSH       EDI
    //                              World.cpp:3466 (11)
    //         00545b36     MOV        this,dword ptr [EBP + 0xfc]
    //         00545b3c     CMP        this,-0x1
    //         00545b3f     JNZ        LAB_00545b79
    //                              World.cpp:3467 (10)
    //         00545b41     MOVSX      ESI,word ptr [EBP + 0x3c]
    //         00545b45     XOR        EAX,EAX
    //         00545b47     TEST       ESI,ESI
    //         00545b49     JLE        LAB_00545bb8
    //                              World.cpp:3487 (33)
    //         00545b4b     MOV        EDX,dword ptr [EBP + 0x40]
    //         00545b4e     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_00545b52                                                 XREF[1]:     00545b63(j)  
    //         00545b52     MOV        this,dword ptr [EDX]
    //         00545b54     XOR        EBX,EBX
    //         00545b56     MOV        BL,byte ptr [ECX + this->master_players]
    //         00545b59     CMP        EBX,EDI
    //         00545b5b     JZ         LAB_00545b6c
    //         00545b5d     INC        EAX
    //         00545b5e     ADD        EDX,0x4
    //         00545b61     CMP        EAX,ESI
    //         00545b63     JL         LAB_00545b52
    //         00545b65     POP        EDI
    //         00545b66     POP        ESI
    //         00545b67     POP        EBP
    //         00545b68     POP        EBX
    //         00545b69     RET        0x4
    //                               LAB_00545b6c                                                 XREF[1]:     00545b5b(j)  
    //                              World.cpp:3469 (6)
    //         00545b6c     MOV        dword ptr [EBP + 0xfc],EAX
    //                              World.cpp:3487 (7)
    //         00545b72     POP        EDI
    //         00545b73     POP        ESI
    //         00545b74     POP        EBP
    //         00545b75     POP        EBX
    //         00545b76     RET        0x4
    //                               LAB_00545b79                                                 XREF[1]:     00545b3f(j)  
    //                              World.cpp:3479 (16)
    //         00545b79     MOVSX      ESI,word ptr [EBP + 0x3c]
    //         00545b7d     MOV        EDX,this
    //         00545b7f     XOR        EDI,EDI
    //         00545b81     CMP        EDX,ESI
    //         00545b83     JGE        LAB_00545bb8
    //                               LAB_00545b85                                                 XREF[1]:     00545ba9(j)  
    //         00545b85     CMP        EDI,ESI
    //         00545b87     JGE        LAB_00545bb8
    //                              World.cpp:3480 (23)
    //         00545b89     MOV        EAX,dword ptr [EBP + 0x40]
    //         00545b8c     XOR        EBX,EBX
    //         00545b8e     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //         00545b91     MOV        BL,byte ptr [EAX + 0x48]
    //         00545b94     MOV        EAX,dword ptr [ESP + param_1]
    //         00545b98     CMP        EBX,EAX
    //         00545b9a     JNZ        LAB_00545ba0
    //         00545b9c     CMP        EDX,this
    //         00545b9e     JNZ        LAB_00545bb2
    //                               LAB_00545ba0                                                 XREF[1]:     00545b9a(j)  
    //                              World.cpp:3485 (11)
    //         00545ba0     LEA        EAX,[EDX + 0x1]
    //         00545ba3     CDQ
    //         00545ba4     IDIV       ESI
    //         00545ba6     INC        EDI
    //         00545ba7     CMP        EDX,ESI
    //         00545ba9     JL         LAB_00545b85
    //                              World.cpp:3487 (7)
    //         00545bab     POP        EDI
    //         00545bac     POP        ESI
    //         00545bad     POP        EBP
    //         00545bae     POP        EBX
    //         00545baf     RET        0x4
    //                               LAB_00545bb2                                                 XREF[1]:     00545b9e(j)  
    //                              World.cpp:3481 (6)
    //         00545bb2     MOV        dword ptr [EBP + 0xfc],EDX
    //                               LAB_00545bb8                                                 XREF[3]:     00545b49(j), 00545b83(j), 
    //                                                                                                         00545b87(j)  
    //                              World.cpp:3487 (7)
    //         00545bb8     POP        EDI
    //         00545bb9     POP        ESI
    //         00545bba     POP        EBP
    //         00545bbb     POP        EBX
    //         00545bbc     RET        0x4
    //         00545bbf     ??         90h
    return;
}

void RGE_Game_World::useComputerPlayerUpdateTime(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall useComputerPlayerUpdateTime(RGE_Game_World * this, u
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00545bc6(R)  
    //                               ?useComputerPlayerUpdateTime@RGE_Game_World@@QAEXK@Z         XREF[2]:     doSomething:004f0a47(c), 
    //                               RGE_Game_World::useComputerPlayerUpdateTime                               doSomething:004f0aea(c)  
    //                              World.cpp:3492 (14)
    //         00545bc0     MOV        EAX,dword ptr [ECX + this->availableComputerPl
    //         00545bc6     MOV        EDX,dword ptr [ESP + param_1]
    //         00545bca     CMP        EAX,EDX
    //         00545bcc     JNC        LAB_00545bdb
    //                              World.cpp:3494 (10)
    //         00545bce     MOV        dword ptr [ECX + this->availableComputerPlayer
    //                              World.cpp:3497 (3)
    //         00545bd8     RET        0x4
    //                               LAB_00545bdb                                                 XREF[1]:     00545bcc(j)  
    //                              World.cpp:3496 (8)
    //         00545bdb     SUB        EAX,EDX
    //         00545bdd     MOV        dword ptr [ECX + this->availableComputerPlayer
    //                              World.cpp:3497 (3)
    //         00545be3     RET        0x4
    //         00545be6     ??         90h
    //         00545be7     NOP
    //         00545be8     NOP
    //         00545be9     NOP
    //         00545bea     NOP
    //         00545beb     NOP
    //         00545bec     NOP
    //         00545bed     NOP
    //         00545bee     NOP
    //         00545bef     NOP
    return;
}

int RGE_Game_World::computerPlayerUpdateTimeAvailable() {
    /* TODO: Stub */
    //                              int __thiscall computerPlayerUpdateTimeAvailable(RGE_Game_World * th
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?computerPlayerUpdateTimeAvailable@RGE_Game_World@@QAEHXZ
    //                               RGE_Game_World::computerPlayerUpdateTimeAvailable
    //                              World.cpp:3502 (14)
    //         00545bf0     MOV        EDX,dword ptr [ECX + this->availableComputerPl
    //         00545bf6     XOR        EAX,EAX
    //         00545bf8     CMP        EAX,EDX
    //         00545bfa     SBB        EAX,EAX
    //         00545bfc     NEG        EAX
    //                              World.cpp:3506 (1)
    //         00545bfe     RET
    //         00545bff     ??         90h
    return 0;
}

int RGE_Game_World::objectGroupOnTile(int param_1, int param_2, int param_3, int param_4, int* param_5) {
    /* TODO: Stub */
    //                              int __thiscall objectGroupOnTile(RGE_Game_World * this, int param_1,
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00545c58(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00545c54(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00545c00(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00545c0e(R)  
    //              int *             Stack[0x14]:4  param_5                   XREF[2]:     00545c29(R), 00545c94(R)  
    //                               ?objectGroupOnTile@RGE_Game_World@@QAEHHHHHAAH@Z             XREF[2]:     findTilePath:0046c8ca(c), 
    //                               RGE_Game_World::objectGroupOnTile                                         copyPath:0046da0c(c)  
    //                              World.cpp:3512 (35)
    //         00545c00     MOV        EAX,dword ptr [ESP + param_3]
    //         00545c04     PUSH       ESI
    //         00545c05     TEST       EAX,EAX
    //         00545c07     PUSH       EDI
    //         00545c08     JL         LAB_00545c94
    //         00545c0e     MOV        EDX,dword ptr [ESP + param_4]
    //         00545c12     TEST       EDX,EDX
    //         00545c14     JL         LAB_00545c94
    //         00545c16     MOV        ESI,dword ptr [ECX + this->map]
    //         00545c19     CMP        EAX,dword ptr [ESI + 0x8]
    //         00545c1c     JGE        LAB_00545c94
    //         00545c1e     CMP        EDX,dword ptr [ESI + 0xc]
    //         00545c21     JGE        LAB_00545c94
    //                              World.cpp:3519 (29)
    //         00545c23     MOV        ESI,dword ptr [ESI + 0x8d8c]
    //         00545c29     MOV        EDI,dword ptr [ESP + param_5]
    //         00545c2d     SHL        EDX,0x2
    //         00545c30     LEA        EAX,[EAX + EAX*0x2]
    //         00545c33     MOV        ESI,dword ptr [ESI + EDX*0x1]
    //         00545c36     SHL        EAX,0x3
    //         00545c39     MOVSX      ESI,word ptr [ESI + EAX*0x1 + 0x14]
    //         00545c3e     MOV        dword ptr [EDI],ESI
    //                              World.cpp:3520 (16)
    //         00545c40     MOV        this,dword ptr [ECX + this->map]
    //         00545c43     MOV        this,dword ptr [this->_padding_ + 0x8d8c]
    //         00545c49     MOV        EDX,dword ptr [this->_padding_ + EDX*0x1]
    //         00545c4c     MOV        EAX,dword ptr [EDX + EAX*0x1 + 0x10]
    //                              World.cpp:3521 (12)
    //         00545c50     TEST       EAX,EAX
    //         00545c52     JZ         LAB_00545c9e
    //         00545c54     MOV        ESI,dword ptr [ESP + param_2]
    //         00545c58     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_00545c5c                                                 XREF[1]:     00545c82(j)  
    //                              World.cpp:3522 (2)
    //         00545c5c     MOV        this,dword ptr [EAX]
    //                              World.cpp:3523 (4)
    //         00545c5e     TEST       this,this
    //         00545c60     JZ         LAB_00545c9e
    //                              World.cpp:3525 (14)
    //         00545c62     CMP        EDX,-0x1
    //         00545c65     JZ         LAB_00545c72
    //         00545c67     MOV        EDI,dword ptr [ECX + this->world_time_delta]
    //         00545c6a     MOVSX      EDI,word ptr [EDI + 0x4a]
    //         00545c6e     CMP        EDI,EDX
    //                              World.cpp:3527 (2)
    //         00545c70     JNZ        LAB_00545c7d
    //                               LAB_00545c72                                                 XREF[1]:     00545c65(j)  
    //                              World.cpp:3529 (11)
    //         00545c72     MOV        EDI,dword ptr [ECX + this->old_world_time]
    //         00545c75     MOVSX      EDI,word ptr [EDI + 0x14]
    //         00545c79     CMP        EDI,ESI
    //         00545c7b     JZ         LAB_00545c8c
    //                               LAB_00545c7d                                                 XREF[1]:     00545c70(j)  
    //                              World.cpp:3531 (7)
    //         00545c7d     MOV        EAX,dword ptr [EAX + 0x4]
    //         00545c80     TEST       EAX,EAX
    //         00545c82     JNZ        LAB_00545c5c
    //                              World.cpp:3516 (3)
    //         00545c84     OR         EAX,0xffffffff
    //                              World.cpp:3536 (5)
    //         00545c87     POP        EDI
    //         00545c88     POP        ESI
    //         00545c89     RET        0x14
    //                               LAB_00545c8c                                                 XREF[1]:     00545c7b(j)  
    //                              World.cpp:3530 (3)
    //         00545c8c     MOV        EAX,dword ptr [ECX + this->world_time]
    //                              World.cpp:3536 (5)
    //         00545c8f     POP        EDI
    //         00545c90     POP        ESI
    //         00545c91     RET        0x14
    //                               LAB_00545c94                                                 XREF[4]:     00545c08(j), 00545c14(j), 
    //                                                                                                         00545c1c(j), 00545c21(j)  
    //                              World.cpp:3515 (10)
    //         00545c94     MOV        EAX,dword ptr [ESP + param_5]
    //         00545c98     MOV        dword ptr [EAX],0x0
    //                               LAB_00545c9e                                                 XREF[2]:     00545c52(j), 00545c60(j)  
    //                              World.cpp:3536 (8)
    //         00545c9e     POP        EDI
    //         00545c9f     OR         EAX,0xffffffff
    //         00545ca2     POP        ESI
    //         00545ca3     RET        0x14
    //         00545ca6     ??         90h
    //         00545ca7     NOP
    //         00545ca8     NOP
    //         00545ca9     NOP
    //         00545caa     NOP
    //         00545cab     NOP
    //         00545cac     NOP
    //         00545cad     NOP
    //         00545cae     NOP
    //         00545caf     NOP
    return 0;
}

int RGE_Game_World::difficultyLevel() {
    /* TODO: Stub */
    //                              int __thiscall difficultyLevel(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?difficultyLevel@RGE_Game_World@@QAEHXZ                      XREF[10]:    bestUnitToAttack:004151cb(c), 
    //                               RGE_Game_World::difficultyLevel                                           addObject:004f0e7d(c), 
    //                                                                                                         notify:004f6432(c), 
    //                                                                                                         notify:004f6454(c), 
    //                                                                                                         notify:004f730d(c), 
    //                                                                                                         notify:004f7332(c), 
    //                                                                                                         processNotify:00504578(c), 
    //                                                                                                         processIdle:00504651(c), 
    //                                                                                                         processNotify:00504e44(c), 
    //                                                                                                         processIdle:0050771d(c)  
    //                              World.cpp:3541 (3)
    //         00545cb0     PUSH       ESI
    //         00545cb1     MOV        ESI,this
    //                              World.cpp:3543 (9)
    //         00545cb3     CMP        dword ptr [ESI + 0x100],-0x1
    //         00545cba     JNZ        LAB_00545ccd
    //                              World.cpp:3544 (17)
    //         00545cbc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00545cc2     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         00545cc7     MOV        dword ptr [ESI + 0x100],EAX
    //                               LAB_00545ccd                                                 XREF[1]:     00545cba(j)  
    //                              World.cpp:3545 (6)
    //         00545ccd     MOV        EAX,dword ptr [ESI + 0x100]
    //                              World.cpp:3546 (2)
    //         00545cd3     POP        ESI
    //         00545cd4     RET
    //         00545cd5     ??         90h
    //         00545cd6     NOP
    //         00545cd7     NOP
    //         00545cd8     NOP
    //         00545cd9     NOP
    //         00545cda     NOP
    //         00545cdb     NOP
    //         00545cdc     NOP
    //         00545cdd     NOP
    //         00545cde     NOP
    //         00545cdf     NOP
    return 0;
}

RGE_Scenario* RGE_Game_World::get_scenario_info(char* param_1) {
    /* TODO: Stub */
    //                              RGE_Scenario * __thiscall get_scenario_info(RGE_Game_World * this, c
    //              RGE_Scenario *    EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?get_scenario_info@RGE_Game_World@@UAEPAVRGE_Scenario@@PAD@Z XREF[2]:     00577540(*), 005779f8(*)  
    //                               RGE_Game_World::get_scenario_info
    //                              World.cpp:3550 (2)
    //         00545ce0     XOR        EAX,EAX
    //                              World.cpp:3553 (3)
    //         00545ce2     RET        0x4
    //         00545ce5     ??         90h
    //         00545ce6     NOP
    //         00545ce7     NOP
    //         00545ce8     NOP
    //         00545ce9     NOP
    //         00545cea     NOP
    //         00545ceb     NOP
    //         00545cec     NOP
    //         00545ced     NOP
    //         00545cee     NOP
    //         00545cef     NOP
    return 0;
}

int RGE_Game_World::maxNumberObjects() {
    /* TODO: Stub */
    //                              int __thiscall maxNumberObjects(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?maxNumberObjects@RGE_Game_World@@QAEHXZ
    //                               RGE_Game_World::maxNumberObjects
    //                              World.cpp:3559 (6)
    //         00545cf0     MOV        EAX,dword ptr [ECX + this->maxNumberObjectsVal
    //                              World.cpp:3561 (1)
    //         00545cf6     RET
    //         00545cf7     ??         90h
    //         00545cf8     NOP
    //         00545cf9     NOP
    //         00545cfa     NOP
    //         00545cfb     NOP
    //         00545cfc     NOP
    //         00545cfd     NOP
    //         00545cfe     NOP
    //         00545cff     NOP
    return 0;
}

int RGE_Game_World::maxNumberNegativeObjects() {
    /* TODO: Stub */
    //                              int __thiscall maxNumberNegativeObjects(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?maxNumberNegativeObjects@RGE_Game_World@@QAEHXZ
    //                               RGE_Game_World::maxNumberNegativeObjects
    //                              World.cpp:3567 (6)
    //         00545d00     MOV        EAX,dword ptr [ECX + this->maxNumberNegativeOb
    //                              World.cpp:3569 (1)
    //         00545d06     RET
    //         00545d07     ??         90h
    //         00545d08     NOP
    //         00545d09     NOP
    //         00545d0a     NOP
    //         00545d0b     NOP
    //         00545d0c     NOP
    //         00545d0d     NOP
    //         00545d0e     NOP
    //         00545d0f     NOP
    return 0;
}

int RGE_Game_World::numberObjects() {
    /* TODO: Stub */
    //                              int __thiscall numberObjects(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?numberObjects@RGE_Game_World@@QAEHXZ
    //                               RGE_Game_World::numberObjects
    //                              World.cpp:3575 (6)
    //         00545d10     MOV        EAX,dword ptr [ECX + this->numberObjectsValue]
    //                              World.cpp:3577 (1)
    //         00545d16     RET
    //         00545d17     ??         90h
    //         00545d18     NOP
    //         00545d19     NOP
    //         00545d1a     NOP
    //         00545d1b     NOP
    //         00545d1c     NOP
    //         00545d1d     NOP
    //         00545d1e     NOP
    //         00545d1f     NOP
    return 0;
}

int RGE_Game_World::numberNegativeObjects() {
    /* TODO: Stub */
    //                              int __thiscall numberNegativeObjects(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?numberNegativeObjects@RGE_Game_World@@QAEHXZ
    //                               RGE_Game_World::numberNegativeObjects
    //                              World.cpp:3583 (6)
    //         00545d20     MOV        EAX,dword ptr [ECX + this->numberNegativeObjec
    //                              World.cpp:3585 (1)
    //         00545d26     RET
    //         00545d27     ??         90h
    //         00545d28     NOP
    //         00545d29     NOP
    //         00545d2a     NOP
    //         00545d2b     NOP
    //         00545d2c     NOP
    //         00545d2d     NOP
    //         00545d2e     NOP
    //         00545d2f     NOP
    return 0;
}

RGE_Static_Object* RGE_Game_World::object(int param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall object(RGE_Game_World * this, int par
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00545d30(R)  
    //                               ?object@RGE_Game_World@@QAEPAVRGE_Static_Object@@H@Z         XREF[181]:   set_target_obj:00407a40(c), 
    //                               RGE_Game_World::object                                                    set_target_obj2:00407ab0(c), 
    //                                                                                                         object:0040d76e(c), 
    //                                                                                                         object:0040d81c(c), 
    //                                                                                                         do_command_ai_order:00434d4f(c), 
    //                                                                                                         command_ai_order:00435e08(c), 
    //                                                                                                         command_ai_order:00435e15(c), 
    //                                                                                                         findTilePath:0046b933(c), 
    //                                                                                                         findTilePath:0046bb08(c), 
    //                                                                                                         findTilePath:0046c8f0(c), 
    //                                                                                                         findTilePath:0046cb89(c), 
    //                                                                                                         findTilePath:0046cc73(c), 
    //                                                                                                         findTilePath:0046cd7b(c), 
    //                                                                                                         findTilePath:0046ce67(c), 
    //                                                                                                         findTilePath:0046d07a(c), 
    //                                                                                                         findTilePath:0046d157(c), 
    //                                                                                                         build:004cb5e6(c), 
    //                                                                                                         idleCivilian:004f7f08(c), 
    //                                                                                                         idleCivilian:004f8052(c), 
    //                                                                                                         idleCivilian:004f8238(c), [more]
    //                              World.cpp:3591 (9)
    //         00545d30     MOV        EDX,dword ptr [ESP + param_1]
    //         00545d34     PUSH       ESI
    //         00545d35     TEST       EDX,EDX
    //         00545d37     JGE        LAB_00545d54
    //                              World.cpp:3596 (14)
    //         00545d39     MOV        ESI,dword ptr [ECX + this->maxNumberNegativeOb
    //         00545d3f     MOV        EAX,EDX
    //         00545d41     NEG        EAX
    //         00545d43     CMP        EAX,ESI
    //         00545d45     JGE        LAB_00545d54
    //                              World.cpp:3597 (9)
    //         00545d47     MOV        this,dword ptr [ECX + this->negativeObjectsVal
    //         00545d4d     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //                              World.cpp:3603 (4)
    //         00545d50     POP        ESI
    //         00545d51     RET        0x4
    //                               LAB_00545d54                                                 XREF[2]:     00545d37(j), 00545d45(j)  
    //                              World.cpp:3600 (13)
    //         00545d54     CMP        EDX,-0x1
    //         00545d57     JLE        LAB_00545d6e
    //         00545d59     CMP        EDX,dword ptr [ECX + this->maxNumberObjectsVal
    //         00545d5f     JGE        LAB_00545d6e
    //                              World.cpp:3601 (9)
    //         00545d61     MOV        EAX,dword ptr [ECX + this->objectsValue]
    //         00545d67     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //                              World.cpp:3603 (4)
    //         00545d6a     POP        ESI
    //         00545d6b     RET        0x4
    //                               LAB_00545d6e                                                 XREF[2]:     00545d57(j), 00545d5f(j)  
    //                              World.cpp:3602 (2)
    //         00545d6e     XOR        EAX,EAX
    //                              World.cpp:3603 (4)
    //         00545d70     POP        ESI
    //         00545d71     RET        0x4
    //         00545d74     ??         90h
    //         00545d75     NOP
    //         00545d76     NOP
    //         00545d77     NOP
    //         00545d78     NOP
    //         00545d79     NOP
    //         00545d7a     NOP
    //         00545d7b     NOP
    //         00545d7c     NOP
    //         00545d7d     NOP
    //         00545d7e     NOP
    //         00545d7f     NOP
    return 0;
}

RGE_Static_Object* RGE_Game_World::object_ptr(int param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall object_ptr(RGE_Game_World * this, int
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00545d80(R)  
    //                               ?object_ptr@RGE_Game_World@@QAEPAVRGE_Static_Object@@H@Z
    //                               RGE_Game_World::object_ptr
    //                              World.cpp:3609 (10)
    //         00545d80     MOV        EAX,dword ptr [ESP + param_1]
    //         00545d84     PUSH       EAX
    //         00545d85     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              World.cpp:3630 (3)
    //         00545d8a     RET        0x4
    //         00545d8d     ??         90h
    //         00545d8e     NOP
    //         00545d8f     NOP
    return 0;
}

long RGE_Game_World::get_next_object_id() {
    /* TODO: Stub */
    //                              long __thiscall get_next_object_id(RGE_Game_World * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?get_next_object_id@RGE_Game_World@@QAEJXZ                   XREF[2]:     setup:004c1776(c), 
    //                               RGE_Game_World::get_next_object_id                                        change_unique_id:004c1d2f(c)  
    //                              World.cpp:3636 (7)
    //         00545d90     MOV        AL,byte ptr [ECX + this->scenario_object_flag]
    //         00545d93     TEST       AL,AL
    //         00545d95     JNZ        LAB_00545dca
    //                              World.cpp:3641 (32)
    //         00545d97     MOV        EAX,dword ptr [ECX + this->maxNumberObjectsVal
    //         00545d9d     PUSH       ESI
    //         00545d9e     LEA        EDX,[EAX + -0x1]
    //         00545da1     MOV        EAX,dword ptr [ECX + this->next_object_id]
    //         00545da4     CMP        EDX,EAX
    //         00545da6     JL         LAB_00545dbf
    //         00545da8     MOV        ESI,dword ptr [ECX + this->objectsValue]
    //                               LAB_00545dae                                                 XREF[1]:     00545dbd(j)  
    //         00545dae     MOV        EAX,dword ptr [ECX + this->next_object_id]
    //         00545db1     CMP        dword ptr [ESI + EAX*0x4],0x0
    //         00545db5     JZ         LAB_00545dbf
    //                              World.cpp:3642 (8)
    //         00545db7     INC        EAX
    //         00545db8     CMP        EDX,EAX
    //         00545dba     MOV        dword ptr [ECX + this->next_object_id],EAX
    //         00545dbd     JGE        LAB_00545dae
    //                               LAB_00545dbf                                                 XREF[2]:     00545da6(j), 00545db5(j)  
    //                              World.cpp:3644 (4)
    //         00545dbf     MOV        EAX,dword ptr [ECX + this->next_object_id]
    //         00545dc2     POP        ESI
    //                              World.cpp:3645 (6)
    //         00545dc3     LEA        EDX,[EAX + 0x1]
    //         00545dc6     MOV        dword ptr [ECX + this->next_object_id],EDX
    //                              World.cpp:3651 (1)
    //         00545dc9     RET
    //                               LAB_00545dca                                                 XREF[1]:     00545d95(j)  
    //                              World.cpp:3648 (3)
    //         00545dca     MOV        EAX,dword ptr [ECX + this->scenario_object_id]
    //                              World.cpp:3651 (1)
    //         00545dcd     RET
    //         00545dce     ??         90h
    //         00545dcf     NOP
    return 0;
}

long RGE_Game_World::get_next_reusable_object_id() {
    /* TODO: Stub */
    //                              long __thiscall get_next_reusable_object_id(RGE_Game_World * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?get_next_reusable_object_id@RGE_Game_World@@QAEJXZ          XREF[2]:     setup:004c1769(c), 
    //                               RGE_Game_World::get_next_reusable_object_id                               change_unique_id:004c1d22(c)  
    //                              World.cpp:3657 (7)
    //         00545dd0     MOV        AL,byte ptr [ECX + this->scenario_object_flag]
    //         00545dd3     TEST       AL,AL
    //         00545dd5     JZ         LAB_00545de8
    //                              World.cpp:3662 (3)
    //         00545dd7     MOV        EAX,dword ptr [ECX + this->scenario_object_id]
    //                              World.cpp:3663 (7)
    //         00545dda     MOV        EDX,dword ptr [ECX + this->next_reusable_objec
    //         00545ddd     CMP        EAX,EDX
    //         00545ddf     JGE        LAB_00545df1
    //                              World.cpp:3669 (6)
    //         00545de1     LEA        EDX,[EAX + -0x1]
    //         00545de4     MOV        dword ptr [ECX + this->next_reusable_object_id
    //                              World.cpp:3673 (1)
    //         00545de7     RET
    //                               LAB_00545de8                                                 XREF[1]:     00545dd5(j)  
    //                              World.cpp:3668 (3)
    //         00545de8     MOV        EAX,dword ptr [ECX + this->next_reusable_objec
    //                              World.cpp:3669 (6)
    //         00545deb     LEA        EDX,[EAX + -0x1]
    //         00545dee     MOV        dword ptr [ECX + this->next_reusable_object_id
    //                               LAB_00545df1                                                 XREF[1]:     00545ddf(j)  
    //                              World.cpp:3673 (1)
    //         00545df1     RET
    //         00545df2     ??         90h
    //         00545df3     NOP
    //         00545df4     NOP
    //         00545df5     NOP
    //         00545df6     NOP
    //         00545df7     NOP
    //         00545df8     NOP
    //         00545df9     NOP
    //         00545dfa     NOP
    //         00545dfb     NOP
    //         00545dfc     NOP
    //         00545dfd     NOP
    //         00545dfe     NOP
    //         00545dff     NOP
    return 0;
}

int RGE_Game_World::addObject(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall addObject(RGE_Game_World * this, RGE_Static_Object * 
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     00545e01(R), 00545ea1(R), 00545f93(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00545e10(W), 00545e32(R), 00545f0a(W), 00545f20(R), 
    //                                                                                     00545f83(R)  
    //              int               Stack[-0x8]:4  lookupSlot
    //                               ?addObject@RGE_Game_World@@UAEHPAVRGE_Static_Object@@@Z      XREF[2]:     00577550(*), 00577a08(*)  
    //                               RGE_Game_World::addObject
    //                              World.cpp:3679 (1)
    //         00545e00     PUSH       this
    //                              World.cpp:3681 (25)
    //         00545e01     MOV        EDX,dword ptr [ESP + param_1]
    //         00545e05     PUSH       EBX
    //         00545e06     PUSH       EBP
    //         00545e07     PUSH       ESI
    //         00545e08     MOV        EAX,dword ptr [EDX + 0x4]
    //         00545e0b     PUSH       EDI
    //         00545e0c     TEST       EAX,EAX
    //         00545e0e     MOV        ESI,this
    //         00545e10     MOV        dword ptr [ESP + local_4],EAX
    //         00545e14     JL         LAB_00545f00
    //                              World.cpp:3686 (17)
    //         00545e1a     MOV        this,dword ptr [ESI + 0x90]
    //         00545e20     LEA        EDI,[this->_padding_ + -0x1]
    //         00545e23     CMP        EDI,EAX
    //         00545e25     JGE        LAB_00545eba
    //                              World.cpp:3688 (3)
    //         00545e2b     LEA        EBP,[ECX + ECX*0x1]
    //                              World.cpp:3691 (4)
    //         00545e2e     CMP        EBP,EAX
    //         00545e30     JGE        LAB_00545e43
    //                              World.cpp:3692 (17)
    //         00545e32     FILD       dword ptr [ESP + local_4]
    //         00545e36     FMUL       float ptr [DAT_00577a1c]                         = CDh
    //         00545e3c     CALL       __ftol                                           undefined __ftol()
    //         00545e41     MOV        EBP,EAX
    //                               LAB_00545e43                                                 XREF[1]:     00545e30(j)  
    //                              World.cpp:3694 (18)
    //         00545e43     LEA        EAX,[EBP*0x4 + 0x0]
    //         00545e4a     PUSH       EAX
    //         00545e4b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00545e50     MOV        EBX,EAX
    //         00545e52     ADD        ESP,0x4
    //                              World.cpp:3695 (4)
    //         00545e55     TEST       EBX,EBX
    //         00545e57     JNZ        LAB_00545e61
    //                              World.cpp:3760 (8)
    //         00545e59     POP        EDI
    //         00545e5a     POP        ESI
    //         00545e5b     POP        EBP
    //         00545e5c     POP        EBX
    //         00545e5d     POP        this
    //         00545e5e     RET        0x4
    //                               LAB_00545e61                                                 XREF[1]:     00545e57(j)  
    //                              World.cpp:3700 (12)
    //         00545e61     MOV        this,dword ptr [ESI + 0x90]
    //         00545e67     XOR        EAX,EAX
    //         00545e69     TEST       this,this
    //         00545e6b     JLE        LAB_00545e86
    //                               LAB_00545e6d                                                 XREF[1]:     00545e84(j)  
    //                              World.cpp:3701 (25)
    //         00545e6d     MOV        this,dword ptr [ESI + 0x88]
    //         00545e73     INC        EAX
    //         00545e74     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         00545e78     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         00545e7c     MOV        this,dword ptr [ESI + 0x90]
    //         00545e82     CMP        EAX,this
    //         00545e84     JL         LAB_00545e6d
    //                               LAB_00545e86                                                 XREF[1]:     00545e6b(j)  
    //                              World.cpp:3702 (15)
    //         00545e86     CMP        EAX,EBP
    //         00545e88     JGE        LAB_00545e95
    //         00545e8a     MOV        this,EBP
    //         00545e8c     LEA        EDI,[EBX + EAX*0x4]
    //         00545e8f     SUB        this,EAX
    //         00545e91     XOR        EAX,EAX
    //         00545e93     STOSD.REP  ES:EDI
    //                               LAB_00545e95                                                 XREF[1]:     00545e88(j)  
    //                              World.cpp:3704 (12)
    //         00545e95     MOV        EAX,dword ptr [ESI + 0x88]
    //         00545e9b     PUSH       EAX
    //         00545e9c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              World.cpp:3707 (25)
    //         00545ea1     MOV        EDX,dword ptr [ESP + param_1]
    //         00545ea5     MOV        dword ptr [ESI + 0x88],EBX
    //         00545eab     MOV        dword ptr [VIS_UNIT_objectsValue],EBX            = 00000000
    //         00545eb1     ADD        ESP,0x4
    //         00545eb4     MOV        dword ptr [ESI + 0x90],EBP
    //                               LAB_00545eba                                                 XREF[1]:     00545e25(j)  
    //                              World.cpp:3711 (14)
    //         00545eba     MOV        this,dword ptr [EDX + 0x4]
    //         00545ebd     MOV        EAX,dword ptr [ESI + 0x88]
    //         00545ec3     LEA        EAX,[EAX + this->_padding_*0x4]
    //         00545ec6     MOV        this,dword ptr [EAX]
    //                              World.cpp:3712 (2)
    //         00545ec8     MOV        dword ptr [EAX],EDX
    //                              World.cpp:3713 (7)
    //         00545eca     MOV        EDX,dword ptr [ESI + 0x8c]
    //         00545ed0     INC        EDX
    //                              World.cpp:3715 (14)
    //         00545ed1     TEST       this,this
    //         00545ed3     MOV        dword ptr [ESI + 0x8c],EDX
    //         00545ed9     JZ         LAB_00545fbc
    //                              World.cpp:3717 (11)
    //         00545edf     MOV        AL,byte ptr [ESI + 0x74]
    //         00545ee2     TEST       AL,AL
    //         00545ee4     JZ         LAB_00545fbc
    //                              World.cpp:3719 (4)
    //         00545eea     MOV        byte ptr [ESI + 0x74],0x0
    //                              World.cpp:3720 (5)
    //         00545eee     CALL       RGE_Static_Object::change_unique_id              void change_unique_id(RGE_Static_Object * this)
    //                              World.cpp:3759 (5)
    //         00545ef3     MOV        EAX,0x1
    //                              World.cpp:3760 (8)
    //         00545ef8     POP        EDI
    //         00545ef9     POP        ESI
    //         00545efa     POP        EBP
    //         00545efb     POP        EBX
    //         00545efc     POP        this
    //         00545efd     RET        0x4
    //                               LAB_00545f00                                                 XREF[1]:     00545e14(j)  
    //                              World.cpp:3730 (4)
    //         00545f00     NEG        EAX
    //         00545f02     MOV        EDI,EAX
    //                              World.cpp:3731 (21)
    //         00545f04     MOV        EAX,dword ptr [ESI + 0x9c]
    //         00545f0a     MOV        dword ptr [ESP + local_4],EDI
    //         00545f0e     LEA        this,[EAX + -0x1]
    //         00545f11     CMP        this,EDI
    //         00545f13     JGE        LAB_00545fa6
    //                              World.cpp:3733 (3)
    //         00545f19     LEA        EBP,[EAX + EAX*0x1]
    //                              World.cpp:3736 (4)
    //         00545f1c     CMP        EBP,EDI
    //         00545f1e     JGE        LAB_00545f31
    //                              World.cpp:3737 (17)
    //         00545f20     FILD       dword ptr [ESP + local_4]
    //         00545f24     FMUL       float ptr [DAT_00577a1c]                         = CDh
    //         00545f2a     CALL       __ftol                                           undefined __ftol()
    //         00545f2f     MOV        EBP,EAX
    //                               LAB_00545f31                                                 XREF[1]:     00545f1e(j)  
    //                              World.cpp:3739 (18)
    //         00545f31     LEA        EDX,[EBP*0x4 + 0x0]
    //         00545f38     PUSH       EDX
    //         00545f39     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00545f3e     MOV        EBX,EAX
    //         00545f40     ADD        ESP,0x4
    //                              World.cpp:3740 (4)
    //         00545f43     TEST       EBX,EBX
    //         00545f45     JNZ        LAB_00545f4f
    //                              World.cpp:3760 (8)
    //         00545f47     POP        EDI
    //         00545f48     POP        ESI
    //         00545f49     POP        EBP
    //         00545f4a     POP        EBX
    //         00545f4b     POP        this
    //         00545f4c     RET        0x4
    //                               LAB_00545f4f                                                 XREF[1]:     00545f45(j)  
    //                              World.cpp:3745 (12)
    //         00545f4f     MOV        this,dword ptr [ESI + 0x9c]
    //         00545f55     XOR        EAX,EAX
    //         00545f57     TEST       this,this
    //         00545f59     JLE        LAB_00545f74
    //                               LAB_00545f5b                                                 XREF[1]:     00545f72(j)  
    //                              World.cpp:3746 (25)
    //         00545f5b     MOV        this,dword ptr [ESI + 0x94]
    //         00545f61     INC        EAX
    //         00545f62     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         00545f66     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         00545f6a     MOV        this,dword ptr [ESI + 0x9c]
    //         00545f70     CMP        EAX,this
    //         00545f72     JL         LAB_00545f5b
    //                               LAB_00545f74                                                 XREF[1]:     00545f59(j)  
    //                              World.cpp:3747 (19)
    //         00545f74     CMP        EAX,EBP
    //         00545f76     JGE        LAB_00545f87
    //         00545f78     MOV        this,EBP
    //         00545f7a     LEA        EDI,[EBX + EAX*0x4]
    //         00545f7d     SUB        this,EAX
    //         00545f7f     XOR        EAX,EAX
    //         00545f81     STOSD.REP  ES:EDI
    //         00545f83     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_00545f87                                                 XREF[1]:     00545f76(j)  
    //                              World.cpp:3749 (12)
    //         00545f87     MOV        EAX,dword ptr [ESI + 0x94]
    //         00545f8d     PUSH       EAX
    //         00545f8e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              World.cpp:3751 (19)
    //         00545f93     MOV        EDX,dword ptr [ESP + param_1]
    //         00545f97     ADD        ESP,0x4
    //         00545f9a     MOV        dword ptr [ESI + 0x94],EBX
    //         00545fa0     MOV        dword ptr [ESI + 0x9c],EBP
    //                               LAB_00545fa6                                                 XREF[1]:     00545f13(j)  
    //                              World.cpp:3755 (9)
    //         00545fa6     MOV        this,dword ptr [ESI + 0x94]
    //         00545fac     MOV        dword ptr [this->_padding_ + EDI*0x4],EDX
    //                              World.cpp:3756 (13)
    //         00545faf     MOV        EAX,dword ptr [ESI + 0x98]
    //         00545fb5     INC        EAX
    //         00545fb6     MOV        dword ptr [ESI + 0x98],EAX
    //                               LAB_00545fbc                                                 XREF[2]:     00545ed9(j), 00545ee4(j)  
    //                              World.cpp:3760 (13)
    //         00545fbc     POP        EDI
    //         00545fbd     POP        ESI
    //         00545fbe     POP        EBP
    //         00545fbf     MOV        EAX,0x1
    //         00545fc4     POP        EBX
    //         00545fc5     POP        this
    //         00545fc6     RET        0x4
    //         00545fc9     ??         90h
    //         00545fca     NOP
    //         00545fcb     NOP
    //         00545fcc     NOP
    //         00545fcd     NOP
    //         00545fce     NOP
    //         00545fcf     NOP
    return 0;
}

int RGE_Game_World::removeObject(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall removeObject(RGE_Game_World * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00545fd0(R)  
    //                               ?removeObject@RGE_Game_World@@UAEHH@Z                        XREF[2]:     00577554(*), 00577a0c(*)  
    //                               RGE_Game_World::removeObject
    //                              World.cpp:3766 (9)
    //         00545fd0     MOV        EDX,dword ptr [ESP + param_1]
    //         00545fd4     PUSH       ESI
    //         00545fd5     TEST       EDX,EDX
    //         00545fd7     JGE        LAB_00545ffd
    //                              World.cpp:3771 (14)
    //         00545fd9     MOV        ESI,dword ptr [ECX + this->maxNumberNegativeOb
    //         00545fdf     MOV        EAX,EDX
    //         00545fe1     NEG        EAX
    //         00545fe3     CMP        EAX,ESI
    //         00545fe5     JGE        LAB_00545ffd
    //                              World.cpp:3773 (13)
    //         00545fe7     MOV        this,dword ptr [ECX + this->negativeObjectsVal
    //         00545fed     MOV        dword ptr [this->_padding_ + EAX*0x4],0x0
    //                              World.cpp:3774 (5)
    //         00545ff4     MOV        EAX,0x1
    //                              World.cpp:3783 (4)
    //         00545ff9     POP        ESI
    //         00545ffa     RET        0x4
    //                               LAB_00545ffd                                                 XREF[2]:     00545fd7(j), 00545fe5(j)  
    //                              World.cpp:3777 (13)
    //         00545ffd     CMP        EDX,-0x1
    //         00546000     JLE        LAB_00546020
    //         00546002     CMP        EDX,dword ptr [ECX + this->maxNumberObjectsVal
    //         00546008     JGE        LAB_00546020
    //                              World.cpp:3779 (13)
    //         0054600a     MOV        EAX,dword ptr [ECX + this->objectsValue]
    //         00546010     MOV        dword ptr [EAX + EDX*0x4],0x0
    //                              World.cpp:3780 (5)
    //         00546017     MOV        EAX,0x1
    //                              World.cpp:3783 (4)
    //         0054601c     POP        ESI
    //         0054601d     RET        0x4
    //                               LAB_00546020                                                 XREF[2]:     00546000(j), 00546008(j)  
    //                              World.cpp:3782 (2)
    //         00546020     XOR        EAX,EAX
    //                              World.cpp:3783 (4)
    //         00546022     POP        ESI
    //         00546023     RET        0x4
    //         00546026     ??         90h
    //         00546027     NOP
    //         00546028     NOP
    //         00546029     NOP
    //         0054602a     NOP
    //         0054602b     NOP
    //         0054602c     NOP
    //         0054602d     NOP
    //         0054602e     NOP
    //         0054602f     NOP
    return 0;
}

int RGE_Game_World::initializePathingSystem() {
    /* TODO: Stub */
    //                              int __thiscall initializePathingSystem(RGE_Game_World * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //                               ?initializePathingSystem@RGE_Game_World@@QAEHXZ              XREF[3]:     load_world:0054224c(c), 
    //                               RGE_Game_World::initializePathingSystem                                   new_game:00542b21(c), 
    //                                                                                                         new_random_game:00542d7b(c)  
    //                              World.cpp:3788 (3)
    //         00546030     PUSH       ESI
    //         00546031     MOV        ESI,this
    //                              World.cpp:3790 (7)
    //         00546033     MOV        EAX,dword ptr [ESI + 0x28]
    //         00546036     TEST       EAX,EAX
    //         00546038     JNZ        LAB_0054603c
    //                              World.cpp:3795 (2)
    //         0054603a     POP        ESI
    //         0054603b     RET
    //                               LAB_0054603c                                                 XREF[1]:     00546038(j)  
    //                              World.cpp:3792 (20)
    //         0054603c     MOV        this,dword ptr [EAX + 0xc]
    //         0054603f     MOV        EDX,dword ptr [EAX + 0x8]
    //         00546042     PUSH       ESI
    //         00546043     PUSH       EAX
    //         00546044     PUSH       this
    //         00546045     PUSH       EDX
    //         00546046     MOV        this,pathSystem
    //         0054604b     CALL       PathingSystem::initialize                        int initialize(PathingSystem * this, int para
    //                              World.cpp:3793 (23)
    //         00546050     MOV        EAX,dword ptr [ESI + 0x28]
    //         00546053     PUSH       ESI
    //         00546054     PUSH       EAX
    //         00546055     MOV        this,dword ptr [EAX + 0xc]
    //         00546058     MOV        EDX,dword ptr [EAX + 0x8]
    //         0054605b     PUSH       this
    //         0054605c     PUSH       EDX
    //         0054605d     MOV        this,aiPathSystem
    //         00546062     CALL       PathingSystem::initialize                        int initialize(PathingSystem * this, int para
    //                              World.cpp:3794 (5)
    //         00546067     MOV        EAX,0x1
    //                              World.cpp:3795 (2)
    //         0054606c     POP        ESI
    //         0054606d     RET
    //         0054606e     ??         90h
    //         0054606f     NOP
    //                              * public: unsigned char __thiscall RGE_Game_World::recycle_object_out_of_game(unsigned char,class RG... *
    //                              uchar __thiscall recycle_object_out_of_game(RGE_Game_World * this, u
    //              uchar             AL:1           <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00546070(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[7]:     00546094(R), 005460a9(R), 005460be(R), 005460d3(R), 
    //                                                                                     005460e8(R), 005460fd(R), 00546112(R)  
    //                               ?recycle_object_out_of_game@RGE_Game_World@@QAEEEPAVRGE_Sta  XREF[1]:     recycle_out_of_game:004c15b1(c)  
    //                               RGE_Game_World::recycle_object_out_of_game
    //                              World.cpp:3802 (36)
    //         00546070     MOV        EAX,dword ptr [ESP + param_1]
    //         00546074     AND        EAX,0xff
    //         00546079     ADD        EAX,-0xa
    //         0054607c     CMP        EAX,0x32
    //         0054607f     JA         switchD_0054608d::caseD_b
    //         00546085     XOR        EDX,EDX
    //         00546087     MOV        DL,byte ptr [EAX + 0x54614c]=>PTR_caseD_32_005
    //                               switchD_0054608d::switchD
    //         0054608d     JMP        dword ptr [EDX*0x4 + switchD_0054608d::switchd   = 00546094
    //                               switchD_0054608d::caseD_a                                    XREF[2]:     0054608d(j), 0054612c(*)  
    //                              World.cpp:3806 (11)
    //         00546094     MOV        EAX,dword ptr [ESP + param_2]
    //         00546098     MOV        this,dword ptr [ECX + this->reusable_static_ob
    //         0054609e     PUSH       EAX
    //                              World.cpp:3824 (5)
    //         0054609f     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         005460a4     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         005460a6     RET        0x8
    //                               switchD_0054608d::caseD_14                                   XREF[2]:     0054608d(j), 00546130(*)  
    //                              World.cpp:3809 (11)
    //         005460a9     MOV        EDX,dword ptr [ESP + param_2]
    //         005460ad     MOV        this,dword ptr [ECX + this->reusable_animated_
    //         005460b3     PUSH       EDX
    //                              World.cpp:3824 (5)
    //         005460b4     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         005460b9     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         005460bb     RET        0x8
    //                               switchD_0054608d::caseD_1e                                   XREF[2]:     0054608d(j), 00546138(*)  
    //                              World.cpp:3812 (11)
    //         005460be     MOV        EAX,dword ptr [ESP + param_2]
    //         005460c2     MOV        this,dword ptr [ECX + this->reusable_moving_ob
    //         005460c8     PUSH       EAX
    //                              World.cpp:3824 (5)
    //         005460c9     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         005460ce     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         005460d0     RET        0x8
    //                               switchD_0054608d::caseD_28                                   XREF[2]:     0054608d(j), 0054613c(*)  
    //                              World.cpp:3815 (11)
    //         005460d3     MOV        EDX,dword ptr [ESP + param_2]
    //         005460d7     MOV        this,dword ptr [ECX + this->reusable_action_ob
    //         005460dd     PUSH       EDX
    //                              World.cpp:3824 (5)
    //         005460de     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         005460e3     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         005460e5     RET        0x8
    //                               switchD_0054608d::caseD_32                                   XREF[2]:     0054608d(j), 00546140(*)  
    //                              World.cpp:3818 (11)
    //         005460e8     MOV        EAX,dword ptr [ESP + param_2]
    //         005460ec     MOV        this,dword ptr [ECX + this->reusable_combat_ob
    //         005460f2     PUSH       EAX
    //                              World.cpp:3824 (5)
    //         005460f3     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         005460f8     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         005460fa     RET        0x8
    //                               switchD_0054608d::caseD_3c                                   XREF[2]:     0054608d(j), 00546144(*)  
    //                              World.cpp:3821 (11)
    //         005460fd     MOV        EDX,dword ptr [ESP + param_2]
    //         00546101     MOV        this,dword ptr [ECX + this->reusable_missile_o
    //         00546107     PUSH       EDX
    //                              World.cpp:3824 (5)
    //         00546108     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         0054610d     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         0054610f     RET        0x8
    //                               switchD_0054608d::caseD_19                                   XREF[2]:     0054608d(j), 00546134(*)  
    //                              World.cpp:3824 (16)
    //         00546112     MOV        EAX,dword ptr [ESP + param_2]
    //         00546116     MOV        this,dword ptr [ECX + this->reusable_dopplegan
    //         0054611c     PUSH       EAX
    //         0054611d     CALL       RGE_Object_List::add_node                        RGE_Object_Node * add_node(RGE_Object_List * 
    //                              World.cpp:3832 (2)
    //         00546122     MOV        AL,0x1
    //                              World.cpp:3833 (3)
    //         00546124     RET        0x8
    //                               switchD_0054608d::caseD_c                                    XREF[3]:     0054607f(j), 0054608d(j), 
    //                               switchD_0054608d::caseD_d                                                 00546148(*)  
    //                               switchD_0054608d::caseD_e
    //                               switchD_0054608d::caseD_f
    //                               switchD_0054608d::caseD_10
    //                               switchD_0054608d::caseD_11
    //                               switchD_0054608d::caseD_12
    //                               switchD_0054608d::caseD_13
    //                               switchD_0054608d::caseD_15
    //                               switchD_0054608d::caseD_16
    //                               switchD_0054608d::caseD_17
    //                               switchD_0054608d::caseD_18
    //                               switchD_0054608d::caseD_1a
    //                               switchD_0054608d::caseD_1b
    //                               switchD_0054608d::caseD_1c
    //                               switchD_0054608d::caseD_1d
    //                               switchD_0054608d::caseD_1f
    //                               switchD_0054608d::caseD_20
    //                               switchD_0054608d::caseD_21
    //                               switchD_0054608d::caseD_22
    //                               switchD_0054608d::caseD_23
    //                               switchD_0054608d::caseD_24
    //                               switchD_0054608d::caseD_25
    //                               switchD_0054608d::caseD_26
    //                               switchD_0054608d::caseD_27
    //                               switchD_0054608d::caseD_29
    //                               switchD_0054608d::caseD_2a
    //                               switchD_0054608d::caseD_2b
    //                               switchD_0054608d::caseD_2c
    //                               switchD_0054608d::caseD_2d
    //                               switchD_0054608d::caseD_2e
    //                               switchD_0054608d::caseD_2f
    //                               switchD_0054608d::caseD_30
    //                               switchD_0054608d::caseD_31
    //                               switchD_0054608d::caseD_33
    //                               switchD_0054608d::caseD_34
    //                               switchD_0054608d::caseD_35
    //                               switchD_0054608d::caseD_36
    //                               switchD_0054608d::caseD_37
    //                               switchD_0054608d::caseD_38
    //                               switchD_0054608d::caseD_39
    //                               switchD_0054608d::caseD_3a
    //                               switchD_0054608d::caseD_3b
    //                               switchD_0054608d::caseD_b
    //                              World.cpp:3828 (2)
    //         00546127     XOR        AL,AL
    //                              World.cpp:3833 (86)
    //         00546129     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0054608d::switchdataD_0054612c                       XREF[1]:     recycle_object_out_of_game:0054608
    //         0054612c     addr       switchD_0054608d::caseD_a
    //         00546130     addr       switchD_0054608d::caseD_14
    //         00546134     addr       switchD_0054608d::caseD_19
    //         00546138     addr       switchD_0054608d::caseD_1e
    //         0054613c     addr       switchD_0054608d::caseD_28
    //                               PTR_caseD_32_00546140+2                                      XREF[0,1]:   recycle_object_out_of_game:0054608
    //         00546140     addr       switchD_0054608d::caseD_32
    //         00546144     addr       switchD_0054608d::caseD_3c
    //         00546148     addr       switchD_0054608d::caseD_b
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0054608d::switchdataD_0054614c
    //         0054614c     db         0h
    //         0054614d     db         7h
    //         0054614e     db         7h
    //         0054614f     db         7h
    //         00546150     db         7h
    //         00546151     db         7h
    //         00546152     db         7h
    //         00546153     db         7h
    //         00546154     db         7h
    //         00546155     db         7h
    //         00546156     db         1h
    //         00546157     db         7h
    //         00546158     db         7h
    //         00546159     db         7h
    //         0054615a     db         7h
    //         0054615b     db         2h
    //         0054615c     db         7h
    //         0054615d     db         7h
    //         0054615e     db         7h
    //         0054615f     db         7h
    //         00546160     db         3h
    //         00546161     db         7h
    //         00546162     db         7h
    //         00546163     db         7h
    //         00546164     db         7h
    //         00546165     db         7h
    //         00546166     db         7h
    //         00546167     db         7h
    //         00546168     db         7h
    //         00546169     db         7h
    //         0054616a     db         4h
    //         0054616b     db         7h
    //         0054616c     db         7h
    //         0054616d     db         7h
    //         0054616e     db         7h
    //         0054616f     db         7h
    //         00546170     db         7h
    //         00546171     db         7h
    //         00546172     db         7h
    //         00546173     db         7h
    //         00546174     db         5h
    //         00546175     db         7h
    //         00546176     db         7h
    //         00546177     db         7h
    //         00546178     db         7h
    //         00546179     db         7h
    //         0054617a     db         7h
    //         0054617b     db         7h
    //         0054617c     db         7h
    //         0054617d     db         7h
    //         0054617e     db         6h
    //         0054617f     ??         90h
    return 0;
}

RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(uchar param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall recycle_object_in_to_game(RGE_Game_Wo
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00546180(R)  
    //                               ?recycle_object_in_to_game@RGE_Game_World@@QAEPAVRGE_Static  XREF[7]:     make_new_obj:0044f5cf(c), 
    //                               RGE_Game_World::recycle_object_in_to_game                                 make_new_obj:0044fc2f(c), 
    //                                                                                                         make_new_obj:004506ff(c), 
    //                                                                                                         make_new_obj:004512ff(c), 
    //                                                                                                         make_new_obj:0045179f(c), 
    //                                                                                                         make_new_obj:00451e1f(c), 
    //                                                                                                         make_new_obj:0045300f(c)  
    //                              World.cpp:3841 (39)
    //         00546180     MOV        EAX,dword ptr [ESP + param_1]
    //         00546184     PUSH       ESI
    //         00546185     AND        EAX,0xff
    //         0054618a     XOR        ESI,ESI
    //         0054618c     ADD        EAX,-0xa
    //         0054618f     CMP        EAX,0x32
    //         00546192     JA         switchD_005461a0::caseD_b
    //         00546198     XOR        EDX,EDX
    //         0054619a     MOV        DL,byte ptr [EAX + 0x54629c]=>PTR_caseD_32_005
    //                               switchD_005461a0::switchD
    //         005461a0     JMP        dword ptr [EDX*0x4 + switchD_005461a0::switchd   = 005461a7
    //                               switchD_005461a0::caseD_a                                    XREF[2]:     005461a0(j), 0054627c(*)  
    //                              World.cpp:3847 (17)
    //         005461a7     MOV        this,dword ptr [ECX + this->reusable_static_ob
    //         005461ad     MOV        EAX,dword ptr [ECX + this->world_time]
    //         005461b0     TEST       EAX,EAX
    //         005461b2     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         005461b8     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         005461ba     PUSH       0x0
    //         005461bc     PUSH       ESI
    //         005461bd     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         005461c2     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         005461c4     POP        ESI
    //         005461c5     RET        0x4
    //                               switchD_005461a0::caseD_14                                   XREF[2]:     005461a0(j), 00546280(*)  
    //                              World.cpp:3854 (17)
    //         005461c8     MOV        this,dword ptr [ECX + this->reusable_animated_
    //         005461ce     MOV        EAX,dword ptr [ECX + this->world_time]
    //         005461d1     TEST       EAX,EAX
    //         005461d3     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         005461d9     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         005461db     PUSH       0x0
    //         005461dd     PUSH       ESI
    //         005461de     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         005461e3     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         005461e5     POP        ESI
    //         005461e6     RET        0x4
    //                               switchD_005461a0::caseD_1e                                   XREF[2]:     005461a0(j), 00546288(*)  
    //                              World.cpp:3861 (13)
    //         005461e9     MOV        this,dword ptr [ECX + this->reusable_moving_ob
    //         005461ef     MOV        EAX,dword ptr [ECX + this->world_time]
    //         005461f2     TEST       EAX,EAX
    //         005461f4     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         005461f6     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         005461f8     PUSH       0x0
    //         005461fa     PUSH       ESI
    //         005461fb     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         00546200     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         00546202     POP        ESI
    //         00546203     RET        0x4
    //                               switchD_005461a0::caseD_28                                   XREF[2]:     005461a0(j), 0054628c(*)  
    //                              World.cpp:3868 (13)
    //         00546206     MOV        this,dword ptr [ECX + this->reusable_action_ob
    //         0054620c     MOV        EAX,dword ptr [ECX + this->world_time]
    //         0054620f     TEST       EAX,EAX
    //         00546211     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         00546213     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         00546215     PUSH       0x0
    //         00546217     PUSH       ESI
    //         00546218     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         0054621d     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         0054621f     POP        ESI
    //         00546220     RET        0x4
    //                               switchD_005461a0::caseD_32                                   XREF[2]:     005461a0(j), 00546290(*)  
    //                              World.cpp:3875 (13)
    //         00546223     MOV        this,dword ptr [ECX + this->reusable_combat_ob
    //         00546229     MOV        EAX,dword ptr [ECX + this->world_time]
    //         0054622c     TEST       EAX,EAX
    //         0054622e     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         00546230     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         00546232     PUSH       0x0
    //         00546234     PUSH       ESI
    //         00546235     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         0054623a     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         0054623c     POP        ESI
    //         0054623d     RET        0x4
    //                               switchD_005461a0::caseD_3c                                   XREF[2]:     005461a0(j), 00546294(*)  
    //                              World.cpp:3882 (13)
    //         00546240     MOV        this,dword ptr [ECX + this->reusable_missile_o
    //         00546246     MOV        EAX,dword ptr [ECX + this->world_time]
    //         00546249     TEST       EAX,EAX
    //         0054624b     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         0054624d     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         0054624f     PUSH       0x0
    //         00546251     PUSH       ESI
    //         00546252     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                              World.cpp:3897 (2)
    //         00546257     MOV        EAX,ESI
    //                              World.cpp:3898 (4)
    //         00546259     POP        ESI
    //         0054625a     RET        0x4
    //                               switchD_005461a0::caseD_19                                   XREF[2]:     005461a0(j), 00546284(*)  
    //                              World.cpp:3889 (13)
    //         0054625d     MOV        this,dword ptr [ECX + this->reusable_dopplegan
    //         00546263     MOV        EAX,dword ptr [ECX + this->world_time]
    //         00546266     TEST       EAX,EAX
    //         00546268     JZ         switchD_005461a0::caseD_b
    //                              World.cpp:3891 (2)
    //         0054626a     MOV        ESI,dword ptr [EAX]
    //                              World.cpp:3892 (8)
    //         0054626c     PUSH       0x0
    //         0054626e     PUSH       ESI
    //         0054626f     CALL       RGE_Object_List::remove_node                     void remove_node(RGE_Object_List * this, RGE_
    //                               switchD_005461a0::caseD_c                                    XREF[10]:    00546192(j), 005461a0(j), 
    //                               switchD_005461a0::caseD_d                                                 005461b2(j), 005461d3(j), 
    //                               switchD_005461a0::caseD_e                                                 005461f4(j), 00546211(j), 
    //                               switchD_005461a0::caseD_f                                                 0054622e(j), 0054624b(j), 
    //                               switchD_005461a0::caseD_10                                                00546268(j), 00546298(*)  
    //                               switchD_005461a0::caseD_11
    //                               switchD_005461a0::caseD_12
    //                               switchD_005461a0::caseD_13
    //                               switchD_005461a0::caseD_15
    //                               switchD_005461a0::caseD_16
    //                               switchD_005461a0::caseD_17
    //                               switchD_005461a0::caseD_18
    //                               switchD_005461a0::caseD_1a
    //                               switchD_005461a0::caseD_1b
    //                               switchD_005461a0::caseD_1c
    //                               switchD_005461a0::caseD_1d
    //                               switchD_005461a0::caseD_1f
    //                               switchD_005461a0::caseD_20
    //                               switchD_005461a0::caseD_21
    //                               switchD_005461a0::caseD_22
    //                               switchD_005461a0::caseD_23
    //                               switchD_005461a0::caseD_24
    //                               switchD_005461a0::caseD_25
    //                               switchD_005461a0::caseD_26
    //                               switchD_005461a0::caseD_27
    //                               switchD_005461a0::caseD_29
    //                               switchD_005461a0::caseD_2a
    //                               switchD_005461a0::caseD_2b
    //                               switchD_005461a0::caseD_2c
    //                               switchD_005461a0::caseD_2d
    //                               switchD_005461a0::caseD_2e
    //                               switchD_005461a0::caseD_2f
    //                               switchD_005461a0::caseD_30
    //                               switchD_005461a0::caseD_31
    //                               switchD_005461a0::caseD_33
    //                               switchD_005461a0::caseD_34
    //                               switchD_005461a0::caseD_35
    //                               switchD_005461a0::caseD_36
    //                               switchD_005461a0::caseD_37
    //                               switchD_005461a0::caseD_38
    //                               switchD_005461a0::caseD_39
    //                               switchD_005461a0::caseD_3a
    //                               switchD_005461a0::caseD_3b
    //                               switchD_005461a0::caseD_b
    //                              World.cpp:3897 (2)
    //         00546274     MOV        EAX,ESI
    //                              World.cpp:3898 (89)
    //         00546276     POP        ESI
    //         00546277     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0054627a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054627a
    //         0054627a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_005461a0::switchdataD_0054627c                       XREF[1]:     recycle_object_in_to_game:005461a0
    //         0054627c     addr       switchD_005461a0::caseD_a
    //         00546280     addr       switchD_005461a0::caseD_14
    //         00546284     addr       switchD_005461a0::caseD_19
    //         00546288     addr       switchD_005461a0::caseD_1e
    //         0054628c     addr       switchD_005461a0::caseD_28
    //                               PTR_caseD_32_00546290+2                                      XREF[0,1]:   recycle_object_in_to_game:0054619a
    //         00546290     addr       switchD_005461a0::caseD_32
    //         00546294     addr       switchD_005461a0::caseD_3c
    //         00546298     addr       switchD_005461a0::caseD_b
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_005461a0::switchdataD_0054629c
    //         0054629c     db         0h
    //         0054629d     db         7h
    //         0054629e     db         7h
    //         0054629f     db         7h
    //         005462a0     db         7h
    //         005462a1     db         7h
    //         005462a2     db         7h
    //         005462a3     db         7h
    //         005462a4     db         7h
    //         005462a5     db         7h
    //         005462a6     db         1h
    //         005462a7     db         7h
    //         005462a8     db         7h
    //         005462a9     db         7h
    //         005462aa     db         7h
    //         005462ab     db         2h
    //         005462ac     db         7h
    //         005462ad     db         7h
    //         005462ae     db         7h
    //         005462af     db         7h
    //         005462b0     db         3h
    //         005462b1     db         7h
    //         005462b2     db         7h
    //         005462b3     db         7h
    //         005462b4     db         7h
    //         005462b5     db         7h
    //         005462b6     db         7h
    //         005462b7     db         7h
    //         005462b8     db         7h
    //         005462b9     db         7h
    //         005462ba     db         4h
    //         005462bb     db         7h
    //         005462bc     db         7h
    //         005462bd     db         7h
    //         005462be     db         7h
    //         005462bf     db         7h
    //         005462c0     db         7h
    //         005462c1     db         7h
    //         005462c2     db         7h
    //         005462c3     db         7h
    //         005462c4     db         5h
    //         005462c5     db         7h
    //         005462c6     db         7h
    //         005462c7     db         7h
    //         005462c8     db         7h
    //         005462c9     db         7h
    //         005462ca     db         7h
    //         005462cb     db         7h
    //         005462cc     db         7h
    //         005462cd     db         7h
    //         005462ce     db         6h
    //         005462cf     ??         90h
    return 0;
}

void RGE_Game_World::update_mutual_allies() {
    /* TODO: Stub */
    //                              void __thiscall update_mutual_allies(RGE_Game_World * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005464a0(W), 005464a6(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00546439(W), 005464df(R), 00546506(W)  
    //              int               Stack[-0xc]:4  pNum                      XREF[3]:     00546447(W), 005464d0(R), 005464ed(W)  
    //              int               Stack[-0x10]:4 index
    //                               ?update_mutual_allies@RGE_Game_World@@QAEXXZ                 XREF[5]:     do_command_game:0050a268(c), 
    //                               RGE_Game_World::update_mutual_allies                                      add_attribute_num:005195ad(c), 
    //                                                                                                         scenario_postload:00519d8c(c), 
    //                                                                                                         create_game:00527746(c), 
    //                                                                                                         load_world:005422a9(c)  
    //                              World.cpp:3903 (8)
    //         005462d0     SUB        ESP,0xc
    //         005462d3     PUSH       EBX
    //         005462d4     PUSH       EBP
    //         005462d5     PUSH       ESI
    //         005462d6     MOV        ESI,this
    //                              World.cpp:3908 (22)
    //         005462d8     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         005462de     PUSH       EDI
    //         005462df     MOV        EAX,dword ptr [ESI + 0x4]
    //         005462e2     PUSH       EAX
    //         005462e3     PUSH       s_updating_player_visibilites_@_wt               = "updating player visibilites @ wt=%d\n"
    //         005462e8     PUSH       this
    //         005462e9     CALL       fprintf                                          undefined fprintf()
    //                              World.cpp:3914 (17)
    //         005462ee     XOR        EBP,EBP
    //         005462f0     ADD        ESP,0xc
    //         005462f3     XOR        EDX,EDX
    //         005462f5     CMP        word ptr [ESI + 0x3c],BP
    //         005462f9     JLE        LAB_00546398
    //                               LAB_005462ff                                                 XREF[1]:     00546392(j)  
    //                              World.cpp:3917 (12)
    //         005462ff     MOV        EAX,dword ptr [ESI + 0x40]
    //         00546302     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00546305     MOV        dword ptr [ECX + this+0xd0],EBP
    //                              World.cpp:3918 (12)
    //         0054630b     MOV        EAX,dword ptr [ESI + 0x40]
    //         0054630e     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00546311     MOV        dword ptr [ECX + this+0xd4],EBP
    //                              World.cpp:3919 (17)
    //         00546317     MOV        EAX,dword ptr [ESI + 0x40]
    //         0054631a     MOV        this,dword ptr [EAX + EDX*0x4]
    //         0054631d     MOV        EAX,0xdc
    //         00546322     MOV        dword ptr [ECX + this->reusable_static_objects
    //                               LAB_00546328                                                 XREF[1]:     0054633a(j)  
    //                              World.cpp:3922 (20)
    //         00546328     MOV        this,dword ptr [ESI + 0x40]
    //         0054632b     ADD        EAX,0x4
    //         0054632e     CMP        EAX,0x100
    //         00546333     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00546336     MOV        dword ptr [this->_padding_ + EAX*0x1 + -0x4],EBP
    //         0054633a     JL         LAB_00546328
    //                              World.cpp:3924 (11)
    //         0054633c     MOV        EAX,dword ptr [ESI + 0x40]
    //         0054633f     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //         00546342     ADD        EAX,0xac
    //                              World.cpp:3926 (2)
    //         00546347     XOR        EDI,EDI
    //                               LAB_00546349                                                 XREF[1]:     00546389(j)  
    //                              World.cpp:3928 (4)
    //         00546349     CMP        EDI,EDX
    //         0054634b     JNZ        LAB_00546380
    //                              World.cpp:3931 (30)
    //         0054634d     MOV        EBX,0x1
    //         00546352     MOV        this,EDX
    //         00546354     MOV        dword ptr [EAX],0x1
    //         0054635a     SHL        EBX,this
    //         0054635c     MOV        this,dword ptr [ESI + 0x40]
    //         0054635f     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00546362     MOV        dword ptr [ECX + this+0xd4],EBX
    //         00546368     LEA        this,[EDX + 0x10]
    //                              World.cpp:3932 (19)
    //         0054636b     MOV        EBX,0x1
    //         00546370     SHL        EBX,this
    //         00546372     MOV        this,dword ptr [ESI + 0x40]
    //         00546375     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00546378     MOV        dword ptr [ECX + this+0xd0],EBX
    //                              World.cpp:3934 (2)
    //         0054637e     JMP        LAB_00546382
    //                               LAB_00546380                                                 XREF[1]:     0054634b(j)  
    //                              World.cpp:3936 (2)
    //         00546380     MOV        dword ptr [EAX],EBP
    //                               LAB_00546382                                                 XREF[1]:     0054637e(j)  
    //                              World.cpp:3926 (22)
    //         00546382     INC        EDI
    //         00546383     ADD        EAX,0x4
    //         00546386     CMP        EDI,0x9
    //         00546389     JL         LAB_00546349
    //         0054638b     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         0054638f     INC        EDX
    //         00546390     CMP        EDX,EAX
    //         00546392     JL         LAB_005462ff
    //                               LAB_00546398                                                 XREF[1]:     005462f9(j)  
    //                              World.cpp:3943 (19)
    //         00546398     MOVSX      this,word ptr [ESI + 0x3c]
    //         0054639c     MOV        EBX,0x1
    //         005463a1     CMP        this,EBX
    //         005463a3     MOV        EDI,EBX
    //         005463a5     JLE        LAB_00546431
    //                               LAB_005463ab                                                 XREF[1]:     0054642b(j)  
    //                              World.cpp:3945 (14)
    //         005463ab     MOV        EDX,dword ptr [ESI + 0x40]
    //         005463ae     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         005463b1     CMP        dword ptr [EAX + 0x100],EBX
    //         005463b7     JNZ        LAB_00546424
    //                              World.cpp:3947 (6)
    //         005463b9     CMP        this,EBX
    //         005463bb     MOV        EAX,EBX
    //         005463bd     JLE        LAB_00546424
    //                               LAB_005463bf                                                 XREF[1]:     00546420(j)  
    //                              World.cpp:3949 (4)
    //         005463bf     CMP        EAX,EDI
    //         005463c1     JZ         LAB_00546419
    //                              World.cpp:3951 (34)
    //         005463c3     MOV        EDX,dword ptr [ESI + 0x40]
    //         005463c6     MOV        this,dword ptr [EDX + EDI*0x4]
    //         005463c9     MOV        EBP,dword ptr [ECX + this->world_time_delta_se
    //         005463cf     CMP        byte ptr [EBP + EAX*0x1],0x0
    //         005463d4     JNZ        LAB_00546419
    //         005463d6     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         005463d9     MOV        EDX,dword ptr [EDX + 0x84]
    //         005463df     CMP        byte ptr [EDX + EDI*0x1],0x0
    //         005463e3     JNZ        LAB_00546419
    //                              World.cpp:3953 (7)
    //         005463e5     MOV        dword ptr [ECX + EAX*0x4 + this->campaign_scen
    //                              World.cpp:3954 (20)
    //         005463ec     MOV        this,dword ptr [ESI + 0x40]
    //         005463ef     MOV        EBP,EBX
    //         005463f1     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         005463f4     MOV        this,EAX
    //         005463f6     SHL        EBP,this
    //         005463f8     MOV        this,dword ptr [EDX + 0xd4]
    //         005463fe     OR         this,EBP
    //                              World.cpp:3955 (34)
    //         00546400     MOV        EBP,EBX
    //         00546402     MOV        dword ptr [EDX + 0xd4],this
    //         00546408     MOV        EDX,dword ptr [ESI + 0x40]
    //         0054640b     LEA        this,[EAX + 0x10]
    //         0054640e     MOV        EDX,dword ptr [EDX + EDI*0x4]
    //         00546411     SHL        EBP,this
    //         00546413     OR         dword ptr [EDX + 0xd0],EBP
    //                               LAB_00546419                                                 XREF[3]:     005463c1(j), 005463d4(j), 
    //                                                                                                         005463e3(j)  
    //         00546419     MOVSX      this,word ptr [ESI + 0x3c]
    //         0054641d     INC        EAX
    //         0054641e     CMP        EAX,this
    //         00546420     JL         LAB_005463bf
    //                              World.cpp:3947 (2)
    //         00546422     XOR        EBP,EBP
    //                               LAB_00546424                                                 XREF[2]:     005463b7(j), 005463bd(j)  
    //                              World.cpp:3943 (13)
    //         00546424     MOVSX      this,word ptr [ESI + 0x3c]
    //         00546428     INC        EDI
    //         00546429     CMP        EDI,this
    //         0054642b     JL         LAB_005463ab
    //                               LAB_00546431                                                 XREF[1]:     005463a5(j)  
    //                              World.cpp:3968 (20)
    //         00546431     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         00546435     XOR        this,this
    //         00546437     CMP        EAX,EBP
    //         00546439     MOV        dword ptr [ESP + local_8],this
    //         0054643d     JLE        LAB_00546512
    //         00546443     XOR        EDX,EDX
    //                               LAB_00546445                                                 XREF[1]:     0054650a(j)  
    //                              World.cpp:3970 (17)
    //         00546445     CMP        EAX,EBX
    //         00546447     MOV        dword ptr [ESP + pNum],EBX
    //         0054644b     JLE        LAB_005464fc
    //         00546451     MOV        EBP,0xe0
    //                               LAB_00546456                                                 XREF[1]:     005464f1(j)  
    //                              World.cpp:3974 (21)
    //         00546456     CMP        EBX,this
    //         00546458     JZ         LAB_005464e3
    //         0054645e     MOV        EDI,dword ptr [ESI + 0x40]
    //         00546461     MOV        EDI,dword ptr [EDX + EDI*0x1]
    //         00546464     CMP        dword ptr [EDI + EBP*0x1 + -0x30],0x0
    //         00546469     JNZ        LAB_005464e3
    //                              World.cpp:3980 (9)
    //         0054646b     MOV        EDI,0x1
    //         00546470     CMP        EAX,EDI
    //         00546472     JLE        LAB_005464e3
    //                               LAB_00546474                                                 XREF[1]:     005464dd(j)  
    //                              World.cpp:3984 (16)
    //         00546474     MOV        EAX,dword ptr [ESI + 0x40]
    //         00546477     MOV        this,dword ptr [EDX + EAX*0x1]
    //         0054647a     CMP        dword ptr [ECX + EDI*0x4 + this->campaign_scen
    //         00546482     JNZ        LAB_005464d6
    //                              World.cpp:3989 (20)
    //         00546484     MOV        this,dword ptr [EAX + EDI*0x4]
    //         00546487     CMP        dword ptr [EBP + this->_padding_*0x1 + -0x30],
    //         0054648c     JNZ        LAB_005464d6
    //         0054648e     CMP        dword ptr [EDX + this->_padding_*0x1 + 0xac],0x1
    //         00546496     JNZ        LAB_005464d6
    //                              World.cpp:3993 (28)
    //         00546498     MOV        EAX,dword ptr [EDX + EAX*0x1]
    //         0054649b     MOV        this,0x1
    //         005464a0     MOV        dword ptr [ESP + local_4],this
    //         005464a4     MOV        this,EBX
    //         005464a6     MOV        EBX,dword ptr [ESP + local_4]
    //         005464aa     SHL        EBX,this
    //         005464ac     MOV        this,dword ptr [EAX + 0xd8]
    //         005464b2     OR         this,EBX
    //                              World.cpp:3997 (43)
    //         005464b4     MOV        EBX,0x1
    //         005464b9     MOV        dword ptr [EAX + 0xd8],this
    //         005464bf     MOV        EAX,dword ptr [ESI + 0x40]
    //         005464c2     MOV        this,dword ptr [EDX + EAX*0x1]
    //         005464c5     LEA        EAX,[this->_padding_ + EBP*0x1]
    //         005464c8     MOV        this,EDI
    //         005464ca     SHL        EBX,this
    //         005464cc     MOV        this,dword ptr [EAX]
    //         005464ce     OR         this,EBX
    //         005464d0     MOV        EBX,dword ptr [ESP + pNum]
    //         005464d4     MOV        dword ptr [EAX],this
    //                               LAB_005464d6                                                 XREF[3]:     00546482(j), 0054648c(j), 
    //                                                                                                         00546496(j)  
    //         005464d6     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005464da     INC        EDI
    //         005464db     CMP        EDI,EAX
    //         005464dd     JL         LAB_00546474
    //                              World.cpp:3980 (4)
    //         005464df     MOV        this,dword ptr [ESP + local_8]
    //                               LAB_005464e3                                                 XREF[3]:     00546458(j), 00546469(j), 
    //                                                                                                         00546472(j)  
    //                              World.cpp:3970 (25)
    //         005464e3     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         005464e7     INC        EBX
    //         005464e8     ADD        EBP,0x4
    //         005464eb     CMP        EBX,EAX
    //         005464ed     MOV        dword ptr [ESP + pNum],EBX
    //         005464f1     JL         LAB_00546456
    //         005464f7     MOV        EBX,0x1
    //                               LAB_005464fc                                                 XREF[1]:     0054644b(j)  
    //                              World.cpp:3968 (22)
    //         005464fc     MOVSX      EAX,word ptr [ESI + 0x3c]
    //         00546500     INC        this
    //         00546501     ADD        EDX,0x4
    //         00546504     CMP        this,EAX
    //         00546506     MOV        dword ptr [ESP + local_8],this
    //         0054650a     JL         LAB_00546445
    //         00546510     XOR        EBP,EBP
    //                               LAB_00546512                                                 XREF[1]:     0054643d(j)  
    //                              World.cpp:4007 (13)
    //         00546512     CMP        word ptr [ESI + 0x3c],0x0
    //         00546517     JLE        LAB_005466dc
    //         0054651d     XOR        EBX,EBX
    //                               LAB_0054651f                                                 XREF[1]:     005466d6(j)  
    //                              World.cpp:4009 (18)
    //         0054651f     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         00546525     PUSH       EBP
    //         00546526     PUSH       s_player_%d_                                     = "player %d\n"
    //         0054652b     PUSH       this
    //         0054652c     CALL       fprintf                                          undefined fprintf()
    //                              World.cpp:4011 (47)
    //         00546531     MOV        EDX,dword ptr [ESI + 0x40]
    //         00546534     ADD        ESP,0xc
    //         00546537     MOV        EAX,dword ptr [EBX + EDX*0x1]
    //         0054653a     MOV        this,dword ptr [EAX + 0xd8]
    //         00546540     MOV        EDX,dword ptr [EAX + 0xd4]
    //         00546546     MOV        EAX,dword ptr [EAX + 0xd0]
    //         0054654c     PUSH       this
    //         0054654d     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         00546553     PUSH       EDX
    //         00546554     PUSH       EAX
    //         00546555     PUSH       s___mutualExploredMask_=_%8.8x___m               = "  mutualExploredMask = %8.8x   mutualVisib
    //         0054655a     PUSH       this
    //         0054655b     CALL       fprintf                                          undefined fprintf()
    //                              World.cpp:4013 (41)
    //         00546560     MOV        EDX,dword ptr [ESI + 0x40]
    //         00546563     XOR        this,this
    //         00546565     ADD        ESP,0x14
    //         00546568     MOV        EAX,dword ptr [EBX + EDX*0x1]
    //         0054656b     MOV        this,byte ptr [EAX + 0x104]
    //         00546571     MOV        EDX,dword ptr [EAX + 0x100]
    //         00546577     MOV        EAX,[DVlogf]                                     = 00000000
    //         0054657c     PUSH       this
    //         0054657d     PUSH       EDX
    //         0054657e     PUSH       s___allied_LOS_Enable_=_%d___allie               = "  allied_LOS_Enable = %d   allied_victory 
    //         00546583     PUSH       EAX
    //         00546584     CALL       fprintf                                          undefined fprintf()
    //                              World.cpp:4015 (28)
    //         00546589     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         0054658f     ADD        ESP,0x10
    //         00546592     PUSH       s___unitDiplomacy_=_[                            = "  unitDiplomacy = ["
    //         00546597     PUSH       this
    //         00546598     CALL       fprintf                                          undefined fprintf()
    //         0054659d     ADD        ESP,0x8
    //         005465a0     MOV        EDI,0x88
    //                               LAB_005465a5                                                 XREF[1]:     005465f5(j)  
    //                              World.cpp:4018 (30)
    //         005465a5     MOV        EDX,dword ptr [ESI + 0x40]
    //         005465a8     MOV        EAX,dword ptr [EBX + EDX*0x1]
    //         005465ab     MOV        EDX,dword ptr [DVlogf]                           = 00000000
    //         005465b1     MOV        this,dword ptr [EAX + EDI*0x1]
    //         005465b4     PUSH       this
    //         005465b5     PUSH       s_%d                                             = 6425h
    //         005465ba     PUSH       EDX
    //         005465bb     CALL       fprintf                                          undefined fprintf()
    //         005465c0     ADD        ESP,0xc
    //                              World.cpp:4019 (8)
    //         005465c3     CMP        EDI,0xa8
    //         005465c9     JGE        LAB_005465d8
    //                              World.cpp:4020 (11)
    //         005465cb     MOV        EAX,[DVlogf]                                     = 00000000
    //         005465d0     PUSH       s_,_                                             = ", "
    //         005465d5     PUSH       EAX
    //                              World.cpp:4021 (2)
    //         005465d6     JMP        LAB_005465e4
    //                               LAB_005465d8                                                 XREF[1]:     005465c9(j)  
    //                              World.cpp:4022 (31)
    //         005465d8     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         005465de     PUSH       s_]_                                             = "]\n"
    //         005465e3     PUSH       this
    //                               LAB_005465e4                                                 XREF[1]:     005465d6(j)  
    //         005465e4     CALL       fprintf                                          undefined fprintf()
    //         005465e9     ADD        EDI,0x4
    //         005465ec     ADD        ESP,0x8
    //         005465ef     CMP        EDI,0xac
    //         005465f5     JL         LAB_005465a5
    //                              World.cpp:4025 (20)
    //         005465f7     MOV        EDX,dword ptr [DVlogf]                           = 00000000
    //         005465fd     PUSH       s___mututalAlly_=_[                              = "  mututalAlly = ["
    //         00546602     PUSH       EDX
    //         00546603     CALL       fprintf                                          undefined fprintf()
    //         00546608     ADD        ESP,0x8
    //                              World.cpp:4056 (56)
    //         0054660b     MOV        EDI,0xac
    //                               LAB_00546610                                                 XREF[1]:     00546660(j)  
    //         00546610     MOV        EAX,dword ptr [ESI + 0x40]
    //         00546613     MOV        this,dword ptr [EBX + EAX*0x1]
    //         00546616     MOV        EAX,[DVlogf]                                     = 00000000
    //         0054661b     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
    //         0054661e     PUSH       EDX
    //         0054661f     PUSH       s_%d                                             = 6425h
    //         00546624     PUSH       EAX
    //         00546625     CALL       fprintf                                          undefined fprintf()
    //         0054662a     ADD        ESP,0xc
    //         0054662d     CMP        EDI,0xcc
    //         00546633     JGE        LAB_00546643
    //         00546635     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         0054663b     PUSH       s_,_                                             = ", "
    //         00546640     PUSH       this
    //         00546641     JMP        LAB_0054664f
    //                               LAB_00546643                                                 XREF[1]:     00546633(j)  
    //                              World.cpp:4032 (31)
    //         00546643     MOV        EDX,dword ptr [DVlogf]                           = 00000000
    //         00546649     PUSH       s_]_                                             = "]\n"
    //         0054664e     PUSH       EDX
    //                               LAB_0054664f                                                 XREF[1]:     00546641(j)  
    //         0054664f     CALL       fprintf                                          undefined fprintf()
    //         00546654     ADD        EDI,0x4
    //         00546657     ADD        ESP,0x8
    //         0054665a     CMP        EDI,0xd0
    //         00546660     JL         LAB_00546610
    //                              World.cpp:4035 (19)
    //         00546662     MOV        EAX,[DVlogf]                                     = 00000000
    //         00546667     PUSH       s___RemoveVisibleBits_=_[                        = "  RemoveVisibleBits = ["
    //         0054666c     PUSH       EAX
    //         0054666d     CALL       fprintf                                          undefined fprintf()
    //         00546672     ADD        ESP,0x8
    //                              World.cpp:4056 (57)
    //         00546675     MOV        EDI,0xdc
    //                               LAB_0054667a                                                 XREF[1]:     005466ca(j)  
    //         0054667a     MOV        this,dword ptr [ESI + 0x40]
    //         0054667d     MOV        EDX,dword ptr [EBX + this->_padding_*0x1]
    //         00546680     MOV        this,dword ptr [DVlogf]                          = 00000000
    //         00546686     MOV        EAX,dword ptr [EDX + EDI*0x1]
    //         00546689     PUSH       EAX
    //         0054668a     PUSH       s_%8.8x                                          = "%8.8x"
    //         0054668f     PUSH       this
    //         00546690     CALL       fprintf                                          undefined fprintf()
    //         00546695     ADD        ESP,0xc
    //         00546698     CMP        EDI,0xfc
    //         0054669e     JGE        LAB_005466ae
    //         005466a0     MOV        EDX,dword ptr [DVlogf]                           = 00000000
    //         005466a6     PUSH       s_,_                                             = ", "
    //         005466ab     PUSH       EDX
    //         005466ac     JMP        LAB_005466b9
    //                               LAB_005466ae                                                 XREF[1]:     0054669e(j)  
    //                              World.cpp:4042 (46)
    //         005466ae     MOV        EAX,[DVlogf]                                     = 00000000
    //         005466b3     PUSH       s_]_                                             = "]\n"
    //         005466b8     PUSH       EAX
    //                               LAB_005466b9                                                 XREF[1]:     005466ac(j)  
    //         005466b9     CALL       fprintf                                          undefined fprintf()
    //         005466be     ADD        EDI,0x4
    //         005466c1     ADD        ESP,0x8
    //         005466c4     CMP        EDI,0x100
    //         005466ca     JL         LAB_0054667a
    //         005466cc     MOVSX      this,word ptr [ESI + 0x3c]
    //         005466d0     INC        EBP
    //         005466d1     ADD        EBX,0x4
    //         005466d4     CMP        EBP,this
    //         005466d6     JL         LAB_0054651f
    //                               LAB_005466dc                                                 XREF[1]:     00546517(j)  
    //                              World.cpp:4049 (11)
    //         005466dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005466e2     MOV        EDX,dword ptr [this->_padding_]
    //         005466e4     CALL       dword ptr [EDX + 0x2c]
    //                              World.cpp:4050 (13)
    //         005466e7     TEST       EAX,EAX
    //         005466e9     JZ         LAB_005466f4
    //         005466eb     MOV        EDX,dword ptr [EAX]
    //         005466ed     PUSH       0x2
    //         005466ef     MOV        this,EAX
    //         005466f1     CALL       dword ptr [EDX + 0x20]
    //                               LAB_005466f4                                                 XREF[1]:     005466e9(j)  
    //                              World.cpp:4052 (11)
    //         005466f4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         005466fa     MOV        EAX,dword ptr [this->_padding_]
    //         005466fc     CALL       dword ptr [EAX + 0x30]
    //                              World.cpp:4053 (13)
    //         005466ff     TEST       EAX,EAX
    //         00546701     JZ         LAB_0054670c
    //         00546703     MOV        EDX,dword ptr [EAX]
    //         00546705     PUSH       0x2
    //         00546707     MOV        this,EAX
    //         00546709     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0054670c                                                 XREF[1]:     00546701(j)  
    //                              World.cpp:4056 (8)
    //         0054670c     POP        EDI
    //         0054670d     POP        ESI
    //         0054670e     POP        EBP
    //         0054670f     POP        EBX
    //         00546710     ADD        ESP,0xc
    //         00546713     RET
    //         00546714     ??         90h
    //         00546715     NOP
    //         00546716     NOP
    //         00546717     NOP
    //         00546718     NOP
    //         00546719     NOP
    //         0054671a     NOP
    //         0054671b     NOP
    //         0054671c     NOP
    //         0054671d     NOP
    //         0054671e     NOP
    //         0054671f     NOP
    //                              * unsigned char __cdecl zone_pop(struct Zone_Queue * *,struct Zone_Queue * *,long &,long &)             *
    //                              uchar __cdecl zone_pop(Zone_Queue * * param_1, Zone_Queue * * param_
    //              uchar             AL:1           <RETURN>
    //              Zone_Queue * *    Stack[0x4]:4   param_1                   XREF[1]:     00546721(R)  
    //              Zone_Queue * *    Stack[0x8]:4   param_2                   XREF[1]:     00546754(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[1]:     0054672f(R)  
    //              long *            Stack[0x10]:4  param_4                   XREF[1]:     00546738(R)  
    //                               ?zone_pop@@YAEPAPAUZone_Queue@@0AAJ1@Z                       XREF[1]:     do_zone_map_area:00546e2a(c)  
    //                               zone_pop
    //                              zone_map.cpp:32 (1)
    //         00546720     PUSH       ESI
    //                              zone_map.cpp:35 (10)
    //         00546721     MOV        ESI,dword ptr [ESP + param_1]
    //         00546725     MOV        EAX,dword ptr [ESI]
    //         00546727     TEST       EAX,EAX
    //         00546729     JNZ        LAB_0054672f
    //                              zone_map.cpp:36 (2)
    //         0054672b     XOR        AL,AL
    //                              zone_map.cpp:48 (2)
    //         0054672d     POP        ESI
    //         0054672e     RET
    //                               LAB_0054672f                                                 XREF[1]:     00546729(j)  
    //                              zone_map.cpp:39 (6)
    //         0054672f     MOV        EDX,dword ptr [ESP + param_3]
    //         00546733     MOV        ECX,dword ptr [EAX]
    //                              zone_map.cpp:43 (22)
    //         00546735     PUSH       EAX
    //         00546736     MOV        dword ptr [EDX],ECX
    //         00546738     MOV        EDX,dword ptr [ESP + param_4]
    //         0054673c     MOV        ECX,dword ptr [EAX + 0x4]
    //         0054673f     MOV        dword ptr [EDX],ECX
    //         00546741     MOV        ECX,dword ptr [EAX + 0x8]
    //         00546744     MOV        dword ptr [ESI],ECX
    //         00546746     CALL       free                                             undefined free()
    //                              zone_map.cpp:45 (9)
    //         0054674b     MOV        EAX,dword ptr [ESI]
    //         0054674d     ADD        ESP,0x4
    //         00546750     TEST       EAX,EAX
    //         00546752     JNZ        LAB_0054675e
    //                              zone_map.cpp:46 (10)
    //         00546754     MOV        EDX,dword ptr [ESP + param_2]
    //         00546758     MOV        dword ptr [EDX],0x0
    //                               LAB_0054675e                                                 XREF[1]:     00546752(j)  
    //                              zone_map.cpp:47 (2)
    //         0054675e     MOV        AL,0x1
    //                              zone_map.cpp:48 (2)
    //         00546760     POP        ESI
    //         00546761     RET
    //         00546762     ??         90h
    //         00546763     NOP
    //         00546764     NOP
    //         00546765     NOP
    //         00546766     NOP
    //         00546767     NOP
    //         00546768     NOP
    //         00546769     NOP
    //         0054676a     NOP
    //         0054676b     NOP
    //         0054676c     NOP
    //         0054676d     NOP
    //         0054676e     NOP
    //         0054676f     NOP
    //                              * void __cdecl zone_push(struct Zone_Queue * *,struct Zone_Queue * *,long,long)                         *
    //                              void __cdecl zone_push(Zone_Queue * * param_1, Zone_Queue * * param_
    //              void              <VOID>         <RETURN>
    //              Zone_Queue * *    Stack[0x4]:4   param_1                   XREF[1]:     00546796(R)  
    //              Zone_Queue * *    Stack[0x8]:4   param_2                   XREF[1]:     00546779(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00546789(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0054678f(R)  
    //                               ?zone_push@@YAXPAPAUZone_Queue@@0JJ@Z                        XREF[4]:     do_zone_map_area:00546c63(c), 
    //                               zone_push                                                                 do_zone_map_area:00546cf0(c), 
    //                                                                                                         do_zone_map_area:00546d82(c), 
    //                                                                                                         do_zone_map_area:00546e0e(c)  
    //                              zone_map.cpp:53 (9)
    //         00546770     PUSH       0xc
    //         00546772     PUSH       0x1
    //         00546774     CALL       calloc                                           undefined calloc()
    //                              zone_map.cpp:58 (13)
    //         00546779     MOV        EDX,dword ptr [ESP + param_2]
    //         0054677d     ADD        ESP,0x8
    //         00546780     MOV        ECX,dword ptr [EDX]
    //         00546782     TEST       ECX,ECX
    //         00546784     JZ         LAB_00546789
    //                              zone_map.cpp:59 (3)
    //         00546786     MOV        dword ptr [ECX + 0x8],EAX
    //                               LAB_00546789                                                 XREF[1]:     00546784(j)  
    //                              zone_map.cpp:60 (6)
    //         00546789     MOV        ECX,dword ptr [ESP + param_3]
    //         0054678d     MOV        dword ptr [EAX],ECX
    //                              zone_map.cpp:61 (7)
    //         0054678f     MOV        ECX,dword ptr [ESP + param_4]
    //         00546793     MOV        dword ptr [EAX + 0x4],ECX
    //                              zone_map.cpp:64 (11)
    //         00546796     MOV        ECX,dword ptr [ESP + param_1]
    //         0054679a     MOV        dword ptr [EDX],EAX
    //         0054679c     CMP        dword ptr [ECX],0x0
    //         0054679f     JNZ        LAB_005467a3
    //                              zone_map.cpp:65 (2)
    //         005467a1     MOV        dword ptr [ECX],EAX
    //                               LAB_005467a3                                                 XREF[1]:     0054679f(j)  
    //                              zone_map.cpp:66 (1)
    //         005467a3     RET
    //         005467a4     ??         90h
    //         005467a5     NOP
    //         005467a6     NOP
    //         005467a7     NOP
    //         005467a8     NOP
    //         005467a9     NOP
    //         005467aa     NOP
    //         005467ab     NOP
    //         005467ac     NOP
    //         005467ad     NOP
    //         005467ae     NOP
    //         005467af     NOP
    return;
}

void RGE_Game_World::data_load_players_type(short param_1, short param_2, _iobuf* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Game_World::data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Game_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

uchar RGE_Game_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Game_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

uchar RGE_Game_World::recycle_object_out_of_game(uchar param_1, RGE_Static_Object* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

