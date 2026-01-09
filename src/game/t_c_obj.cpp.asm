#include "common.h"
#include "t_c_obj.h"

TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Combat_Object(TRIBE_Combat_Object * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ca1b7(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004ca1bd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004ca1d0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ca1d4(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ca1ef(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ca1c7(W)  
    //                               ??0TRIBE_Combat_Object@@QAE@HPAVRGE_Game_World@@H@Z          XREF[2]:     TRIBE_Building_Object:004c81fd(c), 
    //                               TRIBE_Combat_Object::TRIBE_Combat_Object                                  load:00511bae(c)  
    //                              t_c_obj.cpp:72 (48)
    //         004ca1a0     PUSH       -0x1
    //         004ca1a2     PUSH       FUN_0055fb38
    //         004ca1a7     MOV        EAX,FS:[0x0]
    //         004ca1ad     PUSH       EAX
    //         004ca1ae     MOV        dword ptr FS:[0x0],ESP
    //         004ca1b5     PUSH       this
    //         004ca1b6     PUSH       EBX
    //         004ca1b7     MOV        EBX,dword ptr [ESP + param_1]
    //         004ca1bb     PUSH       ESI
    //         004ca1bc     PUSH       EDI
    //         004ca1bd     MOV        EDI,dword ptr [ESP + param_2]
    //         004ca1c1     PUSH       0x0
    //         004ca1c3     MOV        ESI,this
    //         004ca1c5     PUSH       EDI
    //         004ca1c6     PUSH       EBX
    //         004ca1c7     MOV        dword ptr [ESP + local_10],ESI
    //         004ca1cb     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                              t_c_obj.cpp:73 (22)
    //         004ca1d0     MOV        EAX,dword ptr [ESP + param_3]
    //         004ca1d4     MOV        dword ptr [ESP + local_4],0x0
    //         004ca1dc     TEST       EAX,EAX
    //         004ca1de     MOV        dword ptr [ESI],TRIBE_Combat_Object::`vftable'   = 004ca180
    //         004ca1e4     JZ         LAB_004ca1ef
    //                              t_c_obj.cpp:74 (9)
    //         004ca1e6     PUSH       EDI
    //         004ca1e7     PUSH       EBX
    //         004ca1e8     MOV        this,ESI
    //         004ca1ea     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, int par
    //                               LAB_004ca1ef                                                 XREF[1]:     004ca1e4(j)  
    //                              t_c_obj.cpp:75 (22)
    //         004ca1ef     MOV        this,dword ptr [ESP + local_c]
    //         004ca1f3     MOV        EAX,ESI
    //         004ca1f5     POP        EDI
    //         004ca1f6     POP        ESI
    //         004ca1f7     MOV        dword ptr FS:[0x0],this
    //         004ca1fe     POP        EBX
    //         004ca1ff     ADD        ESP,0x10
    //         004ca202     RET        0xc
    //         004ca205     ??         90h
    //         004ca206     NOP
    //         004ca207     NOP
    //         004ca208     NOP
    //         004ca209     NOP
    //         004ca20a     NOP
    //         004ca20b     NOP
    //         004ca20c     NOP
    //         004ca20d     NOP
    //         004ca20e     NOP
    //         004ca20f     NOP
}

TRIBE_Combat_Object::TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Combat_Object(TRIBE_Combat_Object * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ca1b7(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004ca1bd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004ca1d0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ca1d4(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ca1ef(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ca1c7(W)  
    //                               ??0TRIBE_Combat_Object@@QAE@HPAVRGE_Game_World@@H@Z          XREF[2]:     TRIBE_Building_Object:004c81fd(c), 
    //                               TRIBE_Combat_Object::TRIBE_Combat_Object                                  load:00511bae(c)  
    //                              t_c_obj.cpp:72 (48)
    //         004ca1a0     PUSH       -0x1
    //         004ca1a2     PUSH       FUN_0055fb38
    //         004ca1a7     MOV        EAX,FS:[0x0]
    //         004ca1ad     PUSH       EAX
    //         004ca1ae     MOV        dword ptr FS:[0x0],ESP
    //         004ca1b5     PUSH       this
    //         004ca1b6     PUSH       EBX
    //         004ca1b7     MOV        EBX,dword ptr [ESP + param_1]
    //         004ca1bb     PUSH       ESI
    //         004ca1bc     PUSH       EDI
    //         004ca1bd     MOV        EDI,dword ptr [ESP + param_2]
    //         004ca1c1     PUSH       0x0
    //         004ca1c3     MOV        ESI,this
    //         004ca1c5     PUSH       EDI
    //         004ca1c6     PUSH       EBX
    //         004ca1c7     MOV        dword ptr [ESP + local_10],ESI
    //         004ca1cb     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                              t_c_obj.cpp:73 (22)
    //         004ca1d0     MOV        EAX,dword ptr [ESP + param_3]
    //         004ca1d4     MOV        dword ptr [ESP + local_4],0x0
    //         004ca1dc     TEST       EAX,EAX
    //         004ca1de     MOV        dword ptr [ESI],TRIBE_Combat_Object::`vftable'   = 004ca180
    //         004ca1e4     JZ         LAB_004ca1ef
    //                              t_c_obj.cpp:74 (9)
    //         004ca1e6     PUSH       EDI
    //         004ca1e7     PUSH       EBX
    //         004ca1e8     MOV        this,ESI
    //         004ca1ea     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, int par
    //                               LAB_004ca1ef                                                 XREF[1]:     004ca1e4(j)  
    //                              t_c_obj.cpp:75 (22)
    //         004ca1ef     MOV        this,dword ptr [ESP + local_c]
    //         004ca1f3     MOV        EAX,ESI
    //         004ca1f5     POP        EDI
    //         004ca1f6     POP        ESI
    //         004ca1f7     MOV        dword ptr FS:[0x0],this
    //         004ca1fe     POP        EBX
    //         004ca1ff     ADD        ESP,0x10
    //         004ca202     RET        0xc
    //         004ca205     ??         90h
    //         004ca206     NOP
    //         004ca207     NOP
    //         004ca208     NOP
    //         004ca209     NOP
    //         004ca20a     NOP
    //         004ca20b     NOP
    //         004ca20c     NOP
    //         004ca20d     NOP
    //         004ca20e     NOP
    //         004ca20f     NOP
}

TRIBE_Combat_Object::~TRIBE_Combat_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Combat_Object(TRIBE_Combat_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ca23a(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ca22a(W)  
    //                               ??1TRIBE_Combat_Object@@UAE@XZ                               XREF[2]:     ~TRIBE_Building_Object:004c8350(c)
    //                               TRIBE_Combat_Object::~TRIBE_Combat_Object                                 `vector_deleting_destructor':004ca
    //                              t_c_obj.cpp:81 (36)
    //         004ca210     PUSH       -0x1
    //         004ca212     PUSH       FUN_0055fb58
    //         004ca217     MOV        EAX,FS:[0x0]
    //         004ca21d     PUSH       EAX
    //         004ca21e     MOV        dword ptr FS:[0x0],ESP
    //         004ca225     PUSH       this
    //         004ca226     PUSH       ESI
    //         004ca227     MOV        ESI,this
    //         004ca229     PUSH       EDI
    //         004ca22a     MOV        dword ptr [ESP + local_10],ESI
    //         004ca22e     MOV        dword ptr [ESI],TRIBE_Combat_Object::`vftable'   = 004ca180
    //                              t_c_obj.cpp:84 (18)
    //         004ca234     MOV        AL,byte ptr [ESI + 0x1c4]
    //         004ca23a     MOV        dword ptr [ESP + local_4],0x0
    //         004ca242     TEST       AL,AL
    //         004ca244     JZ         LAB_004ca263
    //                              t_c_obj.cpp:86 (3)
    //         004ca246     MOV        this,dword ptr [ESI + 0x8]
    //                              t_c_obj.cpp:87 (14)
    //         004ca249     TEST       this,this
    //         004ca24b     MOVSX      EDI,word ptr [ECX + this->_padding_]
    //         004ca24f     JZ         LAB_004ca257
    //         004ca251     MOV        EAX,dword ptr [this->_padding_]
    //         004ca253     PUSH       0x1
    //         004ca255     CALL       dword ptr [EAX]
    //                               LAB_004ca257                                                 XREF[1]:     004ca24f(j)  
    //                              t_c_obj.cpp:88 (12)
    //         004ca257     MOV        this,dword ptr [ESI + 0xc]
    //         004ca25a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ca25d     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         004ca260     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_004ca263                                                 XREF[1]:     004ca244(j)  
    //                              t_c_obj.cpp:95 (25)
    //         004ca263     MOV        this,dword ptr [ESI + 0x8]
    //         004ca266     MOV        AX,word ptr [ECX + this->_padding_]
    //         004ca26a     CMP        AX,0x4
    //         004ca26e     JZ         LAB_004ca2b9
    //         004ca270     CMP        AX,0x15
    //         004ca274     JZ         LAB_004ca2b9
    //         004ca276     CMP        AX,0x2
    //         004ca27a     JZ         LAB_004ca2b9
    //                              t_c_obj.cpp:102 (35)
    //         004ca27c     CMP        AX,0x12
    //         004ca280     JZ         LAB_004ca288
    //         004ca282     CMP        byte ptr [ECX + this->_padding_],0x46
    //         004ca286     JZ         LAB_004ca29f
    //                               LAB_004ca288                                                 XREF[1]:     004ca280(j)  
    //         004ca288     MOV        this,word ptr [ECX + this->_padding_]
    //         004ca28c     CMP        this,0x4f
    //         004ca290     JZ         LAB_004ca29f
    //         004ca292     CMP        this,0x45
    //         004ca296     JZ         LAB_004ca29f
    //         004ca298     CMP        this,0xc7
    //         004ca29d     JNZ        LAB_004ca2d1
    //                               LAB_004ca29f                                                 XREF[3]:     004ca286(j), 004ca290(j), 
    //                                                                                                         004ca296(j)  
    //                              t_c_obj.cpp:103 (26)
    //         004ca29f     MOV        this,dword ptr [ESI + 0xc]
    //         004ca2a2     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca2a5     FLD        float ptr [EAX + 0xa0]
    //         004ca2ab     FSUB       float ptr [DAT_00574c78]                         = align(2)
    //         004ca2b1     FSTP       float ptr [EAX + 0xa0]
    //         004ca2b7     JMP        LAB_004ca2d1
    //                               LAB_004ca2b9                                                 XREF[3]:     004ca26e(j), 004ca274(j), 
    //                                                                                                         004ca27a(j)  
    //                              t_c_obj.cpp:96 (26)
    //         004ca2b9     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca2bc     MOV        EAX,dword ptr [EDX + 0x50]
    //         004ca2bf     FLD        float ptr [EAX + 0x94]
    //         004ca2c5     FSUB       float ptr [DAT_00574c78]                         = align(2)
    //         004ca2cb     FSTP       float ptr [EAX + 0x94]
    //                               LAB_004ca2d1                                                 XREF[2]:     004ca29d(j), 004ca2b7(j)  
    //         004ca2d1     MOV        this,ESI
    //                              t_c_obj.cpp:104 (30)
    //         004ca2d3     MOV        dword ptr [ESP + 0x14],0xffffffff
    //         004ca2db     CALL       RGE_Combat_Object::~RGE_Combat_Object            void ~RGE_Combat_Object(RGE_Combat_Object * t
    //         004ca2e0     MOV        this,dword ptr [ESP + 0xc]
    //         004ca2e4     POP        EDI
    //         004ca2e5     MOV        dword ptr FS:[0x0],this
    //         004ca2ec     POP        ESI
    //         004ca2ed     ADD        ESP,0x10
    //         004ca2f0     RET
    //         004ca2f1     ??         90h
    //         004ca2f2     NOP
    //         004ca2f3     NOP
    //         004ca2f4     NOP
    //         004ca2f5     NOP
    //         004ca2f6     NOP
    //         004ca2f7     NOP
    //         004ca2f8     NOP
    //         004ca2f9     NOP
    //         004ca2fa     NOP
    //         004ca2fb     NOP
    //         004ca2fc     NOP
    //         004ca2fd     NOP
    //         004ca2fe     NOP
    //         004ca2ff     NOP
    //                              * protected: virtual int __thiscall TRIBE_Combat_Object::setup(class TRIBE_Master_Combat_Object *,cl... *
    //                              int __thiscall setup(TRIBE_Combat_Object * this, TRIBE_Master_Combat
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              TRIBE_Master_C    Stack[0x4]:4   param_1                   XREF[1]:     004ca315(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004ca310(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004ca304(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004ca30b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004ca300(R)  
    //                               ?setup@TRIBE_Combat_Object@@MAEHPAVTRIBE_Master_Combat_Obje  XREF[4]:     setup:004c8407(c), 
    //                               TRIBE_Combat_Object::setup                                                TRIBE_Combat_Object:004ca157(c), 
    //                                                                                                         005749cc(*), 00574c74(*)  
    //                              t_c_obj.cpp:111 (35)
    //         004ca300     MOV        EAX,dword ptr [ESP + param_5]
    //         004ca304     MOV        EDX,dword ptr [ESP + param_3]
    //         004ca308     PUSH       ESI
    //         004ca309     MOV        ESI,this
    //         004ca30b     MOV        this,dword ptr [ESP + param_4]
    //         004ca30f     PUSH       EAX
    //         004ca310     MOV        EAX,dword ptr [ESP + param_2]
    //         004ca314     PUSH       this
    //         004ca315     MOV        this,dword ptr [ESP + param_1]
    //         004ca319     PUSH       EDX
    //         004ca31a     PUSH       EAX
    //         004ca31b     PUSH       this
    //         004ca31c     MOV        this,ESI
    //         004ca31e     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, RGE_Maste
    //                              t_c_obj.cpp:116 (10)
    //         004ca323     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca326     CMP        word ptr [EDX + 0x4a],0x0
    //         004ca32b     JNZ        LAB_004ca334
    //                              t_c_obj.cpp:117 (7)
    //         004ca32d     MOV        byte ptr [ESI + 0x1c0],0x1
    //                               LAB_004ca334                                                 XREF[1]:     004ca32b(j)  
    //                              t_c_obj.cpp:121 (14)
    //         004ca334     MOV        EAX,dword ptr [ESI]
    //         004ca336     MOV        this,ESI
    //         004ca338     MOV        byte ptr [ESI + 0x4e],0x46
    //         004ca33c     CALL       dword ptr [EAX + 0x250]
    //                              t_c_obj.cpp:128 (32)
    //         004ca342     MOV        this,dword ptr [ESI + 0x8]
    //         004ca345     MOV        byte ptr [ESI + 0x1c4],0x0
    //         004ca34c     MOV        AX,word ptr [ECX + this->_padding_]
    //         004ca350     CMP        AX,0x4
    //         004ca354     JZ         LAB_004ca39f
    //         004ca356     CMP        AX,0x15
    //         004ca35a     JZ         LAB_004ca39f
    //         004ca35c     CMP        AX,0x2
    //         004ca360     JZ         LAB_004ca39f
    //                              t_c_obj.cpp:135 (35)
    //         004ca362     CMP        AX,0x12
    //         004ca366     JZ         LAB_004ca36e
    //         004ca368     CMP        byte ptr [ECX + this->_padding_],0x46
    //         004ca36c     JZ         LAB_004ca385
    //                               LAB_004ca36e                                                 XREF[1]:     004ca366(j)  
    //         004ca36e     MOV        this,word ptr [ECX + this->_padding_]
    //         004ca372     CMP        this,0x4f
    //         004ca376     JZ         LAB_004ca385
    //         004ca378     CMP        this,0x45
    //         004ca37c     JZ         LAB_004ca385
    //         004ca37e     CMP        this,0xc7
    //         004ca383     JNZ        LAB_004ca3b7
    //                               LAB_004ca385                                                 XREF[3]:     004ca36c(j), 004ca376(j), 
    //                                                                                                         004ca37c(j)  
    //                              t_c_obj.cpp:136 (26)
    //         004ca385     MOV        this,dword ptr [ESI + 0xc]
    //         004ca388     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca38b     FLD        float ptr [EAX + 0xa0]
    //         004ca391     FSUB       float ptr [DAT_00574c7c]
    //         004ca397     FSTP       float ptr [EAX + 0xa0]
    //         004ca39d     JMP        LAB_004ca3b7
    //                               LAB_004ca39f                                                 XREF[3]:     004ca354(j), 004ca35a(j), 
    //                                                                                                         004ca360(j)  
    //                              t_c_obj.cpp:129 (24)
    //         004ca39f     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca3a2     MOV        EAX,dword ptr [EDX + 0x50]
    //         004ca3a5     FLD        float ptr [EAX + 0x94]
    //         004ca3ab     FSUB       float ptr [DAT_00574c7c]
    //         004ca3b1     FSTP       float ptr [EAX + 0x94]
    //                               LAB_004ca3b7                                                 XREF[2]:     004ca383(j), 004ca39d(j)  
    //                              t_c_obj.cpp:139 (10)
    //         004ca3b7     MOV        EAX,dword ptr [ESI + 0x8]
    //         004ca3ba     CMP        word ptr [EAX + 0x14],0x12
    //         004ca3bf     JNZ        LAB_004ca3ce
    //                              t_c_obj.cpp:141 (7)
    //         004ca3c1     MOV        dword ptr [ESI + 0x44],0x42c80000
    //                              t_c_obj.cpp:142 (6)
    //         004ca3c8     MOV        word ptr [ESI + 0x4c],0x22
    //                               LAB_004ca3ce                                                 XREF[1]:     004ca3bf(j)  
    //                              t_c_obj.cpp:145 (5)
    //         004ca3ce     MOV        EAX,0x1
    //                              t_c_obj.cpp:146 (4)
    //         004ca3d3     POP        ESI
    //         004ca3d4     RET        0x14
    //         004ca3d7     ??         90h
    //         004ca3d8     NOP
    //         004ca3d9     NOP
    //         004ca3da     NOP
    //         004ca3db     NOP
    //         004ca3dc     NOP
    //         004ca3dd     NOP
    //         004ca3de     NOP
    //         004ca3df     NOP
}

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Combat_Object * this, int param_1, RGE_Ga
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004ca3fd(R), 004ca4c1(*), 004ca4ce(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[3]:     004ca3f6(R), 004ca42a(*), 004ca437(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004ca455(W), 004ca490(W), 004ca4b6(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ca4f3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004ca44f(W), 004ca48a(W)  
    //                               ?setup@TRIBE_Combat_Object@@MAEHHPAVRGE_Game_World@@@Z       XREF[3]:     setup:004c849e(c), 
    //                               TRIBE_Combat_Object::setup                                                TRIBE_Combat_Object:004ca1ea(c), 
    //                                                                                                         00574bf8(*)  
    //                              t_c_obj.cpp:152 (22)
    //         004ca3e0     PUSH       -0x1
    //         004ca3e2     PUSH       FUN_0055fb86
    //         004ca3e7     MOV        EAX,FS:[0x0]
    //         004ca3ed     PUSH       EAX
    //         004ca3ee     MOV        dword ptr FS:[0x0],ESP
    //         004ca3f5     PUSH       this
    //                              t_c_obj.cpp:155 (20)
    //         004ca3f6     MOV        EAX,dword ptr [ESP + param_2]
    //         004ca3fa     PUSH       EBX
    //         004ca3fb     PUSH       ESI
    //         004ca3fc     PUSH       EDI
    //         004ca3fd     MOV        EDI,dword ptr [ESP + param_1]
    //         004ca401     PUSH       EAX
    //         004ca402     MOV        ESI,this
    //         004ca404     PUSH       EDI
    //         004ca405     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, int param
    //                              t_c_obj.cpp:159 (19)
    //         004ca40a     LEA        EBX,[ESI + 0x1c4]
    //         004ca410     PUSH       0x1
    //         004ca412     PUSH       EBX
    //         004ca413     PUSH       EDI
    //         004ca414     MOV        byte ptr [ESI + 0x4e],0x46
    //         004ca418     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:160 (13)
    //         004ca41d     MOV        AL,byte ptr [EBX]
    //         004ca41f     ADD        ESP,0xc
    //         004ca422     TEST       AL,AL
    //         004ca424     JZ         LAB_004ca4c1
    //                              t_c_obj.cpp:162 (13)
    //         004ca42a     LEA        this=>param_2,[ESP + 0x24]
    //         004ca42e     PUSH       0x1
    //         004ca430     PUSH       this
    //         004ca431     PUSH       EDI
    //         004ca432     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:163 (11)
    //         004ca437     MOV        AL,byte ptr [ESP + param_2]
    //         004ca43b     ADD        ESP,0xc
    //         004ca43e     CMP        AL,0x46
    //         004ca440     JNZ        LAB_004ca479
    //                              t_c_obj.cpp:164 (53)
    //         004ca442     PUSH       0x164
    //         004ca447     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ca44c     ADD        ESP,0x4
    //         004ca44f     MOV        dword ptr [ESP + local_10],EAX
    //         004ca453     TEST       EAX,EAX
    //         004ca455     MOV        dword ptr [ESP + local_4],0x0
    //         004ca45d     JZ         LAB_004ca4b4
    //         004ca45f     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca462     PUSH       0x1
    //         004ca464     MOV        EDX,dword ptr [EDX + 0x3c]
    //         004ca467     MOV        this,dword ptr [EDX + 0x30]
    //         004ca46a     MOV        EDX,dword ptr [EDX + 0x38]
    //         004ca46d     PUSH       this
    //         004ca46e     PUSH       EDX
    //         004ca46f     PUSH       EDI
    //         004ca470     MOV        this,EAX
    //         004ca472     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              t_c_obj.cpp:165 (6)
    //         004ca477     JMP        LAB_004ca4b6
    //                               LAB_004ca479                                                 XREF[1]:     004ca440(j)  
    //         004ca479     CMP        AL,0x50
    //         004ca47b     JNZ        LAB_004ca4c1
    //                              t_c_obj.cpp:166 (68)
    //         004ca47d     PUSH       0x17c
    //         004ca482     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ca487     ADD        ESP,0x4
    //         004ca48a     MOV        dword ptr [ESP + local_10],EAX
    //         004ca48e     TEST       EAX,EAX
    //         004ca490     MOV        dword ptr [ESP + local_4],0x1
    //         004ca498     JZ         LAB_004ca4b4
    //         004ca49a     MOV        this,dword ptr [ESI + 0xc]
    //         004ca49d     PUSH       0x1
    //         004ca49f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ca4a2     MOV        this,dword ptr [EDX + 0x30]
    //         004ca4a5     MOV        EDX,dword ptr [EDX + 0x38]
    //         004ca4a8     PUSH       this
    //         004ca4a9     PUSH       EDX
    //         004ca4aa     PUSH       EDI
    //         004ca4ab     MOV        this,EAX
    //         004ca4ad     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
    //         004ca4b2     JMP        LAB_004ca4b6
    //                               LAB_004ca4b4                                                 XREF[2]:     004ca45d(j), 004ca498(j)  
    //         004ca4b4     XOR        EAX,EAX
    //                               LAB_004ca4b6                                                 XREF[2]:     004ca477(j), 004ca4b2(j)  
    //         004ca4b6     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004ca4be     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_004ca4c1                                                 XREF[2]:     004ca424(j), 004ca47b(j)  
    //                              t_c_obj.cpp:170 (13)
    //         004ca4c1     LEA        EAX=>param_1,[ESP + 0x20]
    //         004ca4c5     PUSH       0x4
    //         004ca4c7     PUSH       EAX
    //         004ca4c8     PUSH       EDI
    //         004ca4c9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:172 (12)
    //         004ca4ce     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca4d2     ADD        ESP,0xc
    //         004ca4d5     CMP        EAX,0x1
    //         004ca4d8     JNZ        LAB_004ca4f3
    //                              t_c_obj.cpp:174 (10)
    //         004ca4da     MOV        EDX,dword ptr [ESI]
    //         004ca4dc     MOV        this,ESI
    //         004ca4de     CALL       dword ptr [EDX + 0x250]
    //                              t_c_obj.cpp:175 (7)
    //         004ca4e4     MOV        ESI,dword ptr [ESI + 0x74]
    //         004ca4e7     TEST       ESI,ESI
    //         004ca4e9     JZ         LAB_004ca4f3
    //                              t_c_obj.cpp:176 (8)
    //         004ca4eb     MOV        EAX,dword ptr [ESI]
    //         004ca4ed     PUSH       EDI
    //         004ca4ee     MOV        this,ESI
    //         004ca4f0     CALL       dword ptr [EAX + 0x8]
    //                               LAB_004ca4f3                                                 XREF[2]:     004ca4d8(j), 004ca4e9(j)  
    //                              t_c_obj.cpp:180 (25)
    //         004ca4f3     MOV        this,dword ptr [ESP + local_c]
    //         004ca4f7     POP        EDI
    //         004ca4f8     POP        ESI
    //         004ca4f9     MOV        EAX,0x1
    //         004ca4fe     MOV        dword ptr FS:[0x0],this
    //         004ca505     POP        EBX
    //         004ca506     ADD        ESP,0x10
    //         004ca509     RET        0x8
    //         004ca50c     ??         90h
    //         004ca50d     NOP
    //         004ca50e     NOP
    //         004ca50f     NOP
    return 0;
}

int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Combat_Object * this, int param_1, RGE_Ga
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004ca3fd(R), 004ca4c1(*), 004ca4ce(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[3]:     004ca3f6(R), 004ca42a(*), 004ca437(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004ca455(W), 004ca490(W), 004ca4b6(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ca4f3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004ca44f(W), 004ca48a(W)  
    //                               ?setup@TRIBE_Combat_Object@@MAEHHPAVRGE_Game_World@@@Z       XREF[3]:     setup:004c849e(c), 
    //                               TRIBE_Combat_Object::setup                                                TRIBE_Combat_Object:004ca1ea(c), 
    //                                                                                                         00574bf8(*)  
    //                              t_c_obj.cpp:152 (22)
    //         004ca3e0     PUSH       -0x1
    //         004ca3e2     PUSH       FUN_0055fb86
    //         004ca3e7     MOV        EAX,FS:[0x0]
    //         004ca3ed     PUSH       EAX
    //         004ca3ee     MOV        dword ptr FS:[0x0],ESP
    //         004ca3f5     PUSH       this
    //                              t_c_obj.cpp:155 (20)
    //         004ca3f6     MOV        EAX,dword ptr [ESP + param_2]
    //         004ca3fa     PUSH       EBX
    //         004ca3fb     PUSH       ESI
    //         004ca3fc     PUSH       EDI
    //         004ca3fd     MOV        EDI,dword ptr [ESP + param_1]
    //         004ca401     PUSH       EAX
    //         004ca402     MOV        ESI,this
    //         004ca404     PUSH       EDI
    //         004ca405     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, int param
    //                              t_c_obj.cpp:159 (19)
    //         004ca40a     LEA        EBX,[ESI + 0x1c4]
    //         004ca410     PUSH       0x1
    //         004ca412     PUSH       EBX
    //         004ca413     PUSH       EDI
    //         004ca414     MOV        byte ptr [ESI + 0x4e],0x46
    //         004ca418     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:160 (13)
    //         004ca41d     MOV        AL,byte ptr [EBX]
    //         004ca41f     ADD        ESP,0xc
    //         004ca422     TEST       AL,AL
    //         004ca424     JZ         LAB_004ca4c1
    //                              t_c_obj.cpp:162 (13)
    //         004ca42a     LEA        this=>param_2,[ESP + 0x24]
    //         004ca42e     PUSH       0x1
    //         004ca430     PUSH       this
    //         004ca431     PUSH       EDI
    //         004ca432     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:163 (11)
    //         004ca437     MOV        AL,byte ptr [ESP + param_2]
    //         004ca43b     ADD        ESP,0xc
    //         004ca43e     CMP        AL,0x46
    //         004ca440     JNZ        LAB_004ca479
    //                              t_c_obj.cpp:164 (53)
    //         004ca442     PUSH       0x164
    //         004ca447     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ca44c     ADD        ESP,0x4
    //         004ca44f     MOV        dword ptr [ESP + local_10],EAX
    //         004ca453     TEST       EAX,EAX
    //         004ca455     MOV        dword ptr [ESP + local_4],0x0
    //         004ca45d     JZ         LAB_004ca4b4
    //         004ca45f     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca462     PUSH       0x1
    //         004ca464     MOV        EDX,dword ptr [EDX + 0x3c]
    //         004ca467     MOV        this,dword ptr [EDX + 0x30]
    //         004ca46a     MOV        EDX,dword ptr [EDX + 0x38]
    //         004ca46d     PUSH       this
    //         004ca46e     PUSH       EDX
    //         004ca46f     PUSH       EDI
    //         004ca470     MOV        this,EAX
    //         004ca472     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              t_c_obj.cpp:165 (6)
    //         004ca477     JMP        LAB_004ca4b6
    //                               LAB_004ca479                                                 XREF[1]:     004ca440(j)  
    //         004ca479     CMP        AL,0x50
    //         004ca47b     JNZ        LAB_004ca4c1
    //                              t_c_obj.cpp:166 (68)
    //         004ca47d     PUSH       0x17c
    //         004ca482     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ca487     ADD        ESP,0x4
    //         004ca48a     MOV        dword ptr [ESP + local_10],EAX
    //         004ca48e     TEST       EAX,EAX
    //         004ca490     MOV        dword ptr [ESP + local_4],0x1
    //         004ca498     JZ         LAB_004ca4b4
    //         004ca49a     MOV        this,dword ptr [ESI + 0xc]
    //         004ca49d     PUSH       0x1
    //         004ca49f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ca4a2     MOV        this,dword ptr [EDX + 0x30]
    //         004ca4a5     MOV        EDX,dword ptr [EDX + 0x38]
    //         004ca4a8     PUSH       this
    //         004ca4a9     PUSH       EDX
    //         004ca4aa     PUSH       EDI
    //         004ca4ab     MOV        this,EAX
    //         004ca4ad     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
    //         004ca4b2     JMP        LAB_004ca4b6
    //                               LAB_004ca4b4                                                 XREF[2]:     004ca45d(j), 004ca498(j)  
    //         004ca4b4     XOR        EAX,EAX
    //                               LAB_004ca4b6                                                 XREF[2]:     004ca477(j), 004ca4b2(j)  
    //         004ca4b6     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004ca4be     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_004ca4c1                                                 XREF[2]:     004ca424(j), 004ca47b(j)  
    //                              t_c_obj.cpp:170 (13)
    //         004ca4c1     LEA        EAX=>param_1,[ESP + 0x20]
    //         004ca4c5     PUSH       0x4
    //         004ca4c7     PUSH       EAX
    //         004ca4c8     PUSH       EDI
    //         004ca4c9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_c_obj.cpp:172 (12)
    //         004ca4ce     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca4d2     ADD        ESP,0xc
    //         004ca4d5     CMP        EAX,0x1
    //         004ca4d8     JNZ        LAB_004ca4f3
    //                              t_c_obj.cpp:174 (10)
    //         004ca4da     MOV        EDX,dword ptr [ESI]
    //         004ca4dc     MOV        this,ESI
    //         004ca4de     CALL       dword ptr [EDX + 0x250]
    //                              t_c_obj.cpp:175 (7)
    //         004ca4e4     MOV        ESI,dword ptr [ESI + 0x74]
    //         004ca4e7     TEST       ESI,ESI
    //         004ca4e9     JZ         LAB_004ca4f3
    //                              t_c_obj.cpp:176 (8)
    //         004ca4eb     MOV        EAX,dword ptr [ESI]
    //         004ca4ed     PUSH       EDI
    //         004ca4ee     MOV        this,ESI
    //         004ca4f0     CALL       dword ptr [EAX + 0x8]
    //                               LAB_004ca4f3                                                 XREF[2]:     004ca4d8(j), 004ca4e9(j)  
    //                              t_c_obj.cpp:180 (25)
    //         004ca4f3     MOV        this,dword ptr [ESP + local_c]
    //         004ca4f7     POP        EDI
    //         004ca4f8     POP        ESI
    //         004ca4f9     MOV        EAX,0x1
    //         004ca4fe     MOV        dword ptr FS:[0x0],this
    //         004ca505     POP        EBX
    //         004ca506     ADD        ESP,0x10
    //         004ca509     RET        0x8
    //         004ca50c     ??         90h
    //         004ca50d     NOP
    //         004ca50e     NOP
    //         004ca50f     NOP
    return 0;
}

RGE_Action_List* TRIBE_Combat_Object::create_action_list() {
    /* TODO: Stub */
    //                              RGE_Action_List * __thiscall create_action_list(TRIBE_Combat_Object 
    //              RGE_Action_Lis    EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ca539(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004ca54b(R), 004ca55b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ca533(W)  
    //                               ?create_action_list@TRIBE_Combat_Object@@UAEPAVRGE_Action_L  XREF[2]:     00574990(*), 00574c38(*)  
    //                               TRIBE_Combat_Object::create_action_list
    //                              t_c_obj.cpp:186 (25)
    //         004ca510     PUSH       -0x1
    //         004ca512     PUSH       FUN_0055fb9b
    //         004ca517     MOV        EAX,FS:[0x0]
    //         004ca51d     PUSH       EAX
    //         004ca51e     MOV        dword ptr FS:[0x0],ESP
    //         004ca525     PUSH       this
    //         004ca526     PUSH       ESI
    //         004ca527     MOV        ESI,this
    //                              t_c_obj.cpp:187 (34)
    //         004ca529     PUSH       0xc
    //         004ca52b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ca530     ADD        ESP,0x4
    //         004ca533     MOV        dword ptr [ESP + local_10],EAX
    //         004ca537     TEST       EAX,EAX
    //         004ca539     MOV        dword ptr [ESP + local_4],0x0
    //         004ca541     JZ         LAB_004ca55b
    //         004ca543     PUSH       ESI
    //         004ca544     MOV        this,EAX
    //         004ca546     CALL       TRIBE_Action_List::TRIBE_Action_List             undefined TRIBE_Action_List(TRIBE_Action_List
    //                              t_c_obj.cpp:189 (34)
    //         004ca54b     MOV        this,dword ptr [ESP + local_c]
    //         004ca54f     MOV        dword ptr FS:[0x0],this
    //         004ca556     POP        ESI
    //         004ca557     ADD        ESP,0x10
    //         004ca55a     RET
    //                               LAB_004ca55b                                                 XREF[1]:     004ca541(j)  
    //         004ca55b     MOV        this,dword ptr [ESP + local_c]
    //         004ca55f     XOR        EAX,EAX
    //         004ca561     MOV        dword ptr FS:[0x0],this
    //         004ca568     POP        ESI
    //         004ca569     ADD        ESP,0x10
    //         004ca56c     RET
    //         004ca56d     ??         90h
    //         004ca56e     NOP
    //         004ca56f     NOP
    return 0;
}

void TRIBE_Combat_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(TRIBE_Combat_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004ca573(R), 004ca5a7(*), 004ca5af(W)  
    //                               ?save@TRIBE_Combat_Object@@UAEXH@Z                           XREF[2]:     save:004c8bcb(c), 00574a50(*)  
    //                               TRIBE_Combat_Object::save
    //                              t_c_obj.cpp:195 (3)
    //         004ca570     PUSH       EBX
    //         004ca571     PUSH       ESI
    //         004ca572     PUSH       EDI
    //                              t_c_obj.cpp:196 (12)
    //         004ca573     MOV        EDI,dword ptr [ESP + param_1]
    //         004ca577     MOV        ESI,this
    //         004ca579     PUSH       EDI
    //         004ca57a     CALL       RGE_Combat_Object::save                          void save(RGE_Combat_Object * this, int param
    //                              t_c_obj.cpp:198 (15)
    //         004ca57f     LEA        EBX,[ESI + 0x1c4]
    //         004ca585     PUSH       0x1
    //         004ca587     PUSH       EBX
    //         004ca588     PUSH       EDI
    //         004ca589     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              t_c_obj.cpp:199 (9)
    //         004ca58e     MOV        AL,byte ptr [EBX]
    //         004ca590     ADD        ESP,0xc
    //         004ca593     TEST       AL,AL
    //         004ca595     JZ         LAB_004ca5a0
    //                              t_c_obj.cpp:200 (9)
    //         004ca597     MOV        this,dword ptr [ESI + 0x8]
    //         004ca59a     PUSH       EDI
    //         004ca59b     MOV        EAX,dword ptr [this->_padding_]
    //         004ca59d     CALL       dword ptr [EAX + 0x14]
    //                               LAB_004ca5a0                                                 XREF[1]:     004ca595(j)  
    //                              t_c_obj.cpp:203 (7)
    //         004ca5a0     MOV        EAX,dword ptr [ESI + 0x74]
    //         004ca5a3     TEST       EAX,EAX
    //         004ca5a5     JZ         LAB_004ca5ce
    //                              t_c_obj.cpp:206 (21)
    //         004ca5a7     LEA        this=>param_1,[ESP + 0x10]
    //         004ca5ab     PUSH       0x4
    //         004ca5ad     PUSH       this=>DAT_fffffff8
    //         004ca5ae     PUSH       EDI=>DAT_fffffff4
    //         004ca5af     MOV        dword ptr [ESP + param_1],0x1
    //         004ca5b7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              t_c_obj.cpp:207 (12)
    //         004ca5bc     MOV        this,dword ptr [ESI + 0x74]
    //         004ca5bf     ADD        ESP,0xc
    //         004ca5c2     MOV        EDX,dword ptr [this->_padding_]
    //         004ca5c4     PUSH       EDI
    //         004ca5c5     CALL       dword ptr [EDX + 0x4]
    //                              t_c_obj.cpp:213 (6)
    //         004ca5c8     POP        EDI
    //         004ca5c9     POP        ESI
    //         004ca5ca     POP        EBX
    //         004ca5cb     RET        0x4
    //                               LAB_004ca5ce                                                 XREF[1]:     004ca5a5(j)  
    //                              t_c_obj.cpp:211 (24)
    //         004ca5ce     LEA        EAX,[ESP + 0x10]
    //         004ca5d2     PUSH       0x4
    //         004ca5d4     PUSH       EAX=>DAT_fffffff8
    //         004ca5d5     PUSH       EDI=>DAT_fffffff4
    //         004ca5d6     MOV        dword ptr [ESP + 0x1c],0x0
    //         004ca5de     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004ca5e3     ADD        ESP,0xc
    //                              t_c_obj.cpp:213 (6)
    //         004ca5e6     POP        EDI
    //         004ca5e7     POP        ESI
    //         004ca5e8     POP        EBX
    //         004ca5e9     RET        0x4
    //         004ca5ec     ??         90h
    //         004ca5ed     NOP
    //         004ca5ee     NOP
    //         004ca5ef     NOP
    return;
}

uchar TRIBE_Combat_Object::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(TRIBE_Combat_Object * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //                               ?update@TRIBE_Combat_Object@@UAEEXZ                          XREF[2]:     update:004c8b31(c), 00574a44(*)  
    //                               TRIBE_Combat_Object::update
    //                              t_c_obj.cpp:219 (16)
    //         004ca5f0     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca5f3     CMP        word ptr [EAX + 0x14],0x12
    //         004ca5f8     JNZ        LAB_004ca635
    //         004ca5fa     CMP        byte ptr [ECX + this->_padding_],0x2
    //         004ca5fe     JNZ        LAB_004ca635
    //                              t_c_obj.cpp:224 (24)
    //         004ca600     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca603     MOV        EDX,dword ptr [EAX + 0x50]
    //         004ca606     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004ca609     FLD        float ptr [EDX + 0x8c]
    //         004ca60f     FMUL       float ptr [EAX + 0x84]
    //         004ca615     FADD       float ptr [ECX + this->_padding_]
    //                              t_c_obj.cpp:225 (16)
    //         004ca618     FCOM       float ptr [DAT_00574c80]
    //         004ca61e     FSTP       float ptr [ECX + this->_padding_]
    //         004ca621     FNSTSW     AX
    //         004ca623     TEST       AH,0x1
    //         004ca626     JNZ        LAB_004ca62f
    //                              t_c_obj.cpp:226 (7)
    //         004ca628     MOV        dword ptr [ECX + this->_padding_],0x42c80000
    //                               LAB_004ca62f                                                 XREF[1]:     004ca626(j)  
    //                              t_c_obj.cpp:227 (6)
    //         004ca62f     MOV        word ptr [ECX + this->_padding_],0x22
    //                               LAB_004ca635                                                 XREF[2]:     004ca5f8(j), 004ca5fe(j)  
    //                              t_c_obj.cpp:230 (5)
    //         004ca635     JMP        RGE_Combat_Object::update                        uchar update(RGE_Combat_Object * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         004ca63a     ??         90h
    //         004ca63b     NOP
    //         004ca63c     NOP
    //         004ca63d     NOP
    //         004ca63e     NOP
    //         004ca63f     NOP
    return 0;
}

void TRIBE_Combat_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall modify(TRIBE_Combat_Object * this, float param_1, uc
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[4]:     004ca676(R), 004ca6a5(R), 004ca6ce(R), 004ca6e6(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004ca641(R)  
    //                               ?modify@TRIBE_Combat_Object@@UAEXME@Z                        XREF[2]:     modify:004c8e71(c), 00574a68(*)  
    //                               TRIBE_Combat_Object::modify
    //                              t_c_obj.cpp:237 (1)
    //         004ca640     PUSH       EBX
    //                              t_c_obj.cpp:240 (15)
    //         004ca641     MOV        EBX,dword ptr [ESP + param_2]
    //         004ca645     CMP        BL,0x65
    //         004ca648     JNZ        LAB_004ca6e6
    //         004ca64e     PUSH       EDI
    //         004ca64f     PUSH       ESI
    //                              t_c_obj.cpp:267 (165)
    //         004ca650     MOV        ESI,0x70
    //         004ca655     MOV        EDX,0x6a
    //                               LAB_004ca65a                                                 XREF[1]:     004ca6de(j)  
    //         004ca65a     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004ca65d     CMP        word ptr [EDX + EDI*0x1],0x4
    //         004ca662     JNZ        LAB_004ca683
    //         004ca664     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca667     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca66a     FLD        float ptr [EAX + 0x10]
    //         004ca66d     FSUB       float ptr [ESI + EDI*0x1]
    //         004ca670     FSTP       float ptr [EAX + 0x10]
    //         004ca673     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca676     FLD        float ptr [ESP + param_1]
    //         004ca67a     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca67d     FADD       float ptr [EAX + 0x10]
    //         004ca680     FSTP       float ptr [EAX + 0x10]
    //                               LAB_004ca683                                                 XREF[1]:     004ca662(j)  
    //         004ca683     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004ca686     CMP        word ptr [EDX + EDI*0x1],0xb
    //         004ca68b     JNZ        LAB_004ca6ac
    //         004ca68d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca690     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca693     FLD        float ptr [EAX + 0x2c]
    //         004ca696     FSUB       float ptr [ESI + EDI*0x1]
    //         004ca699     FSTP       float ptr [EAX + 0x2c]
    //         004ca69c     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca69f     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca6a2     FLD        float ptr [EAX + 0x2c]
    //         004ca6a5     FSUB       float ptr [ESP + param_1]
    //         004ca6a9     FSTP       float ptr [EAX + 0x2c]
    //                               LAB_004ca6ac                                                 XREF[1]:     004ca68b(j)  
    //         004ca6ac     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004ca6af     CMP        word ptr [EDX + EDI*0x1],0x13
    //         004ca6b4     JNZ        LAB_004ca6d5
    //         004ca6b6     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca6b9     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca6bc     FLD        float ptr [EAX + 0x4c]
    //         004ca6bf     FSUB       float ptr [ESI + EDI*0x1]
    //         004ca6c2     FSTP       float ptr [EAX + 0x4c]
    //         004ca6c5     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca6c8     MOV        EAX,dword ptr [EAX + 0x50]
    //         004ca6cb     FLD        float ptr [EAX + 0x4c]
    //         004ca6ce     FSUB       float ptr [ESP + param_1]
    //         004ca6d2     FSTP       float ptr [EAX + 0x4c]
    //                               LAB_004ca6d5                                                 XREF[1]:     004ca6b4(j)  
    //         004ca6d5     ADD        EDX,0x2
    //         004ca6d8     ADD        ESI,0x4
    //         004ca6db     CMP        EDX,0x70
    //         004ca6de     JL         LAB_004ca65a
    //         004ca6e4     POP        ESI
    //         004ca6e5     POP        EDI
    //                               LAB_004ca6e6                                                 XREF[1]:     004ca648(j)  
    //         004ca6e6     MOV        EDX,dword ptr [ESP + param_1]
    //         004ca6ea     PUSH       EBX
    //         004ca6eb     PUSH       EDX
    //         004ca6ec     CALL       RGE_Static_Object::modify                        void modify(RGE_Static_Object * this, float p
    //         004ca6f1     POP        EBX
    //         004ca6f2     RET        0x8
    //         004ca6f5     ??         90h
    //         004ca6f6     NOP
    //         004ca6f7     NOP
    //         004ca6f8     NOP
    //         004ca6f9     NOP
    //         004ca6fa     NOP
    //         004ca6fb     NOP
    //         004ca6fc     NOP
    //         004ca6fd     NOP
    //         004ca6fe     NOP
    //         004ca6ff     NOP
    return;
}

void TRIBE_Combat_Object::transform(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall transform(TRIBE_Combat_Object * this, RGE_Master_Sta
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     004ca700(R)  
    //                               ?transform@TRIBE_Combat_Object@@UAEXPAVRGE_Master_Static_Ob  XREF[3]:     transform:004c8e99(c), 
    //                               TRIBE_Combat_Object::transform                                            005747cc(*), 00574a74(*)  
    //                              t_c_obj.cpp:273 (17)
    //         004ca700     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca704     PUSH       ESI
    //         004ca705     MOV        ESI,this
    //         004ca707     PUSH       EDI
    //         004ca708     PUSH       EAX
    //         004ca709     MOV        EDI,dword ptr [ESI + 0x8]
    //         004ca70c     CALL       RGE_Action_Object::transform                     void transform(RGE_Action_Object * this, RGE_
    //                              t_c_obj.cpp:278 (9)
    //         004ca711     CMP        byte ptr [ESI + 0x1c4],0x1
    //         004ca718     JNZ        LAB_004ca72d
    //                              t_c_obj.cpp:280 (12)
    //         004ca71a     TEST       EDI,EDI
    //         004ca71c     JZ         LAB_004ca726
    //         004ca71e     MOV        EDX,dword ptr [EDI]
    //         004ca720     PUSH       0x1
    //         004ca722     MOV        this,EDI
    //         004ca724     CALL       dword ptr [EDX]
    //                               LAB_004ca726                                                 XREF[1]:     004ca71c(j)  
    //                              t_c_obj.cpp:281 (7)
    //         004ca726     MOV        byte ptr [ESI + 0x1c4],0x0
    //                               LAB_004ca72d                                                 XREF[1]:     004ca718(j)  
    //                              t_c_obj.cpp:283 (5)
    //         004ca72d     POP        EDI
    //         004ca72e     POP        ESI
    //         004ca72f     RET        0x4
    //         004ca732     ??         90h
    //         004ca733     NOP
    //         004ca734     NOP
    //         004ca735     NOP
    //         004ca736     NOP
    //         004ca737     NOP
    //         004ca738     NOP
    //         004ca739     NOP
    //         004ca73a     NOP
    //         004ca73b     NOP
    //         004ca73c     NOP
    //         004ca73d     NOP
    //         004ca73e     NOP
    //         004ca73f     NOP
    return;
}

void TRIBE_Combat_Object::set_object_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_object_state(TRIBE_Combat_Object * this, uchar p
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ca74b(R)  
    //                               ?set_object_state@TRIBE_Combat_Object@@UAEXE@Z               XREF[1]:     00574a7c(*)  
    //                               TRIBE_Combat_Object::set_object_state
    //                              t_c_obj.cpp:289 (37)
    //         004ca740     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ca743     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004ca746     MOV        AL,byte ptr [EDX + 0x1d]
    //         004ca749     TEST       AL,AL
    //         004ca74b     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca74f     JNZ        LAB_004ca76d
    //         004ca751     CMP        AL,0x3
    //         004ca753     JC         LAB_004ca76d
    //         004ca755     CMP        byte ptr [ECX + this->_padding_],0x2
    //         004ca759     JA         LAB_004ca76d
    //         004ca75b     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ca75e     CMP        word ptr [EDX + 0x14],0x1
    //         004ca763     JNZ        LAB_004ca76d
    //                              t_c_obj.cpp:298 (5)
    //         004ca765     CALL       TRIBE_Combat_Object::reposition_artifact         void reposition_artifact(TRIBE_Combat_Object 
    //                              t_c_obj.cpp:303 (3)
    //         004ca76a     RET        0x4
    //                               LAB_004ca76d                                                 XREF[4]:     004ca74f(j), 004ca753(j), 
    //                                                                                                         004ca759(j), 004ca763(j)  
    //                              t_c_obj.cpp:302 (6)
    //         004ca76d     PUSH       EAX
    //         004ca76e     CALL       RGE_Static_Object::set_object_state              void set_object_state(RGE_Static_Object * thi
    //                              t_c_obj.cpp:303 (3)
    //         004ca773     RET        0x4
    //         004ca776     ??         90h
    //         004ca777     NOP
    //         004ca778     NOP
    //         004ca779     NOP
    //         004ca77a     NOP
    //         004ca77b     NOP
    //         004ca77c     NOP
    //         004ca77d     NOP
    //         004ca77e     NOP
    //         004ca77f     NOP
    return;
}

void TRIBE_Combat_Object::cancel_object() {
    /* TODO: Stub */
    //                              void __thiscall cancel_object(TRIBE_Combat_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //                               ?cancel_object@TRIBE_Combat_Object@@UAEXXZ                   XREF[2]:     cancel_object:004c948b(c), 
    //                               TRIBE_Combat_Object::cancel_object                                        00574c60(*)  
    //                              t_c_obj.cpp:307 (5)
    //         004ca780     MOV        EAX,dword ptr [this->_padding_]
    //         004ca782     JMP        dword ptr [EAX + 0x6c]
    //         004ca785     ??         90h
    //         004ca786     NOP
    //         004ca787     NOP
    //         004ca788     NOP
    //         004ca789     NOP
    //         004ca78a     NOP
    //         004ca78b     NOP
    //         004ca78c     NOP
    //         004ca78d     NOP
    //         004ca78e     NOP
    //         004ca78f     NOP
    return;
}

void TRIBE_Combat_Object::die_die_die() {
    /* TODO: Stub */
    //                              void __thiscall die_die_die(TRIBE_Combat_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //                               ?die_die_die@TRIBE_Combat_Object@@UAEXXZ                     XREF[2]:     005747e4(*), 00574a8c(*)  
    //                               TRIBE_Combat_Object::die_die_die
    //                              t_c_obj.cpp:313 (4)
    //         004ca790     PUSH       ESI
    //         004ca791     PUSH       EDI
    //         004ca792     MOV        EDI,this
    //                              t_c_obj.cpp:314 (31)
    //         004ca794     CMP        byte ptr [EDI + 0x48],0x2
    //         004ca798     JNZ        LAB_004ca7d8
    //         004ca79a     MOV        EAX,dword ptr [EDI + 0xc]
    //         004ca79d     MOV        this,dword ptr [EAX + 0x50]
    //         004ca7a0     FLD        float ptr [ECX + this->_padding_]
    //         004ca7a6     FCOMP      float ptr [DAT_00574c78]                         = align(2)
    //         004ca7ac     FNSTSW     AX
    //         004ca7ae     TEST       AH,0x1
    //         004ca7b1     JNZ        LAB_004ca7d8
    //                              t_c_obj.cpp:316 (13)
    //         004ca7b3     MOV        this,dword ptr [EDI + 0x184]
    //         004ca7b9     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004ca7be     MOV        ESI,EAX
    //                              t_c_obj.cpp:317 (17)
    //         004ca7c0     TEST       ESI,ESI
    //         004ca7c2     JZ         LAB_004ca7d8
    //         004ca7c4     MOV        EDX,dword ptr [ESI]
    //         004ca7c6     MOV        this,ESI
    //         004ca7c8     CALL       dword ptr [EDX + 0x18]
    //         004ca7cb     CMP        AX,0x68
    //         004ca7cf     JNZ        LAB_004ca7d8
    //                              t_c_obj.cpp:318 (7)
    //         004ca7d1     MOV        this,ESI
    //         004ca7d3     CALL       TRIBE_Action_Convert::martyrdom                  void martyrdom(TRIBE_Action_Convert * this)
    //                               LAB_004ca7d8                                                 XREF[4]:     004ca798(j), 004ca7b1(j), 
    //                                                                                                         004ca7c2(j), 004ca7cf(j)  
    //                              t_c_obj.cpp:321 (7)
    //         004ca7d8     MOV        this,EDI
    //         004ca7da     CALL       RGE_Static_Object::die_die_die                   void die_die_die(RGE_Static_Object * this)
    //                              t_c_obj.cpp:322 (3)
    //         004ca7df     POP        EDI
    //         004ca7e0     POP        ESI
    //         004ca7e1     RET
    //         004ca7e2     ??         90h
    //         004ca7e3     NOP
    //         004ca7e4     NOP
    //         004ca7e5     NOP
    //         004ca7e6     NOP
    //         004ca7e7     NOP
    //         004ca7e8     NOP
    //         004ca7e9     NOP
    //         004ca7ea     NOP
    //         004ca7eb     NOP
    //         004ca7ec     NOP
    //         004ca7ed     NOP
    //         004ca7ee     NOP
    //         004ca7ef     NOP
    //                              * public: virtual void __thiscall TRIBE_Combat_Object::damage(int,struct RGE_Armor_Weapon_Info *,flo... *
    //                              void __thiscall damage(TRIBE_Combat_Object * this, int param_1, RGE_
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ca822(R)  
    //              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[1]:     004ca81e(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004ca81a(R)  
    //              RGE_Player *      Stack[0x10]:4  param_4                   XREF[1]:     004ca816(R)  
    //              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     004ca812(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004ca803(W), 004ca866(R), 004ca87a(R)  
    //              float             Stack[-0x8]:4  temp_hp
    //                               ?damage@TRIBE_Combat_Object@@UAEXHPAURGE_Armor_Weapon_Info@  XREF[1]:     00574a90(*)  
    //                               TRIBE_Combat_Object::damage
    //                              t_c_obj.cpp:330 (7)
    //         004ca7f0     PUSH       this
    //         004ca7f1     PUSH       EBX
    //         004ca7f2     PUSH       EBP
    //         004ca7f3     PUSH       ESI
    //         004ca7f4     MOV        ESI,this
    //         004ca7f6     PUSH       EDI
    //                              t_c_obj.cpp:335 (27)
    //         004ca7f7     FLD        float ptr [ESI + 0x30]
    //         004ca7fa     FCOMP      double ptr [DAT_00574c88]
    //         004ca800     MOV        EAX,dword ptr [ESI + 0x30]
    //         004ca803     MOV        dword ptr [ESP + local_4],EAX
    //         004ca807     FNSTSW     AX
    //         004ca809     TEST       AH,0x1
    //         004ca80c     JNZ        LAB_004ca8b2
    //                              t_c_obj.cpp:339 (32)
    //         004ca812     MOV        EBX,dword ptr [ESP + param_5]
    //         004ca816     MOV        EBP,dword ptr [ESP + param_4]
    //         004ca81a     MOV        this,dword ptr [ESP + param_3]
    //         004ca81e     MOV        EDX,dword ptr [ESP + param_2]
    //         004ca822     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca826     PUSH       EBX
    //         004ca827     PUSH       EBP
    //         004ca828     PUSH       this
    //         004ca829     PUSH       EDX
    //         004ca82a     PUSH       EAX
    //         004ca82b     MOV        this,ESI
    //         004ca82d     CALL       RGE_Combat_Object::damage                        void damage(RGE_Combat_Object * this, int par
    //                              t_c_obj.cpp:343 (16)
    //         004ca832     FLD        float ptr [ESI + 0x30]
    //         004ca835     FCOMP      double ptr [DAT_00574c88]
    //         004ca83b     FNSTSW     AX
    //         004ca83d     TEST       AH,0x1
    //         004ca840     JZ         LAB_004ca866
    //                              t_c_obj.cpp:344 (22)
    //         004ca842     MOV        this,dword ptr [EBX + 0x8]
    //         004ca845     MOV        EDI,dword ptr [ESI]
    //         004ca847     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004ca84b     PUSH       EDX
    //         004ca84c     MOV        this,ESI
    //         004ca84e     CALL       dword ptr [EDI + 0x13c]
    //         004ca854     TEST       AL,AL
    //         004ca856     JNZ        LAB_004ca866
    //                              t_c_obj.cpp:349 (14)
    //         004ca858     PUSH       0x1
    //         004ca85a     PUSH       0x0=>DAT_fffffff8
    //         004ca85c     PUSH       0x0=>DAT_fffffff4
    //         004ca85e     MOV        this,ESI
    //         004ca860     CALL       dword ptr [EDI + 0x84]
    //                               LAB_004ca866                                                 XREF[2]:     004ca840(j), 004ca856(j)  
    //                              t_c_obj.cpp:354 (20)
    //         004ca866     FLD        float ptr [ESP + local_4]
    //         004ca86a     FSUB       float ptr [ESI + 0x30]
    //         004ca86d     FCOMP      double ptr [DAT_00574c88]
    //         004ca873     FNSTSW     AX
    //         004ca875     TEST       AH,0x1
    //         004ca878     JZ         LAB_004ca887
    //                              t_c_obj.cpp:355 (13)
    //         004ca87a     FLD        float ptr [ESP + local_4]
    //         004ca87e     FSUB       float ptr [DAT_00574c78]                         = align(2)
    //         004ca884     FSTP       float ptr [ESI + 0x30]
    //                               LAB_004ca887                                                 XREF[1]:     004ca878(j)  
    //                              t_c_obj.cpp:360 (26)
    //         004ca887     MOV        EAX,dword ptr [ESI + 0xc]
    //         004ca88a     CMP        word ptr [EAX + 0x4a],0x0
    //         004ca88f     JLE        LAB_004ca8b2
    //         004ca891     FLD        float ptr [ESI + 0x30]
    //         004ca894     FCOMP      float ptr [DAT_00574c78]                         = align(2)
    //         004ca89a     FNSTSW     AX
    //         004ca89c     TEST       AH,0x1
    //         004ca89f     JZ         LAB_004ca8b2
    //                              t_c_obj.cpp:361 (17)
    //         004ca8a1     MOV        EDX,dword ptr [EBP]
    //         004ca8a4     PUSH       0x0
    //         004ca8a6     PUSH       offset DAT_fffffff8
    //         004ca8ab     PUSH       offset DAT_fffffff4
    //         004ca8ad     MOV        this,EBP
    //         004ca8af     CALL       dword ptr [EDX + 0x78]
    //                               LAB_004ca8b2                                                 XREF[3]:     004ca80c(j), 004ca88f(j), 
    //                                                                                                         004ca89f(j)  
    //                              t_c_obj.cpp:362 (8)
    //         004ca8b2     POP        EDI
    //         004ca8b3     POP        ESI
    //         004ca8b4     POP        EBP
    //         004ca8b5     POP        EBX
    //         004ca8b6     POP        this
    //         004ca8b7     RET        0x14
    //         004ca8ba     ??         90h
    //         004ca8bb     NOP
    //         004ca8bc     NOP
    //         004ca8bd     NOP
    //         004ca8be     NOP
    //         004ca8bf     NOP
    return;
}

void TRIBE_Combat_Object::change_ownership(RGE_Player* param_1) {
    /* TODO: Stub */
    //                              void __thiscall change_ownership(TRIBE_Combat_Object * this, RGE_Pla
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     004ca8c5(R)  
    //                               ?change_ownership@TRIBE_Combat_Object@@MAEXPAVRGE_Player@@@Z XREF[2]:     change_ownership:004c8d90(c), 
    //                               TRIBE_Combat_Object::change_ownership                                     00574a64(*)  
    //                              t_c_obj.cpp:368 (5)
    //         004ca8c0     PUSH       EBP
    //         004ca8c1     PUSH       ESI
    //         004ca8c2     MOV        ESI,this
    //         004ca8c4     PUSH       EDI
    //                              t_c_obj.cpp:372 (11)
    //         004ca8c5     MOV        EDI,dword ptr [ESP + param_1]
    //         004ca8c9     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ca8cc     TEST       EAX,EAX
    //         004ca8ce     JL         LAB_004ca8ed
    //                              t_c_obj.cpp:424 (29)
    //         004ca8d0     LEA        this,[ESI + 0x194]
    //         004ca8d6     MOV        EBP,0x9
    //                               LAB_004ca8db                                                 XREF[1]:     004ca8eb(j)  
    //         004ca8db     MOV        EAX,dword ptr [this->_padding_]
    //         004ca8dd     TEST       EAX,EAX
    //         004ca8df     JZ         LAB_004ca8e7
    //         004ca8e1     MOV        DL,byte ptr [EDI + 0x4a]
    //         004ca8e4     MOV        byte ptr [EAX + 0x5],DL
    //                               LAB_004ca8e7                                                 XREF[1]:     004ca8df(j)  
    //         004ca8e7     ADD        this,0x4
    //         004ca8ea     DEC        EBP
    //         004ca8eb     JNZ        LAB_004ca8db
    //                               LAB_004ca8ed                                                 XREF[1]:     004ca8ce(j)  
    //                              t_c_obj.cpp:382 (10)
    //         004ca8ed     MOV        EAX,dword ptr [ESI + 0x8]
    //         004ca8f0     CMP        word ptr [EAX + 0x14],0x1
    //         004ca8f5     JNZ        LAB_004ca905
    //                              t_c_obj.cpp:384 (8)
    //         004ca8f7     PUSH       EDI
    //         004ca8f8     MOV        this,ESI
    //         004ca8fa     CALL       RGE_Action_Object::change_ownership              void change_ownership(RGE_Action_Object * thi
    //                              t_c_obj.cpp:424 (6)
    //         004ca8ff     POP        EDI
    //         004ca900     POP        ESI
    //         004ca901     POP        EBP
    //         004ca902     RET        0x4
    //                               LAB_004ca905                                                 XREF[1]:     004ca8f5(j)  
    //                              t_c_obj.cpp:388 (17)
    //         004ca905     MOVSX      EAX,word ptr [EAX + 0x10]
    //         004ca909     MOV        this,dword ptr [EDI + 0x24]
    //         004ca90c     CMP        dword ptr [this->_padding_ + EAX*0x4],0x0
    //         004ca910     JZ         LAB_004ca9ec
    //                              t_c_obj.cpp:390 (6)
    //         004ca916     TEST       byte ptr [ESI + 0x36],0x1
    //         004ca91a     JZ         LAB_004ca925
    //                              t_c_obj.cpp:391 (9)
    //         004ca91c     MOV        this,dword ptr [ESI + 0xc]
    //         004ca91f     PUSH       ESI
    //         004ca920     CALL       RGE_Player::unselect_one_object                  void unselect_one_object(RGE_Player * this, R
    //                               LAB_004ca925                                                 XREF[1]:     004ca91a(j)  
    //                              t_c_obj.cpp:393 (7)
    //         004ca925     MOV        this,ESI
    //         004ca927     CALL       RGE_Static_Object::take_attribute_from_owner     void take_attribute_from_owner(RGE_Static_Obj
    //                              t_c_obj.cpp:395 (28)
    //         004ca92c     MOV        EAX,dword ptr [ESI + 0x50]
    //         004ca92f     MOV        this,dword ptr [ESI + 0xc]
    //         004ca932     PUSH       EAX
    //         004ca933     XOR        EAX,EAX
    //         004ca935     MOV        AL,byte ptr [ESI + 0x4a]
    //         004ca938     MOV        EDX,dword ptr [this->_padding_]
    //         004ca93a     PUSH       EAX
    //         004ca93b     XOR        EAX,EAX
    //         004ca93d     MOV        AL,byte ptr [ESI + 0x49]
    //         004ca940     PUSH       EAX
    //         004ca941     PUSH       ESI
    //         004ca942     CALL       dword ptr [EDX + 0xe0]
    //                              t_c_obj.cpp:396 (26)
    //         004ca948     MOV        EDX,dword ptr [EDI]
    //         004ca94a     XOR        EAX,EAX
    //         004ca94c     MOV        AL,byte ptr [ESI + 0x4a]
    //         004ca94f     XOR        this,this
    //         004ca951     MOV        this,byte ptr [ESI + 0x49]
    //         004ca954     PUSH       EAX
    //         004ca955     PUSH       this=>DAT_fffffff8
    //         004ca956     PUSH       ESI=>DAT_fffffff4
    //         004ca957     MOV        this,EDI
    //         004ca959     CALL       dword ptr [EDX + 0xdc]
    //         004ca95f     MOV        dword ptr [ESI + 0x50],EAX
    //                              t_c_obj.cpp:400 (7)
    //         004ca962     MOV        AL,byte ptr [ESI + 0x48]
    //         004ca965     CMP        AL,0x2
    //         004ca967     JNZ        LAB_004ca97b
    //                              t_c_obj.cpp:401 (18)
    //         004ca969     MOV        EAX,dword ptr [ESI + 0xc]
    //         004ca96c     MOV        EDX,dword ptr [ESI]
    //         004ca96e     PUSH       -0x1
    //         004ca970     PUSH       0x0=>DAT_fffffff8
    //         004ca972     PUSH       EAX=>DAT_fffffff4
    //         004ca973     MOV        this,ESI
    //         004ca975     CALL       dword ptr [EDX + 0xdc]
    //                               LAB_004ca97b                                                 XREF[1]:     004ca967(j)  
    //                              t_c_obj.cpp:404 (13)
    //         004ca97b     MOV        AL,byte ptr [ESI + 0x1c4]
    //         004ca981     MOV        dword ptr [ESI + 0xc],EDI
    //         004ca984     TEST       AL,AL
    //         004ca986     JNZ        LAB_004ca99a
    //                              t_c_obj.cpp:407 (11)
    //         004ca988     MOV        this,dword ptr [ESI + 0x8]
    //         004ca98b     MOV        EDX,dword ptr [this->_padding_]
    //         004ca98d     CALL       dword ptr [EDX + 0x1c]
    //         004ca990     MOV        dword ptr [ESI + 0x8],EAX
    //                              t_c_obj.cpp:408 (7)
    //         004ca993     MOV        byte ptr [ESI + 0x1c4],0x1
    //                               LAB_004ca99a                                                 XREF[1]:     004ca986(j)  
    //                              t_c_obj.cpp:412 (6)
    //         004ca99a     CMP        byte ptr [ESI + 0x48],0x2
    //         004ca99e     JNZ        LAB_004ca9b2
    //                              t_c_obj.cpp:413 (18)
    //         004ca9a0     MOV        this,dword ptr [ESI + 0xc]
    //         004ca9a3     MOV        EAX,dword ptr [ESI]
    //         004ca9a5     PUSH       -0x1
    //         004ca9a7     PUSH       0x0=>DAT_fffffff8
    //         004ca9a9     PUSH       this=>DAT_fffffff4
    //         004ca9aa     MOV        this,ESI
    //         004ca9ac     CALL       dword ptr [EAX + 0xd8]
    //                               LAB_004ca9b2                                                 XREF[1]:     004ca99e(j)  
    //                              t_c_obj.cpp:415 (7)
    //         004ca9b2     MOV        this,ESI
    //         004ca9b4     CALL       RGE_Static_Object::give_attribute_to_owner       void give_attribute_to_owner(RGE_Static_Objec
    //                              t_c_obj.cpp:420 (7)
    //         004ca9b9     MOV        this,dword ptr [ESI + 0x74]
    //         004ca9bc     TEST       this,this
    //         004ca9be     JZ         LAB_004ca9cf
    //                              t_c_obj.cpp:421 (15)
    //         004ca9c0     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ca9c3     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004ca9c6     MOV        EDX,dword ptr [EAX + 0x4]
    //         004ca9c9     PUSH       EDX
    //         004ca9ca     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                               LAB_004ca9cf                                                 XREF[1]:     004ca9be(j)  
    //                              t_c_obj.cpp:422 (29)
    //         004ca9cf     MOVSX      this,word ptr [EDI + 0x4a]
    //         004ca9d3     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ca9d6     MOV        EDX,dword ptr [ESI]
    //         004ca9d8     PUSH       0x0
    //         004ca9da     PUSH       0x0=>DAT_fffffff8
    //         004ca9dc     PUSH       this=>DAT_fffffff4
    //         004ca9dd     PUSH       offset DAT_fffffff0
    //         004ca9e2     PUSH       EAX
    //         004ca9e3     PUSH       EAX
    //         004ca9e4     MOV        this,ESI
    //         004ca9e6     CALL       dword ptr [EDX + 0x148]
    //                               LAB_004ca9ec                                                 XREF[1]:     004ca910(j)  
    //                              t_c_obj.cpp:424 (6)
    //         004ca9ec     POP        EDI
    //         004ca9ed     POP        ESI
    //         004ca9ee     POP        EBP
    //         004ca9ef     RET        0x4
    //         004ca9f2     ??         90h
    //         004ca9f3     NOP
    //         004ca9f4     NOP
    //         004ca9f5     NOP
    //         004ca9f6     NOP
    //         004ca9f7     NOP
    //         004ca9f8     NOP
    //         004ca9f9     NOP
    //         004ca9fa     NOP
    //         004ca9fb     NOP
    //         004ca9fc     NOP
    //         004ca9fd     NOP
    //         004ca9fe     NOP
    //         004ca9ff     NOP
    return;
}

float TRIBE_Combat_Object::calc_attack_modifier(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              float __thiscall calc_attack_modifier(TRIBE_Combat_Object * this, RG
    //              float             ST0:10         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     004caa0d(R), 004caa2a(R)  
    //                               ?calc_attack_modifier@TRIBE_Combat_Object@@UAEMPAVRGE_Stati  XREF[2]:     00574868(*), 00574b10(*)  
    //                               TRIBE_Combat_Object::calc_attack_modifier
    //                              t_c_obj.cpp:430 (13)
    //         004caa00     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004caa03     CMP        word ptr [EAX + 0x124],0x0
    //         004caa0b     JL         LAB_004caa27
    //                              t_c_obj.cpp:464 (17)
    //         004caa0d     MOV        EAX,dword ptr [ESP + param_1]
    //         004caa11     MOV        EDX,dword ptr [this->_padding_]
    //         004caa13     PUSH       EAX
    //         004caa14     CALL       dword ptr [EDX + 0x24c]
    //         004caa1a     TEST       EAX,EAX
    //         004caa1c     JZ         LAB_004caa41
    //                              t_c_obj.cpp:465 (6)
    //         004caa1e     FLD        float ptr [DAT_00574c90]
    //                              t_c_obj.cpp:480 (3)
    //         004caa24     RET        0x4
    //                               LAB_004caa27                                                 XREF[1]:     004caa0b(j)  
    //                              t_c_obj.cpp:473 (17)
    //         004caa27     FLD        float ptr [ECX + this->_padding_]
    //         004caa2a     MOV        this,dword ptr [ESP + param_1]
    //         004caa2e     FCOMP      float ptr [ECX + this->_padding_]
    //         004caa31     FNSTSW     AX
    //         004caa33     TEST       AH,0x1
    //         004caa36     JZ         LAB_004caa41
    //                              t_c_obj.cpp:474 (6)
    //         004caa38     FLD        float ptr [DAT_00574c94]                         = 4Ch    L
    //                              t_c_obj.cpp:480 (3)
    //         004caa3e     RET        0x4
    //                               LAB_004caa41                                                 XREF[2]:     004caa1c(j), 004caa36(j)  
    //                              t_c_obj.cpp:476 (6)
    //         004caa41     FLD        float ptr [DAT_00574c78]                         = align(2)
    //                              t_c_obj.cpp:480 (3)
    //         004caa47     RET        0x4
    //         004caa4a     ??         90h
    //         004caa4b     NOP
    //         004caa4c     NOP
    //         004caa4d     NOP
    //         004caa4e     NOP
    //         004caa4f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_Combat_Object::attack(class RGE_Static_Object *,cla... *
    //                              uchar __thiscall attack(TRIBE_Combat_Object * this, RGE_Static_Objec
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004caa54(R)  
    //              RGE_Combat_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004caa8b(R)  
    //                               ?attack@TRIBE_Combat_Object@@UAEEPAVRGE_Static_Object@@PAVR  XREF[2]:     0057499c(*), 00574c44(*)  
    //                               TRIBE_Combat_Object::attack
    //                              t_c_obj.cpp:486 (4)
    //         004caa50     PUSH       ESI
    //         004caa51     MOV        ESI,this
    //         004caa53     PUSH       EDI
    //                              t_c_obj.cpp:489 (31)
    //         004caa54     MOV        EDI,dword ptr [ESP + param_1]
    //         004caa58     MOV        EAX,dword ptr [ESI + 0x8]
    //         004caa5b     CMP        word ptr [EAX + 0x124],0x0
    //         004caa63     JL         LAB_004caa8b
    //         004caa65     TEST       EDI,EDI
    //         004caa67     JZ         LAB_004caa8b
    //         004caa69     MOV        this,dword ptr [EDI + 0xc]
    //         004caa6c     CMP        word ptr [ECX + this+0x4a],0x0
    //         004caa71     JLE        LAB_004caa8b
    //                              t_c_obj.cpp:490 (24)
    //         004caa73     MOV        EAX,dword ptr [ESI + 0x40]
    //         004caa76     MOV        EDX,dword ptr [this->_padding_]
    //         004caa78     PUSH       0x0
    //         004caa7a     PUSH       EAX
    //         004caa7b     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004caa7e     PUSH       EAX
    //         004caa7f     MOV        EAX,dword ptr [ESI + 0x38]
    //         004caa82     PUSH       EAX
    //                              language.dll match for 0x70: "B"
    //         004caa83     PUSH       0x70
    //         004caa85     CALL       dword ptr [EDX + 0x94]
    //                               LAB_004caa8b                                                 XREF[3]:     004caa63(j), 004caa67(j), 
    //                                                                                                         004caa71(j)  
    //                              t_c_obj.cpp:492 (13)
    //         004caa8b     MOV        this,dword ptr [ESP + param_2]
    //         004caa8f     PUSH       this
    //         004caa90     PUSH       EDI=>DAT_fffffff8
    //         004caa91     MOV        this,ESI
    //         004caa93     CALL       RGE_Combat_Object::attack                        uchar attack(RGE_Combat_Object * this, RGE_St
    //                              t_c_obj.cpp:493 (5)
    //         004caa98     POP        EDI
    //         004caa99     POP        ESI
    //         004caa9a     RET        0x8
    //         004caa9d     ??         90h
    //         004caa9e     NOP
    //         004caa9f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_Combat_Object::do_attack(class RGE_Static_Object *,... *
    //                              uchar __thiscall do_attack(TRIBE_Combat_Object * this, RGE_Static_Ob
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004caaa4(R)  
    //              RGE_Combat_Obj    Stack[0x8]:4   param_2                   XREF[2]:     004cab39(R), 004cabf7(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     004cab45(R), 004cabf2(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     004cab41(R), 004cabee(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[2]:     004cab3d(R), 004cabea(R)  
    //                               ?do_attack@TRIBE_Combat_Object@@UAEEPAVRGE_Static_Object@@P  XREF[2]:     005749a0(*), 00574c48(*)  
    //                               TRIBE_Combat_Object::do_attack
    //                              t_c_obj.cpp:500 (4)
    //         004caaa0     PUSH       EBX
    //         004caaa1     PUSH       EBP
    //         004caaa2     PUSH       ESI
    //         004caaa3     PUSH       EDI
    //                              t_c_obj.cpp:503 (10)
    //         004caaa4     MOV        EDI,dword ptr [ESP + param_1]
    //         004caaa8     MOV        ESI,this
    //         004caaaa     TEST       EDI,EDI
    //         004caaac     JNZ        LAB_004caab7
    //                              t_c_obj.cpp:504 (2)
    //         004caaae     XOR        AL,AL
    //                              t_c_obj.cpp:542 (7)
    //         004caab0     POP        EDI
    //         004caab1     POP        ESI
    //         004caab2     POP        EBP
    //         004caab3     POP        EBX
    //         004caab4     RET        0x14
    //                               LAB_004caab7                                                 XREF[1]:     004caaac(j)  
    //                              t_c_obj.cpp:511 (34)
    //         004caab7     MOV        EAX,[rge_base_game]                              = 00000000
    //         004caabc     MOV        this,dword ptr [EAX + 0x9a8]
    //         004caac2     TEST       this,this
    //         004caac4     JZ         LAB_004cab08
    //         004caac6     MOV        this,dword ptr [ESI + 0x8]
    //         004caac9     MOV        AX,word ptr [ECX + this->_padding_]
    //         004caacd     CMP        AX,0x7a
    //         004caad1     JZ         LAB_004caad9
    //         004caad3     CMP        AX,0x7b
    //         004caad7     JNZ        LAB_004cab08
    //                               LAB_004caad9                                                 XREF[1]:     004caad1(j)  
    //                              t_c_obj.cpp:514 (31)
    //         004caad9     MOV        this,dword ptr [EDI + 0x4]
    //         004caadc     MOV        EAX,dword ptr [ESI + 0x4]
    //         004caadf     MOV        EDX,dword ptr [ESI]
    //         004caae1     PUSH       0x0
    //         004caae3     PUSH       this
    //         004caae4     PUSH       0x258
    //         004caae9     PUSH       0x200
    //         004caaee     PUSH       EAX
    //         004caaef     PUSH       EAX
    //         004caaf0     MOV        this,ESI
    //         004caaf2     CALL       dword ptr [EDX + 0x148]
    //                              t_c_obj.cpp:515 (7)
    //         004caaf8     MOV        EDX,dword ptr [EDI]
    //         004caafa     MOV        this,EDI
    //         004caafc     CALL       dword ptr [EDX + 0x6c]
    //                              t_c_obj.cpp:516 (2)
    //         004caaff     MOV        AL,0x1
    //                              t_c_obj.cpp:542 (7)
    //         004cab01     POP        EDI
    //         004cab02     POP        ESI
    //         004cab03     POP        EBP
    //         004cab04     POP        EBX
    //         004cab05     RET        0x14
    //                               LAB_004cab08                                                 XREF[2]:     004caac4(j), 004caad7(j)  
    //                              t_c_obj.cpp:521 (49)
    //         004cab08     MOV        this,dword ptr [ESI + 0x8]
    //         004cab0b     FLD        float ptr [ECX + this->_padding_]
    //         004cab11     FCOMP      float ptr [DAT_00574c98]
    //         004cab17     FNSTSW     AX
    //         004cab19     TEST       AH,0x41
    //         004cab1c     JNZ        LAB_004cabea
    //         004cab22     FLD        float ptr [ECX + this->_padding_]
    //         004cab28     FCOMP      float ptr [DAT_00574c9c]                         = A4h
    //         004cab2e     FNSTSW     AX
    //         004cab30     TEST       AH,0x1
    //         004cab33     JZ         LAB_004cabea
    //                              t_c_obj.cpp:523 (31)
    //         004cab39     MOV        EBP,dword ptr [ESP + param_2]
    //         004cab3d     MOV        EAX,dword ptr [ESP + param_5]
    //         004cab41     MOV        this,dword ptr [ESP + param_4]
    //         004cab45     MOV        EDX,dword ptr [ESP + param_3]
    //         004cab49     MOV        EBX,dword ptr [ESI]
    //         004cab4b     PUSH       EDI
    //         004cab4c     PUSH       EBP
    //         004cab4d     PUSH       EAX
    //         004cab4e     PUSH       this
    //         004cab4f     PUSH       EDX
    //         004cab50     MOV        this,ESI
    //         004cab52     CALL       dword ptr [EBX + 0x21c]
    //                              t_c_obj.cpp:526 (29)
    //         004cab58     MOV        this,dword ptr [EDI + 0x4]
    //         004cab5b     MOV        EAX,dword ptr [ESI + 0x4]
    //         004cab5e     PUSH       0x0
    //         004cab60     PUSH       this=>DAT_fffffff8
    //         004cab61     PUSH       offset DAT_fffffff4
    //         004cab66     PUSH       offset DAT_fffffff0
    //         004cab6b     PUSH       EAX
    //         004cab6c     PUSH       EAX
    //         004cab6d     MOV        this,ESI
    //         004cab6f     CALL       dword ptr [EBX + 0x148]
    //                              t_c_obj.cpp:529 (36)
    //         004cab75     PUSH       0x211
    //         004cab7a     PUSH       s_C:\msdev\work\age1_x1\t_c_obj.cp               = "C:\\msdev\\work\\age1_x1\\t_c_obj.cpp"
    //         004cab7f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004cab84     LEA        EAX,[EAX + EAX*0x4]
    //         004cab87     ADD        ESP,0x8
    //         004cab8a     LEA        this,[EAX + EAX*0x4]
    //         004cab8d     MOV        EAX,0x80010003
    //         004cab92     SHL        this,0x2
    //         004cab95     IMUL       this
    //         004cab97     ADD        EDX,this
    //                              t_c_obj.cpp:530 (24)
    //         004cab99     MOV        this,dword ptr [ESI + 0x8]
    //         004cab9c     SAR        EDX,0xe
    //         004cab9f     MOV        EAX,EDX
    //         004caba1     SHR        EAX,0x1f
    //         004caba4     ADD        EDX,EAX
    //         004caba6     MOVSX      EAX,word ptr [ECX + this+0x126]
    //         004cabad     CMP        EDX,EAX
    //         004cabaf     JG         LAB_004cabe1
    //                              t_c_obj.cpp:532 (9)
    //         004cabb1     PUSH       EDI
    //         004cabb2     MOV        this,ESI
    //         004cabb4     CALL       dword ptr [EBX + 0xf0]
    //                              t_c_obj.cpp:535 (39)
    //         004cabba     MOV        this,dword ptr [ESI + 0xc]
    //         004cabbd     MOV        EAX,dword ptr [ESI + 0x8]
    //         004cabc0     FSTP       float ptr [ESP + 0x24]
    //         004cabc4     PUSH       EBP
    //         004cabc5     MOV        EDX,dword ptr [EDI]
    //         004cabc7     PUSH       this=>DAT_fffffff8
    //         004cabc8     MOV        this,dword ptr [ESP + 0x2c]
    //         004cabcc     PUSH       this=>DAT_fffffff4
    //         004cabcd     MOV        this,dword ptr [EAX + 0x10c]
    //         004cabd3     MOVSX      EAX,word ptr [EAX + 0x108]
    //         004cabda     PUSH       this=>DAT_fffffff0
    //         004cabdb     PUSH       EAX
    //         004cabdc     MOV        this,EDI
    //         004cabde     CALL       dword ptr [EDX + 0x70]
    //                               LAB_004cabe1                                                 XREF[1]:     004cabaf(j)  
    //                              t_c_obj.cpp:538 (2)
    //         004cabe1     MOV        AL,0x1
    //                              t_c_obj.cpp:542 (7)
    //         004cabe3     POP        EDI
    //         004cabe4     POP        ESI
    //         004cabe5     POP        EBP
    //         004cabe6     POP        EBX
    //         004cabe7     RET        0x14
    //                               LAB_004cabea                                                 XREF[2]:     004cab1c(j), 004cab33(j)  
    //                              t_c_obj.cpp:541 (28)
    //         004cabea     MOV        this,dword ptr [ESP + param_5]
    //         004cabee     MOV        EDX,dword ptr [ESP + param_4]
    //         004cabf2     MOV        EAX,dword ptr [ESP + param_3]
    //         004cabf6     PUSH       this
    //         004cabf7     MOV        this,dword ptr [ESP + param_2]
    //         004cabfb     PUSH       EDX
    //         004cabfc     PUSH       EAX
    //         004cabfd     PUSH       this
    //         004cabfe     PUSH       EDI
    //         004cabff     MOV        this,ESI
    //         004cac01     CALL       RGE_Combat_Object::do_attack                     uchar do_attack(RGE_Combat_Object * this, RGE
    //                              t_c_obj.cpp:542 (7)
    //         004cac06     POP        EDI
    //         004cac07     POP        ESI
    //         004cac08     POP        EBP
    //         004cac09     POP        EBX
    //         004cac0a     RET        0x14
    //         004cac0d     ??         90h
    //         004cac0e     NOP
    //         004cac0f     NOP
    return 0;
}

void TRIBE_Combat_Object::get_armor(short* param_1, short* param_2) {
    /* TODO: Stub */
    //                              void __thiscall get_armor(TRIBE_Combat_Object * this, short * param_
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[1]:     004cac14(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[1]:     004cac61(R)  
    //                               ?get_armor@TRIBE_Combat_Object@@UAEXAAF0@Z                   XREF[2]:     005749a4(*), 00574c4c(*)  
    //                               TRIBE_Combat_Object::get_armor
    //                              t_c_obj.cpp:550 (19)
    //         004cac10     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cac13     PUSH       ESI
    //         004cac14     MOV        ESI,dword ptr [ESP + param_1]
    //         004cac18     MOVZX      DX,byte ptr [EAX + 0x100]
    //         004cac20     MOV        word ptr [ESI],DX
    //                              t_c_obj.cpp:554 (14)
    //         004cac23     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cac26     XOR        EDX,EDX
    //         004cac28     CMP        word ptr [EAX + 0x102],DX
    //         004cac2f     JLE        LAB_004cac5e
    //                              t_c_obj.cpp:550 (1)
    //         004cac31     PUSH       EDI
    //                               LAB_004cac32                                                 XREF[1]:     004cac5b(j)  
    //                              t_c_obj.cpp:554 (6)
    //         004cac32     MOV        EAX,dword ptr [EAX + 0x104]
    //                              t_c_obj.cpp:556 (19)
    //         004cac38     CMP        word ptr [EAX + EDX*0x4],0x4
    //         004cac3d     LEA        EAX,[EAX + EDX*0x4]
    //         004cac40     JNZ        LAB_004cac4e
    //         004cac42     MOV        AX,word ptr [EAX + 0x2]
    //         004cac46     CMP        AX,word ptr [ESI]
    //         004cac49     JLE        LAB_004cac4e
    //                              t_c_obj.cpp:557 (3)
    //         004cac4b     MOV        word ptr [ESI],AX
    //                               LAB_004cac4e                                                 XREF[2]:     004cac40(j), 004cac49(j)  
    //                              t_c_obj.cpp:554 (15)
    //         004cac4e     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cac51     INC        EDX
    //         004cac52     MOVSX      EDI,word ptr [EAX + 0x102]
    //         004cac59     CMP        EDX,EDI
    //         004cac5b     JL         LAB_004cac32
    //                              t_c_obj.cpp:550 (1)
    //         004cac5d     POP        EDI
    //                               LAB_004cac5e                                                 XREF[1]:     004cac2f(j)  
    //                              t_c_obj.cpp:560 (7)
    //         004cac5e     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cac61     MOV        EAX,dword ptr [ESP + param_2]
    //                              t_c_obj.cpp:561 (14)
    //         004cac65     POP        ESI
    //         004cac66     MOV        DX,word ptr [ECX + this->_padding_]
    //         004cac6d     MOV        word ptr [EAX],DX
    //         004cac70     RET        0x8
    //         004cac73     ??         90h
    //         004cac74     NOP
    //         004cac75     NOP
    //         004cac76     NOP
    //         004cac77     NOP
    //         004cac78     NOP
    //         004cac79     NOP
    //         004cac7a     NOP
    //         004cac7b     NOP
    //         004cac7c     NOP
    //         004cac7d     NOP
    //         004cac7e     NOP
    //         004cac7f     NOP
    return;
}

void TRIBE_Combat_Object::get_pierce_armor(short* param_1, short* param_2) {
    /* TODO: Stub */
    //                              void __thiscall get_pierce_armor(TRIBE_Combat_Object * this, short *
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[1]:     004cac81(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[1]:     004cacc8(R)  
    //                               ?get_pierce_armor@TRIBE_Combat_Object@@UAEXAAF0@Z            XREF[2]:     005749bc(*), 00574c64(*)  
    //                               TRIBE_Combat_Object::get_pierce_armor
    //                              t_c_obj.cpp:569 (1)
    //         004cac80     PUSH       ESI
    //                              t_c_obj.cpp:572 (4)
    //         004cac81     MOV        ESI,dword ptr [ESP + param_1]
    //                              t_c_obj.cpp:573 (19)
    //         004cac85     XOR        EDX,EDX
    //         004cac87     MOV        word ptr [ESI],0x0
    //         004cac8c     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cac8f     CMP        word ptr [EAX + 0x102],DX
    //         004cac96     JLE        LAB_004cacc5
    //                              t_c_obj.cpp:569 (1)
    //         004cac98     PUSH       EDI
    //                               LAB_004cac99                                                 XREF[1]:     004cacc2(j)  
    //                              t_c_obj.cpp:573 (6)
    //         004cac99     MOV        EAX,dword ptr [EAX + 0x104]
    //                              t_c_obj.cpp:575 (19)
    //         004cac9f     CMP        word ptr [EAX + EDX*0x4],0x3
    //         004caca4     LEA        EAX,[EAX + EDX*0x4]
    //         004caca7     JNZ        LAB_004cacb5
    //         004caca9     MOV        AX,word ptr [EAX + 0x2]
    //         004cacad     CMP        AX,word ptr [ESI]
    //         004cacb0     JLE        LAB_004cacb5
    //                              t_c_obj.cpp:576 (3)
    //         004cacb2     MOV        word ptr [ESI],AX
    //                               LAB_004cacb5                                                 XREF[2]:     004caca7(j), 004cacb0(j)  
    //                              t_c_obj.cpp:573 (15)
    //         004cacb5     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cacb8     INC        EDX
    //         004cacb9     MOVSX      EDI,word ptr [EAX + 0x102]
    //         004cacc0     CMP        EDX,EDI
    //         004cacc2     JL         LAB_004cac99
    //                              t_c_obj.cpp:569 (1)
    //         004cacc4     POP        EDI
    //                               LAB_004cacc5                                                 XREF[1]:     004cac96(j)  
    //                              t_c_obj.cpp:579 (7)
    //         004cacc5     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cacc8     MOV        EAX,dword ptr [ESP + param_2]
    //                              t_c_obj.cpp:580 (14)
    //         004caccc     POP        ESI
    //         004caccd     MOV        DX,word ptr [ECX + this->_padding_]
    //         004cacd4     MOV        word ptr [EAX],DX
    //         004cacd7     RET        0x8
    //         004cacda     ??         90h
    //         004cacdb     NOP
    //         004cacdc     NOP
    //         004cacdd     NOP
    //         004cacde     NOP
    //         004cacdf     NOP
    return;
}

void TRIBE_Combat_Object::reposition_artifact() {
    /* TODO: Stub */
    //                              void __thiscall reposition_artifact(TRIBE_Combat_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cad6d(W)  
    //              int               Stack[-0x8]:4  map_max_y                 XREF[1]:     004cad65(W)  
    //              int               Stack[-0xc]:4  map_max_x                 XREF[2]:     004cad81(W), 004cad9c(R)  
    //              int               Stack[-0x10]:4 x                         XREF[1]:     004cad56(W)  
    //              int               Stack[-0x14]:4 found_pos                 XREF[2]:     004cad4f(W), 004cade0(R)  
    //              int               Stack[-0x18]:4 y2                        XREF[4]:     004cacfb(W), 004cad25(W), 004cad47(R), 004cad77(R)  
    //              int               Stack[-0x1c]:4 x1                        XREF[2]:     004cad4b(W), 004cad7b(R)  
    //              int               Stack[-0x20]:4 x2                        XREF[4]:     004cad0c(W), 004cad31(W), 004cad38(R), 004cadbd(R)  
    //              int               Stack[-0x24]:4 y1                        XREF[4]:     004cad10(W), 004cad3c(W), 004cadb9(W), 004cadd0(R)  
    //              float             Stack[-0x28]:4 x_pos                     XREF[4]:     004cad14(W), 004cad40(W), 004cadc7(W), 004cadcb(R)  
    //              float             Stack[-0x2c]:4 y_pos
    //                               ?reposition_artifact@TRIBE_Combat_Object@@QAEXXZ             XREF[1]:     set_object_state:004ca765(c)  
    //                               TRIBE_Combat_Object::reposition_artifact
    //                              t_c_obj.cpp:586 (9)
    //         004cace0     SUB        ESP,0x28
    //         004cace3     PUSH       EBX
    //         004cace4     PUSH       EBP
    //         004cace5     PUSH       ESI
    //         004cace6     MOV        ESI,this
    //         004cace8     PUSH       EDI
    //                              t_c_obj.cpp:608 (7)
    //         004cace9     MOV        EDI,dword ptr [ESI + 0x20]
    //         004cacec     TEST       EDI,EDI
    //         004cacee     JZ         LAB_004cad1a
    //                              t_c_obj.cpp:610 (8)
    //         004cacf0     FLD        float ptr [EDI + 0x38]
    //         004cacf3     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:611 (12)
    //         004cacf8     FLD        float ptr [EDI + 0x3c]
    //         004cacfb     MOV        dword ptr [ESP + y2],EAX
    //         004cacff     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:613 (20)
    //         004cad04     MOV        this,dword ptr [EDI + 0x3c]
    //         004cad07     MOV        EBP,EAX
    //         004cad09     MOV        EAX,dword ptr [EDI + 0x38]
    //         004cad0c     MOV        dword ptr [ESP + x2],EBP
    //         004cad10     MOV        dword ptr [ESP + y1],EAX
    //         004cad14     MOV        dword ptr [ESP + x_pos],this
    //                              t_c_obj.cpp:615 (2)
    //         004cad18     JMP        LAB_004cad44
    //                               LAB_004cad1a                                                 XREF[1]:     004cacee(j)  
    //                              t_c_obj.cpp:617 (8)
    //         004cad1a     FLD        float ptr [ESI + 0x38]
    //         004cad1d     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:618 (12)
    //         004cad22     FLD        float ptr [ESI + 0x3c]
    //         004cad25     MOV        dword ptr [ESP + y2],EAX
    //         004cad29     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:619 (7)
    //         004cad2e     MOV        EDX,dword ptr [ESI + 0x38]
    //         004cad31     MOV        dword ptr [ESP + x2],EAX
    //                              t_c_obj.cpp:620 (15)
    //         004cad35     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cad38     MOV        EBP,dword ptr [ESP + x2]
    //         004cad3c     MOV        dword ptr [ESP + y1],EDX
    //         004cad40     MOV        dword ptr [ESP + x_pos],EAX
    //                               LAB_004cad44                                                 XREF[1]:     004cad18(j)  
    //                              t_c_obj.cpp:627 (18)
    //         004cad44     MOV        EDX,dword ptr [ESI + 0xc]
    //         004cad47     MOV        this,dword ptr [ESP + y2]
    //         004cad4b     MOV        dword ptr [ESP + x1],this
    //         004cad4f     MOV        dword ptr [ESP + found_pos],EBP
    //         004cad53     MOV        EAX,dword ptr [EDX + 0x3c]
    //                              t_c_obj.cpp:631 (27)
    //         004cad56     MOV        dword ptr [ESP + x],0x0
    //         004cad5e     MOV        EBX,dword ptr [EAX + 0x28]
    //         004cad61     MOV        EAX,dword ptr [EBX + 0x8]
    //         004cad64     DEC        EAX
    //         004cad65     MOV        dword ptr [ESP + map_max_y],EAX
    //         004cad69     MOV        EAX,dword ptr [EBX + 0xc]
    //         004cad6c     DEC        EAX
    //         004cad6d     MOV        dword ptr [ESP + local_4],EAX
    //                              t_c_obj.cpp:633 (6)
    //         004cad71     JMP        LAB_004cad77
    //                               LAB_004cad73                                                 XREF[2]:     004cafa4(j), 004cafaf(j)  
    //         004cad73     MOV        EBP,dword ptr [ESP + 0x18]
    //                               LAB_004cad77                                                 XREF[1]:     004cad71(j)  
    //                              t_c_obj.cpp:636 (20)
    //         004cad77     MOV        EDI,dword ptr [ESP + y2]
    //         004cad7b     MOV        EAX,dword ptr [ESP + x1]
    //         004cad7f     CMP        EDI,EAX
    //         004cad81     MOV        dword ptr [ESP + map_max_x],EDI
    //         004cad85     JG         LAB_004cae54
    //                               LAB_004cad8b                                                 XREF[1]:     004cae44(j)  
    //                              t_c_obj.cpp:638 (9)
    //         004cad8b     PUSH       EBP
    //         004cad8c     PUSH       EDI=>DAT_fffffff8
    //         004cad8d     MOV        this,EBX
    //         004cad8f     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              t_c_obj.cpp:639 (8)
    //         004cad94     CMP        AL,0x1
    //         004cad96     JZ         LAB_004cade0
    //         004cad98     CMP        AL,0x2
    //         004cad9a     JZ         LAB_004cade0
    //                              t_c_obj.cpp:641 (4)
    //         004cad9c     FILD       dword ptr [ESP + map_max_x]
    //                              t_c_obj.cpp:643 (64)
    //         004cada0     PUSH       0x1
    //         004cada2     MOV        this,dword ptr [ESI + 0x8]
    //         004cada5     PUSH       0x1
    //         004cada7     PUSH       0x0
    //         004cada9     FSUB       float ptr [DAT_00574ca0]
    //         004cadaf     PUSH       0x1
    //         004cadb1     MOV        EDX,dword ptr [this->_padding_]
    //         004cadb3     PUSH       0x1
    //         004cadb5     PUSH       0x1
    //         004cadb7     PUSH       0x0
    //         004cadb9     FSTP       float ptr [ESP + y1]
    //         004cadbd     FILD       dword ptr [ESP + x2]
    //         004cadc1     FSUB       float ptr [DAT_00574ca0]
    //         004cadc7     FSTP       float ptr [ESP + x_pos]
    //         004cadcb     MOV        EAX,dword ptr [ESP + x_pos]
    //         004cadcf     PUSH       EAX
    //         004cadd0     MOV        EAX,dword ptr [ESP + y1]
    //         004cadd4     PUSH       EAX
    //         004cadd5     MOV        EAX,dword ptr [ESI + 0xc]
    //         004cadd8     PUSH       EAX
    //         004cadd9     CALL       dword ptr [EDX + 0x20]
    //         004caddc     TEST       AL,AL
    //         004cadde     JZ         LAB_004cae4c
    //                               LAB_004cade0                                                 XREF[2]:     004cad96(j), 004cad9a(j)  
    //                              t_c_obj.cpp:649 (13)
    //         004cade0     MOV        this,dword ptr [ESP + found_pos]
    //         004cade4     PUSH       this
    //         004cade5     PUSH       EDI=>DAT_fffffff8
    //         004cade6     MOV        this,EBX
    //         004cade8     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              t_c_obj.cpp:650 (8)
    //         004caded     CMP        AL,0x1
    //         004cadef     JZ         LAB_004cae39
    //         004cadf1     CMP        AL,0x2
    //         004cadf3     JZ         LAB_004cae39
    //                              t_c_obj.cpp:652 (4)
    //         004cadf5     FILD       dword ptr [ESP + 0x2c]
    //                              t_c_obj.cpp:654 (64)
    //         004cadf9     PUSH       0x1
    //         004cadfb     MOV        this,dword ptr [ESI + 0x8]
    //         004cadfe     PUSH       offset DAT_fffffff8
    //         004cae00     PUSH       0x0=>DAT_fffffff4
    //         004cae02     FSUB       float ptr [DAT_00574ca0]
    //         004cae08     PUSH       offset DAT_fffffff0
    //         004cae0a     MOV        EDX,dword ptr [this->_padding_]
    //         004cae0c     PUSH       0x1
    //         004cae0e     PUSH       0x1
    //         004cae10     PUSH       0x0
    //         004cae12     FSTP       float ptr [ESP + 0x30]
    //         004cae16     FILD       dword ptr [ESP + 0x40]
    //         004cae1a     FSUB       float ptr [DAT_00574ca0]
    //         004cae20     FSTP       float ptr [ESP + 0x2c]
    //         004cae24     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004cae28     PUSH       EAX
    //         004cae29     MOV        EAX,dword ptr [ESP + 0x34]
    //         004cae2d     PUSH       EAX
    //         004cae2e     MOV        EAX,dword ptr [ESI + 0xc]
    //         004cae31     PUSH       EAX
    //         004cae32     CALL       dword ptr [EDX + 0x20]
    //         004cae35     TEST       AL,AL
    //         004cae37     JZ         LAB_004cae4c
    //                               LAB_004cae39                                                 XREF[2]:     004cadef(j), 004cadf3(j)  
    //                              t_c_obj.cpp:636 (19)
    //         004cae39     MOV        EAX,dword ptr [ESP + 0x1c]
    //         004cae3d     INC        EDI
    //         004cae3e     CMP        EDI,EAX
    //         004cae40     MOV        dword ptr [ESP + 0x2c],EDI
    //         004cae44     JLE        LAB_004cad8b
    //         004cae4a     JMP        LAB_004cae54
    //                               LAB_004cae4c                                                 XREF[2]:     004cadde(j), 004cae37(j)  
    //                              t_c_obj.cpp:656 (8)
    //         004cae4c     MOV        dword ptr [ESP + 0x28],0x1
    //                               LAB_004cae54                                                 XREF[2]:     004cad85(j), 004cae4a(j)  
    //                              t_c_obj.cpp:662 (12)
    //         004cae54     MOV        EAX,dword ptr [ESP + 0x28]
    //         004cae58     TEST       EAX,EAX
    //         004cae5a     JNZ        LAB_004cafd9
    //                              t_c_obj.cpp:666 (22)
    //         004cae60     MOV        this,dword ptr [ESP + 0x24]
    //         004cae64     LEA        EDI,[EBP + 0x1]
    //         004cae67     MOV        dword ptr [ESP + 0x2c],EDI
    //         004cae6b     LEA        EBP,[this->_padding_ + -0x1]
    //         004cae6e     CMP        EDI,EBP
    //         004cae70     JG         LAB_004caf3f
    //                               LAB_004cae76                                                 XREF[1]:     004caf2f(j)  
    //                              t_c_obj.cpp:668 (13)
    //         004cae76     MOV        EDX,dword ptr [ESP + 0x20]
    //         004cae7a     PUSH       EDI
    //         004cae7b     PUSH       EDX=>DAT_fffffff8
    //         004cae7c     MOV        this,EBX
    //         004cae7e     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              t_c_obj.cpp:669 (8)
    //         004cae83     CMP        AL,0x1
    //         004cae85     JZ         LAB_004caecf
    //         004cae87     CMP        AL,0x2
    //         004cae89     JZ         LAB_004caecf
    //                              t_c_obj.cpp:671 (4)
    //         004cae8b     FILD       dword ptr [ESP + 0x20]
    //                              t_c_obj.cpp:673 (64)
    //         004cae8f     PUSH       0x1
    //         004cae91     MOV        this,dword ptr [ESI + 0x8]
    //         004cae94     PUSH       offset DAT_fffffff8
    //         004cae96     PUSH       0x0=>DAT_fffffff4
    //         004cae98     FSUB       float ptr [DAT_00574ca0]
    //         004cae9e     PUSH       offset DAT_fffffff0
    //         004caea0     MOV        EAX,dword ptr [this->_padding_]
    //         004caea2     PUSH       0x1
    //         004caea4     PUSH       0x1
    //         004caea6     PUSH       0x0
    //         004caea8     FSTP       float ptr [ESP + 0x30]
    //         004caeac     FILD       dword ptr [ESP + 0x48]
    //         004caeb0     FSUB       float ptr [DAT_00574ca0]
    //         004caeb6     FSTP       float ptr [ESP + 0x2c]
    //         004caeba     MOV        EDX,dword ptr [ESP + 0x2c]
    //         004caebe     PUSH       EDX
    //         004caebf     MOV        EDX,dword ptr [ESP + 0x34]
    //         004caec3     PUSH       EDX
    //         004caec4     MOV        EDX,dword ptr [ESI + 0xc]
    //         004caec7     PUSH       EDX
    //         004caec8     CALL       dword ptr [EAX + 0x20]
    //         004caecb     TEST       AL,AL
    //         004caecd     JZ         LAB_004caf37
    //                               LAB_004caecf                                                 XREF[2]:     004cae85(j), 004cae89(j)  
    //                              t_c_obj.cpp:679 (13)
    //         004caecf     MOV        EAX,dword ptr [ESP + 0x1c]
    //         004caed3     PUSH       EDI
    //         004caed4     PUSH       EAX=>DAT_fffffff8
    //         004caed5     MOV        this,EBX
    //         004caed7     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              t_c_obj.cpp:680 (8)
    //         004caedc     CMP        AL,0x1
    //         004caede     JZ         LAB_004caf28
    //         004caee0     CMP        AL,0x2
    //         004caee2     JZ         LAB_004caf28
    //                              t_c_obj.cpp:682 (4)
    //         004caee4     FILD       dword ptr [ESP + 0x1c]
    //                              t_c_obj.cpp:684 (64)
    //         004caee8     PUSH       0x1
    //         004caeea     MOV        this,dword ptr [ESI + 0x8]
    //         004caeed     PUSH       offset DAT_fffffff8
    //         004caeef     PUSH       0x0=>DAT_fffffff4
    //         004caef1     FSUB       float ptr [DAT_00574ca0]
    //         004caef7     PUSH       offset DAT_fffffff0
    //         004caef9     MOV        EDX,dword ptr [this->_padding_]
    //         004caefb     PUSH       0x1
    //         004caefd     PUSH       0x0
    //         004caeff     PUSH       0x0
    //         004caf01     FSTP       float ptr [ESP + 0x30]
    //         004caf05     FILD       dword ptr [ESP + 0x48]
    //         004caf09     FSUB       float ptr [DAT_00574ca0]
    //         004caf0f     FSTP       float ptr [ESP + 0x2c]
    //         004caf13     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004caf17     PUSH       EAX
    //         004caf18     MOV        EAX,dword ptr [ESP + 0x34]
    //         004caf1c     PUSH       EAX
    //         004caf1d     MOV        EAX,dword ptr [ESI + 0xc]
    //         004caf20     PUSH       EAX
    //         004caf21     CALL       dword ptr [EDX + 0x20]
    //         004caf24     TEST       AL,AL
    //         004caf26     JZ         LAB_004caf37
    //                               LAB_004caf28                                                 XREF[2]:     004caede(j), 004caee2(j)  
    //                              t_c_obj.cpp:666 (15)
    //         004caf28     INC        EDI
    //         004caf29     CMP        EDI,EBP
    //         004caf2b     MOV        dword ptr [ESP + 0x2c],EDI
    //         004caf2f     JLE        LAB_004cae76
    //         004caf35     JMP        LAB_004caf3f
    //                               LAB_004caf37                                                 XREF[2]:     004caecd(j), 004caf26(j)  
    //                              t_c_obj.cpp:686 (8)
    //         004caf37     MOV        dword ptr [ESP + 0x28],0x1
    //                               LAB_004caf3f                                                 XREF[2]:     004cae70(j), 004caf35(j)  
    //                              t_c_obj.cpp:692 (12)
    //         004caf3f     MOV        EAX,dword ptr [ESP + 0x28]
    //         004caf43     TEST       EAX,EAX
    //         004caf45     JNZ        LAB_004cafd9
    //                              t_c_obj.cpp:697 (40)
    //         004caf4b     MOV        EAX,dword ptr [ESP + 0x20]
    //         004caf4f     TEST       EAX,EAX
    //         004caf51     JNZ        LAB_004caf75
    //         004caf53     MOV        this,dword ptr [ESP + 0x1c]
    //         004caf57     MOV        EDX,dword ptr [ESP + 0x30]
    //         004caf5b     CMP        this,EDX
    //         004caf5d     JNZ        LAB_004caf73
    //         004caf5f     MOV        this,dword ptr [ESP + 0x18]
    //         004caf63     TEST       this,this
    //         004caf65     JNZ        LAB_004caf73
    //         004caf67     MOV        EDX,dword ptr [ESP + 0x24]
    //         004caf6b     MOV        this,dword ptr [ESP + 0x34]
    //         004caf6f     CMP        EDX,this
    //         004caf71     JZ         LAB_004cafb4
    //                               LAB_004caf73                                                 XREF[2]:     004caf5d(j), 004caf65(j)  
    //                              t_c_obj.cpp:713 (4)
    //         004caf73     TEST       EAX,EAX
    //                               LAB_004caf75                                                 XREF[1]:     004caf51(j)  
    //         004caf75     JLE        LAB_004caf7c
    //                              t_c_obj.cpp:714 (5)
    //         004caf77     DEC        EAX
    //         004caf78     MOV        dword ptr [ESP + 0x20],EAX
    //                               LAB_004caf7c                                                 XREF[1]:     004caf75(j)  
    //                              t_c_obj.cpp:715 (8)
    //         004caf7c     MOV        EAX,dword ptr [ESP + 0x18]
    //         004caf80     TEST       EAX,EAX
    //         004caf82     JLE        LAB_004caf89
    //                              t_c_obj.cpp:716 (5)
    //         004caf84     DEC        EAX
    //         004caf85     MOV        dword ptr [ESP + 0x18],EAX
    //                               LAB_004caf89                                                 XREF[1]:     004caf82(j)  
    //                              t_c_obj.cpp:717 (12)
    //         004caf89     MOV        EAX,dword ptr [ESP + 0x1c]
    //         004caf8d     MOV        this,dword ptr [ESP + 0x30]
    //         004caf91     CMP        EAX,this
    //         004caf93     JGE        LAB_004caf9a
    //                              t_c_obj.cpp:718 (5)
    //         004caf95     INC        EAX
    //         004caf96     MOV        dword ptr [ESP + 0x1c],EAX
    //                               LAB_004caf9a                                                 XREF[1]:     004caf93(j)  
    //                              t_c_obj.cpp:719 (16)
    //         004caf9a     MOV        this,dword ptr [ESP + 0x34]
    //         004caf9e     MOV        EAX,dword ptr [ESP + 0x24]
    //         004cafa2     CMP        EAX,this
    //         004cafa4     JGE        LAB_004cad73
    //                              t_c_obj.cpp:720 (10)
    //         004cafaa     INC        EAX
    //         004cafab     MOV        dword ptr [ESP + 0x24],EAX
    //         004cafaf     JMP        LAB_004cad73
    //                               LAB_004cafb4                                                 XREF[1]:     004caf71(j)  
    //                              t_c_obj.cpp:699 (7)
    //         004cafb4     MOV        EAX,dword ptr [ESI + 0x20]
    //         004cafb7     TEST       EAX,EAX
    //         004cafb9     JZ         LAB_004cafcb
    //                              t_c_obj.cpp:701 (3)
    //         004cafbb     MOV        EDX,dword ptr [EAX + 0x38]
    //                              t_c_obj.cpp:702 (11)
    //         004cafbe     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004cafc1     MOV        dword ptr [ESP + 0x14],EDX
    //         004cafc5     MOV        dword ptr [ESP + 0x10],EAX
    //                              t_c_obj.cpp:704 (2)
    //         004cafc9     JMP        LAB_004cafd9
    //                               LAB_004cafcb                                                 XREF[1]:     004cafb9(j)  
    //                              t_c_obj.cpp:706 (3)
    //         004cafcb     MOV        this,dword ptr [ESI + 0x38]
    //                              t_c_obj.cpp:707 (11)
    //         004cafce     MOV        EDX,dword ptr [ESI + 0x3c]
    //         004cafd1     MOV        dword ptr [ESP + 0x14],this
    //         004cafd5     MOV        dword ptr [ESP + 0x10],EDX
    //                               LAB_004cafd9                                                 XREF[3]:     004cae5a(j), 004caf45(j), 
    //                                                                                                         004cafc9(j)  
    //                              t_c_obj.cpp:725 (21)
    //         004cafd9     MOV        EAX,dword ptr [ESI + 0x40]
    //         004cafdc     MOV        EBP,dword ptr [ESP + 0x10]
    //         004cafe0     MOV        EBX,dword ptr [ESP + 0x14]
    //         004cafe4     PUSH       EAX
    //         004cafe5     PUSH       EBP=>DAT_fffffff8
    //         004cafe6     PUSH       EBX=>DAT_fffffff4
    //         004cafe7     MOV        this,ESI
    //         004cafe9     CALL       RGE_Static_Object::set_location                  void set_location(RGE_Static_Object * this, f
    //                              t_c_obj.cpp:726 (7)
    //         004cafee     MOV        EAX,dword ptr [ESI + 0x20]
    //         004caff1     TEST       EAX,EAX
    //         004caff3     JZ         LAB_004cafff
    //                              t_c_obj.cpp:727 (10)
    //         004caff5     MOV        EDX,dword ptr [ESI]
    //         004caff7     MOV        this,ESI
    //         004caff9     CALL       dword ptr [EDX + 0xd4]
    //                               LAB_004cafff                                                 XREF[1]:     004caff3(j)  
    //                              t_c_obj.cpp:728 (13)
    //         004cafff     MOV        EAX,dword ptr [ESI + 0x40]
    //         004cb002     MOV        EDI,dword ptr [ESI]
    //         004cb004     PUSH       EAX
    //         004cb005     PUSH       EBP=>DAT_fffffff8
    //         004cb006     PUSH       EBX=>DAT_fffffff4
    //         004cb007     MOV        this,ESI
    //         004cb009     CALL       dword ptr [EDI + 0x34]
    //                              t_c_obj.cpp:729 (19)
    //         004cb00c     MOV        this,dword ptr [ESI + 0xc]
    //         004cb00f     FSTP       ST0
    //         004cb011     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004cb014     MOV        EAX,dword ptr [EDX + 0x40]
    //         004cb017     MOV        this,dword ptr [EAX]
    //         004cb019     PUSH       this
    //         004cb01a     MOV        this,ESI
    //         004cb01c     CALL       dword ptr [EDI + 0x44]
    //                              t_c_obj.cpp:730 (16)
    //         004cb01f     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb022     MOV        this,ESI
    //         004cb024     PUSH       EDX
    //         004cb025     PUSH       EBP=>DAT_fffffff8
    //         004cb026     PUSH       EBX=>DAT_fffffff4
    //         004cb027     PUSH       0x0=>DAT_fffffff0
    //         004cb029     CALL       dword ptr [EDI + 0x9c]
    //                              t_c_obj.cpp:731 (7)
    //         004cb02f     MOV        dword ptr [ESI + 0x30],0x3f800000
    //                              t_c_obj.cpp:732 (8)
    //         004cb036     POP        EDI
    //         004cb037     POP        ESI
    //         004cb038     POP        EBP
    //         004cb039     POP        EBX
    //         004cb03a     ADD        ESP,0x28
    //         004cb03d     RET
    //         004cb03e     ??         90h
    //         004cb03f     NOP
    return;
}

int TRIBE_Combat_Object::can_debark() {
    /* TODO: Stub */
    //                              int __thiscall can_debark(TRIBE_Combat_Object * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //                               ?can_debark@TRIBE_Combat_Object@@QAEHXZ
    //                               TRIBE_Combat_Object::can_debark
    //                              t_c_obj.cpp:740 (12)
    //         004cb040     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cb043     CMP        byte ptr [EAX + 0x8f],0x7
    //         004cb04a     JZ         LAB_004cb04f
    //                              t_c_obj.cpp:752 (2)
    //         004cb04c     XOR        EAX,EAX
    //                              t_c_obj.cpp:811 (1)
    //         004cb04e     RET
    //                               LAB_004cb04f                                                 XREF[1]:     004cb04a(j)  
    //                              t_c_obj.cpp:754 (12)
    //         004cb04f     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb052     XOR        EAX,EAX
    //         004cb054     CMP        word ptr [ECX + this->_padding_],AX
    //         004cb058     SETNZ      AL
    //                              t_c_obj.cpp:811 (1)
    //         004cb05b     RET
    //         004cb05c     ??         90h
    //         004cb05d     NOP
    //         004cb05e     NOP
    //         004cb05f     NOP
    return 0;
}

int TRIBE_Combat_Object::hunt(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall hunt(TRIBE_Combat_Object * this, int param_1, int par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb076(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb095(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb196(R)  
    //                               ?hunt@TRIBE_Combat_Object@@UAEHHH@Z                          XREF[2]:     005748dc(*), 00574b84(*)  
    //                               TRIBE_Combat_Object::hunt
    //                              t_c_obj.cpp:817 (22)
    //         004cb060     MOV        EAX,FS:[0x0]
    //         004cb066     PUSH       -0x1
    //         004cb068     PUSH       FUN_0055fbbb
    //         004cb06d     PUSH       EAX
    //         004cb06e     MOV        dword ptr FS:[0x0],ESP
    //         004cb075     PUSH       EBX
    //                              t_c_obj.cpp:818 (23)
    //         004cb076     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb07a     PUSH       EBP
    //         004cb07b     PUSH       ESI
    //         004cb07c     PUSH       EDI
    //         004cb07d     MOV        EDI,this
    //         004cb07f     PUSH       EAX
    //         004cb080     MOV        this,dword ptr [EDI + 0xc]
    //         004cb083     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb086     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb08b     MOV        ESI,EAX
    //                              t_c_obj.cpp:819 (8)
    //         004cb08d     TEST       ESI,ESI
    //         004cb08f     JZ         LAB_004cb196
    //                              t_c_obj.cpp:831 (67)
    //         004cb095     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb099     TEST       EAX,EAX
    //         004cb09b     JNZ        LAB_004cb0de
    //         004cb09d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb0a3     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb0a8     CMP        AL,0x1
    //         004cb0aa     JNZ        LAB_004cb0de
    //         004cb0ac     MOV        this,dword ptr [EDI + 0x184]
    //         004cb0b2     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb0b7     MOV        EDX,dword ptr [EAX]
    //         004cb0b9     MOV        this,EAX
    //         004cb0bb     CALL       dword ptr [EDX + 0x4c]
    //         004cb0be     CMP        EAX,ESI
    //         004cb0c0     JNZ        LAB_004cb0de
    //         004cb0c2     MOV        this,dword ptr [EDI + 0x184]
    //         004cb0c8     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb0cd     MOV        EDX,dword ptr [EAX]
    //         004cb0cf     MOV        this,EAX
    //         004cb0d1     CALL       dword ptr [EDX + 0x18]
    //         004cb0d4     CMP        AX,0x6e
    //                              t_c_obj.cpp:836 (6)
    //         004cb0d8     JZ         LAB_004cb191
    //                               LAB_004cb0de                                                 XREF[3]:     004cb09b(j), 004cb0aa(j), 
    //                                                                                                         004cb0c0(j)  
    //                              t_c_obj.cpp:842 (39)
    //         004cb0de     MOV        this,dword ptr [EDI + 0x184]
    //         004cb0e4     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb0e9     CMP        AL,0x1
    //         004cb0eb     JNZ        LAB_004cb126
    //         004cb0ed     MOV        this,dword ptr [EDI + 0x184]
    //         004cb0f3     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb0f8     MOV        EDX,dword ptr [EAX]
    //         004cb0fa     MOV        this,EAX
    //         004cb0fc     CALL       dword ptr [EDX + 0x18]
    //         004cb0ff     CMP        AX,0x6e
    //         004cb103     JNZ        LAB_004cb126
    //                              t_c_obj.cpp:845 (31)
    //         004cb105     MOV        this,dword ptr [EDI + 0x184]
    //         004cb10b     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb110     MOV        this,dword ptr [ESI + 0x40]
    //         004cb113     MOV        EDX,dword ptr [EAX]
    //         004cb115     PUSH       this
    //         004cb116     MOV        this,dword ptr [ESI + 0x3c]
    //         004cb119     PUSH       this=>DAT_fffffff8
    //         004cb11a     MOV        this,dword ptr [ESI + 0x38]
    //         004cb11d     PUSH       this=>DAT_fffffff4
    //         004cb11e     PUSH       ESI=>DAT_fffffff0
    //         004cb11f     MOV        this,EAX
    //         004cb121     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:846 (2)
    //         004cb124     JMP        LAB_004cb191
    //                               LAB_004cb126                                                 XREF[2]:     004cb0eb(j), 004cb103(j)  
    //                              t_c_obj.cpp:851 (25)
    //         004cb126     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb129     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cb12c     MOV        this,dword ptr [ESI + 0x38]
    //         004cb12f     MOV        EBP,dword ptr [EDI]
    //         004cb131     PUSH       EDX
    //         004cb132     PUSH       EAX=>DAT_fffffff8
    //         004cb133     PUSH       this=>DAT_fffffff4
    //         004cb134     PUSH       ESI=>DAT_fffffff0
    //         004cb135     MOV        this,EDI
    //         004cb137     CALL       dword ptr [EBP + 0x210]
    //         004cb13d     MOV        EBX,EAX
    //                              t_c_obj.cpp:852 (4)
    //         004cb13f     TEST       EBX,EBX
    //         004cb141     JZ         LAB_004cb196
    //                              t_c_obj.cpp:859 (42)
    //         004cb143     PUSH       0x44
    //         004cb145     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb14a     ADD        ESP,0x4
    //         004cb14d     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb151     TEST       EAX,EAX
    //         004cb153     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb15b     JZ         LAB_004cb16b
    //         004cb15d     PUSH       ESI
    //         004cb15e     PUSH       EBX=>DAT_fffffff8
    //         004cb15f     PUSH       EDI=>DAT_fffffff4
    //         004cb160     MOV        this,EAX
    //         004cb162     CALL       TRIBE_Action_Hunt::TRIBE_Action_Hunt             undefined TRIBE_Action_Hunt(TRIBE_Action_Hunt
    //         004cb167     MOV        ESI,EAX
    //         004cb169     JMP        LAB_004cb16d
    //                               LAB_004cb16b                                                 XREF[1]:     004cb15b(j)  
    //         004cb16b     XOR        ESI,ESI
    //                               LAB_004cb16d                                                 XREF[1]:     004cb169(j)  
    //                              t_c_obj.cpp:860 (12)
    //         004cb16d     TEST       ESI,ESI
    //         004cb16f     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb177     JNZ        LAB_004cb17d
    //                              t_c_obj.cpp:864 (4)
    //         004cb179     XOR        EAX,EAX
    //         004cb17b     JMP        LAB_004cb196
    //                               LAB_004cb17d                                                 XREF[1]:     004cb177(j)  
    //                              t_c_obj.cpp:866 (11)
    //         004cb17d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb183     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:867 (9)
    //         004cb188     PUSH       ESI
    //         004cb189     MOV        this,EDI
    //         004cb18b     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb191                                                 XREF[2]:     004cb0d8(j), 004cb124(j)  
    //                              t_c_obj.cpp:868 (5)
    //         004cb191     MOV        EAX,0x1
    //                               LAB_004cb196                                                 XREF[3]:     004cb08f(j), 004cb141(j), 
    //                                                                                                         004cb17b(j)  
    //                              t_c_obj.cpp:869 (21)
    //         004cb196     MOV        this,dword ptr [ESP + local_c]
    //         004cb19a     POP        EDI
    //         004cb19b     POP        ESI
    //         004cb19c     POP        EBP
    //         004cb19d     MOV        dword ptr FS:[0x0],this
    //         004cb1a4     POP        EBX
    //         004cb1a5     ADD        ESP,0xc
    //         004cb1a8     RET        0x8
    //         004cb1ab     ??         90h
    //         004cb1ac     NOP
    //         004cb1ad     NOP
    //         004cb1ae     NOP
    //         004cb1af     NOP
    return 0;
}

int TRIBE_Combat_Object::convert(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall convert(TRIBE_Combat_Object * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb1c6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb1e5(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb2e6(R)  
    //                               ?convert@TRIBE_Combat_Object@@UAEHHH@Z                       XREF[2]:     005748e4(*), 00574b8c(*)  
    //                               TRIBE_Combat_Object::convert
    //                              t_c_obj.cpp:875 (22)
    //         004cb1b0     MOV        EAX,FS:[0x0]
    //         004cb1b6     PUSH       -0x1
    //         004cb1b8     PUSH       FUN_0055fbdb
    //         004cb1bd     PUSH       EAX
    //         004cb1be     MOV        dword ptr FS:[0x0],ESP
    //         004cb1c5     PUSH       EBX
    //                              t_c_obj.cpp:876 (23)
    //         004cb1c6     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb1ca     PUSH       EBP
    //         004cb1cb     PUSH       ESI
    //         004cb1cc     PUSH       EDI
    //         004cb1cd     MOV        EDI,this
    //         004cb1cf     PUSH       EAX
    //         004cb1d0     MOV        this,dword ptr [EDI + 0xc]
    //         004cb1d3     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb1d6     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb1db     MOV        ESI,EAX
    //                              t_c_obj.cpp:877 (8)
    //         004cb1dd     TEST       ESI,ESI
    //         004cb1df     JZ         LAB_004cb2e6
    //                              t_c_obj.cpp:889 (67)
    //         004cb1e5     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb1e9     TEST       EAX,EAX
    //         004cb1eb     JNZ        LAB_004cb22e
    //         004cb1ed     MOV        this,dword ptr [EDI + 0x184]
    //         004cb1f3     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb1f8     CMP        AL,0x1
    //         004cb1fa     JNZ        LAB_004cb22e
    //         004cb1fc     MOV        this,dword ptr [EDI + 0x184]
    //         004cb202     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb207     MOV        EDX,dword ptr [EAX]
    //         004cb209     MOV        this,EAX
    //         004cb20b     CALL       dword ptr [EDX + 0x4c]
    //         004cb20e     CMP        EAX,ESI
    //         004cb210     JNZ        LAB_004cb22e
    //         004cb212     MOV        this,dword ptr [EDI + 0x184]
    //         004cb218     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb21d     MOV        EDX,dword ptr [EAX]
    //         004cb21f     MOV        this,EAX
    //         004cb221     CALL       dword ptr [EDX + 0x18]
    //         004cb224     CMP        AX,0x68
    //                              t_c_obj.cpp:894 (6)
    //         004cb228     JZ         LAB_004cb2e1
    //                               LAB_004cb22e                                                 XREF[3]:     004cb1eb(j), 004cb1fa(j), 
    //                                                                                                         004cb210(j)  
    //                              t_c_obj.cpp:900 (39)
    //         004cb22e     MOV        this,dword ptr [EDI + 0x184]
    //         004cb234     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb239     CMP        AL,0x1
    //         004cb23b     JNZ        LAB_004cb276
    //         004cb23d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb243     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb248     MOV        EDX,dword ptr [EAX]
    //         004cb24a     MOV        this,EAX
    //         004cb24c     CALL       dword ptr [EDX + 0x18]
    //         004cb24f     CMP        AX,0x68
    //         004cb253     JNZ        LAB_004cb276
    //                              t_c_obj.cpp:903 (31)
    //         004cb255     MOV        this,dword ptr [EDI + 0x184]
    //         004cb25b     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb260     MOV        this,dword ptr [ESI + 0x40]
    //         004cb263     MOV        EDX,dword ptr [EAX]
    //         004cb265     PUSH       this
    //         004cb266     MOV        this,dword ptr [ESI + 0x3c]
    //         004cb269     PUSH       this=>DAT_fffffff8
    //         004cb26a     MOV        this,dword ptr [ESI + 0x38]
    //         004cb26d     PUSH       this=>DAT_fffffff4
    //         004cb26e     PUSH       ESI=>DAT_fffffff0
    //         004cb26f     MOV        this,EAX
    //         004cb271     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:904 (2)
    //         004cb274     JMP        LAB_004cb2e1
    //                               LAB_004cb276                                                 XREF[2]:     004cb23b(j), 004cb253(j)  
    //                              t_c_obj.cpp:909 (25)
    //         004cb276     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb279     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cb27c     MOV        this,dword ptr [ESI + 0x38]
    //         004cb27f     MOV        EBP,dword ptr [EDI]
    //         004cb281     PUSH       EDX
    //         004cb282     PUSH       EAX=>DAT_fffffff8
    //         004cb283     PUSH       this=>DAT_fffffff4
    //         004cb284     PUSH       ESI=>DAT_fffffff0
    //         004cb285     MOV        this,EDI
    //         004cb287     CALL       dword ptr [EBP + 0x210]
    //         004cb28d     MOV        EBX,EAX
    //                              t_c_obj.cpp:910 (4)
    //         004cb28f     TEST       EBX,EBX
    //         004cb291     JZ         LAB_004cb2e6
    //                              t_c_obj.cpp:917 (42)
    //         004cb293     PUSH       0x48
    //         004cb295     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb29a     ADD        ESP,0x4
    //         004cb29d     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb2a1     TEST       EAX,EAX
    //         004cb2a3     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb2ab     JZ         LAB_004cb2bb
    //         004cb2ad     PUSH       ESI
    //         004cb2ae     PUSH       EBX=>DAT_fffffff8
    //         004cb2af     PUSH       EDI=>DAT_fffffff4
    //         004cb2b0     MOV        this,EAX
    //         004cb2b2     CALL       TRIBE_Action_Convert::TRIBE_Action_Convert       undefined TRIBE_Action_Convert(TRIBE_Action_C
    //         004cb2b7     MOV        ESI,EAX
    //         004cb2b9     JMP        LAB_004cb2bd
    //                               LAB_004cb2bb                                                 XREF[1]:     004cb2ab(j)  
    //         004cb2bb     XOR        ESI,ESI
    //                               LAB_004cb2bd                                                 XREF[1]:     004cb2b9(j)  
    //                              t_c_obj.cpp:918 (12)
    //         004cb2bd     TEST       ESI,ESI
    //         004cb2bf     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb2c7     JNZ        LAB_004cb2cd
    //                              t_c_obj.cpp:922 (4)
    //         004cb2c9     XOR        EAX,EAX
    //         004cb2cb     JMP        LAB_004cb2e6
    //                               LAB_004cb2cd                                                 XREF[1]:     004cb2c7(j)  
    //                              t_c_obj.cpp:924 (11)
    //         004cb2cd     MOV        this,dword ptr [EDI + 0x184]
    //         004cb2d3     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:925 (9)
    //         004cb2d8     PUSH       ESI
    //         004cb2d9     MOV        this,EDI
    //         004cb2db     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb2e1                                                 XREF[2]:     004cb228(j), 004cb274(j)  
    //                              t_c_obj.cpp:926 (5)
    //         004cb2e1     MOV        EAX,0x1
    //                               LAB_004cb2e6                                                 XREF[3]:     004cb1df(j), 004cb291(j), 
    //                                                                                                         004cb2cb(j)  
    //                              t_c_obj.cpp:927 (21)
    //         004cb2e6     MOV        this,dword ptr [ESP + local_c]
    //         004cb2ea     POP        EDI
    //         004cb2eb     POP        ESI
    //         004cb2ec     POP        EBP
    //         004cb2ed     MOV        dword ptr FS:[0x0],this
    //         004cb2f4     POP        EBX
    //         004cb2f5     ADD        ESP,0xc
    //         004cb2f8     RET        0x8
    //         004cb2fb     ??         90h
    //         004cb2fc     NOP
    //         004cb2fd     NOP
    //         004cb2fe     NOP
    //         004cb2ff     NOP
    return 0;
}

int TRIBE_Combat_Object::heal(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall heal(TRIBE_Combat_Object * this, int param_1, int par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb316(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb335(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb436(R)  
    //                               ?heal@TRIBE_Combat_Object@@UAEHHH@Z                          XREF[2]:     00574800(*), 00574aa8(*)  
    //                               TRIBE_Combat_Object::heal
    //                              t_c_obj.cpp:933 (22)
    //         004cb300     MOV        EAX,FS:[0x0]
    //         004cb306     PUSH       -0x1
    //         004cb308     PUSH       FUN_0055fbfb
    //         004cb30d     PUSH       EAX
    //         004cb30e     MOV        dword ptr FS:[0x0],ESP
    //         004cb315     PUSH       EBX
    //                              t_c_obj.cpp:934 (23)
    //         004cb316     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb31a     PUSH       EBP
    //         004cb31b     PUSH       ESI
    //         004cb31c     PUSH       EDI
    //         004cb31d     MOV        EDI,this
    //         004cb31f     PUSH       EAX
    //         004cb320     MOV        this,dword ptr [EDI + 0xc]
    //         004cb323     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb326     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb32b     MOV        ESI,EAX
    //                              t_c_obj.cpp:935 (8)
    //         004cb32d     TEST       ESI,ESI
    //         004cb32f     JZ         LAB_004cb436
    //                              t_c_obj.cpp:947 (67)
    //         004cb335     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb339     TEST       EAX,EAX
    //         004cb33b     JNZ        LAB_004cb37e
    //         004cb33d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb343     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb348     CMP        AL,0x1
    //         004cb34a     JNZ        LAB_004cb37e
    //         004cb34c     MOV        this,dword ptr [EDI + 0x184]
    //         004cb352     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb357     MOV        EDX,dword ptr [EAX]
    //         004cb359     MOV        this,EAX
    //         004cb35b     CALL       dword ptr [EDX + 0x4c]
    //         004cb35e     CMP        EAX,ESI
    //         004cb360     JNZ        LAB_004cb37e
    //         004cb362     MOV        this,dword ptr [EDI + 0x184]
    //         004cb368     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb36d     MOV        EDX,dword ptr [EAX]
    //         004cb36f     MOV        this,EAX
    //         004cb371     CALL       dword ptr [EDX + 0x18]
    //         004cb374     CMP        AX,0x69
    //                              t_c_obj.cpp:952 (6)
    //         004cb378     JZ         LAB_004cb431
    //                               LAB_004cb37e                                                 XREF[3]:     004cb33b(j), 004cb34a(j), 
    //                                                                                                         004cb360(j)  
    //                              t_c_obj.cpp:958 (39)
    //         004cb37e     MOV        this,dword ptr [EDI + 0x184]
    //         004cb384     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb389     CMP        AL,0x1
    //         004cb38b     JNZ        LAB_004cb3c6
    //         004cb38d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb393     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb398     MOV        EDX,dword ptr [EAX]
    //         004cb39a     MOV        this,EAX
    //         004cb39c     CALL       dword ptr [EDX + 0x18]
    //         004cb39f     CMP        AX,0x69
    //         004cb3a3     JNZ        LAB_004cb3c6
    //                              t_c_obj.cpp:961 (31)
    //         004cb3a5     MOV        this,dword ptr [EDI + 0x184]
    //         004cb3ab     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb3b0     MOV        this,dword ptr [ESI + 0x40]
    //         004cb3b3     MOV        EDX,dword ptr [EAX]
    //         004cb3b5     PUSH       this
    //         004cb3b6     MOV        this,dword ptr [ESI + 0x3c]
    //         004cb3b9     PUSH       this=>DAT_fffffff8
    //         004cb3ba     MOV        this,dword ptr [ESI + 0x38]
    //         004cb3bd     PUSH       this=>DAT_fffffff4
    //         004cb3be     PUSH       ESI=>DAT_fffffff0
    //         004cb3bf     MOV        this,EAX
    //         004cb3c1     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:962 (2)
    //         004cb3c4     JMP        LAB_004cb431
    //                               LAB_004cb3c6                                                 XREF[2]:     004cb38b(j), 004cb3a3(j)  
    //                              t_c_obj.cpp:967 (25)
    //         004cb3c6     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb3c9     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cb3cc     MOV        this,dword ptr [ESI + 0x38]
    //         004cb3cf     MOV        EBP,dword ptr [EDI]
    //         004cb3d1     PUSH       EDX
    //         004cb3d2     PUSH       EAX=>DAT_fffffff8
    //         004cb3d3     PUSH       this=>DAT_fffffff4
    //         004cb3d4     PUSH       ESI=>DAT_fffffff0
    //         004cb3d5     MOV        this,EDI
    //         004cb3d7     CALL       dword ptr [EBP + 0x210]
    //         004cb3dd     MOV        EBX,EAX
    //                              t_c_obj.cpp:968 (4)
    //         004cb3df     TEST       EBX,EBX
    //         004cb3e1     JZ         LAB_004cb436
    //                              t_c_obj.cpp:975 (42)
    //         004cb3e3     PUSH       0x40
    //         004cb3e5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb3ea     ADD        ESP,0x4
    //         004cb3ed     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb3f1     TEST       EAX,EAX
    //         004cb3f3     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb3fb     JZ         LAB_004cb40b
    //         004cb3fd     PUSH       ESI
    //         004cb3fe     PUSH       EBX=>DAT_fffffff8
    //         004cb3ff     PUSH       EDI=>DAT_fffffff4
    //         004cb400     MOV        this,EAX
    //         004cb402     CALL       TRIBE_Action_Heal::TRIBE_Action_Heal             undefined TRIBE_Action_Heal(TRIBE_Action_Heal
    //         004cb407     MOV        ESI,EAX
    //         004cb409     JMP        LAB_004cb40d
    //                               LAB_004cb40b                                                 XREF[1]:     004cb3fb(j)  
    //         004cb40b     XOR        ESI,ESI
    //                               LAB_004cb40d                                                 XREF[1]:     004cb409(j)  
    //                              t_c_obj.cpp:976 (12)
    //         004cb40d     TEST       ESI,ESI
    //         004cb40f     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb417     JNZ        LAB_004cb41d
    //                              t_c_obj.cpp:980 (4)
    //         004cb419     XOR        EAX,EAX
    //         004cb41b     JMP        LAB_004cb436
    //                               LAB_004cb41d                                                 XREF[1]:     004cb417(j)  
    //                              t_c_obj.cpp:982 (11)
    //         004cb41d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb423     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:983 (9)
    //         004cb428     PUSH       ESI
    //         004cb429     MOV        this,EDI
    //         004cb42b     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb431                                                 XREF[2]:     004cb378(j), 004cb3c4(j)  
    //                              t_c_obj.cpp:984 (5)
    //         004cb431     MOV        EAX,0x1
    //                               LAB_004cb436                                                 XREF[3]:     004cb32f(j), 004cb3e1(j), 
    //                                                                                                         004cb41b(j)  
    //                              t_c_obj.cpp:985 (21)
    //         004cb436     MOV        this,dword ptr [ESP + local_c]
    //         004cb43a     POP        EDI
    //         004cb43b     POP        ESI
    //         004cb43c     POP        EBP
    //         004cb43d     MOV        dword ptr FS:[0x0],this
    //         004cb444     POP        EBX
    //         004cb445     ADD        ESP,0xc
    //         004cb448     RET        0x8
    //         004cb44b     ??         90h
    //         004cb44c     NOP
    //         004cb44d     NOP
    //         004cb44e     NOP
    //         004cb44f     NOP
    return 0;
}

int TRIBE_Combat_Object::repair(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall repair(TRIBE_Combat_Object * this, int param_1, int p
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb465(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb485(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb5a1(R)  
    //                               ?repair@TRIBE_Combat_Object@@UAEHHH@Z                        XREF[2]:     005748e8(*), 00574b90(*)  
    //                               TRIBE_Combat_Object::repair
    //                              t_c_obj.cpp:991 (21)
    //         004cb450     MOV        EAX,FS:[0x0]
    //         004cb456     PUSH       -0x1
    //         004cb458     PUSH       FUN_0055fc1b
    //         004cb45d     PUSH       EAX
    //         004cb45e     MOV        dword ptr FS:[0x0],ESP
    //                              t_c_obj.cpp:992 (24)
    //         004cb465     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb469     PUSH       EBX
    //         004cb46a     PUSH       EBP
    //         004cb46b     PUSH       ESI
    //         004cb46c     MOV        ESI,this
    //         004cb46e     PUSH       EDI
    //         004cb46f     PUSH       EAX
    //         004cb470     MOV        this,dword ptr [ESI + 0xc]
    //         004cb473     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb476     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb47b     MOV        EDI,EAX
    //                              t_c_obj.cpp:993 (8)
    //         004cb47d     TEST       EDI,EDI
    //         004cb47f     JZ         LAB_004cb5a1
    //                              t_c_obj.cpp:1005 (67)
    //         004cb485     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb489     TEST       EAX,EAX
    //         004cb48b     JNZ        LAB_004cb4ce
    //         004cb48d     MOV        this,dword ptr [ESI + 0x184]
    //         004cb493     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb498     CMP        AL,0x1
    //         004cb49a     JNZ        LAB_004cb4ce
    //         004cb49c     MOV        this,dword ptr [ESI + 0x184]
    //         004cb4a2     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb4a7     MOV        EDX,dword ptr [EAX]
    //         004cb4a9     MOV        this,EAX
    //         004cb4ab     CALL       dword ptr [EDX + 0x4c]
    //         004cb4ae     CMP        EAX,EDI
    //         004cb4b0     JNZ        LAB_004cb4ce
    //         004cb4b2     MOV        this,dword ptr [ESI + 0x184]
    //         004cb4b8     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb4bd     MOV        EDX,dword ptr [EAX]
    //         004cb4bf     MOV        this,EAX
    //         004cb4c1     CALL       dword ptr [EDX + 0x18]
    //         004cb4c4     CMP        AX,0x6a
    //                              t_c_obj.cpp:1010 (6)
    //         004cb4c8     JZ         LAB_004cb59c
    //                               LAB_004cb4ce                                                 XREF[3]:     004cb48b(j), 004cb49a(j), 
    //                                                                                                         004cb4b0(j)  
    //                              t_c_obj.cpp:1016 (39)
    //         004cb4ce     MOV        this,dword ptr [ESI + 0x184]
    //         004cb4d4     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb4d9     CMP        AL,0x1
    //         004cb4db     JNZ        LAB_004cb519
    //         004cb4dd     MOV        this,dword ptr [ESI + 0x184]
    //         004cb4e3     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb4e8     MOV        EDX,dword ptr [EAX]
    //         004cb4ea     MOV        this,EAX
    //         004cb4ec     CALL       dword ptr [EDX + 0x18]
    //         004cb4ef     CMP        AX,0x6a
    //         004cb4f3     JNZ        LAB_004cb519
    //                              t_c_obj.cpp:1019 (31)
    //         004cb4f5     MOV        this,dword ptr [ESI + 0x184]
    //         004cb4fb     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb500     MOV        this,dword ptr [EDI + 0x40]
    //         004cb503     MOV        EDX,dword ptr [EAX]
    //         004cb505     PUSH       this
    //         004cb506     MOV        this,dword ptr [EDI + 0x3c]
    //         004cb509     PUSH       this=>DAT_fffffff8
    //         004cb50a     MOV        this,dword ptr [EDI + 0x38]
    //         004cb50d     PUSH       this=>DAT_fffffff4
    //         004cb50e     PUSH       EDI=>DAT_fffffff0
    //         004cb50f     MOV        this,EAX
    //         004cb511     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:1020 (5)
    //         004cb514     JMP        LAB_004cb59c
    //                               LAB_004cb519                                                 XREF[2]:     004cb4db(j), 004cb4f3(j)  
    //                              t_c_obj.cpp:1024 (16)
    //         004cb519     MOV        EDX,dword ptr [ESI + 0xc]
    //         004cb51c     MOV        EAX,dword ptr [EDX + 0x24]
    //         004cb51f     MOV        EAX,dword ptr [EAX + 0x270]
    //         004cb525     TEST       EAX,EAX
    //         004cb527     JZ         LAB_004cb531
    //                              t_c_obj.cpp:1025 (8)
    //         004cb529     MOV        EDX,dword ptr [ESI]
    //         004cb52b     PUSH       EAX
    //         004cb52c     MOV        this,ESI
    //         004cb52e     CALL       dword ptr [EDX + 0x54]
    //                               LAB_004cb531                                                 XREF[1]:     004cb527(j)  
    //                              t_c_obj.cpp:1029 (25)
    //         004cb531     MOV        EAX,dword ptr [EDI + 0x40]
    //         004cb534     MOV        this,dword ptr [EDI + 0x3c]
    //         004cb537     MOV        EDX,dword ptr [EDI + 0x38]
    //         004cb53a     MOV        EBP,dword ptr [ESI]
    //         004cb53c     PUSH       EAX
    //         004cb53d     PUSH       this=>DAT_fffffff8
    //         004cb53e     PUSH       EDX=>DAT_fffffff4
    //         004cb53f     PUSH       EDI=>DAT_fffffff0
    //         004cb540     MOV        this,ESI
    //         004cb542     CALL       dword ptr [EBP + 0x210]
    //         004cb548     MOV        EBX,EAX
    //                              t_c_obj.cpp:1030 (4)
    //         004cb54a     TEST       EBX,EBX
    //         004cb54c     JZ         LAB_004cb5a1
    //                              t_c_obj.cpp:1037 (42)
    //         004cb54e     PUSH       0x44
    //         004cb550     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb555     ADD        ESP,0x4
    //         004cb558     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb55c     TEST       EAX,EAX
    //         004cb55e     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb566     JZ         LAB_004cb576
    //         004cb568     PUSH       EDI
    //         004cb569     PUSH       EBX=>DAT_fffffff8
    //         004cb56a     PUSH       ESI=>DAT_fffffff4
    //         004cb56b     MOV        this,EAX
    //         004cb56d     CALL       TRIBE_Action_Repair::TRIBE_Action_Repair         undefined TRIBE_Action_Repair(TRIBE_Action_Re
    //         004cb572     MOV        EDI,EAX
    //         004cb574     JMP        LAB_004cb578
    //                               LAB_004cb576                                                 XREF[1]:     004cb566(j)  
    //         004cb576     XOR        EDI,EDI
    //                               LAB_004cb578                                                 XREF[1]:     004cb574(j)  
    //                              t_c_obj.cpp:1038 (12)
    //         004cb578     TEST       EDI,EDI
    //         004cb57a     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb582     JNZ        LAB_004cb588
    //                              t_c_obj.cpp:1042 (4)
    //         004cb584     XOR        EAX,EAX
    //         004cb586     JMP        LAB_004cb5a1
    //                               LAB_004cb588                                                 XREF[1]:     004cb582(j)  
    //                              t_c_obj.cpp:1044 (11)
    //         004cb588     MOV        this,dword ptr [ESI + 0x184]
    //         004cb58e     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:1045 (9)
    //         004cb593     PUSH       EDI
    //         004cb594     MOV        this,ESI
    //         004cb596     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb59c                                                 XREF[2]:     004cb4c8(j), 004cb514(j)  
    //                              t_c_obj.cpp:1046 (5)
    //         004cb59c     MOV        EAX,0x1
    //                               LAB_004cb5a1                                                 XREF[3]:     004cb47f(j), 004cb54c(j), 
    //                                                                                                         004cb586(j)  
    //                              t_c_obj.cpp:1047 (21)
    //         004cb5a1     MOV        this,dword ptr [ESP + local_c]
    //         004cb5a5     POP        EDI
    //         004cb5a6     POP        ESI
    //         004cb5a7     POP        EBP
    //         004cb5a8     MOV        dword ptr FS:[0x0],this
    //         004cb5af     POP        EBX
    //         004cb5b0     ADD        ESP,0xc
    //         004cb5b3     RET        0x8
    //         004cb5b6     ??         90h
    //         004cb5b7     NOP
    //         004cb5b8     NOP
    //         004cb5b9     NOP
    //         004cb5ba     NOP
    //         004cb5bb     NOP
    //         004cb5bc     NOP
    //         004cb5bd     NOP
    //         004cb5be     NOP
    //         004cb5bf     NOP
    return 0;
}

int TRIBE_Combat_Object::build(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall build(TRIBE_Combat_Object * this, int param_1, int pa
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb5d6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb5f5(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb6f6(R)  
    //                               ?build@TRIBE_Combat_Object@@UAEHHH@Z                         XREF[2]:     005748ec(*), 00574b94(*)  
    //                               TRIBE_Combat_Object::build
    //                              t_c_obj.cpp:1053 (22)
    //         004cb5c0     MOV        EAX,FS:[0x0]
    //         004cb5c6     PUSH       -0x1
    //         004cb5c8     PUSH       FUN_0055fc3b
    //         004cb5cd     PUSH       EAX
    //         004cb5ce     MOV        dword ptr FS:[0x0],ESP
    //         004cb5d5     PUSH       EBX
    //                              t_c_obj.cpp:1054 (23)
    //         004cb5d6     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb5da     PUSH       EBP
    //         004cb5db     PUSH       ESI
    //         004cb5dc     PUSH       EDI
    //         004cb5dd     MOV        EDI,this
    //         004cb5df     PUSH       EAX
    //         004cb5e0     MOV        this,dword ptr [EDI + 0xc]
    //         004cb5e3     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb5e6     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb5eb     MOV        ESI,EAX
    //                              t_c_obj.cpp:1055 (8)
    //         004cb5ed     TEST       ESI,ESI
    //         004cb5ef     JZ         LAB_004cb6f6
    //                              t_c_obj.cpp:1067 (67)
    //         004cb5f5     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb5f9     TEST       EAX,EAX
    //         004cb5fb     JNZ        LAB_004cb63e
    //         004cb5fd     MOV        this,dword ptr [EDI + 0x184]
    //         004cb603     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb608     CMP        AL,0x1
    //         004cb60a     JNZ        LAB_004cb63e
    //         004cb60c     MOV        this,dword ptr [EDI + 0x184]
    //         004cb612     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb617     MOV        EDX,dword ptr [EAX]
    //         004cb619     MOV        this,EAX
    //         004cb61b     CALL       dword ptr [EDX + 0x4c]
    //         004cb61e     CMP        EAX,ESI
    //         004cb620     JNZ        LAB_004cb63e
    //         004cb622     MOV        this,dword ptr [EDI + 0x184]
    //         004cb628     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb62d     MOV        EDX,dword ptr [EAX]
    //         004cb62f     MOV        this,EAX
    //         004cb631     CALL       dword ptr [EDX + 0x18]
    //         004cb634     CMP        AX,0x65
    //                              t_c_obj.cpp:1072 (6)
    //         004cb638     JZ         LAB_004cb6f1
    //                               LAB_004cb63e                                                 XREF[3]:     004cb5fb(j), 004cb60a(j), 
    //                                                                                                         004cb620(j)  
    //                              t_c_obj.cpp:1078 (39)
    //         004cb63e     MOV        this,dword ptr [EDI + 0x184]
    //         004cb644     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb649     CMP        AL,0x1
    //         004cb64b     JNZ        LAB_004cb686
    //         004cb64d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb653     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb658     MOV        EDX,dword ptr [EAX]
    //         004cb65a     MOV        this,EAX
    //         004cb65c     CALL       dword ptr [EDX + 0x18]
    //         004cb65f     CMP        AX,0x65
    //         004cb663     JNZ        LAB_004cb686
    //                              t_c_obj.cpp:1081 (31)
    //         004cb665     MOV        this,dword ptr [EDI + 0x184]
    //         004cb66b     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb670     MOV        this,dword ptr [ESI + 0x40]
    //         004cb673     MOV        EDX,dword ptr [EAX]
    //         004cb675     PUSH       this
    //         004cb676     MOV        this,dword ptr [ESI + 0x3c]
    //         004cb679     PUSH       this=>DAT_fffffff8
    //         004cb67a     MOV        this,dword ptr [ESI + 0x38]
    //         004cb67d     PUSH       this=>DAT_fffffff4
    //         004cb67e     PUSH       ESI=>DAT_fffffff0
    //         004cb67f     MOV        this,EAX
    //         004cb681     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:1082 (2)
    //         004cb684     JMP        LAB_004cb6f1
    //                               LAB_004cb686                                                 XREF[2]:     004cb64b(j), 004cb663(j)  
    //                              t_c_obj.cpp:1087 (25)
    //         004cb686     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb689     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cb68c     MOV        this,dword ptr [ESI + 0x38]
    //         004cb68f     MOV        EBP,dword ptr [EDI]
    //         004cb691     PUSH       EDX
    //         004cb692     PUSH       EAX=>DAT_fffffff8
    //         004cb693     PUSH       this=>DAT_fffffff4
    //         004cb694     PUSH       ESI=>DAT_fffffff0
    //         004cb695     MOV        this,EDI
    //         004cb697     CALL       dword ptr [EBP + 0x210]
    //         004cb69d     MOV        EBX,EAX
    //                              t_c_obj.cpp:1088 (4)
    //         004cb69f     TEST       EBX,EBX
    //         004cb6a1     JZ         LAB_004cb6f6
    //                              t_c_obj.cpp:1095 (42)
    //         004cb6a3     PUSH       0x40
    //         004cb6a5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb6aa     ADD        ESP,0x4
    //         004cb6ad     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb6b1     TEST       EAX,EAX
    //         004cb6b3     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb6bb     JZ         LAB_004cb6cb
    //         004cb6bd     PUSH       ESI
    //         004cb6be     PUSH       EBX=>DAT_fffffff8
    //         004cb6bf     PUSH       EDI=>DAT_fffffff4
    //         004cb6c0     MOV        this,EAX
    //         004cb6c2     CALL       TRIBE_Action_Build::TRIBE_Action_Build           undefined TRIBE_Action_Build(TRIBE_Action_Bui
    //         004cb6c7     MOV        ESI,EAX
    //         004cb6c9     JMP        LAB_004cb6cd
    //                               LAB_004cb6cb                                                 XREF[1]:     004cb6bb(j)  
    //         004cb6cb     XOR        ESI,ESI
    //                               LAB_004cb6cd                                                 XREF[1]:     004cb6c9(j)  
    //                              t_c_obj.cpp:1096 (12)
    //         004cb6cd     TEST       ESI,ESI
    //         004cb6cf     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb6d7     JNZ        LAB_004cb6dd
    //                              t_c_obj.cpp:1100 (4)
    //         004cb6d9     XOR        EAX,EAX
    //         004cb6db     JMP        LAB_004cb6f6
    //                               LAB_004cb6dd                                                 XREF[1]:     004cb6d7(j)  
    //                              t_c_obj.cpp:1102 (11)
    //         004cb6dd     MOV        this,dword ptr [EDI + 0x184]
    //         004cb6e3     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:1103 (9)
    //         004cb6e8     PUSH       ESI
    //         004cb6e9     MOV        this,EDI
    //         004cb6eb     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb6f1                                                 XREF[2]:     004cb638(j), 004cb684(j)  
    //                              t_c_obj.cpp:1104 (5)
    //         004cb6f1     MOV        EAX,0x1
    //                               LAB_004cb6f6                                                 XREF[3]:     004cb5ef(j), 004cb6a1(j), 
    //                                                                                                         004cb6db(j)  
    //                              t_c_obj.cpp:1105 (21)
    //         004cb6f6     MOV        this,dword ptr [ESP + local_c]
    //         004cb6fa     POP        EDI
    //         004cb6fb     POP        ESI
    //         004cb6fc     POP        EBP
    //         004cb6fd     MOV        dword ptr FS:[0x0],this
    //         004cb704     POP        EBX
    //         004cb705     ADD        ESP,0xc
    //         004cb708     RET        0x8
    //         004cb70b     ??         90h
    //         004cb70c     NOP
    //         004cb70d     NOP
    //         004cb70e     NOP
    //         004cb70f     NOP
    return 0;
}

int TRIBE_Combat_Object::trade(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall trade(TRIBE_Combat_Object * this, int param_1, int pa
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb726(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cb745(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cb846(R)  
    //                               ?trade@TRIBE_Combat_Object@@UAEHHH@Z                         XREF[2]:     005748f0(*), 00574b98(*)  
    //                               TRIBE_Combat_Object::trade
    //                              t_c_obj.cpp:1111 (22)
    //         004cb710     MOV        EAX,FS:[0x0]
    //         004cb716     PUSH       -0x1
    //         004cb718     PUSH       FUN_0055fc5b
    //         004cb71d     PUSH       EAX
    //         004cb71e     MOV        dword ptr FS:[0x0],ESP
    //         004cb725     PUSH       EBX
    //                              t_c_obj.cpp:1112 (23)
    //         004cb726     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb72a     PUSH       EBP
    //         004cb72b     PUSH       ESI
    //         004cb72c     PUSH       EDI
    //         004cb72d     MOV        EDI,this
    //         004cb72f     PUSH       EAX
    //         004cb730     MOV        this,dword ptr [EDI + 0xc]
    //         004cb733     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cb736     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004cb73b     MOV        ESI,EAX
    //                              t_c_obj.cpp:1113 (8)
    //         004cb73d     TEST       ESI,ESI
    //         004cb73f     JZ         LAB_004cb846
    //                              t_c_obj.cpp:1125 (67)
    //         004cb745     MOV        EAX,dword ptr [ESP + param_2]
    //         004cb749     TEST       EAX,EAX
    //         004cb74b     JNZ        LAB_004cb78e
    //         004cb74d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb753     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb758     CMP        AL,0x1
    //         004cb75a     JNZ        LAB_004cb78e
    //         004cb75c     MOV        this,dword ptr [EDI + 0x184]
    //         004cb762     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb767     MOV        EDX,dword ptr [EAX]
    //         004cb769     MOV        this,EAX
    //         004cb76b     CALL       dword ptr [EDX + 0x4c]
    //         004cb76e     CMP        EAX,ESI
    //         004cb770     JNZ        LAB_004cb78e
    //         004cb772     MOV        this,dword ptr [EDI + 0x184]
    //         004cb778     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb77d     MOV        EDX,dword ptr [EAX]
    //         004cb77f     MOV        this,EAX
    //         004cb781     CALL       dword ptr [EDX + 0x18]
    //         004cb784     CMP        AX,0x6f
    //                              t_c_obj.cpp:1130 (6)
    //         004cb788     JZ         LAB_004cb841
    //                               LAB_004cb78e                                                 XREF[3]:     004cb74b(j), 004cb75a(j), 
    //                                                                                                         004cb770(j)  
    //                              t_c_obj.cpp:1136 (39)
    //         004cb78e     MOV        this,dword ptr [EDI + 0x184]
    //         004cb794     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004cb799     CMP        AL,0x1
    //         004cb79b     JNZ        LAB_004cb7d6
    //         004cb79d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb7a3     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb7a8     MOV        EDX,dword ptr [EAX]
    //         004cb7aa     MOV        this,EAX
    //         004cb7ac     CALL       dword ptr [EDX + 0x18]
    //         004cb7af     CMP        AX,0x6f
    //         004cb7b3     JNZ        LAB_004cb7d6
    //                              t_c_obj.cpp:1139 (31)
    //         004cb7b5     MOV        this,dword ptr [EDI + 0x184]
    //         004cb7bb     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cb7c0     MOV        this,dword ptr [ESI + 0x40]
    //         004cb7c3     MOV        EDX,dword ptr [EAX]
    //         004cb7c5     PUSH       this
    //         004cb7c6     MOV        this,dword ptr [ESI + 0x3c]
    //         004cb7c9     PUSH       this=>DAT_fffffff8
    //         004cb7ca     MOV        this,dword ptr [ESI + 0x38]
    //         004cb7cd     PUSH       this=>DAT_fffffff4
    //         004cb7ce     PUSH       ESI=>DAT_fffffff0
    //         004cb7cf     MOV        this,EAX
    //         004cb7d1     CALL       dword ptr [EDX + 0x34]
    //                              t_c_obj.cpp:1140 (2)
    //         004cb7d4     JMP        LAB_004cb841
    //                               LAB_004cb7d6                                                 XREF[2]:     004cb79b(j), 004cb7b3(j)  
    //                              t_c_obj.cpp:1145 (25)
    //         004cb7d6     MOV        EDX,dword ptr [ESI + 0x40]
    //         004cb7d9     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004cb7dc     MOV        this,dword ptr [ESI + 0x38]
    //         004cb7df     MOV        EBP,dword ptr [EDI]
    //         004cb7e1     PUSH       EDX
    //         004cb7e2     PUSH       EAX=>DAT_fffffff8
    //         004cb7e3     PUSH       this=>DAT_fffffff4
    //         004cb7e4     PUSH       ESI=>DAT_fffffff0
    //         004cb7e5     MOV        this,EDI
    //         004cb7e7     CALL       dword ptr [EBP + 0x210]
    //         004cb7ed     MOV        EBX,EAX
    //                              t_c_obj.cpp:1146 (4)
    //         004cb7ef     TEST       EBX,EBX
    //         004cb7f1     JZ         LAB_004cb846
    //                              t_c_obj.cpp:1153 (42)
    //         004cb7f3     PUSH       0x48
    //         004cb7f5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb7fa     ADD        ESP,0x4
    //         004cb7fd     MOV        dword ptr [ESP + 0x20],EAX
    //         004cb801     TEST       EAX,EAX
    //         004cb803     MOV        dword ptr [ESP + 0x18],0x0
    //         004cb80b     JZ         LAB_004cb81b
    //         004cb80d     PUSH       ESI
    //         004cb80e     PUSH       EBX=>DAT_fffffff8
    //         004cb80f     PUSH       EDI=>DAT_fffffff4
    //         004cb810     MOV        this,EAX
    //         004cb812     CALL       TRIBE_Action_Trade::TRIBE_Action_Trade           undefined TRIBE_Action_Trade(TRIBE_Action_Tra
    //         004cb817     MOV        ESI,EAX
    //         004cb819     JMP        LAB_004cb81d
    //                               LAB_004cb81b                                                 XREF[1]:     004cb80b(j)  
    //         004cb81b     XOR        ESI,ESI
    //                               LAB_004cb81d                                                 XREF[1]:     004cb819(j)  
    //                              t_c_obj.cpp:1154 (12)
    //         004cb81d     TEST       ESI,ESI
    //         004cb81f     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004cb827     JNZ        LAB_004cb82d
    //                              t_c_obj.cpp:1158 (4)
    //         004cb829     XOR        EAX,EAX
    //         004cb82b     JMP        LAB_004cb846
    //                               LAB_004cb82d                                                 XREF[1]:     004cb827(j)  
    //                              t_c_obj.cpp:1160 (11)
    //         004cb82d     MOV        this,dword ptr [EDI + 0x184]
    //         004cb833     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_c_obj.cpp:1161 (9)
    //         004cb838     PUSH       ESI
    //         004cb839     MOV        this,EDI
    //         004cb83b     CALL       dword ptr [EBP + 0x208]
    //                               LAB_004cb841                                                 XREF[2]:     004cb788(j), 004cb7d4(j)  
    //                              t_c_obj.cpp:1162 (5)
    //         004cb841     MOV        EAX,0x1
    //                               LAB_004cb846                                                 XREF[3]:     004cb73f(j), 004cb7f1(j), 
    //                                                                                                         004cb82b(j)  
    //                              t_c_obj.cpp:1163 (21)
    //         004cb846     MOV        this,dword ptr [ESP + local_c]
    //         004cb84a     POP        EDI
    //         004cb84b     POP        ESI
    //         004cb84c     POP        EBP
    //         004cb84d     MOV        dword ptr FS:[0x0],this
    //         004cb854     POP        EBX
    //         004cb855     ADD        ESP,0xc
    //         004cb858     RET        0x8
    //         004cb85b     ??         90h
    //         004cb85c     NOP
    //         004cb85d     NOP
    //         004cb85e     NOP
    //         004cb85f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int)const  *
    //                              uchar __thiscall keepGatheringWhenObjectIsOut(TRIBE_Combat_Object * 
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb860(R)  
    //                               ?keepGatheringWhenObjectIsOut@TRIBE_Combat_Object@@UBEEH@Z   XREF[2]:     005748b0(*), 00574b58(*)  
    //                               TRIBE_Combat_Object::keepGatheringWhenObjectIsOut
    //                              t_c_obj.cpp:1168 (14)
    //         004cb860     MOV        EAX,dword ptr [ESP + param_1]
    //         004cb864     CMP        EAX,0x32
    //         004cb867     JZ         LAB_004cb873
    //         004cb869     CMP        EAX,0x2d
    //         004cb86c     JZ         LAB_004cb873
    //                              t_c_obj.cpp:1171 (2)
    //         004cb86e     XOR        AL,AL
    //                              t_c_obj.cpp:1172 (3)
    //         004cb870     RET        0x4
    //                               LAB_004cb873                                                 XREF[2]:     004cb867(j), 004cb86c(j)  
    //                              t_c_obj.cpp:1170 (2)
    //         004cb873     MOV        AL,0x1
    //                              t_c_obj.cpp:1172 (3)
    //         004cb875     RET        0x4
    //         004cb878     ??         90h
    //         004cb879     NOP
    //         004cb87a     NOP
    //         004cb87b     NOP
    //         004cb87c     NOP
    //         004cb87d     NOP
    //         004cb87e     NOP
    //         004cb87f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_Combat_Object::produceWhenKilledBy(int)const           *
    //                              uchar __thiscall produceWhenKilledBy(TRIBE_Combat_Object * this, int
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004cb896(R)  
    //                               ?produceWhenKilledBy@TRIBE_Combat_Object@@UBEEH@Z            XREF[2]:     005748b4(*), 00574b5c(*)  
    //                               TRIBE_Combat_Object::produceWhenKilledBy
    //                              t_c_obj.cpp:1177 (7)
    //         004cb880     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cb883     MOVSX      EAX,word ptr [EAX + 0x14]
    //                              t_c_obj.cpp:1181 (10)
    //         004cb887     CMP        EAX,0x9
    //         004cb88a     JZ         LAB_004cb896
    //         004cb88c     CMP        EAX,0xa
    //         004cb88f     JZ         LAB_004cb896
    //                              t_c_obj.cpp:1182 (2)
    //         004cb891     MOV        AL,0x1
    //                              t_c_obj.cpp:1188 (3)
    //         004cb893     RET        0x4
    //                               LAB_004cb896                                                 XREF[2]:     004cb88a(j), 004cb88f(j)  
    //                              t_c_obj.cpp:1185 (8)
    //         004cb896     CMP        dword ptr [ESP + param_1],0x4
    //         004cb89b     SETZ       AL
    //                              t_c_obj.cpp:1188 (3)
    //         004cb89e     RET        0x4
    //         004cb8a1     ??         90h
    //         004cb8a2     NOP
    //         004cb8a3     NOP
    //         004cb8a4     NOP
    //         004cb8a5     NOP
    //         004cb8a6     NOP
    //         004cb8a7     NOP
    //         004cb8a8     NOP
    //         004cb8a9     NOP
    //         004cb8aa     NOP
    //         004cb8ab     NOP
    //         004cb8ac     NOP
    //         004cb8ad     NOP
    //         004cb8ae     NOP
    //         004cb8af     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_Combat_Object::useSameZoneDropsite(void)const          *
    //                              uchar __thiscall useSameZoneDropsite(TRIBE_Combat_Object * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //                               ?useSameZoneDropsite@TRIBE_Combat_Object@@UBEEXZ             XREF[2]:     005748b8(*), 00574b60(*)  
    //                               TRIBE_Combat_Object::useSameZoneDropsite
    //                              t_c_obj.cpp:1193 (7)
    //         004cb8b0     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cb8b3     MOVSX      EAX,word ptr [EAX + 0x14]
    //                              t_c_obj.cpp:1198 (10)
    //         004cb8b7     CMP        EAX,0x15
    //         004cb8ba     JZ         LAB_004cb8c4
    //         004cb8bc     CMP        EAX,0x2
    //         004cb8bf     JZ         LAB_004cb8c4
    //                              t_c_obj.cpp:1201 (2)
    //         004cb8c1     MOV        AL,0x1
    //                              t_c_obj.cpp:1202 (1)
    //         004cb8c3     RET
    //                               LAB_004cb8c4                                                 XREF[2]:     004cb8ba(j), 004cb8bf(j)  
    //                              t_c_obj.cpp:1199 (2)
    //         004cb8c4     XOR        AL,AL
    //                              t_c_obj.cpp:1202 (1)
    //         004cb8c6     RET
    //         004cb8c7     ??         90h
    //         004cb8c8     NOP
    //         004cb8c9     NOP
    //         004cb8ca     NOP
    //         004cb8cb     NOP
    //         004cb8cc     NOP
    //         004cb8cd     NOP
    //         004cb8ce     NOP
    //         004cb8cf     NOP
    return 0;
}

void TRIBE_Combat_Object::initUnitAI() {
    /* TODO: Stub */
    //                              void __thiscall initUnitAI(TRIBE_Combat_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[14]:    004cb934(W), 004cb972(W), 004cb9b0(W), 004cb9ee(W), 
    //                                                                                     004cba36(W), 004cba7a(W), 004cbabe(W), 004cbaf7(W), 
    //                                                                                     004cbb35(W), 004cbb73(W), 004cbbb1(W), 004cbc17(W), 
    //                                                                                     004cbc55(W), 004cbc8f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[15]:    004cb94f(R), 004cb98d(R), 004cb9cb(R), 004cba09(R), 
    //                                                                                     004cba51(R), 004cba95(R), 004cbad9(R), 004cbb12(R), 
    //                                                                                     004cbb50(R), 004cbb8e(R), 004cbbcc(R), 004cbc32(R), 
    //                                                                                     004cbc6c(R), 004cbca6(R), 004cbcbb(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[14]:    004cb92e(W), 004cb96c(W), 004cb9aa(W), 004cb9e8(W), 
    //                                                                                     004cba30(W), 004cba74(W), 004cbab8(W), 004cbaf1(W), 
    //                                                                                     004cbb2f(W), 004cbb6d(W), 004cbbab(W), 004cbc11(W), 
    //                                                                                     004cbc4f(W), 004cbc89(W)  
    //                               ?initUnitAI@TRIBE_Combat_Object@@MAEXXZ                      XREF[2]:     005749c8(*), 00574c70(*)  
    //                               TRIBE_Combat_Object::initUnitAI
    //                              t_c_obj.cpp:1208 (25)
    //         004cb8d0     PUSH       -0x1
    //         004cb8d2     PUSH       FUN_0055fd0a
    //         004cb8d7     MOV        EAX,FS:[0x0]
    //         004cb8dd     PUSH       EAX
    //         004cb8de     MOV        dword ptr FS:[0x0],ESP
    //         004cb8e5     PUSH       this
    //         004cb8e6     PUSH       ESI
    //         004cb8e7     MOV        ESI,this
    //                              t_c_obj.cpp:1213 (32)
    //         004cb8e9     MOV        EAX,dword ptr [ESI + 0x8]
    //         004cb8ec     MOVSX      this,word ptr [EAX + 0x14]
    //         004cb8f0     DEC        this
    //         004cb8f1     CMP        this,0x20
    //         004cb8f4     JA         switchD_004cb902::caseD_6
    //         004cb8fa     XOR        EDX,EDX
    //         004cb8fc     MOV        DL,byte ptr [this->_padding_ + 0x4cbd0c]=>PTR_
    //                               switchD_004cb902::switchD
    //         004cb902     JMP        dword ptr [EDX*0x4 + switchD_004cb902::switchd   = 004cb909
    //                               switchD_004cb902::caseD_1                                    XREF[2]:     004cb902(j), 004cbccc(*)  
    //                              t_c_obj.cpp:1218 (24)
    //         004cb909     MOV        AX,word ptr [EAX + 0x10]
    //         004cb90d     CMP        AX,0x63
    //         004cb911     JZ         switchD_004cb902::caseD_5
    //         004cb917     CMP        AX,0xa
    //         004cb91b     JZ         switchD_004cb902::caseD_5
    //                              t_c_obj.cpp:1219 (43)
    //         004cb921     PUSH       0x134
    //         004cb926     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb92b     ADD        ESP,0x4
    //         004cb92e     MOV        dword ptr [ESP + local_10],EAX
    //         004cb932     TEST       EAX,EAX
    //         004cb934     MOV        dword ptr [ESP + local_4],0x0
    //         004cb93c     JZ         LAB_004cbcb6
    //         004cb942     PUSH       0x5
    //         004cb944     PUSH       ESI
    //         004cb945     MOV        this,EAX
    //         004cb947     CALL       TribeArtifactUnitAIModule::TribeArtifactUnitAI   undefined TribeArtifactUnitAIModule(TribeArti
    //                              t_c_obj.cpp:1307 (3)
    //         004cb94c     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cb94f     MOV        this,dword ptr [ESP + local_c]
    //         004cb953     MOV        dword ptr FS:[0x0],this
    //         004cb95a     POP        ESI
    //         004cb95b     ADD        ESP,0x10
    //         004cb95e     RET
    //                               switchD_004cb902::caseD_4                                    XREF[2]:     004cb902(j), 004cbcd8(*)  
    //                              t_c_obj.cpp:1223 (43)
    //         004cb95f     PUSH       0x134
    //         004cb964     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb969     ADD        ESP,0x4
    //         004cb96c     MOV        dword ptr [ESP + local_10],EAX
    //         004cb970     TEST       EAX,EAX
    //         004cb972     MOV        dword ptr [ESP + local_4],0x1
    //         004cb97a     JZ         LAB_004cbcb6
    //         004cb980     PUSH       0xa
    //         004cb982     PUSH       ESI
    //         004cb983     MOV        this,EAX
    //         004cb985     CALL       TribeCivilianUnitAIModule::TribeCivilianUnitAI   undefined TribeCivilianUnitAIModule(TribeCivi
    //                              t_c_obj.cpp:1307 (3)
    //         004cb98a     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cb98d     MOV        this,dword ptr [ESP + local_c]
    //         004cb991     MOV        dword ptr FS:[0x0],this
    //         004cb998     POP        ESI
    //         004cb999     ADD        ESP,0x10
    //         004cb99c     RET
    //                               switchD_004cb902::caseD_12                                   XREF[2]:     004cb902(j), 004cbcf4(*)  
    //                              t_c_obj.cpp:1227 (43)
    //         004cb99d     PUSH       0x134
    //         004cb9a2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb9a7     ADD        ESP,0x4
    //         004cb9aa     MOV        dword ptr [ESP + local_10],EAX
    //         004cb9ae     TEST       EAX,EAX
    //         004cb9b0     MOV        dword ptr [ESP + local_4],0x2
    //         004cb9b8     JZ         LAB_004cbcb6
    //         004cb9be     PUSH       0xa
    //         004cb9c0     PUSH       ESI
    //         004cb9c1     MOV        this,EAX
    //         004cb9c3     CALL       TribePriestUnitAIModule::TribePriestUnitAIModule undefined TribePriestUnitAIModule(TribePriest
    //                              t_c_obj.cpp:1307 (3)
    //         004cb9c8     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cb9cb     MOV        this,dword ptr [ESP + local_c]
    //         004cb9cf     MOV        dword ptr FS:[0x0],this
    //         004cb9d6     POP        ESI
    //         004cb9d7     ADD        ESP,0x10
    //         004cb9da     RET
    //                               switchD_004cb902::caseD_9                                    XREF[2]:     004cb902(j), 004cbce4(*)  
    //                              t_c_obj.cpp:1231 (43)
    //         004cb9db     PUSH       0x134
    //         004cb9e0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cb9e5     ADD        ESP,0x4
    //         004cb9e8     MOV        dword ptr [ESP + local_10],EAX
    //         004cb9ec     TEST       EAX,EAX
    //         004cb9ee     MOV        dword ptr [ESP + local_4],0x3
    //         004cb9f6     JZ         LAB_004cbcb6
    //         004cb9fc     PUSH       0xa
    //         004cb9fe     PUSH       ESI
    //         004cb9ff     MOV        this,EAX
    //         004cba01     CALL       TribeHuntedAnimalUnitAIModule::TribeHuntedAnim   undefined TribeHuntedAnimalUnitAIModule(Tribe
    //                              t_c_obj.cpp:1307 (3)
    //         004cba06     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cba09     MOV        this,dword ptr [ESP + local_c]
    //         004cba0d     MOV        dword ptr FS:[0x0],this
    //         004cba14     POP        ESI
    //         004cba15     ADD        ESP,0x10
    //         004cba18     RET
    //                               switchD_004cb902::caseD_a                                    XREF[2]:     004cb902(j), 004cbce8(*)  
    //                              t_c_obj.cpp:1236 (10)
    //         004cba19     MOV        AX,word ptr [EAX + 0x10]
    //         004cba1d     CMP        AX,0x9d
    //         004cba21     JNZ        LAB_004cba61
    //                              t_c_obj.cpp:1237 (43)
    //         004cba23     PUSH       0x134
    //         004cba28     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cba2d     ADD        ESP,0x4
    //         004cba30     MOV        dword ptr [ESP + local_10],EAX
    //         004cba34     TEST       EAX,EAX
    //         004cba36     MOV        dword ptr [ESP + local_4],0x4
    //         004cba3e     JZ         LAB_004cbcb6
    //         004cba44     PUSH       0xa
    //         004cba46     PUSH       ESI
    //         004cba47     MOV        this,EAX
    //         004cba49     CALL       TribeHuntedAnimalUnitAIModule::TribeHuntedAnim   undefined TribeHuntedAnimalUnitAIModule(Tribe
    //                              t_c_obj.cpp:1307 (3)
    //         004cba4e     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cba51     MOV        this,dword ptr [ESP + local_c]
    //         004cba55     MOV        dword ptr FS:[0x0],this
    //         004cba5c     POP        ESI
    //         004cba5d     ADD        ESP,0x10
    //         004cba60     RET
    //                               LAB_004cba61                                                 XREF[1]:     004cba21(j)  
    //                              t_c_obj.cpp:1239 (6)
    //         004cba61     CMP        AX,0x30
    //         004cba65     JNZ        LAB_004cbaa5
    //                              t_c_obj.cpp:1240 (43)
    //         004cba67     PUSH       0x134
    //         004cba6c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cba71     ADD        ESP,0x4
    //         004cba74     MOV        dword ptr [ESP + local_10],EAX
    //         004cba78     TEST       EAX,EAX
    //         004cba7a     MOV        dword ptr [ESP + local_4],0x5
    //         004cba82     JZ         LAB_004cbcb6
    //         004cba88     PUSH       0xa
    //         004cba8a     PUSH       ESI
    //         004cba8b     MOV        this,EAX
    //         004cba8d     CALL       TribeElephantUnitAIModule::TribeElephantUnitAI   undefined TribeElephantUnitAIModule(TribeElep
    //                              t_c_obj.cpp:1307 (3)
    //         004cba92     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cba95     MOV        this,dword ptr [ESP + local_c]
    //         004cba99     MOV        dword ptr FS:[0x0],this
    //         004cbaa0     POP        ESI
    //         004cbaa1     ADD        ESP,0x10
    //         004cbaa4     RET
    //                               LAB_004cbaa5                                                 XREF[1]:     004cba65(j)  
    //                              t_c_obj.cpp:1242 (4)
    //         004cbaa5     CMP        AX,0x7e
    //                              t_c_obj.cpp:1243 (45)
    //         004cbaa9     PUSH       0x134
    //         004cbaae     JNZ        LAB_004cbae9
    //         004cbab0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbab5     ADD        ESP,0x4
    //         004cbab8     MOV        dword ptr [ESP + local_10],EAX
    //         004cbabc     TEST       EAX,EAX
    //         004cbabe     MOV        dword ptr [ESP + local_4],0x6
    //         004cbac6     JZ         LAB_004cbcb6
    //         004cbacc     PUSH       0xa
    //         004cbace     PUSH       ESI
    //         004cbacf     MOV        this,EAX
    //         004cbad1     CALL       TribeLionUnitAIModule::TribeLionUnitAIModule     undefined TribeLionUnitAIModule(TribeLionUnit
    //                              t_c_obj.cpp:1307 (3)
    //         004cbad6     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbad9     MOV        this,dword ptr [ESP + local_c]
    //         004cbadd     MOV        dword ptr FS:[0x0],this
    //         004cbae4     POP        ESI
    //         004cbae5     ADD        ESP,0x10
    //         004cbae8     RET
    //                               LAB_004cbae9                                                 XREF[1]:     004cbaae(j)  
    //                              t_c_obj.cpp:1246 (38)
    //         004cbae9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbaee     ADD        ESP,0x4
    //         004cbaf1     MOV        dword ptr [ESP + local_10],EAX
    //         004cbaf5     TEST       EAX,EAX
    //         004cbaf7     MOV        dword ptr [ESP + local_4],0x7
    //         004cbaff     JZ         LAB_004cbcb6
    //         004cbb05     PUSH       0xa
    //         004cbb07     PUSH       ESI
    //         004cbb08     MOV        this,EAX
    //         004cbb0a     CALL       TribePreditorUnitAIModule::TribePreditorUnitAI   undefined TribePreditorUnitAIModule(TribePred
    //                              t_c_obj.cpp:1307 (3)
    //         004cbb0f     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbb12     MOV        this,dword ptr [ESP + local_c]
    //         004cbb16     MOV        dword ptr FS:[0x0],this
    //         004cbb1d     POP        ESI
    //         004cbb1e     ADD        ESP,0x10
    //         004cbb21     RET
    //                               switchD_004cb902::caseD_15                                   XREF[2]:     004cb902(j), 004cbcfc(*)  
    //                              t_c_obj.cpp:1250 (43)
    //         004cbb22     PUSH       0x134
    //         004cbb27     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbb2c     ADD        ESP,0x4
    //         004cbb2f     MOV        dword ptr [ESP + local_10],EAX
    //         004cbb33     TEST       EAX,EAX
    //         004cbb35     MOV        dword ptr [ESP + local_4],0x8
    //         004cbb3d     JZ         LAB_004cbcb6
    //         004cbb43     PUSH       0xa
    //         004cbb45     PUSH       ESI
    //         004cbb46     MOV        this,EAX
    //         004cbb48     CALL       TribeFishingShipUnitAIModule::TribeFishingShip   undefined TribeFishingShipUnitAIModule(TribeF
    //                              t_c_obj.cpp:1307 (3)
    //         004cbb4d     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbb50     MOV        this,dword ptr [ESP + local_c]
    //         004cbb54     MOV        dword ptr FS:[0x0],this
    //         004cbb5b     POP        ESI
    //         004cbb5c     ADD        ESP,0x10
    //         004cbb5f     RET
    //                               switchD_004cb902::caseD_2                                    XREF[2]:     004cb902(j), 004cbcd0(*)  
    //                              t_c_obj.cpp:1254 (43)
    //         004cbb60     PUSH       0x134
    //         004cbb65     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbb6a     ADD        ESP,0x4
    //         004cbb6d     MOV        dword ptr [ESP + local_10],EAX
    //         004cbb71     TEST       EAX,EAX
    //         004cbb73     MOV        dword ptr [ESP + local_4],0x9
    //         004cbb7b     JZ         LAB_004cbcb6
    //         004cbb81     PUSH       0xa
    //         004cbb83     PUSH       ESI
    //         004cbb84     MOV        this,EAX
    //         004cbb86     CALL       TribeTradeShipUnitAIModule::TribeTradeShipUnit   undefined TribeTradeShipUnitAIModule(TribeTra
    //                              t_c_obj.cpp:1307 (3)
    //         004cbb8b     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbb8e     MOV        this,dword ptr [ESP + local_c]
    //         004cbb92     MOV        dword ptr FS:[0x0],this
    //         004cbb99     POP        ESI
    //         004cbb9a     ADD        ESP,0x10
    //         004cbb9d     RET
    //                               switchD_004cb902::caseD_14                                   XREF[2]:     004cb902(j), 004cbcf8(*)  
    //                              t_c_obj.cpp:1258 (43)
    //         004cbb9e     PUSH       0x134
    //         004cbba3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbba8     ADD        ESP,0x4
    //         004cbbab     MOV        dword ptr [ESP + local_10],EAX
    //         004cbbaf     TEST       EAX,EAX
    //         004cbbb1     MOV        dword ptr [ESP + local_4],0xa
    //         004cbbb9     JZ         LAB_004cbcb6
    //         004cbbbf     PUSH       0xa
    //         004cbbc1     PUSH       ESI
    //         004cbbc2     MOV        this,EAX
    //         004cbbc4     CALL       TribeTransportShipUnitAIModule::TribeTransport   undefined TribeTransportShipUnitAIModule(Trib
    //                              t_c_obj.cpp:1307 (3)
    //         004cbbc9     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbbcc     MOV        this,dword ptr [ESP + local_c]
    //         004cbbd0     MOV        dword ptr FS:[0x0],this
    //         004cbbd7     POP        ESI
    //         004cbbd8     ADD        ESP,0x10
    //         004cbbdb     RET
    //                               switchD_004cb902::caseD_1b                                   XREF[3]:     004cb902(j), 004cbcd4(*), 
    //                               switchD_004cb902::caseD_3                                                 004cbd00(*)  
    //                              t_c_obj.cpp:1270 (40)
    //         004cbbdc     MOV        AX,word ptr [EAX + 0x10]
    //         004cbbe0     CMP        AX,0x4f
    //         004cbbe4     JZ         LAB_004cbc42
    //         004cbbe6     CMP        AX,0xc7
    //         004cbbea     JZ         LAB_004cbc42
    //         004cbbec     CMP        AX,0x45
    //         004cbbf0     JZ         LAB_004cbc42
    //         004cbbf2     CMP        AX,0x116
    //         004cbbf6     JZ         LAB_004cbc42
    //         004cbbf8     CMP        AX,0x17f
    //         004cbbfc     JZ         LAB_004cbc42
    //         004cbbfe     CMP        AX,0x17c
    //         004cbc02     JZ         LAB_004cbc42
    //                              t_c_obj.cpp:1273 (43)
    //         004cbc04     PUSH       0x134
    //         004cbc09     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbc0e     ADD        ESP,0x4
    //         004cbc11     MOV        dword ptr [ESP + local_10],EAX
    //         004cbc15     TEST       EAX,EAX
    //         004cbc17     MOV        dword ptr [ESP + local_4],0xc
    //         004cbc1f     JZ         LAB_004cbcb6
    //         004cbc25     PUSH       0xa
    //         004cbc27     PUSH       ESI
    //         004cbc28     MOV        this,EAX
    //         004cbc2a     CALL       TribeBuildingUnitAIModule::TribeBuildingUnitAI   undefined TribeBuildingUnitAIModule(TribeBuil
    //                              t_c_obj.cpp:1307 (3)
    //         004cbc2f     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbc32     MOV        this,dword ptr [ESP + local_c]
    //         004cbc36     MOV        dword ptr FS:[0x0],this
    //         004cbc3d     POP        ESI
    //         004cbc3e     ADD        ESP,0x10
    //         004cbc41     RET
    //                               LAB_004cbc42                                                 XREF[6]:     004cbbe4(j), 004cbbea(j), 
    //                                                                                                         004cbbf0(j), 004cbbf6(j), 
    //                                                                                                         004cbbfc(j), 004cbc02(j)  
    //                              t_c_obj.cpp:1271 (39)
    //         004cbc42     PUSH       0x134
    //         004cbc47     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbc4c     ADD        ESP,0x4
    //         004cbc4f     MOV        dword ptr [ESP + local_10],EAX
    //         004cbc53     TEST       EAX,EAX
    //         004cbc55     MOV        dword ptr [ESP + local_4],0xb
    //         004cbc5d     JZ         LAB_004cbcb6
    //         004cbc5f     PUSH       0xa
    //         004cbc61     PUSH       ESI
    //         004cbc62     MOV        this,EAX
    //         004cbc64     CALL       TribeTowerUnitAIModule::TribeTowerUnitAIModule   undefined TribeTowerUnitAIModule(TribeTowerUn
    //                              t_c_obj.cpp:1307 (3)
    //         004cbc69     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbc6c     MOV        this,dword ptr [ESP + local_c]
    //         004cbc70     MOV        dword ptr FS:[0x0],this
    //         004cbc77     POP        ESI
    //         004cbc78     ADD        ESP,0x10
    //         004cbc7b     RET
    //                               switchD_004cb902::caseD_c                                    XREF[3]:     004cb8f4(j), 004cb902(j), 
    //                               switchD_004cb902::caseD_d                                                 004cbd08(*)  
    //                               switchD_004cb902::caseD_11
    //                               switchD_004cb902::caseD_13
    //                               switchD_004cb902::caseD_16
    //                               switchD_004cb902::caseD_17
    //                               switchD_004cb902::caseD_18
    //                               switchD_004cb902::caseD_19
    //                               switchD_004cb902::caseD_1a
    //                               switchD_004cb902::caseD_1c
    //                               switchD_004cb902::caseD_6
    //                              t_c_obj.cpp:1307 (42)
    //         004cbc7c     PUSH       0x134
    //         004cbc81     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004cbc86     ADD        ESP,0x4
    //         004cbc89     MOV        dword ptr [ESP + local_10],EAX
    //         004cbc8d     TEST       EAX,EAX
    //         004cbc8f     MOV        dword ptr [ESP + local_4],0xd
    //         004cbc97     JZ         LAB_004cbcb6
    //         004cbc99     PUSH       0xa
    //         004cbc9b     PUSH       ESI
    //         004cbc9c     MOV        this,EAX
    //         004cbc9e     CALL       TribeSoldierUnitAIModule::TribeSoldierUnitAIMo   undefined TribeSoldierUnitAIModule(TribeSoldi
    //         004cbca3     MOV        dword ptr [ESI + 0x74],EAX
    //                              t_c_obj.cpp:1310 (16)
    //         004cbca6     MOV        this,dword ptr [ESP + local_c]
    //         004cbcaa     MOV        dword ptr FS:[0x0],this
    //         004cbcb1     POP        ESI
    //         004cbcb2     ADD        ESP,0x10
    //         004cbcb5     RET
    //                               LAB_004cbcb6                                                 XREF[14]:    004cb93c(j), 004cb97a(j), 
    //                                                                                                         004cb9b8(j), 004cb9f6(j), 
    //                                                                                                         004cba3e(j), 004cba82(j), 
    //                                                                                                         004cbac6(j), 004cbaff(j), 
    //                                                                                                         004cbb3d(j), 004cbb7b(j), 
    //                                                                                                         004cbbb9(j), 004cbc1f(j), 
    //                                                                                                         004cbc5d(j), 004cbc97(j)  
    //                              t_c_obj.cpp:1307 (5)
    //         004cbcb6     XOR        EAX,EAX
    //         004cbcb8     MOV        dword ptr [ESI + 0x74],EAX
    //                               switchD_004cb902::caseD_7                                    XREF[8]:     004cb902(j), 004cb911(j), 
    //                               switchD_004cb902::caseD_8                                                 004cb91b(j), 004cbcdc(*), 
    //                               switchD_004cb902::caseD_b                                                 004cbce0(*), 004cbcec(*), 
    //                               switchD_004cb902::caseD_e                                                 004cbcf0(*), 004cbd04(*)  
    //                               switchD_004cb902::caseD_f
    //                               switchD_004cb902::caseD_10
    //                               switchD_004cb902::caseD_1d
    //                               switchD_004cb902::caseD_1e
    //                               switchD_004cb902::caseD_1f
    //                               switchD_004cb902::caseD_20
    //                               switchD_004cb902::caseD_21
    //                               switchD_004cb902::caseD_5
    //                              t_c_obj.cpp:1310 (114)
    //         004cbcbb     MOV        this,dword ptr [ESP + local_c]
    //         004cbcbf     POP        ESI
    //         004cbcc0     MOV        dword ptr FS:[0x0],this
    //         004cbcc7     ADD        ESP,0x10
    //         004cbcca     RET
    //         004cbccb     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004cb902::switchdataD_004cbccc                       XREF[1]:     initUnitAI:004cb902(*)  
    //         004cbccc     addr       switchD_004cb902::caseD_1
    //         004cbcd0     addr       switchD_004cb902::caseD_2
    //         004cbcd4     addr       switchD_004cb902::caseD_3
    //         004cbcd8     addr       switchD_004cb902::caseD_4
    //         004cbcdc     addr       switchD_004cb902::caseD_5
    //         004cbce0     addr       switchD_004cb902::caseD_5
    //         004cbce4     addr       switchD_004cb902::caseD_9
    //         004cbce8     addr       switchD_004cb902::caseD_a
    //         004cbcec     addr       switchD_004cb902::caseD_5
    //         004cbcf0     addr       switchD_004cb902::caseD_5
    //         004cbcf4     addr       switchD_004cb902::caseD_12
    //         004cbcf8     addr       switchD_004cb902::caseD_14
    //         004cbcfc     addr       switchD_004cb902::caseD_15
    //         004cbd00     addr       switchD_004cb902::caseD_3
    //         004cbd04     addr       switchD_004cb902::caseD_5
    //                               PTR_caseD_6_004cbd08+3                                       XREF[0,1]:   initUnitAI:004cb8fc(*)  
    //         004cbd08     addr       switchD_004cb902::caseD_6
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004cb902::switchdataD_004cbd0c
    //         004cbd0c     db         0h
    //         004cbd0d     db         1h
    //         004cbd0e     db         2h
    //         004cbd0f     db         3h
    //         004cbd10     db         4h
    //         004cbd11     db         Fh
    //         004cbd12     db         5h
    //         004cbd13     db         5h
    //         004cbd14     db         6h
    //         004cbd15     db         7h
    //         004cbd16     db         8h
    //         004cbd17     db         Fh
    //         004cbd18     db         Fh
    //         004cbd19     db         9h
    //         004cbd1a     db         9h
    //         004cbd1b     db         9h
    //         004cbd1c     db         Fh
    //         004cbd1d     db         Ah
    //         004cbd1e     db         Fh
    //         004cbd1f     db         Bh
    //         004cbd20     db         Ch
    //         004cbd21     db         Fh
    //         004cbd22     db         Fh
    //         004cbd23     db         Fh
    //         004cbd24     db         Fh
    //         004cbd25     db         Fh
    //         004cbd26     db         Dh
    //         004cbd27     db         Fh
    //         004cbd28     db         Eh
    //         004cbd29     db         Eh
    //         004cbd2a     db         Eh
    //         004cbd2b     db         Eh
    //         004cbd2c     db         Eh
    //         004cbd2d     ??         90h
    //         004cbd2e     ??         90h
    //         004cbd2f     ??         90h
    //                              * int __cdecl lines_intersect(float,float,float,float,float,float,float,float)                          *
    //                              int __cdecl lines_intersect(float param_1, float param_2, float para
    //              int               EAX:4          <RETURN>
    //              float             Stack[0x4]:4   param_1
    //              float             Stack[0x8]:4   param_2
    //              float             Stack[0xc]:4   param_3
    //              float             Stack[0x10]:4  param_4
    //              float             Stack[0x14]:4  param_5
    //              float             Stack[0x18]:4  param_6
    //              float             Stack[0x1c]:4  param_7
    //              float             Stack[0x20]:4  param_8
    //                               ?lines_intersect@@YAHMMMMMMMM@Z                              XREF[1]:     higher_check_for_cliff:004cbe41(c)
    //                               lines_intersect
    //                              t_c_obj.cpp:1373 (5)
    //         004cbd30     MOV        EAX,0x1
    //                              t_c_obj.cpp:1375 (1)
    //         004cbd35     RET
    //         004cbd36     ??         90h
    //         004cbd37     NOP
    //         004cbd38     NOP
    //         004cbd39     NOP
    //         004cbd3a     NOP
    //         004cbd3b     NOP
    //         004cbd3c     NOP
    //         004cbd3d     NOP
    //         004cbd3e     NOP
    //         004cbd3f     NOP
    //                              * public: virtual int __thiscall TRIBE_Combat_Object::higher_check_for_cliff(class RGE_Static_Object... *
    //                              int __thiscall higher_check_for_cliff(TRIBE_Combat_Object * this, RG
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cbdc0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004cbd64(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004cbd41(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     004cbe2d(R), 004cbe31(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[2]:     004cbdf5(R), 004cbe1f(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[2]:     004cbe11(R), 004cbe36(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[2]:     004cbd95(R), 004cbe04(R)  
    //              RGE_Map *         Stack[0x20]:4  param_8                   XREF[1]:     004cbd57(R)  
    //              RGE_Static_Obj    Stack[0x24]:4  param_9                   XREF[2]:     004cbda9(R), 004cbdb5(W)  
    //              float *           Stack[0x28]:4  param_10                  XREF[1]:     004cbd91(R)  
    //              int *             Stack[0x2c]:4  param_11                  XREF[2]:     004cbeaf(R), 004cbec5(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004cbd4d(W), 004cbe4d(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     004cbe08(*)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     004cbe16(*)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     004cbe24(*)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     004cbe3a(*)  
    //                               ?higher_check_for_cliff@TRIBE_Combat_Object@@UAEHPAVRGE_Sta  XREF[2]:     005749c0(*), 00574c68(*)  
    //                               TRIBE_Combat_Object::higher_check_for_cliff
    //                              t_c_obj.cpp:1379 (1)
    //         004cbd40     PUSH       this
    //                              t_c_obj.cpp:1385 (56)
    //         004cbd41     MOV        EDX,dword ptr [ESP + param_3]
    //         004cbd45     PUSH       EBX
    //         004cbd46     PUSH       EBP
    //         004cbd47     PUSH       ESI
    //         004cbd48     MOV        ESI,this
    //         004cbd4a     PUSH       EDI
    //         004cbd4b     TEST       EDX,EDX
    //         004cbd4d     MOV        dword ptr [ESP + local_4],ESI
    //         004cbd51     JL         LAB_004cbedb
    //         004cbd57     MOV        this,dword ptr [ESP + param_8]
    //         004cbd5b     CMP        EDX,dword ptr [ECX + this->_padding_]
    //         004cbd5e     JGE        LAB_004cbedb
    //         004cbd64     MOV        EAX,dword ptr [ESP + param_2]
    //         004cbd68     TEST       EAX,EAX
    //         004cbd6a     JL         LAB_004cbedb
    //         004cbd70     CMP        EAX,dword ptr [ECX + this->_padding_]
    //         004cbd73     JGE        LAB_004cbedb
    //                              t_c_obj.cpp:1390 (32)
    //         004cbd79     MOV        this,dword ptr [this->_padding_ + 0x8d8c]
    //         004cbd7f     LEA        EAX,[EAX + EAX*0x2]
    //         004cbd82     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         004cbd85     MOV        EBX,dword ptr [ECX + EAX*0x8 + this->_padding_]
    //         004cbd89     TEST       EBX,EBX
    //         004cbd8b     JZ         LAB_004cbedb
    //         004cbd91     MOV        EDI,dword ptr [ESP + param_10]
    //         004cbd95     MOV        EBP,dword ptr [ESP + param_7]
    //                               LAB_004cbd99                                                 XREF[1]:     004cbe56(j)  
    //                              t_c_obj.cpp:1393 (2)
    //         004cbd99     MOV        this,dword ptr [EBX]
    //                              t_c_obj.cpp:1394 (14)
    //         004cbd9b     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004cbd9e     CMP        word ptr [EDX + 0x14],0x22
    //         004cbda3     JNZ        LAB_004cbe51
    //                              t_c_obj.cpp:1397 (10)
    //         004cbda9     CMP        this,dword ptr [ESP + param_9]
    //         004cbdad     JZ         LAB_004cbe51
    //                              t_c_obj.cpp:1402 (13)
    //         004cbdb3     MOV        EAX,dword ptr [EDI]
    //         004cbdb5     MOV        dword ptr [ESP + param_9],this
    //         004cbdb9     CMP        EAX,0xbf800000
    //         004cbdbe     JNZ        LAB_004cbdef
    //                              t_c_obj.cpp:1404 (20)
    //         004cbdc0     MOV        EAX,dword ptr [ESP + param_1]
    //         004cbdc4     FLD        float ptr [EAX + 0x38]
    //         004cbdc7     FLD        float ptr [EAX + 0x3c]
    //         004cbdca     FSUB       float ptr [ESI + 0x3c]
    //         004cbdcd     FXCH
    //         004cbdcf     FSUB       float ptr [ESI + 0x38]
    //         004cbdd2     FPATAN
    //                              t_c_obj.cpp:1405 (15)
    //         004cbdd4     FCOM       float ptr [DAT_00574c98]
    //         004cbdda     FST        float ptr [EDI]
    //         004cbddc     FNSTSW     AX
    //         004cbdde     TEST       AH,0x1
    //         004cbde1     JZ         LAB_004cbded
    //                              t_c_obj.cpp:1406 (10)
    //         004cbde3     FSUB       float ptr [DAT_00574ca4]                         = DBh
    //         004cbde9     FSTP       float ptr [EDI]
    //         004cbdeb     JMP        LAB_004cbdef
    //                               LAB_004cbded                                                 XREF[1]:     004cbde1(j)  
    //                              t_c_obj.cpp:1405 (2)
    //         004cbded     FSTP       ST0
    //                               LAB_004cbdef                                                 XREF[2]:     004cbdbe(j), 004cbdeb(j)  
    //                              t_c_obj.cpp:1412 (2)
    //         004cbdef     XOR        EAX,EAX
    //                              t_c_obj.cpp:1423 (96)
    //         004cbdf1     PUSH       this
    //         004cbdf2     MOV        AL,byte ptr [ECX + this+0x35]
    //         004cbdf5     MOV        EDX,dword ptr [ESP + param_5]
    //         004cbdf9     MOV        ESI,EAX
    //         004cbdfb     SHL        EAX,0x5
    //         004cbdfe     FLD        float ptr [EAX + DAT_00587274]
    //         004cbe04     FADD       float ptr [ESP + param_7]
    //         004cbe08     FSTP       float ptr [ESP]=>local_18
    //         004cbe0b     FLD        float ptr [EAX + DAT_00587270]
    //         004cbe11     FADD       float ptr [ESP + param_6]
    //         004cbe15     PUSH       this
    //         004cbe16     FSTP       float ptr [ESP]=>local_1c
    //         004cbe19     FLD        float ptr [EAX + DAT_0058726c]
    //         004cbe1f     FADD       float ptr [ESP + param_5]
    //         004cbe23     PUSH       this
    //         004cbe24     FSTP       float ptr [ESP]=>local_20
    //         004cbe27     FLD        float ptr [EAX + DAT_00587268]
    //         004cbe2d     FADD       float ptr [ESP + param_4]
    //         004cbe31     MOV        EAX,dword ptr [ESP + param_4]
    //         004cbe35     PUSH       this
    //         004cbe36     MOV        this,dword ptr [ESP + param_6]
    //         004cbe3a     FSTP       float ptr [ESP]=>local_24
    //         004cbe3d     PUSH       EBP
    //         004cbe3e     PUSH       this
    //         004cbe3f     PUSH       EDX
    //         004cbe40     PUSH       EAX
    //         004cbe41     CALL       lines_intersect                                  int lines_intersect(float param_1, float para
    //         004cbe46     ADD        ESP,0x20
    //         004cbe49     TEST       EAX,EAX
    //         004cbe4b     JNZ        LAB_004cbe66
    //         004cbe4d     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_004cbe51                                                 XREF[2]:     004cbda3(j), 004cbdad(j)  
    //                              t_c_obj.cpp:1390 (11)
    //         004cbe51     MOV        EBX,dword ptr [EBX + 0x4]
    //         004cbe54     TEST       EBX,EBX
    //         004cbe56     JNZ        LAB_004cbd99
    //                              t_c_obj.cpp:1386 (2)
    //         004cbe5c     XOR        EAX,EAX
    //                              t_c_obj.cpp:1442 (8)
    //         004cbe5e     POP        EDI
    //         004cbe5f     POP        ESI
    //         004cbe60     POP        EBP
    //         004cbe61     POP        EBX
    //         004cbe62     POP        this
    //         004cbe63     RET        0x2c
    //                               LAB_004cbe66                                                 XREF[1]:     004cbe4b(j)  
    //                              t_c_obj.cpp:1429 (73)
    //         004cbe66     CMP        ESI,0x19
    //         004cbe69     JGE        LAB_004cbe8e
    //         004cbe6b     FLD        float ptr [EDI]
    //         004cbe6d     MOV        this,ESI
    //         004cbe6f     SHL        this,0x5
    //         004cbe72     FCOMP      float ptr [this->_padding_ + TRIBE_Cliff_Highe   = 4048f5c3
    //         004cbe78     FNSTSW     AX
    //         004cbe7a     TEST       AH,0x1
    //         004cbe7d     JNZ        LAB_004cbe8e
    //         004cbe7f     FLD        float ptr [EDI]
    //         004cbe81     FCOMP      float ptr [this->_padding_ + DAT_0058725c]       = 52h    R
    //         004cbe87     FNSTSW     AX
    //         004cbe89     TEST       AH,0x41
    //         004cbe8c     JNZ        LAB_004cbeaf
    //                               LAB_004cbe8e                                                 XREF[2]:     004cbe69(j), 004cbe7d(j)  
    //         004cbe8e     FLD        float ptr [EDI]
    //         004cbe90     SHL        ESI,0x5
    //         004cbe93     FCOMP      float ptr [ESI + DAT_00587260]
    //         004cbe99     FNSTSW     AX
    //         004cbe9b     TEST       AH,0x1
    //         004cbe9e     JNZ        LAB_004cbec5
    //         004cbea0     FLD        float ptr [EDI]
    //         004cbea2     FCOMP      float ptr [ESI + DAT_00587264]
    //         004cbea8     FNSTSW     AX
    //         004cbeaa     TEST       AH,0x41
    //         004cbead     JZ         LAB_004cbec5
    //                               LAB_004cbeaf                                                 XREF[1]:     004cbe8c(j)  
    //                              t_c_obj.cpp:1431 (7)
    //         004cbeaf     MOV        EAX,dword ptr [ESP + param_11]
    //         004cbeb3     MOV        this,dword ptr [EAX]
    //         004cbeb5     INC        this
    //                              t_c_obj.cpp:1434 (2)
    //         004cbeb6     MOV        dword ptr [EAX],this
    //                              t_c_obj.cpp:1435 (5)
    //         004cbeb8     MOV        EAX,0x1
    //                              t_c_obj.cpp:1442 (8)
    //         004cbebd     POP        EDI
    //         004cbebe     POP        ESI
    //         004cbebf     POP        EBP
    //         004cbec0     POP        EBX
    //         004cbec1     POP        this
    //         004cbec2     RET        0x2c
    //                               LAB_004cbec5                                                 XREF[2]:     004cbe9e(j), 004cbead(j)  
    //                              t_c_obj.cpp:1434 (9)
    //         004cbec5     MOV        EAX,dword ptr [ESP + param_11]
    //         004cbec9     MOV        this,dword ptr [EAX]
    //         004cbecb     DEC        this
    //         004cbecc     MOV        dword ptr [EAX],this
    //                              t_c_obj.cpp:1435 (5)
    //         004cbece     MOV        EAX,0x1
    //                              t_c_obj.cpp:1442 (18)
    //         004cbed3     POP        EDI
    //         004cbed4     POP        ESI
    //         004cbed5     POP        EBP
    //         004cbed6     POP        EBX
    //         004cbed7     POP        this
    //         004cbed8     RET        0x2c
    //                               LAB_004cbedb                                                 XREF[5]:     004cbd51(j), 004cbd5e(j), 
    //                                                                                                         004cbd6a(j), 004cbd73(j), 
    //                                                                                                         004cbd8b(j)  
    //         004cbedb     POP        EDI
    //         004cbedc     POP        ESI
    //         004cbedd     POP        EBP
    //         004cbede     XOR        EAX,EAX
    //         004cbee0     POP        EBX
    //         004cbee1     POP        this
    //         004cbee2     RET        0x2c
    //         004cbee5     ??         90h
    //         004cbee6     NOP
    //         004cbee7     NOP
    //         004cbee8     NOP
    //         004cbee9     NOP
    //         004cbeea     NOP
    //         004cbeeb     NOP
    //         004cbeec     NOP
    //         004cbeed     NOP
    //         004cbeee     NOP
    //         004cbeef     NOP
    return;
}

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall higher_than_target(TRIBE_Combat_Object * this, RGE_St
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     004cbef8(R), 004cc0e3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004cc073(W), 004cc177(R), 004cc17c(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     004cc00b(W), 004cc027(W)  
    //              int               Stack[-0xc]:4  Tile_Dx2                  XREF[2]:     004cc00f(W), 004cc02f(W)  
    //              int               Stack[-0x10]:4 Tile_Dy2                  XREF[2]:     004cc007(W), 004cc01b(W)  
    //              int               Stack[-0x14]:4 Tile_Dx1                  XREF[2]:     004cbfff(W), 004cc023(W)  
    //              int               Stack[-0x18]:4 Tile_Dy1                  XREF[3]:     004cc048(W), 004cc0ad(R), 004cc0f2(W)  
    //              int               Stack[-0x1c]:4 PriorY                    XREF[3]:     004cc044(W), 004cc0a3(R), 004cc0ee(W)  
    //              int               Stack[-0x20]:4 PriorX                    XREF[7]:     004cbf98(W), 004cbf9c(R), 004cbfc4(W), 004cbfee(W), 
    //                                                                                     004cbff2(R), 004cc061(W), 004cc0c9(R)  
    //              int               Stack[-0x24]:4 NumSteps                  XREF[2]:     004cc059(W), 004cc0be(*)  
    //              float             Stack[-0x28]:4 AngleToTarget             XREF[4]:     004cc04f(W), 004cc07f(R), 004cc08f(W), 004cc098(R)  
    //              float             Stack[-0x2c]:4 YTile                     XREF[3]:     004cc03b(W), 004cc077(R), 004cc089(W)  
    //              float             Stack[-0x30]:4 XTile                     XREF[3]:     004cc069(W), 004cc0ba(*), 004cc186(R)  
    //              int               Stack[-0x34]:4 HigherCalc                XREF[3]:     004cbf1f(W), 004cbf27(R), 004cc0d2(R)  
    //              float             Stack[-0x38]:4 DestX                     XREF[3]:     004cbf35(W), 004cbf43(R), 004cc0cd(R)  
    //              float             Stack[-0x3c]:4 DestY                     XREF[5]:     004cbfba(W), 004cbfbe(R), 004cbfd7(R), 004cbfe8(R), 
    //                                                                                     004cc083(R)  
    //              float             Stack[-0x40]:4 YStep                     XREF[4]:     004cbfaa(W), 004cbfb4(R), 004cbfd1(R), 004cc07b(R)  
    //              float             Stack[-0x44]:4 XStep                     XREF[4]:     004cbf23(W), 004cbf2b(R), 004cc033(R), 004cc0de(R)  
    //              float             Stack[-0x48]:4 StartX                    XREF[4]:     004cbf39(W), 004cbf47(R), 004cc037(R), 004cc0d9(R)  
    //              float             Stack[-0x4c]:4 StartY
    //                               ?higher_than_target@TRIBE_Combat_Object@@UAEHPAVRGE_Static_  XREF[2]:     005749c4(*), 00574c6c(*)  
    //                               TRIBE_Combat_Object::higher_than_target
    //                              t_c_obj.cpp:1446 (8)
    //         004cbef0     SUB        ESP,0x48
    //         004cbef3     PUSH       EBX
    //         004cbef4     PUSH       EBP
    //         004cbef5     MOV        EBP,this
    //         004cbef7     PUSH       ESI
    //                              t_c_obj.cpp:1448 (18)
    //         004cbef8     MOV        this,dword ptr [ESP + param_1]
    //         004cbefc     PUSH       EDI
    //         004cbefd     FLD        float ptr [EBP + 0x40]
    //         004cbf00     FCOMP      float ptr [ECX + this->_padding_]
    //         004cbf03     FNSTSW     AX
    //         004cbf05     TEST       AH,0x41
    //         004cbf08     JNZ        LAB_004cbf19
    //                              t_c_obj.cpp:1449 (5)
    //         004cbf0a     MOV        EAX,0x1
    //                              t_c_obj.cpp:1549 (10)
    //         004cbf0f     POP        EDI
    //         004cbf10     POP        ESI
    //         004cbf11     POP        EBP
    //         004cbf12     POP        EBX
    //         004cbf13     ADD        ESP,0x48
    //         004cbf16     RET        0x4
    //                               LAB_004cbf19                                                 XREF[1]:     004cbf08(j)  
    //                              t_c_obj.cpp:1467 (3)
    //         004cbf19     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              t_c_obj.cpp:1470 (22)
    //         004cbf1c     MOV        EDX,dword ptr [EBP + 0x38]
    //         004cbf1f     MOV        dword ptr [ESP + HigherCalc],EAX
    //         004cbf23     MOV        dword ptr [ESP + XStep],EDX
    //         004cbf27     FLD        float ptr [ESP + HigherCalc]
    //         004cbf2b     FSUB       float ptr [ESP + XStep]
    //         004cbf2f     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              t_c_obj.cpp:1474 (49)
    //         004cbf32     MOV        this,dword ptr [EBP + 0x3c]
    //         004cbf35     MOV        dword ptr [ESP + DestX],EAX
    //         004cbf39     MOV        dword ptr [ESP + StartX],this
    //         004cbf3d     FCOM       float ptr [DAT_00574c98]
    //         004cbf43     FLD        float ptr [ESP + DestX]
    //         004cbf47     FSUB       float ptr [ESP + StartX]
    //         004cbf4b     FNSTSW     AX
    //         004cbf4d     TEST       AH,0x40
    //         004cbf50     JZ         LAB_004cbf6f
    //         004cbf52     FCOM       float ptr [DAT_00574c98]
    //         004cbf58     FNSTSW     AX
    //         004cbf5a     TEST       AH,0x40
    //         004cbf5d     JZ         LAB_004cbf6f
    //         004cbf5f     FSTP       ST0
    //         004cbf61     FSTP       ST0
    //                              t_c_obj.cpp:1475 (2)
    //         004cbf63     XOR        EAX,EAX
    //                              t_c_obj.cpp:1549 (10)
    //         004cbf65     POP        EDI
    //         004cbf66     POP        ESI
    //         004cbf67     POP        EBP
    //         004cbf68     POP        EBX
    //         004cbf69     ADD        ESP,0x48
    //         004cbf6c     RET        0x4
    //                               LAB_004cbf6f                                                 XREF[2]:     004cbf50(j), 004cbf5d(j)  
    //                              t_c_obj.cpp:1478 (21)
    //         004cbf6f     FLD        ST0
    //         004cbf71     FLD        ST2
    //         004cbf73     FXCH
    //         004cbf75     FABS
    //         004cbf77     FXCH
    //         004cbf79     FABS
    //         004cbf7b     FCOMPP
    //         004cbf7d     FNSTSW     AX
    //         004cbf7f     TEST       AH,0x1
    //         004cbf82     JZ         LAB_004cbf88
    //                              t_c_obj.cpp:1479 (2)
    //         004cbf84     FLD        ST0
    //                              t_c_obj.cpp:1480 (2)
    //         004cbf86     JMP        LAB_004cbf8a
    //                               LAB_004cbf88                                                 XREF[1]:     004cbf82(j)  
    //                              t_c_obj.cpp:1481 (20)
    //         004cbf88     FLD        ST1
    //                               LAB_004cbf8a                                                 XREF[1]:     004cbf86(j)  
    //         004cbf8a     CALL       __ftol                                           undefined __ftol()
    //         004cbf8f     CDQ
    //         004cbf90     MOV        this,EAX
    //         004cbf92     XOR        this,EDX
    //         004cbf94     SUB        this,EDX
    //         004cbf96     SHL        this,0x1
    //         004cbf98     MOV        dword ptr [ESP + PriorX],this
    //                              t_c_obj.cpp:1483 (4)
    //         004cbf9c     FILD       dword ptr [ESP + PriorX]
    //                              t_c_obj.cpp:1484 (14)
    //         004cbfa0     FXCH       ST2
    //         004cbfa2     FDIV       ST0,ST2
    //         004cbfa4     FXCH
    //         004cbfa6     FDIV       ST0,ST2
    //         004cbfa8     FXCH
    //         004cbfaa     FST        float ptr [ESP + YStep]
    //                              t_c_obj.cpp:1491 (41)
    //         004cbfae     FCOMP      float ptr [DAT_00574c98]
    //         004cbfb4     FLD        float ptr [ESP + YStep]
    //         004cbfb8     FXCH
    //         004cbfba     FSTP       float ptr [ESP + DestY]
    //         004cbfbe     MOV        EDX,dword ptr [ESP + DestY]
    //         004cbfc2     FNSTSW     AX
    //         004cbfc4     MOV        dword ptr [ESP + PriorX],EDX
    //         004cbfc8     TEST       AH,0x1
    //         004cbfcb     FSTP       ST1
    //         004cbfcd     JZ         LAB_004cbfd7
    //         004cbfcf     FSTP       ST0
    //         004cbfd1     FLD        float ptr [ESP + YStep]
    //         004cbfd5     FCHS
    //                               LAB_004cbfd7                                                 XREF[1]:     004cbfcd(j)  
    //                              t_c_obj.cpp:1492 (27)
    //         004cbfd7     FLD        float ptr [ESP + DestY]
    //         004cbfdb     FCOMP      float ptr [DAT_00574c98]
    //         004cbfe1     FNSTSW     AX
    //         004cbfe3     TEST       AH,0x1
    //         004cbfe6     JZ         LAB_004cbff2
    //         004cbfe8     FLD        float ptr [ESP + DestY]
    //         004cbfec     FCHS
    //         004cbfee     FSTP       float ptr [ESP + PriorX]
    //                               LAB_004cbff2                                                 XREF[1]:     004cbfe6(j)  
    //                              t_c_obj.cpp:1494 (11)
    //         004cbff2     FCOMP      float ptr [ESP + PriorX]
    //         004cbff6     FNSTSW     AX
    //         004cbff8     TEST       AH,0x41
    //         004cbffb     JNZ        LAB_004cc019
    //                              t_c_obj.cpp:1496 (14)
    //         004cbffd     XOR        EAX,EAX
    //         004cbfff     MOV        dword ptr [ESP + Tile_Dx1],0xffffffff
    //         004cc007     MOV        dword ptr [ESP + Tile_Dy2],EAX
    //                              t_c_obj.cpp:1497 (12)
    //         004cc00b     MOV        dword ptr [ESP + local_8],EAX
    //         004cc00f     MOV        dword ptr [ESP + Tile_Dx2],0x1
    //                              t_c_obj.cpp:1499 (2)
    //         004cc017     JMP        LAB_004cc033
    //                               LAB_004cc019                                                 XREF[1]:     004cbffb(j)  
    //                              t_c_obj.cpp:1501 (14)
    //         004cc019     XOR        EAX,EAX
    //         004cc01b     MOV        dword ptr [ESP + Tile_Dy2],0xffffffff
    //         004cc023     MOV        dword ptr [ESP + Tile_Dx1],EAX
    //                              t_c_obj.cpp:1502 (12)
    //         004cc027     MOV        dword ptr [ESP + local_8],0x1
    //         004cc02f     MOV        dword ptr [ESP + Tile_Dx2],EAX
    //                               LAB_004cc033                                                 XREF[1]:     004cc017(j)  
    //                              t_c_obj.cpp:1506 (4)
    //         004cc033     MOV        EAX,dword ptr [ESP + XStep]
    //                              t_c_obj.cpp:1507 (8)
    //         004cc037     MOV        EDX,dword ptr [ESP + StartX]
    //         004cc03b     MOV        dword ptr [ESP + YTile],EAX
    //                              t_c_obj.cpp:1509 (9)
    //         004cc03f     MOV        EAX,0xfffffc19
    //         004cc044     MOV        dword ptr [ESP + PriorY],EAX
    //                              t_c_obj.cpp:1510 (4)
    //         004cc048     MOV        dword ptr [ESP + Tile_Dy1],EAX
    //                              t_c_obj.cpp:1512 (13)
    //         004cc04c     MOV        EAX,dword ptr [EBP + 0xc]
    //         004cc04f     MOV        dword ptr [ESP + AngleToTarget],EDX
    //         004cc053     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004cc056     MOV        EAX,dword ptr [EDX + 0x28]
    //                              t_c_obj.cpp:1516 (14)
    //         004cc059     MOV        dword ptr [ESP + NumSteps],0xbf800000
    //         004cc061     MOV        dword ptr [ESP + PriorX],EAX
    //         004cc065     XOR        EAX,EAX
    //                              t_c_obj.cpp:1518 (12)
    //         004cc067     TEST       this,this
    //         004cc069     MOV        dword ptr [ESP + XTile],EAX
    //         004cc06d     JLE        LAB_004cc18a
    //                              t_c_obj.cpp:1506 (4)
    //         004cc073     MOV        dword ptr [ESP + local_4],this
    //                               LAB_004cc077                                                 XREF[1]:     004cc180(j)  
    //                              t_c_obj.cpp:1520 (8)
    //         004cc077     FLD        float ptr [ESP + YTile]
    //         004cc07b     FADD       float ptr [ESP + YStep]
    //                              t_c_obj.cpp:1521 (16)
    //         004cc07f     FLD        float ptr [ESP + AngleToTarget]
    //         004cc083     FADD       float ptr [ESP + DestY]
    //         004cc087     FXCH
    //         004cc089     FST        float ptr [ESP + YTile]
    //         004cc08d     FXCH
    //                              t_c_obj.cpp:1523 (9)
    //         004cc08f     FSTP       float ptr [ESP + AngleToTarget]
    //         004cc093     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:1524 (11)
    //         004cc098     FLD        float ptr [ESP + AngleToTarget]
    //         004cc09c     MOV        ESI,EAX
    //         004cc09e     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:1526 (20)
    //         004cc0a3     MOV        this,dword ptr [ESP + PriorY]
    //         004cc0a7     MOV        EDI,EAX
    //         004cc0a9     CMP        ESI,this
    //         004cc0ab     JNZ        LAB_004cc0b7
    //         004cc0ad     CMP        EDI,dword ptr [ESP + Tile_Dy1]
    //         004cc0b1     JZ         LAB_004cc177
    //                               LAB_004cc0b7                                                 XREF[1]:     004cc0ab(j)  
    //                              t_c_obj.cpp:1536 (69)
    //         004cc0b7     MOV        this,dword ptr [EBP]
    //         004cc0ba     LEA        EDX=>XTile,[ESP + 0x28]
    //         004cc0be     LEA        EAX=>NumSteps,[ESP + 0x34]
    //         004cc0c2     PUSH       EDX
    //         004cc0c3     MOV        EBX,dword ptr [this->_padding_ + 0x248]
    //         004cc0c9     MOV        this,dword ptr [ESP + PriorX]
    //         004cc0cd     MOV        EDX,dword ptr [ESP + DestX]
    //         004cc0d1     PUSH       EAX
    //         004cc0d2     MOV        EAX,dword ptr [ESP + HigherCalc]
    //         004cc0d6     PUSH       0x0
    //         004cc0d8     PUSH       this
    //         004cc0d9     MOV        this,dword ptr [ESP + StartX]
    //         004cc0dd     PUSH       EDX
    //         004cc0de     MOV        EDX,dword ptr [ESP + XStep]
    //         004cc0e2     PUSH       EAX
    //         004cc0e3     MOV        EAX,dword ptr [ESP + param_1]
    //         004cc0e7     PUSH       this
    //         004cc0e8     PUSH       EDX
    //         004cc0e9     PUSH       EDI
    //         004cc0ea     PUSH       ESI
    //         004cc0eb     PUSH       EAX
    //         004cc0ec     MOV        this,EBP
    //         004cc0ee     MOV        dword ptr [ESP + PriorY],ESI
    //         004cc0f2     MOV        dword ptr [ESP + Tile_Dy1],EDI
    //         004cc0f6     CALL       EBX
    //         004cc0f8     TEST       EAX,EAX
    //         004cc0fa     JNZ        LAB_004cc177
    //                              t_c_obj.cpp:1537 (63)
    //         004cc0fc     LEA        this,[ESP + 0x28]
    //         004cc100     LEA        EDX,[ESP + 0x34]
    //         004cc104     PUSH       this
    //         004cc105     MOV        this,dword ptr [ESP + 0x24]
    //         004cc109     PUSH       EDX=>DAT_fffffff8
    //         004cc10a     MOV        EDX,dword ptr [ESP + 0x2c]
    //         004cc10e     PUSH       EAX=>DAT_fffffff4
    //         004cc10f     MOV        EAX,dword ptr [ESP + 0x44]
    //         004cc113     PUSH       EAX=>DAT_fffffff0
    //         004cc114     MOV        EAX,dword ptr [ESP + 0x20]
    //         004cc118     PUSH       this
    //         004cc119     MOV        this,dword ptr [ESP + 0x28]
    //         004cc11d     PUSH       EDX
    //         004cc11e     MOV        EDX,dword ptr [ESP + 0x5c]
    //         004cc122     PUSH       EAX
    //         004cc123     MOV        EAX,dword ptr [ESP + 0x64]
    //         004cc127     ADD        EDX,EDI
    //         004cc129     PUSH       this
    //         004cc12a     MOV        this,dword ptr [ESP + 0x7c]
    //         004cc12e     ADD        EAX,ESI
    //         004cc130     PUSH       EDX
    //         004cc131     PUSH       EAX
    //         004cc132     PUSH       this
    //         004cc133     MOV        this,EBP
    //         004cc135     CALL       EBX
    //         004cc137     TEST       EAX,EAX
    //         004cc139     JNZ        LAB_004cc177
    //                              t_c_obj.cpp:1538 (75)
    //         004cc13b     MOV        this,dword ptr [ESP + 0x38]
    //         004cc13f     LEA        EDX,[ESP + 0x28]
    //         004cc143     LEA        EAX,[ESP + 0x34]
    //         004cc147     PUSH       EDX
    //         004cc148     MOV        EDX,dword ptr [ESP + 0x24]
    //         004cc14c     PUSH       EAX=>DAT_fffffff8
    //         004cc14d     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004cc151     PUSH       0x0=>DAT_fffffff4
    //         004cc153     PUSH       this=>DAT_fffffff0
    //         004cc154     MOV        this,dword ptr [ESP + 0x20]
    //         004cc158     PUSH       EDX
    //         004cc159     MOV        EDX,dword ptr [ESP + 0x28]
    //         004cc15d     PUSH       EAX
    //         004cc15e     MOV        EAX,dword ptr [ESP + 0x64]
    //         004cc162     PUSH       this
    //         004cc163     MOV        this,dword ptr [ESP + 0x6c]
    //         004cc167     ADD        EAX,EDI
    //         004cc169     PUSH       EDX
    //         004cc16a     MOV        EDX,dword ptr [ESP + 0x7c]
    //         004cc16e     ADD        this,ESI
    //         004cc170     PUSH       EAX
    //         004cc171     PUSH       this
    //         004cc172     PUSH       EDX
    //         004cc173     MOV        this,EBP
    //         004cc175     CALL       EBX
    //                               LAB_004cc177                                                 XREF[3]:     004cc0b1(j), 004cc0fa(j), 
    //                                                                                                         004cc139(j)  
    //         004cc177     MOV        EAX,dword ptr [ESP + local_4]
    //         004cc17b     DEC        EAX
    //         004cc17c     MOV        dword ptr [ESP + local_4],EAX
    //         004cc180     JNZ        LAB_004cc077
    //                              t_c_obj.cpp:1518 (4)
    //         004cc186     MOV        EAX,dword ptr [ESP + XTile]
    //                               LAB_004cc18a                                                 XREF[1]:     004cc06d(j)  
    //                              t_c_obj.cpp:1543 (5)
    //         004cc18a     CMP        EAX,0x1
    //         004cc18d     JGE        LAB_004cc191
    //                              t_c_obj.cpp:1544 (2)
    //         004cc18f     XOR        EAX,EAX
    //                               LAB_004cc191                                                 XREF[1]:     004cc18d(j)  
    //                              t_c_obj.cpp:1545 (4)
    //         004cc191     TEST       EAX,EAX
    //         004cc193     JLE        LAB_004cc19a
    //                              t_c_obj.cpp:1546 (5)
    //         004cc195     MOV        EAX,0x1
    //                               LAB_004cc19a                                                 XREF[1]:     004cc193(j)  
    //                              t_c_obj.cpp:1548 (2)
    //         004cc19a     XOR        this,this
    //                              t_c_obj.cpp:1549 (17)
    //         004cc19c     POP        EDI
    //         004cc19d     TEST       EAX,EAX
    //         004cc19f     SETG       this
    //         004cc1a2     POP        ESI
    //         004cc1a3     POP        EBP
    //         004cc1a4     MOV        EAX,this
    //         004cc1a6     POP        EBX
    //         004cc1a7     ADD        ESP,0x48
    //         004cc1aa     RET        0x4
    //         004cc1ad     ??         90h
    //         004cc1ae     NOP
    //         004cc1af     NOP
    //                              * protected: virtual unsigned char __thiscall TRIBE_Combat_Object::area_attack(float,float,float,cla... *
    //                              uchar __thiscall area_attack(TRIBE_Combat_Object * this, float param
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[3]:     004cc1fc(R), 004cc20a(R), 004cc337(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[3]:     004cc21a(R), 004cc22c(R), 004cc33e(R)  
    //              float             Stack[0xc]:4   param_3
    //              RGE_Combat_Obj    Stack[0x10]:4  param_4
    //              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     004cc2dc(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004cc1da(W), 004cc3c2(R)  
    //              float             Stack[-0x8]:4  r2                        XREF[2]:     004cc1ce(W), 004cc2bc(R)  
    //              RGE_Map *         Stack[-0xc]:4  map                       XREF[3]:     004cc291(W), 004cc496(R), 004cc4a2(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     004cc2b8(W), 004cc47c(R), 004cc488(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     004cc2b4(W), 004cc478(R), 004cc484(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[3]:     004cc37c(W), 004cc39f(R), 004cc3ae(R)  
    //              float             Stack[-0x1c]:4 ry                        XREF[4]:     004cc28d(W), 004cc2c6(R), 004cc492(R), 004cc49e(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     004cc223(W), 004cc24e(R), 004cc25c(W), 004cc299(R)  
    //              short             Stack[-0x24]:2 x1                        XREF[4]:     004cc211(W), 004cc23e(R), 004cc246(W), 004cc295(R)  
    //              short             Stack[-0x28]:2 x0                        XREF[6]:     004cc34a(W), 004cc357(R), 004cc368(R), 004cc36e(W), 
    //                                                                                     004cc39b(R), 004cc3aa(R)  
    //              float             Stack[-0x2c]:4 attack_modifier
    //                               ?area_attack@TRIBE_Combat_Object@@MAEEMMMPAVRGE_Combat_Obje  XREF[2]:     00574994(*), 00574c3c(*)  
    //                               TRIBE_Combat_Object::area_attack
    //                              t_c_obj.cpp:1556 (8)
    //         004cc1b0     SUB        ESP,0x28
    //         004cc1b3     PUSH       EBX
    //         004cc1b4     PUSH       EBP
    //         004cc1b5     PUSH       EDI
    //         004cc1b6     MOV        EDI,this
    //                              t_c_obj.cpp:1567 (15)
    //         004cc1b8     MOV        EDX,dword ptr [EDI + 0x8]
    //         004cc1bb     MOV        EAX,dword ptr [EDI + 0xc]
    //         004cc1be     FLD        float ptr [EDX + 0x118]
    //         004cc1c4     MOV        this,dword ptr [EAX + 0x3c]
    //                              t_c_obj.cpp:1573 (27)
    //         004cc1c7     FLD        ST0
    //         004cc1c9     FMUL       ST1
    //         004cc1cb     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cc1ce     MOV        dword ptr [ESP + r2],EAX
    //         004cc1d2     MOV        BX,word ptr [EAX + 0x8]
    //         004cc1d6     MOV        BP,word ptr [EAX + 0xc]
    //         004cc1da     FSTP       float ptr [ESP + local_4]
    //         004cc1de     DEC        BX
    //         004cc1e0     DEC        BP
    //                              t_c_obj.cpp:1579 (15)
    //         004cc1e2     FCOM       double ptr [DAT_00574ca8]
    //         004cc1e8     FNSTSW     AX
    //         004cc1ea     TEST       AH,0x41
    //         004cc1ed     JZ         LAB_004cc1fc
    //         004cc1ef     FSTP       ST0
    //                              t_c_obj.cpp:1580 (2)
    //         004cc1f1     XOR        AL,AL
    //                              t_c_obj.cpp:1633 (9)
    //         004cc1f3     POP        EDI
    //         004cc1f4     POP        EBP
    //         004cc1f5     POP        EBX
    //         004cc1f6     ADD        ESP,0x28
    //         004cc1f9     RET        0x14
    //                               LAB_004cc1fc                                                 XREF[1]:     004cc1ed(j)  
    //                              t_c_obj.cpp:1582 (12)
    //         004cc1fc     FLD        float ptr [ESP + param_1]
    //         004cc200     FSUB       ST0,ST1
    //         004cc202     PUSH       ESI
    //         004cc203     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:1583 (18)
    //         004cc208     FLD        ST0
    //         004cc20a     FADD       float ptr [ESP + param_1]
    //         004cc20e     SUB        EAX,0x2
    //         004cc211     MOV        dword ptr [ESP + x1],EAX
    //         004cc215     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:1584 (18)
    //         004cc21a     FLD        float ptr [ESP + param_2]
    //         004cc21e     FSUB       ST0,ST1
    //         004cc220     ADD        EAX,0x2
    //         004cc223     MOV        dword ptr [ESP + local_20],EAX
    //         004cc227     CALL       __ftol                                           undefined __ftol()
    //                              t_c_obj.cpp:1585 (18)
    //         004cc22c     FADD       float ptr [ESP + param_2]
    //         004cc230     MOV        SI,AX
    //         004cc233     SUB        ESI,0x2
    //         004cc236     CALL       __ftol                                           undefined __ftol()
    //         004cc23b     ADD        EAX,0x2
    //                              t_c_obj.cpp:1587 (16)
    //         004cc23e     CMP        word ptr [ESP + x1],0x0
    //         004cc244     JGE        LAB_004cc24e
    //         004cc246     MOV        dword ptr [ESP + x1],0x0
    //                               LAB_004cc24e                                                 XREF[1]:     004cc244(j)  
    //                              t_c_obj.cpp:1588 (18)
    //         004cc24e     MOVSX      EDX,word ptr [ESP + local_20]
    //         004cc253     MOVSX      this,BX
    //         004cc256     INC        this
    //         004cc257     CMP        EDX,this
    //         004cc259     JLE        LAB_004cc260
    //         004cc25b     INC        EBX
    //         004cc25c     MOV        dword ptr [ESP + local_20],EBX
    //                               LAB_004cc260                                                 XREF[1]:     004cc259(j)  
    //                              t_c_obj.cpp:1589 (7)
    //         004cc260     TEST       SI,SI
    //         004cc263     JGE        LAB_004cc267
    //         004cc265     XOR        ESI,ESI
    //                               LAB_004cc267                                                 XREF[1]:     004cc263(j)  
    //                              t_c_obj.cpp:1590 (14)
    //         004cc267     MOVSX      this,BP
    //         004cc26a     MOVSX      EDX,AX
    //         004cc26d     INC        this
    //         004cc26e     CMP        EDX,this
    //         004cc270     JLE        LAB_004cc275
    //         004cc272     LEA        EAX,[EBP + 0x1]
    //                               LAB_004cc275                                                 XREF[1]:     004cc270(j)  
    //                              t_c_obj.cpp:1592 (32)
    //         004cc275     CMP        SI,AX
    //         004cc278     JGE        LAB_004cc4ac
    //         004cc27e     MOVSX      this,SI
    //         004cc281     MOVSX      EAX,AX
    //         004cc284     LEA        EDX,[this->_padding_*0x4 + 0x0]
    //         004cc28b     SUB        EAX,this
    //         004cc28d     MOV        dword ptr [ESP + ry],EDX
    //         004cc291     MOV        dword ptr [ESP + map],EAX
    //                               LAB_004cc295                                                 XREF[1]:     004cc4a6(j)  
    //                              t_c_obj.cpp:1593 (39)
    //         004cc295     MOV        EAX,dword ptr [ESP + x1]
    //         004cc299     MOV        EDX,dword ptr [ESP + local_20]
    //         004cc29d     CMP        AX,DX
    //         004cc2a0     JGE        LAB_004cc492
    //         004cc2a6     MOVSX      EAX,AX
    //         004cc2a9     MOVSX      EDX,DX
    //         004cc2ac     LEA        this,[EAX + EAX*0x2]
    //         004cc2af     SHL        this,0x3
    //         004cc2b2     SUB        EDX,EAX
    //         004cc2b4     MOV        dword ptr [ESP + local_14],this
    //         004cc2b8     MOV        dword ptr [ESP + local_10],EDX
    //                               LAB_004cc2bc                                                 XREF[1]:     004cc48c(j)  
    //                              t_c_obj.cpp:1594 (29)
    //         004cc2bc     MOV        EAX,dword ptr [ESP + r2]
    //         004cc2c0     MOV        EDX,dword ptr [EAX + 0x8d8c]
    //         004cc2c6     MOV        EAX,dword ptr [ESP + ry]
    //         004cc2ca     MOV        EDX,dword ptr [EAX + EDX*0x1]
    //         004cc2cd     MOV        EBP,dword ptr [EDX + this->_padding_*0x1 + 0x10]
    //         004cc2d1     TEST       EBP,EBP
    //         004cc2d3     JZ         LAB_004cc47c
    //                               LAB_004cc2d9                                                 XREF[1]:     004cc472(j)  
    //                              t_c_obj.cpp:1597 (3)
    //         004cc2d9     MOV        ESI,dword ptr [EBP]
    //                              t_c_obj.cpp:1598 (12)
    //         004cc2dc     MOV        EAX,dword ptr [ESP + param_5]
    //         004cc2e0     CMP        ESI,EAX
    //         004cc2e2     JZ         LAB_004cc46d
    //                              t_c_obj.cpp:1600 (31)
    //         004cc2e8     MOV        EDX,dword ptr [EDI + 0x8]
    //         004cc2eb     MOV        AX,word ptr [EDX + 0x10]
    //         004cc2ef     CMP        AX,0x2e
    //         004cc2f3     JZ         LAB_004cc307
    //         004cc2f5     CMP        AX,0x28
    //         004cc2f9     JZ         LAB_004cc307
    //         004cc2fb     CMP        AX,0x153
    //         004cc2ff     JZ         LAB_004cc307
    //         004cc301     CMP        AX,0x159
    //         004cc305     JNZ        LAB_004cc315
    //                               LAB_004cc307                                                 XREF[3]:     004cc2f3(j), 004cc2f9(j), 
    //                                                                                                         004cc2ff(j)  
    //                              t_c_obj.cpp:1601 (14)
    //         004cc307     MOV        EAX,dword ptr [ESI + 0xc]
    //         004cc30a     MOV        this,dword ptr [EDI + 0xc]
    //         004cc30d     CMP        EAX,this
    //         004cc30f     JZ         LAB_004cc46d
    //                               LAB_004cc315                                                 XREF[1]:     004cc305(j)  
    //                              t_c_obj.cpp:1604 (31)
    //         004cc315     CMP        ESI,EDI
    //         004cc317     JZ         LAB_004cc46d
    //         004cc31d     MOV        this,dword ptr [ESI + 0x8]
    //         004cc320     MOV        BL,byte ptr [EDX + 0x11c]
    //         004cc326     MOV        AL,byte ptr [ECX + this+0x8b]
    //         004cc32c     CMP        AL,BL
    //         004cc32e     JC         LAB_004cc46d
    //                              t_c_obj.cpp:1607 (7)
    //         004cc334     FLD        float ptr [ESI + 0x38]
    //         004cc337     FSUB       float ptr [ESP + param_1]
    //                              t_c_obj.cpp:1608 (7)
    //         004cc33b     FLD        float ptr [ESI + 0x3c]
    //         004cc33e     FSUB       float ptr [ESP + param_2]
    //                              t_c_obj.cpp:1610 (21)
    //         004cc342     FLD        ST1
    //         004cc344     FCOMP      float ptr [DAT_00574c98]
    //         004cc34a     FSTP       float ptr [ESP + x0]
    //         004cc34e     FNSTSW     AX
    //         004cc350     TEST       AH,0x1
    //         004cc353     JZ         LAB_004cc357
    //         004cc355     FCHS
    //                               LAB_004cc357                                                 XREF[1]:     004cc353(j)  
    //                              t_c_obj.cpp:1611 (27)
    //         004cc357     FLD        float ptr [ESP + x0]
    //         004cc35b     FCOMP      float ptr [DAT_00574c98]
    //         004cc361     FNSTSW     AX
    //         004cc363     TEST       AH,0x1
    //         004cc366     JZ         LAB_004cc372
    //         004cc368     FLD        float ptr [ESP + x0]
    //         004cc36c     FCHS
    //         004cc36e     FSTP       float ptr [ESP + x0]
    //                               LAB_004cc372                                                 XREF[1]:     004cc366(j)  
    //                              t_c_obj.cpp:1612 (3)
    //         004cc372     FLD        float ptr [ECX + this->_padding_]
    //                              t_c_obj.cpp:1614 (38)
    //         004cc375     FLD        ST1
    //         004cc377     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cc37a     FCOMP
    //         004cc37c     MOV        dword ptr [ESP + local_18],this
    //         004cc380     FNSTSW     AX
    //         004cc382     TEST       AH,0x41
    //         004cc385     JNZ        LAB_004cc391
    //         004cc387     FXCH
    //         004cc389     FSUB       ST0,ST1
    //         004cc38b     FXCH
    //         004cc38d     FSTP       ST0
    //         004cc38f     JMP        LAB_004cc39b
    //                               LAB_004cc391                                                 XREF[1]:     004cc385(j)  
    //         004cc391     FSTP       ST0
    //         004cc393     FSTP       ST0
    //         004cc395     FLD        float ptr [DAT_00574c98]
    //                               LAB_004cc39b                                                 XREF[1]:     004cc38f(j)  
    //                              t_c_obj.cpp:1615 (31)
    //         004cc39b     FLD        float ptr [ESP + x0]
    //         004cc39f     FCOMP      float ptr [ESP + local_18]
    //         004cc3a3     FNSTSW     AX
    //         004cc3a5     TEST       AH,0x41
    //         004cc3a8     JNZ        LAB_004cc3b4
    //         004cc3aa     FLD        float ptr [ESP + x0]
    //         004cc3ae     FSUB       float ptr [ESP + local_18]
    //         004cc3b2     JMP        LAB_004cc3ba
    //                               LAB_004cc3b4                                                 XREF[1]:     004cc3a8(j)  
    //         004cc3b4     FLD        float ptr [DAT_00574c98]
    //                               LAB_004cc3ba                                                 XREF[1]:     004cc3b2(j)  
    //                              t_c_obj.cpp:1617 (37)
    //         004cc3ba     FLD        ST1
    //         004cc3bc     FLD        ST1
    //         004cc3be     FXCH
    //         004cc3c0     FMUL       ST3
    //         004cc3c2     FLD        float ptr [ESP + local_4]
    //         004cc3c6     FXCH       ST2
    //         004cc3c8     FMUL       ST3
    //         004cc3ca     FADDP
    //         004cc3cc     FXCH
    //         004cc3ce     FCOMPP
    //         004cc3d0     FNSTSW     AX
    //         004cc3d2     FSTP       ST0
    //         004cc3d4     TEST       AH,0x41
    //         004cc3d7     FSTP       ST0
    //         004cc3d9     JNZ        LAB_004cc46d
    //                              t_c_obj.cpp:1619 (36)
    //         004cc3df     PUSH       0x653
    //         004cc3e4     PUSH       s_C:\msdev\work\age1_x1\t_c_obj.cp               = "C:\\msdev\\work\\age1_x1\\t_c_obj.cpp"
    //         004cc3e9     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004cc3ee     LEA        EAX,[EAX + EAX*0x4]
    //         004cc3f1     ADD        ESP,0x8
    //         004cc3f4     LEA        this,[EAX + EAX*0x4]
    //         004cc3f7     MOV        EAX,0x80010003
    //         004cc3fc     SHL        this,0x2
    //         004cc3ff     IMUL       this
    //         004cc401     ADD        EDX,this
    //                              t_c_obj.cpp:1620 (22)
    //         004cc403     MOV        this,dword ptr [EDI + 0x8]
    //         004cc406     SAR        EDX,0xe
    //         004cc409     MOV        EAX,EDX
    //         004cc40b     SHR        EAX,0x1f
    //         004cc40e     ADD        EDX,EAX
    //         004cc410     CMP        DX,word ptr [ECX + this+0x126]
    //         004cc417     JG         LAB_004cc46d
    //                              t_c_obj.cpp:1622 (11)
    //         004cc419     MOV        EDX,dword ptr [EDI]
    //         004cc41b     PUSH       ESI
    //         004cc41c     MOV        this,EDI
    //         004cc41e     CALL       dword ptr [EDX + 0xf0]
    //                              t_c_obj.cpp:1624 (43)
    //         004cc424     MOV        this,dword ptr [ESP + 0x48]
    //         004cc428     MOV        EAX,dword ptr [EDI + 0x8]
    //         004cc42b     MOV        EDX,dword ptr [EDI + 0xc]
    //         004cc42e     MOV        EBX,dword ptr [ESI]
    //         004cc430     FSTP       float ptr [ESP + 0x10]
    //         004cc434     PUSH       this
    //         004cc435     MOV        this,dword ptr [ESP + 0x14]
    //         004cc439     PUSH       EDX=>DAT_fffffff8
    //         004cc43a     MOV        EDX,dword ptr [EAX + 0x10c]
    //         004cc440     MOVSX      EAX,word ptr [EAX + 0x108]
    //         004cc447     PUSH       this=>DAT_fffffff4
    //         004cc448     PUSH       EDX=>DAT_fffffff0
    //         004cc449     PUSH       EAX
    //         004cc44a     MOV        this,ESI
    //         004cc44c     CALL       dword ptr [EBX + 0x70]
    //                              t_c_obj.cpp:1625 (16)
    //         004cc44f     FLD        float ptr [ESI + 0x30]
    //         004cc452     FCOMP      float ptr [DAT_00574c78]                         = align(2)
    //         004cc458     FNSTSW     AX
    //         004cc45a     TEST       AH,0x1
    //         004cc45d     JZ         LAB_004cc46d
    //                              t_c_obj.cpp:1626 (25)
    //         004cc45f     PUSH       0x1
    //         004cc461     PUSH       0x0=>DAT_fffffff8
    //         004cc463     PUSH       0x0=>DAT_fffffff4
    //         004cc465     MOV        this,ESI
    //         004cc467     CALL       dword ptr [EBX + 0x84]
    //                               LAB_004cc46d                                                 XREF[7]:     004cc2e2(j), 004cc30f(j), 
    //                                                                                                         004cc317(j), 004cc32e(j), 
    //                                                                                                         004cc3d9(j), 004cc417(j), 
    //                                                                                                         004cc45d(j)  
    //         004cc46d     MOV        EBP,dword ptr [EBP + 0x4]
    //         004cc470     TEST       EBP,EBP
    //         004cc472     JNZ        LAB_004cc2d9
    //                              t_c_obj.cpp:1594 (4)
    //         004cc478     MOV        this,dword ptr [ESP + local_14]
    //                               LAB_004cc47c                                                 XREF[1]:     004cc2d3(j)  
    //                              t_c_obj.cpp:1593 (22)
    //         004cc47c     MOV        EAX,dword ptr [ESP + local_10]
    //         004cc480     ADD        this,0x18
    //         004cc483     DEC        EAX
    //         004cc484     MOV        dword ptr [ESP + local_14],this
    //         004cc488     MOV        dword ptr [ESP + local_10],EAX
    //         004cc48c     JNZ        LAB_004cc2bc
    //                               LAB_004cc492                                                 XREF[1]:     004cc2a0(j)  
    //                              t_c_obj.cpp:1592 (26)
    //         004cc492     MOV        this,dword ptr [ESP + ry]
    //         004cc496     MOV        EAX,dword ptr [ESP + map]
    //         004cc49a     ADD        this,0x4
    //         004cc49d     DEC        EAX
    //         004cc49e     MOV        dword ptr [ESP + ry],this
    //         004cc4a2     MOV        dword ptr [ESP + map],EAX
    //         004cc4a6     JNZ        LAB_004cc295
    //                               LAB_004cc4ac                                                 XREF[1]:     004cc278(j)  
    //                              t_c_obj.cpp:1556 (1)
    //         004cc4ac     POP        ESI
    //                              t_c_obj.cpp:1633 (11)
    //         004cc4ad     POP        EDI
    //         004cc4ae     POP        EBP
    //         004cc4af     MOV        AL,0x1
    //         004cc4b1     POP        EBX
    //         004cc4b2     ADD        ESP,0x28
    //         004cc4b5     RET        0x14
    //         004cc4b8     ??         90h
    //         004cc4b9     NOP
    //         004cc4ba     NOP
    //         004cc4bb     NOP
    //         004cc4bc     NOP
    //         004cc4bd     NOP
    //         004cc4be     NOP
    //         004cc4bf     NOP
    return 0;
}

uchar TRIBE_Combat_Object::heal(float param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall heal(TRIBE_Combat_Object * this, float param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[8]:     004cc4e3(R), 004cc507(R), 004cc50b(W), 004cc511(R), 
    //                                                                                     004cc515(W), 004cc528(W), 004cc544(R), 004cc555(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004cc4ff(W), 004cc503(R), 004cc536(W), 004cc53c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cc548(*)  
    //                               ?heal@TRIBE_Combat_Object@@MAEEM@Z                           XREF[2]:     heal:004c872f(c), 00574aac(*)  
    //                               TRIBE_Combat_Object::heal
    //                              t_c_obj.cpp:1637 (4)
    //         004cc4c0     PUSH       this
    //         004cc4c1     PUSH       ESI
    //         004cc4c2     MOV        ESI,this
    //                              t_c_obj.cpp:1643 (31)
    //         004cc4c4     MOV        this,dword ptr [ESI + 0x8]
    //         004cc4c7     MOV        AX,word ptr [ECX + this->_padding_]
    //         004cc4cb     CMP        AX,0x2
    //         004cc4cf     JZ         LAB_004cc4f4
    //         004cc4d1     CMP        AX,0x14
    //         004cc4d5     JZ         LAB_004cc4f4
    //         004cc4d7     CMP        AX,0x15
    //         004cc4db     JZ         LAB_004cc4f4
    //         004cc4dd     CMP        AX,0x16
    //         004cc4e1     JZ         LAB_004cc4f4
    //                              t_c_obj.cpp:1656 (12)
    //         004cc4e3     MOV        EAX,dword ptr [ESP + param_1]
    //         004cc4e7     MOV        this,ESI
    //         004cc4e9     PUSH       EAX
    //         004cc4ea     CALL       RGE_Static_Object::heal                          uchar heal(RGE_Static_Object * this, float pa
    //                              t_c_obj.cpp:1657 (5)
    //         004cc4ef     POP        ESI
    //         004cc4f0     POP        this
    //         004cc4f1     RET        0x4
    //                               LAB_004cc4f4                                                 XREF[4]:     004cc4cf(j), 004cc4d5(j), 
    //                                                                                                         004cc4db(j), 004cc4e1(j)  
    //                              t_c_obj.cpp:1645 (29)
    //         004cc4f4     MOVSX      EDX,word ptr [ECX + this+0x26]
    //         004cc4f8     MOVSX      EAX,word ptr [ECX + this+0x15a]
    //         004cc4ff     MOV        dword ptr [ESP + local_4],EDX
    //         004cc503     FILD       dword ptr [ESP + local_4]
    //         004cc507     FLD        float ptr [ESP + param_1]
    //         004cc50b     MOV        dword ptr [ESP + param_1],EAX
    //         004cc50f     FMUL       ST1
    //                              t_c_obj.cpp:1647 (20)
    //         004cc511     FIDIV      dword ptr [ESP + param_1]
    //         004cc515     FST        float ptr [ESP + param_1]
    //         004cc519     FADD       float ptr [ESI + 0x30]
    //         004cc51c     FCOMP
    //         004cc51e     FNSTSW     AX
    //         004cc520     TEST       AH,0x41
    //         004cc523     JNZ        LAB_004cc52e
    //                              t_c_obj.cpp:1648 (9)
    //         004cc525     FSUB       float ptr [ESI + 0x30]
    //         004cc528     FSTP       float ptr [ESP + param_1]
    //         004cc52c     JMP        LAB_004cc530
    //                               LAB_004cc52e                                                 XREF[1]:     004cc523(j)  
    //                              t_c_obj.cpp:1647 (2)
    //         004cc52e     FSTP       ST0
    //                               LAB_004cc530                                                 XREF[1]:     004cc52c(j)  
    //                              t_c_obj.cpp:1650 (37)
    //         004cc530     ADD        EDX,EDX
    //         004cc532     MOV        AX,word ptr [ECX + this->_padding_]
    //         004cc536     MOV        dword ptr [ESP + local_4],EDX
    //         004cc53a     PUSH       0x1
    //         004cc53c     FILD       dword ptr [ESP + local_4]
    //         004cc540     PUSH       this
    //         004cc541     MOV        this,dword ptr [ESI + 0xc]
    //         004cc544     FDIVR      float ptr [ESP + param_1]
    //         004cc548     FSTP       float ptr [ESP]=>local_10
    //         004cc54b     PUSH       EAX
    //         004cc54c     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
    //         004cc551     TEST       AL,AL
    //         004cc553     JZ         LAB_004cc566
    //                              t_c_obj.cpp:1651 (12)
    //         004cc555     MOV        this,dword ptr [ESP + param_1]
    //         004cc559     PUSH       this
    //         004cc55a     MOV        this,ESI
    //         004cc55c     CALL       RGE_Static_Object::heal                          uchar heal(RGE_Static_Object * this, float pa
    //                              t_c_obj.cpp:1657 (5)
    //         004cc561     POP        ESI
    //         004cc562     POP        this
    //         004cc563     RET        0x4
    //                               LAB_004cc566                                                 XREF[1]:     004cc553(j)  
    //                              t_c_obj.cpp:1653 (2)
    //         004cc566     MOV        AL,0x2
    //                              t_c_obj.cpp:1657 (5)
    //         004cc568     POP        ESI
    //         004cc569     POP        this
    //         004cc56a     RET        0x4
    //         004cc56d     ??         90h
    //         004cc56e     NOP
    //         004cc56f     NOP
    return 0;
}

int TRIBE_Combat_Object::canRepair() {
    /* TODO: Stub */
    //                              int __thiscall canRepair(TRIBE_Combat_Object * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004cc57b(W), 004cc583(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cc591(*)  
    //                               ?canRepair@TRIBE_Combat_Object@@MAEHXZ                       XREF[2]:     00574808(*), 00574ab0(*)  
    //                               TRIBE_Combat_Object::canRepair
    //                              t_c_obj.cpp:1661 (1)
    //         004cc570     PUSH       this
    //                              t_c_obj.cpp:1665 (51)
    //         004cc571     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004cc574     PUSH       0x0
    //         004cc576     PUSH       this
    //         004cc577     MOVSX      EDX,word ptr [EAX + 0x26]
    //         004cc57b     MOV        dword ptr [ESP + local_4],EDX
    //         004cc57f     MOV        AX,word ptr [EAX + 0x10]
    //         004cc583     FILD       dword ptr [ESP + local_4]
    //         004cc587     FLD        ST0
    //         004cc589     FSUB       float ptr [ECX + this->_padding_]
    //         004cc58c     MOV        this,dword ptr [ECX + this->_padding_]
    //         004cc58f     FDIV       ST0,ST1
    //         004cc591     FSTP       float ptr [ESP]=>local_c
    //         004cc594     PUSH       0x0
    //         004cc596     PUSH       EAX
    //         004cc597     FSTP       ST0
    //         004cc599     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
    //         004cc59e     NEG        AL
    //         004cc5a0     SBB        EAX,EAX
    //         004cc5a2     NEG        EAX
    //                              t_c_obj.cpp:1668 (2)
    //         004cc5a4     POP        this
    //         004cc5a5     RET
    //         004cc5a6     ??         90h
    //         004cc5a7     NOP
    //         004cc5a8     NOP
    //         004cc5a9     NOP
    //         004cc5aa     NOP
    //         004cc5ab     NOP
    //         004cc5ac     NOP
    //         004cc5ad     NOP
    //         004cc5ae     NOP
    //         004cc5af     NOP
    return 0;
}

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall do_repair(TRIBE_Combat_Object * this, RGE_Static_Obj
    //              void              <VOID>         <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cc5b3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cc5bd(W)  
    //                               ?do_repair@TRIBE_Combat_Object@@QAEXPAVRGE_Static_Object@@@Z XREF[1]:     do_command_repair:0050a716(c)  
    //                               TRIBE_Combat_Object::do_repair
    //                              t_c_obj.cpp:1678 (3)
    //         004cc5b0     PUSH       this
    //         004cc5b1     PUSH       EBX
    //         004cc5b2     PUSH       EBP
    //                              t_c_obj.cpp:1691 (20)
    //         004cc5b3     MOV        EBP,dword ptr [ESP + param_1]
    //         004cc5b7     PUSH       ESI
    //         004cc5b8     MOV        ESI,this
    //         004cc5ba     PUSH       EDI
    //         004cc5bb     CMP        EBP,ESI
    //         004cc5bd     MOV        dword ptr [ESP + local_4],ESI
    //         004cc5c1     JZ         LAB_004cc727
    //                              t_c_obj.cpp:1695 (11)
    //         004cc5c7     MOV        EAX,dword ptr [ESI + 0x8]
    //         004cc5ca     CMP        word ptr [EAX + 0x10],0x9c
    //         004cc5d0     JZ         LAB_004cc5e6
    //                              t_c_obj.cpp:1698 (20)
    //         004cc5d2     MOV        EAX,dword ptr [ESI + 0xc]
    //         004cc5d5     MOV        EDX,dword ptr [ESI]
    //         004cc5d7     MOV        this,dword ptr [EAX + 0x24]
    //         004cc5da     MOV        EAX,dword ptr [this->_padding_ + 0x270]
    //         004cc5e0     MOV        this,ESI
    //         004cc5e2     PUSH       EAX
    //         004cc5e3     CALL       dword ptr [EDX + 0x54]
    //                               LAB_004cc5e6                                                 XREF[1]:     004cc5d0(j)  
    //                              t_c_obj.cpp:1702 (9)
    //         004cc5e6     MOV        this,dword ptr [ESI + 0x8]
    //         004cc5e9     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              t_c_obj.cpp:1703 (10)
    //         004cc5ef     XOR        this,this
    //         004cc5f1     MOVSX      EBX,word ptr [EAX + 0x8]
    //         004cc5f5     TEST       EBX,EBX
    //         004cc5f7     JLE        LAB_004cc633
    //                              t_c_obj.cpp:1702 (3)
    //         004cc5f9     MOV        EDI,dword ptr [EAX + 0x4]
    //                               LAB_004cc5fc                                                 XREF[1]:     004cc62f(j)  
    //                              t_c_obj.cpp:1705 (2)
    //         004cc5fc     MOV        ESI,dword ptr [EDI]
    //                              t_c_obj.cpp:1706 (7)
    //         004cc5fe     CMP        word ptr [ESI + 0x6],0x6a
    //         004cc603     JNZ        LAB_004cc627
    //                              t_c_obj.cpp:1708 (24)
    //         004cc605     MOV        EDX,dword ptr [EBP + 0x8]
    //         004cc608     CMP        byte ptr [EDX + 0x4],0x50
    //         004cc60c     JNZ        LAB_004cc61d
    //         004cc60e     MOV        AX,word ptr [ESI + 0x8]
    //         004cc612     CMP        AX,0xffff
    //         004cc616     JZ         LAB_004cc637
    //         004cc618     TEST       AX,AX
    //         004cc61b     JZ         LAB_004cc637
    //                               LAB_004cc61d                                                 XREF[1]:     004cc60c(j)  
    //                              t_c_obj.cpp:1710 (10)
    //         004cc61d     MOV        AX,word ptr [ESI + 0x8]
    //         004cc621     CMP        AX,word ptr [EDX + 0x14]
    //         004cc625     JZ         LAB_004cc637
    //                               LAB_004cc627                                                 XREF[1]:     004cc603(j)  
    //                              t_c_obj.cpp:1713 (10)
    //         004cc627     XOR        ESI,ESI
    //         004cc629     INC        this
    //         004cc62a     ADD        EDI,0x4
    //         004cc62d     CMP        this,EBX
    //         004cc62f     JL         LAB_004cc5fc
    //                              t_c_obj.cpp:1703 (6)
    //         004cc631     JMP        LAB_004cc637
    //                               LAB_004cc633                                                 XREF[1]:     004cc5f7(j)  
    //         004cc633     MOV        ESI,dword ptr [ESP + 0x18]
    //                               LAB_004cc637                                                 XREF[4]:     004cc616(j), 004cc61b(j), 
    //                                                                                                         004cc625(j), 004cc631(j)  
    //                              t_c_obj.cpp:1719 (15)
    //         004cc637     MOV        EBX,dword ptr [ESP + 0x10]
    //         004cc63b     MOV        this,dword ptr [EBX + 0x184]
    //         004cc641     CALL       RGE_Action_List::get_task                        RGE_Task * get_task(RGE_Action_List * this)
    //                              t_c_obj.cpp:1720 (2)
    //         004cc646     XOR        EDI,EDI
    //                              t_c_obj.cpp:1722 (8)
    //         004cc648     CMP        EAX,EDI
    //         004cc64a     MOV        dword ptr [ESP + 0x18],EDI
    //         004cc64e     JZ         LAB_004cc68c
    //                              t_c_obj.cpp:1724 (4)
    //         004cc650     CMP        ESI,EAX
    //         004cc652     JNZ        LAB_004cc68c
    //                              t_c_obj.cpp:1726 (28)
    //         004cc654     MOV        this,dword ptr [EBP + 0x40]
    //         004cc657     MOV        EDX,dword ptr [EBP + 0x3c]
    //         004cc65a     MOV        EAX,dword ptr [EBP + 0x38]
    //         004cc65d     PUSH       this
    //         004cc65e     MOV        this,dword ptr [EBX + 0x184]
    //         004cc664     PUSH       EDX=>DAT_fffffff8
    //         004cc665     PUSH       EAX=>DAT_fffffff4
    //         004cc666     PUSH       EBP=>DAT_fffffff0
    //         004cc667     CALL       RGE_Action_List::action_work                     int action_work(RGE_Action_List * this, RGE_S
    //         004cc66c     TEST       EAX,EAX
    //         004cc66e     JZ         LAB_004cc68c
    //                              t_c_obj.cpp:1728 (20)
    //         004cc670     MOV        this,dword ptr [EBX + 0x184]
    //         004cc676     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004cc67b     MOV        EDX,dword ptr [EAX]
    //         004cc67d     MOV        this,EAX
    //         004cc67f     CALL       dword ptr [EDX + 0x18]
    //         004cc682     MOV        EDI,EAX
    //                              t_c_obj.cpp:1729 (8)
    //         004cc684     MOV        dword ptr [ESP + 0x18],0x1
    //                               LAB_004cc68c                                                 XREF[3]:     004cc64e(j), 004cc652(j), 
    //                                                                                                         004cc66e(j)  
    //                              t_c_obj.cpp:1734 (8)
    //         004cc68c     MOV        EAX,dword ptr [ESP + 0x18]
    //         004cc690     TEST       EAX,EAX
    //         004cc692     JNZ        LAB_004cc6d3
    //                              t_c_obj.cpp:1737 (4)
    //         004cc694     TEST       ESI,ESI
    //         004cc696     JZ         LAB_004cc6b5
    //                              t_c_obj.cpp:1738 (27)
    //         004cc698     MOV        EDX,dword ptr [EBP + 0x40]
    //         004cc69b     MOV        this,dword ptr [EBX + 0x184]
    //         004cc6a1     PUSH       EDX
    //         004cc6a2     MOV        EDX,dword ptr [EBP + 0x3c]
    //         004cc6a5     MOV        EAX,dword ptr [this->_padding_]
    //         004cc6a7     PUSH       EDX=>DAT_fffffff8
    //         004cc6a8     MOV        EDX,dword ptr [EBP + 0x38]
    //         004cc6ab     PUSH       EDX=>DAT_fffffff4
    //         004cc6ac     PUSH       EBP=>DAT_fffffff0
    //         004cc6ad     PUSH       ESI
    //         004cc6ae     CALL       dword ptr [EAX + 0x4]
    //         004cc6b1     MOV        ESI,EAX
    //                              t_c_obj.cpp:1739 (2)
    //         004cc6b3     JMP        LAB_004cc6b7
    //                               LAB_004cc6b5                                                 XREF[1]:     004cc696(j)  
    //                              t_c_obj.cpp:1740 (2)
    //         004cc6b5     XOR        ESI,ESI
    //                               LAB_004cc6b7                                                 XREF[1]:     004cc6b3(j)  
    //                              t_c_obj.cpp:1744 (4)
    //         004cc6b7     TEST       ESI,ESI
    //         004cc6b9     JZ         LAB_004cc6d1
    //                              t_c_obj.cpp:1746 (7)
    //         004cc6bb     MOV        EAX,dword ptr [ESI]
    //         004cc6bd     MOV        this,ESI
    //         004cc6bf     CALL       dword ptr [EAX + 0x18]
    //                              t_c_obj.cpp:1747 (13)
    //         004cc6c2     MOV        EDX,dword ptr [EBX]
    //         004cc6c4     PUSH       ESI
    //         004cc6c5     MOV        this,EBX
    //         004cc6c7     MOV        EDI,EAX
    //         004cc6c9     CALL       dword ptr [EDX + 0x208]
    //                              t_c_obj.cpp:1749 (2)
    //         004cc6cf     JMP        LAB_004cc6d3
    //                               LAB_004cc6d1                                                 XREF[1]:     004cc6b9(j)  
    //                              t_c_obj.cpp:1751 (2)
    //         004cc6d1     XOR        EDI,EDI
    //                               LAB_004cc6d3                                                 XREF[2]:     004cc692(j), 004cc6cf(j)  
    //                              t_c_obj.cpp:1756 (7)
    //         004cc6d3     MOV        this,dword ptr [EBX + 0x74]
    //         004cc6d6     TEST       this,this
    //         004cc6d8     JZ         LAB_004cc727
    //                              t_c_obj.cpp:1758 (3)
    //         004cc6da     OR         EAX,0xffffffff
    //                              t_c_obj.cpp:1759 (3)
    //         004cc6dd     OR         ESI,0xffffffff
    //                              t_c_obj.cpp:1760 (6)
    //         004cc6e0     CMP        DI,0x6a
    //         004cc6e4     JNZ        LAB_004cc6f0
    //                              t_c_obj.cpp:1763 (5)
    //         004cc6e6     MOV        ESI,0x26a
    //                              t_c_obj.cpp:1764 (5)
    //         004cc6eb     MOV        EAX,0x2ce
    //                               LAB_004cc6f0                                                 XREF[1]:     004cc6e4(j)  
    //                              t_c_obj.cpp:1767 (6)
    //         004cc6f0     PUSH       EAX
    //         004cc6f1     CALL       UnitAIModule::setCurrentOrder                    void setCurrentOrder(UnitAIModule * this, int
    //                              t_c_obj.cpp:1768 (9)
    //         004cc6f6     MOV        this,dword ptr [EBX + 0x74]
    //         004cc6f9     PUSH       ESI
    //         004cc6fa     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              t_c_obj.cpp:1769 (32)
    //         004cc6ff     MOV        EAX,dword ptr [EBP + 0x40]
    //         004cc702     MOV        this,dword ptr [EBP + 0x3c]
    //         004cc705     MOV        EDX,dword ptr [EBP + 0x38]
    //         004cc708     PUSH       EAX
    //         004cc709     MOV        EAX,dword ptr [EBP + 0x8]
    //         004cc70c     PUSH       this=>DAT_fffffff8
    //         004cc70d     PUSH       EDX=>DAT_fffffff4
    //         004cc70e     MOV        EDX,dword ptr [EBP + 0x4]
    //         004cc711     MOVSX      this,word ptr [EAX + 0x14]
    //         004cc715     PUSH       this=>DAT_fffffff0
    //         004cc716     MOV        this,dword ptr [EBX + 0x74]
    //         004cc719     PUSH       EDX
    //         004cc71a     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                              t_c_obj.cpp:1775 (8)
    //         004cc71f     MOV        this,dword ptr [EBX + 0x74]
    //         004cc722     CALL       UnitAIModule::setTaskedByPlayer                  void setTaskedByPlayer(UnitAIModule * this)
    //                               LAB_004cc727                                                 XREF[2]:     004cc5c1(j), 004cc6d8(j)  
    //                              t_c_obj.cpp:1777 (8)
    //         004cc727     POP        EDI
    //         004cc728     POP        ESI
    //         004cc729     POP        EBP
    //         004cc72a     POP        EBX
    //         004cc72b     POP        this
    //         004cc72c     RET        0x4
    //         004cc72f     ??         90h
    return;
}

void TRIBE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

uchar TRIBE_Combat_Object::attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar TRIBE_Combat_Object::do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar TRIBE_Combat_Object::produceWhenKilledBy(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar TRIBE_Combat_Object::useSameZoneDropsite() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Combat_Object::higher_check_for_cliff(RGE_Static_Object* param_1, int param_2, int param_3, float param_4, float param_5, float param_6, float param_7, RGE_Map* param_8, RGE_Static_Object* param_9, float* param_10, int* param_11) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar TRIBE_Combat_Object::area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

