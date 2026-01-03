#include "../common.h"
#include "act_move.h"

RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Move_To(RGE_Action_Move_To * this, i
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040552c(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00405526(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00405546(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040555f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00405536(W)
//                               ??0RGE_Action_Move_To@@QAE@HPAVRGE_Action_Object@@@Z         XREF[1]:     create_action:0040415b(c)
//                               RGE_Action_Move_To::RGE_Action_Move_To
//                              act_move.cpp:40 (47)
//         00405510     PUSH       -0x1
//         00405512     PUSH       FUN_0055c308
//         00405517     MOV        EAX,FS:[0x0]
//         0040551d     PUSH       EAX
//         0040551e     MOV        dword ptr FS:[0x0],ESP
//         00405525     PUSH       this
//         00405526     MOV        EAX,dword ptr [ESP + param_2]
//         0040552a     PUSH       ESI
//         0040552b     PUSH       EDI
//         0040552c     MOV        EDI,dword ptr [ESP + param_1]
//         00405530     PUSH       0x1
//         00405532     MOV        ESI,this
//         00405534     PUSH       EAX
//         00405535     PUSH       EDI
//         00405536     MOV        dword ptr [ESP + local_10],ESI
//         0040553a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              act_move.cpp:42 (32)
//         0040553f     LEA        this,[ESI + 0x40]
//         00405542     PUSH       0x4
//         00405544     PUSH       this
//         00405545     PUSH       EDI
//         00405546     MOV        dword ptr [ESP + local_4],0x0
//         0040554e     MOV        dword ptr [ESI],RGE_Action_Move_To::`vftable'    = 00405580
//         00405554     MOV        word ptr [ESI + 0x4],0x1
//         0040555a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              act_move.cpp:43 (24)
//         0040555f     MOV        this,dword ptr [ESP + local_c]
//         00405563     ADD        ESP,0xc
//         00405566     MOV        EAX,ESI
//         00405568     MOV        dword ptr FS:[0x0],this
//         0040556f     POP        EDI
//         00405570     POP        ESI
//         00405571     ADD        ESP,0x10
//         00405574     RET        0x8
//         00405577     ??         90h
//         00405578     NOP
//         00405579     NOP
//         0040557a     NOP
//         0040557b     NOP
//         0040557c     NOP
//         0040557d     NOP
//         0040557e     NOP
//         0040557f     NOP
}

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Move_To(RGE_Action_Move_To * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004055a0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004055b9(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004055c1(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004055bd(R)
//              float             Stack[0x14]:4  param_5                   XREF[2]:     004055af(R), 004055c8(R)
//              RGE_Sprite *      Stack[0x18]:4  param_6                   XREF[1]:     004055d4(R)
//                               ??0RGE_Action_Move_To@@QAE@PAVRGE_Action_Object@@MMMMPAVRGE  XREF[17]:    set_state:00401625(c),
//                               RGE_Action_Move_To::RGE_Action_Move_To                                    update:0040231f(c),
//                                                                                                         set_state:0040268d(c),
//                                                                                                         set_state:00402d0f(c),
//                                                                                                         set_state:00403209(c),
//                                                                                                         move_to:004063a3(c),
//                                                                                                         set_state:00406ed3(c),
//                                                                                                         set_state:00406f10(c),
//                                                                                                         moveTo:00430e6c(c),
//                                                                                                         set_state:004ccd5b(c),
//                                                                                                         set_state:004ccdaf(c),
//                                                                                                         set_state:004cd44b(c),
//                                                                                                         set_state:004cdec1(c),
//                                                                                                         set_state:004ceb67(c),
//                                                                                                         set_state:004cf41d(c),
//                                                                                                         set_state:004d193e(c),
//                                                                                                         set_state:004d2983(c)
//                              act_move.cpp:51 (15)
//         004055a0     MOV        EAX,dword ptr [ESP + param_1]
//         004055a4     PUSH       ESI
//         004055a5     PUSH       0x1
//         004055a7     MOV        ESI,this
//         004055a9     PUSH       EAX
//         004055aa     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              act_move.cpp:61 (64)
//         004055af     FLD        float ptr [ESP + param_5]
//         004055b3     FCOMP      float ptr [DAT_0056e400]                         = align(22)
//         004055b9     MOV        this,dword ptr [ESP + param_2]
//         004055bd     MOV        EAX,dword ptr [ESP + param_4]
//         004055c1     MOV        EDX,dword ptr [ESP + param_3]
//         004055c5     MOV        dword ptr [ESI + 0x20],this
//         004055c8     MOV        this,dword ptr [ESP + param_5]
//         004055cc     MOV        dword ptr [ESI + 0x28],EAX
//         004055cf     FNSTSW     AX
//         004055d1     MOV        dword ptr [ESI + 0x40],this
//         004055d4     MOV        this,dword ptr [ESP + param_6]
//         004055d8     TEST       AH,0x41
//         004055db     MOV        dword ptr [ESI],RGE_Action_Move_To::`vftable'    = 00405580
//         004055e1     MOV        word ptr [ESI + 0x4],0x1
//         004055e7     MOV        dword ptr [ESI + 0x24],EDX
//         004055ea     MOV        dword ptr [ESI + 0x38],this
//         004055ed     JZ         LAB_004055f6
//                              act_move.cpp:62 (7)
//         004055ef     MOV        dword ptr [ESI + 0x40],0x3ecccccd
//                               LAB_004055f6                                                 XREF[1]:     004055ed(j)
//                              act_move.cpp:64 (4)
//         004055f6     TEST       this,this
//         004055f8     JNZ        LAB_00405619
//                              act_move.cpp:66 (16)
//         004055fa     MOV        EDX,dword ptr [ESI + 0x8]
//         004055fd     MOV        EAX,dword ptr [EDX + 0x8]
//         00405600     MOV        this,dword ptr [EAX + 0xbc]
//         00405606     TEST       this,this
//         00405608     JNZ        LAB_00405616
//                              act_move.cpp:67 (6)
//         0040560a     MOV        EAX,dword ptr [EAX + 0x18]
//         0040560d     MOV        dword ptr [ESI + 0x38],EAX
//                              act_move.cpp:76 (6)
//         00405610     MOV        EAX,ESI
//         00405612     POP        ESI
//         00405613     RET        0x18
//                               LAB_00405616                                                 XREF[1]:     00405608(j)
//                              act_move.cpp:69 (3)
//         00405616     MOV        dword ptr [ESI + 0x38],this
//                               LAB_00405619                                                 XREF[1]:     004055f8(j)
//                              act_move.cpp:76 (6)
//         00405619     MOV        EAX,ESI
//         0040561b     POP        ESI
//         0040561c     RET        0x18
//         0040561f     ??         90h
}

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, RGE_Sprite* param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Move_To(RGE_Action_Move_To * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00405636(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0040564a(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     00405680(R), 0040568a(R)
//              RGE_Sprite *      Stack[0x10]:4  param_4                   XREF[1]:     00405691(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00405651(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004056c5(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00405641(W)
//                               ??0RGE_Action_Move_To@@QAE@PAVRGE_Action_Object@@PAVRGE_Sta  XREF[13]:    set_state:004015ec(c),
//                               RGE_Action_Move_To::RGE_Action_Move_To                                    set_state:004032d6(c),
//                                                                                                         set_state:00403440(c),
//                                                                                                         move_to:00406373(c),
//                                                                                                         moveTo:00430cf2(c),
//                                                                                                         set_state:004cd4eb(c),
//                                                                                                         set_state:004cdf5d(c),
//                                                                                                         set_state:004cec04(c),
//                                                                                                         set_state:004cf50e(c),
//                                                                                                         set_state:004cf6f4(c),
//                                                                                                         set_state:004d19e4(c),
//                                                                                                         set_state:004d2a4c(c),
//                                                                                                         set_state:004d2b98(c)
//                              act_move.cpp:84 (42)
//         00405620     PUSH       -0x1
//         00405622     PUSH       FUN_0055c328
//         00405627     MOV        EAX,FS:[0x0]
//         0040562d     PUSH       EAX
//         0040562e     MOV        dword ptr FS:[0x0],ESP
//         00405635     PUSH       this
//         00405636     MOV        EAX,dword ptr [ESP + param_1]
//         0040563a     PUSH       ESI
//         0040563b     PUSH       EDI
//         0040563c     MOV        ESI,this
//         0040563e     PUSH       0x1
//         00405640     PUSH       EAX
//         00405641     MOV        dword ptr [ESP + local_10],ESI
//         00405645     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              act_move.cpp:87 (32)
//         0040564a     MOV        EDI,dword ptr [ESP + param_2]
//         0040564e     MOV        this,ESI
//         00405650     PUSH       EDI
//         00405651     MOV        dword ptr [ESP + local_4],0x0
//         00405659     MOV        dword ptr [ESI],RGE_Action_Move_To::`vftable'    = 00405580
//         0040565f     MOV        word ptr [ESI + 0x4],0x1
//         00405665     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              act_move.cpp:88 (4)
//         0040566a     TEST       EDI,EDI
//         0040566c     JZ         LAB_00405680
//                              act_move.cpp:90 (6)
//         0040566e     MOV        this,dword ptr [EDI + 0x38]
//         00405671     MOV        dword ptr [ESI + 0x20],this
//                              act_move.cpp:91 (6)
//         00405674     MOV        EDX,dword ptr [EDI + 0x3c]
//         00405677     MOV        dword ptr [ESI + 0x24],EDX
//                              act_move.cpp:92 (6)
//         0040567a     MOV        EAX,dword ptr [EDI + 0x40]
//         0040567d     MOV        dword ptr [ESI + 0x28],EAX
//                               LAB_00405680                                                 XREF[1]:     0040566c(j)
//                              act_move.cpp:98 (31)
//         00405680     FLD        float ptr [ESP + param_3]
//         00405684     FCOMP      float ptr [DAT_0056e400]                         = align(22)
//         0040568a     MOV        this,dword ptr [ESP + param_3]
//         0040568e     MOV        dword ptr [ESI + 0x40],this
//         00405691     MOV        this,dword ptr [ESP + param_4]
//         00405695     MOV        dword ptr [ESI + 0x38],this
//         00405698     FNSTSW     AX
//         0040569a     TEST       AH,0x41
//         0040569d     JZ         LAB_004056a6
//                              act_move.cpp:99 (7)
//         0040569f     MOV        dword ptr [ESI + 0x40],0x3ecccccd
//                               LAB_004056a6                                                 XREF[1]:     0040569d(j)
//                              act_move.cpp:101 (4)
//         004056a6     TEST       this,this
//         004056a8     JNZ        LAB_004056c5
//                              act_move.cpp:103 (16)
//         004056aa     MOV        EDX,dword ptr [ESI + 0x8]
//         004056ad     MOV        EAX,dword ptr [EDX + 0x8]
//         004056b0     MOV        this,dword ptr [EAX + 0xbc]
//         004056b6     TEST       this,this
//         004056b8     JNZ        LAB_004056c2
//                              act_move.cpp:104 (6)
//         004056ba     MOV        EAX,dword ptr [EAX + 0x18]
//         004056bd     MOV        dword ptr [ESI + 0x38],EAX
//                              act_move.cpp:105 (2)
//         004056c0     JMP        LAB_004056c5
//                               LAB_004056c2                                                 XREF[1]:     004056b8(j)
//                              act_move.cpp:106 (3)
//         004056c2     MOV        dword ptr [ESI + 0x38],this
//                               LAB_004056c5                                                 XREF[2]:     004056a8(j), 004056c0(j)
//                              act_move.cpp:112 (21)
//         004056c5     MOV        this,dword ptr [ESP + local_c]
//         004056c9     MOV        EAX,ESI
//         004056cb     POP        EDI
//         004056cc     MOV        dword ptr FS:[0x0],this
//         004056d3     POP        ESI
//         004056d4     ADD        ESP,0x10
//         004056d7     RET        0x10
//         004056da     ??         90h
//         004056db     NOP
//         004056dc     NOP
//         004056dd     NOP
//         004056de     NOP
//         004056df     NOP
}

RGE_Action_Move_To::~RGE_Action_Move_To() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Action_Move_To(RGE_Action_Move_To * this)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00405708(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004056f9(W)
//                               ??1RGE_Action_Move_To@@UAE@XZ                                XREF[1]:     `scalar_deleting_destructor':00405
//                               RGE_Action_Move_To::~RGE_Action_Move_To
//                              act_move.cpp:118 (35)
//         004056e0     PUSH       -0x1
//         004056e2     PUSH       FUN_0055c348
//         004056e7     MOV        EAX,FS:[0x0]
//         004056ed     PUSH       EAX
//         004056ee     MOV        dword ptr FS:[0x0],ESP
//         004056f5     PUSH       this
//         004056f6     PUSH       ESI
//         004056f7     MOV        ESI,this
//         004056f9     MOV        dword ptr [ESP + local_10],ESI
//         004056fd     MOV        dword ptr [ESI],RGE_Action_Move_To::`vftable'    = 00405580
//                              act_move.cpp:122 (21)
//         00405703     MOV        this,dword ptr [ESI + 0x8]
//         00405706     PUSH       0x0
//         00405708     MOV        dword ptr [ESP + local_4],0x0
//         00405710     MOV        EAX,dword ptr [this->_padding_]
//         00405712     CALL       dword ptr [EAX + 0x1c0]
//                              act_move.cpp:123 (13)
//         00405718     MOV        this,dword ptr [ESI + 0x8]
//         0040571b     MOV        EDX,dword ptr [this->_padding_]
//         0040571d     CALL       dword ptr [EDX + 0x1ec]
//         00405723     MOV        this,ESI
//                              act_move.cpp:124 (29)
//         00405725     MOV        dword ptr [ESP + 0x10],0xffffffff
//         0040572d     CALL       RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
//         00405732     MOV        this,dword ptr [ESP + 0x8]
//         00405736     POP        ESI
//         00405737     MOV        dword ptr FS:[0x0],this
//         0040573e     ADD        ESP,0x10
//         00405741     RET
//         00405742     ??         90h
//         00405743     NOP
//         00405744     NOP
//         00405745     NOP
//         00405746     NOP
//         00405747     NOP
//         00405748     NOP
//         00405749     NOP
//         0040574a     NOP
//         0040574b     NOP
//         0040574c     NOP
//         0040574d     NOP
//         0040574e     NOP
//         0040574f     NOP
}

void RGE_Action_Move_To::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Action_Move_To * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00405752(R)
//                               ?save@RGE_Action_Move_To@@UAEXH@Z                            XREF[1]:     0056e3b4(*)
//                               RGE_Action_Move_To::save
//                              act_move.cpp:130 (2)
//         00405750     PUSH       ESI
//         00405751     PUSH       EDI
//                              act_move.cpp:131 (12)
//         00405752     MOV        EDI,dword ptr [ESP + param_1]
//         00405756     MOV        ESI,this
//         00405758     PUSH       EDI
//         00405759     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              act_move.cpp:132 (15)
//         0040575e     ADD        ESI,0x40
//         00405761     PUSH       0x4
//         00405763     PUSH       ESI
//         00405764     PUSH       EDI
//         00405765     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040576a     ADD        ESP,0xc
//                              act_move.cpp:133 (5)
//         0040576d     POP        EDI
//         0040576e     POP        ESI
//         0040576f     RET        0x4
//         00405772     ??         90h
//         00405773     NOP
//         00405774     NOP
//         00405775     NOP
//         00405776     NOP
//         00405777     NOP
//         00405778     NOP
//         00405779     NOP
//         0040577a     NOP
//         0040577b     NOP
//         0040577c     NOP
//         0040577d     NOP
//         0040577e     NOP
//         0040577f     NOP
    return;
}

void RGE_Action_Move_To::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(RGE_Action_Move_To * this, uchar para
//              void              <VOID>         <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?first_in_stack@RGE_Action_Move_To@@UAEXE@Z                  XREF[1]:     0056e3bc(*)
//                               RGE_Action_Move_To::first_in_stack
//                              act_move.cpp:139 (3)
//         00405780     PUSH       ESI
//         00405781     MOV        ESI,this
//                              act_move.cpp:141 (24)
//         00405783     MOV        EAX,dword ptr [ESI + 0x10]
//         00405786     TEST       EAX,EAX
//         00405788     JZ         LAB_004057a8
//         0040578a     MOV        this,dword ptr [ESI + 0x40]
//         0040578d     PUSH       this
//         0040578e     MOV        this,dword ptr [ESI + 0x8]
//         00405791     PUSH       EAX
//         00405792     CALL       RGE_Static_Object::inRange                       int inRange(RGE_Static_Object * this, RGE_Sta
//         00405797     TEST       EAX,EAX
//         00405799     JZ         LAB_004057a8
//                              act_move.cpp:145 (9)
//         0040579b     MOV        EDX,dword ptr [ESI]
//         0040579d     PUSH       0x1
//         0040579f     MOV        this,ESI
//         004057a1     CALL       dword ptr [EDX + 0x5c]
//                              act_move.cpp:162 (4)
//         004057a4     POP        ESI
//         004057a5     RET        0x4
//                               LAB_004057a8                                                 XREF[2]:     00405788(j), 00405799(j)
//                              act_move.cpp:150 (24)
//         004057a8     MOV        this,dword ptr [ESI + 0x8]
//         004057ab     MOV        EAX,dword ptr [this->_padding_]
//         004057ad     CALL       dword ptr [EAX + 0xfc]
//         004057b3     FCOMP      double ptr [null_0056e408]                       = align(14)
//         004057b9     FNSTSW     AX
//         004057bb     TEST       AH,0x40
//         004057be     JZ         LAB_004057cd
//                              act_move.cpp:154 (9)
//         004057c0     MOV        EDX,dword ptr [ESI]
//         004057c2     PUSH       0xd
//         004057c4     MOV        this,ESI
//         004057c6     CALL       dword ptr [EDX + 0x5c]
//                              act_move.cpp:162 (4)
//         004057c9     POP        ESI
//         004057ca     RET        0x4
//                               LAB_004057cd                                                 XREF[1]:     004057be(j)
//                              act_move.cpp:161 (9)
//         004057cd     MOV        EAX,dword ptr [ESI]
//         004057cf     PUSH       0x3
//         004057d1     MOV        this,ESI
//         004057d3     CALL       dword ptr [EAX + 0x5c]
//                              act_move.cpp:162 (4)
//         004057d6     POP        ESI
//         004057d7     RET        0x4
//         004057da     ??         90h
//         004057db     NOP
//         004057dc     NOP
//         004057dd     NOP
//         004057de     NOP
//         004057df     NOP
    return;
}

void RGE_Action_Move_To::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(RGE_Action_Move_To * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004057e2(R)
//                               ?set_state@RGE_Action_Move_To@@MAEXE@Z                       XREF[1]:     0056e3fc(*)
//                               RGE_Action_Move_To::set_state
//                              act_move.cpp:168 (2)
//         004057e0     MOV        EAX,this
//                              act_move.cpp:173 (7)
//         004057e2     MOV        this,dword ptr [ESP + param_1]
//         004057e6     MOV        byte ptr [EAX + 0xc],this
//                              act_move.cpp:175 (27)
//         004057e9     AND        this,0xff
//         004057ef     DEC        this
//         004057f0     CMP        this,0xd
//         004057f3     JA         switchD_004057fd::caseD_2
//         004057f5     XOR        EDX,EDX
//         004057f7     MOV        DL,byte ptr [this->_padding_ + 0x405840]=>PTR_
//                               switchD_004057fd::switchD
//         004057fd     JMP        dword ptr [EDX*0x4 + switchD_004057fd::switchd   = 00405813
//                               switchD_004057fd::caseD_4                                    XREF[2]:     004057fd(j), 00405834(*)
//                              act_move.cpp:182 (9)
//         00405804     MOV        this,dword ptr [EAX + 0x8]
//         00405807     MOV        EAX,dword ptr [EAX + 0x38]
//         0040580a     PUSH       EAX
//         0040580b     MOV        EDX,dword ptr [this->_padding_]
//                              act_move.cpp:196 (3)
//         0040580d     CALL       dword ptr [EDX + 0x38]
//                              act_move.cpp:200 (3)
//         00405810     RET        0x4
//                               switchD_004057fd::caseD_d                                    XREF[3]:     004057fd(j), 00405830(*),
//                               switchD_004057fd::caseD_e                                                 00405838(*)
//                               switchD_004057fd::caseD_1
//                              act_move.cpp:191 (7)
//         00405813     MOV        this,byte ptr [EAX + 0x3c]
//         00405816     TEST       this,this
//         00405818     JNZ        switchD_004057fd::caseD_2
//                              act_move.cpp:196 (17)
//         0040581a     MOV        EAX,dword ptr [EAX + 0x8]
//         0040581d     MOV        this,dword ptr [EAX + 0x8]
//         00405820     MOV        EDX,dword ptr [EAX]
//         00405822     MOV        this,dword ptr [ECX + this->_padding_]
//         00405825     PUSH       this
//         00405826     MOV        this,EAX
//         00405828     CALL       dword ptr [EDX + 0x38]
//                               switchD_004057fd::caseD_3                                    XREF[4]:     004057f3(j), 004057fd(j),
//                               switchD_004057fd::caseD_5                                                 00405818(j), 0040583c(*)
//                               switchD_004057fd::caseD_6
//                               switchD_004057fd::caseD_7
//                               switchD_004057fd::caseD_8
//                               switchD_004057fd::caseD_9
//                               switchD_004057fd::caseD_a
//                               switchD_004057fd::caseD_b
//                               switchD_004057fd::caseD_c
//                               switchD_004057fd::caseD_2
//                              act_move.cpp:200 (35)
//         0040582b     RET        0x4
    return;
}

uchar RGE_Action_Move_To::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Action_Move_To * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//              float             Stack[-0x8]:4  yDiff@fffffff8
//              float             Stack[-0xc]:3  yDiff
//                               ?update@RGE_Action_Move_To@@UAEEXZ                           XREF[1]:     0056e3c8(*)
//                               RGE_Action_Move_To::update
//                              act_move.cpp:206 (7)
//         00405850     SUB        ESP,0x8
//         00405853     PUSH       ESI
//         00405854     MOV        ESI,this
//         00405856     PUSH       EDI
//                              act_move.cpp:233 (27)
//         00405857     MOV        EAX,dword ptr [ESI + 0x18]
//         0040585a     CMP        EAX,-0x1
//         0040585d     JZ         LAB_0040587c
//         0040585f     PUSH       EAX
//         00405860     MOV        EAX,dword ptr [ESI + 0x8]
//         00405863     MOV        this,dword ptr [EAX + 0xc]
//         00405866     MOV        this,dword ptr [ECX + this->_padding_]
//         00405869     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0040586e     TEST       EAX,EAX
//         00405870     JNZ        LAB_0040587c
//                              act_move.cpp:237 (8)
//         00405872     MOV        EDX,dword ptr [ESI]
//         00405874     PUSH       EAX
//         00405875     MOV        this,ESI
//         00405877     CALL       dword ptr [EDX + 0x54]
//                              act_move.cpp:252 (2)
//         0040587a     JMP        LAB_004058b5
//                               LAB_0040587c                                                 XREF[2]:     0040585d(j), 00405870(j)
//                              act_move.cpp:255 (27)
//         0040587c     MOV        EAX,dword ptr [ESI + 0x1c]
//         0040587f     CMP        EAX,-0x1
//         00405882     JZ         LAB_0040589f
//         00405884     PUSH       EAX
//         00405885     MOV        EAX,dword ptr [ESI + 0x8]
//         00405888     MOV        this,dword ptr [EAX + 0xc]
//         0040588b     MOV        this,dword ptr [ECX + this->_padding_]
//         0040588e     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00405893     TEST       EAX,EAX
//         00405895     JNZ        LAB_0040589f
//                              act_move.cpp:256 (8)
//         00405897     MOV        EDX,dword ptr [ESI]
//         00405899     PUSH       EAX
//         0040589a     MOV        this,ESI
//         0040589c     CALL       dword ptr [EDX + 0x58]
//                               LAB_0040589f                                                 XREF[2]:     00405882(j), 00405895(j)
//                              act_move.cpp:259 (7)
//         0040589f     MOV        EAX,dword ptr [ESI + 0x10]
//         004058a2     TEST       EAX,EAX
//         004058a4     JZ         LAB_004058eb
//                              act_move.cpp:261 (6)
//         004058a6     CMP        byte ptr [EAX + 0x48],0x7
//         004058aa     JC         LAB_004058eb
//                              act_move.cpp:266 (9)
//         004058ac     MOV        EAX,dword ptr [ESI]
//         004058ae     PUSH       0x0
//         004058b0     MOV        this,ESI
//         004058b2     CALL       dword ptr [EAX + 0x54]
//                               LAB_004058b5                                                 XREF[1]:     0040587a(j)
//                              act_move.cpp:268 (6)
//         004058b5     CMP        byte ptr [ESI + 0x3c],0x1
//         004058b9     JNZ        LAB_004058c3
//                              act_move.cpp:273 (2)
//         004058bb     MOV        AL,0x5
//                              act_move.cpp:504 (6)
//         004058bd     POP        EDI
//         004058be     POP        ESI
//         004058bf     ADD        ESP,0x8
//         004058c2     RET
//                               LAB_004058c3                                                 XREF[1]:     004058b9(j)
//                              act_move.cpp:281 (32)
//         004058c3     MOV        this,dword ptr [ESI + 0x8]
//         004058c6     MOV        ESI,dword ptr [ESI + 0x18]
//         004058c9     PUSH       0x0
//         004058cb     PUSH       ESI
//         004058cc     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004058cf     MOV        EDX,dword ptr [this->_padding_]
//         004058d1     PUSH       0x262
//         004058d6     PUSH       0x1fb
//         004058db     PUSH       EAX
//         004058dc     PUSH       EAX
//         004058dd     CALL       dword ptr [EDX + 0x148]
//                              act_move.cpp:282 (2)
//         004058e3     MOV        AL,0x4
//                              act_move.cpp:504 (6)
//         004058e5     POP        EDI
//         004058e6     POP        ESI
//         004058e7     ADD        ESP,0x8
//         004058ea     RET
//                               LAB_004058eb                                                 XREF[2]:     004058a4(j), 004058aa(j)
//                              act_move.cpp:287 (30)
//         004058eb     XOR        this,this
//         004058ed     MOV        this,byte ptr [ESI + 0xc]
//         004058f0     DEC        this
//         004058f1     CMP        this,0xc
//         004058f4     JA         switchD_00405902::caseD_2
//         004058fa     XOR        EDX,EDX
//         004058fc     MOV        DL,byte ptr [this->_padding_ + 0x405be0]=>PTR_
//                               switchD_00405902::switchD
//         00405902     JMP        dword ptr [EDX*0x4 + switchD_00405902::switchd   = 00405bc2
//                               switchD_00405902::caseD_3                                    XREF[2]:     00405902(j), 00405bd0(*)
//                              act_move.cpp:291 (21)
//         00405909     TEST       EAX,EAX
//         0040590b     JZ         LAB_0040596b
//         0040590d     MOV        this,dword ptr [ESI + 0x40]
//         00405910     PUSH       this
//         00405911     MOV        this,dword ptr [ESI + 0x8]
//         00405914     PUSH       EAX
//         00405915     CALL       RGE_Static_Object::inRange                       int inRange(RGE_Static_Object * this, RGE_Sta
//         0040591a     TEST       EAX,EAX
//         0040591c     JZ         LAB_0040596b
//                              act_move.cpp:296 (9)
//         0040591e     MOV        EDX,dword ptr [ESI]
//         00405920     PUSH       0x1
//         00405922     MOV        this,ESI
//         00405924     CALL       dword ptr [EDX + 0x5c]
//                              act_move.cpp:297 (7)
//         00405927     MOV        AL,byte ptr [ESI + 0x3c]
//         0040592a     TEST       AL,AL
//         0040592c     JNZ        LAB_0040594c
//                              act_move.cpp:302 (30)
//         0040592e     MOV        this,dword ptr [ESI + 0x8]
//         00405931     PUSH       0x0
//         00405933     PUSH       0x0
//         00405935     PUSH       0x262
//         0040593a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0040593d     MOV        EDX,dword ptr [this->_padding_]
//         0040593f     PUSH       0x1fa
//         00405944     PUSH       EAX
//         00405945     PUSH       EAX
//         00405946     CALL       dword ptr [EDX + 0x148]
//                               LAB_0040594c                                                 XREF[1]:     0040592c(j)
//                              act_move.cpp:308 (13)
//         0040594c     MOV        this,dword ptr [ESI + 0x8]
//         0040594f     PUSH       0x0
//         00405951     MOV        EAX,dword ptr [this->_padding_]
//         00405953     CALL       dword ptr [EAX + 0x12c]
//                              act_move.cpp:309 (3)
//         00405959     MOV        this,dword ptr [ESI + 0x8]
//                              act_move.cpp:310 (9)
//         0040595c     MOV        AL,0x2
//         0040595e     MOV        dword ptr [this->_padding_ + 0x58],0x0
//                              act_move.cpp:504 (6)
//         00405965     POP        EDI
//         00405966     POP        ESI
//         00405967     ADD        ESP,0x8
//         0040596a     RET
//                               LAB_0040596b                                                 XREF[2]:     0040590b(j), 0040591c(j)
//                              act_move.cpp:314 (7)
//         0040596b     MOV        EAX,dword ptr [ESI + 0x10]
//         0040596e     TEST       EAX,EAX
//         00405970     JZ         LAB_00405984
//                              act_move.cpp:319 (6)
//         00405972     MOV        EDX,dword ptr [EAX + 0x38]
//         00405975     MOV        dword ptr [ESI + 0x20],EDX
//                              act_move.cpp:320 (6)
//         00405978     MOV        this,dword ptr [EAX + 0x3c]
//         0040597b     MOV        dword ptr [ESI + 0x24],this
//                              act_move.cpp:321 (6)
//         0040597e     MOV        EDX,dword ptr [EAX + 0x40]
//         00405981     MOV        dword ptr [ESI + 0x28],EDX
//                               LAB_00405984                                                 XREF[1]:     00405970(j)
//                              act_move.cpp:328 (21)
//         00405984     MOV        EAX,dword ptr [ESI + 0x24]
//         00405987     MOV        this,dword ptr [ESI + 0x20]
//         0040598a     PUSH       0x3f800000
//         0040598f     PUSH       EAX
//         00405990     PUSH       this
//         00405991     MOV        this,dword ptr [ESI + 0x8]
//         00405994     CALL       RGE_Moving_Object::setGoal                       void setGoal(RGE_Moving_Object * this, float
//                              act_move.cpp:330 (8)
//         00405999     FLD        float ptr [ESI + 0x20]
//         0040599c     CALL       __ftol                                           undefined __ftol()
//                              act_move.cpp:331 (12)
//         004059a1     FLD        float ptr [ESI + 0x24]
//         004059a4     MOV        byte ptr [ESP + 0x8],AL
//         004059a8     CALL       __ftol                                           undefined __ftol()
//                              act_move.cpp:332 (12)
//         004059ad     FLD        float ptr [ESI + 0x28]
//         004059b0     MOV        byte ptr [ESP + 0x9],AL
//         004059b4     CALL       __ftol                                           undefined __ftol()
//                              act_move.cpp:335 (17)
//         004059b9     MOV        this,dword ptr [ESI + 0x8]
//         004059bc     MOV        byte ptr [ESP + 0xa],AL
//         004059c0     MOV        AL,byte ptr [this->_padding_ + 0x174]
//         004059c6     TEST       AL,AL
//         004059c8     JNZ        LAB_004059e1
//                              act_move.cpp:339 (15)
//         004059ca     MOV        EDX,dword ptr [this->_padding_]
//         004059cc     LEA        EAX,[ESP + 0x8]
//         004059d0     PUSH       0x0
//         004059d2     PUSH       EAX
//         004059d3     CALL       dword ptr [EDX + 0x1bc]
//                              act_move.cpp:340 (8)
//         004059d9     MOV        this,dword ptr [ESI + 0x8]
//         004059dc     CALL       RGE_Moving_Object::setFinalUserDefinedWaypoint   void setFinalUserDefinedWaypoint(RGE_Moving_O
//                               LAB_004059e1                                                 XREF[1]:     004059c8(j)
//                              act_move.cpp:346 (12)
//         004059e1     MOV        this,dword ptr [ESI + 0x40]
//         004059e4     PUSH       this
//         004059e5     MOV        this,dword ptr [ESI + 0x8]
//         004059e8     CALL       RGE_Moving_Object::setActionRange                void setActionRange(RGE_Moving_Object * this,
//                              act_move.cpp:348 (7)
//         004059ed     MOV        EAX,dword ptr [ESI + 0x10]
//         004059f0     TEST       EAX,EAX
//         004059f2     JZ         LAB_00405a10
//                              act_move.cpp:350 (12)
//         004059f4     MOV        EDX,dword ptr [EAX + 0x4]
//         004059f7     MOV        this,dword ptr [ESI + 0x8]
//         004059fa     PUSH       EDX
//         004059fb     CALL       RGE_Moving_Object::setTargetID                   void setTargetID(RGE_Moving_Object * this, in
//                              act_move.cpp:352 (14)
//         00405a00     MOV        EAX,dword ptr [ESI + 0x10]
//         00405a03     MOV        EAX,dword ptr [EAX + 0x8]
//         00405a06     MOV        this,dword ptr [EAX + 0x34]
//         00405a09     MOV        EDX,dword ptr [EAX + 0x30]
//         00405a0c     PUSH       this
//         00405a0d     PUSH       EDX
//                              act_move.cpp:354 (2)
//         00405a0e     JMP        LAB_00405a1e
//                               LAB_00405a10                                                 XREF[1]:     004059f2(j)
//                              act_move.cpp:356 (10)
//         00405a10     MOV        this,dword ptr [ESI + 0x8]
//         00405a13     PUSH       -0x1
//         00405a15     CALL       RGE_Moving_Object::setTargetID                   void setTargetID(RGE_Moving_Object * this, in
//                              act_move.cpp:357 (12)
//         00405a1a     PUSH       0x0
//         00405a1c     PUSH       0x0
//                               LAB_00405a1e                                                 XREF[1]:     00405a0e(j)
//         00405a1e     MOV        this,dword ptr [ESI + 0x8]
//         00405a21     CALL       RGE_Moving_Object::setTargetRadius               void setTargetRadius(RGE_Moving_Object * this
//                              act_move.cpp:360 (16)
//         00405a26     MOV        this,dword ptr [ESI + 0x8]
//         00405a29     CALL       RGE_Moving_Object::findPath                      PathResult findPath(RGE_Moving_Object * this)
//         00405a2e     TEST       EAX,EAX
//         00405a30     JNZ        switchD_00405902::caseD_2
//                              act_move.cpp:364 (9)
//         00405a36     MOV        EAX,dword ptr [ESI]
//         00405a38     PUSH       0x4
//         00405a3a     MOV        this,ESI
//         00405a3c     CALL       dword ptr [EAX + 0x5c]
//                              act_move.cpp:503 (2)
//         00405a3f     XOR        AL,AL
//                              act_move.cpp:504 (6)
//         00405a41     POP        EDI
//         00405a42     POP        ESI
//         00405a43     ADD        ESP,0x8
//         00405a46     RET
//                               switchD_00405902::caseD_4                                    XREF[2]:     00405902(j), 00405bd4(*)
//                              act_move.cpp:375 (4)
//         00405a47     TEST       EAX,EAX
//         00405a49     JZ         LAB_00405aa9
//                              act_move.cpp:380 (6)
//         00405a4b     FLD        float ptr [ESI + 0x20]
//         00405a4e     FSUB       float ptr [EAX + 0x38]
//                              act_move.cpp:381 (6)
//         00405a51     FLD        float ptr [ESI + 0x24]
//         00405a54     FSUB       float ptr [EAX + 0x3c]
//                              act_move.cpp:385 (76)
//         00405a57     FLD        ST1
//         00405a59     FCOMP      double ptr [null_0056e410]                       = align(6)
//         00405a5f     FSTP       float ptr [ESP + 0x8]
//         00405a63     FNSTSW     AX
//         00405a65     TEST       AH,0x1
//         00405a68     JNZ        LAB_00405b53
//         00405a6e     FCOMP      double ptr [DAT_0056e418]
//         00405a74     FNSTSW     AX
//         00405a76     TEST       AH,0x41
//         00405a79     JZ         LAB_00405b55
//         00405a7f     FLD        float ptr [ESP + 0x8]
//         00405a83     FCOMP      double ptr [null_0056e410]                       = align(6)
//         00405a89     FNSTSW     AX
//         00405a8b     TEST       AH,0x1
//         00405a8e     JNZ        LAB_00405b55
//         00405a94     FLD        float ptr [ESP + 0x8]
//         00405a98     FCOMP      double ptr [DAT_0056e418]
//         00405a9e     FNSTSW     AX
//         00405aa0     TEST       AH,0x41
//                              act_move.cpp:402 (6)
//         00405aa3     JZ         LAB_00405b55
//                               LAB_00405aa9                                                 XREF[1]:     00405a49(j)
//                              act_move.cpp:409 (8)
//         00405aa9     MOV        this,dword ptr [ESI + 0x8]
//         00405aac     CALL       RGE_Moving_Object::doMove                        int doMove(RGE_Moving_Object * this)
//                              act_move.cpp:412 (4)
//         00405ab1     TEST       EAX,EAX
//         00405ab3     JNZ        LAB_00405af3
//                              act_move.cpp:417 (9)
//         00405ab5     MOV        EAX,dword ptr [ESI]
//         00405ab7     PUSH       0x1
//         00405ab9     MOV        this,ESI
//         00405abb     CALL       dword ptr [EAX + 0x5c]
//                               switchD_00405902::caseD_d                                    XREF[2]:     00405902(j), 00405bd8(*)
//                              act_move.cpp:492 (7)
//         00405abe     MOV        AL,byte ptr [ESI + 0x3c]
//         00405ac1     TEST       AL,AL
//         00405ac3     JNZ        LAB_00405ae3
//                              act_move.cpp:498 (30)
//         00405ac5     MOV        this,dword ptr [ESI + 0x8]
//         00405ac8     PUSH       0x0
//         00405aca     PUSH       0x0
//         00405acc     PUSH       0x262
//         00405ad1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00405ad4     MOV        EDX,dword ptr [this->_padding_]
//         00405ad6     PUSH       0x1f9
//         00405adb     PUSH       EAX
//         00405adc     PUSH       EAX
//         00405add     CALL       dword ptr [EDX + 0x148]
//                               LAB_00405ae3                                                 XREF[1]:     00405ac3(j)
//                              act_move.cpp:500 (2)
//         00405ae3     MOV        AL,0x3
//                              act_move.cpp:504 (6)
//         00405ae5     POP        EDI
//         00405ae6     POP        ESI
//         00405ae7     ADD        ESP,0x8
//         00405aea     RET
//                               switchD_00405902::caseD_5                                    XREF[5]:     004058f4(j), 00405902(j),
//                               switchD_00405902::caseD_6                                                 00405a30(j), 00405af6(j),
//                               switchD_00405902::caseD_7                                                 00405bdc(*)
//                               switchD_00405902::caseD_8
//                               switchD_00405902::caseD_9
//                               switchD_00405902::caseD_a
//                               switchD_00405902::caseD_b
//                               switchD_00405902::caseD_c
//                               switchD_00405902::caseD_2
//                              act_move.cpp:503 (2)
//         00405aeb     XOR        AL,AL
//                              act_move.cpp:504 (6)
//         00405aed     POP        EDI
//         00405aee     POP        ESI
//         00405aef     ADD        ESP,0x8
//         00405af2     RET
//                               LAB_00405af3                                                 XREF[1]:     00405ab3(j)
//                              act_move.cpp:428 (5)
//         00405af3     CMP        EAX,0x2
//         00405af6     JNZ        switchD_00405902::caseD_2
//                              act_move.cpp:435 (11)
//         00405af8     MOV        EAX,dword ptr [ESI + 0x10]
//         00405afb     TEST       EAX,EAX
//         00405afd     JZ         LAB_00405b8c
//                              act_move.cpp:437 (6)
//         00405b03     FLD        float ptr [ESI + 0x20]
//         00405b06     FSUB       float ptr [EAX + 0x38]
//                              act_move.cpp:438 (6)
//         00405b09     FLD        float ptr [ESI + 0x24]
//         00405b0c     FSUB       float ptr [EAX + 0x3c]
//                              act_move.cpp:442 (70)
//         00405b0f     FLD        ST1
//         00405b11     FCOMP      double ptr [null_0056e410]                       = align(6)
//         00405b17     FSTP       float ptr [ESP + 0xc]
//         00405b1b     FNSTSW     AX
//         00405b1d     TEST       AH,0x1
//         00405b20     JNZ        LAB_00405b53
//         00405b22     FCOMP      double ptr [DAT_0056e418]
//         00405b28     FNSTSW     AX
//         00405b2a     TEST       AH,0x41
//         00405b2d     JZ         LAB_00405b55
//         00405b2f     FLD        float ptr [ESP + 0xc]
//         00405b33     FCOMP      double ptr [null_0056e410]                       = align(6)
//         00405b39     FNSTSW     AX
//         00405b3b     TEST       AH,0x1
//         00405b3e     JNZ        LAB_00405b55
//         00405b40     FLD        float ptr [ESP + 0xc]
//         00405b44     FCOMP      double ptr [DAT_0056e418]
//         00405b4a     FNSTSW     AX
//         00405b4c     TEST       AH,0x41
//         00405b4f     JNZ        LAB_00405b8c
//         00405b51     JMP        LAB_00405b55
//                               LAB_00405b53                                                 XREF[2]:     00405a68(j), 00405b20(j)
//         00405b53     FSTP       ST0
//                               LAB_00405b55                                                 XREF[6]:     00405a79(j), 00405a8e(j),
//                                                                                                         00405aa3(j), 00405b2d(j),
//                                                                                                         00405b3e(j), 00405b51(j)
//                              act_move.cpp:447 (27)
//         00405b55     MOV        this,dword ptr [ESI + 0x8]
//         00405b58     PUSH       0x0
//         00405b5a     PUSH       0x0
//         00405b5c     PUSH       0x0
//         00405b5e     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00405b61     MOV        EDX,dword ptr [this->_padding_]
//         00405b63     PUSH       0x1fc
//         00405b68     PUSH       EAX
//         00405b69     PUSH       EAX
//         00405b6a     CALL       dword ptr [EDX + 0x148]
//                              act_move.cpp:448 (9)
//         00405b70     MOV        EDI,dword ptr [ESI]
//         00405b72     PUSH       0x3
//         00405b74     MOV        this,ESI
//         00405b76     CALL       dword ptr [EDI + 0x5c]
//                              act_move.cpp:450 (7)
//         00405b79     MOV        EDI,dword ptr [EDI + 0x28]
//         00405b7c     MOV        this,ESI
//         00405b7e     CALL       EDI
//                              act_move.cpp:455 (4)
//         00405b80     MOV        this,ESI
//         00405b82     CALL       EDI
//                              act_move.cpp:503 (2)
//         00405b84     XOR        AL,AL
//                              act_move.cpp:504 (6)
//         00405b86     POP        EDI
//         00405b87     POP        ESI
//         00405b88     ADD        ESP,0x8
//         00405b8b     RET
//                               LAB_00405b8c                                                 XREF[2]:     00405afd(j), 00405b4f(j)
//                              act_move.cpp:466 (7)
//         00405b8c     MOV        AL,byte ptr [ESI + 0x3c]
//         00405b8f     TEST       AL,AL
//         00405b91     JNZ        LAB_00405bb1
//                              act_move.cpp:471 (30)
//         00405b93     MOV        this,dword ptr [ESI + 0x8]
//         00405b96     PUSH       0x0
//         00405b98     PUSH       0x0
//         00405b9a     PUSH       0x262
//         00405b9f     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00405ba2     MOV        EDX,dword ptr [this->_padding_]
//         00405ba4     PUSH       0x1fa
//         00405ba9     PUSH       EAX
//         00405baa     PUSH       EAX
//         00405bab     CALL       dword ptr [EDX + 0x148]
//                               LAB_00405bb1                                                 XREF[1]:     00405b91(j)
//                              act_move.cpp:473 (9)
//         00405bb1     MOV        EAX,dword ptr [ESI]
//         00405bb3     PUSH       0x1
//         00405bb5     MOV        this,ESI
//         00405bb7     CALL       dword ptr [EAX + 0x5c]
//                              act_move.cpp:480 (2)
//         00405bba     MOV        AL,0x2
//                              act_move.cpp:504 (49)
//         00405bbc     POP        EDI
//         00405bbd     POP        ESI
//         00405bbe     ADD        ESP,0x8
//         00405bc1     RET
//                               switchD_00405902::caseD_1                                    XREF[2]:     00405902(j), 00405bcc(*)
//         00405bc2     POP        EDI
//         00405bc3     MOV        AL,0x1
//         00405bc5     POP        ESI
//         00405bc6     ADD        ESP,0x8
//         00405bc9     RET
    return 0;
}

uchar RGE_Action_Move_To::is_in_range() {
    /* TODO: Stub */
//                              uchar __thiscall is_in_range(RGE_Action_Move_To * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action_Mov    ECX:4 (auto)   this
//                               ?is_in_range@RGE_Action_Move_To@@IAEEXZ
//                               RGE_Action_Move_To::is_in_range
//                              act_move.cpp:510 (3)
//         00405bf0     PUSH       ESI
//         00405bf1     MOV        ESI,this
//                              act_move.cpp:511 (14)
//         00405bf3     FLD        float ptr [ESI + 0x40]
//         00405bf6     FCOMP      float ptr [DAT_0056e400]                         = align(22)
//         00405bfc     FNSTSW     AX
//         00405bfe     TEST       AH,0x41
//                              act_move.cpp:514 (9)
//         00405c01     MOV        EAX,dword ptr [ESI + 0x10]
//         00405c04     JNZ        LAB_00405c37
//         00405c06     TEST       EAX,EAX
//         00405c08     JZ         LAB_00405c15
//                              act_move.cpp:515 (9)
//         00405c0a     MOV        this,dword ptr [ESI + 0x8]
//         00405c0d     PUSH       EAX
//         00405c0e     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//                              act_move.cpp:516 (2)
//         00405c13     JMP        LAB_00405c29
//                               LAB_00405c15                                                 XREF[1]:     00405c08(j)
//                              act_move.cpp:517 (20)
//         00405c15     MOV        EAX,dword ptr [ESI + 0x28]
//         00405c18     MOV        this,dword ptr [ESI + 0x24]
//         00405c1b     MOV        EDX,dword ptr [ESI + 0x20]
//         00405c1e     PUSH       EAX
//         00405c1f     PUSH       this
//         00405c20     MOV        this,dword ptr [ESI + 0x8]
//         00405c23     PUSH       EDX
//         00405c24     CALL       RGE_Static_Object::distance_to_position          float distance_to_position(RGE_Static_Object
//                               LAB_00405c29                                                 XREF[1]:     00405c13(j)
//                              act_move.cpp:518 (10)
//         00405c29     FCOMP      float ptr [ESI + 0x40]
//         00405c2c     FNSTSW     AX
//         00405c2e     TEST       AH,0x41
//         00405c31     JZ         LAB_00405c51
//                              act_move.cpp:519 (2)
//         00405c33     MOV        AL,0x1
//                              act_move.cpp:527 (2)
//         00405c35     POP        ESI
//         00405c36     RET
//                               LAB_00405c37                                                 XREF[1]:     00405c04(j)
//                              act_move.cpp:523 (22)
//         00405c37     TEST       EAX,EAX
//         00405c39     JZ         LAB_00405c51
//         00405c3b     MOV        this,dword ptr [ESI + 0x8]
//         00405c3e     PUSH       0x3e800000
//         00405c43     PUSH       EAX
//         00405c44     CALL       RGE_Static_Object::inRange                       int inRange(RGE_Static_Object * this, RGE_Sta
//         00405c49     TEST       EAX,EAX
//         00405c4b     JZ         LAB_00405c51
//                              act_move.cpp:524 (2)
//         00405c4d     MOV        AL,0x1
//                              act_move.cpp:527 (2)
//         00405c4f     POP        ESI
//         00405c50     RET
//                               LAB_00405c51                                                 XREF[3]:     00405c31(j), 00405c39(j),
//                                                                                                         00405c4b(j)
//                              act_move.cpp:526 (2)
//         00405c51     XOR        AL,AL
//                              act_move.cpp:527 (2)
//         00405c53     POP        ESI
//         00405c54     RET
//         00405c55     ??         90h
//         00405c56     NOP
//         00405c57     NOP
//         00405c58     NOP
//         00405c59     NOP
//         00405c5a     NOP
//         00405c5b     NOP
//         00405c5c     NOP
//         00405c5d     NOP
//         00405c5e     NOP
//         00405c5f     NOP
    return 0;
}

