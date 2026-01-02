#include "../common.h"
#include "act_entr.h"

RGE_Action_Enter::RGE_Action_Enter(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Enter(RGE_Action_Enter * this, RGE_A
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00402429(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00402442(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[2]:     0040243e(R), 00402483(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00402449(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004025d6(R)
//              XYPoint           Stack[-0x18]:8 rVal
//              XYPoint           Stack[-0x20]:8 start
//              XYPoint           Stack[-0x28]:8 dest                      XREF[1]:     00402435(W)
//                               ??0RGE_Action_Enter@@QAE@PAVRGE_Action_Object@@PAVRGE_Task@  XREF[2]:     enter:00431206(c),
//                               RGE_Action_Enter::RGE_Action_Enter                                        create_task_action:004d0b00(c)
//                              act_entr.cpp:61 (46)
//         00402410     PUSH       -0x1
//         00402412     PUSH       FUN_0055c138
//         00402417     MOV        EAX,FS:[0x0]
//         0040241d     PUSH       EAX
//         0040241e     MOV        dword ptr FS:[0x0],ESP
//         00402425     SUB        ESP,0x1c
//         00402428     PUSH       EBX
//         00402429     MOV        EBX,dword ptr [ESP + param_1]
//         0040242d     PUSH       EBP
//         0040242e     PUSH       ESI
//         0040242f     PUSH       EDI
//         00402430     MOV        EDI,this
//         00402432     PUSH       0x1
//         00402434     PUSH       EBX
//         00402435     MOV        dword ptr [ESP + dest.x],EDI
//         00402439     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              act_entr.cpp:64 (39)
//         0040243e     MOV        ESI,dword ptr [ESP + param_3]
//         00402442     MOV        EAX,dword ptr [ESP + param_2]
//         00402446     PUSH       ESI
//         00402447     MOV        this,EDI
//         00402449     MOV        dword ptr [ESP + local_4],0x0
//         00402451     MOV        dword ptr [EDI],RGE_Action_Enter::`vftable'      = 004023f0
//         00402457     MOV        word ptr [EDI + 0x4],0x3
//         0040245d     MOV        dword ptr [EDI + 0x30],EAX
//         00402460     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              act_entr.cpp:70 (8)
//         00402465     TEST       ESI,ESI
//         00402467     JZ         LAB_004025d6
//                              act_entr.cpp:72 (6)
//         0040246d     MOV        this,dword ptr [ESI + 0x38]
//         00402470     MOV        dword ptr [EDI + 0x20],this
//                              act_entr.cpp:73 (6)
//         00402473     MOV        EDX,dword ptr [ESI + 0x3c]
//         00402476     MOV        dword ptr [EDI + 0x24],EDX
//                              act_entr.cpp:74 (6)
//         00402479     MOV        EAX,dword ptr [ESI + 0x40]
//         0040247c     MOV        dword ptr [EDI + 0x28],EAX
//                              act_entr.cpp:84 (96)
//         0040247f     MOV        EAX,dword ptr [ESI]
//         00402481     MOV        this,ESI
//         00402483     MOV        dword ptr [ESP + param_3],EAX
//         00402487     MOV        EBP,dword ptr [EAX + 0x134]
//         0040248d     CALL       EBP
//         0040248f     CMP        AL,0x2
//         00402491     JNZ        LAB_004024bd
//         00402493     MOV        this,ESI
//         00402495     CALL       RGE_Static_Object::more_room                     uchar more_room(RGE_Static_Object * this)
//         0040249a     CMP        AL,0x1
//         0040249c     JNZ        LAB_004024ad
//         0040249e     MOV        this,dword ptr [EDI + 0x8]
//         004024a1     MOV        this,dword ptr [ECX + this->field12_0xc]
//         004024a4     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004024a9     TEST       EAX,EAX
//         004024ab     JZ         LAB_004024df
//                               LAB_004024ad                                                 XREF[1]:     0040249c(j)
//         004024ad     MOV        EDX,dword ptr [EDI + 0x8]
//         004024b0     MOV        this,dword ptr [EDX + 0xc]
//         004024b3     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004024b8     CMP        EAX,0x1
//         004024bb     JZ         LAB_004024df
//                               LAB_004024bd                                                 XREF[1]:     00402491(j)
//         004024bd     MOV        this,ESI
//         004024bf     CALL       EBP
//         004024c1     CMP        AL,0xb
//         004024c3     JNZ        LAB_004025a4
//         004024c9     MOV        this,dword ptr [ESI + 0x184]
//         004024cf     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004024d4     MOV        this,dword ptr [EAX + 0x1c]
//         004024d7     TEST       this,this
//         004024d9     JNZ        LAB_004025a4
//                               LAB_004024df                                                 XREF[2]:     004024ab(j), 004024bb(j)
//                              act_entr.cpp:91 (8)
//         004024df     FLD        float ptr [EBX + 0x38]
//         004024e2     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:92 (12)
//         004024e7     FLD        float ptr [EBX + 0x3c]
//         004024ea     MOV        dword ptr [ESP + 0x1c],EAX
//         004024ee     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:94 (12)
//         004024f3     FLD        float ptr [ESI + 0x38]
//         004024f6     MOV        dword ptr [ESP + 0x20],EAX
//         004024fa     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:95 (12)
//         004024ff     FLD        float ptr [ESI + 0x3c]
//         00402502     MOV        dword ptr [ESP + 0x14],EAX
//         00402506     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:97 (40)
//         0040250b     PUSH       0x1
//         0040250d     PUSH       offset DAT_fffffff8
//         0040250f     LEA        this,[ESP + 0x2c]
//         00402513     PUSH       offset DAT_fffffff4
//         00402515     PUSH       this=>DAT_fffffff0
//         00402516     LEA        EDX,[ESP + 0x24]
//         0040251a     LEA        this,[ESP + 0x2c]
//         0040251e     MOV        dword ptr [ESP + 0x28],EAX
//         00402522     MOV        EAX,dword ptr [EBX]
//         00402524     PUSH       EDX
//         00402525     PUSH       this
//         00402526     MOV        this,EBX
//         00402528     CALL       dword ptr [EAX + 0x1b4]
//         0040252e     CMP        EAX,0x1
//         00402531     JNZ        LAB_00402577
//                              act_entr.cpp:102 (4)
//         00402533     FILD       dword ptr [ESP + 0x24]
//                              act_entr.cpp:105 (62)
//         00402537     PUSH       EAX
//         00402538     PUSH       offset DAT_fffffff8
//         0040253d     FST        float ptr [ESP + 0x48]
//         00402541     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         00402547     MOV        this,dword ptr [ESP + 0x48]
//         0040254b     FSTP       float ptr [EDI + 0x20]
//         0040254e     FILD       dword ptr [ESP + 0x30]
//         00402552     FST        float ptr [ESP + 0x44]
//         00402556     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         0040255c     MOV        EAX,dword ptr [ESP + 0x44]
//         00402560     FSTP       float ptr [EDI + 0x24]
//         00402563     MOV        EDX,dword ptr [ESI + 0x40]
//         00402566     PUSH       EDX=>DAT_fffffff4
//         00402567     MOV        EDX,dword ptr [ESP + 0x50]
//         0040256b     PUSH       EAX=>DAT_fffffff0
//         0040256c     PUSH       this
//         0040256d     MOV        this,ESI
//         0040256f     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:107 (2)
//         00402575     JMP        LAB_004025d6
//                               LAB_00402577                                                 XREF[1]:     00402531(j)
//                              act_entr.cpp:112 (3)
//         00402577     MOV        EAX,dword ptr [ESI + 0x38]
//                              act_entr.cpp:115 (40)
//         0040257a     PUSH       0x1
//         0040257c     MOV        dword ptr [EDI + 0x20],EAX
//         0040257f     MOV        this,dword ptr [ESI + 0x3c]
//         00402582     MOV        dword ptr [EDI + 0x24],this
//         00402585     MOV        EDX,dword ptr [ESI + 0x40]
//         00402588     MOV        EAX,dword ptr [EBX + 0x3c]
//         0040258b     MOV        this,dword ptr [EBX + 0x38]
//         0040258e     PUSH       offset DAT_fffffff8
//         00402593     PUSH       EDX=>DAT_fffffff4
//         00402594     MOV        EDX,dword ptr [ESP + 0x50]
//         00402598     PUSH       EAX=>DAT_fffffff0
//         00402599     PUSH       this
//         0040259a     MOV        this,ESI
//         0040259c     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:119 (10)
//         004025a2     JMP        LAB_004025d6
//                               LAB_004025a4                                                 XREF[2]:     004024c3(j), 004024d9(j)
//         004025a4     MOV        this,ESI
//         004025a6     CALL       EBP
//         004025a8     CMP        AL,0xb
//         004025aa     JNZ        LAB_004025d6
//                              act_entr.cpp:121 (21)
//         004025ac     MOV        this,dword ptr [ESI + 0x184]
//         004025b2     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004025b7     MOV        this,EAX
//         004025b9     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         004025be     FSTP       float ptr [EDI + 0x20]
//                              act_entr.cpp:122 (21)
//         004025c1     MOV        this,dword ptr [ESI + 0x184]
//         004025c7     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004025cc     MOV        this,EAX
//         004025ce     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//         004025d3     FSTP       float ptr [EDI + 0x24]
//                               LAB_004025d6                                                 XREF[4]:     00402467(j), 00402575(j),
//                                                                                                         004025a2(j), 004025aa(j)
//                              act_entr.cpp:134 (23)
//         004025d6     MOV        this,dword ptr [ESP + local_c]
//         004025da     MOV        EAX,EDI
//         004025dc     POP        EDI
//         004025dd     POP        ESI
//         004025de     POP        EBP
//         004025df     MOV        dword ptr FS:[0x0],this
//         004025e6     POP        EBX
//         004025e7     ADD        ESP,0x28
//         004025ea     RET        0xc
//         004025ed     ??         90h
//         004025ee     NOP
//         004025ef     NOP
}

RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Enter(RGE_Action_Enter * this, RGE_A
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00402429(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00402442(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[2]:     0040243e(R), 00402483(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00402449(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004025d6(R)
//              XYPoint           Stack[-0x18]:8 rVal
//              XYPoint           Stack[-0x20]:8 start
//              XYPoint           Stack[-0x28]:8 dest                      XREF[1]:     00402435(W)
//                               ??0RGE_Action_Enter@@QAE@PAVRGE_Action_Object@@PAVRGE_Task@  XREF[2]:     enter:00431206(c),
//                               RGE_Action_Enter::RGE_Action_Enter                                        create_task_action:004d0b00(c)
//                              act_entr.cpp:61 (46)
//         00402410     PUSH       -0x1
//         00402412     PUSH       FUN_0055c138
//         00402417     MOV        EAX,FS:[0x0]
//         0040241d     PUSH       EAX
//         0040241e     MOV        dword ptr FS:[0x0],ESP
//         00402425     SUB        ESP,0x1c
//         00402428     PUSH       EBX
//         00402429     MOV        EBX,dword ptr [ESP + param_1]
//         0040242d     PUSH       EBP
//         0040242e     PUSH       ESI
//         0040242f     PUSH       EDI
//         00402430     MOV        EDI,this
//         00402432     PUSH       0x1
//         00402434     PUSH       EBX
//         00402435     MOV        dword ptr [ESP + dest.x],EDI
//         00402439     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              act_entr.cpp:64 (39)
//         0040243e     MOV        ESI,dword ptr [ESP + param_3]
//         00402442     MOV        EAX,dword ptr [ESP + param_2]
//         00402446     PUSH       ESI
//         00402447     MOV        this,EDI
//         00402449     MOV        dword ptr [ESP + local_4],0x0
//         00402451     MOV        dword ptr [EDI],RGE_Action_Enter::`vftable'      = 004023f0
//         00402457     MOV        word ptr [EDI + 0x4],0x3
//         0040245d     MOV        dword ptr [EDI + 0x30],EAX
//         00402460     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              act_entr.cpp:70 (8)
//         00402465     TEST       ESI,ESI
//         00402467     JZ         LAB_004025d6
//                              act_entr.cpp:72 (6)
//         0040246d     MOV        this,dword ptr [ESI + 0x38]
//         00402470     MOV        dword ptr [EDI + 0x20],this
//                              act_entr.cpp:73 (6)
//         00402473     MOV        EDX,dword ptr [ESI + 0x3c]
//         00402476     MOV        dword ptr [EDI + 0x24],EDX
//                              act_entr.cpp:74 (6)
//         00402479     MOV        EAX,dword ptr [ESI + 0x40]
//         0040247c     MOV        dword ptr [EDI + 0x28],EAX
//                              act_entr.cpp:84 (96)
//         0040247f     MOV        EAX,dword ptr [ESI]
//         00402481     MOV        this,ESI
//         00402483     MOV        dword ptr [ESP + param_3],EAX
//         00402487     MOV        EBP,dword ptr [EAX + 0x134]
//         0040248d     CALL       EBP
//         0040248f     CMP        AL,0x2
//         00402491     JNZ        LAB_004024bd
//         00402493     MOV        this,ESI
//         00402495     CALL       RGE_Static_Object::more_room                     uchar more_room(RGE_Static_Object * this)
//         0040249a     CMP        AL,0x1
//         0040249c     JNZ        LAB_004024ad
//         0040249e     MOV        this,dword ptr [EDI + 0x8]
//         004024a1     MOV        this,dword ptr [ECX + this->field12_0xc]
//         004024a4     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004024a9     TEST       EAX,EAX
//         004024ab     JZ         LAB_004024df
//                               LAB_004024ad                                                 XREF[1]:     0040249c(j)
//         004024ad     MOV        EDX,dword ptr [EDI + 0x8]
//         004024b0     MOV        this,dword ptr [EDX + 0xc]
//         004024b3     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004024b8     CMP        EAX,0x1
//         004024bb     JZ         LAB_004024df
//                               LAB_004024bd                                                 XREF[1]:     00402491(j)
//         004024bd     MOV        this,ESI
//         004024bf     CALL       EBP
//         004024c1     CMP        AL,0xb
//         004024c3     JNZ        LAB_004025a4
//         004024c9     MOV        this,dword ptr [ESI + 0x184]
//         004024cf     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004024d4     MOV        this,dword ptr [EAX + 0x1c]
//         004024d7     TEST       this,this
//         004024d9     JNZ        LAB_004025a4
//                               LAB_004024df                                                 XREF[2]:     004024ab(j), 004024bb(j)
//                              act_entr.cpp:91 (8)
//         004024df     FLD        float ptr [EBX + 0x38]
//         004024e2     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:92 (12)
//         004024e7     FLD        float ptr [EBX + 0x3c]
//         004024ea     MOV        dword ptr [ESP + 0x1c],EAX
//         004024ee     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:94 (12)
//         004024f3     FLD        float ptr [ESI + 0x38]
//         004024f6     MOV        dword ptr [ESP + 0x20],EAX
//         004024fa     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:95 (12)
//         004024ff     FLD        float ptr [ESI + 0x3c]
//         00402502     MOV        dword ptr [ESP + 0x14],EAX
//         00402506     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:97 (40)
//         0040250b     PUSH       0x1
//         0040250d     PUSH       offset DAT_fffffff8
//         0040250f     LEA        this,[ESP + 0x2c]
//         00402513     PUSH       offset DAT_fffffff4
//         00402515     PUSH       this=>DAT_fffffff0
//         00402516     LEA        EDX,[ESP + 0x24]
//         0040251a     LEA        this,[ESP + 0x2c]
//         0040251e     MOV        dword ptr [ESP + 0x28],EAX
//         00402522     MOV        EAX,dword ptr [EBX]
//         00402524     PUSH       EDX
//         00402525     PUSH       this
//         00402526     MOV        this,EBX
//         00402528     CALL       dword ptr [EAX + 0x1b4]
//         0040252e     CMP        EAX,0x1
//         00402531     JNZ        LAB_00402577
//                              act_entr.cpp:102 (4)
//         00402533     FILD       dword ptr [ESP + 0x24]
//                              act_entr.cpp:105 (62)
//         00402537     PUSH       EAX
//         00402538     PUSH       offset DAT_fffffff8
//         0040253d     FST        float ptr [ESP + 0x48]
//         00402541     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         00402547     MOV        this,dword ptr [ESP + 0x48]
//         0040254b     FSTP       float ptr [EDI + 0x20]
//         0040254e     FILD       dword ptr [ESP + 0x30]
//         00402552     FST        float ptr [ESP + 0x44]
//         00402556     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         0040255c     MOV        EAX,dword ptr [ESP + 0x44]
//         00402560     FSTP       float ptr [EDI + 0x24]
//         00402563     MOV        EDX,dword ptr [ESI + 0x40]
//         00402566     PUSH       EDX=>DAT_fffffff4
//         00402567     MOV        EDX,dword ptr [ESP + 0x50]
//         0040256b     PUSH       EAX=>DAT_fffffff0
//         0040256c     PUSH       this
//         0040256d     MOV        this,ESI
//         0040256f     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:107 (2)
//         00402575     JMP        LAB_004025d6
//                               LAB_00402577                                                 XREF[1]:     00402531(j)
//                              act_entr.cpp:112 (3)
//         00402577     MOV        EAX,dword ptr [ESI + 0x38]
//                              act_entr.cpp:115 (40)
//         0040257a     PUSH       0x1
//         0040257c     MOV        dword ptr [EDI + 0x20],EAX
//         0040257f     MOV        this,dword ptr [ESI + 0x3c]
//         00402582     MOV        dword ptr [EDI + 0x24],this
//         00402585     MOV        EDX,dword ptr [ESI + 0x40]
//         00402588     MOV        EAX,dword ptr [EBX + 0x3c]
//         0040258b     MOV        this,dword ptr [EBX + 0x38]
//         0040258e     PUSH       offset DAT_fffffff8
//         00402593     PUSH       EDX=>DAT_fffffff4
//         00402594     MOV        EDX,dword ptr [ESP + 0x50]
//         00402598     PUSH       EAX=>DAT_fffffff0
//         00402599     PUSH       this
//         0040259a     MOV        this,ESI
//         0040259c     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:119 (10)
//         004025a2     JMP        LAB_004025d6
//                               LAB_004025a4                                                 XREF[2]:     004024c3(j), 004024d9(j)
//         004025a4     MOV        this,ESI
//         004025a6     CALL       EBP
//         004025a8     CMP        AL,0xb
//         004025aa     JNZ        LAB_004025d6
//                              act_entr.cpp:121 (21)
//         004025ac     MOV        this,dword ptr [ESI + 0x184]
//         004025b2     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004025b7     MOV        this,EAX
//         004025b9     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         004025be     FSTP       float ptr [EDI + 0x20]
//                              act_entr.cpp:122 (21)
//         004025c1     MOV        this,dword ptr [ESI + 0x184]
//         004025c7     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004025cc     MOV        this,EAX
//         004025ce     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//         004025d3     FSTP       float ptr [EDI + 0x24]
//                               LAB_004025d6                                                 XREF[4]:     00402467(j), 00402575(j),
//                                                                                                         004025a2(j), 004025aa(j)
//                              act_entr.cpp:134 (23)
//         004025d6     MOV        this,dword ptr [ESP + local_c]
//         004025da     MOV        EAX,EDI
//         004025dc     POP        EDI
//         004025dd     POP        ESI
//         004025de     POP        EBP
//         004025df     MOV        dword ptr FS:[0x0],this
//         004025e6     POP        EBX
//         004025e7     ADD        ESP,0x28
//         004025ea     RET        0xc
//         004025ed     ??         90h
//         004025ee     NOP
//         004025ef     NOP
}

RGE_Action_Enter::~RGE_Action_Enter() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Action_Enter(RGE_Action_Enter * this)
//              void              <VOID>         <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//                               ??1RGE_Action_Enter@@UAE@XZ                                  XREF[1]:     `scalar_deleting_destructor':00402
//                               RGE_Action_Enter::~RGE_Action_Enter
//                              act_entr.cpp:140 (11)
//         004025f0     MOV        dword ptr [this->field0_0x0],RGE_Action_Enter:   = 004023f0
//         004025f6     JMP        RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         004025fb     ??         90h
//         004025fc     NOP
//         004025fd     NOP
//         004025fe     NOP
//         004025ff     NOP
}

void RGE_Action_Enter::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(RGE_Action_Enter * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?first_in_stack@RGE_Action_Enter@@UAEXE@Z                    XREF[1]:     0056e15c(*)
//                               RGE_Action_Enter::first_in_stack
//                              act_entr.cpp:150 (7)
//         00402600     MOV        EAX,dword ptr [this->field0_0x0]
//         00402602     PUSH       0x4
//         00402604     CALL       dword ptr [EAX + 0x5c]
//                              act_entr.cpp:152 (3)
//         00402607     RET        0x4
//         0040260a     ??         90h
//         0040260b     NOP
//         0040260c     NOP
//         0040260d     NOP
//         0040260e     NOP
//         0040260f     NOP
    return;
}

void RGE_Action_Enter::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(RGE_Action_Enter * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[2]:     00402631(R), 00402660(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00402666(W), 0040269a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004026d2(R), 004026fb(R)
//                               ?set_state@RGE_Action_Enter@@MAEXE@Z                         XREF[1]:     0056e19c(*)
//                               RGE_Action_Enter::set_state
//                              act_entr.cpp:158 (25)
//         00402610     MOV        EAX,FS:[0x0]
//         00402616     PUSH       -0x1
//         00402618     PUSH       FUN_0055c15b
//         0040261d     PUSH       EAX
//         0040261e     MOV        dword ptr FS:[0x0],ESP
//         00402625     PUSH       ESI
//         00402626     MOV        ESI,this
//         00402628     PUSH       EDI
//                              act_entr.cpp:167 (8)
//         00402629     MOV        this,dword ptr [ESI + 0x34]
//         0040262c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              act_entr.cpp:169 (7)
//         00402631     MOV        EAX,dword ptr [ESP + param_1]
//         00402635     MOV        byte ptr [ESI + 0xc],AL
//                              act_entr.cpp:171 (30)
//         00402638     AND        EAX,0xff
//         0040263d     DEC        EAX
//         0040263e     CMP        EAX,0xd
//         00402641     JA         switchD_0040264f::caseD_3
//         00402647     XOR        this,this
//         00402649     MOV        this,byte ptr [EAX + 0x402724]=>PTR_caseD_3_00
//                               switchD_0040264f::switchD
//         0040264f     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0040   = 004026ec
//                               switchD_0040264f::caseD_4                                    XREF[2]:     0040264f(j), 00402718(*)
//                              act_entr.cpp:176 (66)
//         00402656     PUSH       0x44
//         00402658     CALL       operator_new                                     void * operator_new(uint param_1)
//         0040265d     ADD        ESP,0x4
//         00402660     MOV        dword ptr [ESP + param_1],EAX
//         00402664     TEST       EAX,EAX
//         00402666     MOV        dword ptr [ESP + local_4],0x0
//         0040266e     JZ         LAB_00402696
//         00402670     MOV        EDX,dword ptr [ESI + 0x30]
//         00402673     MOV        this,dword ptr [EDX + 0x34]
//         00402676     MOV        EDX,dword ptr [EDX + 0x24]
//         00402679     PUSH       this
//         0040267a     MOV        this,dword ptr [ESI + 0x28]
//         0040267d     PUSH       EDX
//         0040267e     MOV        EDX,dword ptr [ESI + 0x24]
//         00402681     PUSH       this
//         00402682     MOV        this,dword ptr [ESI + 0x20]
//         00402685     PUSH       EDX
//         00402686     MOV        EDX,dword ptr [ESI + 0x8]
//         00402689     PUSH       this
//         0040268a     PUSH       EDX
//         0040268b     MOV        this,EAX
//         0040268d     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         00402692     MOV        EDI,EAX
//         00402694     JMP        LAB_00402698
//                               LAB_00402696                                                 XREF[1]:     0040266e(j)
//         00402696     XOR        EDI,EDI
//                               LAB_00402698                                                 XREF[1]:     00402694(j)
//                              act_entr.cpp:177 (12)
//         00402698     TEST       EDI,EDI
//         0040269a     MOV        dword ptr [ESP + local_4],0xffffffff
//         004026a2     JNZ        LAB_004026c0
//                              act_entr.cpp:179 (9)
//         004026a4     MOV        EAX,dword ptr [ESI]
//         004026a6     PUSH       0xd
//         004026a8     MOV        this,ESI
//         004026aa     CALL       dword ptr [EAX + 0x5c]
//                              act_entr.cpp:201 (19)
//         004026ad     MOV        this,dword ptr [ESP + 0x8]
//         004026b1     MOV        dword ptr FS:[0x0],this
//         004026b8     POP        EDI
//         004026b9     POP        ESI
//         004026ba     ADD        ESP,0xc
//         004026bd     RET        0x4
//                               LAB_004026c0                                                 XREF[1]:     004026a2(j)
//                              act_entr.cpp:182 (9)
//         004026c0     MOV        this,dword ptr [ESI + 0x34]
//         004026c3     PUSH       EDI
//         004026c4     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              act_entr.cpp:183 (9)
//         004026c9     PUSH       0x1
//         004026cb     MOV        this,EDI
//         004026cd     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              act_entr.cpp:201 (19)
//         004026d2     MOV        this,dword ptr [ESP + local_c]
//         004026d6     MOV        dword ptr FS:[0x0],this
//         004026dd     POP        EDI
//         004026de     POP        ESI
//         004026df     ADD        ESP,0xc
//         004026e2     RET        0x4
//                               switchD_0040264f::caseD_2                                    XREF[2]:     0040264f(j), 00402714(*)
//                              act_entr.cpp:188 (7)
//         004026e5     MOV        dword ptr [ESI + 0x2c],0x3f800000
//                               switchD_0040264f::caseD_d                                    XREF[3]:     0040264f(j), 00402710(*),
//                               switchD_0040264f::caseD_e                                                 0040271c(*)
//                               switchD_0040264f::caseD_1
//                              act_entr.cpp:198 (15)
//         004026ec     MOV        this,dword ptr [ESI + 0x8]
//         004026ef     MOV        EAX,dword ptr [ECX + this->field8_0x8]
//         004026f2     MOV        EDX,dword ptr [this->field0_0x0]
//         004026f4     MOV        EAX,dword ptr [EAX + 0x18]
//         004026f7     PUSH       EAX
//         004026f8     CALL       dword ptr [EDX + 0x38]
//                               switchD_0040264f::caseD_5                                    XREF[3]:     00402641(j), 0040264f(j),
//                               switchD_0040264f::caseD_6                                                 00402720(*)
//                               switchD_0040264f::caseD_7
//                               switchD_0040264f::caseD_8
//                               switchD_0040264f::caseD_9
//                               switchD_0040264f::caseD_a
//                               switchD_0040264f::caseD_b
//                               switchD_0040264f::caseD_c
//                               switchD_0040264f::caseD_3
//                              act_entr.cpp:201 (55)
//         004026fb     MOV        this,dword ptr [ESP + local_c]
//         004026ff     POP        EDI
//         00402700     MOV        dword ptr FS:[0x0],this
//         00402707     POP        ESI
//         00402708     ADD        ESP,0xc
//         0040270b     RET        0x4
    return;
}

uchar RGE_Action_Enter::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Action_Enter * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action_Ent    ECX:4 (auto)   this
//              XYPoint           Stack[-0xc]:8  rVal
//              XYPoint           Stack[-0x14]:8 start
//              XYPoint           Stack[-0x1c]:8 dest
//                               ?update@RGE_Action_Enter@@UAEEXZ                             XREF[1]:     0056e168(*)
//                               RGE_Action_Enter::update
//                              act_entr.cpp:207 (8)
//         00402740     SUB        ESP,0x24
//         00402743     PUSH       EBX
//         00402744     PUSH       ESI
//         00402745     MOV        ESI,this
//         00402747     PUSH       EDI
//                              act_entr.cpp:229 (25)
//         00402748     MOV        EAX,dword ptr [ESI + 0x18]
//         0040274b     CMP        EAX,-0x1
//         0040274e     JZ         LAB_00402763
//         00402750     PUSH       EAX
//         00402751     MOV        EAX,dword ptr [ESI + 0x8]
//         00402754     MOV        this,dword ptr [EAX + 0xc]
//         00402757     MOV        this,dword ptr [ECX + this->field60_0x3c]
//         0040275a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0040275f     TEST       EAX,EAX
//                              act_entr.cpp:237 (2)
//         00402761     JZ         LAB_004027ae
//                               LAB_00402763                                                 XREF[1]:     0040274e(j)
//                              act_entr.cpp:240 (27)
//         00402763     MOV        EAX,dword ptr [ESI + 0x1c]
//         00402766     CMP        EAX,-0x1
//         00402769     JZ         LAB_00402786
//         0040276b     PUSH       EAX
//         0040276c     MOV        EAX,dword ptr [ESI + 0x8]
//         0040276f     MOV        this,dword ptr [EAX + 0xc]
//         00402772     MOV        this,dword ptr [ECX + this->field60_0x3c]
//         00402775     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0040277a     TEST       EAX,EAX
//         0040277c     JNZ        LAB_00402786
//                              act_entr.cpp:245 (8)
//         0040277e     MOV        EDX,dword ptr [ESI]
//         00402780     PUSH       EAX
//         00402781     MOV        this,ESI
//         00402783     CALL       dword ptr [EDX + 0x58]
//                               LAB_00402786                                                 XREF[2]:     00402769(j), 0040277c(j)
//                              act_entr.cpp:248 (11)
//         00402786     MOV        EAX,dword ptr [ESI + 0x10]
//         00402789     TEST       EAX,EAX
//         0040278b     JZ         LAB_004027e5
//         0040278d     CMP        byte ptr [EAX + 0x48],0x3
//                              act_entr.cpp:253 (2)
//         00402791     JNC        LAB_004027ae
//                              act_entr.cpp:257 (27)
//         00402793     TEST       EAX,EAX
//         00402795     JZ         LAB_004027e5
//         00402797     MOV        this,dword ptr [ESI + 0x8]
//         0040279a     MOV        EAX,dword ptr [EAX + 0xc]
//         0040279d     MOV        this,dword ptr [ECX + this->field12_0xc]
//         004027a0     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004027a4     MOV        EDX,dword ptr [this->field0_0x0]
//         004027a6     PUSH       EAX
//         004027a7     CALL       dword ptr [EDX + 0x1c]
//         004027aa     TEST       EAX,EAX
//         004027ac     JNZ        LAB_004027e5
//                               LAB_004027ae                                                 XREF[2]:     00402761(j), 00402791(j)
//                              act_entr.cpp:259 (9)
//         004027ae     MOV        EDI,dword ptr [ESI]
//         004027b0     PUSH       0x1
//         004027b2     MOV        this,ESI
//         004027b4     CALL       dword ptr [EDI + 0x5c]
//                              act_entr.cpp:260 (7)
//         004027b7     PUSH       0x0
//         004027b9     MOV        this,ESI
//         004027bb     CALL       dword ptr [EDI + 0x54]
//                              act_entr.cpp:261 (30)
//         004027be     MOV        this,dword ptr [ESI + 0x8]
//         004027c1     PUSH       0x0
//         004027c3     PUSH       0x0
//         004027c5     PUSH       0x269
//         004027ca     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004027cd     MOV        EDX,dword ptr [this->field0_0x0]
//         004027cf     PUSH       0x1fb
//         004027d4     PUSH       EAX
//         004027d5     PUSH       EAX
//         004027d6     CALL       dword ptr [EDX + 0x148]
//                              act_entr.cpp:262 (2)
//         004027dc     MOV        AL,0x4
//                              act_entr.cpp:415 (7)
//         004027de     POP        EDI
//         004027df     POP        ESI
//         004027e0     POP        EBX
//         004027e1     ADD        ESP,0x24
//         004027e4     RET
//                               LAB_004027e5                                                 XREF[3]:     0040278b(j), 00402795(j),
//                                                                                                         004027ac(j)
//                              act_entr.cpp:265 (30)
//         004027e5     XOR        EAX,EAX
//         004027e7     MOV        AL,byte ptr [ESI + 0xc]
//         004027ea     DEC        EAX
//         004027eb     CMP        EAX,0xc
//         004027ee     JA         switchD_004027fc::caseD_3
//         004027f4     XOR        this,this
//         004027f6     MOV        this,byte ptr [EAX + 0x402b10]=>PTR_caseD_3_00
//                               switchD_004027fc::switchD
//         004027fc     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0040   = 00402ac1
//                               switchD_004027fc::caseD_4                                    XREF[2]:     004027fc(j), 00402b04(*)
//                              act_entr.cpp:270 (16)
//         00402803     MOV        this,dword ptr [ESI + 0x10]
//         00402806     TEST       this,this
//         00402808     JZ         switchD_0040282a::caseD_3
//         0040280a     CALL       RGE_Static_Object::is_dying                      uchar is_dying(RGE_Static_Object * this)
//         0040280f     TEST       AL,AL
//         00402811     JNZ        switchD_0040282a::caseD_3
//                              act_entr.cpp:277 (30)
//         00402813     MOV        this,dword ptr [ESI + 0x34]
//         00402816     MOV        EDX,dword ptr [this->field0_0x0]
//         00402818     CALL       dword ptr [EDX + 0xc]
//         0040281b     AND        EAX,0xff
//         00402820     DEC        EAX
//         00402821     CMP        EAX,0x4
//         00402824     JA         switchD_004027fc::caseD_3
//                               switchD_0040282a::switchD
//         0040282a     JMP        dword ptr [EAX*0x4 + switchD_0040282a::switchd   = 00402843
//                               switchD_0040282a::caseD_2                                    XREF[2]:     0040282a(j), 00402b28(*)
//                              act_entr.cpp:295 (9)
//         00402831     MOV        EAX,dword ptr [ESI]
//         00402833     PUSH       0x2
//         00402835     MOV        this,ESI
//         00402837     CALL       dword ptr [EAX + 0x5c]
//                              act_entr.cpp:414 (2)
//         0040283a     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         0040283c     POP        EDI
//         0040283d     POP        ESI
//         0040283e     POP        EBX
//         0040283f     ADD        ESP,0x24
//         00402842     RET
//                               switchD_0040282a::caseD_1                                    XREF[3]:     0040282a(j), 00402b20(*),
//                               switchD_0040282a::caseD_0                                                 00402b24(*)
//                              act_entr.cpp:300 (18)
//         00402843     MOV        this,dword ptr [ESI + 0x10]
//         00402846     PUSH       this
//         00402847     MOV        this,dword ptr [ESI + 0x8]
//         0040284a     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//         0040284f     FSUB       float ptr [DAT_0056e1a4]
//                              act_entr.cpp:301 (13)
//         00402855     MOV        EDX,dword ptr [ESI + 0x30]
//         00402858     FCOMP      float ptr [EDX + 0x24]
//         0040285b     FNSTSW     AX
//         0040285d     TEST       AH,0x41
//         00402860     JZ         LAB_00402873
//                              act_entr.cpp:305 (15)
//         00402862     MOV        this,dword ptr [ESI + 0x8]
//         00402865     MOV        EDX,dword ptr [ESI + 0x10]
//         00402868     PUSH       EDX
//         00402869     MOV        EAX,dword ptr [this->field0_0x0]
//         0040286b     CALL       dword ptr [EAX + 0xd0]
//                              act_entr.cpp:310 (2)
//         00402871     JMP        LAB_004028ef
//                               LAB_00402873                                                 XREF[1]:     00402860(j)
//                              act_entr.cpp:316 (9)
//         00402873     MOV        EDX,dword ptr [ESI]
//         00402875     PUSH       0x2
//         00402877     MOV        this,ESI
//         00402879     CALL       dword ptr [EDX + 0x5c]
//                              act_entr.cpp:414 (2)
//         0040287c     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         0040287e     POP        EDI
//         0040287f     POP        ESI
//         00402880     POP        EBX
//         00402881     ADD        ESP,0x24
//         00402884     RET
//                               switchD_0040282a::caseD_4                                    XREF[5]:     00402808(j), 00402811(j),
//                               switchD_0040282a::caseD_3                                                 0040282a(j), 00402b2c(*),
//                                                                                                         00402b30(*)
//                              act_entr.cpp:272 (9)
//         00402885     MOV        EDI,dword ptr [ESI]
//         00402887     PUSH       0x0
//         00402889     MOV        this,ESI
//         0040288b     CALL       dword ptr [EDI + 0x54]
//                              act_entr.cpp:273 (7)
//         0040288e     PUSH       0xd
//         00402890     MOV        this,ESI
//         00402892     CALL       dword ptr [EDI + 0x5c]
//                              act_entr.cpp:414 (2)
//         00402895     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         00402897     POP        EDI
//         00402898     POP        ESI
//         00402899     POP        EBX
//         0040289a     ADD        ESP,0x24
//         0040289d     RET
//                               switchD_004027fc::caseD_2                                    XREF[2]:     004027fc(j), 00402b00(*)
//                              act_entr.cpp:323 (21)
//         0040289e     MOV        this,dword ptr [ESI + 0x8]
//         004028a1     FLD        float ptr [ESI + 0x2c]
//         004028a4     MOV        EAX,dword ptr [ECX + this->field12_0xc]
//         004028a7     MOV        EDX,dword ptr [EAX + 0x3c]
//         004028aa     FSUB       float ptr [EDX + 0x84]
//         004028b0     FST        float ptr [ESI + 0x2c]
//                              act_entr.cpp:324 (17)
//         004028b3     FCOMP      float ptr [DAT_0056e1a8]
//         004028b9     FNSTSW     AX
//         004028bb     TEST       AH,0x41
//         004028be     JZ         switchD_004027fc::caseD_3
//                              act_entr.cpp:325 (15)
//         004028c4     MOV        EAX,dword ptr [ESI + 0x10]
//         004028c7     PUSH       EAX
//         004028c8     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//         004028cd     FSUB       float ptr [DAT_0056e1a4]
//                              act_entr.cpp:326 (13)
//         004028d3     MOV        this,dword ptr [ESI + 0x30]
//         004028d6     FCOMP      float ptr [ECX + this->field36_0x24]
//         004028d9     FNSTSW     AX
//         004028db     TEST       AH,0x41
//         004028de     JZ         LAB_00402926
//                              act_entr.cpp:330 (15)
//         004028e0     MOV        this,dword ptr [ESI + 0x8]
//         004028e3     MOV        EAX,dword ptr [ESI + 0x10]
//         004028e6     PUSH       EAX
//         004028e7     MOV        EDX,dword ptr [this->field0_0x0]
//         004028e9     CALL       dword ptr [EDX + 0xd0]
//                               LAB_004028ef                                                 XREF[1]:     00402871(j)
//                              act_entr.cpp:331 (7)
//         004028ef     MOV        AL,byte ptr [ESI + 0x3c]
//         004028f2     TEST       AL,AL
//         004028f4     JNZ        LAB_00402914
//                              act_entr.cpp:333 (30)
//         004028f6     MOV        this,dword ptr [ESI + 0x8]
//         004028f9     PUSH       0x0
//         004028fb     PUSH       0x0
//         004028fd     PUSH       0x269
//         00402902     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         00402905     MOV        EDX,dword ptr [this->field0_0x0]
//         00402907     PUSH       0x1fa
//         0040290c     PUSH       EAX
//         0040290d     PUSH       EAX
//         0040290e     CALL       dword ptr [EDX + 0x148]
//                               LAB_00402914                                                 XREF[1]:     004028f4(j)
//                              act_entr.cpp:334 (9)
//         00402914     MOV        EAX,dword ptr [ESI]
//         00402916     PUSH       0x1
//         00402918     MOV        this,ESI
//         0040291a     CALL       dword ptr [EAX + 0x5c]
//                              act_entr.cpp:335 (2)
//         0040291d     MOV        AL,0x2
//                              act_entr.cpp:415 (7)
//         0040291f     POP        EDI
//         00402920     POP        ESI
//         00402921     POP        EBX
//         00402922     ADD        ESP,0x24
//         00402925     RET
//                               LAB_00402926                                                 XREF[1]:     004028de(j)
//                              act_entr.cpp:341 (19)
//         00402926     MOV        this,dword ptr [ESI + 0x10]
//         00402929     MOV        EDX,dword ptr [this->field0_0x0]
//         0040292b     CALL       dword ptr [EDX + 0x134]
//         00402931     CMP        AL,0x2
//         00402933     JNZ        LAB_00402a70
//                              act_entr.cpp:348 (15)
//         00402939     MOV        EDI,dword ptr [ESI + 0x8]
//         0040293c     FLD        float ptr [EDI + 0x38]
//         0040293f     CALL       __ftol                                           undefined __ftol()
//         00402944     MOV        dword ptr [ESP + 0x20],EAX
//                              act_entr.cpp:349 (8)
//         00402948     FLD        float ptr [EDI + 0x3c]
//         0040294b     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:351 (19)
//         00402950     MOV        EBX,dword ptr [ESI + 0x10]
//         00402953     MOV        dword ptr [ESP + 0x24],EAX
//         00402957     FLD        float ptr [EBX + 0x38]
//         0040295a     CALL       __ftol                                           undefined __ftol()
//         0040295f     MOV        dword ptr [ESP + 0x18],EAX
//                              act_entr.cpp:352 (8)
//         00402963     FLD        float ptr [EBX + 0x3c]
//         00402966     CALL       __ftol                                           undefined __ftol()
//                              act_entr.cpp:354 (44)
//         0040296b     PUSH       0x1
//         0040296d     PUSH       0x2
//         0040296f     LEA        this,[ESP + 0x30]
//         00402973     PUSH       0x2
//         00402975     PUSH       this
//         00402976     LEA        EDX,[ESP + 0x28]
//         0040297a     LEA        this,[ESP + 0x30]
//         0040297e     MOV        dword ptr [ESP + 0x2c],EAX
//         00402982     MOV        EAX,dword ptr [EDI]
//         00402984     PUSH       EDX
//         00402985     PUSH       this
//         00402986     MOV        this,EDI
//         00402988     CALL       dword ptr [EAX + 0x1b4]
//         0040298e     CMP        EAX,0x1
//         00402991     JNZ        LAB_00402a31
//                              act_entr.cpp:361 (21)
//         00402997     FILD       dword ptr [ESP + 0x2c]
//         0040299b     FILD       dword ptr [ESP + 0x28]
//         0040299f     FST        float ptr [ESP + 0x14]
//         004029a3     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         004029a9     FLD        float ptr [ESI + 0x20]
//                              act_entr.cpp:414 (67)
//         004029ac     FXCH       ST2
//         004029ae     FST        float ptr [ESP + 0x10]
//         004029b2     FSUB       float ptr [DAT_0056e1a0]                         = align(3)
//         004029b8     FXCH       ST2
//         004029ba     FCOMP
//         004029bc     FXCH
//         004029be     FST        float ptr [ESP + 0xc]
//         004029c2     FNSTSW     AX
//         004029c4     TEST       AH,0x40
//         004029c7     JZ         LAB_004029f6
//         004029c9     FCOMP      float ptr [ESI + 0x24]
//         004029cc     FNSTSW     AX
//         004029ce     TEST       AH,0x40
//         004029d1     JZ         LAB_004029f8
//         004029d3     MOV        EAX,dword ptr [ESI + 0x10]
//         004029d6     PUSH       0x4
//         004029d8     MOV        this,ESI
//         004029da     MOV        EDX,dword ptr [EAX + 0x38]
//         004029dd     MOV        dword ptr [ESI + 0x20],EDX
//         004029e0     MOV        EAX,dword ptr [EAX + 0x3c]
//         004029e3     MOV        EDX,dword ptr [ESI]
//         004029e5     MOV        dword ptr [ESI + 0x24],EAX
//         004029e8     FSTP       ST0
//         004029ea     CALL       dword ptr [EDX + 0x5c]
//         004029ed     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         004029ef     POP        EDI
//         004029f0     POP        ESI
//         004029f1     POP        EBX
//         004029f2     ADD        ESP,0x24
//         004029f5     RET
//                               LAB_004029f6                                                 XREF[1]:     004029c7(j)
//                              act_entr.cpp:361 (2)
//         004029f6     FSTP       ST0
//                               LAB_004029f8                                                 XREF[1]:     004029d1(j)
//                              act_entr.cpp:372 (4)
//         004029f8     MOV        this,dword ptr [ESP + 0xc]
//                              act_entr.cpp:374 (35)
//         004029fc     PUSH       0x1
//         004029fe     FSTP       float ptr [ESI + 0x20]
//         00402a01     MOV        dword ptr [ESI + 0x24],this
//         00402a04     MOV        this,dword ptr [ESI + 0x10]
//         00402a07     PUSH       0x0
//         00402a09     MOV        EAX,dword ptr [ECX + this+0x40]
//         00402a0c     MOV        EDX,dword ptr [this->field0_0x0]
//         00402a0e     PUSH       EAX
//         00402a0f     MOV        EAX,dword ptr [ESP + 0x1c]
//         00402a13     PUSH       EAX
//         00402a14     MOV        EAX,dword ptr [ESP + 0x24]
//         00402a18     PUSH       EAX
//         00402a19     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:398 (9)
//         00402a1f     MOV        EDX,dword ptr [ESI]
//         00402a21     PUSH       0x4
//         00402a23     MOV        this,ESI
//         00402a25     CALL       dword ptr [EDX + 0x5c]
//                              act_entr.cpp:414 (2)
//         00402a28     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         00402a2a     POP        EDI
//         00402a2b     POP        ESI
//         00402a2c     POP        EBX
//         00402a2d     ADD        ESP,0x24
//         00402a30     RET
//                               LAB_00402a31                                                 XREF[1]:     00402991(j)
//                              act_entr.cpp:382 (3)
//         00402a31     MOV        this,dword ptr [ESI + 0x10]
//                              act_entr.cpp:385 (42)
//         00402a34     PUSH       0x1
//         00402a36     PUSH       0x3f000000
//         00402a3b     MOV        EDX,dword ptr [ECX + this->field56_0x38]
//         00402a3e     MOV        dword ptr [ESI + 0x20],EDX
//         00402a41     MOV        EAX,dword ptr [ECX + this->field60_0x3c]
//         00402a44     MOV        EDX,dword ptr [this->field0_0x0]
//         00402a46     MOV        dword ptr [ESI + 0x24],EAX
//         00402a49     MOV        EAX,dword ptr [ESI + 0x8]
//         00402a4c     MOV        EDI,dword ptr [ECX + this+0x40]
//         00402a4f     PUSH       EDI
//         00402a50     MOV        EDI,dword ptr [EAX + 0x3c]
//         00402a53     MOV        EAX,dword ptr [EAX + 0x38]
//         00402a56     PUSH       EDI
//         00402a57     PUSH       EAX
//         00402a58     CALL       dword ptr [EDX + 0x154]
//                              act_entr.cpp:398 (9)
//         00402a5e     MOV        EDX,dword ptr [ESI]
//         00402a60     PUSH       0x4
//         00402a62     MOV        this,ESI
//         00402a64     CALL       dword ptr [EDX + 0x5c]
//                              act_entr.cpp:414 (2)
//         00402a67     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         00402a69     POP        EDI
//         00402a6a     POP        ESI
//         00402a6b     POP        EBX
//         00402a6c     ADD        ESP,0x24
//         00402a6f     RET
//                               LAB_00402a70                                                 XREF[1]:     00402933(j)
//                              act_entr.cpp:389 (15)
//         00402a70     MOV        this,dword ptr [ESI + 0x10]
//         00402a73     MOV        EDX,dword ptr [this->field0_0x0]
//         00402a75     CALL       dword ptr [EDX + 0x134]
//         00402a7b     CMP        AL,0xb
//         00402a7d     JNZ        LAB_00402aaf
//                              act_entr.cpp:391 (21)
//         00402a7f     MOV        EAX,dword ptr [ESI + 0x10]
//         00402a82     MOV        this,dword ptr [EAX + 0x184]
//         00402a88     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00402a8d     MOV        this,EAX
//         00402a8f     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//                              act_entr.cpp:392 (27)
//         00402a94     MOV        this,dword ptr [ESI + 0x10]
//         00402a97     FSTP       float ptr [ESI + 0x20]
//         00402a9a     MOV        this,dword ptr [this->field0_0x0 + 0x184]
//         00402aa0     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00402aa5     MOV        this,EAX
//         00402aa7     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//         00402aac     FSTP       float ptr [ESI + 0x24]
//                               LAB_00402aaf                                                 XREF[1]:     00402a7d(j)
//                              act_entr.cpp:398 (9)
//         00402aaf     MOV        EDX,dword ptr [ESI]
//         00402ab1     PUSH       0x4
//         00402ab3     MOV        this,ESI
//         00402ab5     CALL       dword ptr [EDX + 0x5c]
//                              act_entr.cpp:414 (2)
//         00402ab8     XOR        AL,AL
//                              act_entr.cpp:415 (7)
//         00402aba     POP        EDI
//         00402abb     POP        ESI
//         00402abc     POP        EBX
//         00402abd     ADD        ESP,0x24
//         00402ac0     RET
//                               switchD_004027fc::caseD_1                                    XREF[2]:     004027fc(j), 00402afc(*)
//                              act_entr.cpp:406 (2)
//         00402ac1     MOV        AL,0x1
//                              act_entr.cpp:415 (7)
//         00402ac3     POP        EDI
//         00402ac4     POP        ESI
//         00402ac5     POP        EBX
//         00402ac6     ADD        ESP,0x24
//         00402ac9     RET
//                               switchD_004027fc::caseD_d                                    XREF[2]:     004027fc(j), 00402b08(*)
//                              act_entr.cpp:410 (30)
//         00402aca     MOV        this,dword ptr [ESI + 0x8]
//         00402acd     PUSH       0x0
//         00402acf     PUSH       0x0
//         00402ad1     PUSH       0x269
//         00402ad6     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         00402ad9     MOV        EDX,dword ptr [this->field0_0x0]
//         00402adb     PUSH       0x1f9
//         00402ae0     PUSH       EAX
//         00402ae1     PUSH       EAX
//         00402ae2     CALL       dword ptr [EDX + 0x148]
//                              act_entr.cpp:411 (2)
//         00402ae8     MOV        AL,0x3
//                              act_entr.cpp:415 (74)
//         00402aea     POP        EDI
//         00402aeb     POP        ESI
//         00402aec     POP        EBX
//         00402aed     ADD        ESP,0x24
//         00402af0     RET
//                               switchD_004027fc::caseD_5                                    XREF[5]:     004027ee(j), 004027fc(j),
//                               switchD_004027fc::caseD_6                                                 00402824(j), 004028be(j),
//                               switchD_004027fc::caseD_7                                                 00402b0c(*)
//                               switchD_004027fc::caseD_8
//                               switchD_004027fc::caseD_9
//                               switchD_004027fc::caseD_a
//                               switchD_004027fc::caseD_b
//                               switchD_004027fc::caseD_c
//                               switchD_0040282a::default
//                               switchD_004027fc::caseD_3
//         00402af1     POP        EDI
//         00402af2     POP        ESI
//         00402af3     XOR        AL,AL
//         00402af5     POP        EBX
//         00402af6     ADD        ESP,0x24
//         00402af9     RET
    return 0;
}

