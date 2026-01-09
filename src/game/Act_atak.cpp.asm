#include "common.h"
#include "Act_atak.h"

RGE_Action_Attack::RGE_Action_Attack(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_Attack(RGE_Action_Attack * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040101c(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[7]:     00401016(R), 004010ac(*), 004010b9(R), 004010c9(*), 
    //                                                                                     004010d9(R), 004010ec(*), 004010f9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00401036(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00401109(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00401026(W)  
    //                               ??0RGE_Action_Attack@@QAE@HPAVRGE_Action_Object@@@Z          XREF[3]:     004000ac(*), 00400184(*), 
    //                               RGE_Action_Attack::RGE_Action_Attack                                      create_action:0040401f(c)  
    //                              Act_atak.cpp:42 (47)
    //         00401000     PUSH       -0x1
    //         00401002     PUSH       FUN_0055c0b8
    //         00401007     MOV        EAX,FS:[0x0]
    //         0040100d     PUSH       EAX
    //         0040100e     MOV        dword ptr FS:[0x0],ESP
    //         00401015     PUSH       this
    //         00401016     MOV        EAX,dword ptr [ESP + param_2]
    //         0040101a     PUSH       ESI
    //         0040101b     PUSH       EDI
    //         0040101c     MOV        EDI,dword ptr [ESP + param_1]
    //         00401020     PUSH       0x1
    //         00401022     MOV        ESI,this
    //         00401024     PUSH       EAX
    //         00401025     PUSH       EDI
    //         00401026     MOV        dword ptr [ESP + local_10],ESI
    //         0040102a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //                              Act_atak.cpp:47 (35)
    //         0040102f     LEA        this,[ESI + 0x4c]
    //         00401032     PUSH       0x4
    //         00401034     PUSH       this
    //         00401035     PUSH       EDI
    //         00401036     MOV        dword ptr [ESP + local_4],0x0
    //         0040103e     MOV        dword ptr [ESI],RGE_Action_Attack::`vftable'     = 00401150
    //         00401044     MOV        word ptr [ESI + 0x4],0x9
    //         0040104a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040104f     ADD        ESP,0xc
    //                              Act_atak.cpp:48 (15)
    //         00401052     LEA        EDX,[ESI + 0x50]
    //         00401055     PUSH       0x4
    //         00401057     PUSH       EDX
    //         00401058     PUSH       EDI
    //         00401059     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040105e     ADD        ESP,0xc
    //                              Act_atak.cpp:49 (15)
    //         00401061     LEA        EAX,[ESI + 0x54]
    //         00401064     PUSH       0x2
    //         00401066     PUSH       EAX
    //         00401067     PUSH       EDI
    //         00401068     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040106d     ADD        ESP,0xc
    //                              Act_atak.cpp:50 (15)
    //         00401070     LEA        this,[ESI + 0x56]
    //         00401073     PUSH       0x2
    //         00401075     PUSH       this
    //         00401076     PUSH       EDI
    //         00401077     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040107c     ADD        ESP,0xc
    //                              Act_atak.cpp:51 (15)
    //         0040107f     LEA        EDX,[ESI + 0x58]
    //         00401082     PUSH       0x1
    //         00401084     PUSH       EDX
    //         00401085     PUSH       EDI
    //         00401086     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040108b     ADD        ESP,0xc
    //                              Act_atak.cpp:52 (15)
    //         0040108e     LEA        EAX,[ESI + 0x59]
    //         00401091     PUSH       0x1
    //         00401093     PUSH       EAX
    //         00401094     PUSH       EDI
    //         00401095     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040109a     ADD        ESP,0xc
    //                              Act_atak.cpp:53 (15)
    //         0040109d     LEA        this,[ESI + 0x5a]
    //         004010a0     PUSH       0x1
    //         004010a2     PUSH       this
    //         004010a3     PUSH       EDI
    //         004010a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004010a9     ADD        ESP,0xc
    //                              Act_atak.cpp:55 (13)
    //         004010ac     LEA        EDX=>param_2,[ESP + 0x20]
    //         004010b0     PUSH       0x2
    //         004010b2     PUSH       EDX
    //         004010b3     PUSH       EDI
    //         004010b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:56 (16)
    //         004010b9     MOV        EAX,dword ptr [ESP + param_2]
    //         004010bd     MOV        this,dword ptr [ESI + 0x8]
    //         004010c0     ADD        ESP,0xc
    //         004010c3     PUSH       EAX
    //         004010c4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:58 (16)
    //         004010c9     LEA        this=>param_2,[ESP + 0x20]
    //         004010cd     PUSH       0x2
    //         004010cf     PUSH       this
    //         004010d0     PUSH       EDI
    //         004010d1     MOV        dword ptr [ESI + 0x40],EAX
    //         004010d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:59 (19)
    //         004010d9     MOV        EDX,dword ptr [ESP + param_2]
    //         004010dd     MOV        this,dword ptr [ESI + 0x8]
    //         004010e0     ADD        ESP,0xc
    //         004010e3     PUSH       EDX
    //         004010e4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //         004010e9     MOV        dword ptr [ESI + 0x44],EAX
    //                              Act_atak.cpp:61 (13)
    //         004010ec     LEA        EAX=>param_2,[ESP + 0x20]
    //         004010f0     PUSH       0x2
    //         004010f2     PUSH       EAX
    //         004010f3     PUSH       EDI
    //         004010f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:62 (16)
    //         004010f9     MOV        this,dword ptr [ESP + param_2]
    //         004010fd     ADD        ESP,0xc
    //         00401100     PUSH       this
    //         00401101     MOV        this,dword ptr [ESI + 0x8]
    //         00401104     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:63 (24)
    //         00401109     MOV        this,dword ptr [ESP + local_c]
    //         0040110d     MOV        dword ptr [ESI + 0x48],EAX
    //         00401110     MOV        EAX,ESI
    //         00401112     POP        EDI
    //         00401113     MOV        dword ptr FS:[0x0],this
    //         0040111a     POP        ESI
    //         0040111b     ADD        ESP,0x10
    //         0040111e     RET        0x8
    //         00401121     ??         90h
    //         00401122     NOP
    //         00401123     NOP
    //         00401124     NOP
    //         00401125     NOP
    //         00401126     NOP
    //         00401127     NOP
    //         00401128     NOP
    //         00401129     NOP
    //         0040112a     NOP
    //         0040112b     NOP
    //         0040112c     NOP
    //         0040112d     NOP
    //         0040112e     NOP
    //         0040112f     NOP
}

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4, RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_Attack(RGE_Action_Attack * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040101c(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[7]:     00401016(R), 004010ac(*), 004010b9(R), 004010c9(*), 
    //                                                                                     004010d9(R), 004010ec(*), 004010f9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00401036(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00401109(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00401026(W)  
    //                               ??0RGE_Action_Attack@@QAE@HPAVRGE_Action_Object@@@Z          XREF[3]:     004000ac(*), 00400184(*), 
    //                               RGE_Action_Attack::RGE_Action_Attack                                      create_action:0040401f(c)  
    //                              Act_atak.cpp:42 (47)
    //         00401000     PUSH       -0x1
    //         00401002     PUSH       FUN_0055c0b8
    //         00401007     MOV        EAX,FS:[0x0]
    //         0040100d     PUSH       EAX
    //         0040100e     MOV        dword ptr FS:[0x0],ESP
    //         00401015     PUSH       this
    //         00401016     MOV        EAX,dword ptr [ESP + param_2]
    //         0040101a     PUSH       ESI
    //         0040101b     PUSH       EDI
    //         0040101c     MOV        EDI,dword ptr [ESP + param_1]
    //         00401020     PUSH       0x1
    //         00401022     MOV        ESI,this
    //         00401024     PUSH       EAX
    //         00401025     PUSH       EDI
    //         00401026     MOV        dword ptr [ESP + local_10],ESI
    //         0040102a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //                              Act_atak.cpp:47 (35)
    //         0040102f     LEA        this,[ESI + 0x4c]
    //         00401032     PUSH       0x4
    //         00401034     PUSH       this
    //         00401035     PUSH       EDI
    //         00401036     MOV        dword ptr [ESP + local_4],0x0
    //         0040103e     MOV        dword ptr [ESI],RGE_Action_Attack::`vftable'     = 00401150
    //         00401044     MOV        word ptr [ESI + 0x4],0x9
    //         0040104a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040104f     ADD        ESP,0xc
    //                              Act_atak.cpp:48 (15)
    //         00401052     LEA        EDX,[ESI + 0x50]
    //         00401055     PUSH       0x4
    //         00401057     PUSH       EDX
    //         00401058     PUSH       EDI
    //         00401059     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040105e     ADD        ESP,0xc
    //                              Act_atak.cpp:49 (15)
    //         00401061     LEA        EAX,[ESI + 0x54]
    //         00401064     PUSH       0x2
    //         00401066     PUSH       EAX
    //         00401067     PUSH       EDI
    //         00401068     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040106d     ADD        ESP,0xc
    //                              Act_atak.cpp:50 (15)
    //         00401070     LEA        this,[ESI + 0x56]
    //         00401073     PUSH       0x2
    //         00401075     PUSH       this
    //         00401076     PUSH       EDI
    //         00401077     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040107c     ADD        ESP,0xc
    //                              Act_atak.cpp:51 (15)
    //         0040107f     LEA        EDX,[ESI + 0x58]
    //         00401082     PUSH       0x1
    //         00401084     PUSH       EDX
    //         00401085     PUSH       EDI
    //         00401086     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040108b     ADD        ESP,0xc
    //                              Act_atak.cpp:52 (15)
    //         0040108e     LEA        EAX,[ESI + 0x59]
    //         00401091     PUSH       0x1
    //         00401093     PUSH       EAX
    //         00401094     PUSH       EDI
    //         00401095     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040109a     ADD        ESP,0xc
    //                              Act_atak.cpp:53 (15)
    //         0040109d     LEA        this,[ESI + 0x5a]
    //         004010a0     PUSH       0x1
    //         004010a2     PUSH       this
    //         004010a3     PUSH       EDI
    //         004010a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004010a9     ADD        ESP,0xc
    //                              Act_atak.cpp:55 (13)
    //         004010ac     LEA        EDX=>param_2,[ESP + 0x20]
    //         004010b0     PUSH       0x2
    //         004010b2     PUSH       EDX
    //         004010b3     PUSH       EDI
    //         004010b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:56 (16)
    //         004010b9     MOV        EAX,dword ptr [ESP + param_2]
    //         004010bd     MOV        this,dword ptr [ESI + 0x8]
    //         004010c0     ADD        ESP,0xc
    //         004010c3     PUSH       EAX
    //         004010c4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:58 (16)
    //         004010c9     LEA        this=>param_2,[ESP + 0x20]
    //         004010cd     PUSH       0x2
    //         004010cf     PUSH       this
    //         004010d0     PUSH       EDI
    //         004010d1     MOV        dword ptr [ESI + 0x40],EAX
    //         004010d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:59 (19)
    //         004010d9     MOV        EDX,dword ptr [ESP + param_2]
    //         004010dd     MOV        this,dword ptr [ESI + 0x8]
    //         004010e0     ADD        ESP,0xc
    //         004010e3     PUSH       EDX
    //         004010e4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //         004010e9     MOV        dword ptr [ESI + 0x44],EAX
    //                              Act_atak.cpp:61 (13)
    //         004010ec     LEA        EAX=>param_2,[ESP + 0x20]
    //         004010f0     PUSH       0x2
    //         004010f2     PUSH       EAX
    //         004010f3     PUSH       EDI
    //         004010f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:62 (16)
    //         004010f9     MOV        this,dword ptr [ESP + param_2]
    //         004010fd     ADD        ESP,0xc
    //         00401100     PUSH       this
    //         00401101     MOV        this,dword ptr [ESI + 0x8]
    //         00401104     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:63 (24)
    //         00401109     MOV        this,dword ptr [ESP + local_c]
    //         0040110d     MOV        dword ptr [ESI + 0x48],EAX
    //         00401110     MOV        EAX,ESI
    //         00401112     POP        EDI
    //         00401113     MOV        dword ptr FS:[0x0],this
    //         0040111a     POP        ESI
    //         0040111b     ADD        ESP,0x10
    //         0040111e     RET        0x8
    //         00401121     ??         90h
    //         00401122     NOP
    //         00401123     NOP
    //         00401124     NOP
    //         00401125     NOP
    //         00401126     NOP
    //         00401127     NOP
    //         00401128     NOP
    //         00401129     NOP
    //         0040112a     NOP
    //         0040112b     NOP
    //         0040112c     NOP
    //         0040112d     NOP
    //         0040112e     NOP
    //         0040112f     NOP
}

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5, RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_Attack(RGE_Action_Attack * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040101c(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[7]:     00401016(R), 004010ac(*), 004010b9(R), 004010c9(*), 
    //                                                                                     004010d9(R), 004010ec(*), 004010f9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00401036(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00401109(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00401026(W)  
    //                               ??0RGE_Action_Attack@@QAE@HPAVRGE_Action_Object@@@Z          XREF[3]:     004000ac(*), 00400184(*), 
    //                               RGE_Action_Attack::RGE_Action_Attack                                      create_action:0040401f(c)  
    //                              Act_atak.cpp:42 (47)
    //         00401000     PUSH       -0x1
    //         00401002     PUSH       FUN_0055c0b8
    //         00401007     MOV        EAX,FS:[0x0]
    //         0040100d     PUSH       EAX
    //         0040100e     MOV        dword ptr FS:[0x0],ESP
    //         00401015     PUSH       this
    //         00401016     MOV        EAX,dword ptr [ESP + param_2]
    //         0040101a     PUSH       ESI
    //         0040101b     PUSH       EDI
    //         0040101c     MOV        EDI,dword ptr [ESP + param_1]
    //         00401020     PUSH       0x1
    //         00401022     MOV        ESI,this
    //         00401024     PUSH       EAX
    //         00401025     PUSH       EDI
    //         00401026     MOV        dword ptr [ESP + local_10],ESI
    //         0040102a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //                              Act_atak.cpp:47 (35)
    //         0040102f     LEA        this,[ESI + 0x4c]
    //         00401032     PUSH       0x4
    //         00401034     PUSH       this
    //         00401035     PUSH       EDI
    //         00401036     MOV        dword ptr [ESP + local_4],0x0
    //         0040103e     MOV        dword ptr [ESI],RGE_Action_Attack::`vftable'     = 00401150
    //         00401044     MOV        word ptr [ESI + 0x4],0x9
    //         0040104a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040104f     ADD        ESP,0xc
    //                              Act_atak.cpp:48 (15)
    //         00401052     LEA        EDX,[ESI + 0x50]
    //         00401055     PUSH       0x4
    //         00401057     PUSH       EDX
    //         00401058     PUSH       EDI
    //         00401059     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040105e     ADD        ESP,0xc
    //                              Act_atak.cpp:49 (15)
    //         00401061     LEA        EAX,[ESI + 0x54]
    //         00401064     PUSH       0x2
    //         00401066     PUSH       EAX
    //         00401067     PUSH       EDI
    //         00401068     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040106d     ADD        ESP,0xc
    //                              Act_atak.cpp:50 (15)
    //         00401070     LEA        this,[ESI + 0x56]
    //         00401073     PUSH       0x2
    //         00401075     PUSH       this
    //         00401076     PUSH       EDI
    //         00401077     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040107c     ADD        ESP,0xc
    //                              Act_atak.cpp:51 (15)
    //         0040107f     LEA        EDX,[ESI + 0x58]
    //         00401082     PUSH       0x1
    //         00401084     PUSH       EDX
    //         00401085     PUSH       EDI
    //         00401086     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040108b     ADD        ESP,0xc
    //                              Act_atak.cpp:52 (15)
    //         0040108e     LEA        EAX,[ESI + 0x59]
    //         00401091     PUSH       0x1
    //         00401093     PUSH       EAX
    //         00401094     PUSH       EDI
    //         00401095     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040109a     ADD        ESP,0xc
    //                              Act_atak.cpp:53 (15)
    //         0040109d     LEA        this,[ESI + 0x5a]
    //         004010a0     PUSH       0x1
    //         004010a2     PUSH       this
    //         004010a3     PUSH       EDI
    //         004010a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004010a9     ADD        ESP,0xc
    //                              Act_atak.cpp:55 (13)
    //         004010ac     LEA        EDX=>param_2,[ESP + 0x20]
    //         004010b0     PUSH       0x2
    //         004010b2     PUSH       EDX
    //         004010b3     PUSH       EDI
    //         004010b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:56 (16)
    //         004010b9     MOV        EAX,dword ptr [ESP + param_2]
    //         004010bd     MOV        this,dword ptr [ESI + 0x8]
    //         004010c0     ADD        ESP,0xc
    //         004010c3     PUSH       EAX
    //         004010c4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:58 (16)
    //         004010c9     LEA        this=>param_2,[ESP + 0x20]
    //         004010cd     PUSH       0x2
    //         004010cf     PUSH       this
    //         004010d0     PUSH       EDI
    //         004010d1     MOV        dword ptr [ESI + 0x40],EAX
    //         004010d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:59 (19)
    //         004010d9     MOV        EDX,dword ptr [ESP + param_2]
    //         004010dd     MOV        this,dword ptr [ESI + 0x8]
    //         004010e0     ADD        ESP,0xc
    //         004010e3     PUSH       EDX
    //         004010e4     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //         004010e9     MOV        dword ptr [ESI + 0x44],EAX
    //                              Act_atak.cpp:61 (13)
    //         004010ec     LEA        EAX=>param_2,[ESP + 0x20]
    //         004010f0     PUSH       0x2
    //         004010f2     PUSH       EAX
    //         004010f3     PUSH       EDI
    //         004010f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Act_atak.cpp:62 (16)
    //         004010f9     MOV        this,dword ptr [ESP + param_2]
    //         004010fd     ADD        ESP,0xc
    //         00401100     PUSH       this
    //         00401101     MOV        this,dword ptr [ESI + 0x8]
    //         00401104     CALL       RGE_Static_Object::get_sprite_pointer            RGE_Sprite * get_sprite_pointer(RGE_Static_Ob
    //                              Act_atak.cpp:63 (24)
    //         00401109     MOV        this,dword ptr [ESP + local_c]
    //         0040110d     MOV        dword ptr [ESI + 0x48],EAX
    //         00401110     MOV        EAX,ESI
    //         00401112     POP        EDI
    //         00401113     MOV        dword ptr FS:[0x0],this
    //         0040111a     POP        ESI
    //         0040111b     ADD        ESP,0x10
    //         0040111e     RET        0x8
    //         00401121     ??         90h
    //         00401122     NOP
    //         00401123     NOP
    //         00401124     NOP
    //         00401125     NOP
    //         00401126     NOP
    //         00401127     NOP
    //         00401128     NOP
    //         00401129     NOP
    //         0040112a     NOP
    //         0040112b     NOP
    //         0040112c     NOP
    //         0040112d     NOP
    //         0040112e     NOP
    //         0040112f     NOP
}

RGE_Action_Attack::~RGE_Action_Attack() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Action_Attack(RGE_Action_Attack * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //                               ??1RGE_Action_Attack@@UAE@XZ                                 XREF[1]:     `vector_deleting_destructor':00401
    //                               RGE_Action_Attack::~RGE_Action_Attack
    //                              Act_atak.cpp:196 (11)
    //         004013a0     MOV        dword ptr [this->_padding_],RGE_Action_Attack:   = 00401150
    //         004013a6     JMP        RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         004013ab     ??         90h
    //         004013ac     NOP
    //         004013ad     NOP
    //         004013ae     NOP
    //         004013af     NOP
}

void RGE_Action_Attack::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Action_Attack * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[10]:    004013b2(R), 00401432(W), 00401438(W), 00401440(*), 
    //                                                                                     0040145b(W), 00401461(W), 00401469(*), 00401484(W), 
    //                                                                                     0040148a(W), 00401492(*)  
    //                               ?save@RGE_Action_Attack@@UAEXH@Z                             XREF[1]:     0056e06c(*)  
    //                               RGE_Action_Attack::save
    //                              Act_atak.cpp:221 (2)
    //         004013b0     PUSH       ESI
    //         004013b1     PUSH       EDI
    //                              Act_atak.cpp:222 (12)
    //         004013b2     MOV        EDI,dword ptr [ESP + param_1]
    //         004013b6     MOV        ESI,this
    //         004013b8     PUSH       EDI
    //         004013b9     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
    //                              Act_atak.cpp:224 (15)
    //         004013be     LEA        EAX,[ESI + 0x4c]
    //         004013c1     PUSH       0x4
    //         004013c3     PUSH       EAX
    //         004013c4     PUSH       EDI
    //         004013c5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004013ca     ADD        ESP,0xc
    //                              Act_atak.cpp:225 (15)
    //         004013cd     LEA        this,[ESI + 0x50]
    //         004013d0     PUSH       0x4
    //         004013d2     PUSH       this
    //         004013d3     PUSH       EDI
    //         004013d4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004013d9     ADD        ESP,0xc
    //                              Act_atak.cpp:226 (15)
    //         004013dc     LEA        EDX,[ESI + 0x54]
    //         004013df     PUSH       0x2
    //         004013e1     PUSH       EDX
    //         004013e2     PUSH       EDI
    //         004013e3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004013e8     ADD        ESP,0xc
    //                              Act_atak.cpp:227 (15)
    //         004013eb     LEA        EAX,[ESI + 0x56]
    //         004013ee     PUSH       0x2
    //         004013f0     PUSH       EAX
    //         004013f1     PUSH       EDI
    //         004013f2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004013f7     ADD        ESP,0xc
    //                              Act_atak.cpp:228 (15)
    //         004013fa     LEA        this,[ESI + 0x58]
    //         004013fd     PUSH       0x1
    //         004013ff     PUSH       this
    //         00401400     PUSH       EDI
    //         00401401     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00401406     ADD        ESP,0xc
    //                              Act_atak.cpp:229 (15)
    //         00401409     LEA        EDX,[ESI + 0x59]
    //         0040140c     PUSH       0x1
    //         0040140e     PUSH       EDX
    //         0040140f     PUSH       EDI
    //         00401410     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00401415     ADD        ESP,0xc
    //                              Act_atak.cpp:230 (12)
    //         00401418     LEA        EAX,[ESI + 0x5a]
    //         0040141b     PUSH       0x1
    //         0040141d     PUSH       EAX
    //         0040141e     PUSH       EDI
    //         0040141f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              Act_atak.cpp:233 (10)
    //         00401424     MOV        EAX,dword ptr [ESI + 0x40]
    //         00401427     ADD        ESP,0xc
    //         0040142a     TEST       EAX,EAX
    //         0040142c     JZ         LAB_00401438
    //                              Act_atak.cpp:234 (8)
    //         0040142e     MOV        this,word ptr [EAX + 0x72]
    //         00401432     MOV        dword ptr [ESP + param_1],this
    //                              Act_atak.cpp:235 (2)
    //         00401436     JMP        LAB_00401440
    //                               LAB_00401438                                                 XREF[1]:     0040142c(j)  
    //                              Act_atak.cpp:236 (8)
    //         00401438     MOV        dword ptr [ESP + param_1],0xffffffff
    //                               LAB_00401440                                                 XREF[1]:     00401436(j)  
    //                              Act_atak.cpp:237 (13)
    //         00401440     LEA        EDX=>param_1,[ESP + 0xc]
    //         00401444     PUSH       0x2
    //         00401446     PUSH       EDX
    //         00401447     PUSH       EDI
    //         00401448     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              Act_atak.cpp:239 (10)
    //         0040144d     MOV        EAX,dword ptr [ESI + 0x44]
    //         00401450     ADD        ESP,0xc
    //         00401453     TEST       EAX,EAX
    //         00401455     JZ         LAB_00401461
    //                              Act_atak.cpp:240 (8)
    //         00401457     MOV        AX,word ptr [EAX + 0x72]
    //         0040145b     MOV        dword ptr [ESP + param_1],EAX
    //                              Act_atak.cpp:241 (2)
    //         0040145f     JMP        LAB_00401469
    //                               LAB_00401461                                                 XREF[1]:     00401455(j)  
    //                              Act_atak.cpp:242 (8)
    //         00401461     MOV        dword ptr [ESP + param_1],0xffffffff
    //                               LAB_00401469                                                 XREF[1]:     0040145f(j)  
    //                              Act_atak.cpp:243 (13)
    //         00401469     LEA        this=>param_1,[ESP + 0xc]
    //         0040146d     PUSH       0x2
    //         0040146f     PUSH       this
    //         00401470     PUSH       EDI
    //         00401471     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              Act_atak.cpp:245 (10)
    //         00401476     MOV        ESI,dword ptr [ESI + 0x48]
    //         00401479     ADD        ESP,0xc
    //         0040147c     TEST       ESI,ESI
    //         0040147e     JZ         LAB_0040148a
    //                              Act_atak.cpp:246 (8)
    //         00401480     MOV        DX,word ptr [ESI + 0x72]
    //         00401484     MOV        dword ptr [ESP + param_1],EDX
    //                              Act_atak.cpp:247 (2)
    //         00401488     JMP        LAB_00401492
    //                               LAB_0040148a                                                 XREF[1]:     0040147e(j)  
    //                              Act_atak.cpp:248 (8)
    //         0040148a     MOV        dword ptr [ESP + param_1],0xffffffff
    //                               LAB_00401492                                                 XREF[1]:     00401488(j)  
    //                              Act_atak.cpp:249 (16)
    //         00401492     LEA        EAX=>param_1,[ESP + 0xc]
    //         00401496     PUSH       0x2
    //         00401498     PUSH       EAX
    //         00401499     PUSH       EDI
    //         0040149a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040149f     ADD        ESP,0xc
    //                              Act_atak.cpp:250 (5)
    //         004014a2     POP        EDI
    //         004014a3     POP        ESI
    //         004014a4     RET        0x4
    //         004014a7     ??         90h
    //         004014a8     NOP
    //         004014a9     NOP
    //         004014aa     NOP
    //         004014ab     NOP
    //         004014ac     NOP
    //         004014ad     NOP
    //         004014ae     NOP
    //         004014af     NOP
    return;
}

void RGE_Action_Attack::first_in_stack(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall first_in_stack(RGE_Action_Attack * this, uchar param
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              int               Stack[-0x8]:4  rangeStatus
    //                               ?first_in_stack@RGE_Action_Attack@@UAEXE@Z                   XREF[1]:     0056e074(*)  
    //                               RGE_Action_Attack::first_in_stack
    //                              Act_atak.cpp:256 (4)
    //         004014b0     PUSH       this
    //         004014b1     PUSH       ESI
    //         004014b2     MOV        ESI,this
    //                              Act_atak.cpp:263 (58)
    //         004014b4     MOV        this,dword ptr [ESI + 0x8]
    //         004014b7     MOV        EAX,dword ptr [this->_padding_]
    //         004014b9     CALL       dword ptr [EAX + 0xfc]
    //         004014bf     FCOMP      double ptr [null_0056e0c0]                       = align(11)
    //         004014c5     FNSTSW     AX
    //         004014c7     TEST       AH,0x40
    //         004014ca     JNZ        LAB_004014fc
    //         004014cc     MOV        this,dword ptr [ESI + 0x8]
    //         004014cf     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004014d4     TEST       EAX,EAX
    //         004014d6     JZ         LAB_004014ee
    //         004014d8     MOV        this,dword ptr [ESI + 0x8]
    //         004014db     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004014e0     MOV        this,EAX
    //         004014e2     CALL       UnitAIModule::currentOrder                       int currentOrder(UnitAIModule * this)
    //         004014e7     CMP        EAX,0x2d5
    //         004014ec     JZ         LAB_004014fc
    //                               LAB_004014ee                                                 XREF[1]:     004014d6(j)  
    //                              Act_atak.cpp:298 (9)
    //         004014ee     MOV        EDX,dword ptr [ESI]
    //         004014f0     PUSH       0x4
    //         004014f2     MOV        this,ESI
    //         004014f4     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:299 (5)
    //         004014f7     POP        ESI
    //         004014f8     POP        this
    //         004014f9     RET        0x4
    //                               LAB_004014fc                                                 XREF[2]:     004014ca(j), 004014ec(j)  
    //                              Act_atak.cpp:266 (24)
    //         004014fc     LEA        EAX,[ESP + 0x4]
    //         00401500     MOV        this,ESI
    //         00401502     PUSH       EAX
    //         00401503     MOV        dword ptr [ESP + 0x8],0xffffffff
    //         0040150b     CALL       RGE_Action_Attack::ready_to_attack               int ready_to_attack(RGE_Action_Attack * this,
    //         00401510     TEST       EAX,EAX
    //         00401512     JNZ        LAB_00401529
    //                              Act_atak.cpp:271 (5)
    //         00401514     CMP        dword ptr [ESP + 0x4],0x1
    //                              Act_atak.cpp:277 (2)
    //         00401519     JZ         LAB_00401529
    //                              Act_atak.cpp:283 (9)
    //         0040151b     MOV        EAX,dword ptr [ESI]
    //         0040151d     PUSH       0xd
    //         0040151f     MOV        this,ESI
    //         00401521     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:299 (5)
    //         00401524     POP        ESI
    //         00401525     POP        this
    //         00401526     RET        0x4
    //                               LAB_00401529                                                 XREF[2]:     00401512(j), 00401519(j)  
    //                              Act_atak.cpp:291 (9)
    //         00401529     MOV        EDX,dword ptr [ESI]
    //         0040152b     PUSH       0x6
    //         0040152d     MOV        this,ESI
    //         0040152f     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:299 (5)
    //         00401532     POP        ESI
    //         00401533     POP        this
    //         00401534     RET        0x4
    //         00401537     ??         90h
    //         00401538     NOP
    //         00401539     NOP
    //         0040153a     NOP
    //         0040153b     NOP
    //         0040153c     NOP
    //         0040153d     NOP
    //         0040153e     NOP
    //         0040153f     NOP
    return;
}

int RGE_Action_Attack::stop() {
    /* TODO: Stub */
    //                              int __thiscall stop(RGE_Action_Attack * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //                               ?stop@RGE_Action_Attack@@UAEHXZ                              XREF[1]:     0056e084(*)  
    //                               RGE_Action_Attack::stop
    //                              Act_atak.cpp:305 (7)
    //         00401540     MOV        EAX,dword ptr [this->_padding_]
    //         00401542     PUSH       0x1
    //         00401544     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:307 (5)
    //         00401547     MOV        EAX,0x1
    //                              Act_atak.cpp:308 (1)
    //         0040154c     RET
    //         0040154d     ??         90h
    //         0040154e     NOP
    //         0040154f     NOP
    return 0;
}

void RGE_Action_Attack::set_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_state(RGE_Action_Attack * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[5]:     00401571(R), 004015ca(W), 004015fb(W), 004016b9(*), 
    //                                                                                     004016c3(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004015d0(W), 00401601(W), 00401630(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0040159a(R), 00401694(R), 00401733(R)  
    //                               ?set_state@RGE_Action_Attack@@MAEXE@Z                        XREF[1]:     0056e0b4(*)  
    //                               RGE_Action_Attack::set_state
    //                              Act_atak.cpp:314 (25)
    //         00401550     MOV        EAX,FS:[0x0]
    //         00401556     PUSH       -0x1
    //         00401558     PUSH       FUN_0055c106
    //         0040155d     PUSH       EAX
    //         0040155e     MOV        dword ptr FS:[0x0],ESP
    //         00401565     PUSH       ESI
    //         00401566     MOV        ESI,this
    //         00401568     PUSH       EDI
    //                              Act_atak.cpp:321 (8)
    //         00401569     MOV        this,dword ptr [ESI + 0x34]
    //         0040156c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              Act_atak.cpp:324 (7)
    //         00401571     MOV        EAX,dword ptr [ESP + param_1]
    //         00401575     MOV        byte ptr [ESI + 0xc],AL
    //                              Act_atak.cpp:327 (30)
    //         00401578     AND        EAX,0xff
    //         0040157d     DEC        EAX
    //         0040157e     CMP        EAX,0xd
    //         00401581     JA         switchD_0040158f::caseD_3
    //         00401587     XOR        this,this
    //         00401589     MOV        this,byte ptr [EAX + 0x401764]=>PTR_caseD_3_00
    //                               switchD_0040158f::switchD
    //         0040158f     JMP        dword ptr [this->_padding_*0x4 + switchD_00401   = 00401727
    //                               switchD_0040158f::caseD_2                                    XREF[2]:     0040158f(j), 0040174c(*)  
    //                              Act_atak.cpp:330 (4)
    //         00401596     MOV        byte ptr [ESI + 0x5a],0x0
    //                              Act_atak.cpp:403 (19)
    //         0040159a     MOV        this,dword ptr [ESP + local_c]
    //         0040159e     MOV        dword ptr FS:[0x0],this
    //         004015a5     POP        EDI
    //         004015a6     POP        ESI
    //         004015a7     ADD        ESP,0xc
    //         004015aa     RET        0x4
    //                               switchD_0040158f::caseD_4                                    XREF[2]:     0040158f(j), 00401750(*)  
    //                              Act_atak.cpp:336 (7)
    //         004015ad     MOV        AL,byte ptr [ESI + 0x5a]
    //         004015b0     TEST       AL,AL
    //         004015b2     JBE        LAB_004015b9
    //                              Act_atak.cpp:337 (5)
    //         004015b4     DEC        AL
    //         004015b6     MOV        byte ptr [ESI + 0x5a],AL
    //                               LAB_004015b9                                                 XREF[1]:     004015b2(j)  
    //                              Act_atak.cpp:340 (3)
    //         004015b9     MOV        EAX,dword ptr [ESI + 0x10]
    //                              Act_atak.cpp:341 (53)
    //         004015bc     PUSH       0x44
    //         004015be     TEST       EAX,EAX
    //         004015c0     JZ         LAB_004015f3
    //         004015c2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004015c7     ADD        ESP,0x4
    //         004015ca     MOV        dword ptr [ESP + param_1],EAX
    //         004015ce     TEST       EAX,EAX
    //         004015d0     MOV        dword ptr [ESP + local_4],0x0
    //         004015d8     JZ         LAB_0040162c
    //         004015da     MOV        EDX,dword ptr [ESI + 0x40]
    //         004015dd     MOV        this,dword ptr [ESI + 0x4c]
    //         004015e0     PUSH       EDX
    //         004015e1     MOV        EDX,dword ptr [ESI + 0x10]
    //         004015e4     PUSH       this
    //         004015e5     MOV        this,dword ptr [ESI + 0x8]
    //         004015e8     PUSH       EDX
    //         004015e9     PUSH       this
    //         004015ea     MOV        this,EAX
    //         004015ec     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //                              Act_atak.cpp:342 (2)
    //         004015f1     JMP        LAB_0040162e
    //                               LAB_004015f3                                                 XREF[1]:     004015c0(j)  
    //                              Act_atak.cpp:344 (69)
    //         004015f3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004015f8     ADD        ESP,0x4
    //         004015fb     MOV        dword ptr [ESP + param_1],EAX
    //         004015ff     TEST       EAX,EAX
    //         00401601     MOV        dword ptr [ESP + local_4],0x1
    //         00401609     JZ         LAB_0040162c
    //         0040160b     MOV        EDX,dword ptr [ESI + 0x40]
    //         0040160e     MOV        this,dword ptr [ESI + 0x4c]
    //         00401611     PUSH       EDX
    //         00401612     MOV        EDX,dword ptr [ESI + 0x28]
    //         00401615     PUSH       this
    //         00401616     MOV        this,dword ptr [ESI + 0x24]
    //         00401619     PUSH       EDX
    //         0040161a     MOV        EDX,dword ptr [ESI + 0x20]
    //         0040161d     PUSH       this
    //         0040161e     MOV        this,dword ptr [ESI + 0x8]
    //         00401621     PUSH       EDX
    //         00401622     PUSH       this
    //         00401623     MOV        this,EAX
    //         00401625     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         0040162a     JMP        LAB_0040162e
    //                               LAB_0040162c                                                 XREF[2]:     004015d8(j), 00401609(j)  
    //         0040162c     XOR        EAX,EAX
    //                               LAB_0040162e                                                 XREF[2]:     004015f1(j), 0040162a(j)  
    //         0040162e     MOV        EDI,EAX
    //         00401630     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Act_atak.cpp:346 (4)
    //         00401638     TEST       EDI,EDI
    //         0040163a     JNZ        LAB_0040167b
    //                              Act_atak.cpp:348 (7)
    //         0040163c     MOV        AL,byte ptr [ESI + 0x3c]
    //         0040163f     TEST       AL,AL
    //         00401641     JNZ        LAB_0040165f
    //                              Act_atak.cpp:353 (28)
    //         00401643     MOV        this,dword ptr [ESI + 0x8]
    //         00401646     PUSH       EDI
    //         00401647     PUSH       EDI
    //         00401648     PUSH       0x262
    //         0040164d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00401650     MOV        EDX,dword ptr [this->_padding_]
    //         00401652     PUSH       0x1f9
    //         00401657     PUSH       EAX
    //         00401658     PUSH       EAX
    //         00401659     CALL       dword ptr [EDX + 0x148]
    //                               LAB_0040165f                                                 XREF[1]:     00401641(j)  
    //                              Act_atak.cpp:355 (9)
    //         0040165f     MOV        EAX,dword ptr [ESI]
    //         00401661     PUSH       0x1
    //         00401663     MOV        this,ESI
    //         00401665     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:403 (19)
    //         00401668     MOV        this,dword ptr [ESP + 0x8]
    //         0040166c     MOV        dword ptr FS:[0x0],this
    //         00401673     POP        EDI
    //         00401674     POP        ESI
    //         00401675     ADD        ESP,0xc
    //         00401678     RET        0x4
    //                               LAB_0040167b                                                 XREF[1]:     0040163a(j)  
    //                              Act_atak.cpp:358 (9)
    //         0040167b     MOV        this,dword ptr [ESI + 0x34]
    //         0040167e     PUSH       EDI
    //         0040167f     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                              Act_atak.cpp:359 (9)
    //         00401684     PUSH       0x1
    //         00401686     MOV        this,EDI
    //         00401688     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
    //                              Act_atak.cpp:361 (7)
    //         0040168d     MOV        dword ptr [ESI + 0x2c],0x0
    //                              Act_atak.cpp:403 (19)
    //         00401694     MOV        this,dword ptr [ESP + local_c]
    //         00401698     MOV        dword ptr FS:[0x0],this
    //         0040169f     POP        EDI
    //         004016a0     POP        ESI
    //         004016a1     ADD        ESP,0xc
    //         004016a4     RET        0x4
    //                               switchD_0040158f::caseD_6                                    XREF[2]:     0040158f(j), 00401754(*)  
    //                              Act_atak.cpp:366 (14)
    //         004016a7     MOV        AL,byte ptr [ESI + 0x5a]
    //         004016aa     TEST       AL,AL
    //         004016ac     JBE        LAB_004016b9
    //         004016ae     MOV        EAX,dword ptr [ESI + 0x10]
    //         004016b1     TEST       EAX,EAX
    //         004016b3     JZ         LAB_004016b9
    //                              Act_atak.cpp:367 (4)
    //         004016b5     MOV        byte ptr [ESI + 0x5a],0x0
    //                               LAB_004016b9                                                 XREF[2]:     004016ac(j), 004016b3(j)  
    //                              Act_atak.cpp:372 (23)
    //         004016b9     LEA        this=>param_1,[ESP + 0x18]
    //         004016bd     OR         EDI,0xffffffff
    //         004016c0     PUSH       this
    //         004016c1     MOV        this,ESI
    //         004016c3     MOV        dword ptr [ESP + param_1],EDI
    //         004016c7     CALL       RGE_Action_Attack::ready_to_attack               int ready_to_attack(RGE_Action_Attack * this,
    //         004016cc     TEST       EAX,EAX
    //         004016ce     JZ         LAB_004016f4
    //                              Act_atak.cpp:374 (8)
    //         004016d0     MOV        this,dword ptr [ESI + 0x8]
    //         004016d3     CALL       RGE_Combat_Object::reset_attack_timer            void reset_attack_timer(RGE_Combat_Object * t
    //                              Act_atak.cpp:375 (9)
    //         004016d8     MOV        EDX,dword ptr [ESI]
    //         004016da     PUSH       0x7
    //         004016dc     MOV        this,ESI
    //         004016de     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:403 (19)
    //         004016e1     MOV        this,dword ptr [ESP + 0x8]
    //         004016e5     MOV        dword ptr FS:[0x0],this
    //         004016ec     POP        EDI
    //         004016ed     POP        ESI
    //         004016ee     ADD        ESP,0xc
    //         004016f1     RET        0x4
    //                               LAB_004016f4                                                 XREF[1]:     004016ce(j)  
    //                              Act_atak.cpp:381 (14)
    //         004016f4     MOV        this,dword ptr [ESI + 0x8]
    //         004016f7     CMP        word ptr [ESI + 0x54],DI
    //         004016fb     MOV        EAX,dword ptr [this->_padding_]
    //         004016fd     JNZ        LAB_0040172c
    //         004016ff     MOV        EDX,dword ptr [ESI + 0x44]
    //                              Act_atak.cpp:382 (2)
    //         00401702     JMP        LAB_0040172f
    //                               switchD_0040158f::caseD_7                                    XREF[2]:     0040158f(j), 00401758(*)  
    //                              Act_atak.cpp:390 (12)
    //         00401704     MOV        this,dword ptr [ESI + 0x8]
    //         00401707     MOV        EDX,dword ptr [ESI + 0x44]
    //         0040170a     PUSH       EDX
    //         0040170b     MOV        EAX,dword ptr [this->_padding_]
    //         0040170d     CALL       dword ptr [EAX + 0x38]
    //                              Act_atak.cpp:391 (4)
    //         00401710     MOV        byte ptr [ESI + 0x58],0x1
    //                              Act_atak.cpp:403 (19)
    //         00401714     MOV        this,dword ptr [ESP + 0x8]
    //         00401718     MOV        dword ptr FS:[0x0],this
    //         0040171f     POP        EDI
    //         00401720     POP        ESI
    //         00401721     ADD        ESP,0xc
    //         00401724     RET        0x4
    //                               switchD_0040158f::caseD_d                                    XREF[3]:     0040158f(j), 00401748(*), 
    //                               switchD_0040158f::caseD_e                                                 0040175c(*)  
    //                               switchD_0040158f::caseD_1
    //                              Act_atak.cpp:400 (12)
    //         00401727     MOV        this,dword ptr [ESI + 0x8]
    //         0040172a     MOV        EAX,dword ptr [this->_padding_]
    //                               LAB_0040172c                                                 XREF[1]:     004016fd(j)  
    //         0040172c     MOV        EDX,dword ptr [ESI + 0x48]
    //                               LAB_0040172f                                                 XREF[1]:     00401702(j)  
    //         0040172f     PUSH       EDX
    //         00401730     CALL       dword ptr [EAX + 0x38]
    //                               switchD_0040158f::caseD_5                                    XREF[3]:     00401581(j), 0040158f(j), 
    //                               switchD_0040158f::caseD_8                                                 00401760(*)  
    //                               switchD_0040158f::caseD_9
    //                               switchD_0040158f::caseD_a
    //                               switchD_0040158f::caseD_b
    //                               switchD_0040158f::caseD_c
    //                               switchD_0040158f::caseD_3
    //                              Act_atak.cpp:403 (63)
    //         00401733     MOV        this,dword ptr [ESP + local_c]
    //         00401737     POP        EDI
    //         00401738     MOV        dword ptr FS:[0x0],this
    //         0040173f     POP        ESI
    //         00401740     ADD        ESP,0xc
    //         00401743     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00401746()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00401746
    //         00401746     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040158f::switchdataD_00401748                       XREF[1]:     set_state:0040158f(*)  
    //         00401748     addr       switchD_0040158f::caseD_1
    //         0040174c     addr       switchD_0040158f::caseD_2
    //         00401750     addr       switchD_0040158f::caseD_4
    //         00401754     addr       switchD_0040158f::caseD_6
    //         00401758     addr       switchD_0040158f::caseD_7
    //         0040175c     addr       switchD_0040158f::caseD_1
    //                               PTR_caseD_3_00401760+3                                       XREF[0,1]:   set_state:00401589(*)  
    //         00401760     addr       switchD_0040158f::caseD_3
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040158f::switchdataD_00401764
    //         00401764     db         0h
    //         00401765     db         1h
    //         00401766     db         6h
    //         00401767     db         2h
    //         00401768     db         6h
    //         00401769     db         3h
    //         0040176a     db         4h
    //         0040176b     db         6h
    //         0040176c     db         6h
    //         0040176d     db         6h
    //         0040176e     db         6h
    //         0040176f     db         6h
    //         00401770     db         5h
    //         00401771     db         5h
    //         00401772     ??         90h
    //         00401773     ??         90h
    //         00401774     ??         90h
    //         00401775     ??         90h
    //         00401776     ??         90h
    //         00401777     ??         90h
    //         00401778     ??         90h
    //         00401779     ??         90h
    //         0040177a     ??         90h
    //         0040177b     ??         90h
    //         0040177c     ??         90h
    //         0040177d     ??         90h
    //         0040177e     ??         90h
    //         0040177f     ??         90h
    return;
}

uchar RGE_Action_Attack::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Action_Attack * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int               Stack[-0x8]:4  rangeStatus
    //                               ?update@RGE_Action_Attack@@UAEEXZ                            XREF[1]:     0056e080(*)  
    //                               RGE_Action_Attack::update
    //                              Act_atak.cpp:409 (5)
    //         00401780     PUSH       this
    //         00401781     PUSH       ESI
    //         00401782     MOV        ESI,this
    //         00401784     PUSH       EDI
    //                              Act_atak.cpp:446 (9)
    //         00401785     MOV        EAX,dword ptr [ESI + 0x8]
    //         00401788     MOV        this,dword ptr [EAX + 0xc]
    //         0040178b     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              Act_atak.cpp:459 (34)
    //         0040178e     MOV        this,dword ptr [ESI + 0x18]
    //         00401791     CMP        this,-0x1
    //         00401794     FLD        float ptr [EDX + 0x84]
    //         0040179a     FADD       float ptr [ESI + 0x2c]
    //         0040179d     FSTP       float ptr [ESI + 0x2c]
    //         004017a0     JZ         LAB_004017b2
    //         004017a2     MOV        EAX,dword ptr [EAX + 0xc]
    //         004017a5     PUSH       this
    //         004017a6     MOV        this,dword ptr [EAX + 0x3c]
    //         004017a9     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004017ae     TEST       EAX,EAX
    //                              Act_atak.cpp:465 (2)
    //         004017b0     JZ         LAB_004017e3
    //                               LAB_004017b2                                                 XREF[1]:     004017a0(j)  
    //                              Act_atak.cpp:468 (27)
    //         004017b2     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004017b5     CMP        EAX,-0x1
    //         004017b8     JZ         LAB_004017d6
    //         004017ba     MOV        this,dword ptr [ESI + 0x8]
    //         004017bd     PUSH       EAX
    //         004017be     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004017c1     MOV        this,dword ptr [EDX + 0x3c]
    //         004017c4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         004017c9     TEST       EAX,EAX
    //         004017cb     JNZ        LAB_004017d6
    //                              Act_atak.cpp:472 (9)
    //         004017cd     MOV        EAX,dword ptr [ESI]
    //         004017cf     PUSH       0x0
    //         004017d1     MOV        this,ESI
    //         004017d3     CALL       dword ptr [EAX + 0x58]
    //                               LAB_004017d6                                                 XREF[2]:     004017b8(j), 004017cb(j)  
    //                              Act_atak.cpp:475 (13)
    //         004017d6     MOV        EAX,dword ptr [ESI + 0x10]
    //         004017d9     TEST       EAX,EAX
    //         004017db     JZ         LAB_00401834
    //         004017dd     CMP        byte ptr [EAX + 0x48],0x3
    //         004017e1     JC         LAB_004017f9
    //                               LAB_004017e3                                                 XREF[1]:     004017b0(j)  
    //                              Act_atak.cpp:480 (9)
    //         004017e3     MOV        EDI,dword ptr [ESI]
    //         004017e5     PUSH       0x0
    //         004017e7     MOV        this,ESI
    //         004017e9     CALL       dword ptr [EDI + 0x54]
    //                              Act_atak.cpp:481 (7)
    //         004017ec     PUSH       0x2
    //         004017ee     MOV        this,ESI
    //         004017f0     CALL       dword ptr [EDI + 0x5c]
    //                              Act_atak.cpp:482 (2)
    //         004017f3     MOV        AL,0x5
    //                              Act_atak.cpp:704 (4)
    //         004017f5     POP        EDI
    //         004017f6     POP        ESI
    //         004017f7     POP        this
    //         004017f8     RET
    //                               LAB_004017f9                                                 XREF[1]:     004017e1(j)  
    //                              Act_atak.cpp:488 (34)
    //         004017f9     TEST       EAX,EAX
    //         004017fb     JZ         LAB_00401834
    //         004017fd     MOV        this,dword ptr [ESI + 0x8]
    //         00401800     MOV        this,dword ptr [ECX + this->_padding_]
    //         00401803     CMP        word ptr [ECX + this+0x4a],0x0
    //         00401808     JZ         LAB_00401834
    //         0040180a     MOV        EAX,dword ptr [EAX + 0xc]
    //         0040180d     MOV        EDX,dword ptr [this->_padding_]
    //         0040180f     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         00401813     PUSH       EAX
    //         00401814     CALL       dword ptr [EDX + 0x1c]
    //         00401817     TEST       EAX,EAX
    //         00401819     JZ         LAB_00401834
    //                              Act_atak.cpp:490 (9)
    //         0040181b     MOV        EDX,dword ptr [ESI]
    //         0040181d     PUSH       0x1
    //         0040181f     MOV        this,ESI
    //         00401821     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:491 (11)
    //         00401824     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401827     TEST       AL,AL
    //         00401829     JNZ        LAB_004018e6
    //                              Act_atak.cpp:498 (5)
    //         0040182f     JMP        LAB_004018c6
    //                               LAB_00401834                                                 XREF[4]:     004017db(j), 004017fb(j), 
    //                                                                                                         00401808(j), 00401819(j)  
    //                              Act_atak.cpp:502 (14)
    //         00401834     MOV        EAX,dword ptr [ESI + 0x10]
    //         00401837     TEST       EAX,EAX
    //         00401839     JZ         LAB_00401848
    //         0040183b     MOV        this,dword ptr [EAX + 0x20]
    //         0040183e     TEST       this,this
    //         00401840     JZ         LAB_00401848
    //                              Act_atak.cpp:504 (4)
    //         00401842     MOV        EAX,dword ptr [ESI]
    //         00401844     PUSH       0x1
    //                              Act_atak.cpp:512 (2)
    //         00401846     JMP        LAB_004018ba
    //                               LAB_00401848                                                 XREF[2]:     00401839(j), 00401840(j)  
    //                              Act_atak.cpp:515 (26)
    //         00401848     XOR        EAX,EAX
    //         0040184a     MOV        AL,byte ptr [ESI + 0xc]
    //         0040184d     DEC        EAX
    //         0040184e     CMP        EAX,0xc
    //         00401851     JA         switchD_0040185b::caseD_3
    //         00401853     XOR        this,this
    //         00401855     MOV        this,byte ptr [EAX + 0x401aac]=>PTR_caseD_3_00
    //                               switchD_0040185b::switchD
    //         0040185b     JMP        dword ptr [this->_padding_*0x4 + switchD_00401   = 00401a88
    //                               switchD_0040185b::caseD_4                                    XREF[2]:     0040185b(j), 00401a98(*)  
    //                              Act_atak.cpp:522 (26)
    //         00401862     MOV        this,dword ptr [ESI + 0x34]
    //         00401865     MOV        EDX,dword ptr [this->_padding_]
    //         00401867     CALL       dword ptr [EDX + 0xc]
    //         0040186a     AND        EAX,0xff
    //         0040186f     DEC        EAX
    //         00401870     CMP        EAX,0x3
    //         00401873     JA         switchD_0040185b::caseD_3
    //                               switchD_00401875::switchD
    //         00401875     JMP        dword ptr [EAX*0x4 + switchD_00401875::switchd   = 004018ec
    //                               switchD_00401875::caseD_2                                    XREF[2]:     00401875(j), 00401ac4(*)  
    //                              Act_atak.cpp:528 (9)
    //         0040187c     MOV        EAX,dword ptr [ESI]
    //         0040187e     PUSH       0xd
    //         00401880     MOV        this,ESI
    //         00401882     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:529 (7)
    //         00401885     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401888     TEST       AL,AL
    //         0040188a     JNZ        LAB_004018aa
    //                               switchD_0040185b::caseD_d                                    XREF[2]:     0040185b(j), 00401aa4(*)  
    //                              Act_atak.cpp:699 (30)
    //         0040188c     MOV        this,dword ptr [ESI + 0x8]
    //         0040188f     PUSH       0x0
    //         00401891     PUSH       0x0
    //         00401893     PUSH       0x258
    //         00401898     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040189b     MOV        EDX,dword ptr [this->_padding_]
    //         0040189d     PUSH       0x1f9
    //         004018a2     PUSH       EAX
    //         004018a3     PUSH       EAX
    //         004018a4     CALL       dword ptr [EDX + 0x148]
    //                               LAB_004018aa                                                 XREF[1]:     0040188a(j)  
    //                              Act_atak.cpp:700 (2)
    //         004018aa     MOV        AL,0x3
    //                              Act_atak.cpp:704 (4)
    //         004018ac     POP        EDI
    //         004018ad     POP        ESI
    //         004018ae     POP        this
    //         004018af     RET
    //                               switchD_0040185b::caseD_5                                    XREF[10]:    00401851(j), 0040185b(j), 
    //                               switchD_0040185b::caseD_8                                                 00401873(j), 00401911(j), 
    //                               switchD_0040185b::caseD_9                                                 00401976(j), 0040197e(j), 
    //                               switchD_0040185b::caseD_a                                                 004019ae(j), 00401a18(j), 
    //                               switchD_0040185b::caseD_b                                                 00401a3c(j), 00401aa8(*)  
    //                               switchD_0040185b::caseD_c
    //                               switchD_00401875::default
    //                               switchD_0040185b::caseD_3
    //                              Act_atak.cpp:703 (2)
    //         004018b0     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         004018b2     POP        EDI
    //         004018b3     POP        ESI
    //         004018b4     POP        this
    //         004018b5     RET
    //                               switchD_00401875::caseD_3                                    XREF[2]:     00401875(j), 00401ac8(*)  
    //                              Act_atak.cpp:541 (9)
    //         004018b6     MOV        EAX,dword ptr [ESI]
    //         004018b8     PUSH       0xe
    //                               LAB_004018ba                                                 XREF[1]:     00401846(j)  
    //         004018ba     MOV        this,ESI
    //         004018bc     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:542 (7)
    //         004018bf     MOV        AL,byte ptr [ESI + 0x3c]
    //         004018c2     TEST       AL,AL
    //         004018c4     JNZ        LAB_004018e6
    //                               LAB_004018c6                                                 XREF[1]:     0040182f(j)  
    //                              Act_atak.cpp:546 (32)
    //         004018c6     MOV        this,dword ptr [ESI + 0x8]
    //         004018c9     MOV        ESI,dword ptr [ESI + 0x18]
    //         004018cc     PUSH       0x0
    //         004018ce     PUSH       ESI
    //         004018cf     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004018d2     MOV        EDX,dword ptr [this->_padding_]
    //         004018d4     PUSH       0x258
    //         004018d9     PUSH       0x1fb
    //         004018de     PUSH       EAX
    //         004018df     PUSH       EAX
    //         004018e0     CALL       dword ptr [EDX + 0x148]
    //                               LAB_004018e6                                                 XREF[2]:     00401829(j), 004018c4(j)  
    //                              Act_atak.cpp:548 (2)
    //         004018e6     MOV        AL,0x4
    //                              Act_atak.cpp:704 (4)
    //         004018e8     POP        EDI
    //         004018e9     POP        ESI
    //         004018ea     POP        this
    //         004018eb     RET
    //                               switchD_00401875::caseD_1                                    XREF[3]:     00401875(j), 00401abc(*), 
    //                               switchD_00401875::caseD_0                                                 00401ac0(*)  
    //                              Act_atak.cpp:555 (9)
    //         004018ec     MOV        EAX,dword ptr [ESI]
    //         004018ee     PUSH       0x6
    //         004018f0     MOV        this,ESI
    //         004018f2     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:703 (2)
    //         004018f5     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         004018f7     POP        EDI
    //         004018f8     POP        ESI
    //         004018f9     POP        this
    //         004018fa     RET
    //                               switchD_0040185b::caseD_6                                    XREF[2]:     0040185b(j), 00401a9c(*)  
    //                              Act_atak.cpp:567 (24)
    //         004018fb     LEA        this,[ESP + 0x8]
    //         004018ff     MOV        dword ptr [ESP + 0x8],0xffffffff
    //         00401907     PUSH       this
    //         00401908     MOV        this,ESI
    //         0040190a     CALL       RGE_Action_Attack::ready_to_attack               int ready_to_attack(RGE_Action_Attack * this,
    //         0040190f     TEST       EAX,EAX
    //         00401911     JZ         switchD_0040185b::caseD_3
    //                              Act_atak.cpp:570 (8)
    //         00401913     MOV        this,dword ptr [ESI + 0x8]
    //         00401916     CALL       RGE_Combat_Object::reset_attack_timer            void reset_attack_timer(RGE_Combat_Object * t
    //                              Act_atak.cpp:571 (9)
    //         0040191b     MOV        EDX,dword ptr [ESI]
    //         0040191d     PUSH       0x7
    //         0040191f     MOV        this,ESI
    //         00401921     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:703 (2)
    //         00401924     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         00401926     POP        EDI
    //         00401927     POP        ESI
    //         00401928     POP        this
    //         00401929     RET
    //                               switchD_0040185b::caseD_7                                    XREF[2]:     0040185b(j), 00401aa0(*)  
    //                              Act_atak.cpp:577 (11)
    //         0040192a     MOV        AL,byte ptr [ESI + 0x58]
    //         0040192d     TEST       AL,AL
    //         0040192f     JNZ        LAB_004019e0
    //                              Act_atak.cpp:583 (12)
    //         00401935     MOV        this,dword ptr [ESI + 0x8]
    //         00401938     MOV        EAX,dword ptr [this->_padding_]
    //         0040193a     CALL       dword ptr [EAX + 0x7c]
    //         0040193d     CMP        AL,0x1
    //         0040193f     JNZ        LAB_0040198a
    //                              Act_atak.cpp:585 (14)
    //         00401941     MOV        EAX,dword ptr [ESI + 0x10]
    //         00401944     TEST       EAX,EAX
    //         00401946     JNZ        LAB_0040195e
    //         00401948     MOV        AL,byte ptr [ESI + 0x5a]
    //         0040194b     TEST       AL,AL
    //         0040194d     JNZ        LAB_0040195e
    //                              Act_atak.cpp:587 (9)
    //         0040194f     MOV        EDX,dword ptr [ESI]
    //         00401951     PUSH       0x2
    //         00401953     MOV        this,ESI
    //         00401955     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:703 (2)
    //         00401958     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         0040195a     POP        EDI
    //         0040195b     POP        ESI
    //         0040195c     POP        this
    //         0040195d     RET
    //                               LAB_0040195e                                                 XREF[2]:     00401946(j), 0040194d(j)  
    //                              Act_atak.cpp:593 (8)
    //         0040195e     MOV        this,dword ptr [ESI + 0x8]
    //         00401961     CALL       RGE_Combat_Object::reset_attack_timer            void reset_attack_timer(RGE_Combat_Object * t
    //                              Act_atak.cpp:594 (11)
    //         00401966     MOV        EAX,dword ptr [ESI]
    //         00401968     PUSH       0x6
    //         0040196a     MOV        this,ESI
    //         0040196c     MOV        EDI,dword ptr [EAX + 0x5c]
    //         0040196f     CALL       EDI
    //                              Act_atak.cpp:598 (19)
    //         00401971     MOV        AL,byte ptr [ESI + 0xc]
    //         00401974     CMP        AL,0xd
    //         00401976     JZ         switchD_0040185b::caseD_3
    //         0040197c     CMP        AL,0x4
    //         0040197e     JZ         switchD_0040185b::caseD_3
    //                              Act_atak.cpp:600 (6)
    //         00401984     PUSH       0x7
    //         00401986     MOV        this,ESI
    //         00401988     CALL       EDI
    //                               LAB_0040198a                                                 XREF[1]:     0040193f(j)  
    //                              Act_atak.cpp:605 (7)
    //         0040198a     MOV        AL,byte ptr [ESI + 0x58]
    //         0040198d     TEST       AL,AL
    //         0040198f     JNZ        LAB_004019e0
    //                              Act_atak.cpp:608 (35)
    //         00401991     MOV        EAX,dword ptr [ESI + 0x8]
    //         00401994     MOV        this,dword ptr [EAX + 0x18]
    //         00401997     MOV        EAX,dword ptr [EAX + 0x10]
    //         0040199a     PUSH       EAX
    //         0040199b     MOV        EDX,dword ptr [this->_padding_]
    //         0040199d     CALL       dword ptr [EDX + 0x24]
    //         004019a0     CMP        AL,0x1
    //         004019a2     JZ         LAB_004019b4
    //         004019a4     MOV        this,dword ptr [ESI + 0x8]
    //         004019a7     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004019aa     TEST       byte ptr [EDX + 0x70],0x1
    //         004019ae     JNZ        switchD_0040185b::caseD_3
    //                               LAB_004019b4                                                 XREF[1]:     004019a2(j)  
    //                              Act_atak.cpp:616 (14)
    //         004019b4     MOV        EAX,dword ptr [ESI + 0x10]
    //         004019b7     TEST       EAX,EAX
    //         004019b9     JNZ        LAB_004019d1
    //         004019bb     MOV        AL,byte ptr [ESI + 0x5a]
    //         004019be     TEST       AL,AL
    //         004019c0     JNZ        LAB_004019d1
    //                              Act_atak.cpp:621 (9)
    //         004019c2     MOV        EAX,dword ptr [ESI]
    //         004019c4     PUSH       0x2
    //         004019c6     MOV        this,ESI
    //         004019c8     CALL       dword ptr [EAX + 0x5c]
    //                              Act_atak.cpp:703 (2)
    //         004019cb     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         004019cd     POP        EDI
    //         004019ce     POP        ESI
    //         004019cf     POP        this
    //         004019d0     RET
    //                               LAB_004019d1                                                 XREF[2]:     004019b9(j), 004019c0(j)  
    //                              Act_atak.cpp:628 (9)
    //         004019d1     MOV        EDX,dword ptr [ESI]
    //         004019d3     PUSH       0x6
    //         004019d5     MOV        this,ESI
    //         004019d7     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:703 (2)
    //         004019da     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         004019dc     POP        EDI
    //         004019dd     POP        ESI
    //         004019de     POP        this
    //         004019df     RET
    //                               LAB_004019e0                                                 XREF[2]:     0040192f(j), 0040198f(j)  
    //                              Act_atak.cpp:635 (9)
    //         004019e0     MOV        AX,word ptr [ESI + 0x56]
    //         004019e4     TEST       AX,AX
    //         004019e7     JNZ        LAB_00401a06
    //                              Act_atak.cpp:640 (29)
    //         004019e9     MOV        EAX,dword ptr [ESI + 0x8]
    //         004019ec     MOV        this,dword ptr [EAX + 0x10]
    //         004019ef     MOVSX      EDX,word ptr [this->_padding_ + 0x5e]
    //         004019f3     MOV        dword ptr [ESP + 0x8],EDX
    //         004019f7     FILD       dword ptr [ESP + 0x8]
    //         004019fb     FMUL       float ptr [null_0056e0c8]                        = align(3)
    //         00401a01     CALL       __ftol                                           undefined __ftol()
    //                               LAB_00401a06                                                 XREF[1]:     004019e7(j)  
    //                              Act_atak.cpp:656 (24)
    //         00401a06     MOV        EDX,dword ptr [ESI + 0x8]
    //         00401a09     PUSH       EAX
    //         00401a0a     MOV        this,dword ptr [EDX + 0x18]
    //         00401a0d     MOV        EAX,dword ptr [EDX + 0x10]
    //         00401a10     PUSH       EAX
    //         00401a11     MOV        EDI,dword ptr [this->_padding_]
    //         00401a13     CALL       dword ptr [EDI + 0x20]
    //         00401a16     TEST       AL,AL
    //         00401a18     JZ         switchD_0040185b::caseD_3
    //                              Act_atak.cpp:661 (7)
    //         00401a1e     MOV        this,ESI
    //         00401a20     CALL       RGE_Action_Attack::do_attack                     void do_attack(RGE_Action_Attack * this)
    //                              Act_atak.cpp:703 (2)
    //         00401a25     XOR        AL,AL
    //                              Act_atak.cpp:704 (4)
    //         00401a27     POP        EDI
    //         00401a28     POP        ESI
    //         00401a29     POP        this
    //         00401a2a     RET
    //                               switchD_0040185b::caseD_2                                    XREF[2]:     0040185b(j), 00401a94(*)  
    //                              Act_atak.cpp:669 (23)
    //         00401a2b     MOV        EAX,dword ptr [ESI + 0x8]
    //         00401a2e     MOV        this,dword ptr [EAX + 0x18]
    //         00401a31     MOV        EAX,dword ptr [EAX + 0x10]
    //         00401a34     PUSH       EAX
    //         00401a35     MOV        EDX,dword ptr [this->_padding_]
    //         00401a37     CALL       dword ptr [EDX + 0x24]
    //         00401a3a     CMP        AL,0x1
    //         00401a3c     JNZ        switchD_0040185b::caseD_3
    //                              Act_atak.cpp:674 (9)
    //         00401a42     MOV        EDI,dword ptr [ESI]
    //         00401a44     PUSH       0x0
    //         00401a46     MOV        this,ESI
    //         00401a48     CALL       dword ptr [EDI + 0x54]
    //                              Act_atak.cpp:675 (7)
    //         00401a4b     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401a4e     TEST       AL,AL
    //         00401a50     JNZ        LAB_00401a70
    //                              Act_atak.cpp:679 (30)
    //         00401a52     MOV        this,dword ptr [ESI + 0x8]
    //         00401a55     PUSH       0x0
    //         00401a57     PUSH       0x0
    //         00401a59     PUSH       0x258
    //         00401a5e     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00401a61     MOV        EDX,dword ptr [this->_padding_]
    //         00401a63     PUSH       0x1fa
    //         00401a68     PUSH       EAX
    //         00401a69     PUSH       EAX
    //         00401a6a     CALL       dword ptr [EDX + 0x148]
    //                               LAB_00401a70                                                 XREF[1]:     00401a50(j)  
    //                              Act_atak.cpp:681 (7)
    //         00401a70     PUSH       0x1
    //         00401a72     MOV        this,ESI
    //         00401a74     CALL       dword ptr [EDI + 0x5c]
    //                              Act_atak.cpp:682 (13)
    //         00401a77     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401a7a     DEC        AL
    //         00401a7c     NEG        AL
    //         00401a7e     SBB        AL,AL
    //         00401a80     AND        AL,0xfd
    //         00401a82     ADD        AL,0x5
    //                              Act_atak.cpp:704 (72)
    //         00401a84     POP        EDI
    //         00401a85     POP        ESI
    //         00401a86     POP        this
    //         00401a87     RET
    //                               switchD_0040185b::caseD_1                                    XREF[2]:     0040185b(j), 00401a90(*)  
    //         00401a88     POP        EDI
    //         00401a89     MOV        AL,0x1
    //         00401a8b     POP        ESI
    //         00401a8c     POP        this
    //         00401a8d     RET
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00401a8e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00401a8e
    //         00401a8e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040185b::switchdataD_00401a90                       XREF[1]:     update:0040185b(*)  
    //         00401a90     addr       switchD_0040185b::caseD_1
    //         00401a94     addr       switchD_0040185b::caseD_2
    //         00401a98     addr       switchD_0040185b::caseD_4
    //         00401a9c     addr       switchD_0040185b::caseD_6
    //         00401aa0     addr       switchD_0040185b::caseD_7
    //         00401aa4     addr       switchD_0040185b::caseD_d
    //                               PTR_caseD_3_00401aa8+3                                       XREF[0,1]:   update:00401855(*)  
    //         00401aa8     addr       switchD_0040185b::caseD_3
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040185b::switchdataD_00401aac
    //         00401aac     db         0h
    //         00401aad     db         1h
    //         00401aae     db         6h
    //         00401aaf     db         2h
    //         00401ab0     db         6h
    //         00401ab1     db         3h
    //         00401ab2     db         4h
    //         00401ab3     db         6h
    //         00401ab4     db         6h
    //         00401ab5     db         6h
    //         00401ab6     db         6h
    //         00401ab7     db         6h
    //         00401ab8     db         5h
    //         00401ab9     ??         90h
    //         00401aba     ??         8Bh
    //         00401abb     ??         FFh
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00401875::switchdataD_00401abc                       XREF[1]:     update:00401875(*)  
    //         00401abc     addr       switchD_00401875::caseD_0
    //         00401ac0     addr       switchD_00401875::caseD_0
    //         00401ac4     addr       switchD_00401875::caseD_2
    //         00401ac8     addr       switchD_00401875::caseD_3
    //         00401acc     ??         90h
    //         00401acd     ??         90h
    //         00401ace     ??         90h
    //         00401acf     ??         90h
    return 0;
}

int RGE_Action_Attack::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
    //                              int __thiscall work(RGE_Action_Attack * this, RGE_Static_Object * pa
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00401ad0(R)  
    //              float             Stack[0x8]:4   param_2
    //              float             Stack[0xc]:4   param_3
    //              float             Stack[0x10]:4  param_4
    //                               ?work@RGE_Action_Attack@@UAEHPAVRGE_Static_Object@@MMM@Z     XREF[1]:     0056e08c(*)  
    //                               RGE_Action_Attack::work
    //                              Act_atak.cpp:711 (12)
    //         00401ad0     MOV        EAX,dword ptr [ESP + param_1]
    //         00401ad4     PUSH       ESI
    //         00401ad5     TEST       EAX,EAX
    //         00401ad7     PUSH       EDI
    //         00401ad8     MOV        ESI,this
    //         00401ada     JZ         LAB_00401b1a
    //                              Act_atak.cpp:729 (23)
    //         00401adc     CMP        EAX,dword ptr [ESI + 0x10]
    //         00401adf     JNZ        LAB_00401afd
    //         00401ae1     MOV        this,byte ptr [ESI + 0xc]
    //         00401ae4     CMP        this,0x4
    //         00401ae7     JZ         LAB_00401b10
    //         00401ae9     CMP        this,0x6
    //         00401aec     JZ         LAB_00401b10
    //         00401aee     CMP        this,0x7
    //         00401af1     JNZ        LAB_00401afd
    //                              Act_atak.cpp:730 (5)
    //         00401af3     MOV        EAX,0x1
    //                              Act_atak.cpp:744 (5)
    //         00401af8     POP        EDI
    //         00401af9     POP        ESI
    //         00401afa     RET        0x10
    //                               LAB_00401afd                                                 XREF[2]:     00401adf(j), 00401af1(j)  
    //                              Act_atak.cpp:736 (12)
    //         00401afd     MOV        EDI,dword ptr [ESI]
    //         00401aff     PUSH       EAX
    //         00401b00     MOV        this,ESI
    //         00401b02     MOV        byte ptr [ESI + 0x5a],0x0
    //         00401b06     CALL       dword ptr [EDI + 0x54]
    //                              Act_atak.cpp:737 (7)
    //         00401b09     PUSH       0x4
    //         00401b0b     MOV        this,ESI
    //         00401b0d     CALL       dword ptr [EDI + 0x5c]
    //                               LAB_00401b10                                                 XREF[2]:     00401ae7(j), 00401aec(j)  
    //                              Act_atak.cpp:738 (5)
    //         00401b10     MOV        EAX,0x1
    //                              Act_atak.cpp:744 (12)
    //         00401b15     POP        EDI
    //         00401b16     POP        ESI
    //         00401b17     RET        0x10
    //                               LAB_00401b1a                                                 XREF[1]:     00401ada(j)  
    //         00401b1a     POP        EDI
    //         00401b1b     XOR        EAX,EAX
    //         00401b1d     POP        ESI
    //         00401b1e     RET        0x10
    //         00401b21     ??         90h
    //         00401b22     NOP
    //         00401b23     NOP
    //         00401b24     NOP
    //         00401b25     NOP
    //         00401b26     NOP
    //         00401b27     NOP
    //         00401b28     NOP
    //         00401b29     NOP
    //         00401b2a     NOP
    //         00401b2b     NOP
    //         00401b2c     NOP
    //         00401b2d     NOP
    //         00401b2e     NOP
    //         00401b2f     NOP
    return 0;
}

int RGE_Action_Attack::ready_to_attack(int* param_1) {
    /* TODO: Stub */
    //                              int __thiscall ready_to_attack(RGE_Action_Attack * this, int * param
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              int *             Stack[0x4]:4   param_1
    //              float             Stack[-0x8]:4  z_change
    //              float             Stack[-0xc]:4  y_change
    //                               ?ready_to_attack@RGE_Action_Attack@@IAEHAAH@Z                XREF[3]:     first_in_stack:0040150b(c), 
    //                               RGE_Action_Attack::ready_to_attack                                        set_state:004016c7(c), 
    //                                                                                                         update:0040190a(c)  
    //                              Act_atak.cpp:750 (7)
    //         00401b30     SUB        ESP,0x8
    //         00401b33     PUSH       ESI
    //         00401b34     MOV        ESI,this
    //         00401b36     PUSH       EDI
    //                              Act_atak.cpp:757 (27)
    //         00401b37     MOV        EDX,dword ptr [ESI + 0x24]
    //         00401b3a     MOV        this,dword ptr [ESI + 0x8]
    //         00401b3d     PUSH       EDX
    //         00401b3e     MOV        EDX,dword ptr [ESI + 0x20]
    //         00401b41     MOV        EAX,dword ptr [this->_padding_]
    //         00401b43     PUSH       EDX
    //         00401b44     MOV        EDX,dword ptr [ESI + 0x10]
    //         00401b47     PUSH       EDX
    //         00401b48     CALL       dword ptr [EAX + 0x1f0]
    //         00401b4e     TEST       AL,AL
    //         00401b50     JNZ        LAB_00401b5c
    //                              Act_atak.cpp:758 (2)
    //         00401b52     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401b54     POP        EDI
    //         00401b55     POP        ESI
    //         00401b56     ADD        ESP,0x8
    //         00401b59     RET        0x4
    //                               LAB_00401b5c                                                 XREF[1]:     00401b50(j)  
    //                              Act_atak.cpp:762 (11)
    //         00401b5c     MOV        EDI,dword ptr [ESI + 0x10]
    //         00401b5f     TEST       EDI,EDI
    //         00401b61     JNZ        LAB_00401beb
    //                              Act_atak.cpp:765 (20)
    //         00401b67     MOV        EAX,dword ptr [ESI + 0x28]
    //         00401b6a     MOV        this,dword ptr [ESI + 0x24]
    //         00401b6d     MOV        EDX,dword ptr [ESI + 0x20]
    //         00401b70     PUSH       EAX
    //         00401b71     PUSH       this=>DAT_fffffff8
    //         00401b72     MOV        this,dword ptr [ESI + 0x8]
    //         00401b75     PUSH       EDX=>DAT_fffffff4
    //         00401b76     CALL       RGE_Static_Object::distance_to_position          float distance_to_position(RGE_Static_Object 
    //                              Act_atak.cpp:769 (10)
    //         00401b7b     FCOM       float ptr [ESI + 0x50]
    //         00401b7e     FNSTSW     AX
    //         00401b80     TEST       AH,0x1
    //         00401b83     JZ         LAB_00401b92
    //                              Act_atak.cpp:771 (8)
    //         00401b85     MOV        EAX,dword ptr [ESP + 0x14]
    //         00401b89     FSTP       ST0
    //         00401b8b     MOV        dword ptr [EAX],EDI
    //                              Act_atak.cpp:785 (5)
    //         00401b8d     JMP        LAB_00401d71
    //                               LAB_00401b92                                                 XREF[1]:     00401b83(j)  
    //                              Act_atak.cpp:792 (3)
    //         00401b92     MOV        EAX,dword ptr [ESI + 0x8]
    //                              Act_atak.cpp:796 (71)
    //         00401b95     MOV        EAX,dword ptr [EAX + 0x8]
    //         00401b98     MOV        this,dword ptr [EAX + 0x30]
    //         00401b9b     MOV        dword ptr [ESP + 0x8],this
    //         00401b9f     FLD        float ptr [ESP + 0x8]
    //         00401ba3     FLD        float ptr [EAX + 0x34]
    //         00401ba6     FXCH       ST2
    //         00401ba8     FXCH
    //         00401baa     FLD        ST2
    //         00401bac     FXCH
    //         00401bae     FMUL       float ptr [ESP + 0x8]
    //         00401bb2     FXCH
    //         00401bb4     FMUL       ST3
    //         00401bb6     FADDP
    //         00401bb8     FSQRT
    //         00401bba     FST        float ptr [ESP + 0xc]
    //         00401bbe     FADD       float ptr [ESI + 0x4c]
    //         00401bc1     FSUB       float ptr [DAT_0056e0cc]                         = 9Ah
    //         00401bc7     FSTP       float ptr [ESP + 0xc]
    //         00401bcb     FCOMP      float ptr [ESP + 0xc]
    //         00401bcf     FNSTSW     AX
    //         00401bd1     TEST       AH,0x41
    //         00401bd4     FSTP       ST0
    //         00401bd6     JNZ        LAB_00401ea0
    //                              Act_atak.cpp:798 (10)
    //         00401bdc     MOV        EDX,dword ptr [ESP + 0x14]
    //         00401be0     MOV        dword ptr [EDX],0x2
    //                              Act_atak.cpp:813 (5)
    //         00401be6     JMP        LAB_00401e09
    //                               LAB_00401beb                                                 XREF[1]:     00401b61(j)  
    //                              Act_atak.cpp:825 (29)
    //         00401beb     MOV        this,dword ptr [EDI + 0xc]
    //         00401bee     CMP        word ptr [ECX + this+0x4a],0x0
    //         00401bf3     JLE        LAB_00401c63
    //         00401bf5     MOV        EDX,dword ptr [EDI + 0x8]
    //         00401bf8     MOV        AX,word ptr [EDX + 0x14]
    //         00401bfc     CMP        AX,0x3
    //         00401c00     JZ         LAB_00401c63
    //         00401c02     CMP        AX,0x1b
    //         00401c06     JZ         LAB_00401c63
    //                              Act_atak.cpp:826 (32)
    //         00401c08     FLD        float ptr [EDI + 0x3c]
    //         00401c0b     CALL       __ftol                                           undefined __ftol()
    //         00401c10     FLD        float ptr [EDI + 0x38]
    //         00401c13     PUSH       EAX
    //         00401c14     CALL       __ftol                                           undefined __ftol()
    //         00401c19     PUSH       EAX=>DAT_fffffff8
    //         00401c1a     MOV        EAX,dword ptr [ESI + 0x8]
    //         00401c1d     MOV        this,dword ptr [EAX + 0xc]
    //         00401c20     MOV        this,dword ptr [ECX + this->_padding_]
    //         00401c23     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
    //                              Act_atak.cpp:827 (4)
    //         00401c28     TEST       AL,AL
    //         00401c2a     JNZ        LAB_00401c3f
    //                              Act_atak.cpp:831 (9)
    //         00401c2c     MOV        EDX,dword ptr [ESI]
    //         00401c2e     PUSH       0xd
    //         00401c30     MOV        this,ESI
    //         00401c32     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:832 (2)
    //         00401c35     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401c37     POP        EDI
    //         00401c38     POP        ESI
    //         00401c39     ADD        ESP,0x8
    //         00401c3c     RET        0x4
    //                               LAB_00401c3f                                                 XREF[1]:     00401c2a(j)  
    //                              Act_atak.cpp:834 (17)
    //         00401c3f     CMP        AL,0x80
    //         00401c41     JNZ        LAB_00401c63
    //         00401c43     MOV        EAX,dword ptr [ESI + 0x10]
    //         00401c46     MOV        this,dword ptr [EAX + 0x8]
    //         00401c49     MOV        AL,byte ptr [this->_padding_ + 0x65]
    //         00401c4c     TEST       AL,AL
    //         00401c4e     JNZ        LAB_00401c63
    //                              Act_atak.cpp:838 (9)
    //         00401c50     MOV        EDX,dword ptr [ESI]
    //         00401c52     PUSH       0xd
    //         00401c54     MOV        this,ESI
    //         00401c56     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:839 (2)
    //         00401c59     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401c5b     POP        EDI
    //         00401c5c     POP        ESI
    //         00401c5d     ADD        ESP,0x8
    //         00401c60     RET        0x4
    //                               LAB_00401c63                                                 XREF[5]:     00401bf3(j), 00401c00(j), 
    //                                                                                                         00401c06(j), 00401c41(j), 
    //                                                                                                         00401c4e(j)  
    //                              Act_atak.cpp:846 (46)
    //         00401c63     MOV        EDX,dword ptr [ESI + 0x10]
    //         00401c66     FLD        float ptr [EDX + 0x38]
    //         00401c69     FCOMP      float ptr [ESI + 0x20]
    //         00401c6c     FNSTSW     AX
    //         00401c6e     TEST       AH,0x40
    //         00401c71     JZ         LAB_00401c91
    //         00401c73     FLD        float ptr [EDX + 0x3c]
    //         00401c76     FCOMP      float ptr [ESI + 0x24]
    //         00401c79     FNSTSW     AX
    //         00401c7b     TEST       AH,0x40
    //         00401c7e     JZ         LAB_00401c91
    //         00401c80     FLD        float ptr [EDX + 0x40]
    //         00401c83     FCOMP      float ptr [ESI + 0x28]
    //         00401c86     FNSTSW     AX
    //         00401c88     TEST       AH,0x40
    //         00401c8b     JNZ        LAB_00401ea0
    //                               LAB_00401c91                                                 XREF[2]:     00401c71(j), 00401c7e(j)  
    //                              Act_atak.cpp:848 (6)
    //         00401c91     FLD        float ptr [EDX + 0x38]
    //         00401c94     FSUB       float ptr [ESI + 0x20]
    //                              Act_atak.cpp:850 (11)
    //         00401c97     FLD        float ptr [EDX + 0x40]
    //         00401c9a     FLD        float ptr [EDX + 0x3c]
    //         00401c9d     FSUB       float ptr [ESI + 0x24]
    //         00401ca0     FXCH
    //                              Act_atak.cpp:858 (117)
    //         00401ca2     FLD        ST2
    //         00401ca4     FCOMP      float ptr [null_0056e0c8]                        = align(3)
    //         00401caa     FSUB       float ptr [ESI + 0x28]
    //         00401cad     FXCH
    //         00401caf     FSTP       float ptr [ESP + 0x8]
    //         00401cb3     FNSTSW     AX
    //         00401cb5     FSTP       float ptr [ESP + 0xc]
    //         00401cb9     TEST       AH,0x41
    //         00401cbc     JZ         LAB_00401d15
    //         00401cbe     FCOMP      float ptr [DAT_0056e0d0]
    //         00401cc4     FNSTSW     AX
    //         00401cc6     TEST       AH,0x1
    //         00401cc9     JNZ        LAB_00401d17
    //         00401ccb     FLD        float ptr [ESP + 0x8]
    //         00401ccf     FCOMP      float ptr [null_0056e0c8]                        = align(3)
    //         00401cd5     FNSTSW     AX
    //         00401cd7     TEST       AH,0x41
    //         00401cda     JZ         LAB_00401d17
    //         00401cdc     FLD        float ptr [ESP + 0x8]
    //         00401ce0     FCOMP      float ptr [DAT_0056e0d0]
    //         00401ce6     FNSTSW     AX
    //         00401ce8     TEST       AH,0x1
    //         00401ceb     JNZ        LAB_00401d17
    //         00401ced     FLD        float ptr [ESP + 0xc]
    //         00401cf1     FCOMP      float ptr [null_0056e0c8]                        = align(3)
    //         00401cf7     FNSTSW     AX
    //         00401cf9     TEST       AH,0x41
    //         00401cfc     JZ         LAB_00401d17
    //         00401cfe     FLD        float ptr [ESP + 0xc]
    //         00401d02     FCOMP      float ptr [DAT_0056e0d0]
    //         00401d08     FNSTSW     AX
    //         00401d0a     TEST       AH,0x1
    //         00401d0d     JZ         LAB_00401ea0
    //         00401d13     JMP        LAB_00401d17
    //                               LAB_00401d15                                                 XREF[1]:     00401cbc(j)  
    //         00401d15     FSTP       ST0
    //                               LAB_00401d17                                                 XREF[5]:     00401cc9(j), 00401cda(j), 
    //                                                                                                         00401ceb(j), 00401cfc(j), 
    //                                                                                                         00401d13(j)  
    //                              Act_atak.cpp:860 (9)
    //         00401d17     MOV        this,dword ptr [ESI + 0x8]
    //         00401d1a     PUSH       EDX
    //         00401d1b     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //                              Act_atak.cpp:872 (28)
    //         00401d20     MOV        EAX,dword ptr [ESI + 0x8]
    //         00401d23     MOV        EAX,dword ptr [EAX + 0x8]
    //         00401d26     MOV        this,dword ptr [EAX + 0x30]
    //         00401d29     FLD        float ptr [EAX + 0x34]
    //         00401d2c     MOV        dword ptr [ESP + 0x8],this
    //         00401d30     FLD        float ptr [ESP + 0x8]
    //         00401d34     FLD        ST1
    //         00401d36     FXCH
    //         00401d38     FMUL       float ptr [ESP + 0x8]
    //                              Act_atak.cpp:878 (39)
    //         00401d3c     FLD        ST3
    //         00401d3e     FXCH       ST2
    //         00401d40     FMUL       ST3
    //         00401d42     FXCH       ST2
    //         00401d44     FCOMP      float ptr [ESI + 0x50]
    //         00401d47     FXCH
    //         00401d49     FADDP
    //         00401d4b     FNSTSW     AX
    //         00401d4d     FSQRT
    //         00401d4f     TEST       AH,0x1
    //         00401d52     FSTP       ST1
    //         00401d54     FADD       float ptr [ESI + 0x4c]
    //         00401d57     FSUB       float ptr [DAT_0056e0cc]                         = 9Ah
    //         00401d5d     JZ         LAB_00401dee
    //                              Act_atak.cpp:880 (14)
    //         00401d63     MOV        EDX,dword ptr [ESP + 0x14]
    //         00401d67     FSTP       ST0
    //         00401d69     FSTP       ST0
    //         00401d6b     MOV        dword ptr [EDX],0x0
    //                               LAB_00401d71                                                 XREF[1]:     00401b8d(j)  
    //                              Act_atak.cpp:881 (7)
    //         00401d71     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401d74     TEST       AL,AL
    //         00401d76     JNZ        LAB_00401d93
    //                              Act_atak.cpp:886 (27)
    //         00401d78     MOV        this,dword ptr [ESI + 0x8]
    //         00401d7b     PUSH       0x0
    //         00401d7d     PUSH       0x0=>DAT_fffffff8
    //         00401d7f     PUSH       0x0=>DAT_fffffff4
    //         00401d81     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00401d84     MOV        EDX,dword ptr [this->_padding_]
    //         00401d86     PUSH       offset DAT_fffffff0
    //         00401d8b     PUSH       EAX
    //         00401d8c     PUSH       EAX
    //         00401d8d     CALL       dword ptr [EDX + 0x148]
    //                               LAB_00401d93                                                 XREF[1]:     00401d76(j)  
    //                              Act_atak.cpp:889 (62)
    //         00401d93     MOV        this,dword ptr [ESI + 0x8]
    //         00401d96     MOV        EAX,dword ptr [this->_padding_]
    //         00401d98     CALL       dword ptr [EAX + 0xfc]
    //         00401d9e     FCOMP      double ptr [null_0056e0c0]                       = align(11)
    //         00401da4     FNSTSW     AX
    //         00401da6     TEST       AH,0x40
    //         00401da9     JNZ        LAB_00401ddb
    //         00401dab     MOV        this,dword ptr [ESI + 0x8]
    //         00401dae     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00401db3     TEST       EAX,EAX
    //         00401db5     JZ         LAB_00401e81
    //         00401dbb     MOV        this,dword ptr [ESI + 0x8]
    //         00401dbe     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00401dc3     MOV        this,EAX
    //         00401dc5     CALL       UnitAIModule::currentOrder                       int currentOrder(UnitAIModule * this)
    //         00401dca     CMP        EAX,0x2d5
    //         00401dcf     JZ         LAB_00401ddb
    //                              Act_atak.cpp:900 (2)
    //         00401dd1     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401dd3     POP        EDI
    //         00401dd4     POP        ESI
    //         00401dd5     ADD        ESP,0x8
    //         00401dd8     RET        0x4
    //                               LAB_00401ddb                                                 XREF[2]:     00401da9(j), 00401dcf(j)  
    //                              Act_atak.cpp:890 (9)
    //         00401ddb     MOV        EDX,dword ptr [ESI]
    //         00401ddd     PUSH       0xd
    //         00401ddf     MOV        this,ESI
    //         00401de1     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:894 (2)
    //         00401de4     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401de6     POP        EDI
    //         00401de7     POP        ESI
    //         00401de8     ADD        ESP,0x8
    //         00401deb     RET        0x4
    //                               LAB_00401dee                                                 XREF[1]:     00401d5d(j)  
    //                              Act_atak.cpp:903 (17)
    //         00401dee     FXCH
    //         00401df0     FCOMP
    //         00401df2     FNSTSW     AX
    //         00401df4     TEST       AH,0x41
    //         00401df7     FSTP       ST0
    //         00401df9     JNZ        LAB_00401e8b
    //                              Act_atak.cpp:905 (10)
    //         00401dff     MOV        EAX,dword ptr [ESP + 0x14]
    //         00401e03     MOV        dword ptr [EAX],0x2
    //                               LAB_00401e09                                                 XREF[1]:     00401be6(j)  
    //                              Act_atak.cpp:909 (7)
    //         00401e09     MOV        AL,byte ptr [ESI + 0x3c]
    //         00401e0c     TEST       AL,AL
    //         00401e0e     JNZ        LAB_00401e2b
    //                              Act_atak.cpp:914 (27)
    //         00401e10     MOV        this,dword ptr [ESI + 0x8]
    //         00401e13     PUSH       0x0
    //         00401e15     PUSH       0x0=>DAT_fffffff8
    //         00401e17     PUSH       0x0=>DAT_fffffff4
    //         00401e19     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00401e1c     MOV        EDX,dword ptr [this->_padding_]
    //         00401e1e     PUSH       offset DAT_fffffff0
    //         00401e23     PUSH       EAX
    //         00401e24     PUSH       EAX
    //         00401e25     CALL       dword ptr [EDX + 0x148]
    //                               LAB_00401e2b                                                 XREF[1]:     00401e0e(j)  
    //                              Act_atak.cpp:918 (58)
    //         00401e2b     MOV        this,dword ptr [ESI + 0x8]
    //         00401e2e     MOV        EAX,dword ptr [this->_padding_]
    //         00401e30     CALL       dword ptr [EAX + 0xfc]
    //         00401e36     FCOMP      double ptr [null_0056e0c0]                       = align(11)
    //         00401e3c     FNSTSW     AX
    //         00401e3e     TEST       AH,0x40
    //         00401e41     JNZ        LAB_00401e78
    //         00401e43     MOV        this,dword ptr [ESI + 0x8]
    //         00401e46     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00401e4b     TEST       EAX,EAX
    //         00401e4d     JZ         LAB_00401e65
    //         00401e4f     MOV        this,dword ptr [ESI + 0x8]
    //         00401e52     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00401e57     MOV        this,EAX
    //         00401e59     CALL       UnitAIModule::currentOrder                       int currentOrder(UnitAIModule * this)
    //         00401e5e     CMP        EAX,0x2d5
    //         00401e63     JZ         LAB_00401e78
    //                               LAB_00401e65                                                 XREF[1]:     00401e4d(j)  
    //                              Act_atak.cpp:925 (9)
    //         00401e65     MOV        EDX,dword ptr [ESI]
    //         00401e67     PUSH       0x4
    //         00401e69     MOV        this,ESI
    //         00401e6b     CALL       dword ptr [EDX + 0x5c]
    //                              Act_atak.cpp:929 (2)
    //         00401e6e     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401e70     POP        EDI
    //         00401e71     POP        ESI
    //         00401e72     ADD        ESP,0x8
    //         00401e75     RET        0x4
    //                               LAB_00401e78                                                 XREF[2]:     00401e41(j), 00401e63(j)  
    //                              Act_atak.cpp:919 (9)
    //         00401e78     MOV        EAX,dword ptr [ESI]
    //         00401e7a     PUSH       0xd
    //         00401e7c     MOV        this,ESI
    //         00401e7e     CALL       dword ptr [EAX + 0x5c]
    //                               LAB_00401e81                                                 XREF[1]:     00401db5(j)  
    //                              Act_atak.cpp:923 (2)
    //         00401e81     XOR        EAX,EAX
    //                              Act_atak.cpp:954 (8)
    //         00401e83     POP        EDI
    //         00401e84     POP        ESI
    //         00401e85     ADD        ESP,0x8
    //         00401e88     RET        0x4
    //                               LAB_00401e8b                                                 XREF[1]:     00401df9(j)  
    //                              Act_atak.cpp:932 (9)
    //         00401e8b     MOV        EAX,dword ptr [ESI + 0x10]
    //         00401e8e     MOV        this,dword ptr [EAX + 0x38]
    //         00401e91     MOV        dword ptr [ESI + 0x20],this
    //                              Act_atak.cpp:933 (6)
    //         00401e94     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00401e97     MOV        dword ptr [ESI + 0x24],EDX
    //                              Act_atak.cpp:934 (6)
    //         00401e9a     MOV        EAX,dword ptr [EAX + 0x40]
    //         00401e9d     MOV        dword ptr [ESI + 0x28],EAX
    //                               LAB_00401ea0                                                 XREF[3]:     00401bd6(j), 00401c8b(j), 
    //                                                                                                         00401d0d(j)  
    //                              Act_atak.cpp:940 (10)
    //         00401ea0     MOV        this,dword ptr [ESP + 0x14]
    //         00401ea4     MOV        dword ptr [this->_padding_],0x1
    //                              Act_atak.cpp:942 (12)
    //         00401eaa     MOV        this,dword ptr [ESI + 0x8]
    //         00401ead     MOV        EDX,dword ptr [this->_padding_]
    //         00401eaf     CALL       dword ptr [EDX + 0x7c]
    //         00401eb2     NEG        AL
    //         00401eb4     SBB        EAX,EAX
    //                              Act_atak.cpp:954 (10)
    //         00401eb6     POP        EDI
    //         00401eb7     NEG        EAX
    //         00401eb9     POP        ESI
    //         00401eba     ADD        ESP,0x8
    //         00401ebd     RET        0x4
    return 0;
}

void RGE_Action_Attack::do_attack() {
    /* TODO: Stub */
    //                              void __thiscall do_attack(RGE_Action_Attack * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //                               ?do_attack@RGE_Action_Attack@@IAEXXZ                         XREF[1]:     update:00401a20(c)  
    //                               RGE_Action_Attack::do_attack
    //                              Act_atak.cpp:960 (3)
    //         00401ec0     PUSH       ESI
    //         00401ec1     MOV        ESI,this
    //                              Act_atak.cpp:966 (3)
    //         00401ec3     MOV        EAX,dword ptr [ESI + 0x10]
    //                              Act_atak.cpp:971 (17)
    //         00401ec6     MOV        this,dword ptr [ESI + 0x8]
    //         00401ec9     TEST       EAX,EAX
    //         00401ecb     JZ         LAB_00401edd
    //         00401ecd     MOV        EDX,dword ptr [this->_padding_]
    //         00401ecf     PUSH       this
    //         00401ed0     PUSH       EAX
    //         00401ed1     CALL       dword ptr [EDX + 0x224]
    //                              Act_atak.cpp:982 (4)
    //         00401ed7     MOV        byte ptr [ESI + 0x58],0x0
    //                              Act_atak.cpp:983 (2)
    //         00401edb     POP        ESI
    //         00401edc     RET
    //                               LAB_00401edd                                                 XREF[1]:     00401ecb(j)  
    //                              Act_atak.cpp:975 (21)
    //         00401edd     MOV        EDX,dword ptr [ESI + 0x28]
    //         00401ee0     MOV        EAX,dword ptr [this->_padding_]
    //         00401ee2     PUSH       this
    //         00401ee3     PUSH       EDX
    //         00401ee4     MOV        EDX,dword ptr [ESI + 0x24]
    //         00401ee7     PUSH       EDX
    //         00401ee8     MOV        EDX,dword ptr [ESI + 0x20]
    //         00401eeb     PUSH       EDX
    //         00401eec     CALL       dword ptr [EAX + 0x220]
    //                              Act_atak.cpp:982 (4)
    //         00401ef2     MOV        byte ptr [ESI + 0x58],0x0
    //                              Act_atak.cpp:983 (2)
    //         00401ef6     POP        ESI
    //         00401ef7     RET
    //         00401ef8     ??         90h
    //         00401ef9     NOP
    //         00401efa     NOP
    //         00401efb     NOP
    //         00401efc     NOP
    //         00401efd     NOP
    //         00401efe     NOP
    //         00401eff     NOP
    //                              * protected: virtual void __thiscall RGE_Action_Attack::copy_obj_sprites(class RGE_Master_Action_Obj... *
    //                              void __thiscall copy_obj_sprites(RGE_Action_Attack * this, RGE_Maste
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     00401f0e(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00401f03(R)  
    //              RGE_Task *        Stack[0xc]:4   param_3                   XREF[1]:     00401f09(R)  
    //                               ?copy_obj_sprites@RGE_Action_Attack@@MAEXPAVRGE_Master_Acti  XREF[1]:     0056e09c(*)  
    //                               RGE_Action_Attack::copy_obj_sprites
    //                              Act_atak.cpp:989 (22)
    //         00401f00     MOV        EAX,dword ptr [ECX + this->move_sprite]
    //         00401f03     MOV        EDX,dword ptr [ESP + param_2]
    //         00401f07     PUSH       EBX
    //         00401f08     PUSH       ESI
    //         00401f09     MOV        ESI,dword ptr [ESP + param_3]
    //         00401f0d     PUSH       EDI
    //         00401f0e     MOV        EDI,dword ptr [ESP + param_1]
    //         00401f12     TEST       EAX,EAX
    //         00401f14     JZ         LAB_00401f3f
    //                              Act_atak.cpp:992 (13)
    //         00401f16     TEST       EDX,EDX
    //         00401f18     JZ         LAB_00401f28
    //         00401f1a     TEST       ESI,ESI
    //         00401f1c     JZ         LAB_00401f28
    //         00401f1e     CMP        EAX,dword ptr [EDX + 0x34]
    //         00401f21     JNZ        LAB_00401f28
    //                              Act_atak.cpp:993 (3)
    //         00401f23     MOV        EAX,dword ptr [ESI + 0x34]
    //                              Act_atak.cpp:994 (16)
    //         00401f26     JMP        LAB_00401f3c
    //                               LAB_00401f28                                                 XREF[3]:     00401f18(j), 00401f1c(j), 
    //                                                                                                         00401f21(j)  
    //         00401f28     MOV        EBX,dword ptr [ECX + this->_padding_]
    //         00401f2b     MOV        EBX,dword ptr [EBX + 0x8]
    //         00401f2e     CMP        EAX,dword ptr [EBX + 0xbc]
    //         00401f34     JNZ        LAB_00401f3f
    //                              Act_atak.cpp:995 (9)
    //         00401f36     MOV        EAX,dword ptr [EDI + 0xbc]
    //                               LAB_00401f3c                                                 XREF[1]:     00401f26(j)  
    //         00401f3c     MOV        dword ptr [ECX + this->move_sprite],EAX
    //                               LAB_00401f3f                                                 XREF[2]:     00401f14(j), 00401f34(j)  
    //                              Act_atak.cpp:998 (7)
    //         00401f3f     MOV        EAX,dword ptr [ECX + this->fight_sprite]
    //         00401f42     TEST       EAX,EAX
    //         00401f44     JZ         LAB_00401f81
    //                              Act_atak.cpp:1000 (13)
    //         00401f46     TEST       EDX,EDX
    //         00401f48     JZ         LAB_00401f6a
    //         00401f4a     TEST       ESI,ESI
    //         00401f4c     JZ         LAB_00401f58
    //         00401f4e     CMP        EAX,dword ptr [EDX + 0x38]
    //         00401f51     JNZ        LAB_00401f58
    //                              Act_atak.cpp:1001 (3)
    //         00401f53     MOV        EAX,dword ptr [ESI + 0x38]
    //                              Act_atak.cpp:1002 (15)
    //         00401f56     JMP        LAB_00401f7e
    //                               LAB_00401f58                                                 XREF[2]:     00401f4c(j), 00401f51(j)  
    //         00401f58     TEST       EDX,EDX
    //         00401f5a     JZ         LAB_00401f6a
    //         00401f5c     TEST       ESI,ESI
    //         00401f5e     JZ         LAB_00401f6a
    //         00401f60     CMP        EAX,dword ptr [EDX + 0x3c]
    //         00401f63     JNZ        LAB_00401f6a
    //                              Act_atak.cpp:1003 (3)
    //         00401f65     MOV        EAX,dword ptr [ESI + 0x3c]
    //                              Act_atak.cpp:1004 (16)
    //         00401f68     JMP        LAB_00401f7e
    //                               LAB_00401f6a                                                 XREF[4]:     00401f48(j), 00401f5a(j), 
    //                                                                                                         00401f5e(j), 00401f63(j)  
    //         00401f6a     MOV        EBX,dword ptr [ECX + this->_padding_]
    //         00401f6d     MOV        EBX,dword ptr [EBX + 0x8]
    //         00401f70     CMP        EAX,dword ptr [EBX + 0xfc]
    //         00401f76     JNZ        LAB_00401f81
    //                              Act_atak.cpp:1005 (9)
    //         00401f78     MOV        EAX,dword ptr [EDI + 0xfc]
    //                               LAB_00401f7e                                                 XREF[2]:     00401f56(j), 00401f68(j)  
    //         00401f7e     MOV        dword ptr [ECX + this->fight_sprite],EAX
    //                               LAB_00401f81                                                 XREF[2]:     00401f44(j), 00401f76(j)  
    //                              Act_atak.cpp:1008 (7)
    //         00401f81     MOV        EAX,dword ptr [ECX + this->wait_sprite]
    //         00401f84     TEST       EAX,EAX
    //         00401f86     JZ         LAB_00401fcb
    //                              Act_atak.cpp:1010 (13)
    //         00401f88     TEST       EDX,EDX
    //         00401f8a     JZ         LAB_00401fba
    //         00401f8c     TEST       ESI,ESI
    //         00401f8e     JZ         LAB_00401fa1
    //         00401f90     CMP        EAX,dword ptr [EDX + 0x38]
    //         00401f93     JNZ        LAB_00401fa1
    //                              Act_atak.cpp:1011 (6)
    //         00401f95     MOV        EDX,dword ptr [ESI + 0x38]
    //         00401f98     MOV        dword ptr [ECX + this->wait_sprite],EDX
    //                              Act_atak.cpp:1017 (6)
    //         00401f9b     POP        EDI
    //         00401f9c     POP        ESI
    //         00401f9d     POP        EBX
    //         00401f9e     RET        0xc
    //                               LAB_00401fa1                                                 XREF[2]:     00401f8e(j), 00401f93(j)  
    //                              Act_atak.cpp:1012 (13)
    //         00401fa1     TEST       EDX,EDX
    //         00401fa3     JZ         LAB_00401fba
    //         00401fa5     TEST       ESI,ESI
    //         00401fa7     JZ         LAB_00401fba
    //         00401fa9     CMP        EAX,dword ptr [EDX + 0x3c]
    //         00401fac     JNZ        LAB_00401fba
    //                              Act_atak.cpp:1013 (3)
    //         00401fae     MOV        EAX,dword ptr [ESI + 0x3c]
    //                              Act_atak.cpp:1015 (3)
    //         00401fb1     MOV        dword ptr [ECX + this->wait_sprite],EAX
    //                              Act_atak.cpp:1017 (6)
    //         00401fb4     POP        EDI
    //         00401fb5     POP        ESI
    //         00401fb6     POP        EBX
    //         00401fb7     RET        0xc
    //                               LAB_00401fba                                                 XREF[4]:     00401f8a(j), 00401fa3(j), 
    //                                                                                                         00401fa7(j), 00401fac(j)  
    //                              Act_atak.cpp:1014 (11)
    //         00401fba     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00401fbd     MOV        EDX,dword ptr [EDX + 0x8]
    //         00401fc0     CMP        EAX,dword ptr [EDX + 0x18]
    //         00401fc3     JNZ        LAB_00401fcb
    //                              Act_atak.cpp:1015 (6)
    //         00401fc5     MOV        EAX,dword ptr [EDI + 0x18]
    //         00401fc8     MOV        dword ptr [ECX + this->wait_sprite],EAX
    //                               LAB_00401fcb                                                 XREF[2]:     00401f86(j), 00401fc3(j)  
    //                              Act_atak.cpp:1017 (6)
    //         00401fcb     POP        EDI
    //         00401fcc     POP        ESI
    //         00401fcd     POP        EBX
    //         00401fce     RET        0xc
    //         00401fd1     ??         90h
    //         00401fd2     NOP
    //         00401fd3     NOP
    //         00401fd4     NOP
    //         00401fd5     NOP
    //         00401fd6     NOP
    //         00401fd7     NOP
    //         00401fd8     NOP
    //         00401fd9     NOP
    //         00401fda     NOP
    //         00401fdb     NOP
    //         00401fdc     NOP
    //         00401fdd     NOP
    //         00401fde     NOP
    //         00401fdf     NOP
    return;
}

void RGE_Action_Attack::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

