#include "../common.h"
#include "vis_unit.h"

Visible_Unit_Manager::Visible_Unit_Manager(int param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall Visible_Unit_Manager(Visible_Unit_Manager * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              Visible_Unit_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b5a0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b5aa(R)
//                               ??0Visible_Unit_Manager@@QAE@HH@Z                            XREF[1]:     new_map:00455bfb(c)
//                               Visible_Unit_Manager::Visible_Unit_Manager
//                              vis_unit.cpp:49 (10)
//         0053b5a0     MOV        EAX,dword ptr [ESP + param_1]
//         0053b5a4     PUSH       EBX
//         0053b5a5     PUSH       EBP
//         0053b5a6     PUSH       ESI
//         0053b5a7     PUSH       EDI
//         0053b5a8     MOV        EDI,this
//                              vis_unit.cpp:58 (4)
//         0053b5aa     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:59 (3)
//         0053b5ae     XOR        EBP,EBP
//         0053b5b0     INC        this
//                              vis_unit.cpp:61 (19)
//         0053b5b1     PUSH       0x4
//         0053b5b3     PUSH       EAX
//         0053b5b4     MOV        dword ptr [EDI + 0x18],EAX
//         0053b5b7     MOV        dword ptr [EDI + 0x1c],this
//         0053b5ba     MOV        dword ptr [EDI + 0x20],EBP
//         0053b5bd     CALL       calloc                                           undefined calloc()
//         0053b5c2     MOV        dword ptr [EDI],EAX
//                              vis_unit.cpp:64 (10)
//         0053b5c4     MOV        EAX,dword ptr [EDI + 0x18]
//         0053b5c7     ADD        ESP,0x8
//         0053b5ca     CMP        EAX,EBP
//         0053b5cc     JLE        LAB_0053b61f
//                               LAB_0053b5ce                                                 XREF[1]:     0053b61d(j)
//                              vis_unit.cpp:66 (16)
//         0053b5ce     MOV        EDX,dword ptr [EDI + 0x1c]
//         0053b5d1     PUSH       0x8
//         0053b5d3     PUSH       EDX
//         0053b5d4     CALL       calloc                                           undefined calloc()
//         0053b5d9     MOV        this,dword ptr [EDI]
//         0053b5db     ADD        ESP,0x8
//                              vis_unit.cpp:68 (17)
//         0053b5de     XOR        EBX,EBX
//         0053b5e0     MOV        dword ptr [this->PlayerDataPtrs + EBP*0x4],EAX
//         0053b5e3     MOV        EDX,dword ptr [EDI]
//         0053b5e5     MOV        this,dword ptr [EDI + 0x1c]
//         0053b5e8     MOV        EAX,dword ptr [EDX + EBP*0x4]
//         0053b5eb     TEST       this,this
//         0053b5ed     JLE        LAB_0053b617
//                              vis_unit.cpp:66 (3)
//         0053b5ef     LEA        ESI,[EAX + 0x6]
//                               LAB_0053b5f2                                                 XREF[1]:     0053b615(j)
//                              vis_unit.cpp:72 (37)
//         0053b5f2     PUSH       0x8
//         0053b5f4     MOV        word ptr [ESI + -0x2],0x20
//         0053b5fa     PUSH       0x20
//         0053b5fc     MOV        word ptr [ESI],0x0
//         0053b601     CALL       calloc                                           undefined calloc()
//         0053b606     ADD        ESP,0x8
//         0053b609     MOV        dword ptr [ESI + -0x6],EAX
//         0053b60c     MOV        EAX,dword ptr [EDI + 0x1c]
//         0053b60f     INC        EBX
//         0053b610     ADD        ESI,0x8
//         0053b613     CMP        EBX,EAX
//         0053b615     JL         LAB_0053b5f2
//                               LAB_0053b617                                                 XREF[1]:     0053b5ed(j)
//                              vis_unit.cpp:64 (8)
//         0053b617     MOV        EAX,dword ptr [EDI + 0x18]
//         0053b61a     INC        EBP
//         0053b61b     CMP        EBP,EAX
//         0053b61d     JL         LAB_0053b5ce
//                               LAB_0053b61f                                                 XREF[1]:     0053b5cc(j)
//                              vis_unit.cpp:77 (3)
//         0053b61f     LEA        EBX,[EDI + 0x4]
//                              vis_unit.cpp:81 (44)
//         0053b622     XOR        ESI,ESI
//                               LAB_0053b624                                                 XREF[1]:     0053b64c(j)
//         0053b624     PUSH       0x800
//         0053b629     CALL       malloc                                           undefined malloc()
//         0053b62e     MOV        dword ptr [EBX],EAX
//         0053b630     MOV        dword ptr [ESI + VisibleUnitList],EAX            = 00000000
//         0053b636     MOV        dword ptr [ESI + VisibleUnitList_Size],0x0       = 00000000
//         0053b640     ADD        ESI,0x4
//         0053b643     ADD        ESP,0x4
//         0053b646     ADD        EBX,0x4
//         0053b649     CMP        ESI,0x14
//         0053b64c     JL         LAB_0053b624
//                              vis_unit.cpp:84 (7)
//         0053b64e     MOV        this,EDI
//         0053b650     CALL       Visible_Unit_Manager::Build_Distance_Table       void Build_Distance_Table(Visible_Unit_Manage
//                              vis_unit.cpp:86 (6)
//         0053b655     MOV        dword ptr [VisibleUnitManager],EDI               = 00000000
//                              vis_unit.cpp:88 (9)
//         0053b65b     MOV        EAX,EDI
//         0053b65d     POP        EDI
//         0053b65e     POP        ESI
//         0053b65f     POP        EBP
//         0053b660     POP        EBX
//         0053b661     RET        0x8
//         0053b664     ??         90h
//         0053b665     NOP
//         0053b666     NOP
//         0053b667     NOP
//         0053b668     NOP
//         0053b669     NOP
//         0053b66a     NOP
//         0053b66b     NOP
//         0053b66c     NOP
//         0053b66d     NOP
//         0053b66e     NOP
//         0053b66f     NOP
}

Visible_Unit_Manager::~Visible_Unit_Manager() {
    /* TODO: Stub */
//                              void __thiscall ~Visible_Unit_Manager(Visible_Unit_Manager * this)
//              void              <VOID>         <RETURN>
//              Visible_Unit_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0053b686(W), 0053b6c0(R), 0053b6cd(W)
//              int               Stack[-0x8]:4  i
//                               ??1Visible_Unit_Manager@@QAE@XZ                              XREF[2]:     ~RGE_Map:0045554e(c),
//                               Visible_Unit_Manager::~Visible_Unit_Manager                               new_map:00455bc4(c)
//                              vis_unit.cpp:91 (5)
//         0053b670     PUSH       this
//         0053b671     PUSH       EBX
//         0053b672     MOV        EBX,this
//         0053b674     PUSH       EBP
//                              vis_unit.cpp:97 (10)
//         0053b675     XOR        EBP,EBP
//         0053b677     MOV        EAX,dword ptr [EBX]
//         0053b679     PUSH       ESI
//         0053b67a     CMP        EAX,EBP
//         0053b67c     PUSH       EDI
//         0053b67d     JZ         LAB_0053b6e0
//                              vis_unit.cpp:99 (13)
//         0053b67f     MOV        this,dword ptr [EBX + 0x18]
//         0053b682     XOR        EAX,EAX
//         0053b684     CMP        this,EBP
//         0053b686     MOV        dword ptr [ESP + local_4],EAX
//         0053b68a     JLE        LAB_0053b6d5
//                               LAB_0053b68c                                                 XREF[1]:     0053b6d1(j)
//                              vis_unit.cpp:101 (5)
//         0053b68c     MOV        this,dword ptr [EBX]
//         0053b68e     MOV        EBP,dword ptr [this->PlayerDataPtrs + EAX*0x4]
//                              vis_unit.cpp:102 (4)
//         0053b691     TEST       EBP,EBP
//         0053b693     JZ         LAB_0053b6c7
//                              vis_unit.cpp:104 (9)
//         0053b695     MOV        EAX,dword ptr [EBX + 0x1c]
//         0053b698     XOR        EDI,EDI
//         0053b69a     TEST       EAX,EAX
//         0053b69c     JLE        LAB_0053b6ba
//                              vis_unit.cpp:125 (2)
//         0053b69e     MOV        ESI,EBP
//                               LAB_0053b6a0                                                 XREF[1]:     0053b6b8(j)
//                              vis_unit.cpp:106 (26)
//         0053b6a0     MOV        EAX,dword ptr [ESI]
//         0053b6a2     TEST       EAX,EAX
//         0053b6a4     JZ         LAB_0053b6af
//         0053b6a6     PUSH       EAX
//         0053b6a7     CALL       free                                             undefined free()
//         0053b6ac     ADD        ESP,0x4
//                               LAB_0053b6af                                                 XREF[1]:     0053b6a4(j)
//         0053b6af     MOV        EAX,dword ptr [EBX + 0x1c]
//         0053b6b2     INC        EDI
//         0053b6b3     ADD        ESI,0x8
//         0053b6b6     CMP        EDI,EAX
//         0053b6b8     JL         LAB_0053b6a0
//                               LAB_0053b6ba                                                 XREF[1]:     0053b69c(j)
//                              vis_unit.cpp:108 (25)
//         0053b6ba     PUSH       EBP
//         0053b6bb     CALL       free                                             undefined free()
//         0053b6c0     MOV        EAX,dword ptr [ESP + local_4]
//         0053b6c4     ADD        ESP,0x4
//                               LAB_0053b6c7                                                 XREF[1]:     0053b693(j)
//         0053b6c7     MOV        this,dword ptr [EBX + 0x18]
//         0053b6ca     INC        EAX
//         0053b6cb     CMP        EAX,this
//         0053b6cd     MOV        dword ptr [ESP + local_4],EAX
//         0053b6d1     JL         LAB_0053b68c
//                              vis_unit.cpp:99 (2)
//         0053b6d3     XOR        EBP,EBP
//                               LAB_0053b6d5                                                 XREF[1]:     0053b68a(j)
//                              vis_unit.cpp:111 (11)
//         0053b6d5     MOV        EDX,dword ptr [EBX]
//         0053b6d7     PUSH       EDX
//         0053b6d8     CALL       free                                             undefined free()
//         0053b6dd     ADD        ESP,0x4
//                               LAB_0053b6e0                                                 XREF[1]:     0053b67d(j)
//                              vis_unit.cpp:114 (3)
//         0053b6e0     LEA        EDI,[EBX + 0x4]
//                              vis_unit.cpp:117 (23)
//         0053b6e3     XOR        ESI,ESI
//                               LAB_0053b6e5                                                 XREF[1]:     0053b709(j)
//         0053b6e5     MOV        EAX,dword ptr [EDI]
//         0053b6e7     CMP        EAX,EBP
//         0053b6e9     JZ         LAB_0053b6f4
//         0053b6eb     PUSH       EAX
//         0053b6ec     CALL       free                                             undefined free()
//         0053b6f1     ADD        ESP,0x4
//                               LAB_0053b6f4                                                 XREF[1]:     0053b6e9(j)
//         0053b6f4     MOV        dword ptr [ESI + VisibleUnitList],EBP            = 00000000
//                              vis_unit.cpp:118 (17)
//         0053b6fa     MOV        dword ptr [ESI + VisibleUnitList_Size],EBP       = 00000000
//         0053b700     ADD        ESI,0x4
//         0053b703     ADD        EDI,0x4
//         0053b706     CMP        ESI,0x14
//         0053b709     JL         LAB_0053b6e5
//                              vis_unit.cpp:121 (16)
//         0053b70b     MOV        EBX,dword ptr [EBX + 0x20]
//         0053b70e     CMP        EBX,EBP
//         0053b710     JZ         LAB_0053b71b
//         0053b712     PUSH       EBX
//         0053b713     CALL       free                                             undefined free()
//         0053b718     ADD        ESP,0x4
//                               LAB_0053b71b                                                 XREF[1]:     0053b710(j)
//                              vis_unit.cpp:125 (12)
//         0053b71b     POP        EDI
//         0053b71c     MOV        dword ptr [VisibleUnitManager],EBP               = 00000000
//         0053b722     POP        ESI
//         0053b723     POP        EBP
//         0053b724     POP        EBX
//         0053b725     POP        this
//         0053b726     RET
//         0053b727     ??         90h
//         0053b728     NOP
//         0053b729     NOP
//         0053b72a     NOP
//         0053b72b     NOP
//         0053b72c     NOP
//         0053b72d     NOP
//         0053b72e     NOP
//         0053b72f     NOP
}

void Visible_Unit_Manager::Build_Distance_Table() {
    /* TODO: Stub */
//                              void __thiscall Build_Distance_Table(Visible_Unit_Manager * this)
//              void              <VOID>         <RETURN>
//              Visible_Unit_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0053b76a(W), 0053b7c3(R), 0053b7d1(W)
//                               ?Build_Distance_Table@Visible_Unit_Manager@@QAEXXZ           XREF[1]:     Visible_Unit_Manager:0053b650(c)
//                               Visible_Unit_Manager::Build_Distance_Table
//                              vis_unit.cpp:129 (7)
//         0053b730     PUSH       this
//         0053b731     PUSH       EBX
//         0053b732     PUSH       EBP
//         0053b733     MOV        EBP,this
//         0053b735     PUSH       ESI
//         0053b736     PUSH       EDI
//                              vis_unit.cpp:135 (16)
//         0053b737     MOV        EAX,dword ptr [EBP + 0x20]
//         0053b73a     TEST       EAX,EAX
//         0053b73c     JZ         LAB_0053b747
//         0053b73e     PUSH       EAX
//         0053b73f     CALL       free                                             undefined free()
//         0053b744     ADD        ESP,0x4
//                               LAB_0053b747                                                 XREF[1]:     0053b73c(j)
//                              vis_unit.cpp:139 (12)
//         0053b747     PUSH       0x100
//         0053b74c     CALL       malloc                                           undefined malloc()
//         0053b751     MOV        EDI,EAX
//                              vis_unit.cpp:140 (21)
//         0053b753     MOV        this,0x40
//         0053b758     OR         EAX,0xffffffff
//         0053b75b     MOV        dword ptr [EBP + 0x20],EDI
//         0053b75e     STOSD.REP  ES:EDI
//         0053b760     MOV        this,NormalLOS                                   = 0058cde0
//         0053b765     ADD        ESP,0x4
//                              vis_unit.cpp:142 (6)
//         0053b768     XOR        EBX,EBX
//         0053b76a     MOV        dword ptr [ESP + local_4],this=>NormalLOS        = 0058cde0
//                               LAB_0053b76e                                                 XREF[1]:     0053b7d5(j)
//                              vis_unit.cpp:144 (2)
//         0053b76e     MOV        ESI,dword ptr [this->PlayerDataPtrs]=>->Edge_O   = 0058cde0
//                                                                                  = 0058cdf8
//                              vis_unit.cpp:145 (9)
//         0053b770     MOV        EAX,dword ptr [ESI]=>Edge_Offsets_N0             = 00000000
//                                                                                  = ffffffff
//         0053b772     CMP        EAX,0x3e7
//         0053b777     JZ         LAB_0053b7c7
//                               LAB_0053b779                                                 XREF[1]:     0053b7c1(j)
//                              vis_unit.cpp:148 (3)
//         0053b779     MOV        EDX,dword ptr [ESI + 0x4]=>DAT_0058cde4          = FFFFFFFFh
//                              vis_unit.cpp:149 (3)
//         0053b77c     MOV        this,dword ptr [ESI + 0x8]=>DAT_0058cde8         = 00000001h
//                              vis_unit.cpp:151 (9)
//         0053b77f     TEST       EAX,EAX
//         0053b781     JL         LAB_0053b7b6
//         0053b783     CMP        EAX,0xf
//         0053b786     JG         LAB_0053b7b6
//                              vis_unit.cpp:153 (6)
//         0053b788     TEST       EDX,EDX
//         0053b78a     JGE        LAB_0053b78e
//         0053b78c     XOR        EDX,EDX
//                               LAB_0053b78e                                                 XREF[1]:     0053b78a(j)
//                              vis_unit.cpp:154 (10)
//         0053b78e     CMP        this,0xf
//         0053b791     JLE        LAB_0053b798
//         0053b793     MOV        this,0xf
//                               LAB_0053b798                                                 XREF[1]:     0053b791(j)
//                              vis_unit.cpp:155 (5)
//         0053b798     SHL        EAX,0x4
//         0053b79b     ADD        EAX,EDX
//                              vis_unit.cpp:157 (9)
//         0053b79d     CMP        EDX,this
//         0053b79f     JG         LAB_0053b7b6
//         0053b7a1     SUB        this,EDX
//         0053b7a3     INC        this
//         0053b7a4     MOV        EDI,this
//                               LAB_0053b7a6                                                 XREF[1]:     0053b7b4(j)
//                              vis_unit.cpp:159 (5)
//         0053b7a6     MOV        this,dword ptr [EBP + 0x20]
//         0053b7a9     ADD        this,EAX
//                              vis_unit.cpp:160 (7)
//         0053b7ab     CMP        byte ptr [this->PlayerDataPtrs],0xff
//         0053b7ae     JNZ        LAB_0053b7b2
//         0053b7b0     MOV        byte ptr [this->PlayerDataPtrs],BL
//                               LAB_0053b7b2                                                 XREF[1]:     0053b7ae(j)
//                              vis_unit.cpp:161 (4)
//         0053b7b2     INC        EAX
//         0053b7b3     DEC        EDI
//         0053b7b4     JNZ        LAB_0053b7a6
//                               LAB_0053b7b6                                                 XREF[3]:     0053b781(j), 0053b786(j),
//                                                                                                         0053b79f(j)
//                              vis_unit.cpp:145 (3)
//         0053b7b6     MOV        EAX,dword ptr [ESI + 0xc]=>DAT_0058cdec          = 000003E7h
//                                                                                  = 00000001h
//                              vis_unit.cpp:164 (10)
//         0053b7b9     ADD        ESI,0xc
//         0053b7bc     CMP        EAX,0x3e7
//         0053b7c1     JNZ        LAB_0053b779
//                              vis_unit.cpp:145 (4)
//         0053b7c3     MOV        this,dword ptr [ESP + local_4]
//                               LAB_0053b7c7                                                 XREF[1]:     0053b777(j)
//                              vis_unit.cpp:142 (16)
//         0053b7c7     ADD        this,0x4
//         0053b7ca     INC        EBX
//         0053b7cb     CMP        this,PTR_Edge_Offsets_N16_0058ea50               = 0058daa0
//         0053b7d1     MOV        dword ptr [ESP + local_4],this=>PTR_Edge_Offse   = 0058cdf8
//                                                                                  = 0058ce28
//         0053b7d5     JLE        LAB_0053b76e
//                              vis_unit.cpp:168 (6)
//         0053b7d7     POP        EDI
//         0053b7d8     POP        ESI
//         0053b7d9     POP        EBP
//         0053b7da     POP        EBX
//         0053b7db     POP        this
//         0053b7dc     RET
//         0053b7dd     ??         90h
//         0053b7de     NOP
//         0053b7df     NOP
    return;
}

void Visible_Unit_Manager::Update_Unit_Info(int param_1, int param_2, int param_3, int param_4, int param_5, ulong param_6, ulong param_7, VISIBLE_UNIT_REC** param_8) {
    /* TODO: Stub */
//                              void __thiscall Update_Unit_Info(Visible_Unit_Manager * this, int pa
//              void              <VOID>         <RETURN>
//              Visible_Unit_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b908(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b90e(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053b915(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053b91c(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     0053b7e7(R), 0053b849(R)
//              ulong             Stack[0x18]:4  param_6                   XREF[5]:     0053b7ec(R), 0053b804(W), 0053b8f1(R), 0053b95e(R),
//                                                                                     0053b97f(W)
//              ulong             Stack[0x1c]:4  param_7                   XREF[4]:     0053b7e3(R), 0053b853(R), 0053b96c(R), 0053b977(W)
//              VISIBLE_UNIT_R    Stack[0x20]:4  param_8                   XREF[5]:     0053b81f(R), 0053b82a(W), 0053b8d6(R), 0053b8f5(R),
//                                                                                     0053b989(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053b800(W), 0053b8e9(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0053b899(W), 0053b8a8(R)
//              VISIBLE_UNIT_R    Stack[-0xc]:4  r                         XREF[3]:     0053b815(W), 0053b8ed(R), 0053b985(W)
//              int               Stack[-0x10]:4 i                         XREF[3]:     0053b82e(W), 0053b8d0(R), 0053b955(R)
//                               ?Update_Unit_Info@Visible_Unit_Manager@@QAEXHHHHHKKPAPAUVIS  XREF[3]:     ~RGE_Combat_Object:0042fabc(c),
//                               Visible_Unit_Manager::Update_Unit_Info                                    enter_obj:00430665(c),
//                                                                                                         update:00430746(c)
//                              vis_unit.cpp:172 (3)
//         0053b7e0     SUB        ESP,0x10
//                              vis_unit.cpp:180 (4)
//         0053b7e3     MOV        EDX,dword ptr [ESP + param_7]
//                              vis_unit.cpp:182 (39)
//         0053b7e7     MOV        EAX,dword ptr [ESP + param_5]
//         0053b7eb     PUSH       EBX
//         0053b7ec     MOV        EBX,dword ptr [ESP + param_6]
//         0053b7f0     PUSH       EBP
//         0053b7f1     PUSH       ESI
//         0053b7f2     MOV        ESI,dword ptr [ECX + this->Category_Count]
//         0053b7f5     XOR        EDX,EBX
//         0053b7f7     AND        EDX,0xffff
//         0053b7fd     CMP        EAX,ESI
//         0053b7ff     PUSH       EDI
//         0053b800     MOV        dword ptr [ESP + local_4],this
//         0053b804     MOV        dword ptr [ESP + param_6],EDX
//         0053b808     JGE        LAB_0053b993
//                              vis_unit.cpp:185 (17)
//         0053b80e     MOV        EAX,dword ptr [ECX + this->Player_Count]
//         0053b811     XOR        EDI,EDI
//         0053b813     TEST       EAX,EAX
//         0053b815     MOV        dword ptr [ESP + r],EDI
//         0053b819     JLE        LAB_0053b993
//                              vis_unit.cpp:258 (19)
//         0053b81f     MOV        ESI,dword ptr [ESP + param_8]
//         0053b823     MOV        EAX,0x194
//         0053b828     SUB        EAX,ESI
//         0053b82a     MOV        dword ptr [ESP + param_8],ESI
//         0053b82e     MOV        dword ptr [ESP + i],EAX
//                               LAB_0053b832                                                 XREF[1]:     0053b98d(j)
//                              vis_unit.cpp:185 (8)
//         0053b832     TEST       EDX,EDX
//         0053b834     JZ         LAB_0053b993
//                              vis_unit.cpp:188 (13)
//         0053b83a     MOV        EAX,EDX
//         0053b83c     AND        EAX,0x1
//         0053b83f     CMP        AL,0x1
//         0053b841     JNZ        LAB_0053b96c
//                              vis_unit.cpp:191 (12)
//         0053b847     MOV        EAX,dword ptr [this->PlayerDataPtrs]
//         0053b849     MOV        EBX,dword ptr [ESP + param_5]
//         0053b84d     MOV        EAX,dword ptr [EAX + EDI*0x4]
//         0053b850     LEA        EBP,[EAX + EBX*0x8]
//                              vis_unit.cpp:193 (15)
//         0053b853     MOV        EAX,dword ptr [ESP + param_7]
//         0053b857     AND        EAX,0x1
//         0053b85a     CMP        AL,0x1
//         0053b85c     JNZ        LAB_0053b92b
//                              vis_unit.cpp:195 (14)
//         0053b862     MOV        AX,word ptr [EBP + 0x4]
//         0053b866     CMP        word ptr [EBP + 0x6],AX
//         0053b86a     JNZ        LAB_0053b8f9
//                              vis_unit.cpp:197 (3)
//         0053b870     MOVSX      EBX,AX
//                              vis_unit.cpp:198 (11)
//         0053b873     PUSH       0x8
//         0053b875     LEA        this,[EBX + EBX*0x1]
//         0053b878     PUSH       this
//         0053b879     CALL       calloc                                           undefined calloc()
//                              vis_unit.cpp:199 (33)
//         0053b87e     MOV        ESI,dword ptr [EBP]
//         0053b881     LEA        this,[EBX*0x8 + 0x0]
//         0053b888     MOV        EDX,this
//         0053b88a     MOV        EDI,EAX
//         0053b88c     SHR        this,0x2
//         0053b88f     MOVSD.REP  ES:EDI,ESI
//         0053b891     MOV        this,EDX
//         0053b893     ADD        ESP,0x8
//         0053b896     AND        this,0x3
//         0053b899     MOV        dword ptr [ESP + local_8],EAX
//         0053b89d     MOVSB.REP  ES:EDI,ESI
//                              vis_unit.cpp:200 (9)
//         0053b89f     MOV        EAX,dword ptr [EBP]
//         0053b8a2     PUSH       EAX
//         0053b8a3     CALL       free                                             undefined free()
//                              vis_unit.cpp:201 (4)
//         0053b8a8     MOV        EAX,dword ptr [ESP + local_8]
//                              vis_unit.cpp:206 (21)
//         0053b8ac     XOR        EDX,EDX
//         0053b8ae     ADD        ESP,0x4
//         0053b8b1     CMP        word ptr [EBP + 0x6],DX
//         0053b8b5     LEA        this,[EBX + EBX*0x1]
//         0053b8b8     MOV        dword ptr [EBP],EAX
//         0053b8bb     MOV        word ptr [EBP + 0x4],this
//         0053b8bf     JLE        LAB_0053b8e9
//                               LAB_0053b8c1                                                 XREF[1]:     0053b8e7(j)
//                              vis_unit.cpp:209 (11)
//         0053b8c1     MOV        this,dword ptr [EAX]
//         0053b8c3     MOV        ESI,dword ptr [VIS_UNIT_objectsValue]            = 00000000
//         0053b8c9     MOV        this,dword ptr [ESI + this->PlayerDataPtrs*0x4]
//                              vis_unit.cpp:210 (4)
//         0053b8cc     TEST       this,this
//         0053b8ce     JZ         LAB_0053b8dd
//                              vis_unit.cpp:211 (25)
//         0053b8d0     MOV        ESI,dword ptr [ESP + i]
//         0053b8d4     ADD        this,ESI
//         0053b8d6     MOV        ESI,dword ptr [ESP + param_8]
//         0053b8da     MOV        dword ptr [this->PlayerDataPtrs + ESI*0x1],EAX
//                               LAB_0053b8dd                                                 XREF[1]:     0053b8ce(j)
//         0053b8dd     MOVSX      this,word ptr [EBP + 0x6]
//         0053b8e1     INC        EDX
//         0053b8e2     ADD        EAX,0x8
//         0053b8e5     CMP        EDX,this
//         0053b8e7     JL         LAB_0053b8c1
//                               LAB_0053b8e9                                                 XREF[1]:     0053b8bf(j)
//                              vis_unit.cpp:206 (16)
//         0053b8e9     MOV        this,dword ptr [ESP + local_4]
//         0053b8ed     MOV        EDI,dword ptr [ESP + r]
//         0053b8f1     MOV        EDX,dword ptr [ESP + param_6]
//         0053b8f5     MOV        ESI,dword ptr [ESP + param_8]
//                               LAB_0053b8f9                                                 XREF[1]:     0053b86a(j)
//                              vis_unit.cpp:216 (7)
//         0053b8f9     MOVSX      EAX,word ptr [EBP + 0x6]
//         0053b8fd     MOV        EBX,dword ptr [EBP]
//                              vis_unit.cpp:223 (35)
//         0053b900     MOV        byte ptr [EBX + EAX*0x8 + 0x4],0x0
//         0053b905     LEA        EAX,[EBX + EAX*0x8]
//         0053b908     MOV        EBX,dword ptr [ESP + param_1]
//         0053b90c     MOV        dword ptr [EAX],EBX
//         0053b90e     MOV        BL,byte ptr [ESP + param_2]
//         0053b912     MOV        byte ptr [EAX + 0x5],BL
//         0053b915     MOV        BL,byte ptr [ESP + param_3]
//         0053b919     MOV        byte ptr [EAX + 0x6],BL
//         0053b91c     MOV        BL,byte ptr [ESP + param_4]
//         0053b920     MOV        byte ptr [EAX + 0x7],BL
//                              vis_unit.cpp:225 (4)
//         0053b923     INC        word ptr [EBP + 0x6]
//                              vis_unit.cpp:227 (2)
//         0053b927     MOV        dword ptr [ESI],EAX
//                              vis_unit.cpp:230 (2)
//         0053b929     JMP        LAB_0053b96c
//                               LAB_0053b92b                                                 XREF[1]:     0053b85c(j)
//                              vis_unit.cpp:234 (13)
//         0053b92b     MOVSX      EDX,word ptr [EBP + 0x6]
//         0053b92f     MOV        EBX,dword ptr [EBP]
//         0053b932     MOV        EAX,dword ptr [ESI]
//         0053b934     LEA        EDX,[EBX + EDX*0x8 + -0x8]
//                              vis_unit.cpp:236 (4)
//         0053b938     CMP        EDX,EAX
//         0053b93a     JZ         LAB_0053b95e
//                              vis_unit.cpp:238 (10)
//         0053b93c     MOV        EBX,dword ptr [EDX]
//         0053b93e     MOV        dword ptr [EAX],EBX
//         0053b940     MOV        EDX,dword ptr [EDX + 0x4]
//         0053b943     MOV        dword ptr [EAX + 0x4],EDX
//                              vis_unit.cpp:242 (11)
//         0053b946     MOV        EDX,dword ptr [EAX]
//         0053b948     MOV        EBX,dword ptr [VIS_UNIT_objectsValue]            = 00000000
//         0053b94e     MOV        EDX,dword ptr [EBX + EDX*0x4]
//                              vis_unit.cpp:243 (4)
//         0053b951     TEST       EDX,EDX
//         0053b953     JZ         LAB_0053b95e
//                              vis_unit.cpp:244 (9)
//         0053b955     MOV        EBX,dword ptr [ESP + i]
//         0053b959     ADD        EDX,EBX
//         0053b95b     MOV        dword ptr [EDX + ESI*0x1],EAX
//                               LAB_0053b95e                                                 XREF[2]:     0053b93a(j), 0053b953(j)
//                              vis_unit.cpp:249 (14)
//         0053b95e     MOV        EDX,dword ptr [ESP + param_6]
//         0053b962     MOV        dword ptr [ESI],0x0
//         0053b968     DEC        word ptr [EBP + 0x6]
//                               LAB_0053b96c                                                 XREF[2]:     0053b841(j), 0053b929(j)
//                              vis_unit.cpp:254 (39)
//         0053b96c     MOV        EAX,dword ptr [ESP + param_7]
//         0053b970     ADD        ESI,0x4
//         0053b973     SHR        EAX,0x1
//         0053b975     SHR        EDX,0x1
//         0053b977     MOV        dword ptr [ESP + param_7],EAX
//         0053b97b     MOV        EAX,dword ptr [ECX + this->Player_Count]
//         0053b97e     INC        EDI
//         0053b97f     MOV        dword ptr [ESP + param_6],EDX
//         0053b983     CMP        EDI,EAX
//         0053b985     MOV        dword ptr [ESP + r],EDI
//         0053b989     MOV        dword ptr [ESP + param_8],ESI
//         0053b98d     JL         LAB_0053b832
//                               LAB_0053b993                                                 XREF[3]:     0053b808(j), 0053b819(j),
//                                                                                                         0053b834(j)
//                              vis_unit.cpp:258 (10)
//         0053b993     POP        EDI
//         0053b994     POP        ESI
//         0053b995     POP        EBP
//         0053b996     POP        EBX
//         0053b997     ADD        ESP,0x10
//         0053b99a     RET        0x20
//         0053b99d     ??         90h
//         0053b99e     NOP
//         0053b99f     NOP
    return;
}

int Visible_Unit_Manager::GetVisibleUnits(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6, int* param_7) {
    /* TODO: Stub */
//                              int __thiscall GetVisibleUnits(Visible_Unit_Manager * this, int para
//              int               EAX:4          <RETURN>
//              Visible_Unit_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0053b9ed(R), 0053ba68(R), 0053ba76(R), 0053ba7d(R)
//              int               Stack[0x8]:4   param_2                   XREF[4]:     0053ba1a(R), 0053ba92(R), 0053ba9c(R), 0053baa3(R)
//              int               Stack[0xc]:4   param_3                   XREF[3]:     0053b9d5(R), 0053b9e2(W), 0053babb(R)
//              int               Stack[0x10]:4  param_4                   XREF[3]:     0053b9c0(R), 0053b9ea(W), 0053bab3(R)
//              int *             Stack[0x14]:4  param_5                   XREF[2]:     0053ba32(R), 0053ba3a(W)
//              int               Stack[0x18]:4  param_6                   XREF[2]:     0053b9a6(R), 0053bb0b(RW)
//              int *             Stack[0x1c]:4  param_7                   XREF[1]:     0053bac5(R)
//              int               Stack[-0x8]:4  found                     XREF[4]:     0053b9b0(W), 0053bae1(R), 0053bafc(W), 0053bb17(R)
//              int               Stack[-0xc]:4  y1                        XREF[2]:     0053ba29(W), 0053ba97(R)
//              int               Stack[-0x10]:4 y2                        XREF[2]:     0053ba2c(W), 0053ba8d(R)
//              int               Stack[-0x14]:4 x1                        XREF[2]:     0053ba1d(W), 0053ba6d(R)
//              int               Stack[-0x18]:4 x2                        XREF[2]:     0053ba17(W), 0053ba5f(R)
//              VISIBLE_UNIT_P    Stack[-0x1c]:4 PDP                       XREF[2]:     0053ba22(W), 0053ba3d(R)
//              int               Stack[-0x20]:4 count                     XREF[2]:     0053ba54(W), 0053bb02(RW)
//                               ?GetVisibleUnits@Visible_Unit_Manager@@QAEHHHHHPAHH0@Z       XREF[1]:     search:00415112(c)
//                               Visible_Unit_Manager::GetVisibleUnits
//                              vis_unit.cpp:265 (6)
//         0053b9a0     PUSH       EBP
//         0053b9a1     MOV        EBP,ESP
//         0053b9a3     SUB        ESP,0x1c
//                              vis_unit.cpp:278 (17)
//         0053b9a6     MOV        EAX,dword ptr [EBP + param_6]
//         0053b9a9     XOR        EDX,EDX
//         0053b9ab     PUSH       EBX
//         0053b9ac     PUSH       ESI
//         0053b9ad     CMP        EAX,EDX
//         0053b9af     PUSH       EDI
//         0053b9b0     MOV        dword ptr [EBP + found],EDX
//         0053b9b3     JG         LAB_0053b9c0
//         0053b9b5     XOR        EAX,EAX
//                              vis_unit.cpp:434 (9)
//         0053b9b7     POP        EDI
//         0053b9b8     POP        ESI
//         0053b9b9     POP        EBX
//         0053b9ba     MOV        ESP,EBP
//         0053b9bc     POP        EBP
//         0053b9bd     RET        0x1c
//                               LAB_0053b9c0                                                 XREF[1]:     0053b9b3(j)
//                              vis_unit.cpp:279 (12)
//         0053b9c0     MOV        ESI,dword ptr [EBP + param_4]
//         0053b9c3     MOV        EAX,dword ptr [ECX + this->Player_Count]
//         0053b9c6     CMP        ESI,EAX
//         0053b9c8     JL         LAB_0053b9d5
//         0053b9ca     XOR        EAX,EAX
//                              vis_unit.cpp:434 (9)
//         0053b9cc     POP        EDI
//         0053b9cd     POP        ESI
//         0053b9ce     POP        EBX
//         0053b9cf     MOV        ESP,EBP
//         0053b9d1     POP        EBP
//         0053b9d2     RET        0x1c
//                               LAB_0053b9d5                                                 XREF[1]:     0053b9c8(j)
//                              vis_unit.cpp:281 (16)
//         0053b9d5     MOV        EAX,dword ptr [EBP + param_3]
//         0053b9d8     CMP        EAX,0xf
//         0053b9db     JLE        LAB_0053b9e5
//         0053b9dd     MOV        EAX,0xf
//         0053b9e2     MOV        dword ptr [EBP + param_3],EAX
//                               LAB_0053b9e5                                                 XREF[1]:     0053b9db(j)
//                              vis_unit.cpp:283 (2)
//         0053b9e5     MOV        EDI,dword ptr [this->PlayerDataPtrs]
//                              vis_unit.cpp:284 (6)
//         0053b9e7     MOV        this,dword ptr [ECX + this->distanceTable]
//         0053b9ea     MOV        dword ptr [EBP + param_4],this
//                              vis_unit.cpp:294 (38)
//         0053b9ed     MOV        this,dword ptr [EBP + param_1]
//         0053b9f0     MOV        ESI,dword ptr [EDI + ESI*0x4]
//         0053b9f3     MOV        dword ptr [VisibleUnitList_Size],EDX             = 00000000
//         0053b9f9     MOV        dword ptr [DAT_0087d7cc],EDX
//         0053b9ff     MOV        dword ptr [DAT_0087d7d0],EDX                     = align(4)
//         0053ba05     MOV        dword ptr [DAT_0087d7d4],EDX
//         0053ba0b     MOV        dword ptr [DAT_0087d7d8],EDX
//         0053ba11     MOV        EDX,this
//                              vis_unit.cpp:295 (7)
//         0053ba13     ADD        this,EAX
//         0053ba15     SUB        EDX,EAX
//         0053ba17     MOV        dword ptr [EBP + x2],this
//                              vis_unit.cpp:296 (13)
//         0053ba1a     MOV        this,dword ptr [EBP + param_2]
//         0053ba1d     MOV        dword ptr [EBP + x1],EDX
//         0053ba20     MOV        EDX,this
//         0053ba22     MOV        dword ptr [EBP + PDP],ESI
//         0053ba25     SUB        EDX,EAX
//                              vis_unit.cpp:297 (8)
//         0053ba27     ADD        EAX,this
//         0053ba29     MOV        dword ptr [EBP + y1],EDX
//         0053ba2c     MOV        dword ptr [EBP + y2],EAX
//                              vis_unit.cpp:302 (1)
//         0053ba2f     PUSH       EBX
//                              vis_unit.cpp:303 (1)
//         0053ba30     PUSH       ESI
//                              vis_unit.cpp:304 (1)
//         0053ba31     PUSH       EDI
//                              Symbol Ref: No symbol: start
//                               LAB_0053ba32                                                 XREF[1]:     0053bb0e(j)
//                              vis_unit.cpp:307 (3)
//         0053ba32     MOV        EBX,dword ptr [EBP + param_5]
//                              vis_unit.cpp:308 (2)
//         0053ba35     MOV        EAX,dword ptr [EBX]
//                              vis_unit.cpp:309 (3)
//         0053ba37     ADD        EBX,0x4
//                              vis_unit.cpp:310 (3)
//         0053ba3a     MOV        dword ptr [EBP + param_5],EBX
//                              vis_unit.cpp:312 (3)
//         0053ba3d     MOV        EDX,dword ptr [EBP + PDP]
//                              vis_unit.cpp:313 (3)
//         0053ba40     LEA        EBX,[EDX + EAX*0x8]
//                              vis_unit.cpp:315 (2)
//         0053ba43     MOV        ESI,dword ptr [EBX]
//                              vis_unit.cpp:316 (3)
//         0053ba45     MOV        this,dword ptr [EBX + 0x6]
//                              vis_unit.cpp:317 (6)
//         0053ba48     AND        this,0xffff
//                              vis_unit.cpp:318 (6)
//         0053ba4e     JZ         LAB_0053bb0b
//                              vis_unit.cpp:320 (3)
//         0053ba54     MOV        dword ptr [EBP + count],this
//                              Symbol Ref: No symbol: scan_list
//                               LAB_0053ba57                                                 XREF[1]:     0053bb05(j)
//                              vis_unit.cpp:328 (5)
//         0053ba57     MOV        EAX,0x0
//                              vis_unit.cpp:329 (3)
//         0053ba5c     MOV        AL,byte ptr [ESI + 0x6]
//                              vis_unit.cpp:331 (3)
//         0053ba5f     CMP        EAX,dword ptr [EBP + x2]
//                              vis_unit.cpp:332 (6)
//         0053ba62     JG         LAB_0053baff
//                              vis_unit.cpp:334 (3)
//         0053ba68     CMP        EAX,dword ptr [EBP + param_1]
//                              vis_unit.cpp:335 (2)
//         0053ba6b     JGE        LAB_0053ba7d
//                              vis_unit.cpp:337 (3)
//         0053ba6d     CMP        EAX,dword ptr [EBP + x1]
//                              vis_unit.cpp:338 (6)
//         0053ba70     JL         LAB_0053baff
//                              vis_unit.cpp:340 (3)
//         0053ba76     MOV        EDX,dword ptr [EBP + param_1]
//                              vis_unit.cpp:341 (2)
//         0053ba79     SUB        EDX,EAX
//                              vis_unit.cpp:342 (2)
//         0053ba7b     JMP        LAB_0053ba82
//                              Symbol Ref: No symbol: do_ypos2
//                               LAB_0053ba7d                                                 XREF[1]:     0053ba6b(j)
//                              vis_unit.cpp:345 (3)
//         0053ba7d     SUB        EAX,dword ptr [EBP + param_1]
//                              vis_unit.cpp:346 (2)
//         0053ba80     MOV        EDX,EAX
//                              Symbol Ref: No symbol: do_ypos
//                               LAB_0053ba82                                                 XREF[1]:     0053ba7b(j)
//                              vis_unit.cpp:351 (5)
//         0053ba82     MOV        EAX,0x0
//                              vis_unit.cpp:352 (3)
//         0053ba87     AND        EDX,0xf
//                              vis_unit.cpp:353 (3)
//         0053ba8a     MOV        AL,byte ptr [ESI + 0x7]
//                              vis_unit.cpp:355 (3)
//         0053ba8d     CMP        EAX,dword ptr [EBP + y2]
//                              vis_unit.cpp:356 (2)
//         0053ba90     JG         LAB_0053baff
//                              vis_unit.cpp:358 (3)
//         0053ba92     CMP        EAX,dword ptr [EBP + param_2]
//                              vis_unit.cpp:359 (2)
//         0053ba95     JGE        LAB_0053baa3
//                              vis_unit.cpp:361 (3)
//         0053ba97     CMP        EAX,dword ptr [EBP + y1]
//                              vis_unit.cpp:362 (2)
//         0053ba9a     JL         LAB_0053baff
//                              vis_unit.cpp:364 (3)
//         0053ba9c     MOV        this,dword ptr [EBP + param_2]
//                              vis_unit.cpp:365 (2)
//         0053ba9f     SUB        this,EAX
//                              vis_unit.cpp:366 (2)
//         0053baa1     JMP        LAB_0053baa8
//                              Symbol Ref: No symbol: do_dist2
//                               LAB_0053baa3                                                 XREF[1]:     0053ba95(j)
//                              vis_unit.cpp:369 (3)
//         0053baa3     SUB        EAX,dword ptr [EBP + param_2]
//                              vis_unit.cpp:370 (2)
//         0053baa6     MOV        this,EAX
//                              Symbol Ref: No symbol: do_dist
//                               LAB_0053baa8                                                 XREF[1]:     0053baa1(j)
//                              vis_unit.cpp:375 (3)
//         0053baa8     AND        this,0xf
//                              vis_unit.cpp:376 (5)
//         0053baab     MOV        EAX,0x0
//                              vis_unit.cpp:377 (3)
//         0053bab0     SHL        this,0x4
//                              vis_unit.cpp:378 (3)
//         0053bab3     MOV        EBX,dword ptr [EBP + param_4]
//                              vis_unit.cpp:379 (2)
//         0053bab6     ADD        EDX,this
//                              vis_unit.cpp:380 (3)
//         0053bab8     MOV        AL,byte ptr [EBX + EDX*0x1]
//                              vis_unit.cpp:382 (3)
//         0053babb     CMP        EAX,dword ptr [EBP + param_3]
//                              vis_unit.cpp:383 (2)
//         0053babe     JG         LAB_0053baff
//                              vis_unit.cpp:387 (2)
//         0053bac0     MOV        EDX,EAX
//                              vis_unit.cpp:388 (3)
//         0053bac2     MOV        AL,byte ptr [ESI + 0x5]
//                              vis_unit.cpp:389 (3)
//         0053bac5     MOV        EDI,dword ptr [EBP + param_7]
//                              vis_unit.cpp:390 (3)
//         0053bac8     MOV        EAX,dword ptr [EDI + EAX*0x4]
//                              vis_unit.cpp:392 (7)
//         0053bacb     MOV        this,dword ptr [EAX*0x4 + VisibleUnitList_Size]  = 00000000
//                              vis_unit.cpp:394 (6)
//         0053bad2     CMP        this,0x100
//                              vis_unit.cpp:395 (2)
//         0053bad8     JGE        LAB_0053baff
//                              vis_unit.cpp:397 (7)
//         0053bada     MOV        EDI,dword ptr [EAX*0x4 + VisibleUnitList]        = 00000000
//                              vis_unit.cpp:398 (3)
//         0053bae1     MOV        EBX,dword ptr [EBP + found]
//                              vis_unit.cpp:399 (3)
//         0053bae4     LEA        EDI,[EDI + this->PlayerDataPtrs*0x8]
//                              vis_unit.cpp:400 (1)
//         0053bae7     INC        this
//                              vis_unit.cpp:402 (7)
//         0053bae8     MOV        dword ptr [EAX*0x4 + VisibleUnitList_Size],this  = 00000000
//                              vis_unit.cpp:404 (3)
//         0053baef     MOV        EAX,dword ptr [ESI + 0x4]
//                              vis_unit.cpp:405 (2)
//         0053baf2     MOV        this,dword ptr [ESI]
//                              vis_unit.cpp:406 (2)
//         0053baf4     MOV        AL,DL
//                              vis_unit.cpp:408 (1)
//         0053baf6     INC        EBX
//                              vis_unit.cpp:410 (2)
//         0053baf7     MOV        dword ptr [EDI],this
//                              vis_unit.cpp:411 (3)
//         0053baf9     MOV        dword ptr [EDI + 0x4],EAX
//                              vis_unit.cpp:413 (3)
//         0053bafc     MOV        dword ptr [EBP + found],EBX
//                              Symbol Ref: No symbol: next_entry
//                               LAB_0053baff                                                 XREF[6]:     0053ba62(j), 0053ba70(j),
//                                                                                                         0053ba90(j), 0053ba9a(j),
//                                                                                                         0053babe(j), 0053bad8(j)
//                              vis_unit.cpp:416 (3)
//         0053baff     ADD        ESI,0x8
//                              vis_unit.cpp:417 (3)
//         0053bb02     DEC        dword ptr [EBP + count]
//                              vis_unit.cpp:418 (6)
//         0053bb05     JNZ        LAB_0053ba57
//                              Symbol Ref: No symbol: empty_list
//                               LAB_0053bb0b                                                 XREF[1]:     0053ba4e(j)
//                              vis_unit.cpp:423 (3)
//         0053bb0b     DEC        dword ptr [EBP + param_6]
//                              vis_unit.cpp:424 (6)
//         0053bb0e     JNZ        LAB_0053ba32
//                              vis_unit.cpp:426 (1)
//         0053bb14     POP        EDI
//                              vis_unit.cpp:427 (1)
//         0053bb15     POP        ESI
//                              vis_unit.cpp:428 (1)
//         0053bb16     POP        EBX
//                              vis_unit.cpp:432 (3)
//         0053bb17     MOV        EAX,dword ptr [EBP + found]
//                              vis_unit.cpp:434 (9)
//         0053bb1a     POP        EDI
//         0053bb1b     POP        ESI
//         0053bb1c     POP        EBX
//         0053bb1d     MOV        ESP,EBP
//         0053bb1f     POP        EBP
//         0053bb20     RET        0x1c
//         0053bb23     ??         90h
//         0053bb24     NOP
//         0053bb25     NOP
//         0053bb26     NOP
//         0053bb27     NOP
//         0053bb28     NOP
//         0053bb29     NOP
//         0053bb2a     NOP
//         0053bb2b     NOP
//         0053bb2c     NOP
//         0053bb2d     NOP
//         0053bb2e     NOP
//         0053bb2f     NOP
    return 0;
}

Visible_Resource_Manager::Visible_Resource_Manager(RGE_Player* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall Visible_Resource_Manager(Visible_Resource_Manag
//              undefined         <UNASSIGNED>   <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0053bbfc(R), 0053bc0e(R), 0053bc5f(R), 0053bc78(R),
//                                                                                     0053bcac(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     0053bce2(R), 0053bcfa(R)
//                               ??0Visible_Resource_Manager@@QAE@HPAVRGE_Player@@@Z          XREF[2]:     load:0046fb56(c),
//                               Visible_Resource_Manager::Visible_Resource_Manager                        load:00512996(c)
//                              vis_unit.cpp:477 (20)
//         0053bbe0     FLD        float ptr [save_game_version]                    = 7.23
//         0053bbe6     FCOMP      float ptr [DAT_005776c8]                         = 1Fh
//         0053bbec     PUSH       EBX
//         0053bbed     PUSH       EBP
//         0053bbee     PUSH       ESI
//         0053bbef     MOV        ESI,this
//         0053bbf1     PUSH       EDI
//         0053bbf2     FNSTSW     AX
//                              vis_unit.cpp:484 (24)
//         0053bbf4     LEA        EBP,[ESI + 0x10]
//         0053bbf7     TEST       AH,0x1
//         0053bbfa     JNZ        LAB_0053bc0e
//         0053bbfc     MOV        EDI,dword ptr [ESP + param_1]
//         0053bc00     PUSH       0x4
//         0053bc02     PUSH       EBP
//         0053bc03     PUSH       EDI
//         0053bc04     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bc09     ADD        ESP,0xc
//                              vis_unit.cpp:486 (2)
//         0053bc0c     JMP        LAB_0053bc19
//                               LAB_0053bc0e                                                 XREF[1]:     0053bbfa(j)
//                              vis_unit.cpp:488 (11)
//         0053bc0e     MOV        EDI,dword ptr [ESP + param_1]
//         0053bc12     MOV        dword ptr [EBP],0x5
//                               LAB_0053bc19                                                 XREF[1]:     0053bc0c(j)
//                              vis_unit.cpp:491 (13)
//         0053bc19     MOV        EAX,dword ptr [EBP]
//         0053bc1c     XOR        EBX,EBX
//         0053bc1e     CMP        EAX,EBX
//         0053bc20     JLE        LAB_0053bcf2
//                              vis_unit.cpp:493 (13)
//         0053bc26     PUSH       0x4
//         0053bc28     PUSH       EAX
//         0053bc29     CALL       calloc                                           undefined calloc()
//         0053bc2e     ADD        ESP,0x8
//         0053bc31     MOV        dword ptr [ESI],EAX
//                              vis_unit.cpp:494 (11)
//         0053bc33     MOV        EAX,dword ptr [EBP]
//         0053bc36     PUSH       0x4
//         0053bc38     PUSH       EAX
//         0053bc39     CALL       calloc                                           undefined calloc()
//                              vis_unit.cpp:495 (20)
//         0053bc3e     MOV        this,dword ptr [EBP]
//         0053bc41     ADD        ESP,0x8
//         0053bc44     MOV        dword ptr [ESI + 0x4],EAX
//         0053bc47     PUSH       0x4
//         0053bc49     PUSH       this
//         0053bc4a     CALL       calloc                                           undefined calloc()
//         0053bc4f     MOV        dword ptr [ESI + 0x8],EAX
//                              vis_unit.cpp:497 (13)
//         0053bc52     MOV        EAX,dword ptr [EBP]
//         0053bc55     ADD        ESP,0x8
//         0053bc58     TEST       EAX,EAX
//         0053bc5a     JLE        LAB_0053bcb0
//                               LAB_0053bc5c                                                 XREF[1]:     0053bcaa(j)
//         0053bc5c     MOV        EDX,dword ptr [ESI + 0x4]
//                              vis_unit.cpp:499 (25)
//         0053bc5f     MOV        EAX,dword ptr [ESP + param_1]
//         0053bc63     LEA        EDI,[EBX*0x4 + 0x0]
//         0053bc6a     PUSH       0x4
//         0053bc6c     ADD        EDX,EDI
//         0053bc6e     PUSH       EDX
//         0053bc6f     PUSH       EAX
//         0053bc70     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bc75     MOV        this,dword ptr [ESI + 0x8]
//                              vis_unit.cpp:500 (18)
//         0053bc78     MOV        EDX,dword ptr [ESP + param_1]
//         0053bc7c     ADD        ESP,0xc
//         0053bc7f     ADD        this,EDI
//         0053bc81     PUSH       0x4
//         0053bc83     PUSH       this
//         0053bc84     PUSH       EDX
//         0053bc85     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              vis_unit.cpp:501 (34)
//         0053bc8a     MOV        EAX,dword ptr [ESI + 0x4]
//         0053bc8d     ADD        ESP,0xc
//         0053bc90     MOV        this,dword ptr [EAX + EDI*0x1]
//         0053bc93     SHL        this,0x3
//         0053bc96     PUSH       this
//         0053bc97     CALL       malloc                                           undefined malloc()
//         0053bc9c     MOV        EDX,dword ptr [ESI]
//         0053bc9e     ADD        ESP,0x4
//         0053bca1     INC        EBX
//         0053bca2     MOV        dword ptr [EDX + EDI*0x1],EAX
//         0053bca5     MOV        EAX,dword ptr [EBP]
//         0053bca8     CMP        EBX,EAX
//         0053bcaa     JL         LAB_0053bc5c
//                              vis_unit.cpp:497 (4)
//         0053bcac     MOV        EDI,dword ptr [ESP + param_1]
//                               LAB_0053bcb0                                                 XREF[1]:     0053bc5a(j)
//                              vis_unit.cpp:504 (9)
//         0053bcb0     MOV        EAX,dword ptr [EBP]
//         0053bcb3     XOR        EBX,EBX
//         0053bcb5     TEST       EAX,EAX
//         0053bcb7     JLE        LAB_0053bcfa
//                               LAB_0053bcb9                                                 XREF[1]:     0053bce0(j)
//                              vis_unit.cpp:506 (10)
//         0053bcb9     MOV        EAX,dword ptr [ESI + 0x8]
//         0053bcbc     MOV        EAX,dword ptr [EAX + EBX*0x4]
//         0053bcbf     TEST       EAX,EAX
//         0053bcc1     JLE        LAB_0053bcda
//                              vis_unit.cpp:507 (31)
//         0053bcc3     MOV        EDX,dword ptr [ESI]
//         0053bcc5     LEA        this,[EAX*0x8 + 0x0]
//         0053bccc     PUSH       this
//         0053bccd     MOV        EAX,dword ptr [EDX + EBX*0x4]
//         0053bcd0     PUSH       EAX
//         0053bcd1     PUSH       EDI
//         0053bcd2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bcd7     ADD        ESP,0xc
//                               LAB_0053bcda                                                 XREF[1]:     0053bcc1(j)
//         0053bcda     MOV        EAX,dword ptr [EBP]
//         0053bcdd     INC        EBX
//         0053bcde     CMP        EBX,EAX
//         0053bce0     JL         LAB_0053bcb9
//                              vis_unit.cpp:517 (4)
//         0053bce2     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:518 (12)
//         0053bce6     MOV        EAX,ESI
//         0053bce8     MOV        dword ptr [ESI + 0xc],this
//         0053bceb     POP        EDI
//         0053bcec     POP        ESI
//         0053bced     POP        EBP
//         0053bcee     POP        EBX
//         0053bcef     RET        0x8
//                               LAB_0053bcf2                                                 XREF[1]:     0053bc20(j)
//                              vis_unit.cpp:512 (2)
//         0053bcf2     MOV        dword ptr [ESI],EBX
//                              vis_unit.cpp:513 (3)
//         0053bcf4     MOV        dword ptr [ESI + 0x4],EBX
//                              vis_unit.cpp:514 (3)
//         0053bcf7     MOV        dword ptr [ESI + 0x8],EBX
//                               LAB_0053bcfa                                                 XREF[1]:     0053bcb7(j)
//                              vis_unit.cpp:517 (4)
//         0053bcfa     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:518 (12)
//         0053bcfe     MOV        EAX,ESI
//         0053bd00     MOV        dword ptr [ESI + 0xc],this
//         0053bd03     POP        EDI
//         0053bd04     POP        ESI
//         0053bd05     POP        EBP
//         0053bd06     POP        EBX
//         0053bd07     RET        0x8
//         0053bd0a     ??         90h
//         0053bd0b     NOP
//         0053bd0c     NOP
//         0053bd0d     NOP
//         0053bd0e     NOP
//         0053bd0f     NOP
}

Visible_Resource_Manager::Visible_Resource_Manager(int param_1, RGE_Player* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall Visible_Resource_Manager(Visible_Resource_Manag
//              undefined         <UNASSIGNED>   <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0053bbfc(R), 0053bc0e(R), 0053bc5f(R), 0053bc78(R),
//                                                                                     0053bcac(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     0053bce2(R), 0053bcfa(R)
//                               ??0Visible_Resource_Manager@@QAE@HPAVRGE_Player@@@Z          XREF[2]:     load:0046fb56(c),
//                               Visible_Resource_Manager::Visible_Resource_Manager                        load:00512996(c)
//                              vis_unit.cpp:477 (20)
//         0053bbe0     FLD        float ptr [save_game_version]                    = 7.23
//         0053bbe6     FCOMP      float ptr [DAT_005776c8]                         = 1Fh
//         0053bbec     PUSH       EBX
//         0053bbed     PUSH       EBP
//         0053bbee     PUSH       ESI
//         0053bbef     MOV        ESI,this
//         0053bbf1     PUSH       EDI
//         0053bbf2     FNSTSW     AX
//                              vis_unit.cpp:484 (24)
//         0053bbf4     LEA        EBP,[ESI + 0x10]
//         0053bbf7     TEST       AH,0x1
//         0053bbfa     JNZ        LAB_0053bc0e
//         0053bbfc     MOV        EDI,dword ptr [ESP + param_1]
//         0053bc00     PUSH       0x4
//         0053bc02     PUSH       EBP
//         0053bc03     PUSH       EDI
//         0053bc04     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bc09     ADD        ESP,0xc
//                              vis_unit.cpp:486 (2)
//         0053bc0c     JMP        LAB_0053bc19
//                               LAB_0053bc0e                                                 XREF[1]:     0053bbfa(j)
//                              vis_unit.cpp:488 (11)
//         0053bc0e     MOV        EDI,dword ptr [ESP + param_1]
//         0053bc12     MOV        dword ptr [EBP],0x5
//                               LAB_0053bc19                                                 XREF[1]:     0053bc0c(j)
//                              vis_unit.cpp:491 (13)
//         0053bc19     MOV        EAX,dword ptr [EBP]
//         0053bc1c     XOR        EBX,EBX
//         0053bc1e     CMP        EAX,EBX
//         0053bc20     JLE        LAB_0053bcf2
//                              vis_unit.cpp:493 (13)
//         0053bc26     PUSH       0x4
//         0053bc28     PUSH       EAX
//         0053bc29     CALL       calloc                                           undefined calloc()
//         0053bc2e     ADD        ESP,0x8
//         0053bc31     MOV        dword ptr [ESI],EAX
//                              vis_unit.cpp:494 (11)
//         0053bc33     MOV        EAX,dword ptr [EBP]
//         0053bc36     PUSH       0x4
//         0053bc38     PUSH       EAX
//         0053bc39     CALL       calloc                                           undefined calloc()
//                              vis_unit.cpp:495 (20)
//         0053bc3e     MOV        this,dword ptr [EBP]
//         0053bc41     ADD        ESP,0x8
//         0053bc44     MOV        dword ptr [ESI + 0x4],EAX
//         0053bc47     PUSH       0x4
//         0053bc49     PUSH       this
//         0053bc4a     CALL       calloc                                           undefined calloc()
//         0053bc4f     MOV        dword ptr [ESI + 0x8],EAX
//                              vis_unit.cpp:497 (13)
//         0053bc52     MOV        EAX,dword ptr [EBP]
//         0053bc55     ADD        ESP,0x8
//         0053bc58     TEST       EAX,EAX
//         0053bc5a     JLE        LAB_0053bcb0
//                               LAB_0053bc5c                                                 XREF[1]:     0053bcaa(j)
//         0053bc5c     MOV        EDX,dword ptr [ESI + 0x4]
//                              vis_unit.cpp:499 (25)
//         0053bc5f     MOV        EAX,dword ptr [ESP + param_1]
//         0053bc63     LEA        EDI,[EBX*0x4 + 0x0]
//         0053bc6a     PUSH       0x4
//         0053bc6c     ADD        EDX,EDI
//         0053bc6e     PUSH       EDX
//         0053bc6f     PUSH       EAX
//         0053bc70     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bc75     MOV        this,dword ptr [ESI + 0x8]
//                              vis_unit.cpp:500 (18)
//         0053bc78     MOV        EDX,dword ptr [ESP + param_1]
//         0053bc7c     ADD        ESP,0xc
//         0053bc7f     ADD        this,EDI
//         0053bc81     PUSH       0x4
//         0053bc83     PUSH       this
//         0053bc84     PUSH       EDX
//         0053bc85     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              vis_unit.cpp:501 (34)
//         0053bc8a     MOV        EAX,dword ptr [ESI + 0x4]
//         0053bc8d     ADD        ESP,0xc
//         0053bc90     MOV        this,dword ptr [EAX + EDI*0x1]
//         0053bc93     SHL        this,0x3
//         0053bc96     PUSH       this
//         0053bc97     CALL       malloc                                           undefined malloc()
//         0053bc9c     MOV        EDX,dword ptr [ESI]
//         0053bc9e     ADD        ESP,0x4
//         0053bca1     INC        EBX
//         0053bca2     MOV        dword ptr [EDX + EDI*0x1],EAX
//         0053bca5     MOV        EAX,dword ptr [EBP]
//         0053bca8     CMP        EBX,EAX
//         0053bcaa     JL         LAB_0053bc5c
//                              vis_unit.cpp:497 (4)
//         0053bcac     MOV        EDI,dword ptr [ESP + param_1]
//                               LAB_0053bcb0                                                 XREF[1]:     0053bc5a(j)
//                              vis_unit.cpp:504 (9)
//         0053bcb0     MOV        EAX,dword ptr [EBP]
//         0053bcb3     XOR        EBX,EBX
//         0053bcb5     TEST       EAX,EAX
//         0053bcb7     JLE        LAB_0053bcfa
//                               LAB_0053bcb9                                                 XREF[1]:     0053bce0(j)
//                              vis_unit.cpp:506 (10)
//         0053bcb9     MOV        EAX,dword ptr [ESI + 0x8]
//         0053bcbc     MOV        EAX,dword ptr [EAX + EBX*0x4]
//         0053bcbf     TEST       EAX,EAX
//         0053bcc1     JLE        LAB_0053bcda
//                              vis_unit.cpp:507 (31)
//         0053bcc3     MOV        EDX,dword ptr [ESI]
//         0053bcc5     LEA        this,[EAX*0x8 + 0x0]
//         0053bccc     PUSH       this
//         0053bccd     MOV        EAX,dword ptr [EDX + EBX*0x4]
//         0053bcd0     PUSH       EAX
//         0053bcd1     PUSH       EDI
//         0053bcd2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0053bcd7     ADD        ESP,0xc
//                               LAB_0053bcda                                                 XREF[1]:     0053bcc1(j)
//         0053bcda     MOV        EAX,dword ptr [EBP]
//         0053bcdd     INC        EBX
//         0053bcde     CMP        EBX,EAX
//         0053bce0     JL         LAB_0053bcb9
//                              vis_unit.cpp:517 (4)
//         0053bce2     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:518 (12)
//         0053bce6     MOV        EAX,ESI
//         0053bce8     MOV        dword ptr [ESI + 0xc],this
//         0053bceb     POP        EDI
//         0053bcec     POP        ESI
//         0053bced     POP        EBP
//         0053bcee     POP        EBX
//         0053bcef     RET        0x8
//                               LAB_0053bcf2                                                 XREF[1]:     0053bc20(j)
//                              vis_unit.cpp:512 (2)
//         0053bcf2     MOV        dword ptr [ESI],EBX
//                              vis_unit.cpp:513 (3)
//         0053bcf4     MOV        dword ptr [ESI + 0x4],EBX
//                              vis_unit.cpp:514 (3)
//         0053bcf7     MOV        dword ptr [ESI + 0x8],EBX
//                               LAB_0053bcfa                                                 XREF[1]:     0053bcb7(j)
//                              vis_unit.cpp:517 (4)
//         0053bcfa     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:518 (12)
//         0053bcfe     MOV        EAX,ESI
//         0053bd00     MOV        dword ptr [ESI + 0xc],this
//         0053bd03     POP        EDI
//         0053bd04     POP        ESI
//         0053bd05     POP        EBP
//         0053bd06     POP        EBX
//         0053bd07     RET        0x8
//         0053bd0a     ??         90h
//         0053bd0b     NOP
//         0053bd0c     NOP
//         0053bd0d     NOP
//         0053bd0e     NOP
//         0053bd0f     NOP
}

Visible_Resource_Manager::~Visible_Resource_Manager() {
    /* TODO: Stub */
//                              void __thiscall ~Visible_Resource_Manager(Visible_Resource_Manager *
//              void              <VOID>         <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//                               ??1Visible_Resource_Manager@@QAE@XZ                          XREF[1]:     ~RGE_Player:0046ec17(c)
//                               Visible_Resource_Manager::~Visible_Resource_Manager
//                              vis_unit.cpp:521 (4)
//         0053bd10     PUSH       ESI
//         0053bd11     MOV        ESI,this
//         0053bd13     PUSH       EDI
//                              vis_unit.cpp:524 (9)
//         0053bd14     XOR        EDI,EDI
//         0053bd16     MOV        EAX,dword ptr [ESI + 0x10]
//         0053bd19     TEST       EAX,EAX
//         0053bd1b     JLE        LAB_0053bd37
//                               LAB_0053bd1d                                                 XREF[1]:     0053bd35(j)
//                              vis_unit.cpp:526 (26)
//         0053bd1d     MOV        EAX,dword ptr [ESI]
//         0053bd1f     MOV        EAX,dword ptr [EAX + EDI*0x4]
//         0053bd22     TEST       EAX,EAX
//         0053bd24     JZ         LAB_0053bd2f
//         0053bd26     PUSH       EAX
//         0053bd27     CALL       free                                             undefined free()
//         0053bd2c     ADD        ESP,0x4
//                               LAB_0053bd2f                                                 XREF[1]:     0053bd24(j)
//         0053bd2f     MOV        EAX,dword ptr [ESI + 0x10]
//         0053bd32     INC        EDI
//         0053bd33     CMP        EDI,EAX
//         0053bd35     JL         LAB_0053bd1d
//                               LAB_0053bd37                                                 XREF[1]:     0053bd1b(j)
//                              vis_unit.cpp:529 (15)
//         0053bd37     MOV        EAX,dword ptr [ESI]
//         0053bd39     TEST       EAX,EAX
//         0053bd3b     JZ         LAB_0053bd46
//         0053bd3d     PUSH       EAX
//         0053bd3e     CALL       free                                             undefined free()
//         0053bd43     ADD        ESP,0x4
//                               LAB_0053bd46                                                 XREF[1]:     0053bd3b(j)
//                              vis_unit.cpp:530 (16)
//         0053bd46     MOV        EAX,dword ptr [ESI + 0x4]
//         0053bd49     TEST       EAX,EAX
//         0053bd4b     JZ         LAB_0053bd56
//         0053bd4d     PUSH       EAX
//         0053bd4e     CALL       free                                             undefined free()
//         0053bd53     ADD        ESP,0x4
//                               LAB_0053bd56                                                 XREF[1]:     0053bd4b(j)
//                              vis_unit.cpp:531 (16)
//         0053bd56     MOV        ESI,dword ptr [ESI + 0x8]
//         0053bd59     TEST       ESI,ESI
//         0053bd5b     JZ         LAB_0053bd66
//         0053bd5d     PUSH       ESI
//         0053bd5e     CALL       free                                             undefined free()
//         0053bd63     ADD        ESP,0x4
//                               LAB_0053bd66                                                 XREF[1]:     0053bd5b(j)
//                              vis_unit.cpp:533 (3)
//         0053bd66     POP        EDI
//         0053bd67     POP        ESI
//         0053bd68     RET
//         0053bd69     ??         90h
//         0053bd6a     NOP
//         0053bd6b     NOP
//         0053bd6c     NOP
//         0053bd6d     NOP
//         0053bd6e     NOP
//         0053bd6f     NOP
}

void Visible_Resource_Manager::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(Visible_Resource_Manager * this, int param_1)
//              void              <VOID>         <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053bd72(R)
//                               ?save@Visible_Resource_Manager@@QAEXH@Z                      XREF[1]:     save2:00470427(c)
//                               Visible_Resource_Manager::save
//                              vis_unit.cpp:537 (2)
//         0053bd70     PUSH       EBX
//         0053bd71     PUSH       EBP
//                              vis_unit.cpp:540 (20)
//         0053bd72     MOV        EBP,dword ptr [ESP + param_1]
//         0053bd76     PUSH       ESI
//         0053bd77     MOV        ESI,this
//         0053bd79     PUSH       EDI
//         0053bd7a     PUSH       0x4
//         0053bd7c     LEA        EBX,[ESI + 0x10]
//         0053bd7f     PUSH       EBX
//         0053bd80     PUSH       EBP
//         0053bd81     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              vis_unit.cpp:542 (23)
//         0053bd86     MOV        EAX,dword ptr [EBX]
//         0053bd88     ADD        ESP,0xc
//         0053bd8b     XOR        EDI,EDI
//         0053bd8d     TEST       EAX,EAX
//         0053bd8f     JLE        LAB_0053bdc2
//                               LAB_0053bd91                                                 XREF[1]:     0053bdc0(j)
//         0053bd91     MOV        EAX,dword ptr [ESI + 0x4]
//         0053bd94     LEA        EBX,[EDI*0x4 + 0x0]
//         0053bd9b     ADD        EAX,EBX
//                              vis_unit.cpp:544 (17)
//         0053bd9d     PUSH       0x4
//         0053bd9f     PUSH       EAX
//         0053bda0     PUSH       EBP
//         0053bda1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0053bda6     MOV        this,dword ptr [ESI + 0x8]
//         0053bda9     ADD        ESP,0xc
//         0053bdac     ADD        this,EBX
//                              vis_unit.cpp:545 (20)
//         0053bdae     PUSH       0x4
//         0053bdb0     PUSH       this
//         0053bdb1     PUSH       EBP
//         0053bdb2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0053bdb7     MOV        EAX,dword ptr [ESI + 0x10]
//         0053bdba     ADD        ESP,0xc
//         0053bdbd     INC        EDI
//         0053bdbe     CMP        EDI,EAX
//         0053bdc0     JL         LAB_0053bd91
//                               LAB_0053bdc2                                                 XREF[1]:     0053bd8f(j)
//                              vis_unit.cpp:548 (9)
//         0053bdc2     MOV        EAX,dword ptr [ESI + 0x10]
//         0053bdc5     XOR        EDI,EDI
//         0053bdc7     TEST       EAX,EAX
//         0053bdc9     JLE        LAB_0053bdf0
//                               LAB_0053bdcb                                                 XREF[1]:     0053bdee(j)
//                              vis_unit.cpp:550 (10)
//         0053bdcb     MOV        EDX,dword ptr [ESI + 0x8]
//         0053bdce     MOV        EAX,dword ptr [EDX + EDI*0x4]
//         0053bdd1     TEST       EAX,EAX
//         0053bdd3     JLE        LAB_0053bde8
//                              vis_unit.cpp:551 (27)
//         0053bdd5     MOV        this,dword ptr [ESI]
//         0053bdd7     SHL        EAX,0x3
//         0053bdda     MOV        EDX,dword ptr [this->VR_List + EDI*0x4]
//         0053bddd     PUSH       EAX
//         0053bdde     PUSH       EDX
//         0053bddf     PUSH       EBP
//         0053bde0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0053bde5     ADD        ESP,0xc
//                               LAB_0053bde8                                                 XREF[1]:     0053bdd3(j)
//         0053bde8     MOV        EAX,dword ptr [ESI + 0x10]
//         0053bdeb     INC        EDI
//         0053bdec     CMP        EDI,EAX
//         0053bdee     JL         LAB_0053bdcb
//                               LAB_0053bdf0                                                 XREF[1]:     0053bdc9(j)
//                              vis_unit.cpp:554 (7)
//         0053bdf0     POP        EDI
//         0053bdf1     POP        ESI
//         0053bdf2     POP        EBP
//         0053bdf3     POP        EBX
//         0053bdf4     RET        0x4
//         0053bdf7     ??         90h
//         0053bdf8     NOP
//         0053bdf9     NOP
//         0053bdfa     NOP
//         0053bdfb     NOP
//         0053bdfc     NOP
//         0053bdfd     NOP
//         0053bdfe     NOP
//         0053bdff     NOP
    return;
}

void Visible_Resource_Manager::Process_New_Tiles(RGE_Tile_List* param_1) {
    /* TODO: Stub */
//                              void __thiscall Process_New_Tiles(Visible_Resource_Manager * this, R
//              void              <VOID>         <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              RGE_Tile_List *   Stack[0x4]:4   param_1                   XREF[5]:     0053be0c(*), 0053be11(*), 0053be4c(R), 0053bea5(R),
//                                                                                     0053beb3(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053be44(W), 0053be50(R)
//              RGE_Tile * *      Stack[-0x8]:4  TileOffsets               XREF[3]:     0053be03(*), 0053be1a(R), 0053bea9(R)
//              int               Stack[-0xc]:4  size
//                               ?Process_New_Tiles@Visible_Resource_Manager@@QAEXPAVRGE_Til  XREF[1]:     update:0047016f(c)
//                               Visible_Resource_Manager::Process_New_Tiles
//                              vis_unit.cpp:559 (3)
//         0053be00     SUB        ESP,0x8
//                              vis_unit.cpp:569 (23)
//         0053be03     LEA        EAX=>TileOffsets,[ESP]
//         0053be07     PUSH       EBX
//         0053be08     PUSH       EBP
//         0053be09     MOV        EBP,this
//         0053be0b     PUSH       EAX
//         0053be0c     LEA        this=>param_1,[ESP + 0x18]
//         0053be10     PUSH       this
//         0053be11     MOV        this=>param_1,dword ptr [ESP + 0x1c]
//         0053be15     CALL       RGE_Tile_List::get_list_info                     void get_list_info(RGE_Tile_List * this, RGE_
//                              vis_unit.cpp:571 (12)
//         0053be1a     MOV        EAX,dword ptr [ESP + TileOffsets]
//         0053be1e     TEST       EAX,EAX
//         0053be20     JLE        LAB_0053bebb
//                              vis_unit.cpp:572 (11)
//         0053be26     MOV        this,dword ptr [EBP + 0x10]
//         0053be29     TEST       this,this
//         0053be2b     JZ         LAB_0053bebb
//                              vis_unit.cpp:576 (3)
//         0053be31     MOV        EDX,dword ptr [EBP + 0xc]
//                              vis_unit.cpp:580 (24)
//         0053be34     XOR        EBX,EBX
//         0053be36     TEST       EAX,EAX
//         0053be38     MOV        this,dword ptr [EDX + 0x3c]
//         0053be3b     MOV        EDX,dword ptr [this->VR_List + 0x28]
//         0053be3e     MOV        this,dword ptr [EDX + 0x8d8c]
//         0053be44     MOV        dword ptr [ESP + local_4],this
//         0053be48     JLE        LAB_0053bebb
//         0053be4a     PUSH       EDI
//         0053be4b     PUSH       ESI
//                               LAB_0053be4c                                                 XREF[1]:     0053beb7(j)
//                              vis_unit.cpp:585 (19)
//         0053be4c     MOV        EAX,dword ptr [ESP + param_1]
//         0053be50     MOV        this,dword ptr [ESP + local_4]
//         0053be54     MOV        EDX,dword ptr [EAX + 0x4]
//         0053be57     MOV        EAX,dword ptr [EAX]
//         0053be59     MOV        EDX,dword ptr [this->VR_List + EDX*0x4]
//         0053be5c     LEA        EAX,[EAX + EAX*0x2]
//                              vis_unit.cpp:589 (8)
//         0053be5f     MOVSX      EDI,word ptr [EDX + EAX*0x8 + 0x14]
//         0053be64     LEA        EAX,[EDX + EAX*0x8]
//                              vis_unit.cpp:590 (4)
//         0053be67     TEST       EDI,EDI
//         0053be69     JLE        LAB_0053bea5
//                              vis_unit.cpp:592 (3)
//         0053be6b     MOV        ESI,dword ptr [EAX + 0x10]
//                              vis_unit.cpp:594 (8)
//         0053be6e     TEST       ESI,ESI
//         0053be70     JZ         LAB_0053bea5
//                               LAB_0053be72                                                 XREF[1]:     0053bea3(j)
//         0053be72     TEST       EDI,EDI
//         0053be74     JLE        LAB_0053bea5
//                              vis_unit.cpp:596 (2)
//         0053be76     MOV        EAX,dword ptr [ESI]
//                              vis_unit.cpp:597 (4)
//         0053be78     TEST       EAX,EAX
//         0053be7a     JZ         LAB_0053be9d
//                              vis_unit.cpp:599 (13)
//         0053be7c     MOV        this,dword ptr [EAX + 0x8]
//         0053be7f     MOV        DL,byte ptr [this->VR_List + 0xa5]
//         0053be85     TEST       DL,DL
//         0053be87     JZ         LAB_0053be9d
//                              vis_unit.cpp:601 (20)
//         0053be89     MOV        EAX,dword ptr [EAX + 0x4]
//         0053be8c     XOR        EDX,EDX
//         0053be8e     MOV        DL,byte ptr [this->VR_List + 0xa7]
//         0053be94     MOV        this,EBP
//         0053be96     PUSH       EDX
//         0053be97     PUSH       EAX
//         0053be98     CALL       Visible_Resource_Manager::AddResource            void AddResource(Visible_Resource_Manager * t
//                               LAB_0053be9d                                                 XREF[2]:     0053be7a(j), 0053be87(j)
//                              vis_unit.cpp:605 (3)
//         0053be9d     MOV        ESI,dword ptr [ESI + 0x4]
//                              vis_unit.cpp:606 (5)
//         0053bea0     DEC        EDI
//         0053bea1     TEST       ESI,ESI
//         0053bea3     JNZ        LAB_0053be72
//                               LAB_0053bea5                                                 XREF[3]:     0053be69(j), 0053be70(j),
//                                                                                                         0053be74(j)
//                              vis_unit.cpp:580 (22)
//         0053bea5     MOV        this,dword ptr [ESP + param_1]
//         0053bea9     MOV        EAX,dword ptr [ESP + TileOffsets]
//         0053bead     INC        EBX
//         0053beae     ADD        this,0x8
//         0053beb1     CMP        EBX,EAX
//         0053beb3     MOV        dword ptr [ESP + param_1],this
//         0053beb7     JL         LAB_0053be4c
//         0053beb9     POP        ESI
//         0053beba     POP        EDI
//                               LAB_0053bebb                                                 XREF[3]:     0053be20(j), 0053be2b(j),
//                                                                                                         0053be48(j)
//                              vis_unit.cpp:611 (8)
//         0053bebb     POP        EBP
//         0053bebc     POP        EBX
//         0053bebd     ADD        ESP,0x8
//         0053bec0     RET        0x4
//         0053bec3     ??         90h
//         0053bec4     NOP
//         0053bec5     NOP
//         0053bec6     NOP
//         0053bec7     NOP
//         0053bec8     NOP
//         0053bec9     NOP
//         0053beca     NOP
//         0053becb     NOP
//         0053becc     NOP
//         0053becd     NOP
//         0053bece     NOP
//         0053becf     NOP
    return;
}

void Visible_Resource_Manager::AddResource(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall AddResource(Visible_Resource_Manager * this, int par
//              void              <VOID>         <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     0053bee7(R), 0053bf96(R)
//              int               Stack[0x8]:4   param_2                   XREF[5]:     0053befa(R), 0053bf2f(W), 0053bf5c(R), 0053bf8d(W),
//                                                                                     0053bf9a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053bef0(W), 0053bf60(R)
//              RGE_Static_Obj    Stack[-0x8]:4  o                         XREF[2]:     0053bf19(W), 0053bf6d(R)
//              int               Stack[-0xc]:4  n
//                               ?AddResource@Visible_Resource_Manager@@QAEXHH@Z              XREF[1]:     Process_New_Tiles:0053be98(c)
//                               Visible_Resource_Manager::AddResource
//                              vis_unit.cpp:616 (7)
//         0053bed0     SUB        ESP,0x8
//         0053bed3     PUSH       EBX
//         0053bed4     MOV        EBX,this
//         0053bed6     PUSH       EDI
//                              vis_unit.cpp:624 (11)
//         0053bed7     MOV        EAX,dword ptr [EBX + 0x10]
//         0053beda     TEST       EAX,EAX
//         0053bedc     JZ         LAB_0053bfbc
//                              vis_unit.cpp:632 (12)
//         0053bee2     MOV        EAX,[VIS_UNIT_objectsValue]                      = 00000000
//         0053bee7     MOV        this,dword ptr [ESP + param_1]
//         0053beeb     MOV        EDI,dword ptr [EAX + this->VR_List*0x4]
//                              vis_unit.cpp:634 (12)
//         0053beee     TEST       EDI,EDI
//         0053bef0     MOV        dword ptr [ESP + local_4],EDI
//         0053bef4     JZ         LAB_0053bfbc
//                              vis_unit.cpp:638 (29)
//         0053befa     MOV        EDX,dword ptr [ESP + param_2]
//         0053befe     MOV        EAX,dword ptr [EBX + 0x4]
//         0053bf01     MOV        this,dword ptr [EBX + 0x8]
//         0053bf04     PUSH       ESI
//         0053bf05     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         0053bf08     PUSH       EBP
//         0053bf09     LEA        EBP,[EDX*0x4 + 0x0]
//         0053bf10     MOV        EDX,dword ptr [this->VR_List + EDX*0x4]
//         0053bf13     CMP        EDX,EAX
//         0053bf15     JNZ        LAB_0053bf74
//                              vis_unit.cpp:640 (6)
//         0053bf17     ADD        EAX,EAX
//         0053bf19     MOV        dword ptr [ESP + o],EAX
//                              vis_unit.cpp:642 (13)
//         0053bf1d     LEA        EDX,[EAX*0x8 + 0x0]
//         0053bf24     PUSH       EDX
//         0053bf25     CALL       malloc                                           undefined malloc()
//                              vis_unit.cpp:643 (37)
//         0053bf2a     MOV        this,dword ptr [EBX + 0x4]
//         0053bf2d     MOV        EDX,dword ptr [EBX]
//         0053bf2f     MOV        dword ptr [ESP + param_2],EAX
//         0053bf33     MOV        EDI,EAX
//         0053bf35     MOV        this,dword ptr [this->VR_List + EBP*0x1]
//         0053bf38     MOV        ESI,dword ptr [EDX + EBP*0x1]
//         0053bf3b     SHL        this,0x3
//         0053bf3e     MOV        EAX,this
//         0053bf40     ADD        ESP,0x4
//         0053bf43     SHR        this,0x2
//         0053bf46     MOVSD.REP  ES:EDI,ESI
//         0053bf48     MOV        this,EAX
//         0053bf4a     AND        this,0x3
//         0053bf4d     MOVSB.REP  ES:EDI,ESI
//                              vis_unit.cpp:644 (11)
//         0053bf4f     MOV        this,dword ptr [EBX]
//         0053bf51     MOV        EDX,dword ptr [this->VR_List + EBP*0x1]
//         0053bf54     PUSH       EDX
//         0053bf55     CALL       free                                             undefined free()
//                              vis_unit.cpp:645 (6)
//         0053bf5a     MOV        EAX,dword ptr [EBX]
//         0053bf5c     MOV        this,dword ptr [ESP + param_2]
//                              vis_unit.cpp:646 (20)
//         0053bf60     MOV        EDI,dword ptr [ESP + local_4]
//         0053bf64     ADD        ESP,0x4
//         0053bf67     MOV        dword ptr [EAX + EBP*0x1],this
//         0053bf6a     MOV        EDX,dword ptr [EBX + 0x4]
//         0053bf6d     MOV        EAX,dword ptr [ESP + o]
//         0053bf71     MOV        dword ptr [EDX + EBP*0x1],EAX
//                               LAB_0053bf74                                                 XREF[1]:     0053bf15(j)
//                              vis_unit.cpp:651 (5)
//         0053bf74     MOV        this,dword ptr [EBX]
//         0053bf76     MOV        EDX,dword ptr [EBX + 0x8]
//                              vis_unit.cpp:653 (17)
//         0053bf79     FLD        float ptr [EDI + 0x38]
//         0053bf7c     MOV        EAX,dword ptr [EDX + EBP*0x1]
//         0053bf7f     MOV        this,dword ptr [this->VR_List + EBP*0x1]
//         0053bf82     LEA        ESI,[this->VR_List + EAX*0x8]
//         0053bf85     CALL       __ftol                                           undefined __ftol()
//                              vis_unit.cpp:654 (12)
//         0053bf8a     FLD        float ptr [EDI + 0x3c]
//         0053bf8d     MOV        dword ptr [ESP + param_2],EAX
//         0053bf91     CALL       __ftol                                           undefined __ftol()
//                              vis_unit.cpp:656 (4)
//         0053bf96     MOV        EDX,dword ptr [ESP + param_1]
//                              vis_unit.cpp:659 (17)
//         0053bf9a     MOV        this,byte ptr [ESP + param_2]
//         0053bf9e     MOV        dword ptr [ESI],EDX
//         0053bfa0     MOV        byte ptr [ESI + 0x4],0x0
//         0053bfa4     MOV        byte ptr [ESI + 0x5],0x0
//         0053bfa8     MOV        byte ptr [ESI + 0x6],this
//                              vis_unit.cpp:660 (3)
//         0053bfab     MOV        byte ptr [ESI + 0x7],AL
//                              vis_unit.cpp:662 (14)
//         0053bfae     MOV        EDX,dword ptr [EBX + 0x8]
//         0053bfb1     ADD        EBP,EDX
//         0053bfb3     MOV        EAX,dword ptr [EBP]
//         0053bfb6     INC        EAX
//         0053bfb7     MOV        dword ptr [EBP],EAX
//         0053bfba     POP        EBP
//         0053bfbb     POP        ESI
//                               LAB_0053bfbc                                                 XREF[2]:     0053bedc(j), 0053bef4(j)
//                              vis_unit.cpp:665 (8)
//         0053bfbc     POP        EDI
//         0053bfbd     POP        EBX
//         0053bfbe     ADD        ESP,0x8
//         0053bfc1     RET        0x8
//         0053bfc4     ??         90h
//         0053bfc5     NOP
//         0053bfc6     NOP
//         0053bfc7     NOP
//         0053bfc8     NOP
//         0053bfc9     NOP
//         0053bfca     NOP
//         0053bfcb     NOP
//         0053bfcc     NOP
//         0053bfcd     NOP
//         0053bfce     NOP
//         0053bfcf     NOP
    return;
}

int Visible_Resource_Manager::Remove_Resource(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall Remove_Resource(Visible_Resource_Manager * this, int
//              int               EAX:4          <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053bffd(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053bfdb(R)
//                               ?Remove_Resource@Visible_Resource_Manager@@QAEHHH@Z          XREF[1]:     remove_visible_resource:004c519b(c
//                               Visible_Resource_Manager::Remove_Resource
//                              vis_unit.cpp:669 (11)
//         0053bfd0     MOV        EAX,dword ptr [ECX + this->num_visible_resourc
//         0053bfd3     PUSH       EBX
//         0053bfd4     PUSH       EBP
//         0053bfd5     PUSH       ESI
//         0053bfd6     TEST       EAX,EAX
//         0053bfd8     PUSH       EDI
//         0053bfd9     JZ         LAB_0053c041
//                              vis_unit.cpp:683 (17)
//         0053bfdb     MOV        EAX,dword ptr [ESP + param_2]
//         0053bfdf     MOV        EDX,dword ptr [ECX + this->VR_ListUsed]
//         0053bfe2     MOV        EDX,dword ptr [EDX + EAX*0x4]
//         0053bfe5     LEA        EBX,[EAX*0x4 + 0x0]
//                              vis_unit.cpp:685 (4)
//         0053bfec     TEST       EDX,EDX
//         0053bfee     JZ         LAB_0053c041
//                              vis_unit.cpp:687 (2)
//         0053bff0     MOV        EAX,dword ptr [this->VR_List]
//                              vis_unit.cpp:688 (4)
//         0053bff2     DEC        EDX
//         0053bff3     MOV        EDI,dword ptr [EAX + EBX*0x1]
//                              vis_unit.cpp:690 (7)
//         0053bff6     MOV        EAX,0x0
//         0053bffb     JS         LAB_0053c041
//                              vis_unit.cpp:703 (6)
//         0053bffd     MOV        EBP,dword ptr [ESP + param_1]
//         0053c001     MOV        ESI,EDI
//                               LAB_0053c003                                                 XREF[1]:     0053c00d(j)
//                              vis_unit.cpp:692 (12)
//         0053c003     CMP        dword ptr [ESI],EBP
//         0053c005     JZ         LAB_0053c018
//         0053c007     INC        EAX
//         0053c008     ADD        ESI,0x8
//         0053c00b     CMP        EAX,EDX
//         0053c00d     JLE        LAB_0053c003
//                              vis_unit.cpp:702 (2)
//         0053c00f     XOR        EAX,EAX
//                              vis_unit.cpp:703 (7)
//         0053c011     POP        EDI
//         0053c012     POP        ESI
//         0053c013     POP        EBP
//         0053c014     POP        EBX
//         0053c015     RET        0x8
//                               LAB_0053c018                                                 XREF[1]:     0053c005(j)
//                              vis_unit.cpp:694 (4)
//         0053c018     CMP        EAX,EDX
//         0053c01a     JGE        LAB_0053c02a
//                              vis_unit.cpp:695 (14)
//         0053c01c     MOV        ESI,dword ptr [EDI + EDX*0x8]
//         0053c01f     MOV        dword ptr [EDI + EAX*0x8],ESI
//         0053c022     MOV        EDX,dword ptr [EDI + EDX*0x8 + 0x4]
//         0053c026     MOV        dword ptr [EDI + EAX*0x8 + 0x4],EDX
//                               LAB_0053c02a                                                 XREF[1]:     0053c01a(j)
//                              vis_unit.cpp:697 (11)
//         0053c02a     MOV        EAX,dword ptr [ECX + this->VR_ListUsed]
//         0053c02d     MOV        this,dword ptr [EAX + EBX*0x1]
//         0053c030     ADD        EAX,EBX
//         0053c032     DEC        this
//         0053c033     MOV        dword ptr [EAX],this
//                              vis_unit.cpp:698 (5)
//         0053c035     MOV        EAX,0x1
//                              vis_unit.cpp:703 (16)
//         0053c03a     POP        EDI
//         0053c03b     POP        ESI
//         0053c03c     POP        EBP
//         0053c03d     POP        EBX
//         0053c03e     RET        0x8
//                               LAB_0053c041                                                 XREF[3]:     0053bfd9(j), 0053bfee(j),
//                                                                                                         0053bffb(j)
//         0053c041     POP        EDI
//         0053c042     POP        ESI
//         0053c043     POP        EBP
//         0053c044     XOR        EAX,EAX
//         0053c046     POP        EBX
//         0053c047     RET        0x8
//         0053c04a     ??         90h
//         0053c04b     NOP
//         0053c04c     NOP
//         0053c04d     NOP
//         0053c04e     NOP
//         0053c04f     NOP
    return 0;
}

VISIBLE_RESOURCE_REC* Visible_Resource_Manager::Get_Closest_Resource(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6) {
    /* TODO: Stub */
//                              VISIBLE_RESOURCE_REC * __thiscall Get_Closest_Resource(Visible_Resou
//              VISIBLE_RESOUR    EAX:4          <RETURN>
//              Visible_Resour    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053c0b0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053c0d2(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[7]:     0053c050(R), 0053c096(W), 0053c124(R), 0053c161(W),
//                                                                                     0053c17b(R), 0053c188(W), 0053c190(R)
//              int *             Stack[0x14]:4  param_5                   XREF[1]:     0053c12e(R)
//              int               Stack[0x18]:4  param_6                   XREF[3]:     0053c0a8(R), 0053c0e8(W), 0053c0ee(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0053c09e(W), 0053c15d(W), 0053c177(R)
//              VISIBLE_RESOUR    Stack[-0x8]:4  c                         XREF[3]:     0053c0ac(W), 0053c165(R), 0053c16d(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0053c0c0(W), 0053c14d(W), 0053c155(R)
//              int               Stack[-0x10]:4 Reject                    XREF[2]:     0053c0d6(W), 0053c10b(R)
//              int               Stack[-0x14]:4 xd
//                               ?Get_Closest_Resource@Visible_Resource_Manager@@QAEPAUVISIB  XREF[1]:     closestResourceObject:00415eab(c)
//                               Visible_Resource_Manager::Get_Closest_Resource
//                              vis_unit.cpp:708 (40)
//         0053c050     MOV        EAX,dword ptr [ESP + param_4]
//         0053c054     SUB        ESP,0x10
//         0053c057     TEST       EAX,EAX
//         0053c059     PUSH       EBX
//         0053c05a     PUSH       EBP
//         0053c05b     PUSH       ESI
//         0053c05c     PUSH       EDI
//         0053c05d     MOV        ESI,this
//         0053c05f     JL         LAB_0053c1a3
//         0053c065     MOV        this,dword ptr [ESI + 0x10]
//         0053c068     TEST       this,this
//         0053c06a     JZ         LAB_0053c1a3
//         0053c070     CMP        EAX,this
//         0053c072     JGE        LAB_0053c1a3
//                              vis_unit.cpp:722 (13)
//         0053c078     LEA        EDX,[EAX*0x4 + 0x0]
//         0053c07f     MOV        EAX,dword ptr [ESI + 0x8]
//         0053c082     MOV        EAX,dword ptr [EAX + EDX*0x1]
//                              vis_unit.cpp:724 (8)
//         0053c085     TEST       EAX,EAX
//         0053c087     JZ         LAB_0053c1a3
//                              vis_unit.cpp:729 (4)
//         0053c08d     MOV        ESI,dword ptr [ESI]
//         0053c08f     XOR        this,this
//                              vis_unit.cpp:731 (23)
//         0053c091     TEST       EAX,EAX
//         0053c093     MOV        EBP,dword ptr [ESI + EDX*0x1]
//         0053c096     MOV        dword ptr [ESP + param_4],0x270f
//         0053c09e     MOV        dword ptr [ESP + local_4],this
//         0053c0a2     JLE        LAB_0053c17b
//                              vis_unit.cpp:792 (40)
//         0053c0a8     MOV        EBX,dword ptr [ESP + param_6]
//         0053c0ac     MOV        dword ptr [ESP + c],EAX
//                               LAB_0053c0b0                                                 XREF[1]:     0053c171(j)
//         0053c0b0     MOV        EDI,dword ptr [ESP + param_1]
//         0053c0b4     XOR        EAX,EAX
//         0053c0b6     MOV        AL,byte ptr [EBP + 0x6]
//         0053c0b9     XOR        this,this
//         0053c0bb     MOV        this,byte ptr [EBP + 0x7]
//         0053c0be     CMP        EAX,EDI
//         0053c0c0     MOV        dword ptr [ESP + local_c],0x0
//         0053c0c8     JLE        LAB_0053c0d0
//         0053c0ca     SUB        EAX,EDI
//         0053c0cc     MOV        EDI,EAX
//         0053c0ce     JMP        LAB_0053c0d2
//                               LAB_0053c0d0                                                 XREF[1]:     0053c0c8(j)
//                              vis_unit.cpp:731 (2)
//         0053c0d0     SUB        EDI,EAX
//                               LAB_0053c0d2                                                 XREF[1]:     0053c0ce(j)
//                              vis_unit.cpp:740 (18)
//         0053c0d2     MOV        ESI,dword ptr [ESP + param_2]
//         0053c0d6     MOV        dword ptr [ESP + Reject],EDI
//         0053c0da     CMP        this,ESI
//         0053c0dc     JLE        LAB_0053c0e4
//         0053c0de     SUB        this,ESI
//         0053c0e0     MOV        ESI,this
//         0053c0e2     JMP        LAB_0053c0e6
//                               LAB_0053c0e4                                                 XREF[1]:     0053c0dc(j)
//                              vis_unit.cpp:731 (2)
//         0053c0e4     SUB        ESI,this
//                               LAB_0053c0e6                                                 XREF[1]:     0053c0e2(j)
//                              vis_unit.cpp:742 (8)
//         0053c0e6     CMP        EDI,ESI
//         0053c0e8     MOV        dword ptr [ESP + param_6],ESI
//         0053c0ec     JLE        LAB_0053c10b
//                              vis_unit.cpp:744 (27)
//         0053c0ee     FILD       dword ptr [ESP + param_6]
//         0053c0f2     FMUL       double ptr [DAT_005776d0]                        = 66h    f
//         0053c0f8     FSUBR      double ptr [DAT_005776d8]                        = 85h
//         0053c0fe     CALL       __ftol                                           undefined __ftol()
//         0053c103     SUB        EDI,EAX
//         0053c105     SUB        EDI,ESI
//         0053c107     MOV        ESI,EDI
//                              vis_unit.cpp:746 (2)
//         0053c109     JMP        LAB_0053c124
//                               LAB_0053c10b                                                 XREF[1]:     0053c0ec(j)
//                              vis_unit.cpp:748 (25)
//         0053c10b     FILD       dword ptr [ESP + Reject]
//         0053c10f     FMUL       double ptr [DAT_005776d0]                        = 66h    f
//         0053c115     FSUBR      double ptr [DAT_005776d8]                        = 85h
//         0053c11b     CALL       __ftol                                           undefined __ftol()
//         0053c120     SUB        ESI,EAX
//         0053c122     SUB        ESI,EDI
//                               LAB_0053c124                                                 XREF[1]:     0053c109(j)
//                              vis_unit.cpp:751 (6)
//         0053c124     CMP        ESI,dword ptr [ESP + param_4]
//         0053c128     JGE        LAB_0053c165
//                              vis_unit.cpp:755 (12)
//         0053c12a     TEST       EBX,EBX
//         0053c12c     JZ         LAB_0053c155
//         0053c12e     MOV        EAX,dword ptr [ESP + param_5]
//         0053c132     TEST       EAX,EAX
//         0053c134     JZ         LAB_0053c155
//                              vis_unit.cpp:757 (6)
//         0053c136     XOR        this,this
//         0053c138     TEST       EBX,EBX
//         0053c13a     JLE        LAB_0053c155
//                              vis_unit.cpp:759 (17)
//         0053c13c     MOV        EDX,dword ptr [EBP]
//                               LAB_0053c13f                                                 XREF[1]:     0053c149(j)
//         0053c13f     CMP        EDX,dword ptr [EAX]
//         0053c141     JZ         LAB_0053c14d
//         0053c143     INC        this
//         0053c144     ADD        EAX,0x4
//         0053c147     CMP        this,EBX
//         0053c149     JL         LAB_0053c13f
//         0053c14b     JMP        LAB_0053c155
//                               LAB_0053c14d                                                 XREF[1]:     0053c141(j)
//                              vis_unit.cpp:761 (8)
//         0053c14d     MOV        dword ptr [ESP + local_c],0x1
//                               LAB_0053c155                                                 XREF[4]:     0053c12c(j), 0053c134(j),
//                                                                                                         0053c13a(j), 0053c14b(j)
//                              vis_unit.cpp:769 (8)
//         0053c155     MOV        EAX,dword ptr [ESP + local_c]
//         0053c159     TEST       EAX,EAX
//         0053c15b     JNZ        LAB_0053c165
//                              vis_unit.cpp:771 (4)
//         0053c15d     MOV        dword ptr [ESP + local_4],EBP
//                              vis_unit.cpp:772 (22)
//         0053c161     MOV        dword ptr [ESP + param_4],ESI
//                               LAB_0053c165                                                 XREF[2]:     0053c128(j), 0053c15b(j)
//         0053c165     MOV        EAX,dword ptr [ESP + c]
//         0053c169     ADD        EBP,0x8
//         0053c16c     DEC        EAX
//         0053c16d     MOV        dword ptr [ESP + c],EAX
//         0053c171     JNZ        LAB_0053c0b0
//                              vis_unit.cpp:731 (4)
//         0053c177     MOV        this,dword ptr [ESP + local_4]
//                               LAB_0053c17b                                                 XREF[1]:     0053c0a2(j)
//                              vis_unit.cpp:779 (17)
//         0053c17b     MOV        EDX,dword ptr [ESP + param_4]
//         0053c17f     MOV        EAX,0xff
//         0053c184     CMP        EDX,EAX
//         0053c186     JLE        LAB_0053c18c
//         0053c188     MOV        dword ptr [ESP + param_4],EAX
//                               LAB_0053c18c                                                 XREF[1]:     0053c186(j)
//                              vis_unit.cpp:781 (11)
//         0053c18c     TEST       this,this
//         0053c18e     JZ         LAB_0053c197
//         0053c190     MOV        DL,byte ptr [ESP + param_4]
//         0053c194     MOV        byte ptr [ECX + this->VR_ListSize],DL
//                               LAB_0053c197                                                 XREF[1]:     0053c18e(j)
//                              vis_unit.cpp:790 (2)
//         0053c197     MOV        EAX,this
//                              vis_unit.cpp:792 (22)
//         0053c199     POP        EDI
//         0053c19a     POP        ESI
//         0053c19b     POP        EBP
//         0053c19c     POP        EBX
//         0053c19d     ADD        ESP,0x10
//         0053c1a0     RET        0x18
//                               LAB_0053c1a3                                                 XREF[4]:     0053c05f(j), 0053c06a(j),
//                                                                                                         0053c072(j), 0053c087(j)
//         0053c1a3     POP        EDI
//         0053c1a4     POP        ESI
//         0053c1a5     POP        EBP
//         0053c1a6     XOR        EAX,EAX
//         0053c1a8     POP        EBX
//         0053c1a9     ADD        ESP,0x10
//         0053c1ac     RET        0x18
//         0053c1af     ??         90h
    return 0;
}

