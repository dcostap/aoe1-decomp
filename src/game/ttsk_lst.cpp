#include "../common.h"
#include "ttsk_lst.h"

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              RGE_Task * __thiscall get_target_task(TRIBE_Task_List * this, RGE_Ac
//              RGE_Task *        EAX:4          <RETURN>
//              TRIBE_Task_Lis    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[3]:     0052c3f1(R), 0052c504(R), 0052c74e(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0052c3fc(R)
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//              float             Stack[0x14]:4  param_5
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0052c405(W), 0052c4bf(R), 0052c52f(R), 0052c5b1(R)
//                               ?get_target_task@TRIBE_Task_List@@UAEPAVRGE_Task@@PAVRGE_Ac  XREF[1]:     00576784(*)
//                               TRIBE_Task_List::get_target_task
//                              ttsk_lst.cpp:41 (1)
//         0052c3f0     PUSH       this
//                              ttsk_lst.cpp:49 (91)
//         0052c3f1     MOV        EDX,dword ptr [ESP + param_1]
//         0052c3f5     PUSH       EBX
//         0052c3f6     PUSH       EBP
//         0052c3f7     PUSH       ESI
//         0052c3f8     MOV        BP,word ptr [EDX + 0x4c]
//         0052c3fc     MOV        ESI,dword ptr [ESP + param_2]
//         0052c400     CMP        BP,-0x1
//         0052c404     PUSH       EDI
//         0052c405     MOV        dword ptr [ESP + local_4],this
//         0052c409     JZ         LAB_0052c508
//         0052c40f     FLD        float ptr [EDX + 0x44]
//         0052c412     FCOMP      float ptr [DAT_0057733c]
//         0052c418     FNSTSW     AX
//         0052c41a     TEST       AH,0x41
//         0052c41d     JNZ        LAB_0052c508
//         0052c423     TEST       ESI,ESI
//         0052c425     JZ         LAB_0052c508
//         0052c42b     CMP        byte ptr [ESI + 0x48],0x2
//         0052c42f     JNZ        LAB_0052c508
//         0052c435     MOV        EAX,dword ptr [EDX + 0x8]
//         0052c438     MOV        AX,word ptr [EAX + 0x14]
//         0052c43c     CMP        AX,0x4
//         0052c440     JZ         LAB_0052c44c
//         0052c442     CMP        AX,0x15
//         0052c446     JNZ        LAB_0052c508
//                               LAB_0052c44c                                                 XREF[1]:     0052c440(j)
//                              ttsk_lst.cpp:51 (3)
//         0052c44c     OR         this,0xffffffff
//                              ttsk_lst.cpp:52 (3)
//         0052c44f     OR         EDI,0xffffffff
//                              ttsk_lst.cpp:54 (6)
//         0052c452     CMP        AX,0x4
//         0052c456     JNZ        LAB_0052c488
//                              ttsk_lst.cpp:56 (24)
//         0052c458     MOVSX      EAX,BP
//         0052c45b     DEC        EAX
//         0052c45c     CMP        EAX,0x10
//         0052c45f     JA         switchD_0052c469::caseD_4
//         0052c461     XOR        EBX,EBX
//         0052c463     MOV        BL,byte ptr [EAX + 0x52c8b8]=>PTR_caseD_4_0052
//                               switchD_0052c469::switchD
//         0052c469     JMP        dword ptr [EBX*0x4 + switchD_0052c469::switchd   = 0052c470
//                               switchD_0052c469::caseD_2                                    XREF[4]:     0052c469(j), 0052c8a4(*),
//                               switchD_0052c469::caseD_3                                                 0052c8a8(*), 0052c8b0(*)
//                               switchD_0052c469::caseD_f
//                               switchD_0052c469::caseD_11
//                               switchD_0052c469::caseD_1
//                              ttsk_lst.cpp:63 (5)
//         0052c470     MOV        this,0x6d
//                              ttsk_lst.cpp:64 (5)
//         0052c475     MOV        EDI,0x67
//                              ttsk_lst.cpp:65 (2)
//         0052c47a     JMP        switchD_0052c469::caseD_4
//                               switchD_0052c469::caseD_10                                   XREF[2]:     0052c469(j), 0052c8ac(*)
//                              ttsk_lst.cpp:68 (5)
//         0052c47c     MOV        this,0x6d
//                              ttsk_lst.cpp:69 (5)
//         0052c481     MOV        EDI,0x44
//                              ttsk_lst.cpp:73 (8)
//         0052c486     JMP        switchD_0052c469::caseD_4
//                               LAB_0052c488                                                 XREF[1]:     0052c456(j)
//         0052c488     CMP        AX,0x15
//         0052c48c     JNZ        switchD_0052c469::caseD_4
//                              ttsk_lst.cpp:75 (13)
//         0052c48e     MOVSX      EAX,BP
//         0052c491     CMP        EAX,0x9
//         0052c494     JZ         LAB_0052c49b
//         0052c496     CMP        EAX,0x11
//         0052c499     JNZ        switchD_0052c469::caseD_4
//                               LAB_0052c49b                                                 XREF[1]:     0052c494(j)
//                              ttsk_lst.cpp:79 (5)
//         0052c49b     MOV        this,0x2d
//                               switchD_0052c469::caseD_5                                    XREF[7]:     0052c45f(j), 0052c469(j),
//                               switchD_0052c469::caseD_6                                                 0052c47a(j), 0052c486(j),
//                               switchD_0052c469::caseD_7                                                 0052c48c(j), 0052c499(j),
//                               switchD_0052c469::caseD_8                                                 0052c8b4(*)
//                               switchD_0052c469::caseD_9
//                               switchD_0052c469::caseD_a
//                               switchD_0052c469::caseD_b
//                               switchD_0052c469::caseD_c
//                               switchD_0052c469::caseD_d
//                               switchD_0052c469::caseD_e
//                               switchD_0052c469::caseD_4
//                              ttsk_lst.cpp:85 (31)
//         0052c4a0     MOV        EAX,dword ptr [ESI + 0x8]
//         0052c4a3     MOVSX      EAX,word ptr [EAX + 0x10]
//         0052c4a7     CMP        EAX,this
//         0052c4a9     JZ         LAB_0052c4af
//         0052c4ab     CMP        EAX,EDI
//         0052c4ad     JNZ        LAB_0052c508
//                               LAB_0052c4af                                                 XREF[1]:     0052c4a9(j)
//         0052c4af     MOV        this,dword ptr [ESI + 0xc]
//         0052c4b2     MOV        EAX,dword ptr [EDX + 0xc]
//         0052c4b5     MOV        this,word ptr [this->field0_0x0 + 0x4a]
//         0052c4b9     CMP        this,word ptr [EAX + 0x4a]
//         0052c4bd     JNZ        LAB_0052c508
//                              ttsk_lst.cpp:87 (14)
//         0052c4bf     MOV        EAX,dword ptr [ESP + local_4]
//         0052c4c3     XOR        EDI,EDI
//         0052c4c5     MOVSX      EBX,word ptr [EAX + 0x8]
//         0052c4c9     TEST       EBX,EBX
//         0052c4cb     JLE        LAB_0052c508
//                              ttsk_lst.cpp:294 (27)
//         0052c4cd     MOV        this,EAX
//         0052c4cf     MOV        EDX,dword ptr [ECX + this->field4_0x4]
//                               LAB_0052c4d2                                                 XREF[1]:     0052c502(j)
//         0052c4d2     MOV        EAX,dword ptr [EDX]
//         0052c4d4     CMP        word ptr [EAX + 0x14],BP
//         0052c4d8     JNZ        LAB_0052c4fc
//         0052c4da     MOV        this,word ptr [EAX + 0x6]
//         0052c4de     CMP        this,0x5
//         0052c4e2     JZ         LAB_0052c899
//                              ttsk_lst.cpp:90 (20)
//         0052c4e8     CMP        this,0x6e
//         0052c4ec     JZ         LAB_0052c899
//         0052c4f2     CMP        this,0x6f
//         0052c4f6     JZ         LAB_0052c899
//                               LAB_0052c4fc                                                 XREF[1]:     0052c4d8(j)
//                              ttsk_lst.cpp:87 (12)
//         0052c4fc     INC        EDI
//         0052c4fd     ADD        EDX,0x4
//         0052c500     CMP        EDI,EBX
//         0052c502     JL         LAB_0052c4d2
//         0052c504     MOV        EDX,dword ptr [ESP + param_1]
//                               LAB_0052c508                                                 XREF[8]:     0052c409(j), 0052c41d(j),
//                                                                                                         0052c425(j), 0052c42f(j),
//                                                                                                         0052c446(j), 0052c4ad(j),
//                                                                                                         0052c4bd(j), 0052c4cb(j)
//                              ttsk_lst.cpp:144 (39)
//         0052c508     TEST       ESI,ESI
//         0052c50a     MOV        BL,0x50
//         0052c50c     JZ         LAB_0052c74e
//         0052c512     TEST       EDX,EDX
//         0052c514     JZ         LAB_0052c567
//         0052c516     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c519     MOV        this,dword ptr [EDX + 0xc]
//         0052c51c     CMP        EAX,this
//         0052c51e     JNZ        LAB_0052c567
//         0052c520     MOV        this,dword ptr [ESI + 0x8]
//         0052c523     CMP        byte ptr [ECX + this->field4_0x4],BL
//         0052c526     JNZ        LAB_0052c567
//         0052c528     MOV        AL,byte ptr [ESI + 0x48]
//         0052c52b     TEST       AL,AL
//         0052c52d     JNZ        LAB_0052c567
//                              ttsk_lst.cpp:146 (18)
//         0052c52f     MOV        EAX,dword ptr [ESP + local_4]
//         0052c533     XOR        EDX,EDX
//         0052c535     MOVSX      ESI,word ptr [EAX + 0x8]
//         0052c539     TEST       ESI,ESI
//         0052c53b     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (28)
//         0052c541     MOV        this,dword ptr [EAX + 0x4]
//         0052c544     MOV        EDI,0x65
//                               LAB_0052c549                                                 XREF[1]:     0052c55b(j)
//         0052c549     MOV        EAX,dword ptr [this->field0_0x0]
//         0052c54b     CMP        word ptr [EAX + 0x6],DI
//         0052c54f     JZ         LAB_0052c899
//         0052c555     INC        EDX
//         0052c556     ADD        this,0x4
//         0052c559     CMP        EDX,ESI
//         0052c55b     JL         LAB_0052c549
//                              ttsk_lst.cpp:152 (2)
//         0052c55d     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c55f     POP        EDI
//         0052c560     POP        ESI
//         0052c561     POP        EBP
//         0052c562     POP        EBX
//         0052c563     POP        this
//         0052c564     RET        0x14
//                               LAB_0052c567                                                 XREF[4]:     0052c514(j), 0052c51e(j),
//                                                                                                         0052c526(j), 0052c52d(j)
//                              ttsk_lst.cpp:159 (74)
//         0052c567     TEST       ESI,ESI
//         0052c569     JZ         LAB_0052c74e
//         0052c56f     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c572     MOV        this,dword ptr [EDX + 0xc]
//         0052c575     CMP        EAX,this
//         0052c577     JZ         LAB_0052c59f
//         0052c579     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c57d     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c57f     PUSH       EAX
//         0052c580     CALL       dword ptr [EDX + 0x1c]
//         0052c583     TEST       EAX,EAX
//         0052c585     JZ         LAB_0052c5e5
//         0052c587     MOV        EAX,dword ptr [ESP + 0x18]
//         0052c58b     MOV        this,dword ptr [ESI + 0xc]
//         0052c58e     MOV        EAX,dword ptr [EAX + 0xc]
//         0052c591     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c593     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c597     PUSH       EAX
//         0052c598     CALL       dword ptr [EDX + 0x1c]
//         0052c59b     TEST       EAX,EAX
//         0052c59d     JZ         LAB_0052c5e5
//                               LAB_0052c59f                                                 XREF[1]:     0052c577(j)
//         0052c59f     CMP        byte ptr [ESI + 0x48],0x3
//         0052c5a3     JNC        LAB_0052c5e5
//         0052c5a5     MOV        this,dword ptr [ESI + 0x8]
//         0052c5a8     CMP        byte ptr [this->field0_0x0 + 0x8f],0x7
//         0052c5af     JNZ        LAB_0052c5e5
//                              ttsk_lst.cpp:161 (18)
//         0052c5b1     MOV        EAX,dword ptr [ESP + local_4]
//         0052c5b5     XOR        EDX,EDX
//         0052c5b7     MOVSX      ESI,word ptr [EAX + 0x8]
//         0052c5bb     TEST       ESI,ESI
//         0052c5bd     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (3)
//         0052c5c3     MOV        this,dword ptr [EAX + 0x4]
//                               LAB_0052c5c6                                                 XREF[1]:     0052c5d9(j)
//                              ttsk_lst.cpp:163 (2)
//         0052c5c6     MOV        EAX,dword ptr [this->field0_0x0]
//                              ttsk_lst.cpp:164 (19)
//         0052c5c8     CMP        word ptr [EAX + 0x6],0x3
//         0052c5cd     JZ         LAB_0052c899
//         0052c5d3     INC        EDX
//         0052c5d4     ADD        this,0x4
//         0052c5d7     CMP        EDX,ESI
//         0052c5d9     JL         LAB_0052c5c6
//                              ttsk_lst.cpp:167 (2)
//         0052c5db     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c5dd     POP        EDI
//         0052c5de     POP        ESI
//         0052c5df     POP        EBP
//         0052c5e0     POP        EBX
//         0052c5e1     POP        this
//         0052c5e2     RET        0x14
//                               LAB_0052c5e5                                                 XREF[4]:     0052c585(j), 0052c59d(j),
//                                                                                                         0052c5a3(j), 0052c5af(j)
//                              ttsk_lst.cpp:180 (87)
//         0052c5e5     TEST       ESI,ESI
//         0052c5e7     JZ         LAB_0052c74e
//         0052c5ed     MOV        this,dword ptr [ESP + 0x18]
//         0052c5f1     TEST       this,this
//         0052c5f3     JZ         LAB_0052c689
//         0052c5f9     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c5fc     MOV        this,dword ptr [ECX + this+0xc]
//         0052c5ff     CMP        EAX,this
//         0052c601     JZ         LAB_0052c611
//         0052c603     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c607     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c609     PUSH       EAX
//         0052c60a     CALL       dword ptr [EDX + 0x1c]
//         0052c60d     TEST       EAX,EAX
//         0052c60f     JZ         LAB_0052c689
//                               LAB_0052c611                                                 XREF[1]:     0052c601(j)
//         0052c611     MOV        this,dword ptr [ESI + 0x8]
//         0052c614     CMP        byte ptr [ECX + this->field4_0x4],BL
//         0052c617     JNZ        LAB_0052c689
//         0052c619     MOVSX      EDX,word ptr [this->field0_0x0 + 0x26]
//         0052c61d     MOV        dword ptr [ESP + 0x1c],EDX
//         0052c621     FILD       dword ptr [ESP + 0x1c]
//         0052c625     FCOMP      float ptr [ESI + 0x30]
//         0052c628     FNSTSW     AX
//         0052c62a     TEST       AH,0x41
//         0052c62d     JNZ        LAB_0052c689
//         0052c62f     CMP        byte ptr [ESI + 0x48],0x3
//         0052c633     JNC        LAB_0052c689
//         0052c635     CMP        word ptr [this->field0_0x0 + 0x10],0x32
//         0052c63a     JZ         LAB_0052c689
//                              ttsk_lst.cpp:182 (18)
//         0052c63c     MOV        EAX,dword ptr [ESP + 0x10]
//         0052c640     XOR        ESI,ESI
//         0052c642     MOVSX      EDI,word ptr [EAX + 0x8]
//         0052c646     TEST       EDI,EDI
//         0052c648     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (32)
//         0052c64e     MOV        this,EAX
//         0052c650     MOV        EBX,0x6a
//         0052c655     MOV        EDX,dword ptr [ECX + this->field4_0x4]
//                               LAB_0052c658                                                 XREF[1]:     0052c67d(j)
//         0052c658     MOV        EAX,dword ptr [EDX]
//         0052c65a     CMP        word ptr [EAX + 0x6],BX
//         0052c65e     JNZ        LAB_0052c677
//         0052c660     MOV        this,word ptr [EAX + 0x8]
//         0052c664     CMP        this,-0x1
//         0052c668     JZ         LAB_0052c899
//                              ttsk_lst.cpp:185 (9)
//         0052c66e     TEST       this,this
//         0052c671     JZ         LAB_0052c899
//                               LAB_0052c677                                                 XREF[1]:     0052c65e(j)
//                              ttsk_lst.cpp:182 (8)
//         0052c677     INC        ESI
//         0052c678     ADD        EDX,0x4
//         0052c67b     CMP        ESI,EDI
//         0052c67d     JL         LAB_0052c658
//                              ttsk_lst.cpp:188 (2)
//         0052c67f     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c681     POP        EDI
//         0052c682     POP        ESI
//         0052c683     POP        EBP
//         0052c684     POP        EBX
//         0052c685     POP        this
//         0052c686     RET        0x14
//                               LAB_0052c689                                                 XREF[6]:     0052c5f3(j), 0052c60f(j),
//                                                                                                         0052c617(j), 0052c62d(j),
//                                                                                                         0052c633(j), 0052c63a(j)
//                              ttsk_lst.cpp:201 (135)
//         0052c689     TEST       ESI,ESI
//         0052c68b     JZ         LAB_0052c74e
//         0052c691     MOV        EAX,dword ptr [ESP + 0x18]
//         0052c695     TEST       EAX,EAX
//         0052c697     JZ         LAB_0052c74e
//         0052c69d     MOV        EDX,dword ptr [ESP + 0x18]
//         0052c6a1     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c6a4     MOV        this,dword ptr [EDX + 0xc]
//         0052c6a7     CMP        EAX,this
//         0052c6a9     JZ         LAB_0052c6d5
//         0052c6ab     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c6af     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c6b1     PUSH       EAX
//         0052c6b2     CALL       dword ptr [EDX + 0x1c]
//         0052c6b5     TEST       EAX,EAX
//         0052c6b7     JZ         LAB_0052c74e
//         0052c6bd     MOV        EAX,dword ptr [ESP + 0x18]
//         0052c6c1     MOV        this,dword ptr [ESI + 0xc]
//         0052c6c4     MOV        EAX,dword ptr [EAX + 0xc]
//         0052c6c7     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c6c9     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c6cd     PUSH       EAX
//         0052c6ce     CALL       dword ptr [EDX + 0x1c]
//         0052c6d1     TEST       EAX,EAX
//         0052c6d3     JZ         LAB_0052c74e
//                               LAB_0052c6d5                                                 XREF[1]:     0052c6a9(j)
//         0052c6d5     MOV        EAX,dword ptr [ESI + 0x8]
//         0052c6d8     MOV        DI,word ptr [EAX + 0x14]
//         0052c6dc     CMP        DI,0x2
//         0052c6e0     JZ         LAB_0052c6f4
//         0052c6e2     CMP        DI,0x14
//         0052c6e6     JZ         LAB_0052c6f4
//         0052c6e8     CMP        DI,0x15
//         0052c6ec     JZ         LAB_0052c6f4
//         0052c6ee     CMP        DI,0x16
//         0052c6f2     JNZ        LAB_0052c74e
//                               LAB_0052c6f4                                                 XREF[3]:     0052c6e0(j), 0052c6e6(j),
//                                                                                                         0052c6ec(j)
//         0052c6f4     MOVSX      this,word ptr [EAX + 0x26]
//         0052c6f8     MOV        dword ptr [ESP + 0x1c],this
//         0052c6fc     FILD       dword ptr [ESP + 0x1c]
//         0052c700     FCOMP      float ptr [ESI + 0x30]
//         0052c703     FNSTSW     AX
//         0052c705     TEST       AH,0x41
//         0052c708     JNZ        LAB_0052c74e
//         0052c70a     CMP        byte ptr [ESI + 0x48],0x3
//         0052c70e     JNC        LAB_0052c74e
//                              ttsk_lst.cpp:203 (18)
//         0052c710     MOV        EAX,dword ptr [ESP + 0x10]
//         0052c714     XOR        EDX,EDX
//         0052c716     MOVSX      ESI,word ptr [EAX + 0x8]
//         0052c71a     TEST       ESI,ESI
//         0052c71c     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (16)
//         0052c722     MOV        this,dword ptr [EAX + 0x4]
//         0052c725     MOV        EBX,0x6a
//                               LAB_0052c72a                                                 XREF[1]:     0052c742(j)
//         0052c72a     MOV        EAX,dword ptr [this->field0_0x0]
//         0052c72c     CMP        word ptr [EAX + 0x6],BX
//         0052c730     JNZ        LAB_0052c73c
//                              ttsk_lst.cpp:206 (10)
//         0052c732     CMP        word ptr [EAX + 0x8],DI
//         0052c736     JZ         LAB_0052c899
//                               LAB_0052c73c                                                 XREF[1]:     0052c730(j)
//                              ttsk_lst.cpp:203 (8)
//         0052c73c     INC        EDX
//         0052c73d     ADD        this,0x4
//         0052c740     CMP        EDX,ESI
//         0052c742     JL         LAB_0052c72a
//                              ttsk_lst.cpp:209 (2)
//         0052c744     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c746     POP        EDI
//         0052c747     POP        ESI
//         0052c748     POP        EBP
//         0052c749     POP        EBX
//         0052c74a     POP        this
//         0052c74b     RET        0x14
//                               LAB_0052c74e                                                 XREF[10]:    0052c50c(j), 0052c569(j),
//                                                                                                         0052c5e7(j), 0052c68b(j),
//                                                                                                         0052c697(j), 0052c6b7(j),
//                                                                                                         0052c6d3(j), 0052c6f2(j),
//                                                                                                         0052c708(j), 0052c70e(j)
//                              ttsk_lst.cpp:246 (26)
//         0052c74e     MOV        EDI,dword ptr [ESP + param_1]
//         0052c752     TEST       EDI,EDI
//         0052c754     JZ         LAB_0052c87f
//         0052c75a     MOV        EDX,dword ptr [EDI + 0x8]
//         0052c75d     CMP        word ptr [EDX + 0x14],0x12
//         0052c762     JNZ        LAB_0052c87f
//                              ttsk_lst.cpp:255 (56)
//         0052c768     TEST       ESI,ESI
//         0052c76a     JZ         LAB_0052c875
//         0052c770     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c773     MOV        this,dword ptr [EDI + 0xc]
//         0052c776     CMP        EAX,this
//         0052c778     JZ         LAB_0052c7d8
//         0052c77a     CMP        byte ptr [ESI + 0x48],0x3
//         0052c77e     JNC        LAB_0052c7d8
//         0052c780     MOV        AX,word ptr [EAX + 0x4a]
//         0052c784     TEST       AX,AX
//         0052c787     JLE        LAB_0052c7d8
//         0052c789     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c78b     MOVSX      EAX,AX
//         0052c78e     PUSH       EAX
//         0052c78f     CALL       dword ptr [EDX + 0x1c]
//         0052c792     TEST       EAX,EAX
//         0052c794     JNZ        LAB_0052c7d8
//         0052c796     MOV        this,dword ptr [ESI + 0x8]
//         0052c799     CMP        word ptr [this->field0_0x0 + 0x14],0x1
//         0052c79e     JZ         LAB_0052c7d8
//                              ttsk_lst.cpp:259 (18)
//         0052c7a0     MOV        EAX,dword ptr [ESP + 0x10]
//         0052c7a4     XOR        EDX,EDX
//         0052c7a6     MOVSX      ESI,word ptr [EAX + 0x8]
//         0052c7aa     TEST       ESI,ESI
//         0052c7ac     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (28)
//         0052c7b2     MOV        this,dword ptr [EAX + 0x4]
//         0052c7b5     MOV        EDI,0x68
//                               LAB_0052c7ba                                                 XREF[1]:     0052c7cc(j)
//         0052c7ba     MOV        EAX,dword ptr [this->field0_0x0]
//         0052c7bc     CMP        word ptr [EAX + 0x6],DI
//         0052c7c0     JZ         LAB_0052c899
//         0052c7c6     INC        EDX
//         0052c7c7     ADD        this,0x4
//         0052c7ca     CMP        EDX,ESI
//         0052c7cc     JL         LAB_0052c7ba
//                              ttsk_lst.cpp:265 (2)
//         0052c7ce     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c7d0     POP        EDI
//         0052c7d1     POP        ESI
//         0052c7d2     POP        EBP
//         0052c7d3     POP        EBX
//         0052c7d4     POP        this
//         0052c7d5     RET        0x14
//                               LAB_0052c7d8                                                 XREF[5]:     0052c778(j), 0052c77e(j),
//                                                                                                         0052c787(j), 0052c794(j),
//                                                                                                         0052c79e(j)
//                              ttsk_lst.cpp:278 (109)
//         0052c7d8     TEST       ESI,ESI
//         0052c7da     JZ         LAB_0052c875
//         0052c7e0     MOV        EAX,dword ptr [ESI + 0xc]
//         0052c7e3     MOV        this,dword ptr [EDI + 0xc]
//         0052c7e6     CMP        EAX,this
//         0052c7e8     JZ         LAB_0052c7f8
//         0052c7ea     MOVSX      EAX,word ptr [EAX + 0x4a]
//         0052c7ee     MOV        EDX,dword ptr [this->field0_0x0]
//         0052c7f0     PUSH       EAX
//         0052c7f1     CALL       dword ptr [EDX + 0x1c]
//         0052c7f4     TEST       EAX,EAX
//         0052c7f6     JZ         LAB_0052c875
//                               LAB_0052c7f8                                                 XREF[1]:     0052c7e8(j)
//         0052c7f8     MOV        this,dword ptr [ESI + 0x8]
//         0052c7fb     MOVSX      EDX,word ptr [this->field0_0x0 + 0x26]
//         0052c7ff     MOV        dword ptr [ESP + 0x18],EDX
//         0052c803     FILD       dword ptr [ESP + 0x18]
//         0052c807     FCOMP      float ptr [ESI + 0x30]
//         0052c80a     FNSTSW     AX
//         0052c80c     TEST       AH,0x41
//         0052c80f     JNZ        LAB_0052c875
//         0052c811     CMP        byte ptr [ESI + 0x48],0x3
//         0052c815     JNC        LAB_0052c875
//         0052c817     MOV        AX,word ptr [this->field0_0x0 + 0x14]
//         0052c81b     CMP        AX,0x15
//         0052c81f     JZ         LAB_0052c875
//         0052c821     CMP        AX,0x2
//         0052c825     JZ         LAB_0052c875
//         0052c827     CMP        AX,0x14
//         0052c82b     JZ         LAB_0052c875
//         0052c82d     CMP        AX,0x16
//         0052c831     JZ         LAB_0052c875
//         0052c833     CMP        AX,0x1
//         0052c837     JZ         LAB_0052c875
//         0052c839     CMP        AX,0x1b
//         0052c83d     JZ         LAB_0052c875
//         0052c83f     CMP        AX,0x3
//         0052c843     JZ         LAB_0052c875
//                              ttsk_lst.cpp:280 (14)
//         0052c845     MOV        EAX,dword ptr [ESP + 0x10]
//         0052c849     XOR        EDX,EDX
//         0052c84b     MOVSX      ESI,word ptr [EAX + 0x8]
//         0052c84f     TEST       ESI,ESI
//         0052c851     JLE        LAB_0052c875
//                              ttsk_lst.cpp:294 (24)
//         0052c853     MOV        this,dword ptr [EAX + 0x4]
//         0052c856     MOV        EDI,0x69
//                               LAB_0052c85b                                                 XREF[1]:     0052c869(j)
//         0052c85b     MOV        EAX,dword ptr [this->field0_0x0]
//         0052c85d     CMP        word ptr [EAX + 0x6],DI
//         0052c861     JZ         LAB_0052c899
//         0052c863     INC        EDX
//         0052c864     ADD        this,0x4
//         0052c867     CMP        EDX,ESI
//         0052c869     JL         LAB_0052c85b
//                              ttsk_lst.cpp:286 (2)
//         0052c86b     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c86d     POP        EDI
//         0052c86e     POP        ESI
//         0052c86f     POP        EBP
//         0052c870     POP        EBX
//         0052c871     POP        this
//         0052c872     RET        0x14
//                               LAB_0052c875                                                 XREF[18]:    0052c53b(j), 0052c5bd(j),
//                                                                                                         0052c648(j), 0052c71c(j),
//                                                                                                         0052c76a(j), 0052c7ac(j),
//                                                                                                         0052c7da(j), 0052c7f6(j),
//                                                                                                         0052c80f(j), 0052c815(j),
//                                                                                                         0052c81f(j), 0052c825(j),
//                                                                                                         0052c82b(j), 0052c831(j),
//                                                                                                         0052c837(j), 0052c83d(j),
//                                                                                                         0052c843(j), 0052c851(j)
//                              ttsk_lst.cpp:289 (2)
//         0052c875     XOR        EAX,EAX
//                              ttsk_lst.cpp:294 (8)
//         0052c877     POP        EDI
//         0052c878     POP        ESI
//         0052c879     POP        EBP
//         0052c87a     POP        EBX
//         0052c87b     POP        this
//         0052c87c     RET        0x14
//                               LAB_0052c87f                                                 XREF[2]:     0052c754(j), 0052c762(j)
//                              ttsk_lst.cpp:293 (26)
//         0052c87f     MOV        EAX,dword ptr [ESP + 0x28]
//         0052c883     MOV        this,dword ptr [ESP + 0x24]
//         0052c887     MOV        EDX,dword ptr [ESP + 0x20]
//         0052c88b     PUSH       EAX
//         0052c88c     PUSH       this
//         0052c88d     MOV        this,dword ptr [ESP + 0x18]
//         0052c891     PUSH       EDX
//         0052c892     PUSH       ESI
//         0052c893     PUSH       EDI
//         0052c894     CALL       RGE_Task_List::get_target_task                   RGE_Task * get_target_task(RGE_Task_List * th
//                               LAB_0052c899                                                 XREF[10]:    0052c4e2(j), 0052c4ec(j),
//                                                                                                         0052c4f6(j), 0052c54f(j),
//                                                                                                         0052c5cd(j), 0052c668(j),
//                                                                                                         0052c671(j), 0052c736(j),
//                                                                                                         0052c7c0(j), 0052c861(j)
//                              ttsk_lst.cpp:294 (48)
//         0052c899     POP        EDI
//         0052c89a     POP        ESI
//         0052c89b     POP        EBP
//         0052c89c     POP        EBX
//         0052c89d     POP        this
//         0052c89e     RET        0x14
    return 0;
}

int TRIBE_Task_List::is_attack_task(RGE_Task* param_1) {
    /* TODO: Stub */
//                              int __thiscall is_attack_task(TRIBE_Task_List * this, RGE_Task * par
//              int               EAX:4          <RETURN>
//              TRIBE_Task_Lis    ECX:4 (auto)   this
//              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     0052c8d0(R)
//                               ?is_attack_task@TRIBE_Task_List@@UAEHPAVRGE_Task@@@Z         XREF[1]:     00576788(*)
//                               TRIBE_Task_List::is_attack_task
//                              ttsk_lst.cpp:299 (11)
//         0052c8d0     MOV        EAX,dword ptr [ESP + param_1]
//         0052c8d4     CMP        word ptr [EAX + 0x6],0x68
//         0052c8d9     JNZ        LAB_0052c8e3
//                              ttsk_lst.cpp:301 (5)
//         0052c8db     MOV        EAX,0x1
//                              ttsk_lst.cpp:304 (3)
//         0052c8e0     RET        0x4
//                               LAB_0052c8e3                                                 XREF[1]:     0052c8d9(j)
//                              ttsk_lst.cpp:303 (6)
//         0052c8e3     PUSH       EAX
//         0052c8e4     CALL       RGE_Task_List::is_attack_task                    int is_attack_task(RGE_Task_List * this, RGE_
//                              ttsk_lst.cpp:304 (3)
//         0052c8e9     RET        0x4
//         0052c8ec     ??         90h
//         0052c8ed     NOP
//         0052c8ee     NOP
//         0052c8ef     NOP
    return 0;
}

