#include "../common.h"
#include "action.h"

RGE_Action::RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action(RGE_Action * this, int param_1, RGE_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040747e(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0040747a(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0040746c(R)
//                               ??0RGE_Action@@QAE@HPAVRGE_Action_Object@@H@Z                XREF[21]:    RGE_Action_Attack:0040102a(c),
//                               RGE_Action::RGE_Action                                                    RGE_Action_Bird:00401ff1(c),
//                                                                                                         RGE_Action_Enter:004023d1(c),
//                                                                                                         RGE_Action_Explore:00402b51(c),
//                                                                                                         RGE_Action_Gather:00402eca(c),
//                                                                                                         RGE_Action_Make:004049c1(c),
//                                                                                                         RGE_Action_Missile:00404bda(c),
//                                                                                                         RGE_Action_Move_To:0040553a(c),
//                                                                                                         RGE_Action_Transport:00406d71(c),
//                                                                                                         TRIBE_Action_Artifact:004ccbb1(c),
//                                                                                                         TRIBE_Action_Build:004cd1c1(c),
//                                                                                                         TRIBE_Action_Convert:004cda0b(c),
//                                                                                                         TRIBE_Action_Discovery_Artifact:00
//                                                                                                         TRIBE_Action_Heal:004ce941(c),
//                                                                                                         TRIBE_Action_Hunt:004cf0ba(c),
//                                                                                                         TRIBE_Action_Make_Obj:004d0dfa(c),
//                                                                                                         TRIBE_Action_Repair:004d16ab(c),
//                                                                                                         TRIBE_Action_Make_Tech:004d21da(c)
//                                                                                                         TRIBE_Action_Trade:004d268a(c),
//                                                                                                         TRIBE_Action_Wonder:004d3481(c),
//                                                                                                         [more]
//                              action.cpp:36 (12)
//         00407460     PUSH       ESI
//         00407461     MOV        ESI,this
//         00407463     OR         EAX,0xffffffff
//         00407466     MOV        dword ptr [ESI + 0x18],EAX
//         00407469     MOV        dword ptr [ESI + 0x1c],EAX
//                              action.cpp:40 (14)
//         0040746c     MOV        EAX,dword ptr [ESP + param_3]
//         00407470     MOV        dword ptr [ESI],RGE_Action::`vftable'            = 004074a0
//         00407476     TEST       EAX,EAX
//         00407478     JZ         LAB_0040748b
//                              action.cpp:41 (17)
//         0040747a     MOV        EAX,dword ptr [ESP + param_2]
//         0040747e     MOV        this,dword ptr [ESP + param_1]
//         00407482     PUSH       EAX
//         00407483     PUSH       this
//         00407484     MOV        this,ESI
//         00407486     CALL       RGE_Action::setup                                int setup(RGE_Action * this, int param_1, RGE
//                               LAB_0040748b                                                 XREF[1]:     00407478(j)
//                              action.cpp:42 (6)
//         0040748b     MOV        EAX,ESI
//         0040748d     POP        ESI
//         0040748e     RET        0xc
//         00407491     ??         90h
//         00407492     NOP
//         00407493     NOP
//         00407494     NOP
//         00407495     NOP
//         00407496     NOP
//         00407497     NOP
//         00407498     NOP
//         00407499     NOP
//         0040749a     NOP
//         0040749b     NOP
//         0040749c     NOP
//         0040749d     NOP
//         0040749e     NOP
//         0040749f     NOP
}

RGE_Action::RGE_Action(RGE_Action_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action(RGE_Action * this, RGE_Action_Object
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004074da(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004074cc(R)
//                               ??0RGE_Action@@QAE@PAVRGE_Action_Object@@H@Z                 XREF[32]:    RGE_Action_Attack:00401197(c),
//                               RGE_Action::RGE_Action                                                    RGE_Action_Attack:004012bb(c),
//                                                                                                         RGE_Action_Enter:00402439(c),
//                                                                                                         RGE_Action_Gather:00402f65(c),
//                                                                                                         RGE_Action_Make:00404a1a(c),
//                                                                                                         RGE_Action_Missile:00404cb4(c),
//                                                                                                         RGE_Action_Move_To:004055aa(c),
//                                                                                                         RGE_Action_Move_To:00405645(c),
//                                                                                                         RGE_Action_Transport:00406dca(c),
//                                                                                                         TRIBE_Action_Artifact:004ccc0a(c),
//                                                                                                         TRIBE_Action_Artifact:004ccc3a(c),
//                                                                                                         TRIBE_Action_Build:004cd236(c),
//                                                                                                         TRIBE_Action_Convert:004cdab5(c),
//                                                                                                         TRIBE_Action_Discovery_Artifact:00
//                                                                                                         TRIBE_Action_Discovery_Artifact:00
//                                                                                                         TRIBE_Action_Heal:004ce9b5(c),
//                                                                                                         TRIBE_Action_Hunt:004cf155(c),
//                                                                                                         TRIBE_Action_Make_Obj:004d0eba(c),
//                                                                                                         TRIBE_Action_Repair:004d1745(c),
//                                                                                                         TRIBE_Action_Repair:004d17ba(c),
//                                                                                                         [more]
//                              action.cpp:49 (12)
//         004074c0     PUSH       ESI
//         004074c1     MOV        ESI,this
//         004074c3     OR         EAX,0xffffffff
//         004074c6     MOV        dword ptr [ESI + 0x18],EAX
//         004074c9     MOV        dword ptr [ESI + 0x1c],EAX
//                              action.cpp:53 (14)
//         004074cc     MOV        EAX,dword ptr [ESP + param_2]
//         004074d0     MOV        dword ptr [ESI],RGE_Action::`vftable'            = 004074a0
//         004074d6     TEST       EAX,EAX
//         004074d8     JZ         LAB_004074e4
//                              action.cpp:54 (10)
//         004074da     MOV        EAX,dword ptr [ESP + param_1]
//         004074de     PUSH       EAX
//         004074df     CALL       RGE_Action::setup                                int setup(RGE_Action * this, RGE_Action_Objec
//                               LAB_004074e4                                                 XREF[1]:     004074d8(j)
//                              action.cpp:55 (6)
//         004074e4     MOV        EAX,ESI
//         004074e6     POP        ESI
//         004074e7     RET        0x8
//         004074ea     ??         90h
//         004074eb     NOP
//         004074ec     NOP
//         004074ed     NOP
//         004074ee     NOP
//         004074ef     NOP
}

RGE_Action::~RGE_Action() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Action(RGE_Action * this)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ??1RGE_Action@@UAE@XZ                                        XREF[28]:    ~RGE_Action:0040202e(T),
//                               RGE_Action::~RGE_Action                                                   ~RGE_Action_Bird:00402030(j),
//                                                                                                         ~RGE_Action_Enter:004025f6(c),
//                                                                                                         ~RGE_Action:00402b8e(T),
//                                                                                                         ~RGE_Action_Explore:00402b90(j),
//                                                                                                         ~RGE_Action:00402f2e(T),
//                                                                                                         ~RGE_Action_Gather:00402f30(j),
//                                                                                                         ~RGE_Action:004049fe(T),
//                                                                                                         ~RGE_Action_Make:00404a00(j),
//                                                                                                         ~RGE_Action:00404c7e(T),
//                                                                                                         ~RGE_Action_Missile:00404c80(j),
//                                                                                                         ~RGE_Action_Move_To:0040572d(c),
//                                                                                                         ~RGE_Action:00406dae(T),
//                                                                                                         ~RGE_Action_Transport:00406db0(j),
//                                                                                                         `vector_deleting_destructor':00407
//                                                                                                         ~RGE_Action:004ccbee(T),
//                                                                                                         ~TRIBE_Action_Artifact:004ccbf0(j)
//                                                                                                         ~RGE_Action:004cd1fe(T),
//                                                                                                         ~TRIBE_Action_Build:004cd200(j),
//                                                                                                         ~RGE_Action:004cda7e(T), [more]
//                              action.cpp:60 (4)
//         004074f0     PUSH       ESI
//         004074f1     MOV        ESI,this
//         004074f3     PUSH       EDI
//                              action.cpp:61 (13)
//         004074f4     PUSH       0x0
//         004074f6     MOV        dword ptr [ESI],RGE_Action::`vftable'            = 004074a0
//         004074fc     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              action.cpp:62 (9)
//         00407501     PUSH       0x0
//         00407503     MOV        this,ESI
//         00407505     CALL       RGE_Action::set_target_obj2                      void set_target_obj2(RGE_Action * this, RGE_S
//                              action.cpp:63 (7)
//         0040750a     MOV        EDI,dword ptr [ESI + 0x34]
//         0040750d     TEST       EDI,EDI
//         0040750f     JZ         LAB_00407528
//                              action.cpp:65 (16)
//         00407511     MOV        this,EDI
//         00407513     CALL       RGE_Action_List::~RGE_Action_List                void ~RGE_Action_List(RGE_Action_List * this)
//         00407518     PUSH       EDI
//         00407519     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0040751e     ADD        ESP,0x4
//                              action.cpp:66 (7)
//         00407521     MOV        dword ptr [ESI + 0x34],0x0
//                               LAB_00407528                                                 XREF[1]:     0040750f(j)
//                              action.cpp:68 (3)
//         00407528     POP        EDI
//         00407529     POP        ESI
//         0040752a     RET
//         0040752b     ??         90h
//         0040752c     NOP
//         0040752d     NOP
//         0040752e     NOP
//         0040752f     NOP
}

int RGE_Action::setup(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Action * this, RGE_Action_Object * param_1)
//              int               EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00407680(R)
//                               ?setup@RGE_Action@@UAEHPAVRGE_Action_Object@@@Z              XREF[23]:    RGE_Action:004074df(c),
//                               RGE_Action::setup                                                         setup:004d3a05(c), 0056e05c(*),
//                                                                                                         0056e0dc(*), 0056e144(*),
//                                                                                                         0056e1b4(*), 0056e21c(*),
//                                                                                                         0056e2bc(*), 0056e324(*),
//                                                                                                         0056e3a4(*), 0056e654(*),
//                                                                                                         0056e6d4(*), 00574eac(*),
//                                                                                                         00574f1c(*), 00574f94(*),
//                                                                                                         00575014(*), 00575084(*),
//                                                                                                         005750f4(*), 005751ac(*),
//                                                                                                         0057520c(*), [more]
//                              action.cpp:126 (10)
//         00407680     MOV        EAX,dword ptr [ESP + param_1]
//         00407684     PUSH       EBX
//         00407685     PUSH       ESI
//         00407686     MOV        ESI,this
//         00407688     XOR        EBX,EBX
//                              action.cpp:138 (40)
//         0040768a     PUSH       EAX
//         0040768b     MOV        EDX,dword ptr [ESI]
//         0040768d     MOV        word ptr [ESI + 0x4],BX
//         00407691     MOV        dword ptr [ESI + 0x8],EAX
//         00407694     MOV        byte ptr [ESI + 0xc],BL
//         00407697     MOV        dword ptr [ESI + 0x10],EBX
//         0040769a     MOV        dword ptr [ESI + 0x14],EBX
//         0040769d     MOV        dword ptr [ESI + 0x20],EBX
//         004076a0     MOV        dword ptr [ESI + 0x24],EBX
//         004076a3     MOV        dword ptr [ESI + 0x28],EBX
//         004076a6     MOV        dword ptr [ESI + 0x2c],EBX
//         004076a9     MOV        dword ptr [ESI + 0x30],EBX
//         004076ac     CALL       dword ptr [EDX + 0xc]
//         004076af     MOV        dword ptr [ESI + 0x34],EAX
//                              action.cpp:139 (3)
//         004076b2     MOV        dword ptr [ESI + 0x38],EBX
//                              action.cpp:140 (3)
//         004076b5     MOV        byte ptr [ESI + 0x3c],BL
//                              action.cpp:143 (10)
//         004076b8     POP        ESI
//         004076b9     MOV        EAX,0x1
//         004076be     POP        EBX
//         004076bf     RET        0x4
//         004076c2     ??         90h
//         004076c3     NOP
//         004076c4     NOP
//         004076c5     NOP
//         004076c6     NOP
//         004076c7     NOP
//         004076c8     NOP
//         004076c9     NOP
//         004076ca     NOP
//         004076cb     NOP
//         004076cc     NOP
//         004076cd     NOP
//         004076ce     NOP
//         004076cf     NOP
    return 0;
}

int RGE_Action::setup(RGE_Action_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Action * this, RGE_Action_Object * param_1)
//              int               EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00407680(R)
//                               ?setup@RGE_Action@@UAEHPAVRGE_Action_Object@@@Z              XREF[23]:    RGE_Action:004074df(c),
//                               RGE_Action::setup                                                         setup:004d3a05(c), 0056e05c(*),
//                                                                                                         0056e0dc(*), 0056e144(*),
//                                                                                                         0056e1b4(*), 0056e21c(*),
//                                                                                                         0056e2bc(*), 0056e324(*),
//                                                                                                         0056e3a4(*), 0056e654(*),
//                                                                                                         0056e6d4(*), 00574eac(*),
//                                                                                                         00574f1c(*), 00574f94(*),
//                                                                                                         00575014(*), 00575084(*),
//                                                                                                         005750f4(*), 005751ac(*),
//                                                                                                         0057520c(*), [more]
//                              action.cpp:126 (10)
//         00407680     MOV        EAX,dword ptr [ESP + param_1]
//         00407684     PUSH       EBX
//         00407685     PUSH       ESI
//         00407686     MOV        ESI,this
//         00407688     XOR        EBX,EBX
//                              action.cpp:138 (40)
//         0040768a     PUSH       EAX
//         0040768b     MOV        EDX,dword ptr [ESI]
//         0040768d     MOV        word ptr [ESI + 0x4],BX
//         00407691     MOV        dword ptr [ESI + 0x8],EAX
//         00407694     MOV        byte ptr [ESI + 0xc],BL
//         00407697     MOV        dword ptr [ESI + 0x10],EBX
//         0040769a     MOV        dword ptr [ESI + 0x14],EBX
//         0040769d     MOV        dword ptr [ESI + 0x20],EBX
//         004076a0     MOV        dword ptr [ESI + 0x24],EBX
//         004076a3     MOV        dword ptr [ESI + 0x28],EBX
//         004076a6     MOV        dword ptr [ESI + 0x2c],EBX
//         004076a9     MOV        dword ptr [ESI + 0x30],EBX
//         004076ac     CALL       dword ptr [EDX + 0xc]
//         004076af     MOV        dword ptr [ESI + 0x34],EAX
//                              action.cpp:139 (3)
//         004076b2     MOV        dword ptr [ESI + 0x38],EBX
//                              action.cpp:140 (3)
//         004076b5     MOV        byte ptr [ESI + 0x3c],BL
//                              action.cpp:143 (10)
//         004076b8     POP        ESI
//         004076b9     MOV        EAX,0x1
//         004076be     POP        EBX
//         004076bf     RET        0x4
//         004076c2     ??         90h
//         004076c3     NOP
//         004076c4     NOP
//         004076c5     NOP
//         004076c6     NOP
//         004076c7     NOP
//         004076c8     NOP
//         004076c9     NOP
//         004076ca     NOP
//         004076cb     NOP
//         004076cc     NOP
//         004076cd     NOP
//         004076ce     NOP
//         004076cf     NOP
    return 0;
}

RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object* param_1) {
    /* TODO: Stub */
//                              RGE_Action_List * __thiscall create_action_list(RGE_Action * this, R
//              RGE_Action_Lis    EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004076f9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0040770e(R), 00407720(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004076f3(W)
//                               ?create_action_list@RGE_Action@@UAEPAVRGE_Action_List@@PAVR  XREF[21]:    0056e064(*), 0056e0e4(*),
//                               RGE_Action::create_action_list                                            0056e14c(*), 0056e1bc(*),
//                                                                                                         0056e224(*), 0056e2c4(*),
//                                                                                                         0056e32c(*), 0056e3ac(*),
//                                                                                                         0056e65c(*), 0056e6dc(*),
//                                                                                                         00574eb4(*), 00574f24(*),
//                                                                                                         00574f9c(*), 0057501c(*),
//                                                                                                         0057508c(*), 005750fc(*),
//                                                                                                         005751b4(*), 00575214(*),
//                                                                                                         0057528c(*), 005752f4(*), [more]
//                              action.cpp:147 (25)
//         004076d0     PUSH       -0x1
//         004076d2     PUSH       FUN_0055c42b
//         004076d7     MOV        EAX,FS:[0x0]
//         004076dd     PUSH       EAX
//         004076de     MOV        dword ptr FS:[0x0],ESP
//         004076e5     PUSH       this
//         004076e6     PUSH       ESI
//         004076e7     MOV        ESI,this
//                              action.cpp:148 (37)
//         004076e9     PUSH       0xc
//         004076eb     CALL       operator_new                                     void * operator_new(uint param_1)
//         004076f0     ADD        ESP,0x4
//         004076f3     MOV        dword ptr [ESP + local_10],EAX
//         004076f7     TEST       EAX,EAX
//         004076f9     MOV        dword ptr [ESP + local_4],0x0
//         00407701     JZ         LAB_00407720
//         00407703     MOV        this,dword ptr [ESI + 0x8]
//         00407706     PUSH       this
//         00407707     MOV        this,EAX
//         00407709     CALL       RGE_Action_List::RGE_Action_List                 undefined RGE_Action_List(RGE_Action_List * t
//                              action.cpp:149 (38)
//         0040770e     MOV        this,dword ptr [ESP + local_c]
//         00407712     MOV        dword ptr FS:[0x0],this
//         00407719     POP        ESI
//         0040771a     ADD        ESP,0x10
//         0040771d     RET        0x4
//                               LAB_00407720                                                 XREF[1]:     00407701(j)
//         00407720     MOV        this,dword ptr [ESP + local_c]
//         00407724     XOR        EAX,EAX
//         00407726     MOV        dword ptr FS:[0x0],this
//         0040772d     POP        ESI
//         0040772e     ADD        ESP,0x10
//         00407731     RET        0x4
//         00407734     ??         90h
//         00407735     NOP
//         00407736     NOP
//         00407737     NOP
//         00407738     NOP
//         00407739     NOP
//         0040773a     NOP
//         0040773b     NOP
//         0040773c     NOP
//         0040773d     NOP
//         0040773e     NOP
//         0040773f     NOP
    return 0;
}

void RGE_Action::rehook() {
    /* TODO: Stub */
//                              void __thiscall rehook(RGE_Action * this)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?rehook@RGE_Action@@UAEXXZ                                   XREF[22]:    0056e068(*), 0056e0e8(*),
//                               RGE_Action::rehook                                                        0056e150(*), 0056e1c0(*),
//                                                                                                         0056e228(*), 0056e2c8(*),
//                                                                                                         0056e330(*), 0056e3b0(*),
//                                                                                                         0056e660(*), 0056e6e0(*),
//                                                                                                         00574eb8(*), 00574f28(*),
//                                                                                                         00574fa0(*), 00575020(*),
//                                                                                                         00575090(*), 00575100(*),
//                                                                                                         005751b8(*), 00575218(*),
//                                                                                                         00575290(*), 005752f8(*), [more]
//                              action.cpp:153 (3)
//         00407740     PUSH       ESI
//         00407741     MOV        ESI,this
//                              action.cpp:154 (7)
//         00407743     MOV        EAX,dword ptr [ESI + 0x10]
//         00407746     TEST       EAX,EAX
//         00407748     JZ         LAB_00407760
//                              action.cpp:156 (9)
//         0040774a     MOV        this,dword ptr [ESI + 0x8]
//         0040774d     PUSH       EAX
//         0040774e     CALL       RGE_Static_Object::get_object_pointer            RGE_Static_Object * get_object_pointer(RGE_St
//                              action.cpp:157 (7)
//         00407753     TEST       EAX,EAX
//         00407755     MOV        dword ptr [ESI + 0x10],EAX
//         00407758     JZ         LAB_00407760
//                              action.cpp:158 (6)
//         0040775a     MOV        EAX,dword ptr [EAX + 0x4]
//         0040775d     MOV        dword ptr [ESI + 0x18],EAX
//                               LAB_00407760                                                 XREF[2]:     00407748(j), 00407758(j)
//                              action.cpp:160 (7)
//         00407760     MOV        EAX,dword ptr [ESI + 0x14]
//         00407763     TEST       EAX,EAX
//         00407765     JZ         LAB_0040777d
//                              action.cpp:162 (9)
//         00407767     MOV        this,dword ptr [ESI + 0x8]
//         0040776a     PUSH       EAX
//         0040776b     CALL       RGE_Static_Object::get_object_pointer            RGE_Static_Object * get_object_pointer(RGE_St
//                              action.cpp:163 (7)
//         00407770     TEST       EAX,EAX
//         00407772     MOV        dword ptr [ESI + 0x14],EAX
//         00407775     JZ         LAB_0040777d
//                              action.cpp:164 (6)
//         00407777     MOV        this,dword ptr [EAX + 0x4]
//         0040777a     MOV        dword ptr [ESI + 0x1c],this
//                               LAB_0040777d                                                 XREF[2]:     00407765(j), 00407775(j)
//                              action.cpp:166 (7)
//         0040777d     MOV        this,dword ptr [ESI + 0x34]
//         00407780     TEST       this,this
//         00407782     JZ         LAB_00407789
//                              action.cpp:167 (5)
//         00407784     CALL       RGE_Action_List::rehook                          void rehook(RGE_Action_List * this)
//                               LAB_00407789                                                 XREF[1]:     00407782(j)
//                              action.cpp:168 (2)
//         00407789     POP        ESI
//         0040778a     RET
//         0040778b     ??         90h
//         0040778c     NOP
//         0040778d     NOP
//         0040778e     NOP
//         0040778f     NOP
    return;
}

void RGE_Action::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Action * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[7]:     00407796(R), 004077c2(W), 004077cb(W), 004077cf(*),
//                                                                                     004077e6(W), 004077ef(W), 004077f3(*)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     00407864(W), 0040786e(W), 00407872(*), 004078a1(W),
//                                                                                     004078ab(W), 004078af(*)
//              short             Stack[-0x8]:2  short_val
//                               ?save@RGE_Action@@UAEXH@Z                                    XREF[22]:    save:004013b9(c),
//                               RGE_Action::save                                                          save:00403029(c),
//                                                                                                         save:004054b9(c),
//                                                                                                         save:00405759(c),
//                                                                                                         save:004cdb79(c),
//                                                                                                         save:004ce6d9(c),
//                                                                                                         save:004cf219(c),
//                                                                                                         save:004d0f79(c),
//                                                                                                         save:004d1859(c),
//                                                                                                         save:004d2379(c),
//                                                                                                         save:004d27f9(c), 0056e0ec(*),
//                                                                                                         0056e154(*), 0056e1c4(*),
//                                                                                                         0056e2cc(*), 0056e664(*),
//                                                                                                         0056e6e4(*), 00574ebc(*),
//                                                                                                         00574f2c(*), 00575094(*), [more]
//                              action.cpp:172 (6)
//         00407790     PUSH       this
//         00407791     PUSH       EBX
//         00407792     PUSH       ESI
//         00407793     MOV        ESI,this
//         00407795     PUSH       EDI
//                              action.cpp:176 (19)
//         00407796     MOV        EDI,dword ptr [ESP + param_1]
//         0040779a     PUSH       0x2
//         0040779c     LEA        EAX,[ESI + 0x4]
//         0040779f     PUSH       EAX
//         004077a0     PUSH       EDI
//         004077a1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004077a6     ADD        ESP,0xc
//                              action.cpp:177 (12)
//         004077a9     LEA        this,[ESI + 0xc]
//         004077ac     PUSH       0x1
//         004077ae     PUSH       this
//         004077af     PUSH       EDI
//         004077b0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              action.cpp:179 (13)
//         004077b5     MOV        EAX,dword ptr [ESI + 0x10]
//         004077b8     ADD        ESP,0xc
//         004077bb     OR         EBX,0xffffffff
//         004077be     TEST       EAX,EAX
//         004077c0     JNZ        LAB_004077c8
//                              action.cpp:180 (4)
//         004077c2     MOV        dword ptr [ESP + param_1],EBX
//                              action.cpp:181 (2)
//         004077c6     JMP        LAB_004077cf
//                               LAB_004077c8                                                 XREF[1]:     004077c0(j)
//                              action.cpp:182 (7)
//         004077c8     MOV        EDX,dword ptr [EAX + 0x4]
//         004077cb     MOV        dword ptr [ESP + param_1],EDX
//                               LAB_004077cf                                                 XREF[1]:     004077c6(j)
//                              action.cpp:183 (13)
//         004077cf     LEA        EAX=>param_1,[ESP + 0x14]
//         004077d3     PUSH       0x4
//         004077d5     PUSH       EAX
//         004077d6     PUSH       EDI
//         004077d7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              action.cpp:185 (10)
//         004077dc     MOV        EAX,dword ptr [ESI + 0x14]
//         004077df     ADD        ESP,0xc
//         004077e2     TEST       EAX,EAX
//         004077e4     JNZ        LAB_004077ec
//                              action.cpp:186 (4)
//         004077e6     MOV        dword ptr [ESP + param_1],EBX
//                              action.cpp:187 (2)
//         004077ea     JMP        LAB_004077f3
//                               LAB_004077ec                                                 XREF[1]:     004077e4(j)
//                              action.cpp:188 (7)
//         004077ec     MOV        this,dword ptr [EAX + 0x4]
//         004077ef     MOV        dword ptr [ESP + param_1],this
//                               LAB_004077f3                                                 XREF[1]:     004077ea(j)
//                              action.cpp:189 (16)
//         004077f3     LEA        EDX=>param_1,[ESP + 0x14]
//         004077f7     PUSH       0x4
//         004077f9     PUSH       EDX
//         004077fa     PUSH       EDI
//         004077fb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00407800     ADD        ESP,0xc
//                              action.cpp:191 (15)
//         00407803     LEA        EAX,[ESI + 0x18]
//         00407806     PUSH       0x4
//         00407808     PUSH       EAX
//         00407809     PUSH       EDI
//         0040780a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040780f     ADD        ESP,0xc
//                              action.cpp:192 (15)
//         00407812     LEA        this,[ESI + 0x1c]
//         00407815     PUSH       0x4
//         00407817     PUSH       this
//         00407818     PUSH       EDI
//         00407819     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040781e     ADD        ESP,0xc
//                              action.cpp:193 (15)
//         00407821     LEA        EDX,[ESI + 0x20]
//         00407824     PUSH       0x4
//         00407826     PUSH       EDX
//         00407827     PUSH       EDI
//         00407828     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040782d     ADD        ESP,0xc
//                              action.cpp:194 (15)
//         00407830     LEA        EAX,[ESI + 0x24]
//         00407833     PUSH       0x4
//         00407835     PUSH       EAX
//         00407836     PUSH       EDI
//         00407837     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040783c     ADD        ESP,0xc
//                              action.cpp:195 (15)
//         0040783f     LEA        this,[ESI + 0x28]
//         00407842     PUSH       0x4
//         00407844     PUSH       this
//         00407845     PUSH       EDI
//         00407846     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040784b     ADD        ESP,0xc
//                              action.cpp:196 (12)
//         0040784e     LEA        EDX,[ESI + 0x2c]
//         00407851     PUSH       0x4
//         00407853     PUSH       EDX
//         00407854     PUSH       EDI
//         00407855     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              action.cpp:198 (10)
//         0040785a     MOV        EAX,dword ptr [ESI + 0x30]
//         0040785d     ADD        ESP,0xc
//         00407860     TEST       EAX,EAX
//         00407862     JNZ        LAB_0040786a
//                              action.cpp:199 (4)
//         00407864     MOV        dword ptr [ESP + local_4],EBX
//                              action.cpp:200 (2)
//         00407868     JMP        LAB_00407872
//                               LAB_0040786a                                                 XREF[1]:     00407862(j)
//                              action.cpp:201 (8)
//         0040786a     MOV        AX,word ptr [EAX + 0x2]
//         0040786e     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_00407872                                                 XREF[1]:     00407868(j)
//                              action.cpp:202 (16)
//         00407872     LEA        this=>local_4,[ESP + 0xc]
//         00407876     PUSH       0x2
//         00407878     PUSH       this
//         00407879     PUSH       EDI
//         0040787a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040787f     ADD        ESP,0xc
//                              action.cpp:204 (12)
//         00407882     LEA        EDX,[ESI + 0x3c]
//         00407885     PUSH       0x1
//         00407887     PUSH       EDX
//         00407888     PUSH       EDI
//         00407889     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              action.cpp:206 (12)
//         0040788e     MOV        this,dword ptr [ESI + 0x34]
//         00407891     ADD        ESP,0xc
//         00407894     PUSH       EDI
//         00407895     CALL       RGE_Action_List::save                            void save(RGE_Action_List * this, int param_1)
//                              action.cpp:208 (7)
//         0040789a     MOV        ESI,dword ptr [ESI + 0x38]
//         0040789d     TEST       ESI,ESI
//         0040789f     JNZ        LAB_004078a7
//                              action.cpp:209 (4)
//         004078a1     MOV        dword ptr [ESP + local_4],EBX
//                              action.cpp:210 (2)
//         004078a5     JMP        LAB_004078af
//                               LAB_004078a7                                                 XREF[1]:     0040789f(j)
//                              action.cpp:211 (8)
//         004078a7     MOV        AX,word ptr [ESI + 0x72]
//         004078ab     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_004078af                                                 XREF[1]:     004078a5(j)
//                              action.cpp:212 (16)
//         004078af     LEA        this=>local_4,[ESP + 0xc]
//         004078b3     PUSH       0x2
//         004078b5     PUSH       this
//         004078b6     PUSH       EDI
//         004078b7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004078bc     ADD        ESP,0xc
//                              action.cpp:213 (7)
//         004078bf     POP        EDI
//         004078c0     POP        ESI
//         004078c1     POP        EBX
//         004078c2     POP        this
//         004078c3     RET        0x4
//         004078c6     ??         90h
//         004078c7     NOP
//         004078c8     NOP
//         004078c9     NOP
//         004078ca     NOP
//         004078cb     NOP
//         004078cc     NOP
//         004078cd     NOP
//         004078ce     NOP
//         004078cf     NOP
    return;
}

short RGE_Action::type() {
    /* TODO: Stub */
//                              short __thiscall type(RGE_Action * this)
//              short             AX:2           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?type@RGE_Action@@UAEFXZ                                     XREF[22]:    0056e070(*), 0056e0f0(*),
//                               RGE_Action::type                                                          0056e158(*), 0056e1c8(*),
//                                                                                                         0056e230(*), 0056e2d0(*),
//                                                                                                         0056e338(*), 0056e3b8(*),
//                                                                                                         0056e668(*), 0056e6e8(*),
//                                                                                                         00574ec0(*), 00574f30(*),
//                                                                                                         00574fa8(*), 00575028(*),
//                                                                                                         00575098(*), 00575108(*),
//                                                                                                         005751c0(*), 00575220(*),
//                                                                                                         00575298(*), 00575300(*), [more]
//                              action.cpp:217 (4)
//         004078d0     MOV        AX,word ptr [ECX + this->action_type]
//                              action.cpp:219 (1)
//         004078d4     RET
//         004078d5     ??         90h
//         004078d6     NOP
//         004078d7     NOP
//         004078d8     NOP
//         004078d9     NOP
//         004078da     NOP
//         004078db     NOP
//         004078dc     NOP
//         004078dd     NOP
//         004078de     NOP
//         004078df     NOP
    return 0;
}

void RGE_Action::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(RGE_Action * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?first_in_stack@RGE_Action@@UAEXE@Z                          XREF[2]:     0056e6ec(*), 005753fc(*)
//                               RGE_Action::first_in_stack
//                              action.cpp:226 (3)
//         004078e0     RET        0x4
//         004078e3     ??         90h
//         004078e4     NOP
//         004078e5     NOP
//         004078e6     NOP
//         004078e7     NOP
//         004078e8     NOP
//         004078e9     NOP
//         004078ea     NOP
//         004078eb     NOP
//         004078ec     NOP
//         004078ed     NOP
//         004078ee     NOP
//         004078ef     NOP
    return;
}

int RGE_Action::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(RGE_Action * this)
//              int               EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?stop@RGE_Action@@UAEHXZ                                     XREF[12]:    0056e104(*), 0056e16c(*),
//                               RGE_Action::stop                                                          0056e1dc(*), 0056e2e4(*),
//                                                                                                         0056e34c(*), 0056e3cc(*),
//                                                                                                         0056e6fc(*), 00574fbc(*),
//                                                                                                         0057503c(*), 005750ac(*),
//                                                                                                         005753a4(*), 0057540c(*)
//                              action.cpp:233 (2)
//         004078f0     XOR        EAX,EAX
//                              action.cpp:235 (1)
//         004078f2     RET
//         004078f3     ??         90h
//         004078f4     NOP
//         004078f5     NOP
//         004078f6     NOP
//         004078f7     NOP
//         004078f8     NOP
//         004078f9     NOP
//         004078fa     NOP
//         004078fb     NOP
//         004078fc     NOP
//         004078fd     NOP
//         004078fe     NOP
//         004078ff     NOP
    return 0;
}

int RGE_Action::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(RGE_Action * this, RGE_Static_Object * param_
//              int               EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?move_to@RGE_Action@@UAEHPAVRGE_Static_Object@@MMM@Z         XREF[15]:    0056e088(*), 0056e108(*),
//                               RGE_Action::move_to                                                       0056e170(*), 0056e1e0(*),
//                                                                                                         0056e2e8(*), 0056e350(*),
//                                                                                                         0056e3d0(*), 0056e700(*),
//                                                                                                         00574fc0(*), 00575040(*),
//                                                                                                         005750b0(*), 005751d8(*),
//                                                                                                         005752b0(*), 005753a8(*),
//                                                                                                         00575410(*)
//                              action.cpp:241 (2)
//         00407900     XOR        EAX,EAX
//                              action.cpp:243 (3)
//         00407902     RET        0x10
//         00407905     ??         90h
//         00407906     NOP
//         00407907     NOP
//         00407908     NOP
//         00407909     NOP
//         0040790a     NOP
//         0040790b     NOP
//         0040790c     NOP
//         0040790d     NOP
//         0040790e     NOP
//         0040790f     NOP
    return 0;
}

int RGE_Action::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(RGE_Action * this, RGE_Static_Object * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?work@RGE_Action@@UAEHPAVRGE_Static_Object@@MMM@Z            XREF[11]:    0056e10c(*), 0056e174(*),
//                               RGE_Action::work                                                          0056e2ec(*), 0056e354(*),
//                                                                                                         0056e3d4(*), 0056e704(*),
//                                                                                                         00575044(*), 005751dc(*),
//                                                                                                         005752b4(*), 005753ac(*),
//                                                                                                         00575414(*)
//                              action.cpp:249 (2)
//         00407910     XOR        EAX,EAX
//                              action.cpp:251 (3)
//         00407912     RET        0x10
//         00407915     ??         90h
//         00407916     NOP
//         00407917     NOP
//         00407918     NOP
//         00407919     NOP
//         0040791a     NOP
//         0040791b     NOP
//         0040791c     NOP
//         0040791d     NOP
//         0040791e     NOP
//         0040791f     NOP
    return 0;
}

uchar RGE_Action::attack_response(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall attack_response(RGE_Action * this, RGE_Static_Objec
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?attack_response@RGE_Action@@UAEEPAVRGE_Static_Object@@@Z    XREF[22]:    0056e090(*), 0056e110(*),
//                               RGE_Action::attack_response                                               0056e178(*), 0056e1e8(*),
//                                                                                                         0056e250(*), 0056e2f0(*),
//                                                                                                         0056e358(*), 0056e3d8(*),
//                                                                                                         0056e688(*), 0056e708(*),
//                                                                                                         00574ee0(*), 00574f50(*),
//                                                                                                         00574fc8(*), 00575048(*),
//                                                                                                         005750b8(*), 00575128(*),
//                                                                                                         005751e0(*), 00575240(*),
//                                                                                                         005752b8(*), 00575320(*), [more]
//                              action.cpp:257 (2)
//         00407920     XOR        AL,AL
//                              action.cpp:259 (3)
//         00407922     RET        0x4
//         00407925     ??         90h
//         00407926     NOP
//         00407927     NOP
//         00407928     NOP
//         00407929     NOP
//         0040792a     NOP
//         0040792b     NOP
//         0040792c     NOP
//         0040792d     NOP
//         0040792e     NOP
//         0040792f     NOP
    return 0;
}

uchar RGE_Action::relation_response(long param_1, uchar param_2) {
    /* TODO: Stub */
//                              uchar __thiscall relation_response(RGE_Action * this, long param_1,
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              uchar             Stack[0x8]:1   param_2
//                               ?relation_response@RGE_Action@@UAEEJE@Z                      XREF[22]:    0056e094(*), 0056e114(*),
//                               RGE_Action::relation_response                                             0056e17c(*), 0056e1ec(*),
//                                                                                                         0056e254(*), 0056e2f4(*),
//                                                                                                         0056e35c(*), 0056e3dc(*),
//                                                                                                         0056e68c(*), 0056e70c(*),
//                                                                                                         00574ee4(*), 00574f54(*),
//                                                                                                         00574fcc(*), 0057504c(*),
//                                                                                                         005750bc(*), 0057512c(*),
//                                                                                                         005751e4(*), 00575244(*),
//                                                                                                         005752bc(*), 00575324(*), [more]
//                              action.cpp:265 (2)
//         00407930     XOR        AL,AL
//                              action.cpp:267 (3)
//         00407932     RET        0x8
//         00407935     ??         90h
//         00407936     NOP
//         00407937     NOP
//         00407938     NOP
//         00407939     NOP
//         0040793a     NOP
//         0040793b     NOP
//         0040793c     NOP
//         0040793d     NOP
//         0040793e     NOP
//         0040793f     NOP
    return 0;
}

void RGE_Action::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(RGE_Action * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00407940(R)
//                               ?set_state@RGE_Action@@MAEXE@Z                               XREF[2]:     0056e72c(*), 0057543c(*)
//                               RGE_Action::set_state
//                              action.cpp:271 (7)
//         00407940     MOV        AL,byte ptr [ESP + param_1]
//         00407944     MOV        byte ptr [ECX + this->state],AL
//                              action.cpp:273 (3)
//         00407947     RET        0x4
//         0040794a     ??         90h
//         0040794b     NOP
//         0040794c     NOP
//         0040794d     NOP
//         0040794e     NOP
//         0040794f     NOP
    return;
}

uchar RGE_Action::inside_obj_update() {
    /* TODO: Stub */
//                              uchar __thiscall inside_obj_update(RGE_Action * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?inside_obj_update@RGE_Action@@UAEEXZ                        XREF[22]:    0056e078(*), 0056e0f8(*),
//                               RGE_Action::inside_obj_update                                             0056e160(*), 0056e1d0(*),
//                                                                                                         0056e238(*), 0056e2d8(*),
//                                                                                                         0056e340(*), 0056e3c0(*),
//                                                                                                         0056e670(*), 0056e6f0(*),
//                                                                                                         00574ec8(*), 00574f38(*),
//                                                                                                         00574fb0(*), 00575030(*),
//                                                                                                         005750a0(*), 00575110(*),
//                                                                                                         005751c8(*), 00575228(*),
//                                                                                                         005752a0(*), 00575308(*), [more]
//                              action.cpp:283 (3)
//         00407950     PUSH       ESI
//         00407951     MOV        ESI,this
//                              action.cpp:284 (13)
//         00407953     MOV        EAX,dword ptr [ESI + 0x10]
//         00407956     TEST       EAX,EAX
//         00407958     JZ         LAB_00407969
//         0040795a     CMP        byte ptr [EAX + 0x48],0x7
//         0040795e     JC         LAB_00407969
//                              action.cpp:285 (9)
//         00407960     MOV        EAX,dword ptr [ESI]
//         00407962     PUSH       0x0
//         00407964     MOV        this,ESI
//         00407966     CALL       dword ptr [EAX + 0x54]
//                               LAB_00407969                                                 XREF[2]:     00407958(j), 0040795e(j)
//                              action.cpp:287 (13)
//         00407969     MOV        EAX,dword ptr [ESI + 0x14]
//         0040796c     TEST       EAX,EAX
//         0040796e     JZ         LAB_0040797f
//         00407970     CMP        byte ptr [EAX + 0x48],0x7
//         00407974     JC         LAB_0040797f
//                              action.cpp:288 (9)
//         00407976     MOV        EDX,dword ptr [ESI]
//         00407978     PUSH       0x0
//         0040797a     MOV        this,ESI
//         0040797c     CALL       dword ptr [EDX + 0x58]
//                               LAB_0040797f                                                 XREF[2]:     0040796e(j), 00407974(j)
//                              action.cpp:290 (2)
//         0040797f     MOV        AL,0x1
//                              action.cpp:291 (2)
//         00407981     POP        ESI
//         00407982     RET
//         00407983     ??         90h
//         00407984     NOP
//         00407985     NOP
//         00407986     NOP
//         00407987     NOP
//         00407988     NOP
//         00407989     NOP
//         0040798a     NOP
//         0040798b     NOP
//         0040798c     NOP
//         0040798d     NOP
//         0040798e     NOP
//         0040798f     NOP
    return 0;
}

uchar RGE_Action::idle_update() {
    /* TODO: Stub */
//                              uchar __thiscall idle_update(RGE_Action * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?idle_update@RGE_Action@@UAEEXZ                              XREF[22]:    0056e07c(*), 0056e0fc(*),
//                               RGE_Action::idle_update                                                   0056e164(*), 0056e1d4(*),
//                                                                                                         0056e23c(*), 0056e2dc(*),
//                                                                                                         0056e344(*), 0056e3c4(*),
//                                                                                                         0056e674(*), 0056e6f4(*),
//                                                                                                         00574ecc(*), 00574f3c(*),
//                                                                                                         00574fb4(*), 00575034(*),
//                                                                                                         005750a4(*), 00575114(*),
//                                                                                                         005751cc(*), 0057522c(*),
//                                                                                                         005752a4(*), 0057530c(*), [more]
//                              action.cpp:301 (3)
//         00407990     PUSH       ESI
//         00407991     MOV        ESI,this
//                              action.cpp:305 (13)
//         00407993     MOV        EAX,dword ptr [ESI + 0x10]
//         00407996     TEST       EAX,EAX
//         00407998     JZ         LAB_004079a9
//         0040799a     CMP        byte ptr [EAX + 0x48],0x7
//         0040799e     JC         LAB_004079a9
//                              action.cpp:306 (9)
//         004079a0     MOV        EAX,dword ptr [ESI]
//         004079a2     PUSH       0x0
//         004079a4     MOV        this,ESI
//         004079a6     CALL       dword ptr [EAX + 0x54]
//                               LAB_004079a9                                                 XREF[2]:     00407998(j), 0040799e(j)
//                              action.cpp:308 (13)
//         004079a9     MOV        EAX,dword ptr [ESI + 0x14]
//         004079ac     TEST       EAX,EAX
//         004079ae     JZ         LAB_004079bf
//         004079b0     CMP        byte ptr [EAX + 0x48],0x7
//         004079b4     JC         LAB_004079bf
//                              action.cpp:309 (9)
//         004079b6     MOV        EDX,dword ptr [ESI]
//         004079b8     PUSH       0x0
//         004079ba     MOV        this,ESI
//         004079bc     CALL       dword ptr [EDX + 0x58]
//                               LAB_004079bf                                                 XREF[2]:     004079ae(j), 004079b4(j)
//                              action.cpp:314 (2)
//         004079bf     MOV        AL,0x1
//                              action.cpp:315 (2)
//         004079c1     POP        ESI
//         004079c2     RET
//         004079c3     ??         90h
//         004079c4     NOP
//         004079c5     NOP
//         004079c6     NOP
//         004079c7     NOP
//         004079c8     NOP
//         004079c9     NOP
//         004079ca     NOP
//         004079cb     NOP
//         004079cc     NOP
//         004079cd     NOP
//         004079ce     NOP
//         004079cf     NOP
    return 0;
}

uchar RGE_Action::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Action * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?update@RGE_Action@@UAEEXZ                                   XREF[2]:     0056e6f8(*), 00575408(*)
//                               RGE_Action::update
//                              action.cpp:324 (3)
//         004079d0     PUSH       ESI
//         004079d1     MOV        ESI,this
//                              action.cpp:326 (13)
//         004079d3     MOV        EAX,dword ptr [ESI + 0x10]
//         004079d6     TEST       EAX,EAX
//         004079d8     JZ         LAB_004079e9
//         004079da     CMP        byte ptr [EAX + 0x48],0x7
//         004079de     JC         LAB_004079e9
//                              action.cpp:327 (9)
//         004079e0     MOV        EAX,dword ptr [ESI]
//         004079e2     PUSH       0x0
//         004079e4     MOV        this,ESI
//         004079e6     CALL       dword ptr [EAX + 0x54]
//                               LAB_004079e9                                                 XREF[2]:     004079d8(j), 004079de(j)
//                              action.cpp:329 (13)
//         004079e9     MOV        EAX,dword ptr [ESI + 0x14]
//         004079ec     TEST       EAX,EAX
//         004079ee     JZ         LAB_004079ff
//         004079f0     CMP        byte ptr [EAX + 0x48],0x7
//         004079f4     JC         LAB_004079ff
//                              action.cpp:330 (9)
//         004079f6     MOV        EDX,dword ptr [ESI]
//         004079f8     PUSH       0x0
//         004079fa     MOV        this,ESI
//         004079fc     CALL       dword ptr [EDX + 0x58]
//                               LAB_004079ff                                                 XREF[2]:     004079ee(j), 004079f4(j)
//                              action.cpp:333 (10)
//         004079ff     MOV        this,dword ptr [ESI + 0x34]
//         00407a02     MOV        EAX,dword ptr [ECX + this->obj]
//         00407a05     TEST       EAX,EAX
//         00407a07     JZ         LAB_00407a10
//                              action.cpp:334 (5)
//         00407a09     MOV        EAX,dword ptr [this->_padding_]
//         00407a0b     CALL       dword ptr [EAX + 0xc]
//                              action.cpp:341 (2)
//         00407a0e     POP        ESI
//         00407a0f     RET
//                               LAB_00407a10                                                 XREF[1]:     00407a07(j)
//                              action.cpp:337 (3)
//         00407a10     MOV        AL,byte ptr [ESI + 0xc]
//                              action.cpp:341 (7)
//         00407a13     POP        ESI
//         00407a14     CMP        AL,0x1
//         00407a16     SETZ       AL
//         00407a19     RET
//         00407a1a     ??         90h
//         00407a1b     NOP
//         00407a1c     NOP
//         00407a1d     NOP
//         00407a1e     NOP
//         00407a1f     NOP
    return 0;
}

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_target_obj(RGE_Action * this, RGE_Static_Object
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00407a24(R)
//                               ?set_target_obj@RGE_Action@@UAEXPAVRGE_Static_Object@@@Z     XREF[35]:    RGE_Action_Attack:004011b5(c),
//                               RGE_Action::set_target_obj                                                RGE_Action_Enter:00402460(c),
//                                                                                                         RGE_Action_Gather:00402f8c(c),
//                                                                                                         RGE_Action_Missile:00404ce9(c),
//                                                                                                         RGE_Action_Move_To:00405665(c),
//                                                                                                         ~RGE_Action:004074fc(c),
//                                                                                                         TRIBE_Action_Build:004cd271(c),
//                                                                                                         TRIBE_Action_Convert:004cdae3(c),
//                                                                                                         TRIBE_Action_Discovery_Artifact:00
//                                                                                                         TRIBE_Action_Heal:004ce9dc(c),
//                                                                                                         TRIBE_Action_Hunt:004cf17c(c),
//                                                                                                         TRIBE_Action_Repair:004d1770(c),
//                                                                                                         TRIBE_Action_Trade:004d275c(c),
//                                                                                                         0056e0ac(*), 0056e12c(*),
//                                                                                                         0056e194(*), 0056e204(*),
//                                                                                                         0056e26c(*), 0056e30c(*),
//                                                                                                         0056e374(*), [more]
//                              action.cpp:347 (4)
//         00407a20     PUSH       ESI
//         00407a21     MOV        ESI,this
//         00407a23     PUSH       EDI
//                              action.cpp:350 (15)
//         00407a24     MOV        EDI,dword ptr [ESP + param_1]
//         00407a28     MOV        EAX,dword ptr [ESI + 0x10]
//         00407a2b     TEST       EAX,EAX
//         00407a2d     JZ         LAB_00407a57
//         00407a2f     CMP        EAX,EDI
//         00407a31     JZ         LAB_00407a57
//                              action.cpp:352 (18)
//         00407a33     MOV        this,dword ptr [ESI + 0x8]
//         00407a36     MOV        EAX,dword ptr [ESI + 0x18]
//         00407a39     PUSH       EAX
//         00407a3a     MOV        EDX,dword ptr [ECX + this->state]
//         00407a3d     MOV        this,dword ptr [EDX + 0x3c]
//         00407a40     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              action.cpp:353 (4)
//         00407a45     TEST       EAX,EAX
//         00407a47     JZ         LAB_00407a57
//                              action.cpp:354 (14)
//         00407a49     MOV        this,dword ptr [ESI + 0x8]
//         00407a4c     MOV        EDX,dword ptr [EAX]
//         00407a4e     PUSH       this
//         00407a4f     MOV        this,EAX
//         00407a51     CALL       dword ptr [EDX + 0xc4]
//                               LAB_00407a57                                                 XREF[3]:     00407a2d(j), 00407a31(j),
//                                                                                                         00407a47(j)
//                              action.cpp:356 (5)
//         00407a57     CMP        dword ptr [ESI + 0x10],EDI
//         00407a5a     JZ         LAB_00407a8a
//                              action.cpp:359 (7)
//         00407a5c     TEST       EDI,EDI
//         00407a5e     MOV        dword ptr [ESI + 0x10],EDI
//         00407a61     JZ         LAB_00407a83
//                              action.cpp:361 (3)
//         00407a63     MOV        EDX,dword ptr [EDI + 0x4]
//                              action.cpp:362 (24)
//         00407a66     MOV        this,word ptr [ESI + 0x4]
//         00407a6a     MOV        EAX,dword ptr [EDI]
//         00407a6c     MOV        dword ptr [ESI + 0x18],EDX
//         00407a6f     MOV        EDX,dword ptr [ESI + 0x8]
//         00407a72     PUSH       0x0
//         00407a74     PUSH       this=>DAT_fffffff8
//         00407a75     PUSH       EDX=>DAT_fffffff4
//         00407a76     MOV        this,EDI
//         00407a78     CALL       dword ptr [EAX + 0xc0]
//                              action.cpp:367 (5)
//         00407a7e     POP        EDI
//         00407a7f     POP        ESI
//         00407a80     RET        0x4
//                               LAB_00407a83                                                 XREF[1]:     00407a61(j)
//                              action.cpp:365 (7)
//         00407a83     MOV        dword ptr [ESI + 0x18],0xffffffff
//                               LAB_00407a8a                                                 XREF[1]:     00407a5a(j)
//                              action.cpp:367 (5)
//         00407a8a     POP        EDI
//         00407a8b     POP        ESI
//         00407a8c     RET        0x4
//         00407a8f     ??         90h
    return;
}

void RGE_Action::set_target_obj2(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_target_obj2(RGE_Action * this, RGE_Static_Object
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00407a94(R)
//                               ?set_target_obj2@RGE_Action@@UAEXPAVRGE_Static_Object@@@Z    XREF[24]:    RGE_Action_Missile:00404cf5(c),
//                               RGE_Action::set_target_obj2                                               ~RGE_Action:00407505(c),
//                                                                                                         0056e0b0(*), 0056e130(*),
//                                                                                                         0056e198(*), 0056e208(*),
//                                                                                                         0056e270(*), 0056e310(*),
//                                                                                                         0056e378(*), 0056e3f8(*),
//                                                                                                         0056e6a8(*), 0056e728(*),
//                                                                                                         00574f00(*), 00574f70(*),
//                                                                                                         00574fe8(*), 00575068(*),
//                                                                                                         005750d8(*), 00575148(*),
//                                                                                                         00575200(*), 00575260(*), [more]
//                              action.cpp:371 (4)
//         00407a90     PUSH       ESI
//         00407a91     MOV        ESI,this
//         00407a93     PUSH       EDI
//                              action.cpp:372 (15)
//         00407a94     MOV        EDI,dword ptr [ESP + param_1]
//         00407a98     MOV        EAX,dword ptr [ESI + 0x14]
//         00407a9b     TEST       EAX,EAX
//         00407a9d     JZ         LAB_00407ac7
//         00407a9f     CMP        EAX,EDI
//         00407aa1     JZ         LAB_00407ac7
//                              action.cpp:374 (18)
//         00407aa3     MOV        this,dword ptr [ESI + 0x8]
//         00407aa6     MOV        EAX,dword ptr [ESI + 0x1c]
//         00407aa9     PUSH       EAX
//         00407aaa     MOV        EDX,dword ptr [ECX + this->state]
//         00407aad     MOV        this,dword ptr [EDX + 0x3c]
//         00407ab0     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              action.cpp:375 (4)
//         00407ab5     TEST       EAX,EAX
//         00407ab7     JZ         LAB_00407ac7
//                              action.cpp:376 (14)
//         00407ab9     MOV        this,dword ptr [ESI + 0x8]
//         00407abc     MOV        EDX,dword ptr [EAX]
//         00407abe     PUSH       this
//         00407abf     MOV        this,EAX
//         00407ac1     CALL       dword ptr [EDX + 0xc4]
//                               LAB_00407ac7                                                 XREF[3]:     00407a9d(j), 00407aa1(j),
//                                                                                                         00407ab7(j)
//                              action.cpp:378 (5)
//         00407ac7     CMP        dword ptr [ESI + 0x14],EDI
//         00407aca     JZ         LAB_00407afa
//                              action.cpp:381 (7)
//         00407acc     TEST       EDI,EDI
//         00407ace     MOV        dword ptr [ESI + 0x14],EDI
//         00407ad1     JZ         LAB_00407af3
//                              action.cpp:383 (3)
//         00407ad3     MOV        EDX,dword ptr [EDI + 0x4]
//                              action.cpp:384 (24)
//         00407ad6     MOV        this,word ptr [ESI + 0x4]
//         00407ada     MOV        EAX,dword ptr [EDI]
//         00407adc     MOV        dword ptr [ESI + 0x1c],EDX
//         00407adf     MOV        EDX,dword ptr [ESI + 0x8]
//         00407ae2     PUSH       0x0
//         00407ae4     PUSH       this=>DAT_fffffff8
//         00407ae5     PUSH       EDX=>DAT_fffffff4
//         00407ae6     MOV        this,EDI
//         00407ae8     CALL       dword ptr [EAX + 0xc0]
//                              action.cpp:389 (5)
//         00407aee     POP        EDI
//         00407aef     POP        ESI
//         00407af0     RET        0x4
//                               LAB_00407af3                                                 XREF[1]:     00407ad1(j)
//                              action.cpp:387 (7)
//         00407af3     MOV        dword ptr [ESI + 0x1c],0xffffffff
//                               LAB_00407afa                                                 XREF[1]:     00407aca(j)
//                              action.cpp:389 (5)
//         00407afa     POP        EDI
//         00407afb     POP        ESI
//         00407afc     RET        0x4
//         00407aff     ??         90h
    return;
}

void RGE_Action::copy_obj(RGE_Master_Action_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Action * this, RGE_Master_Action_Object
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[2]:     00407b04(R), 00407ba7(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     00407b0b(W), 00407b67(W), 00407b74(W), 00407b81(W),
//                                                                                     00407b8e(W), 00407b92(R)
//              RGE_Sprite *      Stack[-0x8]:4  new_sprite
//                               ?copy_obj@RGE_Action@@UAEXPAVRGE_Master_Action_Object@@@Z    XREF[22]:    0056e098(*), 0056e118(*),
//                               RGE_Action::copy_obj                                                      0056e180(*), 0056e1f0(*),
//                                                                                                         0056e258(*), 0056e2f8(*),
//                                                                                                         0056e360(*), 0056e3e0(*),
//                                                                                                         0056e690(*), 0056e710(*),
//                                                                                                         00574ee8(*), 00574f58(*),
//                                                                                                         00574fd0(*), 00575050(*),
//                                                                                                         005750c0(*), 00575130(*),
//                                                                                                         005751e8(*), 00575248(*),
//                                                                                                         005752c0(*), 00575328(*), [more]
//                              action.cpp:393 (4)
//         00407b00     PUSH       this
//         00407b01     PUSH       EBX
//         00407b02     PUSH       EBP
//         00407b03     PUSH       ESI
//                              action.cpp:398 (40)
//         00407b04     MOV        ESI,dword ptr [ESP + param_1]
//         00407b08     PUSH       EDI
//         00407b09     MOV        EDI,this
//         00407b0b     MOV        dword ptr [ESP + local_4],0x0
//         00407b13     MOV        this,dword ptr [EDI + 0x30]
//         00407b16     TEST       this,this
//         00407b18     JZ         LAB_00407bd6
//         00407b1e     MOV        EAX,dword ptr [ESI + 0xd8]
//         00407b24     TEST       EAX,EAX
//         00407b26     JZ         LAB_00407bd6
//                              action.cpp:402 (10)
//         00407b2c     MOVSX      ESI,word ptr [EAX + 0x8]
//         00407b30     MOV        EBP,dword ptr [EAX + 0x4]
//         00407b33     DEC        ESI
//         00407b34     JS         LAB_00407b4e
//                              action.cpp:407 (4)
//         00407b36     MOV        this,word ptr [ECX + this+0x6]
//                              action.cpp:432 (20)
//         00407b3a     LEA        EAX,[EBP + ESI*0x4]
//                               LAB_00407b3e                                                 XREF[1]:     00407b4c(j)
//         00407b3e     MOV        EDX,dword ptr [EAX]
//         00407b40     CMP        word ptr [EDX + 0x6],this
//         00407b44     JZ         LAB_00407b4e
//         00407b46     DEC        ESI
//         00407b47     SUB        EAX,0x4
//         00407b4a     TEST       ESI,ESI
//         00407b4c     JGE        LAB_00407b3e
//                               LAB_00407b4e                                                 XREF[2]:     00407b34(j), 00407b44(j)
//                              action.cpp:411 (8)
//         00407b4e     TEST       ESI,ESI
//         00407b50     JL         LAB_00407bef
//                              action.cpp:413 (21)
//         00407b56     MOV        EAX,dword ptr [EBP + ESI*0x4]
//         00407b5a     MOV        this,dword ptr [EDI + 0x8]
//         00407b5d     MOV        EDX,dword ptr [ECX + this->target_obj]
//         00407b60     MOV        EBX,dword ptr [EAX + 0x34]
//         00407b63     CMP        EDX,EBX
//         00407b65     JNZ        LAB_00407b6d
//         00407b67     MOV        dword ptr [ESP + local_4],EBX
//                              action.cpp:414 (13)
//         00407b6b     JMP        LAB_00407b92
//                               LAB_00407b6d                                                 XREF[1]:     00407b65(j)
//         00407b6d     MOV        EBX,dword ptr [EAX + 0x38]
//         00407b70     CMP        EDX,EBX
//         00407b72     JNZ        LAB_00407b7a
//         00407b74     MOV        dword ptr [ESP + local_4],EBX
//                              action.cpp:415 (13)
//         00407b78     JMP        LAB_00407b92
//                               LAB_00407b7a                                                 XREF[1]:     00407b72(j)
//         00407b7a     MOV        EBX,dword ptr [EAX + 0x3c]
//         00407b7d     CMP        EDX,EBX
//         00407b7f     JNZ        LAB_00407b87
//         00407b81     MOV        dword ptr [ESP + local_4],EBX
//                              action.cpp:416 (13)
//         00407b85     JMP        LAB_00407b92
//                               LAB_00407b87                                                 XREF[1]:     00407b7f(j)
//         00407b87     MOV        EAX,dword ptr [EAX + 0x40]
//         00407b8a     CMP        EDX,EAX
//         00407b8c     JNZ        LAB_00407b92
//         00407b8e     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_00407b92                                                 XREF[4]:     00407b6b(j), 00407b78(j),
//                                                                                                         00407b85(j), 00407b8c(j)
//                              action.cpp:418 (8)
//         00407b92     MOV        EAX,dword ptr [ESP + local_4]
//         00407b96     TEST       EAX,EAX
//         00407b98     JZ         LAB_00407ba0
//                              action.cpp:419 (6)
//         00407b9a     MOV        EDX,dword ptr [this->_padding_]
//         00407b9c     PUSH       EAX
//         00407b9d     CALL       dword ptr [EDX + 0x38]
//                               LAB_00407ba0                                                 XREF[1]:     00407b98(j)
//                              action.cpp:421 (21)
//         00407ba0     MOV        this,dword ptr [EBP + ESI*0x4]
//         00407ba4     MOV        EDX,dword ptr [EDI + 0x30]
//         00407ba7     MOV        EBX,dword ptr [ESP + param_1]
//         00407bab     MOV        EAX,dword ptr [EDI]
//         00407bad     PUSH       this
//         00407bae     PUSH       EDX=>DAT_fffffff8
//         00407baf     PUSH       EBX=>DAT_fffffff4
//         00407bb0     MOV        this,EDI
//         00407bb2     CALL       dword ptr [EAX + 0x44]
//                              action.cpp:422 (18)
//         00407bb5     MOV        EDX,dword ptr [EBP + ESI*0x4]
//         00407bb9     MOV        this,dword ptr [EDI + 0x34]
//         00407bbc     PUSH       EDX
//         00407bbd     MOV        EDX,dword ptr [EDI + 0x30]
//         00407bc0     MOV        EAX,dword ptr [this->_padding_]
//         00407bc2     PUSH       EDX=>DAT_fffffff8
//         00407bc3     PUSH       EBX=>DAT_fffffff4
//         00407bc4     CALL       dword ptr [EAX + 0x18]
//                              action.cpp:424 (7)
//         00407bc7     MOV        EAX,dword ptr [EBP + ESI*0x4]
//         00407bcb     MOV        dword ptr [EDI + 0x30],EAX
//                              action.cpp:432 (8)
//         00407bce     POP        EDI
//         00407bcf     POP        ESI
//         00407bd0     POP        EBP
//         00407bd1     POP        EBX
//         00407bd2     POP        this
//         00407bd3     RET        0x4
//                               LAB_00407bd6                                                 XREF[2]:     00407b18(j), 00407b26(j)
//                              action.cpp:429 (12)
//         00407bd6     MOV        EDX,dword ptr [EDI]
//         00407bd8     PUSH       0x0
//         00407bda     PUSH       0x0
//         00407bdc     PUSH       ESI
//         00407bdd     MOV        this,EDI
//         00407bdf     CALL       dword ptr [EDX + 0x44]
//                              action.cpp:430 (13)
//         00407be2     MOV        this,dword ptr [EDI + 0x34]
//         00407be5     PUSH       0x0
//         00407be7     PUSH       0x0=>DAT_fffffff8
//         00407be9     PUSH       ESI=>DAT_fffffff4
//         00407bea     MOV        EAX,dword ptr [this->_padding_]
//         00407bec     CALL       dword ptr [EAX + 0x18]
//                               LAB_00407bef                                                 XREF[1]:     00407b50(j)
//                              action.cpp:432 (8)
//         00407bef     POP        EDI
//         00407bf0     POP        ESI
//         00407bf1     POP        EBP
//         00407bf2     POP        EBX
//         00407bf3     POP        this
//         00407bf4     RET        0x4
//         00407bf7     ??         90h
//         00407bf8     NOP
//         00407bf9     NOP
//         00407bfa     NOP
//         00407bfb     NOP
//         00407bfc     NOP
//         00407bfd     NOP
//         00407bfe     NOP
//         00407bff     NOP
    return;
}

void RGE_Action::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    /* TODO: Stub */
//                              void __thiscall copy_obj_sprites(RGE_Action * this, RGE_Master_Actio
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              RGE_Master_Act    Stack[0x4]:4   param_1
//              RGE_Task *        Stack[0x8]:4   param_2
//              RGE_Task *        Stack[0xc]:4   param_3
//                               ?copy_obj_sprites@RGE_Action@@UAEXPAVRGE_Master_Action_Obje  XREF[21]:    0056e11c(*), 0056e184(*),
//                               RGE_Action::copy_obj_sprites                                              0056e1f4(*), 0056e25c(*),
//                                                                                                         0056e2fc(*), 0056e364(*),
//                                                                                                         0056e3e4(*), 0056e694(*),
//                                                                                                         0056e714(*), 00574eec(*),
//                                                                                                         00574f5c(*), 00574fd4(*),
//                                                                                                         00575054(*), 005750c4(*),
//                                                                                                         00575134(*), 005751ec(*),
//                                                                                                         0057524c(*), 005752c4(*),
//                                                                                                         0057532c(*), 005753bc(*), [more]
//                              action.cpp:436 (3)
//         00407c00     RET        0xc
//         00407c03     ??         90h
//         00407c04     NOP
//         00407c05     NOP
//         00407c06     NOP
//         00407c07     NOP
//         00407c08     NOP
//         00407c09     NOP
//         00407c0a     NOP
//         00407c0b     NOP
//         00407c0c     NOP
//         00407c0d     NOP
//         00407c0e     NOP
//         00407c0f     NOP
    return;
}

void RGE_Action::get_state_name(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_state_name(RGE_Action * this, char * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[2]:     00407caa(R), 00407cd3(R)
//                               ?get_state_name@RGE_Action@@UAEXPAD@Z                        XREF[22]:    0056e0a0(*), 0056e120(*),
//                               RGE_Action::get_state_name                                                0056e188(*), 0056e1f8(*),
//                                                                                                         0056e260(*), 0056e300(*),
//                                                                                                         0056e368(*), 0056e3e8(*),
//                                                                                                         0056e698(*), 0056e718(*),
//                                                                                                         00574ef0(*), 00574f60(*),
//                                                                                                         00574fd8(*), 00575058(*),
//                                                                                                         005750c8(*), 00575138(*),
//                                                                                                         005751f0(*), 00575250(*),
//                                                                                                         005752c8(*), 00575330(*), [more]
//                              action.cpp:441 (23)
//         00407c10     XOR        EAX,EAX
//         00407c12     PUSH       ESI
//         00407c13     MOV        AL,byte ptr [ECX + this->state]
//         00407c16     PUSH       EDI
//         00407c17     CMP        EAX,0xf
//         00407c1a     JA         switchD_00407c20::default
//                               switchD_00407c20::switchD
//         00407c20     JMP        dword ptr [EAX*0x4 + switchD_00407c20::switchd   = 00407c27
//                               switchD_00407c20::caseD_0                                    XREF[2]:     00407c20(j), 00407ce8(*)
//                              action.cpp:444 (10)
//         00407c27     MOV        EDI,s_None                                       = 4Eh
//         00407c2c     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_1                                    XREF[2]:     00407c20(j), 00407cec(*)
//                              action.cpp:445 (7)
//         00407c31     MOV        EDI,s_Done                                       = "Done"
//         00407c36     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_2                                    XREF[2]:     00407c20(j), 00407cf0(*)
//                              action.cpp:446 (10)
//         00407c38     MOV        EDI,s_Wait                                       = 57h
//         00407c3d     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_3                                    XREF[2]:     00407c20(j), 00407cf4(*)
//                              action.cpp:447 (7)
//         00407c42     MOV        EDI,s_Search                                     = "Search"
//         00407c47     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_4                                    XREF[2]:     00407c20(j), 00407cf8(*)
//                              action.cpp:448 (7)
//         00407c49     MOV        EDI,s_Goto                                       = "Goto"
//         00407c4e     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_5                                    XREF[2]:     00407c20(j), 00407cfc(*)
//                              action.cpp:449 (7)
//         00407c50     MOV        EDI,s_Goto2                                      = "Goto2"
//         00407c55     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_6                                    XREF[2]:     00407c20(j), 00407d00(*)
//                              action.cpp:450 (7)
//         00407c57     MOV        EDI,s_Work                                       = "Work"
//         00407c5c     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_7                                    XREF[2]:     00407c20(j), 00407d04(*)
//                              action.cpp:451 (7)
//         00407c5e     MOV        EDI,s_Work2                                      = "Work2"
//         00407c63     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_8                                    XREF[2]:     00407c20(j), 00407d08(*)
//                              action.cpp:452 (7)
//         00407c65     MOV        EDI,s_Return                                     = "Return"
//         00407c6a     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_9                                    XREF[2]:     00407c20(j), 00407d0c(*)
//                              action.cpp:453 (7)
//         00407c6c     MOV        EDI,s_Turn                                       = "Turn"
//         00407c71     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_a                                    XREF[2]:     00407c20(j), 00407d10(*)
//                              action.cpp:454 (7)
//         00407c73     MOV        EDI,s_Delay                                      = "Delay"
//         00407c78     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_b                                    XREF[2]:     00407c20(j), 00407d14(*)
//                              action.cpp:455 (7)
//         00407c7a     MOV        EDI,s_Move                                       = 4Dh
//         00407c7f     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_c                                    XREF[2]:     00407c20(j), 00407d18(*)
//                              action.cpp:456 (7)
//         00407c81     MOV        EDI,s_Attack                                     = 41h
//         00407c86     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_d                                    XREF[2]:     00407c20(j), 00407d1c(*)
//                              action.cpp:457 (7)
//         00407c88     MOV        EDI,s_Failed                                     = "Failed"
//         00407c8d     JMP        LAB_00407c9b
//                               switchD_00407c20::caseD_e                                    XREF[2]:     00407c20(j), 00407d20(*)
//                              action.cpp:458 (7)
//         00407c8f     MOV        EDI,s_Invalidated                                = 49h
//         00407c94     JMP        LAB_00407cc4
//                               switchD_00407c20::caseD_f                                    XREF[2]:     00407c20(j), 00407d24(*)
//                              action.cpp:459 (31)
//         00407c96     MOV        EDI,s_MoveNoSearch                               = 4Dh
//                               LAB_00407c9b                                                 XREF[7]:     00407c36(j), 00407c47(j),
//                                                                                                         00407c55(j), 00407c63(j),
//                                                                                                         00407c71(j), 00407c7f(j),
//                                                                                                         00407c8d(j)
//         00407c9b     OR         this,0xffffffff
//         00407c9e     XOR        EAX,EAX
//         00407ca0     SCASB.RE   ES:EDI=>s_MoveNoSearch                           = 4Dh
//                                                                                  = "oveNoSearch"
//                                                                                  = "Failed"
//                                                                                  = "Turn"
//                                                                                  = "Work2"
//                                                                                  = "Goto2"
//         00407ca2     NOT        this
//         00407ca4     SUB        EDI,this
//         00407ca6     MOV        EDX,this
//         00407ca8     MOV        ESI,EDI
//         00407caa     MOV        EDI,dword ptr [ESP + param_1]
//         00407cae     SHR        this,0x2
//         00407cb1     MOVSD.REP  ES:EDI,ESI
//         00407cb3     MOV        this,EDX
//                              action.cpp:460 (5)
//         00407cb5     AND        this,0x3
//         00407cb8     MOVSB.REP  ES:EDI,ESI
//                              action.cpp:462 (5)
//         00407cba     POP        EDI
//         00407cbb     POP        ESI
//         00407cbc     RET        0x4
//                               switchD_00407c20::default                                    XREF[1]:     00407c1a(j)
//                              action.cpp:460 (36)
//         00407cbf     MOV        EDI,s_Unknown                                    = 55h
//                               LAB_00407cc4                                                 XREF[8]:     00407c2c(j), 00407c3d(j),
//                                                                                                         00407c4e(j), 00407c5c(j),
//                                                                                                         00407c6a(j), 00407c78(j),
//                                                                                                         00407c86(j), 00407c94(j)
//         00407cc4     OR         this,0xffffffff
//         00407cc7     XOR        EAX,EAX
//         00407cc9     SCASB.RE   ES:EDI=>s_Invalidated                            = 55h
//                                                                                  = 41h
//                                                                                  = 4Eh
//                                                                                  = 49h
//                                                                                  = "nvalidated"
//                                                                                  = "Delay"
//         00407ccb     NOT        this
//         00407ccd     SUB        EDI,this
//         00407ccf     MOV        EAX,this
//         00407cd1     MOV        ESI,EDI
//         00407cd3     MOV        EDI,dword ptr [ESP + param_1]
//         00407cd7     SHR        this,0x2
//         00407cda     MOVSD.REP  ES:EDI,ESI
//         00407cdc     MOV        this,EAX
//         00407cde     AND        this,0x3
//         00407ce1     MOVSB.REP  ES:EDI,ESI
//                              action.cpp:462 (69)
//         00407ce3     POP        EDI
//         00407ce4     POP        ESI
//         00407ce5     RET        0x4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00407c20::switchdataD_00407ce8                       XREF[1]:     get_state_name:00407c20(*)
//         00407ce8     addr       switchD_00407c20::caseD_0
//         00407cec     addr       switchD_00407c20::caseD_1
//         00407cf0     addr       switchD_00407c20::caseD_2
//         00407cf4     addr       switchD_00407c20::caseD_3
//         00407cf8     addr       switchD_00407c20::caseD_4
//         00407cfc     addr       switchD_00407c20::caseD_5
//         00407d00     addr       switchD_00407c20::caseD_6
//         00407d04     addr       switchD_00407c20::caseD_7
//         00407d08     addr       switchD_00407c20::caseD_8
//         00407d0c     addr       switchD_00407c20::caseD_9
//         00407d10     addr       switchD_00407c20::caseD_a
//         00407d14     addr       switchD_00407c20::caseD_b
//         00407d18     addr       switchD_00407c20::caseD_c
//         00407d1c     addr       switchD_00407c20::caseD_d
//         00407d20     addr       switchD_00407c20::caseD_e
//         00407d24     addr       switchD_00407c20::caseD_f
//         00407d28     ??         90h
//         00407d29     ??         90h
//         00407d2a     ??         90h
//         00407d2b     ??         90h
//         00407d2c     ??         90h
//         00407d2d     ??         90h
//         00407d2e     ??         90h
//         00407d2f     ??         90h
    return;
}

float RGE_Action::targetX() {
    /* TODO: Stub */
//                              float __thiscall targetX(RGE_Action * this)
//              float             ST0:10         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?targetX@RGE_Action@@QBEMXZ                                  XREF[10]:    RGE_Action_Enter:004025b9(c),
//                               RGE_Action::targetX                                                       update:00402a8f(c),
//                                                                                                         attack:00430ad5(c),
//                                                                                                         attack:00430af2(c),
//                                                                                                         attack:00430b0f(c),
//                                                                                                         moveTo:00430d93(c),
//                                                                                                         currentTargetX:0043162f(c),
//                                                                                                         meet_target:004d2165(c),
//                                                                                                         load_game:005268ba(c),
//                                                                                                         load_game:00526beb(c)
//                              action.cpp:468 (3)
//         00407d30     FLD        float ptr [ECX + this->target_x]
//                              action.cpp:470 (1)
//         00407d33     RET
//         00407d34     ??         90h
//         00407d35     NOP
//         00407d36     NOP
//         00407d37     NOP
//         00407d38     NOP
//         00407d39     NOP
//         00407d3a     NOP
//         00407d3b     NOP
//         00407d3c     NOP
//         00407d3d     NOP
//         00407d3e     NOP
//         00407d3f     NOP
    return 0;
}

float RGE_Action::targetY() {
    /* TODO: Stub */
//                              float __thiscall targetY(RGE_Action * this)
//              float             ST0:10         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?targetY@RGE_Action@@QBEMXZ                                  XREF[7]:     RGE_Action_Enter:004025ce(c),
//                               RGE_Action::targetY                                                       update:00402aa7(c),
//                                                                                                         moveTo:00430db0(c),
//                                                                                                         currentTargetY:0043165f(c),
//                                                                                                         meet_target:004d217d(c),
//                                                                                                         load_game:005268ad(c),
//                                                                                                         load_game:00526bde(c)
//                              action.cpp:476 (3)
//         00407d40     FLD        float ptr [ECX + this->target_y]
//                              action.cpp:478 (1)
//         00407d43     RET
//         00407d44     ??         90h
//         00407d45     NOP
//         00407d46     NOP
//         00407d47     NOP
//         00407d48     NOP
//         00407d49     NOP
//         00407d4a     NOP
//         00407d4b     NOP
//         00407d4c     NOP
//         00407d4d     NOP
//         00407d4e     NOP
//         00407d4f     NOP
    return 0;
}

float RGE_Action::targetZ() {
    /* TODO: Stub */
//                              float __thiscall targetZ(RGE_Action * this)
//              float             ST0:10         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?targetZ@RGE_Action@@QBEMXZ                                  XREF[4]:     moveTo:00430dcd(c),
//                               RGE_Action::targetZ                                                       currentTargetZ:0043168f(c),
//                                                                                                         load_game:005268a0(c),
//                                                                                                         load_game:00526bd1(c)
//                              action.cpp:484 (3)
//         00407d50     FLD        float ptr [ECX + this->target_z]
//                              action.cpp:486 (1)
//         00407d53     RET
//         00407d54     ??         90h
//         00407d55     NOP
//         00407d56     NOP
//         00407d57     NOP
//         00407d58     NOP
//         00407d59     NOP
//         00407d5a     NOP
//         00407d5b     NOP
//         00407d5c     NOP
//         00407d5d     NOP
//         00407d5e     NOP
//         00407d5f     NOP
    return 0;
}

uchar RGE_Action::subAction() {
    /* TODO: Stub */
//                              uchar __thiscall subAction(RGE_Action * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?subAction@RGE_Action@@QBEEXZ                                XREF[2]:     load_game:00526893(c),
//                               RGE_Action::subAction                                                     load_game:00526bc4(c)
//                              action.cpp:492 (3)
//         00407d60     MOV        AL,byte ptr [ECX + this->subActionValue]
//                              action.cpp:494 (1)
//         00407d63     RET
//         00407d64     ??         90h
//         00407d65     NOP
//         00407d66     NOP
//         00407d67     NOP
//         00407d68     NOP
//         00407d69     NOP
//         00407d6a     NOP
//         00407d6b     NOP
//         00407d6c     NOP
//         00407d6d     NOP
//         00407d6e     NOP
//         00407d6f     NOP
    return 0;
}

void RGE_Action::setSubAction(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setSubAction(RGE_Action * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00407d70(R)
//                               ?setSubAction@RGE_Action@@QAEXE@Z                            XREF[18]:    set_state:00401688(c),
//                               RGE_Action::setSubAction                                                  set_state:004026cd(c),
//                                                                                                         set_state:00402d46(c),
//                                                                                                         set_state:00403240(c),
//                                                                                                         set_state:00403480(c),
//                                                                                                         set_state:00406f50(c),
//                                                                                                         set_state:004cd482(c),
//                                                                                                         set_state:004cd52b(c),
//                                                                                                         set_state:004cdef8(c),
//                                                                                                         set_state:004cdf9d(c),
//                                                                                                         set_state:004ceb9e(c),
//                                                                                                         set_state:004cec44(c),
//                                                                                                         set_state:004cf455(c),
//                                                                                                         set_state:004cf735(c),
//                                                                                                         set_state:004d1975(c),
//                                                                                                         set_state:004d1a24(c),
//                                                                                                         set_state:004d29bb(c),
//                                                                                                         set_state:004d2bd9(c)
//                              action.cpp:500 (7)
//         00407d70     MOV        AL,byte ptr [ESP + param_1]
//         00407d74     MOV        byte ptr [ECX + this->subActionValue],AL
//                              action.cpp:502 (3)
//         00407d77     RET        0x4
//         00407d7a     ??         90h
//         00407d7b     NOP
//         00407d7c     NOP
//         00407d7d     NOP
//         00407d7e     NOP
//         00407d7f     NOP
    return;
}

