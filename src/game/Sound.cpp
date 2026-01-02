#include "../common.h"
#include "Sound.h"

RGE_Sound::RGE_Sound(_iobuf* param_1, short param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sound(RGE_Sound * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ??0RGE_Sound@@QAE@XZ
//                               RGE_Sound::RGE_Sound
//                              Sound.cpp:94 (2)
//         004bc070     MOV        EAX,this
//                              Sound.cpp:95 (5)
//         004bc072     XOR        this,this
//         004bc074     MOV        word ptr [EAX],this
//                              Sound.cpp:96 (4)
//         004bc077     MOV        word ptr [EAX + 0x2],this
//                              Sound.cpp:97 (3)
//         004bc07b     MOV        dword ptr [EAX + 0x4],this
//                              Sound.cpp:98 (1)
//         004bc07e     RET
//         004bc07f     ??         90h
}

RGE_Sound::RGE_Sound(int param_1, TSound_Driver* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sound(RGE_Sound * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ??0RGE_Sound@@QAE@XZ
//                               RGE_Sound::RGE_Sound
//                              Sound.cpp:94 (2)
//         004bc070     MOV        EAX,this
//                              Sound.cpp:95 (5)
//         004bc072     XOR        this,this
//         004bc074     MOV        word ptr [EAX],this
//                              Sound.cpp:96 (4)
//         004bc077     MOV        word ptr [EAX + 0x2],this
//                              Sound.cpp:97 (3)
//         004bc07b     MOV        dword ptr [EAX + 0x4],this
//                              Sound.cpp:98 (1)
//         004bc07e     RET
//         004bc07f     ??         90h
}

RGE_Sound::RGE_Sound() {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sound(RGE_Sound * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ??0RGE_Sound@@QAE@XZ
//                               RGE_Sound::RGE_Sound
//                              Sound.cpp:94 (2)
//         004bc070     MOV        EAX,this
//                              Sound.cpp:95 (5)
//         004bc072     XOR        this,this
//         004bc074     MOV        word ptr [EAX],this
//                              Sound.cpp:96 (4)
//         004bc077     MOV        word ptr [EAX + 0x2],this
//                              Sound.cpp:97 (3)
//         004bc07b     MOV        dword ptr [EAX + 0x4],this
//                              Sound.cpp:98 (1)
//         004bc07e     RET
//         004bc07f     ??         90h
}

RGE_Sound::~RGE_Sound() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Sound(RGE_Sound * this)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ??1RGE_Sound@@QAE@XZ                                         XREF[1]:     ~RGE_Game_World:00540bcc(c)
//                               RGE_Sound::~RGE_Sound
//                              Sound.cpp:103 (3)
//         004bc080     PUSH       ESI
//         004bc081     MOV        ESI,this
//                              Sound.cpp:108 (13)
//         004bc083     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc086     MOV        word ptr [ESI],0x0
//         004bc08b     TEST       EAX,EAX
//         004bc08d     JZ         LAB_004bc0ed
//         004bc08f     PUSH       EBX
//                              Sound.cpp:110 (10)
//         004bc090     XOR        EBX,EBX
//         004bc092     CMP        word ptr [ESI + 0x2],BX
//         004bc096     JLE        LAB_004bc0d7
//         004bc098     PUSH       EDI
//         004bc099     PUSH       EBP
//                              Sound.cpp:123 (85)
//         004bc09a     XOR        EDI,EDI
//                               LAB_004bc09c                                                 XREF[1]:     004bc0d3(j)
//         004bc09c     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc09f     MOV        byte ptr [EAX + EDI*0x1],0x0
//         004bc0a3     MOV        this,dword ptr [ESI + 0x4]
//         004bc0a6     MOV        EBP,dword ptr [this->play_at_update_count + ED
//         004bc0aa     TEST       EBP,EBP
//         004bc0ac     JZ         LAB_004bc0c9
//         004bc0ae     MOV        this,EBP
//         004bc0b0     CALL       TDigital::~TDigital                              void ~TDigital(TDigital * this)
//         004bc0b5     PUSH       EBP
//         004bc0b6     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004bc0bb     MOV        EDX,dword ptr [ESI + 0x4]
//         004bc0be     ADD        ESP,0x4
//         004bc0c1     MOV        dword ptr [EDX + EDI*0x1 + 0x18],0x0
//                               LAB_004bc0c9                                                 XREF[1]:     004bc0ac(j)
//         004bc0c9     MOVSX      EAX,word ptr [ESI + 0x2]
//         004bc0cd     INC        EBX
//         004bc0ce     ADD        EDI,0x24
//         004bc0d1     CMP        EBX,EAX
//         004bc0d3     JL         LAB_004bc09c
//         004bc0d5     POP        EBP
//         004bc0d6     POP        EDI
//                               LAB_004bc0d7                                                 XREF[1]:     004bc096(j)
//         004bc0d7     MOV        this,dword ptr [ESI + 0x4]
//         004bc0da     PUSH       this
//         004bc0db     CALL       free                                             undefined free()
//         004bc0e0     ADD        ESP,0x4
//         004bc0e3     XOR        EAX,EAX
//         004bc0e5     MOV        dword ptr [ESI + 0x4],EAX
//         004bc0e8     MOV        word ptr [ESI + 0x2],AX
//         004bc0ec     POP        EBX
//                               LAB_004bc0ed                                                 XREF[1]:     004bc08d(j)
//         004bc0ed     POP        ESI
//         004bc0ee     RET
//         004bc0ef     ??         90h
}

void RGE_Sound::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Sound * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004bc0f1(R)
//                               ?save@RGE_Sound@@QAEXH@Z                                     XREF[1]:     base_save:00543922(c)
//                               RGE_Sound::save
//                              Sound.cpp:129 (1)
//         004bc0f0     PUSH       EBX
//                              Sound.cpp:132 (24)
//         004bc0f1     MOV        EBX,dword ptr [ESP + param_1]
//         004bc0f5     PUSH       EBP
//         004bc0f6     PUSH       ESI
//         004bc0f7     PUSH       EDI
//         004bc0f8     MOV        EDI,this
//         004bc0fa     PUSH       0x2
//         004bc0fc     LEA        EAX,[EDI + 0xc]
//         004bc0ff     PUSH       EAX
//         004bc100     PUSH       EBX
//         004bc101     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bc106     ADD        ESP,0xc
//                              Sound.cpp:133 (12)
//         004bc109     PUSH       0x2
//         004bc10b     PUSH       EDI
//         004bc10c     PUSH       EBX
//         004bc10d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bc112     ADD        ESP,0xc
//                              Sound.cpp:134 (15)
//         004bc115     LEA        ESI,[EDI + 0x2]
//         004bc118     PUSH       0x2
//         004bc11a     PUSH       ESI
//         004bc11b     PUSH       EBX
//         004bc11c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bc121     ADD        ESP,0xc
//                              Sound.cpp:135 (12)
//         004bc124     LEA        this,[EDI + 0x8]
//         004bc127     PUSH       0x4
//         004bc129     PUSH       this
//         004bc12a     PUSH       EBX
//         004bc12b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              Sound.cpp:137 (11)
//         004bc130     MOV        SI,word ptr [ESI]
//         004bc133     ADD        ESP,0xc
//         004bc136     TEST       SI,SI
//         004bc139     JLE        LAB_004bc187
//                              Sound.cpp:139 (7)
//         004bc13b     XOR        EBP,EBP
//         004bc13d     TEST       SI,SI
//         004bc140     JLE        LAB_004bc187
//                              Sound.cpp:146 (2)
//         004bc142     XOR        ESI,ESI
//                               LAB_004bc144                                                 XREF[1]:     004bc185(j)
//                              Sound.cpp:141 (14)
//         004bc144     MOV        EDX,dword ptr [EDI + 0x4]
//         004bc147     PUSH       0xd
//         004bc149     ADD        EDX,ESI
//         004bc14b     PUSH       EDX
//         004bc14c     PUSH       EBX
//         004bc14d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              Sound.cpp:142 (19)
//         004bc152     MOV        EAX,dword ptr [EDI + 0x4]
//         004bc155     ADD        ESP,0xc
//         004bc158     LEA        this,[EAX + ESI*0x1 + 0x10]
//         004bc15c     PUSH       0x4
//         004bc15e     PUSH       this
//         004bc15f     PUSH       EBX
//         004bc160     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              Sound.cpp:143 (34)
//         004bc165     MOV        EDX,dword ptr [EDI + 0x4]
//         004bc168     ADD        ESP,0xc
//         004bc16b     LEA        EAX,[EDX + ESI*0x1 + 0x14]
//         004bc16f     PUSH       0x2
//         004bc171     PUSH       EAX
//         004bc172     PUSH       EBX
//         004bc173     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bc178     MOVSX      this,word ptr [EDI + 0x2]
//         004bc17c     ADD        ESP,0xc
//         004bc17f     INC        EBP
//         004bc180     ADD        ESI,0x24
//         004bc183     CMP        EBP,this
//         004bc185     JL         LAB_004bc144
//                               LAB_004bc187                                                 XREF[2]:     004bc139(j), 004bc140(j)
//                              Sound.cpp:146 (7)
//         004bc187     POP        EDI
//         004bc188     POP        ESI
//         004bc189     POP        EBP
//         004bc18a     POP        EBX
//         004bc18b     RET        0x4
//         004bc18e     ??         90h
//         004bc18f     NOP
    return;
}

void RGE_Sound::restart_sound(TSound_Driver* param_1) {
    /* TODO: Stub */
//                              void __thiscall restart_sound(RGE_Sound * this, TSound_Driver * para
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//              TSound_Driver *   Stack[0x4]:4   param_1                   XREF[1]:     004bc1d5(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004bc1ed(W), 004bc20e(W), 004bc221(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004bc254(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004bc1e7(W)
//                               ?restart_sound@RGE_Sound@@QAEXPAVTSound_Driver@@@Z           XREF[2]:     stop_sound_system:0041f868(c),
//                               RGE_Sound::restart_sound                                                  restart_sound_system:0041f968(c)
//                              Sound.cpp:151 (26)
//         004bc190     PUSH       -0x1
//         004bc192     PUSH       FUN_0055f8bb
//         004bc197     MOV        EAX,FS:[0x0]
//         004bc19d     PUSH       EAX
//         004bc19e     MOV        dword ptr FS:[0x0],ESP
//         004bc1a5     PUSH       this
//         004bc1a6     PUSH       EBX
//         004bc1a7     PUSH       ESI
//         004bc1a8     MOV        ESI,this
//                              Sound.cpp:154 (16)
//         004bc1aa     XOR        EBX,EBX
//         004bc1ac     CMP        word ptr [ESI + 0x2],BX
//         004bc1b0     JLE        LAB_004bc254
//         004bc1b6     PUSH       EDI
//         004bc1b7     PUSH       EBP
//         004bc1b8     XOR        EDI,EDI
//                               LAB_004bc1ba                                                 XREF[1]:     004bc24c(j)
//                              Sound.cpp:156 (11)
//         004bc1ba     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc1bd     MOV        EBP,dword ptr [EAX + EDI*0x1 + 0x18]
//         004bc1c1     TEST       EBP,EBP
//         004bc1c3     JZ         LAB_004bc1d5
//                              Sound.cpp:157 (16)
//         004bc1c5     MOV        this,EBP
//         004bc1c7     CALL       TDigital::~TDigital                              void ~TDigital(TDigital * this)
//         004bc1cc     PUSH       EBP
//         004bc1cd     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004bc1d2     ADD        ESP,0x4
//                               LAB_004bc1d5                                                 XREF[1]:     004bc1c3(j)
//                              Sound.cpp:159 (8)
//         004bc1d5     MOV        EBP,dword ptr [ESP + param_1]
//         004bc1d9     TEST       EBP,EBP
//         004bc1db     JZ         LAB_004bc22f
//                              Sound.cpp:160 (61)
//         004bc1dd     PUSH       0x3c
//         004bc1df     CALL       operator_new                                     void * operator_new(uint param_1)
//         004bc1e4     ADD        ESP,0x4
//         004bc1e7     MOV        dword ptr [ESP + local_10],EAX
//         004bc1eb     TEST       EAX,EAX
//         004bc1ed     MOV        dword ptr [ESP + local_4],0x0
//         004bc1f5     JZ         LAB_004bc21c
//         004bc1f7     MOV        this,dword ptr [ESI + 0x4]
//         004bc1fa     LEA        EDX,[this->play_at_update_count + EDI*0x1]
//         004bc1fd     MOV        this,dword ptr [ECX + EDI*0x1 + this+0x10]
//         004bc201     PUSH       this
//         004bc202     PUSH       EDX
//         004bc203     PUSH       EBP
//         004bc204     MOV        this,EAX
//         004bc206     CALL       TDigital::TDigital                               undefined TDigital(TDigital * this, TSound_Dr
//         004bc20b     MOV        EDX,dword ptr [ESI + 0x4]
//         004bc20e     MOV        dword ptr [ESP + local_4],0xffffffff
//         004bc216     MOV        dword ptr [EDX + EDI*0x1 + 0x18],EAX
//                              Sound.cpp:161 (2)
//         004bc21a     JMP        LAB_004bc23a
//                               LAB_004bc21c                                                 XREF[1]:     004bc1f5(j)
//                              Sound.cpp:160 (17)
//         004bc21c     MOV        EDX,dword ptr [ESI + 0x4]
//         004bc21f     XOR        EAX,EAX
//         004bc221     MOV        dword ptr [ESP + local_4],0xffffffff
//         004bc229     MOV        dword ptr [EDX + EDI*0x1 + 0x18],EAX
//                              Sound.cpp:161 (2)
//         004bc22d     JMP        LAB_004bc23a
//                               LAB_004bc22f                                                 XREF[1]:     004bc1db(j)
//                              Sound.cpp:162 (11)
//         004bc22f     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc232     MOV        dword ptr [EAX + EDI*0x1 + 0x18],0x0
//                               LAB_004bc23a                                                 XREF[2]:     004bc21a(j), 004bc22d(j)
//                              Sound.cpp:163 (26)
//         004bc23a     MOV        this,dword ptr [ESI + 0x4]
//         004bc23d     INC        EBX
//         004bc23e     MOV        byte ptr [this->play_at_update_count + EDI*0x1
//         004bc243     ADD        EDI,0x24
//         004bc246     MOVSX      EDX,word ptr [ESI + 0x2]
//         004bc24a     CMP        EBX,EDX
//         004bc24c     JL         LAB_004bc1ba
//         004bc252     POP        EBP
//         004bc253     POP        EDI
//                               LAB_004bc254                                                 XREF[1]:     004bc1b0(j)
//                              Sound.cpp:165 (19)
//         004bc254     MOV        this,dword ptr [ESP + local_c]
//         004bc258     POP        ESI
//         004bc259     MOV        dword ptr FS:[0x0],this
//         004bc260     POP        EBX
//         004bc261     ADD        ESP,0x10
//         004bc264     RET        0x4
//         004bc267     ??         90h
//         004bc268     NOP
//         004bc269     NOP
//         004bc26a     NOP
//         004bc26b     NOP
//         004bc26c     NOP
//         004bc26d     NOP
//         004bc26e     NOP
//         004bc26f     NOP
    return;
}

void RGE_Sound::update(ulong param_1) {
    /* TODO: Stub */
//                              void __thiscall update(RGE_Sound * this, ulong param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004bc28d(R)
//                               ?update@RGE_Sound@@QAEXK@Z                                   XREF[1]:     update_sounds:00542e71(c)
//                               RGE_Sound::update
//                              Sound.cpp:170 (4)
//         004bc270     PUSH       EBP
//         004bc271     PUSH       ESI
//         004bc272     MOV        ESI,this
//                              Sound.cpp:174 (16)
//         004bc274     MOV        AX,word ptr [ESI + 0x2]
//         004bc278     TEST       AX,AX
//         004bc27b     JLE        LAB_004bc2ca
//         004bc27d     MOV        this,dword ptr [ESI + 0x8]
//         004bc280     TEST       this,this
//         004bc282     JBE        LAB_004bc2ca
//                              Sound.cpp:175 (9)
//         004bc284     XOR        EBP,EBP
//         004bc286     TEST       AX,AX
//         004bc289     JLE        LAB_004bc2ca
//         004bc28b     PUSH       EDI
//         004bc28c     PUSH       EBX
//                              Sound.cpp:185 (66)
//         004bc28d     MOV        EBX,dword ptr [ESP + param_1]
//         004bc291     XOR        EDI,EDI
//                               LAB_004bc293                                                 XREF[1]:     004bc2c6(j)
//         004bc293     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc296     ADD        EAX,EDI
//         004bc298     CMP        byte ptr [EAX + 0x1c],0x1
//         004bc29c     JNZ        LAB_004bc2bc
//         004bc29e     MOV        EDX,dword ptr [EAX + 0x20]
//         004bc2a1     MOV        this,EBX
//         004bc2a3     SUB        this,EDX
//         004bc2a5     MOV        EDX,dword ptr [ESI + 0x8]
//         004bc2a8     CMP        this,EDX
//         004bc2aa     JBE        LAB_004bc2bc
//         004bc2ac     MOV        this,dword ptr [EAX + 0x18]
//         004bc2af     CALL       TDigital::unload                                 void unload(TDigital * this)
//         004bc2b4     MOV        EDX,dword ptr [ESI + 0x4]
//         004bc2b7     MOV        byte ptr [EDX + EDI*0x1 + 0x1c],0x2
//                               LAB_004bc2bc                                                 XREF[2]:     004bc29c(j), 004bc2aa(j)
//         004bc2bc     MOVSX      EAX,word ptr [ESI + 0x2]
//         004bc2c0     INC        EBP
//         004bc2c1     ADD        EDI,0x24
//         004bc2c4     CMP        EBP,EAX
//         004bc2c6     JL         LAB_004bc293
//         004bc2c8     POP        EBX
//         004bc2c9     POP        EDI
//                               LAB_004bc2ca                                                 XREF[3]:     004bc27b(j), 004bc282(j),
//                                                                                                         004bc289(j)
//         004bc2ca     POP        ESI
//         004bc2cb     POP        EBP
//         004bc2cc     RET        0x4
//         004bc2cf     ??         90h
    return;
}

void RGE_Sound::set_cache_time(ulong param_1) {
    /* TODO: Stub */
//                              void __thiscall set_cache_time(RGE_Sound * this, ulong param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004bc2d0(R)
//                               ?set_cache_time@RGE_Sound@@QAEXK@Z
//                               RGE_Sound::set_cache_time
//                              Sound.cpp:190 (7)
//         004bc2d0     MOV        EAX,dword ptr [ESP + param_1]
//         004bc2d4     MOV        dword ptr [ECX + this->cache_time],EAX
//                              Sound.cpp:192 (3)
//         004bc2d7     RET        0x4
//         004bc2da     ??         90h
//         004bc2db     NOP
//         004bc2dc     NOP
//         004bc2dd     NOP
//         004bc2de     NOP
//         004bc2df     NOP
    return;
}

void RGE_Sound::play_at_update() {
    /* TODO: Stub */
//                              void __thiscall play_at_update(RGE_Sound * this)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ?play_at_update@RGE_Sound@@QAEXXZ
//                               RGE_Sound::play_at_update
//                              Sound.cpp:197 (3)
//         004bc2e0     INC        word ptr [this->play_at_update_count]
//                              Sound.cpp:199 (1)
//         004bc2e3     RET
//         004bc2e4     ??         90h
//         004bc2e5     NOP
//         004bc2e6     NOP
//         004bc2e7     NOP
//         004bc2e8     NOP
//         004bc2e9     NOP
//         004bc2ea     NOP
//         004bc2eb     NOP
//         004bc2ec     NOP
//         004bc2ed     NOP
//         004bc2ee     NOP
//         004bc2ef     NOP
    return;
}

void RGE_Sound::update_play() {
    /* TODO: Stub */
//                              void __thiscall update_play(RGE_Sound * this)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ?update_play@RGE_Sound@@QAEXXZ
//                               RGE_Sound::update_play
//                              Sound.cpp:204 (3)
//         004bc2f0     PUSH       ESI
//         004bc2f1     MOV        ESI,this
//                              Sound.cpp:205 (6)
//         004bc2f3     CMP        word ptr [ESI],0x0
//         004bc2f7     JLE        LAB_004bc305
//                              Sound.cpp:207 (7)
//         004bc2f9     PUSH       0x1
//         004bc2fb     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                              Sound.cpp:208 (5)
//         004bc300     MOV        word ptr [ESI],0x0
//                               LAB_004bc305                                                 XREF[1]:     004bc2f7(j)
//                              Sound.cpp:210 (2)
//         004bc305     POP        ESI
//         004bc306     RET
//         004bc307     ??         90h
//         004bc308     NOP
//         004bc309     NOP
//         004bc30a     NOP
//         004bc30b     NOP
//         004bc30c     NOP
//         004bc30d     NOP
//         004bc30e     NOP
//         004bc30f     NOP
    return;
}

void RGE_Sound::play(int param_1) {
    /* TODO: Stub */
//                              void __thiscall play(RGE_Sound * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004bc3db(R)
//              char[256]         Stack[-0x104   s                         XREF[0,3]:   004bc3a7(*), 004bc3c2(*), 004bc3ce(*)
//                               ?play@RGE_Sound@@QAEXH@Z                                     XREF[22]:    set_state:0040333b(c),
//                               RGE_Sound::play                                                           update:00403a92(c),
//                                                                                                         play_command_sound:0044f98c(c),
//                                                                                                         play_move_sound:0044f9ac(c),
//                                                                                                         select_one_object:00470e11(c),
//                                                                                                         update_play:004bc2fb(c),
//                                                                                                         play_sound:004c002d(c),
//                                                                                                         play_sound:004c007b(c),
//                                                                                                         play_sound:004c00c9(c),
//                                                                                                         recycle_in_to_game:004c1564(c),
//                                                                                                         setup:004c1814(c),
//                                                                                                         update:004c3e3d(c),
//                                                                                                         set_object_state:004c87af(c),
//                                                                                                         set_state:004cd56b(c),
//                                                                                                         set_state:004cdfe0(c),
//                                                                                                         set_state:004cecae(c),
//                                                                                                         set_state:004cf636(c),
//                                                                                                         update:004cfd52(c),
//                                                                                                         set_state:004d1b11(c),
//                                                                                                         set_state:004d2a9a(c), [more]
//                              Sound.cpp:215 (12)
//         004bc310     SUB        ESP,0x100
//         004bc316     PUSH       EBX
//         004bc317     PUSH       EBP
//         004bc318     PUSH       ESI
//         004bc319     PUSH       EDI
//         004bc31a     MOV        EDI,this
//                              Sound.cpp:219 (11)
//         004bc31c     CMP        word ptr [EDI + 0x2],0x0
//         004bc321     JLE        LAB_004bc45d
//                              Sound.cpp:221 (21)
//         004bc327     PUSH       0xdd
//         004bc32c     PUSH       s_C:\msdev\work\age1_x1\Sound.cpp                = "C:\\msdev\\work\\age1_x1\\Sound.cpp"
//         004bc331     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004bc336     LEA        EAX,[EAX + EAX*0x4]
//         004bc339     ADD        ESP,0x8
//                              Sound.cpp:223 (39)
//         004bc33c     MOVSX      ESI,word ptr [EDI + 0x2]
//         004bc340     LEA        this,[EAX + EAX*0x4]
//         004bc343     MOV        EAX,0x80010003
//         004bc348     SHL        this,0x2
//         004bc34b     IMUL       this
//         004bc34d     ADD        EDX,this
//         004bc34f     SAR        EDX,0xe
//         004bc352     MOV        EAX,EDX
//         004bc354     SHR        EAX,0x1f
//         004bc357     ADD        EDX,EAX
//         004bc359     XOR        EAX,EAX
//         004bc35b     TEST       ESI,ESI
//         004bc35d     JLE        LAB_004bc45d
//                              Sound.cpp:273 (36)
//         004bc363     MOV        EBX,dword ptr [EDI + 0x4]
//         004bc366     LEA        this,[EBX + 0x14]
//                               LAB_004bc369                                                 XREF[1]:     004bc378(j)
//         004bc369     MOVSX      EBP,word ptr [this->play_at_update_count]
//         004bc36c     SUB        EDX,EBP
//         004bc36e     TEST       EDX,EDX
//         004bc370     JLE        LAB_004bc387
//         004bc372     INC        EAX
//         004bc373     ADD        this,0x24
//         004bc376     CMP        EAX,ESI
//         004bc378     JL         LAB_004bc369
//         004bc37a     POP        EDI
//         004bc37b     POP        ESI
//         004bc37c     POP        EBP
//         004bc37d     POP        EBX
//         004bc37e     ADD        ESP,0x100
//         004bc384     RET        0x4
//                               LAB_004bc387                                                 XREF[1]:     004bc370(j)
//                              Sound.cpp:228 (21)
//         004bc387     LEA        ESI,[EAX + EAX*0x8]
//         004bc38a     SHL        ESI,0x2
//         004bc38d     MOV        this,dword ptr [EBX + ESI*0x1 + 0x18]
//         004bc391     LEA        EAX,[EBX + ESI*0x1]
//         004bc394     TEST       this,this
//         004bc396     JZ         LAB_004bc45d
//                              Sound.cpp:232 (10)
//         004bc39c     MOV        this,dword ptr [do_draw_log]
//         004bc3a2     TEST       this,this
//         004bc3a4     JZ         LAB_004bc3db
//                              Sound.cpp:235 (16)
//         004bc3a6     PUSH       EAX
//         004bc3a7     LEA        this=>s[4],[ESP + 0x14]
//         004bc3ab     PUSH       s_{%s                                            = "{%s"
//         004bc3b0     PUSH       this
//         004bc3b1     CALL       sprintf                                          undefined sprintf()
//                              Sound.cpp:236 (12)
//         004bc3b6     MOV        EAX,[safe_draw_log]
//         004bc3bb     ADD        ESP,0xc
//         004bc3be     TEST       EAX,EAX
//         004bc3c0     JZ         LAB_004bc3ce
//                              Sound.cpp:237 (10)
//         004bc3c2     LEA        EDX=>s[4],[ESP + 0x10]
//         004bc3c6     PUSH       EDX
//         004bc3c7     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//                              Sound.cpp:238 (2)
//         004bc3cc     JMP        LAB_004bc3d8
//                               LAB_004bc3ce                                                 XREF[1]:     004bc3c0(j)
//                              Sound.cpp:239 (13)
//         004bc3ce     LEA        EAX=>s[4],[ESP + 0x10]
//         004bc3d2     PUSH       EAX
//         004bc3d3     CALL       write_draw_log                                   void write_draw_log(char * param_1)
//                               LAB_004bc3d8                                                 XREF[1]:     004bc3cc(j)
//         004bc3d8     ADD        ESP,0x4
//                               LAB_004bc3db                                                 XREF[1]:     004bc3a4(j)
//                              Sound.cpp:243 (11)
//         004bc3db     MOV        EAX,dword ptr [ESP + param_1]
//         004bc3e2     TEST       EAX,EAX
//         004bc3e4     JZ         LAB_004bc3f4
//                              Sound.cpp:244 (12)
//         004bc3e6     MOV        this,dword ptr [EDI + 0x4]
//         004bc3e9     MOV        this,dword ptr [this->play_at_update_count + E
//         004bc3ed     CALL       TDigital::add_to_play_list                       int add_to_play_list(TDigital * this)
//                              Sound.cpp:245 (2)
//         004bc3f2     JMP        LAB_004bc400
//                               LAB_004bc3f4                                                 XREF[1]:     004bc3e4(j)
//                              Sound.cpp:246 (12)
//         004bc3f4     MOV        EDX,dword ptr [EDI + 0x4]
//         004bc3f7     MOV        this,dword ptr [EDX + ESI*0x1 + 0x18]
//         004bc3fb     CALL       TDigital::play                                   int play(TDigital * this)
//                               LAB_004bc400                                                 XREF[1]:     004bc3f2(j)
//                              Sound.cpp:249 (9)
//         004bc400     MOV        EAX,[do_draw_log]
//         004bc405     TEST       EAX,EAX
//         004bc407     JZ         LAB_004bc426
//                              Sound.cpp:251 (5)
//         004bc409     MOV        EAX,[safe_draw_log]
//                              Sound.cpp:252 (14)
//         004bc40e     PUSH       s_}                                              = "}"
//         004bc413     TEST       EAX,EAX
//         004bc415     JZ         LAB_004bc41e
//         004bc417     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//                              Sound.cpp:253 (2)
//         004bc41c     JMP        LAB_004bc423
//                               LAB_004bc41e                                                 XREF[1]:     004bc415(j)
//                              Sound.cpp:254 (8)
//         004bc41e     CALL       write_draw_log                                   void write_draw_log(char * param_1)
//                               LAB_004bc423                                                 XREF[1]:     004bc41c(j)
//         004bc423     ADD        ESP,0x4
//                               LAB_004bc426                                                 XREF[1]:     004bc407(j)
//                              Sound.cpp:258 (3)
//         004bc426     MOV        EAX,dword ptr [EDI + 0x4]
//                              Sound.cpp:264 (46)
//         004bc429     PUSH       0x108
//         004bc42e     PUSH       s_C:\msdev\work\age1_x1\Sound.cpp                = "C:\\msdev\\work\\age1_x1\\Sound.cpp"
//         004bc433     MOV        byte ptr [EAX + ESI*0x1 + 0x1c],0x1
//         004bc438     MOV        EBX,dword ptr [debug_timeGetTime_on]
//         004bc43e     MOV        dword ptr [debug_timeGetTime_on],0x0
//         004bc448     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004bc44d     MOV        this,dword ptr [EDI + 0x4]
//         004bc450     ADD        ESP,0x8
//         004bc453     MOV        dword ptr [this->play_at_update_count + ESI*0x
//                              Sound.cpp:266 (6)
//         004bc457     MOV        dword ptr [debug_timeGetTime_on],EBX
//                               LAB_004bc45d                                                 XREF[3]:     004bc321(j), 004bc35d(j),
//                                                                                                         004bc396(j)
//                              Sound.cpp:273 (13)
//         004bc45d     POP        EDI
//         004bc45e     POP        ESI
//         004bc45f     POP        EBP
//         004bc460     POP        EBX
//         004bc461     ADD        ESP,0x100
//         004bc467     RET        0x4
//         004bc46a     ??         90h
//         004bc46b     NOP
//         004bc46c     NOP
//         004bc46d     NOP
//         004bc46e     NOP
//         004bc46f     NOP
    return;
}

char* RGE_Sound::get_file_name() {
    /* TODO: Stub */
//                              char * __thiscall get_file_name(RGE_Sound * this)
//              char *            EAX:4          <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ?get_file_name@RGE_Sound@@QAEPADXZ                           XREF[1]:     handle_terrain_sound:0049ba54(c)
//                               RGE_Sound::get_file_name
//                              Sound.cpp:278 (5)
//         004bc470     PUSH       EBX
//         004bc471     PUSH       ESI
//         004bc472     PUSH       EDI
//         004bc473     MOV        EDI,this
//                              Sound.cpp:282 (7)
//         004bc475     CMP        word ptr [EDI + 0x2],0x0
//         004bc47a     JLE        LAB_004bc4e3
//                              Sound.cpp:284 (21)
//         004bc47c     PUSH       0x11c
//         004bc481     PUSH       s_C:\msdev\work\age1_x1\Sound.cpp                = "C:\\msdev\\work\\age1_x1\\Sound.cpp"
//         004bc486     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004bc48b     LEA        EAX,[EAX + EAX*0x4]
//         004bc48e     ADD        ESP,0x8
//                              Sound.cpp:286 (35)
//         004bc491     MOVSX      ESI,word ptr [EDI + 0x2]
//         004bc495     LEA        this,[EAX + EAX*0x4]
//         004bc498     MOV        EAX,0x80010003
//         004bc49d     SHL        this,0x2
//         004bc4a0     IMUL       this
//         004bc4a2     ADD        EDX,this
//         004bc4a4     SAR        EDX,0xe
//         004bc4a7     MOV        EAX,EDX
//         004bc4a9     SHR        EAX,0x1f
//         004bc4ac     ADD        EDX,EAX
//         004bc4ae     XOR        EAX,EAX
//         004bc4b0     TEST       ESI,ESI
//         004bc4b2     JLE        LAB_004bc4e3
//                              Sound.cpp:299 (23)
//         004bc4b4     MOV        EDI,dword ptr [EDI + 0x4]
//         004bc4b7     LEA        this,[EDI + 0x14]
//                               LAB_004bc4ba                                                 XREF[1]:     004bc4c9(j)
//         004bc4ba     MOVSX      EBX,word ptr [this->play_at_update_count]
//         004bc4bd     SUB        EDX,EBX
//         004bc4bf     TEST       EDX,EDX
//         004bc4c1     JLE        LAB_004bc4d1
//         004bc4c3     INC        EAX
//         004bc4c4     ADD        this,0x24
//         004bc4c7     CMP        EAX,ESI
//         004bc4c9     JL         LAB_004bc4ba
//                              Sound.cpp:298 (2)
//         004bc4cb     XOR        EAX,EAX
//                              Sound.cpp:299 (4)
//         004bc4cd     POP        EDI
//         004bc4ce     POP        ESI
//         004bc4cf     POP        EBX
//         004bc4d0     RET
//                               LAB_004bc4d1                                                 XREF[1]:     004bc4c1(j)
//                              Sound.cpp:291 (11)
//         004bc4d1     LEA        this,[EAX + EAX*0x8]
//         004bc4d4     MOV        EAX,dword ptr [EDI + this->play_at_update_coun
//         004bc4d8     TEST       EAX,EAX
//         004bc4da     JZ         LAB_004bc4e3
//                              Sound.cpp:292 (3)
//         004bc4dc     ADD        EAX,0xa
//                              Sound.cpp:299 (10)
//         004bc4df     POP        EDI
//         004bc4e0     POP        ESI
//         004bc4e1     POP        EBX
//         004bc4e2     RET
//                               LAB_004bc4e3                                                 XREF[3]:     004bc47a(j), 004bc4b2(j),
//                                                                                                         004bc4da(j)
//         004bc4e3     POP        EDI
//         004bc4e4     POP        ESI
//         004bc4e5     XOR        EAX,EAX
//         004bc4e7     POP        EBX
//         004bc4e8     RET
//         004bc4e9     ??         90h
//         004bc4ea     NOP
//         004bc4eb     NOP
//         004bc4ec     NOP
//         004bc4ed     NOP
//         004bc4ee     NOP
//         004bc4ef     NOP
    return 0;
}

void RGE_Sound::stop() {
    /* TODO: Stub */
//                              void __thiscall stop(RGE_Sound * this)
//              void              <VOID>         <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ?stop@RGE_Sound@@QAEXXZ                                      XREF[3]:     ~TRIBE_Screen_Game:00495535(c),
//                               RGE_Sound::stop                                                           pause:00540d4a(c),
//                                                                                                         turn_sound_off:00541e82(c)
//                              Sound.cpp:304 (4)
//         004bc4f0     PUSH       EBX
//         004bc4f1     PUSH       ESI
//         004bc4f2     MOV        ESI,this
//                              Sound.cpp:307 (9)
//         004bc4f4     MOV        AX,word ptr [ESI + 0x2]
//         004bc4f8     TEST       AX,AX
//         004bc4fb     JLE        LAB_004bc534
//                              Sound.cpp:309 (8)
//         004bc4fd     XOR        EBX,EBX
//         004bc4ff     TEST       AX,AX
//         004bc502     JLE        LAB_004bc534
//         004bc504     PUSH       EDI
//                              Sound.cpp:318 (46)
//         004bc505     XOR        EDI,EDI
//                               LAB_004bc507                                                 XREF[1]:     004bc531(j)
//         004bc507     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc50a     MOV        this,dword ptr [EAX + EDI*0x1 + 0x18]
//         004bc50e     TEST       this,this
//         004bc510     JZ         LAB_004bc527
//         004bc512     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
//         004bc517     TEST       EAX,EAX
//         004bc519     JZ         LAB_004bc527
//         004bc51b     MOV        this,dword ptr [ESI + 0x4]
//         004bc51e     MOV        this,dword ptr [this->play_at_update_count + E
//         004bc522     CALL       TDigital::stop                                   void stop(TDigital * this)
//                               LAB_004bc527                                                 XREF[2]:     004bc510(j), 004bc519(j)
//         004bc527     MOVSX      EDX,word ptr [ESI + 0x2]
//         004bc52b     INC        EBX
//         004bc52c     ADD        EDI,0x24
//         004bc52f     CMP        EBX,EDX
//         004bc531     JL         LAB_004bc507
//                              Sound.cpp:304 (1)
//         004bc533     POP        EDI
//                               LAB_004bc534                                                 XREF[2]:     004bc4fb(j), 004bc502(j)
//                              Sound.cpp:318 (3)
//         004bc534     POP        ESI
//         004bc535     POP        EBX
//         004bc536     RET
//         004bc537     ??         90h
//         004bc538     NOP
//         004bc539     NOP
//         004bc53a     NOP
//         004bc53b     NOP
//         004bc53c     NOP
//         004bc53d     NOP
//         004bc53e     NOP
//         004bc53f     NOP
    return;
}

int RGE_Sound::is_playing() {
    /* TODO: Stub */
//                              int __thiscall is_playing(RGE_Sound * this)
//              int               EAX:4          <RETURN>
//              RGE_Sound *       ECX:4 (auto)   this
//                               ?is_playing@RGE_Sound@@QAEHXZ
//                               RGE_Sound::is_playing
//                              Sound.cpp:323 (5)
//         004bc540     PUSH       EBX
//         004bc541     PUSH       ESI
//         004bc542     MOV        ESI,this
//         004bc544     PUSH       EDI
//                              Sound.cpp:326 (9)
//         004bc545     MOV        AX,word ptr [ESI + 0x2]
//         004bc549     TEST       AX,AX
//         004bc54c     JLE        LAB_004bc586
//                              Sound.cpp:328 (7)
//         004bc54e     XOR        EBX,EBX
//         004bc550     TEST       AX,AX
//         004bc553     JLE        LAB_004bc586
//                              Sound.cpp:339 (2)
//         004bc555     XOR        EDI,EDI
//                               LAB_004bc557                                                 XREF[1]:     004bc575(j)
//                              Sound.cpp:330 (11)
//         004bc557     MOV        EAX,dword ptr [ESI + 0x4]
//         004bc55a     MOV        this,dword ptr [EAX + EDI*0x1 + 0x18]
//         004bc55e     TEST       this,this
//         004bc560     JZ         LAB_004bc56b
//                              Sound.cpp:332 (9)
//         004bc562     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
//         004bc567     TEST       EAX,EAX
//         004bc569     JNZ        LAB_004bc57d
//                               LAB_004bc56b                                                 XREF[1]:     004bc560(j)
//                              Sound.cpp:328 (12)
//         004bc56b     MOVSX      this,word ptr [ESI + 0x2]
//         004bc56f     INC        EBX
//         004bc570     ADD        EDI,0x24
//         004bc573     CMP        EBX,this
//         004bc575     JL         LAB_004bc557
//                              Sound.cpp:338 (2)
//         004bc577     XOR        EAX,EAX
//                              Sound.cpp:339 (4)
//         004bc579     POP        EDI
//         004bc57a     POP        ESI
//         004bc57b     POP        EBX
//         004bc57c     RET
//                               LAB_004bc57d                                                 XREF[1]:     004bc569(j)
//                              Sound.cpp:333 (5)
//         004bc57d     MOV        EAX,0x1
//                              Sound.cpp:339 (10)
//         004bc582     POP        EDI
//         004bc583     POP        ESI
//         004bc584     POP        EBX
//         004bc585     RET
//                               LAB_004bc586                                                 XREF[2]:     004bc54c(j), 004bc553(j)
//         004bc586     POP        EDI
//         004bc587     POP        ESI
//         004bc588     XOR        EAX,EAX
//         004bc58a     POP        EBX
//         004bc58b     RET
//         004bc58c     ??         90h
//         004bc58d     NOP
//         004bc58e     NOP
//         004bc58f     NOP
    return 0;
}

