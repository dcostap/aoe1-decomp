#include "common.h"
#include "ani_obj.h"

RGE_Animated_Object::RGE_Animated_Object(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Animated_Object(RGE_Animated_Object * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a227(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0041a22d(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0041a240(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041a244(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041a25f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041a237(W)  
    //                               ??0RGE_Animated_Object@@QAE@HPAVRGE_Game_World@@H@Z          XREF[3]:     RGE_Doppleganger_Object:00441a9d(c
    //                               RGE_Animated_Object::RGE_Animated_Object                                  RGE_Moving_Object:0045c5ec(c), 
    //                                                                                                         load:004639dd(c)  
    //                              ani_obj.cpp:38 (48)
    //         0041a210     PUSH       -0x1
    //         0041a212     PUSH       FUN_0055c948
    //         0041a217     MOV        EAX,FS:[0x0]
    //         0041a21d     PUSH       EAX
    //         0041a21e     MOV        dword ptr FS:[0x0],ESP
    //         0041a225     PUSH       this
    //         0041a226     PUSH       EBX
    //         0041a227     MOV        EBX,dword ptr [ESP + param_1]
    //         0041a22b     PUSH       ESI
    //         0041a22c     PUSH       EDI
    //         0041a22d     MOV        EDI,dword ptr [ESP + param_2]
    //         0041a231     PUSH       0x0
    //         0041a233     MOV        ESI,this
    //         0041a235     PUSH       EDI
    //         0041a236     PUSH       EBX
    //         0041a237     MOV        dword ptr [ESP + local_10],ESI
    //         0041a23b     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              ani_obj.cpp:39 (22)
    //         0041a240     MOV        EAX,dword ptr [ESP + param_3]
    //         0041a244     MOV        dword ptr [ESP + local_4],0x0
    //         0041a24c     TEST       EAX,EAX
    //         0041a24e     MOV        dword ptr [ESI],RGE_Animated_Object::`vftable'   = 0041a1e0
    //         0041a254     JZ         LAB_0041a25f
    //                              ani_obj.cpp:40 (9)
    //         0041a256     PUSH       EDI
    //         0041a257     PUSH       EBX
    //         0041a258     MOV        this,ESI
    //         0041a25a     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, int par
    //                               LAB_0041a25f                                                 XREF[1]:     0041a254(j)  
    //                              ani_obj.cpp:41 (22)
    //         0041a25f     MOV        this,dword ptr [ESP + local_c]
    //         0041a263     MOV        EAX,ESI
    //         0041a265     POP        EDI
    //         0041a266     POP        ESI
    //         0041a267     MOV        dword ptr FS:[0x0],this
    //         0041a26e     POP        EBX
    //         0041a26f     ADD        ESP,0x10
    //         0041a272     RET        0xc
    //         0041a275     ??         90h
    //         0041a276     NOP
    //         0041a277     NOP
    //         0041a278     NOP
    //         0041a279     NOP
    //         0041a27a     NOP
    //         0041a27b     NOP
    //         0041a27c     NOP
    //         0041a27d     NOP
    //         0041a27e     NOP
    //         0041a27f     NOP
    //                              * public: virtual void __thiscall RGE_Animated_Object::recycle_in_to_game(class RGE_Master_Static_Ob... *
    //                              void __thiscall recycle_in_to_game(RGE_Animated_Object * this, RGE_M
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0041a295(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0041a290(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0041a284(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0041a28b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0041a280(R)  
    //                               ?recycle_in_to_game@RGE_Animated_Object@@UAEXPAVRGE_Master_  XREF[4]:     recycle_in_to_game:00441c12(c), 
    //                               RGE_Animated_Object::recycle_in_to_game                                   recycle_in_to_game:0045c87f(c), 
    //                                                                                                         0056ec14(*), 00570224(*)  
    //                              ani_obj.cpp:46 (35)
    //         0041a280     MOV        EAX,dword ptr [ESP + param_5]
    //         0041a284     MOV        EDX,dword ptr [ESP + param_3]
    //         0041a288     PUSH       ESI
    //         0041a289     MOV        ESI,this
    //         0041a28b     MOV        this,dword ptr [ESP + param_4]
    //         0041a28f     PUSH       EAX
    //         0041a290     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a294     PUSH       this
    //         0041a295     MOV        this,dword ptr [ESP + param_1]
    //         0041a299     PUSH       EDX
    //         0041a29a     PUSH       EAX
    //         0041a29b     PUSH       this
    //         0041a29c     MOV        this,ESI
    //         0041a29e     CALL       RGE_Static_Object::recycle_in_to_game            void recycle_in_to_game(RGE_Static_Object * t
    //                              ani_obj.cpp:50 (19)
    //         0041a2a3     PUSH       0x0
    //         0041a2a5     MOV        this,ESI
    //         0041a2a7     MOV        dword ptr [ESI + 0x88],0x0
    //         0041a2b1     CALL       RGE_Static_Object::set_sleep_flag                void set_sleep_flag(RGE_Static_Object * this,
    //                              ani_obj.cpp:51 (4)
    //         0041a2b6     POP        ESI
    //         0041a2b7     RET        0x14
    //         0041a2ba     ??         90h
    //         0041a2bb     NOP
    //         0041a2bc     NOP
    //         0041a2bd     NOP
    //         0041a2be     NOP
    //         0041a2bf     NOP
    //                              * protected: virtual int __thiscall RGE_Animated_Object::setup(class RGE_Master_Animated_Object *,cl... *
    //                              int __thiscall setup(RGE_Animated_Object * this, RGE_Master_Animated
    //              int               EAX:4          <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Master_Ani    Stack[0x4]:4   param_1                   XREF[1]:     0041a2d5(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0041a2d0(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0041a2c4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0041a2cb(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0041a2c0(R)  
    //                               ?setup@RGE_Animated_Object@@MAEHPAVRGE_Master_Animated_Obje  XREF[11]:    RGE_Animated_Object:0041a1b7(c), 
    //                               RGE_Animated_Object::setup                                                setup:00441d4f(c), 
    //                                                                                                         setup:0045c98f(c), 0056e608(*), 
    //                                                                                                         0056edf8(*), 0056f440(*), 
    //                                                                                                         00570408(*), 005708d8(*), 
    //                                                                                                         00570b30(*), 00574960(*), 
    //                                                                                                         00574c08(*)  
    //                              ani_obj.cpp:55 (35)
    //         0041a2c0     MOV        EAX,dword ptr [ESP + param_5]
    //         0041a2c4     MOV        EDX,dword ptr [ESP + param_3]
    //         0041a2c8     PUSH       ESI
    //         0041a2c9     MOV        ESI,this
    //         0041a2cb     MOV        this,dword ptr [ESP + param_4]
    //         0041a2cf     PUSH       EAX
    //         0041a2d0     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a2d4     PUSH       this
    //         0041a2d5     MOV        this,dword ptr [ESP + param_1]
    //         0041a2d9     PUSH       EDX
    //         0041a2da     PUSH       EAX
    //         0041a2db     PUSH       this
    //         0041a2dc     MOV        this,ESI
    //         0041a2de     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, RGE_Maste
    //                              ani_obj.cpp:60 (23)
    //         0041a2e3     PUSH       0x0
    //         0041a2e5     MOV        this,ESI
    //         0041a2e7     MOV        byte ptr [ESI + 0x4e],0x14
    //         0041a2eb     MOV        dword ptr [ESI + 0x88],0x0
    //         0041a2f5     CALL       RGE_Static_Object::set_sleep_flag                void set_sleep_flag(RGE_Static_Object * this,
    //                              ani_obj.cpp:62 (5)
    //         0041a2fa     MOV        EAX,0x1
    //                              ani_obj.cpp:63 (4)
    //         0041a2ff     POP        ESI
    //         0041a300     RET        0x14
    //         0041a303     ??         90h
    //         0041a304     NOP
    //         0041a305     NOP
    //         0041a306     NOP
    //         0041a307     NOP
    //         0041a308     NOP
    //         0041a309     NOP
    //         0041a30a     NOP
    //         0041a30b     NOP
    //         0041a30c     NOP
    //         0041a30d     NOP
    //         0041a30e     NOP
    //         0041a30f     NOP
}

RGE_Animated_Object::RGE_Animated_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Animated_Object(RGE_Animated_Object * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a227(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0041a22d(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0041a240(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041a244(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041a25f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041a237(W)  
    //                               ??0RGE_Animated_Object@@QAE@HPAVRGE_Game_World@@H@Z          XREF[3]:     RGE_Doppleganger_Object:00441a9d(c
    //                               RGE_Animated_Object::RGE_Animated_Object                                  RGE_Moving_Object:0045c5ec(c), 
    //                                                                                                         load:004639dd(c)  
    //                              ani_obj.cpp:38 (48)
    //         0041a210     PUSH       -0x1
    //         0041a212     PUSH       FUN_0055c948
    //         0041a217     MOV        EAX,FS:[0x0]
    //         0041a21d     PUSH       EAX
    //         0041a21e     MOV        dword ptr FS:[0x0],ESP
    //         0041a225     PUSH       this
    //         0041a226     PUSH       EBX
    //         0041a227     MOV        EBX,dword ptr [ESP + param_1]
    //         0041a22b     PUSH       ESI
    //         0041a22c     PUSH       EDI
    //         0041a22d     MOV        EDI,dword ptr [ESP + param_2]
    //         0041a231     PUSH       0x0
    //         0041a233     MOV        ESI,this
    //         0041a235     PUSH       EDI
    //         0041a236     PUSH       EBX
    //         0041a237     MOV        dword ptr [ESP + local_10],ESI
    //         0041a23b     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              ani_obj.cpp:39 (22)
    //         0041a240     MOV        EAX,dword ptr [ESP + param_3]
    //         0041a244     MOV        dword ptr [ESP + local_4],0x0
    //         0041a24c     TEST       EAX,EAX
    //         0041a24e     MOV        dword ptr [ESI],RGE_Animated_Object::`vftable'   = 0041a1e0
    //         0041a254     JZ         LAB_0041a25f
    //                              ani_obj.cpp:40 (9)
    //         0041a256     PUSH       EDI
    //         0041a257     PUSH       EBX
    //         0041a258     MOV        this,ESI
    //         0041a25a     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, int par
    //                               LAB_0041a25f                                                 XREF[1]:     0041a254(j)  
    //                              ani_obj.cpp:41 (22)
    //         0041a25f     MOV        this,dword ptr [ESP + local_c]
    //         0041a263     MOV        EAX,ESI
    //         0041a265     POP        EDI
    //         0041a266     POP        ESI
    //         0041a267     MOV        dword ptr FS:[0x0],this
    //         0041a26e     POP        EBX
    //         0041a26f     ADD        ESP,0x10
    //         0041a272     RET        0xc
    //         0041a275     ??         90h
    //         0041a276     NOP
    //         0041a277     NOP
    //         0041a278     NOP
    //         0041a279     NOP
    //         0041a27a     NOP
    //         0041a27b     NOP
    //         0041a27c     NOP
    //         0041a27d     NOP
    //         0041a27e     NOP
    //         0041a27f     NOP
    //                              * public: virtual void __thiscall RGE_Animated_Object::recycle_in_to_game(class RGE_Master_Static_Ob... *
    //                              void __thiscall recycle_in_to_game(RGE_Animated_Object * this, RGE_M
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0041a295(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0041a290(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0041a284(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0041a28b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0041a280(R)  
    //                               ?recycle_in_to_game@RGE_Animated_Object@@UAEXPAVRGE_Master_  XREF[4]:     recycle_in_to_game:00441c12(c), 
    //                               RGE_Animated_Object::recycle_in_to_game                                   recycle_in_to_game:0045c87f(c), 
    //                                                                                                         0056ec14(*), 00570224(*)  
    //                              ani_obj.cpp:46 (35)
    //         0041a280     MOV        EAX,dword ptr [ESP + param_5]
    //         0041a284     MOV        EDX,dword ptr [ESP + param_3]
    //         0041a288     PUSH       ESI
    //         0041a289     MOV        ESI,this
    //         0041a28b     MOV        this,dword ptr [ESP + param_4]
    //         0041a28f     PUSH       EAX
    //         0041a290     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a294     PUSH       this
    //         0041a295     MOV        this,dword ptr [ESP + param_1]
    //         0041a299     PUSH       EDX
    //         0041a29a     PUSH       EAX
    //         0041a29b     PUSH       this
    //         0041a29c     MOV        this,ESI
    //         0041a29e     CALL       RGE_Static_Object::recycle_in_to_game            void recycle_in_to_game(RGE_Static_Object * t
    //                              ani_obj.cpp:50 (19)
    //         0041a2a3     PUSH       0x0
    //         0041a2a5     MOV        this,ESI
    //         0041a2a7     MOV        dword ptr [ESI + 0x88],0x0
    //         0041a2b1     CALL       RGE_Static_Object::set_sleep_flag                void set_sleep_flag(RGE_Static_Object * this,
    //                              ani_obj.cpp:51 (4)
    //         0041a2b6     POP        ESI
    //         0041a2b7     RET        0x14
    //         0041a2ba     ??         90h
    //         0041a2bb     NOP
    //         0041a2bc     NOP
    //         0041a2bd     NOP
    //         0041a2be     NOP
    //         0041a2bf     NOP
    //                              * protected: virtual int __thiscall RGE_Animated_Object::setup(class RGE_Master_Animated_Object *,cl... *
    //                              int __thiscall setup(RGE_Animated_Object * this, RGE_Master_Animated
    //              int               EAX:4          <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Master_Ani    Stack[0x4]:4   param_1                   XREF[1]:     0041a2d5(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0041a2d0(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0041a2c4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0041a2cb(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0041a2c0(R)  
    //                               ?setup@RGE_Animated_Object@@MAEHPAVRGE_Master_Animated_Obje  XREF[11]:    RGE_Animated_Object:0041a1b7(c), 
    //                               RGE_Animated_Object::setup                                                setup:00441d4f(c), 
    //                                                                                                         setup:0045c98f(c), 0056e608(*), 
    //                                                                                                         0056edf8(*), 0056f440(*), 
    //                                                                                                         00570408(*), 005708d8(*), 
    //                                                                                                         00570b30(*), 00574960(*), 
    //                                                                                                         00574c08(*)  
    //                              ani_obj.cpp:55 (35)
    //         0041a2c0     MOV        EAX,dword ptr [ESP + param_5]
    //         0041a2c4     MOV        EDX,dword ptr [ESP + param_3]
    //         0041a2c8     PUSH       ESI
    //         0041a2c9     MOV        ESI,this
    //         0041a2cb     MOV        this,dword ptr [ESP + param_4]
    //         0041a2cf     PUSH       EAX
    //         0041a2d0     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a2d4     PUSH       this
    //         0041a2d5     MOV        this,dword ptr [ESP + param_1]
    //         0041a2d9     PUSH       EDX
    //         0041a2da     PUSH       EAX
    //         0041a2db     PUSH       this
    //         0041a2dc     MOV        this,ESI
    //         0041a2de     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, RGE_Maste
    //                              ani_obj.cpp:60 (23)
    //         0041a2e3     PUSH       0x0
    //         0041a2e5     MOV        this,ESI
    //         0041a2e7     MOV        byte ptr [ESI + 0x4e],0x14
    //         0041a2eb     MOV        dword ptr [ESI + 0x88],0x0
    //         0041a2f5     CALL       RGE_Static_Object::set_sleep_flag                void set_sleep_flag(RGE_Static_Object * this,
    //                              ani_obj.cpp:62 (5)
    //         0041a2fa     MOV        EAX,0x1
    //                              ani_obj.cpp:63 (4)
    //         0041a2ff     POP        ESI
    //         0041a300     RET        0x14
    //         0041a303     ??         90h
    //         0041a304     NOP
    //         0041a305     NOP
    //         0041a306     NOP
    //         0041a307     NOP
    //         0041a308     NOP
    //         0041a309     NOP
    //         0041a30a     NOP
    //         0041a30b     NOP
    //         0041a30c     NOP
    //         0041a30d     NOP
    //         0041a30e     NOP
    //         0041a30f     NOP
}

int RGE_Animated_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Animated_Object * this, int param_1, RGE_Ga
    //              int               EAX:4          <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a316(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0041a310(R)  
    //                               ?setup@RGE_Animated_Object@@MAEHHPAVRGE_Game_World@@@Z       XREF[4]:     RGE_Animated_Object:0041a25a(c), 
    //                               RGE_Animated_Object::setup                                                setup:00441db0(c), 
    //                                                                                                         setup:0045cab3(c), 0056ede8(*)  
    //                              ani_obj.cpp:67 (19)
    //         0041a310     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a314     PUSH       ESI
    //         0041a315     PUSH       EDI
    //         0041a316     MOV        EDI,dword ptr [ESP + param_1]
    //         0041a31a     PUSH       EAX
    //         0041a31b     MOV        ESI,this
    //         0041a31d     PUSH       EDI
    //         0041a31e     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, int param
    //                              ani_obj.cpp:70 (4)
    //         0041a323     MOV        byte ptr [ESI + 0x4e],0x14
    //                              ani_obj.cpp:72 (18)
    //         0041a327     ADD        ESI,0x88
    //         0041a32d     PUSH       0x4
    //         0041a32f     PUSH       ESI
    //         0041a330     PUSH       EDI
    //         0041a331     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0041a336     ADD        ESP,0xc
    //                              ani_obj.cpp:74 (5)
    //         0041a339     MOV        EAX,0x1
    //                              ani_obj.cpp:75 (5)
    //         0041a33e     POP        EDI
    //         0041a33f     POP        ESI
    //         0041a340     RET        0x8
    //         0041a343     ??         90h
    //         0041a344     NOP
    //         0041a345     NOP
    //         0041a346     NOP
    //         0041a347     NOP
    //         0041a348     NOP
    //         0041a349     NOP
    //         0041a34a     NOP
    //         0041a34b     NOP
    //         0041a34c     NOP
    //         0041a34d     NOP
    //         0041a34e     NOP
    //         0041a34f     NOP
    return 0;
}

int RGE_Animated_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Animated_Object * this, int param_1, RGE_Ga
    //              int               EAX:4          <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a316(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0041a310(R)  
    //                               ?setup@RGE_Animated_Object@@MAEHHPAVRGE_Game_World@@@Z       XREF[4]:     RGE_Animated_Object:0041a25a(c), 
    //                               RGE_Animated_Object::setup                                                setup:00441db0(c), 
    //                                                                                                         setup:0045cab3(c), 0056ede8(*)  
    //                              ani_obj.cpp:67 (19)
    //         0041a310     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a314     PUSH       ESI
    //         0041a315     PUSH       EDI
    //         0041a316     MOV        EDI,dword ptr [ESP + param_1]
    //         0041a31a     PUSH       EAX
    //         0041a31b     MOV        ESI,this
    //         0041a31d     PUSH       EDI
    //         0041a31e     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, int param
    //                              ani_obj.cpp:70 (4)
    //         0041a323     MOV        byte ptr [ESI + 0x4e],0x14
    //                              ani_obj.cpp:72 (18)
    //         0041a327     ADD        ESI,0x88
    //         0041a32d     PUSH       0x4
    //         0041a32f     PUSH       ESI
    //         0041a330     PUSH       EDI
    //         0041a331     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0041a336     ADD        ESP,0xc
    //                              ani_obj.cpp:74 (5)
    //         0041a339     MOV        EAX,0x1
    //                              ani_obj.cpp:75 (5)
    //         0041a33e     POP        EDI
    //         0041a33f     POP        ESI
    //         0041a340     RET        0x8
    //         0041a343     ??         90h
    //         0041a344     NOP
    //         0041a345     NOP
    //         0041a346     NOP
    //         0041a347     NOP
    //         0041a348     NOP
    //         0041a349     NOP
    //         0041a34a     NOP
    //         0041a34b     NOP
    //         0041a34c     NOP
    //         0041a34d     NOP
    //         0041a34e     NOP
    //         0041a34f     NOP
    return 0;
}

uchar RGE_Animated_Object::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Animated_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //                               ?update@RGE_Animated_Object@@UAEEXZ                          XREF[4]:     update:00406b09(c), 
    //                               RGE_Animated_Object::update                                               update:00441eb6(c), 0056ec34(*), 
    //                                                                                                         0057096c(*)  
    //                              ani_obj.cpp:79 (4)
    //         0041a350     PUSH       EBX
    //         0041a351     PUSH       ESI
    //         0041a352     MOV        ESI,this
    //                              ani_obj.cpp:85 (7)
    //         0041a354     CALL       RGE_Static_Object::update                        uchar update(RGE_Static_Object * this)
    //         0041a359     MOV        BL,AL
    //                              ani_obj.cpp:91 (13)
    //         0041a35b     XOR        EAX,EAX
    //         0041a35d     MOV        AL,byte ptr [ESI + 0x48]
    //         0041a360     SUB        EAX,0x3
    //         0041a363     JZ         LAB_0041a388
    //         0041a365     DEC        EAX
    //         0041a366     JNZ        LAB_0041a3a6
    //                              ani_obj.cpp:103 (16)
    //         0041a368     MOV        this,dword ptr [ESI + 0x18]
    //         0041a36b     MOV        EDX,dword ptr [ESI + 0x10]
    //         0041a36e     PUSH       EDX
    //         0041a36f     MOV        EAX,dword ptr [this->_padding_]
    //         0041a371     CALL       dword ptr [EAX + 0x18]
    //         0041a374     TEST       AL,AL
    //         0041a376     JNZ        LAB_0041a3a6
    //                              ani_obj.cpp:105 (4)
    //         0041a378     MOV        byte ptr [ESI + 0x48],0x5
    //                              ani_obj.cpp:106 (10)
    //         0041a37c     MOV        dword ptr [ESI + 0x88],0x0
    //                              ani_obj.cpp:108 (2)
    //         0041a386     JMP        LAB_0041a3a6
    //                               LAB_0041a388                                                 XREF[1]:     0041a363(j)  
    //                              ani_obj.cpp:94 (10)
    //         0041a388     MOV        EAX,dword ptr [ESI + 0x8]
    //         0041a38b     MOV        this,dword ptr [EAX + 0x1c]
    //         0041a38e     TEST       this,this
    //         0041a390     JNZ        LAB_0041a39d
    //                              ani_obj.cpp:95 (9)
    //         0041a392     MOV        EDX,dword ptr [ESI]
    //         0041a394     PUSH       0x5
    //         0041a396     MOV        this,ESI
    //         0041a398     CALL       dword ptr [EDX + 0x5c]
    //                              ani_obj.cpp:96 (2)
    //         0041a39b     JMP        LAB_0041a3a6
    //                               LAB_0041a39d                                                 XREF[1]:     0041a390(j)  
    //                              ani_obj.cpp:97 (9)
    //         0041a39d     MOV        EAX,dword ptr [ESI]
    //         0041a39f     PUSH       0x4
    //         0041a3a1     MOV        this,ESI
    //         0041a3a3     CALL       dword ptr [EAX + 0x5c]
    //                               LAB_0041a3a6                                                 XREF[4]:     0041a366(j), 0041a376(j), 
    //                                                                                                         0041a386(j), 0041a39b(j)  
    //                              ani_obj.cpp:115 (28)
    //         0041a3a6     MOV        EAX,dword ptr [ESI + 0x88]
    //         0041a3ac     MOV        this,dword ptr [ESI + 0x18]
    //         0041a3af     PUSH       EAX
    //         0041a3b0     MOV        EAX,dword ptr [ESI + 0xc]
    //         0041a3b3     MOV        EDX,dword ptr [this->_padding_]
    //         0041a3b5     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0041a3b8     MOV        EAX,dword ptr [EAX + 0x84]
    //         0041a3be     PUSH       EAX=>DAT_fffffff8
    //         0041a3bf     CALL       dword ptr [EDX + 0x8]
    //                              ani_obj.cpp:124 (2)
    //         0041a3c2     MOV        AL,BL
    //                              ani_obj.cpp:125 (3)
    //         0041a3c4     POP        ESI
    //         0041a3c5     POP        EBX
    //         0041a3c6     RET
    //         0041a3c7     ??         90h
    //         0041a3c8     NOP
    //         0041a3c9     NOP
    //         0041a3ca     NOP
    //         0041a3cb     NOP
    //         0041a3cc     NOP
    //         0041a3cd     NOP
    //         0041a3ce     NOP
    //         0041a3cf     NOP
    return 0;
}

void RGE_Animated_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Animated_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a3d2(R)  
    //                               ?save@RGE_Animated_Object@@UAEXH@Z                           XREF[3]:     save:00441f89(c), 
    //                               RGE_Animated_Object::save                                                 save:0045ce0c(c), 0056ec40(*)  
    //                              ani_obj.cpp:129 (2)
    //         0041a3d0     PUSH       ESI
    //         0041a3d1     PUSH       EDI
    //                              ani_obj.cpp:130 (12)
    //         0041a3d2     MOV        EDI,dword ptr [ESP + param_1]
    //         0041a3d6     MOV        ESI,this
    //         0041a3d8     PUSH       EDI
    //         0041a3d9     CALL       RGE_Static_Object::save                          void save(RGE_Static_Object * this, int param
    //                              ani_obj.cpp:133 (18)
    //         0041a3de     ADD        ESI,0x88
    //         0041a3e4     PUSH       0x4
    //         0041a3e6     PUSH       ESI
    //         0041a3e7     PUSH       EDI
    //         0041a3e8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041a3ed     ADD        ESP,0xc
    //                              ani_obj.cpp:134 (5)
    //         0041a3f0     POP        EDI
    //         0041a3f1     POP        ESI
    //         0041a3f2     RET        0x4
    //         0041a3f5     ??         90h
    //         0041a3f6     NOP
    //         0041a3f7     NOP
    //         0041a3f8     NOP
    //         0041a3f9     NOP
    //         0041a3fa     NOP
    //         0041a3fb     NOP
    //         0041a3fc     NOP
    //         0041a3fd     NOP
    //         0041a3fe     NOP
    //         0041a3ff     NOP
    return;
}

void RGE_Animated_Object::transform(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall transform(RGE_Animated_Object * this, RGE_Master_Sta
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0041a400(R)  
    //                               ?transform@RGE_Animated_Object@@UAEXPAVRGE_Master_Static_Ob  XREF[3]:     transform:0045d0e8(c), 
    //                               RGE_Animated_Object::transform                                            0056ec64(*), 00570274(*)  
    //                              ani_obj.cpp:138 (10)
    //         0041a400     MOV        EAX,dword ptr [ESP + param_1]
    //         0041a404     PUSH       EAX
    //         0041a405     CALL       RGE_Static_Object::transform                     void transform(RGE_Static_Object * this, RGE_
    //                              ani_obj.cpp:140 (3)
    //         0041a40a     RET        0x4
    //         0041a40d     ??         90h
    //         0041a40e     NOP
    //         0041a40f     NOP
    //                              * public: virtual void __thiscall RGE_Animated_Object::set_being_worked_on(class RGE_Action_Object *... *
    //                              void __thiscall set_being_worked_on(RGE_Animated_Object * this, RGE_
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0041a419(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041a414(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0041a410(R)  
    //                               ?set_being_worked_on@RGE_Animated_Object@@UAEXPAVRGE_Action  XREF[8]:     0056e4e0(*), 0056ecd0(*), 
    //                               RGE_Animated_Object::set_being_worked_on                                  0056f318(*), 005702e0(*), 
    //                                                                                                         005707b0(*), 00570a08(*), 
    //                                                                                                         00574838(*), 00574ae0(*)  
    //                              ani_obj.cpp:145 (20)
    //         0041a410     MOV        EAX,dword ptr [ESP + param_3]
    //         0041a414     MOV        EDX,dword ptr [ESP + param_2]
    //         0041a418     PUSH       EAX
    //         0041a419     MOV        EAX,dword ptr [ESP + param_1]
    //         0041a41d     PUSH       EDX
    //         0041a41e     PUSH       EAX
    //         0041a41f     CALL       RGE_Static_Object::set_being_worked_on           void set_being_worked_on(RGE_Static_Object * 
    //                              ani_obj.cpp:147 (3)
    //         0041a424     RET        0xc
    //         0041a427     ??         90h
    //         0041a428     NOP
    //         0041a429     NOP
    //         0041a42a     NOP
    //         0041a42b     NOP
    //         0041a42c     NOP
    //         0041a42d     NOP
    //         0041a42e     NOP
    //         0041a42f     NOP
    //                              * public: virtual void __thiscall RGE_Animated_Object::release_being_worked_on(class RGE_Static_Obje... *
    //                              void __thiscall release_being_worked_on(RGE_Animated_Object * this, 
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0041a430(R)  
    //                               ?release_being_worked_on@RGE_Animated_Object@@UAEXPAVRGE_St  XREF[5]:     release_being_worked_on:004305d9(c
    //                               RGE_Animated_Object::release_being_worked_on                              0056e4e4(*), 0056ecd4(*), 
    //                                                                                                         005702e4(*), 00570a0c(*)  
    //                              ani_obj.cpp:152 (13)
    //         0041a430     MOV        EAX,dword ptr [ESP + param_1]
    //         0041a434     PUSH       ESI
    //         0041a435     MOV        ESI,this
    //         0041a437     PUSH       EAX
    //         0041a438     CALL       RGE_Static_Object::release_being_worked_on       void release_being_worked_on(RGE_Static_Objec
    //                              ani_obj.cpp:159 (9)
    //         0041a43d     PUSH       0x0
    //         0041a43f     MOV        this,ESI
    //         0041a441     CALL       RGE_Static_Object::set_sleep_flag                void set_sleep_flag(RGE_Static_Object * this,
    //                              ani_obj.cpp:160 (4)
    //         0041a446     POP        ESI
    //         0041a447     RET        0x4
    //         0041a44a     ??         90h
    //         0041a44b     NOP
    //         0041a44c     NOP
    //         0041a44d     NOP
    //         0041a44e     NOP
    //         0041a44f     NOP
    //                              * public: virtual void __thiscall RGE_Static_Object::do_command(class RGE_Static_Object *,float,floa... *
    //                              void __thiscall do_command(RGE_Static_Object * this, RGE_Static_Obje
    //              void              <VOID>         <RETURN>
    //              RGE_Static_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1
    //              float             Stack[0x8]:4   param_2
    //              float             Stack[0xc]:4   param_3
    //              float             Stack[0x10]:4  param_4
    //                               ?do_command@RGE_Static_Object@@UAEXPAV1@MMM@Z                XREF[5]:     0056eca8(*), 005702b8(*), 
    //                               RGE_Static_Object::do_command                                             005709e0(*), 005745c8(*), 
    //                                                                                                         00574d48(*)  
    //                              stat_obj.h:158 (3)
    //         0041a450     RET        0x10
    //         0041a453     ??         90h
    //         0041a454     NOP
    //         0041a455     NOP
    //         0041a456     NOP
    //         0041a457     NOP
    //         0041a458     NOP
    //         0041a459     NOP
    //         0041a45a     NOP
    //         0041a45b     NOP
    //         0041a45c     NOP
    //         0041a45d     NOP
    //         0041a45e     NOP
    //         0041a45f     NOP
    //                              * public: virtual void __thiscall RGE_Static_Object::move_to(class RGE_Static_Object *,float,float,f... *
    //                              void __thiscall move_to(RGE_Static_Object * this, RGE_Static_Object 
    //              void              <VOID>         <RETURN>
    //              RGE_Static_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1
    //              float             Stack[0x8]:4   param_2
    //              float             Stack[0xc]:4   param_3
    //              float             Stack[0x10]:4  param_4
    //                               ?move_to@RGE_Static_Object@@UAEXPAV1@MMM@Z                   XREF[5]:     0056ecac(*), 005702bc(*), 
    //                               RGE_Static_Object::move_to                                                005709e4(*), 005745cc(*), 
    //                                                                                                         00574d4c(*)  
    //                              stat_obj.h:159 (3)
    //         0041a460     RET        0x10
    //         0041a463     ??         90h
    //         0041a464     NOP
    //         0041a465     NOP
    //         0041a466     NOP
    //         0041a467     NOP
    //         0041a468     NOP
    //         0041a469     NOP
    //         0041a46a     NOP
    //         0041a46b     NOP
    //         0041a46c     NOP
    //         0041a46d     NOP
    //         0041a46e     NOP
    //         0041a46f     NOP
    return;
}

float RGE_Animated_Object::getSpeed() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Animated_Object::~RGE_Animated_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Animated_Object(RGE_Animated_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //                               ??1RGE_Animated_Object@@UAE@XZ                               XREF[2]:     `scalar_deleting_destructor':0041a
    //                               RGE_Animated_Object::~RGE_Animated_Object                                 FUN_0055dc60:0055dc63(c)  
    //         0041a200     JMP        RGE_Static_Object::~RGE_Static_Object
    //         0041a205     ??         90h
    //         0041a206     NOP
    //         0041a207     NOP
    //         0041a208     NOP
    //         0041a209     NOP
    //         0041a20a     NOP
    //         0041a20b     NOP
    //         0041a20c     NOP
    //         0041a20d     NOP
    //         0041a20e     NOP
    //         0041a20f     NOP
}

void RGE_Animated_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Animated_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Animated_Object::release_being_worked_on(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

