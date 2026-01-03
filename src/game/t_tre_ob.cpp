#include "../common.h"
#include "t_tre_ob.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Tree_Object(TRIBE_Tree_Object * this, TRI
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Tree_Obj    ECX:4 (auto)   this
//              TRIBE_Master_T    Stack[0x4]:4   param_1                   XREF[2]:     004cca8e(R), 004ccabc(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     004cca76(R), 004ccab8(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cca80(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cca7b(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004cca86(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     004ccaa2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ccaa6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ccacc(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cca99(W)
//                               ??0TRIBE_Tree_Object@@QAE@PAVTRIBE_Master_Tree_Object@@PAVR  XREF[1]:     make_new_obj:0050f36f(c)
//                               TRIBE_Tree_Object::TRIBE_Tree_Object
//                              t_tre_ob.cpp:36 (66)
//         004cca60     PUSH       -0x1
//         004cca62     PUSH       FUN_0055fd28
//         004cca67     MOV        EAX,FS:[0x0]
//         004cca6d     PUSH       EAX
//         004cca6e     MOV        dword ptr FS:[0x0],ESP
//         004cca75     PUSH       this
//         004cca76     MOV        EAX,dword ptr [ESP + param_2]
//         004cca7a     PUSH       EBX
//         004cca7b     MOV        EBX,dword ptr [ESP + param_4]
//         004cca7f     PUSH       EBP
//         004cca80     MOV        EBP,dword ptr [ESP + param_3]
//         004cca84     PUSH       ESI
//         004cca85     PUSH       EDI
//         004cca86     MOV        EDI,dword ptr [ESP + param_5]
//         004cca8a     PUSH       0x0
//         004cca8c     MOV        ESI,this
//         004cca8e     MOV        this,dword ptr [ESP + param_1]
//         004cca92     PUSH       EDI
//         004cca93     PUSH       EBX
//         004cca94     PUSH       EBP
//         004cca95     PUSH       EAX
//         004cca96     PUSH       this
//         004cca97     MOV        this,ESI
//         004cca99     MOV        dword ptr [ESP + local_10],ESI
//         004cca9d     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
//                              t_tre_ob.cpp:37 (22)
//         004ccaa2     MOV        EAX,dword ptr [ESP + param_6]
//         004ccaa6     MOV        dword ptr [ESP + local_4],0x0
//         004ccaae     TEST       EAX,EAX
//         004ccab0     MOV        dword ptr [ESI],TRIBE_Tree_Object::`vftable'     = 004ccaf0
//         004ccab6     JZ         LAB_004ccacc
//                              t_tre_ob.cpp:38 (20)
//         004ccab8     MOV        EDX,dword ptr [ESP + param_2]
//         004ccabc     MOV        EAX,dword ptr [ESP + param_1]
//         004ccac0     PUSH       EDI
//         004ccac1     PUSH       EBX
//         004ccac2     PUSH       EBP
//         004ccac3     PUSH       EDX
//         004ccac4     PUSH       EAX
//         004ccac5     MOV        this,ESI
//         004ccac7     CALL       RGE_Static_Object::setup                         int setup(RGE_Static_Object * this, RGE_Maste
//                               LAB_004ccacc                                                 XREF[1]:     004ccab6(j)
//                              t_tre_ob.cpp:39 (23)
//         004ccacc     MOV        this,dword ptr [ESP + local_c]
//         004ccad0     MOV        EAX,ESI
//         004ccad2     POP        EDI
//         004ccad3     POP        ESI
//         004ccad4     POP        EBP
//         004ccad5     MOV        dword ptr FS:[0x0],this
//         004ccadc     POP        EBX
//         004ccadd     ADD        ESP,0x10
//         004ccae0     RET        0x18
//         004ccae3     ??         90h
//         004ccae4     NOP
//         004ccae5     NOP
//         004ccae6     NOP
//         004ccae7     NOP
//         004ccae8     NOP
//         004ccae9     NOP
//         004ccaea     NOP
//         004ccaeb     NOP
//         004ccaec     NOP
//         004ccaed     NOP
//         004ccaee     NOP
//         004ccaef     NOP
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

