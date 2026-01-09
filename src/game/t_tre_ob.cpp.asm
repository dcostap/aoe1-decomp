#include "common.h"
#include "t_tre_ob.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Tree_Object(TRIBE_Tree_Object * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Tree_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ccb37(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004ccb3d(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004ccb50(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ccb54(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ccb6f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ccb47(W)  
    //                               ??0TRIBE_Tree_Object@@QAE@HPAVRGE_Game_World@@H@Z
    //                               TRIBE_Tree_Object::TRIBE_Tree_Object
    //                              t_tre_ob.cpp:44 (48)
    //         004ccb20     PUSH       -0x1
    //         004ccb22     PUSH       FUN_0055fd48
    //         004ccb27     MOV        EAX,FS:[0x0]
    //         004ccb2d     PUSH       EAX
    //         004ccb2e     MOV        dword ptr FS:[0x0],ESP
    //         004ccb35     PUSH       this
    //         004ccb36     PUSH       EBX
    //         004ccb37     MOV        EBX,dword ptr [ESP + param_1]
    //         004ccb3b     PUSH       ESI
    //         004ccb3c     PUSH       EDI
    //         004ccb3d     MOV        EDI,dword ptr [ESP + param_2]
    //         004ccb41     PUSH       0x0
    //         004ccb43     MOV        ESI,this
    //         004ccb45     PUSH       EDI
    //         004ccb46     PUSH       EBX
    //         004ccb47     MOV        dword ptr [ESP + local_10],ESI
    //         004ccb4b     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              t_tre_ob.cpp:45 (22)
    //         004ccb50     MOV        EAX,dword ptr [ESP + param_3]
    //         004ccb54     MOV        dword ptr [ESP + local_4],0x0
    //         004ccb5c     TEST       EAX,EAX
    //         004ccb5e     MOV        dword ptr [ESI],TRIBE_Tree_Object::`vftable'     = 004ccaf0
    //         004ccb64     JZ         LAB_004ccb6f
    //                              t_tre_ob.cpp:46 (9)
    //         004ccb66     PUSH       EDI
    //         004ccb67     PUSH       EBX
    //         004ccb68     MOV        this,ESI
    //         004ccb6a     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, int param
    //                               LAB_004ccb6f                                                 XREF[1]:     004ccb64(j)  
    //                              t_tre_ob.cpp:47 (22)
    //         004ccb6f     MOV        this,dword ptr [ESP + local_c]
    //         004ccb73     MOV        EAX,ESI
    //         004ccb75     POP        EDI
    //         004ccb76     POP        ESI
    //         004ccb77     MOV        dword ptr FS:[0x0],this
    //         004ccb7e     POP        EBX
    //         004ccb7f     ADD        ESP,0x10
    //         004ccb82     RET        0xc
    //         004ccb85     ??         90h
    //         004ccb86     NOP
    //         004ccb87     NOP
    //         004ccb88     NOP
    //         004ccb89     NOP
    //         004ccb8a     NOP
    //         004ccb8b     NOP
    //         004ccb8c     NOP
    //         004ccb8d     NOP
    //         004ccb8e     NOP
    //         004ccb8f     NOP
}

TRIBE_Tree_Object::TRIBE_Tree_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Tree_Object(TRIBE_Tree_Object * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Tree_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ccb37(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004ccb3d(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004ccb50(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ccb54(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ccb6f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ccb47(W)  
    //                               ??0TRIBE_Tree_Object@@QAE@HPAVRGE_Game_World@@H@Z
    //                               TRIBE_Tree_Object::TRIBE_Tree_Object
    //                              t_tre_ob.cpp:44 (48)
    //         004ccb20     PUSH       -0x1
    //         004ccb22     PUSH       FUN_0055fd48
    //         004ccb27     MOV        EAX,FS:[0x0]
    //         004ccb2d     PUSH       EAX
    //         004ccb2e     MOV        dword ptr FS:[0x0],ESP
    //         004ccb35     PUSH       this
    //         004ccb36     PUSH       EBX
    //         004ccb37     MOV        EBX,dword ptr [ESP + param_1]
    //         004ccb3b     PUSH       ESI
    //         004ccb3c     PUSH       EDI
    //         004ccb3d     MOV        EDI,dword ptr [ESP + param_2]
    //         004ccb41     PUSH       0x0
    //         004ccb43     MOV        ESI,this
    //         004ccb45     PUSH       EDI
    //         004ccb46     PUSH       EBX
    //         004ccb47     MOV        dword ptr [ESP + local_10],ESI
    //         004ccb4b     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              t_tre_ob.cpp:45 (22)
    //         004ccb50     MOV        EAX,dword ptr [ESP + param_3]
    //         004ccb54     MOV        dword ptr [ESP + local_4],0x0
    //         004ccb5c     TEST       EAX,EAX
    //         004ccb5e     MOV        dword ptr [ESI],TRIBE_Tree_Object::`vftable'     = 004ccaf0
    //         004ccb64     JZ         LAB_004ccb6f
    //                              t_tre_ob.cpp:46 (9)
    //         004ccb66     PUSH       EDI
    //         004ccb67     PUSH       EBX
    //         004ccb68     MOV        this,ESI
    //         004ccb6a     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, int param
    //                               LAB_004ccb6f                                                 XREF[1]:     004ccb64(j)  
    //                              t_tre_ob.cpp:47 (22)
    //         004ccb6f     MOV        this,dword ptr [ESP + local_c]
    //         004ccb73     MOV        EAX,ESI
    //         004ccb75     POP        EDI
    //         004ccb76     POP        ESI
    //         004ccb77     MOV        dword ptr FS:[0x0],this
    //         004ccb7e     POP        EBX
    //         004ccb7f     ADD        ESP,0x10
    //         004ccb82     RET        0xc
    //         004ccb85     ??         90h
    //         004ccb86     NOP
    //         004ccb87     NOP
    //         004ccb88     NOP
    //         004ccb89     NOP
    //         004ccb8a     NOP
    //         004ccb8b     NOP
    //         004ccb8c     NOP
    //         004ccb8d     NOP
    //         004ccb8e     NOP
    //         004ccb8f     NOP
}

void TRIBE_Tree_Object::set_object_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_object_state(TRIBE_Tree_Object * this, uchar par
    //              void              <VOID>         <RETURN>
    //              TRIBE_Tree_Obj    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ccb90(R)  
    //                               ?set_object_state@TRIBE_Tree_Object@@UAEXE@Z                 XREF[1]:     00574d0c(*)  
    //                               TRIBE_Tree_Object::set_object_state
    //                              t_tre_ob.cpp:51 (10)
    //         004ccb90     MOV        EAX,dword ptr [ESP + param_1]
    //         004ccb94     PUSH       EAX
    //         004ccb95     CALL       RGE_Static_Object::set_object_state              void set_object_state(RGE_Static_Object * thi
    //                              t_tre_ob.cpp:62 (3)
    //         004ccb9a     RET        0x4
    //         004ccb9d     ??         90h
    //         004ccb9e     NOP
    //         004ccb9f     NOP
    return;
}

TRIBE_Tree_Object::~TRIBE_Tree_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Tree_Object(TRIBE_Tree_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Tree_Obj    ECX:4 (auto)   this
    //                               ??1TRIBE_Tree_Object@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':004cc
    //                               TRIBE_Tree_Object::~TRIBE_Tree_Object
    //         004ccb10     JMP        RGE_Static_Object::~RGE_Static_Object
    //         004ccb15     ??         90h
    //         004ccb16     NOP
    //         004ccb17     NOP
    //         004ccb18     NOP
    //         004ccb19     NOP
    //         004ccb1a     NOP
    //         004ccb1b     NOP
    //         004ccb1c     NOP
    //         004ccb1d     NOP
    //         004ccb1e     NOP
    //         004ccb1f     NOP
}

